/*
 * CUsartStateUnusable.cpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#include <CUsartStateUnusable.hpp>
#include <CUsartStateUsable.hpp>
#include <EPeripheralState.hpp>

void CUsartStateUnusable::nextState( CUsartState *  currentState,
                                     bool           switchToNextState )
{
    if ( switchToNextState == true )
    {
    currentState = new CUsartStateUsable( m_gpioManager,
                                          m_rccManager );
    if( currentState == 0 )
    {
        currentState = this;
    }
    else
    {
        delete this;
    }
    }
}

EPeripheralState CUsartStateUnusable::getState()
{
    return m_stateInfo;
}

