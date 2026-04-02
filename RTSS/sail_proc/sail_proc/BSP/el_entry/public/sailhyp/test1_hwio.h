#ifndef __TEST1_HWIO_H__
#define __TEST1_HWIO_H__
/*
===========================================================================
*/
/**
    @file sail_wwdog_hwio.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        LeMansAU [lemansau_v1.0_p3q1r37]

    This file contains HWIO register definitions for the following modules:
        SAILSS_RTCU_WDOG_0_RTCU_WWDOG
        SAILSS_RTCU_WDOG_1_RTCU_WWDOG
        SAILSS_RTCU_WDOG_2_RTCU_WWDOG
        SAILSS_RTCU_WDOG_3_RTCU_WWDOG


    Generation parameters:
    { 'filename': 'sail_wwdog_hwio.h',
      'header': '#include "msmhwiobase.h"',
      'modules': [ 'SAILSS_RTCU_WDOG_0_RTCU_WWDOG',
                   'SAILSS_RTCU_WDOG_1_RTCU_WWDOG',
                   'SAILSS_RTCU_WDOG_2_RTCU_WWDOG',
                   'SAILSS_RTCU_WDOG_3_RTCU_WWDOG'],
      'output-fvals': True,
      'output-offsets': True}
*/
/*
    ===========================================================================

    Copyright (c) 2021 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/el_entry/public/sailhyp/test1_hwio.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "msmhwiobase.h"

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_RTCU_WDOG_0_RTCU_WWDOG
 *--------------------------------------------------------------------------*/

#define SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE                                           (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_BASE      + 0x00000000)
#define SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_SIZE                                      0x1000
#define SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_USED                                      0x80
#define SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS                                      0x00000000

#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ENABLE_ADDR                                        (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0x0)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ENABLE_OFFS                                        (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ENABLE_RMSK                                               0x3
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ENABLE_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ENABLE_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ENABLE_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ENABLE_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ENABLE_IN)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ENABLE_ENABLE_BMSK                                        0x3
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ENABLE_ENABLE_SHFT                                          0

#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PET_ADDR                                           (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0x4)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PET_OFFS                                           (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PET_RMSK                                                  0x3
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PET_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PET_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PET_PET_BMSK                                              0x3
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PET_PET_SHFT                                                0

#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_START_TIME_ADDR                                    (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0x8)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_START_TIME_OFFS                                    (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_START_TIME_RMSK                                    0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_START_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_START_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_START_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_START_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_START_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_START_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_START_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_START_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_0_WWDOG_START_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_START_TIME_COUNT_BMSK                              0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_START_TIME_COUNT_SHFT                                       0

#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BARK_TIME_ADDR                                     (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0xc)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BARK_TIME_OFFS                                     (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0xc)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BARK_TIME_RMSK                                     0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BARK_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BARK_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BARK_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BARK_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BARK_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BARK_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BARK_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BARK_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BARK_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BARK_TIME_COUNT_BMSK                               0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BARK_TIME_COUNT_SHFT                                        0

#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BITE_TIME_ADDR                                     (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0x10)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BITE_TIME_OFFS                                     (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0x10)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BITE_TIME_RMSK                                     0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BITE_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BITE_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BITE_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BITE_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BITE_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BITE_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BITE_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BITE_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BITE_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BITE_TIME_COUNT_BMSK                               0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_BITE_TIME_COUNT_SHFT                                        0

#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MIN_TIME_ADDR                               (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0x14)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MIN_TIME_OFFS                               (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MIN_TIME_RMSK                               0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MIN_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MIN_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MIN_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MIN_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MIN_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MIN_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MIN_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MIN_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MIN_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MIN_TIME_COUNT_BMSK                         0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MIN_TIME_COUNT_SHFT                                  0

#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MAX_TIME_ADDR                               (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0x18)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MAX_TIME_OFFS                               (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0x18)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MAX_TIME_RMSK                               0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MAX_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MAX_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MAX_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MAX_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MAX_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MAX_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MAX_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MAX_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MAX_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MAX_TIME_COUNT_BMSK                         0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_WINDOW_MAX_TIME_COUNT_SHFT                                  0

#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_1_ADDR                                      (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0x1c)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_1_OFFS                                      (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0x1c)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_1_RMSK                                      0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_1_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_1_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_1_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_1_COUNT_BMSK                                0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_1_COUNT_SHFT                                         0

#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_2_ADDR                                      (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0x20)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_2_OFFS                                      (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0x20)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_2_RMSK                                             0x7
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_2_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_2_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_2_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_2_STATE_BMSK                                       0x7
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_2_STATE_SHFT                                         0

#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ERROR_SYNDROME_ADDR                                (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0x24)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ERROR_SYNDROME_OFFS                                (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0x24)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ERROR_SYNDROME_RMSK                                       0x7
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ERROR_SYNDROME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ERROR_SYNDROME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ERROR_SYNDROME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ERROR_SYNDROME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ERROR_SYNDROME_BARK_BMSK                                  0x4
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ERROR_SYNDROME_BARK_SHFT                                    2
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ERROR_SYNDROME_MAX_WINDOW_ERROR_BMSK                      0x2
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ERROR_SYNDROME_MAX_WINDOW_ERROR_SHFT                        1
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ERROR_SYNDROME_MIN_WINDOW_ERROR_BMSK                      0x1
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_ERROR_SYNDROME_MIN_WINDOW_ERROR_SHFT                        0

#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FREEZE_CTRL_ADDR                                   (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0x28)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FREEZE_CTRL_OFFS                                   (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0x28)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FREEZE_CTRL_RMSK                                          0x3
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FREEZE_CTRL_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FREEZE_CTRL_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FREEZE_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FREEZE_CTRL_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FREEZE_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FREEZE_CTRL_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FREEZE_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FREEZE_CTRL_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FREEZE_CTRL_IN)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FREEZE_CTRL_DEBUG_MODE_FREEZE_BMSK                        0x2
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FREEZE_CTRL_DEBUG_MODE_FREEZE_SHFT                          1
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FREEZE_CTRL_PWR_CTL_FREEZE_BMSK                           0x1
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FREEZE_CTRL_PWR_CTL_FREEZE_SHFT                             0

#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_RELOAD_CTRL_ADDR                                   (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0x2c)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_RELOAD_CTRL_OFFS                                   (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0x2c)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_RELOAD_CTRL_RMSK                                          0x7
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_RELOAD_CTRL_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_RELOAD_CTRL_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_RELOAD_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_RELOAD_CTRL_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_RELOAD_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_RELOAD_CTRL_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_RELOAD_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_RELOAD_CTRL_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_0_WWDOG_RELOAD_CTRL_IN)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_RELOAD_CTRL_FREEZE_2_RUN_AUTO_LOAD_BMSK                   0x4
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_RELOAD_CTRL_FREEZE_2_RUN_AUTO_LOAD_SHFT                     2
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_RELOAD_CTRL_FREEZE_2_ERROR_AUTO_LOAD_BMSK                 0x2
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_RELOAD_CTRL_FREEZE_2_ERROR_AUTO_LOAD_SHFT                   1
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_RELOAD_CTRL_RUN_2_ERROR_AUTO_LOAD_BMSK                    0x1
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_RELOAD_CTRL_RUN_2_ERROR_AUTO_LOAD_SHFT                      0

#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_EN_ADDR                                 (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0x30)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_EN_OFFS                                 (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0x30)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_EN_RMSK                                        0xf
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_EN_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_EN_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_EN_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_EN_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_EN_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_EN_IN)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_EN_ERROR_ID_BMSK                               0xf
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_EN_ERROR_ID_SHFT                                 0

#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_SYNDROME_ADDR                           (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0x34)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_SYNDROME_OFFS                           (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0x34)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_SYNDROME_RMSK                                  0xf
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_SYNDROME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_SYNDROME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_SYNDROME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_SYNDROME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_SYNDROME_ERROR_ID_BMSK                         0xf
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_SYNDROME_ERROR_ID_SHFT                           0

#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_ADDR                     (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0x38)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_OFFS                     (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0x38)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_RMSK                            0x1
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_CLEAR_BMSK                      0x1
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_CLEAR_SHFT                        0

#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_3_ADDR                                      (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0x3c)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_3_OFFS                                      (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0x3c)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_3_RMSK                                      0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_3_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_3_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_3_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_3_COUNT_REDUNDANT_BMSK                      0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_3_COUNT_REDUNDANT_SHFT                               0

#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_4_ADDR                                      (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0x40)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_4_OFFS                                      (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0x40)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_4_RMSK                                             0x7
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_4_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_4_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_4_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_4_STATE_REDUNDANT_BMSK                             0x7
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_STATUS_4_STATE_REDUNDANT_SHFT                               0

#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_CONTROL_ADDR                                   (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0x60)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_CONTROL_OFFS                                   (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0x60)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_CONTROL_RMSK                                   0x800fffff
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_CONTROL_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_CONTROL_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_CONTROL_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_CONTROL_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_CONTROL_IN)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_CONTROL_PWD_CHECK_ERROR_BMSK                   0x80000000
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_CONTROL_PWD_CHECK_ERROR_SHFT                           31
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_CONTROL_PWD_VALUE_BMSK                            0xffff0
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_CONTROL_PWD_VALUE_SHFT                                  4
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_CONTROL_PWD_CHECK_EN_BMSK                             0xf
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_CONTROL_PWD_CHECK_EN_SHFT                               0

