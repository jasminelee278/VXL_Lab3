
#include "fsm.h"


int green_temp_counter;
int yellow_temp_counter;


void update_led_counter(){
	red_counter = led_red_duration;
	yellow_counter = led_yellow_duration;
	green_counter = led_green_duration;
}

void red_duration_process(){
	led_red_duration = red_counter;
	green_temp_counter = led_red_duration - led_yellow_duration;
	if (green_temp_counter > led_green_duration)
		led_green_duration = green_temp_counter;
	else if (green_temp_counter < led_green_duration){
		yellow_temp_counter = led_red_duration - led_green_duration;
		if (yellow_temp_counter > led_yellow_duration)
			led_yellow_duration = yellow_temp_counter;
		else led_red_duration = led_green_duration + led_yellow_duration;
	}
}

void yellow_duration_process(){
	led_yellow_duration = yellow_counter;
	green_temp_counter = led_red_duration - led_yellow_duration;
	if (green_temp_counter > led_green_duration)
		led_green_duration = green_temp_counter;
	else if (green_temp_counter < led_green_duration)
		led_red_duration = led_yellow_duration + led_green_duration;
}

void green_duration_process(){
	led_green_duration = green_counter;
	yellow_temp_counter = led_red_duration - led_green_duration;
	if (yellow_temp_counter > led_yellow_duration)
		led_yellow_duration = yellow_temp_counter;
	else if (yellow_temp_counter < led_yellow_duration)
		led_red_duration = led_yellow_duration + led_green_duration;
}

