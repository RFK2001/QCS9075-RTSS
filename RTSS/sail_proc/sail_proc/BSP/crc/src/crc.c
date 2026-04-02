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
    File Name          : crc.c
    Component Name     : crc Device driver
    Description        : CRC SAE J1850 is used as a building block for higher level 
	                     FuSa constructs.
    $Header: 
    $DateTime: 
    $Author: 
=================================================================================================*/

/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/

#include "crc.h"
#include "crcconfig.h"
#include "crc_local.h"

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
CRC_FUNC crcStatus_e xCrc8Generate( const uint8 ucChannelId, const uint8 *pucBuffer,
                           const uint8 ucLength, uint8 *const pucCrcData )
{
    uint8 ucCrc8;
    uint8 ucCount = 0U;
    crcStatus_e xStatus = CRC_SUCCESS;
    const uint8 *puBufPtr = pucBuffer;

    if ((pucBuffer == NULL) || (pucCrcData == NULL) || (ucLength == 0U)) {
        xStatus = CRC_INVALID_PARAMETER;
    } else {
		ucCrc8 = xCrcCoreConfig.ChCfgPtr[ucChannelId].ucInitialValue;
        for (ucCount = 0; ucCount < ucLength; ucCount++) {
            ucCrc8 = xCrcCoreConfig.ChCfgPtr[ucChannelId].pCRCtable[(ucCrc8 ^ (uint8)*(puBufPtr++)) & 0xFFU];
        }

        *pucCrcData = ucCrc8 ^ xCrcCoreConfig.ChCfgPtr[ucChannelId].ucFinalXORValue;

        if(xCrcCoreConfig.ChCfgPtr[ucChannelId].bResultDataReflected == TRUE)
        {
        	*pucCrcData = ~ucCrc8;
        }
    }

    return xStatus;
}

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
CRC_FUNC crcStatus_e xCrc8Verify( const uint8 ucChannelId, const uint8 *pucBuffer,
                         const uint8 ucLength, const uint8 ucCrcData )
{
    uint8 checking_crc = 0;
    crcStatus_e xStatus = CRC_SUCCESS;

    xStatus = xCrc8Generate(ucChannelId, pucBuffer, ucLength, &checking_crc);

    if (xStatus == CRC_SUCCESS) {
        if (checking_crc != ucCrcData) {
            xStatus = CRC_ERROR;
        }
    }
    return xStatus;
}

/* End of File*/
