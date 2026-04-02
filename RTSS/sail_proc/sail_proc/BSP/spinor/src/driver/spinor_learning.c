/*
===========================================================================
*/
/**
    @file  spinor_learning.c
    @brief SPINOR training support functions

*/
/*
    ===========================================================================

    Copyright (c) 2020-2025 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/driver/spinor_learning.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "spinor_cm_defs.h"
#include "spinor_core.h"
#include "spinor_job.h"
#include "spinor_hal.h"
#include "spinor_utils.h"
#include "spinor_osal.h"
#include "spinor_init_config.h"
#include "debug_log.h"
#include "boot_logger.h"
#include "spinor_diag.h"
#include "gpt_partition1.h"
#include "common_functions.h"

/* Defines for DDR DLP Training*/
#define MAX_LANES 8
#define MAX_NUM_PHASE_SHIFT 8

/* Defines for SDR DLL training */
#define MAX_SDR_DLL_PHASES 16

#define DLP_GUID "e71077eb-c60d-46ac-a6a0-130dd47925fc"

/* Globals for DLP training */
uint32_t dlp_partition_address = 0;
uint8_t dlp_pattern_read[128]=
                                  {
                                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                  };

uint8_t default_hard_coded_dlp[128]=
                                  {
                                        0xFF,0xFF,0x00,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0xCC,0xCC,0xCC,0x33,0xCC,0xCC,
                                        0xCC,0x33,0x33,0xCC,0xCC,0xCC,0xFF,0xFF,0xFF,0xEE,0xFF,0xFF,0xFF,0xEE,0xEE,0xFF,
                                        0xFF,0xFF,0xDD,0xFF,0xFF,0xFF,0xDD,0xDD,0xFF,0xFF,0xFF,0xBB,0xFF,0xFF,0xFF,0xBB,
                                        0xBB,0xFF,0xFF,0xFF,0x77,0xFF,0xFF,0xFF,0x77,0x77,0xFF,0x77,0xBB,0xDD,0xEE,0xFF,
                                        0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0xCC,0xCC,0xCC,0x33,0xCC,
                                        0xCC,0xCC,0x33,0x33,0xCC,0xCC,0xCC,0xFF,0xFF,0xFF,0xEE,0xFF,0xFF,0xFF,0xEE,0xEE,
                                        0xFF,0xFF,0xFF,0xDD,0xFF,0xFF,0xFF,0xDD,0xDD,0xFF,0xFF,0xFF,0xBB,0xFF,0xFF,0xFF,
                                        0xBB,0xBB,0xFF,0xFF,0xFF,0x77,0xFF,0xFF,0xFF,0x77,0x77,0xFF,0x77,0xBB,0xDD,0xEE,
                                  };

/* CDR phase select (gray coded) */
uint8 sdr_dll_cdr_phase_sel [MAX_SDR_DLL_PHASES]= {
                                 0,  /* phase 0 */
                                 1,  /* phase 1 */
                                 3,  /* phase 2 */
                                 2,  /* phase 3 */
                                 6,  /* phase 4 */
                                 7,  /* phase 5 */
                                 5,  /* phase 6 */
                                 4,  /* phase 7 */
                                 12, /* phase 8 */
                                 13, /* phase 9 */
                                 15, /* phase 10 */
                                 14, /* phase 11 */
                                 10, /* phase 12 */
                                 11, /* phase 13 */
                                 9,  /* phase 14 */
                                 8,  /* phase 15 */
                              };
/* Phase shift for SDR DLL mode */
uint8_t phase_shift[3]= {0xff,0xff,0xff};

/* Phase shift per lane for DDR DLP training */
uint8_t lane_phase_shift[3][MAX_LANES] = {
                                             /* First index of match for each lane */
                                            {
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT
                                            },
                                             /* Last index of match for each lane*/
                                            {
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT
                                            },
                                            /* Final shift for each lane*/
                                            {
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT,
                                                MAX_NUM_PHASE_SHIFT
                                            }
                                         };

