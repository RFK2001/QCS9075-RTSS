/*
===========================================================================
*/
/**
    @file  DioCfg.h
    @brief Config Header file for Dio driver

*/
/*
    ===========================================================================

    Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
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
#ifndef DIO_CFG_H
#define DIO_CFG_H
/*==============================================================================
**                      Include Section                                       **
==============================================================================*/

/*==============================================================================
**                      Global Macro                                          **
==============================================================================*/

#define DIO_DEV_ERROR_DETECT	(STD_OFF)
#define DIO_FLIP_CHANNEL_API	(STD_ON)
#define DIO_VERSION_INFO_API	(STD_OFF)

#define DIO_PORT_PIN_0			(0U)
#define DIO_PORT_PIN_1			(1U)
#define DIO_PORT_PIN_2			(2U)
#define DIO_PORT_PIN_3			(3U)
#define DIO_PORT_PIN_4			(4U)
#define DIO_PORT_PIN_5			(5U)
#define DIO_PORT_PIN_6			(6U)
#define DIO_PORT_PIN_7			(7U)
#define DIO_PORT_PIN_8			(8U)
#define DIO_PORT_PIN_9			(9U)
#define DIO_PORT_PIN_10			(10U)
#define DIO_PORT_PIN_11			(11U)
#define DIO_PORT_PIN_12			(12U)
#define DIO_PORT_PIN_13			(13U)
#define DIO_PORT_PIN_14			(14U)
#define DIO_PORT_PIN_15			(15U)
#define DIO_PORT_PIN_16			(16U)
#define DIO_PORT_PIN_17			(17U)
#define DIO_PORT_PIN_18			(18U)
#define DIO_PORT_PIN_19			(19U)
#define DIO_PORT_PIN_20			(20U)
#define DIO_PORT_PIN_21			(21U)
#define DIO_PORT_PIN_22			(22U)
#define DIO_PORT_PIN_23			(23U)
#define DIO_PORT_PIN_24			(24U)
#define DIO_PORT_PIN_25			(25U)
#define DIO_PORT_PIN_26			(26U)
#define DIO_PORT_PIN_27			(27U)
#define DIO_PORT_PIN_28			(28U)
#define DIO_PORT_PIN_29			(29U)
#define DIO_PORT_PIN_30			(30U)
#define DIO_PORT_PIN_31			(31U)
#define DIO_PORT_PIN_32			(32U)
#define DIO_PORT_PIN_33			(33U)
#define DIO_PORT_PIN_34			(34U)
#define DIO_PORT_PIN_35			(35U)
#define DIO_PORT_PIN_36			(36U)
#define DIO_PORT_PIN_37			(37U)
#define DIO_PORT_PIN_38			(38U)
#define DIO_PORT_PIN_39			(39U)
#define DIO_PORT_PIN_40			(40U)
#define DIO_PORT_PIN_41			(41U)
#define DIO_PORT_PIN_42			(42U)
#define DIO_PORT_PIN_43			(43U)
#define DIO_PORT_PIN_44			(44U)
#define DIO_PORT_PIN_45			(45U)
#define DIO_PORT_PIN_46			(46U)
#define DIO_PORT_PIN_47			(47U)
#define DIO_PORT_PIN_48			(48U)
#define DIO_PORT_PIN_49			(49U)
#define DIO_PORT_PIN_50			(50U)
#define DIO_PORT_PIN_51			(51U)
#define DIO_PORT_PIN_52			(52U)
#define DIO_PORT_PIN_53			(53U)
#define DIO_PORT_PIN_54			(54U)
#define DIO_PORT_PIN_55			(55U)
#define DIO_PORT_PIN_56			(56U)
#define DIO_PORT_PIN_57			(57U)
#define DIO_PORT_PIN_58			(58U)
#define DIO_PORT_PIN_59			(59U)
#define DIO_PORT_PIN_60			(60U)
#define DIO_PORT_PIN_61			(61U)
#define DIO_PORT_PIN_62			(62U)
#define DIO_PORT_PIN_63			(63U)
#define DIO_PORT_PIN_64			(64U)
#define DIO_PORT_PIN_65			(65U)
#define DIO_PORT_PIN_66			(66U)
#define DIO_PORT_PIN_67			(67U)
#define DIO_PORT_PIN_68			(68U)
#define DIO_PORT_PIN_69			(69U)
#define DIO_PORT_PIN_70			(70U)
#define DIO_PORT_PIN_71			(71U)
#define DIO_PORT_PIN_72			(72U)
#define DIO_PORT_PIN_73			(73U)
#define DIO_PORT_PIN_74			(74U)
#define DIO_PORT_PIN_75			(75U)
#define DIO_PORT_PIN_76			(76U)
#define DIO_PORT_PIN_77			(77U)
#define DIO_PORT_PIN_78			(78U)
#define DIO_PORT_PIN_MAX	    (79U)

