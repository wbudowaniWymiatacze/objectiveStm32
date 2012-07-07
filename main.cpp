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
#include <UsartParams.hpp>

#include <stdio.h>
#include <string.h>

int main()
{
    SystemInit();

    CGpioManager gpioMngr;
    CRccManager rccMngr;
    SUsartConfig usartConfStruct;
    USART_InitTypeDef & usartConf = usartConfStruct.usartConfig;
    CUsart usart1( gpioMngr, rccMngr, CUsartParams< 0 >::m_usartParams );

    usartConf.USART_BaudRate = 115200;
    usartConf.USART_WordLength = USART_WordLength_8b;
    usartConf.USART_StopBits = USART_StopBits_1;
    usartConf.USART_Parity = USART_Parity_No;
    usartConf.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    usartConf.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

    GPIO_InitTypeDef gpiosConfig[ 2 ];

    gpiosConfig[ 0 ].GPIO_Pin = 0;                      // TODO: GPIO_Pin i tak jest później ignorowany - usunąć
    gpiosConfig[ 0 ].GPIO_Speed = GPIO_Speed_50MHz;
    gpiosConfig[ 0 ].GPIO_Mode = GPIO_Mode_IN_FLOATING;

    gpiosConfig[ 1 ].GPIO_Pin = 0;                      // TODO: GPIO_Pin i tak jest później ignorowany - usunąć
    gpiosConfig[ 1 ].GPIO_Speed = GPIO_Speed_50MHz;
    gpiosConfig[ 1 ].GPIO_Mode = GPIO_Mode_AF_PP;

    usart1.init( gpiosConfig, &usartConfStruct );
    
    char buffer[] = { "artur" };
    uint16_t buffer16[ strlen( buffer ) ];
    // convert to format proper for CUsart::write()
    for( int idx=0; idx< ( int ) strlen( buffer ); idx++)
    {
        buffer16[ idx ] = ( uint16_t ) buffer[ idx ];
    }
    usart1.write( buffer16, 5 );

    while(1)
    {
        for (int i=0;i< ( int ) 7000000;i++);
        usart1.write( ( uint16_t * ) "A", 1 );
        usart1.write( ( uint16_t * ) "r", 1 );
        usart1.write( ( uint16_t * ) "m", 1 );
        usart1.write( ( uint16_t * ) "\r", 1 );
        usart1.write( ( uint16_t * ) "\n", 1 );
    }
    
    return 0;

}


