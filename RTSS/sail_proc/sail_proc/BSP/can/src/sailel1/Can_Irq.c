/*
===========================================================================
*/
/**
    @file  pmic.c
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
#include "Can_Irq.h"

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

/*==============================================================================
|                       LOCAL VARIABLES                                        |
==============================================================================*/
/*==============================================================================
|                       ISRTION DEFINITIONS                                   |
==============================================================================*/

#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS0_INT0_ISR)
{
    CANSS_INT0_COMMON_HANDLER(CANSS_ZERO);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS0_INT1_ISR)
{
    CANSS_INT1_COMMON_HANDLER(CANSS_ZERO);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS1_INT0_ISR)
{
    CANSS_INT0_COMMON_HANDLER(CANSS_ONE);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS1_INT1_ISR)
{
    CANSS_INT1_COMMON_HANDLER(CANSS_ONE);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS2_INT0_ISR)
{
    CANSS_INT0_COMMON_HANDLER(CANSS_TWO);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS2_INT1_ISR)
{
    CANSS_INT1_COMMON_HANDLER(CANSS_TWO);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS3_INT0_ISR)
{
    CANSS_INT0_COMMON_HANDLER(CANSS_THREE);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS3_INT1_ISR)
{
    CANSS_INT1_COMMON_HANDLER(CANSS_THREE);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS4_INT0_ISR)
{
    CANSS_INT0_COMMON_HANDLER(CANSS_FOUR);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS4_INT1_ISR)
{
    CANSS_INT1_COMMON_HANDLER(CANSS_FOUR);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS5_INT0_ISR)
{
    CANSS_INT0_COMMON_HANDLER(CANSS_FIVE);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS5_INT1_ISR)
{
    CANSS_INT1_COMMON_HANDLER(CANSS_FIVE);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS6_INT0_ISR)
{
    CANSS_INT0_COMMON_HANDLER(CANSS_SIX);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS6_INT1_ISR)
{
    CANSS_INT1_COMMON_HANDLER(CANSS_SIX);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS7_INT0_ISR)
{
    CANSS_INT0_COMMON_HANDLER(CANSS_SEVEN);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS7_INT1_ISR)
{
    CANSS_INT1_COMMON_HANDLER(CANSS_SEVEN);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS0_FE0_ISR)
{
    CANSS_FE0_COMMON_HANDLER(CANSS_ZERO);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS1_FE0_ISR)
{
    CANSS_FE0_COMMON_HANDLER(CANSS_ONE);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS2_FE0_ISR)
{
    CANSS_FE0_COMMON_HANDLER(CANSS_TWO);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS3_FE0_ISR)
{
    CANSS_FE0_COMMON_HANDLER(CANSS_THREE);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS4_FE0_ISR)
{
    CANSS_FE0_COMMON_HANDLER(CANSS_FOUR);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS5_FE0_ISR)
{
    CANSS_FE0_COMMON_HANDLER(CANSS_FIVE);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS6_FE0_ISR)
{
    CANSS_FE0_COMMON_HANDLER(CANSS_SIX);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS7_FE0_ISR)
{
    CANSS_FE0_COMMON_HANDLER(CANSS_SEVEN);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS0_FE1_ISR)
{
    CANSS_FE1_COMMON_HANDLER(CANSS_ZERO);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS1_FE1_ISR)
{
    CANSS_FE1_COMMON_HANDLER(CANSS_ONE);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS2_FE1_ISR)
{
    CANSS_FE1_COMMON_HANDLER(CANSS_TWO);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS3_FE1_ISR)
{
    CANSS_FE1_COMMON_HANDLER(CANSS_THREE);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS4_FE1_ISR)
{
    CANSS_FE1_COMMON_HANDLER(CANSS_FOUR);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS5_FE1_ISR)
{
    CANSS_FE1_COMMON_HANDLER(CANSS_FIVE);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS6_FE1_ISR)
{
    CANSS_FE1_COMMON_HANDLER(CANSS_SIX);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS7_FE1_ISR)
{
    CANSS_FE1_COMMON_HANDLER(CANSS_SEVEN);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS0_FE2_ISR)
{
    CANSS_FE2_COMMON_HANDLER(CANSS_ZERO);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS1_FE2_ISR)
{
    CANSS_FE2_COMMON_HANDLER(CANSS_ONE);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS2_FE2_ISR)
{
    CANSS_FE2_COMMON_HANDLER(CANSS_TWO);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS3_FE2_ISR)
{
    CANSS_FE2_COMMON_HANDLER(CANSS_THREE);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS4_FE2_ISR)
{
    CANSS_FE2_COMMON_HANDLER(CANSS_FOUR);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS5_FE2_ISR)
{
    CANSS_FE2_COMMON_HANDLER(CANSS_FIVE);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS6_FE2_ISR)
{
    CANSS_FE2_COMMON_HANDLER(CANSS_SIX);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS7_FE2_ISR)
{
    CANSS_FE2_COMMON_HANDLER(CANSS_SEVEN);
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS0_DMA_ISR)
{
	#if(CAN_DMA_ENABLE == STD_ON)
    CANSS_COMMON_DMA_HANDLER(CANSS_ZERO);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS1_DMA_ISR)
{
	#if(CAN_DMA_ENABLE == STD_ON)
    CANSS_COMMON_DMA_HANDLER(CANSS_ONE);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS2_DMA_ISR)
{
	#if(CAN_DMA_ENABLE == STD_ON)
    CANSS_COMMON_DMA_HANDLER(CANSS_TWO);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS3_DMA_ISR)
{
	#if(CAN_DMA_ENABLE == STD_ON)
    CANSS_COMMON_DMA_HANDLER(CANSS_THREE);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS4_DMA_ISR)
{
	#if(CAN_DMA_ENABLE == STD_ON)
    CANSS_COMMON_DMA_HANDLER(CANSS_FOUR);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS5_DMA_ISR)
{
	#if(CAN_DMA_ENABLE == STD_ON)
    CANSS_COMMON_DMA_HANDLER(CANSS_FIVE);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS6_DMA_ISR)
{
	#if(CAN_DMA_ENABLE == STD_ON)
    CANSS_COMMON_DMA_HANDLER(CANSS_SIX);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS7_DMA_ISR)
{
	#if(CAN_DMA_ENABLE == STD_ON)
    CANSS_COMMON_DMA_HANDLER(CANSS_SEVEN);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS0_DMU_ISR)
{
	#if(CAN_DMA_ENABLE == STD_ON)
    CANSS_COMMON_DMU_HANDLER(CANSS_ZERO);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS1_DMU_ISR)
{
	#if(CAN_DMA_ENABLE == STD_ON)
    CANSS_COMMON_DMU_HANDLER(CANSS_ONE);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS2_DMU_ISR)
{
	#if(CAN_DMA_ENABLE == STD_ON)
    CANSS_COMMON_DMU_HANDLER(CANSS_TWO);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS3_DMU_ISR)
{
	#if(CAN_DMA_ENABLE == STD_ON)
    CANSS_COMMON_DMU_HANDLER(CANSS_THREE);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS4_DMU_ISR)
{
	#if(CAN_DMA_ENABLE == STD_ON)
    CANSS_COMMON_DMU_HANDLER(CANSS_FOUR);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS5_DMU_ISR)
{
	#if(CAN_DMA_ENABLE == STD_ON)
    CANSS_COMMON_DMU_HANDLER(CANSS_FIVE);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS6_DMU_ISR)
{
	#if(CAN_DMA_ENABLE == STD_ON)
    CANSS_COMMON_DMU_HANDLER(CANSS_SIX);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS7_DMU_ISR)
{
	#if(CAN_DMA_ENABLE == STD_ON)
    CANSS_COMMON_DMU_HANDLER(CANSS_SEVEN);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS0_FUSA_ERROR_ISR)
{
	#if(CAN_FUSA_ENABLE == STD_ON)
    CANSS_FUSA_ERROR_HANDLER(CANSS_ZERO);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS1_FUSA_ERROR_ISR)
{
	#if(CAN_FUSA_ENABLE == STD_ON)
    CANSS_FUSA_ERROR_HANDLER(CANSS_ONE);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS2_FUSA_ERROR_ISR)
{
	#if(CAN_FUSA_ENABLE == STD_ON)
    CANSS_FUSA_ERROR_HANDLER(CANSS_TWO);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS3_FUSA_ERROR_ISR)
{
	#if(CAN_FUSA_ENABLE == STD_ON)
    CANSS_FUSA_ERROR_HANDLER(CANSS_THREE);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS4_FUSA_ERROR_ISR)
{
	#if(CAN_FUSA_ENABLE == STD_ON)
    CANSS_FUSA_ERROR_HANDLER(CANSS_FOUR);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS5_FUSA_ERROR_ISR)
{
	#if(CAN_FUSA_ENABLE == STD_ON)
    CANSS_FUSA_ERROR_HANDLER(CANSS_FIVE);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS6_FUSA_ERROR_ISR)
{
	#if(CAN_FUSA_ENABLE == STD_ON)
    CANSS_FUSA_ERROR_HANDLER(CANSS_SIX);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS7_FUSA_ERROR_ISR)
{
	#if(CAN_FUSA_ENABLE == STD_ON)
    CANSS_FUSA_ERROR_HANDLER(CANSS_SEVEN);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS0_FUSA_WARNING_ISR)
{
	#if(CAN_FUSA_ENABLE == STD_ON)
    CANSS_FUSA_WARNING_HANDLER(CANSS_ZERO);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS1_FUSA_WARNING_ISR)
{
	#if(CAN_FUSA_ENABLE == STD_ON)
    CANSS_FUSA_WARNING_HANDLER(CANSS_ONE);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS2_FUSA_WARNING_ISR)
{
	#if(CAN_FUSA_ENABLE == STD_ON)
    CANSS_FUSA_WARNING_HANDLER(CANSS_TWO);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS3_FUSA_WARNING_ISR)
{
	#if(CAN_FUSA_ENABLE == STD_ON)
    CANSS_FUSA_WARNING_HANDLER(CANSS_THREE);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS4_FUSA_WARNING_ISR)
{
	#if(CAN_FUSA_ENABLE == STD_ON)
    CANSS_FUSA_WARNING_HANDLER(CANSS_FOUR);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS5_FUSA_WARNING_ISR)
{
	#if(CAN_FUSA_ENABLE == STD_ON)
    CANSS_FUSA_WARNING_HANDLER(CANSS_FIVE);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS6_FUSA_WARNING_ISR)
{
	#if(CAN_FUSA_ENABLE == STD_ON)
    CANSS_FUSA_WARNING_HANDLER(CANSS_SIX);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
ISR(CANSS7_FUSA_WARNING_ISR)
{
	#if(CAN_FUSA_ENABLE == STD_ON)
    CANSS_FUSA_WARNING_HANDLER(CANSS_SEVEN);
    #endif
}
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"

