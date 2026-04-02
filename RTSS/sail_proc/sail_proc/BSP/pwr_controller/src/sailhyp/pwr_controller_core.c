
/*
===========================================================================
*/
/**
    @file  pwr_controller_core.c
    @brief Implementation of Power Controller core functions

*/
/*
    ===========================================================================

    Copyright (c) 2021-2023 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/pwr_controller/src/sailhyp/pwr_controller_core.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "hw_io.h"
#include "HALhwio.h"
#include "pwr_controller_core.h"
#include "pwr_controller_cmn.h"
#include "pwr_controller_seq.h"
#include "sail_pwr_cntrl_hwio.h"
#include "interrupts.h"
#include "busywait.h"
#include "common_functions.h"
#include "libfdt_env.h"
#include "libfdt.h"
#include "fdt_utils.h"
#include "debug_log.h"

/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * -------------------------------------------------------------------------*/
#define ARRAY_LENGTH(a) (sizeof(a) / sizeof((a)[0]))

#define PC_WAKEIRQ_TO_RTCU_VECTOR  812          /* WakeIRQ interrupt vector */

#define PC_SLEEP_TMR_VAL           0x1550       /* SAIL Sleep timer value */

#define PC_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_VS_FUSA_ERR_0_BMSK 1U << 3U
#define PC_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_VS_FUSA_ERR_1_BMSK 1U << 4U

#define PC_SAIL_FATAL_ERR_ISO_EN_MASK_SPARE_FATAL_EN_0_VS_MD_FUSA_ERR_0_BMSK 1U << 10U
#define PC_SAIL_FATAL_ERR_ISO_EN_MASK_SPARE_FATAL_EN_1_VS_MD_FUSA_ERR_1_BMSK 1U << 11U
#define SLEEP_EN_GPIO_CONFIG_PRESENT                                          1UL

/* Power Controller Driver context */
PCCoreDrvInfoType_e xPCDrvCtx = {0};

/* Power Controller Hardware base address */
uint32 ulPCBaseAddress = SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE;

/* Initalizes APM Settings */
static PCCoreStatusType_e prvPCCoreAPMInit(void);

/* Initalizes the Interrupts needed for Power Controller */
static PCCoreStatusType_e prvPCCoreInterruptInit(void);

/* Controls the enables for Power Controller Interrupt */
static PCCoreStatusType_e prvPCCoreInterruptCtrl(boolean ctrl);

static enum handler_return xPCCoreWakeISRHandler(void *arg);

/**********************************************************
 * Initalizes APM Settings
 *
 *
 * @param type [IN]
 *   None
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static PCCoreStatusType_e prvPCCoreAPMInit(void)
{
    uint32 ulRegOut;

    /*Enable APM Clock and complete the APM Programming and Disable APM Clock*/

    /* Program SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_0[1] to 0x1 */
    ulRegOut = REG_IN(ulPCBaseAddress, PWR_CTRL_SPARE_REG_0);
    ulRegOut |= 0x2;
    REG_OUT(ulPCBaseAddress, PWR_CTRL_SPARE_REG_0, ulRegOut);

    /* Program SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_OUT[2:1] to 0x1 */
    ulRegOut = REG_IN(ulPCBaseAddress, SAIL_CX_APM_FUNC_OUT);
    ulRegOut |= 0x2;
    REG_OUT(ulPCBaseAddress, SAIL_CX_APM_FUNC_OUT, ulRegOut);

    /* Program SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_0[4] to 0x1 */
    ulRegOut = REG_IN(ulPCBaseAddress, SAIL_CX_APM_CONTROLLER_CONFIG_0);
    ulRegOut |= 0x10;
    REG_OUT(ulPCBaseAddress, SAIL_CX_APM_CONTROLLER_CONFIG_0, ulRegOut);

    /* Program SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_OUT[0] to 0x1 */
    ulRegOut = REG_IN(ulPCBaseAddress, SAIL_CX_APM_FUNC_OUT);
    ulRegOut |= 0x1;
    REG_OUT(ulPCBaseAddress, SAIL_CX_APM_FUNC_OUT, ulRegOut);

    /* Program SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_5[0] to 0x1 */
    ulRegOut = REG_IN(ulPCBaseAddress, SAIL_CX_APM_CONTROLLER_CONFIG_5);
    ulRegOut |= 0x1;
    REG_OUT(ulPCBaseAddress, SAIL_CX_APM_CONTROLLER_CONFIG_5, ulRegOut);

    /* Program SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_1 to 0x05057005 */
    REG_OUT(ulPCBaseAddress, SAIL_CX_APM_CONTROLLER_CONFIG_1, 0x05057005);

    /* Program SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_2 to 0x05050570 */
    REG_OUT(ulPCBaseAddress, SAIL_CX_APM_CONTROLLER_CONFIG_2, 0x05050570);

    /* Program SAILSS_PWR_CTRL_SAIL_CX_APM_CONTROLLER_CONFIG_8[0] to 0x1 */
    ulRegOut = REG_IN(ulPCBaseAddress, SAIL_CX_APM_CONTROLLER_CONFIG_8);
    ulRegOut |= 0x1;
    REG_OUT(ulPCBaseAddress, SAIL_CX_APM_CONTROLLER_CONFIG_8, ulRegOut);

    /* Program SAILSS_PWR_CTRL_PWR_CTRL_SPARE_REG_0[1] to 0x0 */
    ulRegOut = REG_IN(ulPCBaseAddress, PWR_CTRL_SPARE_REG_0);
    ulRegOut ^= 0x2;
    REG_OUT(ulPCBaseAddress, PWR_CTRL_SPARE_REG_0, ulRegOut);

    return PC_SUCCESS;
}

