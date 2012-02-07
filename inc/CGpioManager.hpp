/*
 * CGpioManager.hpp
 *
 *  Created on: Feb 7, 2012
 *      Author: artur
 */

#ifndef CGPIOMANAGER_HPP_
#define CGPIOMANAGER_HPP_

#include <boardDefs.hpp>

#include <TypePeriph.hpp>
#include <CUsartGpios.hpp>

class CGpioManager {
public:
	CGpioManager();

	/*
	 * return true if pin on the port is free to use (not used by another
	 * peripheral), false otherwise
	 */
	bool checkPortPinAvailability( unsigned short port, unsigned short pin );

	/*
	 * sets pin on the port unused by any peripheral
	 */
	void setPortPinUnused( unsigned short port, unsigned short pin );

	/*
	 * sets pin on the port as used
	 */
	void setPortPinUsed( unsigned short port, unsigned short pin );

	/*
	 * returns NULL if the GPIOs are already in use
	 */
	CUsartGpios * getGpios( EUsart usartX );

	void remap( EUsart usartX );

	/*
	 * deletes
	 */
	void releaseGpios( CUsartGpios * usartGpios );
	~CGpioManager();

private:
	/*
	 * keeps the information whether the pin on the given port is
	 * used by any peripheral
	 */
	bool m_PortPinUsed[ NUMBER_OF_PORTS ][ NUMBER_OF_PINS_PER_PORT ];
};

#endif /* CGPIOMANAGER_HPP_ */
