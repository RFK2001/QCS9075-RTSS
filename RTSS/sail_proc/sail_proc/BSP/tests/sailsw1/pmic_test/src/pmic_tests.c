
/**********************************************************************************************************
    Copyright (c) 2021,2023 Qualcomm Technologies, Inc.
    All Rights Reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.

    Export of this technology or software is regulated by the U.S. Government.
    Diversion contrary to U.S. law prohibited.

    All ideas, ucdata and information contained in or disclosed by
    this document are confidential and proprietary information of
    Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
    By accepting this material the recipient agrees that this material
    and the information contained therein are held in confidence and in
    trust and will not be used, copied, reproduced in whole or in part,
    nor its contents revealed in any manner to others without the express
    written permission of Qualcomm Technologies, Inc.
**********************************************************************************************************/

/*=========================================================================================================
    File Name          : pmictest.c
    Component Name     : pmic
    Description        : this file contains all the unit test cases
    $Header: //components/dev/bsp.sail/1.0/asuthar.bsp.sail.1.0.movePmicTestToEl1/tests/pmic_tests.c#1 $
    $DateTime: 2022/07/07 02:26:54 $
    $Author: asuthar $
=========================================================================================================*/

/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/


#include <stdio.h>
#include "pmichwio.h"
#include "pmici2c.h"
#include "pmiccommon.h"
#include "pmicapi.h"
#include "pmicconfig.h"
#include "pmicinternal.h"
#include "debug_log.h"
#include "tests.h"
#include "syscall_pub.h"
#include "syscall_hvc.h"
#include "FreeRTOSOsal.h"
#include "common_functions.h"
#include "spinor_el1_api.h"
//#include "wdt_safertos.h"
#include "err_fatal.h"
#include "syscall_svc.h"
#include "syscall.h"
#include "chipinfo.h"
#include "chipinfodefs.h"
#include "spinor_cm_defs.h"
//#include "monitor.h"
#include "logcode.h"
//#include "pmicSafeRtosinternal.h"
#include "i2c.h"
//#include "bootstatus_com.h"

#if __has_include("external_build_flag.h")
    #include "external_build_flag.h"
#endif


/*=========================================================================================================
**                                        Local defines and macros                                       **
=========================================================================================================*/

#if lemans
    #define pmicTotalTestCase                          65u
    #define NUMBER_OF_STATIC_EEPROM_REGISTERS          8U
#else
    #define pmicTotalTestCase                          66u
    #define NUMBER_OF_STATIC_EEPROM_REGISTERS          3u
#endif

#define MAX_SIZE                                   7u
#define NUMBER_OF_PFSM_EEPROM_REGISTERS            32U
#define EEPROMBUSY                                 0x02U
#define MAX_NVM_VERSION_AVAILABLE                  0x2U

#define CMD_PMIC_UPDATE_TO_1                       0x6u
#define CMD_PMIC_UPDATE_TO_2                       0x7u


#define COMMON_MAJOR_VERSION         1
#define COMMON_MINOR_VERSION         2
#define COMMON_SUB_MINOR_VERSION     1

#define THESHOLD_VIP_FIRMWARE_VERSION (COMMON_MAJOR_VERSION*100u+COMMON_MINOR_VERSION*10u+COMMON_SUB_MINOR_VERSION)



/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/


typedef struct
{
    uint8    address;
    uint64   payload;
    uint64   mask;
} EEPROM_INTERFACE;


typedef enum
{
    EXT_WDG_NO_ACTION = 0,
    EXT_WDG_PET,
    EXT_WDG_DISABLE, 
    EXT_WDG_ENABLE,
} eExtWdgActionType;

typedef struct
{
    eExtWdgActionType ExtWdgAction;
}PMIC_EXTWDG_QueueMsgType;



TEST_FUNC TESTerrorType_e xTestExtWdgWrapper(void);
/*=========================================================================================================
 @Service name        prvPmicCommReadByte
 @Description         This function is used make trap to read PMIC Addr using I2C bus
 @param[in]           <xpageId> <PAGE_ID_0 , PAGE_ID_1 ... PAGE_ID_4>
 @param[in]           <uladdr> <Address which user wants to read>
 @param[out]          <pcdata> <return value present on uladdr of PMIC>
 @param[in, out]      <Ptr>
 @return              <pmicErrFlagType_e> <Return xErrFlag type based on status of transaction on I2C bus>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

TEST_FUNC pmicErrFlagType_e prvPmicCommReadByte(pmicPageId_e xpageId, uint32 uladdr , uint8 *pcdata)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32_t hvcId     = PMIC_COMM_READ;
    uint32_t paramId   = PMIC_COMM_READ_PARM_ID;
    uint32_t arg1      = (uint32_t)xpageId;
    uint32_t arg2      = (uint32_t)uladdr;
    uint32_t arg3      = (uint32_t)pcdata;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    xErrFlag = paramId;
    
    return xErrFlag;

}

/*=========================================================================================================
 @Service name        prvPmicCommWriteByte
 @Description         prvPmicCommWriteByte is used to write on PMIC Addr using I2C bus
 @param[in]           <xpageId> <PAGE_ID_0 , PAGE_ID_1 ... PAGE_ID_4>
 @param[in]           <uladdr> <Address which user wants to read>
 @param[in]           <pcdata> <value need to be written on uladdr of PMIC>
 @param[in, out]      <Ptr>
 @return              <xErrFlag> <Return xErrFlagtype based on status of transaction on I2C bus>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>
 @Reentrancy          <NO>
 @Note                <None>
=========================================================================================================*/

TEST_FUNC pmicErrFlagType_e prvPmicCommWriteByte(pmicPageId_e xpageId,uint32 uladdr ,uint8 ucdata)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32_t hvcId     = PMIC_COMM_WRITE;
    uint32_t paramId   = PMIC_COMM_WRITE_PARM_ID;
    uint32_t arg1      = (uint32_t)xpageId;
    uint32_t arg2      = (uint32_t)uladdr;
    uint32_t arg3      = (uint32_t)ucdata;
    uint32_t arg4      = 0;
    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
        /* TODO: Implement error handler or log */
        while(1);
    }

    xErrFlag = paramId;
    
    return xErrFlag;  
}

#ifdef SAILSW3
/*=========================================================================================================
**                                        Global variables and constants                                 **
=========================================================================================================*/

extern xQueueHandle xPmicExtWdgQueueHandle;

extern pmicDebugType_e ucPmicDebugMode;

TEST_DATA uint8 ucnumOFTestCases = 0x0u;

TEST_DATA uint16 uspmicLdo[MAX_SIZE] = 
{
    1800U,1750U,1700U,1750U,1800U,1850U,1900U
};


TEST_DATA uint16 uspmicSmps[MAX_SIZE] = 
{
    1700U,
    1720U,
    1740U,
    1760U,
    1780U,
    1800U,
    1820U
};



TEST_DATA uint16 uspmicSmpsVolt[MAX_SIZE-1] = 
{
    1003u,
    1200u,
    1145u,
    869u,
    979u,
    999u
};

TEST_DATA uint16 uspmicSmpsVoltRead[MAX_SIZE-1] =
{
    1005u,
    1200u,
    1150u,
    870u,
    980u,
    1000u
};

/* CPR_STRIPPING_CHANGES */
TEST_DATA char const *pxStringConversion[PMIC_CPR_VOLTAGE_LEVEL_COUNT] =
{
    [PMIC_CPR_VOLTAGE_LEVEL_RETENTION] = "retention",
    [PMIC_CPR_VOLTAGE_LEVEL_RETENTION_BIN1] = "retention_bin1",
    [PMIC_CPR_VOLTAGE_LEVEL_SVS_L1] = "svs_l1",
    [PMIC_CPR_VOLTAGE_LEVEL_NOMINAL] = "nominal",
    [PMIC_CPR_VOLTAGE_LEVEL_TURBO] = "turbo",
    [PMIC_CPR_VOLTAGE_LEVEL_TURBO_L1] = "turbo_l1"
};


TEST_DATA char const *pxCoreRail[PMIC_INVALID_RAIL] =
{
    [PMIC_CX_RAIL] = "cx",
    [PMIC_MX_RAIL] = "mx"
};

TEST_DATA char const *pxCrashResetString[PMIC_CRASH_PASS_INVALID+1] = 
{
    [PMIC_CRASH_PASS_0] = "Pass0",
    [PMIC_CRASH_PASS_1] = "Pass1",
    [PMIC_CRASH_PASS_2] = "Pass2",
    [PMIC_POFF_PON] = "poff_pon",
    [PMIC_POFF_PON_SKIP_KPD] = "poff_pon_skip_kpd",
    [PMIC_WARM_RESET] = "warm_reset",
    [PMIC_POFF] = "poff",
    [PMIC_CRASH_PASS_INVALID] = "Invalid"
};

#if lemans
TEST_BSS const pmicRegulatorConfigType pxpmicLdoTest[] = 
{
    /* AccessAllowed     AlwaysOn       MinPwrMode             SettlingErrorEnabled   SettlingEnabled   MinVoltage MaxVoltage*/
    {PMIC_ACCESS_ALLOWED,     PMIC_ALWAYS_ON,PMIC_NOT_SUPPORTED_MODE, PMIC_SETTLING_ERR_EN,   PMIC_SETTLING_EN   , 600,       3300     }, /* LDO1 */
    {PMIC_ACCESS_ALLOWED,     PMIC_ALWAYS_ON,PMIC_NOT_SUPPORTED_MODE, PMIC_SETTLING_ERR_EN,   PMIC_SETTLING_EN   , 600,       3300     }, /* LDO2 */
    {PMIC_ACCESS_DISALLOWED,  PMIC_NONE,    PMIC_NOT_SUPPORTED_MODE, PMIC_SETTLING_ERR_EN,   PMIC_SETTLING_EN   , 600,       3300     }, /* LDO3 */
    {PMIC_ACCESS_ALLOWED,     PMIC_ALWAYS_ON,PMIC_NOT_SUPPORTED_MODE, PMIC_SETTLING_ERR_EN,   PMIC_SETTLING_EN   , 1200,      3300     }, /* LDO4 */
};

TEST_BSS const pmicRegulatorConfigType pxpmicSmpsTest[] =
{
    /* AccessAllowed     AlwaysOn       MinPwrMode    SettlingErrorEnabled   SettlingEnabled   MinVoltage MaxVoltage */
    {PMIC_ACCESS_DISALLOWED,  PMIC_NONE,    PMIC_AUTO_MODE, PMIC_SETTLING_ERR_EN,   PMIC_SETTLING_EN   , 300,          3340  },/* BUCK1 */
    {PMIC_ACCESS_DISALLOWED,  PMIC_NONE,    PMIC_AUTO_MODE, PMIC_SETTLING_ERR_EN,   PMIC_SETTLING_EN   , 300,          3340  },/* BUCK2 */
    {PMIC_ACCESS_ALLOWED,     PMIC_NONE,    PMIC_AUTO_MODE, PMIC_SETTLING_ERR_EN,   PMIC_SETTLING_EN   , 300,          3340  },/* BUCK3 SAIL_CX */ 
    {PMIC_ACCESS_ALLOWED,     PMIC_ALWAYS_ON,PMIC_AUTO_MODE, PMIC_SETTLING_ERR_EN,   PMIC_SETTLING_EN   , 300,          3340  },/* BUCK4 SAIL_MX */
    {PMIC_ACCESS_ALLOWED,     PMIC_ALWAYS_ON,PMIC_AUTO_MODE, PMIC_SETTLING_ERR_EN,   PMIC_SETTLING_EN   , 300,          3340  },/* BUCK5 SAIL_PX3/ECC */
};

#else
TEST_BSS const pmicRegulatorConfigType pxpmicLdoTest[PMIC_MAX_LDO_COUNT] = 
{
    /* AccessAllowed     AlwaysOn       MinPwrMode             SettlingErrorEnabled   SettlingEnabled   MinVoltage MaxVoltage*/
    {(uint32) PMIC_ACCESS_ALLOWED,     (uint32) PMIC_ALWAYS_ON,(uint32) PMIC_NOT_SUPPORTED_MODE, (uint32) PMIC_SETTLING_ERR_EN,  (uint32)  PMIC_SETTLING_EN   , 600u,       3300u     }, /* LDO1 */
    {(uint32) PMIC_ACCESS_ALLOWED,     (uint32) PMIC_NONE,     (uint32) PMIC_NOT_SUPPORTED_MODE, (uint32) PMIC_SETTLING_ERR_EN,  (uint32)  PMIC_SETTLING_EN   , 600u,       3300u     }, /* LDO2 */
    {(uint32) PMIC_ACCESS_DISALLOWED,  (uint32) PMIC_NONE,     (uint32) PMIC_NOT_SUPPORTED_MODE, (uint32) PMIC_SETTLING_ERR_EN,  (uint32)  PMIC_SETTLING_EN   , 600u,       3300u     }, /* LDO3 */
    {(uint32) PMIC_ACCESS_ALLOWED,     (uint32) PMIC_ALWAYS_ON,(uint32) PMIC_NOT_SUPPORTED_MODE, (uint32) PMIC_SETTLING_ERR_EN,  (uint32)  PMIC_SETTLING_EN   , 1200u,      3300u     }, /* LDO4 */
};

TEST_BSS const pmicRegulatorConfigType pxpmicSmpsTest[PMIC_MAX_SMPS_COUNT] =
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
TEST_BSS const uint16 pscxVoltagePlanTest[] =
{
    [PMIC_CPR_VOLTAGE_LEVEL_RETENTION] = 320,
    [PMIC_CPR_VOLTAGE_LEVEL_RETENTION_BIN1] = 360,
    [PMIC_CPR_VOLTAGE_LEVEL_SVS_L1]   = 795,
    [PMIC_CPR_VOLTAGE_LEVEL_NOMINAL]  = 820,
    [PMIC_CPR_VOLTAGE_LEVEL_TURBO]    = 890,
    [PMIC_CPR_VOLTAGE_LEVEL_TURBO_L1] = 965, 
};

/* CPR_STRIPPING_CHANGES */
TEST_BSS const uint16 psmxVoltagePlanTest[] =
{
    [PMIC_CPR_VOLTAGE_LEVEL_RETENTION] = 560,
    [PMIC_CPR_VOLTAGE_LEVEL_RETENTION_BIN1] = 560,
    [PMIC_CPR_VOLTAGE_LEVEL_SVS_L1]   = 795,
    [PMIC_CPR_VOLTAGE_LEVEL_NOMINAL]  = 820,
    [PMIC_CPR_VOLTAGE_LEVEL_TURBO]    = 890,
    [PMIC_CPR_VOLTAGE_LEVEL_TURBO_L1] = 890,
};

TEST_DATA uint8 ucpmicLdoCountTest = sizeof(pxpmicLdoTest)/sizeof(pmicRegulatorConfigType);

TEST_DATA uint8 ucpmicSmpsCountTest = sizeof(pxpmicSmpsTest)/sizeof(pmicRegulatorConfigType);

#ifdef monaco

TEST_BSS const EEPROM_INTERFACE staticBANK0EEPROM[MAX_NVM_VERSION_AVAILABLE][NUMBER_OF_STATIC_EEPROM_REGISTERS] =
{
    {
        {0x38, 0x0000000000000003, 0x00000000000000FF},
        {0x3C, 0x59b5369200000000, 0xFFFFFFFF00000000},  
        {0x3E, 0x5f2c6021229e0000, 0xFFFFFFFFFFFF0000}
    },
    {
        {0x38, 0x0000000000000006, 0x00000000000000FF},
        {0x3C, 0x6b3c041b00000000, 0xFFFFFFFF00000000},  
        {0x3E, 0x56cba19c75870000, 0xFFFFFFFFFFFF0000}
    }
};

TEST_BSS const EEPROM_INTERFACE pfsmBANK1EEPROM[MAX_NVM_VERSION_AVAILABLE][NUMBER_OF_PFSM_EEPROM_REGISTERS] =
{
    {
        {0x00, 0x9072821a9072800a, 0xFFFFFFFFFFFFFFFF},
        {0x02, 0x9079be3a9070fe2a, 0xFFFFFFFFFFFFFFFF},
        {0x04, 0x5179b45a51790e4a, 0xFFFFFFFFFFFFFFFF},
        {0x06, 0x4659b27a4659ae6a, 0xFFFFFFFFFFFFFFFF},
        {0x08, 0x1c20989a3ef9328a, 0xFFFFFFFFFFFFFFFF},
        {0x0A, 0x7f807cbaa7a942aa, 0xFFFFFFFFFFFFFFFF},
        {0x0C, 0x7f80feda1c20feca, 0xFFFFFFFFFFFFFFFF},
        {0x0E, 0xb0e088fab0e940ea, 0xFFFFFFFFFFFFFFFF},
        {0x10, 0xaea07d1ab0e0ff0a, 0xFFFFFFFFFFFFFFFF},
        {0x12, 0x0045453aafc9472a, 0xFFFFFFFFFFFFFFFF},
        {0x14, 0x003c895a1c20094a, 0xFFFFFFFFFFFFFFFF},
        {0x16, 0xbc89b17ab669316a, 0xFFFFFFFFFFFFFFFF},
        {0x18, 0xbe89379abc80918a, 0xFFFFFFFFFFFFFFFF},
        {0x1A, 0xfeffff4bbf29b7aa, 0xFFFFFFFFFFFFFFFF},
        {0x1C, 0x78004e1365dfc3dc, 0xFFFFFFFFFFFFFFFF},
        {0x1E, 0x40c4b1331284a2d2, 0xFFFFFFFFFFFFFFFF},
        {0x20, 0x7a6134ec4d133130, 0xFFFFFFFFFFFFFFFF},
        {0x22, 0x10811b8447409a20, 0xFFFFFFFFFFFFFFFF},
        {0x24, 0xb04c2822c52dc16f, 0xFFFFFFFFFFFFFFFF},
        {0x26, 0x35db04c2020c539d, 0xFFFFFFFFFFFFFFFF},
        {0x28, 0xcc53ddb04c301ec5, 0xFFFFFFFFFFFFFFFF},
        {0x2A, 0xf75ac54ddb844801, 0xFFFFFFFFFFFFFFFF},
        {0x2C, 0x4b1001284a212784, 0xFFFFFFFFFFFFFFFF},
        {0x2E, 0x780b1344a0133800, 0xFFFFFFFFFFFFFFFF},
        {0x30, 0x03092181d4945472, 0xFFFFFFFFFFFFFFFF},
        {0x32, 0xd4571022c4cfb6fc, 0xFFFFFFFFFFFFFFFF},
        {0x34, 0xe442c8b12fd4a72b, 0xFFFFFFFFFFFFFFFF},
        {0x36, 0x404cc133dd068230, 0xFFFFFFFFFFFFFFFF},
        {0x38, 0x373ac4b682d00324, 0xFFFFFFFFFFFFFFFF},
        {0x3A, 0x3f7c22cae1003f78, 0xFFFFFFFFFFFFFFFF},
        {0x3C, 0xfffffbbc24cae040, 0xFFFFFFFFFFFFFFFF},
        {0x3E, 0xc0f74833702c8b1f, 0xFFFFFFFFFFFFFFFF}
    },
    {
        {0x00, 0x9062821a9062800a, 0xFFFFFFFFFFFFFFFF},
        {0x02, 0x9069be3a9060fe2a, 0xFFFFFFFFFFFFFFFF},
        {0x04, 0x5219b45a52190e4a, 0xFFFFFFFFFFFFFFFF},
        {0x06, 0x46f9b27a46f9ae6a, 0xFFFFFFFFFFFFFFFF},
        {0x08, 0x1ad0989a3f99328a, 0xFFFFFFFFFFFFFFFF},
        {0x0A, 0xb19930baa51942aa, 0xFFFFFFFFFFFFFFFF},
        {0x0C, 0xb7b090dab7b9b0ca, 0xFFFFFFFFFFFFFFFF},
        {0x0E, 0xba59b6fab9b936ea, 0xFFFFFFFFFFFFFFFF},
        {0x10, 0x1ad0ff1a80207d0a, 0xFFFFFFFFFFFFFFFF},
        {0x12, 0xac19413a8020ff2a, 0xFFFFFFFFFFFFFFFF},
        {0x14, 0xac10ff5aac10894a, 0xFFFFFFFFFFFFFFFF},
        {0x16, 0x1ad0097a0045456a, 0xFFFFFFFFFFFFFFFF},
        {0x18, 0xd2c50cb1003c898a, 0xFFFFFFFFFFFFFFFF},
        {0x1A, 0xdf32d830db3dfc1f, 0xFFFFFFFFFFFFFFFF},
        {0x1C, 0xe1365dfc3de4101b, 0xFFFFFFFFFFFFFFFF},
        {0x1E, 0x1331284a2d278004, 0xFFFFFFFFFFFFFFFF},
        {0x20, 0x4ec4d13313040c4b, 0xFFFFFFFFFFFFFFFF},
        {0x22, 0xb8447409a207a613, 0xFFFFFFFFFFFFFFFF},
        {0x24, 0x822c52dc16f10811, 0xFFFFFFFFFFFFFFFF},
        {0x26, 0x4c2020c539db04c2, 0xFFFFFFFFFFFFFFFF},
        {0x28, 0xdb04c301ec535db0, 0xFFFFFFFFFFFFFFFF},
        {0x2A, 0x54ddb844801cc53d, 0xFFFFFFFFFFFFFFFF},
        {0x2C, 0x1284a212784f75ac, 0xFFFFFFFFFFFFFFFF},
        {0x2E, 0x344a01338004b100, 0xFFFFFFFFFFFFFFFF},
        {0x30, 0x181d4945472780b1, 0xFFFFFFFFFFFFFFFF},
        {0x32, 0x022c4cfb6fc03092, 0xFFFFFFFFFFFFFFFF},
        {0x34, 0x8b12fd4a72bd4571, 0xFFFFFFFFFFFFFFFF},
        {0x36, 0x133dd068230e442c, 0xFFFFFFFFFFFFFFFF},
        {0x38, 0x4b682d00324404cc, 0xFFFFFFFFFFFFFFFF},
        {0x3A, 0x2cae1003f7fa702c, 0xFFFFFFFFFFFFFFFF},
        {0x3C, 0xbbc24cae0403f7c2, 0xFFFFFFFFFFFFFFFF},
        {0x3E, 0x833702c8b1ffffff, 0xFFFFFFFFFFFFFFFF}
    }
};

