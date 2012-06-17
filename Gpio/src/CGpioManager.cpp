/*
 * CGpioManager.cpp
 *
 *  Created on: Feb 7, 2012
 *      Author: artur
 */

#include <boardDefs.hpp>

#include <CGpioManager.hpp>
#include <list>
#include <algorithm>

CGpioManager::CGpioManager()
{
    m_emptyGpio = new CGpio();
}


void CGpioManager::releaseGpio( CGpio * gpio )
{
    m_usedGPios.remove(gpio);
}

bool CGpioManager::isGpioUsed(CGpio* gpio)
{
    TGpioList::iterator Iter;
    for(Iter=m_usedGPios.begin() ; Iter!=m_usedGPios.end();Iter++)
    {
        if( (*(*Iter))==(*gpio) )
        {
            return true;
        }
    }
    
    return false;
    
    //result = std::find( m_usedGPios.begin(), m_usedGPios.end( ), gpio );
    //if  ( result == m_usedGPios.end() )
    //    return false;
    //else
    //    return true;
    
}

CGpioManager & CGpioManager::operator=( CGpioManager const & gpioManager )
{
    return const_cast<CGpioManager &> ( gpioManager );
}

CGpioManager::CGpioManager( CGpioManager const & gpioManager )
{
    *this = const_cast<CGpioManager &> ( gpioManager );
}


