/* 
 * File:   PeripheralTypes.hpp
 * Author: reymondo
 *
 * Created on 13 czerwiec 2012, 22:09
 */

#ifndef PERIPHERALTYPES_HPP
#define	PERIPHERALTYPES_HPP


typedef struct SPeripheralConfig
{
    GPIO_TypeDef *   gpioPort; 
    uint32_t         remap; 
    uint32_t         apb1;     
    uint32_t         apb2;
    uint8_t          irqChannel;
    
//    bool operator<( const SPeripheralConfig& a)
//    {
//        return this->apb1<a.apb1;
//    }
//    bool operator==( const SPeripheralConfig& a)
//    {
//        return this->apb1==a.apb1;
//    }
//    
    bool operator<( const SPeripheralConfig a)
    {
        return (apb1<a.apb1) && (apb2<a.apb2) && (gpioPort<a.gpioPort) && (remap < a.remap);
    }
    
}SPeripheralConfig;

typedef struct TPeripheralConfigLed : public SPeripheralConfig
{
    uint16_t         gpioPin;
}TPeripheralConfigLed;

typedef struct TPeripheralConfigUsart : public SPeripheralConfig
{
    USART_TypeDef *  usart;
    uint16_t         gpioPinTx;
    uint16_t         gpioPinRx;
}TPeripheralConfigUsart;

typedef struct TPeripheralConfigI2C : public SPeripheralConfig
{
    I2C_TypeDef *    i2c;
    uint16_t         gpioPinScl;
    uint16_t         gpioPpinSda;
}TPeripheralConfigI2C;

#endif	/* PERIPHERALTYPES_HPP */

