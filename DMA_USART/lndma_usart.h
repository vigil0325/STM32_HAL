#ifndef _LNDMA_USART_H_
#define _LNDMA_USART_H_

#include "stm32f1xx.h"

//DMA�ṹ����
extern DMA_HandleTypeDef g_DMA_Handle;

//DMA���ú���
void dma_config(void);

uint32_t buffercmp(const uint32_t* pbuffer1, uint32_t* pbuffer2, uint16_t bufferlength);

#endif
