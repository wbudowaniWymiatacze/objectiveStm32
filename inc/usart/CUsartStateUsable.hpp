/*
 * CUsartStateUsable.hpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#ifndef CUSARTSTATEUSABLE_HPP_
#define CUSARTSTATEUSABLE_HPP_

#include <boardDefs.hpp>

#include <CGpioManager.hpp>
#include <CUsartState.hpp>
#include <CUsartStateRunning.hpp>

class CUsartStateUsable : public CUsartState {
public:

	void remap( uint32_t	remapValue );

	/*
	 * initialise needed GPIO
	 */

	// TODO: zmienić na wywołanie z nr portu i pinu
	void gpioInit( uint32_t				port,
				   uint32_t				pin,
				   GPIOSpeed_TypeDef	speed,
				   GPIOMode_TypeDef		mode );

	/*
	 * initialise USART
	 */
	void init( USART_TypeDef *		usartId,
			   USART_InitTypeDef &	periphConfig );

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

	void nextState( CUsartState *	currentState,
					bool			switchToNextState );

	~CUsartStateUsable() {}
};

#endif /* CUSARTSTATEUSABLE_HPP_ */
