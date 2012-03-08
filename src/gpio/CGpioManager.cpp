/*
 * CGpioManager.cpp
 *
 *  Created on: Feb 7, 2012
 *      Author: artur
 */

#include <boardDefs.hpp>

#include <CGpioManager.hpp>
#include <TypePeriph.hpp>

#include <gpioPortAddress.hpp>

CGpioManager::CGpioManager() {
	// TODO Auto-generated constructor stub

}

bool CGpioManager::checkPortPinAvailability( unsigned short port, unsigned short pin )
{
	return m_portPinUsed[ port ][ pin ];
}

void CGpioManager::setPortPinUnused( unsigned short port, unsigned short pin )
{
	m_portPinUsed[ port ][ pin ] = false;
}

void CGpioManager::setPortPinUsed( unsigned short port, unsigned short pin )
{
	m_portPinUsed[ port ][ pin ] = true;
}

bool CGpioManager::getGpio( uint32_t port,
		  	  	  	  	  	uint32_t pin )
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

void CGpioManager::initGpio( uint32_t			port,
					  	  	 GPIO_InitTypeDef *	gpioConfig )
{
	GPIO_Init( gpioPortAddress[ port ], gpioConfig );
}

void CGpioManager::releaseGpio( uint32_t port,
	 	 	 	 	 	 	 	uint32_t pin )
{
	setPortPinUnused( port, pin );
}

CGpioManager::~CGpioManager() {
	// TODO Auto-generated destructor stub
}

