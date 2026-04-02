#ifndef __SPINOR_TRAP_DEFS_H__
#define __SPINOR_TRAP_DEFS_H__

/*
===========================================================================
*/
/**
    @file  spinor_trap_defs.h
    @brief Common defines shared between SPINOR EL2 and EL1 trap layer.

*/
/*
    ===========================================================================

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

    ===========================================================================

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/public/spinor_trap_defs.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "spinor_cm_defs.h"

/* Trap Handle type */
typedef struct
{
    spinor_handle_t handle;
    uint32 *pwd;
}spinorTrapHandle_t;

/* Trap Region Info type */
typedef struct {
    uint32_t base;
    uint32_t size;
} spinorTrapRegionInfo_t;

/* Trap Bincmd Parameters */
typedef struct
{
    uint32_t addr;                /* Address of the memory/register */
    uint32_t len;                 /* Length of the buffer or data or block count */
    uint8 *buffer;                /* Data buffer */
    uint8_t opcode;               /* Opcode for the SPI command */
    uint8_t dummy_cycle;          /* Number of Dummy cycles (used only for binary commands) */
    uint8_t num_addr_bytes;       /* Number of address bytes (used only for binary commands) */
    boolean is_write_operation;   /* Is the operation write or not. Needed for cache/pre/post operations (used only for binary commands) */
    boolean use_dma;              /* Use the SPINOR DMA or PIO. Needed for cache/pre/post operations(used only for binary commands) */
}spinorTrapBincmdParams_t;

/* Trap Read/Write Param type */
typedef struct {
    uint32_t byte_offset;
    uint32_t byte_count;
    const void *buffer;
} spinorTrapRWRegionParam_t;

/* Trap Open Handle type */
typedef struct
{
    spinorTrapHandle_t *h;
    eSpinorUserType eUserType;
}spinorTrapOpenParam_t;

/* Trap Close Handle type */
typedef struct
{
    spinorTrapHandle_t *h;
}spinorTrapCloseParam_t;

/* Trap Low Power mode type */
typedef struct
{
    spinorTrapHandle_t *h;
    uint32_t bLowPower;
}spinorTrapLowPowerParam_t;

/* Trap Get GPT partition Info type */
typedef struct
{
    spinorTrapHandle_t *h;
    const char *guid;
    spinorTrapRegionInfo_t *pRegion;
}spinorTrapGetGptPartInfParam_t;

/* Trap Set Partition Attribute type */
typedef struct
{
    spinorTrapHandle_t *h;
    const char *guid;
    eSpinorProtectType eAttrib;
}spinorTrapSetPartAttribParam_t;

/* Trap Get Partition Attribute type */
typedef struct
{
    spinorTrapHandle_t *h;
    const char *guid;
    eSpinorProtectType* eAttrib;
}spinorTrapGetPartAttribParam_t;

/* Trap Set OTA type */
typedef struct
{
    spinorTrapHandle_t *h;
}spinorTrapSetOtaParam_t;

/* Trap Main function type */
typedef struct
{
    spinorTrapHandle_t *h;
}spinorTrapMainFuncParam_t;

/* Trap Get Job Result type */
typedef struct
{
    spinorTrapHandle_t *h;
}spinorTrapGetJobResParam_t;

/* Trap BinCmd type */
typedef struct
{
    spinorTrapHandle_t *h;
    spinorTrapBincmdParams_t *cmdparams;
}spinorTrapBincmdtype_t;

/* Trap Erase type */
typedef struct
{
    spinorTrapHandle_t *h;
    uint32 start_block;
    uint32 block_count;
}spinorTrapEraseParam_t;

/* Trap Write type */
typedef struct
{
    spinorTrapHandle_t *h;
    spinorTrapRWRegionParam_t *pRWParams;
}spinorTrapWriteParam_t;

/* Trap Read type */
typedef struct
{
    spinorTrapHandle_t *h;
    spinorTrapRWRegionParam_t *pRWParams;
}spinorTrapReadParam_t;

/* Trap Init type */
typedef struct
{
    int type;
}spinorTrapInitParam_t;

/* Trap Deinit type */
typedef struct
{
    int param;
}spinorTrapDeinitParam_t;

/* Trap Get Memory Info type */
typedef struct
{
    spinorTrapHandle_t *h;
    spinorMemInfoType *pMemInfo;
}spinorTrapGetMemInfParam_t;

