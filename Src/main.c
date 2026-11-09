#include "systick.h"

#define SYST_CSR (*(volatile uint32_t*)0xE000E010) // SysTick control and status register
#define SYST_RVR (*(volatile uint32_t*)0xE000E014) // ,, reload value register
#define SYST_CVR (*(volatile uint32_t*)0xE000E018) // ,, current value register
//Casting address to volatile 32-bit pointer and dereference(go to that mem address and read/write) it

int main (void){

}
