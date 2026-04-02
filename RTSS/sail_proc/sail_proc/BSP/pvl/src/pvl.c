/*
===========================================================================
*/
/**
    @file  pvl.c
    @brief implementation of pvl test cases

*/
/*
===========================================================================

    Copyright (c) 2022-2025 Qualcomm Technologies, Inc.
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

    $Header: $
    $DateTime: $
    $Author: $

===========================================================================
*/

#include "types.h"
#include "pvl_api.h"
#include "pvl.h"
#include "pvl_diag.h"
#include "spinor_el2_api.h"
#include "spinor_cm_defs.h"
#include "spinor_pvl_api.h"
#include "target_linker_map.h"
#include "timetick.h"
#include "common_functions.h"
#include "busywait.h"
#include "xbl_def.h"
#include "boot.h"
#include "gpt_partition1.h"

#define PVL_READ_BUF_SIZE       (32*1024U)
#define PVL_WRITE_BUF_SIZE      4096U
#define PVL_KPI_RAM_DUMP_GUID   "46117b39-6a0f-4cf9-b70a-71c09a62ba72"   /* read SAIL_RAM_DUMP to do read KPI test */
#define WRITE_BYTE_PATTERN      0x34
#define ERASE_BYTE_PATTERN      0xFF
#define READ_BYTE_PATTERN       0x00
#define GPT_CRC32_SEED_INVERSE              1UL
#define CD_PARTITION_SIZE       0x100000
#define SAIL_1MB_RAM_ADDR       0x8180000

static spinor_hardcode_data_mode g_test_mode_params;
static uint8_t* swaADdr = (uint8_t *)(SAIL_1MB_RAM_ADDR); //SAIL_SRAM3 bank
static uint8_t* ucReadBuf = (uint8_t *)(SAIL_1MB_RAM_ADDR + CD_PARTITION_SIZE); //SAIL_SRAM3 bank + 1MB
static uint8_t* ucwriteBuf = (uint8_t *)(SAIL_1MB_RAM_ADDR + CD_PARTITION_SIZE+ PVL_READ_BUF_SIZE); //SAIL_SRAM3 bank + 1MB + 32KB
uint32_t write_count = 0;
uint32_t erase_count = 0;
boolean xblInitialized = false;
boolean xblloadtest = false;

uint8_t default_hard_coded_dlp_sram3_pvl[128]=
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

uint8_t inverse_hard_coded_dlp[128]=
                                  {
                                        0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x33,0x33,0x33,0xCC,0x33,0x33,
                                        0x33,0xCC,0xCC,0x33,0x33,0x33,0x00,0x00,0x00,0x11,0x00,0x00,0x00,0x11,0x11,0x00,
                                        0x00,0x00,0x22,0x00,0x00,0x00,0x22,0x22,0x00,0x00,0x00,0x44,0x00,0x00,0x00,0x44,
                                        0x44,0x00,0x00,0x00,0x88,0x00,0x00,0x00,0x88,0x88,0x00,0x88,0x44,0x22,0x11,0x00,
                                        0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x33,0x33,0x33,0xCC,0x33,
                                        0x33,0x33,0xCC,0xCC,0x33,0x33,0x33,0x00,0x00,0x00,0x11,0x00,0x00,0x00,0x11,0x11,
                                        0x00,0x00,0x00,0x22,0x00,0x00,0x00,0x22,0x22,0x00,0x00,0x00,0x44,0x00,0x00,0x00,
                                        0x44,0x44,0x00,0x00,0x00,0x88,0x00,0x00,0x00,0x88,0x88,0x00,0x88,0x44,0x22,0x11,
                                  };

typedef struct {
  uint64_t eraseStart;
  uint64_t eraseEnd;
  uint64_t eraseDurationUs;
  uint64_t writeStart;
  uint64_t writeEnd;
  uint64_t writeDurationUs;
  uint64_t readStart;
  uint64_t readEnd;
  uint64_t readDurationUs;
  uint64_t eraseAvgDurationUs;
  uint64_t writeAvgDurationUs;
  uint64_t readAvgDurationUs;
} spinorEl2PerfTimestampType;

static spinorEl2PerfTimestampType gSpinorEl2PerfStruct;

typedef struct {
    uint64_t read_kpi_32KB;
    uint64_t read_kpi_4KB;
    uint64_t read_kpi_256B;
    uint64_t erase_kpi;
    uint64_t write_kpi_256B;
    uint64_t write_kpi_1KB;
    uint64_t write_kpi_4KB;
}spinorKPIParamType;

static spinorKPIParamType gSpinorKPIValues;    /* Avg Time taken in us */

typedef struct {
    uint32_t read_perf_32KB;
    uint32_t read_perf_4KB;
    uint32_t read_perf_256B;
    uint32_t erase_perf;
    uint32_t write_perf_256B;
    uint32_t write_perf_1KB;
    uint32_t write_perf_4KB;
}spinorPerfParamType;

static spinorPerfParamType gSpinorPerfValues;   /* Performance in KB/s */


static void El2PerfTestSetTimestamp(uint64_t *tick)
{
  *tick = timetick_get64();
}

static void El2PerfTestSetDuration(uint64_t start, uint64_t end, uint64_t *durationUs)
{
  *durationUs = (end - start) * 10 / 192;
}

static uint64_t El2PerfTestDurationToTick(uint64_t ulMicroseconds)
{
  uint64_t ticks = (ulMicroseconds / 10) * 192;
  return ticks;
}

static void init_global_params(void)
{
  memset (&g_test_mode_params, 0, sizeof(g_test_mode_params));
}

/* Helper function to get the number of 4kblocks in the sectors for which the address belongs */
static uint32 GetNum4kBlock(uint32_t addr, spinorSectorMapInfoType *sectorMapInfo)
{
    uint32 num_blocks;

    for (int idx = 0; idx <= 4; idx++)
    {
        if ( (addr >= sectorMapInfo->sectorMapInfo[idx].start_range) && (addr <= sectorMapInfo->sectorMapInfo[idx].end_range))
        {
          num_blocks = sectorMapInfo->sectorMapInfo[idx].er_size_KB/4;
          return num_blocks;
        }
    }

    return 0;
}

static SPINOR_STATUS flash_init_open_and_get_mem_info(spinor_handle_t *handle, int32_t type, spinor_hardcode_data_mode* hardcode_mode, spinorMemInfoType* memInfo, int32_t spinor_user_type)
{
  SPINOR_STATUS status;
  spinor_handle_t handle_loc = NULL;
  spinorMemInfoType memInfo_loc = {0U};

  do
  {
    status = spinorEl2Init(type, hardcode_mode);
    if ( SPINOR_DEVICE_DONE != status)
    {
      PVL_LOG_ERROR("%s: Error, spinorEl2Init failed, ret = %d\r\n", __func__, status);
      break;
    }
    PVL_LOG_WARNING("%s: spinorEl2Init done\r\n", __func__);

    status = spinorEl2Open ( &handle_loc, spinor_user_type );
    if ( SPINOR_DEVICE_DONE != status)
    {
      PVL_LOG_ERROR("%s: spinorEl2Open failed, ret = %d\r\n", __func__, status);
      break;
    }
    PVL_LOG_WARNING("%s: spinorEl2Open done\r\n", __func__);

    status = spinorEl2GetMemInfo ( handle_loc, &memInfo_loc );
    if ( SPINOR_DEVICE_DONE != status)
    {
      PVL_LOG_ERROR("%s: Error, spinorEl2GetMemInfo failed, ret = %d\r\n", __func__, status);
      break;
    }
    if ( !memInfo_loc.device_id )
    {
      PVL_LOG_ERROR("%s: Error, no device ID\r\n", __func__);
      break;
    }
    PVL_LOG_WARNING("%s: spinorEl2GetMemInfo done. device_id = 0x%x\r\n", __func__, memInfo_loc.device_id);
    *handle = handle_loc;
    *memInfo = memInfo_loc;
  } while (0U);

  return status;
}

static SPINOR_STATUS read_kpi_test(spinor_handle_t handle, struct spinor_info* memInfo,
                                   const char* read_guid, uint32_t read_bytes, uint64_t* avg_duration_us)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t partition_base = 0;
    uint32_t partition_size = CD_PARTITION_SIZE;
    uint32_t i = 0;
    uint32_t offset;
    gSpinorEl2PerfStruct.readAvgDurationUs = 0;
    uint32_t loop = 0;


    status = spinorEl2GetGptPartitionInfo(handle, read_guid, &partition_base, &partition_size);
    if ( SPINOR_DEVICE_DONE != status)
    {
      PVL_LOG_ERROR("%s: Error, no partition found for guid '%s'\r\n", __func__, read_guid);
      goto read_kpi_test_end;
    }
    if(partition_size > CD_PARTITION_SIZE)
        partition_size= CD_PARTITION_SIZE;
    loop = partition_size/read_bytes;

    for(i = 0; i < loop; i++)
    {
        gSpinorEl2PerfStruct.readStart = 0;
        gSpinorEl2PerfStruct.readEnd = 0;
        gSpinorEl2PerfStruct.readDurationUs = 0;

        offset = partition_base + (i * read_bytes);
        El2PerfTestSetTimestamp(&gSpinorEl2PerfStruct.readStart);
        status = spinorEl2Read (handle, offset, read_bytes, ucReadBuf);
        if ( SPINOR_DEVICE_DONE == status)
        {
            El2PerfTestSetTimestamp(&gSpinorEl2PerfStruct.readEnd);
            El2PerfTestSetDuration(gSpinorEl2PerfStruct.readStart, gSpinorEl2PerfStruct.readEnd, &gSpinorEl2PerfStruct.readDurationUs);

            gSpinorEl2PerfStruct.readAvgDurationUs += gSpinorEl2PerfStruct.readDurationUs;
            if (memcmp(ucReadBuf, swaADdr + (i * read_bytes), read_bytes))
            {
                /* read and write data are different */
                PVL_LOG_ERROR("%s: Error, write data inconsistent \r\n", __func__, offset, PVL_WRITE_BUF_SIZE);
                status = SPINOR_DEVICE_FAIL;
                break;
            }
            continue;
        }
        PVL_LOG_ERROR("%s: Error, read failed. start_addr = 0x%x, size  = 0x%x\r\n", __func__, offset, read_bytes);
        break;
    }

    if(SPINOR_DEVICE_DONE == status)
    {
        *avg_duration_us = (gSpinorEl2PerfStruct.readAvgDurationUs/loop);
    }

read_kpi_test_end:
  return status; //mzhu todo
}
static SPINOR_STATUS erase_kpi_test(spinor_handle_t handle, struct spinor_info* memInfo,
                                   const char* erase_write_guid, uint64_t* avg_duration_us)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t erase_start_block = 0;
    uint32_t erase_block_count = 0;
    uint32_t block_size_bytes = 0;
    uint32_t partition_base = 0;
    uint32_t partition_size = CD_PARTITION_SIZE;
    uint32_t offset = 0;
    uint32_t i = 0,j=0;
    gSpinorEl2PerfStruct.eraseAvgDurationUs = 0;
    uint32_t loop = 0;
    spinorSectorMapInfoType sectorMapInfo = {0};


    status = spinorEl2GetGptPartitionInfo(handle, erase_write_guid, &partition_base, &partition_size);
    if ( SPINOR_DEVICE_DONE != status)
    {
      PVL_LOG_ERROR("%s: Error, no partition found for guid '%s'\r\n", __func__, erase_write_guid);
      goto erase_kpi_test_end;
    }
    if(partition_size < memInfo->pages_per_block * memInfo->page_size_bytes)
    {
      PVL_LOG_ERROR("%s: Error,partition size is invalid \r\n", __func__);
      goto erase_kpi_test_end;
    }

    status = spinorEl2GetSectorMapInfo(handle, &sectorMapInfo);
    if( SPINOR_DEVICE_DONE != status )
    {
        PVL_LOG_ERROR("%s: Error, Getting Sector map info \r\n", __func__);
        goto erase_kpi_test_end;
    }

    if(partition_size > CD_PARTITION_SIZE)
        partition_size= CD_PARTITION_SIZE;
    block_size_bytes  = memInfo->pages_per_block * memInfo->page_size_bytes;
    erase_block_count = 1;
    loop = partition_size/4096;
    erase_start_block = (partition_base/block_size_bytes) ;

    while (loop>0)
    {
        gSpinorEl2PerfStruct.eraseStart = 0;
        gSpinorEl2PerfStruct.eraseEnd = 0;
        gSpinorEl2PerfStruct.eraseDurationUs = 0;

        /* Get num 4k block */
        erase_block_count = GetNum4kBlock(erase_start_block*block_size_bytes, &sectorMapInfo);

        El2PerfTestSetTimestamp(&gSpinorEl2PerfStruct.eraseStart);

        status = spinorEl2Erase (handle, erase_start_block, erase_block_count);
        if (SPINOR_DEVICE_DONE == status)
        {
          El2PerfTestSetTimestamp(&gSpinorEl2PerfStruct.eraseEnd);
          El2PerfTestSetDuration(gSpinorEl2PerfStruct.eraseStart, gSpinorEl2PerfStruct.eraseEnd, &gSpinorEl2PerfStruct.eraseDurationUs);

          gSpinorEl2PerfStruct.eraseAvgDurationUs += gSpinorEl2PerfStruct.eraseDurationUs;

          offset = erase_start_block*block_size_bytes;
          for (j=0;j<erase_block_count;j++)
          {
              status = spinorEl2Read(handle, offset+(j * block_size_bytes), block_size_bytes, ucReadBuf);
              if ( SPINOR_DEVICE_DONE != status)
              {
                  PVL_LOG_ERROR("%s: Error, while reading after erase\r\n", __func__);
                  break;
              }
              memset(ucwriteBuf, ERASE_BYTE_PATTERN, block_size_bytes);
              if (memcmp(ucReadBuf, ucwriteBuf, block_size_bytes))
              {
                  /* read and write data are different */
                  PVL_LOG_ERROR("%s: Error, Read data after erase inconsistent at offset=0x%x and size=0x%x \r\n", __func__, offset+(j * block_size_bytes), PVL_WRITE_BUF_SIZE);
                  status = SPINOR_DEVICE_FAIL;
                  break;
              }
          }
          if (j<erase_block_count)
          {
              break;
          }
          erase_start_block += erase_block_count;
          loop -= erase_block_count;
          continue;
        }
        PVL_LOG_ERROR("%s: Error, erase failed. start_block = 0x%x, block_count = 0x%x, block_size = 0x%x\r\n",
                        __func__, erase_start_block, erase_block_count, block_size_bytes);
        break;
    }


    if(SPINOR_DEVICE_DONE == status)
    {
        *avg_duration_us = (gSpinorEl2PerfStruct.eraseAvgDurationUs/(partition_size/(erase_block_count * 4096)));
        erase_count += 1;
    }

    //Prerana to combine erase and write kpi test into one function
