/*
 * CGpioManager.hpp
 *
 *  Created on: Feb 7, 2012
 *      Author: artur
 */

#ifndef CGPIOMANAGER_HPP_
#define CGPIOMANAGER_HPP_

#include <boardDefs.hpp>

/*
 * only CManagersFactory can create it!!
 */
class CGpioManager {
public:
	CGpioManager();
	/*
	 * return true if pin on the port is free to use (not used by another
	 * peripheral), false otherwise
	 */
	bool checkPortPinAvailability( uint8_t port, uint8_t pin );

	/*
	 * sets pin on the port unused by any peripheral
	 */
	void setPortPinUnused( uint8_t port, uint8_t pin );

	/*
	 * sets pin on the port as used
	 */
	void setPortPinUsed( uint8_t port, uint8_t pin );

	/*
	 * returns false if the GPIOs are already in use
	 */
	bool getGpio( uint8_t port,
				  uint8_t pin );

	/*
	 * remap GPIOs
	 */
	void remap( uint32_t remapValue );

	/*
	 * initialise GPIO
	 */
	void initGpio( uint8_t				port,
				   GPIO_InitTypeDef *	gpioConfig );

	/*
	 * set pins of given GPIOs as unused
	 */
	void releaseGpio( uint8_t port,
			 	 	  uint8_t pin );

	CGpioManager & operator=( CGpioManager const & gpioManager );
	CGpioManager( CGpioManager const & gpioManager );

private:
	GPIO_TypeDef * m_gpioPortAddress[ NUMBER_OF_PORTS ];
	/*
	 * keeps the information whether the pin on the given port is
	 * used by any peripheral
	 */
	bool m_portPinUsed[ NUMBER_OF_PORTS ][ NUMBER_OF_PINS_PER_PORT ];
};

#endif /* CGPIOMANAGER_HPP_ */
