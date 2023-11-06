/*
 * fsm_auto.c
 *
 *  Created on: Oct 22, 2023
 *      Author: ad
 */
#include "auto.h"


void auto_run(){
	if(MODE == MODE1){
		switch(autostate){
			case AUTO_INIT:
				autostate = RED_GREEN;
				setTimer(0, 100);
				break;
			case RED_GREEN:
				if (isButtonPressed(0) == 1 ){
					HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
											  |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
					MODE = MODE2;
					HAL_GPIO_WritePin(GPIOA, RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
						                          |YELLOW2_Pin|GREEN2_Pin, GPIO_PIN_SET);
					setTimer(3, 25);
					break;
				}
				displayFirstLedCouple(RED);
				displaySecondLedCouple(GREEN);
				if(timer_flag[0] == 1){
					countdownFirstCoupleLed--;
					countdownSecondCoupleLed--;
					if(countdownSecondCoupleLed == 0){
						countdownSecondCoupleLed = yellowDelay;
						autostate = RED_YELLOW;
					}
					setTimer(0, 100);
				}
				break;
			case RED_YELLOW:
				if (isButtonPressed(0) == 1 ){
					HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
											  |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
					MODE = MODE2;
					break;
				}
				displayFirstLedCouple(RED);
				displaySecondLedCouple(YELLOW);
				if(timer_flag[0] == 1){
					countdownFirstCoupleLed--;
					countdownSecondCoupleLed--;
					if(countdownSecondCoupleLed == 0){
						countdownSecondCoupleLed = redDelay;
						countdownFirstCoupleLed = greenDelay;
						autostate = GREEN_RED;
					}
					setTimer(0, 100);
				}
				break;
			case GREEN_RED:
				if (isButtonPressed(0) == 1 ){
					HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
											  |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
					MODE = MODE2;
					break;
				}
				displayFirstLedCouple(GREEN);
				displaySecondLedCouple(RED);
				if(timer_flag[0] == 1){
					countdownFirstCoupleLed--;
					countdownSecondCoupleLed--;
					if(countdownFirstCoupleLed == 0){
						countdownFirstCoupleLed = yellowDelay;
						autostate = YELLOW_RED;
					}
					setTimer(0, 100);
				}
				break;
			case YELLOW_RED:
				if (isButtonPressed(0) == 1 ){
					HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
											  |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
					MODE = MODE2;
					break;
				}
				displayFirstLedCouple(RED);
				displaySecondLedCouple(GREEN);
				if(timer_flag[0] == 1){
					countdownFirstCoupleLed--;
					countdownSecondCoupleLed--;
					if(countdownFirstCoupleLed == 0){
						countdownSecondCoupleLed = greenDelay;
						countdownFirstCoupleLed = redDelay;
						autostate = RED_GREEN;
					}
					setTimer(0, 100);
				}
				break;
		}
		switch(seg7AutoState){
			case SEG_INIT:
				seg7AutoState = FIRST;
				setTimer(2, 1);
				break;
			case FIRST:
				if(timer_flag[2] == 1){
					showTimeDelay_First(countdownFirstCoupleLed, countdownSecondCoupleLed);
					seg7AutoState = SECOND;
					setTimer(2, 50);
				}
				break;
			case SECOND:
				if(timer_flag[2] == 1){
					showTimeDelay_Second(countdownFirstCoupleLed, countdownSecondCoupleLed);
					seg7AutoState = FIRST;
					setTimer(2, 50);
				}
				break;
			default:
				break;
		}
	}
}
