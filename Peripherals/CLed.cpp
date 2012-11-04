/* 
 * File:   CLed.cpp
 * Author: reymondo
 * 
 * Created on 15 czerwiec 2012, 22:10
 */

#include "CLed.hpp"

CLed::CLed(CGpioManager* GM,SPeripheralConfig& config ):
IPeripheral(GM){
        
    TPeripheralConfig&  A = static_cast<TPeripheralConfigLed&>(config);
    
    pin = GM->getGpio<CGpioOutput>(A.gpioPort,A.gpioPin);
    
}

CLed::~CLed() 
{
}


void CLed::init() 
{
    pin->init();
}

void CLed::deinit() 
{
}

void CLed::on()
{
    pin->set(true);
}

void CLed::off()
{
    pin->set(false);
}

void CLed::toogle()
{
    pin->toogle();
}
