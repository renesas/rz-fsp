/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_HPSW_H
 #define R_HPSW_H

 #include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "r_hpsw_cfg.h"
 #include "r_ether_switch_api.h"

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZT
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_HPSW
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** C clock select */
typedef enum e_hpsw_c_clock
{
    HPSW_c_clock_0_MBPS    = 0x0,      ///< 0
    HPSW_c_clock_10_MBPS   = 0x1,      ///< 10Mbit/s(2.5MHz)
    HPSW_c_clock_100_MBPS  = 0x2,      ///< 100Mbit/s(25MHz)
    HPSW_c_clock_1000_MBPS = 0x3,      ///< 1000Mbit/s(125MHz)
} hpsw_c_clock_t;

/** port timeout */
typedef enum e_hpsw_port_timeout
{
    HPSW_PORT_NOT_TIMEOUT = 0,         ///< Not port timeout occured
    HPSW_PORT_TIMEOUT     = 1,         ///< Port timeout occured
} hpsw_port_timeout_t;

/** port link */
typedef enum e_hpsw_port_link
{
    HPSW_PORT_UNLINK = 0,              ///< Port unlink
    HPSW_PORT_LINK   = 1,              ///< Port link
} hpsw_port_link_t;

/** clock select */
typedef enum e_hpsw_clock_select
{
    HPSW_CLOCK_NONE = 0x00,            ///< NONE
    HPSW_CLOCK_TOD  = 0x01,            ///< TOD
    HPSW_CLOCK_LRIG = 0x02,            ///< LRIG
    HPSW_CLOCK_PPS  = 0x03,            ///< PPS
    HPSW_CLOCK_PTP  = 0x04,            ///< PTP
    HPSW_CLOCK_RTC  = 0x05,            ///< RTC
    HPSW_CLOCK_DCF  = 0x06,            ///< DCF
    HPSW_CLOCK_NTP  = 0x07,            ///< NTP
    HPSW_CLOCK_REGS = 0xFE,            ///< REGS
    HPSW_CLOCK_EXT  = 0xFF,            ///< EXT
} hpsw_clock_select_t;

/** mode select */
typedef enum e_hpsw_mode
{
    HPSW_MODE_NONE = 0x0,              ///< None
    HPSW_MODE_PRP  = 0x1,              ///< PRP
    HPSW_MODE_HSR  = 0x2,              ///< HSR
} hpsw_mode_t;

/** ptp tc profile */
typedef enum e_hpsw_ptp_tc_profile
{
    HPSW_PTP_TC_DEFAULT  = 0x0,        ///< Default profile
    HPSW_PTP_TC_ELECTRIC = 0x1,        ///< Electric power profile
    HPSW_PTP_TC_UTILITY  = 0x2,        ///< Utility profile
    HPSW_PTP_TC_TSN      = 0x3,        ///< TSN Profile
} hpsw_ptp_tc_profile_t;

/** ptp tc layer */
typedef enum e_hpsw_ptp_tc_layer
{
    HPSW_PTP_TC_LAYER_802  = 0x0,      ///< 802.3
    HPSW_PTP_TC_LAYER_IPv4 = 0x1,      ///< IPv4
} hpsw_ptp_tc_layer_t;

/** ptp tc delay mechanism */
typedef enum e_hpsw_ptp_tc_delay_mechanism
{
    HPSW_PTP_TC_DELAY_P2P = 0x0,       ///< P2P
    HPSW_PTP_TC_DELAY_E2E = 0x1,       ///< E2E
} hpsw_ptp_tc_delay_mechanism_t;

/** ptp tc E2E unicast or multicast */
typedef enum e_hpsw_ptp_tc_delay_e2e_uni
{
    HPSW_PTP_TC_DELAY_E2E_MULTI = 0x0, ///< Muliticast
    HPSW_PTP_TC_DELAY_E2E_UNI   = 0x1, ///< Unicast
} hpsw_ptp_tc_delay_e2e_uni_t;

/** ptp oc profile */
typedef enum e_hpsw_ptp_oc_profile
{
    HPSW_PTP_OC_DEFAULT     = 0x0,     ///< Default profile
    HPSW_PTP_OC_ELECTRIC    = 0x1,     ///< Electric power profile
    HPSW_PTP_OC_UTILITY     = 0x2,     ///< Utility profile
    HPSW_PTP_OC_TSN         = 0x3,     ///< TSN Profile
    HPSW_PTP_OC_ITU_G8265_1 = 0x4,     ///< ITU G8265.1 Profile
    HPSW_PTP_OC_ITU_G8275_1 = 0x5,     ///< ITU G8275.1 Profile
    HPSW_PTP_OC_ITU_G8275_2 = 0x6,     ///< ITU G8275.2 Profile
} hpsw_ptp_oc_profile_t;

