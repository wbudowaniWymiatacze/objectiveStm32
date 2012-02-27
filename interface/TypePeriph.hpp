/*
 * TypePeriph.hpp
 *
 *  Created on: Feb 4, 2012
 *      Author: artur
 */

#ifndef TYPEPERIPH_HPP_
#define TYPEPERIPH_HPP_

#include <boardDefs.hpp>

enum EUsart {
	EUsart1,
	EUsart2,
	EUsart3
};

typedef EUsart EUsart;

typedef struct
{
	static const int tx  = USART1_TX_PIN;
	static const int rx  = USART1_RX_PIN;
	static const int port= USART1_PORT;
} SUsart1;

typedef struct
{
	static const int tx  = USART2_TX_PIN;
	static const int rx  = USART2_RX_PIN;
	static const int port= USART2_PORT;
} SUsart2;

#endif /* TYPEPERIPH_HPP_ */
