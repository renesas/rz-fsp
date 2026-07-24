/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/

/* Access to peripherals and board defines. */
#include "bsp_api.h"
#include "r_gether_phy.h"

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

#ifndef GETHER_PHY_ERROR_RETURN

 #define GETHER_PHY_ERROR_RETURN(a, err)    FSP_ERROR_RETURN((a), (err))
#endif

#define GETHER_REG_SIZE                          (0x10000UL)

/** "RPHY" in ASCII.  Used to determine if the control block is open. */
#define GETHER_PHY_OPEN                          (0x52504859U)

/* Media Independent Interface */
#define GETHER_PHY_MII_ST                        (1)
#define GETHER_PHY_MII_READ                      (2)
#define GETHER_PHY_MII_WRITE                     (1)

/* Standard PHY Registers */
#define GETHER_PHY_REG_CONTROL                   (0)
#define GETHER_PHY_REG_STATUS                    (1)
#define GETHER_PHY_REG_IDENTIFIER1               (2)
#define GETHER_PHY_REG_IDENTIFIER2               (3)
#define GETHER_PHY_REG_AN_ADVERTISEMENT          (4)
#define GETHER_PHY_REG_AN_LINK_PARTNER           (5)
#define GETHER_PHY_REG_AN_EXPANSION              (6)
#define GETHER_PHY_REG_AN_MASTER_SLAVE_STATUS    (10)
#define GETHER_PHY_REG_EXSTATUS                  (15)

/* Basic Mode Control Register Bit Definitions */
#define GETHER_PHY_CONTROL_RESET                 (1 << 15)
#define GETHER_PHY_CONTROL_LOOPBACK              (1 << 14)
#define GETHER_PHY_CONTROL_100_MBPS              (1 << 13)
#define GETHER_PHY_CONTROL_AN_ENABLE             (1 << 12)
#define GETHER_PHY_CONTROL_POWER_DOWN            (1 << 11)
#define GETHER_PHY_CONTROL_ISOLATE               (1 << 10)
#define GETHER_PHY_CONTROL_AN_RESTART            (1 << 9)
#define GETHER_PHY_CONTROL_FULL_DUPLEX           (1 << 8)
#define GETHER_PHY_CONTROL_COLLISION             (1 << 7)

/* Basic Mode Status Register Bit Definitions */
#define GETHER_PHY_STATUS_100_T4                 (1 << 15)
#define GETHER_PHY_STATUS_100F                   (1 << 14)
#define GETHER_PHY_STATUS_100H                   (1 << 13)
#define GETHER_PHY_STATUS_10F                    (1 << 12)
#define GETHER_PHY_STATUS_10H                    (1 << 11)
#define GETHER_PHY_STATUS_AN_COMPLETE            (1 << 5)
#define GETHER_PHY_STATUS_RM_FAULT               (1 << 4)
#define GETHER_PHY_STATUS_AN_ABILITY             (1 << 3)
#define GETHER_PHY_STATUS_LINK_UP                (1 << 2)
#define GETHER_PHY_STATUS_JABBER                 (1 << 1)
#define GETHER_PHY_STATUS_EX_CAPABILITY          (1 << 0)

/* Auto Negotiation Advertisement Bit Definitions */
#define GETHER_PHY_AN_ADVERTISEMENT_NEXT_PAGE    (1 << 15)
#define GETHER_PHY_AN_ADVERTISEMENT_RM_FAULT     (1 << 13)
#define GETHER_PHY_AN_ADVERTISEMENT_ASM_DIR      (1 << 11)
#define GETHER_PHY_AN_ADVERTISEMENT_PAUSE        (1 << 10)
#define GETHER_PHY_AN_ADVERTISEMENT_100_T4       (1 << 9)
#define GETHER_PHY_AN_ADVERTISEMENT_100F         (1 << 8)
#define GETHER_PHY_AN_ADVERTISEMENT_100H         (1 << 7)
#define GETHER_PHY_AN_ADVERTISEMENT_10F          (1 << 6)
#define GETHER_PHY_AN_ADVERTISEMENT_10H          (1 << 5)
#define GETHER_PHY_AN_ADVERTISEMENT_SELECTOR     (1 << 0)

/* Auto Negotiate Link Partner Ability Bit Definitions */
#define GETHER_PHY_AN_LINK_PARTNER_NEXT_PAGE     (1 << 15)
#define GETHER_PHY_AN_LINK_PARTNER_ACK           (1 << 14)
#define GETHER_PHY_AN_LINK_PARTNER_RM_FAULT      (1 << 13)
#define GETHER_PHY_AN_LINK_PARTNER_ASM_DIR       (1 << 11)
#define GETHER_PHY_AN_LINK_PARTNER_PAUSE         (1 << 10)
#define GETHER_PHY_AN_LINK_PARTNER_100_T4        (1 << 9)
#define GETHER_PHY_AN_LINK_PARTNER_100F          (1 << 8)
#define GETHER_PHY_AN_LINK_PARTNER_100H          (1 << 7)
#define GETHER_PHY_AN_LINK_PARTNER_10F           (1 << 6)
#define GETHER_PHY_AN_LINK_PARTNER_10H           (1 << 5)
#define GETHER_PHY_AN_LINK_PARTNER_SELECTOR      (1 << 0)

#define GETHER_PHY_ADDRESS_SIZE                  (0x1fU)
#define GETHER_PHY_REGISTER_DATA_SIZE            (0xffffU)

/* Auto Negotiate Master Slave Status Bit Definitions */
#define GETHER_PHY_AN_LINK_PARTNER_1000F         (1 << 11)

#define GETHER_PHY_EXSTATUS_1000FX               (1 << 15)
#define GETHER_PHY_EXSTATUS_1000HX               (1 << 14)
#define GETHER_PHY_EXSTATUS_1000FT               (1 << 13)
#define GETHER_PHY_EXSTATUS_1000HT               (1 << 12)

#define GETHER_PHY_CXR23_MDI_MASK                (1 << 3)
#define GETHER_PHY_CXR23_MDO_HIGH                (0x04)
#define GETHER_PHY_CXR23_MDO_LOW                 (0x00)
#define GETHER_PHY_CXR23_MMD_WRITE               (0x02)
#define GETHER_PHY_CXR23_MMD_READ                (0x00)
#define GETHER_PHY_CXR23_MDC_HIGH                (0x01)
#define GETHER_PHY_CXR23_MDC_LOW                 (0x00)

