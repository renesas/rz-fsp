/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_pcie_rc.h"
#include "r_pcie_rc_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "PCIR" in ASCII, used to determine if channel is open. */
#define PCIE_RC_OPEN                                           (0x50434952UL)

/* Root Complex mode. */
#define PCIE_RC_PCIE_MODE_MODE_PORT_ROOT_COMPLEX               (1)

/* PHY settings related values. */
#define PCIE_RC_PHY_XCFGA_LA0_SETTING_NUM                      (6)
#define PCIE_RC_PHY_XCFGA_LA1_SETTING_NUM                      (6)

/* PCI Express Configuration Register (Type1 : Root Complex) settings related values. */
#define PCIE_RC_LINKC_SLS_REG_GEN2_SETTING_VALUE               (0x2) /*If only PCI Express Gen1/Gen2 is supported */
#define PCIE_RC_LINKC2_SLSV_REG_GEN2_SETTING_VALUE             (0x3) /*If only PCI Express Gen1/Gen2 is supported */
#define PCIE_RC_LINKCS2_TLS_REG_GEN2_SETTING_VALUE             (0x2) /*If only PCI Express Gen1/Gen2 is supported */
#define PCIE_RC_LINKCS_CCC_REG_SINGLE_LINK_SETTING_VALUE       (0x1) /*Setting in case of Single link mode */

/* Interrupt settings values.
 * See Section "Initialization Procedure" in the RZ microprocessor Hardware Manual for more details. */
#define PCIE_RC_PEIS0_REG_SETTING_VALUE                        (0x00001200)
#define PCIE_RC_PEIS1_REG_SETTING_VALUE                        (0x00030303)
#define PCIE_RC_AMEIS_AMEIE_REG_SETTING_VALUE                  (0x00000F0F)
#define PCIE_RC_ASEIS1_ASEIE1_REG_SETTING_VALUE                (0x00000F03)
#define PCIE_RC_MSGRCVIS_SETTING_VALUE                         (0x010F0000)
#define PCIE_RC_MSGRCVIE_SETTING_VALUE                         (0x01050000)

/* Mask value when obtain the upper 3 bits from the PCSTAT1.LTSSM_STATE bits. */
#define PCIE_RC_PCI_RC_PCSTAT1_LTSSM_STATE_UPPER_3_BIT_MASK    (0x1CU) // b'1_1100

/* Shift value to obtain upper 32-bit address value from 64-bit address. */
#define PCIE_RC_SHIFT_FOR_UPPER_32BIT_VALUE                    (32U)

/* Wait 500 us or more to release the reset (RST_RSM_B). */
#define PCIE_RC_RELEASE_RESET_WAIT_US                          (500U)

/* Delay up to 500 ms before timing out waiting for each request . */
#define PCIE_RC_REQUEST_TIMEOUT_US                             (500000U)

/* Setting value for Lane Equalization Control Register */
#if PCIE_RC_CFG_LINK_MODE == (1U << R_PCIE_LNK_PCIE_LINKMODE_LINK_MASTER_Pos)

/* For the 2 lanes x 1 channel configuration.*/
 #define PCIE_RC_LEQCTL_SETTING_VALUE             (0x78787878)

#elif PCIE_RC_CFG_LINK_MODE == (3U << R_PCIE_LNK_PCIE_LINKMODE_LINK_MASTER_Pos)

/* For the 1 lane x 2 channels configuration.*/
 #define PCIE_RC_LEQCTL_SETTING_VALUE             (0x7F7F7878)
#endif

/* Offset address value for nth window setting register. */
#define PCIE_RC_WINDOW_SETTING_ADDR_NTH_OFFSET    (0x20)

#define PCIE_RC_HARDWARE_REGISTER_WAIT(reg, required_value, timeout) \
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

/* PCI_RC_REQISS Type of Request. */
typedef enum e_pcie_rc_reqiss_tr_type
{
    PCIE_RC_REQISS_TR_TYPE_ZERO_LENGTH_READ                  = 0x00,
    PCIE_RC_REQISS_TR_TYPE_CONFIGURATION_READ_TYPE0          = 0x04,
    PCIE_RC_REQISS_TR_TYPE_CONFIGURATION_WRITE_TYPE0         = 0x05,
    PCIE_RC_REQISS_TR_TYPE_CONFIGURATION_READ_TYPE1          = 0x06,
    PCIE_RC_REQISS_TR_TYPE_CONFIGURATION_WRITE_TYPE1         = 0x07,
    PCIE_RC_REQISS_TR_TYPE_MESSAGE_REQUEST                   = 0x08,
    PCIE_RC_REQISS_TR_TYPE_MESSAGE_REQUEST_WITH_DATA_PALYOAD = 0x09,
} pcie_rc_reqiss_tr_type_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static inline void r_pcie_rc_write_protect_enable(pcie_rc_instance_ctrl_t * p_instance_ctrl, uint32_t bit_mask);
static inline void r_pcie_rc_write_protect_disable(pcie_rc_instance_ctrl_t * p_instance_ctrl, uint32_t bit_mask);

static void r_pcie_rc_xcfgd_setting(pcie_rc_instance_ctrl_t * p_instance_ctrl);
static void r_pcie_rc_xcfga_cmn_setting(pcie_rc_instance_ctrl_t * p_instance_ctrl);

#if (1 == BSP_FEATURE_PCIE_PHY_XCFG_SETTING_PATTERN)
static void r_pcie_rc_xcfga_la0_setting(pcie_rc_instance_ctrl_t * p_instance_ctrl);
static void r_pcie_rc_xcfga_la1_setting(pcie_rc_instance_ctrl_t * p_instance_ctrl);

#elif (2 == BSP_FEATURE_PCIE_PHY_XCFG_SETTING_PATTERN)
static uint32_t r_pcie_rc_get_otp_value(void);

#endif

static void r_pcie_rc_window_setting(pcie_rc_instance_ctrl_t * p_instance_ctrl);
static void r_pcie_rc_enable_irq(IRQn_Type const irq, uint32_t priority, void * p_context);
static void r_pcie_rc_disable_irq(IRQn_Type irq);
static void r_pcie_rc_interrupt_setup(pcie_rc_instance_ctrl_t * p_instance_ctrl);

static void r_pcie_rc_configuration_register_type1_init(pcie_rc_instance_ctrl_t * p_instance_ctrl);
static void r_pcie_rc_self_configuration_register_write(pcie_rc_instance_ctrl_t * p_instance_ctrl,
                                                        uint32_t                  register_number,
                                                        uint32_t                  register_value);
static void r_pcie_rc_self_configuration_register_read(pcie_rc_instance_ctrl_t * p_instance_ctrl,
                                                       uint32_t                  register_number,
                                                       uint32_t                * p_register_value);
static void r_pcie_rc_call_callback(pcie_rc_instance_ctrl_t * p_ctrl, pci_callback_args_t * p_args);
static void r_pcie_common_intx_handler(pci_event_t event);

/***********************************************************************************************************************
 * ISR prototypes
 **********************************************************************************************************************/
void pcie_rc_message_receive_handler(void);
void pcie_rc_power_off_indication_handler(void);
void pcie_rc_inta_handler(void);
void pcie_rc_intb_handler(void);
void pcie_rc_intc_handler(void);
void pcie_rc_intd_handler(void);
void pcie_rc_msi_handler(void);
void pcie_rc_event_handler(void);
void pcie_rc_link_equalization_request_handler(void);
void pcie_rc_link_width_change_handler(void);

void pcie_rc_correctable_error_handler(uint32_t id);
void pcie_rc_non_fatal_error_handler(uint32_t id);
void pcie_rc_fatal_error_handler(uint32_t id);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
#if (1 == BSP_FEATURE_PCIE_PHY_XCFG_SETTING_PATTERN)
static const uint32_t pcie_rc_phy_xcfgd_setting_value[BSP_FEATURE_PCIE_RC_PHY_XCFGD_SETTING_VALUE_NUM] =
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

static const uint32_t pcie_rc_phy_xcfga_cmn_setting_value[BSP_FEATURE_PCIE_RC_PHY_XCFGA_CMN_SETTING_VALUE_NUM] =
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

static const uint32_t pcie_rc_phy_xcfga_la0_setting_value[BSP_FEATURE_PCIE_RC_PHY_XCFGA_CMN_SETTING_VALUE_NUM] =
{
    0x08000000,                        /* Setting value of XCFGA_LN0 (offset 0x000) */
    0x00050400,                        /* Setting value of XCFGA_LN0 (offset 0x010) */
    0xE0003300,                        /* Setting value of XCFGA_LN0 (offset 0x020) */
    0xC0400FBF,                        /* Setting value of XCFGA_LN0 (offset 0x030) */
    0x960902A0,                        /* Setting value of XCFGA_LN0 (offset 0x040) */
    0x00020860                         /* Setting value of XCFGA_LN0 (offset 0x050) */
};

static const uint32_t pcie_rc_phy_xcfga_la1_setting_value[BSP_FEATURE_PCIE_RC_PHY_XCFGA_CMN_SETTING_VALUE_NUM] =
{
    0x08000000,                        /* Setting value of XCFGA_LN1 (offset 0x000) */
    0x00050400,                        /* Setting value of XCFGA_LN1 (offset 0x010) */
    0xE0003300,                        /* Setting value of XCFGA_LN1 (offset 0x020) */
    0xC0400FBF,                        /* Setting value of XCFGA_LN1 (offset 0x030) */
    0x960902A0,                        /* Setting value of XCFGA_LN1 (offset 0x040) */
    0x00020860                         /* Setting value of XCFGA_LN1 (offset 0x050) */
};
#else
static const uint32_t pcie_rc_phy_xcfgd_setting_value[BSP_FEATURE_PCIE_RC_PHY_XCFGD_SETTING_VALUE_NUM] =
{
    0x00000000,                        /* Setting value of XCFGD (offset 0x000) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x010) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x020) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x030) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x040) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x050) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x060) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x070) */
    0xE0006801,                        /* Setting value of XCFGD (offset 0x080) */
    0x007F7E30,                        /* Setting value of XCFGD (offset 0x090) */
    0x403E0000,                        /* Setting value of XCFGD (offset 0x0A0) */
    0x978FF500,                        /* Setting value of XCFGD (offset 0x0B0) */
    0xEC000000,                        /* Setting value of XCFGD (offset 0x0C0) */
    0x009F1400,                        /* Setting value of XCFGD (offset 0x0D0) */
    0x0000E000,                        /* Setting value of XCFGD (offset 0x0E0) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x0F0) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x100) */
    0x78000000,                        /* Setting value of XCFGD (offset 0x110) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x120) */
    0x00880000,                        /* Setting value of XCFGD (offset 0x130) */
    0x000005C0,                        /* Setting value of XCFGD (offset 0x140) */
    0x1E000000,                        /* Setting value of XCFGD (offset 0x150) */
    0x00780920,                        /* Setting value of XCFGD (offset 0x160) */
    0xC94005E2,                        /* Setting value of XCFGD (offset 0x170) */
    0x90000A04,                        /* Setting value of XCFGD (offset 0x180) */
    0x00161414,                        /* Setting value of XCFGD (offset 0x190) */
    0x00004834,                        /* Setting value of XCFGD (offset 0x1A0) */
    0x00006000,                        /* Setting value of XCFGD (offset 0x1B0) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x1C0) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x1D0) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x1E0) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x1F0) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x200) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x210) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x220) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x230) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x240) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x250) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x260) */
};