erase_kpi_test_end:
    return status; //mzhu todo
}

static SPINOR_STATUS write_kpi_test(spinor_handle_t handle, struct spinor_info* memInfo,
                                   const char* erase_write_guid, uint32_t write_bytes, uint64_t* avg_duration_us)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t partition_base = 0;
    uint32_t partition_size = 0;
    uint32_t i = 0;
    uint32_t offset = 0;
    uint32_t loop = 0;
    gSpinorEl2PerfStruct.writeAvgDurationUs = 0;
    uint8_t* wr_offset;

    status = spinorEl2GetGptPartitionInfo( handle, erase_write_guid, &partition_base, &partition_size);
    if ( SPINOR_DEVICE_DONE != status)
    {
      PVL_LOG_ERROR("%s: Error, no partition found for guid '%s'\r\n", __func__, erase_write_guid);
      goto write_kpi_test_end;
    }

    partition_size = CD_PARTITION_SIZE;
    loop = partition_size/write_bytes;

    for(i = 0; i < loop; i++)
    {
        gSpinorEl2PerfStruct.writeStart = 0;
        gSpinorEl2PerfStruct.writeEnd = 0;
        gSpinorEl2PerfStruct.writeDurationUs = 0;
        offset = partition_base + i * write_bytes;
        wr_offset = swaADdr + i * write_bytes;

        El2PerfTestSetTimestamp(&gSpinorEl2PerfStruct.writeStart);

        status = spinorEl2Write (handle, offset, write_bytes, wr_offset);
        if ( SPINOR_DEVICE_DONE == status)
        {
            El2PerfTestSetTimestamp(&gSpinorEl2PerfStruct.writeEnd);
            El2PerfTestSetDuration(gSpinorEl2PerfStruct.writeStart, gSpinorEl2PerfStruct.writeEnd, &gSpinorEl2PerfStruct.writeDurationUs);

            gSpinorEl2PerfStruct.writeAvgDurationUs += gSpinorEl2PerfStruct.writeDurationUs;

            status = spinorEl2Read ( handle, offset, write_bytes, ucReadBuf);
            if (SPINOR_DEVICE_DONE != status)
            {
                /* read after write failed */
                PVL_LOG_ERROR("%s: Error, Read after write failed at offset=0x%x and size=0x%x \r\n", __func__, offset, write_bytes);
                status = SPINOR_DEVICE_FAIL;
                break;
            }
            if (memcmp(swaADdr + i * write_bytes, ucReadBuf, write_bytes))
            {
                /* read and write data are different */
                PVL_LOG_ERROR("%s: Error, write data inconsistent for write at offset=0x%x and size=0x%x\r\n", __func__, offset, write_bytes);
                status = SPINOR_DEVICE_FAIL;
                break;
            }
            continue;
        }
        PVL_LOG_ERROR("%s: Error, write failed. start_addr = 0x%x, size  = 0x%x\r\n", __func__, offset, write_bytes);
        break;
    }

    if(SPINOR_DEVICE_DONE == status)
    {
        *avg_duration_us = (gSpinorEl2PerfStruct.writeAvgDurationUs/loop);
        write_count += 1;
    }

write_kpi_test_end:
    return status; //mzhu todo
}

static SPINOR_STATUS read_erase_write_kpi_test(spinor_handle_t handle, struct spinor_info* memInfo, const char* read_guid, const char* erase_write_guid)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
    uint32_t partition_base;
    uint32_t partition_size;
    uint32_t erase_start_block;
    uint32_t erase_block_count;
    uint32_t block_size_bytes;
    uint32_t max_er_size = 0,max_er_size_idx=0;
    spinorSectorMapInfoType sectorMapInfo = {0};

    status = spinorEl2GetGptPartitionInfo(handle, erase_write_guid, &partition_base, &partition_size);
    if ( SPINOR_DEVICE_DONE != status)
    {
      PVL_LOG_ERROR("%s: Error, no partition found for guid '%s'\r\n", __func__, erase_write_guid);
      return status;
    }

    if(partition_size < memInfo->pages_per_block * memInfo->page_size_bytes)
    {
      PVL_LOG_ERROR("%s: Error,partition size is invalid \r\n", __func__);
      return status;
    }

    status = spinorEl2GetSectorMapInfo(handle, &sectorMapInfo);
    if( SPINOR_DEVICE_DONE != status )
    {
        PVL_LOG_ERROR("%s: Error, Getting Sector map info \r\n", __func__);
        return status;
    }

    /* Getting the max erase size and the index */
    for (int idx = 0; idx < sizeof(sectorMapInfo.sectorMapInfo) / sizeof(sectorMapInfo.sectorMapInfo[0]); idx++)
    {
        if(sectorMapInfo.sectorMapInfo[idx].er_size_KB > max_er_size)
        {
            max_er_size = sectorMapInfo.sectorMapInfo[idx].er_size_KB;
            max_er_size_idx = idx;
        }
    }

    /* If the partition used for erase kpi test is not in the max size erase range error out to change partition map */
    if ( (partition_base < sectorMapInfo.sectorMapInfo[max_er_size_idx].start_range) ||
         (partition_base > sectorMapInfo.sectorMapInfo[max_er_size_idx].end_range) ||
         ((partition_base+partition_size-1) > sectorMapInfo.sectorMapInfo[max_er_size_idx].end_range)
       )
    {
         PVL_LOG_ERROR("%s: Error, Partition used for Erase KPI test is not in the range of the max erase size of the part.\r\n Change the partition layout to set the erase partition in the correct range and rerun the test", __func__);
         return status;
    }

    do
    {
        PVL_LOG_WARNING("%s: started PVL read_erase_write_kpi_test, taking few moments to read/erase/write \r\n", __func__);
        /* Measure 4KB and 32KB read performance */
        status = read_kpi_test(handle, memInfo, read_guid, PVL_READ_BUF_SIZE, &gSpinorKPIValues.read_kpi_32KB);
        if (SPINOR_DEVICE_DONE != status)
        {
          PVL_LOG_ERROR("%s: Error, 32KB read KPI test failed, status = %d\r\n", __func__, status);
          break;
        }
        status = read_kpi_test(handle, memInfo, read_guid, 4096U, &gSpinorKPIValues.read_kpi_4KB);
        if (SPINOR_DEVICE_DONE != status)
        {
          PVL_LOG_ERROR("%s: Error, 4KB read KPI test failed, status = %d\r\n", __func__, status);
          break;
        }
        /* Measure 256B read performance */
        status = read_kpi_test(handle, memInfo, read_guid, 256U, &gSpinorKPIValues.read_kpi_256B);
        if (SPINOR_DEVICE_DONE != status)
        {
          PVL_LOG_ERROR("%s: Error, 256B read KPI test failed, status = %d\r\n", __func__, status);
          break;
        }
        /* Measure erase performance */
        status = erase_kpi_test(handle, memInfo, erase_write_guid, &gSpinorKPIValues.erase_kpi);
        if (SPINOR_DEVICE_DONE != status)
        {
          PVL_LOG_ERROR("%s: Error, 4KB erase KPI test failed, status = %d\r\n", __func__, status);
          break;
        }
        /* Measure 256B, 1KB and 4KB write performance */
        status = write_kpi_test(handle, memInfo, erase_write_guid, 256U, &gSpinorKPIValues.write_kpi_256B);
        if (SPINOR_DEVICE_DONE != status)
        {
          PVL_LOG_ERROR("%s: Error, 256B write KPI test failed, status = %d\r\n", __func__, status);
          break;
        }
        //////////Need to erase again before write back again with 1KB
        status = spinorEl2GetGptPartitionInfo( handle, erase_write_guid, &partition_base, &partition_size);
        if ( SPINOR_DEVICE_DONE != status)
        {
          PVL_LOG_ERROR("%s: Error, no partition found for guid '%s'\r\n", __func__, erase_write_guid);
          break;
        }

        block_size_bytes  = memInfo->pages_per_block * memInfo->page_size_bytes;
        erase_start_block = partition_base / block_size_bytes;
        if(partition_size > CD_PARTITION_SIZE)
            partition_size= CD_PARTITION_SIZE;

        erase_block_count = partition_size/ block_size_bytes;

        status = spinorEl2Erase (handle, erase_start_block, erase_block_count);
        if ( SPINOR_DEVICE_DONE != status)
        {
          PVL_LOG_ERROR("%s: Error, erase failed. start_block = 0x%x, block_count = 0x%x, block_size = 0x%x\r\n",
                        __func__, erase_start_block, erase_block_count, block_size_bytes);
          break;
        }

        erase_count++;

        //////////////////////////////////////////
        status = write_kpi_test(handle, memInfo, erase_write_guid, 1024U, &gSpinorKPIValues.write_kpi_1KB);
        if (SPINOR_DEVICE_DONE != status)
        {
           PVL_LOG_ERROR("%s: Error, 1KB write KPI test failed, status = %d\r\n", __func__, status);
           break;
        }

        //////////////////Need to erase again before write back again with 4KB
        status = spinorEl2Erase (handle, erase_start_block, erase_block_count);
        if ( SPINOR_DEVICE_DONE != status)
        {
          PVL_LOG_ERROR("%s: Error, erase failed. start_block = 0x%x, block_count = 0x%x, block_size = 0x%x\r\n",
                        __func__, erase_start_block, erase_block_count, block_size_bytes);
          break;
        }

        erase_count++;

        //////////////////////////////////////////
        status = write_kpi_test(handle, memInfo, erase_write_guid, 4096U, &gSpinorKPIValues.write_kpi_4KB);
        if (SPINOR_DEVICE_DONE != status)
        {
          PVL_LOG_ERROR("%s: Error, 4KB write KPI test failed, status = %d\r\n", __func__, status);
          break;
        }

        PVL_LOG_WARNING("%s: Avg time taken for :32KB_read = %ld us, 4KB_read = %ld us, 256B_read = %ld us, %dKB_erase = %ld us, 256B_write = %ld us, 1KB_write = %ld us, 4KB_write = %ld us\r\n",
                     __func__, (long)gSpinorKPIValues.read_kpi_32KB, (long)gSpinorKPIValues.read_kpi_4KB,  (long)gSpinorKPIValues.read_kpi_256B, max_er_size,
                     (long)gSpinorKPIValues.erase_kpi, (long)gSpinorKPIValues.write_kpi_256B,
                     (long)gSpinorKPIValues.write_kpi_1KB, (long)gSpinorKPIValues.write_kpi_4KB);

        gSpinorPerfValues.read_perf_32KB = (32 * 1024)/gSpinorKPIValues.read_kpi_32KB; /* in MBps */
        gSpinorPerfValues.read_perf_4KB = (4 * 1024)/gSpinorKPIValues.read_kpi_4KB; /* in MBps */
        gSpinorPerfValues.read_perf_256B = 256/gSpinorKPIValues.read_kpi_256B; /* in MBps */
        gSpinorPerfValues.erase_perf = (max_er_size * 1024 * 1000)/gSpinorKPIValues.erase_kpi; /* in Kbps */
        gSpinorPerfValues.write_perf_256B = (256 * 1000)/gSpinorKPIValues.write_kpi_256B; /* in Kbps */
        gSpinorPerfValues.write_perf_1KB = (1 * 1024 * 1000)/gSpinorKPIValues.write_kpi_1KB; /* in Kbps */
        gSpinorPerfValues.write_perf_4KB = (4 * 1024 * 1000)/gSpinorKPIValues.write_kpi_4KB; /* in Kbps */

        PVL_LOG_WARNING("%s: KPI for :32KB_read = %d MB/s, 4KB_read = %d MB/s,  256B_read = %d MB/s, %dKB_erase = %d KB/s, 256B_write = %d KB/s, 1KB_write = %d KB/s, 4KB_write = %d KB/s\r\n",
                     __func__, gSpinorPerfValues.read_perf_32KB, gSpinorPerfValues.read_perf_4KB, gSpinorPerfValues.read_perf_256B,
                     max_er_size, gSpinorPerfValues.erase_perf, gSpinorPerfValues.write_perf_256B,
                     gSpinorPerfValues.write_perf_1KB, gSpinorPerfValues.write_perf_4KB);

        PVL_LOG_WARNING("%s: Completed PVL read_erase_write_kpi_test\r\n", __func__);

    } while (FALSE);

    return status;
}


