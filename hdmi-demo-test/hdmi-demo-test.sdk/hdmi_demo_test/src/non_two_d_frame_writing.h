/*
 * non_two_d_frame_writing.h
 *
 *  Created on: May 15, 2024
 *      Author: blomecj
 */

#ifndef SRC_NON_TWO_D_FRAME_WRITING_H_
#define SRC_NON_TWO_D_FRAME_WRITING_H_


#include "xil_types.h"
#include "project_main.h"

//typedef struct rgb_val{
//	u8 red;
//	u8 green;
//	u8 blue;
//} rgb_val;

extern void writeWhiteZero(u32 x, u32 y, u8 * frame, u32 stride);

extern void writeWhiteOne(u32 x, u32 y, u8 * frame, u32 stride);

extern void writeWhiteTwo(u32 x, u32 y, u8 * frame, u32 stride);

extern void writeWhiteThree(u32 x, u32 y, u8 * frame, u32 stride);

extern void writeWhiteFour(u32 x, u32 y, u8 * frame, u32 stride);

extern void writeWhiteFive(u32 x, u32 y, u8 * frame, u32 stride);

extern void writeWhiteSix(u32 x, u32 y, u8 * frame, u32 stride);

extern void writeWhiteSeven(u32 x, u32 y, u8 * frame, u32 stride);

extern void writeWhiteEight(u32 x, u32 y, u8 * frame, u32 stride);

extern void writeWhiteNine(u32 x, u32 y, u8 * frame, u32 stride);

extern void writePlayer(u32 x, u32 y, u8 * frame, u32 stride);

extern void clearPlayer(u32 x, u32 y, u8 * frame, u32 stride);

extern void writeGameScreen(u8 * frame, u32 stride);

//extern void drawFrame(rgb_val ** twoDRGBArray, u8 *frame, u32 width, u32 height, u32 stride);

#endif /* SRC_NON_TWO_D_FRAME_WRITING_H_ */