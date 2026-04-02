/*
===========================================================================
*/
/**
    @file  spinor_el2.c
    @brief Implementation of spinor EL2 Support functions

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

    $Header: $
    $DateTime: $
    $Author: $

    ===========================================================================
*/

#include "spinor_el2_api.h"
#include "spinor_el2.h"
#include "spinor_api.h"
#include "blacklist.h"
#include "fd_mgr.h"
#include "gpt_p1.h"
#include "spinor_el2_trap.h"
#include "gpt_partition1.h"
#include "sailbsp_mutex.h"
#include "spinor_diag.h"

#include "debug_log.h"
#include "target.h"
#include "common_functions.h"

/* SPINOR EL2 Log buffer size */
#define SPINOR_EL2_ERR_LOG_SIZE  32

/** Error log format
*  0xXXYYZZZZ
*
*    0xXX -> 1-byte for classifying the source of the error
*
*                 1-  client errors errors
*                 2-  HAL layer
*                 3-  EL2 layer
*                 4-  FD layer
*                 5-  Blacklist layer
*                 6-  GPT layer
*
*    0xYY      -> 1-byte for the handle/File descriptor id to track the client 0 represents EL2 layer itself
*    0xZZZZ    -> 2-bytes for actual error codes
*/

typedef enum
{
    EL2_ERR_CLASS_CLIENT = 1,  /* Errors/Warnings Originating from Clients */
    EL2_ERR_CLASS_HAL,         /* Errors/Warnings from HAL layer */
    EL2_ERR_CLASS_EL2,         /* Errors/Warnings from within EL2 layer */
    EL2_ERR_CLASS_FD,          /* Errors/Warnings from FD file */
    EL2_ERR_CLASS_BL,          /* Errors/Warnings from to Blacklist file*/
    EL2_ERR_CLASS_GPT,         /* Errors/Warnings from GPT layer */
    EL2_ERR_CLASS_MAX = 0xFF   /* Max classification type */
}EL2ErrClassType_e;

typedef struct {
    uint32_t ulStartAddr;
    uint32_t ulSize;
} spinorEl2El1ReadBufEntryType;

/* Flash Error Log */
typedef struct
{
  boolean bInitDone;
  mutex_t xEl2LogMutex;
  uint8  ucSpinorEL2ErrIndex;
  uint32 usSpinorEL2ErrCodes[SPINOR_EL2_ERR_LOG_SIZE];
} spinorEl2logsType;

typedef struct {
    uint8_t *puWorkBuf;
    uint32_t ulBufLen;
    guid_t tmpGuid;
    spinor_handle_t spinorHandle;
    spinorMemInfoType memInfo;
    spinorSectorMapInfoType el2SectorMapInfo;
    uint32_t el2SectorMapAlignmentAddr;
    spinorEl2logsType xdbgLogs;
    mutex_t mutex;
    boolean bEnableBootMode;
    boolean bInitDone;
    SPINOR_STATUS xJobStatus;
    spinorEl2El1ReadBufEntryType El1ReadbufEntry[SAILBSP_CPU_COUNT];
} spinorEl2ContextType;

#ifdef SPINOR_EL2_DEFAULT_BLACKLIST
const char* El2Guids[]=
{
    "e71077eb-c60d-46ac-a6a0-130dd47925fc",      // partition label="SAIL_DLP"
    "8701faa8-baa0-43cf-9c90-3b30495c558e",      // partition label="SAIL_HYP"
    "48f990b1-4e61-4b16-9f76-2244ee819eb3",      // partition label="SAIL_SW1"
    "e96d074b-6921-49f2-bd7c-c6a0a4bb72e1",      // partition label="SAIL_SW2"
    //"8498942c-6f0e-41e5-957e-206e4df63c1e",      // partition label="SAIL_SEC_ELF"
    "19a02f73-e542-4ce9-af87-be5209f4cbaa",      // partition label="SAIL_DBG_POLICY"
    //"487bd3fa-5af2-48a5-a79b-68ff44cd7c35",      // partition label="MD_BIST_PATTERN2"
    //"1f063844-27c8-4a6b-aee1-fea622246306",      // partition label="SAIL_TGB_MARKER"
    //"5fd6ab83-6d6a-48ac-8d74-4d743d15a0b1",      // partition label="SAIL_PMIC_LOG"/
    "46117b39-6a0f-4cf9-b70a-71c09a62ba72",      // partition label="SAIL_RAM_DUMP"
    "503e59a3-66c6-4386-9999-00a44a94c039",      // partition label="SAIL_NOR_TEST_EL2"
    "025416ff-75ca-475a-9c62-e4c90e4acc2d",      // partition label="SAIL_SW1_BKUP"
    "a866cb7e-3e25-4c2e-95cd-2dfae9290fba",      // partition label="SAIL_SW2_BKUP"
//  "a9eb764c-8a63-4ec0-aa9f-9ee2a53e5a88",      // partition label="SAIL_SEC_ELF_BKUP"
//  "04bc082a-6e31-438c-889c-fbeb791ecaec",      // partition label="SAIL_DBG_POLICY_BKUP"
//  "f02c1c93-6cbe-4d60-9724-c51154f8eb88",      // partition label="MD_BIST_PATTERN2_BKUP"
//  "c6fba11c-3562-4e87-b0f6-baae13c8eb21",      // partition label="SAIL_TGB_MARKER_BKUP"
    "ccd55b90-28b7-4d96-993f-ac93a512f1eb",      // partition label="SAIL_HYP_BKUP"
    "7b361e53-ac16-4c81-86b2-ae5cbfab198a",      // partition label="SAIL_DLP_BKUP"
};
#endif /* SPINOR_EL2_DEFAULT_BLACKLIST */

static spinorEl2ContextType gel2Ctxt __attribute__ ((aligned(sizeof(uint32_t)))) = {0};
static spinor_init_type_t spinor_el2_init_flag;
static boolean bContextInitDone;

/* It is a global mutex to protect the other cores from also making HVC calls to SPINOR */
static volatile atomic_uint *gSpinorglobMutex = (atomic_uint *)OSPI_EL1_MUTEX_ADDR;

/**********************************************************
 * Initialize OSPI EL2 Logs
 *
 * @param type void [IN]
 *   None
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
static void el2LogInit(void)
{
    /* Initalize the mutex for the debug logs */
    mutex_init(&gel2Ctxt.xdbgLogs.xEl2LogMutex);
    gel2Ctxt.xdbgLogs.bInitDone = TRUE;
}

/**********************************************************
 * Logs OSPI EL2 codes
 *
 * @param type pErrLog [IN/OUT]
 *   Pointer to the Errlog structure as input
 *   Updates the error messages to the buffer
 *
 * @param type xErrClass [IN]
 *   Error class type to identify source of error
 *
 * @param type ulHandle [IN]
 *   Handle to identify the client
 *
 * @param type usErrCode [IN]
 *   Actual Error code to identify the error
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
static void el2Log(spinorEl2logsType *pErrLog, EL2ErrClassType_e xErrClass, uint32 ulHandle, uint16 usErrCode)
{
    if( TRUE == gel2Ctxt.xdbgLogs.bInitDone)
    {
      mutex_lock(&gel2Ctxt.xdbgLogs.xEl2LogMutex);
      if (pErrLog->ucSpinorEL2ErrIndex >= SPINOR_EL2_ERR_LOG_SIZE)
      {
        pErrLog->ucSpinorEL2ErrIndex = 0;
      }
      pErrLog->usSpinorEL2ErrCodes[pErrLog->ucSpinorEL2ErrIndex++] = (xErrClass << 24) | (FD_IDX(ulHandle) << 16 ) | usErrCode;
      mutex_unlock(&gel2Ctxt.xdbgLogs.xEl2LogMutex);
    }

    return;
}

/**********************************************************
 * Checks if the OSPI EL2 driver is intialized for the initalization requested
 *
 * @param type [IN]
 *   Type of initialization
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean spinorEl2IsInitDone(int type)
{
    if (gel2Ctxt.bInitDone && (spinor_el2_init_flag == type))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**********************************************************
 * Locks access to the OSPI EL2 driver
 *
 * @param none
 *
 * @return void [OUT]
 *
 **********************************************************/
static void el2Lock(void)
{
    mutex_lock(&gel2Ctxt.mutex);
}

/**********************************************************
 * Unlocks access to OSPI EL2 driver
 *
 * @param none
 *
 * @return void [OUT]
 *
 **********************************************************/
static void el2Unlock(void)
{
    mutex_unlock(&gel2Ctxt.mutex);
}

