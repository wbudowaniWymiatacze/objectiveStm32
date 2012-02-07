/*
 * CUsartGpios.hpp
 *
 *  Created on: Feb 7, 2012
 *      Author: artur
 */

#ifndef CUSARTGPIOS_HPP_
#define CUSARTGPIOS_HPP_

#include <CGpio.hpp>

class CUsartGpios
{
	CUsartGpios( unsigned short rxPort,
				 unsigned short rxPin,
				 unsigned short txPort,
				 unsigned short txPin ) :
		m_rx( rxPort, rxPin ), m_tx( txPort, txPin ) {}
	CGpio m_rx;
	CGpio m_tx;
};


#endif /* CUSARTGPIOS_HPP_ */
