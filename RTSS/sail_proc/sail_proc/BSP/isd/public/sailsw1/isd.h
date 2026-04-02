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

#ifndef SAILEL2

#define ISD_FUNC  __attribute__ ( ( section ( "isd_func" ) ) )

#else
#define ISD_FUNC
#endif

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "target.h"
#include "FreeRTOSOsal.h"
#include "freertos_init.h"
#define ISD_SAIL_MAX_CPUS                       SAILBSP_CPU_COUNT
#define ISD_TASK_INSTANCE                       ( 3U )
#define ISD_QUEUE_INSTANCE                      ( 3U )
#define ISD_MASTER_CORE                         ( 0U )



#define ISD_CORE_0                               (0U)
#define ISD_CORE_1                               (1U)
#define ISD_CORE_2                               (2U)

#define ISD_UNUSED_PARAMETER(x)                 ((void)(x))
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
    SOC_DEEP_SLEEP
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
	/* new event should be insterted here if any to correct functioning of get status API */
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
	ISD_GET_MB_READY_STATUS
}isdGetStatusType_e;




/* callback function ptr type*/
typedef void  (*ISD_ClientNotificationCallbackFn)( const isdStatesType_e eState, void *pCBData);


/* Queue handle of ISD driver */
extern QueueHandle_t xISDQueueHandle[ISD_QUEUE_INSTANCE]; 
/* global functions declarations*/
extern isdResultsType_e eISDDisableIsolations(void);               /* API used to exit Island Mode */
extern isdResultsType_e eISDSailPSHoldDeAssert(void);              /* API used to de-assert SAIL_PS_HOLD */
extern isdResultsType_e eISDSailToMDPSHoldFlwMDPSHold(void);    /* API used to assert SAIL_TO_MD_PS_HOLD */
extern isdResultsType_e eISDSailToMDPSHoldDeAssert(void);          /* API used to de-assert SAIL_TO_MD_PS_HOLD */
extern isdResultsType_e eISDFatalError(uint32 nIntr);              /* API used to notify ISD Driver when a fatal error occurs */
extern uint32 GetIsoEnFatalErrStatus(void);                  /* API used to get sail_ps_hold fatal error status */
extern isdResultsType_e eISDConfigFatalErrIsoEnMask(isdFataErrType_e eFatalErr, isdFatalErrMaskType eFatalErrMask);     /* API used to set fatal error mask for iso en */
extern isdResultsType_e CfgFatalErrSailPsHoldMask(isdFataErrType_e eFatalErr,isdFatalErrMaskType eFatalErrMask);     /* API used to set fatal error mask for sail_ps_hold de-assertion */
extern isdResultsType_e eISDSetIsolationState(isdIsolationTypes_e eIso,isdIsolationStateType_e eState);        /* API to enable/disable isoaltions individually*/
extern isdIsolationStateType_e eISDGetIsolationState(isdIsolationTypes_e eIso);              /* API to get individual isolation status*/
extern isdResultsType_e eISDDeregisterNotification(ISD_ClientNotificationCallbackFn pCB);
extern isdResultsType_e eISDRegisterNotification(ISD_ClientNotificationCallbackFn pCB,void *pCBData);
extern boolean eISDDrv_QAMV4Present(void);                        /* API used to get QAMV4 info */
extern ISD_FUNC isdStatesType_e  eISDGetCurrentState(void);
extern ISD_FUNC isdResultsType_e eISDSWOverrideIsoCtrl(uint8 value);
extern ISD_FUNC isdResultsType_e eISDSWIsolationsEnableAll(void);
extern ISD_FUNC isdResultsType_e eISDEnableIsolations(void);
extern isdStatusType_e eISDGetStatus(isdGetStatusType_e eGetStatus);
extern uint32_t eISDGetMDIntrReason(void);
extern ISD_FUNC isdResultsType_e eISDSailPSHoldAssert(void);
extern ISD_FUNC uint32 GetSailPSHoldFatalErrStatus(void);
extern void vISDInit(void);                                        /* API used to initialise ISD Driver */

extern BaseType_t xISDTaskInit( CPUIdType_e  xSchdCore,UBaseType_t  xTaskPrior );
extern BaseType_t xISDSMPTaskInit( CPUIdType_e xSchdCore,UBaseType_t  xTaskPrior );
extern void vISDSetSAILMDAck(uint32 nStatus);
extern isdResultsType_e prvISDSendIPCCInterrupt(void);                         /* API to send IPCC interrupt between SAIL cores */
extern void vISDUpdatePendingEventStatus( void );
extern ISD_FUNC isdResultsType_e eISDDeInit(void);
extern ISD_FUNC void vISDInitSMP(void);
extern ISD_FUNC void vISDTask(void* arg);
extern ISD_FUNC void vISDSMPTask(void* arg);
#endif
