/**********************************************************************************************************
    Copyright (c) 2022 Qualcomm Technologies, Inc.
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
    File Name          : icb_tests.c
    Component Name     : icb Unit Test
    Description        : icb Unit Test features are implemented in this file.
    $Header: $
    $DateTime: 2 $
    $Author: pwbldsvc $
=========================================================================================================*/

/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/

//#include "wdt_safertos.h"
//#include "wdt_cfg_safertos.h"
#include "Clock.h"
#include "sail_csr_hwio.h"
#include "sailbsp_mutex.h"
#include "common_functions.h"
//#include "sail_wwdog_hwio.h"
#include "sail_security_control_hwio.h"
#include "HALhwio.h"
#include "hw_io.h"
#include "FreeRTOSOsal.h"
#include "freertos_init.h"
//#include "mailboxInt_api.h"
#include "busywait.h"
#include "debug_log.h"
#include "cache_ops.h"
#include "common_functions.h"
//#include "wdt_tests.h"
#include "icb_tests.h"
#include "tests.h"
#include "chipinfodefs.h"
#include "chipinfo.h"


/*=========================================================================================================
**                                        Local defines and macros                                       **
=========================================================================================================*/
typedef enum
{
    ICB_FAIL,
    ICB_PASS,
}Icb_Test_StatusType_e;

#define ICB_LEMANS_SAIL_R1_VERSION          0x00010000u /* 16bit Major - 16bit Minor version */
#define ICB_LEMANS_SAIL_R2_VERSION          0x00020000u /* 16bit Major - 16bit Minor version */

#define ICB_TEST_SAILSS_MEM_UNUSED    0x1f08000U   /* Decoder Error Access */
#define ICB_TEST_SAILSS_MEM_SEC       0xF0600000   /* WDog ASIL-D Secured Access WDT connected to ASIL-D NOC */
#define ICB_TEST_SAILSS_MEM_WHOLE     0xF8000980   /* CAN0 Not used memory */

/*ASILB Isolation NoC */
#define SAIL_ASILB_ISO_NOC_SFTYCTL_OUTEN_R1   0xF8D40118
#define SAIL_ASILB_ISO_NOC_SFTYCTL_BISTCTL_R1 0xF8D40108
#define SAIL_ASILB_ISO_NOC_SFTYCTL_OUTEN_R2   0xF8D41018
#define SAIL_ASILB_ISO_NOC_SFTYCTL_BISTCTL_R2 0xF8D41008
/*ASILB NoC*/
#define SAIL_ASILB_NOC_SFTYCTL_OUTEN       0xF8D07018
#define SAIL_ASILB_NOC_SFTYCTL_BISTCTL     0xF8D07008
/*ASILD NoC */
#define SAIL_ASILD_NOC_SFTYCTL_OUTEN       0xF0D12018
#define SAIL_ASILD_NOC_SFTYCTL_BISTCTL     0xF0D12008
#define FaultInEn0_high 0xF0D00044
/*ASILD Isolation NoC */
#define SAIL_ASILD_ISO_NOC_SFTYCTL_OUTEN   0xF0D41018
#define SAIL_ASILD_ISO_NOC_SFTYCTL_BISTCTL 0xF0D41008
#define SAIL_ASILD_NOC_WARN_CLEAR 		   0xF0D20018


TEST_DATA static  ChipInfoVersionType ICB_LeManSailVersion_1 ;
TEST_DATA static ChipInfoFamilyType ICB_SailFamily_1 ;



TEST_FUNC static void prvICBTestDebugPrint_UserDefined ( Icb_Test_StatusType_e IcbTest_Result, const char * IcbTest_Msg )
{
    if( ICB_PASS == IcbTest_Result )
    {
        DEBUG_LOG( SAIL_INFO,"ICB  %s : Passed \n\r",  IcbTest_Msg );
    }
    else if( ICB_FAIL == IcbTest_Result )
    {
        DEBUG_LOG( SAIL_INFO,"ICB  %s : Failed  \n\r", IcbTest_Msg);
    }
    else
    {
    	DEBUG_LOG( SAIL_INFO,"%s : ICB test  \n\r",  IcbTest_Msg);
    }
}

/*>>>>>>>>>>>>>>> Abort test cases -   <<<<<<<<<<<<<<<*/

