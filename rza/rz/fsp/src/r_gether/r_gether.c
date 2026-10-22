/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/
#include <string.h>
#include "bsp_api.h"
#include "r_gether.h"
#include "r_gether_phy.h"
#include "hal_data.h"

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/
#ifndef GETHER_ERROR_RETURN

 #define GETHER_ERROR_RETURN(a, err)    FSP_ERROR_RETURN((a), (err))
#endif

#define GETHER_ETHERC_REG_SIZE                           (0x10000UL)
#define GETHER_ETHERC_EDMAC_REG_SIZE                     (0x10000UL)
#define GETHER_NUMBER_OF_INTERRUPT                       (0x3UL)

#define GETHER_ETHERC_INITIALIZATION_WAIT_CYCLE          (0x64UL)

/** "ETHE" in ASCII.  Used to determine if the control block is open. */
#define GETHER_OPEN                                      (0x45544845U)

/* Definition of the maximum buffer size */
#define GETHER_RCV_BUFF_MAX                              (8192)

/* Definition of the maximum / minimum number of data that can be sent at one time in the Ethernet */
#define GETHER_MAXIMUM_FRAME_SIZE                        (1514U) /* Maximum number of transmitted data */
#define GETHER_MINIMUM_FRAME_SIZE                        (60U)   /* Minimum number of transmitted data */

/* Definition of the maximum padding offset */
#define GETHER_MAXIMUM_PADDING_OFFSET                    (63U)

/* Bit definition of Ethernet interrupt factor*/
#define GETHER_ETHERC_INTERRUPT_FACTOR_ALL               (0x00000037UL)

#define GETHER_ETHERC_INTERRUPT_FACTOR_LCHNG             (1UL << 2)
#define GETHER_ETHERC_INTERRUPT_FACTOR_MPD               (1UL << 1)

/* Bit definition of Ethernet interrupt enable */
#define GETHER_ETHERC_INTERRUPT_ENABLE_LCHNG             (1UL << 2)
#define GETHER_ETHERC_INTERRUPT_ENABLE_MPD               (1UL << 1)

#define GETHER_ETHERC_INTERRUPT_FR                       (18)
#define GETHER_ETHERC_INTERRUPT_RDE                      (16)
#define GETHER_ETHERC_INTERRUPT_RFOF                     (17)
#define GETHER_ETHERC_INTERRUPT_TC                       (21)

/* Macro definitions of ETHERC/EDMAC configurations */
#define GETHER_ETHERC_ECMR_MODE_CLEAR                    (0x00000000UL)
#define GETHER_ETHERC_CXR2A_DEFAULT_VALUE                (1518U)
#define GETHER_ETHERC_IPGR_DEFAULT_VALUE                 (0x00000014UL)
#define GETHER_ETHERC_APR_MAXIMUM_VALUE                  (0x0000FFFFUL)
#define GETHER_ETHERC_FCFTR_MINIMUM_VALUE                (0x00000000UL)
#define GETHER_RCR_DEFAULT_VALUE                         (0x60000000UL)
#define GETHER_TGC_DEFAULT_VALUE                         (0x00222200UL)
#define GETHER_RTC_FIXED_BITS                            (0x7ffc0000UL)
#define GETHER_ETHERC_CXR2C_DEFAULT_VALUE                (0x00000000UL) /* LINKSTA = low active, INT = low active */
#define GETHER_ETHERC_CXR35_RGMII_VALUE                  (0x03E80000UL)
#define GETHER_ETHERC_CXR35_MII_VALUE                    (0x03E80002UL)

/* Number of entries in PAUSE resolution table */
#define GETHER_PAUSE_TABLE_ENTRIES                       (8)

/* Local device and link partner PAUSE settings */
#define GETHER_PAUSE_XMIT_OFF                            (0)      /* The pause frame transmission is prohibited. */
#define GETHER_PAUSE_RECV_OFF                            (0)      /* The pause frame reception is prohibited.    */
#define GETHER_PAUSE_XMIT_ON                             (1)      /* The pause frame transmission is permitted.  */
#define GETHER_PAUSE_RECV_ON                             (1)      /* The pause frame reception is permitted.     */

/* Macro definition for buffer alignment adjustment */
#define GETHER_BUFFER_32BYTE_ALIGNMENT_MASK              (0x1FUL) /* Mask for checking whether or not 32-bit alignment. */

#define GETHER_CXR2D_SPEED_10MBPS                        (0UL)
#define GETHER_CXR2D_SPEED_100MBPS                       (1UL)
#define GETHER_CXR2D_SPEED_1000MBPS                      (2UL)

#define GETHER_BASE_DESCRIPTOR_TX_OFFSET                 (0UL)
#define GETHER_BASE_DESCRIPTOR_RX_OFFSET                 (4UL)
#define GETHER_NUMBER_OF_BASE_DESCRIPTOR                 (6UL)

#define GETHER_DECRIPTOR_INT_TX                          (1U)
#define GETHER_DECRIPTOR_INT_RX                          (2U)

#define GETHER_DECRIPTOR_MAX_ADDRESS                     (0x0000000400000000ULL)

/* PAUSE link mask and shift values */

/*
 * The mask value and shift value which are for that shift the bits form a line and
 * for comparing the bit information of PAUSE function which support the local device and
 * Link partner with the assorted table(pause_resolution) which enable or disable the PAUSE frame.
 */
#define GETHER_LINK_RESOLUTION_ABILITY_MASK              (3)
#define GETHER_LINK_RESOLUTION_LOCAL_ABILITY_BITSHIFT    (2)

/* Etherc mode */
#define GETHER_NO_USE_MAGIC_PACKET_DETECT                (0)
#define GETHER_USE_MAGIC_PACKET_DETECT                   (1)

/* GETHER_NO_DATA is the return value that indicates that no received data. */
#define GETHER_NO_DATA                                   (0)

#define GETHER_OPC_MODE_RESET                            (0UL)
#define GETHER_OPC_MODE_CONFIG                           (1UL)
#define GETHER_OPC_MODE_OPERATION                        (2UL)

#define GETHER_ADDRESS_UPPER_BITS_MASK                   (0xFFFFFFFF00000000ULL)
#define GETHER_ADDRESS_4BYTE_MASK                        (0xFFFFFFFFFFFFFFFCULL)

#define GETHER_MASK_10BITS                               (0x3FFU)
#define GETHER_MASK_12BITS                               (0xFFFU)

#define GETHER_ALIGN_128                                 __attribute__((__aligned__(128)))

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
typedef void (BSP_CMSE_NONSECURE_CALL * ether_prv_ns_callback)(ether_callback_args_t * p_args);
#elif defined(__GNUC__)
typedef BSP_CMSE_NONSECURE_CALL void (*volatile ether_prv_ns_callback)(ether_callback_args_t * p_args);
#endif

typedef uint64_t address_size_t;

/*
 * PauseMaskE, PauseValE and pause_resolutionS are use to create
 * PAUSE resolution Table 28B-3 in IEEE 802.3-2008 standard.
 */
typedef enum e_gether_pause_mask
{
    GETHER_PAUSE_MASK0,
    GETHER_PAUSE_MASK1,
    GETHER_PAUSE_MASK2,
    GETHER_PAUSE_MASK3,
    GETHER_PAUSE_MASK4,
    GETHER_PAUSE_MASK5,
    GETHER_PAUSE_MASK6,
    GETHER_PAUSE_MASK7,
    GETHER_PAUSE_MASK8,
    GETHER_PAUSE_MASK9,
    GETHER_PAUSE_MASKA,
    GETHER_PAUSE_MASKB,
    GETHER_PAUSE_MASKC,
    GETHER_PAUSE_MASKD,
    GETHER_PAUSE_MASKE,
    GETHER_PAUSE_MASKF
} gether_pause_mask_t;

typedef enum e_gether_pause_val
{
    GETHER_PAUSE_VAL0,
    GETHER_PAUSE_VAL1,
    GETHER_PAUSE_VAL2,
    GETHER_PAUSE_VAL3,
    GETHER_PAUSE_VAL4,
    GETHER_PAUSE_VAL5,
    GETHER_PAUSE_VAL6,
    GETHER_PAUSE_VAL7,
    GETHER_PAUSE_VAL8,
    GETHER_PAUSE_VAL9,
    GETHER_PAUSE_VALA,
    GETHER_PAUSE_VALB,
    GETHER_PAUSE_VALC,
    GETHER_PAUSE_VALD,
    GETHER_PAUSE_VALE,
    GETHER_PAUSE_VALF
} gether_pause_val_t;

typedef struct st_gether_pause_resolution
{
    gether_pause_mask_t mask;
    gether_pause_val_t  value;
    uint8_t             transmit;
    uint8_t             receive;
} gether_pause_resolution_t;

typedef struct st_gether_basic_descriptor
{
    volatile uint32_t                 ds  : 12; /* Descriptor size */
    volatile uint32_t                 cc  : 12; /* Content control MSBs (reserved) */
    volatile uint32_t                 die : 4;  /* Descriptor interrupt enable */
    volatile gether_descriptor_type_t dt  : 4;  /* Descriptor type */
    volatile uint32_t                 dptr;     /* Descriptor pointer */
} gether_basic_descriptor_t;

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 ***********************************************************************************************************************/
void gether_eint_isr(IRQn_Type const irq);

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
#if (GETHER_CFG_PARAM_CHECKING_ENABLE)
static fsp_err_t gether_open_param_check(ether_instance_ctrl_t const * const p_instance_ctrl,
                                         ether_cfg_t const * const           p_cfg);

#endif

static void gether_enable_icu(ether_instance_ctrl_t * const p_instance_ctrl);
static void gether_disable_icu(ether_instance_ctrl_t * const p_instance_ctrl);
static void gether_reset_mac(R_ETHER0_Type * const p_reg);
static void gether_init_descriptors(ether_instance_ctrl_t * const p_instance_ctrl);
static void gether_init_buffers(ether_instance_ctrl_t * const p_instance_ctrl);
static void gether_config_ethernet(ether_instance_ctrl_t const * const p_instance_ctrl, const uint8_t mode);
static void gether_pause_resolution(uint32_t const local_ability,
                                    uint32_t const partner_ability,
                                    uint32_t     * ptx_pause,
                                    uint32_t     * prx_pause);
static void gether_configure_mac(ether_instance_ctrl_t * const p_instance_ctrl,
                                 const uint8_t                 mac_addr[],
                                 const uint8_t                 mode);
static fsp_err_t gether_do_link(ether_instance_ctrl_t * const p_instance_ctrl, const uint8_t mode);
static fsp_err_t gether_link_status_check(ether_instance_ctrl_t const * const p_instance_ctrl);
static uint8_t   gether_check_magic_packet_detection_bit(ether_instance_ctrl_t const * const p_instance_ctrl);
static void      ether_call_callback(ether_instance_ctrl_t * p_instance_ctrl, ether_callback_args_t * p_callback_args);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/** Name of module used by error logger macro */
#if BSP_CFG_ERROR_LOG != 0
static const char g_module_name[] = "gether";
#endif

#if defined(__GNUC__)

/* This structure is affected by warnings from a GCC compiler bug. This pragma suppresses the warnings in this
 * structure only.*/

 #pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

/** ETHER HAL API mapping for Ethernet Controller interface. */
const ether_api_t g_ether_on_gether =
{
    .open            = R_GETHER_Open,
    .close           = R_GETHER_Close,
    .read            = R_GETHER_Read,
    .bufferRelease   = R_GETHER_BufferRelease,
    .rxBufferUpdate  = R_GETHER_RxBufferUpdate,
    .write           = R_GETHER_Write,
    .linkProcess     = R_GETHER_LinkProcess,
    .wakeOnLANEnable = R_GETHER_WakeOnLANEnable,
    .txStatusGet     = R_GETHER_TxStatusGet,
    .callbackSet     = R_GETHER_CallbackSet,
};

/*
 * PAUSE Resolution as documented in IEEE 802.3-2008_section2 Annex
 * 28B, Table 28B-3. The following table codify logic that
 * determines how the PAUSE is configured for local transmitter
 * and receiver and partner transmitter and receiver.
 */
static const gether_pause_resolution_t pause_resolution[GETHER_PAUSE_TABLE_ENTRIES] =
{
    {GETHER_PAUSE_MASKC, GETHER_PAUSE_VAL0, GETHER_PAUSE_XMIT_OFF, GETHER_PAUSE_RECV_OFF  },
    {GETHER_PAUSE_MASKE, GETHER_PAUSE_VAL4, GETHER_PAUSE_XMIT_OFF, GETHER_PAUSE_RECV_OFF  },
    {GETHER_PAUSE_MASKF, GETHER_PAUSE_VAL6, GETHER_PAUSE_XMIT_OFF, GETHER_PAUSE_RECV_OFF  },
    {GETHER_PAUSE_MASKF, GETHER_PAUSE_VAL7, GETHER_PAUSE_XMIT_ON,  GETHER_PAUSE_RECV_OFF  },
    {GETHER_PAUSE_MASKE, GETHER_PAUSE_VAL8, GETHER_PAUSE_XMIT_OFF, GETHER_PAUSE_RECV_OFF  },
    {GETHER_PAUSE_MASKA, GETHER_PAUSE_VALA, GETHER_PAUSE_XMIT_ON,  GETHER_PAUSE_RECV_ON   },
    {GETHER_PAUSE_MASKF, GETHER_PAUSE_VALC, GETHER_PAUSE_XMIT_OFF, GETHER_PAUSE_RECV_OFF  },
    {GETHER_PAUSE_MASKF, GETHER_PAUSE_VALD, GETHER_PAUSE_XMIT_OFF, GETHER_PAUSE_RECV_ON   }
};

