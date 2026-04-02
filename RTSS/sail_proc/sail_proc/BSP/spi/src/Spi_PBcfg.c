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
    File Name          : Spi_PBcfg.c
    Component Name     : AutoSAR SPI BSW Module
    Description        : Spi_PBCfg.c file generated for AUTOSAR_SWS_SPIHandlerDriver.pdf implementation
	                     AutoSAR R22-11
    $Header: $
    $DateTime: $
    $Author: $
=========================================================================================================*/

/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/
#include "Spi.h"

/*=========================================================================================================
**                          Golbal typedefs : Enums, Structures Union and other typedefs                **
==========================================================================================================*/
/*List of Sequence IDs*/
SPI_RO static const Spi_SequenceType Spi_SequenceTbl[] =
{
 	0U,
 	1U,
 	2U,
	3U,
	4U,
	SPI_SEQUENCE_DELIMITER
};

/*List of Job IDs*/
static const Spi_JobType Spi_JobTbl[] =
{
	0U,
	1U,
	2U,
	3U,
	4U,
	SPI_JOB_DELIMITER
};
 
/*List of HWs*/
SPI_RO static const Spi_HwUnitType Spi_HwUnitTbl[] =
{
	CSIB4,
};

/*List of channels*/
SPI_RO static const Spi_ChannelType Spi_ChannelTbl[] =
{
	0U,
	1U,
	2U,
	3U,
	4U,
	5U,
	SPI_CHANNEL_DELIMITER 		
};

/*List of Jobs in each Sequence*/
SPI_RO static const Spi_JobType SpiSequence_0_JobList[] =
{
	0,
    SPI_JOB_DELIMITER
};
SPI_RO static const Spi_JobType SpiSequence_1_JobList[] =
{
	1,
    SPI_JOB_DELIMITER
};
SPI_RO static const Spi_JobType SpiSequence_2_JobList[] =
{
	2,
    SPI_JOB_DELIMITER
};

SPI_RO static const Spi_JobType SpiSequence_3_JobList[] =
{
	3,
	4,
    SPI_JOB_DELIMITER
};

SPI_RO static const Spi_JobType SpiSequence_4_JobList[] =
{
	1,
    SPI_JOB_DELIMITER
};

/*List of Channels in each Job*/
SPI_RO static const Spi_ChannelType SpiJob_0_ChannelList[] =
{
	0,
	SPI_CHANNEL_DELIMITER
};
SPI_RO static const Spi_ChannelType SpiJob_1_ChannelList[] =
{
	1,
	SPI_CHANNEL_DELIMITER
};
SPI_RO static const Spi_ChannelType SpiJob_2_ChannelList[] =
{
	2,
	SPI_CHANNEL_DELIMITER
};
SPI_RO static const Spi_ChannelType SpiJob_3_ChannelList[] =
{
	3,
	SPI_CHANNEL_DELIMITER
};
SPI_RO static const Spi_ChannelType SpiJob_4_ChannelList[] =
{
	4,
	SPI_CHANNEL_DELIMITER
};


/*Sequence share list with other sequence*/
SPI_RO static const Spi_SequenceType SpiSequence_0_SeqShareList[] =
{ 
SPI_SEQUENCE_DELIMITER
};
SPI_RO static const Spi_SequenceType SpiSequence_1_SeqShareList[] =
{ 
SPI_SEQUENCE_DELIMITER
};
SPI_RO static const Spi_SequenceType SpiSequence_2_SeqShareList[] =
{ 
SPI_SEQUENCE_DELIMITER
};
SPI_RO static const Spi_SequenceType SpiSequence_3_SeqShareList[] =
{ 
SPI_SEQUENCE_DELIMITER
};
SPI_RO static const Spi_SequenceType SpiSequence_4_SeqShareList[] =
{
SPI_SEQUENCE_DELIMITER
};

