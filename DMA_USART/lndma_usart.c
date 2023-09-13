#include "lndma_usart.h"
#include "usartln.h"

//DMA�ṹ����
DMA_HandleTypeDef g_DMA_Handle;

//DMA���ú����ڴ浽����
void dma_config(){

    //ʹ��DMA1ʱ��
    __HAL_RCC_DMA1_CLK_ENABLE();
    
    //������ѡ��洢��������Ҫͨ��4
    g_DMA_Handle.Instance                 = DMA1_Channel4;
    //�洢��������
    g_DMA_Handle.Init.Direction           = DMA_MEMORY_TO_PERIPH;
    //���������ַ������ģʽ
    g_DMA_Handle.Init.PeriphInc           = DMA_PINC_DISABLE;
    //�洢����ַ����ģʽ
    g_DMA_Handle.Init.MemInc              = DMA_MINC_ENABLE;
    //�������ݳ���8
    g_DMA_Handle.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    //�洢�����ݳ���8
    g_DMA_Handle.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    //DMAģʽΪ��ͨ
    g_DMA_Handle .Init.Mode               = DMA_NORMAL;
    //DMA���ȼ�
    g_DMA_Handle.Init.Priority            = DMA_PRIORITY_HIGH;
    //���DMA��������������
    HAL_DMA_Init(&g_DMA_Handle);
    
    //��DMA���������ӵ�һ��ĺ���
    __HAL_LINKDMA(&g_uart1_handle,hdmatx,g_DMA_Handle);
    
}

//�ȽϼĴ�������
uint32_t buffercmp(const uint32_t* pbuffer1, uint32_t* pbuffer2, uint16_t bufferlength){
    
    //�ж���������Դ�������Ƿ����
    while(bufferlength--){
        if(*pbuffer1 != *pbuffer2){
            return 0;
        }
        pbuffer1++;
        pbuffer2++;
    }
    //��ȷ����1
    return 1;
}


