
#include "global.h"

int status = INIT;
int mode = 1;

int led_red_duration = 5;
int led_yellow_duration = 3;
int led_green_duration = 2;
int red_counter = 5;
int yellow_counter = 3;
int green_counter = 2;

int index_led = 0;
int led_buffer[6] = {0, 5, 0, 3, 0, 2};
int led_counter_buffer[6] = {0, 5, 0, 3, 0, 2};
int mode_buffer[2] = {0, 1};
int led_color_pair[2] = {RED, GREEN};
int red_7seg_counter = 5;
int yellow_7seg_counter = 3;
int green_7seg_counter = 2;


void init_traffic(){
	HAL_GPIO_TogglePin(LED1_R_GPIO_Port, LED1_R_Pin);
	HAL_GPIO_TogglePin(LED1_Y_GPIO_Port, LED1_Y_Pin);
	HAL_GPIO_TogglePin(LED1_G_GPIO_Port, LED1_G_Pin);
	HAL_GPIO_TogglePin(LED2_R_GPIO_Port, LED2_R_Pin);
	HAL_GPIO_TogglePin(LED2_Y_GPIO_Port, LED2_Y_Pin);
	HAL_GPIO_TogglePin(LED2_G_GPIO_Port, LED2_G_Pin);
}
