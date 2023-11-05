/*
 * fsm_auto.c
 *
 *  Created on: Oct 22, 2023
 *      Author: ad
 */
#include "auto.h"


void auto_run(){
	if (isButtonPressed(0) == 1 ){
		HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
		                          |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
		MODE = MODE2;
	}
	if(MODE == MODE1){
		switch(firstCoupleLedAutoState){
			case LED_INIT:
				firstCoupleLedAutoState = RED;
				setTimer(0, 100);
				break;
			case RED:
				displayFirstLedCouple(RED);
				if(timer_flag[0] == 1){
					countdownFirstCoupleLed--;
					if(countdownFirstCoupleLed == 0){
						countdownFirstCoupleLed = greenDelay;
						firstCoupleLedAutoState = GREEN;
					}
					setTimer(0, 100);
				}
				break;
			case GREEN:
				displayFirstLedCouple(GREEN);
				if(timer_flag[0] == 1){
					countdownFirstCoupleLed--;
					if(countdownFirstCoupleLed == 0){
						countdownFirstCoupleLed = yellowDelay;
						firstCoupleLedAutoState = YELLOW;
					}
					setTimer(0, 100);
				}
				break;
			case YELLOW:
				displayFirstLedCouple(YELLOW);
				if(timer_flag[0] == 1){
					countdownFirstCoupleLed--;
					if(countdownFirstCoupleLed == 0){
						countdownFirstCoupleLed = redDelay;
						firstCoupleLedAutoState = RED;
					}
					setTimer(0, 100);
				}
				break;
			default:
				break;
		}
		switch(secondCoupleLedAutoState){
			case LED_INIT:
				secondCoupleLedAutoState = GREEN;
				setTimer(1, 100);
				break;
			case RED:
				displaySecondLedCouple(RED);
				if(timer_flag[1] == 1){
					countdownSecondCoupleLed--;
					if(countdownSecondCoupleLed == 0){
						countdownSecondCoupleLed = greenDelay;
						secondCoupleLedAutoState = GREEN;
					}
					setTimer(1, 100);
				}
				break;
			case GREEN:
				displaySecondLedCouple(GREEN);
				if(timer_flag[1] == 1){
					countdownSecondCoupleLed--;
					if(countdownSecondCoupleLed == 0){
						countdownSecondCoupleLed = yellowDelay;
						secondCoupleLedAutoState = YELLOW;
					}
					setTimer(1, 100);
				}
				break;
			case YELLOW:
				displaySecondLedCouple(YELLOW);
				if(timer_flag[1] == 1){
					countdownSecondCoupleLed--;
					if(countdownSecondCoupleLed == 0){
						countdownSecondCoupleLed = redDelay;
						secondCoupleLedAutoState = RED;
					}
					setTimer(1, 100);
				}
				break;
			default:
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
