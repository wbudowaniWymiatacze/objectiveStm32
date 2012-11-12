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

#include <cstdio> 

void ordinaryDelay(int val = 10000)
{
    for(int i=0;i<val;i++);
}

CLed* GlobalLed;

class GlobalLedToogler : public InterruptHandler
{
    void handle()
    {
        GlobalLed->toogle();
    }
};

int main()
{

    SystemInit();
    ordinaryDelay();

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
    
    CLed* led = PM.getPeripheral<CLed>(ledConfig);
    led->init();
    
    ledConfig.gpioPin = GPIO_Pin_7;
    
    GlobalLed = PM.getPeripheral<CLed>(ledConfig);
    GlobalLed->init();
    
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
//    ordinaryDelay();
    
    led->on();
    
    GlobalLed->on();
    
    GlobalLedToogler glt;
    IsrDispatcher isrDisp;
    
    isrDisp.registerInterrupt(SysTick_IRQn,glt);
    
    SysTick_Config(10000000);
       
    
    while(1)
    {
        led->toogle();
        ordinaryDelay(900000);        
    }   
    
}





