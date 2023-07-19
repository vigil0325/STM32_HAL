
#include "key.h"

void key_init(void){
    //��GPIO��ʱ��ʹ��
    //PA0 PC13
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    
    //���ð���GPIO�Ľṹ��
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
    
    //��ʼ��GPIO
    HAL_GPIO_Init(GPIOA,&key1_struct);
    HAL_GPIO_Init(GPIOC,&key2_struct);
    
}

uint8_t key1_scan(void){
    
    //��ð����ĵ�ƽ HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);  HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13);
    if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0 == OPEN))
    {
        //��ʱ����
        HAL_Delay(10);
        if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == OPEN)
        {
            //ֱ�������ɿ��Ž�������ķ���
            while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == OPEN);
            return LED_OPEN;
        }
    }
    if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13 == OPEN))
    {
        //��ʱ����
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


