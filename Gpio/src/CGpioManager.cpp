/*
 * CGpioManager.cpp
 *
 *  Created on: Feb 7, 2012
 *      Author: artur
 */

#include <boardDefs.hpp>

#include <CGpioManager.hpp>
#include <TypePeriph.hpp>

CGpioManager::CGpioManager()
{
    GPIO_TypeDef * gpioArr[] = { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG };

    for( uint8_t port=0; port<NUMBER_OF_PORTS; port++ )
    {
    m_gpioPortAddress[ port ] = gpioArr[ port ];
    for( uint8_t pin=0; pin<NUMBER_OF_PINS_PER_PORT; pin++ )
    {
        m_portPinUsed[ port][ pin ] = false;
    }
    }
}

bool CGpioManager::checkPortPinAvailability( uint8_t port, uint8_t pin )
{
    return m_portPinUsed[ port ][ pin ];
}

void CGpioManager::setPortPinUnused( uint8_t port, uint8_t pin )
{
    m_portPinUsed[ port ][ pin ] = false;
}

void CGpioManager::setPortPinUsed( uint8_t port, uint8_t pin )
{
    m_portPinUsed[ port ][ pin ] = true;
}

void CGpioManager::remap( uint32_t remapValue )
{
    GPIO_PinRemapConfig( remapValue, ENABLE );
}

void CGpioManager::initGpio( uint8_t            port,
                             GPIO_InitTypeDef * gpioConfig )
{
    GPIO_Init( m_gpioPortAddress[ port ], gpioConfig );
}

void CGpioManager::releaseGpio( uint8_t port,
                                uint8_t pin )
{
    setPortPinUnused( port, pin );
}

uint8_t CGpioManager::getPortIndex(GPIO_TypeDef * port)
{
/*    switch(port)
    {
        case GPIOA : 
            return 0;
        case GPIOB : 
            return 1;
        case GPIOC : 
            return 2;
        case GPIOD : 
            return 3;
        case GPIOE : 
            return 4;
        case GPIOF : 
            return 5;
        case GPIOG : 
            return 6;
    }*/
    if(port==GPIOC)
    {
        return 4;
    }
    return 0;
}
    
uint8_t CGpioManager::getPinIndex(uint16_t pin)
{
    switch(pin)
    {
        case GPIO_Pin_0 : 
            return 0;
        case GPIO_Pin_1 : 
            return 1;
        case GPIO_Pin_2 : 
            return 2;
        case GPIO_Pin_3 : 
            return 3;
        case GPIO_Pin_4 : 
            return 4;
        case GPIO_Pin_5 : 
            return 5;
        case GPIO_Pin_6 : 
            return 6;
        case GPIO_Pin_7 : 
            return 7;
        case GPIO_Pin_8 : 
            return 8;
        case GPIO_Pin_9 : 
            return 9;
            // ... TODO   
        default :
            return 0;
                  
                    
    }
    
}

CGpioManager & CGpioManager::operator=( CGpioManager const & gpioManager )
{
    return const_cast<CGpioManager &> ( gpioManager );
}

CGpioManager::CGpioManager( CGpioManager const & gpioManager )
{
    *this = const_cast<CGpioManager &> ( gpioManager );
}

