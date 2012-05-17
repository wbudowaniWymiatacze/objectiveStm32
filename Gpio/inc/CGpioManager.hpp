/*
 * CGpioManager.hpp
 *
 *  Created on: Feb 7, 2012
 *      Author: artur
 */
#include <CGpio.hpp>

#ifndef CGPIOMANAGER_HPP_
#define CGPIOMANAGER_HPP_

#include <boardDefs.hpp>

/*
 * only CManagersFactory can create it!!
 */
class CGpioManager {
public:
    CGpioManager();
    /*
     * return true if pin on the port is free to use (not used by another
     * peripheral), false otherwise
     */
    bool checkPortPinAvailability( uint8_t port, uint8_t pin );

    /*
     * sets pin on the port unused by any peripheral
     */
    void setPortPinUnused( uint8_t port, uint8_t pin );

    /*
     * sets pin on the port as used
     */
    void setPortPinUsed( uint8_t port, uint8_t pin );

    /*
     * returns false if the GPIOs are already in use
     */
    bool getGpio( uint8_t port,
          uint8_t pin );

    /*
     * remap GPIOs
     */
    void remap( uint32_t remapValue );

    /*
     * initialise GPIO
     */
    void initGpio( uint8_t              port,
                   GPIO_InitTypeDef *   gpioConfig );

    /*
     * set pins of given GPIOs as unused
     */
    void releaseGpio( uint8_t   port,
                      uint8_t   pin );
    
    /*
     * returns CGpio object if the GPIO is not already in use
     */
    template <typename gpiotype> 
    gpiotype getGpio( GPIO_TypeDef * port, 
                      uint16_t pin,
                      GPIOSpeed_TypeDef speed );
    
    uint8_t getPortIndex(GPIO_TypeDef * port);
    
    uint8_t getPinIndex(uint16_t pin);

    CGpioManager & operator=( CGpioManager const & gpioManager );
    CGpioManager( CGpioManager const & gpioManager );

private:
    GPIO_TypeDef * m_gpioPortAddress[ NUMBER_OF_PORTS ];
    /*
     * keeps the information whether the pin on the given port is
     * used by any peripheral
     */
    bool m_portPinUsed[ NUMBER_OF_PORTS ][ NUMBER_OF_PINS_PER_PORT ];
};


template <typename gpiotype> 
gpiotype CGpioManager::getGpio( GPIO_TypeDef * port,
                             uint16_t pin, 
                             GPIOSpeed_TypeDef speed )
{
    
    // check if the port and pin are used by another peripheral
    bool portPinUsed = checkPortPinAvailability( getPortIndex(port), getPinIndex(pin) );

    if ( portPinUsed == true )
    {
    return CGpio(port, pin, speed);
    }

    // set the port and the pin as used
    setPortPinUsed( getPortIndex(port), getPinIndex(pin) );

    return gpiotype(port, pin, speed);
}
#endif /* CGPIOMANAGER_HPP_ */
