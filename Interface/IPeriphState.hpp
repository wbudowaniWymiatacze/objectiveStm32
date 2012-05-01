/*
 * IPeriphState.hpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#ifndef IPERIPHSTATE_HPP_
#define IPERIPHSTATE_HPP_

#include <boardDefs.hpp>
#include <EPeripheralState.hpp>

class IPeriphState {
public:
    IPeriphState() {}
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
    virtual IPeriphState * nextState( bool    switchToNextState ) = 0;
    virtual IPeriphState * deinit( USART_TypeDef *    id,
                                     uint32_t           apb1,
                                     uint32_t           apb2 ) = 0;
    virtual EPeripheralState getState() = 0;
    virtual ~IPeriphState() {}
};

#endif /* IPERIPHSTATE_HPP_ */
