/**
 * @file trap_dispatch.c
 * @brief
 * Source file for Sail Trap dispatch
 *
 *        Copyright (c) 2023 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*===========================================================================

                            EDIT HISTORY FOR FILE

when       who      what, where, why
--------   ---     ------------------------------------------------------------

=============================================================================*/


/*===========================================================================
                               INCLUDE FILES
===========================================================================*/
#include "types.h"
#include "el2_types.h"
#include "el2_asm.h"
#include "errno.h"
#include "common_functions.h"
#include "err_fatal.h"
#include "debug_log.h"
#include "exception_events.h"
#include "cache_ops.h"
#include "barrier.h"

/*===========================================================================
                                VARIABLES
============================================================================*/
extern volatile uint32_t ulabort_flag[4];

/*===========================================================================
                                Helper Functions
============================================================================*/
static inline void exception_skip_inst(bool is_il32)
{
	vcpu_general_registers_t* el1_ctxt = exception_core_get_el1_ctxt();
	register_t pc = ELR_EL2_get_ReturnAddress(&el1_ctxt->pc);

	pc += is_il32 ? 4U : 2U;
    ELR_EL2_set_ReturnAddress(&el1_ctxt->pc,pc);
}

 /*===========================================================================
 *								FUNCTIONS
 *===========================================================================*/
// Dispatching of EL1 VMs synchronous exceptions and asynchronous system errors
void exception_dispatch()
{
	ESR_EL2_t   esr	  = register_ESR_EL2_read();
	//FAR_EL2_t   far	  = register_FAR_EL2_read_ordered(&asm_ordering);
	ELR_EL2_t   elr   = register_ELR_HYP_read_ordered(&asm_ordering);
	//HPFAR_EL2_t hpfar = register_HPFAR_EL2_read_ordered(&asm_ordering);

    ESR_EL2_ISS_MCR_MRC_t iss;

	trap_result_t result = TRAP_RESULT_UNHANDLED;
	uint32_t phys_core_id = get_curr_phys_cpu_num();
	esr_ec_t ec	 = ESR_EL2_get_EC(&esr);

	switch (ec) {
	case ESR_EC_UNKNOWN		:
	case ESR_EC_WFIWFE		:
	case ESR_EC_MCRRMRCC15	:
	case ESR_EC_MCRMRC14	:
	case ESR_EC_LDCSTC		:
	case ESR_EC_FPEN 		:
	case ESR_EC_VMRS_EL2 	:
	case ESR_EC_MRRC14 		:
	case ESR_EC_ILLEGAL 	:
	case ESR_EC_SVC32 		:
	case ESR_EC_HVC32_EL2 	:
	case ESR_EC_SMC32_EL2 	:
	case ESR_EC_INST_ABT_LO :
	case ESR_EC_INST_ABT 	:
	case ESR_EC_PC_ALIGN 	:
	case ESR_EC_DATA_ABT_LO :
	case ESR_EC_DATA_ABT 	:
		//We are not handling any of these exceptions.
		//Expand corresponding EC case as needed.
		break;
	case ESR_EC_MCRMRC15	:
		iss = ESR_EL2_ISS_MCR_MRC_cast(ESR_EL2_get_ISS(&esr));
		if(ESR_EL2_ISS_MCR_MRC_get_Direction(&iss) ) {
			result = trigger_trap_coproc_reg_read_event(iss);
		}
		else {
			result = trigger_trap_coproc_reg_write_event(iss);
		}
        break;
	default:
		LOG_ERROR("Unknown trap EC from the Guest VM");
		err_fatal(EL_ENTRY,ERR_FATAL_UNKNOWN_EXCEPTION);
        break; //Should not reach here anyways 
	}

	switch (result) {
	case TRAP_RESULT_UNHANDLED:
	case TRAP_RESULT_FAULT:
        LOG_ERROR("Unhandled trap from EL1, ESR_EL2 = {0x%08X}, "
                "ELR_HYP = {0x%08X}\n\r", ESR_EL2_raw(esr),ELR_EL2_raw(elr));
        ulabort_flag[phys_core_id] = 1;
        err_fatal(EL_ENTRY,ERR_FATAL_UNHANDLED_EXCEPTION);
		break;
	case TRAP_RESULT_EMULATED:
		exception_skip_inst(1);
		break;
	case TRAP_RESULT_RETRY:
		// Nothing to do here.
		break;
	}
}




