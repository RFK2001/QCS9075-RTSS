/*
===========================================================================
*/
/**
    @file Can_Drv.c
    @brief Contain All top level function of PMIC driver

*/
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
|                       MISRA-C VIOLATIONS                                     |
==============================================================================*/
/*
*/
/*==============================================================================
|                       INCLUDE FILES                                          |
==============================================================================*/
#include "Can_Drv.h"
#ifdef CAN_PLT_SAFERTOS_ENABLE
#include "Can_SafeRTOS.h"
#include "CanIf.h"
#else
#include "CanIf_Cbk.h"
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
#include "SchM_Can.h"
#if(CAN_LPDU_CALLOUT_ENABLE == STD_ON)
#include "Can_Externals.h"
#endif    
/*==============================================================================
 |                      EXPORTED CONSTANTS and MACROS                          |
 ==============================================================================*/
/*==============================================================================
|                       LOCAL CONSTANTS and MACROS                             |
==============================================================================*/
/*==============================================================================
|                       GLOBAL CONSTANTS                                       |
==============================================================================*/
/*==============================================================================
|                       GLOBAL VARIABLES                                       |
==============================================================================*/
#define CAN_START_SEC_VAR_CLEARED_ASIL_B_PTR
#include "Can_MemMap.h"
static const Can_ConfigType*Can_Drv_ConfigPtr;
#define CAN_STOP_SEC_VAR_CLEARED_ASIL_B_PTR
#include "Can_MemMap.h"
#if (CAN_DMA_ENABLE == STD_ON)
#ifdef CAN_DMA_DDR_ADDR_ENABLE
    #define CAN_START_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    static Can_TxEventFifoDMAType  Can_DMA_TxEvent_Data_Buffer[NUMBER_OF_ACTIVE_CAN_CTRL][TX_EVENT_CMD_MAX_DMA_DESC] ={0};
    #define CAN_STOP_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    #define CAN_START_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    static Can_DmaCmdDescType  CAN_DMA_TX_Event_CMD_Descriptors[NUMBER_OF_ACTIVE_CAN_CTRL][TX_EVENT_CMD_MAX_DMA_DESC] ={0};
    #define CAN_STOP_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    #define CAN_START_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    static Can_RXbuffFifoDMAType  Can_DMA_Rx0_Data_Buffer[NUMBER_OF_ACTIVE_CAN_CTRL][RX_FIFO_0_CMD_MAX_DMA_DESC] ={0};
    #define CAN_STOP_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    #define CAN_START_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    static Can_DmaCmdDescType  CAN_DMA_RX_FIFO_0_CMD_Descriptors[NUMBER_OF_ACTIVE_CAN_CTRL][RX_FIFO_0_CMD_MAX_DMA_DESC]={0};
    #define CAN_STOP_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    #define CAN_START_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    static Can_RXbuffFifoDMAType  Can_DMA_Rx1_Data_Buffer[NUMBER_OF_ACTIVE_CAN_CTRL][RX_FIFO_1_CMD_MAX_DMA_DESC] ={0};
    #define CAN_STOP_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    #define CAN_START_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    static Can_DmaCmdDescType  CAN_DMA_RX_FIFO_1_CMD_Descriptors[NUMBER_OF_ACTIVE_CAN_CTRL][RX_FIFO_1_CMD_MAX_DMA_DESC] ={0};
    #define CAN_STOP_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    #define CAN_START_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    static Can_TxBufferDMAType  Can_DMA_Tx_Data_Buffer[NUMBER_OF_ACTIVE_CAN_CTRL][TX_CMD_MAX_DMA_DESC] ={0};
    #define CAN_STOP_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    #define CAN_START_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    static Can_DmaCmdDescType  CAN_DMA_TX_CMD_Descriptors[NUMBER_OF_ACTIVE_CAN_CTRL][TX_CMD_MAX_DMA_DESC] ={0};
    #define CAN_STOP_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
#else
    #define CAN_START_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    static Can_TxEventFifoDMAType  Can_DMA_TxEvent_Data_Buffer[NUMBER_OF_ACTIVE_CAN_CTRL][TX_EVENT_CMD_MAX_DMA_DESC] ={0};
    #define CAN_STOP_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    #define CAN_START_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    static Can_DmaCmdDescType  CAN_DMA_TX_Event_CMD_Descriptors[NUMBER_OF_ACTIVE_CAN_CTRL][TX_EVENT_CMD_MAX_DMA_DESC] ={0};
    #define CAN_STOP_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    #define CAN_START_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    static Can_RXbuffFifoDMAType  Can_DMA_Rx0_Data_Buffer[NUMBER_OF_ACTIVE_CAN_CTRL][RX_FIFO_0_CMD_MAX_DMA_DESC] ={0};
    #define CAN_STOP_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    #define CAN_START_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    static Can_DmaCmdDescType  CAN_DMA_RX_FIFO_0_CMD_Descriptors[NUMBER_OF_ACTIVE_CAN_CTRL][RX_FIFO_0_CMD_MAX_DMA_DESC]={0};
    #define CAN_STOP_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    #define CAN_START_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    static Can_RXbuffFifoDMAType  Can_DMA_Rx1_Data_Buffer[NUMBER_OF_ACTIVE_CAN_CTRL][RX_FIFO_1_CMD_MAX_DMA_DESC] ={0};
    #define CAN_STOP_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    #define CAN_START_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    static Can_DmaCmdDescType  CAN_DMA_RX_FIFO_1_CMD_Descriptors[NUMBER_OF_ACTIVE_CAN_CTRL][RX_FIFO_1_CMD_MAX_DMA_DESC] ={0};
    #define CAN_STOP_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    #define CAN_START_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    static Can_TxBufferDMAType  Can_DMA_Tx_Data_Buffer[NUMBER_OF_ACTIVE_CAN_CTRL][TX_CMD_MAX_DMA_DESC] ={0};
    #define CAN_STOP_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    #define CAN_START_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
    static Can_DmaCmdDescType  CAN_DMA_TX_CMD_Descriptors[NUMBER_OF_ACTIVE_CAN_CTRL][TX_CMD_MAX_DMA_DESC] ={0};
    #define CAN_STOP_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #include "Can_MemMap.h"
