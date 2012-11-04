/* 
 * File:   CPeriphalManager.hpp
 * Author: reymondo
 *
 * Created on 12 czerwiec 2012, 18:51
 */

#ifndef CPERIPHALMANAGER_HPP
#define	CPERIPHALMANAGER_HPP

#include <IPeripheral.hpp>
#include <CLed.hpp>
#include <CI2C.hpp>
#include <PeripheralTypes.hpp>
#include <CGpioManager.hpp>
#include <map>



class CPeriphalManager 
{

    
  public:
    CPeriphalManager(CGpioManager * GM);
    CPeriphalManager(const CPeriphalManager& orig);
    virtual ~CPeriphalManager();
    
    template<typename TPeripheral>
    TPeripheral* getPeripheral(SPeripheralConfig& config);
    
    template<typename TPeripheral, typename TPeriphMap>
    TPeripheral* getPeripheralImpl(SPeripheralConfig& conf, TPeriphMap& map);
    
  private:
      
    void enableAPB1(uint32_t apb1);
    void enableAPB2(uint32_t apb2);
           
    CGpioManager * GM;
    
    PeripheralTypes<CLed>::TPeriphMap LedPeriphMap;
    PeripheralTypes<CI2C>::TPeriphMap I2CPeriphMap;
    
};

template<typename TPeripheral, typename TPeriphMap>
TPeripheral* CPeriphalManager::getPeripheralImpl(SPeripheralConfig& conf, TPeriphMap& map)
{
    typedef typename TPeripheral::TPeripheralConfig TPeripheralConfig;
    TPeripheralConfig& config = static_cast<TPeripheralConfig&>(conf);
    typename TPeriphMap::iterator Iter = map.find(config);
    
    if (Iter != map.end())
    {
      return static_cast<TPeripheral*>(Iter->second);
    }
   
    enableAPB1(config.apb1);
    enableAPB2(config.apb2);

    TPeripheral* Periph = new TPeripheral(GM,config);

    map[config] = Periph;
    
    return Periph;
    
}



#endif	/* CPERIPHALMANAGER_HPP */

