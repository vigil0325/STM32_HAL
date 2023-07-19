
#include "key.h"

void key_init(void){
    //给GPIO的时钟使能
    //PA0 PC13
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    
    //配置按键GPIO的结构体
    GPIO_InitTypeDef key1_struct;
    GPIO_InitTypeDef key2_struct;
    
    led_struct.Mode  = GPIO_MODE_INPUT ;
    led_struct.Pin   = GPIO_PIN_0;
    led_struct.Pull  = GPIO_SPEED_FREQ_LOW;
    led_struct.Speed = GPIO_PULLDOWN;
    
    led_struct.Mode  = GPIO_MODE_INPUT ;
    led_struct.Pin   = GPIO_PIN_13;
    led_struct.Pull  = GPIO_SPEED_FREQ_LOW;
    led_struct.Speed = GPIO_PULLDOWN;
    
    //初始化GPIO
    HAL_GPIO_Init(GPIOA,&key1_struct);
    HAL_GPIO_Init(GPIOC,&key2_struct);
    
}

uint8_t key1_scan(void){
    
    //获得按键的电平 HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);  HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13);
    if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0 == OPEN))
    {
        //延时消抖
        HAL_Delay(10);
        if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == OPEN)
        {
            //直到按键松开才进入下面的返回
            while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == OPEN);
            return LED_OPEN;
        }
    }
    if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13 == OPEN))
    {
        //延时消抖
        HAL_Delay(10);
        if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13) == OPEN)
        {
            while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13) == OPEN);
            return LED_CLOSE;
        }
    } 
    else
    {
        return LED_STAY;
    }
    
}


