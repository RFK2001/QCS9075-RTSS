/**
 * @file ipcc_gic.c
 * @brief
 * Source file for Interfaces which handle the traps due to Read/Write OPs
 * on Co Processor Registers. Specifically for GIC HW block.
 *
 *        Copyright (c) 2022 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/

/*============================================================================
 *                              Include Files
 *============================================================================*/

#include "arch_ops.h"
#include "target.h"
#include "debug_log.h"
#include "el2_types.h"
#include "common_functions.h"
#include "err_fatal.h"
#include "coproc_registers.h"

 /*===========================================================================
                                DEFINES
============================================================================*/ 
 

 /*===========================================================================
                                VARIABLES
============================================================================*/ 
 //For now just using the GPRs to abstart EL1 context. We can scale it encompass
 //full El1 VM context when needed.
 vcpu_general_registers_t el1_ctxt_gpr[SAILBSP_CPU_COUNT] = {};

 /*===========================================================================
                                FUNCTIONS
============================================================================*/ 
 vcpu_general_registers_t* exception_core_get_el1_ctxt(void);
 
/*============================================================================
            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE
============================================================================*/
static void el1_ctxt_gpr_write(uint8_t reg_num,register_t val){
     //define the saved el1 context and have a means to 
     //point to it when needed and update it here when 
     //requested.	 
	 vcpu_general_registers_t* el1_ctxt = exception_core_get_el1_ctxt();
	 el1_ctxt->x[reg_num] = val;
 }
 
static register_t el1_ctxt_gpr_read(uint8_t reg_num){
	 //define the saved el1 context and have a means to 
     //point to it when needed and read it here when 
     //requested.
	 vcpu_general_registers_t* el1_ctxt = exception_core_get_el1_ctxt();
	 return el1_ctxt->x[reg_num];
}

/*
 *===========================================================================
 *						        Functions
 *===========================================================================
 */
vcpu_general_registers_t* exception_core_get_el1_ctxt(void) {
    uint32_t phys_core_id = get_curr_phys_cpu_num();
    
	return &el1_ctxt_gpr[phys_core_id];
	
}
 