TEST_FUNC Icb_Test_StatusType_e TC_ICB_001_1( uint8_t currentCoreNun )
{
	uint32 Icb_read;
	Icb_read = *((volatile uint32 *) ICB_TEST_SAILSS_MEM_UNUSED);
    return ICB_PASS;
}

TEST_FUNC Icb_Test_StatusType_e TC_ICB_001_2( uint8_t currentCoreNun )
{
	uint32 Icb_Write = 0x5;
	*((volatile uint32 *) ICB_TEST_SAILSS_MEM_UNUSED) = Icb_Write;
	return ICB_PASS;
}

TEST_FUNC Icb_Test_StatusType_e TC_ICB_001_3( uint8_t currentCoreNun )
{
	uint32 Icb_read;
	Icb_read = *((volatile uint32 *) ICB_TEST_SAILSS_MEM_SEC);
	return ICB_PASS;
}

TEST_FUNC Icb_Test_StatusType_e TC_ICB_001_4( uint8_t currentCoreNun )
{
	uint32 Icb_Write = 0x5;
	*((volatile uint32 *) ICB_TEST_SAILSS_MEM_SEC) = Icb_Write;
	return ICB_PASS;
}

/*>>>>>>>>>>>>>>> [TC_ICB_001] Test -   <<<<<<<<<<<<<<<*/

TEST_FUNC Icb_Test_StatusType_e TC_ICB_001( uint8_t currentCoreNun )
{
//	*(uint32*)(SAIL_ASILD_NOC_SFTYCTL_OUTEN) = 0x6;
//	*(uint32_t*)FaultInEn0_high = 0xffffffff;
//	*(uint32*)(SAIL_ASILD_NOC_SFTYCTL_BISTCTL) = 0x1;
    return ICB_PASS;
}

/*>>>>>>>>>>>>>>> [TC_FUSA_014] Test ASILD NOC error interrupt - FUSA_ERROR_215 <<<<<<<<<<*/

TEST_FUNC Icb_Test_StatusType_e TC_ICB_002( uint8_t currentCoreNun )
{
	*(uint32*)(HWIO_SAILSS_CSR_CSR_VLD_RDY_ERR_CLR_ADDR) = 0x1;
	*(uint32*)(SAIL_ASILD_NOC_SFTYCTL_BISTCTL) = 0x2;
	*(uint32*)(SAIL_ASILD_NOC_SFTYCTL_OUTEN) = 0x2;
	*(uint32*)(SAIL_ASILD_NOC_SFTYCTL_BISTCTL) = 0x1;
	
    return ICB_PASS;
}

/*>>>>>>>>>>>>>>> [TC_FUSA_015] Test ASILD NOC warning interrupt - FUSA_WARN_428 <<<<<<<<<<*/

TEST_FUNC Icb_Test_StatusType_e TC_ICB_003( uint8_t currentCoreNun )
{
	*(uint32*)(SAIL_ASILD_NOC_SFTYCTL_OUTEN) = 0x5;
	*(uint32*)(SAIL_ASILD_NOC_SFTYCTL_BISTCTL) = 0x1;
    return ICB_PASS;
}


TEST_FUNC Icb_Test_StatusType_e TC_ICB_004( uint8_t currentCoreNun )
{
//	*(uint32*)(SAIL_ASILD_NOC_SFTYCTL_OUTEN) = 0x5;
//	*(uint32*)(SAIL_ASILD_NOC_SFTYCTL_BISTCTL) = 0x1;
    return ICB_PASS;
}
/*>>>>>>>>>>>>>>> [TC_FUSA_012] Test ASILB NOC error interrupt - FUSA_ERROR_28 <<<<<<<<<<*/



TEST_FUNC Icb_Test_StatusType_e TC_ICB_005( uint8_t currentCoreNun )
{
	uint32 Icb_read;
	*(uint32*)(SAIL_ASILB_NOC_SFTYCTL_OUTEN) = 0x6;
	*(uint32*)(SAIL_ASILB_NOC_SFTYCTL_BISTCTL) = 0x1;
    return ICB_PASS;
}


/*>>>>>>>>>>>>>>> [TC_FUSA_013] Test ASILB NOC Warning interrupt - FUSA_WARN_424 <<<<<<<<<<*/

