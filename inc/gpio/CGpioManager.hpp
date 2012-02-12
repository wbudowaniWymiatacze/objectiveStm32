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

class CGpioManager {
public:
	CGpioManager();

	/*
	 * return true if pin on the port is free to use (not used by another
	 * peripheral), false otherwise
	 */
	static bool checkPortPinAvailability( unsigned short port, unsigned short pin );

	/*
	 * sets pin on the port unused by any peripheral
	 */
	static void setPortPinUnused( unsigned short port, unsigned short pin );

	/*
	 * sets pin on the port as used
	 */
	static void setPortPinUsed( unsigned short port, unsigned short pin );

	/*
	 * returns false if the GPIOs are already in use
	 */
	static bool getGpio( uint32_t port,
						 uint32_t pin );

	/*
	 * remap GPIOs
	 */
	static void remap( uint32_t remapValue );

	/*
	 * initialise GPIO
	 */
	static void initGpio( uint32_t				port,
						  GPIO_InitTypeDef *	gpioConfig );

	/*
	 * set pins of given GPIOs as unused
	 */
	static void releaseGpio( uint32_t port,
			 	 	 	 	 uint32_t pin );
	~CGpioManager();

private:
};

#endif /* CGPIOMANAGER_HPP_ */
