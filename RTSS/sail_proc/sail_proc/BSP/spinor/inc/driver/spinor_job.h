
#ifndef __SPINOR_JOB_H__
#define __SPINOR_JOB_H__
/*
===========================================================================
*/
/**
    @file  spinor_job.h
    @brief This file provides definitions for the spinor job

*/
/*
    ===========================================================================

    Copyright (c) 2023 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/inc/driver/spinor_job.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "spinor_api.h"
#include "spinor_cmd.h"
#include "spinor_transaction.h"
#include "timetick.h"

/* Mode of the Job */
typedef enum
{
    SPINOR_JOB_MODE_ASYNC = 0,       /* Asynchronous operation */
    SPINOR_JOB_MODE_SYNC,            /* Synchronous operation */
    SPINOR_JOB_MODE_MAX              /* Max/Error value */
}spinor_JobModeType;

/* Type of Job Operation */
typedef enum
{
    SPINOR_JOB_OP_NONE = 0,          /* Default/init value */
    SPINOR_JOB_OP_ERASE_MEM,         /* Erase Memory Operation */
    SPINOR_JOB_OP_READ_MEM,          /* Read Memory Operation */
    SPINOR_JOB_OP_WRITE_MEM,         /* Write Memory Operation */
    SPINOR_JOB_OP_WRITE_REG,         /* Write Register Operation */
    SPINOR_JOB_OP_WRITE_REG_ADDR,    /* Write Register with an address Operation */
    SPINOR_JOB_OP_READ_REG,          /* Read Register Operation */
    SPINOR_JOB_OP_READ_REG_ADDR,     /* Read Register with an address Operation */
    SPINOR_JOB_OP_READ_SFDP,         /* Read SFDP Operation */
    SPINOR_JOB_OP_DEV_OP,            /* Device Operation */
    SPINOR_JOB_OP_BINARY_CMD,        /* Binary command type */
    SPINOR_JOB_OP_MAX,               /* Max/Error value */
}spinor_JobOperationType;

/* Overall Job Operation State */
typedef struct
{
    union
    {
        spinor_SPICMDOperationStateType spicmdstate;
        spinor_EraseOperationStateType erasememstate;
        spinor_WriteOperationStateType writememstate;
        spinor_ReadOperationStateType readmemstate;
    };
}spinor_JobOperationStateType;

/* Job Operation Parameters */
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
}spinor_OperationParamType;

/* Job Operation Context */
typedef struct
{
    spinor_JobOperationType jobType;                 /* Job Type */
    spinor_OperationParamType jobParams;             /* Job Parameters */
    spinor_JobOperationStateType jobOperationState;  /* Job Status */
    uint32 sparereadbuffer;                          /* Spare buffer for read status */
    uint32 extrareadbuffer;                          /* Spare buffer for reading last few bytes of read data */
    SPINOR_CMDEngineParamType CMDEngineParams;       /* Command Engine Params in progress */
    timetick_type_64 t1;                             /* Transaction start timetick for measuring timeouts */
}spinor_JobOperationCtxType;

/**********************************************************
 * Despatches the Job Operation synchornously
 *
 * @param xJobType [IN]
 *   Type of the Job Operation
 *
 * @param xMemParams [IN]
 *   Job Operation Parameters
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_jobDispatcherSyncWrapper(spinor_JobOperationType xJobType, spinor_OperationParamType* xMemParams);

/**********************************************************
 * Despatches the Job Operation asynchronosly
 *
 * @param xJobMode [IN]
 *   Mode of the Job Operation
 *
 * @param xJobType [IN]
 *   Type of the Job Operation
 *
 * @param xMemParams [IN]
 *   Job Operation Parameters
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_jobDispatcher(spinor_JobModeType xJobMode, spinor_JobOperationType xJobType, spinor_OperationParamType* xMemParams);

/**********************************************************
 * Prepare the job operation for Command Engine.
 *
 * @param cmd_mode [IN]
 *   SPI Command mode
 *
 * @param addr [IN]
 *   Address of the memory
 *
 * @param reg_value [IN/OUT]
 *   Pointer to the data buffer
 *
 * @param len [IN]
 *   Length of the data buffer
 *
 * @param opcode [IN]
 *   Opcode for the SPI command
 *
 * @return void [OUT]
 *
 **********************************************************/
void spinor_jobPrepareOperation(SPI_COMMAND_TYPE cmd_mode, uint32_t addr, uint8 *reg_value, uint32 len,uint8_t opcode);

/**********************************************************
 * Start the Job Operation.
 *
 * @param CMDEngineParams [IN]
 *   Command Engine Parameters to start the Job
 *
 * @return int [OUT]
 *   Status of the Operation
 **********************************************************/
SPINOR_STATUS spinor_jobStartOperation(SPINOR_CMDEngineParamType* CMDEngineParams);

/**********************************************************
 * Gets the current status of the Job Operation.
 *
 * @param void [IN]
 *
 * @return int [OUT]
 *   Status of the Job Operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_jobGetOperationStatus(void);

/**********************************************************
 * Main function loop to run the Job Operation.
 *
 * @param void [IN]
 *
 * @return void [OUT]
 *
 **********************************************************/
void spinor_jobRunOperation(void);

#endif /* __SPINOR_JOB_H__ */