static gether_basic_descriptor_t g_gether_basic_descriptors[
    BSP_FEATURE_GETHER_MAX_CHANNELS][GETHER_NUMBER_OF_BASE_DESCRIPTOR] ETHER_BUFFER_PLACE_IN_SECTION GETHER_ALIGN_128;

static uint32_t tag_counter = 0;

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZA
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZA_GETHER
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/********************************************************************************************************************//**
 * @brief After ETHERC, EDMAC and PHY-LSI are reset in software, an auto negotiation of PHY-LSI is begun.
 * Afterwards, the link signal change interrupt is permitted. Implements @ref RZA::ether_api_t::open.
 *
 * @retval  FSP_SUCCESS                             Channel opened successfully.
 * @retval  FSP_ERR_ASSERTION                       Pointer to ETHER control block or configuration structure is NULL.
 * @retval  FSP_ERR_ALREADY_OPEN                    Control block has already been opened or channel is being used by another
 *                                                  instance. Call close() then open() to reconfigure.
 * @retval  FSP_ERR_ETHER_ERROR_PHY_COMMUNICATION   Initialization of PHY-LSI failed.
 * @retval  FSP_ERR_INVALID_CHANNEL                 Invalid channel number is given.
 * @retval  FSP_ERR_INVALID_POINTER                 Pointer to MAC address is NULL.
 * @retval  FSP_ERR_INVALID_ARGUMENT                Interrupt is not enabled.
 * @retval  FSP_ERR_ETHER_PHY_ERROR_LINK            Initialization of PHY-LSI failed.
 ***********************************************************************************************************************/
fsp_err_t R_GETHER_Open (ether_ctrl_t * const p_ctrl, ether_cfg_t const * const p_cfg)
{
    fsp_err_t                     err             = FSP_SUCCESS;
    ether_instance_ctrl_t       * p_instance_ctrl = (ether_instance_ctrl_t *) p_ctrl;
    ether_phy_instance_extend_t * p_phy_instance_extend;
    R_EMAC0_Type                * p_reg_emac;
    bsp_ethernet_channel_t        ioprt_ch = BSP_ETHERNET_CHANNEL_0;

    fsp_err_t phy_ret;

#if (GETHER_CFG_PARAM_CHECKING_ENABLE)

    /** Check parameters. */
    err = gether_open_param_check(p_instance_ctrl, p_cfg); /** check arguments */
    GETHER_ERROR_RETURN((FSP_SUCCESS == err), err);
#endif
    ether_instance_extend_t * p_ether_instance_extend = (ether_instance_extend_t *) p_cfg->p_extend;
#if (GETHER_CFG_PARAM_CHECKING_ENABLE)
    GETHER_ERROR_RETURN((NULL != p_ether_instance_extend->p_reg_emac), FSP_ERR_INVALID_POINTER);
    GETHER_ERROR_RETURN((NULL != p_ether_instance_extend->p_reg_ether), FSP_ERR_INVALID_POINTER);
    GETHER_ERROR_RETURN((NULL != p_ether_instance_extend->p_reg_toe), FSP_ERR_INVALID_POINTER);
#endif

    /* Prevent ether from resetting the linking process if it has already opened, even if the parameter-checking
     * function is disabled. */
    GETHER_ERROR_RETURN((GETHER_OPEN != p_instance_ctrl->open), FSP_ERR_ALREADY_OPEN);

    /** Make sure this channel exists. */
    p_instance_ctrl->p_reg_emac  = (R_EMAC0_Type *) p_ether_instance_extend->p_reg_emac;
    p_instance_ctrl->p_reg_ether = (R_ETHER0_Type *) p_ether_instance_extend->p_reg_ether;
    p_instance_ctrl->p_reg_toe   = (R_TOE0_Type *) p_ether_instance_extend->p_reg_toe;

    p_reg_emac = p_instance_ctrl->p_reg_emac;

    if (p_cfg->channel == 1)
    {
        ioprt_ch = BSP_ETHERNET_CHANNEL_1;
    }

    /** GPIO settings */
    p_phy_instance_extend = (ether_phy_instance_extend_t *) p_cfg->p_ether_phy_instance->p_cfg->p_extend;
    if (p_phy_instance_extend->voltage == ETHER_PHY_VOLTAGE_33)
    {
        R_BSP_EthernetVoltageModeCfg(ioprt_ch, BSP_ETHERNET_VOLTAGE_33);
    }
    else if (p_phy_instance_extend->voltage == ETHER_PHY_VOLTAGE_25)
    {
        R_BSP_EthernetVoltageModeCfg(ioprt_ch, BSP_ETHERNET_VOLTAGE_25);
    }
    else if (p_phy_instance_extend->voltage == ETHER_PHY_VOLTAGE_18)
    {
        R_BSP_EthernetVoltageModeCfg(ioprt_ch, BSP_ETHERNET_VOLTAGE_18);
    }
    else
    {
        FSP_ERROR_RETURN(0, FSP_ERR_INVALID_ARGUMENT);
    }

    if (p_cfg->p_ether_phy_instance->p_cfg->mii_type == ETHER_PHY_MII_TYPE_RGMII)
    {
        R_BSP_EthernetModeCfg(ioprt_ch, BSP_ETHERNET_MODE_RGMII);
    }
    else if (p_cfg->p_ether_phy_instance->p_cfg->mii_type == ETHER_PHY_MII_TYPE_MII)
    {
        R_BSP_EthernetModeCfg(ioprt_ch, BSP_ETHERNET_MODE_MII);
    }
    else
    {
        FSP_ERROR_RETURN(0, FSP_ERR_INVALID_ARGUMENT);
    }

    /* Initialize configuration of Ethernet module. */
    p_instance_ctrl->p_gether_cfg = p_cfg;

    /* Initialize the flags */
    p_instance_ctrl->link_establish_status = GETHER_LINK_ESTABLISH_STATUS_DOWN;
    p_instance_ctrl->link_change           = GETHER_LINK_CHANGE_NO_CHANGE;
    p_instance_ctrl->previous_link_status  = GETHER_PREVIOUS_LINK_STATUS_DOWN;

    /* register interrupt */
    R_FSP_IsrContextSet(p_instance_ctrl->p_gether_cfg->irq, gether_eint_isr);

    /* Set callback and context pointers, if configured */
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    R_BSP_MODULE_START(FSP_IP_ETHER, p_instance_ctrl->p_gether_cfg->channel);

    /* Initialize the Ethernet buffer */
    gether_init_buffers(p_instance_ctrl);

    /* Software reset */
    gether_reset_mac(p_instance_ctrl->p_reg_ether);

    /* Software reset the PHY */
    phy_ret = p_instance_ctrl->p_gether_cfg->p_ether_phy_instance->p_api->open(
        p_instance_ctrl->p_gether_cfg->p_ether_phy_instance->p_ctrl,
        p_instance_ctrl->p_gether_cfg->p_ether_phy_instance->p_cfg);
    GETHER_ERROR_RETURN((FSP_SUCCESS == phy_ret), phy_ret);

#if !GETHER_PHY_CFG_INIT_PHY_LSI_AUTOMATIC

    /* Initialize the PHY */
    if (FSP_SUCCESS == phy_ret)
    {
        phy_ret = p_instance_ctrl->p_gether_cfg->p_ether_phy_instance->p_api->chipInit(
            p_instance_ctrl->p_gether_cfg->p_ether_phy_instance->p_ctrl,
            p_instance_ctrl->p_gether_cfg->p_ether_phy_instance->p_cfg);
    }
#endif

    if (FSP_SUCCESS == phy_ret)
    {
        if (p_cfg->p_ether_phy_instance->p_cfg->mii_type == ETHER_PHY_MII_TYPE_RGMII)
        {
            p_reg_emac->CXR35             = GETHER_ETHERC_CXR35_RGMII_VALUE;
            p_reg_emac->CXR31_b.SEL_LINK0 = 1;
        }
        else
        {
            p_reg_emac->CXR35             = GETHER_ETHERC_CXR35_MII_VALUE;
            p_reg_emac->CXR31_b.SEL_LINK0 = 0;
        }

        p_reg_emac->CXR2C = GETHER_ETHERC_CXR2C_DEFAULT_VALUE;

        /* Receive frame limit set register */
        p_reg_emac->CXR2A = GETHER_RCV_BUFF_MAX + 4;

        p_instance_ctrl->open = GETHER_OPEN;

        err = FSP_SUCCESS;
    }
    else
    {
        if (FSP_ERR_ETHER_PHY_ERROR_LINK == phy_ret)
        {
            err = FSP_ERR_ETHER_ERROR_PHY_COMMUNICATION;
        }
        else
        {
            err = phy_ret;
        }
    }

    return err;
}                                      /* End of function R_GETHER_Open() */

/********************************************************************************************************************//**
 * @brief Disables interrupts. Removes power and releases hardware lock. Implements @ref RZA::ether_api_t::close.
 *
 * @retval  FSP_SUCCESS                                 Channel successfully closed.
 * @retval  FSP_ERR_ASSERTION                           Pointer to ETHER control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN                            The control block has not been opened
 *
 ***********************************************************************************************************************/
fsp_err_t R_GETHER_Close (ether_ctrl_t * const p_ctrl)
{
    fsp_err_t               err             = FSP_SUCCESS;
    ether_instance_ctrl_t * p_instance_ctrl = (ether_instance_ctrl_t *) p_ctrl;
    R_EMAC0_Type          * p_reg_emac;
    R_ETHER0_Type         * p_reg_ether;

#if (GETHER_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GETHER_ERROR_RETURN(GETHER_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_reg_emac  = (R_EMAC0_Type *) p_instance_ctrl->p_reg_emac;
    p_reg_ether = (R_ETHER0_Type *) p_instance_ctrl->p_reg_ether;

    /* Disable Ethernet interrupt. */
    gether_disable_icu(p_instance_ctrl);

    p_reg_ether->RIC0 = 0;
    p_reg_ether->RIC1 = 0;
    p_reg_ether->RIC2 = 0;
    p_reg_ether->TIC  = 0;

    p_instance_ctrl->p_gether_cfg->p_ether_phy_instance->p_api->close(
        p_instance_ctrl->p_gether_cfg->p_ether_phy_instance->p_ctrl);

    p_reg_emac->CXR22 = 0;

    /* Disable TE and RE  */
    p_reg_emac->CXR20 = GETHER_ETHERC_ECMR_MODE_CLEAR;

    /* Reset DMAC */
    p_reg_ether->CCC_b.OPC = GETHER_OPC_MODE_RESET;

    /* Free all the skb's in the RX queue and the DMA buffers. */
    gether_init_buffers(p_instance_ctrl);

    /* Initialize the flags */
    p_instance_ctrl->link_establish_status = GETHER_LINK_ESTABLISH_STATUS_DOWN;
    p_instance_ctrl->link_change           = GETHER_LINK_CHANGE_NO_CHANGE;
#if (GETHER_CFG_USE_LINKSTA == 0)
    p_instance_ctrl->previous_link_status = GETHER_PREVIOUS_LINK_STATUS_DOWN;
#endif

    /** Remove power to the channel. */
    R_BSP_MODULE_STOP(FSP_IP_ETHER, p_instance_ctrl->p_gether_cfg->channel);

    /** Clear configure block parameters. */
    p_instance_ctrl->p_gether_cfg = NULL;

    /** Mark the channel not open so other APIs cannot use it. */
    p_instance_ctrl->open = 0U;

    return err;
}                                      /* End of function R_GETHER_Close() */

/********************************************************************************************************************//**
 * @brief Move to the next buffer in the circular receive buffer list. Implements @ref RZA::ether_api_t::bufferRelease.
 *
 * @retval  FSP_SUCCESS                             Processing completed successfully.
 * @retval  FSP_ERR_ASSERTION                       Pointer to ETHER control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN                        The control block has not been opened
 * @retval  FSP_ERR_ETHER_ERROR_LINK                Auto-negotiation is not completed, and reception is not enabled.
 * @retval  FSP_ERR_ETHER_ERROR_MAGIC_PACKET_MODE   As a Magic Packet is being detected, transmission and reception is
 *                                                  not enabled.
 ***********************************************************************************************************************/
