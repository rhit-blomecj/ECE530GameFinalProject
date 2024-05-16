/*
 * non_two_d_frame_writing.c
 *
 *  Created on: May 15, 2024
 *      Author: blomecj
 */


/*
 * writing_to_two_d_frame.c
 *
 *  Created on: May 14, 2024
 *      Author: blomecj
 */

#include "non_two_d_frame_writing.h"

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

void writeWhiteZero(u32 x, u32 y, u8 * frame, u32 stride){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){

			if(BOT || TOP || LEFT || RIGHT){
				frame[i*3+j*stride] = 255;
				frame[i*3+j*stride + 1] = 255;
				frame[i*3+j*stride + 2] = 255;

			}
			else{
				frame[i*3+j*stride] = 0;
				frame[i*3+j*stride + 1] = 0;
				frame[i*3+j*stride + 2] = 0;
			}

		}
	}
}

void writeWhiteOne(u32 x, u32 y, u8 * frame, u32 stride){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){


			if(i > x + 15 && i < max_x-15){
				frame[i*3+j*stride] = 255;
				frame[i*3+j*stride + 1] = 255;
				frame[i*3+j*stride + 2] = 255;
			}
			else{
				frame[i*3+j*stride] = 0;
				frame[i*3+j*stride + 1] = 0;
				frame[i*3+j*stride + 2] = 0;
			}

		}
	}
}

void writeWhiteTwo(u32 x, u32 y, u8 * frame, u32 stride){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){

			if(TOP || BOT || MID || TOP_RIGHT || BOT_LEFT){
				frame[i*3+j*stride] = 255;
				frame[i*3+j*stride + 1] = 255;
				frame[i*3+j*stride + 2] = 255;
			}
			else{
				frame[i*3+j*stride] = 0;
				frame[i*3+j*stride + 1] = 0;
				frame[i*3+j*stride + 2] = 0;
			}

		}
	}
}

void writeWhiteThree(u32 x, u32 y, u8 * frame, u32 stride){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){

			if(TOP || BOT || MID || RIGHT){
				frame[i*3+j*stride] = 255;
				frame[i*3+j*stride + 1] = 255;
				frame[i*3+j*stride + 2] = 255;
			}
			else{
				frame[i*3+j*stride] = 0;
				frame[i*3+j*stride + 1] = 0;
				frame[i*3+j*stride + 2] = 0;
			}
		}
	}
}

void writeWhiteFour(u32 x, u32 y, u8 * frame, u32 stride){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){

			if(MID || RIGHT || TOP_LEFT){
				frame[i*3+j*stride] = 255;
				frame[i*3+j*stride + 1] = 255;
				frame[i*3+j*stride + 2] = 255;
			}
			else{
				frame[i*3+j*stride] = 0;
				frame[i*3+j*stride + 1] = 0;
				frame[i*3+j*stride + 2] = 0;
			}

		}
	}
}

void writeWhiteFive(u32 x, u32 y, u8 * frame, u32 stride){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){

			if(TOP || BOT || MID || TOP_LEFT || BOT_RIGHT){
				frame[i*3+j*stride] = 255;
				frame[i*3+j*stride + 1] = 255;
				frame[i*3+j*stride + 2] = 255;
			}
			else{
				frame[i*3+j*stride] = 0;
				frame[i*3+j*stride + 1] = 0;
				frame[i*3+j*stride + 2] = 0;
			}

		}
	}
}

void writeWhiteSix(u32 x, u32 y, u8 * frame, u32 stride){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){

			if(TOP || BOT || MID || LEFT || BOT_RIGHT){
				frame[i*3+j*stride] = 255;
				frame[i*3+j*stride + 1] = 255;
				frame[i*3+j*stride + 2] = 255;
			}
			else{
				frame[i*3+j*stride] = 0;
				frame[i*3+j*stride + 1] = 0;
				frame[i*3+j*stride + 2] = 0;
			}

		}
	}
}

void writeWhiteSeven(u32 x, u32 y, u8 * frame, u32 stride){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){

			if(TOP || RIGHT){
				frame[i*3+j*stride] = 255;
				frame[i*3+j*stride + 1] = 255;
				frame[i*3+j*stride + 2] = 255;
			}
			else{
				frame[i*3+j*stride] = 0;
				frame[i*3+j*stride + 1] = 0;
				frame[i*3+j*stride + 2] = 0;
			}
		}
	}
}

void writeWhiteEight(u32 x, u32 y, u8 * frame, u32 stride){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){

			if(TOP || MID || BOT || RIGHT || LEFT){
				frame[i*3+j*stride] = 255;
				frame[i*3+j*stride + 1] = 255;
				frame[i*3+j*stride + 2] = 255;
			}
			else{
				frame[i*3+j*stride] = 0;
				frame[i*3+j*stride + 1] = 0;
				frame[i*3+j*stride + 2] = 0;
			}

		}
	}
}