/*Sequence config structure*/
SPI_RO static const Spi_SequenceConfigType Spi_SequenceConfig[] =
{
	{
		.SpiSequenceId 				= 0,
		.SpiSeqEndNotification 		= NULL_PTR,
		.SpiSharedSeqAssignment     = SpiSequence_0_SeqShareList,
		.SpiJobAssignment			= SpiSequence_0_JobList,
		.SpiJobsPerSeq				= 1,
		.SpiSeqType					= SYNCHRONOUS,
		.SpiHwUnit					= CSIB4,
	},
	{
		.SpiSequenceId 				= 1,
		.SpiSeqEndNotification 		= NULL_PTR,
		.SpiSharedSeqAssignment     = SpiSequence_1_SeqShareList,
		.SpiJobAssignment			= SpiSequence_1_JobList,
		.SpiJobsPerSeq				= 1,
		.SpiSeqType					= SYNCHRONOUS,
		.SpiHwUnit					= CSIB4,
	},
	{
		.SpiSequenceId 				= 2,
		.SpiSeqEndNotification 		= NULL_PTR,
		.SpiSharedSeqAssignment     = SpiSequence_2_SeqShareList,
		.SpiJobAssignment			= SpiSequence_2_JobList,
		.SpiJobsPerSeq				= 1,
		.SpiSeqType					= SYNCHRONOUS,
		.SpiHwUnit					= CSIB4,
	},
	{
		.SpiSequenceId 				= 3,
		.SpiSeqEndNotification 		= SpiSequence_3_Test_Notification,//SpiSequence_3_Test_Notification,
		.SpiSharedSeqAssignment     = SpiSequence_3_SeqShareList,
		.SpiJobAssignment			= SpiSequence_3_JobList,
		.SpiJobsPerSeq				= 2,
		.SpiSeqType					= ASYNCHRONOUS,
		.SpiHwUnit					= CSIB4,
	},
	{
		.SpiSequenceId 				= 4,
		.SpiSeqEndNotification 		= SpiSequence_4_Test_Notification,//SpiSequence_4_Test_Notification,
		.SpiSharedSeqAssignment     = SpiSequence_4_SeqShareList,
		.SpiJobAssignment			= SpiSequence_4_JobList,
		.SpiJobsPerSeq				= 1,
		.SpiSeqType					= ASYNCHRONOUS,
		.SpiHwUnit					= CSIB4,
	},
};

/*Job config structure*/ 
SPI_RO static const Spi_JobConfigType Spi_JobConfig[] =
 {
	{
		.SpiJobId 				= 0,
		.SpiChannelAssignment   = SpiJob_0_ChannelList,
		.SpiChannelsPerJob      = 1,
		.SpiInternalLoopBack 	= TRUE,
		.SpiJobEndNotification  = NULL_PTR,
		.SpiJobPriority 		= 0,
		.SpiHwUnit  			= CSIB4,
		.SpiBaudrate            = 1.0E7,
		.SpiCsIdentifier 		= 0,
		.SpiCsPolarity 			= LOW,
		.SpiCsSelection         = CS_VIA_PERIPHERAL_ENGINE,
		.SpiDataShiftEdge 		= LEADING,
		.SpiEnableCs 			= TRUE,
		.SpiShiftClockIdleLevel = LOW,
		.SpiCsBehavior 			= CS_KEEP_ASSERTED,
		.SpiTimeCs2Clk 			= 1.0E-7,
		.SpiInterWordDelay 		= 1.0E-5,
		.SpiPostCmdDelay 		= 0,
	},
 	{
 		.SpiJobId 				= 1,
		.SpiChannelAssignment   = SpiJob_1_ChannelList,
 		.SpiChannelsPerJob      = 1,
 		.SpiInternalLoopBack 	= FALSE,
		.SpiJobEndNotification  = NULL_PTR,
 		.SpiJobPriority 		= 1,
    	.SpiHwUnit  			= CSIB4,
    	.SpiBaudrate            = 4000000.0,
 		.SpiCsIdentifier 		= 0,
 		.SpiCsPolarity 			= LOW,
    	.SpiCsSelection         = CS_VIA_PERIPHERAL_ENGINE,
 		.SpiDataShiftEdge 		= TRAILING,
 		.SpiEnableCs 			= TRUE,
 		.SpiShiftClockIdleLevel = LOW,
 		.SpiCsBehavior 			= CS_KEEP_ASSERTED,
 		.SpiTimeCs2Clk 			= 0.01,
 		.SpiInterWordDelay 		= 1.0E-4,
  		.SpiPostCmdDelay 		= 0,
 	},
 	{
 		.SpiJobId 				= 2,
		.SpiChannelAssignment   = SpiJob_2_ChannelList,
 		.SpiChannelsPerJob      = 1,
 		.SpiInternalLoopBack 	= FALSE,
		.SpiJobEndNotification  = NULL_PTR,
 		.SpiJobPriority 		= 2,
    	.SpiHwUnit  			= CSIB4,
    	.SpiBaudrate            = 4000000.0,
 		.SpiCsIdentifier 		= 1,
 		.SpiCsPolarity 			= LOW,
    	.SpiCsSelection         = CS_VIA_PERIPHERAL_ENGINE,
 		.SpiDataShiftEdge 		= TRAILING,
 		.SpiEnableCs 			= TRUE,
 		.SpiShiftClockIdleLevel = LOW,
 		.SpiCsBehavior 			= CS_KEEP_ASSERTED,
 		.SpiTimeCs2Clk 			= 0.01,
 		.SpiInterWordDelay 		= 1.0E-4,
  		.SpiPostCmdDelay 		= 0,
 	},
	{
 		.SpiJobId 				= 3,
		.SpiChannelAssignment   = SpiJob_3_ChannelList,
 		.SpiChannelsPerJob      = 1,
 		.SpiInternalLoopBack 	= TRUE,
		.SpiJobEndNotification  = NULL_PTR,
 		.SpiJobPriority 		= 0,
    	.SpiHwUnit  			= CSIB4,
    	.SpiBaudrate            = 1.0E7,
 		.SpiCsIdentifier 		= 0,
 		.SpiCsPolarity 			= LOW,
    	.SpiCsSelection         = CS_VIA_PERIPHERAL_ENGINE,
 		.SpiDataShiftEdge 		= LEADING,
 		.SpiEnableCs 			= TRUE,
 		.SpiShiftClockIdleLevel = LOW,
 		.SpiCsBehavior 			= CS_KEEP_ASSERTED,
 		.SpiTimeCs2Clk 			= 1.0E-7,
 		.SpiInterWordDelay 		= 1.0E-5,
  		.SpiPostCmdDelay 		= 0,
 	},
	{
 		.SpiJobId 				= 4,
		.SpiChannelAssignment   = SpiJob_4_ChannelList,
 		.SpiChannelsPerJob      = 1,
 		.SpiInternalLoopBack 	= TRUE,
		.SpiJobEndNotification  = NULL_PTR,
 		.SpiJobPriority 		= 0,
    	.SpiHwUnit  			= CSIB4,
    	.SpiBaudrate            = 1.0E7,
 		.SpiCsIdentifier 		= 0,
 		.SpiCsPolarity 			= LOW,
    	.SpiCsSelection         = CS_VIA_PERIPHERAL_ENGINE,
 		.SpiDataShiftEdge 		= LEADING,
 		.SpiEnableCs 			= TRUE,
 		.SpiShiftClockIdleLevel = LOW,
 		.SpiCsBehavior 			= CS_KEEP_ASSERTED,
 		.SpiTimeCs2Clk 			= 0.01,
 		.SpiInterWordDelay 		= 1.0E-4,
  		.SpiPostCmdDelay 		= 0,
 	},
 };
 
 /*Channel config structure*/ 
