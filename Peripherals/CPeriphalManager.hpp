/* 
 * File:   CPeriphalManager.hpp
 * Author: reymondo
 *
 * Created on 12 czerwiec 2012, 18:51
 */

#ifndef CPERIPHALMANAGER_HPP
#define	CPERIPHALMANAGER_HPP

#include <IPeripheral.hpp>
#include <PeripheralTypes.hpp>
#include <CGpioManager.hpp>
#include <map>

class cmp
{
public:
    bool operator()(SPeripheralConfig x,SPeripheralConfig y)
    {
        return x < y;
    }
};

class CPeriphalManager 
{
    typedef std::map < SPeripheralConfig, IPeripheral*,cmp> TPeriphMap;
    
  public:
    CPeriphalManager(CGpioManager * GM);
    CPeriphalManager(const CPeriphalManager& orig);
    virtual ~CPeriphalManager();
    
    template<typename TPeripheral>
    TPeripheral* getPeripheral(SPeripheralConfig* config);
    
  private:
      
    void enableAPB1(uint32_t apb1);
    void enableAPB2(uint32_t apb2);
           
    CGpioManager * GM;
    TPeriphMap PeriphMap;

};

template<typename TPeripheral>
TPeripheral * CPeriphalManager::getPeripheral(SPeripheralConfig* config)
{
    
    TPeripheral * Periph;

    
    TPeriphMap::iterator Iter = PeriphMap.find(*config);
    
    if (Iter != PeriphMap.end())
    {
        return static_cast<TPeripheral*>(PeriphMap[*config]);
    }    
   
    enableAPB1(config->apb1);
    enableAPB2(config->apb2);

    Periph = new TPeripheral(GM,config);

    PeriphMap[*config] = static_cast<IPeripheral*>(Periph);
    
    return Periph;
    
}


#endif	/* CPERIPHALMANAGER_HPP */

