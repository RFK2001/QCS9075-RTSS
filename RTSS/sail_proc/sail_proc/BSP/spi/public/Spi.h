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
    File Name          : Spi.h
    Component Name     : AutoSAR SPI BSW Module
    Description        : All types mentioned in AUTOSAR_SWS_SPIHandlerDriver.pdf are added in this file
	                     AutoSAR 11/22
    $Header: //components/dev/autosar.sail/1.0/rsargar.autosar.sail.1.0.spicheckintest1/BSW/MCAL/Spi/inc/Spi.h#1 $
    $DateTime: 2024/02/23 04:27:20 $
    $Author: rsargar $
=========================================================================================================*/
#ifndef SPI_H
#define SPI_H
/*==============================================================================
**                      Include Section                                       **
==============================================================================*/
#include "types.h"
#include "Spi_Cfg.h"

#ifndef SAILEL2
#define SPI_FUNC  
#define SPI_RO 
#endif
typedef uint8 Std_ReturnType;
/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/
#include "types.h"
#include "Spi_Cfg.h"
#define SPI_DATA 
/*=========================================================================================================
**                                         Global Macro Definitions                                      **
=========================================================================================================*/
#define SPI_INSTANCE_ID                		((uint8)0U)
#define SPI_VENDOR_ID                  		0x00B8U
//#define SPI_MODULE_ID                  		((uint16)83U)

#define SPI_AR_RELEASE_MAJOR_VERSION        4u
#define SPI_AR_RELEASE_MINOR_VERSION        8u
#define SPI_AR_RELEASE_REVISION_VERSION     0u

#define SPI_SW_MAJOR_VERSION           		1U
#define SPI_SW_MINOR_VERSION           		0U
#define SPI_SW_PATCH_VERSION           		0U
#define SAILSS_QUPV3_1_SE0_BASE_ADDR 								0xF1900000u
#define SAILSS_QUPV3_1_SE1_BASE_ADDR 								0xF1904000u
#define SAILSS_QUPV3_1_SE2_BASE_ADDR 								0xF1908000u
#define SAILSS_QUPV3_1_SE3_BASE_ADDR 								0xF190c000u
#define SAILSS_QUPV3_1_SE4_BASE_ADDR 								0xF1910000u
#define SAILSS_QUPV3_1_SE5_BASE_ADDR 								0xF1914000u

//typedef uint8 Std_ReturnType;
/* ERROR IDs */
/* API service invoked with wrong Channel  */
#define SPI_E_PARAM_CHANNEL            ((uint8)0x0AU)
/* API service invoked with wrong Job      */
#define SPI_E_PARAM_JOB                ((uint8)0x0BU)
/* API service invoked with wrong Sequence */
#define SPI_E_PARAM_SEQ                ((uint8)0x0CU)
/* API service invoked with wrong Length   */
#define SPI_E_PARAM_LENGTH             ((uint8)0x0DU)
/* API service invoked with wrong Hw unit  */
#define SPI_E_PARAM_UNIT               ((uint8)0x0EU)
/* API service invoked with NULL pointer   */
#define SPI_E_PARAM_POINTER            ((uint8)0x10U)
/* For API service(except Init) invoked before initialization */
#define SPI_E_UNINIT                   ((uint8)0x1AU)
/* Requested Sequence for async transmit,
   is already in state SPI_SEQ_PENDING   */
#define SPI_E_SEQ_PENDING              ((uint8)0x2AU)
/* Spi_SyncTransmit is invoked while a sequence is on transmission */
#define SPI_E_SEQ_IN_PROCESS           ((uint8)0x3AU)
/* SPI_Init service invoked,
   while the SPI driver has already been initialized */
#define SPI_E_ALREADY_INITIALIZED      ((uint8)0x4AU)

