/**
 * @file debug_log.h
 * @brief
 * Header file for debug macros of safety manager
 *
 *        Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/

#ifndef DEBUG_LOG_H_
#define DEBUG_LOG_H_

#include <stdio.h>
#include <stdint.h>

#define TIMESTAMP_STRING_SIZE   16
#define CORE_INDEX_PRINT_SIZE    2
#define configXO_MICROSEC		        ( 1000000UL )
#define configXO_TICKPERSEC		        ( 19200000UL )

#define SAIL_NOLOG      LOG_NONE
#define SAIL_ERROR      LOG_ERROR
#define SAIL_WARNING    LOG_WARNING
#define SAIL_INFO       LOG_INFO
#define SAIL_DEBUG      LOG_DEBUG
#define SAIL_LOG_NOUART LOG_NOUART
#define SAIL_LOG_LEVEL_MAX  LOG_LEVEL_MAX

typedef enum {
    LOG_NONE        = 0,
    LOG_ERROR       = 1,
    LOG_WARNING     = 2,
    LOG_INFO        = 3,
    LOG_DEBUG       = 4,
    LOG_NOUART      = 5,
    LOG_LEVEL_MAX,
} LogLevel_e;

typedef enum
{
    LOG_UART_STOP,
    LOG_UART_WORKING,
} LogUartState_e;

typedef struct
{
	uint32_t PrintAddress;
	uint32_t DataLen;
}UartLogType;

typedef enum
{
    LOG_MB_STOP,
    LOG_MB_WORKING,
} LogMBState_e;

typedef enum
{
    TIMESTAMP_DISABLE,
    TIMESTAMP_ENABLE,
} TimeStampInfo;
LogMBState_e eLogToMBSAILConsoleOff(void);
void vDebugLogRegNotifyCb(void (*pvDbgLogRxCb)(volatile void *rslt));
void vLogSetUartState(LogUartState_e eUartState);
void vLogSetLevel(LogLevel_e ulNewLevel);
void vLogMessage(TimeStampInfo Time_Stamp, LogLevel_e eLevel, const char *message, ...);
void vLogUartLogBufferDeinit(void);
void vDebugLogInit(void);
LogLevel_e vLogGetLevel(void);

#define LOG_DEBUG(message, ...) \
        vLogMessage(TIMESTAMP_ENABLE,LOG_DEBUG, message, ##__VA_ARGS__);

#define LOG_INFO(message, ...) \
        vLogMessage(TIMESTAMP_ENABLE,LOG_INFO, message, ##__VA_ARGS__);

#define LOG_WARNING(message, ...) \
        vLogMessage(TIMESTAMP_ENABLE,LOG_WARNING, message, ##__VA_ARGS__);

#define LOG_ERROR(message, ...) \
        vLogMessage(TIMESTAMP_ENABLE,LOG_ERROR, message, ##__VA_ARGS__);

#define LOG_NOUART(message, ...) \
        vLogMessage(TIMESTAMP_ENABLE,LOG_NOUART, message, ##__VA_ARGS__);

#define DEBUG_LOG(log_level, message, ...) \
        vLogMessage(TIMESTAMP_ENABLE,log_level, message, ##__VA_ARGS__);

#define DEBUG_LOG_NOTIMESTAMP(log_level, message, ...) \
        vLogMessage(TIMESTAMP_DISABLE,log_level, message, ##__VA_ARGS__);
		
#endif /* DEBUG_LOG_H_ */