#define GETHER_PHY_PREAMBLE_LENGTH               (32U)
#define GETHER_PHY_WRITE_DATA_BIT_MASK           (0x8000)

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global function
 ***********************************************************************************************************************/

#if (ETHER_PHY_CFG_TARGET_KSZ9131RNXI_ENABLE)
extern void gether_phy_targets_ksz9131rnxi_initialize(ether_phy_instance_ctrl_t * p_instance_ctrl);
extern bool gether_phy_target_ksz9131rnxi_is_support_link_partner_ability(ether_phy_instance_ctrl_t * p_instance_ctrl,
                                                                          uint32_t                    line_speed_duplex);

#endif

/***********************************************************************************************************************
 * Private global variables and functions
 ***********************************************************************************************************************/
static void gether_phy_preamble(ether_phy_instance_ctrl_t * p_instance_ctrl);
static void gether_phy_reg_set(ether_phy_instance_ctrl_t * p_instance_ctrl, uint32_t reg_addr, int32_t option);
static void gether_phy_reg_read(ether_phy_instance_ctrl_t * p_instance_ctrl, uint32_t * pdata);
static void gether_phy_reg_write(ether_phy_instance_ctrl_t * p_instance_ctrl, uint32_t data);
static void gether_phy_trans_zto0(ether_phy_instance_ctrl_t * p_instance_ctrl);
static void gether_phy_trans_1to0(ether_phy_instance_ctrl_t * p_instance_ctrl);
static void gether_phy_trans_idle(ether_phy_instance_ctrl_t * p_instance_ctrl);
static void gether_phy_mii_write1(ether_phy_instance_ctrl_t * p_instance_ctrl);
static void gether_phy_mii_write0(ether_phy_instance_ctrl_t * p_instance_ctrl);
static void gether_phy_mii_writez(ether_phy_instance_ctrl_t * p_instance_ctrl);
static void gether_phy_targets_initialize(ether_phy_instance_ctrl_t * p_instance_ctrl);
static bool gether_phy_targets_is_support_link_partner_ability(ether_phy_instance_ctrl_t * p_instance_ctrl,
                                                               uint32_t                    line_speed_duplex);

