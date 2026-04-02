/**********************************************************************************************************
    Copyright (c) 2022 Qualcomm Technologies, Inc.
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
**********************************************************************************************************/

/*=========================================================================================================
    File Name          : Crashdbg_cfg.h
    Component Name     : Crash Debug
    Description        : Crash Debug feature global interfaces and global parameters are defined here.
    $Header: //components/dev/bsp.sail/1.0/sikk.bsp.sail.1.0.ddrdump9/crashdbg/inc/Crashdbg_cfg.h#1 $
    $DateTime: 2022/04/21 15:21:59 $
    $Author: sikk $
=========================================================================================================*/

/* Include header file guard */
#ifndef _CRASHDBG_CFG_H_
#define _CRASHDBG_CFG_H_

/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/
#include "types.h"
#include "common_functions.h"


/*=========================================================================================================
**                          SAILSS Dump data - 5MB Reserved in both DDR and SPINOR                       **
** IMPORTANT NOTE-Each dump size shall be in 4KB blocks,as it's the min. block size supported in SPINOR  **
** PASS1        SAIL Log data           20KB                                                             **
**              SAIL SRAM data          3MB(3072KB)                                                      **
**              SAIL Cache data         256KB(64KB per R52 core: 32KB DataCache/32KB InstructionCache)   ** 
**              SAIL TCM data           64KB(64KB per R52 core. In PASS1, only boot core can be dumped)  **
** PASS2        SAIL Registers data     8KB                                                              **
**              SAIL R52 APB scandump   64KB(both R52 clusters/4 cores)                                  **
**              SAIL crash debug Log    4KB                                                              **
**              SAIL Dump Format        4KB                                                              **
=========================================================================================================*/
/*=========================================================================================================
**                          SAILSS DDR Region- SAILSS_DDR_256_0 - Address 0x2000 0000 to 0x2FFF FFFF     **
=========================================================================================================*/
/* SAIL DDR Region Start Address and Total Size reserved for Sail crash dump */
#define SAIL_DDR_DUMP_STARTADDR         (0x2FB00000UL) // Top 5MB of SAILSS_DDR_256_0
#define SAIL_DDR_DUMP_SIZE              (0x500000UL)   // 5MB size reserved for SAIL crash debug data dump in DDR
#define SAIL_DDR_RESTORE_DUMP_REGION    (0x2FF80000UL)  // Higher 512KB in 5MB region is used for SPINOR dump restore
#define SAIL_DDR_RESTORE_DUMP_SIZE      (512*1024U)

/* SAIL DDR Region - Split up for each dump data entry */

/* DDR Regions to be dumped in PASS1 */

/* DDR Region - SAIL log data from QUP RAM */
#define SAIL_DDR_DUMP_LOG_STARTADDR  (SAIL_DDR_DUMP_STARTADDR) //0x2FB00000
#define SAIL_DDR_DUMP_LOG_SIZE       (0x5000UL)    // 20KB size reserved for SAIL log data in DDR

/* DDR Region - SAIL SRAM data */
#define SAIL_DDR_DUMP_SRAM_STARTADDR (SAIL_DDR_DUMP_LOG_STARTADDR + SAIL_DDR_DUMP_LOG_SIZE) //0x2FB05000
#define SAIL_DDR_DUMP_SRAM_SIZE      (0x300000UL)  // 3MB size reserved for SAIL SRAM data dump in DDR

