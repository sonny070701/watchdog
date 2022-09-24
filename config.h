/*
 * config.h
 * Sonny Ceja
 * - Configuración de los headers -
 */

#ifndef CONFIG_H_
#define CONFIG_H_

//COLORES Y PINES
#define _NON_COLOR          0

#define _YELLOW             1
#define _RED1               2
#define _PURPLE             3

#define _GREEN1             4
#define _RED2               5
#define _WHITE1				6

#define _BLUE				7
#define _GREEN2				8
#define _WHITE2				9

#define SW2_GPIO       (GPIOC)
#define SW2_PIN        (6u)

#define SW3_GPIO       (GPIOA)
#define SW3_PIN        (4u)

#define RED_LED_GPIO   (GPIOB)
#define RED_LED_PIN    (22u)

#define BLUE_LED_GPIO  (GPIOB)
#define BLUE_LED_PIN   (21u)

#define GREEN_LED_GPIO (GPIOE)
#define GREEN_LED_PIN  (26u)

//GPIO//
#define false 0
#define true  1

#define all      0xFFFFFFFF
#define sw2_p    6u
#define sw3_p    4u
#define red_p    22u
#define blue_p   21u
#define green_p  26u

//RGB
#define b_1 1
#define b_21 21
#define b_22 22
#define b_26 26
#define bp_8 8

//State machine
#define selector_ARM 3
#define selector_VRB 12
#define selector_AVB 48

#endif /* CONFIG_H_ */