/** GETHER_PHY HAL API mapping for Ethernet PHY Controller interface */
/*LDRA_INSPECTED 27 D This structure must be accessible in user code. It cannot be static. */
const ether_phy_api_t g_ether_phy_on_gether_phy =
{
    .open                  = R_GETHER_PHY_Open,
    .close                 = R_GETHER_PHY_Close,
    .startAutoNegotiate    = R_GETHER_PHY_StartAutoNegotiate,
    .linkPartnerAbilityGet = R_GETHER_PHY_LinkPartnerAbilityGet,
    .linkStatusGet         = R_GETHER_PHY_LinkStatusGet,
    .chipInit              = R_GETHER_PHY_ChipInit,
    .read                  = R_GETHER_PHY_Read,
    .write                 = R_GETHER_PHY_Write
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZA
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZA_GETHER_PHY
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/********************************************************************************************************************//**
 * @brief Resets Ethernet PHY device. Implements @ref ether_phy_api_t::open.
 *
 * @retval  FSP_SUCCESS                             Channel opened successfully.
 * @retval  FSP_ERR_ASSERTION                       Pointer to GETHER_PHY control block or configuration structure is NULL.
 * @retval  FSP_ERR_ALREADY_OPEN                    Control block has already been opened or channel is being used by another
 *                                                  instance. Call close() then open() to reconfigure.
 * @retval  FSP_ERR_INVALID_CHANNEL                 Invalid channel number is given.
 * @retval  FSP_ERR_INVALID_POINTER                 Pointer to p_cfg is NULL.
 * @retval  FSP_ERR_TIMEOUT                         PHY-LSI Reset wait timeout.
 * @retval  FSP_ERR_INVALID_ARGUMENT                Register address is incorrect
 * @retval  FSP_ERR_NOT_INITIALIZED                 The control block has not been initialized.
 ***********************************************************************************************************************/
fsp_err_t R_GETHER_PHY_Open (ether_phy_ctrl_t * const p_ctrl, ether_phy_cfg_t const * const p_cfg)
{
    fsp_err_t err = FSP_SUCCESS;
    ether_phy_instance_ctrl_t * p_instance_ctrl = (ether_phy_instance_ctrl_t *) p_ctrl;
    R_EMAC0_Type              * p_reg_emac;

#if (GETHER_PHY_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GETHER_PHY_ERROR_RETURN(NULL != p_cfg, FSP_ERR_INVALID_POINTER);
    GETHER_PHY_ERROR_RETURN(NULL != p_cfg->p_extend, FSP_ERR_INVALID_POINTER);
    GETHER_PHY_ERROR_RETURN((GETHER_PHY_OPEN != p_instance_ctrl->open), FSP_ERR_ALREADY_OPEN);
    GETHER_PHY_ERROR_RETURN((BSP_FEATURE_GETHER_MAX_CHANNELS > p_cfg->channel), FSP_ERR_INVALID_CHANNEL);
#endif

    /** Make sure this channel exists. */
    ether_phy_instance_extend_t * p_phy_instance_extend = (ether_phy_instance_extend_t *) p_cfg->p_extend;

    p_reg_emac = (R_EMAC0_Type *) p_phy_instance_extend->p_reg_emac;
#if (GETHER_PHY_CFG_PARAM_CHECKING_ENABLE)
    GETHER_PHY_ERROR_RETURN(NULL != p_reg_emac, FSP_ERR_INVALID_POINTER);
#endif
    p_instance_ctrl->p_reg_cxr23     = (uint32_t *) &p_reg_emac->CXR23;
    p_instance_ctrl->local_advertise = 0;

    /* Initialize configuration of ethernet phy module. */
    p_instance_ctrl->p_gether_phy_cfg = p_cfg;

#if GETHER_PHY_CFG_INIT_PHY_LSI_AUTOMATIC
    uint32_t reg   = 0;
    uint32_t count = 0;

    p_instance_ctrl->interface_status = GETHER_PHY_INTERFACE_STATUS_INITIALIZED;

    /* Reset PHY */
    R_GETHER_PHY_Write(p_instance_ctrl, GETHER_PHY_REG_CONTROL, GETHER_PHY_CONTROL_RESET);

    /* Reset completion waiting */
    do
    {
        R_GETHER_PHY_Read(p_instance_ctrl, GETHER_PHY_REG_CONTROL, &reg);
        count++;
    } while ((reg & GETHER_PHY_CONTROL_RESET) && (count < p_cfg->phy_reset_wait_time));

    if (count < p_cfg->phy_reset_wait_time)
    {
        gether_phy_targets_initialize(p_instance_ctrl);

        p_instance_ctrl->open = GETHER_PHY_OPEN;

        err = FSP_SUCCESS;
    }
    else
    {
        err = FSP_ERR_TIMEOUT;
    }

#else
    p_instance_ctrl->open = GETHER_PHY_OPEN;

    err = FSP_SUCCESS;
#endif

    return err;
}                                      /* End of function R_GETHER_PHY_Open() */

/********************************************************************************************************************//**
 * @brief Close Ethernet PHY device. Implements @ref ether_phy_api_t::close.
 *
 * @retval  FSP_SUCCESS                                 Channel successfully closed.
 * @retval  FSP_ERR_ASSERTION                           Pointer to GETHER_PHY control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN                            The control block has not been opened
 *
 ***********************************************************************************************************************/
fsp_err_t R_GETHER_PHY_Close (ether_phy_ctrl_t * const p_ctrl)
{
    fsp_err_t err = FSP_SUCCESS;
    ether_phy_instance_ctrl_t * p_instance_ctrl = (ether_phy_instance_ctrl_t *) p_ctrl;

#if (GETHER_PHY_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GETHER_PHY_ERROR_RETURN(GETHER_PHY_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /** Clear configure block parameters. */
    p_instance_ctrl->p_gether_phy_cfg = NULL;
    p_instance_ctrl->local_advertise  = 0;
    p_instance_ctrl->p_reg_cxr23      = NULL;

    p_instance_ctrl->interface_status = GETHER_PHY_INTERFACE_STATUS_UNINITIALIZED;
    p_instance_ctrl->open             = 0;

    return err;
}                                      /* End of function R_GETHER_PHY_Close() */

/********************************************************************************************************************//**
 * @brief Starts auto-negotiate. Implements @ref ether_phy_api_t::startAutoNegotiate.
 *
 * @retval  FSP_SUCCESS                                 GETHER_PHY successfully starts auto-negotiate.
 * @retval  FSP_ERR_ASSERTION                           Pointer to GETHER_PHY control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN                            The control block has not been opened
 * @retval  FSP_ERR_INVALID_ARGUMENT                    Register address is incorrect
 * @retval  FSP_ERR_INVALID_POINTER                     Pointer to read buffer is NULL.
 * @retval  FSP_ERR_NOT_INITIALIZED                     The control block has not been initialized
 ***********************************************************************************************************************/
fsp_err_t R_GETHER_PHY_StartAutoNegotiate (ether_phy_ctrl_t * const p_ctrl)
{
    ether_phy_instance_ctrl_t * p_instance_ctrl = (ether_phy_instance_ctrl_t *) p_ctrl;
    uint32_t reg = 0;

#if (GETHER_PHY_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GETHER_PHY_ERROR_RETURN(GETHER_PHY_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    GETHER_PHY_ERROR_RETURN(GETHER_PHY_INTERFACE_STATUS_INITIALIZED == p_instance_ctrl->interface_status,
                            FSP_ERR_NOT_INITIALIZED);
#endif

    /* Set local ability */
    /* When pause frame is not used */
    if (ETHER_PHY_FLOW_CONTROL_DISABLE == p_instance_ctrl->p_gether_phy_cfg->flow_control)
    {
        p_instance_ctrl->local_advertise = ((((GETHER_PHY_AN_ADVERTISEMENT_100F |
                                               GETHER_PHY_AN_ADVERTISEMENT_100H) |
                                              GETHER_PHY_AN_ADVERTISEMENT_10F) |
                                             GETHER_PHY_AN_ADVERTISEMENT_10H) |
                                            GETHER_PHY_AN_ADVERTISEMENT_SELECTOR);
    }
    /* When pause frame is used */
    else
    {
        p_instance_ctrl->local_advertise = ((((((GETHER_PHY_AN_ADVERTISEMENT_ASM_DIR |
                                                 GETHER_PHY_AN_ADVERTISEMENT_PAUSE) |
                                                GETHER_PHY_AN_ADVERTISEMENT_100F) |
                                               GETHER_PHY_AN_ADVERTISEMENT_100H) |
                                              GETHER_PHY_AN_ADVERTISEMENT_10F) |
                                             GETHER_PHY_AN_ADVERTISEMENT_10H) |
                                            GETHER_PHY_AN_ADVERTISEMENT_SELECTOR);
    }

    /* Configure what the PHY and the Ethernet controller on this board supports */
    R_GETHER_PHY_Write(p_instance_ctrl, GETHER_PHY_REG_AN_ADVERTISEMENT, p_instance_ctrl->local_advertise);
    R_GETHER_PHY_Write(p_instance_ctrl,
                       GETHER_PHY_REG_CONTROL,
                       (GETHER_PHY_CONTROL_AN_ENABLE |
                        GETHER_PHY_CONTROL_AN_RESTART));

    R_GETHER_PHY_Read(p_instance_ctrl, GETHER_PHY_REG_AN_ADVERTISEMENT, &reg);

    return FSP_SUCCESS;
}                                      /* End of function R_GETHER_PHY_StartAutoNegotiate() */

/********************************************************************************************************************//**
 * @brief Reports the other side's physical capability. Implements @ref ether_phy_api_t::linkPartnerAbilityGet.
 *
 * @retval  FSP_SUCCESS                                 GETHER_PHY successfully get link partner ability.
 * @retval  FSP_ERR_ASSERTION                           Pointer to GETHER_PHY control block is NULL.
 * @retval  FSP_ERR_INVALID_POINTER                     Pointer to arguments are NULL.
 * @retval  FSP_ERR_NOT_OPEN                            The control block has not been opened
 * @retval  FSP_ERR_ETHER_PHY_ERROR_LINK                PHY-LSI is not link up.
 * @retval  FSP_ERR_ETHER_PHY_NOT_READY                 The auto-negotiation isn't completed
 * @retval  FSP_ERR_INVALID_ARGUMENT                    Status register address is incorrect
 * @retval  FSP_ERR_NOT_INITIALIZED                     The control block has not been initialized
 ***********************************************************************************************************************/
