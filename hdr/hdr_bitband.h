/** \file hdr_bitband.h
 * \brief Header for bit-banding
 * \author Freddie Chopin, http://www.freddiechopin.info/
 * \date 2012-01-07
 */

/******************************************************************************
* chip: ARMv7-M (Cortex-M3)
* compiler: arm-none-eabi-gcc (Sourcery CodeBench Lite 2011.09-69) 4.6.1
******************************************************************************/

#ifndef HDR_BITBAND_H_
#define HDR_BITBAND_H_

/*
+=============================================================================+
| global definitions
+=============================================================================+
*/

#define BITBAND_SRAM_REF   					0x20000000
#define BITBAND_SRAM_BASE  					0x22000000

#define BITBAND_PERIPH_REF   				0x40000000
#define BITBAND_PERIPH_BASE  				0x42000000

/*
+=============================================================================+
| strange variables
+=============================================================================+
*/

#define bitband_t *(volatile unsigned long*)

/*
+=============================================================================+
| macros
+=============================================================================+
*/

#define m_BITBAND_SRAM(address, bit)		(BITBAND_SRAM_BASE + (((unsigned long)address) - BITBAND_SRAM_REF) * 32 + (bit) * 4)
#define m_BITBAND_PERIPH(address, bit)		(BITBAND_PERIPH_BASE + (((unsigned long)address) - BITBAND_PERIPH_REF) * 32 + (bit) * 4)

/******************************************************************************
* END OF FILE
******************************************************************************/
#endif /* HDR_BITBAND_H_ */
