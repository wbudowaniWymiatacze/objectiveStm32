/*
 * CUsartStateUsable.cpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#include <boardDefs.hpp>

#include <CRcc.hpp>
#include <CUsartStateUsable.hpp>

using namespace Rcc;

void CUsartStateUsable::remap( uint32_t	remapValue )
{
	CGpioManager::remap( remapValue );
}


void CUsartStateUsable::apbEnable( uint32_t apb1Value,
								   uint32_t apb2Value )
{
	CRcc::apb1Enable( apb1Value );
	CRcc::apb2Enable( apb2Value );
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

	// initialise USART clock
	USART_ClockInitTypeDef	clockInitStruct;
	USART_ClockStructInit( &clockInitStruct );
	USART_ClockInit( usartId, &clockInitStruct );

	//Enable USART
	USART_Cmd( usartId, ENABLE );
}


void CUsartStateUsable::nextState( CUsartState *	currentState,
		 	 	 	 	 	 	   bool				switchToNextState )
{
	if ( switchToNextState == true )
	{
		currentState = new CUsartStateRunning;
		delete this;
	}
}


void CUsartStateUsable::deinit( USART_TypeDef *	id,
								uint32_t		apb1,
								uint32_t		apb2 )
{
	// Disable USART
	USART_Cmd( id, DISABLE );

	/*
	 * Undo USART_ClockInit
	 * Clear CLKEN, CPOL, CPHA and LBCL bits
	 */
	// TODO: fix
//	id->CR2 &= CR2_CLOCK_CLEAR_Mask;

	// disable APB
	CRcc::apb1Disable( apb1 );
	CRcc::apb2Disable( apb2 );
}

