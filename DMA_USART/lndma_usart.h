#ifndef _LNDMA_USART_H_
#define _LNDMA_USART_H_

#include "stm32f1xx.h"

//DMA结构体句柄
extern DMA_HandleTypeDef g_DMA_Handle;

//DMA配置函数
void dma_config(void);

uint32_t buffercmp(const uint32_t* pbuffer1, uint32_t* pbuffer2, uint16_t bufferlength);

#endif