/**********************************************************
 * Reads from a GPT partition
 *
 * @param ulStartByte [IN]
 *   GPT partition start address.
 *
 * @param ulSize [OUT]
 *   GPT partition size.
 *
 * @param pBuf [OUT]
 *   Pointer to the buffer containing the data read out.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static uint32_t gptReadCb (uint8_t *pBuf, uint32_t ulStartByte, uint32_t ulSize)
{
    SPINOR_STATUS ret = spinor_read ( gel2Ctxt.spinorHandle, ulStartByte, ulSize, pBuf );
    if ( ret == SPINOR_DEVICE_DONE )
    {
        return ulSize;
    }
    else
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_EL2,0,0x1);
        SPINOR_LOG_ERROR_EL2("%s: Error, spinor read failed \r\n", __func__);
        return 0;
    }
}

/**********************************************************
 * Checks the number of 4k blocks for 1 block of a specific region
 *
 * @param addr [IN]
 *   Address for the SPINOR erase
 *
 * @param block_info [IN/OUT]
 *   Struct for storing block info
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static SPINOR_STATUS el2GetNum4kBlock(uint32_t addr, spinor_getnum4kblockType *block_info)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

    if(block_info == NULL)
    {
        status = SPINOR_DEVICE_INVALID_PARAMETER;
        goto spinor_util_getnum4kblock_end;
    }

    for (int idx = 0; idx < sizeof(gel2Ctxt.el2SectorMapInfo.sectorMapInfo) / sizeof(gel2Ctxt.el2SectorMapInfo.sectorMapInfo[0]); idx++)
    {
        if ( (addr >= gel2Ctxt.el2SectorMapInfo.sectorMapInfo[idx].start_range) && (addr <= gel2Ctxt.el2SectorMapInfo.sectorMapInfo[idx].end_range))
        {
          block_info->block_num = gel2Ctxt.el2SectorMapInfo.sectorMapInfo[idx].er_size_KB/4;
          block_info->idx = idx;
          status = SPINOR_DEVICE_DONE;
          goto spinor_util_getnum4kblock_end;
        }
    }

spinor_util_getnum4kblock_end:
    return status;
}

/**********************************************************
 * Initialize the global lock
 *
 * @param none [IN]
 *
 * @return void [OUT]
 *
 **********************************************************/
void el2MultiCoreSafeReservationInit(void)
{
    atomic_fetch_and(gSpinorglobMutex, 0);
}

/**********************************************************
 * Unlock for the global lock
 *
 * @param coreid [IN]
 *   Core Id trying to release the lock.
 *
 * @param bTrap [IN]
 *   Trap call
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean el2MultiCoreSafeResRemove(uint32_t coreid, boolean bTrap)
{
    uint32_t el_offset = 0;
    uint32_t myMask = 0;
    uint32_t oldMask = 0;

     uint32_t cpu_num= get_curr_phys_cpu_num();

     if (cpu_num != coreid)
     {
         el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_EL2,0,0x2);
         SPINOR_LOG_ERROR_EL2("%s: invalid coreid %d received \r\n", __func__, coreid);
         return FALSE;
     }

    /* Keeping the masks separate for EL1 and EL2 */
    if (TRUE==bTrap)
    {
        el_offset = SAILBSP_CPU_COUNT;
    }
    else
    {
        el_offset = 0;
    }

    myMask = 1<<(el_offset+coreid);
    oldMask = atomic_load(gSpinorglobMutex);

    if (oldMask & myMask)
    {
        oldMask = atomic_fetch_and(gSpinorglobMutex, ~myMask);
        return TRUE;
    }
    else
    {
        //bug. Lock trying to be released by someone not holding the lock
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_EL2,0,0x3);
        SPINOR_LOG_ERROR_EL2("%s: Lock oldMask 0x%x trying to be released by myMask 0x%x not holding the lock \r\n", __func__, oldMask, myMask);
        return FALSE;
    }
}

/**********************************************************
 * Try lock for the global lock
 *
 * @param coreid [IN]
 *   Core Id trying to acquire the lock.
 *
 * @param bTrap [IN]
 *   Trap call
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean el2MultiCoreSafeResTry(uint32_t coreid, boolean bTrap)
{
    uint32_t el_offset = 0;
    uint32_t myMask = 0;
    uint32_t oldMask = 0;

    uint32_t cpu_num= get_curr_phys_cpu_num();

    if (cpu_num != coreid)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_EL2,0,0x4);
        SPINOR_LOG_ERROR_EL2("%s: invalid coreid %d received \r\n", __func__, coreid);
        return FALSE;
    }

    /* Keeping the masks separate for EL1 and EL2 */
    if (TRUE==bTrap)
    {
        el_offset = SAILBSP_CPU_COUNT;
    }
    else
    {
        el_offset = 0;
    }

    myMask = 1<<(el_offset+coreid);

    oldMask = atomic_fetch_or(gSpinorglobMutex, myMask);

    if (oldMask == myMask)
    {
        //trying to reacquire the same lock from same core, return FALSE. This is not an error
        return FALSE;
    }

    if (oldMask != 0)
    {
        //someone is  using the lock, revert the mask and return FALSE
        oldMask = atomic_fetch_and(gSpinorglobMutex, ~myMask);
        return FALSE;
    }

    //else holding the lock
    return TRUE;
}

/**********************************************************
 * Initialize OSPI EL2 driver
 *
 * @param type [IN]
 *   Type of initialization
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
int el2Init( int type, uint8_t *puWorkBuf, uint32_t ulBufLen, spinor_hardcode_data_mode *hardcoded_data_mode )
{
    SPINOR_STATUS ret = SPINOR_DEVICE_FAIL;
    struct spinor_info spinor_info;
    uint32_t max_er_size = 0;

    boolean status;
    uint32_t pulStartAddr, pulSize;

    if ( TRUE == gel2Ctxt.bInitDone )
    {
        // already initialized
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_EL2,0,0x5);
        SPINOR_LOG_ERROR_EL2("%s: Error, driver already initialized \r\n", __func__);
        return 0;
    }

    spinor_el2_init_flag = (spinor_init_type_t)type;

    if (spinor_el2_init_flag != SPINOR_INIT_TYPE_DEFAULT && spinor_el2_init_flag != SPINOR_INIT_TYPE_RAM_DUMP)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_EL2,0,0x6);
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid parameter \r\n", __func__);
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    memset(&gel2Ctxt, 0, sizeof(gel2Ctxt));
    mutex_init(&gel2Ctxt.mutex);
    gel2Ctxt.puWorkBuf = puWorkBuf;
    gel2Ctxt.ulBufLen  = ulBufLen;

    el2LogInit();

    /* Initialize El2 trap layer to handle trap system call */
    if(SPINOR_DEVICE_DONE != spinorEl2TrapInit())
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_EL2,0,0x7);
        SPINOR_LOG_ERROR_EL2("%s: Error, el2 trap init failed \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    fdReset();

    blacklistReset();

    ret = spinor_init(type, hardcoded_data_mode);

    if (ret == SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG(SAIL_INFO,"SPINOR HAL layer Init done\n\r");

        if ( SPINOR_DEVICE_DONE != spinor_open ( &gel2Ctxt.spinorHandle ) )
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_HAL,0,0x8);
            SPINOR_LOG_ERROR_EL2("%s: Error, open failed \r\n", __func__);
            spinor_deinit();
            return SPINOR_DEVICE_FAIL;
        }

        ret = spinor_get_info ( gel2Ctxt.spinorHandle, &spinor_info );
        if (ret != SPINOR_DEVICE_DONE)
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_HAL,(uint32_t)gel2Ctxt.spinorHandle,0x9);
            SPINOR_LOG_ERROR_EL2("%s: Error, get info failed \r\n", __func__);
            spinor_close (gel2Ctxt.spinorHandle);
            spinor_deinit();
            return SPINOR_DEVICE_FAIL;
        }

        gel2Ctxt.memInfo.block_count = spinor_info.block_count;
        gel2Ctxt.memInfo.pages_per_block = spinor_info.pages_per_block;
        gel2Ctxt.memInfo.page_size_bytes = spinor_info.page_size_bytes;
        gel2Ctxt.memInfo.device_id = spinor_info.device_id;

        DEBUG_LOG(SAIL_WARNING,"[SPINOR] Device block count = %d \n\r", spinor_info.block_count);
        DEBUG_LOG(SAIL_WARNING,"[SPINOR] Device pages per block = %d \n\r", spinor_info.pages_per_block);
        DEBUG_LOG(SAIL_WARNING,"[SPINOR] Device page size in bytes = %d \n\r", spinor_info.page_size_bytes);

        /* Populate the sec map info in the EL2 context*/
        ret = spinor_get_sector_map_info(gel2Ctxt.spinorHandle, &gel2Ctxt.el2SectorMapInfo);
        if (ret != SPINOR_DEVICE_DONE)
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_HAL,(uint32_t)gel2Ctxt.spinorHandle,0xA);
            SPINOR_LOG_ERROR_EL2("%s: Error, get info failed \r\n", __func__);
            spinor_close (gel2Ctxt.spinorHandle);
            spinor_deinit();
            return SPINOR_DEVICE_FAIL;
        }

        /* Checking the value to which addresses should be aligned */
        for (int idx = 0; idx < sizeof(gel2Ctxt.el2SectorMapInfo.sectorMapInfo) / sizeof(gel2Ctxt.el2SectorMapInfo.sectorMapInfo[0]); idx++)
        {
            if(gel2Ctxt.el2SectorMapInfo.sectorMapInfo[idx].er_size_KB > max_er_size)
            {
                max_er_size = gel2Ctxt.el2SectorMapInfo.sectorMapInfo[idx].er_size_KB;
            }
        }

        gel2Ctxt.el2SectorMapAlignmentAddr = max_er_size * 1024;

        if (FALSE == gptPartitionInit(gel2Ctxt.memInfo.block_count, gptReadCb, gel2Ctxt.puWorkBuf, gel2Ctxt.ulBufLen, SPINOR_BYTES_ALIGNMENT))
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_GPT,(uint32_t)gel2Ctxt.spinorHandle,0xB);
            SPINOR_LOG_ERROR_EL2("%s: Error, gpt partition init failed \r\n", __func__);
            spinor_close (gel2Ctxt.spinorHandle);
            spinor_deinit();
            return SPINOR_DEVICE_FAIL;
        }

