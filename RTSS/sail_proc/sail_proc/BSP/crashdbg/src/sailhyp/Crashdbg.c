/**********************************************************************************************************
** Copyright (c) 2021 Qualcomm Technologies, Inc.                                                        **
** All Rights Reserved.                                                                                  **
** Confidential and Proprietary - Qualcomm Technologies, Inc.                                            **
**********************************************************************************************************/

 /*========================================================================================================
    File Name          : Crashdbg.c
    Component Name     : SAIL CRASH DEBUG
    Description        : SAIL crash debug features are implemented in this file.
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/crashdbg/src/sailhyp/Crashdbg.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $
 ========================================================================================================*/

/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/
#include "HALhwio.h"
#include "sail_csr_hwio.h"
#include "saildbg_apb_sdc_hwio.h"
#include "saildbg_dcc_hwio.h"
#include "err_fatal.h"
#include "saildbg_hwio.h"
#include "cache_ops.h"
#include "pmicapi.h"
#include "Crashdbg.h"
#include "Crashdbg_cfg.h"
#include "Crashdbg_api.h"
#include "Crashdbg_dcc.h"
#include "Crashdbg_sdientry.h"
#include "isd.h"
#include "gpio.h"
#include "busywait.h"
#include "spinor_el2_api.h"
#include "common_functions.h"
#include "arm_acle.h"
#include "debug_log.h"
#include "chipinfo.h"
#include "sail_sec_dbg_policy.h"
#include "Clock.h"
#include "target.h"
#include "bist.h"

/*=========================================================================================================
**                                        Local defines and macros                                       **
=========================================================================================================*/
/* To check MD Reset FSM State and MD_PS_HOLD during SAIL Debug PASS phases */
#define PASS1_START 1
#define PASS1_END 2
#define PASS2_START 3
#define PASS2_END 4

/* Time value in ms to wait for MD_PS_HOLD assertion in PASS1, to de-isolate SAIL for any incorrect PSAIL_ERR_N */
#define MDPSHLD_ASSERT_WAIT_TIME 50

/* Timeout value in ms for DDR Ready from MD */
#define DDR_RDY_PASS1_TIMEOUT 1000
#define DDR_RDY_PASS2_TIMEOUT 10000
#define MD_PASS1_TIMEOUT      56*1000U //ms
#define MD_PASS2_DUMP_COPY_TIMEOUT      20*60*1000U // =20mins in ms

/* Offset of DCC SRAM - Linked list1 data address from where SAILSS register data is stored */
/* Note - Offset starts after DCC clock register data that is stored for read-modify-write operation of CLK_ENABLE of each register */
#define REGDUMP_START_OFFSET 0x18

/* Offset of DCC SRAM - Linked list0 data address from where SAILSS register data is stored */
/* Note - Offset starts after DCC clock register data that is stored for read-modify-write operation of CLK_ENABLE of each register */
#define SCANDUMP_START_OFFSET 0x18

/* CSR SPARE REG2 macros */
#define SPARE_REG_GET_BIT(pos)      ((HWIO_IN(SAILSS_CSR_SPARE_REG2)>>(pos))&(1U))
#define SPARE_REG_SET_BIT(pos)      HWIO_OUT(SAILSS_CSR_SPARE_REG2, HWIO_IN(SAILSS_CSR_SPARE_REG2) | (1U << (pos)))
#define SPARE_REG_READ_VAL()        HWIO_IN(SAILSS_CSR_SPARE_REG2)
#define COPY_SPARE_REG(dest_addr)   ((void)sailbsp_memscpy((void*)dest_addr, 4U, (void*)HWIO_ADDR(SAILSS_CSR_SPARE_REG2), 4U))


/*Pass1 DDR ready mask for spare register read */
#define MD_DDR_RDY_P1_MASK 0x20

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
==========================================================================================================*/
/* Crash debug configuration of sailss */
static const Saildbg_config_type Saildbg_config_data =
{
    /* SailSS Reset debug enable global flag */
    .sail_rst_dbg_en                = 1,
    /* Sail SS crash debug enablement */
    /* R52 Watchdog bite/reset debug enable */
    .wdog_rst_dbg_en                = 1,
    /* Sail Temperature sensor reset debug enable */
    .sail_tsense_rst_dbg_en         = 1,
    /* Sail PMIC Resin reset debug enable */
    .sail_pmic_resin_rst_dbg_en       = 1,
    /* Allow other reset debug enable */
    .allow_other_rst_dbg_en         = 1,
    /* Power sequencer watchdog reset debug enable */
    .pwrseq_wdog_rst_dbg_en         = 1,
    /* MD PMIC fault reset debug enable */
    .md_pmic_fault_rst_dbg_en         = 1,
    /* MD_PS_HOLD deassertion reset debug enable */
    .md_ps_hold_rst_dbg_en          = 1,
    /* Access reset first pass debug enable -
    to access control xPU/VMIDMT logic at the start of debug first pass */
    .acc_ctrl_rst_dbg_en            = 1,
    /* Crash debug overrides to dump debug data */
    /* Cache invalidation disable */
    .cache_inv_dis                  = 1,
    /* GPRs initialization disable */
    .reg_init_dis                   = 1,
    /* PASS1 Timer configuration */
    /* PASS1 Timer enable/disable */
    .sail_pass1_tmr_en              = 1,
    /* Timeout value in ms for sail to complete PASS1 */
    .sail_pass1_timeout             = MD_PASS1_TIMEOUT,//Note - configured timeout on MD = 55sec
    /* Abnormal Wakeup timeout to continue crash reset flow,
    when "crash_wakeup_seq_done" is not set by Crash wakeup sequencer in PASS0 */
    /*ToDO - All the time values shall be updated with values configured on Main Domain(MD) */
    .sail_abnwkup_timeout           = 32,
    /* Wakeup Timer enable/disable */
    .sail_wkup_tmr_en               = 1,
    /* Wind down Timer (ms) - For various blocks like Voltage Sensor Slave controller and DCC
    to wind down their operation and flush trace to ETB, as preparation step before reset occurs.
    Timeout modified as in MD to support IVI case. Time taken by LL1 is ~1ms.
    Note - 59 register reads approx. takes around 1ms.*/
    .wind_down_time                 = 8,
    /* Save Contents timer (ms) - Period for flushing trace to ETR or saving contents in local buffers
    as preparation step before reset occurs */
    .save_data_time                 = 8,
    /* Stop Capture timer (ms) - For asserting stop capture CTI signal in order to stop trace formatter */
    .stop_trace_time                = 8,
    /* Prepare for Reset timer (ms) - For asserting pre_ares signal to various blocks such as MPM */
    .prep_reset_time                = 10,
};

/* To indicate that SAIL is not in "FIRST_PASS_ST" FSM state during sdi entry */
static boolean sail_pass1_err_sts;

/* To save SAIL Reset Status */
static uint32_t sail_rst_sts;

static uint32_t Saildbg_regdump_values[SAILSS_REGDUMP_SIZE] = {0};

/* SAILSS Dump Data structure for each dump_type(Cache,log,SRAM etc) in Pass 1 */
static dump_table_type Sail_DumpTable_P1[] = {
    {SAIL_DUMP_TABLE_P1,     0x00, SAILDUMP_MAGIC_DEFAULT, {SAIL_DDR_DUMP_TBL_STARTADDR,     SAIL_SPINOR_DUMP_TBL_OFFSET},     SAIL_DDR_DUMP_TBL_SIZE},
    {SAIL_DATA_SRAM_DUMP,    0x00, SAILDUMP_MAGIC_DEFAULT, {SAIL_DDR_DUMP_SRAM_STARTADDR,    SAIL_SPINOR_OFFSET_UNDEFINED},    SAIL_DDR_DUMP_SRAM_SIZE},
    {SAIL_LOG_DUMP,          0x00, SAILDUMP_MAGIC_DEFAULT, {SAIL_DDR_DUMP_LOG_STARTADDR,     SAIL_SPINOR_DUMP_LOG_OFFSET},     SAIL_DDR_DUMP_LOG_SIZE},
    /* ToDO - Dumps that are skipped and based on debug policy flags shall be handled  with different values of magic or define
    an additional member in dump_table_type structure to identify the same  */
    {CPU_TCM_DUMP,           0x00, SAILDUMP_MAGIC_DEFAULT, {SAIL_DDR_DUMP_TCM_STARTADDR,     SAIL_SPINOR_OFFSET_UNDEFINED},     SAIL_DDR_DUMP_TCM_SIZE},
    {EL1_TASKHIST_DUMP,      0x00, SAILDUMP_MAGIC_DEFAULT, {SAIL_DDR_DUMP_TASKHISTORY_STARTADDR,     SAIL_SPINOR_DUMP_TASKHISTORY_OFFSET},     SAIL_DDR_DUMP_TASKHISTORY_SIZE},
    {SAIL_GICINTSTAT_DUMP,   0x00, SAILDUMP_MAGIC_DEFAULT, {SAIL_DDR_DUMP_GICINTSTAT_STARTADDR,     SAIL_SPINOR_DUMP_GICINTSTAT_OFFSET},     SAIL_DDR_DUMP_GICINTSTAT_SIZE},	
};

/* SAILSS Dump Data structure for each dump_type(scandump, critical registers etc) in Pass 2 */
static dump_table_type Sail_DumpTable_P2[] = {
    {SAIL_DUMP_TABLE_P2,     0x00, SAILDUMP_MAGIC_DEFAULT, {SAIL_DDR_DUMP_TBL_STARTADDR + sizeof(Sail_DumpTable_P1),
                                                            SAIL_SPINOR_DUMP_TBL_OFFSET + sizeof(Sail_DumpTable_P1)},          SAIL_DDR_DUMP_TBL_SIZE},
    {SAIL_DATA_APB_SCANDUMP, 0x00, SAILDUMP_MAGIC_DEFAULT, {SAIL_DDR_APB_SCANDUMP_STARTADDR, SAIL_SPINOR_APB_SCANDUMP_OFFSET}, SAIL_DDR_APB_SCANDUMP_SIZE},
    {SAIL_REG_DUMP,          0x00, SAILDUMP_MAGIC_DEFAULT, {SAIL_DDR_DUMP_REG_STARTADDR,     SAIL_SPINOR_DUMP_REG_OFFSET},     SAIL_DDR_DUMP_REG_SIZE},
    {SAIL_DBGLOG_DUMP,       0x00, SAILDUMP_MAGIC_DEFAULT, {SAIL_DDR_DUMP_DBGLOG_STARTADDR,  SAIL_SPINOR_DUMP_DBGLOG_OFFSET},  SAIL_DDR_DUMP_DBGLOG_SIZE}
};

/* dump data type with dump table row buffer and dump addresses and size.
Since it contains source dump address, it is used internally and not to be exposed in dumps */
typedef struct
{
    dump_table_type *dump_table_buf;         /* Pointer to dump table row */

    /* when using this type, address and size can be referred from below fields instead of dump_table_buf.
    Below address are updated based on hyp/non-hyp region dumps unlike dump_table_buf which always has full dump info. */
    uint32 dest_addr[SAILSS_DUMP_TYPE_MAX];  /* dump destination address */
    uint32 src_addr;                         /* dump source address */
    uint32 src_size;                         /* dump source size */
} dump_data_int;

/* Address table type to store source and destination addresses of full and non-hyp dumps */
typedef struct
{
    dump_type id;
    uint32 hyp_src_addr;
    uint32 hyp_src_size;
    uint32 nonhyp_dest_addr[SAILSS_DUMP_TYPE_MAX];
    uint32 nonhyp_src_addr;
    uint32 nonhyp_src_size;
} dump_addr_table;

/* List of dump items with separate regions for full dump and non-hypervisor dumps */
static const dump_addr_table Sail_DumpAddrTable[] = {
    {SAIL_LOG_DUMP,       SAIL_LOG_QUPRAM_STARTADDR,SAIL_QUPRAM_HYP_LOG_SIZE, {SAIL_DDR_DUMP_LOG_STARTADDR + SAIL_QUPRAM_HYP_LOG_SIZE, SAIL_SPINOR_DUMP_LOG_OFFSET + SAIL_QUPRAM_HYP_LOG_SIZE}, SAIL_QUPRAM_NON_HYP_STARTADDR, SAIL_QUPRAM_NON_HYP_SIZE},
    {SAIL_DATA_SRAM_DUMP, SAIL_SRAM_STARTADDR,SAIL_SRAM_HYP_SIZE,{SAIL_DDR_DUMP_SRAM_STARTADDR + SAIL_SRAM_HYP_SIZE,      SAIL_SPINOR_OFFSET_UNDEFINED},      SAIL_SRAM_NON_HYP_STARTADDR,   SAIL_SRAM_NON_HYP_SIZE},
};

/*=========================================================================================================
**                          Internal Functions                                                            **
==========================================================================================================*/
static void Crashdbg_Enable(const Saildbg_config_type* dbg_cfg);
static void Crashdbg_ClockInitColdboot(void);
static void Crashdbg_pass1_DumpComplete(void);
static boolean Crashdbg_pass2_dump_R52Scandumpdata(spinor_handle_t handle, Saildumpmemtype dumpdst, uint32 dump_start_addr);
dump_table_type *Crashdbg_GetDumpTableBuffer(dump_type id);
void Crashdbg_pass1_dumptoFlash(void);
void Crashdbg_pass1_dumptoDDR(void);
static boolean Crashdbg_pass1_dump_cache(spinor_handle_t handle, Saildumpmemtype dumpdst,
                                         uintptr_t *buffer, SaildbgL1cachetype cache_type);
static void Crashdbg_pass1_DDRDumpStarted(void);
static boolean Crashdbg_WaitforDDRReady(void);
static boolean Crashdbg_WaitforMD(uint8_t phase);
static boolean Crashdbg_pass2_dump_CritDbgRegData(spinor_handle_t handle, Saildumpmemtype dumpdst, uint32 dump_start_addr);
static boolean Crashdbg_pass1_dump_tcmData(spinor_handle_t handle, Saildumpmemtype dumpdst, uint32 dump_start_addr);
void Crashdbg_pass1_sdi(void);
static void Crashdbg_pass1_ClockInit(void);
static void Crashdbg_validate_saildump(spinor_handle_t handle, uint32 region_offset, Saildumpmemtype dumpdst);
void Crashdbg_pass2_dumptoFlash(void);
static void Crashdbg_pass2_DumpComplete(void);
void Crashdbg_pass2_dumptoDDR(void);
static void Crashdbg_pass2_ClockInit(void);
void Crashdbg_pass1_busywait_ms(uint32 delay_ms);
static void Crashdbg_dumpFmtTable(spinor_handle_t handle, uint32 region_offset,uint32 partition_size, Saildumpmemtype dumpdst, dump_type id);
void Crashdbg_pass2_ReadFromFlash(void);
static boolean Crashdbg_pass1_dump_log_sram(spinor_handle_t handle,uint32 byte_offset,uint32 partition_size, Saildumpmemtype dumpdst, dump_table_type *dump_table_buf, dump_addr_table * dump_addr_buf);
dump_addr_table *Crashdbg_GetDumpAddrTableBuffer(dump_type id);
/*=========================================================================================================
**                          External Functions                                                            **
==========================================================================================================*/
//extern int spinorEl2Init(int type);
extern void icb_early_noc_config(void);

/*=========================================================================================================
**                          Function Definitions                                                          **
==========================================================================================================*/
/*===========================================================================
**  Function :  Crashdbg_Enable
** ==========================================================================
*/
/*!
*
* @brief : Crash debug enablement at cold boot
* @param : dbg_cfg [in] - SAIL sub system debug configuration
* @Dependencies : Initialize crash debug only when SAIL reset debug flag(sail_rst_dbg_en) is enabled
* @retval : None
* @Side Effects : None
*
*/
static void Crashdbg_Enable(const Saildbg_config_type* dbg_cfg)
{
    uint32_t cfg_data = 0;

    /* To enable various error events that can initiate crash reset flow */
    if (dbg_cfg->wdog_rst_dbg_en)
        cfg_data |= HWIO_FMSK(SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE, R52_WDOG_RESET_DEBUG_EN);
    if (dbg_cfg->sail_tsense_rst_dbg_en)
        cfg_data |= HWIO_FMSK(SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE, SAIL_TSENSE_RESET_DEBUG_EN);

    /* ALLOW_OTHER_RST_DBG_EN is enabled together with PMIC_RESIN_RESET_DEBUG_EN bit, to allow SW write to PS_HOLD as crash reset, in case of SW based errors */
    if (dbg_cfg->allow_other_rst_dbg_en)
        cfg_data |= ( HWIO_FMSK(SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE, PMIC_RESIN_RESET_DEBUG_EN) |
                      HWIO_FMSK(SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE, ALLOW_OTHER_RST_DBG_EN) );
    else if (dbg_cfg->sail_pmic_resin_rst_dbg_en)
        cfg_data |= HWIO_FMSK(SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE, PMIC_RESIN_RESET_DEBUG_EN);

    if (dbg_cfg->pwrseq_wdog_rst_dbg_en)
        cfg_data |= HWIO_FMSK(SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE, PWR_SEQ_WDOG_RST_DEBUG_EN);
    if (dbg_cfg->md_pmic_fault_rst_dbg_en)
        cfg_data |= HWIO_FMSK(SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE, MD_PMIC_FAULT_RST_DEBUG_EN);
    if (dbg_cfg->md_ps_hold_rst_dbg_en)
    {
        cfg_data |= HWIO_FMSK(SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE, MD_PS_HOLD_RST_DEBUG_EN);
        /* Unmask MD_PS_HOLD to allow concurrent crash flow upon MD fatal error detection
         i.e allow SAIL PS HOLD de-assertion upon MD_PS_HOLD de-assertion */
        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK, FSM_STATE_MASK, 0xCFF8);
    }
    else
    {
        /* Mask MD_PS_HOLD in all SAIL RESET CTRL FSM States.
        This is a SW workaround to avoid SAIL PS HOLD de-assertion upon MD_PS_HOLD de-assertion,
        though MD_PS_HOLD Reset debug is disabled */
        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK, FSM_STATE_MASK, 0xFFFF);
    }

    if (dbg_cfg->acc_ctrl_rst_dbg_en)
        cfg_data |= HWIO_FMSK(SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE, ACCESS_RESET_FIRST_PASS_EN);

    /* Setting this bit ensures that clocks are gated before PASS2 reset is asserted and thereby,
    clock to memories doesn't glitch during PASS2 reset phase. Reference - SAILSS_CC HPG */
    cfg_data |= HWIO_FMSK(SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE, FUNC_CLK_DIS_IN_SP_EN);

    /* Configure all above necessary debug enablement */
    HWIO_OUTM(SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE, cfg_data, cfg_data);

    /* Clear the reset status register */
    HWIO_OUT(SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS, HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_RMSK);
}

