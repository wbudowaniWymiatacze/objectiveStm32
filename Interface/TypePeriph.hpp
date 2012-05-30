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
    static const uint8_t tx         = USART1_TX_PIN;
    static const uint8_t rx         = USART1_RX_PIN;
    static const uint8_t port       = USART1_PORT;
    static const uint32_t remap     = 0;
    USART_TypeDef * id;
    static const uint32_t apb1      = USART1_APB1;
    static const uint32_t apb2      = USART1_APB2;
    static const uint8_t irqChannel = USART1_IRQn;
} SUsart1;

// USART1 remapped
typedef struct
{
    static const uint8_t tx         = USART1_TX_PIN_REMAP;
    static const uint8_t rx         = USART1_RX_PIN_REMAP;
    static const uint8_t port       = USART1_PORT_REMAP;
    static const uint32_t remap     = GPIO_Remap_USART1;
    USART_TypeDef * id;
    static const uint32_t apb1      = USART1_REMAP_APB1;
    static const uint32_t apb2      = USART1_REMAP_APB2;
    static const uint8_t irqChannel = USART1_IRQn;
} SUsart2;

// USART2
typedef struct
{
    static const uint8_t tx         = USART2_TX_PIN;
    static const uint8_t rx         = USART2_RX_PIN;
    static const uint8_t port       = USART2_PORT;
    static const uint32_t remap     = 0;
    USART_TypeDef * id;
    static const uint32_t apb1      = USART2_APB1;
    static const uint32_t apb2      = USART2_APB2;
    static const uint8_t irqChannel = USART2_IRQn;
} SUsart3;

// USART2 remapped
typedef struct
{
    static const uint8_t tx         = USART2_TX_PIN_REMAP;
    static const uint8_t rx         = USART2_RX_PIN_REMAP;
    static const uint8_t port       = USART2_PORT_REMAP;
    static const uint32_t remap     = GPIO_Remap_USART2;
    USART_TypeDef * id;
    static const uint32_t apb1      = USART2_REMAP_APB1;
    static const uint32_t apb2      = USART2_REMAP_APB2;
    static const uint8_t irqChannel = USART2_IRQn;
} SUsart4;

// USART3
typedef struct
{
    static const uint8_t tx         = USART3_TX_PIN;
    static const uint8_t rx         = USART3_RX_PIN;
    static const uint8_t port       = USART3_PORT;
    static const uint32_t remap     = 0;
    USART_TypeDef * id;
    static const uint32_t apb1      = USART3_APB1;
    static const uint32_t apb2      = USART3_APB2;
    static const uint8_t irqChannel = USART3_IRQn;
} SUsart5;

// USART3 partially remapped
typedef struct
{
    static const uint8_t tx         = USART3_TX_PIN_PART_REMAP;
    static const uint8_t rx         = USART3_RX_PIN_PART_REMAP;
    static const uint8_t port       = USART3_PORT_PART_REMAP;
    static const uint32_t remap     = GPIO_PartialRemap_USART3;
    USART_TypeDef * id;
    static const uint32_t apb1      = USART3_PART_REMAP_APB1;
    static const uint32_t apb2      = USART3_PART_REMAP_APB2;
    static const uint8_t irqChannel = USART3_IRQn;
} SUsart6;

// USART3 fully remapped
typedef struct
{
    static const uint8_t tx         = USART3_TX_PIN_FULL_REMAP;
    static const uint8_t rx         = USART3_RX_PIN_FULL_REMAP;
    static const uint8_t port       = USART3_PORT_FULL_REMAP;
    static const uint32_t remap     = GPIO_FullRemap_USART3;
    USART_TypeDef * id;
    static const uint32_t apb1      = USART3_FULL_REMAP_APB1;
    static const uint32_t apb2      = USART3_FULL_REMAP_APB2;
    static const uint8_t irqChannel = USART3_IRQn;
} SUsart7;
#endif /* TYPEPERIPH_HPP_ */
