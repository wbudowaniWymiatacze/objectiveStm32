/* 
 * File:   sd.cpp
 * Author: mear
 *
 * Created on 15 kwiecień 2012, 22:22
 */

#include <../inc/sd.h>

static void card_insert_init(void)
{
    RCC->APB2ENR |= CARD_INSERT_APB2ENR;
    io_config(CARD_INSERT_PORT,CARD_INSERT_PIN,GPIO_MODE_INPUT,GPIO_CNF_IN_FLOAT);
}