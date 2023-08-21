
#include "usartln.h"
#include "stdio.h"

UART_HandleTypeDef g_uart1_handle;//UART句柄

//配置串口工作参数
void uart_init(uint32_t baudrate){
    
    //定义结构体
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

//串口底层初始化
//先初始化时钟，再初始化IO，使能USAR1T1中断，设置优先级
void HAL_UART_MspInit(UART_HandleTypeDef *huart){
    
    //如果是串口1，进行串口1的初始化
    if(huart->Instance == USART1){
        //使能USTRA1和相应IO的时钟
        __HAL_RCC_USART1_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();
        
        //配置GPIO结构体,输出不用设置上下拉，输入不用设置速度
        GPIO_InitTypeDef gpiotx_struct;
        gpiotx_struct.Pin   = GPIO_PIN_9;
        gpiotx_struct.Mode  = GPIO_MODE_AF_PP;//推挽式复用
        gpiotx_struct.Pull = GPIO_PULLUP;
        gpiotx_struct.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(GPIOA,&gpiotx_struct);
    
        GPIO_InitTypeDef gpiorx_struct;
        gpiorx_struct.Pin   = GPIO_PIN_10;
        gpiorx_struct.Mode  = GPIO_MODE_AF_INPUT;//输入
        gpiorx_struct.Pull  = GPIO_PULLUP;//上拉，因为空闲时信号是高电平
        HAL_GPIO_Init(GPIOA,&gpiorx_struct);
    
        //设置中断优先级
        HAL_NVIC_SetPriority(USART1_IRQn,0,1);
        HAL_NVIC_EnableIRQ(USART1_IRQn);//使能中断
    }
    
}



//重定向fputc到USART1串口，可使用printf
int fputc(int ch,FILE *f){
    
    HAL_UART_Transmit(&g_uart1_handle,(uint8_t *)&ch,1,1000);
    return(ch);
    
}



//重定向 c 库函数 scanf 到串口 USARTx，重写向后可使用 scanf、getchar 等函数
int fgetc(FILE *f)
{
    int ch;
    HAL_UART_Receive(&g_uart1_handle, (uint8_t *)&ch, 1, 1000);
    return(ch);
    
}

//串口1中断服务函数
void USART1_IRQHandler(void){
    
    uint8_t ch = 0;
    if (__HAL_UART_GET_FLAG( &g_uart1_handle, UART_FLAG_RXNE ) != RESET) 
    {
        ch=(uint16_t)READ_REG(g_uart1_handle.Instance->DR);
        WRITE_REG( g_uart1_handle.Instance->DR,ch);
    }
    
}



