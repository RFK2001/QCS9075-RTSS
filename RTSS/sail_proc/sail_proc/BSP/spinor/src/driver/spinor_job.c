/*
===========================================================================
*/
/**
    @file  spinor_job.c
    @brief This file provides definitions for the spinor job

*/
/*
    ===========================================================================

    Copyright (c) 2023-2024 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/driver/spinor_job.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/
#include "spinor_job.h"
#include "spinor_transaction.h"
#include "spinor_diag.h"
#include "common_functions.h"
#include "spinor_core.h"

spinor_JobOperationCtxType spinor_jobOperationCtx = {0};

/**********************************************************
 * Sets the current Job Operation Type.
 *
 * @param xJobType [IN]
 *   Type of the Job Operation.
 *
 * @return void [OUT]
 *
 **********************************************************/
void spinor_jobSetOperationType(spinor_JobOperationType xJobType)
{
    spinor_jobOperationCtx.jobType = xJobType;
}

/**********************************************************
 * Gets the current Job Operation Type.
 *
 * @param void [IN]
 *
 * @return int [OUT]
 *   Type of the Job Operation.
 *
 **********************************************************/
spinor_JobOperationType spinor_jobGetOperationType(void)
{
    return(spinor_jobOperationCtx.jobType);
}

/**********************************************************
 * Gets the current status of the Job Operation.
 *
 * @param void [IN]
 *
 * @return int [OUT]
 *   Status of the Job Operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_jobGetOperationStatus(void)
{
    spinor_JobOperationType xJobOpType;

    xJobOpType = spinor_jobGetOperationType();

    switch (xJobOpType)
    {
        case SPINOR_JOB_OP_ERASE_MEM:
        {
            if (ERASE_OP_ERROR == spinor_jobOperationCtx.jobOperationState.erasememstate)
            {
                return SPINOR_DEVICE_FAIL;
            }
            else if (ERASE_OP_ECC_ERROR == spinor_jobOperationCtx.jobOperationState.erasememstate)
            {
                return SPINOR_ACCESS_ECC_ERROR;
            }
            else if (ERASE_OP_CRC_ERROR == spinor_jobOperationCtx.jobOperationState.erasememstate)
            {
                return SPINOR_ACCESS_CRC_ERROR;
            }
            else if (ERASE_OP_DONE == spinor_jobOperationCtx.jobOperationState.erasememstate)
            {
                return SPINOR_DEVICE_DONE;
            }
            else if (ERASE_TIMEOUT_ERROR == spinor_jobOperationCtx.jobOperationState.erasememstate)
            {
                return SPINOR_OPERATION_TIMEOUT;
            }
            else
            {
                return SPINOR_DEVICE_OK_NOT_DONE;
            }
        }
        case SPINOR_JOB_OP_READ_MEM:
        {
            if (READ_OP_ERROR == spinor_jobOperationCtx.jobOperationState.readmemstate)
            {
                return SPINOR_DEVICE_FAIL;
            }
            else if (READ_OP_ECC_ERROR == spinor_jobOperationCtx.jobOperationState.readmemstate)
            {
                return SPINOR_ACCESS_ECC_ERROR;
            }
            else if (READ_OP_CRC_ERROR == spinor_jobOperationCtx.jobOperationState.readmemstate)
            {
                return SPINOR_ACCESS_CRC_ERROR;
            }
            else if (READ_OP_DONE == spinor_jobOperationCtx.jobOperationState.readmemstate)
            {
                return SPINOR_DEVICE_DONE;
            }
            else if (READ_TIMEOUT_ERROR == spinor_jobOperationCtx.jobOperationState.readmemstate)
            {
                return SPINOR_OPERATION_TIMEOUT;
            }
            else
            {
                return SPINOR_DEVICE_OK_NOT_DONE;
            }
        }
        case SPINOR_JOB_OP_WRITE_MEM:
        {

            if (WRITE_OP_ERROR == spinor_jobOperationCtx.jobOperationState.writememstate)
            {
                return SPINOR_DEVICE_FAIL;
            }
            else if (WRITE_OP_ECC_ERROR == spinor_jobOperationCtx.jobOperationState.writememstate)
            {
                return SPINOR_ACCESS_ECC_ERROR;
            }
            else if (WRITE_OP_CRC_ERROR == spinor_jobOperationCtx.jobOperationState.writememstate)
            {
                return SPINOR_ACCESS_CRC_ERROR;
            }
            else if (WRITE_OP_DONE == spinor_jobOperationCtx.jobOperationState.writememstate)
            {
                return SPINOR_DEVICE_DONE;
            }
            else if (WRITE_TIMEOUT_ERROR == spinor_jobOperationCtx.jobOperationState.writememstate)
            {
                return SPINOR_OPERATION_TIMEOUT;
            }
            else
            {
                return SPINOR_DEVICE_OK_NOT_DONE;
            }
        }
        case SPINOR_JOB_OP_WRITE_REG:
        case SPINOR_JOB_OP_WRITE_REG_ADDR:
        case SPINOR_JOB_OP_READ_REG:
        case SPINOR_JOB_OP_READ_REG_ADDR:
        case SPINOR_JOB_OP_READ_SFDP:
        case SPINOR_JOB_OP_DEV_OP:
        case SPINOR_JOB_OP_BINARY_CMD:
        {
            if (SPI_CMD_OP_ERROR == spinor_jobOperationCtx.jobOperationState.spicmdstate)
            {
                return SPINOR_DEVICE_FAIL;
            }
            else if (SPI_CMD_OP_DONE == spinor_jobOperationCtx.jobOperationState.spicmdstate)
            {
                return SPINOR_DEVICE_DONE;
            }
            else if (SPI_CMD_TIMEOUT_ERROR == spinor_jobOperationCtx.jobOperationState.spicmdstate)
            {
                return SPINOR_OPERATION_TIMEOUT;
            }
            else
            {
                return SPINOR_DEVICE_OK_NOT_DONE;
            }
        }
        default:
        {
            return SPINOR_DEVICE_INVALID_PARAMETER;
            SPINOR_LOG_ERROR("%s: Error, Invalid Operation Type, jobType = 0x%x \r\n", __func__, xJobOpType);
        }
    }
}

/**********************************************************
 * Despatches the Job Operation asynchronosly
 *
 * @param xJobMode [IN]
 *   Job Mode type.
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
SPINOR_STATUS spinor_jobDispatcher(spinor_JobModeType xJobMode, spinor_JobOperationType xJobType, spinor_OperationParamType* xMemParams)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    SPINOR_CMDEngineStatusType eCmdEngineStatus;
    eCmdEngineStatus = spinorCMDEngineGetState();

    if (SPINOR_JOB_MODE_ASYNC == xJobMode)
    {
        if (SPINOR_CMD_ENGINE_IDLE != eCmdEngineStatus)
        {
            return SPINOR_ACCESS_NO_BUS;
        }
    }
    else
    {
        while (SPINOR_CMD_ENGINE_IDLE != eCmdEngineStatus)
        {
            SPINOR_LOG_WARNING("%s: Error, CMD Engine is not idle. this should not happen. Lock not working \r\n", __func__);
            eCmdEngineStatus = spinorCMDEngineGetState();
        }
    }

    switch (xJobType)
    {
        case SPINOR_JOB_OP_ERASE_MEM:
        {
            #ifdef SPINOR_PROFILE_ENABLED
            p_spinor_dev->profiling_time.spinor_core_erase_time = uBootLogger_LogStartTime("---\r\n");
            #endif /* SPINOR_PROFILE_ENABLED */

            spinor_jobOperationCtx.jobOperationState.erasememstate = ERASE_PENDING;
            spinor_jobSetOperationType(xJobType);
            sailbsp_memscpy(&spinor_jobOperationCtx.jobParams,sizeof(spinor_OperationParamType), xMemParams,sizeof(spinor_OperationParamType));
            status = spinor_trans_erase_async(&spinor_jobOperationCtx);
            if (SPINOR_DEVICE_DONE != status)
            {
                spinor_jobOperationCtx.jobOperationState.erasememstate = ERASE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }
            break;
        }
        case SPINOR_JOB_OP_READ_MEM:
        {
            #ifdef SPINOR_PROFILE_ENABLED
            p_spinor_dev->profiling_time.spinor_core_read_time = uBootLogger_LogStartTime("---\r\n");
            #endif /* SPINOR_PROFILE_ENABLED */

            spinor_jobOperationCtx.jobOperationState.readmemstate = READ_PENDING;
            spinor_jobSetOperationType(xJobType);
            sailbsp_memscpy(&spinor_jobOperationCtx.jobParams,sizeof(spinor_OperationParamType), xMemParams,sizeof(spinor_OperationParamType));
            status = spinor_trans_read_async(&spinor_jobOperationCtx);
            if (SPINOR_DEVICE_DONE != status)
            {
                spinor_jobOperationCtx.jobOperationState.readmemstate = READ_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }
            break;
        }
        case SPINOR_JOB_OP_WRITE_MEM:
        {
            #ifdef SPINOR_PROFILE_ENABLED
            p_spinor_dev->profiling_time.spinor_core_write_time = uBootLogger_LogStartTime("---\r\n");
            #endif /* SPINOR_PROFILE_ENABLED */

            spinor_jobOperationCtx.jobOperationState.writememstate =  WRITE_PENDING;
            spinor_jobSetOperationType(xJobType);
            sailbsp_memscpy(&spinor_jobOperationCtx.jobParams,sizeof(spinor_OperationParamType), xMemParams,sizeof(spinor_OperationParamType));
            status = spinor_trans_write_async(&spinor_jobOperationCtx);
            if (SPINOR_DEVICE_DONE != status)
            {
                spinor_jobOperationCtx.jobOperationState.writememstate = WRITE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }
            break;
        }
        case SPINOR_JOB_OP_WRITE_REG:
        case SPINOR_JOB_OP_WRITE_REG_ADDR:
        case SPINOR_JOB_OP_READ_REG:
        case SPINOR_JOB_OP_READ_REG_ADDR:
        case SPINOR_JOB_OP_READ_SFDP:
        case SPINOR_JOB_OP_DEV_OP:
        case SPINOR_JOB_OP_BINARY_CMD:
        {
            spinor_jobOperationCtx.jobOperationState.spicmdstate = SPI_CMD_PENDING;
            spinor_jobSetOperationType(xJobType);
            sailbsp_memscpy(&spinor_jobOperationCtx.jobParams,sizeof(spinor_OperationParamType), xMemParams,sizeof(spinor_OperationParamType));
            status = spinor_trans_spicmd_async(&spinor_jobOperationCtx);
            if (SPINOR_DEVICE_DONE != status)
            {
                spinor_jobOperationCtx.jobOperationState.spicmdstate = SPI_CMD_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }
            break;
        }
        case SPINOR_JOB_OP_MAX:
        default:
            SPINOR_LOG_ERROR("%s: Error, invalid Job type, jobType = 0x%x \r\n", __func__, xJobType);
            return SPINOR_DEVICE_INVALID_PARAMETER;
            break;
    }

    return SPINOR_DEVICE_OK_NOT_DONE;
}

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
SPINOR_STATUS spinor_jobDispatcherSyncWrapper(spinor_JobOperationType xJobType, spinor_OperationParamType* xMemParams)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  status = spinor_jobDispatcher(SPINOR_JOB_MODE_ASYNC, xJobType, xMemParams);
  if (SPINOR_DEVICE_OK_NOT_DONE != status)
  {
    SPINOR_LOG_ERROR("%s: Error, Job Dispatch failed for jobType=%d, status = 0x%x \r\n", __func__, xJobType, status);
    return SPINOR_DEVICE_FAIL;
  }

  while (SPINOR_DEVICE_OK_NOT_DONE == status)
  {
    spinor_jobRunOperation();
    status = spinor_jobGetOperationStatus();
  }

  if (SPINOR_DEVICE_DONE != status)
  {
    status = SPINOR_DEVICE_FAIL;
  }

  return status;
}

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
void spinor_jobPrepareOperation(SPI_COMMAND_TYPE cmd_mode, uint32_t addr, uint8 *reg_value, uint32 len,uint8_t opcode)
{
    spinor_jobOperationCtx.CMDEngineParams.cmd_mode = cmd_mode;
    spinor_jobOperationCtx.CMDEngineParams.addr = addr;
    spinor_jobOperationCtx.CMDEngineParams.reg_value = reg_value;
    spinor_jobOperationCtx.CMDEngineParams.len = len;
    spinor_jobOperationCtx.CMDEngineParams.opcode = opcode;
}

