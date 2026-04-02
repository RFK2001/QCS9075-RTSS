/*
  ===========================================================================
*/
/**
  @file mailboxExt_api.c
  @brief implements module APIs
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
/*==============================================================================
**                          	Include files                                 **
==============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <common_functions.h>
#include <stdatomic.h>
#include "hw_io.h"
#include "debug_log.h"
#include "cache_ops.h"
#include "interrupts.h"
#include "IPCC.h"
#include "logcode.h"
#include "mailboxLib.h"
#include "mailboxExt_api.h"
#include "mailboxExt_config.h"
#include "busywait.h"
#include "timetick.h"

/*==============================================================================
**       Local typedefs :Macros        										  **
==============================================================================*/

/*==============================================================================
**       Global typedefs : Enums, Structures Union and other typedefs         **
==============================================================================*/
/* chan descriptor */
typedef struct
{
	MailboxEBNotificationFuncPtr NotifPtr;
	uint32_t _cdminline[1];
}xEBClientCbkDesc_t;
/*==============================================================================
**                         Global variables and constants                     **
==============================================================================*/

#define MailBox_TASK_INSTANCES			( 3U )			

static mailboxEB_DATA IPCC_Handle xMailboxExt_IpccHandle[MailBox_TASK_INSTANCES][mailboxEB_IPC_PROTOCOL_MAX] = { NULL, NULL, NULL };
/*==============================================================================
**                     Local function prototypes                              **
==============================================================================*/
/* chan event handling */
MAILBOX_EXT_FUNC static void prvMailboxEBChanHandler( IPCC_CBData nData, IPCC_Client eSenderID, IPCC_Signal nSignal);
MAILBOX_EXT_FUNC static int32 prvEBGetCore( uint32 *pCoreID );
MAILBOX_EXT_FUNC static int32 prvMailboxIOSanityCheck( xMailboxExtclienttype MBclient_ID );
MAILBOX_EXT_FUNC static int32 prvMailboxSMIOSanityCheck( xMailboxExtclienttype MBclient_ID );
MAILBOX_EXT_FUNC static uint32_t prvEBGetSZofCoreStatusPTR( void );
MAILBOX_EXT_FUNC static void prvEBWrCoreStatus( uint32_t core , uint32_t sts );
MAILBOX_EXT_FUNC static uint32_t prvEBRdCoreStatus( uint32_t core );
MAILBOX_EXT_FUNC static uint32_t * prvEBGetCoreStatusPTR( void );
MAILBOX_EXT_FUNC static uint32_t * prvEBGetCoreBCKStatusPTR( void );
MAILBOX_EXT_FUNC static uint32_t prvEBGetSZofCoreStatusPTR( void );
MAILBOX_EXT_FUNC static void* prvEBGetEBCbkHandle( uint32_t chan );
MAILBOX_EXT_FUNC static void prvEBBCKWrCoreStatus( uint32_t core , uint32_t sts );
MAILBOX_EXT_FUNC static uint32_t prvEBBCKRdCoreStatus( uint32_t core );
MAILBOX_EXT_FUNC static int32 prvEB_IPCC_AttachEx( uint32_t core );
MAILBOX_EXT_FUNC static int32 prvEB_IPCC_DettachEx( uint32_t core );
MAILBOX_EXT_FUNC static int32 prvEB_IPCC_RegisterInterrupt( uint32_t core );
MAILBOX_EXT_FUNC static int32 prvEB_IPCC_DeRegisterInterrupt( uint32_t core );

#if defined(__ARM_GNU__)
	extern uint32_t lnk_shr_eb_bck_status[];
	extern uint32_t lnk_shr_eb_status[];
	extern uint32_t lnk_shr_eb_map_vect[];

	#define SHR_EBBCKSTATUS_ADDRESS     (lnk_shr_eb_bck_status)
	#define SHR_EBSTATUS_ADDRESS        (lnk_shr_eb_status)
	#define SHR_EBMAPVECT_ADDRESS       (lnk_shr_eb_map_vect)
#elif defined(__ARM_FUSA__)
	extern uint32_t Image$$SHR_EBBCKSTATUS$$RO$$Base[];
	extern uint32_t Image$$SHR_EBSTATUS$$RO$$Base[];
	extern uint32_t Image$$SHR_EBMAPVECT$$RO$$Base[];

	#define SHR_EBBCKSTATUS_ADDRESS     (Image$$SHR_EBBCKSTATUS$$RO$$Base)
	#define SHR_EBSTATUS_ADDRESS        (Image$$SHR_EBSTATUS$$RO$$Base)
	#define SHR_EBMAPVECT_ADDRESS       (Image$$SHR_EBMAPVECT$$RO$$Base)
#else
    #error "Unknown Linker Symbols Format"
