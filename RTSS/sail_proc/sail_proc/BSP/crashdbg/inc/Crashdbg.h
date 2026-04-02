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
    File Name          : Crashdbg.h
    Component Name     : Crash Debug
    Description        : Crash Debug feature global interfaces and global parameters are defined here.
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/crashdbg/inc/Crashdbg.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $
=========================================================================================================*/

/* Include header file guard */
#ifndef _CRASHDBG_H_
#define _CRASHDBG_H_

/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/
#include "types.h"

/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/
/* Applicable only for RUMI Test platform */
//#define RUMI

/* SAILSS XO clock frequency in HZ */
#ifdef RUMI
    #define SAILSS_CC_XO_CLOCK_HZ 200000
#else
    #define SAILSS_CC_XO_CLOCK_HZ 19200000
#endif

/* SAILSS Sleep clock frequency in HZ */
#ifdef RUMI
    #define SAILSS_CC_SLEEP_CLOCK_HZ 32760
#else
    #define SAILSS_CC_SLEEP_CLOCK_HZ 37500
#endif
 
/* Convert time in ms into clock cycles before writing into timeout config registers */
#define CONVERT_TO_CYCLES(time_in_ms, clock_in_hz) ((uint32) ((time_in_ms * (uint64)clock_in_hz)/(1000)))
/* Convert cycles(ticks) to milliseconds */
#define CONVERT_TICKS_TO_MS(timer_ticks, clock_in_hz) ((uint32)((uint64)(timer_ticks * 1000) / (uint64)clock_in_hz))

/* Maximum shift count to read all packed scan dump data i.e 32-bit from RTCU scan register */
#define MAXCNT_OF_PKD_DATA  6062

/* Mask for R52 Scan dump data of 24 bit valid with each bit corresponds to one scan chain.
Total number of scan chains supported in each R52 cluster is 24 */
#define SCANDUMP_DATA_PACKET_MASK            (0x00FFFFFFL)

/* For easy scan dump analysis, scan dump data stored in DCC SRAM will be unpacked in 24 bit format */
/* Below macros will be used for unpacking algorithm */ 
#define UNPACKED_DATA_SIZE_WORDS              4
#define UNPACKED_DATA_SIZE_BYTES             (UNPACKED_DATA_SIZE_WORDS<<2)
#define PACKED_DATA_SIZE_WORDS                3
#define PACKED_DATA_SIZE_BYTES               (PACKED_DATA_SIZE_WORDS<<2)

// Data.Set 0xF1000000 %LE %Long 0x1
#define SAILSS_PWR_CTRL_ISD_CONTROL 0xF1000000UL
#define SAIL_NORMAL_MODE 0x1
#define SAIL_ISLAND_MODE 0x2

/* Number of SAILSS critical registers to be collected during crash debug */
#define SAILSS_REGDUMP_SIZE 75

/* crashdbg init status magic numbers */
#define CRASHDBG_INIT_SUCCESS                (0xAAAAAAAAU)

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/
/* Sail data dump destination memory */
typedef enum
{
    SAILSS_DDR = 0x0,
    SAILSS_NORFLASH = 0x1,
    SAILSS_DUMP_TYPE_MAX,
}Saildumpmemtype;

/*=========================================================================================================
**                          SAIL R52 APB Scandump Data Structure Format                                  **
=========================================================================================================*/
/**
  Sail scan dump data structure format for a cluster
 */
typedef struct
{
  /* Chipset information */
  uint32 chipid;
  /* JTAG ID information */
  uint32 jtagid;
  /* IP block enum */
  uint32 ipinfo;
  /* Count of instances in the dump */
  uint32 instances; //ToDO - Check whether changing the type as "SaildbgScandumpIPType" will need any change on tool side.
  /* Data  */
  uint32 data[];
}SaildbgIPScandumpType;

/**
  Enum for Sail IP blocks which support scan dump (either by DCC or SDI SW in PASS1)
 */
typedef enum
{
  SCANDUMP_R52_CLUSTER_0 = 0,
  SCANDUMP_R52_CLUSTER_1 = 1,
  MAX_IP_COUNT,
  INVALID_IP          = 0x7FFFFFFF,
}SaildbgScandumpIPType;

/* Scandump data packet type - 32bit packed data in DCC SRAM will be unpacked into 24bit format before dump */
#pragma pack(push)
#pragma pack(1)
typedef union
{
    uint32 packeddata[3];
    struct {
        uint32 unpackeddata_0:24;
        uint32 unpackeddata_1:24;
        uint32 unpackeddata_2:24;
        uint32 unpackeddata_3:24;
    };
} SaildbgScanDataPktType;
#pragma pack(pop)

/*=========================================================================================================
**                          Function declarations                                                        **
=========================================================================================================*/

#endif /* _CRASHDBG_H_ */
