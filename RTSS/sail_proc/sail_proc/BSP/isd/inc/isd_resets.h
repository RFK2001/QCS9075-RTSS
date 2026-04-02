#ifndef ISD_RESETS_H__
#define ISD_RESETS_H__

/*
===========================================================================
*/
/**
  @file isd_os.h
  @brief Private interface include file for isd internal os abstraction layer.
*/
/*
  ===========================================================================

  Copyright (c) 2022 Qualcomm Technologies Incorporated.  
  All Rights Reserved.
  Qualcomm Proprietary and Confidential.

  ===========================================================================
*/

#include "types.h"


#define ISD_TZ_IPC_NON_SEC_INTR         37U
#define ISD_TZ_IPC_SEC_INTR             38U
#define ISD_TZ_INTR_SAIL_MD_CONFIG_SIZE 31U /* supposed be aligned with ISD_SailMDStatusType */

typedef enum
{
    SECURE_INTR=0,
    NON_SECURE_INTR

}ISD_SailMDIntrType;

typedef enum
{
    MD_SEC_FUSE_HR,
    MD_SW_CR,
    MD_VSENSE_STATUS,
    MD_SOC_WR,
    MD_WR_SAIL_ISLAND,
    MD_DDR_READY,
    MD_AUTH_FAIL_SWITCH_LUN_HR,
    MD_FORCE_EDL,
    MD_FAILURE_FORCE_PASS2,
    MD_RESET_READY,
    MD_GRACEFUL_SHUTDOWN,
    XBLSEC_BOOT_SUCCESS,
    XBLLDR_BOOT_SUCCESS,
    TZ_BOOT_SUCCESS,
    QHEE_BOOT_SUCCESS,
    UEFI_BOOT_SUCCESS,
    ABL_BOOT_SUCCESS,
    MD_SOC_HR,
	MD_SAIL_LPM_DDR_SUSPEND,
    MD_S1_READY,
	MD_MB_READY,
    SAIL_SEC_FUSE_HR,
    SAIL_VSENSE_READY,
    SAIL_RESET_READY,
    SAIL_RGMII_VOL_SEL,
    SAIL_SW_CR,
    SAIL_TEST_MANAGER_MODE,
    SAIL_ISLAND_READY,
    SAIL_OSPI_MD_CTRL,
    SAIL_SDI_DISABLED,
    MD_SOC_SDI_DISABLE,
    SAIL_QAMV4_DETECTION,

    /*
     * Note : Add Any entry above this
     * Issue Description :- On warm/ cold boot path ISD driver will populated missed
     * Shadow register config from MD. On warm boot path shadow register config will
     * be populated to STR and ISD API will fill up Sleep queue with STR information
     * as last shadow register config was STR and SAIL will enter into sleep again.
     * To avoid such cases STR/Deep Sleep ENUM is expected to have highest value in
     * ISD_SailMDStatusType
     */
    
    STR_COMM_TO_SAIL,
    MD_SOC_DEEP_SLEEP,
    ISD_TaskStatesMAX

}ISD_SailMDStatusType;

typedef struct
{
    ISD_SailMDStatusType eIntrReason;
    uint32         value;
}ISD_IntrConfigType;
/* ISD RTOS Queue Msg Type*/

typedef struct
{
    ISD_SailMDIntrType   eIntrType;
    isdStatesType_e stStatus;
}ISD_QueueMsgType;

extern void prvIPCNonSecISR(void *args);
extern void prvIPCNonSecISR_CB(void *args);
extern void prvTZIPCSecISR(void *args);
extern void prvTZIPCSecISR_CB(void *args);
extern void prvISDSetSAILMDAck(uint32 nStatus);
extern void prvISD_MDIntrHandler(ISD_DriverContext_t **pISDContext, ISD_SailMDStatusType nResetReason);
extern void prvISD_IPCCIntrHandler(isdStatesType_e state);
extern void prvISD_ISDStateHandler(ISD_DriverContext_t *pContxt, isdStatesType_e state);
static uint32 prvISDGetMDStatus(void);

#endif