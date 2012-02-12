/*
 * gpioPortAddress.hpp
 *
 *  Created on: Feb 11, 2012
 *      Author: artur
 */

#ifndef GPIOPORTADDRESS_HPP_
#define GPIOPORTADDRESS_HPP_
// ST includes
#include <boardDefs.hpp>

// all GPIO ports supported by ST. Not adjusted to a board
GPIO_TypeDef * gpioPortAddress[ ] = { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG };

#endif /* GPIOPORTADDRESS_HPP_ */
