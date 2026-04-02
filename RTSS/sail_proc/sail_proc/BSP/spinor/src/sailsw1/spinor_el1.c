
/*
===========================================================================
*/
/**
    @file  spinor_el1.c
    @brief Implementation of spinor EL1 Support functions

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/sailsw1/spinor_el1.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/


#include "spinor_el1_api.h"
#include "spinor_el1.h"
#include "spinor_el1_trap.h"
#include "sailbsp_mutex.h"

#include "debug_log.h"
#include "syscall_pub.h"
#include "spinor_trap_defs.h"

#include "FreeRTOSOsal.h"
#include "common_functions.h"
#include "err_fatal.h"

/* SPINOR EL1 Log buffer size */
#define SPINOR_EL1_ERR_LOG_SIZE  32

/* Max 4k blocks allowed to be erased from EL1 at a time */
#define SPINOR_MAX_BLOCKS_ERASE_EL1  1
/* Max bytes allowed to be written from EL1 at a time */
#define SPINOR_MAX_BYTES_WRITE_EL1   4096
/* Max bytes allowed to be read from EL1 at a time */
#define SPINOR_MAX_BYTES_READ_EL1    4096

/* Log Range: 1(0x1) to 76(0x4C) */

/** Error log format
*  0xXXYYZZZZ
*
*    0xXX -> 1-byte for classifying the source of the error
*
*                 1-  client errors errors
*                 2-  El1 layer
*                 3-  EL2 layer
*
*    0xYY      -> 1-byte for the handle/File descriptor id to track the client 0 represents EL2 layer itself
*    0xZZZZ    -> 2-bytes for actual error codes
*/

typedef enum
{
    EL1_ERR_CLASS_CLIENT = 1,  /* Errors/Warnings Originating from Clients */
    EL1_ERR_CLASS_EL1,         /* Errors/Warnings from EL1 layer */
    EL1_ERR_CLASS_EL2,         /* Errors/Warnings from EL2 layer */
    EL2_ERR_CLASS_MAX = 0xFF   /* Max classification type */
}EL1ErrClassType_e;

/* SPINOR EL1 Operation Type */
typedef enum
{
    SPINOR_EL1_NONE = 0,
    SPINOR_EL1_READ,
    SPINOR_EL1_WRITE,
    SPINOR_EL1_ERASE,
    SPINOR_EL1_SPICMD
}spinorEl1OpType;

/* Flash Error Log */
typedef struct
{
  boolean bInitDone;
  mutex_t xEl1LogMutex;
  uint8  ucSpinorEL1ErrIndex;
  uint32 usSpinorEL1ErrCodes[SPINOR_EL1_ERR_LOG_SIZE];
} spinorEl1logsType;

/* SPINOR EL1 Context Type */
typedef struct
{
    spinorEl1logsType xdbgLogs;
    spinorSectorMapInfoType el1SectorMapInfo;
    uint32_t el1SectorMapAlignmentAddr;
    mutex_t mutex;
    boolean bInitDone;
    uint32 pwd;          /* Dummy password, used to pass the address for the dummy user password */
    uint8 GlobalTransID; /* Global for transaction ID */
    boolean el1_bincmdlock_acquired;
} spinorEl1ContextType;

/* SPINOR EL1 Operation Parameters */
typedef struct
{
    spinorEl1OpType opType;
    uint32 byte_offset;
    uint32 byte_count;
    const void* buffer;
}spinorEl1OpParamType;

typedef struct
{
    spinor_handle_t handle;                         /* SPINOR client handle*/
    eSpinorUserType eUserType;                      /* SPINOR EL1 client user type */
    spinorEl1OpParamType opParam;                   /* SPINOR client operation parameters */
    spinorEl1CallbackType spinorCallback;           /* SPINOR client callback function if provided */
    SPINOR_STATUS status;                           /* Variable to update the operation status */
    uint8 trans_ID;                                 /* Variable to hold transaction ID */
}spinorEl1QueueItemType;

typedef struct
{
    spinor_handle_t handle;                         /* SPINOR client handle*/
    SPINOR_STATUS status;                          /* Pointer to update the operation status */
    uint8 trans_ID;                                 /* Variable to hold transaction ID */
}spinorEl1NotifyQueueItemType;

/* Task Init Macros */
#define SPINOR_EL1_TASK_STACK_SIZE    ( 4096 )

/* Queue Init Macros */
#define SPINOR_EL1_Q_LENGTH           ( 1 )
#define SPINOR_EL1_Q_ITEM_SIZE        ( sizeof(spinorEl1QueueItemType) )
#define SPINOR_EL1_Q_BUFFER_SIZE      ( SPINOR_EL1_Q_LENGTH * SPINOR_EL1_Q_ITEM_SIZE )

#define SPINOR_EL1_NOTIFY_Q_LENGTH           ( 1 )
#define SPINOR_EL1_NOTIFY_Q_ITEM_SIZE        ( sizeof(spinorEl1NotifyQueueItemType) )
#define SPINOR_EL1_NOTIFY_Q_BUFFER_SIZE      ( SPINOR_EL1_NOTIFY_Q_LENGTH * SPINOR_EL1_NOTIFY_Q_ITEM_SIZE )

#define SPINOR_LOC_QUEUE_SIZE  5

/* Task Init Definitions */
static StaticTask_t xSpinorEl1TaskTCB = { 0 };
static StackType_t xSpinorEl1TaskStack[ SPINOR_EL1_TASK_STACK_SIZE ] __attribute__( ( aligned( MEM_ALIGNMENT_64 ) ) ) = { 0 };
static TaskHandle_t xSpinorEl1TaskInitHandle = NULL;

static const char* pcSpinorEl1TaskName = "spinor_el1_task";
/* Queue Buffers and Handles definitions */
uint8_t xSpinorEl1QueueBuffer[ SPINOR_EL1_Q_BUFFER_SIZE ] __attribute__( ( aligned( MEM_ALIGNMENT_4 ) ) ) = { 0 };
SPINOR_UNPRIV_DATA QueueHandle_t xSpinorEl1QueueHandle = NULL;
static StaticQueue_t xSpinorEl1QueueBufferStatic;

uint8_t xSpinorEl1NotifyQueueBuffer[ SPINOR_EL1_NOTIFY_Q_BUFFER_SIZE ] __attribute__( ( aligned( MEM_ALIGNMENT_4 ) ) ) = { 0 };
SPINOR_UNPRIV_DATA QueueHandle_t xSpinorEl1NotifyQueueHandle = NULL;
static StaticQueue_t xSpinorEl1NotifyQueueBufferStatic;

/* SPINOR Local queue */
/* Initialize front and rear pointers for local queue */
typedef struct
{
    uint8 writePtr;
    uint8 readPtr;
    uint8 numItems;
    spinorEl1QueueItemType Queue[SPINOR_LOC_QUEUE_SIZE];
}SpinorLocQueueType;

SPINOR_UNPRIV_DATA static SpinorLocQueueType spinorLocalQueue;

SPINOR_UNPRIV_DATA static spinorEl1ContextType gEl1Ctxt = {0};

SPINOR_UNPRIV_DATA static uint8_t guSpinorEl1ReadBuf[SPINOR_MAX_BYTES_READ_EL1] __attribute__ ((aligned(EL_SHARED_CACHELINE_SIZE))); /* align to cache line in case doing cache invalidation only */

/**********************************************************
 * Initialize OSPI EL1 Logs
 *
 * @param type void [IN]
 *   None
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
SPINOR_FUNC static void el1LogInit(void)
{
    /* Initalize the mutex for the debug logs */
    mutex_init(&gEl1Ctxt.xdbgLogs.xEl1LogMutex);
    gEl1Ctxt.xdbgLogs.bInitDone = TRUE;
}

/**********************************************************
 * Logs OSPI EL1 codes
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
SPINOR_FUNC static void el1Log(spinorEl1logsType *pErrLog, EL1ErrClassType_e xErrClass, uint32 ulHandle, uint16 usErrCode)
{
    if( TRUE == gEl1Ctxt.xdbgLogs.bInitDone)
    {
      mutex_lock(&gEl1Ctxt.xdbgLogs.xEl1LogMutex);
      if (pErrLog->ucSpinorEL1ErrIndex >= SPINOR_EL1_ERR_LOG_SIZE)
      {
        pErrLog->ucSpinorEL1ErrIndex = 0;
      }
      pErrLog->usSpinorEL1ErrCodes[pErrLog->ucSpinorEL1ErrIndex++] = (xErrClass << 24) | ((ulHandle & 0xFF) << 16 ) | usErrCode;
      mutex_unlock(&gEl1Ctxt.xdbgLogs.xEl1LogMutex);
    }

    return;
}

/**********************************************************
 * Locks access to the OSPI EL1 driver
 *
 * @param none
 *
 * @return void [OUT]
 *
 **********************************************************/
SPINOR_FUNC static uint32_t el1Lock(void)
{
    boolean status;
    spinorTrapParams_t trapParam={0};

    trapParam.resLockParam.coreid = get_curr_phys_cpu_num();

    status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_RESLOCK, &trapParam);
    if (status == FALSE)
    {
        return 0;
    }
    return 1;

}

/**********************************************************
 * Unlocks access to OSPI EL1 driver
 *
 * @param none
 *
 * @return void [OUT]
 *
 **********************************************************/
SPINOR_FUNC static void el1Unlock(void)
{
    boolean status;
    spinorTrapParams_t trapParam={0};

    trapParam.resLockParam.coreid = get_curr_phys_cpu_num();

    status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_RESUNLOCK, &trapParam);

    if (status == FALSE)
    {
        DEBUG_LOG( SAIL_ERROR,"%s: Error, EL1 unlock failed \r\n", __func__);
        err_fatal(SPINOR, SPINOR_DEVICE_FAIL);
    }
}

/**********************************************************
 * Gets the user type for the handle
 *
 * @param handle [IN] Handle for the Spinor client
 *
 * @return eSpinorUserType [OUT] User type for the handle
 *
 **********************************************************/
SPINOR_FUNC static eSpinorUserType el1GetUserType(spinor_handle_t handle)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinorTrapHandle_t h;
    spinorTrapParams_t trapParam={0};
    eSpinorUserType usertype = SPINOR_USER_TYPE_MAX;

    /* Construct the Trap handle structure */
    h.handle = handle;
    h.pwd = &gEl1Ctxt.pwd;

    trapParam.getUserTypeParam.h = &h;
    trapParam.getUserTypeParam.userType = &usertype;
    status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_GETUSERTYPE, &trapParam);
    if (status != SPINOR_DEVICE_DONE)
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL2,(uint32_t)handle,0x1);
        DEBUG_LOG( SAIL_ERROR,"%s: Error, Get user type call failed \r\n", __func__);
        return SPINOR_USER_TYPE_MAX;
    }

    return usertype;
}

/**********************************************************
 * SPINOR Local Queue Init
 *
 * @param none
 *
 * @return void [OUT]
 *
 **********************************************************/
