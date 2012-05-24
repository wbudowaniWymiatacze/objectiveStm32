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
    CGpio();
    
    virtual ~CGpio();
    
    virtual void set(bool state);
    virtual void toogle();
    virtual bool get();
    
    virtual void init();
    
    int operator == (CGpio const &);  
    
    void remap(uint32_t remapValue);
    
protected:
    void realInit();    
    GPIO_TypeDef *    m_GpioPort;
    uint16_t          m_GpioPin;
    GPIOSpeed_TypeDef m_GpioSpeed;    
    GPIOMode_TypeDef  m_GpioMode;
};

#endif	/* CGPIO_HPP */

