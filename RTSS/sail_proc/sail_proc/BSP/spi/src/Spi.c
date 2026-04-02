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
    File Name          : Spi.c
    Component Name     : AutoSAR SPI BSW Module
    Description        : Implementation of AUTOSAR_SWS_SPIHandlerDriver.pdf.
	                     AutoSAR 11/22
    $Header:  $
    $DateTime: 2024/02/23 04:27:20 $
    $Author: $
=========================================================================================================*/

/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/
#include "Spi.h"
//#include "sail_qupv3_hwio.h"
#include "qup_common_hwio.h"
#include "hw_io.h"
#include "Clock.h" /*Needs to Be uncommented once EL1 clocks are enabled and SPI_Init is moved to EL1*/
#include "busywait.h"
//#include "module_init.h"
#include "gpio.h"
#include <libfdt.h>
#include "fdt_utils.h"
#include "debug_log.h"
#include "freertos_init.h"
#include "logcode.h"
#include "msmhwiobase.h"
#include "sleepEl1.h"
#include "interrupts.h"

/*==============================================================================
**                      PRIVATE macros and global variables                   **
==============================================================================*/
/* Semaphore to synchronize with SPI start and end of transfer */


/* spiPackingType;
* Packing data information
*/
typedef struct
{
   uint8 ucStart;
   uint8 ucDirection;
   uint8 ucLength;
   uint8 ucStop;
} spiPackingType;

#define POLL_TIME_DEFAULT_US            1000U
#define POLL_INTERVAL_US                5U
SPI_DATA static uint32 ulQupCommonBase;

SPI_DATA static Spi_JobResultType Spi_JobStatusTbl[SPI_MAX_JOB];

SPI_DATA static Spi_SeqResultType Spi_SeqStatusTbl[SPI_MAX_SEQUENCE];

SPI_DATA static const Spi_ConfigType* GlobalConfigPtr;

SPI_DATA  static Spi_BufferType Spi_BufferTblPtr[SPI_MAX_CHANNEL];

SPI_DATA static Spi_StatusType Spi_HwUnitStatus[SPI_MAX_HW_UNIT];

SPI_DATA volatile Spi_RunTimeStatusType Spi_RunTimeStatus =
{
	.SpiSyncStatus = SPI_UNINIT,
	.SpiBusStatus = Spi_HwUnitStatus,
	.JobStatus = Spi_JobStatusTbl,
	.SeqStatus = Spi_SeqStatusTbl,
	.ChannelBufPtrs = Spi_BufferTblPtr,
};

typedef struct
{
	uint16 LastJobIndex;
	Spi_SequenceType SpiSeqIndex;
	uint16 usCurrentJobIdx;
	Spi_ChannelType ChannelIdx;
} SpiAsyncTransferCntxt;

/* CS Asssertion to CLK ON delay. */
#define spiGENI_M_CMD0_SPI_PARAM_PRE_CMD_DLY      0x00000000U
/* Keep CS asserted at the end of the sequence. */
#define spiGENI_M_CMD0_SPI_PARAM_FRAGMENTATION    0x00000004U
#define spiIRQ_CLEAR_MASK         0xFFFFFFFFU
#define spiBITS_PER_BYTE          8U
#define spiBYTES_PER_FIFO_REG     4U
#define SPI_BITS_PER_WORD_8 	  		0x8U
#define SPI_BITS_PER_WORD_16 	  		16U
#define SPI_BITS_PER_WORD_32 	  		32U

#define spiFIFO_RX_WATERMARK	  13U
#define spiFIFO_TX_WATERMARK_IRQ_EN			0x40000000U
#define spiFIFO_TX_WATERMARK_IRQ_DISABLE	0xBFFFFFFFU

static StaticSemaphore_t xSPICBSemaphoreBuffer;
SPI_DATA SemaphoreHandle_t xSPICBSemaphoreHandle = NULL;
#define spiXFERHNDLRTASK_STACK_SIZE                   ( 2048 )
static StaticTask_t xSPIXferHandlerTaskTCB = { 0 };
static StackType_t xSPIXFERHNDLRTaskStack[ spiXFERHNDLRTASK_STACK_SIZE ] \
			__attribute__( ( aligned( MEM_ALIGNMENT_64 ) ) ) = { 0 };
#define spiSEQ_Q_LEN           	( 10U )
#define spiQ_ITEM_SIZE        ( sizeof( unsigned char ) )
#define spiQ_BUFFER_SIZE      ( spiSEQ_Q_LEN * spiQ_ITEM_SIZE )
SPI_DATA uint8_t xSPISEQXFERQBuffer[ spiQ_BUFFER_SIZE] __attribute__( ( aligned( MEM_ALIGNMENT_4 ) ) ) = { 0 };

SPI_DATA TaskHandle_t xSPIXferHandlerTaskHandle = NULL;

SPI_DATA QueueHandle_t xSPISEQXFERQHandle = NULL;
StaticQueue_t xSPIQueueBuffer;

extern uint32_t Image$$lnkSPIDATAStartAddr$$ZI$$Base;
extern uint32_t Image$$lnkSPIDATAEndAddr$$ZI$$Base;

SPI_DATA uint32 ulSPISleepHandle = 0U;

#define SAILBSP_SPI_DATA_ADDR_BASE        (void *)&Image$$lnkSPIDATAStartAddr$$ZI$$Base
#define SAILBSP_SPI_DATA_ADDR_SIZE        (uint32_t)( (uint32_t)&Image$$lnkSPIDATAEndAddr$$ZI$$Base -\
                                                            (uint32_t)&Image$$lnkSPIDATAStartAddr$$ZI$$Base )

#define SAILBSP_QUPV3_REG_ADDR_BASE    (void *)SAILSS_QUPV3_1_QUPV3_ID_1_BASE
#define SAILBSP_QupV3_REG_ADDR_SIZE            SAILSS_QUPV3_1_QUPV3_ID_1_BASE_SIZE

SPI_DATA static volatile SpiAsyncTransferCntxt xASyncTrnCntxt[SPI_MAX_HW_UNIT];

static Std_ReturnType Spi_prvCheckHandlerInitStatus( uint8 ucApiId );
static Std_ReturnType  Spi_prvGetJobIndex(
					const Spi_JobType JobId,
					Spi_JobType *JobIndex
			);
static Std_ReturnType Spi_prvCheckInitParam(const Spi_ConfigType* ConfigPtr);
static Std_ReturnType Spi_prvCheckSeqParam(uint32 ulApiId,
			const Spi_SequenceType SequenceId,
			uint8 *SequenceIdx
		);
#if (SPI_DEBUG_MODE == 0x1U)
static void Spi_prvReportError( const uint8 ucApiId,
								const uint8 ucErrorId);
#endif

static Std_ReturnType  Spi_prvGetChannelIndex(
				const Spi_ChannelType ChannelId,
				uint8 *ChannelIndex
			);
static Std_ReturnType Spi_prvGetHwUnitIndex(
					Spi_HwUnitType HwUnit,
					uint8 *HwIndex
				);

static Std_ReturnType Spi_prvDisableGpioSettings(void);
static void Spi_prvClockDisable( const char *clk_name);
static Std_ReturnType Spi_prvSyncStartSequence(
			const Spi_SequenceType SeqIndex);

static Std_ReturnType Spi_prvEnableGpioSettings(void);

static ClockResult Spi_prvClockEnable( const char *clk_name, uint32 clk_value );

static Std_ReturnType Spi_prvSerialEngineInit(
						const Spi_HwUnitConfigType *SpiHwConfigPtr);
static void Spi_prvReadFromFifo( 
						uint32 ulSEBaseAddr,
						Spi_ChannelType ChannelIndex);
static void Spi_prvWriteToFifo( 
						uint32 ulSEBaseAddr,
						Spi_ChannelType ChannelIndex);
static void Spi_prvSerialEngineDeInit( const Spi_HwUnitConfigType *SpiHwConfigPtr);

static Std_ReturnType Spi_prvCheckDriverBusy( void );

static Std_ReturnType Spi_prvCheckJobSharingStatus(const Spi_SequenceType eSeqIndex);
static Std_ReturnType Spi_prvConfigureIntrpt( uint8 ucHwMap, const Spi_HwUnitConfigType *SpiHwConfigPtr);

static SPI_FUNC void vSPIDeInit_Sleep( const sleepModeType_e eState );
/*==============================================================================
**                      Global Function Definitions 			              **
==============================================================================*/


/*******************************************************************************
* Service Name:    : Spi_Init
* Syntax           : void Spi_Init(const Spi_ConfigType* ConfigPtr)
* Service Id(Hex)  : 0x00
* Sync/Async       : Synchronous
* Reentrancy       : Non Reentrant
* Parameters(IN)   : ConfigPtr: Pointer to configuration set
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : None
* Description      : Service for SPI initialization
********************************************************************************/
SPI_FUNC void Spi_Init(const Spi_ConfigType* ConfigPtr)
{
	Std_ReturnType RetVal 	= E_NOT_OK;
	uint8 ucHwMap = 0;
	uint32_t log_data = DEFAULT_BOOT_STATUS;
	/* Check the init parameter and handler status*/
	ConfigPtr = &Spi_Config;
	RetVal = Spi_prvCheckInitParam(ConfigPtr);

	if( RetVal == (uint8)E_OK)
	{
		#if (SPI_DEBUG_MODE == 0x1U)
		{
			Spi_prvReportError(SPI_SID_INIT, SPI_E_ALREADY_INITIALIZED);
		}
		#endif
	}
	else
	{
		RetVal = Spi_prvEnableGpioSettings();
		if(RetVal == (uint8)E_OK)
		{
			for(ucHwMap = 0; ucHwMap < (uint8)SPI_MAX_HW_UNIT; ucHwMap++)
			{
				Spi_prvClockEnable(ConfigPtr->HwUnitCfgptr[ucHwMap].psSE_clock, ConfigPtr->HwUnitCfgptr[ucHwMap].SpiHwClkFrequency); /*Needs to Be Uncommented once EL1 clocks are enabled and SPI_Init is moved to EL1*/
				Spi_prvSerialEngineInit( &ConfigPtr->HwUnitCfgptr[ucHwMap]);

#if(SPI_LEVEL_DELIVERED != 0U)
				if( ConfigPtr->HwUnitCfgptr[ucHwMap].SpiHardwareType == ASYNCHRONOUS){
					Spi_RunTimeStatus.SpiBusStatus[ucHwMap] = SPI_IDLE;
				}
#endif
			}
			/*Initialize the job status */
			for(uint8 i = 0; i< SPI_MAX_JOB;i++)
			{
				Spi_RunTimeStatus.JobStatus[i] = SPI_JOB_OK;
			}

			/* Copy to global configuration pointer*/
			GlobalConfigPtr = ConfigPtr;

			/* Set the driver status to IDLE */
			#if((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))
			/* Set the driver status to IDLE */
			Spi_RunTimeStatus.SpiSyncStatus = SPI_IDLE;
			log_data = SPI;
			vLcWriteLogCode(SAIL_BOOT_MILESTONES, PASS, &log_data, 1);
			#endif


			if( ulSPISleepHandle == 0u )
			{
				if ( SLEEP_ERR_FLAG_SUCCESS != xSleepRegisterCallBackEl1(&vSPIDeInit_Sleep,&ulSPISleepHandle,get_curr_phys_cpu_num()))
				{
					DEBUG_LOG(SAIL_INFO,"vSPIDeInit_Sleep Sleep Reg Failed\n\r");
			    }			
			}
		}
	}
}


/*******************************************************************************
* Service Name:    : Spi_SetupEB
* Syntax           : Std_ReturnType Spi_SetupEB
						(
							const Spi_ChannelType Channel,
							const Spi_DataBufferType* SrcDataBufferPtr,
							Spi_DataBufferType* DesDataBufferPtr,
							Spi_NumberOfDataType Length
						)
* Service Id(Hex)  : 0x05
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : Channel - Channel ID.
* 					 SrcDataBufferPtr - Pointer to source data buffer.
* 					 DesDataBufferPtrPointer - to destination data buffer in RAM.
* 					 Length - Length (number of data elements) of the data to be transmitted
* 					 from SrcDataBufferPtr and/or received from DesDataBufferPtr
* 					 Min.: 1
* 					 Max.: Max of data specified at configuration for this channel
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : Std_ReturnType - E_OK: Setup command has been accepted
* 									  E_NOT_OK: Setup command has not been accepted
* Description      : Service to setup the buffers and the length of data for the
*					 EB SPI Handler/Driver Channel specified.
********************************************************************************/
SPI_FUNC Std_ReturnType Spi_SetupEB
(
    const Spi_ChannelType Channel,
    const Spi_DataBufferType* SrcDataBufferPtr,
    Spi_DataBufferType* DesDataBufferPtr,
    Spi_NumberOfDataType Length
)
{
	Std_ReturnType RetVal = E_OK;
	Spi_ChannelType ChannelIndex =  0x0U;
	Spi_NumberOfDataType MaxLength = 0U;
	const Spi_ChannelConfigType *Spi_ChannelConfigPtr = NULL_PTR;

	/* Check if Driver is initialized */
	RetVal = Spi_prvCheckHandlerInitStatus(SPI_SID_SETUPEB);

	if(RetVal == (uint8)E_OK)
	{
		/*Get channel configuration table index of channel ID*/
		if(Spi_prvGetChannelIndex(Channel, &ChannelIndex) == E_OK)
		{
			Spi_ChannelConfigPtr = &GlobalConfigPtr->ChannelCfgPtr[ChannelIndex];

			if(Spi_ChannelConfigPtr->SpiChannelType != (uint8)SPI_EB)
			{
				RetVal = E_NOT_OK;
			}
			else
			{
				MaxLength = Spi_ChannelConfigPtr->SpiEbMaxLength;
				if( ( Length > MaxLength ) || ( 0U >= Length ) )
				{
					RetVal = E_NOT_OK;
					#if (SPI_DEBUG_MODE == 0x1U)
					{
						Spi_prvReportError(SPI_SID_SETUPEB, SPI_E_PARAM_LENGTH);
					}
					#endif
				}
				else
				{
					Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].TransferLength  = Length;
					if( NULL_PTR != SrcDataBufferPtr )
					{
						Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].SrcPtr = SrcDataBufferPtr;
					}
					else
					{
						RetVal = E_NOT_OK;
					}

					if( NULL_PTR != DesDataBufferPtr )
					{
						Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].DestPtr = DesDataBufferPtr;
					}
					else
					{
						RetVal = E_NOT_OK;
					}

				}
			}
		}
		else
		{
			#if (SPI_DEBUG_MODE == 0x1U)
			{
				Spi_prvReportError(SPI_SID_SETUPEB, SPI_E_PARAM_CHANNEL);
			}
			#endif
		}
	}
	DEBUG_LOG(SAIL_WARNING, "%s : %d END \n\r", __func__, __LINE__);
	return RetVal;
}


