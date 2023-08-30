#ifndef _LNDMA_H_
#define _LNDMA_H_

#include "stm32f1xx.h"

#define BUFFER_SIZE 32

// ���� aSRC_Buffer ������Ϊ DMA ��������Դ,const �ؼ��ֽ� aSRC_Const_Buffer �����������Ϊ�������� 
extern const uint32_t aSRC_Buffer[BUFFER_SIZE];

//���� DMA ����Ŀ��洢��
extern uint32_t aDST_Buffer[BUFFER_SIZE];

//DMA�ṹ����
extern DMA_HandleTypeDef DMA_Handle;

void dma_config(void);
uint32_t buffercmp(const uint32_t* pbuffer1, uint32_t* pbuffer2, uint16_t bufferlength);

#endif
