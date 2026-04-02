/*
==============================================================================

FILE: CrashdbgClient.c

DESCRIPTION:
  Crashdbg driver System Call ( SW1/EL1 ) module interface.

==============================================================================

$Header: $

==============================================================================
Copyright (c) 2022 QUALCOMM Technologies Incorporated.
All Rights Reserved.
QUALCOMM Proprietary/GTDR
==============================================================================

*/

/*=========================================================================
      Include Files
==========================================================================*/

#include "stdbool.h"
#include "stdint.h"
#include "types.h"
#include "Crashdbg.h"
#include "Crashdbg_cfg.h"
#include "isd.h"
#include "spinor_cm_defs.h"
#include "spinor_el1_api.h"
#include "debug_log.h"
#include "common_functions.h"
#include "freertos_init.h"
#include "sleepEl1.h"

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
==========================================================================================================*/
#define CRASHDBG_FUNC  __attribute__ ( ( section ( "crashdbg_func" ) ) )

#ifdef SAILSW1

#ifdef lemans
/* Critical data register dump configuration to be used for debug purposes.
 * Not exposed externally. Ideally, all default clocked and
 * readily accessible registers to be used in this list.
 * IMPORTANT NOTE - The order of registers should match with the order in which it's collected by DCC in PASS0.
 * i.e DCC Linked List1 "dcc_ll_sequence_1" in Crashdbg_dcc_cfg.c */
__attribute__((used))
volatile static char* Saildbg_regdump_names_EL1[SAILSS_REGDUMP_SIZE] =
{
  /* EAM Registers(for FUSA related source information) */
  [0] = "SAILSS_CSR_FUSA_ERROR_STATUS_0",
  [1] = "SAILSS_CSR_FUSA_ERROR_STATUS_1",
  [2] = "SAILSS_CSR_FUSA_ERROR_STATUS_2",
  [3] = "SAILSS_CSR_FUSA_ERROR_STATUS_3",
  [4] = "SAILSS_CSR_FUSA_ERROR_STATUS_4",
  [5] = "SAILSS_CSR_FUSA_ERROR_STATUS_5",
  [6] = "SAILSS_CSR_FUSA_ERROR_STATUS_6",
  [7] = "SAILSS_CSR_FUSA_ERROR_STATUS_7",
  [8] = "SAILSS_CSR_SM_ERROR_STATUS",
  [9] = "SAILSS_CSR_SAFETY_ISO_CONTROL",
  [10] = "SAILSS_CSR_TIMESTAMP_ERR_STATUS_MAIN",
  [11] = "SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_0",
  [12] = "SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_1",
  [13] = "SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_2",
  [14] = "SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_3",
  [15] = "SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_4",

  /* RTCU Lockstep comparator syndrome status registers */
  [16] = "SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME",
  [17] = "SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME",
  /* RTCU - Watchdog-FUSA syndrome */
  [18] = "SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_SYNDROME",
  [19] = "SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_SYNDROME",
  [20] = "SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_SYNDROME",
  [21] = "SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_SYNDROME",
    /* RTCU Error-Aggregator Syndrome registers */
  [22] = "SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_0",
  [23] = "SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_1",
  [24] = "SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_0",
  [25] = "SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_1",
  [26] = "SAILSS_CSR_RTCU_CLUSTER0_WARNING_SYNDROME",
  [27] = "SAILSS_CSR_RTCU_CLUSTER1_WARNING_SYNDROME",
  /* RTCU - Memory Error Fault profiling count */
  [28] = "SAILSS_CSR_RTCU_CORE_0_MEMORY_PROFILING",
  [29] = "SAILSS_CSR_RTCU_CORE_1_MEMORY_PROFILING",
  [30] = "SAILSS_CSR_RTCU_CORE_2_MEMORY_PROFILING",
  [31] = "SAILSS_CSR_RTCU_CORE_3_MEMORY_PROFILING",

  /* Island State Detector related registers */
  [32] = "SAILSS_PWR_CTRL_ISD_CONTROL",
  [33] = "SAILSS_PWR_CTRL_ISD_ISO_CTRL",
  [34] = "SAILSS_PWR_CTRL_ISD_STATUS",
  [35] = "SAILSS_PWR_CTRL_PS_HOLD",
  [36] = "SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK",
  [37] = "SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK",
  [38] = "SAILSS_PWR_CTRL_ISD_ISO_STATUS",
  [39] = "SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_ISO_EN_STATUS",
  [40] = "SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS",
  [41] = "SAILSS_PWR_CTRL_ISD_SPARE_REG_0",
  [42] = "SAILSS_PWR_CTRL_ISD_SPARE_REG_1",

  /* Power Controller (for LP-Crash) */
  [43] = "SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL",
  [44] = "SAILSS_PWR_CTRL_PWR_SEQ_WDOG_STATUS",
  [45] = "SAILSS_PWR_CTRL_PWR_CTRL_STATUS",
  [46] = "SAILSS_PWR_CTRL_ASILB_NOC_QCH_PROTOCOL",
  [47] = "SAILSS_PWR_CTRL_ASILB_NOC_QCH_STATUS",
  [48] = "SAILSS_PWR_CTRL_ASILD_NOC_QCH_PROTOCOL",
  [49] = "SAILSS_PWR_CTRL_ASILD_NOC_QCH_STATUS",
  [50] = "SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_PROTOCOL",
  [51] = "SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_STATUS",
  [52] = "SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_PROTOCOL",
  [53] = "SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_STATUS",
  [54] = "SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_PROTOCOL",
  [55] = "SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_STATUS",
  [56] = "SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_PROTOCOL",
  [57] = "SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_STATUS",
  [58] = "SAILSS_PWR_CTRL_CXO_PAD_EN_STATUS",
  [59] = "SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_0",
  [60] = "SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_0",
  [61] = "SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_1",
  [62] = "SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENTS",
  [63] = "SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_0",
  [64] = "SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_1",
  [65] = "SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENTS",
  [66] = "SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS",
  [67] = "SAILSS_PWR_CTRL_PWR_CTRL_CONTROL",
  [68] = "SAILSS_PWR_CTRL_PWR_SEQ_DBG_PROGRAM_COUNTER",
  [69] = "SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_PROGRAM_COUNTER",
  [70] = "SAILSS_CSR_SAIL_CORES_WFI_STATUS",
  [71] = "SAILSS_TLMM_SAILSS_TLMM_WEST_MPM_WAKEUP_INT_EN_1",
  [72] = "SAILSS_TLMM_SAILSS_TLMM_GPIO_CFG66",
  [73] = "SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0",
  [74] = "SAILSS_PWR_CTRL_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0"
  /* End */
};
#endif