fsp_err_t R_GETHER_BufferRelease (ether_ctrl_t * const p_ctrl)
{
    fsp_err_t               err             = FSP_SUCCESS;
    ether_instance_ctrl_t * p_instance_ctrl = (ether_instance_ctrl_t *) p_ctrl;

    /* Check argument */
#if (GETHER_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GETHER_ERROR_RETURN(GETHER_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* When the Link up processing is not completed, return error */
    GETHER_ERROR_RETURN(GETHER_LINK_ESTABLISH_STATUS_UP == p_instance_ctrl->link_establish_status,
                        FSP_ERR_ETHER_ERROR_LINK);

    /* In case of detection mode of magic packet, return error. */
    GETHER_ERROR_RETURN(0 == gether_check_magic_packet_detection_bit(p_instance_ctrl),
                        FSP_ERR_ETHER_ERROR_MAGIC_PACKET_MODE);

    /* Move to next descriptor */
    p_instance_ctrl->p_rx_descriptor->ds  = p_instance_ctrl->p_gether_cfg->ether_buffer_size & GETHER_MASK_12BITS;
    p_instance_ctrl->p_rx_descriptor->ti  = 0;
    p_instance_ctrl->p_rx_descriptor->ei  = 0;
    p_instance_ctrl->p_rx_descriptor->ps  = 0;
    p_instance_ctrl->p_rx_descriptor->msc = 0;
    p_instance_ctrl->p_rx_descriptor->die = GETHER_DECRIPTOR_INT_RX;
    p_instance_ctrl->p_rx_descriptor->dt  = GETHER_DESCRIPTOR_TYPE_FEMPTY;

    p_instance_ctrl->p_rx_descriptor++;

    if ((p_instance_ctrl->p_rx_descriptor->dt == GETHER_DESCRIPTOR_TYPE_LINKFIX) ||
        (p_instance_ctrl->p_rx_descriptor->dt == GETHER_DESCRIPTOR_TYPE_LINK))
    {
        /* Move to next descriptor */
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
        uint64_t pa = (uint64_t)
                      (void *) (((address_size_t) p_instance_ctrl->p_rx_descriptor &
                                 GETHER_ADDRESS_UPPER_BITS_MASK) |
                                (address_size_t) p_instance_ctrl->p_rx_descriptor->dptr);
        uint64_t va;
        R_MMU_PAtoVA(&g_mmu_ctrl, pa, &va);
        p_instance_ctrl->p_rx_descriptor = (gether_instance_rx_descriptor_t *) va;
#else                                  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
        p_instance_ctrl->p_rx_descriptor =
            (void *) (((address_size_t) p_instance_ctrl->p_rx_descriptor & GETHER_ADDRESS_UPPER_BITS_MASK) |
                      (address_size_t) p_instance_ctrl->p_rx_descriptor->dptr);
#endif  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
    }

    err = FSP_SUCCESS;

    return err;
}                                      /* End of function R_GETHER_BufferRelease() */

/********************************************************************************************************************//**
 * @brief Change the buffer pointer of the current rx buffer descriptor. Implements @ref RZA::ether_api_t::rxBufferUpdate.
 *
 * @retval  FSP_SUCCESS                             Processing completed successfully.
 * @retval  FSP_ERR_ASSERTION                       A pointer argument is NULL.
 * @retval  FSP_ERR_NOT_OPEN                        The control block has not been opened.
 * @retval  FSP_ERR_INVALID_POINTER                 The pointer of buffer is NULL or not aligned on a 32-bit boundary.
 * @retval  FSP_ERR_INVALID_MODE                    Driver is configured to non zero copy mode.
 ***********************************************************************************************************************/
fsp_err_t R_GETHER_RxBufferUpdate (ether_ctrl_t * const p_ctrl, __attribute__((unused)) void * const p_buffer)
{
    fsp_err_t               err             = FSP_SUCCESS;
    ether_instance_ctrl_t * p_instance_ctrl = (ether_instance_ctrl_t *) p_ctrl;

    /* Check argument */
#if (GETHER_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GETHER_ERROR_RETURN(GETHER_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    GETHER_ERROR_RETURN(NULL != p_buffer, FSP_ERR_INVALID_POINTER);
    GETHER_ERROR_RETURN(0 == ((address_size_t) p_buffer & (address_size_t) GETHER_BUFFER_32BYTE_ALIGNMENT_MASK),
                        FSP_ERR_INVALID_POINTER);
    GETHER_ERROR_RETURN(ETHER_ZEROCOPY_ENABLE == p_instance_ctrl->p_gether_cfg->zerocopy, FSP_ERR_INVALID_MODE);
#endif

    while (p_instance_ctrl->p_rx_descriptor->dt == GETHER_DESCRIPTOR_TYPE_LINKFIX)
    {
        /* next descriptor */
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
        uint64_t pa = (uint64_t)
                      (void *) (((address_size_t) p_instance_ctrl->p_rx_descriptor &
                                 GETHER_ADDRESS_UPPER_BITS_MASK) |
                                (address_size_t) p_instance_ctrl->p_rx_descriptor->dptr);
        uint64_t va;
        R_MMU_PAtoVA(&g_mmu_ctrl, pa, &va);
        p_instance_ctrl->p_rx_descriptor = (gether_instance_rx_descriptor_t *) va;
#else                                  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
        p_instance_ctrl->p_rx_descriptor =
            (void *) (((address_size_t) p_instance_ctrl->p_rx_descriptor & GETHER_ADDRESS_UPPER_BITS_MASK) |
                      (address_size_t) p_instance_ctrl->p_rx_descriptor->dptr);
#endif  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
    }

    p_instance_ctrl->p_rx_descriptor->dt = GETHER_DESCRIPTOR_TYPE_FEMPTY;
    p_instance_ctrl->p_rx_descriptor++;

    return err;
}

/********************************************************************************************************************//**
 * @brief The Link up processing, the Link down processing, and the magic packet detection processing are executed.
 *  Implements @ref RZA::ether_api_t::linkProcess.
 *
 * @retval  FSP_SUCCESS                                 Link is up.
 * @retval  FSP_ERR_ASSERTION                           Pointer to ETHER control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN                            The control block has not been opened.
 * @retval  FSP_ERR_ETHER_ERROR_LINK                    Link is down.
 * @retval  FSP_ERR_ETHER_PHY_ERROR_LINK                Initialization of the PHY-LSI failed.
 ***********************************************************************************************************************/
fsp_err_t R_GETHER_LinkProcess (ether_ctrl_t * const p_ctrl)
{
    fsp_err_t               err             = FSP_SUCCESS;
    ether_instance_ctrl_t * p_instance_ctrl = (ether_instance_ctrl_t *) p_ctrl;
    R_EMAC0_Type          * p_reg_emac;
    R_TOE0_Type           * p_reg_toe;
    R_ETHER0_Type         * p_reg_ether;
    ether_callback_args_t   callback_arg;

#if (GETHER_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GETHER_ERROR_RETURN(GETHER_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    ether_instance_extend_t * p_ether_instance_extend =
        (ether_instance_extend_t *) p_instance_ctrl->p_gether_cfg->p_extend;

    /* Set the base address of I/O register */
    p_reg_emac  = (R_EMAC0_Type *) p_instance_ctrl->p_reg_emac;
    p_reg_toe   = (R_TOE0_Type *) p_instance_ctrl->p_reg_toe;
    p_reg_ether = (R_ETHER0_Type *) p_instance_ctrl->p_reg_ether;

#if (GETHER_CFG_USE_LINKSTA == 0)
    err = gether_link_status_check(p_instance_ctrl);

    /* The state of the link status in PHY-LSI is confirmed and Link Up/Down is judged. */
    if (FSP_SUCCESS == err)
    {
        /* When becoming Link up */
        if (GETHER_PREVIOUS_LINK_STATUS_DOWN == p_instance_ctrl->previous_link_status)
        {
            p_instance_ctrl->link_change = GETHER_LINK_CHANGE_LINK_UP;

            /* Update Link status */
            p_instance_ctrl->previous_link_status = GETHER_PREVIOUS_LINK_STATUS_UP;
        }
    }
    else
    {
        /* When becoming Link down */
        if (GETHER_PREVIOUS_LINK_STATUS_UP == p_instance_ctrl->previous_link_status)
        {
            p_instance_ctrl->link_change = GETHER_LINK_CHANGE_LINK_DOWN;

            /* Update Link status */
            p_instance_ctrl->previous_link_status = GETHER_PREVIOUS_LINK_STATUS_DOWN;
        }
    }

#else

    /* Set the base address of I/O register */
    p_reg_emac = (R_EMAC0_Type *) p_instance_ctrl->p_reg_emac;

    /* It is confirmed not to become Link down while changing the setting. */
    if (GETHER_CFG_LINK_PRESENT == p_reg_emac->CXR2B_b.LINK)
    {
        p_instance_ctrl->link_change = GETHER_LINK_CHANGE_LINK_UP;
    }
    else if (GETHER_LINK_ESTABLISH_STATUS_UP == p_instance_ctrl->link_establish_status)
    {
        p_instance_ctrl->link_change = GETHER_LINK_CHANGE_LINK_DOWN;
    }
#endif

    /* When the link is up */
    if (GETHER_LINK_CHANGE_LINK_UP == p_instance_ctrl->link_change)
    {
#if (GETHER_CFG_USE_LINKSTA == 1)

        /*
         * The Link Up/Down is confirmed by the Link Status bit of PHY register1,
         * because the LINK signal of PHY-LSI is used for LED indicator, and
         * isn't used for notifing the Link Up/Down to external device.
         */
        err = gether_link_status_check(p_instance_ctrl);

        if (FSP_SUCCESS == err)
        {
#endif

#if (GETHER_CFG_USE_LINKSTA == 1)
        p_instance_ctrl->link_change = GETHER_LINK_CHANGE_LINK_DOWN;
#elif (GETHER_CFG_USE_LINKSTA == 0)
        p_instance_ctrl->link_change = GETHER_LINK_CHANGE_NO_CHANGE;
#endif

        /* Initialize the transmit and receive descriptor */
        memset(p_ether_instance_extend->p_rx_descriptor, 0x00,
               sizeof(gether_instance_rx_descriptor_t) * (p_instance_ctrl->p_gether_cfg->num_rx_descriptors + 1));
        memset(p_ether_instance_extend->p_tx_descriptor, 0x00,
               sizeof(gether_instance_tx_descriptor_t) * (p_instance_ctrl->p_gether_cfg->num_tx_descriptors + 1));
        memset(g_gether_basic_descriptors[p_instance_ctrl->p_gether_cfg->channel], 0x00,
               sizeof(g_gether_basic_descriptors[0]));

        /* Initialize the Ethernet buffer */
        gether_init_buffers(p_instance_ctrl);

        p_instance_ctrl->link_establish_status = GETHER_LINK_ESTABLISH_STATUS_UP;

        /*
         * ETHERC and EDMAC are set after ETHERC and EDMAC are reset in software
         * and sending and receiving is permitted.
         */
        gether_configure_mac(p_instance_ctrl,
                             p_instance_ctrl->p_gether_cfg->p_mac_address,
                             GETHER_NO_USE_MAGIC_PACKET_DETECT);

        p_reg_emac->CXR20 = GETHER_ETHERC_ECMR_MODE_CLEAR;

        p_reg_emac->CXR21 = ((1UL << R_ETHER_CXR21_FCI_Pos) & R_ETHER_CXR21_FCI_Msk) |
                            ((1UL << R_ETHER_CXR21_LINKI_Pos) & R_ETHER_CXR21_LINKI_Msk) |
                            ((1UL << R_ETHER_CXR21_PFRI_Pos) & R_ETHER_CXR21_PFRI_Msk);

        /* E-MAC interrupt enable register */
        p_reg_emac->CXR22 = ((1UL << R_ETHER_CXR22_FCIM_Pos) & R_ETHER_CXR22_FCIM_Msk);

        err = gether_do_link(p_instance_ctrl, GETHER_NO_USE_MAGIC_PACKET_DETECT);

        if (FSP_SUCCESS == err)
        {
            if (NULL != p_instance_ctrl->p_callback)
            {
                callback_arg.channel     = p_instance_ctrl->p_gether_cfg->channel;
                callback_arg.event       = ETHER_EVENT_LINK_ON;
                callback_arg.status_ecsr = 0;
                callback_arg.status_eesr = 0;
                callback_arg.p_context   = p_instance_ctrl->p_gether_cfg->p_context;
                ether_call_callback(p_instance_ctrl, &callback_arg);
            }
        }
        else
        {
            /* When PHY auto-negotiation is not completed */
            p_instance_ctrl->link_establish_status = GETHER_LINK_ESTABLISH_STATUS_DOWN;
            p_instance_ctrl->link_change           = GETHER_LINK_CHANGE_LINK_UP;
        }

#if (GETHER_CFG_USE_LINKSTA == 1)
    }
    else
    {
        /* no process */
    }
#endif

        /* Enable adding TX checksum */
        p_reg_toe->CSR1 = (1 << R_ETHER_CSR1_TIP4_Pos) |
                          (1 << R_ETHER_CSR1_TTCP4_Pos) |
                          (1 << R_ETHER_CSR1_TUDP4_Pos) |
                          (1 << R_ETHER_CSR1_TICMP4_Pos);

        /* Enable calculating RX checksum */
        p_reg_toe->CSR2 = (1 << R_ETHER_CSR2_RIP4_Pos) |
                          (1 << R_ETHER_CSR2_RTCP4_Pos) |
                          (1 << R_ETHER_CSR2_RUDP4_Pos) |
                          (1 << R_ETHER_CSR2_RICMP4_Pos);

        /* Set the base address of descriptors */
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
        {
            uint64_t pa = 0;
            R_MMU_VAtoPA(&g_mmu_ctrl, (uint64_t) g_gether_basic_descriptors[p_instance_ctrl->p_gether_cfg->channel],
                         &pa);
            p_reg_ether->DBAT = (uint32_t) (address_size_t) pa;
        }
#else                                  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
        p_reg_ether->DBAT = (uint64_t) g_gether_basic_descriptors[p_instance_ctrl->p_gether_cfg->channel];
#endif  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
        /* Set RX */
        p_reg_ether->RCR = GETHER_RCR_DEFAULT_VALUE;

        /* Set Max Frame Length (RTC) */
        p_reg_ether->RTC = GETHER_RTC_FIXED_BITS | p_instance_ctrl->p_gether_cfg->ether_buffer_size;

        p_reg_ether->CIE  = 0x00000000; /* default value */
        p_reg_ether->DIE  = 0x00000000; /* default value */
        p_reg_ether->EIE  = 0x00000000; /* default value */
        p_reg_ether->RIE0 = 0x00000000; /* default value */
        p_reg_ether->RIE1 = 0x00000000; /* default value */
        p_reg_ether->RIE2 = 0x00000000; /* default value */
        p_reg_ether->TIE  = 0x00000000; /* default value */
        p_reg_ether->RIE3 = 0x00000000; /* default value */

        /* PAUSE prohibition */
        p_reg_emac->CXR72 = 1;

        /* E-MAC status register clear */
        p_reg_emac->CXR21 = ((1UL << R_ETHER_CXR21_FCI_Pos) & R_ETHER_CXR21_FCI_Msk) |
                            ((1UL << R_ETHER_CXR21_LINKI_Pos) & R_ETHER_CXR21_LINKI_Msk) |
                            ((1UL << R_ETHER_CXR21_PFRI_Pos) & R_ETHER_CXR21_PFRI_Msk);

        /* E-MAC interrupt enable register */
        p_reg_emac->CXR22_b.FCIM = 1;

        /* Clear all ETHERC status BFR, PSRTO, LCHNG, MPD, ICD */
        p_reg_emac->CXR21 = GETHER_ETHERC_INTERRUPT_FACTOR_ALL;

        /* DMAC init */
        p_reg_ether->CCC_b.BOC = 0;

        /* Set RX */
        p_reg_ether->RCR = GETHER_RCR_DEFAULT_VALUE;

        /* Set FIFO size */
        p_reg_ether->TGC = GETHER_TGC_DEFAULT_VALUE;

        p_reg_ether->TCCR = 0;

        /* Interrupt enable: */

        p_reg_ether->DIC = (1 << GETHER_DECRIPTOR_INT_TX) |
                           (1 << GETHER_DECRIPTOR_INT_RX);

        /* Frame receive */
        p_reg_ether->RIC0 = ((1UL << R_ETHER_RIC0_FRE_Pos) & R_ETHER_RIC0_FRE_Msk);
        p_reg_ether->RIC1 = 0;

        /* Receive FIFO full error, descriptor empty */
        p_reg_ether->RIC2 = ((1UL << R_ETHER_RIC2_QFE_Pos) & R_ETHER_RIC2_QFE_Msk) |
                            ((1UL << R_ETHER_RIC2_RFFE_Pos) & R_ETHER_RIC2_RFFE_Msk);
        p_reg_ether->RIC3      = 0;
        p_reg_ether->TIE_b.FTS = 1;

        /* Setting the control will start the DMAC process. */
        p_reg_ether->CCC_b.OPC = GETHER_OPC_MODE_OPERATION;
        p_reg_toe->CSR0_b.TPE  = 1;
        p_reg_toe->CSR0_b.RPE  = 1;

        if ((ETHER_FLOW_CONTROL_ENABLE == p_instance_ctrl->p_gether_cfg->flow_control))
        {
            p_reg_emac->CXR20_b.RXF  = 1;
            p_reg_emac->CXR20_b.TZPF = 1;
        }

        p_reg_emac->CXR20_b.RPE = 1;
        p_reg_emac->CXR20_b.TPE = 1;

        p_reg_emac->CXR20_b.RCPT = 1;

        /* Move the TX descriptor */
        p_reg_ether->TCCR_b.TSRQ = 1;

        /* Interrupt enable: */
        gether_enable_icu(p_instance_ctrl);
    }
    /* When the link is down */
    else if (GETHER_LINK_CHANGE_LINK_DOWN == p_instance_ctrl->link_change)
    {
        p_instance_ctrl->link_change = GETHER_LINK_CHANGE_NO_CHANGE;

#if (GETHER_CFG_USE_LINKSTA == 1)

        /*
         * The Link Up/Down is confirmed by the Link Status bit of PHY register1,
         * because the LINK signal of PHY-LSI is used for LED indicator, and
         * isn't used for notifying the Link Up/Down to external device.
         */
        err = gether_link_status_check(p_instance_ctrl);
        if (FSP_ERR_ETHER_ERROR_LINK == err)
        {
#endif
        while (p_reg_ether->TCCR_b.TSRQ == 1)
        {
            ;
        }

        /* E-MAC.CXR20 Set bit6 (RPE) = "0" to stop Rx Function of E-MAC. Not necessary to change other bits. */
        p_reg_emac->CXR20_b.RPE = 0;

        /* DMAC.CSR Wait until bit20 (RPO) will be "0" (Wait Reception FIFO will be empty) */
        while (p_reg_ether->CSR_b.RPO == 1)
        {
            ;
        }

        /* DMAC.CCC Set bit8 (DTSR) = "1" to stop URAM access. Not necessary to change other bits. */
        p_reg_ether->CCC_b.DTSR = 1;

        /* DMAC.CSR Wait until bit8 (DTS) will be "1" (URAM access is stopping) */
        while (p_reg_ether->CSR_b.DTS == 0)
        {
            ;
        }

        /* TOE.CSR0 Wait until bit5 (RPE) and bit4 (TPE) will be "0"*/
        while (p_reg_toe->CSR0 & (R_ETHER_CSR0_TPE_Msk | R_ETHER_CSR0_RPE_Msk))
        {
            /* TOE.CSR0 Set bit5 (RPE) = "0" and bit4 (TPE) = "0" to stop Rx and Tx Function of TOE. Not necessary to change other bits. */
            p_reg_toe->CSR0 = 0;
        }

        /* E-MAC.CXR20 Wait until bit6 (RPE) and bit5 (TPE) will be "0" */
        while (p_reg_emac->CXR20 & (R_ETHER_CXR20_TPE_Msk | R_ETHER_CXR20_RPE_Msk))
        {
            /* E-MAC.CXR20 Set bit5 (TPE) = "0" to stop Tx Function of E-MAC. Not necessary to change other bits. */
            p_reg_emac->CXR20_b.TPE = 0;
            p_reg_emac->CXR20_b.RPE = 0;
        }

        /* DMAC.CCC Set bit [1:0] = "01b" (Config Mode) and bit8 (DTSR) = "0" */
        p_reg_ether->CCC = (uint32_t) ((p_reg_ether->CCC & ~(R_ETHER_CCC_OPC_Msk | R_ETHER_CCC_DTSR_Msk)) |
                                       GETHER_OPC_MODE_CONFIG);

        p_instance_ctrl->link_establish_status = GETHER_LINK_ESTABLISH_STATUS_DOWN;

        if (NULL != p_instance_ctrl->p_callback)
        {
            callback_arg.channel     = p_instance_ctrl->p_gether_cfg->channel;
            callback_arg.event       = ETHER_EVENT_LINK_OFF;
            callback_arg.status_ecsr = 0;
            callback_arg.status_eesr = 0;
            callback_arg.p_context   = p_instance_ctrl->p_gether_cfg->p_context;
            ether_call_callback(p_instance_ctrl, &callback_arg);
        }

#if (GETHER_CFG_USE_LINKSTA == 1)
    }
    else
    {
        ;                              /* no operation */
    }
#endif
    }
    else
    {
        ;                              /* no operation */
    }

    return err;
} /* End of function R_GETHER_LinkProcess() */