fsp_err_t R_GETHER_PHY_LinkPartnerAbilityGet (ether_phy_ctrl_t * const p_ctrl,
                                              uint32_t * const         p_line_speed_duplex,
                                              uint32_t * const         p_local_pause,
                                              uint32_t * const         p_partner_pause)
{
    ether_phy_instance_ctrl_t * p_instance_ctrl = (ether_phy_instance_ctrl_t *) p_ctrl;
    uint32_t reg = 0;

#if (GETHER_PHY_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GETHER_PHY_ERROR_RETURN(GETHER_PHY_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    GETHER_PHY_ERROR_RETURN(NULL != p_line_speed_duplex, FSP_ERR_INVALID_POINTER);
    GETHER_PHY_ERROR_RETURN(NULL != p_local_pause, FSP_ERR_INVALID_POINTER);
    GETHER_PHY_ERROR_RETURN(NULL != p_partner_pause, FSP_ERR_INVALID_POINTER);
    GETHER_PHY_ERROR_RETURN(GETHER_PHY_INTERFACE_STATUS_INITIALIZED == p_instance_ctrl->interface_status,
                            FSP_ERR_NOT_INITIALIZED);
#endif

    /* Because reading the first time shows the previous state, the Link status bit is read twice. */
    R_GETHER_PHY_Read(p_instance_ctrl, GETHER_PHY_REG_STATUS, &reg);
    R_GETHER_PHY_Read(p_instance_ctrl, GETHER_PHY_REG_STATUS, &reg);

    /* When the link isn't up, return error */
    GETHER_PHY_ERROR_RETURN(GETHER_PHY_STATUS_LINK_UP == (reg & GETHER_PHY_STATUS_LINK_UP),
                            FSP_ERR_ETHER_PHY_ERROR_LINK);

    /* Establish local pause capability */
    if (GETHER_PHY_AN_ADVERTISEMENT_PAUSE == (p_instance_ctrl->local_advertise & GETHER_PHY_AN_ADVERTISEMENT_PAUSE))
    {
        (*p_local_pause) |= (1 << 1);
    }

    if (GETHER_PHY_AN_ADVERTISEMENT_ASM_DIR == (p_instance_ctrl->local_advertise & GETHER_PHY_AN_ADVERTISEMENT_ASM_DIR))
    {
        (*p_local_pause) |= 1;
    }

    /* When the auto-negotiation isn't completed, return error */
    GETHER_PHY_ERROR_RETURN(GETHER_PHY_STATUS_AN_COMPLETE == (reg & GETHER_PHY_STATUS_AN_COMPLETE),
                            FSP_ERR_ETHER_PHY_NOT_READY);

    /* Get the link partner response */
    R_GETHER_PHY_Read(p_instance_ctrl, GETHER_PHY_REG_AN_LINK_PARTNER, &reg);

    /* Establish partner pause capability */
    if (GETHER_PHY_AN_LINK_PARTNER_PAUSE == (reg & GETHER_PHY_AN_LINK_PARTNER_PAUSE))
    {
        (*p_partner_pause) = (1 << 1);
    }

    if (GETHER_PHY_AN_LINK_PARTNER_ASM_DIR == (reg & GETHER_PHY_AN_LINK_PARTNER_ASM_DIR))
    {
        (*p_partner_pause) |= 1;
    }

    /* Establish the line speed and the duplex */
    if ((GETHER_PHY_AN_LINK_PARTNER_10H == (reg & GETHER_PHY_AN_LINK_PARTNER_10H)) &&
        gether_phy_targets_is_support_link_partner_ability(p_instance_ctrl, ETHER_PHY_LINK_SPEED_10H))
    {
        (*p_line_speed_duplex) = ETHER_PHY_LINK_SPEED_10H;
    }

    if ((GETHER_PHY_AN_LINK_PARTNER_10F == (reg & GETHER_PHY_AN_LINK_PARTNER_10F)) &&
        gether_phy_targets_is_support_link_partner_ability(p_instance_ctrl, ETHER_PHY_LINK_SPEED_10F))
    {
        (*p_line_speed_duplex) = ETHER_PHY_LINK_SPEED_10F;
    }

    if ((GETHER_PHY_AN_LINK_PARTNER_100H == (reg & GETHER_PHY_AN_LINK_PARTNER_100H)) &&
        gether_phy_targets_is_support_link_partner_ability(p_instance_ctrl, ETHER_PHY_LINK_SPEED_100H))
    {
        (*p_line_speed_duplex) = ETHER_PHY_LINK_SPEED_100H;
    }

    if ((GETHER_PHY_AN_LINK_PARTNER_100F == (reg & GETHER_PHY_AN_LINK_PARTNER_100F)) &&
        gether_phy_targets_is_support_link_partner_ability(p_instance_ctrl, ETHER_PHY_LINK_SPEED_100F))
    {
        (*p_line_speed_duplex) = ETHER_PHY_LINK_SPEED_100F;
    }

#if (ETHER_PHY_CFG_TARGET_KSZ9131RNXI_ENABLE)

    /* Check if the link partner has 1000BASE-T full duplex capability */
    R_GETHER_PHY_Read(p_instance_ctrl, GETHER_PHY_REG_AN_MASTER_SLAVE_STATUS, &reg);
    if (GETHER_PHY_AN_LINK_PARTNER_1000F == (reg & GETHER_PHY_AN_LINK_PARTNER_1000F))
    {
        /* Get the link partner response */
        R_GETHER_PHY_Read(p_instance_ctrl, GETHER_PHY_REG_EXSTATUS, &reg);
        if (GETHER_PHY_EXSTATUS_1000FX == (reg & GETHER_PHY_EXSTATUS_1000FX))
        {
            (*p_line_speed_duplex) = ETHER_PHY_LINK_SPEED_1000F;
        }

        if (GETHER_PHY_EXSTATUS_1000FT == (reg & GETHER_PHY_EXSTATUS_1000FT))
        {
            (*p_line_speed_duplex) = ETHER_PHY_LINK_SPEED_1000F;
        }
    }
#endif

    return FSP_SUCCESS;
}                                      /* End of function R_GETHER_PHY_LinkPartnerAbilityGet() */

/********************************************************************************************************************//**
 * @brief Returns the status of the physical link. Implements @ref ether_phy_api_t::linkStatusGet.
 *
 * @retval  FSP_SUCCESS                                 GETHER_PHY successfully get link partner ability.
 * @retval  FSP_ERR_ASSERTION                           Pointer to GETHER_PHY control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN                            The control block has not been opened
 * @retval  FSP_ERR_ETHER_PHY_ERROR_LINK                PHY-LSI is not link up.
 * @retval  FSP_ERR_INVALID_ARGUMENT                    Status register address is incorrect
 * @retval  FSP_ERR_INVALID_POINTER                     Pointer to read buffer is NULL.
 * @retval  FSP_ERR_NOT_INITIALIZED                     The control block has not been initialized.
 ***********************************************************************************************************************/
