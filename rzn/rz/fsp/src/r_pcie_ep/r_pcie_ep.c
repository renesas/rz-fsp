/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_pcie_ep.h"
#include "r_pcie_ep_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "PCIE" in ASCII, used to determine if channel is open. */
#define PCIE_EP_OPEN                                           (0x50434945UL)

/* End Point mode. */
#define PCIE_EP_PCIE_MODE_MODE_PORT_ENDPOINT                   (0)

/* PHY settings related values. */
#define PCIE_EP_PHY_XCFGD_SETTING_VALUE_NUM                    (27)
#define PCIE_EP_PHY_XCFGA_CMN_SETTING_VALUE_NUM                (16)
#define PCIE_EP_PHY_XCFGA_LA0_SETTING_VALUE_NUM                (6)
#define PCIE_EP_PHY_XCFGA_LA1_SETTING_VALUE_NUM                (6)

/* Interrupt settings values.
 * See Section "Initialization Procedure" in the RZ microprocessor Hardware Manual for more details. */
#define PCIE_EP_PEIS0_REG_SETTING_VALUE                        (0x00001200)
#define PCIE_EP_PEIS1_REG_SETTING_VALUE                        (0x00030303)
#define PCIE_EP_AMEIS_AMEIE_REG_SETTING_VALUE                  (0x00000F0F)
#define PCIE_EP_ASEIS1_ASEIE1_REG_SETTING_VALUE                (0x00000F03)
#define PCIE_EP_MSGRCVIS_SETTING_VALUE                         (0x010F0000)
#define PCIE_EP_MSGRCVIE_SETTING_VALUE                         (0x010A0000)

/* Clear PCIe Event Interrupt Status 2 register. */
#define PCIE_EP_PEIS2_REG_SETTING_VALUE                        (0x0001FF00)

/* Mask value when obtain the upper 3 bits from the PCSTAT1.LTSSM_STATE bits. */
#define PCIE_EP_PCI_EP_PCSTAT1_LTSSM_STATE_UPPER_3_BIT_MASK    (0x1CU) // b'1_1100

/* Shift value to obtain upper 32-bit address value from 64-bit address. */
#define PCIE_EP_SHIFT_FOR_UPPER_32BIT_VALUE                    (32U)

/* Wait 500 us or more to release the reset (RST_RSM_B). */
#define PCIE_EP_RELEASE_RESET_WAIT_US                          (500U)

/* Delay up to 500 ms before timing out waiting for each request . */
#define PCIE_EP_TIMEOUT_US                                     (500000U)

/* Offset address value for nth window setting register. */
#define PCIE_EP_WINDOW_SETTING_ADDR_NTH_OFFSET                 (0x20)

/* Offset address value for nth function window setting register. */
#define PCIE_EP_WINDOW_SETTING_ADDR_NTH_FUNCTION_OFFSET        (0x200)

/* Offset address value for nth function configuration register. */
#define PCIE_EP_CONFIG_REG_SETTING_ADDR_NTH_FUNCTION_OFFSET    (0x1000)

#define PCIE_EP_HARDWARE_REGISTER_WAIT(reg, required_value, timeout) \
    while ((timeout))                                                \
    {                                                                \
        if ((required_value) == (reg))                               \
        {                                                            \
            break;                                                   \
        }                                                            \
        (timeout)--;                                                 \
        R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MICROSECONDS);       \
    }

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/* PCI_EP_REQISS Type of Request. */
typedef enum e_pcie_ep_reqiss_tr_type
{
    PCIE_EP_REQISS_TR_TYPE_ZERO_LENGTH_READ                  = 0x00,
    PCIE_EP_REQISS_TR_TYPE_CONFIGURATION_READ_TYPE0          = 0x04,
    PCIE_EP_REQISS_TR_TYPE_CONFIGURATION_WRITE_TYPE0         = 0x05,
    PCIE_EP_REQISS_TR_TYPE_CONFIGURATION_READ_TYPE1          = 0x06,
    PCIE_EP_REQISS_TR_TYPE_CONFIGURATION_WRITE_TYPE1         = 0x07,
    PCIE_EP_REQISS_TR_TYPE_MESSAGE_REQUEST                   = 0x08,
    PCIE_EP_REQISS_TR_TYPE_MESSAGE_REQUEST_WITH_DATA_PALYOAD = 0x09,
} pcie_ep_reqiss_tr_type_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static inline void r_pcie_ep_write_protect_enable(pcie_ep_instance_ctrl_t * p_instance_ctrl, uint32_t bit_mask);
static inline void r_pcie_ep_write_protect_disable(pcie_ep_instance_ctrl_t * p_instance_ctrl, uint32_t bit_mask);

static void r_pcie_ep_xcfgd_setting(pcie_ep_instance_ctrl_t * p_instance_ctrl);
static void r_pcie_ep_xcfga_cmn_setting(pcie_ep_instance_ctrl_t * p_instance_ctrl);
static void r_pcie_ep_xcfga_la0_setting(pcie_ep_instance_ctrl_t * p_instance_ctrl);
static void r_pcie_ep_xcfga_la1_setting(pcie_ep_instance_ctrl_t * p_instance_ctrl);

static void r_pcie_ep_window_setting(pcie_ep_instance_ctrl_t * p_instance_ctrl);
static void r_pcie_ep_enable_irq(IRQn_Type const irq, uint32_t priority, void * p_context);
static void r_pcie_ep_disable_irq(IRQn_Type irq);
static void r_pcie_ep_interrupt_setup(pcie_ep_instance_ctrl_t * p_instance_ctrl);

static void r_pcie_ep_configuration_register_type0_init(pcie_ep_instance_ctrl_t * p_instance_ctrl);
static void r_pcie_ep_self_configuration_register_write(pcie_ep_instance_ctrl_t * p_instance_ctrl,
                                                        uint32_t                  register_number,
                                                        uint32_t                  register_value,
                                                        uint32_t                  function);
static void r_pcie_ep_self_configuration_register_read(pcie_ep_instance_ctrl_t * p_instance_ctrl,
                                                       uint32_t                  register_number,
                                                       uint32_t                  function,
                                                       uint32_t                * p_register_value);
static void r_pcie_ep_call_callback(pcie_ep_instance_ctrl_t * p_ctrl, pci_callback_args_t * p_args);

/***********************************************************************************************************************
 * ISR prototypes
 **********************************************************************************************************************/
void pcie_ep_message_receive_handler(void);
void pcie_ep_pme_turn_off_msg_event_handler(void);
void pcie_ep_power_off_indication_handler(void);
void pcie_ep_d3_event_handler(void);
void pcie_ep_flr_handler(void);
void pcie_ep_event_handler(void);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
static const uint32_t pcie_ep_phy_xcfgd_setting_value[PCIE_EP_PHY_XCFGD_SETTING_VALUE_NUM] =
{
    0x00002000,                        /* Setting value of XCFGD (offset 0x000) */
    0x00C00090,                        /* Setting value of XCFGD (offset 0x010) */
    0x000001E0,                        /* Setting value of XCFGD (offset 0x020) */
    0x02000000,                        /* Setting value of XCFGD (offset 0x030) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x040) */
    0x00520154,                        /* Setting value of XCFGD (offset 0x050) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x060) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x070) */
    0x44440000,                        /* Setting value of XCFGD (offset 0x080) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x090) */
    0x5DBB8000,                        /* Setting value of XCFGD (offset 0x0A0) */
    0x1E000000,                        /* Setting value of XCFGD (offset 0x0B0) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x0C0) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x0D0) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x0E0) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x0F0) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x100) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x110) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x120) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x130) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x140) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x150) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x160) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x170) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x180) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x190) */
    0x00000000                         /* Setting value of XCFGD (offset 0x1A0) */
};

static const uint32_t pcie_ep_phy_xcfga_cmn_setting_value[PCIE_EP_PHY_XCFGA_CMN_SETTING_VALUE_NUM] =
{
    0x00000080,                        /* Setting value of XCFGA_CMN (offset 0x000) */
    0x60940060,                        /* Setting value of XCFGA_CMN (offset 0x010) */
    0x00C12000,                        /* Setting value of XCFGA_CMN (offset 0x020) */
    0x60000BF8,                        /* Setting value of XCFGA_CMN (offset 0x030) */
    0x80834238,                        /* Setting value of XCFGA_CMN (offset 0x040) */
    0x00001118,                        /* Setting value of XCFGA_CMN (offset 0x050) */
    0x32040400,                        /* Setting value of XCFGA_CMN (offset 0x060) */
    0x21914064,                        /* Setting value of XCFGA_CMN (offset 0x070) */
    0x52948A03,                        /* Setting value of XCFGA_CMN (offset 0x080) */
    0x219CE008,                        /* Setting value of XCFGA_CMN (offset 0x090) */
    0x0C867F02,                        /* Setting value of XCFGA_CMN (offset 0x0A0) */
    0x40643228,                        /* Setting value of XCFGA_CMN (offset 0x0B0) */
    0x010A9291,                        /* Setting value of XCFGA_CMN (offset 0x0C0) */
    0xE044039C,                        /* Setting value of XCFGA_CMN (offset 0x0D0) */
    0x08800807,                        /* Setting value of XCFGA_CMN (offset 0x0E0) */
    0x00041002                         /* Setting value of XCFGA_CMN (offset 0x0F0) */
};

