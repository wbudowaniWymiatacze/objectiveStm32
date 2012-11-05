/*
 * KamodRGB.hpp
 *
 *  Created on: 29-02-2012
 *      Author: reymondo
 */

#ifndef KAMODRGB_HPP_

#include <CI2C.hpp>

typedef enum KamodRGBColors
{
	KAmber = 2,
	KBlue   ,
	KRed ,
	KGreen  ,

}KamodRGBColors;

class KamodRGB
{
  public:
	KamodRGB();
	KamodRGB(u8 addr,  CI2C* i2c);
	void init(u8 addr, CI2C* i2c);
	void light(KamodRGBColors color, u8 val);
  private:
	CI2C* i2c;
	u8 addr;

};


#define KAMODRGB_HPP_


#endif /* KAMODRGB_HPP_ */
