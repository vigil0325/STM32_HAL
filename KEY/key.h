
#ifndef _KEY_H_
#define _KEY_H_
#define LED_OPEN 1
#define LED_CLOSE 0

#include "stm32f1xx.h"


void key_init(void);
uint8_t key_scan(void);




#endif
