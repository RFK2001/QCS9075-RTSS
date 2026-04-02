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
    File Name          : Crashdbg_dcc_hal.h
    Component Name     : SAIL Crash Debug DCC HAL API
    Description        : This module defines hardware layer apis for DCC block.
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/crashdbg/inc/Crashdbg_dcc_hal.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $
=========================================================================================================*/
/* Include header file guard */
#ifndef _CRASHDBG_DCC_HAL_H
#define _CRASHDBG_DCC_HAL_H

/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/
#include "types.h"

/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/
/* Macro to align 'addr' to 'align' number of bytes */
#define ALIGN_ADDR(addr, align)    ((addr + align - 1)&(~(align-1)))

/* Get the word offset for a byte address. DCC requires word index 
 offset everywhere */
#define WORD_INDEX(x)               (x>>2)
#define BYTE_INDEX(x)               (x<<2)

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/
/* Possible Sink types to store the fetched data */
typedef enum
{
  HAL_DCC_SINK_SRAM,
  //HAL_DCC_SINK_ETB,
  HAL_DCC_SINK_MAX,
  HAL_DCC_SINK_INVALID = 0x7FFFFFFF
}hal_dcc_sink_type;

/* Supported functions/operations by DCC */ 
typedef enum
{
 HAL_DCC_FUNC_REG_CAPTURE,
 //HAL_DCC_FUNC_CRC_CAPTURE,
 HAL_DCC_FUNC_MAX,
 HAL_DCC_FUNC_INVALID = 0x7FFFFFFF,
}hal_dcc_func_type;

/* Supported Trigger types */
typedef enum
{
  HAL_DCC_HW_TRIGGER,
  HAL_DCC_TRIGGER_MAX,
}hal_dcc_trig_type;

/* DCC Linked list parameters */
typedef struct
{
  /* timeout value */
  uint32 ntimeout;
  /* per-transaction timeout value */
  uint32 ntranstimeout;  
  /* data offset */
  uint32 noffset;
  /* sink enum */
  hal_dcc_sink_type esink;
  /* func type */
  hal_dcc_func_type efunc;
  /* trigger type */
  hal_dcc_trig_type etrigger;
}hal_dcc_list_params_type;

/*=========================================================================================================
**                          Function declarations										                 **
=========================================================================================================*/
/*===========================================================================
**  HAL_DCC_GET_MAX_LISTS
** ==========================================================================
*/
/*!
*
* @brief
*   Return the max. number of lists supported by this version of DCC
*
* @param[in]
*   None
*
* @par Dependencies
*   None
*
* @retval
*   None
*
* @par Side Effects
*   Mainly used to check against this value
*
*
*/
uint32 hal_dcc_get_max_lists(void);

/*===========================================================================
**  HAL_DCC_GET_SINKBASE
** ==========================================================================
*/
/*!
*
* @brief
*   Return the sink's base address as per system memorymap
*
* @param[in]
*   Sink type
*
* @par Dependencies
*   None
*
* @retval
*   
*
* @par Side Effects
*   Mainly used to check against this value
*
*
*/
uint64 hal_dcc_get_sinkbase(hal_dcc_sink_type);

/*===========================================================================
**  HAL_DCC_GET_DATA_BASE
** ==========================================================================
*/
/*!
*
* @brief
*   API to retrieve the sink's base address within a sink
*
* @param[in]
*   List index
*
* @par Dependencies
*   None
*
* @retval
*   hex number return value
*
* @par Side Effects
*   None
*
*
*/
uint32 hal_dcc_get_database(uint32 list);

/*===========================================================================
**  HAL_DCC_INIT_SINK
** ==========================================================================
*/
/*!
*
* @brief
*   Initialize a given sink for use by DCC driver
*
* @param[in]
*   Sink type
*
* @par Dependencies
*   None
*
* @retval
*  Success or Fail 
*
* @par Side Effects
*   Mainly used to check against this value
*
*
*/
boolean hal_dcc_init_sink(hal_dcc_sink_type sink);

/*===========================================================================
**  HAL_DCC_GET_SINK
** ==========================================================================
*/
/*!
*
* @brief
*   API to retrieve the sink for a list
*
* @param[in]
*   List index
*
* @par Dependencies
*   None
*
* @retval
*   hal_dcc_sink_type return value
*
* @par Side Effects
*   None
*
*
*/
hal_dcc_sink_type hal_dcc_get_sink(uint32 list);