/* Trap Is Device Alive type */
typedef struct
{
    int param;
}spinorTrapIsDevAliveParam_t;

/* Trap SFDP Dump type */
typedef struct
{
    int param;
}spinorTrapSfdpDumpParam_t;

/* Trap Init ReadBuffer Region type */
typedef struct
{
    uint32 addr;
    uint32 size;
}spinorTrapInitReadBufRegParam_t;

/* Trap SW Reset Close type */
typedef struct
{
    uint32_t resetCoreID;
}spinorTrapSWResetClose_t;

/* Trap GetUserType type */
typedef struct
{
    spinorTrapHandle_t *h;
    eSpinorUserType* userType;
}spinorTrapGetUserType_t;

/* Trap Resource lock type */
typedef struct
{
    uint32_t coreid;
}spinorTrapResLockType_t;

/* Trap Get sector Info type */
typedef struct
{
    spinorTrapHandle_t *h;
    spinorSectorMapInfoType *secMapInfo;
}spinorTrapGetSectorInfParam_t;

/* Trap Parameter type */
typedef struct
{
    union
    {
        spinorTrapOpenParam_t openParam;
        spinorTrapCloseParam_t closeParam;
        spinorTrapLowPowerParam_t lowPowerParam;
        spinorTrapGetGptPartInfParam_t gptPartInfoParam;
        spinorTrapSetPartAttribParam_t setPartAttribParam;
        spinorTrapGetPartAttribParam_t getPartAttribParam;
        spinorTrapSetOtaParam_t setOtaParam;
        spinorTrapMainFuncParam_t mainFuncParam;
        spinorTrapGetJobResParam_t getJobResParam;
        spinorTrapBincmdtype_t bincmdParam;
        spinorTrapEraseParam_t  eraseParam;
        spinorTrapWriteParam_t writeParam;
        spinorTrapReadParam_t readParam;
        spinorTrapInitParam_t initParam;
        spinorTrapDeinitParam_t deinitParam;
        spinorTrapGetMemInfParam_t getMemInfoParam;
        spinorTrapIsDevAliveParam_t isDevAliveParam;
        spinorTrapSfdpDumpParam_t sfdpDumpParam;
        spinorTrapInitReadBufRegParam_t readBufRegParam;
        spinorTrapSWResetClose_t resetCloseParam;
        spinorTrapGetUserType_t getUserTypeParam;
        spinorTrapResLockType_t resLockParam;
        spinorTrapGetSectorInfParam_t secMapInfoParam;
    };
}spinorTrapParams_t;

/* Event IDs for SPINOR trap calls */

typedef enum : uint32
{
    SAIL_SPINOR_FUNC_INIT   = 0,
    SAIL_SPINOR_FUNC_INIT_READBUF_REG,
    SAIL_SPINOR_FUNC_DEINIT,
    SAIL_SPINOR_FUNC_OPEN,
    SAIL_SPINOR_FUNC_CLOSE,
    SAIL_SPINOR_FUNC_GET_PARTITION_INFO,
    SAIL_SPINOR_FUNC_ERASE,
    SAIL_SPINOR_FUNC_BINCMD,
    SAIL_SPINOR_FUNC_WRITE,
    SAIL_SPINOR_FUNC_READ,
    SAIL_SPINOR_FUNC_LOWPOWER,
    SAIL_SPINOR_FUNC_SET_OTA,
    SAIL_SPINOR_FUNC_GET_MEMINFO,
    SAIL_SPINOR_FUNC_IS_DEVICE_ALIVE,
    SAIL_SPINOR_FUNC_SFDP_DUMP,
    SAIL_SPINOR_FUNC_SET_PARTITION_ATTRIB,
    SAIL_SPINOR_FUNC_GET_PARTITION_ATTRIB,
    SAIL_SPINOR_FUNC_MAINFUNC,
    SAIL_SPINOR_FUNC_GETJOBRESULT,
    SAIL_SPINOR_FUNC_SWRESETCLOSE,
    SAIL_SPINOR_FUNC_GETUSERTYPE,
    SAIL_SPINOR_FUNC_RESLOCK,
    SAIL_SPINOR_FUNC_RESUNLOCK,
    SAIL_SPINOR_FUNC_GET_SECTOR_MAP_INFO,
    SAIL_SPINOR_FUNC_MAX
}spinorTrapEventID_t;

#endif /* __SPINOR_TRAP_DEFS_H__ */
