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
    File Name          : can_tests.h
    Component Name     : CAN Driver
    Description        : All CAN test code.
    $Header: $
    $DateTime:  $
    $Author:  $
=========================================================================================================*/

/* Include header file guard */
#ifndef CAN_TESTS_H_
#define CAN_TESTS_H_
#include "tests.h"

/****************************************************STD ID RANGE FILTERS*********************************************/
#define STD_ID_FILT_RANGE_FF0 	{                                                                     				  \
	.SFID2=0x150,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x100,    /*Standard Filter ID 1                                                                        */ \
	.SFEC= 1,        /* Store into Rx FF0 														                   */ \
	.SFT=0           /*Range filter from SFID1 to SFID2 (SFID2 = SFID1)                                            */ \
	}
#define STD_ID_FILT_RANGE_FF1   {                                                                     				  \
	.SFID2=0x200,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x151,    /*Standard Filter ID 1                                                                        */ \
	.SFEC= 2,        /* Store into Rx FF1 														                   */ \
	.SFT=0           /*Range filter from SFID1 to SFID2 (SFID2 = SFID1)                                            */ \
	}

#define STD_ID_FILT_RANGE_REJECT {                                                                     				  \
	.SFID2=0x99,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x50,     /*Standard Filter ID 1                                                                        */ \
	.SFEC= 3,        /*Reject 														                   			   */ \
	.SFT=0           /*Range filter from SFID1 to SFID2 (SFID2 = SFID1)                                            */ \
	}
#define STD_ID_FILT_RANGE_SET_PRIORITY {                                                              				  \
	.SFID2=0x49,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x45,     /*Standard Filter ID 1                                                                        */ \
	.SFEC= 4,        /*Set Priority 														           			   */ \
	.SFT=0           /*Range filter from SFID1 to SFID2 (SFID2 = SFID1)                                            */ \
    }
#define STD_ID_FILT_RANGE_SET_PRIORITY_FF0 {                                                            			  \
	.SFID2=0x44,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x40,     /*Standard Filter ID 1                                                                        */ \
	.SFEC= 5,        /*Set Priority & Store In FF0 													   			   */ \
	.SFT=0           /*Range filter from SFID1 to SFID2 (SFID2 = SFID1)                                            */ \
    }
#define STD_ID_FILT_RANGE_SET_PRIORITY_FF1 {                                                            			  \
	.SFID2=0x39,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x30,     /*Standard Filter ID 1                                                                        */ \
	.SFEC= 6,        /*Set Priority & Store In FF1 														 		   */ \
	.SFT=0           /*Range filter from SFID1 to SFID2 (SFID2 = SFID1)                                            */ \
    }

/****************************************************STD ID DUAL FILTERS**********************************************/
#define STD_ID_FILT_DUAL_FF0 	{                                                                     				  \
	.SFID2=0x150,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x100,    /*Standard Filter ID 1                                                                        */ \
	.SFEC= 1,        /* Store into Rx FF0 														                   */ \
	.SFT=1           /*Dual ID Filter								                                               */ \
	}
#define STD_ID_FILT_DUAL_FF1   {                                                                     				  \
	.SFID2=0x200,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x151,    /*Standard Filter ID 1                                                                        */ \
	.SFEC= 2,        /* Store into Rx FF1 														                   */ \
	.SFT=1           /*Dual ID Filter                                                                              */ \
	}

#define STD_ID_FILT_DUAL_REJECT {                                                                     				  \
	.SFID2=0x99,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x50,     /*Standard Filter ID 1                                                                        */ \
	.SFEC= 3,        /*Reject 														                   			   */ \
	.SFT=1           /*Dual ID Filter                                                                              */ \
	}
#define STD_ID_FILT_DUAL_SET_PRIORITY {                                                              				  \
	.SFID2=0x49,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x45,     /*Standard Filter ID 1                                                                        */ \
	.SFEC= 4,        /*Set Priority 														           			   */ \
	.SFT=1           /*Dual ID Filter                                                                              */ \
    }
