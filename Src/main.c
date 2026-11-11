#include "stm32f1xx.h" // it includes ST's core device header file, official register definitions etc.
#include "systick.h"
#include "uart.h"

int main (void){
	systick_init(); //initializing our 1ms system timer
	while(1){
		//main infinite loop
	}
}