/*===========================================================================
**  Function :  Crashdbg_ClockInitColdboot
** ==========================================================================
*/
/*!
*
* @brief : Crash debug Clock init at cold boot
* @param : None
* @Dependencies : None
* @retval : None
* @Side Effects : None
*
*/
static void Crashdbg_ClockInitColdboot(void)
{
    /* Enable all necessary clocks to access and initialize DCC at cold boot */
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR, CLK_ENABLE, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR, CLK_ENABLE, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR, CLK_ENABLE, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_APB_CBCR, CLK_ENABLE, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR, CLK_ENABLE, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR, CLK_ENABLE, 0x1);
    /* QDSS XO clock is needed for DCC to execute any LL programmed
    in DCC SRAM - PASS0(LL1 - wind down HW trigger) and PASS1 (LL0 - scan dump HW trigger) */
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR, CLK_ENABLE, 0x1);
}

/*===========================================================================
**  Function :  Crashdbg_Init
** ==========================================================================
*/
/*!
*
* @brief : Crash debug enablement and other necessary configuration at cold boot
* @param : None
* @Dependencies : None
* @retval : Crashdbg_Result [out] - DBG_DISABLED = 0x2, DBG_FAILED = 0x1, DBG_SUCCESS = 0x0
* @Side Effects : None
*
*/
Crashdbg_Result Crashdbg_Init(void)
{
    const Saildbg_config_type* dbg_cfg = &Saildbg_config_data;
    uint32_t reg_val;
    uint32_t sdi_entry_addr;
    uint32_t ret = PMIC_ERR_FLAG_SUCCESS;
    boolean is_sec_dp_flag_en = FALSE;
    boolean is_nonsec_dp_flag_en = FALSE;

    /* Return Crash debug status as "Failed" when config data is NULL */
    if(!dbg_cfg)
        return (DBG_FAILED);

    is_sec_dp_flag_en = secdbg_dp_is_flag_enabled(SECDBG_ENABLE_SAIL_SECURE_CRASH_DUMPS);
    is_nonsec_dp_flag_en = secdbg_dp_is_flag_enabled(SECDBG_ENABLE_SAIL_NONSECURE_CRASH_DUMPS);

    /* Do not initialize crash debug when SAIL reset debug flag is disabled or when both security flags are disbaled */
    if (!(dbg_cfg->sail_rst_dbg_en) || (!is_sec_dp_flag_en && !is_nonsec_dp_flag_en))
    {
        DEBUG_LOG( SAIL_WARNING,"SAILSS crash debug disabled\r\n" );
        return (DBG_DISABLED);
    }
    if (is_sec_dp_flag_en) SPARE_REG_SET_BIT(SR_FULL_DUMP_ENABLED);

    /* 1 - Clock Init at Cold boot */
    Crashdbg_ClockInitColdboot();

    /* 2 - Enable various debug events that can initiate crash debug flow */
    /* This will initialize the Sail RESET FSM CTRL in HW,
    so that FSM CTRL will move to the right states upon crash events  */
    Crashdbg_Enable(dbg_cfg);

    /* 3 - Enable PASS1 timer and configure timeout value */
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_TIMEOUT, TIMER_VAL, CONVERT_TO_CYCLES(dbg_cfg->sail_pass1_timeout, SAILSS_CC_XO_CLOCK_HZ));
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL, FIRST_PASS_TMR_EN, dbg_cfg->sail_pass1_tmr_en);

    /* 4 - Workaround in SW - Enable System Wakeup for successful RESET CTRL state transition in PASS0 */
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL, SYS_WKUP_WO_AOP_EN, 0x1);

    /* 5 - Configure abnormal wakeup timeout value and Enable Wakeup timer  */
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ABNORM_WKUP_TIMEOUT, TIMER_VAL, CONVERT_TO_CYCLES(dbg_cfg->sail_abnwkup_timeout, SAILSS_CC_XO_CLOCK_HZ));
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL, WKUP_TMR_EN, dbg_cfg->sail_wkup_tmr_en);

    /* 6 - Enable PASS1 timer and configure timeout value */
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_WIND_DOWN_TIMER, TIMER_VAL, CONVERT_TO_CYCLES(dbg_cfg->wind_down_time, SAILSS_CC_SLEEP_CLOCK_HZ));
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SAVE_CONTENTS_TIMER, TIMER_VAL, CONVERT_TO_CYCLES(dbg_cfg->save_data_time, SAILSS_CC_SLEEP_CLOCK_HZ));
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_STOP_CAPTURE_TIMER, TIMER_VAL, CONVERT_TO_CYCLES(dbg_cfg->stop_trace_time, SAILSS_CC_SLEEP_CLOCK_HZ));
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_PREPARE_FOR_RESET_TIMER, TIMER_VAL, CONVERT_TO_CYCLES(dbg_cfg->prep_reset_time, SAILSS_CC_SLEEP_CLOCK_HZ));

    /* 7 - Configure vector table for SDI entry during PASS1.
     First instruction to be executed in SDI must be in ARM Code.
     Also initialize Stack pointer before executing SDI */
    void (*funcptr) (void) = sdiinit_sp;
    sdi_entry_addr = (uint32)(funcptr) >> 5;
    HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0, CFGVECTABLE, sdi_entry_addr); /* LSR by 5,as CFGVECTABLE field = bit[26:0] */

    /* 8 - DCC Init to program the Linked List in DCC SRAM for scan dump execution in PASS0*/
    if(FALSE == CrashdbgDCCInit())
    {
        DEBUG_LOG(SAIL_WARNING, "SAILSS crash debug DCC init failed\r\n");
        return DBG_FAILED;
    }

    /* 9 - Configure SAIL pmic for crash reset PASS0 */
    if(TRUE == bSailPmicPresent())
    {
        /* Configure SAIL PMIC only for ADAS - Independent PMIC case */
        ret = xPmicSetResetState(PMIC_CRASH_PASS_0);
		if (PMIC_ERR_FLAG_SUCCESS != ret)
		{
			DEBUG_LOG(SAIL_WARNING, "SAILSS crash debug PMIC set reset state failed\r\n");
			return DBG_FAILED;
		}
    }

    *crashdbg_init_status_ptr = (uint32_t)CRASHDBG_INIT_SUCCESS;
    DEBUG_LOG( SAIL_WARNING,"SAILSS crash debug init completed \r\n" );
    return (DBG_SUCCESS);
}

/*===========================================================================
**  Function :  Crashdbg_pass1_DumpComplete
** ==========================================================================
*/
/*!
*
* @brief : In PASS1, Inform MD that SAIL dump is complete and waiting for MD to complete PASS1.
* @param : None
* @Dependencies :
* @retval : None
* @Side Effects : None
*
*/
static void Crashdbg_pass1_DumpComplete(void)
{
    /* Inform MD that SAIL_PASS1_COMPLETE 0xAB000001 and SAIL is waiting for MD to complete PASS1 */
    /* a) This is for debug purpose on SAIL side, in case SAIL couldnt't set FIRST_PASSS_COMPLETE due to this wait
       b) This shall be check on MD side, before de-asserting MD_PS_HOLD to avoid NOC hangs during SAIL DDR dump in PASS1 */
    HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG, 0xAB);
    HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG, 0x00);
    HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG, 0x00);
    HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG, 0x01);
}

/*===========================================================================
**  Function :  Crashdbg_GetDumpTableBuffer
** ==========================================================================
*/
/*!
*
* @brief : Get DDR start_addr and len of each dump data type.
* @param : None
* @Dependencies : None
* @retval : None
* @Side Effects : None
*
*/
dump_table_type *Crashdbg_GetDumpTableBuffer(dump_type id)
{
    dump_table_type *buffer = NULL;
    uint8 rows = 0U;
    uint8 i = 0U;

    /* sanity check on dump_type id */
    if (SAIL_MAX_DUMP > id)
    {
        /* Check if id is present in pass1 table */
        rows = SIZEOF_ARRAY(Sail_DumpTable_P1);
        for (i = 0; i < rows; i++)
        {
            if (Sail_DumpTable_P1[i].id == id)
            {
                buffer = &Sail_DumpTable_P1[i];
                break;
            }
        }

        /* This condition passes if above for loop didn't hit break. Pass2 table is checked */
        if (i >= rows)
        {
            for (i = 0; i < SIZEOF_ARRAY(Sail_DumpTable_P2); i++)
            {
                if (Sail_DumpTable_P2[i].id == id)
                {
                    buffer = &Sail_DumpTable_P2[i];
                    break;
                }
            }
        }
    }

    return buffer;
}
/*===========================================================================
**  Function :  Crashdbg_GetDumpAddrTableBuffer
** ==========================================================================
*/
/*!
*
* @brief : Get address table buffer containg dump source addresses mapped to destination addresses .
* @param : Dump id 
* @Dependencies : None
* @retval : Address table
* @Side Effects : None
*
*/
dump_addr_table *Crashdbg_GetDumpAddrTableBuffer(dump_type id)
{
    dump_addr_table *dump_addr_buf = NULL;
    uint8 i = 0U;

    if (SAIL_MAX_DUMP > id)
    {
        /* Get required addresses and copy size from address table */
        for (i = 0; i < SIZEOF_ARRAY(Sail_DumpAddrTable); i++)
        {
            if (Sail_DumpAddrTable[i].id == id)
            {
                dump_addr_buf = (dump_addr_table*)&Sail_DumpAddrTable[i];
                break;
            }
        }
    }

    return dump_addr_buf;
}

/*===========================================================================
**  Function :  Crashdbg_pass1_dump_log_sram
** ==========================================================================
*/
/*!
*
* @brief : Dumps qupram and sram dumps
* @param : handle [in] NULL i.e not valid in case of DDR dump or Valid SPINOR handle to dump in SAIL NOR flash
* @param : dumpdst [in] DDR or NOR flash to store SAILSS register data
* @param : buffer [in] pointer to dump table 
* @param : buffer [in] pointer to dump address table 
* @Dependencies : Crashdbg_GetDumpTableBuffer() and Crashdbg_GetDumpAddrTableBuffer()
* @retval : status [out] FALSE if logdump /sram dump collection fails
* @Side Effects : None
*
*/
static boolean Crashdbg_pass1_dump_log_sram(spinor_handle_t handle,uint32 byte_offset,uint32 partition_size, Saildumpmemtype dumpdst, dump_table_type *dump_table_buf, dump_addr_table * dump_addr_buf)
{

    boolean status = FALSE;
    boolean is_nonhyp = (FALSE == secdbg_dp_is_flag_enabled(SECDBG_ENABLE_SAIL_SECURE_CRASH_DUMPS));
    uint32_t dest_addr_offset = 0u;
    size_t copied_size = 0U;
    uint32 start_byte = 0;
    SPINOR_STATUS result;

    if(NULL == dump_table_buf || NULL == dump_addr_buf)
    {
        return status;
    }
    /* Based on destination, either copy to DDR or SAIL NOR flash */
    if (dumpdst == SAILSS_DDR)
    {
      if( (dump_table_buf->start_addr[SAILSS_DDR] >= byte_offset) && //byte_offset for DDR = SAIL_DDR_DUMP_STARTADDR
          (dump_table_buf->start_addr[SAILSS_DDR] + dump_table_buf->len) < (byte_offset + partition_size))
      {
        if(0 == is_nonhyp)
        {
            copied_size = sailbsp_memscpy((void*)dump_table_buf->start_addr[SAILSS_DDR]+dest_addr_offset, dump_addr_buf->hyp_src_size,
                                        (void*)dump_addr_buf->hyp_src_addr, dump_addr_buf->hyp_src_size);
            if(copied_size < dump_addr_buf->hyp_src_size)
            {
                return status;
            }
        }
        
        dest_addr_offset = dump_addr_buf->hyp_src_size;

        copied_size = sailbsp_memscpy((void*)dump_table_buf->start_addr[SAILSS_DDR]+dest_addr_offset, dump_addr_buf->nonhyp_src_size,
                                    (void*)dump_addr_buf->nonhyp_src_addr, dump_addr_buf->nonhyp_src_size);
        if(copied_size < dump_addr_buf->nonhyp_src_size)
    {
        return status;
    }
        else
        {
            status = TRUE;
        }
      }
    }
    else if (dumpdst == SAILSS_NORFLASH)
    {
        /* Actual start address of SAIL registers dump in SPINOR RAM dump 5MB partition */
        start_byte = byte_offset + dump_table_buf->start_addr[SAILSS_NORFLASH]+dest_addr_offset;
        if((start_byte+dump_table_buf->len) < (byte_offset+partition_size))
        {

        result = spinorEl2Erase(handle, SPINOR_BLOCK_COUNT(start_byte), SPINOR_BLOCK_COUNT(dump_table_buf->len));
        if (result == SPINOR_DEVICE_DONE)
    {
            if(0 == is_nonhyp)
        {
                result = spinorEl2Write(handle, start_byte, dump_addr_buf->hyp_src_size, (void *)(dump_addr_buf->hyp_src_addr));
                if(SPINOR_DEVICE_DONE != result)
            {
                    return status;
            }
        }

            dest_addr_offset = dump_addr_buf->hyp_src_size;
            start_byte = byte_offset + dump_table_buf->start_addr[SAILSS_NORFLASH]+dest_addr_offset;

            result = spinorEl2Write(handle, start_byte, dump_addr_buf->nonhyp_src_size, (void *)(dump_addr_buf->nonhyp_src_addr));
            if(SPINOR_DEVICE_DONE != result)
            {
                return status;
            }
            else
            {
            status = TRUE;
        }
          }
        }
    }

return (status);
}

/*===========================================================================
**  Function :  Crashdbg_rd_imp_cdbgdr1
** ==========================================================================
*/
/*!
*
* @brief : Read cache DATA RAM from Cache Debug Data Register 1
* @param : None
* @Dependencies :
* @retval : regval [out] Value of IMP_CDBGDR1 register
* @Side Effects : None
*
*/
static inline uint32_t Crashdbg_rd_imp_cdbgdr1(void)
{
    uint32 regval;

    //IMP_CDBGDR1 - Cache Debug Data Register 1
    regval = __arm_mrc(15, 3, 15, 0, 1);
    return (regval);
}

/*===========================================================================
**  Function :  Crashdbg_rd_imp_cdbgdr0
** ==========================================================================
*/
/*!
*
* @brief : Read cache TAG RAM or DATA RAM from Cache Debug Data Register 0
* @param : None
* @Dependencies :
* @retval : regval [out] Value of IMP_CDBGDR0 register
* @Side Effects : None
*
*/
static inline uint32_t Crashdbg_rd_imp_cdbgdr0(void)
{
    uint32 regval;

    //IMP_CDBGDR0 - Cache Debug Data Register 0
    regval = __arm_mrc(15, 3, 15, 0, 0);
    return (regval);
}

/*===========================================================================
**  Function :  Crashdbg_wr_imp_cdbgicd
** ==========================================================================
*/
/*!
*
* @brief : Select Instruction cache Data way/set index/data offset using IMP_CDBGICD register
* @param : icache_encodedata [in] value to be written
* @Dependencies :
* @retval : None
* @Side Effects : None
*
*/
static inline void Crashdbg_wr_imp_cdbgicd(uint32 icache_encodedata)
{
    //IMP_CDBGICD - Instruction Cache Data Read Operation Register
    __arm_mcr(15, 3, icache_encodedata, 15, 4, 1);
}

/*===========================================================================
**  Function :  Crashdbg_wr_imp_cdbgdcd
** ==========================================================================
*/
/*!
*
* @brief : Select Data cache Data way/set index/data offset using IMP_CDBGDCD register
* @param : dcache_encodedata [in] value to be written
* @Dependencies :
* @retval : None
* @Side Effects : None
*
*/
static inline void Crashdbg_wr_imp_cdbgdcd(uint32 dcache_encodedata)
{
    //IMP_CDBGDCD - Data Cache Data Read Operation Register
    __arm_mcr(15, 3, dcache_encodedata, 15, 4, 0);
}