#define STD_ID_FILT_DUAL_SET_PRIORITY_FF0 {                                                            				  \
	.SFID2=0x44,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x40,     /*Standard Filter ID 1                                                                        */ \
	.SFEC= 5,        /*Set Priority & Store In FF0 													   			   */ \
	.SFT=1           /*Dual ID Filter                                                                              */ \
    }
#define STD_ID_FILT_DUAL_SET_PRIORITY_FF1 {                                                            				  \
	.SFID2=0x39,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x30,     /*Standard Filter ID 1                                                                        */ \
	.SFEC= 6,        /*Set Priority & Store In FF1 														 		   */ \
	.SFT=1           /*Dual ID Filter                                                                              */ \
    }

/****************************************************STD ID CLASSIC FILTERS*********************************************/

#define STD_ID_FILT_CLASSIC_FF0 {                                                                     				  \
	.SFID2=0x150,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x100,    /*Standard Filter ID 1                                                                        */ \
	.SFEC= 1,        /* Store into Rx FF0 														                   */ \
	.SFT=2           /*Classic Filter                                          									   */ \
	}
#define STD_ID_FILT_CLASSIC_FF1  {                                                                     				  \
	.SFID2=0x200,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x151,    /*Standard Filter ID 1                                                                        */ \
	.SFEC= 2,        /*Store into Rx FF1 														                   */ \
	.SFT=2           /*Classic Filter                                                                              */ \
	}

#define STD_ID_FILT_CLASSIC_REJECT {                                                                   				  \
	.SFID2=0x99,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x50,     /*Standard Filter ID 1                                                                        */ \
	.SFEC= 3,        /*Reject 														                   			   */ \
	.SFT=2           /*Classic Filter                                                                              */ \
	}
#define STD_ID_FILT_CLASSIC_SET_PRIORITY {                                                            				  \
	.SFID2=0x49,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x45,     /*Standard Filter ID 1                                                                        */ \
	.SFEC= 4,        /*Set Priority 														           			   */ \
	.SFT=2           /*Classic Filter                                                                              */ \
    }
#define STD_ID_FILT_CLASSIC_SET_PRIORITY_FF0 {                                                         				  \
	.SFID2=0x44,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x40,     /*Standard Filter ID 1                                                                        */ \
	.SFEC= 5,        /*Set Priority & Store In FF0 													   			   */ \
	.SFT=2           /*Classic Filter                                                                              */ \
    }
#define STD_ID_FILT_CLASSIC_SET_PRIORITY_FF1 {                                                         				  \
	.SFID2=0x39,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x30,     /*Standard Filter ID 1                                                                        */ \
	.SFEC= 6,        /*Set Priority & Store In FF1 														 		   */ \
	.SFT=2           /*Classic Filter                                                                              */ \
    }

 /****************************************************STD ID FILTERS SFT IGNORED***************************************/

#define STD_ID_STORE_TO_RX_BUFF_TRG_FE0 {                                                                     		  \
	.SFID2=0x40,     /* Store in Rx Buffer 0 and Set FE0 Event  		                  				           */ \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x100,    /*Standard Filter ID 1                                                                        */ \
	.SFEC= 7,        /* Store into Rx FF0 														                   */ \
	.SFT=2           /*Don't Care Since SFEC = 7                                         						   */ \
	}
#define STD_ID_STORE_TO_RX_BUFF_TRG_FE1  {                                                                  		  \
	.SFID2=0x81,     /* Store in Rx Buffer 1 and Set FE1 Event													   */ \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x151,    /*Standard Filter ID 1                                                                        */ \
	.SFEC= 7,        /*Store into Rx FF1 														                   */ \
	.SFT=2           /*Don't Care Since SFEC = 7                                                                   */ \
	}

#define STD_ID_STORE_TO_RX_BUFF_TRG_FE2 {                                                              				  \
	.SFID2=0x102,    /* Store in Rx Buffer 2 and Set FE2 Event 													   */ \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x50,     /*Standard Filter ID 1                                                                        */ \
	.SFEC= 7,        /*Reject 														                   			   */ \
	.SFT=2           /*Don't Care Since SFEC = 7                                                                   */ \
	}