#define SPINORDC_TASK_STACK_SIZE        1024U
#define SPINORDC_TASK_DELAY             50U

#define DDR_LOGDUMP_RESTORE_REGION_ADDR (SAIL_DDR_RESTORE_DUMP_REGION)
#define DDR_REGDUMP_RESTORE_REGION_ADDR (SAIL_DDR_RESTORE_DUMP_REGION + SAIL_DDR_DUMP_LOG_SIZE)

/* Declare task TCB. */
static StaticTask_t xSPINORDCTaskTCB = { 0 };
TaskHandle_t xSPINORDCTaskHandle = NULL;
static StackType_t xSPINORDCTaskStack[SPINORDC_TASK_STACK_SIZE] __attribute__( ( aligned( MEM_ALIGNMENT_64 ) ) ) = { 0 };

BSP_GLOBAL_DATA spinor_handle_t g_cdbg_spinor_handle = NULL;

static void prvCrashdbgDeInit_Sleep( const sleepModeType_e eState );


static uint32 ulCrashdbgSleepHandle = 0;


/* =========================================================================
**  Function : Crashdbg_spinordcTask
** =========================================================================*/
/**
  @brief This function copies SPINOR logdump and regdump data from SPINOR into DDR
  @param None
  @return None
  @dependencies None
*/
static void Crashdbg_spinordcTask(void* taskparams);

/* TODO: To be moved to crashdbg EL1 public header */ 
/*===========================================================================
**  Function : Crashdbg_spinordcTask
** =========================================================================*/
/**
  @brief This function copies SPINOR logdump and regdump data from SPINOR into DDR
  @param
  @return None
  @dependencies None
*/
extern BaseType_t xCrashdbgSPINORDCTaskInit(CPUIdType_e xSchdCore, UBaseType_t xTaskPrior);