#ifdef SPINOR_EL2_DEFAULT_BLACKLIST
        /* Initalialize the Blacklist regions that should only be accessed by EL2 */
        for (int i=0;i<(sizeof(El2Guids)/sizeof(char*));i++)
        {
            if (FALSE == gptPartitionDecodeGUIDString((const char*)El2Guids[i], &gel2Ctxt.tmpGuid))
            {
                el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_GPT,gel2Ctxt.spinorHandle,0xC);
                SPINOR_LOG_ERROR_EL2("%s: Error, gpt partition decode guid string failed \r\n", __func__);
                spinor_close (gel2Ctxt.spinorHandle);
                spinor_deinit();
                return SPINOR_DEVICE_FAIL;
            }

            status = gptGetPartitionInfo(&gel2Ctxt.tmpGuid, &pulStartAddr, &pulSize);
            if (FALSE == status)
            {
                el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_GPT,gel2Ctxt.spinorHandle,0xD);
                SPINOR_LOG_ERROR_EL2("%s: Error, get gpt partition info failed \r\n", __func__);
                spinor_close (gel2Ctxt.spinorHandle);
                spinor_deinit();
                return SPINOR_DEVICE_FAIL;

            }

            status = blacklistAddEntry(pulStartAddr, pulSize, SPINOR_PROTECT_RDWR);
            if (FALSE == status)
            {
                el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_BL,gel2Ctxt.spinorHandle,0xE);
                SPINOR_LOG_ERROR_EL2("%s: Error, blacklist add entry failed \r\n", __func__);
                spinor_close (gel2Ctxt.spinorHandle);
                spinor_deinit();
                return SPINOR_DEVICE_FAIL;
            }
        }
#endif /* SPINOR_EL2_DEFAULT_BLACKLIST */

        bContextInitDone = TRUE;

        /* we already enable ECC and CRC */
        spinor_enable_ecc_check();
        spinor_enable_crc_check();

        /* set EL2 iniot done flag */
        gel2Ctxt.bInitDone = TRUE;
    }

    return (int)ret;
}

/**********************************************************
 * Initialize the ReadBuffer Region for EL1 clients
 *
 * @param ulAddr [IN]
 *   Start address of the Region
 *
 * @param ulSize [IN]
 *   Size of the Region
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_STATUS el2InitReadBufRegion(uint32_t ulAddr, uint32_t ulSize)
{
    uint8 cpu_num= get_curr_phys_cpu_num();

    if (gel2Ctxt.El1ReadbufEntry[cpu_num].ulStartAddr != 0)
    {
        return SPINOR_DEVICE_FAIL;
    }

    gel2Ctxt.El1ReadbufEntry[cpu_num].ulStartAddr = ulAddr;
    gel2Ctxt.El1ReadbufEntry[cpu_num].ulSize = ulSize;

    return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * De-initialize OSPI EL2 driver
 *
 * @param none
 *
 * @return void [OUT]
 *
 **********************************************************/
void el2DeInit( void )
{
    gptPartitionDeInit();
    spinor_close ( gel2Ctxt.spinorHandle );
    spinor_deinit();
    blacklistReset();
    fdReset();
    (void)spinorEl2TrapDeInit();
    memset(&gel2Ctxt, 0, sizeof(gel2Ctxt));
    spinor_el2_init_flag = 0;
    bContextInitDone = 0;
}

