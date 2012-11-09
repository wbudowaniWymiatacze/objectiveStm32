/* 
 * File:   CButton.hpp
 * Author: reymondo
 *
 * Created on 15 czerwiec 2012, 22:10
 */

#ifndef CBUTTON_HPP
#define	CBUTTON_HPP

#include <IPeripheral.hpp>
#include <PeripheralTypes.hpp>
#include <CGpioInput.hpp>

class CButton : public IPeripheral
{
public:
    typedef TPeripheralConfigButton TPeripheralConfig;
    
    CButton(CGpioManager * GM,SPeripheralConfig& config);
    virtual ~CButton();
    void init();
    void deinit();
    
    bool isPressed();
    
private:
    CGpio * pin;

};

#endif	/* CBUTTON_HPP */

