/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "bsp_api.h"

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_bsc_sdram.h"
#include "r_bsc_sdram_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "BSDR" in ASCII, used to determine if channel is open. */
#define BSC_SDRAM_PRV_OPEN                       (0x42534452)

#define BSC_SDRAM_CHANNEL_DUMMY                  (0x0U)
#define BSC_SDRAM_VALID_CS_CHANNELS              (0x0C) /* Valid channel : CS2 and CS3 */

/* BSC CSNBCR register bit masks */
#define BSC_SDRAM_PRV_CSNBCR_BSZ_VALUE_MASK      (0x03U)
#define BSC_SDRAM_PRV_CSNBCR_IWRRS_VALUE_MASK    (0x07U)
#define BSC_SDRAM_PRV_CSNBCR_IWRRD_VALUE_MASK    (0x07U)
#define BSC_SDRAM_PRV_CSNBCR_IWRWS_VALUE_MASK    (0x07U)
#define BSC_SDRAM_PRV_CSNBCR_IWRWD_VALUE_MASK    (0x07U)
#define BSC_SDRAM_PRV_CSNBCR_IWW_VALUE_MASK      (0x07U)

#define BSC_SDRAM_PRV_CSNBCR_TYPE_SDRAM          (0x04U)
#define BSC_SDRAM_PRV_CSNBCR_RESERVED_Pos        (11U)

/* BSC CSNWCR register bit masks */
#define BSC_SDRAM_PRV_CSNWCR_WTRC_VALUE_MASK     (0x03U)
#define BSC_SDRAM_PRV_CSNWCR_TRWL_VALUE_MASK     (0x03U)
#define BSC_SDRAM_PRV_CSNWCR_A3CL_VALUE_MASK     (0x03U)
#define BSC_SDRAM_PRV_CSNWCR_WTRCD_VALUE_MASK    (0x03U)
#define BSC_SDRAM_PRV_CSNWCR_WTRP_VALUE_MASK     (0x03U)

#define BSC_SDRAM_PRV_CSNWCR_A2CL_VALUE_MASK     (0x03U)
#define BSC_SDRAM_PRB_CS2WCR_10BIT_MASK          (1U << 10U)

/* BSC SDCR register bit masks */
#define BSC_SDRAM_PRV_SDCR_A3COL_VALUE_MASK      (0x03U)
#define BSC_SDRAM_PRV_SDCR_A3ROW_VALUE_MASK      (0x03U)
#define BSC_SDRAM_PRV_SDCR_A2COL_VALUE_MASK      (0x03U)
#define BSC_SDRAM_PRV_SDCR_A2ROW_VALUE_MASK      (0x03U)
#define BSC_SDRAM_PRV_SDCR_BACTV_VALUE_MASK      (0x01U)

/* BSC RTCSR register bit mask */
#define BSC_SDRAM_PRV_RTCSR_RRC_Pos              (0U)
#define BSC_SDRAM_PRV_RTCSR_RRC_VALUE_MASK       (0x07U)
#define BSC_SDRAM_PRV_RTCSR_CKS_Pos              (3U)
#define BSC_SDRAM_PRV_RTCSR_CKS_VALUE_MASK       (0x07U)
#define BSC_SDRAM_PRV_RTCSR_CMIE_Msk             (0x40UL)
#define BSC_SDRAM_PRV_RTCSR_CMF_Msk              (0x80UL)

/* SDRAM MRS Configuration */
#define BSC_SDRAM_MRS_CS2_ACCESS_ADDRESS_BASE    (0x80211000)
#define BSC_SDRAM_MRS_CS3_ACCESS_ADDRESS_BASE    (0x80212000)
#define BSC_SDRAM_MRS_BUTST_LENGTH_1             (0x00U)
#define BSC_SDRAM_MRS_BURST_LENGTH_Pos           (0U)
#define BSC_SDRAM_MRS_WRAP_SEQUENTIAL            (0x00U)
#define BSC_SDRAM_MRS_WRAP_MODE_Pos              (3U)
#define BSC_SDRAM_MRS_LTMODE_Pos                 (4U)
#define BSC_SDRAM_MRS_LTMODE_VALUE_MASK          (0x07U)
#define BSC_SDRAM_MRS_WRITE_MODE_Pos             (9U)
#define BSC_SDRAM_MRS_WRITE_MODE_VALUE_MASK      (0x01U)