static const uint32_t pcie_rc_phy_xcfga_cmn_setting_value[BSP_FEATURE_PCIE_RC_PHY_XCFGA_CMN_SETTING_VALUE_NUM] =
{
    0x20B0081C,                        /* Setting value of XCFGD (offset 0x400) */
    0x0A013D10,                        /* Setting value of XCFGD (offset 0x410) */
    0x20010000,                        /* Setting value of XCFGD (offset 0x420) */
    0x00170C00,                        /* Setting value of XCFGD (offset 0x430) */
    0x25000600,                        /* Setting value of XCFGD (offset 0x440) */
    0xFDC36C08,                        /* Setting value of XCFGD (offset 0x450) */
    0x005B4000,                        /* Setting value of XCFGD (offset 0x460) */
    0x80909028,                        /* Setting value of XCFGD (offset 0x470) */
    0x90905800,                        /* Setting value of XCFGD (offset 0x480) */
    0x00580080,                        /* Setting value of XCFGD (offset 0x490) */
    0x00281919,                        /* Setting value of XCFGD (offset 0x4A0) */
    0x00686868,                        /* Setting value of XCFGD (offset 0x4B0) */
    0x00000202,                        /* Setting value of XCFGD (offset 0x4C0) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x4D0) */
    0x00200000,                        /* Setting value of XCFGD (offset 0x4E0) */
    0x00000020,                        /* Setting value of XCFGD (offset 0x4F0) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x500) */
    0x83328088,                        /* Setting value of XCFGD (offset 0x510) */
    0x20B0026F,                        /* Setting value of XCFGD (offset 0x520) */
    0x36B88233,                        /* Setting value of XCFGD (offset 0x530) */
    0xB08232D0,                        /* Setting value of XCFGD (offset 0x540) */
    0x1900A0A0,                        /* Setting value of XCFGD (offset 0x550) */
    0xC0002819,                        /* Setting value of XCFGD (offset 0x560) */
    0x19190091,                        /* Setting value of XCFGD (offset 0x570) */
    0x58670028,                        /* Setting value of XCFGD (offset 0x580) */
    0x00E0F50D,                        /* Setting value of XCFGD (offset 0x590) */
    0x00008000,                        /* Setting value of XCFGD (offset 0x5A0) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x5B0) */
    0x00020202,                        /* Setting value of XCFGD (offset 0x5C0) */
    0x000000FC,                        /* Setting value of XCFGD (offset 0x5D0) */
    0x000A000A,                        /* Setting value of XCFGD (offset 0x5E0) */
    0x00000800,                        /* Setting value of XCFGD (offset 0x5F0) */
    0x000A0000,                        /* Setting value of XCFGD (offset 0x600) */
    0x0800000A,                        /* Setting value of XCFGD (offset 0x610) */
    0x6A000000,                        /* Setting value of XCFGD (offset 0x620) */
    0x6A186A18,                        /* Setting value of XCFGD (offset 0x630) */
    0x80000018,                        /* Setting value of XCFGD (offset 0x640) */
    0x003000F0,                        /* Setting value of XCFGD (offset 0x650) */
    0x00000000,                        /* Setting value of XCFGD (offset 0x660) */
};
#endif

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/* Channel control struct array */
static pcie_rc_instance_ctrl_t * gp_instance_ctrl[2] = {NULL};

