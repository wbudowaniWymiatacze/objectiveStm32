/*
 * CUsartState.hpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#ifndef CUSARTSTATE_HPP_
#define CUSARTSTATE_HPP_

#include <boardDefs.hpp>
#include <EPeripheralState.hpp>

class CUsartState {
public:
    CUsartState() {}
    virtual void remap( uint32_t    remapValue ) = 0;
    virtual void apbEnable( uint32_t    apb1Value,
                            uint32_t    apb2Value ) = 0;
    virtual void gpioInit( uint8_t              port,
                           uint8_t              pin,
                           GPIO_InitTypeDef &   gpioConfig ) = 0;
    virtual void init( USART_TypeDef *      usartId,
                       USART_InitTypeDef &  periphConfig ) = 0;
    virtual void read( USART_TypeDef *  usartId,
                       uint16_t *       data,
                       uint8_t          nData ) = 0;
    virtual void write( USART_TypeDef * usartId,
                        uint16_t *      data,
                        uint8_t         nData ) = 0;
    virtual void interruptsConfig( NVIC_InitTypeDef & interruptsConfig ) = 0;
    virtual void nextState( CUsartState *   currentState,
                            bool            switchToNextState ) = 0;
    virtual void deinit( USART_TypeDef *    id,
                         uint32_t           apb1,
                         uint32_t           apb2,
                         CUsartState *      usartState ) = 0;
    virtual EPeripheralState getState() = 0;
    virtual ~CUsartState() {}
};

#endif /* CUSARTSTATE_HPP_ */