fsp_err_t R_GETHER_PHY_LinkStatusGet (ether_phy_ctrl_t * const p_ctrl)
{
    ether_phy_instance_ctrl_t * p_instance_ctrl = (ether_phy_instance_ctrl_t *) p_ctrl;
    uint32_t  reg = 0;
    fsp_err_t err = FSP_SUCCESS;

#if (GETHER_PHY_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GETHER_PHY_ERROR_RETURN(GETHER_PHY_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Because reading the first time shows the previous state, the Link status bit is read twice. */
    R_GETHER_PHY_Read(p_instance_ctrl, GETHER_PHY_REG_STATUS, &reg);
    R_GETHER_PHY_Read(p_instance_ctrl, GETHER_PHY_REG_STATUS, &reg);

    /* When the link isn't up, return error */
    if (GETHER_PHY_STATUS_LINK_UP != (reg & GETHER_PHY_STATUS_LINK_UP))
    {
        /* Link is down */
        err = FSP_ERR_ETHER_PHY_ERROR_LINK;
    }
    else
    {
        /* Link is up */
        err = FSP_SUCCESS;
    }

    return err;
}                                      /* End of function R_GETHER_PHY_LinkStatusGet() */

/********************************************************************************************************************//**
 * @brief Initialize Ethernet PHY device. Implements @ref ether_phy_api_t::chipInit.
 *
 * @retval  FSP_SUCCESS                             PHY device initialized successfully.
 * @retval  FSP_ERR_ASSERTION                       Pointer to GETHER_PHY control block or configuration structure is NULL.
 * @retval  FSP_ERR_INVALID_ARGUMENT                Address or data is not a valid size.
 * @retval  FSP_ERR_INVALID_POINTER                 Pointer to p_cfg is NULL.
 * @retval  FSP_ERR_NOT_INITIALIZED                 The control block has not been initialized.
 * @retval  FSP_ERR_NOT_OPEN                        The control block has not been opened.
 * @retval  FSP_ERR_TIMEOUT                         PHY-LSI Reset wait timeout.
 ***********************************************************************************************************************/
fsp_err_t R_GETHER_PHY_ChipInit (ether_phy_ctrl_t * const p_ctrl, ether_phy_cfg_t const * const p_cfg)
{
    fsp_err_t err = FSP_SUCCESS;
    ether_phy_instance_ctrl_t * p_instance_ctrl = (ether_phy_instance_ctrl_t *) p_ctrl;
    uint32_t reg   = 0;
    uint32_t count = 0;

#if (GETHER_PHY_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GETHER_PHY_ERROR_RETURN(NULL != p_cfg, FSP_ERR_INVALID_POINTER);
    GETHER_PHY_ERROR_RETURN(GETHER_PHY_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_instance_ctrl->interface_status = GETHER_PHY_INTERFACE_STATUS_INITIALIZED;

    /* Reset PHY */
    R_GETHER_PHY_Write(p_instance_ctrl, GETHER_PHY_REG_CONTROL, GETHER_PHY_CONTROL_RESET);

    /* Reset completion waiting */
    do
    {
        R_GETHER_PHY_Read(p_instance_ctrl, GETHER_PHY_REG_CONTROL, &reg);
        count++;
    } while ((reg & GETHER_PHY_CONTROL_RESET) && (count < p_cfg->phy_reset_wait_time));

    if (count < p_cfg->phy_reset_wait_time)
    {
        gether_phy_targets_initialize(p_instance_ctrl);

        err = FSP_SUCCESS;
    }
    else
    {
        err = FSP_ERR_TIMEOUT;
    }

    return err;
}                                      /* End of function R_GETHER_PHY_ChipInit() */

/********************************************************************************************************************//**
 * @brief Read data from register of PHY-LSI . Implements @ref ether_phy_api_t::read.
 *
 * @retval  FSP_SUCCESS                                 GETHER_PHY successfully read data.
 * @retval  FSP_ERR_ASSERTION                           Pointer to GETHER_PHY control block is NULL.
 * @retval  FSP_ERR_INVALID_POINTER                     Pointer to read buffer is NULL.
 * @retval  FSP_ERR_INVALID_ARGUMENT                    Address is not a valid size.
 * @retval  FSP_ERR_NOT_INITIALIZED                     The control block has not been initialized.
 ***********************************************************************************************************************/
fsp_err_t R_GETHER_PHY_Read (ether_phy_ctrl_t * const p_ctrl, uint32_t reg_addr, uint32_t * const p_data)
{
    ether_phy_instance_ctrl_t * p_instance_ctrl = (ether_phy_instance_ctrl_t *) p_ctrl;
    uint32_t data;
#if (GETHER_PHY_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GETHER_PHY_ERROR_RETURN(NULL != p_data, FSP_ERR_INVALID_POINTER);
    GETHER_PHY_ERROR_RETURN(GETHER_PHY_ADDRESS_SIZE >= reg_addr, FSP_ERR_INVALID_ARGUMENT);
    GETHER_PHY_ERROR_RETURN(GETHER_PHY_INTERFACE_STATUS_INITIALIZED == p_instance_ctrl->interface_status,
                            FSP_ERR_NOT_INITIALIZED);
#endif

    /*
     * The value is read from the PHY register by the frame format of MII Management Interface provided
     * for by Table 22-12 of 22.2.4.5 of IEEE 802.3-2008_section2.
     */
    gether_phy_preamble(p_instance_ctrl);
    gether_phy_reg_set(p_instance_ctrl, reg_addr, GETHER_PHY_MII_READ);
    gether_phy_trans_zto0(p_instance_ctrl);
    gether_phy_reg_read(p_instance_ctrl, &data);
    gether_phy_trans_idle(p_instance_ctrl);

    (*p_data) = data;

    return FSP_SUCCESS;
}                                      /* End of function R_GETHER_PHY_Read() */

/********************************************************************************************************************//**
 * @brief Write data to register of PHY-LSI . Implements @ref ether_phy_api_t::write.
 *
 * @retval  FSP_SUCCESS                                 GETHER_PHY successfully write data.
 * @retval  FSP_ERR_ASSERTION                           Pointer to GETHER_PHY control block is NULL.
 * @retval  FSP_ERR_INVALID_ARGUMENT                    Address or data is not a valid size.
 * @retval  FSP_ERR_NOT_INITIALIZED                     The control block has not been initialized.
 ***********************************************************************************************************************/
fsp_err_t R_GETHER_PHY_Write (ether_phy_ctrl_t * const p_ctrl, uint32_t reg_addr, uint32_t data)
{
    ether_phy_instance_ctrl_t * p_instance_ctrl = (ether_phy_instance_ctrl_t *) p_ctrl;

#if (GETHER_PHY_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GETHER_PHY_ERROR_RETURN(GETHER_PHY_ADDRESS_SIZE >= reg_addr, FSP_ERR_INVALID_ARGUMENT);
    GETHER_PHY_ERROR_RETURN(GETHER_PHY_REGISTER_DATA_SIZE >= data, FSP_ERR_INVALID_ARGUMENT);
    GETHER_PHY_ERROR_RETURN(GETHER_PHY_INTERFACE_STATUS_INITIALIZED == p_instance_ctrl->interface_status,
                            FSP_ERR_NOT_INITIALIZED);
#endif

    /*
     * The value is read from the PHY register by the frame format of MII Management Interface provided
     * for by Table 22-12 of 22.2.4.5 of IEEE 802.3-2008_section2.
     */
    gether_phy_preamble(p_instance_ctrl);
    gether_phy_reg_set(p_instance_ctrl, reg_addr, GETHER_PHY_MII_WRITE);
    gether_phy_trans_1to0(p_instance_ctrl);
    gether_phy_reg_write(p_instance_ctrl, data);
    gether_phy_trans_idle(p_instance_ctrl);

    return FSP_SUCCESS;
}                                      /* End of function R_GETHER_PHY_Write() */

/*******************************************************************************************************************//**
 * @} (end addtogroup GETHER_PHY)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/**
 * Private functions
 */

/***********************************************************************************************************************
 * Function Name: phy_preamble
 * Description  : As preliminary preparation for access to the PHY module register,
 *                "1" is output via the MII management interface.
 * Arguments    : gether_channel -
 *                    Ethernet channel number
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_phy_preamble (ether_phy_instance_ctrl_t * p_instance_ctrl)
{
    int16_t i;

    /*
     * The processing of PRE (preamble) about the frame format of MII Management Interface which is
     * provided by "Table 22-12" of "22.2.4.5" of "IEEE 802.3-2008_section2".
     */
    i = GETHER_PHY_PREAMBLE_LENGTH;
    while (i > 0)
    {
        gether_phy_mii_write1(p_instance_ctrl);
        i--;
    }
}                                      /* End of function gether_phy_preamble() */