static const uint32_t pcie_ep_phy_xcfga_la0_setting_value[PCIE_EP_PHY_XCFGA_CMN_SETTING_VALUE_NUM] =
{
    0x08000000,                        /* Setting value of XCFGA_LN0 (offset 0x000) */
    0x00050400,                        /* Setting value of XCFGA_LN0 (offset 0x010) */
    0xE0003300,                        /* Setting value of XCFGA_LN0 (offset 0x020) */
    0xC0400FBF,                        /* Setting value of XCFGA_LN0 (offset 0x030) */
    0x960902A0,                        /* Setting value of XCFGA_LN0 (offset 0x040) */
    0x00020860                         /* Setting value of XCFGA_LN0 (offset 0x050) */
};

static const uint32_t pcie_ep_phy_xcfga_la1_setting_value[PCIE_EP_PHY_XCFGA_CMN_SETTING_VALUE_NUM] =
{
    0x08000000,                        /* Setting value of XCFGA_LN1 (offset 0x000) */
    0x00050400,                        /* Setting value of XCFGA_LN1 (offset 0x010) */
    0xE0003300,                        /* Setting value of XCFGA_LN1 (offset 0x020) */
    0xC0400FBF,                        /* Setting value of XCFGA_LN1 (offset 0x030) */
    0x960902A0,                        /* Setting value of XCFGA_LN1 (offset 0x040) */
    0x00020860                         /* Setting value of XCFGA_LN1 (offset 0x050) */
};

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/* Channel control struct array */
static pcie_ep_instance_ctrl_t * gp_instance_ctrl[2] = {NULL};

/** PCIE_EP implementation of PCI API. */
const pci_api_t g_pci_on_pcie_ep =
{
    .open                         = R_PCIE_EP_Open,
    .selfConfigurationRegisterGet = R_PCIE_EP_SelfConfigurationRegisterGet,
    .selfConfigurationRegisterSet = R_PCIE_EP_SelfConfigurationRegisterSet,
    .configurationRegisterWrite   = R_PCIE_EP_ConfigurationRegisterWrite,
    .configurationRegisterRead    = R_PCIE_EP_ConfigurationRegisterRead,
    .iORegisterWrite              = R_PCIE_EP_IORegisterWrite,
    .iORegisterRead               = R_PCIE_EP_IORegisterRead,
    .messageWrite                 = R_PCIE_EP_MessageWrite,
    .messageRead             = R_PCIE_EP_MessageRead,
    .intxAssert              = R_PCIE_EP_IntxAssert,
    .intxDeassert            = R_PCIE_EP_IntxDeassert,
    .linkStatusGet           = R_PCIE_EP_LinkStatusGet,
    .linkWidthChange         = R_PCIE_EP_LinkWidthChange,
    .linkSpeedChange         = R_PCIE_EP_LinkSpeedChange,
    .linkEqualizationRequest = R_PCIE_EP_LinkEqualizationRequest,
    .callbackSet             = R_PCIE_EP_CallbackSet,
    .close                        = R_PCIE_EP_Close,
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZN
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZN_PCIE_EP
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initialize the PCIE_EP API.  Implements @ref pci_api_t::open.
 *
 * @retval FSP_SUCCESS              PCIE_EP successfully initialized.
 * @retval FSP_ERR_ASSERTION        Invalid input argument.
 * @retval FSP_ERR_ALREADY_OPEN     Module is already open.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_EP_Open (pci_ctrl_t * const p_ctrl, pci_cfg_t const * const p_cfg)
{
    pcie_ep_instance_ctrl_t * p_instance_ctrl = (pcie_ep_instance_ctrl_t *) p_ctrl;
#if PCIE_EP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(PCIE_EP_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    pcie_ep_extended_cfg_t const * p_extend = (pcie_ep_extended_cfg_t const *) p_cfg->p_extend;

#if PCIE_EP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_extend->p_reg);
    FSP_ASSERT(NULL != p_extend->p_reg_spl);
#endif

    /* Initialize control structure.  */
    p_instance_ctrl->p_cfg     = p_cfg;
    p_instance_ctrl->channel   = p_cfg->channel;
    p_instance_ctrl->function  = p_cfg->function;
    p_instance_ctrl->p_reg     = (R_PCIE0_Type *) p_extend->p_reg;
    p_instance_ctrl->p_reg_phy = (R_PCIE_PHY_Type *) R_PCIE_PHY_BASE;
    p_instance_ctrl->p_reg_spl = (R_PCIE_SPL0_Type *) p_extend->p_reg_spl;
    p_instance_ctrl->p_reg_lnk = (R_PCIE_LNK_Type *) R_PCIE_LNK_BASE;

    if (p_instance_ctrl->function == 0)
    {
        /* Set the End-point mode and Channel Configuration.
         * Set MODE_PORT bit in the PCIE_MODE register to 0.
         * Set LINK_MASTER bits in the PCIE_LINKMODE register. */
        p_instance_ctrl->p_reg_spl->PCIE_MODE_b.MODE_PORT = PCIE_EP_PCIE_MODE_MODE_PORT_ENDPOINT;
        p_instance_ctrl->p_reg_lnk->PCIE_LINKMODE         = p_extend->link_mode;

        R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);

        /* Release the reset (ARESETn). */
        R_BSP_ModuleResetDisable(BSP_MODULE_RESET_PCIE);

        /* Release the module stop state. */
        R_BSP_MODULE_START(FSP_IP_PCIE, 0);

        R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

#ifdef BSP_FEATURE_BSP_SLAVE_STOP_SUPPORTED

        /* Release Slave Stop Function. */
        R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_SYSTEM);
        R_BSP_SlaveStopRelease(BSP_BUS_SLAVE_PCIE0);
        if (1 == p_instance_ctrl->channel)
        {
            R_BSP_SlaveStopRelease(BSP_BUS_SLAVE_PCIE1);
        }
        R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_SYSTEM);
