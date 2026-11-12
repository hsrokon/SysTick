#include "clock.h"

void clock_init_72mhz(void){
	RCC->CR |= (1<<16); //HSE ON
	while(!(RCC->CR & (1<<17)));//wait until HSE stable/ready






	RCC->CFGR |= (0x7<<18)|(1<<16)|(0x2<<0);
	//PLLMUL=x9, PLL multiplication factor 9 | selected HSE as PLL input clock source | Selected PLL as system clock

	RCC->CR |= (1<<24); // PLL Enable
	while(!(RCC->CR & (1<<25)));//Wait for PLL to lock

}