/********************************************************************************************************************//**
 * @brief The setting of ETHERC is changed from normal sending and receiving mode to magic packet detection mode.
 * Implements @ref RZA::ether_api_t::wakeOnLANEnable.
 *
 * @retval  FSP_SUCCESS                                 Processing completed successfully.
 * @retval  FSP_ERR_ASSERTION                           Pointer to ETHER control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN                            The control block has not been opened.
 * @retval  FSP_ERR_ETHER_ERROR_LINK                    Auto-negotiation is not completed, and reception is not enabled.
 * @retval  FSP_ERR_ETHER_PHY_ERROR_LINK                Initialization of PHY-LSI failed.
 ***********************************************************************************************************************/
fsp_err_t R_GETHER_WakeOnLANEnable (ether_ctrl_t * const p_ctrl)
{
    fsp_err_t err = FSP_SUCCESS;
    ether_instance_ctrl_t * p_instance_ctrl = (ether_instance_ctrl_t *) p_ctrl;
#if (GETHER_CFG_USE_LINKSTA == 1)
    R_EMAC0_Type * p_reg_emac;
#endif

    /* Check argument */
#if (GETHER_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GETHER_ERROR_RETURN(GETHER_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* When the Link up processing is not completed, return error */
    GETHER_ERROR_RETURN(GETHER_LINK_ESTABLISH_STATUS_UP == p_instance_ctrl->link_establish_status,
                        FSP_ERR_ETHER_ERROR_LINK);

    err = gether_do_link(p_instance_ctrl, GETHER_USE_MAGIC_PACKET_DETECT);
    if (FSP_SUCCESS == err)
    {
#if (GETHER_CFG_USE_LINKSTA == 1)

        /* Set the base address of I/O register */
        p_reg_emac = (R_EMAC0_Type *) p_instance_ctrl->p_reg_emac;

        /* It is confirmed not to become Link down while changing the setting. */
        if (GETHER_CFG_LINK_PRESENT == p_reg_emac->CXR2B_b.LINK)
        {
            err = FSP_SUCCESS;
        }
        else
        {
            err = FSP_ERR_ETHER_ERROR_LINK;
        }

#else

        /* It is confirmed not to become Link down while changing the setting. */
        err = gether_link_status_check(p_instance_ctrl);
#endif
    }
    else
    {
        err = FSP_ERR_ETHER_ERROR_LINK;
    }

    return err;
}                                      /* End of function R_GETHER_WakeOnLANEnable() */

/********************************************************************************************************************//**
 * @brief Receive Ethernet frame. Receives data to the location specified by the pointer to the receive buffer.
 * In zero copy mode, the address of the receive buffer is returned.
 * In non zero copy mode, the received data in the internal buffer is copied to the pointer passed by the argument.
 * Implements @ref RZA::ether_api_t::read.
 *
 * @retval  FSP_SUCCESS                                 Processing completed successfully.
 * @retval  FSP_ERR_ASSERTION                           Pointer to ETHER control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN                            The control block has not been opened.
 * @retval  FSP_ERR_ETHER_ERROR_NO_DATA                 There is no data in receive buffer.
 * @retval  FSP_ERR_ETHER_ERROR_LINK                    Auto-negotiation is not completed, and reception is not enabled.
 * @retval  FSP_ERR_ETHER_ERROR_MAGIC_PACKET_MODE       As a Magic Packet is being detected, transmission and reception
 *                                                      is not enabled.
 * @retval  FSP_ERR_INVALID_POINTER                     Value of the pointer is NULL.
 * @retval  FSP_ERR_INVALID_SIZE                        The buffer size is smaller than  @ref ether_cfg_t::ether_buffer_size.
 *
 ***********************************************************************************************************************/
