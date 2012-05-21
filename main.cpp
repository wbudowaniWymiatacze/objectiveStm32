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

LED GreenLED;
LED YellowLED;
USART Console;

int main()
{
    //SystemInit();

//LEDS
//    GreenLED.init(green);
    YellowLED.init(yellow);

//    GreenLED.On();
    YellowLED.On();
    
    
    CGpioManager GM;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    
    //CGpioOutput Gpio(GPIOC, GPIO_Pin_6, GPIO_Speed_10MHz);
    CGpioOutput Gpio = GM.getGpio<CGpioOutput>(GPIOC,GPIO_Pin_6, GPIO_Speed_10MHz);
    Gpio.init();
    Gpio.set(true);
    
    int i=0;
    while(1)
    {
        if(i>100000)
        {
            i=0;
            Gpio.toogle();
        }
        i++;
    }   
}