#endif
/*==============================================================================
**                     Global functions definition                            **
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
MAILBOX_EXT_FUNC int32 slMailBox_Enable(void)
{
	int32 slstatus  = MB_E_SUCCESS;
	/* Get the Current CPU Id.*/
	uint32 ulcore = mailboxEB_COREMAX;
	if( MB_E_SUCCESS != prvEBGetCore( &ulcore ) )
	{
		slstatus = MB_E_INVALID_INDEX;
	}
    /* Attach the MD MPROC  for the sail*/
	if( MB_E_SUCCESS != slstatus )
	{
        DEBUG_LOG( SAIL_ERROR,"vMailBox_Enable(%d): failed, MB_E_INVALID_INDEX\n\r", ulcore);
	}
	else if(MB_CONFIGURED <= prvEBRdCoreStatus( ulcore ))
	{
		DEBUG_LOG( SAIL_ERROR,"vMailBox_Enable(%d): retry, already in enabled state\n\r", ulcore );	
	} /* once mdos support enbaled add other handles for more signal mapping */
    else if( MB_E_SUCCESS != prvEB_IPCC_AttachEx(ulcore) )
    {
        DEBUG_LOG( SAIL_ERROR,"vMailBox_Enable(%d): IPCC Attach failed.\n\r", ulcore);
		slstatus = MB_E_INVALID_CFG;
    }
	else
	{
		/* chan map init */
		const mbconfig_t *pxmbconf = pxMailBoxEB_GetMbConfig( MAILBOX_QCMI_IDN );
		const mbsub_rgn_config_t *pxmbsubregion = pxMailBoxEB_GetSubRegConfig( MAILBOX_QCMI_IDN );
		const mb_desc_t *pxmbdesc = (const mb_desc_t*)pxmbconf->mblocator;
		/* init chans as per runtime req */
		if( MB_E_SUCCESS != LibMB_ChanMapInit( pxmbconf, pxmbsubregion ))
		{
			DEBUG_LOG( SAIL_ERROR,"vMailBox_Enable(%d): Chan Map Init failed.\n\r", ulcore);
			slstatus = MB_E_INVALID_CFG;
		}
		else
		{
			/* register for IPC Intr. */
			if( MB_E_SUCCESS == prvEB_IPCC_RegisterInterrupt( ulcore ) )
			{
				prvEBWrCoreStatus( ulcore, MB_CONFIGURED );
				/* last status */
				if( MB_INITIIALIZED < prvEBBCKRdCoreStatus( ulcore ) )
				{
					/* pass? ok: reinstall */
					if( MB_E_SUCCESS != LibMB_Validate( pxmbdesc ) )
					{
						slstatus = MB_E_INVALID_MAILBOX;
						DEBUG_LOG( SAIL_ERROR,"vMailBox_Enable(%d): eb validate failed\n\r", ulcore );
					}
					else
					{
						prvEBWrCoreStatus( ulcore, MB_E2EREADY );
					}
				}
				DEBUG_LOG( SAIL_ERROR,"vMailBox_Enable(%d): success, status %d\n\r", ulcore, prvEBRdCoreStatus(ulcore));
			}
			else
			{
				slstatus = MB_E_INVALID_CFG;
				DEBUG_LOG( SAIL_ERROR,"vMailBox_Enable(%d): failed, MB_E_INVALID_CFG\n\r", ulcore);
			}
		}
	}
	return slstatus;
}

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
MAILBOX_EXT_FUNC int32 slMailBox_DeInit(void)
{
	int32 slstatus  = MB_E_SUCCESS;
	/* Get the Current CPU Id.*/
	uint32 ulcore = mailboxEB_COREMAX;
	if( MB_E_SUCCESS != prvEBGetCore( &ulcore ) )
	{
		slstatus = MB_E_INVALID_INDEX;
	}
	/* detach clients */
	if( MB_E_SUCCESS != slstatus )
	{
        DEBUG_LOG( SAIL_ERROR,"slMailBox_DeInit(%d): failed, MB_E_INVALID_INDEX\n\r", ulcore );
	}
	else if(MB_UNINITIALIZED == prvEBRdCoreStatus( ulcore ))
	{
		DEBUG_LOG( SAIL_ERROR,"slMailBox_DeInit(%d): retry, already in deinit state\n\r", ulcore );	
	}
	else
	{
		/* update status */
		if( MB_E_SUCCESS != prvEB_IPCC_DeRegisterInterrupt( ulcore ) )
		{
			slstatus = MB_E_INVALID_CFG;
			DEBUG_LOG( SAIL_ERROR, "slMailBox_DeInit(%d): IPCC DeRegister failed, status %d\n\r", ulcore, prvEBRdCoreStatus( ulcore ) );
		}
		else if( MB_E_SUCCESS != prvEB_IPCC_DettachEx( ulcore ) )
		{
			slstatus = MB_E_INVALID_CFG;
			DEBUG_LOG( SAIL_ERROR, "slMailBox_DeInit(%d): IPCC Detach failed.\n\r", ulcore );
		}
		else
		{
			prvEBWrCoreStatus( ulcore, MB_UNINITIALIZED );
			DEBUG_LOG( SAIL_ERROR,"slMailBox_DeInit(%d): success, status %d\n\r", ulcore, prvEBRdCoreStatus( ulcore ) );
		}
	}
	return slstatus;
}

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
)
{
	xEBClientCbkDesc_t *pxEBClientCbkDesc = NULL;
	int32 slstatus = MB_E_SUCCESS;
	if((MAILBOX_EBMAX > MBclient_ID) && ((xMailboxExtclienttype)0 <= MBclient_ID))
	{
		pxEBClientCbkDesc = prvEBGetEBCbkHandle( (uint32_t)MBclient_ID );
		pxEBClientCbkDesc->NotifPtr = Callbackfunctionptr;
		/* load whole cache line */
		pxEBClientCbkDesc->_cdminline[0] = 0xFFU;
	}
	else
	{
		slstatus = MB_E_INVALID_INDEX;
		DEBUG_LOG( SAIL_DEBUG,"vMailboxClientReg(): Invalid Param...%d\n\r", MBclient_ID );
	}
	return slstatus;
}

/*==============================================================================
 @Service name        prvMailboxEBChanHandler
 @Description         Interrupt handler for EB client channels.
 @param[in]           nData - custom data
                      eSenderID - Sender ID
                      nSignal - Signal Id
 @param[out]          NA
 @param[in, out]      NA
 @return              NA
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC static void prvMailboxEBChanHandler
( 
	IPCC_CBData nData,
	IPCC_Client eSenderID,
	IPCC_Signal nSignal
)
{
	const xMailboxEBChanRec_t *pMailboxChanRec = NULL;
	const xMailboxEBClientRec_t *pMailboxClientRec = nData;
	xMailboxExtclienttype eClient = MAILBOX_EBMAX;
	uint32 ulcore = 0U;
	if(MB_E_SUCCESS != prvEBGetCore( &ulcore ))
	{
		DEBUG_LOG( SAIL_ERROR, "prvMailboxEBChanHandler() failed, core %d\n\r", ulcore );
	}
	else
	{
		if( NULL != pMailboxClientRec )
		{
			pMailboxChanRec = &pMailboxClientRec->ChanRec[MB_CHAN_RD_MODE];
			if( NULL != pMailboxChanRec )
			{
				eClient  =  pMailboxChanRec->eClient;
				invalidate_dcache();
			}
		}
		/* check client */
		if( MB_E_SUCCESS == prvMailboxSMIOSanityCheck( eClient ))
		{
			xEBClientCbkDesc_t *pxEBClientCbkDesc = prvEBGetEBCbkHandle( (uint32_t)eClient );
			/* decouple event on the basis client cfg design */
			if((NULL != pMailboxChanRec) && (NULL != pMailboxChanRec->pDbgCnt))
			{
				++(*pMailboxChanRec->pDbgCnt);
			}
			/* check valid handle */
			if((NULL != pxEBClientCbkDesc) && (NULL != pxEBClientCbkDesc->NotifPtr ))
			{
				pxEBClientCbkDesc->NotifPtr( eClient );
			}
			else
			{
				/* record event */
				DEBUG_LOG( SAIL_INFO, "prvMailboxEBChanHandler() default...%d\n\r", eClient );
			}
		}
		else
		{
			/* record event */
			DEBUG_LOG( SAIL_ERROR, "prvMailboxEBChanHandler() EIO default...%d\n\r", eClient );
		}
	}
	return;
}

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
MAILBOX_EXT_FUNC int32 slMailBoxEB_Init(void)
{
	uint32_t log_data = 0U;
	int32 sllStatus   = MB_E_INVALID_CFG;
	uint32 ulcore     = 0U;
    const mbconfig_t *pxmbconf = pxMailBoxEB_GetMbConfig( MAILBOX_QCMI_IDN );
    const mbsub_rgn_config_t *pxmbsubregion = pxMailBoxEB_GetSubRegConfig( MAILBOX_QCMI_IDN );
	mb_desc_t *pxmbdesc = (mb_desc_t*)pxmbconf->mblocator;
	if(MB_E_SUCCESS != prvEBGetCore( &ulcore ))
	{
		sllStatus = MB_E_INVALID_INDEX;
	}
	else if( MB_E_SUCCESS == LibMB_Create( pxmbdesc, pxmbconf, pxmbsubregion))
    {
        DEBUG_LOG( SAIL_ERROR, "slMailBoxEB_Init(%d): Mailbox installation done\n\r", ulcore);
		prvEBWrCoreStatus( ulcore, MB_INITIIALIZED );
		sllStatus = MB_E_SUCCESS;
		(log_data) = (uint32_t)EXT_MAILBOX;
		(void)vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data , 1);
    }
    else
    {
        DEBUG_LOG( SAIL_ERROR, "slMailBoxEB_Init(%d): Mailbox installation failed\n\r", ulcore);
    }
    return sllStatus;
}

