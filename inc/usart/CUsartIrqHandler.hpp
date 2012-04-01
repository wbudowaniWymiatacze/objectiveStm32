/*
 * CUsartIrqHandler.hpp
 *
 *  Created on: Mar 29, 2012
 *      Author: artur
 */

#ifndef CUSARTIRQHANDLER_HPP_
#define CUSARTIRQHANDLER_HPP_

#include <boardDefs.hpp>

#include <IPeripheral.hpp>

class IIrqHandler
{
public:
	IIrqHandler() {}
	IIrqHandler( IPeripheral * periph );
	virtual void registerPeripheral( IPeripheral * periph ) = 0;
	virtual void unregisterPeripheral( IPeripheral * periph ) = 0;
	virtual ~IIrqHandler();
};

class CUsartIrqHandler : public IIrqHandler {
public:
	CUsartIrqHandler();
	CUsartIrqHandler( IPeripheral * usart );
	void registerPeripheral( IPeripheral * usart );
	void unregisterPeripheral( IPeripheral * usart );

	/*
	 * Interrupt handling functions. To be implemented by a programmer
	 */
	static void usart1Handler();
	static void usart2Handler();
	static void usart3Handler();

private:
	static IPeripheral *	m_usart[ NUMBER_OF_USARTS ];
};

#endif /* CUSARTIRQHANDLER_HPP_ */