SPINOR_STATUS spinor_local_queue_init(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

    spinorLocalQueue.writePtr = 0;
    spinorLocalQueue.readPtr = 0;
    spinorLocalQueue.numItems = 0;
    memset(spinorLocalQueue.Queue, 0, sizeof(spinorLocalQueue.Queue));

    status = SPINOR_DEVICE_DONE;
    return status;
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
static SPINOR_STATUS el1GetNum4kBlock(uint32_t addr, spinor_getnum4kblockType *block_info)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

    if(block_info == NULL)
    {
        status = SPINOR_DEVICE_INVALID_PARAMETER;
        goto el1GetNum4kBlock_end;
    }

    for (int idx = 0; idx < sizeof(gEl1Ctxt.el1SectorMapInfo.sectorMapInfo) / sizeof(gEl1Ctxt.el1SectorMapInfo.sectorMapInfo[0]); idx++)
    {
        if ( (addr >= gEl1Ctxt.el1SectorMapInfo.sectorMapInfo[idx].start_range) && (addr <= gEl1Ctxt.el1SectorMapInfo.sectorMapInfo[idx].end_range))
        {
          block_info->block_num = gEl1Ctxt.el1SectorMapInfo.sectorMapInfo[idx].er_size_KB/4;
          block_info->idx = idx;
          status = SPINOR_DEVICE_DONE;
          goto el1GetNum4kBlock_end;
        }
    }

el1GetNum4kBlock_end:
    return status;
}

/**********************************************************
 * Initialize OSPI EL1 driver
 *
 * @param type [IN]
 *   None
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS el1Init(void)
{
    uint64 ret;
    spinorTrapParams_t trapParam={0};
    spinor_handle_t handle;
    uint32_t max_er_size = 0;

    boolean status;
    if ( TRUE == gEl1Ctxt.bInitDone )
    {
        // already initialized
        return 0;
    }

    /* Initalize SPINOR EL1 logs */
    el1LogInit();

    trapParam.initParam.type = SPINOR_INIT_TYPE_DEFAULT;

    status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_INIT, &trapParam);
    if (status == FALSE)
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL2,0,0x2);
        DEBUG_LOG( SAIL_ERROR, "%s: Error, el1 init failed \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    trapParam=(spinorTrapParams_t){0};

    trapParam.readBufRegParam.addr = (uint32_t)guSpinorEl1ReadBuf;
    trapParam.readBufRegParam.size = sizeof(guSpinorEl1ReadBuf)/sizeof(guSpinorEl1ReadBuf[0]);

    status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_INIT_READBUF_REG, &trapParam);
    if (status != SPINOR_DEVICE_DONE)
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL2,0,0x3);
        DEBUG_LOG( SAIL_ERROR, "%s: Error, el1 init Read Buffer Region failed \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    /* Initialize SPINOR Local Queue */
    status = spinor_local_queue_init();
    if (status != SPINOR_DEVICE_DONE)
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL1,(uint32_t)handle,0x4);
        DEBUG_LOG(SAIL_ERROR, "%s: Error, el1 local queue init failed \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    gEl1Ctxt.bInitDone = TRUE;

    /* Obtain SPINOR Sector map Info */
    status = el1Open(&handle, SPINOR_USER_TYPE_EL1);
    if (status != SPINOR_DEVICE_DONE)
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL2,(uint32_t)handle,0x5);
        DEBUG_LOG( SAIL_ERROR, "%s: Error, el1 Open failed \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    status = el1GetSectorMapInfo(handle, &gEl1Ctxt.el1SectorMapInfo);
    if (status != SPINOR_DEVICE_DONE)
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL2,(uint32_t)handle,0x6);
        DEBUG_LOG( SAIL_ERROR, "%s: Error, el1 GetSecMapInfo failed \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    /* Checking the value to which addresses should be aligned */
    for (int idx = 0; idx < sizeof(gEl1Ctxt.el1SectorMapInfo.sectorMapInfo) / sizeof(gEl1Ctxt.el1SectorMapInfo.sectorMapInfo[0]); idx++)
    {
        if(gEl1Ctxt.el1SectorMapInfo.sectorMapInfo[idx].er_size_KB > max_er_size)
        {
            max_er_size = gEl1Ctxt.el1SectorMapInfo.sectorMapInfo[idx].er_size_KB;
        }
    }

    gEl1Ctxt.el1SectorMapAlignmentAddr = max_er_size * 1024;

    /* Close the handle */
    status = el1Close(handle);
    if (status != SPINOR_DEVICE_DONE)
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL2,(uint32_t)handle,0x7);
        DEBUG_LOG( SAIL_ERROR, "%s: Error, el1 Open failed \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * De-initialize OSPI EL1 driver
 *
 * @param none
 *
 * @return void [OUT]
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS el1DeInit( void )
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t val;
    spinorTrapParams_t trapParam={0};

    if(TRUE == gEl1Ctxt.bInitDone)
    {
        while(1)
        {
            /* lock the EL1 */
            val = el1Lock();

            if(val)
            {
                trapParam.deinitParam.param = 0;
                status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_DEINIT, &trapParam);
                if(status != SPINOR_DEVICE_DONE)
                {
                    DEBUG_LOG( SAIL_ERROR,"%s: Error, el1 deinit failed \r\n", __func__);
                }

                memset(&gEl1Ctxt, 0, sizeof(gEl1Ctxt));
                el1Unlock();

                return status;
            }
            else
            {
                if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
                {
                    vFreeRTOSTaskDelay(1);
                }
            }
        }
    }
    return status;
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
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS el1Open( spinor_handle_t *handle, eSpinorUserType eUserType)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinorTrapHandle_t h;
    uint32_t val;
    spinorTrapParams_t trapParam={0};

    *handle = NULL;

    if (( FALSE == gEl1Ctxt.bInitDone )  || ((SPINOR_USER_TYPE_EL1 != eUserType) && (SPINOR_USER_TYPE_EL1_SUPER != eUserType) && (SPINOR_USER_TYPE_OTA != eUserType) ))
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_CLIENT,0,0x8);
        DEBUG_LOG( SAIL_ERROR,"%s: Error, initialization not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    while(1)
    {
        /* lock the EL1 */
        val = el1Lock();

        if(val)
        {
            /* Construct the Trap handle structure */
            h.handle = (spinor_handle_t)handle;
            h.pwd = &gEl1Ctxt.pwd;

            trapParam.openParam.h = &h;
            trapParam.openParam.eUserType = eUserType;

            status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_OPEN, &trapParam);
            if (status != SPINOR_DEVICE_DONE)
            {
                el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL2,(uint32_t)*handle,0x9);
                DEBUG_LOG( SAIL_ERROR,"%s: Error, el1 open failed \r\n", __func__);
                el1Unlock();
                return status;
            }

            el1Unlock();

            return SPINOR_DEVICE_DONE;
        }
        else
        {
             if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
            {
                vFreeRTOSTaskDelay(1);
            }
        }
    }
}

/**********************************************************
 * Closes handle to a spinor service.
 * Clients should close the handle when accesses to
 * the device is no longer needed.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS el1Close( spinor_handle_t handle)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinorTrapHandle_t h;
    uint32_t val;
    spinorTrapParams_t trapParam={0};

    if ( FALSE == gEl1Ctxt.bInitDone )
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_CLIENT,0,0xA);
        DEBUG_LOG( SAIL_ERROR,"%s: Error, init not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    while(1)
    {
        /* lock the EL1 */
        val = el1Lock();

        if(val)
        {
            /* Construct the Trap handle structure */
            h.handle = handle;
            h.pwd = &gEl1Ctxt.pwd;

            trapParam.closeParam.h = &h;
            status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_CLOSE, &trapParam);
            if (status != SPINOR_DEVICE_DONE)
            {
                el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL2,(uint32_t)handle,0xB);
                DEBUG_LOG( SAIL_ERROR,"%s: Error, el1 close failed \r\n", __func__);
                el1Unlock();
                return status;
            }

            el1Unlock();

            return SPINOR_DEVICE_DONE;
        }
        else
        {
             if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
            {
                vFreeRTOSTaskDelay(1);
            }
        }
    }

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
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS el1GetGptPartitionInfo( spinor_handle_t handle, const char *guid, uint32_t *pulStartAddr, uint32_t *pulSize)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinorTrapHandle_t h;
    uint32_t val;
    spinorTrapParams_t trapParam={0};

    spinorTrapRegionInfo_t xRegionInfo = {0};

    if ( FALSE == gEl1Ctxt.bInitDone )
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_CLIENT,0,0xC);
        DEBUG_LOG( SAIL_ERROR,"%s: Error, init not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    while(1)
    {
        /* lock the EL1 */
        val = el1Lock();

        if(val)
        {
            /* Construct the Trap handle structure */
            h.handle = handle;
            h.pwd = &gEl1Ctxt.pwd;

            trapParam.gptPartInfoParam.h = &h;
            trapParam.gptPartInfoParam.guid = guid;
            trapParam.gptPartInfoParam.pRegion = &xRegionInfo;

            status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_GET_PARTITION_INFO, &trapParam);
            if (status != SPINOR_DEVICE_DONE)
            {
                *pulStartAddr = 0;
                *pulSize = 0;
                el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL2,(uint32_t)handle,0xD);
                DEBUG_LOG( SAIL_ERROR,"%s: Error, el1 getgpt partition info failed \r\n", __func__);
                el1Unlock();
                return status;
            }

            *pulStartAddr = xRegionInfo.base;
            *pulSize = xRegionInfo.size;

            el1Unlock();

            return SPINOR_DEVICE_DONE;
        }
        else
        {
             if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
            {
                vFreeRTOSTaskDelay(1);
            }
        }
    }
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
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS el1SetPartitionAttrib( spinor_handle_t handle, const char *guid,  eSpinorProtectType eAttrib )
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinorTrapHandle_t h;
    uint32_t val;
    spinorTrapParams_t trapParam={0};

    spinorTrapRegionInfo_t xRegionInfo = {0};

    if ( FALSE == gEl1Ctxt.bInitDone )
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_CLIENT,0,0xE);
        DEBUG_LOG( SAIL_ERROR,"%s: Error, init not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    while(1)
    {
        /* lock the EL1 */
        val = el1Lock();

        if(val)
        {
            /* Construct the Trap handle structure */
            h.handle = handle;
            h.pwd = &gEl1Ctxt.pwd;

            trapParam.setPartAttribParam.h = &h;
            trapParam.setPartAttribParam.guid = guid;
            trapParam.setPartAttribParam.eAttrib = eAttrib;

            status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_SET_PARTITION_ATTRIB, &trapParam);
            if (status != SPINOR_DEVICE_DONE)
            {
                el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL2,(uint32_t)handle,0xF);
                DEBUG_LOG( SAIL_ERROR,"%s: Error, el1 Set partition attribute failed \r\n", __func__);
                el1Unlock();
                return status;
            }

            el1Unlock();

            return SPINOR_DEVICE_DONE;
        }
        else
        {
             if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
            {
                vFreeRTOSTaskDelay(1);
            }
        }
    }
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
 * @param eAttrib [IN/OUT]
 *   Pointer to address that contains Protection type for the region.
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS el1GetPartitionAttrib( spinor_handle_t handle, const char *guid,  eSpinorProtectType* eAttrib )
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinorTrapHandle_t h;
    uint32_t val;
    spinorTrapParams_t trapParam={0};

    spinorTrapRegionInfo_t xRegionInfo = {0};

    if ( FALSE == gEl1Ctxt.bInitDone )
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_CLIENT,0,0x10);
        DEBUG_LOG( SAIL_ERROR,"%s: Error, init not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    while(1)
    {
        /* lock the EL1 */
        val = el1Lock();

        if(val)
        {
            /* Construct the Trap handle structure */
            h.handle = handle;
            h.pwd = &gEl1Ctxt.pwd;

            trapParam.getPartAttribParam.h = &h;
            trapParam.getPartAttribParam.guid = guid;
            trapParam.getPartAttribParam.eAttrib = eAttrib;

            status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_GET_PARTITION_ATTRIB, &trapParam);
            if (status != SPINOR_DEVICE_DONE)
            {
                el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL2,(uint32_t)handle,0x11);
                DEBUG_LOG( SAIL_ERROR,"%s: Error, el1 Get partition attribute failed \r\n", __func__);
                el1Unlock();
                return status;
            }

            el1Unlock();

            return SPINOR_DEVICE_DONE;
        }
        else
        {
            if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
            {
                vFreeRTOSTaskDelay(1);
            }
        }
    }
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
SPINOR_FUNC SPINOR_STATUS el1GetSectorMapInfo( spinor_handle_t handle, spinorSectorMapInfoType *pSecMapInfo )
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinorTrapHandle_t h;
    uint32_t val;
    spinorTrapParams_t trapParam={0};

    if ( FALSE == gEl1Ctxt.bInitDone )
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_CLIENT,0,0x12);
        DEBUG_LOG( SAIL_ERROR,"%s: Error, init not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    while(1)
    {
        /* lock the EL1 */
        val = el1Lock();

        if(val)
        {
            /* Construct the Trap handle structure */
            h.handle = handle;
            h.pwd = &gEl1Ctxt.pwd;

            trapParam.secMapInfoParam.h = &h;
            trapParam.secMapInfoParam.secMapInfo = pSecMapInfo;

            status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_GET_SECTOR_MAP_INFO, &trapParam);
            if (status != SPINOR_DEVICE_DONE)
            {
                el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL2,(uint32_t)handle,0x13);
                DEBUG_LOG( SAIL_ERROR,"%s: Error, el1 Get Sector Map info failed \r\n", __func__);
                el1Unlock();
                return status;
            }

            el1Unlock();

            return SPINOR_DEVICE_DONE;
        }
        else
        {
             if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
            {
                vFreeRTOSTaskDelay(1);
            }
        }
    }
}