/*===========================================================================
**  Function :  Crashdbg_wr_imp_cdbgict
** ==========================================================================
*/
/*!
*
* @brief : Select Instruction cache Tag way/set index using IMP_CDBGICT register
* @param : icache_encodetag [in] value to be written
* @Dependencies :
* @retval : None
* @Side Effects : None
*
*/
static inline void Crashdbg_wr_imp_cdbgict(uint32 icache_encodetag)
{
    //IMP_CDBGICT - Instruction Cache Tag Read Operation Register
    __arm_mcr(15, 3, icache_encodetag, 15, 2, 1);
}

/*===========================================================================
**  Function :  Crashdbg_wr_imp_cdbgdct
** ==========================================================================
*/
/*!
*
* @brief : Select Data cache Tag way/set index/data offset using IMP_CDBGDCT register
* @param : dcache_encodetag [in] value to be written
* @Dependencies :
* @retval : None
* @Side Effects : None
*
*/
static inline void Crashdbg_wr_imp_cdbgdct(uint32 dcache_encodetag)
{
    //IMP_CDBGDCT - Data Cache Tag Read Operation Register
    __arm_mcr(15, 3, dcache_encodetag, 15, 2, 0);
}

/*===========================================================================
**  Function :  Crashdbg_pass1_wr_cache_opreg
** ==========================================================================
*/
/*!
*
* @brief : Select Cache Tag or Data Read Operation Register to read Tag or Data RAM, respectively.
* @param : cache_type [in] cache type (Icache or Dcache)
* @param : rd_dataRAM [in] TRUE-Select Data RAM, FALSE-Select Tag RAM
* @param : value [in] value to be written
* @Dependencies :
* @retval : None
* @Side Effects : None
*
*/
static void Crashdbg_pass1_wr_cache_opreg(SaildbgL1cachetype cache_type, boolean rd_dataRAM, uint32 val)
{
    switch(cache_type)
    {
      case SAILSS_L1_DCACHE://Data cache
        if (rd_dataRAM == TRUE)
          Crashdbg_wr_imp_cdbgdcd(val);//Dcache Data Operation Register
        else
          Crashdbg_wr_imp_cdbgdct(val);//Dcache Tag Operation Register
        break;

      case SAILSS_L1_ICACHE://Instruction cache
        if(rd_dataRAM == TRUE)
          Crashdbg_wr_imp_cdbgicd(val);//Icache Data Operation Register
        else
          Crashdbg_wr_imp_cdbgict(val);//Icache Tag Operation Register
        break;

      default:
        break;
    }
}
/*===========================================================================
**  Function :  Crashdbg_pass1_dump_cache
** ==========================================================================
*/
/*!
*
* @brief : Dump cache content into predefined memory(DDR or SPINOR) location in PASS1
* @param : handle [in] NULL i.e not valid in case of DDR dump or Valid SPINOR handle to dump in SAIL NOR flash
* @param : dumpdst [in] DDR or NOR flash to store SAILSS register data
* @param : buffer [in] DDR or NOR flash Start Address to store SAILSS register data
* @param : cache_type [in] cache type (Icache or Dcache)
* @Dependencies : to be called with a valid spinor handle, when destination is SPINOR.
* @retval : status [out] FALSE - Dump Failed, TRUE - Dump Success
* @Side Effects : None
*
*/
static boolean Crashdbg_pass1_dump_cache(spinor_handle_t handle, Saildumpmemtype dumpdst,
                                         uintptr_t *buffer, SaildbgL1cachetype cache_type)
{
    uint32 num_sets, num_ways;
    uint32 tag_offset, data_offset, offset;
    uint8 dump_tag_data, fill_bufcnt = 0;
    uint32 write_val;
    boolean status = FALSE;
    boolean rd_dataRAM = FALSE;
    uint32 tmp_databuf[SAIL_SPINOR_PAGESIZE_IN_WORDS]={0};
    size_t copied_size = 0U;
    uint32 addr_offset;
    SPINOR_STATUS spinor_result;

    if (buffer)
    {
      /* 1 - Get Info about "Number of Sets"(Index) and
      "Associativity"(Number of Ways) */
      num_sets = R52_CCSIDR_NUMSETS + 1;
      num_ways = R52_CCSIDR_NUMWAYS + 1;

      /* 2 - Get Offset i.e length to encode all data and Tag in a cache line.
        a)TAG RAM length is 1 word per cache line(23 Tag bits including 1 valid bit).
        b)DATA RAM length is 16words per cache line.
          Formula:log(Offset in bytes) = (linesize + 4); logbase=2
          Note- Convert Data offset in double words, as we read double-word at a time
          via Cache Debug Data Register0 and Cache Debug Data Register1 */
      tag_offset = R52_CACHE_TAGOFFS_INWORDS;
      data_offset = R52_CACHE_DATAOFFS_INDWORDS;

      /* 4 - Dump TAG RAM first and then DATA RAM */
      dump_tag_data = 2; //2:Read Tag RAM, 1:Read Data RAM of selected cache_type
      while(dump_tag_data)
      {
        if(dump_tag_data == 2)
        {
          offset = tag_offset;//1 Tag word per cache line
          addr_offset = 0;    //To dump Tag RAM at the start of DDR/SPINOR memory for CPU_L1_xCACHE_DUMP type
          rd_dataRAM = FALSE; //To read only Cache Debug Data Register0
        }
        else
        {
          offset = data_offset;//8 double word Data per cache line
          rd_dataRAM = TRUE; //To read both Cache Debug Data Register 0 and 1
        }

        for (uint32 i = 0; i < num_ways; i++)
        {
          for (uint32 j = 0; j < num_sets; j++)
          {
            for (uint32 k = 0; k < offset; k++)
            {
                /* 5 - Build the write value to encode each cache line/set/way
                NOTE - Tag RAM and Data RAM location encoding is same
                for both Instruction and Data cache,w.r.t ARM R52 manual */
                write_val = 0;
                write_val |= (k << R52_IMP_CDBGxCD_BITSHFT_DATAOFFS);
                write_val |= (j << R52_IMP_CDBGxCD_BITSHFT_SETINDEX);
                write_val |= (i << R52_IMP_CDBGxCD_BITSHFT_WAY);

                /* 6 - Write into Cache Tag Read Operation Register to read Tag RAM
                OR Cache Data Read Operation Register to read Data RAM */
                Crashdbg_pass1_wr_cache_opreg(cache_type, rd_dataRAM, write_val);

                /* 7 - Read data from Cache Debug Data Register0 and Register1
                a) Tag RAM - 23bits per line; bit22-Valid bit,21:0-Tag bits;
                  Hence read only from Register0.
                b) DATA RAM - double-word data can be read at a time */
                if (fill_bufcnt < SAIL_SPINOR_PAGESIZE_IN_WORDS)
                {
                  tmp_databuf[fill_bufcnt] = Crashdbg_rd_imp_cdbgdr0();
                  if (rd_dataRAM == TRUE)
                  {
                    if ((fill_bufcnt + 1) < SAIL_SPINOR_PAGESIZE_IN_WORDS)
                      tmp_databuf[fill_bufcnt+1] = Crashdbg_rd_imp_cdbgdr1();
                    fill_bufcnt+=2;
                  }
                  else
                  {
                    fill_bufcnt+=1;
                  }
                  /* 8 - Fill 64 words(256 bytes)in the buffer before dump.
                   This will help to speed up SPINOR-write time by page-write(256bytes),
                   when DDR isn't available from MD. No such limitations in DDR.
                  IMPORTANT NOTE - Both Tag(2KB) and Data(32KB) size in I/Dcache are multiples of 64words.
                  Hence, no leftover data in the buffer(<64 words),when we read the last cache "Way" */
                  if(fill_bufcnt == SAIL_SPINOR_PAGESIZE_IN_WORDS)
                  {
                    /* 9 - Copy data into DDR or SPINOR */
                    if(dumpdst == SAILSS_DDR)
                    {
                      /* Copy cache Tag RAM and Data RAM into DDR */
                      copied_size = sailbsp_memscpy((void *)(uintptr_t)(buffer + addr_offset), sizeof(tmp_databuf),
                                                    (void *)(uintptr_t)(tmp_databuf), sizeof(tmp_databuf));
                      addr_offset += SAIL_SPINOR_PAGESIZE_IN_WORDS;
                      status = (copied_size == sizeof(tmp_databuf));
                    }
                    else if ((SAILSS_NORFLASH == dumpdst) && handle)
                    {
                        spinor_result = spinorEl2Write(handle, (uint32)(buffer + addr_offset), sizeof(tmp_databuf), (void*)(uintptr_t)tmp_databuf);
                        if (SPINOR_DEVICE_DONE != spinor_result)
                        {
                            while(1);
                        }
                        status = TRUE;
                    }
                    else
                    {
                        /* Invalid dump destination memory */
                    }
                    fill_bufcnt = 0;
                  }
                }
            }//loop - Offset
          }//loop - Sets
        }//loop - Ways
        dump_tag_data--;
      }//while loop
    }
    return (status);
}

/*===========================================================================
**  Function :  Crashdbg_pass2_ReadFromFlash
** ==========================================================================
*/
/*!
*
* @brief : Read Pass1 spinor dump data from flash
* @param : None
* @Dependencies :
* @retval : None
* @Side Effects : None
*
*/
void Crashdbg_pass2_ReadFromFlash(void)
{
    spinor_handle_t handle = NULL;
    SPINOR_STATUS result;
    uint32 start_byte = 0;
    uint32 byte_offset = 0;
    uint32 partition_size = 0;
    spinorMemInfoType mem_info;
    dump_table_type *dump_table_buf = NULL;
    dump_addr_table *dump_addr_buf = NULL;
    boolean is_only_nonhyp = (FALSE == secdbg_dp_is_flag_enabled(SECDBG_ENABLE_SAIL_SECURE_CRASH_DUMPS));
    uint32_t dest_addr_offset = 0u;

    /* Spinor init for ram dump */
    result = spinorEl2Init(SPINOR_INIT_TYPE_RAM_DUMP, NULL);
    if (result != SPINOR_DEVICE_DONE)
    {
      goto exit;
    }
	
    /* Register a handle for client/crash debug user to use SPINOR services in EL2 */
    result = spinorEl2Open(&handle, SPINOR_USER_TYPE_CRASH_DBG);
    if (result != SPINOR_DEVICE_DONE)
    {
      goto deinit;
    }

    /* To get info about block size, Page size and number of blocks */
    result = spinorEl2GetMemInfo(handle, &mem_info);
    if (result != SPINOR_DEVICE_DONE)
    {
      goto close_handle;
    }

    /* Get GPT info about partition start address and size allocated for ram dump/client/crash debug user */
    result = spinorEl2GetGptPartitionInfo(handle, SAIL_SPINOR_GUID, &byte_offset, &partition_size);
    if (result != SPINOR_DEVICE_DONE)
    {
      goto close_handle;
    }

    /* From above partition info, byte_offset=Start address of SAIL RAM DUMP parition as per SPINOR partition xml
       and partition_size = 0x00500000  i.e 5MB, the total size reserved for SAIL RAM DUMP.
       Note - Same DDR macro "SAIL_DDR_DUMP_SIZE" is used for size allocation check in SPINOR */
    if(partition_size < SAIL_DDR_DUMP_SIZE && (mem_info.pages_per_block * mem_info.page_size_bytes) != SAIL_SPINOR_BLKSIZE)
    {
		DEBUG_LOG(SAIL_ERROR, "[CRASHDBG] SPINOR spinor memory allocation mismatch\r\n");
        while(1); //To trap spinor memory allocation mismatch
    }

    /* NOTE - MAKE SURE SAIL IS NOT IN ISLAND MODE AND QUP RAM clock is enabled */
    /* Dump SAIL log data from spinor to DDR */
    
    dump_table_buf = Crashdbg_GetDumpTableBuffer(SAIL_LOG_DUMP);
    dump_addr_buf = Crashdbg_GetDumpAddrTableBuffer(SAIL_LOG_DUMP);
    if(NULL != dump_table_buf && NULL !=dump_addr_buf)
    {
    if(FALSE == is_only_nonhyp)
    {
        start_byte = byte_offset + dump_table_buf->start_addr[SAILSS_NORFLASH]+dest_addr_offset;
        result = spinorEl2Read(handle, start_byte, dump_addr_buf->hyp_src_size,( (void *)(dump_table_buf->start_addr[SAILSS_DDR])+dest_addr_offset));
        if (SPINOR_DEVICE_DONE != result)
        {
            DEBUG_LOG(SAIL_ERROR, "[CRASHDBG] SPINOR log dump data restore to DDR failed\r\n");
        }
    }

    dest_addr_offset = (size_t)dump_addr_buf->hyp_src_size;
    /* If full dumps has to be collected , then dump non hyp dumps as well */
	start_byte = byte_offset + dump_table_buf->start_addr[SAILSS_NORFLASH]+dest_addr_offset;;
    result = spinorEl2Read(handle, start_byte, dump_addr_buf->nonhyp_src_size,( (void *)(dump_table_buf->start_addr[SAILSS_DDR])+dest_addr_offset));
    if (SPINOR_DEVICE_DONE != result)
    {
        DEBUG_LOG(SAIL_ERROR, "[CRASHDBG] SPINOR log dump data restore to DDR failed\r\n");
    }

    }
    dump_table_buf = Crashdbg_GetDumpTableBuffer(EL1_TASKHIST_DUMP);
    if(dump_table_buf)
    {
        /* Actual start address of SAIL EL1 task history dump in SPINOR -SAIL_RAM_DUMP 5MB partition */
        start_byte = byte_offset + dump_table_buf->start_addr[SAILSS_NORFLASH];
        result = spinorEl2Read(handle, start_byte, dump_table_buf->len, (void *)(dump_table_buf->start_addr[SAILSS_DDR]));
        if (SPINOR_DEVICE_DONE != result)
        {
            DEBUG_LOG(SAIL_ERROR, "[CRASHDBG] SPINOR task history data restore to DDR failed\r\n");
        }			
		SPARE_REG_SET_BIT(SR_P1_TASKHIST_NOR_DUMP_TO_DDR_COMPLETE);	
    }

    dump_table_buf = Crashdbg_GetDumpTableBuffer(SAIL_GICINTSTAT_DUMP);
    if(dump_table_buf)
    {
        start_byte = byte_offset + dump_table_buf->start_addr[SAILSS_NORFLASH];
        result = spinorEl2Read(handle, start_byte, dump_table_buf->len, (void *)(dump_table_buf->start_addr[SAILSS_DDR]));
        if (SPINOR_DEVICE_DONE != result)
        {
            DEBUG_LOG(SAIL_ERROR, "[CRASHDBG] SPINOR GIC register dump data restore to DDR failed\r\n");
        }			
		SPARE_REG_SET_BIT(SR_P1_GICINTSTAT_NOR_DUMP_TO_DDR_COMPLETE);	
    }
    close_handle:
        /* Close the handle */
        result = spinorEl2Close(handle);
        if (result != SPINOR_DEVICE_DONE)
        {
          /* ToDO - log the error */
        }
    deinit:
        /* DeInitialize SPINOR driver in EL2 */
        spinorEl2DeInit(SPINOR_INIT_TYPE_RAM_DUMP);
    exit:
        return;

}
/*===========================================================================
**  Function :  Crashdbg_pass1_dumptoFlash
** ==========================================================================
*/
/*!
*
* @brief : Dump crash debug data into Sail Flash
* @param : None
* @Dependencies :
* @retval : None
* @Side Effects : None
*
*/
void Crashdbg_pass1_dumptoFlash(void)
{
    spinor_handle_t handle = NULL;
    uint32 partition_size = 0;
    spinorMemInfoType mem_info;
    dump_table_type *dump_table_buf = NULL;
    dump_addr_table *dump_addr_buf = NULL;
    boolean status = FALSE;
    SPINOR_STATUS result;
    uint32 byte_offset = 0;
    uint32 start_byte = 0;	

    /* Spinor init for ram dump */
    result = spinorEl2Init(SPINOR_INIT_TYPE_RAM_DUMP, NULL);
    if (result != SPINOR_DEVICE_DONE)
    {
      goto exit;
    }

    /* Register a handle for client/crash debug user to use SPINOR services in EL2 */
    result = spinorEl2Open(&handle, SPINOR_USER_TYPE_CRASH_DBG);
    if (result != SPINOR_DEVICE_DONE)
    {
      goto deinit;
    }

    /* To get info about block size, Page size and number of blocks */
    result = spinorEl2GetMemInfo(handle, &mem_info);
    if (result != SPINOR_DEVICE_DONE)
    {
      goto close_handle;
    }

    /* Get GPT info about partition start address and size allocated for ram dump/client/crash debug user */
    result = spinorEl2GetGptPartitionInfo(handle, SAIL_SPINOR_GUID, &byte_offset, &partition_size);
    if (result != SPINOR_DEVICE_DONE)
    {
      goto close_handle;
    }

    /* From above partition info, byte_offset=Start address of SAIL RAM DUMP parition as per SPINOR partition xml
       and partition_size = 0x00500000  i.e 5MB, the total size reserved for SAIL RAM DUMP.
       Note - Same DDR macro "SAIL_DDR_DUMP_SIZE" is used for size allocation check in SPINOR */
    if(partition_size < SAIL_DDR_DUMP_SIZE && (mem_info.pages_per_block * mem_info.page_size_bytes) != SAIL_SPINOR_BLKSIZE)
    {
        while(1); //To trap spinor memory allocation mismatch
    }

    dump_table_buf = Crashdbg_GetDumpTableBuffer(SAIL_LOG_DUMP);
    dump_addr_buf = Crashdbg_GetDumpAddrTableBuffer(SAIL_LOG_DUMP);
    if((NULL != dump_table_buf) && (dump_table_buf->magic != SAILDUMP_MAGIC_SUCCESS))
    {
        status = Crashdbg_pass1_dump_log_sram(handle,byte_offset,partition_size, SAILSS_NORFLASH, dump_table_buf ,dump_addr_buf ); 
       
        if(! status)
        {
            dump_table_buf->magic = SAILDUMP_MAGIC_FAILURE;
        }
        else
        {
            /* Update magic and version after succesful dump */
            dump_table_buf->magic = SAILDUMP_MAGIC_SUCCESS;
            dump_table_buf->version = LOG_DUMP_FORMAT_VERSION;
            SPARE_REG_SET_BIT(SR_LOG_DUMP_COMPLETE);
        }
    }

	/* TASK HISTORY */
    dump_table_buf = Crashdbg_GetDumpTableBuffer(EL1_TASKHIST_DUMP);
    if(dump_table_buf)
    {
        if (dump_table_buf->magic != SAILDUMP_MAGIC_SUCCESS)
        {
            /* Actual start address of SAIL EL1 task history dump in SPINOR -SAIL_RAM_DUMP 5MB partition */
            start_byte = byte_offset + dump_table_buf->start_addr[SAILSS_NORFLASH];
            result = spinorEl2Erase(handle, SPINOR_BLOCK_COUNT(start_byte), SPINOR_BLOCK_COUNT(dump_table_buf->len));
            if (result == SPINOR_DEVICE_DONE)
            {
                result = spinorEl2Write(handle, start_byte, dump_table_buf->len, (void *)(SAIL_SRAM_EL1TASKHIST_STARTADDR));
                if (SPINOR_DEVICE_DONE != result)
                {
                    dump_table_buf->magic = SAILDUMP_MAGIC_FAILURE;
                }
                else
                {
                    /* Update magic and version after succesful dump */
                    dump_table_buf->magic = SAILDUMP_MAGIC_SUCCESS;
                    dump_table_buf->version = TCM_DUMP_FORMAT_VERSION;
                    SPARE_REG_SET_BIT(SR_TASKHIST_COMPLETE);
                }
            }
        }
    }

	/* GICINTSTAT */
    dump_table_buf = Crashdbg_GetDumpTableBuffer(SAIL_GICINTSTAT_DUMP);
    if(dump_table_buf)
    {
        if (dump_table_buf->magic != SAILDUMP_MAGIC_SUCCESS)
        {
            /* Actual start address of SAIL EL1 task history dump in SPINOR -SAIL_RAM_DUMP 5MB partition */
            start_byte = byte_offset + dump_table_buf->start_addr[SAILSS_NORFLASH];
            result = spinorEl2Erase(handle, SPINOR_BLOCK_COUNT(start_byte), SPINOR_BLOCK_COUNT(dump_table_buf->len));
            if (result == SPINOR_DEVICE_DONE)
            {
                result = spinorEl2Write(handle, start_byte, dump_table_buf->len, (void *)(SAIL_SRAM_GICINTSTAT_STARTADDR));
                if (SPINOR_DEVICE_DONE != result)
                {
                    dump_table_buf->magic = SAILDUMP_MAGIC_FAILURE;
                }
                else
                {
                    /* Update magic and version after succesful dump */
                    dump_table_buf->magic = SAILDUMP_MAGIC_SUCCESS;
                    dump_table_buf->version = TCM_DUMP_FORMAT_VERSION;
                    SPARE_REG_SET_BIT(SR_GICINTSTAT_COMPLETE);
                }
            }
        }
    }
    /* After dumping all other regions, dump Sail_DumpTable_P1 variable */
    Crashdbg_dumpFmtTable(handle, byte_offset,partition_size, SAILSS_NORFLASH, SAIL_DUMP_TABLE_P1);
    SPARE_REG_SET_BIT(SR_P1_TABLE_DUMP_COMPLETE);

close_handle:
    /* Close the handle */
    result = spinorEl2Close(handle);
    if (result != SPINOR_DEVICE_DONE)
    {
      /* ToDO - log the error */
    }
deinit:
    /* DeInitialize SPINOR driver in EL2 */
    spinorEl2DeInit(SPINOR_INIT_TYPE_RAM_DUMP);
exit:
    return;
}

