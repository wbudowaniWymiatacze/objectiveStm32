/*
 * CPeripheralInterface.hpp
 *
 *  Created on: Jan 21, 2012
 *      Author: artur
 */

#ifndef CPERIPHERALINTERFACE_HPP_
#define CPERIPHERALINTERFACE_HPP_

// ST headers
#include <misc.h>

// our headers
#include <SPeriphConfig.h>

/*
 * base class for peripherals. Specifies interface for the peripherals.
 * Purely virtual.
 */
template < typename T >
class CPeripheralInterface
{
public:

	CPeripheralInterface() {}

	/* creates the object
	 *
	 * @param[in]	apb2PeriphClock	specifies which APB2 peripheral to refer to
	 *
	 */
	CPeripheralInterface( u32 apb2PeriphClock ) {}

	/*
	 * initialises peripheral:
	 * - initialises its APB2 clock
	 * - sets a peripheral's configuration structure
	 * - initialises the peripheral with its configuration structure
	 *
	 * @param[in]	SPeriphConfig*	pointer to the configuration structure of
	 * 								a peripheral
	 *
	 * @param[out]	bool			True if configuration was successful, False otherwise
	 */
	virtual bool init( SPeriphConfig* ) {}

	/*
	 * configure a peripheral's interrupts
	 */
	virtual bool configInterrupts( NVIC_InitTypeDef* ) {}

	/*
	 * read data from a peripheral's global input buffer to the class' input buffer
	 */
	virtual bool read() {}

	/*
	 * write data from the class' output buffer to a peripheral's global output buffer
	 */
	virtual bool write() {}

	/*
	 * copy data from input buffer
	 */
	void getInputBufferData( T* ) {}

	/*
	 * copy data to output buffer
	 */
	void setOutputBufferData( T* ){}

	virtual ~CPeripheralInterface()
	{

	}

	// fields
	/*
	 * a peripheral's APB2 clock
	 */
	u32 m_apb2PeriphClock;

	/*
	 * a peripheral's configuration structure
	 */
	SPeriphConfig m_configStruct;

	/*
	 * interrupts configuration structure
	 */
	NVIC_InitTypeDef m_interruptsConfig;

	/*
	 * input buffer
	 */
	T* m_inBuffer;

	/*
	 * input buffer
	 */
	T* m_outBuffer;

	/*
	 * DMA to transfer data between a peripheral's global buffers and the class' buffers
	 */
	CPeripheralInterface< T >* m_dma;
};

#endif /* CPERIPHERALINTERFACE_HPP_ */
