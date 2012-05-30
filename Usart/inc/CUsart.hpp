/*
 * CUsart.hpp
 *
 *  Created on: Feb 4, 2012
 *      Author: artur
 */

#ifndef CUSART_HPP_
#define CUSART_HPP_

#include <boardDefs.hpp>

#include <IPeripheral.hpp>
#include <SUsartConfig.hpp>
#include <CGpioManager.hpp>
#include <CRccManager.hpp>
#include <IPeriphState.hpp>
#include <CUsartStateUnusable.hpp>
#include <TypePeriph.hpp>
#include <EPeripheralState.hpp>

extern uint16_t g_usartReadBuffer[ 100 ];
extern uint16_t g_usartWriteBuffer[ 100 ];

template < typename usartX >
class CUsart : public IPeripheral {
public:
    CUsart( CGpioManager & gpioManager,
            CRccManager & rccManager );
    void init( GPIO_InitTypeDef *   gpiosConfig,
               SPeriphConfig *      config );
    void read( uint16_t *   data,
               uint8_t      nData );
    void write( uint16_t *  data,
                uint8_t     nData );
    void configureInterrupts( uint16_t  interruptSource );
    void deconfigureInterrupts( uint16_t    interruptSource );
    void interruptsOn( uint8_t  priority,
                       uint8_t  subpriority );
    void interruptsOff();
    bool checkInterruptSource( uint16_t interruptSource );
    void deinit();
    inline void changeState( IPeriphState *   newState );
    EPeripheralState getState();
    uint32_t getIndex();
    ~CUsart();

private:
    void setIds();

    usartX         m_usartParams;
    IPeriphState *  m_usartState;
    CGpioManager    m_gpioManager;
    CRccManager     m_rccManager;
    uint32_t        m_index;

};

template < typename usartX >
CUsart< usartX >::CUsart( CGpioManager &    gpioManager,
                             CRccManager &     rccManager )
{
    setIds();
    m_gpioManager = gpioManager;
    m_rccManager = rccManager;
    CUsartStateUnusable * initialState = new CUsartStateUnusable( &m_gpioManager,
                                                                  &m_rccManager );
    changeState( initialState );
}

template < typename usartX >
void CUsart< usartX >::init( GPIO_InitTypeDef * gpiosConfig,
                                SPeriphConfig *    config )
{
    bool gpiosSet = m_gpioManager.getGpio( m_usartParams.port,
                                           m_usartParams.rx );
    gpiosSet &= m_gpioManager.getGpio( m_usartParams.port,
                                       m_usartParams.tx );

    if ( gpiosSet == false )
    {
        m_gpioManager.releaseGpio( m_usartParams.port,
                                   m_usartParams.rx );
        m_gpioManager.releaseGpio( m_usartParams.port,
                                   m_usartParams.tx );
    }

    changeState( m_usartState->nextState( gpiosSet ) );

    // enable APBs
    m_usartState->apbEnable( m_usartParams.apb1,
                             m_usartParams.apb2 );

    m_usartState->remap( m_usartParams.remap );

    // TODO: zmienić wywołanie inicjalizacji GPIO?
    // initialise GPIOs
    m_usartState->gpioInit( m_usartParams.port,
                            m_usartParams.rx,
                            gpiosConfig[ 0 ] );
    m_usartState->gpioInit( m_usartParams.port,
                            m_usartParams.tx,
                            gpiosConfig[ 1 ] );

    //initialise usart
    SUsartConfig * usartConfStruct = ( SUsartConfig * ) config;
    m_usartState->init( m_usartParams.id,
                        usartConfStruct->usartConfig );

    changeState( m_usartState->nextState( true ) );
}

template < typename usartX >
void CUsart< usartX >::read( uint16_t * data,
                             uint8_t    nData )
{
    m_usartState->read( m_usartParams.id,
                        data,
                        nData );
}

template < typename usartX >
void CUsart< usartX >::write( uint16_t *    data,
                              uint8_t       nData )
{
    m_usartState->write( m_usartParams.id,
                         data,
                         nData );
}

template < typename usartX >
void CUsart< usartX >::configureInterrupts( uint16_t    interruptSource )
{
    USART_ITConfig( m_usartParams.id,
                    interruptSource,
                    ENABLE );
}

template < typename usartX >
void CUsart< usartX >::deconfigureInterrupts( uint16_t  interruptSource )
{
    USART_ITConfig( m_usartParams.id,
                    interruptSource,
                    DISABLE );
}

template < typename usartX >
void CUsart< usartX >::interruptsOn( uint8_t    priority,
                                     uint8_t    subpriority )
{
    NVIC_InitTypeDef interruptConfig;

    interruptConfig.NVIC_IRQChannel = m_usartParams.irqChannel;
    interruptConfig.NVIC_IRQChannelPreemptionPriority = priority;
    interruptConfig.NVIC_IRQChannelSubPriority = subpriority;
    interruptConfig.NVIC_IRQChannelCmd = ENABLE;

    m_usartState->interruptsConfig( interruptConfig );
}

template < typename usartX >
void CUsart< usartX >::interruptsOff()
{
    NVIC_InitTypeDef interruptConfig;

    interruptConfig.NVIC_IRQChannel = m_usartParams.irqChannel;
    interruptConfig.NVIC_IRQChannelPreemptionPriority = 15;    // lowest priority
    interruptConfig.NVIC_IRQChannelSubPriority = 0;        // don't know
    interruptConfig.NVIC_IRQChannelCmd = DISABLE;

    m_usartState->interruptsConfig( interruptConfig );
}

template < typename usartX >
bool CUsart< usartX >::checkInterruptSource( uint16_t   interruptSource )
{
    return USART_GetITStatus( m_usartParams.id, interruptSource ) != RESET;
}

template < typename usartX >
void CUsart< usartX >::deinit()
{
    changeState( m_usartState->deinit( m_usartParams.id,
                                       m_usartParams.apb1,
                                       m_usartParams.apb2 ) );

    m_gpioManager.releaseGpio( m_usartParams.port,
                               m_usartParams.rx );
    m_gpioManager.releaseGpio( m_usartParams.port,
                               m_usartParams.tx );
}

template < typename usartX >
void CUsart< usartX >::changeState( IPeriphState *   newState )
{
    m_usartState = newState;
}

template < typename usartX >
EPeripheralState CUsart< usartX >::getState()
{
    return m_usartState->getState();
}

template < typename usartX >
uint32_t CUsart< usartX >::getIndex()
{
    return m_index;
}

template < typename usartX >
CUsart< usartX >::~CUsart()
{
    interruptsOff();
    delete m_usartState;
}

template < >
void CUsart< SUsart1 >::setIds()
{
    m_usartParams.id    = USART1;
    m_index        = 1;
}

template < >
void CUsart< SUsart2 >::setIds()
{
    m_usartParams.id    = USART1;
    m_index        = 1;
}

template < >
void CUsart< SUsart3 >::setIds()
{
    m_usartParams.id    = USART2;
    m_index        = 2;
}

template < >
void CUsart< SUsart4 >::setIds()
{
    m_usartParams.id     = USART2;
    m_index        = 2;
}

template < >
void CUsart< SUsart5 >::setIds()
{
    m_usartParams.id     = USART3;
    m_index        = 3;
}

template < >
void CUsart< SUsart6 >::setIds()
{
    m_usartParams.id    = USART3;
    m_index        = 3;
}

template < >
void CUsart< SUsart7 >::setIds()
{
    m_usartParams.id    = USART3;
    m_index        = 3;
}

#endif /* CUSART_HPP_ */