/* =========================================================================
**  Function : xCrashdbgSPINORDCTaskInit
** =========================================================================*/
/**
  @brief This function allocates resource and creates safertos task for SPINOR dump collection
  @param None
  @return None
  @dependencies None
*/
CRASHDBG_FUNC BaseType_t xCrashdbgSPINORDCTaskInit(CPUIdType_e xSchdCore, UBaseType_t xTaskPrior)
{
    BaseType_t xResult = pdFAIL;
	UBaseType_t uxCoreAffinityMask;

    /* The structure passed to xTaskCreate() to create the check task. */
		TaskParams_t xInitTaskParameters =
	{
        .pvTaskCode     = Crashdbg_spinordcTask,                 /* The function that implements the task being created. */
        .pcName         = "cdbgSPINORDCTask",              /* The name of the task being created. The kernel does not use this itself, it's just to assist debugging. */
        .pxTaskBuffer   = &xSPINORDCTaskTCB,              /* The buffer allocated for use as the task TCB. */
        .puxStackBuffer = xSPINORDCTaskStack,             /* The buffer allocated for use as the task stack. */
		.usStackDepth   = SPINORDC_TASK_STACK_SIZE,      /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        .pvParameters   = NULL,                               /* The task parameter, not used in this case. */
        .uxPriority     = ( xTaskPrior ),                         /* The priority assigned to the task being created. */
        .xRegions       = {                                   /* The MPU task parameters. */
                                    { NULL, 0UL, 0UL},    /* No additional region definitions are required. */
                                    { NULL, 0UL, 0UL},
                                    { NULL, 0UL, 0UL},
                                    { NULL, 0UL, 0UL},
                                    { NULL, 0UL, 0UL},
                                    { NULL, 0UL, 0UL}
            }
	};
    uxCoreAffinityMask = ( 1 << xSchdCore );
    /* Check if crash debug driver init is completed and create dump collection task */
    if ((uint32_t)CRASHDBG_INIT_SUCCESS == *crashdbg_init_status_ptr)
    {
        xResult = xFreeRTOSTaskCreateAffinitySet( &xInitTaskParameters, uxCoreAffinityMask, &xSPINORDCTaskHandle);
		
    if ( SLEEP_ERR_FLAG_SUCCESS != xSleepRegisterCallBackEl1(&prvCrashdbgDeInit_Sleep,&ulCrashdbgSleepHandle,get_curr_phys_cpu_num()))
    {
        DEBUG_LOG(SAIL_INFO,"prvCrashdbgDeInit_Sleep Sleep Reg Failed\n\r");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO,"prvCrashdbgDeInit_Sleep Sleep Reg Success\n\r");
    }
    }
	else
	{
		/* If crashdebug is not initialized in hyp , no spinor DC task needed in el1. So, simply retun from the init function.*/
		xResult = pdPASS; 
	}



    return xResult;
}

