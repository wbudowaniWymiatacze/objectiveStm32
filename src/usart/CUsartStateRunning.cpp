/*
 * CUsartStateRunning.cpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#include <CUsartStateRunning.hpp>
#include <CUsartStateUsable.hpp>

void CUsartStateRunning::read( USART_TypeDef *	usartId,
							   uint16_t *		data,
							   uint8_t			nData )
{
	for( uint8_t n=0; n<nData; n++ )
	{
		data[ n-1 ] = USART_ReceiveData( usartId );
	}
}

void CUsartStateRunning::write( USART_TypeDef *	usartId,
								uint16_t *		data,
								uint8_t			nData )
{
	for( uint8_t n=0; n<nData; n++ )
	{
		USART_SendData( usartId,
						data[ n-1 ] );
		while( USART_GetFlagStatus( usartId, USART_FLAG_TC ) == RESET)
		{
			;
		}
	}
}

void CUsartStateRunning::interruptsConfig( NVIC_InitTypeDef & interruptsConfig )
{
	NVIC_Init( &interruptsConfig );
}

void CUsartStateRunning::deinit( USART_TypeDef *	id,
		 	 	 	 	 	 	 uint32_t			apb1,
		 	 	 	 	 	 	 uint32_t			apb2,
		 	 	 	 	 	 	 CUsartState *		usartState )
{
	CUsartStateUsable * usartUsable = new CUsartStateUsable( m_gpioManager,
								   	   	   	   	   	   	  	 m_rccManager );

	usartUsable->deinit( id,
						 apb1,
						 apb2,
						 usartState );

	delete this;
}