/*******************************************************************************
* Service Name:    : Spi_SyncTransmit
* Syntax           : Std_ReturnType Spi_SyncTransmit (
				 	 	 	 Spi_SequenceType Sequence
							)
* Service Id(Hex)  : 0x0a
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : Sequence: Sequence ID
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : Std_ReturnType - E_OK: 	Transmission command has been accepted
*									  E_NOT_OK: Transmission command has not been accepted
* Description      : Service to transmit data on the SPI bus.
********************************************************************************/
SPI_FUNC Std_ReturnType Spi_SyncTransmit (
				 Spi_SequenceType Sequence
			)
{
	Std_ReturnType RetVal = E_NOT_OK;
	uint8 SeqIndex = SPI_SEQUENCE_DELIMITER;

	/* Check if Driver is initialized */
	RetVal = Spi_prvCheckHandlerInitStatus(SPI_SID_SYNCTRANSMIT);
	if(RetVal == (uint8)E_OK)
	{
		/* Checks if the application passed sequence Id is a valid
		sequence to be transmitted and also check the sequence type ? sync or async */
		RetVal = Spi_prvCheckSeqParam(SPI_SID_SYNCTRANSMIT, Sequence, &SeqIndex);

		if(RetVal == (uint8)E_OK)
		{
			/* Check whether the sequence is pending */
			if( Spi_RunTimeStatus.SpiSyncStatus == SPI_BUSY)
			{
				#if (SPI_DEBUG_MODE == 0x1U)
				{
					Spi_prvReportError(SPI_SID_SYNCTRANSMIT, SPI_E_SEQ_IN_PROCESS);
				}
				#endif
				RetVal = E_NOT_OK;
			}
			else
			{
				/* Update Handler status to SPI_BUSY before transmission*/
				Spi_RunTimeStatus.SpiSyncStatus = SPI_BUSY;
				Spi_RunTimeStatus.SeqStatus[SeqIndex] = SPI_SEQ_PENDING;
				/* Start Sequence transmission*/
				RetVal = Spi_prvSyncStartSequence( SeqIndex);

				/* Update Handler status to SPI_IDLE after transmission*/
				Spi_RunTimeStatus.SpiSyncStatus = SPI_IDLE;
			}
		}
	}

	return RetVal;
}

#if (SPI_LEVEL_DELIVERED != 0U)
/*******************************************************************************
* Service Name:    : Spi_AsyncTransmit
* Syntax           : Std_ReturnType Spi_AsyncTransmit (Spi_SequenceType Sequence)
* Service Id(Hex)  : 0x03
* Sync/Async       : Asynchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : Sequence: Sequence ID
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : Std_ReturnType - E_OK: 	Transmission command has been accepted
*									  E_NOT_OK: Transmission command has not been accepted
* Description      : Service to transmit data on the SPI bus.
********************************************************************************/
SPI_FUNC Std_ReturnType Spi_AsyncTransmit (Spi_SequenceType Sequence)
{
	Std_ReturnType RetVal = E_NOT_OK;
	uint8 SeqIndex = SPI_SEQUENCE_DELIMITER;
	const Spi_JobType *Spi_JobAssignmentTblPtr  = NULL_PTR;
	Spi_JobType JobsPerSeq 						= 0XFFU;
	volatile Spi_JobType JobId					= 0XFFU;
	uint16 JobIndex = SPI_JOB_DELIMITER;
	/* Check if Driver is initialized */
	RetVal = Spi_prvCheckHandlerInitStatus(SPI_SID_ASYNCTRANSMIT);

	if(RetVal == (uint8)E_OK)
	{
		/* Checks if the application passed sequence Id is a valid
		sequence to be transmitted and also check the sequence type ? sync or async */
		RetVal = Spi_prvCheckSeqParam(SPI_SID_ASYNCTRANSMIT, Sequence, &SeqIndex);

		if( RetVal == (uint8)E_OK)
		{
			if( Spi_RunTimeStatus.SeqStatus[SeqIndex] != SPI_SEQ_PENDING)
			{
				RetVal = Spi_prvCheckJobSharingStatus(SeqIndex);
				if( RetVal == (uint8)E_OK)
				{
					/*Insert Sequence in the pending list*/
					if( pdPASS != xFreeRTOSQueueSend ( xSPISEQXFERQHandle, (void*)&SeqIndex, 0))
					{
						RetVal = E_NOT_OK;
					}
					else
					{
						Spi_JobAssignmentTblPtr	= GlobalConfigPtr->SequenceCfgPtr[SeqIndex].SpiJobAssignment;
						JobsPerSeq			= GlobalConfigPtr->SequenceCfgPtr[SeqIndex].SpiJobsPerSeq;
						for( uint16 SpiJobLookUp = 0U; SpiJobLookUp < JobsPerSeq ; SpiJobLookUp++ )
						{
							/* Get Job Id */
							JobId = Spi_JobAssignmentTblPtr[SpiJobLookUp];

							RetVal = Spi_prvGetJobIndex(JobId, &JobIndex);
							if( RetVal == (uint8)E_OK)
							{
								/* Set jobs status to pending */
								Spi_RunTimeStatus.JobStatus[JobIndex] = SPI_JOB_QUEUED;
							}
						}

					}
				}
				else
				{
					RetVal = E_NOT_OK;
				}
			}
			else
			{
				RetVal = E_NOT_OK;
			}
		}
	}

	return RetVal;
}
#endif

/*******************************************************************************
* Service Name:    : Spi_GetStatus
* Syntax           : FUNC(Spi_StatusType, SPI_CODE_FAST) Spi_GetStatus(void)
* Service Id(Hex)  : 0x06
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : None
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : SPI_UNINIT: The SPI Handler/Driver is not initialized.
*                    SPI_IDLE : The SPI Handler/Driver is not currently
*                    transmitting any Job.
*                    SPI_BUSY: The SPI Handler/Driver is performing a SPI
*                    Job (transmit).
* Description      : Service returns the SPI Handler/Driver software module status.
********************************************************************************/
Spi_StatusType Spi_GetStatus(void)
{
	Std_ReturnType RetVal 	= E_NOT_OK;
	Spi_StatusType RetStatus =  SPI_UNINIT;

	/* Check if Driver is initialized */
	RetVal = Spi_prvCheckHandlerInitStatus(SPI_SID_GETSTATUS);

	if(RetVal == (uint8)E_OK)
	{
		RetVal = Spi_prvCheckDriverBusy();
		if( RetVal == E_NOT_OK)
		{
			RetStatus = SPI_BUSY;
		}
		else
		{
			RetStatus = SPI_IDLE;
		}
	}

	return RetStatus;
}

/*******************************************************************************
* Service Name:    : Spi_GetJobResult
* Syntax           : Spi_JobResultType Spi_GetJobResult (const Spi_JobType Job)
* Service Id(Hex)  : 0x07
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : Job - Job ID for which the status
*                    to be returned
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : Spi_JobResultType - status of the job
*                    returns SPI_JOB_FAILED for any errors
* Description      : This service returns the last transmission result of the specified Job.
********************************************************************************/
Spi_JobResultType Spi_GetJobResult (const Spi_JobType Job)
{
	Std_ReturnType RetVal 	= E_NOT_OK;
	Spi_JobResultType JobResult = SPI_JOB_FAILED;
	Spi_JobType JobIndex = 0x0;

	/* Check if Driver is initialized */
	RetVal = Spi_prvCheckHandlerInitStatus(SPI_SID_GETJOBRESULT);
	if(RetVal == (uint8)E_OK)
	{
		/* Get the index of the Job Id*/
		RetVal = Spi_prvGetJobIndex(Job, &JobIndex);
		if(RetVal == (uint8)E_OK)
		{
			/*Get the Job status*/
			JobResult = Spi_RunTimeStatus.JobStatus[JobIndex];
		}
		else
		{
			 DEBUG_LOG(SAIL_ERROR, "Invalid Job ID\r\n");
		}
	}

	return JobResult;
}

/*******************************************************************************
* Service Name:    : Spi_GetSequenceResult
* Syntax           : Spi_SeqResultType Spi_GetSequenceResult ( Spi_SequenceType Sequence)
* Service Id(Hex)  : 0x08
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : Sequence - Sequence Id for which the status
*                    to be returned
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : Spi_SeqResultType - status of the Sequence
*                    returns SPI_SEQ_FAILED for any errors
* Description      : This service returns the last transmission result of the specified Sequence.
********************************************************************************/
Spi_SeqResultType Spi_GetSequenceResult ( Spi_SequenceType Sequence)
{
	Std_ReturnType RetVal 	= E_NOT_OK;
	Spi_SeqResultType SeqResult = SPI_SEQ_FAILED;
	uint8 SeqIndex = 0;

	/* Check if Driver is initialized */
	RetVal = Spi_prvCheckHandlerInitStatus(SPI_SID_GETSEQUENCERESULT);
	if(RetVal == (uint8)E_OK)
	{
		/* Checks the validity of the sequence Id*/
		for(uint8 Index = 0; Index<SPI_MAX_SEQUENCE; Index++)
		{
			if(GlobalConfigPtr->SequenceTbl[Index] == Sequence)
			{
				SeqIndex = Index;
				RetVal = E_OK;
				break;
			}
		}
		if(RetVal == (uint8)E_OK)
		{
			/*Get the sequence status*/
			SeqResult = Spi_RunTimeStatus.SeqStatus[SeqIndex];
		}
		else
		{
			 DEBUG_LOG(SAIL_ERROR, "Invalid Sequence ID\r\n");
		}
	}

	return SeqResult;
}

/*******************************************************************************
* Service Name:    : Spi_DeInit
* Syntax           : Std_ReturnType Spi_DeInit(void)
* Service Id(Hex)  : 0x01
* Sync/Async       : Synchronous
* Reentrancy       : Non Reentrant
* Parameters(IN)   : None
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : Std_ReturnType - E_OK: de-initialisation command has been accepted
*									  E_NOT_OK: de-initialisation command has not been accepted
* Description      : Service for SPI de-initialization
********************************************************************************/
SPI_FUNC Std_ReturnType Spi_DeInit(void)
{
	Std_ReturnType RetVal 	= E_NOT_OK;
	uint8 ucHwMap = 0;

	/* Check if Driver is initialized */
	RetVal = Spi_prvCheckHandlerInitStatus(SPI_SID_DEINIT);

	if(RetVal == (uint8)E_OK)
	{

		RetVal = Spi_prvCheckDriverBusy();

		if( RetVal == (uint8)E_OK)
		{
			/*Reset all the hardwares*/
			for(ucHwMap = 0; ucHwMap < (uint8)SPI_MAX_HW_UNIT; ucHwMap++)
			{
				/* DeInitialize the GSI HW: TX channel, RX channel and event channel*/
				Spi_prvSerialEngineDeInit(&GlobalConfigPtr->HwUnitCfgptr[ucHwMap]);
				if( RetVal == (uint8)E_OK)
				{
					RetVal = Spi_prvDisableGpioSettings();
					if( RetVal == (uint8)E_OK)
					{
						Spi_prvClockDisable(GlobalConfigPtr->HwUnitCfgptr[ucHwMap].psSE_clock);
						/*Reset HW status to UnInit*/
						#if(SPI_LEVEL_DELIVERED != 0U)
						if( GlobalConfigPtr->HwUnitCfgptr[ucHwMap].SpiHardwareType == ASYNCHRONOUS)
						{
							Spi_RunTimeStatus.SpiBusStatus[ucHwMap] = SPI_UNINIT;
						}
						#endif
					}
				}
				else
				{
					break;
				}
			}
			for(uint16 chindex = 0; chindex < (uint16)SPI_MAX_CHANNEL; chindex++)
			{
				Spi_RunTimeStatus.ChannelBufPtrs[chindex].TransferredLen = 0x0U;
				Spi_RunTimeStatus.ChannelBufPtrs[chindex].ReceivedLen = 0x0U;
			}
			if( RetVal == (uint8)E_OK)
			{
				#if((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))
				/* Set the driver status to SPI_UNINIT */
				Spi_RunTimeStatus.SpiSyncStatus = SPI_UNINIT;
				#endif

				/* Reset the global pointer*/
				GlobalConfigPtr = NULL_PTR;
			}
		}
	}

	return RetVal;
}

/*========================================================================================================
 @Service name        vSPIDeInit_Sleep
 @Description         DeInit Call Back to register to sleep driver
 @param[in]           eState -> SLEEP_ENTRY = arg from sleep driver to Deinit SPI Driver
                                SLEEP_ABORT = arg from sleep driver in case sleep Driver want to abort sleep
 @param[out]          NA
 @param[in, out]      NA
 @return              void
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 =========================================================================================================*/

