
#include "./led.h"

//LED灯初始化函数
void led_init(void){
    
    //给GPIOB的时钟使能
    __HAL_RCC_GPIOB_CLK_ENABLE();
    
    
    //对GPIO输出进行配置
    GPIO_InitTypeDef GPIO_Init;
    GPIO_Init.Mode   = GPIO_MODE_OUTPUT_PP;
    GPIO_Init.Pin    = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_5;
    GPIO_Init.Pull   = GPIO_NOPULL;
    GPIO_Init.Speed  = GPIO_SPEED_FREQ_LOW;
    
    HAL_GPIO_Init(GPIOB,&GPIO_Init);
    
}

//对LED操作的函数 颜色：红色1 绿色2 蓝色3；操作：开启4，关闭5
void led_operation(int color, int operate, int delay){

    if(color == 1){
        if(operate == 4){
            //红灯开启
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);
            HAL_Delay(delay);
        }
        if(operate == 5){
            //红灯关闭
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
            HAL_Delay(delay);
        }
    }
    
    if(color == 2){
        if(operate == 4){
            //绿灯开启
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
            HAL_Delay(delay);
        }
        if(operate == 5){
            //绿灯关闭
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
            HAL_Delay(delay);
        }
    }
    
    if(color == 3){
        if(operate == 4){
            //蓝灯开启
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
            HAL_Delay(delay);
        }
        if(operate == 5){
            //蓝灯关闭
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
            HAL_Delay(delay);
        }
    }
    
}