/* DDR Region - SAIL Data and Instruction cache of all cores */
#define SAIL_DDR_DUMP_ICACHE_STARTADDR (SAIL_DDR_DUMP_SRAM_STARTADDR + SAIL_DDR_DUMP_SRAM_SIZE) //0x2FE05000
#define SAIL_DDR_DUMP_CORE_CACHE_TAGSIZE  (0x800UL)   // Icache - 2KB TAG RAM; same for Dcache
#define SAIL_DDR_DUMP_CORE_CACHE_DATASIZE (0x8000UL)  // Icache - 32KB DATA RAM; same for Dcache
#define SAIL_DDR_DUMP_CORE_CACHEDUMP_SIZE (SAIL_DDR_DUMP_CORE_CACHE_TAGSIZE + SAIL_DDR_DUMP_CORE_CACHE_DATASIZE)
#define SAIL_DDR_DUMP_DCACHE_STARTADDR    (SAIL_DDR_DUMP_ICACHE_STARTADDR + SAIL_DDR_DUMP_CORE_CACHEDUMP_SIZE)
#define SAIL_DDR_DUMP_CACHE_SIZE          (0x40000UL) // Total 256KB size reserved for SAIL cache dump in DDR

#define SAIL_DDR_DUMP_TASKHISTORY_STARTADDR (SAIL_DDR_DUMP_ICACHE_STARTADDR + SAIL_DDR_DUMP_CACHE_SIZE) //0x2FE45000
#define SAIL_DDR_DUMP_TASKHISTORY_SIZE      (0x4000UL)    // 16KB size 
#define SAIL_DDR_DUMP_GICINTSTAT_STARTADDR (SAIL_DDR_DUMP_TASKHISTORY_STARTADDR + SAIL_DDR_DUMP_TASKHISTORY_SIZE) //0x2FE49000
#define SAIL_DDR_DUMP_GICINTSTAT_SIZE      (0x1000U)    // 4KB size
/* DDR Region - 64KB reserved space */
#define SAIL_DDR_DUMP_RESERVED_1_STARTADDR (SAIL_DDR_DUMP_GICINTSTAT_STARTADDR + SAIL_DDR_DUMP_GICINTSTAT_SIZE) //0x2FE4A000
#define SAIL_DDR_DUMP_RESERVED_1_SIZE      (0xB000UL)    // 44KB

/* DDR Regions to be dumped in PASS2 */

/* DDR Region - SAIL registers data(FUSA, PwrCtrl, Syndromes, Watchdog etc) from DCC SRAM */
#define SAIL_DDR_DUMP_REG_STARTADDR  (SAIL_DDR_DUMP_RESERVED_1_STARTADDR + SAIL_DDR_DUMP_RESERVED_1_SIZE) //0x2FE55000
#define SAIL_DDR_DUMP_REG_SIZE       (0x2000UL)    // 8KB size reserved for SAIL Registers data in DDR

/* DDR Region - SAIL R52 APB Scandump data from DCC SRAM */
#define SAIL_DDR_APB_SCANDUMP_STARTADDR (SAIL_DDR_DUMP_REG_STARTADDR + SAIL_DDR_DUMP_REG_SIZE) //0x2FE57000
#define SAIL_DDR_APB_SCANDUMP_SIZE      (0x10000UL) // 64KB size reserved for SAIL R52 APB scandump data in DDR

/* DDR Region - SAIL crash debug log */
#define SAIL_DDR_DUMP_DBGLOG_STARTADDR (SAIL_DDR_APB_SCANDUMP_STARTADDR + SAIL_DDR_APB_SCANDUMP_SIZE) //0x2FE67000
#define SAIL_DDR_DUMP_DBGLOG_SIZE      (0x1000UL) // 4KB size reserved for SAIL crash debug log in Pass1/Pass2

/* DDR Region - SAIL Dump Data Format for PASS1 */
#define SAIL_DDR_DUMP_TBL_STARTADDR (SAIL_DDR_DUMP_DBGLOG_STARTADDR + SAIL_DDR_DUMP_DBGLOG_SIZE) //0x2FE68000
#define SAIL_DDR_DUMP_TBL_SIZE      (0x1000UL)    // 4KB size reserved for SAIL Dump Format

/* DDR Region - SAIL TCM content of all cores to be dumped in PASS1 */
#define SAIL_DDR_DUMP_TCM_STARTADDR (SAIL_DDR_DUMP_TBL_STARTADDR + SAIL_DDR_DUMP_TBL_SIZE) //0x2FE69000
#define SAIL_DDR_DUMP_TCM_SIZE      (0x60000UL)    // 384KB size reserved for SAIL boot core TCM dump in DDR

