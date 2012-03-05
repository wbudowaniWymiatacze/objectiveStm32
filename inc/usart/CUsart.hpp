/*
 * CUsart.hpp
 *
 *  Created on: Feb 4, 2012
 *      Author: artur
 */

#ifndef CUSART_HPP_
#define CUSART_HPP_

#include <boardDefs.hpp>

#include <CGpioManager.hpp>
#include <CUsartState.hpp>
#include <CUsartStateUnusable.hpp>
#include <TypePeriph.hpp>

// TODO: klasa bazowa interfejsu CPeripheralInterface, po której dziedziczą CUsart, CSpi itp.
template < typename usartX >
class CUsart {
public:
	CUsart();
	void init( GPIOSpeed_TypeDef	rxSpeed,
			   GPIOMode_TypeDef		rxMode,
			   GPIOSpeed_TypeDef	txSpeed,
			   GPIOMode_TypeDef		txMode,
			   USART_InitTypeDef &	usartConfig );
	~CUsart();

private:
	friend class CUsartState;
	void setId();

	usartX					m_usartParams;
	CUsartState *			m_usartState;
};

template < typename usartX >
CUsart< usartX >::CUsart()
{
	m_usartState = new CUsartStateUnusable;

	bool gpiosSet = CGpioManager::getGpio( m_usartParams.port,
										   m_usartParams.rx );
	gpiosSet &= CGpioManager::getGpio( m_usartParams.port,
									   m_usartParams.tx );

	if ( gpiosSet == false )
	{
		CGpioManager::releaseGpio( m_usartParams.port,
				   	   	   	   	   m_usartParams.rx );
		CGpioManager::releaseGpio( m_usartParams.port,
								   m_usartParams.tx );
	}

	m_usartState->nextState( m_usartState, gpiosSet );
}

template < typename usartX >
void CUsart< usartX >::init( GPIOSpeed_TypeDef		rxSpeed,
							 GPIOMode_TypeDef		rxMode,
							 GPIOSpeed_TypeDef		txSpeed,
							 GPIOMode_TypeDef		txMode,
							 USART_InitTypeDef	&	usartConfig )
{
	m_usartState->remap( m_usartParams.remap );
	// initialise GPIOs
	m_usartState->gpioInit( m_usartParams.port,
							m_usartParams.rx,
							rxSpeed,
							rxMode );
	m_usartState->gpioInit( m_usartParams.port,
							m_usartParams.tx,
							txSpeed,
							txMode );

	//initialise usart
	m_usartState->init( m_usartParams.id,
						usartConfig );
}

template < typename usartX >
CUsart< usartX >::~CUsart()
{
	m_usartState->deinit( m_usartParams.id,
						  m_usartParams.apb1,
						  m_usartParams.apb2 );

	CGpioManager::releaseGpio( m_usartParams.port,
							   m_usartParams.rx );
	CGpioManager::releaseGpio( m_usartParams.port,
							   m_usartParams.tx );
	delete m_usartState;
}

template < >
void CUsart< SUsart1 >::setId()
{
	m_usartParams.id = USART1;
}

template < >
void CUsart< SUsart2 >::setId()
{
	m_usartParams.id = USART1;
}

template < >
void CUsart< SUsart3 >::setId()
{
	m_usartParams.id = USART2;
}

template < >
void CUsart< SUsart4 >::setId()
{
	m_usartParams.id = USART2;
}

template < >
void CUsart< SUsart5 >::setId()
{
	m_usartParams.id = USART3;
}

template < >
void CUsart< SUsart6 >::setId()
{
	m_usartParams.id = USART3;
}

template < >
void CUsart< SUsart7 >::setId()
{
	m_usartParams.id = USART3;
}

#endif /* CUSART_HPP_ */