/*=============================================================================
 @Service name        slMailboxSendTrigger(xMailboxExtclienttype MBclient_ID)
 @Description         This API shall used to trigger the corresponding
					  IPC interrupt to configured client domain.
					  API provided to QC SM application use case.
					  AoU: before calling this API, the data is writtern 
					  into the DDR region. This funciton only triggers the
					  interrupt to the destination client.
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
MAILBOX_EXT_FUNC int32 slMailboxSendTrigger(xMailboxExtclienttype MBclient_ID)
{
	const mbsub_rgn_config_t *pmbsubrgn = NULL;
	const xMailboxEBClientRec_t *pMailboxClientRec = NULL;
	const xMailboxEBChanRec_t *pMailboxChanRec = NULL;
	uint32_t ulpid = 0U;
	int32 slStatus = MB_E_NOT_READY;
	uint32 ulcore = mailboxEB_COREMAX;
	prvEBGetCore( &ulcore );

	if( MB_E_SUCCESS == prvMailboxSMIOSanityCheck( MBclient_ID ) )
	{
		/* get client cnfg rec */
		pMailboxClientRec = &xMailboxClientRec[MBclient_ID];
		pMailboxChanRec   = &pMailboxClientRec->ChanRec[MB_CHAN_WR_MODE];
		/* get mb ipc cfg */
		pmbsubrgn = ( const mbsub_rgn_config_t *)pMailboxChanRec->pRgnCfg;
		/* activate trig */
		if(NULL != pmbsubrgn)
		{
			slStatus = MB_E_SUCCESS;
			if((uint32_t)IPCC_P_MPROC == pmbsubrgn->prot )
			{
				ulpid = mailboxEB_IPC_MPROC;
			}
			else if((uint32_t)IPCC_P_COMPUTEL0 == pmbsubrgn->prot )
			{
				ulpid = mailboxEB_IPC_CL0;
			}
			else if((uint32_t)IPCC_P_COMPUTEL1 == pmbsubrgn->prot )
			{
				ulpid = mailboxEB_IPC_CL1;
			}
			else
			{
				slStatus = MB_E_INVALID_CFG;
			}
			/* trig event */
			if((MB_E_SUCCESS == slStatus) && ((IPCC_Status_t) IPCC_EOK != \
					IPCC_Trigger( xMailboxExt_IpccHandle[ulcore][ulpid], (IPCC_Client)pmbsubrgn->sender, \
																(IPCC_Signal)pmbsubrgn->sig, \
																(IPCC_Signal)pmbsubrgn->sig)))
			{
				slStatus = MB_E_TRIG;
				DEBUG_LOG( SAIL_DEBUG, "MailboxEB: slMailboxSendTrigger(p%d) trig error, %d\n\r", ulpid, MBclient_ID );
			}
			/* dbgcnt update */
			if((NULL != pMailboxChanRec) && (NULL != pMailboxChanRec->pDbgCnt))
			{
				++(*pMailboxChanRec->pDbgCnt);
			}
		}
	}
	return slStatus;
}

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
MAILBOX_EXT_FUNC int32 slMailboxChanSendTrigger
( 
	xMailboxExtclienttype MBclient_ID,
	xMailboxExtChanType ChanType
)
{
	const mbsub_rgn_config_t *pmbsubrgn = NULL;
	const xMailboxEBClientRec_t *pMailboxClientRec = NULL;
	const xMailboxEBChanRec_t *pMailboxChanRec = NULL;
	uint32_t ulpid = 0U;
	int32 slStatus = MB_E_NOT_READY;
	/* Get the Current CPU Id.*/
	uint32 ulcore = mailboxEB_COREMAX;
	prvEBGetCore( &ulcore );

	if((ChanType < MB_MSG_RD_CHAN) || (ChanType > MB_MSG_WR_CHAN))
	{
		slStatus = MB_E_INVALID_INDEX;
	}
	else if( MB_E_SUCCESS == prvMailboxSMIOSanityCheck( MBclient_ID ) )
	{
		/* get client cnfg rec */
		pMailboxClientRec = &xMailboxClientRec[MBclient_ID];
		pMailboxChanRec   = &pMailboxClientRec->ChanRec[ChanType];
		/* get mb ipc cfg */
		pmbsubrgn = ( const mbsub_rgn_config_t *)pMailboxChanRec->pRgnCfg;
		/* activate trig */
		if(NULL != pmbsubrgn)
		{
			slStatus = MB_E_SUCCESS;
			if((uint32_t)IPCC_P_MPROC == pmbsubrgn->prot )
			{
				ulpid = mailboxEB_IPC_MPROC;
			}
			else if((uint32_t)IPCC_P_COMPUTEL0 == pmbsubrgn->prot )
			{
				ulpid = mailboxEB_IPC_CL0;
			}
			else if((uint32_t)IPCC_P_COMPUTEL1 == pmbsubrgn->prot )
			{
				ulpid = mailboxEB_IPC_CL1;
			}
			else
			{
				slStatus = MB_E_INVALID_CFG;
			}
			/* trig event */
			if((MB_E_SUCCESS == slStatus) && ((IPCC_Status_t) IPCC_EOK != \
					IPCC_Trigger( xMailboxExt_IpccHandle[ulcore][ulpid], (IPCC_Client)pmbsubrgn->sender, \
																(IPCC_Signal)pmbsubrgn->sig, \
																(IPCC_Signal)pmbsubrgn->sig)))
			{
				slStatus = MB_E_TRIG;
				DEBUG_LOG( SAIL_DEBUG, "MailboxEB: slMailboxSendTrigger(p%d) trig error, %d\n\r", ulpid, MBclient_ID );
			}
			/* dbgcnt update */
			if((NULL!= pMailboxChanRec) && (NULL != pMailboxChanRec->pDbgCnt))
			{
				++(*pMailboxChanRec->pDbgCnt);
			}
		}
	}
	else
	{
		;/*do nothing*/
	}
	return slStatus;
}

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
MAILBOX_EXT_FUNC int32 slMailboxWrite(xMailboxExtclienttype MBclient_ID, uint32 num_item, uint8 *wbuff)
{
	const xMailboxEBClientRec_t *pMailboxClientRec = NULL;
	const xMailboxEBChanRec_t *pMailboxChanRec = NULL;
	mb_desc_t *pxmbdesc = NULL;
	int32 slStatus = MB_E_NOT_READY;
	if( MB_E_SUCCESS == prvMailboxIOSanityCheck( MBclient_ID ) )
	{
		/* get client cnfg rec */
		pMailboxClientRec = &xMailboxClientRec[MBclient_ID];
		pMailboxChanRec   = &pMailboxClientRec->ChanRec[MB_CHAN_WR_MODE];
		pxmbdesc = (mb_desc_t*)pMailboxChanRec->MbAddress;
		slStatus = slMailbox_Get_FreeItemNum(MBclient_ID);
		if(0 >= slStatus )
		{
			DEBUG_LOG( SAIL_DEBUG, "MailboxEB: slMailboxWrite() no free item, %d\n\r", MBclient_ID);
		}
		else if(mailboxEB_QCMI_NUMSUBREGION > (uint32)pMailboxChanRec->ChanId)
		{
			slStatus = LibMB_Write(pxmbdesc, wbuff, num_item, (uint32)pMailboxChanRec->ChanId);
		}
		else
		{
			slStatus = MB_E_INVALID_INDEX;
		}
		if(slStatus > 0)
		{
			if(MB_E_SUCCESS != slMailboxChanSendTrigger(MBclient_ID, MB_MSG_WR_CHAN))
			{
				slStatus = MB_E_TRIG;
				DEBUG_LOG( SAIL_DEBUG, "MailboxEB: slMailboxWrite() trig error, %d\n\r", MBclient_ID);
			}
		}
	}
	return slStatus;
}

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
MAILBOX_EXT_FUNC int32 slMailboxRead(xMailboxExtclienttype MBclient_ID,uint32 num_item,uint8 *rbuff)
{
	const xMailboxEBClientRec_t *pMailboxClientRec = NULL;
	const xMailboxEBChanRec_t *pMailboxChanRec = NULL;
	mb_desc_t *pxmbdesc = NULL;
	int32 slStatus = MB_E_NOT_READY;
	if( MB_E_SUCCESS == prvMailboxIOSanityCheck( MBclient_ID ) )
	{
		/* get client cnfg rec */
		pMailboxClientRec = &xMailboxClientRec[MBclient_ID];
		pMailboxChanRec   = &pMailboxClientRec->ChanRec[MB_CHAN_RD_MODE];
		pxmbdesc = (mb_desc_t*)pMailboxChanRec->MbAddress;
		slStatus = slMailbox_Get_ValidItemNum(MBclient_ID);
		if(slStatus > 0)
		{
			slStatus = LibMB_Read(pxmbdesc, rbuff, num_item, (uint32)pMailboxChanRec->ChanId);
			if( 0 >= slStatus )
			{
				DEBUG_LOG( SAIL_DEBUG, "slMailboxRead(): rd error, %d \n\r", MBclient_ID);
			}
		}
	}
	return slStatus;
}

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
MAILBOX_EXT_FUNC int32 slMailbox_Get_FreeItemNum(xMailboxExtclienttype MBclient_ID)
{
	const xMailboxEBClientRec_t *pMailboxClientRec = NULL;
	const xMailboxEBChanRec_t *pMailboxChanRec = NULL;
	mb_desc_t *pxmbdesc = NULL;
	int32 slStatus = MB_E_NOT_READY;
	
	if((MAILBOX_EBMAX <= MBclient_ID) || ((xMailboxExtclienttype)0 > MBclient_ID))
	{
		DEBUG_LOG( SAIL_ERROR, "MailboxEB: slMailbox_Get_FreeItemNum failed, MB_E_INVALID_INDEX client %d\n\r", MBclient_ID);
	}
	
	else if( MB_E_SUCCESS == prvMailboxIOSanityCheck( MBclient_ID ) )
	{
		/* get client cnfg rec */
		pMailboxClientRec = &xMailboxClientRec[MBclient_ID];
		pMailboxChanRec   = &pMailboxClientRec->ChanRec[MB_CHAN_WR_MODE];
		pxmbdesc = (mb_desc_t*)pMailboxChanRec->MbAddress;
		if(mailboxEB_QCMI_NUMSUBREGION > (uint32)pMailboxChanRec->ChanId)
		{
			slStatus = LibMB_Get_FreeItemNum(pxmbdesc, (uint32)pMailboxChanRec->ChanId);
		}
		else
		{
			slStatus = MB_E_INVALID_INDEX;
		}
	}
	else
	{
		;/*do nothing*/
	}
	return slStatus;
}

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
MAILBOX_EXT_FUNC int32 slMailbox_Get_ValidItemNum(xMailboxExtclienttype MBclient_ID)
{
	const xMailboxEBClientRec_t *pMailboxClientRec = NULL;
	const xMailboxEBChanRec_t *pMailboxChanRec = NULL;
	mb_desc_t *pxmbdesc = NULL;
	int32 slStatus = MB_E_NOT_READY;
	
	if((MAILBOX_EBMAX <= MBclient_ID) || ((xMailboxExtclienttype)0 > MBclient_ID))
	{
		DEBUG_LOG( SAIL_ERROR, "MailboxEB: slMailbox_Get_ValidItemNum failed, MB_E_INVALID_INDEX client %d\n\r", MBclient_ID);
	}
	
	else if( MB_E_SUCCESS == prvMailboxIOSanityCheck( MBclient_ID ) )
	{
		/* get client cnfg rec */
		pMailboxClientRec = &xMailboxClientRec[MBclient_ID];
		pMailboxChanRec   = &pMailboxClientRec->ChanRec[MB_CHAN_RD_MODE];
		pxmbdesc = (mb_desc_t*)pMailboxChanRec->MbAddress;
		if(mailboxEB_QCMI_NUMSUBREGION > (uint32)pMailboxChanRec->ChanId)
		{
			slStatus = LibMB_Get_ValidItemNum(pxmbdesc, (uint32)pMailboxChanRec->ChanId);
		}
		else
		{
			slStatus = MB_E_INVALID_INDEX;
		}
	}
	else
	{
		;/*do nothing*/
	}
	return slStatus;
}

