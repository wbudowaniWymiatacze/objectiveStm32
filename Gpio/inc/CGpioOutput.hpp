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
    virtual ~CGpioOutput();
    
    void set(bool state);
    void toogle();
    bool get();
private:

};

#endif	/* CGPIOOUTPUT_HPP */

