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
    File Name.............. : Can_Fusa_Internal.h
    Description............ : This file contains functionality of Safety requirements for CAN driver
    Autosar Release Version : R22-11
    Platform............... :
    SW Release Version..... :
==============================================================================*/
/*==============================================================================
|                       MISRA-C VIOLATIONS                                     |
==============================================================================*/
/*
*/
#ifndef CAN_FUSA_INTERNAL_H
#define CAN_FUSA_INTERNAL_H
#ifdef __cplusplus
extern "C"{
#endif
/*==============================================================================
|                       INCLUDE FILES                                          |
==============================================================================*/
#include "Can_Fusa.h"
#ifndef CAN_PLT_SAFERTOS_ENABLE
//#include "CDD_Ssm_Client.h"
#else
//#include "fusa.h"
#endif /* End of CAN_PLT_SAFERTOS_ENABLE*/
/*==============================================================================
|                       EXPORTED CONSTANTS and MACROS                          |
==============================================================================*/
#define FUSA_TIMEOUT_VALUE              0x186A0u
#define CAN_FUSA_EDGE_INTERRUPTS_MASK   0x00000002u
#define CAN_FUSA_LEVEL_INTERRUPTS_MASK  0x00000000u


#define NUM_OF_LEVEL_FAULTS               0xAu
#define CAN_NUM_EDGE_ERRORS               0x00000008u
#define CAN_EDGE_ERR_SPARE_BITS           0x00000000u
#define CAN_NUM_EDGE_WARN                 0x00000002u
#define CAN_EDGE_WARN_SPARE_BITS          0x00000001u
#define CAN_NUM_LEVEL_WARN                0x00000009u
#define CAN_LEVEL_WARN_SPARE_BITS         0x00000002u
#define CAN_NUM_LEVEL_ERRORS              0x00000001u
#define CAN_LEVEL_ERR_SPARE_BITS          0x00000001u
#define CAN_FUSA_ALL_ERROR_MASK           0xFFFFFFFFu
#define CAN_FUSA_EDGE_EAE_MASK            0xFFFFFFFFu
#define CANSS_FUSA_LEVEL_EAE_MASK         0xFFFFFFFFu
#define CAN_FUSA_EDGE_ERROR_MASK          0x00000000u
#define CAN_FUSA_LEVEL_ERROR_MASK         0x00000000u
#define CAN_FUSA_CHECK_THRESHOLD          0xff
#define CAN_FUSA_EDGE_WARNING_MASK        0x000007FBu

#define CANSS_FUSA_ECC_SINGLE_BIT_MSK              1u
#define CANSS_FUSA_DMU_IR_ARA_MSK                  2u
#define CANSS_FUSA_ECC_DOUBLE_BIT_MSK              8u
#define CANSS_FUSA_CSR_PARITY_MSK                 16u
#define CANSS_FUSA_INT_AHB_TIMEOUT_MSK            32u
#define CANSS_FUSA_AHB_ARB_TIMEOUT_MSK            64u
#define CANSS_FUSA_DMA_FSM_TIMEOUT_MSK           128u
#define CANSS_FUSA_MRAM_ARB_TIMEOUT_MSK          256u
#define CANSS_FUSA_ECC_AED_BIT_MSK               512u
#define CANSS_FUSA_ECC_DATA_PARITY_BIT_MSK      1024u
#define CANSS_FUSA_IR_PED_MSK                      1u
#define CANSS_FUSA_IR_PEA_MSK                      2u
#define CANSS_FUSA_IR_BO_MSK                       4u
#define CANSS_FUSA_IR_EW_MSK                       8u
#define CANSS_FUSA_IR_EP_MSK                      16u
#define CANSS_FUSA_IR_ELO_MSK                     32u
#define CANSS_FUSA_IR_BEU_MSK                     64u
#define CANSS_FUSA_IR_MRAF_MSK                   128u
#define CANSS_FUSA_IR_ARA_MSK                    256u
#define CANSS_FUSA_IR_WDI_MSK                    2048u
/*==============================================================================
|                       EXPORTED STRUCTURES, ENUMS, TYPEDEFS                   |
==============================================================================*/
typedef enum
{
    CAN_FUSA_ERROR,
    CAN_FUSA_WARNING,
    NUM_FUSA_INTS
}Can_Fusa_Interrupt_Type;
typedef struct
{
    uint32 Fusa_ErrorStatus_Addr;
    uint32 Fusa_ErrorStatus_BMSK;
#ifdef CAN_PLT_SAFERTOS_ENABLE
    uint32 Fusa_Error_ID;
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
}Fusa_Error_Csr_Map_Type;
typedef struct
{
    boolean safeState;
    can_fusa_fault_code faultCode;
}Can_Fault_State_Info;


/*==============================================================================
|                       EXPORTED FUNCTIONS                                     |
==============================================================================*/
#if(CAN_FUSA_ENABLE == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void CanFusa_Timeout_Init(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void CanFusa_ECC_Init(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void CanFusa_Cfg_Init(const Can_ConfigType* Config);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType CanFusa_EnterSafeState(uint8 ControllerId,
                                        can_fusa_fault_code CanSmFaultCode);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void CanFusa_ConfigureFusaInterrupts(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern boolean CanFusa_Cntrl_In_SafeState(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern can_fusa_fault_code CanFusa_Cntrl_GetCurFaultCode(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType CanFusa_Set_CanDrv_SafeState(uint8 ApiID);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType CanFusa_ReInit_Controller(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType CanFusa_Fusa_DeInit(void);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void CanFusa_Validate_ModeCheckCnt(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void CanFusa_Reset_ModeCheckCnt(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void CANSS_FUSA_ERROR_HANDLER(uint8 CanCtrID);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void CANSS_FUSA_WARNING_HANDLER(uint8 CanCtrID);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#ifdef CAN_PLT_SAFERTOS_ENABLE
extern void CANSS_FUSA_TIMEOUT_STATUS(uint8 CanCtrID);
extern void CANSS_FUSA_PROTOCOL_STATUS(uint8 CanCtrID);
extern void CANSS_FUSA_ECC_STATUS(uint8 CanCtrID);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
#endif
/*==============================================================================
|                       EXPORTED VARIABLES                                     |
==============================================================================*/

#endif /* CAN_FUSA_INTERNAL_H */
/*==============================================================================
==============================================================================*/
