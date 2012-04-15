/* 
 * File:   sd.h
 * Author: mear
 *
 * Created on 15 kwiecień 2012, 22:22
 */

#ifndef SD_H
#define	SD_H

#define CARD_INSERT_PORT GPIOB
#define CARD_INSERT_PIN 9
#define CARD_INSERT_APB2ENR RCC_APB2Periph_GPIOB

/*----------------------------------------------------------*/
/** GPIO bits macros */ // TODO: czy tego nie ma już gdzieś w kodzie?
enum
{
	//! GPIO mode input
	GPIO_MODE_INPUT = 0,
	//! GPIO mode out 10MHZ
	GPIO_MODE_10MHZ = 1,
	//! GPIO mode out 2MHZ
	GPIO_MODE_2MHZ = 2,
	//! GPIO mode out 50MHZ
	GPIO_MODE_50MHZ = 3
};

enum
{
	//! Configuration IN analog mode
	GPIO_CNF_IN_ANALOG = 0,
	//! Configuration IN float mode
	GPIO_CNF_IN_FLOAT = 1,
	//! Configuration IN pullup mode
	GPIO_CNF_IN_PULLUP = 2
};
/*----------------------------------------------------------*/

/*----------------------------------------------------------*/
/**
 * 	Configure GPIO line into selected mode
 *	@param[in] port Port to configure
 *	@param[in] mode New port mode
 *	@param[in] config New port configuration
 */
static inline void io_config(GPIO_TypeDef* port,uint8_t bit,uint32_t mode,uint32_t config)
{
	if(bit>7)
	{
		port->CRH &= ~(0xf<<(4*(bit-8)));
		port->CRH |= (mode|(config<<2)) << (4*(bit-8));
	}
	else
	{
		port->CRL &= ~(0xf<<(4*bit));
		port->CRL |= (mode|(config<<2)) << (4*bit);
	}
}
/*----------------------------------------------------------*/

//Initialize card insert
static void card_insert_init(void);

#endif	/* SD_H */