/***********************************************************************************************************************
 * Function Name: gether_phy_reg_set
 * Description  : Sets a PHY device to read or write mode
 * Arguments    : gether_channel -
 *                    Ethernet channel number
 *                reg_addr -
 *                    address of the PHY register
 *                option -
 *                    mode
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_phy_reg_set (ether_phy_instance_ctrl_t * p_instance_ctrl, uint32_t reg_addr, int32_t option)
{
    int32_t  i;
    uint32_t data = 0;

    /*
     * The processing of ST (start of frame),OP (operation code), PHYAD (PHY Address), and
     * REGAD (Register Address)  about the frame format of MII Management Interface which is
     * provided by "Table 22-12" of "22.2.4.5" of "IEEE 802.3-2008_section2".
     */
    data = (GETHER_PHY_MII_ST << 14);                                             /* ST code    */

    if (GETHER_PHY_MII_READ == option)
    {
        data |= (GETHER_PHY_MII_READ << 12);                                      /* OP code(RD)  */
    }
    else
    {
        data |= (GETHER_PHY_MII_WRITE << 12);                                     /* OP code(WT)  */
    }

    data |= (uint32_t) (p_instance_ctrl->p_gether_phy_cfg->phy_lsi_address << 7); /* PHY Address  */

    data |= (reg_addr << 2);                                                      /* Reg Address  */

    i = 14;
    while (i > 0)
    {
        if (0 == (data & GETHER_PHY_WRITE_DATA_BIT_MASK))
        {
            gether_phy_mii_write0(p_instance_ctrl);
        }
        else
        {
            gether_phy_mii_write1(p_instance_ctrl);
        }

        data = (data << 1);
        i--;
    }
}                                      /* End of function gether_phy_reg_set() */

/***********************************************************************************************************************
 * Function Name: gether_phy_reg_read
 * Description  : Reads PHY register through MII interface
 * Arguments    : p_instance_ctrl -
 *                    Ethernet channel number
 *                pdata -
 *                    pointer to store the data read
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_phy_reg_read (ether_phy_instance_ctrl_t * p_instance_ctrl, uint32_t * pdata)
{
    int32_t  i;
    int32_t  j;
    uint32_t reg_data;

    volatile uint32_t * petherc_cxr23;

    petherc_cxr23 = p_instance_ctrl->p_reg_cxr23;

    /*
     * The processing of DATA (data) about reading of the frame format of MII Management Interface which is
     * provided by "Table 22-12" of "22.2.4.5" of "IEEE 802.3-2008_section2".
     */
    reg_data = 0;
    i        = 16;
    while (i > 0)
    {
        for (j = p_instance_ctrl->p_gether_phy_cfg->mii_bit_access_wait_time; j > 0; j--)
        {
            (*petherc_cxr23) = (GETHER_PHY_CXR23_MDO_LOW | GETHER_PHY_CXR23_MMD_READ | GETHER_PHY_CXR23_MDC_LOW);
        }

        reg_data  = (reg_data << 1);
        reg_data |= (uint32_t) (((*petherc_cxr23) & GETHER_PHY_CXR23_MDI_MASK) >> 3); /* MDI read  */

        for (j = p_instance_ctrl->p_gether_phy_cfg->mii_bit_access_wait_time; j > 0; j--)
        {
            (*petherc_cxr23) = (GETHER_PHY_CXR23_MDO_LOW | GETHER_PHY_CXR23_MMD_READ | GETHER_PHY_CXR23_MDC_HIGH);
        }

        for (j = p_instance_ctrl->p_gether_phy_cfg->mii_bit_access_wait_time; j > 0; j--)
        {
            (*petherc_cxr23) = (GETHER_PHY_CXR23_MDO_LOW | GETHER_PHY_CXR23_MMD_READ | GETHER_PHY_CXR23_MDC_HIGH);
        }

        for (j = p_instance_ctrl->p_gether_phy_cfg->mii_bit_access_wait_time; j > 0; j--)
        {
            (*petherc_cxr23) = (GETHER_PHY_CXR23_MDO_LOW | GETHER_PHY_CXR23_MMD_READ | GETHER_PHY_CXR23_MDC_LOW);
        }

        i--;
    }

    (*pdata) = reg_data;
}                                      /* End of function gether_phy_reg_read() */