/**********************************************************
 * Initalizes the Interrupts needed for Power Controller
 *
 *
 * @param type [IN]
 *   None
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static PCCoreStatusType_e prvPCCoreInterruptInit(void)
{
    int slRetval=0;

    /* Configure Wake IRQ Attibutes */

    /* Program SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_0 to 0xFFFFFFFF */
    REG_OUT(ulPCBaseAddress, WAKE_IRQ_CFG_ENABLE_0, 0xFFFFFFFF);

    /* Program SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_0 to 0xFFFFFF1F */
    REG_OUT(ulPCBaseAddress, WAKE_IRQ_CFG_POLARITY_0, 0xFFFFFF1F);

    /* Program SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_0 to 0xFFFFFFFF */
    REG_OUT(ulPCBaseAddress, WAKE_IRQ_CFG_POSEDGE_0, 0xFFFFFFFF);

    /* Program SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_0 to 0x00000000 */
    REG_OUT(ulPCBaseAddress, WAKE_IRQ_CFG_NEGEDGE_0, 0x031C0000);

    /* Program SAILSS_PWR_CTRL_WAKE_IRQ_CFG_ENABLE_1 to 0xFFFFFFFF */
    REG_OUT(ulPCBaseAddress, WAKE_IRQ_CFG_ENABLE_1, 0xFFFFFFFF);

    /* Program SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POLARITY_1 to 0xFFFFFFFF */
    REG_OUT(ulPCBaseAddress, WAKE_IRQ_CFG_POLARITY_1, 0xFFFFFFFF);

    /* Program SAILSS_PWR_CTRL_WAKE_IRQ_CFG_POSEDGE_1 to 0xFFFFFFFF */
    REG_OUT(ulPCBaseAddress, WAKE_IRQ_CFG_POSEDGE_1, 0xFFFFFFFF);

    /* Program SAILSS_PWR_CTRL_WAKE_IRQ_CFG_NEGEDGE_1 to 0x00000000 */
    REG_OUT(ulPCBaseAddress, WAKE_IRQ_CFG_NEGEDGE_1, 0x00000000);

#ifdef PC_EL2_INTERRUPTS_ENABLED

    /* Mask the Interrupt at GIC before configuring */
    slRetval = mask_interrupt(PC_WAKEIRQ_TO_RTCU_VECTOR);
    if (slRetval)
    {
        return PC_FAIL;
    }

    /* Configure the Interrupt at GIC */
    slRetval = configure_interrupt(PC_WAKEIRQ_TO_RTCU_VECTOR, INT_CONFIG_LEVEL_TRIGGER, 0);
    if (slRetval)
    {
        return PC_FAIL;
    }

    /* Register the Interrupt handler at GIC */
    slRetval = register_int_handler(PC_WAKEIRQ_TO_RTCU_VECTOR, xPCCoreWakeISRHandler, 0);
    if (slRetval)
    {
        return PC_FAIL;
    }
#endif /* PC_EL2_INTERRUPTS_ENABLED */

    /* Do not unmask the interrupt at GIC here */
    xPCDrvCtx.bWakeIRQEnabled = FALSE;

    return PC_SUCCESS;
}

