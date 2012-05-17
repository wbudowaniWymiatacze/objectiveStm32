/* 
 * File:   CGpioOutput.cpp
 * Author: reymondo
 * 
 * Created on 17 maj 2012, 19:11
 */

#include <CGpioOutput.hpp>


CGpioOutput::CGpioOutput(GPIO_TypeDef * port, uint16_t pin, GPIOSpeed_TypeDef speed):
CGpio(port, pin, speed, GPIO_Mode_Out_PP)
{
    
}

CGpioOutput::~CGpioOutput() 
{
    
}

void CGpioOutput::set(bool state)
{
    if(state)
    {
        GPIO_SetBits(m_GpioPort, m_GpioPin);
    }
    else
    {
        GPIO_ResetBits(m_GpioPort, m_GpioPin);
    }
}

void CGpioOutput::toogle()
{
    this->set(!this->get());
}

bool CGpioOutput::get()
{
    return GPIO_ReadInputDataBit(m_GpioPort,m_GpioPin) != RESET;
}