/*==============================================================================

FILE:      NOC_error.c

DESCRIPTION: This file implements NOC Error Handler.

PUBLIC CLASSES:  Not Applicable

INITIALIZATION AND SEQUENCING REQUIREMENTS:  N/A

Edit History

When        Who    What, where, why
----------  ---    ----------------------------------------------------------- 
    Copyright (c) 2024 Qualcomm Technologies, Inc.
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
==============================================================================*/
#include "NOC_error.h"
#include "debug_log.h"
#include "err_fatal.h"
#include "syscall_pub.h"
#include "syscall.h"
#include "common_functions.h"
#include "HALhwio.h"
#include "sail_asild_noc_service_network.h"

ChipInfoVersionType ICB_LeManSailVersion_el2 =0U;
ChipInfoFamilyType ICB_SailFamily_el2 = CHIPINFO_FAMILY_LEMANSAU;
static NOCERR_propdata_type* NOCERR_propdata_el2;
static NOCERR_info_type* NOCInfo_el2;
static NOCERR_info_type_oem* NOCInfoOEM_el2;
static ICB_SailNocErrorLogToFuSa_type ICB_SailNocErrorLogToFuSa_el2 ;

static void NOC_Error_Log_Obs(NOCERR_info_type *noc_info);
static void NOC_Error_Log_Safety(NOCERR_info_type *noc_info,uint32_t idx);
static void NOC_Error_SideBandMangerClear( NOCERR_info_type *noc_info, NOCERR_info_type_oem *noc_info_oem);
static void NOC_SftyAggregClear( NOCERR_info_type *noc_info, uint32_t idx, uint32_t Alow, uint32_t AHigh, uint32_t Blow, uint32_t Bhigh);
static uint32_t NOC_Error_SideBandMangerSyndroLog( NOCERR_info_type *noc_info, uint32_t noc_idx);
static uint32_t NOC_Error_GetSBFltinSts0LowAsilBIso (uint32_t noc_idx, uint32_t idx, uint32_t val);
static uint32_t NOC_Error_GetSBFaultinStatus0Low (uint32_t noc_idx, uint32_t idx, uint32_t val);

void icb_el2_init(void);
void icb_el2_noc_init(void);
void icb_early_noc_config(void);
uint32_t NOC_Error_InterruptHandle(uint32_t intr_vector);
/*============================================================================
                          MACROs
============================================================================*/
#define NOC_OUT8(addr, data)   (*((volatile uint8_t *) (addr)) = ((uint8_t) (data)))
#define NOC_OUT16(addr, data)  (*((volatile uint16_t *) (addr)) = ((uint16_t) (data)))
#define NOC_OUT32(addr, data)  (*((volatile uint32_t *) (addr)) = ((uint32_t) (data)))
#define NOC_IN8(addr)   ((uint8_t) (*((volatile uint8_t *) (addr))))
#define NOC_IN16(addr)  ((uin16) (*((volatile uint16_t *) (addr))))
#define NOC_IN32(addr)  ((uint32_t)(*((volatile uint32_t *) (addr))))
//#define NOC_REG_ADDR(base,offset)   (((uint8_t*)(base)) + (offset))
#define NOC_REG_ADDR(base,offset)   (((uint32_t*)(base)) + (offset/4U))
#define REGISTER_VALID(offs) ((offs)!=REGISTER_NOT_APPLICABLE)

SAIL_DEFINE_SYSCALL((uint32_t)ICB_HVC_ID,
                    (uint32_t)ICB_PARAM_ID,
                    0,
                    icb_hvc_el2);

/* Available NOC ISR in SAIL subsystem */
typedef enum{
    ICB_NOC_FUNCTIONAL_FAULT = 0U,
    ICB_NOC_FUSA_ERROR =1U,
    ICB_NOC_FUSA_WARRNING=2U,
    ICB_INT_PER_NOC =3U
} ICB_NOC_Int_Type_el2;

/* Bit position of FautlInStatus for ASIL B in ipcat: 24th ERL/obs, 20th Cflt, 19th Uflt ,remaining are timeout */
/* Bit position creating :0th - uflt, 1st- Cflt, 2nd- obs/erl fault,  3 Timeout*/
static uint32_t ICB_ASIL_B_Noc_LUT[7U][2U] =
                                          { {0x01180000U, 7U},
                                            {0x01100000U, 6U},
                                            {0x01080000U, 5U},
                                            {0x00180000U, 3U},
                                            {0x00080000U, 1U},
                                            {0x00100000U, 2U},
                                            {0x01000000U, 4U} };

/* Bit position of FautlInStatus for ASIL B ISO in ipcat: 4th ERL, 1th Cflt, 0th Uflt */
/* Bit position creating :0th - uflt, 1st- Cflt, 2nd- obs/erl fault,  3 Timeout*/
static uint32_t ICB_ASIL_B_ISO_Noc_LUT[7U][2U] =
                                              { {0x13U, 7U},
                                                {0x3U,  3U},
                                                {0x11U, 5U},
                                                {0x12U, 3U},
                                                {0x1U,  1U},
                                                {0x2U,  2U},
                                                {0x10,  4U} };

/*===========================================================================
**  Function :  icb_early_noc_config
** ==========================================================================
*/
/*!
*
* @brief
*   Configure Asil-d noc for MD ddr access from R52
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
* @par .
*
*/
void icb_early_noc_config(void)
{
  HWIO_OUT(SAILSS_ASIL_D_ASIL_D_NOC_XM_R52_CPU0_0_DYNATTR_MAINCTL_LOW, 0x00100);
  HWIO_OUT(SAILSS_ASIL_D_ASIL_D_NOC_XM_R52_CPU0_0_DYNATTR_TRTYPELUT_LOW, 0x33210);
  HWIO_OUT(SAILSS_ASIL_D_ASIL_D_NOC_XM_R52_CPU0_1_DYNATTR_MAINCTL_LOW, 0x00100);
  HWIO_OUT(SAILSS_ASIL_D_ASIL_D_NOC_XM_R52_CPU0_1_DYNATTR_TRTYPELUT_LOW, 0x33210);
  HWIO_OUT(SAILSS_ASIL_D_ASIL_D_NOC_XM_R52_CPU1_0_DYNATTR_MAINCTL_LOW, 0x00100);
  HWIO_OUT(SAILSS_ASIL_D_ASIL_D_NOC_XM_R52_CPU1_0_DYNATTR_TRTYPELUT_LOW, 0x33210);
  HWIO_OUT(SAILSS_ASIL_D_ASIL_D_NOC_XM_R52_CPU1_1_DYNATTR_MAINCTL_LOW, 0x00100);
  HWIO_OUT(SAILSS_ASIL_D_ASIL_D_NOC_XM_R52_CPU1_1_DYNATTR_TRTYPELUT_LOW, 0x33210);
}

