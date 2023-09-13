#include "lndma_usart.h"
#include "usartln.h"

//DMA结构体句柄
DMA_HandleTypeDef g_DMA_Handle;

//DMA配置函数内存到外设
void dma_config(){

    //使能DMA1时钟
    __HAL_RCC_DMA1_CLK_ENABLE();
    
    //数据流选择存储器到外设要通道4
    g_DMA_Handle.Instance                 = DMA1_Channel4;
    //存储器到外设
    g_DMA_Handle.Init.Direction           = DMA_MEMORY_TO_PERIPH;
    //串口外设地址不递增模式
    g_DMA_Handle.Init.PeriphInc           = DMA_PINC_DISABLE;
    //存储器地址增量模式
    g_DMA_Handle.Init.MemInc              = DMA_MINC_ENABLE;
    //外设数据长度8
    g_DMA_Handle.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    //存储器数据长度8
    g_DMA_Handle.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    //DMA模式为普通
    g_DMA_Handle .Init.Mode               = DMA_NORMAL;
    //DMA优先级
    g_DMA_Handle.Init.Priority            = DMA_PRIORITY_HIGH;
    //完成DMA数据流参数配置
    HAL_DMA_Init(&g_DMA_Handle);
    
    //将DMA与外设连接到一起的函数
    __HAL_LINKDMA(&g_uart1_handle,hdmatx,g_DMA_Handle);
    
}

//比较寄存器函数
uint32_t buffercmp(const uint32_t* pbuffer1, uint32_t* pbuffer2, uint16_t bufferlength){
    
    //判断两个数据源的数据是否相等
    while(bufferlength--){
        if(*pbuffer1 != *pbuffer2){
            return 0;
        }
        pbuffer1++;
        pbuffer2++;
    }
    //正确返回1
    return 1;
}