/* Place spare reg info at the higher 4KB of the 5MB region */ 
#define SAIL_DDR_CRASHDBG_STATUS_ADDR ((SAIL_DDR_DUMP_STARTADDR + SAIL_DDR_DUMP_SIZE) - 4096U) //0x2FFFF000

/*=========================================================================================================
**                      SAILSS SPINOR - Refer SPINOR partition xml for the Start address and Size(5MB)   **
=========================================================================================================*/
/* SAIL SPINOR Region - Split up for each dump data entry */
/* Start address and Size reserved for the complete SAIL dump will be retrieved via SPINOR GPT info API
   Hence, define address offset and the number of blocks(4KB per block) to be erased before SPINOR write */
#define SAIL_SPINOR_BLKSIZE  (uint32)4096
#define SPINOR_BLOCK_COUNT(_byte_) ((_byte_)/SAIL_SPINOR_BLKSIZE)

/* SPINOR Regions to be dumped in PASS1 */

/* SPINOR Offset address - SAIL log data from QUP RAM */
#define SAIL_SPINOR_DUMP_LOG_OFFSET  (0x0UL)


/* SPINOR Regions to be dumped in PASS2 */

/* SPINOR Offset address  - SAIL registers data(FUSA, PwrCtrl, Syndromes, Watchdog etc) from DCC SRAM */
#define SAIL_SPINOR_DUMP_REG_OFFSET  (SAIL_SPINOR_DUMP_LOG_OFFSET + SAIL_DDR_DUMP_LOG_SIZE) //0x5000

/* SPINOR Offset address - SAIL R52 APB Scandump data from DCC SRAM */
#define SAIL_SPINOR_APB_SCANDUMP_OFFSET (SAIL_SPINOR_DUMP_REG_OFFSET + SAIL_DDR_DUMP_REG_SIZE) //0x357000

/* SPINOR Offset address - SAIL crash debug log */
#define SAIL_SPINOR_DUMP_DBGLOG_OFFSET (SAIL_SPINOR_APB_SCANDUMP_OFFSET + SAIL_DDR_APB_SCANDUMP_SIZE) //0x367000

/* SPINOR Offset address - SAIL Dump Data Format for PASS1 */
#define SAIL_SPINOR_DUMP_TBL_OFFSET (SAIL_SPINOR_DUMP_DBGLOG_OFFSET + SAIL_DDR_DUMP_DBGLOG_SIZE) //0x368000

/* SPINOR Offset address - SAIL TCM content of all cores to be dumped in PASS1 */
#define SAIL_SPINOR_DUMP_TASKHISTORY_OFFSET (SAIL_SPINOR_DUMP_TBL_OFFSET + SAIL_DDR_DUMP_TBL_SIZE)//0x19000

/* SPINOR Offset address - SAIL GICINTSTAT dump */
#define SAIL_SPINOR_DUMP_GICINTSTAT_OFFSET (SAIL_SPINOR_DUMP_TASKHISTORY_OFFSET + SAIL_DDR_DUMP_TASKHISTORY_SIZE)//0x1D000
/* SPINOR Offset undefined - to fill up in dump format table which is common for both DDR/SPINOR dump */
/*Undefined value should be greater than or equal to ramdump partition size so that it doesn't overwrite other crashdumps regions*/
#define SAIL_SPINOR_OFFSET_UNDEFINED  (0x20000000UL) 
/* SPINOR GUID for SAIL RAM DUMP partition */
#define SAIL_SPINOR_GUID "46117b39-6a0f-4cf9-b70a-71c09a62ba72"

/* SPINOR page size - 256 bytes i.e 64 words.
Note- SPINOR write in pages(min. write size) will be faster  */
#define SAIL_SPINOR_PAGESIZE_IN_WORDS  64

