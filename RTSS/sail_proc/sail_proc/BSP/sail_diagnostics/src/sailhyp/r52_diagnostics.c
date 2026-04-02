/**
 * @file r52_diagnostics.c
 * @brief Sail R52 diagnostics 
 * Source file for the definition of R52 diagnostics API
 *
 *        Copyright (c) 2021 -2022 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
*/


/*===========================================================================

                            EDIT HISTORY FOR FILE

when       who      what, where, why
--------   ---     ------------------------------------------------------------
08.04.22   pmdonthi       Created
=============================================================================*/

#include <stdlib.h>
#include <stdio.h>
#include "sail_csr_hwio.h"
#include "HALhwio.h"
#include "sail_security_control_hwio.h"
#include "hw_io.h"
#include "boot_utils_config.h"
#include "boot.h"
#include "debug_log.h"
#include "r52_diagnostics.h"
#include "common_functions.h"
#include "arm_acle.h"

int ecc_enable_check(void)
{
	int ecc_status = 0;

	if (((uint32)0 == get_curr_cluster_num()))
	{
		if (HWIO_INF(SAILSS_CSR_RTCU_CLUSTER0_CONFIG0, CFGRAMPROTEN) != ECC_ENABLE_CHECK_BIT)
		{
			ecc_status = 1;
			goto ecc_enable_check_end;
		}
	}
	else
	{
		if (HWIO_INF(SAILSS_CSR_RTCU_CLUSTER1_CONFIG0, CFGRAMPROTEN) != ECC_ENABLE_CHECK_BIT)
		{
			ecc_status = 1;
			goto ecc_enable_check_end;
		}
	}

ecc_enable_check_end:
	return ecc_status;
}

int bus_protection_check(void)
{
	int bus_status = 0;

	uint32_t val;
	val = (uint32)__arm_mrc(15, 0, 15, 2, 0); //read BUS_PROTECTION bit in IMP_BUILDOPTR register

	if ((val & BUS_PROTECTION_CHECK) != BUS_PROTECTION_ENABLED)
	{
		bus_status = 1;
	}

	return bus_status;
}

int selfhosted_dbgr_disablement(void)
{
	int dbg_status = 0;

	uint32_t val;
	val = (uint32)__arm_mrc(15, 4, 1, 1, 1); //read the value of the TDE bit in HDCR register

	if ((val & TDE_BIT_CHECK) != TDE_BIT_CHECK)
	{
		//set the TDE bit to 1
		val |= TDE_BIT_CHECK;
		(void)__arm_mcr(15, 4, val, 1, 1, 1);

		val = (uint32)__arm_mrc(15, 4, 1, 1, 1);
		if ((val & TDE_BIT_CHECK) != TDE_BIT_CHECK)
		{
			dbg_status = 1;
		}
	}

	return dbg_status;
}

