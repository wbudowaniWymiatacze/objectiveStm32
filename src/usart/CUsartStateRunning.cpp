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
void CUsartStateRunning::read()
{

}

/*
 * TODO: implement write
 */
void CUsartStateRunning::write()
{

}

void CUsartStateRunning::deinit( USART_TypeDef *	id,
		 	 	 	 	 	 	 uint32_t			apb1,
		 	 	 	 	 	 	 uint32_t			apb2 )
{
	// all the initialisation was done in CUsartStateUsable
	// also deinitialisation is implemented in there
	CUsartStateUsable usartUsable;
	usartUsable.deinit( id,
						apb1,
						apb2 );
}

