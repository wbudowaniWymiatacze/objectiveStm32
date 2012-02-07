/*
 * shared_ptr.hpp
 *
 *  Created on: Jan 29, 2012
 *      Author: artur
 */

#ifndef SHARED_PTR_HPP_
#define SHARED_PTR_HPP_

#include <cassert>

template < typename T >
class shared_ptr
{
public:
	// creates shared_ptr without pointing to any object
	shared_ptr() : m_obj( 0 ) { m_referencesCounter = new unsigned int; *m_referencesCounter = 0; }

	// creates shared_ptr with object to point to
	shared_ptr( T* obj ) : m_obj( obj )
	{
		m_referencesCounter = new unsigned int;
		*m_referencesCounter = ( unsigned int ) 1;
	}

	// copy constructor
	shared_ptr( shared_ptr< T >& sharedPtrObj );

	// dereference will point to the wrapped object
	// shared_ptr->foo() will call m_obj->foo()
	T* operator->() { assert( m_obj != 0 ); return m_obj; }

	// current object is "unwrapped", its reference value is decreased
	// wraps object wrapped by the argument, gets its references counter and increases it
	shared_ptr< T >& operator=(const shared_ptr< T >& );

	// current object is "unwrapped", its reference value is decreased
	// wraps the argument object, increases references counter
	shared_ptr< T >& operator=( const T* );

	virtual ~shared_ptr();

private:

	// returns pointer to the wrapped object
	T* getObj() { return m_obj; }

	// shares references counter so that it may be changed by another shared_ptr
	unsigned int* shareRefCounter() { return m_referencesCounter; }

	// unwraps currently wrapped object
	// returns the value of the references count after unwrapping
	void unwrap();

	T*				m_obj;
	unsigned int*	m_referencesCounter;
};

template < typename T >
shared_ptr< T >::shared_ptr( shared_ptr< T >& sharedPtrObj )
{
	( *this ).m_obj = sharedPtrObj.getObj();
	( *this ).m_referencesCounter = sharedPtrObj.shareRefCounter();
}

template < typename T >
shared_ptr< T >& shared_ptr< T >::operator=( const shared_ptr< T >& sharedPtrObj )
{
	// unwrap the currently wrapped object
	( *this ).unwrap();

	( *this ).m_obj = sharedPtrObj.getObj();
	( *this ).m_referencesCounter = sharedPtrObj.shareRefCounter();

	return *this;

}

template < typename T >
shared_ptr< T >& shared_ptr< T >::operator=( const T* obj )
{
	// unwrap the currently wrapped object
	( *this ).unwrap();

	m_obj = obj;
	*m_referencesCounter = 1;

	return *this;
}

template < typename T >
void shared_ptr< T >::unwrap()
{
	if ( --( *m_referencesCounter ) == 0 )
	{
		if ( m_obj != 0 )
		{
			delete m_obj;
		}
	}
}

template < typename T >
shared_ptr< T >::~shared_ptr()
{
	unwrap();
}

#endif /* SHARED_PTR_HPP_ */
