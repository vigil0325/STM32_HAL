#ifndef _USARTLN_H_
#define _USARTLN_H_

#include "stm32f1xx.h"

extern UART_HandleTypeDef g_uart1_handle;//USART句柄
extern uint8_t g_rx_buffer[1];//HAL库使用的串口接收数据缓存区
extern uint8_t g_rx_usart1_flag;//串口接收到数据标志

void uart_init(uint32_t baudrate);
void Usart_SendString(uint8_t * str);
void show_message(void);
    
#endif