/**********************************************************
 * Erases given spinor blocks
 *
 * @param handle [IN]
 *   SPINOR service interface handle
 *
 * @param start_block [IN]
 *   A starting block for a number of blocks to erase.
 *
 * @param block_count [IN]
 *   Number of blocks to erase
 *
 * @param eraseCallback[IN]
 *   Spinor callback function
 *
 * @param userdata[IN/OUT]
 *   Returs user data via callback function
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS el1Erase( spinor_handle_t handle,uint32 start_block, uint32 block_count, spinorEl1CallbackType eraseCallback, spinorEl1userdata *userdata)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinorTrapHandle_t h;
    uint32_t block_count_max;
    uint32_t val;
    spinorTrapParams_t trapParam={0};
    spinorEl1QueueItemType spinorEl1EraseQueueItem = {0};
    spinorEl1NotifyQueueItemType spinorEl1statusQueueItem ={0};
    BaseType_t xResult;
    uint32 start_addr = start_block * 4096, end_addr = ((start_block + block_count) * 4096) - 1;
    spinor_getnum4kblockType el1BlockInfo = {0};

    if ( FALSE == gEl1Ctxt.bInitDone )
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_CLIENT,0,0x14);
        DEBUG_LOG( SAIL_ERROR,"%s: Error, init not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    /* Return failure if called from IRQ mode */
    if(TRUE == xSyscallIsIrqMode())
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_CLIENT,0,0x15);
        DEBUG_LOG( SAIL_ERROR,"%s: Error, return fail as erase called from IRQ mode \r\n", __func__);
        return SPINOR_DEVICE_NOT_SUPPORTED;
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
    status = el1GetNum4kBlock(start_addr, &el1BlockInfo);
    if(status != SPINOR_DEVICE_DONE)
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL1,(uint32_t)handle,0x16);
        DEBUG_LOG(SAIL_ERROR,"%s: Error, el2GetNum4kBlock failed \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    if(el1BlockInfo.block_num > 1)
    {
        if((start_addr & (gEl1Ctxt.el1SectorMapAlignmentAddr - 1)) != 0)
        {
            if(start_addr != gEl1Ctxt.el1SectorMapInfo.sectorMapInfo[el1BlockInfo.idx].start_range)
            {
                //Address is unaligned to any end address or 256KB boundary
                el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL1,(uint32_t)handle,0x17);
                DEBUG_LOG(SAIL_ERROR,"%s: Error, erase start address unaligned to the boundary \r\n", __func__);
                return SPINOR_ERASE_BLOCK_INVALID;
            }
        }
    }

    /* End Address check - Check alignment to next 256KB */
    status = el1GetNum4kBlock(end_addr, &el1BlockInfo);
    if(status != SPINOR_DEVICE_DONE)
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL1,(uint32_t)handle,0x18);
        DEBUG_LOG(SAIL_ERROR,"%s: Error, el2GetNum4kBlock failed \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    if(el1BlockInfo.block_num > 1)
    {
        if(((end_addr + 1) & (gEl1Ctxt.el1SectorMapAlignmentAddr - 1)) != 0)
        {
            if(end_addr != gEl1Ctxt.el1SectorMapInfo.sectorMapInfo[el1BlockInfo.idx].end_range)
            {
                //Address is unaligned to any end address or 256KB boundary
                el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL1,(uint32_t)handle,0x19);
                DEBUG_LOG(SAIL_ERROR,"%s: Error, erase end address unaligned to the boundary \r\n", __func__);
                return SPINOR_ERASE_BLOCK_INVALID;
            }
        }
    }

     if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
    {
        spinorEl1EraseQueueItem.handle = handle;
        spinorEl1EraseQueueItem.eUserType = el1GetUserType(handle);
        spinorEl1EraseQueueItem.spinorCallback = eraseCallback;
        spinorEl1EraseQueueItem.status = status;
        spinorEl1EraseQueueItem.opParam.opType = SPINOR_EL1_ERASE;
        spinorEl1EraseQueueItem.opParam.buffer = NULL;
        spinorEl1EraseQueueItem.opParam.byte_offset = start_block;
        spinorEl1EraseQueueItem.opParam.byte_count = block_count;
        spinorEl1EraseQueueItem.trans_ID = ++gEl1Ctxt.GlobalTransID;

        //TODO: check if the handle is unique and not already present in the local queue

        //DEBUG_LOG(SAIL_INFO, "%s: Queuing Erase Msg to SPINOR task queue.\n\r", __func__);
        xResult = xFreeRTOSQueueSend(xSpinorEl1QueueHandle, &spinorEl1EraseQueueItem, pdMS_TO_TICKS(freertosMAX_DELAY));
        if (pdPASS == xResult)
        {
            //DEBUG_LOG(SAIL_INFO, "%s: Msg queued from Erase. !\n\r", __func__);
            status = SPINOR_DEVICE_OK_NOT_DONE;
        }
        else if (errQUEUE_FULL == xResult)
        {
            //queuing failed as queue full
            el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL1, (uint32_t)handle, 0x4D);
            DEBUG_LOG(SAIL_INFO, "%s: Error,in Queuing to SafeRTOS queue, queue full \r\n", __func__);
            status = SPINOR_ACCESS_NO_BUS;
        }
        else
        {
            el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL1, (uint32_t)handle, 0x1A);
            DEBUG_LOG(SAIL_ERROR, "%s: Error,in Queuing to SPINOR task queue block=0x%x, size=0x%x\r\n", __func__, start_block, block_count);
            return SPINOR_DEVICE_FAIL;
        }
        //DEBUG_LOG(SAIL_INFO, "%s: Erase Msg queued to SPINOR task queue. Waiting for result !\n\r", __func__);

        if (spinorEl1EraseQueueItem.spinorCallback == NULL)
        {
            //DEBUG_LOG(SAIL_INFO, "%s: Waiting for Erase Status Notification !\n\r", __func__);

            while(1)
            {
                xResult = xFreeRTOSQueuePeek(xSpinorEl1NotifyQueueHandle, &spinorEl1statusQueueItem, freertosMAX_DELAY);
                if (pdPASS == xResult)
                {
                    status = SPINOR_DEVICE_DONE;
                }
                else if(errQUEUE_EMPTY == xResult)
                {
                    status = SPINOR_ACCESS_NO_BUS;
                    DEBUG_LOG(SAIL_INFO, "%s: Error,in Queue peek to SafeRTOS queue, queue empty \r\n", __func__);
                    err_fatal(SPINOR, status);
                }
                else
                {
                    status = SPINOR_DEVICE_FAIL;
                    el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL1,(uint32_t)handle,0x1B);
                    DEBUG_LOG(SAIL_ERROR, "%s: Peek from Notify Queue failed \n\r", __func__);
                    err_fatal(SAFERTOS, xResult);
                }

                if(spinorEl1statusQueueItem.handle == spinorEl1EraseQueueItem.handle && spinorEl1statusQueueItem.trans_ID == spinorEl1EraseQueueItem.trans_ID)
                {
                    break;
                }
                else
                {
                     if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
                    {
                        vFreeRTOSTaskDelay(1);
                    }
                }
            }

            xResult = xFreeRTOSQueueReceive(xSpinorEl1NotifyQueueHandle, &spinorEl1statusQueueItem, freertosMAX_DELAY);
            if (pdPASS == xResult)
            {
                status = SPINOR_DEVICE_DONE;
            }
            else if(errQUEUE_EMPTY == xResult)
            {
                status = SPINOR_ACCESS_NO_BUS;
                DEBUG_LOG(SAIL_INFO, "%s: Error,in Queue receive from SafeRTOS queue, queue empty \r\n", __func__);
                err_fatal(SPINOR, status);
            }
            else
            {
                status = SPINOR_DEVICE_FAIL;
                el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL1,(uint32_t)handle,0x1C);
                DEBUG_LOG(SAIL_ERROR, "%s: Receive from Notify Queue failed \n\r", __func__);
                err_fatal(SAFERTOS, xResult);
            }

            //DEBUG_LOG(SAIL_INFO, "%s: SPINOR Erase result received. Processing !\n\r", __func__);
            status = spinorEl1statusQueueItem.status;

            if (SPINOR_DEVICE_DONE != status)
            {
                el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)handle, 0x1D);
                DEBUG_LOG(SAIL_ERROR, "%s: Error, el1 erase failed at 0x%x start block and 0x%x block count, status = 0x%x \r\n", __func__, start_block, block_count, status);
                return status;
            }

            return status;
        }
        else
        {
            /* As the operation is asynchronous, queue operation to the thread and return status here. */
            if (status == SPINOR_DEVICE_OK_NOT_DONE)
                userdata->transaction_ID = spinorEl1EraseQueueItem.trans_ID;
            else
                userdata->transaction_ID = 0xFF; //failure case

            return status;
        }
    }
    else
    {
        /* Try lock till the lock is acquired */
        while (1)
        {
            val = el1Lock();
            if (val)
            {
                break;
            }
            else
            {
                 if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
                {
                    vFreeRTOSTaskDelay(1);
                }
            }
        }

        /* Split the erases into max permissible erase blocks allowed from EL1 */
        while (block_count)
        {
            status = el1GetNum4kBlock(start_block * 4096, &el1BlockInfo);
            if(status != SPINOR_DEVICE_DONE)
            {
                status = SPINOR_DEVICE_FAIL;
                el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL1,(uint32_t)handle,0x1E);
                DEBUG_LOG(SAIL_ERROR, "%s: Error, el1GetNum4kBlock \r\n", __func__);
                el1Unlock();
                return status;
            }

            block_count_max = (block_count > el1BlockInfo.block_num) ? el1BlockInfo.block_num : block_count;

            /* Construct the Trap handle structure */
            h.handle = handle;
            h.pwd = &gEl1Ctxt.pwd;

            trapParam.eraseParam.h = &h;
            trapParam.eraseParam.start_block = start_block;
            trapParam.eraseParam.block_count = block_count_max;

            status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_ERASE, &trapParam);
            if (status != SPINOR_DEVICE_OK_NOT_DONE)
            {
                el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)handle, 0x1F);
                DEBUG_LOG(SAIL_ERROR, "%s: Error, el1 erase failed at 0x%x start block and %d block count \r\n", __func__, start_block, block_count_max);
                el1Unlock();
                return status;
            }

            /* Scheduler not started. Do the polling here */
            while (SPINOR_DEVICE_OK_NOT_DONE == status)
            {
                trapParam = (spinorTrapParams_t){ 0 };
                trapParam.mainFuncParam.h = &h;
                status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_MAINFUNC, &trapParam);
                if (status != SPINOR_DEVICE_DONE)
                {
                    el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)handle, 0x20);
                    DEBUG_LOG(SAIL_ERROR, "%s: Error, el1 erase failed at 0x%x start block and 0x%x block count \r\n", __func__, start_block, block_count_max);
                    el1Unlock();
                    return status;
                }

                trapParam = (spinorTrapParams_t){ 0 };
                trapParam.getJobResParam.h = &h;
                status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_GETJOBRESULT, &trapParam);
                if ((SPINOR_DEVICE_OK_NOT_DONE != status) && (SPINOR_DEVICE_DONE != status))
                {
                    el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)handle, 0x21);
                    DEBUG_LOG(SAIL_ERROR, "%s: Error, el1 erase failed at 0x%x start block and %d block count, status = 0x%x \r\n", __func__, start_block, block_count_max, status);
                    el1Unlock();
                    return status;
                }

                /* If the operation is done break the poll loop*/
                if (status == SPINOR_DEVICE_DONE)
                {
                    break;
                }
                else
                {
                     if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
                    {
                        vFreeRTOSTaskDelay(1);
                    }
                }
            }

            start_block = start_block + block_count_max;
            block_count = block_count - block_count_max;

        }

        el1Unlock();
        return SPINOR_DEVICE_DONE;
    }
}

