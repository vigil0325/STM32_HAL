
#include "usartln.h"
#include "stdio.h"

UART_HandleTypeDef g_uart1_handle;//UART���

//���ô��ڹ�������
void uart_init(uint32_t baudrate){
    
    //����ṹ��
    g_uart1_handle.Instance          = USART1;
    g_uart1_handle.Init.BaudRate     = baudrate;
    g_uart1_handle.Init.WordLength   = UART_WORDLENGTH_8B;
    g_uart1_handle.Init.StopBits     = UART_STOPBITS_1;
    g_uart1_handle.Init.Parity       = UART_PARITY_NONE;
    g_uart1_handle.Init.Mode         = UART_MODE_TX_RX;
    g_uart1_handle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
    HAL_UART_Init(&g_uart1_handle);
    
    __HAL_UART_ENABLE_IT(&g_uart1_handle,UART_IT_RXNE);
}

//���ڵײ��ʼ��
//�ȳ�ʼ��ʱ�ӣ��ٳ�ʼ��IO��ʹ��USAR1T1�жϣ��������ȼ�
void HAL_UART_MspInit(UART_HandleTypeDef *huart){
    
    //����Ǵ���1�����д���1�ĳ�ʼ��
    if(huart->Instance == USART1){
        //ʹ��USTRA1����ӦIO��ʱ��
        __HAL_RCC_USART1_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();
        
        //����GPIO�ṹ��,����������������������벻�������ٶ�
        GPIO_InitTypeDef gpiotx_struct;
        gpiotx_struct.Pin   = GPIO_PIN_9;
        gpiotx_struct.Mode  = GPIO_MODE_AF_PP;//����ʽ����
        gpiotx_struct.Pull = GPIO_PULLUP;
        gpiotx_struct.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(GPIOA,&gpiotx_struct);
    
        GPIO_InitTypeDef gpiorx_struct;
        gpiorx_struct.Pin   = GPIO_PIN_10;
        gpiorx_struct.Mode  = GPIO_MODE_AF_INPUT;//����
        gpiorx_struct.Pull  = GPIO_PULLUP;//��������Ϊ����ʱ�ź��Ǹߵ�ƽ
        HAL_GPIO_Init(GPIOA,&gpiorx_struct);
    
        //�����ж����ȼ�
        HAL_NVIC_SetPriority(USART1_IRQn,0,1);
        HAL_NVIC_EnableIRQ(USART1_IRQn);//ʹ���ж�
    }
    
}



//�ض���fputc��USART1���ڣ���ʹ��printf
int fputc(int ch,FILE *f){
    
    HAL_UART_Transmit(&g_uart1_handle,(uint8_t *)&ch,1,1000);
    return(ch);
    
}



//�ض��� c �⺯�� scanf ������ USARTx����д����ʹ�� scanf��getchar �Ⱥ���
int fgetc(FILE *f)
{
    int ch;
    HAL_UART_Receive(&g_uart1_handle, (uint8_t *)&ch, 1, 1000);
    return(ch);
    
}

//����1�жϷ�����
void USART1_IRQHandler(void){
    
    uint8_t ch = 0;
    if (__HAL_UART_GET_FLAG( &g_uart1_handle, UART_FLAG_RXNE ) != RESET) 
    {
        ch=(uint16_t)READ_REG(g_uart1_handle.Instance->DR);
        WRITE_REG( g_uart1_handle.Instance->DR,ch);
    }
    
}



