#include "include/duckling.h"
#include "include/arch/ports.h"

K_STATUS os_create_process(function_ptr func);


void os_add_process(function_ptr function, PROCESS_PRIORITY priority);


void os_yield(){
//  port_yield();
}


void enter_critical(){
//  port_enter_critical();
}


void exit_critical(){
//  port_exit_critical();
}

