/*
===========================================================================
*/
/**
    @file  spinor_transaction.c
    @brief This file provides definitions for the spinor transactions

*/
/*
    ===========================================================================

    Copyright (c) 2020-2024 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/driver/spinor_transaction.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "spinor_cm_defs.h"
#include "spinor_job.h"
#include "spinor_transaction.h"
#include "spinor_core.h"
#include "spinor_dma_pio.h"
#include "debug_log.h"
#include "boot_logger.h"
#include "spinor_diag.h"
#include "common_functions.h"
#include "spinor_utils.h"

#ifdef NORPVL_ENB
extern uint32_t spinor_thead_delay_us;
extern uint32_t spinor_thread_chunk_size;
#endif

#define MAX_READSIZE_PER_DMA (((DMA_MAX_DESCRIPTORS-4) * DMA_MAX_TRSFR_LEN_PER_DESCRIPTOR))

/**********************************************************
 * Main function loop for Read Transaction.
 *
 * @param Ctx [IN/OUT]
 *   Context for the Job
 *
 * @return int [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_trans_read_async(void *Ctx)
{
    boolean split_read_enabled = FALSE;
    boolean crc_status = FALSE;
    uint32 max_transfer_size = 0;
    uint32 transfer_size = 0;
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinor_JobOperationCtxType *JobCtx;

    JobCtx = (spinor_JobOperationCtxType *)Ctx;

#ifdef SPINOR_CRC_ENABLE
    crc_status = GetCRCFlag();
    if((p_spinor_dev->enable_crc == TRUE) && (crc_status == TRUE))
    {
      /* Max_transfer_size reduced to 256 when CRC is enabled */
      max_transfer_size = PAGE_SIZE_IN_BYTES;
    }
    else
#else
    {
      /* The max transfer size is the maximum amount of reads that can be accommodated in the DMA descriptors. */
      max_transfer_size = MAX_READSIZE_PER_DMA;
    }
