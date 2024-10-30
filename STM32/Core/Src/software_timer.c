
#include "software_timer.h"

#define TICK 		10
#define MAX_PARAM	5

int timer_counter[MAX_PARAM] = {0};
int timer_flag[MAX_PARAM] = {0};


void setTimer(int index, int duration){
    timer_counter[index] = duration / TICK;
    timer_flag[index] = 0;
}

int isTimerExpired(int index){
	if(timer_flag[index] == 1){
		timer_flag[index] = 0;
		return 1;
	}
	return 0;
}

void timer_run(){
    for (int i = 0; i < MAX_PARAM; i++){
        if(timer_counter[i] > 0){
            timer_counter[i]--;
            if (timer_counter[i] == 0) timer_flag[i] = 1;
        }
    }
}