#define STD_ID_DEBUG_MSG_A {                                                            				              \
	.SFID2=0x200,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x45,     /*Standard Filter ID 1                                                                        */ \
	.SFEC= 7,        /*Set Priority 														           			   */ \
	.SFT=2           /*Don't Care Since SFEC = 7                                                                   */ \
    }
#define STD_ID_DEBUG_MSG_B {                                                         				                  \
	.SFID2=0x400,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x40,     /*Standard Filter ID 1                                                                        */ \
	.SFEC= 7,        /*Set Priority & Store In FF0 													   			   */ \
	.SFT=2           /*Don't Care Since SFEC = 7                                                                   */ \
    }
#define STD_ID_DEBUG_MSG_C {                                                         				                  \
	.SFID2=0x600,    															                    				  \
	.RES =0,         /*                                                                                            */ \
	.SSYNC=0,        /*Only evaluated when CCCR.UTSU = ?1?.                                                        */ \
	.SFID1=0x30,     /*Standard Filter ID 1                                                                        */ \
	.SFEC= 7,        /*Set Priority & Store In FF1 														 		   */ \
	.SFT=2           /*Don't Care Since SFEC = 7                                                                   */ \
    }

/****************************************************XTD ID RANGE FILTERS*********************************************/
#define XTD_ID_FILT_RANGE_FF0 {                                                                                     \
	.EFID1=0x1F000000,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=1,              /*  Store in Rx FIFO 0 if filter matches                                               */ \
	.EFID2=0x1F000100,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=0                /*  Range filter from EFID1 to EFID2 (EFID2 = EFID1)                                   */ \
	}
#define XTD_ID_FILT_RANGE_FF1 {                                                                                     \
	.EFID1=0x1F000101,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=2,              /*  Store in Rx FIFO 1 if filter matches                                               */ \
	.EFID2=0x1F000200,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=0                /*  Range filter from EFID1 to EFID2 (EFID2 = EFID1)                                   */ \
	}
#define XTD_ID_FILT_RANGE_REJECT {                                                                                  \
	.EFID1=0x1F000201,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=3,              /*  Reject this Range                                                                  */ \
	.EFID2=0x1F000300,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=0                /*  Range filter from EFID1 to EFID2 (EFID2 = EFID1)                                   */ \
	}
#define XTD_ID_FILT_RANGE_SET_PRIORITY {                                                                            \
	.EFID1=0x1F000301,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=4,              /*  Set Priority No Storage                                                            */ \
	.EFID2=0x1F000400,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=0                /*  Range filter from EFID1 to EFID2 (EFID2 = EFID1)                                   */ \
	}
#define XTD_ID_FILT_RANGE_SET_PRIORITY_FF0 {                                                                        \
	.EFID1=0x1F000401,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=5,              /*  Set Priority Store To FF0                                                          */ \
	.EFID2=0x1F000500,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=0                /*  Range filter from EFID1 to EFID2 (EFID2 = EFID1)                                   */ \
	}
#define XTD_ID_FILT_RANGE_SET_PRIORITY_FF1 {                                                                        \
	.EFID1=0x1F000201,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=6,              /*  Set Priority Store To FF1                                                          */ \
	.EFID2=0x1F000300,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=0                /*  Range filter from EFID1 to EFID2 (EFID2 = EFID1)                                   */ \
	}

/****************************************************XTD ID DUAL FILTERS*********************************************/
#define XTD_ID_FILT_DUAL_FF0 {                                                                                      \
	.EFID1=0x1F000000,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=1,              /*  Store in Rx FIFO 0 if filter matches                                               */ \
	.EFID2=0x1F000100,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=1                /*  Dual filter EFID1 OR EFID2                                                         */ \
	}
#define XTD_ID_FILT_DUAL_FF1 {                                                                                      \
	.EFID1=0x1F000101,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=2,              /*  Store in Rx FIFO 1 if filter matches                                               */ \
	.EFID2=0x1F000200,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=1                /*  Dual filter EFID1 OR EFID2                                 					     */ \
	}
