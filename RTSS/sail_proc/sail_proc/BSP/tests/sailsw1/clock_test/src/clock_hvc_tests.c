/**
 * @file clock_hvc_tests.c
 * @brief
 * Source file for testing clock driver of SAIL subsystem
 *
 *        Copyright (c) 2022 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */
/*==========================================================================*/


/*============================================================================
 * Include Files
 *============================================================================*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "types.h"
#include "errno.h"
#include "ClockDefs.h"
#include "debug_log.h"
#include "types.h"
#include "Clock.h"
#include "hw_io.h"
#include "HALclkHWIO.h"
#include "HALhwio.h"
#include "busywait.h"
#include "tests.h"


#define testCLOCK_TOTAL_TEST_CASES   11U
/*===========================================================================
                               VARIABLES
============================================================================*/

TEST_FUNC static void prvLockCAM_PLL0(void);
TEST_FUNC static void prvUnLockCAM_PLL0(void);

TEST_FUNC static ClockResult TC_CLOCK_HVC_001(uint32_t testNum);
TEST_FUNC static ClockResult TC_CLOCK_HVC_002(uint32_t testNum);
TEST_FUNC static ClockResult TC_CLOCK_HVC_003(uint32_t testNum);
TEST_FUNC static ClockResult TC_CLOCK_HVC_004(uint32_t testNum);
TEST_FUNC static ClockResult TC_CLOCK_HVC_005(uint32_t testNum);
TEST_FUNC static ClockResult TC_CLOCK_HVC_006(uint32_t testNum);
TEST_FUNC static ClockResult TC_CLOCK_HVC_007(uint32_t testNum);
TEST_FUNC static ClockResult TC_CLOCK_HVC_008(uint32_t testNum);
TEST_FUNC static ClockResult TC_CLOCK_HVC_009(uint32_t testNum);
TEST_FUNC static ClockResult TC_CLOCK_HVC_010(uint32_t testNum);
TEST_FUNC static ClockResult TC_CLOCK_HVC_011(uint32_t testNum);

typedef struct
{
    char     *clkName;
    uint32_t freq;
}TestClockType;

/* CAN Clocks */
TEST_DATA const TestClockType xCANClocksTestTable[]=
{
    { "sailss_cc_can0_ahb_clk", 100 },    /*  Max Nom , cbc,  sailss_cc_sail_noc_center_qh_grp:div1  */
    { "sailss_cc_can0_core_clk", 80 },    /*  Max Nom , cbc,  sailss_cc_can0_core_grp  */
    { "sailss_cc_can1_ahb_clk", 100 },    /*  Max Nom , cbc,  sailss_cc_sail_noc_center_qh_grp:div1  */
    { "sailss_cc_can1_core_clk", 80 },    /*  Max Nom , cbc,  sailss_cc_can1_core_grp  */
    { "sailss_cc_can2_ahb_clk", 100 },    /*  Max Nom , cbc,  sailss_cc_sail_noc_center_qh_grp:div1  */
    { "sailss_cc_can2_core_clk", 80 },    /*  Max Nom , cbc,  sailss_cc_can2_core_grp  */
    { "sailss_cc_can3_ahb_clk", 100 },    /*  Max Nom , cbc,  sailss_cc_sail_noc_center_qh_grp:div1  */
    { "sailss_cc_can3_core_clk", 80 },    /*  Max Nom , cbc,  sailss_cc_can3_core_grp  */
    { "sailss_cc_can4_ahb_clk", 100 },    /*  Max Nom , cbc,  sailss_cc_sail_noc_center_qh_grp:div1  */
    { "sailss_cc_can4_core_clk", 80 },    /*  Max Nom , cbc,  sailss_cc_can4_core_grp  */
    { "sailss_cc_can5_ahb_clk", 100 },    /*  Max Nom , cbc,  sailss_cc_sail_noc_center_qh_grp:div1  */
    { "sailss_cc_can5_core_clk", 80 },    /*  Max Nom , cbc,  sailss_cc_can5_core_grp  */
    { "sailss_cc_can6_ahb_clk", 100 },    /*  Max Nom , cbc,  sailss_cc_sail_noc_center_qh_grp:div1  */
    { "sailss_cc_can6_core_clk", 80 },    /*  Max Nom , cbc,  sailss_cc_can6_core_grp  */
    { "sailss_cc_can7_ahb_clk", 100 },    /*  Max Nom , cbc,  sailss_cc_sail_noc_center_qh_grp:div1  */
    { "sailss_cc_can7_core_clk", 80 },    /*  Max Nom , cbc,  sailss_cc_can7_core_grp  */
};


