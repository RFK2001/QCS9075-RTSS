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
#ifndef CANTRCV_184_TCAN1146_REG_H
#define CANTRCV_184_TCAN1146_REG_H

/*==============================================================================
 **                      Local defines and macros                              **
 ==============================================================================*/
#define TCAN1146_DEVICEID0_REG_ADDR             (uint8)0x00
#define TCAN1146_DEVICEID1_REG_ADDR             (uint8)0x01
#define TCAN1146_DEVICEID2_REG_ADDR             (uint8)0x02
#define TCAN1146_DEVICEID3_REG_ADDR             (uint8)0x03
#define TCAN1146_DEVICEID4_REG_ADDR             (uint8)0x04
#define TCAN1146_DEVICEID5_REG_ADDR             (uint8)0x05
#define TCAN1146_DEVICEID6_REG_ADDR             (uint8)0x06
#define TCAN1146_DEVICEID7_REG_ADDR             (uint8)0x07
#define TCAN1146_REV_ID_MAJOR_REG_ADDR          (uint8)0x08
#define TCAN1146_REV_ID_MINOR_REG_ADDR          (uint8)0x09
#define TCAN1146_SCRATCH_PAD_SPI_REG_ADDR       (uint8)0x0F

#define TCAN1146_MODE_CONTROL_REG_ADDR          (uint8)0x10
#define  TCAN1146_MODE_SEL_BIT_POS              (uint8)0
#define  TCAN1146_MODE_SEL_BIT_MASK             \
    (uint8)(7u << TCAN1146_MODE_SEL_BIT_POS)
#define  TCAN1146_MODE_SEL_SLEEP                (uint8)0x1
#define  TCAN1146_MODE_SEL_STANDBY              (uint8)0x4
#define  TCAN1146_MODE_SEL_LISTEN               (uint8)0x5
#define  TCAN1146_MODE_SEL_NORMAL               (uint8)0x7
#define  TCAN1146_FD_EN_BIT_POS                 (uint8)5
#define  TCAN1146_DTO_DIS_BIT_POS               (uint8)6
#define  TCAN1146_SW_EN_BIT_POS                 (uint8)7
#define TCAN1146_WAKE_PIN_CONFIG_REG_ADDR       (uint8)0x11
#define  TCAN1146_WAKE_CONFIG_BIT_POS           (uint8)6
#define  TCAN1146_WAKE_CONFIG_PULSE             (uint8)0x3
#define TCAN1146_PIN_CONFIG_REG_ADDR            (uint8)0x12
#define  TCAN1146_RXD_WK_CONFIG_BIT_POS         (uint8)2
#define  TCAN1146_N_INT_SEL_BIT_POS             (uint8)3
#define TCAN1146_WD_CONFIG_1_REG_ADDR           (uint8)0x13
#define TCAN1146_WD_CONFIG_2_REG_ADDR           (uint8)0x14
#define TCAN1146_WD_INPUT_TRIG_REG_ADDR         (uint8)0x15
#define TCAN1146_WD_RST_PULSE_REG_ADDR          (uint8)0x16
#define TCAN1146_FSM_CONFIG_REG_ADDR            (uint8)0x17
#define  TCAN1146_FS_DIS_BIT_POS                (uint8)0
#define  TCAN1146_FS_CNTR_EN_BIT_POS            (uint8)7
#define TCAN1146_FSM_COUNTER_REG_ADDR           (uint8)0x18
#define TCAN1146_DEVICE_RESET_REG_ADDR          (uint8)0x19
#define  TCAN1146_SF_RST_BIT_POS                (uint8)1
#define TCAN1146_DEVICE_CONFIG1_REG_ADDR        (uint8)0x1A
#define  TCAN1146_LIMP_DIS_BIT_POS              (uint8)4
#define  TCAN1146_INH_DIS_BIT_POS               (uint8)6
#define TCAN1146_DEVICE_CONFIG2_REG_ADDR        (uint8)0x1B
#define TCAN1146_SWE_DIS_REG_ADDR               (uint8)0x1C
#define  TCAN1146_CANSLNT_SWE_DIS_BIT_POS       (uint8)2
#define  TCAN1146_SWE_DIS_BIT_POS               (uint8)7
#define TCAN1146_SDO_CONFIG_REG_ADDR            (uint8)0x29
#define  TCAN1146_SDO_CONFIG_BIT_POS            (uint8)0
#define TCAN1146_WD_QA_CONFIG_REG_ADDR          (uint8)0x2D
#define TCAN1146_WD_QA_ANSWER_REG_ADDR          (uint8)0x2E
#define TCAN1146_WD_QA_QUESTION_REG_ADDR        (uint8)0x2F
/*
 * Selective wake registers
 */
