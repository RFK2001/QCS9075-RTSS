/*==============================================================================

FILE:      NOC_error.c

DESCRIPTION: This file implements NOC Error Handler.

PUBLIC CLASSES:  Not Applicable

INITIALIZATION AND SEQUENCING REQUIREMENTS:  N/A

Edit History

When        Who    What, where, why
----------  ---    ----------------------------------------------------------- 
    Copyright (c) 2023-2024 Qualcomm Technologies, Inc.
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
==============================================================================*/
#include "icb_error.h"
#include "sail_csr_hwio.h"
#include "Clock.h"
#include "debug_log.h"
#include "freertos_init.h"
#include "spinor_el1_api.h"
#include "chipinfo.h"
//#include "fusa_serv.h"
//#include "fusa.h"
#include "err_fatal.h"
#include "common_functions.h"
#include "FreeRTOSOsal.h"
#include "interrupts.h"
#include "syscall_hvc.h"
#include "syscall_svc.h"
#include "syscall_pub.h"
#include "syscall.h"
/*============================================================================
                          DEFINEs
============================================================================*/
#define NOC_OUT32(addr, data)  (*((volatile uint32_t *) (addr)) = ((uint32_t) (data)))
#define NOC_ERROR_LOG_MAX_SIZE_SPINOR  4096U /* SPINOR reserved  for Error log store */
#define NOCERROR_RECORD_SIZE           112U
/*============================================================================
**             Global typedefs : Enums, Structures Union and other typedefs **
=============================================================================*/

/* Available NOC ISR in SAIL subsystem */
typedef enum{
    ICB_NOC_FUNCTIONAL_FAULT = 0U,
    ICB_NOC_FUSA_ERROR =1U,
    ICB_NOC_FUSA_WARRNING=2U,
    ICB_INT_PER_NOC =3U
} ICB_NOC_Int_Type;


/* Available NOC in SAIL subsystem */
typedef enum{
    ICB_ASIL_D_NOC = 0U,
    ICB_ASIL_B_NOC = 1U,
    ICB_ASIL_D_ISO_NOC = 2U,
    ICB_ASIL_B_ISO_NOC = 3U,
    ICB_NOC_NUM = 4U,
    INVALID_WWDT_ID = 0xFFU,
} ICB_NOC_Type;

/* Available NOC ISR config data in SAIL subsystem */
typedef struct{
    ICB_NOC_Type ICB_NOC;
    uint32_t int_num;
    uint32_t int_cfg; /* Level or edge */
    InterruptHandle_t icb_int_handler;
    uint32_t int_priority;
} ICB_NOC_IRQ_Config_Type;
#if 0
/* Available NOC ISR mapping to Fusa config data in SAIL subsystem */
typedef struct{
    ICB_NOC_Type Icb_Noc;
    uint32_t Icb_IrqNum;
    FUSAErrorID_e Icb_FusaErrorId;
    FUSAErrorSource_e Icb_FusaErrorSrc;
    FUSAErrorType_e Icb_FusaErrorType;
    uint32_t Icb_SailFusaErrorStatus_Addr;
    uint32_t Icb_SailFusaErrorStatus_BMSK;
} ICB_NocIrqFusaMapTbl_Type;

static volatile FUSAQueueMsgType Icb_NocErrorFUSAQueueMsg = { 0 } ;
#endif
static ICB_DATA ICB_SailNocErrorLogToFuSa_type ICB_SailNocErrorLogToFuSa;
/*=============================================================================
**                                   Local function prototypes               **
==============================================================================*/

