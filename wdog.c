/*
 * wdog.c
 *
 *  Created on: 22 sep 2022
 *      Author: sonny
 */
#include "wdog.h"
#include "stdint.h"

void wdog_init(void)
{
	 WDOG_Init(wdog_base, &config);
}

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