/**********************************************************
 * Controls the enables for Power Controller Interrupt
 *
 *
 * @param type [IN]
 *   Control for the enable/disable of interrupt
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static PCCoreStatusType_e prvPCCoreInterruptCtrl(boolean bCtrl)
{
#ifdef PC_EL2_INTERRUPTS_ENABLED
    int slRetval = 0;

    if (TRUE == bCtrl) {
        /* Enable wakeIRQ path in GIC */
        slRetval = unmask_interrupt(PC_WAKEIRQ_TO_RTCU_VECTOR);
        if (slRetval)
        {
            return PC_FAIL;
        }
        xPCDrvCtx.bWakeIRQEnabled = TRUE;
    }
    else
    {
        /* Disable wakeIRQ path in GIC */
        slRetval = mask_interrupt(PC_WAKEIRQ_TO_RTCU_VECTOR);
        if (slRetval)
        {
            return PC_FAIL;
        }
        xPCDrvCtx.bWakeIRQEnabled = FALSE;
    }
#endif /* PC_EL2_INTERRUPTS_ENABLED */

    return PC_SUCCESS;
}

/**********************************************************
 * Interrupt Handler for the Power controller Wake ISR
 *
 *
 * @param type [IN]
 *   Argument requsted while registering the handler
 *
 * @return int [OUT]
 *   Return type.
 *
 **********************************************************/
static enum handler_return xPCCoreWakeISRHandler(void *pvarg)
{
    uint32 ulWakeupReasonLo=0, UlWakeupReasonHi=0;

    /* Read the wake up status */
    ulWakeupReasonLo = REG_IN(ulPCBaseAddress, WAKE_IRQ_STATUS_0);
    UlWakeupReasonHi = REG_IN(ulPCBaseAddress, WAKE_IRQ_STATUS_1);

    xPCDrvCtx.ullWakeupReason  = (((uint64)UlWakeupReasonHi)<<32) | ulWakeupReasonLo;

    /* Assert the Stop Wake monitoring and Clear the Start monitoring */
    REG_OUTF(ulPCBaseAddress, WAKE_HANDLER_CFG, STOP_MONITORING, 1);
    REG_OUTF(ulPCBaseAddress, WAKE_HANDLER_CFG, START_MONITORING, 0);

    /* Mask the interrupt here */
    prvPCCoreInterruptCtrl(FALSE);

    return INT_NO_RESCHEDULE;
}

static void vPCCoreConfFatalErrIsoEnMask(void)
{
	uint32_t ulHwioVal = 0U;
	
	ulHwioVal  = HWIO_INX(ulPCBaseAddress, SAIL_FATAL_ERR_ISO_EN_MASK);
	ulHwioVal &= ~( PC_SAIL_FATAL_ERR_ISO_EN_MASK_SPARE_FATAL_EN_0_VS_MD_FUSA_ERR_0_BMSK | 
	                PC_SAIL_FATAL_ERR_ISO_EN_MASK_SPARE_FATAL_EN_1_VS_MD_FUSA_ERR_1_BMSK );
	HWIO_OUTX(ulPCBaseAddress, SAIL_FATAL_ERR_ISO_EN_MASK, ulHwioVal);
}

static void vPCCoreConfFatalErrPsHoldEnMask(void)
{
	uint32_t ulHwioVal = 0U;
	
	ulHwioVal  = HWIO_INX(ulPCBaseAddress, SAIL_FATAL_ERR_PS_HOLD_EN_MASK);
	ulHwioVal &= ~( PC_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_VS_FUSA_ERR_0_BMSK | 
	                PC_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_VS_FUSA_ERR_1_BMSK );
	HWIO_OUTX(ulPCBaseAddress, SAIL_FATAL_ERR_PS_HOLD_EN_MASK, ulHwioVal);
}

