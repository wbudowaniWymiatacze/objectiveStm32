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
#include <CButton.hpp>

class PeripheralMapsStorage {
public:
    PeripheralMapsStorage();
    PeripheralMapsStorage(const PeripheralMapsStorage& orig);
    virtual ~PeripheralMapsStorage();
    
    operator PeripheralMapTypes<CLed>::TPeriphMap&()
    {
        return LedPeriphMap;
    }
    operator PeripheralMapTypes<CButton>::TPeriphMap&()
    {
        return ButtonPeriphMap;
    }
    operator PeripheralMapTypes<CI2C>::TPeriphMap&()
    {
        return I2CPeriphMap;
    }
    operator PeripheralMapTypes<CUsart>::TPeriphMap&()
    {
        return CUsartPeriphMap;
    }
    
private:
    PeripheralMapTypes<CLed>::TPeriphMap    LedPeriphMap;
    PeripheralMapTypes<CButton>::TPeriphMap ButtonPeriphMap;
    PeripheralMapTypes<CI2C>::TPeriphMap    I2CPeriphMap;
    PeripheralMapTypes<CUsart>::TPeriphMap  CUsartPeriphMap;

};

#endif	/* PERIPHERALMAPSSTORAGE_HPP */

