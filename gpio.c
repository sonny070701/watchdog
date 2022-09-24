#include "MK64F12.h"
#include "gpio.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_clock.h"
#include "config.h"

volatile static gpio_interrupt_flags_t g_intr_status_flag = {false};

static void (*gpio_C_callback)(uint32_t flags) = false;
static void (*gpio_A_callback)(uint32_t flags) = false;


void GPIO_callback_init(gpio_name_t gpio, void (*handler)(uint32_t flags))
{
	if(GPIO_A == gpio)
	{
		gpio_A_callback = handler;
	}
	else
	{
		gpio_C_callback = handler;
	}

}

void PORTC_IRQHandler(void)
{

	uint32_t irq_status = false;

	irq_status = GPIO_PortGetInterruptFlags(GPIOC);

	if(gpio_C_callback)
	{
		gpio_C_callback(irq_status);
	}

	GPIO_PortClearInterruptFlags(GPIOC, all);

}


void PORTA_IRQHandler(void)
{
	uint32_t irq_status = false;

	irq_status = GPIO_PortGetInterruptFlags(GPIOA);

	if(gpio_A_callback)
	{
		gpio_A_callback(irq_status);
	}

	GPIO_PortClearInterruptFlags(GPIOA, irq_status);
}

void GPIO_init(void)
{
	gpio_pin_config_t gpio_input_config = {
			        kGPIO_DigitalInput,
			        false,
			    };

	gpio_pin_config_t gpio_output_config = {
			        kGPIO_DigitalOutput,
			        true,
			    };

	const port_pin_config_t button_config = {
			kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
			kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
			kPORT_PassiveFilterEnable,                              /* Passive filter is disabled */
			kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
			kPORT_HighDriveStrength,                                 /* High drive strength is configured */
			kPORT_MuxAsGpio,                                         /* Pin is configured as PTA4 */
			kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
		  };


	CLOCK_EnableClock(kCLOCK_PortA);
	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortE);
	CLOCK_EnableClock(kCLOCK_PortC);

	GPIO_PinInit(SW2_GPIO, SW2_PIN, &gpio_input_config);
	PORT_SetPinConfig(PORTC, sw2_p, &button_config);
	PORT_SetPinInterruptConfig(PORTC, sw2_p, kPORT_InterruptFallingEdge);

	GPIO_PinInit(GPIOA, SW3_PIN, &gpio_input_config);
	PORT_SetPinConfig(PORTA, sw3_p, &button_config);
	PORT_SetPinInterruptConfig(PORTA, sw3_p, kPORT_InterruptFallingEdge);

	PORT_SetPinMux(PORTB, red_p, kPORT_MuxAsGpio);
	GPIO_PinInit(GPIOB, red_p, &gpio_output_config);

	PORT_SetPinMux(PORTB, blue_p, kPORT_MuxAsGpio);
	GPIO_PinInit(GPIOB, blue_p, &gpio_output_config);

	PORT_SetPinMux(PORTE, green_p, kPORT_MuxAsGpio);
	GPIO_PinInit(GPIOE, green_p, &gpio_output_config);
}


void GPIO_clear_irq_status(gpio_name_t gpio)
{
	if(GPIO_A == gpio)
	{
		g_intr_status_flag.flag_port_a = false;
	}

	else
	{
		g_intr_status_flag.flag_port_c = false;
	}
}

uint8_t GPIO_get_irq_status(gpio_name_t gpio)
{
	uint8_t status = false;

	if(GPIO_A == gpio)
	{
		status = g_intr_status_flag.flag_port_a;
	}
	else
	{
		status = g_intr_status_flag.flag_port_c;
	}

	return(status);
}