/*=========================================================================================================
**                          SAILSS Debug data memory info                                                **
=========================================================================================================*/
#if defined(SAIL_RTOS) || defined(NORPVL_ENB)
/* Source address info of SAIL log data i.e QUP RAM Start address */
#define SAIL_LOG_QUPRAM_STARTADDR         HYP_DEBUGLOG_STARTADDRESS
#define SAIL_QUPRAM_HYP_LOG_SIZE          (HYP_DEBUGLOG_SIZE + HYP_DEBUGLOG_EXTRA_SIZE)
#define SAIL_QUPRAM_NON_HYP_STARTADDR     OS_DEBUGLOG_STARTADDRESS
#define SAIL_QUPRAM_NON_HYP_SIZE          (OS_DEBUGLOG_SIZE + OS_DEBUGLOG_EXTRA_SIZE)

#elif defined(SAIL_CASAR)

/* Source address info of SAIL log data i.e QUP RAM Start address */
#define SAIL_LOG_QUPRAM_STARTADDR         HYP_DEBUGLOG_STARTADDRESS
#define SAIL_QUPRAM_HYP_LOG_SIZE          (HYP_DEBUGLOG_SIZE + HYP_DEBUGLOG_EXTRA_SIZE)
#define SAIL_QUPRAM_NON_HYP_STARTADDR     0x1f03c00U
#define SAIL_QUPRAM_NON_HYP_SIZE          0x2000U

#endif
/* Source address info of SAIL SRAM i.e SRAM Start address */
#define SAIL_SRAM_STARTADDR               (0x08000000UL)
#define SAIL_SRAM_HYP_SIZE                (0xE1000) /* 900KB - it comes from the SRAM memory map */
#define SAIL_SRAM_NON_HYP_STARTADDR       (SAIL_SRAM_STARTADDR + SAIL_SRAM_HYP_SIZE) /* 900KB from start of SRAM is secure data, followed by 2.1MB of non-secure data */ 
#define SAIL_SRAM_NON_HYP_SIZE            (SAIL_DDR_DUMP_SRAM_SIZE - SAIL_SRAM_HYP_SIZE) /* 3MB(total SRAM size) - 900KB(hypervisor) */

#if defined(__ARM_GNU__)
  /* shared memory where crash debug init status is updated by sailhyp during boot up */
  extern volatile uint32_t lnk_shr_cdbg_status;
  #define crashdbg_init_status_ptr (&lnk_shr_cdbg_status)

  /* Source address info of SAIL SRAM i.e SRAM Start address of EL1 TASK SWITCH HISTORY */
  extern uint32_t lnk_shr_sailsw1_task_history;
  extern uint32_t lnk_shr_sail_gic_init_stat;

  #define SAIL_SRAM_EL1TASKHIST_STARTADDR		      (&lnk_shr_sailsw1_task_history)
  #define SAIL_SRAM_GICINTSTAT_STARTADDR    		  (&lnk_shr_sail_gic_init_stat)

#elif defined(__ARM_FUSA__)
  /* shared memory where crash debug init status is updated by sailhyp during boot up */
  extern volatile uint32_t Image$$SHR_CDBGSTATUS$$RO$$Base;
  #define crashdbg_init_status_ptr (&Image$$SHR_CDBGSTATUS$$RO$$Base)

  /* Source address info of SAIL SRAM i.e SRAM Start address of EL1 TASK SWITCH HISTORY */
  extern uint32_t Image$$SHR_SAILSW1_TASKHISTORY$$ZI$$Base;
  extern uint32_t Image$$SHR_SAIL_GICINTSTAT$$ZI$$Base;

  #define SAIL_SRAM_EL1TASKHIST_STARTADDR 				(&Image$$SHR_SAILSW1_TASKHISTORY$$ZI$$Base)
  #define SAIL_SRAM_GICINTSTAT_STARTADDR 				  (&Image$$SHR_SAIL_GICINTSTAT$$ZI$$Base)
