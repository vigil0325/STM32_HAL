#ifndef _LNDMA_H_
#define _LNDMA_H_

#include "stm32f1xx.h"

#define BUFFER_SIZE 32

// 定义 aSRC_Buffer 数组作为 DMA 传输数据源,const 关键字将 aSRC_Const_Buffer 数组变量定义为常量类型 
extern const uint32_t aSRC_Buffer[BUFFER_SIZE];

//定义 DMA 传输目标存储器
extern uint32_t aDST_Buffer[BUFFER_SIZE];

//DMA结构体句柄
extern DMA_HandleTypeDef DMA_Handle;

void dma_config(void);
uint32_t buffercmp(const uint32_t* pbuffer1, uint32_t* pbuffer2, uint16_t bufferlength);

#endif
