/*
 * CGpio.cpp
 *
 *  Created on: Jan 29, 2012
 *      Author: artur
 */

// ST includes
#include <stm32f10x_gpio.h>

#include "../inc/CGpio.hpp"
#include <TypePeriph.hpp>

CGpio::CGpio() {
	// TODO Auto-generated constructor stub

}

unsigned short CGpio::getPort()
{
	return m_port;
}

unsigned short CGpio::getPin()
{
	return m_pin;
}

void CGpio::init( GPIOSpeed_TypeDef speed, GPIOMode_TypeDef mode )
{
	GPIO_InitTypeDef gpioConf;

	gpioConf.GPIO_Pin = getPin();
	gpioConf.GPIO_Speed = speed;
	gpioConf.GPIO_Mode	= mode;

	GPIO_Init( gpioPortAddress[ getPort() ], &gpioConf );
}

bool CGpio::deinit()
{
	return true;
}

CGpio::~CGpio() {
	// TODO Auto-generated destructor stub
}