#define XTD_ID_FILT_DUAL_REJECT {                                                                                   \
	.EFID1=0x1F000201,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=3,              /*  Reject this Range                                                                  */ \
	.EFID2=0x1F000300,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=1                /*  Dual filter EFID1 OR EFID2                                					     */ \
	}
#define XTD_ID_FILT_DUAL_SET_PRIORITY {                                                                             \
	.EFID1=0x1F000301,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=4,              /*  Set Priority No Storage                                                            */ \
	.EFID2=0x1F000400,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=1                /*  Dual filter EFID1 OR EFID2                               						     */ \
	}
#define XTD_ID_FILT_DUAL_SET_PRIORITY_FF0 {                                                                         \
	.EFID1=0x1F000401,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=5,              /*  Set Priority Store To FF0                                                          */ \
	.EFID2=0x1F000500,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=1                /*  Dual filter EFID1 OR EFID2                            					         */ \
	}
#define XTD_ID_FILT_DUAL_SET_PRIORITY_FF1 {                                                                         \
	.EFID1=0x1F000201,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=6,              /*  Set Priority Store To FF1                                                          */ \
	.EFID2=0x1F000300,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=1                /*  Dual filter EFID1 OR EFID2                                    					 */ \
	}

/****************************************************XTD ID CLASSIC FILTERS******************************************/
#define XTD_ID_FILT_CLASSIC_FF0 {                                                                                      \
	.EFID1=0x1F000000,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=1,              /*  Store in Rx FIFO 0 if filter matches                                               */ \
	.EFID2=0x1F000100,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=2                /*  Classical filter EFID1 -> Filter  EFID2 -> Mask XIDAM Applied                      */ \
	}
#define XTD_ID_FILT_CLASSIC_FF1 {                                                                                   \
	.EFID1=0x1F000101,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=2,              /*  Store in Rx FIFO 1 if filter matches                                               */ \
	.EFID2=0x1F000200,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=2                /*  Classical filter EFID1 -> Filter  EFID2 -> Mask XIDAM Applied                      */ \
	}
#define XTD_ID_FILT_CLASSIC_REJECT {                                                                                \
	.EFID1=0x1F000201,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=3,              /*  Reject this Range                                                                  */ \
	.EFID2=0x1F000300,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=2                /*  Classical filter EFID1 -> Filter  EFID2 -> Mask XIDAM Applied                      */ \
	}
#define XTD_ID_FILT_CLASSIC_SET_PRIORITY {                                                                          \
	.EFID1=0x1F000301,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=4,              /*  Set Priority No Storage                                                            */ \
	.EFID2=0x1F000400,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=2                /*  Classical filter EFID1 -> Filter  EFID2 -> Mask XIDAM Applied                      */ \
	}
#define XTD_ID_FILT_CLASSIC_SET_PRIORITY_FF0 {                                                                      \
	.EFID1=0x1F000401,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=5,              /*  Set Priority Store To FF0                                                          */ \
	.EFID2=0x1F000500,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=2                /*  Classical filter EFID1 -> Filter  EFID2 -> Mask XIDAM Applied                      */ \
	}
#define XTD_ID_FILT_CLASSIC_SET_PRIORITY_FF1 {                                                                      \
	.EFID1=0x1F000201,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=6,              /*  Set Priority Store To FF1                                                          */ \
	.EFID2=0x1F000300,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=2                /*  Classical filter EFID1 -> Filter  EFID2 -> Mask XIDAM Applied                      */ \
	}


/****************************************************XTD ID RANGE FILTERS WITHOUT XIDAM*****************************/
#define XTD_ID_FILT_RANGE_FF0_NO_XIDAM {                                                                            \
	.EFID1=0x1F000000,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=1,              /*  Store in Rx FIFO 0 if filter matches                                               */ \
	.EFID2=0x1F000100,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=3                /*  Range filter from EFID1 to EFID2 (EFID2 = EFID1)                                   */ \
	}
