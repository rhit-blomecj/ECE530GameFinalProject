#include "project_main.h"
/* ------------------------------------------------------------ */
/*				Global Variables								*/
/* ------------------------------------------------------------ */

/*
 * Display and Video Driver structs
 */
DisplayCtrl dispCtrl;
XAxiVdma vdma;
INTC intc;
char fRefresh; //flag used to trigger a refresh of the Menu on video detect
int playerPos = ROW3_COORD;
/*
 * Framebuffers for video data
 */
u8 frameBuf[DISPLAY_NUM_FRAMES][FRAME_ARRAY_SIZE] __attribute__((aligned(0x20)));
u8 *pFrames[DISPLAY_NUM_FRAMES]; //array of pointers to the frame buffers

int main(void)
{
	HardwareInitialize();

	GameRun();

	return 0;
}

void HardwareInitialize()
{
	int Status;
	XAxiVdma_Config *vdmaConfig;
	int i;

	/*
	 * Initialize an array of pointers to the 3 frame buffers
	 */
	for (i = 0; i < DISPLAY_NUM_FRAMES; i++)
	{
		pFrames[i] = frameBuf[i];
	}

	//setup the pointers to my 2 d frame
	// sets up our 2D array for representing frames (C pointer stuff)
//	for (i = 0; i < GAME_RES_HEIGHT; i++)
//	{
//		twoDFrameRep[i] = twoDFrame[i];
//	}
	/*
	 * Initialize a timer used for a simple delay
	 */
	TimerInitialize(SCU_TIMER_ID);

	/*
	 * Initialize VDMA driver
	 */
	vdmaConfig = XAxiVdma_LookupConfig(VDMA_ID);
	if (!vdmaConfig)
	{
		xil_printf("No video DMA found for ID %d\r\n", VDMA_ID);
		return;
	}
	Status = XAxiVdma_CfgInitialize(&vdma, vdmaConfig, vdmaConfig->BaseAddress);
	if (Status != XST_SUCCESS)
	{
		xil_printf("VDMA Configuration Initialization failed %d\r\n", Status);
		return;
	}

	/*
	 * Initialize the Display controller and start it
	 */
	Status = DisplayInitialize(&dispCtrl, &vdma, HDMI_OUT_VTC_ID, DYNCLK_BASEADDR, pFrames, GAME_STRIDE);
	if (Status != XST_SUCCESS)
	{
		xil_printf("Display Ctrl initialization failed during demo initialization%d\r\n", Status);
		return;
	}
	Status = DisplayStart(&dispCtrl);
	if (Status != XST_SUCCESS)
	{
		xil_printf("Couldn't start display during demo initialization%d\r\n", Status);
		return;
	}



	/*
	 * Initialize the Interrupt controller and start it.
	 */
	Status = fnInitInterruptController(&intc);
	if(Status != XST_SUCCESS) {
		xil_printf("Error initializing interrupts");
		return;
	}

	//if this breaks just remove
	DisplayStop(&dispCtrl);
	DisplaySetMode(&dispCtrl, &VMODE_1920x1080);
	DisplayStart(&dispCtrl);

	return;
}


void GameRun()
{
	char userInput = 0;

	writeGameScreen(pFrames[dispCtrl.curFrame], GAME_STRIDE);
	writePlayer(ROW3_COORD, PLAYER_Y_COORD, pFrames[dispCtrl.curFrame], GAME_STRIDE);


	/* Flush UART FIFO */
	while (XUartPs_IsReceiveData(UART_BASEADDR))
	{
		XUartPs_ReadReg(UART_BASEADDR, XUARTPS_FIFO_OFFSET);
	}

	while (userInput != 'q')
	{
		fRefresh = 0;

		Xil_DCacheFlushRange((unsigned int) pFrames[dispCtrl.curFrame], FRAME_ARRAY_SIZE);

		/* Wait for data on UART */
		while (!XUartPs_IsReceiveData(UART_BASEADDR) && !fRefresh)
		{}

		/* Store the first character in the UART receive FIFO and echo it */
		if (XUartPs_IsReceiveData(UART_BASEADDR))
		{
			userInput = XUartPs_ReadReg(UART_BASEADDR, XUARTPS_FIFO_OFFSET);
			xil_printf("%c", userInput);
		}
		else  //Refresh triggered by video detect interrupt
		{
			userInput = 'r';
		}



		switch (userInput)
		{
		case '1':
			writeWhiteOne(40, 0, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case '2':
			writeWhiteTwo(80, 0, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case '3':
			writeWhiteThree(120, 0, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case '4':
			writeWhiteFour(160, 0, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case '5':
			writeWhiteFive(200, 0, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case '6':
			writeWhiteSix(240, 0, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case '7':
			writeWhiteSeven(280, 0, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case '8':
			writeWhiteEight(320, 0, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case '9':
			writeWhiteNine(360, 0, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case '0':
			writeWhiteZero(0,0,pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case ',':
			movePlayerLeft(pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case '.':
			movePlayerRight(pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case 'q':
			break;
		case 'r':
			break;
		default :
			xil_printf("\n\rInvalid Selection");
			TimerDelay(500000);
		}
	}

	return;
}

void movePlayerLeft(u8* frame, u32 stride){
	switch(playerPos){
		case ROW1_COORD:
			playerPos = ROW1_COORD;
			clearPlayer(ROW1_COORD, PLAYER_Y_COORD, frame, stride);
			break;
		case ROW2_COORD:
			playerPos = ROW1_COORD;
			clearPlayer(ROW2_COORD, PLAYER_Y_COORD, frame, stride);
			break;
		case ROW3_COORD:
			playerPos = ROW2_COORD;
			clearPlayer(ROW3_COORD, PLAYER_Y_COORD, frame, stride);
			break;
		case ROW4_COORD:
			playerPos = ROW3_COORD;
			clearPlayer(ROW4_COORD, PLAYER_Y_COORD, frame, stride);
			break;
		case ROW5_COORD:
			playerPos = ROW4_COORD;
			clearPlayer(ROW5_COORD, PLAYER_Y_COORD, frame, stride);
			break;
	}
	writePlayer(playerPos, PLAYER_Y_COORD, frame, stride);

}

void movePlayerRight(u8* frame, u32 stride){
	switch(playerPos){
		case ROW1_COORD:
			playerPos = ROW2_COORD;
			clearPlayer(ROW1_COORD, PLAYER_Y_COORD, frame, stride);
			break;
		case ROW2_COORD:
			playerPos = ROW3_COORD;
			clearPlayer(ROW2_COORD, PLAYER_Y_COORD, frame, stride);
			break;
		case ROW3_COORD:
			playerPos = ROW4_COORD;
			clearPlayer(ROW3_COORD, PLAYER_Y_COORD, frame, stride);
			break;
		case ROW4_COORD:
			playerPos = ROW5_COORD;
			clearPlayer(ROW4_COORD, PLAYER_Y_COORD, frame, stride);
			break;
		case ROW5_COORD:
			playerPos = ROW5_COORD;
			clearPlayer(ROW5_COORD, PLAYER_Y_COORD, frame, stride);
			break;
	}

	writePlayer(playerPos, PLAYER_Y_COORD, frame, stride);

}
