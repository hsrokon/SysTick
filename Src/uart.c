#include "uart.h"

void uart_init(void){

	RCC->APB2ENR |= (1<<14)|(1<<2);
	GPIOA->CRH &= ~(0xFF<<4);
	GPIOA->CRH |= (0x4B<<4); // 9 Tx, 10 Rx

	//Baud rate for 72MHz (27.3.4) |Cal_1: 72MHz/(16*9600)=468.75 | 468=111010100=0x1D4 | 0.75*16=12(in Hex can be rep as 0xC)=00010010 | 0x1D4C
	//Cal_2: 72MHz/9600 = 7500 = 0x1D4C
	USART1->BRR=0x1D4C; // 0x1D4C for 72MHz
	USART1->CR1 |=(1<<13)|(1<<3)|(1<<2);
}

void uart_send_char(char c){
	//Waiting for the transmit data register(TXE) to be 1.
	while(!(USART1->SR &(1<<7)));//(1<<7) is a bit mask = 0000 0000 1000 0000, that is compared to every bit of Status Register(SR)

	USART1->DR=c;
}

void uart_send_string(const char *string){//here "*" is a pointer, points to mem address where string starts
	while(*string){//here"*" is a dereference operator, which can access or modify the stored value at that address
		uart_send_char(*string++);//first sends the single character then increments
	}
}