#else
    #error "Unknown Linker Symbols Format"
#endif

/*=========================================================================================================
**                          SAILSS Magic and Format Version/Numbers for each dump type                   **
=========================================================================================================*/
#define SAILDUMP_MAGIC_SUCCESS 0x5341494C //ASCII-"SAIL". This magic number shall be common for all dump types.
#define SAILDUMP_MAGIC_DEFAULT 0xFFFFFFFF
#define SAILDUMP_MAGIC_FAILURE 0x00FA11ED

// 0x(Major version)(Minor version)
#define LOG_DUMP_FORMAT_VERSION     0x10
#define SRAM_DUMP_FORMAT_VERSION    0x10
#define REG_DUMP_FORMAT_VERSION     0x20
#define SCAN_DUMP_FORMAT_VERSION    0x10
#define CACHE_DUMP_FORMAT_VERSION   0x10
#define TABLE_DUMP_FORMAT_VERSION   0x10
#define TCM_DUMP_FORMAT_VERSION     0x10
#define DBGLOG_DUMP_FORMAT_VERSION  0x10

/*=========================================================================================================
**                          SAILSS Reset Status update in PASS2 - UART console                           **
=========================================================================================================*/
#define SRST_STS_MSK         HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SRST_RESET_STATUS_BMSK
#define SRST_STS_SHFT        HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SRST_RESET_STATUS_SHFT
#define QDSS_SW_RST_MSK      HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_QDSS_SW_SRST_RESET_STATUS_BMSK
#define QDSS_SW_RST_SHFT     HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_QDSS_SW_SRST_RESET_STATUS_SHFT
#define MDPSHLDRST_STS_MSK   HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_MD_PS_HOLD_RESET_STATUS_BMSK
#define MDPSHLDRST_STS_SHFT  HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_MD_PS_HOLD_RESET_STATUS_SHFT
#define MDPMICFLT_STS_MSK    HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_MD_PMIC_FAULT_RESET_STATUS_BMSK
#define MDPMICFLT_STS_SHFT   HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_MD_PMIC_FAULT_RESET_STATUS_SHFT
#define PWRSEQWDOG_EXP_MSK   HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_PWR_SEQ_WDOG_EXPIRE_RESET_STATUS_BMSK
#define PWRSEQWDOG_EXP_SHFT  HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_PWR_SEQ_WDOG_EXPIRE_RESET_STATUS_SHFT
#define PMICABNRESIN_MSK     HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_PMIC_ABNORMAL_RESIN_RESET_STATUS_BMSK
#define PMICABNRESIN_SHFT    HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_PMIC_ABNORMAL_RESIN_RESET_STATUS_SHFT
#define TSENS1RST_STS_MSK    HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_TSENSE1_RESET_STATUS_BMSK
#define TSENS1RST_STS_SHFT   HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_TSENSE1_RESET_STATUS_SHFT
#define TSENS0RST_STS_MSK    HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_TSENSE0_RESET_STATUS_BMSK
#define TSENS0RST_STS_SHFT   HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_TSENSE0_RESET_STATUS_SHFT
#define R52WDOG_EXP_MSK      HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_R52_WDOG_EXPIRE_RESET_STATUS_BMSK
#define R52WDOG_EXP_SHFT     HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_R52_WDOG_EXPIRE_RESET_STATUS_SHFT

/*=========================================================================================================
**                          SAILSS ARM R52 Cache Registers bit field access macros                       **
=========================================================================================================*/
#define R52_CCSIDR_LINESIZE 0x2  //16 words per cache line
#define R52_CCSIDR_NUMSETS  0x7F //128 Set-Index per Way/Cache page/Cache block
#define R52_CCSIDR_NUMWAYS  0x3  //4 Ways/Cache pages/Cache blocks

#define R52_CACHE_TAGOFFS_INWORDS 1  //Tag RAM has 1word tag per line(23 bits max incl.valid bit)
#define R52_CACHE_DATAOFFS_INDWORDS 8 //Data RAM has 8 double-words data per cache line

