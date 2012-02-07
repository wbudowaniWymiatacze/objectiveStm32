/*
 * CGpioManager.cpp
 *
 *  Created on: Feb 7, 2012
 *      Author: artur
 */

#include "../inc/CGpioManager.hpp"
#include <TypePeriph.hpp>
#include <CUsartGpios.hpp>
#include <EUsartBitOffset.hpp>
#include <EGpioNumberfBits.hpp>

CGpioManager::CGpioManager() {
	// TODO Auto-generated constructor stub

}

inline bool CGpioManager::checkPortPinAvailability( unsigned short port, unsigned short pin )
{
	return m_PortPinUsed[ port ][ pin ];
}

inline void CGpioManager::setPortPinUnused( unsigned short port, unsigned short pin )
{
	m_PortPinUsed[ port ][ pin ] = false;
}

inline void CGpioManager::setPortPinUsed( unsigned short port, unsigned short pin )
{
	m_PortPinUsed[ port ][ pin ] = true;
}

CUsartGpios * CGpioManager::getGpios( EUsart usartX )
{
	unsigned short rxPort = ( usartX >> EUsartRxPortBitOffset ) & EGpioPortNumberOfBits;
	unsigned short rxPin = ( usartX >> EUsartRxPinBitOffset ) & EGpiotPinNumberOfBits;
	unsigned short txPort = ( usartX >> EUsartTxPortBitOffset ) & EGpioPortNumberOfBits;
	unsigned short txPin = ( usartX >> EUsartTxPinBitOffset ) & EGpiotPinNumberOfBits;

	// check if the port and pin are used by another peripheral
	// RX port and pin
	bool portPinUsed = checkPortPinAvailability( rxPort, rxPin );
	// TX port and pin
	portPinUsed &= checkPortPinAvailability( txPort, txPin );

	if ( portPinUsed == true )
	{
		return 0;
	}

	CUsartGpios * usartGpios = new CUsartGpios( rxPort,
												rxPin,
												txPort,
												txPin );

	if ( usartGpios != 0 )
	{
		setPortPinUsed( rxPort, rxPin );
		setPortPinUsed( txPort, txPin );
	}

	return usartGpios;
}

inline void CGpioManager::releaseGpios( CUsartGpios * usartGpios )
{
	setPortPinUnused( usartGpios->m_rx.getPort(), usartGpios->m_rx.getPin() );
	setPortPinUnused( usartGpios->m_tx.getPort(), usartGpios->m_tx.getPin() );
	delete usartGpios;
	usartGpios = 0;
}

CGpioManager::~CGpioManager() {
	// TODO Auto-generated destructor stub
}

