/*
 * UsartParams.hpp
 *
 *  Created on: Feb 4, 2012
 *      Author: artur
 */

#ifndef USARTPARAMS_HPP
#define USARTPARAMS_HPP

#include <boardDefs.hpp>

/*
 * structure holding all parameters needed by USART
 */
struct SUsartParams
{
    uint16_t tx;
    uint16_t rx;
    uint8_t port;
    uint32_t remap;
    USART_TypeDef * id;
    uint32_t apb1;
    uint32_t apb2;
    uint8_t irqChannel;
};

/*
 * template structure which holds parameters values for given USART
 */
template < uint8_t usartId >
struct CUsartParams
{
    static SUsartParams m_usartParams;
};

#endif /* USARTPARAMS_HPP */
