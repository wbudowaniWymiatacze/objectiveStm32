/*
 * CRcc.hpp
 *
 *  Created on: Mar 3, 2012
 *      Author: artur
 */

#ifndef CRCC_HPP_
#define CRCC_HPP_


// TODO: make it singleton?
class CRcc {
public:
	CRcc();
	void apb1Enable( uint32_t apb1Value );
	void apb1Disable( uint32_t apb1Value );
	void apb2Enable( uint32_t apb2Value );
	void apb2Disable( uint32_t apb2Value );
	~CRcc() {}

private:
	inline void increaseUseCount( uint32_t * useCounter,
								  uint32_t value );

	uint32_t m_apb1UseCounter[ sizeof( uint32_t ) ];
	uint32_t m_apb2UseCounter[ sizeof( uint32_t ) ];
};

#endif /* CRCC_HPP_ */
