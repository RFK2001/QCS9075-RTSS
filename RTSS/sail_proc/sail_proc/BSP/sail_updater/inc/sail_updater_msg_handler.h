
#ifndef __SAIL_UPDATER_MSG_HANDLER_H__
#define __SAIL_UPDATER_MSG_HANDLER_H__

/*
===========================================================================
*/
/**
    @file  sail_updater_msg_handler.h
    @brief This file provides definitions for the SAIL Updater Message Handling support functions.

*/
/*
    ===========================================================================

    Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/sail_updater/inc/sail_updater_msg_handler.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "sail_updater_cmn.h"

#include "sail_updater_msgtypes.h"

/**********************************************************
 * Checks the Validity of the Header Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterMsgCheckHeaderValidity(sailUpdaterMsgHeaderType* pReqMsg);

/**********************************************************
 * Process the Request Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
void vSAILUpdaterMsgProcessReqMsg(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Prepares the Error Response Message
 *
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Request Message
 *
 * @param eStatus [IN]
 *   Error Message
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
void vSAILUpdaterMsgPrepareErrRsp(sailUpdaterMsgHeaderType* pRspMsg, SAILUpdaterStatusType_e eStatus);

/**********************************************************
 * Sends the Response Message
 *
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Request Message
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
void vSAILUpdaterMsgSendResponse(sailUpdaterMsgHeaderType* pRspMsg);

#endif /* __SAIL_UPDATER_MSG_HANDLER_H__ */
