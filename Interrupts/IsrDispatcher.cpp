/* 
 * File:   InterruptsHandler.cpp
 * Author: reymondo
 * 
 * Created on 10 listopad 2012, 16:41
 */

#include "IsrDispatcher.hpp"
#include "Peripherals/CLed.hpp"

IsrDispatcher::TvectorMap IsrDispatcher::vectorMap;

IsrDispatcher::IsrDispatcher() {
}

IsrDispatcher::IsrDispatcher(const IsrDispatcher& orig) {
}

IsrDispatcher::~IsrDispatcher() {
}

void IsrDispatcher::runInterrupt(IRQn_Type i)
{
    TvectorMap::iterator iter = vectorMap.find(i);
    if(iter != vectorMap.end())
        vectorMap[i]->handle();

}

void IsrDispatcher::registerInterrupt(IRQn_Type i,InterruptHandler& hand)
{
    vectorMap[i]= &hand;

}

extern "C" {

void SysTick_Handler()
{ 
    IsrDispatcher::runInterrupt(SysTick_IRQn);
   
}



} //extern"C"