/**********************************************************
 * Initalizes the Power controller driver context
 *
 *
 * @param type [IN]
 *   None
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
PCCoreStatusType_e xPCDrvInit(void)
{
    xPCDrvCtx.bPCCoreInitDone    = FALSE;
    xPCDrvCtx.ePCCoreSeqInit     = PC_SEQUENCE_UNINIT;
    xPCDrvCtx.ePCCoreSleepStatus = PC_MODE_ACTIVE;
    xPCDrvCtx.ePCCorePMIC        = PC_PMIC_TYPE_UNKNOWN;
    xPCDrvCtx.ullWakeIRQCfgMask  = 0;
    xPCDrvCtx.ullWakeupReason    = 0;
    xPCDrvCtx.bWakeIRQEnabled    = FALSE;

    return PC_SUCCESS;
}

/**********************************************************
 * Initalizes the Power controller Hardware
 * and Core functionalities required by the Power controller
 *
 *
 * @param type [IN]
 *   PMIC type to configure the hardware accordingly
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
PCCoreStatusType_e xPCCoreInit(PCCorePMICType_e ePMICType)
{
    uint8 ucSAILWakeup = 0,ucMDWakeup = 0;
    PCCoreStatusType_e eStatus;
    uint32 ulRegOut = 0 ;
    uint32_t ulSleepEnGpio = 0ul;
    int retval_dtb = -1;
    void *pDTB = NULL;
    int32_t offset = 0, root_offset = 0;

    if (TRUE == xPCDrvCtx.bPCCoreInitDone)
    {
        /* Return failure if core init gets called again after a successful Init */
        return PC_FAIL;
    }

    /* Load sequencer for crash sequences.
       Do this first due to the dependency in the crashdump path for this sequencer to be loaded for wakeup done signal
    */
    eStatus = xPCCoreLoadSequencer(PC_CRASH_SEQUENCE ,&crash_wkup_seq_mem_cmds[0], ARRAY_LENGTH(crash_wkup_seq_mem_cmds),
                                        &crash_wkup_br_addr[0], ARRAY_LENGTH(crash_wkup_br_addr));

    if (PC_SUCCESS != eStatus)
    {
        return PC_FAIL;
    }

    /* Load sequencer for sleep sequences */
    eStatus = xPCCoreLoadSequencer(PC_SLEEP_SEQUENCE ,&pwr_ctl_seq_mem_cmds[0], ARRAY_LENGTH(pwr_ctl_seq_mem_cmds),
                                        &pwr_ctl_br_addr[0], ARRAY_LENGTH(pwr_ctl_br_addr));

    if (PC_SUCCESS != eStatus)
    {
        return PC_FAIL;
    }

    if (PC_PMIC_INDEPENDENT == ePMICType)
    {
        xPCDrvCtx.ePCCorePMIC = PC_PMIC_TYPE_INDEPENDENT;
        ucMDWakeup = 0;
        ucSAILWakeup = 0x1;
    }
    else if (PC_PMIC_MERGED == ePMICType)
    {
        xPCDrvCtx.ePCCorePMIC = PC_PMIC_TYPE_MERGED;
        ucMDWakeup = 1;
        ucSAILWakeup = 0x0;
    }
    else
    {
        xPCDrvCtx.ePCCorePMIC = PC_PMIC_TYPE_UNKNOWN;
        return PC_FAIL;
    }

    /* Configure the MD_WAKE_UP based on the PMIC type */
    REG_OUTF(ulPCBaseAddress, PWR_SEQ_BR_EVENT_CONTROL, MD_WAKE_UP, (ucMDWakeup));
    REG_OUTF(ulPCBaseAddress, PWR_SEQ_BR_EVENT_CONTROL, SAIL_WAKE_UP, (ucSAILWakeup));

    /* APM settings */
    prvPCCoreAPMInit();

    vPCCoreConfFatalErrIsoEnMask();

    vPCCoreConfFatalErrPsHoldEnMask();
	
    /* Configure Wake IRQ Attibutes and Interrupts */
    eStatus = prvPCCoreInterruptInit();
    if (PC_SUCCESS != eStatus)
    {
        return PC_FAIL;
    }

    /* Enable Power Controller glitch sources */
    /* Program SAILSS_PWR_CTRL_PwR_CTRL_SPARE_REG_0[20:2]=0x7FFFF */
    ulRegOut = REG_IN(ulPCBaseAddress, PWR_CTRL_SPARE_REG_0);
    ulRegOut |= (0x7FFFF << 2);
    REG_OUT(ulPCBaseAddress, PWR_CTRL_SPARE_REG_0, ulRegOut);
    /*
    * This config read is enabling customer to control the sleep_en gpio that is going from SAILSS to SAIL PMIC 
    * for some different purpose
    * GPIO_66 on Lemans
    * GPIO_55 on Monaco
    */
    pDTB = fdt_get_dtb();
    if ( NULL != pDTB )
    {
        root_offset = fdt_path_offset(pDTB, "/sailGpioConfig");
        if(root_offset > 0)
        {
            retval_dtb = fdt_getprop_u32(pDTB, root_offset, "sleep_en_gpio", &ulSleepEnGpio);
            if(retval_dtb == 0)
            {
                if(SLEEP_EN_GPIO_CONFIG_PRESENT == ulSleepEnGpio )
                {
                    REG_OUTF(ulPCBaseAddress, SAIL_SLEEP_EN_PAD_CONTROL, SAIL_SLEEP_EN_OE, 0UL);
                    REG_OUTF(ulPCBaseAddress, SAIL_SLEEP_EN_PAD_CONTROL, SAIL_SLEEP_EN_IE, 1UL);
                    DEBUG_LOG(SAIL_WARNING,"[PWR]Slp En Applied\n\r");
                }
            }
        }
    }

    xPCDrvCtx.bPCCoreInitDone = TRUE;
    return PC_SUCCESS;
}

