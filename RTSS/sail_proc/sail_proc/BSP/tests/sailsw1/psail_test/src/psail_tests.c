
/**********************************************************************************************************
    Copyright (c) 2021 Qualcomm Technologies, Inc.
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
    File Name          : psail_tests.c
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
#include "debug_log.h"
#include "tests.h"
#include "spinor_el1_api.h"
#include "psailInternal.h"
#include "i2c.h"
#include "HALhwio.h"

/*=========================================================================================================
**                                        Global variables and constants                                 **
=========================================================================================================*/

#define sailDbgCmd          0x1u
#define unitTestCmd         0x0u

extern xQueueHandle xPsailQueueHandle;
extern psailDebugType_e ucPsailDebugMode;
/*=========================================================================================================
**                                        Local function prototypes                                      **
=========================================================================================================*/

TEST_FUNC TESTerrorType_e prvPsailFaultInjection(void);
TEST_FUNC TESTerrorType_e prvPsailDisablePsail_err_n(void);

/*=========================================================================================================
**                                        Global function definitions                                    **
=========================================================================================================*/

/*=========================================================================================================
 @Service name        xTestPsailWrapper
 @Description         xTestPsailWrapper is call the psail module from TEST Application
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

TEST_FUNC TESTerrorType_e xTestPsailWrapper(void)
{
    Psail_QueueMsgType xMsg = {PSAIL_ERROR_OCCURED};
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint8 *find;
    uint8 len;

    find = APPL_SAIL_Shell_gettoken(NULL);

    if (APPL_SAIL_Shell_stricmp("log",(char*)find))
    {
        xRetStatus = xReadOutPsailLogs(NULL,unitTestCmd,&len);
    }else if (APPL_SAIL_Shell_stricmp("fault",(char*)find))
    {
        xRetStatus = prvPsailFaultInjection();
        if ( xRetStatus == MODULE_TEST_PASSED )
        {
            DEBUG_LOG(SAIL_INFO,"PSAIL Fault Injection Passed\n\r");
        }else
        {
            DEBUG_LOG(SAIL_INFO,"PSAIL Fault Injection Failed\n\r");
        }
    }
    else if (APPL_SAIL_Shell_stricmp("nofault",(char*)find))
    {
        xRetStatus = prvPsailDisablePsail_err_n();
    }
    else if (APPL_SAIL_Shell_stricmp("debug",(char*)find))
    {
        ucPsailDebugMode = PSAIL_DEBUG_ON;
        DEBUG_LOG(SAIL_INFO,"[PSAIL] PSAIL DEBUG Mode Entered. All Level 2 errors will now be collected and dumped to SPINOR!!!\n\r");
    }
    else if (APPL_SAIL_Shell_stricmp("read",(char*)find))
    {
        xRetStatus = xFreeRTOSQueueSend(xPsailQueueHandle,&xMsg, freertosMAX_DELAY);
    }
    else
    {
        DEBUG_LOG(SAIL_INFO,"PSAIL CMD NOT FOUND!!!\n\r");
    }

    return xRetStatus;
}


/*=========================================================================================================
**                                        Local function definitions                                     **
=========================================================================================================*/


