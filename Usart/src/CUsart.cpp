#include <CUsart.hpp>
#include <CUsartStateUnusable.hpp>

CUsart::CUsart( CGpioManager &  gpioManager,
                 CRccManager &  rccManager,
                 SUsartParams & usartParams) :
m_usartParams( usartParams ), m_rccManager ( rccManager )
{
    // TODO: fix CGpioManager and CRccManager copy constructor and operator=
    m_gpioManager = gpioManager;
    CUsartStateUnusable * initialState = new CUsartStateUnusable( &m_gpioManager,
                                                                  &m_rccManager );
    changeState( initialState );
}

void CUsart::init( GPIO_InitTypeDef *   gpiosConfig,
                   SPeriphConfig *      config )
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

void CUsart::read( uint16_t *   data,
                   uint8_t      nData )
{
    m_usartState->read( m_usartParams.id,
                        data,
                        nData );
}

void CUsart::write( uint16_t *  data,
                    uint8_t     nData )
{
    m_usartState->write( m_usartParams.id,
                         data,
                         nData );
}

void CUsart::configureInterrupts( uint16_t    interruptSource )
{
    USART_ITConfig( m_usartParams.id,
                    interruptSource,
                    ENABLE );
}

void CUsart::deconfigureInterrupts( uint16_t  interruptSource )
{
    USART_ITConfig( m_usartParams.id,
                    interruptSource,
                    DISABLE );
}

void CUsart::interruptsOn( uint8_t      priority,
                           uint8_t      subpriority )
{
    NVIC_InitTypeDef interruptConfig;

    interruptConfig.NVIC_IRQChannel = m_usartParams.irqChannel;
    interruptConfig.NVIC_IRQChannelPreemptionPriority = priority;
    interruptConfig.NVIC_IRQChannelSubPriority = subpriority;
    interruptConfig.NVIC_IRQChannelCmd = ENABLE;

    m_usartState->interruptsConfig( interruptConfig );
}

void CUsart::interruptsOff()
{
    NVIC_InitTypeDef interruptConfig;

    interruptConfig.NVIC_IRQChannel = m_usartParams.irqChannel;
    interruptConfig.NVIC_IRQChannelPreemptionPriority = 15;    // lowest priority
    interruptConfig.NVIC_IRQChannelSubPriority = 0;        // don't know
    interruptConfig.NVIC_IRQChannelCmd = DISABLE;

    m_usartState->interruptsConfig( interruptConfig );
}

bool CUsart::checkInterruptSource( uint16_t   interruptSource )
{
    return USART_GetITStatus( m_usartParams.id, interruptSource ) != RESET;
}

void CUsart::deinit()
{
    changeState( m_usartState->deinit( m_usartParams.id,
                                       m_usartParams.apb1,
                                       m_usartParams.apb2 ) );

    m_gpioManager.releaseGpio( m_usartParams.port,
                               m_usartParams.rx );
    m_gpioManager.releaseGpio( m_usartParams.port,
                               m_usartParams.tx );
}

void CUsart::changeState( IPeriphState *   newState )
{
    m_usartState = newState;
}

EPeripheralState CUsart::getState()
{
    return m_usartState->getState();
}

uint32_t CUsart::getIndex()
{
    return m_index;
}

CUsart::~CUsart()
{
    interruptsOff();
    delete m_usartState;
}
