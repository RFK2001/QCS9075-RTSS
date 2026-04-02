/**************************************************************************************************
    Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
    All Rights Reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.

    Export of this technology or software is regulated by the U.S. Government.
    Diversion contrary to U.S. law prohibited.

    All ideas, data and information contained in or disclosed by
    this document are confidential and proprietary information of
    Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
    By accepting this material the recipient agrees that this material
    and the information contained therein are held in confidence and in
    trust and will not be used, copied, reproduced in whole or in part,
    nor its contents revealed in any manner to others without the express
    written permission of Qualcomm Technologies, Inc.
**************************************************************************************************/

/*=================================================================================================
    File Name          : commonClient.h
    Component Name     : 
    Description        : Header file for Common clients for System Calls
    $Header: 
    $DateTime: 
    $Author: 
==================================================================================================*/
/* Include header file guard */
#ifndef COMMONCLIENT_H
#define COMMONCLIENT_H

#include <types.h>

typedef struct
{
    uint8 mbist_started;
    uint8 mbist_done;
    uint8 mbist_pass;
    uint8 lbist_started;
    uint8 lbist_done;
    uint8 lbist_pass; 
}BISTData;

/*===========================================================================
**  Function :  bootcfg_getMDBIST_core
** ==========================================================================*/
/*
    This function gets the MDBIST core number from boot configuration 

    @return
	BIST core number.

    @dependencies
    None.
*/
uint8_t bootcfg_getMDBIST_core(void);

/*===========================================================================
**  Function :  read_mpidr_by_syscall
** ==========================================================================
*/
/*!
*
* @brief
*   helper function to read mpidr register
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   return mpidr value.
*
*/

uint32_t read_mpidr_by_syscall ( void );

#ifndef SAILEL2
/*===========================================================================
**  Function :  IsClusterInLockStepMode
** ==========================================================================
*/
/*!
*
* @brief
*   This function to check if particular cluster is in lockstep mode
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/

uint8 IsClusterInLockStepMode ( uint8 cluster_num );


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
void SAILbspACGVSysCallHandler(void);

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

int vBISTData ( BISTData *pData );

#endif
#endif /* COMMONCLIENT_H  */