static SPINOR_STATUS basic_flash_read_write_erase_test(spinor_handle_t handle, struct spinor_info* memInfo, const char *guid)
{
  SPINOR_STATUS status;
  uint32_t erase_start_block;
  uint32_t erase_block_count;
  uint32_t block_size_bytes;
  uint32_t partition_base;
  uint32_t partition_size;
  uint8_t* wr_offset;
  uint32_t i;
  uint32_t loop_count;
  uint32_t offset;

  do
  {
    PVL_LOG_WARNING("%s: started PVL basic_flash_read_write_erase_test, taking few moments to read/erase/write \r\n", __func__);
    status = spinorEl2GetGptPartitionInfo( handle, guid, &partition_base, &partition_size);
    if ( SPINOR_DEVICE_DONE != status)
    {
      PVL_LOG_ERROR("%s: Error, no partition found for guid '%s'\r\n", __func__, guid);
      break;
    }

    block_size_bytes  = memInfo->pages_per_block * memInfo->page_size_bytes;
    erase_start_block = partition_base / block_size_bytes;
    if(partition_size > CD_PARTITION_SIZE)
        partition_size= CD_PARTITION_SIZE;

    erase_block_count = partition_size/ block_size_bytes;

    status = spinorEl2Erase (handle, erase_start_block, erase_block_count);
    if ( SPINOR_DEVICE_DONE != status)
    {
      PVL_LOG_ERROR("%s: Error, erase failed. start_block = 0x%x, block_count = 0x%x, block_size = 0x%x\r\n",
                    __func__, erase_start_block, erase_block_count, block_size_bytes);
      break;
    }

    erase_count++;

    memset(ucReadBuf, READ_BYTE_PATTERN, PVL_READ_BUF_SIZE);
    memset(ucwriteBuf, ERASE_BYTE_PATTERN, PVL_READ_BUF_SIZE);

    loop_count = partition_size / PVL_READ_BUF_SIZE;

    for (i = 0; i < loop_count; i++)
    {
      offset = partition_base + i * PVL_READ_BUF_SIZE;
      status = spinorEl2Read ( handle, offset, PVL_READ_BUF_SIZE, ucReadBuf);
      if ( SPINOR_DEVICE_DONE != status)
      {
        PVL_LOG_ERROR("%s: Error, read after erase failed. start_addr = 0x%x, size  = 0x%x\r\n", __func__, offset, PVL_READ_BUF_SIZE);
        break;
      }

      if (memcmp(ucReadBuf, ucwriteBuf, PVL_READ_BUF_SIZE))
      {
        /* read and write data are different */
        PVL_LOG_ERROR("%s: Error, read data after erase inconsistent at offset=0x%x and size=0x%x\r\n", __func__, offset, PVL_READ_BUF_SIZE);
        status = SPINOR_DEVICE_FAIL;
        break;
      }
    }

    loop_count = partition_size / PVL_WRITE_BUF_SIZE;
    for (i = 0; i < loop_count; i++)
    {
      offset = partition_base + i * PVL_WRITE_BUF_SIZE;
      wr_offset = swaADdr + i * PVL_WRITE_BUF_SIZE;
      status = spinorEl2Write ( handle, offset, PVL_WRITE_BUF_SIZE, wr_offset);
      if ( SPINOR_DEVICE_DONE != status)
      {
        PVL_LOG_ERROR("%s: Error, write failed. start_addr = 0x%x, size  = 0x%x\r\n", __func__, offset, PVL_WRITE_BUF_SIZE);
        break;
      }

      memset(ucReadBuf, ERASE_BYTE_PATTERN, PVL_WRITE_BUF_SIZE);

      status = spinorEl2Read ( handle, offset, PVL_WRITE_BUF_SIZE, ucReadBuf);
      if ( SPINOR_DEVICE_DONE != status)
      {
        PVL_LOG_ERROR("%s: Error, read failed. start_addr = 0x%x, size  = 0x%x\r\n", __func__, offset, PVL_WRITE_BUF_SIZE);
        break;
      }
      if (memcmp(ucReadBuf, swaADdr+i * PVL_WRITE_BUF_SIZE, PVL_WRITE_BUF_SIZE))
      {
        /* read and write data are different */
        PVL_LOG_ERROR("%s: Error, read data and write comparison failed for offset=0x%x and size=0x%x\r\n", __func__, offset, PVL_WRITE_BUF_SIZE);
        status = SPINOR_DEVICE_FAIL;
        break;
      }
    }

    /* Increment Write count after sweeping through 1MB of the partition with writes */
    write_count++;

    PVL_LOG_WARNING("%s: erase, write and read basic tests done\r\n", __func__);

  }while (FALSE);

  return status;
}

static int32_t stress_test_one(spinor_handle_t handle, struct spinor_info* memInfo, uint32_t dur_usec,
                               const char *read4k_guid, const char *erase_write_guid, const char *read32k_guid,
                               boolean write_test, boolean erase_test, boolean read_test, uint32_t ulWaitUs)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
    uint32_t partition_base = 0, partition_size = 0, offset = 0, block_size_bytes = 0, erase_start_block = 0, erase_block_count = 0,loop_count=0;
    int64 timeout = 0, timeout_init = 0;
    uint64_t start_time = 0, end_time = 0, delta = 0;
    int i;
    uint8_t* wr_offset;
    timeout = dur_usec;
    timeout_init = timeout;

    /* Note: erase, read (check FF), write, read (check write), read32k, read4k */

    while (timeout > 0)
    {
        start_time = 0;
        end_time = 0;
        delta = 0;

        //measure start time
        El2PerfTestSetTimestamp(&start_time);

        status = spinor_pvl_exit_powder_down();
        if ( SPINOR_DEVICE_DONE != status)
        {
            PVL_LOG_ERROR("%s: Error, cannot exit low power, status = %d\r\n", __func__, status);
            break;
        }

        status = spinorEl2GetGptPartitionInfo( handle, erase_write_guid, &partition_base, &partition_size);
        if ( SPINOR_DEVICE_DONE != status)
        {
            PVL_LOG_ERROR("%s: Error, no partition found for guid '%s'\r\n", __func__, erase_write_guid);
            break;
        }

        offset = partition_base;
        partition_size = (partition_size>CD_PARTITION_SIZE)?CD_PARTITION_SIZE:partition_size;

        block_size_bytes  = memInfo->pages_per_block * memInfo->page_size_bytes;
        erase_start_block = partition_base / block_size_bytes;
        erase_block_count = partition_size / block_size_bytes;

        memset(ucwriteBuf, ERASE_BYTE_PATTERN, PVL_WRITE_BUF_SIZE);

        if (erase_test || write_test)
        {
            status = spinorEl2Erase (handle, erase_start_block, erase_block_count);
            if ( SPINOR_DEVICE_DONE != status)
            {
                status = SPINOR_DEVICE_FAIL;
                break;
            }
            erase_count++;

            for (i = 0; i < erase_block_count; i++)
            {
                memset(ucReadBuf, READ_BYTE_PATTERN, PVL_WRITE_BUF_SIZE);
                status = spinorEl2Read (handle, offset+i*PVL_WRITE_BUF_SIZE, PVL_WRITE_BUF_SIZE, ucReadBuf);
                if ( SPINOR_DEVICE_DONE != status)
                {
                    PVL_LOG_ERROR("%s: Error, Read after erase failed at offset=0x%x and size=0x%x \r\n", __func__, offset+i*PVL_WRITE_BUF_SIZE, PVL_WRITE_BUF_SIZE);
                    status = SPINOR_DEVICE_FAIL;
                    break;
                }

                if (memcmp(ucReadBuf, ucwriteBuf, PVL_WRITE_BUF_SIZE))
                {
                    /* read and erase data are different */
                    PVL_LOG_ERROR("%s: Error, erase data inconsistent at offset=0x%x and size=0x%x \r\n", __func__, offset+i*PVL_WRITE_BUF_SIZE, PVL_WRITE_BUF_SIZE);
                    status = SPINOR_DEVICE_FAIL;
                    break;
                }
            }
        }

        if (write_test)
        {
          for (i = 0; i < erase_block_count; i++)
          {
            wr_offset = swaADdr + i * PVL_WRITE_BUF_SIZE;
            status = spinorEl2Write (handle, (offset+i*PVL_WRITE_BUF_SIZE), PVL_WRITE_BUF_SIZE, wr_offset);
            if ( SPINOR_DEVICE_DONE != status)
            {
                PVL_LOG_ERROR("%s: Error, Write failed for offset=0x%x and size=0x%x \r\n", __func__, (offset+i*PVL_WRITE_BUF_SIZE), PVL_WRITE_BUF_SIZE);
                status = SPINOR_DEVICE_FAIL;
                break;
            }

            memset(ucReadBuf, READ_BYTE_PATTERN, PVL_WRITE_BUF_SIZE);
            status = spinorEl2Read (handle, (offset + i * PVL_WRITE_BUF_SIZE), PVL_WRITE_BUF_SIZE, ucReadBuf);
            if ( SPINOR_DEVICE_DONE != status)
            {
                PVL_LOG_ERROR("%s: Error, Read failed for offset=0x%x and size=0x%x \r\n", __func__, (offset+i*PVL_WRITE_BUF_SIZE), PVL_WRITE_BUF_SIZE);
                status = SPINOR_DEVICE_FAIL;
                break;
            }

            if (memcmp(ucReadBuf, wr_offset, PVL_WRITE_BUF_SIZE))
            {
                /* read and write data are different */
                PVL_LOG_ERROR("%s: Error, write data inconsistent at offset=0x%x and size=0x%x \r\n", __func__, (offset+i*PVL_WRITE_BUF_SIZE), PVL_WRITE_BUF_SIZE);
                status = SPINOR_DEVICE_FAIL;
                break;
            }
          }
          write_count += 1;
        }
        if (read_test)
        {
            /* 32KB read test */
            status = spinorEl2GetGptPartitionInfo( handle, erase_write_guid, &partition_base, &partition_size);
            if ( SPINOR_DEVICE_DONE != status)
            {
                PVL_LOG_ERROR("%s: Error, 32KB read, no partition found for guid '%s'\r\n", __func__, erase_write_guid);
                break;
            }
            offset = partition_base;
            partition_size = (partition_size>CD_PARTITION_SIZE)?CD_PARTITION_SIZE:partition_size;
            block_size_bytes  = memInfo->pages_per_block * memInfo->page_size_bytes;
            erase_start_block = partition_base / block_size_bytes;
            erase_block_count = partition_size / block_size_bytes;

            loop_count = partition_size/PVL_READ_BUF_SIZE;

            for (i = 0; i < loop_count; i++)
            {
                memset(ucReadBuf, READ_BYTE_PATTERN, PVL_READ_BUF_SIZE);

                status = spinorEl2Read (handle, offset+i*PVL_READ_BUF_SIZE, PVL_READ_BUF_SIZE, ucReadBuf);
                if ( SPINOR_DEVICE_DONE != status)
                {
                    status = SPINOR_DEVICE_FAIL;
                    PVL_LOG_ERROR("%s: Error, 32KB read error at offset =0x%x status = %d\r\n", __func__, offset+i*PVL_READ_BUF_SIZE, status);
                    break;
                }

                if (memcmp(ucReadBuf, swaADdr + i * PVL_READ_BUF_SIZE, PVL_READ_BUF_SIZE))
                {
                    /* read data mismatch */
                    PVL_LOG_ERROR("%s: Error, Read data mismatch at offset=0x%x and size=0x%x \r\n", __func__, offset+i*PVL_READ_BUF_SIZE, PVL_READ_BUF_SIZE);
                    status = SPINOR_DEVICE_FAIL;
                    break;
                }

            }

            /* 4KB read test */
            loop_count = erase_block_count;
            for (i = 0; i < loop_count; i++)
            {
              memset(ucReadBuf, READ_BYTE_PATTERN, PVL_WRITE_BUF_SIZE);
              status = spinorEl2Read (handle, (offset + i * PVL_WRITE_BUF_SIZE), PVL_WRITE_BUF_SIZE, ucReadBuf);
              if ( SPINOR_DEVICE_DONE != status)
              {
                status = SPINOR_DEVICE_FAIL;
                PVL_LOG_ERROR("%s: Error, 4KB read error at offset=0x%x status = %d\r\n", __func__, offset+i*PVL_WRITE_BUF_SIZE, status);
                break;
              }

              if (memcmp(ucReadBuf, swaADdr + i * PVL_WRITE_BUF_SIZE, PVL_WRITE_BUF_SIZE))
              {
                  /* read data mismatch */
                  PVL_LOG_ERROR("%s: Error, Read data mismatch at offset=0x%x and size=0x%x \r\n", __func__, offset+i*PVL_WRITE_BUF_SIZE, PVL_WRITE_BUF_SIZE);
                  status = SPINOR_DEVICE_FAIL;
                  break;
              }
            }

        }

        if (erase_test == 1 && write_test == 0 && read_test == 0)
        {
          for (i = 0; i < erase_block_count; i++)
          {
            wr_offset = swaADdr + i * PVL_WRITE_BUF_SIZE;
            status = spinorEl2Write (handle, (offset+i*PVL_WRITE_BUF_SIZE), PVL_WRITE_BUF_SIZE, wr_offset);
            if ( SPINOR_DEVICE_DONE != status)
            {
                PVL_LOG_ERROR("%s: Error, NEW WRITE failed for offset=0x%x and size=0x%x \r\n", __func__, (offset+i*PVL_WRITE_BUF_SIZE), PVL_WRITE_BUF_SIZE);
                status = SPINOR_DEVICE_FAIL;
                break;
            }
          }
        }

        status = spinor_pvl_enter_powder_down();
        if ( SPINOR_DEVICE_DONE != status)
        {
            status = SPINOR_DEVICE_FAIL;
            PVL_LOG_ERROR("%s: Error, cannot enter low power, status = %d\r\n", __func__, status);
            break;
        }

        //measure end time
        //subtract delta
        if (ulWaitUs)
        {
            busywait(ulWaitUs);
        }
        El2PerfTestSetTimestamp(&end_time);
        El2PerfTestSetDuration(start_time, end_time, &delta);
        timeout -= delta;
    }

    status = spinor_pvl_exit_powder_down();
    if ( SPINOR_DEVICE_DONE != status)
    {
        PVL_LOG_ERROR("%s: Error, cannot exit low power at the end of the func, status = %d\r\n", __func__, status);
        return status;
    }
    return status;
}

