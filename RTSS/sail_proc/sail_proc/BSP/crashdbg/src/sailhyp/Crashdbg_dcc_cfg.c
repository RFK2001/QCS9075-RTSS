/**********************************************************************************************************
** Copyright (c) 2021 Qualcomm Technologies, Inc.                                                        **
** All Rights Reserved.                                                                                  **
** Confidential and Proprietary - Qualcomm Technologies, Inc.                                            **
**********************************************************************************************************/

 /*========================================================================================================
    File Name          : Crashdbg_dcc_cfg.c
    Component Name     : SAIL CRASH DEBUG DCC driver
    Description        : SAIL crash debug DCC driver settings implemented in this file.
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/crashdbg/src/sailhyp/Crashdbg_dcc_cfg.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $
 ========================================================================================================*/

/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/
#include "types.h"
#include "HALhwio.h"
#include "hw_io.h"
#include "Crashdbg_dcc.h"


/*=========================================================================================================
**                                        Local defines and macros                                       **
=========================================================================================================*/
/* General macros to find array size and DCC SRAM size in KB */
#define KB(x)                         (x * 1024)
#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

/* Linked Lists Code Region */
#define DCC_LL_CODE_REGION_BASE       (0)
#define DCC_LL_CODE_REGION_SIZE       (KB(2))

/* Linked Lists Data Region */
#define DCC_LL_DATA_REGION_BASE       (DCC_LL_CODE_REGION_BASE + DCC_LL_CODE_REGION_SIZE)
#define DCC_LL_DATA_REGION_SIZE       (KB(55))

/* Linked Lists Data Region Split between linked lists currently supported/configured in SW */
/* First 50KB of Linked Lists Data Region is for LL0 to store R52 clusters scan dump data */
#define DCC_LL0_DATA_REGION_BASE      DCC_LL_DATA_REGION_BASE
#define DCC_LL0_DATA_REGION_SIZE      (KB(48)) //24KB for each R52 cluster
/* Next 2KB of Linked Lists Data Region is for LL1 to store SAILSS critical registers data */
#define DCC_LL1_DATA_REGION_BASE      (DCC_LL0_DATA_REGION_BASE + DCC_LL0_DATA_REGION_SIZE)
#define DCC_LL1_DATA_REGION_SIZE      (KB(2))
/* Last 5KB additional buffer for future use */

/* Total Linked list Region in DCC SRAM */
#define DCC_LL_SRAM_REGION_END        (KB(57)) //Code(first 2KB) + Data Region(following 55KB)

/* Offset for PC */
#define DCC_LL_PC_BYTE_OFFSET         (68) //ToDO - check and redefine value for SAIL

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
==========================================================================================================*/
/* Global DCC Settings */
static const  dcc_config_type dcc_config_data =
{
  .dcc_en = 1,
  .dcc_mem_size = KB(57),//LL Code plus Data Size. whenever we change this size, DCC_SRAM_SIZE macro shall be updated.
  .sink = DCC_SINK_SRAM,
  .pc_trigger = DCC_TRIGGER_WINDDOWN,
  .pc_offset  = DCC_LL_PC_BYTE_OFFSET,
  .pc_size = sizeof(uint64),
  .pc_count = 4,//PC of four R52 cores
};