#define MAX_PORT				(0U)
#define MAX_PORT_PINS			(8U)

#define DIO_CHANNEL_MAX_GROUPS	(0U)

/* Symbolic names for DIO Channels, Port & Channel groups */

#define DIO_CHANNEL_0		DIO_PORT_PIN_0
#define DIO_CHANNEL_1		DIO_PORT_PIN_1
#define DIO_CHANNEL_2		DIO_PORT_PIN_2
#define DIO_CHANNEL_3		DIO_PORT_PIN_3
#define DIO_CHANNEL_4		DIO_PORT_PIN_4
#define DIO_CHANNEL_5		DIO_PORT_PIN_5
#define DIO_CHANNEL_6		DIO_PORT_PIN_6
#define DIO_CHANNEL_7		DIO_PORT_PIN_7
#define DIO_CHANNEL_8		DIO_PORT_PIN_8
#define DIO_CHANNEL_9		DIO_PORT_PIN_9
#define DIO_CHANNEL_10		DIO_PORT_PIN_10
#define DIO_CHANNEL_11		DIO_PORT_PIN_11
#define DIO_CHANNEL_12		DIO_PORT_PIN_12
#define DIO_CHANNEL_13		DIO_PORT_PIN_13
#define DIO_CHANNEL_14		DIO_PORT_PIN_14
#define DIO_CHANNEL_15		DIO_PORT_PIN_15
#define DIO_CHANNEL_16		DIO_PORT_PIN_16
#define DIO_CHANNEL_17		DIO_PORT_PIN_17
#define DIO_CHANNEL_18		DIO_PORT_PIN_18
#define DIO_CHANNEL_19		DIO_PORT_PIN_19
#define DIO_CHANNEL_20		DIO_PORT_PIN_20
#define DIO_CHANNEL_21		DIO_PORT_PIN_21
#define DIO_CHANNEL_22		DIO_PORT_PIN_22
#define DIO_CHANNEL_23		DIO_PORT_PIN_23
#define DIO_CHANNEL_24		DIO_PORT_PIN_24
#define DIO_CHANNEL_25		DIO_PORT_PIN_25
#define DIO_CHANNEL_26		DIO_PORT_PIN_26
#define DIO_CHANNEL_27		DIO_PORT_PIN_27
#define DIO_CHANNEL_28		DIO_PORT_PIN_28
#define DIO_CHANNEL_29		DIO_PORT_PIN_29
#define DIO_CHANNEL_30		DIO_PORT_PIN_30
#define DIO_CHANNEL_31		DIO_PORT_PIN_31
#define DIO_CHANNEL_32		DIO_PORT_PIN_32
#define DIO_CHANNEL_33		DIO_PORT_PIN_33
#define DIO_CHANNEL_34		DIO_PORT_PIN_34
#define DIO_CHANNEL_35		DIO_PORT_PIN_35
#define DIO_CHANNEL_36		DIO_PORT_PIN_36
#define DIO_CHANNEL_37		DIO_PORT_PIN_37
#define DIO_CHANNEL_38		DIO_PORT_PIN_38
#define DIO_CHANNEL_39		DIO_PORT_PIN_39
#define DIO_CHANNEL_40		DIO_PORT_PIN_40
#define DIO_CHANNEL_41		DIO_PORT_PIN_41
#define DIO_CHANNEL_42		DIO_PORT_PIN_42
#define DIO_CHANNEL_43		DIO_PORT_PIN_43
#define DIO_CHANNEL_44		DIO_PORT_PIN_44
#define DIO_CHANNEL_45		DIO_PORT_PIN_45
#define DIO_CHANNEL_46		DIO_PORT_PIN_46
#define DIO_CHANNEL_47		DIO_PORT_PIN_47
#define DIO_CHANNEL_48		DIO_PORT_PIN_48
#define DIO_CHANNEL_49		DIO_PORT_PIN_49
#define DIO_CHANNEL_50		DIO_PORT_PIN_50
#define DIO_CHANNEL_51		DIO_PORT_PIN_51
#define DIO_CHANNEL_52		DIO_PORT_PIN_52
#define DIO_CHANNEL_53		DIO_PORT_PIN_53
#define DIO_CHANNEL_54		DIO_PORT_PIN_54
#define DIO_CHANNEL_55		DIO_PORT_PIN_55
#define DIO_CHANNEL_56		DIO_PORT_PIN_56
#define DIO_CHANNEL_57		DIO_PORT_PIN_57
#define DIO_CHANNEL_58		DIO_PORT_PIN_58
#define DIO_CHANNEL_59		DIO_PORT_PIN_59
#define DIO_CHANNEL_60		DIO_PORT_PIN_60
#define DIO_CHANNEL_61		DIO_PORT_PIN_61
#define DIO_CHANNEL_62		DIO_PORT_PIN_62
#define DIO_CHANNEL_63		DIO_PORT_PIN_63
#define DIO_CHANNEL_64		DIO_PORT_PIN_64
#define DIO_CHANNEL_65		DIO_PORT_PIN_65
#define DIO_CHANNEL_66		DIO_PORT_PIN_66
#define DIO_CHANNEL_67		DIO_PORT_PIN_67
#define DIO_CHANNEL_68		DIO_PORT_PIN_68
#define DIO_CHANNEL_69		DIO_PORT_PIN_69
#define DIO_CHANNEL_70		DIO_PORT_PIN_70
#define DIO_CHANNEL_71		DIO_PORT_PIN_71
#define DIO_CHANNEL_72		DIO_PORT_PIN_72
#define DIO_CHANNEL_73		DIO_PORT_PIN_73
#define DIO_CHANNEL_74		DIO_PORT_PIN_74
#define DIO_CHANNEL_75		DIO_PORT_PIN_75
#define DIO_CHANNEL_76		DIO_PORT_PIN_76
#define DIO_CHANNEL_77		DIO_PORT_PIN_77
#define DIO_CHANNEL_78		DIO_PORT_PIN_78
#define DIO_CHANNEL_MAX		DIO_PORT_PIN_MAX		