#endif
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 DmaTxWriteIdx[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 DmaTxReadIdx[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 DmaTxEventReadIdx[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 DmaRxFifo0ReadIdx[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 DmaRxFifo1ReadIdx[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_AhbErrorCnt[NUMBER_OF_ACTIVE_CAN_CTRL][NUM_OF_CAN_DMA_CHANNELS] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_BOOLEAN
#include "Can_MemMap.h"
static boolean DmaTxDescAval[NUMBER_OF_ACTIVE_CAN_CTRL]={FALSE};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_BOOLEAN
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_BOOLEAN
#include "Can_MemMap.h"
static boolean DmaSwTrigger[NUMBER_OF_ACTIVE_CAN_CTRL]={FALSE};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_BOOLEAN
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 DmaPendingTxTransferCnt[NUMBER_OF_ACTIVE_CAN_CTRL]={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_TXENSA_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_TXEIE_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_TXEIAS_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_TXEIDLC_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_TXEWATA_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_TXEIR_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_RX0ENSA_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_RX0EID_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_RX0EIAS_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_RX0E1W_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_RX0EIO_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_BEC_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_BEU_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_RX1ENSA_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_RX1EID_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_RX1EIAS_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_RX1E1W_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_RX1EIO_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_TXEENSA_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_TXEEID_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_TXEEIAS_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_TXEEIW_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_DT_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_IAC_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#if(CAN_ENABLE_DEBUG_LOGGING ==STD_ON)
#define CAN_START_SEC_VAR_INIT_ASIL_B_16
#include "Can_MemMap.h"
static uint16 Can_DMA_TransferDoneCnt[NUMBER_OF_ACTIVE_CAN_CTRL][NUM_OF_CAN_DMA_CHANNELS] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_16
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_RX1ED_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_RX0ED_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_TXEED_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_DMA_TXEE_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] = {0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#endif
#endif
#if(CAN_ENABLE_DEBUG_LOGGING ==STD_ON)
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_ARA_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_WD_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_EW_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_ELO_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_TO_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_MRAF_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_TEFL_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_TFE_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_TCF_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_TC_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_BEU_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_BEC_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_RF0L_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_RF1L_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_TEFF_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_RF0F_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_RF1F_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_REFN_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_TEFW_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_HPM_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_RF1W_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_RF1N_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_RF0W_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_RF0N_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_FE0_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_FE1_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_FE2_InterruptCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#if(CAN_MIXED_MODE_ENABLE == STD_ON || CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_Tx_LostCnt[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#endif
#endif
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static boolean Can_BusOffRec[NUMBER_OF_ACTIVE_CAN_CTRL] ={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#if(CAN_FUSA_ENABLE == STD_ON)
#define CAN_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
Can_RegConfigInfo Can_ConfigReg[NUMBER_OF_ACTIVE_CAN_CTRL] = {0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#endif
#define CAN_START_SEC_CONST_ASIL_B_8
#include "Can_MemMap.h"
/*Hash to convert the DLC to actual size*/
static const uint8 Can_Drv_CANFDDLC[CANSS_SEVEN] = {
    CANFD_SDU_DLC_9_CONVERT_LEN_12,
    CANFD_SDU_DLC_10_CONVERT_LEN_16,
    CANFD_SDU_DLC_11_CONVERT_LEN_20,
    CANFD_SDU_DLC_12_CONVERT_LEN_24,
    CANFD_SDU_DLC_13_CONVERT_LEN_32,
    CANFD_SDU_DLC_14_CONVERT_LEN_48,
    CANFD_SDU_DLC_15_CONVERT_LEN_64
};
#define CAN_STOP_SEC_CONST_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_CONST_ASIL_B_32
#include "Can_MemMap.h"
const uint32 Can_Controller_Arr[CAN_MTTCAN_MAX_CNT] = {
    SAILSS_CANSS_0_CANSS_BASE,
    SAILSS_CANSS_1_CANSS_BASE,
    SAILSS_CANSS_2_CANSS_BASE,
    SAILSS_CANSS_3_CANSS_BASE,
    SAILSS_CANSS_4_CANSS_BASE,
    SAILSS_CANSS_5_CANSS_BASE,
    SAILSS_CANSS_6_CANSS_BASE,
    SAILSS_CANSS_7_CANSS_BASE
};
#define CAN_STOP_SEC_CONST_ASIL_B_32
#include "Can_MemMap.h"
#define CAN_START_SEC_CONST_ASIL_B_32
#include "Can_MemMap.h"
static const uint32 Can_Controller_Max_Mram[CAN_MTTCAN_MAX_CNT] = {
    HWIO_SAILSS_CANSS_0_CANSS_MRAMn_MAXn,
    HWIO_SAILSS_CANSS_1_CANSS_MRAMn_MAXn,
    HWIO_SAILSS_CANSS_2_CANSS_MRAMn_MAXn,
    HWIO_SAILSS_CANSS_3_CANSS_MRAMn_MAXn,
    HWIO_SAILSS_CANSS_4_CANSS_MRAMn_MAXn,
    HWIO_SAILSS_CANSS_5_CANSS_MRAMn_MAXn,
    HWIO_SAILSS_CANSS_6_CANSS_MRAMn_MAXn,
    HWIO_SAILSS_CANSS_7_CANSS_MRAMn_MAXn
};
#define CAN_STOP_SEC_CONST_ASIL_B_32
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_CLEARED_ASIL_B_32
#include "Can_MemMap.h"
static uint32 InterruptConfigVal[NUMBER_OF_ACTIVE_CAN_CTRL] ;
#define CAN_STOP_SEC_VAR_CLEARED_ASIL_B_32
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_CLEARED_ASIL_B_16
#include "Can_MemMap.h"
static uint16 Can_Drv_RxTimeStamp[CAN_MAX_HRH_CONFIGURED];
#define CAN_STOP_SEC_VAR_CLEARED_ASIL_B_16
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_CLEARED_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static Can_TxTimestampType Can_Drv_TxTimeStamp[NUMBER_OF_ACTIVE_CAN_CTRL][CANSS_TX_TIMESTAMP_FIFO_SIZE];
#define CAN_STOP_SEC_VAR_CLEARED_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_CLEARED_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_Drv_EnableEgressObject[CAN_MAX_HTH_CONFIGURED];
#define CAN_STOP_SEC_VAR_CLEARED_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
static uint8 Can_Drv_TxTsIndex[NUMBER_OF_ACTIVE_CAN_CTRL]={0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_CLEARED_ASIL_B_16
#include "Can_MemMap.h"
static uint16 Can_Drv_BaudRate[NUMBER_OF_ACTIVE_CAN_CTRL];
#define CAN_STOP_SEC_VAR_CLEARED_ASIL_B_16
#include "Can_MemMap.h"
#if(CAN_MIXED_MODE_ENABLE == STD_ON || CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
#define CAN_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static Can_PendingPduType Can_Drv_PendingPduNotifications[NUMBER_OF_ACTIVE_CAN_CTRL]={{0}};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#endif
#if(CAN_GLOBAL_TIME_SUPPORT == STD_ON)
/*Variable updated with ISR when ther is a timestamp overflow hence internal timestamp can exceed 16 bits*/
#define CAN_START_SEC_VAR_INIT_ASIL_B_32
#include "Can_MemMap.h"
static uint32 Can_Drv_TSWrapCounter[NUMBER_OF_ACTIVE_CAN_CTRL] = {0};
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_32
#include "Can_MemMap.h"
#endif

#ifdef CAN_PLT_SAFERTOS_ENABLE
/*==============================================================================
|                  SAFERTOS SPECIFIC GLOBAL VARIABLES                          |
==============================================================================*/
CAN_DATA static uint32 CAN_Reg_Setting_Cnt[CAN_MTTCAN_MAX_CNT] = {0};
CAN_DATA static bool Can_Cfg_Reg_Is_Valid[CAN_MTTCAN_MAX_CNT] = {FALSE};
#endif

/*==============================================================================
|                       LOCAL FUNCTION PROTOTYPES                              |
==============================================================================*/
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static Can_HwHandleType Can_Drv_GetRxObjectIndex
                                                 (uint8 BufferId,
                                                  uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static void Can_Drv_Memset(void* Source,uint32 Value,
                                               uint32 WordLength);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static void Can_Drv_Memcopy(void* Dest,const void* Src,
                                                uint32 WordLength);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static uint32 ConvertToDLC (uint32 MsgLength);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline Std_ReturnType Can_Drv_MRAM_ResetCheck(uint8 CanCtrID);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void  Can_Drv_BaudRateConfig(
    const Can_NominalBaudConfigPtrType *const BaudrateConfig,
    uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void  Can_Drv_FilterConfig(
        uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_TimeStampConfig (
    uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void  Can_Drv_RxConfig(
                                    uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void  Can_Drv_TxConfig(
                                      uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#if(CAN_ENABLE_SECURITY_EVENT == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_Process_ProtocolErrors(
        uint8 ControllerId,
        CanSS_ErrorType ProtocolErrorType);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_ProcessRxBufferIsr
                              (uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_NotifyRxCallback(Can_RXbuffFifoType* RxBufferElement,Can_HwType MailBox,uint8 ObjectId
#ifdef CAN_PLT_SAFERTOS_ENABLE
                                             , bool isIsr
#endif
                                             );
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_ProcessRxFIFOIsr
                              (uint8 ControllerId,
                              Can_RxBufferType RxFIFOType);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_CCControlResetInit
        (const Can_CtrlConfigType *const ctrlConfig,
        uint8 ApiId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void  Can_Drv_InterruptConfig(
                                         uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline Std_ReturnType Can_Drv_Get_CanBitTimeStamp(
        uint8 ControllerId,
        uint16 TimeStamp,
        Can_TimeStampType* TimeStampPtr);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline Std_ReturnType Can_Drv_CCControlInit
                          (const Can_CtrlConfigType *const ctrlConfig,
                           uint8 ApiId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"

#ifdef CAN_PLT_SAFERTOS_ENABLE
static inline void Can_Drv_TxNotification(uint8 ControllerId, PduIdType swPduHandle,
							 Can_TimeStampType timeStamp, Can_HwHandleType HwObjId, bool isIsr);
#else
static inline void Can_Drv_TxNotification(PduIdType swPduHandle);
#endif

#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_RxNotification
                                          (Can_HwType MailBoxInfo, PduInfoType PduInfo
#ifdef CAN_PLT_SAFERTOS_ENABLE
                                           ,Can_TimeStampType timeStamp, bool isIsr
#endif
                                           );
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_SetSleepMode(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_SetUnintMode(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline  void Can_Drv_SetIdleMode(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline  void Can_Drv_SetNormalMode(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_MRAM_Init(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#if(CAN_MIXED_MODE_ENABLE == STD_ON || CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static void Can_Drv_Add_Pdu_ToPendingTxList(uint8 ControllerId, 
                                            PduIdType pduId, 
                                            const Can_TxHOHType* txObj);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif

#if(CAN_MIXED_MODE_ENABLE == STD_ON || CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_Delete_Pdu_FromPendingTxList(uint8 ControllerId, 
                                                        uint8 readIndex);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_AcknowledgeRx(uint8 CanCtrID, 
                 Can_RxBufferType RxFifoCfg, uint8 RxIndex);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline uint8 Can_Drv_GetRxElementSize(uint8 Dlc);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_EnablePEAInterrupts(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
/*==============================================================================
|                       LOCAL VARIABLES                                        |
==============================================================================*/
/*==============================================================================
|                       FUNCTION DEFINITIONS                                   |
==============================================================================*/
#ifdef CAN_PLT_SAFERTOS_ENABLE
static void Can_Drv_CfgUpdate(uint8 ControllerId, bool flag)
{
    Can_Cfg_Reg_Is_Valid[ControllerId] = flag;
}

bool Can_Drv_Is_Controller_CfgValid(uint8 ControllerId)
{
     return Can_Cfg_Reg_Is_Valid[ControllerId];
}
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
Std_ReturnType Can_Drv_Init (uint8 ControllerId)
{
    Std_ReturnType status = E_OK;
    const Can_CtrlConfigType* ctrlConfig;
    const Can_NominalBaudConfigPtrType* canCtrlDefaultBaudrate;
    ctrlConfig = &Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId];
#ifdef CAN_PLT_SAFERTOS_ENABLE
    Can_Drv_CfgUpdate(ControllerId, FALSE);
    status = Can_Safertos_Enable_Clock(ControllerId);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
    status = Can_Drv_MRAM_ResetCheck(ctrlConfig->CanCtrID);
    if(E_NOT_OK != status ){
        Can_Drv_MRAM_Init(ControllerId);
    }
    else{
        status = E_NOT_OK;
    }
    if(E_OK == status ){
#if(CAN_FUSA_ENABLE == STD_ON)
        CanFusa_ECC_Init(ControllerId);
        /*Configure FUSA Timeout Values*/
        CanFusa_Timeout_Init(ControllerId);
#endif
        status = Can_Drv_CCControlInit(ctrlConfig, CAN_SID_INIT);
    }
    /*Initialization of CCCR register bits*/
    if(E_OK == status ){
#ifdef CAN_PLT_SAFERTOS_ENABLE
        CAN_Reg_Setting_Cnt[ctrlConfig->CanCtrID]++;
#endif
#if(CAN_FUSA_ENABLE == STD_ON)
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID,RWD,WDC,WDG_TIMEOUT_VALUE);
#endif
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, CCCR, ASM, CANSS_ZERO);
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, CCCR, CSR, CANSS_ZERO);
        /* check can Loopback enable,*/
         if(ctrlConfig->CanLoopBackEnable == CAN_LOOPBACK_INTERNAL){
		 	SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, CCCR, TEST, CANSS_ONE);
		 	SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TEST, LBCK, CANSS_ONE);		
         	SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, CCCR, MON, CANSS_ONE);
         }else if(ctrlConfig->CanLoopBackEnable == CAN_LOOPBACK_EXTERNAL){
		 	SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, CCCR, TEST, CANSS_ONE);
		 	SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TEST, LBCK, CANSS_ONE);		
         	SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, CCCR, MON, CANSS_ZERO);
         }
         else{
		 	SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, CCCR, TEST, CANSS_ZERO);
		 	SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TEST, LBCK, CANSS_ZERO);		
            SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, CCCR, MON, CANSS_ZERO);
         }
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, CCCR, DAR, CANSS_ONE);
#if(CAN_TRANSMIT_PAUSE == STD_ON)
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, CCCR, TXP,(uint32) CANSS_ONE);
#else
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, CCCR, TXP,(uint32) CANSS_ZERO);
#endif
        if(ctrlConfig->CanFDModeEnabled){
            SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, CCCR, FDOE,(uint32)CANSS_ONE);
        }
        else{
            SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, CCCR, FDOE,(uint32)CANSS_ZERO);
        }
#ifdef CAN_PLT_SAFERTOS_ENABLE
        CAN_Reg_Setting_Cnt[ctrlConfig->CanCtrID]--;
#endif
        /*Get Default Baudrate value*/
        canCtrlDefaultBaudrate =&ctrlConfig->CanCtrlNominalBaudrate[(ctrlConfig->DefaultBaudRateIndex)];
        /*Update Current Baudrate Index */
        Can_CtrlInfo[ControllerId].CanCtrlCurBaudrateIdx = ctrlConfig->DefaultBaudRateIndex;
        /*Set Default Baudrate*/
        Can_Drv_BaudRateConfig(canCtrlDefaultBaudrate,ControllerId);
        /*Configure Interrupts */
        Can_Drv_InterruptConfig(ControllerId);
        /*Filter configuration*/
        Can_Drv_FilterConfig(ControllerId);
#if(CAN_GLOBAL_TIME_SUPPORT == STD_ON)
        /*TimeStamp configuration*/
        Can_Drv_TimeStampConfig(ControllerId);
#endif
        /*Configure RX */
        Can_Drv_RxConfig(ControllerId);
        /*Set the TX configuration*/
        Can_Drv_TxConfig(ControllerId);
        /*Initialize DMA*/
#if (CAN_DMA_ENABLE == STD_ON)
        Can_Drv_DMA_Init(ControllerId);
#endif
        /*Reset CCCR CCE and INIT bits*/
        (void)Can_Drv_CCControlResetInit(ctrlConfig, CAN_SID_INIT);

#ifdef CAN_PLT_SAFERTOS_ENABLE
        status = Can_Safertos_Interrupt_Register(ControllerId);
        if(E_NOT_OK == status ){
            return status;
        }
        status = Can_Safertos_Config_Gpio(ControllerId);
        if(E_NOT_OK == status ){
            return status;
        }
        Can_Drv_CfgUpdate(ControllerId, TRUE);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
    }
    return status;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
Std_ReturnType Can_Drv_SetBaudrate (uint8 ControllerId,
                                                uint16 BaudRateConfigID)
{
    Std_ReturnType status = E_OK;
    const Can_CtrlConfigType* ctrlConfig = &Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId];
    const Can_NominalBaudConfigPtrType* canCtrlBaudrateConfig;
#ifdef CAN_PLT_SAFERTOS_ENABLE
    Can_Drv_CfgUpdate(ControllerId, FALSE);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
    status = Can_Drv_CCControlInit(ctrlConfig, CAN_SID_SET_BAUDRATE);
    if(E_OK == status){
        Can_CtrlInfo[ControllerId].CanCtrlCurBaudrateIdx = BaudRateConfigID;
        /*Set  Baudrate*/
        canCtrlBaudrateConfig = &(ctrlConfig->CanCtrlNominalBaudrate[BaudRateConfigID]);
        Can_Drv_BaudRateConfig(canCtrlBaudrateConfig ,ControllerId);
        /*Reset CCCR CCE and INIT bits*/
        (void)Can_Drv_CCControlResetInit(ctrlConfig, CAN_SID_SET_BAUDRATE);
    }
#ifdef CAN_PLT_SAFERTOS_ENABLE
        Can_Drv_CfgUpdate(ControllerId, TRUE);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
    return status;
}
void Can_Drv_SetControllerMode(uint8 ControllerId,
                                 Can_ControllerStateType TransitionState)
{
#ifdef CAN_PLT_SAFERTOS_ENABLE
        Can_Drv_CfgUpdate(ControllerId, FALSE);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
    switch(TransitionState)
    {
        case CAN_CS_UNINIT:
             Can_Drv_SetUnintMode(ControllerId);
             break;
        case CAN_CS_STARTED:
             Can_Drv_SetNormalMode(ControllerId);
             break;
        case CAN_CS_STOPPED:
             Can_Drv_SetIdleMode(ControllerId);
             break;
        case CAN_CS_SLEEP:
             Can_Drv_SetSleepMode(ControllerId);
             break;
        default:
            /*An invalid State not possible, Checks in Can.c*/
             break;
    }
#ifdef CAN_PLT_SAFERTOS_ENABLE
            Can_Drv_CfgUpdate(ControllerId, TRUE);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
Std_ReturnType Can_Drv_Write
                  (const Can_PduType* pduInfoPtr,
                   const Can_TxHOHType* TxObj)
{
    Std_ReturnType retval = E_OK;
    uint8 txBufferId = CANSS_ZERO;
    uint8 ctrlrId;
    uint8 controllerId;
    uint8 data;
    uint8 txElementSize;
    uint8 index;
#if(CAN_TRIGGER_TRANSMIT_SUPPORTED == STD_ON)
    uint8 dataBuffer[CAN_MAX_BUFF_DLC];
#endif
    PduInfoType pduInfo;
    Can_TxBufferConfigType txBufDraft = {0};
    Can_TxBufferConfigType *txBufElement= NULL_PTR;
    const Can_NominalBaudConfigPtrType *canCtrlBaudrateConfig;
    controllerId = TxObj->HwTxObjectCtrlrId;
    const Can_CtrlConfigType *const ctrlConfig = &Can_Drv_ConfigPtr->CanActiveCtrPtr[controllerId];
    const Can_MsgRamConfigType *const pMRamConfig = ctrlConfig-> CanMsgRamConfig;
    uint32 msgLength;
    uint32 txbufferMask = 0;
    uint32 dlcValue;
    Can_IdType canId;
    /* Actual Controller ID of the Tx Object*/
    ctrlrId = ctrlConfig->CanCtrID;
    canCtrlBaudrateConfig =&ctrlConfig->CanCtrlNominalBaudrate[Can_CtrlInfo[controllerId].CanCtrlCurBaudrateIdx];
    /*copy the data from PduInfo to pdu*/
    pduInfo.SduDataPtr = pduInfoPtr->sdu;
    pduInfo.SduLength = pduInfoPtr->length;
    canId = pduInfoPtr->id;
    pduInfo.MetaDataPtr = (uint8*)&canId;
    /* Assign Tx buffer index with the value of  FIFO/Queue Put Index if the Message buffer type is FIFO or Queue */
    if( TxObj->TxMsgBufType !=CAN_TxBuffer)
    {
        /* Check if FIFO or QUEUE is FULL */
        if((IN_CAN_HW_FIELD(ctrlrId,TXFQS,TFQF)) != CANSS_ZERO)
        {
            retval = (Std_ReturnType) CAN_BUSY;
        }
        else
        {
            txBufferId =(uint8) IN_CAN_HW_FIELD(ctrlrId, TXFQS, TFQPI);
            if((txBufferId < ONE_INT_SIZE)){
            txbufferMask = (uint32)CANSS_ONE << txBufferId;
            }
        }
    }
    else
    {
        txBufferId = (uint8) TxObj->TxBufferIndex;
        if((txBufferId < ONE_INT_SIZE)){
            txbufferMask = (uint32)CANSS_ONE << txBufferId;
            /* Check the corresponding buffer is free or not */
            if((IN_CAN_HW_FIELD(ctrlrId,TXBRP, TRP) & (txbufferMask)) != CANSS_ZERO){
                retval = (Std_ReturnType) CAN_BUSY;
            }
        }
    }
    if (E_OK == retval)
    {
#if(CAN_TRIGGER_TRANSMIT_SUPPORTED == STD_ON)
        if ((pduInfo.SduDataPtr == NULL_PTR) &&
                (TxObj->TriggerTxEnable == STD_ON))
        {
            pduInfo.SduDataPtr = dataBuffer;
            pduInfo.SduLength = TxObj->TxPayloadLength;
#ifndef CAN_PLT_SAFERTOS_ENABLE 		
            retval = CanIf_TriggerTransmit(
                            ((pduInfoPtr->swPduHandle)),
                                            &pduInfo);
#endif
        }
#endif
        if(E_OK == retval)
        {
            /* Check if CANFD is enabled */
            if((pduInfoPtr->id &CAN_FRAME_TYPE_MASK) == CAN_FRAME_TYPE_MASK)
            {
                dlcValue = ConvertToDLC(pduInfo.SduLength);
                if(dlcValue == CANSS_EIGHT)
                {
                   msgLength = dlcValue;
                }
                else
                {
                    msgLength = Can_Drv_CANFDDLC[dlcValue - CANSS_NINE];
                }
                /* Enable BRS if Data baudrate is configured */
                if(canCtrlBaudrateConfig->DataBaudRatePtr != NULL_PTR)
                {
                    txBufDraft.T1.BRS=(uint8)canCtrlBaudrateConfig->DataBaudRatePtr->BrsSwitch;
                }
            }
            else
            {
                msgLength = pduInfo.SduLength;
                dlcValue = msgLength;
            }
            if(pMRamConfig->TxMaxBufferDlc > (uint8)CANSS_ZERO)
            {
                 /*element size = 8 bytes of header + DLC */
                txElementSize = ((CANSS_EIGHT +Can_Drv_CANFDDLC[pMRamConfig->TxMaxBufferDlc - CANSS_ONE]) >> CANSS_TWO);
            }
            else
            {
                /*element size = 8 bytes of DLC and 8 bytes of header is 4 words*/
                txElementSize = CANSS_FOUR;
            }
            /*Configure Message RAM */
            if(((uint32)pduInfoPtr->id & CAN_ID_TYPE_MASK) == (uint32)CANSS_ZERO)
            {
               /* Standard Identifier */
               txBufDraft.T0.STD_ID.ID =  (uint16)pduInfoPtr->id;
               txBufDraft.T0.STD_ID.XTD = CANSS_ZERO;
               txBufDraft.T0.STD_ID.ESI = CANSS_ZERO;
               txBufDraft.T0.STD_ID.RTR = CANSS_ZERO;
            }
            else
            {
               /* Extended Identifier */
               txBufDraft.T0.XTD_ID.ID =  pduInfoPtr->id;
               txBufDraft.T0.XTD_ID.XTD = CANSS_ONE;
               txBufDraft.T0.XTD_ID.ESI = CANSS_ZERO;
               txBufDraft.T0.XTD_ID.RTR = CANSS_ZERO;
            }
            /* used for variying the PDU id at TXComplete which is passed
            through Bits_MsgMarker_0 bits.*/
            Can_Drv_TxTimeStamp[controllerId][Can_Drv_TxTsIndex[controllerId]].CanId = ((pduInfoPtr->id)&TX_ELEMENT_ID_MASK);
            Can_Drv_TxTimeStamp[controllerId][Can_Drv_TxTsIndex[controllerId]].PduId = pduInfoPtr->swPduHandle;
            Can_Drv_TxTimeStamp[controllerId][Can_Drv_TxTsIndex[controllerId]].ObjectId = TxObj->HwTxObjectId;
            Can_Drv_TxTsIndex[controllerId]++;
            if(Can_Drv_TxTsIndex[controllerId] == CANSS_TX_TIMESTAMP_FIFO_SIZE){
                Can_Drv_TxTsIndex[controllerId] = CANSS_ZERO;
            }
            txBufDraft.T1.EFC =  CANSS_ONE;
            txBufDraft.T1.DLC = (uint8)dlcValue;
            /*Store PduID*/
            txBufDraft.T1.MM1 = (uint8) pduInfoPtr->swPduHandle;
            txBufDraft.T1.MM2 = CANSS_ZERO;
            txBufDraft.T1.RES1 = CANSS_ZERO;
            /*Classic CAN or CANFD*/
            txBufDraft.T1.FDF=(uint8)((pduInfoPtr->id &CAN_FRAME_TYPE_MASK) >> CAN_FRAME_TYPE_SHIFT);
            /* Store data bytes into TX Element */
            if (pduInfo.SduDataPtr != NULL_PTR){
            /*if condition is added to avoid Klockwork error*/
                for(index = 0U; index < msgLength; index++)
                {
                    if (index >= pduInfo.SduLength)
                    {
                        /* Fill with user configured padding byte value */
                        data = TxObj->PaddingValue;
                    }
                    else
                    {
                        data = pduInfo.SduDataPtr[index];
                    }
                    txBufDraft.TxData[index] = data;
                }
            }
#if (CAN_DMA_ENABLE ==STD_ON)
            if((TxObj->TxMsgBufType ==CAN_TxFIFO) &&
                    (ctrlConfig ->CanDmaEnable != FALSE))
            {
                retval = Can_Drv_Write_DMA((TxObj->HwTxObjectCtrlrId),txBufDraft);
            }
            else
#endif
            {
                /* Assign the address of Message Ram corresponding to the buffer index */
                txBufElement = (Can_TxBufferConfigType*) IN_CAN_MRAM_BASE(ctrlConfig->CanCtrID,
                                ((uint32)pMRamConfig->TxBufferStartAdd +
                                (uint32)txElementSize * txBufferId));
                /* Assign the configurations to the Message Ram Element */
                Can_Drv_Memcopy(txBufElement,&txBufDraft,((CANSS_EIGHT+msgLength)>>CANSS_TWO));
                /* Request Transmission */
                SET_CAN_HW_FIELD(ctrlrId, TXBAR, AR, txbufferMask);
            }
        }
    }
    return (retval);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_TxComplete(uint8 ControllerId
#if(CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
    ,uint8 PeriodId
#endif
#ifdef CAN_PLT_SAFERTOS_ENABLE
    ,bool isIsr
#endif
)
{
    uint8  fifoLevel;
    uint8  canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
    uint32 index;
    uint32 canId;
    PduIdType pduId;
    Can_HwHandleType txObjectId=0;
    uint8 timeStampIndex;
    volatile Can_TxEventFifoType* txEventElement;
    const Can_CtrlConfigType *const ctrlConfig = &(Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId]);
    const Can_MsgRamConfigType *const pMRamConfig = ctrlConfig->CanMsgRamConfig;
    const Can_TxHOHType* txObj;
    /* Get the fifo level*/
    fifoLevel = (uint8)IN_CAN_HW_FIELD(canCtrId, TXEFS, EFFC);
    while (fifoLevel != CANSS_ZERO)
    {
        /* Extract the get index */
        index = IN_CAN_HW_FIELD(canCtrId, TXEFS, EFGI);
        /* Assign the address of Message Ram corresponding to the Tx Event FIFO get index */
        txEventElement = (Can_TxEventFifoType*)IN_CAN_MRAM_BASE(canCtrId,
                         (pMRamConfig->TxEventFIFOStartAdd +(uint32)TX_EVENT_FIFO_ELEM_SIZE_IN_WORDS*index));
        pduId = (uint16) txEventElement->E1.E1A.MM;
        /* Extract the Can ID of the transmitted message */
        if(txEventElement->E0.XTD_ID.XTD == CANSS_ZERO)
        {
            /* Standard Identifier*/
            canId = ((txEventElement->E0.STD_ID.ID) & TX_EVENT_FIFO_ELEMENT_ID_MASK);
        }
        else
        {
            /* Extended Identifier*/
            canId = ((txEventElement->E0.XTD_ID.ID) & TX_EVENT_FIFO_ELEMENT_ID_MASK);
        }
        /* Compare the lower 8 bits of PDU ID and and CAN to varify and store the timestamp */
        timeStampIndex = 0;
        while(timeStampIndex < CANSS_TX_TIMESTAMP_FIFO_SIZE){
            if(txEventElement->E1.E1A.MM == (uint8)(Can_Drv_TxTimeStamp[ControllerId][timeStampIndex].PduId & 0xFFU) &&
               (canId == Can_Drv_TxTimeStamp[ControllerId][timeStampIndex].CanId)) {
                    Can_Drv_TxTimeStamp[ControllerId][timeStampIndex].TimeStamp =
                                        (uint16) txEventElement -> E1.E1A.TXTS;
                    pduId = Can_Drv_TxTimeStamp[ControllerId][timeStampIndex].PduId;
                    txObjectId = Can_Drv_TxTimeStamp[ControllerId][timeStampIndex].ObjectId;
                    txObjectId  =Can_Drv_ConfigPtr->CanTxRxObjMapPtr[txObjectId].ObjIndex;
                    break;
            }
            timeStampIndex++;
        }
        txObj = &(Can_Drv_ConfigPtr->CanTxHwObjPtr[txObjectId]);
#if(CAN_MIXED_MODE_ENABLE == STD_ON && CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
        if(((ctrlConfig->CanTxProcessing == CAN_MIXED) && (txObj->ObjectPollingEnabled == TRUE)) ||
           ((ctrlConfig->CanTxProcessing == CAN_POLLING) && (txObj-> TxPeriodId != PeriodId)))
#elif(CAN_MIXED_MODE_ENABLE == STD_ON )
        if((ctrlConfig->CanTxProcessing == CAN_MIXED) && (txObj->ObjectPollingEnabled == TRUE))
#elif(CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
        if ((ctrlConfig->CanTxProcessing == CAN_POLLING) && (txObj-> TxPeriodId != PeriodId))
#endif
#if(CAN_MIXED_MODE_ENABLE == STD_ON || CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
        {
            Can_Drv_Add_Pdu_ToPendingTxList(ControllerId, pduId, txObj);
        }
        else
#endif            
        {
#ifdef CAN_PLT_SAFERTOS_ENABLE           
		  uint16 time = (uint16) txEventElement -> E1.E1A.TXTS;
		  Can_TimeStampType timestamp = {0};
		  
		  Can_Drv_Get_CanBitTimeStamp(ControllerId, time, &timestamp);
		  /*Invoke CanIf_TxConfirmation */
          Can_Drv_TxNotification(ControllerId, pduId, timestamp, txObjectId, isIsr);

#else			/*Invoke CanIf_TxConfirmation */
          Can_Drv_TxNotification(pduId);
#endif			
        }
        /* Providing Acknowlege corresponding to the get index */
        SET_CAN_HW_FIELD(canCtrId, TXEFA, EFA, (index));
        fifoLevel--;
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#if(CAN_MIXED_MODE_ENABLE == STD_ON || CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_Process_PendingTxList(uint8 ControllerId
#if(CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
    ,uint8 PeriodId
#endif
)
{
    PduIdType pduId;
    /*ReadIndex points to the star*/
    uint8 readIndex  = Can_Drv_PendingPduNotifications[ControllerId].PduReadIdx;
    while(readIndex  != Can_Drv_PendingPduNotifications[ControllerId].PduStoreIdx)
    {
#if(CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
        if((Can_Drv_PendingPduNotifications[ControllerId].PduInfo[readIndex].PeriodId == PeriodId)&&
            (Can_Drv_PendingPduNotifications[ControllerId].PduInfo[readIndex].NotifiedByCallBack == FALSE))
        {
            pduId = Can_Drv_PendingPduNotifications[ControllerId].PduInfo[readIndex].PduId;
            Can_Drv_PendingPduNotifications[ControllerId].PduInfo[readIndex].NotifiedByCallBack = TRUE;
#ifndef CAN_PLT_SAFERTOS_ENABLE			
            /*Invoke CanIf_TxConfirmation */
            Can_Drv_TxNotification(pduId);
#endif			
        }
#else
        pduId = Can_Drv_PendingPduNotifications[ControllerId].PduInfo[readIndex].PduId;
#ifndef CAN_PLT_SAFERTOS_ENABLE		
        Can_Drv_TxNotification(pduId);
#endif	
#endif
        readIndex = (uint8)(readIndex  + CANSS_ONE) % TX_PDU_LIST_MAX_ARR_SIZE;
    }
    Can_Drv_Delete_Pdu_FromPendingTxList(ControllerId, readIndex);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif

#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static void Can_Drv_EnablePEAInterrupts(uint8 ControllerId){
    uint8 canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;

    #if(CAN_FUSA_ENABLE == STD_OFF)                    
        /* After bus off recovery, Enable PEA interrupt */
        InterruptConfigVal[ControllerId] |= (uint32)CANSS_IR_PEA_BMSK;
        SET_CAN_HW_FIELD(canCtrId,IE,PEAE, CANSS_ONE);
    #endif

    #if(CAN_FUSA_ENABLE == STD_ON)                    
        /* After bus off recovery, Enable PEA interrupt */
        SET_CAN_HW_FIELD_OFFS(canCtrId,CANSS_ZERO,CANSS_FUSA_LEVEL_IRQ_MASK_n,IRQ_MASK, (uint32)CAN_FUSA_LEVEL_INTERRUPTS_MASK );
        /* Update the IE_RegValue variable for Register check feature */
        SchM_Enter_Can_Exclusive_Area_01();
        Can_ConfigReg[ControllerId].IE_RegValue = InterruptConfigVal[ControllerId];
        SchM_Exit_Can_Exclusive_Area_01();
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
Std_ReturnType Can_Drv_PollModeTransition
                               (uint8 ControllerId,
                                Can_ControllerStateType ControllerState)
{
    Std_ReturnType retValue = E_OK;
    boolean initMode = FALSE;
    uint8 regVal;
    uint8 canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
    switch(ControllerState)
    {
        case CAN_CS_STARTED:
            regVal =(uint8)IN_CAN_HW_FIELD(canCtrId,PSR,ACT);
            if(regVal == CANSS_ACT_IDLE)
            {
                Can_CtrlInfo[ControllerId].CanCtrlState = CAN_CS_STARTED;
                if(Can_BusOffRec[ControllerId] == TRUE){
                    Can_Drv_ProcessBusoff(ControllerId);
                }
            }
            else
            {
                retValue = E_NOT_OK;
            }
            break;
        case CAN_CS_STOPPED:
            initMode = (boolean)IN_CAN_HW_FIELD(canCtrId, CCCR, INT);
            if(initMode == TRUE)
            {
                Can_CtrlInfo[ControllerId].CanCtrlState = CAN_CS_STOPPED;
            }
            else
            {
                retValue = E_NOT_OK;
            }
            break;
        case CAN_CS_SLEEP:
            Can_CtrlInfo[ControllerId].CanCtrlState = CAN_CS_SLEEP;
            break;
        default:
            retValue = E_NOT_OK;
            break;
    }
    return retValue;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_CancelPendingTxMsgs(CAN_CtrIdType ControllerId)
{
    uint8 canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
    uint32 txBufPendingStatus =0;
    /*Get Information regarding pending Tx Messages */
    txBufPendingStatus =IN_CAN_HW_FIELD(canCtrId, TXBRP, TRP);
    /*Cancel the pending Tx Messages */
    SET_CAN_HW_FIELD(canCtrId, TXBCR, CR, (txBufPendingStatus));
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_ReadRxErrorCounter
                              (uint8 ControllerId,
                              uint8* RxErrorCounterPtr)
{
    uint8 canCtrId =(uint8)Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
    *RxErrorCounterPtr = (uint8)IN_CAN_HW_FIELD(canCtrId, ECR, REC);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_ReadTxErrorCounter
                            (uint8 ControllerId,
                             uint8* TxErrorCounterPtr)
{
   uint8 canCtrId = (uint8)Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
   *TxErrorCounterPtr =(uint8)IN_CAN_HW_FIELD(canCtrId, ECR, TEC);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_ReadErrorState
                            (uint8 ControllerId,
                            Can_ErrorStateType* ErrorStatePtr)
{
    Can_ErrorStateType errorState;
    uint8 canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
    /* Check if Controller is in Busoff State */
    if(IN_CAN_HW_FIELD(canCtrId, PSR, BO)!= CANSS_ZERO)
    {
        errorState = CAN_ERRORSTATE_BUSOFF;
    }
    /* Check if Controller is in Error Passive State */
    else if(IN_CAN_HW_FIELD(canCtrId, PSR, EP)!= CANSS_ZERO)
    {
        errorState = CAN_ERRORSTATE_PASSIVE;
    }
    else
    {
        errorState = CAN_ERRORSTATE_ACTIVE ;
    }
    *ErrorStatePtr = errorState;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_ProcessBusoff(uint8 ControllerId)
{
    if(ControllerId < NUMBER_OF_ACTIVE_CAN_CTRL)
    {
        uint8 canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
        if(IN_CAN_HW_FIELD(canCtrId, PSR, BO) != CANSS_ZERO)
        {
            if(Can_CtrlInfo[ControllerId].CanCtrlState == CAN_CS_STARTED)
            {
                Can_BusOffRec[ControllerId] = TRUE;
                Can_CtrlInfo[ControllerId].CanCtrlRequestedState = CAN_CS_STOPPED;
				Can_Drv_Config_Interrupts(ControllerId, CAN_CS_STOPPED);
                Can_CtrlInfo[ControllerId].CanCtrlState = CAN_CS_STOPPED;
                CanIf_ControllerBusOff(ControllerId);
            }
        }
        else
        {
            Can_BusOffRec[ControllerId] = FALSE;
            Can_Drv_EnablePEAInterrupts(ControllerId);
        }
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#if(CAN_ENABLE_SECURITY_EVENT == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_ProcessErrPassiveState(uint8 ControllerId)
{
    uint8 canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
    uint16 rxErrorCount = (uint16)IN_CAN_HW_FIELD(canCtrId ,ECR, REC);
    uint16 txErrorCount = (uint16)IN_CAN_HW_FIELD(canCtrId, ECR, TEC);
    CanIf_ControllerErrorStatePassive(ControllerId,rxErrorCount,txErrorCount);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_ProcessRxFIFO(Can_HwType mailBox, Can_RxBufferType rxFifoCfg
#ifdef CAN_PLT_SAFERTOS_ENABLE
                            , bool isIsr
#endif
                            )
{
    uint8 fillLevel;
    uint8 index;
    /*size of RX elements in number of words*/
    uint8 rxElementSize;
    Can_RXbuffFifoType* rxElem;
    uint8 objectId = Can_Drv_ConfigPtr->CanTxRxObjMapPtr[mailBox.Hoh].ObjIndex;
    const Can_CtrlConfigType *const ctrlConfig = &(Can_Drv_ConfigPtr->CanActiveCtrPtr[mailBox.ControllerId]);
    const Can_MsgRamConfigType *const pMRamConfig = ctrlConfig->CanMsgRamConfig;
    if ( CAN_RxFIFO0 == rxFifoCfg ) {
        /* Read message from RX FIFO 0 */
        fillLevel = (uint8)IN_CAN_HW_FIELD(ctrlConfig->CanCtrID,RXF0S,F0FL);
        rxElementSize = Can_Drv_GetRxElementSize(pMRamConfig->RxMaxFIFO0Dlc);
    }
    else
    {
        /* Read message from RX FIFO 1 */
        fillLevel = (uint8)IN_CAN_HW_FIELD(ctrlConfig->CanCtrID,RXF1S,F1FL);
        rxElementSize = Can_Drv_GetRxElementSize(pMRamConfig->RxMaxFIFO1Dlc);
    }
    while (fillLevel != CANSS_ZERO)
    {
        if ( CAN_RxFIFO0 == rxFifoCfg ) {
            index = (uint8)IN_CAN_HW_FIELD(ctrlConfig->CanCtrID,RXF0S,F0GI);
            rxElem = (Can_RXbuffFifoType*) IN_CAN_MRAM_BASE(ctrlConfig->CanCtrID,
                    ((uint32)(pMRamConfig->RxFIFO0StartAdd + ((uint32)rxElementSize * index))));
        }
        else{
            index = (uint8)IN_CAN_HW_FIELD(ctrlConfig->CanCtrID,RXF1S,F1GI);
            rxElem = (Can_RXbuffFifoType*) IN_CAN_MRAM_BASE(ctrlConfig->CanCtrID,
                     ((uint32)(pMRamConfig->RxFIFO1StartAdd +((uint32)rxElementSize * index))));
        }
#ifdef CAN_PLT_SAFERTOS_ENABLE
        Can_Drv_NotifyRxCallback(rxElem,mailBox,objectId,isIsr);
#else
        Can_Drv_NotifyRxCallback(rxElem,mailBox,objectId);
#endif
        // here zero is ignore as fifo doesn't have an index
        Can_Drv_AcknowledgeRx(ctrlConfig->CanCtrID, rxFifoCfg, index); 
        fillLevel--;
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_RxProcessBuffer(Can_HwType MailBox,
                                 uint8 RxBufferIndex)
{
    uint8  canCtrId;
    uint8  rxElementSize;
    uint64 ndatRegval;
    Can_RXbuffFifoType* rxBufferElement;
    const Can_CtrlConfigType *const ctrlConfig =&Can_Drv_ConfigPtr->CanActiveCtrPtr[MailBox.ControllerId];
    uint8 objectId = Can_Drv_ConfigPtr->CanTxRxObjMapPtr[MailBox.Hoh].ObjIndex;
    const Can_MsgRamConfigType *const pMRamConfig = ctrlConfig->CanMsgRamConfig ;
    /* load the actual controller Id */
    canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[MailBox.ControllerId].CanCtrID;
    /* load the buffer status */
    ndatRegval = (uint64) IN_CAN_HW_FIELD(canCtrId, NDAT1, ND);
    ndatRegval |= ((uint64)IN_CAN_HW_FIELD(canCtrId, NDAT2, ND) << ONE_INT_SIZE);
    rxElementSize = Can_Drv_GetRxElementSize(pMRamConfig->RxMaxBufferDlc);
    /* Check if the corresponding buffer received new data */
    if(RxBufferIndex < CANSS_UINT64_LEN)
    {
        if((ndatRegval & ((((uint64)CANSS_ONE) << RxBufferIndex))) != CANSS_ZERO)
        {
            /*Initialize the Message Ram Segment for the corresponding Rx Buffer Element */
            rxBufferElement = (Can_RXbuffFifoType*) IN_CAN_MRAM_BASE(ctrlConfig->CanCtrID,
                                ((uint32)pMRamConfig->RxBufferStartAdd + ((uint32)rxElementSize * RxBufferIndex)));
#ifdef CAN_PLT_SAFERTOS_ENABLE
            Can_Drv_NotifyRxCallback(rxBufferElement,MailBox,objectId,FALSE);
#else
            Can_Drv_NotifyRxCallback(rxBufferElement,MailBox,objectId);
#endif
            /* Provide Acknowlegement for the received data */
            Can_Drv_AcknowledgeRx(ctrlConfig->CanCtrID, CAN_RxDedicatedBuffer, RxBufferIndex);
        }
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_ClearCtrlInterrupts (uint8 ControllerId)
{
    uint32 interruptStatus=0;
    uint8 canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID; 
    interruptStatus= IN_CAN_HW_REG(canCtrId,IR); 
    /*Clearing INT0 and INT1 Interrupts */
    interruptStatus &= (IN_CAN_HW_REG(canCtrId,IE)); // Masking the enabled Interrupts
    if(interruptStatus != CANSS_ZERO)
    {        
        SET_CAN_HW_REG(canCtrId,IR,interruptStatus);//Acknowledge Interrupt 
    }
    /*Clearing DMA Interrupts */
    for(uint8 dmaChannel =0; dmaChannel <NUM_OF_CAN_DMA_CHANNELS; dmaChannel++)
    {
        interruptStatus = IN_CAN_HW_REG_OFFS(canCtrId, dmaChannel, CANSS_DMA_IRQ_STTS_CHNLn);
        interruptStatus &= IN_CAN_HW_REG_OFFS(canCtrId, dmaChannel, CANSS_DMA_IRQ_STTS_EN_CHNLn);  // Mask Disabled Interrupts
        if(interruptStatus == CANSS_ZERO)
        {
                continue;
        }
        SET_CAN_HW_REG_OFFS(canCtrId, dmaChannel, CANSS_DMA_IRQ_STTS_CLR_CHNLn, interruptStatus);  // Acknowledge Interrupt At Source
    }
    /*Clearing DMU Interrupts */
    interruptStatus=IN_CAN_HW_REG(canCtrId,DMUIR);
    if(interruptStatus != CANSS_ZERO)
    {        
        SET_CAN_HW_REG(canCtrId,DMUIR,interruptStatus); // Acknowledge Interrupt 
    }
    /*Clearing Hardware Filter Event Interrupts */
    SET_CAN_HW_REG(canCtrId,CANSS_M_CAN_FE_IRQ_STTS_CLR, CANSS_SEVEN);
                        
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_CtrlModeIndication
                             (uint8 ControllerId,
                              Can_ControllerStateType Can_ControllerIf_State)
{
    CanIf_ControllerModeIndication(ControllerId,Can_ControllerIf_State, CANIF_CTXT_TYPE_NON_ISR);
}
uint8 Can_Drv_ExtractConfigIndex(uint8 CanCtrID)
{
    uint8 CtrlIndex;
    uint8 ConfigIndex = 0;
    for(CtrlIndex=0u; CtrlIndex < NUMBER_OF_ACTIVE_CAN_CTRL ;CtrlIndex++)
    {
       if(Can_Drv_ConfigPtr->CanActiveCtrPtr[CtrlIndex].CanCtrID == CanCtrID)
       {
         ConfigIndex = CtrlIndex;
         break;
       }
    }
    return ConfigIndex;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static Can_HwHandleType Can_Drv_GetRxObjectIndex
                                                 (uint8 BufferId,
                                                  uint8 ControllerId)
{
    Can_HwHandleType rxObjectId  = 0;
    for(uint16 index=0;index<Can_Drv_ConfigPtr->CanNumOfRxHwObj;index++)
    {
     if(((Can_Drv_ConfigPtr->CanRxHwObjPtr[index].RxBufferIndex == BufferId) &&
            (Can_Drv_ConfigPtr->CanRxHwObjPtr[index].HwRxObjectCtrlrId == ControllerId) &&
                (Can_Drv_ConfigPtr->CanRxHwObjPtr[index].RxMsgBufType == CAN_RxDedicatedBuffer)))
     {
        rxObjectId  =(Can_HwHandleType)Can_Drv_ConfigPtr->CanRxHwObjPtr[index].HwRxObjectId;
        break;
     }
    }
    return rxObjectId  ;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static void Can_Drv_Memset(
                        void* Source,
                        uint32 Value,
                        uint32 WordLength)
{
    uint32 *dataPtr = Source;
    for(uint32 i=0;i<WordLength;i++)
    {
        *dataPtr = Value;
        dataPtr++;
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static void Can_Drv_Memcopy(
                        void* Dest,
                        const void* Src,
                        uint32 WordLength)
{
    uint32 *destPtr = (uint32*)Dest;
    const uint32* srcPtr;
#if( CAN_DEV_ERROR_DETECT == STD_ON)
    if(Src == NULL_PTR){
        return;
    }
    else
#endif
    {
        srcPtr = (const uint32*) Src;
        for(uint32 i=0;i<WordLength;i++)
        {
            *destPtr = *srcPtr;
            destPtr++;
            srcPtr++;
        }
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static uint32 ConvertToDLC (uint32 MsgLength)
{
    uint32 msgDLC;
    if (MsgLength <= 8UL)
    {
        msgDLC = MsgLength;
    }
    else if (MsgLength <= 12UL)
    {
        msgDLC = 9UL;
    }
    else if (MsgLength <= 16UL)
    {
        msgDLC = 10UL;
    }
    else if (MsgLength <= 20UL)
    {
        msgDLC = 11UL;
    }
    else if (MsgLength <= 24UL)
    {
        msgDLC = 12UL;
    }
    else if (MsgLength <= 32UL)
    {
        msgDLC = 13UL;
    }
    else if (MsgLength <= 48UL)
    {
        msgDLC = 14UL;
    }
    else
    {
        msgDLC = 15UL;
    }
    return msgDLC;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline Std_ReturnType Can_Drv_MRAM_ResetCheck(uint8 CanCtrID)
{
    uint32 resetStatus = 0x0;
    Std_ReturnType status = E_OK;
    resetStatus = IN_CAN_HW_FIELD(CanCtrID,CANSS_MRAM_STATUS,MRAM_RESET_DONE);

#ifndef CAN_PLT_SAFERTOS_ENABLE
#if(CAN_OS_COUNTER_SUPPORTED == STD_ON)
    TickType counter = 0;
    TickType startTick = 0;
    TickType currentTick = 0;
    TickType delay;
    delay = (TickType) (CAN_HW_WAIT_TIMEOUT / CAN_OS_SECONDS_PER_TICK);
    status = GetCounterValue(CAN_OS_COUNTER_ID, &startTick);
    if(status == E_OK){
        while((counter < delay) && (CANSS_ONE != resetStatus)){
            status = GetCounterValue(CAN_OS_COUNTER_ID,&currentTick);
            resetStatus = IN_CAN_HW_FIELD(CanCtrID,CANSS_MRAM_STATUS,MRAM_RESET_DONE);
            if(status == E_OK)
            {
                counter = currentTick - startTick ;
            }
            else
            {
                break;
            }
        }
    }
#endif
#else
    uint16_t Cnt= pdMS_TO_TICKS(CAN_HW_WAIT_TIMEOUT);
    while(CANSS_ONE != resetStatus){
        if (Cnt != CANSS_ZERO){
            (void)vFreeRTOSTaskDelay(CANSS_ONE);
            Cnt--;
            resetStatus = IN_CAN_HW_FIELD(CanCtrID,CANSS_MRAM_STATUS,MRAM_RESET_DONE);
        }
        else
        {
            break;
        }
    }
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

    if(CANSS_ONE != resetStatus){
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_INIT, CAN_E_INIT_FAILED);
#endif
        status = E_NOT_OK;
    }
    return status;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline Std_ReturnType Can_Drv_CCControlInit(
    const Can_CtrlConfigType *const ctrlConfig,
    uint8 ApiId)
{
    Std_ReturnType status = E_OK;
    uint32 regVal;
    regVal = IN_CAN_HW_FIELD(ctrlConfig->CanCtrID,CCCR,INT);
    if (regVal == CANSS_ZERO) {
#ifdef CAN_PLT_SAFERTOS_ENABLE
        CAN_Reg_Setting_Cnt[ctrlConfig->CanCtrID]++;
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID,CCCR,INT,CANSS_ONE);
        uint16_t Cnt= pdMS_TO_TICKS(CAN_INIT_WAIT_TIMEOUT);
         while(CANSS_ONE != regVal){
             if (Cnt != CANSS_ZERO){
                 (void)vFreeRTOSTaskDelay(CANSS_ONE);
                 Cnt--;
                 regVal = IN_CAN_HW_FIELD(ctrlConfig->CanCtrID,CCCR,INT);
             }
             else
             {
                 break;
             }
        }
        CAN_Reg_Setting_Cnt[ctrlConfig->CanCtrID]--;
#else
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID,CCCR,INT,CANSS_ONE);
#if(CAN_OS_COUNTER_SUPPORTED == STD_ON)
        TickType counter = 0;
        TickType startTick = 0;
        TickType currentTick = 0;
        TickType delay;
        delay = (TickType) (CAN_INIT_WAIT_TIMEOUT / CAN_OS_SECONDS_PER_TICK);
        status = GetCounterValue(CAN_OS_COUNTER_ID, &startTick);
        if(status == E_OK){
            while((counter < delay) && (CANSS_ONE != regVal)){
                status = GetCounterValue(CAN_OS_COUNTER_ID,&currentTick);
                regVal = IN_CAN_HW_FIELD(ctrlConfig->CanCtrID,CCCR,INT);
                if(status == E_OK)
                {
                    counter = currentTick - startTick ;
                }
                else
                {
                    break;
                }
            }
        }
#endif
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
    }
	regVal = IN_CAN_HW_FIELD(ctrlConfig->CanCtrID,CCCR,INT);
    if (CANSS_ONE != regVal) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID,
            ApiId, CAN_E_INIT_FAILED);
#endif
        status = (uint8)E_NOT_OK;
    }
    else{
#ifdef CAN_PLT_SAFERTOS_ENABLE
        CAN_Reg_Setting_Cnt[ctrlConfig->CanCtrID]++;
#endif
        /*Enable configuraion*/
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID,CCCR,CCE,CANSS_ONE);
#ifdef CAN_PLT_SAFERTOS_ENABLE
        CAN_Reg_Setting_Cnt[ctrlConfig->CanCtrID]--;
#endif
        status = (uint8)E_OK;
    }
    return status;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_CCControlResetInit (
    const Can_CtrlConfigType *const ctrlConfig,
    uint8 ApiId)
{
#ifdef CAN_PLT_SAFERTOS_ENABLE
    CAN_Reg_Setting_Cnt[ctrlConfig->CanCtrID]++;
#endif
    SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, CCCR, CCE, CANSS_ZERO);
#ifdef CAN_PLT_SAFERTOS_ENABLE
    CAN_Reg_Setting_Cnt[ctrlConfig->CanCtrID]--;
#endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void  Can_Drv_BaudRateConfig(
    const Can_NominalBaudConfigPtrType *const BaudrateConfig,
    uint8 ControllerId)
{
    const Can_DataBaudConfigPtrType *const pDataBaudRate = BaudrateConfig->DataBaudRatePtr;
    const Can_CtrlConfigType* ctrlConfig;
    ctrlConfig = &Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId];

#ifdef CAN_PLT_SAFERTOS_ENABLE
    CAN_Reg_Setting_Cnt[ctrlConfig->CanCtrID]++;
#endif
    /*set the nominal bit rate*/
    SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, NBTP, NTSEG1, ((uint32)BaudrateConfig->ControllerPropSeg + BaudrateConfig->ControllerPhaseSeg1));
    SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, NBTP, NTSEG2, (BaudrateConfig->ControllerPhaseSeg2));
    SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, NBTP, NBRP,(uint32) (BaudrateConfig->NominalBRPValue));
    SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, NBTP, NSJW, (uint32)(BaudrateConfig->ControllerSyncSeg));
    Can_Drv_BaudRate[ControllerId] = BaudrateConfig->Baudrate;
    if(NULL_PTR != pDataBaudRate){
        /*set the Data bit rate*/
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, DBTP, DTSEG1, ((uint32)pDataBaudRate->ControllerPropSeg +
            pDataBaudRate->ControllerPhaseSeg1));
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, DBTP, DTSEG2, (pDataBaudRate->ControllerPhaseSeg2));
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, DBTP, DBRP, (uint32)(pDataBaudRate->DataBRPValue));
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, DBTP, DSJW, (pDataBaudRate->ControllerSyncSeg));
        if(TRUE == pDataBaudRate->DelayEnable){
            SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, DBTP, TDC,(uint32)CANSS_ONE);
            SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TDCR, TDCF,(pDataBaudRate->TrcvCompDelayFilterLength));
            SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TDCR, TDCO, (pDataBaudRate->TrcvCompDelayOffset));
        }
        else{
            SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, DBTP, TDC,(uint32)CANSS_ZERO);
            SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TDCR, TDCF,(pDataBaudRate->TrcvCompDelayFilterLength));
            SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TDCR, TDCO, (pDataBaudRate->TrcvCompDelayOffset));
        }
        if(TRUE == pDataBaudRate->BrsSwitch){
            SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, CCCR, BRSE,(uint32)CANSS_ONE);
        }
        else{
            SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, CCCR, BRSE,(uint32)CANSS_ZERO);
        }
    }
    else
    {
        SET_CAN_HW_REG(ctrlConfig->CanCtrID, DBTP,DBTP_DEFAULT_VALUE);
        SET_CAN_HW_REG(ctrlConfig->CanCtrID, TDCR,CANSS_ZERO);
    }
#ifdef CAN_PLT_SAFERTOS_ENABLE
    CAN_Reg_Setting_Cnt[ctrlConfig->CanCtrID]--;
#endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_TimeStampConfig (
    uint8 ControllerId)
{
    const Can_CtrlConfigType* ctrlConfig;
    ctrlConfig = &Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId];
    /*Set the prescalar*/
    SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TSCC, TCP, ctrlConfig->CanTimeStampPreScalar);
    /*Set the time stamp type*/
    SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TSCC, TSS, CAN_INTERNAL);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void  Can_Drv_GlobalFilterConfig(
    uint8 ControllerId)
{
    const Can_CtrlConfigType *const ctrlConfig = &Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId];
    const Can_MsgRamConfigType *const pMRamConfig = ctrlConfig->CanMsgRamConfig;
    if(TRUE == pMRamConfig->AcceptNonMatchFrameSTDRXFIFO0){
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, GFC, ANFS, CANSS_ZERO);
    }
    else if(TRUE == pMRamConfig->AcceptNonMatchFrameSTDRXFIFO1){
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, GFC, ANFS, CANSS_ONE);
    }
    else{
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, GFC, ANFS, CANSS_THREE);
    }
    if(TRUE == pMRamConfig->AcceptNonMatchFrameEXTRXFIFO0){
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, GFC, ANFE, CANSS_ZERO);
    }
    else if(TRUE == pMRamConfig->AcceptNonMatchFrameEXTRXFIFO1){
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, GFC, ANFE, CANSS_ONE);
    }
    else{
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, GFC, ANFE, CANSS_THREE);
    }
    SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, GFC, RRFS, CANSS_ONE);
    SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, GFC, RRFE, CANSS_ONE);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void  Can_Drv_FilterConfig(
    uint8 ControllerId)
{
    const Can_CtrlConfigType *const ctrlConfig = &Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId];
    const Can_RxHOHType* pRxObjConfig;
    const Can_HwFilterConfigType* pFilterConfig;
    const Can_MsgRamConfigType *const pMRamConfig = ctrlConfig->CanMsgRamConfig;
    uint8 rxObjIdx,filterIdx;
    volatile Can_StdFilterType* stdFilterElement;
    volatile Can_ExtFilterType* extFilterElement;
    uint8 fecBits;
    /*Register Access*/
    stdFilterElement = (Can_StdFilterType*) (IN_CAN_MRAM_BASE(ctrlConfig->CanCtrID, CANSS_ZERO));
    extFilterElement = (Can_ExtFilterType*) (IN_CAN_MRAM_BASE(ctrlConfig->CanCtrID, (uint32)pMRamConfig->FilterListEXTStartAdd));
    /*Global Filter Configuration*/
    Can_Drv_GlobalFilterConfig(ControllerId);
    /*Standard ID Filter Configuration*/
    SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, SIDFC, LSS, (uint32)(pMRamConfig->StdandardIdFiltersCount));
    SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, SIDFC, FLSSA, (pMRamConfig->FilterListSTDStartAdd));
    /*Extended ID Filter Configuration*/
    SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, XIDFC, LSE, (uint32)(pMRamConfig->ExtendedIdFiltersCount));
    SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, XIDFC, FLESA, (pMRamConfig->FilterListEXTStartAdd));
    for (rxObjIdx=0x0; rxObjIdx < Can_Drv_ConfigPtr->CanNumOfRxHwObj; rxObjIdx++){
        if(Can_Drv_ConfigPtr->CanRxHwObjPtr[rxObjIdx].HwRxObjectCtrlrId == ControllerId){
            pRxObjConfig = &Can_Drv_ConfigPtr->CanRxHwObjPtr[rxObjIdx];
            pFilterConfig = pRxObjConfig->HwFilterPtr;
            if(pRxObjConfig->CanIdType == CAN_STANDARD_ID){
                for(filterIdx=0x0;filterIdx<pRxObjConfig->HwFilterCount; filterIdx++){
                    if(CAN_RxFIFO0 == pRxObjConfig->RxMsgBufType){
                        fecBits= CANSS_ONE;
                        stdFilterElement->SFID2 = (uint16)(pFilterConfig[filterIdx].HwFilterMask & CANSS_SMFE_SFID_MASK);
                    }
                    else if (CAN_RxFIFO1 == pRxObjConfig->RxMsgBufType){
                        fecBits= CANSS_TWO;
                        stdFilterElement->SFID2 = (uint16)(pFilterConfig[filterIdx].HwFilterMask & CANSS_SMFE_SFID_MASK);
                    }
                    else{
                        fecBits= CANSS_SEVEN;
                        stdFilterElement->SFID2 = (uint16)((uint16)pRxObjConfig->RxBufferIndex & CANSS_SMFE_SFID_MASK);
                        if((pFilterConfig[filterIdx].HwFilterEvent) != CANSS_NO_FILTER_EVENT && ((CANSS_SIX+pFilterConfig[filterIdx].HwFilterEvent) < CANSS_NINE)){
                            stdFilterElement->SFID2 |= (uint16)((uint16)CANSS_ONE <<(CANSS_SIX+pFilterConfig[filterIdx].HwFilterEvent));
                        }
                    }
                    stdFilterElement->SFT   = (uint32) pFilterConfig[filterIdx].HwFilterType & CANSS_SMFE_SFT_MASK;
                    stdFilterElement->SFEC  = (uint32) fecBits & CANSS_SMFE_SFEC_MASK;
                    stdFilterElement->SFID1 = (uint32) pFilterConfig[filterIdx].HwFilterValue & CANSS_SMFE_SFID_MASK;
                    /*Time stamp*/
                    stdFilterElement->SSYNC = CANSS_ZERO;
                    stdFilterElement++;
                }
            }
            else if (pRxObjConfig->CanIdType == CAN_EXTENDED_ID){
                for(filterIdx=0x0;filterIdx<pRxObjConfig->HwFilterCount; filterIdx++){
                    if((CAN_RxFIFO0 == pRxObjConfig->RxMsgBufType)){
                        fecBits= CANSS_ONE;
                        extFilterElement->EFID2 = pFilterConfig[filterIdx].HwFilterMask & CANSS_EMFE_EFID_MASK;
                    }
                    else if ((CAN_RxFIFO1 == pRxObjConfig->RxMsgBufType)){
                        fecBits= CANSS_TWO;
                        extFilterElement->EFID2 = pFilterConfig[filterIdx].HwFilterMask & CANSS_EMFE_EFID_MASK;
                    }
                    else{
                        fecBits= CANSS_SEVEN;
                        extFilterElement->EFID2 = pRxObjConfig->RxBufferIndex & CANSS_EMFE_EFID_MASK;
                        if(((pFilterConfig[filterIdx].HwFilterEvent) != CANSS_NO_FILTER_EVENT) && ((CANSS_SIX+pFilterConfig[filterIdx].HwFilterEvent) < CANSS_NINE)){
                            extFilterElement->EFID2 |= (uint16)((uint16)CANSS_ONE<<(CANSS_SIX+pFilterConfig[filterIdx].HwFilterEvent));
                        }
                    }
                    extFilterElement->EFID1 = pFilterConfig[filterIdx].HwFilterValue & CANSS_EMFE_EFID_MASK;
                    extFilterElement->EFEC  = (uint32) fecBits & CANSS_EMFE_EFEC_MASK;
                    /*Time stamp*/
                    extFilterElement->ESYNC = CANSS_ZERO;
                    extFilterElement->EFT   = (uint32) pFilterConfig[filterIdx].HwFilterType & CANSS_EMFE_EFT_MASK;
                    extFilterElement++;
                }
            }
            else{/*CAN_MIXED_ID*/
                for(filterIdx=0x0;filterIdx<pRxObjConfig->HwFilterCount; filterIdx++){
                    if((CAN_RxFIFO0 == pRxObjConfig->RxMsgBufType)){
                        fecBits= CANSS_ONE;
                        stdFilterElement->SFID2 = (uint32) pFilterConfig[filterIdx].HwFilterMask & CANSS_SMFE_SFID_MASK;
                        extFilterElement->EFID2 = pFilterConfig[filterIdx].HwFilterMask & CANSS_EMFE_EFID_MASK;
                    }
                    else if ((CAN_RxFIFO1 == pRxObjConfig->RxMsgBufType)){
                        fecBits= CANSS_TWO;
                        stdFilterElement->SFID2 = (uint32) pFilterConfig[filterIdx].HwFilterMask & CANSS_SMFE_SFID_MASK;
                        extFilterElement->EFID2 = pFilterConfig[filterIdx].HwFilterMask & CANSS_EMFE_EFID_MASK;
                    }
                    else{
                        fecBits= CANSS_SEVEN;
                        stdFilterElement->SFID2 = (uint32) pRxObjConfig->RxBufferIndex & CANSS_SMFE_SFID_MASK;
                        if(((pFilterConfig[filterIdx].HwFilterEvent) != CANSS_NO_FILTER_EVENT) && ((CANSS_SIX+pFilterConfig[filterIdx].HwFilterEvent) < CANSS_NINE)){
                            stdFilterElement->SFID2 |= (uint16)((uint16)CANSS_ONE<<(CANSS_SIX+pFilterConfig[filterIdx].HwFilterEvent));
                        }
                        extFilterElement->EFID2 = pRxObjConfig->RxBufferIndex & CANSS_EMFE_EFID_MASK;
                        if(((pFilterConfig[filterIdx].HwFilterEvent) != CANSS_NO_FILTER_EVENT) && ((CANSS_SIX+pFilterConfig[filterIdx].HwFilterEvent) < CANSS_NINE)){
                            extFilterElement->EFID2 |= (uint16)((uint16)CANSS_ONE<<(CANSS_SIX+pFilterConfig[filterIdx].HwFilterEvent));
                        }
                    }
                    stdFilterElement->SFT   =((uint32)pFilterConfig[filterIdx].HwFilterType & CANSS_SMFE_SFT_MASK);
                    stdFilterElement->SFEC  =(uint32) ((uint32)fecBits & CANSS_SMFE_SFEC_MASK);
                    stdFilterElement->SFID1 =((uint32) pFilterConfig[filterIdx].HwFilterValue & CANSS_SMFE_SFID_MASK);
                    /*Time stamp*/
                    stdFilterElement->SSYNC = CANSS_ZERO;
                    stdFilterElement++;
                    extFilterElement->EFID1 = pFilterConfig[filterIdx].HwFilterValue & CANSS_EMFE_EFID_MASK;
                    extFilterElement->EFEC  = (uint32) ((uint32)fecBits & CANSS_EMFE_EFEC_MASK);
                    /*Time stamp*/
                    extFilterElement->ESYNC = CANSS_ZERO;
                    extFilterElement->EFT   = ((uint32)pFilterConfig[filterIdx].HwFilterType & CANSS_EMFE_EFT_MASK);
                    extFilterElement++;
                }
            }
        }
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void  Can_Drv_RxConfig(uint8 ControllerId)
{
    uint32 regBits = CANSS_ZERO;
    const Can_CtrlConfigType* ctrlConfig;
    ctrlConfig = &Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId];
    const Can_MsgRamConfigType *const pMRamConfig = ctrlConfig->CanMsgRamConfig;
    if(TRUE == pMRamConfig->RxBufferUsed){
        /*read all bits in NDAT1 register and if any bits are not zero then clear those bits*/
        regBits = IN_CAN_HW_FIELD(ctrlConfig->CanCtrID, NDAT1, ND);
        if(regBits != CANSS_ZERO){
            /* writing 1 clears the NDAT1 register bits */
            SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, NDAT1, ND, regBits);
        }
        /*read all bits in NDAT2 register and if any bits are not zero then clear those bits*/
        regBits = IN_CAN_HW_FIELD(ctrlConfig->CanCtrID, NDAT2, ND);
        if(regBits != CANSS_ZERO){
            /* writing 1 clears the NDAT1 register bits */
            SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, NDAT2, ND, regBits);
        }
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, RXBC, RBSA, (pMRamConfig->RxBufferStartAdd));
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, RXESC, RBDS, (uint32)(pMRamConfig->RxMaxBufferDlc ));
    }
    if( TRUE == pMRamConfig->RxFIFO0Used){
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, RXF0C, F0OM, (uint32)CANSS_ZERO);
		if(CAN_INTERRUPT_ON_WATERMARK == ctrlConfig->CanRxProcessing){
			SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, RXF0C, F0WM, (uint32)(ctrlConfig->CanRxFifo0WaterMark));
		}
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, RXF0C, F0S, (uint32)(pMRamConfig->RxFifo0BufferCount));
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, RXF0C, F0SA, (pMRamConfig->RxFIFO0StartAdd));
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, RXF0A, F0AI, (uint32)CANSS_ZERO);
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, RXESC, F0DS, (pMRamConfig->RxMaxFIFO0Dlc));
    }
    if( TRUE == pMRamConfig->RxFIFO1Used){
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, RXF1C, F1OM,(uint32)CANSS_ZERO);
        if(CAN_INTERRUPT_ON_WATERMARK == ctrlConfig->CanRxProcessing){
			SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, RXF1C, F1WM,(uint32)(ctrlConfig->CanRxFifo1WaterMark));
		}
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, RXF1C, F1S,(uint32)(pMRamConfig->RxFifo1BufferCount));
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, RXF1C, F1SA, (pMRamConfig->RxFIFO1StartAdd));
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, RXF1A, F1AI,(uint32)CANSS_ZERO);
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, RXESC, F1DS,(pMRamConfig->RxMaxFIFO1Dlc));
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void  Can_Drv_TxConfig(uint8 ControllerId)
{
    uint32 activeTxBuffers = CANSS_ZERO;
    const Can_CtrlConfigType* ctrlConfig;
    ctrlConfig = &Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId];
    const Can_MsgRamConfigType *const pMRamConfig = ctrlConfig->CanMsgRamConfig;
    if(TRUE == pMRamConfig->TxFIFOUsed){
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TXBC, TFQM,(uint32)CANSS_ZERO);
    }
    else if(TRUE == pMRamConfig->TxQUEUEUsed){
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TXBC, TFQM,(uint32)CANSS_ONE);
    }
    else{
        /*do nothing - To avoid Misra warning*/
    }
    SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TXBC, TFQS,(uint32)(pMRamConfig->TxFIFOQueueCount));
    SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TXBC, NDTB,(uint32)(pMRamConfig->TxBufferCount));
    SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TXBC, TBSA, (pMRamConfig->TxBufferStartAdd));
    SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TXESC, TBDS, (pMRamConfig->TxMaxBufferDlc));
    if( CAN_POLLING != ctrlConfig->CanTxProcessing ){
#if(CAN_DEV_ERROR_DETECT == STD_ON)
        if(pMRamConfig->TxBufferCount < CANSS_UINT32_LEN)
#endif
        {
        //evaluating the bits that represent active TX buffers
        activeTxBuffers = ((uint32)CANSS_ONE << pMRamConfig->TxBufferCount) - CANSS_ONE;
        }
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TXBTIE, TIE, (activeTxBuffers));
    }
    SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TXBCIE, CFIE, CANSS_ZERO);
    if(TRUE == pMRamConfig->TxEventFIFOUsed){
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TXEFC, EFWM,(uint32)(ctrlConfig->CanTxFifoWaterMark));
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TXEFC, EFS,(uint32)(pMRamConfig->TxEventFIFOCount));
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TXEFC, EFSA, (pMRamConfig->TxEventFIFOStartAdd));
        SET_CAN_HW_FIELD(ctrlConfig->CanCtrID, TXEFA, EFA,(uint32)CANSS_ZERO);
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"								
#ifdef CAN_PLT_SAFERTOS_ENABLE								
static inline void Can_Drv_TxNotification(uint8 ControllerId, PduIdType swPduHandle, 
                                        Can_TimeStampType timeStamp, Can_HwHandleType HwObjId,
                                        bool isIsr)								
