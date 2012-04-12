/** \file hdr_gpio.h
 * \brief Header with definition of bits in GPIO control registers
 * \author Freddie Chopin, http://www.freddiechopin.info/
 * \date 2012-01-07
 */

/******************************************************************************
* chip: STM32F1x
* compiler: arm-none-eabi-gcc (Sourcery CodeBench Lite 2011.09-69) 4.6.1
******************************************************************************/

#ifndef HDR_GPIO_H_
#define HDR_GPIO_H_

/*
+=============================================================================+
| global definitions
+=============================================================================+
*/

/*
+-----------------------------------------------------------------------------+
| GPIOx_CRx - Port Configuration Register, Low & High
+-----------------------------------------------------------------------------+
*/

#define GPIO_CRL_MODE0_bit					0
#define GPIO_CRL_MODE0_0_bit				0
#define GPIO_CRL_MODE0_1_bit				1

#define GPIO_CRL_CNF0_bit					2
#define GPIO_CRL_CNF0_0_bit					2
#define GPIO_CRL_CNF0_1_bit					3

#define GPIO_CRL_MODE1_bit					4
#define GPIO_CRL_MODE1_0_bit				4
#define GPIO_CRL_MODE1_1_bit				5

#define GPIO_CRL_CNF1_bit					6
#define GPIO_CRL_CNF1_0_bit					6
#define GPIO_CRL_CNF1_1_bit					7

#define GPIO_CRL_MODE2_bit					8
#define GPIO_CRL_MODE2_0_bit				8
#define GPIO_CRL_MODE2_1_bit				9

#define GPIO_CRL_CNF2_bit					10
#define GPIO_CRL_CNF2_0_bit					10
#define GPIO_CRL_CNF2_1_bit					11

#define GPIO_CRL_MODE3_bit					12
#define GPIO_CRL_MODE3_0_bit				12
#define GPIO_CRL_MODE3_1_bit				13

#define GPIO_CRL_CNF3_bit					14
#define GPIO_CRL_CNF3_0_bit					14
#define GPIO_CRL_CNF3_1_bit					15

#define GPIO_CRL_MODE4_bit					16
#define GPIO_CRL_MODE4_0_bit				16
#define GPIO_CRL_MODE4_1_bit				17

#define GPIO_CRL_CNF4_bit					18
#define GPIO_CRL_CNF4_0_bit					18
#define GPIO_CRL_CNF4_1_bit					19

#define GPIO_CRL_MODE5_bit					20
#define GPIO_CRL_MODE5_0_bit				20
#define GPIO_CRL_MODE5_1_bit				21

#define GPIO_CRL_CNF5_bit					22
#define GPIO_CRL_CNF5_0_bit					22
#define GPIO_CRL_CNF5_1_bit					23

#define GPIO_CRL_MODE6_bit					24
#define GPIO_CRL_MODE6_0_bit				24
#define GPIO_CRL_MODE6_1_bit				25

#define GPIO_CRL_CNF6_bit					26
#define GPIO_CRL_CNF6_0_bit					26
#define GPIO_CRL_CNF6_1_bit					27

#define GPIO_CRL_MODE7_bit					28
#define GPIO_CRL_MODE7_0_bit				28
#define GPIO_CRL_MODE7_1_bit				29

#define GPIO_CRL_CNF7_bit					30
#define GPIO_CRL_CNF7_0_bit					30
#define GPIO_CRL_CNF7_1_bit					31

#define GPIO_CRH_MODE8_bit					0
#define GPIO_CRH_MODE8_0_bit				0
#define GPIO_CRH_MODE8_1_bit				1

#define GPIO_CRH_CNF8_bit					2
#define GPIO_CRH_CNF8_0_bit					2
#define GPIO_CRH_CNF8_1_bit					3

#define GPIO_CRH_MODE9_bit					4
#define GPIO_CRH_MODE9_0_bit				4
#define GPIO_CRH_MODE9_1_bit				5

