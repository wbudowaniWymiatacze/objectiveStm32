/*
 * boardDefs.hpp
 *
 *  Created on: Jan 31, 2012
 *      Author: artur
 */

#ifndef BOARDDEFS_HPP_
#define BOARDDEFS_HPP_

#include <misc.h>

#ifdef STM32F103VBXX

// project's includes
#include "boards/f1xx/f103/STM32F103VBxx_Desc.hpp"
#include "boards/f1xx/gpio.hpp"
#include "boards/f1xx/usart.hpp"
#include "boards/f1xx/rcc.hpp"
#endif

#ifdef STM32F107VCXX

 // project's includes
 #include "boards/f1xx/f107/STM32F107VCxx_Desc.hpp"
 #include "boards/f1xx/gpio.hpp"
 #include "boards/f1xx/usart.hpp"
 #include "boards/f1xx/rcc.hpp"
#endif


#endif /* BOARDDEFS_HPP_ */