static uint32_t NOC_Error_GetSBFltinSts0LowAsilBIso (uint32_t noc_idx, uint32_t idx, uint32_t val)
{
    uint8_t fault_loop_cnt =0U;
    /*Pos:0 - uflt, Pos:1- Cflt, Pos:2- obs fault, Pos 3 Timeout*/
    uint32_t fault_detected = 0U;

    /* ASIL-B isolation */
    /* There are two side band HW in ASIL-D Isolation NOC, and both are present FaultInStatus0_Low
    So need check in idx 0 and idx 1 */
    /* SAILSS_ASIL_B_isolation_asil_b_noc_asil_b_isolation_noc_sbm_sbm_FaultInStatus0_Low */
    if (idx == 0U)
    {
        if(ICB_LeManSailVersion_el2 == ICB_LEMANS_SAIL_R1_VERSION )
        {
            if ( (val & 0x3U) != 0x0U)
            {
                fault_detected = val & 0x3U;
            }
            if ( (val & 0x4U) != 0x0U)
            {
                fault_detected = fault_detected | 0x8U ;
            }
        }
        else
        {
            for(fault_loop_cnt = 0U ;fault_loop_cnt < 7U ; fault_loop_cnt++)
            {
                if(( val & ICB_ASIL_B_ISO_Noc_LUT[fault_loop_cnt][0] ) == ICB_ASIL_B_ISO_Noc_LUT[fault_loop_cnt][0])
                {
                    fault_detected = ICB_ASIL_B_ISO_Noc_LUT[fault_loop_cnt][1];
                    break;
                }
            }
            if( fault_loop_cnt == 7U)
            {
                if ( (val & 0xCU) != 0U)
                {
                    fault_detected = fault_detected | 0x8U ; //
                }
            }
        }
    }
    /* SAILSS_ASIL_B_isolation_asil_b_noc_asil_b_OR_timeout_sbm_FaultInStatus0_Low */
    else  /*idx =1*/
    {
        if ( (val & 0x3U) != 0U)
        {
            fault_detected = fault_detected | 0x8U ; //
        }
    }
    return fault_detected;
}

static uint32_t NOC_Error_GetSBFaultinStatus0Low (uint32_t noc_idx, uint32_t idx, uint32_t val)
{
    uint8_t fault_loop_cnt =0U;
    /*Pos:0 - uflt, Pos:1- Cflt, Pos:2- obs fault, Pos 3 Timeout*/
    uint32_t fault_detected = 0U;

    /*ASIL-B NOC has C Fault U Fault and Err logger Fault info present in*/
    /* SAILSS_ASIL_B_asil_b_noc_asil_b_noc_sail_timeout_sbm_sbm_FaultInStatus0_Low */
    if (noc_idx == 1U)
    {
        for(fault_loop_cnt = 0U ;fault_loop_cnt < 7U ; fault_loop_cnt++)
        {
            if(( val & ICB_ASIL_B_Noc_LUT[fault_loop_cnt][0] ) == ICB_ASIL_B_Noc_LUT[fault_loop_cnt][0])
            {
                fault_detected = ICB_ASIL_B_Noc_LUT[fault_loop_cnt][1];
                break;
            }
        }
        if( fault_loop_cnt == 7U)
        {    
            /* If any bit set other than SafetyController_sail/CFlt[0], SafetyController_sail/UFlt[0]
            and  ERL_asil_b_noc_error_logger/Fault[0], it will be timeout fault */
            if ( (val & 0x2EEFFFFU) != 0U)
            {
                fault_detected = fault_detected | 0x8U ; //
            }
        }
    }
    /* ASIL-D isolation */
    if(noc_idx == 2U)
    {   
        /* There are two side band HW in ASIL-D Isolation NOC, and both are present FaultInStatus0_Low
        So need check in idx 0 and idx 1 */
        /* SAILSS_ASIL_D_isolationNoc_asild_isolation_OR_timeout_sbm_FaultInStatus0_Low */
        if (idx == 0U)
        {
            fault_detected = fault_detected | 0x8U ;
        }
        /* SAILSS_ASIL_D_isolationNoc_asild_isolation_noc_sbm_sbm_FaultInStatus0_Low */
        else /* inx=1 */
        {  
            uint32_t fault_detected_temp1 = 0;
            if ( (val & 0x3U) != 0x0U)
            {
                fault_detected_temp1 = val & 0x3U;
                fault_detected = fault_detected_temp1 | fault_detected;
            }
            if ( (val & 0x4U) != 0U)
            {
                fault_detected = fault_detected | 0x8U ;
            }
        }
    }
    /* ASIL_D */
    /* SAILSS_ASIL_D_asil_d_noc_sbm_FaultInStatus0_Low */
    if (noc_idx == 0U)
    {
        if ( val != 0x0U)
        {
            fault_detected = fault_detected | 0x8U ;
        }
    }
    return fault_detected;
}

static void NOC_SftyAggregClear( NOCERR_info_type *noc_info, uint32_t idx, uint32_t Alow, uint32_t AHigh, uint32_t Blow, uint32_t Bhigh)
{
    // Max number aggregators -32+32+32+32;
    uint8_t pos1 = 0U;
    uint8_t pos2 = 0U;
    uint8_t pos3 = 0U;

    if (Alow != 0U)
    {
        for(uint8_t pos =0U; pos< 32U; pos++)
        {
            if (((Alow >> pos) & 0x1U) == 1U )
            {
                NOC_OUT32(NOC_REG_ADDR(((noc_info->sfty_aggs)[0])[pos].addr  ,
                (noc_info->sfty_aggs)[0][pos].hw->mainctl_low ), 1U);
            }
        }
    }
    if (AHigh != 0U)
    {
        for(uint8_t pos =0U; pos< 32U; pos++)
        {
            if (((AHigh >> pos) & 0x1U) == 1U )
            {
                pos1= pos + 32U;
                NOC_OUT32(NOC_REG_ADDR(((noc_info->sfty_aggs)[0])[pos1].addr  ,
                (noc_info->sfty_aggs)[0][pos].hw->mainctl_low ), 1U);
            }
        }
    }

    if (Blow != 0U)
    {
        for(uint8_t pos =0U; pos< 32U; pos++)
        {
            if (((Blow >> pos) & 0x1U) == 1U )
            {
                pos2= pos + 64U;
                NOC_OUT32(NOC_REG_ADDR(((noc_info->sfty_aggs)[0])[pos2].addr  ,
                (noc_info->sfty_aggs)[0][pos].hw->mainctl_low ), 1U);
            }
        }
    }
    if (Bhigh != 0U)
    {
        for(uint8_t pos =0U; pos< 32U; pos++)
        {
            if (((Bhigh >> pos) & 0x1U) == 1U )
            {
                pos3= pos + 96U;
                NOC_OUT32(NOC_REG_ADDR(((noc_info->sfty_aggs)[0])[pos3].addr  ,
                (noc_info->sfty_aggs)[0][pos].hw->mainctl_low ), 1U);
            }
        }
    }
}

