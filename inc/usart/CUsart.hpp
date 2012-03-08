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
#include <CRcc.hpp>
#include <CUsartState.hpp>
#include <CUsartStateUnusable.hpp>
#include <TypePeriph.hpp>

// TODO: klasa bazowa interfejsu CPeripheralInterface, po której dziedziczą CUsart, CSpi itp.
template < typename usartX >
class CUsart {
public:
	CUsart( CGpioManager & gpioManager,
			CRcc & rccManager );
	void init( GPIOSpeed_TypeDef	rxSpeed,
			   GPIOMode_TypeDef		rxMode,
			   GPIOSpeed_TypeDef	txSpeed,
			   GPIOMode_TypeDef		txMode,
			   USART_InitTypeDef &	usartConfig );
	void read( uint16_t *	data,
			   uint8_t		nData );
	void write( uint16_t *	data,
			    uint8_t		nData );
	~CUsart();

private:
	friend class CUsartState;
	void setId();

	usartX					m_usartParams;
	CUsartState *			m_usartState;
	CGpioManager 			m_gpioManager;
	CRcc					m_rccManager;

};

template < typename usartX >
CUsart< usartX >::CUsart( CGpioManager & gpioManager,
						  CRcc & rccManager )
{
	m_gpioManager = gpioManager;
	m_rccManager = rccManager;
	m_usartState = new CUsartStateUnusable( &m_gpioManager,
											&m_rccManager );

	bool gpiosSet = m_gpioManager.getGpio( m_usartParams.port,
										   m_usartParams.rx );
	gpiosSet &= m_gpioManager.getGpio( m_usartParams.port,
									   m_usartParams.tx );

	if ( gpiosSet == false )
	{
		m_gpioManager.releaseGpio( m_usartParams.port,
				   	   	   	   	   m_usartParams.rx );
		m_gpioManager.releaseGpio( m_usartParams.port,
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
void CUsart< usartX >::read( uint16_t *	data,
			   	   	   	   	 uint8_t	nData )
{
	m_usartState->read( m_usartParams.id,
						data,
						nData );
}

template < typename usartX >
void CUsart< usartX >::write( uint16_t *	data,
			   	   	   	   	  uint8_t		nData )
{
	m_usartState->write( m_usartParams.id,
						 data,
						 nData );
}

template < typename usartX >
CUsart< usartX >::~CUsart()
{
	m_usartState->deinit( m_usartParams.id,
						  m_usartParams.apb1,
						  m_usartParams.apb2 );

	m_gpioManager.releaseGpio( m_usartParams.port,
							   m_usartParams.rx );
	m_gpioManager.releaseGpio( m_usartParams.port,
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