/** PCIE_RC implementation of PCI API. */
const pci_api_t g_pci_on_pcie_rc =
{
    .open                         = R_PCIE_RC_Open,
    .selfConfigurationRegisterGet = R_PCIE_RC_SelfConfigurationRegisterGet,
    .selfConfigurationRegisterSet = R_PCIE_RC_SelfConfigurationRegisterSet,
    .configurationRegisterRead    = R_PCIE_RC_ConfigurationRegisterRead,
    .configurationRegisterWrite   = R_PCIE_RC_ConfigurationRegisterWrite,
    .iORegisterWrite              = R_PCIE_RC_IORegisterWrite,
    .iORegisterRead               = R_PCIE_RC_IORegisterRead,
    .messageWrite                 = R_PCIE_RC_MessageWrite,
    .messageRead             = R_PCIE_RC_MessageRead,
    .intxAssert              = R_PCIE_RC_IntxAssert,
    .intxDeassert            = R_PCIE_RC_IntxDeassert,
    .linkStatusGet           = R_PCIE_RC_LinkStatusGet,
    .linkWidthChange         = R_PCIE_RC_LinkWidthChange,
    .linkSpeedChange         = R_PCIE_RC_LinkSpeedChange,
    .linkEqualizationRequest = R_PCIE_RC_LinkEqualizationRequest,
    .callbackSet             = R_PCIE_RC_CallbackSet,
    .close                        = R_PCIE_RC_Close,
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZT
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_PCIE_RC
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initialize the PCIE_RC API.  Implements @ref pci_api_t::open.
 *
 * @retval FSP_SUCCESS              PCIE_RC successfully initialized.
 * @retval FSP_ERR_ASSERTION        Invalid input argument.
 * @retval FSP_ERR_ALREADY_OPEN     Module is already open.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_RC_Open (pci_ctrl_t * const p_ctrl, pci_cfg_t const * const p_cfg)
{
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) p_ctrl;

#if PCIE_RC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(PCIE_RC_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    pcie_rc_extended_cfg_t const * p_extend = (pcie_rc_extended_cfg_t const *) p_cfg->p_extend;

#if PCIE_RC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_extend->p_reg);
    FSP_ASSERT(NULL != p_extend->p_reg_spl);
#endif

    /* Initialize control structure.  */
    p_instance_ctrl->p_cfg     = p_cfg;
    p_instance_ctrl->channel   = p_cfg->channel;
    p_instance_ctrl->p_reg     = (R_PCIE0_Type *) p_extend->p_reg;
    p_instance_ctrl->p_reg_phy = (R_PCIE_PHY_Type *) R_PCIE_PHY_BASE;
    p_instance_ctrl->p_reg_spl = (R_PCIE_SPL0_Type *) p_extend->p_reg_spl;
#if (1 < BSP_FEATURE_PCIE_SUPPORT_LINK_WIDTH)
    p_instance_ctrl->p_reg_lnk = (R_PCIE_LNK_Type *) R_PCIE_LNK_BASE;
#endif

    /* Set the Root-complex mode and Channel Configuration.
     * Set MODE_PORT bit in the PCIE_MODE register to 1.
     * Set LINK_MASTER bits in the PCIE_LINKMODE register. */
    p_instance_ctrl->p_reg_spl->PCIE_MODE_b.MODE_PORT = PCIE_RC_PCIE_MODE_MODE_PORT_ROOT_COMPLEX;
#if (1 < BSP_FEATURE_PCIE_SUPPORT_LINK_WIDTH)
    p_instance_ctrl->p_reg_lnk->PCIE_LINKMODE = p_extend->link_mode;
#endif

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
     * Set RST_LOAD_B (bit4) and RST_CFG_B (bit3) in the PCI_RC_RESET to 1.*/
    p_instance_ctrl->p_reg->PCI_RC_RESET |= R_PCIE0_PCI_RC_RESET_RST_LOAD_B_Msk | R_PCIE0_PCI_RC_RESET_RST_CFG_B_Msk;

    /* Setting of the PHY.
     * Set the PCI_PHY_XCFGDn register (n = 0 to 26), PCI_PHY_XCFGA_CMNn register (n = 0 to 15),
     * PCI_PHY_XCFGA_L0n register (n = 0 to 5) and PCI_PHY_XCFGA_L1n register (n = 0 to 5). */
    r_pcie_rc_xcfgd_setting(p_instance_ctrl);
    r_pcie_rc_xcfga_cmn_setting(p_instance_ctrl);
#if (1 == BSP_FEATURE_PCIE_PHY_XCFG_SETTING_PATTERN)
    r_pcie_rc_xcfga_la0_setting(p_instance_ctrl);
    r_pcie_rc_xcfga_la1_setting(p_instance_ctrl);
#endif

    /* Enable writing of HwInit attribute registers */
    r_pcie_rc_write_protect_disable(p_instance_ctrl, R_PCIE0_PCI_RC_PERM_CFG_HWINIT_EN_Msk);

#if (2 >= BSP_FEATURE_PCIE_SUPPORT_GEN)

    /* If not supported PCI Express Gen3, need to change the default value.
     * Reference section "PCI_RC_LINKC : Link Capabilities Register" and
     * "PCI_RC_LINKC2 : Link Capabilities 2 Register" in the hardware manual. */
    p_instance_ctrl->p_reg->PCI_RC_LINKC_b.SLS   = PCIE_RC_LINKC_SLS_REG_GEN2_SETTING_VALUE;
    p_instance_ctrl->p_reg->PCI_RC_LINKC2_b.SLSV = PCIE_RC_LINKC2_SLSV_REG_GEN2_SETTING_VALUE;
#endif

    /* Setting of HWINT related registers */
    /* Setting PCI Express Configuration Registers (Type1 : Root Complex) */
    r_pcie_rc_configuration_register_type1_init(p_instance_ctrl);

#if (3 <= BSP_FEATURE_PCIE_SUPPORT_GEN)

    /* Setting Lane Equalization Control Register.
     * For the 2 lanes x 1 channel configuration:
     *     b27-b24 8: Upstream Port 8.0 GTs Transmitter Preset Lane1
     *     b19-b16 8: Downstream Port 8.0 GTs Transmitter Preset Lane1
     *     b11-b8  8: Upstream Port 8.0 GTs Transmitter Preset Lane0
     *     b3-b0   8: Downstream Port 8.0 GTs Transmitter Preset Lane0
     * For the 1 lane x 2 channels configuration:
     *     b11-b8  8: Upstream Port 8.0 GTs Transmitter Preset Lane0
     *     b3-b0   8: Downstream Port 8.0 GTs Transmitter Preset Lane0
     */
    p_instance_ctrl->p_reg->PCI_RC_LEQCTL = PCIE_RC_LEQCTL_SETTING_VALUE;
#endif

#if (3 <= BSP_FEATURE_PCIE_SUPPORT_GEN)

    /* Use Autonomous Mechanisms (Gen3 feature)
     * Set MODE_EQ_AUTONOMOUS bit in PCI_RC_PCCTRL1 to 1. */
    p_instance_ctrl->p_reg->PCI_RC_PCCTRL1 |= R_PCIE0_PCI_EP_MSET4_MODE_EQ_AUTONOMOUS1_Msk;
#endif

    /* Permit ASPM L1 State Transition.
     * Set ALLOW_ENTER_L1 bit in the PCIE_MISC register to 1. */
    p_instance_ctrl->p_reg_spl->PCIE_MISC |= R_PCIE_SPL0_PCIE_MISC_ALLOW_ENTER_L1_Msk;

    /* AXI/MSI/PCI Window settings */
    r_pcie_rc_window_setting(p_instance_ctrl);

    /* Disable writing of HwInit attribute registers */
    r_pcie_rc_write_protect_enable(p_instance_ctrl, R_PCIE0_PCI_RC_PERM_CFG_HWINIT_EN_Msk);

#if (((1 << 8UL) == PCIE_RC_CFG_LINK_MODE) || (0xFF == PCIE_RC_CFG_LINK_MODE))

    /* When using in single link mode, only common clock is supported, no separate clock.
     * Since initial value of PCI_RC_LINKCS CCC register is separate clock, setting should be changed.
     * Reference section "Other Points for Caution Clock setting in case of Single link mode" in the hardware manual. */
    p_instance_ctrl->p_reg->PCI_RC_LINKCS_b.CCC = PCIE_RC_LINKCS_CCC_REG_SINGLE_LINK_SETTING_VALUE;
#endif

    /* Interrupt Enable */
    r_pcie_rc_interrupt_setup(p_instance_ctrl);

    /* Release the reset (RST_PS_B, RST_GP_B, RST_B, RST_OUT_B).
     * Set RST_PS_B, RST_GP_B, RST_B and RST_OUT_B in the PCI_RC_RESET to 1. */
    p_instance_ctrl->p_reg->PCI_RC_RESET |=
        R_PCIE0_PCI_RC_RESET_RST_OUT_B_Msk | R_PCIE0_PCI_RC_RESET_RST_PS_B_Msk |
        R_PCIE0_PCI_RC_RESET_RST_GP_B_Msk | R_PCIE0_PCI_RC_RESET_RST_B_Msk;

    /* Wait for 500 us or more */
    R_BSP_SoftwareDelay(PCIE_RC_RELEASE_RESET_WAIT_US, BSP_DELAY_UNITS_MICROSECONDS);

    /* Release the reset (RST_RSM_B).
     * Set RST_RSM_B in the PCI_RC_RESET to 1.*/
    p_instance_ctrl->p_reg->PCI_RC_RESET |= R_PCIE0_PCI_RC_RESET_RST_RSM_B_Msk;

#if (2 >= BSP_FEATURE_PCIE_SUPPORT_GEN)

    /* If not supported PCI Express Gen3, need to change the default value.
     * Reference section "PCI_RC_LINKCS2 : Link Control 2/Status 2 Register" in the hardware manual. */
    p_instance_ctrl->p_reg->PCI_RC_LINKCS2_b.TLS = PCIE_RC_LINKCS2_TLS_REG_GEN2_SETTING_VALUE;
#endif

    /* Set callback and context pointers, if configured */
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = NULL;
    p_instance_ctrl->p_callback_memory = NULL;

    /* Track ctrl struct */
    gp_instance_ctrl[p_cfg->channel] = p_instance_ctrl;

    /* Mark the module as open so other APIs can be used. */
    p_instance_ctrl->open = PCIE_RC_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the value of configuration register of this PCIE device.
 * Implements @ref pci_api_t::selfConfigurationRegisterSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_RC_SelfConfigurationRegisterSet (pci_ctrl_t * const p_ctrl, uint32_t register_number, uint32_t data)
{
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) p_ctrl;
#if PCIE_RC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(PCIE_RC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    r_pcie_rc_self_configuration_register_write(p_instance_ctrl, register_number, data);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Gets the value of configuration register of this PCIE.
 * Implements @ref pci_api_t::selfConfigurationRegisterGet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_RC_SelfConfigurationRegisterGet (pci_ctrl_t * const p_ctrl, uint32_t register_number,
                                                  uint32_t * p_data)
{
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) p_ctrl;
#if PCIE_RC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_data);
    FSP_ERROR_RETURN(PCIE_RC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    r_pcie_rc_self_configuration_register_read(p_instance_ctrl, register_number, p_data);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Issuing CfgWr0/1 Request.  Implements @ref pci_api_t::configurationRegisterWrite.
 *
 * @retval FSP_SUCCESS                 The configuration write was issued successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_RC_ConfigurationRegisterWrite (pci_ctrl_t * const                            p_ctrl,
                                                pci_configuration_write_type_t                transaction_type,
                                                pci_configuration_register_transfer_t * const p_transfer)
{
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) p_ctrl;
#if PCIE_RC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_transfer);
    FSP_ERROR_RETURN(PCIE_RC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_instance_ctrl->p_reg->PCI_RC_REQADR1 = p_transfer->header_word;

    /* Request Byte Enable Registers */
    p_instance_ctrl->p_reg->PCI_RC_REQBE = 0x0000000F;

    p_instance_ctrl->p_reg->PCI_REQDATA[0].RC = 0x00000000;
    p_instance_ctrl->p_reg->PCI_REQDATA[1].RC = 0x00000000;
    p_instance_ctrl->p_reg->PCI_REQDATA[2].RC = p_transfer->data;

    pcie_rc_reqiss_tr_type_t message_type =
        (transaction_type == PCI_CONFIGURATION_WRITE_TYPE_0) ?
        PCIE_RC_REQISS_TR_TYPE_CONFIGURATION_WRITE_TYPE0 : PCIE_RC_REQISS_TR_TYPE_CONFIGURATION_WRITE_TYPE1;
    p_instance_ctrl->p_reg->PCI_RC_REQISS_b.TR_TYPE = message_type;

    /* Message issue. */
    p_instance_ctrl->p_reg->PCI_RC_REQISS |= R_PCIE0_PCI_RC_REQISS_RI_Msk;

    /* Wait for issuing request. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->PCI_RC_REQISS_b.RI, 0);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Issuing CfgRd0/1 Request.  Implements @ref pci_api_t::configurationRegisterRead.
 *
 * @retval FSP_SUCCESS                 The configuration write was issued successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_RC_ConfigurationRegisterRead (pci_ctrl_t * const                            p_ctrl,
                                               pci_configuration_read_type_t                 transaction_type,
                                               pci_configuration_register_transfer_t * const p_transfer)
{
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) p_ctrl;
#if PCIE_RC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_transfer);
    FSP_ERROR_RETURN(PCIE_RC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_instance_ctrl->p_reg->PCI_RC_REQADR1 = p_transfer->header_word;

    p_instance_ctrl->p_reg->PCI_RC_REQBE = 0x0000000F; /* fixed value */

    pcie_rc_reqiss_tr_type_t message_type =
        (transaction_type == PCI_CONFIGURATION_READ_TYPE_0) ?
        PCIE_RC_REQISS_TR_TYPE_CONFIGURATION_READ_TYPE0 : PCIE_RC_REQISS_TR_TYPE_CONFIGURATION_READ_TYPE1;
    p_instance_ctrl->p_reg->PCI_RC_REQISS_b.TR_TYPE = message_type;

    /* Message issue. */
    p_instance_ctrl->p_reg->PCI_RC_REQISS |= R_PCIE0_PCI_RC_REQISS_RI_Msk;

    /* Wait for issuing request. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->PCI_RC_REQISS_b.RI, 0);

    /* PCI_RC_REQRCVDAT */
    p_transfer->data = p_instance_ctrl->p_reg->PCI_RC_REQRCVDAT;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Issuing IOWr Request.  API not supported. Implements @ref pci_api_t::iORegisterWrite.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by PCIE_RC.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_RC_IORegisterWrite (pci_ctrl_t * const p_ctrl, pci_io_register_transfer_t * const p_transfer)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_transfer);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Issuing IORd Request.  API not supported. Implements @ref pci_api_t::iORegisterRead.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by PCIE_RC.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_RC_IORegisterRead (pci_ctrl_t * const p_ctrl, pci_io_register_transfer_t * const p_transfer)
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
fsp_err_t R_PCIE_RC_MessageWrite (pci_ctrl_t * const p_ctrl, pci_message_transfer_t * const p_transfer, bool with_data)
{
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) p_ctrl;

#if PCIE_RC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_transfer);
    FSP_ERROR_RETURN(PCIE_RC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    uint32_t header = (uint32_t) ((p_transfer->header_1st_word_b.routing_type & 0x07) << 24) |
                      (uint32_t) ((p_transfer->header_2nd_word_b.message_code & UINT8_MAX));

    p_instance_ctrl->p_reg->PCI_RC_REQADR1    = header;
    p_instance_ctrl->p_reg->PCI_REQDATA[0].RC = p_transfer->header_3rd;
    p_instance_ctrl->p_reg->PCI_REQDATA[1].RC = p_transfer->header_4th;

    if (true == with_data)
    {
        p_instance_ctrl->p_reg->PCI_REQDATA[2].RC = p_transfer->data;

        pcie_rc_reqiss_tr_type_t message_type = PCIE_RC_REQISS_TR_TYPE_MESSAGE_REQUEST_WITH_DATA_PALYOAD;
        p_instance_ctrl->p_reg->PCI_RC_REQISS_b.TR_TYPE = message_type;
    }
    else
    {
        pcie_rc_reqiss_tr_type_t message_type = PCIE_RC_REQISS_TR_TYPE_MESSAGE_REQUEST;
        p_instance_ctrl->p_reg->PCI_RC_REQISS_b.TR_TYPE = message_type;
    }

    /* Message issue. */
    p_instance_ctrl->p_reg->PCI_RC_REQISS |= R_PCIE0_PCI_RC_REQISS_RI_Msk;

    /* Wait for issuing request. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->PCI_RC_REQISS_b.RI, 0);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Read message data from PCI.  Implements @ref pci_api_t::messageRead.
 *
 * @retval FSP_SUCCESS                 The message was read successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_RC_MessageRead (pci_ctrl_t * const p_ctrl, pci_message_transfer_t * const p_transfer)
{
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) p_ctrl;

#if PCIE_RC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_transfer);
    FSP_ERROR_RETURN(PCIE_RC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    uint32_t msgcode = p_instance_ctrl->p_reg->PCI_RC_MSGCODE;

    p_transfer->header_1st_word_b.routing_type = (msgcode & R_PCIE0_PCI_RC_MSGCODE_R_Msk) >>
                                                 R_PCIE0_PCI_RC_MSGCODE_R_Pos;
    p_transfer->header_2nd_word_b.message_code = (msgcode & R_PCIE0_PCI_RC_MSGCODE_MC_Msk) >>
                                                 R_PCIE0_PCI_RC_MSGCODE_MC_Pos;
    p_transfer->header_3rd = p_instance_ctrl->p_reg->PCI_RC_MSGH3DW;
    p_transfer->header_4th = p_instance_ctrl->p_reg->PCI_RC_MSGH4DW;

    /* Check the presence or absence of the data payload of the last received Message.
     * If message data is presence, read from PCI_RC_MSGDATA. */
    p_transfer->data = ((msgcode & R_PCIE0_PCI_RC_MSGCODE_MP_Msk) >> R_PCIE0_PCI_RC_MSGCODE_MP_Pos) == 0 ?
                       0 : p_instance_ctrl->p_reg->PCI_RC_MSGDATA;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Assert INTx interrupt Request. API not supported.
 *
 * Implements @ref pci_api_t::intxAssert.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by PCIE_RC.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_RC_IntxAssert (pci_ctrl_t * const p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Deassert INTx interrupt Request. API not supported.
 *
 * Implements @ref pci_api_t::intxDeassert.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by PCIE_RC.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_RC_IntxDeassert (pci_ctrl_t * const p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Gets the Link status and LTSSM state. Implements @ref pci_api_t::linkStatusGet.
 *
 * @retval FSP_SUCCESS                 The PCI status is in p_status.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_RC_LinkStatusGet (pci_ctrl_t * const p_ctrl, pci_status_t * const p_status)
{
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) p_ctrl;
#if PCIE_RC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(PCIE_RC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    uint32_t status = p_instance_ctrl->p_reg->PCI_RC_PCSTAT1;
    if ((status & R_PCIE0_PCI_RC_PCSTAT1_DLDS_Msk) == 0)
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
    uint32_t ltssm_state              = p_instance_ctrl->p_reg->PCI_RC_PCSTAT1_b.LTSSM_STATE;
    uint32_t ltssm_state_upper_5_bits = (ltssm_state >> 2) & 0x1FU;
    uint32_t ltssm_state_upper_3_bits =
        (ltssm_state_upper_5_bits & PCIE_RC_PCI_RC_PCSTAT1_LTSSM_STATE_UPPER_3_BIT_MASK) >> 2U;

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
        uint32_t ltssm_state_lower_2_bits = ltssm_state_upper_5_bits & 0x3U;
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
fsp_err_t R_PCIE_RC_LinkWidthChange (pci_ctrl_t * const p_ctrl, uint32_t link_width, uint32_t option)
{
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) p_ctrl;

#if PCIE_RC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN(PCIE_RC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(0 == (link_width & 0xFFFFFFFC), FSP_ERR_INVALID_ARGUMENT);
#endif

    p_instance_ctrl->p_reg->PCI_RC_PCCTRL2 |=
        (link_width << R_PCIE0_PCI_RC_PCCTRL2_UI_LINK_WIDTH_CHANGE_ENABLE_Pos) |
        (option << R_PCIE0_PCI_RC_PCCTRL2_UI_LINK_CHANGE_AUTONOMOUS_Pos);

    /* Issue a request to change Link Width. */
    p_instance_ctrl->p_reg->PCI_RC_PCCTRL2 |= R_PCIE0_PCI_RC_PCCTRL2_UI_LINK_WIDTH_CHANGE_REQ_Msk;

    /* UI_LINK_WIDTH_CHANGE_REQ bit set to 0 after confirming that PCIe Core Status Register UI_LINK_WIDTH_CHANGE_DONE is asserted. */
    uint32_t timeout_count = PCIE_RC_REQUEST_TIMEOUT_US;
    PCIE_RC_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->PCI_RC_PCSTAT2_b.UI_LINK_WIDTH_CHANGE_DONE, 1U,
                                   timeout_count);
    FSP_ERROR_RETURN((0U != timeout_count), FSP_ERR_TIMEOUT);

    p_instance_ctrl->p_reg->PCI_RC_PCCTRL2 &= (uint32_t) (~R_PCIE0_PCI_RC_PCCTRL2_UI_LINK_WIDTH_CHANGE_REQ_Msk);

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
fsp_err_t R_PCIE_RC_LinkSpeedChange (pci_ctrl_t * const p_ctrl, pci_link_speed_t link_speed, uint32_t option)
{
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) p_ctrl;

#if PCIE_RC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN(PCIE_RC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(link_speed < PCI_LINK_SPEED_16_0_GTS, FSP_ERR_INVALID_ARGUMENT);
#endif

    p_instance_ctrl->p_reg->PCI_RC_PCCTRL2 |=
        (uint32_t) (link_speed << R_PCIE0_PCI_RC_PCCTRL2_UI_LINK_SPEED_CHANGE_Pos) |
        (option << R_PCIE0_PCI_RC_PCCTRL2_UI_LINK_CHANGE_AUTONOMOUS_Pos);

    /* Issue a request to change the Link Speed. */
    p_instance_ctrl->p_reg->PCI_RC_PCCTRL2 |= R_PCIE0_PCI_RC_PCCTRL2_UI_LINK_SPEED_CHANGE_REQ_Msk;

    /* UI_LINK_SPEED_CHANGE_REQ bit set to 0 after confirming that PCIe Core Status Register UI_LINK_SPEED_CHANGE_DONE is asserted. */
    uint32_t timeout_count = PCIE_RC_REQUEST_TIMEOUT_US;
    PCIE_RC_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->PCI_RC_PCSTAT2_b.UI_LINK_SPEED_CHANGE_DONE, 1U,
                                   timeout_count);
    FSP_ERROR_RETURN((0U != timeout_count), FSP_ERR_TIMEOUT);

    p_instance_ctrl->p_reg->PCI_RC_PCCTRL2 &= (uint32_t) (~R_PCIE0_PCI_RC_PCCTRL2_UI_LINK_SPEED_CHANGE_REQ_Msk);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Requires the PCI Express link equalization request. Implements @ref pci_api_t::linkEqualizationRequest.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_TIMEOUT              Link Equalization was not done in time and timeout occurred.
 * @retval  FSP_ERR_UNSUPPORTED          If PCI Express Gen3 is not supported, the function is not supported.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_RC_LinkEqualizationRequest (pci_ctrl_t * const p_ctrl)
{
#if (3 <= BSP_FEATURE_PCIE_SUPPORT_GEN)
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) p_ctrl;

 #if PCIE_RC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN(PCIE_RC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
 #endif

    /* Send Equalization Request. */
    p_instance_ctrl->p_reg->PCI_RC_MSET4 |= R_PCIE0_PCI_RC_MSET4_UI_EQ_REQUEST_Msk;

    /* After UI_EQ_REQUEST set to 1, hold until confirmation of UI_EQ_DONE = 1. */
    uint32_t timeout_count = PCIE_RC_REQUEST_TIMEOUT_US;
    PCIE_RC_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->PCI_RC_MSTAT0_b.UI_EQ_DONE, 1U, timeout_count);
    FSP_ERROR_RETURN((0U != timeout_count), FSP_ERR_TIMEOUT);

    p_instance_ctrl->p_reg->PCI_RC_MSET4 &= (uint32_t) (~R_PCIE0_PCI_RC_MSET4_UI_EQ_REQUEST_Msk);

    return FSP_SUCCESS;
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);

    return FSP_ERR_UNSUPPORTED;
#endif
}

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 * Implements @ref pci_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_RC_CallbackSet (pci_ctrl_t * const          p_ctrl,
                                 void (                    * p_callback)(pci_callback_args_t *),
                                 void * const                p_context,
                                 pci_callback_args_t * const p_callback_memory)
{
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) p_ctrl;