#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_ADDR                                           (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0x64)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_OFFS                                           (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0x64)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_RMSK                                               0xffff
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_IN)
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_PWD_CSR_VALUE_BMSK                                 0xffff
#define HWIO_SAILSS_RTCU_WDOG_0_WWDOG_PWD_PWD_CSR_VALUE_SHFT                                      0

#define HWIO_SAILSS_RTCU_WDOG_0_FUSA_STATUS_REGISTER_ADDR                                (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE      + 0x80)
#define HWIO_SAILSS_RTCU_WDOG_0_FUSA_STATUS_REGISTER_OFFS                                (SAILSS_RTCU_WDOG_0_RTCU_WWDOG_REG_BASE_OFFS + 0x80)
#define HWIO_SAILSS_RTCU_WDOG_0_FUSA_STATUS_REGISTER_RMSK                                    0x1fff
#define HWIO_SAILSS_RTCU_WDOG_0_FUSA_STATUS_REGISTER_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_0_FUSA_STATUS_REGISTER_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_0_FUSA_STATUS_REGISTER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_0_FUSA_STATUS_REGISTER_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_0_FUSA_STATUS_REGISTER_HPCNT_BMSK                              0x1f80
#define HWIO_SAILSS_RTCU_WDOG_0_FUSA_STATUS_REGISTER_HPCNT_SHFT                                   7
#define HWIO_SAILSS_RTCU_WDOG_0_FUSA_STATUS_REGISTER_VPCNT_BMSK                                0x7e
#define HWIO_SAILSS_RTCU_WDOG_0_FUSA_STATUS_REGISTER_VPCNT_SHFT                                   1
#define HWIO_SAILSS_RTCU_WDOG_0_FUSA_STATUS_REGISTER_FLT_BMSK                                   0x1
#define HWIO_SAILSS_RTCU_WDOG_0_FUSA_STATUS_REGISTER_FLT_SHFT                                     0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_RTCU_WDOG_1_RTCU_WWDOG
 *--------------------------------------------------------------------------*/

#define SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE                                           (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_BASE      + 0x00000000)
#define SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_SIZE                                      0x1000
#define SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_USED                                      0x80
#define SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS                                      0x00000000

#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ENABLE_ADDR                                        (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0x0)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ENABLE_OFFS                                        (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ENABLE_RMSK                                               0x3
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ENABLE_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ENABLE_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ENABLE_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ENABLE_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ENABLE_IN)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ENABLE_ENABLE_BMSK                                        0x3
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ENABLE_ENABLE_SHFT                                          0

#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PET_ADDR                                           (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0x4)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PET_OFFS                                           (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PET_RMSK                                                  0x3
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PET_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PET_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PET_PET_BMSK                                              0x3
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PET_PET_SHFT                                                0

#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_START_TIME_ADDR                                    (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0x8)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_START_TIME_OFFS                                    (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_START_TIME_RMSK                                    0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_START_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_START_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_START_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_START_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_START_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_START_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_START_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_START_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_1_WWDOG_START_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_START_TIME_COUNT_BMSK                              0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_START_TIME_COUNT_SHFT                                       0

#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BARK_TIME_ADDR                                     (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0xc)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BARK_TIME_OFFS                                     (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0xc)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BARK_TIME_RMSK                                     0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BARK_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BARK_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BARK_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BARK_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BARK_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BARK_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BARK_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BARK_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BARK_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BARK_TIME_COUNT_BMSK                               0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BARK_TIME_COUNT_SHFT                                        0

#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BITE_TIME_ADDR                                     (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0x10)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BITE_TIME_OFFS                                     (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0x10)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BITE_TIME_RMSK                                     0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BITE_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BITE_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BITE_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BITE_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BITE_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BITE_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BITE_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BITE_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BITE_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BITE_TIME_COUNT_BMSK                               0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_BITE_TIME_COUNT_SHFT                                        0

#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MIN_TIME_ADDR                               (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0x14)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MIN_TIME_OFFS                               (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MIN_TIME_RMSK                               0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MIN_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MIN_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MIN_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MIN_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MIN_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MIN_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MIN_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MIN_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MIN_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MIN_TIME_COUNT_BMSK                         0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MIN_TIME_COUNT_SHFT                                  0

#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MAX_TIME_ADDR                               (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0x18)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MAX_TIME_OFFS                               (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0x18)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MAX_TIME_RMSK                               0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MAX_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MAX_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MAX_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MAX_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MAX_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MAX_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MAX_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MAX_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MAX_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MAX_TIME_COUNT_BMSK                         0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_WINDOW_MAX_TIME_COUNT_SHFT                                  0

#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_1_ADDR                                      (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0x1c)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_1_OFFS                                      (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0x1c)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_1_RMSK                                      0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_1_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_1_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_1_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_1_COUNT_BMSK                                0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_1_COUNT_SHFT                                         0

#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_2_ADDR                                      (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0x20)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_2_OFFS                                      (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0x20)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_2_RMSK                                             0x7
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_2_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_2_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_2_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_2_STATE_BMSK                                       0x7
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_2_STATE_SHFT                                         0

#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ERROR_SYNDROME_ADDR                                (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0x24)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ERROR_SYNDROME_OFFS                                (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0x24)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ERROR_SYNDROME_RMSK                                       0x7
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ERROR_SYNDROME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ERROR_SYNDROME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ERROR_SYNDROME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ERROR_SYNDROME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ERROR_SYNDROME_BARK_BMSK                                  0x4
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ERROR_SYNDROME_BARK_SHFT                                    2
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ERROR_SYNDROME_MAX_WINDOW_ERROR_BMSK                      0x2
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ERROR_SYNDROME_MAX_WINDOW_ERROR_SHFT                        1
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ERROR_SYNDROME_MIN_WINDOW_ERROR_BMSK                      0x1
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_ERROR_SYNDROME_MIN_WINDOW_ERROR_SHFT                        0

#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FREEZE_CTRL_ADDR                                   (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0x28)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FREEZE_CTRL_OFFS                                   (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0x28)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FREEZE_CTRL_RMSK                                          0x3
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FREEZE_CTRL_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FREEZE_CTRL_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FREEZE_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FREEZE_CTRL_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FREEZE_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FREEZE_CTRL_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FREEZE_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FREEZE_CTRL_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FREEZE_CTRL_IN)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FREEZE_CTRL_DEBUG_MODE_FREEZE_BMSK                        0x2
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FREEZE_CTRL_DEBUG_MODE_FREEZE_SHFT                          1
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FREEZE_CTRL_PWR_CTL_FREEZE_BMSK                           0x1
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FREEZE_CTRL_PWR_CTL_FREEZE_SHFT                             0

#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_RELOAD_CTRL_ADDR                                   (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0x2c)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_RELOAD_CTRL_OFFS                                   (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0x2c)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_RELOAD_CTRL_RMSK                                          0x7
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_RELOAD_CTRL_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_RELOAD_CTRL_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_RELOAD_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_RELOAD_CTRL_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_RELOAD_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_RELOAD_CTRL_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_RELOAD_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_RELOAD_CTRL_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_1_WWDOG_RELOAD_CTRL_IN)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_RELOAD_CTRL_FREEZE_2_RUN_AUTO_LOAD_BMSK                   0x4
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_RELOAD_CTRL_FREEZE_2_RUN_AUTO_LOAD_SHFT                     2
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_RELOAD_CTRL_FREEZE_2_ERROR_AUTO_LOAD_BMSK                 0x2
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_RELOAD_CTRL_FREEZE_2_ERROR_AUTO_LOAD_SHFT                   1
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_RELOAD_CTRL_RUN_2_ERROR_AUTO_LOAD_BMSK                    0x1
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_RELOAD_CTRL_RUN_2_ERROR_AUTO_LOAD_SHFT                      0

#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_EN_ADDR                                 (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0x30)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_EN_OFFS                                 (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0x30)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_EN_RMSK                                        0xf
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_EN_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_EN_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_EN_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_EN_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_EN_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_EN_IN)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_EN_ERROR_ID_BMSK                               0xf
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_EN_ERROR_ID_SHFT                                 0

#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_SYNDROME_ADDR                           (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0x34)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_SYNDROME_OFFS                           (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0x34)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_SYNDROME_RMSK                                  0xf
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_SYNDROME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_SYNDROME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_SYNDROME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_SYNDROME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_SYNDROME_ERROR_ID_BMSK                         0xf
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_SYNDROME_ERROR_ID_SHFT                           0

#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_ADDR                     (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0x38)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_OFFS                     (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0x38)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_RMSK                            0x1
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_CLEAR_BMSK                      0x1
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_CLEAR_SHFT                        0

#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_3_ADDR                                      (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0x3c)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_3_OFFS                                      (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0x3c)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_3_RMSK                                      0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_3_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_3_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_3_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_3_COUNT_REDUNDANT_BMSK                      0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_3_COUNT_REDUNDANT_SHFT                               0

#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_4_ADDR                                      (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0x40)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_4_OFFS                                      (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0x40)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_4_RMSK                                             0x7
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_4_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_4_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_4_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_4_STATE_REDUNDANT_BMSK                             0x7
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_STATUS_4_STATE_REDUNDANT_SHFT                               0