/**********************************************************
 * De-initializes the controller
 *
 * @param none
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2ControllerDeInit(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

    fdReset();
    memset(gel2Ctxt.El1ReadbufEntry, 0, sizeof(gel2Ctxt.El1ReadbufEntry));
    status = spinor_controller_deinit();

    return status;
}

/**********************************************************
 * Re-initializes the controller
 *
 * @param none
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2ControllerReInit(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

    status = spinor_init(SPINOR_INIT_TYPE_DEFAULT, NULL);

    return status;
}

/**********************************************************
 * Reset and recovery for Core SW reset if the reset core was using the SPIBUS
 *
 * @param resetCoreid [IN]
 *   Reset coreid
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2MultiCoreSafeResCrashRecover(uint32_t resetCoreid)
{
    uint32_t myMasktrap = 0, myMaskEL2 = 0;
    uint32_t oldMask = 0;
    boolean needsRecovery = FALSE;
    SPINOR_STATUS ret =  SPINOR_DEVICE_DONE;

    myMaskEL2 = 1<<(resetCoreid);
    myMasktrap = 1<<(SAILBSP_CPU_COUNT+resetCoreid);

    /* Get the current lock value */
    oldMask = atomic_load(gSpinorglobMutex);

    /* Check if the lock is acquired by either EL1 or EL2 for the reset core */
    if ((oldMask & myMaskEL2) || (oldMask & myMasktrap))
    {
        needsRecovery = TRUE;
    }

    /* Reset the SPINOR bus and reinitialize if the reset core acquired the lock */
    if (TRUE == needsRecovery)
    {
        SPINOR_LOG_WARNING("%s: Resetting SPINOR BUS for core reset \r\n", __func__);
        ret = spinor_close(gel2Ctxt.spinorHandle);
        if(SPINOR_DEVICE_DONE != ret)
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_HAL,0,0xF);
            SPINOR_LOG_ERROR_EL2("%s: Error, Spinor close failed \r\n", __func__);
            return SPINOR_DEVICE_FAIL;
        }
        ret = spinor_deinit();
        if(SPINOR_DEVICE_DONE != ret)
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_HAL,0,0x10);
            SPINOR_LOG_ERROR_EL2("%s: Error, spinor deinit failed \r\n", __func__);
            return SPINOR_DEVICE_FAIL;
        }
        ret = spinor_init(SPINOR_INIT_TYPE_DEFAULT, NULL);
        if(SPINOR_DEVICE_DONE != ret)
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_HAL,0,0x11);
            SPINOR_LOG_ERROR_EL2("%s: Error, Spinor init failed \r\n", __func__);
            return SPINOR_DEVICE_FAIL;
        }
        ret = spinor_open ( &gel2Ctxt.spinorHandle );
        if(SPINOR_DEVICE_DONE != ret)
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_HAL,0,0x12);
            SPINOR_LOG_ERROR_EL2("%s: Error, spinor open failed \r\n", __func__);
            return SPINOR_DEVICE_FAIL;
        }

        /* Clear the lock acquired by that core */
        if (oldMask & myMaskEL2)
        {
            atomic_fetch_and(gSpinorglobMutex, ~myMaskEL2);
        }
        else
        {
            atomic_fetch_and(gSpinorglobMutex, ~myMasktrap);
        }

        /* Unlock the EL2 Mutex so that othe EL2 functions donot get stuck due to this core */
        el2Unlock();

        SPINOR_LOG_WARNING("%s: Resetting SPINOR BUS for core reset completed \r\n", __func__);
    }

    return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * Opens handle to a access to the spinor device
 *
 *
 * @param type [IN/OUT]
 *   Pointer to SPINOR service interface handle as an input parameter.
 *   Pointer to internal spinor_clients reference count upon return
 *
 * @param eUserType [IN]
 *   SPINOR User type
 *
 * @param pwd [IN/OUT]
 *   Pointer to hold the password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2Open( spinor_handle_t *handle, eSpinorUserType eUserType, uint32_t *pwd)
{
    uint32_t fd = 0;
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;

    *handle = NULL;

    if ( FALSE == gel2Ctxt.bInitDone )
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x13);
        SPINOR_LOG_ERROR_EL2("%s: Error, initilization not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    if (NULL == gel2Ctxt.spinorHandle)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x14);
        SPINOR_LOG_ERROR_EL2("%s: Error, handle is NULL \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    if (SPINOR_USER_TYPE_CRASH_DBG == eUserType)
    {
        if (SPINOR_INIT_TYPE_RAM_DUMP != spinor_el2_init_flag)
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x15);
            SPINOR_LOG_ERROR_EL2("%s: Error, device not supported \r\n", __func__);
            return SPINOR_DEVICE_NOT_SUPPORTED;
        }
    }

    /* lock the EL2 */
    el2Lock();

    if ((SPINOR_USER_TYPE_EL1_SUPER == eUserType) || (SPINOR_USER_TYPE_OTA == eUserType))
    {
        if(fdGetUserCnt(eUserType))
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x16);
            SPINOR_LOG_ERROR_EL2("%s: Error, Invalid user type. Exceeded Max allowed count for usertype \r\n", __func__);
            el2Unlock();
            return SPINOR_DEVICE_INVALID_PARAMETER;
        }

    }

    fd = fdAlloc(eUserType);
    if(fd == 0)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_FD,0,0x17);
        SPINOR_LOG_ERROR_EL2("%s: Error, fd alloc failed \r\n", __func__);
        el2Unlock();
        return SPINOR_NO_FD;
    }

    fdSetLowPowerFlag(fd, FALSE);    /* default set low power flag to FALSE */

    /* make sure that spinor HW driver is at normal power */
    status = spinor_exit_deep_power_down();
    if(status != SPINOR_DEVICE_DONE)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_HAL,fd,0x18);
        SPINOR_LOG_ERROR_EL2("%s: Error, spinor_exit_deep_power_down failed \r\n", __func__);
        el2Unlock();
        return status;
    }

    *pwd = fdGetCurrentPwd(fd);

    el2Unlock ();

    *handle = (void *)fd;

    return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * Closes handle to a spinor service.
 * Clients should close the handle when accesses to
 * the device is no longer needed.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Password cleared on success of the operation else returned as it is
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2Close( spinor_handle_t handle, uint32_t *pwd)
{
    uint32_t fd = (uint32_t)handle;
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;

    if ( FALSE == gel2Ctxt.bInitDone )
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x19);
        SPINOR_LOG_ERROR_EL2("%s: Error, initialization not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    if (NULL == gel2Ctxt.spinorHandle)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x1A);
        SPINOR_LOG_ERROR_EL2("%s: Error, handle is NULL \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    /* lock the EL2 */
    el2Lock();

    /* Check if the handle is valid entry in the list of file descriptors */
    if (FALSE == fdIsValid(fd))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x1B);
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid handle \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Validate the password */
    if (FALSE == fdIsPwdValid(fd,pwd))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,fd,0x1C);
        SPINOR_LOG_ERROR_EL2("%s: Error, password is invalid \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    fdFree(fd);
    if (TRUE == fdCheckLowPowerFlag(NULL))
    {
        status = spinor_enter_deep_power_down();
        if(status != SPINOR_DEVICE_DONE)
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_HAL,fd,0x1D);
            SPINOR_LOG_ERROR_EL2("%s: Error, spinor_enter_deep_power_down failed \r\n", __func__);
            el2Unlock();
            return status;
        }
    }
    el2Unlock();
    *pwd = 0;
    return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * Get memory info from spinor EL2.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param pmemInfo [OUT]
 *   Pointer to the structure that contains the memory info derived.
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2GetMemInfo(spinor_handle_t handle, spinorMemInfoType *pmemInfo, uint32_t *pwd)
{
    if ( FALSE == gel2Ctxt.bInitDone )
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x1E);
        SPINOR_LOG_ERROR_EL2("%s: Error, initialization not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    if (NULL == gel2Ctxt.spinorHandle)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x1F);
        SPINOR_LOG_ERROR_EL2("%s: Error, handle is NULL \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    if (NULL == pmemInfo)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x20);
        SPINOR_LOG_ERROR_EL2("%s: Error, pmeminfo is NULL \r\n", __func__);
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* lock the EL2 */
    el2Lock();

    /* Check if the handle is valid entry in the list of file descriptors */
    if (FALSE == fdIsValid((uint32_t)handle))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x21);
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid handle \r\n", __func__);
        memset(pmemInfo, 0, sizeof(spinorMemInfoType));
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Validate the password */
    if (FALSE == fdIsPwdValid((uint32)handle,pwd))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,(uint32_t)handle,0x22);
        SPINOR_LOG_ERROR_EL2("%s: Error, password is invalid \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }
    *pmemInfo = gel2Ctxt.memInfo;

    /* unlock the EL2 */
    el2Unlock();

    return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * Resume boot mode.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @return void [OUT]
 *
 * @dependencies: this function should be called within the lock
 **********************************************************/
static void el2ResumeBootMode(spinor_handle_t handle)
{
    /* If it is bootloader user or crashdump they need to use the API to set the boot mode. */
    if ( SPINOR_USER_TYPE_BOOT_LOADER == fdGetUserType( (uint32_t)handle ) || SPINOR_USER_TYPE_CRASH_DBG == fdGetUserType ( (uint32_t)handle ) )
    {
        return;
    }

    /* For all other clients check if boot mode is already false.
       If so return since there is no need to disable ECC/CRC checks */
    if ( !gel2Ctxt.bEnableBootMode )
    {
        return;
    }

    /* Boot mode is currently enabled. So disable ECC and CRC checks */
    spinor_disable_ecc_check();
    spinor_disable_crc_check();
}

/**********************************************************
 * Suspend boot mode.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @return void [OUT]
 *
 * @dependencies: this function should be called within the lock
 **********************************************************/
static void el2SuspendBootMode(spinor_handle_t handle)
{
    /* If it is bootloader user or crashdump they need to use the API to set the boot mode. */
    if ( SPINOR_USER_TYPE_BOOT_LOADER == fdGetUserType ( (uint32_t)handle ) || SPINOR_USER_TYPE_CRASH_DBG == fdGetUserType ( (uint32_t)handle ) )
    {
        return;
    }

    /* For all other clients check if boot mode is already false. If so return */
    if ( !gel2Ctxt.bEnableBootMode )
    {
        return;
    }

    /* Boot mode is currently enabled. So enable ECC and CRC checks */
    spinor_enable_ecc_check();
    spinor_enable_crc_check();
}

/**********************************************************
 * Query GPT partition information to spinor framework.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param guid [IN]
 *   NULL terminated GPT partition GUID string.
 *
 * @param pulStartAddr [IN/OUT]
 *   GPT partition start address.
 *
 * @param pulSize [IN/OUT]
 *   GPT partition size.
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2GetGptPartitionInfo( spinor_handle_t handle, const char *guid, uint32_t *pulStartAddr, uint32_t *pulSize, uint32_t *pwd)
{
    boolean status;

    el2Lock();

    /* Check if the handle is valid entry in the list of file descriptors */
    if (FALSE == fdIsValid((uint32_t)handle))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x23);
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid handle \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Validate the password */
    if (FALSE == fdIsPwdValid((uint32_t)handle,pwd))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,(uint32_t)handle,0x24);
        SPINOR_LOG_ERROR_EL2("%s: Error, password is invalid \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    if (FALSE == gptPartitionDecodeGUIDString((const char*)guid, &gel2Ctxt.tmpGuid))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_GPT,(uint32_t)handle,0x25);
        SPINOR_LOG_ERROR_EL2("%s: Error, GUID string decode error \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_FAIL;
    }

    el2SuspendBootMode(handle);
    status = gptGetPartitionInfo(&gel2Ctxt.tmpGuid, pulStartAddr, pulSize);
    el2ResumeBootMode(handle);

    if (FALSE == status)
    {
        *pulStartAddr = 0;
        *pulSize = 0;

        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_GPT,(uint32_t)handle,0x26);
        SPINOR_LOG_ERROR_EL2("%s: Error, gpt get partition info fail \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_FAIL;
    }

    /* For EL1 user check if the partition they are requesting falls under the EL2 blacklist range */
    if (SPINOR_USER_TYPE_EL1 == fdGetUserType((uint32_t)handle))
    {
        if (blacklistCheck(*pulStartAddr, *pulSize, SPINOR_PROTECT_RDWR))
        {
            *pulStartAddr = 0;
            *pulSize = 0;
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_BL,(uint32_t)handle,0x27);
            SPINOR_LOG_ERROR_EL2("%s: Error, blacklist check fail \r\n", __func__);
            el2Unlock();
            return SPINOR_ACCESS_DENIED;
        }
    }

    /* Skip Whitelist check for OTA since they will require access to all regions */
    if ((SPINOR_USER_TYPE_OTA != fdGetUserType((uint32_t)handle)) && (SPINOR_USER_TYPE_EL1_SUPER != fdGetUserType((uint32_t)handle)))
    {
        if(FALSE == fdUpdateWhitelist((uint32_t)handle,&gel2Ctxt.tmpGuid, *pulStartAddr, *pulSize))
        {
            *pulStartAddr = 0;
            *pulSize = 0;

            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_FD,(uint32_t)handle,0x28);
            SPINOR_LOG_ERROR_EL2("%s: Error, update whitelist fail \r\n", __func__);
            el2Unlock();
            return SPINOR_DEVICE_FAIL;
        }
    }

    fdUpdatePwd((uint32_t)handle, pwd);

    el2Unlock();
    return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * Update the Partition Attribute.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param guid [IN]
 *   NULL terminated GPT partition GUID string.
 *
 * @param eAttrib [IN]
 *   Protection type to update for the region.
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2SetPartitionAttrib( spinor_handle_t handle, const char *guid, eSpinorProtectType eAttrib, uint32_t *pwd)
{
    boolean status;
    uint32_t pulStartAddr, pulSize;

    el2Lock();

    /* Check if the handle is valid entry in the list of file descriptors */
    if (FALSE == fdIsValid((uint32_t)handle))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x29);
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid handle \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Validate the password */
    if (FALSE == fdIsPwdValid((uint32_t)handle,pwd))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,(uint32_t)handle,0x2A);
        SPINOR_LOG_ERROR_EL2("%s: Error, password is invalid \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Allow only EL1 Super user and EL2 user to set this configuration */
    if ( SPINOR_USER_TYPE_EL1_SUPER != fdGetUserType((uint32_t)handle) &&
        SPINOR_USER_TYPE_EL2 != fdGetUserType ( (uint32_t)handle ))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_EL2,(uint32_t)handle,0x2B);
        SPINOR_LOG_ERROR_EL2("%s: Error, device not supported \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_NOT_SUPPORTED;
    }

    if (FALSE == gptPartitionDecodeGUIDString((const char*)guid, &gel2Ctxt.tmpGuid))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_GPT,(uint32_t)handle,0x2C);
        SPINOR_LOG_ERROR_EL2("%s: Error, GUID string decode error \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_FAIL;
    }

    el2SuspendBootMode(handle);
    status = gptGetPartitionInfo(&gel2Ctxt.tmpGuid, &pulStartAddr, &pulSize);
    el2ResumeBootMode(handle);

    if (FALSE == status)
    {
        pulStartAddr = 0;
        pulSize = 0;

        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_GPT,(uint32_t)handle,0x2D);
        SPINOR_LOG_ERROR_EL2("%s: Error, gpt get partition info fail \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_FAIL;
    }

    status = blacklistAddEntry(pulStartAddr, pulSize, eAttrib);
    if (FALSE == status)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_BL,(uint32_t)handle,0x2E);
        SPINOR_LOG_ERROR_EL2("%s: Error, blacklist add entry failed \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_FAIL;
    }

    fdUpdatePwd((uint32_t)handle, pwd);

    el2Unlock();
    return SPINOR_DEVICE_DONE;

}

