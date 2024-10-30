
#include "traffic.h"

GPIO_TypeDef* led_ports[] = {LED1_R_GPIO_Port, LED1_Y_GPIO_Port, LED1_G_GPIO_Port,
							 LED2_R_GPIO_Port, LED2_Y_GPIO_Port, LED2_G_GPIO_Port};
uint16_t led_pins[] = {LED1_R_Pin, LED1_Y_Pin, LED1_G_Pin, LED2_R_Pin, LED2_Y_Pin, LED2_G_Pin};
int pin_logic_value[] = {GPIO_PIN_RESET, GPIO_PIN_SET};


void led_clear(){
    HAL_GPIO_WritePin(LED1_R_GPIO_Port, LED1_R_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED1_Y_GPIO_Port, LED1_Y_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED1_G_GPIO_Port, LED1_G_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_R_GPIO_Port, LED2_R_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_Y_GPIO_Port, LED2_Y_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_G_GPIO_Port, LED2_G_Pin, GPIO_PIN_RESET);
}

void led_control(int ledth, int color){
	HAL_GPIO_WritePin(led_ports[ledth * 3], led_pins[ledth * 3], pin_logic_value[(color == RED)]);
	HAL_GPIO_WritePin(led_ports[ledth * 3 + 1], led_pins[ledth * 3 + 1], pin_logic_value[(color == YELLOW)]);
	HAL_GPIO_WritePin(led_ports[ledth * 3 + 2], led_pins[ledth * 3 + 2], pin_logic_value[(color == GREEN)]);
}

void led_blinking(int color){
    HAL_GPIO_TogglePin(led_ports[color], led_pins[color]);
    HAL_GPIO_TogglePin(led_ports[color + 3], led_pins[color + 3]);
}
