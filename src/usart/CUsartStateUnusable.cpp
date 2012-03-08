/*
 * CUsartStateUnusable.cpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#include <CUsartStateUnusable.hpp>
#include <CUsartStateUsable.hpp>

void CUsartStateUnusable::nextState( CUsartState *	currentState,
		 	 	 	 	 	 	 	 bool			switchToNextState )
{
	if ( switchToNextState == true )
	{
		delete this;
		currentState = new CUsartStateUsable( m_gpioManager,
											  m_rccManager );
	}
}