TEST_FUNC Icb_Test_StatusType_e TC_ICB_006( uint8_t currentCoreNun )
{
	uint32 Icb_read;
	*(uint32*)(SAIL_ASILB_NOC_SFTYCTL_OUTEN) = 0x5;
	*(uint32*)(SAIL_ASILB_NOC_SFTYCTL_BISTCTL) = 0x1;
    return ICB_PASS;
}


TEST_FUNC Icb_Test_StatusType_e TC_ICB_007( uint8_t currentCoreNun )
{
//	*(uint32*)(SAIL_ASILD_ISO_NOC_SFTYCTL_OUTEN) = 0x6;
//	*(uint32*)(SAIL_ASILD_ISO_NOC_SFTYCTL_BISTCTL) = 0x1;
    return ICB_PASS;
}

/*>>>>>>>>>>>>>>> [TC_FUSA_018] Test ASILD ISOLATION NOC error interrupt - FUSA_ERROR_216 <<<<<<<<<<*/

TEST_FUNC Icb_Test_StatusType_e TC_ICB_008( uint8_t currentCoreNun )
{
	*(uint32*)(SAIL_ASILD_ISO_NOC_SFTYCTL_OUTEN) = 0x6;
	*(uint32*)(SAIL_ASILD_ISO_NOC_SFTYCTL_BISTCTL) = 0x1;
    return ICB_PASS;
}

/*>>>>>>>>>>>>>>> [TC_FUSA_019] Test ASILD ISOLATION NOC warning interrupt - FUSA_WARN_427 <<<<<<<<<<*/

TEST_FUNC Icb_Test_StatusType_e TC_ICB_009( uint8_t currentCoreNun )
{
	*(uint32*)(SAIL_ASILD_ISO_NOC_SFTYCTL_OUTEN) = 0x5;
	*(uint32*)(SAIL_ASILD_ISO_NOC_SFTYCTL_BISTCTL) = 0x1;
    return ICB_PASS;
}

TEST_FUNC Icb_Test_StatusType_e TC_ICB_010( uint8_t currentCoreNun )
{
	//*(uint32*)(SAIL_ASILD_ISO_NOC_SFTYCTL_OUTEN) = 0x6;
	//*(uint32*)(SAIL_ASILD_ISO_NOC_SFTYCTL_BISTCTL) = 0x1;
    return ICB_PASS;
}

/*>>>>>>>>>>>>>>> [TC_FUSA_016] Test ASILB ISOLATION NOC error interrupt - FUSA_ERROR_29 <<<<<<<<<<*/
TEST_FUNC Icb_Test_StatusType_e TC_ICB_011( uint8_t currentCoreNun )
{

  ICB_LeManSailVersion_1 = ChipInfo_GetSailChipVersion();
  ICB_SailFamily_1 = ChipInfo_GetChipFamily();

	if (ICB_SailFamily_1 == CHIPINFO_FAMILY_LEMANSAU)
	{
	   if(ICB_LeManSailVersion_1 == ICB_LEMANS_SAIL_R1_VERSION )
	   {
	   *(uint32*)(SAIL_ASILB_ISO_NOC_SFTYCTL_OUTEN_R1) = 0x6;
	   *(uint32*)(SAIL_ASILB_ISO_NOC_SFTYCTL_BISTCTL_R1) = 0x1;
	   }
	   else
	   {
	   	*(uint32*)(SAIL_ASILB_ISO_NOC_SFTYCTL_OUTEN_R2) = 0x6;
	   	*(uint32*)(SAIL_ASILB_ISO_NOC_SFTYCTL_BISTCTL_R2) = 0x1;
	   }
    }
	else
	{
	   	*(uint32*)(SAIL_ASILB_ISO_NOC_SFTYCTL_OUTEN_R2) = 0x6;
	   	*(uint32*)(SAIL_ASILB_ISO_NOC_SFTYCTL_BISTCTL_R2) = 0x1;
	}
    return ICB_PASS;
}

/*>>>>>>>>>>>>>>> [TC_FUSA_017] Test ASILB ISOLATION NOC warning interrupt - FUSA_WARN_425 <<<<<<<<<<*/