/*============================================================================
            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE
============================================================================*/
TEST_FUNC static void prvClockTestDebugPrint ( volatile ClockResult eResult,
                                     const char *scTestName,
                                     uint16_t usTestCaseNum );
TEST_FUNC static ClockResult prvTestClockTable( TestClockType *pxClockTable,
                                      uint32 ulTableSize,
                                      uint32_t ulTestCaseNum,
                                      const char *scTestName );
TEST_FUNC static ClockResult prvClockTestsModule( const char *clkName, uint32_t ulfreq );

/*===========================================================================
**  Function :  TC_CLOCK_HVC_001
** ==========================================================================
*/
/*!
*
* @brief
*  Unit test case for validating the CAN clocks
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   ClockResult
* @par Side Effects
*   None
*
*/
TEST_FUNC static ClockResult TC_CLOCK_HVC_001(uint32_t testNum)
{
    return prvTestClockTable( ( TestClockType * ) xCANClocksTestTable,
                              SIZEOF_ARRAY( xCANClocksTestTable ),
                              testNum,
                              "Clock HVC Syscall - CAN Clocks Test Case" );
}
/*===========================================================================
**  Function :  TC_CLOCK_HVC_002
** ==========================================================================
*/
/*!
*
* @brief
*  Unit test case for Validating the multiple time enable and disable
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   ClockResult
* @par Side Effects
*   None
*
*/
TEST_FUNC static ClockResult TC_CLOCK_HVC_002(uint32_t testNum)
{
    volatile ClockResult eResult  = CLOCK_SUCCESS;
    ClockIdType nClockId = 0;
    ClockHandle hClient;
    Clock_GetHandle(&hClient);
    bool pbIsEnabled = FALSE;
    /* This clock enabled two time, inside can init and TC_CLOCK_002 */
    if ( CLOCK_SUCCESS == Clock_GetClockId( hClient,"sailss_cc_can0_ahb_clk", &nClockId ) )
    {
        for(int i = 0; i < ( 50000 - 2 ); i++)
        {
            if ( CLOCK_SUCCESS != Clock_EnableClock(hClient, nClockId ) )
            {

                    eResult = CLOCK_ERROR;
                    goto end;
            }
        }

        for(int i = 0; i<50000; i++)
        {
            if ( CLOCK_SUCCESS != Clock_DisableClock(hClient, nClockId ) )
            {

                    eResult = CLOCK_ERROR;
                    goto end;
            }
        }

        if ( CLOCK_SUCCESS ==  Clock_IsClockEnabled(hClient, nClockId, &pbIsEnabled) )
        {
               if(pbIsEnabled != FALSE)
               {
                   eResult = CLOCK_ERROR;
               }
        }
        else
        {
            eResult = CLOCK_ERROR;
        }
    }
    else
    {
        eResult = CLOCK_ERROR;
    }
end:
    Clock_EnableClock(hClient, nClockId ); // enable can ahb clock to initial counts
    prvClockTestDebugPrint(eResult, "Clock HVC Syscall - Validating the multiple time enable and disable Clock API", testNum );
    return eResult;
}

/*===========================================================================
**  Function :  TC_CLOCK_HVC_003
** ==========================================================================
*/
/*!
*
* @brief
*  Unit test case for Clock HVC Syscall - Clock_IsEnabled()
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   ClockResult
* @par Side Effects
*   None
*
*/
TEST_FUNC static ClockResult TC_CLOCK_HVC_003(uint32_t testNum)
{
    volatile ClockResult eResult  = CLOCK_SUCCESS;
    ClockIdType nClockId = 0;
    ClockHandle hClient;
    Clock_GetHandle(&hClient);
    bool pbIsEnabled = FALSE;
    /* This clock enabled two time, inside can init and TC_CLOCK_002 */
    if ( CLOCK_SUCCESS == Clock_GetClockId( hClient,"sailss_cc_can1_ahb_clk", &nClockId ) )
    {
        for(int i = 0; i < ( 50000 ); i++)
        {
            if ( CLOCK_SUCCESS != Clock_EnableClock(hClient, nClockId ) )
            {

                    eResult = CLOCK_ERROR;
                    goto end;
            }
        }

        for(int i = 0; i<50000; i++)
        {
            if ( CLOCK_SUCCESS != Clock_DisableClock(hClient, nClockId ) )
            {

                    eResult = CLOCK_ERROR;
                    goto end;
            }
        }

        if ( CLOCK_SUCCESS ==  Clock_IsClockEnabled(hClient, nClockId, &pbIsEnabled) )
        {
               if(pbIsEnabled != TRUE)
               {
                   eResult = CLOCK_ERROR;
               }
        }
        else
        {
            eResult = CLOCK_ERROR;
        }
    }
    else
    {
        eResult = CLOCK_ERROR;
    }
end:
    prvClockTestDebugPrint(eResult, "Clock HVC Syscall - Clock_IsEnabled()", 4 );
    return eResult;
}