#define BSC_SDRAM_MRS_SETTING_DUMMY_DATA         (0x0000U)

#define BSC_SDRAM_PROTECT_KEY                    (0xA55A0000)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
#if BSC_SDRAM_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t r_bsc_sdram_open_param_checking(bsc_sdram_instance_ctrl_t * p_instance_ctrl,
                                                 sdram_cfg_t const * const   p_cfg);

#endif

/***********************************************************************************************************************
 * ISR prototypes
 **********************************************************************************************************************/
void bsc_sdram_cmi_int_isr(void);

/** Look-up table for WTRC values */
static const uint32_t wtrc_value_lut[] =
{
    [2] = 0U,
    [3] = 1U,
    [5] = 2U,
    [8] = 3U,
};

/** Look-up table for Auto-Refresh count clock source */
static const uint32_t cks_value_lut[] =
{
    [SDRAM_REFRESH_CYCLE_SOURCE_DIV_4]    = 1U,
    [SDRAM_REFRESH_CYCLE_SOURCE_DIV_16]   = 2U,
    [SDRAM_REFRESH_CYCLE_SOURCE_DIV_64]   = 3U,
    [SDRAM_REFRESH_CYCLE_SOURCE_DIV_256]  = 4U,
    [SDRAM_REFRESH_CYCLE_SOURCE_DIV_1024] = 5U,
    [SDRAM_REFRESH_CYCLE_SOURCE_DIV_2048] = 6U,
    [SDRAM_REFRESH_CYCLE_SOURCE_DIV_4096] = 7U,
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZN
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZN_BSC_SDRAM
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/
const sdram_api_t g_sdram_on_bsc_sdram =
{
    .open             = R_BSC_SDRAM_Open,
    .selfRefreshEnter = R_BSC_SDRAM_SelfRefreshEnter,
    .selfRefreshExit  = R_BSC_SDRAM_SelfRefreshExit,
    .powerDownEnter   = R_BSC_SDRAM_PowerDownEnter,
    .powerDownExit    = R_BSC_SDRAM_PowerDownExit,
    .close            = R_BSC_SDRAM_Close,
};

/*******************************************************************************************************************//**
 * Open the BSC_SDRAM driver module. Configure the BSC and operate the SDRAM initialization.
 * (PALL command is firstly issued. REF command is issued 8 times. MRS command is finally issued.)
 *
 * User can access to the SDRAM like internal memory starting at address 0x78000000 or 0x58000000.
 *
 * @note After the driver is open, Auto-Refresh operation is started.
 *
 * Implements @ref sdram_api_t::open.
 *
 * @retval FSP_SUCCESS              Configuration was successful.
 * @retval FSP_ERR_ASSERTION        The parameter p_instance_ctrl or p_cfg is NULL.
 * @retval FSP_ERR_INVALID_CHANNEL  Invalid Channel.
 * @retval FSP_ERR_ALREADY_OPEN     Driver has already been opened with the same p_instance_ctrl.
 * @retval FSP_ERR_INVALID_ARGUMENT SDRAM parameter is not available.
 **********************************************************************************************************************/
fsp_err_t R_BSC_SDRAM_Open (sdram_ctrl_t * p_ctrl, sdram_cfg_t const * const p_cfg)
{
    bsc_sdram_instance_ctrl_t * p_instance_ctrl = (bsc_sdram_instance_ctrl_t *) p_ctrl;

#if BSC_SDRAM_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = r_bsc_sdram_open_param_checking(p_instance_ctrl, p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    bsc_sdram_extended_cfg_t * p_cfg_extend = (bsc_sdram_extended_cfg_t *) p_cfg->p_extend;

    /* Enable clock to the BSC block */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_START(FSP_IP_BSC, BSC_SDRAM_CHANNEL_DUMMY);
    R_BSP_MODULE_START(FSP_IP_CKIO, BSC_SDRAM_CHANNEL_DUMMY);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    /* Save configurations. */
    p_instance_ctrl->p_cfg = p_cfg;

    /* Calculate the CSnWCR register base address. */
    uint32_t   address_gap = (uint32_t) &R_BSC->CS3WCR_0 - (uint32_t) &R_BSC->CS2WCR_0;
    uint32_t * p_csnwcr    = (uint32_t *) ((uint32_t) &R_BSC->CS0WCR_0 + (address_gap * p_cfg_extend->chip_select));

    /* Set bus access idle cycle. */
    uint32_t csnbcr = (((p_cfg->data_width & BSC_SDRAM_PRV_CSNBCR_BSZ_VALUE_MASK) <<
                        R_BSC_CSnBCR_BSZ_Pos) |
                       1U << BSC_SDRAM_PRV_CSNBCR_RESERVED_Pos |
                       (BSC_SDRAM_PRV_CSNBCR_TYPE_SDRAM << R_BSC_CSnBCR_TYPE_Pos) |
                       ((p_cfg_extend->r_r_same_space_idle_cycle & BSC_SDRAM_PRV_CSNBCR_IWRRS_VALUE_MASK) <<
                        R_BSC_CSnBCR_IWRRS_Pos) |
                       ((p_cfg_extend->r_r_different_space_idle_cycle & BSC_SDRAM_PRV_CSNBCR_IWRRD_VALUE_MASK) <<
                        R_BSC_CSnBCR_IWRRD_Pos) |
                       ((p_cfg_extend->r_w_same_space_idle_cycle & BSC_SDRAM_PRV_CSNBCR_IWRWS_VALUE_MASK) <<
                        R_BSC_CSnBCR_IWRWS_Pos) |
                       ((p_cfg_extend->r_w_different_space_idle_cycle & BSC_SDRAM_PRV_CSNBCR_IWRWD_VALUE_MASK) <<
                        R_BSC_CSnBCR_IWRWD_Pos) |
                       ((p_cfg_extend->w_r_w_w_idle_cycle & BSC_SDRAM_PRV_CSNBCR_IWW_VALUE_MASK) <<
                        R_BSC_CSnBCR_IWW_Pos));

    /* Set SDRAM wait control setting. */
    uint32_t wtrc   = wtrc_value_lut[p_cfg->row_cycle];
    uint32_t csnwcr = (wtrc & BSC_SDRAM_PRV_CSNWCR_WTRC_VALUE_MASK) << R_BSC_CS3WCR_1_WTRC_Pos |
                      (p_cfg->write_recovery_cycle & BSC_SDRAM_PRV_CSNWCR_TRWL_VALUE_MASK) << R_BSC_CS3WCR_1_TRWL_Pos |
                      ((p_cfg->cas_latency - 1U) & BSC_SDRAM_PRV_CSNWCR_A3CL_VALUE_MASK) << R_BSC_CS3WCR_1_A3CL_Pos |
                      (p_cfg->ras_to_cas_delay_cycle & BSC_SDRAM_PRV_CSNWCR_WTRCD_VALUE_MASK) <<
                      R_BSC_CS3WCR_1_WTRCD_Pos |
                      (p_cfg->ras_precharge_cycle & BSC_SDRAM_PRV_CSNWCR_WTRP_VALUE_MASK) << R_BSC_CS3WCR_1_WTRP_Pos;

    /* Set SDRAM control setting. */
    uint32_t sdcr = (p_cfg->column_address_width & BSC_SDRAM_PRV_SDCR_A3COL_VALUE_MASK) << R_BSC_SDCR_A3COL_Pos |
                    ((p_cfg->row_address_width - 3U) & BSC_SDRAM_PRV_SDCR_A3ROW_VALUE_MASK) << R_BSC_SDCR_A3ROW_Pos |
                    (p_cfg_extend->command_mode & BSC_SDRAM_PRV_SDCR_BACTV_VALUE_MASK) << R_BSC_SDCR_BACTV_Pos |
                    0U << R_BSC_SDCR_RMODE_Pos | /* Refresh operation : Auto-Refresh */
                    R_BSC_SDCR_RFSH_Msk;         /* Refresh operation : Enable */

    if (BSC_SDRAM_CHIP_SELECT_2_3 == p_cfg_extend->chip_select)
    {
        /* Set SDRAM control setting for CS2. */
        bsc_sdram_cs2_settings_t const * p_cs2_cfg = p_cfg_extend->p_cs2_cfg;
        sdcr |= (p_cs2_cfg->column_address_width & BSC_SDRAM_PRV_SDCR_A2COL_VALUE_MASK) << R_BSC_SDCR_A2COL_Pos |
                ((p_cs2_cfg->row_address_width - 3U) & BSC_SDRAM_PRV_SDCR_A2ROW_VALUE_MASK) << R_BSC_SDCR_A2ROW_Pos;
    }

    /* Set SDRAM control setting. For setting RTCSR.RRC bit
     * Refresh count = 1 time  -> RTCSR.RRC = 0
     * Refresh count = 2 times -> RTCSR.RRC = 1
     * Refresh count = 4 times -> RTCSR.RRC = 2
     * Refresh count = 6 times -> RTCSR.RRC = 3
     * Refresh count = 8 times -> RTCSR.RRC = 4 */
    uint32_t rrc = p_cfg->refresh_request_count >> 1;

    uint32_t rtcsr = (rrc & BSC_SDRAM_PRV_RTCSR_RRC_VALUE_MASK << BSC_SDRAM_PRV_RTCSR_RRC_Pos) |
                     ((cks_value_lut[p_cfg->source_div] & BSC_SDRAM_PRV_RTCSR_CKS_VALUE_MASK) <<
                      BSC_SDRAM_PRV_RTCSR_CKS_Pos) |
                     BSC_SDRAM_PRV_RTCSR_CMIE_Msk;

    if (BSC_SDRAM_CHIP_SELECT_2_3 != p_cfg_extend->chip_select)
    {
        R_BSC->CSnBCR[p_cfg_extend->chip_select] = csnbcr;
    }
    else                               /* BSC_SDRAM_CHIP_SELECT_2_3 */
    {
        /* Set CS2 and CS3 bus access idle cycle. */
        bsc_sdram_cs2_settings_t const * p_cs2_cfg = p_cfg_extend->p_cs2_cfg;
        uint32_t cs2bcr = (((p_cs2_cfg->data_width & BSC_SDRAM_PRV_CSNBCR_BSZ_VALUE_MASK) << R_BSC_CSnBCR_BSZ_Pos) |
                           1U << BSC_SDRAM_PRV_CSNBCR_RESERVED_Pos |
                           (BSC_SDRAM_PRV_CSNBCR_TYPE_SDRAM << R_BSC_CSnBCR_TYPE_Pos) |
                           ((p_cs2_cfg->r_r_same_space_idle_cycle & BSC_SDRAM_PRV_CSNBCR_IWRRS_VALUE_MASK) <<
                            R_BSC_CSnBCR_IWRRS_Pos) |
                           ((p_cs2_cfg->r_r_different_space_idle_cycle & BSC_SDRAM_PRV_CSNBCR_IWRRD_VALUE_MASK) <<
                            R_BSC_CSnBCR_IWRRD_Pos) |
                           ((p_cs2_cfg->r_w_same_space_idle_cycle & BSC_SDRAM_PRV_CSNBCR_IWRWS_VALUE_MASK) <<
                            R_BSC_CSnBCR_IWRWS_Pos) |
                           ((p_cs2_cfg->r_w_different_space_idle_cycle & BSC_SDRAM_PRV_CSNBCR_IWRWD_VALUE_MASK) <<
                            R_BSC_CSnBCR_IWRWD_Pos) |
                           ((p_cs2_cfg->w_r_w_w_idle_cycle & BSC_SDRAM_PRV_CSNBCR_IWW_VALUE_MASK) <<
                            R_BSC_CSnBCR_IWW_Pos));
        uint32_t cs3bcr = csnbcr;
        R_BSC->CSnBCR[2] = cs2bcr;
        R_BSC->CSnBCR[3] = cs3bcr;
    }

    R_BSC->SDCR  = sdcr;
    R_BSC->RTCNT = BSC_SDRAM_PROTECT_KEY | 0x00U;
    R_BSC->RTCOR = BSC_SDRAM_PROTECT_KEY | p_cfg->auto_refresh_cycle;
    R_BSC->RTCSR = BSC_SDRAM_PROTECT_KEY | rtcsr;

    if (BSC_SDRAM_CHIP_SELECT_2_3 != p_cfg_extend->chip_select)
    {
        *p_csnwcr = csnwcr;
    }
    else                               /* BSC_SDRAM_CHIP_SELECT_2_3 */
    {
        uint32_t cs2wcr =
            ((p_cfg_extend->p_cs2_cfg->cas_latency - 1U) & BSC_SDRAM_PRV_CSNWCR_A2CL_VALUE_MASK) <<
                R_BSC_CS2WCR_1_A2CL_Pos;
        uint32_t cs3wcr = csnwcr;
        R_BSC->CS2WCR_1 = cs2wcr | BSC_SDRAM_PRB_CS2WCR_10BIT_MASK;
        R_BSC->CS3WCR_1 = cs3wcr;
    }

    /* Set SDRAM Mode Register (MRS) */
    uint32_t mrs = (BSC_SDRAM_MRS_BUTST_LENGTH_1 << BSC_SDRAM_MRS_BURST_LENGTH_Pos) |
                   (BSC_SDRAM_MRS_WRAP_SEQUENTIAL << BSC_SDRAM_MRS_WRAP_MODE_Pos) |
                   ((p_cfg->cas_latency & BSC_SDRAM_MRS_LTMODE_VALUE_MASK) << BSC_SDRAM_MRS_LTMODE_Pos) |
                   ((p_cfg->write_burst_mode & BSC_SDRAM_MRS_WRITE_MODE_VALUE_MASK) << BSC_SDRAM_MRS_WRITE_MODE_Pos);

    /* The MRS setting value is written to the SDRAM by performing a 16-bit write to particular address.
     * (see RZ microprocessor Hardware Manual section "Power-On sequence" of "SDRAM Interface") */
    uint32_t mrs_setting_addr = BSC_SDRAM_MRS_CS3_ACCESS_ADDRESS_BASE | (mrs << (p_cfg->data_width - 1));
    *(volatile uint16_t *) mrs_setting_addr = BSC_SDRAM_MRS_SETTING_DUMMY_DATA;
    __asm volatile ("dsb");

    if (BSC_SDRAM_CHIP_SELECT_2_3 == p_cfg_extend->chip_select)
    {
        mrs = (BSC_SDRAM_MRS_BUTST_LENGTH_1 << BSC_SDRAM_MRS_BURST_LENGTH_Pos) |
              (BSC_SDRAM_MRS_WRAP_SEQUENTIAL << BSC_SDRAM_MRS_WRAP_MODE_Pos) |
              ((p_cfg_extend->p_cs2_cfg->cas_latency & BSC_SDRAM_MRS_LTMODE_VALUE_MASK) << BSC_SDRAM_MRS_LTMODE_Pos) |
              ((p_cfg->write_burst_mode & BSC_SDRAM_MRS_WRITE_MODE_VALUE_MASK) << BSC_SDRAM_MRS_WRITE_MODE_Pos);

        /* The MRS setting value is written to the SDRAM connected to CS2. */
        mrs_setting_addr = BSC_SDRAM_MRS_CS2_ACCESS_ADDRESS_BASE | (mrs << (p_cfg_extend->p_cs2_cfg->data_width - 1));
        *(volatile uint16_t *) mrs_setting_addr = BSC_SDRAM_MRS_SETTING_DUMMY_DATA;
        __asm volatile ("dsb");
    }

    /* Set callback and context pointers */
    p_instance_ctrl->p_callback = p_cfg_extend->p_callback;
    p_instance_ctrl->p_context  = p_cfg_extend->p_context;

    /* Enable CPU interrupts. */
    if (p_cfg_extend->cmi_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_cfg_extend->cmi_irq, p_cfg_extend->cmi_ipl, p_instance_ctrl);
    }

    p_instance_ctrl->open = BSC_SDRAM_PRV_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enters Self-Refresh mode.
 *
 * Implements @ref sdram_api_t::selfRefreshEnter.
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_INVALID_MODE        This function can't be called when SDRAM is in Power-down mode.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_BSC_SDRAM_SelfRefreshEnter (sdram_ctrl_t * p_ctrl)
{
    bsc_sdram_instance_ctrl_t * p_instance_ctrl = (bsc_sdram_instance_ctrl_t *) p_ctrl;
#if BSC_SDRAM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(BSC_SDRAM_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    /* Do not enter Self-Refresh mode from Power-Down mode. */
    FSP_ERROR_RETURN(0U == R_BSC->SDCR_b.PDOWN, FSP_ERR_INVALID_MODE);
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
#endif

    /* Enter Self-Refresh operation by setting both the RMODE bit and the RFSH bit in SDCR to 1.
     * (see RZ microprocessor Hardware Manual section "Refreshing" of "SDRAM Interface") */
    R_BSC->SDCR |= (R_BSC_SDCR_RMODE_Msk | R_BSC_SDCR_RFSH_Msk);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Exits Self-Refresh mode. Auto-Refresh operation is re-started to the SDRAM.
 *
 * Implements @ref sdram_api_t::selfRefreshExit.
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_BSC_SDRAM_SelfRefreshExit (sdram_ctrl_t * p_ctrl)
{
    bsc_sdram_instance_ctrl_t * p_instance_ctrl = (bsc_sdram_instance_ctrl_t *) p_ctrl;
#if BSC_SDRAM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(BSC_SDRAM_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
#endif

    /* Auto-Refresh is started if the RFSH bit is set to 1 and the RMODE bit is cleared to 0.
     * (see RZ microprocessor Hardware Manual section "Refreshing" of "SDRAM Interface") */
    uint32_t sdcr = R_BSC->SDCR;
    sdcr       &= ~R_BSC_SDCR_RMODE_Msk;
    sdcr       |= R_BSC_SDCR_RFSH_Msk;
    R_BSC->SDCR = sdcr;

    /* Making the RTCNT value 1 less than the RTCOR value will enable refreshing to be started immediately.
     * (see RZ microprocessor Hardware Manual section "Refreshing" of "SDRAM Interface") */
    uint32_t rtcor = R_BSC->RTCOR;
    R_BSC->RTCNT = BSC_SDRAM_PROTECT_KEY | (rtcor - 1);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enters Power-Down mode.
 *
 * Implements @ref sdram_api_t::powerDownEnter.
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_INVALID_MODE        This function can't be called when SDRAM is in Self-Refresh mode.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_BSC_SDRAM_PowerDownEnter (sdram_ctrl_t * p_ctrl)
{
    bsc_sdram_instance_ctrl_t * p_instance_ctrl = (bsc_sdram_instance_ctrl_t *) p_ctrl;
#if BSC_SDRAM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(BSC_SDRAM_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    /* Do not enter Power-Down mode from Self-Refresh mode. */
    FSP_ERROR_RETURN(0U == R_BSC->SDCR_b.RMODE, FSP_ERR_INVALID_MODE);
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
#endif

    /* The PDOWN bit in SDCR is set to 1 to enter the SDRAM power-down mode. */
    R_BSC->SDCR |= R_BSC_SDCR_PDOWN_Msk;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Exits Power-Down mode.
 *
 * Implements @ref sdram_api_t::powerDownExit.
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_BSC_SDRAM_PowerDownExit (sdram_ctrl_t * p_ctrl)
{
    bsc_sdram_instance_ctrl_t * p_instance_ctrl = (bsc_sdram_instance_ctrl_t *) p_ctrl;
#if BSC_SDRAM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(BSC_SDRAM_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
#endif

    FSP_PARAMETER_NOT_USED(p_instance_ctrl);

    /* The PDOWN bit in SDCR is set to 0 to exit the SDRAM Power-Down mode. */
    R_BSC->SDCR &= ~R_BSC_SDCR_PDOWN_Msk;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Close the BSC_SDRAM driver module.
 *
 * Implements @ref sdram_api_t::close.
 *
 * @retval FSP_SUCCESS             Configuration was successful.
 * @retval FSP_ERR_ASSERTION       p_instance_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN        Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_BSC_SDRAM_Close (sdram_ctrl_t * p_ctrl)
{
    bsc_sdram_instance_ctrl_t * p_instance_ctrl = (bsc_sdram_instance_ctrl_t *) p_ctrl;
#if BSC_SDRAM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(BSC_SDRAM_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    bsc_sdram_extended_cfg_t * p_cfg_extend = (bsc_sdram_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* Disable CPU interrupts. */
    if (p_cfg_extend->cmi_irq >= 0)
    {
        R_BSP_IrqDisable(p_cfg_extend->cmi_irq);
        R_FSP_IsrContextSet(p_cfg_extend->cmi_irq, NULL);
    }

    /* Disable clock to the BSC block */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_STOP(FSP_IP_BSC, BSC_SDRAM_CHANNEL_DUMMY);
    R_BSP_MODULE_STOP(FSP_IP_CKIO, BSC_SDRAM_CHANNEL_DUMMY);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup BSC_SDRAM)
 **********************************************************************************************************************/
#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

#if BSC_SDRAM_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Parameter checking for R_BSC_SDRAM_Open.
 *
 * @param[in] p_instance_ctrl          Pointer to instance control structure.
 * @param[in] p_cfg                    Configuration structure for this instance
 *
 * @retval FSP_SUCCESS                 Initialization was successful and timer has started.
 * @retval FSP_ERR_ASSERTION           A required input pointer is NULL.
 * @retval FSP_ERR_ALREADY_OPEN        R_BSC_SDRAM_Open has already been called for this p_ctrl.
 * @retval FSP_ERR_INVALID_ARGUMENT    SDRAM parameter is not available on BSC.
 * @retval FSP_ERR_INVALID_CHANNEL     Invalid Channel.
 **********************************************************************************************************************/
static fsp_err_t r_bsc_sdram_open_param_checking (bsc_sdram_instance_ctrl_t * p_instance_ctrl,
                                                  sdram_cfg_t const * const   p_cfg)
{
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(BSC_SDRAM_PRV_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);

    /* Validate period parameter. */
    FSP_ERROR_RETURN(p_cfg->auto_refresh_cycle < UINT8_MAX, FSP_ERR_INVALID_ARGUMENT);

    /* Validate number of bits of Row/Column Address. */
    FSP_ERROR_RETURN((SDRAM_ADDRESS_BUS_WIDTH_11_BITS <= p_cfg->row_address_width), FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN((p_cfg->row_address_width <= SDRAM_ADDRESS_BUS_WIDTH_13_BITS), FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN((p_cfg->column_address_width <= SDRAM_ADDRESS_BUS_WIDTH_10_BITS), FSP_ERR_INVALID_ARGUMENT);

    /* Validate divider. */
    FSP_ERROR_RETURN(SDRAM_REFRESH_CYCLE_SOURCE_DIV_1 != p_cfg->source_div, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(SDRAM_REFRESH_CYCLE_SOURCE_DIV_2 != p_cfg->source_div, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(SDRAM_REFRESH_CYCLE_SOURCE_DIV_8 != p_cfg->source_div, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(SDRAM_REFRESH_CYCLE_SOURCE_DIV_32 != p_cfg->source_div, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(SDRAM_REFRESH_CYCLE_SOURCE_DIV_128 != p_cfg->source_div, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(SDRAM_REFRESH_CYCLE_SOURCE_DIV_512 != p_cfg->source_div, FSP_ERR_INVALID_ARGUMENT);

    /* Validate timing parameters. */
    FSP_ERROR_RETURN(p_cfg->ras_precharge_cycle <= 3, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_cfg->ras_to_cas_delay_cycle <= 3, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_cfg->write_recovery_cycle <= 3, FSP_ERR_INVALID_ARGUMENT);

    FSP_ERROR_RETURN(p_cfg->cas_latency != 0, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_cfg->cas_latency <= 4, FSP_ERR_INVALID_ARGUMENT);

    FSP_ERROR_RETURN(((2 == p_cfg->row_cycle) || (3 == p_cfg->row_cycle) ||
                      (5 == p_cfg->row_cycle) || (8 == p_cfg->row_cycle)),
                     FSP_ERR_INVALID_ARGUMENT);

    /* Validate refresh count. */
    FSP_ERROR_RETURN(((1 == p_cfg->refresh_request_count) || (2 == p_cfg->refresh_request_count) ||
                      (4 == p_cfg->refresh_request_count) ||
                      (6 == p_cfg->refresh_request_count) || (8 == p_cfg->refresh_request_count)),
                     FSP_ERR_INVALID_ARGUMENT);

    bsc_sdram_extended_cfg_t * p_cfg_extend = (bsc_sdram_extended_cfg_t *) p_cfg->p_extend;

    /* Validate channel number. */
    FSP_ERROR_RETURN(BSC_SDRAM_VALID_CS_CHANNELS & (1U << p_cfg_extend->chip_select), FSP_ERR_INVALID_CHANNEL);

    if (BSC_SDRAM_CHIP_SELECT_2_3 == p_cfg_extend->chip_select)
    {
        FSP_ASSERT(NULL != p_cfg_extend->p_cs2_cfg);

        /* When areas 2 and 3 are both set to SDRAM, auto precharge mode must be set.
         *  (see RZ microprocessor Hardware Manual section "Bank Active" of "SDRAM Interface") */
        FSP_ERROR_RETURN(BSC_SDRAM_COMMAND_AUTO_PRECHARGE_MODE == p_cfg_extend->command_mode, FSP_ERR_INVALID_ARGUMENT);
    }

    return FSP_SUCCESS;
}

#endif

/*******************************************************************************************************************//**
 * BSC_CMI interrupt processing. When an CMI interrupt fires, the user callback function is called if it is
 * registered in R_BSC_SDRAM_Open() and clear interrupt flag.
 **********************************************************************************************************************/
void bsc_sdram_cmi_int_isr (void)
{
    BSC_SDRAM_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    bsc_sdram_instance_ctrl_t * p_instance_ctrl = (bsc_sdram_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Invoke the callback function if it is set. */
    if (NULL != p_instance_ctrl->p_callback)
    {
        /* Setup parameters for the user-supplied callback function. */
        bsc_sdram_callback_args_t callback_args;

        callback_args.p_context = p_instance_ctrl->p_context;

        p_instance_ctrl->p_callback(&callback_args);
    }

    /* Clear Compare Match Flag. */
    uint32_t rtcsr = R_BSC->RTCSR;
    rtcsr       &= ~BSC_SDRAM_PRV_RTCSR_CMF_Msk;
    R_BSC->RTCSR = BSC_SDRAM_PROTECT_KEY | rtcsr;

    /* Dummy read to ensure that interrupt event is cleared. */
    FSP_REGISTER_READ(R_BSC->RTCSR);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    BSC_SDRAM_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}
