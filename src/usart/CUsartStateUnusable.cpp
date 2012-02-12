/*
 * CUsartStateUnusable.cpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#include <CUsartStateUnusable.hpp>

void CUsartStateUnusable::nextState( CUsartState *	currentState,
		 	 	 	 	 	 	 	 bool			switchToNextState )
{
	if ( switchToNextState == true )
	{
		currentState = new CUsartStateUsable;
		delete this;
	}
}

