/* 
 * File:   sd.h
 * Author: mear
 *
 * Created on 15 kwiecień 2012, 22:22
 */

#ifndef SD_H
#define	SD_H

//Initialize card insert
void card_insert_init(void);

//Initialize leds 3 and 4
void led_34_init(void);

//Detect if card is in the slot
bool card_inside (void);

#endif	/* SD_H */

