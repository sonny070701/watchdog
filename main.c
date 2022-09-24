/*
 * Watchdog implementation
 *
 * Sergio Borrayo Anzaldo
 * Sonny Ceja Celis
 */

//Headers internos//
#include <stdio.h>
#include "gpio.h"
#include "wdog.h"
#include "rgb.h"

//Headers de drivers
#include "fsl_wdog.h"
#include "fsl_rcm.h"

//Variables del wdog
WDOG_Type *wdog_base = WDOG;
RCM_Type *rcm_base   = RCM;

// Valor del timer //
static inline uint32_t GetTimerOutputValue(WDOG_Type *base)
{
    return (uint32_t)((((uint32_t)base->TMROUTH) << 16U) | (base->TMROUTL));
}

int main(void) {

	GPIO_init();

	uint8_t input_port_a = false;
    uint16_t wdog_reset_count = 0;
    uint8_t contador = 0;
    wdog_config_t config;

    if (!(RCM_GetPreviousResetSources(rcm_base) & kRCM_SourceWdog))
        {
            WDOG_ClearResetCount(wdog_base);
        }
    wdog_reset_count = WDOG_GetResetCount(wdog_base);

	for(;;)
	{
		input_port_a = !GPIO_PinRead(GPIOA, 4);

		if(false != input_port_a)
		{
			contador = +1;
		}

		if(input_port_a)
		{
			while(1);
		}

		WDOG_Refresh(WDOG);
		while(GetTimerOutputValue(wdog_base) < (config.timeoutValue >> 3U))
		{
        }
	}
}
