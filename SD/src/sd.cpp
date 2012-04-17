/* 
 * File:   sd.cpp
 * Author: mear
 *
 * Created on 15 kwiecień 2012, 22:22
 */

#include <sd.h>

#include "stm32f10x.h"

void card_insert_init(void)
{
    RCC->APB2ENR |= CARD_INSERT_APB2ENR;                //enable cart insert PB9 
    
}
