
#include "key.h"




void key_init(void){
    //给GPIO的时钟使能
    //PA0 PC13
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    
    //配置按键GPIO的结构体
    GPIO_InitTypeDef key1_struct;
    GPIO_InitTypeDef key2_struct;
    
    key1_struct.Mode  = GPIO_MODE_INPUT ;
    key1_struct.Pin   = GPIO_PIN_0;
    key1_struct.Pull  = GPIO_NOPULL;
    key1_struct.Speed = GPIO_SPEED_FREQ_LOW;
    
    key2_struct.Mode  = GPIO_MODE_INPUT ;
    key2_struct.Pin   = GPIO_PIN_13;
    key2_struct.Pull  = GPIO_NOPULL;
    key2_struct.Speed = GPIO_SPEED_FREQ_LOW;
    
    //初始化GPIO
    HAL_GPIO_Init(GPIOA,&key1_struct);
    HAL_GPIO_Init(GPIOC,&key2_struct);
    
}

uint8_t key_scan(void){
    
    //获得按键的电平 HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);  HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13);
    if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == GPIO_PIN_RESET)
    {
        //延时消抖
        HAL_Delay(10);
        if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == GPIO_PIN_RESET)
        {
            //直到按键松开才进入下面的返回
            while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == GPIO_PIN_RESET);
            return LED_OPEN;
        }
    }
    if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13) == GPIO_PIN_RESET)
    {
        //延时消抖
        HAL_Delay(10);
        if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13) == GPIO_PIN_RESET)
        {
            while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13) == GPIO_PIN_RESET);
            return LED_CLOSE;
        }
    } 
    else
    {
        return 2;
    }
    
}