NOC_FUNC void NOC_Error_InterruptHandle(void* arg);
NOC_FUNC static void NOC_Error_InterruptHandle_CB(void* arg);
NOC_FUNC static void ICB_NOCError_cfg(ICB_NOC_Type Icb_NocName);
NOC_FUNC uint32_t icb_hvc(uint32_t int_num);
/*============================================================================
                        DEVICE CONFIG PROPERTY DATA
============================================================================*/
/* SAIL NOC ISR table */
/* 0 left shift by 3 = 0,  0 is 1st highest priority So config values is 0   */
/* 1 left shift by 3 = 8,  1 is 2nd highest priority,So config values is 8   */
/* 2 left shift by 3 = 16,  2 is 3rd highest priority, So config values is 16*/
static ICB_NOC_IRQ_Config_Type ICB_NOC_IRQ_Config_Tbl[ICB_NOC_NUM][ICB_INT_PER_NOC] =
{
    {
        {.ICB_NOC=ICB_ASIL_D_NOC, .int_num = (uint32_t)73U, .int_cfg = (uint32_t)0U, .icb_int_handler = (InterruptHandle_t)NOC_Error_InterruptHandle, .int_priority =16U},
        {.ICB_NOC=ICB_ASIL_D_NOC, .int_num = (uint32_t)79U, .int_cfg = (uint32_t)0U, .icb_int_handler = (InterruptHandle_t)NOC_Error_InterruptHandle, .int_priority =0U},
        {.ICB_NOC=ICB_ASIL_D_NOC, .int_num = (uint32_t)81U, .int_cfg = (uint32_t)0u, .icb_int_handler = (InterruptHandle_t)NOC_Error_InterruptHandle, .int_priority =8U},
    },
    {
        {.ICB_NOC=ICB_ASIL_B_NOC, .int_num = (uint32_t)54U, .int_cfg = (uint32_t)0U, .icb_int_handler = (InterruptHandle_t)NOC_Error_InterruptHandle, .int_priority =16U},
        {.ICB_NOC=ICB_ASIL_B_NOC, .int_num = (uint32_t)57U, .int_cfg = (uint32_t)0U, .icb_int_handler = (InterruptHandle_t)NOC_Error_InterruptHandle, .int_priority =0U},
        {.ICB_NOC=ICB_ASIL_B_NOC, .int_num = (uint32_t)58U, .int_cfg = (uint32_t)0u, .icb_int_handler = (InterruptHandle_t)NOC_Error_InterruptHandle, .int_priority =8U},
    },
    {
        {.ICB_NOC=ICB_ASIL_D_ISO_NOC, .int_num = (uint32_t)70U, .int_cfg = (uint32_t)0U, .icb_int_handler = (InterruptHandle_t)NOC_Error_InterruptHandle, .int_priority =16U},
        {.ICB_NOC=ICB_ASIL_D_ISO_NOC, .int_num = (uint32_t)74U, .int_cfg = (uint32_t)0U, .icb_int_handler = (InterruptHandle_t)NOC_Error_InterruptHandle, .int_priority =0U},
        {.ICB_NOC=ICB_ASIL_D_ISO_NOC, .int_num = (uint32_t)77U, .int_cfg = (uint32_t)0u, .icb_int_handler = (InterruptHandle_t)NOC_Error_InterruptHandle, .int_priority =8U},
    },
    {
        {.ICB_NOC=ICB_ASIL_B_ISO_NOC, .int_num = (uint32_t)52U, .int_cfg = (uint32_t)0U, .icb_int_handler = (InterruptHandle_t)NOC_Error_InterruptHandle, .int_priority =16U},
        {.ICB_NOC=ICB_ASIL_B_ISO_NOC, .int_num = (uint32_t)59U, .int_cfg = (uint32_t)0U, .icb_int_handler = (InterruptHandle_t)NOC_Error_InterruptHandle, .int_priority =0U},
        {.ICB_NOC=ICB_ASIL_B_ISO_NOC, .int_num = (uint32_t)60U, .int_cfg = (uint32_t)0u, .icb_int_handler = (InterruptHandle_t)NOC_Error_InterruptHandle, .int_priority =8U},
    }
};
#if 0
/* SAIL Functional fault and FuSa Error and Warning table  table */
const static ICB_NocIrqFusaMapTbl_Type ICB_NocIrqFusaMapTbl[ICB_NOC_NUM][ICB_INT_PER_NOC] =
{
    {
        {.Icb_Noc= ICB_ASIL_D_NOC, .Icb_IrqNum=73U,  .Icb_FusaErrorId=FUSA_OTHER_ERRORS, .Icb_FusaErrorSrc= U_ASILD_NOC, .Icb_FusaErrorType= FUSA_ERROR,
        /* FUSA_ERROR_STATUS_2[15]->Signal Name:asild_noc_sail_fusa_error_irq ->Signal Source:u_sail_asil_d_noc ->RTCU SPI[47] */
         .Icb_SailFusaErrorStatus_Addr=HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_ADDR,  .Icb_SailFusaErrorStatus_BMSK=0x8000U                           },
        {.Icb_Noc= ICB_ASIL_D_NOC, .Icb_IrqNum=79U,  .Icb_FusaErrorId=FUSA_ERROR_215,    .Icb_FusaErrorSrc=U_ASILD_NOC, .Icb_FusaErrorType=FUSA_ERROR,
        /* FUSA_ERROR_STATUS_2[15]->Signal Name:asild_noc_sail_fusa_error_irq ->Signal Source:u_sail_asil_d_noc ->RTCU SPI[47] */
         .Icb_SailFusaErrorStatus_Addr=HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_ADDR,  .Icb_SailFusaErrorStatus_BMSK=0x8000U                           },
        {.Icb_Noc= ICB_ASIL_D_NOC, .Icb_IrqNum=81U,  .Icb_FusaErrorId=FUSA_WARN_428,     .Icb_FusaErrorSrc= U_ASILD_NOC, .Icb_FusaErrorType=FUSA_WARNING,
        /* FUSA_ERROR_STATUS_4[28]       ->Signal Name:asild_noc_sail_fusa_warning_irq ->Signal Source:u_sail_asil_d_noc ->RTCU SPI[49] */
         .Icb_SailFusaErrorStatus_Addr=HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_4_ADDR,  .Icb_SailFusaErrorStatus_BMSK=0x10000000U                           },
    },
    {
        {.Icb_Noc= ICB_ASIL_B_NOC, .Icb_IrqNum=54U,  .Icb_FusaErrorId=FUSA_OTHER_ERRORS, .Icb_FusaErrorSrc=U_ASILB_NOC, .Icb_FusaErrorType=FUSA_ERROR,
        /*FUSA_ERROR_STATUS_2[8]        ->Signal Name:asil_b_noc_sail_fusa_error_irq ->Signal Source:u_sail_asil_b_noc ->RTCU SPI[25] */
         .Icb_SailFusaErrorStatus_Addr=HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_ADDR,  .Icb_SailFusaErrorStatus_BMSK=0x100U                           },
        {.Icb_Noc= ICB_ASIL_B_NOC, .Icb_IrqNum=57U,  .Icb_FusaErrorId=FUSA_ERROR_28,     .Icb_FusaErrorSrc=U_ASILB_NOC, .Icb_FusaErrorType=FUSA_ERROR,
        /*FUSA_ERROR_STATUS_2[8]        ->Signal Name:asil_b_noc_sail_fusa_error_irq ->Signal Source:u_sail_asil_b_noc ->RTCU SPI[25] */
         .Icb_SailFusaErrorStatus_Addr=HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_ADDR,  .Icb_SailFusaErrorStatus_BMSK=0x100U                           },
        {.Icb_Noc= ICB_ASIL_B_NOC, .Icb_IrqNum=58U,  .Icb_FusaErrorId=FUSA_WARN_424,     .Icb_FusaErrorSrc=U_ASILB_NOC, .Icb_FusaErrorType=FUSA_WARNING,
        /*FUSA_ERROR_STATUS_4[24]       ->Signal Name:asil_b_noc_sail_fusa_warning_irq ->Signal Source:u_sail_asil_b_noc ->RTCU SPI[27] */
         .Icb_SailFusaErrorStatus_Addr=HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_4_ADDR,  .Icb_SailFusaErrorStatus_BMSK=0x1000000U                           },
    },
    {
      {.Icb_Noc= ICB_ASIL_D_ISO_NOC, .Icb_IrqNum=70U,  .Icb_FusaErrorId=FUSA_OTHER_ERRORS, .Icb_FusaErrorSrc=U_ASILD_ISO_NOC, .Icb_FusaErrorType= FUSA_ERROR,
      /* FUSA_ERROR_STATUS_2[16]       ->Signal Name:asil_d_isolation_sail_fusa_error_irq ->Signal Source:u_sail_asil_d_noc ->RTCU SPI[42] */
       .Icb_SailFusaErrorStatus_Addr=HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_ADDR,  .Icb_SailFusaErrorStatus_BMSK=0x10000U                           },
      {.Icb_Noc= ICB_ASIL_D_ISO_NOC, .Icb_IrqNum=74U,  .Icb_FusaErrorId=FUSA_ERROR_216,    .Icb_FusaErrorSrc=U_ASILD_ISO_NOC, .Icb_FusaErrorType=FUSA_ERROR,
      /* FUSA_ERROR_STATUS_2[16]       ->Signal Name:asil_d_isolation_sail_fusa_error_irq ->Signal Source:u_sail_asil_d_noc ->RTCU SPI[42] */
       .Icb_SailFusaErrorStatus_Addr=HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_ADDR,  .Icb_SailFusaErrorStatus_BMSK=0x10000U                           },
      {.Icb_Noc= ICB_ASIL_D_ISO_NOC, .Icb_IrqNum=77U,  .Icb_FusaErrorId=FUSA_WARN_427,     .Icb_FusaErrorSrc=U_ASILD_ISO_NOC, .Icb_FusaErrorType= FUSA_WARNING,
      /* FUSA_ERROR_STATUS_4[27]       ->Signal Name:asil_d_isolation_sail_fusa_warning_irq ->Signal Source:u_sail_asil_d_noc ->RTCU SPI[45] */
       .Icb_SailFusaErrorStatus_Addr=HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_4_ADDR,  .Icb_SailFusaErrorStatus_BMSK=0x8000000U                           },
    },
    {
      {.Icb_Noc= ICB_ASIL_B_ISO_NOC, .Icb_IrqNum=52U,  .Icb_FusaErrorId=FUSA_OTHER_ERRORS, .Icb_FusaErrorSrc=U_ASILB_ISO_NOC, .Icb_FusaErrorType=FUSA_ERROR,
      /*FUSA_ERROR_STATUS_2[9]        ->Signal Name:asil_b_isolation_sail_fusa_error_irq ->Signal Source:u_sail_asil_b_noc ->RTCU SPI[26] */
       .Icb_SailFusaErrorStatus_Addr=HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_ADDR,  .Icb_SailFusaErrorStatus_BMSK=0x200U                           },
      {.Icb_Noc= ICB_ASIL_B_ISO_NOC, .Icb_IrqNum=59U,  .Icb_FusaErrorId=FUSA_ERROR_29,     .Icb_FusaErrorSrc=U_ASILB_ISO_NOC, .Icb_FusaErrorType=FUSA_ERROR,
      /*FUSA_ERROR_STATUS_2[9]        ->Signal Name:asil_b_isolation_sail_fusa_error_irq ->Signal Source:u_sail_asil_b_noc ->RTCU SPI[26] */
       .Icb_SailFusaErrorStatus_Addr=HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_2_ADDR,  .Icb_SailFusaErrorStatus_BMSK=0x200U                           },
      {.Icb_Noc= ICB_ASIL_B_ISO_NOC, .Icb_IrqNum=60U,  .Icb_FusaErrorId=FUSA_WARN_425,     .Icb_FusaErrorSrc=U_ASILB_ISO_NOC, .Icb_FusaErrorType= FUSA_WARNING,
      /* FUSA_ERROR_STATUS_4[25]       ->Signal Name:asil_b_isolation_sail_fusa_warning_irq ->Signal Source:u_sail_asil_b_noc ->RTCU SPI[28] */
       .Icb_SailFusaErrorStatus_Addr=HWIO_SAILSS_CSR_FUSA_ERROR_STATUS_4_ADDR,  .Icb_SailFusaErrorStatus_BMSK=0x2000000U                           },
    },
};
#endif
/*===========================================================================*/
/**
@brief
       Function to write NOC error log into  SPINOR.

@param[in]  NOCERR_info_type noc_info A point to the NoC to log

@return
      None.

@dependencies
      None.

@sideeffects
      None.
*/
/*==============================================================================*/
uint8_t ICB_NocErrLogData_WtToSpiNOR (NOCERRORrecordType *xMsg )
{
    uint8_t xRetStatus = 1U;
    spinor_handle_t handle = NULL;
    ICB_DATA static uint32 write_offset = 0x0U;
    SPINOR_STATUS WtToSpiNOR_result = 0x1;
    spinorMemInfoType WtToSpiNOR_el1_nor_info={0};
    uint32 ulbyteoffset_icb = 0x0U;
    uint32 ulbyteCount = 0x0U;

    if (xMsg == NULL)
    {
        DEBUG_LOG(SAIL_ERROR,"[ICB]: NULL pointer was passed to ICB_NocErrLogData_WtToSpiNOR()\n\r");
        return 0;
    }

    uint8_t icb_buffer[NOCERROR_RECORD_SIZE];
    (void)memset(icb_buffer, 0, NOCERROR_RECORD_SIZE);
    (void)sailbsp_memscpy(icb_buffer, NOCERROR_RECORD_SIZE, xMsg, sizeof(NOCERRORrecordType));
    WtToSpiNOR_result = spinorEl1Open(&handle,SPINOR_USER_TYPE_EL1);

    if( WtToSpiNOR_result != SPINOR_DEVICE_DONE || handle == NULL)
    {
        DEBUG_LOG(SAIL_ERROR,"[ICB]: Open handle failed\n\r");
        return 0U;
    }

    WtToSpiNOR_result = spinorEl1GetMemInfo ( handle, &WtToSpiNOR_el1_nor_info );
    if( WtToSpiNOR_result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"[ICB]:GetMemInfo failed \n\r");
        xRetStatus = 0U;
        goto ErrSPINOR;
    }

    WtToSpiNOR_result = spinorEl1GetGptPartitionInfo( handle, "c45bc0f4-7869-4286-acdd-144e70c3f6b3", &ulbyteoffset_icb, &ulbyteCount);
    if( WtToSpiNOR_result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"[ICB]:GetGptPartitionInfo failed \n\r");
        xRetStatus = 0U;
        goto ErrSPINOR;
    }

    if (ulbyteCount < ( write_offset + NOCERROR_RECORD_SIZE ))
    {
        DEBUG_LOG(SAIL_ERROR,"[ICB]:Write failed\r\n");
        xRetStatus = 0U;
        goto ErrSPINOR;
    }

    WtToSpiNOR_result = spinorEl1Write ( handle, write_offset + ulbyteoffset_icb, NOCERROR_RECORD_SIZE, icb_buffer );
    if(WtToSpiNOR_result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"[ICB]:Write failed\r\n");
        xRetStatus = 0;
        goto ErrSPINOR;
    }
    write_offset = write_offset + NOCERROR_RECORD_SIZE;

    ErrSPINOR:
    WtToSpiNOR_result = spinorEl1Close(handle);
    if(WtToSpiNOR_result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"[ICB]:Close failed\r\n");
        xRetStatus = 0;
    }
    DEBUG_LOG(SAIL_WARNING,"[ICB]:xRetStatus = %d   WtToSpiNOR_result = %d \r\n", xRetStatus, WtToSpiNOR_result);
    return xRetStatus;
}