SPI_FUNC void vSPIDeInit_Sleep( const sleepModeType_e eState)
{
                DEBUG_LOG(SAIL_ERROR,"###### vSPIDeInit_Sleep\n\r");
    if( STR_SLEEP_MODE == eState )
    {
        if ( E_OK == Spi_DeInit() )
        {
            if (SLEEP_ERR_FLAG_SUCCESS == xSleepDriverAckEl1(ulSPISleepHandle,DRIVER_SLEEP,get_curr_phys_cpu_num()))
            {
                DEBUG_LOG(SAIL_INFO,"vSPIDeInit_Sleep xSleepDriverAck Success\n\r");
            }
        }
    }
}

/*******************************************************************************
**                      Local Function Definitions                           **
*******************************************************************************/
/*=================================================================================================
 @Service name        Spi_prvEnableGpioSettings
 @Description         Enable GPIOS of the serial engine
 @param[in]           Nil
 @param[out]          NA
 @param[in, out]      NA
 @return              Gpio enable status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
SPI_FUNC static Std_ReturnType Spi_prvEnableGpioSettings(void)
{
	int offset = 0, root_offset = 0;
	const char *path;
	char spi_name[5] = {'s', 'p', 'i','0','\0'};
	void *pDTB = NULL;
    uint32 val_array0[5] = {0}, val_array1[5] = {0}, val_array2[5] = {0},val_array3[5] = {0}, val_array4[5] = {0};
    int valSize = 5;
    GPIOConfigType xqupPinCfg = {0x0u};
    uint8 ucGpioNumbers = 0x0u;
    Std_ReturnType RetVal = E_OK;

	pDTB = fdt_get_dtb();
	if (NULL != pDTB)
	{
		root_offset = fdt_path_offset(pDTB, "/qup");
		(void)fdt_getprop_u32(pDTB, root_offset, "common-addr", &ulQupCommonBase);
		root_offset = fdt_path_offset(pDTB, "/aliases");
		for(int k = 0 ; k < 5; k++)
		{
			spi_name[3] = (k+48);
			path = (const char*)fdt_getprop(pDTB, root_offset, spi_name , NULL);
			if (path != NULL) {
				offset = fdt_path_offset(pDTB, path);
				#if defined(CHIPINFO_FAMILY_LEMANSAU)
                path = (char*)fdt_getprop(pDTB, offset, "pinctrl", NULL);
                #elif defined(CHIPINFO_FAMILY_MONACOAU)
                path = (char*)fdt_getprop(pDTB, offset, "pinctrl-monaco", NULL);
				#endif
                if( NULL != path)
                {
                    offset = fdt_path_offset(pDTB, path);
                    (void)fdt_getprop_u32_array(pDTB, offset, "pins", val_array0, &valSize);
                    (void)fdt_getprop_u32_array(pDTB, offset, "func", val_array1, &valSize);
                    (void)fdt_getprop_u32_array(pDTB, offset, "drive-strength", val_array2, &valSize);
                    (void)fdt_getprop_u32_array(pDTB, offset, "dir", val_array3, &valSize);
                    (void)fdt_getprop_u32_array(pDTB, offset, "bias", val_array4, &valSize);
                    for( int i = 0; i < valSize; i++)
                    {
                        ucGpioNumbers = (uint8)val_array0[i];
                        xqupPinCfg.func = val_array1[i];
                        xqupPinCfg.drive = val_array2[i];
                        xqupPinCfg.dir = val_array3[i];
                        xqupPinCfg.pull = val_array4[i];
                        sail_gpio_config_pin(ucGpioNumbers,xqupPinCfg);
                    }
                }
                else
                {
                	RetVal = E_NOT_OK;
                }
			}
		}
	}
	else
	{
		RetVal = E_NOT_OK;
	}

	return RetVal;
}

/*=================================================================================================
 @Service name        Spi_prvClockEnable
 @Description         This function configure and enable the clock for the serial engine
 @param[in]           clk_name, clk_value
 @param[out]          NA
 @param[in, out]      NA
 @return              Clock enable status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/

/*Needs to Be uncommented once EL1 clocks are enabled and SPI_Init is moved to EL1*/
SPI_FUNC static ClockResult Spi_prvClockEnable( const char *clk_name, uint32 clock_freq )
{
    ClockResult eResult = CLOCK_ERROR;
    ClockIdType nClockId = 0U;
    uint32_t ulNFreq;
    uint8 ucCount = 0U;
    ClockHandle hClient = 0U;
 
    (void)Clock_GetHandle(&hClient);
 
    eResult = Clock_GetClockId(hClient, clk_name,  (ClockIdType *)&nClockId);
 
    if ( eResult == CLOCK_SUCCESS )
    {
        eResult = Clock_SetClockFrequency(hClient, nClockId,
                                        clock_freq,
                                          CLOCK_FREQUENCY_HZ_AT_LEAST,&ulNFreq);
 
        eResult = Clock_EnableClock(hClient, nClockId);
 
    }
    return eResult;
    
}

/*=================================================================================================
 @Service name        Spi_prvDisableGpioSettings
 @Description         Disable GPIOS of the spi serial engine
 @param[in]           Nil
 @param[out]          NA
 @param[in, out]      NA
 @return              Gpio enable status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
SPI_FUNC static Std_ReturnType Spi_prvDisableGpioSettings(void)
{
	int offset = 0, root_offset = 0;
	const char *path;
	char spi_name[5] = {'s', 'p', 'i','0','\0'};
	void *pDTB = NULL;
    uint32 val_array0[5] = {0};
    int valSize = 5;
    GPIOConfigType xqupPinCfg = {0x0u};
    uint8 ucGpioNumbers = 0x0u;
    Std_ReturnType RetVal = E_OK;

	pDTB = fdt_get_dtb();
	if (NULL != pDTB)
	{
		root_offset = fdt_path_offset(pDTB, "/aliases");
		for(int k = 0 ; k < 5; k++)
		{
			spi_name[3] = (k+48);
			path = (const char*)fdt_getprop(pDTB, root_offset, spi_name , NULL);
			if (path != NULL) {
				offset = fdt_path_offset(pDTB, path);
				#if defined(CHIPINFO_FAMILY_LEMANSAU)
                path = (char*)fdt_getprop(pDTB, offset, "pinctrl", NULL);
                #elif defined(CHIPINFO_FAMILY_MONACOAU)
                path = (char*)fdt_getprop(pDTB, offset, "pinctrl-monaco", NULL);
                #endif
 
                if( NULL != path)
                {
                    offset = fdt_path_offset(pDTB, path);
                    (void)fdt_getprop_u32_array(pDTB, offset, "pins", val_array0, &valSize);
                    for( int i = 0; i < valSize; i++)
                    {
                        ucGpioNumbers = (uint8)val_array0[i];
                        xqupPinCfg.func = 0;
                        xqupPinCfg.drive = GPIO_2MA;
                        xqupPinCfg.dir = GPIO_IN;
                        xqupPinCfg.pull = GPIO_PD;
                        sail_gpio_config_pin(ucGpioNumbers,xqupPinCfg);
                    }
                }
                else
                {
                	RetVal = E_NOT_OK;
                }
			}
		}
	}
	else
	{
		RetVal = E_NOT_OK;
	}

	return RetVal;
}

/*=================================================================================================
 @Service name        Spi_prvClockDisable
 @Description         This function disables the clock for the serial engine
 @param[in]           clk_name      - clk name
 @param[out]          NA
 @param[in, out]      NA
 @return              void
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/

/*Needs to Be uncommented once EL1 clocks are enabled and SPI_Init is moved to EL1*/
SPI_FUNC static void Spi_prvClockDisable( const char *clk_name)
{
    ClockResult eResult = CLOCK_ERROR;
    ClockIdType nClockId = 0U;
    uint32_t ulNFreq;
    uint8 ucCount = 0U;
    ClockHandle hClient = 0U;

    (void)Clock_GetHandle(&hClient);
   	
    if ( CLOCK_SUCCESS == Clock_GetClockId( hClient, clk_name, &nClockId ) )
    {
     		eResult =  Clock_DisableClockEx( hClient, nClockId, 0);
     		if( CLOCK_SUCCESS != eResult)
     		{
     			DEBUG_LOG(SAIL_ERROR,"Failed to disable serial engine clock \r\n");
     		}
     	
     }
	 
}

/*=================================================================================================
 @Service name        Spi_prvConfigRegSequence
 @Description         This function does the geni config register sequence
 @param[in]           SpiHwConfigPtr - SE HW information
 @param[out]          NA
 @param[in, out]      NA
 @return              spiStatusType_e - Error status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          -
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
SPI_FUNC static void Spi_prvConfigRegSequence(  const Spi_HwUnitConfigType *SpiHwConfigPtr )
{
    uint32 ulSEBaseAddr = SpiHwConfigPtr->SpiSEBaseAddr;
    uint32 ulFifoDepth = 0U;

    /* First, ensure GENI FW is disabled */
    REG_OUT( ulSEBaseAddr, GENI_OUTPUT_CTRL,
            FLD_SET( GENI_OUTPUT_CTRL, IO_OUTPUT_CTRL, 0x0));
    REG_OUTF( ulSEBaseAddr, GENI_DFS_IF_CFG, DFS_IF_EN, 0);

	/* HW Controls the CGC. As per HPG section 3.1.7.3 */
    REG_OUTF(ulSEBaseAddr, QUPV3_COMMON_CGC_CTRL, COMMON_CSR_SLV_CLK_CGC_ON,1);

    // QUPv3 HPG. 3.1.7.3. SE CGC initialization
    REG_OUT( ulSEBaseAddr, DMA_GENERAL_CFG,
            FLD_SET(DMA_GENERAL_CFG, AHB_SEC_SLV_CLK_CGC_ON, 1) |
            FLD_SET(DMA_GENERAL_CFG, DMA_AHB_SLV_CLK_CGC_ON, 1) |
            FLD_SET(DMA_GENERAL_CFG, DMA_TX_CLK_CGC_ON, 1) |
            FLD_SET(DMA_GENERAL_CFG, DMA_RX_CLK_CGC_ON, 1));

    REG_OUT( ulSEBaseAddr, GENI_CGC_CTRL,
            FLD_SET( GENI_CGC_CTRL, EXT_CLK_CGC_ON, 1) |
            FLD_SET( GENI_CGC_CTRL, RX_CLK_CGC_ON, 1) |
            FLD_SET( GENI_CGC_CTRL, TX_CLK_CGC_ON, 1) |
            FLD_SET( GENI_CGC_CTRL, SCLK_CGC_ON, 1) |
            FLD_SET( GENI_CGC_CTRL, DATA_AHB_CLK_CGC_ON, 1) |
            FLD_SET( GENI_CGC_CTRL, CFG_AHB_WR_CLK_CGC_ON, 1) |
            FLD_SET( GENI_CGC_CTRL, CFG_AHB_CLK_CGC_ON, 1));

			/* HPG section 3.1.7.9 */
	ulFifoDepth = REG_INF( ulSEBaseAddr, SE_HW_PARAM_1, RX_FIFO_DEPTH);

	REG_OUT( ulSEBaseAddr, GENI_RX_RFR_WATERMARK_REG,
			FLD_SET( GENI_RX_RFR_WATERMARK_REG, RX_RFR_WATERMARK, ( ulFifoDepth - 2U)));

	REG_OUT( ulSEBaseAddr, GENI_OUTPUT_CTRL,
		FLD_SET( GENI_OUTPUT_CTRL, IO_OUTPUT_CTRL, 0x7f));

	REG_OUT( ulSEBaseAddr, GENI_DMA_MODE_EN, FLD_SET( GENI_DMA_MODE_EN, GENI_DMA_MODE_EN, 0));

	REG_OUT( ulSEBaseAddr, SE_GSI_EVENT_EN, 0);

	/* HPG section 3.1.7.12 */
	REG_OUT( ulSEBaseAddr, GENI_FORCE_DEFAULT_REG,
			FLD_SET( GENI_FORCE_DEFAULT_REG, FORCE_DEFAULT, 1 ));

	REG_OUTF( ulSEBaseAddr, GENI_CGC_CTRL,PROG_RAM_SCLK_OFF, 1);
	REG_OUTF( ulSEBaseAddr, GENI_CGC_CTRL,PROG_RAM_HCLK_OFF, 1);

	REG_OUT( ulSEBaseAddr, GENI_CLK_CTRL,
		FLD_SET( GENI_CLK_CTRL, SER_CLK_SEL, 0x1 ));

	REG_OUTF( ulSEBaseAddr, GENI_CGC_CTRL,PROG_RAM_SCLK_OFF,0 );
	REG_OUTF( ulSEBaseAddr, GENI_CGC_CTRL,PROG_RAM_HCLK_OFF,0 );

	/* HPG section 3.1.7.13 */
	REG_OUT( ulSEBaseAddr, DMA_IF_EN,
			FLD_SET(DMA_IF_EN, DMA_IF_EN, 0x0 ) );

	REG_OUT( ulSEBaseAddr, FIFO_IF_DISABLE,
			FLD_SET(FIFO_IF_DISABLE, FIFO_IF_DISABLE, 0x0 ) );
			
	REG_OUT( ulSEBaseAddr, GENI_CLK_SEL, FLD_SET( GENI_CLK_SEL, CLK_SEL, 0));
}

