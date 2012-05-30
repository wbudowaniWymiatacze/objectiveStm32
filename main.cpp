/*
 * main.cpp
 *
 *  Created on: Jan 21, 2012
 *      Author: artur
 */
#include <boardDefs.hpp>

#include <CGpioManager.hpp>
#include <CRccManager.hpp>
#include <CUsart.hpp>
#include <TypePeriph.hpp>

uint16_t g_usartReadBuffer[ 100 ];
uint16_t g_usartWriteBuffer[ 100 ];

int main()
{
    SystemInit();
	CGpioManager gpioMngr;
	CRccManager rccMngr;
	SUsartConfig usartConfStruct;
	USART_InitTypeDef & usartConf = usartConfStruct.usartConfig;
	CUsart< SUsart5 > usart1( gpioMngr, rccMngr );

	usartConf.USART_BaudRate = 115200;
	usartConf.USART_WordLength = USART_WordLength_8b;
	usartConf.USART_StopBits = USART_StopBits_1;
	usartConf.USART_Parity = USART_Parity_No;
	usartConf.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	usartConf.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	GPIO_InitTypeDef gpiosConfig[ 2 ];

        //@todo TODO
        // mode dla USART Rx i Tx są określone - wywalić konieczność ustawiania GPIO_Mode,
	// speed jako argument CUsart::init z wartością domyślną
	gpiosConfig[ 0 ].GPIO_Pin = 0;                      // TODO: GPIO_Pin i tak jest później ignorowany - usunąć
	gpiosConfig[ 0 ].GPIO_Speed = GPIO_Speed_50MHz;
	gpiosConfig[ 0 ].GPIO_Mode = GPIO_Mode_IN_FLOATING;

	gpiosConfig[ 1 ].GPIO_Pin = 0;                      // TODO: GPIO_Pin i tak jest później ignorowany - usunąć
	gpiosConfig[ 1 ].GPIO_Speed = GPIO_Speed_50MHz;
	gpiosConfig[ 1 ].GPIO_Mode = GPIO_Mode_AF_PP;

	usart1.init( gpiosConfig, &usartConfStruct );

	char buffer[] = { 'a', 'b', 'c', 'd' };
	usart1.write( ( uint16_t * ) buffer, 4 );

	return 0;

//    GPIO_InitTypeDef GPIO_InitStructure;
//    USART_ClockInitTypeDef USART_ClockInitStructure;
//    USART_InitTypeDef USART_InitStructure;
//
//    GPIO_TypeDef * portsArr[] = { GPIOA, GPIOB, GPIOC, GPIOD };
//
//    USART_TypeDef * usart = USART3;
//    uint16_t txPin = USART3_TX_PIN_FULL_REMAP; // USART1_TX_PIN_REMAP
//    GPIO_TypeDef * port = portsArr[ USART3_PORT_FULL_REMAP ]; //USART1_PORT_REMAP
//    int remap = txPin != USART1_TX_PIN && txPin != USART2_TX_PIN && txPin != USART3_TX_PIN;
//    GPIOMode_TypeDef gpioMode = GPIO_Mode_Out_PP;
//    uint32_t remapConfig = GPIO_FullRemap_USART3;
//
//    RCC_APB1PeriphClockCmd( USART3_FULL_REMAP_APB1, ENABLE); //USART1_REMAP_APB1
//    RCC_APB2PeriphClockCmd( USART3_FULL_REMAP_APB2, ENABLE);
//
//    if ( remap != 0 )
//    {
//        gpioMode = GPIO_Mode_AF_PP;
//    }
//
//    GPIO_InitStructure.GPIO_Pin = txPin;
//    GPIO_InitStructure.GPIO_Mode = gpioMode;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_Init( port, &GPIO_InitStructure );
//
//    USART_ClockStructInit( &USART_ClockInitStructure );
//    USART_ClockInit( usart, &USART_ClockInitStructure );
//
//    USART_InitStructure.USART_BaudRate = 115200;
//    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
//    USART_InitStructure.USART_StopBits = USART_StopBits_1;
//    USART_InitStructure.USART_Parity = USART_Parity_No;
//    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//    USART_InitStructure.USART_Mode = USART_Mode_Tx;
//
//    if ( remap != 0 )
//    {
//        GPIO_PinRemapConfig( remapConfig, ENABLE );
//    }
//
//    //Write USART parameters
//    USART_Init( usart, &USART_InitStructure);
//
//    //Enable USART
//    USART_Cmd( usart, ENABLE );
//    //hmmm
//    while( USART_GetFlagStatus( usart, USART_FLAG_TC ) == RESET )
//        ;
//
//    char a = 'a';
//    for( int i = 0; i< 10; i++ )
//    {
//        while( USART_GetFlagStatus( usart, USART_FLAG_TC ) == RESET)
//            ;
//        USART_SendData( usart, (uint16_t) a );
//    }

}