/**********************************************************
 * Checks if the DLP pattern read and the pattern expected are matching (bitwise)
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static boolean is_dlp_match(uint8_t index, uint num_patterns)
{
    uint32_t bits_read=0;
    uint32_t bits_expect=0;
    uint32_t mask=1<<index;


    for (int i=0;i<num_patterns;i++)
    {
        bits_read |= (uint32) (((dlp_pattern_read[i]&mask)>>index) << i);
        bits_expect |= (uint32) (((default_hard_coded_dlp[i]&mask)>>index) << i);
    }

    if (bits_read == bits_expect)
    {
        return TRUE;
    }

    return FALSE;
}

/**********************************************************
 * Checks if the DLP pattern read and the pattern expected are matching
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static boolean is_pattern_match(void)
{
    /* Confirm if the read patern matches the expected pattern */
    for (int j=0;j<sizeof(dlp_pattern_read)/sizeof(dlp_pattern_read[0]);j++)
    {
        if (dlp_pattern_read[j]!=default_hard_coded_dlp[j])
        {
            return FALSE;
        }
    }

    return TRUE;
}

/**********************************************************
 * Performs SDR DLL training
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_learning_SDR_DLL_training(void)
{
    uint8_t i;
    uint8_t num_matches=0;
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinor_OperationParamType xMemParams = {0};

    // total phase shift level
    for(i=0;i<MAX_SDR_DLL_PHASES;i++)
    {
        /* Load the CDR Select config */
        if(FALSE == spinor_hal_load_CDR_cfg(sdr_dll_cdr_phase_sel[i]))
        {
          spinor_log (&p_spinor_dev->debug_log, 0x700);
          SPINOR_LOG_ERROR("%s: Error, load CDR cfg failure \r\n", __func__);
          status = SPINOR_DEVICE_FAIL;
          return status;
        }

        xMemParams = (spinor_OperationParamType){.addr = dlp_partition_address, .buffer = dlp_pattern_read, .len = sizeof(dlp_pattern_read)/sizeof(dlp_pattern_read[0]), .opcode=0, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
        status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_MEM, &xMemParams);
        if (SPINOR_DEVICE_DONE != status)
        {
          spinor_log (&p_spinor_dev->debug_log, 0x701);
          SPINOR_LOG_ERROR("%s: Error, Read failure, status = 0x%x \r\n", __func__, status);
          return status;
        }

        /* For every CDR value, check if the pattern matches */
        if (TRUE == is_pattern_match())
        {
            if (phase_shift[0] == 0xff)
            {
                phase_shift[0] = i;
            }
            phase_shift[1] = i;
            num_matches++;
        }
    }

    /* After all possible CDR check the match results to update the final settings for  phase Shift */
    /* verify there was at least 1 match */
    if(0xFF == phase_shift[0])
    {
        spinor_log (&p_spinor_dev->debug_log, 0x702);
        SPINOR_LOG_ERROR("%s: Error, No phase shift matches \r\n", __func__);
        status = SPINOR_DEVICE_FAIL;
        return status;
    }

    /* Update the final phase shift value in the index 2 */
    phase_shift[2] = phase_shift[0] + (num_matches-1)/2;

    /* Load the CDR Select config */
    if ( FALSE == spinor_hal_load_CDR_cfg ( sdr_dll_cdr_phase_sel[phase_shift[2]] ) )
    {
        spinor_log (&p_spinor_dev->debug_log, 0x703);
        SPINOR_LOG_ERROR("%s: Error, Load CDR cfg 2 failure \r\n", __func__);
        status = SPINOR_DEVICE_FAIL;
        return status;
    }

    /* Read the information again with the new configuration of the sampling clocks */
    xMemParams = (spinor_OperationParamType){.addr = dlp_partition_address, .buffer = dlp_pattern_read, .len = sizeof(dlp_pattern_read)/sizeof(dlp_pattern_read[0]), .opcode=0, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_MEM, &xMemParams);
    if (SPINOR_DEVICE_DONE != status)
    {
      spinor_log (&p_spinor_dev->debug_log, 0x704);
      SPINOR_LOG_ERROR("%s: Error, Read failure 2, status = 0x%x \r\n", __func__, status);
      return status;
    }

    /* Confirm if the read patern matches the expected pattern */
    if (FALSE == is_pattern_match())
    {
        spinor_log (&p_spinor_dev->debug_log, 0x705);
        status = SPINOR_DEVICE_FAIL;
        SPINOR_LOG_ERROR("%s: Error, Pattern match failure \r\n", __func__);
        return status;
    }

    return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * Performs DDR DLP training
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_DDR_DLP_training(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    boolean lane_done[MAX_LANES]={FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE};
    uint8_t num_matches[MAX_LANES] =  {0,0,0,0,0,0,0,0};
    // uint8_t match_cnt=0;
    uint8_t i,j;
    uint8_t cfg[MAX_LANES]= {0,0,0,0,0,0,0,0};
    spinor_OperationParamType xMemParams = {0};


    // total phase shift level
    for(i=0;i<MAX_NUM_PHASE_SHIFT;i++)
    {
        /* Set the sampling clk config to shift level for all lanes*/
        for (int k = 0;k<MAX_LANES;k++)
        {
            cfg[k]= i;
        }

        /* Load the sampling clk config */
        spinor_hal_load_sampling_clk_cfg(cfg);

        xMemParams = (spinor_OperationParamType){.addr = dlp_partition_address, .buffer = dlp_pattern_read, .len = sizeof(dlp_pattern_read)/sizeof(dlp_pattern_read[0]), .opcode=0, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
        status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_MEM, &xMemParams);
        if (SPINOR_DEVICE_DONE != status)
        {
          spinor_log (&p_spinor_dev->debug_log, 0x706);
          SPINOR_LOG_ERROR("%s: Error, Read failure, status = 0x%x \r\n", __func__, status);
          return status;
        }

        /* For every Lane perform the check  to see if there is a match */
        for (j=0;j<MAX_LANES;j++)
        {
            if (TRUE == is_dlp_match(j,sizeof(dlp_pattern_read)/sizeof(dlp_pattern_read[0])))
            {
                if (lane_done[j] == FALSE)
                {
                    lane_done[j] = TRUE;
                    lane_phase_shift[0][j] = i;
                }

                lane_phase_shift[1][j] = i;
                num_matches[j]++;
                //match_cnt++;
            }

            /* If the match_cnt is 8 then all lanes are trained in this iteration . break*/
            //if (match_cnt == 8)
            //{
            //    break;
            //}
        }

        /* If match_cnt is 8 we are done, else reset it to 0 */
        //if (match_cnt == 8)
        //    return;
        //else
        //    match_cnt = 0;
    }

    /* After all possible shifting check the match results to update the final settings for lane phase Shift */
    for (j=0;j<MAX_LANES;j++)
    {
        /* verify there was at least 1 match */
        if(FALSE == lane_done[j])
        {
            spinor_log (&p_spinor_dev->debug_log, 0x707);
            SPINOR_LOG_ERROR("%s: Error, lane done is false for %d \r\n", __func__, j);
            status = SPINOR_DEVICE_FAIL;
            return status;
        }

        /* Update the final Lane phase shift value in the index 2 */
        lane_phase_shift[2][j] = lane_phase_shift[0][j] + (num_matches[j]-1)/2;
    }


    /* Load the sampling clk config from the new learning */
    spinor_hal_load_sampling_clk_cfg(lane_phase_shift[2]);

    /* Read the information again with the new configuration of the sampling clocks */
    xMemParams = (spinor_OperationParamType){.addr = dlp_partition_address, .buffer = dlp_pattern_read, .len = sizeof(dlp_pattern_read)/sizeof(dlp_pattern_read[0]), .opcode=0, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_MEM, &xMemParams);
    if (SPINOR_DEVICE_DONE != status)
    {
      spinor_log (&p_spinor_dev->debug_log, 0x708);
      SPINOR_LOG_ERROR("%s: Error, Read failure 2, status = 0x%x \r\n", __func__, status);
      return status;
    }

    /* Confirm if the read patern matches the expected pattern */
    for (int j=0;j<sizeof(dlp_pattern_read)/sizeof(dlp_pattern_read[0]);j++)
    {
        if (dlp_pattern_read[j]!=default_hard_coded_dlp[j])
        {
            spinor_log (&p_spinor_dev->debug_log, 0x709);
            SPINOR_LOG_ERROR("%s: Error, read patern does not match the expected pattern \r\n", __func__);
            status = SPINOR_DEVICE_FAIL;
            return status;
        }
    }

    return SPINOR_DEVICE_DONE;
}