/*===========================================================================
**  Function :  HAL_DCC_CONFIG_LIST_BASE
** ==========================================================================
*/
/*!
* 
* @brief
*   Configures the offset in the sink which houses the linked list. 
*   
* 
* @param[in] 
*       List index, base address
*  
* @par Dependencies
*   None
* 
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*
*/
void hal_dcc_config_list_base(uint32 list, uint32 base);

/*===========================================================================
**  Function :  HAL_DCC_CONFIG_DATA_BASE
** ==========================================================================
*/
/*!
* 
* @brief
*   Configures the offset in the sink which will store the captured data
*   
* 
* @param[in] 
*       List index, base address
*  
* @par Dependencies
*   None
* 
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*
*/

void hal_dcc_config_data_base(uint32 list, uint32 base);

/*===========================================================================
**  Function :  HAL_DCC_CONFIG_TIMEOUT
** ==========================================================================
*/
/*!
* 
* @brief
*   Configures the timeout value for the linked list operation
*   
* 
* @param[in] 
*       List index, timeout value in clock cycles
*  
* @par Dependencies
*   None
* 
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*
*/

void hal_dcc_config_timeout(uint32 list, uint32 timeout);

/*===========================================================================
**  Function :  HAL_DCC_CONFIG_SINK
** ==========================================================================
*/
/*!
* 
* @brief
*   Configures the sink for a given linked list
*   
* 
* @param[in] 
*       List index and sink enum
*  
* @par Dependencies
*   None
* 
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*
*/

void hal_dcc_config_sink(uint32 list, uint32 sink);

/*===========================================================================
**  Function :  HAL_DCC_CONFIG_FUNC
** ==========================================================================
*/
/*!
* 
* @brief
*   Configures the function (register capture or CRC) for a given linked list
*   
* 
* @param[in] 
*       List index and function enum
*  
* @par Dependencies
*   None
* 
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*
*/


void hal_dcc_config_func(uint32 list, uint32 func);

/*===========================================================================
**  HAL_DCC_CONFIG_LIST
** ==========================================================================
*/
/*!
*
* @brief
*   API to program the parameters of a list in one shot
*
* @param[in]
*   List index and pointer to hal params
*
* @par Dependencies
*   None
*
* @retval
*   hal_dcc_sink_type return value
*
* @par Side Effects
*   None
*
*
*/
boolean hal_dcc_config_list(uint32, hal_dcc_list_params_type *);


/*===========================================================================
**  Function :  HAL_DCC_PROGRAM_LIST
** ==========================================================================
*/
/*!
* 
* @brief
*   Configures the function (register capture or CRC) for a given linked list
*   
* 
* @param[in] 
*       List data, list index, offset in the sink and size of the list
*  
* @par Dependencies
*   None
* 
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*
*/


boolean hal_dcc_program_list(void *list, uint32 list_idx, uint32 offset, uint32 size);


/*===========================================================================
**  Function :  HAL_DCC_LOCK_LIST
** ==========================================================================
*/
/*!
* 
* @brief
*   Locks a given linked list for configuration
*   
* 
* @param[in] 
*       List index
*  
* @par Dependencies
*   None
* 
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*
*/

void hal_dcc_lock_list(uint32 list);

/*===========================================================================
**  HAL_DCC_LOCK_LIST_NS
** ==========================================================================
*/
/*!
*
* @brief
*   Lock a list before configuration with NS attributes
*
* @param[in]
*   List index and sink index
*
* @par Dependencies
*   None
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*
*/
void hal_dcc_lock_list_ns(uint32 list);

/*===========================================================================
**  Function :  HAL_DCC_UNLOCK_LIST
** ==========================================================================
*/
/*!
* 
* @brief
*   UnLocks a given linked list for configuration
*   
* 
* @param[in] 
*       List index
*  
* @par Dependencies
*   None
* 
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*
*/

void hal_dcc_unlock_list(uint32 list);

/*===========================================================================
**  Function :  HAL_DCC_IS_LIST_LOCKED
** ==========================================================================
*/
/*!
* 
* @brief
*   Returns lock value for a given list
*   
* 
* @param[in] 
*       List index
*  
* @par Dependencies
*   None
* 
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*
*/

boolean hal_dcc_is_list_locked(uint32 list);

#endif /* _CRASHDBG_DCC_HAL_H */

