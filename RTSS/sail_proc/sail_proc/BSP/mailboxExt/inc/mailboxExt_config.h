/*
  ===========================================================================
*/
/**
  @file mailboxExt_config.h
  @brief module configuration file
*/
/*
  ===========================================================================
  
  Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
  All rights reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  
  Export of this technology or software is regulated by the U.S. Government.
  Diversion contrary to U.S. law prohibited.
  
  All ideas, data and information contained in or disclosed by
  this document are confidential and proprietary information of
  Qualcomm Technologies Incorporated and all rights therein are expressly 
  reserved.
  By accepting this material the recipient agrees that this material
  and the information contained therein are held in confidence and in
  trust and will not be used, copied, reproduced in whole or in part,
  nor its contents revealed in any manner to others without the express
  written permission of Qualcomm Technologies Incorporated.
  
  ===========================================================================

  $Header: 
  $DateTime:
  $Author:

  ===========================================================================
*/
/*
  ===========================================================================

  EDIT HISTORY FOR MODULE

  when       who      what, where, why
  --------   -------  -------------------------------------------------------

  ===========================================================================
*/
#ifndef MAILBOXEXT_CONFIG_H
#define MAILBOXEXT_CONFIG_H
/*==============================================================================
**                               Include files                      		  **
==============================================================================*/
#include "mailboxLib.h"
#include "IPCC.h"

/* chan Ids 1:1 mapped with mailbox subregion or RW pipe */
typedef enum
{
	EB_CHAN_PMU_RX_IDN,
	EB_CHAN_PMU_TX_IDN,
	EB_CHAN_ULS_RX_IDN,
	EB_CHAN_ULS_TX_IDN,
	EB_CHAN_TST_RX_IDN,
	EB_CHAN_TST_TX_IDN,
	EB_CHAN_CONSOLE_TX_IDN,
	EB_CHAN_OTA_RX_IDN,
	EB_CHAN_OTA_TX_IDN,
	EB_CHAN_TMU_RX_IDN,
	EB_CHAN_TMU_TX_IDN,
	EB_CHAN_PTP_RX_IDN,
	EB_CHAN_PTP_TX_IDN,
	EB_CHAN_CAN_RX_IDN,
	EB_CHAN_CAN_TX_IDN,
	EB_CHAN_POWER_TX_IDN,
	EB_CHAN_FUSE_RX_IDN,
	EB_CHAN_FUSE_TX_IDN,
	EB_CHAN_STZ_RX_IDN,
	EB_CHAN_STZ_TX_IDN,
	/* qcmi resource manager communication client chan entries goes here
	 following placeholder entries always be at the end */
	EB_CHAN_SSM_RX_IDN,	/* SSM RX */
	EB_CHAN_SSM_TX_IDN,	/* SSM TX */
	EB_CHAN_TSM_RX_IDN,	/* TSM RX */
	EB_CHAN_TSM_TX_IDN,	/* TSM TX */
	EB_CHAN_MAX,
}mailboxEBChanType_e;

/* Driver main mailbox Ids */
typedef enum
{
    MAILBOX_QCMI_IDN = 0,
	MAILBOX_SSM_IDN,
	MAILBOX_TSM_IDN,
	MAILBOX_EB_MAX_IDN,
}mailboxEBIDNType_e;

/* Type definition for the NotificationFuncPtrtype */
typedef void (*MailboxNotificationFuncPtr)( IPCC_CBData nData,
	                                        IPCC_Client eSenderID,
											IPCC_Signal nSignal );