static uint32_t NOC_Error_SideBandMangerSyndroLog( NOCERR_info_type *noc_info,
		                                                   uint32_t noc_idx)
{
    uint8_t fault_loop_cnt =0U;
    /*Pos:0 - uflt, Pos:1- Cflt, Pos:2- obs fault, Pos 3 Timeout*/
    uint32_t fault_detected = 0U;
    uint32_t  idx;
    uint32_t  val =0U;

    for( idx = 0U; idx < noc_info->num_sbms; idx++ )
    {
        if( REGISTER_VALID(noc_info->sb_hw[idx]->faultin_status0_low) )
        {
            val = NOC_IN32(NOC_REG_ADDR(noc_info->sb_base_addrs[idx],
            noc_info->sb_hw[idx]->faultin_status0_low));
            noc_info->syndrome.sbms[idx].FAULTINSTATUS0_LOW = val;
            if( 0U != val )
            {   
                /* this kind spiting to avoid cyclomatic complexity   */
                if (noc_idx == 3U)
                {
                    fault_detected = (fault_detected | NOC_Error_GetSBFltinSts0LowAsilBIso ( noc_idx, idx,  val));
                }
                else
                {
                    fault_detected = (fault_detected | NOC_Error_GetSBFaultinStatus0Low ( noc_idx, idx,  val));
                }
            }
        }
        if( REGISTER_VALID(noc_info->sb_hw[idx]->faultin_status0_high) )
        {
            val = NOC_IN32(NOC_REG_ADDR(noc_info->sb_base_addrs[idx],
            noc_info->sb_hw[idx]->faultin_status0_high));
            noc_info->syndrome.sbms[idx].FAULTINSTATUS0_HIGH = val;
            if( 0U != val )
            {  
                /* ASIL_D */
                /* SAILSS_ASIL_D_asil_d_noc_sbm_FaultInStatus0_High */
                if (noc_idx == 0U)
                {    
                    /* this only in ASIL-D because content present in FaultInStatus0_Low will used in FaultInStatus0_High*/
                    uint32_t  fault_detected_temp2 = 0U;
                    fault_detected_temp2 = fault_detected;
                    if ( (val & 0x7U) != 0x0U)
                    {
                        fault_detected = val & 0x7U;
                    }
                    if ( (val & 0x878U) != 0U)
                    {
                        fault_detected = fault_detected | 0x8U ;
                    }
                    fault_detected = fault_detected_temp2 | fault_detected;
                }
            }
        }
        if( REGISTER_VALID(noc_info->sb_hw[idx]->faultin_status1_low) )
        {
            val = NOC_IN32(NOC_REG_ADDR(noc_info->sb_base_addrs[idx],
            noc_info->sb_hw[idx]->faultin_status1_low));
            noc_info->syndrome.sbms[idx].FAULTINSTATUS1_LOW = val;
            if( 0U != val )
            {
                fault_detected = true;
            }
        }
        if( REGISTER_VALID(noc_info->sb_hw[idx]->faultin_status1_high) )
        {
            val = NOC_IN32(NOC_REG_ADDR(noc_info->sb_base_addrs[idx],
            noc_info->sb_hw[idx]->faultin_status1_high));
            noc_info->syndrome.sbms[idx].FAULTINSTATUS1_HIGH = val;
            if( 0U != val )
            {
                fault_detected = true;
            }
        }
        if (fault_detected != 0U)
        {
            if (idx == 0x0U)
            {
                ICB_SailNocErrorLogToFuSa_el2.FAULTINSTATUS0_LOW = noc_info->syndrome.sbms[idx].FAULTINSTATUS0_LOW;
                ICB_SailNocErrorLogToFuSa_el2.FAULTINSTATUS0_HIGH = noc_info->syndrome.sbms[idx].FAULTINSTATUS0_HIGH;
                ICB_SailNocErrorLogToFuSa_el2.FAULTINSTATUS1_LOW = noc_info->syndrome.sbms[idx].FAULTINSTATUS1_LOW;
                ICB_SailNocErrorLogToFuSa_el2.FAULTINSTATUS1_HIGH = noc_info->syndrome.sbms[idx].FAULTINSTATUS1_HIGH;
                DEBUG_LOG(SAIL_ERROR,"[ICB] : noc_idx  = %d  and  Sbm_info = %d and sdm_idx = %d  \n\r" ,noc_idx , fault_detected, idx);
            }else if(idx == 0x1U)
            {
                ICB_SailNocErrorLogToFuSa_el2.FAULTINSTATUS0_LOW_2 = noc_info->syndrome.sbms[idx].FAULTINSTATUS0_LOW;
                ICB_SailNocErrorLogToFuSa_el2.FAULTINSTATUS0_HIGH_2 = noc_info->syndrome.sbms[idx].FAULTINSTATUS0_HIGH;
                ICB_SailNocErrorLogToFuSa_el2.FAULTINSTATUS1_LOW_2 = noc_info->syndrome.sbms[idx].FAULTINSTATUS1_LOW;
                ICB_SailNocErrorLogToFuSa_el2.FAULTINSTATUS1_HIGH_2 = noc_info->syndrome.sbms[idx].FAULTINSTATUS1_HIGH;
                DEBUG_LOG(SAIL_ERROR,"[ICB] : noc_idx  = %d  and  Sbm_info = %d and sdm_idx = %d  \n\r" ,noc_idx , fault_detected, idx);
            }else
            {
                // This comment is for MISRA C 
            }
            fault_detected = false;
        }
    }
    return fault_detected;
}

static void NOC_Error_SideBandMangerClear( NOCERR_info_type *noc_info, NOCERR_info_type_oem *noc_info_oem)
{
    uint32_t  idx ;
    uint32_t  val = 0U;
    /* Clear any sideband managers. */
    for( idx = 0U; idx < noc_info->num_sbms; idx++ )
    {
        if( REGISTER_VALID(noc_info->sb_hw[idx]->faultin_status0_low) )
        {
            val = NOC_IN32(NOC_REG_ADDR(noc_info->sb_base_addrs[idx],
            noc_info->sb_hw[idx]->faultin_status0_low));


            NOC_OUT32(NOC_REG_ADDR(noc_info->sb_base_addrs[idx],
            noc_info->sb_hw[idx]->faultin_en0_low),
            (NOC_IN32(NOC_REG_ADDR(noc_info->sb_base_addrs[idx],
            noc_info->sb_hw[idx]->faultin_en0_low)) & (~val|noc_info_oem->obs_mask[idx].faultin_en0_low)));
        }
        if( REGISTER_VALID(noc_info->sb_hw[idx]->faultin_status0_high) )
        {
            val = NOC_IN32(NOC_REG_ADDR(noc_info->sb_base_addrs[idx],
            noc_info->sb_hw[idx]->faultin_status0_high));

            NOC_OUT32(NOC_REG_ADDR(noc_info->sb_base_addrs[idx],
            noc_info->sb_hw[idx]->faultin_en0_high),
            (NOC_IN32(NOC_REG_ADDR(noc_info->sb_base_addrs[idx],
            noc_info->sb_hw[idx]->faultin_en0_high)) & (~val|noc_info_oem->obs_mask[idx].faultin_en0_high)));
        }
        if( REGISTER_VALID(noc_info->sb_hw[idx]->faultin_status1_low) )
        {
            val = NOC_IN32(NOC_REG_ADDR(noc_info->sb_base_addrs[idx],
            noc_info->sb_hw[idx]->faultin_status1_low));

            NOC_OUT32(NOC_REG_ADDR(noc_info->sb_base_addrs[idx],
            noc_info->sb_hw[idx]->faultin_en1_low),
            (NOC_IN32(NOC_REG_ADDR(noc_info->sb_base_addrs[idx],
            noc_info->sb_hw[idx]->faultin_en1_low)) & (~val|noc_info_oem->obs_mask[idx].faultin_en1_low)));
        }
        if( REGISTER_VALID(noc_info->sb_hw[idx]->faultin_status1_high) )
        {
            val = NOC_IN32(NOC_REG_ADDR(noc_info->sb_base_addrs[idx],
            noc_info->sb_hw[idx]->faultin_status1_high));

            NOC_OUT32(NOC_REG_ADDR(noc_info->sb_base_addrs[idx],
            noc_info->sb_hw[idx]->faultin_en1_high),
            (NOC_IN32(NOC_REG_ADDR(noc_info->sb_base_addrs[idx],
            noc_info->sb_hw[idx]->faultin_en1_high)) & (~val|noc_info_oem->obs_mask[idx].faultin_en1_high)));
        }
    }
}

