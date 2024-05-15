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



#define GAME_RES_WIDTH 	1920
#define GAME_RES_HEIGHT 	1080

#define GAME_STRIDE 	3*(GAME_RES_WIDTH)

//Only need one frame in the frame buffer because I will only be manipulating one frame
#define DISPLAY_NUM_FRAMES 1
// This is the size of the array for the frame because we have the stride which is how wide the frame is *3 for rgb values then times the height of the frame
#define FRAME_ARRAY_SIZE GAME_STRIDE*GAME_RES_HEIGHT

//Lanes for the game each  is 72 pixels wide
#define PLAYER_Y_COORD GAME_RES_HEIGHT-72

#define ROW1_COORD ((GAME_RES_WIDTH-360)/2)
#define ROW2_COORD (ROW1_COORD + 72)
#define ROW3_COORD (ROW2_COORD + 72)
#define ROW4_COORD (ROW3_COORD + 72)
#define ROW5_COORD (ROW4_COORD + 72)
#define ROW5_END_COORD (ROW5_COORD + 72)


void HardwareInitialize();
void GameRun();

#endif /* SRC_PROJECT_MAIN_H_ */
