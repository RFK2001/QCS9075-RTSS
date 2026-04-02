#ifndef ISD_CFG_H_
#define ISD_CFG_H_

/**
 * @file isd_cfg.h
 * @brief
 * Header file to store static configurations of ISD driver of sail
 *
 *        Copyright (c) Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/

#include "isd.h"

#ifdef TEST_SRC_ENABLED
#include "tests.h"
extern void pIsdCallback( const isdStatesType_e eState );
#endif
/*=========================================================================
      Macros
==========================================================================*/
#define ISD_MAX_SUBSCRIBERS                     0x1U

/*
*     BIT 0       : MD_PS_HOLD                   : 1
*     BIT 1       : MD_PMIC_FAULT_N_EN           : 1
*     BIT 2       : SAIL_RESIN_N_EN              : 0 
*     BIT 3       : VS_FUSA_ERR0_EN              : 0
*     BIT 4       : VS_FUSA_ERR1_EN              : 0
*     BIT 5       : TSENSE_PS_HOLD_ARES0_EN      : 0
*     BIT 6       : TSENSE_PS_HOLD_ARES1_EN      : 0
*     BIT 7       : SAIL_R52_WDOG_BITE_EN        : 0
*     BIT 8       : SAIL_SEQ_WDOG_BITE_EN        : 0
*     BIT 9       : SAIL_ERROR_EN                : 0
*     BIT 14-10   : SPARE_FATAL_EN               : 0011
*     BIT 19-15   : SPARE_FATAL_N_EN             : 0000
*     BIT 24-20   : SPARE_EDGE_FATAL_EN          : 0000
*     BIT 29-25   : SPARE_EDGE_FATAL_N_EN        : 0000
*     BIT 31-30   : SPARE_FATAL_N_EN             : 00
*/
#define ISD_FATAL_ERR_ISOLATION_EN_MASK         0x00000C03       

/*
*     BIT 0       : MD_PS_HOLD                   : 0
*     BIT 1       : MD_PMIC_FAULT_N_EN           : 0
*     BIT 2       : SAIL_RESIN_N_EN              : 1 
*     BIT 3       : VS_FUSA_ERR0_EN              : 1
*     BIT 4       : VS_FUSA_ERR1_EN              : 1
*     BIT 5       : TSENSE_PS_HOLD_ARES0_EN      : 1
*     BIT 6       : TSENSE_PS_HOLD_ARES1_EN      : 1
*     BIT 7       : SAIL_R52_WDOG_BITE_EN        : 1
*     BIT 8       : SAIL_SEQ_WDOG_BITE_EN        : 1
*     BIT 9       : SAIL_ERROR_EN                : 0
*     BIT 14-10   : SPARE_FATAL_EN               : 0000
*     BIT 19-15   : SPARE_FATAL_N_EN             : 0000
*     BIT 24-20   : SPARE_EDGE_FATAL_EN          : 0000
*     BIT 29-25   : SPARE_EDGE_FATAL_N_EN        : 0000
*     BIT 31-30   : SPARE_FATAL_N_EN             : 00
*/
#define ISD_FATAL_ERR_PS_HOLD_EN_MASK           0x000001FC      

/* Enable this macro to ENABLE SAIL Island mode for applicable SW reset use case */
//#define ISLAND_ENABLE

#endif