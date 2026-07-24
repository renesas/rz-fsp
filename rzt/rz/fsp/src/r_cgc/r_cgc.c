/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_cgc.h"
#include "r_cgc_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "CGC" in ASCII, used to determine if the module is open. */
#define CGC_OPEN                                       (0x00434743U)

#if 2U == BSP_FEATURE_CGC_SCKCR_TYPE
 #define CGC_PRV_SCKCR3_SPIASYNCSEL_VALUE_MASK         (0x03U)
 #define CGC_PRV_SCKCR3_SCIASYNCSEL_VALUE_MASK         (0x03U)
 #define CGC_PRV_SCKCR3_LCDCDIVSEL_VALUE_MASK          (0x0fU)
 #define CGC_PRV_SCKCR4_SCIEASYNCSEL_VALUE_MASK        (0x03U)
 #define CGC_PRV_SCKCR4_ENCOUTCLK_VALUE_MASK           (0x01U)
#elif 3U == BSP_FEATURE_CGC_SCKCR_TYPE
 #define CGC_PRV_SCKCR3_SPIASYNCSEL_VALUE_MASK         (0x03U)
 #define CGC_PRV_SCKCR3_SCIASYNCSEL_VALUE_MASK         (0x03U)
 #define CGC_PRV_SCKCR3_ETHREFCLKSEL_VALUE_MASK        (0x01U)
 #define CGC_PRV_SCKCR4_SCIEASYNCSEL_VALUE_MASK        (0x03U)
 #define CGC_PRV_SCKCR4_ENCOUTCLK_VALUE_MASK           (0x01U)
 #define CGC_PRV_SCKCR4_DDRCLKSEL_VALUE_MASK           (0x01U)
 #define CGC_PRV_SCKCR4_DDRDIVSEL_VALUE_MASK           (0x07U)
 #define CGC_PRV_SCKCR5_NANDCCLKSEL_VALUE_MASK         (0x0fU)
 #define CGC_PRV_SCKCR5_SDHICLKSEL_VALUE_MASK          (0x01U)
#endif

#if BSP_FEATURE_CGC_PLL0_SSC_SUPPORTED || BSP_FEATURE_CGC_PLL2_SSC_SUPPORTED
 #define CGC_PRV_MFR_MIN                               (0x0)
 #define CGC_PRV_MRR_MIN                               (0x1)
 #define CGC_PRV_MFR_MMR_MIN                           (0x0)
 #define CGC_PRV_MODULATION_FREQUENCY_MIN_HZ           (30000)
 #define CGC_PRV_MODULATION_RATE_MIN_PERCENTAGE        (0)

 #define CGC_PRV_MFR_MAX                               (0xFF)
 #define CGC_PRV_MRR_MAX                               (0x3F)
 #define CGC_PRV_MFR_MMR_MAX                           (0x200)
 #define CGC_PRV_MODULATION_FREQUENCY_MAX_HZ           (150000)
 #define CGC_PRV_MODULATION_RATE_MAX_PERCENTAGE        (5)

 #define CGC_PRV_MAIN_CLOCK_OSC_FREQUENCY_HZ           (25000000)
 #define CGC_PRV_SSC_MODULATION_FREQUENCY_DIV_VALUE    (32)
 #define CGC_PRV_SSC_MODULATION_RATE_DIV_VALUE         (64)
 #define CGC_PRV_PERCENTAGE_TRANSLATION                (100)
#endif

#if BSP_FEATURE_CGC_PLL3_VCO_SETTING_SUPPORTED
 #define CGC_PRV_P_DIVIDER_MIN                         (0x1)
 #define CGC_PRV_M_DIVIDER_MIN                         (0x040)
 #define CGC_PRV_S_DIVIDER_MIN                         (0x0)
 #define CGC_PRV_K_DIVIDER_MIN                         (0x0000)
 #define CGC_PRV_REFERENCE_FREQUENCY_MIN_MHZ           (6)
 #define CGC_PRV_VCO_FREQUENCY_MIN_MHZ                 (1600)
 #define CGC_PRV_PLL_OUTPUT_FREQUENCY_MIN_MHZ          (25)

 #define CGC_PRV_P_DIVIDER_MAX                         (0x3F)
 #define CGC_PRV_M_DIVIDER_MAX                         (0x3FF)
 #define CGC_PRV_S_DIVIDER_MAX                         (0x6)
 #define CGC_PRV_K_DIVIDER_MAX                         (0x7FFF)
 #define CGC_PRV_REFERENCE_FREQUENCY_MAX_MHZ           (25)
 #define CGC_PRV_VCO_FREQUENCY_MAX_MHZ                 (3200)
 #define CGC_PRV_PLL_OUTPUT_FREQUENCY_MAX_MHZ          (430)

 #define CGC_PRV_PLL3_INPUT_FREQUENCY_MHZ              (48)
 #define CGC_PRV_K_DIVIDER_DIV_VALUE                   (65536)
#endif

#if 2 == BSP_FEATURE_CGC_PLL_START_PROCESS_TYPE
 #define CGC_PRV_PMSEL_REGISTER_ADDRESS                (0x81280010)
 #define CGC_PRV_PMSEL_PMSEL0MON_SHIFT                 (9)
 #define CGC_PRV_PMSEL_PMSEL1MON_SHIFT                 (10)
 #define CGC_PRV_PMSEL_PMSEL2MON_SHIFT                 (11)
 #define CGC_PRV_PMSEL_PMSEL3MON_SHIFT                 (12)
 #define CGC_PRV_PMSEL_PMSEL4MON_SHIFT                 (13)
 #define CGC_PRV_PMSEL_PMSELMON_MASK                   (0x01)
#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/* Private enumeration used to tell if a clock is running or not. */
typedef enum e_cgc_prv_clock_state
{
    CGC_PRV_CLOCK_STATE_STOPPED = 0,
    CGC_PRV_CLOCK_STATE_RUNNING = 1,
} cgc_prv_clock_state_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static fsp_err_t r_cgc_clock_check(cgc_clock_t const clock_source);
static bool      r_cgc_stabilization_check(cgc_clock_t clock, cgc_prv_clock_state_t status);

#if 2 == BSP_FEATURE_CGC_PLL_START_PROCESS_TYPE
static bool r_cgc_pll_domain_clock_source_check(cgc_clock_t clock);

#endif
static void r_cgc_clock_change(cgc_clock_t clock, cgc_clock_change_t state);

#if BSP_FEATURE_CGC_PLL0_SSC_SUPPORTED || BSP_FEATURE_CGC_PLL2_SSC_SUPPORTED
static void r_cgc_pll_ssc_cfg(cgc_clock_t clock, cgc_pll_ssc_cfg_t const * p_pll_ssc_cfg);

#endif
#if BSP_FEATURE_CGC_PLL3_VCO_SETTING_SUPPORTED
static void r_cgc_pll_vco_cfg(cgc_clock_t clock, cgc_pll_vco_cfg_t const * pll_vco_cfg);

#endif
static cgc_prv_clock_state_t r_cgc_clock_run_state_get(cgc_clock_t clock);

#if CGC_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t r_cgc_common_parameter_checking(cgc_instance_ctrl_t * p_instance_ctrl);

 #if BSP_FEATURE_CGC_PLL0_SSC_SUPPORTED || BSP_FEATURE_CGC_PLL2_SSC_SUPPORTED
static fsp_err_t r_cgc_pll_ssc_parameter_checking(cgc_pll_ssc_cfg_t const * p_pll_ssc_setting, cgc_clock_t clock);

 #endif
 #if BSP_FEATURE_CGC_PLL3_VCO_SETTING_SUPPORTED
static fsp_err_t r_cgc_pll3_vco_parameter_checking(cgc_pll_vco_cfg_t const * p_pll_vco_setting);

 #endif