#define R52_IMP_CDBGxCD_BITSHFT_DATAOFFS 3 //Bit5:3 - Data Offset encoding
#define R52_IMP_CDBGxCD_BITSHFT_SETINDEX 6 //Bit12:6 - Set-Index encoding
#define R52_IMP_CDBGxCD_BITSHFT_WAY 30     //Bit31:30 - Cache way encoding
/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/
/**
  Sail Crash Reset debug configuration information
 */
typedef struct
{
    /* SailSS Reset debug enable global flag */
    const uint32 sail_rst_dbg_en;

  /* Sail SS crash debug enablement */
    /* R52 Watchdog bite/reset debug enable */
    const uint32 wdog_rst_dbg_en;
    /* Sail Temperature sensor reset debug enable */
    const uint32 sail_tsense_rst_dbg_en;
  /* Sail PMIC Resin reset debug enable */
    const uint32 sail_pmic_resin_rst_dbg_en;
    /* Allow other reset debug enable */
    const uint32 allow_other_rst_dbg_en;
    /* Power sequencer watchdog reset debug enable */
    const uint32 pwrseq_wdog_rst_dbg_en;
  /* MD PMIC fault reset debug enable */
    const uint32 md_pmic_fault_rst_dbg_en;
  /* MD_PS_HOLD deassertion reset debug enable */
    const uint32 md_ps_hold_rst_dbg_en;
  /* Access reset first pass debug enable - 
  to access control xPU/VMIDMT logic at the start of debug first pass */
    const uint32 acc_ctrl_rst_dbg_en;
  
  /* Crash debug overrides to dump debug data */
    /* Cache invalidation disable */
    const uint32 cache_inv_dis;
    /* GPRs initialization disable */
    const uint32 reg_init_dis;
  
  /* PASS1 Timer configuration */
    /* PASS1 Timer enable/disable */
    const uint32 sail_pass1_tmr_en;
    /* Timeout value for sail to complete PASS1 */
    const uint32 sail_pass1_timeout;

  /* Abnormal Wakeup timeout to continue crash reset flow,
  when "crash_wakeup_seq_done" is not set by Crash wakeup sequencer in PASS0 */
    const uint32 sail_abnwkup_timeout;
  /* Wakeup Timer enable/disable */
    const uint8 sail_wkup_tmr_en;
    /* Wind down Timer (ms) - For varoius blocks like Voltage Sensor Slave controller and DCC
  to wind down their operation and flush trace to ETB, as preparation step before reset occurs */
    const uint16 wind_down_time;
    /* Save Contents timer (ms) - Period for flushing trace to ETR or saving contents in local buffers 
  as preparation step before reset occurs */
    const uint16 save_data_time;
    /* Stop Capture timer (ms) - For asserting stop capture CTI signal in order to stop trace formatter */
    const uint16 stop_trace_time;
    /* Prepare for Reset timer (ms) - For asserting pre_ares signal to various block such as MPM */
    const uint16 prep_reset_time;
  
}Saildbg_config_type;

/*=========================================================================================================
**                          SAIL Registers Data Dump Structure Format                                    **
=========================================================================================================*/
/**
  Sail critical debug data registers(EAM-FUSA, ISD, Pwr Ctrl, RTCU syndromes) dump format 
 */
typedef struct
{
    const char*  register_name;
    uint32 register_val;
}SaildbgRegdump_type;

/*=========================================================================================================
**                          CACHE ID                                                                     **
=========================================================================================================*/
/* Sail Cache type possible in register CSSELR-bit0-"InD" i.e Instruction not Data bit */
typedef enum
{
    SAILSS_L1_DCACHE = 0x0,
    SAILSS_L1_ICACHE = 0x1,
}SaildbgL1cachetype;