static int slPvlStressTest(spinor_handle_t handle, spinorMemInfoType *memInfo,
                           boolean write_test, boolean erase_test,
                           boolean read_test, uint32_t  ulStressDurMin, uint32_t ulWaitUs)
{
  int32_t ret = 0;
  uint64_t ulStartTick = 0, ulEndTick = 0, ulCur = 0,deltaTime = 0;
  uint32_t ulIntervalUs = 1 * 60 * 1000000;   /* hard code each loop interval to be one minute */
  uint32_t ulLoop = 1, duration_lapsed_mins = 0;
  //uint32_t ulStartTick_low = 0, ulStartTick_hi = 0, ulEndTick_low = 0, ulEndTick_hi = 0;

  //get the start tick
  //PVL_LOG_WARNING("%s: ulStressDurMin = %d\r\n",__func__, ulStressDurMin);
  El2PerfTestSetTimestamp(&ulStartTick);
  //ulStartTick_low = (uint32_t)ulStartTick;
  //ulStartTick_hi = (uint32_t)(ulStartTick >> 32);
  //PVL_LOG_WARNING("%s: starttime ulStartTick = %llu\r\n",__func__, (unsigned long long)ulStartTick);
  //PVL_LOG_WARNING("%s: starttime ulStartTick_low = 0x%x, ulStartTick_hi = 0x%x\r\n",__func__, ulStartTick_low, ulStartTick_hi);
  uint64_t duration = (uint64_t)ulStressDurMin*60*1000000;
  deltaTime = El2PerfTestDurationToTick(duration);
  ulEndTick = ulStartTick + deltaTime;
  //ulEndTick_low = (uint32_t)ulEndTick;
  //ulEndTick_hi = (uint32_t)(ulEndTick >> 32);
  //PVL_LOG_WARNING("%s: starttime ulEndTick_low = 0x%x, ulEndTick_hi = 0x%x\r\n",__func__, ulEndTick_low, ulEndTick_hi);
  //ulEndTick = ulStartTick + El2PerfTestDurationToTick(ulStressDurMin*60*1000000);
  //PVL_LOG_WARNING("%s: deltaTime = %llu\r\n",__func__, (unsigned long long)deltaTime);
  //PVL_LOG_WARNING("%s: Endtime ulEndTick = %llu\r\n",__func__, (unsigned long long)ulEndTick);
  PVL_LOG_WARNING("%s: PVL stress test START\r\n",__func__);

  do {
    ret = stress_test_one(handle, memInfo, ulIntervalUs,
                          PVL_KPI_RAM_DUMP_GUID, PVL_KPI_RAM_DUMP_GUID, PVL_KPI_RAM_DUMP_GUID,
                          write_test, erase_test, read_test, ulWaitUs);
    El2PerfTestSetTimestamp(&ulCur);
    El2PerfTestSetDuration(ulStartTick, ulCur, &deltaTime);
    duration_lapsed_mins = (deltaTime/(1000000))/60;
    if (ret != 0)
    {
      /* error */
      PVL_LOG_ERROR("%s: PVL stress test FAIL, %d minutes elapsed, %d iterations completed , erase_count = %d, write_count = %d\r\n",
                 __func__, duration_lapsed_mins, ulLoop, erase_count, write_count);
      break;
    }
    ret = read_erase_write_kpi_test(handle, memInfo, PVL_KPI_RAM_DUMP_GUID, PVL_KPI_RAM_DUMP_GUID);
    El2PerfTestSetTimestamp(&ulCur);
    El2PerfTestSetDuration(ulStartTick, ulCur, &deltaTime);
    duration_lapsed_mins = (deltaTime/(1000000))/60;
    //PVL_LOG_WARNING("%s: Currenttimestamp ulCur = %lld\r\n",__func__, (long)(long)ulCur);
    if (ret != 0)
    {
      /* error */
      PVL_LOG_ERROR("%s: PVL kpi test FAIL, %d minutes elapsed, %d iterations completed, erase_count = %d, write_count = %d\r\n",
                 __func__, duration_lapsed_mins, ulLoop, erase_count, write_count);
      break;
    }
    if (ulCur > ulEndTick)
    {
      /* we finished all duration */
      break;
    }
    PVL_LOG_WARNING("%s: PVL stress test for %d minute PASS\r\n",
                 __func__, duration_lapsed_mins);
    PVL_LOG_WARNING("%s: PVL stress test running, %d minutes elapsed, %d iterations completed, erase_count = %d, write_count = %d\r\n",
                 __func__, duration_lapsed_mins, ulLoop, erase_count, write_count);
    ulLoop++;
  } while (1);
  if (ret == 0)
  {
    PVL_LOG_WARNING("%s: PVL stress test DONE, for %d minutes, %d iterations completed, erase_count = %d, write_count = %d\r\n",
                 __func__, duration_lapsed_mins, ulLoop, erase_count, write_count);
  }
  else
  {
    PVL_LOG_ERROR("%s: PVL stress test error, ret = %d, minutes = %d, iterations =  %d, erase_count = %d, write_count = %d\r\n",
                  __func__, ret, duration_lapsed_mins, ulLoop, erase_count, write_count);
  }
  return ret;
}

static int32_t pvl_sailhyp_xbl_test_1(void)
{
    int nRet = XBL_ERROR;
    uint32_t count = 1;
    xbl_boot_params_t bootparam;
    uint8_t coreId = get_curr_phys_cpu_num();
    uint8_t success_count = 0;
    uint8_t failure_count = 0;
    extern int sailhyp_xbl_boot_elfs(xbl_boot_params_t *boot_params, uint32_t count);

    PVL_LOG_WARNING("%s Begin of XBL test\n\r", __func__);

        memset(&bootparam, 0, sizeof(bootparam));
        bootparam.boot_option = XBL_BOOT_OPTION_MANDATORY;
        bootparam.image_id    = XBL_IMAGE_ID_SW1;
        PVL_LOG_WARNING("%s: call to load image_id = %d, option = %d\n\r", __func__, bootparam.image_id, bootparam.boot_option);
        nRet = sailhyp_xbl_boot_elfs (&bootparam, count);
        if (nRet)
        {
            if (nRet == XBL_ERROR_INVALID_ELF)
            {
                PVL_LOG_ERROR("%s: Error - No ELF image or corrupted ELF. core_id = %d, sw image_id = %d, status = %d\n\r",
                              __func__, coreId, XBL_IMAGE_ID_SW1, nRet);
            }
            else
            {
            PVL_LOG_ERROR("%s: Error in ELF loading. core_id = %d, image_id = %d, status = %d\n\r",
                          __func__, coreId, XBL_IMAGE_ID_SW1, nRet);
            }
        }
        else
        {
            PVL_LOG_WARNING("%s: core_id = %d, swimage_id = %d, ELF loading successful\n\r",
                         __func__, coreId, XBL_IMAGE_ID_SW1, nRet);
        }

    PVL_LOG_WARNING("%s End, core_id = %d, success_count = %d, failure_count = %d, ret = %d\n\r",
                 __func__, coreId, success_count, failure_count, nRet);

    return nRet;
}

extern boot_pbl_shared_data_type g_pbl_shared_info;

static int32_t slPvlRunOne(spinor_hardcode_data_mode *test_mode_params, int32_t slBusFreqKhz, uint8_t ucKpi, uint8_t ucStress, uint32_t  ulMininutes, uint32_t ulWaitUs, char* eval_mode, boolean kpi_mode_peak)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
  spinor_handle_t handle = NULL;
  int32_t type = SPINOR_INIT_TYPE_DEFAULT;
  static spinorMemInfoType memInfo = {0U};
  boolean write_test = FALSE, erase_test = FALSE, read_test = FALSE;
  uint64_t delta_stress = 0, start_time_stress = 0, end_time_stress = 0;
  int64 timeout = 0, timeout_init = 0;
  int32_t retval;
  boolean eval_run_mode_sanity = FALSE, eval_run_mode_boot = FALSE, eval_run_mode_stress = FALSE;

  if(sailbsp_stricmp("sanity",(char*)eval_mode))
  {
      eval_run_mode_sanity = TRUE;
  }
  else if(sailbsp_stricmp("boot",(char*)eval_mode))
  {
      eval_run_mode_boot = TRUE;
  }
  else if(sailbsp_stricmp("stress",(char*)eval_mode))
  {
      eval_run_mode_stress = TRUE;
  }

  do
  {
    status = flash_init_open_and_get_mem_info(&handle, type, &g_test_mode_params, &memInfo, SPINOR_USER_TYPE_EL2);
    if (SPINOR_DEVICE_DONE != status)
    {
      PVL_LOG_ERROR("%s: Error, flash_init_open_and_get_mem_info failed \r\n", __func__);
      break;
    }

    status = basic_flash_read_write_erase_test(handle, &memInfo, PVL_KPI_RAM_DUMP_GUID);
    if (SPINOR_DEVICE_DONE != status)
    {
      PVL_LOG_ERROR("%s: Error, basic_flash_read_write_erase_test failed \r\n", __func__);
      break;
    }

    /* Add erase, write and read test */
    if (ucKpi == KPI_ENABLE)
    {

#if 0
      /*  To measure the KPI  with additional delays similar to mission mode scheduling delays uncomment the if0
      and tune the delay params */
      if(kpi_mode_peak == FALSE)
      {
        PVL_LOG_WARNING("%s: PVL changing spinor config params \r\n", __func__);
        #ifdef NORPVL_ENB
        extern SPINOR_STATUS spinor_change_params(uint32 thread_delay_us, uint32_t max_tranfr_pg_size);
        status = spinor_change_params(1000, 16);
        #endif
        if (SPINOR_DEVICE_DONE != status)
        {
          break;
        }
      }
#endif
      /* Measure 4KB and 32KB read performance */
      status = read_erase_write_kpi_test(handle, &memInfo, PVL_KPI_RAM_DUMP_GUID, PVL_KPI_RAM_DUMP_GUID);
      if (SPINOR_DEVICE_DONE != status)
      {
        break;
      }
    }

    if((eval_run_mode_boot || eval_run_mode_stress))
    {
        if ((true == xblloadtest) )
        {
            extern int sailhyp_xbl_init(boot_pbl_shared_data_type*);
            if(false == xblInitialized)
            {
                retval = sailhyp_xbl_init(&g_pbl_shared_info);
                if (0 != retval )
                {
                    /* TBD: Need to reboot is this failed */
                    retval *= -1;
                    PVL_LOG_ERROR("%s: PVL xbl init error, status = %d\r\n", __func__, retval);
                    xblInitialized = false;
                    status = SPINOR_DEVICE_FAIL;
                    break;
                }
                xblInitialized = true;
            }

            if(true == xblInitialized)
            {
              //extern int pvl_sailhyp_xbl_test1(void);
              retval = pvl_sailhyp_xbl_test_1();

              if (0 != retval )
              {
                retval *= -1;
                PVL_LOG_ERROR("%s: PVL xbl test error, status = %d\r\n", __func__, retval);
                status = SPINOR_DEVICE_FAIL;
                break;
              }
            }
            else
            {
                PVL_LOG_WARNING("%s: PVL xbl test warning, XBL not initialized.Skipping XBL test \r\n", __func__);
            }
        }

    }
    if(eval_run_mode_stress)
    {
        if(ucStress == RD_WR_ER_STRESS_TEST ||
           ucStress == READ_STRESS_TEST ||
           ucStress == WRITE_STRESS_TEST ||
           ucStress == ERASE_STRESS_TEST)
          {
              if(ucStress == RD_WR_ER_STRESS_TEST)
              {
                erase_test = TRUE;
                write_test = TRUE;
                read_test = TRUE;
              }
              else if (ucStress == READ_STRESS_TEST)
              {
                read_test = TRUE;
              }
              else if(ucStress == WRITE_STRESS_TEST)
              {
                erase_test = TRUE;
                write_test = TRUE;
              }
              else if(ucStress == ERASE_STRESS_TEST)
              {
                erase_test = TRUE;
              }
              else
              {
                /* Error case. Not supported stress option */
                status = SPINOR_DEVICE_FAIL;
                PVL_LOG_ERROR("%s: PVL stress test error, status = %d\r\n", __func__, status);
                break;
              }
              status = slPvlStressTest(handle, &memInfo, write_test, erase_test, read_test, ulMininutes, ulWaitUs);
          }
    }
  } while (0U);
  return status;
}

static int32_t slPvlRunTestWithModeInput(int32_t slBusFreqKhz, uint8_t ucKpi, uint8_t ucStress, uint32_t  ulMininutes,
                           uint32_t dqs, uint32_t read_mode, uint32_t write_mode, boolean use_pbl, uint32_t ulWaitUs, boolean kpi_mode_peak)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

  PVL_LOG_WARNING("%s: BEGIN, buf_freq_khz = %d, ucKpi = %d, ucStress = %d, ulMininutes = %d, read_mode = %d, write_mode = %d\r\n",
               __func__, slBusFreqKhz, ucKpi, ucStress, ulMininutes, read_mode, write_mode);

  init_global_params();
  do
  {
    if (read_mode != DDR_8_8_8_MODE && read_mode != SDR_1_1_4_MODE && slBusFreqKhz == 0U)
    {
      PVL_LOG_ERROR("%s: NOR_PVL Error, slBusFreqKhz is 0\r\n", __func__);
      break;
    }

    g_test_mode_params.hardcode_dqs                            = dqs;
    g_test_mode_params.hardcode_read_mode                      = read_mode;  //such as SDR_1_1_1_MODE;
    g_test_mode_params.hardcode_write_mode                     = write_mode; //such as SDR_1_1_1_MODE;
    g_test_mode_params.hardcode_bus_clk_khz                    = slBusFreqKhz;

#if 0
    if(read_mode == SDR_1_1_4_MODE || read_mode == SDR_1_4_4_MODE || read_mode == SDR_1_1_8_MODE || read_mode == SDR_1_8_8_MODE || read_mode == SDR_1_1_1_MODE)
    {
        g_test_mode_params.hardcode_no_data_read_dummy_cycle_recfg = 1;
    }
    else
    {
        g_test_mode_params.hardcode_no_data_read_dummy_cycle_recfg = 0;
    }
#endif
    g_test_mode_params.use_pbl                    = use_pbl;

    /* If the SPI bus clock is half of PBL's core freq disable dummy cycle reconfiguration */
    g_test_mode_params.hardcode_no_data_read_dummy_cycle_recfg = (use_pbl || (read_mode == SDR_1_1_4_MODE || read_mode == SDR_1_4_4_MODE || read_mode == SDR_1_1_8_MODE || read_mode == SDR_1_8_8_MODE || read_mode == SDR_1_1_1_MODE))?1:0 ; //(slBusFreqKhz > (PVL_PBL_CORE_CLOCK_KHZ / 2) ) ? 0: 1;

    PVL_LOG_WARNING("%s: buf_freq_khz = %d, read 111_SDR, write 111_SDR, no dummy cycle recfg, NDQS\r\n", __func__, slBusFreqKhz);

    status = slPvlRunOne(&g_test_mode_params, slBusFreqKhz, ucKpi, ucStress, ulMininutes, ulWaitUs, "stress", kpi_mode_peak); //stress option is paased for the eval_mode, since slPvlRunTestWithModeInput is called for different stress modes
  } while (0U);


  //Prerana: call El2Deinit to clean up
  /* Deinit the spinor EL2 */
  spinorEl2DeInit(SPINOR_INIT_TYPE_DEFAULT);

  if(status != 0)
  {
    PVL_LOG_ERROR("%s: error END, status = %d\r\n", __func__, status);
  }
  else
  {
    PVL_LOG_WARNING("%s: END, status = %d\r\n", __func__, status);
  }
  return status;
}