/* =========================================================================
**  Function : Crashdbg_spinordcTask
** =========================================================================*/
/**
  @brief This function copies SPINOR logdump and regdump data from SPINOR into DDR
  @param None
  @return None
  @dependencies None
*/
CRASHDBG_FUNC static void Crashdbg_spinordcTask(void* taskparams)
{
    SPINOR_STATUS spinor_result;
    spinorMemInfoType mem_info;
    dump_table_type dump_table_read_buf[SAIL_MAX_DUMP] = {0};
    dump_table_type *logdump_row = NULL;
    dump_table_type *regdump_row = NULL;
    uint32 start_byte = 0;
    uint32 byte_offset = 0;
    uint32 partition_size = 0;
    boolean clear_spinor_dump = TRUE; /* indicates whether available dumps in SPINOR are restored to DDR */
    boolean valid_dump_detected = FALSE;
    char invalid_msg[] = "[ERROR] Dump data is not available in this memory region.\r\n";

    (void)(taskparams); //unused

    /* wait for S1 DDR ready. Dump data is copied to DDR if its valid, otherwise readable error message is copied */
    while(eISDGetStatus(ISD_GET_MB_READY_STATUS) != MB_READY_SUCCESS)
    {
        (void)vFreeRTOSTaskDelay(SPINORDC_TASK_DELAY);
    }

    /* Register a handle for client/crash debug user to use SPINOR services in EL2 */
    spinor_result = spinorEl1Open(&g_cdbg_spinor_handle, SPINOR_USER_TYPE_EL1);
    if (spinor_result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG(SAIL_ERROR, "[CRASHDBG] SPINOR open EL1 handle failed\r\n");
        goto exit;
    }

    /* To get info about block size, Page size and number of blocks */
    spinor_result = spinorEl1GetMemInfo(g_cdbg_spinor_handle, &mem_info);
    if (spinor_result == SPINOR_ACCESS_DENIED)
    {
        DEBUG_LOG(SAIL_ERROR, "[CRASHDBG] SPINOR EL1 get mem info failed\r\n");
        goto close_handle;
    }

    /* Get GPT info about partition start address and size allocated for ram dump/client/crash debug user */
    spinor_result = spinorEl1GetGptPartitionInfo(g_cdbg_spinor_handle, SAIL_SPINOR_GUID, &byte_offset, &partition_size);
    if (spinor_result == SPINOR_ACCESS_DENIED)
    {
        DEBUG_LOG(SAIL_ERROR, "[CRASHDBG] SPINOR EL1 get partition info failed\r\n");

        goto close_handle;
    }

    /* From above partition info, byte_offset=Start address of SAIL RAM DUMP parition as per SPINOR partition xml
    and partition_size = 0x00500000  i.e 5MB, the total size reserved for SAIL RAM DUMP.
    Note - Same DDR macro "SAIL_DDR_DUMP_SIZE" is used for size allocation check in SPINOR */
    if(partition_size < SAIL_DDR_DUMP_SIZE && (mem_info.pages_per_block * mem_info.page_size_bytes) != SAIL_SPINOR_BLKSIZE)
    {
        DEBUG_LOG(SAIL_ERROR, "[CRASHDBG] SPINOR EL1 memory allocation mismatch\r\n");
        goto close_handle;
    }

    /* Read dump table from SPINOR to check if previous crash dump data is present in SPINOR */
    start_byte = byte_offset + SAIL_SPINOR_DUMP_TBL_OFFSET;
    spinor_result = spinorEl1Read(g_cdbg_spinor_handle, start_byte, sizeof(dump_table_read_buf), (void*)dump_table_read_buf);
    if (SPINOR_DEVICE_DONE != spinor_result)
    {
        DEBUG_LOG(SAIL_ERROR, "[CRASHDBG] SPINOR read Dump Table failed\r\n");
        goto close_handle;
    }

    /* check if any of required dumps are present in SPINOR */
    for (uint8 i = 0; i < SAIL_MAX_DUMP; i++)
    {
        dump_table_type *row = &dump_table_read_buf[i];

        if (SAILDUMP_MAGIC_SUCCESS == row->magic)
        {
            if (SAIL_LOG_DUMP == row->id) logdump_row = row;
            if (SAIL_REG_DUMP == row->id) regdump_row = row;
        }
    }

        (void)vFreeRTOSTaskDelay(SPINORDC_TASK_DELAY);
    /* restore SPINOR logdump data into DDR backup region */
    if (NULL != logdump_row)
    {
        valid_dump_detected = TRUE;
        start_byte = byte_offset + logdump_row->start_addr[SAILSS_NORFLASH];
        spinor_result = spinorEl1Read(g_cdbg_spinor_handle, start_byte, logdump_row->len, (void*)(DDR_LOGDUMP_RESTORE_REGION_ADDR));
        if (SPINOR_DEVICE_DONE != spinor_result)
        {
            clear_spinor_dump = FALSE;
            DEBUG_LOG(SAIL_ERROR, "[CRASHDBG] SPINOR log dump data restore to DDR failed\r\n");
        }
    }
    else
    {
        sailbsp_memscpy((void*)DDR_LOGDUMP_RESTORE_REGION_ADDR, sizeof(invalid_msg),
            (void*)invalid_msg, sizeof(invalid_msg));
    }

        (void)vFreeRTOSTaskDelay(SPINORDC_TASK_DELAY);
    /* restore SPINOR regdump data into DDR backup region */
    if (NULL != regdump_row)
    {
        valid_dump_detected = TRUE;
        start_byte = byte_offset + regdump_row->start_addr[SAILSS_NORFLASH];
        spinor_result = spinorEl1Read(g_cdbg_spinor_handle, start_byte, regdump_row->len, (void*)(DDR_REGDUMP_RESTORE_REGION_ADDR));
        if (SPINOR_DEVICE_DONE != spinor_result)
        {
            clear_spinor_dump = FALSE;
            DEBUG_LOG(SAIL_ERROR, "[CRASHDBG] SPINOR regdump data restore to DDR failed\r\n");
        }
    }
    else
    {
        sailbsp_memscpy((void*)DDR_REGDUMP_RESTORE_REGION_ADDR, sizeof(invalid_msg),
            (void*)invalid_msg, sizeof(invalid_msg));
    }

    /* Erase SPINOR dump table if only if all the valid dump regions are restored successfully */
    if (valid_dump_detected && clear_spinor_dump)
    {
        start_byte = byte_offset + SAIL_SPINOR_DUMP_TBL_OFFSET;
        spinor_result = spinorEl1Erase(g_cdbg_spinor_handle, SPINOR_BLOCK_COUNT(start_byte), SPINOR_BLOCK_COUNT(SAIL_DDR_DUMP_TBL_SIZE));
        if (SPINOR_DEVICE_DONE != spinor_result)
        {
            DEBUG_LOG(SAIL_ERROR, "[CRASHDBG] SPINOR erase Dump Table failed\r\n");
        }
        else
        {
            DEBUG_LOG(SAIL_WARNING, "[CRASHDBG] SPINOR dump data successfully restored and erased\r\n");
        }
    }

    close_handle:
    /* Close the SPINOR handle */
    if (g_cdbg_spinor_handle)
    {
        spinor_result = spinorEl1Close(g_cdbg_spinor_handle);
        if (spinor_result != SPINOR_DEVICE_DONE)
        {
            DEBUG_LOG(SAIL_ERROR, "[CRASHDBG] SPINOR dump collection handle close failure\r\n");
        }
    }

    g_cdbg_spinor_handle = NULL;

    exit:
    vFreeRTOSTaskSuspend(NULL);
    for(;;);
}

