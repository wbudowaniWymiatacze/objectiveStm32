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
#include <CRcc.hpp>
#include <CUsartState.hpp>
#include <CUsartStateRunning.hpp>

class CUsartStateUsable : public CUsartState {
public:

	CUsartStateUsable( CGpioManager *	gpioManager,
					   CRcc	*			rccManager ) :
	m_gpioManager( gpioManager ), m_rccManager( rccManager ) {}

	void remap( uint32_t	remapValue );

	void apbEnable( uint32_t apb1Value,
					uint32_t apb2Value );

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

	void nextState( CUsartState *	currentState,
					bool			switchToNextState );
	void deinit( USART_TypeDef *	id,
				 uint32_t			apb1,
				 uint32_t			apb2 );

	~CUsartStateUsable() {}
private:
	CGpioManager *	m_gpioManager;
	CRcc *			m_rccManager;
};

#endif /* CUSARTSTATEUSABLE_HPP_ */