#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_CONTROL_ADDR                                   (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0x60)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_CONTROL_OFFS                                   (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0x60)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_CONTROL_RMSK                                   0x800fffff
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_CONTROL_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_CONTROL_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_CONTROL_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_CONTROL_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_CONTROL_IN)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_CONTROL_PWD_CHECK_ERROR_BMSK                   0x80000000
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_CONTROL_PWD_CHECK_ERROR_SHFT                           31
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_CONTROL_PWD_VALUE_BMSK                            0xffff0
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_CONTROL_PWD_VALUE_SHFT                                  4
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_CONTROL_PWD_CHECK_EN_BMSK                             0xf
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_CONTROL_PWD_CHECK_EN_SHFT                               0

#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_ADDR                                           (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0x64)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_OFFS                                           (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0x64)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_RMSK                                               0xffff
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_IN)
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_PWD_CSR_VALUE_BMSK                                 0xffff
#define HWIO_SAILSS_RTCU_WDOG_1_WWDOG_PWD_PWD_CSR_VALUE_SHFT                                      0

#define HWIO_SAILSS_RTCU_WDOG_1_FUSA_STATUS_REGISTER_ADDR                                (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE      + 0x80)
#define HWIO_SAILSS_RTCU_WDOG_1_FUSA_STATUS_REGISTER_OFFS                                (SAILSS_RTCU_WDOG_1_RTCU_WWDOG_REG_BASE_OFFS + 0x80)
#define HWIO_SAILSS_RTCU_WDOG_1_FUSA_STATUS_REGISTER_RMSK                                    0x1fff
#define HWIO_SAILSS_RTCU_WDOG_1_FUSA_STATUS_REGISTER_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_1_FUSA_STATUS_REGISTER_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_1_FUSA_STATUS_REGISTER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_1_FUSA_STATUS_REGISTER_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_1_FUSA_STATUS_REGISTER_HPCNT_BMSK                              0x1f80
#define HWIO_SAILSS_RTCU_WDOG_1_FUSA_STATUS_REGISTER_HPCNT_SHFT                                   7
#define HWIO_SAILSS_RTCU_WDOG_1_FUSA_STATUS_REGISTER_VPCNT_BMSK                                0x7e
#define HWIO_SAILSS_RTCU_WDOG_1_FUSA_STATUS_REGISTER_VPCNT_SHFT                                   1
#define HWIO_SAILSS_RTCU_WDOG_1_FUSA_STATUS_REGISTER_FLT_BMSK                                   0x1
#define HWIO_SAILSS_RTCU_WDOG_1_FUSA_STATUS_REGISTER_FLT_SHFT                                     0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_RTCU_WDOG_2_RTCU_WWDOG
 *--------------------------------------------------------------------------*/

#define SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE                                           (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_BASE      + 0x00000000)
#define SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_SIZE                                      0x1000
#define SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_USED                                      0x80
#define SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS                                      0x00000000

#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ENABLE_ADDR                                        (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0x0)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ENABLE_OFFS                                        (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ENABLE_RMSK                                               0x3
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ENABLE_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ENABLE_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ENABLE_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ENABLE_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ENABLE_IN)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ENABLE_ENABLE_BMSK                                        0x3
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ENABLE_ENABLE_SHFT                                          0

#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PET_ADDR                                           (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0x4)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PET_OFFS                                           (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PET_RMSK                                                  0x3
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PET_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PET_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PET_PET_BMSK                                              0x3
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PET_PET_SHFT                                                0

#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_START_TIME_ADDR                                    (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0x8)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_START_TIME_OFFS                                    (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_START_TIME_RMSK                                    0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_START_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_START_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_START_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_START_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_START_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_START_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_START_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_START_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_2_WWDOG_START_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_START_TIME_COUNT_BMSK                              0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_START_TIME_COUNT_SHFT                                       0

#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BARK_TIME_ADDR                                     (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0xc)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BARK_TIME_OFFS                                     (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0xc)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BARK_TIME_RMSK                                     0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BARK_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BARK_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BARK_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BARK_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BARK_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BARK_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BARK_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BARK_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BARK_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BARK_TIME_COUNT_BMSK                               0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BARK_TIME_COUNT_SHFT                                        0

#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BITE_TIME_ADDR                                     (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0x10)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BITE_TIME_OFFS                                     (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0x10)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BITE_TIME_RMSK                                     0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BITE_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BITE_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BITE_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BITE_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BITE_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BITE_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BITE_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BITE_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BITE_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BITE_TIME_COUNT_BMSK                               0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_BITE_TIME_COUNT_SHFT                                        0

#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MIN_TIME_ADDR                               (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0x14)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MIN_TIME_OFFS                               (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MIN_TIME_RMSK                               0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MIN_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MIN_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MIN_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MIN_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MIN_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MIN_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MIN_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MIN_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MIN_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MIN_TIME_COUNT_BMSK                         0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MIN_TIME_COUNT_SHFT                                  0

#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MAX_TIME_ADDR                               (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0x18)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MAX_TIME_OFFS                               (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0x18)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MAX_TIME_RMSK                               0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MAX_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MAX_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MAX_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MAX_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MAX_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MAX_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MAX_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MAX_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MAX_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MAX_TIME_COUNT_BMSK                         0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_WINDOW_MAX_TIME_COUNT_SHFT                                  0

#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_1_ADDR                                      (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0x1c)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_1_OFFS                                      (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0x1c)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_1_RMSK                                      0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_1_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_1_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_1_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_1_COUNT_BMSK                                0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_1_COUNT_SHFT                                         0

#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_2_ADDR                                      (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0x20)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_2_OFFS                                      (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0x20)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_2_RMSK                                             0x7
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_2_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_2_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_2_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_2_STATE_BMSK                                       0x7
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_2_STATE_SHFT                                         0

#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ERROR_SYNDROME_ADDR                                (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0x24)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ERROR_SYNDROME_OFFS                                (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0x24)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ERROR_SYNDROME_RMSK                                       0x7
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ERROR_SYNDROME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ERROR_SYNDROME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ERROR_SYNDROME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ERROR_SYNDROME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ERROR_SYNDROME_BARK_BMSK                                  0x4
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ERROR_SYNDROME_BARK_SHFT                                    2
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ERROR_SYNDROME_MAX_WINDOW_ERROR_BMSK                      0x2
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ERROR_SYNDROME_MAX_WINDOW_ERROR_SHFT                        1
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ERROR_SYNDROME_MIN_WINDOW_ERROR_BMSK                      0x1
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_ERROR_SYNDROME_MIN_WINDOW_ERROR_SHFT                        0

#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FREEZE_CTRL_ADDR                                   (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0x28)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FREEZE_CTRL_OFFS                                   (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0x28)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FREEZE_CTRL_RMSK                                          0x3
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FREEZE_CTRL_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FREEZE_CTRL_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FREEZE_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FREEZE_CTRL_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FREEZE_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FREEZE_CTRL_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FREEZE_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FREEZE_CTRL_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FREEZE_CTRL_IN)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FREEZE_CTRL_DEBUG_MODE_FREEZE_BMSK                        0x2
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FREEZE_CTRL_DEBUG_MODE_FREEZE_SHFT                          1
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FREEZE_CTRL_PWR_CTL_FREEZE_BMSK                           0x1
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FREEZE_CTRL_PWR_CTL_FREEZE_SHFT                             0

#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_RELOAD_CTRL_ADDR                                   (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0x2c)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_RELOAD_CTRL_OFFS                                   (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0x2c)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_RELOAD_CTRL_RMSK                                          0x7
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_RELOAD_CTRL_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_RELOAD_CTRL_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_RELOAD_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_RELOAD_CTRL_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_RELOAD_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_RELOAD_CTRL_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_RELOAD_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_RELOAD_CTRL_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_2_WWDOG_RELOAD_CTRL_IN)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_RELOAD_CTRL_FREEZE_2_RUN_AUTO_LOAD_BMSK                   0x4
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_RELOAD_CTRL_FREEZE_2_RUN_AUTO_LOAD_SHFT                     2
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_RELOAD_CTRL_FREEZE_2_ERROR_AUTO_LOAD_BMSK                 0x2
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_RELOAD_CTRL_FREEZE_2_ERROR_AUTO_LOAD_SHFT                   1
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_RELOAD_CTRL_RUN_2_ERROR_AUTO_LOAD_BMSK                    0x1
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_RELOAD_CTRL_RUN_2_ERROR_AUTO_LOAD_SHFT                      0

#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_EN_ADDR                                 (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0x30)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_EN_OFFS                                 (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0x30)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_EN_RMSK                                        0xf
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_EN_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_EN_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_EN_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_EN_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_EN_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_EN_IN)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_EN_ERROR_ID_BMSK                               0xf
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_EN_ERROR_ID_SHFT                                 0

#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_SYNDROME_ADDR                           (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0x34)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_SYNDROME_OFFS                           (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0x34)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_SYNDROME_RMSK                                  0xf
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_SYNDROME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_SYNDROME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_SYNDROME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_SYNDROME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_SYNDROME_ERROR_ID_BMSK                         0xf
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_SYNDROME_ERROR_ID_SHFT                           0

#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_ADDR                     (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0x38)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_OFFS                     (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0x38)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_RMSK                            0x1
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_CLEAR_BMSK                      0x1
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_CLEAR_SHFT                        0

#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_3_ADDR                                      (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0x3c)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_3_OFFS                                      (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0x3c)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_3_RMSK                                      0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_3_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_3_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_3_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_3_COUNT_REDUNDANT_BMSK                      0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_3_COUNT_REDUNDANT_SHFT                               0

