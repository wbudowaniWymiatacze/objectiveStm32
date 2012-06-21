/*
 * CUsartStateRunning.hpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#ifndef CUSARTSTATERUNNING_HPP_
#define CUSARTSTATERUNNING_HPP_

#include <boardDefs.hpp>

#include <CGpioManager.hpp>
#include <CRccManager.hpp>
#include <IPeripheral.hpp>
#include <IPeriphState.hpp>
#include <EPeripheralState.hpp>

class CUsartStateRunning: public IPeriphState {
public:

    CUsartStateRunning( CGpioManager *  gpioManager,
                        CRccManager *   rccManager ) :
    m_gpioManager( gpioManager ), m_rccManager( rccManager ), m_stateInfo( EPeripheralStateUnusable ) {}

    /*
     * remapping is not allowed in this state,
     * so the function does nothing
     */
    void remap( uint32_t    remapValue )
    {

    }

    /*
     * enabling APB is not allowed in this state,
     * so the function does nothing
     */
    void apbEnable( uint32_t    apb1Value,
                    uint32_t    apb2Value )
    {

    }

    /*
     * gpio initialisation is not allowed in this state,
     * so the function does nothing
     */
    void gpioInit( uint8_t              port,
                   uint16_t              pin,
                   GPIO_InitTypeDef &   gpioConfig )
    {

    }

    /*
     * initialisation of USART is not allowed in this state
     * so the function does nothing
     */
    void init( USART_TypeDef *      usartId,
               USART_InitTypeDef &  periphConfig )
    {

    }

    /*
     * read data from USART input data buffer to the defined buffer
     */
    void read( USART_TypeDef *  usartId,
               uint16_t *       data,
               uint8_t          nData );

    /*
     * write data to USART
     */
    void write( USART_TypeDef * usartId,
                uint16_t *      data,
                uint8_t         nData );

    /*
     * configure interrupts with the given configuration
     */
    void interruptsConfig( NVIC_InitTypeDef &   interruptsConfig );

    /*
     * cannot switch to the next state when in state Running
     */
    IPeriphState * nextState( bool  switchToNextState )
    {
        ( void ) switchToNextState;
        return this;
    }

    IPeriphState * deinit( USART_TypeDef *    id,
                           uint32_t           apb1,
                           uint32_t           apb2 );

    EPeripheralState getState();

    ~CUsartStateRunning() {}
private:
    CGpioManager *      m_gpioManager;
    CRccManager *       m_rccManager;
    EPeripheralState    m_stateInfo;
};

#endif /* CUSARTSTATERUNNING_HPP_ */
