/*
 * CGpioManager.hpp
 *
 *  Created on: Feb 7, 2012
 *      Author: artur
 */
#include <boardDefs.hpp>
#include <CGpio.hpp>
#include <CGpioEmpty.hpp>
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
    CGpio* getGpio(GPIO_TypeDef*     port, 
                   uint16_t          pin,
                   GPIOSpeed_TypeDef speed );
    
    CGpio* getGpio(GPIO_TypeDef*     port, 
                   uint16_t          pin,
                   GPIOSpeed_TypeDef speed,
                   GPIOMode_TypeDef  mode);
    
    
    CGpioManager & operator=( CGpioManager const & gpioManager );
    CGpioManager( CGpioManager const & gpioManager );

private:
    TGpioList m_usedGPios;
    CGpio*    m_emptyGpio;
    
    bool   isGpioUsed(CGpio* gpio);
    CGpio* reserveGpio(CGpio* gpio);

};


template <typename gpiotype> 
CGpio * CGpioManager::getGpio( GPIO_TypeDef * port,
                             uint16_t pin, 
                             GPIOSpeed_TypeDef speed = GPIO_Speed_10MHz )
{
    return reserveGpio(new gpiotype(port, pin, speed));
}
#endif /* CGPIOMANAGER_HPP_ */
