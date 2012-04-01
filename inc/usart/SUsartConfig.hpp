/*
 * SUsartConfig.hpp
 *
 *  Created on: Mar 13, 2012
 *      Author: artur
 */

#ifndef SUSARTCONFIG_HPP_
#define SUSARTCONFIG_HPP_

#include <boardDefs.hpp>

#include <SPeriphConfig.hpp>

struct SUsartConfig : public SPeriphConfig
{
	USART_InitTypeDef	usartConfig;
};


#endif /* SUSARTCONFIG_HPP_ */
