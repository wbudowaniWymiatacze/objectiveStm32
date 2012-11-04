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
    ledConfig.apb2 = RCC_APB2Periph_GPIOC;
    ledConfig.gpioPin = GPIO_Pin_6;
    ledConfig.gpioPort = GPIOC;
    
    CLed * Led = PM.getPeripheral<CLed>(ledConfig);
    
    ledConfig.gpioPin = GPIO_Pin_7;
    
    CLed * Led2 = PM.getPeripheral<CLed>(ledConfig);
    
    ledConfig.gpioPin = GPIO_Pin_6;
    
    CLed * Led3 = PM.getPeripheral<CLed>(ledConfig);
    
    Led->init();
    Led2->init();
    Led3->init();
    
    Led->on();
    
    int i=0;
    while(1)
    {
        if(i>900000)
        {
            i=0;
            Led->toogle();
            Led2->toogle();
            Led3->toogle();
        }
        i++;
    }   
}


