/*
@file debug_err_fatal.c
@brief Misc. error handling routines

*/
 /*        Copyright (c) 2021 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 */


/*===========================================================================
                              Include files
=============================================================================*/
#include "types.h"
#include "cache_ops.h"
#include "err_fatal.h"
#include "busywait.h"
#include "logcode.h"
#include "stack_unwinding.h"
// #include "wdt_freertos.h"


/**
 * @  err_fatal : API for Fatal error cases. This API will either
 wait for WDOG to bite if its enabled. If not it will deassert PS_HOLD.
 */
void __attribute__((noreturn)) err_fatal(MODULE_ID mid,int32_t Error_ID)
{
   //Disable interrupts on this core.
  __asm__ volatile("cpsid  ai");
  ISB;

  if(Error_ID < 0)
  {
    if(mid == SPINOR)
	  Error_ID = Error_ID *(-1) + 1;
    else
	  Error_ID *= -1;

 }
  //LOG_NOUART("SAILBSP Fatal Error. Error Code :%d",err);
  //Capture the backtrace and log it.
  //Check if WDOG has been enabled.
  /*if(is_wdt_enabled())
  {
      do{
          __asm__("wfi");
      }while(1);
  }*/

  
  stack_unwind();
  vLCWriteErrorCode( mid ,get_curr_phys_cpu_num() ,(uint32_t)Error_ID);
  LOG_ERROR("SAILBSP Fatal Error. Module_ID :%d  Error_ID : %d \n\r",mid,Error_ID);
  stack_unwind();

 /* err_fatal() function should never return.*/
  while(1);
}

/**
 * @  err_warning : API for warning error cases. This API will just log the 
 warning and the stack backtrace and continue with the execution.
 */
void  err_warning(sailbsp_err_fatal_e err)
{
  //Disable interrupts on this core.
  uint32_t cpsr_state;
  __asm__ volatile (" mrs %0, cpsr" : "=r" (cpsr_state) :  );
  
  __asm__ volatile("cpsid  aif");
  ISB;
  //log the warning
  // LOG_NOUART("SAILBSP Warning. Error Code :%d",err);
  //Capture the backtrace and log it.

  //restore the aif bits to its orignal state
  __asm__ volatile (" msr cpsr, %0": : "r" (cpsr_state));
}