fsp_err_t R_GETHER_Read (ether_ctrl_t * const p_ctrl, void * const p_buffer, uint32_t * const length_bytes)
{
    fsp_err_t err = FSP_SUCCESS;
    ether_instance_ctrl_t * p_instance_ctrl = (ether_instance_ctrl_t *) p_ctrl;
    uint8_t * p_read_buffer                 = NULL; /* Buffer location controlled by the Ethernet driver */
    uint8_t * p_read_buffer_out             = NULL; /* Buffer location controlled by the Ethernet driver */
    uint32_t received_size = GETHER_NO_DATA;
#if  (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    uint64_t va;
#endif

    /* Check argument */
#if (GETHER_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GETHER_ERROR_RETURN(GETHER_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    GETHER_ERROR_RETURN(NULL != p_buffer, FSP_ERR_INVALID_POINTER);
    GETHER_ERROR_RETURN(NULL != length_bytes, FSP_ERR_INVALID_POINTER);
 #if (GETHER_CFG_READ_BUFFER_SIZE_CHECK)
    GETHER_ERROR_RETURN(p_instance_ctrl->p_gether_cfg->ether_buffer_size <= *length_bytes, FSP_ERR_INVALID_SIZE);
 #endif
#endif

    /* (1) Retrieve the receive buffer location controlled by the  descriptor. */
    /* When the Link up processing is not completed, return error */
    GETHER_ERROR_RETURN(GETHER_LINK_ESTABLISH_STATUS_UP == p_instance_ctrl->link_establish_status,
                        FSP_ERR_ETHER_ERROR_LINK);

    /* In case of detection mode of magic packet, return error. */
    GETHER_ERROR_RETURN(0 == gether_check_magic_packet_detection_bit(p_instance_ctrl),
                        FSP_ERR_ETHER_ERROR_MAGIC_PACKET_MODE);

    while (FSP_SUCCESS == err)
    {
        /* empty */
        if (p_instance_ctrl->p_rx_descriptor->dt == GETHER_DESCRIPTOR_TYPE_FEMPTY)
        {
            *length_bytes = 0;
            err           = FSP_ERR_ETHER_ERROR_NO_DATA;
            break;
        }

        /* received data is contained in the single descriptor */
        if (p_instance_ctrl->p_rx_descriptor->dt == GETHER_DESCRIPTOR_TYPE_FSINGLE)
        {
            /* Calculate the copy size */
            received_size = p_instance_ctrl->p_rx_descriptor->ds;
            p_read_buffer =
                (void *) (((address_size_t) p_instance_ctrl->p_rx_descriptor & GETHER_ADDRESS_UPPER_BITS_MASK) |
                          (address_size_t) p_instance_ctrl->p_rx_descriptor->dptr);

#if  (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
            R_MMU_PAtoVA(&g_mmu_ctrl, (address_size_t) p_read_buffer, &va);
            p_read_buffer = (uint8_t *) va;
#endif                                 /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
            /* copy data */
            memcpy(p_buffer, p_read_buffer, received_size);
            *length_bytes = received_size;

            /* Move to next descriptor */
            R_GETHER_BufferRelease(p_ctrl);

            break;
        }

        /* received data is contained in the multiple descriptors */
        /* The first descriptor */
        if (p_instance_ctrl->p_rx_descriptor->dt == GETHER_DESCRIPTOR_TYPE_FSTART)
        {
            uint32_t receive_size = 0;

            p_read_buffer_out = (uint8_t *) p_buffer;

            /* Calculate the copy size */
            if (*length_bytes == received_size)
            {
                receive_size = 0;
            }
            else if (*length_bytes - received_size > p_instance_ctrl->p_rx_descriptor->ds)
            {
                receive_size = p_instance_ctrl->p_rx_descriptor->ds;
            }
            else
            {
                receive_size = *length_bytes - received_size;
            }

            p_read_buffer =
                (void *) (((address_size_t) p_instance_ctrl->p_rx_descriptor & GETHER_ADDRESS_UPPER_BITS_MASK) |
                          (address_size_t) p_instance_ctrl->p_rx_descriptor->dptr);

#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
            R_MMU_PAtoVA(&g_mmu_ctrl, (address_size_t) p_read_buffer, &va);
            p_read_buffer = (uint8_t *) va;
#endif                                 /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
            /* copy data */
            memcpy(p_read_buffer_out + received_size, p_read_buffer, receive_size);
            received_size += receive_size;

            /* Move to next descriptor */
            R_GETHER_BufferRelease(p_ctrl);
        }
        /* The second descriptor or later */
        else if ((p_instance_ctrl->p_rx_descriptor->dt == GETHER_DESCRIPTOR_TYPE_FMID) ||
                 (p_instance_ctrl->p_rx_descriptor->dt == GETHER_DESCRIPTOR_TYPE_FEND))
        {
            if (received_size == GETHER_NO_DATA)
            {
                /* illegal DT */
                err           = FSP_ERR_ETHER_ERROR_NO_DATA;
                *length_bytes = 0;
                break;
            }

            {
                uint32_t receive_size = 0;
                uint32_t end_of_desc  = 0;

                /* Check the end of descriptor */
                if (p_instance_ctrl->p_rx_descriptor->dt == GETHER_DESCRIPTOR_TYPE_FEND)
                {
                    end_of_desc = 1;
                }

                /* Calculate the copy size */
                p_read_buffer_out = (uint8_t *) p_buffer;
                if (*length_bytes == received_size)
                {
                    receive_size = 0;
                }
                else if (*length_bytes - received_size > p_instance_ctrl->p_rx_descriptor->ds)
                {
                    receive_size = p_instance_ctrl->p_rx_descriptor->ds;
                }
                else
                {
                    /* cannot receive the whole data */
                    receive_size = *length_bytes - received_size;
                }

                p_read_buffer =
                    (void *) (((address_size_t) p_instance_ctrl->p_rx_descriptor & GETHER_ADDRESS_UPPER_BITS_MASK) |
                              (address_size_t) p_instance_ctrl->p_rx_descriptor->dptr);

#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
                R_MMU_PAtoVA(&g_mmu_ctrl, (address_size_t) p_read_buffer, &va);
                p_read_buffer = (uint8_t *) va;
#endif                                 /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
                /* Copy data */
                memcpy(p_read_buffer_out + received_size, p_read_buffer, receive_size);
                received_size += receive_size;

                /* Move to next descriptor */
                R_GETHER_BufferRelease(p_ctrl);

                /* The end of descriptor */
                if (end_of_desc != 0)
                {
                    break;
                }
            }
        }
        else if ((p_instance_ctrl->p_rx_descriptor->dt == GETHER_DESCRIPTOR_TYPE_LINKFIX) ||
                 (p_instance_ctrl->p_rx_descriptor->dt == GETHER_DESCRIPTOR_TYPE_LINK))
        {
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)

            /* Move to next descriptor */
            uint64_t pa = (uint64_t)
                          (void *) (((address_size_t) p_instance_ctrl->p_rx_descriptor &
                                     GETHER_ADDRESS_UPPER_BITS_MASK) |
                                    (address_size_t) p_instance_ctrl->p_rx_descriptor->dptr);
            R_MMU_PAtoVA(&g_mmu_ctrl, pa, &va);
            p_instance_ctrl->p_rx_descriptor = (gether_instance_rx_descriptor_t *) va;
#else                                  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
            p_instance_ctrl->p_rx_descriptor =
                (void *) (((address_size_t) p_instance_ctrl->p_rx_descriptor &
                           GETHER_ADDRESS_UPPER_BITS_MASK) |
                          (address_size_t) p_instance_ctrl->p_rx_descriptor->dptr);
#endif                                 /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
        }
        else
        {
            R_GETHER_BufferRelease(p_ctrl);
        }
    }

    if ((err == FSP_SUCCESS) && (received_size == GETHER_NO_DATA))
    {
        *length_bytes = 0;
        err           = FSP_ERR_ETHER_ERROR_NO_DATA;
    }

    return err;
}                                      /* End of function R_GETHER_Read() */

/********************************************************************************************************************//**
 * @brief Transmit Ethernet frame. Transmits data from the location specified by the pointer to the transmit
 *  buffer, with the data size equal to the specified frame length.
 *  In the non zero copy mode, transmits data after being copied to the internal buffer.
 *  Implements @ref RZA::ether_api_t::write.
 *
 * @retval  FSP_SUCCESS                                 Processing completed successfully.
 * @retval  FSP_ERR_ASSERTION                           Pointer to ETHER control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN                            The control block has not been opened.
 * @retval  FSP_ERR_ETHER_ERROR_LINK                    Auto-negotiation is not completed, and reception is not enabled.
 * @retval  FSP_ERR_ETHER_ERROR_MAGIC_PACKET_MODE       As a Magic Packet is being detected, transmission and reception
 *                                                      is not enabled.
 * @retval  FSP_ERR_ETHER_ERROR_TRANSMIT_BUFFER_FULL    Transmit buffer is not empty.
 * @retval  FSP_ERR_INVALID_POINTER                     Value of the pointer is NULL.
 * @retval  FSP_ERR_INVALID_ARGUMENT                    Value of the send frame size is out of range.
 *
 ***********************************************************************************************************************/
fsp_err_t R_GETHER_Write (ether_ctrl_t * const p_ctrl, void * const p_buffer, uint32_t const frame_length)
{
    fsp_err_t err = FSP_SUCCESS;
    ether_instance_ctrl_t * p_instance_ctrl = (ether_instance_ctrl_t *) p_ctrl;
    R_ETHER0_Type * p_reg_ether;

    uint8_t * p_write_buffer = p_buffer;
    uint32_t buf_size;
    void * p_copy_dst;

    /* Check argument */
#if (GETHER_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GETHER_ERROR_RETURN(GETHER_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    GETHER_ERROR_RETURN(NULL != p_buffer, FSP_ERR_INVALID_POINTER);
    GETHER_ERROR_RETURN((GETHER_MINIMUM_FRAME_SIZE <= frame_length) && (GETHER_MAXIMUM_FRAME_SIZE >= frame_length),
                        FSP_ERR_INVALID_ARGUMENT);
#endif

    /* When the Link up processing is not completed, return error */
    GETHER_ERROR_RETURN(GETHER_LINK_ESTABLISH_STATUS_UP == p_instance_ctrl->link_establish_status,
                        FSP_ERR_ETHER_ERROR_LINK);

    /* In case of detection mode of magic packet, return error. */
    GETHER_ERROR_RETURN(0 == gether_check_magic_packet_detection_bit(p_instance_ctrl),
                        FSP_ERR_ETHER_ERROR_MAGIC_PACKET_MODE);

    p_reg_ether = (R_ETHER0_Type *) p_instance_ctrl->p_reg_ether;
    buf_size    = p_instance_ctrl->p_gether_cfg->ether_buffer_size;

    if (frame_length > buf_size)
    {
        err = FSP_ERR_ETHER_ERROR_TRANSMIT_BUFFER_FULL; /* Transmit buffer overflow */
    }
    else
    {
        gether_instance_tx_descriptor_t * p_tx_desc = p_instance_ctrl->p_tx_descriptor;
        gether_instance_tx_descriptor_t dummy;

        if ((p_tx_desc->dt == GETHER_DESCRIPTOR_TYPE_LINKFIX) || (p_tx_desc->dt == GETHER_DESCRIPTOR_TYPE_LINK))
        {
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)

            /* Move to next descriptor */
            uint64_t pa = (uint64_t)
                          (void *) (((address_size_t) p_tx_desc & GETHER_ADDRESS_UPPER_BITS_MASK) |
                                    (address_size_t) p_instance_ctrl->p_tx_descriptor->dptr);
            uint64_t va;
            R_MMU_PAtoVA(&g_mmu_ctrl, pa, &va);
            p_instance_ctrl->p_tx_descriptor = (gether_instance_tx_descriptor_t *) va;
#else                                  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
            p_instance_ctrl->p_tx_descriptor =
                (void *) (((address_size_t) p_tx_desc & GETHER_ADDRESS_UPPER_BITS_MASK) |
                          (address_size_t) p_tx_desc->dptr);
#endif                                 /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
            p_tx_desc = p_instance_ctrl->p_tx_descriptor;
        }

        /* use single descriptor */
        tag_counter++;
        p_tx_desc->die = GETHER_DECRIPTOR_INT_TX;
        p_tx_desc->msr = 0;
        p_tx_desc->tag = tag_counter & GETHER_MASK_10BITS;
        p_tx_desc->ds  = frame_length & GETHER_MASK_12BITS;

        p_copy_dst =
            (void *) (((address_size_t) p_tx_desc & GETHER_ADDRESS_UPPER_BITS_MASK) |
                      (address_size_t) p_tx_desc->dptr);
        memcpy(p_copy_dst, p_write_buffer, frame_length);

#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)

        /* Clean cache after writing data */
        R_BSP_CACHE_CleanRange((address_size_t) p_copy_dst, (frame_length + 3) & GETHER_ADDRESS_4BYTE_MASK);
#endif                                 /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */

        /* Decide DT */
        p_tx_desc->dt = GETHER_DESCRIPTOR_TYPE_FSINGLE;

        do
        {
            /* Clean cache after writing descriptor */
            R_BSP_CACHE_CleanRange((address_size_t) p_tx_desc, sizeof(gether_instance_tx_descriptor_t));

            /* Read back the last written descriptor */
            dummy = *p_tx_desc;
        } while (memcmp(&dummy, p_tx_desc, sizeof(gether_instance_tx_descriptor_t)));

        /* Move to the next descriptor */
        p_instance_ctrl->p_tx_descriptor++;
        p_tx_desc = p_instance_ctrl->p_tx_descriptor;

        if ((p_tx_desc->dt == GETHER_DESCRIPTOR_TYPE_LINKFIX) || (p_tx_desc->dt == GETHER_DESCRIPTOR_TYPE_LINK))
        {
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)

            /* Move to next descriptor */
            uint64_t pa = (uint64_t)
                          (void *) (((address_size_t) p_tx_desc & GETHER_ADDRESS_UPPER_BITS_MASK) |
                                    (address_size_t) p_instance_ctrl->p_tx_descriptor->dptr);
            uint64_t va;
            R_MMU_PAtoVA(&g_mmu_ctrl, pa, &va);
            p_instance_ctrl->p_tx_descriptor = (gether_instance_tx_descriptor_t *) va;
#else                                  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
            p_instance_ctrl->p_tx_descriptor =
                (void *) (((address_size_t) p_tx_desc & GETHER_ADDRESS_UPPER_BITS_MASK) |
                          (address_size_t) p_tx_desc->dptr);
#endif                                 /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
        }
    }

    if (err == FSP_SUCCESS)
    {
        p_reg_ether->TCCR_b.TSRQ = 1;
    }

    return err;
}                                      /* End of function R_GETHER_Write() */

/**********************************************************************************************************************//**
 * Provides status of Ethernet driver in the user provided pointer. Implements @ref RZA::ether_api_t::txStatusGet.
 *
 * @retval  FSP_SUCCESS                  Transmit buffer address is stored in provided p_buffer_address.
 * @retval  FSP_ERR_ASSERTION            Pointer to ETHER control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_INVALID_POINTER      p_status is NULL.
 * @retval  FSP_ERR_NOT_FOUND            Transmit buffer address has been overwritten in transmit descriptor.
 ***********************************************************************************************************************/
fsp_err_t R_GETHER_TxStatusGet (__attribute__((unused)) ether_ctrl_t * const p_ctrl,
                                __attribute__((unused)) void * const         p_buffer_address)
{
    ether_instance_ctrl_t * p_instance_ctrl = (ether_instance_ctrl_t *) p_ctrl;
    R_ETHER0_Type * p_reg_ether;
    gether_instance_tx_descriptor_t * p_descriptor;
    fsp_err_t err = FSP_ERR_NOT_FOUND;

#if (GETHER_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GETHER_ERROR_RETURN(GETHER_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    GETHER_ERROR_RETURN(NULL != p_buffer_address, FSP_ERR_INVALID_POINTER);
#endif

    p_reg_ether = (R_ETHER0_Type *) p_instance_ctrl->p_reg_ether;

    p_descriptor = (gether_instance_tx_descriptor_t *) (address_size_t) p_reg_ether->CDAR0;
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    {
        uint64_t va;
        R_MMU_PAtoVA(&g_mmu_ctrl, (uint64_t) p_descriptor, &va);
        p_descriptor = (gether_instance_tx_descriptor_t *) va;
    }
#endif                                 /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */

    if (p_instance_ctrl->p_tx_descriptor == p_descriptor)
    {
        if (p_descriptor->dt == GETHER_DESCRIPTOR_TYPE_FEMPTY)
        {
            err = FSP_SUCCESS;
        }
    }

    return err;
}                                      /* End of function R_GETHER_VersionGet() */