/*===========================================================================
**  Function :  Crashdbg_pass1_dumptoDDR
** ==========================================================================
*/
/*!
*
* @brief : Dump crash debug data into DDR - SAIL region
* @param : None
* @Dependencies : Make sure that DDR from MD is ready before dump
* @retval : None
* @Side Effects : None
*
*/
void Crashdbg_pass1_dumptoDDR(void)
{
    dump_table_type *dump_table_buf = NULL;
    dump_addr_table *dump_addr_buf = NULL;
    boolean status = FALSE;
    size_t copied_size = 0U;	

    /* NOTE - MAKE SURE SAIL IS NOT IN ISLAND MODE AND QUP RAM clock is enabled */
    /* Dump SAIL log data from QUP RAM into DDR */
    dump_table_buf = Crashdbg_GetDumpTableBuffer(SAIL_LOG_DUMP);
    dump_addr_buf = Crashdbg_GetDumpAddrTableBuffer(SAIL_LOG_DUMP);
    if((NULL != dump_table_buf) && (dump_table_buf->magic != SAILDUMP_MAGIC_SUCCESS))
    {
        status = Crashdbg_pass1_dump_log_sram(NULL, SAIL_DDR_DUMP_STARTADDR, SAIL_DDR_DUMP_SIZE, SAILSS_DDR, dump_table_buf,dump_addr_buf );
        if(! status)
        {
            dump_table_buf->magic = SAILDUMP_MAGIC_FAILURE;
        }
        else
        {
            /* Update magic and version after succesful dump */
            dump_table_buf->magic = SAILDUMP_MAGIC_SUCCESS;
            dump_table_buf->version = LOG_DUMP_FORMAT_VERSION;
            SPARE_REG_SET_BIT(SR_LOG_DUMP_COMPLETE);
        }
    }

    /* Dump SAIL SRAM data into DDR */
    dump_table_buf = Crashdbg_GetDumpTableBuffer(SAIL_DATA_SRAM_DUMP);
    dump_addr_buf = Crashdbg_GetDumpAddrTableBuffer(SAIL_DATA_SRAM_DUMP);
    if((NULL != dump_table_buf) && (dump_table_buf->magic != SAILDUMP_MAGIC_SUCCESS))
    {
    status = Crashdbg_pass1_dump_log_sram(NULL, SAIL_DDR_DUMP_STARTADDR, SAIL_DDR_DUMP_SIZE, SAILSS_DDR, dump_table_buf, dump_addr_buf ); 
       
    if(! status)
    {
        dump_table_buf->magic = SAILDUMP_MAGIC_FAILURE;
    }
    else
    {
        /* Update magic and version after succesful dump */
        dump_table_buf->magic = SAILDUMP_MAGIC_SUCCESS;
        dump_table_buf->version = SRAM_DUMP_FORMAT_VERSION;
        SPARE_REG_SET_BIT(SR_SRAM_DUMP_COMPLETE);
    }
    }

    /* Dump A, B & C TCMs of Core 0,1 & 2 into DDR */
    dump_table_buf = Crashdbg_GetDumpTableBuffer(CPU_TCM_DUMP);
    if(dump_table_buf)
    {
        if (dump_table_buf->magic != SAILDUMP_MAGIC_SUCCESS)
        {
          if( (dump_table_buf->start_addr[SAILSS_DDR] >= SAIL_DDR_DUMP_STARTADDR) &&
              (dump_table_buf->start_addr[SAILSS_DDR] + dump_table_buf->len) < (SAIL_DDR_DUMP_STARTADDR + SAIL_DDR_DUMP_SIZE))
          {            
            status = Crashdbg_pass1_dump_tcmData(NULL, SAILSS_DDR, dump_table_buf->start_addr[SAILSS_DDR]);
            if (FALSE == status)
            {
                dump_table_buf->magic = SAILDUMP_MAGIC_FAILURE;
            }
            else
            {
                /* Update magic and version after succesful dump */
                dump_table_buf->magic = SAILDUMP_MAGIC_SUCCESS;
                dump_table_buf->version = TCM_DUMP_FORMAT_VERSION;
                SPARE_REG_SET_BIT(SR_TCM_DUMP_COMPLETE);
            }
        }
    }
    }

 /* Dump SAIL SRAM TASK HISTORY into DDR */
     dump_table_buf = Crashdbg_GetDumpTableBuffer(EL1_TASKHIST_DUMP);
    if(dump_table_buf)
    {
        if (dump_table_buf->magic != SAILDUMP_MAGIC_SUCCESS)
        {
		copied_size = sailbsp_memscpy((void*)dump_table_buf->start_addr[SAILSS_DDR], dump_table_buf->len,
									(void*)SAIL_SRAM_EL1TASKHIST_STARTADDR, dump_table_buf->len);
            if(copied_size < dump_table_buf->len)
            {
                dump_table_buf->magic = SAILDUMP_MAGIC_FAILURE;
            }
            else
            {
                /* Update magic and version after succesful dump */
                dump_table_buf->magic = SAILDUMP_MAGIC_SUCCESS;
                dump_table_buf->version = TCM_DUMP_FORMAT_VERSION;
                SPARE_REG_SET_BIT(SR_TASKHIST_COMPLETE);
            }
        }
    }
	
 /* Dump SAIL SRAM GICINTSTAT into DDR */
     dump_table_buf = Crashdbg_GetDumpTableBuffer(SAIL_GICINTSTAT_DUMP);
    if(dump_table_buf)
    {
        if (dump_table_buf->magic != SAILDUMP_MAGIC_SUCCESS)
        {
		copied_size = sailbsp_memscpy((void*)dump_table_buf->start_addr[SAILSS_DDR], dump_table_buf->len,
									(void*)SAIL_SRAM_GICINTSTAT_STARTADDR, dump_table_buf->len);
            if(copied_size < dump_table_buf->len)
            {
                dump_table_buf->magic = SAILDUMP_MAGIC_FAILURE;
            }
            else
            {
                /* Update magic and version after succesful dump */
                dump_table_buf->magic = SAILDUMP_MAGIC_SUCCESS;
                dump_table_buf->version = TCM_DUMP_FORMAT_VERSION;
                SPARE_REG_SET_BIT(SR_GICINTSTAT_COMPLETE);
            }
        }
    }

    /* Dump Sail_DumpTable_P1 data into DDR */
    Crashdbg_dumpFmtTable(NULL, SAIL_DDR_DUMP_STARTADDR, SAIL_DDR_DUMP_SIZE, SAILSS_DDR, SAIL_DUMP_TABLE_P1);
    SPARE_REG_SET_BIT(SR_P1_TABLE_DUMP_COMPLETE);
}

/*===========================================================================
**  Function :  Crashdbg_pass1_DDRDumpStarted
** ==========================================================================
*/
/*!
*
* @brief : In PASS1, Inform MD that SAIL has started DDR dump in PASS1. Only for debug purpose.
* @param : None
* @Dependencies :
* @retval : None
* @Side Effects : None
*
*/
static void Crashdbg_pass1_DDRDumpStarted(void)
{
    /* Inform MD that SAIL has started DDR dump in PASS1 - SAIL_PASS1_STARTED 0xAB000000. No action needed from MD. */
    /* This is only for debug purpose to notify current status of SAIL DDR dump */
    HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG, 0xAB);
    HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG, 0x00);
    HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG, 0x00);
    HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG, 0x00);
}

/*===========================================================================
**  Function :  Crashdbg_WaitforDDRReady
** ==========================================================================
*/
/*!
*
* @brief : Check for MD DDR Ready/DDR out of self refresh before cache flush and DDR dump, in PASS1 and 2 respectively.
* @param : None
* @Dependencies :
* @retval : ddr_rdy_sts [out] TRUE - DDR Ready; FALSE - DDR not available
* @Side Effects : None
*
*/
static boolean Crashdbg_WaitforDDRReady(void)
{
    boolean ddr_rdy_sts = FALSE; /* DDR not available */

    /* Read DDR Ready Status from MD */
    if ( (HWIO_IN(SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS7_REG) == 0xCC) &&
         (HWIO_IN(SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS6_REG) == 0x01) &&
         (HWIO_IN(SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS5_REG) == 0x00) &&
         (HWIO_IN(SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS4_REG) == 0x00)
       )
    {
        /* DDR Ready */
        ddr_rdy_sts = TRUE;
    }
    return(ddr_rdy_sts);
}

/*===========================================================================
**  Function :  Crashdbg_WaitforMD
** ==========================================================================
*/
/*!
*
* @brief : Check MD Reset FSM State and MD_PS_HOLD Status
* @param : phase [in] To check MD status in Pass1 or Pass2 phase
* @param : timeout_ms [in] wait for till given timeout, 0xFFFF for infinite wait
* @Dependencies :
* @retval : ret_md_crashdbg [out] Status that indicate MD in crash debug or not
* @Side Effects : None
*
*/
static boolean Crashdbg_WaitforMD(uint8_t phase)
{
    uint16_t md_rst_fsm_st;
    uint32_t time_elapsed = 0U;
    uint32_t md_ps_hold_raw_sts;
    boolean ret_md_crashdbg;
    boolean wait_forever = FALSE;

    switch (phase)
    {
        case PASS1_START:
            /* Allow "PASS1_START" at the start of SAIL PASS1 */
            /* Read MD RESET FSM state */
            md_rst_fsm_st = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_MD_RESET_FSM_STATUS, FSM_STATE);

            /* When MD also goes through crash reset flow, check for exact MD Reset FSM state */
            if ( ((md_rst_fsm_st >= BLOCK_RESIN_ST) &&  (md_rst_fsm_st <= ALLOW_RESIN_SECOND_PASS_ST)) ||
                 (md_rst_fsm_st == ABNORM_BRINGUP_IN_DBG_ST)  ||
                 ((md_rst_fsm_st >= SP_PRE_DDR_INIT_ST) &&  (md_rst_fsm_st <= ALLOW_PRE_ARES_PCIE_LINK_CHK_ST)) )
            {
                /* When SAIL crashes, MD should also crash. In normal case, MD will be in PASS1 and no wait needed here */
                /* To handle error case, when MD is in PASS0, SAIL can wait for MD to complete PASS0 or reach PASS1 */
                while ( ((md_rst_fsm_st >= BLOCK_RESIN_ST) &&  (md_rst_fsm_st <= ALLOW_RESIN_FIRST_PASS_ST)) ||
                        (md_rst_fsm_st == ABNORM_BRINGUP_IN_DBG_ST) )
                {
                    md_rst_fsm_st = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_MD_RESET_FSM_STATUS, FSM_STATE);
                }

                /* When MD is in PASS1 or PASS2, return "MD in crashdbg" status as TRUE */
                /* MD in PASS2 is possible here, in case of independent crash flow.  Example- SAIL crashes when MD is in PASS2 */
                ret_md_crashdbg = TRUE;
            }
            else
            {
                /* When MD is stuck or not in crash debug flow, return "MD in crashdbg" status as FALSE */
                ret_md_crashdbg = FALSE;
            }
            break;
        case PASS1_END:
            /* Allow "PASS1_END" only when ret_md_crashdbg was "1" in "PASS1_START" */
            /* Read MD RESET FSM state at the end of SAIL PASS1 */
            md_rst_fsm_st = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_MD_RESET_FSM_STATUS, FSM_STATE);

            /* If  MD still executing it's PASS1 SW operations, wait for MD_PS_HOLD de-assertion */
            if (md_rst_fsm_st == FIRST_PASS_ST)
            {
                /* Poll for MD_PS_HOLD Low */
                do
                {
                    /* Infinite wait until MD de-asserts MD_PS_HOLD */
                    md_ps_hold_raw_sts = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS, MD_PS_HOLD_RAW_STATUS);
                } while(md_ps_hold_raw_sts);
            }
            else
            {
                /* When MD completes PASS1 first and now is in PASS2, don't wait. End SAIL PASS1 */
            }

            ret_md_crashdbg = TRUE; /* MD stays in crash debug */
            break;
        case PASS2_START:
            /* Allow "PASS2_START" at the start of SAIL PASS2 */
            /* Read MD RESET FSM state */
            md_rst_fsm_st = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_MD_RESET_FSM_STATUS, FSM_STATE);

            /* When MD also goes through crash reset flow, check for exact MD Reset FSM state */
            if ( ((md_rst_fsm_st >= BLOCK_RESIN_ST) &&  (md_rst_fsm_st <= ALLOW_RESIN_SECOND_PASS_ST)) ||
                 (md_rst_fsm_st == ABNORM_BRINGUP_IN_DBG_ST)  ||
                 ((md_rst_fsm_st >= SP_PRE_DDR_INIT_ST) &&  (md_rst_fsm_st <= ALLOW_PRE_ARES_PCIE_LINK_CHK_ST)) )
            {
                /* When SAIL crashes, MD should also crash. In normal case, MD will be in PASS2 and no wait needed for MD */
                /* To handle error case,  SAIL can wait for MD to reach PASS2 if FSM is not in PASS2 */
                while ( ((md_rst_fsm_st >= BLOCK_RESIN_ST) &&  (md_rst_fsm_st <= ALLOW_RESIN_FIRST_PASS_ST)) ||
                        (md_rst_fsm_st == ABNORM_BRINGUP_IN_DBG_ST) ||
                        (md_rst_fsm_st == FIRST_PASS_ST) )
                {
                    /* Infinite wait until MD completes PASS0/1 -  ABNORMAL CASE */
                    md_rst_fsm_st = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_MD_RESET_FSM_STATUS, FSM_STATE);
                }
                /* When MD is in PASS2, return "MD in crashdbg" status as TRUE */
                ret_md_crashdbg = TRUE;
            }
            else
            {
                /* MD is stuck or not in crash debug flow. Dump the SAIL debug data into Flash */
                ret_md_crashdbg = FALSE;
            }
            break;
        case PASS2_END:
            wait_forever = SPARE_REG_GET_BIT(SR_MD_DDR_RDY_P2);
            /* Allow "PASS2_END" only when ret_md_crashdbg was "1" in "PASS2_START" */
            /* Poll for MD_PS_HOLD Low and MD FSM IDLE_ST */
            do
            {
                /* busywait for 1ms i.e min. wait time between PS HOLD RAW status read.
                Note: MD FSM STATE can't be checked for IDLE, as MD PASS2 sets "second pass complete" bit
                 as soon as MD loads RAMDUMP Image */
                busywait(1000);
                md_ps_hold_raw_sts = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS, MD_PS_HOLD_RAW_STATUS);
                if (!wait_forever)
                {
                    time_elapsed++;
                }
            } while((md_ps_hold_raw_sts) && (time_elapsed < MD_PASS2_DUMP_COPY_TIMEOUT));
            ret_md_crashdbg = TRUE; /* MD just completed crash debug or in PASS2 phase */
            break;
        default:
            ret_md_crashdbg = FALSE;
            break;
    }

    return(ret_md_crashdbg);
}