/* =========================================================================
**  Function : Crashdbg_getLogdumpRestoreInfo
** =========================================================================*/
/**
  @brief gives start address and size of DDR logdump restore region, used by MBtest for sending this data to MD
  @param[out] uint32 *ddr_addr - log data restore region DDR address
  @param[out] uint32 *size - log data size
  @return None
  @dependencies None
*/
CRASHDBG_FUNC void Crashdbg_getLogdumpRestoreInfo(uint32 *ddr_addr, uint32 *size)
{
    *ddr_addr = DDR_LOGDUMP_RESTORE_REGION_ADDR;
    *size = SAIL_DDR_DUMP_LOG_SIZE;

    return;
}

/* =========================================================================
**  Function : Crashdbg_getRegdumpRestoreInfo
** =========================================================================*/
/**
  @brief gives start address and size of DDR regdump restore region, used by MBtest for sending this data to MD
  @param[out] uint32 *ddr_addr - regdump data restore region DDR address
  @param[out] uint32 *size - regdump data size
  @return None
  @dependencies None
*/
CRASHDBG_FUNC void Crashdbg_getRegdumpRestoreInfo(uint32 *ddr_addr, uint32 *size)
{
    *ddr_addr = DDR_REGDUMP_RESTORE_REGION_ADDR;
    *size = SAIL_DDR_DUMP_REG_SIZE;

    return;
}

/*========================================================================================================
 @Service name        prvCrashdbgDeInit_Sleep
 @Description         DeInit Call Back to register to sleep driver
 @param[in]           eState -> SLEEP_ENTRY = arg from sleep driver to Deinit crash dbg Driver
                                SLEEP_ABORT = arg from sleep driver in case sleep Driver want to abort sleep
 @param[out]          NA
 @param[in, out]      NA
 @return              void
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 =========================================================================================================*/


CRASHDBG_FUNC static void prvCrashdbgDeInit_Sleep( const sleepModeType_e eState )
{
    SPINOR_STATUS spinor_result;

    if(( STR_SLEEP_MODE == eState ) || (DEEP_SLEEP_MODE == eState))
    {
        if (g_cdbg_spinor_handle)
        {
            spinor_result = spinorEl1Close(g_cdbg_spinor_handle);
            if (spinor_result != SPINOR_DEVICE_DONE)
            {
                DEBUG_LOG(SAIL_ERROR, "[CRASHDBG] SPINOR dump collection handle close failure\r\n");
                return;
            }
            g_cdbg_spinor_handle = NULL;
        }

        if (SLEEP_ERR_FLAG_SUCCESS == xSleepDriverAckEl1(ulCrashdbgSleepHandle,DRIVER_SLEEP,get_curr_phys_cpu_num()))
        {
            vFreeRTOSTaskSuspend(xSPINORDCTaskHandle);
            DEBUG_LOG(SAIL_INFO,"prvCrashdbgDeInit_Sleep xSleepDriverAck Success\n\r");
        }
        else
        {
            DEBUG_LOG(SAIL_DEBUG,"[CRASHDBG] prvCrashdbgDeInit_Sleep xSleepDriverAck Failed\r\n");
        }
    }
    else
    {
        DEBUG_LOG(SAIL_DEBUG,"Abort Request Recieved\r\n");
    }
}

#endif /* SAILSW1 */