static int32_t slPvlRunTestMissionMode(uint8_t ucKpi, uint8_t ucStress, uint32_t  ulMininutes, uint32_t ulWaitUs, char* eval_mode, boolean kpi_mode_peak)
{
  int32_t slBusFreqKhz = 0U;
  int32_t slRet = NOR_PVL_RET_ERROR;

  PVL_LOG_WARNING("%s: BEGIN, ucKpi = %d, ucStress = %d, ulMininutes = %d\r\n",
               __func__, ucKpi, ucStress, ulMininutes);

  do
  {
    init_global_params();
    slRet = slPvlRunOne(&g_test_mode_params, slBusFreqKhz, ucKpi, ucStress, ulMininutes, ulWaitUs, eval_mode, kpi_mode_peak);
  } while (0U);

  spinorEl2DeInit(SPINOR_INIT_TYPE_DEFAULT);
  if (slRet != NOR_PVL_RET_SUCCESS)
  {
    PVL_LOG_ERROR("%s: Error END, status = %d\r\n", __func__, slRet);
  }
  else
  {
    PVL_LOG_WARNING("%s: END, status = %d\r\n", __func__, slRet);
  }
  return slRet;
}

static int32_t slPvlRun888D_888D(int32_t slBusFreqKhz, uint8_t ucKpi, uint8_t ucStress, uint32_t  ulMininutes, uint32_t ulWaitUs, boolean kpi_mode_peak)
{
  int32_t slRet = NOR_PVL_RET_ERROR;

  /* If input freq is zero, the etst will not hard code
   * mission mode configuration and let the spinor driver to choose. */
  if (slBusFreqKhz == 0)
  {
    slRet = slPvlRunTestMissionMode(ucKpi, ucStress, ulMininutes, ulWaitUs, "stress", kpi_mode_peak);
  }
  else
  {
    uint32_t dqs = (slBusFreqKhz > DLL_LOW_FREQ_KHZ) ? BUS_USE_DQS : BUS_NO_DQS;

    slRet = slPvlRunTestWithModeInput(slBusFreqKhz, ucKpi, ucStress, ulMininutes, dqs, DDR_8_8_8_MODE, DDR_8_8_8_MODE, 0, ulWaitUs, kpi_mode_peak);
  }
  if (slRet != NOR_PVL_RET_SUCCESS)
  {
    PVL_LOG_ERROR("%s: END error, status = %d\r\n", __func__, slRet);
  }
  return slRet;
}

static int32_t slPvlRun888S_888S(int32_t slBusFreqKhz, uint8_t ucKpi, uint8_t ucStress, uint32_t  ulMininutes, uint32_t ulWaitUs, boolean kpi_mode_peak)
{
  uint32_t dqs = (slBusFreqKhz > DLL_LOW_FREQ_KHZ) ? BUS_USE_DQS : BUS_NO_DQS;
  return slPvlRunTestWithModeInput(slBusFreqKhz, ucKpi, ucStress, ulMininutes, dqs, SDR_8_8_8_MODE, SDR_8_8_8_MODE, 0, ulWaitUs, kpi_mode_peak);
}

static int32_t slPvlRun188S_111S(int32_t slBusFreqKhz, uint8_t ucKpi, uint8_t ucStress, uint32_t  ulMininutes, boolean use_pbl, uint32_t ulWaitUs, boolean kpi_mode_peak)
{
  return slPvlRunTestWithModeInput(slBusFreqKhz, ucKpi, ucStress, ulMininutes, BUS_NO_DQS, SDR_1_8_8_MODE, SDR_1_1_1_MODE, use_pbl, ulWaitUs, kpi_mode_peak);
}

static int32_t slPvlRun118S_111S(int32_t slBusFreqKhz, uint8_t ucKpi, uint8_t ucStress, uint32_t  ulMininutes, boolean use_pbl, uint32_t ulWaitUs, boolean kpi_mode_peak)
{
  return slPvlRunTestWithModeInput(slBusFreqKhz, ucKpi, ucStress, ulMininutes, BUS_NO_DQS, SDR_1_1_8_MODE, SDR_1_1_1_MODE, use_pbl, ulWaitUs, kpi_mode_peak);
}

static int32_t slPvlRun444D_444D(int32_t slBusFreqKhz, uint8_t ucKpi, uint8_t ucStress, uint32_t  ulMininutes, uint32_t ulWaitUs, boolean kpi_mode_peak)
{
  return slPvlRunTestWithModeInput(slBusFreqKhz, ucKpi, ucStress, ulMininutes, BUS_NO_DQS, DDR_4_4_4_MODE, DDR_4_4_4_MODE, 0, ulWaitUs, kpi_mode_peak);
}

static int32_t slPvlRun444S_444S(int32_t slBusFreqKhz, uint8_t ucKpi, uint8_t ucStress, uint32_t ulMininutes, uint32_t ulWaitUs, boolean kpi_mode_peak)
{
  return slPvlRunTestWithModeInput(slBusFreqKhz, ucKpi, ucStress, ulMininutes, BUS_NO_DQS, SDR_4_4_4_MODE, SDR_4_4_4_MODE, 0, ulWaitUs, kpi_mode_peak);
}

static int32_t slPvlRun144S_144S(int32_t slBusFreqKhz,uint8_t ucKpi, uint8_t ucStress, uint32_t  ulMininutes, boolean use_pbl, uint32_t ulWaitUs, boolean kpi_mode_peak)
{
  return slPvlRunTestWithModeInput(slBusFreqKhz, ucKpi, ucStress, ulMininutes, BUS_NO_DQS, SDR_1_4_4_MODE, SDR_1_4_4_MODE, use_pbl, ulWaitUs, kpi_mode_peak);
}

static int32_t slPvlRun114S_114S(int32_t slBusFreqKhz,uint8_t ucKpi, uint8_t ucStress, uint32_t  ulMininutes, boolean use_pbl, uint32_t ulWaitUs, boolean kpi_mode_peak)
{
  int32_t slRet = NOR_PVL_RET_ERROR;

  /* DLL with high freq needs DQS but not all QSPI supports DQS. So 114S is used in mission mode. */
  if (slBusFreqKhz== 0)
  {
    slRet = slPvlRunTestMissionMode(ucKpi, ucStress, ulMininutes, ulWaitUs, "stress", kpi_mode_peak);
  }
  else
  {
    slRet = slPvlRunTestWithModeInput(slBusFreqKhz, ucKpi, ucStress, ulMininutes, BUS_NO_DQS, SDR_1_1_4_MODE, SDR_1_1_4_MODE, use_pbl, ulWaitUs, kpi_mode_peak);
  }
  return slRet;
}

static int32_t slPvlRunCrashDbg(void)
{
  int32_t slRet = -1;
  int32_t slBusFreqKhz = 9600;
  uint8_t ucKpi        = 1;
  uint8_t ucStress     = STRESS_DISABLE;
  uint32_t ulMininutes = 0;
  boolean use_pbl      = TRUE;
  uint32_t ulWaitUs    = 0U;
  boolean kpi_mode_peak = TRUE;
  slRet = slPvlRunTestWithModeInput(slBusFreqKhz, ucKpi, ucStress, ulMininutes, BUS_NO_DQS, SDR_1_1_1_MODE, SDR_1_1_1_MODE, use_pbl, ulWaitUs, kpi_mode_peak);
  return slRet;
}
static int32_t slPvlRun111S_111S(int32_t slBusFreqKhz, uint8_t ucKpi, uint8_t ucStress, uint32_t  ulMininutes, boolean use_pbl, uint32_t ulWaitUs, boolean kpi_mode_peak)
{
  return slPvlRunTestWithModeInput(slBusFreqKhz, ucKpi, ucStress, ulMininutes, BUS_NO_DQS, SDR_1_1_1_MODE, SDR_1_1_1_MODE, use_pbl, ulWaitUs, kpi_mode_peak);
}

static int32_t slPvlRunHelp(void)
{

    PVL_LOG_WARNING(" >>>>>>>>>>>>> NOR PVL Tool <<<<<<<<<<<<<<<< \r\n");
    PVL_LOG_WARNING(" Supported commands and their syntax: \r\n");
    PVL_LOG_WARNING("             Command syntax                                                      Description \r\n");
    PVL_LOG_WARNING(" norpvl help                                                        Provides info about the commands supported by the NORPVL Tool \r\n");
    PVL_LOG_WARNING(" norpvl info                                                        Dumps the parsed SFDP tables to the Uart console \r\n");
    PVL_LOG_WARNING(" norpvl crash_dbg                                                   Test a special controller configuration with the memory card \r\n");
    PVL_LOG_WARNING(" norpvl 111s_111s <freq> <stress_choice> <stress_duration>          performs 1S-1S-1S read, 1S-1S-1S pp, erase, KPI, and stress test \r\n");
    PVL_LOG_WARNING(" norpvl 114s_114s <freq> <stress_choice> <stress_duration>          performs 1S-1S-4S read, 1S-1S-4S pp, erase, KPI, and stress test \r\n");
    PVL_LOG_WARNING(" norpvl 144s_144s <freq> <stress_choice> <stress_duration>          performs 1S-4S-4S read, 1S-4S-4S pp, erase, KPI, and stress test \r\n");
    PVL_LOG_WARNING(" norpvl 444s_444s <freq> <stress_choice> <stress_duration>          performs 4S-4S-4S read, 4S-4S-4S pp, erase, KPI, and stress test \r\n");
    PVL_LOG_WARNING(" norpvl 118s_111s <freq> <stress_choice> <stress_duration>          performs 1S-1S-8S read, 1S-1S-1S pp, erase, KPI, and stress test \r\n");
    PVL_LOG_WARNING(" norpvl 888d_888d <freq> <stress_choice> <stress_duration>          performs 8D-8D-8D read, 8D-8D-8D pp, erase, KPI, and stress test \r\n");
    PVL_LOG_WARNING(" norpvl mission <stress_choice> <stress_duration>                   performs pp, erase, KPI, and stress test with mission mode configuration  \r\n");
    PVL_LOG_WARNING(" norpvl screening                                                   performs sanity test \r\n");
    PVL_LOG_WARNING(" norpvl eval <eval_mode> <eval loop> <stress_duration>              performs evaluation test \r\n");
    PVL_LOG_WARNING(" norpvl chiperase <loop>                                            performs entire flash memory erase, read, write\r\n");
    PVL_LOG_WARNING(" norpvl xbl_load <xbl_load choice>                                  enable or disable xbl loading test\r\n");
    PVL_LOG_WARNING(" ........................................................................................................................................... \r\n");
    PVL_LOG_WARNING(" Supported <stress_choice> : stress_no, stress_rd, stress_wr, stress_er, stress_all \r\n");
    PVL_LOG_WARNING(" Supported <freq> : (in KHz)low, pbl, 40000, 80000, 166000 \r\n");
    PVL_LOG_WARNING(" Supported <stress_duration> : provide stress test duration in minutes  \r\n");
    PVL_LOG_WARNING(" Supported <eval_mode> : sanity, boot, stress  \r\n");
    PVL_LOG_WARNING(" Supported <eval_loop> : provide the number of times for the eval test to run, a number > 0  \r\n");
  return NOR_PVL_RET_SUCCESS;
}

static int32_t slPvlChipErase(uint32_t slLoop)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
  spinor_handle_t handle = NULL;
  int32_t type = SPINOR_INIT_TYPE_DEFAULT;
  static spinorMemInfoType memInfo = {0U};
  uint32_t erase_start_block;
  uint32_t erase_block_count;
  uint32_t block_size_bytes;
  uint32_t partition_base;
  uint32_t partition_size;
  uint32_t i;
  uint32_t loop_count;
  uint32_t offset;
  init_global_params();

  g_test_mode_params.hardcode_dqs                            = BUS_NO_DQS;
  g_test_mode_params.hardcode_read_mode                      = SDR_1_1_1_MODE;
  g_test_mode_params.hardcode_write_mode                     = SDR_1_1_1_MODE;
  g_test_mode_params.hardcode_bus_clk_khz                    = 9600; /* KHz */
  g_test_mode_params.hardcode_no_data_read_dummy_cycle_recfg = 1;   /* 1 =disable, 0 = enable */


  status = flash_init_open_and_get_mem_info(&handle, type, &g_test_mode_params, &memInfo, SPINOR_USER_TYPE_OTA);
    if (SPINOR_DEVICE_DONE != status)
    {
      PVL_LOG_ERROR("%s: Error, flash_init_open_and_get_mem_info failed \r\n", __func__);
      return status;
    }

    block_size_bytes  = memInfo.pages_per_block * memInfo.page_size_bytes;
    erase_start_block = 0;
    partition_base =  erase_start_block * block_size_bytes;
    erase_block_count = memInfo.block_count;
    partition_size = erase_block_count * block_size_bytes;
  for(int j = 0; j < slLoop; j++)
  {
    status = spinorEl2Erase (handle, erase_start_block, erase_block_count);
    if ( SPINOR_DEVICE_DONE != status)
    {
      PVL_LOG_ERROR("%s: Error, erase failed. start_block = 0x%x, block_count = 0x%x, block_size = 0x%x\r\n",
                    __func__, erase_start_block, erase_block_count, block_size_bytes);
      break;
    }

    loop_count = partition_size / PVL_READ_BUF_SIZE;

    memset(ucwriteBuf, ERASE_BYTE_PATTERN, PVL_READ_BUF_SIZE);

    for (i = 0; i < loop_count; i++)
    {
      memset(ucReadBuf, READ_BYTE_PATTERN, PVL_READ_BUF_SIZE);
      offset = partition_base + i * PVL_READ_BUF_SIZE;
      status = spinorEl2Read ( handle, offset, PVL_READ_BUF_SIZE, ucReadBuf);
      if ( SPINOR_DEVICE_DONE != status)
      {
        PVL_LOG_ERROR("%s: Error, read failed. start_addr = 0x%x, size  = 0x%x\r\n", __func__, offset, PVL_READ_BUF_SIZE);
        break;
      }

      if (memcmp(ucReadBuf, ucwriteBuf, PVL_READ_BUF_SIZE))
      {
        /* Read after Erase inconsisten  */
        PVL_LOG_ERROR("%s: Error, Read data after Erase inconsistent at offset=0x%x and size=0x%x\r\n", __func__, offset, PVL_READ_BUF_SIZE);
        status = SPINOR_DEVICE_FAIL;
        break;
      }

    }

    memset(ucwriteBuf, READ_BYTE_PATTERN, PVL_READ_BUF_SIZE);

    for (i = 0; i < loop_count; i++)
    {
      offset = partition_base + i * PVL_READ_BUF_SIZE;
      status = spinorEl2Write ( handle, offset, PVL_READ_BUF_SIZE, ucwriteBuf );
      if ( SPINOR_DEVICE_DONE != status)
      {
        PVL_LOG_ERROR("%s: Error, write failed. start_addr = 0x%x, size  = 0x%x\r\n", __func__, offset, PVL_READ_BUF_SIZE);
        break;
      }

      memset(ucReadBuf, ERASE_BYTE_PATTERN, PVL_READ_BUF_SIZE);
      status = spinorEl2Read ( handle, offset, PVL_READ_BUF_SIZE, ucReadBuf);
      if ( SPINOR_DEVICE_DONE != status)
      {
        PVL_LOG_ERROR("%s: Error, read failed. start_addr = 0x%x, size  = 0x%x\r\n", __func__, offset, PVL_READ_BUF_SIZE);
        break;
      }
      if (memcmp(ucReadBuf, ucwriteBuf, PVL_READ_BUF_SIZE))
      {
        /* read and write data are different */
        PVL_LOG_ERROR("%s: Error, read data and write comparison failed at offset=0x%x and size=0x%x\r\n", __func__, offset, PVL_READ_BUF_SIZE);
        status = SPINOR_DEVICE_FAIL;
        break;
      }
    }

    PVL_LOG_WARNING("%s: erase, write and read basic tests done\r\n", __func__);

   }
  /* Deinit the spinor EL2 */
  spinorEl2DeInit(SPINOR_INIT_TYPE_DEFAULT);
  return status;
}