/*==============================================================================
 @Service name        slMailbox_EBResetRequest
 @Description         reset the channels mapped to core, User can decide the 
					  resetting channel as per requirement otherwise
					  each applicaton empty the stale data at its entry point before
					  proceeding.
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA      
 @return 			  0 on success, on error negative nonzero value
 @Pre                 - 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC int32 slMailbox_EBResetRequest( uint32 core )
{
	uint32 ulcore = 0U;
	uint32 schan  = 0U;
	int32 Status  = MB_E_SUCCESS;
	/* chan map init */
	const mbconfig_t *pxmbconf = pxMailBoxEB_GetMbConfig( MAILBOX_QCMI_IDN );
	const mbsub_rgn_config_t *pxmbsubregion = pxMailBoxEB_GetSubRegConfig( MAILBOX_QCMI_IDN );
	mb_desc_t *pxmbdesc = (mb_desc_t*)pxmbconf->mblocator;
	if((NULL == pxmbsubregion) || (core >= mailboxEB_COREMAX) )
	{
		Status = MB_E_INVALID_INDEX;
		DEBUG_LOG( SAIL_ERROR,"slMailbox_ResetRequest(): eparam\n\r" );
	}
	else if(MB_E_SUCCESS == prvEBGetCore( &ulcore ))
	{
		uint32_t coreStatus = prvEBRdCoreStatus(core);
		if((MB_INITIIALIZED <= coreStatus) && (MB_ABORT > coreStatus))
		{
			for(schan = 0U; schan < (uint32)pxmbconf->num_sub_regions; schan++)
			{
				uint32 receiver = ((uint32)IPCC_C_SAIL0 + core);
				if( receiver == pxmbsubregion[schan].receiver)
				{
					bool blsChanRstSts = LibMB_ChanReset( pxmbdesc, pxmbsubregion, schan);
					if(!blsChanRstSts){ break; }
				}		
			}
			if(pxmbconf->num_sub_regions != schan)
			{ 
				Status = MB_E_INVALID_INDEX;
				DEBUG_LOG( SAIL_ERROR, "slMailbox_ResetRequest(%d):  core %d, failed schan %d rst error\n\r", ulcore, core, schan);
			}
			else
			{
				DEBUG_LOG( SAIL_ERROR, "slMailbox_ResetRequest(%d): core %d, success\n\r", ulcore,  core);
			}
		}
		else
		{
			Status = MB_E_NOT_READY;
			DEBUG_LOG( SAIL_ERROR, "slMailbox_ResetRequest(): ignored, Ok\n\r");
		}
	}
	else
	{
		Status = MB_E_INVALID_INDEX;
		DEBUG_LOG( SAIL_ERROR, "slMailbox_ResetRequest(): failed\n\r");
	}
	return (Status);
}

