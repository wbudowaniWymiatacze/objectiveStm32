/*
 * IPeripheral.hpp
 *
 *  Created on: Mar 13, 2012
 *      Author: artur
 */

#ifndef IPERIPHERAL_HPP_
#define IPERIPHERAL_HPP_

#include <boardDefs.hpp>

#include <CGpioManager.hpp>
#include <PeripheralTypes.hpp>

class IPeripheral
{
public:
    
    IPeripheral(CGpioManager * GM):GM(GM),reference(1){};

    virtual ~IPeripheral() {}

protected:
    CGpioManager * GM;
private :  
    int reference;
    
    
};


#endif /* IPERIPHERAL_HPP_ */