/***********************************************************************************************************************
 * Function Name: gether_phy_reg_write
 * Description  : Writes to PHY register through MII interface
 * Arguments    : gether_channel -
 *                    Ethernet channel number
 *                data -
 *                    value to write
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_phy_reg_write (ether_phy_instance_ctrl_t * p_instance_ctrl, uint32_t data)
{
    int32_t i;

    /*
     * The processing of DATA (data) about writing of the frame format of MII Management Interface which is
     * provided by "Table 22-12" of "22.2.4.5" of "IEEE 802.3-2008_section2".
     */
    i = 16;
    while (i > 0)
    {
        if (0 == (data & GETHER_PHY_WRITE_DATA_BIT_MASK))
        {
            gether_phy_mii_write0(p_instance_ctrl);
        }
        else
        {
            gether_phy_mii_write1(p_instance_ctrl);
        }

        i--;
        data = (data << 1);
    }
}                                      /* End of function gether_phy_reg_write() */

/***********************************************************************************************************************
 * Function Name: gether_phy_trans_zto0
 * Description  : Performs bus release so that PHY can drive data
 *              : for read operation
 * Arguments    : gether_channel -
 *                    Ethernet channel number
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_phy_trans_zto0 (ether_phy_instance_ctrl_t * p_instance_ctrl)
{
    /* Release the bus by writing z. */
    gether_phy_mii_writez(p_instance_ctrl);

    /* The PHY will drive the bus to 0. */
    gether_phy_mii_writez(p_instance_ctrl);
}                                      /* End of function gether_phy_trans_zto0() */

/***********************************************************************************************************************
 * Function Name: phy_trans_1to0
 * Description  : Switches data bus so MII interface can drive data
 *              : for write operation
 * Arguments    : gether_channel -
 *                    Ethernet channel number
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_phy_trans_1to0 (ether_phy_instance_ctrl_t * p_instance_ctrl)
{
    /*A (t
     * The processing of Turnaround) about writing of the frame format of MII Management Interface which is
     * provided by "Table 22-12" of "22.2.4.5" of "IEEE 802.3-2008_section2".
     */
    gether_phy_mii_write1(p_instance_ctrl);
    gether_phy_mii_write0(p_instance_ctrl);
}                                      /* End of function gether_phy_trans_1to0() */

/***********************************************************************************************************************
 * Function Name: gether_phy_trans_idle
 * Description  : Switches data bus to IDLE state to prepare for the next transfer.
 * Arguments    : ether_channel -
 *                    Ethernet channel number
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_phy_trans_idle (ether_phy_instance_ctrl_t * p_instance_ctrl)
{
    volatile uint32_t * petherc_pir;

    petherc_pir = p_instance_ctrl->p_reg_cxr23;

    int64_t count = (int64_t) p_instance_ctrl->p_gether_phy_cfg->mii_bit_access_wait_time * 4;

    /* Release the bus for one MDC period. */
    for (int64_t j = count; j > 0; j--)
    {
        (*petherc_pir) = (GETHER_PHY_CXR23_MDO_LOW | GETHER_PHY_CXR23_MMD_READ | GETHER_PHY_CXR23_MDC_LOW);
    }
}

/***********************************************************************************************************************
 * Function Name: gether_phy_mii_write1
 * Description  : Outputs 1 to the MII interface
 * Arguments    : gether_channel -
 *                    Ethernet channel number
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_phy_mii_write1 (ether_phy_instance_ctrl_t * p_instance_ctrl)
{
    int32_t             j;
    volatile uint32_t * petherc_cxr23;

    petherc_cxr23 = p_instance_ctrl->p_reg_cxr23;

    /*
     * The processing of one bit about frame format of MII Management Interface which is
     * provided by "Table 22-12" of "22.2.4.5" of "IEEE 802.3-2008_section2".
     * The data that 1 is output.
     */
    for (j = p_instance_ctrl->p_gether_phy_cfg->mii_bit_access_wait_time; j > 0; j--)
    {
        (*petherc_cxr23) = (GETHER_PHY_CXR23_MDO_HIGH | GETHER_PHY_CXR23_MMD_WRITE | GETHER_PHY_CXR23_MDC_LOW);
    }

    for (j = p_instance_ctrl->p_gether_phy_cfg->mii_bit_access_wait_time; j > 0; j--)
    {
        (*petherc_cxr23) = (GETHER_PHY_CXR23_MDO_HIGH | GETHER_PHY_CXR23_MMD_WRITE | GETHER_PHY_CXR23_MDC_HIGH);
    }

    for (j = p_instance_ctrl->p_gether_phy_cfg->mii_bit_access_wait_time; j > 0; j--)
    {
        (*petherc_cxr23) = (GETHER_PHY_CXR23_MDO_HIGH | GETHER_PHY_CXR23_MMD_WRITE | GETHER_PHY_CXR23_MDC_HIGH);
    }

    for (j = p_instance_ctrl->p_gether_phy_cfg->mii_bit_access_wait_time; j > 0; j--)
    {
        (*petherc_cxr23) = (GETHER_PHY_CXR23_MDO_HIGH | GETHER_PHY_CXR23_MMD_WRITE | GETHER_PHY_CXR23_MDC_LOW);
    }
}                                      /* End of function gether_phy_mii_write1() */

