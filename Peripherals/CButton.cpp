/* 
 * File:   CButton.cpp
 * Author: reymondo
 * 
 * Created on 15 czerwiec 2012, 22:10
 */

#include "CButton.hpp"

CButton::CButton(CGpioManager* GM,SPeripheralConfig& config ):
IPeripheral(GM){
        
    TPeripheralConfig&  A = static_cast<TPeripheralConfigLed&>(config);
    
    pin = GM->getGpio<CGpioInput>(A.gpioPort,A.gpioPin);
    
}

CButton::~CButton() 
{
    GM->releaseGpio(pin);
    pin = NULL;
}


void CButton::init() 
{
    pin->init();
}

void CButton::deinit() 
{

}

bool CButton::isPressed()
{
    return pin->get();
}
