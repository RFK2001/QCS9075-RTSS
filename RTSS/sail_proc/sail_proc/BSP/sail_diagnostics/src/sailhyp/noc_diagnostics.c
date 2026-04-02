/**
 * @file noc_diagnostics.c
 * @brief Sail NOC diagnostics
 * Source file for the definition of NOC diagnostics API
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
#include "sail_asild_noc_service_network.h"
#include "sail_asilb_noc_service_network.h"
#include "hw_io.h"
#include "boot.h"
#include "debug_log.h"
#include "common_functions.h"
#include "noc_diagnostics.h"
#include "busywait.h"

int config_sftyctrl_asild_intr(void)
{
	uint32_t ulDone = 0U;
	int j = 10;
	NOCTestStats_e intd_status = NOC_ERRINJ_PASS;
	
	/* Step 1 */
	REG_OUTF(SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK_REG_BASE, SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_BISTCTL_LOW, STOP, 0x1U);
	ulDone = REG_INF(SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK_REG_BASE, SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_STATUS_LOW, DONE);
	
	/* As per QNOC4.8 HPG, if the field returns 1 after more than 10 polls, the functional safety reporting is in a control fault state */
	while(j-- > 0)
	{
		ulDone = REG_INF(SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK_REG_BASE, SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_STATUS_LOW, DONE);
		if(ulDone == 0U)
		{
			break;
		}
	}
	if (j == 0)
	{
		/* FuSa reporting is in a control fault state */
		intd_status = NOC_ERRINJ_FAIL;
		DEBUG_LOG(SAIL_INFO, "Failed to configure safety controlled interrupts: BIST sequence not done \n\r");
	}
	
	/* Step 2 */
	if(intd_status == NOC_ERRINJ_PASS)
	{
	    REG_OUTF(SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK_REG_BASE, SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_OUTEN_LOW, UFLT, 0x1U);
	    REG_OUTF(SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK_REG_BASE, SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_OUTEN_LOW, CFLT, 0x1U);
	    REG_OUTF(SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK_REG_BASE, SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_OUTEN_LOW, DONE, 0x0U);
	}
	
	return (int)intd_status;
}

