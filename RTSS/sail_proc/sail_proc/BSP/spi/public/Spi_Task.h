/**********************************************************************************************************
    Copyright (c) 2024 Qualcomm Technologies, Inc.
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
    File Name          : Spi_Task.h
    Component Name     : AutoSAR SPI BSW Module
    Description        : All types mentioned in AUTOSAR_SWS_SPIHandlerDriver.pdf are added in this file
	                     AutoSAR 11/22
    $Header: //components/dev/autosar.sail/1.0/rsargar.autosar.sail.1.0.spicheckintest1/BSW/MCAL/Spi/inc/Spi.h#1 $
    $DateTime: 2024/02/23 04:27:20 $
    $Author: rsargar $
=========================================================================================================*/
#ifndef SPI_TASK_H
#define SPI_TASK_H
/*==============================================================================
**                      Include Section                                       **
==============================================================================*/
extern BaseType_t xSPIXferHandlerTaskInit( CPUIdType_e           xSchdCore,
                                        UBaseType_t  spiXFERHNDLR_TASK_PRIORITY );
extern BaseType_t xSPISEQMsgQueueInit( CPUIdType_e xSchdCore );
#include "Spi_PBcfg.h"


#endif /* SPI_TASK_H */
/* End Of File */
