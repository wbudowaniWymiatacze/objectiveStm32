/*
 * TypePeriph.hpp
 *
 *  Created on: Feb 4, 2012
 *      Author: artur
 */

#ifndef TYPEPERIPH_HPP_
#define TYPEPERIPH_HPP_

#include <boardDefs.hpp>

// USART1
typedef struct
{
	static const int tx						= USART1_TX_PIN;
	static const int rx						= USART1_RX_PIN;
	static const int port					= USART1_PORT;
	static const int remap					= 0;
	USART_TypeDef * id;
	static const uint32_t apb1				= USART1_APB1;
	static const uint32_t apb2				= USART1_APB2;
} SUsart1;

// USART1 remapped
typedef struct
{
	static const int tx						= USART1_TX_PIN_REMAP;
	static const int rx						= USART1_RX_PIN_REMAP;
	static const int port					= USART1_PORT_REMAP;
	static const int remap					= GPIO_Remap_USART1;
	USART_TypeDef * id;
	static const uint32_t apb1				= USART1_REMAP_APB1;
	static const uint32_t apb2				= USART1_REMAP_APB2;
} SUsart2;

// USART2
typedef struct
{
	static const int tx						= USART2_TX_PIN;
	static const int rx						= USART2_RX_PIN;
	static const int port					= USART2_PORT;
	static const int remap					= 0;
	USART_TypeDef * id;
	static const uint32_t apb1				= USART2_APB1;
	static const uint32_t apb2				= USART2_APB2;
} SUsart3;

// USART2 remapped
typedef struct
{
	static const int tx						= USART2_TX_PIN_REMAP;
	static const int rx						= USART2_RX_PIN_REMAP;
	static const int port					= USART2_PORT_REMAP;
	static const int remap					= GPIO_Remap_USART2;
	USART_TypeDef * id;
	static const uint32_t apb1				= USART2_REMAP_APB1;
	static const uint32_t apb2				= USART2_REMAP_APB2;
} SUsart4;

// USART3
typedef struct
{
	static const int tx						= USART3_TX_PIN;
	static const int rx						= USART3_RX_PIN;
	static const int port					= USART3_PORT;
	static const int remap					= 0;
	USART_TypeDef * id;
	static const uint32_t apb1				= USART3_APB1;
	static const uint32_t apb2				= USART3_APB2;
} SUsart5;

// USART3 partially remapped
typedef struct
{
	static const int tx						= USART3_TX_PIN_PART_REMAP;
	static const int rx						= USART3_RX_PIN_PART_REMAP;
	static const int port					= USART3_PORT_PART_REMAP;
	static const int remap					= GPIO_PartialRemap_USART3;
	USART_TypeDef * id;
	static const uint32_t apb1				= USART3_PART__REMAP_APB1;
	static const uint32_t apb2				= USART3_PART__REMAP_APB2;
} SUsart6;

// USART3 fully remapped
typedef struct
{
	static const int tx						= USART3_TX_PIN_FULL_REMAP;
	static const int rx						= USART3_RX_PIN_FULL_REMAP;
	static const int port					= USART3_PORT_FULL_REMAP;
	static const int remap					= GPIO_FullRemap_USART3;
	USART_TypeDef * id;
	static const uint32_t apb1				= USART3_FULL__REMAP_APB1;
	static const uint32_t apb2				= USART3_FULL__REMAP_APB2;
} SUsart7;
#endif /* TYPEPERIPH_HPP_ */