/** ptp oc layer */
typedef enum e_hpsw_ptp_oc_layer
{
    HPSW_PTP_OC_LAYER_802  = 0x0,      ///< 802.3
    HPSW_PTP_OC_LAYER_IPv4 = 0x1,      ///< IPv4
    HPSW_PTP_OC_LAYER_IPv6 = 0x2,      ///< IPv6
} hpsw_ptp_oc_layer_t;

/** ptp oc master or slave select */
typedef enum e_hpsw_ptp_oc_master_slave_only
{
    HPSW_PTP_OC_MASTER_SLAVE = 0x0,    ///< Master and slave
    HPSW_PTP_OC_SLAVE        = 0x1,    ///< Slave only
    HPSW_PTP_OC_MASTER       = 0x2,    ///< Master only
} hpsw_ptp_oc_master_slave_only_t;

/** ptp oc delay mechanism */
typedef enum e_hpsw_ptp_oc_delay_mechanism
{
    HPSW_PTP_OC_DELAY_P2P = 0x0,       ///< P2P
    HPSW_PTP_OC_DELAY_E2E = 0x1,       ///< E2E
} hpsw_ptp_oc_delay_mechanism_t;

/** ptp oc E2E unicast or multicast */
typedef enum e_hpsw_ptp_oc_delay_e2e_uni
{
    HPSW_PTP_OC_DELAY_E2E_MULTI = 0x0, ///< Muliticast
    HPSW_PTP_OC_DELAY_E2E_UNI   = 0x1, ///< Unicast
} hpsw_ptp_oc_delay_e2e_uni_t;

/** HPSW configuration data for loading into registers by R_HPSW_Enable() */
struct st_hpsw_cfg
{
    /* Adjustable Clock */
    uint32_t            time_val;                                 ///< Time Adjustment Valid
    uint32_t            offset_val;                               ///< Offset Adjustment Valid
    uint32_t            drift_val;                                ///< Drift Adjustment Valid
    uint32_t            servo_val;                                ///< Servo Parameters Valid
    hpsw_clock_select_t clk_select;                               ///< Source for Clock Adjustments
    uint32_t            clock_time_adj_value_H;                   ///< Clock time adjustment value (High)
    uint32_t            clock_time_adj_value_L;                   ///< Clock time adjustment value (Low)

    /* PTP TC */
    hpsw_ptp_tc_profile_t         ptp_tc_profile;                 ///< Profile
    uint32_t                      ptp_tc_twostep;                 ///< Twostep for PDelay
    hpsw_ptp_tc_layer_t           ptp_tc_layer;                   ///< Layer
    hpsw_ptp_tc_delay_mechanism_t ptp_tc_delay_mechanism;         ///< Delay Mechanism
    hpsw_ptp_tc_delay_e2e_uni_t   ptp_tc_delay_E2E_uni;           ///< Delay E2E uni-cast
    uint32_t                      ptp_tc_profile_val;             ///< Profile valid
    uint32_t                      ptp_tc_vlan_val;                ///< VLAN valid
    uint32_t                      ptp_tc_ip_val;                  ///< IP valid
    uint32_t                      ptp_tc_dscp_val;                ///< DSCP valid
    uint32_t                      ptp_tc_clock_id_val;            ///< Clock Identity Valid
    uint32_t                      ptp_tc_domain_num_val;          ///< Domain Number Valid
    uint32_t                      ptp_tc_default_data_1;          ///< Default data 1
    uint32_t                      ptp_tc_default_data_2;          ///< Default data 2

