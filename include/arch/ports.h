/**
 * @file  ports.h
 * @brief This header file organizes the include paths for the
 *        specific architecures
 */

#ifndef _PORTS_H
#define _PORTS_H

void port_yield(void);

void port_enter_critical(void);

void port_exit_critical(void);


#ifdef CORTEX_M4
#include "arm/cortex_m4/port.h"
#endif

#endif
