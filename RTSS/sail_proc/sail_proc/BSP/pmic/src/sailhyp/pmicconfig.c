/*
===========================================================================
*/
/**
    @file  pmicel2config.c
    @brief contains information about SMPS/LDO config

*/
/*
    ===========================================================================

    Copyright (c) 2021-2023 Qualcomm Technologies, Inc.
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

    $Header:   $
    $DateTime:  $
    $Author:   $

    ===========================================================================
*/

/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/

#include <stdio.h>
#include "pmicconfig.h"


/*=========================================================================================================
**                                        Global variables and constants                                 **
=========================================================================================================*/

#ifdef lemans

const pmicRegulatorConfigType pxpmicLdo[PMIC_MAX_LDO_COUNT] = 
{
    /* AccessAllowed     AlwaysOn       MinPwrMode             SettlingErrorEnabled   SettlingEnabled   MinVoltage MaxVoltage*/
    {(uint32) PMIC_ACCESS_ALLOWED,     (uint32) PMIC_ALWAYS_ON,(uint32) PMIC_NOT_SUPPORTED_MODE, (uint32) PMIC_SETTLING_ERR_EN,   (uint32) PMIC_SETTLING_EN   , 600u,       3300u     }, /* LDO1 */
    {(uint32) PMIC_ACCESS_ALLOWED,     (uint32) PMIC_NONE,     (uint32) PMIC_NOT_SUPPORTED_MODE, (uint32) PMIC_SETTLING_ERR_EN,   (uint32) PMIC_SETTLING_EN   , 600u,       3300u     }, /* LDO2 */
    {(uint32) PMIC_ACCESS_DISALLOWED,  (uint32) PMIC_NONE,     (uint32) PMIC_NOT_SUPPORTED_MODE, (uint32) PMIC_SETTLING_ERR_EN,   (uint32) PMIC_SETTLING_EN   , 600u,       3300u     }, /* LDO3 */
    {(uint32) PMIC_ACCESS_ALLOWED,     (uint32) PMIC_ALWAYS_ON,(uint32) PMIC_NOT_SUPPORTED_MODE, (uint32) PMIC_SETTLING_ERR_EN,   (uint32) PMIC_SETTLING_EN   , 1200u,      3300u     }, /* LDO4 */
};

const pmicRegulatorConfigType pxpmicSmps[PMIC_MAX_SMPS_COUNT] =
{
    /* AccessAllowed     AlwaysOn       MinPwrMode    SettlingErrorEnabled   SettlingEnabled   MinVoltage MaxVoltage */
    {(uint32) PMIC_ACCESS_DISALLOWED, (uint32) PMIC_NONE,     (uint32) PMIC_AUTO_MODE, (uint32) PMIC_SETTLING_ERR_EN,   (uint32) PMIC_SETTLING_EN   , 300u,          3340u  },/* BUCK1 */
    {(uint32) PMIC_ACCESS_DISALLOWED, (uint32) PMIC_NONE,     (uint32) PMIC_AUTO_MODE, (uint32) PMIC_SETTLING_ERR_EN,   (uint32) PMIC_SETTLING_EN   , 300u,          3340u  },/* BUCK2 */
    {(uint32) PMIC_ACCESS_ALLOWED,    (uint32) PMIC_NONE,     (uint32) PMIC_AUTO_MODE, (uint32) PMIC_SETTLING_ERR_EN,   (uint32) PMIC_SETTLING_EN   , 300u,          3340u  },/* BUCK3 SAIL_CX */ 
    {(uint32) PMIC_ACCESS_ALLOWED,    (uint32) PMIC_ALWAYS_ON,(uint32) PMIC_AUTO_MODE, (uint32) PMIC_SETTLING_ERR_EN,   (uint32) PMIC_SETTLING_EN   , 300u,          3340u  },/* BUCK4 SAIL_MX */
    {(uint32) PMIC_ACCESS_ALLOWED,    (uint32) PMIC_ALWAYS_ON,(uint32) PMIC_AUTO_MODE, (uint32) PMIC_SETTLING_ERR_EN,   (uint32) PMIC_SETTLING_EN   , 300u,          3340u  },/* BUCK5 SAIL_PX3/ECC */
};

#endif

#ifdef monaco