/**********************************************************
 * Writes data to the spinor.
 *
 * @param handle [IN]
 *   SPINOR service interface handle
 *
 * @param byte_offset [IN]
 *   Byte offset from the start of the region to write to.
 *
 * @param byte_count [IN]
 *   Number of bytes to write data.
 *
 * @param buffer [IN]
 *   Data buffer for spinor write operation.
 *
 * @param writeCallback[IN]
 *   Spinor callback function
 *
 * @param userdata[IN/OUT]
 *   Returs user data via callback function
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS el1Write( spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, const void *buffer, spinorEl1CallbackType writeCallback, spinorEl1userdata* userdata)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinorTrapRWRegionParam_t xRWParamInfo;
    spinorTrapHandle_t h;
    uint32_t transfer_size;
    uint32_t val;
    spinorTrapParams_t trapParam={0};
    spinorEl1QueueItemType spinorEl1WriteQueueItem = {0};
    spinorEl1NotifyQueueItemType spinorEl1statusQueueItem ={0};
    BaseType_t xResult;

    if ( FALSE == gEl1Ctxt.bInitDone )
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_CLIENT,0,0x22);
        DEBUG_LOG( SAIL_ERROR,"%s: Error, init not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    /* Return failure if called from IRQ mode */
    /*if(TRUE == xSyscallIsIrqMode())
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_CLIENT,0,0x23);
        DEBUG_LOG( SAIL_ERROR,"%s: Error, return failure as write called from IRQ mode \r\n", __func__);
        return SPINOR_DEVICE_NOT_SUPPORTED;
    }*/

     if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
    {
        spinorEl1WriteQueueItem.handle = handle;
        spinorEl1WriteQueueItem.eUserType = el1GetUserType(handle);
        spinorEl1WriteQueueItem.spinorCallback = writeCallback;
        spinorEl1WriteQueueItem.status = status;
        spinorEl1WriteQueueItem.opParam.opType = SPINOR_EL1_WRITE;
        spinorEl1WriteQueueItem.opParam.buffer = buffer;
        spinorEl1WriteQueueItem.opParam.byte_offset = byte_offset;
        spinorEl1WriteQueueItem.opParam.byte_count = byte_count;
        spinorEl1WriteQueueItem.trans_ID = ++gEl1Ctxt.GlobalTransID;

        //TODO: check if the handle is unique and not already present in the local queue

        //DEBUG_LOG(SAIL_INFO, "%s: Queuing Write Msg to SPINOR task queue.\n\r", __func__);
        xResult = xFreeRTOSQueueSend(xSpinorEl1QueueHandle, &spinorEl1WriteQueueItem, pdMS_TO_TICKS(freertosMAX_DELAY));
        if (pdPASS == xResult)
        {
            //DEBUG_LOG(SAIL_INFO, "%s: Msg queued from Erase. !\n\r", __func__);
            status = SPINOR_DEVICE_OK_NOT_DONE;
        }
        else if (errQUEUE_FULL == xResult)
        {
            //queuing failed as queue full
            status = SPINOR_ACCESS_NO_BUS;
            DEBUG_LOG(SAIL_INFO, "%s: Error,in Queuing to FreeRTOS queue, queue full \r\n", __func__);
        }
        else
        {
            el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL1, (uint32_t)handle, 0x24);
            DEBUG_LOG(SAIL_ERROR, "%s: Error,in Queuing to SPINOR task queue addr = 0x%x, size = 0x%x\r\n", __func__, byte_offset, byte_count);
            return SPINOR_DEVICE_FAIL;
        }

        if (spinorEl1WriteQueueItem.spinorCallback == NULL)
        {
            //DEBUG_LOG(SAIL_INFO, "%s: Waiting for Write Status Notification !\n\r", __func__);

            while(1)
            {
                xResult = xFreeRTOSQueuePeek(xSpinorEl1NotifyQueueHandle, &spinorEl1statusQueueItem, freertosMAX_DELAY);
                if (pdPASS == xResult)
                {
                    status = SPINOR_DEVICE_DONE;
                }
                else if(errQUEUE_EMPTY == xResult)
                {
                    status = SPINOR_ACCESS_NO_BUS;
                    DEBUG_LOG(SAIL_INFO, "%s: Error,in Queue peek to SafeRTOS queue, queue empty \r\n", __func__);
                    err_fatal(SPINOR, status);
                }
                else
                {
                    status = SPINOR_DEVICE_FAIL;
                    el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL1,(uint32_t)handle,0x25);
                    DEBUG_LOG(SAIL_ERROR, "%s: Receive from Notify Queue failed \n\r", __func__);
                    err_fatal(SAFERTOS, xResult);
                }

                if(spinorEl1statusQueueItem.handle == spinorEl1WriteQueueItem.handle && spinorEl1statusQueueItem.trans_ID == spinorEl1WriteQueueItem.trans_ID)
                {
                    break;
                }
                else
                {
                     if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
                    {
                        vFreeRTOSTaskDelay(1);
                    }
                }
            }

            xResult = xFreeRTOSQueueReceive(xSpinorEl1NotifyQueueHandle, &spinorEl1statusQueueItem, freertosMAX_DELAY);
            if (pdPASS == xResult)
            {
                status = SPINOR_DEVICE_DONE;
            }
            else if(errQUEUE_EMPTY == xResult)
            {
                status = SPINOR_ACCESS_NO_BUS;
                DEBUG_LOG(SAIL_INFO, "%s: Error,in Queue receive from SafeRTOS queue, queue empty \r\n", __func__);
                err_fatal(SPINOR, status);
            }
            else
            {
                status = SPINOR_DEVICE_FAIL;
                el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL1,(uint32_t)handle,0x26);
                DEBUG_LOG(SAIL_ERROR, "%s: Receive from Notify Queue failed \n\r", __func__);
                err_fatal(SAFERTOS, xResult);
            }

            //DEBUG_LOG(SAIL_INFO, "%s: SPINOR Write result received. Processing !\n\r", __func__);
            status = spinorEl1statusQueueItem.status;

            if (SPINOR_DEVICE_DONE != status)
            {
                el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)handle, 0x27);
                DEBUG_LOG(SAIL_ERROR, "%s: Error, el1 write failed at 0x%x byte offset and 0x%x byte count, status = 0x%x \r\n", __func__, byte_offset, byte_count, status);
                return status;
            }

            return status;
        }
        else
        {
            /* As the operation is asynchronous, queue operation to the thread and return status here. */
            if (status == SPINOR_DEVICE_OK_NOT_DONE)
                userdata->transaction_ID = spinorEl1WriteQueueItem.trans_ID;
            else
                userdata->transaction_ID = 0xFF; //failure case

            return status;
        }
    }
    else
    {
        /* Try lock till the lock is acquired */
        while (1)
        {
            val = el1Lock();
            if (val)
            {
                break;
            }
            else
            {
                 if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
                {
                    vFreeRTOSTaskDelay(1);
                }
            }
        }

        /* Split the writes into max permissible bytes allowed from EL1 */
        while (byte_count)
        {
            transfer_size = (byte_count > SPINOR_MAX_BYTES_WRITE_EL1) ? SPINOR_MAX_BYTES_WRITE_EL1 : byte_count;

            /* Construct the Trap handle structure */
            h.handle = handle;
            h.pwd = &gEl1Ctxt.pwd;

            xRWParamInfo.byte_offset = byte_offset;
            xRWParamInfo.byte_count = transfer_size;
            xRWParamInfo.buffer = buffer;

            trapParam.writeParam.h = &h;
            trapParam.writeParam.pRWParams = &xRWParamInfo;

            status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_WRITE, &trapParam);
            if (status != SPINOR_DEVICE_OK_NOT_DONE)
            {
                el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)handle, 0x28);
                DEBUG_LOG(SAIL_ERROR, "%s: Error, el1 write failed at 0x%x address \r\n", __func__, byte_offset);
                el1Unlock();
                return status;
            }

            while (SPINOR_DEVICE_OK_NOT_DONE == status)
            {
                trapParam = (spinorTrapParams_t){ 0 };
                trapParam.mainFuncParam.h = &h;
                status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_MAINFUNC, &trapParam);
                if (status != SPINOR_DEVICE_DONE)
                {
                    el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)handle, 0x29);
                    DEBUG_LOG(SAIL_ERROR, "%s: Error, el1 write failed at 0x%x address \r\n", __func__, byte_offset);
                    el1Unlock();
                    return status;
                }

                trapParam = (spinorTrapParams_t){ 0 };
                trapParam.getJobResParam.h = &h;
                status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_GETJOBRESULT, &trapParam);
                if ((SPINOR_DEVICE_OK_NOT_DONE != status) && (SPINOR_DEVICE_DONE != status))
                {
                    el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)handle, 0x2A);
                    DEBUG_LOG(SAIL_ERROR, "%s: Error, el1 write failed at 0x%x address, status = 0x%x \r\n", __func__, byte_offset, status);
                    el1Unlock();
                    return status;
                }

                /* If the operation is done break the poll loop*/
                if (status == SPINOR_DEVICE_DONE)
                {
                    break;
                }
                else
                {
                    if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
                    {
                        vFreeRTOSTaskDelay(1);
                    }
                }
            }

            byte_offset += transfer_size;
            buffer += transfer_size;
            byte_count -= transfer_size;
        }

        el1Unlock();
        return SPINOR_DEVICE_DONE;
    }
}

