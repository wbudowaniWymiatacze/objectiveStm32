/*
 * main.cpp
 *
 *  Created on: Jan 21, 2012
 *      Author: artur
 */
#include <boardDefs.hpp>

#include <CGpioManager.hpp>

#include <CPeriphalManager.hpp>
#include <PeripheralTypes.hpp>
#include <IPeripheral.hpp>
#include <CLed.hpp>
#include <CUsart.hpp>

#include "ExternalModules/KamodRGB.hpp"
#include "ExternalModules/KamodMEMS2.hpp"

#include <cstdio> 

void ordinaryDelay(int val = 10000)
{
    for(int i=0;i<val;i++);
}

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
    
    CLed* led = PM.getPeripheral<CLed>(ledConfig);
    
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

    Usart->sendString("\r\n[x, y, z]\n");
    
    KamodRGB leds(0,i2c);
    KamodMEMS2 mems(58,i2c);
        
    leds.light(KAmber,255);
    
    led->init();
    
    led->on();
    char out[15];
    
    while(1)
    {
        led->toogle();
        leds.light(KAmber,0);
        
        ordinaryDelay(900000);
        
        leds.light(KAmber,255);
        leds.light(KBlue, mems.getx());
        leds.light(KGreen,mems.gety());
        leds.light(KRed,  mems.getz());
        
        Usart->sendString("\r               \r");
        sprintf(out,"[%d, %d, %d]",mems.getx(), mems.gety(), mems.getz());
        Usart->sendString(out);
    }   
    
}