TEST_BSS const EEPROM_INTERFACE pfsmBANK2EEPROM[MAX_NVM_VERSION_AVAILABLE][NUMBER_OF_PFSM_EEPROM_REGISTERS] =
{
    {
        {0x00, 0x00fdcaa023820199, 0xFFFFFFFFFFFFFFFF},
        {0x02, 0x02ba1e3738802002, 0xFFFFFFFFFFFFFFFF},
        {0x04, 0xdcec12c8fb4060aa, 0xFFFFFFFFFFFFFFFF},
        {0x06, 0x4fb424c2b8c33720, 0xFFFFFFFFFFFFFFFF},
        {0x08, 0x904e24978d030e44, 0xFFFFFFFFFFFFFFFF},
        {0x0A, 0x127813dd1c64d717, 0xFFFFFFFFFFFFFFFF},
        {0x0C, 0x2c25011ccfb48c39, 0xFFFFFFFFFFFFFFFF},
        {0x0E, 0x32b8200fde0dceb1, 0xFFFFFFFFFFFFFFFF},
        {0x10, 0x555373fffffe2f0d, 0xFFFFFFFFFFFFFFFF},
        {0x12, 0x132886e0a2198288, 0xFFFFFFFFFFFFFFFF},
        {0x14, 0x08ef1004685f4a21, 0xFFFFFFFFFFFFFFFF},
        {0x16, 0xc960028851534520, 0xFFFFFFFFFFFFFFFF},
        {0x18, 0x81dcce68d064cd60, 0xFFFFFFFFFFFFFFFF},
        {0x1A, 0x08c6c80e13406870, 0xFFFFFFFFFFFFFFFF},
        {0x1C, 0x1613b0484ec14138, 0xFFFFFFFFFFFFFFFF},
        {0x1E, 0xdd200cae380986c8, 0xFFFFFFFFFFFFFFFF},
        {0x20, 0x81d33dd33ed27813, 0xFFFFFFFFFFFFFFFF},
        {0x22, 0x3dd3806978803f71, 0xFFFFFFFFFFFFFFFF},
        {0x24, 0x251406a70ca62781, 0xFFFFFFFFFFFFFFFF},
        {0x26, 0x0081458064d70041, 0xFFFFFFFFFFFFFFFF},
        {0x28, 0x33ed202cae7864e7, 0xFFFFFFFFFFFFFFFF},
        {0x2A, 0x0fdc10c91181d058, 0xFFFFFFFFFFFFFFFF},
        {0x2C, 0xdc100fdc101a9d30, 0xFFFFFFFFFFFFFFFF},
        {0x2E, 0x104949e04f74901a, 0xFFFFFFFFFFFFFFFF},
        {0x30, 0x39c03051511935c0, 0xFFFFFFFFFFFFFFFF},
        {0x32, 0xfdc60748032b8f19, 0xFFFFFFFFFFFFFFFF},
        {0x34, 0x7fffdfd2c3318700, 0xFFFFFFFFFFFFFFFF},
        {0x36, 0x80ca124028790328, 0xFFFFFFFFFFFFFFFF},
        {0x38, 0x48600fdfffbffd2d, 0xFFFFFFFFFFFFFFFF},
        {0x3A, 0xf515c408b1bf00c2, 0xFFFFFFFFFFFFFFFF},
        {0x3C, 0xe2f08b2b8200fdc1, 0xFFFFFFFFFFFFFFFF},
        {0x3E, 0x081dc0b22c7fffff, 0xFFFFFFFFFFFFFFFF}
    },
    {
        {0x00, 0xaa023820199c0f74, 0xFFFFFFFFFFFFFFFF},
        {0x02, 0xe373880200200fdc, 0xFFFFFFFFFFFFFFFF},
        {0x04, 0x2c8fb4060aa02ba1, 0xFFFFFFFFFFFFFFFF},
        {0x06, 0x4c2b8c3373e9c0c1, 0xFFFFFFFFFFFFFFFF},
        {0x08, 0x4978d030e444fb42, 0xFFFFFFFFFFFFFFFF},
        {0x0A, 0x3dd1c64d717904e2, 0xFFFFFFFFFFFFFFFF},
        {0x0C, 0x11ccfb48c3912781, 0xFFFFFFFFFFFFFFFF},
        {0x0E, 0x00fdfe9c0b12c250, 0xFFFFFFFFFFFFFFFF},
        {0x10, 0x3fffffe2f0d32b82, 0xFFFFFFFFFFFFFFFF},
        {0x12, 0x6e0a219828855537, 0xFFFFFFFFFFFFFFFF},
        {0x14, 0x004685f4a2113288, 0xFFFFFFFFFFFFFFFF},
        {0x16, 0x2885153452008ef1, 0xFFFFFFFFFFFFFFFF},
        {0x18, 0xe68d064cd60c9600, 0xFFFFFFFFFFFFFFFF},
        {0x1A, 0x80e1340687081dcc, 0xFFFFFFFFFFFFFFFF},
        {0x1C, 0x0484ec1413808c6c, 0xFFFFFFFFFFFFFFFF},
        {0x1E, 0xcae380986c81613b, 0xFFFFFFFFFFFFFFFF},
        {0x20, 0xdd33ed27813dd200, 0xFFFFFFFFFFFFFFFF},
        {0x22, 0x06978803f7181d33, 0xFFFFFFFFFFFFFFFF},
        {0x24, 0x6a70ca627813dd38, 0xFFFFFFFFFFFFFFFF},
        {0x26, 0x58064d7004125140, 0xFFFFFFFFFFFFFFFF},
        {0x28, 0x02cae7864e700814, 0xFFFFFFFFFFFFFFFF},
        {0x2A, 0x0c91181d05833ed2, 0xFFFFFFFFFFFFFFFF},
        {0x2C, 0xfdc101a9d300fdc1, 0xFFFFFFFFFFFFFFFF},
        {0x2E, 0x9e04f74901adc100, 0xFFFFFFFFFFFFFFFF},
        {0x30, 0x051511935c010494, 0xFFFFFFFFFFFFFFFF},
        {0x32, 0x748032b8f1939c03, 0xFFFFFFFFFFFFFFFF},
        {0x34, 0xfd2c3318700fdc60, 0xFFFFFFFFFFFFFFFF},
        {0x36, 0x240287903287ff81, 0xFFFFFFFFFFFFFFFF},
        {0x38, 0xfdff7c1fd2d80ca1, 0xFFFFFFFFFFFFFFFF},
        {0x3A, 0x408b1bf00c248600, 0xFFFFFFFFFFFFFFFF},
        {0x3C, 0xb2b8200fdc1f515c, 0xFFFFFFFFFFFFFFFF},
        {0x3E, 0x0b22c7fffffe2f08, 0xFFFFFFFFFFFFFFFF}
    }
};

TEST_BSS const EEPROM_INTERFACE pfsmBANK3EEPROM[MAX_NVM_VERSION_AVAILABLE][NUMBER_OF_PFSM_EEPROM_REGISTERS] =
{
    {
        {0x00, 0xb4151882443803de, 0xFFFFFFFFFFFFFFFF},
        {0x02, 0x0a0462008015b802, 0xFFFFFFFFFFFFFFFF},
        {0x04, 0xe001d0da004e4620, 0xFFFFFFFFFFFFFFFF},
        {0x06, 0x08c4803278003e16, 0xFFFFFFFFFFFFFFFF},
        {0x08, 0x1613b0484ec14138, 0xFFFFFFFFFFFFFFFF},
        {0x0A, 0x1440c391380986c8, 0xFFFFFFFFFFFFFFFF},
        {0x0C, 0x7d2f9ccb60cc6002, 0xFFFFFFFFFFFFFFFF},
        {0x0E, 0xfbfd2c101a1e0fff, 0xFFFFFFFFFFFFFFFF},
        {0x10, 0xfec2019dde0b720f, 0xFFFFFFFFFFFFFFFF},
        {0x12, 0x42075300fdfff7ff, 0xFFFFFFFFFFFFFFFF},
        {0x14, 0x02b44e200c0000f4, 0xFFFFFFFFFFFFFFFF},
        {0x16, 0x200a04e2008029b8, 0xFFFFFFFFFFFFFFFF},
        {0x18, 0x3e16e001d0804d4e, 0xFFFFFFFFFFFFFFFF},
        {0x1A, 0xb8007c1388018000, 0xFFFFFFFFFFFFFFFF},
        {0x1C, 0x1200c9e1f21c4061, 0xFFFFFFFFFFFFFFFF},
        {0x1E, 0x40c39100330400cb, 0xFFFFFFFFFFFFFFFF},
        {0x20, 0x032bbf7ffffed607, 0xFFFFFFFFFFFFFFFF},
        {0x22, 0x03284101a1c1a588, 0xFFFFFFFFFFFFFFFF},
        {0x24, 0x18d900ca10406a75, 0xFFFFFFFFFFFFFFFF},
        {0x26, 0x54dc303284101a9c, 0xFFFFFFFFFFFFFFFF},
        {0x28, 0x0a2198288400a215, 0xFFFFFFFFFFFFFFFF},
        {0x2A, 0x4685f4a21132886e, 0xFFFFFFFFFFFFFFFF},
        {0x2C, 0x85153452008ef106, 0xFFFFFFFFFFFFFFFF},
        {0x2E, 0x4bcffbffffbc0028, 0xFFFFFFFFFFFFFFFF},
        {0x30, 0x002d70ca6ce373ac, 0xFFFFFFFFFFFFFFFF},
        {0x32, 0x101a5dc0ca107361, 0xFFFFFFFFFFFFFFFF},
        {0x34, 0xfdff4b0ccd803284, 0xFFFFFFFFFFFFFFFF},
        {0x36, 0x54d2002870066cff, 0xFFFFFFFFFFFFFFFF},
        {0x38, 0x11060307dd3649e3, 0xFFFFFFFFFFFFFFFF},
        {0x3A, 0x49e254df3dd0686e, 0xFFFFFFFFFFFFFFFF},
        {0x3C, 0x0060207de3ddcd20, 0xFFFFFFFFFFFFFFFF},
        {0x3E, 0x00c306dc206dc6e0, 0xFFFFFFFFFFFFFFFF}
    },
    {
        {0x00, 0x882443803de081dc, 0xFFFFFFFFFFFFFFFF},
        {0x02, 0x2008015b802b4151, 0xFFFFFFFFFFFFFFFF},
        {0x04, 0x0da004e46200a046, 0xFFFFFFFFFFFFFFFF},
        {0x06, 0x03278003e16e001d, 0xFFFFFFFFFFFFFFFF},
        {0x08, 0x0484ec1413808c48, 0xFFFFFFFFFFFFFFFF},
        {0x0A, 0x391380986c81613b, 0xFFFFFFFFFFFFFFFF},
        {0x0C, 0x5f4b0cc60021440c, 0xFFFFFFFFFFFFFFFF},
        {0x0E, 0xd07f4b040687fff0, 0xFFFFFFFFFFFFFFFF},
        {0x10, 0x003d1081d782dcff, 0xFFFFFFFFFFFFFFFF},
        {0x12, 0x0a6e00ad13880300, 0xFFFFFFFFFFFFFFFF},
        {0x14, 0x1353880281388020, 0xFFFFFFFFFFFFFFFF},
        {0x16, 0x60000f85b8007420, 0xFFFFFFFFFFFFFFFF},
        {0x18, 0x10186e001f04e200, 0xFFFFFFFFFFFFFFFF},
        {0x1A, 0x0032c48032787c87, 0xFFFFFFFFFFFFFFFF},
        {0x1C, 0xb581d030e4400cc1, 0xFFFFFFFFFFFFFFFF},
        {0x1E, 0x696200caeeffffff, 0xFFFFFFFFFFFFFFFF},
        {0x20, 0x1a9d40ca10406870, 0xFFFFFFFFFFFFFFFF},
        {0x22, 0x06a7063640328410, 0xFFFFFFFFFFFFFFFF},
        {0x24, 0x288555370c0ca104, 0xFFFFFFFFFFFFFFFF},
        {0x26, 0xa21b8288660a2100, 0xFFFFFFFFFFFFFFFF},
        {0x28, 0xbc4191a17d28844c, 0xFFFFFFFFFFFFFFFF},
        {0x2A, 0x000a21454d148023, 0xFFFFFFFFFFFFFFFF},
        {0x2C, 0x841cd8400b5c329b, 0xFFFFFFFFFFFFFFFF},
        {0x2E, 0x600ca10406977032, 0xFFFFFFFFFFFFFFFF},
        {0x30, 0x019b3fec1fd2c333, 0xFFFFFFFFFFFFFFFF},
        {0x32, 0x4d9278d534800a1c, 0xFFFFFFFFFFFFFFFF},
        {0x34, 0x741a1b844180c1f7, 0xFFFFFFFFFFFFFFFF},
        {0x36, 0xf7734812789537cf, 0xFFFFFFFFFFFFFFFF},
        {0x38, 0x1b71b80018081f78, 0xFFFFFFFFFFFFFFFF},
        {0x3A, 0x0000000030c1b708, 0xFFFFFFFFFFFFFFFF},
        {0x3C, 0x0000000000000000, 0xFFFFFFFFFFFFFFFF},
        {0x3E, 0x0000000000000000, 0xFFFFFFFFFFFFFFFF}
    }
};

#endif


#ifdef lemans

// Below four arrays ( staticBANK0EEPROM,pfsmBANK1EEPROM,pfsmBANK2EEPROM,pfsmBANK3EEPROM ) can be changed based on NVM Seq release by TI

TEST_BSS const EEPROM_INTERFACE staticBANK0EEPROM[MAX_NVM_VERSION_AVAILABLE][NUMBER_OF_STATIC_EEPROM_REGISTERS] =
{
    {
        {0x1A, 0xA21AA21AA21AA212, 0xFFFFFFFFFFFFFFFF},
        {0x1C, 0x3B0C3B5F5F73B212, 0xFFFFFFFFFFFFFFFF},
        {0x26, 0x1140E6AA05500018, 0xFFFFFFFFFFFFFFFF},
        {0x28, 0x33F0000000000540, 0xFFFFFFFFFFFFFFFF},
        {0x2A, 0x54000000200C7B2B, 0xFFFFFFFFFFFFFFFF},
        {0x38, 0xA5001FA200000101, 0xFFFFFFFFFFFFFFFF},
        {0x3C, 0xE26EFCD8000013C2, 0xFFFFFFFFFFFFFFFF},
        {0x3E, 0x59434ED4B8500000, 0xFFFFFFFFFFFF0000}
    },
    {
        {0x1A, 0xA21AA21AA21C8214, 0xFFFFFFFFFFFFFFFF},
        {0x1C, 0x3B0C3BB2D573B212, 0xFFFFFFFFFFFFFFFF},
        {0x26, 0x1140A6AA05500018, 0xFFFFFFFFFFFFFFFF},
        {0x28, 0x33F0B00000880540, 0xFFFFFFFFFFFFFFFF},
        {0x2A, 0x55400000200C7B2B, 0xFFFFFFFFFFFFFFFF},
        {0x38, 0xA5001F8200000102, 0xFFFFFFFFFFFFFFFF},
        {0x3C, 0x618F7F39000013C2, 0xFFFFFFFFFFFFFFFF},
        {0x3E, 0xD14E58C104B80000, 0xFFFFFFFFFFFF0000}
    }
};

TEST_BSS const EEPROM_INTERFACE pfsmBANK1EEPROM[MAX_NVM_VERSION_AVAILABLE][NUMBER_OF_PFSM_EEPROM_REGISTERS] =
{
    {
        {0x00, 0x9c82821a9c82800a, 0xFFFFFFFFFFFFFFFF},
        {0x02, 0x9c80fe3a9c82902a, 0xFFFFFFFFFFFFFFFF},
        {0x04, 0x57c90e5a9c89be4a, 0xFFFFFFFFFFFFFFFF},
        {0x06, 0x4649ae7a57c9b46a, 0xFFFFFFFFFFFFFFFF},
        {0x08, 0x4009329a4f69b28a, 0xFFFFFFFFFFFFFFFF},
        {0x0A, 0xb24942ba182098aa, 0xFFFFFFFFFFFFFFFF},
        {0x0C, 0x1820feda86607cca, 0xFFFFFFFFFFFFFFFF},
        {0x0E, 0xbc9940fa8660feea, 0xFFFFFFFFFFFFFFFF},
        {0x10, 0xbc90ff1abc90890a, 0xFFFFFFFFFFFFFFFF},
        {0x12, 0xbb79473aba507d2a, 0xFFFFFFFFFFFFFFFF},
        {0x14, 0x1820095a0045454a, 0xFFFFFFFFFFFFFFFF},
        {0x16, 0xfdffff8b003c896a, 0xFFFFFFFFFFFFFFFF},
        {0x18, 0xbecc334a03804eec, 0xFFFFFFFFFFFFFFFF},
        {0x1A, 0x334d0cc334c03834, 0xFFFFFFFFFFFFFFFF},
        {0x1C, 0x26881e882d984dcc, 0xFFFFFFFFFFFFFFFF},
        {0x1E, 0x0a0ab15076e111d0, 0xFFFFFFFFFFFFFFFF},
        {0x20, 0xe11080a314e76e11, 0xFFFFFFFFFFFFFFFF},
        {0x22, 0xf76e110c09b14d76, 0xFFFFFFFFFFFFFFFF},
        {0x24, 0xb15376e112009314, 0xFFFFFFFFFFFFFFFF},
        {0x26, 0x403f79cad0804678, 0xFFFFFFFFFFFFFFFF},
        {0x28, 0xcc004a013dd8cad0, 0xFFFFFFFFFFFFFFFF},
        {0x2A, 0x04de3804ce3804be, 0xFFFFFFFFFFFFFFFF},
        {0x2C, 0x2181d5d45472784e, 0xFFFFFFFFFFFFFFFF},
        {0x2E, 0x1022c4cfb6fc0309, 0xFFFFFFFFFFFFFFFF},
        {0x30, 0x0ca647d4a74bd457, 0xFFFFFFFFFFFFFFFF},
        {0x32, 0x00fdd502410806c7, 0xFFFFFFFFFFFFFFFF},
        {0x34, 0xb16e111e03809041, 0xFFFFFFFFFFFFFFFF},
        {0x36, 0xb190e789fd45c208, 0xFFFFFFFFFFFFFFFF},
        {0x38, 0x3304cf74be138133, 0xFFFFFFFFFFFFFFFF},
        {0x3A, 0xd622da0b400c9101, 0xFFFFFFFFFFFFFFFF},
        {0x3C, 0xffffdec200fdffb9, 0xFFFFFFFFFFFFFFFF},
        {0x3E, 0xc0b22c7f0f7f2b7f, 0xFFFFFFFFFFFFFFFF}
    },
    {
        {0x00,0x9d92821a9d92800a, 0xFFFFFFFFFFFFFFFF},
        {0x02,0x9d99be3a9d90fe2a, 0xFFFFFFFFFFFFFFFF},
        {0x04,0x5749b45a57490e4a, 0xFFFFFFFFFFFFFFFF},
        {0x06,0x5009b27a4809ae6a, 0xFFFFFFFFFFFFFFFF},
        {0x08,0x1720989a40c9328a, 0xFFFFFFFFFFFFFFFF},
        {0x0A,0x86907cbab2d942aa, 0xFFFFFFFFFFFFFFFF},
        {0x0C,0x8690feda1720feca, 0xFFFFFFFFFFFFFFFF},
        {0x0E,0xbc7088fabc7940ea, 0xFFFFFFFFFFFFFFFF},
        {0x10,0xba307d1abc70ff0a, 0xFFFFFFFFFFFFFFFF},
        {0x12,0x0045453abb59472a, 0xFFFFFFFFFFFFFFFF},
        {0x14,0x003c895a1720094a, 0xFFFFFFFFFFFFFFFF},
        {0x16,0x44004e1cfeffffcb, 0xFFFFFFFFFFFFFFFF},
        {0x18,0x10312c4cc4a1bb12, 0xFFFFFFFFFFFFFFFF},
        {0x1A,0x2d984d3b1344cc4c, 0xFFFFFFFFFFFFFFFF},
        {0x1C,0x46e111d026881e88, 0xFFFFFFFFFFFFFFFF},
        {0x1E,0x0a0b714b705bc420, 0xFFFFFFFFFFFFFFFF},
        {0x20,0xe11080af14e76e11, 0xFFFFFFFFFFFFFFFF},
        {0x22,0xf76e110c0a714d76, 0xFFFFFFFFFFFFFFFF},
        {0x24,0x715376e112009f14, 0xFFFFFFFFFFFFFFFF},
        {0x26,0x403f79cad0804679, 0xFFFFFFFFFFFFFFFF},
        {0x28,0xc4004a113dd8cad0, 0xFFFFFFFFFFFFFFFF},
        {0x2A,0x151c9e02c4d10012, 0xFFFFFFFFFFFFFFFF},
        {0x2C,0xe1bf00c2486075b5, 0xFFFFFFFFFFFFFFFF},
        {0x2E,0x75bd4571022c4083, 0xFFFFFFFFFFFFFFFF},
        {0x30,0x10c06c70ca657d4a, 0xFFFFFFFFFFFFFFFF},
        {0x32,0x04200fdd81b55024, 0xFFFFFFFFFFFFFFFF},
        {0x34,0xe6e111e0706d3809, 0xFFFFFFFFFFFFFFFF},
        {0x36,0xac531c2c8b1da206, 0xFFFFFFFFFFFFFFFF},
        {0x38,0x0130620491230e44, 0xFFFFFFFFFFFFFFFF},
        {0x3A,0x24404cc133dd0680, 0xFFFFFFFFFFFFFFFF},
        {0x3C,0x7ff73ac4b682d003, 0xFFFFFFFFFFFFFFFF},
        {0x3E,0xcadffffffbb0803f, 0xFFFFFFFFFFFFFFFF}
    }
};