void writeWhiteNine(u32 x, u32 y, u8 * frame, u32 stride){
	u32 max_x = x+36;//36 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){

			if(TOP || MID || BOT || RIGHT || TOP_LEFT){
				frame[i*3+j*stride] = 255;
				frame[i*3+j*stride + 1] = 255;
				frame[i*3+j*stride + 2] = 255;
			}
			else{
				frame[i*3+j*stride] = 0;
				frame[i*3+j*stride + 1] = 0;
				frame[i*3+j*stride + 2] = 0;
			}

		}
	}
}

void writePlayer(u32 x, u32 y, u8* frame, u32 stride){
	u32 max_x = x+72;//72 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){
			frame[i*3+j*stride] = 0;
			frame[i*3+j*stride + 1] = 0;
			frame[i*3+j*stride + 2] = 255;
		}
	}
}

void clearPlayer(u32 x, u32 y, u8* frame, u32 stride){
	u32 max_x = x+72;//72 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){
			frame[i*3+j*stride] = 255;
			frame[i*3+j*stride + 1] = 0;
			frame[i*3+j*stride + 2] = 0;
		}
	}
}

void writeEnemy(u32 x, u32 y, u8* frame, u32 stride){
	u32 max_x = x+72;//72 is how wide characters are
	u32 max_y = y+72;//72 is how tall characters are
	int i;
	for(i = x; i < max_x; i++){
		int j;
		for (j = y; j < max_y; j++){
			frame[i*3+j*stride] = 0;
			frame[i*3+j*stride + 1] = 255;
			frame[i*3+j*stride + 2] = 0;
		}
	}
}

void writeScore(u32 x, u32 y, int score, u8* frame, u32 stride){
	char val[49];//screen can fit 48 characters the way I am laying it out so we just add one for null terminator
	itoa(score, val, 10);//10 means base ten so it will be a decimal number
	int i = 0;
	while(val[i] != '\0'){
		switch(val[i]){
			case '0':
				writeWhiteZero(x+i*40, y, frame, stride);
				break;
			case '1':
				writeWhiteOne(x+i*40, y, frame, stride);
				break;
			case '2':
				writeWhiteTwo(x+i*40, y, frame, stride);
				break;
			case '3':
				writeWhiteThree(x+i*40, y, frame, stride);
				break;
			case '4':
				writeWhiteFour(x+i*40, y, frame, stride);
				break;
			case '5':
				writeWhiteFive(x+i*40, y, frame, stride);
				break;
			case '6':
				writeWhiteSix(x+i*40, y, frame, stride);
				break;
			case '7':
				writeWhiteSeven(x+i*40, y, frame, stride);
				break;
			case '8':
				writeWhiteEight(x+i*40, y, frame, stride);
				break;
			case '9':
				writeWhiteNine(x+i*40, y, frame, stride);
				break;

		}
		i++;
	}
}

void writeGameScreen(u8 * frame, u32 stride){
	int i;
	for(i = 0; i < GAME_RES_WIDTH; i++){//1280 is screen width
		int j;
		for (j = 0; j < GAME_RES_HEIGHT; j++){//720 is screen height
			if(i < COL1_COORD || i > COL5_END_COORD){
				frame[i*3+j*stride] = 0;
				frame[i*3+j*stride + 1] = 0;
				frame[i*3+j*stride + 2] = 0;
			}else
			if(j < 72){//72 is height of a character so I want to make sure the top of the screen is reserved for score
				frame[i*3+j*stride] = 0;
				frame[i*3+j*stride + 1] = 0;
				frame[i*3+j*stride + 2] = 0;
			}
			else{
				frame[i*3+j*stride] = 255;
				frame[i*3+j*stride + 1] = 0;
				frame[i*3+j*stride + 2] = 0;
			}
		}
	}
}

//void drawFrame(rgb_val ** twoDRGBArray, u8 *frame, u32 width, u32 height, u32 stride){
//	int i;
//	for(i = 0; i < width; i++){
//		int j;
////		int iPixelAddr = i*3;//3 color channels
//		for(j=0; j < height; j++){
//			frame[i*3 + j*stride] = twoDRGBArray[i][j].blue;
//			frame[i*3 + j*stride + 1] = twoDRGBArray[i][j].green;
//			frame[i*3 + j*stride + 2] = twoDRGBArray[i][j].red;
//
////			iPixelAddr += stride;
//		}
//	}
//}