/*******************************************************************************************************************//**
 * @} (end addtogroup GETHER)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 * Implements @ref RZA::ether_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_NO_CALLBACK_MEMORY   p_callback is non-secure and p_callback_memory is either secure or NULL.
 **********************************************************************************************************************/
fsp_err_t R_GETHER_CallbackSet (ether_ctrl_t * const          p_api_ctrl,
                                void (                      * p_callback)(ether_callback_args_t *),
                                void * const                  p_context,
                                ether_callback_args_t * const p_callback_memory)
{
    ether_instance_ctrl_t * p_ctrl = (ether_instance_ctrl_t *) p_api_ctrl;

#if ETHER_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(GETHER_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

#if BSP_TZ_SECURE_BUILD && BSP_FEATURE_ETHER_SUPPORTS_TZ_SECURE

    /* Get security state of p_callback */
    bool callback_is_secure =
        (NULL == cmse_check_address_range((void *) p_callback, sizeof(void *), CMSE_AU_NONSECURE));

 #if ETHER_CFG_PARAM_CHECKING_ENABLE

    /* In secure projects, p_callback_memory must be provided in non-secure space if p_callback is non-secure */
    ether_callback_args_t * const p_callback_memory_checked = cmse_check_pointed_object(p_callback_memory,
                                                                                        CMSE_AU_NONSECURE);
    FSP_ERROR_RETURN(callback_is_secure || (NULL != p_callback_memory_checked), FSP_ERR_NO_CALLBACK_MEMORY);
 #endif
#endif

    /* Store callback and context */
#if BSP_TZ_SECURE_BUILD && BSP_FEATURE_ETHER_SUPPORTS_TZ_SECURE
    p_ctrl->p_callback = callback_is_secure ? p_callback :
                         (void (*)(ether_callback_args_t *))cmse_nsfptr_create(p_callback);
#else
    p_ctrl->p_callback = p_callback;
#endif
    p_ctrl->p_context         = p_context;
    p_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

#if (GETHER_CFG_PARAM_CHECKING_ENABLE)

/*******************************************************************************************************************//**
 * @brief Parameter error check function for open.
 *
 * @param[in] p_instance_ctrl   Pointer to the control block for the channel
 * @param[in] p_cfg             Pointer to the configuration structure specific to UART mode
 *
 * @retval  FSP_SUCCESS                  No parameter error found
 * @retval  FSP_ERR_ASSERTION            Pointer to ETHER control block or configuration structure is NULL
 * @retval  FSP_ERR_INVALID_CHANNEL      Invalid channel number is given.
 * @retval  FSP_ERR_INVALID_POINTER      Pointer to MAC address is NULL.
 * @retval  FSP_ERR_INVALID_ARGUMENT     Irq number lower then 0.
 **********************************************************************************************************************/
static fsp_err_t gether_open_param_check (ether_instance_ctrl_t const * const p_instance_ctrl,
                                          ether_cfg_t const * const           p_cfg)
{
    address_size_t descriptor_base_address;
    address_size_t descriptor_check_address;
    ether_instance_extend_t * p_instance_extend;

    FSP_ASSERT(p_instance_ctrl);
    GETHER_ERROR_RETURN((NULL != p_cfg), FSP_ERR_INVALID_POINTER);
    GETHER_ERROR_RETURN((NULL != p_cfg->p_mac_address), FSP_ERR_INVALID_POINTER);
    GETHER_ERROR_RETURN((NULL != p_cfg->p_extend), FSP_ERR_INVALID_POINTER);
    GETHER_ERROR_RETURN((BSP_FEATURE_GETHER_MAX_CHANNELS > p_cfg->channel), FSP_ERR_INVALID_CHANNEL);
    GETHER_ERROR_RETURN((0 <= p_cfg->irq), FSP_ERR_INVALID_ARGUMENT);
    GETHER_ERROR_RETURN((p_cfg->padding <= ETHER_PADDING_3BYTE), FSP_ERR_INVALID_ARGUMENT);
    GETHER_ERROR_RETURN((NULL != p_cfg->p_extend), FSP_ERR_INVALID_POINTER);

    if (p_cfg->padding != ETHER_PADDING_DISABLE)
    {
        GETHER_ERROR_RETURN((p_cfg->padding_offset <= GETHER_MAXIMUM_PADDING_OFFSET), FSP_ERR_INVALID_ARGUMENT);
    }

    if (p_cfg->zerocopy == ETHER_ZEROCOPY_DISABLE)
    {
        GETHER_ERROR_RETURN((p_cfg->pp_ether_buffers != NULL), FSP_ERR_INVALID_ARGUMENT);
    }

    /*
     * Check Descriptor address
     */
    p_instance_extend        = (ether_instance_extend_t *) p_cfg->p_extend;
    descriptor_base_address  = (address_size_t) g_gether_basic_descriptors;
    descriptor_base_address &= GETHER_ADDRESS_UPPER_BITS_MASK;

    /* The end of base descriptor */
    descriptor_check_address = (address_size_t) g_gether_basic_descriptors[BSP_FEATURE_GETHER_MAX_CHANNELS];
    descriptor_check_address--;
    descriptor_check_address &= GETHER_ADDRESS_UPPER_BITS_MASK;
    GETHER_ERROR_RETURN((descriptor_base_address == descriptor_check_address), FSP_ERR_INVALID_POINTER);

    /* The top of TX descriptor */
    descriptor_check_address  = (address_size_t) p_instance_extend->p_tx_descriptor;
    descriptor_check_address &= GETHER_ADDRESS_UPPER_BITS_MASK;
    GETHER_ERROR_RETURN((descriptor_base_address == descriptor_check_address), FSP_ERR_INVALID_POINTER);

    /* The end of TX descriptor */
    descriptor_check_address = (address_size_t) &(p_instance_extend->p_tx_descriptor[p_cfg->num_tx_descriptors + 1]);
    descriptor_check_address--;
    descriptor_check_address &= GETHER_ADDRESS_UPPER_BITS_MASK;
    GETHER_ERROR_RETURN((descriptor_base_address == descriptor_check_address), FSP_ERR_INVALID_POINTER);

    /* The top of RX descriptor */
    descriptor_check_address  = (address_size_t) p_instance_extend->p_rx_descriptor;
    descriptor_check_address &= GETHER_ADDRESS_UPPER_BITS_MASK;
    GETHER_ERROR_RETURN((descriptor_base_address == descriptor_check_address), FSP_ERR_INVALID_POINTER);

    /* The end of RX descriptor */
    descriptor_check_address = (address_size_t) &(p_instance_extend->p_rx_descriptor[p_cfg->num_rx_descriptors + 1]);
    descriptor_check_address--;
    descriptor_check_address &= GETHER_ADDRESS_UPPER_BITS_MASK;
    GETHER_ERROR_RETURN((descriptor_base_address == descriptor_check_address), FSP_ERR_INVALID_POINTER);

    /* The top of buffer */
    descriptor_check_address  = (address_size_t) p_cfg->pp_ether_buffers;
    descriptor_check_address &= GETHER_ADDRESS_UPPER_BITS_MASK;
    GETHER_ERROR_RETURN((descriptor_base_address == descriptor_check_address), FSP_ERR_INVALID_POINTER);

    /* The end of buffer */
    descriptor_check_address =
        (address_size_t) &(p_cfg->pp_ether_buffers[p_cfg->num_tx_descriptors + p_cfg->num_rx_descriptors + 1]);
    descriptor_check_address--;
    descriptor_check_address &= GETHER_ADDRESS_UPPER_BITS_MASK;
    GETHER_ERROR_RETURN((descriptor_base_address == descriptor_check_address), FSP_ERR_INVALID_POINTER);

    /* Upper limit of the descriptor address */
    GETHER_ERROR_RETURN((descriptor_base_address < GETHER_DECRIPTOR_MAX_ADDRESS), FSP_ERR_INVALID_POINTER);

    return FSP_SUCCESS;
}

#endif

/***********************************************************************************************************************
 * Function Name: gether_reset_mac
 * Description  : The EDMAC and EtherC are reset through the software reset.
 * Arguments    : channel -
 *                    ETHERC channel number
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_reset_mac (R_ETHER0_Type * const p_reg)
{
    uint32_t clock_freq_hz = 0U;
    p_reg->CCC_b.OPC = GETHER_OPC_MODE_RESET;

    /*
     * Waiting time until the initialization of ETHERC and EDMAC is completed is 64 cycles
     * in the clock conversion of an internal bus of EDMAC.
     *//* Call CGC function to obtain current PCLKB clock frequency. */
    clock_freq_hz = R_FSP_SystemClockHzGet(FSP_PRIV_CLOCK_P0CLK);

    R_BSP_SoftwareDelay(GETHER_ETHERC_INITIALIZATION_WAIT_CYCLE * BSP_DELAY_UNITS_SECONDS / clock_freq_hz + 1,
                        BSP_DELAY_UNITS_MICROSECONDS);

    p_reg->CCC_b.OPC = GETHER_OPC_MODE_CONFIG;
}                                      /* End of function gether_reset_mac() */

/***********************************************************************************************************************
 * Function Name: gether_init_rx_descriptors
 * Description  : The EDMAC descriptors and the driver buffers are initialized.
 * Arguments    : channel -
 *                    ETHERC channel number
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_init_rx_descriptors (ether_instance_ctrl_t * const p_instance_ctrl)
{
    uint32_t i;
    ether_instance_extend_t * p_instance_extend = (ether_instance_extend_t *) p_instance_ctrl->p_gether_cfg->p_extend;

#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    uint64_t pa = 0;
#endif                                 /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
    uint32_t tx_num = p_instance_ctrl->p_gether_cfg->num_tx_descriptors;

    /* NOTE: The first TX descriptor is dpecified to the value of DBTL register.
     *       The first RX descriprot is dpecified to (the value of DBTL register + 0x40).
     *       This driver is designed that:
     *           num_tx_descriptors = 7 (fixed).
     *           (num_tx_descriptors + 1)th TX descriptor is the link of the 1st TX descriptor.
     *           (num_rx_descriptors + 1)th RX descriptor is the link of the 1st RX descriptor.
     *           (num_rx_descriptors + 2)th RX descriptor is the end mark of the descriptors.
     */
    p_instance_ctrl->p_rx_descriptor = p_instance_extend->p_rx_descriptor;

    /* Initialize RX descriptors */
    for (i = 0; i < (p_instance_ctrl->p_gether_cfg->num_rx_descriptors); i++)
    {
        p_instance_ctrl->p_rx_descriptor[i].die = GETHER_DECRIPTOR_INT_RX;
        p_instance_ctrl->p_rx_descriptor[i].ti  = 0;
        p_instance_ctrl->p_rx_descriptor[i].ei  = 0;
        p_instance_ctrl->p_rx_descriptor[i].ps  = 0;
        p_instance_ctrl->p_rx_descriptor[i].msc = 0;
        p_instance_ctrl->p_rx_descriptor[i].ds  = p_instance_ctrl->p_gether_cfg->ether_buffer_size &
                                                  GETHER_MASK_12BITS;
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
        R_MMU_VAtoPA(&g_mmu_ctrl, (uint64_t) p_instance_ctrl->p_gether_cfg->pp_ether_buffers[tx_num + i], &pa);
        p_instance_ctrl->p_rx_descriptor[i].dptr = (uint32_t) (address_size_t) pa;
#else                                  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
        p_instance_ctrl->p_rx_descriptor[i].dptr = (uint32_t) (address_size_t)
                                                   p_instance_ctrl->p_gether_cfg->pp_ether_buffers[tx_num + i];
#endif  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
        p_instance_ctrl->p_rx_descriptor[i].dt = GETHER_DESCRIPTOR_TYPE_FEMPTY;
    }

    p_instance_ctrl->p_rx_descriptor[i].die = 0;
    p_instance_ctrl->p_rx_descriptor[i].ti  = 0;
    p_instance_ctrl->p_rx_descriptor[i].ei  = 0;
    p_instance_ctrl->p_rx_descriptor[i].ps  = 0;
    p_instance_ctrl->p_rx_descriptor[i].msc = 0;
    p_instance_ctrl->p_rx_descriptor[i].ds  = 0;
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    R_MMU_VAtoPA(&g_mmu_ctrl, (uint64_t) &(p_instance_ctrl->p_rx_descriptor[0]), &pa);
    p_instance_ctrl->p_rx_descriptor[i].dptr = (uint32_t) (address_size_t) pa;
#else
    p_instance_ctrl->p_rx_descriptor[i].dptr = (uint32_t) (address_size_t) &(p_instance_ctrl->p_rx_descriptor[0]);
#endif
    p_instance_ctrl->p_rx_descriptor[i].dt = GETHER_DESCRIPTOR_TYPE_LINKFIX;
}                                      /* End of function gether_init_descriptors() */

