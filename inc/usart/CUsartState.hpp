/*
 * CUsartState.hpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#ifndef CUSARTSTATE_HPP_
#define CUSARTSTATE_HPP_

#include <boardDefs.hpp>

class CUsartState {
public:
	CUsartState() {}
	virtual void remap( uint32_t	remapValue ) = 0;
	virtual void gpioInit( uint32_t				port,
						   uint32_t				pin,
						   GPIOSpeed_TypeDef	speed,
						   GPIOMode_TypeDef		mode ) = 0;
	virtual void init( USART_TypeDef *		usartId,
			   	   	   USART_InitTypeDef &	periphConfig ) = 0;
	virtual void read() = 0;
	virtual void write() = 0;
	virtual void nextState( CUsartState *	currentState,
 	 	 	 	 	 	 	bool			switchToNextState ) = 0;
	virtual ~CUsartState() {}
};

#endif /* CUSARTSTATE_HPP_ */
