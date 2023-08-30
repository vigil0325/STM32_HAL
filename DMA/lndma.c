#include "lndma.h"
#include "LED.h"

// 定义 aSRC_Buffer 数组作为 DMA 传输数据源,const 关键字将 aSRC_Const_Buffer 数组变量定义为常量类型 
const uint32_t aSRC_Buffer[BUFFER_SIZE] = {0x01020304,0x05060708,0x090A0B0C,0x0D0E0F10,
                                           0x11121314,0x15161718,0x191A1B1C,0x1D1E1F20,
                                           0x21222324,0x25262728,0x292A2B2C,0x2D2E2F30,
                                           0x31323334,0x35363738,0x393A3B3C,0x3D3E3F40,
                                           0x41424344,0x44564748,0x494A4B4C,0x4D4E4F50,
                                           0x51525345,0x55565758,0x595A5B5C,0x5D5E5F60,
                                           0x61626364,0x65666768,0x696A6B6C,0x6D6E6F70,
                                           0x71727374,0x75767778,0x797A7B7C,0x7D7E7F80};

//定义 DMA 传输目标存储器
uint32_t aDST_Buffer[BUFFER_SIZE];

//DMA结构体句柄
DMA_HandleTypeDef DMA_Handle;

//DMA配置函数
void dma_config(){

    //使能DMA1时钟
    __HAL_RCC_DMA1_CLK_ENABLE();
    HAL_StatusTypeDef DMA_status = HAL_ERROR;
    
    //数据流选择
    DMA_Handle.Instance                 = DMA1_Channel1;
    //存储器到外设
    DMA_Handle.Init.Direction           = DMA_MEMORY_TO_MEMORY;
    //外设增量模式
    DMA_Handle.Init.PeriphInc           = DMA_PINC_ENABLE;
    //存储器增量模式
    DMA_Handle.Init.MemInc              = DMA_MINC_ENABLE;
    //外设数据长度32
    DMA_Handle.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
    //存储器数据长度32
    DMA_Handle.Init.MemDataAlignment    = DMA_MDATAALIGN_WORD;
    //DMA模式为普通
    DMA_Handle .Init.Mode               = DMA_NORMAL;
    //DMA优先级
    DMA_Handle.Init.Priority            = DMA_PRIORITY_HIGH;
    //完成DMA数据流参数配置
    HAL_DMA_Init(&DMA_Handle);
    //获取DMA当前状态
    DMA_status = HAL_DMA_Start(&DMA_Handle,(uint32_t)aSRC_Buffer,(uint32_t)aDST_Buffer,32);
    
    // 判断DMA状态
    if(DMA_status != HAL_OK){
        while(1){
            led_operation(RED,OPEN,500);
            led_operation(RED,CLOSE,500);
            led_operation(GREEN,OPEN,500);
            led_operation(GREEN,CLOSE,500);
            led_operation(BLUE,OPEN,500);
            led_operation(BLUE,CLOSE,500);
        }
    }
    
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