/*===========================================================================
**  Function :  Crashdbg_pass1_sdi
** ==========================================================================
*/
/*!
*
* @brief : System Debug Image (SDI) or PASS1 debug phase
* @param : None
* @Dependencies : Execute SDI only when SAIL reset debug flag(sail_rst_dbg_en) is enabled
* @retval : None - SAIL will get reset upon PASS1 completion
* @Side Effects : None
*
*/
void Crashdbg_pass1_sdi(void)
{
    boolean ddr_rdy_sts = FALSE;
    boolean md_in_crashdbg = FALSE;
    uint16_t delay_counter = 0U;
    uint16_t pass1_waittime = 0U;
    uint16_t sail_rst_fsm_st;
    uint32_t mdpshld_rawsts = 0U;

    /* Read FSM state */
    sail_rst_fsm_st = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS, FSM_STATE);

    /* When SAIL is in PASS1 FSM state, continue SDI flow */
    if (sail_rst_fsm_st == FIRST_PASS_ST)
    {
        /* Read SAIL Reset Status to save it in SRAM */
        sail_rst_sts = HWIO_IN(SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS);

        /* SW workaround to enable SAIL PASS1 DDR dump in SoC V1 HW. 
        SoC V1 HW Issue: 
          With GPIO63-PSAIL_ERR enabled via "SAILSS_TLMM_SAILSS_TLMM_WEST_MPM_WAKEUP_INT_EN_1" register at cold boot,
          false PSAIL_ERR/MD_PMIC_FAULT was set and SAIL got isolated, when the above TLMM register gets cleared during PASS1 reset phase.
          This will lead to SAIL PASS1 dump into NOR flash, instead of DDR, though there is no actual PSAIL_ERR.
          Hence in SoC R2, as HW fix, POR value of GPIO63 in above TLMM is set to 0x1.
        SW WA for V1:
          To support SAIL DDR dump in PASS1, SAIL shall be de-isolated upon MD_PS_HOLD assertion and continue with DDR Ready check */
        /* NOTE - In V1, When we monitor SAIL_PS_HOLD and MD_PS_HOLD signals during PASS0-PASS1 resets,
           MD is entering PASS0 and PASS1 ~5ms approx. before SAIL.*/
        /* NOTE - In R2 HW, external 1.8V pull up on PSAIL_ERR_N GPIO is not supported in HW.
           During SAIL PASS1 reset phase, PSAIL_ERR_N is pulled low which lead to SAIL isolation in SDI.
           To support SAIL PASS1 dump into DDR, enable weak pull up on PSAIL_ERR GPIO in SDI and
           de-isolate SAIL based on MD_PS_HOLD raw status */
        do
        {
            /* busy wait time of 1ms between MD_PS_HOLD raw status check */
            Crashdbg_pass1_busywait_ms(1);
            mdpshld_rawsts = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS, MD_PS_HOLD_RAW_STATUS);
            pass1_waittime++;
        } while ((mdpshld_rawsts == 0x1) && (pass1_waittime <= MDPSHLD_ASSERT_WAIT_TIME));
		
        if (mdpshld_rawsts == 0x1)
        {
           eISDDisableIsolations();
        }
        /* Clear it to reuse for DDR ready wait */
        pass1_waittime = 0U;
 
        /* Check MD crash debug status based on MD Reset FSM state */
        md_in_crashdbg = Crashdbg_WaitforMD(PASS1_START);

        /* Note - Make sure SAIL is not in Island mode before DDR dump */
        /* Enable NOC to allow access to SAIL DDR */
        icb_early_noc_config();

        /* Is DDR available within timeout */
        do
        {
            /* busy wait time of 1ms between DDR Ready Status check from MD */
            Crashdbg_pass1_busywait_ms(1);
            /* Read DDR Ready status from MD->SAIL shadow register*/
            ddr_rdy_sts = Crashdbg_WaitforDDRReady();
            pass1_waittime++;
        } while ((!ddr_rdy_sts) && (pass1_waittime <= DDR_RDY_PASS1_TIMEOUT));

        /* Check for DDR Ready */
        if (ddr_rdy_sts)
        {
            SPARE_REG_SET_BIT(SR_MD_DDR_RDY_P1);
            /* Notify MD that SAIL DDR dump has started */
            Crashdbg_pass1_DDRDumpStarted();
            /* Dump cache, SAIL SRAM and SAIL log data into DDR */
            Crashdbg_pass1_dumptoDDR();

            /* Copy CSR SPARE REG value to DDR */
            COPY_SPARE_REG(SAIL_DDR_CRASHDBG_STATUS_ADDR);
        }
        else
        {
            // Dump to SPINOR once OSPI controller is intact after PASS1 reset phase in HW, which is currently not supported.
            Crashdbg_pass1_dumptoFlash();
        }

        /* Set PASS1 Dump complete via shadow register to inform MD
        and now SAIL is waiting for MD to complete PASS1 */
        Crashdbg_pass1_DumpComplete();

        /* When MD is also in crash debug flow, check MD reset FSM status and wait for MD_PS_HOLD de-assertion,if needed */
        if (md_in_crashdbg)
            md_in_crashdbg = Crashdbg_WaitforMD(PASS1_END); /* MD stays in crash debug */

#ifdef RUMI // ToDo- To be removed later after it gets resolved in HW.
        uint32_t pass2_entry_addr;
        pass2_entry_addr = (uint32)(0x0) >> 5;
        // Set to Boot ROM. For RUMI testing, use el2_vector_entry to test without pbl i.e (0x08000000) >> 5;
        HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0, CFGVECTABLE, pass2_entry_addr);
#endif

        /* Set SAIL PASS1 complete */
        SPARE_REG_SET_BIT(SR_PASS1_COMPLETE);
        /* SAIL2MD_PS_HOLD and SAIL_PS_HOLD will be automatically pulled low by HW
        and SAIL will go through PASS2 reset phase */
        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL, FIRST_PASS_COMPLETE, 0x1);
    }
    else
    {
        /* It should never reach here. stay in loop */
        /* Save the pass1 error status in SRAM */
        /* ToDO - Log Error info */
        sail_pass1_err_sts = 1;
        while(1);
    }
}

/*===========================================================================
**  Function :  Crashdbg_pass1_ClockInit
** ==========================================================================
*/
/*!
*
* @brief : Crash debug Clock init in PASS1
* @param : None
* @Dependencies : None
* @retval : None
* @Side Effects : None
*
*/
static void Crashdbg_pass1_ClockInit(void)
{
    /* Enable QUPRAM clock to dump log data */
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR, CLK_ENABLE, 0x1);

    /* Enable SYS TSC clock */
    HWIO_OUTF(SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR, EN, 0x1);

    /* Enable QSPI clocks for SPINOR driver */
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR, CLK_ENABLE, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR, CLK_ENABLE, 0x1);

    /* Power up cluster 1 and bring cores 1 & 2 out of reset */
    Clock_DeassertCoreReset(1);
    Clock_DeassertClusterReset(1);
    Clock_DeassertCoreReset(2);
}

/*===========================================================================
**  Function :  Crashdbg_pass1_vPSailPinConfig
** ==========================================================================
*/
/*!
*
* @brief : Enable weak pull up on PSAIL_ERR_N GPIO in PASS1
* @param : None
* @Dependencies : chip info driver to be intact in SDI.
* @retval : None
* @Side Effects : None
*
*/
static void Crashdbg_pass1_vPSailPinConfig(void)
{
  const uint32_t ngpio_LeMans[] = {63u, 66u};
  const uint32_t ngpio_Monaco[] = {52u, 55u};
  const GPIOConfigType cfg[] = {
                                  {
                                    .func=   0u,
                                    .dir =   GPIO_IN,
                                    .pull =  GPIO_PU,
                                    .drive = GPIO_2MA
                                  },
                                  {
                                    .func=   1u,
                                    .dir =   GPIO_OUT,
                                    .pull =  GPIO_NP,
                                    .drive = GPIO_2MA
                                  }
                             };
                             
#if defined(monaco)
  sail_gpio_config_group(&ngpio_Monaco[0], &cfg[0], (sizeof(ngpio_Monaco)/sizeof(ngpio_Monaco[0])));
#else
  sail_gpio_config_group(&ngpio_LeMans[0], &cfg[0], (sizeof(ngpio_LeMans)/sizeof(ngpio_LeMans[0])));
#endif
}

/*===========================================================================
**  Function :  Crashdbg_pass1_sdi_entry
** ==========================================================================
*/
/*!
*
* @brief : Crash debug - SDI Entry in PASS1
* @param : None
* @Dependencies :
* @retval : None - SAIL will get reset upon PASS1 completion
* @Side Effects : None
*
*/
void Crashdbg_pass1_sdi_entry(void)
{
    /* update SDI entry status in spare reg */
    SPARE_REG_SET_BIT(SR_SDI_ENTRY);
 
    /* Mask MD_PS_HOLD in all SAIL RESET CTRL FSM - Crash debug States.
     a) to avoid SAIL PS HOLD de-assertion upon MD_PS_HOLD de-assertion at the end of PASS1 and
     b) to avoid multiple PASS2 reset phases due to MD_PS_HOLD */
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK, FSM_STATE_MASK, 0xFFF8);

    /* Enable required clocks for PASS1 */
    Crashdbg_pass1_ClockInit();

    /* Initialize gpio & busywait modules which are required for SPINOR in PASS1 */
    sail_gpio_init();
    busywait_init();
    /* Enable weak pull up on PSAIL_ERR_N GPIO */
    Crashdbg_pass1_vPSailPinConfig();
    /* Execute SDI flow */
    Crashdbg_pass1_sdi();

    /* Setting PASS1 complete bit, in the above SDI flow, will de-assert SAIL PS HOLD
    and SAIL will go through PASS2 reset phase. Hence, it shouldn't reach here */
    while(1);
}

/*===========================================================================
**  Function :  Crashdbg_pass2_DumpComplete
** ==========================================================================
*/
/*!
*
* @brief : In PASS2, Write the status fom SAIL to MD as "DDR Dump complete"
* @param : None
* @Dependencies :
* @retval : None
* @Side Effects : None
*
*/
static void Crashdbg_pass2_DumpComplete(void)
{
    /*  Write DDR Dump complete status */
    HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG, 0xAB);
    HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG, 0x01);
    HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG, 0x00);
    HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG, 0x00);
}

/*===========================================================================
**  Function :  Crashdbg_validate_saildump
** ==========================================================================
*/
/*!
*
* @brief : Validate whether all SAIL memory dump in PASS1-PASS2 are successful or not, based on magic number stored for each dump.
* @param : spinor handle if destination is spinor
* @param : spinor ramdump region offset if destination is spinor
* @param : dump destination - DDR or NOR flash
* @Dependencies : This function should be called only when dump destination(DDR or SPINOR) is known and FmtTable dump is complete.
* @retval : None
* @Side Effects : None
*
*/
static void Crashdbg_validate_saildump(spinor_handle_t handle, uint32 region_offset, Saildumpmemtype dumpdst)
{
    size_t sail_dumptable_size = 0U;
    uint8 sail_dumptable_entries = 0U;
    dump_table_type *sail_dumptable_ptr = NULL;
    dump_table_entrytype *sail_memdumpentry_ptr = NULL;
    boolean memdump_fail_flag = FALSE;
    uint8 spinordump_read_buf[240];
    dump_table_type *sail_memdump_data = NULL;
    uint32 start_byte = 0U;
    SPINOR_STATUS spinor_result;

    /* PASS1 and PASS2 SAIL Dump table can be read from DDR/SPINOR as single block of memory,
    as both are dumped into same SAIL_x_DUMP_TBL_y memory block, where x = DDR or SPINOR
    and y = STARTADDR or OFFSET respectively.
    SAIL_x_DUMP_TBL_y has Sail_DumpTable_P1 data first,followed by Sail_DumpTable_P2 */

    /* Get SAIL Dump table info for PASS1 */
    sail_dumptable_ptr = Crashdbg_GetDumpTableBuffer(SAIL_DUMP_TABLE_P1);
    if (!sail_dumptable_ptr)
    {
        DEBUG_LOG(SAIL_WARNING, "SAILSS dump validation buf invalid\r\n");
        goto exit;
    }
    /* Calc SAIL Dump table size and number of entries for both PASS1 and PASS2 */
    sail_dumptable_size = sizeof(Sail_DumpTable_P1) + sizeof(Sail_DumpTable_P2);
    sail_dumptable_entries = (uint8)(sail_dumptable_size / sizeof(Sail_DumpTable_P1[0]));

    if (SAILSS_DDR == dumpdst)
    {
        /* Get DDR start address of SAIL_DDR_DUMP_TBL_y memory block */
        sail_memdumpentry_ptr = (dump_table_entrytype *)sail_dumptable_ptr->start_addr[SAILSS_DDR];
        goto validate;
    }
    else if ((SAILSS_NORFLASH == dumpdst) && handle)
    {
        /* Calc actual start address of SAIL_SPINOR_DUMP_TBL_y memory block with the right offset,
        from SPINOR RAM dump 5MB partition */
        start_byte = region_offset + sail_dumptable_ptr->start_addr[SAILSS_NORFLASH];

        /* Validation possible only when read buffer can hold both PASS1 and PASS2 SAIL Dump table size */
        if (sizeof(spinordump_read_buf) < sail_dumptable_size)
        {
            DEBUG_LOG(SAIL_WARNING, "SAILSS dump validation rdbuf mem insufficient\r\n");
            goto exit;
        }

        /* Read PASS1 and PASS2 SAIL Dump table data from SPINOR  */
        spinor_result = spinorEl2Read(handle, start_byte, sail_dumptable_size, spinordump_read_buf);
        if (SPINOR_DEVICE_DONE != spinor_result)
        {
            DEBUG_LOG(SAIL_WARNING, "SAILSS dump validation from spinor failed\r\n");
            goto exit;
        }
        else
        {
            /* SPINOR read complete.
            Access spinor read buffer in dump_table_entrytype format */
            sail_memdumpentry_ptr = (dump_table_entrytype *)spinordump_read_buf;
        }
    }
    else
    {
        DEBUG_LOG(SAIL_WARNING, "SAILSS dump destination mem invalid\r\n");
        goto exit;
    }

validate:
    if (sail_memdumpentry_ptr)
    {
        for (uint8 i_entry = 0; i_entry < sail_dumptable_entries; i_entry++)
        {
            /* To access magic number of each entry i.e SAIL dump_type(log, SRAM, scandump etc) */
            sail_memdump_data = (dump_table_type *)(sail_memdumpentry_ptr->entries + i_entry);
            /* skip failure print msg for debug log dump */
            if ((sail_memdump_data->magic != SAILDUMP_MAGIC_SUCCESS) &&
                (sail_memdump_data->id != SAIL_DBGLOG_DUMP))
            {
                /* Print dump_type enum value for the failed dumps in PASS1 and PASS2 */
                DEBUG_LOG(SAIL_WARNING, "SAILSS dump for region %d failed \r\n", sail_memdump_data->id);
                memdump_fail_flag = TRUE;
            }
        }

        /* Print dump complete message only when all SAIL dumps are available in DDR/SPINOR. Debug log dump is exception */
        if (!memdump_fail_flag)
        {
            if(SAILSS_DDR == dumpdst)
            {
                DEBUG_LOG(SAIL_WARNING, "SAILSS Pass1-Pass2 DDR dump complete \r\n");
            }
            else
            {
                DEBUG_LOG(SAIL_WARNING, "SAILSS Pass1-Pass2 SPINOR dump complete \r\n");
            }
        }
    }
    else
    {
        DEBUG_LOG(SAIL_WARNING, "SAILSS memdump addr invalid\r\n");
    }
exit:
    return;
}

