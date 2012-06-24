#include <boardDefs.hpp>

#include <UsartParams.hpp>

template <>
SUsartParams CUsartParams< 0 >::m_usartParams = { USART1_TX_PIN,
                                                  USART1_RX_PIN,
                                                  USART1_PORT,
                                                  0,
                                                  USART1,
                                                  USART1_APB1,
                                                  USART1_APB2,
                                                  USART1_IRQn };
template <>
SUsartParams CUsartParams< 1 >::m_usartParams = { USART1_TX_PIN_REMAP,
                                                  USART1_RX_PIN_REMAP,
                                                  USART1_PORT_REMAP,
                                                  GPIO_Remap_USART1,
                                                  USART1,
                                                  USART1_REMAP_APB1,
                                                  USART1_REMAP_APB2,
                                                  USART1_IRQn };
template <>
SUsartParams CUsartParams< 2 >::m_usartParams = { USART2_TX_PIN,
                                                  USART2_RX_PIN,
                                                  USART2_PORT,
                                                  0,
                                                  USART2,
                                                  USART2_APB1,
                                                  USART2_APB2,
                                                  USART2_IRQn };
template <>
SUsartParams CUsartParams< 3 >::m_usartParams = { USART2_TX_PIN_REMAP,
                                                  USART2_RX_PIN_REMAP,
                                                  USART2_PORT_REMAP,
                                                  GPIO_Remap_USART2,
                                                  USART2,
                                                  USART2_REMAP_APB1,
                                                  USART2_REMAP_APB2,
                                                  USART2_IRQn };
template <>
SUsartParams CUsartParams< 4 >::m_usartParams = { USART3_TX_PIN,
                                                  USART3_RX_PIN,
                                                  USART3_PORT,
                                                  0,
                                                  USART3,
                                                  USART3_APB1,
                                                  USART3_APB2,
                                                  USART3_IRQn };
template <>
SUsartParams CUsartParams< 5 >::m_usartParams = { USART3_TX_PIN_PART_REMAP,
                                                  USART3_RX_PIN_PART_REMAP,
                                                  USART3_PORT_PART_REMAP,
                                                  GPIO_PartialRemap_USART3,
                                                  USART3,
                                                  USART3_PART_REMAP_APB1,
                                                  USART3_PART_REMAP_APB2,
                                                  USART3_IRQn };
template <>
SUsartParams CUsartParams< 6 >::m_usartParams = { USART3_TX_PIN_FULL_REMAP,
                                                  USART3_RX_PIN_FULL_REMAP,
                                                  USART3_PORT_FULL_REMAP,
                                                  GPIO_FullRemap_USART3,
                                                  USART3,
                                                  USART3_FULL_REMAP_APB1,
                                                  USART3_FULL_REMAP_APB2,
                                                  USART3_IRQn };
