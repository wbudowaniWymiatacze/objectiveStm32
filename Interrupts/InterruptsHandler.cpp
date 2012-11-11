/* 
 * File:   InterruptsHandler.cpp
 * Author: reymondo
 * 
 * Created on 10 listopad 2012, 16:41
 */

#include "InterruptsHandler.hpp"
#include "Peripherals/CLed.hpp"

InterruptsHandler::InterruptsHandler() {
}

InterruptsHandler::InterruptsHandler(const InterruptsHandler& orig) {
}

InterruptsHandler::~InterruptsHandler() {
}

void InterruptsHandler::runInterrupt(IRQn_Type i)
{
    //vectorMap[i]->handle();

}

void InterruptsHandler::registerInterrupt(IRQn_Type i,InterruptHandler& hand)
{
    vectorMap[i]= &hand;

}

#if defined(__cplusplus)
extern "C" {
#endif
void SysTick_Handler()
{ 
    extern CLed* GlobalLed; 
    GlobalLed->toogle();
    
    InterruptsHandler::runInterrupt(SysTick_IRQn);
    
}
#if defined(__cplusplus)
}
#endif