int r52_diagnostics(void)
{
	int r52_status = 0;
	uint32_t cluster_config = 0;
	volatile uint32_t ulReadVal1 = 0, ulReadVal2 = 0, ulReadVal3 = 0;
	MemErrAggrTestStats_e ulTestStatus3 = MEM_ERRAGGR_FAIL;
	ComparatorTestStats_e ulTestStatus1 = COMP_ERRINJ_FAIL, ulTestStatus2 = COMP_ERRINJ_FAIL;

	r52_status = ecc_enable_check();
	if (r52_status != 0)
	{
		DEBUG_LOG(SAIL_ERROR, "ECC on TCMs not enabled FAILED \r\n");
		r52_status = (int)MEM_ERRAGGR_FAIL;
		goto r52_diagnostics_end;
	}
	DEBUG_LOG(SAIL_INFO, "ECC on TCMs are enabled \r\n");

	r52_status = bus_protection_check();
	if (r52_status != 0)
	{
		DEBUG_LOG(SAIL_ERROR, "Bus protection from R52 to its slaves NOT enabled \r\n");
		r52_status = (int)MEM_ERRAGGR_FAIL;
		goto r52_diagnostics_end;
	}
	DEBUG_LOG(SAIL_INFO, "Bus protection from R52 to its slaves enabled \r\n");

	r52_status = selfhosted_dbgr_disablement();
	if (r52_status != 0)
	{
		DEBUG_LOG(SAIL_ERROR, "Self hosted debugger disablement FAILED \r\n");
		r52_status = (int)MEM_ERRAGGR_FAIL;
		goto r52_diagnostics_end;
	}
	DEBUG_LOG(SAIL_INFO, "Self hosted debugger disablement PASSED \r\n");
	
	if ((uint32)0 == get_curr_phys_cpu_num())
	{
		/*enable memory error profiler*/
		sailbsp_enable_mem_profiler();
	
	    //Memory error aggregator tests
	    REG_OUT(SAILSS_CSR_SAILSS_CSR_REG_BASE, SAILSS_CSR_RTCU_FAULT_INJECTION, MEM_PROFILER_FAULT_INJ_BITS );
  	    ulReadVal3 = 0U;
	    while((ulReadVal3 & 0x00FF0000U) != MEM_PROFILER_FAULT_DETECTION_BITS) /* Mem error aggregators 0, 1, 2 and 3 errors */
	    {
			ulReadVal3 = REG_IN(SAILSS_CSR_SAILSS_CSR_REG_BASE, SAILSS_CSR_FUSA_ERROR_STATUS_4);
	    }
	    ulTestStatus3 = MEM_ERRAGGR_PASS;
	
	    if(ulTestStatus3 == MEM_ERRAGGR_PASS)
	    {
			DEBUG_LOG( SAIL_WARNING,"Memory error aggregator Error Injection PASSED \r\n");
			REG_OUT(SAILSS_CSR_SAILSS_CSR_REG_BASE, SAILSS_CSR_FUSA_ERROR_STATUS_4, MEM_PROFILER_FAULT_DETECTION_BITS);
	    }
	    else
	    {
			DEBUG_LOG( SAIL_ERROR,"Memory error aggregator Error Injection FAILED \r\n");
		    r52_status = (int)MEM_ERRAGGR_FAIL;
			goto r52_diagnostics_end;
	    }
	}
	
	//enable comparator if cluster is in lockstep mode
    sailbsp_enable_comparator();

	//to check if lockstep is enabled
	cluster_config = REG_INF(SAILSS_SECURITY_CONTROL_SAIL_SECURITY_CONTROL_BASE, SAILSS_SECURITY_CONTROL_CAPT_SEC_GPIO, CLUSTER_CONFIG_GPIO);
	
	if (((uint32)1 == (cluster_config & (uint32)1)) && ((uint32)0 == get_curr_cluster_num()))
	{
		//comparator error injection tests: CLUSTER 0
	    REG_OUT(SAILSS_CSR_SAILSS_CSR_REG_BASE, SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_FRC, COMPARATOR_FAULT_INJ_BITS );
  	    ulReadVal1 = 0U;
	    while(ulReadVal1 != COMPARATOR_FAULT_DETECTION_BITS)
	    {
		    ulReadVal1 = REG_IN(SAILSS_CSR_SAILSS_CSR_REG_BASE, SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME);
	    }
	    ulTestStatus1 = COMP_ERRINJ_PASS;
	    REG_OUT(SAILSS_CSR_SAILSS_CSR_REG_BASE, SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME_CLEAR , 0xFF );
	
	    REG_OUT(SAILSS_CSR_SAILSS_CSR_REG_BASE, SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_FRC, 0x00 );
	    REG_OUT(SAILSS_CSR_SAILSS_CSR_REG_BASE, SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME_CLEAR , 0xFF );
		REG_OUT(SAILSS_CSR_SAILSS_CSR_REG_BASE, SAILSS_CSR_FUSA_ERROR_STATUS_2, COMPARATOR_CLUSTER_0_FUSA_CLEAR_BITS);
	
	    if(ulTestStatus1 == COMP_ERRINJ_PASS)
	    {
		    DEBUG_LOG( SAIL_WARNING,"Cluster-0 comparators Error Injection PASSED \r\n");
	    }
	    else
	    {
		    DEBUG_LOG( SAIL_ERROR,"Cluster-0 comparators Error Injection FAILED \r\n");
		    r52_status = (int)COMP_ERRINJ_FAIL;
			goto r52_diagnostics_end;
	    }
	}
	else if(((uint32)2 == (cluster_config & (uint32)2)) && ((uint32)1 == get_curr_cluster_num()))
	{
		//comparator error injection tests: CLUSTER 1
	    REG_OUT(SAILSS_CSR_SAILSS_CSR_REG_BASE, SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_FRC, COMPARATOR_FAULT_INJ_BITS );
  	    ulReadVal2 = 0U;
	    while(ulReadVal2 != COMPARATOR_FAULT_DETECTION_BITS)
	    {
		    ulReadVal2 = REG_IN(SAILSS_CSR_SAILSS_CSR_REG_BASE, SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME);
	    }
	    ulTestStatus2 = COMP_ERRINJ_PASS;
	    REG_OUT(SAILSS_CSR_SAILSS_CSR_REG_BASE, SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME_CLEAR , 0xFF );
	
	    REG_OUT(SAILSS_CSR_SAILSS_CSR_REG_BASE, SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_FRC, 0x00 );
	    REG_OUT(SAILSS_CSR_SAILSS_CSR_REG_BASE, SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME_CLEAR , 0xFF );
		REG_OUT(SAILSS_CSR_SAILSS_CSR_REG_BASE, SAILSS_CSR_FUSA_ERROR_STATUS_3, COMPARATOR_CLUSTER_1_FUSA_CLEAR_BITS);
	
	    if(ulTestStatus2 == COMP_ERRINJ_PASS)
	    {
		    DEBUG_LOG( SAIL_WARNING,"Cluster-1 comparators Error Injection PASSED \r\n");
	    }
	    else
	    {
		    DEBUG_LOG( SAIL_ERROR,"Cluster-1 comparators Error Injection FAILED \r\n");
		    r52_status = (int)COMP_ERRINJ_FAIL;
			goto r52_diagnostics_end;
	    }
	}
	else
	{
		DEBUG_LOG( SAIL_WARNING,"Comparator tests not performed as lockstep mode is not enabled \r\n");
	}
	
r52_diagnostics_end:
	return r52_status;
}
