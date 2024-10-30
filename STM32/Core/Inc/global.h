/*
 * global.h
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "button.h"
#include "traffic.h"
#include "led_7seg.h"
#include "fsm.h"


#define INIT 	            10

#define RED 	            0
#define YELLOW	            1
#define GREEN	            2

#define AUTO_RED_GREEN  	11
#define AUTO_RED_YELLOW 	12
#define AUTO_GREEN_RED  	13
#define AUTO_YELLOW_RED 	14

#define MODIFY_RED  	    21
#define MODIFY_YELLOW 	    22
#define MODIFY_GREEN  	    23

#define MAX_LED_7SEG		4

extern int status;
extern int mode;

extern int led_red_duration;
extern int led_yellow_duration;
extern int led_green_duration;
extern int red_counter;
extern int yellow_counter;
extern int green_counter;

extern int index_led;
extern int led_buffer[];
extern int led_counter_buffer[];
extern int mode_buffer[];
extern int led_color_pair[];
extern int red_7seg_counter;
extern int yellow_7seg_counter;
extern int green_7seg_counter;


void init_traffic();

#endif /* INC_GLOBAL_H_ */
