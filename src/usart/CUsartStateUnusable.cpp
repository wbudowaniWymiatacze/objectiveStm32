/*
 * CUsartStateUnusable.cpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#include <CUsartStateUnusable.hpp>
#include <CUsartStateUsable.hpp>
#include <EPeripheralState.hpp>

void CUsartStateUnusable::nextState( CUsartState *	currentState,
		 	 	 	 	 	 	 	 bool			switchToNextState )
{
	// TODO: najpierw sprawdzić czy udało się stworzyć nowy stan, później zależnie od tego
	// przypisać currentState = nowyStan, albo nie zmieniać currentState
	if ( switchToNextState == true )
	{
		delete this;
		currentState = new CUsartStateUsable( m_gpioManager,
											  m_rccManager );
	}
}

EPeripheralState CUsartStateUnusable::getState()
{
	return m_stateInfo;
}