/*===========================================================================
**  Function :  Crashdbg_pass2_dump_CritDbgRegData
** ==========================================================================
*/
/*!
*
* @brief : Collect critical debug information like SAIL Syndromes, FUSA error/warnings, ECC errors etc
* @param : handle [in] NULL i.e not valid in case of DDR dump or Valid SPINOR handle to dump in SAIL NOR flash
* @param : dumpdst [in] DDR or NOR flash to store SAILSS register data
* @param : buffer [in] DDR or NOR flash Start Address to store SAILSS register data
* @Dependencies : to be called with a valid spinor handle, when destination is SPINOR.
* @retval : None
* @Side Effects : None
*
*/
static boolean Crashdbg_pass2_dump_CritDbgRegData(spinor_handle_t handle, Saildumpmemtype dumpdst, uint32 dump_start_addr)
{
    /* Retrieve register configuration */
    uint16_t regdump_values_size = sizeof(Saildbg_regdump_values);
    uint32_t count = 0;
    dcc_sram_cfg_type dcc_sram_cfg = {0};
    uint32_t regdump_start_offset = REGDUMP_START_OFFSET;
    boolean status = FALSE;
    size_t copied_size = 0U;

    /* Retrieve the configuration from DCC */
    status = CrashdbgDCCRetrieveCfg(DCC_TRIGGER_WINDDOWN, &dcc_sram_cfg);

    //ToDO -SYSDBG_LOG_EVENT(GENERIC_EVENT, dcc_sram_cfg.start_addr, dcc_sram_cfg.size, 0);

    /* Sanity checks */
    if ((status) && (dcc_sram_cfg.start_addr) && (dcc_sram_cfg.size))
    {
        for (uint32_t reg_cnt = 0, byte_cnt = 0 ; reg_cnt < SAILSS_REGDUMP_SIZE; reg_cnt++, byte_cnt+=4)
        {
            if((dcc_sram_cfg.start_addr + regdump_start_offset + byte_cnt) > (dcc_sram_cfg.start_addr + dcc_sram_cfg.size))
                break;
            /* Update the value of collected SAILSS register data from DCC SRAM */
            Saildbg_regdump_values[reg_cnt] = *((uint32 *)(uintptr_t)(dcc_sram_cfg.start_addr + regdump_start_offset + byte_cnt));
        }
        /* Based on destination, either copy to DDR or SAIL NOR flash */
        if (dumpdst == SAILSS_DDR)
        {
            /* Copy the unpacked data into DDR for easy scan dump data analysis */
        copied_size = sailbsp_memscpy((void *)dump_start_addr, regdump_values_size, (void *)(uintptr_t)(Saildbg_regdump_values), regdump_values_size);
        status = (copied_size == regdump_values_size);
        }
        else if (dumpdst == SAILSS_NORFLASH)
        {
        SPINOR_STATUS result = spinorEl2Write(handle, dump_start_addr, regdump_values_size, (void *)Saildbg_regdump_values);
            if (result != SPINOR_DEVICE_DONE)
            while(1);   //SPINOR write failure
            status = TRUE;  //SPINOR write success
        }
        else
        {
            /* Invalid dump destination memory */
            /* ToDo - log error msg in DDR */
        }
    }
    return (status);
}

/*===========================================================================
**  Function :  Crashdbg_pass1_dump_tcmData
** ==========================================================================
*/
/*!
*
* @brief : Read TCM data of R52 core 0, 1 & 2 copy to destination-SAIL DDR or NOR Flash
* @param : handle [in] NULL i.e not valid in case of DDR dump or Valid SPINOR handle to dump in SAIL NOR flash
* @param : dumpdst [in] DDR or NOR flash to store DCC scan dump data
* @param : buffer [in] DDR or NOR flash Start Address to store TCM data
* @Dependencies : to be called with a valid spinor handle
* @retval : status [out] FALSE - TCM dump failed or partially happened, TRUE - TCM dump complete
* @Side Effects : None
*
*/
static boolean Crashdbg_pass1_dump_tcmData(spinor_handle_t handle, Saildumpmemtype dumpdst, uint32 dump_start_addr)
{
    boolean status = TRUE;
    uint8 i = 0U;
    uint32 tcm_addr_map[][2] = {
        {SAIL_CORE0_ATCM_START, SAIL_ATCM_SIZE},
        {SAIL_CORE0_BTCM_START, SAIL_BTCM_SIZE},
        {SAIL_CORE0_CTCM_START, SAIL_CTCM_SIZE},
        {SAIL_CORE1_ATCM_START, SAIL_ATCM_SIZE},
        {SAIL_CORE1_BTCM_START, SAIL_BTCM_SIZE},
        {SAIL_CORE1_CTCM_START, SAIL_CTCM_SIZE},
        {SAIL_CORE2_ATCM_START, SAIL_ATCM_SIZE},
        {SAIL_CORE2_BTCM_START, SAIL_BTCM_SIZE},
        {SAIL_CORE2_CTCM_START, SAIL_CTCM_SIZE}
    };
    size_t copied_size = 0U;
    SPINOR_STATUS result;

    for (i = 0; i < SIZEOF_ARRAY(tcm_addr_map); ++i)
    {
        uint32 src_addr = tcm_addr_map[i][0];
        uint32 tcm_unit_size = tcm_addr_map[i][1];

        if ((SAILSS_NORFLASH == dumpdst) && (NULL != handle))
        {
            result = spinorEl2Write(handle, dump_start_addr, tcm_unit_size, (void *)src_addr);
            if(SPINOR_DEVICE_DONE != result)
            {
                status = FALSE;
                break;
            }            
        }
        else if (SAILSS_DDR == dumpdst)
        {
            copied_size = sailbsp_memscpy((void*)dump_start_addr, (size_t)tcm_unit_size, (void*)src_addr, (size_t)tcm_unit_size);
            if (copied_size < tcm_unit_size)
            {
                status = FALSE;
                break;
            }
        }

        dump_start_addr += tcm_unit_size;
    }

    return status;
}

/*===========================================================================
**  Function :  Crashdbg_pass2_dump_R52Scandumpdata
** ==========================================================================
*/
/*!
*
* @brief : Read scan dump data of R52 clusters from DCC SRAM and copy to destination-SAIL DDR or NOR Flash
* @param : handle [in] NULL i.e not valid in case of DDR dump or Valid SPINOR handle to dump in SAIL NOR flash
* @param : dumpdst [in] DDR or NOR flash to store DCC scan dump data
* @param : buffer [in] DDR or NOR flash Start Address to store DCC scan dump data
* @Dependencies : to be called with a valid spinor handle
* @retval : status [out] FALSE - Scan dump data copy failed, TRUE - Scan dump data copy complete
* @Side Effects : None
*
*/
static boolean Crashdbg_pass2_dump_R52Scandumpdata(spinor_handle_t handle, Saildumpmemtype dumpdst, uint32 dump_start_addr)
{
    dcc_sram_cfg_type dcc_sram_cfg = {0};
    uint32_t scandump_start_offset = SCANDUMP_START_OFFSET;
    uint32 unpacked_scandata[UNPACKED_DATA_SIZE_WORDS] = {0};
    boolean status = FALSE;
    size_t copied_size = 0U;
    SaildbgScanDataPktType scandata;

    /* Retrieve  the configuration from DCC */
    status = CrashdbgDCCRetrieveCfg(DCC_TRIGGER_SCANDUMP, &dcc_sram_cfg);

    //ToDO -SYSDBG_LOG_EVENT(GENERIC_EVENT, dcc_sram_cfg.start_addr, dcc_sram_cfg.size, 0);

    /* Sanity checks */
    if ((status) && (dcc_sram_cfg.start_addr) && (dcc_sram_cfg.size))
    {
        for (uint32 i = 0,j = 0; i < dcc_sram_cfg.size; i+=PACKED_DATA_SIZE_BYTES, j+=UNPACKED_DATA_SIZE_WORDS)
        {
            if((dcc_sram_cfg.start_addr + scandump_start_offset + i) > (dcc_sram_cfg.start_addr + dcc_sram_cfg.size))
                break;

            /* Each RTCU Scan register data stored in DCC would be in 32 bit packed format */
            /* We have 24 scan chains in each R52 cluster. Hence, we need unpacked_scandata i.e of 24 bits valid with each bit corresponds to 1 scan chain.  */

            /* 3 packed data(each 32 bits) can be unpacked to get complete 4 unpacked data (each 24 bit valid but MSByte would be 0x00) */
            /* In one iteration below, 4 unpacked data i.e 4 words or 16 bytes will be copied to DDR */
            /* APB SDC has packed the data in the RTCU Scan register as shown in the below example.
            scandata->packeddata =                          0x76543210  0xFEDCBA98   0x76543210
                                                              **------    ....----     ''''''--
            Actual scan chain data(unpacked_scandata)=      0x543210    0xBA9876   0x10FEDC  0x765432
                                                              ------      ----**     --....    ''''''
            upidx =                                           0          1          2         3
            shift_count =                                     0          8          16        24
            */

            /* Store 3 consecutive 4-byte data */
            scandata.packeddata[0] = *((uint32 *)(uintptr_t)(dcc_sram_cfg.start_addr + scandump_start_offset + i));
            scandata.packeddata[1] = *((uint32 *)(uintptr_t)(dcc_sram_cfg.start_addr + scandump_start_offset + i + 4U));
            scandata.packeddata[2] = *((uint32 *)(uintptr_t)(dcc_sram_cfg.start_addr + scandump_start_offset + i + 8U));

            /* Read 4 consecutive 3-byte data */
            unpacked_scandata[0] = scandata.unpackeddata_0;
            unpacked_scandata[1] = scandata.unpackeddata_1;
            unpacked_scandata[2] = scandata.unpackeddata_2;
            unpacked_scandata[3] = scandata.unpackeddata_3;

            /* Based on destination, either copy to DDR or SAIL NOR flash */
            //ToDO- Format of scan dump data must be defined and updated later, like in MD.
            if(dumpdst == SAILSS_DDR)
            {
                /* Copy the unpacked data into DDR for easy scan dump data analysis */
                copied_size = sailbsp_memscpy((void *)((uint32*)dump_start_addr + j), UNPACKED_DATA_SIZE_BYTES, (void *)(uintptr_t)(unpacked_scandata), UNPACKED_DATA_SIZE_BYTES);
                status = (copied_size == UNPACKED_DATA_SIZE_BYTES);
            }
            else if (dumpdst == SAILSS_NORFLASH)
            {
                SPINOR_STATUS result = spinorEl2Write(handle, dump_start_addr, UNPACKED_DATA_SIZE_BYTES, (void *)unpacked_scandata);
                if (result != SPINOR_DEVICE_DONE)
                    while(1);   //SPINOR write failure
                else
                    dump_start_addr += (uint32)UNPACKED_DATA_SIZE_BYTES;
            }
            else
            {
                /* Invalid dump destination memory */
                /* ToDo - log error msg in DDR */
            }
        }
        status = TRUE; //DCC SRAM Dump into DDR/SPINOR successful
    }
    return (status);
}

/*===========================================================================
**  Function :  Crashdbg_pass2_dumptoFlash
** ==========================================================================
*/
/*!
*
* @brief : Dump crash debug data into Sail Flash
* @param : None
* @Dependencies :
* @retval : None
* @Side Effects : None
*
*/
void Crashdbg_pass2_dumptoFlash(void)
{
    spinor_handle_t handle = NULL;
    SPINOR_STATUS result;
    uint32 start_byte = 0;
    uint32 byte_offset = 0;
    uint32 partition_size = 0;
    boolean ret = FALSE;
    spinorMemInfoType mem_info = {0};
    dump_table_type *dump_table_buf = NULL;

    /* Spinor init for ram dump */
    result = spinorEl2Init(SPINOR_INIT_TYPE_RAM_DUMP, NULL);
    if (result != SPINOR_DEVICE_DONE)
    {
      goto exit;
    }

    /* Register a handle for client/crash debug user to use SPINOR services in EL2 */
    result = spinorEl2Open(&handle, SPINOR_USER_TYPE_CRASH_DBG);
    if (result != SPINOR_DEVICE_DONE)
    {
      goto deinit;
    }

    /* To get info about block size, Page size and number of blocks */
    result = spinorEl2GetMemInfo(handle, &mem_info);
    if (result != SPINOR_DEVICE_DONE)
    {
      goto close_handle;
    }

    /* Get GPT info about partition start address and size allocated for ram dump/client/crash debug user */
    result = spinorEl2GetGptPartitionInfo(handle, SAIL_SPINOR_GUID, &byte_offset, &partition_size);
    if (result != SPINOR_DEVICE_DONE)
    {
      goto close_handle;
    }

    /* From above partition info, byte_offset=Start address of SAIL RAM DUMP parition as per SPINOR partition xml
       and partition_size = 0x00500000  i.e 5MB, the total size reserved for SAIL RAM DUMP.
       Note - Same DDR macro "SAIL_DDR_DUMP_SIZE" is used for size allocation check in SPINOR */
    if(partition_size < SAIL_DDR_DUMP_SIZE && (mem_info.pages_per_block * mem_info.page_size_bytes) != SAIL_SPINOR_BLKSIZE)
    {
        while(1); //To trap spinor memory allocation mismatch
    }

    /* Dump critical SAIL registers data from DCC SRAM into SPINOR */
    dump_table_buf = Crashdbg_GetDumpTableBuffer(SAIL_REG_DUMP);
    if(dump_table_buf)
    {
        if(dump_table_buf->magic != SAILDUMP_MAGIC_SUCCESS)
        {
            /* Actual start address of SAIL registers dump in SPINOR RAM dump 5MB partition */
            start_byte = byte_offset + dump_table_buf->start_addr[SAILSS_NORFLASH];
            if((start_byte+dump_table_buf->len) < (byte_offset+partition_size))
            {
            result = spinorEl2Erase(handle, SPINOR_BLOCK_COUNT(start_byte), SPINOR_BLOCK_COUNT(dump_table_buf->len));
            if (result == SPINOR_DEVICE_DONE)
            {
                /* Write SAIL registers data into SPINOR */
                ret = Crashdbg_pass2_dump_CritDbgRegData(handle, SAILSS_NORFLASH, start_byte);
                if(!ret)
                {
                    dump_table_buf->magic = SAILDUMP_MAGIC_FAILURE;
                    DEBUG_LOG(SAIL_WARNING, "SAILSS registers data dump into NOR flash failed\r\n");
                }
                else
                {
                    dump_table_buf->magic = SAILDUMP_MAGIC_SUCCESS;
                    dump_table_buf->version = REG_DUMP_FORMAT_VERSION;
                    SPARE_REG_SET_BIT(SR_REGDUMP_COMPLETE);
                    DEBUG_LOG(SAIL_WARNING, "SAILSS registers dump into NOR flash successful\r\n");
                }
            }
            else
            {
                DEBUG_LOG(SAIL_WARNING, "SAILSS NOR flash erase partition failed for registers dump\r\n");
            }
        }
        else
        {
                DEBUG_LOG(SAIL_WARNING, "SAILSS NOR flash offset is out of ramdump partition\r\n");
            }
        }
        else
        {
            DEBUG_LOG(SAIL_WARNING,"SAILSS regdump already done. Pass2 re-entry.\r\n");
        }
    }

    /* Dump R52 clusters APB scandump data from DCC SRAM into SPINOR */
    dump_table_buf = Crashdbg_GetDumpTableBuffer(SAIL_DATA_APB_SCANDUMP);
    if(dump_table_buf)
    {
        if(dump_table_buf->magic != SAILDUMP_MAGIC_SUCCESS)
        {
            /* Actual start address of SAIL registers dump in SPINOR RAM dump 5MB partition */
            start_byte = byte_offset + dump_table_buf->start_addr[SAILSS_NORFLASH];
            if((start_byte+dump_table_buf->len) < (byte_offset+partition_size))
            {
            result = spinorEl2Erase(handle, SPINOR_BLOCK_COUNT(start_byte), SPINOR_BLOCK_COUNT(dump_table_buf->len));
            if (result == SPINOR_DEVICE_DONE)
            {
                /* Write R52 scan dump data into SPINOR */
                ret = Crashdbg_pass2_dump_R52Scandumpdata(handle, SAILSS_NORFLASH, start_byte);
                if(!ret)
                {
                    dump_table_buf->magic = SAILDUMP_MAGIC_FAILURE;
                    DEBUG_LOG(SAIL_WARNING, "SAILSS scandump into NOR flash failed\r\n");
                }
                else
                {
                    dump_table_buf->magic = SAILDUMP_MAGIC_SUCCESS;
                    dump_table_buf->version = SCAN_DUMP_FORMAT_VERSION;
                    SPARE_REG_SET_BIT(SR_SCANDUMP_COMPLETE);
                    DEBUG_LOG(SAIL_WARNING, "SAILSS scandump into NOR flash successful\r\n");
                }
            }
            else
            {
                DEBUG_LOG(SAIL_WARNING, "SAILSS NOR flash erase partition failed for scandump\r\n");
            }
        }
        else
        {
                DEBUG_LOG(SAIL_WARNING, "SAILSS NOR flash offset is out of ramdump partition\r\n");
            }
        }
        else
        {
            DEBUG_LOG(SAIL_WARNING,"SAILSS scandump already done. Pass2 re-entry.\r\n");
        }
    }

    /* Dump Sail_DumpTable_P2 variable */
    Crashdbg_dumpFmtTable(handle, byte_offset,partition_size, SAILSS_NORFLASH, SAIL_DUMP_TABLE_P2);
    SPARE_REG_SET_BIT(SR_P2_TABLE_DUMP_COMPLETE);

    /* Print spare reg value in console before dumping SDI console log */
    DEBUG_LOG(SAIL_INFO, "CSR SPARE REG value = 0x%08X\r\n", SPARE_REG_READ_VAL());

    /* Dump PASS2 console logs from QUPRAM into SPINOR */
    /* It is done at the last to capture all previous logs */
    dump_table_buf = Crashdbg_GetDumpTableBuffer(SAIL_DBGLOG_DUMP);
    if(dump_table_buf)
    {
        if(dump_table_buf->magic != SAILDUMP_MAGIC_SUCCESS)
        {
            /* Actual start address of SAIL registers dump in SPINOR RAM dump 5MB partition */
            start_byte = byte_offset + dump_table_buf->start_addr[SAILSS_NORFLASH];
            if((start_byte+dump_table_buf->len) < (byte_offset+partition_size))
            {
            result = spinorEl2Erase(handle, SPINOR_BLOCK_COUNT(start_byte), SPINOR_BLOCK_COUNT(dump_table_buf->len));
            if (result == SPINOR_DEVICE_DONE)
            {
                /* Write PASS2 log data into SPINOR */
                result = spinorEl2Write(handle, start_byte, dump_table_buf->len, (void*)(SAIL_LOG_QUPRAM_STARTADDR));
                if(!ret)
                {
                    dump_table_buf->magic = SAILDUMP_MAGIC_FAILURE;
                    DEBUG_LOG(SAIL_WARNING, "SAILSS scandump into NOR flash failed\r\n");
                }
                else
                {
                    dump_table_buf->magic = SAILDUMP_MAGIC_SUCCESS;
                    dump_table_buf->version = DBGLOG_DUMP_FORMAT_VERSION;
                    SPARE_REG_SET_BIT(SR_DBGLOG_DUMP);
                    DEBUG_LOG(SAIL_WARNING, "SAILSS scandump into NOR flash successful\r\n");
                }
            }
            else
            {
                DEBUG_LOG(SAIL_WARNING, "SAILSS NOR flash erase partition failed for scandump\r\n");
            }
        }
        else
        {
                DEBUG_LOG(SAIL_WARNING, "SAILSS NOR flash offset is out of ramdump partition\r\n");
            }
        }
        else
        {
            DEBUG_LOG(SAIL_WARNING,"SAILSS scandump already done. Pass2 re-entry.\r\n");
        }
    }

    /* Validate SAIL PASS1 and PASS2 dump from SPINOR */
    /* ToDo - Sail dump validation will fail for spinor as PASS1 dump is not supported yet and
    a way to handle dumps that are skipped in general and based on debug policy flags is open */
    //Crashdbg_validate_saildump(handle, byte_offset, SAILSS_NORFLASH);

close_handle:
    /* Close the handle */
    result = spinorEl2Close(handle);
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG(SAIL_WARNING, "SAILSS closing SPINOR handle failed\r\n");
    }
