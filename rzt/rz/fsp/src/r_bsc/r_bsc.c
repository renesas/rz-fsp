/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "bsp_api.h"

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_bsc.h"
#include "r_bsc_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSC_PRV_OPEN                               (0x425343)
#define BSC_CHANNEL_DUMMY                          (0x0U)

#define BSC_VALID_CS_CHANNELS                      (0x2D)       /* Valid channel : CS0,2,3,5 */
#define BSC_R_W_SAME_ACCESS_WAIT_CHANNELS          (0x0D)       /* Valid channel : CS0,2,3 */
#define BSC_CS_TIMING_CONFIGURE_ENABLE_CHANNELS    (0x21)       /* Valid channel : CS0,5 */

#define BSC_PRV_CSNBCR_RESERVED_BIT_MASK           (0x00000800) /* 11th bit of CSnBCR must be 1. */
#define BSC_PRV_CSNBCR_BSZ_VALUE_MASK              (0x03U)
#define BSC_PRV_CSNBCR_TYPE_VALUE_MASK             (0x07U)
#define BSC_PRV_CSNBCR_IWRRS_VALUE_MASK            (0x07U)
#define BSC_PRV_CSNBCR_IWRRD_VALUE_MASK            (0x07U)
#define BSC_PRV_CSNBCR_IWRWS_VALUE_MASK            (0x07U)
#define BSC_PRV_CSNBCR_IWRWD_VALUE_MASK            (0x07U)
#define BSC_PRV_CSNBCR_IWW_VALUE_MASK              (0x07U)

#define BSC_PRV_CSNWCR_HW_VALUE_MASK               (0x03U)
#define BSC_PRV_CSNWCR_SW_VALUE_MASK               (0x03U)
#define BSC_PRV_CSNWCR_WM_VALUE_MASK               (0x01U)
#define BSC_PRV_CSNWCR_WR_VALUE_MASK               (0x0FU)

#define BSC_PRV_CSNWCR_WW_VALUE_MASK               (0x07U)
#define BSC_PRV_CSNWCR_MPXWSBAS_VALUE_MASK         (0x01U)
#define BSC_PRV_CSNWCR_SZSEL_VALUE_MASK            (0x01U)

