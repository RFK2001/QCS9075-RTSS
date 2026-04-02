/*
    ===========================================================================

    Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
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
/*==============================================================================
    File Name.............. : Can_Driver.h
    Description............ : This file contains functionality of CAN driver
    Platform............... :
    SW Release Version..... :
==============================================================================*/
/*==============================================================================
|                       MISRA-C VIOLATIONS                                     |
==============================================================================*/
/*
*/
#ifndef CAN_DRV_H
#define CAN_DRV_H
#ifdef __cplusplus
extern "C"{
#endif
/*==============================================================================
|                       INCLUDE FILES                                          |
==============================================================================*/
#include "Can.h"
#include "HALhwio.h"
#include "msmhwiobase.h"
#include "sail_canss_hwio.h"
#include "cache_ops.h"
#include "Can_Fusa_Internal.h"
#define CAN_PLT_SAFERTOS_ENABLE
#ifndef CAN_PLT_SAFERTOS_ENABLE
#include "Os.h"
#else
#define ISR(x) void x(void *arg)
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

/*==============================================================================
|                       EXPORTED CONSTANTS and MACROS                          |
==============================================================================*/
#define CAN_FRAME_TYPE_MASK           (0x40000000U)
#define CAN_ID_TYPE_MASK              (0x80000000U)
#define CAN_FRAME_TYPE_SHIFT          (0x0000001EU)
#define CAN_ID_TYPE_SHIFT             (0x0000001FU)
#define TX_EVENT_FIFO_ELEMENT_ID_MASK (0x1FFFFFFFU)
#define RX_ELEMENT_ID_MASK            (0x1FFFFFFFU)
#define TX_ELEMENT_ID_MASK            (0x1FFFFFFFU)
#define TX_EVENT_FIFO_ELEM_SIZE_IN_WORDS        2u
/*Standard Message ID Filter Element*/
#define CANSS_SMFE_SFID_MASK      (0x000007ffu)
#define CANSS_SMFE_SSYNC_MASK     (0x00000001u)
#define CANSS_SMFE_SFEC_MASK      (0x00000007u)
#define CANSS_SMFE_SFT_MASK       (0x00000003u)
/*Extended Message ID Filter Element*/
#define CANSS_EMFE_EFID_MASK      (0x1fffffffu)
#define CANSS_EMFE_ESYNC_MASK     (0x00000001u)
#define CANSS_EMFE_EFEC_MASK      (0x00000007u)
#define CANSS_EMFE_EFT_MASK       (0x00000003u)
#define TIMESTAMP_NANO_SEC_DEVISOR  1000000000u
#define TIMESTAMP_CAN_BIT_TO_NS        1000000u
#define CCCR_STATIC_REG_BITS_MSK    0x0000BCFCu
#define CCCR_DEFAULT_VALUE          0x00000040u
#define DBTP_DEFAULT_VALUE          0x00000A33u
#define CAN_MAX_BUFF_DLC       64u
#define ONE_INT_SIZE           32u
#define CAN_DMA_TXE_CHANNEL     0u
#define CAN_DMA_RX0_CHANNEL     1u
#define CAN_DMA_RX1_CHANNEL     2u
#define CAN_DMA_TX_CHANNEL      3u
#define NUM_OF_CAN_DMA_CHANNELS 4u
#define CANSS_ZERO               0u
#define CANSS_ONE                1u
#define CANSS_TWO                2u
#define CANSS_THREE              3u
#define CANSS_FOUR               4u
#define CANSS_FIVE               5u
#define CANSS_SIX                6u
#define CANSS_SEVEN              7u
#define CANSS_EIGHT              8u
#define CANSS_NINE               9u
#define CANSS_TEN               10u
#define CANSS_UINT32_LEN        32u
#define CANSS_UINT64_LEN        64u
#define TX_PDU_LIST_MAX_ARR_SIZE    32u

#define CANSS_ACT_IDLE          1u
#define CANSS_NO_FILTER_EVENT   0xFFu
#define CANSS_TX_TIMESTAMP_FIFO_SIZE       32u
#define CANFD_SDU_DLC_9_CONVERT_LEN_12     12u
#define CANFD_SDU_DLC_10_CONVERT_LEN_16    16u
#define CANFD_SDU_DLC_11_CONVERT_LEN_20    20u
#define CANFD_SDU_DLC_12_CONVERT_LEN_24    24u
#define CANFD_SDU_DLC_13_CONVERT_LEN_32    32u
#define CANFD_SDU_DLC_14_CONVERT_LEN_48    48u
#define CANFD_SDU_DLC_15_CONVERT_LEN_64    64u
#define CANSS_MRAM_REG_BASE_OFFS           SAILSS_CANSS_0_CANSS_MRAM_REG_BASE_OFFS										   
#define CANSS_MAX_NONFD_DLC                 8u
#define CAN_MTTCAN_MAX_CNT                  8u
#define CAN_INTERNAL_TIMESTAMP_NUM_BITS    16u
#define WDG_TIMEOUT_VALUE                  0xFAU

#define CANSS_DMA_TRANS_DONE_BMSK                            HWIO_SAILSS_CANSS_0_CANSS_DMA_IRQ_STTS_CHNLn_DMA_TRANS_DONE_BMSK
#define CANSS_DMA_AHB_ERROR_BMSK                             HWIO_SAILSS_CANSS_0_CANSS_DMA_IRQ_STTS_CHNLn_DMA_AHB_ERROR_BMSK
#define CANSS_DMUIR_ERRORS_MASK                              0x6FEFEF3FU
#define CANSS_DMUIR_DEBUG_INTRS_MASK                         0x10101040U
#define CANSS_DMUIR_IAC_BMSK                                 HWIO_SAILSS_CANSS_0_DMUIR_IAC_BMSK
#define CANSS_DMUIR_DT_BMSK                                  HWIO_SAILSS_CANSS_0_DMUIR_DT_BMSK
#define CANSS_DMUIR_TXEED_BMSK                               HWIO_SAILSS_CANSS_0_DMUIR_TXEED_BMSK
#define CANSS_DMUIR_TXEEIW_BMSK                              HWIO_SAILSS_CANSS_0_DMUIR_TXEEIW_BMSK
#define CANSS_DMUIR_TXEEIAS_BMSK                             HWIO_SAILSS_CANSS_0_DMUIR_TXEEIAS_BMSK
#define CANSS_DMUIR_TXEEID_BMSK                              HWIO_SAILSS_CANSS_0_DMUIR_TXEEID_BMSK
#define CANSS_DMUIR_TXEENSA_BMSK                             HWIO_SAILSS_CANSS_0_DMUIR_TXEENSA_BMSK
#define CANSS_DMUIR_RX1EIO_BMSK                              HWIO_SAILSS_CANSS_0_DMUIR_RX1EIO_BMSK
#define CANSS_DMUIR_RX1ED_BMSK                               HWIO_SAILSS_CANSS_0_DMUIR_RX1ED_BMSK
#define CANSS_DMUIR_RX1EIW_BMSK                              HWIO_SAILSS_CANSS_0_DMUIR_RX1EIW_BMSK
#define CANSS_DMUIR_RX1EIAS_BMSK                             HWIO_SAILSS_CANSS_0_DMUIR_RX1EIAS_BMSK
#define CANSS_DMUIR_RX1EID_BMSK                              HWIO_SAILSS_CANSS_0_DMUIR_RX1EID_BMSK
#define CANSS_DMUIR_RX1ENSA_BMSK                             HWIO_SAILSS_CANSS_0_DMUIR_RX1EID_BMSK
#define CANSS_DMUIR_BEU_BMSK                                 HWIO_SAILSS_CANSS_0_DMUIR_BEU_BMSK
#define CANSS_DMUIR_BEC_BMSK                                 HWIO_SAILSS_CANSS_0_DMUIR_BEC_BMSK
#define CANSS_DMUIR_RX0EIO_BMSK                              HWIO_SAILSS_CANSS_0_DMUIR_RX0EIO_BMSK
#define CANSS_DMUIR_RX0ED_BMSK                               HWIO_SAILSS_CANSS_0_DMUIR_RX0ED_BMSK
#define CANSS_DMUIR_RX0EIW_BMSK                              HWIO_SAILSS_CANSS_0_DMUIR_RX0EIW_BMSK
#define CANSS_DMUIR_RX0EIAS_BMSK                             HWIO_SAILSS_CANSS_0_DMUIR_RX0EIAS_BMSK
#define CANSS_DMUIR_RX0EID_BMSK                              HWIO_SAILSS_CANSS_0_DMUIR_RX0EID_BMSK
#define CANSS_DMUIR_RX0ENSA_BMSK                             HWIO_SAILSS_CANSS_0_DMUIR_RX0ENSA_BMSK
#define CANSS_DMUIR_TXEE_BMSK                                HWIO_SAILSS_CANSS_0_DMUIR_TXEE_BMSK
#define CANSS_DMUIR_TXEIR_BMSK                               HWIO_SAILSS_CANSS_0_DMUIR_TXEIR_BMSK
#define CANSS_DMUIR_TXEWATA_BMSK                             HWIO_SAILSS_CANSS_0_DMUIR_TXEWATA_BMSK
#define CANSS_DMUIR_TXEIDLC_BMSK                             HWIO_SAILSS_CANSS_0_DMUIR_TXEIDLC_BMSK
#define CANSS_DMUIR_TXEIAS_BMSK                              HWIO_SAILSS_CANSS_0_DMUIR_TXEIAS_BMSK
#define CANSS_DMUIR_TXEIE_BMSK                               HWIO_SAILSS_CANSS_0_DMUIR_TXEIE_BMSK
#define CANSS_DMUIR_TXENSA_BMSK                              HWIO_SAILSS_CANSS_0_DMUIR_TXENSA_BMSK
#define CANSS_IR_ARA_BMSK                                    HWIO_SAILSS_CANSS_0_IR_ARA_BMSK
#define CANSS_IR_PED_BMSK                                    HWIO_SAILSS_CANSS_0_IR_PED_BMSK
#define CANSS_IR_PEA_BMSK                                    HWIO_SAILSS_CANSS_0_IR_PEA_BMSK
#define CANSS_IR_WDI_BMSK                                    HWIO_SAILSS_CANSS_0_IR_WDI_BMSK
#define CANSS_IR_BO_BMSK                                     HWIO_SAILSS_CANSS_0_IR_BO_BMSK
#define CANSS_IR_EW_BMSK                                     HWIO_SAILSS_CANSS_0_IR_EW_BMSK
#define CANSS_IR_EP_BMSK                                     HWIO_SAILSS_CANSS_0_IR_EP_BMSK
#define CANSS_IR_ELO_BMSK                                    HWIO_SAILSS_CANSS_0_IR_ELO_BMSK
#define CANSS_IR_BEU_BMSK                                    HWIO_SAILSS_CANSS_0_IR_BEU_BMSK
#define CANSS_IR_BEC_BMSK                                    HWIO_SAILSS_CANSS_0_IR_BEC_BMSK
#define CANSS_IR_DRX_BMSK                                    HWIO_SAILSS_CANSS_0_IR_DRX_BMSK
#define CANSS_IR_TOO_BMSK                                    HWIO_SAILSS_CANSS_0_IR_TOO_BMSK
#define CANSS_IR_MRAF_BMSK                                   HWIO_SAILSS_CANSS_0_IR_MRAF_BMSK
#define CANSS_IR_TSW_BMSK                                    HWIO_SAILSS_CANSS_0_IR_TSW_BMSK
#define CANSS_IR_TEFL_BMSK                                   HWIO_SAILSS_CANSS_0_IR_TEFL_BMSK
#define CANSS_IR_TEFF_BMSK                                   HWIO_SAILSS_CANSS_0_IR_TEFF_BMSK
#define CANSS_IR_TEFW_BMSK                                   HWIO_SAILSS_CANSS_0_IR_TEFW_BMSK
#define CANSS_IR_TEFN_BMSK                                   HWIO_SAILSS_CANSS_0_IR_TEFN_BMSK
#define CANSS_IR_TFE_BMSK                                    HWIO_SAILSS_CANSS_0_IR_TFE_BMSK
#define CANSS_IR_TCF_BMSK                                    HWIO_SAILSS_CANSS_0_IR_TCF_BMSK
#define CANSS_IR_TC_BMSK                                     HWIO_SAILSS_CANSS_0_IR_TC_BMSK
#define CANSS_IR_HPM_BMSK                                    HWIO_SAILSS_CANSS_0_IR_HPM_BMSK
#define CANSS_IR_RF1L_BMSK                                   HWIO_SAILSS_CANSS_0_IR_RF1L_BMSK
#define CANSS_IR_RF1F_BMSK                                   HWIO_SAILSS_CANSS_0_IR_RF1F_BMSK
#define CANSS_IR_RF1W_BMSK                                   HWIO_SAILSS_CANSS_0_IR_RF1W_BMSK
#define CANSS_IR_RF1N_BMSK                                   HWIO_SAILSS_CANSS_0_IR_RF1N_BMSK
#define CANSS_IR_RF0L_BMSK                                   HWIO_SAILSS_CANSS_0_IR_RF0L_BMSK
#define CANSS_IR_RF0F_BMSK                                   HWIO_SAILSS_CANSS_0_IR_RF0F_BMSK
#define CANSS_IR_RF0W_BMSK                                   HWIO_SAILSS_CANSS_0_IR_RF0W_BMSK
#define CANSS_IR_RF0N_BMSK                                   HWIO_SAILSS_CANSS_0_IR_RF0N_BMSK
												   

/*Function like macros to write register */
#define SET_HW_FIELD(addr,fmask,fshift,fval)                                    out_dword(((uint32*)(addr)),(((in_dword((uint32*)(addr))) & ((~(fmask)))) | (((fval) << (fshift)) & (fmask))))
#define SET_CAN_HW_FIELD(controller, reg, field, val)                          SET_HW_FIELD((Can_Controller_Arr[(controller)] + ((uint32)HWIO_SAILSS_CANSS_0_##reg##_OFFS)), ((uint32)HWIO_SAILSS_CANSS_0_##reg##_##field##_BMSK),((uint32)HWIO_SAILSS_CANSS_0_##reg##_##field##_SHFT),((uint32)(val)))
#define SET_CAN_HW_REG(controller,reg,val)                                        out_dword((Can_Controller_Arr[(controller)] + ((uint32) HWIO_SAILSS_CANSS_0_##reg##_OFFS)), ((uint32)(val)))
#define SET_CAN_HW_REG_ADDR_OFFS(controller,address_offs,reg,val)             out_dword((Can_Controller_Arr[(controller)] + ((uint32)HWIO_SAILSS_CANSS_0_##reg##_OFFS) + (address_offs)),((uint32)(val)))
#define SET_CAN_HW_FIELD_ADDR_OFFS(controller,address_offs, reg, field, val) SET_HW_FIELD((Can_Controller_Arr[(controller)] + (HWIO_SAILSS_CANSS_0_##reg##_OFFS) + ((address_offs)), (HWIO_SAILSS_CANSS_0_##reg##_##field##_BMSK),(HWIO_SAILSS_CANSS_0_##reg##_##field##_SHFT),(val))
#define SET_CAN_HW_REG_OFFS(controller,register_offs,reg,val)                 out_dword((Can_Controller_Arr[(controller)] + ((uint32)HWIO_SAILSS_CANSS_0_##reg##_OFFS((uint32)(register_offs)))),((uint32)(val)))
#define SET_CAN_HW_FIELD_OFFS(controller,register_offs, reg, field, val)     SET_HW_FIELD((Can_Controller_Arr[(controller)] + ((uint32)HWIO_SAILSS_CANSS_0_##reg##_OFFS((uint32)(register_offs)))), ((uint32) HWIO_SAILSS_CANSS_0_##reg##_##field##_BMSK), ((uint32)HWIO_SAILSS_CANSS_0_##reg##_##field##_SHFT),((uint32)(val)))
/*Function like macros to read register */
#define IN_HW_FIELD(addr,fmask,fshift)                                           (uint32)((in_dword((uint32*)(addr))&((uint32)(fmask))) >> ((uint32)(fshift)))
#define IN_CAN_HW_FIELD(controller,reg,field)                                  IN_HW_FIELD((Can_Controller_Arr[(controller)] + ((uint32)HWIO_SAILSS_CANSS_0_##reg##_OFFS)),((uint32)(HWIO_SAILSS_CANSS_0_##reg##_##field##_BMSK)), ((uint32)(HWIO_SAILSS_CANSS_0_##reg##_##field##_SHFT)))
#define IN_CAN_HW_REG(controller,reg)                                           in_dword((Can_Controller_Arr[(controller)] + ((uint32) (HWIO_SAILSS_CANSS_0_##reg##_OFFS))))
#define IN_CAN_HW_FIELD_ADDR_OFFS(controller,address_offs,reg,field)         IN_HW_FIELD((Can_Controller_Arr[(controller)] + (HWIO_SAILSS_CANSS_0_##reg##_OFFS) + (address_offs)),(HWIO_SAILSS_CANSS_0_##reg##_##field##_BMSK),(HWIO_SAILSS_CANSS_0_##reg##_##field##_SHFT))
#define IN_CAN_HW_REG_ADDR_OFFS(controller,address_offs,reg)                 in_dword((Can_Controller_Arr[(controller)] + (HWIO_SAILSS_CANSS_0_##reg##_OFFS)) + (address_offs))
#define IN_CAN_HW_REG_OFFS(controller,register_offs,reg)                      in_dword((Can_Controller_Arr[(controller)] + ((uint32)(HWIO_SAILSS_CANSS_0_##reg##_OFFS((uint32)(register_offs))))))
#define IN_CAN_HW_FIELD_OFFS(controller,register_offs, reg, field)           IN_HW_FIELD((Can_Controller_Arr[(controller)] + ((uint32)(HWIO_SAILSS_CANSS_0_##reg##_OFFS((uint32)(register_offs)))), ((uint32)HWIO_SAILSS_CANSS_0_##reg##_##field##_BMSK), ((uint32)HWIO_SAILSS_CANSS_0_##reg##_##field##_SHFT))
#define IN_CAN_MRAM_BASE(controller, offset) ((Can_Controller_Arr[(controller)] + ((uint32)SAILSS_CANSS_0_CANSS_MRAM_REG_BASE_OFFS) + (uint32)((offset) << CANSS_TWO)))
/*==============================================================================
|                       EXPORTED STRUCTURES, ENUMS, TYPEDEFS                   |
==============================================================================*/
/***** Tx Buffer Element ******/
typedef struct
{
    uint32_t ID  : 29 ;
    uint32_t RTR : 1;
    uint32_t XTD : 1;
    uint32_t ESI : 1;
}Can_MTTCAN_MRAM_TxRxBufferElementT0R0_XTD_ID_Type;
typedef struct
{
    uint32_t RES : 18 ;
    uint32_t ID     : 11 ;
    uint32_t RTR : 1;
    uint32_t XTD : 1;
    uint32_t ESI : 1;
}Can_MTTCAN_MRAM_TxRxBufferElementT0R0_STD_ID_Type;
typedef union
{
    Can_MTTCAN_MRAM_TxRxBufferElementT0R0_XTD_ID_Type XTD_ID;
    Can_MTTCAN_MRAM_TxRxBufferElementT0R0_STD_ID_Type STD_ID;
}Can_MTTCAN_MRAM_TxRxBufferElementT0R0_Type;
 typedef struct
{
    uint32  RES1 : 8;
    uint32  MM2  : 8;
    uint32  DLC  : 4;
    uint32  BRS  : 1;
    uint32  FDF  : 1;
    uint32  TSCE : 1;
    uint32  EFC  : 1;
    uint32  MM1  : 8;
}Can_MTTCAN_MRAM_TxBufferElementT1_Type;
typedef struct
{
    Can_MTTCAN_MRAM_TxRxBufferElementT0R0_Type T0;
    Can_MTTCAN_MRAM_TxBufferElementT1_Type T1;
    uint8  TxData[CAN_MAX_BUFF_DLC];
}Can_TxBufferConfigType;
/***** Tx Event Element ******/
typedef struct
{
    uint32 ID  : 29;
    uint32 RTR : 1;
    uint32 XTD : 1;
    uint32 ESI : 1;
}Can_MTTCAN_MRAM_TxEventElementE0_XTD_Type;
typedef struct
{
    uint32 RES : 18;
    uint32 ID  : 11;
    uint32 RTR : 1;
    uint32 XTD : 1;
    uint32 ESI : 1;
}Can_MTTCAN_MRAM_TxEventElementE0_STD_Type;
typedef union
{
    Can_MTTCAN_MRAM_TxEventElementE0_XTD_Type XTD_ID;
    Can_MTTCAN_MRAM_TxEventElementE0_STD_Type STD_ID;
}Can_MTTCAN_MRAM_TxEventElementE0_Type;
typedef struct
{
    uint32 TXTS : 16;
    uint32 DLC  : 4;
    uint32 BRS  : 1;
    uint32 FDF  : 1;
    uint32 ET   : 2;
    uint32 MM   : 8;
}Can_MTTCAN_MRAM_TxEventElementE1A_Type;
typedef struct
{
    uint32 TXTSP : 4;
    uint32 TSC   : 1;
    uint32 RES1  : 3;
    uint32 MM2   : 8;
    uint32 DLC   : 4;
    uint32 BRS   : 1;
    uint32 FDF   : 1;
    uint32 ET    : 2;
    uint32 MM1   : 8;
}Can_MTTCAN_MRAM_TxEventElementE1B_Type;
typedef union
{
    Can_MTTCAN_MRAM_TxEventElementE1A_Type E1A;
    Can_MTTCAN_MRAM_TxEventElementE1B_Type E1B;
} Can_MTTCAN_MRAM_TxEventElementE1_Type;
typedef struct
{
    Can_MTTCAN_MRAM_TxEventElementE0_Type E0;
    Can_MTTCAN_MRAM_TxEventElementE1_Type E1;
}Can_TxEventFifoType;
/***** Rx Buffer Element ******/
typedef struct
{
    uint32 RXTS  : 16;
    uint32 DLC   :  4;
    uint32 BRS   :  1;
    uint32 FDF   :  1;
    uint32 RES1  :  1;
    uint32 FIDX  :  7;
    uint32 ANMF  :  1;
}Can_MTTCAN_MRAM_RxBufferElementR1A_Type;
typedef struct
{
    uint32 RXTSP :  4;
    uint32 TSC   :  1;
    uint32 RES1  : 11;
    uint32 DLC   :  4;
    uint32 BRS   :  1;
    uint32 FDF   :  1;
    uint32 RES2  :  1;
    uint32 FIDX  :  7;
    uint32 ANMF  :  1;
}Can_MTTCAN_MRAM_RxBufferElementR1B_Type;
typedef union
{
    Can_MTTCAN_MRAM_RxBufferElementR1A_Type R1A;
    Can_MTTCAN_MRAM_RxBufferElementR1B_Type R1B;
} Can_MTTCAN_MRAM_RxBufferElementR1_Type;
typedef struct
{
    Can_MTTCAN_MRAM_TxRxBufferElementT0R0_Type R0;
    Can_MTTCAN_MRAM_RxBufferElementR1_Type R1;
    uint8  RxData[CAN_MAX_BUFF_DLC];
}Can_RXbuffFifoType;
/***** DMA Descriptor Type ******/
typedef struct
{
   uint32 *TransferDataAddress;
   uint32 *NextDescriptorAddress;
   uint32 *DestinationAddress;
   uint32  TransferDirection :1;
   uint32  Reserved          :7;
   uint32  TransferFragment  :1;
   uint32  ZeroValues        :7;
   uint32  Transferlength    :16;
}Can_DmaCmdDescType;
/***** DMA Buffer Types ******/
typedef struct
{
    Can_TxEventFifoType Can_TxEventElement;
    uint32 padding[6];
}Can_TxEventFifoDMAType __attribute__((aligned (32)));
typedef struct
{
    Can_TxBufferConfigType Can_TxElement;
    uint32 padding[6];
}Can_TxBufferDMAType __attribute__((aligned (32)));
typedef struct
{
    Can_RXbuffFifoType Can_RxElement;
    uint32 padding[6];
}Can_RXbuffFifoDMAType __attribute__((aligned (32)));
/***** Standard Message ID Filter Element ******/
typedef struct
{
    uint32 SFID2 : 11;
    uint32 RES   : 4;
    uint32 SSYNC : 1;
    uint32 SFID1 : 11;
    uint32 SFEC  : 3;
    uint32 SFT   : 2;
}Can_StdFilterType;
/**** Extended Message ID Filter Element *******/
typedef struct
{
    uint32 EFID1 : 29;
    uint32 EFEC  : 3;
    uint32 EFID2 : 29;
    uint32 ESYNC : 1;
    uint32 EFT   : 2;
}Can_ExtFilterType;
/****** timestamp type ******/
typedef struct{
    uint16 TimeStamp;
    PduIdType PduId;
    uint32 CanId;
    Can_HwHandleType ObjectId;
}Can_TxTimestampType;
/****** Pdu Information type ******/

typedef struct {
    PduIdType PduId;
#if(CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
    uint8     PeriodId;
    uint8     NotifiedByCallBack;
#endif

}Can_PduInfoType;

typedef struct{

    Can_PduInfoType PduInfo[TX_PDU_LIST_MAX_ARR_SIZE];
    uint8     PduReadIdx;
    uint8     PduStoreIdx;

}Can_PendingPduType;

/****** Interrupt Configuration Info  ******/
typedef struct{
    uint32 IE_RegValue;
    uint32 ILS_RegValue;
    uint32 ILE_RegValue;
}Can_RegConfigInfo;
/****** Error Types *******/
typedef enum
{
    CANSS_NO_ERROR =0u,
    CANSS_STUFF_ERROR,
    CANSS_FORM_ERROR,
    CANSS_ACK_ERROR,
    CANSS_BIT1_ERROR,
    CANSS_BIT0_ERROR,
    CANSS_CRC_ERROR,
    CANSS_NO_CHANGE
}CanSS_ErrorType;
/*==============================================================================
|                       EXPORTED VARIABLES                                     |
==============================================================================*/
#define CAN_START_SEC_CONST_ASIL_B_32
#include "Can_MemMap.h"
extern const uint32 Can_Controller_Arr[CAN_MTTCAN_MAX_CNT];
#define CAN_STOP_SEC_CONST_ASIL_B_32
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
extern uint8 Can_InterruptDisableCount
                                             [NUMBER_OF_ACTIVE_CAN_CTRL];
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_8
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
extern Can_CtrlType Can_CtrlInfo[NUMBER_OF_ACTIVE_CAN_CTRL];
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
extern Can_RegConfigInfo Can_ConfigReg[NUMBER_OF_ACTIVE_CAN_CTRL];
#define CAN_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
/*==============================================================================
|                       EXPORTED FUNCTIONS                                     |
==============================================================================*/
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType Can_Drv_Init (uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType Can_ReportDetUninit(uint8 ServiceId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType Can_Drv_SetBaudrate (uint8 ControllerId,
                                                           uint16 BaudRateConfigID);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_SetControllerMode(uint8 ControllerId,
                                                Can_ControllerStateType TransitionState);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType Can_Drv_Write(const Can_PduType* pduInfoPtr,
                                               const Can_TxHOHType* TxObj);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_TxComplete(uint8 ControllerId
#if(CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
    ,uint8 PeriodId
#endif
#ifdef CAN_PLT_SAFERTOS_ENABLE
    ,bool isIsr
#endif
);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType Can_Drv_PollModeTransition
                                    (uint8 ControllerId,
                                     Can_ControllerStateType ControllerState);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_CancelPendingTxMsgs
                                    (CAN_CtrIdType ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_DisableAllInterrupts(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_EnableAllInterrupts(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_ReadRxErrorCounter
                                   (uint8 ControllerId,
                                    uint8* RxErrorCounterPtr);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_ReadTxErrorCounter
                                   (uint8 ControllerId,
                                    uint8* TxErrorCounterPtr);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_ReadErrorState
                                   (uint8 ControllerId,
                                    Can_ErrorStateType* ErrorStatePtr);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_ProcessBusoff(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#if(CAN_ENABLE_SECURITY_EVENT == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_ProcessErrPassiveState(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern uint8 Can_Drv_ExtractConfigIndex
                                      (uint8 CanCtrID);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_Cfg_Init(const Can_ConfigType*Config);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_CtrlModeIndication
                             (uint8 ControllerId,
                              Can_ControllerStateType Can_ControllerIf_State);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#if(CAN_ENABLE_SECURITY_EVENT == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void CanDrv_Arb_Phase_Error_Handler(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void CanDrv_Data_Phase_Error_Handler(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#if((CAN_MIXED_MODE_ENABLE == STD_ON )|| (CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON))
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_Process_PendingTxList(uint8 ControllerId
#if(CAN_MAIN_FUNC_MULTIPLE_RW == STD_ON)
    ,uint8 PeriodId
#endif
);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif

#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_Config_Interrupts(uint8 ControllerId, 
                         Can_ControllerStateType TransitionState);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#if (CAN_DMA_ENABLE == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_DMA_Init(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_DMA_TxDesc_buffers_init(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_DMA_RxDesc_buffers_init(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType Can_Drv_Write_DMA(uint8 ControllerId,
                                                Can_TxBufferConfigType TxBuff);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_TxDMAComplete(uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_ProcessRxFIFODMA
                          (Can_HwType MailBox, Can_RxBufferType RxFifoCfg);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void CANSS_COMMON_DMU_HANDLER(uint8 CanCtrID);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void CANSS_COMMON_DMA_HANDLER(uint8 CanCtrID);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void CANSS_FE0_COMMON_HANDLER(uint8 CanCtrID);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void CANSS_FE1_COMMON_HANDLER(uint8 CanCtrID);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void CANSS_FE2_COMMON_HANDLER(uint8 CanCtrID);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_RxProcessBuffer
                                 (Can_HwType MailBox,
                                 uint8 RxBufferIndex);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_ClearCtrlInterrupts
                             (uint8 ControllerId);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_ProcessRxFIFO
                          (Can_HwType mailBox, Can_RxBufferType rxFifoCfg
#ifdef CAN_PLT_SAFERTOS_ENABLE
                            , bool isIsr
#endif
                           );
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void CANSS_INT0_COMMON_HANDLER(uint8 CanCtrID);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void CANSS_INT1_COMMON_HANDLER(uint8 CanCtrID);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#if(CAN_GLOBAL_TIME_SUPPORT == STD_ON)
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType Can_Drv_GetCurrentTime (
    uint8 ControllerId,
    Can_TimeStampType* TimeStampPtr
);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_Drv_EnableEgressTimeStamp (
    Can_HwHandleType TxObjID
);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType Can_Drv_GetEgressTimeStamp (
    PduIdType TxPduId,
    Can_HwHandleType Hth,
    Can_TimeStampType* TimeStampPtr
);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern Std_ReturnType Can_Drv_GetIngressTimeStamp (
    Can_HwHandleType Hrh,
    Can_TimeStampType* TimeStampPtr
);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#endif
#ifdef CAN_PLT_SAFERTOS_ENABLE
bool Can_Drv_Is_Controller_CfgValid(uint8 ControllerId);
#endif
#endif /* CAN_DRV_H */
/*==============================================================================
==============================================================================*/