/* chan descr type */
typedef struct
{
	mailboxEBIDNType_e MbId;
	mailboxEBChanType_e ChanId;
	uint32 MbAddress;
	uint32 *pDbgCnt;
	xMailboxExtclienttype eClient;
	const mbsub_rgn_config_t *pRgnCfg;
}xMailboxEBChanRec_t;
/* client chan descr type */
typedef struct
{
	xMailboxEBChanRec_t ChanRec[MB_CHAN_MAX_TYPE];
}xMailboxEBClientRec_t;
/*==============================================================================
**                  Local defines and macros                  				  **
==============================================================================*/
/* core config temp : export from target config  */
#define mailboxEB_CORE0		(0U)
#define mailboxEB_CORE1		(1U)
#define mailboxEB_CORE2		(2U)
#define mailboxEB_CORE3		(3U)
#define mailboxEB_COREMAX 	(4U)
/* protocol instance Idn */
#define mailboxEB_IPC_MPROC			(0U)
#define mailboxEB_IPC_CL0			(1U)
#define mailboxEB_IPC_CL1			(2U)
#define mailboxEB_IPC_PROTOCOL_MAX 	(3U)
/* mailbox EB mem map collector */
/* General macro for mailbox driver*/
#define mailboxEB_TOTALNUMEXTERNAL	1U
/* Number of SubRegion in the HLOS general mailbox*/
#define mailboxEB_QCMI_NUMSUBREGION	20U
/* QCMI Nominal run priority 10 to 255 */
/* #define mailboxEB_QCMI_PRIORITY MB_DEFAULT_PRIORITY  */
#define mailboxEB_QCMI_PRIORITY	(55U) 
/*==============================================================================
**                   EB QCMI chan configuration        						  **
===============================================================================*/
/* qcmi resource manager client chan config goes here .. */

/* Unique Signal allocation according SAIL EB Mailbox clients
	for channel configuration pls get help from BSP team */
#define mailboxEB_SIG_00_ID	0U
#define mailboxEB_SIG_01_ID	1U
#define mailboxEB_SIG_02_ID	2U
#define mailboxEB_SIG_03_ID	3U
#define mailboxEB_SIG_04_ID	4U
#define mailboxEB_SIG_05_ID	5U
#define mailboxEB_SIG_06_ID	6U
#define mailboxEB_SIG_07_ID	7U
/* following range supported by CLx */
#define mailboxEB_SIG_08_ID	8U
#define mailboxEB_SIG_09_ID	9U
#define mailboxEB_SIG_10_ID	10U
#define mailboxEB_SIG_11_ID	11U
#define mailboxEB_SIG_12_ID	12U
#define mailboxEB_SIG_13_ID	13U
#define mailboxEB_SIG_14_ID	14U
#define mailboxEB_SIG_15_ID	15U
#define mailboxEB_SIG_16_ID	16U
#define mailboxEB_SIG_17_ID	17U
#define mailboxEB_SIG_18_ID	18U
#define mailboxEB_SIG_19_ID	19U
#define mailboxEB_SIG_20_ID	20U
#define mailboxEB_SIG_21_ID	21U
#define mailboxEB_SIG_22_ID	22U
#define mailboxEB_SIG_23_ID	23U
#define mailboxEB_SIG_24_ID	24U
#define mailboxEB_SIG_25_ID	25U
#define mailboxEB_SIG_26_ID	26U
#define mailboxEB_SIG_27_ID	27U
#define mailboxEB_SIG_28_ID	28U
#define mailboxEB_SIG_29_ID	29U
#define mailboxEB_SIG_30_ID	30U
#define mailboxEB_SIG_31_ID	31U

/* chan 0 : RX PMU config */
#define mailboxEB_CHAN_PMU_RX_IDN_NUMITEM		10U
#define mailboxEB_CHAN_PMU_RX_IDN_ITEMSIZE		128U
#define mailboxEB_CHAN_PMU_RX_IDN_SIGID			mailboxEB_SIG_02_ID

/* chan 1 : TX PMU config */
#define mailboxEB_CHAN_PMU_TX_IDN_NUMITEM		10U
#define mailboxEB_CHAN_PMU_TX_IDN_ITEMSIZE		128U
#define mailboxEB_CHAN_PMU_TX_IDN_SIGID      	mailboxEB_SIG_02_ID
									
/* chan 2 : RX ULS config */        
#define mailboxEB_CHAN_ULS_RX_IDN_NUMITEM  		64U
#define mailboxEB_CHAN_ULS_RX_IDN_ITEMSIZE   	64U
#define mailboxEB_CHAN_ULS_RX_IDN_SIGID      	mailboxEB_SIG_03_ID
									
/* chan 3 : TX ULS config */        
#define mailboxEB_CHAN_ULS_TX_IDN_NUMITEM  		64U
#define mailboxEB_CHAN_ULS_TX_IDN_ITEMSIZE  	64U
#define mailboxEB_CHAN_ULS_TX_IDN_SIGID   		mailboxEB_SIG_03_ID
									