TEST_BSS const EEPROM_INTERFACE pfsmBANK2EEPROM[MAX_NVM_VERSION_AVAILABLE][NUMBER_OF_PFSM_EEPROM_REGISTERS] =
{
    {
        {0x00, 0xe078ece2008003dd, 0xFFFFFFFFFFFFFFFF},
        {0x02, 0x7ea00c8b12c90ae4, 0xFFFFFFFFFFFFFFFF},
        {0x04, 0xee7608b0b22c48fb, 0xFFFFFFFFFFFFFFFF},
        {0x06, 0x8e2864e72c10aecf, 0xFFFFFFFFFFFFFFFF},
        {0x08, 0x4d74e878e0581d10, 0xFFFFFFFFFFFFFFFF},
        {0x0A, 0x4733ed27813dd186, 0xFFFFFFFFFFFFFFFF},
        {0x0C, 0x03f7fee7588b0940, 0xFFFFFFFFFFFFFFFF},
        {0x0E, 0xc10aecffffff0b04, 0xFFFFFFFFFFFFFFFF},
        {0x10, 0x0581d108e2464e72, 0xFFFFFFFFFFFFFFFF},
        {0x12, 0x13dd1464d74e878e, 0xFFFFFFFFFFFFFFFF},
        {0x14, 0x7fee7588b33ed278, 0xFFFFFFFFFFFFFFFF},
        {0x16, 0x4dcffffff0b0403f, 0xFFFFFFFFFFFFFFFF},
        {0x18, 0xa2198288400a2155, 0xFFFFFFFFFFFFFFFF},
        {0x1A, 0x689f4a21132886e0, 0xFFFFFFFFFFFFFFFF},
        {0x1C, 0x454d1483efdf9004, 0xFFFFFFFFFFFFFFFF},
        {0x1E, 0x4193358325800a21, 0xFFFFFFFFFFFFFFFF},
        {0x20, 0x9001a1c2077339a3, 0xFFFFFFFFFFFFFFFF},
        {0x22, 0x84ec1413808c4329, 0xFFFFFFFFFFFFFFFF},
        {0x24, 0x7380986c81613b04, 0xFFFFFFFFFFFFFFFF},
        {0x26, 0x100fdd502410806c, 0xFFFFFFFFFFFFFFFF},
        {0x28, 0x81d27813dd380904, 0xFFFFFFFFFFFFFFFF},
        {0x2A, 0x78003f733dd33ed1, 0xFFFFFFFFFFFFFFFF},
        {0x2C, 0x0ca627813dd38069, 0xFFFFFFFFFFFFFFFF},
        {0x2E, 0x64d70041251406a7, 0xFFFFFFFFFFFFFFFF},
        {0x30, 0xae6c64e700814574, 0xFFFFFFFFFFFFFFFF},
        {0x32, 0x1181d05833ed202c, 0xFFFFFFFFFFFFFFFF},
        {0x34, 0x101a9d100fdc10c9, 0xFFFFFFFFFFFFFFFF},
        {0x36, 0x4f74901adc100fdc, 0xFFFFFFFFFFFFFFFF},
        {0x38, 0x4e1935c0104949e0, 0xFFFFFFFFFFFFFFFF},
        {0x3A, 0x032b8c1939c03051, 0xFFFFFFFFFFFFFFFF},
        {0x3C, 0xc3318500fdc60748, 0xFFFFFFFFFFFFFFFF},
        {0x3E, 0xe2c700a1ffffbfe2, 0xFFFFFFFFFFFFFFFF}
    },
    {
        {0x00,0x08066703ddcfc3df, 0xFFFFFFFFFFFFFFFF},
        {0x02,0x00800803f72c908e, 0xFFFFFFFFFFFFFFFF},
        {0x04,0x60b242b914781ce2, 0xFFFFFFFFFFFFFFFF},
        {0x06,0xcff73b04b000f840, 0xFFFFFFFFFFFFFFFF},
        {0x08,0x242c10aeffffff8b, 0xFFFFFFFFFFFFFFFF},
        {0x0A,0x5d54781058179846, 0xFFFFFFFFFFFFFFFF},
        {0x0C,0x20f849e04f745193, 0xFFFFFFFFFFFFFFFF},
        {0x0E,0xcff73ac4b0540470, 0xFFFFFFFFFFFFFFFF},
        {0x10,0x242c10aeffffff8b, 0xFFFFFFFFFFFFFFFF},
        {0x12,0x5d54781058179846, 0xFFFFFFFFFFFFFFFF},
        {0x14,0x20f849e04f744193, 0xFFFFFFFFFFFFFFFF},
        {0x16,0x490541cff73ac4b0, 0xFFFFFFFFFFFFFFFF},
        {0x18,0xb8288660a2100288, 0xFFFFFFFFFFFFFFFF},
        {0x1A,0x011a17d28844ca21, 0xFFFFFFFFFFFFFFFF},
        {0x1C,0x8480541148023bc4, 0xFFFFFFFFFFFFFFFF},
        {0x1E,0x8d064cd60c960028, 0xFFFFFFFFFFFFFFFF},
        {0x20,0xa6400687081dcce6, 0xFFFFFFFFFFFFFFFF},
        {0x22,0x1213b0504e02310c, 0xFFFFFFFFFFFFFFFF},
        {0x24,0xb1ce0261b20584ec, 0xFFFFFFFFFFFFFFFF},
        {0x26,0x10403f7540904201, 0xFFFFFFFFFFFFFFFF},
        {0x28,0x460749e04f74e024, 0xFFFFFFFFFFFFFFFF},
        {0x2A,0x78003f733dd020f8, 0xFFFFFFFFFFFFFFFF},
        {0x2C,0x0ca627813dd38069, 0xFFFFFFFFFFFFFFFF},
        {0x2E,0x64d70041251406a7, 0xFFFFFFFFFFFFFFFF},
        {0x30,0xae6c64e700814574, 0xFFFFFFFFFFFFFFFF},
        {0x32,0x6074160083e1202c, 0xFFFFFFFFFFFFFFFF},
        {0x34,0x06a74403f7043244, 0xFFFFFFFFFFFFFFFF},
        {0x36,0xdd2406b70403f704, 0xFFFFFFFFFFFFFFFF},
        {0x38,0x864d700412527813, 0xFFFFFFFFFFFFFFFF},
        {0x3A,0xcae3064e700c1453, 0xFFFFFFFFFFFFFFFF},
        {0x3C,0xcc61403f7181d200, 0xFFFFFFFFFFFFFFFF},
        {0x3E,0xb1c0287ffff7fcb0, 0xFFFFFFFFFFFFFFFF}
    }
};

TEST_BSS const EEPROM_INTERFACE pfsmBANK3EEPROM[MAX_NVM_VERSION_AVAILABLE][NUMBER_OF_PFSM_EEPROM_REGISTERS] =
{
    {
        {0x00, 0x0c248500fdfff7ff, 0xFFFFFFFFFFFFFFFF},
        {0x02, 0xdc1f515c408b1bf0, 0xFFFFFFFFFFFFFFFF},
        {0x04, 0x22c7fffffc2c100f, 0xFFFFFFFFFFFFFFFF},
        {0x06, 0x003dd23dd081dc0b, 0xFFFFFFFFFFFFFFFF},
        {0x08, 0x2b4ce200c06e001e, 0xFFFFFFFFFFFFFFFF},
        {0x0A, 0x60ad4e2008029b80, 0xFFFFFFFFFFFFFFFF},
        {0x0C, 0xed6e001d04e200a0, 0xFFFFFFFFFFFFFFFF},
        {0x0E, 0x6e1c004e38365e23, 0xFFFFFFFFFFFFFFFF},
        {0x10, 0x000cae200c9e1c00, 0xFFFFFFFFFFFFFFFF},
        {0x12, 0xec1213b0504e0231, 0xFFFFFFFFFFFFFFFF},
        {0x14, 0x80e78e0261b20584, 0xFFFFFFFFFFFFFFFF},
        {0x16, 0x319607660b7a1771, 0xFFFFFFFFFFFFFFFF},
        {0x18, 0xf8b080687e732d83, 0xFFFFFFFFFFFFFFFF},
        {0x1A, 0xfbf8b0403f7fffdf, 0xFFFFFFFFFFFFFFFF},
        {0x1C, 0xfb080677782dcfff, 0xFFFFFFFFFFFFFFFF},
        {0x1E, 0x081d6803f7ffbfff, 0xFFFFFFFFFFFFFFFF},
        {0x20, 0x06e001e003dd23dd, 0xFFFFFFFFFFFFFFFF},
        {0x22, 0x8029b802b44e200c, 0xFFFFFFFFFFFFFFFF},
        {0x24, 0x01d04e200a04e200, 0xFFFFFFFFFFFFFFFF},
        {0x26, 0x606e0004023ed6e0, 0xFFFFFFFFFFFFFFFF},
        {0x28, 0x48b16e001f06e000, 0xFFFFFFFFFFFFFFFF},
        {0x2A, 0x80327807e1f81202, 0xFFFFFFFFFFFFFFFF},
        {0x2C, 0x0032c433340032b8, 0xFFFFFFFFFFFFFFFF},
        {0x2E, 0x660b7180e7800cc1, 0xFFFFFFFFFFFFFFFF},
        {0x30, 0xbfffffb0b22c5607, 0xFFFFFFFFFFFFFFFF},
        {0x32, 0x8288400a21554dcf, 0xFFFFFFFFFFFFFFFF},
        {0x34, 0x4a21132886e0a219, 0xFFFFFFFFFFFFFFFF},
        {0x36, 0x1483efdf9064689f, 0xFFFFFFFFFFFFFFFF},
        {0x38, 0xb9f622c00a21454d, 0xFFFFFFFFFFFFFFFF},
        {0x3A, 0xd622f3fdffffef3f, 0xFFFFFFFFFFFFFFFF},
        {0x3C, 0xffeffe2c33373fb9, 0xFFFFFFFFFFFFFFFF},
        {0x3E, 0x0000000000000033, 0xFFFFFFFFFFFFFFFF}
    },
    {
        {0x00,0x0921403f7ffefffc, 0xFFFFFFFFFFFFFFFF},
        {0x02,0x07d4571022c6fc03, 0xFFFFFFFFFFFFFFFF},
        {0x04,0xb1ffffff8b0403f7, 0xFFFFFFFFFFFFFFFF},
        {0x06,0xb4e00f78207702c8, 0xFFFFFFFFFFFFFFFF},
        {0x08,0x3880301b80078201, 0xFFFFFFFFFFFFFFFF},
        {0x0A,0x53880200a6e00ad3, 0xFFFFFFFFFFFFFFFF},
        {0x0C,0x35388028182b5823, 0xFFFFFFFFFFFFFFFF},
        {0x0E,0xe000f85b80074201, 0xFFFFFFFFFFFFFFFF},
        {0x10,0xc006e1c004e38365, 0xFFFFFFFFFFFFFFFF},
        {0x12,0x231000cae200c9e1, 0xFFFFFFFFFFFFFFFF},
        {0x14,0x584ec1213b0504e0, 0xFFFFFFFFFFFFFFFF},
        {0x16,0x5e030e44e0261b20, 0xFFFFFFFFFFFFFFFF},
        {0x18,0x0cc6581d982dce08, 0xFFFFFFFFFFFFFFFF},
        {0x1A,0xa1fffff7f2f9ccb6, 0xFFFFFFFFFFFFFFFF},
        {0x1C,0xe0b73fffbff2c101, 0xFFFFFFFFFFFFFFFF},
        {0x1E,0xdfff7fffec2019dd, 0xFFFFFFFFFFFFFFFF},
        {0x20,0xb4e00f782075900f, 0xFFFFFFFFFFFFFFFF},
        {0x22,0x3880301b80078201, 0xFFFFFFFFFFFFFFFF},
        {0x24,0x13880200a6e00ad1, 0xFFFFFFFFFFFFFFFF},
        {0x26,0x8007420135388028, 0xFFFFFFFFFFFFFFFF},
        {0x28,0x606e00040000f85b, 0xFFFFFFFFFFFFFFFF},
        {0x2A,0xe0186e001f06e000, 0xFFFFFFFFFFFFFFFF},
        {0x2C,0x00cae200c9e01f87, 0xFFFFFFFFFFFFFFFF},
        {0x2E,0x00330400cb10ccd0, 0xFFFFFFFFFFFFFFFF},
        {0x30,0xfed607660b40c391, 0xFFFFFFFFFFFFFFFF},
        {0x32,0x0a212415073f7fff, 0xFFFFFFFFFFFFFFFF},
        {0x34,0x2886e0a219828840, 0xFFFFFFFFFFFFFFFF},
        {0x36,0xef1064685f4a2113, 0xFFFFFFFFFFFFFFFF},
        {0x38,0x00a2120150452008, 0xFFFFFFFFFFFFFFFF},
        {0x3A,0xceb12f3feffffef0, 0xFFFFFFFFFFFFFFFF},
        {0x3C,0x3fff7ff2c33373fd, 0xFFFFFFFFFFFFFFFF},
        {0x3E,0x0000000000000003, 0xFFFFFFFFFFFFFFFF}
    }
};

#endif



/*=========================================================================================================
**                                        Local function prototypes                                      **
=========================================================================================================*/

TEST_FUNC static pmicErrFlagType_e prvPmicNVMFrameUpdate(uint8 ucCustomerNVMId );
TEST_FUNC static pmicErrFlagType_e prveepromWrite(EEPROM_INTERFACE *EEPROMptr);
TEST_FUNC static pmicErrFlagType_e prvPmicCrashResetTest(void);
TEST_FUNC static pmicErrFlagType_e prvPmicSmpsLdoTest(void);
TEST_FUNC static pmicErrFlagType_e prvPmicCxMxScalingTest(void);
TEST_FUNC static pmicErrFlagType_e prvPmicGenericAPITest(void);
TEST_FUNC static pmicErrFlagType_e prvPmicTest(void);
TEST_FUNC static pmicCornerRailType_e prvCoreRailStringToValue( char *pxStringCoreRail);
TEST_FUNC static uint64 prvGetOneStep(uint64 ullvoltageUv);
TEST_FUNC static uint64 prvSailCharToLL(char *str);
/* CPR_STRIPPING_CHANGES */
TEST_FUNC static ePMICCprVoltageLevelType prvCornerStringToValue( char *pxStringCorner);
TEST_FUNC static pmicErrFlagType_e prvPmicInfo(TestCaseType TCType, uint8 cpu_id, uint8 *DataBuff, uint8 *ucLength);
TEST_FUNC static TESTerrorType_e prvPmiclogPrint( void );
TEST_FUNC static TESTerrorType_e prvEnableDrv( void );
TEST_FUNC static TESTerrorType_e xTestMXOneStepUpVoltWrapper(void);
TEST_FUNC static TESTerrorType_e xTestCXOneStepUpVoltWrapper(void);
TEST_FUNC static TESTerrorType_e xTestMXOneStepDownVoltWrapper(void);
TEST_FUNC static TESTerrorType_e xTestCXOneStepDownVoltWrapper(void);
TEST_FUNC static TESTerrorType_e xTestMXCoreWriteVoltWrapper(uint64 Abs_volt_lower, uint64 Abs_volt_higher );
TEST_FUNC static TESTerrorType_e xTestCXCoreWriteVoltWrapper(uint64 Abs_volt_lower, uint64 Abs_volt_higher );
TEST_FUNC static TESTerrorType_e x_TestWriteCxVoltWrapper(uint8 Cornervalpassed);    
TEST_FUNC static TESTerrorType_e x_TestWriteMxVoltWrapper(uint8 Cornervalpassed);
TEST_FUNC static pmicErrFlagType_e prvDisableMon(eMonitorType xMonitorId);
/*=========================================================================================================
**                                        Global function definitions                                    **
=========================================================================================================*/

/*=================================================================================================
 @Service name        PMICSysCallSmpsWriteVoltage
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

TEST_FUNC uint32 PMICSysCallSmpsWriteVoltage(uint32 ucindex , uint32 ullvoltageLb , uint32 ullvoltageUb, sailbsp_svc_rsp_t *rsp)
{
    uint64 ullvoltageUv = 0x0;
    ullvoltageUv = ullvoltageUb;
    ullvoltageUv = (ullvoltageUv<<32)|(ullvoltageLb);
    rsp->data[0] = prvPmicSmpsWriteVoltage((uint8)ucindex,ullvoltageUv);

    return SVC_SUCCESS;
}


/*=================================================================================================
 @Service name        PMICSysCallSmpsWriteEnable
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

TEST_FUNC uint32 PMICSysCallSmpsWriteEnable(uint32 ucindex , uint32 benableStatus, sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = prvPmicSmpsWriteEnable((uint8)ucindex,(boolean)benableStatus);

    return SVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICSysCallLdoWriteVoltage
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

TEST_FUNC uint32 PMICSysCallLdoWriteVoltage(uint32 ucindex , uint32 ullvoltageLb , uint32 ullvoltageUb  ,sailbsp_svc_rsp_t *rsp)
{
    uint64 ullvoltageUv = 0x0;
    ullvoltageUv = ullvoltageUb;
    ullvoltageUv = (ullvoltageUv<<32)|(ullvoltageLb);

    rsp->data[0] = prvPmicLdoWriteVoltage((uint8)ucindex,ullvoltageUv);

    return SVC_SUCCESS;
}


/*=================================================================================================
 @Service name        PMICSysCallLdoReadVoltage
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

TEST_FUNC uint32 PMICSysCallLdoReadVoltage(uint32 ucindex , uint64 *pullvoltageUv, sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = prvPmicLdoReadVoltage((uint8)ucindex,pullvoltageUv);

    return SVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICSysCallLdoReadEnable
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/


TEST_FUNC uint32 PMICSysCallLdoReadEnable(uint32 ucindex , boolean *pbenableStatus, sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = prvPmicLdoReadEnable(ucindex,pbenableStatus);

    return SVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICSysCallSmpsReadVoltage
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

TEST_FUNC uint32 PMICSysCallSmpsReadVoltage(uint32 ucindex , uint64 *pullvoltageUv, sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = prvPmicSmpsReadVoltage((uint8)ucindex,pullvoltageUv);

    return SVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICSysCallSmpsReadEnable
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

TEST_FUNC uint32 PMICSysCallSmpsReadEnable(uint32 ucindex , boolean *pbenableStatus, sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = prvPmicSmpsReadEnable((uint8)ucindex,pbenableStatus);

    return SVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICSysCallCommReadByte
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

TEST_FUNC uint32 PMICSysCallCommReadByte(pmicPageId_e xpageId, uint32 uladdr , uint8 *pcdata , sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = prvPmicCommReadByte(xpageId,uladdr,pcdata);

    return SVC_SUCCESS;
}

/*=================================================================================================
 @Service name        PMICSysCallGetSAILPMICINFO
 @Description         SysCall to call Internal PMIC API Present in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              uint32 <SVC_SUCCESS> to indicate SHIM call is successfull
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/


TEST_FUNC uint32 PMICSysCallGetSAILPMICINFO( uint32 ucPmicInfoType,sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) prvGetSAILPMICInfo((pmicInfo_e)ucPmicInfoType);

    return (uint32) SVC_SUCCESS;
}

/*=========================================================================================================
 @Service name        prvPmicLdoReadVoltage
 @Description         prvPmicLdoReadVoltage is Trap call used to read voltage of any particular ldo
 @param[in]           <ucindex>  <PMIC_REG_1,PMIC_REG_2,PMIC_REG_3,PMIC_REG_4>
 @param[out]          <pullvoltageUv>  <read voltage in micro Voltage>
 @param[in, out]      <Ptr>
 @return              <pmicErrFlagType_e> <Return err type based on status of read transaction>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

TEST_FUNC pmicErrFlagType_e prvPmicLdoReadVoltage(uint8 ucindex , uint64 *pullvoltageUv)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32_t hvcId     = PMIC_READ_LDO_VOLTAGE;
    uint32_t paramId   = PMIC_READ_LDO_VOLTAGE_PARM_ID;
    uint32_t arg1      = (uint32_t)ucindex;
    uint32_t arg2      = (uint32_t)pullvoltageUv;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    xErrFlag = paramId;
    
    return xErrFlag;

}

/*=========================================================================================================
 @Service name        prvPmicLdoReadEnable
 @Description         prvPmicLdoReadEnable is Trap call used to read enable status any particular ldo
 @param[in]           <ucindex>  <PMIC_REG_1,PMIC_REG_2,PMIC_REG_3,PMIC_REG_4>
 @param[out]          <pbenableStatus>  <PMIC_DISABLE,PMIC_ENABLE>
 @param[in, out]      <Ptr>
 @return              <err> <Return err type based on status of read transaction or input being passed>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

TEST_FUNC pmicErrFlagType_e prvPmicLdoReadEnable(uint8 ucindex , boolean *pbenableStatus)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32_t hvcId     = PMIC_READ_LDO_ENABLE;
    uint32_t paramId   = PMIC_READ_LDO_ENABLE_PARM_ID;
    uint32_t arg1      = (uint32_t)ucindex;
    uint32_t arg2      = (uint32_t)pbenableStatus;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    xErrFlag = paramId;
    
    return xErrFlag;

}

/*=========================================================================================================
 @Service name        prvPmicSmpsReadEnable
 @Description         prvPmicSmpsReadEnable is Trap call used to get the enable status of SMPS
 @param[in]           <ucindex>  <PMIC_REG_1,PMIC_REG_2,PMIC_REG_3,PMIC_REG_4>
 @param[out]          <benableStatus> <PMIC_DISABLE,PMIC_ENABLE>
 @param[in, out]      NA
 @return              <pmicErrFlagType_e> <Return err type based on status of read transaction>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/


TEST_FUNC pmicErrFlagType_e prvPmicSmpsReadEnable(uint8 ucindex , boolean *pbenableStatus)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32_t hvcId     = PMIC_READ_SMPS_ENABLE;
    uint32_t paramId   = PMIC_READ_SMPS_ENABLE_PARM_ID;
    uint32_t arg1      = (uint32_t)ucindex;
    uint32_t arg2      = (uint32_t)pbenableStatus;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    xErrFlag = paramId;
    
    return xErrFlag;

}

/*=========================================================================================================
 @Service name        prvPmicSmpsReadVoltage
 @Description         prvPmicSmpsReadVoltage is Trap call used to read voltage of any particular SMPS
 @param[in]           <ucindex>  <PMIC_REG_1,PMIC_REG_2,PMIC_REG_3,PMIC_REG_4>
 @param[out]          <pullvoltageUv>  <Read voltage in micro Voltage>
 @param[in, out]      <Ptr>
 @return              <pmicErrFlagType_e> <Return err type based on status of read transaction>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

TEST_FUNC pmicErrFlagType_e prvPmicSmpsReadVoltage(uint8 ucindex , uint64 *pullvoltageUv)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32_t hvcId     = PMIC_READ_SMPS_VOLTAGE;
    uint32_t paramId   = PMIC_READ_SMPS_VOLTAGE_PARM_ID;
    uint32_t arg1      = (uint32_t)ucindex;
    uint32_t arg2      = (uint32_t)pullvoltageUv;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if( TRUE == xSyscallIsPrivilegedMode() )
    {
    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    xErrFlag = paramId;
    
    return xErrFlag;

}

/*=========================================================================================================
 @Service name        prvPmicLdoWriteVoltage
 @Description         prvPmicLdoWriteVoltage is trap call to write voltage of any particular ldo
 @param[in]           <ucindex>  <PMIC_REG_1,PMIC_REG_2,PMIC_REG_3,PMIC_REG_4>
 @param[in]           <ullvoltageUv>  <Configure voltage in micro Voltage i.e. 600000 to configure 600mV or 0.6V>
 @param[out]          <Ptr>
 @param[in, out]      <Ptr>
 @return              <pmicErrFlagType_e> <Return err type based on status of write transaction or input paramter being passed>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

TEST_FUNC pmicErrFlagType_e prvPmicLdoWriteVoltage(uint8 ucindex , uint64 ullvoltageUv)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32_t hvcId     = PMIC_LDO_VOLTAGE_WRITE;
    uint32_t paramId   = PMIC_LDO_VOLTAGE_WRITE_PARM_ID;
    uint32_t arg1      = (uint32_t)ucindex;
    uint32_t arg2      = (uint32_t)ullvoltageUv;
    uint32_t arg3      = (uint32_t)(ullvoltageUv>>32);
    uint32_t arg4      = 0;
    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
        /* TODO: Implement error handler or log */
        while(1);
    }

    xErrFlag = paramId;
    
    return xErrFlag;

}