#endif

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

static uint32_t volatile * const gp_cgc_clock_stp_registers[BSP_FEATURE_CGC_CLOCK_SOURCE_NUM] =
{
    [CGC_CLOCK_LOCO] = (uint32_t *) BSP_FEATURE_CGC_LOCO_CONTROL_ADDRESS,
    [CGC_CLOCK_PLL0] = (uint32_t *) BSP_FEATURE_CGC_PLL0_CONTROL_ADDRESS,
    [CGC_CLOCK_PLL1] = (uint32_t *) BSP_FEATURE_CGC_PLL1_CONTROL_ADDRESS,
#if 3U < BSP_FEATURE_CGC_CLOCK_SOURCE_NUM
    [CGC_CLOCK_PLL2] = (uint32_t *) BSP_FEATURE_CGC_PLL2_CONTROL_ADDRESS,
    [CGC_CLOCK_PLL3] = (uint32_t *) BSP_FEATURE_CGC_PLL3_CONTROL_ADDRESS,
    [CGC_CLOCK_PLL4] = NULL,           // PLL4 is always running
#endif
};

/* How long of a software delay is required after starting each clock before activating it as the system clock. */
static const uint32_t g_cgc_software_wait_us[BSP_FEATURE_CGC_CLOCK_SOURCE_NUM] =
{
    [CGC_CLOCK_LOCO] = BSP_FEATURE_CGC_LOCO_STABILIZATION_MAX_US,
    [CGC_CLOCK_PLL0] = 0U,             // PLL0 has a stabilization wait flag
    [CGC_CLOCK_PLL1] = 0U,             // PLL1 has a stabilization wait flag
#if 3U < BSP_FEATURE_CGC_CLOCK_SOURCE_NUM
    [CGC_CLOCK_PLL2] = 0U,             // PLL2 has a stabilization wait flag
    [CGC_CLOCK_PLL3] = 0U,             // PLL3 has a stabilization wait flag
    [CGC_CLOCK_PLL4] = 0U,             // PLL4 has a stabilization wait flag
#endif
};

static const bsp_reg_protect_t g_cgc_register_protect_settings[BSP_FEATURE_CGC_CLOCK_SOURCE_NUM] =
{
    [CGC_CLOCK_LOCO] = BSP_REG_PROTECT_CGC,
    [CGC_CLOCK_PLL0] = (bsp_reg_protect_t) BSP_FEATURE_CGC_PLL0_PROTECT,
    [CGC_CLOCK_PLL1] = (bsp_reg_protect_t) BSP_FEATURE_CGC_PLL1_PROTECT,
#if 3U < BSP_FEATURE_CGC_CLOCK_SOURCE_NUM
    [CGC_CLOCK_PLL2] = (bsp_reg_protect_t) BSP_FEATURE_CGC_PLL2_PROTECT,
    [CGC_CLOCK_PLL3] = (bsp_reg_protect_t) BSP_FEATURE_CGC_PLL3_PROTECT,
    [CGC_CLOCK_PLL4] = (bsp_reg_protect_t) NULL, // PLL4 is always running
#endif
};

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

