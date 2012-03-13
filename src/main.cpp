/*
 * main.cpp
 *
 *  Created on: Jan 21, 2012
 *      Author: artur
 */
#include <boardDefs.hpp>

#include <CManagersFactory.hpp>
#include <CGpioManager.hpp>
#include <CRccManager.hpp>
#include <CUsart.hpp>
#include <TypePeriph.hpp>

int main()
{
	CGpioManager gpioMngr;
	CRccManager rccMngr;
	SUsartConfig usartConfStruct;
	USART_InitTypeDef usartConf = usartConfStruct.usartConfig;
	CUsart< SUsart1 > usart1( gpioMngr,
							  rccMngr );

	usartConf.USART_BaudRate = 115200;
	usartConf.USART_WordLength = USART_WordLength_8b;
	usartConf.USART_StopBits = USART_StopBits_1;
	usartConf.USART_Parity = USART_Parity_No;
	usartConf.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	usartConf.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	GPIO_InitTypeDef gpiosConfig[ 2 ];

	gpiosConfig[ 0 ].GPIO_Pin = 0;
	gpiosConfig[ 0 ].GPIO_Speed = GPIO_Speed_50MHz;
	gpiosConfig[ 0 ].GPIO_Mode = GPIO_Mode_IN_FLOATING;

	gpiosConfig[ 1 ].GPIO_Pin = 0;
	gpiosConfig[ 1 ].GPIO_Speed = GPIO_Speed_50MHz;
	gpiosConfig[ 1 ].GPIO_Mode = GPIO_Mode_AF_PP;

	usart1.init( gpiosConfig,
				 &usartConfStruct );

	return 0;
}