/*=========================================================================================================
 @Service name        prvPmicSmpsWriteEnable
 @Description         prvPmicSmpsWriteEnable Trap call to Enable SMPS
 @param[in]           <ucindex>  <PMIC_REG_1,PMIC_REG_2,PMIC_REG_3,PMIC_REG_4>
 @param[in]           <benableStatus>  <PMIC_DISABLE,PMIC_ENABLE>
 @param[in, out]      NA
 @return              <pmicErrFlagType_e> <Return err type based on status of read transaction>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/


TEST_FUNC pmicErrFlagType_e prvPmicSmpsWriteEnable(uint8 ucindex , boolean benableStatus)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32_t hvcId     = PMIC_SMPS_ENABLE_WRITE;
    uint32_t paramId   = PMIC_SMPS_ENABLE_WRITE_PARM_ID;
    uint32_t arg1      = (uint32_t)ucindex;
    uint32_t arg2      = (uint32_t)benableStatus;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
        /* TODO: Implement error handler or log */
        while(1);
    }

    xErrFlag = paramId;
    
    return xErrFlag;
}


/*=========================================================================================================
 @Service name        prvPmicSmpsWriteVoltage
 @Description         prvPmicSmpsWriteVoltage Trap call to Write Voltage of SMPS
 @param[in]           <ucindex>  <PMIC_REG_1,PMIC_REG_2,PMIC_REG_3,PMIC_REG_4>
 @param[in]           <ullvoltageUv>  <Voltage need to be configured in micro volt i.e. 600000 if 600mV need to be configure>
 @param[out]          NA
 @param[in, out]      NA
 @return              <pmicErrFlagType_e> <Return err type based on status of read transaction>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

TEST_FUNC pmicErrFlagType_e prvPmicSmpsWriteVoltage(uint8 ucindex , uint64 ullvoltageUv)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint32_t hvcId     = PMIC_SMPS_VOLTAGE_WRITE;
    uint32_t paramId   = PMIC_SMPS_VOLTAGE_WRITE_PARM_ID;
    uint32_t arg1      = (uint32_t)ucindex;
    uint32_t arg2      = (uint32_t)ullvoltageUv;
    uint32_t arg3      = (uint32_t)(ullvoltageUv>>32);
    uint32_t arg4      = 0;
    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
        /* TODO: Implement error handler or log */
        while(1);
    }

    xErrFlag = paramId;
    
    return xErrFlag; 
}

/*=========================================================================================================
 @Service name        prvGetSAILPMICInfo
 @Description         prvGetSAILPMICInfo Trap call to get nvm id
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              <uint8> CustomerNVMId
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/


TEST_FUNC uint8 prvGetSAILPMICInfo( pmicInfo_e xPmicInfoType )
{
    uint32_t hvcId     = PMIC_GET_NVM_ID;
    uint32_t paramId   = PMIC_GET_NVM_ID_PARM_ID;
    uint32_t arg1      = (uint32_t)xPmicInfoType;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
        /* TODO: Implement error handler or log */
        while(1);
    }

    return paramId;
}

/*=========================================================================================================
 @Service name        xTestOneStepDownVoltWrapper
 @Description         xTestOneStepDownVoltWrapper is call step up voltage of cx/mx by one step
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              TESTerrorType_e < MODULE_TEST_FAILED, MODULE_TEST_PASSED>
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/
TEST_FUNC static TESTerrorType_e xTestMXOneStepUpVoltWrapper(void)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    pmicCornerRailType_e xcoreRailVal = PMIC_INVALID_RAIL;
    uint64 ullvoltageUv = 0x0;
	
	xcoreRailVal = PMIC_MX_RAIL;
	
		
    if ( xcoreRailVal >= PMIC_INVALID_RAIL )
    {
        DEBUG_LOG(SAIL_ERROR,"Rail Not Supported\n\r");
    }else
    {
        if (PMIC_ERR_FLAG_SUCCESS == xPmicReadCoreRailVolt(xcoreRailVal,&ullvoltageUv))
        {
            DEBUG_LOG(SAIL_WARNING,"PMIC : Before %s Voltage : %lld uV\n\r",pxCoreRail[xcoreRailVal],ullvoltageUv);

            if(PMIC_ERR_FLAG_SUCCESS == xPmicChangeCoreRailVolt(xcoreRailVal,ullvoltageUv + prvGetOneStep(ullvoltageUv)))
            {
                if (PMIC_ERR_FLAG_SUCCESS == xPmicReadCoreRailVolt(xcoreRailVal,&ullvoltageUv))
                {
                    DEBUG_LOG(SAIL_WARNING,"PMIC : After %s 1 Step Up Voltage : %lld uV Success\n\r",pxCoreRail[xcoreRailVal],ullvoltageUv);
                    xRetStatus = MODULE_TEST_PASSED;
                }else
                {
                    DEBUG_LOG(SAIL_ERROR,"PMIC : After %s 1 Step Up Voltage : %lld uV Failed\n\r",pxCoreRail[xcoreRailVal],ullvoltageUv);
                }
            }
        }
    }

    return xRetStatus;
}

TEST_FUNC static TESTerrorType_e xTestCXOneStepUpVoltWrapper(void)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    pmicCornerRailType_e xcoreRailVal = PMIC_INVALID_RAIL;
    uint64 ullvoltageUv = 0x0;
	
	xcoreRailVal = PMIC_CX_RAIL;
	
		
    if ( xcoreRailVal >= PMIC_INVALID_RAIL )
    {
        DEBUG_LOG(SAIL_ERROR,"Rail Not Supported\n\r");
    }else
    {
        if (PMIC_ERR_FLAG_SUCCESS == xPmicReadCoreRailVolt(xcoreRailVal,&ullvoltageUv))
        {
            DEBUG_LOG(SAIL_ERROR,"PMIC : Before %s Voltage : %lld uV\n\r",pxCoreRail[xcoreRailVal],ullvoltageUv);

            if(PMIC_ERR_FLAG_SUCCESS == xPmicChangeCoreRailVolt(xcoreRailVal,ullvoltageUv + prvGetOneStep(ullvoltageUv)))
            {
                if (PMIC_ERR_FLAG_SUCCESS == xPmicReadCoreRailVolt(xcoreRailVal,&ullvoltageUv))
                {
                    DEBUG_LOG(SAIL_WARNING,"PMIC : After %s 1 Step Up Voltage : %lld uV Success\n\r",pxCoreRail[xcoreRailVal],ullvoltageUv);
                    xRetStatus = MODULE_TEST_PASSED;
                }else
                {
                    DEBUG_LOG(SAIL_ERROR,"PMIC : After %s 1 Step Up Voltage : %lld uV Failed\n\r",pxCoreRail[xcoreRailVal],ullvoltageUv);
                }
            }
        }
    }

    return xRetStatus;
}

/*=========================================================================================================
 @Service name        xTestOneStepDownVoltWrapper
 @Description         xTestOneStepDownVoltWrapper is call step up voltage of cx/mx by one step
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              TESTerrorType_e < MODULE_TEST_FAILED, MODULE_TEST_PASSED>
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/


TEST_FUNC TESTerrorType_e xTestOneStepUpVoltWrapper(void)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    pmicCornerRailType_e xcoreRailVal = PMIC_INVALID_RAIL;
    uint64 ullvoltageUv = 0x0;
    uint8 *pxStringCoreRail;

    pxStringCoreRail = APPL_SAIL_Shell_gettoken(NULL);

    xcoreRailVal = prvCoreRailStringToValue((char *)pxStringCoreRail);

    if ( xcoreRailVal >= PMIC_INVALID_RAIL )
    {
        DEBUG_LOG(SAIL_ERROR,"Rail Not Supported\n\r");
    }else
    {
        if (PMIC_ERR_FLAG_SUCCESS == xPmicReadCoreRailVolt(xcoreRailVal,&ullvoltageUv))
        {
            DEBUG_LOG(SAIL_WARNING,"PMIC : Before %s Voltage : %lld uV\n\r",pxCoreRail[xcoreRailVal],ullvoltageUv);

            if(PMIC_ERR_FLAG_SUCCESS == xPmicChangeCoreRailVolt(xcoreRailVal,ullvoltageUv + prvGetOneStep(ullvoltageUv)))
            {
                if (PMIC_ERR_FLAG_SUCCESS == xPmicReadCoreRailVolt(xcoreRailVal,&ullvoltageUv))
                {
                    DEBUG_LOG(SAIL_WARNING,"PMIC : After %s 1 Step Up Voltage : %lld uV Success\n\r",pxCoreRail[xcoreRailVal],ullvoltageUv);
                    xRetStatus = MODULE_TEST_PASSED;
                }else
                {
                    DEBUG_LOG(SAIL_ERROR,"PMIC : After %s 1 Step Up Voltage : %lld uV Failed\n\r",pxCoreRail[xcoreRailVal],ullvoltageUv);
                }
            }
        }
    }

    return xRetStatus;
}

/*=========================================================================================================
 @Service name        xTestOneStepDownVoltWrapper
 @Description         xTestOneStepDownVoltWrapper is call step down voltage of cx/mx by one step
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              TESTerrorType_e < MODULE_TEST_FAILED, MODULE_TEST_PASSED>
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

TEST_FUNC TESTerrorType_e xTestOneStepDownVoltWrapper(void)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    pmicCornerRailType_e xcoreRailVal = PMIC_INVALID_RAIL;
    uint64 ullvoltageUv = 0x0;
    uint8 *pxStringCoreRail;

    pxStringCoreRail = APPL_SAIL_Shell_gettoken(NULL);

    xcoreRailVal = prvCoreRailStringToValue((char *)pxStringCoreRail);
    if ( xcoreRailVal >= PMIC_INVALID_RAIL )
    {
        DEBUG_LOG(SAIL_ERROR,"Rail Not Supported\n\r");
    }else
    {
        if (PMIC_ERR_FLAG_SUCCESS == xPmicReadCoreRailVolt(xcoreRailVal,&ullvoltageUv))
        {
            DEBUG_LOG(SAIL_WARNING,"PMIC : Before %s Voltage : %lld uV\n\r",pxCoreRail[xcoreRailVal],ullvoltageUv);

            if( PMIC_ERR_FLAG_SUCCESS == xPmicChangeCoreRailVolt(xcoreRailVal,ullvoltageUv - prvGetOneStep(ullvoltageUv-1)))
            {
                if (PMIC_ERR_FLAG_SUCCESS == xPmicReadCoreRailVolt(xcoreRailVal,&ullvoltageUv))
                {
                    DEBUG_LOG(SAIL_WARNING,"PMIC : After %s 1 Step Down Voltage : %lld uV Success\n\r",pxCoreRail[xcoreRailVal],ullvoltageUv);
                    xRetStatus = MODULE_TEST_PASSED;
                }else
                {
                     DEBUG_LOG(SAIL_ERROR,"PMIC : After %s 1 Step Down Voltage : %lld Failed \n\r",pxCoreRail[xcoreRailVal],ullvoltageUv);
                }
            }
        }
    }

    return xRetStatus;
}


/*=========================================================================================================
 @Service name        xTestOneStepDownVoltWrapper
 @Description         xTestOneStepDownVoltWrapper is call step down voltage of cx/mx by one step
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              TESTerrorType_e < MODULE_TEST_FAILED, MODULE_TEST_PASSED>
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

TEST_FUNC static TESTerrorType_e xTestMXOneStepDownVoltWrapper(void)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    pmicCornerRailType_e xcoreRailVal = PMIC_INVALID_RAIL;
    uint64 ullvoltageUv = 0x0;
	
	xcoreRailVal = PMIC_MX_RAIL;
	
	if ( xcoreRailVal >= PMIC_INVALID_RAIL )
    {
        DEBUG_LOG(SAIL_ERROR,"Rail Not Supported\n\r");
    }else
    {
        if (PMIC_ERR_FLAG_SUCCESS == xPmicReadCoreRailVolt(xcoreRailVal,&ullvoltageUv))
        {
            DEBUG_LOG(SAIL_WARNING,"PMIC : Before %s Voltage : %lld uV\n\r",pxCoreRail[xcoreRailVal],ullvoltageUv);

            if( PMIC_ERR_FLAG_SUCCESS == xPmicChangeCoreRailVolt(xcoreRailVal,ullvoltageUv - prvGetOneStep(ullvoltageUv-1)))
            {
                if (PMIC_ERR_FLAG_SUCCESS == xPmicReadCoreRailVolt(xcoreRailVal,&ullvoltageUv))
                {
                    DEBUG_LOG(SAIL_WARNING,"PMIC : After %s 1 Step Down Voltage : %lld uV Success\n\r",pxCoreRail[xcoreRailVal],ullvoltageUv);
                    xRetStatus = MODULE_TEST_PASSED;
                }else
                {
                     DEBUG_LOG(SAIL_ERROR,"PMIC : After %s 1 Step Down Voltage : %lld Failed \n\r",pxCoreRail[xcoreRailVal],ullvoltageUv);
                }
            }
        }
    }

    return xRetStatus;
}

TEST_FUNC static TESTerrorType_e xTestCXOneStepDownVoltWrapper(void)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    pmicCornerRailType_e xcoreRailVal = PMIC_INVALID_RAIL;
    uint64 ullvoltageUv = 0x0;
	
	xcoreRailVal = PMIC_CX_RAIL;
	
	if ( xcoreRailVal >= PMIC_INVALID_RAIL )
    {
        DEBUG_LOG(SAIL_ERROR,"Rail Not Supported\n\r");
    }else
    {
        if (PMIC_ERR_FLAG_SUCCESS == xPmicReadCoreRailVolt(xcoreRailVal,&ullvoltageUv))
        {
            DEBUG_LOG(SAIL_WARNING,"PMIC : Before %s Voltage : %lld uV\n\r",pxCoreRail[xcoreRailVal],ullvoltageUv);

            if( PMIC_ERR_FLAG_SUCCESS == xPmicChangeCoreRailVolt(xcoreRailVal,ullvoltageUv - prvGetOneStep(ullvoltageUv-1)))
            {
                if (PMIC_ERR_FLAG_SUCCESS == xPmicReadCoreRailVolt(xcoreRailVal,&ullvoltageUv))
                {
                    DEBUG_LOG(SAIL_WARNING,"PMIC : After %s 1 Step Down Voltage : %lld uV Success\n\r",pxCoreRail[xcoreRailVal],ullvoltageUv);
                    xRetStatus = MODULE_TEST_PASSED;
                }else
                {
                     DEBUG_LOG(SAIL_ERROR,"PMIC : After %s 1 Step Down Voltage : %lld Failed \n\r",pxCoreRail[xcoreRailVal],ullvoltageUv);
                }
            }
        }
    }

    return xRetStatus;
}

/*=========================================================================================================
 @Service name        xTestCoreWriteVoltWrapper
 @Description         xTestCoreWriteVoltWrapper is call to Write Cx/Mx Voltage from Test Application
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              TESTerrorType_e < MODULE_TEST_FAILED, MODULE_TEST_PASSED>
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/



TEST_FUNC TESTerrorType_e xTestCoreWriteVoltWrapper(void)
{
    uint8 *pxVoltageUv;
    uint8 *pxStringCoreRail;
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint64 ullvoltageUv = 0x0;
    pmicCornerRailType_e xcoreRailVal = PMIC_INVALID_RAIL;

    pxStringCoreRail = APPL_SAIL_Shell_gettoken(NULL);

    xcoreRailVal = prvCoreRailStringToValue((char *)pxStringCoreRail);

    if ( xcoreRailVal >= PMIC_INVALID_RAIL )
    {
        DEBUG_LOG(SAIL_ERROR,"Rail Not Supported\n\r");
    }else
    {
        pxVoltageUv = APPL_SAIL_Shell_gettoken(NULL);
        ullvoltageUv = prvSailCharToLL((char *)pxVoltageUv);

        if( PMIC_ERR_FLAG_SUCCESS == xPmicChangeCoreRailVolt(xcoreRailVal , ullvoltageUv))
        {
            DEBUG_LOG(SAIL_WARNING,"PMIC : %s Set To %lld Success\n\r" ,pxCoreRail[xcoreRailVal],ullvoltageUv);
            xRetStatus = MODULE_TEST_PASSED;
        }else
        {
            DEBUG_LOG(SAIL_ERROR,"PMIC : %s Set To %lld Failed\n\r" ,pxCoreRail[xcoreRailVal],ullvoltageUv);
        }
    }

    return xRetStatus;
}

TEST_FUNC static TESTerrorType_e xTestMXCoreWriteVoltWrapper(uint64 Abs_volt_lower, uint64 Abs_volt_higher )
{
    uint8 *pxVoltageUv;
    uint8 *pxStringCoreRail;
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint64 ullvoltageUv = 0x0;
    pmicCornerRailType_e xcoreRailVal = PMIC_INVALID_RAIL;

	xcoreRailVal = PMIC_MX_RAIL;
	
	uint64 lower = ( Abs_volt_lower >> 4 ) * 10 + (Abs_volt_lower & 0xF);
    uint64 upper = ( Abs_volt_higher >> 4 ) * 10 + (Abs_volt_higher & 0xF);
	ullvoltageUv = ((lower*100)+upper)*1000;

    if ( xcoreRailVal >= PMIC_INVALID_RAIL )
    {
        DEBUG_LOG(SAIL_ERROR,"Rail Not Supported\n\r");
    }
	else
    {	
        if( PMIC_ERR_FLAG_SUCCESS == xPmicChangeCoreRailVolt(xcoreRailVal , ullvoltageUv))
        {
            DEBUG_LOG(SAIL_WARNING,"PMIC : %s Set To %lld Success\n\r" ,pxCoreRail[xcoreRailVal],ullvoltageUv);
            xRetStatus = MODULE_TEST_PASSED;
        }else
        {
            DEBUG_LOG(SAIL_ERROR,"PMIC : %s Set To %lld Failed\n\r" ,pxCoreRail[xcoreRailVal],ullvoltageUv);
        }
    }

    return xRetStatus;
}
TEST_FUNC static TESTerrorType_e xTestCXCoreWriteVoltWrapper(uint64 Abs_volt_lower, uint64 Abs_volt_higher  )
{
    uint8 *pxVoltageUv;
    uint8 *pxStringCoreRail;
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint64 ullvoltageUv = 0x0;
    pmicCornerRailType_e xcoreRailVal = PMIC_INVALID_RAIL;
	
	uint64 lower = ( Abs_volt_lower >> 4 ) * 10 + (Abs_volt_lower & 0xF);
    uint64 upper = ( Abs_volt_higher >> 4 ) * 10 + (Abs_volt_higher & 0xF);
	ullvoltageUv = ((lower*100)+upper)*1000;
	
	xcoreRailVal = PMIC_CX_RAIL;

    if ( xcoreRailVal >= PMIC_INVALID_RAIL )
    {
        DEBUG_LOG(SAIL_ERROR,"Rail Not Supported\n\r");
    }
	else
    {
        if( PMIC_ERR_FLAG_SUCCESS == xPmicChangeCoreRailVolt(xcoreRailVal , ullvoltageUv))
        {
            DEBUG_LOG(SAIL_WARNING,"PMIC : %s Set To %lld Success\n\r" ,pxCoreRail[xcoreRailVal],ullvoltageUv);
            xRetStatus = MODULE_TEST_PASSED;
        }else
        {
            DEBUG_LOG(SAIL_ERROR,"PMIC : %s Set To %lld Failed\n\r" ,pxCoreRail[xcoreRailVal],ullvoltageUv);
        }
    }

    return xRetStatus;
}

/*=========================================================================================================
 @Service name        xTestReadMxVoltWrapper
 @Description         xTestReadMxVoltWrapper is call to Read out MX voltage from TEST Application
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              TESTerrorType_e < MODULE_TEST_FAILED, MODULE_TEST_PASSED>
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

TEST_FUNC TESTerrorType_e xTestReadMxVoltWrapper(void)
{

    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint64 ullvoltageUv = 0x0U;

    if (PMIC_ERR_FLAG_SUCCESS == xPmicReadCoreRailVolt(PMIC_MX_RAIL,&ullvoltageUv))
    {
        DEBUG_LOG(SAIL_WARNING,"PMIC : MX Voltage : %lld uV Success\n\r" , ullvoltageUv);
        xRetStatus = MODULE_TEST_PASSED;
    }else
    {
        DEBUG_LOG(SAIL_ERROR,"PMIC : MX Voltage Read Failed\n\r");
        xRetStatus = MODULE_TEST_FAILED;
    }

    return xRetStatus;

}


/*=========================================================================================================
 @Service name        xTestReadCxVoltWrapper
 @Description         xTestReadCxVoltWrapper  is call to Read out CX voltage from TEST Application
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              TESTerrorType_e < MODULE_TEST_FAILED, MODULE_TEST_PASSED>
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

TEST_FUNC TESTerrorType_e xTestReadCxVoltWrapper(void)
{

    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint64 ullvoltageUv = 0x0U;

    if (PMIC_ERR_FLAG_SUCCESS == xPmicReadCoreRailVolt(PMIC_CX_RAIL,&ullvoltageUv))
    {
        DEBUG_LOG(SAIL_WARNING,"PMIC : CX Voltage : %lld uV Success\n\r" , ullvoltageUv);
        xRetStatus = MODULE_TEST_PASSED;
    }else
    {
        DEBUG_LOG(SAIL_ERROR,"PMIC : CX Voltage Read Failed\n\r");
        xRetStatus = MODULE_TEST_FAILED;
    }

    return xRetStatus;

}


/*=========================================================================================================
 @Service name        xTestWriteMxVoltWrapper
 @Description         xTestWriteMxVoltWrapper  is call to Write MX voltage from TEST Application
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              TESTerrorType_e < MODULE_TEST_FAILED, MODULE_TEST_PASSED>
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

TEST_FUNC static TESTerrorType_e x_TestWriteMxVoltWrapper(uint8 Cornervalpassed)
{

    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint8 *pxStringCorner;
/* CPR_STRIPPING_CHANGES */
    ePMICCprVoltageLevelType xcornerVal;
	xcornerVal = PMIC_CPR_VOLTAGE_LEVEL_RETENTION;
	pxStringCorner = APPL_SAIL_Shell_gettoken(NULL);
	xcornerVal = prvCornerStringToValue((char *)pxStringCorner);
	
	if (Cornervalpassed == 0x1)
	{
		xcornerVal = PMIC_CPR_VOLTAGE_LEVEL_RETENTION;
	}
	else if (Cornervalpassed == 0x2)
	{
		xcornerVal =PMIC_CPR_VOLTAGE_LEVEL_RETENTION_BIN1;
	}
	else if (Cornervalpassed == 0x3)
	{
		xcornerVal =PMIC_CPR_VOLTAGE_LEVEL_SVS_L1;
	}
	else if (Cornervalpassed == 0x4)
	{
		xcornerVal =PMIC_CPR_VOLTAGE_LEVEL_NOMINAL;
	}
	else if (Cornervalpassed == 0x5)
	{
		xcornerVal =PMIC_CPR_VOLTAGE_LEVEL_TURBO;
	}
	else if (Cornervalpassed == 0x6)
	{
		xcornerVal =PMIC_CPR_VOLTAGE_LEVEL_TURBO_L1;
	}
	else
	{
		DEBUG_LOG(SAIL_ERROR,"Invalid Corner\n\r");
	}