SPI_FUNC static void xSPIGeniSEIsr_CB(void *arg)
{
    uint32 ucHwUnitIndex = 0U;
    uint32  ulSEBaseAddr = 0U;
    uint32  ulIRQStatus = 0U;
	uint16 usLastJobIndex = 0U;
	uint8 ucSeqIndex = 0U;
	uint16 usCurrentJobIndex = 0;
	Spi_ChannelType ChannelIdx = 0x0;
    BaseType_t xStatus                  =  pdFALSE;
	BaseType_t xHigherPriorityTaskWoken=pdFALSE;

	ucHwUnitIndex = ( uint32 )arg;
    /* Identify the channel and process the interrupt */

	usCurrentJobIndex  = xASyncTrnCntxt[ucHwUnitIndex].usCurrentJobIdx;
	ucSeqIndex = xASyncTrnCntxt[ucHwUnitIndex].SpiSeqIndex;
	ChannelIdx = xASyncTrnCntxt[ucHwUnitIndex].ChannelIdx;
	usLastJobIndex = xASyncTrnCntxt[ucHwUnitIndex].LastJobIndex;
    /* Get the Serial engine base address*/
	ulSEBaseAddr = GlobalConfigPtr->HwUnitCfgptr[ucHwUnitIndex].SpiSEBaseAddr;

    /* Read the IRQ status register*/
    ulIRQStatus = REG_IN( ulSEBaseAddr, GENI_M_IRQ_STATUS);

      /* Check if the interrupt is due to RX_FIFO_LAST */
    if( (FLD_GET( ulIRQStatus, GENI_M_IRQ_STATUS, RX_FIFO_WATERMARK) != 0U)  ||
        		( FLD_GET( ulIRQStatus, GENI_M_IRQ_STATUS, RX_FIFO_LAST) != 0U))
    {
            /* Call the FIFO read function to read data from the RX FIFO or RX WATERMARK*/
      	Spi_prvReadFromFifo( ulSEBaseAddr, ( uint8)ChannelIdx);
    }
        /* Check if the interrupt is due to TX Watermark level*/
    if ( FLD_GET(ulIRQStatus, GENI_M_IRQ_STATUS, TX_FIFO_WATERMARK) != 0U)
    {
        /* Call the FIFO write function to write data to the FIFO*/
     	Spi_prvWriteToFifo(ulSEBaseAddr, ( uint8)ChannelIdx);
    }

    /* Check if the interrupt due to command done*/
    if (FLD_GET( ulIRQStatus, GENI_M_IRQ_STATUS, M_CMD_DONE) != 0U)
    {
			 /* Set the job status to "OK" - job successfully transmitted */
			Spi_RunTimeStatus.JobStatus[usCurrentJobIndex] = SPI_JOB_OK;
			if(usLastJobIndex == usCurrentJobIndex)
			{
				/* Update the HW status to IDLE after transmission*/
				Spi_RunTimeStatus.SpiBusStatus[ucHwUnitIndex] = SPI_IDLE;
				Spi_RunTimeStatus.SeqStatus[ucSeqIndex] = SPI_SEQ_OK;
				Spi_RunTimeStatus.JobStatus[usCurrentJobIndex] = SPI_JOB_OK;
				/* Call sequence end notification for the cancelled sequence also*/
				if( NULL_PTR !=  GlobalConfigPtr->SequenceCfgPtr[ucSeqIndex].SpiSeqEndNotification)
				{
					GlobalConfigPtr->SequenceCfgPtr[ucSeqIndex].SpiSeqEndNotification();
				}
			}
			else
			{
				/* Call Job end notification*/
				if( NULL_PTR != GlobalConfigPtr->JobCfgPtr[usCurrentJobIndex].SpiJobEndNotification )
				{
					GlobalConfigPtr->JobCfgPtr[usCurrentJobIndex].SpiJobEndNotification();
				}
				Spi_RunTimeStatus.JobStatus[usCurrentJobIndex] = SPI_JOB_OK;
			}
			xStatus = xSemaphoreGiveFromISR(xSPICBSemaphoreHandle,&xHigherPriorityTaskWoken );
                        if(xStatus == pdPASS)
                        {
                                freertosYIELD_FROM_ISR( );
                        }

    }

    if (( FLD_GET(ulIRQStatus, GENI_M_IRQ_STATUS, TX_FIFO_WR_ERR) != 0U) || ( FLD_GET(ulIRQStatus, GENI_M_IRQ_STATUS, TX_FIFO_RD_ERR) != 0U) ||
    		( FLD_GET(ulIRQStatus, GENI_M_IRQ_STATUS, RX_FIFO_WR_ERR) != 0U) || ( FLD_GET(ulIRQStatus, GENI_M_IRQ_STATUS, RX_FIFO_RD_ERR) != 0U) ||
			( FLD_GET(ulIRQStatus, GENI_M_IRQ_STATUS, M_CMD_OVERRUN) != 0U) || ( FLD_GET(ulIRQStatus, GENI_M_IRQ_STATUS, M_CMD_FAILURE) != 0U))
    {
		 /* Set the job status to "OK" - job successfully transmitted */
		Spi_RunTimeStatus.JobStatus[usCurrentJobIndex] = SPI_JOB_FAILED;
		Spi_RunTimeStatus.SeqStatus[ucSeqIndex] = SPI_SEQ_FAILED;
    	DEBUG_LOG(SAIL_ERROR,"Spi_Transfer failed: %x!\r\n",ulIRQStatus );
    }
    /* Clear all the GENI_M_IRQ*/
    if(ulIRQStatus != 0U)
    {
        REG_OUT( ulSEBaseAddr, GENI_M_IRQ_CLEAR, ulIRQStatus);
    }
}

SPI_FUNC static void xSPIGeniSEIsr(void *arg)
{


    xSPIGeniSEIsr_CB( arg );


}

/*================================================================================================
 @Service name        Spi_prvConfigureIntrpt
 @Description         This function does the interrupt configuration for Async mode
 @param[in]           SpiHwConfigPtr - SE HW information
 	 	 	 	 	  ucHwMap - HW Index
 @param[out]          NA
 @param[in, out]      NA
 @return              Std_ReturnType - API status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          -
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
SPI_FUNC static Std_ReturnType Spi_prvConfigureIntrpt( uint8 ucHwMap, const Spi_HwUnitConfigType *SpiHwConfigPtr)
{
    uint32 ulSEBaseAddr = SpiHwConfigPtr->SpiSEBaseAddr;
    uint32 ulRegMIRQ = 0;
    Std_ReturnType RetVal = E_OK;
    intEl1Status_t IntStatus = INT_EL1_SUCCESS;

    /* Configure the interrupt */
    IntStatus = xGicSetIntEnable(SpiHwConfigPtr->SpiIntrptNum, (boolean)FALSE);
    if(INT_EL1_SUCCESS != IntStatus)
    {
    	DEBUG_LOG(SAIL_ERROR,"[SPI drv] xGicSetIntEnable failed\r\n");
    	RetVal = E_NOT_OK;
    	return RetVal;
    }

    IntStatus = xGicRegisterIntHandler(SpiHwConfigPtr->SpiIntrptNum, (InterruptHandle_t)xSPIGeniSEIsr, (void *)(uint32)ucHwMap);
    if(INT_EL1_SUCCESS != IntStatus)
    {
    	DEBUG_LOG(SAIL_ERROR,"[SPI drv] xGicRegisterIntHandler failed\r\n");
    	RetVal = E_NOT_OK;
    	return RetVal;
    }

    IntStatus = xGicConfigureInt(SpiHwConfigPtr->SpiIntrptNum, (enum InterruptConfig_t)EL1_INT_CONFIG_EDGE_TRIGGER, NULL);
    if(INT_EL1_SUCCESS != IntStatus)
    {
    	DEBUG_LOG(SAIL_ERROR,"[SPI drv] xGicConfigureInt failed\r\n");
    	RetVal = E_NOT_OK;
    	return RetVal; 
    }

    IntStatus = xGicSetIntPriority(SpiHwConfigPtr->SpiIntrptNum, (uint32_t)0x0U);
    if(INT_EL1_SUCCESS != IntStatus)
    {
    	DEBUG_LOG(SAIL_ERROR,"[SPI drv] xGicSetIntPriority failed\r\n");
    	RetVal = E_NOT_OK;
    	return RetVal;
    }else
    {
    	/* Clear any pending Interrupt. This will ensure the fresh start*/
    	REG_OUT(ulSEBaseAddr, GENI_M_IRQ_CLEAR, spiIRQ_CLEAR_MASK);
    	REG_OUT(ulSEBaseAddr, GENI_S_IRQ_CLEAR, spiIRQ_CLEAR_MASK);
    	REG_OUT(ulSEBaseAddr, DMA_TX_IRQ_CLR, spiIRQ_CLEAR_MASK);
    	REG_OUT(ulSEBaseAddr, DMA_RX_IRQ_CLR, spiIRQ_CLEAR_MASK);
    }

    IntStatus = xGicSetIntEnable(SpiHwConfigPtr->SpiIntrptNum, (boolean)TRUE);
    if(INT_EL1_SUCCESS != IntStatus)
    {
    	DEBUG_LOG(SAIL_ERROR,"[SPI drv] xGicSetIntEnable failed\r\n");
    	RetVal = E_NOT_OK;
    	return RetVal;
    }

	REG_OUT(ulSEBaseAddr, SE_GSI_EVENT_EN,0);

	/* Frame the common M_IRQ enable*/
	ulRegMIRQ = (ulRegMIRQ  | FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_OVERRUN_EN, 1) |
	    FLD_SET(GENI_M_IRQ_ENABLE, M_ILLEGAL_CMD_EN, 1) |
	    FLD_SET(GENI_M_IRQ_ENABLE, RX_FIFO_LAST_EN, 1) |
	    FLD_SET(GENI_M_IRQ_ENABLE, M_TIMESTAMP_EN, 1) |
	    FLD_SET(GENI_M_IRQ_ENABLE, SEC_IRQ_EN, 1) |
	    FLD_SET(GENI_M_IRQ_ENABLE, IO_DATA_ASSERT_EN, 1) |
	    FLD_SET(GENI_M_IRQ_ENABLE, IO_DATA_DEASSERT_EN, 1) |
	    FLD_SET(GENI_M_IRQ_ENABLE, RX_FIFO_RD_ERR_EN, 1) |
	    FLD_SET(GENI_M_IRQ_ENABLE, RX_FIFO_WR_ERR_EN, 1) |
	    FLD_SET(GENI_M_IRQ_ENABLE, TX_FIFO_RD_ERR_EN, 1) |
	    FLD_SET(GENI_M_IRQ_ENABLE, TX_FIFO_WR_ERR_EN, 1));

	         // QUPv3 HPG. 3.1.7.7. Enable GENI interrupts. FIFO Mode.
    REG_OUT( ulSEBaseAddr, GENI_M_IRQ_ENABLE,
    	     ulRegMIRQ |
    	     REG_IN( ulSEBaseAddr, GENI_M_IRQ_ENABLE) |
				 FLD_SET(GENI_M_IRQ_ENABLE, RX_FIFO_WATERMARK_EN, 1) |
				 FLD_SET(GENI_M_IRQ_ENABLE, TX_FIFO_WATERMARK_EN, 1) |
				 FLD_SET(GENI_M_IRQ_ENABLE, RX_FIFO_LAST_EN, 1) |
				 FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_DONE_EN, 1) |
				 FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_FAILURE_EN, 1) |
				 FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_CANCEL_EN, 1) |
				 FLD_SET(GENI_M_IRQ_ENABLE, M_CMD_ABORT_EN, 1));

    return RetVal;
}

/*=================================================================================================
 @Service name        Spi_prvSerialEngineInit
 @Description         This function Initialize the Serial engine of the QUP Hw for the SPI Protocol
 @param[in]           SpiHwConfigPtr      - Pointer for the Hardware configuration
 @param[out]          NA
 @param[in, out]      NA
 @return              Initialization status
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
SPI_FUNC static Std_ReturnType Spi_prvSerialEngineInit( const Spi_HwUnitConfigType *SpiHwConfigPtr)
{
    uint32  ulCfgSeqDone = 0U;
    Std_ReturnType RetVal = E_OK;
    uint32 ulSEBaseAddr = SpiHwConfigPtr->SpiSEBaseAddr;

    Spi_prvConfigRegSequence( SpiHwConfigPtr );

        /*do the following initializations only for ulSlave controller*/
    if( SpiHwConfigPtr->ulSlave == TRUE)
    {
        REG_OUT( ulSEBaseAddr, SPI_SLAVE_EN,
            FLD_SET(SPI_SLAVE_EN, SPI_SLAVE_EN, 1));

        /* for straight connection, write 1 to output ctrl.
          for cross connection, write 2 to output ctrl */
        REG_OUT( ulSEBaseAddr, GENI_OUTPUT_CTRL,
            FLD_SET(GENI_OUTPUT_CTRL, IO_OUTPUT_CTRL, 0x1));

        REG_OUT( ulSEBaseAddr, GENI_CFG_SEQ_START,
            FLD_SET(GENI_CFG_SEQ_START, START_TRIGGER, 1));

        while( ulCfgSeqDone == 0U)
        {
            ulCfgSeqDone = REG_INF( ulSEBaseAddr, GENI_CFG_STATUS,CFG_SEQ_DONE);
        }
    }

    return RetVal;
}

/*******************************************************************************
* Service Name:    : Spi_prvCheckJobSharingStatus
* Syntax           : static Std_ReturnType Spi_prvCheckJobSharingStatus(const Spi_SequenceType eSeqIndex)
* Service Id(Hex)  :
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : None
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : Std_ReturnType - E_OK
*									  E_NOT_OK
* Description      : Service for checking Job sharing status
********************************************************************************/
SPI_FUNC static Std_ReturnType Spi_prvCheckJobSharingStatus(const Spi_SequenceType eSeqIndex)
{
	Std_ReturnType RetVal = E_OK;
	const Spi_SequenceType *Spi_SequenceShareTbl = GlobalConfigPtr->SequenceCfgPtr[eSeqIndex].SpiSharedSeqAssignment;
	Spi_SequenceType SharedSeqIndex = 0U;
	uint8 ucShareIndex = 0;

	SharedSeqIndex = Spi_SequenceShareTbl[ucShareIndex];
	while( SharedSeqIndex != SPI_SEQUENCE_DELIMITER)
	{
		if(Spi_RunTimeStatus.SeqStatus[SharedSeqIndex] == SPI_SEQ_PENDING)
		{
			RetVal = E_NOT_OK;
			break;
		}
		else
		{
			ucShareIndex++;
			SharedSeqIndex = Spi_SequenceShareTbl[ucShareIndex];
		}
	}

	return RetVal;
}