/**********************************************************
 * Allows read data from the spinor
 *
 * @param handle [IN]
 *   SPINOR service interface handle
 *
 * @param byte_offset [IN]
 *   Byte offset from the start of region to read from.
 *
 * @param byte_count [IN]
 *   Number of bytes to read data.
 *
 * @param buffer [OUT]
 *   Data buffer for a spinor read operation.
 *
 * @param readCallback[IN]
 *   Spinor callback function
 *
 * @param userdata[IN/OUT]
 *   Returs user data via callback function
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS el1Read ( spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, void *buffer, spinorEl1CallbackType readCallback, spinorEl1userdata* userdata)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinorTrapRWRegionParam_t xRWParamInfo;
    spinorTrapHandle_t h;
    uint32_t transfer_size;
    uint32_t val;
    spinorTrapParams_t trapParam={0};
    size_t result = 0;
    spinorEl1QueueItemType spinorEl1ReadQueueItem = {0};
    spinorEl1NotifyQueueItemType spinorEl1statusQueueItem ={0};
    BaseType_t xResult;


    if ( FALSE == gEl1Ctxt.bInitDone )
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_CLIENT,0,0x2B);
        DEBUG_LOG( SAIL_ERROR,"%s: Error, init not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    /* Return failure if called from IRQ mode */
    if(TRUE == xSyscallIsIrqMode())
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_CLIENT,0,0x2C);
        DEBUG_LOG( SAIL_ERROR,"%s: Error, return fail as read called from IRQ mode \r\n", __func__);
        return SPINOR_DEVICE_NOT_SUPPORTED;
    }

    if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
    {
        spinorEl1ReadQueueItem.handle = handle;
        spinorEl1ReadQueueItem.eUserType = el1GetUserType(handle);
        spinorEl1ReadQueueItem.spinorCallback = readCallback;
        spinorEl1ReadQueueItem.status = status;
        spinorEl1ReadQueueItem.opParam.opType = SPINOR_EL1_READ;
        spinorEl1ReadQueueItem.opParam.buffer = buffer;
        spinorEl1ReadQueueItem.opParam.byte_offset = byte_offset;
        spinorEl1ReadQueueItem.opParam.byte_count = byte_count;
        spinorEl1ReadQueueItem.trans_ID = ++gEl1Ctxt.GlobalTransID;

        //DEBUG_LOG(SAIL_INFO, "%s: Queuing Read Msg to SPINOR task queue.\n\r", __func__);
        xResult = xFreeRTOSQueueSend(xSpinorEl1QueueHandle, &spinorEl1ReadQueueItem, pdMS_TO_TICKS(freertosMAX_DELAY));
        if (pdPASS == xResult)
        {
            //DEBUG_LOG(SAIL_INFO, "%s: Msg queued from Erase. !\n\r", __func__);
            status = SPINOR_DEVICE_OK_NOT_DONE;
        }
        else if (errQUEUE_FULL == xResult)
        {
            //queuing failed as queue full
            status = SPINOR_ACCESS_NO_BUS;
            DEBUG_LOG(SAIL_INFO, "%s: Error,in Queuing to SafeRTOS queue, queue full \r\n", __func__);
        }
        else
        {
            el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL1, (uint32_t)handle, 0x2D);
            DEBUG_LOG(SAIL_ERROR, "%s: Error,in Queuing to SPINOR task queue at addr=0x%x, size=0x%x \r\n", __func__, byte_offset, byte_count);
            return SPINOR_DEVICE_FAIL;
        }

        if (spinorEl1ReadQueueItem.spinorCallback == NULL)
        {
            //DEBUG_LOG(SAIL_INFO, "%s: Waiting for Read Status Notification !\n\r", __func__);

            while(1)
            {
                xResult = xFreeRTOSQueuePeek(xSpinorEl1NotifyQueueHandle, &spinorEl1statusQueueItem, freertosMAX_DELAY);
                if (pdPASS == xResult)
                {
                    status = SPINOR_DEVICE_DONE;
                }
                else if(errQUEUE_EMPTY == xResult)
                {
                    status = SPINOR_ACCESS_NO_BUS;
                    DEBUG_LOG(SAIL_INFO, "%s: Error,in Queue peek to SafeRTOS queue, queue empty \r\n", __func__);
                    err_fatal(SPINOR, status);
                }
                else
                {
                    status = SPINOR_DEVICE_FAIL;
                    el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL1,(uint32_t)handle,0x2E);
                    DEBUG_LOG(SAIL_ERROR, "%s: Receive from Notify Queue failed \n\r", __func__);
                    err_fatal(SAFERTOS, xResult);
                }

                if(spinorEl1statusQueueItem.handle == spinorEl1ReadQueueItem.handle && spinorEl1statusQueueItem.trans_ID == spinorEl1ReadQueueItem.trans_ID)
                {
                    break;
                }
                else
                {
                     if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
                    {
                        vFreeRTOSTaskDelay(1);
                    }
                }
            }

            xResult = xFreeRTOSQueueReceive(xSpinorEl1NotifyQueueHandle, &spinorEl1statusQueueItem, freertosMAX_DELAY);
            if (pdPASS == xResult)
            {
                status = SPINOR_DEVICE_DONE;
            }
            else if(errQUEUE_EMPTY == xResult)
            {
                status = SPINOR_ACCESS_NO_BUS;
                DEBUG_LOG(SAIL_INFO, "%s: Error,in Queue receive from SafeRTOS queue, queue empty \r\n", __func__);
                err_fatal(SPINOR, status);
            }
            else
            {
                status = SPINOR_DEVICE_FAIL;
                el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL1,(uint32_t)handle,0x2F);
                DEBUG_LOG(SAIL_ERROR, "%s: Receive from Notify Queue failed \n\r", __func__);
                err_fatal(SAFERTOS, xResult);
            }

            //             DEBUG_LOG(SAIL_INFO, "%s: SPINOR Read result received. Processing !\n\r", __func__);
            status = spinorEl1statusQueueItem.status;

            if (SPINOR_DEVICE_DONE != status)
            {
                el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)handle, 0x30);
                DEBUG_LOG(SAIL_ERROR, "%s: Error, el1 read failed at 0x%x byte offset and 0x%x byte count, status = 0x%x \r\n", __func__, byte_offset, byte_count, status);
                return status;
            }

            return status;
        }
        else
        {
            /* As the operation is asynchronous, queue operation to the thread and return status here. */
            if (status == SPINOR_DEVICE_OK_NOT_DONE)
                userdata->transaction_ID = spinorEl1ReadQueueItem.trans_ID;
            else
                userdata->transaction_ID = 0xFF; //failure case

            return status;
        }
    }
    else
    {
        /* Try lock till the lock is acquired */
        while (1)
        {
            val = el1Lock();
            if (val)
            {
                break;
            }
            else
            {
                 if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
                {
                    vFreeRTOSTaskDelay(1);
                }
            }
        }

        while (byte_count)
        {
            transfer_size = (byte_count > SPINOR_MAX_BYTES_READ_EL1) ? SPINOR_MAX_BYTES_READ_EL1 : byte_count;
            /* Construct the Trap handle structure */
            h.handle = handle;
            h.pwd = &gEl1Ctxt.pwd;

            xRWParamInfo.byte_offset = byte_offset;
            xRWParamInfo.byte_count = transfer_size;
            xRWParamInfo.buffer = (void*)guSpinorEl1ReadBuf;

            trapParam.readParam.h = &h;
            trapParam.readParam.pRWParams = &xRWParamInfo;

            status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_READ, &trapParam);
            if (status != SPINOR_DEVICE_OK_NOT_DONE)
            {
                el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)handle, 0x31);
                DEBUG_LOG(SAIL_ERROR, "%s: Error, el1 read failed at 0x%x address \r\n", __func__, byte_offset);
                el1Unlock();
                return status;
            }

            while (SPINOR_DEVICE_OK_NOT_DONE == status)
            {
                trapParam = (spinorTrapParams_t){ 0 };
                trapParam.mainFuncParam.h = &h;
                status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_MAINFUNC, &trapParam);
                if (status != SPINOR_DEVICE_DONE)
                {
                    el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)handle, 0x32);
                    DEBUG_LOG(SAIL_ERROR, "%s: Error, el1 read failed at 0x%x address \r\n", __func__, byte_offset);
                    el1Unlock();
                    return status;
                }

                trapParam = (spinorTrapParams_t){ 0 };
                trapParam.getJobResParam.h = &h;
                status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_GETJOBRESULT, &trapParam);
                if ((SPINOR_DEVICE_OK_NOT_DONE != status) && (SPINOR_DEVICE_DONE != status))
                {
                    el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)handle, 0x33);
                    DEBUG_LOG(SAIL_ERROR, "%s: Error, el1 read failed at 0x%x address, status = 0x%x \r\n", __func__, byte_offset, status);
                    el1Unlock();
                    return status;
                }

                /* If the operation is done break the poll loop*/
                if (status == SPINOR_DEVICE_DONE)
                {
                    break;
                }
                else
                {
                     if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
                    {
                        vFreeRTOSTaskDelay(1);
                    }
                }
            }

            /* Copy the read data into the user buffer */
            result = sailbsp_memscpy(buffer, transfer_size, (const void*)guSpinorEl1ReadBuf, transfer_size);
            if (result == 0)
            {
                el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL1, (uint32_t)handle, 0x34);
                DEBUG_LOG(SAIL_ERROR, "%s: Copy to user buffer failed \r\n", __func__);
                el1Unlock();
                return status;
            }

            byte_offset += transfer_size;
            buffer += transfer_size;
            byte_count -= transfer_size;
        }

        el1Unlock();
        return SPINOR_DEVICE_DONE;
    }
}

