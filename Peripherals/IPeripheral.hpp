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
    friend class CPeriphalManager;
    
public: 
    IPeripheral(CGpioManager * GM):GM(GM),referenceCounter(1){};
    virtual ~IPeripheral() {}

protected:
    CGpioManager * GM;
    
private :  
    int referenceCounter; 
    
};

#endif /* IPERIPHERAL_HPP_ */