/* Linked list 0 sequence to be executed for R52 APB scan dump at the start of PASS1, upon scan dump trigger from HW */
const __attribute__((aligned(16))) dcc_ll_entry_type dcc_ll_sequence_0 []=
{
    // Initial delays followed as such in MD.
// 1: LOOP 2 #1
    0x40010000,
// 2: LOOP 2 #2
    0x40010000,
// 3: LOOP 2 #3
    0x40010000,
    // Enable necessary clocks to access Sail DCC from R52 and vice-versa.
// STRM &HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_ADDR &HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_CLK_ENABLE_BMSK &HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_CLK_ENABLE_BMSK
    0xf111000,
    0xc0008103,
    0x80000001,
    0x1,
    0x1,
// STRM &HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_ADDR &HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_CLK_ENABLE_BMSK &HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_CLK_ENABLE_BMSK
    0xf111400,
    0xc0008102,
    0x80000001,
    0x1,
    0x1,
// STRM &HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_ADDR &HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_CLK_ENABLE_BMSK &HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_CLK_ENABLE_BMSK
    0xf111402,
    0xc0008103,
    0x80000001,
    0x1,
    0x1,
// STRM &HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_ADDR &HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_CLK_ENABLE_BMSK &HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_CLK_ENABLE_BMSK
    0xf111403,
    0xc0008100,
    0x80000001,
    0x1,
    0x1,
// STRM &HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_ADDR &HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_CLK_ENABLE_BMSK &HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_CLK_ENABLE_BMSK
    0xf111403,
    0xc0008101,
    0x80000001,
    0x1,
    0x1,
// STRM &HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_ADDR &HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_CLK_ENABLE_BMSK &HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_CLK_ENABLE_BMSK
    0xf112B00,
    0xc0008100,
    0x80000001,
    0x1,
    0x1,
    // Delay after enabling the clocks, followed as such in MD.
// 4:  LOOP 4 #4
    0x40030000,
// 5:  LOOP 4 #5
    0x40030000,
// 6:  LOOP 2 #6
    0x40010000,
// 7:  LOOP 2 #7
    0x40010000,
    // Start Scan dump of R52-Clusters by DCC.
// STR &APB:HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_ADDR 0x0
    0x3fb01000,
    0xc0000100,
    0x0,
    // Select R52-Cluster-0 first for scan dump.
// STR &APB:HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DUMP_MODE_ADDR  0x1
    0x3fb01000,
    0xc0000101,
    0x1,
    // delay - 3cycles
// 8:  LOOP 3 #8
    0x40002000,
    // Read Scan register data for R52-Cluster-0. Read register 6062 times to get the complete cluster scan chain data.
// 9:LD &HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_REG_ADDR
    0x2fb01002,
    0xc0008100,
//    LOOP 2560 #9
    0x49ff0002,
// 10:LD &HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_REG_ADDR
    0x2fb01002,
    0xc0008100,
//    LOOP 2560 #10
    0x49ff0002,
// 11:LD &HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_REG_ADDR
    0x2fb01002,
    0xc0008100,
//    LOOP 942 #11
    0x43ad0002,
    // Remove input isolation(CPU isolation) to allow scan dump reset on Cluster-0 at the end.
// STR &APB:HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_0_EN_ADDR  0x1
    0x3fb01000,
    0xc0000102,
    0x1,
    // End R52-Cluster-0 scan dump.
// STR &APB:HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DUMP_MODE_ADDR  0x0
    0x3fb01000,
    0xc0000101,
    0x0,
// STR &AHB:HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_ADDR 0x0000001
    0x1F111D02,
    0xc0000100,
    0x0000001,
// 12:  LOOP 4 #12
    0x40030000,

    // Start Scan dump of other R52-Cluster by DCC
// STR &APB:HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_ADDR 0x2
    0x3fb01000,
    0xc0000100,
    0x2,
    // Select R52-Cluster-1 for scan dump.
// STR &APB:HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DUMP_MODE_ADDR  0x2
    0x3fb01000,
    0xc0000101,
    0x2,
    // delay - 3cycles
// 13:  LOOP 3 #13
    0x40002000,
    // Read Scan register data for R52-Cluster-1. Read register 6062 times to get the complete cluster scan chain data
// 14:LD &HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_REG_ADDR
    0x2fb01002,
    0xc0008100,
//    LOOP 2560 #14
    0x49ff0002,
// 15:LD &HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_REG_ADDR
    0x2fb01002,
    0xc0008100,
//    LOOP 2560 #15
    0x49ff0002,
// 16:LD &HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_REG_ADDR
    0x2fb01002,
    0xc0008100,
//    LOOP 942 #16
    0x43ad0002,
    // Remove input isolation(CPU isolation) to allow scan dump reset to Cluster-1.
// STR &APB:HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_0_EN_ADDR  0x2
    0x3fb01000,
    0xc0000102,
    0x2,
    // End R52-Cluster-1 scan dump.
// STR &APB:HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DUMP_MODE_ADDR  0x0
    0x3fb01000,
    0xc0000101,
    0x0,

    // Assert scan dump reset on Cluster 0 & 1
// STR &AHB:HWIO_SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL_ADDR 0x3
    0x1F113460,
    0xc0000100,
    0x3,
    //delay - 10cycles
// 13:  LOOP 10 #13
    0x40090000,
    // Clears output isolation
// STR &APB:HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_1_EN_ADDR  0x3
    0x3FB01000,
    0xc0000103,
    0x3,
    //delay - 10cycles
// 14:  LOOP 10 #14
    0x40090000,

    // De-asssert scan dump reset control to bring both Cluster 0 & 1 CPU out of reset
// STR &AHB:HWIO_SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL_ADDR 0x0
    0x1F113460,
    0xc0000100,
    0x0,
// END
    0xc0000000,
};

