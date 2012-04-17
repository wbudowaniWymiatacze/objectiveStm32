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

#endif	/* SD_H */

