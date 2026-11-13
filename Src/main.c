#include "systick.h"
#include "uart.h"
#include "clock.h"

int main (void){

	clock_init_72mhz();//initializes HSE and 72MHz clk
	systick_init(); //initializing our 1ms system timer
	uart_init();//initializing uart

	while(1){

		uart_send_string("Hello, from STM32 blue pill, using SysTick!!! Subhan Allah!\r\n");
		delay_ms(1000);//using SysTick for delay

	}
}