/* Development Errors*/
#define SPI_E_DMA_TX_CHAN_STOP_FAIL		((uint8)0x5AU)
#define SPI_E_DMA_RX_CHAN_STOP_FAIL		((uint8)0x6AU)
#define SPI_E_DMA_TX_CHAN_RESET_FAIL	((uint8)0x7AU)
#define SPI_E_DMA_RX_CHAN_RESET_FAIL	((uint8)0x8AU)
#define SPI_E_DMA_TX_CHAN_DEALLOC_FAIL	((uint8)0x9AU)
#define SPI_E_DMA_RX_CHAN_DEALLOC_FAIL	((uint8)0xAAU)
/* Service ID */
/* Spi_Init */
#define SPI_SID_INIT                   ((uint8)0x00U)
/* Spi_DeInit */
#define SPI_SID_DEINIT                 ((uint8)0x01U)
/* Spi_AsyncTransmit */
#define SPI_SID_ASYNCTRANSMIT          ((uint8)0x03U)
/* Spi_SetupEB */
#define SPI_SID_SETUPEB                ((uint8)0x05U)
/* Spi_GetStatus */
#define SPI_SID_GETSTATUS              ((uint8)0x06U)
/* Spi_GetJobResult */
#define SPI_SID_GETJOBRESULT           ((uint8)0x07U)
/* Spi_GetSequenceResult */
#define SPI_SID_GETSEQUENCERESULT      ((uint8)0x08U)
/* Spi_GetVersionInfo */
#define SPI_SID_GETVERSIONINFO         ((uint8)0x09U)
/* Spi_SyncTransmit */
#define SPI_SID_SYNCTRANSMIT           ((uint8)0x0AU)
/* Spi_GetHWUnitStatus */
#define SPI_SID_GETHWUNITSTATUS        ((uint8)0x0BU)
/* Spi_Cancel */
#define SPI_SID_CANCEL                 ((uint8)0x0CU)
/* Spi_SetAsyncMode */
#define SPI_SID_SETASYNCMODE           ((uint8)0x0DU)
/* Spi_MainFunction_Handling */
#define SPI_SID_MAINFUNCTION_HANDLING  ((uint8)0x10U)

/* Base address specific to HW*/
#define CSIB0_BASE_ADDR 	SAILSS_QUPV3_1_SE0_BASE_ADDR
#define CSIB1_BASE_ADDR 	SAILSS_QUPV3_1_SE1_BASE_ADDR
#define CSIB2_BASE_ADDR 	SAILSS_QUPV3_1_SE2_BASE_ADDR
#define CSIB3_BASE_ADDR 	SAILSS_QUPV3_1_SE3_BASE_ADDR
#define CSIB4_BASE_ADDR 	SAILSS_QUPV3_1_SE4_BASE_ADDR
#define CSIB5_BASE_ADDR 	SAILSS_QUPV3_1_SE5_BASE_ADDR

#define SPI_MSB  (0U)
#define SPI_LSB  (1U)

#define SPI_EB  (0U)
#define SPI_IB  (1U)

#define SPI_HW_ERROR_DEM_REPORT 0U
#define SPI_DEM_REPORT_ENABLED 1U

#define SPI_NUM_RINGS_PER_GPII         2U
#define E_NOT_OK 0x01u
#define NULL_PTR            ((void *)0)
#define E_OK 0x00u

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/* IRQ Type */
typedef enum
{
   GPI_IRQ_CH_CTRL          = 1,
   GPI_IRQ_EV_CTRL          = 2,
   GPI_IRQ_GLOB_EE          = 4,
   GPI_IRQ_IEOB             = 8,
   GPI_IRQ_GENERAL          = 64,

   GPI_IRQ_OTHER            = 0xfff
}GPI_IRQ_TYPE;
/* Type : Spi_StatusType */
typedef enum
{
  SPI_UNINIT,
  SPI_IDLE,
  SPI_BUSY
} Spi_StatusType;

/* Type : Spi_JobResultType */
typedef enum
{
  SPI_JOB_OK,
  SPI_JOB_PENDING,
  SPI_JOB_FAILED,
  SPI_JOB_QUEUED
} Spi_JobResultType;

/* Type : Spi_SeqResultType */
typedef enum
{
  SPI_SEQ_OK,
  SPI_SEQ_PENDING,
  SPI_SEQ_FAILED,
  SPI_SEQ_CANCELED
} Spi_SeqResultType;

/*Non-standard : need to check the requirement*/
typedef enum
{
  SPI_LOOPBACK_DISABLE = 0U,     /* Disables the Loopback mode   */
  SPI_LOOPBACK_ENABLE = 1U       /* Enables the Loopback mode   */
} Spi_LoopBackType;

/* Type : Spi_SeqQueueType */
typedef struct
{
	 signed char scStartIndex;
	 signed char scEndIndex;
	 uint8 ucSequenceId[SPI_MAX_SEQ_QUEUE_LENGTH];
} Spi_SeqQueueType;