TEST_FUNC Icb_Test_StatusType_e TC_ICB_012( uint8_t currentCoreNun )
{

  ICB_LeManSailVersion_1 = ChipInfo_GetSailChipVersion();
  ICB_SailFamily_1 = ChipInfo_GetChipFamily();

	if (ICB_SailFamily_1 == CHIPINFO_FAMILY_LEMANSAU)
	{
	   if(ICB_LeManSailVersion_1 == ICB_LEMANS_SAIL_R1_VERSION )
	   {
	   *(uint32*)(SAIL_ASILB_ISO_NOC_SFTYCTL_OUTEN_R1) = 0x5;
	   *(uint32*)(SAIL_ASILB_ISO_NOC_SFTYCTL_BISTCTL_R1) = 0x1;
	   }
	   else
	   {
	   	*(uint32*)(SAIL_ASILB_ISO_NOC_SFTYCTL_OUTEN_R2) = 0x5;
	   	*(uint32*)(SAIL_ASILB_ISO_NOC_SFTYCTL_BISTCTL_R2) = 0x1;
	   }
    }
	else
	{
	   	*(uint32*)(SAIL_ASILB_ISO_NOC_SFTYCTL_OUTEN_R2) = 0x5;
	   	*(uint32*)(SAIL_ASILB_ISO_NOC_SFTYCTL_BISTCTL_R2) = 0x1;
	}
    return ICB_PASS;
}


TEST_FUNC Icb_Test_StatusType_e vICBTestFunctionality(void)
{

	Icb_Test_StatusType_e IcbTest_Result  = ICB_FAIL;
    uint8 currentCoreNun = 0;
    uint8 ucTestCaseCnt =  12U;
    uint8 ucTotalTestCase = 12U;

	currentCoreNun = get_curr_phys_cpu_num();

    ICB_LeManSailVersion_1 = ChipInfo_GetSailChipVersion();
    ICB_SailFamily_1 = ChipInfo_GetChipFamily();

	if (0 == currentCoreNun)
   {



        if( ICB_PASS != TC_ICB_004(currentCoreNun) )
        {
           // ucTestCaseCnt--;
        }

		if( ICB_PASS != TC_ICB_005( currentCoreNun ) )
        {
           // ucTestCaseCnt--;
        }

        if( ICB_PASS != TC_ICB_006(currentCoreNun ) )
        {
           // ucTestCaseCnt--;
        }

        if( ICB_PASS != TC_ICB_007(currentCoreNun ) )
        {
            ucTestCaseCnt--;
        }

        if( ICB_PASS != TC_ICB_008(currentCoreNun) )
        {
           // ucTestCaseCnt--;
        }

		if( ICB_PASS != TC_ICB_009( currentCoreNun ) )
        {
           // ucTestCaseCnt--;
        }

        if( ICB_PASS != TC_ICB_010(currentCoreNun ) )
        {
           // ucTestCaseCnt--;
        }

        if( ICB_PASS != TC_ICB_011(currentCoreNun ) )
        {
           // ucTestCaseCnt--;
        }

        if( ICB_PASS != TC_ICB_012(currentCoreNun) )
        {
          //  ucTestCaseCnt--;
        }
		if( ICB_PASS != TC_ICB_001( currentCoreNun ) )
        {
            //ucTestCaseCnt--;
        }

        if( ICB_PASS != TC_ICB_002(currentCoreNun ) )
        {
           // ucTestCaseCnt--;
        }

        if( ICB_PASS != TC_ICB_003(currentCoreNun ) )
        {
           // ucTestCaseCnt--;
        }

        if( ucTotalTestCase == ucTestCaseCnt )
        {
            DEBUG_LOG( SAIL_INFO, "[ICB_tests] :[ Passed]\r\n", currentCoreNun );
            IcbTest_Result =  ICB_PASS;
        }
        else
        {
            DEBUG_LOG( SAIL_INFO, "[ICB_tests] :[ fail]\r\n", currentCoreNun );
            IcbTest_Result =  ICB_FAIL;
        }

        vFreeRTOSTaskDelay(100);



		//(void)slMailboxIBSend(UARTTESTFRAME_CORE0_1,58,(uint8 *)&UartRxCmdCpy[0]);
   }
	return IcbTest_Result;
}

/*========================================================================================================
**  Function :  xTestICB_El1_Wrapper
**  Icb test
** ========================================================================================================
*/


