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
	void setUsartStmId();
	// TODO: co, jeżeli inny USART niż USART3 ma partial i full
	void setRemapVal();
	friend class CUsartState;

	usartX			m_gpios;
	CUsartState *	m_usartState;
	USART_TypeDef *	m_usartStmId;
	uint32_t		m_remapValue;
};

template < typename usartX >
CUsart< usartX >::CUsart()
{
	m_usartState = new CUsartStateUnusable;

	bool gpiosSet = CGpioManager::getGpio( m_gpios.port,
											m_gpios.rx );
	gpiosSet &= CGpioManager::getGpio( m_gpios.port,
										m_gpios.tx );

	if ( gpiosSet == false )
	{
		CGpioManager::releaseGpio( m_gpios.port,
								   m_gpios.rx );
		CGpioManager::releaseGpio( m_gpios.port,
								   m_gpios.tx );
	}

	setUsartStmId();
	setRemapVal();

	m_usartState->nextState( m_usartState, gpiosSet );
}

// przenieść inicjację do konstruktora USART
template < typename usartX >
void CUsart< usartX >::init( GPIOSpeed_TypeDef		rxSpeed,
							 GPIOMode_TypeDef		rxMode,
							 GPIOSpeed_TypeDef		txSpeed,
							 GPIOMode_TypeDef		txMode,
							 USART_InitTypeDef	&	usartConfig )
{
	m_usartState->remap( m_remapValue );
	// initialise GPIOs
	m_usartState->gpioInit( m_gpios.port,
							m_gpios.rx,
							rxSpeed,
							rxMode );
	m_usartState->gpioInit( m_gpios.port,
							m_gpios.tx,
							txSpeed,
							txMode );

	//initialise usart
	m_usartState->init( m_usartStmId,
						usartConfig );
}

template < >
void CUsart< SUsart1 >::setUsartStmId()
{
	m_usartStmId = USART1;
}

template < >
void CUsart< SUsart2 >::setUsartStmId()
{
	m_usartStmId = USART2;
}

//template < >
//void CUsart< SUsart3 >::setUsartStmId()
//{
//	m_usartStmId = USART3;
//}

template < >
void CUsart< SUsart1 >::setRemapVal()
{
	m_remapValue = GPIO_Remap_USART1;
}

template < >
void CUsart< SUsart2 >::setRemapVal()
{
	m_remapValue = GPIO_Remap_USART2;
}

// TODO: sprawdzić różnicę między FULL, a PARTIAL
//template < >
//void CUsart< SUsart3 >::setRemapVal()
//{
//	m_remapValue = GPIO_FullRemap_USART3;
//}

template < typename usartX >
CUsart< usartX >::~CUsart()
{
	CGpioManager::releaseGpio( m_gpios.port,
							   m_gpios.rx );
	CGpioManager::releaseGpio( m_gpios.port,
							   m_gpios.tx );
	delete m_usartState;
}

#endif /* CUSART_HPP_ */
