/*
 * wdog.h
 *
 *  Created on: 22 sep 2022
 *      Author: sonny
 */

#ifndef WDOG_H_
#define WDOG_H_

#include "rgb.h"
#include "gpio.h"
#include "fsl_wdog.h"
#include "fsl_rcm.h"

#define WDOG_WCT_INSTRUCITON_COUNT (256U)

static WDOG_Type *wdog_base = WDOG;
static RCM_Type *rcm_base   = RCM;
wdog_config_t config;

void wdog_init(void);
static void WaitWctClose(WDOG_Type *base);

static inline uint32_t GetTimerOutputValue(WDOG_Type *base);

#endif /* WDOG_H_ */
