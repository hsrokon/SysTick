#include "systick.h"

#define SYST_CSR (*(volatile uint32_t*)0xE000E010) // SysTick control and status register
#define SYST_RVR (*(volatile uint32_t*)0xE000E014) // ,, reload value register
#define SYST_CVR (*(volatile uint32_t*)0xE000E018) // ,, current value register
//Casting address to volatile 32-bit pointer and dereferencing(go to that mem address and read/write) it

int main (void){

	SYST_RVR=71999; //72MHz /1000(ms)=72000
	SYST_CVR=0; //Forcing current value reg to force reload
	SYST_CSR=(0x7<<0); // configuring CLOCKSOURCE, TICKINT, ENABLE
	//When counter reaches 0, value in the ReloadVR gets loaded on the CurrentVR

}