/**********************************************************
 * Get the attribute for the Partition.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param guid [IN]
 *   NULL terminated GPT partition GUID string.
 *
 * @param eAttrib [IN]
 *   Pointer to address that contains Protection type for the region.
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2GetPartitionAttrib( spinor_handle_t handle, const char *guid, eSpinorProtectType* eAttrib, uint32_t *pwd)
{
    boolean status;
    uint32_t pulStartAddr, pulSize, ulIndex;

    el2Lock();

    /* Check if the handle is valid entry in the list of file descriptors */
    if (FALSE == fdIsValid((uint32_t)handle))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x2F);
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid handle \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Validate the password */
    if (FALSE == fdIsPwdValid((uint32_t)handle,pwd))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,(uint32_t)handle,0x30);
        SPINOR_LOG_ERROR_EL2("%s: Error, password is invalid \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Allow only EL1 Super user and EL2 user to get this configuration */
    if ( SPINOR_USER_TYPE_EL1_SUPER != fdGetUserType((uint32_t)handle) &&
        SPINOR_USER_TYPE_EL2 != fdGetUserType ( (uint32_t)handle ))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_EL2,(uint32_t)handle,0x31);
        SPINOR_LOG_ERROR_EL2("%s: Error, device not supported \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_NOT_SUPPORTED;
    }

    if (FALSE == gptPartitionDecodeGUIDString((const char*)guid, &gel2Ctxt.tmpGuid))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_GPT,(uint32_t)handle,0x32);
        SPINOR_LOG_ERROR_EL2("%s: Error, GUID string decode error \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_FAIL;
    }

    el2SuspendBootMode(handle);
    status = gptGetPartitionInfo(&gel2Ctxt.tmpGuid, &pulStartAddr, &pulSize);
    el2ResumeBootMode(handle);

    if (FALSE == status)
    {
        pulStartAddr = 0;
        pulSize = 0;

        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_GPT,(uint32_t)handle,0x33);
        SPINOR_LOG_ERROR_EL2("%s: Error, gpt get partition info fail \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_FAIL;
    }

    status =  blacklistIsRegionExist(pulStartAddr, pulSize, &ulIndex);
    if (TRUE == status)
    {
        /* Region found in blacklist region, get the attribute using index */
        status = blacklistGetAttrib(ulIndex, eAttrib);
        if (FALSE == status)
        {
            /* Unexpected region index */
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_BL,(uint32_t)handle,0x34);
            SPINOR_LOG_ERROR_EL2("%s: Error, Unexpected Index %d for existing region address 0x%x and size 0x%x in blacklist \r\n", __func__, ulIndex, pulStartAddr, pulStartAddr);
            el2Unlock();
            return SPINOR_DEVICE_FAIL;
        }
    }
    else
    {
        /* Region not found in blacklist. So not protected region */
        *eAttrib = SPINOR_PROTECT_NONE;
    }

    fdUpdatePwd((uint32_t)handle, pwd);

    el2Unlock();
    return SPINOR_DEVICE_DONE;

}

/**********************************************************
 * Main function loop to run EL2 Operations.
 *
 * @param void [IN]
 *
 * @return void [OUT]
 *
 **********************************************************/
SPINOR_STATUS el2Mainfunction(spinor_handle_t handle, boolean bTrap, uint32_t *pwd)
{
    SPINOR_STATUS ret;

    if ( FALSE == gel2Ctxt.bInitDone )
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x35);
        SPINOR_LOG_ERROR_EL2("%s: Error, initialization not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    if (NULL == gel2Ctxt.spinorHandle)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x36);
        SPINOR_LOG_ERROR_EL2("%s: Error, handle is NULL \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    /* lock the EL2 */
    el2Lock();

    /* Check if the handle is valid entry in the list of file descriptors */
    if (FALSE == fdIsValid((uint32_t)handle))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x37);
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid handle \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Validate the password */
    if (FALSE == fdIsPwdValid((uint32_t)handle,pwd))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,(uint32_t)handle,0x38);
        SPINOR_LOG_ERROR_EL2("%s: Error, password is invalid \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    spinor_mainFunction();
    gel2Ctxt.xJobStatus = spinor_getJobResult();

    fdUpdatePwd((uint32_t)handle, pwd);

    el2Unlock();

    return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * Gets the current status of the EL2 Operation.
 *
 * @param void [IN]
 *
 * @return int [OUT]
 *   Status of the Operation.
 *
 **********************************************************/
SPINOR_STATUS el2GetJobResult(spinor_handle_t handle, boolean bTrap, uint32_t *pwd)
{
    if ( FALSE == gel2Ctxt.bInitDone )
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x39);
        SPINOR_LOG_ERROR_EL2("%s: Error, initialization not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    if (NULL == gel2Ctxt.spinorHandle)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x3A);
        SPINOR_LOG_ERROR_EL2("%s: Error, handle is NULL \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    /* lock the EL2 */
    el2Lock();

    /* Check if the handle is valid entry in the list of file descriptors */
    if (FALSE == fdIsValid((uint32_t)handle))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x3B);
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid handle \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Validate the password */
    if (FALSE == fdIsPwdValid((uint32_t)handle,pwd))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,(uint32_t)handle,0x3C);
        SPINOR_LOG_ERROR_EL2("%s: Error, password is invalid \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* If operation is not pending, then we can resume bootMode
       Doing it here since there is no other communication for a transaction after the transer is either successful or error */
    if (gel2Ctxt.xJobStatus != SPINOR_DEVICE_OK_NOT_DONE)
    {
        /* Since we reenabled ECC and CRC, this will affect boot transaction KPI.
         * Here we disable both ECC and CRC again.
         */
        el2ResumeBootMode(handle);
    }

    fdUpdatePwd((uint32_t)handle, pwd);

    el2Unlock();


    return gel2Ctxt.xJobStatus;
}

/**********************************************************
 * Performs the SPI Binary command
 *
 * @param handle [IN]
 *   SPINOR service interface handle
 *
 * @param bTrap [IN]
 *
 * @param bincmdParams [IN]
 *   Pointer to the Binary Command Params
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2Bincmd( spinor_handle_t handle, boolean bTrap, void* bincmdParams, uint32_t *pwd)
{
    SPINOR_STATUS ret;

    if ( FALSE == gel2Ctxt.bInitDone )
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x3D);
        SPINOR_LOG_ERROR_EL2("%s: Error, initialization not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    if (NULL == gel2Ctxt.spinorHandle)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x3E);
        SPINOR_LOG_ERROR_EL2("%s: Error, handle is NULL \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    /* lock the EL2 */
    el2Lock();

    /* Check if the handle is valid entry in the list of file descriptors */
    if (FALSE == fdIsValid((uint32_t)handle))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x3F);
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid handle \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Validate the password */
    if (FALSE == fdIsPwdValid((uint32_t)handle,pwd))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,(uint32_t)handle,0x40);
        SPINOR_LOG_ERROR_EL2("%s: Error, password is invalid \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Allow only EL1 Super user to perform this operation */
    if ( SPINOR_USER_TYPE_EL1_SUPER != fdGetUserType((uint32_t)handle) )
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_EL2,(uint32_t)handle,0x41);
        SPINOR_LOG_ERROR_EL2("%s: Error, device not supported \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_NOT_SUPPORTED;
    }

    /* If EL2 is set to boot mode, ECC and CRC are disabled.
     * For non boot loader transaction, we still want to enable ECC and CRC.
     */
    el2SuspendBootMode(handle);

    if (bTrap)
    {
        ret = spinor_bincmd_async(gel2Ctxt.spinorHandle, bincmdParams);

        /* Update the context with the result */
        gel2Ctxt.xJobStatus = spinor_getJobResult();

        /* If error then resume boot mode again */
        if (ret != SPINOR_DEVICE_OK_NOT_DONE)
        {
            /* Since we reenabled ECC and CRC, this will affect boot transaction KPI.
             * Here we disable both ECC and CRC again.
             */
            el2ResumeBootMode(handle);
        }
    }
    else
    {
        /* Since we reenabled ECC and CRC, this will affect boot transaction KPI.
         * Here we disable both ECC and CRC again.
         */
        el2ResumeBootMode(handle);

        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_EL2,(uint32_t)handle,0x42);
        SPINOR_LOG_ERROR_EL2("%s: Error, Bin Cmd Operation not allowed in EL2 \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_NOT_SUPPORTED;
    }

    fdUpdatePwd((uint32_t)handle, pwd);

    el2Unlock();

    return ret;
}

