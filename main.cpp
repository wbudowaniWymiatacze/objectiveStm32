/*
 * main.cpp
 *
 *  Created on: Jan 21, 2012
 *      Author: artur
 */
#include <boardDefs.hpp>

#include <CGpioManager.hpp>
#include <CRccManager.hpp>
#include <TypePeriph.hpp>`
#include <CGpioOutput.hpp>

int main()
{
    //SystemInit();
   
    CGpioManager GM;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    
    CGpio* Gpio = GM.getGpio<CGpioOutput>(GPIOB,GPIO_Pin_0, GPIO_Speed_10MHz);
    CGpio* Gpio3 = GM.getGpio<CGpioOutput>(GPIOC,GPIO_Pin_4, GPIO_Speed_10MHz);
    
    Gpio->init();
    Gpio3->init();
    
    Gpio->set(true);
    
    int i=0;
    while(1)
    {
        if(i>100000)
        {
            i=0;
            Gpio->toogle();
            Gpio3->toogle();
        }
        i++;
    }   
}


