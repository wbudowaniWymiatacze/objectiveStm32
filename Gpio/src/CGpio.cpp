/* 
 * File:   CGpio.cpp
 * Author: reymondo
 * 
 * Created on 17 maj 2012, 18:31
 */

#include <CGpio.hpp>

CGpio::CGpio(GPIO_TypeDef * port, uint16_t pin, GPIOSpeed_TypeDef speed, GPIOMode_TypeDef mode) :
        m_GpioPort(port),
        m_GpioPin(pin),
        m_GpioSpeed(speed),
        m_GpioMode(mode)
{
    
}

CGpio::~CGpio() 
{
    
}

void CGpio::set(bool state)
{
    state=state;
}

void CGpio::toogle()
{
    
}

bool CGpio::get()
{
    return false;
}

void CGpio::init()
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    GPIO_InitStructure.GPIO_Speed = m_GpioSpeed;
    GPIO_InitStructure.GPIO_Mode = m_GpioMode;
    GPIO_InitStructure.GPIO_Pin = m_GpioPin;
    GPIO_Init(m_GpioPort, &GPIO_InitStructure);
}