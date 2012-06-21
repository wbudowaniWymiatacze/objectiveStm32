/*
 * main.cpp
 *
 *  Created on: Jan 21, 2012
 *      Author: artur
 */
#include <boardDefs.hpp>

#include <CGpioManager.hpp>
#include <CRccManager.hpp>
#include <CGpio.hpp>

#include <CPeriphalManager.hpp>
#include <Peripherals/PeripheralTypes.hpp>
#include <IPeripheral.hpp>
#include <Peripherals/CLed.hpp>

#include "Peripherals/IPeripheral.hpp"



int main()
{

    SystemInit();
    
    /*PERIPHERAL MANAGER TEST*/
    CGpioManager GM;    
    CPeriphalManager PM(&GM);
   
    TPeripheralConfigLed ledConfig;
    ledConfig.apb1 = 0;
    ledConfig.apb2 = RCC_APB2Periph_GPIOC;
    ledConfig.gpioPin = GPIO_Pin_6;
    ledConfig.gpioPort = GPIOC;
    ledConfig.irqChannel = 0;
    ledConfig.remap = 0;
    
    CLed * Led = PM.getPeripheral<CLed>(&ledConfig);
    
    CLed * Led2 = PM.getPeripheral<CLed>(&ledConfig);
    
    Led->init();
    
    Led->on();
    
    int i=0;
    while(1)
    {
        if(i>100000)
        {
            i=0;
            Led->toogle();
            //Led2->toogle();
        }
        i++;
    }   
}