#else
static inline void Can_Drv_TxNotification(PduIdType swPduHandle)
#endif	
{
#ifdef CAN_PLT_SAFERTOS_ENABLE
    if (TRUE == isIsr)
    {
	    CanIf_TxConfirmation(ControllerId, swPduHandle, timeStamp, HwObjId, CANIF_CTXT_TYPE_ISR);
    }
    else
    {
        CanIf_TxConfirmation(ControllerId, swPduHandle, timeStamp, HwObjId, CANIF_CTXT_TYPE_NON_ISR);
    }
#else
    CanIf_TxConfirmation(swPduHandle);
#endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#ifdef CAN_PLT_SAFERTOS_ENABLE	
static inline void Can_Drv_RxNotification(Can_HwType MailBoxInfo,
                                           PduInfoType PduInfo, 
										   Can_TimeStampType timeStamp,
										   bool isIsr) 
{
    CanIf_RxIndication(&MailBoxInfo,&PduInfo,timeStamp,isIsr);
}
#else
static inline void Can_Drv_RxNotification(Can_HwType MailBoxInfo,
                                           PduInfoType PduInfo); 
{
    CanIf_RxIndication(&MailBoxInfo,&PduInfo);
}	

#endif

#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_SetIdleMode(uint8 ControllerId)
{
    uint8 canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
    boolean regVal;

#ifdef CAN_PLT_SAFERTOS_ENABLE
    uint16_t Cnt= pdMS_TO_TICKS(CAN_TIMEOUT_DURATION);
    /* Cancel Pending Tx Messages */
    Can_Drv_CancelPendingTxMsgs(ControllerId);
    /* Disable Interrupts */
    Can_Drv_Config_Interrupts(ControllerId,CAN_CS_STOPPED);
    CAN_Reg_Setting_Cnt[canCtrId]++;
    /* Set to Initialisation Mode and enable write access to protected registers */
    SET_CAN_HW_FIELD(canCtrId, CCCR, INT, CANSS_ONE);
    CAN_Reg_Setting_Cnt[canCtrId]--;
    regVal = (boolean)IN_CAN_HW_FIELD(canCtrId, CCCR, INT);

    while(regVal != TRUE){
        if (Cnt != CANSS_ZERO){
            (void)vFreeRTOSTaskDelay(CANSS_ONE);
            Cnt--;
            regVal =(boolean)IN_CAN_HW_FIELD(canCtrId, CCCR, INT);
        }
        else
        {
            break;
        }
    }
#else
#if(CAN_OS_COUNTER_SUPPORTED == STD_ON)
    TickType counter = 0;
    TickType startTick = 0;
    TickType currentTick = 0;
    StatusType status;
    TickType delay;
#endif
    /* Cancel Pending Tx Messages */
    Can_Drv_CancelPendingTxMsgs(ControllerId);
    /* Disable Interrupts */
    Can_Drv_Config_Interrupts(ControllerId,CAN_CS_STOPPED);
    /* Set to Initialisation Mode and enable write access to protected registers */
    SET_CAN_HW_FIELD(canCtrId, CCCR, INT, CANSS_ONE);
#if(CAN_OS_COUNTER_SUPPORTED == STD_ON)
    regVal = (boolean)IN_CAN_HW_FIELD(canCtrId, CCCR, INT);
    delay = (TickType) (CAN_TIMEOUT_DURATION / CAN_OS_SECONDS_PER_TICK);
    status = GetCounterValue(CAN_OS_COUNTER_ID,&startTick);
    if(status == E_OK)
    {
        while((regVal != TRUE) && (counter < delay))
        {
            status = GetCounterValue(CAN_OS_COUNTER_ID,&currentTick);
            if(status == E_OK)
            {
                counter = currentTick - startTick ;
            }
            else
            {
                break;
            }
            regVal =(boolean)IN_CAN_HW_FIELD(canCtrId, CCCR, INT);
        }
    }
#endif
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_SetNormalMode(uint8 ControllerId)
{
    uint8 canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
	uint8 regVal;
#ifdef CAN_PLT_SAFERTOS_ENABLE
    uint16_t Cnt= pdMS_TO_TICKS(CAN_TIMEOUT_DURATION);
#if(CAN_FUSA_ENABLE == STD_ON)
    Std_ReturnType retVal = E_OK;
    if((CanFusa_Cntrl_In_SafeState(ControllerId)== TRUE) 
                    &&(CanFusa_Cntrl_GetCurFaultCode(ControllerId)== CAN_FUSA_FLT_CODE_CFG_MISMATCH))
    {
        retVal = CanFusa_ReInit_Controller(ControllerId);
    }
    if(retVal == E_OK)
#endif
    {
        Can_Drv_Config_Interrupts(ControllerId,CAN_CS_STARTED);
        CAN_Reg_Setting_Cnt[canCtrId]++;
        /* Set to Normal Mode */
        SET_CAN_HW_FIELD(canCtrId, CCCR, INT, CANSS_ZERO);
        CAN_Reg_Setting_Cnt[canCtrId]--;
    }

    regVal =(uint8)IN_CAN_HW_FIELD(canCtrId,PSR,ACT);

    while(regVal != CANSS_ACT_IDLE){
        if (Cnt != CANSS_ZERO){
           (void)vFreeRTOSTaskDelay(CANSS_ONE);
           Cnt--;
              regVal =(uint8)IN_CAN_HW_FIELD(canCtrId,PSR,ACT);
        }
        else
        {
            break;
        }
    }
#else
#if(CAN_OS_COUNTER_SUPPORTED == STD_ON)
        TickType counter = 0;
        TickType startTick = 0;
        TickType currentTick = 0;
        StatusType status;
        TickType delay;
#endif
#if(CAN_FUSA_ENABLE == STD_ON)
        Std_ReturnType retVal = E_OK;
        if((CanFusa_Cntrl_In_SafeState(ControllerId)== TRUE) 
                        &&(CanFusa_Cntrl_GetCurFaultCode(ControllerId)== CAN_FUSA_FLT_CODE_CFG_MISMATCH))
        {
            retVal = CanFusa_ReInit_Controller(ControllerId);
        }
        if(retVal == E_OK)
#endif
        {
            Can_Drv_Config_Interrupts(ControllerId,CAN_CS_STARTED);
            /* Set to Normal Mode */
            SET_CAN_HW_FIELD(canCtrId, CCCR, INT, CANSS_ZERO);
        }
#if(CAN_OS_COUNTER_SUPPORTED == STD_ON)
        regVal =(uint8)IN_CAN_HW_FIELD(canCtrId,PSR,ACT);
        delay = (TickType) (CAN_TIMEOUT_DURATION / CAN_OS_SECONDS_PER_TICK);
        status = GetCounterValue(CAN_OS_COUNTER_ID,&startTick);
        if(status == E_OK)
        {
            while((regVal != CANSS_ACT_IDLE) && 
                  (counter < delay))
            {
                status = GetCounterValue(CAN_OS_COUNTER_ID,&currentTick);
                if(status == E_OK)
                {
                    counter = currentTick - startTick ;
                }
                else
                {
                    break;
                }
                regVal =(uint8)IN_CAN_HW_FIELD(canCtrId,PSR,ACT);
            }
        }
#endif
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_SetSleepMode(uint8 ControllerId)
{
    /* Empty */
    /* Added for future requirements */
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_SetUnintMode(uint8 ControllerId)
{
    Can_Drv_Config_Interrupts(ControllerId , CAN_CS_UNINIT);
#ifdef CAN_PLT_SAFERTOS_ENABLE
    (void)Can_Safertos_Interrupt_Deregister(ControllerId);
    (void)Can_Safertos_Disable_Clock(ControllerId);
#endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_MRAM_Init(uint8 ControllerId)
{
    uint8 canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
    uint32  *pMRAM_StartAddress;
    pMRAM_StartAddress = (uint32*)(Can_Controller_Arr[canCtrId] + (uint32)CANSS_MRAM_REG_BASE_OFFS);
    Can_Drv_Memset(pMRAM_StartAddress,CANSS_ZERO,Can_Controller_Max_Mram[canCtrId]);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#if(CAN_GLOBAL_TIME_SUPPORT == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
Std_ReturnType Can_Drv_GetCurrentTime (
    uint8 ControllerId,
    Can_TimeStampType* TimeStampPtr)
{
    uint8 canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
    return Can_Drv_Get_CanBitTimeStamp(ControllerId,
            (uint16)IN_CAN_HW_FIELD(canCtrId,TSCV,TSC), TimeStampPtr);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_EnableEgressTimeStamp (
    Can_HwHandleType TxObjID)
{
    Can_Drv_EnableEgressObject[TxObjID] = TRUE;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
Std_ReturnType Can_Drv_GetEgressTimeStamp (
    PduIdType TxPduId,
    Can_HwHandleType Hth,
    Can_TimeStampType* TimeStampPtr)
{
    Std_ReturnType status = E_NOT_OK;
    uint8 txObjId = Can_Drv_ConfigPtr->CanTxRxObjMapPtr[Hth].ObjIndex;
    uint8 controllerId = Can_Drv_ConfigPtr->CanTxHwObjPtr[txObjId].HwTxObjectCtrlrId;
    uint8 timeStampIndex = 0;
    if(Can_Drv_EnableEgressObject[txObjId] == (uint8) TRUE){
        while(timeStampIndex < CANSS_TX_TIMESTAMP_FIFO_SIZE){
            if(TxPduId == Can_Drv_TxTimeStamp[controllerId][timeStampIndex].PduId){
                status = Can_Drv_Get_CanBitTimeStamp(controllerId,
                    Can_Drv_TxTimeStamp[controllerId][timeStampIndex].TimeStamp, TimeStampPtr);
                    Can_Drv_TxTimeStamp[controllerId][timeStampIndex].CanId = 0;
                    Can_Drv_TxTimeStamp[controllerId][timeStampIndex].PduId = 0;
                    break;
            }
            timeStampIndex++;
        }
    }
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if(timeStampIndex == CANSS_TX_TIMESTAMP_FIFO_SIZE){
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID,
                CAN_SID_GETEGRESSTIMESTAMP, CAN_E_PARAM_LPDU);
    }
#endif
    return status;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
Std_ReturnType Can_Drv_GetIngressTimeStamp (
    Can_HwHandleType Hrh,
    Can_TimeStampType* TimeStampPtr)
{
    uint8 objectId = Can_Drv_ConfigPtr->CanTxRxObjMapPtr[Hrh].ObjIndex;
    uint8 controllerId = Can_Drv_ConfigPtr->CanRxHwObjPtr[objectId].HwRxObjectCtrlrId;
    return Can_Drv_Get_CanBitTimeStamp(controllerId, Can_Drv_RxTimeStamp[objectId], TimeStampPtr);
}
static inline Std_ReturnType Can_Drv_Get_CanBitTimeStamp(
        uint8 ControllerId,
        uint16 TimeStamp,
        Can_TimeStampType* TimeStampPtr)
{
    Std_ReturnType status= E_OK;
    uint8 prescalar;
    uint8 ctrlrId;
    uint64 timeStampCount;
    uint64 timeInNs;
    uint32 canBitnInNsec;
    if(Can_Drv_BaudRate[ControllerId] == CANSS_ZERO){
        status = E_NOT_OK;
    }
    else{
        /*Physical Controller Number*/
        ctrlrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
        prescalar = (uint8) IN_CAN_HW_FIELD(ctrlrId,TSCC,TCP);
        timeStampCount = (((((uint64)Can_Drv_TSWrapCounter[ControllerId])   <<
                           CAN_INTERNAL_TIMESTAMP_NUM_BITS) |     TimeStamp)    *
                          ((uint64)prescalar + CANSS_ONE));
        /*
         Can_Drv_BaudRate[ControllerId] has the nominal baud rate configured in KBPS
         can_bit_in_sec = 1/(Can_Drv_BaudRate[ControllerId] * 1000);
         can_bitn_in_nsec = can_bit_in_sec x 10^9;
         hence
         can_bitn_in_nsec = 10^9 /(Can_Drv_BaudRate[ControllerId] * 1000);
                          = 10^6 / Can_Drv_BaudRate[ControllerId]
         TIMESTAMP_CAN_BIT_TO_NS = 10^6
        */
        canBitnInNsec = TIMESTAMP_CAN_BIT_TO_NS / Can_Drv_BaudRate[ControllerId];
        timeInNs = timeStampCount * canBitnInNsec;
        TimeStampPtr -> seconds = (uint32) (timeInNs / TIMESTAMP_NANO_SEC_DEVISOR);
        TimeStampPtr -> nanoseconds = (uint32) (timeInNs % TIMESTAMP_NANO_SEC_DEVISOR);
    }
    return status;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#if (CAN_DMA_ENABLE == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_DMA_Init(uint8 ControllerId)
{
    uint8 canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
    const Can_CtrlConfigType *const pCtrlConfig =&Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId];
    const Can_MsgRamConfigType *const pMRamConfig = pCtrlConfig-> CanMsgRamConfig;
    if(pCtrlConfig->CanDmaEnable !=FALSE)
    {
        Can_Drv_DMA_TxDesc_buffers_init(ControllerId);
        Can_Drv_DMA_RxDesc_buffers_init(ControllerId);
        if(pMRamConfig->TxFIFOUsed!= FALSE)
        {
            DmaTxDescAval[ControllerId]=TRUE;
            /* For enabling DMA Configurations for Tx Objects */
            SET_CAN_HW_FIELD_OFFS(canCtrId, CAN_DMA_TX_CHANNEL, CANSS_DMA_CTRL_CHNLn, SW_CMD_TRIGGER_EN, CANSS_ONE);
            SET_CAN_HW_FIELD_OFFS(canCtrId, CAN_DMA_TX_CHANNEL, CANSS_DMA_CONFIG_CHNLn, USE_HMEMTYPE_LAST_ON_DESC_OR_CHAIN, CANSS_ONE);
            SET_CAN_HW_FIELD_OFFS(canCtrId, CAN_DMA_TX_CHANNEL, CANSS_NEXT_DMA_DESC_ADDR_CHNLn, NEXT_DESC_ADDR,(uint32)&CAN_DMA_TX_CMD_Descriptors[ControllerId][0]);
            SET_CAN_HW_FIELD_OFFS(canCtrId, CAN_DMA_TX_CHANNEL, CANSS_DMA_CTRL_CHNLn, DMA_CHANNEL_EN, CANSS_ONE);
            /*Enable Interrupts for CAN_DMA_TX_CHANNEL*/
            /* AHB Error Interrupt*/
            SET_CAN_HW_FIELD_OFFS(canCtrId,CAN_DMA_TX_CHANNEL,CANSS_DMA_IRQ_STTS_EN_CHNLn,DMA_AHB_ERROR_EN,CANSS_ONE);
            /* Transfer Done Interrupt*/
            SET_CAN_HW_FIELD_OFFS(canCtrId,CAN_DMA_TX_CHANNEL,CANSS_DMA_IRQ_STTS_EN_CHNLn,DMA_TRANS_DONE_EN,CANSS_ONE);
        }
        if(pMRamConfig->TxEventFIFOUsed!= FALSE)
        {
            /* For enabling DMA Configurations for Tx Event*/
            SET_CAN_HW_FIELD_OFFS(canCtrId, CAN_DMA_TXE_CHANNEL, CANSS_DMA_CTRL_CHNLn, DMU_TXER_EN, CANSS_ONE);
            SET_CAN_HW_FIELD_OFFS(canCtrId, CAN_DMA_TXE_CHANNEL, CANSS_DMA_CONFIG_CHNLn, USE_HMEMTYPE_LAST_ON_DESC_OR_CHAIN, CANSS_ONE);
            SET_CAN_HW_FIELD_OFFS(canCtrId, CAN_DMA_TXE_CHANNEL, CANSS_NEXT_DMA_DESC_ADDR_CHNLn, NEXT_DESC_ADDR,(uint32)&CAN_DMA_TX_Event_CMD_Descriptors[ControllerId][0]);
            SET_CAN_HW_FIELD_OFFS(canCtrId, CAN_DMA_TXE_CHANNEL, CANSS_DMA_CTRL_CHNLn, DMA_CHANNEL_EN, CANSS_ONE);
            /*Enable Interrupts for CAN_DMA_TXE_CHANNEL*/
            /* AHB Error Interrupt*/
            SET_CAN_HW_FIELD_OFFS(canCtrId,CAN_DMA_TXE_CHANNEL,CANSS_DMA_IRQ_STTS_EN_CHNLn,DMA_AHB_ERROR_EN,CANSS_ONE);
            /* Transfer Done Interrupt*/
            SET_CAN_HW_FIELD_OFFS(canCtrId,CAN_DMA_TXE_CHANNEL,CANSS_DMA_IRQ_STTS_EN_CHNLn,DMA_TRANS_DONE_EN,CANSS_ONE);
        }
        if(pMRamConfig->RxFIFO0Used!= FALSE)
        {
            /* For enabling DMA Configurations for Rx Objects */
            SET_CAN_HW_FIELD_OFFS(canCtrId, CAN_DMA_RX0_CHANNEL, CANSS_DMA_CTRL_CHNLn, DMU_RX0R_EN, CANSS_ONE);
            SET_CAN_HW_FIELD_OFFS(canCtrId, CAN_DMA_RX0_CHANNEL, CANSS_DMA_CONFIG_CHNLn, USE_HMEMTYPE_LAST_ON_DESC_OR_CHAIN, CANSS_ONE);
            SET_CAN_HW_FIELD_OFFS(canCtrId, CAN_DMA_RX0_CHANNEL, CANSS_NEXT_DMA_DESC_ADDR_CHNLn, NEXT_DESC_ADDR,
                                                            (uint32)&CAN_DMA_RX_FIFO_0_CMD_Descriptors[ControllerId][0]);
            SET_CAN_HW_FIELD_OFFS(canCtrId, CAN_DMA_RX0_CHANNEL, CANSS_DMA_CTRL_CHNLn, DMA_CHANNEL_EN, CANSS_ONE);
            /*Enable Interrupts for CAN_DMA_RX0_CHANNEL*/
            /* AHB Error Interrupt*/
            SET_CAN_HW_FIELD_OFFS(canCtrId,CAN_DMA_RX0_CHANNEL,CANSS_DMA_IRQ_STTS_EN_CHNLn,DMA_AHB_ERROR_EN,CANSS_ONE);
            /* Transfer Done Interrupt*/
            SET_CAN_HW_FIELD_OFFS(canCtrId,CAN_DMA_RX0_CHANNEL,CANSS_DMA_IRQ_STTS_EN_CHNLn,DMA_TRANS_DONE_EN,CANSS_ONE);
        }
        if(pMRamConfig->RxFIFO1Used!= FALSE)
        {
            SET_CAN_HW_FIELD_OFFS(canCtrId, CAN_DMA_RX1_CHANNEL, CANSS_DMA_CTRL_CHNLn, DMU_RX1R_EN, CANSS_ONE);
            SET_CAN_HW_FIELD_OFFS(canCtrId, CAN_DMA_RX1_CHANNEL, CANSS_DMA_CONFIG_CHNLn, USE_HMEMTYPE_LAST_ON_DESC_OR_CHAIN, CANSS_ONE);
            SET_CAN_HW_FIELD_OFFS(canCtrId, CAN_DMA_RX1_CHANNEL, CANSS_NEXT_DMA_DESC_ADDR_CHNLn, NEXT_DESC_ADDR,
                                                                                                      (uint32)&CAN_DMA_RX_FIFO_1_CMD_Descriptors[ControllerId][0]);
            SET_CAN_HW_FIELD_OFFS(canCtrId, CAN_DMA_RX1_CHANNEL, CANSS_DMA_CTRL_CHNLn, DMA_CHANNEL_EN, CANSS_ONE);
            /*Enable Interrupts for CAN_DMA_RX1_CHANNEL*/
            /* AHB Error Interrupt*/
            SET_CAN_HW_FIELD_OFFS(canCtrId,CAN_DMA_RX1_CHANNEL,CANSS_DMA_IRQ_STTS_EN_CHNLn,DMA_AHB_ERROR_EN,CANSS_ONE);
            /* Transfer Done Interrupt*/
            SET_CAN_HW_FIELD_OFFS(canCtrId,CAN_DMA_RX1_CHANNEL,CANSS_DMA_IRQ_STTS_EN_CHNLn,DMA_TRANS_DONE_EN,CANSS_ONE);
        }
    }
    else
    {
        //Do Nothing
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_DMA_TxDesc_buffers_init(uint8 ControllerId)
{
   uint8 dmaDescIndex = 0;
   const Can_CtrlConfigType *const pCtrlConfig =&Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId];
   const Can_MsgRamConfigType *const pMRamConfig = pCtrlConfig-> CanMsgRamConfig;
   if(pMRamConfig->TxFIFOUsed!= FALSE)
   {
       /*for initializing Descriptor buffers for Tx */
       for(dmaDescIndex =0;dmaDescIndex <TX_CMD_MAX_DMA_DESC;dmaDescIndex++)
       {
           CAN_DMA_TX_CMD_Descriptors[ControllerId][dmaDescIndex].TransferDataAddress = (uint32 *)(&Can_DMA_Tx_Data_Buffer[ControllerId][dmaDescIndex]);
           if(dmaDescIndex == (TX_CMD_MAX_DMA_DESC - CANSS_ONE))
           {
               CAN_DMA_TX_CMD_Descriptors[ControllerId][dmaDescIndex].NextDescriptorAddress= (uint32*)&CAN_DMA_TX_CMD_Descriptors[ControllerId][0];
           }
           else
           {
               CAN_DMA_TX_CMD_Descriptors[ControllerId][dmaDescIndex].NextDescriptorAddress= (uint32*)&CAN_DMA_TX_CMD_Descriptors[ControllerId][dmaDescIndex + CANSS_ONE];
           }
           CAN_DMA_TX_CMD_Descriptors[ControllerId][dmaDescIndex].DestinationAddress =(uint32*)0x200;
           CAN_DMA_TX_CMD_Descriptors[ControllerId][dmaDescIndex].TransferDirection = CANSS_ONE;
           CAN_DMA_TX_CMD_Descriptors[ControllerId][dmaDescIndex].TransferFragment = CANSS_ZERO;
           CAN_DMA_TX_CMD_Descriptors[ControllerId][dmaDescIndex].Reserved = CANSS_ZERO;
           CAN_DMA_TX_CMD_Descriptors[ControllerId][dmaDescIndex].ZeroValues = CANSS_ZERO;
           CAN_DMA_TX_CMD_Descriptors[ControllerId][dmaDescIndex].Transferlength = CANSS_ZERO;
       }
   }
   if(pMRamConfig->TxEventFIFOUsed!= FALSE)
   {
       /*for initializing Descriptor buffers for Tx Event */
       for(dmaDescIndex =0;dmaDescIndex <TX_EVENT_CMD_MAX_DMA_DESC;dmaDescIndex++)
       {
           CAN_DMA_TX_Event_CMD_Descriptors[ControllerId][dmaDescIndex].TransferDataAddress =(uint32*)&Can_DMA_TxEvent_Data_Buffer[ControllerId][dmaDescIndex];
           if(dmaDescIndex == (TX_EVENT_CMD_MAX_DMA_DESC - CANSS_ONE))
           {
               CAN_DMA_TX_Event_CMD_Descriptors[ControllerId][dmaDescIndex].NextDescriptorAddress= (uint32*)&CAN_DMA_TX_Event_CMD_Descriptors[ControllerId][0];
           }
           else
           {
               CAN_DMA_TX_Event_CMD_Descriptors[ControllerId][dmaDescIndex].NextDescriptorAddress= (uint32*)&CAN_DMA_TX_Event_CMD_Descriptors[ControllerId][dmaDescIndex+CANSS_ONE];
           }
           CAN_DMA_TX_Event_CMD_Descriptors[ControllerId][dmaDescIndex].DestinationAddress =(uint32*)0x380;
           CAN_DMA_TX_Event_CMD_Descriptors[ControllerId][dmaDescIndex].TransferDirection = 0x0;
           CAN_DMA_TX_Event_CMD_Descriptors[ControllerId][dmaDescIndex].TransferFragment = 0x0;
           CAN_DMA_TX_Event_CMD_Descriptors[ControllerId][dmaDescIndex].Reserved = 0x0;
           CAN_DMA_TX_Event_CMD_Descriptors[ControllerId][dmaDescIndex].ZeroValues = 0x0;
           CAN_DMA_TX_Event_CMD_Descriptors[ControllerId][dmaDescIndex].Transferlength = 0x8;
       }
   }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_DMA_RxDesc_buffers_init(uint8 ControllerId)
{
   uint8 dmaDescIndex = 0;
   const Can_CtrlConfigType* pCtrlConfig =&Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId];
   const Can_MsgRamConfigType* pMRamConfig = pCtrlConfig-> CanMsgRamConfig;
   if(pMRamConfig->RxFIFO0Used!= FALSE)
   {
       /*for initializing Descriptor buffers for Rx FIFO 0 */
       for(dmaDescIndex =0;dmaDescIndex <RX_FIFO_0_CMD_MAX_DMA_DESC;dmaDescIndex++)
       {
           CAN_DMA_RX_FIFO_0_CMD_Descriptors[ControllerId][dmaDescIndex].TransferDataAddress =(uint32*)&Can_DMA_Rx0_Data_Buffer[ControllerId][dmaDescIndex];
           if(dmaDescIndex == (RX_FIFO_0_CMD_MAX_DMA_DESC - CANSS_ONE))
           {
               CAN_DMA_RX_FIFO_0_CMD_Descriptors[ControllerId][dmaDescIndex].NextDescriptorAddress=(uint32*)&CAN_DMA_RX_FIFO_0_CMD_Descriptors[ControllerId][0];
           }
           else
           {
               CAN_DMA_RX_FIFO_0_CMD_Descriptors[ControllerId][dmaDescIndex].NextDescriptorAddress=(uint32*)&CAN_DMA_RX_FIFO_0_CMD_Descriptors[ControllerId][dmaDescIndex + CANSS_ONE];
           }
           CAN_DMA_RX_FIFO_0_CMD_Descriptors[ControllerId][dmaDescIndex].DestinationAddress =(uint32*)0x280;
           CAN_DMA_RX_FIFO_0_CMD_Descriptors[ControllerId][dmaDescIndex].TransferDirection = CANSS_ZERO;
           CAN_DMA_RX_FIFO_0_CMD_Descriptors[ControllerId][dmaDescIndex].TransferFragment = CANSS_ZERO;
           CAN_DMA_RX_FIFO_0_CMD_Descriptors[ControllerId][dmaDescIndex].Reserved = CANSS_ZERO;
           CAN_DMA_RX_FIFO_0_CMD_Descriptors[ControllerId][dmaDescIndex].ZeroValues = CANSS_ZERO;
           CAN_DMA_RX_FIFO_0_CMD_Descriptors[ControllerId][dmaDescIndex].Transferlength = 0x48;
       }
   }
   if(pMRamConfig->RxFIFO1Used!= FALSE)
   {
        /*for initializing Descriptor buffers for Rx FIFO 1*/
       for(dmaDescIndex =0;dmaDescIndex <RX_FIFO_1_CMD_MAX_DMA_DESC;dmaDescIndex++)
       {
           CAN_DMA_RX_FIFO_1_CMD_Descriptors[ControllerId][dmaDescIndex].TransferDataAddress =(uint32*)&Can_DMA_Rx1_Data_Buffer[ControllerId][dmaDescIndex];
           if(dmaDescIndex == (RX_FIFO_1_CMD_MAX_DMA_DESC - CANSS_ONE))
           {
               CAN_DMA_RX_FIFO_1_CMD_Descriptors[ControllerId][dmaDescIndex].NextDescriptorAddress=(uint32*)&CAN_DMA_RX_FIFO_1_CMD_Descriptors[ControllerId][0];
           }
           else
           {
               CAN_DMA_RX_FIFO_1_CMD_Descriptors[ControllerId][dmaDescIndex].NextDescriptorAddress=(uint32*)&CAN_DMA_RX_FIFO_1_CMD_Descriptors[ControllerId][dmaDescIndex+CANSS_ONE];
           }
           CAN_DMA_RX_FIFO_1_CMD_Descriptors[ControllerId][dmaDescIndex].DestinationAddress =(uint32*)0x300;
           CAN_DMA_RX_FIFO_1_CMD_Descriptors[ControllerId][dmaDescIndex].TransferDirection = CANSS_ZERO;
           CAN_DMA_RX_FIFO_1_CMD_Descriptors[ControllerId][dmaDescIndex].TransferFragment = CANSS_ZERO;
           CAN_DMA_RX_FIFO_1_CMD_Descriptors[ControllerId][dmaDescIndex].Reserved = CANSS_ZERO;
           CAN_DMA_RX_FIFO_1_CMD_Descriptors[ControllerId][dmaDescIndex].ZeroValues = CANSS_ZERO;
           CAN_DMA_RX_FIFO_1_CMD_Descriptors[ControllerId][dmaDescIndex].Transferlength = 0x48;
       }
   }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
Std_ReturnType Can_Drv_Write_DMA(uint8 ControllerId, Can_TxBufferConfigType TxBuff)
{
    Std_ReturnType retVal = E_OK;
    uint8 canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
    if(DmaTxDescAval[ControllerId] == TRUE)
    {
		Can_DMA_Tx_Data_Buffer[ControllerId][DmaTxWriteIdx[ControllerId]].Can_TxElement = TxBuff;
        if((TxBuff.T1.DLC)>CANSS_EIGHT)
        {
            CAN_DMA_TX_CMD_Descriptors[ControllerId][DmaTxWriteIdx[ControllerId]].Transferlength = 
                                   (uint32) Can_Drv_CANFDDLC[TxBuff.T1.DLC -CANSS_NINE] + CANSS_EIGHT;
        }
        else
        {
            CAN_DMA_TX_CMD_Descriptors[ControllerId][DmaTxWriteIdx[ControllerId]].Transferlength = (uint16)(CANSS_EIGHT <<CANSS_ONE);
        }
        if(DmaTxWriteIdx[ControllerId] == DmaTxReadIdx[ControllerId] && DmaSwTrigger[ControllerId] == FALSE)
        {
            DmaSwTrigger[ControllerId] = TRUE;
        }
        else
        {
            DmaPendingTxTransferCnt[ControllerId] ++;
        }
        DmaTxWriteIdx[ControllerId]++;
        DmaTxWriteIdx[ControllerId]=DmaTxWriteIdx[ControllerId]%TX_CMD_MAX_DMA_DESC;
        if(DmaTxWriteIdx[ControllerId] == DmaTxReadIdx[ControllerId])
        {
            DmaTxDescAval[ControllerId] = FALSE;
        }
        if(DmaSwTrigger[ControllerId] == TRUE)
        {
            DmaSwTrigger[ControllerId] = FALSE;
            SET_CAN_HW_FIELD_OFFS(canCtrId, CAN_DMA_TX_CHANNEL,CANSS_DMA_SW_TRIGGER_CHNLn,SW_TRIGGER,CANSS_ONE);
        }
    }
    else
    {
        retVal = (Std_ReturnType) CAN_BUSY;
    }
    return retVal;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_TxDMAComplete(uint8 ControllerId)
{
    PduIdType PduId;
    uint32 CanId;
    uint8  timeStampIndex;
    Can_TxEventFifoType* txEventElement;
#ifdef CAN_PLT_SAFERTOS_ENABLE
    Can_HwHandleType HwObjId = 0;
#endif
    clean_invalidate_cache_by_range(
                    (uint32)&Can_DMA_TxEvent_Data_Buffer[ControllerId][0],
                    (uint32)&Can_DMA_TxEvent_Data_Buffer[ControllerId][(TX_EVENT_CMD_MAX_DMA_DESC - CANSS_ONE)]);
    txEventElement=&(Can_DMA_TxEvent_Data_Buffer[ControllerId][DmaTxEventReadIdx[ControllerId]].Can_TxEventElement);
    PduId = (PduIdType) txEventElement->E1.E1A.MM;
    /* Extract the Can ID of the transmitted message */
    if(txEventElement->E0.XTD_ID.XTD == CANSS_ZERO)
    {
        /* Standard Identifier */
        CanId = ((txEventElement->E0.STD_ID.ID) & TX_EVENT_FIFO_ELEMENT_ID_MASK);
    }
    else
    {
        /* Extended Identifier */
        CanId = ((txEventElement->E0.XTD_ID.ID) & TX_EVENT_FIFO_ELEMENT_ID_MASK);
    }
    /* Compare the lower 8 bits of PDU ID and and CAN to varify and store the timestamp */
    timeStampIndex = 0;
    while(timeStampIndex < CANSS_TX_TIMESTAMP_FIFO_SIZE){
        if(txEventElement->E1.E1A.MM == ((uint8)(Can_Drv_TxTimeStamp[ControllerId][timeStampIndex].PduId & 0xFFU)) &&
                   (CanId == Can_Drv_TxTimeStamp[ControllerId][timeStampIndex].CanId)) {
                    Can_Drv_TxTimeStamp[ControllerId][timeStampIndex].TimeStamp = 
                    (uint16) txEventElement -> E1.E1A.TXTS;
                    PduId = Can_Drv_TxTimeStamp[ControllerId][timeStampIndex].PduId;
                    HwObjId = Can_Drv_TxTimeStamp[ControllerId][timeStampIndex].ObjectId;
                    break;
                        }
        timeStampIndex++;
    }
    DmaTxEventReadIdx[ControllerId]++;
    DmaTxEventReadIdx[ControllerId]=DmaTxEventReadIdx[ControllerId]%TX_EVENT_CMD_MAX_DMA_DESC;
    /*Invoke CanIf_TxConfirmation  */
#ifdef CAN_PLT_SAFERTOS_ENABLE           
		  uint16 time = (uint16) txEventElement -> E1.E1A.TXTS;
		  Can_TimeStampType timestamp = {0};
		  
		  Can_Drv_Get_CanBitTimeStamp(ControllerId, time, &timestamp);
		  	/*Invoke CanIf_TxConfirmation */
          Can_Drv_TxNotification(ControllerId, PduId, timestamp, HwObjId, TRUE);
		  
#else		
    Can_Drv_TxNotification(PduId);
#endif
    Can_Drv_Memset(txEventElement,CANSS_ZERO,CANSS_TWO);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_ProcessRxFIFODMA
                          (Can_HwType MailBox, Can_RxBufferType RxFifoCfg)
{
    uint8  canCtrId ;
    uint8  controllerId = MailBox.ControllerId;
    uint8  objectId = Can_Drv_ConfigPtr->CanTxRxObjMapPtr[MailBox.Hoh].ObjIndex;
    Can_RXbuffFifoType* rxFifoElement;
    const Can_CtrlConfigType *const pCtrlConfig =&Can_Drv_ConfigPtr->CanActiveCtrPtr[controllerId];
    canCtrId  = pCtrlConfig->CanCtrID;
    if (CAN_RxFIFO0 == RxFifoCfg )
    {
        clean_invalidate_cache_by_range(
            (uint32)&Can_DMA_Rx0_Data_Buffer[controllerId][0],
            (uint32)&Can_DMA_Rx0_Data_Buffer[controllerId][(RX_FIFO_0_CMD_MAX_DMA_DESC - CANSS_ONE)]);
            rxFifoElement=&(Can_DMA_Rx0_Data_Buffer[controllerId][DmaRxFifo0ReadIdx[controllerId]].Can_RxElement);
            DmaRxFifo0ReadIdx[controllerId]++;
            DmaRxFifo0ReadIdx[controllerId]=DmaRxFifo0ReadIdx[controllerId]%RX_FIFO_0_CMD_MAX_DMA_DESC;
    }
    else
    {
        clean_invalidate_cache_by_range(
            (uint32)&Can_DMA_Rx1_Data_Buffer[controllerId][0],
            (uint32)&Can_DMA_Rx1_Data_Buffer[controllerId][(RX_FIFO_1_CMD_MAX_DMA_DESC - CANSS_ONE)]);
            rxFifoElement=&(Can_DMA_Rx1_Data_Buffer[controllerId][DmaRxFifo1ReadIdx[controllerId]].Can_RxElement);
            DmaRxFifo1ReadIdx[controllerId]++;
            DmaRxFifo1ReadIdx[controllerId]=DmaRxFifo1ReadIdx[controllerId]%RX_FIFO_1_CMD_MAX_DMA_DESC;
    }
#ifdef CAN_PLT_SAFERTOS_ENABLE 
    Can_Drv_NotifyRxCallback(rxFifoElement,MailBox,objectId,TRUE);
#else
    Can_Drv_NotifyRxCallback(rxFifoElement,MailBox,objectId);
#endif
    Can_Drv_Memset(rxFifoElement,CANSS_ZERO,CANSS_TWO);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_DisableAllInterrupts(uint8 ControllerId)
{
    uint8 canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
#ifdef CAN_PLT_SAFERTOS_ENABLE
    CAN_Reg_Setting_Cnt[ControllerId]++;
#endif
    SET_CAN_HW_REG(canCtrId,IE,CANSS_ZERO);
#ifdef CAN_PLT_SAFERTOS_ENABLE
    CAN_Reg_Setting_Cnt[ControllerId]--;
#endif

#if (CAN_DMA_ENABLE == STD_ON)
    if(Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanDmaEnable == TRUE)
    {
        for(uint8 dmaChannel =0; dmaChannel  <NUM_OF_CAN_DMA_CHANNELS; dmaChannel ++)
        {
            SET_CAN_HW_FIELD_OFFS(canCtrId,dmaChannel,CANSS_DMA_IRQ_STTS_EN_CHNLn,DMA_TRANS_DONE_EN,CANSS_ZERO);
            SET_CAN_HW_FIELD_OFFS(canCtrId,dmaChannel,CANSS_DMA_IRQ_STTS_EN_CHNLn,DMA_AHB_ERROR_EN,CANSS_ZERO);
        }
        SET_CAN_HW_REG(canCtrId,DMUIE,CANSS_ZERO);
    }
#endif
    SET_CAN_HW_REG(canCtrId,CANSS_M_CAN_FE_IRQ_STTS_EN,CANSS_ZERO);
#if(CAN_FUSA_ENABLE == STD_ON)
    SchM_Enter_Can_Exclusive_Area_01();
    Can_ConfigReg[ControllerId].IE_RegValue = (uint32)CANSS_ZERO;
    SchM_Exit_Can_Exclusive_Area_01();
    SET_CAN_HW_REG_OFFS(canCtrId,CANSS_ZERO,CANSS_FUSA_IRQ_MASK_n,(uint32)CAN_FUSA_ALL_ERROR_MASK);
    SET_CAN_HW_REG_OFFS(canCtrId,CANSS_ZERO,CANSS_FUSA_LEVEL_IRQ_MASK_n,(uint32)CAN_FUSA_ALL_ERROR_MASK);
#endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_EnableAllInterrupts(uint8 ControllerId)
{
    uint8 canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
#if(CAN_DMA_ENABLE == STD_ON)
    uint32  dmuIntrMask;
#endif

#if(CAN_FUSA_ENABLE == STD_OFF)
    /* When bus off recovery, Disable PEA interrupt */
    if(Can_BusOffRec[ControllerId] == TRUE)
        InterruptConfigVal[ControllerId] &= ~(uint32)CANSS_IR_PEA_BMSK;
#endif

#ifdef CAN_PLT_SAFERTOS_ENABLE
    CAN_Reg_Setting_Cnt[ControllerId]++;
#endif
    SET_CAN_HW_REG(canCtrId,IE,InterruptConfigVal[ControllerId]);
#ifdef CAN_PLT_SAFERTOS_ENABLE
    CAN_Reg_Setting_Cnt[ControllerId]--;
#endif

#if(CAN_DMA_ENABLE == STD_ON)
    if(Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanDmaEnable == TRUE)
    {
        for(uint8 dmaChannel =0; dmaChannel <NUM_OF_CAN_DMA_CHANNELS; dmaChannel++)
        {
            SET_CAN_HW_FIELD_OFFS(canCtrId,dmaChannel,CANSS_DMA_IRQ_STTS_EN_CHNLn,DMA_TRANS_DONE_EN,CANSS_ONE);
            SET_CAN_HW_FIELD_OFFS(canCtrId,dmaChannel,CANSS_DMA_IRQ_STTS_EN_CHNLn,DMA_AHB_ERROR_EN,CANSS_ONE);
        }
        dmuIntrMask = CANSS_DMUIR_ERRORS_MASK;
#if(CAN_ENABLE_DEBUG_LOGGING == STD_ON)
        dmuIntrMask |= CANSS_DMUIR_DEBUG_INTRS_MASK;
#endif
        SET_CAN_HW_REG(canCtrId,DMUIE,(uint32)dmuIntrMask);
    }
#endif
    SET_CAN_HW_REG(canCtrId,CANSS_M_CAN_FE_IRQ_STTS_EN,CANSS_SEVEN);
#if(CAN_FUSA_ENABLE == STD_ON)
    SET_CAN_HW_REG_OFFS(canCtrId,CANSS_ZERO,CANSS_FUSA_IRQ_MASK_n,(uint32)CAN_FUSA_EDGE_INTERRUPTS_MASK);
    
    /* When bus off recovery, Disable PEA interrupt. Otherwise not */
    if(Can_BusOffRec[ControllerId] != TRUE)
        SET_CAN_HW_REG_OFFS(canCtrId,CANSS_ZERO,CANSS_FUSA_LEVEL_IRQ_MASK_n,(uint32)CAN_FUSA_LEVEL_INTERRUPTS_MASK );
    else
        SET_CAN_HW_REG_OFFS(canCtrId,CANSS_ZERO,CANSS_FUSA_LEVEL_IRQ_MASK_n,(uint32)((uint32)CAN_FUSA_LEVEL_INTERRUPTS_MASK | (uint32)CANSS_FUSA_IR_PEA_MSK));
    
    SchM_Enter_Can_Exclusive_Area_01();
    Can_ConfigReg[ControllerId].IE_RegValue = InterruptConfigVal[ControllerId];
    SchM_Exit_Can_Exclusive_Area_01();
#endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_Cfg_Init(const Can_ConfigType*Config)
{
    Can_Drv_ConfigPtr = Config;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"

#if(CAN_ENABLE_SECURITY_EVENT == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void CanDrv_Arb_Phase_Error_Handler(
                                              uint8 ControllerId)
{
    CanSS_ErrorType ProtocolErrorType;
    uint8 canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
    ProtocolErrorType = (CanSS_ErrorType)IN_CAN_HW_FIELD(canCtrId, PSR, LEC);
    if((ProtocolErrorType != CANSS_NO_ERROR) && (ProtocolErrorType != CANSS_NO_CHANGE))
    {
        Can_Drv_Process_ProtocolErrors(ControllerId,ProtocolErrorType);
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void CanDrv_Data_Phase_Error_Handler(
                                              uint8 ControllerId)
{
    CanSS_ErrorType ProtocolErrorType;
    uint8 canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
    ProtocolErrorType = (CanSS_ErrorType)IN_CAN_HW_FIELD(canCtrId, PSR, DLEC);
    if((ProtocolErrorType != CANSS_NO_ERROR) && (ProtocolErrorType != CANSS_NO_CHANGE))
    {
        Can_Drv_Process_ProtocolErrors(ControllerId,ProtocolErrorType);
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_Process_ProtocolErrors(
        uint8 ControllerId,
        CanSS_ErrorType ProtocolErrorType)
{
    if(ProtocolErrorType == CANSS_STUFF_ERROR)
    {
        CanIf_ErrorNotification(ControllerId,CAN_ERROR_CHECK_STUFFING_FAILED);
    }
    else if(ProtocolErrorType == CANSS_FORM_ERROR)
    {
        CanIf_ErrorNotification(ControllerId,CAN_ERROR_CHECK_FORM_FAILED);
    }
    else if(ProtocolErrorType == CANSS_ACK_ERROR)
    {
        CanIf_ErrorNotification(ControllerId,CAN_ERROR_CHECK_ACK_FAILED);
    }
    else if(ProtocolErrorType == CANSS_BIT1_ERROR)
    {
        CanIf_ErrorNotification(ControllerId,CAN_ERROR_BIT_MONITORING1);
    }
    else if(ProtocolErrorType == CANSS_BIT0_ERROR)
    {
        CanIf_ErrorNotification(ControllerId,CAN_ERROR_BIT_MONITORING0);
    }
    else if(ProtocolErrorType == CANSS_CRC_ERROR)
    {
        CanIf_ErrorNotification(ControllerId,CAN_ERROR_CHECK_CRC_FAILED);
    }
    else
    {
        /* Keeping as Empty */
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void  Can_Drv_InterruptConfig(
                                            uint8 ControllerId)
{
    const Can_CtrlConfigType* ctrlConfig;
    ctrlConfig = &Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId];
    uint8  canCtrId = ctrlConfig->CanCtrID;
    uint32 regBits = CANSS_ZERO;
    uint32  ileRegValue = 0;
    uint32  ilsRegValue = 0;
    //flag bits to check if the interrupt line needs to be enabled
    boolean line0 = FALSE;
    InterruptConfigVal[ControllerId] =0;
    const Can_MsgRamConfigType *const pMRamConfig = ctrlConfig->CanMsgRamConfig;
#ifdef CAN_PLT_SAFERTOS_ENABLE
    CAN_Reg_Setting_Cnt[canCtrId]++;
#endif
    /*read all bits in IR register and if any bits are not zero then clear those bits*/
    regBits = IN_CAN_HW_REG(canCtrId,IR);
    if(regBits != CANSS_ZERO){
        /* writing 1 clears the IR register bits */
        SET_CAN_HW_REG(canCtrId,IR,regBits);
    }
    if(CAN_INTERRUPT == ctrlConfig->CanBusoffProcessing){
#if(CAN_FUSA_ENABLE == STD_OFF)
        SET_CAN_HW_FIELD(canCtrId,ILS, BOL, CANSS_ONE);
        InterruptConfigVal[ControllerId]|= (uint32) CANSS_IR_BO_BMSK;
        ilsRegValue |= (uint32) CANSS_IR_BO_BMSK;
#endif
    }
    else{
        SET_CAN_HW_FIELD(canCtrId, IE, BOE, CANSS_ZERO);
    }
    if(ctrlConfig->CanRxProcessing != CAN_POLLING){
        if(TRUE == pMRamConfig->RxBufferUsed)
        {
            SET_CAN_HW_FIELD(canCtrId, ILS, DRXL, CANSS_ZERO);
            line0 = TRUE;
            InterruptConfigVal[ControllerId]|= (uint32)CANSS_IR_DRX_BMSK;
            ilsRegValue &=~ (uint32)(CANSS_IR_DRX_BMSK);
        }
        if(TRUE  == pMRamConfig->RxFIFO0Used )
        {
            if(ctrlConfig->CanDmaEnable == FALSE)
            {
                if((ctrlConfig->CanRxProcessing == CAN_INTERRUPT_ON_NEW_ENTRY)
                    ||(ctrlConfig->CanRxProcessing == CAN_MIXED ))
                {
                    SET_CAN_HW_FIELD(canCtrId, ILS, RF0NL, CANSS_ZERO);
                    line0 = TRUE;
                    InterruptConfigVal[ControllerId]|= (uint32)CANSS_IR_RF0N_BMSK;
                    ilsRegValue &=~ (uint32)(CANSS_IR_RF0N_BMSK);
                }
                else
                {
                    SET_CAN_HW_FIELD(canCtrId, ILS, RF0WL, CANSS_ZERO);
                    line0 = TRUE;
                    InterruptConfigVal[ControllerId]|= (uint32)CANSS_IR_RF0W_BMSK;
                    ilsRegValue &=~ (uint32)(CANSS_IR_RF0W_BMSK);
                }
            }
        }
        if(TRUE  == pMRamConfig->RxFIFO1Used )
        {
            if(ctrlConfig->CanDmaEnable == FALSE)
            {
                if((ctrlConfig->CanRxProcessing == CAN_INTERRUPT_ON_NEW_ENTRY)
                    ||(ctrlConfig->CanRxProcessing == CAN_MIXED))
                {
                    SET_CAN_HW_FIELD(canCtrId, ILS, RF1NL, CANSS_ZERO);
                    line0 = TRUE;
                    InterruptConfigVal[ControllerId]|= (uint32)CANSS_IR_RF1N_BMSK;
                    ilsRegValue &=~ (uint32)(CANSS_IR_RF1N_BMSK);
                }
                else
                {
                    SET_CAN_HW_FIELD(canCtrId, ILS, RF1WL, CANSS_ZERO);
                    line0 = TRUE;
                    InterruptConfigVal[ControllerId]|= (uint32)CANSS_IR_RF1W_BMSK;
                    ilsRegValue &=~ (uint32)(CANSS_IR_RF1W_BMSK);
                }
            }
        }
    }
    else
    {
        SET_CAN_HW_FIELD(canCtrId, IE, DRXE, CANSS_ZERO);
        SET_CAN_HW_FIELD(canCtrId, IE, RF0NE, CANSS_ZERO);
        SET_CAN_HW_FIELD(canCtrId, IE, RF0WE, CANSS_ZERO);
        SET_CAN_HW_FIELD(canCtrId, IE, RF0FE, CANSS_ZERO);
        SET_CAN_HW_FIELD(canCtrId, IE, RF1NE, CANSS_ZERO);
        SET_CAN_HW_FIELD(canCtrId, IE, RF1WE, CANSS_ZERO);
        SET_CAN_HW_FIELD(canCtrId, IE, RF1FE, CANSS_ZERO);
    }
    if ((TRUE == pMRamConfig->TxEventFIFOUsed) &&
        (ctrlConfig->CanTxProcessing!= CAN_POLLING))
    {
        if(ctrlConfig->CanDmaEnable == FALSE)
        {
            if((ctrlConfig->CanTxProcessing == CAN_INTERRUPT_ON_NEW_ENTRY)
                || (ctrlConfig->CanTxProcessing == CAN_MIXED ))
            {
                SET_CAN_HW_FIELD(canCtrId, ILS,TEFNL, CANSS_ZERO);
                line0 = TRUE;
                InterruptConfigVal[ControllerId]|= (uint32)CANSS_IR_TEFN_BMSK;
                ilsRegValue &=~ (uint32)(CANSS_IR_TEFN_BMSK);
            }
            else
            {
                SET_CAN_HW_FIELD(canCtrId, ILS, TEFWL, CANSS_ZERO);
                line0 = TRUE;
                InterruptConfigVal[ControllerId]|= (uint32)CANSS_IR_TEFW_BMSK;
                ilsRegValue &=~ (uint32)(CANSS_IR_TEFW_BMSK);
            }
        }
    }
    else
    {
        SET_CAN_HW_FIELD(canCtrId, IE, TEFNE, CANSS_ZERO);
        SET_CAN_HW_FIELD(canCtrId, IE, TEFWE, CANSS_ZERO);
        SET_CAN_HW_FIELD(canCtrId, IE, TEFFE, CANSS_ZERO);
    }
#if(CAN_ENABLE_SECURITY_EVENT == STD_ON)
#if(CAN_FUSA_ENABLE == STD_OFF)
    SET_CAN_HW_FIELD(canCtrId, ILS, EPL, CANSS_ONE);
    SET_CAN_HW_FIELD(canCtrId, ILS, PEAL, CANSS_ONE);
    SET_CAN_HW_FIELD(canCtrId, ILS, PEDL, CANSS_ONE);
    InterruptConfigVal[ControllerId]|= ((uint32)CANSS_IR_EP_BMSK) | 
	            ((uint32)CANSS_IR_PEA_BMSK) | ((uint32)CANSS_IR_PED_BMSK); 
    ilsRegValue |= ((uint32)CANSS_IR_EP_BMSK) |((uint32)CANSS_IR_PEA_BMSK) |((uint32)CANSS_IR_PED_BMSK);
#endif
#endif
    SET_CAN_HW_FIELD(canCtrId, ILS, RF0LL, CANSS_ONE);
    SET_CAN_HW_FIELD(canCtrId, ILS, RF0FL, CANSS_ZERO);
    SET_CAN_HW_FIELD(canCtrId, ILS, RF1LL, CANSS_ONE);
    SET_CAN_HW_FIELD(canCtrId, ILS, RF1FL, CANSS_ZERO);
    InterruptConfigVal[ControllerId]|= ((uint32)CANSS_IR_RF0F_BMSK) | ((uint32)CANSS_IR_RF0L_BMSK) |
                                        	((uint32)CANSS_IR_RF1F_BMSK) |((uint32)CANSS_IR_RF1L_BMSK);
    ilsRegValue |=(((uint32)CANSS_IR_RF0L_BMSK) | ((uint32)CANSS_IR_RF1L_BMSK));
    ilsRegValue &=~(((uint32)CANSS_IR_RF0F_BMSK) | ((uint32)CANSS_IR_RF1F_BMSK));
#if(CAN_GLOBAL_TIME_SUPPORT == STD_ON)
    SET_CAN_HW_FIELD(canCtrId, ILS, TSWL, CANSS_ONE);
    InterruptConfigVal[ControllerId]|= (uint32)CANSS_IR_TSW_BMSK;
    ilsRegValue|= (uint32)CANSS_IR_TSW_BMSK;
#endif
    SET_CAN_HW_FIELD(canCtrId, ILS, TEFFL, CANSS_ZERO);
    InterruptConfigVal[ControllerId]|= (uint32)CANSS_IR_TEFF_BMSK;
    ilsRegValue &=~ (uint32)(CANSS_IR_TEFF_BMSK);
#if(CAN_ENABLE_DEBUG_LOGGING == STD_ON)
#if(CAN_FUSA_ENABLE == STD_OFF)
    SET_CAN_HW_FIELD(canCtrId, ILS, ARAL, CANSS_ONE);
    SET_CAN_HW_FIELD(canCtrId, ILS, WDIL, CANSS_ONE);
    SET_CAN_HW_FIELD(canCtrId, ILS, EWL, CANSS_ONE);
    SET_CAN_HW_FIELD(canCtrId, ILS, ELOL, CANSS_ONE);
    SET_CAN_HW_FIELD(canCtrId, ILS, BEUL, CANSS_ONE);
    SET_CAN_HW_FIELD(canCtrId, ILS, MRAFL, CANSS_ONE);
    InterruptConfigVal[ControllerId]|= ((uint32)CANSS_IR_ARA_BMSK | (uint32)CANSS_IR_WDI_BMSK | (uint32)CANSS_IR_EW_BMSK
                                       | (uint32)CANSS_IR_ELO_BMSK | (uint32)CANSS_IR_BEU_BMSK | (uint32)CANSS_IR_MRAF_BMSK);
    ilsRegValue |= ((uint32)CANSS_IR_ARA_BMSK | (uint32)CANSS_IR_WDI_BMSK | (uint32)CANSS_IR_EW_BMSK
                    | (uint32)CANSS_IR_ELO_BMSK | (uint32)CANSS_IR_BEU_BMSK | (uint32)CANSS_IR_MRAF_BMSK);
#endif
    SET_CAN_HW_FIELD(canCtrId, ILS, BECL, CANSS_ONE);
    SET_CAN_HW_FIELD(canCtrId, ILS, TOOL, CANSS_ONE);
    SET_CAN_HW_FIELD(canCtrId, ILS, TFEL, CANSS_ZERO);
    SET_CAN_HW_FIELD(canCtrId, ILS, TCFL, CANSS_ZERO);
    SET_CAN_HW_FIELD(canCtrId, ILS, TCL, CANSS_ZERO);
    SET_CAN_HW_FIELD(canCtrId, ILS, TEFLL, CANSS_ONE);
    SET_CAN_HW_FIELD(canCtrId, ILS, HPML, CANSS_ZERO);
    InterruptConfigVal[ControllerId]|= ((uint32)CANSS_IR_BEC_BMSK | (uint32)CANSS_IR_TOO_BMSK | (uint32)CANSS_IR_TFE_BMSK
                                       | (uint32)CANSS_IR_TCF_BMSK |(uint32) CANSS_IR_TC_BMSK | (uint32)CANSS_IR_TEFL_BMSK | (uint32)CANSS_IR_HPM_BMSK);
    ilsRegValue |= ((uint32)CANSS_IR_BEC_BMSK | (uint32)CANSS_IR_TOO_BMSK | (uint32)CANSS_IR_TEFL_BMSK);
    ilsRegValue &= ~((uint32)CANSS_IR_TFE_BMSK | (uint32)CANSS_IR_TCF_BMSK | (uint32)CANSS_IR_TC_BMSK |(uint32)CANSS_IR_HPM_BMSK);
#endif
    if(TRUE == line0){
        SET_CAN_HW_FIELD(canCtrId, ILE, EINT0, CANSS_ONE);
        ileRegValue |= (uint32)CANSS_ONE;
    }
    SET_CAN_HW_FIELD(canCtrId, ILE, EINT1, CANSS_ONE);
    ileRegValue |= (uint32)CANSS_TWO;
#ifdef CAN_PLT_SAFERTOS_ENABLE
    CAN_Reg_Setting_Cnt[canCtrId]--;
#endif

#if(CAN_FUSA_ENABLE == STD_ON)
    Can_ConfigReg[ControllerId].ILS_RegValue = ilsRegValue; 
    Can_ConfigReg[ControllerId].ILE_RegValue = ileRegValue; 
    CanFusa_ConfigureFusaInterrupts(ControllerId);
#endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"

#if(CAN_MIXED_MODE_ENABLE == STD_ON || CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_Add_Pdu_ToPendingTxList(uint8 ControllerId, 
                                            PduIdType pduId, 
                                            const Can_TxHOHType* txObj){
    SchM_Enter_Can_Exclusive_Area_03();
    Can_Drv_PendingPduNotifications[ControllerId].
            PduInfo[(Can_Drv_PendingPduNotifications[ControllerId].PduStoreIdx)].PduId = pduId;
#if(CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
    Can_Drv_PendingPduNotifications[ControllerId].PduInfo[(Can_Drv_PendingPduNotifications[ControllerId].PduStoreIdx)].PeriodId = txObj-> TxPeriodId;
    Can_Drv_PendingPduNotifications[ControllerId].PduInfo[(Can_Drv_PendingPduNotifications[ControllerId].PduStoreIdx)].NotifiedByCallBack= FALSE;
#endif
    Can_Drv_PendingPduNotifications[ControllerId].PduStoreIdx = 
        ((Can_Drv_PendingPduNotifications[ControllerId].PduStoreIdx) + CANSS_ONE ) % 
                                          TX_PDU_LIST_MAX_ARR_SIZE;
    if(Can_Drv_PendingPduNotifications[ControllerId].PduReadIdx == 
                                Can_Drv_PendingPduNotifications[ControllerId].PduStoreIdx){
        Can_Drv_PendingPduNotifications[ControllerId].PduReadIdx = 
                ((Can_Drv_PendingPduNotifications[ControllerId].PduReadIdx) + CANSS_ONE ) % 
                    TX_PDU_LIST_MAX_ARR_SIZE;
#if(CAN_ENABLE_DEBUG_LOGGING ==STD_ON)
        Can_Tx_LostCnt[ControllerId]++;
#endif
    }
    SchM_Exit_Can_Exclusive_Area_03();
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif

#if(CAN_MIXED_MODE_ENABLE == STD_ON || CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_Delete_Pdu_FromPendingTxList(uint8 ControllerId, uint8 readIndex){
    SchM_Enter_Can_Exclusive_Area_03();
#if(CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
    while((Can_Drv_PendingPduNotifications[ControllerId].PduInfo[(Can_Drv_PendingPduNotifications[ControllerId].PduReadIdx)].NotifiedByCallBack == TRUE) && 
       (Can_Drv_PendingPduNotifications[ControllerId].PduReadIdx != Can_Drv_PendingPduNotifications[ControllerId].PduStoreIdx)){
        Can_Drv_PendingPduNotifications[ControllerId].PduReadIdx = 
                        (Can_Drv_PendingPduNotifications[ControllerId].PduReadIdx + CANSS_ONE) %
                        TX_PDU_LIST_MAX_ARR_SIZE;
    }
#else
    Can_Drv_PendingPduNotifications[ControllerId].PduReadIdx = readIndex ;
#endif
    SchM_Exit_Can_Exclusive_Area_03();
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif

#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void Can_Drv_Config_Interrupts(uint8 ControllerId, 
                                                     Can_ControllerStateType TransitionState)
{
    uint8 canCtrId = Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanCtrID;
#if(CAN_FUSA_ENABLE == STD_ON)
    uint32  fusaEdgeInterruptMask = 0;
    uint32  fusaLevelInterruptMask = 0;
#endif    
    uint32  ieRegValue = 0;
#if(CAN_DMA_ENABLE == STD_ON)
    uint32  dmuieRegValue = 0;
#endif
    SchM_Enter_Can_Exclusive_Area_00();
    if(Can_InterruptDisableCount[ControllerId] == CANSS_ZERO)
    {
        SchM_Exit_Can_Exclusive_Area_00();
        if(TransitionState == CAN_CS_STARTED)
        {
            Can_Drv_EnableAllInterrupts(ControllerId);         
         
        }
        else if(TransitionState == CAN_CS_STOPPED)
        {
            /*Enabling the interrupts required in STOPPED State*/
            ieRegValue = CANSS_IR_ARA_BMSK;
#if(CAN_DMA_ENABLE == STD_ON)
            dmuieRegValue = (uint32)CANSS_DMUIR_IAC_BMSK;
#endif
#if(CAN_FUSA_ENABLE == STD_ON)        
            fusaEdgeInterruptMask = CAN_FUSA_EDGE_INTERRUPTS_MASK | ~(CANSS_FUSA_CSR_PARITY_MSK);
            fusaLevelInterruptMask = CAN_FUSA_LEVEL_INTERRUPTS_MASK | ~(CANSS_FUSA_IR_ARA_MSK);
#endif
#ifdef CAN_PLT_SAFERTOS_ENABLE
            CAN_Reg_Setting_Cnt[ControllerId]++;
#endif
            SET_CAN_HW_REG(canCtrId,IE,ieRegValue);
#ifdef CAN_PLT_SAFERTOS_ENABLE
            CAN_Reg_Setting_Cnt[ControllerId]--;
#endif

#if(CAN_DMA_ENABLE == STD_ON)
            if(Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanDmaEnable == TRUE)
            {
                for(uint8 dmaChannel =0; dmaChannel <NUM_OF_CAN_DMA_CHANNELS; dmaChannel++)
                {
                    SET_CAN_HW_FIELD_OFFS(canCtrId,dmaChannel,CANSS_DMA_IRQ_STTS_EN_CHNLn,DMA_TRANS_DONE_EN,(uint32)CANSS_ZERO);
                    SET_CAN_HW_FIELD_OFFS(canCtrId,dmaChannel,CANSS_DMA_IRQ_STTS_EN_CHNLn,DMA_AHB_ERROR_EN,(uint32)CANSS_ZERO);
                }
                SET_CAN_HW_REG(canCtrId,DMUIE,(uint32)dmuieRegValue);
            }
#endif        
        SET_CAN_HW_REG(canCtrId,CANSS_M_CAN_FE_IRQ_STTS_EN,(uint32)CANSS_ZERO);
#if(CAN_FUSA_ENABLE == STD_ON)
        SET_CAN_HW_REG_OFFS(canCtrId,CANSS_ZERO,CANSS_FUSA_IRQ_MASK_n,(uint32)fusaEdgeInterruptMask);
        SET_CAN_HW_REG_OFFS(canCtrId,CANSS_ZERO,CANSS_FUSA_LEVEL_IRQ_MASK_n,(uint32)fusaLevelInterruptMask);
        SchM_Enter_Can_Exclusive_Area_01();
        Can_ConfigReg[ControllerId].IE_RegValue = ieRegValue;//Storing latest IE values
        SchM_Exit_Can_Exclusive_Area_01();
#endif
        }
        else if(TransitionState == CAN_CS_UNINIT)
        {
            Can_Drv_DisableAllInterrupts(ControllerId);
        }
        else
        {
            // Do Nothing 
        }
    }
    else{
        SchM_Exit_Can_Exclusive_Area_00();
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_ProcessRxBufferIsr
                              (uint8 ControllerId)
{
    uint8 BufferIndex = 0;
    uint8 rxElementSize;
    uint8 objectId;
    uint64 ndatRegval;
    uint64 bufferMask;
    Can_HwType mailBox = {.ControllerId = ControllerId, .Hoh = 0};
    const Can_CtrlConfigType *const ctrlConfig =&Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId];
    Can_RXbuffFifoType* rxBufferElement;
    const Can_MsgRamConfigType *const pMRamConfig = ctrlConfig->CanMsgRamConfig ;
    /* load the buffer status */
    ndatRegval = (uint64)IN_CAN_HW_FIELD(ctrlConfig->CanCtrID,NDAT1, ND);
    ndatRegval |= ((uint64)IN_CAN_HW_FIELD(ctrlConfig->CanCtrID, NDAT2, ND) << ONE_INT_SIZE);
    while((ndatRegval != 0UL) && (BufferIndex < CANSS_UINT64_LEN))
    {
        bufferMask = ((uint64)CANSS_ONE) << BufferIndex;
        /* Check if the corresponding buffer received new data */
        if((ndatRegval & (bufferMask)) != CANSS_ZERO)
        {
            mailBox.Hoh = Can_Drv_GetRxObjectIndex(BufferIndex,ControllerId);
            objectId = Can_Drv_ConfigPtr->CanTxRxObjMapPtr[mailBox.Hoh].ObjIndex;
#if(CAN_MIXED_MODE_ENABLE == STD_ON)
            if((Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanRxProcessing == CAN_MIXED) &&
                        (Can_Drv_ConfigPtr->CanRxHwObjPtr[objectId].ObjectPollingEnabled == TRUE))
            {
                ndatRegval &= ~(bufferMask);
                BufferIndex++;
                continue;
            }
            else
#endif
            {
                rxElementSize = Can_Drv_GetRxElementSize(pMRamConfig->RxMaxBufferDlc);
                /*Initialize the Message Ram Segment for the corresponding Rx Buffer Element */
                rxBufferElement = (Can_RXbuffFifoType*) IN_CAN_MRAM_BASE(ctrlConfig->CanCtrID,
                                ((uint32)pMRamConfig->RxBufferStartAdd + ((uint32)rxElementSize * BufferIndex)));  
#ifdef CAN_PLT_SAFERTOS_ENABLE              
                Can_Drv_NotifyRxCallback(rxBufferElement,mailBox,objectId,TRUE);
#else
				Can_Drv_NotifyRxCallback(rxBufferElement,mailBox,objectId);
#endif
                /* Provide Acknowlegement for the received data */
                Can_Drv_AcknowledgeRx(ctrlConfig->CanCtrID, CAN_RxDedicatedBuffer, BufferIndex);            
                /*Acknowledge the received data */
                ndatRegval &= ~(bufferMask);
            }
        }
        BufferIndex++;
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_NotifyRxCallback(Can_RXbuffFifoType* RxBufferElement,Can_HwType MailBox ,uint8 ObjectId
#ifdef CAN_PLT_SAFERTOS_ENABLE
                                             , bool isIsr
#endif
                                              )
{
    uint8 dlcValue;
    uint32 canId;
    PduInfoType pduInfo;
    uint8 rxBuffer[CAN_MAX_BUFF_DLC];
    volatile Can_RXbuffFifoType* rxBufferElement = RxBufferElement;
    dlcValue = (uint8) rxBufferElement->R1.R1A.DLC;
    if(dlcValue > CANSS_MAX_NONFD_DLC)
    {
        pduInfo.SduLength = Can_Drv_CANFDDLC[dlcValue -CANSS_NINE];
    }
    else
    {
        pduInfo.SduLength = dlcValue;
    }
    if (RxBufferElement->R0.XTD_ID.XTD == CANSS_ZERO)
    {
        /* Standard Identifier */
        canId = (rxBufferElement->R0.STD_ID.ID & RX_ELEMENT_ID_MASK);
        MailBox.CanId = (canId |((uint32)(rxBufferElement->R1.R1A.FDF)<<CAN_FRAME_TYPE_SHIFT));
    }
    else
    {
        /* Extended Identifier */
        canId = (rxBufferElement->R0.XTD_ID.ID & RX_ELEMENT_ID_MASK);
        MailBox.CanId = (canId | ((uint32)CAN_EXTENDED_ID<<CAN_ID_TYPE_SHIFT)
                                    | (((uint32)rxBufferElement->R1.R1A.FDF)<<CAN_FRAME_TYPE_SHIFT));
    }
    if (pduInfo.SduLength > CANSS_ZERO)
    {
        pduInfo.SduDataPtr = rxBuffer;
    }
    else
    {
        pduInfo.SduDataPtr = NULL_PTR;
    }
    /* Store data */
    for(uint8 idx = 0U; idx < pduInfo.SduLength; idx++)
    {
        rxBuffer[idx] =rxBufferElement->RxData[idx];
    }
    pduInfo.MetaDataPtr = (uint8*)&canId;
    Can_Drv_RxTimeStamp[ObjectId] = (uint16) rxBufferElement->R1.R1A.RXTS;
#if(CAN_LPDU_CALLOUT_ENABLE == STD_ON)
    if(CAN_LPDU_CALLOUT_FUNCTION(MailBox.Hoh,canId,(uint8)pduInfo.SduLength,pduInfo.SduDataPtr) == TRUE)
#endif
    {
#ifdef CAN_PLT_SAFERTOS_ENABLE
		uint16 time = (uint16) rxBufferElement->R1.R1A.RXTS;
		Can_TimeStampType timestamp = {0};
		
		Can_Drv_Get_CanBitTimeStamp(MailBox.ControllerId, time, &timestamp);
		Can_Drv_RxNotification(MailBox,pduInfo, timestamp, isIsr);
#else		
        /*Invoke CanIf_RxIndication */
        Can_Drv_RxNotification(MailBox,pduInfo);
#endif		
    }
            
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline uint8 Can_Drv_GetRxElementSize(uint8 Dlc){
    uint8 rxElementSize;
    if(Dlc > (uint8)CANSS_ZERO){
         /*element size = 8 bytes of header + DLC */
        rxElementSize = ((CANSS_EIGHT +Can_Drv_CANFDDLC[Dlc -(uint8)CANSS_ONE])
            >> CANSS_TWO);
    }
    else{
        /*element size = 8 bytes of DLC and 8 bytes of header is 4 words*/
        rxElementSize = CANSS_FOUR;
    }
    return rxElementSize;
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_AcknowledgeRx(uint8 CanCtrID, Can_RxBufferType RxFifoCfg, uint8 RxIndex){
    if ( CAN_RxFIFO0 == RxFifoCfg ) {
        /* Updating index in FIFO0 */
        SET_CAN_HW_FIELD(CanCtrID, RXF0A, F0AI, RxIndex);
    }
    else if (CAN_RxFIFO1 == RxFifoCfg){
        /* Updating index in FIFO1 */
        SET_CAN_HW_FIELD(CanCtrID, RXF1A, F1AI, RxIndex);
    }
    else{
        if (RxIndex < ONE_INT_SIZE )
        {
            SET_CAN_HW_FIELD(CanCtrID, NDAT1, ND, ((uint32)CANSS_ONE<<RxIndex));
        }
        else if ((RxIndex - ONE_INT_SIZE) < ONE_INT_SIZE )
        {
            SET_CAN_HW_FIELD(CanCtrID, NDAT2, ND, (((uint32)CANSS_ONE)<<(RxIndex - ONE_INT_SIZE)));
        }
        else{
            /*Do nothing*/
        }
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
static inline void Can_Drv_ProcessRxFIFOIsr
                              (uint8 ControllerId,
                              Can_RxBufferType RxFIFOType)
{
    Can_HwHandleType hoh = 0;
    Can_HwHandleType rxObjectId  = 0;
    Can_HwType mailBox = {.ControllerId = ControllerId, .Hoh = 0};
    for(uint8 index=0;index<Can_Drv_ConfigPtr->CanNumOfRxHwObj;index++)
    {
        if((Can_Drv_ConfigPtr->CanRxHwObjPtr[index].HwRxObjectCtrlrId == ControllerId) &&
                (Can_Drv_ConfigPtr->CanRxHwObjPtr[index].RxMsgBufType == RxFIFOType))
        {
            hoh= Can_Drv_ConfigPtr->CanRxHwObjPtr[index].HwRxObjectId;
            rxObjectId  = index;
            break;
        }
    }
    mailBox.Hoh = hoh;
#if (CAN_DMA_ENABLE == STD_ON)
    if(Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanDmaEnable==TRUE)
    {
        Can_Drv_ProcessRxFIFODMA(mailBox,RxFIFOType);
    }
    else
#endif
    {
#if(CAN_MIXED_MODE_ENABLE == STD_ON)
        if((Can_Drv_ConfigPtr->CanActiveCtrPtr[ControllerId].CanRxProcessing == CAN_MIXED) &&
                        (Can_Drv_ConfigPtr->CanRxHwObjPtr[rxObjectId ].ObjectPollingEnabled == TRUE))
        {
            return;
        }
        else
#endif
        {
#ifdef CAN_PLT_SAFERTOS_ENABLE
            Can_Drv_ProcessRxFIFO(mailBox, RxFIFOType, TRUE);
#else
            Can_Drv_ProcessRxFIFO(mailBox, RxFIFOType);
#endif
        }
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#if (CAN_DMA_ENABLE == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void CANSS_COMMON_DMU_HANDLER(uint8 CanCtrID)
{
    uint8 controllerId = Can_Drv_ExtractConfigIndex(CanCtrID);
#if(CAN_FUSA_ENABLE == STD_ON)
    if(CanFusa_Cntrl_In_SafeState(controllerId) != TRUE)
#endif
    {
        uint32 interruptStatus=0;
        interruptStatus=IN_CAN_HW_REG(CanCtrID,DMUIR);
        /* Acknowledge Interrupt */
        SET_CAN_HW_REG(CanCtrID,DMUIR,interruptStatus);
        /*Checking whether interrupt occured due to TX Not Start Address*/
        if((interruptStatus & (uint32)CANSS_DMUIR_TXENSA_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_TXENSA_InterruptCnt[controllerId]++;
        }
        /*Checking whether interrupt occured due to Illegal Enqueueing of TX Element */
        if((interruptStatus & (uint32)CANSS_DMUIR_TXEIE_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_TXEIE_InterruptCnt[controllerId]++;
        }
        /*Checking whether interrupt occured due to TX Element Illegal Access Sequence */
        if((interruptStatus & (uint32)CANSS_DMUIR_TXEIAS_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_TXEIAS_InterruptCnt[controllerId]++;
        }
        /*Checking whether interrupt occured due to TX Element Illegal DLC */
        if((interruptStatus & (uint32)CANSS_DMUIR_TXEIDLC_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_TXEIDLC_InterruptCnt[controllerId]++;
        }
        /*Checking whether interrupt occured due to TX Element Write After Trigger Address */
        if((interruptStatus & (uint32)CANSS_DMUIR_TXEWATA_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_TXEWATA_InterruptCnt[controllerId]++;
        }
        /*Checking whether interrupt occured due to TX Element Illegal Read */
        if((interruptStatus & (uint32)CANSS_DMUIR_TXEIR_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_TXEIR_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to RX0 Element Not Start Address */
        if((interruptStatus & (uint32)CANSS_DMUIR_RX0ENSA_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_RX0ENSA_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to RX0 Element Illegal Dequeueing */
        if((interruptStatus & (uint32)CANSS_DMUIR_RX0EID_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_RX0EID_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to RX0 Element Illegal Access Sequence */
        if((interruptStatus & (uint32)CANSS_DMUIR_RX0EIAS_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_RX0EIAS_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to RX0 Element Illegal Write */
        if((interruptStatus & (uint32)CANSS_DMUIR_RX0EIW_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_RX0E1W_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to RX0 Element Illegal Overwrite by timestamp */
        if((interruptStatus & (uint32)CANSS_DMUIR_RX0EIO_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_RX0EIO_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to Corrected bit error */
        if((interruptStatus & (uint32)CANSS_DMUIR_BEC_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_BEC_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to Uncorrected bit error */
        if((interruptStatus & (uint32)CANSS_DMUIR_BEU_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_BEU_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to RX1 Element Not Start Address */
        if((interruptStatus & (uint32)CANSS_DMUIR_RX1ENSA_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_RX1ENSA_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to RX1 Element Illegal Dequeueing */
        if((interruptStatus & (uint32)CANSS_DMUIR_RX1EID_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_RX1EID_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to RX1 Element Illegal Access Sequence */
        if((interruptStatus & (uint32)CANSS_DMUIR_RX1EIAS_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_RX1EIAS_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to RX1 Element Illegal Write */
        if((interruptStatus & (uint32)CANSS_DMUIR_RX1EIW_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_RX1E1W_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to RX1 Element Illegal Overwrite by timestamp */
        if((interruptStatus & (uint32)CANSS_DMUIR_RX1EIO_BMSK ) !=CANSS_ZERO)
        {
            Can_DMA_RX1EIO_InterruptCnt[controllerId]++;
        }
        /*Checking whether interrupt occured due to TX Event Not Start Address */
        if((interruptStatus & (uint32)CANSS_DMUIR_TXEENSA_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_TXEENSA_InterruptCnt[controllerId]++;
        }
        /*Checking whether interrupt occured due to TX Event Element Illegal Dequeueing */
        if((interruptStatus & (uint32)CANSS_DMUIR_TXEEID_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_TXEEID_InterruptCnt[controllerId]++;
        }
        /*Checking whether interrupt occured due to TX Event Element Illegal Access Sequence */
        if((interruptStatus & (uint32)CANSS_DMUIR_TXEEIAS_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_TXEEIAS_InterruptCnt[controllerId]++;
        }
        /*Checking whether interrupt occured due to TX Event Element Illegal Write */
        if((interruptStatus & (uint32)CANSS_DMUIR_TXEEIW_BMSK) !=CANSS_ZERO)
        {
           Can_DMA_TXEEIW_InterruptCnt[controllerId]++;
        }
        /*Checking whether interrupt occured due to Debug Trigger */
        if((interruptStatus & (uint32)CANSS_DMUIR_DT_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_DT_InterruptCnt[controllerId]++;
        }
        /*Checking whether interrupt occured due to Illegal Access while in Configuration mode */
        if((interruptStatus & (uint32)CANSS_DMUIR_IAC_BMSK ) !=CANSS_ZERO)
        {
            Can_DMA_IAC_InterruptCnt[controllerId]++;
        }
#if(CAN_ENABLE_DEBUG_LOGGING ==STD_ON)
        /*Checking whether interrupt occured due to TX Element Enqueued */
        if((interruptStatus & (uint32)CANSS_DMUIR_TXEE_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_TXEE_InterruptCnt[controllerId]++;
        }
        /*Checking whether interrupt occured due to TX Event Element Dequeued */
        if((interruptStatus & (uint32)CANSS_DMUIR_TXEED_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_TXEED_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to RX1 Element Dequeued */
        if((interruptStatus & (uint32)CANSS_DMUIR_RX1ED_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_RX1ED_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to RX0 Element Dequeued */
        if((interruptStatus & (uint32)CANSS_DMUIR_RX0ED_BMSK) !=CANSS_ZERO)
        {
            Can_DMA_RX0ED_InterruptCnt[controllerId]++;
        }
#endif
    }        

}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void CANSS_COMMON_DMA_HANDLER(uint8 CanCtrID)
{
    uint8 controllerId = Can_Drv_ExtractConfigIndex(CanCtrID);
#if(CAN_FUSA_ENABLE == STD_ON)
    if(CanFusa_Cntrl_In_SafeState(controllerId) != TRUE)
#endif
    {
        uint32 interruptStatus=0;
        for(uint8 dmaChannel =0; dmaChannel <NUM_OF_CAN_DMA_CHANNELS; dmaChannel++)
        {
            interruptStatus = IN_CAN_HW_REG_OFFS(CanCtrID, dmaChannel, CANSS_DMA_IRQ_STTS_CHNLn);
            interruptStatus &= IN_CAN_HW_REG_OFFS(CanCtrID, dmaChannel, CANSS_DMA_IRQ_STTS_EN_CHNLn);  // Mask Disabled Interrupts
            if(interruptStatus == CANSS_ZERO)
            {
                continue;
            }
            SET_CAN_HW_REG_OFFS(CanCtrID, dmaChannel, CANSS_DMA_IRQ_STTS_CLR_CHNLn, interruptStatus);  // Acknowledge Interrupt At Source
            switch(dmaChannel)
            {
                case CAN_DMA_TXE_CHANNEL:
                    if((interruptStatus &CANSS_DMA_TRANS_DONE_BMSK)!= CANSS_ZERO)
                    {
#if(CAN_ENABLE_DEBUG_LOGGING ==STD_ON)
                        Can_DMA_TransferDoneCnt[controllerId][CAN_DMA_TXE_CHANNEL]++;
#endif
                        Can_Drv_TxDMAComplete(controllerId);  
                    }
                    else if((interruptStatus &CANSS_DMA_AHB_ERROR_BMSK)!= CANSS_ZERO)
                    {
                        Can_DMA_AhbErrorCnt[controllerId][CAN_DMA_TXE_CHANNEL]++;
                    }
                    else
                    {
                        /* Do nothing */
                    }
                    break;
                case CAN_DMA_RX0_CHANNEL:
                    if((interruptStatus &CANSS_DMA_TRANS_DONE_BMSK)!= CANSS_ZERO)
                    {
#if(CAN_ENABLE_DEBUG_LOGGING ==STD_ON)
                        Can_DMA_TransferDoneCnt[controllerId][CAN_DMA_RX0_CHANNEL]++;
#endif
                        Can_Drv_ProcessRxFIFOIsr(controllerId,CAN_RxFIFO0);
                    }
                    else if((interruptStatus &CANSS_DMA_AHB_ERROR_BMSK)!= CANSS_ZERO)
                    {
                        Can_DMA_AhbErrorCnt[controllerId][CAN_DMA_RX0_CHANNEL]++;
                    }
                    else
                    {
                        /* Do nothing */
                    }
                    break;
                
                case CAN_DMA_RX1_CHANNEL:
                    if((interruptStatus &CANSS_DMA_TRANS_DONE_BMSK) != CANSS_ZERO)
                    {
#if(CAN_ENABLE_DEBUG_LOGGING ==STD_ON)
                        Can_DMA_TransferDoneCnt[controllerId][CAN_DMA_RX1_CHANNEL]++;
#endif
                        Can_Drv_ProcessRxFIFOIsr(controllerId,CAN_RxFIFO1);
                    }
                    else if((interruptStatus &CANSS_DMA_AHB_ERROR_BMSK) != CANSS_ZERO)
                    {
                        Can_DMA_AhbErrorCnt[controllerId][CAN_DMA_RX1_CHANNEL]++;
                    }
                    else
                    {
                        /* Do nothing */
                    }
                    break;
                
                case CAN_DMA_TX_CHANNEL:
                    if((interruptStatus &CANSS_DMA_TRANS_DONE_BMSK)!= CANSS_ZERO)
                    {
#if(CAN_ENABLE_DEBUG_LOGGING ==STD_ON)
                        Can_DMA_TransferDoneCnt[controllerId][CAN_DMA_TX_CHANNEL]++;
#endif
                        DmaTxReadIdx[controllerId]++;
                        DmaTxReadIdx[controllerId]=DmaTxReadIdx[controllerId]%TX_CMD_MAX_DMA_DESC;
                        DmaTxDescAval[controllerId] = TRUE;
                        if(DmaPendingTxTransferCnt[controllerId]!=CANSS_ZERO)
                        {
                            SET_CAN_HW_FIELD_OFFS(CanCtrID, CAN_DMA_TX_CHANNEL,CANSS_DMA_SW_TRIGGER_CHNLn,SW_TRIGGER,CANSS_ONE);
                            DmaPendingTxTransferCnt[controllerId] --;
                        }
                    }
                    else if((interruptStatus &CANSS_DMA_AHB_ERROR_BMSK) != CANSS_ZERO)
                    {
                        Can_DMA_AhbErrorCnt[controllerId][CAN_DMA_TX_CHANNEL]++;
                    }
                    else
                    {
                        /* Do nothing */
                    }
                    break;    
                
                default:
                    /*Do Nothing*/
                    break;                    
            
            }
        }
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void CANSS_INT0_COMMON_HANDLER(uint8 CanCtrID)
{
    uint8 controllerId =Can_Drv_ExtractConfigIndex(CanCtrID);
#if(CAN_FUSA_ENABLE == STD_ON)
    if(CanFusa_Cntrl_In_SafeState(controllerId) != TRUE)
#endif
    {
        uint32 interruptStatus=0;
        interruptStatus= IN_CAN_HW_REG(CanCtrID,IR);
        /* Masking the Interrupts configured for line 0 */
        interruptStatus &= ~(IN_CAN_HW_REG(CanCtrID,ILS)); 
        /* Masking the enabled Interrupts  */
        interruptStatus &= (IN_CAN_HW_REG(CanCtrID,IE));     
        /* Acknowledge Interrupt */
        SET_CAN_HW_REG(CanCtrID,IR,interruptStatus);
        const Can_CtrlConfigType *const ctrlConfig =&Can_Drv_ConfigPtr->CanActiveCtrPtr[controllerId];
        /* Checking whether interrupt occured due to new entry in Rx FIFO0*/    
        if((interruptStatus & (uint32)CANSS_IR_RF0N_BMSK) !=CANSS_ZERO)
        {
#if(CAN_ENABLE_DEBUG_LOGGING ==STD_ON)
            Can_RF0N_InterruptCnt[controllerId]++;
#endif
            Can_Drv_ProcessRxFIFOIsr(controllerId,CAN_RxFIFO0);
        }
        /* Checking whether interrupt occured due to water mark level reached in Rx FIFO0*/    
        if((interruptStatus & (uint32)CANSS_IR_RF0W_BMSK) !=CANSS_ZERO)
        {
#if(CAN_ENABLE_DEBUG_LOGGING ==STD_ON)
            Can_RF0W_InterruptCnt[controllerId]++;
#endif
            Can_Drv_ProcessRxFIFOIsr(controllerId,CAN_RxFIFO0);
        }
        /* Checking whether interrupt occured due to  Rx FIFO0 Full*/    
        if((interruptStatus & (uint32)CANSS_IR_RF0F_BMSK) !=CANSS_ZERO)
        {
#if(CAN_ENABLE_DEBUG_LOGGING ==STD_ON)
            Can_RF0F_InterruptCnt[controllerId]++;
#endif
            if((ctrlConfig->CanRxProcessing!= CAN_POLLING)&& (ctrlConfig->CanDmaEnable == FALSE))
            {
                Can_Drv_ProcessRxFIFOIsr(controllerId,CAN_RxFIFO0);
            }
        }
        /*Checking whether interrupt occured due to new entry in Rx FIFO1*/    
        if((interruptStatus & (uint32)CANSS_IR_RF1N_BMSK)!=CANSS_ZERO)
        {
#if(CAN_ENABLE_DEBUG_LOGGING ==STD_ON)
            Can_RF1N_InterruptCnt[controllerId]++;
#endif
            Can_Drv_ProcessRxFIFOIsr(controllerId,CAN_RxFIFO1);
        }
        /* Checking whether interrupt occured due to water mark level reached in Rx FIFO1*/    
        if((interruptStatus & (uint32)CANSS_IR_RF1W_BMSK) !=CANSS_ZERO)
        {
#if(CAN_ENABLE_DEBUG_LOGGING ==STD_ON)
            Can_RF1W_InterruptCnt[controllerId]++;
#endif
            Can_Drv_ProcessRxFIFOIsr(controllerId,CAN_RxFIFO1);
        }
        /* Checking whether interrupt occured due to  Rx FIFO1 Full*/    
        if((interruptStatus & (uint32)CANSS_IR_RF1F_BMSK) !=CANSS_ZERO)
        {
#if(CAN_ENABLE_DEBUG_LOGGING ==STD_ON)
            Can_RF1F_InterruptCnt[controllerId]++;
#endif
            if((ctrlConfig->CanRxProcessing!= CAN_POLLING)&& (ctrlConfig->CanDmaEnable == FALSE))
            {
                Can_Drv_ProcessRxFIFOIsr(controllerId,CAN_RxFIFO1);
            }
        }
        /* Checking whether interrupt occured due to new entry in Tx Event FIFO*/    
        if((interruptStatus & (uint32)CANSS_IR_TEFN_BMSK) !=CANSS_ZERO)
        {
#if(CAN_ENABLE_DEBUG_LOGGING ==STD_ON)
            Can_REFN_InterruptCnt[controllerId]++;
#endif
            Can_Drv_TxComplete(controllerId
#if(CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
            ,CAN_PERIODID_IGNORE
#endif
#ifdef CAN_PLT_SAFERTOS_ENABLE
            ,TRUE
#endif
            );                                
        }
        /* Checking whether interrupt occured due to water mark level reached in Tx Event FIFO*/    
        if((interruptStatus & (uint32)CANSS_IR_TEFW_BMSK) !=CANSS_ZERO)
        {

            Can_Drv_TxComplete(controllerId
#if(CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
            ,CAN_PERIODID_IGNORE
#endif
#ifdef CAN_PLT_SAFERTOS_ENABLE
            ,TRUE
#endif
            );
#if(CAN_ENABLE_DEBUG_LOGGING ==STD_ON)
            Can_TEFW_InterruptCnt[controllerId]++;
#endif
        }
        /* Checking whether interrupt occured due to  Tx Event FIFO full*/    
        if((interruptStatus & (uint32)CANSS_IR_TEFF_BMSK) !=CANSS_ZERO)
        {
#if(CAN_ENABLE_DEBUG_LOGGING ==STD_ON)
            Can_TEFF_InterruptCnt[controllerId]++;
#endif
            if((ctrlConfig->CanTxProcessing!= CAN_POLLING)&& (ctrlConfig->CanDmaEnable == FALSE))
            {
                Can_Drv_TxComplete(controllerId
#if(CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
                ,CAN_PERIODID_IGNORE
#endif
#ifdef CAN_PLT_SAFERTOS_ENABLE
                ,TRUE
#endif
            );                                                                          
            }
        }
        /* Checking whether interrupt occured due to new message received in Rx Buffer*/    
        if((interruptStatus & (uint32)CANSS_IR_DRX_BMSK)!=CANSS_ZERO)
        {
            Can_Drv_ProcessRxBufferIsr(controllerId);
        }
#if(CAN_ENABLE_DEBUG_LOGGING ==STD_ON)
        /* Checking whether interrupt occured due to Tx FIFO Empty*/
        if((interruptStatus & (uint32)CANSS_IR_TFE_BMSK) != CANSS_ZERO)
        {
            Can_TFE_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to Transmission Cancellation Finished */
        if((interruptStatus & (uint32)CANSS_IR_TCF_BMSK) != CANSS_ZERO)
        {
            Can_TCF_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to Transmission Completed*/
        if((interruptStatus & (uint32)CANSS_IR_TC_BMSK) != CANSS_ZERO)
        {
            Can_TC_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to High Priority Message*/
        if((interruptStatus & (uint32)CANSS_IR_HPM_BMSK) != CANSS_ZERO)
        {
            Can_HPM_InterruptCnt[controllerId]++;
        }
#endif
    }        
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void CANSS_INT1_COMMON_HANDLER(uint8 CanCtrID)
{
    uint8 controllerId = Can_Drv_ExtractConfigIndex(CanCtrID);
    uint32 interruptStatus=0;
#if(CAN_FUSA_ENABLE == STD_ON)
    if(CanFusa_Cntrl_In_SafeState(controllerId) != TRUE)
#endif
    {
        interruptStatus= IN_CAN_HW_REG(CanCtrID,IR); 
        /* Masking the Interrupts configured for line 1 */
        interruptStatus &= (IN_CAN_HW_REG(CanCtrID,ILS));
        /* Masking the enabled Interrupts  */
        interruptStatus &= (IN_CAN_HW_REG(CanCtrID,IE));     
        /* Acknowledge Interrupt */
        SET_CAN_HW_REG(CanCtrID,IR,interruptStatus);
#if(CAN_ENABLE_SECURITY_EVENT == STD_ON)
        /* Checking whether interrupt occured due to Error Passive State */
        if((interruptStatus & (uint32)CANSS_IR_EP_BMSK) != CANSS_ZERO)
        {
            Can_Drv_ProcessErrPassiveState(controllerId);
        
        }
        /*Checking whether interrupt occured due to Protocol error in arbitration phase */
        if((interruptStatus & (uint32)CANSS_IR_PEA_BMSK) != CANSS_ZERO)
        {
            CanDrv_Arb_Phase_Error_Handler(controllerId);    
        }
        /* Checking whether interrupt occured due to Protocol error in data phase */
        if((interruptStatus & (uint32)CANSS_IR_PED_BMSK) != CANSS_ZERO)
        {
            CanDrv_Data_Phase_Error_Handler(controllerId);
        }
#endif
        /* Checking whether interrupt occured due to Busoff State */
        if((interruptStatus & (uint32)CANSS_IR_BO_BMSK)!= CANSS_ZERO)
        {
            Can_Drv_ProcessBusoff(controllerId);
        }
        /* Checking whether interrupt occured due to Rx FIFO0 Data lost */
        if((interruptStatus & (uint32)CANSS_IR_RF0L_BMSK) != CANSS_ZERO)
        {
#if(CAN_ENABLE_DEBUG_LOGGING == STD_ON)
            Can_RF0L_InterruptCnt[controllerId]++;
#endif
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportRuntimeError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_ISR , CAN_E_DATALOST);
#endif
        }
        /* Checking whether interrupt occured due to Rx FIFO1 Data lost */
        if((interruptStatus & (uint32)CANSS_IR_RF1L_BMSK) != CANSS_ZERO)
        {
#if(CAN_ENABLE_DEBUG_LOGGING == STD_ON)
            Can_RF1L_InterruptCnt[controllerId]++;
#endif
#if (CAN_DEV_ERROR_DETECT == STD_ON)

            (void)Det_ReportRuntimeError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SID_ISR , CAN_E_DATALOST);
#endif
        }
#if(CAN_GLOBAL_TIME_SUPPORT == STD_ON)
        /* Checking whether interrupt occured due to Timestamp Wraparound */
        if((interruptStatus & (uint32)CANSS_IR_TSW_BMSK) != CANSS_ZERO)
        {
            Can_Drv_TSWrapCounter[controllerId]++;
        }
#endif
#if(CAN_ENABLE_DEBUG_LOGGING ==STD_ON)
        /* Checking whether interrupt occured due to 2 Bit Uncorrectable Error */
        if((interruptStatus & (uint32)CANSS_IR_BEU_BMSK) != CANSS_ZERO)
        {
            Can_BEU_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to 1 Bit Correctable Error */
        if((interruptStatus & (uint32)CANSS_IR_BEC_BMSK) != CANSS_ZERO)
        {
            Can_BEC_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to Access to Reserved Address */
        if((interruptStatus & (uint32)CANSS_IR_ARA_BMSK) != CANSS_ZERO)
        {
            Can_ARA_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to Watchdog Timeout */
        if((interruptStatus & (uint32)CANSS_IR_WDI_BMSK) != CANSS_ZERO)
        {
            Can_WD_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to Warning Status */
        if((interruptStatus & (uint32)CANSS_IR_EW_BMSK) != CANSS_ZERO)
        {
            Can_EW_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to Error Logging Overflow */
        if((interruptStatus & (uint32)CANSS_IR_ELO_BMSK) != CANSS_ZERO)
        {
            Can_ELO_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to Timeout */
        if((interruptStatus & (uint32)CANSS_IR_TOO_BMSK) != CANSS_ZERO)
        {
            Can_TO_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to Message RAM Access Failure */
        if((interruptStatus & (uint32)CANSS_IR_MRAF_BMSK) != CANSS_ZERO)
        {
            Can_MRAF_InterruptCnt[controllerId]++;
        }
        /* Checking whether interrupt occured due to Tx Event FIFO Element Lost */
        if((interruptStatus & (uint32)CANSS_IR_TEFL_BMSK) != CANSS_ZERO)
        {
            Can_TEFL_InterruptCnt[controllerId]++;
        }
#endif
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void CANSS_FE0_COMMON_HANDLER(uint8 CanCtrID)
{
#if(CAN_FUSA_ENABLE == STD_ON)
    uint8 controllerId = Can_Drv_ExtractConfigIndex(CanCtrID);;
    if(CanFusa_Cntrl_In_SafeState(controllerId) != TRUE)
#endif
    {
        SET_CAN_HW_REG(CanCtrID,CANSS_M_CAN_FE_IRQ_STTS_CLR, CANSS_ONE);
#if(CAN_ENABLE_DEBUG_LOGGING == STD_ON)
        //Can_FE0_InterruptCnt[controllerId]++;
#endif
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void CANSS_FE1_COMMON_HANDLER(uint8 CanCtrID)
{
 #if(CAN_FUSA_ENABLE == STD_ON)
     uint8 controllerId = Can_Drv_ExtractConfigIndex(CanCtrID);
    if(CanFusa_Cntrl_In_SafeState(controllerId) != TRUE)
#endif
    {
        SET_CAN_HW_REG(CanCtrID,CANSS_M_CAN_FE_IRQ_STTS_CLR, CANSS_TWO);
#if(CAN_ENABLE_DEBUG_LOGGING == STD_ON)
        //Can_FE1_InterruptCnt[controllerId]++;
#endif
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
void CANSS_FE2_COMMON_HANDLER(uint8 CanCtrID)
{
#if(CAN_FUSA_ENABLE == STD_ON)
    uint8 controllerId = Can_Drv_ExtractConfigIndex(CanCtrID);
    if(CanFusa_Cntrl_In_SafeState(controllerId) != TRUE)
#endif
    {
        SET_CAN_HW_REG(CanCtrID,CANSS_M_CAN_FE_IRQ_STTS_CLR, CANSS_FOUR);
#if(CAN_ENABLE_DEBUG_LOGGING == STD_ON)
       // Can_FE2_InterruptCnt[controllerId]++;
#endif
    }
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