#ifndef DioConf_DioChannel_DioChannel_0_GPIO_0
#define DioConf_DioChannel_DioChannel_0_GPIO_0 (DIO_CHANNEL_0)
#endif


#ifndef DioConf_DioChannel_DioChannel_1_GPIO_1
#define DioConf_DioChannel_DioChannel_1_GPIO_1 (DIO_CHANNEL_1)
#endif


#ifndef DioConf_DioChannel_DioChannel_2_GPIO_2
#define DioConf_DioChannel_DioChannel_2_GPIO_2 (DIO_CHANNEL_2)
#endif


#ifndef DioConf_DioChannel_DioChannel_3_GPIO_3
#define DioConf_DioChannel_DioChannel_3_GPIO_3 (DIO_CHANNEL_3)
#endif


#ifndef DioConf_DioChannel_DioChannel_4_GPIO_4
#define DioConf_DioChannel_DioChannel_4_GPIO_4 (DIO_CHANNEL_4)
#endif


#ifndef DioConf_DioChannel_DioChannel_5_GPIO_5
#define DioConf_DioChannel_DioChannel_5_GPIO_5 (DIO_CHANNEL_5)
#endif


#ifndef DioConf_DioChannel_DioChannel_6_GPIO_6
#define DioConf_DioChannel_DioChannel_6_GPIO_6 (DIO_CHANNEL_6)
#endif


#ifndef DioConf_DioChannel_DioChannel_7_GPIO_7
#define DioConf_DioChannel_DioChannel_7_GPIO_7 (DIO_CHANNEL_7)
#endif


#ifndef DioConf_DioChannel_DioChannel_8_GPIO_8
#define DioConf_DioChannel_DioChannel_8_GPIO_8 (DIO_CHANNEL_8)
#endif


#ifndef DioConf_DioChannel_DioChannel_9_GPIO_9
#define DioConf_DioChannel_DioChannel_9_GPIO_9 (DIO_CHANNEL_9)
#endif


#ifndef DioConf_DioChannel_DioChannel_10_GPIO_10
#define DioConf_DioChannel_DioChannel_10_GPIO_10 (DIO_CHANNEL_10)
#endif


#ifndef DioConf_DioChannel_DioChannel_11_GPIO_11
#define DioConf_DioChannel_DioChannel_11_GPIO_11 (DIO_CHANNEL_11)
#endif


