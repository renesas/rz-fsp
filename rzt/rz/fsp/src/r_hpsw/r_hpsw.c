/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_hpsw.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** "HPSW" in ASCII, used to determine if channel is open. */
#define HPSW_OPEN             (('H' << 24U) | ('P' << 16U) | ('S' << 8U) | ('W' << 0U))

/* Initial value of down counter for timeout detection */
#define HPSW_TIMEOUT_COUNT    (1000000000)

/* Bit Mask for register access */
#define HPSW_1BIT_MASK        (0x1U)
#define HPSW_2BITS_MASK       (0x3U)
#define HPSW_3BITS_MASK       (0x7U)
#define HPSW_4BITS_MASK       (0xfU)
#define HPSW_8BITS_MASK       (0xffU)
#define HPSW_16BITS_MASK      (0xffffU)

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void r_hpsw_state_initialize(void);
static void r_hpsw_enable(ether_switch_ctrl_t * const p_ctrl, hpsw_cfg_t const * const p_cfg);
static void r_hpsw_ptp_enable(ether_switch_ctrl_t * const p_ctrl, hpsw_cfg_t const * const p_cfg);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/** HPSW Implementation of General Timer Driver  */
const ether_switch_api_t g_ether_switch_on_hpsw =
{
    .open  = R_HPSW_Open,
    .close = R_HPSW_Close,
};

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
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initializes the HPSW module instance. Implements @ref ether_switch_api_t::open.
 *
 * @retval FSP_SUCCESS                 HPSW configuration set successfully.
 * @retval FSP_ERR_ASSERTION           Pointer to HPSW control block or configuration structure is NULL.
 * @retval FSP_ERR_ALREADY_OPEN        R_HPSW_Open has already been called for this p_ctrl.
 **********************************************************************************************************************/