/*=================================================================================================
 @Service name        Spi_prvSerialEngineDeInit
 @Description         This function DeInitialize the Serial engine of the QUP Hw for the SPI Protocol
 @param[in]           SpiHwConfigPtr      - Pointer for the Hardware configuration
 @param[out]          NA
 @param[in, out]      NA
 @return              NA
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
SPI_FUNC static void Spi_prvSerialEngineDeInit( const Spi_HwUnitConfigType *SpiHwConfigPtr)
{
	intEl1Status_t IntStatus = INT_EL1_SUCCESS;
	uint32 ulSEBaseAddr = SpiHwConfigPtr->SpiSEBaseAddr;

    /* Disable the Interrupts*/
    REG_OUT(ulSEBaseAddr, SE_IRQ_EN,
                     FLD_SET(SE_IRQ_EN, DMA_RX_IRQ_EN, 0) |
                     FLD_SET(SE_IRQ_EN, DMA_TX_IRQ_EN, 0) |
                     FLD_SET(SE_IRQ_EN, GENI_M_IRQ_EN, 0) |
                     FLD_SET(SE_IRQ_EN, GENI_S_IRQ_EN, 0));

    if( SpiHwConfigPtr->SpiHardwareType == ASYNCHRONOUS)
    {
        /* De-register the interrupt */
        IntStatus = xGicSetIntEnable(SpiHwConfigPtr->SpiIntrptNum, (boolean)FALSE);
        if(INT_EL1_SUCCESS != IntStatus)
        {
        	DEBUG_LOG(SAIL_ERROR,"[SPI drv] xGicSetIntEnable(FALSE) failed\r\n");
        }
        IntStatus = xGicUnRegisterIntHandler(SpiHwConfigPtr->SpiIntrptNum, (uint32_t)0x0U);
        if(INT_EL1_SUCCESS != IntStatus)
        {
        	DEBUG_LOG(SAIL_ERROR,"[SPI drv] xGicUnRegisterIntHandler failed\r\n");
        }
    }

    /* Clear any pending Interrupt.*/
    REG_OUT(ulSEBaseAddr, GENI_M_IRQ_CLEAR, spiIRQ_CLEAR_MASK);
    REG_OUT(ulSEBaseAddr, GENI_S_IRQ_CLEAR, spiIRQ_CLEAR_MASK);
    REG_OUT( ulSEBaseAddr, GENI_M_IRQ_ENABLE,0x0U);
}

/*******************************************************************************
* Service Name:    : Spi_prvCheckDriverBusy
* Syntax           : static FUNC(Std_ReturnType, SPI_CODE_FAST) Spi_prvCheckDriverBusy
* 						( void )
*					 )
* Service Id(Hex)  : NA
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : Nil
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : Std_ReturnType - E_OK
*									  E_NOT_OK
* Description      : Service for checking any HW is busy or not
********************************************************************************/
SPI_FUNC static Std_ReturnType Spi_prvCheckDriverBusy( void )
{
	Std_ReturnType RetVal = E_OK;

	#if( SPI_LEVEL_DELIVERED != 1U)
	if( Spi_RunTimeStatus.SpiSyncStatus == SPI_BUSY)
	{
		RetVal = E_NOT_OK;
	}
	#endif

	#if( SPI_LEVEL_DELIVERED != 0U)
	for( uint8 ucHwindex = 0; ucHwindex < SPI_MAX_HW_UNIT; ucHwindex++)
	{
		if( Spi_RunTimeStatus.SpiBusStatus[ucHwindex] == SPI_BUSY)
		{
			RetVal = E_NOT_OK;
			break;
		}
	}
	#endif

	return RetVal;
}

/*******************************************************************************
* Service Name:    : Spi_prvCheckInitParam
* Syntax           : static FUNC(Std_ReturnType, SPI_CODE_FAST) Spi_prvCheckInitParam(
*											P2CONST(Spi_ConfigType, AUTOMATIC, SPI_APPL_DATA)ConfigPtr)
* Service Id(Hex)  : NA
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : ConfigPtr - config pointer
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : Std_ReturnType - E_OK
*									  E_NOT_OK
* Description      : Service for checking handler status
********************************************************************************/
SPI_FUNC static Std_ReturnType Spi_prvCheckInitParam(const Spi_ConfigType* ConfigPtr)
{
	Std_ReturnType RetVal = E_OK;

	/* Check the validity of configuration pointer*/
	if( ConfigPtr == NULL_PTR)
	{
		#if (SPI_DEBUG_MODE == 0x1U)
		{
			Spi_prvReportError(SPI_SID_INIT, SPI_E_PARAM_POINTER);
		}
		#endif
	}
	else
	{
		/* If Level-0 OR Level-2, check the sync status if not initialized */
		#if((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))
		if( Spi_RunTimeStatus.SpiSyncStatus == SPI_UNINIT)
		{
			RetVal = E_NOT_OK;
		}
		#endif

		#if((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
		for(uint8 ucHwMap = 0; ucHwMap < (uint8)SPI_MAX_HW_UNIT; ucHwMap++)
		{
			if( ConfigPtr->HwUnitCfgptr[ucHwMap].SpiHardwareType == ASYNCHRONOUS)
			{
				if( Spi_RunTimeStatus.SpiBusStatus[ucHwMap] == SPI_UNINIT)
				{
					 RetVal = E_NOT_OK;
					 break;
				}
			}
		}
		#endif
	}

	return RetVal;
}

/*******************************************************************************
* Service Name:    : Spi_prvCheckHandlerInitStatus
* Syntax           : static FUNC(Std_ReturnType, SPI_CODE_FAST) Spi_prvCheckHandlerInitStatus(
*											VAR(uint8,  AUTOMATIC) ucApiId)
* Service Id(Hex)  : NA
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : ucApiId - Api ID
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : Std_ReturnType - E_OK
*									  E_NOT_OK
* Description      : Service for checking handler status
********************************************************************************/
SPI_FUNC static Std_ReturnType Spi_prvCheckHandlerInitStatus( uint8 ucApiId )
{
	Std_ReturnType RetVal = E_OK;

    /* If Level-0 OR Level-2, check the sync status if not initialized */
    #if((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))
		if( Spi_RunTimeStatus.SpiSyncStatus == SPI_UNINIT)
		{
	        RetVal = E_NOT_OK;
		}
	#endif

	#if((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
	if( GlobalConfigPtr != NULL_PTR)
	{
		for(uint8 ucHwMap = 0; ucHwMap < (uint8)SPI_MAX_HW_UNIT; ucHwMap++)
		{
			if( GlobalConfigPtr->HwUnitCfgptr[ucHwMap].SpiHardwareType == ASYNCHRONOUS)
			{
				if( Spi_RunTimeStatus.SpiBusStatus[ucHwMap] == SPI_UNINIT)
				{
					 RetVal = E_NOT_OK;
					 break;
				}
			}
		}
	}
	else
	{
		 RetVal = E_NOT_OK;
	}
	#endif

	if(RetVal == (uint8)E_NOT_OK)
	{
		if( ucApiId != (uint8)SPI_SID_INIT)
		{
			#if (SPI_DEBUG_MODE == 0x1U)
			{
				Spi_prvReportError(ucApiId, SPI_E_UNINIT);
			}
			#endif
		}
	}

	return RetVal;
}


/*******************************************************************************
* Service Name:    : Spi_prvCheckSeqParam
* Syntax           : static FUNC(Std_ReturnType, SPI_CODE_FAST) Spi_prvCheckSeqParam(
*											VAR(uint32,  AUTOMATIC) ulApiType,
*											const VAR(Spi_SequenceType, AUTOMATIC) SequenceId,
*											P2VAR(uint8, AUTOMATIC, SPI_APPL_DATA) SequenceIdx)
* Service Id(Hex)  :
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : SequenceId - sequence id
* Parameters(INOUT): SequenceIdx - sequence index
* Parameters(OUT)  : None
* Return Value     : Std_ReturnType - E_OK
*									  E_NOT_OK
* Description      : Service for checking Sequence properties
********************************************************************************/
SPI_FUNC static Std_ReturnType Spi_prvCheckSeqParam(uint32 ulApiId,
			const Spi_SequenceType SequenceId,
			uint8 *SequenceIdx
		)
{
	Std_ReturnType RetVal = E_NOT_OK;
	uint32 ulApiType = 0U;
	uint8 MappedSeqIndex = SPI_SEQUENCE_DELIMITER;

	if( ulApiId == SPI_SID_ASYNCTRANSMIT)
	{
		ulApiType = 1;
	}

	for(uint8 Index = 0; Index<SPI_MAX_SEQUENCE; Index++)
	{
		if(GlobalConfigPtr->SequenceTbl[Index] == SequenceId)
		{
			MappedSeqIndex = Index;
			RetVal = E_OK;
			break;
		}
	}
	if( RetVal == (uint8)E_OK)
	{
		*SequenceIdx = MappedSeqIndex;

		if(ulApiId == SPI_SID_CANCEL)
		{
			RetVal = E_OK;
		}
		else
		{
			if( GlobalConfigPtr->SequenceCfgPtr[MappedSeqIndex].SpiSeqType == ulApiType)
			{
				RetVal = E_OK;
			}
			else
			{
				RetVal = E_NOT_OK;
			}
		}
	}

	if( RetVal == (uint8)E_NOT_OK)
	{
		#if (SPI_DEBUG_MODE == 0x1U)
		{
			Spi_prvReportError(ulApiId, SPI_E_PARAM_SEQ);
		}
		#endif
	}

	return RetVal;
}

/*******************************************************************************
* Service Name:    : Spi_prvGetJobIndex
* Syntax           : static FUNC(Std_ReturnType, SPI_CODE_FAST) Spi_prvGetJobIndex(
*											VAR(Spi_JobType, AUTOMATIC) JobId,
*											P2VAR(Spi_JobType, AUTOMATIC, SPI_APPL_DATA) JobIndex)
* Service Id(Hex)  :
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : JobId - Job Id
* Parameters(INOUT): JobIndex - Index corresponding to Job id
* Parameters(OUT)  : None
* Return Value     : Std_ReturnType - E_OK
*									  E_NOT_OK
* Description      :Service for getting the job index
********************************************************************************/
SPI_FUNC static Std_ReturnType  Spi_prvGetJobIndex(
					const Spi_JobType JobId,
					Spi_JobType *JobIndex
			)
{
	Std_ReturnType RetVal = E_NOT_OK;

	for(uint16 Index = 0; Index <SPI_MAX_JOB; Index++)
	{
		if(GlobalConfigPtr->JobTbl[Index] == JobId)
		{
			*JobIndex = Index;
			RetVal = E_OK;
			break;
		}
	}

	return RetVal;
}

/*******************************************************************************
* Service Name:    : Spi_prvGetChannelIndex
* Syntax           : static FUNC(Std_ReturnType, SPI_CODE_FAST) Spi_prvGetChannelIndex(
*											const VAR(Spi_ChannelType,  AUTOMATIC) ChannelId,
*											P2VAR(uint8, AUTOMATIC, SPI_APPL_DATA) ChannelIndex)
* Service Id(Hex)  :
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : ChannelId
* Parameters(INOUT): ChannelIndex - index of the channelid
* Parameters(OUT)  : None
* Return Value     : Std_ReturnType - E_OK
*									  E_NOT_OK
* Description      : Service for getting the channel index
********************************************************************************/
SPI_FUNC static Std_ReturnType  Spi_prvGetChannelIndex(
				const Spi_ChannelType ChannelId,
				uint8 *ChannelIndex
			)
{
	Std_ReturnType RetVal = E_NOT_OK;

	for(uint8 Index = 0; Index <SPI_MAX_CHANNEL; Index++)
	{
		if(GlobalConfigPtr->ChannelTbl[Index] == ChannelId)
		{
			*ChannelIndex = Index;
			RetVal = E_OK;
			break;
		}
	}

	return RetVal;
}