/**********************************************************
 * Vote low power to spinor framework.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param bLowPower [IN]
 *   Vote to allow low power
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS el1LowPower ( spinor_handle_t handle, boolean bLowPower)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinorTrapHandle_t h;
    uint32_t val;
    spinorTrapParams_t trapParam={0};

    if ( FALSE == gEl1Ctxt.bInitDone )
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_CLIENT,0,0x35);
        DEBUG_LOG( SAIL_ERROR,"%s: Error, init not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    while(1)
    {
        /* lock the EL1 */
        val = el1Lock();

        if(val)
        {
            /* Construct the Trap handle structure */
            h.handle = handle;
            h.pwd = &gEl1Ctxt.pwd;

            trapParam.lowPowerParam.h = &h;
            trapParam.lowPowerParam.bLowPower = bLowPower;
            status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_LOWPOWER, &trapParam);
            if (status != SPINOR_DEVICE_DONE)
            {
                el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL2,(uint32_t)handle,0x36);
                DEBUG_LOG( SAIL_ERROR,"%s: Error, el1 lowpower failed \r\n", __func__);
                el1Unlock();
                return status;
            }

            el1Unlock();

            return SPINOR_DEVICE_DONE;
        }
        else
        {
             if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
            {
                vFreeRTOSTaskDelay(1);
            }
        }
    }
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
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS el1GetMemInfo(spinor_handle_t handle, spinorMemInfoType *pmemInfo)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinorTrapHandle_t h;
    uint32_t val;
    spinorTrapParams_t trapParam={0};

    if ( FALSE == gEl1Ctxt.bInitDone )
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_CLIENT,0,0x37);
        DEBUG_LOG( SAIL_ERROR,"%s: Error, init not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    while(1)
    {
        /* lock the EL1 */
        val = el1Lock();

        if(val)
        {
            /* Construct the Trap handle structure */
            h.handle = handle;
            h.pwd = &gEl1Ctxt.pwd;

            trapParam.getMemInfoParam.h = &h;
            trapParam.getMemInfoParam.pMemInfo = pmemInfo;
            status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_GET_MEMINFO, &trapParam);
            if (status != SPINOR_DEVICE_DONE)
            {
                el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL2,(uint32_t)handle,0x38);
                DEBUG_LOG( SAIL_ERROR,"%s: Error, el1 getmeminfo failed \r\n", __func__);
                el1Unlock();
                return status;
            }

            el1Unlock();

            return SPINOR_DEVICE_DONE;
        }
        else
        {
             if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
            {
                vFreeRTOSTaskDelay(1);
            }
        }
    }
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
SPINOR_FUNC SPINOR_STATUS el1IsDeviceAlive( void )
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t val;
    spinorTrapParams_t trapParam={0};

    if ( FALSE == gEl1Ctxt.bInitDone )
    {
        DEBUG_LOG( SAIL_ERROR,"%s: Error, init not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    while(1)
    {
        /* lock the EL1 */
        val = el1Lock();

        if(val)
        {
            trapParam.isDevAliveParam.param = 0;
            status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_IS_DEVICE_ALIVE, &trapParam);
            if (status != SPINOR_DEVICE_DONE)
            {
                el1Unlock();
                return status;
            }

            el1Unlock();

            return SPINOR_DEVICE_DONE;
        }
        else
        {
             if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
            {
                vFreeRTOSTaskDelay(1);
            }
        }
    }
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
SPINOR_FUNC SPINOR_STATUS el1DumpSFDP(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t val;
    spinorTrapParams_t trapParam={0};

    if (FALSE == gEl1Ctxt.bInitDone)
    {
        DEBUG_LOG(SAIL_ERROR, "%s: Error, init not done \r\n", __func__);
        return SPINOR_DEVICE_FAIL;
    }

    while (1)
    {
        /* lock the EL1 */
        val = el1Lock();

        if (val)
        {
            trapParam.sfdpDumpParam.param = 0;
            status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_SFDP_DUMP, &trapParam);
            if (status != SPINOR_DEVICE_DONE)
            {
                el1Unlock();
                return status;
            }

            el1Unlock();

            return SPINOR_DEVICE_DONE;
        }
        else
        {
             if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
            {
                vFreeRTOSTaskDelay(1);
            }
        }
    }
}

/**********************************************************
 * Spinor EL1 task Resouce Initalization
 *
 *
 * @param xSchdCore [IN]
 *   CPU number
 *
 * @return portBaseType [OUT]
 *   Status of the Initalization
 *
 **********************************************************/
BaseType_t xSpinorEl1TaskResourceInit(CPUIdType_e xSchdCore)
{
    BaseType_t xCreateResult = pdPASS;

    /* Queue for Queuing item */
    xCreateResult = xFreeRTOSQueueCreate( xSpinorEl1QueueBuffer,
                                  SPINOR_EL1_Q_LENGTH,
                                  SPINOR_EL1_Q_ITEM_SIZE,
                                  &xSpinorEl1QueueHandle, &xSpinorEl1QueueBufferStatic);
    if( xCreateResult != pdPASS )
    {
        xCreateResult = pdFAIL;
        return xCreateResult;
    }

    /* Queue for Status Notification */
    xCreateResult = xFreeRTOSQueueCreate( xSpinorEl1NotifyQueueBuffer,
                                  SPINOR_EL1_NOTIFY_Q_LENGTH,
                                  SPINOR_EL1_NOTIFY_Q_ITEM_SIZE,
                                  &xSpinorEl1NotifyQueueHandle,&xSpinorEl1NotifyQueueBufferStatic );
    if( xCreateResult != pdPASS )
    {
        xCreateResult = pdFAIL;
        return xCreateResult;
    }

    return xCreateResult;
}

/**********************************************************
 * SPINOR EL1 Task Init
 *
 *
 * @param xSchdCore [IN]
 *   CPU number
 *
 * @param xTaskPrior [IN]
 *   Task Priority
 *
 * @return portBaseType [OUT]
 *   Status of the operation
 *
 **********************************************************/
BaseType_t xSpinorEL1TaskInit( CPUIdType_e  xSchdCore, UBaseType_t  xTaskPrior )
{
    BaseType_t xResult;
    UBaseType_t uxCoreAffinityMask;
    /* The structure passed to xSAILTaskCreate() to create the check task. */
    TaskParams_t xInitTaskParameters =
    {
        .pvTaskCode =vSpinorEl1Task,                              /* The function that implements the task being created. */
        .pcName = "SPINOR EL1",                                /* The name of the task being created. The kernel does not use this itself, it's just to assist debugging. */
        .pxTaskBuffer =&xSpinorEl1TaskTCB,                          /* The buffer allocated for use as the task TCB. */
        .puxStackBuffer = xSpinorEl1TaskStack,                         /* The buffer allocated for use as the task stack. */
        .usStackDepth =SPINOR_EL1_TASK_STACK_SIZE,                  /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        .pvParameters =NULL,                                        /* The task parameter, not used in this case. */
        .uxPriority = (xTaskPrior),                                  /* The priority assigned to the task being created. */
        .xRegions = {				   /* The MPU task parameters. */
						 {NULL, 0UL, 0UL}, /* No additional region definitions are required. */
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL}}};

        /* Create the check task. */
	uxCoreAffinityMask = (1 << xSchdCore);
    xResult = xFreeRTOSTaskCreateAffinitySet( &xInitTaskParameters, uxCoreAffinityMask, /* The structure containing the task parameters created at the start of this function. */
                           &xSpinorEl1TaskInitHandle );

    return xResult;
}

boolean spinorIsQueueFull(void)
{
    if (spinorLocalQueue.numItems >= SPINOR_LOC_QUEUE_SIZE )
    {
        //queue full
        return TRUE;
    }

    return FALSE;
}

boolean spinorIsQueueEmpty(void)
{
    if (spinorLocalQueue.numItems <= 0)
    {
        //queue empty
        return TRUE;
    }

    return FALSE;
}

SPINOR_STATUS spinorQueueAdd(spinorEl1QueueItemType SpinorQueueElement)
{
    size_t result = 0;

    /* Copy from temp variable to local queue */
    result = sailbsp_memscpy((void*)&spinorLocalQueue.Queue[spinorLocalQueue.writePtr], sizeof(spinorEl1QueueItemType), (const void*)&SpinorQueueElement, sizeof(spinorEl1QueueItemType));
    if (result == 0)
    {
        /* copy failure */
        return SPINOR_DEVICE_FAIL;
    }

    spinorLocalQueue.numItems++;
    spinorLocalQueue.writePtr = (spinorLocalQueue.writePtr + 1) % SPINOR_LOC_QUEUE_SIZE;

    return SPINOR_DEVICE_DONE;
}

SPINOR_STATUS spinorQueueDelete(void)
{
    memset(&spinorLocalQueue.Queue[spinorLocalQueue.readPtr], 0, sizeof(spinorEl1QueueItemType));

    spinorLocalQueue.numItems--;

    spinorLocalQueue.readPtr = (spinorLocalQueue.readPtr + 1) % SPINOR_LOC_QUEUE_SIZE;

    return SPINOR_DEVICE_DONE;
}