static void NOC_Error_Log_Safety (NOCERR_info_type *noc_info, uint32_t idx)
{
    if( REGISTER_VALID(noc_info->sfty_ctl_hw[idx]->cflta_low) )
    {
        noc_info->syndrome.sfty_ctl[idx].CFLTA_LOW =
        NOC_IN32(NOC_REG_ADDR(noc_info->sfty_ctl_addrs[idx],
        noc_info->sfty_ctl_hw[idx]->cflta_low));
    }
    if( REGISTER_VALID(noc_info->sfty_ctl_hw[idx]->cflta_high) )
    {
        noc_info->syndrome.sfty_ctl[idx].CFLTA_HIGH =
        NOC_IN32(NOC_REG_ADDR(noc_info->sfty_ctl_addrs[idx],
        noc_info->sfty_ctl_hw[idx]->cflta_high));
    }
    if( REGISTER_VALID(noc_info->sfty_ctl_hw[idx]->uflta_low) )
    {
        noc_info->syndrome.sfty_ctl[idx].UFLTA_LOW =
        NOC_IN32(NOC_REG_ADDR(noc_info->sfty_ctl_addrs[idx],
        noc_info->sfty_ctl_hw[idx]->uflta_low));
    }
    if( REGISTER_VALID(noc_info->sfty_ctl_hw[idx]->uflta_high) )
    {
        noc_info->syndrome.sfty_ctl[idx].UFLTA_HIGH =
        NOC_IN32(NOC_REG_ADDR(noc_info->sfty_ctl_addrs[idx],
        noc_info->sfty_ctl_hw[idx]->uflta_high));
    }
    if( REGISTER_VALID(noc_info->sfty_ctl_hw[idx]->cfltb_low) )
    {
        noc_info->syndrome.sfty_ctl[idx].CFLTB_LOW =
        NOC_IN32(NOC_REG_ADDR(noc_info->sfty_ctl_addrs[idx],
        noc_info->sfty_ctl_hw[idx]->cfltb_low));
    }
    if( REGISTER_VALID(noc_info->sfty_ctl_hw[idx]->cfltb_high) )
    {
        noc_info->syndrome.sfty_ctl[idx].CFLTB_HIGH =
        NOC_IN32(NOC_REG_ADDR(noc_info->sfty_ctl_addrs[idx],
        noc_info->sfty_ctl_hw[idx]->cfltb_high));
    }
    if( REGISTER_VALID(noc_info->sfty_ctl_hw[idx]->ufltb_low) )
    {
        noc_info->syndrome.sfty_ctl[idx].UFLTB_LOW =
        NOC_IN32(NOC_REG_ADDR(noc_info->sfty_ctl_addrs[idx],
        noc_info->sfty_ctl_hw[idx]->ufltb_low));
    }
    if( REGISTER_VALID(noc_info->sfty_ctl_hw[idx]->ufltb_high) )
    {
        noc_info->syndrome.sfty_ctl[idx].UFLTB_HIGH =
        NOC_IN32(NOC_REG_ADDR(noc_info->sfty_ctl_addrs[idx],
        noc_info->sfty_ctl_hw[idx]->ufltb_high));
    }

    NOC_SftyAggregClear( noc_info, idx,
    noc_info->syndrome.sfty_ctl[idx].CFLTA_LOW ,
    noc_info->syndrome.sfty_ctl[idx].CFLTA_HIGH,
    noc_info->syndrome.sfty_ctl[idx].CFLTB_LOW,
    noc_info->syndrome.sfty_ctl[idx].CFLTB_HIGH);

    NOC_SftyAggregClear( noc_info, idx,
    noc_info->syndrome.sfty_ctl[idx].UFLTA_LOW ,
    noc_info->syndrome.sfty_ctl[idx].UFLTA_HIGH,
    noc_info->syndrome.sfty_ctl[idx].UFLTB_LOW,
    noc_info->syndrome.sfty_ctl[idx].UFLTB_HIGH);

    ICB_SailNocErrorLogToFuSa_el2.CFLTA_LOW   = noc_info->syndrome.sfty_ctl[idx].CFLTA_LOW;
    ICB_SailNocErrorLogToFuSa_el2.CFLTA_HIGH  = noc_info->syndrome.sfty_ctl[idx].CFLTA_HIGH;
    ICB_SailNocErrorLogToFuSa_el2.UFLTA_LOW   = noc_info->syndrome.sfty_ctl[idx].UFLTA_LOW;
    ICB_SailNocErrorLogToFuSa_el2.UFLTA_HIGH  = noc_info->syndrome.sfty_ctl[idx].UFLTA_HIGH;
    ICB_SailNocErrorLogToFuSa_el2.CFLTB_LOW   = noc_info->syndrome.sfty_ctl[idx].CFLTB_LOW;
    ICB_SailNocErrorLogToFuSa_el2.CFLTB_HIGH  = noc_info->syndrome.sfty_ctl[idx].CFLTB_HIGH;
    ICB_SailNocErrorLogToFuSa_el2.UFLTB_LOW   = noc_info->syndrome.sfty_ctl[idx].UFLTB_LOW;
    ICB_SailNocErrorLogToFuSa_el2.UFLTB_HIGH  = noc_info->syndrome.sfty_ctl[idx].UFLTB_HIGH;
}

