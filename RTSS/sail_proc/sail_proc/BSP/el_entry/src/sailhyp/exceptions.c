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
#include "el2_types.h"
#include "el2_asm.h"
#include "common_functions.h"
#include "err_fatal.h"
#include "debug_log.h"
#include "barrier.h"

extern volatile uint32_t ulabort_flag[4] ;
static void exception_handler_log_nouart(void);

void EL2_Prefetch_Abort_Exception_Handler(void)
{
	uint32_t phys_core_id = get_curr_phys_cpu_num();
	ulabort_flag[phys_core_id] = 1;
    exception_handler_log_nouart();
    err_fatal(EL_ENTRY,ERR_FATAL_EL2_PREFETCH_ABT);
}

void EL2_Abort_Exception_Handler(void)
{
	uint32_t phys_core_id = get_curr_phys_cpu_num();
	ulabort_flag[phys_core_id] = 1;
    exception_handler_log_nouart();
    err_fatal(EL_ENTRY,ERR_FATAL_EL2_DATA_ABT);
}

void EL2_Undefined_Exception_Handler(void)
{
	uint32_t phys_core_id = get_curr_phys_cpu_num();
	ulabort_flag[phys_core_id] = 1;
    exception_handler_log_nouart();
    err_fatal(EL_ENTRY,ERR_FATAL_EL2_UNDEF_ABT);
}

static void exception_handler_log_nouart(void){
    ESR_EL2_t   esr	  = register_ESR_EL2_read();
    ELR_EL2_t   elr   = register_ELR_HYP_read_ordered(&asm_ordering);
    HIFAR_EL2_t   hifar	  = register_HIFAR_EL2_read();
    HDFAR_EL2_t   hdfar	  = register_HDFAR_EL2_read();
    SPSR_EL2_A32_t spsr_hyp = register_SPSR_HYP_EL2_read();
    LOG_INFO(" SPSR_HYP = {%x}\n\r", SPSR_EL2_raw(spsr_hyp));
    LOG_INFO(" ESR_EL2 = {%x}\n\r", ESR_EL2_raw(esr));   
    LOG_INFO(" ELR_HYP = {%x}\n\r", ELR_EL2_raw(elr));
    LOG_INFO(" HDFAR_EL2 = {%x}\n\r", HDFAR_EL2_raw(hdfar));  
    LOG_INFO(" HIFAR_EL2 = {%x}\n\r", HIFAR_EL2_raw(hifar));    
}
