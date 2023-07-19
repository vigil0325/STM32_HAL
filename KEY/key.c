
#include "key.h"




void key_init(void){
    //��GPIO��ʱ��ʹ��
    //PA0 PC13
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    
    //���ð���GPIO�Ľṹ��
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
    
    //��ʼ��GPIO
    HAL_GPIO_Init(GPIOA,&key1_struct);
    HAL_GPIO_Init(GPIOC,&key2_struct);
    
}

uint8_t key_scan(void){
    
    //��ð����ĵ�ƽ HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);  HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13);
    if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == GPIO_PIN_RESET)
    {
        //��ʱ����
        HAL_Delay(10);
        if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == GPIO_PIN_RESET)
        {
            //ֱ�������ɿ��Ž�������ķ���
            while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == GPIO_PIN_RESET);
            return LED_OPEN;
        }
    }
    if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13) == GPIO_PIN_RESET)
    {
        //��ʱ����
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


