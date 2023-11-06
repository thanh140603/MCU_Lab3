/*
 * global.h
 *
 *  Created on: Oct 22, 2023
 *      Author: ad
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"


enum ModeState {MODE1 = 1, MODE2 = 2, MODE3 = 3, MODE4 = 4};
enum LedState {LED_INIT, RED, GREEN, YELLOW};
enum AutoState {AUTO_INIT, RED_GREEN, RED_YELLOW, GREEN_RED, YELLOW_RED};
enum LedToggleState {TOGGLE_INIT, TOGGLE};
enum SegState {SEG_INIT, FIRST, SECOND};
enum IncreaseDelayState {INCREASE_INIT, INCREASE};


extern enum ModeState MODE;
extern enum AutoState autostate;

extern enum SegState modeSeg;

extern enum LedState firstCoupleLedAutoState;
extern enum LedState secondCoupleLedAutoState;
extern enum SegState seg7AutoState;

extern int redDelay;
extern int greenDelay;
extern int yellowDelay;



extern int countdownFirstCoupleLed;
extern int countdownSecondCoupleLed;

void setValues(void);


#endif /* INC_GLOBAL_H_ */
