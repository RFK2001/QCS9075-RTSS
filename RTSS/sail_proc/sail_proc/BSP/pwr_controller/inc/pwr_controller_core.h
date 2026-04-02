
#ifndef __PWR_CONTROLLER_CORE_H__
#define __PWR_CONTROLLER_CORE_H__

/*
===========================================================================
*/
/**
    @file  pwr_controller_core.h
    @brief This file provides definitions for the Power Controller core support functions.

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/pwr_controller/inc/pwr_controller_core.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "types.h"

/* Return Types for the Core operations */
typedef enum
{
   PC_SUCCESS,                   /* Success */
   PC_FAIL                       /* Failure */
}PCCoreStatusType_e;

/* Power Controller Sequencer Type */
typedef enum
{
   PC_SLEEP_SEQUENCE,            /* Sleep Sequence */
   PC_CRASH_SEQUENCE,            /* Crash Sequence */
}PCCoreSeqType_e;

/* Status of the Sequencer Initalization */
typedef enum
{
   PC_SEQUENCE_UNINIT,           /* Sequencer Not initalized */
   PC_SLEEP_SEQUENCE_DONE,       /* Sleep Sequencer loaded */
   PC_CRASH_SEQUENCE_DONE        /* Crash Sequencer loaded */
}PCCoreSeqStatusType_e;

/* Sleep Status of the Power controller driver */
typedef enum
{
   PC_MODE_ACTIVE,               /* Active mode */
   PC_MODE_STANDBY_SET,          /* Standby mode */
   PC_MODE_SLEEP_SET,             /* Sleep mode */
   PC_MODE_DEEPSLEEP_SET          /* Deep Sleep mode */
}PCCoreSleepStatusType_e;

/* PMIC type */
typedef enum
{
   PC_PMIC_TYPE_UNKNOWN,         /* PMIC type not defined */
   PC_PMIC_TYPE_INDEPENDENT,     /* Independent PMIC */
   PC_PMIC_TYPE_MERGED           /* Merged PMIC */
}PCCorePMICType_e;

/* PC Wake IRQ Sources */
typedef enum
{

    /*
        WAKE_IRQ_STATUS_0
            0 : sail_pwr_rdy
            1 :  pc_sleep_tmr_wake_irq
            2 :  md_secure_wdog_bite
            3 :  aodap_pc_csyspwrupreq
            4 :  md_sleep_tmr_expiry
            5 :  pi_srst_n
            6 :  eud_pc_srst_n
            7 :  swao_pc_srst_n
            8 :  sail_pwr_ctrl_irq_core_in_mx_gpio_2
            9  : sail_pwr_ctrl_irq_core_in_mx_gpio_7
            10 : sail_pwr_ctrl_irq_core_in_mx_gpio_10
            11 : sail_pwr_ctrl_irq_core_in_mx_gpio_15
            12 : sail_pwr_ctrl_irq_core_in_mx_gpio_16
            13 : sail_pwr_ctrl_irq_core_in_mx_gpio_17
            14 : sail_pwr_ctrl_irq_core_in_mx_gpio_18
            15 : sail_pwr_ctrl_irq_core_in_mx_gpio_21
            16 : sail_pwr_ctrl_irq_core_in_mx_gpio_38
            17 : sail_pwr_ctrl_irq_core_in_mx_gpio_40
            18 : sail_pwr_ctrl_irq_core_in_mx_gpio_42
            19 : sail_pwr_ctrl_irq_core_in_mx_gpio_44
            20 : sail_pwr_ctrl_irq_core_in_mx_gpio_46
            21 : sail_pwr_ctrl_irq_core_in_mx_gpio_48
            22 : sail_pwr_ctrl_irq_core_in_mx_gpio_50
            23 : sail_pwr_ctrl_irq_core_in_mx_gpio_52
            24 : sail_pwr_ctrl_irq_core_in_mx_gpio_53
            25 : sail_pwr_ctrl_irq_core_in_mx_gpio_54
            26 : sail_pwr_ctrl_irq_core_in_mx_gpio_55
            27 : sail_pwr_ctrl_irq_core_in_mx_gpio_56
            28 : sail_pwr_ctrl_irq_core_in_mx_gpio_57
            29 : sail_pwr_ctrl_irq_core_in_mx_gpio_58
            30 : sail_pwr_ctrl_irq_core_in_mx_gpio_59
            31 : sail_pwr_ctrl_irq_core_in_mx_gpio_60

        WAKE_IRQ_STATUS_1
            0 : sail_pwr_ctrl_irq_core_in_mx_gpio_61
            1 : sail_pwr_ctrl_irq_core_in_mx_gpio_62
            2 : sail_pwr_ctrl_irq_core_in_mx_gpio_63
            3 : sail_pwr_ctrl_irq_core_in_mx_gpio_64
            4 : sail_pwr_ctrl_irq_core_in_mx_gpio_65
            31:5 : <spare>
    */
  PC_SAIL_PWR_RDY = 0,             /*  0 : sail_pwr_rdy            */
  PC_PC_SLEEP_TMR_WAKE_IRQ = 1,    /*  1 :  pc_sleep_tmr_wake_irq  */
  PC_MD_SECURE_WDOG_BITE = 2,      /*  2 :  md_secure_wdog_bite    */
  PC_AODAP_PC_CSYSPWRUPREQ = 3,    /*  3 :  aodap_pc_csyspwrupreq  */
  PC_MD_SLEEP_TMR_EXPIRY = 4,      /*  4 :  md_sleep_tmr_expiry    */
  PC_PI_SRST_N = 5,                /*  5 :  pi_srst_n              */
  PC_EUD_PC_SRST_N = 6,            /*  6 :  eud_pc_srst_n          */
  PC_SWAO_PC_SRST_N = 7,           /*  7 :  swao_pc_srst_n         */
  PC_GPIO_WAKES = 8,
  PC_WAKEUP_SRC_MAX = 37

}PCCoreWakeIRQSrcType_e;

/* Power Controller Driver Context */
typedef struct
{
  boolean                  bPCCoreInitDone;          /* Status of the PC Core Initialization */
  PCCoreSeqStatusType_e    ePCCoreSeqInit;           /* Status of the PC Sequencer Initalization */
  PCCoreSleepStatusType_e  ePCCoreSleepStatus;       /* Status of the current Sleep status configured */
  PCCorePMICType_e         ePCCorePMIC;              /* Type of PMIC */
  uint64_t                 ullWakeIRQCfgMask;        /* Configuration for the wakeIRQ mask */
  uint64_t                 ullWakeupReason;          /* Last read wakeup reason */
  boolean                  bWakeIRQEnabled;          /* WakeIRQ enable status in GIC */
}PCCoreDrvInfoType_e;

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
PCCoreStatusType_e xPCDrvInit(void);

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
PCCoreStatusType_e xPCCoreInit(PCCorePMICType_e pmic_type);

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
                                        uint32 *puSeqBrAddr, uint32 ulBrCfgSize);

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
PCCoreStatusType_e xPCCoreConfigureWakeIRQSource(uint64 mask);

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
PCCoreStatusType_e xPCCoreCtrlGlitchSrc(boolean bCtrl);

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
PCCoreStatusType_e xPCCoreSleepEnter(PCCoreSleepStatusType_e mode);

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
PCCoreStatusType_e xPCCoreSleepExit(void);

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
PCCoreStatusType_e xPCCoreTriggerSequencer(boolean ctrl);

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
PCCoreStatusType_e xPCCorePopulateWakeupReason(uint64 *reason);

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
boolean bPCCoreIsReadyForSleep(void); 

#endif /* __PWR_CONTROLLER_CORE_H__ */