/*******************************************************************************
* Service Name:    : Spi_prvGetHwUnitIndex
* Syntax           : static FUNC(Std_ReturnType, SPI_CODE_FAST) Spi_prvGetHwUnitIndex(
*											VAR(Spi_HwUnitType, AUTOMATIC) HwUnit,
*											P2VAR(uint8, AUTOMATIC, SPI_APPL_DATA) HwIndex)
* Service Id(Hex)  :
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : HwUnit
* Parameters(INOUT): HwIndex - index of hardware unit id
* Parameters(OUT)  : None
* Return Value     : Std_ReturnType - E_OK
*									  E_NOT_OK
* Description      : Service for getting the hardware index
********************************************************************************/
SPI_FUNC static Std_ReturnType Spi_prvGetHwUnitIndex(
					Spi_HwUnitType HwUnit,
					uint8 *HwIndex
				)
{
	Std_ReturnType RetVal = E_NOT_OK;

	for(uint8 Index = 0; Index <SPI_MAX_HW_UNIT; Index++)
	{
		if(GlobalConfigPtr->HwUnitTbl[Index] == HwUnit)
		{
			*HwIndex = Index;
			RetVal = E_OK;
			break;
		}
	}

	return RetVal;
}
/*=================================================================================================
 @Service name        prvSPIPackingConfig
 @Description         This function does the GENI miscellaneous configurations
 @param[in]           ulSEBaseAddr
 	 	 	 	 	  ucBitsPerWord
 @param[out]          NA
 @param[in, out]      NA
 @return              void
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          -
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
SPI_FUNC static void prvSPIPackingConfig( uint32 ulSEBaseAddr, uint8 ucBitsPerWord)
{
	spiPackingType xPackingVec[4] = { 0};
	/*SPI Packing configuration for different Channel data width*/
	spiPackingType  xPackingVec_8bit[4] = { { 7, 1, 7, 0 },
			   	   	   	  	  	  	  	  { 15, 1, 7, 0 },
										  { 23, 1, 7, 0 },
										  { 31, 1, 7, 1 } };
	spiPackingType  xPackingVec_16bit[4] = { { 0xf, 1, 7, 0 },
			   	   	   	  	  	  	  	   { 7, 1, 7, 0 },
										  { 0x1f, 1, 7, 0 },
										  { 0x17, 1, 7, 1 } };
	spiPackingType  xPackingVec_32bit[4] = { { 0x1f, 1, 7, 0 },
			   	   	   	  	  	  	  	  { 0x17, 1, 7, 0 },
										  { 0xf, 1, 7, 0 },
										  { 0x7, 1, 7, 1 } };

    switch( ucBitsPerWord)
    {
    	case SPI_BITS_PER_WORD_8:
    	    /*packing vector for mode (4 * 8)
    	      fifo entry contains 4 words of 8 bits */
    		(void)memcpy(&xPackingVec, &xPackingVec_8bit, sizeof(xPackingVec));
    		break;
    	case SPI_BITS_PER_WORD_16:
    	    /*packing vector for mode (2 * 16)
    	      fifo entry contains 2 words of 16 bits */
    		(void)memcpy(&xPackingVec, &xPackingVec_16bit, sizeof(xPackingVec));
    		break;
    	case SPI_BITS_PER_WORD_32:
    	    /*packing vector for mode (1 * 32)
    	      fifo entry contains 1 word of 32 bits */
    		(void)memcpy(&xPackingVec, &xPackingVec_32bit, sizeof(xPackingVec));
    		break;
    	default:
    		(void)memcpy(&xPackingVec, &xPackingVec_8bit, sizeof(xPackingVec));
    		break;
    }

    REG_OUT( ulSEBaseAddr, GENI_TX_PACKING_CFG0,
        FLD_SET( GENI_TX_PACKING_CFG0, VEC_1_START_INDEX, xPackingVec[1].ucStart) |
        FLD_SET( GENI_TX_PACKING_CFG0, VEC_1_DIRECTION, xPackingVec[1].ucDirection) |
        FLD_SET( GENI_TX_PACKING_CFG0, VEC_1_LENGTH, xPackingVec[1].ucLength) |
        FLD_SET( GENI_TX_PACKING_CFG0, VEC_1_STOP, xPackingVec[1].ucStop) |
        FLD_SET( GENI_TX_PACKING_CFG0, VEC_0_START_INDEX, xPackingVec[0].ucStart) |
        FLD_SET( GENI_TX_PACKING_CFG0, VEC_0_DIRECTION, xPackingVec[0].ucDirection) |
        FLD_SET( GENI_TX_PACKING_CFG0, VEC_0_LENGTH, xPackingVec[0].ucLength) |
        FLD_SET( GENI_TX_PACKING_CFG0, VEC_0_STOP, xPackingVec[0].ucStop));

    REG_OUT( ulSEBaseAddr, GENI_TX_PACKING_CFG1,
        FLD_SET( GENI_TX_PACKING_CFG1, VEC_3_START_INDEX, xPackingVec[3].ucStart) |
        FLD_SET( GENI_TX_PACKING_CFG1, VEC_3_DIRECTION, xPackingVec[3].ucDirection) |
        FLD_SET( GENI_TX_PACKING_CFG1, VEC_3_LENGTH, xPackingVec[3].ucLength) |
        FLD_SET( GENI_TX_PACKING_CFG1, VEC_3_STOP, xPackingVec[3].ucStop) |
        FLD_SET( GENI_TX_PACKING_CFG1, VEC_2_START_INDEX, xPackingVec[2].ucStart) |
        FLD_SET( GENI_TX_PACKING_CFG1, VEC_2_DIRECTION, xPackingVec[2].ucDirection) |
        FLD_SET( GENI_TX_PACKING_CFG1, VEC_2_LENGTH, xPackingVec[2].ucLength) |
        FLD_SET( GENI_TX_PACKING_CFG1, VEC_2_STOP, xPackingVec[2].ucStop));

    REG_OUT( ulSEBaseAddr, GENI_RX_PACKING_CFG0,
        FLD_SET( GENI_RX_PACKING_CFG0, VEC_1_START_INDEX, xPackingVec[1].ucStart) |
        FLD_SET( GENI_RX_PACKING_CFG0, VEC_1_DIRECTION, xPackingVec[1].ucDirection) |
        FLD_SET( GENI_RX_PACKING_CFG0, VEC_1_LENGTH, xPackingVec[1].ucLength) |
        FLD_SET( GENI_RX_PACKING_CFG0, VEC_1_STOP, xPackingVec[1].ucStop) |
        FLD_SET( GENI_RX_PACKING_CFG0, VEC_0_START_INDEX, xPackingVec[0].ucStart) |
        FLD_SET( GENI_RX_PACKING_CFG0, VEC_0_DIRECTION, xPackingVec[0].ucDirection) |
        FLD_SET( GENI_RX_PACKING_CFG0, VEC_0_LENGTH, xPackingVec[0].ucLength) |
        FLD_SET( GENI_RX_PACKING_CFG0, VEC_0_STOP, xPackingVec[0].ucStop));

    REG_OUT( ulSEBaseAddr, GENI_RX_PACKING_CFG1,
        FLD_SET( GENI_RX_PACKING_CFG1, VEC_3_START_INDEX, xPackingVec[3].ucStart) |
        FLD_SET( GENI_RX_PACKING_CFG1, VEC_3_DIRECTION, xPackingVec[3].ucDirection) |
        FLD_SET( GENI_RX_PACKING_CFG1, VEC_3_LENGTH, xPackingVec[3].ucLength) |
        FLD_SET( GENI_RX_PACKING_CFG1, VEC_3_STOP, xPackingVec[3].ucStop) |
        FLD_SET( GENI_RX_PACKING_CFG1, VEC_2_START_INDEX, xPackingVec[2].ucStart) |
        FLD_SET( GENI_RX_PACKING_CFG1, VEC_2_DIRECTION, xPackingVec[2].ucDirection) |
        FLD_SET( GENI_RX_PACKING_CFG1, VEC_2_LENGTH, xPackingVec[2].ucLength) |
        FLD_SET( GENI_RX_PACKING_CFG1, VEC_2_STOP, xPackingVec[2].ucStop));
}

SPI_FUNC static Std_ReturnType Spi_prvSyncStartJob(
			const Spi_JobType JobIndex
		)
{
	Std_ReturnType RetVal = E_NOT_OK;
	const Spi_ChannelType * Spi_ChannelAssignmentTblPtr 	= NULL_PTR;
	Spi_ChannelType	ChannelId 		= 0XFFU;
	Spi_ChannelType ChannelIndex =  0x0U;
	Spi_ChannelType SpiChannelLookUp 	= 0;
	Spi_ChannelType	ChannelsPerJob	= 0XFFU;
	uint8 HwIndex = 0u;
	uint32 ulSEBaseAddr = 0x0;
    uint32 ulTXWatermark = 1U;
    uint32 ulRegTimeoutUS = POLL_TIME_DEFAULT_US;
    uint32  ulIRQStatus = 0U;
    uint8 ucClockDiv = 0x0;
    uint8  ucGranularity = 0U;
    uint32 ulParams = 0U;
    uint8 xOpcode = 3;// GENI_M_CMD0_SPI_OPCODE_FULL_DUPLEX
    const Spi_JobConfigType *SpiJobConfigPtr = &GlobalConfigPtr->JobCfgPtr[JobIndex];


	Spi_prvGetHwUnitIndex(SpiJobConfigPtr->SpiHwUnit, &HwIndex);
	Spi_RunTimeStatus.SpiBusStatus[HwIndex] = SPI_BUSY;
	ulSEBaseAddr = GlobalConfigPtr->HwUnitCfgptr[HwIndex].SpiSEBaseAddr;
			
    uint8 inter_word_delay_cycles = (uint8)(SpiJobConfigPtr->SpiInterWordDelay/SpiJobConfigPtr->SpiBaudrate);
    uint8 cs_clk_delay_cycles = (uint8)(SpiJobConfigPtr->SpiTimeCs2Clk/SpiJobConfigPtr->SpiBaudrate);

    REG_OUT( ulSEBaseAddr, SPI_LOOPBACK_CFG,
            FLD_SET(SPI_LOOPBACK_CFG, LOOPBACK_MODE,SpiJobConfigPtr->SpiInternalLoopBack));

    // QUPv3 HPG. 3.2.1. General Configuration
    ucClockDiv = 100000000/SpiJobConfigPtr->SpiBaudrate;
       /* spi config settings by setting dfs index and clock divider */
    REG_OUT( ulSEBaseAddr, GENI_SER_M_CLK_CFG,
        FLD_SET( GENI_SER_M_CLK_CFG, CLK_DIV_VALUE, ucClockDiv) |
        FLD_SET( GENI_SER_M_CLK_CFG, SER_CLK_EN, 1));

    REG_OUT( ulSEBaseAddr, SPI_CPHA, FLD_SET(SPI_CPHA, CPHA, SpiJobConfigPtr->SpiDataShiftEdge));
    REG_OUT( ulSEBaseAddr, SPI_CPOL, FLD_SET(SPI_CPOL, CPOL, SpiJobConfigPtr->SpiShiftClockIdleLevel));

	Spi_ChannelAssignmentTblPtr	= SpiJobConfigPtr->SpiChannelAssignment;
	ChannelsPerJob			= SpiJobConfigPtr->SpiChannelsPerJob;
	
		/* Get Channel to be transmitted */
	ChannelId = Spi_ChannelAssignmentTblPtr[SpiChannelLookUp];

	REG_OUT( ulSEBaseAddr, SPI_DEMUX_SEL,
	    FLD_SET(SPI_DEMUX_SEL, CS_DEMUX_SEL, SpiJobConfigPtr->SpiCsIdentifier));

	REG_OUT( ulSEBaseAddr, SPI_DEMUX_OUTPUT_INV,
	    FLD_SET( SPI_DEMUX_OUTPUT_INV, CS_DEMUX_OUTPUT_INV, SpiJobConfigPtr->SpiCsPolarity));

	REG_OUT( ulSEBaseAddr, SPI_TRANS_CFG,
			        FLD_SET(SPI_TRANS_CFG, SPI_CS_TOGGLE, SpiJobConfigPtr->SpiCsBehavior));

			    /* CS CLK & Inter word delay for channel */
	REG_OUT( ulSEBaseAddr, SPI_DELAYS_COUNTERS,
			        FLD_SET( SPI_DELAYS_COUNTERS, SPI_CS_CLK_DLY, cs_clk_delay_cycles) |
			        FLD_SET( SPI_DELAYS_COUNTERS, SPI_INTER_WORDS_DLY, inter_word_delay_cycles));

	if ( cs_clk_delay_cycles != 0U)
	{
		ulParams |= spiGENI_M_CMD0_SPI_PARAM_PRE_CMD_DLY;
	}


	/*Get channel configuration table index of channel ID*/
	if(Spi_prvGetChannelIndex(ChannelId, &ChannelIndex) == E_OK)
	{
		Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].TransferredLen = 0x0;
		Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].ReceivedLen = 0x0;
		const Spi_ChannelConfigType *ChannelCfgPtr = &GlobalConfigPtr->ChannelCfgPtr[ChannelIndex];
		if( ChannelCfgPtr->SpiDataWidth == 8U)
		{
			ucGranularity = 0U;
		}
		else
		{
			ucGranularity =  ChannelCfgPtr->SpiDataWidth >> 4U;
		}
			/* Channel data width configuration*/
		REG_OUT( ulSEBaseAddr, SPI_WORD_LEN,
		    FLD_SET(SPI_WORD_LEN, SPI_WORD_LEN, ( ChannelCfgPtr->SpiDataWidth - 4U)));

		REG_OUT( ulSEBaseAddr, GENI_BYTE_GRANULARITY,
		            FLD_SET( GENI_BYTE_GRANULARITY, GENI_BYTE_GRANULARITY, ucGranularity));
		prvSPIPackingConfig( ulSEBaseAddr, ChannelCfgPtr->SpiDataWidth);

		REG_OUT( ulSEBaseAddr, SPI_TX_TRANS_LEN, Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].TransferLength );
		REG_OUT( ulSEBaseAddr, SPI_RX_TRANS_LEN, Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].TransferLength );

		/* Configure Opcode & Params in GENI_M_CMD0 register. */
		REG_OUT( ulSEBaseAddr, GENI_M_CMD0,
            FLD_SET( GENI_M_CMD0, OPCODE, xOpcode) |
            FLD_SET( GENI_M_CMD0, PARAM, 0));
		REG_OUT( ulSEBaseAddr, GENI_RX_WATERMARK_REG,
				FLD_SET( GENI_RX_WATERMARK_REG, RX_WATERMARK, 13));
		REG_OUT( ulSEBaseAddr, GENI_TX_WATERMARK_REG,
            FLD_SET( GENI_TX_WATERMARK_REG, TX_WATERMARK, ulTXWatermark));
        ulIRQStatus = REG_IN( ulSEBaseAddr, GENI_M_IRQ_STATUS);
		if(FLD_GET(ulIRQStatus, GENI_M_IRQ_STATUS, TX_FIFO_WATERMARK) == 1U)
		{
			/*ToDo:Run a loop to support more than 60bytes transfer*/
			/* Write data into the FIFO */
			Spi_prvWriteToFifo( ulSEBaseAddr, ChannelIndex);
			REG_OUT( ulSEBaseAddr, GENI_M_IRQ_CLEAR, 0x40000000U);
		}
		ulRegTimeoutUS = POLL_TIME_DEFAULT_US;
		ulIRQStatus = REG_IN( ulSEBaseAddr, GENI_M_IRQ_STATUS);
		while( ( FLD_GET(ulIRQStatus, GENI_M_IRQ_STATUS, M_CMD_DONE) != 1U) && ( ulRegTimeoutUS != 0U ))
		{
			ulIRQStatus = REG_IN( ulSEBaseAddr, GENI_M_IRQ_STATUS);
			busywait( POLL_INTERVAL_US);
			ulRegTimeoutUS -= POLL_INTERVAL_US;
		}
		if ( ( ulRegTimeoutUS == 0U) && ( FLD_GET(ulIRQStatus, GENI_M_IRQ_STATUS, M_CMD_DONE) != 1U))
		{
			Spi_RunTimeStatus.JobStatus[JobIndex] = SPI_JOB_FAILED;
			RetVal = E_NOT_OK;
		}
		else
		{
			if( (FLD_GET( ulIRQStatus, GENI_M_IRQ_STATUS, RX_FIFO_WATERMARK) != 0U)  ||
			        		( FLD_GET( ulIRQStatus, GENI_M_IRQ_STATUS, RX_FIFO_LAST) != 0U))
			{
				/* Read data from the FIFO */
				Spi_prvReadFromFifo(  ulSEBaseAddr, ChannelIndex);
				/* clear the status bits */
				REG_OUT( ulSEBaseAddr, GENI_M_IRQ_CLEAR, HWIO_GENI_M_IRQ_CLEAR_M_CMD_DONE_CLEAR_BMSK);
				REG_OUT( ulSEBaseAddr, GENI_M_IRQ_CLEAR, ulIRQStatus);
				RetVal = E_OK;
			}
			else
			{
				Spi_RunTimeStatus.JobStatus[JobIndex] = SPI_JOB_FAILED;
				RetVal = E_NOT_OK;
			}
		}

		 /* Set the job status to "OK" - job successfully transmitted */
		Spi_RunTimeStatus.JobStatus[JobIndex] = SPI_JOB_OK;
		/* Update the HW status to IDLE after transmission*/
		Spi_RunTimeStatus.SpiBusStatus[HwIndex] = SPI_IDLE;
	}

	return RetVal;
}

