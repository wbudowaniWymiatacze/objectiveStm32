/* 
 * File:   CGpioI2C.cpp
 * Author: reymondo
 * 
 * Created on 4 listopad 2012, 19:11
 */

#include <CGpioI2C.hpp>


CGpioI2C::CGpioI2C(GPIO_TypeDef * port, uint16_t pin, GPIOSpeed_TypeDef speed):
CGpio(port, pin, speed, GPIO_Mode_AF_OD)
{
  
}

CGpioI2C::CGpioI2C()
{
    
}

CGpioI2C::~CGpioI2C() 
{
    
}

void CGpioI2C::init() 
{
    realInit();
}