#define TCAN1146_SW_ID1_REG_ADDR                (uint8)0x30
#define  TCAN1146_SW_ID1_EXTID_17_10_BIT_MASK   (uint8)0xFF /* [7:0] Extended id bits 17:10 bitmask */
#define TCAN1146_SW_ID2_REG_ADDR                (uint8)0x31
#define  TCAN1146_SW_ID2_EXTID_9_2_BIT_MASK     (uint8)0xFF /* [7:0] Extended id bits 9:2 bitmask */
#define TCAN1146_SW_ID3_REG_ADDR                (uint8)0x32
#define  TCAN1146_SW_ID3_EXTID_1_0_BIT_POS      (uint8)6
#define  TCAN1146_SW_ID3_IDE_BIT_POS            (uint8)5
#define  TCAN1146_SW_ID3_EXTID_1_0_BIT_MASK     (uint8)0xC0 /* [7:6] Extended id bits 1:0 bitmask */
#define  TCAN1146_SW_ID3_EXTID_28_24_BIT_MASK   (uint8)0x1F /* [4:0] Extended id bits 28:24 bitmask */
#define  TCAN1146_SW_ID3_ID_10_6_BIT_MASK       (uint8)0x1F /* [4:0] Classic id bits 10:6 bitmask */
#define TCAN1146_SW_ID4_REG_ADDR                (uint8)0x33
#define  TCAN1146_SW_ID4_EXTID_23_18_BIT_POS    (uint8)2
#define  TCAN1146_SW_ID4_ID_5_0_BIT_POS         (uint8)2
#define  TCAN1146_SW_ID4_EXTID_23_18_BIT_MASK   (uint8)0xFC /* [7:2] Extended id bits 23:18 bitmask */
#define  TCAN1146_SW_ID4_ID_5_0_BIT_MASK        (uint8)0xFC /* [7:2] Classic id bits 5:0 bitmask */
#define TCAN1146_SW_ID_MASK1_REG_ADDR           (uint8)0x34
#define  TCAN1146_SW_ID_MASK1_EXTID_17_16_BIT_MASK   (uint8)0x03    /* [1:0] Extended id bits 17:16 bitmask */
#define TCAN1146_SW_ID_MASK2_REG_ADDR           (uint8)0x35
#define  TCAN1146_SW_ID_MASK2_EXTID_15_8_BIT_MASK   (uint8)0xFF     /* [7:0] Extended id bits 15:8 bitmask */
#define TCAN1146_SW_ID_MASK3_REG_ADDR           (uint8)0x36
#define  TCAN1146_SW_ID_MASK3_EXTID_7_0_BIT_MASK   (uint8)0xFF      /* [7:0] Extended id bits 7:0 bitmask */
#define TCAN1146_SW_ID_MASK4_REG_ADDR           (uint8)0x37
#define  TCAN1146_SW_ID_MASK4_EXTID_28_21_BIT_MASK   (uint8)0xFF    /* [7:0] Extended id bits 28:21 bitmask */
#define  TCAN1146_SW_ID_MASK4_ID_10_3_BIT_MASK  (uint8)0xFF /* [7:0] Classic id bits 10:3 bitmask */
#define TCAN1146_SW_ID_MASK_DLC_REG_ADDR        (uint8)0x38
#define  TCAN1146_SW_ID_MASK_DLC_EXTID_20_18_BIT_POS     (uint8)5
#define  TCAN1146_SW_ID_MASK_DLC_ID_2_0_BIT_POS (uint8)5
#define  TCAN1146_SW_ID_MASK_DLC_BIT_POS        (uint8)1
#define  TCAN1146_SW_ID_MASK_DLC_EXTID_20_18_BIT_MASK   (uint8)0xE0 /* [7:5] Extended id bits 20:18 bitmask */
#define  TCAN1146_SW_ID_MASK_DLC_ID_2_0_BIT_MASK     (uint8)0xE0    /* [7:5] Classic id bits 2:0 bitmask */
#define  TCAN1146_SW_ID_MASK_DLC_BIT_MASK       (uint8)0x1E /* [4:1] SW frame DLC bitmask */
#define TCAN1146_SW_DATA_0_REG_ADDR             (uint8)0x39
#define TCAN1146_SW_DATA_1_REG_ADDR             (uint8)0x3A
#define TCAN1146_SW_DATA_2_REG_ADDR             (uint8)0x3B
#define TCAN1146_SW_DATA_3_REG_ADDR             (uint8)0x3C
#define TCAN1146_SW_DATA_4_REG_ADDR             (uint8)0x3D
#define TCAN1146_SW_DATA_5_REG_ADDR             (uint8)0x3E
#define TCAN1146_SW_DATA_6_REG_ADDR             (uint8)0x3F
#define TCAN1146_SW_DATA_7_REG_ADDR             (uint8)0x40
#define TCAN1146_SW_CFG1_REG_ADDR               (uint8)0x44
#define  TCAN1146_SW_CFG1_CANDR_50_KBPS         (uint8)0
#define  TCAN1146_SW_CFG1_CANDR_100_KBPS        (uint8)1
#define  TCAN1146_SW_CFG1_CANDR_125_KBPS        (uint8)2
#define  TCAN1146_SW_CFG1_CANDR_250_KBPS        (uint8)3
#define  TCAN1146_SW_CFG1_CANDR_500_KBPS        (uint8)5
#define  TCAN1146_SW_CFG1_CANDR_1_MBPS          (uint8)7
#define  TCAN1146_SW_CFG1_FD_PASSIVE_BIT_POS    (uint8)7
#define  TCAN1146_SW_CFG1_CANDR_BIT_POS         (uint8)4
#define  TCAN1146_SW_CFG1_FD_DR_BIT_POS         (uint8)2
#define TCAN1146_SW_CFG2_REG_ADDR               (uint8)0x45
#define TCAN1146_SW_CFG3_REG_ADDR               (uint8)0x46
#define TCAN1146_SW_CFG4_REG_ADDR               (uint8)0x47
#define  TCAN1146_SW_CFG4_SWCFG_BIT_POS         (uint8)7
/* Interrupt register*/
#define TCAN1146_INT_GLOBAL_REG_ADDR            (uint8)0x50
#define TCAN1146_INT_1_REG_ADDR                 (uint8)0x51
#define  TCAN1146_CANINT_BIT_POS                (uint8)6
#define  TCAN1146_LWU_BIT_POS                   (uint8)5
#define  TCAN1146_WKERR_BIT_POS                 (uint8)4
#define  TCAN1146_FRAME_OVF_BIT_POS             (uint8)3
#define  TCAN1146_CANSLNT_BIT_POS               (uint8)2
#define  TCAN1146_CANTO_BIT_POS                 (uint8)1
#define  TCAN1146_CANDOM_BIT_POS                (uint8)0
#define  TCAN1146_INT_1_RSVD_MASK               (uint8)0xFF
#define TCAN1146_INT_2_REG_ADDR                 (uint8)0x52
#define  TCAN1146_PWRON_BIT_POS                 (uint8)6
#define  TCAN1146_INT_2_RSVD_MASK               (uint8)0xDF
#define TCAN1146_INT_3_REG_ADDR                 (uint8)0x53
#define  TCAN1146_SWERR_BIT_POS                 (uint8)6
#define  TCAN1146_INT_3_RSVD_MASK               (uint8)0xA1
#define TCAN1146_INT_CANBUS_REG_ADDR            (uint8)0x54
#define  TCAN1146_INT_CANBUS_RSVD_MASK          (uint8)0x7F
#define TCAN1146_INT_GLOBAL_ENABLE_REG_ADDR     (uint8)0x55
#define TCAN1146_INT_ENABLE_1_REG_ADDR          (uint8)0x56
#define  TCAN1146_CANINT_ENABLE_BIT_POS         (uint8)6
#define  TCAN1146_LWU_ENABLE_BIT_POS            (uint8)5
#define  TCAN1146_WKERR_ENABLE_BIT_POS          (uint8)4
#define  TCAN1146_FRAME_OVF_ENABLE_BIT_POS      (uint8)3
#define TCAN1146_INT_ENABLE_2_REG_ADDR          (uint8)0x57
#define TCAN1146_INT_ENABLE_3_REG_ADDR          (uint8)0x58
#define  TCAN1146_SWERR_ENABLE_BIT_POS          (uint8)6
#define TCAN1146_INT_ENABLE_CANBUS_REG_ADDR     (uint8)0x59

#endif /* CANTRCV_184_TCAN1146_REG_H */

/*==============================================================================
  |                               END OF FILE                                    |
  ==============================================================================*/
