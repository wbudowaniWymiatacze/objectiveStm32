/*
 * CRccManager.cpp
 *
 *  Created on: Mar 3, 2012
 *      Author: artur
 */
#include <boardDefs.hpp>
#include <CRccManager.hpp>

CRccManager::CRccManager()
{
    for( uint8_t bit=0; bit<sizeof( uint32_t ); bit++ )
    {
    m_apb1UseCounter[ bit ] = 0;
    m_apb2UseCounter[ bit ] = 0;
    }
}

void CRccManager::apb1Enable( uint32_t apb1Value )
{
    increaseUseCount( m_apb1UseCounter, apb1Value );
    RCC_APB1PeriphClockCmd( apb1Value, ENABLE );
}

void CRccManager::apb1Disable( uint32_t apb1Value )
{
    uint32_t value = apb1Value;
    uint32_t bitNumber = 0;
    while( value != 0 )
    {
    // get the position of the MSB
    bitNumber = __builtin_clz( value );
    if ( m_apb1UseCounter[ bitNumber ] != 0 )
    {
        m_apb1UseCounter[ bitNumber ]--;
    }
    if ( m_apb1UseCounter[ bitNumber ] == 0 )
    {
        RCC_APB1PeriphClockCmd( 1<<bitNumber, DISABLE );
    }
    value -= 1<<bitNumber;
    }
}

void CRccManager::apb2Enable( uint32_t apb2Value )
{
    increaseUseCount( m_apb2UseCounter, apb2Value );
    RCC_APB1PeriphClockCmd( apb2Value, ENABLE );
}

void CRccManager::apb2Disable( uint32_t apb1Value )
{
    uint32_t value = apb1Value;
    uint32_t bitNumber = 0;
    while( value != 0 )
    {
    // get the position of the MSB
    bitNumber = __builtin_clz( value );
    if ( m_apb2UseCounter[ bitNumber ] != 0 )
    {
        m_apb2UseCounter[ bitNumber ]--;
    }
    if ( m_apb2UseCounter[ bitNumber ] == 0 )
    {
        RCC_APB2PeriphClockCmd( 1<<bitNumber, DISABLE );
    }
    value -= 1<<bitNumber;
    }
}

inline void CRccManager::increaseUseCount( uint32_t * useCounter, uint32_t value )
{
    uint32_t bitNumber = 0;
    while( value != 0 )
    {
    // get the position of the MSB
    bitNumber = __builtin_clz( value );
    useCounter[ bitNumber ]++;
    value -= 1<<bitNumber;
    }
}

CRccManager::CRccManager( CRccManager const & rccManager )
{
    *this = const_cast<CRccManager &> ( rccManager );
}

CRccManager & CRccManager::operator=( CRccManager const & rccManager )
{
    return const_cast<CRccManager &> ( rccManager );
}

