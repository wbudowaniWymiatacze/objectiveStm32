/*
 * CGpioManager.hpp
 *
 *  Created on: Feb 7, 2012
 *      Author: artur
 */
#include <boardDefs.hpp>
#include <CGpio.hpp>
#include <list>


#ifndef CGPIOMANAGER_HPP_
#define CGPIOMANAGER_HPP_


/*
 * only CManagersFactory can create it!!
 */
class CGpioManager {
    
    typedef std::list <CGpio*> TGpioList;
    
public:
    CGpioManager();

    /*
     * set given Gpio as unused
     */
    void releaseGpio( CGpio * gpio );
    
    /*
     * returns CGpio object if the GPIO is not already in use
     */
    template <typename gpiotype> 
    CGpio * getGpio( GPIO_TypeDef * port, 
                      uint16_t pin,
                      GPIOSpeed_TypeDef speed );


    CGpioManager & operator=( CGpioManager const & gpioManager );
    CGpioManager( CGpioManager const & gpioManager );

private:
    TGpioList m_usedGPios;
    CGpio* m_emptyGpio;
    bool isGpioUsed(CGpio* gpio);

};


template <typename gpiotype> 
CGpio * CGpioManager::getGpio( GPIO_TypeDef * port,
                             uint16_t pin, 
                             GPIOSpeed_TypeDef speed = GPIO_Speed_10MHz )
{
    CGpio * gpio = new gpiotype(port, pin, speed);
    
    bool portPinUsed = isGpioUsed(gpio);
    //bool portPinUsed = false;
    
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
#endif /* CGPIOMANAGER_HPP_ */
