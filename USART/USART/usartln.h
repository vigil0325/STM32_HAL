#ifndef _USARTLN_H_
#define _USARTLN_H_

#include "stm32f1xx.h"

extern UART_HandleTypeDef g_uart1_handle;//USART���

void uart_init(uint32_t baudrate);
    
#endif

