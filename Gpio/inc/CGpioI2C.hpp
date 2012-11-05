/* 
 * File:   CGpioI2C.hpp
 * Author: reymondo
 *
 * Created on 4 listopad 2012, 19:11
 */

#include<CGpio.hpp>

#ifndef CGPIOI2C_HPP
#define	CGPIOI2C_HPP

class CGpioI2C : public CGpio {
public:
    CGpioI2C(GPIO_TypeDef * port, uint16_t pin, GPIOSpeed_TypeDef speed);
    CGpioI2C();
    virtual ~CGpioI2C();
    
    void init();
    
private:

};

#endif	/* CGPIOI2C_HPP */