#endif

    /* Check if split reads are needed */
    if ((TRUE == p_spinor_dev->dll_config_en) && (SPI_TRANSFER_DTR == p_spinor_dev->config_data->device_transfer_rate) && (FALSE == p_spinor_dev->config_data->dqs_sync_qspi_clk))
    {
        split_read_enabled = TRUE;
    }
    else
    {
        split_read_enabled = FALSE;
    }

    switch (JobCtx->jobOperationState.readmemstate)
    {
        case READ_PENDING:
        {
            /* If split read is needed, change the size of the transfer to reduce 2 bytes. Split read contents will be taken care outside of this size */
            if (TRUE == split_read_enabled)
            {
                JobCtx->jobParams.len = JobCtx->jobParams.len - 2;
                if (JobCtx->jobParams.len==0)
                {
                    goto splitread;
                }
            }

            /* Transfer size per iteration */
            transfer_size = (JobCtx->jobParams.len > max_transfer_size)? max_transfer_size : JobCtx->jobParams.len;

            /* Prepare the command for the command engine */
            /* Start with the Write Enable command */
            spinor_jobPrepareOperation(OSPI_READ_MODE, JobCtx->jobParams.addr, JobCtx->jobParams.buffer, transfer_size, 0);

            /* Obtain transaction start timetick */
            JobCtx->t1 = timetick_get64();

            /* Start the job operation and command Engine */
            status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
            if (SPINOR_DEVICE_DONE != status)
            {
                JobCtx->jobOperationState.readmemstate = READ_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }

            JobCtx->jobParams.addr += transfer_size;
            JobCtx->jobParams.buffer += transfer_size;
            JobCtx->jobParams.len -= transfer_size;

            JobCtx->jobOperationState.readmemstate = READ_SND_READ_CMD;
            break;
        }

        case READ_SND_READ_CMD:
        {
            SPINOR_CMDEngineStatusType eCmdEngineStatus;
            eCmdEngineStatus = spinorCMDEngineGetState();
            uint8 len;

            if(p_spinor_dev->perfmode_enabled == FALSE)
                len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
            else
                len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;

            if ((SPINOR_CMD_ENGINE_FLUSH_TIMEOUT == eCmdEngineStatus) || (SPINOR_CMD_ENGINE_ERROR == eCmdEngineStatus) || (SPINOR_CMD_ENGINE_FLUSH_ERROR == eCmdEngineStatus))
            {
                /* Engine timeout or error */
                JobCtx->jobOperationState.readmemstate = READ_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }

            if (SPINOR_CMD_ENGINE_IDLE != eCmdEngineStatus)
            {
                /* Engine busy still */
                return SPINOR_DEVICE_DONE;
            }

            /* If ECC CRC enabled, check for the status */
            if ((p_spinor_dev->config_data->ecc_info.ecc_supported == TRUE) && (p_spinor_dev->ecc_enabled_status_local == TRUE))
            {
#ifdef SPINOR_ECC_ENABLE
                /* Read the ECC register */
                spinor_jobPrepareOperation(OSPI_REGISTER_READ, 0, (uint8 *)&JobCtx->sparereadbuffer, len, READ_STATUS_CMD);

                /* Start the job operation and command Engine */
                status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
                if (SPINOR_DEVICE_DONE != status)
                {
                    JobCtx->jobOperationState.readmemstate = READ_OP_ERROR;
                    return SPINOR_DEVICE_FAIL;
                }

                /* next state is check ECC */
                JobCtx->jobOperationState.readmemstate = READ_RD_ECC_ERR_STATUS;
#endif
            }
            else if ((p_spinor_dev->config_data->crc_info.crc_supported == TRUE) && (crc_status == TRUE))
            {
#ifdef SPINOR_CRC_ENABLE
                /* next state is check CRC */
                JobCtx->jobOperationState.readmemstate = READ_RD_CRC_ERR_STATUS;
#endif
            }
            else if (JobCtx->jobParams.len>0)
            {
                /* Check for more data to read */
                transfer_size = (JobCtx->jobParams.len > max_transfer_size)? max_transfer_size : JobCtx->jobParams.len;

                /* Prepare the command for the command engine */
                /* Start with the Write Enable command */
                spinor_jobPrepareOperation(OSPI_READ_MODE, JobCtx->jobParams.addr, JobCtx->jobParams.buffer, transfer_size, 0);

                /* Obtain transaction start timetick */
                JobCtx->t1 = timetick_get64();

                /* Start the job operation and command Engine */
                status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
                if (SPINOR_DEVICE_DONE != status)
                {
                    JobCtx->jobOperationState.readmemstate = READ_OP_ERROR;
                    return SPINOR_DEVICE_FAIL;
                }

                JobCtx->jobParams.addr += transfer_size;
                JobCtx->jobParams.buffer += transfer_size;
                JobCtx->jobParams.len -= transfer_size;

                JobCtx->jobOperationState.readmemstate = READ_SND_READ_CMD;
                break;
            }
            else
            {
splitread:
                if (TRUE == split_read_enabled)
                {
                    transfer_size = 2;

                    /* Prepare the command for the command engine */
                    /* Start with the Write Enable command */
                    spinor_jobPrepareOperation(OSPI_READ_MODE, JobCtx->jobParams.addr, (uint8*)&JobCtx->extrareadbuffer, transfer_size , 0);

                    /* Obtain transaction start timetick */
                    JobCtx->t1 = timetick_get64();

                    /* Start the job operation and command Engine */
                    status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
                    if (SPINOR_DEVICE_DONE != status)
                    {
                        JobCtx->jobOperationState.readmemstate = READ_OP_ERROR;
                        return SPINOR_DEVICE_FAIL;
                    }

                    JobCtx->jobOperationState.readmemstate = READ_SEND_SPLITREAD_CMD;
                }
                else
                {
                    JobCtx->jobOperationState.readmemstate = READ_OP_DONE;
                }
            }
            break;
        }

        case READ_RD_ECC_ERR_STATUS:
        case READ_RD_ECC_ERR_ADDR:
        case READ_RD_CRC_ERR_STATUS:
            break;

        case READ_SEND_SPLITREAD_CMD:
        {
            SPINOR_CMDEngineStatusType eCmdEngineStatus;
            eCmdEngineStatus = spinorCMDEngineGetState();
            uint8 len;

            if(p_spinor_dev->perfmode_enabled == FALSE)
                len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
            else
                len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;

            if ((SPINOR_CMD_ENGINE_FLUSH_TIMEOUT == eCmdEngineStatus) || (SPINOR_CMD_ENGINE_ERROR == eCmdEngineStatus)  || (SPINOR_CMD_ENGINE_FLUSH_ERROR == eCmdEngineStatus))
            {
                /* Engine timeout or error */
                JobCtx->jobOperationState.readmemstate = READ_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }

            if (SPINOR_CMD_ENGINE_IDLE != eCmdEngineStatus)
            {
                /* Engine busy still */
                return SPINOR_DEVICE_DONE;
            }

            /* If ECC CRC enabled, check for the status */
            if ((p_spinor_dev->config_data->ecc_info.ecc_supported == TRUE) && (p_spinor_dev->ecc_enabled_status_local == TRUE))
            {
                /* Read the ECC register */
                spinor_jobPrepareOperation(OSPI_REGISTER_READ, 0, (uint8 *)&JobCtx->sparereadbuffer, len, READ_STATUS_CMD);

                /* Start the job operation and command Engine */
                status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
                if (SPINOR_DEVICE_DONE != status)
                {
                    JobCtx->jobOperationState.readmemstate = READ_OP_ERROR;
                    return SPINOR_DEVICE_FAIL;
                }

                /* next state is check ECC */
                JobCtx->jobOperationState.readmemstate = READ_RD_ECC_ERR_STATUS1;
            }
            else if ((p_spinor_dev->config_data->crc_info.crc_supported == TRUE) && (crc_status == TRUE))
            {
                /* next state is check CRC */
                JobCtx->jobOperationState.readmemstate = READ_RD_CRC_ERR_STATUS1;
            }
            else
            {
                JobCtx->jobOperationState.readmemstate = READ_COPY_SPLIT_CONTENTS;

                size_t result = sailbsp_memscpy(JobCtx->jobParams.buffer, 2*sizeof(uint8), (uint8 *)&JobCtx->extrareadbuffer, 2*sizeof(uint8));
                if(result == 0)
                {
                    status = SPINOR_DEVICE_FAIL;
                    spinor_log (&p_spinor_dev->debug_log, 0xA00);
                    SPINOR_LOG_ERROR("%s: Error, memscpy failed \r\n", __func__);
                    return status;
                }

                JobCtx->jobOperationState.readmemstate = READ_OP_DONE;
            }
            break;
        }

        case READ_RD_ECC_ERR_STATUS1:
        case READ_RD_ECC_ERR_ADDR1:
        case READ_RD_CRC_ERR_STATUS1:
        case READ_OP_DONE:
            break;


        case READ_OP_ERROR:
        case READ_OP_ECC_ERROR:
        case READ_OP_CRC_ERROR:
        {
            SPINOR_LOG_INFO("%s: Read Error State , Nothing to do \r\n", __func__);
            break;
        }

        case READ_TIMEOUT_ERROR:
        {
            SPINOR_LOG_INFO("%s: Read Timeout Error State , Nothing to do \r\n", __func__);
            break;
        }

        default:
        {
            spinor_log (&p_spinor_dev->debug_log, 0xA01);
            SPINOR_LOG_ERROR("%s: Error, Invalid Read state \r\n", __func__);
            return SPINOR_DEVICE_FAIL;
            break;
        }
    }

