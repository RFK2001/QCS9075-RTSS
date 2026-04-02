/**********************************************************************************************************
    Copyright (c) 2021 Qualcomm Technologies, Inc.
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
**********************************************************************************************************/

/*=========================================================================================================
    File Name          : Crashdbg_dcc.h
    Component Name     : SAIL Crash Debug DCC driver API
    Description        : This module defines all interfaces exposed by the DCC driver.
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/crashdbg/inc/Crashdbg_dcc.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $
=========================================================================================================*/

/* Include header file guard */
#ifndef _CRASHDBG_DCC_H
#define _CRASHDBG_DCC_H

/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/
#include "types.h"

/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
==========================================================================================================*/
/**
  Sail DCC Sink types
 */
typedef enum
{
  DCC_SINK_SRAM,
  //DCC_SINK_ETB,
  DCC_SINK_MAX,
  DCC_SINK_INVALID = 0x7FFFFFFF
}dcc_sink_type;

/**
  Sail DCC Trigger types
 */
typedef enum
{
  DCC_TRIGGER_SCANDUMP,
  DCC_TRIGGER_WINDDOWN,
  DCC_TRIGGER_MAX,
  DCC_TRIGGER_INVALID = 0x7FFFFFFF
}dcc_trigger_type;

/**
  Sail DCC SRAM configuration to access scan dump data
 */
typedef struct
{
  uint64 start_addr;
  uint32 size;
}dcc_sram_cfg_type;

/**
  Sail DCC configuration of each LL
 */
typedef struct
{
  /* Linked List index */
  const uint32 ll_idx;
  /* Linked List timeout */
  const uint32 ll_timeout;
  const boolean ll_timeout_en;
  /* Linked List per-transaction timeout */
  const uint32 llt_timeout;
  const boolean llt_timeout_en;  
  /* Linked List offset */
  const uint32 ll_offset;
  /* FD start address offset
   * for a given sink */
  const uint32 ll_fd_offset;
  const uint32 ll_fd_size;
  /* Linked list trigger */
  const dcc_trigger_type ll_trigger;
  /* Linked List */
  const void *ll;
  /* Linked List size */
  const uint32 ll_size;
}dcc_ll_config_type;

/**
  Sail DCC configuration
 */
typedef struct
{
  /* DCC Global enable */
  const boolean dcc_en;
  /* Total Memory for all LLs in bytes */
  const uint32 dcc_mem_size;
  /* Type of sink to be used */
  dcc_sink_type sink;
  /* Apps PC information */
  dcc_trigger_type pc_trigger;
  /* Apps PC offset within the LL */
  uint32 pc_offset;
  /* Size of each PC entry (per core)
   * in bytes */
  uint32 pc_size;
  /* How many PCs are saved */
  uint32 pc_count;
}dcc_config_type;

/* Linked List entry type that will be generated and programmed into DCC SRAM */
typedef uint32 dcc_ll_entry_type;

/*===========================================================================
** 	Function: CrashdbgDCCInit
** ==========================================================================
*/
/*!
* 
* @brief
*	Top Level Function which performs DCC initialization
*
* @param[in] 
*	None
*  
* @par Dependencies
*	None
* 
* @retval
*   None
* 
* @par Side Effects
*	Must be called only after global struct is initialized
*/
boolean CrashdbgDCCInit(void);


/*===========================================================================
** 	Function: CrashdbgDCCRetrieveCfg
** ==========================================================================
*/
/*!
* 
* @brief
*	Top Level function to retrieve DCC SRAM start address and size for a particular
*	list based on trigger
*
* @param[in] 
*	Trigger used for the DCC linked list. 
*  
* @par Dependencies
*	None
* 
* @retval
*   None
* 
* @par Side Effects
*	Must be called only after global struct is initialized
*/

boolean CrashdbgDCCRetrieveCfg(dcc_trigger_type trigger, dcc_sram_cfg_type *cfg);

/*===========================================================================
**  Function: CrashdbgDCCRetrievePC
** ==========================================================================
*/
/*!
* 
* @brief
* Top Level function to retrieve PC information when entering debug flow
*
* @param[in] 
* Core for which the PC is required 
*  
* @par Dependencies
* None
* 
* @retval
*   None
* 
* @par Side Effects
*   Depends on static information being configured correctly.
*/
uint64 CrashdbgDCCRetrievePC(uint32 core);

#endif /* _CRASHDBG_DCC_H */ 