/*==============================================================================
 @Service name        eMailbox_Get_Status
 @Description         Get driver global status, on failure 0xFFU
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA      
 @return 			  MB_UNINITIALIZED - Deinit state
					  MB_CONFIGURED	 - Configured state
					  MB_INITIIALIZED - Init state
					  MB_E2EREADY	 - MD and SAIL Driver/RM ready E2E ready
					  MB_ABORT	 - MD and SAIL Driver/RM comm abort
 @Pre                 NA 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC mailboxEBStatusType_e eMailbox_Get_Status(void)
{
	mailboxEBStatusType_e EBStatus = 0xFFU;
	uint32 ulcore = 0U;
	if(MB_E_SUCCESS == prvEBGetCore( &ulcore ))
	{
		EBStatus = prvEBRdCoreStatus( ulcore );
	}
	return (EBStatus);
}

/*==============================================================================
 @Service name        eMailbox_Get_CoreStatus
 @Description         Get driver global status by core, on failure 0xFFU
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA      
 @return 			  MB_UNINITIALIZED - Deinit state
					  MB_CONFIGURED	 - Configured state
					  MB_INITIIALIZED - Init state
					  MB_E2EREADY	 - MD and SAIL Driver/RM ready E2E ready
					  MB_ABORT	 - MD and SAIL Driver/RM comm abort
 @Pre                 NA 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          No
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC mailboxEBStatusType_e eMailbox_Get_CoreStatus(uint32 core)
{
	mailboxEBStatusType_e EBStatus = 0xFFU;
	if(core >= mailboxEB_COREMAX)
	{
		DEBUG_LOG(SAIL_ERROR, "MailboxEB: eMailbox_Get_CoreStatus(%d) ignored\n\r", core);
	}
	else
	{
		DSB;
		EBStatus = prvEBRdCoreStatus( core );
	}
	return (EBStatus);
}

/*==============================================================================
 @Service name        eMailbox_Abort
 @Description         Set driver global status to comm abort 
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
 @Note                QC Internal platform Use Case only
==============================================================================*/
MAILBOX_EXT_FUNC mailboxEBStatusType_e eMailbox_Abort(void)
{
	mailboxEBStatusType_e EBStatus = 0xFFU;
	uint32 ulbckcore = 0U;
	uint32 ulcore = 0U;
	if(MB_E_SUCCESS == prvEBGetCore( &ulcore ))
	{
		ulbckcore = ulcore;
		EBStatus = prvEBRdCoreStatus( ulcore );
		if( MB_ABORT > EBStatus )
		{
			/* bck core status for resuming later */
			libmbcopy_bytes( (void*)prvEBGetCoreBCKStatusPTR() , (void*)prvEBGetCoreStatusPTR() , prvEBGetSZofCoreStatusPTR() );
			DSB;
			for( ulcore = 0U; ulcore < mailboxEB_COREMAX; ulcore++)
			{
				prvEBWrCoreStatus( ulcore , MB_ABORT );
			}
			DSB;
			EBStatus = prvEBRdCoreStatus( ulbckcore );
		}
		else
		{
			DEBUG_LOG(SAIL_INFO, "MailboxEB: eMailbox_Abort() ignored, status %d, core %d\n\r", EBStatus, ulcore);
		}
	}
	return (EBStatus);
}

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
MAILBOX_EXT_FUNC mailboxEBStatusType_e eMailbox_Set_Status( mailboxEBStatusType_e expectedState, uint32 core )
{
	mailboxEBStatusType_e EBStatus = 0xFFU;
	uint32 ulcore = 0U;
	if( ((uint32)expectedState < MB_UNINITIALIZED) || ((uint32)expectedState > MB_ABORT) || (core >= mailboxEB_COREMAX))
	{
		DEBUG_LOG(SAIL_ERROR, "MailboxEB: eMailbox_Set_Status() ignored\n\r");
	}
	else if(MB_E_SUCCESS == prvEBGetCore( &ulcore ))
	{
		{
			DSB;
			{
				prvEBWrCoreStatus( core , expectedState );
			}
			DSB;
		}
		EBStatus = prvEBRdCoreStatus( core );
		DEBUG_LOG(SAIL_INFO, "MailboxEB: eMailbox_Set_Status(%d): success core %d, status %d\n\r", ulcore, core, EBStatus);
	}
	else
	{
		; /* do nothing */
	}
	return (EBStatus);
}

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
MAILBOX_EXT_FUNC mailboxEBStatusType_e eMailbox_SetBCK_Status( mailboxEBStatusType_e expectedState, uint32 core )
{
	mailboxEBStatusType_e EBStatus = 0xFFU;
	uint32 ulcore = 0U;
	if( (expectedState < MB_UNINITIALIZED) || (expectedState > MB_ABORT) || (core >= mailboxEB_COREMAX) )
	{
		DEBUG_LOG(SAIL_ERROR, "MailboxEB: eMailbox_SetBCK_Status() ignored\n\r");
	}
	else if(MB_E_SUCCESS == prvEBGetCore( &ulcore ))
	{
		{
			DSB;
			{
				prvEBBCKWrCoreStatus( core , expectedState );
			}
			DSB;
		}
		EBStatus = prvEBBCKRdCoreStatus( core );
		DEBUG_LOG(SAIL_INFO, "MailboxEB: eMailbox_SetBCK_Status(%d): success core %d, status %d\n\r", ulcore, core, EBStatus);
	}
	else
	{
		; /* do nothing */
	}
	return (EBStatus);
}

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
 @Note                QC Internal platform Use Case only
==============================================================================*/
MAILBOX_EXT_FUNC mailboxEBStatusType_e eMailbox_Resume(void)
{
	mailboxEBStatusType_e EBStatus = 0xFFU;
	uint32 ulcore = 0U;
	if(MB_E_SUCCESS == prvEBGetCore( &ulcore ))
	{
		EBStatus = prvEBRdCoreStatus( ulcore );
		if( MB_ABORT == EBStatus )
		{
			libmbcopy_bytes( (void*)prvEBGetCoreStatusPTR() , (void*)prvEBGetCoreBCKStatusPTR() , prvEBGetSZofCoreStatusPTR() );
			DSB;
			EBStatus = prvEBRdCoreStatus( ulcore );
		}
		else
		{
			DEBUG_LOG(SAIL_INFO, "MailboxEB: eMailbox_Resume() ignored, status %d, core %d\n\r", EBStatus, ulcore);
		}
	}
	return (EBStatus);
}

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
 @Note                QC Internal Use only
