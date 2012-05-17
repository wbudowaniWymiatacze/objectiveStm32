/* 
 * File:   CGpio.hpp
 * Author: reymondo
 *
 * Created on 17 maj 2012, 18:31
 */

#include <boardDefs.hpp>

#ifndef CGPIO_HPP
#define	CGPIO_HPP

class CGpio {
public:
    CGpio(GPIO_TypeDef * port, uint16_t pin, GPIOSpeed_TypeDef speed, GPIOMode_TypeDef mode);
    
    virtual ~CGpio();
    
    void set(bool state);
    void toogle();
    bool get();
    
    void init();
    
protected:
    GPIO_TypeDef *    m_GpioPort;
    uint16_t          m_GpioPin;
    GPIOSpeed_TypeDef m_GpioSpeed;    
    GPIOMode_TypeDef  m_GpioMode;
};

#endif	/* CGPIO_HPP */

