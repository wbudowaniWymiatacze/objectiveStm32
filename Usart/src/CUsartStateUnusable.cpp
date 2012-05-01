/*
 * CUsartStateUnusable.cpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#include <IPeripheral.hpp>
#include <IPeriphState.hpp>
#include <CUsartStateUnusable.hpp>
#include <CUsartStateUsable.hpp>
#include <EPeripheralState.hpp>

IPeriphState * CUsartStateUnusable::nextState( bool  switchToNextState )
{
    if ( switchToNextState == true )
    {
        IPeriphState * newState = new CUsartStateUsable( m_gpioManager,
                                                          m_rccManager );
        if( newState != 0 )
        {
            delete this;
            return newState;
        }
    }
    return this;
}

EPeripheralState CUsartStateUnusable::getState()
{
    return m_stateInfo;
}

