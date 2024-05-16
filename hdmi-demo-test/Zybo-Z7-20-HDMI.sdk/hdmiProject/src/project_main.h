/*
 * project_main.h
 *
 *  Created on: May 14, 2024
 *      Author: blomecj
 */

#ifndef SRC_PROJECT_MAIN_H_
#define SRC_PROJECT_MAIN_H_

/* ------------------------------------------------------------ */
/*				Include File Definitions						*/
/* ------------------------------------------------------------ */
#include "display_ctrl/display_ctrl.h"
#include "intc/intc.h"
#include <stdio.h>
#include "xuartps.h"
#include "math.h"
#include <ctype.h>
#include <stdlib.h>
#include "xil_types.h"
#include "xil_cache.h"
#include "timer_ps/timer_ps.h"
#include "xparameters.h"
#include "non_two_d_frame_writing.h"

/*
 * XPAR redefines
 */
#define DYNCLK_BASEADDR 		XPAR_AXI_DYNCLK_0_BASEADDR
#define VDMA_ID 				XPAR_AXIVDMA_0_DEVICE_ID
#define HDMI_OUT_VTC_ID 		XPAR_V_TC_OUT_DEVICE_ID
#define HDMI_IN_VTC_ID 			XPAR_V_TC_IN_DEVICE_ID
#define HDMI_IN_GPIO_ID 		XPAR_AXI_GPIO_VIDEO_DEVICE_ID
#define HDMI_IN_VTC_IRPT_ID 	XPAR_FABRIC_V_TC_IN_IRQ_INTR
#define HDMI_IN_GPIO_IRPT_ID 	XPAR_FABRIC_AXI_GPIO_VIDEO_IP2INTC_IRPT_INTR
#define SCU_TIMER_ID 			XPAR_SCUTIMER_DEVICE_ID
#define UART_BASEADDR 			XPAR_PS7_UART_1_BASEADDR


// Device ID and Interrupt ID definitions
#define INTC_DEVICE_ID 		XPAR_PS7_SCUGIC_0_DEVICE_ID
//AXI_TIMER_0 Count Up timer
#define TMR_DEVICE_ID		XPAR_AXI_TIMER_0_DEVICE_ID
#define BTNS_DEVICE_ID		XPAR_AXI_GPIO_0_DEVICE_ID
#define INTC_GPIO_INTERRUPT_ID 	XPAR_FABRIC_AXI_GPIO_0_IP2INTC_IRPT_INTR

#define INTC_TMR_INTERRUPT_ID 	XPAR_FABRIC_AXI_TIMER_0_INTERRUPT_INTR

#define BTN_INT_MASK 			XGPIO_IR_CH1_MASK


#define GAME_RES_WIDTH 	1920
#define GAME_RES_HEIGHT 	1080

#define GAME_STRIDE 	3*(GAME_RES_WIDTH)

//Only need one frame in the frame buffer because I will only be manipulating one frame
#define DISPLAY_NUM_FRAMES 1
// This is the size of the array for the frame because we have the stride which is how wide the frame is *3 for rgb values then times the height of the frame
#define FRAME_ARRAY_SIZE GAME_STRIDE*GAME_RES_HEIGHT

//Lanes for the game each  is 72 pixels wide
#define PLAYER_Y_COORD 	GAME_RES_HEIGHT-72
#define SCORE_Y_COORD 	0 //I want score alligned at top of screen


#define COL1_COORD ((GAME_RES_WIDTH-360)/2)
#define COL2_COORD (COL1_COORD + 72)
#define COL3_COORD (COL2_COORD + 72)
#define COL4_COORD (COL3_COORD + 72)
#define COL5_COORD (COL4_COORD + 72)
#define COL5_END_COORD (COL5_COORD + 72)

#define ROW0_Y_COORD 	0
#define ROW1_Y_COORD 	ROW0_Y_COORD+72
#define ROW2_Y_COORD	ROW1_Y_COORD+72
#define ROW3_Y_COORD	ROW2_Y_COORD+72
#define ROW4_Y_COORD	ROW3_Y_COORD+72
#define ROW5_Y_COORD	ROW4_Y_COORD+72
#define ROW6_Y_COORD	ROW5_Y_COORD+72
#define ROW7_Y_COORD	ROW6_Y_COORD+72
#define ROW8_Y_COORD	ROW7_Y_COORD+72
#define ROW9_Y_COORD	ROW8_Y_COORD+72
#define ROW10_Y_COORD	ROW9_Y_COORD+72
#define ROW11_Y_COORD	ROW10_Y_COORD+72
#define ROW12_Y_COORD	ROW11_Y_COORD+72
#define ROW13_Y_COORD	ROW12_Y_COORD+72
#define ROW14_Y_COORD	ROW13_Y_COORD+72


void HardwareInitialize();
void GameRun();

extern void movePlayerLeft();
extern void movePlayerRight();

#endif /* SRC_PROJECT_MAIN_H_ */