/*=========================================================================================================
 @Service name        prvSailCharToINT
 @Description         prvSailCharToINT is used to convert string to int i.e. '674' to 674
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

TEST_FUNC uint8 prvSailCharToINT(char *str)
{
    uint8 ullresult = 0x0u;
    uint8 ucIndex = 0x0u;

    for( ucIndex = 0x0u ; str[ucIndex]!= '\0' ; ucIndex++)
    {
        ullresult = ullresult*10u + (str[ucIndex]-'0');
    }

    return ullresult;
}


/*=========================================================================================================
 @Service name        prvPsailFaultInjection
 @Description         prvPsailFaultInjection is used to inject fault on particular PSAIL
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              TESTerrorType_e <MODULE_TEST_PASSED,MODULE_TEST_FAILED>
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

TEST_FUNC TESTerrorType_e prvPsailFaultInjection(void)
{ 
    TESTerrorType_e xRetStatus = MODULE_TEST_PASSED;
    uint8 ucHardwareId = 0x0;
    uint8 data = 0x0u;
    uint8 ucPsailChannel = 0x0;
    uint8 *find;

    find = APPL_SAIL_Shell_gettoken(NULL);

    if(find == NULL)
    {
        DEBUG_LOG(SAIL_INFO,"PSAIL ChannelID Invalid\n\r");
        return MODULE_TEST_FAILED;
    }

    ucPsailChannel = prvSailCharToINT((char *)find)+PSAIL_B_ID;

    if ( ucPsailChannel < PSAIL_B_ID || ucPsailChannel >= MAX_PSAIL_ID )
    {
        DEBUG_LOG(SAIL_INFO,"PSAIL ChannelID out of Range\n\r");
        return MODULE_TEST_FAILED;
    }

    if ( I2C_SUCCESS == xI2cPingStatusFromSlave(ucPsailChannel,ucHardwareId))
    {
        DEBUG_LOG(SAIL_INFO,"PSAIL Fault Injection Started\n\r");
        data = 0x80;
        if( I2C_SUCCESS != xI2cWrite(ucPsailChannel,0xC481,0x1,&data))
        {
            DEBUG_LOG(SAIL_INFO,"I2C:Write Data Failed\n\r");
            xRetStatus = MODULE_TEST_FAILED;    
        }
        if( I2C_SUCCESS != xI2cWrite(ucPsailChannel,0xC430,0x1,&data))
        {
            DEBUG_LOG(SAIL_INFO,"I2C:Write Data Failed\n\r"); 
            xRetStatus = MODULE_TEST_FAILED;          
        }
        data = 0x10;
        if( I2C_SUCCESS != xI2cWrite(ucPsailChannel,0xC4E2,0x1,&data))
        {
            DEBUG_LOG(SAIL_INFO,"I2C:Write Data Failed\n\r");    
            xRetStatus = MODULE_TEST_FAILED;       
        }
        data = 0x2;
        if( I2C_SUCCESS != xI2cWrite(ucPsailChannel,0xC4E4,0x1,&data))
        {
            DEBUG_LOG(SAIL_INFO,"I2C:Write Data Failed\n\r");   
            xRetStatus = MODULE_TEST_FAILED;        
        }
    }else
    {
        DEBUG_LOG(SAIL_INFO,"PSAIL:%d Not Present\n\r",ucPsailChannel-0x3u);
        xRetStatus = MODULE_TEST_FAILED;
    }

    return xRetStatus;
}




TEST_FUNC TESTerrorType_e prvPsailDisablePsail_err_n(void)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_PASSED;
    uint8 ucHardwareId = 0x0u;
    uint8 data = 0x0u;
    uint8 ucPsailChannel = 0x0u;
    uint8 ucPsailIndex = 0x0u;

    for ( ucPsailIndex = 0x0u ; ucPsailIndex < psailMAX_CHIP_ON_SOC ; ucPsailIndex++ )
    {
        ucPsailChannel = ucPsailIndex + PSAIL_B_ID;
        if( I2C_SUCCESS ==  xI2cPingStatusFromSlave((uint8) ucPsailChannel , ucHardwareId))
        {
            data = 0x10;
            if( I2C_SUCCESS != xI2cWrite(ucPsailChannel,0xF9E5,0x1u,&data))
            {
                DEBUG_LOG(SAIL_ERROR,"I2C:Write Data Failed\n\r");
                xRetStatus = MODULE_TEST_FAILED;    
            }
            else
            {
                data = 0x18;
                if( I2C_SUCCESS != xI2cWrite(ucPsailChannel,0xF9E4,0x1u,&data))
                {
                    DEBUG_LOG(SAIL_ERROR,"I2C:Write Data Failed\n\r");
                    xRetStatus = MODULE_TEST_FAILED;    
                }
                else
                {
                    DEBUG_LOG(SAIL_INFO,"PSAIL Faults will not Trigger Psail_err_n to be Asserted on Psail : %d\n\r",ucPsailIndex);
                }
            }
        }
    }

    return xRetStatus;
}

/*=========================================================================================================
 @Service name        xReadOutPsailLogs
 @Description         xReadOutPsailLogs is used to Read out PSAIL stored in SPINOR Memory
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              TESTerrorType_e <MODULE_TEST_PASSED,MODULE_TEST_FAILED>
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Aync
 @Reentrancy          NO         
 @Note                None
=========================================================================================================*/

