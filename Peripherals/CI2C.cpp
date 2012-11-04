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
    TPeripheralConfigI2C * A = (TPeripheralConfigI2C*)config;
    I2Cx = A->i2c;
    GPIO_Pin_SCL = GM->getGpio<CGpioOutput>(A->gpioPort,A->gpioPinScl);
    GPIO_Pin_SDA = GM->getGpio<CGpioOutput>(A->gpioPort,A->gpioPinSda);
    
}


CI2C::~CI2C() {
}

