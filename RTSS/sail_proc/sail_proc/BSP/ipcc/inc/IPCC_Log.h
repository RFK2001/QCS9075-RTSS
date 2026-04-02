#ifndef IPCCLOG_H__
#define IPCCLOG_H__
/*===========================================================================

  IPCC_Log.h

DESCRIPTION
  This modules contains the logging mechanism for IPCC Logs.

REFERENCES

       Copyright (c) 2018-2025 Qualcomm Technologies, Inc.
               All Rights Reserved.
            Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/

/*===========================================================================

                      EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.

$Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/ipcc/inc/IPCC_Log.h#1 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
05/29/18   cpaulo  First draft created. 
===========================================================================*/
#include "types.h"
#include "debug_log.h"

/*===========================================================================
FUNCTION IPCCLog_Init
===========================================================================*/
void IPCCLog_Init( void );


/*===========================================================================
FUNCTION IPCCLog_Out
===========================================================================*/
void IPCCLog_Out( uint32 nArgs, const char* sztStr, ... );
/*#ifndef SAILEL2
  #define IPCCLog_Out(nArgs,message, ...) \
        vLogMessage(TIMESTAMP_DISABLE,nArgs, message, ##__VA_ARGS__);
#else
  #define IPCCLog_Out(nArgs,message, ...)
#endif*/
#endif /*__IPCCLOG_H__*/