#if PCIE_RC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(PCIE_RC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */
    p_instance_ctrl->p_callback        = p_callback;
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Closes the PCIE_RC module.  Implements @ref pci_api_t::close.
 *
 * @retval FSP_SUCCESS                 The module is successfully closed.
 * @retval FSP_ERR_ASSERTION           Invalid input argument.
 * @retval FSP_ERR_NOT_OPEN            Module is not open.
 **********************************************************************************************************************/
fsp_err_t R_PCIE_RC_Close (pci_ctrl_t * const p_ctrl)
{
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) p_ctrl;

#if PCIE_RC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN(PCIE_RC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Get config and extend struct */
    pci_cfg_t              * p_cfg    = (pci_cfg_t *) p_instance_ctrl->p_cfg;
    pcie_rc_extended_cfg_t * p_extend = (pcie_rc_extended_cfg_t *) p_cfg->p_extend;

    /* Disable interrupts */
    r_pcie_rc_disable_irq(p_instance_ctrl->p_cfg->inta_irq);
    r_pcie_rc_disable_irq(p_instance_ctrl->p_cfg->intb_irq);
    r_pcie_rc_disable_irq(p_instance_ctrl->p_cfg->intc_irq);
    r_pcie_rc_disable_irq(p_instance_ctrl->p_cfg->intd_irq);
    r_pcie_rc_disable_irq(p_instance_ctrl->p_cfg->msi_irq);
    r_pcie_rc_disable_irq(p_extend->msg_irq);
    r_pcie_rc_disable_irq(p_extend->link_width_change_irq);
    r_pcie_rc_disable_irq(p_extend->link_equalization_request_irq);
    r_pcie_rc_disable_irq(p_extend->pcie_event_irq);
    r_pcie_rc_disable_irq(p_extend->poweroff_indication_l2_irq);

    /* Reset/Stop PCIE module if other is not open */
    if (NULL == gp_instance_ctrl[!p_cfg->channel])
    {
        p_instance_ctrl->p_reg->PCI_RC_RESET &= (uint32_t) (~R_PCIE0_PCI_RC_RESET_RST_RSM_B_Msk);

        /* Wait for 500 us or more */
        R_BSP_SoftwareDelay(PCIE_RC_RELEASE_RESET_WAIT_US, BSP_DELAY_UNITS_MICROSECONDS);

        p_instance_ctrl->p_reg->PCI_RC_RESET &=
            (uint32_t) (~(R_PCIE0_PCI_RC_RESET_RST_OUT_B_Msk | R_PCIE0_PCI_RC_RESET_RST_PS_B_Msk |
                          R_PCIE0_PCI_RC_RESET_RST_GP_B_Msk | R_PCIE0_PCI_RC_RESET_RST_B_Msk));

        p_instance_ctrl->p_reg->PCI_RC_RESET &=
            (uint32_t) (~(R_PCIE0_PCI_RC_RESET_RST_LOAD_B_Msk | R_PCIE0_PCI_RC_RESET_RST_CFG_B_Msk));

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

    p_instance_ctrl->open = 0U;

    /* All done, return success. */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup PCIE_RC)
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
 * @param[in]  bit_mask                The bit position of PCI_RC_PERM.
 **********************************************************************************************************************/
