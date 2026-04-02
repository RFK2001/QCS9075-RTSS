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

/*=============================================================================
    File Name.............. : CanTrcv_184_Tcan1044_Drv.c
    Description............ : CAN Transceiver TCAN1044 driver internal source
                              file
    Autosar Release Version : R22-11
    Platform............... :
    SW Release Version..... :

=============================================================================*/

/*=============================================================================
|                       REVISION HISTORY                                      |
===============================================================================
| Revision  Date            Changed By        Description                     |
===============================================================================

=============================================================================*/

/*=============================================================================
|                       INCLUDE FILES                                         |
=============================================================================*/
#include "CanTrcv_184_Tcan1044_Drv.h"   /*CAN Transceiver internal header file*/
#ifdef CAN_PLT_SAFERTOS_ENABLE
#include "gpio.h"
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
/******************************************************************************
Service Name...... : CanTrcv_184_Tcan1044_NormalMode
Parameters (IN)... : ChannelPtr
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : None
Description....... : This service initiates the transition to the Normal
                     operating mode
Design IDs Covered :
******************************************************************************/
void Tcan1044DrvSetNormalMode(const CanTrcv_Tcan1044ChConfigType *channelPtr)
{
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-Low */
#ifndef CAN_PLT_SAFERTOS_ENABLE
    Dio_WriteChannel((channelPtr->StandBypin), (Dio_LevelType)STD_LOW);
#else
    (void)sail_gpio_WritePin((uint32_t)channelPtr->StandBypin, (uint32_t)STD_LOW);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
}
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"

#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
/******************************************************************************
Service Name...... : CanTrcv_184_Tcan1044_StandbyMode
Parameters (IN)... : ChannelPtr
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : None
Description....... : This service initiates the transition to the Standby
                     operating mode
Design IDs Covered :
******************************************************************************/
void Tcan1044DrvSetStandbyMode(const CanTrcv_Tcan1044ChConfigType *channelPtr)
{
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
#ifndef CAN_PLT_SAFERTOS_ENABLE
    Dio_WriteChannel((channelPtr->StandBypin), (Dio_LevelType)STD_HIGH);
#else
        (void)sail_gpio_WritePin((uint32_t)channelPtr->StandBypin, (uint32_t)STD_HIGH);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

}
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"

/*=============================================================================
|                       END OF FILE                                           |
=============================================================================*/
