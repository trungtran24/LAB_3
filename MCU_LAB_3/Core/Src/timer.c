/*
 * timer.c
 *
 *  Created on: Jan 10, 2023
 *      Author: 84915
 */


#include "main.h"
#include "input_reading.h"

void setTimer0(int duration);
void timer_run();

//our clock configured cycle
int TIMER_CYCLE = 10;

int timerTimeOut_counter = 0;
int timerTimeOut_flag = 1;

int timerTrafficHorizontal_counter = 0;
int timerTrafficHorizontal_flag = 1;

int timerTrafficVertical_counter = 0;
int timerTrafficVertical_flag = 1;

int timerBlink_counter = 0;
int timerBlink_flag = 1;

int timerLED7_counter = 0;
int timerLED7_flag = 1;

void setTimerTimeOut(int duration) {
	timerTimeOut_counter = duration / TIMER_CYCLE;
	timerTimeOut_flag = 0;
}

void setTimerTrafficHorizontal(int duration) {
	timerTrafficHorizontal_counter = duration / TIMER_CYCLE;
	timerTrafficHorizontal_flag = 0;
}

void setTimerTrafficVertical(int duration) {
	timerTrafficVertical_counter = duration / TIMER_CYCLE;
	timerTrafficVertical_flag = 0;
}

void setTimerBlink(int duration) {
	timerBlink_counter = duration / TIMER_CYCLE;
	timerBlink_flag = 0;
}

void setTimerLED7(int duration) {
	timerLED7_counter = duration / TIMER_CYCLE;
	timerLED7_flag = 0;
}

void timer_run() {
	if (timerTrafficHorizontal_counter > 0) {
		timerTrafficHorizontal_counter--;
		if (timerTrafficHorizontal_counter == 0)
			timerTrafficHorizontal_flag = 1;
	}
	if (timerTrafficVertical_counter > 0) {
		timerTrafficVertical_counter--;
		if (timerTrafficVertical_counter == 0)
			timerTrafficVertical_flag = 1;
	}
	if (timerBlink_counter > 0) {
		timerBlink_counter--;
		if (timerBlink_counter == 0)
			timerBlink_flag = 1;
	}
	if (timerLED7_counter > 0) {
		timerLED7_counter--;
		if (timerLED7_counter == 0)
			timerLED7_flag = 1;
	}
	if (timerTimeOut_counter > 0) {
		timerTimeOut_counter--;
		if (timerTimeOut_counter == 0)
			timerTimeOut_flag = 1;
	}
}
