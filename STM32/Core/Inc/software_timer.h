#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

int TICK;
int MAX_PARAM;

extern int timer_counter[];
extern int timer_flag[];


void setTimer(int index, int duration);
int isTimerExpired(int index);
void timer_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
