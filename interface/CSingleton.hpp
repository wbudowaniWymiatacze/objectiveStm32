/*
 * CSingleton.hpp
 *
 *  Created on: Mar 10, 2012
 *      Author: artur
 */

#ifndef CSINGLETON_HPP_
#define CSINGLETON_HPP_

template < typename T >
class CSingleton
{
public:
    static T * getInstance()
    {
    static T instance;
    return &instance;
    }

protected:
    CSingleton() {}
    ~CSingleton() {}

private:
    CSingleton( CSingleton< T > const & );
    CSingleton< T > & operator=( CSingleton< T > const & );
};

#endif /* CSINGLETON_HPP_ */