#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_4_ADDR                                      (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0x40)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_4_OFFS                                      (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0x40)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_4_RMSK                                             0x7
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_4_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_4_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_4_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_4_STATE_REDUNDANT_BMSK                             0x7
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_STATUS_4_STATE_REDUNDANT_SHFT                               0

#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_CONTROL_ADDR                                   (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0x60)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_CONTROL_OFFS                                   (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0x60)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_CONTROL_RMSK                                   0x800fffff
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_CONTROL_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_CONTROL_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_CONTROL_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_CONTROL_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_CONTROL_IN)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_CONTROL_PWD_CHECK_ERROR_BMSK                   0x80000000
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_CONTROL_PWD_CHECK_ERROR_SHFT                           31
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_CONTROL_PWD_VALUE_BMSK                            0xffff0
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_CONTROL_PWD_VALUE_SHFT                                  4
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_CONTROL_PWD_CHECK_EN_BMSK                             0xf
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_CONTROL_PWD_CHECK_EN_SHFT                               0

#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_ADDR                                           (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0x64)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_OFFS                                           (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0x64)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_RMSK                                               0xffff
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_IN)
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_PWD_CSR_VALUE_BMSK                                 0xffff
#define HWIO_SAILSS_RTCU_WDOG_2_WWDOG_PWD_PWD_CSR_VALUE_SHFT                                      0

#define HWIO_SAILSS_RTCU_WDOG_2_FUSA_STATUS_REGISTER_ADDR                                (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE      + 0x80)
#define HWIO_SAILSS_RTCU_WDOG_2_FUSA_STATUS_REGISTER_OFFS                                (SAILSS_RTCU_WDOG_2_RTCU_WWDOG_REG_BASE_OFFS + 0x80)
#define HWIO_SAILSS_RTCU_WDOG_2_FUSA_STATUS_REGISTER_RMSK                                    0x1fff
#define HWIO_SAILSS_RTCU_WDOG_2_FUSA_STATUS_REGISTER_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_2_FUSA_STATUS_REGISTER_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_2_FUSA_STATUS_REGISTER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_2_FUSA_STATUS_REGISTER_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_2_FUSA_STATUS_REGISTER_HPCNT_BMSK                              0x1f80
#define HWIO_SAILSS_RTCU_WDOG_2_FUSA_STATUS_REGISTER_HPCNT_SHFT                                   7
#define HWIO_SAILSS_RTCU_WDOG_2_FUSA_STATUS_REGISTER_VPCNT_BMSK                                0x7e
#define HWIO_SAILSS_RTCU_WDOG_2_FUSA_STATUS_REGISTER_VPCNT_SHFT                                   1
#define HWIO_SAILSS_RTCU_WDOG_2_FUSA_STATUS_REGISTER_FLT_BMSK                                   0x1
#define HWIO_SAILSS_RTCU_WDOG_2_FUSA_STATUS_REGISTER_FLT_SHFT                                     0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_RTCU_WDOG_3_RTCU_WWDOG
 *--------------------------------------------------------------------------*/

#define SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE                                           (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_BASE      + 0x00000000)
#define SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_SIZE                                      0x1000
#define SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_USED                                      0x80
#define SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS                                      0x00000000

#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ENABLE_ADDR                                        (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0x0)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ENABLE_OFFS                                        (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ENABLE_RMSK                                               0x3
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ENABLE_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ENABLE_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ENABLE_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ENABLE_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ENABLE_IN)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ENABLE_ENABLE_BMSK                                        0x3
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ENABLE_ENABLE_SHFT                                          0

#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PET_ADDR                                           (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0x4)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PET_OFFS                                           (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PET_RMSK                                                  0x3
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PET_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PET_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PET_PET_BMSK                                              0x3
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PET_PET_SHFT                                                0

#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_START_TIME_ADDR                                    (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0x8)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_START_TIME_OFFS                                    (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_START_TIME_RMSK                                    0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_START_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_START_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_START_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_START_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_START_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_START_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_START_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_START_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_3_WWDOG_START_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_START_TIME_COUNT_BMSK                              0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_START_TIME_COUNT_SHFT                                       0

#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BARK_TIME_ADDR                                     (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0xc)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BARK_TIME_OFFS                                     (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0xc)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BARK_TIME_RMSK                                     0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BARK_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BARK_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BARK_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BARK_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BARK_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BARK_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BARK_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BARK_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BARK_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BARK_TIME_COUNT_BMSK                               0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BARK_TIME_COUNT_SHFT                                        0

#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BITE_TIME_ADDR                                     (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0x10)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BITE_TIME_OFFS                                     (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0x10)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BITE_TIME_RMSK                                     0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BITE_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BITE_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BITE_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BITE_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BITE_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BITE_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BITE_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BITE_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BITE_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BITE_TIME_COUNT_BMSK                               0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_BITE_TIME_COUNT_SHFT                                        0

#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MIN_TIME_ADDR                               (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0x14)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MIN_TIME_OFFS                               (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MIN_TIME_RMSK                               0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MIN_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MIN_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MIN_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MIN_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MIN_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MIN_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MIN_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MIN_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MIN_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MIN_TIME_COUNT_BMSK                         0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MIN_TIME_COUNT_SHFT                                  0

#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MAX_TIME_ADDR                               (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0x18)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MAX_TIME_OFFS                               (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0x18)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MAX_TIME_RMSK                               0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MAX_TIME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MAX_TIME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MAX_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MAX_TIME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MAX_TIME_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MAX_TIME_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MAX_TIME_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MAX_TIME_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MAX_TIME_IN)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MAX_TIME_COUNT_BMSK                         0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_WINDOW_MAX_TIME_COUNT_SHFT                                  0

#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_1_ADDR                                      (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0x1c)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_1_OFFS                                      (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0x1c)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_1_RMSK                                      0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_1_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_1_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_1_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_1_COUNT_BMSK                                0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_1_COUNT_SHFT                                         0

#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_2_ADDR                                      (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0x20)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_2_OFFS                                      (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0x20)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_2_RMSK                                             0x7
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_2_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_2_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_2_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_2_STATE_BMSK                                       0x7
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_2_STATE_SHFT                                         0

#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ERROR_SYNDROME_ADDR                                (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0x24)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ERROR_SYNDROME_OFFS                                (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0x24)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ERROR_SYNDROME_RMSK                                       0x7
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ERROR_SYNDROME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ERROR_SYNDROME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ERROR_SYNDROME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ERROR_SYNDROME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ERROR_SYNDROME_BARK_BMSK                                  0x4
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ERROR_SYNDROME_BARK_SHFT                                    2
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ERROR_SYNDROME_MAX_WINDOW_ERROR_BMSK                      0x2
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ERROR_SYNDROME_MAX_WINDOW_ERROR_SHFT                        1
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ERROR_SYNDROME_MIN_WINDOW_ERROR_BMSK                      0x1
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_ERROR_SYNDROME_MIN_WINDOW_ERROR_SHFT                        0

#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FREEZE_CTRL_ADDR                                   (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0x28)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FREEZE_CTRL_OFFS                                   (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0x28)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FREEZE_CTRL_RMSK                                          0x3
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FREEZE_CTRL_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FREEZE_CTRL_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FREEZE_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FREEZE_CTRL_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FREEZE_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FREEZE_CTRL_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FREEZE_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FREEZE_CTRL_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FREEZE_CTRL_IN)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FREEZE_CTRL_DEBUG_MODE_FREEZE_BMSK                        0x2
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FREEZE_CTRL_DEBUG_MODE_FREEZE_SHFT                          1
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FREEZE_CTRL_PWR_CTL_FREEZE_BMSK                           0x1
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FREEZE_CTRL_PWR_CTL_FREEZE_SHFT                             0

#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_RELOAD_CTRL_ADDR                                   (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0x2c)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_RELOAD_CTRL_OFFS                                   (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0x2c)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_RELOAD_CTRL_RMSK                                          0x7
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_RELOAD_CTRL_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_RELOAD_CTRL_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_RELOAD_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_RELOAD_CTRL_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_RELOAD_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_RELOAD_CTRL_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_RELOAD_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_RELOAD_CTRL_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_3_WWDOG_RELOAD_CTRL_IN)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_RELOAD_CTRL_FREEZE_2_RUN_AUTO_LOAD_BMSK                   0x4
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_RELOAD_CTRL_FREEZE_2_RUN_AUTO_LOAD_SHFT                     2
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_RELOAD_CTRL_FREEZE_2_ERROR_AUTO_LOAD_BMSK                 0x2
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_RELOAD_CTRL_FREEZE_2_ERROR_AUTO_LOAD_SHFT                   1
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_RELOAD_CTRL_RUN_2_ERROR_AUTO_LOAD_BMSK                    0x1
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_RELOAD_CTRL_RUN_2_ERROR_AUTO_LOAD_SHFT                      0

#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_EN_ADDR                                 (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0x30)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_EN_OFFS                                 (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0x30)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_EN_RMSK                                        0xf
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_EN_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_EN_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_EN_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_EN_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_EN_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_EN_IN)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_EN_ERROR_ID_BMSK                               0xf
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_EN_ERROR_ID_SHFT                                 0

#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_SYNDROME_ADDR                           (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0x34)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_SYNDROME_OFFS                           (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0x34)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_SYNDROME_RMSK                                  0xf
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_SYNDROME_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_SYNDROME_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_SYNDROME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_SYNDROME_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_SYNDROME_ERROR_ID_BMSK                         0xf
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_SYNDROME_ERROR_ID_SHFT                           0

