/*
 * CGpio.hpp
 *
 *  Created on: Jan 29, 2012
 *      Author: artur
 */

#ifndef CGPIO_HPP_
#define CGPIO_HPP_

// ST includes
#include <stm32f10x_gpio.h>

#include <TypePeriph.hpp>

// all GPIO ports supported by ST. Not adjusted to a board
GPIO_TypeDef * gpioPortAddress[ ] = { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG };

class CGpio
{
  public:
	CGpio();
	void setPort( unsigned short port ) : m_port( port ) {}
	void setPin( unsigned short pin ) : m_pin( pin ) {}
	unsigned short getPort();
	unsigned short getPin();
	void init( GPIOSpeed_TypeDef speed, GPIOMode_TypeDef mode );
	bool deinit();
	~CGpio();

  private:
	unsigned short m_pin;
	unsigned short m_port;
};

#endif /* CGPIO_HPP_ */
