/*
 * CUsartStateUsable.cpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#include <boardDefs.hpp>

#include <CRccManager.hpp>
#include <CUsartStateUsable.hpp>
#include <CUsartStateUnusable.hpp>

void CUsartStateUsable::remap( uint32_t	remapValue )
{
	m_gpioManager->remap( remapValue );
}


void CUsartStateUsable::apbEnable( uint32_t apb1Value,
								   uint32_t apb2Value )
{
	m_rccManager->apb1Enable( apb1Value );
	m_rccManager->apb2Enable( apb2Value );
}


void CUsartStateUsable::gpioInit( uint8_t				port,
								  uint8_t				pin,
								  GPIO_InitTypeDef &	gpioConfig )
{
	gpioConfig.GPIO_Pin		= pin;
	m_gpioManager->initGpio( port, &gpioConfig );
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
		currentState = new CUsartStateRunning( m_gpioManager,
											   m_rccManager );
		delete this;
	}
}


void CUsartStateUsable::deinit( USART_TypeDef *	id,
								uint32_t		apb1,
								uint32_t		apb2,
								CUsartState *	usartState )
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
	m_rccManager->apb1Disable( apb1 );
	m_rccManager->apb2Disable( apb2 );

	usartState = new CUsartStateUnusable( m_gpioManager,
										  m_rccManager );

	delete this;
}