static void NOC_Error_Log_Obs (NOCERR_info_type *noc_info)
{
    if( REGISTER_VALID(noc_info->erl_hw->errlog0_low) )
    {
        noc_info->syndrome.ERRLOG0_LOW =
        NOC_IN32(NOC_REG_ADDR(noc_info->erl_base_addr,noc_info->erl_hw->errlog0_low));
    }
 
    if( REGISTER_VALID(noc_info->erl_hw->errlog0_high) )
    {
        noc_info->syndrome.ERRLOG0_HIGH =
        NOC_IN32(NOC_REG_ADDR(noc_info->erl_base_addr,noc_info->erl_hw->errlog0_high));
    }
 
    if( REGISTER_VALID(noc_info->erl_hw->errlog1_low) )
    {
        noc_info->syndrome.ERRLOG1_LOW =
        NOC_IN32(NOC_REG_ADDR(noc_info->erl_base_addr,noc_info->erl_hw->errlog1_low));
    }
 
    if( REGISTER_VALID(noc_info->erl_hw->errlog1_high) )
    {
        noc_info->syndrome.ERRLOG1_HIGH =
        NOC_IN32(NOC_REG_ADDR(noc_info->erl_base_addr,noc_info->erl_hw->errlog1_high));
    }
 
    if( REGISTER_VALID(noc_info->erl_hw->errlog2_low) )
    {
        noc_info->syndrome.ERRLOG2_LOW =
        NOC_IN32(NOC_REG_ADDR(noc_info->erl_base_addr,noc_info->erl_hw->errlog2_low));
    }
 
    if( REGISTER_VALID(noc_info->erl_hw->errlog2_high) )
    {
        noc_info->syndrome.ERRLOG2_HIGH =
        NOC_IN32(NOC_REG_ADDR(noc_info->erl_base_addr,noc_info->erl_hw->errlog2_high));
    }
 
    if( REGISTER_VALID(noc_info->erl_hw->errlog3_low) )
    {
        noc_info->syndrome.ERRLOG3_LOW =
        NOC_IN32(NOC_REG_ADDR(noc_info->erl_base_addr,noc_info->erl_hw->errlog3_low));
    }
 
    if( REGISTER_VALID(noc_info->erl_hw->errlog3_high) )
    {
        noc_info->syndrome.ERRLOG3_HIGH =
        NOC_IN32(NOC_REG_ADDR(noc_info->erl_base_addr,noc_info->erl_hw->errlog3_high));
    }
 
    if( REGISTER_VALID(noc_info->erl_hw->errlog2_1_low) )
    {
        noc_info->syndrome.ERRLOG2_1_LOW =
        NOC_IN32(NOC_REG_ADDR(noc_info->erl_base_addr,noc_info->erl_hw->errlog2_1_low));
    }
 
    if( REGISTER_VALID(noc_info->erl_hw->errlog2_1_high) )
    {
        noc_info->syndrome.ERRLOG2_1_HIGH =
        NOC_IN32(NOC_REG_ADDR(noc_info->erl_base_addr,noc_info->erl_hw->errlog2_1_high));
    }
 
    if( REGISTER_VALID(noc_info->erl_hw->errlog4_3_low) )
    {
        noc_info->syndrome.ERRLOG4_3_LOW =
        NOC_IN32(NOC_REG_ADDR(noc_info->erl_base_addr,noc_info->erl_hw->errlog4_3_low));
    }
 
    if( REGISTER_VALID(noc_info->erl_hw->errlog4_3_high) )
    {
        noc_info->syndrome.ERRLOG4_3_HIGH =
        NOC_IN32(NOC_REG_ADDR(noc_info->erl_base_addr,noc_info->erl_hw->errlog4_3_high));
    }
 
    if( REGISTER_VALID(noc_info->erl_hw->errlog6_5_low) )
    {
        noc_info->syndrome.ERRLOG6_5_LOW =
        NOC_IN32(NOC_REG_ADDR(noc_info->erl_base_addr,noc_info->erl_hw->errlog6_5_low));
    }
 
    if( REGISTER_VALID(noc_info->erl_hw->errlog6_5_high) )
    {
        noc_info->syndrome.ERRLOG6_5_HIGH =
        NOC_IN32(NOC_REG_ADDR(noc_info->erl_base_addr,noc_info->erl_hw->errlog6_5_high));
    }
 
    if( REGISTER_VALID(noc_info->erl_hw->errlog8_high) )
    {
        noc_info->syndrome.ERRLOG8_HIGH =
        NOC_IN32(NOC_REG_ADDR(noc_info->erl_base_addr,noc_info->erl_hw->errlog8_high));
    }

    ICB_SailNocErrorLogToFuSa_el2.ERRLOG0_HIGH = noc_info->syndrome.ERRLOG0_HIGH;
    ICB_SailNocErrorLogToFuSa_el2.ERRLOG0_LOW = noc_info->syndrome.ERRLOG0_LOW;
    ICB_SailNocErrorLogToFuSa_el2.ERRLOG1_HIGH = noc_info->syndrome.ERRLOG1_HIGH;
    ICB_SailNocErrorLogToFuSa_el2.ERRLOG1_LOW = noc_info->syndrome.ERRLOG1_LOW;
    ICB_SailNocErrorLogToFuSa_el2.ERRLOG2_HIGH = noc_info->syndrome.ERRLOG2_HIGH;
    ICB_SailNocErrorLogToFuSa_el2.ERRLOG2_LOW = noc_info->syndrome.ERRLOG2_LOW;
    ICB_SailNocErrorLogToFuSa_el2.ERRLOG3_HIGH = noc_info->syndrome.ERRLOG3_HIGH;
    ICB_SailNocErrorLogToFuSa_el2.ERRLOG3_LOW = noc_info->syndrome.ERRLOG3_LOW;
    //(void)err_fatal(1,2); // to communicate to VIP
}


void icb_el2_init( void )
{
    uint32_t i;
    uint32_t idx;

    NOCERR_propdata_type_oem* NOCERR_propdata_oem_el2;

    ICB_LeManSailVersion_el2 = ChipInfo_GetSailChipVersion();
    ICB_SailFamily_el2 = ChipInfo_GetChipFamily();
    // DEBUG_LOG(SAIL_INFO,"[ICB] : ICB_LeManSailVersion_el2   = %d       \n\r" ,ICB_LeManSailVersion_el2);
    // DEBUG_LOG(SAIL_INFO,"[ICB] :ICB_SailFamily_el2   = %d       \n\r" ,ICB_SailFamily_el2);
    // Get device property data for configuration

    NOCERR_propdata_el2 = NOC_ErrPltfrmGetPrgmData();
    if(NOCERR_propdata_el2 == NULL)
    {
        DEBUG_LOG(SAIL_ERROR, "[ICB] : NOC ERR Propdata Cfg is NULL\r\n")
        return;  // NOC data structure is not initialized in data file
    }

    NOCERR_propdata_oem_el2 = NOC_ErrPltfrmGetPrgmData_OEM();
    if(NOCERR_propdata_oem_el2 == NULL)
    {
        DEBUG_LOG(SAIL_ERROR, "[ICB] : NOC ERR OEM Propdata Cfg is NULL\r\n")
        return;  // NOC data structure is not initialized in data file
    }

    NOCInfo_el2 = NOCERR_propdata_el2->NOCInfo;
    if(NOCInfo_el2 == NULL)
    {
        DEBUG_LOG(SAIL_ERROR, "[ICB] : NOC ERR Propdata Info Cfg is NULL\r\n")
        return;  // NOC data structure is not initialized in data file
    }

    NOCInfoOEM_el2 = NOCERR_propdata_oem_el2->NOCInfoOEM;
    if(NOCInfoOEM_el2 == NULL)
    {
        DEBUG_LOG(SAIL_ERROR, "[ICB] : NOC ERR OEM Propdata info Cfg is NULL\r\n")
        return;  // NOC data structure is not initialized in data file
    }

    /* BIST is taken care NOC diagnostic So below call is commented  */
    /* NOC_Error_Init_Target(NOCInfo_el2, NOCERR_propdata_el2->len,  NOCInfoOEM_el2); */

    /* Enable timeout clocks */
    /*
    for(i = 0; i < NOCERR_propdata_el2->num_clock_regs; i++)
    {
        NOC_OUT32(NOCERR_propdata_el2->clock_reg_addrs[i], NOCERR_propdata_oem_el2->clock_reg_vals[i]);
    }
    */
    // DEBUG_LOG(SAIL_INFO," NOCERR_propdata_oem_el2       \n\r" );
    // DEBUG_LOG(SAIL_INFO," NOCInfoOEM_el2          \n\r" );

    for(i=0U; i < NOCERR_propdata_el2->len; i++)
    {
        // register for noc error interrupt in EL1
        // Enable Interrupts (Set FAULTEN)
        if(NOCInfoOEM_el2[i].intr_enable)
        {
            /* Write sideband configuration */
            for( idx = 0U; idx < NOCInfo_el2[i].num_sbms; idx++ )
            {
                if( REGISTER_VALID(NOCInfo_el2[i].sb_hw[idx]->faultin_en0_low) )
                {
                    NOC_OUT32(NOC_REG_ADDR(NOCInfo_el2[i].sb_base_addrs[idx],
                    NOCInfo_el2[i].sb_hw[idx]->faultin_en0_low),
                    NOCInfoOEM_el2[i].sbms[idx].faultin_en0_low);
                }
                if( REGISTER_VALID(NOCInfo_el2[i].sb_hw[idx]->faultin_en0_high) )
                {
                    NOC_OUT32(NOC_REG_ADDR(NOCInfo_el2[i].sb_base_addrs[idx],
                    NOCInfo_el2[i].sb_hw[idx]->faultin_en0_high),
                    NOCInfoOEM_el2[i].sbms[idx].faultin_en0_high);
                }
                if( REGISTER_VALID(NOCInfo_el2[i].sb_hw[idx]->faultin_en1_low) )
                {
                    NOC_OUT32(NOC_REG_ADDR(NOCInfo_el2[i].sb_base_addrs[idx],
                    NOCInfo_el2[i].sb_hw[idx]->faultin_en1_low),
                    NOCInfoOEM_el2[i].sbms[idx].faultin_en1_low);
                }
                if( REGISTER_VALID(NOCInfo_el2[i].sb_hw[idx]->faultin_en1_high) )
                {
                    NOC_OUT32(NOC_REG_ADDR(NOCInfo_el2[i].sb_base_addrs[idx],
                    NOCInfo_el2[i].sb_hw[idx]->faultin_en1_high),
                    NOCInfoOEM_el2[i].sbms[idx].faultin_en1_high);
                }
            }

#if (ICB_SAIL_NOC_POS_CFG)
            /* Write PoS configuration. */
            for( idx = 0; idx < NOCInfo_el2[i].num_pos; idx++ )
            {
                if( REGISTER_VALID(NOCInfo_el2[i].pos_hw[idx]->errlog_low) )
                {
                    NOC_OUT32(NOC_REG_ADDR(NOCInfo_el2[i].pos_base_addrs[idx],
                    NOCInfo_el2[i].pos_hw[idx]->errlog_low),
                    NOCInfoOEM_el2[i].pos[idx].enable?1:0);
                }
            }
#endif

#if (ICB_SAIL_NOC_POC_CFG)
            /* Write PoC (Point of Coherency) configuration. */
            for( idx = 0; idx < NOCInfo_el2[i].num_poc; idx++ )
            {
                if( REGISTER_VALID(NOCInfo_el2[i].poc_hw[idx]->errset_low) )
                {
                    NOC_OUT32(NOC_REG_ADDR(NOCInfo_el2[i].poc_base_addrs[idx],
                    NOCInfo_el2[i].poc_hw[idx]->errset_low),
                    NOCInfoOEM_el2[i].poc[idx].enable?1:0);
                }
            }
#endif
            // set SAIL ASIL-D NoC md 0 link timeout to max 
            NOC_OUT32(0xF0D45040U, 0x0000011FU);
#if (ICB_SAIL_NOC_TIMEOUT_CFG)
            /* Write timeout enable configuration */
            for( idx = 0; idx < NOCInfo_el2[i].num_tos; idx++ )
            {
                NOC_OUT32(NOCInfo_el2[i].to_addrs[idx],
                NOCInfoOEM_el2[i].to_reg_vals[idx]);
            }
#endif
            /* Write out Safety configuration. */
            for( idx = 0; idx < NOCInfo_el2[i].num_sfty_ctl; idx++ )
            {
                if( REGISTER_VALID(NOCInfo_el2[i].sfty_ctl_hw[idx]->outen_low) )
                {
                    NOC_OUT32(NOC_REG_ADDR(NOCInfo_el2[i].sfty_ctl_addrs[idx],
                    NOCInfo_el2[i].sfty_ctl_hw[idx]->outen_low),
                    NOCInfoOEM_el2[i].sfty_ctl[idx].outen_low);
                }
            }

            if(NOCInfo_el2[i].erl_base_addr != NULL)
            {
                /* Enable faults and stall-until-serviced fault network flag. */
                NOC_OUT32(NOC_REG_ADDR(NOCInfo_el2[i].erl_base_addr,
                NOCInfo_el2[i].erl_hw->main_ctl_low),
                0x3U);
            }
        }
    }
}