typedef struct
{
    uint8 ucStart;
    uint8 ucDirection;
    uint8 ucLength;
    uint8 ucStop;
} Spi_DataPackingType;

/* Type : Spi_DataBufferType */
typedef uint8 Spi_DataBufferType;
/* Type : Spi_NumberOfDataType */
typedef uint16 Spi_NumberOfDataType;
/* Type : Spi_ChannelType:Channel ID)*/
typedef uint8 Spi_ChannelType;
/* Type : Spi_JobType Job ID*/
typedef uint16 Spi_JobType;
/* Type : Spi_SequenceType Sequence ID */
typedef uint8 Spi_SequenceType;
/* Type: Spi_HWUnitType Specifies the identification (ID) for a SPI HW (unit) */
typedef uint8 Spi_HWUnitType;

#if (SPI_LEVEL_DELIVERED != 0U)
typedef enum
{
  SPI_POLLING_MODE,
  SPI_INTERRUPT_MODE
} Spi_AsyncModeType;
#endif

/* Type : Spi_LevelType */
typedef enum
{
	LOW = 0,
	HIGH
} Spi_LevelType;

/* Type Spi_CsBehaviorType */
typedef enum
{
	CS_KEEP_ASSERTED = 0,
	CS_TOGGLE
} Spi_CsBehaviorType;

/* Type : Spi_LevelType */
typedef enum
{
	TRAILING = 0,
	LEADING = 1,
} Spi_DataEdgeType;

/* Type : Spi_HwUnitType */
typedef enum
{
	CSIB0 = 0,
	CSIB1,
	CSIB2,
	CSIB3,
	CSIB4,
	CSIB5
} Spi_HwUnitType;

/* Type: Spi_JobEndNotification
   To provide Job Notification the following type will be used */
typedef void(*Spi_JobEndNotification)(void);

/* Type: Spi_SeqEndNotification
   To provide Sequence Notification the following type will be used */
typedef void(*Spi_SeqEndNotification)(void);

typedef struct
{
  /* Pointer to constant source buffer */
  const Spi_DataBufferType * SrcPtr;

  /* Pointer to destination buffer */
  Spi_DataBufferType * DestPtr;

  /* Number of data elements to be transferred */
  Spi_NumberOfDataType TransferLength;

  Spi_NumberOfDataType TransferredLen;
  Spi_NumberOfDataType ReceivedLen;

} Spi_BufferType;

typedef struct
{
	/* SPI Handler status */
	Spi_StatusType SpiSyncStatus;
	Spi_JobResultType *JobStatus;
	Spi_SeqResultType	*SeqStatus;
	Spi_StatusType *SpiBusStatus;
	/* Buffer pointer table */
	Spi_BufferType *ChannelBufPtrs;
} Spi_RunTimeStatusType;

typedef enum
{
    SPI_FIFO_POLLING_MODE = 0,
    SPI_FIFO_MODE,
    SPI_DMA_MODE
}Spi_OperationModeType;

/* Type: Spi_HwUnitConfigType */
typedef struct
{
	Spi_HwUnitType 	SpiHwUnit;
	/* Base address of the hardware*/
	uint32 	SpiSEBaseAddr;
	uint32  SpiHwClkFrequency;
	 /* sync -0 async - 1 */
	uint32 	SpiHardwareType;
	uint32 	SpiIntrptNum;
	uint8 ucGpiIndex;
    uint32     ulSlave;
	const char   *psSE_clock;
	Spi_OperationModeType SpiOpMode;
} Spi_HwUnitConfigType;

/* Type: Spi_ChannelConfigType */
typedef struct
{
	/* channel */
	Spi_ChannelType SpiChannelId;
	/* EB or IB type : 0 or 1 */
	uint8 SpiChannelType;
	/* transmitted data unit */
	uint8 SpiDataWidth;
	/* deafult data incase of null pointer by Appl */
	uint8 SpiDefaultData;
	/* maximum size: no. of EB buffer element only */
	uint16 SpiEbMaxLength;
	/* maximum data buffer: case of IB Channels only */
	uint16 SpiIbNBuffers;
	/* first starting bit for transmission LSB or MSB : 0 or 1 */
	uint8 SpiTransferStart;
} Spi_ChannelConfigType;