/**********************************************************
 * Erases given spinor blocks
 *
 * @param handle [IN]
 *   SPINOR service interface handle
 *
 * @param bTrap [IN]
 *
 * @param start_block [IN]
 *   A starting block for a number of blocks to erase.
 *
 * @param block_count [IN]
 *   Number of blocks to erase
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2Erase( spinor_handle_t handle, boolean bTrap, uint32 start_block, uint32 block_count, uint32_t *pwd)
{
    SPINOR_STATUS ret;
    uint32 valid_start_addr, valid_end_addr, current_start_addr, current_end_addr;
    spinor_getnum4kblockType el2BlockInfo = {0};

    if ( FALSE == gel2Ctxt.bInitDone )
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x43);
        SPINOR_LOG_ERROR_EL2("%s: Error, initialization not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    if (NULL == gel2Ctxt.spinorHandle)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x44);
        SPINOR_LOG_ERROR_EL2("%s: Error, handle is NULL \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    //0 to (0x6000 - 1) and last 20k -> only EL2 user and EL1 superuser and ota should access this
    valid_start_addr = 0x6000;
    valid_end_addr = (gel2Ctxt.memInfo.block_count - 5) * (gel2Ctxt.memInfo.pages_per_block * gel2Ctxt.memInfo.page_size_bytes);
    current_start_addr = start_block * (gel2Ctxt.memInfo.pages_per_block * gel2Ctxt.memInfo.page_size_bytes);
    current_end_addr = ((start_block + block_count) * (gel2Ctxt.memInfo.pages_per_block * gel2Ctxt.memInfo.page_size_bytes)) -1;
    if((SPINOR_USER_TYPE_OTA != fdGetUserType((uint32_t)handle)) && (SPINOR_USER_TYPE_EL1_SUPER != fdGetUserType((uint32_t)handle)) && (SPINOR_USER_TYPE_EL2 != fdGetUserType((uint32_t)handle)))
    {
        if(current_start_addr < valid_start_addr || current_end_addr >= valid_end_addr)
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x45);
            SPINOR_LOG_ERROR_EL2("%s: Error, Access is denied for start address 0x%x and end address 0x%x \r\n", __func__, current_start_addr, current_end_addr);
            return SPINOR_ACCESS_DENIED;
        }
    }

    /* Address range checks are performed for the erase operations to make sure that the start and end addresses align with the
     * natural boundary of the nor flash sector map. This is because for the hybrid sectors the erase operations for the different
     * regions have different erase sizes and we want to return an error to the client incase the erase regions passed do not align
     * with different sector alignments.
     * This is needed so that we dont erase regions that are not expected to be erased by the user.
     * For hybrid sectors (block sizes are >4KB), the start and end address needs to be aligned to 256KB address or with the
     * respective start/end address of the address range.
    */

    /* Start Address check - Check alignment to previous 256KB */
    ret = el2GetNum4kBlock(current_start_addr, &el2BlockInfo);
    if(ret != SPINOR_DEVICE_DONE)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x46);
        SPINOR_LOG_ERROR_EL2("%s: Error, el2GetNum4kBlock failed \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    if(el2BlockInfo.block_num > 1)
    {
        if((current_start_addr & (gel2Ctxt.el2SectorMapAlignmentAddr - 1)) != 0)
        {
            if(current_start_addr != gel2Ctxt.el2SectorMapInfo.sectorMapInfo[el2BlockInfo.idx].start_range)
            {
                //Address is unaligned to any end address or 256KB boundary
                el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x47);
                SPINOR_LOG_ERROR_EL2("%s: Error, erase start address unaligned to the boundary \r\n", __func__);
                return SPINOR_ERASE_BLOCK_INVALID;
            }
        }
    }

    /* End Address check - Check alignment to next 256KB */
    ret = el2GetNum4kBlock(current_end_addr, &el2BlockInfo);
    if(ret != SPINOR_DEVICE_DONE)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x48);
        SPINOR_LOG_ERROR_EL2("%s: Error, el2GetNum4kBlock failed \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    if(el2BlockInfo.block_num > 1)
    {
        if(((current_end_addr + 1) & (gel2Ctxt.el2SectorMapAlignmentAddr - 1)) != 0)
        {
            if(current_end_addr != gel2Ctxt.el2SectorMapInfo.sectorMapInfo[el2BlockInfo.idx].end_range)
            {
                //Address is unaligned to any end address or 256KB boundary
                el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x49);
                SPINOR_LOG_ERROR_EL2("%s: Error, erase end address unaligned to the boundary \r\n", __func__);
                return SPINOR_ERASE_BLOCK_INVALID;
            }
        }
    }

    /* lock the EL2 */
    el2Lock();

    /* Check if the handle is valid entry in the list of file descriptors */
    if (FALSE == fdIsValid((uint32_t)handle))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x4A);
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid handle \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Validate the password */
    if (FALSE == fdIsPwdValid((uint32_t)handle,pwd))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,(uint32_t)handle,0x4B);
        SPINOR_LOG_ERROR_EL2("%s: Error, password is invalid \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Check if the range of device address accessed is in whitelist range */
    if (FALSE == fdWhitelistCheck((uint32_t) handle, start_block*4096, block_count*4096))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_FD,(uint32_t)handle,0x4C);
        SPINOR_LOG_ERROR_EL2("%s: Error, whitelist check fail, 0x%x start block and %d block count \r\n", __func__, start_block, block_count);
        el2Unlock();
        return SPINOR_ACCESS_DENIED;
    }

    if ( (SPINOR_USER_TYPE_OTA != fdGetUserType ( (uint32_t)handle ) )  && (SPINOR_USER_TYPE_EL1_SUPER != fdGetUserType ( (uint32_t)handle ) ))
    {
        if (bTrap && blacklistCheck(start_block * 4096, block_count * 4096, SPINOR_PROTECT_WR))
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_BL,(uint32_t)handle,0x4D);
            SPINOR_LOG_ERROR_EL2("%s: Error, blacklist check fail, 0x%x start block and %d block count \r\n", __func__, start_block, block_count);
            el2Unlock();
            return SPINOR_ACCESS_DENIED;
        }
    }

    /* If EL2 is set to boot mode, ECC and CRC are disabled.
     * For non boot loader transaction, we still want to enable ECC and CRC.
     */
    el2SuspendBootMode(handle);

    if (bTrap)
    {
        ret = spinor_erase_async(gel2Ctxt.spinorHandle, start_block, block_count);

        /* Update the context with the result */
        gel2Ctxt.xJobStatus = spinor_getJobResult();

        /* If error then resume boot mode again */
        if (ret != SPINOR_DEVICE_OK_NOT_DONE)
        {
            /* Since we reenabled ECC and CRC, this will affect boot transaction KPI.
             * Here we disable both ECC and CRC again.
             */
            el2ResumeBootMode(handle);
        }
    }
    else
    {
        ret = spinor_erase(gel2Ctxt.spinorHandle, start_block, block_count);

        /* Since we reenabled ECC and CRC, this will affect boot transaction KPI.
         * Here we disable both ECC and CRC again.
         */
        el2ResumeBootMode(handle);
    }

    fdUpdatePwd((uint32_t)handle, pwd);

    el2Unlock();

    return ret;
}

