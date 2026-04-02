/*
===========================================================================
*/
/**
    @file  pvl.h
    @brief pvl test definitions

*/
/*
===========================================================================

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

===========================================================================

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/pvl/inc/pvl.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

===========================================================================
*/

#ifndef __PVLH__
#define __PVLH__

#include "types.h"

typedef enum
{
  NOR_PVL_CMD_SCREENING,
  NOR_PVL_CMD_INFO,
  NOR_PVL_CMD_CRASH_DBG,
  NOR_PVL_CMD_111S_111S,   /* read 111S and write 111S */
  NOR_PVL_CMD_114S_114S,   /* read 114S and write 111S */
  NOR_PVL_CMD_144S_144S,   /* read 144S and write 111S */
  NOR_PVL_CMD_444S_444S,
  NOR_PVL_CMD_444D_444D,
  NOR_PVL_CMD_118S_111S,   /* read 118S and write 111S */
  NOR_PVL_CMD_188S_111S,   /* read 188S and write 111S */
  NOR_PVL_CMD_888S_888S,
  NOR_PVL_CMD_888D_888D,
  NOR_PVL_CMD_MISSION,     /* read, write and freq are set by the driver, i.e., mission mode configuration */
  NOR_PVL_CMD_EVAL,
  NOR_PVL_CMD_HELP,
  NOR_PVL_CMD_CHIPERASE,
  NOR_PVL_CMD_XBL_LOAD,
  NOR_PVL_CMD_MAX,
} eNorPvlCmdType;

#define DQS_DISABLE                  0
#define DQS_ENABLE                   1
#define DQS_AUTO                     2
#define KPI_DISABLE                  0
#define KPI_ENABLE                   1
#define KPI_AUTO                     2
#define STRESS_DISABLE               4
#define READ_STRESS_TEST             0
#define WRITE_STRESS_TEST            1
#define ERASE_STRESS_TEST            2
#define RD_WR_ER_STRESS_TEST         3

#define READ_32K_DUR_MSEC
#define READ_4K_DUR_MSEC
#define WRITE_4K_DUR_MSEC
#define ERASE_4K_DUR_MSEC

#define NOR_PVL_RET_SUCCESS          0
#define NOR_PVL_RET_ERROR           -1

#define PVL_PBL_CORE_CLOCK_KHZ       171000U
#define PVL_CRASH_DBG_CORE_CLOCK_KHZ 19200U
#define PVL_MAX_CLOCK_KHZ           166000U
#define PVL_STRESS_TEST_DURATION_MSEC 1800000000U // (30minutes) in microseconds
#define PVL_444D_MAX_FREQ             80000       // Hard code 80MHz for 444D */
#define PVL_114S_MAX_FREQ             83000       // Hard code 83MHz for 114S */
#define PVL_EVAL_STRESS_TEST_BUSY_WAIT_US 1000000U;
#define PVL_PBL_ONELANE_CLOCK_KHZ 40000U

int32_t slPvlRun(eNorPvlCmdType eCmd, char *cmd);
int32_t slPvlRun1Param(eNorPvlCmdType eCmd, char *cmd, char* param0);
int32_t slPvlRun2Params(eNorPvlCmdType eCmd, char *cmd, char* param0, char* param1);
int32_t slPvlRun3Params(eNorPvlCmdType eCmd, char *cmd, char* param0, char* param1, char* param2);
int32_t vPvlInit1MBBuffer(void);

#endif /* __PVL_H__ */