/* Linked list 1 sequence to be executed for SAILSS critical registers data collection in PASS0, upon wind_down_req trigger from HW */
const __attribute__((aligned(16))) dcc_ll_entry_type dcc_ll_sequence_1 []=
{
// Initial delays followed as such in MD.
// 1: LOOP 2 #1
    0x40010000,
// 2: LOOP 2 #2
    0x40010000,
// 3: LOOP 2 #3
    0x40010000,
// Enable necessary clocks to access Sail DCC from R52 and vice-versa.
// STRM &HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_ADDR &HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_CLK_ENABLE_BMSK &HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_CLK_ENABLE_BMSK
    0xf111000,
    0xc0008103,
    0x80000001,
    0x1,
    0x1,
// STRM &HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_ADDR &HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_CLK_ENABLE_BMSK &HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_CLK_ENABLE_BMSK
    0xf111400,
    0xc0008102,
    0x80000001,
    0x1,
    0x1,
// STRM &HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_ADDR &HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_CLK_ENABLE_BMSK &HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_CLK_ENABLE_BMSK
    0xf111402,
    0xc0008103,
    0x80000001,
    0x1,
    0x1,
// STRM &HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_ADDR &HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_CLK_ENABLE_BMSK &HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_CLK_ENABLE_BMSK
    0xf111403,
    0xc0008100,
    0x80000001,
    0x1,
    0x1,
// STRM &HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_ADDR &HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_CLK_ENABLE_BMSK &HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_CLK_ENABLE_BMSK
    0xf111403,
    0xc0008101,
    0x80000001,
    0x1,
    0x1,
// STRM &HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_ADDR &HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_CLK_ENABLE_BMSK &HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_CLK_ENABLE_BMSK
    0xf112B00,
    0xc0008100,
    0x80000001,
    0x1,
    0x1,
// Delay after enabling the clocks, followed as such in MD.
// 4:  LOOP 4 #4
    0x40030000,
// 5:  LOOP 4 #5
    0x40030000,
// 6:  LOOP 2 #6
    0x40010000,
// 7:  LOOP 2 #7
    0x40010000,
// Collect SAILSS EAM registers - for FUSA related source information
// Read and store register - SAILSS_CSR_FUSA_ERROR_STATUS_0
    0x0F030107,
    0xC0008100,
// Read and store register - SAILSS_CSR_FUSA_ERROR_STATUS_1
    0x0F030107,
    0xC0008101,
// Read and store register - SAILSS_CSR_FUSA_ERROR_STATUS_2
    0x0F030110,
    0xC0008103,
// Read and store register - SAILSS_CSR_FUSA_ERROR_STATUS_3
    0x0F030111,
    0xC0008100,
// Read and store register - SAILSS_CSR_FUSA_ERROR_STATUS_4
    0x0F030111,
    0xC0008101,
// Read and store register - SAILSS_CSR_FUSA_ERROR_STATUS_5
    0x0F030111,
    0xC0008102,
// Read and store register - SAILSS_CSR_FUSA_ERROR_STATUS_6
    0x0F030111,
    0xC0008103,
// Read and store register - SAILSS_CSR_FUSA_ERROR_STATUS_7
    0x0F030113,
    0xC0008100,
// Read and store register - SAILSS_CSR_SM_ERROR_STATUS
    0x0F030107,
    0xC0008102,
// Read and store register - SAILSS_CSR_SAFETY_ISO_CONTROL
    0x0F030100,
    0xC0008103,
// Read and store register - SAILSS_CSR_TIMESTAMP_ERR_STATUS_MAIN
    0x0F03010C,
    0xC0008102,
// Read and store register - SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_0
    0x0F03010C,
    0xC0008103,
// Read and store register - SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_1
    0x0F03010D,
    0xC0008100,
// Read and store register - SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_2
    0x0F030119,
    0xC0008100,
// Read and store register - SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_3
    0x0F030119,
    0xC0008102,
// Read and store register - SAILSS_CSR_TIMESTAMP_ERR_STATUS_SRC_4
    0x0F030119,
    0xC0008103,
// Collect RTCU - Lockstep Comparator Syndrome
// Read and store register - SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_SYNDROME
    0x0F030006,
    0xC0008100,
// Read and store register - SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_SYNDROME
    0x0F030007,
    0xC0008100,
// Collect RTCU - Watchdog FUSA Syndrome
// Read and store register - SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_SYNDROME
    0x0F060003,
    0xC0008101,
// Read and store register - SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_SYNDROME
    0x0F060103,
    0xC0008101,
// Read and store register - SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_SYNDROME
    0x0F060203,
    0xC0008101,
// Read and store register - SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_SYNDROME
    0x0F060303,
    0xC0008101,
// Collect RTCU - Error Aggregator Syndrome
// Read and store register - SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_0
    0x0F030008,
    0xC0008102,
// Read and store register - SAILSS_CSR_RTCU_CLUSTER0_ERROR_SYNDROME_1
    0x0F030008,
    0xC0008103,
// Read and store register - SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_0
    0x0F03000A,
    0xC0008102,
// Read and store register - SAILSS_CSR_RTCU_CLUSTER1_ERROR_SYNDROME_1
    0x0F03000A,
    0xC0008103,
// Read and store register - SAILSS_CSR_RTCU_CLUSTER0_WARNING_SYNDROME
    0x0F03000B,
    0xC0008102,
// Read and store register - SAILSS_CSR_RTCU_CLUSTER1_WARNING_SYNDROME
    0x0F03000C,
    0xC0008102,
// Collect RTCU - Memory error-fault profiling count
// Read and store register - SAILSS_CSR_RTCU_CORE_0_MEMORY_PROFILING
    0x0F03000E,
    0xC0008100,
// Read and store register - SAILSS_CSR_RTCU_CORE_1_MEMORY_PROFILING
    0x0F03000E,
    0xC0008101,
// Read and store register - SAILSS_CSR_RTCU_CORE_2_MEMORY_PROFILING
    0x0F03000E,
    0xC0008102,
// Read and store register - SAILSS_CSR_RTCU_CORE_3_MEMORY_PROFILING
    0x0F03000E,
    0xC0008103,
// Collect Island State Detector registers
// Read and store register - SAILSS_PWR_CTRL_ISD_CONTROL
    0x0F100000,
    0xC0008100,
// Read and store register - SAILSS_PWR_CTRL_ISD_ISO_CTRL
    0x0F100000,
    0xC0008101,
// Read and store register - SAILSS_PWR_CTRL_ISD_STATUS
    0x0F100000,
    0xC0008102,
// Read and store register - SAILSS_PWR_CTRL_PS_HOLD
    0x0F100000,
    0xC0008103,
// Read and store register - SAILSS_PWR_CTRL_SAIL_FATAL_ERR_ISO_EN_MASK
    0x0F100001,
    0xC0008100,
// Read and store register - SAILSS_PWR_CTRL_SAIL_FATAL_ERR_PS_HOLD_EN_MASK
    0x0F100001,
    0xC0008101,
// Read and store register - SAILSS_PWR_CTRL_ISD_ISO_STATUS
    0x0F100002,
    0xC0008102,
// Read and store register - SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_ISO_EN_STATUS
    0x0F100002,
    0xC0008103,
// Read and store register - SAILSS_PWR_CTRL_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS
    0x0F100003,
    0xC0008100,
// Read and store register - SAILSS_PWR_CTRL_ISD_SPARE_REG_0
    0x0F100003,
    0xC0008101,
// Read and store register - SAILSS_PWR_CTRL_ISD_SPARE_REG_1
    0x0F100003,
    0xC0008102,
// Collect Power controller registers related to crash in low power mode
// Read and store register - SAILSS_PWR_CTRL_PWR_SEQ_WDOG_CTRL
    0x0F100040,
    0xC0008100,
// Read and store register - SAILSS_PWR_CTRL_PWR_SEQ_WDOG_STATUS
    0x0F100040,
    0xC0008102,
// Read and store register - SAILSS_PWR_CTRL_PWR_CTRL_STATUS
    0x0F100042,
    0xC0008101,
// Read and store register - SAILSS_PWR_CTRL_ASILB_NOC_QCH_PROTOCOL
    0x0F100042,
    0xC0008102,
// Read and store register - SAILSS_PWR_CTRL_ASILB_NOC_QCH_STATUS
    0x0F100043,
    0xC0008100,
// Read and store register - SAILSS_PWR_CTRL_ASILD_NOC_QCH_PROTOCOL
    0x0F100043,
    0xC0008101,
// Read and store register - SAILSS_PWR_CTRL_ASILD_NOC_QCH_STATUS
    0x0F100043,
    0xC0008103,
// Read and store register - SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_PROTOCOL
    0x0F100044,
    0xC0008100,
// Read and store register - SAILSS_PWR_CTRL_CLUSTER0_CORE0_PCH_STATUS
    0x0F100044,
    0xC0008102,
// Read and store register - SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_PROTOCOL
    0x0F100044,
    0xC0008103,
// Read and store register - SAILSS_PWR_CTRL_CLUSTER0_CORE1_PCH_STATUS
    0x0F100045,
    0xC0008101,
// Read and store register - SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_PROTOCOL
    0x0F100045,
    0xC0008102,
// Read and store register - SAILSS_PWR_CTRL_CLUSTER1_CORE0_PCH_STATUS
    0x0F100046,
    0xC0008100,
// Read and store register - SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_PROTOCOL
    0x0F100046,
    0xC0008101,
// Read and store register - SAILSS_PWR_CTRL_CLUSTER1_CORE1_PCH_STATUS
    0x0F100046,
    0xC0008103,
// Read and store register - SAILSS_PWR_CTRL_CXO_PAD_EN_STATUS
    0x0F100051,
    0xC0008103,
// Read and store register - SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_0
    0x0F100060,
    0xC0008100,
// Read and store register - SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_0
    0x0F100120,
    0xC0008102,
// Read and store register - SAILSS_PWR_CTRL_PWR_SEQ_PWR_CONTROL_1
    0x0F100120,
    0xC0008103,
// Read and store register - SAILSS_PWR_CTRL_PWR_SEQ_WAIT_EVENTS
    0x0F100121,
    0xC0008100,
// Read and store register - SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_0
    0x0F100150,
    0xC0008102,
// Read and store register - SAILSS_PWR_CTRL_CRASH_WAKEUP_PWR_CONTROL_1
    0x0F100150,
    0xC0008103,
// Read and store register - SAILSS_PWR_CTRL_CRASH_WAKEUP_WAIT_EVENTS
    0x0F100151,
    0xC0008100,
// Read and store register - SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS
    0x0F114902,
    0xC0008100,
// Read and store register - SAILSS_PWR_CTRL_PWR_CTRL_CONTROL
    0x0F100042,
    0xC0008100,
// Read and store register - SAILSS_PWR_CTRL_PWR_SEQ_DBG_PROGRAM_COUNTER
    0x0F100100,
    0xC0008103,
// Read and store register - SAILSS_PWR_CTRL_CRASH_WAKEUP_DBG_PROGRAM_COUNTER
    0x0F100130,
    0xC0008103,
// Read and store register - SAILSS_CSR_SAIL_CORES_WFI_STATUS
    0x0F030503,
    0xC0008103,
// Read and store register - SAILSS_TLMM_SAILSS_TLMM_WEST_MPM_WAKEUP_INT_EN_1
    0x0F014F00,
    0xC0008101,
// Read and store register - SAILSS_TLMM_SAILSS_TLMM_GPIO_CFG66
    0x0F014200,
    0xC0008100,
// END
    0xc0000000,
};