    /* PTP OC */
    hpsw_ptp_oc_profile_t           ptp_oc_profile;               ///< Profile
    uint32_t                        ptp_oc_twostep;               ///< Twostep for PDelay
    uint32_t                        ptp_oc_signaling;             ///< Signaling
    hpsw_ptp_oc_layer_t             ptp_oc_layer;                 ///< Layer
    hpsw_ptp_oc_master_slave_only_t ptp_oc_master_slave;          ///< Master or slave select
    uint32_t                        ptp_oc_dis_offset_correction; ///< Disable offset correction
    uint32_t                        ptp_oc_allow_uni_slave;       ///< Only allow uni-cast slaves previously added to the uni-cast dataset
    hpsw_ptp_oc_delay_mechanism_t   ptp_oc_delay_mechanism;       ///< Delay Mechanism
    hpsw_ptp_oc_delay_e2e_uni_t     ptp_oc_delay_E2E_uni;         ///< Delay E2E uni-cast
    uint32_t                        ptp_oc_profile_val;           ///< Profile valid
    uint32_t                        ptp_oc_vlan_val;              ///< VLAN valid
    uint32_t                        ptp_oc_ip_val;                ///< IP valid
    uint32_t                        ptp_oc_dscp_val;              ///< DSCP valid
    uint32_t                        ptp_oc_clock_id_val;          ///< Clock ID valid
    uint32_t                        ptp_oc_domain_num_val;        ///< Domain number valid
    uint32_t                        ptp_oc_clock_qualiry_val;     ///< Clock quality valid
    uint32_t                        ptp_oc_priority1_val;         ///< Priority1 valid
    uint32_t                        ptp_oc_priority2_val;         ///< Priority2 valid
    uint32_t                        ptp_oc_gm_id_val;             ///< Grand master short ID valid
    uint32_t                        ptp_oc_gm_time_inac_val;      ///< Grand master time Inaccuracy valid
    uint32_t                        ptp_oc_max_steps_rem_val;     ///< Max steps removed valid
    uint32_t                        ptp_oc_local_priority_val;    ///< Local priority valid
    uint32_t                        ptp_oc_default_data_1;        ///< Default data 1
    uint32_t                        ptp_oc_default_data_2;        ///< Default data 2
    uint8_t  ptp_oc_priority1;                                    ///< Priority1
    uint8_t  ptp_oc_priority2;                                    ///< Priority2
    uint32_t delay_mechanism_val;                                 ///< Delay mechanism valid
    uint32_t msg_interval_val;                                    ///< Message intervals valid
    uint32_t asymmetry_val;                                       ///< Asymmetry valid
    uint32_t max_pdelay_val;                                      ///< Maximum peer delay valid
    uint32_t local_priority_val;                                  ///< Local priority valid
    uint32_t ptp_oc_announce_interval;                            ///< Signed announce log interval
    uint32_t ptp_oc_announce_timeout;                             ///< Announce timeout

    /* HPSW */
    uint32_t vlan_val;                                            ///< Vlan valid
    uint32_t vlan;                                                ///< Vlan
    uint32_t vlan_enable;                                         ///< Enable vlan

    uint32_t mac1;                                                ///< MAC 1
    uint32_t mac2;                                                ///< MAC 2
};

/** HPSW configuration data for loading into registers by R_HPSW_Enable() Please refer to the struct st_hpsw_cfg. */
typedef struct st_hpsw_cfg hpsw_cfg_t;

/** HPSW port status */
struct st_hpsw_status
{
    hpsw_port_timeout_t timeout_port_A; ///< Port A timeout
    hpsw_port_timeout_t timeout_port_B; ///< Port B timeout
    hpsw_port_link_t    link_port_A;    ///< Port A link status
    hpsw_port_link_t    link_port_B;    ///< Port B link status
    hpsw_port_link_t    link_port_C;    ///< Port C link status
};

/** HPSW port status Please refer to the struct st_hpsw_status. */
typedef struct st_hpsw_status hpsw_status_t;

/** HPSW send/receive frame counter */
struct st_hpsw_counter
{
    uint32_t TX_counter;               ///< TX counter
    uint32_t TX_error_counter;         ///< TX error counter
    uint32_t RX_counter;               ///< RX counter
    uint32_t RX_error_counter;         ///< RX error counter
};

/** HPSW send/receive frame counter Please refer to the struct st_hpsw_counter. */
typedef struct st_hpsw_counter hpsw_counter_t;

/** HPSW data set */
struct st_hpsw_ptp_dataset
{
    /* PTP TC */
    uint32_t ptp_tc_default_data_1;        ///< Default data 1
    uint32_t ptp_tc_default_data_2;        ///< Default data 2
    uint32_t ptp_tc_default_data_3;        ///< Default data 3
    uint32_t ptp_tc_default_data_4;        ///< Default data 4
    uint32_t ptp_tc_port_data_1;           ///< Port data 1
    uint32_t ptp_tc_port_data_2;           ///< Port data 2
    uint32_t ptp_tc_port_data_3;           ///< Port data 3
    uint32_t ptp_tc_port_data_4;           ///< Port data 4
    uint32_t ptp_tc_port_data_5;           ///< Port data 5
    uint32_t ptp_tc_port_data_6;           ///< Port data 6

