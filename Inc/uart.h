#ifndef UART_H_
#define UART_H_

#define STM32F103xB
#include "stm32f1xx.h" // it includes ST's core device header file, official register definitions etc.
#include <stdint.h>

void uart_init(void);
void uart_send_char(char c);
void uart_send_string(const char *string);

#endif /* UART_H_ */
