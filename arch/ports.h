/**
 * @file  ports.h
 * @brief This header file organizes the include paths for the
 *        specific architecures
 */

#ifndef PORTS_H
#define PORTS_H

#ifdef ARM
  #ifdef CORTEX_M4
  #define PORT_INCLUDE #include "arch/arm/cortex_m4/port.h"
  #endif
#endif

#endif