fsp_err_t R_HPSW_Open (ether_switch_ctrl_t * const p_ctrl, ether_switch_cfg_t const * const p_cfg)
{
    hpsw_instance_ctrl_t * p_instance_ctrl = (hpsw_instance_ctrl_t *) p_ctrl;
    R_HPSW_INI_Type      * p_reg_hpsw_ini  = R_HPSW_INI;
    R_HPSW_Type          * p_reg_hpsw      = R_HPSW;

#if HPSW_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_cfg);
#endif
    FSP_ERROR_RETURN(HPSW_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);

    p_instance_ctrl->p_hpsw_ini_reg = p_reg_hpsw_ini;
    p_instance_ctrl->p_hpsw_reg     = p_reg_hpsw;
    p_instance_ctrl->p_hpsw_cfg     = p_cfg;

    /* One time initialization for all HPSW instances. */
    r_hpsw_state_initialize();

    /* Mark instance as opened. */
    p_instance_ctrl->open = HPSW_OPEN;

    /* All done.  */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Close driver data.  Implements @ref ether_switch_api_t::close.
 *
 * @retval FSP_SUCCESS                 HPSW closed.
 * @retval FSP_ERR_ASSERTION           p_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_HPSW_Close (ether_switch_ctrl_t * const p_ctrl)
{
    hpsw_instance_ctrl_t * p_instance_ctrl = (hpsw_instance_ctrl_t *) p_ctrl;

#if HPSW_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(HPSW_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_ctrl);
#endif

    p_instance_ctrl->p_hpsw_cfg     = NULL;
    p_instance_ctrl->p_hpsw_ini_reg = NULL;
    p_instance_ctrl->p_hpsw_reg     = NULL;

    /* Mark instance as closed. */
    p_instance_ctrl->open = 0U;

    /* All done.  */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Set the converter speed and duplex after initilaize. Speed 1000Mbps is valid for only RGMII.
 *
 * @retval FSP_SUCCESS                 Speed adn duplex seetings successfully changed.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_HPSW_EnableSet (ether_switch_ctrl_t * const p_ctrl, hpsw_cfg_t const * const p_cfg, bool enable)
{
    hpsw_instance_ctrl_t * p_instance_ctrl = (hpsw_instance_ctrl_t *) p_ctrl;
    R_HPSW_Type          * p_reg_hpsw;

#if HPSW_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ERROR_RETURN(HPSW_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_reg_hpsw = p_instance_ctrl->p_hpsw_reg;

    if (enable)
    {
        r_hpsw_enable(p_instance_ctrl, p_cfg);
        r_hpsw_ptp_enable(p_instance_ctrl, p_cfg);

        p_reg_hpsw->ClockControl_b.ENABLE = 0x1;
        p_reg_hpsw->HSRPRPCONTROL_b.EN    = 0x1;
        p_reg_hpsw->TCCONTROL_b.ENABLE    = 0x1;
        p_reg_hpsw->OCCONTROL_b.ENABLE    = 0x1;
    }
    else
    {
        p_reg_hpsw->ClockControl_b.ENABLE = 0x0;
        p_reg_hpsw->HSRPRPCONTROL_b.EN    = 0x0;
        p_reg_hpsw->TCCONTROL_b.ENABLE    = 0x0;
        p_reg_hpsw->OCCONTROL_b.ENABLE    = 0x0;
    }

    /* All done.  */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Retrieves the current state and counter value stores them in p_status.
 *
 * @retval FSP_SUCCESS                 Current status and counter value provided in p_status.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_HPSW_StatusGet (ether_switch_ctrl_t * const p_ctrl, hpsw_status_t * const p_status)
{
    hpsw_instance_ctrl_t * p_instance_ctrl = (hpsw_instance_ctrl_t *) p_ctrl;
    R_HPSW_Type          * p_reg_hpsw;

#if HPSW_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(HPSW_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_reg_hpsw = p_instance_ctrl->p_hpsw_reg;

    p_status->timeout_port_A = (hpsw_port_timeout_t) p_reg_hpsw->HSRPRPSTATUS_b.TOA;
    p_status->timeout_port_B = (hpsw_port_timeout_t) p_reg_hpsw->HSRPRPSTATUS_b.TOB;
    p_status->link_port_A    = (hpsw_port_link_t) p_reg_hpsw->HSRPRPSTATUS_b.LINKA;
    p_status->link_port_B    = (hpsw_port_link_t) p_reg_hpsw->HSRPRPSTATUS_b.LINKB;
    p_status->link_port_C    = (hpsw_port_link_t) p_reg_hpsw->HSRPRPSTATUS_b.LINKC;

    /* All done.  */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Retrieves the current state and counter value stores them in p_status.
 *
 * @retval FSP_SUCCESS                 Current status and counter value provided in p_status.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_HPSW_CounterGet (ether_switch_ctrl_t * const p_ctrl, uint32_t port, hpsw_counter_t * const p_counter)
{
    hpsw_instance_ctrl_t * p_instance_ctrl = (hpsw_instance_ctrl_t *) p_ctrl;
    R_HPSW_Type          * p_reg_hpsw;

#if HPSW_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_counter);
    FSP_ERROR_RETURN(HPSW_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_reg_hpsw = p_instance_ctrl->p_hpsw_reg;

    switch (port)
    {
        case 0:                        /* Port A */
        {
            p_counter->TX_counter       = p_reg_hpsw->HSRPRPTXFRAMECOUNT0;
            p_counter->TX_error_counter = p_reg_hpsw->HSRPRPTXERRCOUNT0;
            p_counter->RX_counter       = p_reg_hpsw->HSRPRPRXFRAMECOUNT0;
            p_counter->RX_error_counter = p_reg_hpsw->HSRPRPRXERRCOUNT0;
            break;
        }

        case 1:                        /* Port B */
        {
            p_counter->TX_counter       = p_reg_hpsw->HSRPRPTXFRAMECOUNT1;
            p_counter->TX_error_counter = p_reg_hpsw->HSRPRPTXERRCOUNT1;
            p_counter->RX_counter       = p_reg_hpsw->HSRPRPRXFRAMECOUNT1;
            p_counter->RX_error_counter = p_reg_hpsw->HSRPRPRXERRCOUNT1;
            break;
        }

        case 2:                        /* Port C */
        {
            p_counter->TX_counter       = p_reg_hpsw->HSRPRPTXFRAMECOUNT2;
            p_counter->TX_error_counter = p_reg_hpsw->HSRPRPTXERRCOUNT2;
            p_counter->RX_counter       = p_reg_hpsw->HSRPRPRXFRAMECOUNT2;
            p_counter->RX_error_counter = p_reg_hpsw->HSRPRPRXERRCOUNT2;
            break;
        }

        default:
        {
            break;
        }
    }

    /* All done. */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Retrieves the current state and counter value stores them in p_status.
 *
 * @retval FSP_SUCCESS                 Current status and counter value provided in p_status.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_HPSW_CounterClear (ether_switch_ctrl_t * const p_ctrl)
{
    hpsw_instance_ctrl_t * p_instance_ctrl = (hpsw_instance_ctrl_t *) p_ctrl;
    R_HPSW_Type          * p_reg_hpsw;

#if HPSW_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(HPSW_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_reg_hpsw = p_instance_ctrl->p_hpsw_reg;

    p_reg_hpsw->HSRPRPFRAMECOUNTCONTROL_b.CLR = 0x1;

    /* All done.  */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Retrieves the current state and counter value stores them in p_status.
 *
 * @retval FSP_SUCCESS                 Current status and counter value provided in p_status.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 * @retval FSP_ERR_TIMEOUT             Read data set wait timeout.
 **********************************************************************************************************************/
fsp_err_t R_HPSW_PtpDataGet (ether_switch_ctrl_t * const p_ctrl, hpsw_ptp_dataset_t * const p_dataset)
{
    hpsw_instance_ctrl_t * p_instance_ctrl = (hpsw_instance_ctrl_t *) p_ctrl;
    R_HPSW_Type          * p_reg_hpsw;
    uint32_t               time = HPSW_TIMEOUT_COUNT;
    fsp_err_t              err  = FSP_SUCCESS;

#if HPSW_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_dataset);
    FSP_ERROR_RETURN(HPSW_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_reg_hpsw = p_instance_ctrl->p_hpsw_reg;

    /* Read TC default data */
    p_reg_hpsw->TCDEFAULTDSCONTROL_b.READ = 0x1;
    while (p_reg_hpsw->TCDEFAULTDSCONTROL_b.READDONE != 0x1)
    {
        /* Timeout */
        if (time == 0)
        {
            err = FSP_ERR_TIMEOUT;

            return err;
        }

        time--;
    }

    p_dataset->ptp_tc_default_data_1 = p_reg_hpsw->TCDEFAULTDS1;
    p_dataset->ptp_tc_default_data_2 = p_reg_hpsw->TCDEFAULTDS2;
    p_dataset->ptp_tc_default_data_3 = p_reg_hpsw->TCDEFAULTDS3;
    p_dataset->ptp_tc_default_data_4 = p_reg_hpsw->TCDEFAULTDS4;

    /* Read TC port data */
    p_reg_hpsw->TCPORTDSCONTROL_b.READ = 0x1;
    time = HPSW_TIMEOUT_COUNT;
    while (p_reg_hpsw->TCPORTDSCONTROL_b.READDONE != 0x1)
    {
        /* Timeout */
        if (time == 0)
        {
            err = FSP_ERR_TIMEOUT;

            return err;
        }

        time--;
    }

    p_dataset->ptp_tc_port_data_1 = p_reg_hpsw->TCPORTDS1;
    p_dataset->ptp_tc_port_data_2 = p_reg_hpsw->TCPORTDS2;
    p_dataset->ptp_tc_port_data_3 = p_reg_hpsw->TCPORTDS3;
    p_dataset->ptp_tc_port_data_4 = p_reg_hpsw->TCPORTDS4;
    p_dataset->ptp_tc_port_data_5 = p_reg_hpsw->TCPORTDS5;
    p_dataset->ptp_tc_port_data_6 = p_reg_hpsw->TCPORTDS6;

    /* Read OC default data */
    p_reg_hpsw->OCDEFAULTDSCONTROL_b.READ = 0x1;
    time = HPSW_TIMEOUT_COUNT;
    while (p_reg_hpsw->OCDEFAULTDSCONTROL_b.READDONE != 0x1)
    {
        /* Timeout */
        if (time == 0)
        {
            err = FSP_ERR_TIMEOUT;

            return err;
        }

        time--;
    }

    p_dataset->ptp_oc_default_data_1 = p_reg_hpsw->OCDEFAULTDS1;
    p_dataset->ptp_oc_default_data_2 = p_reg_hpsw->OCDEFAULTDS2;
    p_dataset->ptp_oc_default_data_3 = p_reg_hpsw->OCDEFAULTDS3;
    p_dataset->ptp_oc_default_data_4 = p_reg_hpsw->OCDEFAULTDS4;
    p_dataset->ptp_oc_default_data_5 = p_reg_hpsw->OCDEFAULTDS5;
    p_dataset->ptp_oc_default_data_6 = p_reg_hpsw->OCDEFAULTDS6;
    p_dataset->ptp_oc_default_data_7 = p_reg_hpsw->OCDEFAULTDS7;

    /* Read OC port data */
    p_reg_hpsw->OCPORTDSCONTROL_b.READ = 0x1;
    time = HPSW_TIMEOUT_COUNT;
    while (p_reg_hpsw->OCPORTDSCONTROL_b.READDONE != 0x1)
    {
        /* Timeout */
        if (time == 0)
        {
            err = FSP_ERR_TIMEOUT;

            return err;
        }

        time--;
    }

    p_dataset->ptp_oc_port_data_1 = p_reg_hpsw->OCPORTDS1;
    p_dataset->ptp_oc_port_data_2 = p_reg_hpsw->OCPORTDS2;
    p_dataset->ptp_oc_port_data_3 = p_reg_hpsw->OCPORTDS3;
    p_dataset->ptp_oc_port_data_4 = p_reg_hpsw->OCPORTDS4;
    p_dataset->ptp_oc_port_data_5 = p_reg_hpsw->OCPORTDS5;
    p_dataset->ptp_oc_port_data_6 = p_reg_hpsw->OCPORTDS6;
    p_dataset->ptp_oc_port_data_7 = p_reg_hpsw->OCPORTDS7;
    p_dataset->ptp_oc_port_data_8 = p_reg_hpsw->OCPORTDS8;

    /* Read OC current data */
    p_reg_hpsw->OCCURRENTDSCONTROL_b.READ = 0x1;
    time = HPSW_TIMEOUT_COUNT;
    while (p_reg_hpsw->OCCURRENTDSCONTROL_b.READDONE != 0x1)
    {
        /* Timeout */
        if (time == 0)
        {
            err = FSP_ERR_TIMEOUT;

            return err;
        }

        time--;
    }

    p_dataset->ptp_oc_current_data_1 = p_reg_hpsw->OCCURRENTDS1;
    p_dataset->ptp_oc_current_data_2 = p_reg_hpsw->OCCURRENTDS2;
    p_dataset->ptp_oc_current_data_3 = p_reg_hpsw->OCCURRENTDS3;
    p_dataset->ptp_oc_current_data_4 = p_reg_hpsw->OCCURRENTDS4;
    p_dataset->ptp_oc_current_data_5 = p_reg_hpsw->OCCURRENTDS5;

    /* Read OC parent data */
    p_reg_hpsw->OCPARENTDSCONTROL_b.READ = 0x1;
    time = HPSW_TIMEOUT_COUNT;
    while (p_reg_hpsw->OCPARENTDSCONTROL_b.READDONE != 0x1)
    {
        /* Timeout */
        if (time == 0)
        {
            err = FSP_ERR_TIMEOUT;

            return err;
        }

        time--;
    }

    p_dataset->ptp_oc_parent_data_1 = p_reg_hpsw->OCPARENTDS1;
    p_dataset->ptp_oc_parent_data_2 = p_reg_hpsw->OCPARENTDS2;
    p_dataset->ptp_oc_parent_data_3 = p_reg_hpsw->OCPARENTDS3;
    p_dataset->ptp_oc_parent_data_4 = p_reg_hpsw->OCPARENTDS4;
    p_dataset->ptp_oc_parent_data_5 = p_reg_hpsw->OCPARENTDS5;
    p_dataset->ptp_oc_parent_data_6 = p_reg_hpsw->OCPARENTDS6;
    p_dataset->ptp_oc_parent_data_7 = p_reg_hpsw->OCPARENTDS7;
    p_dataset->ptp_oc_parent_data_8 = p_reg_hpsw->OCPARENTDS8;
    p_dataset->ptp_oc_parent_data_9 = p_reg_hpsw->OCPARENTDS9;

    /* Read OC time properties data */
    p_reg_hpsw->OCTIMEPROPERTIESDSCONTROL_b.READ = 0x1;
    time = HPSW_TIMEOUT_COUNT;
    while (p_reg_hpsw->OCTIMEPROPERTIESDSCONTROL_b.READDONE != 0x1)
    {
        /* Timeout */
        if (time == 0)
        {
            err = FSP_ERR_TIMEOUT;

            return err;
        }

        time--;
    }

    p_dataset->ptp_oc_time_propertie_data_1 = p_reg_hpsw->OCTIMEPROPERTIESDS1;
    p_dataset->ptp_oc_time_propertie_data_2 = p_reg_hpsw->OCTIMEPROPERTIESDS2;
    p_dataset->ptp_oc_time_propertie_data_3 = p_reg_hpsw->OCTIMEPROPERTIESDS3;
    p_dataset->ptp_oc_time_propertie_data_4 = p_reg_hpsw->OCTIMEPROPERTIESDS4;
    p_dataset->ptp_oc_time_propertie_data_5 = p_reg_hpsw->OCTIMEPROPERTIESDS5;
    p_dataset->ptp_oc_time_propertie_data_6 = p_reg_hpsw->OCTIMEPROPERTIESDS6;
    p_dataset->ptp_oc_time_propertie_data_7 = p_reg_hpsw->OCTIMEPROPERTIESDS7;
    p_dataset->ptp_oc_time_propertie_data_8 = p_reg_hpsw->OCTIMEPROPERTIESDS8;
    p_dataset->ptp_oc_time_propertie_data_9 = p_reg_hpsw->OCTIMEPROPERTIESDS9;

    /* All done.  */
    return err;
}

/** @} (end addtogroup HPSW) */
#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * HPSW Enable
 **********************************************************************************************************************/
static void r_hpsw_enable (ether_switch_ctrl_t * const p_ctrl, hpsw_cfg_t const * const p_cfg)
{
    hpsw_instance_ctrl_t * p_instance_ctrl = (hpsw_instance_ctrl_t *) p_ctrl;
    R_HPSW_Type          * p_reg_hpsw      = p_instance_ctrl->p_hpsw_reg;
    R_HPSW_INI_Type      * p_reg_hpsw_ini  = p_instance_ctrl->p_hpsw_ini_reg;

    p_reg_hpsw_ini->HPSW_C_CLK_SEL_b.CSEL = p_reg_hpsw_ini->HPSW_LINK_SPD_b.RPC;

    p_reg_hpsw->ClockControl_b.TIMEVAL         = p_cfg->time_val & HPSW_1BIT_MASK;
    p_reg_hpsw->ClockControl_b.OFFSETVAL       = p_cfg->offset_val & HPSW_1BIT_MASK;
    p_reg_hpsw->ClockControl_b.DRIFTVAL        = p_cfg->drift_val & HPSW_1BIT_MASK;
    p_reg_hpsw->ClockControl_b.SERVOVAL        = p_cfg->servo_val & HPSW_1BIT_MASK;
    p_reg_hpsw->ClockSelect_b.CLKSELECT        = p_cfg->clk_select & HPSW_8BITS_MASK;
    p_reg_hpsw->ClockTimeAdjValueL_b.TIMEADJNS = p_cfg->clock_time_adj_value_H;
    p_reg_hpsw->ClockTimeAdjValueH_b.TIMEADJNS = p_cfg->clock_time_adj_value_L;
    p_reg_hpsw->HSRPRPCONFIGMODE_b.MODE        = ((hpsw_extend_cfg_t *) p_instance_ctrl->p_hpsw_cfg->p_extend)->mode &
                                                 HPSW_3BITS_MASK;
    p_reg_hpsw->HSRPRPCONFIGCONTROL_b.MODEVAL = 0x1;
    if (p_cfg->vlan_val == 0x1)
    {
        p_reg_hpsw->HSRPRPCONFIGVLAN_b.VLAN       = p_cfg->vlan & HPSW_16BITS_MASK;
        p_reg_hpsw->HSRPRPCONFIGVLAN_b.VLANEN     = 0x1;
        p_reg_hpsw->HSRPRPCONFIGCONTROL_b.VLANVAL = p_cfg->vlan_val & HPSW_1BIT_MASK;
    }

    p_reg_hpsw->HSRPRPMAC1                = p_cfg->mac1;
    p_reg_hpsw->HSRPRPMAC2                = p_cfg->mac2;
    p_reg_hpsw->HSRPRPMACCONTROL_b.MACVAL = 0x1;
}

/*******************************************************************************************************************//**
 * PTP Enable
 **********************************************************************************************************************/
static void r_hpsw_ptp_enable (ether_switch_ctrl_t * const p_ctrl, hpsw_cfg_t const * const p_cfg)
{
    hpsw_instance_ctrl_t * p_instance_ctrl = (hpsw_instance_ctrl_t *) p_ctrl;
    R_HPSW_Type          * p_reg_hpsw      = p_instance_ctrl->p_hpsw_reg;

    /* PTP TC */
    p_reg_hpsw->TCCONFIGPROFILE_b.PROFILE = p_cfg->ptp_tc_profile;
    if (p_cfg->ptp_tc_profile == HPSW_PTP_TC_DEFAULT)
    {
        p_reg_hpsw->TCCONFIGPROFILE_b.LAYER          = p_cfg->ptp_tc_layer & HPSW_1BIT_MASK;
        p_reg_hpsw->TCCONFIGPROFILE_b.DELAYMECHANISM = p_cfg->ptp_tc_delay_mechanism & HPSW_1BIT_MASK;
    }

    p_reg_hpsw->TCCONFIGPROFILE_b.TWOSTEP         = p_cfg->ptp_tc_twostep & HPSW_1BIT_MASK;
    p_reg_hpsw->TCCONFIGPROFILE_b.DELAYE2EUNICAST = p_cfg->ptp_tc_delay_E2E_uni & HPSW_1BIT_MASK;
    p_reg_hpsw->TCCONFIGCONTROL_b.PROFILEVAL      = p_cfg->ptp_tc_profile_val & HPSW_1BIT_MASK;
    p_reg_hpsw->TCCONFIGCONTROL_b.VLANVAL         = p_cfg->ptp_tc_vlan_val & HPSW_1BIT_MASK;
    p_reg_hpsw->TCCONFIGCONTROL_b.IPVAL           = p_cfg->ptp_tc_ip_val & HPSW_1BIT_MASK;
    p_reg_hpsw->TCCONFIGCONTROL_b.DSCPVAL         = p_cfg->ptp_tc_dscp_val & HPSW_1BIT_MASK;
    p_reg_hpsw->TCDEFAULTDS1 = p_cfg->ptp_tc_default_data_1;
    p_reg_hpsw->TCDEFAULTDS2 = p_cfg->ptp_tc_default_data_2;
    p_reg_hpsw->TCDEFAULTDSCONTROL_b.CLOCKIDVAL  = p_cfg->ptp_tc_clock_id_val & HPSW_1BIT_MASK;
    p_reg_hpsw->TCDEFAULTDSCONTROL_b.DOMAINNRVAL = p_cfg->ptp_tc_domain_num_val & HPSW_1BIT_MASK;

    /* PTP OC */
    p_reg_hpsw->OCCONFIGPROFILE_b.PROFILE          = p_cfg->ptp_oc_profile & HPSW_3BITS_MASK;
    p_reg_hpsw->OCCONFIGPROFILE_b.TWOSTEP          = p_cfg->ptp_oc_twostep & HPSW_1BIT_MASK;
    p_reg_hpsw->OCCONFIGPROFILE_b.SIGNALING        = p_cfg->ptp_oc_signaling & HPSW_1BIT_MASK;
    p_reg_hpsw->OCCONFIGPROFILE_b.MASTERSLAVEONLY  = p_cfg->ptp_oc_master_slave & HPSW_2BITS_MASK;
    p_reg_hpsw->OCCONFIGPROFILE_b.DISABLEOFFSETCOR = p_cfg->ptp_oc_dis_offset_correction & HPSW_1BIT_MASK;
    p_reg_hpsw->OCCONFIGPROFILE_b.AUTHUNICASTSLAVE = p_cfg->ptp_oc_allow_uni_slave & HPSW_1BIT_MASK;
    p_reg_hpsw->OCCONFIGPROFILE_b.DELAYMECHANISM   = p_cfg->ptp_oc_delay_mechanism & HPSW_1BIT_MASK;
    p_reg_hpsw->OCCONFIGPROFILE_b.DELAYE2EUNICAST  = p_cfg->ptp_oc_delay_E2E_uni & HPSW_1BIT_MASK;
    p_reg_hpsw->OCCONFIGCONTROL_b.PROFILEVAL       = p_cfg->ptp_oc_profile_val & HPSW_1BIT_MASK;
    p_reg_hpsw->OCCONFIGCONTROL_b.VLANVAL          = p_cfg->ptp_oc_vlan_val & HPSW_1BIT_MASK;
    p_reg_hpsw->OCCONFIGCONTROL_b.IPVAL            = p_cfg->ptp_oc_ip_val & HPSW_1BIT_MASK;
    p_reg_hpsw->OCCONFIGCONTROL_b.DSCPVAL          = p_cfg->ptp_oc_dscp_val & HPSW_1BIT_MASK;
    p_reg_hpsw->OCDEFAULTDS1 = p_cfg->ptp_oc_default_data_1;
    p_reg_hpsw->OCDEFAULTDS2 = p_cfg->ptp_oc_default_data_2;
    p_reg_hpsw->OCDEFAULTDSCONTROL_b.CLOCKIDVAL      = p_cfg->ptp_oc_clock_id_val & HPSW_1BIT_MASK;
    p_reg_hpsw->OCDEFAULTDSCONTROL_b.DOMAINNRVAL     = p_cfg->ptp_oc_domain_num_val & HPSW_1BIT_MASK;
    p_reg_hpsw->OCDEFAULTDSCONTROL_b.CLOCKQUALIRYVAL = p_cfg->ptp_oc_clock_qualiry_val & HPSW_1BIT_MASK;
    p_reg_hpsw->OCDEFAULTDSCONTROL_b.PRIORITY1VAL    = p_cfg->ptp_oc_priority1_val & HPSW_1BIT_MASK;
    p_reg_hpsw->OCDEFAULTDSCONTROL_b.PRIORITY2VAL    = p_cfg->ptp_oc_priority2_val & HPSW_1BIT_MASK;
    p_reg_hpsw->OCDEFAULTDSCONTROL_b.GMIDVAL         = p_cfg->ptp_oc_gm_id_val & HPSW_1BIT_MASK;
    p_reg_hpsw->OCDEFAULTDSCONTROL_b.GMTIMEINACVAL   = p_cfg->ptp_oc_gm_time_inac_val & HPSW_1BIT_MASK;
    p_reg_hpsw->OCDEFAULTDSCONTROL_b.MAXSTEPSREMVAL  = p_cfg->ptp_oc_max_steps_rem_val & HPSW_1BIT_MASK;
    p_reg_hpsw->OCDEFAULTDSCONTROL_b.LOCALPRIOVAL    = p_cfg->ptp_oc_local_priority_val & HPSW_1BIT_MASK;
    p_reg_hpsw->OCDEFAULTDS3_b.PRIORITY1             = p_cfg->ptp_oc_priority1 & HPSW_8BITS_MASK;
    p_reg_hpsw->OCDEFAULTDS3_b.PRIORITY2             = p_cfg->ptp_oc_priority2 & HPSW_8BITS_MASK;
    p_reg_hpsw->OCPORTDS5_b.ANNOUNCEINTERVAL         = p_cfg->ptp_oc_announce_interval & HPSW_8BITS_MASK;
    p_reg_hpsw->OCPORTDS5_b.ANNOUNCETIMEOUT          = p_cfg->ptp_oc_announce_timeout & HPSW_8BITS_MASK;
    p_reg_hpsw->OCPORTDSCONTROL_b.DELAYMECHANISMVAL  = p_cfg->delay_mechanism_val & HPSW_1BIT_MASK;
    p_reg_hpsw->OCPORTDSCONTROL_b.MSGINTERVALVAL     = p_cfg->msg_interval_val & HPSW_1BIT_MASK;
    p_reg_hpsw->OCPORTDSCONTROL_b.ASYNNETRYVAL       = p_cfg->asymmetry_val & HPSW_1BIT_MASK;
    p_reg_hpsw->OCPORTDSCONTROL_b.MAXPDELAYVAL       = p_cfg->max_pdelay_val & HPSW_1BIT_MASK;
    p_reg_hpsw->OCPORTDSCONTROL_b.LOCALPRIOVAL       = p_cfg->local_priority_val & HPSW_1BIT_MASK;
}

/*******************************************************************************************************************//**
 * One time state initialization for all HPSW instances.
 **********************************************************************************************************************/
static void r_hpsw_state_initialize (void)
{
    /* Stores initialization state to skip initialization in ::R_ETHER_SELECTOR_Open after the first call. */
    static bool g_hpsw_state_initialized = false;

    /* HPSW requires a one time initialization.
     *  This will be handled only the first time this function is called.
     *  This initialization:
     *  -# Powers on the HPSW block.
     *  -# Release reset control of the ETHSS and the MII Converter  */
    if (!g_hpsw_state_initialized)
    {
        g_hpsw_state_initialized = true;

        /* Release from the slave stop state */
        R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_SYSTEM);
        R_BSP_SlaveStopRelease(BSP_BUS_SLAVE_HPSW);
        R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_SYSTEM);

        /* Power on HPSW*/
        R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
        R_BSP_MODULE_START(FSP_IP_HPSW, 0);

        /* Release modules */
        R_BSP_ModuleResetDisable(BSP_MODULE_RESET_HPSW);
        R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);
    }
}
