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
#include <UsartParams.hpp>
#include <EPeripheralState.hpp>

class CUsart : public IPeripheral {
public:
    CUsart( CGpioManager &      gpioManager,
            CRccManager &       rccManager,
            SUsartParams &      usartParams );
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

    SUsartParams    m_usartParams;
    IPeriphState *  m_usartState;
    CGpioManager    m_gpioManager;
    CRccManager     m_rccManager;
    uint32_t        m_index;

};

#endif /* CUSART_HPP_ */
