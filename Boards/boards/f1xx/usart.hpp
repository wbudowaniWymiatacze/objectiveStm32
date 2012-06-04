/*
 * USART.hpp
 *
 *  Created on: Feb 4, 2012
 *      Author: artur
 */

#ifndef USART_HPP_
#define USART_HPP_

// ST includes
#include <stm32f10x_usart.h>
#include <stm32f10x.h>
#include <stm32f10x_rcc.h>

#define USART_NUMBER_GPIOS					2
#define CR2_CLOCK_CLEAR_Mask				((uint16_t)0xF0FF)  /*!< USART CR2 Clock Mask */

// USART1
#define USART1_PORT							0
#define USART1_RX_PIN						10
#define USART1_TX_PIN						9
#define USART1_APB1							0
#define USART1_APB2							RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1
// USART1 remapped
#define USART1_PORT_REMAP					1
#define USART1_RX_PIN_REMAP					7
#define USART1_TX_PIN_REMAP					6
#define USART1_REMAP_APB1					0
#define USART1_REMAP_APB2					RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOB | RCC_APB2Periph_USART1

// USART2
#define USART2_PORT							0
#define USART2_RX_PIN						3
#define USART2_TX_PIN						2
#define USART2_APB1							RCC_APB1Periph_USART2
#define USART2_APB2							RCC_APB2Periph_GPIOA
// USART2 remapped
#define USART2_PORT_REMAP					3
#define USART2_RX_PIN_REMAP					GPIO_Pin_6
#define USART2_TX_PIN_REMAP					GPIO_Pin_5
#define USART2_REMAP_APB1					RCC_APB1Periph_USART2
#define USART2_REMAP_APB2					RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOD

// USART3
#define USART3_PORT							1
#define USART3_RX_PIN						11
#define USART3_TX_PIN						10
#define USART3_APB1							RCC_APB1Periph_USART3
#define USART3_APB2							RCC_APB2Periph_GPIOB
// USART3 partially remapped
#define USART3_PORT_PART_REMAP				2
#define USART3_RX_PIN_PART_REMAP			11
#define USART3_TX_PIN_PART_REMAP			10
#define USART3_PART_REMAP_APB1				RCC_APB1Periph_USART3
#define USART3_PART_REMAP_APB2				RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOC
// USART3 fully remapped
#define USART3_PORT_FULL_REMAP				3
#define USART3_RX_PIN_FULL_REMAP			9
#define USART3_TX_PIN_FULL_REMAP			8
#define USART3_FULL_REMAP_APB1				RCC_APB1Periph_USART3
#define USART3_FULL_REMAP_APB2				RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOD


#endif /* USART_HPP_ */
