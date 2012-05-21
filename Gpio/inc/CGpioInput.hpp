/* 
 * File:   CGpioInput.hpp
 * Author: reymondo
 *
 * Created on 17 maj 2012, 19:10
 */

#include <CGpio.hpp>

#ifndef CGPIOINPUT_HPP
#define	CGPIOINPUT_HPP

class CGpioInput: public CGpio {
public:
    CGpioInput(GPIO_TypeDef * port, uint16_t pin, GPIOSpeed_TypeDef speed);
    CGpioInput();
    virtual ~CGpioInput();
    
    bool get();
    
    void init();
    
private:
    

};

#endif	/* CGPIOINPUT_HPP */

