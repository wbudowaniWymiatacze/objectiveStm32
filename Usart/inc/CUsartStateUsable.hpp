/*
 * CUsartStateUsable.hpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#ifndef CUSARTSTATEUSABLE_HPP_
#define CUSARTSTATEUSABLE_HPP_

#include <boardDefs.hpp>

#include <CGpioManager.hpp>
#include <CRccManager.hpp>
#include <IPeripheral.hpp>
#include <IPeriphState.hpp>
#include <CUsartStateRunning.hpp>
#include <EPeripheralState.hpp>

class CUsartStateUsable : public IPeriphState {
public:

    CUsartStateUsable( CGpioManager *   gpioManager,
                         CRccManager *    rccManager ) :
    m_gpioManager( gpioManager ), m_rccManager( rccManager ) {}

    void remap( uint32_t    remapValue );

    void apbEnable( uint32_t    apb1Value,
                    uint32_t    apb2Value );

    /*
     * initialise needed GPIO
     */

    // TODO: zmienić na wywołanie z nr portu i pinu
    void gpioInit( uint8_t              port,
                   uint8_t              pin,
                   GPIO_InitTypeDef &   gpioConfig );

    /*
     * initialise USART
     */
    void init( USART_TypeDef *      usartId,
                USART_InitTypeDef &  periphConfig );

    /*
     * read does nothing in this state
     */
    void read( USART_TypeDef *  usartId,
               uint16_t *       data,
               uint8_t          nData )
    {

    }

    /*
     * read does nothing in this state
     */
    void write( USART_TypeDef * usartId,
                uint16_t *      data,
                uint8_t         nData )
    {

    }

    /*
     * configure interrupts with the given configuration
     */
    void interruptsConfig( NVIC_InitTypeDef & interruptsConfig );

    /*
     * depending on the argument returns pointer to the
     * new state or to the current state (in case
     * switchToNextState == false or allocating new state
     * was unsuccessful)
     */
    IPeriphState * nextState( bool  switchToNextState );

    IPeriphState * deinit( USART_TypeDef *    id,
                            uint32_t           apb1,
                            uint32_t           apb2 );

    EPeripheralState getState();

    ~CUsartStateUsable() {}
private:
    CGpioManager *      m_gpioManager;
    CRccManager *       m_rccManager;
    EPeripheralState    m_stateInfo;
};

#endif /* CUSARTSTATEUSABLE_HPP_ */