#ifdef SPINOR_PROFILE_ENABLED
  p_spinor_dev->profiling_time.spinor_core_read_time = vBootLogger_LogDeltaTime(p_spinor_dev->profiling_time.spinor_core_read_time, "SPINOR read END time \r\n");
#endif /* SPINOR_PROFILE_ENABLED */

spinor_core_read_end:
  return status;
}

/**********************************************************
 * Main function loop for Write Transaction.
 *
 * @param Ctx [IN/OUT]
 *   Context for the Job
 *
 * @return int [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_trans_write_async(void *Ctx)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinor_JobOperationCtxType *JobCtx;

    JobCtx = (spinor_JobOperationCtxType *)Ctx;

    switch (JobCtx->jobOperationState.writememstate)
    {
        case WRITE_PENDING:
        {
            /* Prepare the command for the command engine */
            /* Start with the Write Enable command */

            spinor_jobPrepareOperation(OSPI_DEVICE_OP_MODE, 0, (uint8*)&JobCtx->sparereadbuffer, 0, WRITE_ENABLE_CMD);

            /* Obtain transaction start timetick */
            JobCtx->t1 = timetick_get64();

            /* Start the job operation and command Engine */
            status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
            if (SPINOR_DEVICE_DONE != status)
            {
                JobCtx->jobOperationState.writememstate = WRITE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }
            JobCtx->jobOperationState.writememstate = WRITE_SND_WR_EN_CMD;
            break;
        }
        case WRITE_SND_WR_EN_CMD:
        {
            SPINOR_CMDEngineStatusType eCmdEngineStatus;
            eCmdEngineStatus = spinorCMDEngineGetState();
            uint8 len;

            if ((SPINOR_CMD_ENGINE_FLUSH_TIMEOUT == eCmdEngineStatus) || (SPINOR_CMD_ENGINE_ERROR == eCmdEngineStatus)  || (SPINOR_CMD_ENGINE_FLUSH_ERROR == eCmdEngineStatus))
            {
                /* Engine timeout or error */
                JobCtx->jobOperationState.writememstate = WRITE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }

            if (SPINOR_CMD_ENGINE_IDLE != eCmdEngineStatus)
            {
                /* Engine busy still */
                return SPINOR_DEVICE_DONE;
            }

            /* After the write enable command read the Write enable latch */
            if(p_spinor_dev->perfmode_enabled == FALSE)
                len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
            else
                len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;

            /* Read the write enable latch command */
            spinor_jobPrepareOperation(OSPI_REGISTER_READ, 0, (uint8 *)&JobCtx->sparereadbuffer, len, READ_STATUS_CMD);

            /* Start the job operation and command Engine */
            status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
            if (SPINOR_DEVICE_DONE != status)
            {
                JobCtx->jobOperationState.writememstate = WRITE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }
            JobCtx->jobOperationState.writememstate = WRITE_RD_WR_EN_LATCH;
            break;
        }
        case WRITE_RD_WR_EN_LATCH:
        {
            SPINOR_CMDEngineStatusType eCmdEngineStatus;
            eCmdEngineStatus = spinorCMDEngineGetState();
            uint8 len;

            if ((SPINOR_CMD_ENGINE_FLUSH_TIMEOUT == eCmdEngineStatus) || (SPINOR_CMD_ENGINE_ERROR == eCmdEngineStatus)  || (SPINOR_CMD_ENGINE_FLUSH_ERROR == eCmdEngineStatus))
            {
                /* Engine timeout or error */
                JobCtx->jobOperationState.writememstate = WRITE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }

            if (SPINOR_CMD_ENGINE_IDLE != eCmdEngineStatus)
            {
                /* Engine busy still */
                return SPINOR_DEVICE_DONE;

            }

            /* Read completed here. Check the value */
            if(!((uint8)JobCtx->sparereadbuffer & STATUS_WR_EN_MASK))
            {
                if(p_spinor_dev->perfmode_enabled == FALSE)
                    len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
                else
                    len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;

                /* Write enable latch not set. Read the write enable latch command register again*/
                spinor_jobPrepareOperation(OSPI_REGISTER_READ, 0, (uint8*)&JobCtx->sparereadbuffer, len, READ_STATUS_CMD);

                /* Start the job operation and command Engine */
                status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
                if (SPINOR_DEVICE_DONE != status)
                {
                    JobCtx->jobOperationState.writememstate = WRITE_OP_ERROR;
                    return SPINOR_DEVICE_FAIL;
                }
                JobCtx->jobOperationState.writememstate = WRITE_RD_WR_EN_LATCH;
            }
            else
            {
                uint32 limit = p_spinor_dev->config_data->page_size_in_bytes;
                uint32 transfer_size = 0;
                JobCtx->sparereadbuffer = 0;

                /* In case the start address is not on page boundary, we write from the */
                /* start address to the end of the page as a separate write transaction */
                if (JobCtx->jobParams.addr % p_spinor_dev->config_data->page_size_in_bytes)
                {
                  transfer_size = p_spinor_dev->config_data->page_size_in_bytes - (JobCtx->jobParams.addr % p_spinor_dev->config_data->page_size_in_bytes);
                  if (transfer_size > JobCtx->jobParams.len)
                  {
                    transfer_size = JobCtx->jobParams.len;
                  }
                }
                else
                {
                  transfer_size = (JobCtx->jobParams.len > limit) ? (limit) : (JobCtx->jobParams.len);
                }

                /* Write enable latch successful. move to next state to send write command */
                spinor_jobPrepareOperation(OSPI_WRITE_MODE, JobCtx->jobParams.addr, JobCtx->jobParams.buffer, transfer_size, 0);

                /* Start the job operation and command Engine */
                status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
                if (SPINOR_DEVICE_DONE != status)
                {
                    JobCtx->jobOperationState.writememstate = WRITE_OP_ERROR;
                    return SPINOR_DEVICE_FAIL;
                }

                JobCtx->jobParams.addr += transfer_size;
                JobCtx->jobParams.buffer += transfer_size;
                JobCtx->jobParams.len -= transfer_size;
                JobCtx->jobOperationState.writememstate = WRITE_SND_WRITE_CMD;
            }
            break;
        }
        case WRITE_SND_WRITE_CMD:
        {
            SPINOR_CMDEngineStatusType eCmdEngineStatus;
            eCmdEngineStatus = spinorCMDEngineGetState();
            uint8 len;

            if ((SPINOR_CMD_ENGINE_FLUSH_TIMEOUT == eCmdEngineStatus) || (SPINOR_CMD_ENGINE_ERROR == eCmdEngineStatus)  || (SPINOR_CMD_ENGINE_FLUSH_ERROR == eCmdEngineStatus))
            {
                /* Engine timeout or error */
                JobCtx->jobOperationState.writememstate = WRITE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }

            if (SPINOR_CMD_ENGINE_IDLE != eCmdEngineStatus)
            {
                /* Engine busy still */
                return SPINOR_DEVICE_DONE;

            }

            /* After the write command read the Program Erase busy */
            if(p_spinor_dev->perfmode_enabled == FALSE)
                len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
            else
                len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;

            /* Read the Status register for Program Erase busy */
            spinor_jobPrepareOperation(OSPI_REGISTER_READ, 0, (uint8 *)&JobCtx->sparereadbuffer, len, READ_STATUS_CMD);

            /* Start the job operation and command Engine */
            status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
            if (SPINOR_DEVICE_DONE != status)
            {
                JobCtx->jobOperationState.writememstate = WRITE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }
            JobCtx->jobOperationState.writememstate = WRITE_RD_PE_WR_BUSY_STATUS;
            break;
        }
        case WRITE_RD_PE_WR_BUSY_STATUS:
        {
            SPINOR_CMDEngineStatusType eCmdEngineStatus;
            eCmdEngineStatus = spinorCMDEngineGetState();
            uint8 len;

            if(p_spinor_dev->perfmode_enabled == FALSE)
                len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
            else
                len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;

            if ((SPINOR_CMD_ENGINE_FLUSH_TIMEOUT == eCmdEngineStatus) || (SPINOR_CMD_ENGINE_ERROR == eCmdEngineStatus)  || (SPINOR_CMD_ENGINE_FLUSH_ERROR == eCmdEngineStatus))
            {
                /* Engine timeout or error */
                JobCtx->jobOperationState.writememstate = WRITE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }

            if (SPINOR_CMD_ENGINE_IDLE != eCmdEngineStatus)
            {
                /* Engine busy still */
                return SPINOR_DEVICE_DONE;

            }

            /* Read completed here. Check the value */
            if (!(((uint8)JobCtx->sparereadbuffer & PROG_ERASE_WRITE_BUSY_BMSK) == 0))
            {
                /* Write not completed. Read the register again*/
                spinor_jobPrepareOperation(OSPI_REGISTER_READ, 0, (uint8*)&JobCtx->sparereadbuffer, len, READ_STATUS_CMD);

                /* Start the job operation and command Engine */
                status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
                if (SPINOR_DEVICE_DONE != status)
                {
                    JobCtx->jobOperationState.writememstate = WRITE_OP_ERROR;
                    return SPINOR_DEVICE_FAIL;
                }
                JobCtx->jobOperationState.writememstate = WRITE_RD_PE_WR_BUSY_STATUS;
            }
            else
            {
                JobCtx->sparereadbuffer = 0;
                uint8 err_status_register = p_spinor_dev->config_data->write_err_status_reg;
                /* Write busy is 0. move to next state to check the vendor error write  */
                spinor_jobPrepareOperation(OSPI_REGISTER_READ, 0, (uint8 *)&JobCtx->sparereadbuffer, len, err_status_register);

                /* Start the job operation and command Engine */
                status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
                if (SPINOR_DEVICE_DONE != status)
                {
                    JobCtx->jobOperationState.writememstate = WRITE_OP_ERROR;
                    return SPINOR_DEVICE_FAIL;
                }
                JobCtx->jobOperationState.writememstate = WRITE_RD_VENDOR_ERR_STATUS;
            }
            break;
        }
        case WRITE_RD_VENDOR_ERR_STATUS:
        {
            SPINOR_CMDEngineStatusType eCmdEngineStatus;
            eCmdEngineStatus = spinorCMDEngineGetState();
            uint8 len;

            bool crc_status = FALSE;
#ifdef SPINOR_CRC_ENABLE
            crc_status = GetCRCFlag();
#endif

            if(p_spinor_dev->perfmode_enabled == FALSE)
                len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
            else
                len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;

            if ((SPINOR_CMD_ENGINE_FLUSH_TIMEOUT == eCmdEngineStatus) || (SPINOR_CMD_ENGINE_ERROR == eCmdEngineStatus)  || (SPINOR_CMD_ENGINE_FLUSH_ERROR == eCmdEngineStatus))
            {
                /* Engine timeout or error */
                JobCtx->jobOperationState.writememstate = WRITE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }

            if (SPINOR_CMD_ENGINE_IDLE != eCmdEngineStatus)
            {
                /* Engine busy still */
                return SPINOR_DEVICE_DONE;

            }

            /* Read completed here. check for error */
            if (((uint8)JobCtx->sparereadbuffer & p_spinor_dev->config_data->write_err_bmsk))
            {
                /* Error in Erase operation */
                JobCtx->jobOperationState.writememstate = WRITE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }

            /* If ECC CRC enabled, check for the status */
            if ((p_spinor_dev->config_data->ecc_info.ecc_supported == TRUE) && (p_spinor_dev->ecc_enabled_status_local == TRUE))
            {
#ifdef SPINOR_ECC_ENABLE
                /* Read the ECC register */
                spinor_jobPrepareOperation(OSPI_REGISTER_READ, 0, (uint8 *)&JobCtx->sparereadbuffer, len, READ_STATUS_CMD);

                /* Start the job operation and command Engine */
                status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
                if (SPINOR_DEVICE_DONE != status)
                {
                    JobCtx->jobOperationState.writememstate = WRITE_OP_ERROR;
                    return SPINOR_DEVICE_FAIL;
                }

                /* next state is check ECC */
                JobCtx->jobOperationState.writememstate = WRITE_RD_ECC_ERR_STATUS;
#endif
            }
            else if ((p_spinor_dev->config_data->crc_info.crc_supported == TRUE) && (crc_status == TRUE))
            {
#ifdef SPINOR_CRC_ENABLE
                /* next state is check CRC */
                JobCtx->jobOperationState.writememstate = WRITE_RD_CRC_ERR_STATUS;
#endif
            }
            else
            {
                if (JobCtx->jobParams.len>0)
                {
                    JobCtx->jobOperationState.writememstate = WRITE_PENDING;
                }
                else
                {
                    JobCtx->jobOperationState.writememstate = WRITE_OP_DONE;
                }
            }
            break;
        }

        case WRITE_RD_ECC_ERR_STATUS:
        case WRITE_RD_ECC_ERR_ADDR:
        case WRITE_RD_CRC_ERR_STATUS:
        case WRITE_OP_DONE:
            break;

        case WRITE_OP_ERROR:
        case WRITE_OP_ECC_ERROR:
        case WRITE_OP_CRC_ERROR:
        {
            SPINOR_LOG_INFO("%s: Write Error State , Nothing to do \r\n", __func__);
            break;
        }

        case WRITE_TIMEOUT_ERROR:
        {
            SPINOR_LOG_INFO("%s: Write Timeout Error State , Nothing to do \r\n", __func__);
            break;
        }

        default:
        {
            SPINOR_LOG_ERROR("%s: Error, Invalid Write state \r\n", __func__);
            spinor_log (&p_spinor_dev->debug_log, 0xA02);
            return SPINOR_DEVICE_FAIL;
            break;
        }
    }