/* chan 4 : RX TST config */        
#define mailboxEB_CHAN_TST_RX_IDN_NUMITEM   	10U
#define mailboxEB_CHAN_TST_RX_IDN_ITEMSIZE 		64U
#define mailboxEB_CHAN_TST_RX_IDN_SIGID      	mailboxEB_SIG_04_ID
									
/* chan 5 : TX TST config */        
#define mailboxEB_CHAN_TST_TX_IDN_NUMITEM  		10U
#define mailboxEB_CHAN_TST_TX_IDN_ITEMSIZE  	64U
#define mailboxEB_CHAN_TST_TX_IDN_SIGID    		mailboxEB_SIG_04_ID
									
/* chan 6 : TX CONSOLE config */    
#define mailboxEB_CHAN_CONSOLE_TX_IDN_NUMITEM 	0x6000U
#define mailboxEB_CHAN_CONSOLE_TX_IDN_ITEMSIZE 	1U
#define mailboxEB_CHAN_CONSOLE_TX_IDN_SIGID   	mailboxEB_SIG_05_ID
									
/* chan 7 :RX OTA config */         
#define mailboxEB_CHAN_OTA_RX_IDN_NUMITEM 		2U
#define mailboxEB_CHAN_OTA_RX_IDN_ITEMSIZE 		72U
#define mailboxEB_CHAN_OTA_RX_IDN_SIGID  		mailboxEB_SIG_06_ID

/* chan 8 :TX OTA config */
#define mailboxEB_CHAN_OTA_TX_IDN_NUMITEM  		2U
#define mailboxEB_CHAN_OTA_TX_IDN_ITEMSIZE		72U
#define mailboxEB_CHAN_OTA_TX_IDN_SIGID			mailboxEB_SIG_06_ID

/* chan 9 :RX TMU config */         
#define mailboxEB_CHAN_TMU_RX_IDN_NUMITEM 		2U
#define mailboxEB_CHAN_TMU_RX_IDN_ITEMSIZE 		64U
#define mailboxEB_CHAN_TMU_RX_IDN_SIGID  		mailboxEB_SIG_07_ID

/* chan 10:TX TMU config */
#define mailboxEB_CHAN_TMU_TX_IDN_NUMITEM  		2U
#define mailboxEB_CHAN_TMU_TX_IDN_ITEMSIZE		64U
#define mailboxEB_CHAN_TMU_TX_IDN_SIGID			mailboxEB_SIG_07_ID

/* chan 11:RX PTP config */         
#define mailboxEB_CHAN_PTP_RX_IDN_NUMITEM 		2U
#define mailboxEB_CHAN_PTP_RX_IDN_ITEMSIZE 		32U
#define mailboxEB_CHAN_PTP_RX_IDN_SIGID  		mailboxEB_SIG_08_ID

/* chan 12:TX PTP config */
#define mailboxEB_CHAN_PTP_TX_IDN_NUMITEM  		2U
#define mailboxEB_CHAN_PTP_TX_IDN_ITEMSIZE		32U
#define mailboxEB_CHAN_PTP_TX_IDN_SIGID			mailboxEB_SIG_08_ID

/* chan 13:RX CAN config */         
#define mailboxEB_CHAN_CAN_RX_IDN_NUMITEM 		10U
#define mailboxEB_CHAN_CAN_RX_IDN_ITEMSIZE 		128U
#define mailboxEB_CHAN_CAN_RX_IDN_SIGID  		mailboxEB_SIG_09_ID

/* chan 14:TX CAN config */
#define mailboxEB_CHAN_CAN_TX_IDN_NUMITEM  		10U
#define mailboxEB_CHAN_CAN_TX_IDN_ITEMSIZE		128U
#define mailboxEB_CHAN_CAN_TX_IDN_SIGID			mailboxEB_SIG_09_ID

/* chan 15 : TX POWER config */    
#define mailboxEB_CHAN_POWER_TX_IDN_NUMITEM 	2U
#define mailboxEB_CHAN_POWER_TX_IDN_ITEMSIZE 	64U
#define mailboxEB_CHAN_POWER_TX_IDN_SIGID   	mailboxEB_SIG_10_ID