/* CPR_STRIPPING_CHANGES */
    if ( xcornerVal >= PMIC_CPR_VOLTAGE_LEVEL_COUNT )
    {
        DEBUG_LOG(SAIL_ERROR,"MX Voted Corner Not Supported\n\r");
    }
    else
    {
        if ( PMIC_ERR_FLAG_SUCCESS == xPmicChangeCornerVolt(PMIC_MX_RAIL , xcornerVal) )
        {
            xRetStatus = MODULE_TEST_PASSED;
        }else
        {
            xRetStatus = MODULE_TEST_FAILED;
        }
    }

    return xRetStatus;

}

/*=========================================================================================================
 @Service name        xTestWriteMxVoltWrapper
 @Description         xTestWriteMxVoltWrapper  is call to Write MX voltage from TEST Application
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              TESTerrorType_e < MODULE_TEST_FAILED, MODULE_TEST_PASSED>
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

TEST_FUNC TESTerrorType_e xTestWriteMxVoltWrapper(void)
{

    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint8 *pxStringCorner;
/* CPR_STRIPPING_CHANGES */
    ePMICCprVoltageLevelType xcornerVal = PMIC_CPR_VOLTAGE_LEVEL_RETENTION;

    pxStringCorner = APPL_SAIL_Shell_gettoken(NULL);

    xcornerVal = prvCornerStringToValue((char *)pxStringCorner);

/* CPR_STRIPPING_CHANGES */
    if ( xcornerVal >= PMIC_CPR_VOLTAGE_LEVEL_COUNT )
    {
        DEBUG_LOG(SAIL_ERROR,"MX Voted Corner Not Supported\n\r");
    }
    else
    {
        if ( PMIC_ERR_FLAG_SUCCESS == xPmicChangeCornerVolt(PMIC_MX_RAIL , xcornerVal) )
        {
            xRetStatus = MODULE_TEST_PASSED;
        }else
        {
            xRetStatus = MODULE_TEST_FAILED;
        }
    }

    return xRetStatus;

}



TEST_FUNC TESTerrorType_e xTestPmicGetResetState(void)
{
    pmicCrashDebugType_e xcrashDebug = PMIC_CRASH_PASS_INVALID;
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;

    xErrFlag = xPmicGetResetState(&xcrashDebug);

    if(xErrFlag == PMIC_ERR_FLAG_SUCCESS)
    {
        DEBUG_LOG(SAIL_WARNING,"PMIC Reset State : %s\n\r",pxCrashResetString[xcrashDebug]);
        xRetStatus = MODULE_TEST_PASSED;
    }else
    {
        DEBUG_LOG(SAIL_ERROR,"PMIC Reset Failed\n\r");
    }
    return xRetStatus;
}


/*=========================================================================================================
 @Service name        xTestWriteCxVoltWrapper
 @Description         xTestWriteCxVoltWrapper  is call to Write CX voltage from TEST Application
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              TESTerrorType_e < MODULE_TEST_FAILED, MODULE_TEST_PASSED>
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/
TEST_FUNC static TESTerrorType_e x_TestWriteCxVoltWrapper(uint8 Cornervalpassed)
{

    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
/* CPR_STRIPPING_CHANGES */ 

	ePMICCprVoltageLevelType xcornerVal;
	xcornerVal = PMIC_CPR_VOLTAGE_LEVEL_RETENTION;
	if (Cornervalpassed == 0x1)
	{
		xcornerVal = PMIC_CPR_VOLTAGE_LEVEL_RETENTION;
	}
	else if (Cornervalpassed == 0x2)
	{
		xcornerVal =PMIC_CPR_VOLTAGE_LEVEL_RETENTION_BIN1;
	}
	else if (Cornervalpassed == 0x3)
	{
		xcornerVal =PMIC_CPR_VOLTAGE_LEVEL_SVS_L1;
	}
	else if (Cornervalpassed == 0x4)
	{
		xcornerVal =PMIC_CPR_VOLTAGE_LEVEL_NOMINAL;
	}
	else if (Cornervalpassed == 0x5)
	{
		xcornerVal =PMIC_CPR_VOLTAGE_LEVEL_TURBO;
	}
	else if (Cornervalpassed == 0x6)
	{
		xcornerVal =PMIC_CPR_VOLTAGE_LEVEL_TURBO_L1;
	}
	else
	{
		DEBUG_LOG(SAIL_ERROR,"Invalid Corner\n\r");
	}
/* CPR_STRIPPING_CHANGES */
    if ( xcornerVal >= PMIC_CPR_VOLTAGE_LEVEL_COUNT )
    {
        DEBUG_LOG(SAIL_ERROR,"CX Voted Corner Not Supported\n\r");
    }
    else
    {
        if ( PMIC_ERR_FLAG_SUCCESS == xPmicChangeCornerVolt(PMIC_CX_RAIL , xcornerVal) )
        {
            xRetStatus = MODULE_TEST_PASSED;
        }else
        {
            xRetStatus = MODULE_TEST_FAILED;
        }
    }

    return xRetStatus;

}

/*=========================================================================================================
 @Service name        xTestWriteCxVoltWrapper
 @Description         xTestWriteCxVoltWrapper  is call to Write CX voltage from TEST Application
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              TESTerrorType_e < MODULE_TEST_FAILED, MODULE_TEST_PASSED>
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

TEST_FUNC TESTerrorType_e xTestWriteCxVoltWrapper(void)
{

    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint8 *pxStringCorner;
/* CPR_STRIPPING_CHANGES */
    ePMICCprVoltageLevelType xcornerVal = PMIC_CPR_VOLTAGE_LEVEL_RETENTION;

    pxStringCorner = APPL_SAIL_Shell_gettoken(NULL);

    xcornerVal = prvCornerStringToValue((char *)pxStringCorner);

/* CPR_STRIPPING_CHANGES */
    if ( xcornerVal >= PMIC_CPR_VOLTAGE_LEVEL_COUNT )
    {
        DEBUG_LOG(SAIL_ERROR,"CX Voted Corner Not Supported\n\r");
    }
    else
    {
        if ( PMIC_ERR_FLAG_SUCCESS == xPmicChangeCornerVolt(PMIC_CX_RAIL , xcornerVal) )
        {
            xRetStatus = MODULE_TEST_PASSED;
        }else
        {
            xRetStatus = MODULE_TEST_FAILED;
        }
    }

    return xRetStatus;

}

/*=========================================================================================================
 @Service name        xTestPrintRegSummary
 @Description         xTestPrintRegSummary  is call to Print Smps/Ldo Summary from TEST Application
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              TESTerrorType_e < MODULE_TEST_FAILED, MODULE_TEST_PASSED>
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

TEST_FUNC TESTerrorType_e xTestPrintRegSummary(void)
{

    TESTerrorType_e xRetStatus = MODULE_TEST_PASSED;
    uint8 ucindex = 0x0;
    uint64 ullvoltageRead = 0;
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    boolean benableStatus = FALSE;
    pmicRegulatorModeType_e mode_val = PMIC_NOT_SUPPORTED_MODE;
    char const *enableStr[] = { "off","on" };
    char const *modeStr[] = { "Auto","Npm","Invalid"};

    DEBUG_LOG(SAIL_WARNING,"====================================================================\n\r");
    DEBUG_LOG(SAIL_WARNING,"========================= LDO Summary ==============================\n\r");
    DEBUG_LOG(SAIL_WARNING,"====================================================================\n\r");
    DEBUG_LOG(SAIL_WARNING,"\n\r");
    DEBUG_LOG(SAIL_WARNING,"\n\r");

    for(ucindex = 0x0 ; ucindex < ucpmicLdoCountTest ; ucindex++)
    {
        xErrFlag = prvPmicLdoReadVoltage(ucindex,&ullvoltageRead);
        xErrFlag |= prvPmicLdoReadEnable(ucindex,&benableStatus);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            DEBUG_LOG(SAIL_WARNING,"LDO %d Failed");
            xRetStatus = MODULE_TEST_FAILED;
        }else
        {
            DEBUG_LOG(SAIL_WARNING,"LDO %d Voltage : %llduV , Enable:%s , Mode: %s\n\r",ucindex+1,ullvoltageRead,enableStr[benableStatus],modeStr[mode_val]);
        }
    }

    DEBUG_LOG(SAIL_WARNING,"====================================================================\n\r");
    DEBUG_LOG(SAIL_WARNING,"======================== SMPS Summary ==============================\n\r");
    DEBUG_LOG(SAIL_WARNING,"====================================================================\n\r");
    DEBUG_LOG(SAIL_WARNING,"\n\r");
    DEBUG_LOG(SAIL_WARNING,"\n\r");

    for(ucindex = 0x0 ; ucindex < ucpmicSmpsCountTest ; ucindex++)
    {
        xErrFlag = prvPmicSmpsReadVoltage(ucindex,&ullvoltageRead);
        xErrFlag |= prvPmicSmpsReadEnable(ucindex,&benableStatus);
        xErrFlag |= xPmicSmpsReadMode(ucindex,&mode_val);
        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
        {
            DEBUG_LOG(SAIL_ERROR,"SMPS %d Failed\n\r");
            xRetStatus = MODULE_TEST_FAILED;
        }else
        {
            DEBUG_LOG(SAIL_WARNING,"SMPS %d Voltage : %llduV , Enable:%s , Mode: %s\n\r",ucindex+1,ullvoltageRead,enableStr[benableStatus],modeStr[mode_val]);
        }
    }


    return xRetStatus;

}


/*=========================================================================================================
 @Service name        xTestPmicWrapper
 @Description         xTestPmicWrapper is call all the test module from TEST Application
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              TESTerrorType_e < MODULE_TEST_FAILED, MODULE_TEST_PASSED>
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

TEST_FUNC TESTerrorType_e xTestPmicWrapper(void)
{

    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucCustomerNVMId = 0x0;
    uint8 *find;
    uint8 ucLength = 0x0u;
    uint8 ulcpu_ID = get_curr_phys_cpu_num();
    uint8 ucLogicCustomerID = 0x0u;

    find = APPL_SAIL_Shell_gettoken(NULL);

    if ( TRUE == bSailPmicPresent() )
    {
        if(APPL_SAIL_Shell_stricmp("cx_rdt",(char*)find))
        {
            xRetStatus = xTestReadCxVoltWrapper();
        }else if (APPL_SAIL_Shell_stricmp("mx_rdt",(char*)find))
        {
            xRetStatus = xTestReadMxVoltWrapper();
        }else if (APPL_SAIL_Shell_stricmp("cx_wrt",(char*)find))
        {
            xRetStatus = xTestWriteCxVoltWrapper();
        }else if (APPL_SAIL_Shell_stricmp("mx_wrt",(char*)find))
        {
            xRetStatus = xTestWriteMxVoltWrapper();
        }else if (APPL_SAIL_Shell_stricmp("coredn",(char*)find))
        {
            xRetStatus = xTestOneStepDownVoltWrapper();
        }else if (APPL_SAIL_Shell_stricmp("coreup",(char*)find))
        {
            xRetStatus = xTestOneStepUpVoltWrapper();
        }else if (APPL_SAIL_Shell_stricmp("rstate",(char*)find))
        {
            xRetStatus = xTestPmicGetResetState();
        }else if (APPL_SAIL_Shell_stricmp("crc",(char*)find))
        {
            uint8 pData[2] = {0x11 , 0x0};
            if ( I2C_SUCCESS == xI2cWrite((uint8) PAGE_ID_0 , 0xc9, 2, pData) )
            {
                DEBUG_LOG(SAIL_INFO,"PMIC CRC Fault injection done \r\n");
            }else
            {
                DEBUG_LOG(SAIL_INFO,"PMIC CRC Fault injection failed \r\n");
            }
        }else if (APPL_SAIL_Shell_stricmp("nvm",(char*)find))
        {
            find = APPL_SAIL_Shell_gettoken(NULL);
            ucCustomerNVMId = prvSailCharToLL((char *)find);

            //Firmware update is not supported for MCU-Less part, remove the check once there is requirement/support for SW FW update (MCU-Less)
            if ( TRUE == (boolean)bSailPmicFWMCULess() )
            {
                DEBUG_LOG(SAIL_WARNING,"PMIC FW update is not supported\n\r");
                return MODULE_TEST_FAILED;
            }

            if ( ucCustomerNVMId == prvGetSAILPMICInfo(CUSTOMER_NVMID) ) // No Need to update PMIC FW if asked nvm version already present in device
            {
                DEBUG_LOG(SAIL_WARNING,"PMIC FW Version is already %d\n\r",ucCustomerNVMId)
                return MODULE_TEST_PASSED;
            }

            ucLogicCustomerID = ucCustomerNVMId;

            #ifdef monaco
                ucLogicCustomerID = ucCustomerNVMId/3; // specific for monaco
            #endif

            xErrFlag = prvPmicNVMFrameUpdate(ucLogicCustomerID-1);

            switch(xErrFlag)
            {
                case PMIC_ERR_FLAG_SUCCESS:
                    xRetStatus = MODULE_TEST_PASSED;
                    DEBUG_LOG(SAIL_WARNING,"PMIC FW updated to %d success\n\r",ucCustomerNVMId);
                    DEBUG_LOG(SAIL_WARNING,"Do Power Cycle!!!\n\r");
                    while(1);
                break;

                case PMIC_ERR_NVM_UPDATE_FAILED:
                    DEBUG_LOG(SAIL_ERROR,"PMIC FW updated to %d Failed in between\n\r",ucCustomerNVMId);
                    DEBUG_LOG(SAIL_ERROR,"Do Power Cycle and Retry again!!!\n\r");
                break;

                case PMIC_ERR_OUT_OF_BOUNDARY:
                    DEBUG_LOG(SAIL_ERROR,"PMIC FW %d is not supported\n\r",ucCustomerNVMId)
                break;
                
                default:
                    DEBUG_LOG(SAIL_ERROR,"PMIC FW update to %d failed\n\r",ucCustomerNVMId);
            }

        }else if (APPL_SAIL_Shell_stricmp("regsum",(char*)find))
        {
            xRetStatus = xTestPrintRegSummary();
        }else if (APPL_SAIL_Shell_stricmp("corewrite",(char*)find))
        {
            xRetStatus = xTestCoreWriteVoltWrapper();
        }else if(APPL_SAIL_Shell_stricmp("info",(char*)find))
        {
            if ( PMIC_ERR_FLAG_SUCCESS == prvPmicInfo(UARTFRAMEWORK,ulcpu_ID,NULL,&ucLength) )
            {
                xRetStatus = MODULE_TEST_PASSED;
            }
        }else if(APPL_SAIL_Shell_stricmp("bist",(char*)find))
        {
            if ( PMIC_ERR_FLAG_SUCCESS == xPmicEnableRunTimeBist() )
            {
                DEBUG_LOG(SAIL_WARNING,"RunTime BIST Pass \n\r");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_ERROR,"RunTime BIST FAIL \n\r");
            }
        }
        else if (APPL_SAIL_Shell_stricmp("test",(char*)find))
        {
            if(PMIC_ERR_FLAG_SUCCESS == prvPmicTest())
            {
                xRetStatus = MODULE_TEST_PASSED;
            }else
            {
                DEBUG_LOG(SAIL_ERROR,"prvPmicTest Failed!!!\n\r")
            }

        }else if (APPL_SAIL_Shell_stricmp("debug",(char*)find))
        {
            ucPmicDebugMode = PMIC_DEBUG_ON;
            DEBUG_LOG(SAIL_INFO,"[PMIC] PMIC DEBUG Mode Entered. Now PMIC will be collected and dumped to SPINOR!!!\n\r");
        }
        else if (APPL_SAIL_Shell_stricmp("log",(char*)find))
        {
            xRetStatus = prvPmiclogPrint();
         
        }else if (APPL_SAIL_Shell_stricmp("endrv",(char*)find))
        {
            xRetStatus = prvEnableDrv();
        }else if (APPL_SAIL_Shell_stricmp("extwdg",(char*)find))
        {
            xRetStatus = xTestExtWdgWrapper();
        }
        else
        {
            DEBUG_LOG(SAIL_ERROR,"PMIC CMD NOT FOUND!!!\n\r")
        }
    }else
    {
        DEBUG_LOG(SAIL_ERROR,"Test Cmd Invalid!!\n\r");
        DEBUG_LOG(SAIL_ERROR,"SAIL PMIC Not Found\n\r");
    }


    return xRetStatus;

}


/*=========================================================================================================
**                                        Local function definitions                                     **
=========================================================================================================*/