deinit:
    /* DeInitialize SPINOR driver in EL2 */
    spinorEl2DeInit(SPINOR_INIT_TYPE_RAM_DUMP);
exit:
    return;
}

/*===========================================================================
**  Function :  Crashdbg_pass2_dumptoDDR
** ==========================================================================
*/
/*!
*
* @brief : Dump crash debug data into DDR - SAIL region
* @param : None
* @Dependencies : Make sure that DDR from MD is ready before we allocate and dump the data here
* @retval : TRUE- Dump to DDR successful, FALSE - Dump to DDR Failed
* @Side Effects : None
*
*/
void Crashdbg_pass2_dumptoDDR(void)
{
    dump_table_type *dump_table_buf = NULL;
    boolean status = FALSE;
    size_t copied_size = 0U;

    /* NOTE - MAKE SURE SAIL IS NOT IN ISLAND MODE */
    /* Dump critical SAIL registers data from DCC SRAM into DDR */
    dump_table_buf = Crashdbg_GetDumpTableBuffer(SAIL_REG_DUMP);
    if(dump_table_buf)
    {
        if(dump_table_buf->magic != SAILDUMP_MAGIC_SUCCESS)
        {
          if( (dump_table_buf->start_addr[SAILSS_DDR] >= SAIL_DDR_DUMP_STARTADDR) &&
              (dump_table_buf->start_addr[SAILSS_DDR] + dump_table_buf->len) < (SAIL_DDR_DUMP_STARTADDR + SAIL_DDR_DUMP_SIZE))
          { 			
            status = Crashdbg_pass2_dump_CritDbgRegData(NULL, SAILSS_DDR, dump_table_buf->start_addr[SAILSS_DDR]);
            if(!status)
            {
                dump_table_buf->magic = SAILDUMP_MAGIC_FAILURE;
                DEBUG_LOG( SAIL_ERROR,"SAILSS regdump into DDR failed \r\n" );
            }
            else
            {
                /* Update magic and version after succesful dump */
                dump_table_buf->magic = SAILDUMP_MAGIC_SUCCESS;
                dump_table_buf->version = REG_DUMP_FORMAT_VERSION;
                SPARE_REG_SET_BIT(SR_REGDUMP_COMPLETE);
                DEBUG_LOG( SAIL_WARNING,"SAILSS regdump into DDR completed \r\n" );
            }
        }
        else
        {
            DEBUG_LOG( SAIL_ERROR,"SAILSS regdump region offset is out of ramdump partition \r\n" );
          }		  
        }
        else
        {
            DEBUG_LOG( SAIL_WARNING,"SAILSS regdump alrdy done. Pass2 re-entry \r\n" );
        }
    }

    /* Dump R52 clusters APB scandump data from DCC SRAM into DDR */
    dump_table_buf = Crashdbg_GetDumpTableBuffer(SAIL_DATA_APB_SCANDUMP);
    if(dump_table_buf)
    {
        if(dump_table_buf->magic != SAILDUMP_MAGIC_SUCCESS)
        {
          if( (dump_table_buf->start_addr[SAILSS_DDR] >= SAIL_DDR_DUMP_STARTADDR) &&
              (dump_table_buf->start_addr[SAILSS_DDR] + dump_table_buf->len) < (SAIL_DDR_DUMP_STARTADDR + SAIL_DDR_DUMP_SIZE))
          { 
            /* Copy R52 scan dump data from DCC SRAM into DDR */
            status = Crashdbg_pass2_dump_R52Scandumpdata(NULL, SAILSS_DDR, dump_table_buf->start_addr[SAILSS_DDR]);
            if(!status)
            {
                dump_table_buf->magic = SAILDUMP_MAGIC_FAILURE;
                DEBUG_LOG( SAIL_WARNING,"SAILSS scandump into DDR failed \r\n" );
            }
            else
            {
                /* Update magic and version after succesful dump */
                dump_table_buf->magic = SAILDUMP_MAGIC_SUCCESS;
                dump_table_buf->version = SCAN_DUMP_FORMAT_VERSION;
                SPARE_REG_SET_BIT(SR_SCANDUMP_COMPLETE);
                DEBUG_LOG( SAIL_WARNING,"SAILSS scandump into DDR completed \r\n" );
            }
        }
        else
        {
            DEBUG_LOG( SAIL_ERROR,"SAILSS scandump region offset is out of ramdump partition \r\n" );
          }			
        }
        else
        {
            DEBUG_LOG( SAIL_WARNING,"SAILSS scandump alrdy done. Pass2 re-entry \r\n" );
        }
    }

    /* After dumping all other regions, dump Sail_DumpTable_P2 variable */
    Crashdbg_dumpFmtTable(NULL, SAIL_DDR_DUMP_STARTADDR, SAIL_DDR_DUMP_SIZE, SAILSS_DDR, SAIL_DUMP_TABLE_P2);
    SPARE_REG_SET_BIT(SR_P2_TABLE_DUMP_COMPLETE);

    /* Validate SAIL PASS1 and PASS2 dump from DDR memory */
    Crashdbg_validate_saildump(NULL, 0U, SAILSS_DDR);

    /* Print spare reg value in console before dumping SDI console log */
    DEBUG_LOG(SAIL_INFO, "CSR SPARE REG value = 0x%08X\r\n", SPARE_REG_READ_VAL());

    /* Dump PASS2 console logs from QUPRAM into DDR */
    /* It is done at the last to capture all previous logs */
    dump_table_buf = Crashdbg_GetDumpTableBuffer(SAIL_DBGLOG_DUMP);
    if(dump_table_buf)
    {
        if(dump_table_buf->magic != SAILDUMP_MAGIC_SUCCESS)
        {
          if( (dump_table_buf->start_addr[SAILSS_DDR] >= SAIL_DDR_DUMP_STARTADDR) &&
              (dump_table_buf->start_addr[SAILSS_DDR] + dump_table_buf->len) < (SAIL_DDR_DUMP_STARTADDR + SAIL_DDR_DUMP_SIZE))
          { 		
            /* Copy PASS2 console log data from QUPRAM into DDR */
            copied_size = sailbsp_memscpy((void*)dump_table_buf->start_addr[SAILSS_DDR], dump_table_buf->len,
                                        (void*)SAIL_LOG_QUPRAM_STARTADDR, dump_table_buf->len);
            if(copied_size < dump_table_buf->len)
            {
                dump_table_buf->magic = SAILDUMP_MAGIC_FAILURE;
                DEBUG_LOG( SAIL_WARNING,"SAILSS PASS2 log dump into DDR failed \r\n" );
            }
            else
            {
                /* Update magic and version after succesful dump */
                dump_table_buf->magic = SAILDUMP_MAGIC_SUCCESS;
                dump_table_buf->version = DBGLOG_DUMP_FORMAT_VERSION;
                SPARE_REG_SET_BIT(SR_DBGLOG_DUMP);
                DEBUG_LOG( SAIL_WARNING,"SAILSS PASS2 log dump into DDR completed \r\n" );
            }
        }
        else
        {
            DEBUG_LOG( SAIL_ERROR,"SAILSS dbglogdump region offset is out of ramdump partition \r\n" );
          }				
        }
        else
        {
            DEBUG_LOG( SAIL_WARNING,"SAILSS PASS2 log dump already done. Pass2 re-entry \r\n" );
        }
    }
}

/*===========================================================================
**  Function :  Crashdbg_pass2_ClockInit
** ==========================================================================
*/
/*!
*
* @brief : Crash debug Clock init in PASS2
* @param : None
* @Dependencies : None
* @retval : None
* @Side Effects : None
*
*/
static void Crashdbg_pass2_ClockInit(void)
{
    /* Enable all clocks required to access APB region through DAP */
    //To-DO - SWAO and QDSS clocks shall be removed after DCC dump - trace flush using QDSS driver and in low power mode.
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR, CLK_ENABLE, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR, CLK_ENABLE, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR, CLK_ENABLE, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_APB_CBCR, CLK_ENABLE, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR, CLK_ENABLE, 0x1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR, CLK_ENABLE, 0x1);
    /* QDSS XO clock is needed to access debug data from DCC SRAM */
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR, CLK_ENABLE, 0x1);
}

/*===========================================================================
**  Function :  Crashdbg_pass2_ramdump_entry
** ==========================================================================
*/
/*!
*
* @brief : Ramdump or PASS2 debug phase
* @param : None
* @Dependencies :
* @retval : Crashdbg_Result [out] - DBG_DISABLED = 0x2, DBG_FAILED = 0x1, DBG_SUCCESS = 0x0
* @Side Effects : None
*
*/
Crashdbg_Result Crashdbg_pass2_ramdump_entry(void)
{
    const Saildbg_config_type* dbg_cfg = &Saildbg_config_data;
    uint16_t sail_rst_fsm_st = 0;
    boolean ddr_rdy_sts = FALSE;
    uint16_t ddr_rdy_waittime = 0;
    uint32_t sail_rst_sts = 0;
    uint32_t sail_spare_reg = 0;

    /* Execute PASS2 only when Sail reset debug flag is enabled */
    if (!dbg_cfg->sail_rst_dbg_en)
        return(DBG_DISABLED);

    /* Check for SAIL is in PASS2 to continue Ramdump debug phase */
    sail_rst_fsm_st = HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS, FSM_STATE);
    sail_rst_sts = HWIO_IN(SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS);
    sail_spare_reg = SPARE_REG_READ_VAL();

    DEBUG_LOG( SAIL_WARNING,"DBG PDC Tr = %d, Pass1 expire = %d, Pass1 complete = %d, Sail FSM state = 0x%X, MD FSM state = 0x%X \r\n",
                HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS, DBG_PDC_TRIGGER),
                HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS, FIRST_PASS_EXPIRE),
                HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL, FIRST_PASS_COMPLETE),
                sail_rst_fsm_st, HWIO_IN(SAILSS_CLKCTL_SAILSS_CC_MD_RESET_FSM_STATUS));


    DEBUG_LOG( SAIL_WARNING,"dbg_cookie = 0x%08X \r\n",sail_spare_reg);
    DEBUG_LOG( SAIL_WARNING,"SAILSS pass1 dump status:\r\n SR_FULL_DUMP_ENABLED = %d,\r\n SR_SDI_ENTRY = %d,\r\n \
SR_MD_DDR_RDY_P1 = %d,\r\n SR_LOG_DUMP_COMPLETE = %d,\r\n \
SR_SRAM_DUMP_COMPLETE = %d,\r\n SR_TCM_DUMP_COMPLETE = %d,\r\n SR_P1_TABLE_DUMP_COMPLETE = %d, \r\n SR_TASKHIST_COMPLETE = %d, \r\n \
SR_GICINTSTAT_COMPLETE = %d \r\n",
                (sail_spare_reg >> SR_FULL_DUMP_ENABLED) & 0x1U, 
                (sail_spare_reg >> SR_SDI_ENTRY) & 0x1U,
                (sail_spare_reg >> SR_MD_DDR_RDY_P1) & 0x1U,
                (sail_spare_reg >> SR_LOG_DUMP_COMPLETE) & 0x1U,
                (sail_spare_reg >> SR_SRAM_DUMP_COMPLETE) & 0x1U,
                (sail_spare_reg >> SR_TCM_DUMP_COMPLETE) & 0x1U,
                (sail_spare_reg >> SR_P1_TABLE_DUMP_COMPLETE) & 0x1U,
                (sail_spare_reg >> SR_TASKHIST_COMPLETE) & 0x1U,
                (sail_spare_reg >> SR_GICINTSTAT_COMPLETE) & 0x1U);
    DEBUG_LOG( SAIL_WARNING,"Pass2 Sail_ResetSts_Regval = 0x%X \r\n", sail_rst_sts);

    DEBUG_LOG( SAIL_WARNING,"Srst = %d, Qdss_sw_srst = %d, MDpshld_rst = %d, MDpmicflt = %d \r\n",
                (sail_rst_sts & SRST_STS_MSK) >> SRST_STS_SHFT,
                (sail_rst_sts & QDSS_SW_RST_MSK) >> QDSS_SW_RST_SHFT,
                (sail_rst_sts & MDPSHLDRST_STS_MSK) >> MDPSHLDRST_STS_SHFT,
                (sail_rst_sts & MDPMICFLT_STS_MSK) >> MDPMICFLT_STS_SHFT);
				
    DEBUG_LOG( SAIL_WARNING,"Pwrseqwdog_exp = %d, R52wdog_exp = %d, Sailpmic_AbnrmResin = %d \r\n",
                (sail_rst_sts & PWRSEQWDOG_EXP_MSK) >> PWRSEQWDOG_EXP_SHFT,
                (sail_rst_sts & R52WDOG_EXP_MSK) >> R52WDOG_EXP_SHFT,
                (sail_rst_sts & PMICABNRESIN_MSK) >> PMICABNRESIN_SHFT );				
    
    DEBUG_LOG( SAIL_WARNING,"SailTsens1_rst = %d, SailTsens0_rst = %d \r\n",
                (sail_rst_sts & TSENS1RST_STS_MSK) >> TSENS1RST_STS_SHFT,
                (sail_rst_sts & TSENS0RST_STS_MSK) >> TSENS0RST_STS_SHFT);	
    if (sail_rst_fsm_st == SP_PRE_DDR_INIT_ST)
    {
        /* update ramdump entry status in spare reg */
        SPARE_REG_SET_BIT(SR_RAMDUMP_ENTRY);
        DEBUG_LOG( SAIL_WARNING,"SAILSS pass2 start \r\n" );

        /* SW Workaround - Though SAIL doesn't control DDR, set DDR_OUT_OF_SELF_RFRSH bit to
        move SAIL RESET CTRL FSM state to "SP_POST_DDR_INIT_ST" as soon as SAIL enters PASS2 */
        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL, DDR_OUT_OF_SELF_RFRSH, 0x1);

        /* Clock Init upon PASS2 Entry */
        Crashdbg_pass2_ClockInit();
        /* Program PMIC for hard reset at the beginning of RAMdump like MD,
        to let SAIL hard reset if any second crash happens during dump.
        Configure SAIL PMIC only for ADAS - Independent PMIC case */
        if(TRUE == bSailPmicPresent())
        {
            if (xPmicSetResetState(PMIC_POFF_PON) != PMIC_ERR_FLAG_SUCCESS)
            {
                DEBUG_LOG( SAIL_WARNING,"SAILSS pass2 pmic hard reset cfg failed \r\n" );
            }
        }

        /* Check MD crash debug status based on MD Reset FSM state */
        /* Use case - Wait for MD to reach PASS2 if it's not reached PASS2 yet and SAIL PASS1 timer expired */
        (void)Crashdbg_WaitforMD(PASS2_START);

        /* SAIL can wait for DDR Ready from MD to dump debug data into DDR.
        In MD-PASS2, "Second pass complete" bit is set after successful DDR Init in XBL_LDR
        and as soon as MD RAMDUMP Image is loaded.
        Hence MD RESET CTRL FSM state will be "IDLE" after DDR Ready from MD */
        /* Is DDR available within timeout of 2sec */
        do
        {
            busywait(1000); //busy wait time of 1ms between DDR Ready Status check from MD
            /* Read DDR Ready status from MD->SAIL shadow register*/
            ddr_rdy_sts = Crashdbg_WaitforDDRReady();
            ddr_rdy_waittime++;
        }while ((!ddr_rdy_sts) && (ddr_rdy_waittime <= DDR_RDY_PASS2_TIMEOUT));

        if(ddr_rdy_sts)
        {
            SPARE_REG_SET_BIT(SR_MD_DDR_RDY_P2);

            /* Note - Make sure SAIL is not in Island mode before DDR dump.
            When SAIL is in Island mode, DDR Ready from MD will timeout */
            /* Initialize Dump table to get start address and size info for each dump region/entry */
            DEBUG_LOG( SAIL_WARNING,"SAILSS pass2 DDR Dump Start \r\n" );
            if(0x1u != ((SPARE_REG_READ_VAL()& MD_DDR_RDY_P1_MASK) >> SR_MD_DDR_RDY_P1))
            {
                DEBUG_LOG( SAIL_WARNING,"SAILSS pass2 Copy Pass1 spinor dump to DDR  \r\n" );
                Crashdbg_pass2_ReadFromFlash();
                SPARE_REG_SET_BIT(SR_P1_NOR_DUMP_TO_DDR_COMPLETE);
            }
            /* Copy the SAIL registers and R52 scandump data into DDR-SAIL Region */
            Crashdbg_pass2_dumptoDDR();

            /* Copy CSR SPARE REG value to DDR */
            COPY_SPARE_REG(SAIL_DDR_CRASHDBG_STATUS_ADDR);
        }
        else
        {
            DEBUG_LOG( SAIL_WARNING,"SAILSS pass2 SPINOR Dump Start \r\n" );

            /* Dump debug data into SAIL Flash upon DDR ready timeout */
            Crashdbg_pass2_dumptoFlash();
        }

        /* Set DDR/SPINOR dump complete */
        Crashdbg_pass2_DumpComplete();
        DEBUG_LOG( SAIL_WARNING,"SAILSS pass2 dump complete ACK updated \r\n" );
		
        sail_spare_reg = SPARE_REG_READ_VAL();
        DEBUG_LOG( SAIL_WARNING,"SAILSS pass2 MD FSM state = 0x%X dbg_cookie = 0x%08X \r\n",
                   HWIO_IN(SAILSS_CLKCTL_SAILSS_CC_MD_RESET_FSM_STATUS),sail_spare_reg);
        DEBUG_LOG( SAIL_WARNING,"SAILSS pass2 dump status:\r\n SR_MD_DDR_RDY_P2 = %d,\r\n SR_REGDUMP_COMPLETE = %d,\r\n \
SR_SCANDUMP_COMPLETE = %d,\r\n SR_DBGLOG_DUMP = %d,\r\n \
SR_P2_TABLE_DUMP_COMPLETE = %d,\r\n SR_P1_NOR_DUMP_TO_DDR_COMPLETE = %d, \r\n SR_P1_TASKHIST_NOR_DUMP_TO_DDR_COMPLETE = %d, \r\n \
SR_P1_GICINTSTAT_NOR_DUMP_TO_DDR_COMPLETE = %d \r\n",
                   (sail_spare_reg >> SR_MD_DDR_RDY_P2) & 0x1U,
                   (sail_spare_reg >> SR_REGDUMP_COMPLETE) & 0x1U,
                   (sail_spare_reg >> SR_SCANDUMP_COMPLETE) & 0x1U,
                   (sail_spare_reg >> SR_DBGLOG_DUMP) & 0x1U,
                   (sail_spare_reg >> SR_P2_TABLE_DUMP_COMPLETE) & 0x1U,
                   (sail_spare_reg >> SR_P1_NOR_DUMP_TO_DDR_COMPLETE) & 0x1U,
                   (sail_spare_reg >> SR_P1_TASKHIST_NOR_DUMP_TO_DDR_COMPLETE) & 0x1U,
                   (sail_spare_reg >> SR_P1_GICINTSTAT_NOR_DUMP_TO_DDR_COMPLETE) & 0x1U);
        (void)Crashdbg_WaitforMD(PASS2_END);

        /* Set SAIL PASS2 complete */
        HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL, SECOND_PASS_COMPLETE, 0x1);
        DEBUG_LOG( SAIL_WARNING,"SAILSS pass2 complete \r\n" );

        /* Deassert SAIL2MD_PS_HOLD and SAIL_PS_HOLD at the end of Pass2 */
        (void)eISDSailToMDPSHoldDeAssert();
        (void)eISDSailPSHoldDeAssert();

        /* De-asserting SAIL PS HOLD above will initiate hard reset(POFF and PON) of SAIL.
        Hence, we have an infinite loop at the end of PASS2 */
        while(1);

        return (DBG_SUCCESS);
    }
    else
    {
        DEBUG_LOG( SAIL_WARNING,"SAILSS pass2 skipped. rst_ctrl fsm in %d \r\n",sail_rst_fsm_st);
        return (DBG_FAILED);
    }
}

