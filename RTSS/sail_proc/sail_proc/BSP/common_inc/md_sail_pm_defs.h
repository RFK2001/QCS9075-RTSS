/*=======================================================================
Copyright (c) 2022-2025 QUALCOMM Technologies, Inc. (QTI). All Rights Reserved.
========================================================================*/
#ifndef MD_SAIL_PM_DEFS_H 
#define MD_SAIL_PM_DEFS_H 

#include <inttypes.h>

#define MSG_TYPE_MD_2_SAIL_LOOPBACK_REQUEST           (0xaaccu)          
#define MSG_TYPE_SAIL_2_MD_LOOPBACK_RESPONSE          (MSG_TYPE_MD_2_SAIL_LOOPBACK_REQUEST + 1u) 

#define MSG_TYPE_MD_2_SAIL_PREPARE_FOR_SLEEP_REQUEST  (0xbbddu)
#define MSG_TYPE_SAIL_2_MD_PREPARE_FOR_SLEEP_RESPONSE (MSG_TYPE_MD_2_SAIL_PREPARE_FOR_SLEEP_REQUEST + 1u )

#define MSG_TYPE_SAIL_2_MD_BANDWIDTH_VOTE_REQUEST     (0xcceeu)
#define MSG_TYPE_MD_2_SAIL_BANDWIDTH_VOTE_RESPONSE    (MSG_TYPE_SAIL_2_MD_BANDWIDTH_VOTE_REQUEST + 1u)

#define MSG_TYPE_SAIL_2_MD_RAIL_VOTE_REQUEST          (0xddffu)
#define MSG_TYPE_MD_2_SAIL_RAIL_VOTE_RESPONSE         (MSG_TYPE_SAIL_2_MD_RAIL_VOTE_REQUEST + 1u)

#define MSG_TYPE_MD_2_SAIL_TSENS_READ_REQUEST         (0x2244u)
#define MSG_TYPE_SAIL_2_MD_TSENS_READ_RESPONSE        (MSG_TYPE_MD_2_SAIL_TSENS_READ_REQUEST + 1u)


#define MSG_TYPE_MD_2_SAIL_HELLO_MSG                   (0xbabau)

// Standard TLV message 
typedef struct
{
    //MSG_TYPE_* from above
    uint32_t msg_type;

    //Length of payload+ this header (excludes the sizeof(struct pm_msg_header))
    uint32_t msg_length;
}pm_msg_header;

//Used for loopback for qualification of underlying MB layers.
//APPS populates the variable length data
typedef struct
{
    pm_msg_header header;

    //Variable length data, possibly sequenced and populated with randomness
    uint32_t data [0];
}pm_msg_loopback_request_and_response;

//Used by APPS to 'prepare' the SAIL for an impending sleep cycle.
typedef struct
{
    pm_msg_header header;

    //Currently reserved, set to zero
    uint32_t rsvd; 
}pm_msg_prepare_for_sleep_request;

//Used by SAIL to respond to APSS's 'prepare-sleep' request
typedef struct
{
    pm_msg_header header;

    // Generic OS error code (<errno.h>) from SAIL for the sleep prepare-request from APPS
    // EOK (0) implies success
    uint32_t response_status;
}pm_msg_prepare_for_sleep_response;

//Used by SAIL to place a BW vote between SAIL and an endpoint.
typedef struct
{
    pm_msg_header header;

    //The master ID within the bus topology
    uint32_t mid;

    //The slave ID within the bus topology
    uint32_t sid;

    //Requested instantaneous BW
    uint64_t ib;

    //Requested average BW
    uint64_t ab;
}pm_msg_bw_vote_request;

//Used by APPS to respond to SAIL's BW vote request
typedef struct
{
    pm_msg_header header;

    // Generic OS error code (<errno.h>) from APPS for the BW vote request from SAIL
    // EOK (0) implies success
    uint32_t response_status;
}pm_msg_bw_vote_response;

//Used by SAIL to set the rail voltage to a particular corner.
typedef struct
{
    pm_msg_header header;

    //Null terminated rail name (vdd_mx, vdd_cx)
    char rail_name [16]; 

    //The corner to set the rail to
    uint32_t corner;
}pm_msg_rail_vote_request;

//Used by APPS to respond to SAIL's rail voltage vote request
typedef struct
{
    pm_msg_header header;

    char rail_name [16];
    // Generic OS error code (<errno.h>) from APPS for the rail voltage vote request from SAIL
    // EOK (0) implies success
    uint32_t response_status;
    //Read out corner value after vote is being sent to AOSS from QNX
    uint32_t corner;
}pm_msg_rail_vote_response;


//Used by APPS to read all SAIL TSENS in a single message
typedef struct 
{
    pm_msg_header header;
}pm_msg_read_tsens_request;

//Used by SAIL to respond to APSS's SAIL tsens read request
typedef struct 
{
    pm_msg_header header;

    // Generic OS error code (<errno.h>) from APPS for the rail voltage vote request from SAIL
    // EOK (0) implies success
    int8_t  response_status;   

    //Number of sensors returned within this message
    uint8_t num_sensors;

    //8bit signed temperature value of the sensors,
    //bounded by the num_sensors member.
    int8_t temperature [0];

}pm_msg_read_tsens_response;

#endif
