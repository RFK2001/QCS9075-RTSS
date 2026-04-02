#ifndef ISD_DRV_H_
#define ISD_DRV_H_

/**
 * @file isd_drv.h
 * @brief
 * Private Header file for ISD driver of sail
 *
 *        Copyright (c) 2022 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "isd.h"
#include "isd_os.h"
#include "common_functions.h"
#include "IPCC.h"
#ifndef SAILEL2
#include "freertos_init.h"
#endif
#include "sailbsp_mutex.h"

#ifndef SAILEL2
#define ISD_FUNC  __attribute__ ( ( section ( "isd_func" ) ) )
#else
#define ISD_FUNC
#endif


#define QAMV4_PRESENT                           1u
#define ISD_GET_CURRENT_CORE()                  get_curr_phys_cpu_num()
#define ISD_SAIL_MAX_NOTIFY_CLIENTS             50U
#define ISD_MD_FATAL_ERR_SW_INTR                0x0U
#define ISD_MD_PS_HOLD_FUSA_ERR                 605U
#define ISD_PRIMARY_CORE                        0x0U

#define SAILBSP_CSR_REG_ADDR_BASE    (void *)SAILSS_CSR_SAILSS_CSR_BASE
#define SAILBSP_CSR_REG_ADDR_SIZE            SAILSS_CSR_SAILSS_CSR_BASE_SIZE
#define SAILBSP_ISD_REG_ADDR_BASE  (void *)SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_BASE
#define SAILBSP_ISD_REG_ADDR_SIZE          SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_BASE_SIZE
#define ISD_DATA __attribute__ ( ( section ( "isd_data" ) ) )

typedef struct 
{
    ISD_ClientNotificationCallbackFn pCB;
    void *pCBData;
}isdNotificationDataType;

typedef struct 
{
    isdNotificationDataType eDataArray[ISD_SAIL_MAX_NOTIFY_CLIENTS];
    int8_t nTail;
}isdNotificationListType;

/* context type of ISD driver*/
typedef struct
{
    //ISDOSMutex         stLock;
    //ISDOSMutex         stCoreLock[ISD_SAIL_MAX_CPUS];
    mutex_t         stLock;
    mutex_t         stCoreLock[ISD_SAIL_MAX_CPUS];
    isdStatesType_e    isdState;
    isdNotificationListType eNotifyData[ISD_SAIL_MAX_CPUS];
    IPCC_Handle         eISDIPCCHandle[ISD_SAIL_MAX_CPUS];
    isdStatusType_e eISDStatus;
    uint32_t MD_IntrReason;
    uint8_t QAMV4_Present;
}ISD_DriverContext_t;

extern isdResultsType_e eISDDrv_DeregisterNotification
(
    ISD_DriverContext_t *pISDDriverContext, 
    ISD_ClientNotificationCallbackFn pCB
);

extern isdResultsType_e eISDDrv_RegisterNotification
(
    ISD_DriverContext_t *pISDDriverContext, 
    ISD_ClientNotificationCallbackFn pCB, 
    void *pCBData
);

extern uint32 eISD_GetMDBootErrorCode(void);

/* Linker Symbols */
#if defined(__ARM_GNU__)
    extern ISD_DriverContext_t lnk_shr_isd_context;
    #define ISD_CONTEXT_BASE_ADDRESS            (&lnk_shr_isd_context)
    #define ISD_CONTEXT_BASE_ADDRESS_COPY       ISD_CONTEXT_BASE_ADDRESS

    extern uint32_t  lnk_isd_data_start_addr;
    extern uint32_t  lnk_isd_data_end_addr;
    #define SAILBSP_ISD_DATA_ADDR_BASE          (void *)(&lnk_isd_data_start_addr)
    #define SAILBSP_ISD_DATA_ADDR_SIZE          (uint32_t)((uint32_t)(&lnk_isd_data_end_addr) - (uint32_t)(&lnk_isd_data_start_addr))

#elif defined(__ARM_FUSA__)
    extern ISD_DriverContext_t Image$$SHR_ISDCONTEXT$$RO$$Base;
    #define ISD_CONTEXT_BASE_ADDRESS            (&Image$$SHR_ISDCONTEXT$$RO$$Base)
    #define ISD_CONTEXT_BASE_ADDRESS_COPY       ISD_CONTEXT_BASE_ADDRESS
    
    extern uint32_t  Image$$lnkISDDATAStartAddr$$ZI$$Base;
    extern uint32_t  Image$$lnkISDDATAEndAddr$$ZI$$Base;
    #define SAILBSP_ISD_DATA_ADDR_BASE          (void *)&Image$$lnkISDDATAStartAddr$$ZI$$Base
    #define SAILBSP_ISD_DATA_ADDR_SIZE          (uint32_t)( (uint32_t)&Image$$lnkISDDATAEndAddr$$ZI$$Base  -\
                                                                (uint32_t)&Image$$lnkISDDATAStartAddr$$ZI$$Base )
#else
    #error "Unknown Linker Symbols Format"
#endif

#endif