#define XTD_ID_FILT_RANGE_FF1_NO_XIDAM {                                                                            \
	.EFID1=0x1F000101,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=2,              /*  Store in Rx FIFO 1 if filter matches                                               */ \
	.EFID2=0x1F000200,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=0                /*  Range filter from EFID1 to EFID2 (EFID2 = EFID1)                                   */ \
	}
#define XTD_ID_FILT_RANGE_REJECT_NO_XIDAM {                                                                         \
	.EFID1=0x1F000201,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=3,              /*  Reject this Range                                                                  */ \
	.EFID2=0x1F000300,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=3                /*  Range filter from EFID1 to EFID2 (EFID2 = EFID1)                                   */ \
	}
#define XTD_ID_FILT_RANGE_SET_PRIORITY_NO_XIDAM {                                                                   \
	.EFID1=0x1F000301,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=4,              /*  Set Priority No Storage                                                            */ \
	.EFID2=0x1F000400,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=3                /*  Range filter from EFID1 to EFID2 (EFID2 = EFID1)                                   */ \
	}
#define XTD_ID_FILT_RANGE_SET_PRIORITY_FF0_NO_XIDAM {                                                               \
	.EFID1=0x1F000401,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=5,              /*  Set Priority Store To FF0                                                          */ \
	.EFID2=0x1F000500,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=3                /*  Range filter from EFID1 to EFID2 (EFID2 = EFID1)                                   */ \
	}
#define XTD_ID_FILT_RANGE_SET_PRIORITY_FF1_NO_XIDAM {                                                               \
	.EFID1=0x1F000201,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=6,              /*  Set Priority Store To FF1                                                          */ \
	.EFID2=0x1F000300,    /*  Extended Filter ID 2												                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=3                /*  Range filter from EFID1 to EFID2 (EFID2 = EFID1)                                   */ \
	}

/****************************************************XTD ID FILTERS SFT IGNORED*************************************/
#define XTD_ID_STORE_TO_RX_BUFF_TRG_FE0 {                                                                           \
	.EFID1=0x1F000000,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=7,              /*  Store In Rx Buffer Or As Debug Message                                             */ \
	.EFID2=0x40,          /*  Store To Rx Buffer and set FE0									                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=3                /*  Ignored                                   										 */ \
	}
#define XTD_ID_STORE_TO_RX_BUFF_TRG_FE1 {                                                                           \
	.EFID1=0x1F000101,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=7,              /*  Store In Rx Buffer Or As Debug Message                                             */ \
	.EFID2=0x81,    	  /*  Store To Rx Buffer and set FE1									                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
    .EFT=3                /*  Ignored                                   										 */ \
	}
#define XTD_ID_STORE_TO_RX_BUFF_TRG_FE2 {                                                                           \
	.EFID1=0x1F000201,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=7,              /*  Store In Rx Buffer Or As Debug Message                                             */ \
	.EFID2=0x102,    	  /*  Store To Rx Buffer and set FE2									                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
    .EFT=3                /*  Ignored                                   										 */ \
	}
#define XTD_ID_DEBUG_MSG_A {                                                                                        \
	.EFID1=0x1F000301,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=7,              /*  Store In Rx Buffer Or As Debug Message                                             */ \
	.EFID2=0x200,    	  /*  Treat As Debug Message A											                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
    .EFT=3                /*  Ignored                                   										 */ \
	}
#define XTD_ID_DEBUG_MSG_B {                                                              						    \
	.EFID1=0x1F000401,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=7,              /*  Store In Rx Buffer Or As Debug Message                                             */ \
	.EFID2=0x400,    	  /*  Treat As Debug Message B											                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
	.EFT=3                /*  Ignored                                   										 */ \
	}
