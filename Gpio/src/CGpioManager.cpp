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
    m_emptyGpio = new CGpioEmpty();
}


void CGpioManager::releaseGpio( CGpio * gpio )
{
    m_usedGPios.remove(gpio);
    delete gpio;
}

CGpio * CGpioManager::getGpio(GPIO_TypeDef*     port,
                              uint16_t          pin, 
                              GPIOSpeed_TypeDef speed,
                              GPIOMode_TypeDef  mode)
{
    return reserveGpio(new CGpio(port, pin, speed,mode));
}
bool CGpioManager::isGpioUsed(CGpio* gpio)
{
    //TODO: to replace by list.find(gpio) method ( needs to define compare object like in Device Manager )
    
    TGpioList::iterator Iter;
    for(Iter=m_usedGPios.begin() ; Iter!=m_usedGPios.end();Iter++)
    {
        if( (*(*Iter))==(*gpio) )
        {
            return true;
        }
    }
    
    return false;
    
}
CGpio* CGpioManager::reserveGpio(CGpio* gpio)
{
    bool portPinUsed = isGpioUsed(gpio);
    
    if ( portPinUsed == true )
    {
        delete gpio;
        gpio = m_emptyGpio;
    }
    else
    {
        m_usedGPios.push_front(gpio);
    }        

    return gpio;
}

CGpioManager & CGpioManager::operator=( CGpioManager const & gpioManager )
{
    return const_cast<CGpioManager &> ( gpioManager );
}

CGpioManager::CGpioManager( CGpioManager const & gpioManager )
{
    *this = const_cast<CGpioManager &> ( gpioManager );
}