/*===========================================================================
**  Function :  TC_CLOCK_HVC_004
** ==========================================================================
*/
/*!
*
* @brief
*  Unit test case for validating the Clock HVC Syscall - Clock_IsClockOn() - TRUE
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   ClockResult
* @par Side Effects
*   None
*
*/
TEST_FUNC static ClockResult TC_CLOCK_HVC_004(uint32_t testNum)
{
    volatile ClockResult eResult  = CLOCK_SUCCESS;
    ClockIdType nClockId = 0;
    ClockHandle hClient;
    Clock_GetHandle(&hClient);
    bool pbIsOn = FALSE;
    /* This clock enabled two time, inside can init and TC_CLOCK_002 */
    if ( CLOCK_SUCCESS == Clock_GetClockId( hClient,"sailss_cc_can2_ahb_clk", &nClockId ) )
    {
        if ( CLOCK_SUCCESS ==  Clock_IsClockOn(hClient, nClockId, &pbIsOn) )
        {
            if(pbIsOn != TRUE)
            {
                eResult = CLOCK_ERROR;
            }
        }
        else
        {
            eResult = CLOCK_ERROR;
        }
    }
    else
    {
        eResult = CLOCK_ERROR;
    }
    prvClockTestDebugPrint(eResult, "Clock HVC Syscall - Clock_IsClockOn() - TRUE", testNum );
    return eResult;
}

/*===========================================================================
**  Function :  TC_CLOCK_HVC_005
** ==========================================================================
*/
/*!
*
* @brief
*  Test case for validating the clock enable reference count
*    Sequence1: enable, enable, disable
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   ClockResult
* @par Side Effects
*   None
*
*/
TEST_FUNC static ClockResult TC_CLOCK_HVC_005(uint32_t testNum)
{
    volatile ClockResult eResult         = CLOCK_SUCCESS;
    ClockIdType nClockId        = {0};
    volatile uint32_t ulGetfreq = 0U;
    ClockHandle hClient;
    bool pbIsEnabled = FALSE;
    Clock_GetHandle(&hClient);
    /* This clock enabled two time, inside clock driver init and TC_CLOCK_001 */
    if ( CLOCK_SUCCESS == Clock_GetClockId( hClient,"sailss_cc_can4_ahb_clk", &nClockId ) )
    {
        if ( CLOCK_SUCCESS == Clock_EnableClock(hClient, nClockId ) )
        {
            if ( CLOCK_SUCCESS == Clock_DisableClock(hClient, nClockId ) )
            {
                if ( CLOCK_SUCCESS ==  Clock_IsClockEnabled(hClient, nClockId, &pbIsEnabled) )
                {
                   if(pbIsEnabled != TRUE)
                   {
                       eResult = CLOCK_ERROR;
                   }
                }
                else
                {
                    eResult = CLOCK_ERROR;
                }
            }
            else
            {
                eResult = CLOCK_ERROR; /* failed to get the freq */
            }
         }
        else
        {
            eResult = CLOCK_ERROR; /* failed to get the freq */
        }
    }
    else
    {
        eResult = CLOCK_ERROR; /* failed to get the freq */
    }

    prvClockTestDebugPrint(eResult, "Clock HVC Syscall - validating the clock enable reference count - enable, enable, disable", testNum );
    return eResult;
}