SPI_RO static const Spi_ChannelConfigType Spi_ChannelConfig[] =
 {
 	{
 		.SpiChannelId			= 0,
 		.SpiChannelType 		= SPI_EB,
 		.SpiDataWidth 			= 8,
 		.SpiDefaultData 		= 0,
		.SpiEbMaxLength 		= 255,
 		.SpiTransferStart 		= SPI_MSB,
 	},
 	{
 		.SpiChannelId			= 1,
 		.SpiChannelType 		= SPI_EB,
 		.SpiDataWidth 			= 8,
 		.SpiDefaultData 		= 0,
		.SpiEbMaxLength 		= 255,
 		.SpiTransferStart 		= SPI_MSB,
 	},
 	{
 		.SpiChannelId			= 2,
 		.SpiChannelType 		= SPI_EB,
 		.SpiDataWidth 			= 8,
 		.SpiDefaultData 		= 0,
		.SpiEbMaxLength 		= 255,
 		.SpiTransferStart 		= SPI_MSB,
 	},
{
 		.SpiChannelId			= 3,
 		.SpiChannelType 		= SPI_EB,
 		.SpiDataWidth 			= 8,
 		.SpiDefaultData 		= 0,
		.SpiEbMaxLength 		= 255,
 		.SpiTransferStart 		= SPI_MSB,
 	},
 	{
 		.SpiChannelId			= 4,
 		.SpiChannelType 		= SPI_EB,
 		.SpiDataWidth 			= 8,
 		.SpiDefaultData 		= 0,
		.SpiEbMaxLength 		= 255,
 		.SpiTransferStart 		= SPI_MSB,
 	},
 	{
 		.SpiChannelId			= 5,
 		.SpiChannelType 		= SPI_EB,
 		.SpiDataWidth 			= 8,
 		.SpiDefaultData 		= 0,
		.SpiEbMaxLength 		= 255,
 		.SpiTransferStart 		= SPI_MSB,
 	},
 };
 
/*HW config structure*/ 
 SPI_RO static const Spi_HwUnitConfigType Spi_HwUnitConfig[] =
{
	{
		.SpiHwUnit = CSIB4,
    	.SpiSEBaseAddr = CSIB4_BASE_ADDR,		  	
 		.SpiHwClkFrequency = 100000000,
 		.SpiHardwareType = SYNCHRONOUS,
		.SpiIntrptNum = 406U,
 		.ucGpiIndex = 0U,
		.psSE_clock = "sailss_cc_qupv3_wrap0_s4_clk",
 	},
};

/* Spi Config structure*/
SPI_RO const Spi_ConfigType Spi_Config =
{
	.SequenceCfgPtr 	= Spi_SequenceConfig,
	.JobCfgPtr 			= Spi_JobConfig,
	.ChannelCfgPtr 		= Spi_ChannelConfig,
	.HwUnitCfgptr 		= Spi_HwUnitConfig,
	.SequenceTbl		= Spi_SequenceTbl,
	.JobTbl				= Spi_JobTbl,
	.ChannelTbl			= Spi_ChannelTbl,
	.HwUnitTbl			= Spi_HwUnitTbl,
	.SyncTimeout		= 300
};

/**********************************************************************************************************
**                                  End of file Spi_PBcfg.c                                             **
**********************************************************************************************************/