NOC_FUNC static void NOC_Error_InterruptHandle_CB(void* arg)
{
    ICB_NOC_IRQ_Config_Type *ICB_NOC_IRQ_ErrConfig = (ICB_NOC_IRQ_Config_Type *) arg;
    uint32_t intr_vector = ICB_NOC_IRQ_ErrConfig->int_num;
    uint32_t int_idx = 0x0U;
    uint32_t noc_idx = 0x0U;
    uint32_t fault_detected = icb_hvc(intr_vector);
#if 0
    for(noc_idx = 0x0U; noc_idx < (uint8_t)ICB_NOC_NUM; noc_idx++)
    {
        for(int_idx = 0x0U; int_idx < (uint8)ICB_INT_PER_NOC; int_idx++)
        {
            if(ICB_NOC_IRQ_Config_Tbl[noc_idx][int_idx].int_num == intr_vector )
            {
              Icb_NocErrorFUSAQueueMsg.eEventDomain = SAILSS;
              Icb_NocErrorFUSAQueueMsg.ulPayloadLen  = sizeof(ICB_SailNocErrorLogToFuSa_type);
              Icb_NocErrorFUSAQueueMsg.pvDebugInfo = (void *)&ICB_SailNocErrorLogToFuSa ;//ICB_SAILNOC_ErrorLog;
              /* FuSa Error and FuSa warning ISR reporting to SSM  */
              /* int_idx = 1 is error, int_idx = 2 is warning */
              if (fault_detected == 0x0U)
              {
                  Icb_NocErrorFUSAQueueMsg.eEventId =ICB_NocIrqFusaMapTbl[noc_idx][int_idx].Icb_FusaErrorId;
                  Icb_NocErrorFUSAQueueMsg.eEventSource=ICB_NocIrqFusaMapTbl[noc_idx][int_idx].Icb_FusaErrorSrc;
                  Icb_NocErrorFUSAQueueMsg.eEventType =ICB_NocIrqFusaMapTbl[noc_idx][int_idx].Icb_FusaErrorType;
                  if( vFusaSMErrorUnMaskedFromISR( (uint8_t) Icb_NocErrorFUSAQueueMsg.eEventId) == FUSA_SUCCESS)
                  {
                       /* Assert SM Error Pin*/
                       AssertSMErr(true, SMErr_BSP_TRIG_REQ, Icb_NocErrorFUSAQueueMsg.eEventId);
                  }
                  /* Clear Error Indication at the the SAIL EAM */
                  NOC_OUT32(ICB_NocIrqFusaMapTbl[noc_idx][int_idx].Icb_SailFusaErrorStatus_Addr, ICB_NocIrqFusaMapTbl[noc_idx][int_idx].Icb_SailFusaErrorStatus_BMSK );
                  vFUSAMsgSendToSMFromISR( Icb_NocErrorFUSAQueueMsg);
              }
              /* 0xD -->1101*/ /* Correctable faults are treated has a Warning  */
              /* safety fault detected without FuSa ISR direct functional fault detected */
              /* 0th pos cflt, 2nd pos is Done and 3rd pos bist flt  */
              else if( fault_detected == 0x1U)
              {  
                  Icb_NocErrorFUSAQueueMsg.eEventId =ICB_NocIrqFusaMapTbl[noc_idx][int_idx].Icb_FusaErrorId;
                  Icb_NocErrorFUSAQueueMsg.eEventSource=ICB_NocIrqFusaMapTbl[noc_idx][int_idx].Icb_FusaErrorSrc;
                  Icb_NocErrorFUSAQueueMsg.eEventType =FUSA_WARNING;
                  vFUSAMsgSendToSMFromISR( Icb_NocErrorFUSAQueueMsg);
              }
              /* 1st Pos Uflt */ /* Un-Correctable faults are treated has a Error  */
              else if( fault_detected == 0x2U)
              {  
                  Icb_NocErrorFUSAQueueMsg.eEventId =ICB_NocIrqFusaMapTbl[noc_idx][int_idx].Icb_FusaErrorId;
                  Icb_NocErrorFUSAQueueMsg.eEventSource=ICB_NocIrqFusaMapTbl[noc_idx][int_idx].Icb_FusaErrorSrc;
                  Icb_NocErrorFUSAQueueMsg.eEventType =FUSA_ERROR;
                  vFUSAMsgSendToSMFromISR( Icb_NocErrorFUSAQueueMsg);
              }
              /*  Sbm Pos:0 - uflt, Pos:1- Cflt, Pos:2- ERL fault*/
              /* Un-Correctable side band faults are treated has a Error*/
              else if( fault_detected == 0x3U)
              {
                   Icb_NocErrorFUSAQueueMsg.eEventId =ICB_NocIrqFusaMapTbl[noc_idx][int_idx].Icb_FusaErrorId;
                   Icb_NocErrorFUSAQueueMsg.eEventSource=ICB_NocIrqFusaMapTbl[noc_idx][int_idx].Icb_FusaErrorSrc;
                   Icb_NocErrorFUSAQueueMsg.eEventType = FUSA_ERROR;//ICB_NocIrqFusaMapTbl[noc_idx][int_idx].Icb_FusaErrorType;
                   vFUSAMsgSendToSMFromISR( Icb_NocErrorFUSAQueueMsg);
              }
              /* Timeout fault, ERL and correctable are Warning  */
              else if( fault_detected == 0x4U)
              {
                   Icb_NocErrorFUSAQueueMsg.eEventId =ICB_NocIrqFusaMapTbl[noc_idx][int_idx].Icb_FusaErrorId;
                   Icb_NocErrorFUSAQueueMsg.eEventSource=ICB_NocIrqFusaMapTbl[noc_idx][int_idx].Icb_FusaErrorSrc;
                   Icb_NocErrorFUSAQueueMsg.eEventType = FUSA_WARNING;//ICB_NocIrqFusaMapTbl[noc_idx][int_idx].Icb_FusaErrorType;
                   vFUSAMsgSendToSMFromISR( Icb_NocErrorFUSAQueueMsg);
              }
              else
              {
                   // MISRA C rquired comment
              }
            }
        }
    }
#endif
    NOCERRORrecordType xMsg = { 0 };
    (void)sailbsp_memscpy(&xMsg.nocErrVal,sizeof(ICB_SailNocErrorLogToFuSa_type),&ICB_SailNocErrorLogToFuSa,sizeof(ICB_SailNocErrorLogToFuSa_type));
    xMsg.magicNumber = ICB_MAGIC_NUMBER;
    BaseType_t xQReturn = pdFAIL;
    xQReturn = xFreeRTOSQueueSendFromISR(xIcbQueueHandle, &xMsg);
    if (pdPASS != xQReturn){
        DEBUG_LOG(SAIL_ERROR,"[ICB]:xQueueSendFromISR failed\r\n");
    }else{
        freertosYIELD_FROM_ISR(); 
    }
}