#ifndef DioConf_DioChannel_DioChannel_12_GPIO_12
#define DioConf_DioChannel_DioChannel_12_GPIO_12 (DIO_CHANNEL_12)
#endif


#ifndef DioConf_DioChannel_DioChannel_13_GPIO_13
#define DioConf_DioChannel_DioChannel_13_GPIO_13 (DIO_CHANNEL_13)
#endif


#ifndef DioConf_DioChannel_DioChannel_14_GPIO_14
#define DioConf_DioChannel_DioChannel_14_GPIO_14 (DIO_CHANNEL_14)
#endif


#ifndef DioConf_DioChannel_DioChannel_15_GPIO_15
#define DioConf_DioChannel_DioChannel_15_GPIO_15 (DIO_CHANNEL_15)
#endif


#ifndef DioConf_DioChannel_DioChannel_16_GPIO_16
#define DioConf_DioChannel_DioChannel_16_GPIO_16 (DIO_CHANNEL_16)
#endif


#ifndef DioConf_DioChannel_DioChannel_17_GPIO_17
#define DioConf_DioChannel_DioChannel_17_GPIO_17 (DIO_CHANNEL_17)
#endif


#ifndef DioConf_DioChannel_DioChannel_18_GPIO_18
#define DioConf_DioChannel_DioChannel_18_GPIO_18 (DIO_CHANNEL_18)
#endif


#ifndef DioConf_DioChannel_DioChannel_19_GPIO_19
#define DioConf_DioChannel_DioChannel_19_GPIO_19 (DIO_CHANNEL_19)
#endif


#ifndef DioConf_DioChannel_DioChannel_20_GPIO_20
#define DioConf_DioChannel_DioChannel_20_GPIO_20 (DIO_CHANNEL_20)
#endif


#ifndef DioConf_DioChannel_DioChannel_21_GPIO_21
#define DioConf_DioChannel_DioChannel_21_GPIO_21 (DIO_CHANNEL_21)
#endif


#ifndef DioConf_DioChannel_DioChannel_22_GPIO_22
#define DioConf_DioChannel_DioChannel_22_GPIO_22 (DIO_CHANNEL_22)
#endif


#ifndef DioConf_DioChannel_DioChannel_23_GPIO_23
#define DioConf_DioChannel_DioChannel_23_GPIO_23 (DIO_CHANNEL_23)
#endif


#ifndef DioConf_DioChannel_DioChannel_24_GPIO_24
#define DioConf_DioChannel_DioChannel_24_GPIO_24 (DIO_CHANNEL_24)
#endif


#ifndef DioConf_DioChannel_DioChannel_25_GPIO_25
#define DioConf_DioChannel_DioChannel_25_GPIO_25 (DIO_CHANNEL_25)
#endif


#ifndef DioConf_DioChannel_DioChannel_26_GPIO_26
#define DioConf_DioChannel_DioChannel_26_GPIO_26 (DIO_CHANNEL_26)
#endif


#ifndef DioConf_DioChannel_DioChannel_27_GPIO_27
#define DioConf_DioChannel_DioChannel_27_GPIO_27 (DIO_CHANNEL_27)
#endif


#ifndef DioConf_DioChannel_DioChannel_28_GPIO_28
#define DioConf_DioChannel_DioChannel_28_GPIO_28 (DIO_CHANNEL_28)
#endif


#ifndef DioConf_DioChannel_DioChannel_29_GPIO_29
#define DioConf_DioChannel_DioChannel_29_GPIO_29 (DIO_CHANNEL_29)
#endif


#ifndef DioConf_DioChannel_DioChannel_30_GPIO_30
#define DioConf_DioChannel_DioChannel_30_GPIO_30 (DIO_CHANNEL_30)
#endif


#ifndef DioConf_DioChannel_DioChannel_31_GPIO_31
#define DioConf_DioChannel_DioChannel_31_GPIO_31 (DIO_CHANNEL_31)
#endif


#ifndef DioConf_DioChannel_DioChannel_32_GPIO_32
#define DioConf_DioChannel_DioChannel_32_GPIO_32 (DIO_CHANNEL_32)
#endif


#ifndef DioConf_DioChannel_DioChannel_33_GPIO_33
#define DioConf_DioChannel_DioChannel_33_GPIO_33 (DIO_CHANNEL_33)
#endif


