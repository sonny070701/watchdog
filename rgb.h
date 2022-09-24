/*
 *  Sonny Ceja, Sergio Borrayo
 *  RGB
 */

#ifndef RGB_H_
#define RGB_H_

#include <stdint.h>
#include "config.h"

#define LED_OFF 	_NON_COLOR
#define YELLOW_LED     _YELLOW
#define RED1_LED		 _RED1
#define PURPLE_LED     _PURPLE

#define GREEN1_LED     _GREEN1
#define RED2_LED         _RED2
#define WHITE1_LED     _WHITE1

#define BLUE_LED         _BLUE
#define GREEN2_LED     _GREEN2
#define WHITE2_LED     _WHITE2

void RGB_red_on(void);

void RGB_blue_on(void);

void RGB_green_on(void);

void RGB_purple_on(void);

void RGB_yellow_on(void);

void RGB_white_on(void);

void RGB_off(void);

void RGB_ctrl(uint8_t color);

#endif /* RGB_H_ */
