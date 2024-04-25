/**
 * @file  kernel.h
 * @brief
 */

#ifndef _KERNEL_H
#define _KERNEL_H

#include "arch/ports.h"
#include "config.h"
#include "lib/stdbool.h"

typedef enum K_STATUS { K_SUCCESFUL = true, K_FAILURE = false } K_STATUS;

typedef void (*function_ptr)(void);

/**
 * @typedef PROCESS_STATE
 * @brief   Enum for setting process state
 *
 */
typedef enum PROCESS_STATE {
  NEW = 0,
  RUNNING = 1,
  WAITING = 2,
  READY = 3,
  TERMINATED = 4
} PROCESS_STATE;

/**
 * @typedef PROCESS_PRIORITY
 * @brief   Enum for setting the Task priority
 *
 */
typedef enum PROCESS_PRIORITY {
  PRIORITY_LOW = 0,
  PRIORITY_MEDIUM = 1,
  PRIORITY_HIGH = 2,
} PROCESS_PRIORITY;

/**
 * @typedef   pcb_t
 * @brief     Process Control Block that stores all information about a process
 *            It is the main structure used to schedule.
 *
 */
typedef struct pcb_t pcb_t;
struct pcb_t {
  pcb_t *prev_pcb;
  pcb_t *next_pcb;
  function_ptr function;
  PROCESS_PRIORITY priority;
  PROCESS_STATE state;
};

#endif
