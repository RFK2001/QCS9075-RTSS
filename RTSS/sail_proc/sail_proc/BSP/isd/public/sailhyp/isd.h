#ifndef ISD_H_
#define ISD_H_

/**
 * @file isd.h
 * @brief
 * Header file for ISD driver of sail
 *
 *        Copyright (c) 2021 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include "types.h"

#define ISD_SAIL_MAX_CPUS                       0x4U
#define ISD_UNUSED_PARAMETER(x)                 ((void)(x))

#define ISD_CORE_0                               (0U)
#define ISD_CORE_1                               (1U)
#define ISD_CORE_2                               (2U)

/* enum to store different states of isd driver*/
typedef enum 
{
    UNDEFINED_STATE = 0,
    ISLAND_STATE,
    NORMAL_STATE,
    SOC_WARM_RESET,
    SOC_SHUTDOWN,
    SOC_EDL,
    SOC_HARD_RESET,
    SOC_CRASH_RESET,
}isdStatesType_e;

/* enum to store different result codes to detect errors*/
typedef enum{
    ISD_NOT_INITIALISED = -10,
    ISD_INVALID_FPTR,
    ISD_INSUFFICIENT_MEMORY,
    ISD_FPTR_EXISTS,
    ISD_NOT_OK,
    ISD_OK = 0,
}isdResultsType_e;

/* enum to store fatal error codes */
typedef enum
{
    MD_PS_HOLD_EN = 0,
    MD_PMIC_FAULT_N_EN,
    SAIL_RESIN_N_EN,
    VS_FUSA_ERR0_EN,
    VS_FUSA_ERR1_EN,
    TSENSE_PS_HOLD_ARES0_EN,
    TSENSE_PS_HOLD_ARES1_EN,
    SAIL_R52_WDOG_BITE_EN,
    SAIL_SEQ_WDOG_BITE_EN,
    SAIL_ERROR_EN,
    SPARE_FATAL_EN,
}isdFataErrType_e;

typedef enum
{
    ISD_FATAL_ERR_INACTIVE = 0,
    ISD_FATAL_ERR_ACTIVE   = 1,
    ISD_FATA_ERR_INVALID   = 2
}isdFatalErrMaskType;

/* enum to store different isolation types*/
typedef enum
{
    ISD_SAIL_FROM_MD_CX_ISO_EN = 0,
    ISD_SAIL_FROM_MD_CX_ISO_EN_CLK,
    ISD_SAIL_FROM_MD_CX_ISO_EN_DFT,
    ISD_SAIL_FROM_MD_CX_ISO_EN_DEBUG,
    ISD_SAIL_FROM_MD_MXA_ISO_EN,
    ISD_SAIL_FROM_MD_MXA_ISO_EN_CLK,
    ISD_SAIL_FROM_MD_MXA_ISO_EN_DFT,
    ISD_SAIL_FROM_MD_MXA_ISO_EN_DEBUG,
    ISD_SAIL_ISO_TYPE_MAX,
}isdIsolationTypes_e;

typedef enum
{
    ISD_ISOALTION_DISABLE = 0,
    ISD_ISOLATION_EN      = 1,
    ISD_ISOLATION_INVALID = 2
}isdIsolationStateType_e;


typedef enum 
{
    ISD_MD2SAIL_STATUS_FAILED = 0,
    XBL_SEC_BOOT_SECCESS = 1,
    DDR_READY,
    XBL_LOADER_BOOT_SUCCESS,
    MD_VSENSE_SUCCESS,
    TZ_SUCCESS,
    QHEE_SUCCESS,
    UEFI_SUCCESS,
    ABL_SUCCESS,
	LPM_DDR_SUSPEND_SUCCESS,
    S1_READY_SUCCESS,
	MB_READY_SUCCESS,
    
}isdStatusType_e;

