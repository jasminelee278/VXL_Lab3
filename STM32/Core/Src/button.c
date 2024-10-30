
#include "button.h"

#define MAX_BUTTONS		3
#define NORMAL_STATE 	GPIO_PIN_SET
#define PRESSED_STATE 	GPIO_PIN_SET

int KeyReg0[MAX_BUTTONS] = {NORMAL_STATE};
int KeyReg1[MAX_BUTTONS] = {NORMAL_STATE};
int KeyReg2[MAX_BUTTONS] = {NORMAL_STATE};
int KeyReg3[MAX_BUTTONS] = {NORMAL_STATE};

int TimeOutForKeyPress[MAX_BUTTONS] = {500};
int button_pressed[MAX_BUTTONS] = {0};
int button_long_pressed[MAX_BUTTONS] = {0};

GPIO_TypeDef* butt_ports[MAX_BUTTONS] = {BUTT_1_GPIO_Port, BUTT_2_GPIO_Port, BUTT_3_GPIO_Port};
uint16_t butt_pins[MAX_BUTTONS] = {BUTT_1_Pin, BUTT_2_Pin, BUTT_3_Pin};


int isButtonPressed(int index){
	if(button_pressed[index] == 1){
		button_pressed[index] = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPressed(int index){
	if(button_long_pressed[index] == 1){
		button_long_pressed[index] = 0;
		return 1;
	}
	return 0;
}

void getKeyInput(){
	for (int i = 0; i < MAX_BUTTONS; i++){
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		KeyReg0[i] = HAL_GPIO_ReadPin(butt_ports[i], butt_pins[i]);

		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg2[i] != KeyReg3[i]){
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg2[i] == PRESSED_STATE){
					button_pressed[i] = 1;
					TimeOutForKeyPress[i] = 500;
				}
			}
			else {
				TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0){
					TimeOutForKeyPress[i] = 500;
					if (KeyReg2[i] == PRESSED_STATE){
						button_long_pressed[i] = 1;
					}
				}
			}
		}
	}

}

