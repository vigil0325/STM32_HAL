
#ifndef _LED_H_
#define _LED_H_

#define RED 1
#define GREEN 2
#define BLUE 3
#define OPEN 4
#define CLOSE 5

#include "stm32f1xx.h"

void led_init(void);

void led_operation(int color, int operate, int delay);

#endif
