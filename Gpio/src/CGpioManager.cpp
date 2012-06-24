/*
 * CGpioManager.cpp
 *
 *  Created on: Feb 7, 2012
 *      Author: artur
 */

#include <boardDefs.hpp>

#include <CGpioManager.hpp>
#include <UsartParams.hpp>

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

bool CGpioManager::checkPortPinAvailability( uint8_t port, uint16_t pin )
{
    return m_portPinUsed[ port ][ __builtin_clz( pin ) ];
}

void CGpioManager::setPortPinUnused( uint8_t port, uint16_t pin )
{
    m_portPinUsed[ port ][ __builtin_clz( pin ) ] = false;
}

void CGpioManager::setPortPinUsed( uint8_t port, uint16_t pin )
{
    m_portPinUsed[ port ][ __builtin_clz( pin ) ] = true;
}

bool CGpioManager::getGpio( uint8_t port,
                               uint16_t pin )
{

    // check if the port and pin are used by another peripheral
    bool portPinUsed = checkPortPinAvailability( port, pin );

    if ( portPinUsed == true )
    {
    return false;
    }

    // set the port and the pin as used
    setPortPinUsed( port, pin );

    return true;
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
                                    uint16_t pin )
{
    setPortPinUnused( port, pin );
}

CGpioManager & CGpioManager::operator=( CGpioManager const & gpioManager )
{
    return const_cast<CGpioManager &> ( gpioManager );
}

CGpioManager::CGpioManager( CGpioManager const & gpioManager )
{
    *this = const_cast<CGpioManager &> ( gpioManager );
}