static int32_t slPvlXblLoadTestCtrl(char* param0)
{
  if (sailbsp_stricmp("disable",(char*)param0))
  {
      xblloadtest = false;
  }
  else if (sailbsp_stricmp("enable",(char*)param0))
      xblloadtest = true;
  else
  {
      PVL_LOG_ERROR("NOR_PVL Error, %s, invalid xbl disbale parameter\r\n",param0);
      return NOR_PVL_RET_ERROR;
  }
  return NOR_PVL_RET_SUCCESS;
}

static int32_t slPvlRunInfo(boolean *bOspi, uint32_t *freqkhz)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
  uint32_t freqkhz_loc = 0U;
  boolean is_ospi = TRUE;

  init_global_params();

  g_test_mode_params.hardcode_dqs                            = BUS_NO_DQS;
  g_test_mode_params.hardcode_read_mode                      = SDR_1_1_1_MODE;
  g_test_mode_params.hardcode_write_mode                     = SDR_1_1_1_MODE;
  g_test_mode_params.hardcode_bus_clk_khz                    = 9600; /* KHz */
  g_test_mode_params.hardcode_no_data_read_dummy_cycle_recfg = 1;   /* 1 =disable, 0 = enable */

  PVL_LOG_WARNING("PVL Run Info: freq_khz = %d for 1-1-1 SDR \r\n",g_test_mode_params.hardcode_bus_clk_khz);

  do
  {
    status =spinorEl2Init(SPINOR_INIT_TYPE_DEFAULT, &g_test_mode_params);
    if (status != SPINOR_DEVICE_DONE)
    {
      PVL_LOG_ERROR("%s: Error, spinorEl2Init failed, ret = %d\r\n", __func__, status);
      break;
    }
    status = spinor_pvl_sfdp_dump();
    if (status != SPINOR_DEVICE_DONE)
    {
      PVL_LOG_ERROR("%s: Error, spinor_pvl_sfdp_dump failed, ret = %d\r\n", __func__, status);
      break;
    }
    status = spinor_pvl_get_bus_type(&is_ospi);
    if (status != SPINOR_DEVICE_DONE)
    {
      PVL_LOG_ERROR("%s: Error, spinor_pvl_get_bus_type failed, ret = %d\r\n", __func__, status);
      break;
    }
    if (bOspi)
    {
      *bOspi = is_ospi;
    }
    PVL_LOG_WARNING("%s: is_ospi = %d\r\n", __func__, is_ospi);

    if (is_ospi)
    {
      if (FALSE == spinor_pvl_check_dtr())
      {
        PVL_LOG_ERROR("%s: Error, spinor_pvl_check_dtr failed\r\n", __func__);
        status = SPINOR_DEVICE_FAIL;
        break;
      }
      if (FALSE == spinor_pvl_check_read_118S())
      {
        PVL_LOG_ERROR("%s: Error, spinor_pvl_check_read_118S failed\r\n", __func__);
        status = SPINOR_DEVICE_FAIL;
        break;
      }
      freqkhz_loc = spinor_pvl_get_888_dtr_max_freq();
      if (PVL_MAX_CLOCK_KHZ > freqkhz_loc)
      {
        PVL_LOG_ERROR("%s: Error, spinor_pvl_get_888_dtr_max_freq failed (freq_khz = %d)\r\n", __func__, freqkhz_loc);
        status = SPINOR_DEVICE_FAIL;
        break;
      }
      *freqkhz = PVL_MAX_CLOCK_KHZ;
      PVL_LOG_WARNING("PVL Nor-Device Info: Nor flash device ID = 0x%x, type = Octal SPI with DTR freq = %dKhz and DQS\r\n", spinor_pvl_get_device_id(), *freqkhz);
    }
    else
    {
      if (FALSE == spinor_pvl_check_read_114S())
      {
        PVL_LOG_WARNING("%s: Warning, the card does not support 114S\r\n", __func__);
        if (FALSE == spinor_pvl_check_read_144S())
        {
          PVL_LOG_ERROR("%s: Error, the card does not support 114S and 144S\r\n", __func__);
          status = SPINOR_DEVICE_FAIL;
          break;
        }
      }

      /* Relax this frequency check for QSPI cards */
#if 0
      freqkhz_loc = spinor_pvl_get_444_str_max_freq();
      if (PVL_114S_MAX_FREQ > freqkhz_loc)
      {
        PVL_LOG_ERROR("%s: NOR_PVL Error, spinor_pvl_get_444_str_max_freq failed (freq_khz = %d)\r\n", __func__, freqkhz_loc);
        status = SPINOR_DEVICE_FAIL;
        break;
      }
#endif
      *freqkhz = PVL_114S_MAX_FREQ;
      PVL_LOG_WARNING("PVL Nor-Device Info: Nor flash device ID = 0x%x, type = Quad SPI with STR freq = %dKhz\r\n", spinor_pvl_get_device_id(), *freqkhz);
    }
  } while (FALSE);
  if(status != SPINOR_DEVICE_DONE)
  {
    PVL_LOG_ERROR("PVL Run Info error exit, status: %d \r\n",status);
  }
  else
  {
    PVL_LOG_WARNING("PVL Run Info Done, status: %d \r\n",status);
  }
  /* Deinit the spinor EL2 */
  spinorEl2DeInit(SPINOR_INIT_TYPE_DEFAULT);
  return status;
}
static int32_t slPvlScreeningTestQspi(uint8_t ucKpi, uint8_t ucStress, uint8_t sllStressDur)
{
  int32_t slRet = 0;
  int32_t slBusFreqKhz;
  uint32_t ulCount = 0;
  uint32_t ulWaitUs= 0U;
  boolean kpi_mode_peak = TRUE;

  do
  {
    if (TRUE == spinor_pvl_check_read_114S())
    {
      slBusFreqKhz = 0U;
      slRet = slPvlRun114S_114S(slBusFreqKhz, ucKpi, ucStress, sllStressDur, 1, ulWaitUs, kpi_mode_peak);
      if (slRet != 0)
      {
        PVL_LOG_ERROR("%s: Warning, 114S_114S test failed, status = %d\r\n", slRet);
      }
      else
      {
        ulCount++;
      }

      slBusFreqKhz = PVL_PBL_CORE_CLOCK_KHZ/2;
      slRet = slPvlRun114S_114S(slBusFreqKhz, ucKpi, ucStress, sllStressDur, 1, ulWaitUs, kpi_mode_peak);
      if (slRet != 0)
      {
        PVL_LOG_ERROR("%s: Warning, 114S_114S test failed, status = %d\r\n", slRet);
      }
      else
      {
        ulCount++;
      }
    }

    slBusFreqKhz = PVL_PBL_CORE_CLOCK_KHZ/2;
    if (TRUE == spinor_pvl_check_read_144S())
    {
      slRet = slPvlRun144S_144S(slBusFreqKhz, ucKpi, ucStress, sllStressDur, 1, ulWaitUs, kpi_mode_peak);
      if (slRet != 0)
      {
        PVL_LOG_ERROR("%s: Warning, 144S_144S test failed, status = %d\r\n", slRet);
      }
      else
      {
        ulCount++;
      }
    }

    if (ulCount ==  0U)
    {
      PVL_LOG_ERROR("%s: Error, 114S and 144S are not supported\r\n");
      slRet = -1;
      break;
    }
    /* Do not run 4S4S4D or 4D4D4D mode for QSPI screening test */
#if 0
    slBusFreqKhz = PVL_114S_MAX_FREQ;
    slRet = slPvlRun444S_444S(slBusFreqKhz, ucKpi, ucStress, sllStressDur, ulWaitUs, kpi_mode_peak);
    if (slRet != 0)
    {
      PVL_LOG_ERROR("%s: Error, 444S test failed, status = %d\r\n", slRet);
      break;
    }

    slBusFreqKhz = PVL_444D_MAX_FREQ;
    slRet = slPvlRun444D_444D(slBusFreqKhz, ucKpi, ucStress, sllStressDur, ulWaitUs, kpi_mode_peak);
    if (slRet != 0)
    {
      PVL_LOG_ERROR("%s: Error, 444S test failed, status = %d\r\n", slRet);
      break;
    }
#endif
  }while(0U);
  return slRet;
}
static int32_t slPvlScreeningTestOspi(uint8_t ucKpi, uint8_t ucStress, uint8_t sllStressDur, boolean bTest188S, boolean bTest888S)
{
  int32_t slRet = 0;
  int32_t slBusFreqKhz;
  uint32_t ulWaitUs= 0U;
  boolean kpi_mode_peak = TRUE;

  do
  {
    slBusFreqKhz = PVL_PBL_CORE_CLOCK_KHZ/2;
    slRet = slPvlRun118S_111S(slBusFreqKhz, ucKpi, ucStress, sllStressDur, 1, ulWaitUs, kpi_mode_peak);
    if (slRet != 0)
    {
      PVL_LOG_ERROR("%s: Error, 118S_111S test failed, status = %d\r\n", slRet);
      break;
    }
    /* 188S is optional. If the card supports, test it */
    if (bTest188S && TRUE == spinor_pvl_check_read_188S())
    {
      slRet = slPvlRun188S_111S(slBusFreqKhz, ucKpi, ucStress, sllStressDur, 1, ulWaitUs, kpi_mode_peak);
      if (slRet != 0)
      {
        PVL_LOG_ERROR("%s: Error, 188S_111S test failed, status = %d\r\n", slRet);
        break;
      }
    }
    slBusFreqKhz = 0U; /* Let OSPI driver to choose the max clock which is 166MHz */
    slRet = slPvlRun888D_888D(slBusFreqKhz, ucKpi, ucStress, sllStressDur, ulWaitUs, kpi_mode_peak);
    if (slRet != 0)
    {
      PVL_LOG_ERROR("%s: Error, 888D test failed, status = %d\r\n", slRet);
      break;
    }
    if (bTest888S && TRUE == spinor_pvl_check_888S())
    {
      slBusFreqKhz = PVL_MAX_CLOCK_KHZ;
      slRet = slPvlRun888S_888S(slBusFreqKhz, ucKpi, ucStress, sllStressDur, ulWaitUs, kpi_mode_peak);
      if (slRet != 0)
      {
        PVL_LOG_ERROR("%s: Error, 888S test failed, status = %d\r\n", slRet);
        break;
      }
    }
  } while (0U);
  return slRet;
}
static int32_t slPvlRunScreening(boolean bTest188S, boolean bTest888S)
{
  int32_t slRet = 0;
  uint32_t slBusFreqKhz;
  uint8_t ucKpi = 1;
  uint8_t ucStress = STRESS_DISABLE;
  int32_t slStressMin = 0;
  boolean is_ospi;
  boolean use_pbl = 0;
  uint32_t ulWaitUs = 0U;

  /* Sanity test cases:
   * 1. Run INFO test to get SFDP parameter dump
   * 2  QSPI case: Run basic QSPI tests. No KPI perf tests
   *    OSPI case: Run basic OSPI tests. No KPI perf tests
   * 4. No stress test is run
   */
  do
  {
    slRet = slPvlRunInfo(&is_ospi, &slBusFreqKhz);
    if (slRet != 0)
    {
      PVL_LOG_ERROR("%s: NOR_PVL Error, INFO test failed, status = %d\r\n", slRet);
      break;
    }

    use_pbl = 0;
    slBusFreqKhz = PVL_PBL_ONELANE_CLOCK_KHZ;
    slRet = slPvlRun111S_111S(slBusFreqKhz, ucKpi, ucStress, slStressMin, use_pbl, 0U, TRUE);
    if (slRet != 0)
    {
      PVL_LOG_ERROR("%s: NOR_PVL Error, screening test failed for slPvlRun111S_111S , status = %d\r\n", slRet);
      break;
    }

    if (is_ospi)
    {
      slRet = slPvlScreeningTestOspi(ucKpi, ucStress, slStressMin, bTest188S, bTest888S);
      if (slRet != 0)
      {
        PVL_LOG_ERROR("%s: NOR_PVL Error, ospi screening test failed, status = %d\r\n", slRet);
        break;
      }
    }
    else
    {
      slRet = slPvlScreeningTestQspi(ucKpi, ucStress, slStressMin);
      if (slRet != 0)
      {
        PVL_LOG_ERROR("%s: NOR_PVL Error, qspi screening test failed, status = %d\r\n", slRet);
        break;
      }
    }
  } while (0U);
  return slRet;
}

