/*
 * CUsartStateRunning.hpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#ifndef CUSARTSTATERUNNING_HPP_
#define CUSARTSTATERUNNING_HPP_

#include <boardDefs.hpp>

#include "CUsartState.hpp"

class CUsartStateRunning: public CUsartState {
public:

	/*
	 * remapping is not allowed in this state,
	 * so the function does nothing
	 */
	void remap( uint32_t	remapValue )
	{

	}

	/*
	 * enabling APB is not allowed in this state,
	 * so the function does nothing
	 */
	void apbEnable( uint32_t apb1Value,
					uint32_t apb2Value )
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
	 * TODO: implement read
	 */
	void read();

	/*
	 * TODO: implement write
	 */
	void write();

	/*
	 * no next state exists so the function does nothing
	 */
	void nextState( CUsartState *	currentState,
					bool			switchToNextState )
	{

	}

	void deinit( USART_TypeDef *	id,
			 	 uint32_t			apb1,
			 	 uint32_t			apb2 );

	~CUsartStateRunning() {}
};

#endif /* CUSARTSTATERUNNING_HPP_ */
