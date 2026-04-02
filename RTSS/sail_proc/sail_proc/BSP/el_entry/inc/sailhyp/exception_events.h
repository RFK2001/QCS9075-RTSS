/**
 * @file ipcc_gic.c
 * @brief
 * Source file for Event Routers which handle the Sync Exception traps into EL2.
 
 *        Copyright (c) 2022 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/

/*============================================================================
 *                              Include Files
 *============================================================================*/
#include "el2_types.h"

 /*===========================================================================
                                DEFINES
============================================================================*/ 
 
 /*===========================================================================
                                VARIABLES
============================================================================*/ 
 

 /*===========================================================================
                                FUNCTIONS
============================================================================*/ 
//Context for EL1 on a given core.
vcpu_general_registers_t* exception_core_get_el1_ctxt(void) ;

//Event router for all Trap Events related to Co Processor Read Events.
trap_result_t trigger_trap_coproc_reg_read_event(ESR_EL2_ISS_MCR_MRC_t iss);

//Event router for all Trap Events related to Co Processor Write Events.
trap_result_t trigger_trap_coproc_reg_write_event(ESR_EL2_ISS_MCR_MRC_t iss);