typedef enum 
{
    ISD_GET_XBL_SEC_STATUS = 0,
    ISD_GET_DDR_STATUS,
    ISD_GET_XBL_LOADER_STATUS,
    ISD_GET_VSENSE_STATUS,
    ISD_GET_TZ_STATUS,
    ISD_GET_QHEE_STATUS,
    ISD_GET_UEFI_STATUS,
    ISD_GET_ABL_STATUS,
	ISD_GET_LPM_DDR_SUSPEND_STATUS,
    ISD_GET_S1_READY_STATUS,
    ISD_GET_MB_READY_STATUS,
}isdGetStatusType_e;

/* callback function ptr type*/
typedef void  (*ISD_ClientNotificationCallbackFn)( const isdStatesType_e eState, void *pCBData);

/* global functions declarations*/
isdResultsType_e eISDSWOverrideIsolationsCtrl(uint8 value);        /* API used to override isolation control from HW */
isdResultsType_e eISDSWIsolationsEnableAll(void);
isdResultsType_e eISDEnableIsolations(void);                /* API used to enter Island Mode */
isdResultsType_e eISDDisableIsolations(void);               /* API used to exit Island Mode */
isdResultsType_e eISDSailPSHoldAssert(void);                /* API used to assert SAIL_PS_HOLD */
isdResultsType_e eISDSailPSHoldDeAssert(void);              /* API used to de-assert SAIL_PS_HOLD */
isdResultsType_e eISDSailToMDPSHoldFlwMDPSHold(void);    /* API used to assert SAIL_TO_MD_PS_HOLD */
isdResultsType_e eISDSailToMDPSHoldDeAssert(void);          /* API used to de-assert SAIL_TO_MD_PS_HOLD */
isdStatesType_e  eISDGetCurrentState(void);                 /* API used to get current state of SAIL */
isdResultsType_e eISDFatalError(uint32 nIntr);              /* API used to notify ISD Driver when a fatal error occurs */
uint32 ISDGetSailPSHoldFatalErrStatus(void);             /* API used to get iso en fatal error status */
uint32 nISDGetIsoEnFatalErrorStatus(void);                  /* API used to get sail_ps_hold fatal error status */
isdResultsType_e eISDConfigFatalErrIsoEnMask(
                    isdFataErrType_e eFatalErr, 
                    isdFatalErrMaskType eFatalErrMask);     /* API used to set fatal error mask for iso en */
isdResultsType_e eISDCfgFatalErrSailPsHoldMask(
                    isdFataErrType_e eFatalErr, 
                    isdFatalErrMaskType eFatalErrMask);     /* API used to set fatal error mask for sail_ps_hold de-assertion */
isdResultsType_e eISDSetIsolationState(
                    isdIsolationTypes_e eIso,
                    isdIsolationStateType_e eState);        /* API to enable/disable isoaltions individually*/
isdIsolationStateType_e eISDGetIsolationState(
                    isdIsolationTypes_e eIso);              /* API to get individual isolation status*/
isdResultsType_e eISDDeregisterNotification(
                    ISD_ClientNotificationCallbackFn pCB);
isdResultsType_e eISDRegisterNotification(
                    ISD_ClientNotificationCallbackFn pCB,  
                    void *pCBData);
extern boolean eISDDrv_QAMV4Present(void);                        /* API used to get QAMV4 info */
extern isdStatusType_e eISDGetStatus(isdGetStatusType_e eGetStatus);
void vISDInit(void);                                        /* API used to initialise ISD Driver */
void eISDNotifyAll(const isdStatesType_e eNewState);        /* API to notify registered clients about non-fatal error */
void eISDSetStateinDriverContext(isdStatesType_e eNewState);/* API to update new ISD state in ISD driver context, 
															in case of SOC reset initiated from SAIL */
void eISD_InitiateResetFrmSail(isdStatesType_e state);      /* API to initiate SOC reset from SAIL */
void eISD_InitiateEDLentryFrmSail(isdStatesType_e state, uint32_t image_id);      /* API to initiate EDL entry -SOC warm reset from SAIL */
extern isdResultsType_e prvISDSendIPCCInterrupt(void);                  /* API to send IPCC interrupt between SAIL cores */
extern isdResultsType_e eISDDeInit(void);
extern isdStatusType_e eISDSetCustomMDEvStatus(isdStatusType_e eSetStatus);
extern void vISDInitSMP(void);
#endif