int spinor_gptPartitiontry(uint32 startAddr, uint32 sz, gptHeader_t* gptHdr, boolean* tryval)
{
    size_t result = 0;
    spinor_OperationParamType xMemParams = {0};

    xMemParams = (spinor_OperationParamType){.addr = startAddr, .buffer = dlp_pattern_read, .len = sz, .opcode=0, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    if (SPINOR_DEVICE_DONE != spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_MEM, &xMemParams))
    {
        *tryval = FALSE;
        return -1;
    }

    result = sailbsp_memscpy(gptHdr, sizeof(gptHeader_t), dlp_pattern_read, sizeof(gptHeader_t));
    if(result == 0)
    {
        *tryval = FALSE;
        return -1;
    }

    /* verify GPT header CRC */
    if (FALSE == gptVerifyHeaderCRC32(gptHdr, GPT_CRC32_SEED_DEFAULT))
    {
        *tryval = FALSE;
        return 0;
    }

    *tryval = TRUE;
    return 0;
}


static SPINOR_STATUS spinor_get_dlp_address(void)
{
    int status = 0;
    uint32_t gpthdr_sz;
    uint32_t sz;
    gptHeader_t gptHdr = {0};
    guid_t tmpGuid;
    boolean tryval;
    spinor_OperationParamType xMemParams = {0};
    uint32_t ulBase;
    uint32_t ulEntrySz;
    gptEntry_t *pEntry;

    /* If the address is already populated use the address as it is */
    if (0 != dlp_partition_address)
    {
        return SPINOR_DEVICE_DONE;
    }

    /* check GPT valid */
    gpthdr_sz = sizeof(gptHeader_t);
    sz = (gpthdr_sz % SPINOR_BYTES_ALIGNMENT) ? gpthdr_sz + SPINOR_BYTES_ALIGNMENT - (gpthdr_sz % SPINOR_BYTES_ALIGNMENT) : gpthdr_sz;

    /* check Primary GPT valid */
    status = spinor_gptPartitiontry(NOR_LBA_SZ, sz, &gptHdr, &tryval);
    if(status != 0)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x70F);
        SPINOR_LOG_ERROR("%s:Error, gptPartitiontry1 failed\r\n", __func__);
        goto error;
    }

    if(tryval == TRUE)
    {
        goto found;
    }

    /* Clear the gptHdr contents */
    memset (&gptHdr, 0, sizeof(gptHeader_t));

    /* check Secondary GPT valid */
    status = spinor_gptPartitiontry((p_spinor_dev->config_data->density_in_blocks-1)*NOR_LBA_SZ, sz, &gptHdr, &tryval);
    if(status != 0)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x710);
        SPINOR_LOG_ERROR("%s:Error, gptPartitiontry2 failed\r\n", __func__);
        goto error;
    }

    if(tryval == TRUE)
    {
        goto found;
    }
    else
    {
        spinor_log (&p_spinor_dev->debug_log, 0x714);
        SPINOR_LOG_ERROR("%s:Error, gptPartitiontry2 error\r\n", __func__);
        goto error;
    }

