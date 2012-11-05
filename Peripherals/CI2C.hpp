/* 
 * File:   CI2C.hpp
 * Author: reymondo
 *
 * Created on 18 czerwiec 2012, 20:28
 */

#ifndef CI2C_HPP
#define	CI2C_HPP

#include <IPeripheral.hpp>
#include <PeripheralTypes.hpp>
#include <CGpioI2C.hpp>

class CI2C : public IPeripheral {
  public:
    typedef TPeripheralConfigI2C TPeripheralConfig;
      
    CI2C(CGpioManager * GM,SPeripheralConfig& config);
    virtual ~CI2C();
    void init();
    void deinit();
    
    void sendBytesAndStop(unsigned char addr, unsigned char * b ,unsigned char len);
    void sendBytes(unsigned char addr, unsigned char * b, unsigned char len);
    void readBytes(unsigned char addr, unsigned char * b, unsigned char len);
    
  private:
    I2C_TypeDef * I2Cx;
    CGpio *  GPIO_Pin_SCL ;
    CGpio *  GPIO_Pin_SDA ;  

};

#endif	/* CI2C_HPP */