/***********************************************************************************************************************
 * Function Name: gether_phy_mii_write0
 * Description  : Outputs 0 to the MII interface
 * Arguments    : gether_channel -
 *                    Ethernet channel number
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_phy_mii_write0 (ether_phy_instance_ctrl_t * p_instance_ctrl)
{
    int32_t             j;
    volatile uint32_t * petherc_cxr23;

    petherc_cxr23 = p_instance_ctrl->p_reg_cxr23;

    /*
     * The processing of one bit about frame format of MII Management Interface which is
     * provided by "Table 22-12" of "22.2.4.5" of "IEEE 802.3-2008_section2".
     * The data that 0 is output.
     */
    for (j = p_instance_ctrl->p_gether_phy_cfg->mii_bit_access_wait_time; j > 0; j--)
    {
        (*petherc_cxr23) = (GETHER_PHY_CXR23_MDO_LOW | GETHER_PHY_CXR23_MMD_WRITE | GETHER_PHY_CXR23_MDC_LOW);
    }

    for (j = p_instance_ctrl->p_gether_phy_cfg->mii_bit_access_wait_time; j > 0; j--)
    {
        (*petherc_cxr23) = (GETHER_PHY_CXR23_MDO_LOW | GETHER_PHY_CXR23_MMD_WRITE | GETHER_PHY_CXR23_MDC_HIGH);
    }

    for (j = p_instance_ctrl->p_gether_phy_cfg->mii_bit_access_wait_time; j > 0; j--)
    {
        (*petherc_cxr23) = (GETHER_PHY_CXR23_MDO_LOW | GETHER_PHY_CXR23_MMD_WRITE | GETHER_PHY_CXR23_MDC_HIGH);
    }

    for (j = p_instance_ctrl->p_gether_phy_cfg->mii_bit_access_wait_time; j > 0; j--)
    {
        (*petherc_cxr23) = (GETHER_PHY_CXR23_MDO_LOW | GETHER_PHY_CXR23_MMD_WRITE | GETHER_PHY_CXR23_MDC_LOW);
    }
}                                      /* End of function gether_phy_mii_write0() */

/***********************************************************************************************************************
 * Function Name: gether_phy_mii_writez
 * Description  : Outputs z to the MII interface
 * Arguments    : ether_channel -
 *                    Ethernet channel number
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_phy_mii_writez (ether_phy_instance_ctrl_t * p_instance_ctrl)
{
    int32_t j;

    volatile uint32_t * petherc_pir;

    petherc_pir = p_instance_ctrl->p_reg_cxr23;

    for (j = p_instance_ctrl->p_gether_phy_cfg->mii_bit_access_wait_time; j > 0; j--)
    {
        (*petherc_pir) = (GETHER_PHY_CXR23_MDO_LOW | GETHER_PHY_CXR23_MMD_READ | GETHER_PHY_CXR23_MDC_LOW);
    }

    for (j = p_instance_ctrl->p_gether_phy_cfg->mii_bit_access_wait_time; j > 0; j--)
    {
        (*petherc_pir) = (GETHER_PHY_CXR23_MDO_LOW | GETHER_PHY_CXR23_MMD_READ | GETHER_PHY_CXR23_MDC_HIGH);
    }

    for (j = p_instance_ctrl->p_gether_phy_cfg->mii_bit_access_wait_time; j > 0; j--)
    {
        (*petherc_pir) = (GETHER_PHY_CXR23_MDO_LOW | GETHER_PHY_CXR23_MMD_READ | GETHER_PHY_CXR23_MDC_HIGH);
    }

    for (j = p_instance_ctrl->p_gether_phy_cfg->mii_bit_access_wait_time; j > 0; j--)
    {
        (*petherc_pir) = (GETHER_PHY_CXR23_MDO_LOW | GETHER_PHY_CXR23_MMD_READ | GETHER_PHY_CXR23_MDC_LOW);
    }
}

/***********************************************************************************************************************
 * Function Name: gether_phy_targets_initialize
 * Description  : PHY-LSI specific initialization processing
 * Arguments    : p_instance_ctrl -
 *                    Ethernet control block
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_phy_targets_initialize (ether_phy_instance_ctrl_t * p_instance_ctrl)
{
    switch (p_instance_ctrl->p_gether_phy_cfg->phy_lsi_type)
    {
        /* Use KSZ9131RNXI */
#if (ETHER_PHY_CFG_TARGET_KSZ9131RNXI_ENABLE)
        case ETHER_PHY_LSI_TYPE_KSZ9131RNXI:
        {
            gether_phy_targets_ksz9131rnxi_initialize(p_instance_ctrl);
            break;
        }
#endif

        /* User custom */
#if (GETHER_PHY_CFG_USE_CUSTOM_PHY_LSI_ENABLE)
        case ETHER_PHY_LSI_TYPE_CUSTOM:
        {
            if (NULL != p_instance_ctrl->p_gether_phy_cfg->p_extend)
            {
                ether_phy_instance_extend_t const * p_callback = p_instance_ctrl->p_gether_phy_cfg->p_extend;
                if (NULL != p_callback->p_target_init)
                {
                    p_callback->p_target_init(p_instance_ctrl);
                }
            }

            break;
        }
#endif

        /* If module is configured for default LSI */
        default:
        {
            break;
        }
    }
}                                      /* End of function ether_phy_targets_initialize() */

/***********************************************************************************************************************
 * Function Name: gether_phy_targets_is_support_link_partner_ability
 * Description  : Check if the PHY-LSI connected Ethernet controller supports link ability
 * Arguments    : p_instance_ctrl -
 *                    Ethernet control block
 *                line_speed_duplex -
 *                    Line speed duplex of link partner PHY-LSI
 * Return Value : bool
 ***********************************************************************************************************************/
static bool gether_phy_targets_is_support_link_partner_ability (ether_phy_instance_ctrl_t * p_instance_ctrl,
                                                                uint32_t                    line_speed_duplex)
{
    bool result = false;
    FSP_PARAMETER_NOT_USED(line_speed_duplex);
    switch (p_instance_ctrl->p_gether_phy_cfg->phy_lsi_type)
    {
        /* Use KSZ8091RNB */
#if (ETHER_PHY_CFG_TARGET_KSZ9131RNXI_ENABLE)
        case ETHER_PHY_LSI_TYPE_KSZ9131RNXI:
        {
            result = gether_phy_target_ksz9131rnxi_is_support_link_partner_ability(p_instance_ctrl, line_speed_duplex);
            break;
        }
#endif

/* User custom */
#if (GETHER_PHY_CFG_USE_CUSTOM_PHY_LSI_ENABLE)
        case ETHER_PHY_LSI_TYPE_CUSTOM:
        {
            if (NULL != p_instance_ctrl->p_gether_phy_cfg->p_extend)
            {
                ether_phy_instance_extend_t const * p_callback = p_instance_ctrl->p_gether_phy_cfg->p_extend;
                if (NULL != p_callback->p_target_link_partner_ability_get)
                {
                    result = p_callback->p_target_link_partner_ability_get(p_instance_ctrl, line_speed_duplex);
                }
            }

            break;
        }
#endif

        /* If module is configured for default LSI, always return true */
        default:
        {
            result = true;
            break;
        }
    }

    return result;
}                                      /* End of function ether_phy_targets_is_support_link_partner_ability() */