#endif

        /* Release the reset (RST_LOAD_B, RST_CFG_B).
         * Set RST_LOAD_B (bit4) and RST_CFG_B (bit3) in the PCI_EP_RESET to 1.*/
        p_instance_ctrl->p_reg->PCI_EP_RESET |= R_PCIE0_PCI_EP_RESET_RST_LOAD_B_Msk |
                                                R_PCIE0_PCI_EP_RESET_RST_CFG_B_Msk;

        /* Setting of the PHY.
         * Set the PCI_PHY_XCFGDn register (n = 0 to 26), PCI_PHY_XCFGA_CMNn register (n = 0 to 15),
         * PCI_PHY_XCFGA_L0n register (n = 0 to 5) and PCI_PHY_XCFGA_L1n register (n = 0 to 5). */
        r_pcie_ep_xcfgd_setting(p_instance_ctrl);
        r_pcie_ep_xcfga_cmn_setting(p_instance_ctrl);
        r_pcie_ep_xcfga_la0_setting(p_instance_ctrl);
        r_pcie_ep_xcfga_la1_setting(p_instance_ctrl);

        /* Clear MODE_PORT bit to set Endpoint setting. */
        p_instance_ctrl->p_reg->PCI_EP_PCMSET1 &= (uint32_t) (~R_PCIE0_PCI_EP_PCMSET1_MODE_PORT_Msk);
    }

    /* Setting of HWINT related registers (Function #i, i = 0, 1) */
    /* Setting PCI Express Configuration Registers (Type0 : End Point) */
    r_pcie_ep_configuration_register_type0_init(p_instance_ctrl);

    if (p_instance_ctrl->function == 0)
    {
        /* Permit ASPM L1 State Transition.
         * Set ALLOW_ENTER_L1 bit in the PCIE_MISC register to 1. */
        p_instance_ctrl->p_reg_spl->PCIE_MISC |= R_PCIE_SPL0_PCIE_MISC_ALLOW_ENTER_L1_Msk;
    }

    /* AXI/PCI/MSI Window settings */
    r_pcie_ep_window_setting(p_instance_ctrl);

    /* Interrupt settings */
    r_pcie_ep_interrupt_setup(p_instance_ctrl);

    if (p_instance_ctrl->function == 0)
    {
        /* Release the reset (RST_PS_B, RST_GP_B, RST_B, RST_OUT_B).
         * Set RST_PS_B, RST_GP_B, RST_B and RST_OUT_B in the PCI_EP_RESET to 1. */
        p_instance_ctrl->p_reg->PCI_EP_RESET |=
            R_PCIE0_PCI_EP_RESET_RST_OUT_B_Msk | R_PCIE0_PCI_EP_RESET_RST_PS_B_Msk |
            R_PCIE0_PCI_EP_RESET_RST_GP_B_Msk | R_PCIE0_PCI_EP_RESET_RST_B_Msk;

        /* Wait for 500 us or more */
        R_BSP_SoftwareDelay(PCIE_EP_RELEASE_RESET_WAIT_US, BSP_DELAY_UNITS_MICROSECONDS);

        /* Release the reset (RST_RSM_B).
         * Set RST_RSM_B in the PCI_EP_RESET to 1.*/
        p_instance_ctrl->p_reg->PCI_EP_RESET |= R_PCIE0_PCI_EP_RESET_RST_RSM_B_Msk;
    }

    /* Set callback and context pointers, if configured */
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = NULL;
    p_instance_ctrl->p_callback_memory = NULL;

    if (p_instance_ctrl->function == 0)
    {
        /* Track ctrl struct */
        gp_instance_ctrl[p_instance_ctrl->channel] = p_instance_ctrl;
    }

    /* Mark the module as open so other APIs can be used. */
    p_instance_ctrl->open = PCIE_EP_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the value of configuration register of this PCIE device.
 * Implements @ref pci_api_t::selfConfigurationRegisterSet.
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_EP_SelfConfigurationRegisterSet (pci_ctrl_t * const p_ctrl, uint32_t register_number, uint32_t data)
{
    pcie_ep_instance_ctrl_t * p_instance_ctrl = (pcie_ep_instance_ctrl_t *) p_ctrl;
#if PCIE_EP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(PCIE_EP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    uint32_t function = p_instance_ctrl->function;
    r_pcie_ep_self_configuration_register_write(p_instance_ctrl, register_number, data, function);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Read message data from PCI.  Implements @ref pci_api_t::messageRead.
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_EP_SelfConfigurationRegisterGet (pci_ctrl_t * const p_ctrl, uint32_t register_number,
                                                  uint32_t * p_data)
{
    pcie_ep_instance_ctrl_t * p_instance_ctrl = (pcie_ep_instance_ctrl_t *) p_ctrl;
#if PCIE_EP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_data);
    FSP_ERROR_RETURN(PCIE_EP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    uint32_t function = p_instance_ctrl->function;

    r_pcie_ep_self_configuration_register_read(p_instance_ctrl, register_number, function, p_data);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Issuing CfgWr0/1 Request. API not supported. Implements @ref pci_api_t::configurationRegisterWrite.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by PCIE_EP.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_EP_ConfigurationRegisterWrite (pci_ctrl_t * const                            p_ctrl,
                                                pci_configuration_write_type_t                transaction_type,
                                                pci_configuration_register_transfer_t * const p_transfer)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(transaction_type);
    FSP_PARAMETER_NOT_USED(p_transfer);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Issuing CfgRd0/1 Request. API not supported. Implements @ref pci_api_t::configurationRegisterRead.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by PCIE_EP.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_EP_ConfigurationRegisterRead (pci_ctrl_t * const                            p_ctrl,
                                               pci_configuration_read_type_t                 transaction_type,
                                               pci_configuration_register_transfer_t * const p_transfer)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(transaction_type);
    FSP_PARAMETER_NOT_USED(p_transfer);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Issuing IOWr Request. API not supported. Implements @ref pci_api_t::iORegisterWrite.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by PCIE_EP.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_EP_IORegisterWrite (pci_ctrl_t * const p_ctrl, pci_io_register_transfer_t * const p_transfer)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_transfer);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Issuing IORd Request.  API not supported. Implements @ref pci_api_t::iORegisterRead.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by PCIE_EP.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_EP_IORegisterRead (pci_ctrl_t * const p_ctrl, pci_io_register_transfer_t * const p_transfer)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_transfer);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Issuing Msg/MsgD Request.  Implements @ref pci_api_t::messageWrite.
 *
 * @retval FSP_SUCCESS                 The message was issued successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_EP_MessageWrite (pci_ctrl_t * const p_ctrl, pci_message_transfer_t * const p_transfer, bool with_data)
{
    pcie_ep_instance_ctrl_t * p_instance_ctrl = (pcie_ep_instance_ctrl_t *) p_ctrl;

#if PCIE_EP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_transfer);
    FSP_ERROR_RETURN(PCIE_EP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    uint32_t header = (uint32_t) ((p_transfer->header_1st_word_b.routing_type & 0x07) << 24) |
                      (uint32_t) ((p_transfer->header_2nd_word_b.message_code & UINT8_MAX));

    p_instance_ctrl->p_reg->PCI_EP_REQADR1    = header;
    p_instance_ctrl->p_reg->PCI_REQDATA[0].EP = p_transfer->header_3rd;
    p_instance_ctrl->p_reg->PCI_REQDATA[1].EP = p_transfer->header_4th;

    if (true == with_data)
    {
        p_instance_ctrl->p_reg->PCI_REQDATA[2].EP = p_transfer->data;

        pcie_ep_reqiss_tr_type_t message_type = PCIE_EP_REQISS_TR_TYPE_MESSAGE_REQUEST_WITH_DATA_PALYOAD;
        p_instance_ctrl->p_reg->PCI_EP_REQISS_b.TR_TYPE = message_type;
    }
    else
    {
        pcie_ep_reqiss_tr_type_t message_type = PCIE_EP_REQISS_TR_TYPE_MESSAGE_REQUEST;
        p_instance_ctrl->p_reg->PCI_EP_REQISS_b.TR_TYPE = message_type;
    }

    /* Message issue. */
    p_instance_ctrl->p_reg->PCI_EP_REQISS |= R_PCIE0_PCI_EP_REQISS_RI_Msk;

    /* Wait for issuing request. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->PCI_EP_REQISS_b.RI, 0);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Read message data from PCI.  Implements @ref pci_api_t::messageRead.
 *
 * @retval FSP_SUCCESS                 The message was read successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_EP_MessageRead (pci_ctrl_t * const p_ctrl, pci_message_transfer_t * const p_transfer)
{
    pcie_ep_instance_ctrl_t * p_instance_ctrl = (pcie_ep_instance_ctrl_t *) p_ctrl;

#if PCIE_EP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_transfer);
    FSP_ERROR_RETURN(PCIE_EP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    uint32_t msgcode = p_instance_ctrl->p_reg->PCI_EP_MSGCODE;

    p_transfer->header_1st_word_b.routing_type = (msgcode & R_PCIE0_PCI_EP_MSGCODE_R_Msk) >>
                                                 R_PCIE0_PCI_EP_MSGCODE_R_Pos;
    p_transfer->header_2nd_word_b.message_code = (msgcode & R_PCIE0_PCI_EP_MSGCODE_MC_Msk) >>
                                                 R_PCIE0_PCI_EP_MSGCODE_MC_Pos;
    p_transfer->header_3rd = p_instance_ctrl->p_reg->PCI_EP_MSGH3DW;
    p_transfer->header_4th = p_instance_ctrl->p_reg->PCI_EP_MSGH4DW;

    /* Check the presence or absence of the data payload of the last received Message.
     * If message data is presence, read from PCI_EP_MSGDATA. */
    p_transfer->data = ((msgcode & R_PCIE0_PCI_EP_MSGCODE_MP_Msk) >> R_PCIE0_PCI_EP_MSGCODE_MP_Pos) == 0 ?
                       0 : p_instance_ctrl->p_reg->PCI_EP_MSGDATA;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Assert INTx interrupt Request. Either INTA - INTD set by configuration register is asserted.
 *
 * Implements @ref pci_api_t::intxAssert.
 *
 * @retval FSP_SUCCESS                 The INTx assert is success.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 * @retval FSP_ERR_INVALID_MODE        This function can't be called
 *                                     when MSI is enabled (MSIE bit in MSI Capability Register equals to 1).
 **********************************************************************************************************************/
fsp_err_t R_PCIE_EP_IntxAssert (pci_ctrl_t * const p_ctrl)
{
    pcie_ep_instance_ctrl_t * p_instance_ctrl = (pcie_ep_instance_ctrl_t *) p_ctrl;

#if PCIE_EP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN(PCIE_EP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    if (0 == p_instance_ctrl->function)
    {
        /* To issue INTx interrupt, MSI Capability Register (PCIe configuration register) must be 0. */
        FSP_ERROR_RETURN(p_instance_ctrl->p_reg->PCI_EP_MSICAP_F0_b.MSIE == 0, FSP_ERR_INVALID_MODE);
    }
    else
    {
        /* To issue INTx interrupt, MSI Capability Register (PCIe configuration register) must be 0. */
        FSP_ERROR_RETURN(p_instance_ctrl->p_reg->PCI_EP_MSICAP_F1_b.MSIE == 0, FSP_ERR_INVALID_MODE);
    }
#endif

    /* Issuing Assert_INTx Message.
     * See RZ microprocessor Hardware Manual section "Issuing INTx/MSI Interrupts (Endpoint)" for more details. */
    p_instance_ctrl->p_reg_spl->PCIE_INTX |= 1U << p_instance_ctrl->function;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Deassert INTx interrupt Request. Either INTA - INTD set by configuration register is deasserted.
 *
 * Implements @ref pci_api_t::intxDeassert.
 *
 * @retval FSP_SUCCESS                 The INTx deassert is success.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 * @retval FSP_ERR_INVALID_MODE        This function can't be called
 *                                     when MSI is enabled (MSIE bit in MSI Capability Register equals to 1).
 **********************************************************************************************************************/
fsp_err_t R_PCIE_EP_IntxDeassert (pci_ctrl_t * const p_ctrl)
{
    pcie_ep_instance_ctrl_t * p_instance_ctrl = (pcie_ep_instance_ctrl_t *) p_ctrl;

#if PCIE_EP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN(PCIE_EP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    if (0 == p_instance_ctrl->function)
    {
        /* To issue INTx interrupt, MSI Capability Register (PCIe configuration register) must be 0. */
        FSP_ERROR_RETURN(p_instance_ctrl->p_reg->PCI_EP_MSICAP_F0_b.MSIE == 0, FSP_ERR_INVALID_MODE);
    }
    else
    {
        /* To issue INTx interrupt, MSI Capability Register (PCIe configuration register) must be 0. */
        FSP_ERROR_RETURN(p_instance_ctrl->p_reg->PCI_EP_MSICAP_F1_b.MSIE == 0, FSP_ERR_INVALID_MODE);
    }
#endif

    /* Issuing Deassert_INTx Message.
     * See RZ microprocessor Hardware Manual section "Issuing INTx/MSI Interrupts (Endpoint)" for more details. */
    p_instance_ctrl->p_reg_spl->PCIE_INTX &= ~(1U << p_instance_ctrl->function);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Gets the Link status and LTSSM state. Implements @ref pci_api_t::linkStatusGet.
 *
 * @retval FSP_SUCCESS                 The PCI status is in p_status.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_EP_LinkStatusGet (pci_ctrl_t * const p_ctrl, pci_status_t * const p_status)
{
    pcie_ep_instance_ctrl_t * p_instance_ctrl = (pcie_ep_instance_ctrl_t *) p_ctrl;
#if PCIE_EP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(PCIE_EP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Check Link Up Status*/
    uint32_t status = p_instance_ctrl->p_reg->PCI_EP_PCSTAT1;
    if ((status & R_PCIE0_PCI_EP_PCSTAT1_DLDS_Msk) == 0)
    {
        p_status->is_link_up = true;
    }
    else
    {
        p_status->is_link_up = false;
    }

    /* LTSSM State are indicated by upper 5 bits of LTSSM_STATE bits.
     * Shift LTSSM_STATE[14:8] to the left by 2 to get the upper 5 bit value.
     */
    uint32_t ltssm_state              = p_instance_ctrl->p_reg->PCI_EP_PCSTAT1_b.LTSSM_STATE;
    uint32_t ltssm_state_upper_5_bits = (ltssm_state >> 2) & 0x1FU;
    uint32_t ltssm_state_upper_3_bits =
        (ltssm_state_upper_5_bits & PCIE_EP_PCI_EP_PCSTAT1_LTSSM_STATE_UPPER_3_BIT_MASK) >> 2;

    if (ltssm_state_upper_3_bits == 0x0)
    {
        /* 000xxb : Detect */
        p_status->ltssm_state = PCI_LTSSM_STATE_DETECT;
    }
    else if (ltssm_state_upper_3_bits == 0x01)
    {
        /* 001xxb : Polling */
        p_status->ltssm_state = PCI_LTSSM_STATE_POLLING;
    }
    else if (ltssm_state_upper_3_bits == 0x02)
    {
        /* 010xxb : Configuration */
        p_status->ltssm_state = PCI_LTSSM_STATE_CONFIG;
    }
    else if (ltssm_state_upper_3_bits == 0x03)
    {
        uint32_t ltssm_state_lower_2_bits = ltssm_state_upper_5_bits & 0x3;
        if (ltssm_state_lower_2_bits == 0)
        {
            /* 01100b : L0 */
            p_status->ltssm_state = PCI_LTSSM_STATE_L0;
        }
        else if (ltssm_state_lower_2_bits == 1)
        {
            /* 01101b : L1 */
            p_status->ltssm_state = PCI_LTSSM_STATE_L1;
        }
        else
        {
            /* 0111xb : L2 */
            p_status->ltssm_state = PCI_LTSSM_STATE_L2;
        }
    }
    else if (ltssm_state_upper_3_bits == 0x04)
    {
        /* 100xxb : Recovery */
        p_status->ltssm_state = PCI_LTSSM_STATE_RECOVERY;
    }
    else if (ltssm_state_upper_3_bits == 0x05)
    {
        /* 101xxb : Disable */
        p_status->ltssm_state = PCI_LTSSM_STATE_DISABLE;
    }
    else if (ltssm_state_upper_3_bits == 0x06)
    {
        /* 110xxb : Loopback */
        p_status->ltssm_state = PCI_LTSSM_STATE_LOOPBACK;
    }
    else
    {
        /* Do nothing. */
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the PCI Express link width. Implements @ref pci_api_t::linkWidthChange.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_INVALID_ARGUMENT     Required link width is invalid.
 * @retval  FSP_ERR_TIMEOUT              Link Width change was not done in time and timeout occurred.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_EP_LinkWidthChange (pci_ctrl_t * const p_ctrl, uint32_t link_width, uint32_t option)
{
    pcie_ep_instance_ctrl_t * p_instance_ctrl = (pcie_ep_instance_ctrl_t *) p_ctrl;

#if PCIE_EP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN(PCIE_EP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(0 == (link_width & 0xFFFFFFFC), FSP_ERR_INVALID_ARGUMENT);
#endif

    p_instance_ctrl->p_reg->PCI_EP_PCCTRL2 |=
        (link_width << R_PCIE0_PCI_EP_PCCTRL2_UI_LINK_WIDTH_CHANGE_ENABLE_Pos) |
        (option << R_PCIE0_PCI_EP_PCCTRL2_UI_LINK_CHANGE_AUTONOMOUS_Pos);

    /* Issue a request to change Link Width. */
    p_instance_ctrl->p_reg->PCI_EP_PCCTRL2 |= R_PCIE0_PCI_EP_PCCTRL2_UI_LINK_WIDTH_CHANGE_REQ_Msk;

    /* UI_LINK_WIDTH_CHANGE_REQ bit set to 0 after confirming that PCIe Core Status Register UI_LINK_WIDTH_CHANGE_DONE is asserted. */
    uint32_t timeout_count = PCIE_EP_TIMEOUT_US;
    PCIE_EP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->PCI_EP_PCSTAT2_b.UI_LINK_WIDTH_CHANGE_DONE, 1U,
                                   timeout_count);
    FSP_ERROR_RETURN((0U != timeout_count), FSP_ERR_TIMEOUT);

    p_instance_ctrl->p_reg->PCI_EP_PCCTRL2 &= (uint32_t) (~R_PCIE0_PCI_EP_PCCTRL2_UI_LINK_WIDTH_CHANGE_REQ_Msk);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the PCI Express link speed. Implements @ref pci_api_t::linkSpeedChange.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_INVALID_ARGUMENT     Required link speed is invalid.
 * @retval  FSP_ERR_TIMEOUT              Link speed change was not done in time and timeout occurred.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_EP_LinkSpeedChange (pci_ctrl_t * const p_ctrl, pci_link_speed_t link_speed, uint32_t option)
{
    pcie_ep_instance_ctrl_t * p_instance_ctrl = (pcie_ep_instance_ctrl_t *) p_ctrl;

#if PCIE_EP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN(PCIE_EP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(link_speed < PCI_LINK_SPEED_16_0_GTS, FSP_ERR_INVALID_ARGUMENT);
#endif

    p_instance_ctrl->p_reg->PCI_EP_PCCTRL2 |=
        (uint32_t) (link_speed << R_PCIE0_PCI_EP_PCCTRL2_UI_LINK_SPEED_CHANGE_Pos) |
        (option << R_PCIE0_PCI_EP_PCCTRL2_UI_LINK_CHANGE_AUTONOMOUS_Pos);

    /* Issue a request to change the Link Speed. */
    p_instance_ctrl->p_reg->PCI_EP_PCCTRL2 |= R_PCIE0_PCI_EP_PCCTRL2_UI_LINK_SPEED_CHANGE_REQ_Msk;

    /* UI_LINK_SPEED_CHANGE_REQ bit set to 0 after confirming that PCIe Core Status Register UI_LINK_SPEED_CHANGE_DONE is asserted. */
    uint32_t timeout_count = PCIE_EP_TIMEOUT_US;
    PCIE_EP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->PCI_EP_PCSTAT2_b.UI_LINK_SPEED_CHANGE_DONE, 1U,
                                   timeout_count);
    FSP_ERROR_RETURN((0U != timeout_count), FSP_ERR_TIMEOUT);

    p_instance_ctrl->p_reg->PCI_EP_PCCTRL2 &= (uint32_t) (~R_PCIE0_PCI_EP_PCCTRL2_UI_LINK_SPEED_CHANGE_REQ_Msk);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Requires the PCI Express link equalization request. Implements @ref pci_api_t::linkEqualizationRequest.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_TIMEOUT              Link Equalization was not done in time and timeout occurred.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_EP_LinkEqualizationRequest (pci_ctrl_t * const p_ctrl)
{
    pcie_ep_instance_ctrl_t * p_instance_ctrl = (pcie_ep_instance_ctrl_t *) p_ctrl;

#if PCIE_EP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN(PCIE_EP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Send Equalization Request. */
    p_instance_ctrl->p_reg->PCI_EP_MSET4 |= R_PCIE0_PCI_EP_MSET4_UI_EQ_REQUEST_Msk;

    /* After UI_EQ_REQUEST set to 1, hold until confirmation of UI_EQ_DONE = 1. */
    uint32_t timeout_count = PCIE_EP_TIMEOUT_US;
    PCIE_EP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->PCI_EP_MSTAT0_b.UI_EQ_DONE, 1U, timeout_count);
    FSP_ERROR_RETURN((0U != timeout_count), FSP_ERR_TIMEOUT);

    p_instance_ctrl->p_reg->PCI_EP_MSET4 &= (uint32_t) (~R_PCIE0_PCI_EP_MSET4_UI_EQ_REQUEST_Msk);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 * Implements @ref pci_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_EP_CallbackSet (pci_ctrl_t * const          p_ctrl,
                                 void (                    * p_callback)(pci_callback_args_t *),
                                 void * const                p_context,
                                 pci_callback_args_t * const p_callback_memory)
{
    pcie_ep_instance_ctrl_t * p_instance_ctrl = (pcie_ep_instance_ctrl_t *) p_ctrl;

#if PCIE_EP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(PCIE_EP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */
    p_instance_ctrl->p_callback        = p_callback;
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Closes the PCIE_EP module.  Implements @ref pci_api_t::close.
 *
 * @retval FSP_SUCCESS                 The module is successfully closed.
 * @retval FSP_ERR_ASSERTION           Invalid input argument.
 * @retval FSP_ERR_NOT_OPEN            Module is not open.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_EP_Close (pci_ctrl_t * const p_ctrl)
{
    pcie_ep_instance_ctrl_t * p_instance_ctrl = (pcie_ep_instance_ctrl_t *) p_ctrl;

#if PCIE_EP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN(PCIE_EP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Get config and extend struct */
    pci_cfg_t              * p_cfg    = (pci_cfg_t *) p_instance_ctrl->p_cfg;
    pcie_ep_extended_cfg_t * p_extend = (pcie_ep_extended_cfg_t *) p_cfg->p_extend;

    r_pcie_ep_disable_irq(p_extend->flr_irq);
    r_pcie_ep_disable_irq(p_extend->d3_event_irq);

    if (p_cfg->function == 0)
    {
        r_pcie_ep_disable_irq(p_extend->pme_turn_off_rcv_irq);
        r_pcie_ep_disable_irq(p_extend->poweroff_indication_l2_irq);
        r_pcie_ep_disable_irq(p_extend->msg_irq);
        r_pcie_ep_disable_irq(p_extend->pcie_event_irq);
    }

    /* Reset/Stop PCIE module if other is not open */
    if (p_instance_ctrl->function == 0)
    {
        /* Reset/Stop PCIE module if other is not open */
        if (NULL == gp_instance_ctrl[!p_cfg->channel])
        {
            p_instance_ctrl->p_reg->PCI_EP_RESET &= (uint32_t) (~R_PCIE0_PCI_EP_RESET_RST_RSM_B_Msk);

            /* Wait for 500 us or more */
            R_BSP_SoftwareDelay(PCIE_EP_RELEASE_RESET_WAIT_US, BSP_DELAY_UNITS_MICROSECONDS);

            p_instance_ctrl->p_reg->PCI_EP_RESET &=
                (uint32_t) (~(R_PCIE0_PCI_EP_RESET_RST_OUT_B_Msk | R_PCIE0_PCI_EP_RESET_RST_PS_B_Msk |
                              R_PCIE0_PCI_EP_RESET_RST_GP_B_Msk | R_PCIE0_PCI_EP_RESET_RST_B_Msk));

            p_instance_ctrl->p_reg->PCI_EP_RESET &=
                (uint32_t) (~(R_PCIE0_PCI_EP_RESET_RST_LOAD_B_Msk | R_PCIE0_PCI_EP_RESET_RST_CFG_B_Msk));

#ifdef BSP_FEATURE_BSP_SLAVE_STOP_SUPPORTED
            if (1 == p_instance_ctrl->channel)
            {
                /* Slave Stop Function. */
                R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_SYSTEM);
                R_BSP_SlaveStop(BSP_BUS_SLAVE_PCIE1);
                R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_SYSTEM);
            }
#endif

            R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);

            /* Stop PCIE module. */
            R_BSP_MODULE_STOP(FSP_IP_PCIE, 0);

            /* Enable the reset. */
            R_BSP_ModuleResetEnable(BSP_MODULE_RESET_PCIE);

            R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);
        }

        /* Reset global control struct pointer */
        gp_instance_ctrl[p_cfg->channel] = NULL;
    }

    p_instance_ctrl->open = 0U;

    /* All done, return success. */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup PCIE_EP)
 **********************************************************************************************************************/
#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/*******************************************************************************************************************//**
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Enables write protection.
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 * @param[in]  bit_mask                The position of PCI_EP_PERM.
 **********************************************************************************************************************/
static inline void r_pcie_ep_write_protect_enable (pcie_ep_instance_ctrl_t * p_instance_ctrl, uint32_t bit_mask)
{
    p_instance_ctrl->p_reg->PCI_EP_PERM &= ~bit_mask;
}

/*******************************************************************************************************************//**
 * Disables write protection.
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 * @param[in]  bit_mask                The position of PCI_EP_PERM.
 **********************************************************************************************************************/
static inline void r_pcie_ep_write_protect_disable (pcie_ep_instance_ctrl_t * p_instance_ctrl, uint32_t bit_mask)
{
    p_instance_ctrl->p_reg->PCI_EP_PERM |= bit_mask;
}

/*******************************************************************************************************************//**
 * Initializes PCI_PHY_XCFGDn register (n = 0 to 26).
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 **********************************************************************************************************************/
static void r_pcie_ep_xcfgd_setting (pcie_ep_instance_ctrl_t * p_instance_ctrl)
{
    /* Enable writing of physical layer control/status registers */
    r_pcie_ep_write_protect_disable(p_instance_ctrl, R_PCIE0_PCI_EP_PERM_PHY_REG_CLK_EN_Msk);

    for (uint32_t i = 0; i < PCIE_EP_PHY_XCFGD_SETTING_VALUE_NUM; i++)
    {
        p_instance_ctrl->p_reg_phy->PCI_PHY_XCFGD[i].XCFGD = pcie_ep_phy_xcfgd_setting_value[i];
    }

    /* Disable writing of physical layer control/status registers */
    r_pcie_ep_write_protect_enable(p_instance_ctrl, R_PCIE0_PCI_EP_PERM_PHY_REG_CLK_EN_Msk);
}

/*******************************************************************************************************************//**
 * Initializes PCI_PHY_XCFGA_CMNn register (n = 0 to 15).
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 **********************************************************************************************************************/
static void r_pcie_ep_xcfga_cmn_setting (pcie_ep_instance_ctrl_t * p_instance_ctrl)
{
    /* Enable writing of physical layer control/status registers */
    r_pcie_ep_write_protect_disable(p_instance_ctrl, R_PCIE0_PCI_EP_PERM_PHY_REG_CLK_EN_Msk);

    for (uint32_t i = 0; i < PCIE_EP_PHY_XCFGA_CMN_SETTING_VALUE_NUM; i++)
    {
        p_instance_ctrl->p_reg_phy->PCI_PHY_XCFGA_CMN[i].XCFGA_CMN = pcie_ep_phy_xcfga_cmn_setting_value[i];
    }

    /* Disable writing of physical layer control/status registers */
    r_pcie_ep_write_protect_enable(p_instance_ctrl, R_PCIE0_PCI_EP_PERM_PHY_REG_CLK_EN_Msk);
}

/*******************************************************************************************************************//**
 * Initializes PCI_PHY_XCFGA_L0n register (n = 0 to 5).
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 **********************************************************************************************************************/
static void r_pcie_ep_xcfga_la0_setting (pcie_ep_instance_ctrl_t * p_instance_ctrl)
{
    /* Enable writing of physical layer control/status registers */
    r_pcie_ep_write_protect_disable(p_instance_ctrl, R_PCIE0_PCI_EP_PERM_PHY_REG_CLK_EN_Msk);

    for (uint32_t i = 0; i < PCIE_EP_PHY_XCFGA_LA0_SETTING_VALUE_NUM; i++)
    {
        p_instance_ctrl->p_reg_phy->PCI_PHY_XCFGA_L0[i].XCFGA_LN0 = pcie_ep_phy_xcfga_la0_setting_value[i];
    }

    /* Disable writing of physical layer control/status registers */
    r_pcie_ep_write_protect_enable(p_instance_ctrl, R_PCIE0_PCI_EP_PERM_PHY_REG_CLK_EN_Msk);
}

/*******************************************************************************************************************//**
 * Initializes PCI_PHY_XCFGA_L1n register (n = 0 to 5).
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 **********************************************************************************************************************/
static void r_pcie_ep_xcfga_la1_setting (pcie_ep_instance_ctrl_t * p_instance_ctrl)
{
    /* Enable writing of physical layer control/status registers */
    r_pcie_ep_write_protect_disable(p_instance_ctrl, R_PCIE0_PCI_EP_PERM_PHY_REG_CLK_EN_Msk);

    /* PCI_PHY_XCFGA_L1n (n = 0 to 5) */
    for (uint32_t i = 0; i < PCIE_EP_PHY_XCFGA_LA1_SETTING_VALUE_NUM; i++)
    {
        p_instance_ctrl->p_reg_phy->PCI_PHY_XCFGA_L1[i].XCFGA_LN1 = pcie_ep_phy_xcfga_la1_setting_value[i];
    }

    /* Disable writing of physical layer control/status registers */
    r_pcie_ep_write_protect_enable(p_instance_ctrl, R_PCIE0_PCI_EP_PERM_PHY_REG_CLK_EN_Msk);
}

/*******************************************************************************************************************//**
 * Initializes AXI / PCI / MSI window.
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 **********************************************************************************************************************/
static void r_pcie_ep_window_setting (pcie_ep_instance_ctrl_t * p_instance_ctrl)
{
    uint32_t function = p_instance_ctrl->function;
    pcie_ep_extended_cfg_t const * p_extend = (pcie_ep_extended_cfg_t const *) p_instance_ctrl->p_cfg->p_extend;

    /* AXI Window n n : 0 - 3 */
    for (uint32_t i = 0; i < R_PCIE_EP_NUM_AXI_WINDOW; i++)
    {
        pcie_ep_window_settings_t const * p_axi_window_settings = &(p_extend->axi_window_settings[i]);

        uint32_t address_offset =
            (PCIE_EP_WINDOW_SETTING_ADDR_NTH_FUNCTION_OFFSET * function) + (PCIE_EP_WINDOW_SETTING_ADDR_NTH_OFFSET * i);

        /* Set the AXI Window Base Register */
        uint32_t * p_awbasel =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_EP_AWBASEL0_F0 + address_offset);

        *p_awbasel = p_axi_window_settings->base_address & R_PCIE0_PCI_EP_AWBASEL0_F0_AWB3112_Msk;

        uint32_t * p_awbaseu =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_EP_AWBASEU0_F0 + address_offset);
        *p_awbaseu =
            (uint32_t) ((p_axi_window_settings->base_address >> PCIE_EP_SHIFT_FOR_UPPER_32BIT_VALUE) & UINT32_MAX);

        /* Set the AXI Window Mask Register */
        uint32_t * p_awmaskl =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_EP_AWMASKL0_F0 + address_offset);
        *p_awmaskl = p_axi_window_settings->mask_address & UINT32_MAX;

        uint32_t * p_awmasku =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_EP_AWMASKU0_F0 + address_offset);
        *p_awmasku =
            (uint32_t) ((p_axi_window_settings->mask_address >> PCIE_EP_SHIFT_FOR_UPPER_32BIT_VALUE) &
                        R_PCIE0_PCI_EP_AWMASKU0_F0_AWM6232_Msk);

        /* Set the AXI Destination Register */
        uint32_t * p_adestl =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_EP_ADESTL0_F0 + address_offset);
        *p_adestl = p_axi_window_settings->destination_address & UINT32_MAX;

        uint32_t * p_adestu =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_EP_ADESTU0_F0 + address_offset);
        *p_adestu =
            (uint32_t) ((p_axi_window_settings->destination_address >> PCIE_EP_SHIFT_FOR_UPPER_32BIT_VALUE) &
                        UINT32_MAX);

        /* Set the AXI Window enable */
        *p_awbasel |= p_axi_window_settings->window_enable;
    }

    /* PCI Window n n : 0 - 3 */
    for (uint32_t i = 0; i < R_PCIE_EP_NUM_PCIE_WINDOW; i++)
    {
        pcie_ep_window_settings_t const * p_pci_window_settings = &(p_extend->pci_window_settings[i]);

        uint32_t address_offset =
            (PCIE_EP_WINDOW_SETTING_ADDR_NTH_FUNCTION_OFFSET * function) + (PCIE_EP_WINDOW_SETTING_ADDR_NTH_OFFSET * i);

        /* Set the PCIe Window Base Register */
        uint32_t * p_pwbasel =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_EP_PWBASEL0_F0 + address_offset);
        *p_pwbasel = p_pci_window_settings->base_address & R_PCIE0_PCI_EP_PWBASEL0_F0_PWB3112_Msk;

        uint32_t * p_pwbaseu =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_EP_PWBASEU0_F0 + address_offset);
        *p_pwbaseu =
            (uint32_t) ((p_pci_window_settings->base_address >> PCIE_EP_SHIFT_FOR_UPPER_32BIT_VALUE) & UINT32_MAX);

        /* Set the PCIe Window Mask Register */
        uint32_t * p_pwmaskl =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_EP_PWMASKL0_F0 + address_offset);
        *p_pwmaskl = p_pci_window_settings->mask_address & UINT32_MAX;

        uint32_t * p_pwmasku =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_EP_PWMASKU0_F0 + address_offset);
        *p_pwmasku =
            (uint32_t) ((p_pci_window_settings->mask_address >> PCIE_EP_SHIFT_FOR_UPPER_32BIT_VALUE) &
                        R_PCIE0_PCI_EP_PWMASKU0_F0_PWM6232_Msk);

        /* Set the PCIe Destination Register */
        uint32_t * p_pdestl =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_EP_PDESTL0_F0 + address_offset);
        *p_pdestl = p_pci_window_settings->destination_address & UINT32_MAX;

        uint32_t * p_pdestu =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_EP_PDESTU0_F0 + address_offset);
        *p_pdestu =
            (uint32_t) ((p_pci_window_settings->destination_address >> PCIE_EP_SHIFT_FOR_UPPER_32BIT_VALUE) &
                        UINT32_MAX);

        /* Set the PCIe Window enable */
        *p_pwbasel |= p_pci_window_settings->window_enable;
    }
}

