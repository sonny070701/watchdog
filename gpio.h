/*
 *  Sonny Ceja, Sergio Borrayo
 *  GPIO
*/
#ifndef GPIO_H_
#define GPIO_H_

#include "stdint.h"
#include "config.h"

/*! These constants are used to select an specific port in the different API functions*/
typedef enum{GPIO_A, /*!< Definition to select GPIO A */
			 GPIO_B, /*!< Definition to select GPIO B */
			 GPIO_C, /*!< Definition to select GPIO C */
			 GPIO_D, /*!< Definition to select GPIO D */
			 GPIO_E, /*!< Definition to select GPIO E */
			 GPIO_F  /*!< Definition to select GPIO F */
			} gpio_name_t;

typedef struct
{
	uint8_t flag_port_a : true;
	uint8_t flag_port_b : true;
	uint8_t flag_port_c : true;
	uint8_t flag_port_d : true;
	uint8_t flag_port_e : true;
} gpio_interrupt_flags_t;


void GPIO_callback_init(gpio_name_t gpio, void (*handler)(uint32_t flags));

void GPIO_clear_irq_status(gpio_name_t gpio);

uint8_t GPIO_get_irq_status(gpio_name_t gpio);

void GPIO_init(void);

#endif /* GPIO_H_ */
