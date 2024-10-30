/*
 * led_7seg.h
 */

#ifndef INC_LED_7SEG_H_
#define INC_LED_7SEG_H_

#include "main.h"
#include "global.h"


void display7SEG(int num);
void update7SEG(int index);

void reset_7seg_counter();
void update_7seg_counter();

void update_auto_buffer();
void update_modify_buffer();

void led_7seg_run();

#endif /* INC_LED_7SEG_H_ */

