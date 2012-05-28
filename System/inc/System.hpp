/* 
 * File:   System.hpp
 * Author: reymondo
 *
 * Created on 28 maj 2012, 17:53
 */

#ifndef SYSTEM_HPP
#define	SYSTEM_HPP

class System {
public:
    System();
    System(const System& orig);
    virtual ~System();
    
    InitRccForDevice(uint32_t);
    
private:

};

#endif	/* SYSTEM_HPP */