#ifndef DioConf_DioChannel_DioChannel_34_GPIO_34
#define DioConf_DioChannel_DioChannel_34_GPIO_34 (DIO_CHANNEL_34)
#endif


#ifndef DioConf_DioChannel_DioChannel_35_GPIO_35
#define DioConf_DioChannel_DioChannel_35_GPIO_35 (DIO_CHANNEL_35)
#endif


#ifndef DioConf_DioChannel_DioChannel_36_GPIO_36
#define DioConf_DioChannel_DioChannel_36_GPIO_36 (DIO_CHANNEL_36)
#endif


#ifndef DioConf_DioChannel_DioChannel_37_GPIO_37
#define DioConf_DioChannel_DioChannel_37_GPIO_37 (DIO_CHANNEL_37)
#endif


#ifndef DioConf_DioChannel_DioChannel_38_GPIO_38
#define DioConf_DioChannel_DioChannel_38_GPIO_38 (DIO_CHANNEL_38)
#endif


#ifndef DioConf_DioChannel_DioChannel_39_GPIO_39
#define DioConf_DioChannel_DioChannel_39_GPIO_39 (DIO_CHANNEL_39)
#endif


#ifndef DioConf_DioChannel_DioChannel_40_GPIO_40
#define DioConf_DioChannel_DioChannel_40_GPIO_40 (DIO_CHANNEL_40)
#endif


#ifndef DioConf_DioChannel_DioChannel_41_GPIO_41
#define DioConf_DioChannel_DioChannel_41_GPIO_41 (DIO_CHANNEL_41)
#endif


#ifndef DioConf_DioChannel_DioChannel_42_GPIO_42
#define DioConf_DioChannel_DioChannel_42_GPIO_42 (DIO_CHANNEL_42)
#endif


#ifndef DioConf_DioChannel_DioChannel_43_GPIO_43
#define DioConf_DioChannel_DioChannel_43_GPIO_43 (DIO_CHANNEL_43)
#endif


#ifndef DioConf_DioChannel_DioChannel_44_GPIO_44
#define DioConf_DioChannel_DioChannel_44_GPIO_44 (DIO_CHANNEL_44)
#endif


#ifndef DioConf_DioChannel_DioChannel_45_GPIO_45
#define DioConf_DioChannel_DioChannel_45_GPIO_45 (DIO_CHANNEL_45)
#endif


#ifndef DioConf_DioChannel_DioChannel_46_GPIO_46
#define DioConf_DioChannel_DioChannel_46_GPIO_46 (DIO_CHANNEL_46)
#endif


#ifndef DioConf_DioChannel_DioChannel_47_GPIO_47
#define DioConf_DioChannel_DioChannel_47_GPIO_47 (DIO_CHANNEL_47)
#endif


#ifndef DioConf_DioChannel_DioChannel_48_GPIO_48
#define DioConf_DioChannel_DioChannel_48_GPIO_48 (DIO_CHANNEL_48)
#endif


#ifndef DioConf_DioChannel_DioChannel_49_GPIO_49
#define DioConf_DioChannel_DioChannel_49_GPIO_49 (DIO_CHANNEL_49)
#endif


#ifndef DioConf_DioChannel_DioChannel_50_GPIO_50
#define DioConf_DioChannel_DioChannel_50_GPIO_50 (DIO_CHANNEL_50)
#endif


#ifndef DioConf_DioChannel_DioChannel_51_GPIO_51
#define DioConf_DioChannel_DioChannel_51_GPIO_51 (DIO_CHANNEL_51)
#endif


#ifndef DioConf_DioChannel_DioChannel_52_GPIO_52
#define DioConf_DioChannel_DioChannel_52_GPIO_52 (DIO_CHANNEL_52)
#endif


#ifndef DioConf_DioChannel_DioChannel_53_GPIO_53
#define DioConf_DioChannel_DioChannel_53_GPIO_53 (DIO_CHANNEL_53)
#endif


#ifndef DioConf_DioChannel_DioChannel_54_GPIO_54
#define DioConf_DioChannel_DioChannel_54_GPIO_54 (DIO_CHANNEL_54)
#endif


#ifndef DioConf_DioChannel_DioChannel_55_GPIO_55
#define DioConf_DioChannel_DioChannel_55_GPIO_55 (DIO_CHANNEL_55)
#endif


#ifndef DioConf_DioChannel_DioChannel_56_GPIO_56
#define DioConf_DioChannel_DioChannel_56_GPIO_56 (DIO_CHANNEL_56)
#endif