/**********************************************************
 * Writes data to the spinor.
 *
 * @param handle [IN]
 *   SPINOR service interface handle
 *
 * @param bTrap [IN]
 *
 * @param byte_offset [IN]
 *   Byte offset from the start of the region to write to.
 *
 * @param byte_count [IN]
 *   Number of bytes to write data.
 *
 * @buffer [IN]
 *   Data buffer for spinor write operation.
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2Write( spinor_handle_t handle, boolean bTrap, uint32 byte_offset, uint32 byte_count, const void *buffer, uint32_t *pwd)
{
    SPINOR_STATUS ret = SPINOR_DEVICE_DONE;
    uint32 valid_start_addr, valid_end_addr, current_start_addr, current_end_addr;

    if ( FALSE == gel2Ctxt.bInitDone )
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x4E);
        SPINOR_LOG_ERROR_EL2("%s: Error, initialization not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    if (NULL == gel2Ctxt.spinorHandle)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x4F);
        SPINOR_LOG_ERROR_EL2("%s: Error, handle is NULL \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    //0 to (0x6000 - 1) and last 20k -> only EL2 user and EL1 superuser and ota should access this
    valid_start_addr = 0x6000;
    valid_end_addr = (gel2Ctxt.memInfo.block_count - 5) * (gel2Ctxt.memInfo.pages_per_block * gel2Ctxt.memInfo.page_size_bytes);
    current_start_addr = byte_offset;
    current_end_addr = (byte_offset + byte_count) - 1;
    if((SPINOR_USER_TYPE_OTA != fdGetUserType((uint32_t)handle)) && (SPINOR_USER_TYPE_EL1_SUPER != fdGetUserType((uint32_t)handle)) && (SPINOR_USER_TYPE_EL2 != fdGetUserType((uint32_t)handle)))
    {
        if(current_start_addr < valid_start_addr || current_end_addr >= valid_end_addr)
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x50);
            SPINOR_LOG_ERROR_EL2("%s: Error, Access is denied for start address 0x%x and end address 0x%x \r\n", __func__, current_start_addr, current_end_addr);
            return SPINOR_ACCESS_DENIED;
        }
    }

    /* lock the EL2 */
    el2Lock();

    /* Check if the handle is valid entry in the list of file descriptors */
    if (FALSE == fdIsValid((uint32_t)handle))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x51);
        SPINOR_LOG_ERROR_EL2("%s: Error, handle is invalid \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Validate the password */
    if (FALSE == fdIsPwdValid((uint32_t)handle,pwd))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,(uint32_t)handle,0x52);
        SPINOR_LOG_ERROR_EL2("%s: Error, password is invalid \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Check if the range of device address accessed is in whitelist range */
    if (FALSE == fdWhitelistCheck((uint32_t) handle, byte_offset, byte_count))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_FD,(uint32_t)handle,0x53);
        SPINOR_LOG_ERROR_EL2("%s: Error, whitelist check fail, 0x%x address \r\n", __func__, byte_offset);
        el2Unlock();
        return SPINOR_ACCESS_DENIED;
    }

    if ( (SPINOR_USER_TYPE_OTA != fdGetUserType ( (uint32_t)handle ) )  && (SPINOR_USER_TYPE_EL1_SUPER != fdGetUserType ( (uint32_t)handle ) ))
    {
        if (bTrap && blacklistCheck(byte_offset, byte_count, SPINOR_PROTECT_WR))
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_BL,(uint32_t)handle,0x54);
            SPINOR_LOG_ERROR_EL2("%s: Error, blacklist check fail, 0x%x address \r\n", __func__, byte_offset);
            el2Unlock();
            return SPINOR_ACCESS_DENIED;
        }
    }

    if (SPINOR_USER_TYPE_BOOT_LOADER != fdGetUserType ( (uint32_t)handle ) &&
        SPINOR_USER_TYPE_CRASH_DBG != fdGetUserType ( (uint32_t)handle ) )
    {
        if ( ( byte_offset % SPINOR_BYTES_ALIGNMENT ) || ( byte_count % SPINOR_BYTES_ALIGNMENT ) )
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_EL2,(uint32_t)handle,0x55);
            SPINOR_LOG_ERROR_EL2("%s: Error, invalid byte_offset 0x%x or byte_count 0x%x \r\n", __func__, byte_offset, byte_count);
            el2Unlock();
            return SPINOR_ALIGNMENT;
        }
    }
    el2SuspendBootMode(handle);

    if (bTrap)
    {
        ret = spinor_write_async(gel2Ctxt.spinorHandle, byte_offset, byte_count, buffer);

        /* Update the context with the result */
        gel2Ctxt.xJobStatus = spinor_getJobResult();

        /* If error then resume boot mode again */
        if (ret != SPINOR_DEVICE_OK_NOT_DONE)
        {
            /* Since we reenabled ECC and CRC, this will affect boot transaction KPI.
             * Here we disable both ECC and CRC again.
             */
            el2ResumeBootMode(handle);
        }
    }
    else
    {
        ret = spinor_write(gel2Ctxt.spinorHandle, byte_offset, byte_count, buffer);
        el2ResumeBootMode(handle);
    }

    fdUpdatePwd((uint32)handle, pwd);

    el2Unlock();
    return ret;
}

/**********************************************************
 * Allows read data from the spinor
 *
 * @param handle [IN]
 *   SPINOR service interface handle
 *
 * @param bTrap [IN]
 *
 * @param byte_offset [IN]
 *   Byte offset from the start of region to read from.
 *
 * @param byte_count [IN]
 *   Number of bytes to read data.
 *
 * @buffer [OUT]
 *   Data buffer for a spinor read operation.
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_STATUS el2Read ( spinor_handle_t handle, boolean bTrap, uint32 byte_offset, uint32 byte_count, void *buffer, uint32_t *pwd)
{
    SPINOR_STATUS ret = SPINOR_DEVICE_DONE;
    uint32 valid_start_addr, valid_end_addr, current_start_addr, current_end_addr;

    uint8 cpu_num= get_curr_phys_cpu_num();

    if ( FALSE == gel2Ctxt.bInitDone )
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x56);
        SPINOR_LOG_ERROR_EL2("%s: Error, initialization not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    if (NULL == gel2Ctxt.spinorHandle)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x57);
        SPINOR_LOG_ERROR_EL2("%s: Error, handle is NULL \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    //0 to (0x6000 - 1) and last 20k -> only EL2 user and EL1 superuser and ota should access this
    valid_start_addr = 0x6000;
    valid_end_addr = (gel2Ctxt.memInfo.block_count - 5) * (gel2Ctxt.memInfo.pages_per_block * gel2Ctxt.memInfo.page_size_bytes);
    current_start_addr = byte_offset;
    current_end_addr = (byte_offset + byte_count) - 1;
    if((SPINOR_USER_TYPE_OTA != fdGetUserType((uint32_t)handle)) && (SPINOR_USER_TYPE_EL1_SUPER != fdGetUserType((uint32_t)handle)) && (SPINOR_USER_TYPE_EL2 != fdGetUserType((uint32_t)handle)))
    {
        if(current_start_addr < valid_start_addr || current_end_addr >= valid_end_addr)
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x58);
            SPINOR_LOG_ERROR_EL2("%s: Error, Access is denied for start address 0x%x and end address 0x%x \r\n", __func__, current_start_addr, current_end_addr);
            return SPINOR_ACCESS_DENIED;
        }
    }

    /* lock the EL2 */
    el2Lock();

    /* Check if the handle is valid entry in the list of file descriptors */
    if (FALSE == fdIsValid((uint32_t)handle))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x59);
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid handle \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Validate the password */
    if (FALSE == fdIsPwdValid((uint32_t)handle,pwd))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,(uint32_t)handle,0x5A);
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid password \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Check if the range of device address accessed is in whitelist range */
    if (FALSE == fdWhitelistCheck((uint32_t) handle, byte_offset, byte_count))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_FD,(uint32_t)handle,0x5B);
        SPINOR_LOG_ERROR_EL2("%s: Error, whitelist check fail, 0x%x address \r\n", __func__, byte_offset);
        el2Unlock();
        return SPINOR_ACCESS_DENIED;
    }

    if ( (SPINOR_USER_TYPE_OTA != fdGetUserType ( (uint32_t)handle ) )  && (SPINOR_USER_TYPE_EL1_SUPER != fdGetUserType ( (uint32_t)handle ) ))
    {
        if (bTrap && blacklistCheck(byte_offset, byte_count, SPINOR_PROTECT_RD))
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_BL,(uint32_t)handle,0x5C);
            SPINOR_LOG_ERROR_EL2("%s: Error, blacklist check fail, 0x%x address \r\n", __func__, byte_offset);
            el2Unlock();
            return SPINOR_ACCESS_DENIED;
        }
    }

    if (SPINOR_USER_TYPE_BOOT_LOADER != fdGetUserType ( (uint32_t)handle ) &&
        SPINOR_USER_TYPE_CRASH_DBG != fdGetUserType ( (uint32_t)handle ) )
    {
        if ( ( byte_offset % SPINOR_BYTES_ALIGNMENT ) || ( byte_count % SPINOR_BYTES_ALIGNMENT ) )
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_EL2,(uint32)handle,0x5D);
            SPINOR_LOG_ERROR_EL2("%s: Error, invalid byte_offset 0x%x / byte_count 0x%x \r\n", __func__, byte_offset, byte_count);
            el2Unlock();
            return SPINOR_ALIGNMENT;
        }
    }
    el2SuspendBootMode(handle);

    if (bTrap)
    {
        /* For El1 clients ensure the read buffer is always in the allowed range to protect against DMA attack */
        if (((uint32_t)buffer < gel2Ctxt.El1ReadbufEntry[cpu_num].ulStartAddr) ||
            ((uint32_t)buffer >= (gel2Ctxt.El1ReadbufEntry[cpu_num].ulStartAddr + gel2Ctxt.El1ReadbufEntry[cpu_num].ulSize-1)) ||
            (((uint32_t)buffer + byte_count-1) > (gel2Ctxt.El1ReadbufEntry[cpu_num].ulStartAddr + gel2Ctxt.El1ReadbufEntry[cpu_num].ulSize-1))
            )
        {
            el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_EL2,(uint32)handle,0x5E);
            SPINOR_LOG_ERROR_EL2("%s: Error, buffer 0x%x / byte_count 0x%x not in the EL1 range\r\n", __func__, (uint32_t)buffer, byte_count);
            el2Unlock();
            return SPINOR_ACCESS_DENIED;
        }
        ret = spinor_read_async(gel2Ctxt.spinorHandle, byte_offset, byte_count, buffer);

        /* Update the context with the result */
        gel2Ctxt.xJobStatus = spinor_getJobResult();

        /* If error then resume boot mode again */
        if (ret != SPINOR_DEVICE_OK_NOT_DONE)
        {
            /* Since we reenabled ECC and CRC, this will affect boot transaction KPI.
             * Here we disable both ECC and CRC again.
             */
            el2ResumeBootMode(handle);
        }
    }
    else
    {
        ret = spinor_read(gel2Ctxt.spinorHandle, byte_offset, byte_count, buffer);
        el2ResumeBootMode(handle);
    }

    fdUpdatePwd((uint32_t)handle, pwd);

    el2Unlock();
    return ret;
}

