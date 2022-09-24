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
#include "MK64F12.h"

#define WDOG_WCT_INSTRUCITON_COUNT (256U)

static void WaitWctClose(WDOG_Type *base);

#endif /* WDOG_H_ */