/*========================================================================================================
**     Dump Format for SAIL DUMP_TYPE_DATA (DUMP_TYPE_TABLE is not needed as SAIL is the only client)   **
=========================================================================================================*/
/* Dump Type(ID) - list all SAIL data to be dumped. 
  Low significant nibble shall be used for instances, i.e to identify each core/cpu related dumps */
typedef enum
{
    /* Regions dumped in PASS1 */
    SAIL_DUMP_TABLE_P1     = 0x00,  // dump format - dump table for PASS1
    SAIL_DATA_SRAM_DUMP    = 0x01,  // SAIL SRAM data.
    SAIL_LOG_DUMP          = 0x02,  // SAIL debug log data.
    CPU_L1_ICACHE_DUMP     = 0x03,  // L1 Instruction cache.
    CPU_L1_DCACHE_DUMP     = 0x04,  // L1 Data cache.
    CPU_TCM_DUMP           = 0x05,  // R52 TCM content.
    EL1_TASKHIST_DUMP      = 0x06,
    SAIL_GICINTSTAT_DUMP   = 0x07,

    /* Regions dumped in PASS2 */
    SAIL_DUMP_TABLE_P2     = 0x08,  // dump format - dump table for PASS2
    SAIL_DATA_APB_SCANDUMP = 0x09,  // APB Scandump data of both SAIL R52 clusters.
    SAIL_REG_DUMP          = 0x0A,  // SAIL critical registers data(EAM-FUSA, ISD, Pwr Ctrl, RTCU syndromes).
    SAIL_DBGLOG_DUMP       = 0x0B,  // SAIL PASS2 console log data.

    SAIL_MAX_DUMP
}dump_type;

/* Dump data structure for each dump_type/ID's listed above */
typedef struct
{
    dump_type id;                             // dump_type enum id
    uint32 version;                           // Format[3:0]-Minor revision,[7:4]-Major revision for each data dump_type.This will be set after dump is complete.
    uint32 magic;                             // This will be set after dump is complete. Shall be common for all dump_type.
    uint32 start_addr[SAILSS_DUMP_TYPE_MAX];  // Start address of each SAIL data dump_type in DDR and SPINOR(offset).
    uint32 len;                               // Size of each SAIL data dump_type.
}dump_table_type;

/* Dump data structure to access all dump_table_type entries from SAIL dump table memory block(DDR/SPINOR) */
typedef struct
{
    dump_table_type entries[SAIL_MAX_DUMP];
}dump_table_entrytype;

/* CSR SPARE REGISTER bitwise information */
typedef enum {
    SR_FULL_DUMP_ENABLED       = 0,

    SR_SDI_ENTRY               = 4,
    SR_MD_DDR_RDY_P1           = 5,
    SR_LOG_DUMP_COMPLETE       = 6,
    SR_SRAM_DUMP_COMPLETE      = 7,
    SR_TCM_DUMP_COMPLETE       = 8,
    SR_P1_TABLE_DUMP_COMPLETE  = 9,
    SR_PASS1_COMPLETE          = 10,
    SR_TASKHIST_COMPLETE       = 11,
    SR_GICINTSTAT_COMPLETE     = 12,	

    SR_RAMDUMP_ENTRY           = 16,
    SR_MD_DDR_RDY_P2           = 17,
    SR_REGDUMP_COMPLETE        = 18,
    SR_SCANDUMP_COMPLETE       = 19,
    SR_DBGLOG_DUMP             = 20,
    SR_P2_TABLE_DUMP_COMPLETE  = 21,
    SR_P1_NOR_DUMP_TO_DDR_COMPLETE  = 22,
    SR_P1_TASKHIST_NOR_DUMP_TO_DDR_COMPLETE  = 23,
    SR_P1_GICINTSTAT_NOR_DUMP_TO_DDR_COMPLETE  = 24		
} SPARE_REG_BITPOSITION;

/*=========================================================================================================
**                          Function declarations                                                        **
=========================================================================================================*/

#endif /* _CRASHDBG_CFG_H_ */