/**********************************************************
 * Set boot mode.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param bEnableBootMode [IN]
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2SetBootMode(spinor_handle_t handle, boolean bEnableBootMode, uint32_t *pwd)
{
    if ( FALSE == gel2Ctxt.bInitDone )
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x5F);
        SPINOR_LOG_ERROR_EL2("%s: Error, initialization not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    if (NULL == gel2Ctxt.spinorHandle)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x60);
        SPINOR_LOG_ERROR_EL2("%s: Error, handle is NULL \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    el2Lock();

    /* Check if the handle is valid entry in the list of file descriptors */
    if (FALSE == fdIsValid((uint32_t)handle))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x61);
        SPINOR_LOG_ERROR_EL2("%s: Error, handle is invalid \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Validate the password */
    if (FALSE == fdIsPwdValid((uint32_t)handle,pwd))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,(uint32_t)handle,0x62);
        SPINOR_LOG_ERROR_EL2("%s: Error, password is invalid \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Allow boot loader or crashdbg users to ignore ECC and disable CRC */
    if ( SPINOR_USER_TYPE_BOOT_LOADER != fdGetUserType((uint32_t)handle) &&
        SPINOR_USER_TYPE_CRASH_DBG != fdGetUserType ( (uint32_t)handle ))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_EL2,(uint32_t)handle,0x63);
        SPINOR_LOG_ERROR_EL2("%s: Error, device not supported \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_NOT_SUPPORTED;
    }

    gel2Ctxt.bEnableBootMode = bEnableBootMode;

    if (gel2Ctxt.bEnableBootMode)
    {
        spinor_disable_ecc_check();
        spinor_disable_crc_check();
    }
    else
    {
        spinor_enable_ecc_check();
        spinor_enable_crc_check();
    }

    el2Unlock();
    return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * Vote low power to spinor framework.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param bLowPower [IN]
 *
 * @param bLowPower [IN]
 *   Vote to allow low power
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2LowPower ( spinor_handle_t handle, boolean bLowPower, uint32_t *pwd)
{
    uint32_t ulFdCount = 0;
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;

    if ( FALSE == gel2Ctxt.bInitDone )
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x64);
        SPINOR_LOG_ERROR_EL2("%s: Error, initialization not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    if (NULL == gel2Ctxt.spinorHandle)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x65);
        SPINOR_LOG_ERROR_EL2("%s: Error, handle is NULL \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    el2Lock();

    /* Check if the handle is valid entry in the list of file descriptors */
    if (FALSE == fdIsValid((uint32_t)handle))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x66);
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid handle \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Validate the password */
    if (FALSE == fdIsPwdValid((uint32_t)handle,pwd))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,(uint32_t)handle,0x67);
        SPINOR_LOG_ERROR_EL2("%s: Error, password is invalid \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* DPD mode is entered only if all the users have voted to enter DPD */
    if (TRUE == bLowPower)
    {
        fdSetLowPowerFlag((uint32_t)handle, bLowPower);

        if (TRUE == fdCheckLowPowerFlag(&ulFdCount))
        {
            status = spinor_enter_deep_power_down();
            if(status != SPINOR_DEVICE_DONE)
            {
                el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_HAL,(uint32_t)handle,0x68);
                SPINOR_LOG_ERROR_EL2("%s: Error, spinor_enter_deep_power_down failed \r\n", __func__);
                el2Unlock();
                return status;
            }
            SPINOR_LOG_INFO("%s: Info, SPINOR enter deep power down \r\n", __func__);
        }
    }
    else
    {
        /* DPD mode is exited if any one of the users have voted to exit DPD.
        Once DPD mode is exited, it will not be exited again in case another user votes to exit low power mode */
        if (TRUE == fdCheckLowPowerFlag(&ulFdCount))
        {
            status = spinor_exit_deep_power_down();
            if(status != SPINOR_DEVICE_DONE)
            {
                el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_HAL,(uint32_t)handle,0x69);
                SPINOR_LOG_ERROR_EL2("%s: Error, spinor_exit_deep_power_down failed \r\n", __func__);
                el2Unlock();
                return status;
            }
            SPINOR_LOG_INFO("%s: Info, SPINOR exit deep power down \r\n", __func__);
        }

        fdSetLowPowerFlag((uint32_t)handle, bLowPower);
    }

    el2Unlock();
    return SPINOR_DEVICE_DONE;
}

 /**********************************************************
 * Get the Sector map information.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param pSecMapInfo [IN]
 *   Pointer to the address that will store the sector map information.
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2GetSectorMapInfo ( spinor_handle_t handle, spinorSectorMapInfoType *secMapInfo, uint32_t *pwd)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
    uint32_t ulFdCount = 0;

    if ( FALSE == gel2Ctxt.bInitDone )
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x6A);
        SPINOR_LOG_ERROR_EL2("%s: Error, initialization not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    if (NULL == gel2Ctxt.spinorHandle)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x6B);
        SPINOR_LOG_ERROR_EL2("%s: Error, handle is NULL \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    el2Lock();

    /* Check if the handle is valid entry in the list of file descriptors */
    if (FALSE == fdIsValid((uint32_t)handle))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x6C);
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid handle \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Validate the password */
    if (FALSE == fdIsPwdValid((uint32_t)handle,pwd))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,(uint32_t)handle,0x6D);
        SPINOR_LOG_ERROR_EL2("%s: Error, password is invalid \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Populate the sec map with the region info from the EL2 context */
    *secMapInfo = gel2Ctxt.el2SectorMapInfo;

    el2Unlock();
    return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * Reads from DLP partition to check if the SPINOR device is alive
 *
 * @param none
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2IsDeviceAlive(void)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

  if ( FALSE == gel2Ctxt.bInitDone )
  {
      el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x6E);
      SPINOR_LOG_ERROR_EL2("%s: Error, initialization not done \r\n", __func__);
      return SPINOR_DEVICE_FAIL;
  }

  status = spinor_is_device_alive();

  return status;
}

/**********************************************************
 * Reconfigures the MUX
 *
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2ReconfigureMUX(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

    status = spinor_switch_mux_config();

    return status;
}

/**********************************************************
 * Dumps the SFDP table
 *
 * @param none
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2SFDPDump(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

    if (FALSE == gel2Ctxt.bInitDone)
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x6F);
        SPINOR_LOG_ERROR_EL2("%s: Error, initialization not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    status = spinor_sfdp_dump();

    return status;
}

/**********************************************************
 * Resets the handles upon SW reset
 *
 * @param resetCoreID [IN]
 *   Core ID that got reset.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2SWResetClose(uint32_t resetCoreID)
{
    SPINOR_STATUS ret = SPINOR_DEVICE_DONE;

    /* Clear the read buffers for the core */
    gel2Ctxt.El1ReadbufEntry[resetCoreID].ulStartAddr = 0;
    gel2Ctxt.El1ReadbufEntry[resetCoreID].ulSize = 0;

    /* Reset the FDs for the core */
    fdResetonSWreset(resetCoreID);

    /* Check if the reset requires recovering the SPI BUS */
    ret = el2MultiCoreSafeResCrashRecover(resetCoreID);

    return ret;
}

/**********************************************************
 * Get the usertype for the handle.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param eAttrib [IN/OUT]
 *   Pointer to address that contains User type for the handle.
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2GetUserType( spinor_handle_t handle, eSpinorUserType* usertype, uint32_t *pwd)
{
    el2Lock();

    /* Check if the handle is valid entry in the list of file descriptors */
    if (FALSE == fdIsValid((uint32_t)handle))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,0,0x70);
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid handle \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    /* Validate the password */
    if (FALSE == fdIsPwdValid((uint32_t)handle,pwd))
    {
        el2Log(&gel2Ctxt.xdbgLogs,EL2_ERR_CLASS_CLIENT,(uint32_t)handle,0x71);
        SPINOR_LOG_ERROR_EL2("%s: Error, password is invalid \r\n", __func__);
        el2Unlock();
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

   *usertype =  fdGetUserType ( (uint32_t)handle );

    fdUpdatePwd((uint32_t)handle, pwd);

    el2Unlock();
    return SPINOR_DEVICE_DONE;
}