#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_ADDR                     (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0x38)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_OFFS                     (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0x38)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_RMSK                            0x1
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_CLEAR_BMSK                      0x1
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_FUSA_ERROR_SYNDROME_CLEAR_CLEAR_SHFT                        0

#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_3_ADDR                                      (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0x3c)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_3_OFFS                                      (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0x3c)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_3_RMSK                                      0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_3_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_3_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_3_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_3_COUNT_REDUNDANT_BMSK                      0xffffffff
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_3_COUNT_REDUNDANT_SHFT                               0

#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_4_ADDR                                      (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0x40)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_4_OFFS                                      (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0x40)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_4_RMSK                                             0x7
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_4_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_4_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_4_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_4_STATE_REDUNDANT_BMSK                             0x7
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_STATUS_4_STATE_REDUNDANT_SHFT                               0

#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_CONTROL_ADDR                                   (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0x60)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_CONTROL_OFFS                                   (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0x60)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_CONTROL_RMSK                                   0x800fffff
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_CONTROL_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_CONTROL_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_CONTROL_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_CONTROL_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_CONTROL_IN)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_CONTROL_PWD_CHECK_ERROR_BMSK                   0x80000000
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_CONTROL_PWD_CHECK_ERROR_SHFT                           31
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_CONTROL_PWD_VALUE_BMSK                            0xffff0
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_CONTROL_PWD_VALUE_SHFT                                  4
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_CONTROL_PWD_CHECK_EN_BMSK                             0xf
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_CONTROL_PWD_CHECK_EN_SHFT                               0

#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_ADDR                                           (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0x64)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_OFFS                                           (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0x64)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_RMSK                                               0xffff
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_OUT(v)            \
                out_dword(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_ADDR,v)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_ADDR,m,v,HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_IN)
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_PWD_CSR_VALUE_BMSK                                 0xffff
#define HWIO_SAILSS_RTCU_WDOG_3_WWDOG_PWD_PWD_CSR_VALUE_SHFT                                      0

#define HWIO_SAILSS_RTCU_WDOG_3_FUSA_STATUS_REGISTER_ADDR                                (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE      + 0x80)
#define HWIO_SAILSS_RTCU_WDOG_3_FUSA_STATUS_REGISTER_OFFS                                (SAILSS_RTCU_WDOG_3_RTCU_WWDOG_REG_BASE_OFFS + 0x80)
#define HWIO_SAILSS_RTCU_WDOG_3_FUSA_STATUS_REGISTER_RMSK                                    0x1fff
#define HWIO_SAILSS_RTCU_WDOG_3_FUSA_STATUS_REGISTER_IN                    \
                in_dword(HWIO_SAILSS_RTCU_WDOG_3_FUSA_STATUS_REGISTER_ADDR)
#define HWIO_SAILSS_RTCU_WDOG_3_FUSA_STATUS_REGISTER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_RTCU_WDOG_3_FUSA_STATUS_REGISTER_ADDR, m)
#define HWIO_SAILSS_RTCU_WDOG_3_FUSA_STATUS_REGISTER_HPCNT_BMSK                              0x1f80
#define HWIO_SAILSS_RTCU_WDOG_3_FUSA_STATUS_REGISTER_HPCNT_SHFT                                   7
#define HWIO_SAILSS_RTCU_WDOG_3_FUSA_STATUS_REGISTER_VPCNT_BMSK                                0x7e
#define HWIO_SAILSS_RTCU_WDOG_3_FUSA_STATUS_REGISTER_VPCNT_SHFT                                   1
#define HWIO_SAILSS_RTCU_WDOG_3_FUSA_STATUS_REGISTER_FLT_BMSK                                   0x1
#define HWIO_SAILSS_RTCU_WDOG_3_FUSA_STATUS_REGISTER_FLT_SHFT                                     0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM
 *--------------------------------------------------------------------------*/

#define SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE                           (SAILSS_GIC0_KITE_GIC_BASE      + 0x00120000)
#define SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_SIZE                      0x10000
#define SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_USED                      0xfffc
#define SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS                      (SAILSS_GIC0_KITE_GIC_BASE_PHYS + 0x00120000)
#define SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS                      0x00120000

#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_ADDR                                    (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0x0)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_PHYS                                    (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0x0)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_OFFS                                    (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_RMSK                                    0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_OUT(v)            \
                out_dword(HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_ADDR,v)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_ADDR,m,v,HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_IN)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_UWP_BMSK                                0x80000000
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_UWP_SHFT                                        31
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_RES0_BMSK                               0x78000000
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_RES0_SHFT                                       27
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_DPG1S_BMSK                               0x4000000
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_DPG1S_SHFT                                      26
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_DPG1NS_BMSK                              0x2000000
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_DPG1NS_SHFT                                     25
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_DPG0_BMSK                                0x1000000
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_DPG0_SHFT                                       24
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_RES0_1_BMSK                               0xfffff0
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_RES0_1_SHFT                                      4
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_RWP_BMSK                                       0x8
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_RWP_SHFT                                         3
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_RES0_2_BMSK                                    0x6
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_RES0_2_SHFT                                      1
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_ENABLE_LPIS_BMSK                               0x1
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CTLR_ENABLE_LPIS_SHFT                                 0

#define HWIO_SAILSS_GIC0_ALIAS1_GICR_IIDR_ADDR                                    (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0x4)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_IIDR_PHYS                                    (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0x4)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_IIDR_OFFS                                    (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_IIDR_RMSK                                    0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_IIDR_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS1_GICR_IIDR_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_IIDR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS1_GICR_IIDR_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_IIDR_PRODUCTID_BMSK                          0xff000000
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_IIDR_PRODUCTID_SHFT                                  24
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_IIDR_RES0_BMSK                                 0xf00000
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_IIDR_RES0_SHFT                                       20
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_IIDR_VARIANT_BMSK                               0xf0000
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_IIDR_VARIANT_SHFT                                    16
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_IIDR_REVISION_BMSK                               0xf000
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_IIDR_REVISION_SHFT                                   12
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_IIDR_IMPLEMENTER_BMSK                             0xfff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_IIDR_IMPLEMENTER_SHFT                                 0

