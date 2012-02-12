/*
 * CUsartStateUnusable.hpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#ifndef CUSARTSTATEUNUSABLE_HPP_
#define CUSARTSTATEUNUSABLE_HPP_

#include <boardDefs.hpp>

#include <CUsartState.hpp>
#include <CUsartStateUsable.hpp>

/*
 * except nextState none of the functions does anything
 */
class CUsartStateUnusable : public CUsartState {
public:

	void remap( uint32_t	remapValue )
	{

	}

	/*
	 * gpio initialisation is not allowed in this state,
	 * so the function does nothing
	 */
	void gpioInit( uint32_t				port,
				   uint32_t				pin,
				   GPIOSpeed_TypeDef	speed,
				   GPIOMode_TypeDef		mode )
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
	void read()
	{

	}

	/*
	 * read does nothing in this state
	 */
	void write()
	{

	}

	/*
	 * change state to CUsartStateUsable
	 */
	void nextState( CUsartState *	currentState,
					bool			switchToNextState );

	~CUsartStateUnusable() {}
};


#endif /* CUSARTSTATEUNUSABLE_HPP_ */
