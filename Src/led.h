/*
 * led.h
 *
 *  Created on: Dec 4, 2023
 *      Author: Jesús
 */

#ifndef LED_H_
#define LED_H_

#define LED_GREEN  				12
#define LED_ORANGE 				13
#define LED_RED    				14
#define LED_BLUE   				15

#define DELAY_COUNT_1MS 	    1250U
#define DELAY_COUNT_1S  		(1000U * DELAY_COUNT_1MS)
#define DELAY_COUNT_500MS  		(500U  * DELAY_COUNT_1MS)
#define DELAY_COUNT_250MS 		(250U  * DELAY_COUNT_1MS)
#define DELAY_COUNT_125MS 		(125U  * DELAY_COUNT_1MS)

void LED_initAll(void);
void LED_setOn(uint8_t ledNo);
void LED_setOff(uint8_t ledNo);
void LED_delay(uint32_t count);

#endif /* LED_H_ */