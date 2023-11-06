/*
 * global.c
 *
 *  Created on: Oct 22, 2023
 *      Author: ad
 */
#include "global.h"

enum ModeState MODE;
enum AutoState autostate;


enum SegState modeSeg;

enum LedState firstCoupleLedAutoState;
enum LedState secondCoupleLedAutoState;
enum SegState seg7AutoState;

int redDelay = 10;
int greenDelay = 6;
int yellowDelay = 4;


int countdownFirstCoupleLed;
int countdownSecondCoupleLed;

void setValues(void){
	MODE = MODE1;
	autostate = AUTO_INIT;

	modeSeg = FIRST;

	firstCoupleLedAutoState = LED_INIT;
	secondCoupleLedAutoState = LED_INIT;
	seg7AutoState = SEG_INIT;

	countdownFirstCoupleLed = redDelay;
	countdownSecondCoupleLed = greenDelay;
}

