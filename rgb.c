
#include "rgb.h"
#include "fsl_gpio.h"
#include "MK64F12.h"
#include "gpio.h"
#include "config.h"

volatile static uint8_t led_pit = 0; //00 00 00

//COLORES PRINCIPALES//
void RGB_red_on(void)
{
	RGB_off();
	GPIO_PortClear(GPIOB, b_1 << b_22);
}

void RGB_blue_on(void)
{
	RGB_off();
	GPIO_PortClear(GPIOB, b_1 << b_21);
}

void RGB_green_on(void)
{
	RGB_off();
	GPIO_PortClear(GPIOE, b_1 << b_26);
}

//COLORES SECUNDARIOS//
void RGB_purple_on(void)
{
	RGB_off();
	GPIO_PortClear(GPIOB, b_1 << b_21);
	GPIO_PortClear(GPIOB, b_1 << b_22);
}

void RGB_yellow_on(void)
{
	RGB_off();
	GPIO_PortClear (GPIOE, b_1 << b_26);
	GPIO_PortClear (GPIOB, b_1 << b_22);
}

void RGB_white_on(void)
{
	RGB_off();
	GPIO_PortToggle(GPIOB, b_1 << b_21);
	GPIO_PortToggle(GPIOB, b_1 << b_22);
	GPIO_PortToggle(GPIOE, b_1 << b_26);
}

//APAGAR PUERTOS//
void RGB_off(void)
{
	GPIO_PortSet(GPIOB, b_1 << b_21);
	GPIO_PortSet(GPIOB, b_1 << b_22);
	GPIO_PortSet(GPIOE, b_1 << b_26);
}
