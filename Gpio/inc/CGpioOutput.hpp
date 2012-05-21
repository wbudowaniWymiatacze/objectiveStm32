/* 
 * File:   CGpioOutput.hpp
 * Author: reymondo
 *
 * Created on 17 maj 2012, 19:11
 */

#include<CGpio.hpp>

#ifndef CGPIOOUTPUT_HPP
#define	CGPIOOUTPUT_HPP

class CGpioOutput : public CGpio {
public:
    CGpioOutput(GPIO_TypeDef * port, uint16_t pin, GPIOSpeed_TypeDef speed);
    CGpioOutput();
    virtual ~CGpioOutput();
    
    void set(bool state);
    void toogle();
    bool get();
    
    void init();
    
private:

};

#endif	/* CGPIOOUTPUT_HPP */

