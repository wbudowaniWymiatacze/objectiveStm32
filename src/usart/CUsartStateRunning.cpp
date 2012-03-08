/*
 * CUsartStateRunning.cpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#include <CUsartStateRunning.hpp>
#include <CUsartStateUsable.hpp>

/*
 * TODO: implement read
 */
void CUsartStateRunning::read( USART_TypeDef *	usartId,
							   uint16_t *		data,
							   uint8_t			nData )
{
	while( nData > 0 )
	{
		data[ nData-1 ] = USART_ReceiveData( usartId );
	}
}

/*
 * TODO: implement write
 */
void CUsartStateRunning::write( USART_TypeDef *	usartId,
								uint16_t *		data,
								uint8_t			nData )
{
	while( nData > 0 )
	{
		USART_SendData( usartId,
						data[ nData-1 ] );
		while( USART_GetFlagStatus( usartId, USART_FLAG_TC ) == RESET)
		{
			;
		}
	}
}

void CUsartStateRunning::deinit( USART_TypeDef *	id,
		 	 	 	 	 	 	 uint32_t			apb1,
		 	 	 	 	 	 	 uint32_t			apb2 )
{
	// all the initialisation was done in CUsartStateUsable
	// also deinitialisation is implemented in there
	CUsartStateUsable usartUsable( m_gpioManager,
								   m_rccManager );
	usartUsable.deinit( id,
						apb1,
						apb2 );
}

