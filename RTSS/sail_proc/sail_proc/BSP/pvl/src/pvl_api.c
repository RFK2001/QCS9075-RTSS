/*
===========================================================================
*/
/**
    @file  pvl_api.c
    @brief implementation of pvl tool

*/
/*
===========================================================================

    Copyright (c) 2023 Qualcomm Technologies, Inc.
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

	$Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/pvl/src/pvl_api.c#1 $
	$DateTime: 2025/07/09 22:36:30 $
	$Author: rmunibyr $

===========================================================================
*/

#include "types.h"
#include "common_functions.h"
#include "pvl.h"
#include "pvl_api.h"
#include "pvl_diag.h"

/* UART command coding examples:
 *                "NORPVL CMD_AUTO FREQ_AUTO DQS_AUTO KPI_AUTO STRESS_AUTO"
*                 "NORPVL CMD_INFO LOW DQS_AUTO KPI_AUTO STRESS_AUTO"
*                 "NORPVL 111S_111S 19200 dqs_disable kpi_disable stress_disable"
*
*/

static eNorPvlCmdType get_cmd(char*cmd)
{
  eNorPvlCmdType eCmd = NOR_PVL_CMD_MAX;

  if (sailbsp_stricmp("screening",(char*)cmd))
  {
    eCmd = NOR_PVL_CMD_SCREENING;
  }
  else if (sailbsp_stricmp("info",(char*)cmd))
  {
    eCmd = NOR_PVL_CMD_INFO;
  }
  else if (sailbsp_stricmp("crash_dbg",(char*)cmd))
  {
    eCmd = NOR_PVL_CMD_CRASH_DBG;
  }
  else if (sailbsp_stricmp("111s_111s",(char*)cmd))
  {
    eCmd = NOR_PVL_CMD_111S_111S;
  }
  else if (sailbsp_stricmp("114s_114s",(char*)cmd))
  {
    eCmd = NOR_PVL_CMD_114S_114S;
  }
  else if (sailbsp_stricmp("144s_144s",(char*)cmd))
  {
    eCmd = NOR_PVL_CMD_144S_144S;
  }
  else if (sailbsp_stricmp("444s_444s",(char*)cmd))
  {
    eCmd = NOR_PVL_CMD_444S_444S;
  }
  else if (sailbsp_stricmp("444d_444d",(char*)cmd))
  {
    eCmd = NOR_PVL_CMD_444D_444D;
  }
  else if (sailbsp_stricmp("118s_111s",(char*)cmd))
  {
    eCmd = NOR_PVL_CMD_118S_111S;
  }
  else if (sailbsp_stricmp("188s_111s",(char*)cmd))
  {
    eCmd = NOR_PVL_CMD_188S_111S;
  }
  else if (sailbsp_stricmp("888s_888s",(char*)cmd))
  {
    eCmd = NOR_PVL_CMD_888S_888S;
  }
  else if (sailbsp_stricmp("888d_888d",(char*)cmd))
  {
    eCmd = NOR_PVL_CMD_888D_888D;
  }
  else if(sailbsp_stricmp("mission",(char*)cmd))
  {
    eCmd = NOR_PVL_CMD_MISSION;
  }
  else if(sailbsp_stricmp("eval",(char*)cmd))
  {
    eCmd = NOR_PVL_CMD_EVAL;
  }
  else if(sailbsp_stricmp("help",(char*)cmd))
  {
    eCmd = NOR_PVL_CMD_HELP;
  }
  else if(sailbsp_stricmp("chiperase",(char*)cmd))
  {
    eCmd = NOR_PVL_CMD_CHIPERASE;
  }
  else if(sailbsp_stricmp("xbl_load",(char*)cmd))
  {
    eCmd = NOR_PVL_CMD_XBL_LOAD;
  }
  return eCmd;
}

static volatile int32_t slNorPvlStop = 0U;
void vPvlInit(void)
{
  //vPvlTest("screening", "low", "kpi_disable", "stress_disable", "no_test");
  //vPvlTest("111s_111s", "low", "kpi_disable", "stress_disable", "no_test");
  //vPvlTest("111s_111s", "166", "kpi_disable", "stress_disable", "no_test");
  vPvlInit1MBBuffer();
}

void vPvlTest(char* cmd, char* param0, char* param1, char* param2)
{
  eNorPvlCmdType eCmd  = NOR_PVL_CMD_MAX;
  int32_t slRet = NOR_PVL_RET_ERROR;
  do
  {
    if (cmd == NULL)
    {
      PVL_LOG_ERROR("NOR_PVL start: error, cmd is NULL\r\n");
      break;
    }
    eCmd = get_cmd(cmd);
    if (eCmd == NOR_PVL_CMD_MAX)
    {
      PVL_LOG_ERROR("NOR_PVL Error, invalid cmd '%s' received\r\n", cmd);
      break;
    }
    if (param0 == NULL)
    {
      PVL_LOG_WARNING("NOR_PVL start: cmd = '%s'\r\n", cmd);
      slRet = slPvlRun(eCmd, cmd);
      break;
    }
    else if (param1 == NULL)
    {
      PVL_LOG_WARNING("NOR_PVL start: cmd = '%s', param0 = '%s'\r\n",
                   cmd, param0);
      slRet = slPvlRun1Param(eCmd, cmd, param0);
      break;
    }
    else if (param2 == NULL)
    {
      PVL_LOG_WARNING("NOR_PVL start: cmd = '%s', param0 = '%s', param1 = '%s'\r\n",
                   cmd, param0, param1);
      slRet = slPvlRun2Params(eCmd, cmd, param0, param1);
      break;
    }
    else
    {
      PVL_LOG_WARNING("NOR_PVL start: cmd = '%s', param0 = '%s', param1 = '%s', param2 = '%s'\r\n",
                   cmd, param0, param1, param2);
      slRet = slPvlRun3Params(eCmd, cmd, param0, param1, param2);
      break;
    }
  } while (0U);
  if (slRet != NOR_PVL_RET_SUCCESS)
  {
    PVL_LOG_ERROR("NOR_PVL done with error\r\n");
  }
  else
  {
    PVL_LOG_WARNING("NOR_PVL done success\r\n");
  }
  return;
}