static inline void r_pcie_rc_write_protect_enable (pcie_rc_instance_ctrl_t * p_instance_ctrl, uint32_t bit_mask)
{
    p_instance_ctrl->p_reg->PCI_RC_PERM &= ~bit_mask;
}

/*******************************************************************************************************************//**
 * Disables write protection.
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 * @param[in]  bit_mask                The bit position of PCI_RC_PERM.
 **********************************************************************************************************************/
static inline void r_pcie_rc_write_protect_disable (pcie_rc_instance_ctrl_t * p_instance_ctrl, uint32_t bit_mask)
{
    p_instance_ctrl->p_reg->PCI_RC_PERM |= bit_mask;
}

/*******************************************************************************************************************//**
 * Initializes PCI_PHY_XCFGDn register (n = 0 to 26).
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 **********************************************************************************************************************/
static void r_pcie_rc_xcfgd_setting (pcie_rc_instance_ctrl_t * p_instance_ctrl)
{
    /* Enable writing of physical layer control/status registers */
    r_pcie_rc_write_protect_disable(p_instance_ctrl, R_PCIE0_PCI_RC_PERM_PHY_REG_CLK_EN_Msk);

    /* Set the value to PCI_PHY_XCFGn register.
     * See RZ microprocessor Hardware Manual section "PCI_PHY_XCFGDn : XCFGD Setting Register n (n = 0 to 26)"
     * for more details. */
    for (uint32_t i = 0; i < BSP_FEATURE_PCIE_RC_PHY_XCFGD_SETTING_VALUE_NUM; i++)
    {
        p_instance_ctrl->p_reg_phy->PCI_PHY_XCFGD[i].XCFGD = pcie_rc_phy_xcfgd_setting_value[i];
    }

    /* Disable writing of physical layer control/status registers */
    r_pcie_rc_write_protect_enable(p_instance_ctrl, R_PCIE0_PCI_RC_PERM_PHY_REG_CLK_EN_Msk);
}

/*******************************************************************************************************************//**
 * Initializes PCI_PHY_XCFGA_CMNn register (n = 0 to 15).
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 **********************************************************************************************************************/
static void r_pcie_rc_xcfga_cmn_setting (pcie_rc_instance_ctrl_t * p_instance_ctrl)
{
    /* Enable writing of physical layer control/status registers */
    r_pcie_rc_write_protect_disable(p_instance_ctrl, R_PCIE0_PCI_RC_PERM_PHY_REG_CLK_EN_Msk);

    /* Set the value to PCI_PHY_XCFGA_CMNn register.
     * See RZ microprocessor Hardware Manual section "PCI_PHY_XCFGA_CMNn : XCFGA_CMN Setting Register n (n = 0 to 15)"
     * for more details. */
    for (uint32_t i = 0; i < BSP_FEATURE_PCIE_RC_PHY_XCFGA_CMN_SETTING_VALUE_NUM; i++)
    {
#if (1 == BSP_FEATURE_PCIE_PHY_XCFG_SETTING_PATTERN)
        p_instance_ctrl->p_reg_phy->PCI_PHY_XCFGA_CMN[i].XCFGA_CMN = pcie_rc_phy_xcfga_cmn_setting_value[i];
#else
        if (i == 2)
        {
            uint32_t phy_trimming_code = r_pcie_rc_get_otp_value();
            p_instance_ctrl->p_reg_phy->PCI_PHY_XCFGA_CMN[i].XCFGA_CMN = pcie_rc_phy_xcfga_cmn_setting_value[i] |
                                                                         phy_trimming_code;
        }
        else
        {
            p_instance_ctrl->p_reg_phy->PCI_PHY_XCFGA_CMN[i].XCFGA_CMN = pcie_rc_phy_xcfga_cmn_setting_value[i];
        }
#endif
    }

    /* Disable writing of physical layer control/status registers */
    r_pcie_rc_write_protect_enable(p_instance_ctrl, R_PCIE0_PCI_RC_PERM_PHY_REG_CLK_EN_Msk);
}

#if (1 == BSP_FEATURE_PCIE_PHY_XCFG_SETTING_PATTERN)

/*******************************************************************************************************************//**
 * Initializes PCI_PHY_XCFGA_L0n register (n = 0 to 5).
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 **********************************************************************************************************************/
static void r_pcie_rc_xcfga_la0_setting (pcie_rc_instance_ctrl_t * p_instance_ctrl)
{
    /* Enable writing of physical layer control/status registers */
    r_pcie_rc_write_protect_disable(p_instance_ctrl, R_PCIE0_PCI_RC_PERM_PHY_REG_CLK_EN_Msk);

    /* Set the value to PCI_PHY_XCFGA_L0n register.
     * See RZ microprocessor Hardware Manual section "PCI_PHY_XCFGA_L0n : XCFGA_LN0 Setting Register n (n = 0 to 5)"
     * for more details. */
    for (uint32_t i = 0; i < PCIE_RC_PHY_XCFGA_LA0_SETTING_NUM; i++)
    {
        p_instance_ctrl->p_reg_phy->PCI_PHY_XCFGA_L0[i].XCFGA_LN0 = pcie_rc_phy_xcfga_la0_setting_value[i];
    }

    /* Disable writing of physical layer control/status registers */
    r_pcie_rc_write_protect_enable(p_instance_ctrl, R_PCIE0_PCI_RC_PERM_PHY_REG_CLK_EN_Msk);
}

/*******************************************************************************************************************//**
 * Initializes PCI_PHY_XCFGA_L1n register (n = 0 to 5).
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 **********************************************************************************************************************/
static void r_pcie_rc_xcfga_la1_setting (pcie_rc_instance_ctrl_t * p_instance_ctrl)
{
    /* Enable writing of physical layer control/status registers */
    r_pcie_rc_write_protect_disable(p_instance_ctrl, R_PCIE0_PCI_RC_PERM_PHY_REG_CLK_EN_Msk);

    /* Set the value to PCI_PHY_XCFGA_L1n register.
     * See RZ microprocessor Hardware Manual section "PCI_PHY_XCFGA_L1n : XCFGA_LN1 Setting Register n (n = 0 to 5)"
     * for more details. */
    for (uint32_t i = 0; i < PCIE_RC_PHY_XCFGA_LA1_SETTING_NUM; i++)
    {
        p_instance_ctrl->p_reg_phy->PCI_PHY_XCFGA_L1[i].XCFGA_LN1 = pcie_rc_phy_xcfga_la1_setting_value[i];
    }

    /* Disable writing of physical layer control/status registers */
    r_pcie_rc_write_protect_enable(p_instance_ctrl, R_PCIE0_PCI_RC_PERM_PHY_REG_CLK_EN_Msk);
}

#elif (2 == BSP_FEATURE_PCIE_PHY_XCFG_SETTING_PATTERN)

/*******************************************************************************************************************//**
 * Get OTP data.
 *
 * @retval  pcie_trimming_code  OTP data
 **********************************************************************************************************************/
static uint32_t r_pcie_rc_get_otp_value (void)
{
    uint32_t pcie_trimming_code_low;
    uint32_t pcie_trimming_code_high;
    uint32_t pcie_trimming_code;

    /* OTP power on setting. */
    R_OTP->OTPPWR = R_OTP_OTPPWR_PWR_Msk | R_OTP_OTPPWR_ACCL_Msk;
    FSP_HARDWARE_REGISTER_WAIT(R_OTP->OTPSTR_b.CMD_RDY, 1);

    /* Set the PCIe PHY trimming code Low address to the OTPADRRD register. */
    R_OTP->OTPADRRD = BSP_FEATURE_PCIE_TRIMMING_CODE_LOW_ADDRESS;

    /* Read PCIe PHY trimming code Low. */
    pcie_trimming_code_low = R_OTP->OTPDATARD;

    /* Set the PCIe PHY trimming code High address to the OTPADRRD register. */
    R_OTP->OTPADRRD = BSP_FEATURE_PCIE_TRIMMING_CODE_HIGH_ADDRESS;

    /* Read PCIe PHY trimming code High. */
    pcie_trimming_code_high = R_OTP->OTPDATARD;

    pcie_trimming_code = pcie_trimming_code_low | (pcie_trimming_code_high << 16);

    /* OTP power off setting. */
    R_OTP->OTPPWR &= (uint32_t) ~(R_OTP_OTPPWR_PWR_Msk | R_OTP_OTPPWR_ACCL_Msk);
    FSP_HARDWARE_REGISTER_WAIT(R_OTP->OTPSTR_b.CMD_RDY, 0);

    return pcie_trimming_code;
}