/*===========================================================================
**  Function :  TC_CLOCK_HVC_006
** ==========================================================================
*/
/*!
*
* @brief
*  Test case for validating the clock enable refrence count
*    Sequence2: enable, enable, disable, disable
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   ClockResult
* @par Side Effects
*   None
*
*/
TEST_FUNC static ClockResult TC_CLOCK_HVC_006(uint32_t testNum)
{
    volatile ClockResult eResult         = CLOCK_SUCCESS;
    ClockIdType nClockId        = {0};
    volatile uint32_t ulGetfreq = 0U;
    ClockHandle hClient;
    bool pbIsEnabled = FALSE;
    Clock_GetHandle(&hClient);
    /* This clock enabled two time, inside can init and TC_CLOCK_002 */
    if ( CLOCK_SUCCESS == Clock_GetClockId( hClient,"sailss_cc_can5_ahb_clk", &nClockId ) )
    {
        if ( CLOCK_SUCCESS == Clock_DisableClock(hClient, nClockId ) )
        {
            if ( CLOCK_SUCCESS == Clock_DisableClock(hClient, nClockId ) )
            {
                if ( CLOCK_SUCCESS ==  Clock_IsClockEnabled(hClient, nClockId, &pbIsEnabled) )
                {
                   if(pbIsEnabled != FALSE)
                   {
                       eResult = CLOCK_ERROR;
                   }
                }
                else
                {
                    eResult = CLOCK_ERROR;
                }
            }
            else
            {
                eResult = CLOCK_ERROR; /* failed to get the freq */
            }
        }
        else
        {
            eResult = CLOCK_ERROR; /* failed to get the freq */
        }
    }
    else
    {
        eResult = CLOCK_ERROR; /* failed to get the freq */
    }
    prvClockTestDebugPrint(eResult, "Clock HVC Syscall - validating the clock enable reference count - enable, enable, disable, disable", 8 );
    return eResult;
}

/*===========================================================================
**  Function :  TC_CLOCK_HVC_007
** ==========================================================================
*/
/*!
*
* @brief
*  Test Case to Set incorrect frequency of CAN Clock
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   ClockResult
* @par Side Effects
*   None
*
*/
TEST_FUNC static ClockResult TC_CLOCK_HVC_007(uint32_t testNum)
{
    volatile ClockResult eResult = CLOCK_SUCCESS;
    if( prvClockTestsModule ( "sailss_cc_can0_ahb_clk", 0)  != CLOCK_ERROR)
    {
        eResult = CLOCK_ERROR;
    }
    prvClockTestDebugPrint(eResult, "Clock HVC Syscall - Set incorrect frequency of CAN Clock HVC Syscall", testNum );
    return eResult;
}


/*===========================================================================
**  Function :  TC_CLOCK_008
** ==========================================================================
*/
/*!
*
* @brief
*  Test Case to Set incorrect frequency of EMAC Clock
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   ClockResult
* @par Side Effects
*   None
*
*/
TEST_FUNC static ClockResult TC_CLOCK_HVC_008(uint32_t testNum)
{
    volatile ClockResult eResult = CLOCK_SUCCESS;
    if( prvClockTestsModule ( "sailss_cc_emac0_axi_clk", 0)  != CLOCK_ERROR)
    {
        eResult = CLOCK_ERROR;
    }
    prvClockTestDebugPrint(eResult, "Clock HVC Syscall - Set incorrect frequency of EMAC Clock", testNum );
    return eResult;
}

/*===========================================================================
**  Function :  TC_CLOCK_009
** ==========================================================================
*/
/*!
*
* @brief
*  Test Case for
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   ClockResult
* @par Side Effects
*   None
*
*/
TEST_FUNC static ClockResult TC_CLOCK_HVC_009(uint32_t testNum)
{
    volatile ClockResult eResult         = CLOCK_SUCCESS;
    ClockIdType nClockId        = {0};
    volatile uint32_t ulGetfreq = 0U;
    ClockHandle hClient;
    Clock_GetHandle(&hClient);
    /* This clock enabled two time, inside can init and TC_CLOCK_002 */
    if ( CLOCK_SUCCESS == Clock_GetClockId( hClient,"sailss_cc_can6_ahb_clk", &nClockId ) )
    {
        if ( CLOCK_SUCCESS != Clock_Reset(hClient, nClockId, CLOCK_RESET_ASSERT ) )
        {
            eResult = CLOCK_ERROR; /* failed to get the freq */
        }

        if ( CLOCK_SUCCESS != Clock_Reset(hClient, nClockId, CLOCK_RESET_DEASSERT ) )
        {
            eResult = CLOCK_ERROR; /* failed to get the freq */
        }
    }
    else
    {
        eResult = CLOCK_ERROR; /* failed to get the freq */
    }
    prvClockTestDebugPrint(eResult, "Clock HVC Syscall - Clock_Reset()", testNum );
    return eResult;
}
/*===========================================================================
**  Function :  TC_CLOCK_HVC_010
** ==========================================================================
*/
/*!
*
* @brief
*  Test Case for sailss_cc_emac0_rgmii_clk -freq plan
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   ClockResult
* @par Side Effects
*   None
*
*/
TEST_FUNC static ClockResult TC_CLOCK_HVC_010(uint32_t testNum)
{
    volatile ClockResult eResult = CLOCK_SUCCESS;
    if( prvClockTestsModule ( "sailss_cc_emac0_rgmii_clk", 5)  !=CLOCK_SUCCESS)
    {
        eResult = CLOCK_ERROR;
    }
    if( prvClockTestsModule ( "sailss_cc_emac0_rgmii_clk", 25)  !=CLOCK_SUCCESS)
    {
        eResult = CLOCK_ERROR;
    }
    if( prvClockTestsModule ( "sailss_cc_emac0_rgmii_clk", 50)  !=CLOCK_SUCCESS)
    {
        eResult = CLOCK_ERROR;
    }
    if( prvClockTestsModule ( "sailss_cc_emac0_rgmii_clk", 125)  !=CLOCK_SUCCESS)
    {
        eResult = CLOCK_ERROR;
    }
    if( prvClockTestsModule ( "sailss_cc_emac0_rgmii_clk", 250)  !=CLOCK_SUCCESS)
    {
        eResult = CLOCK_ERROR;
    }
    prvClockTestDebugPrint(eResult, "sailss_cc_emac0_rgmii_clk - freq plan testing", testNum );
    return eResult;
}