TEST_FUNC TESTerrorType_e xTestICB_El1_Wrapper(void)
{
    uint8 *find;
    uint8 currentCoreNun = 0;
    find = APPL_SAIL_Shell_gettoken(NULL);
    uint8 IcbTest_Result = 1;

	TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
	currentCoreNun = get_curr_phys_cpu_num();

    if(APPL_SAIL_Shell_stricmp("test",(char*)find))
    {
        if(ICB_PASS == vICBTestFunctionality() )
        {
             xRetStatus = MODULE_TEST_PASSED;
        }
    }
    else if(APPL_SAIL_Shell_stricmp("asild", (char*)find))
    {

    prvICBTestDebugPrint_UserDefined (  2U, (char*)find );

    find = APPL_SAIL_Shell_gettoken(NULL);

      if(APPL_SAIL_Shell_stricmp("fault",(char*)find))
      {

           TC_ICB_001( currentCoreNun );
           vFreeRTOSTaskDelay(300); /*  if execution is not returned within this time than no pass and system in crash  */
           prvICBTestDebugPrint_UserDefined (  IcbTest_Result, (char*)find );


      }
      else if(APPL_SAIL_Shell_stricmp("error",(char*)find))
      {

      	   TC_ICB_002( currentCoreNun );
      	   vFreeRTOSTaskDelay(300);
           prvICBTestDebugPrint_UserDefined (  IcbTest_Result, (char*)find );

      }
      else if(APPL_SAIL_Shell_stricmp("warning",(char*)find))
      {

           TC_ICB_003( currentCoreNun );
      	   vFreeRTOSTaskDelay(300);
           prvICBTestDebugPrint_UserDefined (  IcbTest_Result, (char*)find );

      }
    }
    else if(APPL_SAIL_Shell_stricmp("asilb", (char*)find))
    {

    prvICBTestDebugPrint_UserDefined (  2U, (char*)find );

    find = APPL_SAIL_Shell_gettoken(NULL);

      if(APPL_SAIL_Shell_stricmp("fault",(char*)find))
      {

           TC_ICB_004( currentCoreNun );
           vFreeRTOSTaskDelay(300);
           prvICBTestDebugPrint_UserDefined (  IcbTest_Result, (char*)find );


      }
      else if(APPL_SAIL_Shell_stricmp("error",(char*)find))
      {

      	   TC_ICB_005( currentCoreNun );
      	   vFreeRTOSTaskDelay(300);
           prvICBTestDebugPrint_UserDefined (  IcbTest_Result, (char*)find );

      }
      else if(APPL_SAIL_Shell_stricmp("warning",(char*)find))
      {

           TC_ICB_006( currentCoreNun );
      	   vFreeRTOSTaskDelay(300);
           prvICBTestDebugPrint_UserDefined (  IcbTest_Result, (char*)find );

      }
    }
    else if(APPL_SAIL_Shell_stricmp("isoasild", (char*)find))
    {

    prvICBTestDebugPrint_UserDefined (  2U, (char*)find );

    find = APPL_SAIL_Shell_gettoken(NULL);

      if(APPL_SAIL_Shell_stricmp("fault",(char*)find))
      {

           TC_ICB_007( currentCoreNun );
           vFreeRTOSTaskDelay(300);
           prvICBTestDebugPrint_UserDefined (  IcbTest_Result, (char*)find );


      }
      else if(APPL_SAIL_Shell_stricmp("error",(char*)find))
      {

      	   TC_ICB_008( currentCoreNun );
      	   vFreeRTOSTaskDelay(300);
           prvICBTestDebugPrint_UserDefined (  IcbTest_Result, (char*)find );

      }
      else if(APPL_SAIL_Shell_stricmp("warning",(char*)find))
      {

           TC_ICB_009( currentCoreNun );
      	   vFreeRTOSTaskDelay(300);
           prvICBTestDebugPrint_UserDefined (  IcbTest_Result, (char*)find );

      }
    }
    else if(APPL_SAIL_Shell_stricmp("isoasilb", (char*)find))
    {

    prvICBTestDebugPrint_UserDefined (  2U, (char*)find );

    find = APPL_SAIL_Shell_gettoken(NULL);

      if(APPL_SAIL_Shell_stricmp("fault",(char*)find))
      {

           TC_ICB_010( currentCoreNun );
           vFreeRTOSTaskDelay(300);
           prvICBTestDebugPrint_UserDefined (  IcbTest_Result, (char*)find );


      }
      else if(APPL_SAIL_Shell_stricmp("error",(char*)find))
      {

      	   TC_ICB_011( currentCoreNun );
      	   vFreeRTOSTaskDelay(300);
           prvICBTestDebugPrint_UserDefined (  IcbTest_Result, (char*)find );

      }
      else if(APPL_SAIL_Shell_stricmp("warning",(char*)find))
      {

           TC_ICB_012( currentCoreNun );
      	   vFreeRTOSTaskDelay(300);
           prvICBTestDebugPrint_UserDefined (  IcbTest_Result, (char*)find );

      }
    }
    else
    {
    	DEBUG_LOG( SAIL_INFO,
    	    	" Icb test Cmds are\n\r" \
    	    	" ---->example : icb asild fault/error/warning \n\r" \
    	    	" ---->noc names are  \n\r" \
    	    	" ---->asilb,  asild, isoasild,  isoasilb \n\r" \
    	    	" ---->Noc isrs are  \n\r" \
    	    	" ---->fault, error, warning  \n\r" \
    	    	);

    }
    return MODULE_TEST_PASSED;
}

