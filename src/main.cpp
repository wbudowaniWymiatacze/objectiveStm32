/*
 * main.cpp
 *
 *  Created on: Jan 21, 2012
 *      Author: artur
 */
#include <boardDefs.hpp>

#include <CUsart.hpp>
#include <TypePeriph.hpp>

int main()
{
	USART_InitTypeDef usartConf;
	CUsart< SUsart1 > usart1;

	usartConf.USART_BaudRate = 115200;
	usartConf.USART_WordLength = USART_WordLength_8b;
	usartConf.USART_StopBits = USART_StopBits_1;
	usartConf.USART_Parity = USART_Parity_No;
	usartConf.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	usartConf.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	usart1.init( GPIO_Speed_50MHz,
				 GPIO_Mode_IN_FLOATING,
				 GPIO_Speed_50MHz,
				 GPIO_Mode_AF_PP,
				 usartConf );

	return 0;
}