int NOC_tests_ASIL_D(void)
{
	int i = 0;
	NOCTestStats_e nocd_status = NOC_ERRINJ_PASS;
	uint32_t ulDone = 0U, ulBistflt = 0U, ulUflt = 0U, ulCflt = 0U;
	
	for(i = 0; i <= SAIL_ASIL_D_NOC_FAULT_AGGR ; i++)
	{
		/* Step 1 */
		
		/* Step 2 */
	    REG_OUTF(SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK_REG_BASE, SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_OUTEN_LOW, UFLT, 0x0U);
	    REG_OUTF(SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK_REG_BASE, SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_OUTEN_LOW, CFLT, 0x0U);
	    REG_OUTF(SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK_REG_BASE, SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_OUTEN_LOW, DONE, 0x1U);
	
	    /* Step 3 */
	    REG_OUTF(SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK_REG_BASE, SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_BISTCTL_LOW, AGGREGID, i);
	
	    /* Step 4 */
	    REG_OUTF(SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK_REG_BASE, SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_BISTCTL_LOW, STOP, 0x1U);
	    ulDone = REG_INF(SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK_REG_BASE, SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_STATUS_LOW, DONE);
	
	    if(ulDone != 0U)
	    {
			/* FuSa reporting is in a control fault state */
		    nocd_status = NOC_ERRINJ_FAIL;
		    DEBUG_LOG(SAIL_INFO,"NOC Error injection fail at %d fault aggregator: BIST sequence not done \n\r", i);
			break;
		}
	    ulDone = 0U;
	
	    /* Step 5 and Step 6 */
	    REG_OUTF(SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK_REG_BASE, SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_BISTCTL_LOW, START, 0x1U);
	    ulDone = REG_INF(SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK_REG_BASE, SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_STATUS_LOW, DONE);
		
		if(ulDone != 1U)
		{
			busywait(50);
			ulDone = REG_INF(SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK_REG_BASE, SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_STATUS_LOW, DONE);
			if(ulDone != 1U)
			{
				nocd_status = NOC_ERRINJ_FAIL;
				break;
			}
		}
		
	    /* Step 7 */
	    ulDone = REG_INF(SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK_REG_BASE, SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_STATUS_LOW, DONE);
	    if(ulDone == 0U)
		{
			/* FuSa reporting is in a control fault state */
		    nocd_status = NOC_ERRINJ_FAIL;
		    DEBUG_LOG(SAIL_INFO,"NOC Error injection fail at %d fault aggregator: Done not asserted \n\r", i);
			break;
		}
	
	    ulBistflt = REG_INF(SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK_REG_BASE, SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_STATUS_LOW, BISTFLT);
	    ulUflt = REG_INF(SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK_REG_BASE, SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_STATUS_LOW, UFLT);
	    ulCflt = REG_INF(SAILSS_ASIL_D_ASIL_D_NOC_DEC_SERVICE_NETWORK_REG_BASE, SAILSS_ASIL_D_ASIL_D_NOC_SFTYCTL_STATUS_LOW, CFLT);
	
	    if(ulBistflt == 1U)
		{
			/* BistFIT = 1 case; either UFit or CFit is zero */
		    if(ulUflt == 0U || ulCflt == 0U)
			{
				nocd_status = NOC_ERRINJ_FAIL;
		        DEBUG_LOG(SAIL_INFO,"NOC Error injection fail at %d fault aggregator: aggregator fault occured \n\r", i);
				break;
		    }
		}
	    else if(ulBistflt == 0U)
	    {
			/* BistFIT = 0 case; both UFit or CFit is one*/
		    if(ulUflt == 1U && ulCflt == 1U)
		    {
				/* Reporting is operational and mission mode can be enabled */
			    nocd_status = (NOCTestStats_e)config_sftyctrl_asild_intr();
			    if(nocd_status != NOC_ERRINJ_PASS)
				{
					nocd_status = NOC_ERRINJ_FAIL;
		            DEBUG_LOG(SAIL_INFO,"NOC Error injection fail: failed to configure safety controlled interrupts at %d fault aggregator \n\r", i);
					break;
			    }
		    }
	    }
	    else
		{
			nocd_status = NOC_ERRINJ_FAIL;
		    DEBUG_LOG( SAIL_INFO,"NOC Error injection fail at %d fault aggregator: reporting in control fault state \n\r", i);
			break;
	    }
	}
	
    return (int)nocd_status;
}


int config_sftyctrl_asilb_intr(void)
{
	uint32_t ulDone = 0U;
	int j = 10;
	NOCTestStats_e intb_status = NOC_ERRINJ_PASS;
	
	/* Step 1 */
	REG_OUTF(SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE, SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_BISTCTL_LOW, STOP, 0x1U);
	ulDone = REG_INF(SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE, SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_STATUS_LOW, DONE);
	
	/* As per QNOC4.8 HPG, if the field returns 1 after more than 10 polls, the functional safety reporting is in a control fault state */
	while(j-- > 0)
	{
		ulDone = REG_INF(SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE, SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_STATUS_LOW, DONE);
		if(ulDone == 0U)
		{
			break;
		}
	}
	if (j == 0)
	{
		/* FuSa reporting is in a control fault state */
		intb_status = NOC_ERRINJ_FAIL;
		DEBUG_LOG(SAIL_INFO, "Failed to configure safety controlled interrupts: BIST sequence not done \n\r");
	}
	
	/* Step 2 */
	if(intb_status == NOC_ERRINJ_PASS)
	{
		REG_OUTF(SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE, SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_OUTEN_LOW, UFLT, 0x1U);
	    REG_OUTF(SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE, SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_OUTEN_LOW, CFLT, 0x1U);
	    REG_OUTF(SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE, SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_OUTEN_LOW, DONE, 0x0U);
	}
	
	return (int)intb_status;
}