/*******************************************************************************************************************//**
 * Configures and enables interrupt if it is a valid vector number.
 *
 * @param[in]  irq                     Interrupt number
 * @param[in]  priority                Priority of the interrupt
 * @param[in]  p_context               The interrupt context is a pointer to data required in the ISR.
 **********************************************************************************************************************/
static void r_pcie_ep_enable_irq (IRQn_Type const irq, uint32_t priority, void * p_context)
{
    if (irq >= 0)
    {
        R_BSP_IrqCfgEnable(irq, priority, p_context);
    }
}

/*******************************************************************************************************************//**
 * Disables interrupt if it is a valid vector number.
 *
 * @param[in]  irq                     Interrupt number
 **********************************************************************************************************************/
static void r_pcie_ep_disable_irq (IRQn_Type irq)
{
    /* Disable interrupts. */
    if (irq >= 0)
    {
        R_BSP_IrqDisable(irq);
        R_FSP_IsrContextSet(irq, NULL);
    }
}

/*******************************************************************************************************************//**
 * Configures PCIE_EP interrupt
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 **********************************************************************************************************************/
static void r_pcie_ep_interrupt_setup (pcie_ep_instance_ctrl_t * p_instance_ctrl)
{
    pcie_ep_extended_cfg_t * p_extend = (pcie_ep_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* Initialize PCIe Event Interrupt Status / Enable 0 Register. */
    p_instance_ctrl->p_reg->PCI_EP_PEIS0 = PCIE_EP_PEIS0_REG_SETTING_VALUE;

    /* ASPML1REN bit should not be enabled in Endpoint mode, so clear it before writing. */
    p_extend->event0_interrupts         &= (uint32_t) (~R_PCIE0_PCI_EP_PEIE0_ASPML1REN_Msk);
    p_instance_ctrl->p_reg->PCI_EP_PEIE0 = p_extend->event0_interrupts;

    /* Initialize PCIe Event Interrupt Status / Enable 1 Register. */
    p_instance_ctrl->p_reg->PCI_EP_PEIS1 = PCIE_EP_PEIS1_REG_SETTING_VALUE;
    p_instance_ctrl->p_reg->PCI_EP_PEIE1 = p_extend->event1_interrupts;

    /* Initialize PCIe Event Interrupt Status / Enable 0 Register. */
    p_instance_ctrl->p_reg->PCI_EP_PEIS2 = PCIE_EP_PEIS2_REG_SETTING_VALUE;
    p_instance_ctrl->p_reg->PCI_EP_PEIE2 = p_extend->event2_interrupts;

    /* Initialize AXI Master Error Interrupt Status / Enable Register. */
    p_instance_ctrl->p_reg->PCI_EP_AMEIS = PCIE_EP_AMEIS_AMEIE_REG_SETTING_VALUE;
    p_instance_ctrl->p_reg->PCI_EP_AMEIE = PCIE_EP_AMEIS_AMEIE_REG_SETTING_VALUE;

    /* Initialize AXI Slave Error Interrupt Status / Enable 1 Register. */
    p_instance_ctrl->p_reg->PCI_EP_ASEIS1 = PCIE_EP_ASEIS1_ASEIE1_REG_SETTING_VALUE;
    p_instance_ctrl->p_reg->PCI_EP_ASEIE1 = PCIE_EP_ASEIS1_ASEIE1_REG_SETTING_VALUE;

    /* Initialize Message Receive Interrupt Status / Enable Register. */
    p_instance_ctrl->p_reg->PCI_EP_MSGRCVIS = PCIE_EP_MSGRCVIS_SETTING_VALUE;
    p_instance_ctrl->p_reg->PCI_EP_MSGRCVIE = PCIE_EP_MSGRCVIE_SETTING_VALUE;

    r_pcie_ep_enable_irq(p_extend->flr_irq, p_extend->flr_ipl, p_instance_ctrl);
    r_pcie_ep_enable_irq(p_extend->d3_event_irq, p_extend->d3_event_ipl, p_instance_ctrl);
    r_pcie_ep_enable_irq(p_extend->pme_turn_off_rcv_irq, p_extend->pme_turn_off_rcv_ipl, p_instance_ctrl);
    r_pcie_ep_enable_irq(p_extend->poweroff_indication_l2_irq, p_extend->poweroff_indication_l2_ipl, p_instance_ctrl);
    r_pcie_ep_enable_irq(p_extend->msg_irq, p_extend->msg_irq, p_instance_ctrl);
    r_pcie_ep_enable_irq(p_extend->pcie_event_irq, p_extend->pcie_event_ipl, p_instance_ctrl);
}

/*******************************************************************************************************************//**
 * Initialize PCIE_EP Configuration register.
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 **********************************************************************************************************************/
static void r_pcie_ep_configuration_register_type0_init (pcie_ep_instance_ctrl_t * p_instance_ctrl)
{
    pcie_ep_configuration_register_0_t const * p_cfg_register =
        p_instance_ctrl->p_cfg->p_configuration_register_header;

    uint32_t function = p_instance_ctrl->function;

    /* PCI_EP_VID_Fi (Vendor and Device ID) */
    r_pcie_ep_self_configuration_register_write(p_instance_ctrl, 0, p_cfg_register->vender_device_id, function);

    /* PCI_EP_COM_STA_Fi (Command and Status) */
    r_pcie_ep_self_configuration_register_write(p_instance_ctrl, 1, p_cfg_register->command_status, function);

    /* PCI_EP_RID_CC_Fi (Revision ID and Class Code) */
    r_pcie_ep_self_configuration_register_write(p_instance_ctrl, 2, p_cfg_register->revision_id_class_code, function);

    /* PCI_EP_CL_HT_Fi (Cache Line and Header Type) */
    r_pcie_ep_self_configuration_register_write(p_instance_ctrl, 3, p_cfg_register->cahce_line_header_type, function);

    /* PCI_EP_SUBSID_Fi (Subsystem ID) */
    r_pcie_ep_self_configuration_register_write(p_instance_ctrl, 11, p_cfg_register->subsystem_id, function);

    /* PCI_EP_INT_Fi (Interrupt Register) */
    r_pcie_ep_self_configuration_register_write(p_instance_ctrl, 15, p_cfg_register->interrupt, function);

    pci_configuration_register_init_t const * p_configuration_register_init =
        p_instance_ctrl->p_cfg->p_configuration_register_init_list;
    uint32_t size = p_instance_ctrl->p_cfg->configuration_register_init_list_length;

    for (uint32_t i = 0; i < size; i++)
    {
        uint32_t register_number = p_configuration_register_init[i].register_number;
        uint32_t init_value      = p_configuration_register_init[i].init_value;
        uint32_t init_value_mask = p_configuration_register_init[i].init_value_mask;

        uint32_t register_value;
        r_pcie_ep_self_configuration_register_read(p_instance_ctrl, register_number, function, &register_value);

        register_value &= ~init_value_mask;
        register_value |= (init_value & init_value_mask);
        r_pcie_ep_self_configuration_register_write(p_instance_ctrl, register_number, register_value, function);
    }

    /* PCI_EP_BAR0_Fi (Base Address Register 0)
     *
     * Depending on the size of the address block required, some lower bits of this field are implemented as Read Only bits.
     * For this reason, set the BAR register last so that the address block size is set first.
     *
     * See Section "PCI_EP_BAR0_Fi : Base Address Register 0 (Function #i)", "PCI_EP_BAR2_Fi : Base Address Register 2 (Function #i)"
     * and "PCI_EP_BAR4_Fi : Base Address Register 4 (Function #i)" in the RZ microprocessor Hardware Manual for more details. */
    r_pcie_ep_self_configuration_register_write(p_instance_ctrl, 4, p_cfg_register->base_address_register_0, function);

    /* PCI_EP_BAR1_Fi (Base Address Register 1) */
    r_pcie_ep_self_configuration_register_write(p_instance_ctrl, 5, p_cfg_register->base_address_register_1, function);

    /* PCI_EP_BAR2_Fi (Base Address Register 2) */
    r_pcie_ep_self_configuration_register_write(p_instance_ctrl, 6, p_cfg_register->base_address_register_2, function);

    /* PCI_EP_BAR3_Fi (Base Address Register 3) */
    r_pcie_ep_self_configuration_register_write(p_instance_ctrl, 7, p_cfg_register->base_address_register_3, function);

    /* PCI_EP_BAR4_Fi (Base Address Register 4) */
    r_pcie_ep_self_configuration_register_write(p_instance_ctrl, 8, p_cfg_register->base_address_register_4, function);

    /* PCI_EP_BAR5_Fi (Base Address Register 5) */
    r_pcie_ep_self_configuration_register_write(p_instance_ctrl, 9, p_cfg_register->base_address_register_5, function);
}

/*******************************************************************************************************************//**
 * Set value to PCIE_EP Configuration register.
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 * @param[in]  register_number         Register number to be set.
 * @param[in]  register_value          Setting value.
 * @param[in]  function                Function.
 **********************************************************************************************************************/
static void r_pcie_ep_self_configuration_register_write (pcie_ep_instance_ctrl_t * p_instance_ctrl,
                                                         uint32_t                  register_number,
                                                         uint32_t                  register_value,
                                                         uint32_t                  function)
{
    uint32_t offset = PCIE_EP_CONFIG_REG_SETTING_ADDR_NTH_FUNCTION_OFFSET * function;

    uint32_t * p_configuration_register_base =
        (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_EP_VID_F0 + offset);

    *(p_configuration_register_base + register_number) = register_value;
}

/*******************************************************************************************************************//**
 * Read value to PCIE_EP Configuration register.
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 * @param[in]  register_number         Register number to be read.
 * @param[in]  function                Function number to be read.
 * @param[out]  p_register_value       Store location of read value.
 **********************************************************************************************************************/
static void r_pcie_ep_self_configuration_register_read (pcie_ep_instance_ctrl_t * p_instance_ctrl,
                                                        uint32_t                  register_number,
                                                        uint32_t                  function,
                                                        uint32_t                * p_register_value)
{
    uint32_t offset = PCIE_EP_CONFIG_REG_SETTING_ADDR_NTH_FUNCTION_OFFSET * function;

    uint32_t * p_configuration_register_base =
        (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_EP_VID_F0 + offset);

    *p_register_value = *(p_configuration_register_base + register_number);
}

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_ctrl     Pointer to PCIE_EP instance control block
 * @param[in]     p_args     Pointer to arguments on stack
 **********************************************************************************************************************/
static void r_pcie_ep_call_callback (pcie_ep_instance_ctrl_t * p_ctrl, pci_callback_args_t * p_args)
{
    pci_callback_args_t args;

    /* Store callback arguments in memory provided by user if available. */
    pci_callback_args_t * p_args_memory = p_ctrl->p_callback_memory;
    if (NULL == p_args_memory)
    {
        /* Store on stack */
        p_args_memory = p_args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt. */
        args = *p_args_memory;

        /* Copy the stacked args to callback memory */
        *p_args_memory = *p_args;
    }

    p_ctrl->p_callback(p_args_memory);

    if (NULL != p_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_ctrl->p_callback_memory = args;
    }
}

/*******************************************************************************************************************//**
 * PCI TURN_OFF Event interrupt processing. When a TURN_OFF Event indication fires, the user callback
 * function is called if it is registered in R_PCIE_EP_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void pcie_ep_pme_turn_off_msg_event_handler (void)
{
    PCIE_EP_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    pcie_ep_instance_ctrl_t * p_instance_ctrl = (pcie_ep_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    pci_callback_args_t args;
    args.event     = PCI_EVENT_PME_TURN_OFF_RCV_EVENT;
    args.p_context = p_instance_ctrl->p_context;

    /* data1 - data3 not used at PCI_EVENT_PME_TURN_OFF_RCV_EVENT event. */
    args.data1 = 0U;
    args.data2 = 0U;
    args.data3 = 0U;

    /* User prepare turn power down. */
    if (NULL != p_instance_ctrl->p_callback)
    {
        r_pcie_ep_call_callback(p_instance_ctrl, &args);
    }

    /* Acknowledge to Power State Transition. */
    p_instance_ctrl->p_reg_spl->PCIE_ACK |= R_PCIE_SPL0_PCIE_ACK_TURN_OFF_EVENT_ACK_Msk;
    p_instance_ctrl->p_reg_spl->PCIE_ACK &= (uint32_t) (~R_PCIE_SPL0_PCIE_ACK_TURN_OFF_EVENT_ACK_Msk);

    /* Dummy read to ensure that interrupt event is cleared. */
    FSP_REGISTER_READ(p_instance_ctrl->p_reg_spl->PCIE_ACK);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    PCIE_EP_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * PCI POWEROFF indication interrupt processing. When a POWEROFF indication interrupt fires, the user callback
 * function is called if it is registered in R_PCIE_EP_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void pcie_ep_power_off_indication_handler (void)
{
    PCIE_EP_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    pcie_ep_instance_ctrl_t * p_instance_ctrl = (pcie_ep_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Set static arguments */
    pci_callback_args_t args;
    args.event     = PCI_EVENT_POWEROFF_L2;
    args.p_context = p_instance_ctrl->p_context;

    /* data1 - data3 not used at PCI_EVENT_POWEROFF_L2 event. */
    args.data1 = 0U;
    args.data2 = 0U;
    args.data3 = 0U;

    if (NULL != p_instance_ctrl->p_callback)
    {
        r_pcie_ep_call_callback(p_instance_ctrl, &args);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    PCIE_EP_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * PCI message receive interrupt processing. When a message receive interrupt fires, the user callback function is called
 * if it is registered in R_PCIE_EP_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void pcie_ep_message_receive_handler (void)
{
    PCIE_EP_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    pcie_ep_instance_ctrl_t * p_instance_ctrl = (pcie_ep_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    uint32_t status = p_instance_ctrl->p_reg->PCI_EP_MSGRCVIS;

    pci_callback_args_t args;
    args.event     = PCI_EVENT_MESSAGE_RECEIVE;
    args.p_context = p_instance_ctrl->p_context;

    /* data1 - data3 not used at PCI_EVENT_MESSAGE_RECEIVE event. */
    args.data1 = 0U;
    args.data2 = 0U;
    args.data3 = 0U;

    if (NULL != p_instance_ctrl->p_callback)
    {
        r_pcie_ep_call_callback(p_instance_ctrl, &args);
    }

    p_instance_ctrl->p_reg->PCI_EP_MSGRCVIS = status;

    /* Dummy read to ensure that interrupt event is cleared. */
    FSP_REGISTER_READ(p_instance_ctrl->p_reg->PCI_EP_MSGRCVIS);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    PCIE_EP_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * PCIE D3 Event interrupt processing. When an PCIE D3 Event interrupt fires, the user callback function is called if it is
 * registered in R_PCIE_EP_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void pcie_ep_d3_event_handler (void)
{
    PCIE_EP_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    pcie_ep_instance_ctrl_t * p_instance_ctrl = (pcie_ep_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    pci_callback_args_t args;
    args.event     = PCI_EVENT_D3_EVENT;
    args.p_context = p_instance_ctrl->p_context;

    /* data1 - data3 not used at PCI_EVENT_D3_EVENT event. */
    args.data1 = 0U;
    args.data2 = 0U;
    args.data3 = 0U;

    if (NULL != p_instance_ctrl->p_callback)
    {
        r_pcie_ep_call_callback(p_instance_ctrl, &args);
    }

    /* Acknowledge to Power State Transition. */
    uint32_t function = p_instance_ctrl->function;
    p_instance_ctrl->p_reg_spl->PCIE_ACK |= 1U << (R_PCIE_SPL0_PCIE_ACK_D3_EVENT_ACK_F0_Pos + function);
    p_instance_ctrl->p_reg_spl->PCIE_ACK &= ~(1U << (R_PCIE_SPL0_PCIE_ACK_D3_EVENT_ACK_F0_Pos + function));

    /* Dummy read to ensure that interrupt event is cleared. */
    FSP_REGISTER_READ(p_instance_ctrl->p_reg_spl->PCIE_ACK);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    PCIE_EP_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * PCIE Event interrupt processing. When an PCIE Event interrupt fires, the user callback function is called if it is
 * registered in R_PCIE_EP_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void pcie_ep_event_handler (void)
{
    PCIE_EP_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    pcie_ep_instance_ctrl_t * p_instance_ctrl = (pcie_ep_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Set static arguments */
    pci_callback_args_t args;
    args.event     = PCI_EVENT_EVENT;
    args.p_context = p_instance_ctrl->p_context;
    args.data1     = p_instance_ctrl->p_reg->PCI_EP_PEIS0;
    args.data2     = p_instance_ctrl->p_reg->PCI_EP_PEIS1;
    args.data3     = p_instance_ctrl->p_reg->PCI_EP_PEIS2;

    if (NULL != p_instance_ctrl->p_callback)
    {
        r_pcie_ep_call_callback(p_instance_ctrl, &args);
    }

    p_instance_ctrl->p_reg->PCI_EP_PEIS0 = args.data1;
    p_instance_ctrl->p_reg->PCI_EP_PEIS1 = args.data2;
    p_instance_ctrl->p_reg->PCI_EP_PEIS2 = args.data3;

    /* Dummy read to ensure that interrupt event is cleared. */
    FSP_REGISTER_READ(p_instance_ctrl->p_reg->PCI_EP_PEIS0);
    FSP_REGISTER_READ(p_instance_ctrl->p_reg->PCI_EP_PEIS1);
    FSP_REGISTER_READ(p_instance_ctrl->p_reg->PCI_EP_PEIS2);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    PCIE_EP_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * PCIE FLR request interrupt processing. When an PCIE FLR request interrupt fires, the user callback function is called
 * if it is registered in R_PCIE_EP_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void pcie_ep_flr_handler (void)
{
    PCIE_EP_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    pcie_ep_instance_ctrl_t * p_instance_ctrl = (pcie_ep_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    pci_callback_args_t args;
    args.event     = PCI_EVENT_FUNCTION_LEVEL_RESET;
    args.p_context = p_instance_ctrl->p_context;

    /* data1 - data3 not used at PCI_EVENT_FUNCTION_LEVEL_RESET event. */
    args.data1 = 0U;
    args.data2 = 0U;
    args.data3 = 0U;

    if (NULL != p_instance_ctrl->p_callback)
    {
        r_pcie_ep_call_callback(p_instance_ctrl, &args);
    }

    uint32_t function = p_instance_ctrl->function;
    p_instance_ctrl->p_reg_spl->PCIE_MISC |= 1U << (R_PCIE_SPL0_PCIE_MISC_FLR_RESET0_Pos + function);

    /* Dummy read to ensure that interrupt event is cleared. */
    FSP_REGISTER_READ(p_instance_ctrl->p_reg_spl->PCIE_MISC);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    PCIE_EP_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}