TESTerrorType_e xTestICBMBWrapper(uint8 *DataBuff , uint8 *ucLength)
{
	TESTerrorType_e xRetStatus = MODULE_TEST_FAILED; 

        if ( *DataBuff == 0x00U )
        {
            if(ICB_PASS == vICBTestFunctionality() )
            {
                xRetStatus = MODULE_TEST_PASSED;
            }
        }
        else if ( *DataBuff == 0x01U )
        {
            if(ICB_PASS == TC_ICB_001(0) )
            {
                xRetStatus = MODULE_TEST_PASSED;
            }
        }
        else if ( *DataBuff == 0x02U )
        {
            if(ICB_PASS == TC_ICB_002(0) )
            {
                xRetStatus = MODULE_TEST_PASSED;
            }
        }
        else if ( *DataBuff == 0x03U )
        {
            if(ICB_PASS == TC_ICB_003(0) )
            {
                xRetStatus = MODULE_TEST_PASSED;
            }
        }
        else if ( *DataBuff == 0x04U )
        {
            if(ICB_PASS == TC_ICB_004(0) )
            {
                xRetStatus = MODULE_TEST_PASSED;
            }
        }
        else if ( *DataBuff == 0x05U )
        {
            if(ICB_PASS == TC_ICB_005(0) )
            {
                xRetStatus = MODULE_TEST_PASSED;
            }
        }
        else if ( *DataBuff == 0x06U )
        {
            if(ICB_PASS == TC_ICB_006(0) )
            {
                xRetStatus = MODULE_TEST_PASSED;
            }
        }
        else if ( *DataBuff == 0x07U )
        {
            if(ICB_PASS == TC_ICB_007(0) )
            {
                xRetStatus = MODULE_TEST_PASSED;
            }
        }
        else if ( *DataBuff == 0x08U )
        {
            if(ICB_PASS == TC_ICB_008(0) )
            {
                xRetStatus = MODULE_TEST_PASSED;
            }
        }
        else if ( *DataBuff == 0x09U )
        {
            if(ICB_PASS == TC_ICB_009(0) )
            {
                xRetStatus = MODULE_TEST_PASSED;
            }
        }
        else if ( *DataBuff == 0x0AU )
        {
            if(ICB_PASS == TC_ICB_010(0) )
            {
                xRetStatus = MODULE_TEST_PASSED;
            }
        }
        else if ( *DataBuff == 0x0BU )
        {
            if(ICB_PASS == TC_ICB_011(0) )
            {
                xRetStatus = MODULE_TEST_PASSED;
            }
        }
        else if ( *DataBuff == 0x0CU )
        {
            if(ICB_PASS == TC_ICB_012(0) )
            {
                xRetStatus = MODULE_TEST_PASSED;
            }
        }

    return xRetStatus;

}
/**********************************************************************************************************
**                                  End of file icb_tests.c                                              **
**********************************************************************************************************/