/**********************************************************
 * Loads the sequencer memory in the Power controller Hardware
 *
 *
 * @param type [IN]
 *   Sequencer type to be loaded
 *      - Power controller Sleep Sequencer
 *      - Power controller Crash Sequencer
 *   Address of the buffer holding the sequence
 *   Size of the buffer data in Dwords
 *   Address of the buffer holding the branch address config
 *   Size of the buffer data in Dwords
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
PCCoreStatusType_e xPCCoreLoadSequencer(PCCoreSeqType_e eSeqType,uint32 *puSeqBuffer,uint32 ulSize,
                                        uint32 *puSeqBrAddr, uint32 ulBrCfgSize)
{
    if ((NULL == puSeqBuffer) || (NULL == puSeqBrAddr))
    {
        return PC_FAIL;
    }

    if (PC_SLEEP_SEQUENCE == eSeqType)
    {
        /* PC Sleep Sequencer */

        /* Check if the size of the data exceeds the sequencer memory */
        if (ulSize > (HWIO_SAILSS_PC_SEQ_MEM_m_MAXm+1))
        {
            return PC_FAIL;
        }

        /* Load the Sequencer */
        for (int i=0;i<ulSize;i++)
        {
            HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,i,*puSeqBuffer);
            puSeqBuffer++;
        }

        /* PC Sleep Sequencer Branch Address Config */

        /* Check if the size of the data exceeds the sequencer memory */
        if (ulBrCfgSize > (HWIO_PWR_SEQ_CONFIG_BR_ADDR_b_MAXb+1))
        {
            return PC_FAIL;
        }

        /* Load the Sequencer */
        for (int i=0;i<ulBrCfgSize;i++)
        {
            HWIO_PWR_SEQ_CONFIG_BR_ADDR_b_OUTI(ulPCBaseAddress,i,*puSeqBrAddr);
            puSeqBrAddr++;
        }

        xPCDrvCtx.ePCCoreSeqInit |= PC_SLEEP_SEQUENCE_DONE;
    }
    else if (PC_CRASH_SEQUENCE == eSeqType)
    {
        /* PC Crash Sequencer */

        /* Check if the size of the data exceeds the sequencer memory */
        if (ulSize > (HWIO_SAILSS_CRASH_SEQ_MEM_m_MAXm+1))
        {
            return PC_FAIL;
        }

        /* Load the Sequencer */
        for (int i=0;i<ulSize;i++)
        {
            HWIO_SAILSS_CRASH_SEQ_MEM_m_OUTI(ulPCBaseAddress,i,*puSeqBuffer);
            puSeqBuffer++;
        }


        /* PC Crash Sequencer Branch Address Config */

        /* Check if the size of the data exceeds the sequencer memory */
        if (ulBrCfgSize > (HWIO_CRASH_WAKEUP_CONFIG_BR_ADDR_b_MAXb+1))
        {
            return PC_FAIL;
        }

        /* Load the Sequencer */
        for (int i=0;i<ulBrCfgSize;i++)
        {
            HWIO_CRASH_WAKEUP_CONFIG_BR_ADDR_b_OUTI(ulPCBaseAddress,i,*puSeqBrAddr);
            puSeqBrAddr++;
        }

        xPCDrvCtx.ePCCoreSeqInit |= PC_CRASH_SEQUENCE_DONE;
    }
    else
    {
        return PC_FAIL;
    }

    return PC_SUCCESS;
}