#ifndef DioConf_DioChannel_DioChannel_57_GPIO_57
#define DioConf_DioChannel_DioChannel_57_GPIO_57 (DIO_CHANNEL_57)
#endif


#ifndef DioConf_DioChannel_DioChannel_58_GPIO_58
#define DioConf_DioChannel_DioChannel_58_GPIO_58 (DIO_CHANNEL_58)
#endif


#ifndef DioConf_DioChannel_DioChannel_59_GPIO_59
#define DioConf_DioChannel_DioChannel_59_GPIO_59 (DIO_CHANNEL_59)
#endif


#ifndef DioConf_DioChannel_DioChannel_60_GPIO_60
#define DioConf_DioChannel_DioChannel_60_GPIO_60 (DIO_CHANNEL_60)
#endif


#ifndef DioConf_DioChannel_DioChannel_61_GPIO_61
#define DioConf_DioChannel_DioChannel_61_GPIO_61 (DIO_CHANNEL_61)
#endif


#ifndef DioConf_DioChannel_DioChannel_62_GPIO_62
#define DioConf_DioChannel_DioChannel_62_GPIO_62 (DIO_CHANNEL_62)
#endif


#ifndef DioConf_DioChannel_DioChannel_63_GPIO_63
#define DioConf_DioChannel_DioChannel_63_GPIO_63 (DIO_CHANNEL_63)
#endif


#ifndef DioConf_DioChannel_DioChannel_64_GPIO_64
#define DioConf_DioChannel_DioChannel_64_GPIO_64 (DIO_CHANNEL_64)
#endif


#ifndef DioConf_DioChannel_DioChannel_65_GPIO_65
#define DioConf_DioChannel_DioChannel_65_GPIO_65 (DIO_CHANNEL_65)
#endif


#ifndef DioConf_DioChannel_DioChannel_66_GPIO_66
#define DioConf_DioChannel_DioChannel_66_GPIO_66 (DIO_CHANNEL_66)
#endif


#ifndef DioConf_DioChannel_DioChannel_67_GPIO_67
#define DioConf_DioChannel_DioChannel_67_GPIO_67 (DIO_CHANNEL_67)
#endif


#ifndef DioConf_DioChannel_DioChannel_68_GPIO_68
#define DioConf_DioChannel_DioChannel_68_GPIO_68 (DIO_CHANNEL_68)
#endif


#ifndef DioConf_DioChannel_DioChannel_69_GPIO_69
#define DioConf_DioChannel_DioChannel_69_GPIO_69 (DIO_CHANNEL_69)
#endif


#ifndef DioConf_DioChannel_DioChannel_70_GPIO_70
#define DioConf_DioChannel_DioChannel_70_GPIO_70 (DIO_CHANNEL_70)
#endif


#ifndef DioConf_DioChannel_DioChannel_71_GPIO_71
#define DioConf_DioChannel_DioChannel_71_GPIO_71 (DIO_CHANNEL_71)
#endif


#ifndef DioConf_DioChannel_DioChannel_72_GPIO_72
#define DioConf_DioChannel_DioChannel_72_GPIO_72 (DIO_CHANNEL_72)
#endif


#ifndef DioConf_DioChannel_DioChannel_73_GPIO_73
#define DioConf_DioChannel_DioChannel_73_GPIO_73 (DIO_CHANNEL_73)
#endif


#ifndef DioConf_DioChannel_DioChannel_74_GPIO_74
#define DioConf_DioChannel_DioChannel_74_GPIO_74 (DIO_CHANNEL_74)
#endif


#ifndef DioConf_DioChannel_DioChannel_75_GPIO_75
#define DioConf_DioChannel_DioChannel_75_GPIO_75 (DIO_CHANNEL_75)
#endif


#ifndef DioConf_DioChannel_DioChannel_76_GPIO_76
#define DioConf_DioChannel_DioChannel_76_GPIO_76 (DIO_CHANNEL_76)
#endif


#ifndef DioConf_DioChannel_DioChannel_77_GPIO_77
#define DioConf_DioChannel_DioChannel_77_GPIO_77 (DIO_CHANNEL_77)
#endif


#ifndef DioConf_DioChannel_DioChannel_78_GPIO_78
#define DioConf_DioChannel_DioChannel_78_GPIO_78 (DIO_CHANNEL_78)
#endif

#endif /* DIO_CFG_H */
/*==============================================================================
**                      			END	                               		  **
==============================================================================*/