#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_ADDR                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0x8)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_PHYS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0x8)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_OFFS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_RMSK                                   0xffffffffffffffffuLL
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_IN                    \
                in_qword(HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_INM(m)            \
                in_qword_masked(HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_AFFINITY_VALUE_BMSK                    0xffffffff00000000uLL
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_AFFINITY_VALUE_SHFT                            32
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_RES0_BMSK                              0xfc000000
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_RES0_SHFT                                      26
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_COMMONLPIAFF_BMSK                       0x3000000
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_COMMONLPIAFF_SHFT                              24
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_PROCESSOR_NUMBER_BMSK                    0xffff00
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_PROCESSOR_NUMBER_SHFT                           8
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_RES0_1_BMSK                                  0xc0
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_RES0_1_SHFT                                     6
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_DPGS_BMSK                                    0x20
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_DPGS_SHFT                                       5
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_LAST_BMSK                                    0x10
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_LAST_SHFT                                       4
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_DIRECTLPI_BMSK                                0x8
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_DIRECTLPI_SHFT                                  3
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_RES0_2_BMSK                                   0x4
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_RES0_2_SHFT                                     2
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_VLPIS_BMSK                                    0x2
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_VLPIS_SHFT                                      1
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_PLPIS_BMSK                                    0x1
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_TYPER_PLPIS_SHFT                                      0

#define HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_ADDR                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0x14)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_PHYS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0x14)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_OFFS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_OUT(v)            \
                out_dword(HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_ADDR,v)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_ADDR,m,v,HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_IN)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_IMPLEMENTATION_DEFINED_BMSK            0x80000000
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_IMPLEMENTATION_DEFINED_SHFT                    31
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_RES0_BMSK                              0x7ffffff8
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_RES0_SHFT                                       3
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_CHILDRENASLEEP_BMSK                           0x4
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_CHILDRENASLEEP_SHFT                             2
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_PROCESSORSLEEP_BMSK                           0x2
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_PROCESSORSLEEP_SHFT                             1
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_IMPLEMENTATION_DEFINED_0_BMSK                 0x1
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_WAKER_IMPLEMENTATION_DEFINED_0_SHFT                   0

#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR4_ADDR                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xffd0)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR4_PHYS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xffd0)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR4_OFFS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xffd0)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR4_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR4_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR4_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR4_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR4_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR4_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR4_SIZE_BMSK                                    0xf0
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR4_SIZE_SHFT                                       4
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR4_DES_2_BMSK                                    0xf
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR4_DES_2_SHFT                                      0

#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR5_ADDR                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xffd4)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR5_PHYS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xffd4)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR5_OFFS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xffd4)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR5_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR5_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR5_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR5_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR5_RES0_BMSK                              0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR5_RES0_SHFT                                       0

#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR6_ADDR                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xffd8)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR6_PHYS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xffd8)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR6_OFFS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xffd8)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR6_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR6_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR6_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR6_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR6_RES0_BMSK                              0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR6_RES0_SHFT                                       0

#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR7_ADDR                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xffdc)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR7_PHYS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xffdc)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR7_OFFS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xffdc)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR7_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR7_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR7_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR7_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR7_RES0_BMSK                              0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR7_RES0_SHFT                                       0

#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR0_ADDR                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xffe0)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR0_PHYS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xffe0)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR0_OFFS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xffe0)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR0_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR0_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR0_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR0_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR0_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR0_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR0_PART_0_BMSK                                  0xff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR0_PART_0_SHFT                                     0

#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR1_ADDR                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xffe4)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR1_PHYS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xffe4)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR1_OFFS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xffe4)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR1_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR1_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR1_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR1_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR1_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR1_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR1_DES_0_BMSK                                   0xf0
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR1_DES_0_SHFT                                      4
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR1_PART_1_BMSK                                   0xf
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR1_PART_1_SHFT                                     0

#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR2_ADDR                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xffe8)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR2_PHYS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xffe8)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR2_OFFS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xffe8)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR2_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR2_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR2_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR2_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR2_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR2_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR2_REVISION_BMSK                                0xf0
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR2_REVISION_SHFT                                   4
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR2_JEDEC_BMSK                                    0x8
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR2_JEDEC_SHFT                                      3
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR2_DES_1_BMSK                                    0x7
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR2_DES_1_SHFT                                      0

#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR3_ADDR                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xffec)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR3_PHYS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xffec)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR3_OFFS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xffec)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR3_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR3_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR3_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR3_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR3_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR3_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR3_REVAND_BMSK                                  0xf0
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR3_REVAND_SHFT                                     4
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR3_CMOD_BMSK                                     0xf
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_PIDR3_CMOD_SHFT                                       0

#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR0_ADDR                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xfff0)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR0_PHYS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xfff0)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR0_OFFS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xfff0)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR0_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR0_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR0_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR0_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR0_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR0_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR0_PRMBL_0_BMSK                                 0xff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR0_PRMBL_0_SHFT                                    0

#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR1_ADDR                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xfff4)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR1_PHYS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xfff4)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR1_OFFS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xfff4)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR1_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR1_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR1_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR1_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR1_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR1_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR1_CLASS_BMSK                                   0xf0
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR1_CLASS_SHFT                                      4
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR1_PRMBL_1_BMSK                                  0xf
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR1_PRMBL_1_SHFT                                    0

#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR2_ADDR                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xfff8)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR2_PHYS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xfff8)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR2_OFFS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xfff8)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR2_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR2_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR2_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR2_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR2_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR2_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR2_PRMBL_2_BMSK                                 0xff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR2_PRMBL_2_SHFT                                    0

#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR3_ADDR                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xfffc)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR3_PHYS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xfffc)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR3_OFFS                                   (SAILSS_GIC0_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xfffc)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR3_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR3_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR3_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR3_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR3_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR3_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR3_PRMBL_3_BMSK                                 0xff
#define HWIO_SAILSS_GIC0_ALIAS1_GICR_CIDR3_PRMBL_3_SHFT                                    0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM
 *--------------------------------------------------------------------------*/

#define SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE                           (SAILSS_GIC0_KITE_GIC_BASE      + 0x00100000)
#define SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_SIZE                      0x10000
#define SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_USED                      0xfffc
#define SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS                      (SAILSS_GIC0_KITE_GIC_BASE_PHYS + 0x00100000)
#define SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS                      0x00100000

#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_ADDR                                    (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0x0)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_PHYS                                    (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0x0)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_OFFS                                    (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_RMSK                                    0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_OUT(v)            \
                out_dword(HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_ADDR,v)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_ADDR,m,v,HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_IN)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_UWP_BMSK                                0x80000000
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_UWP_SHFT                                        31
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_RES0_BMSK                               0x78000000
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_RES0_SHFT                                       27
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_DPG1S_BMSK                               0x4000000
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_DPG1S_SHFT                                      26
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_DPG1NS_BMSK                              0x2000000
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_DPG1NS_SHFT                                     25
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_DPG0_BMSK                                0x1000000
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_DPG0_SHFT                                       24
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_RES0_1_BMSK                               0xfffff0
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_RES0_1_SHFT                                      4
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_RWP_BMSK                                       0x8
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_RWP_SHFT                                         3
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_RES0_2_BMSK                                    0x6
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_RES0_2_SHFT                                      1
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_ENABLE_LPIS_BMSK                               0x1
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CTLR_ENABLE_LPIS_SHFT                                 0

#define HWIO_SAILSS_GIC0_ALIAS0_GICR_IIDR_ADDR                                    (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0x4)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_IIDR_PHYS                                    (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0x4)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_IIDR_OFFS                                    (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_IIDR_RMSK                                    0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_IIDR_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS0_GICR_IIDR_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_IIDR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS0_GICR_IIDR_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_IIDR_PRODUCTID_BMSK                          0xff000000
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_IIDR_PRODUCTID_SHFT                                  24
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_IIDR_RES0_BMSK                                 0xf00000
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_IIDR_RES0_SHFT                                       20
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_IIDR_VARIANT_BMSK                               0xf0000
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_IIDR_VARIANT_SHFT                                    16
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_IIDR_REVISION_BMSK                               0xf000
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_IIDR_REVISION_SHFT                                   12
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_IIDR_IMPLEMENTER_BMSK                             0xfff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_IIDR_IMPLEMENTER_SHFT                                 0

#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_ADDR                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0x8)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_PHYS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0x8)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_OFFS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_RMSK                                   0xffffffffffffffffuLL
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_IN                    \
                in_qword(HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_INM(m)            \
                in_qword_masked(HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_AFFINITY_VALUE_BMSK                    0xffffffff00000000uLL
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_AFFINITY_VALUE_SHFT                            32
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_RES0_BMSK                              0xfc000000
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_RES0_SHFT                                      26
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_COMMONLPIAFF_BMSK                       0x3000000
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_COMMONLPIAFF_SHFT                              24
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_PROCESSOR_NUMBER_BMSK                    0xffff00
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_PROCESSOR_NUMBER_SHFT                           8
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_RES0_1_BMSK                                  0xc0
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_RES0_1_SHFT                                     6
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_DPGS_BMSK                                    0x20
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_DPGS_SHFT                                       5
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_LAST_BMSK                                    0x10
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_LAST_SHFT                                       4
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_DIRECTLPI_BMSK                                0x8
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_DIRECTLPI_SHFT                                  3
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_RES0_2_BMSK                                   0x4
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_RES0_2_SHFT                                     2
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_VLPIS_BMSK                                    0x2
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_VLPIS_SHFT                                      1
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_PLPIS_BMSK                                    0x1
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_TYPER_PLPIS_SHFT                                      0

#define HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_ADDR                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0x14)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_PHYS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0x14)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_OFFS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_OUT(v)            \
                out_dword(HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_ADDR,v)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_ADDR,m,v,HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_IN)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_IMPLEMENTATION_DEFINED_BMSK            0x80000000
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_IMPLEMENTATION_DEFINED_SHFT                    31
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_RES0_BMSK                              0x7ffffff8
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_RES0_SHFT                                       3
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_CHILDRENASLEEP_BMSK                           0x4
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_CHILDRENASLEEP_SHFT                             2
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_PROCESSORSLEEP_BMSK                           0x2
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_PROCESSORSLEEP_SHFT                             1
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_IMPLEMENTATION_DEFINED_0_BMSK                 0x1
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_WAKER_IMPLEMENTATION_DEFINED_0_SHFT                   0

#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR4_ADDR                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xffd0)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR4_PHYS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xffd0)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR4_OFFS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xffd0)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR4_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR4_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR4_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR4_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR4_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR4_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR4_SIZE_BMSK                                    0xf0
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR4_SIZE_SHFT                                       4
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR4_DES_2_BMSK                                    0xf
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR4_DES_2_SHFT                                      0

#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR5_ADDR                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xffd4)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR5_PHYS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xffd4)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR5_OFFS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xffd4)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR5_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR5_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR5_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR5_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR5_RES0_BMSK                              0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR5_RES0_SHFT                                       0

#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR6_ADDR                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xffd8)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR6_PHYS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xffd8)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR6_OFFS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xffd8)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR6_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR6_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR6_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR6_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR6_RES0_BMSK                              0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR6_RES0_SHFT                                       0

#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR7_ADDR                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xffdc)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR7_PHYS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xffdc)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR7_OFFS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xffdc)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR7_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR7_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR7_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR7_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR7_RES0_BMSK                              0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR7_RES0_SHFT                                       0

#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR0_ADDR                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xffe0)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR0_PHYS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xffe0)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR0_OFFS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xffe0)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR0_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR0_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR0_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR0_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR0_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR0_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR0_PART_0_BMSK                                  0xff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR0_PART_0_SHFT                                     0

#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR1_ADDR                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xffe4)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR1_PHYS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xffe4)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR1_OFFS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xffe4)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR1_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR1_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR1_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR1_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR1_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR1_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR1_DES_0_BMSK                                   0xf0
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR1_DES_0_SHFT                                      4
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR1_PART_1_BMSK                                   0xf
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR1_PART_1_SHFT                                     0

#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR2_ADDR                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xffe8)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR2_PHYS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xffe8)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR2_OFFS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xffe8)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR2_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR2_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR2_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR2_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR2_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR2_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR2_REVISION_BMSK                                0xf0
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR2_REVISION_SHFT                                   4
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR2_JEDEC_BMSK                                    0x8
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR2_JEDEC_SHFT                                      3
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR2_DES_1_BMSK                                    0x7
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR2_DES_1_SHFT                                      0

#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR3_ADDR                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xffec)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR3_PHYS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xffec)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR3_OFFS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xffec)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR3_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR3_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR3_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR3_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR3_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR3_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR3_REVAND_BMSK                                  0xf0
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR3_REVAND_SHFT                                     4
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR3_CMOD_BMSK                                     0xf
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_PIDR3_CMOD_SHFT                                       0

#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR0_ADDR                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xfff0)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR0_PHYS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xfff0)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR0_OFFS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xfff0)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR0_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR0_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR0_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR0_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR0_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR0_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR0_PRMBL_0_BMSK                                 0xff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR0_PRMBL_0_SHFT                                    0

#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR1_ADDR                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xfff4)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR1_PHYS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xfff4)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR1_OFFS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xfff4)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR1_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR1_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR1_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR1_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR1_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR1_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR1_CLASS_BMSK                                   0xf0
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR1_CLASS_SHFT                                      4
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR1_PRMBL_1_BMSK                                  0xf
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR1_PRMBL_1_SHFT                                    0

#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR2_ADDR                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xfff8)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR2_PHYS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xfff8)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR2_OFFS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xfff8)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR2_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR2_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR2_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR2_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR2_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR2_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR2_PRMBL_2_BMSK                                 0xff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR2_PRMBL_2_SHFT                                    0

#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR3_ADDR                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xfffc)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR3_PHYS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xfffc)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR3_OFFS                                   (SAILSS_GIC0_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xfffc)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR3_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR3_IN                    \
                in_dword(HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR3_ADDR)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR3_ADDR, m)
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR3_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR3_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR3_PRMBL_3_BMSK                                 0xff
#define HWIO_SAILSS_GIC0_ALIAS0_GICR_CIDR3_PRMBL_3_SHFT                                    0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM
 *--------------------------------------------------------------------------*/

