/*
 * EUsartBitOffset.hpp
 *
 *  Created on: Feb 7, 2012
 *      Author: artur
 */

#ifndef EUSARTBITOFFSET_HPP_
#define EUSARTBITOFFSET_HPP_

#include <EGpioNumberfBits.hpp>

enum EUsartBitOffset
{
	EUsartRxPortBitOffset = 0,
	EUsartRxPinBitOffset = EUsartRxPortBitOffset + EGpioPortNumberOfBits,
	EUsartTxPortBitOffset = EUsartRxPinBitOffset + EGpiotPinNumberOfBits,
	EUsartTxPinBitOffset = EUsartTxPortBitOffset + EGpioPortNumberOfBits
};


#endif /* EUSARTBITOFFSET_HPP_ */