const pmicRegulatorConfigType pxpmicLdo[PMIC_MAX_LDO_COUNT] = 
{
    /* AccessAllowed     AlwaysOn       MinPwrMode             SettlingErrorEnabled   SettlingEnabled   MinVoltage MaxVoltage*/
    {(uint32) PMIC_ACCESS_ALLOWED,     (uint32) PMIC_ALWAYS_ON,(uint32) PMIC_NOT_SUPPORTED_MODE, (uint32) PMIC_SETTLING_ERR_EN,  (uint32)  PMIC_SETTLING_EN   , 600u,       3300u     }, /* LDO1 */
    {(uint32) PMIC_ACCESS_ALLOWED,     (uint32) PMIC_NONE,     (uint32) PMIC_NOT_SUPPORTED_MODE, (uint32) PMIC_SETTLING_ERR_EN,  (uint32)  PMIC_SETTLING_EN   , 600u,       3300u     }, /* LDO2 */
    {(uint32) PMIC_ACCESS_DISALLOWED,  (uint32) PMIC_NONE,     (uint32) PMIC_NOT_SUPPORTED_MODE, (uint32) PMIC_SETTLING_ERR_EN,  (uint32)  PMIC_SETTLING_EN   , 600u,       3300u     }, /* LDO3 */
    {(uint32) PMIC_ACCESS_ALLOWED,     (uint32) PMIC_ALWAYS_ON,(uint32) PMIC_NOT_SUPPORTED_MODE, (uint32) PMIC_SETTLING_ERR_EN,  (uint32)  PMIC_SETTLING_EN   , 1200u,      3300u     }, /* LDO4 */
};

const pmicRegulatorConfigType pxpmicSmps[PMIC_MAX_SMPS_COUNT] =
{
    /* AccessAllowed     AlwaysOn               MinPwrMode    SettlingErrorEnabled   SettlingEnabled   MinVoltage MaxVoltage */
    {(uint32) PMIC_ACCESS_DISALLOWED,  (uint32) PMIC_NONE,         (uint32) PMIC_AUTO_MODE, (uint32) PMIC_SETTLING_ERR_EN,  (uint32) PMIC_SETTLING_EN   , 300u,  3340u  },/* BUCK1 */
    {(uint32) PMIC_ACCESS_DISALLOWED,  (uint32) PMIC_ALWAYS_ON,    (uint32) PMIC_AUTO_MODE, (uint32) PMIC_SETTLING_ERR_EN,  (uint32) PMIC_SETTLING_EN   , 300u,  3340u  },/* BUCK2 */
    {(uint32) PMIC_ACCESS_ALLOWED,     (uint32) PMIC_ALWAYS_ON,    (uint32) PMIC_AUTO_MODE, (uint32) PMIC_SETTLING_ERR_EN,  (uint32) PMIC_SETTLING_EN   , 300u,  3340u  },/* BUCK3 SAIL_CX */ 
    {(uint32) PMIC_ACCESS_ALLOWED,     (uint32) PMIC_ALWAYS_ON,    (uint32) PMIC_AUTO_MODE, (uint32) PMIC_SETTLING_ERR_EN,  (uint32) PMIC_SETTLING_EN   , 300u,  3340u  },/* BUCK4 SAIL_MX */
    {(uint32) PMIC_ACCESS_ALLOWED,     (uint32) PMIC_ALWAYS_ON,    (uint32) PMIC_AUTO_MODE, (uint32) PMIC_SETTLING_ERR_EN,  (uint32) PMIC_SETTLING_EN   , 300u,  3340u  },/* BUCK5 SAIL_PX3/ECC */
};

#endif

/* CPR_STRIPPING_CHANGES */
const uint16 pscxVoltagePlan[PMIC_CPR_VOLTAGE_LEVEL_COUNT] =
{
    [PMIC_CPR_VOLTAGE_LEVEL_RETENTION] = 320u,
    [PMIC_CPR_VOLTAGE_LEVEL_RETENTION_BIN1] = 360u,
    [PMIC_CPR_VOLTAGE_LEVEL_SVS_L1]   = 795u,
    [PMIC_CPR_VOLTAGE_LEVEL_NOMINAL]  = 820u,
    [PMIC_CPR_VOLTAGE_LEVEL_TURBO]    = 890u,
    [PMIC_CPR_VOLTAGE_LEVEL_TURBO_L1] = 965u, 
};

/* CPR_STRIPPING_CHANGES */
const uint16 psmxVoltagePlan[PMIC_CPR_VOLTAGE_LEVEL_COUNT] =
{
    [PMIC_CPR_VOLTAGE_LEVEL_RETENTION] = 560u,
    [PMIC_CPR_VOLTAGE_LEVEL_RETENTION_BIN1] = 560u,
    [PMIC_CPR_VOLTAGE_LEVEL_SVS_L1]   = 795u,
    [PMIC_CPR_VOLTAGE_LEVEL_NOMINAL]  = 820u,
    [PMIC_CPR_VOLTAGE_LEVEL_TURBO]    = 890u,
    [PMIC_CPR_VOLTAGE_LEVEL_TURBO_L1] = 890u,
};

uint8 ucpmicLdoCount = (uint8)(sizeof(pxpmicLdo)/sizeof(pmicRegulatorConfigType));


uint8 ucpmicSmpsCount = (uint8)(sizeof(pxpmicSmps)/sizeof(pmicRegulatorConfigType));

 
/**********************************************************************************************************
**                                  End of file pmicel2config.c                                          **
**********************************************************************************************************/
