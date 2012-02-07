/*
 * main.cpp
 *
 *  Created on: Jan 21, 2012
 *      Author: artur
 */

#include <shared_ptr.hpp>
#include <CDma.hpp>

int main()
{
	CDma<int> dma;
	dma.test( 9 );
	shared_ptr< CDma<float> > dmaSharedPtr( new CDma<float> );

	return 0;
}