/**********************************************************
 * Configures the Wake IRQ in the Power controller Hardware
 *
 *
 * @param type [IN]
 *   Masks containing the IRQs that should be masked in the Power Controller
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
PCCoreStatusType_e xPCCoreConfigureWakeIRQSource(uint64 ullMask)
{
    /* Check if the core is initialized */
    if (FALSE == xPCDrvCtx.bPCCoreInitDone)
    {
        return PC_FAIL;
    }

    /* Make sure atleast the Crash sequencer is loaded before any other core functions are called after Init and Load Sequencer.
       This is not a requirment but it is better to load the  crash sequencer as early as possible */
    if (!(xPCDrvCtx.ePCCoreSeqInit & PC_CRASH_SEQUENCE_DONE))
    {
        return PC_FAIL;
    }

    /* If SAIL power ready is masked, then wake up is SAIL Wakeup (external wakes or Internal wakes) not PMIC wakeup */
    if ((uint32)ullMask & (1<<PC_SAIL_PWR_RDY))
    {
        /* SAIL Wakeup Case*/

        /* Check if atleast one other IRQ sources are unmasked. Else return fail */
        if (!(~ullMask))
        {
            return PC_FAIL;

        }

        /* Configure the Wake IRQs to enabled */
        REG_OUT(ulPCBaseAddress, WAKE_IRQ_CFG_ENABLE_0, (uint32)~ullMask);
        REG_OUT(ulPCBaseAddress, WAKE_IRQ_CFG_ENABLE_1, (uint32)~(ullMask>>32));


        /* Configure the wakeup as SAIL wakeup and disable SAIL PMIC wakeup  */
        REG_OUTF(ulPCBaseAddress, PWR_SEQ_BR_EVENT_CONTROL, SAIL_PMIC_WAKEUP, 0);
    }
    else
    {
        /* SAIL PMIC Wakeup Case */

        /* Make sure other SAIL wakeup sources are not enabled */
        if (~ullMask & ~(uint64)(1<<PC_SAIL_PWR_RDY))
        {
            /* Other SAIL Wake up sources are enabled. Incorrect configuration */
            return PC_FAIL;
        }

        /* Configure the Wake IRQs to enabled */
        REG_OUT(ulPCBaseAddress, WAKE_IRQ_CFG_ENABLE_0, (uint32)~ullMask);
        REG_OUT(ulPCBaseAddress, WAKE_IRQ_CFG_ENABLE_1, (uint32)~(ullMask>>32));

        /* Configure the wakeup as SAIL PMIC wakeup and disable SAIL wakeup  */
        REG_OUTF(ulPCBaseAddress, PWR_SEQ_BR_EVENT_CONTROL, SAIL_WAKE_UP, 0);
        REG_OUTF(ulPCBaseAddress, PWR_SEQ_BR_EVENT_CONTROL, SAIL_PMIC_WAKEUP, 1);
    }

    xPCDrvCtx.ullWakeIRQCfgMask = ullMask;
    return PC_SUCCESS;
}

/**********************************************************
 * Controls the Power Controller Glitch Source and APM Comparator Enable
 *
 *
 * @param type [IN]
 *   Control for the Power controller Glitch Source and APM Comparator
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
PCCoreStatusType_e xPCCoreCtrlGlitchSrc(boolean bCtrl)
{
    uint32 ulRegOut;

    /* If the sleep status is not active, return failure */
    if (PC_MODE_ACTIVE != xPCDrvCtx.ePCCoreSleepStatus)
    {
        return PC_FAIL;
    }

    if(TRUE == bCtrl)
    {
        /* Enable Power Controller glitch sources */
        /* Program SAILSS_PWR_CTRL_PwR_CTRL_SPARE_REG_0[20:2]=0x7FFFF */
        ulRegOut = REG_IN(ulPCBaseAddress, PWR_CTRL_SPARE_REG_0);
        ulRegOut |= (0x7FFFF << 2);
        REG_OUT(ulPCBaseAddress, PWR_CTRL_SPARE_REG_0, ulRegOut);

        /* Enable APM Comparator */
        /* Program SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_OUT[8] to 0x1 */
        ulRegOut = REG_IN(ulPCBaseAddress, SAIL_CX_APM_FUNC_OUT);
        ulRegOut |= ((uint32)1<<8);
        REG_OUT(ulPCBaseAddress, SAIL_CX_APM_FUNC_OUT, ulRegOut);
    }
    else
    {
        /* Disable APM comparator */
        /* Program SAILSS_PWR_CTRL_SAIL_CX_APM_FUNC_OUT[8] to 0x0 */
        ulRegOut = REG_IN(ulPCBaseAddress, SAIL_CX_APM_FUNC_OUT);
        ulRegOut &= ~((uint32)1<<8);
        REG_OUT(ulPCBaseAddress, SAIL_CX_APM_FUNC_OUT, ulRegOut);

        /* Disable all Island State Detector and Power Controller glitch sources */
        /* Program SAILSS_PWR_CTRL_PwR_CTRL_SPARE_REG_0[20:2]=0x0 */
        ulRegOut = REG_IN(ulPCBaseAddress, PWR_CTRL_SPARE_REG_0);
        ulRegOut &= ~((uint32)0x7FFFF << 2);
        REG_OUT(ulPCBaseAddress, PWR_CTRL_SPARE_REG_0, ulRegOut);
    }

    return PC_SUCCESS;
}