/* Linked List specific settings */
static const dcc_ll_config_type dcc_ll_config[] =
{
 /* Configure Linked List ID 0 for Scan dump */
 [0] =
      {
      /* Linked List index */
      .ll_idx = 0,
      /* Linked List timeout */
      .ll_timeout = 0xFFF, //Same as MD
      .ll_timeout_en = 1,
      /* Linked List per-transaction timeout */
      .llt_timeout = 0x0,  //Same as MD
      .llt_timeout_en = 1,
      /* Linked List start offset */
      .ll_offset = DCC_LL_CODE_REGION_BASE,
      /* FD start address offset for a given sink
       * from the start offset.*/
      .ll_fd_offset = DCC_LL0_DATA_REGION_BASE,
      .ll_fd_size   = DCC_LL0_DATA_REGION_SIZE,
      /* Linked list trigger */
      .ll_trigger = DCC_TRIGGER_SCANDUMP,
      /* Linked list */
      .ll = (void *)dcc_ll_sequence_0,
      .ll_size = sizeof(dcc_ll_sequence_0),
      },
 /* Configure Linked List ID 1 for SAILSS critical registers data collection */
 [1] =
      {
      /* Linked List index */
      .ll_idx = 1,
      /* Linked List timeout */
      .ll_timeout = 0xFFF, //Same as MD
      .ll_timeout_en = 1,
      /* Linked List per-transaction timeout */
      .llt_timeout = 0x50, //In MD - timeout =0x0
      .llt_timeout_en = 1,
      /* Linked List start offset */
      .ll_offset = DCC_LL_CODE_REGION_BASE + sizeof(dcc_ll_sequence_0),
      /* FD start address offset for a given sink
       * from the start offset.*/
      .ll_fd_offset = DCC_LL1_DATA_REGION_BASE,
      .ll_fd_size   = DCC_LL1_DATA_REGION_SIZE,
      /* Linked list trigger */
      .ll_trigger = DCC_TRIGGER_WINDDOWN,
      /* Linked list */
      .ll = (void *)dcc_ll_sequence_1,
      .ll_size = sizeof(dcc_ll_sequence_1),
      },
/*ToDO - PC info collection can be added as a LL if needed for SAIL, LL ID to be specified */
};