/*=========================================================================================================
 @Service name        prvEnableDrv
 @Description         prvEnableDrv is used to pull up/down enable drv pin
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              TESTerrorType_e
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

TEST_FUNC static TESTerrorType_e prvEnableDrv( void )
{
    uint8 *find;
    TESTerrorType_e xRetStatus = MODULE_TEST_PASSED;

    find = APPL_SAIL_Shell_gettoken(NULL);

    if(APPL_SAIL_Shell_stricmp("low",(char*)find))
    {
        if (PMIC_ERR_FLAG_SUCCESS != xPmicConfigureEnableDrvPin(PMIC_DISABLE))
        {
            DEBUG_LOG(SAIL_ERROR,"xPmicConfigureEnableDrvPin low Failed\n\r");
            xRetStatus = MODULE_TEST_FAILED;
        }else
        {
            DEBUG_LOG(SAIL_WARNING,"xPmicConfigureEnableDrvPin low Passed\n\r");
        }
    }else if(APPL_SAIL_Shell_stricmp("high",(char*)find))
    {
        if (PMIC_ERR_FLAG_SUCCESS != xPmicConfigureEnableDrvPin(PMIC_ENABLE))
        {
            DEBUG_LOG(SAIL_ERROR,"xPmicConfigureEnableDrvPin High Failed\n\r");
            xRetStatus = MODULE_TEST_FAILED;
        }else
        {
            DEBUG_LOG(SAIL_WARNING,"xPmicConfigureEnableDrvPin High Passed\n\r");
        }
    }else
    {
        DEBUG_LOG(SAIL_ERROR,"xPmicConfigureEnableDrvPin Invalid Cmd\n\r");
    }


    return xRetStatus;
}


/*=========================================================================================================
 @Service name        prvPmiclogPrint
 @Description         prvPmiclogPrint is used to print pmic error logs on console
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              TESTerrorType_e
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

TEST_FUNC static TESTerrorType_e prvPmiclogPrint( void )
{
    TESTerrorType_e xRetStatus = MODULE_TEST_PASSED;
    spinor_handle_t handle = NULL;
    SPINOR_STATUS xspinorReturn = SPINOR_DEVICE_OK_NOT_DONE;
    uint8 ucCountIndex = 0x0u;
    uint32 ullocalbyteCount = 0x0;
    uint32 ulocallbyteoffset = 0x0;
    spinorMemInfoType el1_nor_info = {0};
    int Index = 0x0u;
    pmicDebugInfoHeaderType xPmicHeaderInfo = {0};
    pmicErrType xPmicErrorData = {0};

    xspinorReturn = spinorEl1Open(&handle,SPINOR_USER_TYPE_EL1);

    if( xspinorReturn != SPINOR_DEVICE_DONE || handle == NULL)
    {
        DEBUG_LOG(SAIL_ERROR,"[PMIC]:Open handle failed\r\n");
        return MODULE_TEST_FAILED;
    }

    xspinorReturn = spinorEl1GetMemInfo ( handle, &el1_nor_info );
    if( xspinorReturn != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"[PMIC]:GetMemInfo failed \n\r");
        xRetStatus = MODULE_TEST_FAILED;
        goto ErrSPINOR;
    }

    xspinorReturn = spinorEl1GetGptPartitionInfo( handle, "5fd6ab83-6d6a-48ac-8d74-4d743d15a0b1", &ulocallbyteoffset, &ullocalbyteCount);
    if( xspinorReturn != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"[PMIC]:GetGptPartitionInfo failed \n\r");
        xRetStatus = MODULE_TEST_FAILED;
        goto ErrSPINOR;
    }

    xspinorReturn = spinorEl1Read ( handle, ulocallbyteoffset, sizeof(pmicDebugInfoHeaderType), &xPmicHeaderInfo);
    if( xspinorReturn != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"[PMIC]:SPINOR Read failed \n\r");
        xRetStatus = MODULE_TEST_FAILED;
        goto ErrSPINOR;
    }

    if ( xPmicHeaderInfo.magicNumber == PMIC_MAGIC_NUMBER && xPmicHeaderInfo.magicCRC == PMIC_MAGIC_CRC_NUMBER )
    {
		
		Index = GetPMICErrorIndex( &xPmicHeaderInfo );
        if ( Index == 0 ) // In case of no Error is present then log it on uart console
        {
           xRetStatus =  MODULE_TEST_FAILED;
        }else
		{
			Index = Index- 1;
		}

        if ( Index >= MAX_PMIC_ERROR_INDEX )
        {
            DEBUG_LOG(SAIL_WARNING,"[PMIC]:PMIC Error Index out of Range CurrentIndex:%d\r\n",Index);
        }else if ( MODULE_TEST_FAILED ==  xRetStatus)
        {
            DEBUG_LOG(SAIL_WARNING,"[PMIC]:Fault Info Not Found\r\n");
        }
        else
        {
            DEBUG_LOG(SAIL_WARNING,"[PMIC]:Current Index %d\r\n",Index);
            xspinorReturn = spinorEl1Read ( handle, ulocallbyteoffset+(FIRST_BLOCK_PMIC_ERROR*sizeof(uint8))+(Index*sizeof(pmicErrType)), sizeof(pmicErrType), &xPmicErrorData);
            if( xspinorReturn != SPINOR_DEVICE_DONE )
            {
                DEBUG_LOG(SAIL_ERROR,"[PMIC]:SPINOR Read failed \n\r");
                xRetStatus = MODULE_TEST_FAILED;
                goto ErrSPINOR;
            }
            DEBUG_LOG(SAIL_WARNING,"[PMIC]:ucFSMdata:0x%x wdErrStatus:0x%x  ESM:0x%x ReadBackErr:0x%x CommErr:0x%x \n\r"\
                        "SevereErr:0x%x ModerateErr:0x%x Misc:0x%x Startup:0x%x \n\rGPIO_Data:0x%x GPIO1_8:0x%x\n\r"\
                        "LDO_DATA:0x%x VMON:0x%x LDO3_4:0x%x LDO1_2:0x%x\n\rBUCK_DATA:0x%x Buck5:0x%x Buck3_4:0x%x Buck1_2:0x%x\r\n",
                        xPmicErrorData.FSM_ERR_INT.ErrInfo[0],
                        xPmicErrorData.FSM_ERR_INT.ErrInfo[4],
                        xPmicErrorData.FSM_ERR_INT.ErrInfo[3],
                        xPmicErrorData.FSM_ERR_INT.ErrInfo[2],
                        xPmicErrorData.FSM_ERR_INT.ErrInfo[1],
                        xPmicErrorData.SEVERE_ERR_INT.ErrInfo[0],
                        xPmicErrorData.MODERATE_ERR_INT.ErrInfo[0],
                        xPmicErrorData.MISC_INT.ErrInfo[0],
                        xPmicErrorData.STARTUP_INT.ErrInfo[0],
                        xPmicErrorData.GPIO_INT.ErrInfo[0],
                        xPmicErrorData.GPIO_INT.ErrInfo[1],
                        xPmicErrorData.LDO_VMON_INT.ErrInfo[0],
                        xPmicErrorData.LDO_VMON_INT.ErrInfo[3],
                        xPmicErrorData.LDO_VMON_INT.ErrInfo[2],
                        xPmicErrorData.LDO_VMON_INT.ErrInfo[1],
                        xPmicErrorData.BUCK_INT.ErrInfo[0],
                        xPmicErrorData.BUCK_INT.ErrInfo[3],
                        xPmicErrorData.BUCK_INT.ErrInfo[2],
                        xPmicErrorData.BUCK_INT.ErrInfo[1]);
        }
    }else
    {
        DEBUG_LOG(SAIL_WARNING,"[PMIC]:Pmic log is Empty\r\n");
    }

    ErrSPINOR:
    (void) spinorEl1Close(handle);

    return xRetStatus;
}

/*=========================================================================================================
 @Service name        prvPmicInfo
 @Description         prvPmicInfo is used to print PMIC FW Version info on Uart.
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              pmicErrFlagType_e
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

TEST_FUNC static pmicErrFlagType_e prvPmicInfo( TestCaseType TCType, uint8 cpu_id , uint8 *DataBuff , uint8 *ucLength)
{

    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 ucdevRev = 0x0;
    uint8 ucnvmCode1 = 0x0;
    uint8 ucnvmCode2 = 0x0;
    uint8 uccustomerNvmId = 0x0;

    xErrFlag = prvPmicCommReadByte(PAGE_ID_0, HWIO_PMIC(DEV_REV),&ucdevRev);
    xErrFlag |= prvPmicCommReadByte(PAGE_ID_0, HWIO_PMIC(NVM_CODE_1),&ucnvmCode1);
    xErrFlag |= prvPmicCommReadByte(PAGE_ID_0, HWIO_PMIC(NVM_CODE_2),&ucnvmCode2);
    xErrFlag |= prvPmicCommReadByte(PAGE_ID_0, HWIO_PMIC(CUSTOMER_NVM_ID_REG),&uccustomerNvmId);

    if(TCType == UARTFRAMEWORK)
    {
        DEBUG_LOG(SAIL_WARNING,"PMICFW Version 0x%x, DeviceId 0x%x, nvmCode1 0x%x, nvmCode2 0x%x \n\r",uccustomerNvmId,
                        ucdevRev,ucnvmCode1,ucnvmCode2);
    }
    else if(TCType ==DVFRAMEWORK)
    {
    	if((ucdevRev != 0x82) || (xErrFlag != PMIC_ERR_FLAG_SUCCESS))
    	{
    		DebugPrint_DVTask(DVTASK_FAILED,1+6);
    	}
    }else if (TCType == MBFRAMEWORK )
    {
        DataBuff[0] = ucnvmCode2;
        DataBuff[1] = uccustomerNvmId;
        *ucLength = *ucLength + 2u;
    }

    return xErrFlag;
}



/*=========================================================================================================
 @Service name        prvSailCharToLL
 @Description         prvSailCharToLL is used to convert string to int i.e. '674' to 674
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              char to int value <uint64>
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

TEST_FUNC static uint64 prvSailCharToLL(char *str)
{
    uint64 ullresult = 0x0u;
    uint8 ucIndex = 0x0u;

    for( ucIndex = 0x0u ; str[ucIndex]!= '\0' ; ucIndex++)
    {
        ullresult = ullresult*10u + (str[ucIndex]-'0');
    }

    return ullresult;
}




/*=========================================================================================================
 @Service name        prvPmicTest
 @Description         prvPmicTest is used to call test api to test entire PMIC module
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              pmicErrFlagType_e
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/


TEST_FUNC static pmicErrFlagType_e prvPmicTest(void)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    ucnumOFTestCases = 0x0u;


    // Voltage Monitor need to be disabled before SAIL_CX/SAIL_MX are being scaled

    if ( PMIC_ERR_FLAG_SUCCESS != prvDisableMon(VOLT_MON))
    {
        DEBUG_LOG(SAIL_ERROR,"[PMIC] :VOLT_MON Disable Failed\n\r");
        return PMIC_ERR_TEST_MODULE_FAILED;
    }

    // Clock Monitor need to be disabled before SAIL_CX/SAIL_MX are being scaled
    if ( PMIC_ERR_FLAG_SUCCESS != prvDisableMon(CLOCK_MON))
    {
        DEBUG_LOG(SAIL_ERROR,"[PMIC] :CLOCK_MON Disable Failed\n\r");  
        return PMIC_ERR_TEST_MODULE_FAILED;
    }

    DEBUG_LOG(SAIL_WARNING,">>>>>>  Pmic Test Cases Started   <<<<<<<\n\r");

    if (PMIC_ERR_FLAG_SUCCESS != prvPmicCrashResetTest())
    {
        xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
        goto pmic_test_exit;
    }

    if ( PMIC_ERR_FLAG_SUCCESS != prvPmicSmpsLdoTest())
    {
        xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
        goto pmic_test_exit;
    }

    if ( PMIC_ERR_FLAG_SUCCESS != prvPmicCxMxScalingTest())
    {
        xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
        goto pmic_test_exit;
    }

    if ( PMIC_ERR_FLAG_SUCCESS != prvPmicGenericAPITest())
    {
        xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
        goto pmic_test_exit;
    }

    pmic_test_exit:
    
    if( pmicTotalTestCase == ucnumOFTestCases )
    {
        DEBUG_LOG( SAIL_WARNING, "[PMIC tests Passed]\r\n" );
    }
    else
    {
        DEBUG_LOG( SAIL_ERROR, "[PMIC tests Failed]\r\n" );
    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvPmicCrashResetTest
 @Description         prvPmicCrashResetTest is used to test all crash debug related functions exposed
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              pmicErrFlagType_e
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/


TEST_FUNC static pmicErrFlagType_e prvPmicCrashResetTest(void)
{

    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    pmicCrashDebugType_e xcrashDebug = PMIC_CRASH_PASS_0;
    pmicCrashDebugType_e xreadBackCrashDebug = PMIC_CRASH_PASS_INVALID;

    for ( xcrashDebug = PMIC_CRASH_PASS_0 ; xcrashDebug < PMIC_CRASH_PASS_INVALID ; xcrashDebug++ )
    {
        xErrFlag = xPmicSetResetState(xcrashDebug);
        xErrFlag |= xPmicGetResetState(&xreadBackCrashDebug);

        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag || xcrashDebug !=  xreadBackCrashDebug)
    {
            DEBUG_LOG(SAIL_ERROR,"prvPmicCrashResetTest Failed %s\n\r",pxCrashResetString[xcrashDebug]);
        xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
        goto pmic_test_exit;
    }else
    {
        ucnumOFTestCases++;
            DEBUG_LOG(SAIL_WARNING,"[TC_PMIC_%03d] : prvPmicCrashResetTest %s passed\n\r",ucnumOFTestCases,pxCrashResetString[xcrashDebug]);
    }
    }

    pmic_test_exit:
    return xErrFlag;

}


/*=========================================================================================================
 @Service name        prvPmicSmpsLdoTest
 @Description         prvPmicSmpsLdoTest is used to test all SMPS/LDO API exposed.
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              pmicErrFlagType_e
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/



TEST_FUNC static pmicErrFlagType_e prvPmicSmpsLdoTest(void)
{

    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS; 
    uint16 usvoltage = 0x0;
    uint8 ucsmpsCount = 0x0; 
    boolean benableStatus = FALSE;
    uint64 ullvoltageRead = 0;

    for( uint8 ucindex = 0 ; ucindex < ucpmicLdoCountTest ; ucindex++ )
    {

        if ( PMIC_ACCESS_DISALLOWED == pxpmicLdoTest[ucindex].AccessAllowed )
            continue;
        if ( pxpmicLdoTest[ucindex].AlwaysOn != PMIC_ALWAYS_ON )
        {

        xErrFlag  =  xPmicLdoWriteEnable(ucindex , PMIC_DISABLE);
        xErrFlag |=  prvPmicLdoReadEnable(ucindex , &benableStatus);
            vFreeRTOSTaskDelay(25u);
        if(PMIC_DISABLE != benableStatus || PMIC_ERR_FLAG_SUCCESS != xErrFlag)
        {
                DEBUG_LOG(SAIL_ERROR,"LDO %d Disable Failed\n\r",ucindex+1);
            xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
            goto pmic_test_exit;
            }else
            {
                ucnumOFTestCases++;
                DEBUG_LOG(SAIL_WARNING,"[TC_PMIC_%03d] : LDO %d Disable passed\n\r",ucnumOFTestCases,ucindex+1);
            }
        }

        xErrFlag  =  xPmicLdoWriteEnable(ucindex , PMIC_ENABLE);
        xErrFlag |=  prvPmicLdoReadEnable(ucindex , &benableStatus);
        vFreeRTOSTaskDelay(25u);
        if( PMIC_ENABLE != benableStatus || PMIC_ERR_FLAG_SUCCESS != xErrFlag)
        {
            DEBUG_LOG(SAIL_ERROR,"LDO %d Enable Failed\n\r",ucindex+1);
            xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
            goto pmic_test_exit;
        }else
        {
            ucnumOFTestCases++;
            DEBUG_LOG(SAIL_WARNING,"[TC_PMIC_%03d] : LDO %d Enable passed\n\r",ucnumOFTestCases,ucindex+1);
        }



        for( uint8 ucarrayIndex = 0; ucarrayIndex < MAX_SIZE ; ucarrayIndex++)
        {

            usvoltage = uspmicLdo[ucarrayIndex];

            xErrFlag = prvPmicLdoWriteVoltage(ucindex,usvoltage*1000U);

            xErrFlag |= prvPmicLdoReadVoltage(ucindex,&ullvoltageRead);
            vFreeRTOSTaskDelay(25u);

            if( PMIC_ERR_FLAG_SUCCESS != xErrFlag || ullvoltageRead != usvoltage*1000U )
            {
                DEBUG_LOG(SAIL_ERROR,"LDO %d Voltage : %duV Failed\n\r",ucindex+1,usvoltage*1000U);
                xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
            goto pmic_test_exit;
            }else
            {
                ucnumOFTestCases++;
                DEBUG_LOG(SAIL_WARNING,"[TC_PMIC_%03d] : LDO %d Voltage : %duV passed\n\r",ucnumOFTestCases,ucindex+1,usvoltage*1000U);
            }
        }
    } 

    for( uint8 ucindex = 0 ; ucindex < ucpmicSmpsCountTest ; ucindex++ )
    {
        pmicRegulatorModeType_e mode_val;

        if ( PMIC_ACCESS_DISALLOWED == pxpmicSmpsTest[ucindex].AccessAllowed || 0x2 == ucindex || 0x3 == ucindex ) // Skip the voltage scaling if rail is mx/cx/ or disallowed from SW
            continue;

        if ( PMIC_ALWAYS_ON != pxpmicSmpsTest[ucindex].AlwaysOn )
        {
        xErrFlag =  prvPmicSmpsWriteEnable(ucindex , PMIC_DISABLE);
        xErrFlag |=  prvPmicSmpsReadEnable(ucindex , &benableStatus);
        if( PMIC_DISABLE != benableStatus || PMIC_ERR_FLAG_SUCCESS != xErrFlag)
        {
                DEBUG_LOG(SAIL_ERROR,"SMPS %d disable Failed\n\r",ucindex+1);
            xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
            goto pmic_test_exit;
            }else
            {
                ucnumOFTestCases++;
                DEBUG_LOG(SAIL_WARNING,"[TC_PMIC_%03d] : SMPS %d disable passed\n\r",ucnumOFTestCases,ucindex+1);
        }
        }

        xErrFlag =  prvPmicSmpsWriteEnable(ucindex , PMIC_ENABLE);
        xErrFlag |=  prvPmicSmpsReadEnable(ucindex , &benableStatus);
        if( PMIC_ENABLE != benableStatus || PMIC_ERR_FLAG_SUCCESS != xErrFlag)
        {
            DEBUG_LOG(SAIL_ERROR,"SMPS %d enable Failed\n\r",ucindex+1);
            xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
            goto pmic_test_exit;
        }else
        {
            ucnumOFTestCases++;
            DEBUG_LOG(SAIL_WARNING,"[TC_PMIC_%03d] : SMPS %d enable passed\n\r",ucnumOFTestCases,ucindex+1);
        }

        vFreeRTOSTaskDelay(25u);

        xErrFlag =  xPmicSmpsWriteMode(ucindex , PMIC_FORCED_NPM_MODE);
        xErrFlag |=  xPmicSmpsReadMode(ucindex , &mode_val);
        if(mode_val != PMIC_FORCED_NPM_MODE || PMIC_ERR_FLAG_SUCCESS != xErrFlag)
        {
            DEBUG_LOG(SAIL_ERROR,"SMPS %d Mode:NPM Failed\n\r",ucindex+1);
            xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
            goto pmic_test_exit;
        }else
        {
            ucnumOFTestCases++;
            DEBUG_LOG(SAIL_WARNING,"[TC_PMIC_%03d] : SMPS %d Mode:NPM passed\n\r",ucnumOFTestCases,ucindex+1);
        }

        vFreeRTOSTaskDelay(25u);

        xErrFlag =  xPmicSmpsWriteMode(ucindex , PMIC_AUTO_MODE);
        xErrFlag |=  xPmicSmpsReadMode(ucindex , &mode_val);
        if(mode_val != PMIC_AUTO_MODE || PMIC_ERR_FLAG_SUCCESS != xErrFlag)
        {
            DEBUG_LOG(SAIL_ERROR,"SMPS %d Mode:Auto Failed\n\r",ucindex+1);
            xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
            goto pmic_test_exit;
        }else
        {
            ucnumOFTestCases++;
            DEBUG_LOG(SAIL_WARNING,"[TC_PMIC_%03d] : SMPS %d Mode:Auto passed\n\r",ucnumOFTestCases,ucindex+1);
        }


        for(uint8 ucarrayIndex = 0 ; ucarrayIndex < MAX_SIZE ; ucarrayIndex++)
        {
            usvoltage = uspmicSmps[ucarrayIndex];

            xErrFlag = prvPmicSmpsWriteVoltage(ucindex , usvoltage*1000U);

            xErrFlag |= prvPmicSmpsReadVoltage(ucindex,&ullvoltageRead);

            vFreeRTOSTaskDelay(25u);

            if( PMIC_ERR_FLAG_SUCCESS != xErrFlag || ullvoltageRead != usvoltage*1000U )
            {
                DEBUG_LOG(SAIL_ERROR,"SMPS %d Voltage:%duV Failed\n\r",ucindex+1,usvoltage*1000U);
                xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
                goto pmic_test_exit;
            }else
            {
                ucnumOFTestCases++;
                DEBUG_LOG(SAIL_WARNING,"[TC_PMIC_%03d] : SMPS %d Voltage:%duV passed\n\r",ucnumOFTestCases,ucindex+1,usvoltage*1000U);
            }
            
        }
    }

    for( uint8 ucindex = 0  ;  ucindex < MAX_SIZE-1 ; ucindex++)
    {
        xErrFlag = prvPmicSmpsWriteVoltage(PMIC_REG_4 , uspmicSmpsVolt[ucindex]*1000U);

        xErrFlag |= prvPmicSmpsReadVoltage(PMIC_REG_4, &ullvoltageRead);

        vFreeRTOSTaskDelay(25u);

        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag || ullvoltageRead != uspmicSmpsVoltRead[ucindex]*1000U)
        {
            DEBUG_LOG(SAIL_ERROR,"SMPS:4 Voltage:%duV Failed\n\r",  uspmicSmpsVolt[ucindex]*1000U);
            xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
            goto pmic_test_exit;
        }else
        {
                ucnumOFTestCases++;
            DEBUG_LOG(SAIL_WARNING,"[TC_PMIC_%03d] : SMPS:4 Voltage:%duV passed\n\r",ucnumOFTestCases,uspmicSmpsVoltRead[ucindex]*1000U);
        }

    }

    pmic_test_exit:
    return xErrFlag;
}


/*=========================================================================================================
 @Service name        prvPmicCxMxScalingTest
 @Description         prvPmicCxMxScalingTest is used to test voltage scaling of MX/CX
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              pmicErrFlagType_e
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/


TEST_FUNC static pmicErrFlagType_e prvPmicCxMxScalingTest(void)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint64 ullvoltageRead = 0;

/* CPR_STRIPPING_CHANGES */
     for( ePMICCprVoltageLevelType xcornerVal = PMIC_CPR_VOLTAGE_LEVEL_NOMINAL ; xcornerVal < PMIC_CPR_VOLTAGE_LEVEL_COUNT ; xcornerVal++ )
    {
        ullvoltageRead = 0;

        xErrFlag = xPmicChangeCornerVolt( PMIC_MX_RAIL ,xcornerVal);

        xErrFlag |= xPmicReadCoreRailVolt(PMIC_MX_RAIL ,&ullvoltageRead);

        if( PMIC_ERR_FLAG_SUCCESS != xErrFlag || ullvoltageRead != psmxVoltagePlanTest[xcornerVal]*1000U)
    {
            xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
            goto pmic_test_exit;
        }else
        {
            ucnumOFTestCases++;
            DEBUG_LOG(SAIL_WARNING,"[TC_PMIC_%03d] : %s Set to %s passed\n\r",ucnumOFTestCases,pxCoreRail[PMIC_MX_RAIL],pxStringConversion[xcornerVal]);
    }

        xErrFlag = xPmicChangeCornerVolt( PMIC_CX_RAIL ,xcornerVal);

        xErrFlag |= xPmicReadCoreRailVolt(PMIC_CX_RAIL ,&ullvoltageRead);

        if( PMIC_ERR_FLAG_SUCCESS != xErrFlag || ullvoltageRead != pscxVoltagePlanTest[xcornerVal]*1000U)
        {
            xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
            goto pmic_test_exit;
        }else
        {
            ucnumOFTestCases++;
            DEBUG_LOG(SAIL_WARNING,"[TC_PMIC_%03d] : %s Set to %s passed\n\r",ucnumOFTestCases,pxCoreRail[PMIC_CX_RAIL],pxStringConversion[xcornerVal]);
        }
    }


    for( uint8 ucindex = 0  ;  ucindex < MAX_SIZE-1 ; ucindex++)
    {
        xErrFlag = xPmicChangeCoreRailVolt(PMIC_CX_RAIL , uspmicSmpsVolt[ucindex]*1000U);
		
		vFreeRTOSTaskDelay(25u);

        xErrFlag |= prvPmicSmpsReadVoltage(PMIC_REG_3, &ullvoltageRead);

        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag || ullvoltageRead != uspmicSmpsVoltRead[ucindex]*1000U)
        {
            DEBUG_LOG(SAIL_ERROR,"%s Set to %duV Failed\n\r",pxCoreRail[PMIC_CX_RAIL],uspmicSmpsVoltRead[ucindex]*1000U);
            xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
            goto pmic_test_exit;
        }else
        {
            ucnumOFTestCases++;
            DEBUG_LOG(SAIL_WARNING,"[TC_PMIC_%03d] : %s Set to Voltage:%duV passed\n\r",ucnumOFTestCases,pxCoreRail[PMIC_CX_RAIL],uspmicSmpsVoltRead[ucindex]*1000U);
        }

    }

    for( uint8 ucindex = 0  ;  ucindex < MAX_SIZE-1 ; ucindex++)
    {
        xErrFlag = xPmicChangeCoreRailVolt(PMIC_MX_RAIL , uspmicSmpsVolt[ucindex]*1000U);
		
		vFreeRTOSTaskDelay(25u);

        xErrFlag |= prvPmicSmpsReadVoltage(PMIC_REG_4, &ullvoltageRead);

        if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag || ullvoltageRead != uspmicSmpsVoltRead[ucindex]*1000U)
        {
            DEBUG_LOG(SAIL_ERROR,"%s Set to %duV Failed\n\r",pxCoreRail[PMIC_MX_RAIL],uspmicSmpsVoltRead[ucindex]*1000U);
                xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
                goto pmic_test_exit;
        }else
        {
            ucnumOFTestCases++;
            DEBUG_LOG(SAIL_WARNING,"[TC_PMIC_%03d] : %s Set to Voltage:%duV  passed\n\r",ucnumOFTestCases,pxCoreRail[PMIC_MX_RAIL],uspmicSmpsVoltRead[ucindex]*1000U);
        }
    }

    pmic_test_exit:
    return xErrFlag;

}

/*=========================================================================================================
 @Service name        prvStriCmp
 @Description         prvStriCmp is used to compare two string
 @param[in]           str1 --> Passed by user could be with capital or small letters
                      str2 --> string should be always with small letters
 @param[out]          NA
 @param[in, out]      NA
 @return              1  --> if strings are matching
                      0  --> if strings are not matching
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

TEST_FUNC uint8 prvStriCmp(char const *str1, char const *str2)
{
    uint32 retval = 0U;
    uint32 temp = 0U;
    int res = 0;

    if((str1 != NULL) && (str2 != NULL))
    {
        /* loop limit is not req. as str1 is hard coded string test cmd */
        while(*str1!='\0')
        {
            temp = *str2;

            if((temp >= 'A') && (temp <= 'Z'))
            temp = temp + 32;

            res = *str1 - temp;

            if(res != 0U)
            {
                retval = 0U;
                break;
            }
            str1++;
            str2++;
        }

        if(*str1 == '\0')
        {
            retval = 1U;
        }
    }
    /* compare success ret 1 else 0 */
    return (uint8)retval;
}