/**********************************************************
 * Power Controller Sleep Sequence Entry
 *
 *
 * @param type [IN]
 *   Sleep type to be configured in the Power controller Hardware
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
PCCoreStatusType_e xPCCoreSleepEnter(PCCoreSleepStatusType_e eMode)
{
    PCCoreStatusType_e eStatus;
    uint64 ullSleepTmrVal = PC_SLEEP_TMR_VAL;
    uint32 ulRegOut = 0x0u;

    if ((FALSE == xPCDrvCtx.bPCCoreInitDone) || (PC_MODE_ACTIVE != xPCDrvCtx.ePCCoreSleepStatus))
    {
        return PC_FAIL;
    }

    /* Make sure PC Sleep and Crash sequencer is loaded before attempting sleep entry */
    if (!( (xPCDrvCtx.ePCCoreSeqInit & PC_CRASH_SEQUENCE_DONE) && (xPCDrvCtx.ePCCoreSeqInit & PC_SLEEP_SEQUENCE_DONE) ))
    {
        return PC_FAIL;
    }

    if ( PC_MODE_DEEPSLEEP == eMode ) // Deep sleep 
    {

        /* Disable all wake up sources in deep sleep case */
        REG_OUT(ulPCBaseAddress,WAKE_IRQ_CFG_ENABLE_0, 0x0);
        REG_OUT(ulPCBaseAddress,WAKE_IRQ_CFG_ENABLE_1, 0x0);

        /* 
         * For deep sleep need to over ride by writing in PWR_CONTROLLER Register
         * 18:pwr_seq_md_to_sail_sleen_en_ack --> sleep enable ack to md from sail
         * 19:pwr_seq_md_to_sail_apm_change_ack --> APM change ack to md from sail
         */

        ulRegOut = REG_IN(ulPCBaseAddress,PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0);
        ulRegOut |= (BIT(18u)|BIT(19u));
        REG_OUT(ulPCBaseAddress,PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0,ulRegOut);

        ulRegOut = REG_IN(ulPCBaseAddress,PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0);
        ulRegOut |= (BIT(18u)|BIT(19u));
        REG_OUT(ulPCBaseAddress,PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0,ulRegOut);

    }else
    {
        /* Clear 'stop_monitoring' bit */
        REG_OUTF(ulPCBaseAddress, WAKE_HANDLER_CFG, STOP_MONITORING, 0);

        /* Start monitoring wakes by programming 'start_monitoring' bit */
        REG_OUTF(ulPCBaseAddress, WAKE_HANDLER_CFG, START_MONITORING, 1);

        /* enable wakeIRQ path in GIC */
        eStatus = prvPCCoreInterruptCtrl(TRUE);
        if (PC_SUCCESS != eStatus)
        {
            return PC_FAIL;
        }

        /* Enable/Disable the Sleep timer based on the configuration */
        if (PC_PMIC_TYPE_MERGED == xPCDrvCtx.ePCCorePMIC)
        {
            /* Disable/dont enable SAIL Power controller sleep timer if Merged PMIC */
            REG_OUTF(ulPCBaseAddress, PWR_CTRL_SLEEP_TMR_CMP_VAL_1, PWR_CTRL_SLEEP_TMR_CMP_EN, 0);
        }
        else if ((PC_PMIC_TYPE_INDEPENDENT == xPCDrvCtx.ePCCorePMIC))
        {
            /* Enable SAIL SAIL Power controller sleep timer if independent PMIC and IRQ for Sleep timer wakeup is enabled */

            if (~(xPCDrvCtx.ullWakeIRQCfgMask) & (1<<PC_PC_SLEEP_TMR_WAKE_IRQ) ) {
                //todo: Dilip Get the TSC0 counter value and then add the Sleep timer val to it
                REG_OUT(ulPCBaseAddress, PWR_CTRL_SLEEP_TMR_CMP_VAL_0,(uint32) ullSleepTmrVal);
                REG_OUTF(ulPCBaseAddress, PWR_CTRL_SLEEP_TMR_CMP_VAL_1, PWR_CTRL_SLEEP_TMR_CMP_VAL_1, (uint32)(ullSleepTmrVal>>32));

                /* Enable the sleep timer */
                REG_OUTF(ulPCBaseAddress, PWR_CTRL_SLEEP_TMR_CMP_VAL_1, PWR_CTRL_SLEEP_TMR_CMP_EN, 0); //Reset the Timer before enabling it
                REG_OUTF(ulPCBaseAddress, PWR_CTRL_SLEEP_TMR_CMP_VAL_1, PWR_CTRL_SLEEP_TMR_CMP_EN, 1);
            }
            else
            {
                /* Disable/dont enable SAIL Power controller sleep timer if not enabled in the wakeup source */
                REG_OUTF(ulPCBaseAddress, PWR_CTRL_SLEEP_TMR_CMP_VAL_1, PWR_CTRL_SLEEP_TMR_CMP_EN, 0);
            }
        }
        else
        {
            /* Unknown PMIC type. Return Failure*/
            return PC_FAIL;
        }

        /* Program Sequencer WDOG time */
        REG_OUT(ulPCBaseAddress, PWR_SEQ_WDOG_BITE_TIME, 0xFFFFF);

        /*Program Wake handler configuration (if any) */

        /* LOW_PWR_MODE reg to indicate sleep_mode(SLEEP or STANDBY) */
        REG_OUTF(ulPCBaseAddress, PWR_SEQ_BR_EVENT_CONTROL, LOW_POWER_MODE, (eMode-1));

        /* Start Sequencer WDOG */
        REG_OUTF(ulPCBaseAddress, PWR_SEQ_WDOG_CTRL_EN_WDOG, ENABLE_THE_WDOG, 1);

        xPCCoreTriggerSequencer(TRUE);
    }

    xPCDrvCtx.ePCCoreSleepStatus = eMode;

    return PC_SUCCESS;
}

