/*
 * CUsartIrqHandler.cpp
 *
 *  Created on: Mar 29, 2012
 *      Author: artur
 */

#include <boardDefs.hpp>

#include <IPeripheral.hpp>

#include <CUsartIrqHandler.hpp>

CUsartIrqHandler::CUsartIrqHandler() {

    for( uint32_t usartIndex=0; usartIndex<NUMBER_OF_USARTS; usartIndex++ )
    {
        m_usart[ usartIndex ] = 0;
    }
}

CUsartIrqHandler::CUsartIrqHandler( IPeripheral * usart )
{
    for( uint32_t usartIndex=0; usartIndex<NUMBER_OF_USARTS; usartIndex++ )
    {
    m_usart[ usartIndex ] = 0;
    }

    registerPeripheral( usart );
}

void CUsartIrqHandler::registerPeripheral( IPeripheral * usart )
{
    m_usart[ usart->getIndex() ] = usart;
}

void CUsartIrqHandler::unregisterPeripheral( IPeripheral * usart )
{
    m_usart[ usart->getIndex() ] = 0;
}

