#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_wdog.h"
#include "fsl_rcm.h"

#define WDOG_WCT_INSTRUCITON_COUNT (256U)

static void WaitWctClose(WDOG_Type *base)
{
    /* Accessing register by bus clock */
    for (uint32_t i = 0; i < WDOG_WCT_INSTRUCITON_COUNT; i++)
    {
        (void)base->RSTCNT;
    }
}

static inline uint32_t GetTimerOutputValue(WDOG_Type *base)
{
    return (uint32_t)((((uint32_t)base->TMROUTH) << 16U) | (base->TMROUTL));
}

GPIO_INIT();

int main(void) {

	uint8_t boton = 0;

	for(;;)
	{
		input_port_a = !GPIO_PinRead(GPIOA, 4);
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
