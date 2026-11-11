#include "systick.h"

#define SYST_CSR (*(volatile uint32_t*)0xE000E010) // SysTick control and status register
#define SYST_RVR (*(volatile uint32_t*)0xE000E014) // ,, reload value register
#define SYST_CVR (*(volatile uint32_t*)0xE000E018) // ,, current value register
//Casting address to volatile 32-bit pointer and dereferencing(go to that mem address and read/write) it

volatile uint32_t ms_ticks=0;
//volatile to tell compiler this var can change, so it does not cache a var value in a CPU reg
//uint32_t ensures var holds a + 32 bit wide integer, predictable size for different computer architecture

int main (void){

	SYST_RVR=71999; //72MHz /1000(ms)=72000
	SYST_CVR=0; //Forcing current value reg to force reload
	SYST_CSR=(0x7<<0); // configuring CLOCKSOURCE, TICKINT, ENABLE
	//When counter reaches 0, value in the ReloadVR gets loaded on the CurrentVR, counter starts counting again

	while(1){
		//main loop
	}
}

//Enabling TICKINT, CPU will need SysTick handler every time timer hits 0.
void SysTick_Handler(void){
	ms_ticks++;//increment every 1ms.
}

void delay_ms(uint32_t delay){
	uint32_t start_time = ms_ticks;
	while((ms_ticks-start_time)<delay){
		//Will wait till desired delay time elapses
		//Creates a non-blocking delay
	}
}