#endif

/*******************************************************************************************************************//**
 * Initializes AXI / PCI / MSI window.
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 **********************************************************************************************************************/
static void r_pcie_rc_window_setting (pcie_rc_instance_ctrl_t * p_instance_ctrl)
{
    pcie_rc_extended_cfg_t const * p_extend = (pcie_rc_extended_cfg_t const *) p_instance_ctrl->p_cfg->p_extend;

    /* Set AXI Window n n : 0 - 3 */
    for (uint32_t i = 0; i < R_PCIE_RC_NUM_AXI_WINDOW; i++)
    {
        pcie_rc_window_settings_t const * p_axi_window_settings = &(p_extend->axi_window_settings[i]);

        uint32_t address_offset = PCIE_RC_WINDOW_SETTING_ADDR_NTH_OFFSET * i;

        /* Set the AXI Window Base Register */
        uint32_t * p_awbasel =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_RC_AWBASEL0 + address_offset);
        *p_awbasel = p_axi_window_settings->base_address & R_PCIE0_PCI_RC_AWBASEL0_AWB3112_Msk;

        uint32_t * p_awbaseu =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_RC_AWBASEU0 + address_offset);
        *p_awbaseu =
            (uint32_t) ((p_axi_window_settings->base_address >> PCIE_RC_SHIFT_FOR_UPPER_32BIT_VALUE) & UINT32_MAX);

        /* Set the AXI Window Mask Register */
        uint32_t * p_awmaskl =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_RC_AWMASKL0 + address_offset);
        *p_awmaskl = p_axi_window_settings->mask_address & UINT32_MAX;

        uint32_t * p_awmasku =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_RC_AWMASKU0 + address_offset);
        *p_awmasku =
            (uint32_t) ((p_axi_window_settings->mask_address >> PCIE_RC_SHIFT_FOR_UPPER_32BIT_VALUE) &
                        R_PCIE0_PCI_RC_AWMASKU0_AWM6232_Msk);

        /* Set the AXI Destination Register */
        uint32_t * p_adestl =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_RC_ADESTL0 + address_offset);
        *p_adestl = p_axi_window_settings->destination_address & UINT32_MAX;

        uint32_t * p_adestu =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_RC_ADESTU0 + address_offset);
        *p_adestu =
            (uint32_t) ((p_axi_window_settings->destination_address >> PCIE_RC_SHIFT_FOR_UPPER_32BIT_VALUE) &
                        UINT32_MAX);

        /* Set the AXI Window enable */
        *p_awbasel |= p_axi_window_settings->window_enable;
    }

    /* Set PCIe Window n n : 0 - 3 */
    for (uint32_t i = 0; i < R_PCIE_RC_NUM_PCIE_WINDOW; i++)
    {
        pcie_rc_window_settings_t const * p_pci_window_settings = &(p_extend->pci_window_settings[i]);

        uint32_t address_offset = PCIE_RC_WINDOW_SETTING_ADDR_NTH_OFFSET * i;

        /* Set the PCIe Window Base Register */
        uint32_t * p_pwbasel =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_RC_PWBASEL0 + address_offset);
        *p_pwbasel = p_pci_window_settings->base_address & R_PCIE0_PCI_RC_PWBASEL0_PWB3112_Msk;

        uint32_t * p_pwbaseu =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_RC_PWBASEU0 + address_offset);
        *p_pwbaseu =
            (uint32_t) ((p_pci_window_settings->base_address >> PCIE_RC_SHIFT_FOR_UPPER_32BIT_VALUE) & UINT32_MAX);

        /* Set the PCIe Window Mask Register */
        uint32_t * p_pwmaskl =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_RC_PWMASKL0 + address_offset);
        *p_pwmaskl = p_pci_window_settings->mask_address & UINT32_MAX;

        uint32_t * p_pwmasku =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_RC_PWMASKU0 + address_offset);
        *p_pwmasku =
            (uint32_t) ((p_pci_window_settings->mask_address >> PCIE_RC_SHIFT_FOR_UPPER_32BIT_VALUE) &
                        R_PCIE0_PCI_RC_PWMASKU0_PWM6232_Msk);

        /* Set the PCIe Destination Register */
        uint32_t * p_pdestl =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_RC_PDESTL0 + address_offset);
        *p_pdestl = p_pci_window_settings->destination_address & UINT32_MAX;

        uint32_t * p_pdestu =
            (uint32_t *) ((uintptr_t) &p_instance_ctrl->p_reg->PCI_RC_PDESTU0 + address_offset);
        *p_pdestu =
            (uint32_t) ((p_pci_window_settings->destination_address >> PCIE_RC_SHIFT_FOR_UPPER_32BIT_VALUE) &
                        UINT32_MAX);

        /* Set the PCIe Window enable */
        *p_pwbasel |= p_pci_window_settings->window_enable;
    }

    /* Set MSI window */
    pcie_rc_msi_window_settings_t const * p_msi_window_settings = &(p_extend->msi_window_setting);

    /* Make sure that MSI Receive Window Enable is 0 when changing MSI settings.
     * See Section "PCI_RC_MSIRCVWADRL : MSI Receive Window Address (Lower) Register"
     * and Section "PCI_RC_MSIRCVWADRU : MSI Receive Window Address (Upper) Register"
     * in the RZ microprocessor Hardware Manual for more details. */
    p_instance_ctrl->p_reg->PCI_RC_MSIRCVWADRL = 0x00000000;

    p_instance_ctrl->p_reg->PCI_RC_MSIRCVWADRL = p_msi_window_settings->base_address &
                                                 R_PCIE0_PCI_RC_MSIRCVWADRL_MSIRWAL_Msk;
    p_instance_ctrl->p_reg->PCI_RC_MSIRCVWADRU =
        (uint32_t) ((p_msi_window_settings->base_address >> PCIE_RC_SHIFT_FOR_UPPER_32BIT_VALUE) & UINT32_MAX);
    p_instance_ctrl->p_reg->PCI_RC_MSIRCVWMSKL = p_msi_window_settings->mask_address & UINT32_MAX;
    p_instance_ctrl->p_reg->PCI_RC_MSIRCVWMSKU =
        (uint32_t) ((p_msi_window_settings->mask_address >> PCIE_RC_SHIFT_FOR_UPPER_32BIT_VALUE) &
                    R_PCIE0_PCI_RC_MSIRCVWMSKU_MSIRWMU_Msk);

    p_instance_ctrl->p_reg->PCI_RC_MSIRCVWADRL |= p_msi_window_settings->window_enable;
}

/*******************************************************************************************************************//**
 * Configures and enables interrupt if it is a valid vector number.
 *
 * @param[in]  irq                     Interrupt number
 * @param[in]  priority                Priority of the interrupt
 * @param[in]  p_context               The interrupt context is a pointer to data required in the ISR.
 **********************************************************************************************************************/
static void r_pcie_rc_enable_irq (IRQn_Type const irq, uint32_t priority, void * p_context)
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
static void r_pcie_rc_disable_irq (IRQn_Type irq)
{
    /* Disable interrupts. */
    if (irq >= 0)
    {
        R_BSP_IrqDisable(irq);
        R_FSP_IsrContextSet(irq, NULL);
    }
}

