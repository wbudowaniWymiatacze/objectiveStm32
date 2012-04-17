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
    //enable cart insert pin PB9 wg. Kamami datasheet
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;                
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
    // speed przy inpucie powinnien być ustawiony jako mode = 00 RM8 9.1 tab.20
    GPIO_Init(GPIOB, &GPIO_InitStructure);
   
}

void led_34_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP ; //?
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_2MHz; //?
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

bool card_inside (void)
{
    uint16_t card_detect;
    card_detect = GPIO_ReadInputData(GPIOC);
    return (card_detect >> 9)&1;
}