#define GPIO_CRH_CNF9_bit					6
#define GPIO_CRH_CNF9_0_bit					6
#define GPIO_CRH_CNF9_1_bit					7

#define GPIO_CRH_MODE10_bit					8
#define GPIO_CRH_MODE10_0_bit				8
#define GPIO_CRH_MODE10_1_bit				9

#define GPIO_CRH_CNF10_bit					10
#define GPIO_CRH_CNF10_0_bit				10
#define GPIO_CRH_CNF10_1_bit				11

#define GPIO_CRH_MODE11_bit					12
#define GPIO_CRH_MODE11_0_bit				12
#define GPIO_CRH_MODE11_1_bit				13

#define GPIO_CRH_CNF11_bit					14
#define GPIO_CRH_CNF11_0_bit				14
#define GPIO_CRH_CNF11_1_bit				15

#define GPIO_CRH_MODE12_bit					16
#define GPIO_CRH_MODE12_0_bit				16
#define GPIO_CRH_MODE12_1_bit				17

#define GPIO_CRH_CNF12_bit					18
#define GPIO_CRH_CNF12_0_bit				18
#define GPIO_CRH_CNF12_1_bit				19

#define GPIO_CRH_MODE13_bit					20
#define GPIO_CRH_MODE13_0_bit				20
#define GPIO_CRH_MODE13_1_bit				21

#define GPIO_CRH_CNF13_bit					22
#define GPIO_CRH_CNF13_0_bit				22
#define GPIO_CRH_CNF13_1_bit				23

#define GPIO_CRH_MODE14_bit					24
#define GPIO_CRH_MODE14_0_bit				24
#define GPIO_CRH_MODE14_1_bit				25

#define GPIO_CRH_CNF14_bit					26
#define GPIO_CRH_CNF14_0_bit				26
#define GPIO_CRH_CNF14_1_bit				27

#define GPIO_CRH_MODE15_bit					28
#define GPIO_CRH_MODE15_0_bit				28
#define GPIO_CRH_MODE15_1_bit				29

#define GPIO_CRH_CNF15_bit					30
#define GPIO_CRH_CNF15_0_bit				30
#define GPIO_CRH_CNF15_1_bit				31

#define GPIO_CRx_MODE_IN_value				0
#define GPIO_CRx_MODE_OUT_10M_value			1
#define GPIO_CRx_MODE_OUT_2M_value			2
#define GPIO_CRx_MODE_OUT_50M_value			3
#define GPIO_CRx_MODE_mask					3

#define GPIO_CRx_CNF_IN_ANALOG_value		0
#define GPIO_CRx_CNF_IN_FLOATING_value		1
#define GPIO_CRx_CNF_IN_PULL_U_D_value		2

#define GPIO_CRx_CNF_OUT_PP_value			0
#define GPIO_CRx_CNF_OUT_OD_value			1
#define GPIO_CRx_CNF_ALT_PP_value			2
#define GPIO_CRx_CNF_ALT_OD_value			3
#define GPIO_CRx_CNF_mask					3

#define GPIO_CRx_MODE_CNF_mask				(GPIO_CRx_MODE_mask | (GPIO_CRx_CNF_mask << 2))

/*
+=============================================================================+
| macros
+=============================================================================+
*/

#define m_GPIO_MODE_bit(pin)				(((pin) * 4) & 0x1C)
#define m_GPIO_CNF_bit(pin)					(m_GPIO_MODE_bit(pin) + 2)
#define m_GPIO_MODE_CNF_value(mode, cnf)	((mode) | ((cnf) << 2))

#define m_GPIO_MODE(pin, mode)				((mode) << m_GPIO_MODE_bit(pin))
#define m_GPIO_CNF(pin, cnf)				((cnf) << m_GPIO_CNF_bit(pin))
#define m_GPIO_MODE_CNF(pin, mode, cnf)		(m_GPIO_MODE(pin, mode) | m_GPIO_CNF(pin, cnf))

