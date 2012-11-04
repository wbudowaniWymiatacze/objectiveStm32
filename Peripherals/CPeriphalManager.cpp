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
    CPeriphalManager a=orig;
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

template<>
CLed * CPeriphalManager::getPeripheral<CLed>(SPeripheralConfig& config)
{
    return getPeripheralImpl<CLed,PeripheralTypes<CLed>::TPeriphMap>((config),LedPeriphMap);
    
}
