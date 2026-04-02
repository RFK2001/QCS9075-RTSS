/*
  ===========================================================================
*/
/**
  @file mailboxExt_api.h
  @brief export public module APIs
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
#ifndef MAILBOXEXT_API_H
#define MAILBOXEXT_API_H
/*==============================================================================
**                          	Include files                                 **
==============================================================================*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "types.h"
#ifndef SAILEL2
#include "freertos_init.h"
#endif
/*==============================================================================
**          Global typedefs : Enums, Structures Union and other typedefs      **
==============================================================================*/

/* mailbox EB mem map collector */
#define mailboxEB_DATA		__attribute__(( section ("ebrw")))
#define mailboxEB_CONST		__attribute__(( section ("ebr")))
#define mailboxEB_WEAKCBK	__attribute__(( weak ))
#define MAILBOX_EXT_FUNC __attribute__ ( ( section ( "mailbox_ext_func" ) ) )

/* config set addressed with Client Id */
typedef enum
{
	MAILBOX_HLOSPMU = 0,
	MAILBOX_HLOSUSS,
	MAILBOX_HLOSTST,
	MAILBOX_CONSOLE,
	MAILBOX_OTA,
	MAILBOX_TMU,
	MAILBOX_PTP,
	MAILBOX_CAN,
	MAILBOX_POWER,
	MAILBOX_FUSE,
	MAILBOX_STZ,
	/* qcmi resource manager communication client entries goes here ..start*/
	/* qcmi resource manager communication client entries goes here ..end*/
	MAILBOX_SSM,
	MAILBOX_TSM,
	MAILBOX_EBMAX
}xMailboxExtclienttype;
/* driver chan type */
typedef uint32 xMailboxExtChanType; 
/* driver status type */
typedef uint32 mailboxEBStatusType_e; 
/* Type definition for the NotificationFuncPtrtype */
typedef void (*MailboxEBNotificationFuncPtr) (xMailboxExtclienttype MBclient_ID);
/*==============================================================================
**                     Global MB cfg Macros					              	  **
==============================================================================*/
/* Driver status */
#define MB_UNINITIALIZED	0U
#define MB_CONFIGURED		1U	  	  
#define MB_INITIIALIZED		2U 	  
#define MB_E2EREADY			3U     	  
#define MB_ABORT			4U

/* Driver xMailboxExtChanType value */
#define MB_MSG_RD_CHAN		0U
#define MB_MSG_WR_CHAN		1U	  	  

/* fixed external mailbox addresses , do not modify protected pages start and end pts */
#define mailboxEB_TSM_ADDR	( 0x30C00000U )
#define mailboxEB_SSM_ADDR	( 0x30D00000U )
#define mailboxEB_QCMI_ADDR	( 0x30D80000U )
#define mailboxEB_RSRV_ADDR ( 0x30DFF000U )
/* External Mailbox size*/
#define mailboxEB_TSM_SZ	( 0x80000U )
#define mailboxEB_SSM_SZ	( 0x80000U )
#define mailboxEB_QCMI_SZ	( 0x7F000U )
#define mailboxEB_RSRV_SZ	( 0x200U   )
#ifndef SAILEL2
extern uint32_t Image$$lnkMBCOREDATAStartAddr$$ZI$$Base;
extern uint32_t Image$$lnkMBCOREDATAEndAddr$$ZI$$Base;

/*SAIL Mailbox MPU Region Base Address and Size*/
#define SAILBSP_MBEB_CORE_DATA_ADDR_BASE    (void *)&Image$$lnkMBCOREDATAStartAddr$$ZI$$Base
#define SAILBSP_MBEB_CORE_DATA_ADDR_SIZE    (uint32_t)( (uint32_t)&Image$$lnkMBCOREDATAEndAddr$$ZI$$Base -\
                                                            (uint32_t)&Image$$lnkMBCOREDATAStartAddr$$ZI$$Base )

