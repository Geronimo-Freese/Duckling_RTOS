/**
 * @file  port.h
 * @brief architecure specific functionality
 *        - context switch
 *        - memory allocation (stack)
 *        - interrupts
 */


#ifndef PORT_H
#define PORT_H

typedef unsigned long reg;

typedef struct registers registers;
struct registers {
  reg r0;
  reg r1;
  reg r2;
  reg r3;
  reg r4;
  reg r5;
  reg r6;
  reg r7;
  reg r8;
  reg r9;
  reg r10;
  reg r11;
  reg r12;
  reg sp;
  reg lr;
  reg pc;
  reg psr;
  reg primask;
  reg faultmask;
  reg basepri;
  reg control;
};

#endif
