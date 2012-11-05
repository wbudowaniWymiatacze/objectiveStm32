/* 
 * File:   CPeriphalManager.cpp
 * Author: reymondo
 * 
 * Created on 12 czerwiec 2012, 18:51
 */

#include <CPeriphalManager.hpp>



CPeriphalManager::CPeriphalManager(CGpioManager * GM) :
GM(GM)
{

}

CPeriphalManager::CPeriphalManager(const CPeriphalManager& orig) 
{
    GM = orig.GM;
}

CPeriphalManager::~CPeriphalManager() 
{
    
}

void CPeriphalManager::enableAPB1(uint32_t apb1)
{
     RCC_APB1PeriphClockCmd(apb1, ENABLE);
}
void CPeriphalManager::enableAPB2(uint32_t apb2)
{
    RCC_APB2PeriphClockCmd(apb2, ENABLE);
}
void CPeriphalManager::disableAPB1(uint32_t apb1)
{
     RCC_APB1PeriphClockCmd(apb1, DISABLE);
}
void CPeriphalManager::disableAPB2(uint32_t apb2)
{
    RCC_APB2PeriphClockCmd(apb2, DISABLE);
}

template<>
CLed * CPeriphalManager::getPeripheral<CLed>(SPeripheralConfig& config)
{
    return getPeripheralImpl<CLed>(config,LedPeriphMap);   
}

template<>
CI2C * CPeriphalManager::getPeripheral<CI2C>(SPeripheralConfig& config)
{
    return getPeripheralImpl<CI2C>(config,I2CPeriphMap);   
}

template<>
void CPeriphalManager::delPeripheral<CLed>(CLed* periph)
{
    delPeripheralImpl<CLed,PeripheralTypes<CLed>::TPeriphMap>(periph,LedPeriphMap);
    
}
//TODO change to one argument template like in get...
template<>
void CPeriphalManager::delPeripheral<CI2C>(CI2C* periph)
{
    delPeripheralImpl<CI2C,PeripheralTypes<CI2C>::TPeriphMap>(periph,I2CPeriphMap);
    
}