#define BSC_PRV_TOENR_CSNTOEN_VALUE_MASK           (0x01U)

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void r_bsc_call_callback(bsc_instance_ctrl_t * p_ctrl, bsc_event_t event);
void        bsc_wto_int_isr(uint32_t id);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
static volatile bsc_instance_ctrl_t * gp_ctrl[6] = {NULL};

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZT
{
#endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_BSC
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/
const external_bus_api_t g_external_bus_on_bsc =
{
    .open  = R_BSC_Open,
    .close = R_BSC_Close,
};

/*******************************************************************************************************************//**
 * Open the BSC driver module. After the driver is open, the BSC can be accessed like internal flash memory starting
 * at address 0x70000000 or 0x50000000.
 *
 * Implements @ref external_bus_api_t::open.
 *
 * @retval FSP_SUCCESS             Configuration was successful.
 * @retval FSP_ERR_ASSERTION       The parameter p_instance_ctrl or p_cfg is NULL.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT Invalid Channel.
 * @retval FSP_ERR_ALREADY_OPEN    Driver has already been opened with the same p_instance_ctrl.
 **********************************************************************************************************************/
fsp_err_t R_BSC_Open (external_bus_ctrl_t * p_ctrl, external_bus_cfg_t const * const p_cfg)
{
    bsc_instance_ctrl_t * p_instance_ctrl = (bsc_instance_ctrl_t *) p_ctrl;

#if BSC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(BSC_VALID_CS_CHANNELS & (1U << p_cfg->chip_select), FSP_ERR_IP_CHANNEL_NOT_PRESENT);
    FSP_ERROR_RETURN(BSC_PRV_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);

    /* The number of wait insertions for read and write access cannot be set individually.
     * This depends on the CS number. */
    if (BSC_R_W_SAME_ACCESS_WAIT_CHANNELS & (1U << p_cfg->chip_select))
    {
        FSP_ASSERT(BSC_ACCESS_WAIT_CYCLE_SAME_AS_READ_ACCESS ==
                   ((bsc_extended_cfg_t *) p_cfg->p_extend)->write_access_wait_cycle);
    }

    /* If wait insertion can be set individually for read and write,
     * the number of wait insertion for write access should be less than 6 wait or the same as read access waits. */
    if (!(BSC_R_W_SAME_ACCESS_WAIT_CHANNELS & (1U << p_cfg->chip_select)))
    {
        FSP_ASSERT((((bsc_extended_cfg_t *) p_cfg->p_extend)->write_access_wait_cycle <= BSC_ACCESS_WAIT_CYCLE_6) ||
                   ((bsc_extended_cfg_t *) p_cfg->p_extend)->write_access_wait_cycle ==
                   BSC_ACCESS_WAIT_CYCLE_SAME_AS_READ_ACCESS);
    }
#endif

    bsc_extended_cfg_t * p_cfg_extend = (bsc_extended_cfg_t *) p_cfg->p_extend;

    /* Enable clock to the BSC block */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_START(FSP_IP_BSC, BSC_CHANNEL_DUMMY);
    R_BSP_MODULE_START(FSP_IP_CKIO, BSC_CHANNEL_DUMMY);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    /* Save configurations. */
    p_instance_ctrl->p_cfg = p_cfg;

    /* Set callback and context pointers, if configured */
    p_instance_ctrl->p_callback        = p_cfg_extend->p_callback;
    p_instance_ctrl->p_context         = p_cfg_extend->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    /* Calculate the CSnWCR register base address. */
    uint32_t   address_gap = (uint32_t) ((uintptr_t) &R_BSC->CS3WCR_0 - (uintptr_t) &R_BSC->CS2WCR_0);
    uint32_t * p_csnwcr    = (uint32_t *) ((uintptr_t) &R_BSC->CS0WCR_0 + (address_gap * p_cfg->chip_select));

    /* Set bus access idle cycle. */
    uint32_t csnbcr = BSC_PRV_CSNBCR_RESERVED_BIT_MASK;
    csnbcr |= (((p_cfg->data_width & BSC_PRV_CSNBCR_BSZ_VALUE_MASK) << R_BSC_CSnBCR_BSZ_Pos) |
               ((p_cfg_extend->memory_type & BSC_PRV_CSNBCR_TYPE_VALUE_MASK) << R_BSC_CSnBCR_TYPE_Pos) |
               ((p_cfg_extend->r_r_same_space_idle_cycle & BSC_PRV_CSNBCR_IWRRS_VALUE_MASK) << R_BSC_CSnBCR_IWRRS_Pos) |
               ((p_cfg_extend->r_r_different_space_idle_cycle & BSC_PRV_CSNBCR_IWRRD_VALUE_MASK) <<
                R_BSC_CSnBCR_IWRRD_Pos) |
               ((p_cfg_extend->r_w_same_space_idle_cycle & BSC_PRV_CSNBCR_IWRWS_VALUE_MASK) << R_BSC_CSnBCR_IWRWS_Pos) |
               ((p_cfg_extend->r_w_different_space_idle_cycle & BSC_PRV_CSNBCR_IWRWD_VALUE_MASK) <<
                R_BSC_CSnBCR_IWRWD_Pos) |
               ((p_cfg_extend->w_r_w_w_idle_cycle & BSC_PRV_CSNBCR_IWW_VALUE_MASK) << R_BSC_CSnBCR_IWW_Pos));

    /* Set access wait cycle.
     * If the channel can be set read/write individually, set read access wait cycle here. */
    uint32_t csnwcr = (p_cfg_extend->read_access_wait_cycle & BSC_PRV_CSNWCR_WR_VALUE_MASK) << R_BSC_CS0WCR_0_WR_Pos;

    /* Set write access wait cycle if it can be set individually. */
    if (!((BSC_R_W_SAME_ACCESS_WAIT_CHANNELS) & (1U << p_cfg->chip_select)))
    {
        if (BSC_ACCESS_WAIT_CYCLE_SAME_AS_READ_ACCESS != p_cfg_extend->write_access_wait_cycle)
        {
            csnwcr |=
                (uint32_t) ((p_cfg_extend->write_access_wait_cycle & BSC_PRV_CSNWCR_WW_VALUE_MASK) + 1) <<
                    R_BSC_CS5WCR_WW_Pos;
        }
        else
        {
            /* Set 0 if set write access wait cycle to be the same as the read access wait cycle. */
            csnwcr &= ~(uint32_t) R_BSC_CS5WCR_WW_Msk;
        }
    }

    /* Set CS timing. */
    if (BSC_CS_TIMING_CONFIGURE_ENABLE_CHANNELS & (1U << p_cfg->chip_select))
    {
        csnwcr |= (((p_cfg_extend->cs_pullup_lag & BSC_PRV_CSNWCR_HW_VALUE_MASK) << R_BSC_CS0WCR_0_HW_Pos) |
                   ((p_cfg_extend->cs_pulldown_lead & BSC_PRV_CSNWCR_SW_VALUE_MASK) << R_BSC_CS0WCR_0_SW_Pos));
    }

    /* Set external wait setting. */
    csnwcr |= (p_cfg->external_wait_en & BSC_PRV_CSNWCR_WM_VALUE_MASK) << R_BSC_CS0WCR_0_WM_Pos;

    /* Set CSn Space Bus Control Register. */
    R_BSC->CSnBCR[p_cfg->chip_select] = csnbcr;

    /* Set CSn Space Wait Control Register. */
    *p_csnwcr = csnwcr;

    /* Set Timeout Cycle Constant Register.
     * If user sets the timeout count to 65536, a cast with (uint16_t) store 0 in the TOSCOR register. */
    R_BSC->TOSCOR[p_cfg->chip_select] = (uint16_t) p_cfg_extend->external_wait_timeout_counts;

    /* Set Timeout Enable Register. */
    R_BSC->TOENR |= (p_cfg_extend->external_wait_timeout_enable & BSC_PRV_TOENR_CSNTOEN_VALUE_MASK) <<
                    (p_cfg->chip_select);

    /* Track ctrl struct */
    gp_ctrl[p_cfg->chip_select] = p_ctrl;

    p_instance_ctrl->open = BSC_PRV_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Close the BSC driver module.
 *
 * Implements @ref external_bus_api_t::close.
 *
 * @retval FSP_SUCCESS             Configuration was successful.
 * @retval FSP_ERR_ASSERTION       p_instance_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN        Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_BSC_Close (external_bus_ctrl_t * p_ctrl)
{
    bsc_instance_ctrl_t * p_instance_ctrl = (bsc_instance_ctrl_t *) p_ctrl;
#if BSC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(BSC_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Disable clock to the BSC block */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_STOP(FSP_IP_BSC, BSC_CHANNEL_DUMMY);
    R_BSP_MODULE_STOP(FSP_IP_CKIO, BSC_CHANNEL_DUMMY);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_BSC_CallbackSet (external_bus_ctrl_t       * p_ctrl,
                             void (                    * p_callback)(bsc_callback_args_t *),
                             void * const                p_context,
                             bsc_callback_args_t * const p_callback_memory)
{
    bsc_instance_ctrl_t * p_instance_ctrl = (bsc_instance_ctrl_t *) p_ctrl;

#if BSC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(BSC_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */
    p_instance_ctrl->p_callback        = p_callback;
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup BSC)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_ctrl     Pointer to BSC instance control block
 * @param[in]     event      Event code
 **********************************************************************************************************************/
static void r_bsc_call_callback (bsc_instance_ctrl_t * p_ctrl, bsc_event_t event)
{
    bsc_callback_args_t args;

    /* Store callback arguments in memory provided by user if available. */
    bsc_callback_args_t * p_args = p_ctrl->p_callback_memory;
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

    p_args->event     = event;
    p_args->p_context = p_ctrl->p_context;

    p_ctrl->p_callback(p_args);

    if (NULL != p_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_ctrl->p_callback_memory = args;
    }
}

/*******************************************************************************************************************//**
 * BSC ISR
 **********************************************************************************************************************/
void bsc_wto_int_isr (uint32_t id)
{
    BSC_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    FSP_PARAMETER_NOT_USED(id);

    uint32_t tostr    = R_BSC->TOSTR;
    uint32_t error_cs = 0;
    while (tostr)
    {
        /* Scan and search for error CS channel one by one */
        uint32_t next_tostr = __CLZ(__RBIT(tostr));
        tostr   >>= next_tostr;
        error_cs += next_tostr;

        bsc_instance_ctrl_t * p_ctrl = (bsc_instance_ctrl_t *) gp_ctrl[error_cs];

        /* Call user registered callback */
        if (NULL != p_ctrl)
        {
            if (NULL != p_ctrl->p_callback)
            {
                r_bsc_call_callback(p_ctrl, BSC_EVENT_EXTERNAL_WAIT_TIMEOUT);
            }

            /* Clear TOSTR register. */
            R_BSC->TOSTR &= ~(1U << p_ctrl->p_cfg->chip_select);
        }

        /* Clear the scanned flags one by one */
        tostr &= ~(uint32_t) (1UL);
    }

    BSC_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}
