/**
 * @file coproc_registers.h
 * @brief Co Processor  Register Encoding
 * This list is not exhaustive, it contains mostly registers likely to be
 * trapped and accessed indirectly.
 *
 *        Copyright (c) 2022 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
*/


/*===========================================================================

                            EDIT HISTORY FOR FILE

when       who      what, where, why
--------   ---     ------------------------------------------------------------
10.07.22   rrahul       Created
=============================================================================*/

#ifndef COPROC_REGISTERS_H
#define COPROC_REGISTERS_H

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include "el2_types.h"
#include "types.h"

/*===========================================================================
                           DEFINITION OF EL2 Co Processor registers AArch32
===========================================================================*/
#define ISS_OPC2_OPC1_CRN_CRM(opc2,opc1,crn,crm)              \
		(uint32_t)(((7U & (uint32_t)(opc2)) << 17) | \
				   ((7U & (uint32_t)(opc1)) << 14) | \
				   ((15U & (uint32_t)(crn)) << 10) | \
				   ((15U & (uint32_t)(crm)) << 1))



		   
/*===========================================================================
                            MACROS
===========================================================================*/


//GIC System Registers used ince virtualiation is enabled.
#define ISS_MCR_MRC_ICV_PMR	     ISS_OPC2_OPC1_CRN_CRM(0, 0, 4, 6)
#define ISS_MCR_MRC_ICV_IAR0     ISS_OPC2_OPC1_CRN_CRM(0, 0,12, 8)
#define ISS_MCR_MRC_ICV_EOIR0    ISS_OPC2_OPC1_CRN_CRM(1, 0,12, 8)
#define ISS_MCR_MRC_ICV_HPPIR0   ISS_OPC2_OPC1_CRN_CRM(2, 0,12, 8)
#define ISS_MCR_MRC_ICV_BPR0     ISS_OPC2_OPC1_CRN_CRM(3, 0,12, 8)
#define ISS_MCR_MRC_ICV_AP0R0    ISS_OPC2_OPC1_CRN_CRM(4, 0,12, 8)
#define ISS_MCR_MRC_ICV_AP1R0    ISS_OPC2_OPC1_CRN_CRM(0, 0,12, 9)
#define ISS_MCR_MRC_ICV_DIR      ISS_OPC2_OPC1_CRN_CRM(1, 0,12,11)
#define ISS_MCR_MRC_ICV_RPR      ISS_OPC2_OPC1_CRN_CRM(3, 0,12,11)
#define ISS_MCR_MRC_ICV_IAR1	 ISS_OPC2_OPC1_CRN_CRM(0, 0,12,12)
#define ISS_MCR_MRC_ICV_EOIR1    ISS_OPC2_OPC1_CRN_CRM(1, 0,12,12)
#define ISS_MCR_MRC_ICV_HPPIR1   ISS_OPC2_OPC1_CRN_CRM(2, 0,12,12)
#define ISS_MCR_MRC_ICV_BPR1     ISS_OPC2_OPC1_CRN_CRM(3, 0,12,12)
#define ISS_MCR_MRC_ICV_CTLR     ISS_OPC2_OPC1_CRN_CRM(4, 0,12,12)
#define ISS_MCR_MRC_ICV_IGRPEN0  ISS_OPC2_OPC1_CRN_CRM(6, 0,12,12)
#define ISS_MCR_MRC_ICV_IGRPEN1  ISS_OPC2_OPC1_CRN_CRM(7, 0,12,12)

#endif  //COPROC_REGISTERS_H