    /* PTP OC */
    uint32_t ptp_oc_default_data_1;        ///< Default data 1
    uint32_t ptp_oc_default_data_2;        ///< Default data 2
    uint32_t ptp_oc_default_data_3;        ///< Default data 3
    uint32_t ptp_oc_default_data_4;        ///< Default data 4
    uint32_t ptp_oc_default_data_5;        ///< Default data 5
    uint32_t ptp_oc_default_data_6;        ///< Default data 6
    uint32_t ptp_oc_default_data_7;        ///< Default data 7
    uint32_t ptp_oc_port_data_1;           ///< Port data 1
    uint32_t ptp_oc_port_data_2;           ///< Port data 2
    uint32_t ptp_oc_port_data_3;           ///< Port data 3
    uint32_t ptp_oc_port_data_4;           ///< Port data 4
    uint32_t ptp_oc_port_data_5;           ///< Port data 5
    uint32_t ptp_oc_port_data_6;           ///< Port data 6
    uint32_t ptp_oc_port_data_7;           ///< Port data 7
    uint32_t ptp_oc_port_data_8;           ///< Port data 8
    uint32_t ptp_oc_current_data_1;        ///< Current data 1
    uint32_t ptp_oc_current_data_2;        ///< Current data 2
    uint32_t ptp_oc_current_data_3;        ///< Current data 3
    uint32_t ptp_oc_current_data_4;        ///< Current data 4
    uint32_t ptp_oc_current_data_5;        ///< Current data 5
    uint32_t ptp_oc_parent_data_1;         ///< Parent data 1
    uint32_t ptp_oc_parent_data_2;         ///< Parent data 2
    uint32_t ptp_oc_parent_data_3;         ///< Parent data 3
    uint32_t ptp_oc_parent_data_4;         ///< Parent data 4
    uint32_t ptp_oc_parent_data_5;         ///< Parent data 5
    uint32_t ptp_oc_parent_data_6;         ///< Parent data 6
    uint32_t ptp_oc_parent_data_7;         ///< Parent data 7
    uint32_t ptp_oc_parent_data_8;         ///< Parent data 8
    uint32_t ptp_oc_parent_data_9;         ///< Parent data 9
    uint32_t ptp_oc_time_propertie_data_1; ///< Time properties data 1
    uint32_t ptp_oc_time_propertie_data_2; ///< Time properties data 2
    uint32_t ptp_oc_time_propertie_data_3; ///< Time properties data 3
    uint32_t ptp_oc_time_propertie_data_4; ///< Time properties data 4
    uint32_t ptp_oc_time_propertie_data_5; ///< Time properties data 5
    uint32_t ptp_oc_time_propertie_data_6; ///< Time properties data 6
    uint32_t ptp_oc_time_propertie_data_7; ///< Time properties data 7
    uint32_t ptp_oc_time_propertie_data_8; ///< Time properties data 8
    uint32_t ptp_oc_time_propertie_data_9; ///< Time properties data 9
};

/** HPSW data set Please refer to the struct st_hpsw_ptp_dataset. */
typedef struct st_hpsw_ptp_dataset hpsw_ptp_dataset_t;

/** Extend Configuration parameters. */
struct st_hpsw_extend_cfg
{
    hpsw_mode_t mode;                  ///< HPSW Operating Profile
};

/** Extend Configuration parameters. Please refer to the struct st_hpsw_extend_cfg. */
typedef struct st_hpsw_extend_cfg hpsw_extend_cfg_t;

/** HPSW control block. DO NOT INITIALIZE.  Initialization occurs when @ref hpsw_instance_ctrl_t::open is called. */
struct st_hpsw_instance_ctrl
{
    uint32_t open;                         ///< Used to determine if the channel is configured

    /* Configuration of HPSW module. */
    ether_switch_cfg_t const * p_hpsw_cfg; ///< Pointer to initial configurations.

    /* Interface for HPSW */
    R_HPSW_INI_Type * p_hpsw_ini_reg;      ///< Pointer to HPSW init registers.
    R_HPSW_Type     * p_hpsw_reg;          ///< Pointer to HPSW registers.
};

/** HPSW control block. DO NOT INITIALIZE.  Initialization occurs when @ref hpsw_instance_ctrl_t::open is called. Please refer to the struct st_hpsw_instance_ctrl. */
typedef struct st_hpsw_instance_ctrl hpsw_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const ether_switch_api_t g_ether_switch_on_hpsw;

/** @endcond */

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 ***********************************************************************************************************************/

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/
fsp_err_t R_HPSW_Open(ether_switch_ctrl_t * const p_ctrl, ether_switch_cfg_t const * const p_cfg);

fsp_err_t R_HPSW_Close(ether_switch_ctrl_t * const p_ctrl);

fsp_err_t R_HPSW_EnableSet(ether_switch_ctrl_t * const p_ctrl, hpsw_cfg_t const * const p_cfg, bool enable);

fsp_err_t R_HPSW_StatusGet(ether_switch_ctrl_t * const p_ctrl, hpsw_status_t * const p_status);

fsp_err_t R_HPSW_CounterGet(ether_switch_ctrl_t * const p_ctrl, uint32_t port, hpsw_counter_t * const p_counter);

fsp_err_t R_HPSW_CounterClear(ether_switch_ctrl_t * const p_ctrl);

fsp_err_t R_HPSW_PtpDataGet(ether_switch_ctrl_t * const p_ctrl, hpsw_ptp_dataset_t * const p_dataset);

/*******************************************************************************************************************//**
 * @} (end addtogroup HPSW)
 **********************************************************************************************************************/
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 // R_HPSW_H
