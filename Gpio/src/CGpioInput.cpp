/* 
 * File:   CGpioInput.cpp
 * Author: reymondo
 * 
 * Created on 17 maj 2012, 19:10
 */

#include <CGpioInput.hpp>
#include <CGpio.hpp>

CGpioInput::CGpioInput(GPIO_TypeDef * port, uint16_t pin, GPIOSpeed_TypeDef speed):
CGpio(port, pin, speed,GPIO_Mode_IN_FLOATING) 
{
    
}

CGpioInput::CGpioInput()
{
    
}

CGpioInput::~CGpioInput() 
{
    
}

bool CGpioInput::get() 
{
    return GPIO_ReadInputDataBit(m_GpioPort,m_GpioPin) != RESET;
}

void CGpioInput::init() 
{
    realInit();
}
