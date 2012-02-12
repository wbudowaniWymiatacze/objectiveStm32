/*
 * CUsartStateUsable.cpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#include <boardDefs.hpp>

#include <CUsartStateUsable.hpp>

void CUsartStateUsable::remap( uint32_t	remapValue )
{
	CGpioManager::remap( remapValue );
}


void CUsartStateUsable::gpioInit( uint32_t			port,
											uint32_t			pin,
											GPIOSpeed_TypeDef	speed,
		  	  	  	  	  	  	  	  	  	GPIOMode_TypeDef	mode )
{
	GPIO_InitTypeDef	gpioConfig;

	gpioConfig.GPIO_Pin		= pin;
	gpioConfig.GPIO_Speed	= speed;
	gpioConfig.GPIO_Mode	= mode;
	CGpioManager::initGpio( port, &gpioConfig );
}


void CUsartStateUsable::init( USART_TypeDef *		usartId,
										USART_InitTypeDef &	periphConfig )
{
	// Write USART parameters
	USART_Init( usartId, &periphConfig );

	//Enable USART
	USART_Cmd( usartId, ENABLE );
}


void CUsartStateUsable::nextState( CUsartState *	currentState,
		 	 	 	 	 	 	 	 	 	 	 	  bool			switchToNextState )
{
	if ( switchToNextState == true )
	{
		currentState = new CUsartStateRunning;
		delete this;
	}
}