/*=========================================================================================================
 @Service name        prvGetOneStep
 @Description         prvGetOneStep is used to get step size based on operating voltage
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              step size in micro voltage <uint64>
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

TEST_FUNC static uint64 prvGetOneStep(uint64 ullvoltageUv)
{
    uint64 ullStepVal = 0x0;

    if( ullvoltageUv >= 300000u && ullvoltageUv < 600000u )
    {

        ullStepVal =  20000u; // 20mV

    }else if( ullvoltageUv >= 600000u && ullvoltageUv < 1100000u )
    {

        ullStepVal =  5000u; // 5mV

    }else if( ullvoltageUv >= 1100000u && ullvoltageUv < 1660000u )
    {

        ullStepVal =  10000u; // 10mV

    }else if( ullvoltageUv >= 1660000u && ullvoltageUv <= 3340000u )
    {

        ullStepVal = 20000u; // 20mV

    }

    return ullStepVal;
}

/*=========================================================================================================
 @Service name        prvCornerStringToValue
 @Description         prvCornerStringToValue is used to convert corner string to enum value
 @param[in]           pxStringCorner < RETENTION .. TURBO_L1>
 @param[out]          NA
 @param[in, out]      NA
 @return              eCprVoltageLevelType
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

/* CPR_STRIPPING_CHANGES */
TEST_FUNC static ePMICCprVoltageLevelType prvCornerStringToValue( char *pxStringCorner)
{
    ePMICCprVoltageLevelType xcornerVal = PMIC_CPR_VOLTAGE_LEVEL_RETENTION;

    for( xcornerVal = PMIC_CPR_VOLTAGE_LEVEL_RETENTION ; xcornerVal < PMIC_CPR_VOLTAGE_LEVEL_COUNT ; xcornerVal++ )
    {
        if ( prvStriCmp(pxStringCorner,pxStringConversion[xcornerVal]))
    {
            break;
    }
    }

    return xcornerVal;
}

/*=========================================================================================================
 @Service name        prvCoreRailStringToValue
 @Description         prvCornerStringToValue is used to convert corner string to enum value
 @param[in]           pxStringCorner < RETENTION .. TURBO_L1>
 @param[out]          NA
 @param[in, out]      NA
 @return              eCprVoltageLevelType
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

TEST_FUNC static pmicCornerRailType_e prvCoreRailStringToValue( char *pxStringCoreRail)
{
    pmicCornerRailType_e xcoreRailVal = PMIC_CX_RAIL;

    for( xcoreRailVal = PMIC_CX_RAIL ; xcoreRailVal < PMIC_INVALID_RAIL ; xcoreRailVal++ )
    {
        if ( prvStriCmp(pxStringCoreRail,pxCoreRail[xcoreRailVal]))
        {
            break;
        }
    }

    return xcoreRailVal;
}


/*=========================================================================================================
 @Service name        prvPmicGenericAPITest
 @Description         prvPmicGenericAPITest is used to call Generic APIs exposed
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              pmicErrFlagType_e
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/



TEST_FUNC static pmicErrFlagType_e prvPmicGenericAPITest(void)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    pmicErrType xpmicErrorData = {0};

    if (PMIC_ERR_FLAG_SUCCESS != xPmicConfigureEnableDrvPin(PMIC_ENABLE))
    {
        DEBUG_LOG(SAIL_ERROR,"[TC_PMIC_%03d] : xPmicConfigureEnableDrvPin Failed\n\r",ucnumOFTestCases);
        xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
        goto pmic_test_exit;
    }else
    {
        ucnumOFTestCases++;
        DEBUG_LOG(SAIL_WARNING,"[TC_PMIC_%03d] : xPmicConfigureEnableDrvPin Passed\n\r",ucnumOFTestCases);
    }

    #if 0
        if (PMIC_ERR_FLAG_SUCCESS != xPmicEnableRunTimeBist())
        {
            DEBUG_LOG(SAIL_ERROR,"[TC_PMIC_%03d] : xPmicEnableRunTimeBist Failed\n\r",ucnumOFTestCases);
            xErrFlag = PMIC_ERR_TEST_MODULE_FAILED;
            goto pmic_test_exit;
        }else
        {
            ucnumOFTestCases++;
            DEBUG_LOG(SAIL_WARNING,"[TC_PMIC_%03d] : xPmicEnableRunTimeBist Passed\n\r",ucnumOFTestCases);
        }
    #endif

    xPmicIntrHandler(&xpmicErrorData);

    pmic_test_exit:
    return xErrFlag;
}

TEST_FUNC TESTerrorType_e xPMICDVTestWrapper(void)
{
	uint8 ulcpu_ID = get_curr_phys_cpu_num();
    uint8 ucLength = 0x0u;

	prvPmicInfo(DVFRAMEWORK,ulcpu_ID,NULL,&ucLength);
	return 0;
}

TEST_FUNC TESTerrorType_e xTestPmicMBWrapper(uint32 Cx_Mx, uint64 Abs_volt_lower, uint64 Abs_volt_higher , uint32 up_down , uint8 *DataBuff , uint8 *ucLength)
{
	TESTerrorType_e xRetStatus = MODULE_TEST_FAILED; 
    if (up_down == 0x0 && Abs_volt_lower == 0x0 && Abs_volt_higher == 0x0 )
	{
		if (Cx_Mx == 0x10)
		{
			if ( MODULE_TEST_PASSED == xTestPrintRegSummary() )
            {
                xRetStatus = MODULE_TEST_PASSED;
            }
		}
		else if ( Cx_Mx == 0x11 )
        {
            if ( MODULE_TEST_PASSED == prvPmiclogPrint() )
            {
                xRetStatus = MODULE_TEST_PASSED;
            }
        }
        else if ( Cx_Mx == 0x12 )
        {
            if ( MODULE_TEST_PASSED == xTestPmicGetResetState() )
            {
                xRetStatus = MODULE_TEST_PASSED;
            }
        }
		else if (Cx_Mx == 0x3)
		{
            if ( MODULE_TEST_PASSED == xTestReadCxVoltWrapper() )
            {
                xRetStatus = MODULE_TEST_PASSED;
            }
		}
		else if ( Cx_Mx == 0x4 )
		{
            if ( MODULE_TEST_PASSED == xTestReadMxVoltWrapper() )
            {
                xRetStatus = MODULE_TEST_PASSED;
            }
		}else if ( Cx_Mx == 0x5 )
        {
            if ( DataBuff != NULL)
            {
                if ( PMIC_ERR_FLAG_SUCCESS == prvPmicInfo(MBFRAMEWORK,0u,DataBuff,ucLength) )
                {
                    xRetStatus = MODULE_TEST_PASSED;
                }
            }
        }else if ( Cx_Mx == CMD_PMIC_UPDATE_TO_1 )
        {

            if ( 1u == prvGetSAILPMICInfo(CUSTOMER_NVMID) ) // No Need to update PMIC FW if asked nvm version already present in device
            {
                DEBUG_LOG(SAIL_WARNING,"PMIC FW Version is already %d\n\r",1)
                return MODULE_TEST_PASSED;
            }

            if ( PMIC_ERR_FLAG_SUCCESS == prvPmicNVMFrameUpdate(1-1) )
            {
                DEBUG_LOG(SAIL_WARNING,"PMIC FW updated to %d success\n\r",1);
                DEBUG_LOG(SAIL_WARNING,"Do Power Cycle!!!\n\r");
                xRetStatus = MODULE_TEST_PASSED;
            }

        }else if ( Cx_Mx == CMD_PMIC_UPDATE_TO_2 )
        {    
            if ( 2u == prvGetSAILPMICInfo(CUSTOMER_NVMID) ) // No Need to update PMIC FW if asked nvm version already present in device
            {
                DEBUG_LOG(SAIL_WARNING,"PMIC FW Version is already %d\n\r",2)
                return MODULE_TEST_PASSED;
            }
            if ( PMIC_ERR_FLAG_SUCCESS == prvPmicNVMFrameUpdate(2-1) )
            {
                DEBUG_LOG(SAIL_WARNING,"PMIC FW updated to %d success\n\r",2);
                DEBUG_LOG(SAIL_WARNING,"Do Power Cycle!!!\n\r");
                xRetStatus = MODULE_TEST_PASSED;
            }
        }
	}
	else if ( up_down == 0x1 && Abs_volt_lower == 0x0 && Abs_volt_higher == 0x0 )
	{
		if (Cx_Mx == 0x3 )
		{
			if ( MODULE_TEST_PASSED == xTestCXOneStepDownVoltWrapper() )
			{
				xRetStatus = MODULE_TEST_PASSED;
			}
		}
		else if ( Cx_Mx == 0x4 )
		{
			if ( MODULE_TEST_PASSED == xTestMXOneStepDownVoltWrapper() )
			{
				xRetStatus = MODULE_TEST_PASSED;
			}
		}
	}
	else if ( up_down == 0x2 && Abs_volt_lower == 0x0 && Abs_volt_higher == 0x0)
	{
		if (Cx_Mx == 0x3 )
		{
			if ( MODULE_TEST_PASSED == xTestCXOneStepUpVoltWrapper() )
			{
				xRetStatus = MODULE_TEST_PASSED;
			}
		}
		else if ( Cx_Mx == 0x4 )
		{
			if ( MODULE_TEST_PASSED == xTestMXOneStepUpVoltWrapper() )
			{
				xRetStatus = MODULE_TEST_PASSED;
			}
		}
	}
	else if (up_down == 0x0 && Abs_volt_lower != 0x0 && (Abs_volt_higher == 0x0 || Abs_volt_higher != 0x0 ) )
	{
		if ( Cx_Mx == 0x3 )
		{
			if ( MODULE_TEST_PASSED == xTestCXCoreWriteVoltWrapper(Abs_volt_lower,Abs_volt_higher ))
			{
				xRetStatus = MODULE_TEST_PASSED;
			}
		}
		else if ( Cx_Mx == 0x4 )
		{
			if ( MODULE_TEST_PASSED == xTestMXCoreWriteVoltWrapper(Abs_volt_lower,Abs_volt_higher ) )
			{
				xRetStatus = MODULE_TEST_PASSED;
			}
		}
	}else
    {

    }
	return xRetStatus;
}

/*=========================================================================================================
 @Service name        prvPmicNVMFrameUpdate
 @Description         prvPmicNVMFrameUpdate is used to update TI PMIC Firmware
 @param[in]           ucCustomerNVMId < Version number of Release>
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              <err> <Return err type based on status of transaction on I2C bus>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

TEST_FUNC static pmicErrFlagType_e prvPmicNVMFrameUpdate(uint8 ucCustomerNVMId )
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    pmicPageId_e xpageId = PAGE_ID_0;
    uint64 ullAllBitSet = 0xFFFFFFFFFFFFFFFF;
    uint8 ucIndex = 0x0;
    uint8 ReadBack = 0x0;
    uint8 ucData = 0x0;
    //Wdt_Command_Type xWdt_Test_Command = {WDT_INVALID, 50};
    uint32 ulCurrentVIPFirmwareVersion = 0x0u;
    uint8 ucnvmCode2 = 0x0u;


    if ( ucCustomerNVMId >= MAX_NVM_VERSION_AVAILABLE )
    {
        return PMIC_ERR_OUT_OF_BOUNDARY;
    }

    //Firmware update is not supported for MCU-Less part, remove the check once there is requirement/support for FW update (MCU-Less)
    if ( TRUE == (boolean)bSailPmicFWMCULess() )
    {
        return PMIC_NVM_UPDATE_NOT_SUPPORTED;
    }

    ucnvmCode2 = prvGetSAILPMICInfo(NVMCODE2);


    if (  ucnvmCode2 !=  PMIC_NVM_CODE2_FW_SUPPORTED )
    {
        DEBUG_LOG(SAIL_ERROR,"PMIC Firmware update not required on RTLVersion = %d \r\n",ucnvmCode2);
        return PMIC_ERR_OUT_OF_BOUNDARY;
    }


    #ifdef VIP_FIRMWARE_CHECK_FOR_INTERNAL_BUILD

        /*Read out VIP Firmware Data*/

        ulCurrentVIPFirmwareVersion = ucGetVIPFirmwareData();

        if ( ulCurrentVIPFirmwareVersion < THESHOLD_VIP_FIRMWARE_VERSION)
        {
            DEBUG_LOG(SAIL_ERROR,"VIP Firmware is invalid\r\n");
            DEBUG_LOG(SAIL_ERROR,"Please upgrade VIP Firmware to >= 1.2.1 ( or to Latest VIP Firmware )\r\n");
            return PMIC_ERR_NVM_UPDATE_FAILED;
        }else
        {
            DEBUG_LOG(SAIL_ERROR,"VIP Firmware Version %d.%d.%d\r\n",ulCurrentVIPFirmwareVersion/100,\
                                (ulCurrentVIPFirmwareVersion%100)/10,(ulCurrentVIPFirmwareVersion)%10);
        }

    #endif


    /* 
     * Before De-grading/Upgrading the PMIC FW . SAILSW will Disable the watchdog on DCLS 
     * Core as PMIC FW De-grading/Upgrading takes around ~2.5Sec. And it is assumed/assured
     * that after PMIC FW De-grading/Upgrading , Power cycle is needed so Watchdog will get
     * re-enabled after Power cycle is completed.
     */

    //xWdt_Test_Command.Command = WDT_DISABLE;
    //xWdt_Send_Command(xWdt_Test_Command);

    /*Programming sequence overview:

        1.  Unlock the EEPROM
        2.  Disabled Register CRC
        3.  Configure programming mode
        4.  Set programming mode.
        5.  Program user registers, including the register CRC.
        6.  Program PFSM registers
        7.  Exiting EEPROM programming mode
    */


    /*  Unlocking the EEPROM requires 4 sequential writes to the USER_EE_CTRL_1 register: 0x98, 0xB8, 0x13, 0x7D.  
    *    The sequence of writes cannot be interrupted by any other register accesses, this includes register reads.  
    *   Best practice is to write 0x00 first to reset the mechanism and then write the sequence.  
            USER_EE_CTRL_1: Register Address 0x0A2 (I2C address 0x28, register address 0xA2)
                    Bit7    Bit6     Bit 5   Bit4    Bit3    Bit2    Bit1    Bit0
                                USER_EE_PROG_UNLOCK_SEQ

    */
    ucData = 0x0U;
    xpageId = PAGE_ID_0;
    xErrFlag = prvPmicCommWriteByte(xpageId,HWIO_PMIC(USER_EE_CTRL_1),ucData);

    ucData = 0x98U;
    xpageId = PAGE_ID_0;
    xErrFlag |= prvPmicCommWriteByte(xpageId,HWIO_PMIC(USER_EE_CTRL_1),ucData);


    ucData = 0xB8U;
    xpageId = PAGE_ID_0;
    xErrFlag |= prvPmicCommWriteByte(xpageId,HWIO_PMIC(USER_EE_CTRL_1),ucData);


    ucData = 0x13U;
    xpageId = PAGE_ID_0;
    xErrFlag |= prvPmicCommWriteByte(xpageId,HWIO_PMIC(USER_EE_CTRL_1),ucData);

    ucData = 0x7DU;
    xpageId = PAGE_ID_0;
    xErrFlag |= prvPmicCommWriteByte(xpageId,HWIO_PMIC(USER_EE_CTRL_1),ucData);


    /*Disabled Register CRC

            GENERAL_REG_1: Register Address 0x118 (I2C address 0x29, register address 0x18)
                Bit7    Bit6    Bit 5   Bit4    Bit3    Bit2    Bit1    Bit0
                0   REG_CRC_EN     0      0       0       1       0       1

        The programmed NVM value for GENERAL_REG_1 is 0x45.  
        Clearing bit 6 will prevent the PMIC from shutting down after other changes to the page 1 space are made.
    */

    ucData = 0x05U;
    xpageId = PAGE_ID_1;
    xErrFlag |= prvPmicCommWriteByte(xpageId,HWIO_PMIC(GENERAL_REG_1),ucData);

    ReadBack = 0x0;
    xErrFlag |= prvPmicCommReadByte(xpageId,HWIO_PMIC(GENERAL_REG_1),&ReadBack);
    if( ucData != ReadBack )
    {
        DEBUG_LOG(SAIL_ERROR,"NVM Update Failed Add:%x ,ReadBack:%x ,ucData:%d",HWIO_PMIC(GENERAL_REG_1),ReadBack,ucData);
        return PMIC_ERR_NVM_UPDATE_FAILED;
    }

    /*Configure Programming mode

        EEPROM_CONTROL_2: Register Address 0x1E1 (I2C address 0x29, register address 0xE1)
            Bit7    Bit6    Bit 5            Bit4    Bit3    Bit2    Bit1    Bit0
            0         0   TM_EE_CFG_SINGLE    0             TM_EE_CFG_BANK_DIS

        TM_EE_CFG_SINGLE=1 for all OTA programming.  Clearing TM_EE_CFG_SINGLE is done for the bulk programming mode and will turn off the regulators when the EE_PROG_MODE is set.

        TM_EE_CFG_BANK_DIS selects which banks are enabled for programming

        TM_EE_CFG_BANK_DIS  Description
                1110b       EEPROM bank 0 is enabled.  All writes take place in bank0, 
                            this is where all of the user register settings are located EEPROM.
                1101b       EEPROM bank 1 is enabled. PFSM 0x3000-0x30FF
                1011b       EEPROM bank 2 is enabled. PFSM 0x3100-0x31FF
                0111b       EEPROM bank 3 is enabled. PFSM 0x3200-0x32FF
    */
    ucData = 0x2EU; // EPROM Bank 0 is enable and TM_EE_CFG_SINGLE = 1 to enable OTA programming
    xpageId = PAGE_ID_1;
    xErrFlag |= prvPmicCommWriteByte(xpageId, HWIO_PMIC(EEPROM_CONTROL_2),ucData);

    ReadBack = 0x0;
    xErrFlag |= prvPmicCommReadByte(xpageId,HWIO_PMIC(EEPROM_CONTROL_2),&ReadBack);
    if( ucData != ReadBack )
    {
        DEBUG_LOG(SAIL_ERROR,"NVM Update Failed Add:%x ,ReadBack:%x ,ucData:%d",HWIO_PMIC(EEPROM_CONTROL_2),ReadBack,ucData);
        return PMIC_ERR_NVM_UPDATE_FAILED;
    }



    /*
        Set programming mode
        USER_EE_CTRL_2: Register Address 0x0A3
        Bit7                Bit6                Bit 5   Bit4    Bit3    Bit2    Bit1    Bit0
        USER_PROG_ALLOWED   USER_PROG_UNLOCKED  0       0       0       0       0       EE_PROG_MODE

        Bit 7 will be set when register 0x141 (USER_EE_PROG_UNLOCK) = 0xA5.  After the unlock sequence 
        is provided bit 6 should be set.  At this time, set EE_PROG_MODE.
    */


    ucData = 0xA5U;
    xpageId = PAGE_ID_1;
    xErrFlag |= prvPmicCommWriteByte(xpageId, HWIO_PMIC(USER_EE_PROG_UNLOCK),ucData);

    ReadBack = 0x0;
    xErrFlag |= prvPmicCommReadByte(xpageId,HWIO_PMIC(USER_EE_PROG_UNLOCK),&ReadBack);
    if( ucData != ReadBack )
    {
        DEBUG_LOG(SAIL_ERROR,"NVM Update Failed Add:%x ,ReadBack:%x ,ucData:%d",HWIO_PMIC(USER_EE_PROG_UNLOCK),ReadBack,ucData);
        return PMIC_ERR_NVM_UPDATE_FAILED;
    }



    ucData = 0xC1U;
    xpageId = PAGE_ID_0;
    xErrFlag |= prvPmicCommWriteByte(xpageId, HWIO_PMIC(USER_EE_CTRL_2),ucData);

    ReadBack = 0x0;
    xErrFlag |= prvPmicCommReadByte(xpageId,HWIO_PMIC(USER_EE_CTRL_2),&ReadBack);
    if( ucData != ReadBack )
    {
        DEBUG_LOG(SAIL_ERROR,"NVM Update Failed Add:%x ,ReadBack:%x ,ucData:%d",HWIO_PMIC(USER_EE_CTRL_2),ReadBack,ucData);
        return PMIC_ERR_NVM_UPDATE_FAILED;
    }


    ucIndex = 0x0;
    for ( ucIndex = 0x0 ; ucIndex < NUMBER_OF_STATIC_EEPROM_REGISTERS ; ucIndex++)
    {
        xErrFlag |= prveepromWrite((EEPROM_INTERFACE*)&staticBANK0EEPROM[ucCustomerNVMId][ucIndex]);
    }


    ucData = 0x0; // EPROM Bank 1 is enable and TM_EE_CFG_SINGLE = 1 to enable OTA programming
    xpageId = PAGE_ID_1;
    xErrFlag |= prvPmicCommReadByte(xpageId, HWIO_PMIC(EEPROM_CONTROL_2),&ucData);
    ucData &= (~0xF);
    ucData |= (0xD & 0xF);
    xErrFlag |= prvPmicCommWriteByte(xpageId, HWIO_PMIC(EEPROM_CONTROL_2),ucData);
    ReadBack = 0x0;
    xErrFlag |= prvPmicCommReadByte(xpageId,HWIO_PMIC(EEPROM_CONTROL_2),&ReadBack);
    if( ucData != ReadBack )
    {
        DEBUG_LOG(SAIL_ERROR,"NVM Update Failed Add:%x ,ReadBack:%x ,ucData:%d",HWIO_PMIC(EEPROM_CONTROL_2),ReadBack,ucData);
        return PMIC_ERR_NVM_UPDATE_FAILED;
    }



    ucIndex = 0x0;
    for ( ucIndex = 0x0 ; ucIndex < NUMBER_OF_PFSM_EEPROM_REGISTERS ; ucIndex++)
    {
        xErrFlag |= prveepromWrite((EEPROM_INTERFACE*)&pfsmBANK1EEPROM[ucCustomerNVMId][ucIndex]);
    }

    ucData = 0x0; // EPROM Bank 2 is enable and TM_EE_CFG_SINGLE = 1 to enable OTA programming
    xpageId = PAGE_ID_1;
    xErrFlag |= prvPmicCommReadByte(xpageId, HWIO_PMIC(EEPROM_CONTROL_2),&ucData);
    ucData &= (~0xF);
    ucData |= (0xB & 0xF);
    xErrFlag |= prvPmicCommWriteByte(xpageId, HWIO_PMIC(EEPROM_CONTROL_2),ucData);
    ReadBack = 0x0;
    xErrFlag |= prvPmicCommReadByte(xpageId,HWIO_PMIC(EEPROM_CONTROL_2),&ReadBack);
    if( ucData != ReadBack )
    {
        DEBUG_LOG(SAIL_ERROR,"NVM Update Failed Add:%x ,ReadBack:%x ,ucData:%d",HWIO_PMIC(EEPROM_CONTROL_2),ReadBack,ucData);
        return PMIC_ERR_NVM_UPDATE_FAILED;
    }


    ucIndex = 0x0;
    for ( ucIndex = 0x0 ; ucIndex < NUMBER_OF_PFSM_EEPROM_REGISTERS ; ucIndex++)
    {
        xErrFlag |= prveepromWrite((EEPROM_INTERFACE*)&pfsmBANK2EEPROM[ucCustomerNVMId][ucIndex]);
    }

    ucData = 0x0; // EPROM Bank 2 is enable and TM_EE_CFG_SINGLE = 1 to enable OTA programming
    xpageId = PAGE_ID_1;
    xErrFlag |= prvPmicCommReadByte(xpageId, HWIO_PMIC(EEPROM_CONTROL_2),&ucData);
    ucData &= (~0xF);
    ucData |= (0x7 & 0xF);
    xErrFlag |= prvPmicCommWriteByte(xpageId, HWIO_PMIC(EEPROM_CONTROL_2),ucData);
    ReadBack = 0x0;
    xErrFlag |= prvPmicCommReadByte(xpageId,HWIO_PMIC(EEPROM_CONTROL_2),&ReadBack);
    if( ucData != ReadBack )
    {
        DEBUG_LOG(SAIL_ERROR,"NVM Update Failed Add:%x ,ReadBack:%x ,ucData:%d",HWIO_PMIC(EEPROM_CONTROL_2),ReadBack,ucData);
        return PMIC_ERR_NVM_UPDATE_FAILED;
    }



    ucIndex = 0x0;
    for ( ucIndex = 0x0 ; ucIndex < NUMBER_OF_PFSM_EEPROM_REGISTERS ; ucIndex++)
    {
        xErrFlag |= prveepromWrite((EEPROM_INTERFACE*)&pfsmBANK3EEPROM[ucCustomerNVMId][ucIndex]);
    }

    /*  Exiting EEPROM programming mode 
        After all updates to the NVM have been made the programming mode 
        can be exited by writing 0x00 to the USER_EE_CTRL_1 register
    */
    ucData = 0x0U;
    xpageId = PAGE_ID_0;
    xErrFlag |= prvPmicCommWriteByte(xpageId,HWIO_PMIC(USER_EE_CTRL_1),ucData);

    return xErrFlag;
}