static int32_t slPvlRunEvalOne(char* eval_mode, uint64_t slMinutes, uint32_t ulWaitUs)
{
  boolean is_ospi            = TRUE;
  int32_t slRet              = NOR_PVL_RET_ERROR;
  uint32_t slBusFreqKhz      = 0;
  uint8_t ucKpi              = 1;
  uint8_t ucStress           = STRESS_DISABLE; //RD_WR_ER_STRESS_TEST
  boolean use_pbl            = 0;
  int32_t slScreeningMinutes = 0; //can be made 1
  uint32_t dqs               = BUS_USE_DQS;
  boolean eval_run_mode_sanity = FALSE, eval_run_mode_boot = FALSE, eval_run_mode_stress = FALSE, kpi_mode_peak = FALSE;

  if(sailbsp_stricmp("sanity",(char*)eval_mode))
  {
      eval_run_mode_sanity = TRUE;
  }
  else if(sailbsp_stricmp("boot",(char*)eval_mode))
  {
      eval_run_mode_boot = TRUE;
  }
  else
  {
      eval_run_mode_stress = TRUE;
  }
  /* Sanity test cases:
   * 1. Run INFO test to get SFDP parameter dump
   * 2  QSPI case: Run basic QSPI tests. No KPI perf tests
   *    OSPI case: Run basic OSPI tests. No KPI perf tests
   * 4. No stress test is run
   */
  do
  {
    slRet = slPvlRunInfo(&is_ospi, &slBusFreqKhz);
    if (slRet != 0)
    {
      PVL_LOG_ERROR("%s: NOR_PVL Error, INFO test failed, status = %d\r\n", slRet);
      break;
    }
    use_pbl = 0;
    slBusFreqKhz = PVL_PBL_ONELANE_CLOCK_KHZ;
    slRet = slPvlRun111S_111S(slBusFreqKhz, ucKpi, ucStress, slScreeningMinutes, use_pbl, 0U, kpi_mode_peak);
    if (slRet != 0)
    {
      PVL_LOG_ERROR("%s: NOR_PVL Error, 111S_111S test failed, status = %d\r\n", slRet);
      break;
    }
    if(eval_run_mode_sanity || eval_run_mode_stress)
    {
        slRet = slPvlRunCrashDbg();
        if (slRet != 0)
        {
          PVL_LOG_ERROR("%s: NOR_PVL Error, crash_dbg test failed, status = %d\r\n", slRet);
          break;
        }
    }

    if(is_ospi)
    {
        slBusFreqKhz = PVL_PBL_CORE_CLOCK_KHZ/2;
        slRet = slPvlRun118S_111S(slBusFreqKhz, ucKpi, ucStress, slScreeningMinutes, 1, ulWaitUs, kpi_mode_peak);
        if (slRet != 0)
        {
          PVL_LOG_ERROR("%s: Error, 118S_111S test failed, status = %d\r\n", slRet);
          break;
        }
    }
    else
    {
        slBusFreqKhz = PVL_PBL_CORE_CLOCK_KHZ/2;
        if (TRUE == spinor_pvl_check_read_144S())
        {
          slRet = slPvlRun144S_144S(slBusFreqKhz, ucKpi, ucStress, slScreeningMinutes, 1, ulWaitUs, kpi_mode_peak);
          if (slRet != 0)
          {
            PVL_LOG_ERROR("%s: Error, 144S test failed, status = %d\r\n", slRet);
            break;
          }
        }
        else if(TRUE == spinor_pvl_check_read_114S())
        {
            PVL_LOG_INFO("114S is supported \r\n");

            slBusFreqKhz = PVL_PBL_CORE_CLOCK_KHZ/2;
            slRet = slPvlRun114S_114S(slBusFreqKhz, ucKpi, ucStress, slScreeningMinutes, 1, ulWaitUs, kpi_mode_peak);
            if (slRet != 0)
            {
                PVL_LOG_ERROR("%s: Error, 114S test failed, status = %d\r\n", slRet);
                break;
            }
        }
        else
        {
            PVL_LOG_ERROR("%s: Error, 114S and 144S are not supported\r\n");
            slRet = -1;
            break;
        }
    }

    ucStress = RD_WR_ER_STRESS_TEST;
    slRet = slPvlRunTestMissionMode(ucKpi, ucStress, slMinutes, ulWaitUs, eval_mode, kpi_mode_peak);
    if (slRet != NOR_PVL_RET_SUCCESS)
    {
      PVL_LOG_ERROR("%s: NOR_PVL Error, mission mode stress test failed, status = %d\r\n", slRet);
      break;
    }
  } while (0U);
  return slRet;
}

int32_t slPvlRunEval(char* eval_mode, int32_t slLoop, int32_t slDur, uint32_t ulWaitUs)
{
  int32_t  slRet = NOR_PVL_RET_ERROR;
  int i;

  PVL_LOG_WARNING("%s: NOR_PVL, EVAL start\r\n", __func__);

  for (i = 1; i <= slLoop; i++)
  {
    slRet = slPvlRunEvalOne(eval_mode, (uint32_t)slDur, ulWaitUs);
    if (slRet != NOR_PVL_RET_SUCCESS)
    {
      PVL_LOG_ERROR("%s: NOR_PVL Error, eval test case failed at loop = %d, status = %d\r\n", __func__, i, slRet);
      break;
    }
    PVL_LOG_WARNING("%s: NOR_PVL, EVAL loop %d completed\r\n", __func__, i);
  }

  if (slRet == NOR_PVL_RET_SUCCESS)
  {
    PVL_LOG_WARNING("%s: NOR_PVL, EVAL done\r\n", __func__);
  }
  else
  {
    PVL_LOG_ERROR("%s: NOR_PVL, EVAL error exit\r\n", __func__);
  }

  return slRet;
}

int32_t sPvlValidateEvalCmd(char* param0, char* param1, char* param2)
{
    int32_t  slRet = NOR_PVL_RET_ERROR;
    int i;
    uint32_t ulWaitUs     = 0U;
    int32_t slDurMin      = 0;
    int32_t slLoop        = 0;

    if (NULL == param1)
    {
      /* Eval must have loop count. This is error */
      PVL_LOG_ERROR("NOR_PVL Error, missing eval test loop\r\n");
      goto end;
    }

    if (NULL == param2)
    {
      /* Eval must have duration. This is error */
      PVL_LOG_ERROR("NOR_PVL Error, missing each loop's stress test duration\r\n");
      goto end;
    }

    if(!isNumeric((const char*)param1))
    {
        PVL_LOG_ERROR("NOR_PVL Error, %s, invalid loop parameter\r\n",param0);
        goto end;
    }
    slLoop = silbsp_atoi((const char*)param1);

    if(!isNumeric((const char*)param2))
    {
        PVL_LOG_ERROR("NOR_PVL Error, %s, invalid duration parameter\r\n",param1);
      goto end;
    }
    slDurMin = silbsp_atoi((const char*)param2);

    if (slLoop < 0U)
    {
      PVL_LOG_ERROR("NOR_PVL Error, invalid eval test loop '%s'\r\n",param1);
      goto end;
    }

    if (slDurMin < 0U)
    {
      PVL_LOG_ERROR("NOR_PVL Error, invalid stress test duration '%s'\r\n",param2);
      goto end;
    }
    ulWaitUs = PVL_EVAL_STRESS_TEST_BUSY_WAIT_US;
    slRet = slPvlRunEval(param0, slLoop, slDurMin, ulWaitUs);

end:
  return slRet;
}

int32_t slPvlRun3Params(eNorPvlCmdType eCmd, char *cmd,
                        char* param0, char* param1, char* param2)
{
  int32_t  slRet        = NOR_PVL_RET_ERROR;
  int32_t slDurMin      = 0;
  int32_t slLoop        = 0;
  int32_t  slBusFreqKhz = 0U;
  uint8    ucKpi        = KPI_ENABLE; /* always enable KPI */
  uint8    ucStress     = 0U;
  boolean use_pbl       = FALSE;
  uint32_t ulWaitUs     = 0U;
  ulWaitUs = PVL_EVAL_STRESS_TEST_BUSY_WAIT_US;
  boolean kpi_mode_peak = FALSE;

  if (NULL == param0 || NULL == param1 || NULL == param2)
  {
    PVL_LOG_ERROR("NOR_PVL Error, %s, missing cmd parameters\r\n", cmd);
    goto end;
  }

  if ((sailbsp_stricmp("sanity",(char*)param0)) || (sailbsp_stricmp("boot",(char*)param0)) || (sailbsp_stricmp("stress",(char*)param0)))
  {
    slRet = sPvlValidateEvalCmd(param0, param1, param2);
    goto end;
  }

  if (sailbsp_stricmp("low",(char*)param0))
  {
    slBusFreqKhz = PVL_CRASH_DBG_CORE_CLOCK_KHZ / 2; //controller PBL config so divide by 2
  }
  else if (sailbsp_stricmp("pbl",(char*)param0))
  {
    use_pbl = TRUE;
    if(eCmd == NOR_PVL_CMD_444S_444S ||
       eCmd == NOR_PVL_CMD_444D_444D ||
       eCmd == NOR_PVL_CMD_888S_888S ||
       eCmd == NOR_PVL_CMD_888D_888D)
    {
      PVL_LOG_ERROR("NOR_PVL Error, not supported '%s' frequency for command '%s'\r\n",
                    param0, cmd);
      goto end;
    }
    slBusFreqKhz = PVL_PBL_CORE_CLOCK_KHZ / 2;
    //controller PBL config so divide by 2
  }
  else
  {
    if(!isNumeric((const char*)param0))
    {
        PVL_LOG_ERROR("NOR_PVL Error, %s, invalid frequency parameter\r\n",param0);
        goto end;
    }
    slBusFreqKhz = silbsp_atoi((const char*)param0);
    if (slBusFreqKhz == 0U)
    {
      PVL_LOG_ERROR("NOR_PVL Error, invalid freq_khz '%s' %d received\r\n",
                    param0, slBusFreqKhz);
      goto end;
    }
  }

  if (sailbsp_stricmp("stress_no",(char*)param1))
  {
    ucStress = STRESS_DISABLE;
  }
  else if (sailbsp_stricmp("stress_rd",(char*)param1))
  {
    ucStress = READ_STRESS_TEST;
  }
  else if (sailbsp_stricmp("stress_wr",(char*)param1))
  {
    ucStress = WRITE_STRESS_TEST;
  }
  else if(sailbsp_stricmp("stress_er",(char*)param1))
  {
      ucStress = ERASE_STRESS_TEST;
  }
  else if(sailbsp_stricmp("stress_all",(char*)param1))
  {
    ucStress = RD_WR_ER_STRESS_TEST;
  }
  else
  {
    PVL_LOG_ERROR("NOR_PVL Error, invalid stress_test choice '%s' %d received\r\n",
                  param1, ucStress);
    goto end;
  }

  if(!isNumeric((const char*)param2))
  {
    PVL_LOG_ERROR("NOR_PVL Error, %s, invalid duration parameter\r\n",param2);
    goto end;
  }
  slDurMin = silbsp_atoi((const char*)param2);
  if (slDurMin < 0U)
  {
    PVL_LOG_ERROR("NOR_PVL Error, invalid stress test duration '%s' %d received\r\n",
                  param2, slDurMin);
    goto end;
  }

  switch(eCmd)
  {
  case NOR_PVL_CMD_111S_111S:
    use_pbl = 0;
    slBusFreqKhz = PVL_PBL_ONELANE_CLOCK_KHZ;
    slRet = slPvlRun111S_111S(slBusFreqKhz, ucKpi,ucStress, slDurMin, use_pbl, ulWaitUs, kpi_mode_peak);
    break;

  case NOR_PVL_CMD_114S_114S:
    slRet = slPvlRun114S_114S(slBusFreqKhz, ucKpi,ucStress, slDurMin, use_pbl, ulWaitUs, kpi_mode_peak);
    break;

  case NOR_PVL_CMD_144S_144S:
    slRet = slPvlRun144S_144S(slBusFreqKhz, ucKpi,ucStress, slDurMin, use_pbl, ulWaitUs, kpi_mode_peak);
    break;

  case NOR_PVL_CMD_444S_444S:
    slRet = slPvlRun444S_444S(slBusFreqKhz, ucKpi,ucStress, slDurMin, ulWaitUs, kpi_mode_peak);
    break;

  case NOR_PVL_CMD_444D_444D:
    slRet = slPvlRun444D_444D(slBusFreqKhz, ucKpi,ucStress, slDurMin, ulWaitUs, kpi_mode_peak);
    break;

  case NOR_PVL_CMD_118S_111S:
    slRet = slPvlRun118S_111S(slBusFreqKhz, ucKpi,ucStress, slDurMin, use_pbl, ulWaitUs, kpi_mode_peak);
    break;

  case NOR_PVL_CMD_188S_111S:
    slRet = slPvlRun188S_111S(slBusFreqKhz, ucKpi,ucStress, slDurMin, use_pbl, ulWaitUs, kpi_mode_peak);
    break;

  case NOR_PVL_CMD_888S_888S:
    slRet = slPvlRun888S_888S(slBusFreqKhz, ucKpi,ucStress, slDurMin, ulWaitUs, kpi_mode_peak);
    break;

  case NOR_PVL_CMD_888D_888D:
    slRet = slPvlRun888D_888D(slBusFreqKhz, ucKpi,ucStress, slDurMin, ulWaitUs, kpi_mode_peak);
    break;

  default:
    break;
  }
end:
  return slRet;
}