#define SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE                           (SAILSS_GIC1_KITE_GIC_BASE      + 0x00100000)
#define SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_SIZE                      0x10000
#define SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_USED                      0xfffc
#define SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS                      (SAILSS_GIC1_KITE_GIC_BASE_PHYS + 0x00100000)
#define SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS                      0x00100000

#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_ADDR                                    (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0x0)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_PHYS                                    (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0x0)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_OFFS                                    (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_RMSK                                    0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_OUT(v)            \
                out_dword(HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_ADDR,v)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_ADDR,m,v,HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_IN)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_UWP_BMSK                                0x80000000
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_UWP_SHFT                                        31
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_RES0_BMSK                               0x78000000
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_RES0_SHFT                                       27
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_DPG1S_BMSK                               0x4000000
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_DPG1S_SHFT                                      26
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_DPG1NS_BMSK                              0x2000000
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_DPG1NS_SHFT                                     25
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_DPG0_BMSK                                0x1000000
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_DPG0_SHFT                                       24
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_RES0_1_BMSK                               0xfffff0
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_RES0_1_SHFT                                      4
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_RWP_BMSK                                       0x8
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_RWP_SHFT                                         3
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_RES0_2_BMSK                                    0x6
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_RES0_2_SHFT                                      1
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_ENABLE_LPIS_BMSK                               0x1
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CTLR_ENABLE_LPIS_SHFT                                 0

#define HWIO_SAILSS_GIC1_ALIAS0_GICR_IIDR_ADDR                                    (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0x4)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_IIDR_PHYS                                    (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0x4)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_IIDR_OFFS                                    (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_IIDR_RMSK                                    0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_IIDR_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS0_GICR_IIDR_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_IIDR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS0_GICR_IIDR_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_IIDR_PRODUCTID_BMSK                          0xff000000
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_IIDR_PRODUCTID_SHFT                                  24
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_IIDR_RES0_BMSK                                 0xf00000
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_IIDR_RES0_SHFT                                       20
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_IIDR_VARIANT_BMSK                               0xf0000
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_IIDR_VARIANT_SHFT                                    16
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_IIDR_REVISION_BMSK                               0xf000
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_IIDR_REVISION_SHFT                                   12
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_IIDR_IMPLEMENTER_BMSK                             0xfff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_IIDR_IMPLEMENTER_SHFT                                 0

#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_ADDR                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0x8)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_PHYS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0x8)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_OFFS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_RMSK                                   0xffffffffffffffffuLL
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_IN                    \
                in_qword(HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_INM(m)            \
                in_qword_masked(HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_AFFINITY_VALUE_BMSK                    0xffffffff00000000uLL
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_AFFINITY_VALUE_SHFT                            32
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_RES0_BMSK                              0xfc000000
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_RES0_SHFT                                      26
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_COMMONLPIAFF_BMSK                       0x3000000
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_COMMONLPIAFF_SHFT                              24
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_PROCESSOR_NUMBER_BMSK                    0xffff00
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_PROCESSOR_NUMBER_SHFT                           8
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_RES0_1_BMSK                                  0xc0
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_RES0_1_SHFT                                     6
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_DPGS_BMSK                                    0x20
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_DPGS_SHFT                                       5
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_LAST_BMSK                                    0x10
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_LAST_SHFT                                       4
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_DIRECTLPI_BMSK                                0x8
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_DIRECTLPI_SHFT                                  3
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_RES0_2_BMSK                                   0x4
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_RES0_2_SHFT                                     2
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_VLPIS_BMSK                                    0x2
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_VLPIS_SHFT                                      1
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_PLPIS_BMSK                                    0x1
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_TYPER_PLPIS_SHFT                                      0

#define HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_ADDR                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0x14)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_PHYS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0x14)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_OFFS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_OUT(v)            \
                out_dword(HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_ADDR,v)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_ADDR,m,v,HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_IN)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_IMPLEMENTATION_DEFINED_BMSK            0x80000000
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_IMPLEMENTATION_DEFINED_SHFT                    31
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_RES0_BMSK                              0x7ffffff8
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_RES0_SHFT                                       3
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_CHILDRENASLEEP_BMSK                           0x4
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_CHILDRENASLEEP_SHFT                             2
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_PROCESSORSLEEP_BMSK                           0x2
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_PROCESSORSLEEP_SHFT                             1
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_IMPLEMENTATION_DEFINED_0_BMSK                 0x1
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_WAKER_IMPLEMENTATION_DEFINED_0_SHFT                   0

#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR4_ADDR                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xffd0)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR4_PHYS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xffd0)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR4_OFFS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xffd0)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR4_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR4_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR4_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR4_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR4_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR4_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR4_SIZE_BMSK                                    0xf0
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR4_SIZE_SHFT                                       4
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR4_DES_2_BMSK                                    0xf
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR4_DES_2_SHFT                                      0

#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR5_ADDR                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xffd4)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR5_PHYS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xffd4)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR5_OFFS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xffd4)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR5_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR5_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR5_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR5_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR5_RES0_BMSK                              0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR5_RES0_SHFT                                       0

#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR6_ADDR                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xffd8)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR6_PHYS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xffd8)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR6_OFFS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xffd8)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR6_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR6_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR6_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR6_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR6_RES0_BMSK                              0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR6_RES0_SHFT                                       0

#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR7_ADDR                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xffdc)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR7_PHYS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xffdc)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR7_OFFS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xffdc)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR7_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR7_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR7_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR7_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR7_RES0_BMSK                              0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR7_RES0_SHFT                                       0

#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR0_ADDR                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xffe0)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR0_PHYS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xffe0)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR0_OFFS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xffe0)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR0_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR0_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR0_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR0_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR0_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR0_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR0_PART_0_BMSK                                  0xff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR0_PART_0_SHFT                                     0

#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR1_ADDR                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xffe4)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR1_PHYS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xffe4)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR1_OFFS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xffe4)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR1_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR1_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR1_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR1_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR1_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR1_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR1_DES_0_BMSK                                   0xf0
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR1_DES_0_SHFT                                      4
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR1_PART_1_BMSK                                   0xf
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR1_PART_1_SHFT                                     0

#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR2_ADDR                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xffe8)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR2_PHYS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xffe8)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR2_OFFS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xffe8)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR2_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR2_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR2_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR2_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR2_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR2_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR2_REVISION_BMSK                                0xf0
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR2_REVISION_SHFT                                   4
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR2_JEDEC_BMSK                                    0x8
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR2_JEDEC_SHFT                                      3
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR2_DES_1_BMSK                                    0x7
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR2_DES_1_SHFT                                      0

#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR3_ADDR                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xffec)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR3_PHYS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xffec)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR3_OFFS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xffec)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR3_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR3_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR3_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR3_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR3_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR3_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR3_REVAND_BMSK                                  0xf0
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR3_REVAND_SHFT                                     4
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR3_CMOD_BMSK                                     0xf
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_PIDR3_CMOD_SHFT                                       0

#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR0_ADDR                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xfff0)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR0_PHYS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xfff0)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR0_OFFS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xfff0)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR0_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR0_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR0_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR0_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR0_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR0_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR0_PRMBL_0_BMSK                                 0xff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR0_PRMBL_0_SHFT                                    0

#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR1_ADDR                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xfff4)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR1_PHYS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xfff4)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR1_OFFS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xfff4)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR1_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR1_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR1_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR1_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR1_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR1_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR1_CLASS_BMSK                                   0xf0
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR1_CLASS_SHFT                                      4
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR1_PRMBL_1_BMSK                                  0xf
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR1_PRMBL_1_SHFT                                    0

#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR2_ADDR                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xfff8)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR2_PHYS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xfff8)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR2_OFFS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xfff8)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR2_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR2_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR2_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR2_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR2_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR2_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR2_PRMBL_2_BMSK                                 0xff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR2_PRMBL_2_SHFT                                    0

#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR3_ADDR                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE      + 0xfffc)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR3_PHYS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_PHYS + 0xfffc)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR3_OFFS                                   (SAILSS_GIC1_ALIAS0_ALIAS0_GICR_CPU0_MM_REG_BASE_OFFS + 0xfffc)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR3_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR3_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR3_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR3_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR3_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR3_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR3_PRMBL_3_BMSK                                 0xff
#define HWIO_SAILSS_GIC1_ALIAS0_GICR_CIDR3_PRMBL_3_SHFT                                    0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM
 *--------------------------------------------------------------------------*/

#define SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE                           (SAILSS_GIC1_KITE_GIC_BASE      + 0x00120000)
#define SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_SIZE                      0x10000
#define SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_USED                      0xfffc
#define SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS                      (SAILSS_GIC1_KITE_GIC_BASE_PHYS + 0x00120000)
#define SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS                      0x00120000

#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_ADDR                                    (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0x0)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_PHYS                                    (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0x0)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_OFFS                                    (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_RMSK                                    0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_OUT(v)            \
                out_dword(HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_ADDR,v)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_ADDR,m,v,HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_IN)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_UWP_BMSK                                0x80000000
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_UWP_SHFT                                        31
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_RES0_BMSK                               0x78000000
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_RES0_SHFT                                       27
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_DPG1S_BMSK                               0x4000000
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_DPG1S_SHFT                                      26
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_DPG1NS_BMSK                              0x2000000
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_DPG1NS_SHFT                                     25
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_DPG0_BMSK                                0x1000000
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_DPG0_SHFT                                       24
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_RES0_1_BMSK                               0xfffff0
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_RES0_1_SHFT                                      4
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_RWP_BMSK                                       0x8
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_RWP_SHFT                                         3
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_RES0_2_BMSK                                    0x6
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_RES0_2_SHFT                                      1
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_ENABLE_LPIS_BMSK                               0x1
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CTLR_ENABLE_LPIS_SHFT                                 0

