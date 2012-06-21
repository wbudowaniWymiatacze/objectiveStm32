/* 
 * File:   CI2C.cpp
 * Author: reymondo
 * 
 * Created on 18 czerwiec 2012, 20:28
 */

#include <CI2C.hpp>

CI2C::CI2C(CGpioManager * GM,SPeripheralConfig * config ): 
IPeripheral(GM)
{
    TPeripheralConfigI2C * A = (TPeripheralConfigLed*)config;
    I2Cx = A->i2c;
    GPIO_Pin_SCL = GM->getGpio<CGpioOutput>(A->gpioPort,A->gpioPin); ;
    GPIO_Pin_SDA = GM->getGpio<CGpioOutput>(A->gpioPort,A->gpioPin);;  
    
}


CI2C::~CI2C() {
}