NOC_FUNC void NOC_Error_InterruptHandle(void* arg)
{
    /* Freertos ISR handles FPU registers save/restore. */
    NOC_Error_InterruptHandle_CB(arg);
}

//*============================================================================*/
/**
@brief
      Performs initialization for NOC ISR Handler.
      It enables interrupts required to handle NOC errors.

@param[in]  None.

@return
      None.

@dependencies
      None.

@sideeffects
      None.
*/
/*============================================================================*/

NOC_FUNC static void ICB_NOCError_cfg(ICB_NOC_Type Icb_NocName)
{
    for (uint8_t Icb_NocIntNum = 0U ; Icb_NocIntNum< (uint8_t)ICB_INT_PER_NOC; Icb_NocIntNum++)
    {
            (void)xGicSetIntEnable(ICB_NOC_IRQ_Config_Tbl[Icb_NocName][Icb_NocIntNum].int_num, (boolean)FALSE);
            
			(void)xGicConfigureInt(ICB_NOC_IRQ_Config_Tbl[Icb_NocName][Icb_NocIntNum].int_num, (uint32_t)ICB_NOC_IRQ_Config_Tbl[Icb_NocName][Icb_NocIntNum].int_cfg, NULL);
			
            (void)xGicRegisterIntHandler(ICB_NOC_IRQ_Config_Tbl[Icb_NocName][Icb_NocIntNum].int_num, ICB_NOC_IRQ_Config_Tbl[Icb_NocName][Icb_NocIntNum].icb_int_handler,
                                                               (void*)&ICB_NOC_IRQ_Config_Tbl[Icb_NocName][Icb_NocIntNum]);
															   
            (void) xGicSetIntPriority(ICB_NOC_IRQ_Config_Tbl[Icb_NocName][Icb_NocIntNum].int_num, ICB_NOC_IRQ_Config_Tbl[Icb_NocName][Icb_NocIntNum].int_priority);
            (void)xGicSetIntEnable(ICB_NOC_IRQ_Config_Tbl[Icb_NocName][Icb_NocIntNum].int_num, (boolean)TRUE);
    }
}