/***********************************************************************************************************************
 * Function Name: gether_init_descriptors
 * Description  : The EDMAC descriptors and the driver buffers are initialized.
 * Arguments    : channel -
 *                    ETHERC channel number
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_init_descriptors (ether_instance_ctrl_t * const p_instance_ctrl)
{
    uint32_t i;

#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    uint64_t pa = 0;
#endif                                 /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
    ether_instance_extend_t * p_instance_extend = (ether_instance_extend_t *) p_instance_ctrl->p_gether_cfg->p_extend;

    /* Initialize the descriptors */

    p_instance_ctrl->p_rx_descriptor = p_instance_extend->p_rx_descriptor;
    p_instance_ctrl->p_tx_descriptor = p_instance_extend->p_tx_descriptor;

    /* NOTE: The first TX descriptor is dpecified to the value of DBTL register.
     *       The first RX descriprot is dpecified to (the value of DBTL register + 0x20).
     */

    /* Initialize Base descriptors */
    g_gether_basic_descriptors[p_instance_ctrl->p_gether_cfg->channel][GETHER_BASE_DESCRIPTOR_TX_OFFSET].dt =
        GETHER_DESCRIPTOR_TYPE_LINKFIX;
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    R_MMU_VAtoPA(&g_mmu_ctrl, (uint64_t) &(p_instance_extend->p_tx_descriptor[0]), &pa);
    g_gether_basic_descriptors[p_instance_ctrl->p_gether_cfg->channel][GETHER_BASE_DESCRIPTOR_TX_OFFSET].dptr =
        (uint32_t) (address_size_t) pa;
#else                                  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
    g_gether_basic_descriptors[p_instance_ctrl->p_gether_cfg->channel][GETHER_BASE_DESCRIPTOR_TX_OFFSET].dptr =
        (uint32_t) (address_size_t) &(p_instance_extend->p_tx_descriptor[0]);
#endif  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
    g_gether_basic_descriptors[p_instance_ctrl->p_gether_cfg->channel][GETHER_BASE_DESCRIPTOR_RX_OFFSET].dt =
        GETHER_DESCRIPTOR_TYPE_LINKFIX;
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    R_MMU_VAtoPA(&g_mmu_ctrl, (uint64_t) &(p_instance_extend->p_rx_descriptor[0]), &pa);
    g_gether_basic_descriptors[p_instance_ctrl->p_gether_cfg->channel][GETHER_BASE_DESCRIPTOR_RX_OFFSET].dptr =
        (uint32_t) (address_size_t) pa;
#else                                  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
    g_gether_basic_descriptors[p_instance_ctrl->p_gether_cfg->channel][GETHER_BASE_DESCRIPTOR_RX_OFFSET].dptr =
        (uint32_t) (address_size_t) &(p_instance_extend->p_rx_descriptor[0]);
#endif  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */

    /* Initialize TX descriptors */
    for (i = 0; i < (p_instance_ctrl->p_gether_cfg->num_tx_descriptors); i++)
    {
        p_instance_ctrl->p_tx_descriptor[i].die = GETHER_DECRIPTOR_INT_TX;
        p_instance_ctrl->p_tx_descriptor[i].tag = 0;
        p_instance_ctrl->p_tx_descriptor[i].msr = 0;
        p_instance_ctrl->p_tx_descriptor[i].ds  = 0;
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
        R_MMU_VAtoPA(&g_mmu_ctrl, (uint64_t) p_instance_ctrl->p_gether_cfg->pp_ether_buffers[i], &pa);
        p_instance_ctrl->p_tx_descriptor[i].dptr = (uint32_t) (address_size_t) pa;
#else                                  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
        p_instance_ctrl->p_tx_descriptor[i].dptr = (uint32_t) (address_size_t)
                                                   p_instance_ctrl->p_gether_cfg->pp_ether_buffers[i];
#endif  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
        p_instance_ctrl->p_tx_descriptor[i].dt = GETHER_DESCRIPTOR_TYPE_FEMPTY;
    }

    p_instance_ctrl->p_tx_descriptor[i + 0].die = GETHER_DECRIPTOR_INT_TX;
    p_instance_ctrl->p_tx_descriptor[i + 0].tag = 0;
    p_instance_ctrl->p_tx_descriptor[i + 0].msr = 0;
    p_instance_ctrl->p_tx_descriptor[i + 0].ds  = 0;
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    R_MMU_VAtoPA(&g_mmu_ctrl, (uint64_t) &(p_instance_ctrl->p_tx_descriptor[0]), &pa);
    p_instance_ctrl->p_tx_descriptor[i + 0].dptr = (uint32_t) (address_size_t) pa;
#else                                  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
    p_instance_ctrl->p_tx_descriptor[i + 0].dptr = (uint32_t) (address_size_t)
                                                   &(p_instance_ctrl->p_tx_descriptor[0]);
#endif  /* BSP_FEATURE_BSP_HAS_MMU_SUPPORT */
    p_instance_ctrl->p_tx_descriptor[i + 0].dt = GETHER_DESCRIPTOR_TYPE_LINKFIX;

    gether_init_rx_descriptors(p_instance_ctrl);
}                                      /* End of function gether_init_descriptors() */

/***********************************************************************************************************************
 * Function Name: gether_init_buffers
 * Description  : The driver buffers are initialized.
 * Arguments    : p_instance_ctrl -
 *                    ETHERC control block.
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_init_buffers (ether_instance_ctrl_t * const p_instance_ctrl)
{
    uint32_t i;
    uint32_t buffer_num;

    if (NULL != p_instance_ctrl->p_gether_cfg->pp_ether_buffers)
    {
        if (ETHER_ZEROCOPY_DISABLE == p_instance_ctrl->p_gether_cfg->zerocopy)
        {
            buffer_num =
                (uint32_t) (p_instance_ctrl->p_gether_cfg->num_tx_descriptors +
                            p_instance_ctrl->p_gether_cfg->num_rx_descriptors);
        }
        else
        {
            buffer_num = (uint32_t) p_instance_ctrl->p_gether_cfg->num_rx_descriptors;
        }

        for (i = 0; i < buffer_num; i++)
        {
            memset(p_instance_ctrl->p_gether_cfg->pp_ether_buffers[i],
                   0x00,
                   p_instance_ctrl->p_gether_cfg->ether_buffer_size);
        }
    }
}                                      /* End of function gether_init_buffers() */

/***********************************************************************************************************************
 * Function Name: gether_config_ethernet
 * Description  : Configure the Ethernet Controller (EtherC) and the Ethernet
 *                Direct Memory Access controller (EDMAC).
 * Arguments    : channel -
 *                    ETHERC channel number
 *                mode -
 *                   The operational mode is specified.
 *                   NO_USE_MAGIC_PACKET_DETECT (0) - Communicate mode usually
 *                   USE_MAGIC_PACKET_DETECT    (1) - Magic packet detection mode
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_config_ethernet (ether_instance_ctrl_t const * const p_instance_ctrl, const uint8_t mode)
{
    R_EMAC0_Type * p_reg_emac;
    R_ETHER0_Type * p_reg_ether;

#if (GETHER_CFG_PARAM_CHECKING_ENABLE)

    /* Check argument */
    if ((NULL == p_instance_ctrl) || (GETHER_OPEN != p_instance_ctrl->open))
    {
        return;
    }
#endif

    p_reg_emac  = (R_EMAC0_Type *) p_instance_ctrl->p_reg_emac;
    p_reg_ether = (R_ETHER0_Type *) p_instance_ctrl->p_reg_ether;

    /* Magic packet detection mode */
    if (GETHER_USE_MAGIC_PACKET_DETECT == mode)
    {
#if (GETHER_CFG_USE_LINKSTA == 1)
        p_reg_emac->CXR22 = 0;
#elif (GETHER_CFG_USE_LINKSTA == 0)
#endif
    }
    /* Normal mode */
    else
    {
#if (GETHER_CFG_USE_LINKSTA == 1)

        /* LINK Signal Change Interrupt Enable */
        p_reg_emac->CXR21_b.LINKI  = 1;
        p_reg_emac->CXR22_b.LINKIM = 1;
#endif
    }

    /* Ethernet length 1514bytes + CRC and intergap is 96-bit time */
    p_reg_emac->CXR2A = GETHER_ETHERC_CXR2A_DEFAULT_VALUE; /* Ethernet length (1514bytes) + CRC(4byte) */

#if ((defined(__GNUC__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) || (defined(__ARMCC_VERSION) && \
    !defined(__ARM_BIG_ENDIAN)) || (defined(__ICCARM__) && (__LITTLE_ENDIAN__)))

    /* Set little endian mode */
    p_reg_ether->CCC_b.BOC = 0;
#endif
}                                      /* End of function gether_config_ethernet() */

/***********************************************************************************************************************
 * Function Name: gether_pause_resolution
 * Description  : Determines PAUSE frame generation and handling. Uses
 *                the resolution Table 28B-3 of IEEE 802.3-2008.
 * Arguments    : local_ability -
 *                    local PAUSE capability (2 least significant bits)
 *                partner_ability -
 *                    link partner PAUSE capability (2 least significant bits)
 *                *ptx_pause -
 *                    pointer to location to store the result of the table lookup for transmit
 *                    PAUSE. 1 is enable, 0 is disable.
 *                *prx_pause -
 *                    pointer to location to store the result of the table lookup for receive
 *                    PAUSE. 1 is enable, 0 is disable.
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_pause_resolution (uint32_t const local_ability,
                                     uint32_t const partner_ability,
                                     uint32_t     * ptx_pause,
                                     uint32_t     * prx_pause)
{
    uint32_t i;
    uint32_t ability_compare;

    /*
     * Arrange the bits so that they correspond to the Table 28B-3
     * of the IEEE 802.3 values.
     */
    ability_compare =
        (uint32_t) (((local_ability & GETHER_LINK_RESOLUTION_ABILITY_MASK) <<
                     GETHER_LINK_RESOLUTION_LOCAL_ABILITY_BITSHIFT) |
                    (partner_ability & GETHER_LINK_RESOLUTION_ABILITY_MASK));

    /* Walk through the look up table */
    for (i = 0; i < GETHER_PAUSE_TABLE_ENTRIES; i++)
    {
        if ((ability_compare & pause_resolution[i].mask) == pause_resolution[i].value)
        {
            (*ptx_pause) = pause_resolution[i].transmit;
            (*prx_pause) = pause_resolution[i].receive;

            return;
        }
    }
}                                      /* End of function gether_pause_resolution() */

/***********************************************************************************************************************
 * Function Name: gether_configure_mac
 * Description  : Software reset is executed, and ETHERC and EDMAC are configured.
 * Arguments    : channel -
 *                    ETHERC channel number
 *                mac_addr -
 *                    The MAC address of ETHERC
 *                mode -
 *                    The operational mode is specified.
 *                    NO_USE_MAGIC_PACKET_DETECT (0) - Communicate mode usually
 *                    USE_MAGIC_PACKET_DETECT    (1) - Magic packet detection mode
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_configure_mac (ether_instance_ctrl_t * const p_instance_ctrl,
                                  const uint8_t                 mac_addr[],
                                  const uint8_t                 mode)
{
    R_EMAC0_Type * p_reg_emac;
    uint32_t mac_h;
    uint32_t mac_l;

#if (GETHER_CFG_PARAM_CHECKING_ENABLE)

    /* Check argument */
    if ((NULL == p_instance_ctrl) || (GETHER_OPEN != p_instance_ctrl->open))
    {
        return;
    }
#endif

    p_reg_emac = (R_EMAC0_Type *) p_instance_ctrl->p_reg_emac;

    /* Set MAC address */
    mac_h = (((((uint32_t) mac_addr[0] << 24) | ((uint32_t) mac_addr[1] << 16)) | ((uint32_t) mac_addr[2] << 8)) |
             (uint32_t) mac_addr[3]);

    mac_l = (((uint32_t) mac_addr[4] << 8) | (uint32_t) mac_addr[5]);

    p_reg_emac->CXR24 = mac_h;
    p_reg_emac->CXR25 = mac_l;

    /* Initialize receive and transmit descriptors */
    gether_init_descriptors(p_instance_ctrl);

    /* Perform reset of hardware interface configuration */
    gether_config_ethernet(p_instance_ctrl, mode);
}                                      /* End of function gether_configure_mac() */

/********************************************************************************************************************//**
 * @brief Determines the partner PHY capability through auto-negotiation process. The link abilities
 *        are handled to determine duplex, speed and flow control (PAUSE frames).
 *
 * @param[in] p_instance_ctrl           Pointer to the control block for the channel
 * @param[in] mode                      The operational mode is specified.
 *                                      NO_USE_MAGIC_PACKET_DETECT (0) - Communicate mode usually
 *                                      USE_MAGIC_PACKET_DETECT    (1) - Magic packet detection mode
 * @retval  FSP_SUCCESS                 Processing completed successfully.
 * @retval  FSP_ERR_ASSERTION           Pointer to ETHER control block or configuration structure is NULL.
 * @retval  FSP_ERR_NOT_OPEN            The control block has not been opened.
 * @retval  FSP_ERR_ETHER_ERROR_LINK    Auto-negotiation of PHY-LSI is not completed
 *                                      or result of Auto-negotiation is abnormal.
 *
 ***********************************************************************************************************************/
