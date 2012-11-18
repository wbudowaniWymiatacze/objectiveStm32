/* 
 * File:   InterruptsHandler.hpp
 * Author: reymondo
 *
 * Created on 10 listopad 2012, 16:41
 */

#ifndef INTERRUPTSHANDLER_HPP
#define	INTERRUPTSHANDLER_HPP

#include <boardDefs.hpp>
#include <InterruptHandler.hpp>
#include <PeripheralTypes.hpp>
#include <map>

#include "InterruptTypes.hpp"

class IsrDispatcher {
public:
    typedef std::map<IRQn_Type,InterruptHandler*> TMapHandlers;
    typedef std::map<IRQn_Type,uint32_t>          TMapExtLines;
    
    IsrDispatcher(uint32_t NVIC_PriorityGroup = NVIC_PriorityGroup_1);
    IsrDispatcher(const IsrDispatcher& orig);
    virtual ~IsrDispatcher();
    
    static void runInterrupt(IRQn_Type i);
    static void registerInterrupt(IRQn_Type idx, InterruptHandler& hand);

    void enableInterruptExt(TInterruptConfigExt& config);
    void enableInterruptSysTick(float ms);
    

private:
    static TMapHandlers vectorMap;
    static TMapExtLines extLinesMap;
    uint32_t SysTickFreq; //Hz
    uint32_t SysTick_CLKSource;
};



#endif	/* INTERRUPTSHANDLER_HPP */