/*===========================================================================
**  Function :  TC_CLOCK_012
** ==========================================================================
*/
/*!
*
* @brief
*  Test Case for Sleep Entry and Exit or EL1
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   ClockResult
* @par Side Effects
*   None
*
*/
TEST_FUNC static ClockResult TC_CLOCK_HVC_011(uint32_t testNum)
{
    volatile ClockResult eResult = CLOCK_SUCCESS;
    volatile int stop = 1;
    if( Clock_SleepEntry ()  != CLOCK_SUCCESS)
    {
        eResult = CLOCK_ERROR;
        while(stop);
    }
    if(Clock_SleepExit ()  != CLOCK_SUCCESS)
    {
        eResult = CLOCK_ERROR;
        while(stop);
    }
    prvClockTestDebugPrint(eResult, "Clock HVC Syscall - Sleep Entry and Exit Sequence Test", testNum );
    return eResult;
}
/*===========================================================================
**  Function :  prvClockTestsModule
** ==========================================================================
*/
/*!
*
* @brief
*   it is generic module to test clock, input is clock name
*
* @param
*   clkName
*   ulfreq
* @par Dependencies
*   None
* @retval
*   ClockResult
* @par Side Effects
*   None
*
*/
TEST_FUNC static ClockResult prvClockTestsModule( const char *clkName, uint32_t ulfreq )
{
    volatile ClockResult eResult         = CLOCK_SUCCESS;
    ClockIdType nClockId        = {0};
    volatile uint32_t ulGetfreq = 0U;
    ClockHandle hClient;
    Clock_GetHandle(&hClient);

    if ( CLOCK_SUCCESS == Clock_GetClockId( hClient,clkName, &nClockId ) )
    {
        if(CLOCK_SUCCESS == Clock_SetClockFrequency ( hClient, nClockId, ulfreq,
                            CLOCK_FREQUENCY_MHZ_AT_LEAST, ( uint32 *)&ulGetfreq ) )
        {
            if ( CLOCK_SUCCESS == Clock_EnableClock(hClient, nClockId ) )
            {
                if(CLOCK_SUCCESS != Clock_GetClockFrequency( hClient, nClockId, ( uint32 *)&ulGetfreq ) )
                {
                    eResult = CLOCK_ERROR; /* failed to get the freq */
                }
            }
            else
            {
                eResult = CLOCK_ERROR; /* failed to set the freq */
            }
        }
        else
        {
            eResult = CLOCK_ERROR; /* failed to enable the clock */
        }
    }
    else
    {
        eResult = CLOCK_ERROR; /* failed to get clock ID */
    }

    if( ( uint64 ) ulGetfreq != ( ( uint64 )1000000U * ulfreq ) )
    {
        eResult = CLOCK_ERROR; /* set and get freq not same */
    }

    return eResult;
}

