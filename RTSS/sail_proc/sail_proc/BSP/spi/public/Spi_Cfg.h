/* VendorSpecifc File Header */
/**********************************************************************************************************
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
**********************************************************************************************************/

/*=========================================================================================================
    File Name          : Spi_Cfg.h
    Component Name     : AutoSAR SPI BSW Module
    Description        : Spi_Cfg.h file generated for AUTOSAR_SWS_SPIHandlerDriver.pdf implementation
	                     AutoSAR R22-11
    $Header: $
    $DateTime: $
    $Author: $
=========================================================================================================*/

#ifndef SPI_CFG_H
#define SPI_CFG_H

/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/


/*=========================================================================================================
**                                         defines and macros                                            **
=========================================================================================================*/
/*
* @brief : Switches the development error detection and notification on or off.
* @implements :   
*                 STD_ON: if STD_ON, detection and notification is enabled.
*                 STD_OFF: if STD_OFF, detection and notification is disabled.
* @Requirements : 
*/
#define SPI_DEBUG_MODE 				0x0

/* LEVEL 0 - Simple sync
*	LEVEL 1 - Basic async
*	LEVEL 2 - Enhanced mode
*/
#define SPI_LEVEL_DELIVERED 				2

/* Selects the SPI Handler/Driver Channel Buffers usage allowed and delivered.
*	LEVEL 0 - Only Internal buffers
*	LEVEL 1 - Only external buffers
*	LEVEL 2 - Both internal/external buffers
*/
#define SPI_CHANNEL_BUFFERS_ALLOWED 		1

#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT FALSE

#define SPI_JOB_DELIMITER                     ((uint16)0xFFFFU)
  /* Sequence Delimiter, marks end of Sequence */
#define SPI_SEQUENCE_DELIMITER                ((uint8)0xFFU)
  /* Channel Delimiter, marks the end of channel */
#define SPI_CHANNEL_DELIMITER                 ((uint8)0xFFU)
  /* QSPI HW Delimiter, marks the end of QSPI module */
#define SPI_QSPI_HW_DELIMITER                 ((uint8)0xFFU)

#define SYNCHRONOUS  (0U)
#define ASYNCHRONOUS (1U)

#define CS_VIA_PERIPHERAL_ENGINE            	(0x1U)

/* Max Channels */
#define SPI_MAX_CHANNEL 	6
/* Max Jobs */
#define SPI_MAX_JOB 		5
/* Max Sequence */
#define SPI_MAX_SEQUENCE 	5
/* Max Hw Hardware device*/
#define SPI_MAX_HW_UNIT 	1
/* Max External device configured*/
#define SPI_MAX_EXT_DEVICE  4
/* Sequence queue length*/

#define SPI_MAX_SEQ_QUEUE_LENGTH 10U

/* Spi Sequence ID Mapping */
#define  SpiSequence_0  0
#define  SpiSequence_1  1
#define  SpiSequence_2  2
#define  SpiSequence_3  3
#define  SpiSequence_4  4

/* Spi Job ID Mapping */
#define  SpiJob_0  0
#define  SpiJob_1  1
#define  SpiJob_2  2
#define  SpiJob_3  3
#define  SpiJob_4  4

/* Spi Channel ID Mapping */
#define  SpiChannel_0  0
#define  SpiChannel_1  1
#define  SpiChannel_2  2
#define  SpiChannel_3  3
#define  SpiChannel_4  4
#define  SpiChannel_5  5

#endif /* SPI_CFG_H */
/**********************************************************************************************************
**                                     End of file Spi_Cfg.h                                            **
**********************************************************************************************************/