==============================================================================*/
MAILBOX_EXT_FUNC void vMailbox_S1_Handler(void)
{
	int32 sllstatus  = MB_E_INVALID_MAILBOX;
	uint32 ulcore = 0U;
	if( MB_E_SUCCESS != prvEBGetCore(&ulcore) )
	{
		DEBUG_LOG(SAIL_ERROR, "MailboxEB: S1 entry invalid core %d\n\r", ulcore);
	}
	else if( prvEBRdCoreStatus( ulcore ) == MB_CONFIGURED )
	{	/* master s1 handler core install the mailbox */
		if( MB_E_SUCCESS == slMailBoxEB_Init() )
		{
			sllstatus = MB_E_SUCCESS;
		}
		/* update in sync core status to init done */
		if(MB_E_SUCCESS == sllstatus)
		{
			{
				uint32_t coreStatus = prvEBRdCoreStatus( ulcore );
				if(( coreStatus == MB_INITIIALIZED ) \
				    || ( coreStatus == MB_CONFIGURED ))
				{
					prvEBWrCoreStatus( ulcore , MB_INITIIALIZED );
				}
				else
				{	/* skip master core */
					DEBUG_LOG( SAIL_ERROR, "mailboxEB: warning ! install core %d out of sync\n\r", ulcore );
				}
			}
			/* bck core status for resuming later */
			DSB;
			{
				prvEBBCKWrCoreStatus( ulcore , prvEBRdCoreStatus( ulcore ) );
			}
			DSB;
		}
	}
	else if( MB_INITIIALIZED == prvEBRdCoreStatus( ulcore ))
	{
		/* update in sync core status to init done */
		{
			/* consider out of sync core again or final retry otherwise something went wrong on other core */
			uint32_t coreStatus = prvEBRdCoreStatus( ulcore );
			if(( coreStatus == MB_INITIIALIZED ) \
				|| ( coreStatus == MB_CONFIGURED ))
			{
				prvEBWrCoreStatus( ulcore , MB_E2EREADY );
				DEBUG_LOG( SAIL_ERROR, "mailboxEB: ready core %d in sync\n\r", ulcore );
			}
			else
			{
				DEBUG_LOG( SAIL_ERROR, "mailboxEB: warning ! ready core %d out of sync\n\r", ulcore );
			}
		}
		/* bck core status for resuming later */
		DSB;
		{
			prvEBBCKWrCoreStatus( ulcore , prvEBRdCoreStatus( ulcore ) );
		}
		DSB;
		#ifdef SAILSW1
			extern void vLogToMBSAILConsole(void);
			vLogToMBSAILConsole();
		#endif
	}
	else
	{
		DEBUG_LOG(SAIL_ERROR, "MB:InStl retry St %d,%d\n\r", prvEBRdCoreStatus( ulcore ), ulcore );
		#ifdef SAILSW1
			extern void vLogToMBSAILConsole(void);
			if(( MB_CONFIGURED < prvEBRdCoreStatus( ulcore ) ) && ( MB_ABORT > prvEBRdCoreStatus( ulcore )))
			{
				vLogToMBSAILConsole();
			}
		#endif
	}
	return;
}

/*==============================================================================
 @Service name        prvEBGetCore
 @Description         core IO config check
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      pCoreID - core value      
 @return 			  NA
 @Pre                 NA 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          -
 @Reentrancy          Yes
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC static int32 prvEBGetCore( uint32 *pCoreID )
{
	int32 sllStatus = MB_E_INVALID_INDEX;
	if( NULL != pCoreID )
	{
		uint32 ulCore  = get_curr_phys_cpu_num();
		if( mailboxEB_COREMAX <= ulCore )
		{
			/* reset index to 0 to avoid invalid out of boundary core reference */
			*pCoreID = mailboxEB_CORE0 ;
			DEBUG_LOG( SAIL_DEBUG, "MailboxEB: prvEBGetCore() failed, MB_E_INVALID_INDEX core %d\n\r", ulCore);
		}
		else
		{
			*pCoreID = ulCore ;
			sllStatus = MB_E_SUCCESS;
		}
	}
	return sllStatus;
}

/*==============================================================================
 @Service name        prvMailboxSMIOSanityCheck
 @Description         IO Sanity check
 @param[in]           MBclient_ID client Idn
 @param[out]          NA
 @param[in, out]      NA     
 @return 			  NA
 @Pre                 NA 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          -
 @Reentrancy          Yes
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC static int32 prvMailboxSMIOSanityCheck( xMailboxExtclienttype MBclient_ID )
{
	/* log error in error case */
	int32 sllStatus = MB_E_SUCCESS;
	uint32 ulcore   = 0U;
	if((MAILBOX_EBMAX <= MBclient_ID) || ((xMailboxExtclienttype)0 > MBclient_ID))
	{
		sllStatus = MB_E_INVALID_INDEX;
		DEBUG_LOG( SAIL_DEBUG, "MailboxEB: prvMailboxSMIOSanityCheck() failed, MB_E_INVALID_INDEX client %d\n\r", MBclient_ID);
	}
	else if( MB_E_SUCCESS != prvEBGetCore(&ulcore) )
	{
		sllStatus = MB_E_INVALID_INDEX;
		DEBUG_LOG( SAIL_DEBUG, "MailboxEB: prvMailboxSMIOSanityCheck() failed, MB_E_INVALID_INDEX core %d\n\r", ulcore);
	}
	else if( ( MAILBOX_SSM == MBclient_ID ) || ( MAILBOX_TSM == MBclient_ID ))
	{	/* MB_INITIIALIZED updated after HLOS_S1_READY, SM can start early accessing DDR  */
		uint32 coreStatus = prvEBRdCoreStatus( ulcore );
		if( ( MB_E2EREADY == coreStatus ) || ( MB_INITIIALIZED == coreStatus ) )
		{
			sllStatus = MB_E_SUCCESS;
		}
		else
		{
			sllStatus = MB_E_NOT_READY;
			DEBUG_LOG( SAIL_DEBUG, "MailboxEB: prvMailboxSMIOSanityCheck() failed, MB_E_NOT_READY core %d\n\r", ulcore);
		}
	}
	else if( MB_E2EREADY == prvEBRdCoreStatus( ulcore ) )
	{
		sllStatus = MB_E_SUCCESS;
	}
	else
	{
		sllStatus = MB_E_NOT_READY;
		DEBUG_LOG( SAIL_DEBUG, "MailboxEB: prvMailboxSMIOSanityCheck() failed, MB_E_NOT_READY core %d\n\r", ulcore);
	}
	return sllStatus;
}

/*==============================================================================
 @Service name        prvMailboxIOSanityCheck
 @Description         IO Sanity check
 @param[in]           MBclient_ID client Idn
 @param[out]          NA
 @param[in, out]      NA     
 @return 			  NA
 @Pre                 NA 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          -
 @Reentrancy          Yes
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC static int32 prvMailboxIOSanityCheck( xMailboxExtclienttype MBclient_ID )
{
	/* log error in error case */
	int32 sllStatus = MB_E_SUCCESS;
	uint32 ulcore   = 0U;
	if((MAILBOX_EBMAX <= MBclient_ID) || ((xMailboxExtclienttype)0 > MBclient_ID))
	{
		sllStatus = MB_E_INVALID_INDEX;
		DEBUG_LOG( SAIL_DEBUG, "MailboxEB: prvMailboxIOSanityCheck() failed, MB_E_INVALID_INDEX client %d\n\r", MBclient_ID);
	}
	else if( ( MAILBOX_SSM == MBclient_ID ) || ( MAILBOX_TSM == MBclient_ID ))
	{
		/* block SM  access to invalid mailbox , not expected */
		sllStatus = MB_E_INVALID_MAILBOX;
		DEBUG_LOG( SAIL_DEBUG, "MailboxEB: prvMailboxIOSanityCheck() failed, MB_E_INVALID_MAILBOX client %d\n\r", MBclient_ID);
	}
	else if( MB_E_SUCCESS != prvEBGetCore(&ulcore) )
	{
		sllStatus = MB_E_INVALID_INDEX;
		DEBUG_LOG( SAIL_DEBUG, "MailboxEB: prvMailboxIOSanityCheck() failed, MB_E_INVALID_INDEX core %d\n\r", ulcore);
	}
	else if( MB_E2EREADY == prvEBRdCoreStatus( ulcore ) )
	{
		sllStatus = MB_E_SUCCESS;
	}
	else
	{
		sllStatus = MB_E_NOT_READY;
		DEBUG_LOG( SAIL_DEBUG, "MailboxEB: prvMailboxIOSanityCheck() failed, MB_E_NOT_READY core %d\n\r", ulcore);
	}
	return sllStatus;
}