/*******************************************************************************************************************//**
 * Configures PCIE_RC interrupt
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 **********************************************************************************************************************/
static void r_pcie_rc_interrupt_setup (pcie_rc_instance_ctrl_t * p_instance_ctrl)
{
    pcie_rc_extended_cfg_t * p_extend = (pcie_rc_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* Interrupt settings. See Section "Initialization Procedure" in the RZ microprocessor Hardware Manual for more details.
     * Initialize PCIe Event Interrupt Status / Enable 0 Register. */
    p_instance_ctrl->p_reg->PCI_RC_PEIS0 = PCIE_RC_PEIS0_REG_SETTING_VALUE;
    p_instance_ctrl->p_reg->PCI_RC_PEIE0 = p_extend->event0_interrupts;

    /* Initialize PCIe Event Interrupt Status / Enable 1 Register. */
    p_instance_ctrl->p_reg->PCI_RC_PEIS1 = PCIE_RC_PEIS1_REG_SETTING_VALUE;
    p_instance_ctrl->p_reg->PCI_RC_PEIE1 = p_extend->event1_interrupts;

    /* Initialize AXI Master Error Interrupt Status / Enable Register. */
    p_instance_ctrl->p_reg->PCI_RC_AMEIS = PCIE_RC_AMEIS_AMEIE_REG_SETTING_VALUE;
    p_instance_ctrl->p_reg->PCI_RC_AMEIE = PCIE_RC_AMEIS_AMEIE_REG_SETTING_VALUE;

    /* Initialize AXI Slave Error Interrupt Status / Enable 1 Register. */
    p_instance_ctrl->p_reg->PCI_RC_ASEIS1 = PCIE_RC_ASEIS1_ASEIE1_REG_SETTING_VALUE;
    p_instance_ctrl->p_reg->PCI_RC_ASEIE1 = PCIE_RC_ASEIS1_ASEIE1_REG_SETTING_VALUE;

    /* Initialize Message Receive Interrupt Status / Enable Register. */
    p_instance_ctrl->p_reg->PCI_RC_MSGRCVIS = PCIE_RC_MSGRCVIS_SETTING_VALUE;
    p_instance_ctrl->p_reg->PCI_RC_MSGRCVIE = PCIE_RC_MSGRCVIE_SETTING_VALUE;

    /* Initialize PCI INTx Receive Interrupt Enable Registers. */
    p_instance_ctrl->p_reg->PCI_RC_PINTRCVIE = R_PCIE0_PCI_RC_PINTRCVIE_INTARIE_Msk |
                                               R_PCIE0_PCI_RC_PINTRCVIE_INTBRIE_Msk |
                                               R_PCIE0_PCI_RC_PINTRCVIE_INTCRIE_Msk |
                                               R_PCIE0_PCI_RC_PINTRCVIE_INTDRIE_Msk |
                                               R_PCIE0_PCI_RC_PINTRCVIE_MSIRIE_Msk;

    /* Configure Interrupt Controller. */
    r_pcie_rc_enable_irq(p_instance_ctrl->p_cfg->inta_irq, p_instance_ctrl->p_cfg->inta_ipl, p_instance_ctrl);
    r_pcie_rc_enable_irq(p_instance_ctrl->p_cfg->intb_irq, p_instance_ctrl->p_cfg->intb_ipl, p_instance_ctrl);
    r_pcie_rc_enable_irq(p_instance_ctrl->p_cfg->intc_irq, p_instance_ctrl->p_cfg->intc_ipl, p_instance_ctrl);
    r_pcie_rc_enable_irq(p_instance_ctrl->p_cfg->intd_irq, p_instance_ctrl->p_cfg->intd_ipl, p_instance_ctrl);
    r_pcie_rc_enable_irq(p_instance_ctrl->p_cfg->msi_irq, p_instance_ctrl->p_cfg->msi_ipl, p_instance_ctrl);
    r_pcie_rc_enable_irq(p_extend->msg_irq, p_extend->msg_ipl, p_instance_ctrl);
    r_pcie_rc_enable_irq(p_extend->link_width_change_irq, p_extend->link_width_change_ipl, p_instance_ctrl);
    r_pcie_rc_enable_irq(p_extend->link_equalization_request_irq,
                         p_extend->link_equalization_request_ipl,
                         p_instance_ctrl);
    r_pcie_rc_enable_irq(p_extend->pcie_event_irq, p_extend->pcie_event_ipl, p_instance_ctrl);

    r_pcie_rc_enable_irq(p_extend->poweroff_indication_l2_irq, p_extend->poweroff_indication_l2_ipl, p_instance_ctrl);
}

/*******************************************************************************************************************//**
 * Initialize PCIE_RC Configuration register.
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 **********************************************************************************************************************/
static void r_pcie_rc_configuration_register_type1_init (pcie_rc_instance_ctrl_t * p_instance_ctrl)
{
    pcie_rc_configuration_register_1_t const * p_cfg_register =
        p_instance_ctrl->p_cfg->p_configuration_register_header;

    /* PCI_RC_VID (Vendor and Device ID Register)*/
    r_pcie_rc_self_configuration_register_write(p_instance_ctrl, 0, p_cfg_register->vender_device_id);

    /* PCI_RC_COMS_STA (Command and Status Register) */
    r_pcie_rc_self_configuration_register_write(p_instance_ctrl, 1, p_cfg_register->command_status);

    /* PCI_RC_RID_CC (Revision ID and Class Code Register) */
    r_pcie_rc_self_configuration_register_write(p_instance_ctrl, 2, p_cfg_register->revision_id_class_code);

    /* PCI_RC_CL_HT (Cache Line and Header Type Register */
    r_pcie_rc_self_configuration_register_write(p_instance_ctrl, 3, p_cfg_register->cahce_line_header_type);

    /* PCI_RC_BNR (Bus Number Register) */
    r_pcie_rc_self_configuration_register_write(p_instance_ctrl, 6, p_cfg_register->bus_number);

    /* PCI_RC_IOBL_SS (I/O Base/Limit and Secondary Status) */
    r_pcie_rc_self_configuration_register_write(p_instance_ctrl, 7,
                                                p_cfg_register->io_limit_base_limit_secondary_status);

    /* PCI_RC_MEMBL (Memory Base/Limit Register) */
    r_pcie_rc_self_configuration_register_write(p_instance_ctrl, 8, p_cfg_register->memory_base_limit);

    /* PCI_RC_PMBL (Prefetchable Memory Base/Limit Register) */
    r_pcie_rc_self_configuration_register_write(p_instance_ctrl, 9, p_cfg_register->prefetchable_memory_base_limit);

    /* PCI_RC_PBUP32 (Prefetchable Base Upper 32 Bits Register) */
    r_pcie_rc_self_configuration_register_write(p_instance_ctrl, 10, p_cfg_register->prefetchable_base_upper_32);

    /* PCI_RC_PLUP32 (Prefetchable Base Limit 32 Bits Register) */
    r_pcie_rc_self_configuration_register_write(p_instance_ctrl, 11, p_cfg_register->prefetchable_limit_upper_32);

    /* PCI_RC_IOBLUP16 (I/O Base/Limit Upper 16bits Register) */
    r_pcie_rc_self_configuration_register_write(p_instance_ctrl, 12, p_cfg_register->io_base_limit_upper_16);

    /* PCI_RC_CP (Capabilities Pointer Register) */
    r_pcie_rc_self_configuration_register_write(p_instance_ctrl, 13, p_cfg_register->capability_pointer);

    /* PCI_RC_BC_INIT (Bridge Control and Interrupt) */
    r_pcie_rc_self_configuration_register_write(p_instance_ctrl, 15, p_cfg_register->bridge_control_interrupt);

    pci_configuration_register_init_t const * p_configuration_register_init =
        p_instance_ctrl->p_cfg->p_configuration_register_init_list;
    uint32_t size = p_instance_ctrl->p_cfg->configuration_register_init_list_length;

    for (uint32_t i = 0; i < size; i++)
    {
        uint32_t register_number = p_configuration_register_init[i].register_number;
        uint32_t init_value      = p_configuration_register_init[i].init_value;
        uint32_t init_value_mask = p_configuration_register_init[i].init_value_mask;

        uint32_t register_value;
        r_pcie_rc_self_configuration_register_read(p_instance_ctrl, register_number, &register_value);

        register_value &= ~init_value_mask;
        register_value |= (init_value & init_value_mask);

        r_pcie_rc_self_configuration_register_write(p_instance_ctrl, register_number, register_value);
    }

    /* PCI_RC_BAR0 (Base Address Register 0)
     *
     * Depending on the size of the address block required, some lower bits of this field are implemented as Read Only bits.
     * For this reason, set the BAR register last so that the address block size is set first.
     *
     * See Section "PCI_RC_BAR0 : Base Address Register 0" in the RZ microprocessor Hardware Manual for more details. */
    r_pcie_rc_self_configuration_register_write(p_instance_ctrl, 4, p_cfg_register->base_address_register_0);

    /* PCI_RC_BAR1 (Base Address Register 1) */
    r_pcie_rc_self_configuration_register_write(p_instance_ctrl, 5, p_cfg_register->base_address_register_1);
}

/*******************************************************************************************************************//**
 * Set value to PCIE_RC Configuration register.
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 * @param[in]  register_number         Register number to be set.
 * @param[in]  register_value          Setting value.
 **********************************************************************************************************************/
static void r_pcie_rc_self_configuration_register_write (pcie_rc_instance_ctrl_t * p_instance_ctrl,
                                                         uint32_t                  register_number,
                                                         uint32_t                  register_value)
{
    uint32_t * p_configuration_register_base = (uint32_t *) &p_instance_ctrl->p_reg->PCI_RC_VID;
    *(p_configuration_register_base + register_number) = register_value;
}

/*******************************************************************************************************************//**
 * Read value to PCIE_RC Configuration register.
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 * @param[in]  register_number         Register number to be read.
 * @param[out]  p_register_value       Store location of read value.
 **********************************************************************************************************************/
static void r_pcie_rc_self_configuration_register_read (pcie_rc_instance_ctrl_t * p_instance_ctrl,
                                                        uint32_t                  register_number,
                                                        uint32_t                * p_register_value)
{
    uint32_t * p_configuration_register_base = (uint32_t *) &p_instance_ctrl->p_reg->PCI_RC_VID;
    *p_register_value = *(p_configuration_register_base + register_number);
}

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_ctrl     Pointer to PCIE_RC instance control block
 * @param[in]     p_args     Pointer to arguments on stack
 **********************************************************************************************************************/
static void r_pcie_rc_call_callback (pcie_rc_instance_ctrl_t * p_ctrl, pci_callback_args_t * p_args)
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
 * Common processing for INTx interrupt.
 *
 * @param[in]  event  Which INTx event occurred
 **********************************************************************************************************************/
static void r_pcie_common_intx_handler (pci_event_t event)
{
    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Set static arguments */
    pci_callback_args_t args;
    args.event     = event;
    args.p_context = p_instance_ctrl->p_context;

    /* data1 - data3 not used at PCI_EVENT_MESSAGE_RECEIVE event. */
    args.data1 = 0U;
    args.data2 = 0U;
    args.data3 = 0U;

    if (NULL != p_instance_ctrl->p_callback)
    {
        r_pcie_rc_call_callback(p_instance_ctrl, &args);
    }

    /* The PCI_RC_PINTRCVIS register indicates the INTx interrupt factor.
     * When Assert_INTx is received, corresponding bit in the PCI_RC_PINTRCVIS is set.
     * When Deassert_INTx is received, corresponding bit in the PCI_RC_PINTRCVIS is cleared.
     *
     * Because of the above, software don't clear the PCI_RC_PINTRCVIS register.
     *
     * See Section "PCI_RC_PINTRCVIS : PCI INTx Receive Interrupt Status Register"
     * in the RZ microprocessor Hardware Manual for more details.
     */
}

/*******************************************************************************************************************//**
 * PCI message receive interrupt processing. When a message receive interrupt fires, the user callback function is called
 * if it is registered in R_PCIE_RC_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void pcie_rc_message_receive_handler (void)
{
    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    uint32_t status = p_instance_ctrl->p_reg->PCI_RC_MSGRCVIS;

    pci_callback_args_t args;
    args.event     = PCI_EVENT_MESSAGE_RECEIVE;
    args.p_context = p_instance_ctrl->p_context;

    /* data1 - data3 not used at PCI_EVENT_INTx_INTERRUPT event. */
    args.data1 = 0U;
    args.data2 = 0U;
    args.data3 = 0U;

    if (NULL != p_instance_ctrl->p_callback)
    {
        r_pcie_rc_call_callback(p_instance_ctrl, &args);
    }

    p_instance_ctrl->p_reg->PCI_RC_MSGRCVIS = status;

    FSP_REGISTER_READ(p_instance_ctrl->p_reg->PCI_RC_MSGRCVIS);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * POWEROFF on L2 interrupt processing. When an POWEROFF on L2 interrupt fires, the user callback function is called
 * if it is registered in R_PCIE_RC_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void pcie_rc_power_off_indication_handler (void)
{
    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

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
        r_pcie_rc_call_callback(p_instance_ctrl, &args);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * INTA interrupt processing. When an INTA interrupt fires, the user callback function is called if it is
 * registered in R_PCIE_RC_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void pcie_rc_inta_handler (void)
{
    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    r_pcie_common_intx_handler(PCI_EVENT_INTA_INTERRUPT);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * INTB interrupt processing. When an INTB interrupt fires, the user callback function is called if it is
 * registered in R_PCIE_RC_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void pcie_rc_intb_handler (void)
{
    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    r_pcie_common_intx_handler(PCI_EVENT_INTB_INTERRUPT);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * INTC interrupt processing. When an INTC interrupt fires, the user callback function is called if it is
 * registered in R_PCIE_RC_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void pcie_rc_intc_handler (void)
{
    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    r_pcie_common_intx_handler(PCI_EVENT_INTC_INTERRUPT);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * INTD interrupt processing. When an INTD interrupt fires, the user callback function is called if it is
 * registered in R_PCIE_RC_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void pcie_rc_intd_handler (void)
{
    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    r_pcie_common_intx_handler(PCI_EVENT_INTD_INTERRUPT);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * MSI interrupt processing. When an MSI interrupt fires, the user callback function is called if it is
 * registered in R_PCIE_RC_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void pcie_rc_msi_handler (void)
{
    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Set static arguments */
    pci_callback_args_t args;
    args.event     = PCI_EVENT_MSI_INTERRUPT;
    args.p_context = p_instance_ctrl->p_context;

    /* data1 - data3 not used at PCI_EVENT_MSI_INTERRUPT event. */
    args.data1 = 0U;
    args.data2 = 0U;
    args.data3 = 0U;

    if (NULL != p_instance_ctrl->p_callback)
    {
        r_pcie_rc_call_callback(p_instance_ctrl, &args);
    }

    /* Clear MSI Receive Interrupt Status */
    p_instance_ctrl->p_reg->PCI_RC_PINTRCVIS |= R_PCIE0_PCI_RC_PINTRCVIS_MSIRIS_Msk;

    /* Dummy read to ensure that interrupt event is cleared. */
    FSP_REGISTER_READ(p_instance_ctrl->p_reg->PCI_RC_PINTRCVIS);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * PCIE Link equalization request interrupt processing. When an PCIE Link equalization request interrupt fires,
 * the user callback function is called if it is registered in R_PCIE_RC_Open() with the event code that
 * triggered the interrupt.
 **********************************************************************************************************************/
void pcie_rc_link_equalization_request_handler (void)
{
    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Set static arguments */
    pci_callback_args_t args;
    args.event     = PCI_EVENT_LINK_EQUALIZATION_REQUEST;
    args.p_context = p_instance_ctrl->p_context;

    /* data1 - data3 not used at PCI_EVENT_LINK_EQUALIZATION_REQUEST event. */
    args.data1 = 0U;
    args.data2 = 0U;
    args.data3 = 0U;

    if (NULL != p_instance_ctrl->p_callback)
    {
        /* User must clear the Link Equalization Request bit (bit 21) in the Link Control 2 / Status 2 Register
         * (Configuration register offset 0x90) in the user callback function. */
        r_pcie_rc_call_callback(p_instance_ctrl, &args);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * PCIE Event interrupt processing. When an PCIE Event interrupt fires, the user callback function is called if it is
 * registered in R_PCIE_RC_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void pcie_rc_event_handler (void)
{
    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Set static arguments */
    pci_callback_args_t args;
    args.event     = PCI_EVENT_EVENT;
    args.p_context = p_instance_ctrl->p_context;
    args.data1     = p_instance_ctrl->p_reg->PCI_RC_PEIS0;
    args.data2     = p_instance_ctrl->p_reg->PCI_RC_PEIS1;

    if (NULL != p_instance_ctrl->p_callback)
    {
        r_pcie_rc_call_callback(p_instance_ctrl, &args);
    }

    p_instance_ctrl->p_reg->PCI_RC_PEIS0 = args.data1;
    p_instance_ctrl->p_reg->PCI_RC_PEIS1 = args.data2;

    /* Dummy read to ensure that interrupt event is cleared. */
    FSP_REGISTER_READ(p_instance_ctrl->p_reg->PCI_RC_PEIS0);
    FSP_REGISTER_READ(p_instance_ctrl->p_reg->PCI_RC_PEIS1);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * PCIE Link Width Change interrupt processing. When an PCIE Event interrupt fires, the user callback function is called
 * if it is registered in R_PCIE_RC_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void pcie_rc_link_width_change_handler (void)
{
    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    pcie_rc_instance_ctrl_t * p_instance_ctrl = (pcie_rc_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Set static arguments */
    pci_callback_args_t args;
    args.event     = PCI_EVENT_LINK_WIDTH_CHANGE;
    args.p_context = p_instance_ctrl->p_context;

    /* data1 - data3 not used at PCI_EVENT_LINK_WIDTH_CHANGE event. */
    args.data1 = 0U;
    args.data2 = 0U;
    args.data3 = 0U;

    if (NULL != p_instance_ctrl->p_callback)
    {
        /* User must clear the Link Bandwidth Management Status bit (bit 30) and the Link Autonomous Status bit (bit 31)
         * in the Link Control/Status Register (Configuration register offset 0x70) in the user callback function. */
        r_pcie_rc_call_callback(p_instance_ctrl, &args);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    PCIE_RC_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * PCIE Correctable error detect interrupt processing. When an PCIE Event interrupt fires,
 * the user callback function is called if it is registered in R_PCIE_RC_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void pcie_rc_correctable_error_handler (uint32_t id)
{
    uint32_t channel = 0;
    if (BSP_FEATURE_PCIE_CHANNEL0_ERROR_CORRECTABLE_RC_NUM == id)
    {
        channel = 0;
    }
    else if (BSP_FEATURE_PCIE_CHANNEL1_ERROR_CORRECTABLE_RC_NUM == id)
    {
        channel = 1;
    }
    else
    {
        /* Do nothing. */
    }

    pcie_rc_instance_ctrl_t * p_instance_ctrl = gp_instance_ctrl[channel];

    /* Set static arguments */
    pci_callback_args_t args;
    args.event     = PCI_EVENT_CORRECTABLE_ERROR;
    args.p_context = p_instance_ctrl->p_context;

    /* data1 - data3 not used at PCI_EVENT_CORRECTABLE_ERROR event. */
    args.data1 = 0U;
    args.data2 = 0U;
    args.data3 = 0U;

    if (NULL != p_instance_ctrl)
    {
        if (NULL != p_instance_ctrl->p_callback)
        {
            r_pcie_rc_call_callback(p_instance_ctrl, &args);
        }
    }
}

/*******************************************************************************************************************//**
 * PCIE Non fatal error detect interrupt processing. When an PCIE Event interrupt fires,
 * the user callback function is called if it is registered in R_PCIE_RC_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void pcie_rc_non_fatal_error_handler (uint32_t id)
{
    uint32_t channel = 0;
    if (BSP_FEATURE_PCIE_CHANNEL0_ERROR_NON_FATAL_RC_NUM == id)
    {
        channel = 0;
    }
    else if (BSP_FEATURE_PCIE_CHANNEL1_ERROR_NON_FATAL_RC_NUM == id)
    {
        channel = 1;
    }
    else
    {
        /* Do nothing. */
    }

    pcie_rc_instance_ctrl_t * p_instance_ctrl = gp_instance_ctrl[channel];

    /* Set static arguments */
    pci_callback_args_t args;
    args.event     = PCI_EVENT_UNCORRECTABLE_ERROR_NON_FATAL;
    args.p_context = p_instance_ctrl->p_context;

    /* data1 - data3 not used at PCI_EVENT_UNCORRECTABLE_ERROR_NON_FATAL event. */
    args.data1 = 0U;
    args.data2 = 0U;
    args.data3 = 0U;

    if (NULL != p_instance_ctrl)
    {
        if (NULL != p_instance_ctrl->p_callback)
        {
            r_pcie_rc_call_callback(p_instance_ctrl, &args);
        }
    }
}

/*******************************************************************************************************************//**
 * PCIE fatal error detect interrupt processing. When an PCIE Event interrupt fires,
 * the user callback function is called if it is registered in R_PCIE_RC_Open() with the event code that triggered the interrupt.
 **********************************************************************************************************************/
void pcie_rc_fatal_error_handler (uint32_t id)
{
    uint32_t channel = 0;
    if (BSP_FEATURE_PCIE_CHANNEL0_ERROR_FATAL_RC_NUM == id)
    {
        channel = 0;
    }
    else if (BSP_FEATURE_PCIE_CHANNEL1_ERROR_FATAL_RC_NUM == id)
    {
        channel = 1;
    }
    else
    {
        /* Do nothing. */
    }

    pcie_rc_instance_ctrl_t * p_instance_ctrl = gp_instance_ctrl[channel];

    /* Set static arguments */
    pci_callback_args_t args;
    args.event     = PCI_EVENT_UNCORRECTABLE_ERROR_FATAL;
    args.p_context = p_instance_ctrl->p_context;

    /* data1 - data3 not used at PCI_EVENT_UNCORRECTABLE_ERROR_FATAL event. */
    args.data1 = 0U;
    args.data2 = 0U;
    args.data3 = 0U;

    if (NULL != p_instance_ctrl)
    {
        if (NULL != p_instance_ctrl->p_callback)
        {
            r_pcie_rc_call_callback(p_instance_ctrl, &args);
        }
    }
}
