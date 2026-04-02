/**************************************************************************************************
** Copyright (c) 2023 Qualcomm Technologies, Inc.                                                **
** All Rights Reserved.                                                                          **
** Confidential and Proprietary - Qualcomm Technologies, Inc.                                    **
**************************************************************************************************/

/*=================================================================================================
    File Name          : commonClient.c
    Component Name     : clock
    Description        : Common client for System Calls defined in this file
    $Header:  $
    $DateTime:  $
    $Author:  $
=================================================================================================*/

/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/
#include "stdbool.h"
#include "stdint.h"
#include "types.h"
#include "syscall_svc.h"
#include "syscall_hvc.h"
#include "syscall_pub.h"
#include "syscall.h"
#include "err_fatal.h"
#include "cache_ops.h"
#include "hw_io.h"
#include "sail_csr_hwio.h"
#include "msmhwiobase.h"
#include "commonClient.h"
#include "errno.h"

/* SYS CALL DECLARATIONS */
SAIL_DEFINE_SYSCALL(BOOTCFG_GET_MDBIST_CORE_HVC_ID,
                    BOOTCFG_GET_MDBIST_CORE_PARAM_ID,
                    0,
                    SYSCALL_BOOTCFG_GET_MDBIST_CORE);

uint32_t SYSCALL_BOOTCFG_GET_MDBIST_CORE(sailbsp_svc_rsp_t *rsp)
{
  uint8_t rsp_data = bootcfg_getMDBIST_core();

  if (rsp_data != 0U)
  {
      rsp->data[0] = rsp_data;
  }  
  return ((uint32_t)SVC_SUCCESS);
}

void invalidate_dcache_by_addr_syscall( uint32 addr )
{
    uint32_t hvcId     = CACHE_INV_DATA_ADD_HVC_ID;
    uint32_t paramId   = CACHE_INV_DATA_ADD_PARAM_ID;
    uint32_t arg1      = (uint32_t)addr;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        invalidate_dcache_by_addr(addr);
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(COMMON_SRC, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
}

void clean_dcache_by_range_syscall( uint32 addr1, uint32 addr2 )
{
    uint32_t hvcId     = CACHE_CLEAN_DATA_RANGE_HVC_ID;
    uint32_t paramId   = CACHE_CLEAN_DATA_RANGE_PARAM_ID;
    uint32_t arg1      = (uint32_t)addr1;
    uint32_t arg2      = (uint32_t)addr2;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        clean_dcache_by_range(addr1, addr2);
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(COMMON_SRC, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
}

void inval_dcache_by_range_syscall( uint32 addr1, uint32 addr2 )
{
    uint32_t hvcId     = CACHE_INV_DATA_RANGE_HVC_ID;
    uint32_t paramId   = CACHE_INV_DATA_RANGE_PARAM_ID;
    uint32_t arg1      = (uint32_t)addr1;
    uint32_t arg2      = (uint32_t)addr2;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        invalidate_dcache_by_range(addr1, addr2);
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(COMMON_SRC, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
}

void clean_inval_cache_range_syscall( uint32 addr1, uint32 addr2 )
{
    uint32_t hvcId     = CACHE_CLEAN_INV_DATA_RANGE_HVC_ID;
    uint32_t paramId   = CACHE_CLEAN_INV_DATA_RANGE_PARAM_ID;
    uint32_t arg1      = (uint32_t)addr1;
    uint32_t arg2      = (uint32_t)addr2;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        clean_invalidate_cache_by_range(addr1, addr2);
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(COMMON_SRC, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
}

uint8_t bootcfg_getMDBIST_core(void){
    uint32_t hvcId     = BOOTCFG_GET_MDBIST_CORE_HVC_ID;
    uint32_t paramId   = BOOTCFG_GET_MDBIST_CORE_PARAM_ID;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    uint8_t MDBIST_core = 0x0U;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( (int) HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
        	err_fatal(BIST, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( (int) SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(BIST, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
    
    MDBIST_core = paramId;

  return MDBIST_core;
}

/*===========================================================================
**  Function :  IsClusterInLockStepMode
** ==========================================================================
*/
/*!
*
* @brief
*   This function to check if a particular cluster is in lockstep
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/

uint8 IsClusterInLockStepMode ( uint8 cluster_num )
{

    uint32_t hvcId     = (uint32_t)GET_CLUSTER_CONFIG;
    uint32_t paramId   = (uint32_t)GET_CLUSTER_CONFIG_PARM_ID;
    uint32_t arg1      = (uint32_t) cluster_num;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( (int) HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
                err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
            }
        }
    else
    {
        if ( (int) SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
    
    return (uint8) paramId;

}

/*===========================================================================
**  Function :  SAILbspACGVSysCallHandler
** ==========================================================================
*/
/*!
*
* @brief
*   This function triggers the golden CRC calculation of MSA RG for SAIL AC EL2
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/
void SAILbspACGVSysCallHandler(void)
{
    uint32_t hvcId     = SAIL_AC_GV_TRIGGER_HVC_ID;
    uint32_t paramId   = SAIL_AC_GV_TRIGGER_PARAM_ID;
    uint32_t arg1      = (uint32_t)0U;
    uint32_t arg2      = 0U;
    uint32_t arg3      = 0U;
    uint32_t arg4      = 0U;
	
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != (HVCErrnoType)hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(SECURITY_AC, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    return;
}

/*===========================================================================
**  Function :  vBISTData
** ==========================================================================
*/
/*!
*
* @brief
*   This function to get BIST Info
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/

int vBISTData ( BISTData *pData )
{
    if ( NULL == pData  )
    {
        return E_BAD_ADDRESS ;
    }

    pData->mbist_started =  REG_IN(SAILSS_CSR_SAILSS_CSR_BASE,SAILSS_CSR_HBCU_BIST_STATUS_MBIST_STARTED);
    pData->mbist_done = REG_IN(SAILSS_CSR_SAILSS_CSR_BASE,SAILSS_CSR_HBCU_BIST_STATUS_MBIST_DONE);
    pData->mbist_pass = REG_IN(SAILSS_CSR_SAILSS_CSR_BASE,SAILSS_CSR_HBCU_BIST_STATUS_MBIST_PASS);
 
    pData->lbist_started = REG_IN(SAILSS_CSR_SAILSS_CSR_BASE,SAILSS_CSR_HBCU_BIST_STATUS_LBIST_STARTED);
    pData->lbist_done = REG_IN(SAILSS_CSR_SAILSS_CSR_BASE,SAILSS_CSR_HBCU_BIST_STATUS_LBIST_DONE);
    pData->lbist_pass = REG_IN(SAILSS_CSR_SAILSS_CSR_BASE,SAILSS_CSR_HBCU_BIST_STATUS_LBIST_PASS);


    return E_SUCCESS;
}