int32_t slPvlRun2Params(eNorPvlCmdType eCmd, char *cmd,
                        char* param0, char* param1)
{
  int32_t  slRet        = NOR_PVL_RET_ERROR;
  int32_t slDurMin      = 0;
  int32_t slLoop        = 0;
  int32_t  slBusFreqKhz = 0U;
  uint8    ucKpi        = KPI_ENABLE; /* always enable KPI */
  uint8    ucStress     = 0U;
  boolean use_pbl       = FALSE, kpi_mode_peak = FALSE;
  uint32_t ulWaitUs     = 0U;

  switch (eCmd)
  {
  case NOR_PVL_CMD_MISSION:
    if (NULL == param0 || NULL == param1)
    {
      PVL_LOG_ERROR("NOR_PVL Error, %s, missing cmd parameters for Mission mode\r\n", cmd);
      break;
    }

    if (sailbsp_stricmp("stress_no",(char*)param0))
    {
      ucStress = STRESS_DISABLE;
    }
    else if (sailbsp_stricmp("stress_rd",(char*)param0))
    {
      ucStress = READ_STRESS_TEST;
    }
    else if (sailbsp_stricmp("stress_wr",(char*)param0))
    {
      ucStress = WRITE_STRESS_TEST;
    }
    else if(sailbsp_stricmp("stress_er",(char*)param0))
    {
        ucStress = ERASE_STRESS_TEST;
      }
    else if(sailbsp_stricmp("stress_all",(char*)param0))
    {
      ucStress = RD_WR_ER_STRESS_TEST;
    }
    else
    {
      PVL_LOG_ERROR("NOR_PVL Error, invalid stress_test choice '%s' %d received\r\n",
                    param0, ucStress);
      break;
    }

    if(!isNumeric((const char*)param1))
    {
        PVL_LOG_ERROR("NOR_PVL Error, %s, invalid duration parameter\r\n",param1);
      break;
    }
    slDurMin = silbsp_atoi((const char*)param1);
    if (slDurMin < 0U)
    {
      PVL_LOG_ERROR("NOR_PVL Error, invalid stress test duration '%s' %d received\r\n",
                    param1, slDurMin);
      break;
    }
    slRet = slPvlRunTestMissionMode(ucKpi, ucStress, slDurMin, ulWaitUs, "stress", kpi_mode_peak);
    break;

  default:
    break;
  }
  return slRet;
}
int32_t slPvlRun1Param(eNorPvlCmdType eCmd, char *cmd,
                        char* param0)
{
  int32_t  slRet        = NOR_PVL_RET_ERROR;
  int32_t slLoop        = 0;
  switch (eCmd)
  {
  case NOR_PVL_CMD_CHIPERASE:
    if (NULL == param0)
    {
      /* Chiperase must have loop count. This is error */
      PVL_LOG_ERROR("NOR_PVL Error, %s, missing chiperase loop count\r\n", cmd);
      break;
    }

    if(!isNumeric((const char*)param0))
    {
        PVL_LOG_ERROR("NOR_PVL Error, %s, invalid loop parameter\r\n",param0);
      break;
    }
    slLoop = silbsp_atoi((const char*)param0);
    slRet = slPvlChipErase(slLoop);
    break;

  case NOR_PVL_CMD_XBL_LOAD:
    if (NULL == param0)
    {
      /* XBLDISABLE must have disable string. This is error */
      PVL_LOG_ERROR("NOR_PVL Error, %s, missing disable arguement\r\n", cmd);
      break;
    }
    slRet = slPvlXblLoadTestCtrl(param0);
    break;

  default:
    break;
  }
  return slRet;
}
int32_t slPvlRun(eNorPvlCmdType eCmd, char *cmd)
{
  int32_t  slRet        = NOR_PVL_RET_ERROR;
  int32_t slDurMin      = 0;
  int32_t slLoop        = 0;
  uint32_t  slBusFreqKhz = 0U;
  uint8    ucKpi        = KPI_ENABLE; /* always enable KPI */
  uint8    ucStress     = 0U;
  boolean use_pbl       = FALSE;
  boolean ospi_flag;

  switch (eCmd)
  {
  case NOR_PVL_CMD_SCREENING:
    slRet = slPvlRunScreening(TRUE, TRUE);
    break;

  case NOR_PVL_CMD_INFO:
    slRet = slPvlRunInfo(&ospi_flag, &slBusFreqKhz);
    break;

  case NOR_PVL_CMD_CRASH_DBG:
    slRet = slPvlRunCrashDbg();
    break;

  case NOR_PVL_CMD_HELP:
    slRet = slPvlRunHelp();
    break;

  default:
    break;
  }
  return slRet;
}

void u32_to_u8(const uint32_t u32, uint8_t* u8) {

}

int32_t vPvlInit1MBBuffer()
{
  int32_t  slRet        = NOR_PVL_RET_ERROR;
  int32_t slDurMin      = 0;
  int32_t slLoop        = 0;
  int32_t  slBusFreqKhz = 0U;
  uint8    ucKpi        = KPI_ENABLE; /* always enable KPI */
  uint8    ucStress     = 0U;
  boolean use_pbl       = FALSE;
  boolean ospi_flag;
  uint8_t buf[8][128];
  uint8_t *buffer_base = swaADdr;
  uint8_t *buffer_offset = buffer_base;
  uint32_t temp_crc_a1, temp_crc_a2, temp_crc_b1, temp_crc_b2, temp_crc_c1, temp_crc_c2, temp_crc_d1, temp_crc_d2, temp_crc_e1, temp_crc_e2, temp_crc_f1, temp_crc_f2, temp_crc_g1, temp_crc_g2, temp_crc_h1, temp_crc_h2;
  uint32_t intermediate_individual_buffer_size = 128;
  uint8_t temp_crc_1_int8[4], temp_crc_2_int8[4];
  uint32_t* buff_pointer = (uint32_t *) default_hard_coded_dlp_sram3_pvl;
  uint32_t partition_base = 0;
  uint32_t partition_size = 0;
  uint32_t i = 0;
  uint32_t offset = CD_PARTITION_SIZE;
  uint32_t loop = 0;
  uint8_t* wr_offset;
  uint32_t erase_start_block = 0;
  uint32_t erase_block_count = 0;
  uint32_t block_size_bytes = 0;

  for(int i = 0; i < 1024; i++)
  {
      for(int j = 0; j < 8; j++)
      {
          if(j == 0)
          {
              sailbsp_memscpy(buf[0], intermediate_individual_buffer_size, default_hard_coded_dlp_sram3_pvl, intermediate_individual_buffer_size); //buf1
              sailbsp_memscpy(buf[1], intermediate_individual_buffer_size, inverse_hard_coded_dlp, intermediate_individual_buffer_size); //buf2
              temp_crc_a1 = gptCalcCRC32(default_hard_coded_dlp_sram3_pvl, intermediate_individual_buffer_size, GPT_CRC32_SEED_DEFAULT);
              temp_crc_a2 = gptCalcCRC32(default_hard_coded_dlp_sram3_pvl, intermediate_individual_buffer_size, GPT_CRC32_SEED_INVERSE);

              temp_crc_b1 = gptCalcCRC32(inverse_hard_coded_dlp, intermediate_individual_buffer_size, GPT_CRC32_SEED_DEFAULT);
              temp_crc_b2 = gptCalcCRC32(inverse_hard_coded_dlp, intermediate_individual_buffer_size, GPT_CRC32_SEED_INVERSE);
          }

          if(j == 2 || j == 4 || j == 6 )     //(buf3, buf5, buf7)
          {
            temp_crc_1_int8[3] = (temp_crc_a1 & 0xff000000) >> 24;
            temp_crc_1_int8[2] = (temp_crc_a1 & 0x00ff0000) >> 16;
            temp_crc_1_int8[1] = (temp_crc_a1 & 0x0000ff00) >> 8;
            temp_crc_1_int8[0] = temp_crc_a1 & 0x000000ff;

            temp_crc_2_int8[3] = (temp_crc_a2 & 0xff000000) >> 24;
            temp_crc_2_int8[2] = (temp_crc_a2 & 0x00ff0000) >> 16;
            temp_crc_2_int8[1] = (temp_crc_a2 & 0x0000ff00) >> 8;
            temp_crc_2_int8[0] = temp_crc_a2& 0x000000ff;

            for(int k = 0; k < 124;  k++)
            {
                if(k%4 ==0 && k!=0)
                {
                    k = k+4;
                }
                if((k +4) < 128)
                {
                    buf[j][k] = temp_crc_1_int8[k%4] ^  buf[j-2][k];
                    buf[j][k+4] = temp_crc_2_int8[k%4] ^  buf[j-2][k+4];
                }
            }
            temp_crc_a1 = gptCalcCRC32(buf[j], intermediate_individual_buffer_size, GPT_CRC32_SEED_DEFAULT);
            temp_crc_a2 = gptCalcCRC32(buf[j], intermediate_individual_buffer_size, GPT_CRC32_SEED_INVERSE);
            }

        else if(j == 3 || j == 5 || j == 7)    //(buf4, buf6, buf8)
        {
            temp_crc_1_int8[3] = (temp_crc_b1 & 0xff000000) >> 24;
            temp_crc_1_int8[2] = (temp_crc_b1 & 0x00ff0000) >> 16;
            temp_crc_1_int8[1] = (temp_crc_b1 & 0x0000ff00) >> 8;
            temp_crc_1_int8[0] = temp_crc_b1 & 0x000000ff;

            temp_crc_2_int8[3] = (temp_crc_b2 & 0xff000000) >> 24;
            temp_crc_2_int8[2] = (temp_crc_b2 & 0x00ff0000) >> 16;
            temp_crc_2_int8[1] = (temp_crc_b2 & 0x0000ff00) >> 8;
            temp_crc_2_int8[0] = temp_crc_b2& 0x000000ff;

            for(int k = 0; k < 124;  k++)  //buf4
            {
                if(k%4 ==0 && k!=0)
                {
                    k = k+4;
                }
                if((k +4) < 128)
                {
                    buf[j][k] = temp_crc_1_int8[k%4] ^  buf[j-2][k];
                    buf[j][k+4] = temp_crc_2_int8[k%4] ^  buf[j-2][k+4];
                }
            }
            temp_crc_b1 = gptCalcCRC32(buf[j], intermediate_individual_buffer_size, GPT_CRC32_SEED_DEFAULT);
            temp_crc_b2 = gptCalcCRC32(buf[j], intermediate_individual_buffer_size, GPT_CRC32_SEED_INVERSE);
        }
      }

    sailbsp_memscpy(buffer_offset, 1024, buf, 1024); //1st buf of 1024 in 1MB
    buffer_offset += 1024;
  }

  //populate CD partition with 1mb SRAM3
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  spinor_handle_t handle;
  int32_t type = SPINOR_INIT_TYPE_DEFAULT;
  static spinorMemInfoType memInfo = {0U};
  init_global_params();

  g_test_mode_params.hardcode_dqs                            = BUS_NO_DQS;
  g_test_mode_params.hardcode_read_mode                      = SDR_1_1_1_MODE;
  g_test_mode_params.hardcode_write_mode                     = SDR_1_1_1_MODE;
  g_test_mode_params.hardcode_bus_clk_khz                    = 9600; /* KHz */
  g_test_mode_params.hardcode_no_data_read_dummy_cycle_recfg = 1;   /* 1 =disable, 0 = enable */


    status = flash_init_open_and_get_mem_info(&handle, type, &g_test_mode_params, &memInfo, SPINOR_USER_TYPE_EL2);
    if (SPINOR_DEVICE_DONE != status)
    {
      PVL_LOG_ERROR("%s: Error, flash_init_open_and_get_mem_info failed \r\n", __func__);
      return slRet;
    }


    status = spinorEl2GetGptPartitionInfo( handle, PVL_KPI_RAM_DUMP_GUID, &partition_base, &partition_size);
    if ( SPINOR_DEVICE_DONE != status)
    {
      PVL_LOG_ERROR("%s: Error, no partition found for guid '%s'\r\n", __func__, PVL_KPI_RAM_DUMP_GUID);
      return slRet;
    }
    if(partition_size > CD_PARTITION_SIZE)
        partition_size= CD_PARTITION_SIZE;
    loop = partition_size/PVL_READ_BUF_SIZE;

    block_size_bytes  = memInfo.pages_per_block * memInfo.page_size_bytes;
    erase_start_block = partition_base / block_size_bytes;
    if(partition_size > CD_PARTITION_SIZE)
        partition_size= CD_PARTITION_SIZE;

    erase_block_count = partition_size/ block_size_bytes;

    status = spinorEl2Erase (handle, erase_start_block, erase_block_count);
    if ( SPINOR_DEVICE_DONE != status)
    {
      PVL_LOG_ERROR("%s: Error, erase failed. start_block = 0x%x, block_count = 0x%x, block_size = 0x%x\r\n",
                    __func__, erase_start_block, erase_block_count, block_size_bytes);
      return slRet;
    }

    erase_count++;

    for(i = 0; i < loop; i++)
    {
        offset = partition_base + i * PVL_READ_BUF_SIZE;
        wr_offset = swaADdr + i * PVL_READ_BUF_SIZE;

        status = spinorEl2Write (handle, offset, PVL_READ_BUF_SIZE, wr_offset);
        if ( SPINOR_DEVICE_DONE == status)
        {
            status = spinorEl2Read ( handle, offset, PVL_READ_BUF_SIZE, ucReadBuf);
            if (SPINOR_DEVICE_DONE != status)
            {
                /* read after write failed */
                PVL_LOG_ERROR("%s: Error, Read after write failed at offset=0x%x and size=0x%x \r\n", __func__, offset, PVL_READ_BUF_SIZE);
                status = SPINOR_DEVICE_FAIL;
                break;
            }
            if (memcmp(swaADdr + i * PVL_READ_BUF_SIZE, ucReadBuf, PVL_READ_BUF_SIZE))
            {
                /* read and write data are different */
                PVL_LOG_ERROR("%s: Error, write data inconsistent for write at offset=0x%x and size=0x%x\r\n", __func__, offset, PVL_READ_BUF_SIZE);
                status = SPINOR_DEVICE_FAIL;
                break;
            }
            continue;
        }
        PVL_LOG_ERROR("%s: Error, write failed. start_addr = 0x%x, size  = 0x%x\r\n", __func__, offset, PVL_READ_BUF_SIZE);
        break;
    }
    write_count++;

  spinorEl2DeInit(SPINOR_INIT_TYPE_DEFAULT);
  return slRet;
}