uint32_t NOC_Error_InterruptHandle(uint32_t intr_vector)
{
    uint8 noc_idx;
    uint8 idx;
    uint8 int_idx;
    uint8 u8Icb_loopbreak = 0U;
    uint32_t val;
    NOCERR_info_type *noc_info = NULL;
    NOCERR_info_type_oem* noc_info_oem = NULL;
    bool fatal_fault_detected = false;
    uint32_t fault_detected = 0x0U;
 
    /* Find which NOC generated interrupt
     * Potentially multiple on a single IRQ. */
    /* NOCERR_propdata_el2->len 4 NOCs, 0 to 3 NOC data index*/
    for(noc_idx = 0U;
        noc_idx < NOCERR_propdata_el2->len;
        noc_idx++)
    {

        bool Erl_FaultDetected = false;
        //bool Sbm_FaultDetected = false;
        bool target_fatal_allowed = true;
        bool target_delay_fatal = false;
        uint8 SftyCtl_FaultDetected = 0U;
        uint8 SftyCtl_FaultDisableMask = 0U;
        uint32_t Sbm_FaultDetected = 0U;
        /* In Given NOC Check the ISR*/
        for(int_idx = 0U; int_idx < (uint8)ICB_INT_PER_NOC; int_idx++)
        {
            if( NOCInfo_el2[noc_idx].intr_vector[int_idx] == intr_vector )
            {
                noc_info = &NOCInfo_el2[noc_idx];
                noc_info_oem = &NOCInfoOEM_el2[noc_idx];
                ICB_SailNocErrorLogToFuSa_el2.NOC_ID = noc_idx;
                /* Once NOC ISR detected, Start from beginning search for new ISR number*/
                  DEBUG_LOG(SAIL_ERROR,"[ICB]: intr_vector num = %d --> Name of NOC = %s    \n\r" ,intr_vector , NOCInfo_el2[noc_idx].name );
                if(noc_info->erl_base_addr != NULL)
                {
                    // If there is an OBS fault, then log the OBS block syndrome registers
                    if (NOC_IN32(NOC_REG_ADDR(noc_info->erl_base_addr,noc_info->erl_hw->err_valid_low)) == 1U)
                    {
                        // Log OBS Block Syndrome Registers
                        Erl_FaultDetected = true;
                        NOC_Error_Log_Obs(noc_info);
                    }
                }
                /* Check for safety controller errors, if present. */
                for( idx = 0U; idx < NOCInfo_el2[noc_idx].num_sfty_ctl; idx++ )
                {
                    val = NOC_IN32(NOC_REG_ADDR(NOCInfo_el2[noc_idx].sfty_ctl_addrs[idx],
                                                 NOCInfo_el2[noc_idx].sfty_ctl_hw[idx]->status_low));
                    noc_info->syndrome.sfty_ctl[idx].STATUS_LOW = val;
                    /* Only crash for UFlt. */

                    if( val != 0U)
                    {
                        ICB_SailNocErrorLogToFuSa_el2.STATUS_LOW = noc_info->syndrome.sfty_ctl[idx].STATUS_LOW;
                        SftyCtl_FaultDetected = (uint8)val; /* 0th-Cflt, 1st-Uflt, 2nd- Done 3rd -BistFlt */
                        NOC_Error_Log_Safety(noc_info, idx);
                    }
                }

                // If Sideband Manager exists and there is a sideband fault,
                // log the Sideband Manager syndrome info
                /*  Sbm Pos:0 - uflt, Pos:1- Cflt, Pos:2- ERL fault*/
                Sbm_FaultDetected = NOC_Error_SideBandMangerSyndroLog( noc_info, noc_idx );
                #if (ICB_SAIL_NOC_POS_CFG)
                /* If a Point-of-Serialization exists and there is a fault, log it. */
                for( idx = 0; idx < noc_info->num_pos; idx++ )
                {
                    if( REGISTER_VALID(noc_info->pos_hw[idx]->errlog_low) )
                    {
                        val = NOC_IN32(NOC_REG_ADDR(noc_info->pos_base_addrs[idx],
                                                noc_info->pos_hw[idx]->errlog_low));
                        noc_info->syndrome.pos[idx].ERRLOG_LOW = val;

                        /* Check ErrVld specifically */
                        if( 0 != (val & 0x2) )
                        {
                            fault_detected = true;
                        }
                        /* No valid error, skip */
                        else
                        {
                            continue;
                        }
                    }
                    if( REGISTER_VALID(noc_info->pos_hw[idx]->errlog_high) )
                    {
                        noc_info->syndrome.pos[idx].ERRLOG_HIGH =
                        NOC_IN32(NOC_REG_ADDR(noc_info->pos_base_addrs[idx],
                                             noc_info->pos_hw[idx]->errlog_high));
                    }

                }
                #endif

                #if(ICB_SAIL_NOC_POC_CFG)
                for( idx = 0; idx < noc_info->num_poc; idx++ )
                {
                    if( REGISTER_VALID(noc_info->poc_hw[idx]->errstatus_low) )
                    {
                        val = NOC_IN32(NOC_REG_ADDR(noc_info->poc_base_addrs[idx],
                                                noc_info->poc_hw[idx]->errstatus_low));

                        /* Check ErrVld specifically */
                        if( 0 != (val & 0x1) )
                        {
                            noc_info->syndrome.poc[idx].ERRLOGSTATUS_LOW = val;
                            fault_detected = true;
                        }
                        /* No valid error, skip */
                        else
                        {
                            continue;
                        }
                    }
                    if( REGISTER_VALID(noc_info->poc_hw[idx]->errlogmain_low) )
                    {
                        val = NOC_IN32(NOC_REG_ADDR(noc_info->poc_base_addrs[idx],
                                                noc_info->poc_hw[idx]->errlogmain_low));
                        noc_info->syndrome.poc[idx].ERRLOGMAIN_LOW = val;
                    }
                    if( REGISTER_VALID(noc_info->poc_hw[idx]->errlogmain_high) )
                    {
                        val = NOC_IN32(NOC_REG_ADDR(noc_info->poc_base_addrs[idx],
                                                noc_info->poc_hw[idx]->errlogmain_high));
                        noc_info->syndrome.poc[idx].ERRLOGMAIN_HIGH = val;
                    }

                    if( REGISTER_VALID(noc_info->poc_hw[idx]->errlogaddr_low) )
                    {
                        val = NOC_IN32(NOC_REG_ADDR(noc_info->poc_base_addrs[idx],
                                                noc_info->poc_hw[idx]->errlogaddr_low));
                        noc_info->syndrome.poc[idx].ERRLOGADDR_LOW = val;
                    }
                    if( REGISTER_VALID(noc_info->poc_hw[idx]->errlogaddr_high) )
                    {
                        val = NOC_IN32(NOC_REG_ADDR(noc_info->poc_base_addrs[idx],
                                                noc_info->poc_hw[idx]->errlogaddr_high));
                        noc_info->syndrome.poc[idx].ERRLOGADDR_HIGH = val;
                    }

                    if( REGISTER_VALID(noc_info->poc_hw[idx]->errloguser_low) )
                    {
                        val = NOC_IN32(NOC_REG_ADDR(noc_info->poc_base_addrs[idx],
                                                noc_info->poc_hw[idx]->errloguser_low));
                        noc_info->syndrome.poc[idx].ERRLOGUSER_LOW = val;
                    }
                    if( REGISTER_VALID(noc_info->poc_hw[idx]->errloguser_high) )
                    {
                        val = NOC_IN32(NOC_REG_ADDR(noc_info->poc_base_addrs[idx],
                                                noc_info->poc_hw[idx]->errloguser_high));
                        noc_info->syndrome.poc[idx].ERRLOGUSER_HIGH = val;
                    }
                }
                #endif
                if( noc_info->erl_base_addr != NULL)
                {
                    /* Clear OBS error status */
                    NOC_OUT32(NOC_REG_ADDR(noc_info->erl_base_addr, noc_info->erl_hw->err_clear_low), 0x1U);
                }
                #if (ICB_SAIL_NOC_POS_CFG)
                /* Clear any PoS error status */
                for( idx = 0; idx < noc_info->num_pos; idx++ )
                {
                    if( REGISTER_VALID(noc_info->pos_hw[idx]->errlogclr_low) )
                    {
                        NOC_OUT32(NOC_REG_ADDR(noc_info->pos_base_addrs[idx],
                                           noc_info->pos_hw[idx]->errlogclr_low), 
                              0x1);
                    }
                }
                #endif

                #if (ICB_SAIL_NOC_POC_CFG)
                for( idx = 0; idx < noc_info->num_poc; idx++ )
                {
                    if( REGISTER_VALID(noc_info->poc_hw[idx]->errack_low) )
                    {
                        NOC_OUT32(NOC_REG_ADDR(noc_info->poc_base_addrs[idx],
                                           noc_info->poc_hw[idx]->errack_low), 
                              0x1);
                    }
                }
                #endif
                /* Clear any sideband managers. */
                NOC_Error_SideBandMangerClear(noc_info, noc_info_oem);
                /* Don't set error fatal until we're sure we're done.
                * Do record that we need to, though. */
                // target_fatal_allowed = NOC_Error_Handle_Target(noc_info, noc_info_oem, &target_delay_fatal);
                // if(fault_detected && noc_info_oem->error_fatal && target_fatal_allowed)
                //   if(fault_detected && noc_info_oem->error_fatal )
                //  {
                //    fatal_fault_detected = true;
                //  }

                /* FuSa Error and FuSa warning ISR reporting to SSM  */
                /* int_idx = 1 is error, int_idx = 2 is warning */
                if (int_idx != 0U)
                {
                    if (NOC_IN32(NOC_REG_ADDR(noc_info->sfty_ctl_addrs[0], noc_info->sfty_ctl_hw[0]->status_low)) != 0U)
                    {   /* BistCtl_Low */
                        /* Bist status not cleared hence doing Start and Stop is of BIST for same aggregID */
                        /* 0th Start, 1st is stop and 8 to 14 AggregId*/
                        NOC_OUT32(NOC_REG_ADDR(noc_info->sfty_ctl_addrs[0], noc_info->sfty_ctl_hw[0]->bistctl_low), 3U);
                    }
                    if (NOC_IN32(NOC_REG_ADDR(noc_info->sfty_ctl_addrs[0], noc_info->sfty_ctl_hw[0]->status_low)) != 0U)
                    {   /* OutEn_lOw ---> *//* 0th C faults 1st U faults 2nd Done */
                        /* writing 0 will clear ISRs*/
                        SftyCtl_FaultDisableMask = (~SftyCtl_FaultDetected) & 7U ;
                        /* Status_lOw ---> *//* 0th C faults, 1st U faults, 2nd Done, 3rd BistFalt */
                        NOC_OUT32(NOC_REG_ADDR(noc_info->sfty_ctl_addrs[0], noc_info->sfty_ctl_hw[0]->outen_low), SftyCtl_FaultDisableMask);
                    }
                    fault_detected = 0x0U;
                }
                /* 0xD -->1101*/ /* Correctable faults are treated has a Warning  */
                /* safety fault detected without FuSa ISR direct functional fault detected */
                /* 0th pos cflt, 2nd pos is Done and 3rd pos bist flt  */
                else if( (SftyCtl_FaultDetected & 0xDU) != 0U)
                {  
                    if (NOC_IN32(NOC_REG_ADDR(noc_info->sfty_ctl_addrs[0], noc_info->sfty_ctl_hw[0]->status_low)) != 0U)
                    {
                        SftyCtl_FaultDisableMask = (~SftyCtl_FaultDetected) & 7U ;
                        NOC_OUT32(NOC_REG_ADDR(noc_info->sfty_ctl_addrs[0], noc_info->sfty_ctl_hw[0]->outen_low), SftyCtl_FaultDisableMask);
                    }
                    fault_detected = 0x1U;
                }
                /* 1st Pos Uflt */ /* Un-Correctable faults are treated has a Error  */
                else if ( SftyCtl_FaultDetected == 2U)
                {  
                    if (NOC_IN32(NOC_REG_ADDR(noc_info->sfty_ctl_addrs[0], noc_info->sfty_ctl_hw[0]->status_low)) != 0U)
                    {
                        SftyCtl_FaultDisableMask = (~SftyCtl_FaultDetected) & 7U ;
                        NOC_OUT32(NOC_REG_ADDR(noc_info->sfty_ctl_addrs[0], noc_info->sfty_ctl_hw[0]->outen_low), SftyCtl_FaultDisableMask);
                    } 
                    fault_detected = 0x2U;
                }
                /*  Sbm Pos:0 - uflt, Pos:1- Cflt, Pos:2- ERL fault*/
                /* Un-Correctable side band faults are treated has a Error*/
                else if ((Sbm_FaultDetected & 0xFU) == 1U)
                {
                    fault_detected = 0x3U;
                }
                /* Timeout fault, ERL and correctable are Warning  */
                else if ((Sbm_FaultDetected & 0xFU) != 0U)
                {
                    fault_detected = 0x4U;
                }
                else
                {
                    fault_detected = 0xFFU;
                }

                //int_idx =(uint8) ICB_INT_PER_NOC;
                //noc_idx = (uint8)ICB_NOC_NUM;
                u8Icb_loopbreak = 1U;
                break;
            }
        }
        if (u8Icb_loopbreak == 1U)
        {
               break;
        }
    }

    //if(fatal_fault_detected)
    //{
          //Change it to SAILBSP fatal log error
          //DEBUG_LOG(SAIL_ERROR,"[ICB]:SAILBSP_ERR_FATAL_NOC_ERROR");
    //}
    /* If we never set these, we received an invalid IRQ number. */
    if(NULL == noc_info || NULL == noc_info_oem)
    {
        DEBUG_LOG(SAIL_ERROR,"[ICB]:NOC_INV_INTERRUPT_VECTOR\r\n");
    }
    return fault_detected;
}


