/* 
 * File:   InterruptTypes.hpp
 * Author: reymondo
 *
 * Created on 12 listopad 2012, 19:37
 */

#ifndef INTERRUPTTYPES_HPP
#define	INTERRUPTTYPES_HPP

#include <stm32f10x_exti.h>

typedef struct TInterruptConfig
{
   uint8_t   preemptionPriority;
   uint8_t   subpriority;
   IRQn_Type channel;
   
    
}TInterruptConfig;

typedef struct TInterruptConfigExt : public TInterruptConfig
{
    uint32_t            line;       //@ref EXTI_Lines (EXTI_Linex)
    EXTITrigger_TypeDef trigger;    //@ref EXTIMode_TypeDef
    uint8_t             portSource; //@ref GPIO_Port_Sources (GPIO_PortSourceGPIOx)
    uint8_t             pinSource;  //@ref GPIO_Pin_Sources  (GPIO_PinSourcex)
    
}TInterruptConfigExt;

#endif	/* INTERRUPTTYPES_HPP */

