/* 
 * File:   CLed.hpp
 * Author: reymondo
 *
 * Created on 15 czerwiec 2012, 22:10
 */

#ifndef CLED_HPP
#define	CLED_HPP

#include <IPeripheral.hpp>
#include <PeripheralTypes.hpp>
#include <CGpioOutput.hpp>

class CLed : public IPeripheral
{
public:
    typedef TPeripheralConfigLed TPeripheralConfig;
    
    CLed(CGpioManager * GM,SPeripheralConfig& config);
    virtual ~CLed();
    void init();
    void deinit();
    
    void on();
    void off();
    void toogle();
    
private:
    CGpio * pin;

};

#endif	/* CLED_HPP */

