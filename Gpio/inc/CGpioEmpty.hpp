/* 
 * File:   CGpioEmpty.hpp
 * Author: reymondo
 *
 * Created on 4 listopad 2012, 19:11
 */

#include<CGpio.hpp>

#ifndef CGPIOEmpty_HPP
#define	CGPIOEmpty_HPP

class CGpioEmpty : public CGpio {
public:
    CGpioEmpty();
    virtual ~CGpioEmpty();
    
    void init();
    
private:

};

#endif	/* CGPIOEmpty_HPP */

