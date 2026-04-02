/*
  ===========================================================================
*/
/**
  @file mailboxExt_config.c
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
/*==============================================================================
**                                 Include files                              **
================================================================================*/
#include <stdio.h>
#include "mailboxLib.h"
#include "mailboxExt_api.h"
#include "mailboxExt_config.h"
/*==============================================================================
**         Global variables and constants - External Mailbox                  **
==============================================================================*/
/* Configuration structure for mailbox */
mailboxEB_CONST static const mbconfig_t MailboxExt_SAILConfig[mailboxEB_TOTALNUMEXTERNAL] =
{
    {
        "MAILBOX_QCMI_IDN",	/* Name */
		mailboxEB_QCMI_SZ,	/* SZ preconfigured page */
		mailboxEB_QCMI_PRIORITY, /* Nominal run priorty */
		mailboxEB_QCMI_NUMSUBREGION, /* Max RW channels or clients supported mailbox */
		mailboxEB_QCMI_ADDR	/* EB handle */
    },
};
/* attention : updating of RO region only allowed from startup or privi mode but not 
   once OS sched started X: abort exception triggered */
/* Configuration structures for mailbox HLOS QCMI sub-Regions +
	( SSM & TSM placeholder dummy entry ) */
/* SAIL HLOS comm protocol switched to compute L1 line after ES8 baseline */
mailboxEB_DATA static mbsub_rgn_config_t Mailbox_QCMISubRegionCfg[EB_CHAN_MAX] =
{
	/* Do not change QC defined node nomenclature , node sz { 12 char + last '0' or '1' } suffix 
	 * Name: /dev/sail/pm0
     * Description: power management read channel used to receive data from MD related to cx,mx voting
     */
    {
        "/dev/sail/pm0",				// "/dev/sail/Nameofnode0" : for sail each read node naming rule
		(uint32)IPCC_C_APPS,					// tx client selection 
	    (uint32)IPCC_C_SAIL0,					// rx client selection
	    (uint32)IPCC_P_COMPUTEL1,					// protocol selection
	    mailboxEB_CHAN_PMU_RX_IDN_SIGID,		// should be only unique for each qcmi resource manager client chan 
		MB_CHAN_RD_MODE,				// chan type SAIL RD other domain !of chan
		mailboxEB_QCMI_PRIORITY,		// Prio of dev event handling 
	    MB_DEFAULT_CHAN_OFFSET,			// default placeholder
	    MB_DEFAULT_CHAN_OFFSET,			// default placeholder	
	    mailboxEB_CHAN_PMU_RX_IDN_NUMITEM,	// chan max bandwidth 
	    mailboxEB_CHAN_PMU_RX_IDN_ITEMSIZE 	// chan smallest data transfer unit in no. of bytes 1 or greater than 1 
    },
	/* Do not change ....
	 * Name: /dev/sail/pm1
     * Description: power management write channel used to send data to MD related to cx,mx voting
     */
    {
        "/dev/sail/pm1",           		// "/dev/sail/Nameofnode1" : for sail each write node naming rule
		(uint32)IPCC_C_APPS,					// tx client selection 
	    (uint32)IPCC_C_SAIL0,               	// rx client selection
	    (uint32)IPCC_P_COMPUTEL1,               	// protocol selection
	    mailboxEB_CHAN_PMU_TX_IDN_SIGID,      // should be only unique for each qcmi resource manager client chan 
		MB_CHAN_WR_MODE,            	// chan type SAIL RD other domain !of chan
		mailboxEB_QCMI_PRIORITY,        // Prio of dev event handling 
	    MB_DEFAULT_CHAN_OFFSET,    		// default placeholder
	    MB_DEFAULT_CHAN_OFFSET,    		// default placeholder	
	    mailboxEB_CHAN_PMU_TX_IDN_NUMITEM,	// chan max bandwidth 
	    mailboxEB_CHAN_PMU_TX_IDN_ITEMSIZE 	// chan smallest data transfer unit in no. of bytes 1 or greater than 1 
    },
	/* Do not change ....
	 * Name: /dev/sail/uss0
     * Description: demo read channel used to receive data related to USS from MD
     */
    {
        "/dev/sail/uss0",
		(uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL1,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_ULS_RX_IDN_SIGID,
		MB_CHAN_RD_MODE,
	    mailboxEB_QCMI_PRIORITY,
	    MB_DEFAULT_CHAN_OFFSET,
	    MB_DEFAULT_CHAN_OFFSET,
	    mailboxEB_CHAN_ULS_RX_IDN_NUMITEM,
	    mailboxEB_CHAN_ULS_RX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/uss1
     * Description: demo write channel used to send data related to USS to MD 
     */
    {
        "/dev/sail/uss1",
		(uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL1,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_ULS_TX_IDN_SIGID,
		MB_CHAN_WR_MODE,
	    mailboxEB_QCMI_PRIORITY,
	    MB_DEFAULT_CHAN_OFFSET,
	    MB_DEFAULT_CHAN_OFFSET,
	    mailboxEB_CHAN_ULS_TX_IDN_NUMITEM,
	    mailboxEB_CHAN_ULS_TX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/tst0
     * Description: MBTF read channel used to receive MBTF related data from MD  
     */
    {
        "/dev/sail/tst0",
		(uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL0,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_TST_RX_IDN_SIGID,
		MB_CHAN_RD_MODE,
	    mailboxEB_QCMI_PRIORITY,
	    MB_DEFAULT_CHAN_OFFSET,
	    MB_DEFAULT_CHAN_OFFSET,
	    mailboxEB_CHAN_TST_RX_IDN_NUMITEM,
	    mailboxEB_CHAN_TST_RX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/tst1
     * Description: MBTF write channel used to send MBTF result data to MD
     */
    {
        "/dev/sail/tst1",
		(uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL0,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_TST_TX_IDN_SIGID,
		MB_CHAN_WR_MODE,
	    mailboxEB_QCMI_PRIORITY,
	    MB_DEFAULT_CHAN_OFFSET,
	    MB_DEFAULT_CHAN_OFFSET,
	    mailboxEB_CHAN_TST_TX_IDN_NUMITEM,
	    mailboxEB_CHAN_TST_TX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/log
     * Description: sail debug log logger write channel used to send data to MD(HLOS\UEFI)
     */
    {
        "/dev/sail/log",
		(uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL0,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_CONSOLE_TX_IDN_SIGID,
		MB_CHAN_WR_MODE,
	    mailboxEB_QCMI_PRIORITY,
	    MB_DEFAULT_CHAN_OFFSET,
	    MB_DEFAULT_CHAN_OFFSET,
	    mailboxEB_CHAN_CONSOLE_TX_IDN_NUMITEM,
	    mailboxEB_CHAN_CONSOLE_TX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/ota0
     * Description: OTA read channel used to receive data related to OTA from MD 
     */
    {
        "/dev/sail/ota0",
		(uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL0,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_OTA_RX_IDN_SIGID,
		MB_CHAN_RD_MODE,
	    mailboxEB_QCMI_PRIORITY,
		MB_DEFAULT_CHAN_OFFSET,
		MB_DEFAULT_CHAN_OFFSET,
		mailboxEB_CHAN_OTA_RX_IDN_NUMITEM,
		mailboxEB_CHAN_OTA_RX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/ota1
     * Description: OTA write channel used to send data related to OTA to MD 
     */
    {
        "/dev/sail/ota1",
		(uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL0,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_OTA_TX_IDN_SIGID,
		MB_CHAN_WR_MODE,
	    mailboxEB_QCMI_PRIORITY,
		MB_DEFAULT_CHAN_OFFSET,
		MB_DEFAULT_CHAN_OFFSET,
		mailboxEB_CHAN_OTA_TX_IDN_NUMITEM,
		mailboxEB_CHAN_OTA_TX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/tmu0
     * Description: thermal management unit read channel used to receive updates related to thermal sensor data from MD 
     */
	{
        "/dev/sail/tmu0",
		(uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL0,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_TMU_RX_IDN_SIGID,
		MB_CHAN_RD_MODE,
	    mailboxEB_QCMI_PRIORITY,
		MB_DEFAULT_CHAN_OFFSET,
		MB_DEFAULT_CHAN_OFFSET,
		mailboxEB_CHAN_TMU_RX_IDN_NUMITEM,
		mailboxEB_CHAN_TMU_RX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/tmu1
     * Description: thermal management unit write channel used to send updates related to thermal sensor data to MD
     */
    {
        "/dev/sail/tmu1",
		(uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL0,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_TMU_TX_IDN_SIGID,
		MB_CHAN_WR_MODE,
	    mailboxEB_QCMI_PRIORITY,
		MB_DEFAULT_CHAN_OFFSET,
		MB_DEFAULT_CHAN_OFFSET,
		mailboxEB_CHAN_TMU_TX_IDN_NUMITEM,
		mailboxEB_CHAN_TMU_TX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/ptp0
     * Description: time sync read channel used to receive updates from MD
     */
	{
        "/dev/sail/ptp0",
		(uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL2,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_PTP_RX_IDN_SIGID,
		MB_CHAN_RD_MODE,
	    mailboxEB_QCMI_PRIORITY,
		MB_DEFAULT_CHAN_OFFSET,
		MB_DEFAULT_CHAN_OFFSET,
		mailboxEB_CHAN_PTP_RX_IDN_NUMITEM,
		mailboxEB_CHAN_PTP_RX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/ptp1
     * Description: time sync write channel used to send updates to MD
     */
    {
        "/dev/sail/ptp1",
		(uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL2,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_PTP_TX_IDN_SIGID,
		MB_CHAN_WR_MODE,
	    mailboxEB_QCMI_PRIORITY,
		MB_DEFAULT_CHAN_OFFSET,
		MB_DEFAULT_CHAN_OFFSET,
		mailboxEB_CHAN_PTP_TX_IDN_NUMITEM,
		mailboxEB_CHAN_PTP_TX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/can0
     * Description: CAN read channel used to receive data related to CAN from MD 
     */
	{
        "/dev/sail/can0",
		(uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL1,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_CAN_RX_IDN_SIGID,
		MB_CHAN_RD_MODE,
	    mailboxEB_QCMI_PRIORITY,
		MB_DEFAULT_CHAN_OFFSET,
		MB_DEFAULT_CHAN_OFFSET,
		mailboxEB_CHAN_CAN_RX_IDN_NUMITEM,
		mailboxEB_CHAN_CAN_RX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/can1
     * Description: CAN write channel used to send data related to CAN to MD
     */
    {
        "/dev/sail/can1",
		(uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL1,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_CAN_TX_IDN_SIGID,
		MB_CHAN_WR_MODE,
	    mailboxEB_QCMI_PRIORITY,
		MB_DEFAULT_CHAN_OFFSET,
		MB_DEFAULT_CHAN_OFFSET,
		mailboxEB_CHAN_CAN_TX_IDN_NUMITEM,
		mailboxEB_CHAN_CAN_TX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/power
     * Description:  write channel used to send data related to power to MD
     */
    {
        "/dev/sail/pwr1",
		(uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL2,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_POWER_TX_IDN_SIGID,
		MB_CHAN_WR_MODE,
	    mailboxEB_QCMI_PRIORITY,
		MB_DEFAULT_CHAN_OFFSET,
		MB_DEFAULT_CHAN_OFFSET,
		mailboxEB_CHAN_POWER_TX_IDN_NUMITEM,
		mailboxEB_CHAN_POWER_TX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/fzr0
     * Description: read channel used to receive data related to fuse from MD
     */
	{
        "/dev/sail/fzr0",
		(uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL1,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_FUSE_RX_IDN_SIGID,
		MB_CHAN_RD_MODE,
	    mailboxEB_QCMI_PRIORITY,
	    MB_DEFAULT_CHAN_OFFSET,
	    MB_DEFAULT_CHAN_OFFSET,
	    mailboxEB_CHAN_FUSE_RX_IDN_NUMITEM,
	    mailboxEB_CHAN_FUSE_RX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/fzt1
     * Description: write channel used to send data related to fuse to MD
     */
    {
        "/dev/sail/fzt1",
		(uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL1,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_FUSE_TX_IDN_SIGID,
		MB_CHAN_WR_MODE,
	    mailboxEB_QCMI_PRIORITY,
	    MB_DEFAULT_CHAN_OFFSET,
	    MB_DEFAULT_CHAN_OFFSET,
	    mailboxEB_CHAN_FUSE_TX_IDN_NUMITEM,
	    mailboxEB_CHAN_FUSE_TX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/stz0
     * Description: read channel for TEE usecases
     */
	{
        "/dev/sail/stz0",
		(uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL0,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_STZ_RX_IDN_SIGID,
		MB_CHAN_RD_MODE,
	    mailboxEB_QCMI_PRIORITY,
	    MB_DEFAULT_CHAN_OFFSET,
	    MB_DEFAULT_CHAN_OFFSET,
	    mailboxEB_CHAN_STZ_RX_IDN_NUMITEM,
	    mailboxEB_CHAN_STZ_RX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/stz1
     * Description: write channel for TEE usecases
     */
    {
        "/dev/sail/stz1",
		(uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL0,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_STZ_TX_IDN_SIGID,
		MB_CHAN_WR_MODE,
	    mailboxEB_QCMI_PRIORITY,
	    MB_DEFAULT_CHAN_OFFSET,
	    MB_DEFAULT_CHAN_OFFSET,
	    mailboxEB_CHAN_STZ_TX_IDN_NUMITEM,
	    mailboxEB_CHAN_STZ_TX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/sm0
     * Description: safety monitor read channel placeholder used for health monitoring data exchange between SAIL and MD
     */
	{
		"/dev/sail/sm0",
        (uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL2,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_SSM_RX_IDN_SIGID,
		MB_CHAN_RD_MODE,
		mailboxEB_QCMI_PRIORITY,
		MB_DEFAULT_CHAN_OFFSET,	
	    MB_DEFAULT_CHAN_OFFSET,
	    mailboxEB_CHAN_SSM_RX_IDN_NUMITEM,
	    mailboxEB_CHAN_SSM_RX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/sm1
     * Description: safety monitor write channel placeholder used for health monitoring data exchange between SAIL and MD
     */
	{	/* placeholder for ssm */
		"/dev/sail/sm1",
        (uint32)IPCC_C_APPS,
	    (uint32)IPCC_C_SAIL2,
	    (uint32)IPCC_P_COMPUTEL1,
	    mailboxEB_CHAN_SSM_TX_IDN_SIGID,
		MB_CHAN_WR_MODE,
		mailboxEB_QCMI_PRIORITY,
		MB_DEFAULT_CHAN_OFFSET,
	    MB_DEFAULT_CHAN_OFFSET,
	    mailboxEB_CHAN_SSM_TX_IDN_NUMITEM,
		mailboxEB_CHAN_SSM_TX_IDN_ITEMSIZE
    },
	/* Do not change ....
	 * Name: /dev/sail/tz0
     * Description: trust zone read channel placeholder used for fatal error communication between SAIL and MD
     */
	{	/* placeholder for tsm */
		"/dev/sail/tz0",
        (uint32)IPCC_C_TZ,
	    (uint32)IPCC_C_SAIL2,
	    (uint32)IPCC_P_MPROC,
	    mailboxEB_CHAN_TSM_RX_IDN_SIGID,
		MB_CHAN_RD_MODE,
		mailboxEB_QCMI_PRIORITY,
		MB_DEFAULT_CHAN_OFFSET,
	    MB_DEFAULT_CHAN_OFFSET,
	    mailboxEB_CHAN_TSM_RX_IDN_NUMITEM,
	    mailboxEB_CHAN_TSM_RX_IDN_ITEMSIZE
	},
	/* Do not change ....
	 * Name: /dev/sail/tz1
     * Description: trust zone write channel placeholder used for fatal error communication between SAIL and MD
     */
    {	/* placeholder for tsm */
		"/dev/sail/tz1",
        (uint32)IPCC_C_TZ,
	    (uint32)IPCC_C_SAIL2,
	    (uint32)IPCC_P_MPROC,
	    mailboxEB_CHAN_TSM_TX_IDN_SIGID,
		MB_CHAN_WR_MODE,
		mailboxEB_QCMI_PRIORITY,
		MB_DEFAULT_CHAN_OFFSET,
	    MB_DEFAULT_CHAN_OFFSET,
	    mailboxEB_CHAN_TSM_TX_IDN_NUMITEM,
	    mailboxEB_CHAN_TSM_TX_IDN_ITEMSIZE
	}
	 /* delimiter - handle using max sz macro */
};
/* sail mailbox driver dbg client message cntr */
mailboxEB_DATA static uint32 ulMailbox_DbgCnt[EB_CHAN_MAX] = { 0U };
/* sail mailbox driver enabled client record */
mailboxEB_CONST const xMailboxEBClientRec_t xMailboxClientRec[MAILBOX_EBMAX] =
{
	/* client MAILBOX_HLOSPMU  */
	{
		/* rd chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_PMU_RX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_PMU_RX_IDN],
		MAILBOX_HLOSPMU,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_PMU_RX_IDN],
		/* wr chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_PMU_TX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_PMU_TX_IDN],
		MAILBOX_HLOSPMU,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_PMU_TX_IDN]
	},
	/* client MAILBOX_HLOSUSS  */
	{
		/* rd chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_ULS_RX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_ULS_RX_IDN],
		MAILBOX_HLOSUSS,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_ULS_RX_IDN],
		/* wr chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_ULS_TX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_ULS_TX_IDN],
		MAILBOX_HLOSUSS,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_ULS_TX_IDN]
	},
	/* client MAILBOX_HLOSTST  */
	{
		/* rd chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_TST_RX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_TST_RX_IDN],
		MAILBOX_HLOSTST,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_TST_RX_IDN],
		/* wr chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_TST_TX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_TST_TX_IDN],
		MAILBOX_HLOSTST,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_TST_TX_IDN]

	},
	/* client MAILBOX_CONSOLE : rx channel not availble init with def param */
	{
		/* rd chan : NA deafult init */
		(mailboxEBIDNType_e)0xFF,
		(mailboxEBChanType_e)0xFF,
		0,
		NULL,
		(xMailboxExtclienttype)0xFF,
		NULL,
		/* wr chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_CONSOLE_TX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_CONSOLE_TX_IDN],
		MAILBOX_CONSOLE,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_CONSOLE_TX_IDN]
	},
	/* client MAILBOX_OTA  */
	{
		/* rd chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_OTA_RX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_OTA_RX_IDN],
		MAILBOX_OTA,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_OTA_RX_IDN],
		/* wr chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_OTA_TX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_OTA_TX_IDN],
		MAILBOX_OTA,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_OTA_TX_IDN]
	},
	/* client MAILBOX_TMU  */
	{
		/* rd chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_TMU_RX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_TMU_RX_IDN],
		MAILBOX_TMU,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_TMU_RX_IDN],
		/* wr chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_TMU_TX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_TMU_TX_IDN],
		MAILBOX_TMU,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_TMU_TX_IDN]
	},
	/* client MAILBOX_PTP  */
	{
		/* rd chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_PTP_RX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_PTP_RX_IDN],
		MAILBOX_PTP,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_PTP_RX_IDN],
		/* wr chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_PTP_TX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_PTP_TX_IDN],
		MAILBOX_PTP,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_PTP_TX_IDN]
	},
	/* client MAILBOX_CAN  */
	{
		/* rd chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_CAN_RX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_CAN_RX_IDN],
		MAILBOX_CAN,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_CAN_RX_IDN],
		/* wr chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_CAN_TX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_CAN_TX_IDN],
		MAILBOX_CAN,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_CAN_TX_IDN]
	},
	/* client MAILBOX_POWER : rx channel not availble init with def param */
	{
		/* rd chan : NA deafult init */
		0xFF,
		0xFF,
		0,
		NULL,
		0xFF,
		NULL,
		/* wr chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_POWER_TX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_POWER_TX_IDN],
		MAILBOX_POWER,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_POWER_TX_IDN]
	},
	/* client MAILBOX_FUSE*/
	{
		/* rd chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_FUSE_RX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_FUSE_RX_IDN],
		MAILBOX_FUSE,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_FUSE_RX_IDN],
		/* wr chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_FUSE_TX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_FUSE_TX_IDN],
		MAILBOX_FUSE,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_FUSE_TX_IDN]
	},
	/* client MAILBOX_STZ*/
	{
		/* rd chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_STZ_RX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_STZ_RX_IDN],
		MAILBOX_STZ,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_STZ_RX_IDN],
		/* wr chan */
		MAILBOX_QCMI_IDN,
		EB_CHAN_STZ_TX_IDN,
		mailboxEB_QCMI_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_STZ_TX_IDN],
		MAILBOX_STZ,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_STZ_TX_IDN]
	},
	/* client MAILBOX_HLOSSM : support for HWIO only */
	{
		/* rd chan */
		MAILBOX_SSM_IDN,
		EB_CHAN_SSM_RX_IDN,
		mailboxEB_SSM_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_SSM_RX_IDN],
		MAILBOX_SSM,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_SSM_RX_IDN],
		/* wr chan */
		MAILBOX_SSM_IDN,
		EB_CHAN_SSM_TX_IDN,
		mailboxEB_SSM_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_SSM_TX_IDN],
		MAILBOX_SSM,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_SSM_TX_IDN]
	},
	/* client MAILBOX_TZSM : support for HWIO only */
	{
		/* rd chan */
		MAILBOX_TSM_IDN,
		EB_CHAN_TSM_RX_IDN,
		mailboxEB_TSM_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_TSM_RX_IDN],
		MAILBOX_TSM,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_TSM_RX_IDN],
		/* wr chan */
		MAILBOX_TSM_IDN,
		EB_CHAN_TSM_TX_IDN,
		mailboxEB_TSM_ADDR,
		&ulMailbox_DbgCnt[EB_CHAN_TSM_TX_IDN],
		MAILBOX_TSM,
		&Mailbox_QCMISubRegionCfg[EB_CHAN_TSM_TX_IDN]
	}
	/* delimit using client max */
};

/*==============================================================================
 @Service name        MailBox_GetMbConfig
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
MAILBOX_EXT_FUNC const mbconfig_t *pxMailBoxEB_GetMbConfig (mailboxEBIDNType_e MBInstanceId)
{
	const mbconfig_t *pmbCfg = NULL;
	if(MAILBOX_QCMI_IDN == MBInstanceId)
	{
		pmbCfg = &MailboxExt_SAILConfig[MBInstanceId];
	}
    return pmbCfg;
}

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
==============================================================================*/
MAILBOX_EXT_FUNC const mbsub_rgn_config_t *pxMailBoxEB_GetSubRegConfig
(
	mailboxEBIDNType_e MBInstanceId
)
{
	const mbsub_rgn_config_t *pmbCfg = NULL;
	if((MAILBOX_QCMI_IDN == MBInstanceId))
	{
		pmbCfg = &Mailbox_QCMISubRegionCfg[MAILBOX_QCMI_IDN];
	}
    return pmbCfg;
}
/*==============================================================================
** 								EOF											  ** 
==============================================================================*/
