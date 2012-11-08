/* 
 * File:   CUsart.hpp
 * Author: reymondo
 *
 * Created on 8 listopad 2012, 17:09
 */

#ifndef CUSART_HPP
#define	CUSART_HPP

#include <IPeripheral.hpp>
#include <PeripheralTypes.hpp>
#include <CGpio.hpp>

class CUsart : public IPeripheral {
  public:
    typedef TPeripheralConfigUsart TPeripheralConfig;
    
    CUsart(CGpioManager * GM,SPeripheralConfig& config);
    virtual ~CUsart();
    void init();
    
    void sendChar(char c);
    void sendString(const char * c);
    char readChar();
    void readLine(const char * c);
    void recCharHandler(char c);

  private:
    USART_TypeDef * USARTx;
    CGpio*  GPIO_Pin_Tx ;
    CGpio*  GPIO_Pin_Rx ;
    

    char buff[64];
    unsigned char ptr;

};

#endif	/* CUSART_HPP */

