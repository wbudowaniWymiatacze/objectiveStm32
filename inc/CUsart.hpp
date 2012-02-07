/*
 * CUsart.hpp
 *
 *  Created on: Feb 4, 2012
 *      Author: artur
 */

#ifndef CUSART_HPP_
#define CUSART_HPP_

// ST includes
#include <stm32f10x_gpio.h>

#include <CGpioManager.hpp>
#include <TypePeriph.hpp>
#include <CUsartGpios.hpp>

// TODO: klasa bazowa interfejsu CPeripheralInterface, po której dziedziczą CUsart, CSpi itp.
template < EUsart usartX >
class CUsart {
public:
	CUsart();
	void gpiosInit( GPIOSpeed_TypeDef	rxSpeed,
			  	  	GPIOMode_TypeDef	rxMode,
			  	  	GPIOSpeed_TypeDef	txSpeed,
			  	  	GPIOMode_TypeDef	txMode );
	void init();
	~CUsart();

private:
	CUsartGpios * m_gpios;
};

template < EUsart usartX >
CUsart< usartX >::CUsart()
{
	m_gpios = CGpioManager::getGpios( usartX );
}

template < EUsart usartX >
void CUsart< usartX >::gpiosInit( GPIOSpeed_TypeDef	rxSpeed,
								  GPIOMode_TypeDef	rxMode,
								  GPIOSpeed_TypeDef txSpeed,
								  GPIOMode_TypeDef	txMode )
{
	m_gpios->m_rx.init( rxSpeed, rxMode );
	m_gpios->m_tx.init( txSpeed, txMode );
}

template < EUsart usartX >
void CUsart< usartX >::init()
{
	CGpioManager::remap( usartX );

	//Write USART parameters
	//USART_Init(USART2, &USART_InitStructure);

	//Enable USART
	//USART_Cmd(USART2, ENABLE);
}

template < EUsart usartX >
CUsart< usartX >::~CUsart()
{
	CGpioManager::releaseGpios( m_gpios );
}

#endif /* CUSART_HPP_ */
