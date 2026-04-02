/*
    ===========================================================================

    Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
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

    $Header:   $
    $DateTime:  $
    $Author:   $

    ===========================================================================
*/
/* CanTrcv TCAN1146 Pre-compile Configuration Source File */
#ifdef __cplusplus
extern "C"{
#endif

/*****************************************************************************
 **                          Includes                                       **
 *****************************************************************************/
#include "CanTrcv_184_Tcan1146_Cfg.h"
#include "CanTrcv_184_Tcan1146.h"

/*****************************************************************************
 **                  Constants, Macros and Structures                       **
 *****************************************************************************/

#define CANTRCV_184_TCAN1146_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_184_Tcan1146_MemMap.h"
static const uint8 CanTrcv_184_Tcan1146_PnDataMsk0[]=
{
	/* DATA_0 */
	0x0,
	/* DATA_1 */
	0x1,
	/* DATA_2 */
	0x2,
	/* DATA_3 */
	0x3,
	/* DATA_4 */
	0x4,
	/* DATA_5 */
	0x5,
	/* DATA_6 */
	0x6,
	/* DATA_7 */
	0x7
};
#define CANTRCV_184_TCAN1146_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_184_Tcan1146_MemMap.h"
static const uint8 CanTrcv_184_Tcan1146_PnDataMsk1[]=
{
	/* DATA_0 */
	0x0,
	/* DATA_1 */
	0x1,
	/* DATA_2 */
	0x2,
	/* DATA_3 */
	0x3,
	/* DATA_4 */
	0x4,
	/* DATA_5 */
	0x5,
	/* DATA_6 */
	0x6,
	/* DATA_7 */
	0x7
};
#define CANTRCV_184_TCAN1146_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_184_Tcan1146_MemMap.h"
static const CanTrcv_Tcan1146ChPnConfigType CanTrcv_184_Tcan1146_ChPnCfg0 =
{
	/* Can Id of Wakeup Frame */
	0x155,

	/* Can Id Mask of Wakeup Frame */
	0x0,

	/* Can BaudRate in kbps */
	500,

	/* Data Length Code of Wakeup Frame */
	8,

	/* Bus Error Flag Checked */
	TRUE,

	/* Pn Frame is Extended Frame */
	FALSE,

	/* Pn is enabled */
	TRUE,

	/* Power On Reset Flag Checked */
	TRUE,

	/* Pointer to Data Mask */
	CanTrcv_184_Tcan1146_PnDataMsk0
};
#define CANTRCV_184_TCAN1146_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_184_Tcan1146_MemMap.h"
static const CanTrcv_Tcan1146ChPnConfigType CanTrcv_184_Tcan1146_ChPnCfg1 =
{
	/* Can Id of Wakeup Frame */
	0x2aa,

	/* Can Id Mask of Wakeup Frame */
	0x0,

	/* Can BaudRate in kbps */
	500,

	/* Data Length Code of Wakeup Frame */
	8,

	/* Bus Error Flag Checked */
	TRUE,

	/* Pn Frame is Extended Frame */
	FALSE,

	/* Pn is enabled */
	TRUE,

	/* Power On Reset Flag Checked */
	TRUE,

	/* Pointer to Data Mask */
	CanTrcv_184_Tcan1146_PnDataMsk1
};
#define CANTRCV_184_TCAN1146_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_184_Tcan1146_MemMap.h"
static const CanTrcv_Tcan1146ChConfigType CanTrcv_184_Tcan1146_ChConfig[]=
{
	{
		/* Init State */
		CANTRCV_TRCVMODE_STANDBY,

		/* SPI Sequence Id */
		1,

		/* SPI Channel Id */
		1,

		/* Maximum Baudrate */
		5000000u,

		/* Channel Used */
		TRUE,

		/* WakeUp by Bus Support */
		TRUE,

		/* Wakeup Source Id */
		32,

#if(CANTRCV_184_TCAN1146_ICU_CHANNEL_SUPPORT == STD_ON)
		/* ICU Channel support */
		TRUE,

		/* ICU Channel Id */
		10,
#endif

		/* HW PN support*/
		TRUE,

		/* Power On Reset Wakeup Source Id*/
		32,

		/* Syserr Wakeup Source Id*/
		32,

		/*Partial Networking Cfg */
		&CanTrcv_184_Tcan1146_ChPnCfg0,

		/* Event ID for Dem Reporting */
		1
	},
	{
		/* Init State */
		CANTRCV_TRCVMODE_STANDBY,

		/* SPI Sequence Id */
		2,

		/* SPI Channel Id */
		2,

		/* Maximum Baudrate */
		5000000u,

		/* Channel Used */
		TRUE,

		/* WakeUp by Bus Support */
		TRUE,

		/* Wakeup Source Id */
		32,

#if(CANTRCV_184_TCAN1146_ICU_CHANNEL_SUPPORT == STD_ON)
		/* ICU Channel support */
		TRUE,

		/* ICU Channel Id */
		10,
#endif

		/* HW PN support*/
		TRUE,

		/* Power On Reset Wakeup Source Id*/
		32,

		/* Syserr Wakeup Source Id*/
		32,

		/*Partial Networking Cfg */
		&CanTrcv_184_Tcan1146_ChPnCfg1,

		/* Event ID for Dem Reporting */
		2
	}
};
#define CANTRCV_184_TCAN1146_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_184_Tcan1146_MemMap.h"
const CanTrcv_Tcan1146ConfigType CanTrcv_184_Tcan1146_Config =
{
	/* Number of CAN Transceiver Channels */
	2u,

	/* Pointer to CAN Transceiver configurations */
	&CanTrcv_184_Tcan1146_ChConfig[0],

	/* Number of SPI Retries */
	10,
};
#define CANTRCV_184_TCAN1146_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_184_Tcan1146_MemMap.h"

#ifdef __cplusplus
}
#endif
