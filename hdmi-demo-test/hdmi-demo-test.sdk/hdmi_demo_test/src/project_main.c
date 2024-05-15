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
int playerPos = COL3_COORD;
int score = 0;
int enemyArray[15];

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
	writePlayer(COL3_COORD, PLAYER_Y_COORD, pFrames[dispCtrl.curFrame], GAME_STRIDE);
	writeScore(0, SCORE_Y_COORD, score, pFrames[dispCtrl.curFrame], GAME_STRIDE);


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
		case 'x':
			updateEnemyPositions();
			spawnEnemy();
			break;
		case '+':
			score += 100;
			writeScore(0, SCORE_Y_COORD, score, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case '-':
			score -= 100;
			writeScore(0, SCORE_Y_COORD, score, pFrames[dispCtrl.curFrame], GAME_STRIDE);
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

void movePlayerLeft(){
	switch(playerPos){
		case COL1_COORD:
			playerPos = COL1_COORD;
			clearPlayer(COL1_COORD, PLAYER_Y_COORD, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case COL2_COORD:
			playerPos = COL1_COORD;
			clearPlayer(COL2_COORD, PLAYER_Y_COORD, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case COL3_COORD:
			playerPos = COL2_COORD;
			clearPlayer(COL3_COORD, PLAYER_Y_COORD, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case COL4_COORD:
			playerPos = COL3_COORD;
			clearPlayer(COL4_COORD, PLAYER_Y_COORD, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case COL5_COORD:
			playerPos = COL4_COORD;
			clearPlayer(COL5_COORD, PLAYER_Y_COORD, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
	}
	writePlayer(playerPos, PLAYER_Y_COORD, pFrames[dispCtrl.curFrame], GAME_STRIDE);

}

void movePlayerRight(){
	switch(playerPos){
		case COL1_COORD:
			playerPos = COL2_COORD;
			clearPlayer(COL1_COORD, PLAYER_Y_COORD, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case COL2_COORD:
			playerPos = COL3_COORD;
			clearPlayer(COL2_COORD, PLAYER_Y_COORD, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case COL3_COORD:
			playerPos = COL4_COORD;
			clearPlayer(COL3_COORD, PLAYER_Y_COORD, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case COL4_COORD:
			playerPos = COL5_COORD;
			clearPlayer(COL4_COORD, PLAYER_Y_COORD, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case COL5_COORD:
			playerPos = COL5_COORD;
			clearPlayer(COL5_COORD, PLAYER_Y_COORD, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
	}

	writePlayer(playerPos, PLAYER_Y_COORD, pFrames[dispCtrl.curFrame], GAME_STRIDE);

}

void spawnEnemy(){
	int r = (rand()%5)+1; //this should give me a number between 1 and 5

	switch(r){
		case 1:
			enemyArray[1] = COL1_COORD;
			writeEnemy(COL1_COORD, ROW1_Y_COORD, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case 2:
			enemyArray[1] = COL2_COORD;
			writeEnemy(COL2_COORD, ROW1_Y_COORD, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case 3:
			enemyArray[1] = COL3_COORD;
			writeEnemy(COL3_COORD, ROW1_Y_COORD, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case 4:
			enemyArray[1] = COL4_COORD;
			writeEnemy(COL4_COORD, ROW1_Y_COORD, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
		case 5:
			enemyArray[1] = COL5_COORD;
			writeEnemy(COL5_COORD, ROW1_Y_COORD, pFrames[dispCtrl.curFrame], GAME_STRIDE);
			break;
	}

}

void updateEnemyPosition(int enemy){

}

void updateEnemyPositions(){
	int i = 0;
	int temp1 = 0;
	int temp2 = 0;

	for(i = 1; i < 15; i++){
		temp1 = enemyArray[i];
		clearPlayer(enemyArray[i], i*72, pFrames[dispCtrl.curFrame], GAME_STRIDE);
		enemyArray[i] = temp2;
		temp2 = temp1;
	}

	i=1;
	while(i<15){
		writeEnemy(enemyArray[i], (i)*72, pFrames[dispCtrl.curFrame], GAME_STRIDE);
		i++;
	}

}