trap_result_t trigger_trap_coproc_reg_read_event(ESR_EL2_ISS_MCR_MRC_t iss)
{
	trap_result_t ret = TRAP_RESULT_EMULATED;
    uint8_t opc2, opc1, crn, crm;
	uint8_t regnum = ESR_EL2_ISS_MCR_MRC_get_Rt(&iss);
	register_t	   val	  = 0ULL; // Default action is RAZ
	
	 //Check this a read operation.
	 if(!ESR_EL2_ISS_MCR_MRC_get_Direction(&iss)){
		 err_fatal(EL_ENTRY,ERR_FATAL_ASSERT_FAILED);
	 }
	
	 // Remove the fields that are not used in the comparison
	 ESR_EL2_ISS_MCR_MRC_set_Direction(&iss,false);
	 ESR_EL2_ISS_MCR_MRC_set_Rt(&iss,0);
	 ESR_EL2_ISS_MCR_MRC_set_COND(&iss,0);  //check if we need this later
	 ESR_EL2_ISS_MCR_MRC_set_CV(&iss,0);    //Check if we need this later

	 switch(ESR_EL2_ISS_MCR_MRC_raw(iss))
	 {
		 case ISS_MCR_MRC_ICV_PMR	 :  
		    val = __arm_mrc(15, 0, 4, 6, 0);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_IAR0   :
			val = __arm_mrc(15, 0, 12, 8, 0);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_EOIR0  :
			val = __arm_mrc(15, 0, 12, 8, 1);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_HPPIR0 :
			val = __arm_mrc(15, 0, 12, 8, 2);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_BPR0   :
			val = __arm_mrc(15, 0, 12, 8, 3);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_AP0R0  :
			val = __arm_mrc(15, 0, 12, 8, 4);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_AP1R0  :
			val = __arm_mrc(15, 0, 12, 9, 0);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_DIR    :
			val = __arm_mrc(15, 0, 12, 11, 1);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_RPR    :
			val = __arm_mrc(15, 0, 12, 11, 3);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_IAR1	 :
			val = __arm_mrc(15, 0, 12, 12, 0);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_EOIR1  :
			val = __arm_mrc(15, 0, 12, 12, 1);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_HPPIR1 :
			val = __arm_mrc(15, 0, 12, 12, 2);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_BPR1   :
			val = __arm_mrc(15, 0, 12, 12, 3);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_CTLR   :
			val = __arm_mrc(15, 0, 12, 12, 4);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_IGRPEN0:
			val = __arm_mrc(15, 0, 12, 12, 6);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_IGRPEN1:
			val = __arm_mrc(15, 0, 12, 12, 7);
			ISB;
			DSB;
			break;
		default:
			//for now lets do it as RAZ for read ops
			//NA for write ops which we dont support.
			break;
	 }

	// Update the GP register of EL1 context.
    // do we need to define the el1 context to be saved
    // and use that data type to update the said register.	
	if ( ( ret == TRAP_RESULT_EMULATED ) && ( regnum < MAX_CPU_CTX_REG ) ) {
		el1_ctxt_gpr_write( regnum, val);
	}
	
	  /*Enable the fallback option if needed.
	  ret = coproc_reg_read_fallback(iss);
	  if (ret != TRAP_RESULT_UNHANDLED) {
	    goto out;
	  }
      */
	out:
	  return ret;
}
trap_result_t trigger_trap_coproc_reg_write_event(ESR_EL2_ISS_MCR_MRC_t iss)
{
	trap_result_t ret = TRAP_RESULT_EMULATED;
    uint32_t opc2, opc1, crn, crm;
	uint32_t regnum = ESR_EL2_ISS_MCR_MRC_get_Rt(&iss);
	register_t val  = 0;
	
	 //Check this a read operation.
	 if(ESR_EL2_ISS_MCR_MRC_get_Direction(&iss)){
		 err_fatal(EL_ENTRY,ERR_FATAL_ASSERT_FAILED);
	 }

	 // Remove the fields that are not used in the comparison
	 ESR_EL2_ISS_MCR_MRC_set_Direction(&iss,false);
	 ESR_EL2_ISS_MCR_MRC_set_Rt(&iss,0);
	 ESR_EL2_ISS_MCR_MRC_set_COND(&iss,0);  //check if we need this later
	 ESR_EL2_ISS_MCR_MRC_set_CV(&iss,0);    //Check if we need this later
	 if(( regnum < MAX_CPU_CTX_REG ))
	 {
	     val = el1_ctxt_gpr_read(regnum);
	 }
	 else
	 {
	     err_fatal(EL_ENTRY,ERR_FATAL_ASSERT_FAILED);
	 }
	 switch(ESR_EL2_ISS_MCR_MRC_raw(iss))
	 {
	 	case ISS_MCR_MRC_ICV_PMR	 :  
		     __arm_mcr(15, 0, val, 4, 6, 0);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_IAR0   :
			__arm_mcr(15, 0, val, 12, 8, 0);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_EOIR0  :
			__arm_mcr(15, 0, val, 12, 8, 1);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_HPPIR0 :
			__arm_mcr(15, 0, val, 12, 8, 2);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_BPR0   :
			__arm_mcr(15, 0, val, 12, 8, 3);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_AP0R0  :
			__arm_mcr(15, 0, val, 12, 8, 4);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_AP1R0  :
			__arm_mcr(15, 0, val, 12, 9, 0);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_DIR    :
			__arm_mcr(15, 0, val, 12, 11, 1);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_RPR    :
			__arm_mcr(15, 0, val, 12, 11, 3);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_IAR1	 :
			__arm_mcr(15, 0, val, 12, 12, 0);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_EOIR1  :
			__arm_mcr(15, 0, val, 12, 12, 1);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_HPPIR1 :
			__arm_mcr(15, 0, val, 12, 12, 2);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_BPR1   :
			__arm_mcr(15, 0, val, 12, 12, 3);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_CTLR   :
			__arm_mcr(15, 0, val, 12, 12, 4);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_IGRPEN0:
			__arm_mcr(15, 0, val, 12, 12, 6);
			ISB;
			DSB;
			break;
         case ISS_MCR_MRC_ICV_IGRPEN1:
			__arm_mcr(15, 0, val, 12, 12, 7);
			ISB;
			DSB;
			break;
		default:
			//for now lets do it as RAZ for read ops
			//NA for write ops which we dont support.
			break;		 
	 }
	  /*Enable the fallback option if needed.
	  ret = coproc_reg_write_fallback(iss);
	  if (ret != TRAP_RESULT_UNHANDLED) {
	    goto out;
	  }
      */
	out:
	  return ret;
}