#ifdef SPINOR_PROFILE_ENABLED
  p_spinor_dev->profiling_time.spinor_core_write_time = vBootLogger_LogDeltaTime(p_spinor_dev->profiling_time.spinor_core_write_time, "SPINOR write END time \r\n");
#endif /* SPINOR_PROFILE_ENABLED */

  status = SPINOR_DEVICE_DONE;

spinor_core_write_end:
  return status;
}

/**********************************************************
 * Main function loop for SPI CMD Transaction.
 *
 * @param Ctx [IN/OUT]
 *   Context for the Job
 *
 * @return int [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_trans_spicmd_async(void *Ctx)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinor_JobOperationCtxType *JobCtx;
    spinor_JobOperationType xJobOpType;

    JobCtx = (spinor_JobOperationCtxType *)Ctx;

    xJobOpType = JobCtx->jobType; //spinor_getJobOperationType();

    switch (JobCtx->jobOperationState.spicmdstate)
    {
        case SPI_CMD_PENDING:
        {
            SPI_COMMAND_TYPE cmd_mode;

            if (SPINOR_JOB_OP_WRITE_REG == xJobOpType)
            {
                cmd_mode = OSPI_REGISTER_WRITE;
            }
            else if (SPINOR_JOB_OP_WRITE_REG_ADDR == xJobOpType)
            {
                cmd_mode = OSPI_REGISTER_WRITE_ADDR;
            }
            else if (SPINOR_JOB_OP_READ_REG == xJobOpType)
            {
                cmd_mode = OSPI_REGISTER_READ;
            }
            else if (SPINOR_JOB_OP_READ_REG_ADDR == xJobOpType)
            {
                cmd_mode = OSPI_REGISTER_READ_ADDR;
            }
            else if (SPINOR_JOB_OP_READ_SFDP == xJobOpType)
            {
                cmd_mode = OSPI_READ_SFDP_MODE;
            }
            else if (SPINOR_JOB_OP_DEV_OP == xJobOpType)
            {
                cmd_mode = OSPI_DEVICE_OP_MODE;
            }
            else if (SPINOR_JOB_OP_BINARY_CMD == xJobOpType)
            {
                spinor_cmd_set_bin_cmd_params(JobCtx->jobParams.dummy_cycle, JobCtx->jobParams.len, JobCtx->jobParams.num_addr_bytes, JobCtx->jobParams.is_write_operation, JobCtx->jobParams.use_dma);
                cmd_mode = OSPI_BIN_CMD_MODE;
            }
            else
            {
                JobCtx->jobOperationState.spicmdstate = SPI_CMD_OP_ERROR;
                spinor_log (&p_spinor_dev->debug_log, 0xA03);
                SPINOR_LOG_ERROR("%s: Error, Unsupported Operation Type \r\n", __func__);
                return SPINOR_DEVICE_FAIL;
            }

            /* Prepare the command for the command engine */
            /* Start with the commands received */
            spinor_jobPrepareOperation(cmd_mode, JobCtx->jobParams.addr, JobCtx->jobParams.buffer, JobCtx->jobParams.len, JobCtx->jobParams.opcode);

            /* Obtain transaction start timetick */
            JobCtx->t1 = timetick_get64();

            /* Start the job operation and command Engine */
            status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
            if (SPINOR_DEVICE_DONE != status)
            {
                spinor_cmd_clear_bin_cmd_params();
                JobCtx->jobOperationState.spicmdstate = SPI_CMD_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }
            JobCtx->jobOperationState.spicmdstate = SPI_SND_SPI_CMD;
            break;
        }
        case SPI_SND_SPI_CMD:
        {
            SPINOR_CMDEngineStatusType eCmdEngineStatus;
            eCmdEngineStatus = spinorCMDEngineGetState();

            if ((SPINOR_CMD_ENGINE_FLUSH_TIMEOUT == eCmdEngineStatus) || (SPINOR_CMD_ENGINE_ERROR == eCmdEngineStatus)  || (SPINOR_CMD_ENGINE_FLUSH_ERROR == eCmdEngineStatus))
            {
                spinor_cmd_clear_bin_cmd_params();
                /* Engine timeout or error */
                JobCtx->jobOperationState.spicmdstate = SPI_CMD_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }

            if (SPINOR_CMD_ENGINE_IDLE != eCmdEngineStatus)
            {
                /* Engine busy still */
                return SPINOR_DEVICE_DONE;
            }
            else
            {
                spinor_cmd_clear_bin_cmd_params();
                JobCtx->jobOperationState.spicmdstate = SPI_CMD_OP_DONE;
            }
            break;
        }

        case SPI_CMD_OP_DONE:
            if (SPINOR_JOB_OP_BINARY_CMD == xJobOpType)
            {
                spinor_cmd_clear_bin_cmd_params();
            }
            break;

        case SPI_CMD_OP_ERROR:
        {
            spinor_cmd_clear_bin_cmd_params();
            SPINOR_LOG_INFO("%s: SPI CMD Error State , Nothing to do \r\n", __func__);
            break;
        }

        case SPI_CMD_TIMEOUT_ERROR:
        {
            SPINOR_LOG_INFO("%s: SPI CMD Timeout Error State , Nothing to do \r\n", __func__);
            break;
        }

        default:
        {
            spinor_log (&p_spinor_dev->debug_log, 0xA04);
            SPINOR_LOG_ERROR("%s: Error, Invalid SPI CMD state \r\n", __func__);
            return SPINOR_DEVICE_FAIL;
            break;
        }
    }

  return status;
}

