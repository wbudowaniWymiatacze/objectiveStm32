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

LED GreenLED;
LED YellowLED;
USART Console;

int main()
{
    //LEDS
    GreenLED.init(green);
    YellowLED.init(yellow);

    GreenLED.On();
    YellowLED.Off();
    
    int i=0;
    while(1)
    {
        i++;
    }
        

    return 0;
}


