/*
 * CRccManager.hpp
 *
 *  Created on: Mar 3, 2012
 *      Author: artur
 */

#ifndef CRCCMANAGER_HPP_
#define CRCCMANAGER_HPP_

class CRccManager  {
public:
	CRccManager();
	void apb1Enable( uint32_t apb1Value );
	void apb1Disable( uint32_t apb1Value );
	void apb2Enable( uint32_t apb2Value );
	void apb2Disable( uint32_t apb2Value );
	CRccManager( CRccManager const & rccManager );
	CRccManager & operator=( CRccManager const & rccManager );

private:
	inline void increaseUseCount( uint32_t * useCounter,
								  uint32_t value );

	uint32_t m_apb1UseCounter[ sizeof( uint32_t ) ];
	uint32_t m_apb2UseCounter[ sizeof( uint32_t ) ];
};

#endif /* CRCCMANAGER_HPP_ */
