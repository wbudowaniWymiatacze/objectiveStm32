/* 
 * File:   InterruptsHandler.cpp
 * Author: reymondo
 * 
 * Created on 10 listopad 2012, 16:41
 */

#include "IsrDispatcher.hpp"
#include "Peripherals/CLed.hpp"

IsrDispatcher::TMapHandlers IsrDispatcher::vectorMap;
IsrDispatcher::TMapExtLines IsrDispatcher::extLinesMap;

IsrDispatcher::IsrDispatcher(uint32_t NVIC_PriorityGroup) {
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup);
    
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
    SysTickFreq = 72000000/8;
}

IsrDispatcher::~IsrDispatcher() {
}

void IsrDispatcher::runInterrupt(IRQn_Type i)
{
    TMapHandlers::iterator iter = vectorMap.find(i);
    if(iter != vectorMap.end())
        vectorMap[i]->handle();
    
    TMapExtLines::iterator iterExt = extLinesMap.find(i);
    if(iterExt != extLinesMap.end())
        EXTI_ClearITPendingBit(extLinesMap[i]);
}

void IsrDispatcher::registerInterrupt(IRQn_Type i,InterruptHandler& hand)
{
    vectorMap[i]= &hand;
}

void IsrDispatcher::enableInterruptExt(TInterruptConfigExt& conf)
{
    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_InitStruct.NVIC_IRQChannel                   = conf.channel;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = conf.preemptionPriority;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority        = conf.subpriority;
    NVIC_InitStruct.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStruct);

    GPIO_EXTILineConfig(conf.portSource,conf.pinSource);
    
    EXTI_InitTypeDef EXTI_InitStruct;
    EXTI_InitStruct.EXTI_Line    = conf.line;
    EXTI_InitStruct.EXTI_Mode    = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = conf.trigger;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStruct);
    
    extLinesMap[conf.channel] = conf.line;

}

void IsrDispatcher::enableInterruptSysTick(uint32_t ms)
{
    // SysTickFreq*(us/1000) should be fit on 24 bits!!
    SysTick_Config(SysTickFreq*(ms/1000));
}

extern "C" {

void SysTick_Handler()
{ 
    IsrDispatcher::runInterrupt(SysTick_IRQn);
   
}

void EXTI15_10_IRQHandler()
{
    IsrDispatcher::runInterrupt(EXTI15_10_IRQn);
}



} //extern"C"



