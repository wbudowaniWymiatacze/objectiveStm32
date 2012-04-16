/* 
 * File:   sd.h
 * Author: mear
 *
 * Created on 15 kwiecień 2012, 22:22
 */

#ifndef SD_H
#define	SD_H

#define CARD_INSERT_PORT GPIOB                          // wg Kamami datasheet
#define CARD_INSERT_PIN 9                               // wg Kamami datasheet
#define CARD_INSERT_APB2ENR RCC_APB2Periph_GPIOB        // enable IOPBEN (RM 111)

//Initialize card insert
void card_insert_init(void);

/** 
  * @brief Reset and Clock Control
  */

typedef struct
{
 uint32_t CR;
 uint32_t CFGR;
 uint32_t CIR;
 uint32_t APB2RSTR;
 uint32_t APB1RSTR;
 uint32_t AHBENR;
 uint32_t APB2ENR;
 uint32_t APB1ENR;
 uint32_t BDCR;
 uint32_t CSR;
} RCC_TypeDef2;

#endif	/* SD_H */

