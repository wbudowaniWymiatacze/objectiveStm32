/* 
 * File:   InterruptsHandler.hpp
 * Author: reymondo
 *
 * Created on 10 listopad 2012, 16:41
 */

#ifndef INTERRUPTSHANDLER_HPP
#define	INTERRUPTSHANDLER_HPP

#include <stm32f10x.h>
#include <InterruptHandler.hpp>
#include <PeripheralTypes.hpp>
#include <map>

class InterruptsHandler {
public:
    typedef std::map<IRQn_Type,InterruptHandler*> TvectorMap;
    
    InterruptsHandler();
    InterruptsHandler(const InterruptsHandler& orig);
    virtual ~InterruptsHandler();
    
    static void runInterrupt(IRQn_Type i);
    static void registerInterrupt(IRQn_Type idx, InterruptHandler& hand);


    static TvectorMap vectorMap;

};

//extern "C" void SysTick_Handler();



#endif	/* INTERRUPTSHANDLER_HPP */