SPINOR_STATUS spinorEraseHelper(spinorEl1QueueItemType* SpinorQueueElement)
{
    spinorTrapParams_t trapParam = { 0 };
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t transfer_size;
    spinorTrapHandle_t h = { 0 };
    spinor_getnum4kblockType el1BlockInfo = {0};

    while (SpinorQueueElement->opParam.byte_count)
    {
        status = SpinorQueueElement->status;

        /* Construct the Trap handle structure */
        h.handle = SpinorQueueElement->handle;
        h.pwd = &gEl1Ctxt.pwd;

        status = el1GetNum4kBlock(SpinorQueueElement->opParam.byte_offset * 4096, &el1BlockInfo);
        if(status != SPINOR_DEVICE_DONE)
        {
            status = SPINOR_DEVICE_FAIL;
            el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL1,(uint32_t)SpinorQueueElement->handle,0x39);
            DEBUG_LOG(SAIL_ERROR, "%s: Error, el1GetNum4kBlock failed \r\n", __func__);
            goto spinorEraseHelper_end;
        }

        transfer_size = (SpinorQueueElement->opParam.byte_count > el1BlockInfo.block_num) ? el1BlockInfo.block_num : SpinorQueueElement->opParam.byte_count;
        trapParam.eraseParam.h = &h;
        trapParam.eraseParam.start_block = SpinorQueueElement->opParam.byte_offset;
        trapParam.eraseParam.block_count = transfer_size;

        status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_ERASE, &trapParam);
        if (status != SPINOR_DEVICE_OK_NOT_DONE)
        {
            el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)SpinorQueueElement->handle, 0x3A);
            DEBUG_LOG(SAIL_ERROR, "%s: Error, el1 erase failed at 0x%x start block and %d block count \r\n", __func__, SpinorQueueElement->opParam.byte_offset, transfer_size);
            goto spinorEraseHelper_end;
        }

        while (SPINOR_DEVICE_OK_NOT_DONE == status)
        {
            trapParam = (spinorTrapParams_t){ 0 };
            trapParam.mainFuncParam.h = &h;
            status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_MAINFUNC, &trapParam);
            if (status != SPINOR_DEVICE_DONE)
            {
                el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)h.handle, 0x3B);
                DEBUG_LOG(SAIL_ERROR, "%s: SPINOR thread loop error running mainfunction \r\n", __func__);
                goto spinorEraseHelper_end;
            }

            trapParam = (spinorTrapParams_t){ 0 };
            trapParam.getJobResParam.h = &h;
            status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_GETJOBRESULT, &trapParam);
            if ((SPINOR_DEVICE_OK_NOT_DONE != status) && (SPINOR_DEVICE_DONE != status))
            {
                el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)h.handle, 0x3C);
                DEBUG_LOG(SAIL_ERROR, "%s: SPINOR thread loop completed with error, status = 0x%x \r\n", __func__, status);
                goto spinorEraseHelper_end;
            }

            /* If the operation is done break the poll loop */
            if (status == SPINOR_DEVICE_DONE)
            {
                //DEBUG_LOG( SAIL_INFO,"%s: SPINOR thread loop completed successfully \r\n", __func__);
                SpinorQueueElement->opParam.byte_offset = SpinorQueueElement->opParam.byte_offset + transfer_size;
                SpinorQueueElement->opParam.byte_count = SpinorQueueElement->opParam.byte_count - transfer_size;
                break;
            }
            else if (SPINOR_DEVICE_OK_NOT_DONE == status)
            {
                 if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
                {
                    vFreeRTOSTaskDelay(0); //yield
                }
            }
            else
            {
                goto spinorEraseHelper_end;
            }
        }
    }

spinorEraseHelper_end:
    return status;
}

SPINOR_STATUS spinorWriteHelper(spinorEl1QueueItemType* SpinorQueueElement)
{
    spinorTrapParams_t trapParam = { 0 };
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t transfer_size;
    spinorTrapRWRegionParam_t xRWParamInfo;
    spinorTrapHandle_t h = { 0 };

    while (SpinorQueueElement->opParam.byte_count)
    {
        /* Construct the Trap handle structure */
        h.handle = SpinorQueueElement->handle;
        h.pwd = &gEl1Ctxt.pwd;

        transfer_size = (SpinorQueueElement->opParam.byte_count > SPINOR_MAX_BYTES_WRITE_EL1) ? SPINOR_MAX_BYTES_WRITE_EL1 : SpinorQueueElement->opParam.byte_count;
        xRWParamInfo.byte_offset = SpinorQueueElement->opParam.byte_offset;
        xRWParamInfo.byte_count = transfer_size;
        xRWParamInfo.buffer = SpinorQueueElement->opParam.buffer;

        trapParam.writeParam.h = &h;
        trapParam.writeParam.pRWParams = &xRWParamInfo;

        status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_WRITE, &trapParam);
        if (status != SPINOR_DEVICE_OK_NOT_DONE)
        {
            el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)SpinorQueueElement->handle, 0x3D);
            DEBUG_LOG(SAIL_ERROR, "%s: Error, el1 write failed at 0x%x address \r\n", __func__, SpinorQueueElement->opParam.byte_offset);
            goto spinorWriteHelper_end;
        }

        while (SPINOR_DEVICE_OK_NOT_DONE == status)
        {
            trapParam = (spinorTrapParams_t){ 0 };
            trapParam.mainFuncParam.h = &h;
            status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_MAINFUNC, &trapParam);
            if (status != SPINOR_DEVICE_DONE)
            {
                el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)h.handle, 0x3E);
                DEBUG_LOG(SAIL_ERROR, "%s: SPINOR thread loop error running mainfunction \r\n", __func__);
                goto spinorWriteHelper_end;
            }

            trapParam = (spinorTrapParams_t){ 0 };
            trapParam.getJobResParam.h = &h;
            status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_GETJOBRESULT, &trapParam);
            if ((SPINOR_DEVICE_OK_NOT_DONE != status) && (SPINOR_DEVICE_DONE != status))
            {
                el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)h.handle, 0x3F);
                DEBUG_LOG(SAIL_ERROR, "%s: SPINOR thread loop completed with error, status = 0x%x \r\n", __func__, status);
                goto spinorWriteHelper_end;
            }

            /* If the operation is done break the poll loop */
            if (status == SPINOR_DEVICE_DONE)
            {
                //DEBUG_LOG( SAIL_INFO,"%s: SPINOR thread loop completed successfully \r\n", __func__);
                SpinorQueueElement->opParam.byte_offset = SpinorQueueElement->opParam.byte_offset + transfer_size;
                SpinorQueueElement->opParam.byte_count = SpinorQueueElement->opParam.byte_count - transfer_size;
                SpinorQueueElement->opParam.buffer = SpinorQueueElement->opParam.buffer + transfer_size;
                break;
            }
            else if (SPINOR_DEVICE_OK_NOT_DONE == status)
            {
                 if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
                {
                    vFreeRTOSTaskDelay(0); //yield
                }
            }
            else
            {
                goto spinorWriteHelper_end;
            }
        }
    }

spinorWriteHelper_end:
    return status;
}

SPINOR_STATUS spinorReadHelper(spinorEl1QueueItemType* SpinorQueueElement)
{
    spinorTrapParams_t trapParam = { 0 };
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t transfer_size;
    spinorTrapRWRegionParam_t xRWParamInfo;
    spinorTrapHandle_t h = { 0 };
    size_t result = 0;
    BaseType_t xResult;
    void* buffer;
    uint32 byte_count;

    while (SpinorQueueElement->opParam.byte_count)
    {
        /* Construct the Trap handle structure */
        h.handle = SpinorQueueElement->handle;
        h.pwd = &gEl1Ctxt.pwd;

        transfer_size = (SpinorQueueElement->opParam.byte_count > SPINOR_MAX_BYTES_READ_EL1) ? SPINOR_MAX_BYTES_READ_EL1 : SpinorQueueElement->opParam.byte_count;
        xRWParamInfo.byte_offset = SpinorQueueElement->opParam.byte_offset;
        xRWParamInfo.byte_count = transfer_size;
        xRWParamInfo.buffer = (void*)guSpinorEl1ReadBuf;

        trapParam.readParam.h = &h;
        trapParam.readParam.pRWParams = &xRWParamInfo;

        status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_READ, &trapParam);
        if (status != SPINOR_DEVICE_OK_NOT_DONE)
        {
            el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)SpinorQueueElement->handle, 0x40);
            DEBUG_LOG(SAIL_ERROR, "%s: Error, el1 read failed at 0x%x address \r\n", __func__, SpinorQueueElement->opParam.byte_offset);
            goto spinorReadHelper_end;
        }

        while (SPINOR_DEVICE_OK_NOT_DONE == status)
        {
            trapParam = (spinorTrapParams_t){ 0 };
            trapParam.mainFuncParam.h = &h;
            status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_MAINFUNC, &trapParam);
            if (status != SPINOR_DEVICE_DONE)
            {
                el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)h.handle, 0x41);
                DEBUG_LOG(SAIL_ERROR, "%s: SPINOR thread loop error running mainfunction \r\n", __func__);
                goto spinorReadHelper_end;
            }

            trapParam = (spinorTrapParams_t){ 0 };
            trapParam.getJobResParam.h = &h;
            status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_GETJOBRESULT, &trapParam);
            if ((SPINOR_DEVICE_OK_NOT_DONE != status) && (SPINOR_DEVICE_DONE != status))
            {
                el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)h.handle, 0x42);
                DEBUG_LOG(SAIL_ERROR, "%s: SPINOR thread loop completed with error, status = 0x%x \r\n", __func__, status);
                goto spinorReadHelper_end;
            }

            /* If the operation is done break the poll loop */
            if (status == SPINOR_DEVICE_DONE)
            {
                //for reads, copy contents from 4k buffer to user buffer
                result = sailbsp_memscpy((void *)SpinorQueueElement->opParam.buffer, transfer_size, (const void*)guSpinorEl1ReadBuf, transfer_size);
                if (result == 0)
                {
                    el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL1, (uint32_t)SpinorQueueElement->handle, 0x43);
                    DEBUG_LOG(SAIL_ERROR, "%s: Copy to user buffer failed \r\n", __func__);
                    status = SPINOR_DEVICE_FAIL;
                    goto spinorReadHelper_end;
                }

                //DEBUG_LOG( SAIL_INFO,"%s: SPINOR thread loop completed successfully \r\n", __func__);
                SpinorQueueElement->opParam.byte_offset = SpinorQueueElement->opParam.byte_offset + transfer_size;
                SpinorQueueElement->opParam.byte_count = SpinorQueueElement->opParam.byte_count - transfer_size;
                SpinorQueueElement->opParam.buffer = SpinorQueueElement->opParam.buffer + transfer_size;
                break;
            }
            else if (SPINOR_DEVICE_OK_NOT_DONE == status)
            {
                 if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
                {
                    vFreeRTOSTaskDelay(0); //yield
                }
            }
            else
            {
                goto spinorReadHelper_end;
            }
        }
    }

spinorReadHelper_end:
    return status;
}

SPINOR_STATUS process_item(spinorEl1QueueItemType* SpinorQueueElement)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

    switch (SpinorQueueElement->opParam.opType)
    {
        case SPINOR_EL1_ERASE:
            status = spinorEraseHelper(SpinorQueueElement);
            break;

        case SPINOR_EL1_READ:
            status = spinorReadHelper(SpinorQueueElement);
            break;

        case SPINOR_EL1_WRITE:
            status = spinorWriteHelper(SpinorQueueElement);
            break;

        default:
            el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL1,(uint32_t)SpinorQueueElement->handle,0x44);
            DEBUG_LOG(SAIL_ERROR, "%s: Error, invalid operation \r\n", __func__);
            status = SPINOR_DEVICE_FAIL;
            break;
    }

    SpinorQueueElement->status = status;

    return status;
}