/* Type: Spi_JobConfigType */
typedef struct
{
	Spi_JobType SpiJobId;

	/* Link to the channels assigned in the Job*/
	const Spi_ChannelType *SpiChannelAssignment;

	Spi_ChannelType SpiChannelsPerJob;

	#if((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
	Spi_JobEndNotification SpiJobEndNotification;
	#endif
	uint8 SpiJobPriority;

	/* Symbolic name to identify the HW SPI Hardware
	 CSIB0/1/2/3/4/5*/
	Spi_HwUnitType SpiHwUnit;

	/* Index pointing to HwUnitCfg structure*/
	uint8 SpiHWUnitIndex;

	/* Communication Baudrate */
	uint32 SpiBaudrate;

	/* Symbolic name to identify the CS used for this job*/
	uint32 SpiCsIdentifier;

	/* This parameter defines the active polarity of Chip Select.
	STD_HIGH or STD_LOW */
	Spi_LevelType SpiCsPolarity;

	/* Handling of CS*/
	uint32 SpiCsSelection;

	/* This parameter defines the SPI data shift edge.*/
	Spi_DataEdgeType SpiDataShiftEdge;

	/* This parameter enables or not the Chip Select handling functions.*/
	uint8 SpiEnableCs;

	/* This parameter defines the SPI shift clock idle level*/
	Spi_LevelType SpiShiftClockIdleLevel;

	/* Timing between chip select and clk. FW will delay clock toggling
	 *  from CS toggling by this counter value. */
	float SpiTimeCs2Clk;

	/* Delay between the words */
	float SpiInterWordDelay;

	/*Toggle the CS line between words */
	Spi_CsBehaviorType SpiCsBehavior;

	/*Enable internal loopback between miso and mosi
	0- Loopback is disabled
	1-  Loopback is enabled */
	uint8 SpiInternalLoopBack;

	/* post command delay - if a delay from actual command
	completion until SW notification on command completion is needed.*/
	uint8 SpiPostCmdDelay;
} Spi_JobConfigType;

typedef struct
{
	Spi_SequenceType SpiSequenceId;
	#if((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
	Spi_SeqEndNotification SpiSeqEndNotification;
	#endif

	const Spi_JobType *SpiJobAssignment;
	/* Symbolic name to identify the HW SPI Hardware
	 CSIB0/1/2/3/4/5*/
	Spi_HwUnitType SpiHwUnit;
	/* Sync or Async*/
	const uint32 SpiSeqType;

	#if((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
	const Spi_SequenceType *SpiSharedSeqAssignment;
	#endif

	Spi_JobType SpiJobsPerSeq;

} Spi_SequenceConfigType;

typedef struct
{
	/* Pointer to the SPI Sequence configuration */
	const Spi_SequenceConfigType *SequenceCfgPtr;

	/* Pointer to the SPI Job configuration */
	const Spi_JobConfigType *JobCfgPtr;

	/* Pointer to the SPI Channel configuration */
	const Spi_ChannelConfigType *ChannelCfgPtr;

	/* Pointer to the SPI HW configuration */
	const Spi_HwUnitConfigType *HwUnitCfgptr;

	/*Pointer to sequence table*/
	const Spi_SequenceType *SequenceTbl;

	/*Pointer to Job table*/
	const Spi_JobType	* JobTbl;

	/*Pointer to Channel table*/
	const Spi_ChannelType	* ChannelTbl;

	/*Pointer to HW table*/
	const Spi_HwUnitType	* HwUnitTbl;

	/* Timeout for Synchronous transfer */
	uint32 SyncTimeout;
}Spi_ConfigType;

extern void SpiSequence_3_Test_Notification( void );
extern void SpiSequence_4_Test_Notification( void );
extern void Spi_Init(const Spi_ConfigType* ConfigPtr);

extern Std_ReturnType Spi_SetupEB(
								const Spi_ChannelType Channel,
								const Spi_DataBufferType*  SrcDataBufferPtr,
								Spi_DataBufferType*  DesDataBufferPtr,
								Spi_NumberOfDataType Length);

extern Std_ReturnType Spi_SyncTransmit (Spi_SequenceType Sequence);

extern Std_ReturnType Spi_AsyncTransmit (Spi_SequenceType Sequence);
extern Std_ReturnType Spi_DeInit(void);

extern Spi_StatusType Spi_GetStatus(void);

extern Spi_JobResultType Spi_GetJobResult (const Spi_JobType Job);

extern Spi_SeqResultType Spi_GetSequenceResult ( Spi_SequenceType Sequence);

#include "Spi_PBcfg.h"


#endif /* SPI_H */
/* End Of File */
