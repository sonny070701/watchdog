/*
 * Watchdog implementation
 *
 * Sergio Borrayo Anzaldo
 * Sonny Ceja Celis
 */

#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

#include "fsl_wdog.h"
#include "fsl_rcm.h"
#include "config.h"
#include "gpio.h"

// count
#define WDOG_WCT_INSTRUCITON_COUNT (256U)

//pointers
static WDOG_Type *wdog_base = WDOG;
static RCM_Type *rcm_base   = RCM;

//Funciones del wdog//
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

int main(void)
{
    uint16_t wdog_reset_count = 0;
    wdog_config_t config;

    GPIO_init();

    /*If not wdog reset*/
    if (!(RCM_GetPreviousResetSources(rcm_base) & kRCM_SourceWdog))
    {
        WDOG_ClearResetCount(wdog_base);
    }

    wdog_reset_count = WDOG_GetResetCount(wdog_base);

    if (wdog_reset_count == 0)
    {
        WDOG_GetDefaultConfig(&config);
        config.timeoutValue = 0x1002U;
        WDOG_Init(wdog_base, &config);
        WaitWctClose(wdog_base);

        for (;;)
        {
            WDOG_Refresh(wdog_base);
            while (GetTimerOutputValue(wdog_base) < (config.timeoutValue >> 3U)) // esto va siempre del feed / refresh
            {
            }
            if(!(GPIO_PinRead(SW2_GPIO, SW2_PIN))){
            	for(;;){
            	};
            }
        }
        /* wait for wdog timeout reset */
    }
    else if (wdog_reset_count == 1)
    {

        GPIO_PortClear(BLUE_LED_GPIO, 1 << 21);
        WDOG_GetDefaultConfig(&config);
        config.timeoutValue = 0x1002U; // es el tiempo limite que tiene para responder
        WDOG_Init(wdog_base, &config);
        WaitWctClose(wdog_base);
        for(;;)
        {
            WDOG_Refresh(wdog_base);
            while (GetTimerOutputValue(wdog_base) < (config.timeoutValue >> 3U)) // esto va siempre del feed / refresh
            {
            }
            if(!(GPIO_PinRead(SW2_GPIO, SW2_PIN)))
            {
            	for(;;)
            	{
            	}
            }
        }

    }
    else if (wdog_reset_count == 2)
    {
    	GPIO_PortClear(RED_LED_GPIO, 1 << 22);
    	WDOG_GetDefaultConfig(&config);
    	config.timeoutValue = 0x1002U;
    	WDOG_Init(wdog_base, &config);
    	WaitWctClose(wdog_base);
    	for(;;)
    	{
    		WDOG_Refresh(wdog_base);

    		while (GetTimerOutputValue(wdog_base) < (config.timeoutValue >> 3U)) // esto va siempre del feed / refresh
    		{
    		}
    		if(!(GPIO_PinRead(SW2_GPIO, SW2_PIN)))
    		{
    			for(;;)
    			{
    			}
    		}
    	}
    }
    else if(wdog_reset_count == 3)
    {
    	GPIO_PortClear(RED_LED_GPIO,  1 << 22);
    	GPIO_PortClear(BLUE_LED_GPIO, 1 << 21);
    	WDOG_GetDefaultConfig(&config);
    	config.timeoutValue = 0x1002U; // es el tiempo limite que tiene para responder
    	WDOG_Init(wdog_base, &config);
    	WaitWctClose(wdog_base);
    	for(;;)
    	{
    		WDOG_Refresh(wdog_base);
    		while (GetTimerOutputValue(wdog_base) < (config.timeoutValue >> 3U)) // esto va siempre del feed / refresh
    		{
    		}
        	if(!(GPIO_PinRead(SW2_GPIO, SW2_PIN)))
        	{
        		for(;;)
        		{
        	    }
        	}
    	}
    }
    while (1)
    {
    }
}
