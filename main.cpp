/*
 * main.cpp
 *
 *  Created on: Jan 21, 2012
 *      Author: artur
 */

#include <stm32f10x.h>
#include <boardDefs.hpp>

#include <CGpioManager.hpp>

#include <CPeriphalManager.hpp>
#include <PeripheralTypes.hpp>
#include <IPeripheral.hpp>
#include <CLed.hpp>
#include <CUsart.hpp>
#include <CButton.hpp>

#include "ExternalModules/KamodRGB.hpp"
#include "ExternalModules/KamodMEMS2.hpp"
#include "Interrupts/IsrDispatcher.hpp"
#include "stm32f10x_exti.h"

#include <cstdio> 

void ordinaryDelay(int val = 10000);


class LedToogler : public InterruptHandler
{
public:
    LedToogler( CLed* led): led(led){}
    
    void handleInterrupt()
    {
        led->toogle();
    }
private:
    CLed* led;
};

int main()
{

   SystemInit();
    //ordinaryDelay();

    /*PERIPHERAL MANAGER TEST*/
    CGpioManager GM;    
    CPeriphalManager PM(&GM);

    TPeripheralConfigButton buttonConfig;
    buttonConfig.apb2 = RCC_APB2Periph_GPIOC;
    buttonConfig.gpioPin = GPIO_Pin_13;
    buttonConfig.gpioPort = GPIOC;
    
    CButton* tamper = PM.getPeripheral<CButton>(buttonConfig);
    tamper->init();
   
    TPeripheralConfigLed ledConfig;
    ledConfig.apb2 = RCC_APB2Periph_GPIOC;
    ledConfig.gpioPin = GPIO_Pin_6;
    ledConfig.gpioPort = GPIOC;
    
    CLed* greenLed = PM.getPeripheral<CLed>(ledConfig);
    greenLed->init();
    
    ledConfig.gpioPin = GPIO_Pin_7;
    
    CLed* yellowLed = PM.getPeripheral<CLed>(ledConfig);
    yellowLed->init();
    
    TPeripheralConfigI2C i2cConfig;
    
    i2cConfig.i2c        = I2C1;
    i2cConfig.gpioPort   = GPIOB;
    i2cConfig.gpioPinScl = GPIO_Pin_8;
    i2cConfig.gpioPinSda = GPIO_Pin_9;
    i2cConfig.apb1       = RCC_APB1Periph_I2C1;
    i2cConfig.apb2       = RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO ;
    i2cConfig.remap      = GPIO_Remap_I2C1;
    
    CI2C* i2c = PM.getPeripheral<CI2C>(i2cConfig);
    i2c->init();
    ordinaryDelay();

    TPeripheralConfigUsart usartConfig;

    usartConfig.usart = USART2;
    usartConfig.apb1  = RCC_APB1Periph_USART2;
    usartConfig.apb2  = RCC_APB2Periph_GPIOD | RCC_APB2Periph_AFIO ;
    usartConfig.remap = GPIO_Remap_USART2;
    usartConfig.gpioPinTx = GPIO_Pin_5;
    usartConfig.gpioPinRx = GPIO_Pin_6;
    usartConfig.gpioPort  = GPIOD;
    
    CUsart* Usart = PM.getPeripheral<CUsart>(usartConfig);
    Usart->init();
    Usart->sendString("\r\nSTART\n\r");


    
//    KamodRGB leds(0,i2c);
//    Usart->sendString("KamodRGB Enabled\n\r");
//    KamodMEMS2 mems(58,i2c);
//    Usart->sendString("KamodMEMS2 Enabled\n\r");

    IsrDispatcher isrDisp;
    LedToogler yellowLedToogler(yellowLed);
    LedToogler greenLedToogler(greenLed);
    
    
    TInterruptConfigExt tamperInterruptConfig;
    tamperInterruptConfig.preemptionPriority = 0;
    tamperInterruptConfig.subpriority        = 0;
    tamperInterruptConfig.channel            = EXTI15_10_IRQn;  
    tamperInterruptConfig.portSource = GPIO_PortSourceGPIOC;
    tamperInterruptConfig.pinSource  = GPIO_PinSource13;
    tamperInterruptConfig.line       = EXTI_Line13;
    tamperInterruptConfig.trigger    = EXTI_Trigger_Rising;
    
    isrDisp.registerInterrupt(EXTI15_10_IRQn,yellowLedToogler);
    isrDisp.enableInterruptExt(tamperInterruptConfig);    
    
    isrDisp.registerInterrupt(SysTick_IRQn,greenLedToogler);
    isrDisp.enableInterruptSysTick(500);
       
    
    while(1)
    {
        CLed* yellowLed2 = PM.getPeripheral<CLed>(ledConfig);
        yellowLed2->toogle();
        ordinaryDelay(999999);
    }   
    
}


void ordinaryDelay(int val)
{
    for(int i=0;i<val;i++);
}