/*===========================================================================
**  Function :  Crashdbg_GetSailResetCtrlFSMState
** ==========================================================================
*/
/*!
*
* @brief : Get current SAIL RESET Controller FSM State
* @param : None
* @Dependencies :
* @retval : FSM State [out] - 0x0:IDLE to 0xF:ALLOW_PRE_ARES_PCIE_LINK_CHK_ST
* @Side Effects : None
*
*/
CRASHDBG_RST_CTRL_FSM_ST Crashdbg_GetSailResetCtrlFSMState(void)
{
    return (HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS, FSM_STATE));
}

/*===========================================================================
**  Function :  Crashdbg_pass1_busywait_ms
** ==========================================================================
*/
/*!
*
* @brief : Get current SAIL RESET Controller FSM State
* @param : wait time in milliseconds
* @Dependencies : pass 1 timer should be enabled and running
* @retval : None
* @Side Effects : None
*
*/
void Crashdbg_pass1_busywait_ms(uint32 delay_ms)
{
    uint32 pass1_start_tick = 0U;
    uint32 pass1_curr_tick = 0U;
    uint32 pass1_tick_diff = 0U;

    pass1_start_tick = HWIO_IN(SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_CURR_TIME);
    do {
        pass1_curr_tick = HWIO_IN(SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_CURR_TIME);
        /* this is a down counter, so start tick will be higher than current tick */
        pass1_tick_diff = pass1_start_tick - pass1_curr_tick;
    } while (CONVERT_TICKS_TO_MS(pass1_tick_diff, SAILSS_CC_XO_CLOCK_HZ) < delay_ms);
}

/*===========================================================================
**  Function :  Crashdbg_dumpFmtTable
** ==========================================================================
*/
/*!
*
* @brief : Dumps Sail_DumpTable into specified memory (DDR or spinor)
* @param : spinor handle if destination is spinor
* @param : spinor ramdump region offset if destination is spinor
* @param : dump destination - DDR or NOR flash
* @param : dump type - SAIL_DUMP_TABLE_P1 or SAIL_DUMP_TABLE_P2
* @Dependencies : None
* @retval : dump status
* @Side Effects : None
*
*/
static void Crashdbg_dumpFmtTable(spinor_handle_t handle, uint32 region_offset,uint32 partition_size, Saildumpmemtype dumpdst, dump_type id)
{
    uint32 start_byte = 0U;
    size_t copied_size = 0U;
    size_t dump_table_size = 0U;
    dump_table_type *dump_table = NULL;
    dump_table_type *dump_table_buf = NULL;
    SPINOR_STATUS spinor_result;

    dump_table_buf = Crashdbg_GetDumpTableBuffer(id);
    if (!dump_table_buf)
    {
        DEBUG_LOG(SAIL_WARNING, "SAILSS Dump Format table failed due to invalid buffer\r\n");
        goto exit;
    }
    else if (SAILDUMP_MAGIC_SUCCESS == dump_table_buf->magic)
    {
        DEBUG_LOG(SAIL_WARNING, "SAILSS Dump Format table already done\r\n");
        goto exit;
    }
    else
    {

    }

    if (SAIL_DUMP_TABLE_P1 == id)
    {
        dump_table = Sail_DumpTable_P1;
        dump_table_size = sizeof(Sail_DumpTable_P1);
    }
    else if (SAIL_DUMP_TABLE_P2 == id)
    {
        dump_table = Sail_DumpTable_P2;
        dump_table_size = sizeof(Sail_DumpTable_P2);
    }
    else
    {
        DEBUG_LOG(SAIL_WARNING, "SAILSS Dump Format table - invalid dump type id\r\n");
        goto exit;
    }

    /* update magic number and version before writing */
    dump_table_buf->magic = SAILDUMP_MAGIC_SUCCESS;
    dump_table_buf->version = TABLE_DUMP_FORMAT_VERSION;

    if (SAILSS_DDR == dumpdst)
    {
        if( (dump_table_buf->start_addr[SAILSS_DDR] >= region_offset) && //region_offset for DDR = SAIL_DDR_DUMP_STARTADDR
            (dump_table_buf->start_addr[SAILSS_DDR] + dump_table_size) < (region_offset + partition_size))
        {
        /* write Sail_DumpTable structure into DDR */
        copied_size = sailbsp_memscpy((void*)dump_table_buf->start_addr[SAILSS_DDR], dump_table_size,
                                    (void*)dump_table, dump_table_size);
        if (copied_size != dump_table_size)
        {
            DEBUG_LOG(SAIL_WARNING, "SAILSS Dump Format table into DDR failed\r\n");
        }
        else
        {
            DEBUG_LOG(SAIL_WARNING, "SAILSS Dump Format table into DDR successful\r\n");
        }
    }
        else
        {
            DEBUG_LOG(SAIL_WARNING, "SAILSS Dump Format offset is out of bounds with ramdump partition\r\n");
        }    
	}
    else if ((SAILSS_NORFLASH == dumpdst) && handle)
    {
        /* ToDo: Erase dump format table region when dumping in PASS1. Now erasing by default */

        /* Actual start address of SAIL registers dump in SPINOR RAM dump 5MB partition */
        start_byte = region_offset + dump_table_buf->start_addr[SAILSS_NORFLASH];
        if((start_byte+dump_table_buf->len) < (region_offset+partition_size))
        {
        /* skip erase for pass2 dump table, because its start address is not 4KB aligned and will result in erasing pass1 dump table also */
        if (SAIL_DUMP_TABLE_P1 == id)
        {
            spinor_result = spinorEl2Erase(handle, SPINOR_BLOCK_COUNT(start_byte), SPINOR_BLOCK_COUNT(dump_table_buf->len));
            if (SPINOR_DEVICE_DONE != spinor_result)
            {
                DEBUG_LOG(SAIL_WARNING, "SAILSS NOR flash erase partition failed for dump table\r\n");
                goto exit;
            }
        }

        /* write Sail_DumpTable structure into spinor */
        spinor_result = spinorEl2Write(handle, start_byte, dump_table_size, (void*)dump_table);
        if (SPINOR_DEVICE_DONE != spinor_result)
        {
            DEBUG_LOG(SAIL_WARNING, "SAILSS Dump Format table into NOR flash failed\r\n");
            while(1);
        }
        else
        {
            DEBUG_LOG(SAIL_WARNING, "SAILSS Dump Format table into NOR flash successful\r\n");
        }
    }
    else
    {
            DEBUG_LOG(SAIL_WARNING, "SAILSS Dump Format offset is out of bounds with ramdump partition\r\n");
        }
    }
    else
    {
        DEBUG_LOG(SAIL_WARNING, "SAILSS Dump Format table failed due to invalid dump destiantion\r\n");
    }

exit:
    return;
}

/*===========================================================================
**  Function :  Crashdbg_disable
** ==========================================================================
*/
/*!
*
* @brief : Crash debug disable and SAIL follow MD_PS_HOLD disable/enable, upon request
* @param : ctrl_type [in] 0 - clear mask md_ps_hold, 1 - clear debug enable and mask md_ps_hold, 2 - Unmask md_ps_hold
* @Dependencies : None
* @retval : Crashdbg_Result [out] - DBG_DISABLED = 0x2, DBG_FAILED = 0x1, DBG_SUCCESS = 0x0
* @Side Effects : Crashdbg shall be enabled only in the next boot, as part of Crashdbg_Init
*
*/
Crashdbg_Result Crashdbg_disable(Crashdbg_CtrlType_e ctrl_type)
{
    Crashdbg_Result result = DBG_FAILED;
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;

    switch(ctrl_type)
    {
        case DEP_CRASH_DISABLED: /* SAIL in Island mode. Only MD will go through reset in case of Auth fail from primary LUN in XBL_LDR boot stage */

            /* Disable SAIL dependent crash flow upon MD fatal error detection,
            only if it's enabled at cold boot or via UART test command */
            if (HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE, MD_PS_HOLD_RST_DEBUG_EN) == 0x1)
            {
                HWIO_OUTM(SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE,
                          HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_MD_PS_HOLD_RST_DEBUG_EN_BMSK, 0x0);
                /* Mask MD_PS_HOLD to block  SAIL concurrent crash flow upon MD fatal error detection
                i.e allow SAIL PS HOLD will not follow MD_PS_HOLD */
                HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK, FSM_STATE_MASK, 0xFFFF);
            }
            if (HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE, MD_PMIC_FAULT_RST_DEBUG_EN) == 0x1)
            {
                HWIO_OUTM(SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE,
                HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_MD_PMIC_FAULT_RST_DEBUG_EN_BMSK, 0x0);
            }
            result = DBG_DISABLED;
        break;

        case CRASHDBG_DISABLED: /* SAIL and MD warm resets together, in case of Auth fail from secondary LUN in XBL_LDR boot stage */
        case CRASHDBG_DISABLE_PMIC_RECFG:
            /* If already disabled or crash debug mode OFF, skip crash debug disable; 
            especially to avoid override of SAILSS_CC_MD_PS_HOLD_MASK */
            if (HWIO_IN(SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE))
            {	
              /* Clear SAIL RESET debug enable register so that SAIL RESET CTRL FSM won't enter crash reset
              PASS0-PASS1-PASS2 FSM states */
              HWIO_OUT(SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE, 0x0);
              /* Mask MD_PS_HOLD to block  SAIL concurrent crash flow upon MD fatal error detection
              i.e allow SAIL PS HOLD will not follow MD_PS_HOLD */
              HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK, FSM_STATE_MASK, 0xFFFF);
            }
            /* In case of MD_SOC_SDI_DISABLE, disable crash debug feature and re-configure PMIC in one hvc call*/
#if 0
// From MD side SDI_DISABLE Intr coming first then , WR Intr coming so we have commented this part 

	if ( (ctrl_type == CRASHDBG_DISABLE_PMIC_RECFG) && (TRUE == bSailPmicPresent()) )
            {
              /* 
              * For SAFE SP's - Configuring PMIC for POff(Shutdown).
              * For NON-SAFE SP's - Configuring PMIC for POff+POn(Hard reset).   
              */
              if (getSkipMDBISTConfig() == TRUE)
              {
                xErrFlag = xPmicSetResetState(PMIC_POFF_PON);
              }
              else
              {
                xErrFlag = xPmicSetResetState(PMIC_POFF);
              }
              if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
              {
                DEBUG_LOG(SAIL_ERROR,"SAILSS PMIC Shutdown cfg failed \r\n");
              }
            }

#endif
            result = DBG_DISABLED;
        break;

        case DEP_CRASH_ENABLED: /* SAIL in Normal mode, in case of no boot failure from secondary LUN in XBL_LDR boot stage */

            /* Unmask MD_PS_HOLD to allow  SAIL concurrent crash flow upon MD fatal error detection
            i.e allow SAIL PS HOLD will follow MD_PS_HOLD */
            /* NOTE - Re-enabling SAIL dependent crash, upon MD fatal error via UART is not supported.
             This shall be enabled only in next cold boot via Crashdbg_Init*/
            if (HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE, MD_PS_HOLD_RST_DEBUG_EN) == 0x1)
            {
               HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK, FSM_STATE_MASK, 0xCFF8);
               result = DBG_SUCCESS;
            }
            else
            {
               HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK, FSM_STATE_MASK, 0xFFFF);
               result = DBG_DISABLED;
            }
        break;

        default:
		 DEBUG_LOG(SAIL_ERROR,"====> Crashdbg disable Debug case \r\n");
        break;
    }

    return result;
}
/**********************************************************************************************************
**                                  End of file Crashdbg                                                 **
**********************************************************************************************************/