/**********************************************************
 * Start the Job Operation.
 *
 * @param CMDEngineParams [IN]
 *   Command Engine Parameters to start the Job
 *
 * @return int [OUT]
 *   Status of the Operation
 **********************************************************/
SPINOR_STATUS spinor_jobStartOperation(SPINOR_CMDEngineParamType* CMDEngineParams)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;

    status = spinorCMDEngineStart(CMDEngineParams);
    if (SPINOR_DEVICE_DONE != status)
    {
        SPINOR_LOG_ERROR("%s: Error, Start command engine failed, status = 0x%x \r\n", __func__, status);
        return SPINOR_DEVICE_FAIL;
    }

    return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * Main function loop to run the Job Operation.
 *
 * @param void [IN]
 *
 * @return void [OUT]
 *
 **********************************************************/
void spinor_jobRunOperation(void)
{
    spinor_JobOperationType xJobOpType;
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    timetick_type_64 t2 = 0;

    /* Run Cmd engine */
    spinorCMDEngineRun();

    //get command engine result
    //based on the type of spinor_getJobOperationType, check for error or timeout, if idle trigger next job else done

    xJobOpType = spinor_jobGetOperationType();

    switch (xJobOpType)
    {
        case SPINOR_JOB_OP_ERASE_MEM:
        {
            status = spinor_trans_erase_async(&spinor_jobOperationCtx);
            if (status != SPINOR_DEVICE_DONE)
            {
                spinor_jobOperationCtx.jobOperationState.erasememstate = ERASE_OP_ERROR;
            }
            
            if(p_spinor_dev->disable_timeouts == 0)
            {
                t2 = timetick_get64();
                
                if ((elapsedtime_us(t2, spinor_jobOperationCtx.t1)) > p_spinor_dev->erase_timeout)
                {
                    spinor_jobOperationCtx.jobOperationState.erasememstate = ERASE_TIMEOUT_ERROR;
                }
            }

            break;
        }
        case SPINOR_JOB_OP_READ_MEM:
        {
            status = spinor_trans_read_async(&spinor_jobOperationCtx);
            if (status != SPINOR_DEVICE_DONE)
            {
                spinor_jobOperationCtx.jobOperationState.readmemstate = READ_OP_ERROR;
            }
            
            if(p_spinor_dev->disable_timeouts == 0)
            {
                t2 = timetick_get64();

                if ((elapsedtime_us(t2, spinor_jobOperationCtx.t1)) > p_spinor_dev->read_timeout)
                {
                    spinor_jobOperationCtx.jobOperationState.readmemstate = READ_TIMEOUT_ERROR;
                }
            }

            break;
        }
        case SPINOR_JOB_OP_WRITE_MEM:
        {
            status = spinor_trans_write_async(&spinor_jobOperationCtx);
            if (status != SPINOR_DEVICE_DONE)
            {
                spinor_jobOperationCtx.jobOperationState.writememstate = WRITE_OP_ERROR;
            }
            
            if(p_spinor_dev->disable_timeouts == 0)
            {
                t2 = timetick_get64();

                if ((elapsedtime_us(t2, spinor_jobOperationCtx.t1)) > p_spinor_dev->write_timeout)
                {
                    spinor_jobOperationCtx.jobOperationState.writememstate = WRITE_TIMEOUT_ERROR;
                }
            }

            break;
        }
        case SPINOR_JOB_OP_WRITE_REG:
        case SPINOR_JOB_OP_WRITE_REG_ADDR:
        case SPINOR_JOB_OP_READ_REG:
        case SPINOR_JOB_OP_READ_REG_ADDR:
        case SPINOR_JOB_OP_READ_SFDP:
        case SPINOR_JOB_OP_DEV_OP:
        case SPINOR_JOB_OP_BINARY_CMD:
        {
            status = spinor_trans_spicmd_async(&spinor_jobOperationCtx);
            if (status != SPINOR_DEVICE_DONE)
            {
                spinor_jobOperationCtx.jobOperationState.spicmdstate = SPI_CMD_OP_ERROR;
            }
            
            if(p_spinor_dev->disable_timeouts == 0)
            {
                t2 = timetick_get64();

                if ((elapsedtime_us(t2, spinor_jobOperationCtx.t1)) > p_spinor_dev->read_status_timeout)
                {
                    spinor_jobOperationCtx.jobOperationState.spicmdstate = SPI_CMD_TIMEOUT_ERROR;
                }
            }

            break;
        }
        default:
        {
            spinor_jobOperationCtx.jobOperationState.spicmdstate = SPI_CMD_OP_ERROR;
            SPINOR_LOG_ERROR("%s: Error, Invalid Operation Type, jobType = 0x%x \r\n", __func__, xJobOpType);
            break;
        }
    }
}

