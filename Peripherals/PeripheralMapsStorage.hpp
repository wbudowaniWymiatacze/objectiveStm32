/* 
 * File:   PeripheralMapsStorage.hpp
 * Author: reymondo
 *
 * Created on 5 listopad 2012, 19:56
 */

#ifndef PERIPHERALMAPSSTORAGE_HPP
#define	PERIPHERALMAPSSTORAGE_HPP

#include <PeripheralTypes.hpp>
#include <CLed.hpp>
#include <CI2C.hpp>
#include <CUsart.hpp>

class PeripheralMapsStorage {
public:
    PeripheralMapsStorage();
    PeripheralMapsStorage(const PeripheralMapsStorage& orig);
    virtual ~PeripheralMapsStorage();
    
    operator PeripheralTypes<CLed>::TPeriphMap&()
    {
        return LedPeriphMap;
    }
    operator PeripheralTypes<CI2C>::TPeriphMap&()
    {
        return I2CPeriphMap;
    }
    operator PeripheralTypes<CUsart>::TPeriphMap&()
    {
        return CUsartPeriphMap;
    }
    
private:
    PeripheralTypes<CLed>::TPeriphMap LedPeriphMap;
    PeripheralTypes<CI2C>::TPeriphMap I2CPeriphMap;
    PeripheralTypes<CUsart>::TPeriphMap CUsartPeriphMap;

};

#endif	/* PERIPHERALMAPSSTORAGE_HPP */

