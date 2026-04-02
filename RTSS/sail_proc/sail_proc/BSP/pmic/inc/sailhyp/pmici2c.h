/*
===========================================================================
*/
/**
    @file  pmici2c.h
    @brief This file contains api to communicate pmic driver to i2c

*/
/*
    ===========================================================================

    Copyright (c) 2021-2023 Qualcomm Technologies, Inc.
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


/* Include header file guard */
#ifndef PMICI2C_H
#define PMICI2C_H


/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "i2c.h"
#include "pmicapi.h"

/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/

#define SLAVE_PRESENT           ((uint8)0x1u)
#define SLAVE_NOT_PRESENT       ((uint8)0x0u)

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/


typedef struct
{
    uint8 deviceId;
    uint8 nvmCode1;
    uint8 nvmCode2;
    uint8 customerNvmId;
}pmicDeviceInfoType;



/*
• Page 0: User Registers
• Page 1: NVM Control, Configuration, and Test Registers
• Page 2: Trim Registers
• Page 3: SRAM for PFSM Registers
• Page 4: WatchDog Registers
*/

typedef enum : uint32
{
    PAGE_ID_0 = I2C_CHANNEL_ID_0,
    PAGE_ID_1 = I2C_CHANNEL_ID_1,
    PAGE_ID_4 = I2C_CHANNEL_ID_2,
    MAX_PMIC_PAGE_ID
}pmicPageId_e;

typedef enum
{
    DEVICE_ID = 0x0,
    NVMCODE1,
    NVMCODE2,
    CUSTOMER_NVMID,
    MAX_PMIC_ID
}pmicInfo_e;



/*=========================================================================================================
**                                    Global function prototypes                                         **
=========================================================================================================*/

pmicErrFlagType_e prvPmicVersionDetect(void);
pmicErrFlagType_e prvPmicCommReadByte(pmicPageId_e xpageId, uint32 uladdr , uint8* pcdata);
pmicErrFlagType_e prvPmicCommWriteByte(pmicPageId_e xpageId,uint32 uladdr ,uint8 ucdata);
pmicErrFlagType_e prvPmicCommWriteByteMask(pmicPageId_e xpageId,uint32 uladdr,uint8 ucmask, uint8 ucvalue);
pmicErrFlagType_e prvPmicCommReadByteMask(pmicPageId_e xpageId,uint32 uladdr, uint8 ucmask, uint8* pcdata);
void vSetPmicPingStatus(pmicPageId_e xpageId);
uint8 ucGetPmicPingStatus(pmicPageId_e xpageId);
uint8 prvGetSAILPMICInfo( pmicInfo_e xPmicInfoType );
pmicErrFlagType_e prvPmicCRCEnable( void );

#endif /* PMICEL2I2C_H  */
/**********************************************************************************************************
**                                  End of file <pmici2c.h>                                              **
**********************************************************************************************************/