#define HWIO_SAILSS_GIC1_ALIAS1_GICR_IIDR_ADDR                                    (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0x4)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_IIDR_PHYS                                    (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0x4)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_IIDR_OFFS                                    (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_IIDR_RMSK                                    0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_IIDR_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS1_GICR_IIDR_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_IIDR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS1_GICR_IIDR_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_IIDR_PRODUCTID_BMSK                          0xff000000
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_IIDR_PRODUCTID_SHFT                                  24
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_IIDR_RES0_BMSK                                 0xf00000
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_IIDR_RES0_SHFT                                       20
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_IIDR_VARIANT_BMSK                               0xf0000
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_IIDR_VARIANT_SHFT                                    16
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_IIDR_REVISION_BMSK                               0xf000
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_IIDR_REVISION_SHFT                                   12
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_IIDR_IMPLEMENTER_BMSK                             0xfff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_IIDR_IMPLEMENTER_SHFT                                 0

#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_ADDR                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0x8)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_PHYS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0x8)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_OFFS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_RMSK                                   0xffffffffffffffffuLL
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_IN                    \
                in_qword(HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_INM(m)            \
                in_qword_masked(HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_AFFINITY_VALUE_BMSK                    0xffffffff00000000uLL
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_AFFINITY_VALUE_SHFT                            32
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_RES0_BMSK                              0xfc000000
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_RES0_SHFT                                      26
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_COMMONLPIAFF_BMSK                       0x3000000
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_COMMONLPIAFF_SHFT                              24
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_PROCESSOR_NUMBER_BMSK                    0xffff00
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_PROCESSOR_NUMBER_SHFT                           8
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_RES0_1_BMSK                                  0xc0
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_RES0_1_SHFT                                     6
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_DPGS_BMSK                                    0x20
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_DPGS_SHFT                                       5
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_LAST_BMSK                                    0x10
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_LAST_SHFT                                       4
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_DIRECTLPI_BMSK                                0x8
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_DIRECTLPI_SHFT                                  3
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_RES0_2_BMSK                                   0x4
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_RES0_2_SHFT                                     2
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_VLPIS_BMSK                                    0x2
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_VLPIS_SHFT                                      1
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_PLPIS_BMSK                                    0x1
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_TYPER_PLPIS_SHFT                                      0

#define HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_ADDR                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0x14)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_PHYS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0x14)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_OFFS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_OUT(v)            \
                out_dword(HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_ADDR,v)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_ADDR,m,v,HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_IN)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_IMPLEMENTATION_DEFINED_BMSK            0x80000000
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_IMPLEMENTATION_DEFINED_SHFT                    31
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_RES0_BMSK                              0x7ffffff8
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_RES0_SHFT                                       3
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_CHILDRENASLEEP_BMSK                           0x4
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_CHILDRENASLEEP_SHFT                             2
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_PROCESSORSLEEP_BMSK                           0x2
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_PROCESSORSLEEP_SHFT                             1
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_IMPLEMENTATION_DEFINED_0_BMSK                 0x1
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_WAKER_IMPLEMENTATION_DEFINED_0_SHFT                   0

#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR4_ADDR                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xffd0)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR4_PHYS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xffd0)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR4_OFFS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xffd0)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR4_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR4_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR4_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR4_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR4_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR4_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR4_SIZE_BMSK                                    0xf0
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR4_SIZE_SHFT                                       4
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR4_DES_2_BMSK                                    0xf
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR4_DES_2_SHFT                                      0

#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR5_ADDR                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xffd4)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR5_PHYS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xffd4)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR5_OFFS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xffd4)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR5_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR5_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR5_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR5_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR5_RES0_BMSK                              0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR5_RES0_SHFT                                       0

#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR6_ADDR                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xffd8)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR6_PHYS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xffd8)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR6_OFFS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xffd8)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR6_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR6_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR6_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR6_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR6_RES0_BMSK                              0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR6_RES0_SHFT                                       0

#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR7_ADDR                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xffdc)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR7_PHYS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xffdc)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR7_OFFS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xffdc)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR7_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR7_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR7_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR7_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR7_RES0_BMSK                              0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR7_RES0_SHFT                                       0

#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR0_ADDR                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xffe0)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR0_PHYS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xffe0)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR0_OFFS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xffe0)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR0_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR0_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR0_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR0_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR0_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR0_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR0_PART_0_BMSK                                  0xff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR0_PART_0_SHFT                                     0

#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR1_ADDR                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xffe4)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR1_PHYS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xffe4)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR1_OFFS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xffe4)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR1_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR1_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR1_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR1_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR1_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR1_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR1_DES_0_BMSK                                   0xf0
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR1_DES_0_SHFT                                      4
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR1_PART_1_BMSK                                   0xf
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR1_PART_1_SHFT                                     0

#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR2_ADDR                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xffe8)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR2_PHYS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xffe8)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR2_OFFS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xffe8)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR2_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR2_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR2_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR2_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR2_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR2_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR2_REVISION_BMSK                                0xf0
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR2_REVISION_SHFT                                   4
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR2_JEDEC_BMSK                                    0x8
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR2_JEDEC_SHFT                                      3
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR2_DES_1_BMSK                                    0x7
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR2_DES_1_SHFT                                      0

#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR3_ADDR                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xffec)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR3_PHYS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xffec)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR3_OFFS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xffec)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR3_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR3_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR3_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR3_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR3_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR3_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR3_REVAND_BMSK                                  0xf0
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR3_REVAND_SHFT                                     4
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR3_CMOD_BMSK                                     0xf
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_PIDR3_CMOD_SHFT                                       0

#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR0_ADDR                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xfff0)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR0_PHYS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xfff0)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR0_OFFS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xfff0)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR0_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR0_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR0_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR0_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR0_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR0_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR0_PRMBL_0_BMSK                                 0xff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR0_PRMBL_0_SHFT                                    0

#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR1_ADDR                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xfff4)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR1_PHYS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xfff4)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR1_OFFS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xfff4)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR1_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR1_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR1_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR1_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR1_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR1_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR1_CLASS_BMSK                                   0xf0
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR1_CLASS_SHFT                                      4
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR1_PRMBL_1_BMSK                                  0xf
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR1_PRMBL_1_SHFT                                    0

#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR2_ADDR                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xfff8)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR2_PHYS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xfff8)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR2_OFFS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xfff8)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR2_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR2_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR2_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR2_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR2_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR2_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR2_PRMBL_2_BMSK                                 0xff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR2_PRMBL_2_SHFT                                    0

#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR3_ADDR                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE      + 0xfffc)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR3_PHYS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_PHYS + 0xfffc)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR3_OFFS                                   (SAILSS_GIC1_ALIAS1_ALIAS1_GICR_CPU1_MM_REG_BASE_OFFS + 0xfffc)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR3_RMSK                                   0xffffffff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR3_IN                    \
                in_dword(HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR3_ADDR)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR3_ADDR, m)
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR3_RES0_BMSK                              0xffffff00
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR3_RES0_SHFT                                       8
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR3_PRMBL_3_BMSK                                 0xff
#define HWIO_SAILSS_GIC1_ALIAS1_GICR_CIDR3_PRMBL_3_SHFT                                    0


#endif /* __TEST1_HWIO_H__ */
