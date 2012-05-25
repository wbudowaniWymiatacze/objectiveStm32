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
                             GPIOSpeed_TypeDef speed )
{
    CGpio * gpio;
    
    bool portPinUsed = isGpioUsed(gpio);
    //bool portPinUsed = false;
    
    if ( portPinUsed == true )
        //gpio = new CGpio();
        gpio = m_emptyGpio;
    else
        gpio = new gpiotype(port, pin, speed);
        m_usedGPios.push_front(gpio);

    return gpio;
}
#endif /* CGPIOMANAGER_HPP_ */