/*==============================================================================
 @Service name        prvEB_IPCC_AttachEx
 @Description         IPC Attach Handles
 @param[in]           core Idn
 @param[out]          NA
 @param[in, out]      NA     
 @return 			  NA
 @Pre                 NA 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          -
 @Reentrancy          -
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC static int32 prvEB_IPCC_AttachEx( uint32_t core )
{
	int32 slstatus  = MB_E_SUCCESS;
	/* pick client according to cpu or from cfg record */
	uint32 clientID = (uint32)IPCC_C_SAIL0 + core;
	/* attach handles */
	if( (IPCC_Status_t) IPCC_EOK != IPCC_AttachEx( &xMailboxExt_IpccHandle[core][mailboxEB_IPC_MPROC], IPCC_P_MPROC, (IPCC_Client)clientID, core) )
	{
		slstatus = MB_E_INVALID_INDEX;
		DEBUG_LOG( SAIL_ERROR,"prvEB_IPCCAttachEx(%d):MPROC failed.\n\r", core);
	}
	else if( (IPCC_Status_t) IPCC_EOK != IPCC_AttachEx( &xMailboxExt_IpccHandle[core][mailboxEB_IPC_CL0], IPCC_P_COMPUTEL0, (IPCC_Client)clientID, core) )
	{
		slstatus = MB_E_INVALID_INDEX;
		DEBUG_LOG( SAIL_ERROR,"prvEB_IPCCAttachEx(%d):CL0 failed.\n\r", core);
	}
	else if( (IPCC_Status_t) IPCC_EOK != IPCC_AttachEx( &xMailboxExt_IpccHandle[core][mailboxEB_IPC_CL1], IPCC_P_COMPUTEL1, (IPCC_Client)clientID, core) )
	{
		slstatus = MB_E_INVALID_INDEX;
		DEBUG_LOG( SAIL_ERROR,"prvEB_IPCCAttachEx(%d):CL1 failed.\n\r", core);
	}
	else
	{
		; /* do nothing */
	}
	return slstatus;
}

/*==============================================================================
 @Service name        prvEB_IPCC_DettachEx
 @Description         IPC Dettach Handles
 @param[in]           core Idn
 @param[out]          NA
 @param[in, out]      NA     
 @return 			  NA
 @Pre                 NA 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          -
 @Reentrancy          -
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC static int32 prvEB_IPCC_DettachEx( uint32_t core )
{
	int32 slstatus  = MB_E_SUCCESS;
	/* dettach handles */
	if( (IPCC_Status_t) IPCC_EOK != IPCCDrv_DetachEx( &xMailboxExt_IpccHandle[core][mailboxEB_IPC_MPROC], core ) )
	{
		slstatus = MB_E_INVALID_INDEX;
		DEBUG_LOG( SAIL_ERROR,"prvEB_IPCCDettachEx(%d):MPROC failed.\n\r", core);
	}
	else if( (IPCC_Status_t) IPCC_EOK != IPCCDrv_DetachEx( &xMailboxExt_IpccHandle[core][mailboxEB_IPC_CL0], core ) )
	{
		slstatus = MB_E_INVALID_INDEX;
		DEBUG_LOG( SAIL_ERROR,"prvEB_IPCCDettachEx(%d):CL0 failed.\n\r", core);
	}
	else if( (IPCC_Status_t) IPCC_EOK != IPCCDrv_DetachEx( &xMailboxExt_IpccHandle[core][mailboxEB_IPC_CL1], core ) )
	{
		slstatus = MB_E_INVALID_INDEX;
		DEBUG_LOG( SAIL_ERROR,"prvEB_IPCCDettachEx(%d):CL1 failed.\n\r", core);
	}
	else
	{
		; /* do nothing */
	}
	return slstatus;
}

/*==============================================================================
 @Service name        prvEB_IPCC_RegisterInterrupt
 @Description         Register for Intrrupts
 @param[in]           core Idn
 @param[out]          NA
 @param[in, out]      NA     
 @return 			  NA
 @Pre                 NA 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          -
 @Reentrancy          -
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC static int32 prvEB_IPCC_RegisterInterrupt( uint32_t core )
{
	int32 slstatus = MB_E_SUCCESS;
	const mbsub_rgn_config_t *pmbsubrgn = NULL;
	const xMailboxEBClientRec_t *pMailboxClientRec = NULL;
	const xMailboxEBChanRec_t *pMailboxChanRec = NULL;
	uint32 slcselect = 0U;
	uint32 ulpid = mailboxEB_IPC_MPROC;
	/* global client cfg */
	for(slcselect =0; slcselect < (uint32)MAILBOX_EBMAX; slcselect++)
	{
		/* get client cnfg rec */
		pMailboxClientRec = &xMailboxClientRec[slcselect];
		pMailboxChanRec   = &pMailboxClientRec->ChanRec[MB_CHAN_RD_MODE];
		/* get mb ipc cfg ignore mb instance select */
		pmbsubrgn = pMailboxChanRec->pRgnCfg;
		/* attach handle */
		if(( NULL != pmbsubrgn ) && ( MB_CHAN_RD_MODE == pmbsubrgn->mode ))
		{
			if( (uint32_t)IPCC_P_MPROC == pmbsubrgn->prot )
			{
				ulpid = mailboxEB_IPC_MPROC;
			}
			else if( (uint32_t)IPCC_P_COMPUTEL0 == pmbsubrgn->prot )
			{
				ulpid = mailboxEB_IPC_CL0;
			}
			else if( (uint32_t)IPCC_P_COMPUTEL1 == pmbsubrgn->prot )
			{
				ulpid = mailboxEB_IPC_CL1;
			}
			else
			{
				slstatus = MB_E_INVALID_CFG;
				break;
			}
			/* get handle */
			if( (IPCC_Status_t)IPCC_EOK != IPCC_RegisterInterrupt( xMailboxExt_IpccHandle[core][ulpid],   \
															(IPCC_Client)pmbsubrgn->sender,   \
															(IPCC_Signal)pmbsubrgn->sig,      \
															(IPCC_Signal)pmbsubrgn->sig,      \
															(IPCC_CB)prvMailboxEBChanHandler, \
															(IPCC_CBData)pMailboxClientRec ) )
			{
				DEBUG_LOG( SAIL_ERROR, "prvEB_IPCC_RegisterInterrupt(%d): p%d failed.\n\r", core, ulpid );
				slstatus = MB_E_INVALID_CFG;
				break;
			}
		}
	}
	if( (uint32)MAILBOX_EBMAX != slcselect )
	{
		slstatus = MB_E_INVALID_CFG;
		DEBUG_LOG( SAIL_ERROR, "prvEB_IPCC_RegisterInterrupt(%d):failed.\n\r", core);
	}
	return slstatus;
}

