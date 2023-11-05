/*
 * fsm_manual.c
 *
 *  Created on: Oct 22, 2023
 *      Author: ad
 */

#include "manual.h"

void mode2_run(){
	switch(mode2Toggle){
		case TOGGLE_INIT:
			HAL_GPIO_WritePin(GPIOA, RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
	                          |YELLOW2_Pin|GREEN2_Pin, GPIO_PIN_SET);
			mode2Toggle = TOGGLE;
			setTimer(3, 25);
			break;
		case TOGGLE:
			if(timer_flag[3] == 1){
				toggleLeds(RED);
				setTimer(3, 25);
			}
			break;
		default:
			break;
	}

	switch(mode2Increase){
			case INCREASE_INIT:
				if (isButtonPressed(1)==1){
					mode2Increase = INCREASE;
					redDelay +=1;
					greenDelay +=1;
				}

				break;
			case INCREASE:
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
				break;

			default:
				break;
		}

	switch(mode2Seg){
		case SEG_INIT:
			mode2Seg = FIRST;
			setTimer(4, 25);
			break;
		case FIRST:
			if(timer_flag[4] == 1){
				showTimeDelay1(redDelay);
				mode2Seg = SECOND;
				setTimer(4, 25);
			}
			break;
		case SECOND:
			if(timer_flag[4] == 1){
				showTimeDelay2(redDelay);
				setTimer(4, 25);
				mode2Seg = FIRST;
			}
			break;
		default:
			break;
	}
}

void mode3_run(){
	switch(mode3Toggle){
		case TOGGLE_INIT:
			HAL_GPIO_WritePin(GPIOA, RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
	                          |YELLOW2_Pin|GREEN2_Pin, GPIO_PIN_SET);
			mode3Toggle = TOGGLE;
			setTimer(5, 25);
			break;
		case TOGGLE:
			if(timer_flag[5] == 1){
				toggleLeds(YELLOW);
				setTimer(5, 25);
			}
			break;
		default:
			break;
	}

	switch(mode3Increase){
			case INCREASE_INIT:
				if (isButtonPressed(1)==1){
					mode3Increase = INCREASE;
					yellowDelay +=1;
					redDelay +=1;
				}

				break;
			case INCREASE:
				if (isButtonPressed(1)==1){
					yellowDelay +=1;
					redDelay +=1;
					if(yellowDelay >= 99) yellowDelay = 1;
				}
				if (isButtonPressed(2)==1){
					HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
							                          |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
					MODE = MODE1;
					setValues();
				}
				break;

			default:
				break;
		}

	switch(mode3Seg){
		case SEG_INIT:
			mode3Seg = FIRST;
			setTimer(6, 25);
			break;
		case FIRST:
			if(timer_flag[6] == 1){
				showTimeDelay1(yellowDelay);
				mode3Seg = SECOND;
				setTimer(6, 25);
			}
			break;
		case SECOND:
			if(timer_flag[6] == 1){
				showTimeDelay2(yellowDelay);
				setTimer(6, 25);
				mode3Seg = FIRST;
			}
			break;
		default:
			break;
	}
}

void mode4_run(){
	switch(mode4Toggle){
		case TOGGLE_INIT:
			HAL_GPIO_WritePin(GPIOA, RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
	                          |YELLOW2_Pin|GREEN2_Pin, GPIO_PIN_SET);
			mode4Toggle = TOGGLE;
			setTimer(7, 25);
			break;
		case TOGGLE:
			if(timer_flag[7] == 1){
				toggleLeds(GREEN);
				setTimer(7, 25);
			}
			break;
		default:
			break;
	}

	switch(mode4Increase){
			case INCREASE_INIT:
				if (isButtonPressed(1)==1){
					mode4Increase = INCREASE;
					greenDelay +=1;
					redDelay +=1;
				}

				break;
			case INCREASE:
				if (isButtonPressed(1)==1){
					greenDelay +=1;
					redDelay +=1;
					if(greenDelay >= 99) greenDelay = 1;
				}
				if (isButtonPressed(2)==1){
					HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
							                          |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
					MODE = MODE1;
					setValues();
				}
				break;

			default:
				break;
		}

	switch(mode4Seg){
		case SEG_INIT:
			mode4Seg = FIRST;
			setTimer(8, 25);
			break;
		case FIRST:
			if(timer_flag[8] == 1){
				showTimeDelay1(greenDelay);
				mode4Seg = SECOND;
				setTimer(8, 25);
			}
			break;
		case SECOND:
			if(timer_flag[8] == 1){
				showTimeDelay2(greenDelay);
				setTimer(8, 25);
				mode4Seg = FIRST;
			}
			break;
		default:
			break;
	}
}

void manual_run(){
	switch(MODE){
		case MODE2:
			mode2_run();
			if (isButtonPressed(0) == 1){
				MODE = MODE3;
			}
			break;
		case MODE3:
			mode3_run();
			if (isButtonPressed(0) == 1){
				MODE = MODE4;
			}
			break;
		case MODE4:
			mode4_run();
			if (isButtonPressed(0) == 1){
				HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
						                          |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
				MODE = MODE1;
				setValues();
			}
			break;
		default:
			break;
	}
}