//*============================================================================*/
/**
@brief
      Performs initialization for NOC Error Handler.
      It enables interrupts required to handle NOC errors.

@param[in]  None.

@return
      None.

@dependencies
      None.

@sideeffects
      None.
*/
/*============================================================================*/

NOC_FUNC void icb_el1_init( void )
{
    uint32_t i;
    // Get device property data for configuration

    /* BIST is taken care NOC diagnostic So below call is commented  */
    /* NOC_Error_Init_Target(NOCInfo, NOCERR_propdata->len,  NOCInfoOEM); */

    /* Enable timeout clocks */
    /*
    for(i = 0; i < NOCERR_propdata->num_clock_regs; i++)
    {
        NOC_OUT32(NOCERR_propdata->clock_reg_addrs[i], NOCERR_propdata_oem->clock_reg_vals[i]);
    }
    */
    for(i=0U; i < (uint8_t)ICB_NOC_NUM ; i++)
    {
        ICB_NOCError_cfg((ICB_NOC_Type)i);
    }
}

uint8_t ICB_NOCErr_SPINOR_readAndClear(void)
{
    spinor_handle_t handle = NULL;
    SPINOR_STATUS WtToSpiNOR_result = 0x1;
    spinorMemInfoType WtToSpiNOR_el1_nor_info={0};
    uint8_t xRetStatus = 1U;
    uint32 ulbyteoffset_icb = 0x0U;
    uint32 ulbyteCount = 0x0U;
    uint32 block_byte_size = 0x0U;
    char ICB_message_buffer[800] = {0};

    uint8_t icb_buffer[NOCERROR_RECORD_SIZE];

    WtToSpiNOR_result = spinorEl1Open(&handle,SPINOR_USER_TYPE_EL1);
    if( WtToSpiNOR_result != SPINOR_DEVICE_DONE || handle == NULL)
    {
        DEBUG_LOG(SAIL_ERROR,"[ICB]: Open handle failed\n\r");
        return 0U;
    }

    WtToSpiNOR_result = spinorEl1GetMemInfo( handle, &WtToSpiNOR_el1_nor_info );
    if( WtToSpiNOR_result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"[ICB]:GetMemInfo failed \n\r");
        xRetStatus = 0U;
        goto ErrSPINOR;
    }

    WtToSpiNOR_result = spinorEl1GetGptPartitionInfo( handle, "c45bc0f4-7869-4286-acdd-144e70c3f6b3", &ulbyteoffset_icb, &ulbyteCount);
    if( WtToSpiNOR_result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"[ICB]:GetGptPartitionInfo failed \n\r");
        xRetStatus = 0U;
        goto ErrSPINOR;
    }

    WtToSpiNOR_result = spinorEl1Read( handle, ulbyteoffset_icb, NOCERROR_RECORD_SIZE, icb_buffer);
    if( WtToSpiNOR_result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"[ICB]:Read failed \n\r");
        xRetStatus = 0U;
        goto ErrSPINOR;
    }

    block_byte_size = WtToSpiNOR_el1_nor_info.pages_per_block * WtToSpiNOR_el1_nor_info.page_size_bytes;
    NOCERRORrecordType* nocErrRecord;
    nocErrRecord = (NOCERRORrecordType*) icb_buffer;
    uint32 read_offset = 0x0U;

    while (nocErrRecord->magicNumber == ICB_MAGIC_NUMBER)
    {
        (void)snprintf (ICB_message_buffer, sizeof(ICB_message_buffer),
            "NOC ERROR from previous boot, NOC_ID = 0x%X   \n\r"
            "ERRLOG0_LOW  = 0x%X      \n\r"
            "ERRLOG0_HIGH = 0x%X      \n\r"
            "ERRLOG1_LOW  = 0x%X      \n\r"
            "ERRLOG1_HIGH = 0x%X      \n\r"
            "ERRLOG2_LOW  = 0x%X      \n\r"
            "ERRLOG2_HIGH = 0x%X      \n\r"
            "ERRLOG3_LOW  = 0x%X      \n\r"
            "ERRLOG3_HIGH = 0x%X      \n\r"
            "FAULTINSTATUS0_LOW   = 0x%X       \n\r"
            "FAULTINSTATUS0_HIGH  = 0x%X       \n\r"
            "FAULTINSTATUS1_LOW   = 0x%X       \n\r"
            "FAULTINSTATUS1_HIGH  = 0x%X       \n\r"
            "FAULTINSTATUS0_LOW_2   = 0x%X       \n\r"
            "FAULTINSTATUS0_HIGH_2  = 0x%X       \n\r"
            "FAULTINSTATUS1_LOW_2   = 0x%X       \n\r"
            "FAULTINSTATUS1_HIGH_2  = 0x%X       \n\r"
            "STATUS_LOW  = 0x%X       \n\r"
            "CFLTA_LOW  = 0x%X       \n\r"
            "CFLTA_HIGH = 0x%X       \n\r"
            "UFLTA_LOW  = 0x%X       \n\r"
            "UFLTA_HIGH = 0x%X       \n\r"
            "CFLTB_LOW  = 0x%X       \n\r"
            "CFLTB_HIGH = 0x%X       \n\r"
            "UFLTB_LOW  = 0x%X       \n\r"
            "UFLTB_HIGH = 0x%X       \n\r", 
            nocErrRecord->nocErrVal.NOC_ID,
            nocErrRecord->nocErrVal.ERRLOG0_LOW,
            nocErrRecord->nocErrVal.ERRLOG0_HIGH,
            nocErrRecord->nocErrVal.ERRLOG1_LOW,
            nocErrRecord->nocErrVal.ERRLOG1_HIGH,
            nocErrRecord->nocErrVal.ERRLOG2_LOW,
            nocErrRecord->nocErrVal.ERRLOG2_HIGH,
            nocErrRecord->nocErrVal.ERRLOG3_LOW,
            nocErrRecord->nocErrVal.ERRLOG3_HIGH,
            nocErrRecord->nocErrVal.FAULTINSTATUS0_LOW,
            nocErrRecord->nocErrVal.FAULTINSTATUS0_HIGH,
            nocErrRecord->nocErrVal.FAULTINSTATUS1_LOW,
            nocErrRecord->nocErrVal.FAULTINSTATUS1_HIGH,
            nocErrRecord->nocErrVal.FAULTINSTATUS0_LOW_2,
            nocErrRecord->nocErrVal.FAULTINSTATUS0_HIGH_2,
            nocErrRecord->nocErrVal.FAULTINSTATUS1_LOW_2,
            nocErrRecord->nocErrVal.FAULTINSTATUS1_HIGH_2,
            nocErrRecord->nocErrVal.STATUS_LOW,
            nocErrRecord->nocErrVal.CFLTA_LOW,
            nocErrRecord->nocErrVal.CFLTA_HIGH,
            nocErrRecord->nocErrVal.UFLTA_LOW,
            nocErrRecord->nocErrVal.UFLTA_HIGH,
            nocErrRecord->nocErrVal.CFLTB_LOW,
            nocErrRecord->nocErrVal.CFLTB_HIGH,
            nocErrRecord->nocErrVal.UFLTB_LOW,
            nocErrRecord->nocErrVal.UFLTB_HIGH);
        DEBUG_LOG(SAIL_ERROR,"\n\r%s\n\r",ICB_message_buffer);

        (void)memset(icb_buffer, 0, NOCERROR_RECORD_SIZE);
        read_offset = read_offset + NOCERROR_RECORD_SIZE ;
        if ( ulbyteCount < read_offset)
        {
            break;
        }
        WtToSpiNOR_result = spinorEl1Read( handle, ulbyteoffset_icb+read_offset, NOCERROR_RECORD_SIZE, icb_buffer);
        nocErrRecord = (NOCERRORrecordType*) icb_buffer;
        if( WtToSpiNOR_result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG(SAIL_ERROR,"[ICB]:Read failed \n\r");
            xRetStatus = 0U;
            goto ErrSPINOR;
        }

    }
    if (read_offset != 0x0U)
    {
        DEBUG_LOG(SAIL_WARNING,"[ICB]:NOC error from the previous boot\r\n");

        WtToSpiNOR_result = spinorEl1Erase (handle, ulbyteoffset_icb/block_byte_size, ulbyteCount/block_byte_size);
        if( WtToSpiNOR_result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG(SAIL_ERROR,"[ICB]:Erase failed \n\r");
            xRetStatus = 0;
            goto ErrSPINOR;
        }
    }

    ErrSPINOR:
    WtToSpiNOR_result = spinorEl1Close(handle);
    if(WtToSpiNOR_result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"[ICB]:Close failed\r\n");
        xRetStatus = 0;
    }

    return xRetStatus;
}

uint32_t icb_hvc(uint32_t int_num)
{
    uint32_t hvcId = 0;
    uint32_t paramId = 0;
    uint32_t arg1 = int_num;
    uint32_t arg2 = (uint32_t)&ICB_SailNocErrorLogToFuSa ;
    uint32_t arg3 = 0;
    uint32_t arg4 = 0;
    hvcId = (uint32_t)ICB_HVC_ID;
    paramId = (uint32_t)ICB_PARAM_ID;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( 0 != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) ) //HVC_SUCCESS: 0
        {
            DEBUG_LOG(SAIL_ERROR, "icb hvc call failed\n\r");
        }
    }
    return paramId;
}
/*******************************************************************************
**                                  End of file NOC_Error.c                   **
******************************************************************************/
