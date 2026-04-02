/**********************************************************************************************************
    Copyright (c) 2021-2024 Qualcomm Technologies, Inc.
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
    File Name          : autosar_crc.h
    Component Name     : DMA CRC Driver
    Description        : Cache utility header file
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/crc/public/autosar_crc.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $
=========================================================================================================*/

/* Include header file guard */
#ifndef __AUTOSAR_CRC_H__
#define __AUTOSAR_CRC_H__

/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/

#include <stdlib.h>// Include Dependencies here
#include "types.h"

/*=========================================================================================================
**                                     defines and macros                                          **
=========================================================================================================*/
typedef enum
{
    AUTOSAR_CRC_NOT_USED,
    AUTOSAR_CRC_8BIT_SAE_J1850,
    AUTOSAR_CRC_8BIT_0X2F,
    AUTOSAR_CRC_16BIT_CCITT_FALSE,
    AUTOSAR_CRC_32BIT_ETHERNET,
    AUTOSAR_CRC_32BIT_0XF4ACFB13,
    AUTOSAR_CRC_MAX
}AutosarCrcType;
    

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/
uint32_t ulAutosarCrcBufList(AutosarCrcType eCRCPoly, uint32_t *pBufAddrArray, uint32_t *pBufLenArray, uint32_t num);
uint32_t ulAutosarCrc(AutosarCrcType eCRCPoly, uint8_t *pBuf, uint32_t sz);
uint32_t ulAutosarCumulativeCrcBufList(AutosarCrcType eCRCPoly, uint32_t *pBuffersAddr, uint32_t *pBuffersLen, uint32_t num,  bool lastIteration, uint32_t calcCrc);

#endif /*__CE_CACHE_H__*/

/**********************************************************************************************************
**                                  End of file ce_cache.h                                               **
**********************************************************************************************************/