const cgc_api_t g_cgc_on_cgc =
{
    .open                 = R_CGC_Open,
    .clocksCfg            = R_CGC_ClocksCfg,
    .clockStart           = R_CGC_ClockStart,
    .clockStop            = R_CGC_ClockStop,
    .clockCheck           = R_CGC_ClockCheck,
    .systemClockSet       = R_CGC_SystemClockSet,
    .systemClockGet       = R_CGC_SystemClockGet,
    .oscStopDetectEnable  = R_CGC_OscStopDetectEnable,
    .oscStopDetectDisable = R_CGC_OscStopDetectDisable,
    .oscStopStatusClear   = R_CGC_OscStopStatusClear,
    .callbackSet          = R_CGC_CallbackSet,
    .close                = R_CGC_Close,
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZT
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_CGC
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initialize the CGC API.  Implements @ref cgc_api_t::open.
 *
 * @retval FSP_SUCCESS              CGC successfully initialized.
 * @retval FSP_ERR_ASSERTION        Invalid input argument.
 * @retval FSP_ERR_ALREADY_OPEN     Module is already open.
 **********************************************************************************************************************/
fsp_err_t R_CGC_Open (cgc_ctrl_t * const p_ctrl, cgc_cfg_t const * const p_cfg)
{
    cgc_instance_ctrl_t * p_instance_ctrl = (cgc_instance_ctrl_t *) p_ctrl;

#if CGC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ERROR_RETURN(CGC_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    FSP_PARAMETER_NOT_USED(p_cfg);

    /* Mark the module as open so other APIs can be used. */
    p_instance_ctrl->open = CGC_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reconfigures all main system clocks.  This API can be used for any of the following purposes:
 *   - start or stop clocks
 *
 * If the requested system clock source has a stabilization flag, this function blocks waiting for the stabilization
 * flag of the requested system clock source to be set.  If the requested system clock source was just started and it
 * has no stabilization flag, this function blocks for the stabilization time required by the requested system clock
 * source according to the Electrical Characteristics section of the hardware manual.  If the requested system clock
 * source has no stabilization flag and it is already running, it is assumed to be stable and this function will not
 * block.
 *
 * Do not attempt to stop the requested clock source or the source of the PLL if the PLL will be running after this
 * operation completes.
 *
 * Implements @ref cgc_api_t::clocksCfg.
 *
 * @retval FSP_SUCCESS                  Clock configuration applied successfully.
 * @retval FSP_ERR_ASSERTION            Invalid input argument.
 * @retval FSP_ERR_NOT_OPEN             Module is not open.
 * @retval FSP_ERR_NOT_STABILIZED       Clock not stabilized.
 * @retval FSP_ERR_INVALID_ARGUMENT     Clock configuration setting is invalid.
 **********************************************************************************************************************/
fsp_err_t R_CGC_ClocksCfg (cgc_ctrl_t * const p_ctrl, cgc_clocks_cfg_t const * const p_clock_cfg)
{
    cgc_instance_ctrl_t * p_instance_ctrl = (cgc_instance_ctrl_t *) p_ctrl;

    fsp_err_t err = FSP_SUCCESS;
#if CGC_CFG_PARAM_CHECKING_ENABLE
    err = r_cgc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    FSP_ASSERT(NULL != p_clock_cfg);

 #if 1U == BSP_FEATURE_CGC_SCKCR_TYPE

    /* ATCM wait should be 1-wait when CPU0CLK is over 400MHz */
    FSP_ERROR_RETURN(!((0 == R_TCMAW->CPU0WAIT_b.CPU0WAIT) &&
                       (CGC_CPU_CLOCK_DIV_1 == p_clock_cfg->divider_cfg.sckcr2_b.fsel0cr52)),
                     FSP_ERR_INVALID_ARGUMENT);
 #elif 2U == BSP_FEATURE_CGC_SCKCR_TYPE

    /* ATCM wait should be 1-wait when CR52C0CLK is over 500MHz */
    FSP_ERROR_RETURN(!((0 == R_TCMAW->CPU0WAIT_b.CPU0WAIT) &&
                       (CGC_CPU_CLOCK_DIV_1 == p_clock_cfg->divider_cfg.sckcr2_b.cr52cpu0)),
                     FSP_ERR_INVALID_ARGUMENT);

    /* ATCM wait should be 1-wait when CR52C1CLK is over 500MHz */
    FSP_ERROR_RETURN(!((0 == R_TCMAW->CPU1WAIT_b.CPU1WAIT) &&
                       (CGC_CPU_CLOCK_DIV_1 == p_clock_cfg->divider_cfg.sckcr2_b.cr52cpu1)),
                     FSP_ERR_INVALID_ARGUMENT);
 #elif 3U == BSP_FEATURE_CGC_SCKCR_TYPE

    /* ATCM wait should be 1-wait when CR52C0CLK is over 400MHz */
    FSP_ERROR_RETURN(!((0 == R_TCMAW->CPU0WAIT_b.CPU0WAIT) &&
                       (CGC_CPU_CLOCK_DIV_2 == p_clock_cfg->divider_cfg.sckcr2_b.cr52cpu0)),
                     FSP_ERR_INVALID_ARGUMENT);

    /* ATCM wait should be 1-wait when CR52C1CLK is over 400MHz */
    FSP_ERROR_RETURN(!((0 == R_TCMAW->CPU1WAIT_b.CPU1WAIT) &&
                       (CGC_CPU_CLOCK_DIV_2 == p_clock_cfg->divider_cfg.sckcr2_b.cr52cpu1)),
                     FSP_ERR_INVALID_ARGUMENT);
 #endif
 #if BSP_FEATURE_CGC_PLL1_STANDBY_STATE_SUPPORTED

    /* Make sure the oscillator is stable. */
    FSP_ERROR_RETURN(!((0 == R_SYSC_S->PLL1MON_b.PLL1MON) &&
                       (CGC_PHY_CLOCK_PLL1 == p_clock_cfg->divider_cfg.sckcr_b.phy_sel)),
                     FSP_ERR_NOT_STABILIZED);

    /* Do not stop the clock used by other functions. */
    FSP_ERROR_RETURN(!((CGC_CLOCK_CHANGE_STOP == p_clock_cfg->pll1_state) &&
                       (CGC_PHY_CLOCK_PLL1 == p_clock_cfg->divider_cfg.sckcr_b.phy_sel)),
                     FSP_ERR_INVALID_ARGUMENT);

    /* Do not select a stopped clock as the clock source. */
    if (0 == R_SYSC_S->PLL1EN_b.PLL1EN)
    {
        FSP_ERROR_RETURN(!((CGC_CLOCK_CHANGE_NONE == p_clock_cfg->pll1_state) &&
                           (CGC_PHY_CLOCK_PLL1 == p_clock_cfg->divider_cfg.sckcr_b.phy_sel)),
                         FSP_ERR_INVALID_ARGUMENT);
    }
 #endif
 #if BSP_FEATURE_CGC_PLL0_SSC_SUPPORTED

    /* Set values should be within constraints. See RZ microprocessor Hardware Manual section "PLL0 and PLL2 SSC setting and constraints" */

    err = r_cgc_pll_ssc_parameter_checking(&(p_clock_cfg->pll0_ssc_cfg), CGC_CLOCK_PLL0);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
 #endif
 #if BSP_FEATURE_CGC_PLL2_SSC_SUPPORTED

    /* Set values should be within constraints. See RZ microprocessor Hardware Manual section "PLL0 and PLL2 SSC setting and constraints" */

    err = r_cgc_pll_ssc_parameter_checking(&(p_clock_cfg->pll2_ssc_cfg), CGC_CLOCK_PLL2);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
 #endif
 #if BSP_FEATURE_CGC_PLL3_VCO_SETTING_SUPPORTED

    /* Set values should be within constraints. See RZ microprocessor Hardware Manual section "PLL3 setting and constraints" */

    err = r_cgc_pll3_vco_parameter_checking(&(p_clock_cfg->pll3_vco_cfg));
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
 #endif
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
    FSP_PARAMETER_NOT_USED(err);       // unused in some build configurations
#endif

    cgc_divider_cfg_t clock_cfg;
    clock_cfg.sckcr_w  = p_clock_cfg->divider_cfg.sckcr_w;
    clock_cfg.sckcr2_w = p_clock_cfg->divider_cfg.sckcr2_w;
#if 2U == BSP_FEATURE_CGC_SCKCR_TYPE
    clock_cfg.sckcr3_w = p_clock_cfg->divider_cfg.sckcr3_w;
    clock_cfg.sckcr4_w = p_clock_cfg->divider_cfg.sckcr4_w;
    uint32_t sckcr5 = 0;               // dummy
#elif 3U == BSP_FEATURE_CGC_SCKCR_TYPE
    clock_cfg.sckcr3_w = p_clock_cfg->divider_cfg.sckcr3_w;
    clock_cfg.sckcr4_w = p_clock_cfg->divider_cfg.sckcr4_w;
    clock_cfg.sckcr5_w = p_clock_cfg->divider_cfg.sckcr5_w;
#else
    uint32_t sckcr3 = 0;               // dummy
    uint32_t sckcr4 = 0;               // dummy
    uint32_t sckcr5 = 0;               // dummy
#endif

    cgc_clock_change_t options[BSP_FEATURE_CGC_CLOCK_SOURCE_NUM];
    options[CGC_CLOCK_LOCO] = p_clock_cfg->loco_state;

    options[CGC_CLOCK_PLL0] =
#if BSP_FEATURE_CGC_PLL0_STANDBY_STATE_SUPPORTED & !defined(BSP_CFG_CORE_CA55)
        p_clock_cfg->pll0_state;
#else
        CGC_CLOCK_CHANGE_NONE;
#endif
    options[CGC_CLOCK_PLL1] =
#if BSP_FEATURE_CGC_PLL1_STANDBY_STATE_SUPPORTED
        p_clock_cfg->pll1_state;
#else
        CGC_CLOCK_CHANGE_NONE;
#endif
#if 3U < BSP_FEATURE_CGC_CLOCK_SOURCE_NUM
    options[CGC_CLOCK_PLL2] =
 #if BSP_FEATURE_CGC_PLL2_STANDBY_STATE_SUPPORTED
        p_clock_cfg->pll2_state;
 #else
        CGC_CLOCK_CHANGE_NONE;
 #endif
    options[CGC_CLOCK_PLL3] =
 #if BSP_FEATURE_CGC_PLL3_STANDBY_STATE_SUPPORTED
        p_clock_cfg->pll3_state;
 #else
        CGC_CLOCK_CHANGE_NONE;
 #endif
    options[CGC_CLOCK_PLL4] = CGC_CLOCK_CHANGE_NONE;
#endif

    /* Start or stop clocks based on the input configuration. */
    for (int32_t i = (BSP_FEATURE_CGC_CLOCK_SOURCE_NUM - 1); i >= 0; i--)
    {
        cgc_clock_change_t clock_state     = options[i];
        cgc_clock_t        clock_to_change = (cgc_clock_t) i;

        if (CGC_CLOCK_CHANGE_STOP == clock_state)
        {
            R_BSP_RegisterProtectDisable(g_cgc_register_protect_settings[clock_to_change]);
            r_cgc_clock_change(clock_to_change, CGC_CLOCK_CHANGE_STOP);
            R_BSP_RegisterProtectEnable(g_cgc_register_protect_settings[clock_to_change]);
        }
        else if (CGC_CLOCK_CHANGE_START == clock_state)
        {
            R_BSP_RegisterProtectDisable(g_cgc_register_protect_settings[clock_to_change]);
#if BSP_FEATURE_CGC_PLL0_SSC_SUPPORTED

            /* Configure SSC before releasing PLL. */
            if ((clock_to_change == CGC_CLOCK_PLL0) && (R_SYSC_S->PLL0EN == 0))
            {
                r_cgc_pll_ssc_cfg(clock_to_change, &(p_clock_cfg->pll0_ssc_cfg));
            }
#endif
#if BSP_FEATURE_CGC_PLL2_SSC_SUPPORTED

            /* Configure SSC before releasing PLL. */
            if ((clock_to_change == CGC_CLOCK_PLL2) && (R_SYSC_S->PLL2EN == 0))
            {
                r_cgc_pll_ssc_cfg(clock_to_change, &(p_clock_cfg->pll2_ssc_cfg));
            }
#endif
#if BSP_FEATURE_CGC_PLL3_VCO_SETTING_SUPPORTED

            /* Configure VCO settings before releasing PLL. */
            if ((clock_to_change == CGC_CLOCK_PLL3) && (R_SYSC_S->PLL3EN == 0))
            {
                r_cgc_pll_vco_cfg(clock_to_change, &(p_clock_cfg->pll3_vco_cfg));
            }
#endif
            r_cgc_clock_change(clock_to_change, CGC_CLOCK_CHANGE_START);
            R_BSP_RegisterProtectEnable(g_cgc_register_protect_settings[clock_to_change]);
        }
        else
        {
            /* Do nothing. */
        }

        /* If the requested clock is not the subclock and it was just started and it has no stabilization flag, wait
         * for the required stabilization time in software. */
        if (g_cgc_software_wait_us[i] > 0U)
        {
            if (CGC_CLOCK_CHANGE_START == options[i])
            {
                R_BSP_SoftwareDelay(g_cgc_software_wait_us[i], BSP_DELAY_UNITS_MICROSECONDS);
            }
        }
    }

    /* CLMA settings are unsupported for CGC, so do not overwrite CLMA setting value. */
    clock_cfg.sckcr_w |= (uint32_t) (R_SYSC_NS->SCKCR_b.CLMASEL << R_SYSC_NS_SCKCR_CLMASEL_Pos);

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_CGC);
#if 2U == BSP_FEATURE_CGC_SCKCR_TYPE
    bsp_prv_clock_set(clock_cfg.sckcr_w, clock_cfg.sckcr2_w, clock_cfg.sckcr3_w, clock_cfg.sckcr4_w, sckcr5);
#elif 3U == BSP_FEATURE_CGC_SCKCR_TYPE

    /* DDR clock settings are unsupported for CGC, so do not overwrite DDR clock setting values. */
    clock_cfg.sckcr4_w |= (uint32_t) (R_SYSC_NS->SCKCR4_b.DDRCLKSEL << R_SYSC_NS_SCKCR4_DDRCLKSEL_Pos);
    clock_cfg.sckcr4_w |= (uint32_t) (R_SYSC_NS->SCKCR4_b.DDRDIVSEL << R_SYSC_NS_SCKCR4_DDRDIVSEL_Pos);

    bsp_prv_clock_set(clock_cfg.sckcr_w, clock_cfg.sckcr2_w, clock_cfg.sckcr3_w, clock_cfg.sckcr4_w,
                      clock_cfg.sckcr5_w);
#else
    bsp_prv_clock_set(clock_cfg.sckcr_w, clock_cfg.sckcr2_w, sckcr3, sckcr4, sckcr5);
#endif
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_CGC);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Start the specified clock if it is not currently active. Implements @ref cgc_api_t::clockStart.
 *
 * @retval FSP_SUCCESS                  Clock initialized successfully.
 * @retval FSP_ERR_ASSERTION            Invalid input argument.
 * @retval FSP_ERR_NOT_OPEN             Module is not open.
 **********************************************************************************************************************/
fsp_err_t R_CGC_ClockStart (cgc_ctrl_t * const p_ctrl, cgc_clock_t clock_source, cgc_pll_cfg_t const * const p_pll_cfg)
{
    cgc_instance_ctrl_t * p_instance_ctrl = (cgc_instance_ctrl_t *) p_ctrl;

    fsp_err_t err = FSP_SUCCESS;

#if CGC_CFG_PARAM_CHECKING_ENABLE
    err = r_cgc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

 #if BSP_FEATURE_CGC_PLL0_SSC_SUPPORTED
    if (CGC_CLOCK_PLL0 == clock_source)
    {
        FSP_ASSERT(NULL != p_pll_cfg);

        /* Set values should be within constraints. See RZ microprocessor Hardware Manual section "PLL0 and PLL2 SSC setting and constraints" */
        err = r_cgc_pll_ssc_parameter_checking(&(p_pll_cfg->pll0_ssc_cfg), CGC_CLOCK_PLL0);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }
 #endif

 #if BSP_FEATURE_CGC_PLL2_SSC_SUPPORTED
    if (CGC_CLOCK_PLL2 == clock_source)
    {
        FSP_ASSERT(NULL != p_pll_cfg);

        /* Set values should be within constraints. See RZ microprocessor Hardware Manual section "PLL0 and PLL2 SSC setting and constraints" */
        err = r_cgc_pll_ssc_parameter_checking(&(p_pll_cfg->pll2_ssc_cfg), CGC_CLOCK_PLL2);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }
 #endif

 #if BSP_FEATURE_CGC_PLL3_VCO_SETTING_SUPPORTED
    if (CGC_CLOCK_PLL3 == clock_source)
    {
        FSP_ASSERT(NULL != p_pll_cfg);

        /* Set values should be within constraints. See RZ microprocessor Hardware Manual section "PLL3 setting and constraints" */
        err = r_cgc_pll3_vco_parameter_checking(&(p_pll_cfg->pll3_vco_cfg));
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }
 #endif
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
    FSP_PARAMETER_NOT_USED(err);
#endif

    /* Start the clock. */
    R_BSP_RegisterProtectDisable(g_cgc_register_protect_settings[clock_source]);

#if !(BSP_FEATURE_CGC_PLL0_SSC_SUPPORTED || BSP_FEATURE_CGC_PLL2_SSC_SUPPORTED || \
      BSP_FEATURE_CGC_PLL3_VCO_SETTING_SUPPORTED)
    FSP_PARAMETER_NOT_USED(p_pll_cfg);
#endif

#if BSP_FEATURE_CGC_PLL0_SSC_SUPPORTED

    /* Configure SSC before releasing PLL. */
    if ((clock_source == CGC_CLOCK_PLL0) && (R_SYSC_S->PLL0EN == 0))
    {
        r_cgc_pll_ssc_cfg(clock_source, &p_pll_cfg->pll0_ssc_cfg);
    }
#endif
#if BSP_FEATURE_CGC_PLL2_SSC_SUPPORTED

    /* Configure SSC before releasing PLL. */
    if ((clock_source == CGC_CLOCK_PLL2) && (R_SYSC_S->PLL2EN == 0))
    {
        r_cgc_pll_ssc_cfg(clock_source, &p_pll_cfg->pll2_ssc_cfg);
    }
#endif
#if BSP_FEATURE_CGC_PLL3_VCO_SETTING_SUPPORTED

    /* Configure VCO settings before releasing PLL. */
    if ((clock_source == CGC_CLOCK_PLL3) && (R_SYSC_S->PLL3EN == 0))
    {
        r_cgc_pll_vco_cfg(clock_source, &p_pll_cfg->pll3_vco_cfg);
    }
#endif
    r_cgc_clock_change(clock_source, CGC_CLOCK_CHANGE_START);
    R_BSP_RegisterProtectEnable(g_cgc_register_protect_settings[clock_source]);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stop the specified clock if it is active.  Implements @ref cgc_api_t::clockStop.
 *
 * @retval FSP_SUCCESS                      Clock stopped successfully.
 * @retval FSP_ERR_ASSERTION                Invalid input argument.
 * @retval FSP_ERR_NOT_OPEN                 Module is not open.
 * @retval FSP_ERR_IN_USE                   Attempt to stop the current system clock or the PLL source clock.
 * @retval FSP_ERR_NOT_STABILIZED           Clock not stabilized after starting.
 **********************************************************************************************************************/
fsp_err_t R_CGC_ClockStop (cgc_ctrl_t * const p_ctrl, cgc_clock_t clock_source)
{
    cgc_instance_ctrl_t * p_instance_ctrl = (cgc_instance_ctrl_t *) p_ctrl;

#if CGC_CFG_PARAM_CHECKING_ENABLE

    /* Verify p_instance_ctrl is not NULL and the module is open. */
    fsp_err_t err = r_cgc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

 #if defined(BSP_CFG_CORE_CA55)

    /* CA55 core uses PLL0 as clock source. */
    FSP_ERROR_RETURN(clock_source != CGC_CLOCK_PLL0, FSP_ERR_ASSERTION);
 #endif

    /* Make sure the oscillator is stable. */
    FSP_ERROR_RETURN(r_cgc_stabilization_check(clock_source, r_cgc_clock_run_state_get(clock_source)),
                     FSP_ERR_NOT_STABILIZED);

 #if BSP_FEATURE_CGC_PLL1_STANDBY_STATE_SUPPORTED

    /* If clock source is in use, return error */
    FSP_ERROR_RETURN(!((clock_source == CGC_CLOCK_PLL1) && (R_SYSC_NS->SCKCR_b.PHYSEL == 0)), FSP_ERR_IN_USE);
 #endif
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
#endif

    /* Stop the clock. */
    R_BSP_RegisterProtectDisable(g_cgc_register_protect_settings[clock_source]);
    r_cgc_clock_change(clock_source, CGC_CLOCK_CHANGE_STOP);
    R_BSP_RegisterProtectEnable(g_cgc_register_protect_settings[clock_source]);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Set the specified clock as the system clock and configure the internal dividers.
 * Implements @ref cgc_api_t::systemClockSet.
 *
 * This function also updates the SystemCoreClock CMSIS global variable.
 *
 * @retval FSP_SUCCESS                  Operation performed successfully.
 * @retval FSP_ERR_ASSERTION            Invalid input argument.
 * @retval FSP_ERR_NOT_OPEN             Module is not open.
 * @retval FSP_ERR_CLOCK_INACTIVE       The specified clock source is inactive.
 * @retval FSP_ERR_NOT_STABILIZED       The clock source is not stabilized after being turned off or PLL clock source
 *                                      is not stable.
 **********************************************************************************************************************/
fsp_err_t R_CGC_SystemClockSet (cgc_ctrl_t * const              p_ctrl,
                                cgc_clock_t                     clock_source,
                                cgc_divider_cfg_t const * const p_divider_cfg)
{
    cgc_instance_ctrl_t * p_instance_ctrl = (cgc_instance_ctrl_t *) p_ctrl;

#if CGC_CFG_PARAM_CHECKING_ENABLE

    /* Verify p_instance_ctrl is not NULL and the module is open. */
    fsp_err_t err = r_cgc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    FSP_ASSERT(NULL != p_divider_cfg);

    /* Confirm the requested clock is stable. */
    err = r_cgc_clock_check(clock_source);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
    FSP_PARAMETER_NOT_USED(clock_source);
#endif

    cgc_divider_cfg_t clock_cfg;
    clock_cfg.sckcr_w  = p_divider_cfg->sckcr_w;
    clock_cfg.sckcr2_w = p_divider_cfg->sckcr2_w;
#if 2U == BSP_FEATURE_CGC_SCKCR_TYPE
    clock_cfg.sckcr3_w = p_divider_cfg->sckcr3_w;
    clock_cfg.sckcr4_w = p_divider_cfg->sckcr4_w;
    uint32_t sckcr5 = 0;               // dummy
#elif 3U == BSP_FEATURE_CGC_SCKCR_TYPE
    clock_cfg.sckcr3_w = p_divider_cfg->sckcr3_w;
    clock_cfg.sckcr4_w = p_divider_cfg->sckcr4_w;
    clock_cfg.sckcr5_w = p_divider_cfg->sckcr5_w;
#else
    uint32_t sckcr3 = 0;               // dummy
    uint32_t sckcr4 = 0;               // dummy
    uint32_t sckcr5 = 0;               // dummy
#endif

    /* CLMA settings are unsupported for CGC, so do not overwrite CLMA setting values. */
    clock_cfg.sckcr_w |= (uint32_t) (R_SYSC_NS->SCKCR_b.CLMASEL << R_SYSC_NS_SCKCR_CLMASEL_Pos);

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_CGC);
#if 2U == BSP_FEATURE_CGC_SCKCR_TYPE
    bsp_prv_clock_set(clock_cfg.sckcr_w, clock_cfg.sckcr2_w, clock_cfg.sckcr3_w, clock_cfg.sckcr4_w, sckcr5);
#elif 3U == BSP_FEATURE_CGC_SCKCR_TYPE

    /* DDR clock settings are unsupported for CGC, so that do not overwrite DDR clock setting values. */
    clock_cfg.sckcr4_w |= (uint32_t) (R_SYSC_NS->SCKCR4_b.DDRCLKSEL << R_SYSC_NS_SCKCR4_DDRCLKSEL_Pos);
    clock_cfg.sckcr4_w |= (uint32_t) (R_SYSC_NS->SCKCR4_b.DDRDIVSEL << R_SYSC_NS_SCKCR4_DDRDIVSEL_Pos);

    bsp_prv_clock_set(clock_cfg.sckcr_w, clock_cfg.sckcr2_w, clock_cfg.sckcr3_w, clock_cfg.sckcr4_w,
                      clock_cfg.sckcr5_w);
#else
    bsp_prv_clock_set(clock_cfg.sckcr_w, clock_cfg.sckcr2_w, sckcr3, sckcr4, sckcr5);
#endif
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_CGC);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Return the current system clock source and configuration.  Implements @ref cgc_api_t::systemClockGet.
 *
 * @retval FSP_SUCCESS                 Parameters returned successfully.
 * @retval FSP_ERR_ASSERTION           Invalid input argument.
 * @retval FSP_ERR_NOT_OPEN            Module is not open.
 **********************************************************************************************************************/
fsp_err_t R_CGC_SystemClockGet (cgc_ctrl_t * const        p_ctrl,
                                cgc_clock_t * const       p_clock_source,
                                cgc_divider_cfg_t * const p_divider_cfg)
{
    cgc_instance_ctrl_t * p_instance_ctrl = (cgc_instance_ctrl_t *) p_ctrl;

#if CGC_CFG_PARAM_CHECKING_ENABLE

    /* Verify p_instance_ctrl is not NULL and the module is open. */
    fsp_err_t err = r_cgc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
#endif

    /* Get the system clock source */
    if (NULL != p_clock_source)
    {
#if 2U == BSP_FEATURE_CGC_SCKCR_TYPE || 3U == BSP_FEATURE_CGC_SCKCR_TYPE

        /* Always return PLL1 as system clock source. */
        *p_clock_source = CGC_CLOCK_PLL1;
#else

        /* Always return PLL0 as system clock source. */
        *p_clock_source = CGC_CLOCK_PLL0;
#endif
    }

    /* Get current dividers. */
    if (NULL != p_divider_cfg)
    {
        p_divider_cfg->sckcr_w  = R_SYSC_NS->SCKCR & (uint32_t) (~(R_SYSC_NS_SCKCR_CLMASEL_Msk));
        p_divider_cfg->sckcr2_w = R_SYSC_S->SCKCR2;
#if 2U == BSP_FEATURE_CGC_SCKCR_TYPE
        p_divider_cfg->sckcr3_w = R_SYSC_NS->SCKCR3;
        p_divider_cfg->sckcr4_w = R_SYSC_NS->SCKCR4;
#elif 3U == BSP_FEATURE_CGC_SCKCR_TYPE
        p_divider_cfg->sckcr3_w = R_SYSC_NS->SCKCR3;
        p_divider_cfg->sckcr4_w = R_SYSC_NS->SCKCR4 &
                                  (uint32_t) (~(R_SYSC_NS_SCKCR4_DDRCLKSEL_Msk | R_SYSC_NS_SCKCR4_DDRDIVSEL_Msk));
        p_divider_cfg->sckcr5_w = R_SYSC_NS->SCKCR5;
#endif
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Check the specified clock for stability.  Implements @ref cgc_api_t::clockCheck.
 *
 * @retval FSP_SUCCESS                 Clock is running and stable.
 * @retval FSP_ERR_ASSERTION           Invalid input argument.
 * @retval FSP_ERR_NOT_OPEN            Module is not open.
 * @retval FSP_ERR_NOT_STABILIZED      Clock not stabilized.
 * @retval FSP_ERR_CLOCK_INACTIVE      Clock not turned on.
 **********************************************************************************************************************/
fsp_err_t R_CGC_ClockCheck (cgc_ctrl_t * const p_ctrl, cgc_clock_t clock_source)
{
    cgc_instance_ctrl_t * p_instance_ctrl = (cgc_instance_ctrl_t *) p_ctrl;
    fsp_err_t             err;

#if CGC_CFG_PARAM_CHECKING_ENABLE

    /* Verify p_instance_ctrl is not NULL and the module is open. */
    err = r_cgc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
#endif

    /* Ensure the clock is running and stable. */
    err = r_cgc_clock_check(clock_source);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enable the oscillation stop detection for the main clock. API not supported.
 *
 * Implements @ref cgc_api_t::oscStopDetectEnable.
 *
 * @retval FSP_ERR_UNSUPPORTED    API not supported.
 **********************************************************************************************************************/
fsp_err_t R_CGC_OscStopDetectEnable (cgc_ctrl_t * const p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Disable the oscillation stop detection for the main clock. API not supported.
 *
 * Implements @ref cgc_api_t::oscStopDetectDisable.
 *
 * @retval FSP_ERR_UNSUPPORTED    API not supported.
 **********************************************************************************************************************/
fsp_err_t R_CGC_OscStopDetectDisable (cgc_ctrl_t * const p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Clear the Oscillation Stop Detection Status register. API not supported.
 *
 * Implements @ref cgc_api_t::oscStopStatusClear.
 *
 * @retval FSP_ERR_UNSUPPORTED    API not supported.
 **********************************************************************************************************************/
fsp_err_t R_CGC_OscStopStatusClear (cgc_ctrl_t * const p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements cgc_api_t::callbackSet
 *
 * @retval FSP_ERR_UNSUPPORTED    API not supported.
 **********************************************************************************************************************/
fsp_err_t R_CGC_CallbackSet (cgc_ctrl_t * const          p_ctrl,
                             void (                    * p_callback)(cgc_callback_args_t *),
                             void * const                p_context,
                             cgc_callback_args_t * const p_callback_memory)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_callback);
    FSP_PARAMETER_NOT_USED(p_context);
    FSP_PARAMETER_NOT_USED(p_callback_memory);

    return FSP_ERR_UNSUPPORTED;
}

/******************************************************************************************************************//**
 * Closes the CGC module.  Implements @ref cgc_api_t::close.
 *
 * @retval FSP_SUCCESS                 The module is successfully closed.
 * @retval FSP_ERR_ASSERTION           Invalid input argument.
 * @retval FSP_ERR_NOT_OPEN            Module is not open.
 **********************************************************************************************************************/
fsp_err_t R_CGC_Close (cgc_ctrl_t * const p_ctrl)
{
    cgc_instance_ctrl_t * p_instance_ctrl = (cgc_instance_ctrl_t *) p_ctrl;

#if CGC_CFG_PARAM_CHECKING_ENABLE

    /* Verify p_instance_ctrl is not NULL and the module is open. */
    fsp_err_t err = r_cgc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    p_instance_ctrl->open = 0U;

    /* All done, return success. */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup CGC)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

#if CGC_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Verifies the control structure is not NULL and the module is open. This reduces code size when the error logger is
 * used.
 *
 * @param[in]  p_instance_ctrl          Pointer to instance control structure.
 *
 * @retval FSP_SUCCESS                  No error detected.
 * @retval FSP_ERR_ASSERTION            Invalid input argument.
 * @retval FSP_ERR_NOT_OPEN             Module is not open.
 **********************************************************************************************************************/
static fsp_err_t r_cgc_common_parameter_checking (cgc_instance_ctrl_t * p_instance_ctrl)
{
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(CGC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    return FSP_SUCCESS;
}

 #if BSP_FEATURE_CGC_PLL0_SSC_SUPPORTED || BSP_FEATURE_CGC_PLL2_SSC_SUPPORTED

/*******************************************************************************************************************//**
 * Verifies the SSC setting structure values are within constraints.
 * See RZ microprocessor Hardware Manual section "PLL0 and PLL2 SSC setting and constraints"
 *
 * @param[in]  p_pll_ssc_setting        Pointer to SSC setting structure.
 * @param[in]  clock                    Clock to be verified.
 *
 * @retval FSP_SUCCESS                  No error detected.
 * @retval FSP_ERR_ASSERTION            Invalid input argument.
 **********************************************************************************************************************/
static fsp_err_t r_cgc_pll_ssc_parameter_checking (cgc_pll_ssc_cfg_t const * p_pll_ssc_setting, cgc_clock_t clock)
{
    if (1 == p_pll_ssc_setting->pll_ssc_enable)
    {
        uint32_t mfr = p_pll_ssc_setting->pll_ssc_modulation_freq_ctrl;
        uint32_t mrr = p_pll_ssc_setting->pll_ssc_modulation_rate_ctrl;

        FSP_ASSERT(CGC_PRV_MFR_MAX >= mfr);
        FSP_ASSERT(CGC_PRV_MRR_MIN <= mrr && CGC_PRV_MRR_MAX >= mrr);

        uint32_t mfr_mrr = mfr * mrr;

        /* MMF integer value for parameter checking of max constraint. (Round up the result of division.) */
        uint32_t mmf_max =
            (CGC_PRV_MAIN_CLOCK_OSC_FREQUENCY_HZ + (mfr * CGC_PRV_SSC_MODULATION_FREQUENCY_DIV_VALUE) - 1U) /
            (mfr * CGC_PRV_SSC_MODULATION_FREQUENCY_DIV_VALUE);

        /* MMF integer value for parameter checking of min constraint.(Round down the result of division.) */
        uint32_t mmf_min = CGC_PRV_MAIN_CLOCK_OSC_FREQUENCY_HZ / (mfr * CGC_PRV_SSC_MODULATION_FREQUENCY_DIV_VALUE);

        /* MMR integer value for parameter checking of max constraint. (Round up the result of division.) */
        uint32_t mmr_max =
            (clock == CGC_CLOCK_PLL0) ?
            (mfr_mrr * CGC_PRV_PERCENTAGE_TRANSLATION + BSP_FEATURE_CGC_SSC_MODULATION_RATE_DIVISOR_M_PLL0 *
             CGC_PRV_SSC_MODULATION_RATE_DIV_VALUE - 1U) /
            BSP_FEATURE_CGC_SSC_MODULATION_RATE_DIVISOR_M_PLL0 / CGC_PRV_SSC_MODULATION_RATE_DIV_VALUE :
            (mfr_mrr * CGC_PRV_PERCENTAGE_TRANSLATION + BSP_FEATURE_CGC_SSC_MODULATION_RATE_DIVISOR_M_PLL2 *
             CGC_PRV_SSC_MODULATION_RATE_DIV_VALUE - 1U) /
            BSP_FEATURE_CGC_SSC_MODULATION_RATE_DIVISOR_M_PLL2 / CGC_PRV_SSC_MODULATION_RATE_DIV_VALUE;

        FSP_ASSERT(CGC_PRV_MFR_MMR_MAX >= mfr_mrr);
        FSP_ASSERT(CGC_PRV_MODULATION_FREQUENCY_MIN_HZ <= mmf_min && CGC_PRV_MODULATION_FREQUENCY_MAX_HZ >= mmf_max);
        FSP_ASSERT(CGC_PRV_MODULATION_RATE_MAX_PERCENTAGE >= mmr_max);
    }

    return FSP_SUCCESS;
}

 #endif

 #if BSP_FEATURE_CGC_PLL3_VCO_SETTING_SUPPORTED

/*******************************************************************************************************************//**
 * Verifies the VCO setting structure values are within constraints.
 * See RZ microprocessor Hardware Manual section "PLL3 setting and constraints"
 *
 * @param[in]  p_pll_vco_setting        Pointer to VCO setting structure.
 *
 * @retval FSP_SUCCESS                  No error detected.
 * @retval FSP_ERR_ASSERTION            Invalid input argument.
 **********************************************************************************************************************/
static fsp_err_t r_cgc_pll3_vco_parameter_checking (cgc_pll_vco_cfg_t const * p_pll_vco_setting)
{
    uint32_t p_divider = p_pll_vco_setting->pll_divider_p;
    uint32_t m_divider = p_pll_vco_setting->pll_divider_m;
    uint32_t s_divider = p_pll_vco_setting->pll_divider_s;
    uint32_t k_divider = p_pll_vco_setting->pll_divider_delta_sigma_modulator;

    FSP_ASSERT(CGC_PRV_P_DIVIDER_MIN <= p_divider && CGC_PRV_P_DIVIDER_MAX >= p_divider);
    FSP_ASSERT(CGC_PRV_M_DIVIDER_MIN <= m_divider && CGC_PRV_M_DIVIDER_MAX >= m_divider);
    FSP_ASSERT(CGC_PRV_S_DIVIDER_MAX >= s_divider);
    FSP_ASSERT(CGC_PRV_K_DIVIDER_MAX >= k_divider);

    /* FFREF integer value for parameter checking of max constraint. (Round up the result of division.) */
    uint32_t ffref_max = (CGC_PRV_PLL3_INPUT_FREQUENCY_MHZ + p_divider - 1U) / p_divider;

    /* FFREF integer value for parameter checking of min constraint. (Round down the result of division.) */
    uint32_t ffref_min = CGC_PRV_PLL3_INPUT_FREQUENCY_MHZ / p_divider;

    /* FFVCO integer value for parameter checking of max constraint. (Round up the result of division.) */
    uint32_t ffvco_max = (m_divider * CGC_PRV_PLL3_INPUT_FREQUENCY_MHZ * CGC_PRV_K_DIVIDER_DIV_VALUE +
                          k_divider * CGC_PRV_PLL3_INPUT_FREQUENCY_MHZ +
                          CGC_PRV_K_DIVIDER_DIV_VALUE * p_divider - 1) /
                         (CGC_PRV_K_DIVIDER_DIV_VALUE * p_divider);

    /* FFVCO integer value for parameter checking of min constraint. (Round down the result of division.) */
    uint32_t ffvco_min = (m_divider * CGC_PRV_PLL3_INPUT_FREQUENCY_MHZ * CGC_PRV_K_DIVIDER_DIV_VALUE +
                          k_divider * CGC_PRV_PLL3_INPUT_FREQUENCY_MHZ) /
                         (CGC_PRV_K_DIVIDER_DIV_VALUE * p_divider);

    /* FFOUT integer value for parameter checking of max constraint. (Round up the result of division.) */
    uint32_t ffout_max = (m_divider * CGC_PRV_PLL3_INPUT_FREQUENCY_MHZ * CGC_PRV_K_DIVIDER_DIV_VALUE +
                          k_divider * CGC_PRV_PLL3_INPUT_FREQUENCY_MHZ +
                          CGC_PRV_K_DIVIDER_DIV_VALUE * p_divider * (1U << s_divider) - 1) /
                         (CGC_PRV_K_DIVIDER_DIV_VALUE * p_divider * (1U << s_divider));

    /* FFOUT integer value for parameter checking of min constraint. (Round down the result of division.) */
    uint32_t ffout_min = (m_divider * CGC_PRV_PLL3_INPUT_FREQUENCY_MHZ * CGC_PRV_K_DIVIDER_DIV_VALUE +
                          k_divider * CGC_PRV_PLL3_INPUT_FREQUENCY_MHZ) /
                         (CGC_PRV_K_DIVIDER_DIV_VALUE * p_divider * (1U << s_divider));

    FSP_ASSERT(CGC_PRV_REFERENCE_FREQUENCY_MIN_MHZ <= ffref_min && CGC_PRV_REFERENCE_FREQUENCY_MAX_MHZ >= ffref_max);
    FSP_ASSERT(CGC_PRV_VCO_FREQUENCY_MIN_MHZ <= ffvco_min && CGC_PRV_VCO_FREQUENCY_MAX_MHZ >= ffvco_max);
    FSP_ASSERT(CGC_PRV_PLL_OUTPUT_FREQUENCY_MIN_MHZ <= ffout_min && CGC_PRV_PLL_OUTPUT_FREQUENCY_MAX_MHZ >= ffout_max);

    return FSP_SUCCESS;
}

 #endif

#endif

/*******************************************************************************************************************//**
 * Check if the specified clock is running and stable
 *
 * @param[in]   clock_source           Clock to be verified
 *
 * @retval FSP_SUCCESS                 Clock is running and stable.
 * @retval FSP_ERR_NOT_STABILIZED      Clock not stabilized.
 * @retval FSP_ERR_CLOCK_INACTIVE      Clock not turned on.
 **********************************************************************************************************************/
static fsp_err_t r_cgc_clock_check (cgc_clock_t const clock_source)
{
    cgc_prv_clock_state_t running = r_cgc_clock_run_state_get(clock_source);

    /* Ensure the clock is stable if the clock has a stabilization flag. */
    FSP_ERROR_RETURN(r_cgc_stabilization_check(clock_source, running), FSP_ERR_NOT_STABILIZED);

#if 2 == BSP_FEATURE_CGC_PLL_START_PROCESS_TYPE

    /* Ensure clock source of the PLL clock domain is the PLL. */
    FSP_ERROR_RETURN(r_cgc_pll_domain_clock_source_check(clock_source), FSP_ERR_NOT_STABILIZED);
#endif

    /* Ensure the clock is running. */
    FSP_ERROR_RETURN(running, FSP_ERR_CLOCK_INACTIVE);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * This function returns the run state of the selected clock
 *
 * @param[in]  clock   Clock to check
 *
 * @return  1 if running, 0 if stopped
 **********************************************************************************************************************/
static cgc_prv_clock_state_t r_cgc_clock_run_state_get (cgc_clock_t clock)
{
    cgc_prv_clock_state_t ret = CGC_PRV_CLOCK_STATE_STOPPED;

    /* Get clock run state via control register if clock have control register. */
    if (NULL != gp_cgc_clock_stp_registers[clock])
    {
        /* Get clock run state. */
        ret = (cgc_prv_clock_state_t) (*gp_cgc_clock_stp_registers[clock]);
    }
    else
    {
        /* Selected PLL have no control register and is always running. */
        ret = CGC_PRV_CLOCK_STATE_RUNNING;
    }

    return ret;
}

/*******************************************************************************************************************//**
 * This function checks the selected clock for stability.
 *
 * @param[in]  clock   Clock to check
 * @param[in]  status  Current state of the clock
 *
 * @return true if stable or the clock has no stability flag, false if not stable
 **********************************************************************************************************************/
static bool r_cgc_stabilization_check (cgc_clock_t clock, cgc_prv_clock_state_t status)
{
    /* LOCO have no stabilization flags, so return true if the clock is any of these. */
    bool ret = true;

    switch (clock)
    {
        case CGC_CLOCK_PLL0:
        {
            ret = (R_SYSC_S->PLL0MON_b.PLL0MON == (uint32_t) status);
            break;
        }

        case CGC_CLOCK_PLL1:
        {
            ret = (R_SYSC_S->PLL1MON_b.PLL1MON == (uint32_t) status);
            break;
        }

#if BSP_FEATURE_CGC_HAS_PLL2
        case CGC_CLOCK_PLL2:
        {
            ret = (R_SYSC_S->PLL2MON_b.PLL2MON == (uint32_t) status);
            break;
        }
#endif
#if BSP_FEATURE_CGC_HAS_PLL3
        case CGC_CLOCK_PLL3:
        {
            ret = (R_SYSC_S->PLL3MON_b.PLL3MON == (uint32_t) status);
            break;
        }
#endif
#if BSP_FEATURE_CGC_HAS_PLL4
        case CGC_CLOCK_PLL4:
        {
            ret = (R_SYSC_S->PLL4MON_b.PLL4MON == (uint32_t) status);
            break;
        }
#endif
        default:
        {
            break;
        }
    }

    return ret;
}

#if 2 == BSP_FEATURE_CGC_PLL_START_PROCESS_TYPE

/*******************************************************************************************************************//**
 * This function checks the clock source for the domain of the selected PLL is PLL output clock.
 *
 * @param[in]  clock   PLL to check
 *
 * @return true if the clock source for the domain of the selected PLL is PLL output clock, false if not.
 **********************************************************************************************************************/
static bool r_cgc_pll_domain_clock_source_check (cgc_clock_t clock)
{
    bool ret = true;
    switch (clock)
    {
        case CGC_CLOCK_PLL0:
        {
            ret =
                (((*((uint32_t *) CGC_PRV_PMSEL_REGISTER_ADDRESS) >> CGC_PRV_PMSEL_PMSEL0MON_SHIFT) &
                  CGC_PRV_PMSEL_PMSELMON_MASK) == 1);
            break;
        }

        case CGC_CLOCK_PLL1:
        {
            ret =
                (((*((uint32_t *) CGC_PRV_PMSEL_REGISTER_ADDRESS) >> CGC_PRV_PMSEL_PMSEL1MON_SHIFT) &
                  CGC_PRV_PMSEL_PMSELMON_MASK) == 1);
            break;
        }

 #if BSP_FEATURE_CGC_HAS_PLL2
        case CGC_CLOCK_PLL2:
        {
            ret =
                (((*((uint32_t *) CGC_PRV_PMSEL_REGISTER_ADDRESS) >> CGC_PRV_PMSEL_PMSEL2MON_SHIFT) &
                  CGC_PRV_PMSEL_PMSELMON_MASK) == 1);
            break;
        }
 #endif
 #if BSP_FEATURE_CGC_HAS_PLL3
        case CGC_CLOCK_PLL3:
        {
            ret =
                (((*((uint32_t *) CGC_PRV_PMSEL_REGISTER_ADDRESS) >> CGC_PRV_PMSEL_PMSEL3MON_SHIFT) &
                  CGC_PRV_PMSEL_PMSELMON_MASK) == 1);
            break;
        }
 #endif
 #if BSP_FEATURE_CGC_HAS_PLL4
        case CGC_CLOCK_PLL4:
        {
            ret =
                (((*((uint32_t *) CGC_PRV_PMSEL_REGISTER_ADDRESS) >> CGC_PRV_PMSEL_PMSEL4MON_SHIFT) &
                  CGC_PRV_PMSEL_PMSELMON_MASK) == 1);
            break;
        }
 #endif
        default:
        {
            break;
        }
    }

    return ret;
}

#endif

/*******************************************************************************************************************//**
 * This function starts or stops the selected clock.
 * Do not call this subroutine with CGC_CLOCK_CHANGE_NONE or CGC_CLOCK_CHANGE_UNSUPPORTED.
 *
 * @param[in]  clock   Clock to start or stop
 * @param[in]  state   1 to stop clock, 0 to start clock
 **********************************************************************************************************************/
static void r_cgc_clock_change (cgc_clock_t clock, cgc_clock_change_t state)
{
    /* Convert api defined value to register setting value. */
    uint32_t state_set_value = ((uint32_t) (~state) & 0x00000001U);

    if (gp_cgc_clock_stp_registers[clock] != NULL)
    {
        *gp_cgc_clock_stp_registers[clock] = state_set_value;

        /* Wait setting to be reflected in hardware registers. */
        FSP_HARDWARE_REGISTER_WAIT(*gp_cgc_clock_stp_registers[clock], state_set_value);
    }
    else
    {
        /* Selected PLL have no control register. */
    }
}

#if BSP_FEATURE_CGC_PLL0_SSC_SUPPORTED || BSP_FEATURE_CGC_PLL2_SSC_SUPPORTED

/*******************************************************************************************************************//**
 * This function sets the SSC setting register for PLL.
 *
 * @param[in]  clock          PLL to set SSC.
 * @param[in]  p_pll_ssc_cfg  Configuration values for SSC.
 **********************************************************************************************************************/
static void r_cgc_pll_ssc_cfg (cgc_clock_t clock, cgc_pll_ssc_cfg_t const * p_pll_ssc_cfg)
{
    if (clock == CGC_CLOCK_PLL0)
    {
        R_SYSC_S->PLL0_SSC_CTR = (uint32_t) p_pll_ssc_cfg->pll_ssc_modulation_freq_ctrl <<
                                 R_SYSC_S_PLL0_SSC_CTR_PLL0MFR_Pos |
                                 (uint32_t) p_pll_ssc_cfg->pll_ssc_modulation_rate_ctrl <<
                                 R_SYSC_S_PLL0_SSC_CTR_PLL0MRR_Pos |
                                 (uint32_t) p_pll_ssc_cfg->pll_ssc_enable << R_SYSC_S_PLL0_SSC_CTR_PLL0SSCEN_Pos;
    }

    if (clock == CGC_CLOCK_PLL2)
    {
        R_SYSC_S->PLL2_SSC_CTR = (uint32_t) p_pll_ssc_cfg->pll_ssc_modulation_freq_ctrl <<
                                 R_SYSC_S_PLL2_SSC_CTR_PLL2MFR_Pos |
                                 (uint32_t) p_pll_ssc_cfg->pll_ssc_modulation_rate_ctrl <<
                                 R_SYSC_S_PLL2_SSC_CTR_PLL2MRR_Pos |
                                 (uint32_t) p_pll_ssc_cfg->pll_ssc_enable << R_SYSC_S_PLL2_SSC_CTR_PLL2SSCEN_Pos;
    }
}

#endif

#if BSP_FEATURE_CGC_PLL3_VCO_SETTING_SUPPORTED

/*******************************************************************************************************************//**
 * This function sets the PLL setting.
 *
 * @param[in]  clock          PLL you want to set the configuration.
 * @param[in]  p_pll_vco_cfg  Configuration values for the PLL.
 **********************************************************************************************************************/
static void r_cgc_pll_vco_cfg (cgc_clock_t clock, cgc_pll_vco_cfg_t const * p_pll_vco_cfg)
{
    if (clock == CGC_CLOCK_PLL3)
    {
        R_SYSC_S->PLL3_VCO_CTR0 = (uint32_t) p_pll_vco_cfg->pll_divider_p << R_SYSC_S_PLL3_VCO_CTR0_PLL3P_Pos |
                                  (uint32_t) p_pll_vco_cfg->pll_divider_m << R_SYSC_S_PLL3_VCO_CTR0_PLL3M_Pos;

        R_SYSC_S->PLL3_VCO_CTR1 = (uint32_t) p_pll_vco_cfg->pll_divider_delta_sigma_modulator <<
                                  R_SYSC_S_PLL3_VCO_CTR1_PLL3K_Pos |
                                  (uint32_t) p_pll_vco_cfg->pll_divider_s << R_SYSC_S_PLL3_VCO_CTR1_PLL3S_Pos;
    }
}

#endif