/**********************************************************
 * Power Controller Sleep Sequence Exit
 *
 *
 * @param type [IN]
 *   None
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
PCCoreStatusType_e xPCCoreSleepExit(void)
{
    PCCoreStatusType_e eStatus;
    uint32 ulRegOut;

    if (FALSE == xPCDrvCtx.bPCCoreInitDone)
    {
        return PC_FAIL;
    }

    /* Disable Sequencer WDOG */
    REG_OUTF(ulPCBaseAddress, PWR_SEQ_WDOG_CTRL_EN_WDOG, ENABLE_THE_WDOG, 0);

#ifndef PC_EL2_INTERRUPTS_ENABLED

    xPCCoreWakeISRHandler(NULL);

#endif /* PC_EL2_INTERRUPTS_ENABLED */

    /* Disable wakeIRQ path in GIC */
    eStatus = prvPCCoreInterruptCtrl(FALSE);
    if (PC_SUCCESS != eStatus)
    {
        return PC_FAIL;
    }

    xPCDrvCtx.ePCCoreSleepStatus = PC_MODE_ACTIVE;

    xPCCoreTriggerSequencer(FALSE);

    return PC_SUCCESS;
}

/**********************************************************
 * Controls the Power Controller Sequencer Enable
 *
 *
 * @param type [IN]
 *   Control for the Power controller Sequencer
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
PCCoreStatusType_e xPCCoreTriggerSequencer(boolean bCtrl)
{
    if (FALSE == xPCDrvCtx.bPCCoreInitDone)
    {
        return PC_FAIL;
    }

    if (TRUE == bCtrl)
    {
        REG_OUTF(ulPCBaseAddress, PWR_CTRL_CONTROL, SAIL_LOW_PWR_ENTRY, 1);
    }
    else
    {
        REG_OUTF(ulPCBaseAddress, PWR_CTRL_CONTROL, SAIL_LOW_PWR_ENTRY, 0);
    }

    return PC_SUCCESS;
}

/**********************************************************
 * Populates the wake up reason
 *
 *
 * @param type [IN/OUT]
 *   Pointer to Reason mask as input parameter
 *   Mask that provides the reason for the wakeup upon return
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
PCCoreStatusType_e xPCCorePopulateWakeupReason(uint64 *puReason)
{
    if (FALSE == xPCDrvCtx.bPCCoreInitDone)
    {
        *puReason = 0;
        return PC_FAIL;
    }

    /* Wakeup reason might not be accurate if the sleep status is not active.
       Reason will be accurate only if the sleep exit sequence is completed and the ISR has been called


        sleep  irqen
        0       0       --> active, IRQ disabled -> right reason
        0       1       --> active, IRQ enabled  -> Prev reason
        1       0       --> sleep, irq disabled  -> reason or prev reason (treat as fail)
        1       1       --> sleep, irq enabled   -> fail

       */

    if (PC_MODE_ACTIVE != xPCDrvCtx.ePCCoreSleepStatus)
    {
        *puReason = 0;
        return PC_FAIL;
    }

    *puReason = xPCDrvCtx.ullWakeupReason;

    return PC_SUCCESS;
}

/**********************************************************
 * Checks if PC is initialized and ready to enter sleep
 *
 *
 * @param void [IN]
 *   None
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean bPCCoreIsReadyForSleep(void)
{
    if (FALSE == xPCDrvCtx.bPCCoreInitDone)
    {
        return FALSE;
    }

    /* Make sure PC Sleep and Crash sequencer is loaded before attempting sleep entry */
    if (!( (xPCDrvCtx.ePCCoreSeqInit & PC_CRASH_SEQUENCE_DONE) && (xPCDrvCtx.ePCCoreSeqInit & PC_SLEEP_SEQUENCE_DONE) ))
    {
        return FALSE;
    }

    return TRUE;
}

