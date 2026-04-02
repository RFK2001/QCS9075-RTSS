/*
    ===========================================================================

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

    ===========================================================================

    $Header:   $
    $DateTime:  $
    $Author:   $

    ===========================================================================
*/
/* Can Pre-Compile Configuration Header file *//******************************************************************************/
/**
* AUTOMATICALLY GENERATED FILE. DO NOT EDIT.   
* GENERATED ON : Tue Jun 18 21:04:07 IST 2024           
* 
* file: Can_Cfg.h
*
* Description: This is a CAN Pre-Compile configuration Header file for CAN 
*              Module.
*
* <pre>
*
* MODIFICATION HISTORY:
*
* Ver   Who    Date          Changes
* ----- ----  --------   ----------------------------------------------------
* </pre>
*
*******************************************************************************/
#ifndef CAN_CFG_H
#define CAN_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

#ifndef CAN_PLT_SAFERTOS_ENABLE
#include "Os.h"
#endif /* End of CAN_PLT_SAFERTOS_ENABLE*/

/*******************************************************************************
**                      EXPORTED CONSTANTS and MACROS                         **
*******************************************************************************/
/* [SWS_BSW_00059] Published information elements. */
#define CAN_VENDOR_ID_CFG_H   184u
#define CAN_MODULE_ID_CFG_H   80u

#define CAN_AR_RELEASE_MAJOR_VERSION_CFG_H     4u
#define CAN_AR_RELEASE_MINOR_VERSION_CFG_H     8u
#define CAN_AR_RELEASE_REVISION_VERSION_CFG_H  0u

#define CAN_SW_MAJOR_VERSION_CFG_H     1u
#define CAN_SW_MINOR_VERSION_CFG_H     0u
#define CAN_SW_PATCH_VERSION_CFG_H     0u


#define CAN_VARIANT_POST_BUILD


/* Pre-compile option for DET Check */
#define CAN_DEV_ERROR_DETECT            STD_ON

#define CAN_CFG_INSTANCE_ID                 0u

#define CAN_HW_OBJ_0    0u
#define CAN_HW_OBJ_1    1u
#define CAN_HW_OBJ_2    2u
#define CAN_HW_OBJ_3    3u
#define CAN_HW_OBJ_4    4u
#define CAN_HW_OBJ_5    5u
#define CAN_HW_OBJ_6    6u
#define CAN_HW_OBJ_7    7u
#define CAN_HW_OBJ_8    8u
#define CAN_HW_OBJ_9    9u
#define CAN_HW_OBJ_10    10u
#define CAN_HW_OBJ_11    11u
#define CAN_HW_OBJ_12    12u
#define CAN_HW_OBJ_13    13u
#define CAN_HW_OBJ_14    14u
#define CAN_HW_OBJ_15    15u
#define CAN_HW_OBJ_16    16u
#define CAN_HW_OBJ_17    17u
#define CAN_HW_OBJ_18    18u
#define CAN_HW_OBJ_19    19u
#define CAN_HW_OBJ_20    20u
#define CAN_HW_OBJ_21    21u
#define CAN_HW_OBJ_22    22u
#define CAN_HW_OBJ_23    23u
#define CAN_HW_OBJ_24    24u
#define CAN_HW_OBJ_25    25u
#define CAN_HW_OBJ_26    26u
#define CAN_HW_OBJ_27    27u
#define CAN_HW_OBJ_28    28u
#define CAN_HW_OBJ_29    29u
#define CAN_HW_OBJ_30    30u
#define CAN_HW_OBJ_31    31u
#define CAN_HW_OBJ_32    32u
#define CAN_HW_OBJ_33    33u
#define CAN_HW_OBJ_34    34u
#define CAN_HW_OBJ_35    35u
#define CAN_HW_OBJ_36    36u
#define CAN_HW_OBJ_37    37u
#define CAN_HW_OBJ_38    38u
#define CAN_HW_OBJ_39    39u