TEST_FUNC TESTerrorType_e xReadOutPsailLogs(uint8  PsailData[] , boolean bTypeOfCmd , uint8 *len )
{
    TESTerrorType_e xRetStatus = MODULE_TEST_PASSED;
    PsailSPINORDataType xpsailLogsSPINORData = {0};
    spinor_handle_t handle = NULL;
    SPINOR_STATUS result;
    uint8 ucCountIndex = 0x0u;
    uint32 ulbyteCount = 0x0;
    uint32 ulbyteoffset = 0x0;
    uint8 ucCountFaultPerPsail = 0x0;
    spinorMemInfoType el1_nor_info = {0};
    uint32 partsize_count = 0x0u;
    uint8 ucIndex = 0x0u;

    if ( NULL == PsailData && bTypeOfCmd == sailDbgCmd )
    {
        return MODULE_TEST_FAILED;
    }

    result = spinorEl1Open(&handle,SPINOR_USER_TYPE_EL1);

    if( result != SPINOR_DEVICE_DONE || handle == NULL)
    {
        DEBUG_LOG(SAIL_ERROR,"[PSAIL]:Open handle failed\r\n");
        return MODULE_TEST_FAILED;
    }

    result = spinorEl1GetMemInfo ( handle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_INFO,"[PSAIL]:GetMemInfo failed \n\r");
        xRetStatus = MODULE_TEST_FAILED;
        goto ErrSPINOR;
    }

    result = spinorEl1GetGptPartitionInfo( handle, "66768379-5905-40d3-96bc-56222766ec6f", &ulbyteoffset, &ulbyteCount);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_INFO,"[PSAIL]:GetGptPartitionInfo failed \n\r");
        xRetStatus = MODULE_TEST_FAILED;
        goto ErrSPINOR;
    }
    partsize_count = ulbyteCount;

    ulbyteCount = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

    result = spinorEl1Read ( handle, ulbyteoffset, sizeof(PsailSPINORDataType), &xpsailLogsSPINORData);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_INFO,"[PSAIL]:Read failed \n\r");
        xRetStatus = MODULE_TEST_FAILED;
        goto ErrSPINOR;
    }

    if ( xpsailLogsSPINORData.magicNumber == 0xcafe )
    {
        for (ucCountIndex = 0 ; ucCountIndex < psailMAX_CHIP_ON_SOC ; ucCountIndex++)
        {
            if( xpsailLogsSPINORData.ucPsailFaultLog[ucCountIndex].ucLvl2FaultCount )
            {
                DEBUG_LOG(SAIL_INFO,"PsailID :%d\r\n",xpsailLogsSPINORData.ucPsailFaultLog[ucCountIndex].PsailId);
                if ( bTypeOfCmd == sailDbgCmd )
                {
                PsailData[ucIndex++] = xpsailLogsSPINORData.ucPsailFaultLog[ucCountIndex].PsailId;
            }
            }
            for(ucCountFaultPerPsail = 0 ; ucCountFaultPerPsail < xpsailLogsSPINORData.ucPsailFaultLog[ucCountIndex].ucLvl2FaultCount ; ucCountFaultPerPsail++)
            {
                DEBUG_LOG(SAIL_INFO,"=== Entry:%d ===\r\n",ucCountFaultPerPsail+1);
                DEBUG_LOG(SAIL_INFO,"TimeStamp:0x%x\r\n",xpsailLogsSPINORData.ucPsailFaultLog[ucCountIndex].Lvl2ErrorInfo[ucCountFaultPerPsail].ucTimeStamp);
                DEBUG_LOG(SAIL_INFO,"ucMonitorPID:0x%x\r\n",xpsailLogsSPINORData.ucPsailFaultLog[ucCountIndex].Lvl2ErrorInfo[ucCountFaultPerPsail].ucMonitorPID);
                DEBUG_LOG(SAIL_INFO,"ucMonitorIndex:0x%x\r\n",xpsailLogsSPINORData.ucPsailFaultLog[ucCountIndex].Lvl2ErrorInfo[ucCountFaultPerPsail].ucMonitorIndex);
                DEBUG_LOG(SAIL_INFO,"ucOldError:0x%x\r\n",xpsailLogsSPINORData.ucPsailFaultLog[ucCountIndex].Lvl2ErrorInfo[ucCountFaultPerPsail].ucOldError);
                DEBUG_LOG(SAIL_INFO,"ucNewError:0x%x\r\n",xpsailLogsSPINORData.ucPsailFaultLog[ucCountIndex].Lvl2ErrorInfo[ucCountFaultPerPsail].ucNewError);
                if ( bTypeOfCmd == sailDbgCmd )
                {
                PsailData[ucIndex++] = xpsailLogsSPINORData.ucPsailFaultLog[ucCountIndex].Lvl2ErrorInfo[ucCountFaultPerPsail].ucMonitorPID;
            }
            }
            if ( bTypeOfCmd == sailDbgCmd )
            {
            PsailData[ucIndex++] = 0xFF; // Marker for end of the logs of one PSAIL
        }
        }
    }else
    {
        DEBUG_LOG(SAIL_INFO,"Psail log Empty\r\n");
    }

    result = spinorEl1Erase (handle, ulbyteoffset/ulbyteCount, 1);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_INFO,"[PSAIL]:Erase failed \n\r");
        xRetStatus = MODULE_TEST_FAILED;
        goto ErrSPINOR;
    }

    *len = ucIndex;

    ErrSPINOR:
    (void) spinorEl1Close(handle);

    return xRetStatus;

}
 
/**********************************************************************************************************
**                                  End of file psail_test.c                                             **
**********************************************************************************************************/
