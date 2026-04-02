#ifndef  ICBERROR_H
#define  ICBERROR_H
/*============================================================================

FILE:      icb_error.h

DESCRIPTION: Initialization for ICB bus error handlers

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
============================================================================*/
#include "types.h"
#include "freertos_init.h"
/*===========================================================================
                          DEFINEs/MACROs
============================================================================*/
#define ICB_DATA __attribute__ ( ( section ( "icb_data" ) ) )
#define NOC_FUNC __attribute__ ( ( section ( "noc_func" ) ) )


/* Make Sure These Addresses Are Aligned To 64 Bytes */
ICB_DATA extern uint32_t Image$$lnkICBDATAStartAddr$$Base;
ICB_DATA extern uint32_t Image$$lnkICBDATAEndAddr$$Base;

#define SAILBSP_ICB_DATA_ADDR_BASE      (void *)&Image$$lnkICBDATAStartAddr$$Base
#define SAILBSP_ICB_DATA_ADDR_SIZE      (uint32_t)( (uint32_t)&Image$$lnkICBDATAEndAddr$$Base -\
                                                          (uint32_t)&Image$$lnkICBDATAStartAddr$$Base )
#define ICB_MAGIC_NUMBER 0xAAAA6785U
/*============================================================================
                          TYPE DEFINITION
============================================================================*/

typedef struct{
	uint32_t NOC_ID; /* 0: ASIL-D, 1: ASIL-B, 2:ASIL-D ISO, 3: ASIL: B ISO*/
	uint32_t ERRLOG0_LOW;
	uint32_t ERRLOG0_HIGH;
	uint32_t ERRLOG1_LOW;
	uint32_t ERRLOG1_HIGH;
	uint32_t ERRLOG2_LOW;
	uint32_t ERRLOG2_HIGH;
	uint32_t ERRLOG3_LOW;
	uint32_t ERRLOG3_HIGH;
	uint32_t FAULTINSTATUS0_LOW;
	uint32_t FAULTINSTATUS0_HIGH;
	uint32_t FAULTINSTATUS1_LOW;
	uint32_t FAULTINSTATUS1_HIGH;
	uint32_t FAULTINSTATUS0_LOW_2;
	uint32_t FAULTINSTATUS0_HIGH_2;
	uint32_t FAULTINSTATUS1_LOW_2;
	uint32_t FAULTINSTATUS1_HIGH_2;
	uint32_t STATUS_LOW;
	uint32_t CFLTA_LOW;
	uint32_t CFLTA_HIGH;
	uint32_t UFLTA_LOW;
	uint32_t UFLTA_HIGH;
	uint32_t CFLTB_LOW;
	uint32_t CFLTB_HIGH;
	uint32_t UFLTB_LOW;
	uint32_t UFLTB_HIGH;
}ICB_SailNocErrorLogToFuSa_type;

typedef struct
{
	uint32_t magicNumber;
	uint32_t reserved;
	ICB_SailNocErrorLogToFuSa_type nocErrVal; 
}NOCERRORrecordType;

typedef enum
{
      ICB_ERROR_NOT_OCCURED = 0,
      ICB_ERROR_OCCURED
}ICB_ErrType;

extern  QueueHandle_t       xIcbQueueHandle;
extern  TaskHandle_t xIcbTaskHandle;
/*============================================================================
                                 FUNCTIONS
============================================================================*/
BaseType_t xIcb_LogResourcesInit(CPUIdType_e xSchdCore);
BaseType_t xIcbTaskInit(CPUIdType_e xSchdCore, UBaseType_t xTaskPrior);


//*============================================================================*/
/**
@brief
      Log the NOC error information to SPINOR.

@param xMsg [in]: NOCERRORrecordType.

@return
      0 -> SPINOR logging success
      1 -> SPINOR logging failure

@dependencies
      None.

@sideeffects
      None.
*/
/*============================================================================*/
uint8_t ICB_NocErrLogData_WtToSpiNOR (NOCERRORrecordType *xMsg );

//*============================================================================*/
/**
@brief
      Read NOC the error information from SPINOR.

@param[in]  None.

@return
      0 -> SPINOR operation success
      1 -> SPINOR operation failure

@dependencies
      None.

@sideeffects
      None.
*/
/*============================================================================*/
uint8_t ICB_NOCErr_SPINOR_readAndClear(void);
//*============================================================================*/
/**
@brief 
      Initializes all ICB bus error drivers.
 
@param[in]  None.

@return    
      None.

@dependencies
      None.
 
@sideeffects 
      None. 
*/ 
/*============================================================================*/
void icb_el1_init(void);

#endif /* __ICBERROR_H__ */
