#include "lndma.h"
#include "LED.h"

// ���� aSRC_Buffer ������Ϊ DMA ��������Դ,const �ؼ��ֽ� aSRC_Const_Buffer �����������Ϊ�������� 
const uint32_t aSRC_Buffer[BUFFER_SIZE] = {0x01020304,0x05060708,0x090A0B0C,0x0D0E0F10,
                                           0x11121314,0x15161718,0x191A1B1C,0x1D1E1F20,
                                           0x21222324,0x25262728,0x292A2B2C,0x2D2E2F30,
                                           0x31323334,0x35363738,0x393A3B3C,0x3D3E3F40,
                                           0x41424344,0x44564748,0x494A4B4C,0x4D4E4F50,
                                           0x51525345,0x55565758,0x595A5B5C,0x5D5E5F60,
                                           0x61626364,0x65666768,0x696A6B6C,0x6D6E6F70,
                                           0x71727374,0x75767778,0x797A7B7C,0x7D7E7F80};

//���� DMA ����Ŀ��洢��
uint32_t aDST_Buffer[BUFFER_SIZE];

//DMA�ṹ����
DMA_HandleTypeDef DMA_Handle;

//DMA���ú���
void dma_config(){

    //ʹ��DMA1ʱ��
    __HAL_RCC_DMA1_CLK_ENABLE();
    HAL_StatusTypeDef DMA_status = HAL_ERROR;
    
    //������ѡ��
    DMA_Handle.Instance                 = DMA1_Channel1;
    //�洢��������
    DMA_Handle.Init.Direction           = DMA_MEMORY_TO_MEMORY;
    //��������ģʽ
    DMA_Handle.Init.PeriphInc           = DMA_PINC_ENABLE;
    //�洢������ģʽ
    DMA_Handle.Init.MemInc              = DMA_MINC_ENABLE;
    //�������ݳ���32
    DMA_Handle.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
    //�洢�����ݳ���32
    DMA_Handle.Init.MemDataAlignment    = DMA_MDATAALIGN_WORD;
    //DMAģʽΪ��ͨ
    DMA_Handle .Init.Mode               = DMA_NORMAL;
    //DMA���ȼ�
    DMA_Handle.Init.Priority            = DMA_PRIORITY_HIGH;
    //���DMA��������������
    HAL_DMA_Init(&DMA_Handle);
    //��ȡDMA��ǰ״̬
    DMA_status = HAL_DMA_Start(&DMA_Handle,(uint32_t)aSRC_Buffer,(uint32_t)aDST_Buffer,32);
    
    // �ж�DMA״̬
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