/**********************************************************
 * SPINOR EL1 Task
 *
 *
 * @param pvParameters [IN/OUT]
 *   Pointer for Input Params
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
void vSpinorEl1Task(void* pvParameters)
{
    spinorTrapParams_t trapParam = { 0 };
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinorEl1NotifyQueueItemType spinorEl1NotifyItem = { 0 };
    spinorEl1QueueItemType SpinorQueueElement = { 0 };
    spinorEl1QueueItemType* CurrentItem = 0;
    BaseType_t xResult;
    uint32_t val, transfer_size;
    spinorTrapRWRegionParam_t xRWParamInfo;
    boolean res = FALSE;

    for (;;)
    {
        //TODO prerana : check if safeRTOS queue is empty, if empty, yield?

        //DEBUG_LOG(SAIL_INFO,"vSpinorEl1Task: Waiting on receive Queue \n\r");
        /* Wait on Receive Queue Event */

        res = spinorIsQueueFull();
        if (res != TRUE)
        {
            /* Queue is not full, receive item */
            xResult = xFreeRTOSQueueReceive(xSpinorEl1QueueHandle, &SpinorQueueElement, freertosMAX_DELAY);
            if (pdPASS == xResult)
            {
                //DEBUG_LOG(SAIL_INFO,"vSpinorEl1Task: receive Queue passed \n\r");
            }
            else if (errQUEUE_EMPTY == xResult)
            {
                el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL1,(uint32_t)SpinorQueueElement.handle,0x45);
                DEBUG_LOG(SAIL_ERROR, "vSpinorEl1Task: Receive from Queue failed: SafeRTOS queue empty \n\r");
                err_fatal(SPINOR, SPINOR_ACCESS_NO_BUS);
            }
            else
            {
                el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL1,(uint32_t)SpinorQueueElement.handle,0x46);
                DEBUG_LOG(SAIL_ERROR, "vSpinorEl1Task: Receive from SafeRTOS Queue failed \n\r");
                err_fatal(SAFERTOS, xResult);
            }

            status = spinorQueueAdd(SpinorQueueElement);
            if (status != SPINOR_DEVICE_DONE)
            {
                //error obtaining element
                el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL1,(uint32_t)SpinorQueueElement.handle,0x47);
                DEBUG_LOG(SAIL_ERROR, "vSpinorEl1Task: SPINOR Queue Add failed \n\r");
                err_fatal(SPINOR, status);
            }
        }

        /* points to the element being processed */
        CurrentItem = &spinorLocalQueue.Queue[spinorLocalQueue.readPtr];

        /* obtain lock */
        /* Try lock till the lock is acquired */
        while (1)
        {
            val = el1Lock();
            if (val)
            {
                break;
            }
            else
            {
                 if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
                {
                    vFreeRTOSTaskDelay(1);
                }
            }
        }

        //Processes the item
        status = process_item(CurrentItem);

        //Callback/Notify
        /* update the status to the pointer */
        if (NULL != CurrentItem->spinorCallback)
        {
            el1Unlock();
            //DEBUG_LOG( SAIL_INFO,"%s:Notifying SPINOR client callback with status 0x%x\r\n", __func__, status);
            CurrentItem->spinorCallback(status, CurrentItem->trans_ID);
        }
        else
        {
            spinorEl1NotifyItem.status = status;
            spinorEl1NotifyItem.handle = CurrentItem->handle;
            spinorEl1NotifyItem.trans_ID = CurrentItem->trans_ID;
            el1Unlock();

            //DEBUG_LOG(SAIL_INFO, "%s: Sending Notify Msg from SPINOR Thread . !\n\r", __func__);
            xResult = xFreeRTOSQueueSend(xSpinorEl1NotifyQueueHandle, &spinorEl1NotifyItem, pdMS_TO_TICKS(freertosMAX_DELAY));
            if (pdPASS == xResult)
            {
                //DEBUG_LOG(SAIL_INFO,"vSpinorEl1Task: Send Queue passed \n\r");
            }
            else if (errQUEUE_FULL == xResult)
            {
                //queuing failed as queue full
                el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL1,(uint32_t)CurrentItem->handle,0x48);
                DEBUG_LOG(SAIL_ERROR, "vSpinorEl1Task: Send to Queue failed: NotifyQueue full \n\r");
                err_fatal(SPINOR, SPINOR_ACCESS_NO_BUS);
            }
            else
            {
                el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL1,(uint32_t)CurrentItem->handle,0x49);
                DEBUG_LOG(SAIL_ERROR, "vSpinorEl1Task: Send to Queue failed: NotifyQueue queuing failed \n\r");
                err_fatal(SAFERTOS, xResult);
            }
        }

        /* Check if Queue is empty */
        res = spinorIsQueueEmpty();
        if (res != TRUE)
        {
            /* Delete item and unlock */
            status = spinorQueueDelete();
            if (status != SPINOR_DEVICE_DONE)
            {
                //error obtaining element
                DEBUG_LOG(SAIL_ERROR, "vSpinorEl1Task: SPINOR Queue Delete failed \n\r");
                err_fatal(SPINOR, status);
            }
        }
    }
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
SPINOR_FUNC SPINOR_STATUS el1SWResetClose(uint32 resetCoreID)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t val;
    spinorTrapParams_t trapParam = { 0 };

    trapParam.resetCloseParam.resetCoreID = resetCoreID;

    status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_SWRESETCLOSE, &trapParam);
    if (status != SPINOR_DEVICE_DONE)
    {
        return status;
    }

    return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * Acquire the lock to the SPIBUS
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS el1AquireLock(spinor_handle_t handle)
{
    uint32_t val;
    /* Return failure if the EL1 layer is not initialized */
    if( FALSE == gEl1Ctxt.bInitDone )
    {
        return SPINOR_DEVICE_FAIL;
    }

    /* Return failure if the lock is already acquired */
    if ( TRUE == gEl1Ctxt.el1_bincmdlock_acquired )
    {
        return SPINOR_DEVICE_FAIL;
    }

    /* obtain lock */
    /* Try to acquire the lock */
    val = el1Lock();
    if (val)
    {
        /* Validate if the user is EL1 Super User */
        if (SPINOR_USER_TYPE_EL1_SUPER == el1GetUserType(handle))
        {
            gEl1Ctxt.el1_bincmdlock_acquired = TRUE;
            return SPINOR_DEVICE_DONE;;
        }
        else
        {
            /* Release lock */
            el1Unlock();
            return SPINOR_DEVICE_NOT_SUPPORTED;
        }
    }
    else
    {
        return SPINOR_ACCESS_NO_BUS;
    }
}

/**********************************************************
 * Release the lock to the SPIBUS
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS el1ReleaseLock(spinor_handle_t handle)
{
    /* Return failure if the EL1 layer is not initialized */
    if( FALSE == gEl1Ctxt.bInitDone )
    {
        return SPINOR_DEVICE_FAIL;
    }

    /* Proceed if the lock is already acquired */
    if ( TRUE == gEl1Ctxt.el1_bincmdlock_acquired )
    {
        /* Validate if the user is EL1 Super User */
        if (SPINOR_USER_TYPE_EL1_SUPER != el1GetUserType(handle))
        {
            return SPINOR_DEVICE_NOT_SUPPORTED;
        }

        /* Release lock */
        el1Unlock();

        gEl1Ctxt.el1_bincmdlock_acquired = FALSE;

        return SPINOR_DEVICE_DONE;
    }
    else
    {
        /* Return failure if the lock is not already acquired */
        return SPINOR_DEVICE_FAIL;
    }
}

/**********************************************************
 * Sends Raw SPI commands to the Flash device synchronously
 *
 * @param handle [IN]
 *   SPINOR service interface handle
 *
 * @param bincmdParams [IN]
 *   Pointer to hold Binary Command Parameters.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 * @dependencies - The SPIBus needs to be acquired before
 *                 sending the command sequences and should be
 *                 released after the sequences are completed.
 *                 The operation is only allowed for EL1 Super users
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS el1Bincmd( spinor_handle_t handle, spinorBincmdParams_t *bincmdParams)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinorTrapHandle_t h;
    spinorTrapParams_t trapParam={0};

     if ( FALSE == gEl1Ctxt.bInitDone )
     {
         /* Return failure if initialization not done */
         return SPINOR_DEVICE_FAIL;
     }

    /* Proceed if the lock is already acquired */
    if ( TRUE == gEl1Ctxt.el1_bincmdlock_acquired )
    {
        /* Validate if the user is EL1 Super User */
        if (SPINOR_USER_TYPE_EL1_SUPER != el1GetUserType(handle))
        {
            return SPINOR_DEVICE_NOT_SUPPORTED;
        }
    }
    else
    {
        /* Return failure if the lock is not already acquired */
        return SPINOR_DEVICE_FAIL;
    }

    /* Lock is acquired and the user is validated as super user so proceed with the binary command */

    /* Construct the Trap handle structure */
    h.handle = handle;
    h.pwd = &gEl1Ctxt.pwd;

    trapParam.bincmdParam.h = &h;
    trapParam.bincmdParam.cmdparams = (spinorTrapBincmdParams_t *)bincmdParams;

    status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_BINCMD, &trapParam);
    if (status != SPINOR_DEVICE_OK_NOT_DONE)
    {
        el1Log(&gEl1Ctxt.xdbgLogs,EL1_ERR_CLASS_EL2,(uint32_t)handle,0x4A);
        DEBUG_LOG( SAIL_ERROR,"%s: Error, Bin Command send failed \r\n", __func__);
        return status;
    }

    while (SPINOR_DEVICE_OK_NOT_DONE == status)
    {
        trapParam = (spinorTrapParams_t){ 0 };
        trapParam.mainFuncParam.h = &h;
        status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_MAINFUNC, &trapParam);
        if (status != SPINOR_DEVICE_DONE)
        {
            el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)handle, 0x4B);
            DEBUG_LOG(SAIL_ERROR, "%s: Error, Bin Cmd Operation failed \r\n", __func__);
            return status;
        }

        trapParam = (spinorTrapParams_t){ 0 };
        trapParam.getJobResParam.h = &h;
        status = spinor_trap_syscall_wrap(SAIL_SPINOR_FUNC_GETJOBRESULT, &trapParam);
        if ((SPINOR_DEVICE_OK_NOT_DONE != status) && (SPINOR_DEVICE_DONE != status))
        {
            el1Log(&gEl1Ctxt.xdbgLogs, EL1_ERR_CLASS_EL2, (uint32_t)handle, 0x4C);
            DEBUG_LOG(SAIL_ERROR, "%s: Error, Bin Cmd Operation status failed, status = 0x%x \r\n", __func__, status);
            el1Unlock();
            return status;
        }

        /* If the operation is done break the poll loop*/
        if (status == SPINOR_DEVICE_DONE)
        {
            break;
        }
        else
        {
             if(taskSCHEDULER_RUNNING == xFreeRTOSTaskGetSchedulerState())
            {
                vFreeRTOSTaskDelay(1);
            }
        }
    }

    return status;
}
