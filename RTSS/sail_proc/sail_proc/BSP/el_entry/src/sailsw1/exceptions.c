 /**
 * @file exceptions.c
 * @brief
 * Source file for Exception Handlers,
 * Exception abort handlers to collect syndrome register information to log the error and follow the crash sequence
 *
 *        Copyright (c) 2023 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/

#include "types.h"
#include "el1_types.h"
#include "el1_asm.h"
#include "err_fatal.h"
#include "debug_log.h"
#include "barrier.h"

volatile uint32_t Current_Lr ;//Stores the address(r14) for the error API ,before it gets corrupt ,as we switch to abort stack

#define EXCEPTION_FUNC __attribute__ ( ( section ( "exception_func" ) ) )
void stack_unwind(void);

EXCEPTION_FUNC static void exception_handler_log_nouart(void);

EXCEPTION_FUNC void EL1_Prefetch_Abort_Exception_Handler(void)
{
	__asm__ volatile( "mov %0, r14\n" : "=r" (Current_Lr) :);
    LOG_INFO("In EL1_Prefetch_Abort_Exception_Handler \n\r"); 
    stack_unwind();
    exception_handler_log_nouart();
    err_fatal(EL1,ERR_FATAL_PREFETCH_ABORT_EXCEPTION);
}

EXCEPTION_FUNC void EL1_Abort_Exception_Handler(void)
{
	__asm__ volatile( "mov %0, r14\n" : "=r" (Current_Lr) :);
    LOG_INFO("In EL1_Abort_Exception_Handler \n\r"); 
    stack_unwind();
    exception_handler_log_nouart();
    err_fatal(EL1,ERR_FATAL_ABORT_EXCEPTION);
}

EXCEPTION_FUNC void EL1_Undefined_Exception_Handler(void)
{
	__asm__ volatile( "mov %0, r14\n" : "=r" (Current_Lr) :);
    LOG_INFO("In EL1_Undefined_Exception_Handler \n\r"); 
    stack_unwind();
    exception_handler_log_nouart();
    err_fatal(EL1,ERR_FATAL_UNDEF_EXCEPTION);
}

EXCEPTION_FUNC static void exception_handler_log_nouart(void){
    IFSR_EL1_t   ifsr	  = register_IFSR_EL1_read();
    DFSR_EL1_t   dfsr	  = register_DFSR_EL1_read();
    IFAR_EL1_t   ifar	  = register_IFAR_EL1_read();
    DFAR_EL1_t   dfar	  = register_DFAR_EL1_read();
    SPSR_EL1_A32_t spsr_svc = register_SPSR_SVC_EL1_read();
    LOG_INFO(" SPSR_SVC = {%x}\n\r", SPSR_EL1_raw(spsr_svc));
    LOG_INFO(" IFSR_EL1 = {%x}\n\r", IFSR_EL1_raw(ifsr));   
    LOG_INFO(" DFSR_EL1 = {%x}\n\r", DFSR_EL1_raw(dfsr));   
    LOG_INFO(" IFAR_EL1 = {%x}\n\r", IFAR_EL1_raw(ifar)); 
    LOG_INFO(" DFAR_EL1 = {%x}\n\r", DFAR_EL1_raw(dfar));    
}

