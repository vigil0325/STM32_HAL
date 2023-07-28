

//PA0 KEY1���� �����ش��� 

#include "exti.h"


void exti_init(void){
    
    //ʹ��GPIOA��ʱ��
    __HAL_RCC_GPIOA_CLK_ENABLE();
    
    //����GPIO�ṹ��
    GPIO_InitTypeDef gpio_struct;
    
    gpio_struct.Mode  = GPIO_MODE_IT_RISING;//�����ش���
    gpio_struct.Pin   = GPIO_PIN_0;
    gpio_struct.Pull  = GPIO_PULLDOWN;
    
    HAL_GPIO_Init(GPIOA,&gpio_struct);
    
    //�������ȼ�
    HAL_NVIC_SetPriority(EXTI0_IRQn,2,0);
    
    //ʹ���ж�
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

//�жϷ�����
void EXTI0_IRQHandler(void){
    
    //�жϴ���������
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
    
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
    
    //�жϽ��������һ��
    if(GPIO_Pin == GPIO_PIN_0){
        
        if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == 1){
            
            //����
            //HAL_Delay(10); ��������������°���KEY1�����ƻᱣ�ְ��µ�״̬���䣬���������̵Ƶ�ƽ��ת�������޷������
            if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == 1){
            
                HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_0);
            
            }
        }
    }
}


