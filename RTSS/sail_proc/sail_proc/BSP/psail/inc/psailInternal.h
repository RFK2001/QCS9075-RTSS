/*
===========================================================================
*/
/**
    @file  psailInternal.h
    @brief This file contains all the internal API exposed in PSAIL Driver
        which is internally used 

*/
/*
    ===========================================================================

    Copyright (c) 2021-2022 Qualcomm Technologies, Inc.
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
#ifndef PSAILINTERNAL_H
#define PSAILINTERNAL_H


/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include <stdbool.h>
#include "types.h"
#include "i2c.h"
#include "freertos_init.h"
#include "chipinfo.h"
#include "chipinfodefs.h"
#include "platforminfodefs.h"

/*=================================================================================================
**                          Global typedefs : Macros, Enums and  Structures                       **
===================================================================================================*/
#define HWIO_PSAIL(reg)             (uint32)HWIO_##reg##_ADDR
#define HWIO_PMSK(reg, field)       (uint32)HWIO_##reg##_##field##_BMSK 
#define HWIO_PSHFT(reg, field)      (uint32)HWIO_##reg##_##field##_SHFT

#define psailMAX_CHIP_ON_SOC                        0x4U
#define psailREVID_PERPH_TYPE                       0x51U
#define psailREVID_PERPH_SUBTYPE                    0x4FU
#define psailDEFAULT_REVID                          0xFFU
#define psailDEFAULT_LOG_EVT_CNT                    0U
#define psailNUM_OF_MEM_INTF_RD_DATA_REG            0x6U
#define psailNUM_OF_AGGR_STATUS_REG                 0x5U
#define psailEFS_RET_SUCCESS                        0x0U
/* PsailID, Aggr status reg 0-4, No_of_Log_events = 7 bytes*/
#define psailLOG_HEADER_INFO_SIZE                   0x7U
#define MaxFaultDataPerPsail                        10u
#define BITSET(x)                                   ((((uint8)0x1u)<<(uint8)x)&(0xFFu))
#define psailMAX_CHANNEL_ID							0x6u
#define psailErr_GPIO_LEMANS                        63U // PSAIL Pin of MD PSAIL PMIC is mapped to SAIL_GPIO_IO 63
#define psailErr_GPIO_MONACO                        52U // PSAIL Pin of MD PSAIL PMIC is mapped to SAIL_GPIO_IO 52

#ifdef lemans
    #define psailPinGPIONumber                      psailErr_GPIO_LEMANS
#else
    #define psailPinGPIONumber                      psailErr_GPIO_MONACO
#endif

#define PSAIL_DATA                        __attribute__ ( ( section ( "psail_data" ) ) )

/* Make Sure These Addresses Are Aligned To 64 Bytes */
PSAIL_DATA extern uint32_t Image$$lnkPSAILDATAStartAddr$$Base;
PSAIL_DATA extern uint32_t Image$$lnkPSAILDATAEndAddr$$Base;

#define SAILBSP_PSAIL_DATA_ADDR_BASE      (void *)&Image$$lnkPSAILDATAStartAddr$$Base
#define SAILBSP_PSAIL_DATA_ADDR_SIZE      (uint32_t)( (uint32_t)&Image$$lnkPSAILDATAEndAddr$$Base -\
                                                          (uint32_t)&Image$$lnkPSAILDATAStartAddr$$Base )

/*
 * psailChannelType_e;
 * PSAIL Channel list
 */
typedef enum
{
    PSAIL_B_ID = I2C_CHANNEL_ID_3,
    PSAIL_D_ID = I2C_CHANNEL_ID_4,
    PSAIL_F_ID = I2C_CHANNEL_ID_5,
    PSAIL_H_ID = I2C_CHANNEL_ID_6,
    MAX_PSAIL_ID
} psailChannelType_e;


/*
 * psailDeviceInfoType;
 * PSAIL Device information
 */
typedef struct
{
    psailChannelType_e eChannelId;
    boolean  bPsailPresent;
    uint8    ucRevIdType;
    uint8    ucRevIdSubType;
    uint8    ucLogEventCnt;
    uint8    ucPsailPingStatus;
} psailDeviceInfoType;

/*
 * psailLevel2FaultLogType;
 * PSAIL log information
 * from FAULT_AGG_MEM_INTF_RD_DATA4-5 register
 */
typedef struct
{
    unsigned ucTimeStamp:32;
    unsigned ucMonitorPID:8;
    unsigned ucMonitorIndex:3;
    unsigned ucNewError:2;
    unsigned ucOldError:2;
    unsigned ucThresholdViolation:2;
} psailLevel2FaultLogType;

/*
 * PSAILStatusType_e;
 * List of PSAIL error status
 */
typedef enum
{
    PSAIL_ERROR = 0,
    PSAIL_SUCCESS,
    PSAIL_INIT_ERROR,
    PSAIL_LOG_DUMP_ERROR,
    PSAIL_LOG_WRITE_ERROR,
    PSAIL_IVI_PFLR_Mode
}PSAILStatusType_e;

typedef struct
{
    uint8 PsailId;
    uint8 ucLvl2FaultCount;
    psailLevel2FaultLogType Lvl2ErrorInfo[MaxFaultDataPerPsail];
}PsailFaultLogDataType;

typedef struct
{
    PsailFaultLogDataType ucPsailFaultLog[psailMAX_CHIP_ON_SOC];
    uint32 magicNumber;
    uint64 rsvd;
}PsailSPINORDataType;


typedef enum
{
    PSAIL_ERROR_OCCURED = 0,
    PSAIL_ERROR_NOT_OCCURED = 1,
}psailErrType;


typedef struct
{
    psailErrType PsailStatus;
}Psail_QueueMsgType;



/*
 * psailDebugType_e;
 * PSAIL Debug Modes
 */
typedef enum
{
    PSAIL_DEBUG_OFF = 0,
    PSAIL_DEBUG_ON
} psailDebugType_e;


/*=========================================================================================================
**                                    Local function prototypes                                         **
=========================================================================================================*/


PSAILStatusType_e xPSAILDumpSDAMMemory(void);

PSAILStatusType_e xPSAILCollectFirstFaultLog(uint8 ucPsailErrorData[16]);

PSAILStatusType_e xPSAILDumpFaultLog( PsailFaultLogDataType ucPsailFaultLog[] );

PSAILStatusType_e xPinBIST(void);

PSAILStatusType_e xPsailBPingTillReady(void);

PSAILStatusType_e xPsailDriverInit(void);

void vPSAILClearError(void);

#endif /* PSAILINTERNAL_H  */
/**********************************************************************************************************
**                                  End of file psailInternal.h                                          **
**********************************************************************************************************/
