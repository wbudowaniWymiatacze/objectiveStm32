/*
 * main.cpp
 *
 *  Created on: Jan 21, 2012
 *      Author: artur
 */
#include <boardDefs.hpp>

#include <CGpioManager.hpp>
#include <CRccManager.hpp>
#include <TypePeriph.hpp>

#include <stm32-P107.hpp>

#include <CGpioOutput.hpp>




int main()
{
    //SystemInit();
    
    CGpioManager GM;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    
    CGpio* Gpio = GM.getGpio<CGpioOutput>(GPIOC,GPIO_Pin_6, GPIO_Speed_10MHz);
    
    CGpio* Gpio2 = GM.getGpio<CGpioOutput>(GPIOC,GPIO_Pin_7);
    
    Gpio2->init();
    Gpio->init();
    Gpio->set(true);
    
    int i=0;
    while(1)
    {
        if(i>100000)
        {
            i=0;
            Gpio->toogle();
            Gpio2->toogle();
        }
        i++;
    }   
}