/*==============================================================================
 @Service name        prvEB_IPCC_DeRegisterInterrupt
 @Description         DeRegister Intrrupts
 @param[in]           core Idn
 @param[out]          NA
 @param[in, out]      NA     
 @return 			  NA
 @Pre                 NA 
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          -
 @Reentrancy          -
 @Note                -
==============================================================================*/
MAILBOX_EXT_FUNC static int32 prvEB_IPCC_DeRegisterInterrupt( uint32_t core )
{
	int32 slstatus = MB_E_SUCCESS;
	const mbsub_rgn_config_t *pmbsubrgn = NULL;
	const xMailboxEBClientRec_t *pMailboxClientRec = NULL;
	const xMailboxEBChanRec_t *pMailboxChanRec = NULL;
	uint32 slcselect = 0U;
	uint32 ulpid = mailboxEB_IPC_MPROC;
	/* global client cfg */
	for(slcselect =0; slcselect < (uint32)MAILBOX_EBMAX; slcselect++)
	{
		/* get client cnfg rec */
		pMailboxClientRec = &xMailboxClientRec[slcselect];
		pMailboxChanRec   = &pMailboxClientRec->ChanRec[MB_CHAN_RD_MODE];
		/* get mb ipc cfg ignore mb instance select */
		pmbsubrgn = pMailboxChanRec->pRgnCfg;
		/* attach handle */
		if(( NULL != pmbsubrgn ) && ( MB_CHAN_RD_MODE == pmbsubrgn->mode ))
		{
			if( (uint32_t)IPCC_P_MPROC == pmbsubrgn->prot )
			{
				ulpid = mailboxEB_IPC_MPROC;
			}
			else if( (uint32_t)IPCC_P_COMPUTEL0 == pmbsubrgn->prot )
			{
				ulpid = mailboxEB_IPC_CL0;
			}
			else if( (uint32_t)IPCC_P_COMPUTEL1 == pmbsubrgn->prot )
			{
				ulpid = mailboxEB_IPC_CL1;
			}
			else
			{
				slstatus = MB_E_INVALID_CFG;
				break;
			}
			/* get handle */
			if( (IPCC_Status_t)IPCC_EOK != IPCC_DeregisterInterrupt( xMailboxExt_IpccHandle[core][ulpid],   \
															(IPCC_Client)pmbsubrgn->sender,     	   \
															(IPCC_Signal)pmbsubrgn->sig,        	   \
															(IPCC_Signal)pmbsubrgn->sig ) )
			{
				DEBUG_LOG( SAIL_ERROR, "prvEB_IPCC_DeRegisterInterrupt(%d): p%d , eclient %d failed.\n\r", core, ulpid, slcselect );
				slstatus = MB_E_INVALID_CFG;
				break;
			}
		}
	}
	if( (uint32)MAILBOX_EBMAX != slcselect )
	{
		slstatus = MB_E_INVALID_CFG;
		DEBUG_LOG( SAIL_ERROR, "prvEB_IPCC_DeRegisterInterrupt(%d): eclient %d failed.\n\r", core, slcselect);
	}
	return slstatus;
}

/*==============================================================================
**						Private Helper APIs								
==============================================================================*/
MAILBOX_EXT_FUNC static void prvEBWrCoreStatus( uint32_t core , uint32_t sts )
{
	uint32_t * xEBCoreStatus = NULL;
	do{
		xEBCoreStatus = (void *)SHR_EBSTATUS_ADDRESS;
	} while(NULL == xEBCoreStatus);
	*( ( volatile uint32_t * ) ( ( uintptr_t ) xEBCoreStatus + ( 64U * core ) ) ) = sts;
	return;
}

MAILBOX_EXT_FUNC static uint32_t prvEBRdCoreStatus( uint32_t core )
{
	uint32_t * xEBCoreStatus = NULL;
	do{
		xEBCoreStatus = (void *)SHR_EBSTATUS_ADDRESS;
	} while(NULL == xEBCoreStatus);
	uint32_t sts = *( ( volatile uint32_t * ) ( ( uintptr_t ) xEBCoreStatus + ( 64U * core ) ) );
	return ( sts );
}	

MAILBOX_EXT_FUNC static void prvEBBCKWrCoreStatus( uint32_t core , uint32_t sts )
{
	uint32_t * xEBCoreStatus = NULL;
	do{
		xEBCoreStatus = (void *)SHR_EBBCKSTATUS_ADDRESS;
	} while(NULL == xEBCoreStatus);
	*( ( volatile uint32_t * ) ( ( uintptr_t ) xEBCoreStatus + ( 64U * core ) ) ) = sts;
	return;
}

MAILBOX_EXT_FUNC static uint32_t prvEBBCKRdCoreStatus( uint32_t core )
{
	uint32_t * xEBCoreStatus = NULL;
	do{
		xEBCoreStatus = (void *)SHR_EBBCKSTATUS_ADDRESS;
	} while(NULL == xEBCoreStatus);
	uint32_t sts = *( ( volatile uint32_t * ) ( ( uintptr_t ) xEBCoreStatus + ( 64U * core ) ) );
	return ( sts );
}	

MAILBOX_EXT_FUNC static uint32_t * prvEBGetCoreStatusPTR( void )
{
	uint32_t * xEBCoreStatus = NULL;
	do{
		xEBCoreStatus = (void *)SHR_EBSTATUS_ADDRESS;
	} while(NULL == xEBCoreStatus);
	return ( xEBCoreStatus );
}

MAILBOX_EXT_FUNC static uint32_t * prvEBGetCoreBCKStatusPTR( void )
{
	uint32_t * xEBCoreStatus = NULL;
	do{
		xEBCoreStatus = (void *)SHR_EBBCKSTATUS_ADDRESS;
	} while(NULL == xEBCoreStatus);
	return ( xEBCoreStatus );
}

MAILBOX_EXT_FUNC static void * prvEBGetEBCbkHandle( uint32_t chan )
{
	uint32_t * xEBHandle = NULL;
	do{
		xEBHandle = (void *)SHR_EBMAPVECT_ADDRESS;
	} while(NULL == xEBHandle);
	volatile xEBClientCbkDesc_t * xEBCbkHandle = NULL;
	do{
		xEBCbkHandle = ( ( volatile xEBClientCbkDesc_t * ) ( ( uintptr_t ) xEBHandle + ( sizeof( xEBClientCbkDesc_t ) * chan ) ) );
	} while(NULL == xEBCbkHandle);
	return ( (void*)xEBCbkHandle );
}

MAILBOX_EXT_FUNC static uint32_t prvEBGetSZofCoreStatusPTR( void )
{
	uint32_t SZofCoreStatusPTR = (64U * mailboxEB_COREMAX);
	return ( SZofCoreStatusPTR );
}
/*==============================================================================
**						Debug support APIs								
==============================================================================*/
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
MAILBOX_EXT_FUNC int32_t slMailboxEBDebugEventCnt( xMailboxExtclienttype client , uint32_t rwtype )
{	
	int32_t sllStatus = MB_E_INVALID_INDEX;
	const xMailboxEBChanRec_t *pMailboxChanRec = NULL;
	if((MAILBOX_EBMAX <= client) || ((xMailboxExtclienttype)0 > client))
	{
		sllStatus = MB_E_INVALID_INDEX;
	}
	else if( (MB_CHAN_RD_MODE != rwtype) && (MB_CHAN_WR_MODE != rwtype) )
	{
		sllStatus = MB_E_INVALID_INDEX;
	}
	else
	{
		/* get client cnfg rec */
		pMailboxChanRec = &xMailboxClientRec[client].ChanRec[rwtype];
		if( NULL != pMailboxChanRec->pDbgCnt )
		{
			sllStatus =	(int32_t)*( pMailboxChanRec->pDbgCnt );
		}
		else
		{
			sllStatus = MB_E_NULL_INPUT;
		}
	}
	return (sllStatus);
}

#ifdef MAILBOX_TEST_ENABLE
    #include "mailbox_ut.h"
#endif
/*==============================================================================
** 									EOF 
==============================================================================*/