/* SAIL_TO_MD_IPC_Register base and size , need to be modified if there is any change in IPCC Memory map*/
#define SAILBSP_TO_MD_IPCC_CL1_REG_ADDR_BASE      (void*)0xC049B000U
#define SAILBSP_TO_MD_IPCC_CL0_REG_ADDR_BASE      (void*)0xC045B000U
#define SAILBSP_TO_MD_IPCC_MPROC_REG_ADDR_BASE    (void*)0xC041B000U
#define SAILBSP_TO_MD_IPCC_REG_ADDR_SIZE           0x4000U
#endif
/*==============================================================================
**                Global variables and Public APIs		                      **
==============================================================================*/
/*==============================================================================
 @Service name        slMailBox_Enable
 @Description         This API shall configure the chan and IPCC signal required  
                      for the mailbox application.
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              on success 0 , on error nonzero negative value
 @Pre                 IPCC Driver init
 @Post                NA
 @Requirements IDs    -
 @Design IDs          -
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC int32 slMailBox_Enable(void);
/*==============================================================================
 @Service name        slMailBox_DeInit
 @Description         This API shall deinit the mbExt on respective core
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              on success 0 , on error nonzero negative value
 @Pre                 IPCC Driver init
 @Post                NA
 @Requirements IDs    -
 @Design IDs          -
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC int32 slMailBox_DeInit(void);
/*==============================================================================
 @Service name        slMailBoxEB_Init
 @Description         This API shall Initialize mailbox region and configure the 
					  interrupt.
 @param[in]           ucMailboxId - Mailbox Id
 @param[out]          NA
 @param[in, out]      NA
 @return              Return the status of the mailbox driver
 @Pre                 IPCC driver shall be initialized before calling this fun
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC int32 slMailBoxEB_Init(void);
/*==============================================================================
 @Service name        slMailboxClientReg
 @Description         This API shall register the mailbox client to mailbox driver.
 @param[in]           MBclient_ID - mailbox channle Id
 @param[in]           Callbackfunctionptr - callback handler 
 @param[out]          NA
 @param[in, out]      NA
 @return              on success 0 , on error nonzero negative value
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          -
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC int32 slMailboxClientReg
( 
	xMailboxExtclienttype MBclient_ID,
	MailboxEBNotificationFuncPtr Callbackfunctionptr
);
/*=============================================================================
 @Service name        slMailboxSendTrigger(xMailboxExtclienttype MBclient_ID)
 @Description         This API shall send the passed data to DDR region and 
                      trigger the corresponding IPCC interrupt.
 @param[in]           MBclient_ID - mailbox client Id
 @param[out]          NA
 @param[in, out]      NA
 @return 			  If success return zero otherwise nonzero value.
 @Pre                 Mailbox driver shall be initialized before calling this fun
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC int32 slMailboxSendTrigger(xMailboxExtclienttype MBclient_ID);
/*=============================================================================
 @Service name        slMailboxChanSendTrigger
                       ( xMailboxExtclienttype MBclient_ID,
					     xMailboxExtChanType ChanType
					   )
 @Description         This API shall trigger the corresponding IPC interrupt mapped
						to client chan.
 @param[in]           MBclient_ID - mailbox client Id
 @param[in]           ChanType - mailbox chan type MB_MSG_RD_CHAN or MB_MSG_WR_CHAN
 @param[out]          NA
 @param[in, out]      NA
 @return 			  If success return zero otherwise nonzero value.
 @Pre                 Mailbox driver shall be initialized before calling this fun
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC int32 slMailboxChanSendTrigger(xMailboxExtclienttype MBclient_ID, xMailboxExtChanType ChanType);
/*==============================================================================
 @Service name        slMailboxWrite
 @Description         This API shall send the passed data to DDR region and 
                      trigger the corresponding IPCC interrupt.
 @param[in]           Mailbox_Id - mailbox channle Id
                      Mailbox_SubRegId - mailbox subregion id
                      num_item - Number of item to send
                      puclQueueSAILAPSSTx - Pointer to the data to be send
 @param[out]          NA
 @param[in, out]      NA
 @return 			  If read success return the actual item number read from
				      mailbox else return negative error code.If the sub-region
					  is full return 0.
 @retval  			  actual_item_num Wite items into mailbox success.
 @retval  			  -11 Some input pointer(s) is(are) NULL.
 @retval  			  -22 Input Mailbox configurations are unreasonable.
 @retval  			  -33 Invalid sub-region index.
 @retval  			  -44 Mailbox has not been created.
 @retval  			  -55 Mailbox has not enough free buffer.
 @retval  			  -66 Mailbox is corrupt.
 @Pre                 Mailbox driver shall be initialized before calling this fun
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC int32 slMailboxWrite(xMailboxExtclienttype MBclient_ID,uint32 num_item,uint8 *wbuff);
/*==============================================================================
 @Service name        slMailboxRead
 @Description         This API shall read data to DDR region
 @param[in]           Mailbox_Id - mailbox channle Id
                      Mailbox_SubRegId - mailbox subregion id
                      num_item - Number of item to send
 @param[out]          NA
 @param[in, out]      puclQueueSAILAPSSTx - Pointer to the buff          
 @return 			  If read success return the actual item number read from 
					  mailbox   else return negative error code.If the subrgn
					  is empty ret 0.
 @retval  			  actual_item_num read on success.
 @retval  			  -11 Some input pointer(s) is(are) NULL.
 @retval  			  -33 Invalid sub-region index.
 @retval  			  -44 Mailbox has not been created.
 @retval  			  -66 Mailbox is corrupt.
 @Pre                 Mailbox driver shall be initialized before calling this fun
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC int32 slMailboxRead(xMailboxExtclienttype MBclient_ID,uint32 num_item,uint8 *rbuff);
/*==============================================================================
 @Service name        slMailbox_Get_FreeItemNum
 @Description         Get the number of free items count from a mailbox subrgn
 @param[in]           MBclient_ID - mailbox cleint Id
 @param[out]          NA
 @param[in, out]      NA      
 @return 			  if get the number of free items count success return the 
						item number, else return negative error code.
 @retval  			  Get the number of free item count success
 @retval  			  -11 Some input pointer(s) is(are) NULL.
 @retval  			  -33 Invalid sub-region index.
 @retval  			  -44 Mailbox has not been created.
 @retval  			  -66 Mailbox is corrupt.
 @Pre                 Mailbox driver shall be initialized before calling this fun 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC int32 slMailbox_Get_FreeItemNum(xMailboxExtclienttype MBclient_ID);
/*==============================================================================
 @Service name        slMailbox_Get_ValidItemNum
 @Description         Get the number of valid items count from a mailbox subrgn
 @param[in]           MBclient_ID - mailbox cleint Id
 @param[out]          NA
 @param[in, out]      NA      
 @return 			  if get the number of valid item count success return the 
						item count, else  return negative error code.
 @retval  			  Get the number of free item count success
 @retval  			  -11 Some input pointer(s) is(are) NULL.
 @retval  			  -33 Invalid sub-region index.
 @retval  			  -44 Mailbox has not been created.
 @retval  			  -66 Mailbox is corrupt.
 @Pre                 Mailbox driver shall be initialized before calling this fun
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC int32 slMailbox_Get_ValidItemNum(xMailboxExtclienttype MBclient_ID);
/*==============================================================================
 @Service name        eMailbox_Get_Status
 @Description         Get driver global status 
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA      
 @return 			  MB_UNINITIALIZED - Deinit state
					  MB_CONFIGURED	 - Configured state
					  MB_INITIIALIZED - Init state
					  MB_E2EREADY	 - MD and SAIL Driver/RM ready E2E ready
					  MB_ABORT	 - MD and SAIL Driver/RM comm abort
					  Driver updated status, on failure 0xFFU
 @Pre                 NA 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC mailboxEBStatusType_e eMailbox_Get_Status(void);
/*==============================================================================
 @Service name        eMailbox_Get_CoreStatus
 @Description         Get driver global status by core 
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA      
 @return 			  MB_UNINITIALIZED - Deinit state
					  MB_CONFIGURED	 - Configured state
					  MB_INITIIALIZED - Init state
					  MB_E2EREADY	 - MD and SAIL Driver/RM ready E2E ready
					  MB_ABORT	 - MD and SAIL Driver/RM comm abort
					  Driver updated status, on failure 0xFFU
 @Pre                 NA 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC mailboxEBStatusType_e eMailbox_Get_CoreStatus(uint32 core);
/*==============================================================================
 @Service name        eMailbox_Set_Status
 @Description         change driver global state machine to expected state
 @param[in]           expectedState - state to be set
 @param[out]          core - core number
 @param[in, out]      NA      
 @return 			  Driver updated status, on failure 0xFFU
 @Pre                 NA 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                QC Internal platform Use Case only
==============================================================================*/
MAILBOX_EXT_FUNC mailboxEBStatusType_e eMailbox_Set_Status( mailboxEBStatusType_e expectedState, uint32 core );
/*==============================================================================
 @Service name        eMailbox_SetBCK_Status
 @Description         change driver global state machine to expected state
 @param[in]           expectedState - state to be set
 @param[out]          core - core number
 @param[in, out]      NA      
 @return 			  Driver updated status, on failure 0xFFU
 @Pre                 NA 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                QC Internal platform Use Case only
==============================================================================*/
MAILBOX_EXT_FUNC mailboxEBStatusType_e eMailbox_SetBCK_Status( mailboxEBStatusType_e expectedState, uint32 core );
/*==============================================================================
 @Service name        eMailbox_Abort
 @Description         Set driver global status to comm abort 
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA      
 @return 			   Driver updated status, on failure 0xFFU
 @Pre                 NA 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC mailboxEBStatusType_e eMailbox_Abort(void);
/*==============================================================================
 @Service name        eMailbox_Resume
 @Description         Set driver global status to prev state before abort
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA      
 @return 			  Driver updated status, on failure 0xFFU
 @Pre                 NA 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC mailboxEBStatusType_e eMailbox_Resume(void);
/*==============================================================================
 @Service name        slMailbox_EBResetRequest
 @Description         reset the channels mapped to core, User can decide the 
					  resetting channel on core if requirement is there otherwise
					  each applicaton empty the stale data at its entry point before
					  proceeding.
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA      
 @return 			  0 on success, on error negative nonzero value
 @Pre                 NA 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC int32 slMailbox_EBResetRequest( uint32 core );
/*==============================================================================
 @Service name        vMailbox_S1_Handler
 @Description         Mialbox S1 Map init notification 
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA      
 @return 			  NA
 @Pre                 NA 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Asynchronous function
 @Reentrancy          Yes
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC void vMailbox_S1_Handler(void);
/*==============================================================================
 @Service name        slMailboxEBDebugEventCnt
 @Description         Read debug event count
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA      
 @return 			  NA
 @Pre                 NA 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Asynchronous function
 @Reentrancy          Yes
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC int32_t slMailboxEBDebugEventCnt( xMailboxExtclienttype client , uint32_t rwtype );
#endif /* MAILBOXEXT_API_H */
/*==============================================================================
** 							          EOF						  			  ** 
==============================================================================*/
