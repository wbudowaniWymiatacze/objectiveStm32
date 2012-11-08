/* 
 * File:   KamodMEMS2.cpp
 * Author: reymondo
 * 
 * Created on 4 marzec 2012, 19:30
 */

#include "KamodMEMS2.hpp"

KamodMEMS2::KamodMEMS2() 
{
   
}

KamodMEMS2::KamodMEMS2(unsigned char  ad, CI2C* i) 
{
    init(ad, i);
}

void KamodMEMS2::init(unsigned char ad, CI2C* i)
{
    addr=ad;
    i2c=i;
    unsigned char cr1Val = LIS35_REG_CR1_XEN | 
                           LIS35_REG_CR1_YEN | 
                           LIS35_REG_CR1_ZEN | 
                           LIS35_REG_CR1_ACTIVE | 
                           LIS35_REG_CR1_FULL_SCALE;
    
    writeToRegister(LIS35_REG_CR1, cr1Val);
}

unsigned char  KamodMEMS2::getx()
{
    return getRegisterVal(LIS35_REG_OUTX);
}

unsigned char  KamodMEMS2::gety()
{
    return getRegisterVal(LIS35_REG_OUTY);
}

unsigned char  KamodMEMS2::getz()
{
    return getRegisterVal(LIS35_REG_OUTZ);
}

unsigned char KamodMEMS2::getRegisterVal(unsigned char regAddr )
{
    unsigned char  B=regAddr;
    i2c->sendBytes(addr,&B,1);
    i2c->readBytes(addr, &B, 1);
    return B; 
}

void KamodMEMS2::writeToRegister(unsigned char regAddr, unsigned char val)
{
    unsigned char B[2] = {regAddr, val};
    i2c->sendBytesAndStop(addr,B,2);
}
