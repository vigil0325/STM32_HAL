
#include "./led.h"

//LED�Ƴ�ʼ������
void led_init(void){
    
    //��GPIOB��ʱ��ʹ��
    __HAL_RCC_GPIOB_CLK_ENABLE();
    
    
    //��GPIO�����������
    GPIO_InitTypeDef GPIO_Init;
    GPIO_Init.Mode   = GPIO_MODE_OUTPUT_PP;
    GPIO_Init.Pin    = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_5;
    GPIO_Init.Pull   = GPIO_NOPULL;
    GPIO_Init.Speed  = GPIO_SPEED_FREQ_LOW;
    
    HAL_GPIO_Init(GPIOB,&GPIO_Init);
    
}

//��LED�����ĺ��� ��ɫ����ɫ1 ��ɫ2 ��ɫ3������������4���ر�5
void led_operation(int color, int operate, int delay){

    if(color == 1){
        if(operate == 4){
            //��ƿ���
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);
            HAL_Delay(delay);
        }
        if(operate == 5){
            //��ƹر�
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
            HAL_Delay(delay);
        }
    }
    
    if(color == 2){
        if(operate == 4){
            //�̵ƿ���
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
            HAL_Delay(delay);
        }
        if(operate == 5){
            //�̵ƹر�
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
            HAL_Delay(delay);
        }
    }
    
    if(color == 3){
        if(operate == 4){
            //���ƿ���
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
            HAL_Delay(delay);
        }
        if(operate == 5){
            //���ƹر�
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
            HAL_Delay(delay);
        }
    }
    
}

