#include "clock.h"

void clock_init_72mhz(void){
	RCC->CR |= (1<<16); //HSE ON
	while(!(RCC->CR & (1<<17)));//wait until HSE stable/ready


	//Configuring flash access control register, so CPU don't fetch fast and CRASH
	FLASH->ACR |= FLASH_ACR_PRFTBE;//Prefetch buffer enabled, bit 4 of ACR,"FLASH_ACR_PRFTBE" is a CMSIS macro from stm32f103xb.h file,
	FLASH->ACR &= ~(FLASH_ACR_LATENCY);
	// FLASH_ACR_LATENCY is FLASH_ACR_LATENCY_Msk which clears bit [2:0] and is defined 0x7UL(Unsigned Long), so 0x7UL=0x00000007 (8*4=32bit)=29 zeroes, 3 1s at last
	FLASH->ACR |= (0x2<<0); // in stm32f103xb.h, FLASH_ACR_LATENCY_2 is written 0x4=100, but we need 10 which is 0x2(acc. to ref. manual), header file has mistaken it

	//Configuring Clock Configuration Register
	//Reset
	RCC->CFGR &= ~((0xF<<18)|(1<<17)|(1<<16)|(0x3<<0));//Resetting PLLMUL[3:0], PLLXTPRE (so no division is pre configured), PLLSRC, SW[1:0]
	//Configure
	RCC->CFGR |= (0x7<<18)|(1<<16);
	//PLLMUL=x9, PLL multiplication factor 9 | selected HSE as PLL input clock source

	RCC->CR |= (1<<24); // PLL Enabled | CR= Control Register for Clock
	while(!(RCC->CR & (1<<25)));//Wait for PLL to lock

	RCC->CFGR &= ~((1<<1)|(1<<0));//Resetting individually instead with hex, so only 2 desired bits gets reset instead of 4 unintentionally,
	RCC->CFGR |= (0x2<<0);// Selected PLL as system clock

	//Checking if PLL is selected as System Clock with SWS=System Control Switch Status, if not selected then wait
	while((RCC->CFGR & (3<<2)!=(2<<2)));
	//Mask (3<<2)=shift decimal 3 (11 in bin) 2 steps left, which isolates bits 3 and 2 for checking. Then we check it against (2<<2), shifting dec 2 (10 in bin)
	//10: PLL used as system clock
}
