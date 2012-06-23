/*
 * CUsartStateUnusable.hpp
 *
 *  Created on: Feb 12, 2012
 *      Author: artur
 */

#ifndef CUSARTSTATEUNUSABLE_HPP_
#define CUSARTSTATEUNUSABLE_HPP_

#include <boardDefs.hpp>

#include <CGpioManager.hpp>
#include <CRccManager.hpp>
#include <IPeriphState.hpp>
#include <EPeripheralState.hpp>

/*
 * except nextState none of the functions does anything
 */
class CUsartStateUnusable : public IPeriphState {
public:

    CUsartStateUnusable( CGpioManager * gpioManager,
                         CRccManager *  rccManager ) :
    m_gpioManager( gpioManager ), m_rccManager( rccManager ), m_stateInfo( EPeripheralStateUnusable ) {}

    void remap( uint32_t    remapValue )
    {
        ( void ) remapValue;
    }

    void apbEnable( uint32_t    apb1Value,
                    uint32_t    apb2Value )
    {
        ( void ) apb1Value;
        ( void ) apb2Value;
    }

    /*
     * gpio initialisation is not allowed in this state,
     * so the function does nothing
     */
    void gpioInit( uint8_t              port,
                   uint16_t              pin,
                   GPIO_InitTypeDef &   gpioConfig )
    {
        ( void ) port;
        ( void ) pin;
        ( void ) gpioConfig;
    }

    /*
     * initialisation of USART is not allowed in this state
     * so the function does nothing
     */
    void init( USART_TypeDef *      usartId,
               USART_InitTypeDef &  periphConfig )
    {
        ( void ) usartId;
        ( void ) periphConfig;
    }

    /*
     * read does nothing in this state
     */
    void read( USART_TypeDef *  usartId,
               uint16_t *       data,
               uint8_t          nData )
    {
        ( void ) usartId;
        ( void ) data;
        ( void ) nData;
    }

    /*
     * read does nothing in this state
     */
    void write( USART_TypeDef * usartId,
                uint16_t *      data,
                uint8_t         nData )
    {
        ( void ) usartId;
        ( void ) data;
        ( void ) nData;
    }

    /*
     * interrupts cannot be configured in this state
     */
    void interruptsConfig( NVIC_InitTypeDef & interruptsConfig )
    {
        ( void ) interruptsConfig;
    }

    /*
     * depending on the argument returns pointer to the
     * new state or to the current state (in case
     * switchToNextState == false or allocating new state
     * was unsuccessful)
     */
    IPeriphState * nextState( bool  switchToNextState );

    IPeriphState * deinit( USART_TypeDef *    id,
                           uint32_t           apb1,
                           uint32_t           apb2 )
    {
        ( void ) id;
        ( void ) apb1;
        ( void ) apb2;
        return this;
    }

    EPeripheralState getState();

    ~CUsartStateUnusable() {}

private:
    CGpioManager *      m_gpioManager;
    CRccManager *       m_rccManager;
    EPeripheralState    m_stateInfo;
};


#endif /* CUSARTSTATEUNUSABLE_HPP_ */
