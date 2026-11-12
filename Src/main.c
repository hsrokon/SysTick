#include "stm32f1xx.h" // it includes ST's core device header file, official register definitions etc.
#include "systick.h"
#include "uart.h"

int main (void){

	systick_init(); //initializing our 1ms system timer
	uart_init();//initializing uart

	while(1){

		uart_send_string("Hello, from STM32 blue pill, using SysTick!!! Subhan Allah!\r\n");
		delay_ms(1000);//using SysTick for delay

	}
}