found:
    /* Found valid GPT header. Get the GUID for DLP partition and find the address within the first 2 partition entries */
    /* get guid_t */
    if (FALSE == gptPartitionDecodeGUIDString((const char*)DLP_GUID, &tmpGuid))
    {
        spinor_log (&p_spinor_dev->debug_log, 0x711);
        SPINOR_LOG_ERROR("%s:Error, GUID string decode error\r\n", __func__);
        goto error;
    }

    ulBase     = ((uint32_t)(gptHdr.partition_entry_lba & 0xFFFFFFFF)) * NOR_LBA_SZ;
    ulEntrySz  = gptHdr.size_of_partition_entry;

    pEntry  = (gptEntry_t *)dlp_pattern_read;

    for ( int i = 0; i < 2; i++ )
    {
        xMemParams = (spinor_OperationParamType){.addr = (ulBase + i * ulEntrySz), .buffer = dlp_pattern_read, .len = sz, .opcode=0, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
        if (SPINOR_DEVICE_DONE != spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_MEM, &xMemParams))
        {
            spinor_log (&p_spinor_dev->debug_log, 0x712);
            SPINOR_LOG_ERROR("%s:Error, reading GPT partition entry %d failed\r\n", __func__,i);
            goto error;
        }
        if ( !gptVerifyPartitionGuid(pEntry, &tmpGuid) )
        {
            continue;
        }
        dlp_partition_address = (uint32_t)gptGetPartitionBase ( pEntry, NOR_LBA_SZ );
        SPINOR_LOG_WARNING("%s:dlp partition address 0x%x obtained\r\n", __func__,dlp_partition_address);
        memset (dlp_pattern_read, 0, sizeof(dlp_pattern_read)/sizeof(dlp_pattern_read[0]));
        return SPINOR_DEVICE_DONE;
    }