#define XTD_ID_DEBUG_MSG_C {                                                               							\
	.EFID1=0x1F000201,    /*  Extended Filter ID 1                                                               */ \
	.EFEC=7,              /*  Store In Rx Buffer Or As Debug Message                                             */ \
	.EFID2=0x600,    	  /*  Treat As Debug Message C											                 */ \
	.ESYNC=0,             /*  Only evaluated when CCCR.UTSU = ?1?                                                */ \
    .EFT=3                /*  Ignored                                   										 */ \
	}


#define CAN_STD_RANGE_FILTER_TEST               \
    STD_ID_FILT_RANGE_FF0,			            \
    STD_ID_FILT_RANGE_FF1,                      \
    STD_ID_FILT_RANGE_REJECT,                   \
    STD_ID_FILT_RANGE_SET_PRIORITY,             \
    STD_ID_FILT_RANGE_SET_PRIORITY_FF0,         \
    STD_ID_FILT_RANGE_SET_PRIORITY_FF1

#define CAN_STD_DUAL_FILTER_TEST                \
    STD_ID_FILT_DUAL_FF0,                       \
    STD_ID_FILT_DUAL_FF1,                       \
    STD_ID_FILT_DUAL_REJECT,                    \
    STD_ID_FILT_DUAL_SET_PRIORITY,              \
    STD_ID_FILT_DUAL_SET_PRIORITY_FF0,          \
    STD_ID_FILT_DUAL_SET_PRIORITY_FF1,          \

#define CAN_STD_CLASSIC_FILTER_TEST             \
    STD_ID_FILT_CLASSIC_FF0,                    \
    STD_ID_FILT_CLASSIC_FF1,                    \
    STD_ID_FILT_CLASSIC_REJECT,                 \
    STD_ID_FILT_CLASSIC_SET_PRIORITY,           \
    STD_ID_FILT_CLASSIC_SET_PRIORITY_FF0,       \
    STD_ID_FILT_CLASSIC_SET_PRIORITY_FF1

#define CAN_STD_RX_BUFF_DEBUG_FILTER_TEST       \
    STD_ID_STORE_TO_RX_BUFF_TRG_FE0,            \
    STD_ID_STORE_TO_RX_BUFF_TRG_FE1,            \
    STD_ID_STORE_TO_RX_BUFF_TRG_FE2,            \
    STD_ID_DEBUG_MSG_A,                         \
    STD_ID_DEBUG_MSG_B,                         \
    STD_ID_DEBUG_MSG_C

#define CAN_XTD_RANGE_FILTER_TEST               \
    XTD_ID_FILT_RANGE_FF0,                      \
    XTD_ID_FILT_RANGE_FF1,                      \
    XTD_ID_FILT_RANGE_REJECT,                   \
    XTD_ID_FILT_RANGE_SET_PRIORITY,             \
    XTD_ID_FILT_RANGE_SET_PRIORITY_FF0,         \
    XTD_ID_FILT_RANGE_SET_PRIORITY_FF1

#define CAN_XTD_DUAL_FILTER_TEST                \
    XTD_ID_FILT_DUAL_FF0,                       \
    XTD_ID_FILT_DUAL_FF1,                       \
    XTD_ID_FILT_DUAL_REJECT,                    \
    XTD_ID_FILT_DUAL_SET_PRIORITY,              \
    XTD_ID_FILT_DUAL_SET_PRIORITY_FF0,          \
    XTD_ID_FILT_DUAL_SET_PRIORITY_FF1

#define CAN_XTD_CLASSIC_FILTER_TEST             \
   XTD_ID_FILT_CLASSIC_FF0,                     \
   XTD_ID_FILT_CLASSIC_FF1,                     \
   XTD_ID_FILT_CLASSIC_REJECT,                  \
   XTD_ID_FILT_CLASSIC_SET_PRIORITY,            \
   XTD_ID_FILT_CLASSIC_SET_PRIORITY_FF0,        \
   XTD_ID_FILT_CLASSIC_SET_PRIORITY_FF1