/*
+=============================================================================+
| combinations of MODE and CNF
+=============================================================================+
*/

// input combinations
#define  GPIO_CRx_MODE_CNF_IN_ANALOG_value		m_GPIO_MODE_CNF_value(GPIO_CRx_MODE_IN_value, GPIO_CRx_CNF_IN_ANALOG_value)
#define  GPIO_CRx_MODE_CNF_IN_FLOATING_value	m_GPIO_MODE_CNF_value(GPIO_CRx_MODE_IN_value, GPIO_CRx_CNF_IN_FLOATING_value)
#define  GPIO_CRx_MODE_CNF_IN_PULL_U_D_value	m_GPIO_MODE_CNF_value(GPIO_CRx_MODE_IN_value, GPIO_CRx_CNF_IN_PULL_U_D_value)

// push-pull normal output combinations
#define  GPIO_CRx_MODE_CNF_OUT_PP_2M_value		m_GPIO_MODE_CNF_value(GPIO_CRx_MODE_OUT_2M_value, GPIO_CRx_CNF_OUT_PP_value)
#define  GPIO_CRx_MODE_CNF_OUT_PP_10M_value		m_GPIO_MODE_CNF_value(GPIO_CRx_MODE_OUT_10M_value, GPIO_CRx_CNF_OUT_PP_value)
#define  GPIO_CRx_MODE_CNF_OUT_PP_50M_value		m_GPIO_MODE_CNF_value(GPIO_CRx_MODE_OUT_50M_value, GPIO_CRx_CNF_OUT_PP_value)

// open-drain normal output combinations
#define  GPIO_CRx_MODE_CNF_OUT_OD_2M_value		m_GPIO_MODE_CNF_value(GPIO_CRx_MODE_OUT_2M_value, GPIO_CRx_CNF_OUT_OD_value)
#define  GPIO_CRx_MODE_CNF_OUT_OD_10M_value		m_GPIO_MODE_CNF_value(GPIO_CRx_MODE_OUT_10M_value, GPIO_CRx_CNF_OUT_OD_value)
#define  GPIO_CRx_MODE_CNF_OUT_OD_50M_value		m_GPIO_MODE_CNF_value(GPIO_CRx_MODE_OUT_50M_value, GPIO_CRx_CNF_OUT_OD_value)

// push-pull alternate output combinations
#define  GPIO_CRx_MODE_CNF_ALT_PP_2M_value		m_GPIO_MODE_CNF_value(GPIO_CRx_MODE_OUT_2M_value, GPIO_CRx_CNF_ALT_PP_value)
#define  GPIO_CRx_MODE_CNF_ALT_PP_10M_value		m_GPIO_MODE_CNF_value(GPIO_CRx_MODE_OUT_10M_value, GPIO_CRx_CNF_ALT_PP_value)
#define  GPIO_CRx_MODE_CNF_ALT_PP_50M_value		m_GPIO_MODE_CNF_value(GPIO_CRx_MODE_OUT_50M_value, GPIO_CRx_CNF_ALT_PP_value)

// open-drain alternate output combinations
#define  GPIO_CRx_MODE_CNF_ALT_OD_2M_value		m_GPIO_MODE_CNF_value(GPIO_CRx_MODE_OUT_2M_value, GPIO_CRx_CNF_ALT_OD_value)
#define  GPIO_CRx_MODE_CNF_ALT_OD_10M_value		m_GPIO_MODE_CNF_value(GPIO_CRx_MODE_OUT_10M_value, GPIO_CRx_CNF_ALT_OD_value)
#define  GPIO_CRx_MODE_CNF_ALT_OD_50M_value		m_GPIO_MODE_CNF_value(GPIO_CRx_MODE_OUT_50M_value, GPIO_CRx_CNF_ALT_OD_value)

/******************************************************************************
* END OF FILE
******************************************************************************/
#endif /* HDR_GPIO_H_ */
