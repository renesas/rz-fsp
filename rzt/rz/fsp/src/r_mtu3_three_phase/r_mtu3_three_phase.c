/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_mtu3_cfg.h"
#include "r_mtu3_three_phase_cfg.h"

#include "r_mtu3.h"
#include "r_mtu3_three_phase.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "MT3P" in ASCII, used to determine if channel is open. */
#define MTU3_THREE_PHASE_OPEN             (0x4D543350ULL)

#define MTU3_THREE_CH1ST                  (0U)
#define MTU3_THREE_CH2ND                  (1U)
#define MTU3_THREE_USE_CHNG               (0U)
#define MTU3_THREE_USE_CHA                (3U)
#define MTU3_THREE_USE_CHB                (6U)
#define MTU3_THREE_TRWER_PROTECT          (0U)
#define MTU3_THREE_TRWER_ACCESS           (1U)
#define MTU3_THREE_NO_DEADTIME            (0U)
#define MTU3_THREE_CHU0                   (0U)
#define MTU3_THREE_CHV1                   (1U)
#define MTU3_THREE_CHW2                   (2U)
#define MTU3_THREE_TMDR1_PWM_MODE1        (0x0DU)
#define MTU3_THREE_TMDR1_PWM_MODE2        (0x0EU)
#define MTU3_THREE_TMDR1_PWM_MODE3        (0x0FU)
#define MTU3_THREE_TOER_ALL               (0x3FU)
#define MTU3_THREE_TCR_SYNCHRONOUS_CLR    R_MTU3_TCR_CCLR_Msk

/* mtu3 common XXXB registers offset address */
#define MTU3_THREE_BREG_OFFSET            (0x800U)

/* offset address : TCNT */
#define MTU36_TCNT_OFFSET_ADDRESS         (0x0110U)
#define MTU47_TCNT_OFFSET_ADDRESS         (0x0012U)

/* offset address : TGRx */
#define MTU36_TGRA_OFFSET_ADDRESS         (0x0118U)
#define MTU36_TGRB_OFFSET_ADDRESS         (0x011AU)
#define MTU36_TGRC_OFFSET_ADDRESS         (0x0124U)
#define MTU36_TGRD_OFFSET_ADDRESS         (0x0126U)
#define MTU36_TGRE_OFFSET_ADDRESS         (0x0172U)

#define MTU47_TGRA_OFFSET_ADDRESS         (0x001CU)
#define MTU47_TGRB_OFFSET_ADDRESS         (0x001EU)
#define MTU47_TGRC_OFFSET_ADDRESS         (0x0028U)
#define MTU47_TGRD_OFFSET_ADDRESS         (0x002AU)
#define MTU47_TGRE_OFFSET_ADDRESS         (0x0074U)
#define MTU47_TGRF_OFFSET_ADDRESS         (0x0076U)

/* offset address : TMDR1, TIORH/L, TIER, TCR */
#define MTU36_TMDR1_OFFSET_ADDRESS        (0x0102U)
#define MTU47_TMDR1_OFFSET_ADDRESS        (0x0003U)
#define MTU36_TIORH_OFFSET_ADDRESS        (0x0104U)
#define MTU36_TIORL_OFFSET_ADDRESS        (0x0105U)
#define MTU47_TIORH_OFFSET_ADDRESS        (0x0006U)
#define MTU47_TIORL_OFFSET_ADDRESS        (0x0007U)
#define MTU36_TIER_OFFSET_ADDRESS         (0x0108U)
#define MTU47_TIER_OFFSET_ADDRESS         (0x0009U)
#define MTU36_TCR_OFFSET_ADDRESS          (0x0100U)
#define MTU47_TCR_OFFSET_ADDRESS          (0x0001U)

#define MTU3_THREE_TGR_MAX                (0xFFFFUL)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static uint32_t    r_mtu3_three_phase_check_ch(three_phase_cfg_t const * const p_cfg);
static fsp_err_t   r_mtu3_three_phase_regset(mtu3_three_phase_instance_ctrl_t * p_instance_ctrl, void const * p_extend);
static inline void r_mtu3_three_phase_write_protect_enable(mtu3_three_phase_instance_ctrl_t * const p_instance_ctrl);
static inline void r_mtu3_three_phase_write_protect_disable(mtu3_three_phase_instance_ctrl_t * const p_instance_ctrl);

