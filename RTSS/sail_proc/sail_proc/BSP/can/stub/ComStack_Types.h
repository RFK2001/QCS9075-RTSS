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
    File Name          : ComStack_Types.h
    Component Name     : communication stack  types
    Description        : Internal Header file for CAN Driver.
    $Header: //components/rel/bsp.sail/1.0/can/inc/ComStack_Types.h#11 $
    $DateTime: 2022/07/07 12:35:03 $
    $Author: pwbldsvc $
=========================================================================================================*/

/**
 * @file ComStack_Types.h
 * @author radvajesh
 * @date 17 Aug 2022
 * @brief File containing standard communication stack  types.
 *
 * The com stack types header file defines communication stack  types
 * @see https://www.autosar.org/fileadmin/user_upload/standards/classic/4-3/AUTOSAR_SWS_CommunicationStackTypes.pdf
 */
#include "Std_Types.h"

#ifndef COMSTACK_TYPES_H
#define COMSTACK_TYPES_H

#define COMSTACKTYPE_AR_MAJOR_VERSION       (4U)
#define COMSTACKTYPE_AR_MINOR_VERSION       (8U)
#define COMSTACKTYPE_AR_PATCH_VERSION       (0U)
/** @var typedef uint16 PduIdType
 * @brief This type is used within the entire AUTOSAR Com Stack except for bus drivers.Zero-based integer number
 *
 * @ReqID:[SWS_COMTYPE_00005].
 */
typedef uint16 PduIdType;


/** @var typedef uint16 PduLengthType
 * @brief This type shall be used within the entire AUTOSAR Com Stack of an ECU except for
 * bus drivers.
 *
 * @ReqID:[SWS_COMTYPE_00008].
 */
typedef uint16 PduLengthType;


/** @struct PduInfoType
 * @brief Variables of this type shall be used to store the basic information about a PDU of
 * any type, namely a pointer variable pointing to its SDU (payload), a pointer to
 * Meta Data of the PDU, and the corresponding length of the SDU in bytes...
 *
 * @ReqID:SWS_COMTYPE_00011.
 */
typedef struct
{
  /*Pointer to the SDU (i.e. payload data) of the PDU. The type of this pointer depends on the memory model being
   used at compile time.*/

	uint8* SduDataPtr;

	/*Pointer to the meta data (e.g. CAN ID,socket ID, diagnostic addresses) of the
      PDU, consisting of a sequence of meta data items. The length and type of the
      meta data items is statically configured for each PDU. Meta data items with
      more than 8 bits use platform byte order*/

	uint8* MetaDataPtr;

	/*Length of the SDU in bytes*/
	PduLengthType SduLength;

}PduInfoType;

/** @enum BufReq_ReturnType
 * @brief Variables of this type shall be used to store the result of a buffer request
 *
 * @ReqID:SWS_COMTYPE_00012.
 */
typedef enum 
{
	/*Buffer request accomplished successful*/
	BUFREQ_OK,
	
	/*Buffer request not successful. Buffer cannot be accessed*/
	BUFREQ_E_NOT_OK,
	
	/*Temporarily no buffer available. It's up the requester to retry 
	request for a certain time*/
	BUFREQ_E_BUSY,
	
	/*No Buffer of the required length can be provided*/
	BUFREQ_E_OVFL
}BufReq_ReturnType;
	

#endif /* COMSTACK_TYPES_H */