/*===========================================================================
**  Function :  prvTestClockTable
** ==========================================================================
*/
/*!
*
* @brief
*  Generic clock table test function
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   ClockResult
* @par Side Effects
*   None
*
*/
TEST_FUNC static ClockResult prvTestClockTable( TestClockType *pxClockTable,
                                      uint32 ulTableSize,
                                      uint32_t ulTestCaseNum,
                                      const char *scTestName )
{
    volatile ClockResult eResult = CLOCK_SUCCESS;

    for(volatile uint32_t i = 0; i < ulTableSize ; i++)
    {
        if( prvClockTestsModule ( pxClockTable[i].clkName, pxClockTable[i].freq)  != CLOCK_SUCCESS)
        {
            prvClockTestDebugPrint(eResult, scTestName, ulTestCaseNum );
            eResult = CLOCK_ERROR;
            break;
        }
    }

    if( eResult != CLOCK_ERROR )
    {
        prvClockTestDebugPrint(eResult, scTestName, ulTestCaseNum );
    }

    return eResult;
}

static void prvClockTestDebugPrint ( ClockResult eResult,
                                     const char *scTestName,
                                     uint16_t usTestCaseNum )
{
    if( CLOCK_SUCCESS != eResult )
    {
        DEBUG_LOG( SAIL_INFO,"[TC_CLOCK_%03d] Failed: %s\n\r", usTestCaseNum, scTestName );
    }
    else
    {
        DEBUG_LOG( SAIL_INFO,"[TC_CLOCK_%03d] Passed: %s\n\r", usTestCaseNum, scTestName );
    }
}
/*===========================================================================
**  Function :   xTestClockHVCWrappper
** ==========================================================================
*/
/*!
*
* @brief
*  Wrapper function for HVC Clock API Test cases
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
* @par Side Effects
*   None
*
*/
TEST_FUNC int xTestClockHVCWrappper( void )
{
    volatile int stop = 1;
    int xReturn = 0;
    uint32_t  testCaseCnt = ( testCLOCK_TOTAL_TEST_CASES );
    uint32_t  testNum     = 1;

    ClockHandle   hClient;
    rail_voltage_level eGetCorner;
    (void)Clock_GetHandle(&hClient);

    uint8* find              =  APPL_SAIL_Shell_gettoken(NULL);

    if(APPL_SAIL_Shell_stricmp("voltage_dump",(char*)find))
    {
        Clock_GetVoltageRailCorner( hClient,"/vcs/vdd_sail_mx" , &eGetCorner );
        DEBUG_LOG(SAIL_INFO,"/vcs/vdd_sail_mx - %d\n\r", eGetCorner);
        Clock_GetVoltageRailCorner( hClient, "/vcs/vdd_sail_cx", &eGetCorner );
        DEBUG_LOG(SAIL_INFO,"/vcs/vdd_sail_cx - %d\n\r", eGetCorner);
    }
    else if(APPL_SAIL_Shell_stricmp("sail_dump",(char*)find))
    {
        Clock_NodeRefCountDump();
    }
    else
    {
        if( TC_CLOCK_HVC_001(testNum++) == CLOCK_ERROR )
        {
            testCaseCnt--;
        }
        if( TC_CLOCK_HVC_002(testNum++) == CLOCK_ERROR )
        {
            testCaseCnt--;
        }
        if( TC_CLOCK_HVC_003(testNum++) == CLOCK_ERROR )
        {
            testCaseCnt--;
        }
        if( TC_CLOCK_HVC_004(testNum++) == CLOCK_ERROR )
        {
            testCaseCnt--;
        }
        if( TC_CLOCK_HVC_005(testNum++) == CLOCK_ERROR )
        {
            testCaseCnt--;
        }
        if( TC_CLOCK_HVC_006(testNum++) == CLOCK_ERROR )
        {
            testCaseCnt--;
        }
        if( TC_CLOCK_HVC_007(testNum++) == CLOCK_ERROR )
        {
            testCaseCnt--;
        }
        if( TC_CLOCK_HVC_008(testNum++) == CLOCK_ERROR )
        {
            testCaseCnt--;
        }
        if( TC_CLOCK_HVC_009(testNum++) == CLOCK_ERROR )
        {
            testCaseCnt--;
        }
        if( TC_CLOCK_HVC_010(testNum++) == CLOCK_ERROR )
        {
            testCaseCnt--;
        }
        if( TC_CLOCK_HVC_011(testNum++) == CLOCK_ERROR )
        {
            testCaseCnt--;
        }

        if( ( testCLOCK_TOTAL_TEST_CASES ) == testCaseCnt )
        {
            DEBUG_LOG( SAIL_INFO, "[CLOCK Tests passed]\n\r" );
            xReturn = 1;
        }
        else
        {
            DEBUG_LOG( SAIL_INFO, "[CLOCK Tests Failed]\n\r" );
        }
    }
    return xReturn;
}