error:
    memset (dlp_pattern_read, 0, sizeof(dlp_pattern_read)/sizeof(dlp_pattern_read[0]));
    return SPINOR_DEVICE_FAIL;
}

/**********************************************************
 * Check if NOR flash card's pattern matches the defined pattern
 *
 * @param result [IN/OUT] Result of the pattern match check
 *
 * @return int [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_learning_check_nor_pattern(boolean* result)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  spinor_OperationParamType xMemParams = {0};

  *result = FALSE;

  status = spinor_get_dlp_address();

  if(SPINOR_DEVICE_DONE != status)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x713);
    SPINOR_LOG_ERROR("%s:Failed to get dlp partition address status=0x%x\r\n", __func__, status);
    goto done;
  }

  xMemParams = (spinor_OperationParamType){.addr = dlp_partition_address, .buffer = dlp_pattern_read, .len = sizeof(dlp_pattern_read)/sizeof(dlp_pattern_read[0]), .opcode=0, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
  status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_MEM, &xMemParams);
  if (SPINOR_DEVICE_DONE != status)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x70A);
    SPINOR_LOG_ERROR("%s:Error,Read failure, status=0x%x\r\n", __func__, status);
    goto done;
  }

  /* Confirm if the read patern matches the expected pattern */
  *result = is_pattern_match();
  if (FALSE == *result)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x70B);
    SPINOR_LOG_ERROR("%s:Warning,pattern does not match\r\n", __func__);
    goto done;
  }

done:
  return status;
}

boolean spinor_learning_write_nor_pattern(void)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  boolean bRet = FALSE;

  spinor_OperationParamType xMemParams = {0};

  /* Erase the 4k Block */
  xMemParams = (spinor_OperationParamType){.addr = dlp_partition_address, .buffer = 0, .len = 1, .opcode=0, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
  status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_ERASE_MEM, &xMemParams);
  if (SPINOR_DEVICE_DONE != status)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x70C);
    SPINOR_LOG_ERROR("%s:Error, Erase failure, status = 0x%x\r\n", __func__, status);
    goto end;
  }

  /* Write the default pattern */
  xMemParams = (spinor_OperationParamType){.addr = dlp_partition_address, .buffer = default_hard_coded_dlp, .len = sizeof(default_hard_coded_dlp)/sizeof(default_hard_coded_dlp[0]), .opcode=0, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
  status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_WRITE_MEM, &xMemParams);
  if (SPINOR_DEVICE_DONE != status)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x70D);
    SPINOR_LOG_ERROR("%s:Error, Write failure, status = 0x%x\r\n", __func__, status);
    goto end;
  }

  xMemParams = (spinor_OperationParamType){.addr = dlp_partition_address, .buffer = dlp_pattern_read, .len = sizeof(dlp_pattern_read)/sizeof(dlp_pattern_read[0]), .opcode=0, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
  status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_MEM, &xMemParams);
  if (SPINOR_DEVICE_DONE != status)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x70E);
    SPINOR_LOG_ERROR("%s:Error, Read failure, status = 0x%x\r\n", __func__, status);
    goto end;
  }

  status = spinor_learning_check_nor_pattern(&bRet);
  if ((SPINOR_DEVICE_DONE != status) || (FALSE == bRet) )
  {
    bRet = FALSE;
    goto end;
  }
end:
  return bRet;
}