/*=========================================================================================================
**                          Internal Functions                                                           **
==========================================================================================================*/


/*=========================================================================================================
**                          Function Definitions - Sail Crash Debug DCC driver setting                    **
==========================================================================================================*/
/*===========================================================================
**  Function :  dcc_get_ll_config
** ==========================================================================
*/
/*!
*
* @brief : Get Linked List Configuration
* @param : idx [in] Linked List ID 0-7
* @Dependencies :
* @retval : dcc_cfg_ptr [out] Points to the location of Linked List configuration requested.
* @Side Effects : None
*
*/
const  dcc_ll_config_type *dcc_get_ll_config(uint32 idx)
{
  const dcc_ll_config_type *dcc_cfg_ptr = NULL;

  if (idx < ARRAY_SIZE(dcc_ll_config))
    dcc_cfg_ptr = &dcc_ll_config[idx];

  return dcc_cfg_ptr;
}

/*===========================================================================
**  Function :  dcc_get_ll_cnt
** ==========================================================================
*/
/*!
*
* @brief : Get the number of Linked List Configuration supported.
* @param : None
* @Dependencies :
* @retval : dcc_cfg_size [out] Size of Linked List, Possible values 1 to 8.
* @Side Effects : None
*
*/
const  uint32 dcc_get_ll_cnt(void)
{
  uint32 dcc_cfg_size = 0;

  dcc_cfg_size = ARRAY_SIZE(dcc_ll_config);

  return dcc_cfg_size;
}

/*===========================================================================
**  Function :  dcc_get_config
** ==========================================================================
*/
/*!
*
* @brief : Get the DCC settings info i.e DCC sink type, sink memory size, trigger type etc.
* @param : None
* @Dependencies :
* @retval : dcc_config_data [out] Points to the DCC settings information.
* @Side Effects : None
*
*/
const dcc_config_type *dcc_get_config(void)
{
  return &dcc_config_data;
}
/**********************************************************************************************************
**                                  End of file Crashdbg_dcc_cfg                                         **
**********************************************************************************************************/