/*Counts*/
#define CAN_MAX_HOH_CONFIGURED          40u
#define CAN_MAX_HTH_CONFIGURED          16u
#define CAN_MAX_HRH_CONFIGURED          24u
#define NUMBER_OF_ACTIVE_CAN_CTRL       8u
#define CAN_FD_OPERATION_ENABLED        STD_ON


/*Enable APIs*/
#define CAN_VERSION_API_ENABLE          STD_ON
#define CAN_SET_BAUDRATE_API            STD_ON
#define CAN_MAIN_READ_FUNC_ENABLE      STD_ON
#define CAN_MAIN_WRITE_FUNC_ENABLE     STD_ON
#define CAN_MIXED_MODE_ENABLE          STD_OFF
#define CAN_TX_OBJ_MIXED_MODE_ENABLE   STD_OFF
#define CAN_RX_OBJ_POLLING_ENABLE      STD_OFF

#define CAN_MAIN_BUSOFF_FUNC_ENABLE     STD_ON
#define CAN_MAIN_WAKEUP_FUNC_ENABLE     STD_ON 
#define CAN_MULTIPLEXED_TRANSMISSION    STD_ON
/*Init wait timout*/
#define CAN_INIT_WAIT_TIMEOUT           1.0
#define CAN_MAIN_BUSOFF_FUNC_PERIOD     10.0u
#define CAN_MAIN_FUNC_MODE_PERIOD       10.0u
#define CAN_MAIN_WAKEUP_FUNC_PERIOD     0.0u
/*MRAM reset timeout*/
#define CAN_HW_WAIT_TIMEOUT             1.0
#define CAN_MAIN_FUNC_MULTIPLE_RW       STD_OFF
#define CAN_OS_COUNTER_SUPPORTED        STD_ON
#define CAN_OS_COUNTER_ID               OsCounter
#define CAN_OS_SECONDS_PER_TICK         0.111
#define CAN_TIMEOUT_DURATION            1.0
#define CAN_DMA_ENABLE                  STD_OFF //STD_ON
#define CAN_ECC_ENABLE                  STD_OFF
#ifdef CAN_PLT_SAFERTOS_ENABLE
#define CAN_FUSA_ENABLE                 STD_OFF
#else
#define CAN_FUSA_ENABLE                 STD_OFF
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

#define CAN_ENABLE_DEBUG_LOGGING        STD_ON
#define CAN_TRIGGER_TRANSMIT_SUPPORTED  STD_ON
#define CANFD_PADDING_SW_PROCESSING     STD_ON
#define CAN_TRANSMIT_PAUSE              STD_ON

#define CAN_GLOBAL_TIME_SUPPORT         STD_ON
#define CAN_ENABLE_SECURITY_EVENT       STD_ON
#define CAN_CLOCK_FREQUENCY             80u
#define CAN_PARTITION_SUPPORT_ENABLE    STD_OFF
#define CAN_TTCAN_SUPPORTED_IN_CANIF    STD_OFF
/*Payload length */
#define CAN_OBJECT_PL_12      12u
#define CAN_OBJECT_PL_16      16u
#define CAN_OBJECT_PL_20      20u
#define CAN_OBJECT_PL_24      24u
#define CAN_OBJECT_PL_32      32u
#define CAN_OBJECT_PL_48      48u
#define CAN_OBJECT_PL_64      64u
#define CAN_OBJECT_PL_8       8u
#define CAN_LPDU_CALLOUT_ENABLE STD_OFF
#define TX_CMD_MAX_DMA_DESC             1u
#define TX_EVENT_CMD_MAX_DMA_DESC       1u
#define RX_FIFO_0_CMD_MAX_DMA_DESC      1u
#define RX_FIFO_1_CMD_MAX_DMA_DESC      1u
typedef int CanBaseAddressType;
#ifdef __cplusplus
}
#endif

#endif /* CAN_CFG_H */
/*******************************************************************************
**                               End of File                                  **
*******************************************************************************/

