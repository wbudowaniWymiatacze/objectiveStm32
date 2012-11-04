/* 
 * File:   PeripheralTypes.hpp
 * Author: reymondo
 *
 * Created on 13 czerwiec 2012, 22:09
 */

#ifndef PERIPHERALTYPES_HPP
#define	PERIPHERALTYPES_HPP

#include <map>

enum EPeripheralConfig
{
    None = 0 ,
    Led,
    Usart,
    I2C   
};

template<typename TPeripheralConfig>
class cmp
{
public:
    bool operator()(TPeripheralConfig x,TPeripheralConfig y)
    {
        return x < y;
    }
};

template<typename TPeripheral>
struct PeripheralTypes
{
    typedef std::map <typename TPeripheral::TPeripheralConfig, TPeripheral*,cmp<typename TPeripheral::TPeripheralConfig> > TPeriphMap;
};


typedef struct SPeripheralConfig
{
    EPeripheralConfig type; 
    GPIO_TypeDef*     gpioPort; 
    uint32_t          remap; 
    uint32_t          apb1;     
    uint32_t          apb2;
    uint8_t           irqChannel;
    
    bool operator<( const SPeripheralConfig a)
    {
        return (apb1<a.apb1) && (apb2<a.apb2) && (gpioPort<a.gpioPort) && (remap < a.remap);
    }
    
    SPeripheralConfig():
        type(None), gpioPort(0), remap(0), apb1(0), apb2(0), irqChannel(0)
    {
        
    }
    
  
}SPeripheralConfig;

typedef struct TPeripheralConfigLed : public SPeripheralConfig
{
    uint16_t         gpioPin;
    
    TPeripheralConfigLed()
    {
        type = Led;
    }
    
    bool operator<( const TPeripheralConfigLed a)
    {
        return (apb1<a.apb1) && (apb2<a.apb2) && (gpioPort<a.gpioPort) && (remap < a.remap) && (gpioPin < a.gpioPin);
    }
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
    uint16_t         gpioPinSda;
}TPeripheralConfigI2C;

#endif	/* PERIPHERALTYPES_HPP */