/*******************************************************************************
* Service Name:    : Spi_prvSyncStartSequence
* Syntax           :static FUNC(Std_ReturnType, SPI_CODE_FAST) Spi_prvSyncStartSequence(
*											const VAR(Spi_SequenceType, AUTOMATIC) SeqIndex)
* Service Id(Hex)  :
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : SeqIndex - sequence index
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : Std_ReturnType - E_OK
*									  E_NOT_OK
* Description      : Service for starting the sync sequence
********************************************************************************/
SPI_FUNC static Std_ReturnType Spi_prvSyncStartSequence(
			const Spi_SequenceType SeqIndex)
{
	Std_ReturnType RetVal = E_NOT_OK;
	const Spi_JobType *Spi_JobAssignmentTblPtr  = NULL_PTR;
	Spi_JobType JobsPerSeq 						= 0XFFU;
	volatile Spi_JobType JobId					= 0XFFU;
	volatile Spi_JobType SpiJobLookUp 			= 0xFFU;
	uint16 JobIndex = SPI_JOB_DELIMITER;

	/* Get Job list , No. of Jobs  */
	Spi_JobAssignmentTblPtr	= GlobalConfigPtr->SequenceCfgPtr[SeqIndex].SpiJobAssignment;
	JobsPerSeq			= GlobalConfigPtr->SequenceCfgPtr[SeqIndex].SpiJobsPerSeq;
	for( SpiJobLookUp = 0U; SpiJobLookUp < JobsPerSeq ; SpiJobLookUp++ )
	{
		/* Get Job Id */
		JobId = Spi_JobAssignmentTblPtr[SpiJobLookUp];

		/*Get Job config table index of Job ID*/
		RetVal = Spi_prvGetJobIndex(JobId, &JobIndex);
		if(RetVal == (uint8)E_OK)
		{
			 /* Set jobs status to pending */
			Spi_RunTimeStatus.JobStatus[JobIndex] = SPI_JOB_PENDING;

			/* Start the Job transmission */
			RetVal = Spi_prvSyncStartJob( JobIndex);

			if( Spi_RunTimeStatus.JobStatus[JobIndex] == SPI_JOB_FAILED)
			{
				Spi_RunTimeStatus.SeqStatus[SeqIndex] = SPI_SEQ_FAILED;
				/* Set all remaining job status to SPI_JOB_FAILED*/
				while(SpiJobLookUp != JobsPerSeq)
				{
					/* Set the job status of sequence to be failed */
					SpiJobLookUp++;
					JobId = Spi_JobAssignmentTblPtr[SpiJobLookUp];
					/*Get Job config table index of Job ID*/
					RetVal = Spi_prvGetJobIndex(JobId, &JobIndex);
					if(RetVal == (uint8)E_OK)
					{
						Spi_RunTimeStatus.JobStatus[JobId] = SPI_JOB_FAILED;
					}
				}
			}
		}
	}

	/* If sequence is pending, update status to "OK" and indicate
	      successful transmission */
	if(Spi_RunTimeStatus.SeqStatus[SeqIndex] == SPI_SEQ_PENDING)
	{
		Spi_RunTimeStatus.SeqStatus[SeqIndex] = SPI_SEQ_OK;
	}

	return RetVal;
}

/*=================================================================================================
 @Service name        Spi_prvWriteToFifo
 @Description         This function write the data to be send into the FIFO
 @param[in]           ucHardwareId  - SE hardware ID
 @param[out]          NA
 @param[in, out]      NA
 @return              void
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          ->
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
SPI_FUNC static void Spi_prvWriteToFifo( uint32 ulSEBaseAddr, Spi_ChannelType ChannelIndex)
{
    uint32 ulLength = 0U;
    uint32 ulWord = 0U;
    uint8  ucWriteCount  = 0U;
    uint32 ulTxWaterMark = REG_INF(ulSEBaseAddr, GENI_TX_WATERMARK_REG, TX_WATERMARK);
    uint32 ulTxFifoDepth = REG_INF(ulSEBaseAddr, SE_HW_PARAM_0, TX_FIFO_DEPTH);
    const uint8 *puBuffer = Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].SrcPtr +
    		Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].TransferredLen;
    uint32 ulBytesToWrite = (ulTxFifoDepth << 2U) - (ulTxWaterMark << 2U);

    /* Find the number of bytes to write to FIFO */
    if( Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].TransferLength != 0U )
    {
        ulLength = Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].TransferLength;
    }

    /* Check if the data to be write is less then the Fifo size*/
    if ( ( ulLength - Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].TransferredLen) <= ulBytesToWrite)
    {
        /* Calculate the bytes to be write*/
        ulBytesToWrite = ulLength - Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].TransferredLen;
        /* reset the TX watermark level*/
        REG_OUT(ulSEBaseAddr, GENI_TX_WATERMARK_REG, FLD_SET(GENI_TX_WATERMARK_REG, TX_WATERMARK, 0));
    }

    /* Write the data into FIFO*/
    for( ucWriteCount = 0; ucWriteCount < ulBytesToWrite; ucWriteCount++)
    {
    /* Pack the 4 bytes to a single 32 bit. So it can be write directly to TX FIFO */
    	if ( ( ucWriteCount != 0U) && ( ( ucWriteCount % spiBYTES_PER_FIFO_REG) == 0U))
    	{
    		REG_OUTI(ulSEBaseAddr, GENI_TX_FIFOn, 0, ulWord);
    		ulWord = 0U;
    	}
    	ulWord = ulWord | (puBuffer[ucWriteCount] <<
                                         ( ( ucWriteCount % spiBYTES_PER_FIFO_REG)*spiBITS_PER_BYTE));
    }
    REG_OUTI(ulSEBaseAddr, GENI_TX_FIFOn, 0, ulWord);

   /* Update the data count to be transfered*/
	Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].TransferredLen += ulBytesToWrite;
}

/*=================================================================================================
 @Service name        Spi_prvReadFromFifo
 @Description         This function read the data from the RX FIFO and copy into the user space
 @param[in]           ucHardwareId - Hardware ID
 @param[out]          NA
 @param[in, out]      NA
 @return              void
 @Pre                 NA
 @Post                NA
 @Requirements IDs    -
 @Design IDs          -
 @service ID          -
 @Sync/Async          Synchronous function
 @Reentrancy          -
 @Note                -
=================================================================================================*/
SPI_FUNC static void Spi_prvReadFromFifo( uint32 ulSEBaseAddr, Spi_ChannelType ChannelIndex)
{
    uint32 ulBytesInLastWord = 0U;
    uint32 ulWord = 0U;
    uint8  ucReadCount = 0U;
    uint32 ulRXFifoStatus = REG_IN( ulSEBaseAddr, GENI_RX_FIFO_STATUS);

    uint32 ulBytesToRead = FLD_GET( ulRXFifoStatus, GENI_RX_FIFO_STATUS, RX_FIFO_WC) *spiBYTES_PER_FIFO_REG;
    uint32 ulReceived = Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].ReceivedLen;
    uint8 *puBuffer = Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].DestPtr + ulReceived;
    uint32 ulLength = Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].TransferLength;

    if ( FLD_GET( ulRXFifoStatus, GENI_RX_FIFO_STATUS, RX_LAST) != 0U)
    {
    	ulBytesInLastWord = FLD_GET( ulRXFifoStatus, GENI_RX_FIFO_STATUS, RX_LAST_BYTE_VALID);
        ulBytesToRead = ( ulBytesToRead - spiBYTES_PER_FIFO_REG ) + ulBytesInLastWord;
    }

    /* Check if the Transfer count is less then bytes to read*/
    if ( ( ulLength - ulReceived) < ulBytesToRead)
    {
        /* Find the bytes to read */
        ulBytesToRead = ulLength - ulReceived;
    }

    for ( ucReadCount = 0U; ucReadCount < ulBytesToRead; ucReadCount++)
    {
        if ( ( ucReadCount % spiBYTES_PER_FIFO_REG) == 0U)
        {
            ulWord = REG_INI(ulSEBaseAddr, GENI_RX_FIFOn, 0);
        }
        puBuffer[ucReadCount] = ( uint8)( ulWord >> ( ( ucReadCount % spiBYTES_PER_FIFO_REG)*spiBITS_PER_BYTE)) & 0xFFU;
    }

     /* Update the transfered count*/
    Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].ReceivedLen += ulBytesToRead;

    /*clear the rx_fifo_last status bit */
    if( Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].ReceivedLen == ulLength)
    {
        REG_OUT( ulSEBaseAddr, GENI_M_IRQ_CLEAR, HWIO_GENI_M_IRQ_CLEAR_RX_FIFO_LAST_CLEAR_BMSK);
    }

    /* Clear the Watermark status bit*/
    REG_OUT( ulSEBaseAddr, GENI_M_IRQ_CLEAR, HWIO_GENI_M_IRQ_CLEAR_RX_FIFO_WATERMARK_CLEAR_BMSK);
}
#if (SPI_DEBUG_MODE == 0x1U)
/*******************************************************************************
* Service Name:    : Spi_prvReportError
* Syntax           : static FUNC(void, SPI_CODE_FAST) Spi_prvReportError(
*											const uint8 ucApiId,
											const uint8 ucErrorId)
* Service Id(Hex)  : NA
* Sync/Async       : Synchronous
* Reentrancy       : Reentrant
* Parameters(IN)   : ucApiId  - API
* 					 ucErrorId - Error passed from API
* Parameters(INOUT): None
* Parameters(OUT)  : None
* Return Value     : None
* Description      : Service for reporting error to DET
********************************************************************************/
static void Spi_prvReportError( const uint8 ucApiId,
								const uint8 ucErrorId)
{
	DEBUG_LOG(SAIL_INFO,"[SPI] EL1 Error- API_ID:%d, Error_ID: %d \r\n", ucApiId, ucErrorId);
}
#endif

