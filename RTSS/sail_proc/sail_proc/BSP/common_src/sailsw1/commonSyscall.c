/**************************************************************************************************
** Copyright (c) 2023 Qualcomm Technologies, Inc.                                                **
** All Rights Reserved.                                                                          **
** Confidential and Proprietary - Qualcomm Technologies, Inc.                                    **
**************************************************************************************************/

/*=================================================================================================
    File Name          : commonSyscall.c
    Component Name     : clock
    Description        : Common System Calls defined in this file
    $Header:  $
    $DateTime:  $
    $Author:  $
=================================================================================================*/

/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/
#include <stdlib.h>
#include <stdio.h>
#include "syscall_pub.h"
#include "syscall.h"
#include "types.h"
#include "cache_ops.h"
#include "commonClient.h"

extern uint8 IsClusterInLockStepMode ( uint8 cluster_num );
/* =========================================================================
**  Function : Syscall_invalidate_dcache_by_addr
** =========================================================================*/
/**
  This function execute cache invalidate by add

  @param

  @return
  SVC_SUCCESS

  @dependencies
  None.
*/
uint32 Syscall_invalidate_dcache_by_addr( uint32_t addr, sailbsp_svc_rsp_t *rsp )
{
    /* rsp->data[0] return clock result */
    invalidate_dcache_by_addr(addr);

    return SVC_SUCCESS;
}

/* =========================================================================
**  Function : Syscall_clean_dcache_by_range
** =========================================================================*/
/**
  This function execute cache Flush by Range

  @param

  @return
  SVC_SUCCESS

  @dependencies
  None.
*/
uint32 Syscall_clean_dcache_by_range( uint32_t addr1, uint32_t addr2, sailbsp_svc_rsp_t *rsp )
{
    /* rsp->data[0] return clock result */
    clean_dcache_by_range(addr1, addr2);

    return SVC_SUCCESS;
}

/* =========================================================================
**  Function : Syscall_invalidate_dcache_by_range
** =========================================================================*/
/**
  This function execute cache Invalidate by Range

  @param

  @return
  SVC_SUCCESS

  @dependencies
  None.
*/
uint32 Syscall_invalidate_dcache_by_range( uint32_t addr1, uint32_t addr2, sailbsp_svc_rsp_t *rsp )
{
    /* rsp->data[0] return clock result */
    invalidate_dcache_by_range(addr1, addr2);

    return SVC_SUCCESS;
}

/* =========================================================================
**  Function : Syscall_clean_invalidate_cache_by_range
** =========================================================================*/
/**
  This function execute cache Flush and Invalidate by Range

  @param

  @return
  SVC_SUCCESS

  @dependencies
  None.
*/
uint32 Syscall_clean_invalidate_cache_by_range( uint32_t addr1, uint32_t addr2, sailbsp_svc_rsp_t *rsp )
{
    /* rsp->data[0] return clock result */
    clean_invalidate_cache_by_range(addr1, addr2);

    return SVC_SUCCESS;
}

/* =========================================================================
**  Function : SysCall_IsClusterInLockStepMode
** =========================================================================*/
/**
  This function will return True if current cluster is in lock step mode

  @param

  @return
  SVC_SUCCESS

  @dependencies
  None.
*/

uint32 SysCall_IsClusterInLockStepMode(uint32 cluster_num, sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) IsClusterInLockStepMode ((uint8)cluster_num);

    return (uint32) SVC_SUCCESS;
}

/* =========================================================================
**  Function : Syscall_read_mpidr
** =========================================================================*/
/**
  helper function to read mpidr register

  @param

  @return
  SVC_SUCCESS

  @dependencies
  None.
*/

uint32 Syscall_read_mpidr(sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = (uint32)__arm_mrc(15, 0, 0, 0, 5);

    return (uint32) SVC_SUCCESS;
}
/*
 * uint32 ClockSyscall_SleepExit ( sailbsp_svc_rsp_t *rsp )
 */

SAIL_DEFINE_SYSCALL( GET_CLUSTER_CONFIG,
                     GET_CLUSTER_CONFIG_PARM_ID,
                     0,
                     SysCall_IsClusterInLockStepMode );

SAIL_DEFINE_SYSCALL( CACHE_INV_DATA_ADD_HVC_ID,
                     CACHE_INV_DATA_ADD_PARAM_ID,
                     0,
                     Syscall_invalidate_dcache_by_addr );

SAIL_DEFINE_SYSCALL( CACHE_CLEAN_DATA_RANGE_HVC_ID,
                     CACHE_CLEAN_DATA_RANGE_PARAM_ID,
                     0,
                     Syscall_clean_dcache_by_range );

SAIL_DEFINE_SYSCALL( CACHE_INV_DATA_RANGE_HVC_ID,
                     CACHE_INV_DATA_RANGE_PARAM_ID,
                     0,
                     Syscall_invalidate_dcache_by_range );

SAIL_DEFINE_SYSCALL( CACHE_CLEAN_INV_DATA_RANGE_HVC_ID,
                     CACHE_CLEAN_INV_DATA_RANGE_PARAM_ID,
                     0,
                     Syscall_clean_invalidate_cache_by_range );
SAIL_DEFINE_SYSCALL( SAIL_READ_MPIDR,
                     SAIL_READ_MPIDR_PARAM_ID,
                     0,
                     Syscall_read_mpidr );
