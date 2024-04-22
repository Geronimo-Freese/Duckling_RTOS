/**
 * @file  rtos.h
 * @brief Main #include file
 *        This software is a 1 header include system
 *
 *        USER-INCLUDE-FILE
 */

#ifndef _RTOS_H
#define _RTOS_H

#include "kernel.h"
#include "sys/errno.h"

/**
 * @brief   adds a task to the OS for scheduling
 *
 * @param   pointer to the function
 * @return  status of the action
 */
K_STATUS os_create_process(function_ptr func);

/**
 * @brief
 *
 * @param func
 * @return
 */
K_STATUS os_add_process(function_ptr func);



/**
 * @brief   Adds a process to schedule for the kernel
 *
 * @param   function  Function Pointer for the pcb to know
 *                    where the function is located
 * @param   priority  priority for the scheduler
 * @return  Kernel status regarding this action
 */
void os_add_process(function_ptr function, PROCESS_PRIORITY priority);

/**
 * @brief Starts the execution of the kernel and
 *        sets up all related information so the
 *        scheduler can start giving processes ressources
 *
 * @return Kernel status regarding this action
 */
void os_start();

/**
 * @brief Calling Task will give up execution time so
 *        the scheduler can reschedule
 *
 * @return Kernel status regarding this action
 */
void os_yield();

/**
 * @brief Enters a critical region which may not
 *        be interrupted by the scheduler due to
 *        non-atomic action by the caller
 *
 * @return Kernel status regarding this action
 */
void enter_critical();

/**
 * @brief Exits a critical region so the scheduler
 *        can be executed again safely
 *
 * @return Kernel status regarding this action
 */
void exit_critical();


#endif
