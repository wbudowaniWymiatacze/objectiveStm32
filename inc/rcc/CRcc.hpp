/*
 * CRcc.hpp
 *
 *  Created on: Mar 3, 2012
 *      Author: artur
 */

#ifndef CRCC_HPP_
#define CRCC_HPP_


// TODO: make it singleton?
namespace Rcc
{

class CRcc {
public:
	CRcc();
	static void apb1Enable( uint32_t apb1Value );
	static void apb1Disable( uint32_t apb1Value );
	static void apb2Enable( uint32_t apb2Value );
	static void apb2Disable( uint32_t apb2Value );
	~CRcc() {}

private:
	static inline void increaseUseCount( uint32_t * useCounter, uint32_t value );

	static uint32_t m_apb1UseCounter[ sizeof( uint32_t ) ];
	static uint32_t m_apb2UseCounter[ sizeof( uint32_t ) ];
};

} // namespace Rcc

#endif /* CRCC_HPP_ */
