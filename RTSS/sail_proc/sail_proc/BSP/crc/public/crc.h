/**************************************************************************************************
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
**************************************************************************************************/

/*=================================================================================================
    File Name          : crc.h
    Component Name     : crc driver header file
    Description        : crc driver header file
    $Header			   : 
    $DateTime          : 
    $Author            : 
=================================================================================================*/

#ifndef CRC_H
#define CRC_H

/*=================================================================================================
**                                     Include files                                             **
=================================================================================================*/
#include "types.h"

/*=================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs         **
=================================================================================================*/


#ifndef SAILEL2
#define CRC_FUNC  __attribute__ ( ( section ( "crc_func" ) ) )
#define CRC_RO    __attribute__ ( ( section ( "crc_ro" ) ) )
#else
#define CRC_FUNC
#define CRC_RO
#endif
/* Type definition for the crc status*/
typedef enum {
    CRC_SUCCESS = 0x0,
    CRC_INVALID_PARAMETER,
    CRC_ERROR,
}crcStatus_e;
/* Type definition for the crc configuration */
typedef struct
{
	uint8                ucChannelId;
    const uint8          *pCRCtable;
    uint8                ucInitialValue;
    uint8                ucFinalXORValue;
	boolean              bInputDataReflected;
    boolean              bResultDataReflected;
}crcConfigType;

typedef struct
{
    const crcConfigType  *ChCfgPtr;
}crcCoreConfigType;

/*=================================================================================================
**                                        Global functions definition                            **
=================================================================================================*/
/*=================================================================================================
 @Service name        xCrc8Generate()
 @Description         This API is used to generate a CRC value for specific data and length.                       
 @param[in]           ucChannelId: channel ID
 @param[in]           pucBuffer:    Input data buffer pointer  
 @param[in]           ucLength:    length of the data buffer 
 @param[out]          pucCrcData:   OUTPUT parameter that will contain the value of generated CRC result
 @param[in, out]      NA
 @return              CRC_SUCCESS:   generate CRC successfully
                      CRC_INVALID_PARAMETER:  parameter invalid
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/
crcStatus_e xCrc8Generate( const uint8 ucChannelId, const uint8 *pucBuffer,
                           const uint8 ucLength, uint8 *const pucCrcData );

/*=================================================================================================
 @Service name        xCrc8Verify()
 @Description         This API is Used to verify the CRC value for specific data and length.      
 @param[in]           ucChannelId: channel ID
 @param[in]           pucBuffer:    Input data buffer pointer  
 @param[in]           ucLength:    length of the data buffer 
 @param[out]          ucCrcData:    The CRC that to be verified
 @param[in, out]      NA
 @return              CRC_SUCCESS:   verify CRC successfully
                      CRC_INVALID_PARAMETER:  parameter invalid
					  CRC_ERROR:  Recalculated CRC mismatch with received CRC
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
=================================================================================================*/
crcStatus_e xCrc8Verify( const uint8 ucChannelId, const uint8 *pucBuffer,
                         const uint8 ucLength, const uint8 ucCrcData );

#endif /* _CRC_H_ */
