#ifndef SYSTICK_H_
#define SYSTICK_H_

#define STM32F103xB
#include "stm32f1xx.h" // it includes ST's core device header file, official register definitions etc.
#include <stdint.h>

void systick_init(void);//function that needs a global access needs to be declared in header file so linker can connect them.
void delay_ms(uint32_t delay);
extern volatile uint32_t ms_ticks; // "extern" tells compiler this variable exists, look for it, don't create new copy

#endif /* SYSTICK_H_ */