uint32_t icb_hvc_el2(uint32_t int_num, uint32_t ICB_SailNocErrorLog, sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = NOC_Error_InterruptHandle(int_num);
    (void)sailbsp_memscpy((ICB_SailNocErrorLogToFuSa_type*)ICB_SailNocErrorLog,sizeof(ICB_SailNocErrorLogToFuSa_type), &ICB_SailNocErrorLogToFuSa_el2 ,sizeof(ICB_SailNocErrorLogToFuSa_type));
    char ICB_message_buffer[800] = {0};
    (void)snprintf (ICB_message_buffer, sizeof(ICB_message_buffer),
        "NOC_ID = 0x%X   \n\r"
        "ERRLOG0_LOW  = 0x%X      \n\r"
        "ERRLOG0_HIGH = 0x%X      \n\r"
        "ERRLOG1_LOW  = 0x%X      \n\r"
        "ERRLOG1_HIGH = 0x%X      \n\r"
        "ERRLOG2_LOW  = 0x%X      \n\r"
        "ERRLOG2_HIGH = 0x%X      \n\r"
        "ERRLOG3_LOW  = 0x%X      \n\r"
        "ERRLOG3_HIGH = 0x%X      \n\r"
        "FAULTINSTATUS0_LOW   = 0x%X       \n\r"
        "FAULTINSTATUS0_HIGH  = 0x%X       \n\r"
        "FAULTINSTATUS1_LOW   = 0x%X       \n\r"
        "FAULTINSTATUS1_HIGH  = 0x%X       \n\r"
        "FAULTINSTATUS0_LOW_2   = 0x%X       \n\r"
        "FAULTINSTATUS0_HIGH_2  = 0x%X       \n\r"
        "FAULTINSTATUS1_LOW_2   = 0x%X       \n\r"
        "FAULTINSTATUS1_HIGH_2  = 0x%X       \n\r"
        "STATUS_LOW  = 0x%X       \n\r"
        "CFLTA_LOW  = 0x%X       \n\r"
        "CFLTA_HIGH = 0x%X       \n\r"
        "UFLTA_LOW  = 0x%X       \n\r"
        "UFLTA_HIGH = 0x%X       \n\r"
        "CFLTB_LOW  = 0x%X       \n\r"
        "CFLTB_HIGH = 0x%X       \n\r"
        "UFLTB_LOW  = 0x%X       \n\r"
        "UFLTB_HIGH = 0x%X       \n\r", 
        ICB_SailNocErrorLogToFuSa_el2.NOC_ID,
        ICB_SailNocErrorLogToFuSa_el2.ERRLOG0_LOW,
        ICB_SailNocErrorLogToFuSa_el2.ERRLOG0_HIGH,
        ICB_SailNocErrorLogToFuSa_el2.ERRLOG1_LOW,
        ICB_SailNocErrorLogToFuSa_el2.ERRLOG1_HIGH,
        ICB_SailNocErrorLogToFuSa_el2.ERRLOG2_LOW,
        ICB_SailNocErrorLogToFuSa_el2.ERRLOG2_HIGH,
        ICB_SailNocErrorLogToFuSa_el2.ERRLOG3_LOW,
        ICB_SailNocErrorLogToFuSa_el2.ERRLOG3_HIGH,
        ICB_SailNocErrorLogToFuSa_el2.FAULTINSTATUS0_LOW,
        ICB_SailNocErrorLogToFuSa_el2.FAULTINSTATUS0_HIGH,
        ICB_SailNocErrorLogToFuSa_el2.FAULTINSTATUS1_LOW,
        ICB_SailNocErrorLogToFuSa_el2.FAULTINSTATUS1_HIGH,
        ICB_SailNocErrorLogToFuSa_el2.FAULTINSTATUS0_LOW_2,
        ICB_SailNocErrorLogToFuSa_el2.FAULTINSTATUS0_HIGH_2,
        ICB_SailNocErrorLogToFuSa_el2.FAULTINSTATUS1_LOW_2,
        ICB_SailNocErrorLogToFuSa_el2.FAULTINSTATUS1_HIGH_2,
        ICB_SailNocErrorLogToFuSa_el2.STATUS_LOW,
        ICB_SailNocErrorLogToFuSa_el2.CFLTA_LOW,
        ICB_SailNocErrorLogToFuSa_el2.CFLTA_HIGH,
        ICB_SailNocErrorLogToFuSa_el2.UFLTA_LOW,
        ICB_SailNocErrorLogToFuSa_el2.UFLTA_HIGH,
        ICB_SailNocErrorLogToFuSa_el2.CFLTB_LOW,
        ICB_SailNocErrorLogToFuSa_el2.CFLTB_HIGH,
        ICB_SailNocErrorLogToFuSa_el2.UFLTB_LOW,
        ICB_SailNocErrorLogToFuSa_el2.UFLTB_HIGH);

    DEBUG_LOG(SAIL_ERROR,"\n\r%s\n\r",ICB_message_buffer);
    (void)memset(&ICB_SailNocErrorLogToFuSa_el2 , 0, sizeof(ICB_SailNocErrorLogToFuSa_el2 ));
    return 0x0U;
}

void icb_el2_noc_init(void)
{
	// do not call this API from here added in booting path
    //icb_early_noc_config();
    icb_el2_init();
}

