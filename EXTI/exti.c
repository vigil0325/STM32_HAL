

//PA0 KEY1下拉 上升沿触发 

#include "exti.h"


void exti_init(void){
    
    //使能GPIOA的时钟
    __HAL_RCC_GPIOA_CLK_ENABLE();
    
    //建立GPIO结构体
    GPIO_InitTypeDef gpio_struct;
    
    gpio_struct.Mode  = GPIO_MODE_IT_RISING;//上升沿触发
    gpio_struct.Pin   = GPIO_PIN_0;
    gpio_struct.Pull  = GPIO_PULLDOWN;
    
    HAL_GPIO_Init(GPIOA,&gpio_struct);
    
    //设置优先级
    HAL_NVIC_SetPriority(EXTI0_IRQn,2,0);
    
    //使能中断
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

//中断服务函数
void EXTI0_IRQHandler(void){
    
    //中断处理公共函数
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
    
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
    
    //判断进入的是哪一条
    if(GPIO_Pin == GPIO_PIN_0){
        
        if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == 1){
            
            //消抖
            //HAL_Delay(10); 如果加入消抖则按下按键KEY1后蓝灯会保持按下的状态不变，并不会让绿灯电平翻转，问题无法解决。
            if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == 1){
            
                HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_0);
            
            }
        }
    }
}