SPI_FUNC static Std_ReturnType Spi_prvAsyncStartJob(	const Spi_JobType JobIndex,
											uint8 HwIndex)
{
	Std_ReturnType RetVal = E_NOT_OK;
	const Spi_ChannelType * Spi_ChannelAssignmentTblPtr 	= NULL_PTR;
	Spi_ChannelType	ChannelId 		= 0XFFU;
	Spi_ChannelType ChannelIndex =  0x0U;
	Spi_ChannelType SpiChannelLookUp 	= 0x0;
	uint32 irq_enval = 0U;
    uint32 ulTXWatermark = 1U;
    uint32  ulIRQStatus = 0U;
    uint8 ucClockDiv = 0x0;
    uint8  ucGranularity = 0U;
    uint32 ulParams = 0U;
    uint8 xOpcode = 3;// GENI_M_CMD0_SPI_OPCODE_FULL_DUPLEX
    uint32 ulSEBaseAddr = GlobalConfigPtr->HwUnitCfgptr[HwIndex].SpiSEBaseAddr;

    const Spi_JobConfigType *SpiJobConfigPtr = &GlobalConfigPtr->JobCfgPtr[JobIndex];

	irq_enval = REG_IN( ulSEBaseAddr, GENI_M_IRQ_ENABLE);
	REG_OUT( ulSEBaseAddr, GENI_M_IRQ_ENABLE, (irq_enval & spiFIFO_TX_WATERMARK_IRQ_DISABLE));

	Spi_RunTimeStatus.SpiBusStatus[HwIndex] = SPI_BUSY;
	ulSEBaseAddr = GlobalConfigPtr->HwUnitCfgptr[HwIndex].SpiSEBaseAddr;

	//Spi_prvConfigTransferParam(SpiJobConfigPtr, );
    uint8 inter_word_delay_cycles = (uint8)(SpiJobConfigPtr->SpiInterWordDelay/SpiJobConfigPtr->SpiBaudrate);
    uint8 cs_clk_delay_cycles = (uint8)(SpiJobConfigPtr->SpiTimeCs2Clk/SpiJobConfigPtr->SpiBaudrate);

    REG_OUT( ulSEBaseAddr, SPI_LOOPBACK_CFG,
            FLD_SET(SPI_LOOPBACK_CFG, LOOPBACK_MODE,SpiJobConfigPtr->SpiInternalLoopBack));

    // QUPv3 HPG. 3.2.1. General Configuration
    ucClockDiv = 100000000/SpiJobConfigPtr->SpiBaudrate;
       /* spi config settings by setting dfs index and clock divider */
    REG_OUT( ulSEBaseAddr, GENI_SER_M_CLK_CFG,
        FLD_SET( GENI_SER_M_CLK_CFG, CLK_DIV_VALUE, ucClockDiv) |
        FLD_SET( GENI_SER_M_CLK_CFG, SER_CLK_EN, 1));

    REG_OUT( ulSEBaseAddr, SPI_CPHA, FLD_SET(SPI_CPHA, CPHA, SpiJobConfigPtr->SpiDataShiftEdge));
    REG_OUT( ulSEBaseAddr, SPI_CPOL, FLD_SET(SPI_CPOL, CPOL, SpiJobConfigPtr->SpiShiftClockIdleLevel));

	Spi_ChannelAssignmentTblPtr	= SpiJobConfigPtr->SpiChannelAssignment;

	/* Get Channel to be transmitted */
	ChannelId = Spi_ChannelAssignmentTblPtr[SpiChannelLookUp];

	REG_OUT( ulSEBaseAddr, SPI_DEMUX_SEL,
	    FLD_SET(SPI_DEMUX_SEL, CS_DEMUX_SEL, SpiJobConfigPtr->SpiCsIdentifier));

	REG_OUT( ulSEBaseAddr, SPI_DEMUX_OUTPUT_INV,
	    FLD_SET( SPI_DEMUX_OUTPUT_INV, CS_DEMUX_OUTPUT_INV, SpiJobConfigPtr->SpiCsPolarity));

	REG_OUT( ulSEBaseAddr, SPI_TRANS_CFG,
			        FLD_SET(SPI_TRANS_CFG, SPI_CS_TOGGLE, SpiJobConfigPtr->SpiCsBehavior));

	/* CS CLK & Inter word delay for channel */
	REG_OUT( ulSEBaseAddr, SPI_DELAYS_COUNTERS,
			        FLD_SET( SPI_DELAYS_COUNTERS, SPI_CS_CLK_DLY, cs_clk_delay_cycles) |
			        FLD_SET( SPI_DELAYS_COUNTERS, SPI_INTER_WORDS_DLY, inter_word_delay_cycles));

	if ( cs_clk_delay_cycles != 0U)
	{
		ulParams |= spiGENI_M_CMD0_SPI_PARAM_PRE_CMD_DLY;
	}
	/*Get channel configuration table index of channel ID*/
	if(Spi_prvGetChannelIndex(ChannelId, &ChannelIndex) == E_OK)
	{
		xASyncTrnCntxt[HwIndex].ChannelIdx = ChannelIndex;
		Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].TransferredLen = 0x0;
		Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].ReceivedLen = 0x0;
		const Spi_ChannelConfigType *ChannelCfgPtr = &GlobalConfigPtr->ChannelCfgPtr[ChannelIndex];
		if( ChannelCfgPtr->SpiDataWidth == 8U)
			{
				ucGranularity = 0U;
			}
			else
			{
				ucGranularity =  ChannelCfgPtr->SpiDataWidth >> 4U;
			}
				/* Channel data width configuration*/
			REG_OUT( ulSEBaseAddr, SPI_WORD_LEN,
			    FLD_SET(SPI_WORD_LEN, SPI_WORD_LEN, ( ChannelCfgPtr->SpiDataWidth - 4U)));

			REG_OUT( ulSEBaseAddr, GENI_BYTE_GRANULARITY,
			            FLD_SET( GENI_BYTE_GRANULARITY, GENI_BYTE_GRANULARITY, ucGranularity));
			prvSPIPackingConfig( ulSEBaseAddr, ChannelCfgPtr->SpiDataWidth);

			REG_OUT( ulSEBaseAddr, SPI_TX_TRANS_LEN, Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].TransferLength );
			REG_OUT( ulSEBaseAddr, SPI_RX_TRANS_LEN, Spi_RunTimeStatus.ChannelBufPtrs[ChannelIndex].TransferLength );

			/* Configure Opcode & Params in GENI_M_CMD0 register. */
			REG_OUT( ulSEBaseAddr, GENI_M_CMD0,
	            FLD_SET( GENI_M_CMD0, OPCODE, xOpcode) |
	            FLD_SET( GENI_M_CMD0, PARAM, 0));

			REG_OUT( ulSEBaseAddr, GENI_RX_WATERMARK_REG,
	            FLD_SET(GENI_RX_WATERMARK_REG, RX_WATERMARK, spiFIFO_RX_WATERMARK));
			REG_OUT( ulSEBaseAddr, GENI_TX_WATERMARK_REG,
	            FLD_SET( GENI_TX_WATERMARK_REG, TX_WATERMARK, ulTXWatermark));

			ulIRQStatus = REG_IN( ulSEBaseAddr, GENI_M_IRQ_STATUS);
			/* Write data into the FIFO */
			Spi_prvWriteToFifo( ulSEBaseAddr, (uint8)ChannelIndex);

			REG_OUT( ulSEBaseAddr, GENI_M_IRQ_CLEAR, ulIRQStatus);
			irq_enval = REG_IN( ulSEBaseAddr, GENI_M_IRQ_ENABLE);
			REG_OUT( ulSEBaseAddr, GENI_M_IRQ_ENABLE, (irq_enval|spiFIFO_TX_WATERMARK_IRQ_EN));
	}

	return RetVal;
}

/* SPI Transfer task definition*/
SPI_FUNC void vSPIXferHandlerTask( void *pvParameters )
{
	Std_ReturnType RetVal = E_NOT_OK;
	const Spi_JobType *Spi_JobAssignmentTblPtr  = NULL_PTR;
	Spi_JobType JobsPerSeq 						= 0XFFU;
	uint8 SeqIndex = 0U;
	volatile Spi_JobType JobId					= 0XFFU;
	Spi_JobType SpiJobLookUp 					= 0xFFU;
	uint16 JobIndex = SPI_JOB_DELIMITER;
	BaseType_t SpiQStaus 						= pdFAIL;
	uint8 ucHwIndex = 0x0;
	uint8_t ucHwMap = 0;
	uint8_t int_status = 0;
	uint8_t free_handle = 1;
	const Spi_ConfigType* ConfigPtr = &Spi_Config; 
	if( ConfigPtr->HwUnitCfgptr[ucHwMap].SpiHardwareType == ASYNCHRONOUS)
	{
		Spi_RunTimeStatus.SpiBusStatus[ucHwMap] = SPI_IDLE;
		int_status = Spi_prvConfigureIntrpt(ucHwMap, &ConfigPtr->HwUnitCfgptr[ucHwMap]);
		if( E_OK == int_status){
			DEBUG_LOG( SAIL_WARNING, "Spi_prvConfigureIntrpt enabled\n\r" );
		}else{
			DEBUG_LOG( SAIL_WARNING, "Spi_prvConfigureIntrpt failed\n\r" );
		}


		if( xFreeRTOSSemaphoreGive (xSPICBSemaphoreHandle) != pdTRUE ){
			DEBUG_LOG(SAIL_WARNING,"SPI Semaphore GIVE failed\n\r");
		}else{
			DEBUG_LOG(SAIL_WARNING,"SPI Semaphore GIVE sucess\n\r");
		}
	}
	for ( ; ; )
	{
		SpiQStaus = xFreeRTOSQueueReceive ( xSPISEQXFERQHandle, (void*)&SeqIndex, pdMS_TO_TICKS( freertosMAX_DELAY ));
		if( pdFAIL == SpiQStaus )
		{
			DEBUG_LOG( SAIL_WARNING, "vSPIXferHandlerTask(): Rx Seq Q FAIL !\n\r");
		}
		else
		{
			/* Set sequence status to pending */
			Spi_RunTimeStatus.SeqStatus[SeqIndex] = SPI_SEQ_PENDING;

			RetVal = Spi_prvGetHwUnitIndex(GlobalConfigPtr->SequenceCfgPtr[SeqIndex].SpiHwUnit, &ucHwIndex);
			if( RetVal == (uint8)E_OK)
			{
				xASyncTrnCntxt[ucHwIndex].SpiSeqIndex = SeqIndex;
				memset((void*) xASyncTrnCntxt, 0xFF, sizeof(SpiAsyncTransferCntxt));
				/* Update Handler status to SPI_BUSY before transmission*/
				Spi_JobAssignmentTblPtr	= GlobalConfigPtr->SequenceCfgPtr[SeqIndex].SpiJobAssignment;
				JobsPerSeq			= GlobalConfigPtr->SequenceCfgPtr[SeqIndex].SpiJobsPerSeq;
				xASyncTrnCntxt[ucHwIndex].SpiSeqIndex = SeqIndex;

				for( SpiJobLookUp = 0U; SpiJobLookUp < JobsPerSeq ; SpiJobLookUp++ )
				{
					/* Get Job Id */
					JobId = Spi_JobAssignmentTblPtr[SpiJobLookUp];

					/*Get Job config table index of Job ID*/
					RetVal = Spi_prvGetJobIndex(JobId, &JobIndex);
					if( RetVal == (uint8)E_OK)
					{
						if( SpiJobLookUp == (JobsPerSeq - 1))
						{
							xASyncTrnCntxt[ucHwIndex].LastJobIndex = JobIndex;
						}
						Spi_RunTimeStatus.JobStatus[JobIndex] = SPI_JOB_PENDING;


						if( pdPASS != xFreeRTOSSemaphoreTake( xSPICBSemaphoreHandle, pdMS_TO_TICKS(freertosMAX_DELAY) ) )
						{
							DEBUG_LOG(SAIL_WARNING,"SPI Callback Semaphore could not acquire\n\r");
						}

						xASyncTrnCntxt[ucHwIndex].usCurrentJobIdx = JobIndex;
						/* Start the Job transmission */
						RetVal = Spi_prvAsyncStartJob(JobIndex, ucHwIndex);
					}
				}
			}
		}

	}

}

/* SPI transfer message queue init*/
SPI_FUNC BaseType_t xSPISEQMsgQueueInit( CPUIdType_e xSchdCore )
{
	BaseType_t xCreateResult = pdPASS;
	xCreateResult = xFreeRTOSQueueCreate( xSPISEQXFERQBuffer,
			spiSEQ_Q_LEN,
			spiQ_ITEM_SIZE,
			&xSPISEQXFERQHandle,&xSPIQueueBuffer );
	if( xCreateResult != pdPASS )
	{
		xCreateResult = pdFAIL;
	}
	return xCreateResult;
}

/* SPI Transfer task init*/
SPI_FUNC BaseType_t xSPIXferHandlerTaskInit( CPUIdType_e           xSchdCore,
                                        UBaseType_t  spiXFERHNDLR_TASK_PRIORITY )
{
    BaseType_t xResult;
	UBaseType_t uxCoreAffinityMask;

    /* The structure passed to xSAILTaskCreate() to create the check task. */
    TaskParams_t xInitTaskParameters =
    {
    	.pvTaskCode =vSPIXferHandlerTask,        		/* The function that implements the task being created. */
		.pcName =  "vSPIXferHandlerTask",      		/* The name of the task being created. The kernel does not use this itself, it's just to assist debugging. */
        .pxTaskBuffer = &xSPIXferHandlerTaskTCB,          /* The buffer allocated for use as the task TCB. */
		.puxStackBuffer =xSPIXFERHNDLRTaskStack,         	/* The buffer allocated for use as the task stack. */
		.usStackDepth =spiXFERHNDLRTASK_STACK_SIZE,     /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        .pvParameters =NULL,                               /* The task parameter, not used in this case. */
		.uxPriority =spiXFERHNDLR_TASK_PRIORITY,       /* The priority assigned to the task being created. */
		.xRegions = {				   /* The MPU task parameters. */
			{NULL, 0UL, 0UL}, /* No additional region definitions are required. */
			{NULL, 0UL, 0UL},
			{NULL, 0UL, 0UL},
			{NULL, 0UL, 0UL},
			{NULL, 0UL, 0UL},
			{NULL, 0UL, 0UL}},
        
    };
	uxCoreAffinityMask = (1 << xSchdCore);  //Mapped to core 2 from core 0 for testing
	xResult = xFreeRTOSTaskCreateAffinitySet( &xInitTaskParameters,uxCoreAffinityMask, /* The structure containing the task parameters created at the start of this function. */
			&xSPIXferHandlerTaskHandle );
	/* Create the check task. */

	BaseType_t xReturn1 = xFreeRTOSSemaphoreCreateBinary(&xSPICBSemaphoreBuffer,&xSPICBSemaphoreHandle);
	if( pdFALSE == xReturn1)
	{
		DEBUG_LOG( SAIL_WARNING, "SPI Callback Binary Semaphore Creation failed\n\r" );
	}else{
		DEBUG_LOG( SAIL_WARNING, "[ SPI drv] SPI Callback Binary Semaphore Creation Success\n\r" );
	}


    return xResult;
}
#if 0 // TODO RADVA
void SPI_Module_Init(bootEntryStateType_e  xBootState,
                     bootRetentionFlagType xRetentionVal,
                     uint32_t              ulCoreNum )
{
   // uint cpu_index =  arch_curr_cpu_id();
    if(xBootState == BOOT_COLD_STARTUP ||  xRetentionVal == BOOT_NO_RETENTION_FLAG )
    {
    	Spi_Init(&Spi_Config);
    }
}

/* init module */
BOOT_MODULE_INIT_DEFINE( SPI_MODULE_ID,
                         INIT_GROUP_1,
                         SPI_Module_Init,
                         NULL,
                         INIT_CORE_2);
#endif