/* chan 16: RX FUSE config */
#define mailboxEB_CHAN_FUSE_RX_IDN_NUMITEM		2U
#define mailboxEB_CHAN_FUSE_RX_IDN_ITEMSIZE		64U
#define mailboxEB_CHAN_FUSE_RX_IDN_SIGID		mailboxEB_SIG_11_ID

/* chan 17: TX FUSE config */
#define mailboxEB_CHAN_FUSE_TX_IDN_NUMITEM		2U
#define mailboxEB_CHAN_FUSE_TX_IDN_ITEMSIZE		160U
#define mailboxEB_CHAN_FUSE_TX_IDN_SIGID		mailboxEB_SIG_11_ID

/* chan 18: RX STZ config */
#define mailboxEB_CHAN_STZ_RX_IDN_NUMITEM		2U
#define mailboxEB_CHAN_STZ_RX_IDN_ITEMSIZE		128U
#define mailboxEB_CHAN_STZ_RX_IDN_SIGID			mailboxEB_SIG_12_ID

/* chan 19: TX STZ config */
#define mailboxEB_CHAN_STZ_TX_IDN_NUMITEM		2U
#define mailboxEB_CHAN_STZ_TX_IDN_ITEMSIZE		128U
#define mailboxEB_CHAN_STZ_TX_IDN_SIGID		    mailboxEB_SIG_12_ID
#define mailboxEB_CHAN_SSM_RX_IDN_NUMITEM		0U
#define mailboxEB_CHAN_SSM_RX_IDN_ITEMSIZE		0U
#define mailboxEB_CHAN_SSM_RX_IDN_SIGID			mailboxEB_SIG_01_ID

/* chan 17:TX SSM config */
#define mailboxEB_CHAN_SSM_TX_IDN_NUMITEM		0U
#define mailboxEB_CHAN_SSM_TX_IDN_ITEMSIZE		0U
#define mailboxEB_CHAN_SSM_TX_IDN_SIGID			mailboxEB_SIG_01_ID

/* chan 18:RX TSM config */
#define mailboxEB_CHAN_TSM_RX_IDN_NUMITEM		0U
#define mailboxEB_CHAN_TSM_RX_IDN_ITEMSIZE		0U
#define mailboxEB_CHAN_TSM_RX_IDN_SIGID			mailboxEB_SIG_00_ID

/* chan 19:TX TSM config */
#define mailboxEB_CHAN_TSM_TX_IDN_NUMITEM		0U
#define mailboxEB_CHAN_TSM_TX_IDN_ITEMSIZE		0U
#define mailboxEB_CHAN_TSM_TX_IDN_SIGID			mailboxEB_SIG_00_ID

/*==============================================================================
**               Global variables and constants                			      **
==============================================================================*/
mailboxEB_CONST extern const xMailboxEBClientRec_t xMailboxClientRec[MAILBOX_EBMAX];
/*==============================================================================
**                Global functions prototype                 			      **
==============================================================================*/
/*==============================================================================
 @Service name        pxMailBoxEB_GetMbConfig
 @Description         This API shall return the Mailbox configuration
 @param[in]           MBInstanceId - Mailbox Instance ID
 @param[out]          NA
 @param[in, out]      NA
 @return              mailbox configuration for the passed mailbox channel Id
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC const mbconfig_t *pxMailBoxEB_GetMbConfig (mailboxEBIDNType_e MBInstanceId);
/*==============================================================================
 @Service name        pxMailBoxEB_GetSubRegConfig
 @Description         This API shall return the Mailbox subregion configuration
 @param[in]           MBInstanceId - Mailbox Instance ID
 @param[out]          NA
 @param[in, out]      NA
 @return              mailbox configuration for the passed mailbox channel Id
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
===============================================================================*/
MAILBOX_EXT_FUNC const mbsub_rgn_config_t *pxMailBoxEB_GetSubRegConfig
( 
	mailboxEBIDNType_e MBInstanceId
);
#endif /* MAILBOXEXT_CONFIG_H */
/*==============================================================================
** 								EOF											  ** 
==============================================================================*/
