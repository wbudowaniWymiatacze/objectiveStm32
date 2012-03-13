/*
 * CUsartStateUnusable.hpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#ifndef CUSARTSTATEUNUSABLE_HPP_
#define CUSARTSTATEUNUSABLE_HPP_

#include <boardDefs.hpp>

#include <CGpioManager.hpp>
#include <CRccManager.hpp>
#include <CUsartState.hpp>

/*
 * except nextState none of the functions does anything
 */
class CUsartStateUnusable : public CUsartState {
public:

	CUsartStateUnusable( CGpioManager * gpioManager,
						 CRccManager *	rccManager ) :
	m_gpioManager( gpioManager ), m_rccManager( rccManager ) {}

	void remap( uint32_t	remapValue )
	{

	}

	void apbEnable( uint32_t apb1Value,
					uint32_t apb2Value )
	{

	}

	/*
	 * gpio initialisation is not allowed in this state,
	 * so the function does nothing
	 */
	void gpioInit( uint8_t				port,
				   uint8_t				pin,
				   GPIO_InitTypeDef &	gpioConfig )
	{

	}

	/*
	 * initialisation of USART is not allowed in this state
	 * so the function does nothing
	 */
	void init( USART_TypeDef *		usartId,
			   USART_InitTypeDef &	periphConfig )
	{

	}

	/*
	 * read does nothing in this state
	 */
	void read( USART_TypeDef *	usartId,
			   uint16_t *		data,
			   uint8_t			nData )
	{

	}

	/*
	 * read does nothing in this state
	 */
	void write( USART_TypeDef *	usartId,
			    uint16_t *		data,
			    uint8_t			nData )
	{

	}

	/*
	 * change state to CUsartStateUsable
	 */
	void nextState( CUsartState *	currentState,
					bool			switchToNextState );

	void deinit( USART_TypeDef *	id,
				 uint32_t			apb1,
				 uint32_t			apb2,
				 CUsartState *		usartState )
	{

	}

	~CUsartStateUnusable() {}

private:
	CGpioManager *	m_gpioManager;
	CRccManager *	m_rccManager;
};


#endif /* CUSARTSTATEUNUSABLE_HPP_ */