static fsp_err_t gether_do_link (ether_instance_ctrl_t * const p_instance_ctrl, const uint8_t mode)
{
    fsp_err_t err;
    R_EMAC0_Type * p_reg_emac;

    uint32_t link_speed_duplex  = 0;
    uint32_t local_pause_bits   = 0;
    uint32_t partner_pause_bits = 0;
    uint32_t transmit_pause_set = 0;
    uint32_t receive_pause_set  = 0;
    uint32_t full_duplex        = 0;
    fsp_err_t link_result;

#if (GETHER_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GETHER_ERROR_RETURN(GETHER_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_reg_emac = (R_EMAC0_Type *) p_instance_ctrl->p_reg_emac;

    /* Set the link status */
    link_result = p_instance_ctrl->p_gether_cfg->p_ether_phy_instance->p_api->linkPartnerAbilityGet(
        p_instance_ctrl->p_gether_cfg->p_ether_phy_instance->p_ctrl,
        &link_speed_duplex,
        &local_pause_bits,
        &partner_pause_bits);

    if (FSP_SUCCESS == link_result)
    {
        switch (link_speed_duplex)
        {
            /* Half duplex link */
            case ETHER_PHY_LINK_SPEED_100H:
            {
                p_reg_emac->CXR20_b.DPM   = 0;
                p_reg_emac->CXR2D_b.SPEED = GETHER_CXR2D_SPEED_100MBPS;
                err = FSP_SUCCESS;
                break;
            }

            case ETHER_PHY_LINK_SPEED_10H:
            {
                p_reg_emac->CXR20_b.DPM   = 0;
                p_reg_emac->CXR2D_b.SPEED = GETHER_CXR2D_SPEED_10MBPS;
                err = FSP_SUCCESS;
                break;
            }

            /* Full duplex link */
            case ETHER_PHY_LINK_SPEED_1000F:
            {
                p_reg_emac->CXR20_b.DPM   = 1;
                p_reg_emac->CXR2D_b.SPEED = GETHER_CXR2D_SPEED_1000MBPS;
                full_duplex               = 1;
                err = FSP_SUCCESS;
                break;
            }

            case ETHER_PHY_LINK_SPEED_100F:
            {
                p_reg_emac->CXR20_b.DPM   = 1;
                p_reg_emac->CXR2D_b.SPEED = GETHER_CXR2D_SPEED_100MBPS;
                full_duplex               = 1;
                err = FSP_SUCCESS;
                break;
            }

            case ETHER_PHY_LINK_SPEED_10F:
            {
                p_reg_emac->CXR20_b.DPM   = 1;
                p_reg_emac->CXR2D_b.SPEED = GETHER_CXR2D_SPEED_10MBPS;
                full_duplex               = 1;
                err = FSP_SUCCESS;
                break;
            }

            default:
            {
                err = FSP_ERR_ETHER_ERROR_LINK;
                break;
            }
        }

        /* At the communicate mode usually */
        if (FSP_SUCCESS == err)
        {
            if (GETHER_NO_USE_MAGIC_PACKET_DETECT == mode)
            {
                /* When pause frame is used */
                if ((full_duplex) && (ETHER_FLOW_CONTROL_ENABLE == p_instance_ctrl->p_gether_cfg->flow_control))
                {
                    /* Set automatic PAUSE for 512 bit-time */
                    p_reg_emac->CXR71 = GETHER_ETHERC_APR_MAXIMUM_VALUE;

                    /* Set unlimited retransmit of PAUSE frames */
                    p_reg_emac->CXR81 = 0;

                    /**
                     * Enable PAUSE for full duplex link depending on
                     * the pause resolution results
                     */
                    gether_pause_resolution(local_pause_bits,
                                            partner_pause_bits,
                                            &transmit_pause_set,
                                            &receive_pause_set);

                    if (GETHER_PAUSE_XMIT_ON == transmit_pause_set)
                    {
                        /* Enable automatic PAUSE frame transmission */
                        p_reg_emac->CXR20_b.TZPF = 1;
                    }
                    else
                    {
                        /* Disable automatic PAUSE frame transmission */
                        p_reg_emac->CXR20_b.TZPF = 0;
                    }

                    if (GETHER_PAUSE_RECV_ON == receive_pause_set)
                    {
                        /* Enable reception of PAUSE frames */
                        p_reg_emac->CXR20_b.RXF = 1;
                    }
                    else
                    {
                        /* Disable reception of PAUSE frames */
                        p_reg_emac->CXR20_b.RXF = 0;
                    }
                }
                /* When pause frame is not used */
                else
                {
                    /* Disable PAUSE for half duplex link */
                    p_reg_emac->CXR20_b.TXF = 0;
                    p_reg_emac->CXR20_b.RXF = 0;
                }

                /* Set the promiscuous mode bit */
                p_reg_emac->CXR20_b.PRM = p_instance_ctrl->p_gether_cfg->promiscuous;
            }
            /* At the magic packet detection mode */
            else
            {
                /* Because data is not transmitted for the magic packet detection waiting,
                 * only the reception is permitted. */
                p_reg_emac->CXR20_b.RPE = 1;

                /*
                 * The reception function of EDMAC keep invalidity
                 * because the receive data don't need to be read when the magic packet detection mode.
                 */
            }
        }
    }
    else
    {
        err = FSP_ERR_ETHER_ERROR_LINK;
    }

    return err;
}                                      /* End of function gether_do_link() */

/***********************************************************************************************************************
 * Function Name: gether_check_magic_packet_detection_bit
 * Description  :
 * Arguments    : ether_instance_ctrl_t const * const p_instance_ctrl
 * Return Value : 1: Magic Packet detection is enabled.
 *                0: Magic Packet detection is disabled.
 ***********************************************************************************************************************/
static uint8_t gether_check_magic_packet_detection_bit (__attribute__(
                                                            (unused)) ether_instance_ctrl_t const * const p_instance_ctrl)
{
    uint8_t ret = 0;

    return ret;
}                                      /* End of function gether_check_magic_packet_detection_bit() */

/*******************************************************************************************************************//**
 * @brief Verifies the Etherent link is up or not.
 *
 * @param[in] p_instance_ctrl   Pointer to the control block for the channel
 *
 * @retval  FSP_SUCCESS:                  Link is up
 * @retval  FSP_ERR_ETHER_ERROR_LINK:     Link is down
 * @retval  FSP_ERR_ETHER_PHY_ERROR_LINK  Initialization of PHY-LSI failed.
 **********************************************************************************************************************/
static fsp_err_t gether_link_status_check (ether_instance_ctrl_t const * const p_instance_ctrl)
{
    fsp_err_t err = FSP_SUCCESS;
    fsp_err_t link_status;

    link_status = p_instance_ctrl->p_gether_cfg->p_ether_phy_instance->p_api->linkStatusGet(
        p_instance_ctrl->p_gether_cfg->p_ether_phy_instance->p_ctrl);

    if (FSP_ERR_ETHER_PHY_ERROR_LINK == link_status)
    {
        /* Link is down */
        err = FSP_ERR_ETHER_ERROR_LINK;
    }
    else
    {
        /* Link is up */
        err = FSP_SUCCESS;
    }

    return err;
}                                      /* End of function gether_link_status_check() */

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_instance_ctrl      Pointer to ether instance control block
 * @param[in]     p_callback_args      Pointer to callback args
 **********************************************************************************************************************/
static void ether_call_callback (ether_instance_ctrl_t * p_instance_ctrl, ether_callback_args_t * p_callback_args)
{
    ether_callback_args_t args;

    /* Store callback arguments in memory provided by user if available.  This allows callback arguments to be
     * stored in non-secure memory so they can be accessed by a non-secure callback function. */
    ether_callback_args_t * p_args = p_instance_ctrl->p_callback_memory;
    if (NULL == p_args)
    {
        /* Store on stack */
        p_args = &args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt. */
        args = *p_args;
    }

    p_args->event       = p_callback_args->event;
    p_args->status_ecsr = p_callback_args->status_ecsr;
    p_args->status_eesr = p_callback_args->status_eesr;
    p_args->channel     = p_instance_ctrl->p_gether_cfg->channel;
    p_args->p_context   = p_instance_ctrl->p_context;

#if BSP_TZ_SECURE_BUILD && BSP_FEATURE_ETHER_SUPPORTS_TZ_SECURE

    /* p_callback can point to a secure function or a non-secure function. */
    if (!cmse_is_nsfptr(p_instance_ctrl->p_callback))
    {
        /* If p_callback is secure, then the project does not need to change security state. */
        p_instance_ctrl->p_callback(p_args);
    }
    else
    {
        /* If p_callback is Non-secure, then the project must change to Non-secure state in order to call the callback. */
        ether_prv_ns_callback p_callback = (ether_prv_ns_callback) (p_instance_ctrl->p_callback);
        p_callback(p_args);
    }

#else

    /* If the project is not Trustzone Secure, then it will never need to change security state in order to call the callback. */
    p_instance_ctrl->p_callback(p_args);
#endif

    if (NULL != p_instance_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_instance_ctrl->p_callback_memory = args;
    }
}

/***********************************************************************************************************************
 * Function Name: gether_eint_isr
 * Description  : Interrupt handler for Ethernet receive and transmit interrupts.
 * Arguments    : none
 * Return Value : none
 ***********************************************************************************************************************/
void gether_eint_isr (IRQn_Type const irq)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    uint32_t status_ecsr;
    uint32_t status_eesr;

    ether_callback_args_t callback_arg;
    R_EMAC0_Type * p_reg_emac;
    R_ETHER0_Type * p_reg_ether;
    R_TOE0_Type * p_reg_toe;

    ether_instance_ctrl_t * p_instance_ctrl = (ether_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    p_reg_emac  = (R_EMAC0_Type *) p_instance_ctrl->p_reg_emac;
    p_reg_ether = (R_ETHER0_Type *) p_instance_ctrl->p_reg_ether;
    p_reg_toe   = (R_TOE0_Type *) p_instance_ctrl->p_reg_toe;

    status_ecsr = p_reg_ether->EIS;
    status_eesr = (uint32_t) (p_reg_ether->RIS0_b.FRF << GETHER_ETHERC_INTERRUPT_FR) |   /* Frame Receive  bit  */
                  (uint32_t) (p_reg_ether->RIS2_b.RFFF << GETHER_ETHERC_INTERRUPT_RDE) | /* Receive Descriptor Empty bit  */
                  (uint32_t) (p_reg_ether->RIS2_b.QFF << GETHER_ETHERC_INTERRUPT_RFOF) | /* Receive Fifo Overflow Flag bit */
                  (uint32_t) (p_reg_ether->TIS_b.FTF << GETHER_ETHERC_INTERRUPT_TC)      /* Transmit Complete bit */
    ;

    /* Set/Clear Flags */
    if (p_reg_ether->ISS_b.MM == 1)
    {
        while ((p_reg_emac->CXR21 & p_reg_emac->CXR22) != 0)
        {
            p_reg_emac->CXR21 = p_reg_emac->CXR22;
        }
    }

    if (p_reg_ether->ISS_b.EM == 1)
    {
        while (p_reg_ether->EIS_b.QFS != 0)
        {
            /* Restart Receive Queue */
            /* Stop DMA */
            p_reg_ether->DLR_b.LBA4 = 1;

            /* initialize RX descriptors */
            gether_init_rx_descriptors(p_instance_ctrl);

            /* Clear QFF */
            while (p_reg_ether->RIS2_b.QFF != 0)
            {
                p_reg_ether->RIS2_b.QFF = 0;
            }

            /* Start DMA */
            p_reg_ether->DLR_b.LBA4 = 0;
        }
    }

    while (p_reg_ether->DIS != 0)
    {
        p_reg_ether->DIS = 0;
    }

    while (p_reg_toe->CSR20 != 0)
    {
        p_reg_toe->CSR20 = 0;
    }

    while (p_reg_ether->TIS != 0)
    {
        p_reg_ether->TIS = 0;
    }

    while (p_reg_ether->RIS0 != 0)
    {
        p_reg_ether->RIS0 = 0;
    }

    while (p_reg_ether->RIS2 != 0)
    {
        p_reg_ether->RIS2 = 0;
    }

    while (p_reg_toe->CSR0_b.RPE == 0)
    {
        p_reg_toe->CSR0_b.RPE = 1;
    }

    while (p_reg_toe->CSR0_b.TPE == 0)
    {
        p_reg_toe->CSR0_b.TPE = 1;
    }

    /* Callback : Interrupt handler */
    if (NULL != p_instance_ctrl->p_callback)
    {
        callback_arg.channel     = p_instance_ctrl->p_gether_cfg->channel;
        callback_arg.event       = ETHER_EVENT_INTERRUPT;
        callback_arg.status_ecsr = status_ecsr;
        callback_arg.status_eesr = status_eesr;
        callback_arg.p_context   = p_instance_ctrl->p_gether_cfg->p_context;
        ether_call_callback(p_instance_ctrl, &callback_arg);
    }

    /* Clear pending IRQ to make sure it doesn't fire again after exiting */
    R_BSP_IrqStatusClear(irq);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}                                      /* End of function gether_eint_isr() */

/***********************************************************************************************************************
 * Function Name: gether_enable_icu
 * Description  :
 * Arguments    : channel -
 *                    Ethernet channel number
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_enable_icu (ether_instance_ctrl_t * const p_instance_ctrl)
{
    /** Configure the Ethernet interrupt. */
    R_BSP_IrqCfgEnable(p_instance_ctrl->p_gether_cfg->irq,
                       p_instance_ctrl->p_gether_cfg->interrupt_priority,
                       p_instance_ctrl);
}                                      /* End of function gether_enable_icu() */

/***********************************************************************************************************************
 * Function Name: gether_disable_icu
 * Description  :
 * Arguments    : channel -
 *                    Ethernet channel number
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_disable_icu (ether_instance_ctrl_t * const p_instance_ctrl)
{
    /* Get IRQ number for EDMAC_EINT interrupt. */
    R_BSP_IrqDisable(p_instance_ctrl->p_gether_cfg->irq);
    R_FSP_IsrContextSet(p_instance_ctrl->p_gether_cfg->irq, NULL);
}                                      /* End of function gether_disable_icu() */
