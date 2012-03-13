/*
 * CUsart.hpp
 *
 *  Created on: Feb 4, 2012
 *      Author: artur
 */

#ifndef CUSART_HPP_
#define CUSART_HPP_

#include <boardDefs.hpp>

#include <IPeripheral.hpp>
#include <SUsartConfig.hpp>
#include <CGpioManager.hpp>
#include <CRccManager.hpp>
#include <CUsartState.hpp>
#include <CUsartStateUnusable.hpp>
#include <TypePeriph.hpp>

// TODO: klasa bazowa interfejsu CPeripheralInterface, po której dziedziczą CUsart, CSpi itp.
template < typename usartX >
class CUsart : public IPeripheral {
public:
	CUsart( CGpioManager & gpioManager,
			CRccManager & rccManager );
	void init( GPIO_InitTypeDef *	gpiosConfig,
			   SPeriphConfig *		config );
	void read( uint16_t *	data,
			   uint8_t		nData );
	void write( uint16_t *	data,
			    uint8_t		nData );
	void deinit();
	~CUsart();

private:
	friend class CUsartState;
	void setId();

	usartX					m_usartParams;
	CUsartState *			m_usartState;
	CGpioManager 			m_gpioManager;
	CRccManager				m_rccManager;

};

template < typename usartX >
CUsart< usartX >::CUsart( CGpioManager & gpioManager,
						  CRccManager & rccManager )
{
	m_gpioManager = gpioManager;
	m_rccManager = rccManager;
	m_usartState = new CUsartStateUnusable( &m_gpioManager,
											&m_rccManager );
}

template < typename usartX >
void CUsart< usartX >::init( GPIO_InitTypeDef *	gpiosConfig,
							 SPeriphConfig *	config )
{
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

	m_usartState->remap( m_usartParams.remap );

	// initialise GPIOs
	for( uint8_t nGpio = 0; nGpio<USART_NUMBER_GPIOS; nGpio++ )
	{
		m_usartState->gpioInit( m_usartParams.port,
								m_usartParams.rx,
								gpiosConfig[ nGpio ] );
	}

	//initialise usart
	SUsartConfig * usartConfStruct = ( SUsartConfig * ) config;
	m_usartState->init( m_usartParams.id,
						usartConfStruct->usartConfig );
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
void CUsart< usartX >::deinit()
{
	m_usartState->deinit( m_usartParams.id,
						  m_usartParams.apb1,
						  m_usartParams.apb2,
						  m_usartState );

	m_gpioManager.releaseGpio( m_usartParams.port,
							   m_usartParams.rx );
	m_gpioManager.releaseGpio( m_usartParams.port,
							   m_usartParams.tx );
}

template < typename usartX >
CUsart< usartX >::~CUsart()
{
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