/***********************************************************************************************************************
 * ISR prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

static const uint8_t tmdr1_md[3] =
{
    R_MTU3_TMDR1_BFA_Msk | R_MTU3_TMDR1_BFB_Msk | MTU3_THREE_TMDR1_PWM_MODE1,
    R_MTU3_TMDR1_BFA_Msk | R_MTU3_TMDR1_BFB_Msk | MTU3_THREE_TMDR1_PWM_MODE2,
    R_MTU3_TMDR1_BFA_Msk | R_MTU3_TMDR1_BFB_Msk | MTU3_THREE_TMDR1_PWM_MODE3
};
static const uint8_t tsyra_clr_ch[8] =
{
    0,                                 /* Disabled */
    R_MTU_TSYRA_SYNC0_Msk,             /* Select MTU0 ch */
    R_MTU_TSYRA_SYNC1_Msk,             /* Select MTU1 ch */
    R_MTU_TSYRA_SYNC2_Msk,             /* Select MTU2 ch */
    R_MTU_TSYRA_SYNC3_Msk,             /* Select MTU3 ch */
    R_MTU_TSYRA_SYNC4_Msk,             /* Select MTU4 ch */
    R_MTU_TSYRB_SYNC6_Msk,             /* Select MTU6 ch */
    R_MTU_TSYRB_SYNC7_Msk              /* Select MTU7 ch */
};

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/* Implementation of MTU3_THREE_PHASE interface  */
const three_phase_api_t g_three_phase_on_mtu3_three_phase =
{
    .open         = R_MTU3_THREE_PHASE_Open,
    .stop         = R_MTU3_THREE_PHASE_Stop,
    .start        = R_MTU3_THREE_PHASE_Start,
    .reset        = R_MTU3_THREE_PHASE_Reset,
    .dutyCycleSet = R_MTU3_THREE_PHASE_DutyCycleSet,
    .callbackSet  = R_MTU3_THREE_PHASE_CallbackSet,
    .close        = R_MTU3_THREE_PHASE_Close,
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZT
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_MTU3_THREE_PHASE
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initializes the 3-phase timer module (and associated timers) and applies configurations. Implements
 * @ref three_phase_api_t::open.
 *
 * @retval FSP_SUCCESS                    Initialization was successful.
 * @retval FSP_ERR_ASSERTION              A required input pointer is NULL.
 * @retval FSP_ERR_ALREADY_OPEN           Module is already open.
 * @retval FSP_ERR_INVALID_CHANNEL        The requested channel is out of range.
 * @retval FSP_ERR_INVALID_ARGUMENT       Period count is out of range.
 *                                        The sum of period count values and dead time is out of range.
 *                                        When ch3 is specified, set ch3 and ch4 in the "Timer Synchronous Register" setting.
 *                                        When ch6 is specified, set ch6 and ch7 in the "Timer Synchronous Register" setting.
 **********************************************************************************************************************/
fsp_err_t R_MTU3_THREE_PHASE_Open (three_phase_ctrl_t * const p_ctrl, three_phase_cfg_t const * const p_cfg)
{
    mtu3_three_phase_instance_ctrl_t * p_instance_ctrl = (mtu3_three_phase_instance_ctrl_t *) p_ctrl;
#if MTU3_THREE_PHASE_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(MTU3_THREE_PHASE_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    /* Get copy of channel : MTU3 or MTU6 */
    p_instance_ctrl->channel = r_mtu3_three_phase_check_ch(p_cfg);
#if MTU3_THREE_PHASE_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN((MTU3_THREE_USE_CHNG != p_instance_ctrl->channel), FSP_ERR_INVALID_CHANNEL);
#endif

    if (MTU3_THREE_USE_CHA == p_instance_ctrl->channel)
    {
        p_instance_ctrl->p_reg_com = (R_MTU_Type *) R_MTU_BASE;                            /* set Base address of common ch MTU3/4 */
    }
    else
    {
        p_instance_ctrl->p_reg_com = (R_MTU_Type *) (R_MTU_BASE + MTU3_THREE_BREG_OFFSET); /* set Base address of common ch MYU6/7 */
    }

    r_mtu3_three_phase_write_protect_disable(p_instance_ctrl);                             /* Enable Read/Write Registers */

    /* Open MTU3 Complementary PWM Mode ch : MTU3/4 or MTU6/7 */
    fsp_err_t err;
    err = R_MTU3_Open(p_cfg->p_timer_instance[MTU3_THREE_CH1ST]->p_ctrl,
                      p_cfg->p_timer_instance[MTU3_THREE_CH1ST]->p_cfg);
    if (FSP_SUCCESS == err)
    {
        err = R_MTU3_Open(p_cfg->p_timer_instance[MTU3_THREE_CH2ND]->p_ctrl,
                          p_cfg->p_timer_instance[MTU3_THREE_CH2ND]->p_cfg);
        if (FSP_SUCCESS != err)
        {
            R_MTU3_Close(p_cfg->p_timer_instance[MTU3_THREE_CH1ST]->p_ctrl);
        }
    }

#if MTU3_CFG_PARAM_CHECKING_ENABLE
    if (err)
    {
        return err;
    }

#else
    FSP_PARAMETER_NOT_USED(err);
#endif

    /* Save a pointer to the MTU3 registers for this channel */
    if (p_instance_ctrl->channel == p_cfg->p_timer_instance[MTU3_THREE_CH1ST]->p_cfg->channel)
    {
        p_instance_ctrl->p_reg[MTU3_THREE_CH1ST] =
            ((mtu3_instance_ctrl_t *) (p_cfg->p_timer_instance[MTU3_THREE_CH1ST]->p_ctrl))->p_reg;
        p_instance_ctrl->p_reg[MTU3_THREE_CH2ND] =
            ((mtu3_instance_ctrl_t *) (p_cfg->p_timer_instance[MTU3_THREE_CH2ND]->p_ctrl))->p_reg;
    }
    else
    {
        p_instance_ctrl->p_reg[MTU3_THREE_CH1ST] =
            ((mtu3_instance_ctrl_t *) (p_cfg->p_timer_instance[MTU3_THREE_CH2ND]->p_ctrl))->p_reg;
        p_instance_ctrl->p_reg[MTU3_THREE_CH2ND] =
            ((mtu3_instance_ctrl_t *) (p_cfg->p_timer_instance[MTU3_THREE_CH1ST]->p_ctrl))->p_reg;
    }

    /* Get copy of MTU3 buffer mode */
    p_instance_ctrl->buffer_mode = p_cfg->buffer_mode;

    /* Save pointer to config struct */
    p_instance_ctrl->p_cfg = p_cfg;

    err = r_mtu3_three_phase_regset(p_instance_ctrl, p_cfg->p_extend);

#ifdef MTU3_THREE_PHASE_CFG_PARAM_CHECKING_ENABLE
    if (err)
    {
        R_MTU3_Close(p_cfg->p_timer_instance[MTU3_THREE_CH1ST]->p_ctrl);
        R_MTU3_Close(p_cfg->p_timer_instance[MTU3_THREE_CH2ND]->p_ctrl);

        return err;
    }

#else
    FSP_PARAMETER_NOT_USED(err);
#endif

    r_mtu3_three_phase_write_protect_enable(p_instance_ctrl); /* Disanable Read/Write Registers */

    p_instance_ctrl->open = MTU3_THREE_PHASE_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stops all timers synchronously. Implements @ref three_phase_api_t::stop.
 *
 * @retval FSP_SUCCESS                 Timers successfully stopped.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_MTU3_THREE_PHASE_Stop (three_phase_ctrl_t * const p_ctrl)
{
    mtu3_three_phase_instance_ctrl_t * p_instance_ctrl = (mtu3_three_phase_instance_ctrl_t *) p_ctrl;
#if MTU3_THREE_PHASE_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(MTU3_THREE_PHASE_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    r_mtu3_three_phase_write_protect_disable(p_instance_ctrl);                                     /* Enable Read/Write Registers */

    /* When setting MTU6, "TSYRA" is used because the address of "MTU3_THREE_BREG_OFFSET" is added to p_reg_com at the time of "open". */
    p_instance_ctrl->p_reg_com->TSTRA &= (uint8_t) ~(R_MTU_TSTRA_CST3_Msk | R_MTU_TSTRA_CST4_Msk); /* Stop timer MTU3/4 or MTU6/7 */
    p_instance_ctrl->p_reg_com->TOERA &= (uint8_t) ~MTU3_THREE_TOER_ALL;                           /* output is disabled (non-active level) */

    r_mtu3_three_phase_write_protect_enable(p_instance_ctrl);                                      /* Disanable Read/Write Registers */

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Starts all timers synchronously. Implements @ref three_phase_api_t::start.
 *
 * @retval FSP_SUCCESS                 Timers successfully started.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_MTU3_THREE_PHASE_Start (three_phase_ctrl_t * const p_ctrl)
{
    mtu3_three_phase_instance_ctrl_t * p_instance_ctrl = (mtu3_three_phase_instance_ctrl_t *) p_ctrl;
#if MTU3_THREE_PHASE_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(MTU3_THREE_PHASE_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    r_mtu3_three_phase_write_protect_disable(p_instance_ctrl); /* Enable Read/Write Registers */

    /* Start timer */
    *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH1ST] + MTU36_TCNT_OFFSET_ADDRESS) = 0U;
    *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH2ND] + MTU47_TCNT_OFFSET_ADDRESS) = 0U;

    /* When setting MTU6, "TSYRA" is used because the address of "MTU3_THREE_BREG_OFFSET" is added to p_reg_com at the time of "open". */
    p_instance_ctrl->p_reg_com->TOERA |= MTU3_THREE_TOER_ALL;                           /* MTU output is enabled; */
    p_instance_ctrl->p_reg_com->TSTRA |= (R_MTU_TSTRA_CST3_Msk | R_MTU_TSTRA_CST4_Msk); /* Start timer MTU3/4 or MTU6/7 */

    r_mtu3_three_phase_write_protect_enable(p_instance_ctrl);                           /* Disanable Read/Write Registers */

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Resets the counter values to 0. Implements @ref three_phase_api_t::reset.
 *
 * @retval FSP_SUCCESS                 Counters were reset successfully.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_MTU3_THREE_PHASE_Reset (three_phase_ctrl_t * const p_ctrl)
{
    mtu3_three_phase_instance_ctrl_t * p_instance_ctrl = (mtu3_three_phase_instance_ctrl_t *) p_ctrl;
#if MTU3_THREE_PHASE_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(MTU3_THREE_PHASE_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    r_mtu3_three_phase_write_protect_disable(p_instance_ctrl); /* Enable Read/Write Registers */

    /* Set whether the timer is running or stopped */
    /* When setting MTU6, "TSYRA" is used because the address of "MTU3_THREE_BREG_OFFSET" is added to p_reg_com at the time of "open". */
    uint8_t tstr = p_instance_ctrl->p_reg_com->TSTRA & (R_MTU_TSTRA_CST3_Msk | R_MTU_TSTRA_CST4_Msk);

    /* Stop timer & initial output level */
    p_instance_ctrl->p_reg_com->TSTRA &= (uint8_t) ~(R_MTU_TSTRA_CST3_Msk | R_MTU_TSTRA_CST4_Msk); /* Stop timer MTU3/4 or MTU6/7 */
    p_instance_ctrl->p_reg_com->TOERA &= (uint8_t) ~MTU3_THREE_TOER_ALL;                           /* output is disabled (non-active level) */

    /* Restart timer */
    *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH1ST] + MTU36_TCNT_OFFSET_ADDRESS) = 0U;
    *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH2ND] + MTU47_TCNT_OFFSET_ADDRESS) = 0U;
    if (tstr != 0)                                                                          /* If timer is running then restart timer */
    {
        p_instance_ctrl->p_reg_com->TOERA |= MTU3_THREE_TOER_ALL;                           /* MTU output is enabled; */
        p_instance_ctrl->p_reg_com->TSTRA |= (R_MTU_TSTRA_CST3_Msk | R_MTU_TSTRA_CST4_Msk); /* Start timer MTU3/4 or MTU6/7 */
    }

    r_mtu3_three_phase_write_protect_enable(p_instance_ctrl);                               /* Disanable Read/Write Registers */

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Sets duty cycle for all three timers. Implements @ref three_phase_api_t::dutyCycleSet.
 *
 * In symmetric PWM mode duty cycle values are reflected after the next trough. In asymmetric PWM mode values are
 * reflected at the next trough OR crest, whichever comes first.
 *
 * When double-buffering is enabled the values in @ref three_phase_duty_cycle_t::duty_buffer are set to the
 * double-buffer registers. When values are reflected the first time the single buffer values
 * (@ref three_phase_duty_cycle_t::duty) are used. On the second reflection the duty_buffer values are used.
 * In asymmetric PWM mode this enables both count-up and count-down PWM values to be set at trough (or crest)
 * exclusively.
 *
 * @note It is recommended to call this function in a high-priority callback to ensure that it is not interrupted and
 * that no MTU3 events occur during setting that would result in a duty cycle buffer load operation.
 *
 * @retval FSP_SUCCESS                 Duty cycle updated successfully.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_MTU3_THREE_PHASE_DutyCycleSet (three_phase_ctrl_t * const       p_ctrl,
                                           three_phase_duty_cycle_t * const p_duty_cycle)
{
    mtu3_three_phase_instance_ctrl_t * p_instance_ctrl = (mtu3_three_phase_instance_ctrl_t *) p_ctrl;
#if MTU3_THREE_PHASE_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_duty_cycle);
    FSP_ERROR_RETURN(MTU3_THREE_PHASE_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Set double-buffer registers (if applicable) */
    if (THREE_PHASE_BUFFER_MODE_DOUBLE == p_instance_ctrl->buffer_mode)
    {
        *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH1ST] +
                                MTU36_TGRE_OFFSET_ADDRESS) = (uint16_t) p_duty_cycle->duty_buffer[MTU3_THREE_CHU0];
        *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH2ND] +
                                MTU47_TGRE_OFFSET_ADDRESS) = (uint16_t) p_duty_cycle->duty_buffer[MTU3_THREE_CHV1];
        *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH2ND] +
                                MTU47_TGRF_OFFSET_ADDRESS) = (uint16_t) p_duty_cycle->duty_buffer[MTU3_THREE_CHW2];
    }

    /* Set duty cycle registers */
    *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH1ST] +
                            MTU36_TGRD_OFFSET_ADDRESS) = (uint16_t) p_duty_cycle->duty[MTU3_THREE_CHU0];
    *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH2ND] +
                            MTU47_TGRC_OFFSET_ADDRESS) = (uint16_t) p_duty_cycle->duty[MTU3_THREE_CHV1];
    *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH2ND] +
                            MTU47_TGRD_OFFSET_ADDRESS) = (uint16_t) p_duty_cycle->duty[MTU3_THREE_CHW2];

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback for the MTU3 U-channel with the option to provide memory for the callback argument
 * structure.
 * Implements @ref three_phase_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_MTU3_THREE_PHASE_CallbackSet (three_phase_ctrl_t * const    p_ctrl,
                                          void (                      * p_callback)(timer_callback_args_t *),
                                          void * const                  p_context,
                                          timer_callback_args_t * const p_callback_memory)
{
    mtu3_three_phase_instance_ctrl_t * p_instance_ctrl = (mtu3_three_phase_instance_ctrl_t *) p_ctrl;

#if MTU3_THREE_PHASE_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_callback);
    FSP_ERROR_RETURN(MTU3_THREE_PHASE_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    R_MTU3_CallbackSet(p_instance_ctrl->p_cfg->p_timer_instance[MTU3_THREE_CH1ST]->p_ctrl,
                       p_callback,
                       p_context,
                       p_callback_memory);
    R_MTU3_CallbackSet(p_instance_ctrl->p_cfg->p_timer_instance[MTU3_THREE_CH2ND]->p_ctrl,
                       p_callback,
                       p_context,
                       p_callback_memory);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stops counters, disables output pins, and clears internal driver data. Implements @ref three_phase_api_t::close.
 *
 * @retval FSP_SUCCESS                 Successful close.
 * @retval FSP_ERR_ASSERTION           p_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance is not opened.
 **********************************************************************************************************************/
fsp_err_t R_MTU3_THREE_PHASE_Close (three_phase_ctrl_t * const p_ctrl)
{
    mtu3_three_phase_instance_ctrl_t * p_instance_ctrl = (mtu3_three_phase_instance_ctrl_t *) p_ctrl;

#if MTU3_THREE_PHASE_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(MTU3_THREE_PHASE_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    r_mtu3_three_phase_write_protect_disable(p_instance_ctrl);                                     /* Enable Read/Write Registers */

    /* Stop timer & initial output level */
    /* When setting MTU6, "TSYRA" is used because the address of "MTU3_THREE_BREG_OFFSET" is added to p_reg_com at the time of "open". */
    p_instance_ctrl->p_reg_com->TSTRA &= (uint8_t) ~(R_MTU_TSTRA_CST3_Msk | R_MTU_TSTRA_CST4_Msk); /* Stop timer MTU3/4 or MTU6/7 */
    p_instance_ctrl->p_reg_com->TOERA &= (uint8_t) ~MTU3_THREE_TOER_ALL;                           /* output is disabled (non-active level) */
    /* Close MTU3 modules */
    R_MTU3_Close(p_instance_ctrl->p_cfg->p_timer_instance[MTU3_THREE_CH1ST]->p_ctrl);
    R_MTU3_Close(p_instance_ctrl->p_cfg->p_timer_instance[MTU3_THREE_CH2ND]->p_ctrl);

    r_mtu3_three_phase_write_protect_enable(p_instance_ctrl); /* Disanable Read/Write Registers */

    /* Clear open flag. */
    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/** @} (end addtogroup MTU3_THREE_PHASE) */
#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/*******************************************************************************************************************//**
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * This function checks if the combination of CHs can be used.
 *
 * @param[in]  p_cfg         Pointer to configuration structure.
 * @retval MTU3_THREE_USE_CHA(=3)       USE MTU3/4ch
 * @retval MTU3_THREE_USE_CHB(=6)       USE MTU6/7ch
 * @retval MTU3_THREE_USE_CHNG(=0)      INVALID_CHANNEL
 **********************************************************************************************************************/
static uint32_t r_mtu3_three_phase_check_ch (three_phase_cfg_t const * const p_cfg)
{
    uint8_t ch1 = p_cfg->p_timer_instance[MTU3_THREE_CH1ST]->p_cfg->channel;
    uint8_t ch2 = p_cfg->p_timer_instance[MTU3_THREE_CH2ND]->p_cfg->channel;

    if (ch1 > ch2)
    {
        uint8_t ch0;
        ch0 = ch2;
        ch2 = ch1;
        ch1 = ch0;
    }

    if ((MTU3_THREE_USE_CHA == ch1) && ((MTU3_THREE_USE_CHA + 1) == ch2))
    {
        return (uint32_t) ch1;         /* MTU3/4 */
    }

    if ((MTU3_THREE_USE_CHB == ch1) && ((MTU3_THREE_USE_CHB + 1) == ch2))
    {
        return (uint32_t) ch1;         /* MTU6/7 */
    }

    return (uint32_t) MTU3_THREE_USE_CHNG;
}

/*******************************************************************************************************************//**
 * This function sets the required additional registers in complementary PWM mode.
 *
 * @param[in]  p_instance_ctrl      Pointer to configuration structure.
 * @param[in]  pp_extend            Pointer to extension features.
 *
 * @retval FSP_SUCCESS                    Initialization was successful.
 * @retval FSP_ERR_INVALID_ARGUMENT       Period count is out of range.
 *                                        The sum of period count values and dead time is out of range.
 *                                        When ch3 is specified, set ch3 and ch4 in the "Timer Synchronous Register" setting.
 *                                        When ch6 is specified, set ch6 and ch7 in the "Timer Synchronous Register" setting.
 **********************************************************************************************************************/
static fsp_err_t r_mtu3_three_phase_regset (mtu3_three_phase_instance_ctrl_t * p_instance_ctrl, void const * pp_extend)
{
    mtu3_three_phase_extended_cfg_t * p_extend = (mtu3_three_phase_extended_cfg_t *) pp_extend;

#ifdef MTU3_THREE_PHASE_CFG_PARAM_CHECKING_ENABLE

    /* period_half < 0xffff */
    if (p_extend->period_half >= (uint16_t) MTU3_THREE_TGR_MAX)
    {
        return FSP_ERR_INVALID_ARGUMENT;
    }

    /* period_half + dead_time <= 0xffff */
    if (((uint32_t) p_extend->period_half + (uint32_t) p_extend->dead_time) > MTU3_THREE_TGR_MAX)
    {
        return FSP_ERR_INVALID_ARGUMENT;
    }

    /* check Timer Synchronous Register */
    if (MTU3_THREE_USE_CHA == p_instance_ctrl->channel) /* MTU3/4 */
    {
        if ((MTU3_THREE_PHASE_SYNCHRONOUS_CHANNEL_3 == p_extend->sync) ||
            (MTU3_THREE_PHASE_SYNCHRONOUS_CHANNEL_4 == p_extend->sync))
        {
            return FSP_ERR_INVALID_ARGUMENT;
        }
    }
    else                               /* MTU6/7 */
    {
        if ((MTU3_THREE_PHASE_SYNCHRONOUS_CHANNEL_6 == p_extend->sync) ||
            (MTU3_THREE_PHASE_SYNCHRONOUS_CHANNEL_7 == p_extend->sync))
        {
            return FSP_ERR_INVALID_ARGUMENT;
        }
    }
#endif

    /* Setting Inter-channel synchronization */
    if (MTU3_THREE_PHASE_SYNCHRONOUS_CHANNEL_DISABLE != p_extend->sync)
    {
        if (MTU3_THREE_USE_CHA == p_instance_ctrl->channel) /* MTU3/4 */
        {
            p_instance_ctrl->p_reg_com->TSYRA = R_MTU_TSYRA_SYNC3_Msk | R_MTU_TSYRA_SYNC4_Msk;
            if (p_extend->sync <= MTU3_THREE_PHASE_SYNCHRONOUS_CHANNEL_2)
            {
                p_instance_ctrl->p_reg_com->TSYRA |= tsyra_clr_ch[p_extend->sync];              /* TSYRA <- Synchronous ch MTU0/1/2 */
            }
            else
            {
                p_instance_ctrl->p_reg_com->TSYRB = tsyra_clr_ch[p_extend->sync];               /* TSYRB <- Synchronous ch MTU6/7 */
            }
        }
        else                                                                                    /* MTU6/7 */
        {
            /* When setting MTU6, "TSYRA" is used because the address of "MTU3_THREE_BREG_OFFSET" is added to p_reg_com at the time of "open". */
            p_instance_ctrl->p_reg_com->TSYRA  = R_MTU_TSYRA_SYNC3_Msk | R_MTU_TSYRA_SYNC4_Msk; /* TSYRB <- Synchronous ch MTU6/7 */
            ((R_MTU_Type *) R_MTU_BASE)->TSYRA = tsyra_clr_ch[p_extend->sync];                  /* TSYRA <- Synchronous ch 0..4   */
        }

        *((volatile uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH1ST] +
          MTU36_TCR_OFFSET_ADDRESS) |= R_MTU3_TCR_CCLR_Msk;
        *((volatile uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH2ND] +
          MTU47_TCR_OFFSET_ADDRESS) |= R_MTU3_TCR_CCLR_Msk;
    }

    /* Setting duty */
    /* Note that TGRA , TGRB  and TCDR are transferred from the buffer register, so no setting is required. */
    *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH1ST] +
                            MTU36_TGRD_OFFSET_ADDRESS) = p_extend->duty_val[MTU3_THREE_CHU0];
    *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH2ND] +
                            MTU47_TGRC_OFFSET_ADDRESS) = p_extend->duty_val[MTU3_THREE_CHV1];
    *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH2ND] +
                            MTU47_TGRD_OFFSET_ADDRESS) = p_extend->duty_val[MTU3_THREE_CHW2];
    if (THREE_PHASE_BUFFER_MODE_DOUBLE == p_instance_ctrl->buffer_mode)
    {
        *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH1ST] +
                                MTU36_TGRE_OFFSET_ADDRESS) = p_extend->duty_double[MTU3_THREE_CHU0];
        *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH2ND] +
                                MTU47_TGRE_OFFSET_ADDRESS) = p_extend->duty_double[MTU3_THREE_CHV1];
        *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH2ND] +
                                MTU47_TGRF_OFFSET_ADDRESS) = p_extend->duty_double[MTU3_THREE_CHW2];
    }
    else
    {
        /* Just in case, set TGRE, TGRE, TGRF even in single buffer mode. */
        *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH1ST] +
                                MTU36_TGRE_OFFSET_ADDRESS) = p_extend->duty_val[MTU3_THREE_CHU0];
        *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH2ND] +
                                MTU47_TGRE_OFFSET_ADDRESS) = p_extend->duty_val[MTU3_THREE_CHV1];
        *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH2ND] +
                                MTU47_TGRF_OFFSET_ADDRESS) = p_extend->duty_val[MTU3_THREE_CHW2];
    }

    /* setting Period and Dead time */
    uint16_t dtime;
    if (MTU3_THREE_NO_DEADTIME == p_extend->dead_time)
    {
        p_instance_ctrl->p_reg_com->TDERA &= (uint8_t) ~R_MTU_TDERB_TDER_Msk; /* TDER : No dead time is generated */
        dtime = 1;
    }
    else
    {
        p_instance_ctrl->p_reg_com->TDERA |= R_MTU_TDERB_TDER_Msk; /* Dead time is generated */
        p_instance_ctrl->p_reg_com->TCBRA  = p_extend->period_half;
        dtime = p_extend->dead_time;
    }

    p_instance_ctrl->p_reg_com->TDDRA = dtime;
    *(volatile uint16_t *) ((uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH1ST] +
                            MTU36_TGRC_OFFSET_ADDRESS) = (uint16_t) (p_extend->period_half + dtime);

    /* set output control registers */
    uint8_t tocr1 = (MTU3_THREE_PHASE_PSYE_TOGGLE == p_extend->period_out) ? R_MTU_TOCR1A_PSYE_Msk : 0; /* Set PSYE bit or not */
    if (MTU3_THREE_PHASE_OUTPUT_LEVEL_ACTIVE_LOW != p_extend->level)
    {
        p_instance_ctrl->p_reg_com->TOCR1A = tocr1 | R_MTU_TOCR1A_OLSN_Msk | R_MTU_TOCR1A_OLSP_Msk;
    }
    else
    {
        p_instance_ctrl->p_reg_com->TOCR1A = tocr1;
    }

    /* Clear TIORH/L  */
    *((volatile uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH1ST] + MTU36_TIORH_OFFSET_ADDRESS) = 0;
    *((volatile uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH1ST] + MTU36_TIORL_OFFSET_ADDRESS) = 0;
    *((volatile uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH2ND] + MTU47_TIORH_OFFSET_ADDRESS) = 0;
    *((volatile uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH2ND] + MTU47_TIORL_OFFSET_ADDRESS) = 0;

    /* setting TMDR1 */
    *((volatile uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH1ST] +
      MTU36_TMDR1_OFFSET_ADDRESS) = tmdr1_md[p_extend->pwm_mode];
    *((volatile uint8_t *) p_instance_ctrl->p_reg[MTU3_THREE_CH2ND] + MTU47_TMDR1_OFFSET_ADDRESS) &=
        (uint8_t) ~(R_MTU3_TMDR1_BFA_Msk | R_MTU3_TMDR1_BFB_Msk);              /* clear BFA,BFB bit */
    if (THREE_PHASE_BUFFER_MODE_DOUBLE == p_instance_ctrl->buffer_mode)
    {
        p_instance_ctrl->p_reg_com->TMDR2A |= R_MTU_TMDR2A_DRS_Msk;            /* Double buffer function is enabled */
    }
    else
    {
        p_instance_ctrl->p_reg_com->TMDR2A &= (uint8_t) ~R_MTU_TMDR2A_DRS_Msk; /* Double buffer function is disabled */
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disables write protection for all relevant MTU3 registers (if enabled).
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 **********************************************************************************************************************/
static inline void r_mtu3_three_phase_write_protect_enable (mtu3_three_phase_instance_ctrl_t * const p_instance_ctrl)
{
#if MTU3_THREE_PHASE_CFG_WRITE_PROTECT_ENABLE
    if (MTU3_THREE_TRWER_ACCESS == p_instance_ctrl->p_reg_com->TRWERA)
    {
        p_instance_ctrl->p_reg_com->TRWERA = MTU3_THREE_TRWER_PROTECT;
    }

#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
#endif
}

/*******************************************************************************************************************//**
 * Disables write protection for all relevant MTU3 registers (if enabled).
 *
 * @param[in]  p_instance_ctrl         Instance control block.
 **********************************************************************************************************************/
static inline void r_mtu3_three_phase_write_protect_disable (mtu3_three_phase_instance_ctrl_t * const p_instance_ctrl)
{
#if MTU3_THREE_PHASE_CFG_WRITE_PROTECT_ENABLE
    p_instance_ctrl->p_reg_com->TRWERA = MTU3_THREE_TRWER_ACCESS;
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
#endif
}
