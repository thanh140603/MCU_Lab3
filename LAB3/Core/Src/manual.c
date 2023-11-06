/*
 * fsm_manual.c
 *
 *  Created on: Oct 22, 2023
 *      Author: ad
 */

#include "manual.h"

void displayIncrease(int delay){
	switch(modeSeg){
		case FIRST:
			showTimeDelay1(delay);
			modeSeg = SECOND;
			break;
		case SECOND:
			showTimeDelay2(delay);
			modeSeg = FIRST;
			break;
		default:
			break;
	}
}

void manual_run(){
	switch(MODE){
		case MODE2:
			if(timer_flag[3] == 1){
				toggleLeds(RED);
				displayIncrease(redDelay);
				setTimer(3, 25);
			}
			if (isButtonPressed(1)==1){
				redDelay +=1;
				greenDelay +=1;

				if(redDelay >= 99) redDelay = 1;
			}
			if (isButtonPressed(2)==1){
				HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
												  |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
				MODE = MODE1;
				setValues();
			}
			if (isButtonPressed(0) == 1){
				setTimer(3, 25);
				MODE = MODE3;
			}
			break;
		case MODE3:
			if(timer_flag[3] == 1){
				toggleLeds(YELLOW);
				displayIncrease(yellowDelay);
				setTimer(3, 25);
			}
			if (isButtonPressed(1)==1){
				yellowDelay +=1;

				if(yellowDelay >= 99) yellowDelay = 1;
			}
			if (isButtonPressed(2)==1){
				HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
												  |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
				MODE = MODE1;
				setValues();
			}
			if (isButtonPressed(0) == 1){
				MODE = MODE4;
			}
			break;
		case MODE4:
			if(timer_flag[3] == 1){
				toggleLeds(GREEN);
				displayIncrease(greenDelay);
				setTimer(3, 25);
			}
			if (isButtonPressed(1)==1){
				redDelay +=1;
				greenDelay +=1;

				if(greenDelay >= 99) greenDelay = 1;
			}
			if (isButtonPressed(2)==1){
				HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
												  |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
				MODE = MODE1;
				setValues();
			}
			if (isButtonPressed(0) == 1){
				MODE = MODE1;
			}
			break;
		default:
			break;
	}
}
