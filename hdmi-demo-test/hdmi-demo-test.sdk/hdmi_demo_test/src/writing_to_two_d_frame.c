/*
 * writing_to_two_d_frame.c
 *
 *  Created on: May 14, 2024
 *      Author: blomecj
 */

#include "writing_to_two_d_frame.h"

//Number writing defines not best practice but will keep me from losing my mind
#define TOP (j < y+5)
#define BOT (j > max_y-5)
#define MID (j > 33 && j < 38)
#define RIGHT (i > max_x-5)
#define LEFT (i < x+5)
#define TOP_RIGHT (RIGHT && j<33)
#define TOP_LEFT (LEFT && j<33)
#define BOT_RIGHT (RIGHT && j>38)
#define BOT_LEFT (LEFT && j>38)

void writeWhiteZero(u32 x, u32 y, rgb_val ** twoDRGBArray){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){

			if(BOT || TOP || LEFT || RIGHT){
				twoDRGBArray[i][j].blue = 255;
				twoDRGBArray[i][j].green = 255;
				twoDRGBArray[i][j].red = 255;
			}
			else{
				twoDRGBArray[i][j].blue = 0;
				twoDRGBArray[i][j].green = 0;
				twoDRGBArray[i][j].red = 0;
			}

		}
	}
}

void writeWhiteOne(u32 x, u32 y, rgb_val ** twoDRGBArray){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){


			if(i > x + 15 && i < max_x-15){
				twoDRGBArray[i][j].blue = 255;
				twoDRGBArray[i][j].green = 255;
				twoDRGBArray[i][j].red = 255;
			}
			else{
				twoDRGBArray[i][j].blue = 0;
				twoDRGBArray[i][j].green = 0;
				twoDRGBArray[i][j].red = 0;
			}

		}
	}
}

void writeWhiteTwo(u32 x, u32 y, rgb_val ** twoDRGBArray){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){

			if(TOP || BOT || MID || TOP_RIGHT || BOT_LEFT){
				twoDRGBArray[i][j].blue = 255;
				twoDRGBArray[i][j].green = 255;
				twoDRGBArray[i][j].red = 255;
			}
			else{
				twoDRGBArray[i][j].blue = 0;
				twoDRGBArray[i][j].green = 0;
				twoDRGBArray[i][j].red = 0;
			}

		}
	}
}

void writeWhiteThree(u32 x, u32 y, rgb_val ** twoDRGBArray){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){

			if(TOP || BOT || MID || RIGHT){
				twoDRGBArray[i][j].blue = 255;
				twoDRGBArray[i][j].green = 255;
				twoDRGBArray[i][j].red = 255;
			}
			else{
				twoDRGBArray[i][j].blue = 0;
				twoDRGBArray[i][j].green = 0;
				twoDRGBArray[i][j].red = 0;
			}
		}
	}
}

void writeWhiteFour(u32 x, u32 y, rgb_val ** twoDRGBArray){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){

			if(MID || RIGHT || TOP_LEFT){
				twoDRGBArray[i][j].blue = 255;
				twoDRGBArray[i][j].green = 255;
				twoDRGBArray[i][j].red = 255;
			}
			else{
				twoDRGBArray[i][j].blue = 0;
				twoDRGBArray[i][j].green = 0;
				twoDRGBArray[i][j].red = 0;
			}

		}
	}
}

void writeWhiteFive(u32 x, u32 y, rgb_val ** twoDRGBArray){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){

			if(TOP || BOT || MID || TOP_LEFT || BOT_RIGHT){
				twoDRGBArray[i][j].blue = 255;
				twoDRGBArray[i][j].green = 255;
				twoDRGBArray[i][j].red = 255;
			}
			else{
				twoDRGBArray[i][j].blue = 0;
				twoDRGBArray[i][j].green = 0;
				twoDRGBArray[i][j].red = 0;
			}

		}
	}
}

void writeWhiteSix(u32 x, u32 y, rgb_val ** twoDRGBArray){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){

			if(TOP || BOT || MID || LEFT || BOT_RIGHT){
				twoDRGBArray[i][j].blue = 255;
				twoDRGBArray[i][j].green = 255;
				twoDRGBArray[i][j].red = 255;
			}
			else{
				twoDRGBArray[i][j].blue = 0;
				twoDRGBArray[i][j].green = 0;
				twoDRGBArray[i][j].red = 0;
			}

		}
	}
}

void writeWhiteSeven(u32 x, u32 y, rgb_val ** twoDRGBArray){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){

			if(TOP || RIGHT){
				twoDRGBArray[i][j].blue = 255;
				twoDRGBArray[i][j].green = 255;
				twoDRGBArray[i][j].red = 255;
			}
			else{
				twoDRGBArray[i][j].blue = 0;
				twoDRGBArray[i][j].green = 0;
				twoDRGBArray[i][j].red = 0;
			}
		}
	}
}

void writeWhiteEight(u32 x, u32 y, rgb_val ** twoDRGBArray){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){

			if(TOP || MID || BOT || RIGHT || LEFT){
				twoDRGBArray[i][j].blue = 255;
				twoDRGBArray[i][j].green = 255;
				twoDRGBArray[i][j].red = 255;
			}
			else{
				twoDRGBArray[i][j].blue = 0;
				twoDRGBArray[i][j].green = 0;
				twoDRGBArray[i][j].red = 0;
			}

		}
	}
}

void writeWhiteNine(u32 x, u32 y, rgb_val ** twoDRGBArray){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){

			if(TOP || MID || BOT || RIGHT || TOP_LEFT){
				twoDRGBArray[i][j].blue = 255;
				twoDRGBArray[i][j].green = 255;
				twoDRGBArray[i][j].red = 255;
			}
			else{
				twoDRGBArray[i][j].blue = 0;
				twoDRGBArray[i][j].green = 0;
				twoDRGBArray[i][j].red = 0;
			}

		}
	}
}

void writePlayer(u32 x, u32 y, rgb_val ** twoDRGBArray){
	u32 max_x = x+72;//72 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){
			twoDRGBArray[i][j].blue = 0;
			twoDRGBArray[i][j].green = 0;
			twoDRGBArray[i][j].red = 255;
		}
	}
}

void writeGameScreen(rgb_val ** twoDRGBArray){
	int i;
	for(i = 0; i < GAME_RES_WIDTH; i++){//1280 is screen width
		int j;
		for (j = 0; j < GAME_RES_HEIGHT; j++){//720 is screen height
			if(i < ROW1_COORD || i > ROW5_END_COORD){
				twoDRGBArray[i][j].blue = 0;
				twoDRGBArray[i][j].green = 0;
				twoDRGBArray[i][j].red = 0;
			}
			else{
				twoDRGBArray[i][j].blue = 255;
				twoDRGBArray[i][j].green = 0;
				twoDRGBArray[i][j].red = 0;
			}
		}
	}
}

void drawFrame(rgb_val ** twoDRGBArray, u8 *frame, u32 width, u32 height, u32 stride){
	int i;
	for(i = 0; i < width; i++){
		int j;
//		int iPixelAddr = i*3;//3 color channels
		for(j=0; j < height; j++){
			frame[i*3 + j*stride] = twoDRGBArray[i][j].blue;
			frame[i*3 + j*stride + 1] = twoDRGBArray[i][j].green;
			frame[i*3 + j*stride + 2] = twoDRGBArray[i][j].red;

//			iPixelAddr += stride;
		}
	}
}

