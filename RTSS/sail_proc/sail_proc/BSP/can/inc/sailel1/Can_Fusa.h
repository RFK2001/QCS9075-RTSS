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
/*==============================================================================
    File Name.............. : Can_Fusa.h
    Description............ :
    Autosar Release Version : R22-11
    Platform............... :
    SW Release Version..... :
==============================================================================*/
/*==============================================================================
|                       MISRA-C VIOLATIONS                                     |
==============================================================================*/
/*
*/
#ifndef CAN_FUSA_H
#define CAN_FUSA_H
#ifdef __cplusplus
extern "C"{
#endif
/*==============================================================================
|                       INCLUDE FILES                                          |
==============================================================================*/
/*==============================================================================
|                       EXPORTED CONSTANTS and MACROS                          |
==============================================================================*/
/*==============================================================================
|                       EXPORTED STRUCTURES, ENUMS, TYPEDEFS                   |
==============================================================================*/
typedef enum
{
  CAN_FUSA_FLT_CODE_SEC_ECC = 0x0,
  CAN_FUSA_FLT_CODE_DMU_IR_ARA,
  CAN_FUSA_FLT_CODE_DED_ECC,
  CAN_FUSA_FLT_CODE_CSR_PARITY,
  CAN_FUSA_FLT_CODE_DMA_MRAM_AHB_TIMEOUT,
  CAN_FUSA_FLT_CODE_AHB_ARB_TIMEOUT,
  CAN_FUSA_FLT_CODE_DMA_FSM_TIMEOUT,
  CAN_FUSA_FLT_CODE_MRAM_ARB_TIMEOUT,
  CAN_FUSA_FLT_CODE_IR_PED,
  CAN_FUSA_FLT_CODE_IR_PEA,
  CAN_FUSA_FLT_CODE_IR_BO,
  CAN_FUSA_FLT_CODE_IR_EW,
  CAN_FUSA_FLT_CODE_IR_EP,
  CAN_FUSA_FLT_CODE_IR_ELO,
  CAN_FUSA_FLT_CODE_IR_BEU,
  CAN_FUSA_FLT_CODE_IR_MRAF,
  CAN_FUSA_FLT_CODE_IR_ARA,
  CAN_FUSA_FLT_CODE_IR_WDI,
  CAN_FUSA_FLT_CODE_CFG_MISMATCH,
  CAN_FUSA_FLT_CODE_INIT_FAILED,
  CAN_FUSA_FLT_CODE_STATE_TRANS_FAILED,
  CAN_FUSA_FLT_CODE_DEINIT_FAILED,
  CAN_FUSA_FLT_CODE_ECC_AED,
  CAN_FUSA_FLT_CODE_ECC_DATA_PARITY,
  CAN_FUSA_FLT_CODE_NO_ERR
} can_fusa_fault_code;
typedef enum
{
  CAN_FUSA_FLT_SRC_CAN0 = 0x0,
  CAN_FUSA_FLT_SRC_CAN1,
  CAN_FUSA_FLT_SRC_CAN2,
  CAN_FUSA_FLT_SRC_CAN3,
  CAN_FUSA_FLT_SRC_CAN4,
  CAN_FUSA_FLT_SRC_CAN5,
  CAN_FUSA_FLT_SRC_CAN6,
  CAN_FUSA_FLT_SRC_CAN7,
  CAN_FUSA_FLT_SRC_CAN_HW_UNIT,
} can_fusa_fault_source;
/*==============================================================================
|                       EXPORTED FUNCTIONS                                     |
==============================================================================*/
/*==============================================================================
|                       EXPORTED VARIABLES                                     |
==============================================================================*/
#ifdef __cplusplus
}
#endif

#endif /* CAN_SAFETY_H */
/*==============================================================================
==============================================================================*/
