/**********************************************************************************************************
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
**********************************************************************************************************/

/*=========================================================================================================
    File Name          : Crashdbg_api.h
    Component Name     : Crash Debug API
    Description        : Crash Debug feature APIs.
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/crashdbg/public/Crashdbg_api.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $
=========================================================================================================*/

/* Include header file guard */
#ifndef _CRASHDBG_API_H_
#define _CRASHDBG_API_H_

/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/
#include "types.h"

/*=========================================================================================================
**                                     Global defines and macros                                          **
=========================================================================================================*/
/* MD and SAIL Reset Control FSM States */
typedef enum {
    POR_ST = 0x0,                                //PowerOnReset State 
    IDLE_ST = 0x1,                               //Idle State - Normal operating mode(No crash)    
    NORMAL_RESET_ST = 0x2,                       //Reset in Normal mode/Mission mode
    BLOCK_RESIN_ST = 0x3,                        //Crash Debug mode - PASS0
    DBG_TIMER_WAIT_ST = 0x4,                     //Crash Debug mode - PASS0
    ALLOW_RESIN_FIRST_PASS_ST = 0x5,             //Crash Debug mode - PASS1 RESET
    FIRST_PASS_ST = 0x6,                         //Crash Debug mode - PASS1
    ALLOW_RESIN_SECOND_PASS_ST = 0x7,            //Crash Debug mode - PASS2 RESET
    NORM_WKUP_IN_DBG_ST = 0x8,                   //Crash Debug mode - PASS0
    ABNORM_BRINGUP_IN_DBG_ST = 0x9,              //Crash Debug mode - PASS0
    SP_PRE_DDR_INIT_ST = 0xC,                    //Crash Debug mode - PASS2
    SP_POST_DDR_INIT_ST = 0xD,                   //Crash Debug mode - PASS2    
    DDR_SELF_RFRSH_CHK_ST = 0xE,                 //Crash Debug mode - PASS2    
    ALLOW_PRE_ARES_PCIE_LINK_CHK_ST = 0xF,       //Crash Debug mode - PASS2
    MAX_STATES
}CRASHDBG_RST_CTRL_FSM_ST;

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/
/**
  Crash debug function return values
 */
typedef enum Crashdbg_Result
{
	DBG_SUCCESS = 0,	
	DBG_FAILED = 1,
	DBG_DISABLED = 2,
}Crashdbg_Result;

/**
  Crash debug feature control values
 */
typedef enum : uint32_t
{
	DEP_CRASH_DISABLED = 0, //Dependent crash disabled to avoid SAIL crash in Island mode.	
	CRASHDBG_DISABLED = 1,  //SAIL Crash debug feature disabled.
	DEP_CRASH_ENABLED = 2,  //Dependent crash enabled, to allow SAIL crash when MD crashes.
	CRASHDBG_DISABLE_PMIC_RECFG = 3, //Disable SAIL Crash debug feature and reconfigure SAIL PMIC 
}Crashdbg_CtrlType_e;
/*=========================================================================================================
**                          Function declarations										                 **
=========================================================================================================*/
/*============================================================================
**   Function : Sail Crash debug Init function
**==========================================================================*/
/*!
* 
* @brief
* Sail specific Crash debug enablement and other necessary initialization at cold boot
* 
* @param[in] 
*   None
*
* @par Dependencies
*   None
* 
* @retval
*   Return None
* 
* @par Side Effects
*   None
* 
*/
Crashdbg_Result Crashdbg_Init(void);

/*============================================================================
**   Function : SDI or PASS1 crash debug phase
**==========================================================================*/

/*!
* 
* @brief
* System Debug Image (SDI) or PASS1 debug phase Entry
* 
* @param[in] 
*   None
*
* @par Dependencies
*   None
* 
* @retval
*   Return Crashdbg_Result - DBG_FAILED = 0x0, DBG_SUCCESS = 0x1
* 
* @par Side Effects
*   None
* 
*/
void Crashdbg_pass1_sdi_entry(void);

/*============================================================================
**   Function : Ramdump or PASS2 crash debug phase
**==========================================================================*/

/*!
* 
* @brief
* Ramdump or PASS2 debug phase Entry
* 
* @param[in] 
*   None
*
* @par Dependencies
*   None
* 
* @retval
*   Return Crashdbg_Result - DBG_FAILED = 0x0, DBG_SUCCESS = 0x1
* 
* @par Side Effects
*   None
* 
*/
Crashdbg_Result Crashdbg_pass2_ramdump_entry(void);

/*============================================================================
**   Function : Get current SAIL RESET Controller FSM State
**==========================================================================*/

/*!
* 
* @brief
* Get current SAIL RESET Controller FSM State
* 
* @param[in] 
*   None
*
* @par Dependencies
*   None
* 
* @retval
*   Return FSM State [out] - 0x0:IDLE to 0xF:ALLOW_PRE_ARES_PCIE_LINK_CHK_ST
* 
* @par Side Effects
*   None
* 
*/
CRASHDBG_RST_CTRL_FSM_ST Crashdbg_GetSailResetCtrlFSMState(void);

/*============================================================================
**   Function : Disable crash debug feature upon request
**==========================================================================*/

/*!
* 
* @brief
* Disable crash debug feature or SAIL follow MD_PS_HOLD, upon request
* 
* @param[in] 
*   ctrl_type 0 - DEP_CRASH_DISABLED, 1 - CRASHDBG_DISABLED, 2 - DEP_CRASH_ENABLED 
*
* @par Dependencies
*   None
* 
* @retval
*   Crashdbg_Result - DBG_DISABLED = 0x2, DBG_FAILED = 0x1, DBG_SUCCESS = 0x0
* 
* @par Side Effects
*   None
* 
*/
Crashdbg_Result Crashdbg_disable(Crashdbg_CtrlType_e ctrl_type);


#ifdef SAILSW1 /* TODO: To be moved to crashdbg EL1 public header */ 
void Crashdbg_getLogdumpRestoreInfo(uint32 *ddr_addr, uint32 *size);
void Crashdbg_getRegdumpRestoreInfo(uint32 *ddr_addr, uint32 *size);
#endif

#endif /* _CRASHDBG_API_H_ */