int NOC_tests_ASIL_B(void)
{
	int i = 0;
	uint32_t ulDone = 0U, ulBistflt = 0U, ulUflt = 0U, ulCflt = 0U;
	NOCTestStats_e nocb_status = NOC_ERRINJ_PASS;
	
	for(i = 0; i <= SAIL_ASIL_B_NOC_FAULT_AGGR ; i++)
	{
		/* Step 1 */

		/* Step 2 */
		REG_OUTF(SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE, SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_OUTEN_LOW, UFLT, 0x0U);
		REG_OUTF(SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE, SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_OUTEN_LOW, CFLT, 0x0U);
		REG_OUTF(SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE, SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_OUTEN_LOW, DONE, 0x1U);

		/* Step 3 */
		REG_OUTF(SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE, SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_BISTCTL_LOW, AGGREGID, i);

		/* Step 4 */
		REG_OUTF(SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE, SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_BISTCTL_LOW, STOP, 0x1U);
		ulDone = REG_INF(SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE, SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_STATUS_LOW, DONE);

		if(ulDone != 0U)
		{
			/* FuSa reporting is in a control fault state */
			nocb_status = NOC_ERRINJ_FAIL;
			DEBUG_LOG(SAIL_INFO,"NOC Error injection fail at %d fault aggregator: BIST sequence not done \n\r", i);
			break;
		}
		ulDone = 0U;

		/* Step 5 and Step 6 */
		REG_OUTF(SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE, SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_BISTCTL_LOW, START, 0x1U);
		ulDone = REG_INF(SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE, SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_STATUS_LOW, DONE);
		
		if(ulDone != 1U)
		{
			busywait(50);
			ulDone = REG_INF(SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE, SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_STATUS_LOW, DONE);
			if(ulDone != 1U)
			{
				nocb_status = NOC_ERRINJ_FAIL;
				break;
			}
		}
		
		/* Step 7 */
		ulDone = REG_INF(SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE, SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_STATUS_LOW, DONE);
		if(ulDone == 0U)
		{
			/* FuSa reporting is in a control fault state */
			nocb_status = NOC_ERRINJ_FAIL;
			DEBUG_LOG(SAIL_INFO,"NOC Error injection fail at %d fault aggregator: Done not asserted \n\r", i);
			break;
		}

		ulBistflt = REG_INF(SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE, SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_STATUS_LOW, BISTFLT);
		ulUflt = REG_INF(SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE, SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_STATUS_LOW, UFLT);
		ulCflt = REG_INF(SAILSS_ASIL_B_SAIL_ASIL_B_NOC_REG_BASE, SAILSS_ASIL_B_ASIL_B_NOC_SFTYCTL_STATUS_LOW, CFLT);

		if(ulBistflt == 1U)
		{
			/* BistFIT = 1 case; either UFit or CFit is zero */
			if(ulUflt == 0U || ulCflt == 0U)
			{
				nocb_status = NOC_ERRINJ_FAIL;
				DEBUG_LOG(SAIL_INFO,"NOC Error injection fail at %d fault aggregator: aggregator fault occured \n\r", i);
				break;
			}
		}
		else if(ulBistflt == 0U)
		{
			/* BistFIT = 0 case; both UFit or CFit is one*/
			if(ulUflt == 1U && ulCflt == 1U)
			{
				/* Reporting is operational and mission mode can be enabled */
				nocb_status = (NOCTestStats_e)config_sftyctrl_asilb_intr();
				if(nocb_status != NOC_ERRINJ_PASS)
				{
					nocb_status = NOC_ERRINJ_FAIL;
					DEBUG_LOG(SAIL_INFO,"NOC Error injection fail: failed to configure safety controlled interrupts at %d fault aggregator \n\r", i);
					break;
				}
			}
		}
		else
		{
			nocb_status = NOC_ERRINJ_FAIL;
			DEBUG_LOG( SAIL_INFO,"NOC Error injection fail at %d fault aggregator: reporting in control fault state \n\r", i);
			break;
		}
	}

    return (int)nocb_status;
}
