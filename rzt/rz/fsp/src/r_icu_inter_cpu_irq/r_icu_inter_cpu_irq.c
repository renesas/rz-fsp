/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * Includes
 *********************************************************************************************************************/
#include "r_icu_inter_cpu_irq.h"
#include "r_icu_inter_cpu_irq_cfg.h"

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

/* "ICUI" in ASCII, used to determine if channel is open. */
#define ICU_INTER_CPU_IRQ_OPEN    (0x49435549U)

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Private function prototypes
 *********************************************************************************************************************/
static void r_icu_inter_cpu_irq_call_callback(icu_inter_cpu_irq_instance_ctrl_t * p_ctrl,
                                              icu_inter_cpu_irq_callback_args_t * p_args);

/***********************************************************************************************************************
 * ISR prototypes
 **********************************************************************************************************************/
void r_icu_inter_cpu_irq_isr(void);

/**********************************************************************************************************************
 * Private global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Global variables
 *********************************************************************************************************************/

/* ICU implementation of ICU_INTER_CPU_IRQ API. */
const icu_inter_cpu_irq_api_t g_icu_inter_cpu_irq_on_icu =
{
    .open        = R_ICU_INTER_CPU_IRQ_Open,
    .generate    = R_ICU_INTER_CPU_IRQ_Generate,
    .callbackSet = R_ICU_INTER_CPU_IRQ_CallbackSet,
    .close       = R_ICU_INTER_CPU_IRQ_Close,
};

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZT
{
#endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_ICU_INTER_CPU_IRQ
 * @{
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Functions
 *********************************************************************************************************************/

/******************************************************************************************************************//**
 * Opens the icu_inter_cpu_irq driver. Implements @ref icu_inter_cpu_irq_api_t::open().
 *
 * @retval  FSP_SUCCESS                       opened successfully.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT     The channel requested in p_cfg is not available on the device selected in
 *                                            r_bsp_cfg.h.
 * @retval  FSP_ERR_ALREADY_OPEN              Module is already open.
 * @retval  FSP_ERR_ASSERTION                 Parameter check failure due to one or more reasons below:
 *                                            1. p_ctrl or p_cfg is NULL.
 *                                            2. Callback parameter is NULL.
 *********************************************************************************************************************/
fsp_err_t R_ICU_INTER_CPU_IRQ_Open (icu_inter_cpu_irq_ctrl_t * const      p_ctrl,
                                    icu_inter_cpu_irq_cfg_t const * const p_cfg)
{
    icu_inter_cpu_irq_instance_ctrl_t * p_instance_ctrl = (icu_inter_cpu_irq_instance_ctrl_t *) p_ctrl;

#if ICU_INTER_CPU_IRQ_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl != NULL);
    FSP_ASSERT(p_cfg != NULL);
    FSP_ERROR_RETURN(0 != ((1U << p_cfg->channel) & BSP_FEATURE_ICU_INTER_CPU_IRQ_CHANNELS_MASK),
                     FSP_ERR_IP_CHANNEL_NOT_PRESENT);

    FSP_ERROR_RETURN(ICU_INTER_CPU_IRQ_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    /* Initialize control block. */
    p_instance_ctrl->p_cfg             = p_cfg;
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    /* NOTE: User can have the driver opened when the IRQ is not in the vector table. This is for use cases
     * that use INTCPU interrupts and do not notify themselves of the interrupts.
     * In such cases we will not set the GIC registers but will continue with the processing.
     */
    if (BSP_IRQ_DISABLED != p_cfg->ipl)
    {
        R_BSP_IrqCfgEnable(p_instance_ctrl->p_cfg->irq, p_cfg->ipl, p_ctrl);
    }

    /* Mark the control block as open */
    p_instance_ctrl->open = ICU_INTER_CPU_IRQ_OPEN;

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Generate software interrupt. Implements @ref icu_inter_cpu_irq_api_t::generate().
 *
 *
 * @retval  FSP_SUCCESS        Function executed without issue.
 * @retval  FSP_ERR_ASSERTION  p_ctrl or p_src is NULL.
 * @retval  FSP_ERR_NOT_OPEN   Device is not open.
 *********************************************************************************************************************/
fsp_err_t R_ICU_INTER_CPU_IRQ_Generate (icu_inter_cpu_irq_ctrl_t * const p_ctrl)
{
    icu_inter_cpu_irq_instance_ctrl_t * p_instance_ctrl = (icu_inter_cpu_irq_instance_ctrl_t *) p_ctrl;

#if ICU_INTER_CPU_IRQ_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl != NULL);

    /* Check if the device is even open, return an error if not */
    FSP_ERROR_RETURN(ICU_INTER_CPU_IRQ_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    uint32_t swint = (uint32_t) (1U << p_instance_ctrl->p_cfg->channel);

    if (BSP_FEATURE_ICU_INTER_CPU_IRQ_NS_SWINT_MASK & swint)
    {
        R_ICU_NS->NS_SWINT = swint;
    }
    else if (BSP_FEATURE_ICU_INTER_CPU_IRQ_S_SWINT_MASK & swint)
    {
#if (1U == BSP_FEATURE_ICU_INTER_CPU_IRQ_CHANNEL)
        R_ICU->S_SWINT = swint >> BSP_FEATURE_ICU_INTER_CPU_IRQ_S_SWINT_SHIFT;
#elif (2U == BSP_FEATURE_ICU_INTER_CPU_IRQ_CHANNEL)
        R_ICU_S->S_SWINT = swint >> BSP_FEATURE_ICU_INTER_CPU_IRQ_S_SWINT_SHIFT;
#endif
    }
    else
    {
        /* Do nothing. Not supported this channel. */
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 * Implements @ref icu_inter_cpu_irq_api_t::callbackSet().
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_ICU_INTER_CPU_IRQ_CallbackSet (icu_inter_cpu_irq_ctrl_t * const p_ctrl,
                                           void (                         * p_callback)(
                                               icu_inter_cpu_irq_callback_args_t *),
                                           void * const                              p_context,
                                           icu_inter_cpu_irq_callback_args_t * const p_callback_memory)
{
    icu_inter_cpu_irq_instance_ctrl_t * p_instance_ctrl = (icu_inter_cpu_irq_instance_ctrl_t *) p_ctrl;

#if ICU_INTER_CPU_IRQ_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(ICU_INTER_CPU_IRQ_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */
    p_instance_ctrl->p_callback        = p_callback;
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Closes the icu_inter_cpu_irq. Implements @ref icu_inter_cpu_irq_api_t::close().
 *
 * @retval  FSP_SUCCESS         Device closed successfully.
 * @retval  FSP_ERR_NOT_OPEN    Device not opened.
 * @retval  FSP_ERR_ASSERTION   p_ctrl is NULL.
 *********************************************************************************************************************/
fsp_err_t R_ICU_INTER_CPU_IRQ_Close (icu_inter_cpu_irq_ctrl_t * const p_ctrl)
{
    icu_inter_cpu_irq_instance_ctrl_t * p_instance_ctrl = (icu_inter_cpu_irq_instance_ctrl_t *) p_ctrl;

#if ICU_INTER_CPU_IRQ_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl != NULL);

    /* Check if the device is even open, return an error if not */
    FSP_ERROR_RETURN(ICU_INTER_CPU_IRQ_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Cleanup. Disable interrupt */

    /* Disable the interrupt, and then clear the interrupt pending bits and inter   rupt status. */
    R_BSP_IrqDisable(p_instance_ctrl->p_cfg->irq);
    R_FSP_IsrContextSet(p_instance_ctrl->p_cfg->irq, NULL);

    /* The device is now considered closed */
    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * @} (end addtogroup ICU_INTER_CPU_IRQ)
 *********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif

/******************************************************************************************************************//**
 * ICU_INTER_CPU_IRQ ISR.
 *********************************************************************************************************************/
void r_icu_inter_cpu_irq_isr (void)
{
    ICU_INTER_CPU_IRQ_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();
    icu_inter_cpu_irq_instance_ctrl_t * p_ctrl = (icu_inter_cpu_irq_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    if ((NULL != p_ctrl) && (NULL != p_ctrl->p_callback))
    {
        /* Set data to identify callback to user, then call user callback. */
        icu_inter_cpu_irq_callback_args_t args;
        args.p_context = p_ctrl->p_context;
        r_icu_inter_cpu_irq_call_callback(p_ctrl, &args);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    ICU_INTER_CPU_IRQ_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_ctrl     Pointer to CAN instance control block
 * @param[in]     p_args     Pointer to arguments on stack
 **********************************************************************************************************************/
static void r_icu_inter_cpu_irq_call_callback (icu_inter_cpu_irq_instance_ctrl_t * p_ctrl,
                                               icu_inter_cpu_irq_callback_args_t * p_args)
{
    icu_inter_cpu_irq_callback_args_t args;
    memset(&args, 0U, sizeof(icu_inter_cpu_irq_callback_args_t));

    /* Store callback arguments in memory provided by user if available. */
    icu_inter_cpu_irq_callback_args_t * p_args_memory = p_ctrl->p_callback_memory;
    if (NULL == p_args_memory)
    {
        /* Use provided args struct on stack */
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