/*=========================================================================================================
 @Service name        prveepromWrite
 @Description         prveepromWrite is used to update data in eeprom Address using I2C bus
 @param[in]           EEPROMptr -> Contains Address and Data
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              <err> <Return err type based on status of transaction on I2C bus>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/


TEST_FUNC static pmicErrFlagType_e prveepromWrite(EEPROM_INTERFACE *EEPROMptr)
{
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
    uint8 READCMD = 0x1;
    uint8 WRITECMD = 0x2;
    uint8 ReadBack = 0x0;
    uint8 ucData = 0x0;
    uint64 currentEEPROM = 0x0;
    uint64 newEEPROM = 0x0;
    uint8 byteRead = 0x0;
    uint8 byteWrite = 0x0;

    if ( EEPROMptr == NULL )
    {
        return PMIC_ERR_PTR_HANDLE;
    }

    if(EEPROMptr->mask != 0xFFFFFFFFFFFFFFFF)
    {
        // read out contents of eepromAddress, even first
        byteWrite = EEPROMptr->address;
        xErrFlag = prvPmicCommWriteByte(PAGE_ID_1,HWIO_PMIC(EECTRL3_ADDRESSCTRL),byteWrite);
        ReadBack = 0x0;
        xErrFlag = prvPmicCommReadByte(PAGE_ID_1,HWIO_PMIC(EECTRL3_ADDRESSCTRL),&ReadBack);
        if( byteWrite != ReadBack )
        {
            DEBUG_LOG(SAIL_ERROR,"NVM Update Failed Add:%x ,ReadBack:%x ,byteWrite:%d",HWIO_PMIC(EECTRL3_ADDRESSCTRL),ReadBack,byteWrite);
            return PMIC_ERR_NVM_UPDATE_FAILED;
        }


        xErrFlag|= prvPmicCommWriteByte(PAGE_ID_1, HWIO_PMIC(EECTRL16_READWRITE_CMD),READCMD);
        xErrFlag|= prvPmicCommReadByte( PAGE_ID_1 , HWIO_PMIC(EECTRL20_ACTIVEPOLL) , &byteRead);
        while(byteRead & EEPROMBUSY)
        {
            xErrFlag|= prvPmicCommReadByte( PAGE_ID_1 , HWIO_PMIC(EECTRL20_ACTIVEPOLL), &byteRead);
        }

        xErrFlag|= prvPmicCommReadByte( PAGE_ID_1 , HWIO_PMIC(EECTRL15_READDATA0),&byteRead);
        currentEEPROM = (uint64)byteRead;

        xErrFlag|= prvPmicCommReadByte( PAGE_ID_1 , HWIO_PMIC(EECTRL14_READDATA1),&byteRead);
        currentEEPROM |= ((uint64)byteRead)<<8;

        xErrFlag|= prvPmicCommReadByte( PAGE_ID_1 , HWIO_PMIC(EECTRL13_READDATA2),&byteRead);
        currentEEPROM |= ((uint64)byteRead)<<16;

        xErrFlag|= prvPmicCommReadByte( PAGE_ID_1 , HWIO_PMIC(EECTRL12_READDATA3 ), &byteRead);
        currentEEPROM |= ((uint64)byteRead)<<24;


        byteWrite = 1+EEPROMptr->address;
        xErrFlag|= prvPmicCommWriteByte(PAGE_ID_1 , HWIO_PMIC(EECTRL3_ADDRESSCTRL),byteWrite);
        ReadBack = 0x0;
        xErrFlag |= prvPmicCommReadByte(PAGE_ID_1,  HWIO_PMIC(EECTRL3_ADDRESSCTRL),&ReadBack);
        if( byteWrite != ReadBack )
        {
            DEBUG_LOG(SAIL_ERROR,"NVM Update Failed Add:%x ,ReadBack:%x ,byteWrite:%d",HWIO_PMIC(EECTRL3_ADDRESSCTRL),ReadBack,byteWrite);
            return PMIC_ERR_NVM_UPDATE_FAILED;
        }


        xErrFlag|= prvPmicCommWriteByte(PAGE_ID_1 , HWIO_PMIC(EECTRL16_READWRITE_CMD),READCMD);
        xErrFlag|= prvPmicCommReadByte( PAGE_ID_1 , HWIO_PMIC(EECTRL20_ACTIVEPOLL),  &byteRead);
        while(byteRead & EEPROMBUSY)
        {
            xErrFlag|= prvPmicCommReadByte( PAGE_ID_1 , HWIO_PMIC(EECTRL20_ACTIVEPOLL) , &byteRead);
        }

        xErrFlag|= prvPmicCommReadByte( PAGE_ID_1 , HWIO_PMIC(EECTRL15_READDATA0),&byteRead);
        currentEEPROM  |= ((uint64)byteRead)<<32;

        xErrFlag|= prvPmicCommReadByte( PAGE_ID_1 , HWIO_PMIC(EECTRL14_READDATA1),&byteRead);
        currentEEPROM  |= ((uint64)byteRead)<<40;

        xErrFlag|= prvPmicCommReadByte( PAGE_ID_1 , HWIO_PMIC(EECTRL13_READDATA2),&byteRead);
        currentEEPROM  |= ((uint64)byteRead)<<48;

        xErrFlag|= prvPmicCommReadByte( PAGE_ID_1 , HWIO_PMIC(EECTRL12_READDATA3),&byteRead);
        currentEEPROM  |= ((uint64)byteRead)<<56;

    }
    newEEPROM = (currentEEPROM & ~EEPROMptr->mask);
    newEEPROM |= (EEPROMptr->payload & EEPROMptr->mask);

    // write EEPROM, even first
    byteWrite = EEPROMptr->address;
    xErrFlag|= prvPmicCommWriteByte( PAGE_ID_1 , HWIO_PMIC(EECTRL3_ADDRESSCTRL),byteWrite);
    ReadBack = 0x0;
    xErrFlag |= prvPmicCommReadByte(PAGE_ID_1,  HWIO_PMIC(EECTRL3_ADDRESSCTRL),&ReadBack);
    if( byteWrite != ReadBack )
    {
        DEBUG_LOG(SAIL_ERROR,"NVM Update Failed Add:%x ,ReadBack:%x ,byteWrite:%d",HWIO_PMIC(EECTRL3_ADDRESSCTRL),ReadBack,byteWrite);
        return PMIC_ERR_NVM_UPDATE_FAILED;
    }


    byteWrite = (newEEPROM)&(0xFF);
    xErrFlag|= prvPmicCommWriteByte( PAGE_ID_1 ,HWIO_PMIC(EECTRL11_WRITEDATA0),byteWrite);
    ReadBack = 0x0;
    xErrFlag |= prvPmicCommReadByte(PAGE_ID_1,  HWIO_PMIC(EECTRL11_WRITEDATA0),&ReadBack);
    if( byteWrite != ReadBack )
    {
        DEBUG_LOG(SAIL_ERROR,"NVM Update Failed Add:%x ,ReadBack:%x ,byteWrite:%d",HWIO_PMIC(EECTRL11_WRITEDATA0),ReadBack,byteWrite);
        return PMIC_ERR_NVM_UPDATE_FAILED;
    }
    newEEPROM = newEEPROM >> 8;


    byteWrite = (newEEPROM)&(0xFF);
    xErrFlag|= prvPmicCommWriteByte( PAGE_ID_1 ,HWIO_PMIC(EECTRL10_WRITEDATA1),byteWrite);
    ReadBack = 0x0;
    xErrFlag |= prvPmicCommReadByte(PAGE_ID_1,  HWIO_PMIC(EECTRL10_WRITEDATA1),&ReadBack);
    if( byteWrite != ReadBack )
    {
        DEBUG_LOG(SAIL_ERROR,"NVM Update Failed Add:%x ,ReadBack:%x ,byteWrite:%d",HWIO_PMIC(EECTRL10_WRITEDATA1),ReadBack,byteWrite);
        return PMIC_ERR_NVM_UPDATE_FAILED;
    }
    newEEPROM = newEEPROM >> 8;

    byteWrite = (newEEPROM)&(0xFF);
    xErrFlag|= prvPmicCommWriteByte( PAGE_ID_1 ,HWIO_PMIC(EECTRL9_WRITEDATA2),byteWrite);
    ReadBack = 0x0;
    xErrFlag |= prvPmicCommReadByte(PAGE_ID_1,  HWIO_PMIC(EECTRL9_WRITEDATA2),&ReadBack);
    if( byteWrite != ReadBack )
    {
        DEBUG_LOG(SAIL_ERROR,"NVM Update Failed Add:%x ,ReadBack:%x ,byteWrite:%d",HWIO_PMIC(EECTRL9_WRITEDATA2),ReadBack,byteWrite);
        return PMIC_ERR_NVM_UPDATE_FAILED;
    }
    newEEPROM = newEEPROM >> 8;

    byteWrite = (newEEPROM)&(0xFF);
    xErrFlag|= prvPmicCommWriteByte( PAGE_ID_1 ,HWIO_PMIC(EECTRL8_WRITEDATA3),byteWrite);
    ReadBack = 0x0;
    xErrFlag |= prvPmicCommReadByte(PAGE_ID_1,  HWIO_PMIC(EECTRL8_WRITEDATA3),&ReadBack);
    if( byteWrite != ReadBack )
    {
        DEBUG_LOG(SAIL_ERROR,"NVM Update Failed Add:%x ,ReadBack:%x ,byteWrite:%d",HWIO_PMIC(EECTRL8_WRITEDATA3),ReadBack,byteWrite);
        return PMIC_ERR_NVM_UPDATE_FAILED;
    }
    newEEPROM = newEEPROM >> 8;

    xErrFlag|= prvPmicCommWriteByte( PAGE_ID_1 ,HWIO_PMIC(EECTRL16_READWRITE_CMD), WRITECMD);
    xErrFlag|= prvPmicCommReadByte( PAGE_ID_1 , HWIO_PMIC(EECTRL20_ACTIVEPOLL),  &byteRead);
    while(byteRead & EEPROMBUSY)
    {
        xErrFlag|= prvPmicCommReadByte( PAGE_ID_1 , HWIO_PMIC(EECTRL20_ACTIVEPOLL),  &byteRead);
    }

    byteWrite = 1+EEPROMptr->address;
    xErrFlag|= prvPmicCommWriteByte( PAGE_ID_1 ,HWIO_PMIC(EECTRL3_ADDRESSCTRL),byteWrite);
    ReadBack = 0x0;
    xErrFlag |= prvPmicCommReadByte(PAGE_ID_1,  HWIO_PMIC(EECTRL3_ADDRESSCTRL),&ReadBack);
    if( byteWrite != ReadBack )
    {
        DEBUG_LOG(SAIL_ERROR,"NVM Update Failed Add:%x ,ReadBack:%x ,byteWrite:%d",HWIO_PMIC(EECTRL3_ADDRESSCTRL),ReadBack,byteWrite);
        return PMIC_ERR_NVM_UPDATE_FAILED;
    }

    byteWrite = (newEEPROM)&(0xFF);
    xErrFlag|= prvPmicCommWriteByte( PAGE_ID_1 ,HWIO_PMIC(EECTRL11_WRITEDATA0),byteWrite);
    ReadBack = 0x0;
    xErrFlag |= prvPmicCommReadByte(PAGE_ID_1,  HWIO_PMIC(EECTRL11_WRITEDATA0),&ReadBack);
    if( byteWrite != ReadBack )
    {
        DEBUG_LOG(SAIL_ERROR,"NVM Update Failed Add:%x ,ReadBack:%x ,byteWrite:%d",HWIO_PMIC(EECTRL11_WRITEDATA0),ReadBack,byteWrite);
        return PMIC_ERR_NVM_UPDATE_FAILED;
    }
    newEEPROM = newEEPROM >> 8;

    byteWrite = (newEEPROM)&(0xFF);
    xErrFlag|= prvPmicCommWriteByte( PAGE_ID_1 ,HWIO_PMIC(EECTRL10_WRITEDATA1),byteWrite);
    ReadBack = 0x0;
    xErrFlag |= prvPmicCommReadByte(PAGE_ID_1,  HWIO_PMIC(EECTRL10_WRITEDATA1),&ReadBack);
    if( byteWrite != ReadBack )
    {
        DEBUG_LOG(SAIL_ERROR,"NVM Update Failed Add:%x ,ReadBack:%x ,byteWrite:%d",HWIO_PMIC(EECTRL10_WRITEDATA1),ReadBack,byteWrite);
        return PMIC_ERR_NVM_UPDATE_FAILED;
    }
    newEEPROM = newEEPROM >> 8;

    byteWrite = (newEEPROM)&(0xFF);
    xErrFlag|= prvPmicCommWriteByte( PAGE_ID_1 ,HWIO_PMIC(EECTRL9_WRITEDATA2),byteWrite);
    ReadBack = 0x0;
    xErrFlag |= prvPmicCommReadByte(PAGE_ID_1,  HWIO_PMIC(EECTRL9_WRITEDATA2),&ReadBack);
    if( byteWrite != ReadBack )
    {
        DEBUG_LOG(SAIL_ERROR,"NVM Update Failed Add:%x ,ReadBack:%x ,byteWrite:%d",HWIO_PMIC(EECTRL9_WRITEDATA2),ReadBack,byteWrite);
        return PMIC_ERR_NVM_UPDATE_FAILED;
    }
    newEEPROM = newEEPROM >> 8;

    byteWrite = (newEEPROM)&(0xFF);
    xErrFlag|= prvPmicCommWriteByte( PAGE_ID_1 ,HWIO_PMIC(EECTRL8_WRITEDATA3),byteWrite);
    ReadBack = 0x0;
    xErrFlag |= prvPmicCommReadByte(PAGE_ID_1,  HWIO_PMIC(EECTRL8_WRITEDATA3),&ReadBack);
    if( byteWrite != ReadBack )
    {
        DEBUG_LOG(SAIL_ERROR,"NVM Update Failed Add:%x ,ReadBack:%x ,byteWrite:%d",HWIO_PMIC(EECTRL8_WRITEDATA3),ReadBack,byteWrite);
        return PMIC_ERR_NVM_UPDATE_FAILED;
    }

    xErrFlag|= prvPmicCommWriteByte( PAGE_ID_1 ,HWIO_PMIC(EECTRL16_READWRITE_CMD),WRITECMD);
    xErrFlag|= prvPmicCommReadByte( PAGE_ID_1 , HWIO_PMIC(EECTRL20_ACTIVEPOLL),  &byteRead);
    while(byteRead & EEPROMBUSY)
    {
        xErrFlag|= prvPmicCommReadByte( PAGE_ID_1 , HWIO_PMIC(EECTRL20_ACTIVEPOLL),  &byteRead);
    }

    return xErrFlag;
}

/*=========================================================================================================
 @Service name        prvDisableMon
 @Description         prvDisableMon is used to disable CLOCK_MON and VOLT_MON
 @param[in]           eMonitorType -> Monitor ID
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              <err> <Return err type based on status of transaction on I2C bus>
 @Pre                 prvPmicVersionDetect should be successfull
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/


TEST_FUNC static pmicErrFlagType_e prvDisableMon(eMonitorType xMonitorId)
{
    eMonitorStateType xState;
    eMonitorErrorType result = MON_RET_SUCCESS;

    // Voltage Monitor need to be disabled before SAIL_CX/SAIL_MX are being scaled

    result = xMonitorGetStatus(xMonitorId, &xState);
    if(result == MON_RET_SUCCESS && xState != MON_UNINITIALIZED)
    {
        if(xState == MON_RUNNING)
        {
            result = xMonitorStop(xMonitorId);
            if(result != MON_RET_SUCCESS)
            {
                return PMIC_ERR_TEST_MODULE_FAILED;
            }
        }
        
        result = xMonitorDeInit(xMonitorId);
        if(result != MON_RET_SUCCESS)
        {
            return PMIC_ERR_TEST_MODULE_FAILED;
        }
    }

    return PMIC_ERR_FLAG_SUCCESS;
}

/*=========================================================================================================
 @Service name        xTestExtWdgWrapper
 @Description         xTestExtWdgWrapper is used to call test api to test External Watchdog of PMIC
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              pmicErrFlagType_e
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/
TEST_FUNC TESTerrorType_e xTestExtWdgWrapper(void)
{
    uint8 *find;
    PMIC_EXTWDG_QueueMsgType xMsg = {0};

    find = APPL_SAIL_Shell_gettoken(NULL);
    if(find == NULL)
    {
        return MODULE_TEST_FAILED;
    }

    else if(APPL_SAIL_Shell_stricmp("enable",(char*)find))
    {
        xMsg.ExtWdgAction = EXT_WDG_ENABLE;
        DEBUG_LOG(SAIL_WARNING,"External Watchdog Enabled\n\r");
    }

    else if(APPL_SAIL_Shell_stricmp("disable",(char*)find))
    {
        xMsg.ExtWdgAction = EXT_WDG_DISABLE;
        DEBUG_LOG(SAIL_WARNING,"External Watchdog Disabled\n\r");
    }

    else if(APPL_SAIL_Shell_stricmp("pet",(char*)find))
    {
        xMsg.ExtWdgAction = EXT_WDG_PET;
        DEBUG_LOG(SAIL_WARNING,"External Watchdog Force Pet\n\r");
    }
    else if(APPL_SAIL_Shell_stricmp("nopet",(char*)find))
    {
        xMsg.ExtWdgAction = EXT_WDG_NO_ACTION;
        DEBUG_LOG(SAIL_WARNING,"External Watchdog no Pet\n\r");
    }
    else
    {
        DEBUG_LOG(SAIL_WARNING,"External Watchdog -- INVALID COMMAND\n\r\t\tUse extwdg enable/disable/pet.\n\r");
        return MODULE_TEST_FAILED;
    }

    xQueueSend( xPmicExtWdgQueueHandle, &xMsg, 0);


    return MODULE_TEST_PASSED;

}



 
SAIL_DEFINE_SYSCALL(  PMIC_GET_NVM_ID,
                      PMIC_GET_NVM_ID_PARM_ID,
                      0,
                      PMICSysCallGetSAILPMICINFO
                    );

 
SAIL_DEFINE_SYSCALL(  PMIC_COMM_READ,
                      PMIC_COMM_READ_PARM_ID,
                      0,
                      PMICSysCallCommReadByte
                    );


SAIL_DEFINE_SYSCALL(  PMIC_SMPS_VOLTAGE_WRITE,
                      PMIC_SMPS_VOLTAGE_WRITE_PARM_ID,
                      0,
                      PMICSysCallSmpsWriteVoltage
                    );


SAIL_DEFINE_SYSCALL(  PMIC_SMPS_ENABLE_WRITE,
                      PMIC_SMPS_ENABLE_WRITE_PARM_ID,
                      0,
                      PMICSysCallSmpsWriteEnable
                    );


SAIL_DEFINE_SYSCALL(  PMIC_LDO_VOLTAGE_WRITE,
                      PMIC_LDO_VOLTAGE_WRITE_PARM_ID,
                      0,
                      PMICSysCallLdoWriteVoltage
                    );


SAIL_DEFINE_SYSCALL(  PMIC_READ_SMPS_ENABLE,
                      PMIC_READ_SMPS_ENABLE_PARM_ID,
                      0,
                      PMICSysCallSmpsReadEnable
                    );

SAIL_DEFINE_SYSCALL(  PMIC_READ_SMPS_VOLTAGE,
                      PMIC_READ_SMPS_VOLTAGE_PARM_ID,
                      0,
                      PMICSysCallSmpsReadVoltage
                    );

SAIL_DEFINE_SYSCALL(  PMIC_READ_LDO_ENABLE,
                      PMIC_READ_LDO_ENABLE_PARM_ID,
                      0,
                      PMICSysCallLdoReadEnable
                    );

SAIL_DEFINE_SYSCALL(  PMIC_READ_LDO_VOLTAGE,
                      PMIC_READ_LDO_VOLTAGE_PARM_ID,
                      0,
                      PMICSysCallLdoReadVoltage
                    );


/**********************************************************************************************************
**                                  End of file <pmictest.c>                                             **
**********************************************************************************************************/

#endif