#define CAN_XTD_RANGE_NO_XIDAM_FILTER_TEST      \
   XTD_ID_FILT_RANGE_FF0_NO_XIDAM,              \
   XTD_ID_FILT_RANGE_FF1_NO_XIDAM,              \
   XTD_ID_FILT_RANGE_REJECT_NO_XIDAM,           \
   XTD_ID_FILT_RANGE_SET_PRIORITY_NO_XIDAM,     \
   XTD_ID_FILT_RANGE_SET_PRIORITY_FF0_NO_XIDAM

#define CAN_XTD_RX_BUFF_DEBUG_FILTER_TEST       \
   XTD_ID_STORE_TO_RX_BUFF_TRG_FE0,             \
   XTD_ID_STORE_TO_RX_BUFF_TRG_FE1,             \
   XTD_ID_STORE_TO_RX_BUFF_TRG_FE2,             \
   XTD_ID_DEBUG_MSG_A,                          \
   XTD_ID_DEBUG_MSG_B,                          \
   XTD_ID_DEBUG_MSG_C




#if CAN_FILTER_TEST_1
  #define TEST_CAN_STD_FILTER_LIST_CFG  CAN_STD_RANGE_FILTER_TEST
  #define TEST_CAN_XTD_FILTER_LIST_CFG  CAN_XTD_RANGE_FILTER_TEST
#elif CAN_FILTER_TEST_2
  #define TEST_CAN_STD_FILTER_LIST_CFG  CAN_STD_DUAL_FILTER_TEST
  #define TEST_CAN_XTD_FILTER_LIST_CFG  CAN_XTD_DUAL_FILTER_TEST
#elif CAN_FILTER_TEST_3
  #define TEST_CAN_STD_FILTER_LIST_CFG  CAN_STD_CLASSIC_FILTER_TEST
  #define TEST_CAN_XTD_FILTER_LIST_CFG  CAN_XTD_CLASSIC_FILTER_TEST
#elif CAN_FILTER_TEST_4
  #define TEST_CAN_STD_FILTER_LIST_CFG  CAN_STD_RX_BUFF_DEBUG_FILTER_TEST
  #define TEST_CAN_XTD_FILTER_LIST_CFG  CAN_XTD_RX_BUFF_DEBUG_FILTER_TEST
#elif CAN_FILTER_TEST_5
  #define TEST_CAN_STD_FILTER_LIST_CFG  CAN_STD_RANGE_FILTER_TEST
  #define TEST_CAN_XTD_FILTER_LIST_CFG  CAN_XTD_RANGE_NO_XIDAM_FILTER_TEST
#endif


volatile extern uint8_t  Can_Bus_off_REC_Mon[CAN_MTTCAN_MAX_CNT] ;
volatile extern Can_MTTCAN_MRAM_TxBufferElement_Type TX_SRAM_Data_Buffer[];
volatile extern Can_MTTCAN_MRAM_TxBufferElement_Type TX_SRAM_Dedicated_Data_Buffer[];
volatile extern uint32_t STD_ID_FILTER_Start_Address[CAN_MTTCAN_MAX_CNT] ;
volatile extern uint32_t XTD_ID_FILTER_Start_Address[CAN_MTTCAN_MAX_CNT] ;
volatile extern uint32_t RX_FIFO_0_Start_Address[CAN_MTTCAN_MAX_CNT] ;
volatile extern uint32_t RX_FIFO_1_Start_Address[CAN_MTTCAN_MAX_CNT] ;
volatile extern uint32_t RX_DEDICATED_BUFF_Start_Address[CAN_MTTCAN_MAX_CNT] ;
volatile extern uint32_t TX_EVENT_FIFO_Start_Address[CAN_MTTCAN_MAX_CNT] ;
volatile extern uint32_t TX_BUFF_Start_Address[CAN_MTTCAN_MAX_CNT] ;
volatile extern uint32_t MRAM_Last_Address[CAN_MTTCAN_MAX_CNT] ;
volatile extern uint32_t * CAN_Controller_Memory_Data_Ptr[];

TEST_FUNC void can_tx_test(void);
TEST_FUNC void Tx_Queue_Test(CAN_Instance_ID Controller_ID);

#endif /* BSP_CAN_PUBLIC_CAN_TESTS_H_ */
