/*
 * IPeripheral.hpp
 *
 *  Created on: Mar 13, 2012
 *      Author: artur
 */

#ifndef IPERIPHERAL_HPP_
#define IPERIPHERAL_HPP_

#include <boardDefs.hpp>

#include <CGpioManager.hpp>
#include <CRccManager.hpp>
#include <SPeriphConfig.hpp>

class IPeripheral
{
public:
	/*
	 * In case when 2 devices use the same GPIO initialisation
	 * and deinitialisation of a peripheral needs to be run.
	 * To avoid calling constructor and destructor many times
	 * this is done in init(...) and deinit(...) functions
	 *
	 * @param[in]:
	 * gpioManager		reference to a GPIO manager.
	 * 					Global object which may become a singleton
	 * 					Dependency Injection is used
	 * 					to avoid incorrect results of testing.
	 *
	 * rccManager		reference to RCC manager.
	 * 					Global object which may become a singleton
	 * 					Dependency Injection is used
	 * 					to avoid incorrect results of testing.
	 */
//	IPeripheral( CGpioManager & gpioManager,
//				 CRccManager & rccManager );

	/*
	 * Sets its GPIOs as used, initialises them and the peripheral.
	 *
	 * @param[in]:
	 * gpiosConfig			pointer to the array of
	 * 						configuration structures of GPIOs
	 *
	 * SPeriphConfig		reference to a configuration structure
	 * 						of the peripheral
	 */
	virtual void init( GPIO_InitTypeDef *	gpiosConfig,
			   	   	   SPeriphConfig *		 ) = 0;

	/*
	 * Reads the specified amount of data
	 * from physical input to the given buffer.
	 *
	 * @param[inout]:
	 * data				pointer to the buffer to save data to
	 *
	 * nData			amount of data to read. 2*nData bytes will be read
	 */
	virtual void read( uint16_t *	data,
			   	   	   uint8_t		nData ) = 0;

	/*
	 * Reads the specified amount of data
	 * from physical input to the given buffer.
	 *
	 * @param[inout]:
	 * data				pointer to the buffer to read data from
	 *
	 * nData			amount of data to write. 2*nData bytes will be written
	 */
	virtual void write( uint16_t *	data,
			    		uint8_t		nData ) = 0;

	/*
	 * Turns interrupts for a peripheral on and sets it to the specified
	 * priority and subpriority
	 *
	 * @param[in]:
	 * priority			priority of the interrupt channel
	 *
	 * subpriority		subpriority of the interrupt channel
	 */
	virtual void interruptsOn( uint8_t	priority,
					   	   	   uint8_t	subpriority ) = 0;

	/*
	 * Turns interrupts for a peripheral off
	 */
	virtual void interruptsOff() = 0;

	/*
	 * Deinitialises the peripheral and GPIOs it uses.
	 * Releases the GPIOs.
	 */
	virtual void deinit() = 0;

	virtual ~IPeripheral() = 0;
};

IPeripheral::~IPeripheral()
{

}


#endif /* IPERIPHERAL_HPP_ */