void fsm_run(){
	switch(status){
		case INIT:
			mode = 1;
			status = AUTO_RED_GREEN;
			setTimer(1, led_green_duration * 1000);
			led_clear();
			index_led = 0;
			setTimer(3, 250);
  			setTimer(4, 1000);
			isButtonPressed(0);
			break;
		case AUTO_RED_GREEN:
			led_control(0, RED);
			led_control(1, GREEN);
			led_color_pair[0] = RED;
			led_color_pair[1] = GREEN;
		    if (isTimerExpired(4) == 1){
		    	red_7seg_counter--;
		    	green_7seg_counter--;
		    	setTimer(4, 1000);
		    }
			if (isTimerExpired(1) == 1){
				reset_7seg_counter();
				status = AUTO_RED_YELLOW;
				setTimer(1, led_yellow_duration * 1000);
				index_led = 0;
			}
			if (isButtonPressed(0) == 1){
				led_clear();
				mode = 2;
				status = MODIFY_RED;
				setTimer(0, 250);
				setTimer(2, 5000);
				index_led = 0;
				isButtonPressed(1);
				isButtonPressed(2);
			}
			break;
		case AUTO_RED_YELLOW:
			led_control(0, RED);
			led_control(1, YELLOW);
			led_color_pair[0] = RED;
			led_color_pair[1] = YELLOW;
			if (isTimerExpired(4) == 1){
				red_7seg_counter--;
			    yellow_7seg_counter--;
			    setTimer(4, 1000);
			}
			if (isTimerExpired(1) == 1){
				reset_7seg_counter();
				status = AUTO_GREEN_RED;
				setTimer(1, led_green_duration * 1000);
				index_led = 0;
			}
			if (isButtonPressed(0) == 1){
				led_clear();
				mode = 2;
				status = MODIFY_RED;
				setTimer(0, 250);
				setTimer(2, 5000);
				index_led = 0;
				isButtonPressed(1);
				isButtonPressed(2);
			}
			break;
		case AUTO_GREEN_RED:
			led_control(0, GREEN);
			led_control(1, RED);
            led_color_pair[0] = GREEN;
            led_color_pair[1] = RED;
		    if (isTimerExpired(4) == 1){
		    	green_7seg_counter--;
		    	red_7seg_counter--;
		    	setTimer(4, 1000);
		    }
			if (isTimerExpired(1) == 1){
				reset_7seg_counter();
				status = AUTO_YELLOW_RED;
				setTimer(1, led_yellow_duration * 1000);
				index_led = 0;
			}
			if (isButtonPressed(0) == 1){
				led_clear();
				mode = 4;
				status = MODIFY_GREEN;
				setTimer(0, 250);
				setTimer(2, 5000);
				index_led = 0;
				isButtonPressed(1);
				isButtonPressed(2);
			}
			break;
		case AUTO_YELLOW_RED:
			led_control(0, YELLOW);
			led_control(1, RED);
            led_color_pair[0] = YELLOW;
            led_color_pair[1] = RED;
		    if (isTimerExpired(4) == 1){
		    	yellow_7seg_counter--;
		    	red_7seg_counter--;
		    	setTimer(4, 1000);
		    }
			if (isTimerExpired(1) == 1){
				reset_7seg_counter();
				status = AUTO_RED_GREEN;
				setTimer(1, led_green_duration * 1000);
				index_led = 0;
			}
			if (isButtonPressed(0) == 1){
				led_clear();
				mode = 3;
				status = MODIFY_YELLOW;
				setTimer(0, 250);
				setTimer(2, 5000);
				index_led = 0;
				isButtonPressed(1);
				isButtonPressed(2);
			}
			break;

		case MODIFY_RED:
			if (isTimerExpired(0) == 1){
				led_blinking(RED);
				setTimer(0, 250);
			}
			if (isTimerExpired(2) == 1){
				update_7seg_counter();
				setTimer(4, 1000);
				mode = 1;
				status = AUTO_RED_GREEN;
				setTimer(1, led_green_duration * 1000);
				index_led = 0;
			}
			if (isButtonPressed(0) == 1){
				led_clear();
				mode = 3;
				status = MODIFY_YELLOW;
				setTimer(0, 250);
				setTimer(2, 5000);
				index_led = 0;
				isButtonPressed(1);
				isButtonPressed(2);
			}
			if (isButtonPressed(1) == 1){
				red_counter++;
				if (red_counter > 99) red_counter = 5;
				setTimer(2, 5000);
			}
			if (isButtonPressed(2) == 1){
				red_duration_process();
				update_led_counter();
				update_7seg_counter();
				setTimer(4, 1000);
				mode = 1;
				status = AUTO_RED_GREEN;
				setTimer(1, led_green_duration * 1000);
				index_led = 0;
			}
			break;
		case MODIFY_YELLOW:
			if (isTimerExpired(0) == 1){
				led_blinking(YELLOW);
				setTimer(0, 250);
			}
			if (isTimerExpired(2) == 1){
				update_7seg_counter();
				setTimer(4, 1000);
				mode = 1;
				status = AUTO_YELLOW_RED;
				setTimer(1, led_yellow_duration * 1000);
				index_led = 0;
			}
			if (isButtonPressed(0) == 1){
				led_clear();
				mode = 4;
				status = MODIFY_GREEN;
				setTimer(0, 250);
				setTimer(2, 5000);
				index_led = 0;
				isButtonPressed(1);
				isButtonPressed(2);
			}
			if (isButtonPressed(1) == 1){
				yellow_counter++;
				if (yellow_counter > 99) yellow_counter = 3;
				setTimer(2, 5000);
			}
			if (isButtonPressed(2) == 1){
				yellow_duration_process();
				update_led_counter();
				update_7seg_counter();
				setTimer(4, 1000);
				mode = 1;
				status = AUTO_YELLOW_RED;
				setTimer(1, led_yellow_duration * 1000);
				index_led = 0;
			}
			break;
		case MODIFY_GREEN:
			if (isTimerExpired(0) == 1){
				led_blinking(GREEN);
				setTimer(0, 250);
			}
			if (isTimerExpired(2) == 1){
				update_7seg_counter();
				setTimer(4, 1000);
				mode = 1;
				status = AUTO_GREEN_RED;
				setTimer(1, led_green_duration * 1000);
				index_led = 0;
			}
			if (isButtonPressed(0) == 1){
				led_clear();
				mode = 2;
				status = MODIFY_RED;
				setTimer(0, 250);
				setTimer(2, 5000);
				index_led = 0;
				isButtonPressed(1);
				isButtonPressed(2);
			}
			if (isButtonPressed(1) == 1){
				green_counter++;
				if (green_counter > 99) green_counter = 2;
				setTimer(2, 5000);
			}
			if (isButtonPressed(2) == 1){
				green_duration_process();
				update_led_counter();
				update_7seg_counter();
				setTimer(4, 1000);
				mode = 1;
				status = AUTO_GREEN_RED;
				setTimer(1, led_green_duration * 1000);
				index_led = 0;
			}
			break;
		default:
			break;
	}
}