/**********************************************************
 * Main function loop for Erase Transaction.
 *
 * @param Ctx [IN/OUT]
 *   Context for the Job
 *
 * @return int [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_trans_erase_async(void *Ctx)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinor_JobOperationCtxType *JobCtx;
    spinor_getnum4kblockType blockInfo = {0};
    uint32_t blocks_erased =0;

    JobCtx = (spinor_JobOperationCtxType *)Ctx;

    switch (JobCtx->jobOperationState.erasememstate)
    {
        case ERASE_PENDING:
        {
            /* Prepare the command for the command engine */
            /* Start with the Write Enable command */
            spinor_jobPrepareOperation(OSPI_DEVICE_OP_MODE, 0, (uint8*)&JobCtx->sparereadbuffer, 0, WRITE_ENABLE_CMD);

            /* Obtain transaction start timetick */
            JobCtx->t1 = timetick_get64();

            /* Start the job operation and command Engine */
            status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
            if (SPINOR_DEVICE_DONE != status)
            {
                JobCtx->jobOperationState.erasememstate = ERASE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }
            JobCtx->jobOperationState.erasememstate = ERASE_SND_WR_EN_CMD;
            break;
        }

        case ERASE_SND_WR_EN_CMD:
        {
            SPINOR_CMDEngineStatusType eCmdEngineStatus;
            eCmdEngineStatus = spinorCMDEngineGetState();
            uint8 len;

            if ((SPINOR_CMD_ENGINE_FLUSH_TIMEOUT == eCmdEngineStatus) || (SPINOR_CMD_ENGINE_ERROR == eCmdEngineStatus)  || (SPINOR_CMD_ENGINE_FLUSH_ERROR == eCmdEngineStatus))
            {
                /* Engine timeout or error */
                JobCtx->jobOperationState.erasememstate = ERASE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }

            if (SPINOR_CMD_ENGINE_IDLE != eCmdEngineStatus)
            {
                /* Engine busy still */
                return SPINOR_DEVICE_DONE;
            }

            /* After the write enable command read the Write enable latch */
            if(p_spinor_dev->perfmode_enabled == FALSE)
                len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
            else
                len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;

            /* Read the write enable latch command */
            spinor_jobPrepareOperation(OSPI_REGISTER_READ, 0, (uint8*)&JobCtx->sparereadbuffer, len, READ_STATUS_CMD);

            /* Start the job operation and command Engine */
            status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
            if (SPINOR_DEVICE_DONE != status)
            {
                JobCtx->jobOperationState.erasememstate = ERASE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }
            JobCtx->jobOperationState.erasememstate = ERASE_RD_WR_EN_LATCH;
            break;
        }
        case ERASE_RD_WR_EN_LATCH:
        {
            SPINOR_CMDEngineStatusType eCmdEngineStatus;
            eCmdEngineStatus = spinorCMDEngineGetState();
            uint8 len;

            if ((SPINOR_CMD_ENGINE_FLUSH_TIMEOUT == eCmdEngineStatus) || (SPINOR_CMD_ENGINE_ERROR == eCmdEngineStatus)  || (SPINOR_CMD_ENGINE_FLUSH_ERROR == eCmdEngineStatus))
            {
                /* Engine timeout or error */
                JobCtx->jobOperationState.erasememstate = ERASE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }

            if (SPINOR_CMD_ENGINE_IDLE != eCmdEngineStatus)
            {
                /* Engine busy still */
                return SPINOR_DEVICE_DONE;

            }

            /* Read completed here. Check the value */
            if(!((uint8)JobCtx->sparereadbuffer & STATUS_WR_EN_MASK))
            {
                if(p_spinor_dev->perfmode_enabled == FALSE)
                    len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
                else
                    len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;

                /* Write enable latch not set. Read the write enable latch command register again*/
                spinor_jobPrepareOperation(OSPI_REGISTER_READ, 0, (uint8 *)&JobCtx->sparereadbuffer, len, READ_STATUS_CMD);

                /* Start the job operation and command Engine */
                status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
                if (SPINOR_DEVICE_DONE != status)
                {
                    JobCtx->jobOperationState.erasememstate = ERASE_OP_ERROR;
                    return SPINOR_DEVICE_FAIL;
                }
                JobCtx->jobOperationState.erasememstate = ERASE_RD_WR_EN_LATCH;
            }
            else
            {
                JobCtx->sparereadbuffer = 0;
                /* Write enable latch successful. move to next state to send erase command */
                spinor_jobPrepareOperation(OSPI_ERASE_MODE, JobCtx->jobParams.addr, (uint8 *)&JobCtx->sparereadbuffer, 0, 0);

                /* Start the job operation and command Engine */
                status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
                if (SPINOR_DEVICE_DONE != status)
                {
                    JobCtx->jobOperationState.erasememstate = ERASE_OP_ERROR;
                    return SPINOR_DEVICE_FAIL;
                }
                JobCtx->jobOperationState.erasememstate = ERASE_SND_ERASE_CMD;
            }
            break;
        }
        case ERASE_SND_ERASE_CMD:
        {
            SPINOR_CMDEngineStatusType eCmdEngineStatus;
            eCmdEngineStatus = spinorCMDEngineGetState();
            uint8 len;

            if ((SPINOR_CMD_ENGINE_FLUSH_TIMEOUT == eCmdEngineStatus) || (SPINOR_CMD_ENGINE_ERROR == eCmdEngineStatus)  || (SPINOR_CMD_ENGINE_FLUSH_ERROR == eCmdEngineStatus))
            {
                /* Engine timeout or error */
                JobCtx->jobOperationState.erasememstate = ERASE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }

            if (SPINOR_CMD_ENGINE_IDLE != eCmdEngineStatus)
            {
                /* Engine busy still */
                return SPINOR_DEVICE_DONE;

            }


            /* After the Erase read the Proram Erase status */
            if(p_spinor_dev->perfmode_enabled == FALSE)
                len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
            else
                len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;

            /* Read the status register command */
            spinor_jobPrepareOperation(OSPI_REGISTER_READ, 0, (uint8*)&JobCtx->sparereadbuffer, len, READ_STATUS_CMD);

            /* Start the job operation and command Engine */
            status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
            if (SPINOR_DEVICE_DONE != status)
            {
                JobCtx->jobOperationState.erasememstate = ERASE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }
            JobCtx->jobOperationState.erasememstate = ERASE_RD_PE_WR_BUSY_STATUS;
            break;
        }
        case ERASE_RD_PE_WR_BUSY_STATUS:
        {
            SPINOR_CMDEngineStatusType eCmdEngineStatus;
            eCmdEngineStatus = spinorCMDEngineGetState();
            uint8 len;

            if(p_spinor_dev->perfmode_enabled == FALSE)
                len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
            else
                len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;

            if ((SPINOR_CMD_ENGINE_FLUSH_TIMEOUT == eCmdEngineStatus) || (SPINOR_CMD_ENGINE_ERROR == eCmdEngineStatus)  || (SPINOR_CMD_ENGINE_FLUSH_ERROR == eCmdEngineStatus))
            {
                /* Engine timeout or error */
                JobCtx->jobOperationState.erasememstate = ERASE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }

            if (SPINOR_CMD_ENGINE_IDLE != eCmdEngineStatus)
            {
                /* Engine busy still */
                return SPINOR_DEVICE_DONE;

            }

            /* Read completed here. Check the value */
            if (!(((uint8)JobCtx->sparereadbuffer & PROG_ERASE_WRITE_BUSY_BMSK) == 0))
            {
                /* Erase not completed. Read the register again*/
                spinor_jobPrepareOperation(OSPI_REGISTER_READ, 0, (uint8*)&JobCtx->sparereadbuffer, len, READ_STATUS_CMD);

                /* Start the job operation and command Engine */
                status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
                if (SPINOR_DEVICE_DONE != status)
                {
                    JobCtx->jobOperationState.erasememstate = ERASE_OP_ERROR;
                    return SPINOR_DEVICE_FAIL;
                }
                JobCtx->jobOperationState.erasememstate = ERASE_RD_PE_WR_BUSY_STATUS;
            }
            else
            {

                JobCtx->sparereadbuffer = 0;
                uint8 err_status_register = p_spinor_dev->config_data->erase_err_status_reg;
                /* Erase busy is 0. move to next state to check the vendor error erase  */
                spinor_jobPrepareOperation(OSPI_REGISTER_READ, 0, (uint8*)&JobCtx->sparereadbuffer, len, err_status_register);

                /* Start the job operation and command Engine */
                status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
                if (SPINOR_DEVICE_DONE != status)
                {
                    JobCtx->jobOperationState.erasememstate = ERASE_OP_ERROR;
                    return SPINOR_DEVICE_FAIL;
                }
                JobCtx->jobOperationState.erasememstate = ERASE_RD_VENDOR_ERR_STATUS;
            }
            break;
        }
        case ERASE_RD_VENDOR_ERR_STATUS:
        {
            SPINOR_CMDEngineStatusType eCmdEngineStatus;
            eCmdEngineStatus = spinorCMDEngineGetState();
            uint8 len;

            bool crc_status = FALSE;
#ifdef SPINOR_CRC_ENABLE
            crc_status = GetCRCFlag();
#endif

            if(p_spinor_dev->perfmode_enabled == FALSE)
                len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
            else
                len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;

            if ((SPINOR_CMD_ENGINE_FLUSH_TIMEOUT == eCmdEngineStatus) || (SPINOR_CMD_ENGINE_ERROR == eCmdEngineStatus)  || (SPINOR_CMD_ENGINE_FLUSH_ERROR == eCmdEngineStatus))
            {
                /* Engine timeout or error */
                JobCtx->jobOperationState.erasememstate = ERASE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }

            if (SPINOR_CMD_ENGINE_IDLE != eCmdEngineStatus)
            {
                /* Engine busy still */
                return SPINOR_DEVICE_DONE;

            }

            /* Read completed here. check for error */
            if (((uint8)JobCtx->sparereadbuffer & p_spinor_dev->config_data->erase_err_bmsk))
            {
                /* Error in Erase operation */
                JobCtx->jobOperationState.erasememstate = ERASE_OP_ERROR;
                return SPINOR_DEVICE_FAIL;
            }

            /* If ECC CRC enabled, check for the status */
            if ((p_spinor_dev->config_data->ecc_info.ecc_supported == TRUE) && (p_spinor_dev->ecc_enabled_status_local == TRUE))
            {
#ifdef SPINOR_ECC_ENABLE
                /* Read the ECC status register */
                spinor_jobPrepareOperation(OSPI_REGISTER_READ, 0, (uint8*)&JobCtx->sparereadbuffer, len, READ_STATUS_CMD);

                /* Start the job operation and command Engine */
                status = spinor_jobStartOperation(&JobCtx->CMDEngineParams);
                if (SPINOR_DEVICE_DONE != status)
                {
                    JobCtx->jobOperationState.erasememstate = ERASE_OP_ERROR;
                    return SPINOR_DEVICE_FAIL;
                }

                /* next state is check ECC */
                JobCtx->jobOperationState.erasememstate = ERASE_RD_ECC_ERR_STATUS;
#endif
            }
            else if ((p_spinor_dev->config_data->crc_info.crc_supported == TRUE) && (crc_status == TRUE))
            {
#ifdef SPINOR_CRC_ENABLE
                /* next state is check CRC */
                JobCtx->jobOperationState.erasememstate = ERASE_RD_CRC_ERR_STATUS;
#endif
            }
            else
            {
                status = spinor_util_getnum4kblock(JobCtx->jobParams.addr, &blockInfo);
                if(status != SPINOR_DEVICE_DONE)
                {
                    return SPINOR_DEVICE_FAIL;
                }
                blocks_erased = blockInfo.block_num;

                JobCtx->jobParams.len = JobCtx->jobParams.len - blocks_erased;

                JobCtx->jobParams.addr += blocks_erased*(p_spinor_dev->config_data->block_size_in_bytes);

                if (JobCtx->jobParams.len>0)
                {
                    JobCtx->jobOperationState.erasememstate = ERASE_PENDING;

                }
                else
                {
                    JobCtx->jobOperationState.erasememstate = ERASE_OP_DONE;
                }
            }
            break;
        }
        case ERASE_RD_ECC_ERR_STATUS:
        case ERASE_RD_ECC_ERR_ADDR:
        case ERASE_RD_CRC_ERR_STATUS:
        case ERASE_OP_DONE:
            break;

        case ERASE_OP_ERROR:
        case ERASE_OP_ECC_ERROR:
        case ERASE_OP_CRC_ERROR:
        {
            SPINOR_LOG_INFO("%s: Erase Error State , Nothing to do \r\n", __func__);
            break;
        }

        case ERASE_TIMEOUT_ERROR:
        {
            SPINOR_LOG_INFO("%s: Erase Timeout Error State , Nothing to do \r\n", __func__);
            break;
        }

        default:
        {
            spinor_log (&p_spinor_dev->debug_log, 0xA05);
            SPINOR_LOG_ERROR("%s: Error, Invalid Erase state \r\n", __func__);
            return SPINOR_DEVICE_FAIL;
            break;
        }
    }

#ifdef SPINOR_PROFILE_ENABLED
  p_spinor_dev->profiling_time.spinor_core_erase_time = vBootLogger_LogDeltaTime(p_spinor_dev->profiling_time.spinor_core_erase_time, "SPINOR erase END time \r\n");
#endif /* SPINOR_PROFILE_ENABLED */

spinor_core_erase_end:
  return status;
}
