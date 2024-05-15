/*
 * writing_to_two_d_frame.h
 *
 *  Created on: May 14, 2024
 *      Author: blomecj
 */

#ifndef SRC_WRITING_TO_TWO_D_FRAME_H_
#define SRC_WRITING_TO_TWO_D_FRAME_H_

#include "xil_types.h"
#include "project_main.h"

typedef struct rgb_val{
	u8 red;
	u8 green;
	u8 blue;
} rgb_val;

extern void writeWhiteZero(u32 x, u32 y, rgb_val ** twoDRGBArray);

extern void writeWhiteOne(u32 x, u32 y, rgb_val ** twoDRGBArray);

extern void writeWhiteTwo(u32 x, u32 y, rgb_val ** twoDRGBArray);

extern void writeWhiteThree(u32 x, u32 y, rgb_val ** twoDRGBArray);

extern void writeWhiteFour(u32 x, u32 y, rgb_val ** twoDRGBArray);

extern void writeWhiteFive(u32 x, u32 y, rgb_val ** twoDRGBArray);

extern void writeWhiteSix(u32 x, u32 y, rgb_val ** twoDRGBArray);

extern void writeWhiteSeven(u32 x, u32 y, rgb_val ** twoDRGBArray);

extern void writeWhiteEight(u32 x, u32 y, rgb_val ** twoDRGBArray);

extern void writeWhiteNine(u32 x, u32 y, rgb_val ** twoDRGBArray);

extern void writePlayer(u32 x, u32 y, rgb_val ** twoDRGBArray);

extern void writeGameScreen(rgb_val ** twoDRGBArray);

extern void drawFrame(rgb_val ** twoDRGBArray, u8 *frame, u32 width, u32 height, u32 stride);

#endif /* SRC_WRITING_TO_TWO_D_FRAME_H_ */