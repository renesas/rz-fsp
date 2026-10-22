/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_mhu_ns_swint_get.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** "MHU" in ASCII, used to determine if channel is open. */
#define MHU_NS_SWINT_GET_OPEN                (0x00774855ULL)

#define MHU_NS_SWINT_GET_SHMEM_CH_SIZE       (0x8)
#define MHU_NS_SWINT_GET_SHMEM_TXD_OFFSET    (0x0)
#define MHU_NS_SWINT_GET_SHMEM_RXD_OFFSET    (0x4)

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
typedef void (BSP_CMSE_NONSECURE_CALL * mhu_ns_swint_get_prv_ns_callback)(mhu_ns_swint_get_callback_args_t * p_args);
#elif defined(__GNUC__)
typedef BSP_CMSE_NONSECURE_CALL void (*volatile mhu_ns_swint_get_prv_ns_callback)(mhu_ns_swint_get_callback_args_t *
                                                                                  p_args);
#endif

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static fsp_err_t r_mhu_ns_swint_get_common_preamble(mhu_ns_swint_get_instance_ctrl_t * p_instance_ctrl);

#if MHU_NS_SWINT_GET_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t r_mhu_ns_swint_get_open_param_checking(mhu_ns_swint_get_instance_ctrl_t   * p_instance_ctrl,
                                                        mhu_ns_swint_get_cfg_t const * const p_cfg);

#endif

/* ISRs. */
void mhu_ns_swint_get_int_isr(void);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/** MHU_NS_SWINT_GET Implementation of MHU Driver  */
const mhu_ns_swint_get_api_t g_mhu_ns_swint_get_on_mhu_ns_swint_get =
{
    .open        = R_MHU_NS_SWINT_GET_Open,
    .callbackSet = R_MHU_NS_SWINT_GET_CallbackSet,
    .close       = R_MHU_NS_SWINT_GET_Close,
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZV
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZV_MHU_NS_SWINT_GET
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initializes the MHU_NS_SWINT_GET module instance. Implements @ref mhu_ns_swint_get_api_t::open.
 *
 * @retval FSP_SUCCESS                 Initialization was successful.
 * @retval FSP_ERR_ASSERTION           A required input pointer is NULL.
 * @retval FSP_ERR_ALREADY_OPEN        R_MHU_NS_SWINT_GET_Open has already been called for this p_ctrl.
 * @retval FSP_ERR_INVALID_ARGUMENT    The specified IRQ number is invalid.
 * @retval FSP_ERR_INVALID_CHANNEL     Requested channel number is not available on MHU_NS_SWINT_GET.
 **********************************************************************************************************************/
fsp_err_t R_MHU_NS_SWINT_GET_Open (mhu_ns_swint_get_ctrl_t * const p_ctrl, mhu_ns_swint_get_cfg_t const * const p_cfg)
{
    mhu_ns_swint_get_instance_ctrl_t * p_instance_ctrl = (mhu_ns_swint_get_instance_ctrl_t *) p_ctrl;

#if MHU_NS_SWINT_GET_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = r_mhu_ns_swint_get_open_param_checking(p_instance_ctrl, p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    FSP_ASSERT(NULL != ((mhu_ns_swint_get_extended_cfg_t *) p_cfg->p_extend)->p_reg);
#endif

    /* Get extended configuration structure pointer. */
    mhu_ns_swint_get_extended_cfg_t * p_extend = (mhu_ns_swint_get_extended_cfg_t *) p_cfg->p_extend;

    p_instance_ctrl->p_regs  = (R_MHU_SWINT0_Type *) p_extend->p_reg;
    p_instance_ctrl->p_cfg   = p_cfg;
    p_instance_ctrl->channel = p_cfg->channel;

    /* Power on the MHU_NS_SWINT_GET channel. */
    R_BSP_MODULE_START(FSP_IP_MHU, p_cfg->channel);

    R_BSP_IrqCfgEnable(p_cfg->rx_irq, p_cfg->rx_ipl, p_instance_ctrl);

    /* Set callback and context pointers */

#if BSP_TZ_SECURE_BUILD

    /* If this is a secure build, the callback provided in p_cfg must be secure. */
    p_instance_ctrl->callback_is_secure = true;
#endif
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    p_instance_ctrl->open = MHU_NS_SWINT_GET_OPEN;

    /* All done.  */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 * Implements @ref mhu_ns_swint_get_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_NO_CALLBACK_MEMORY   p_callback is non-secure and p_callback_memory is either secure or NULL.
 **********************************************************************************************************************/
fsp_err_t R_MHU_NS_SWINT_GET_CallbackSet (mhu_ns_swint_get_ctrl_t * const p_api_ctrl,
                                          void (                        * p_callback)(
                                              mhu_ns_swint_get_callback_args_t *),
                                          void * const                             p_context,
                                          mhu_ns_swint_get_callback_args_t * const p_callback_memory)
{
    mhu_ns_swint_get_instance_ctrl_t * p_ctrl = (mhu_ns_swint_get_instance_ctrl_t *) p_api_ctrl;

#if MHU_NS_SWINT_GET_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(MHU_NS_SWINT_GET_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

#if BSP_TZ_SECURE_BUILD

    /* Get security state of p_callback */
    p_ctrl->callback_is_secure =
        (NULL == cmse_check_address_range((void *) p_callback, sizeof(void *), CMSE_AU_NONSECURE));

 #if MHU_NS_SWINT_GET_CFG_PARAM_CHECKING_ENABLE

    /* In secure projects, p_callback_memory must be provided in non-secure space if p_callback is non-secure */
    mhu_ns_swint_get_callback_args_t * const p_callback_memory_checked = cmse_check_pointed_object(p_callback_memory,
                                                                                                   CMSE_AU_NONSECURE);
    FSP_ERROR_RETURN(p_ctrl->callback_is_secure || (NULL != p_callback_memory_checked), FSP_ERR_NO_CALLBACK_MEMORY);
 #endif
#endif

    /* Store callback and context */

#if BSP_TZ_SECURE_BUILD

    /* cmse_check_address_range returns NULL if p_callback is located in secure memory */
    p_ctrl->callback_is_secure =
        (NULL == cmse_check_address_range((void *) p_callback, sizeof(void *), CMSE_AU_NONSECURE));
#endif
    p_ctrl->p_callback        = p_callback;
    p_ctrl->p_context         = p_context;
    p_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disables interrupts, clears internal driver data.
 * @ref mhu_ns_swint_get_api_t::close.
 *
 *
 *
 * @retval FSP_SUCCESS                 MHU_NS_SWINT_GET closed.
 * @retval FSP_ERR_ASSERTION           p_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_MHU_NS_SWINT_GET_Close (mhu_ns_swint_get_ctrl_t * const p_ctrl)
{
    mhu_ns_swint_get_instance_ctrl_t * p_instance_ctrl = (mhu_ns_swint_get_instance_ctrl_t *) p_ctrl;

    fsp_err_t err = r_mhu_ns_swint_get_common_preamble(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Cleanup the device: disable interrupts. */

    NVIC_DisableIRQ(p_instance_ctrl->p_cfg->rx_irq);
    R_FSP_IsrContextSet(p_instance_ctrl->p_cfg->rx_irq, p_instance_ctrl);

    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/** @} (end addtogroup MHU_NS_SWINT_GET) */

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

#if MHU_NS_SWINT_GET_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Parameter checking for R_MHU_NS_SWINT_GET_Open.
 *
 * @param[in] p_instance_ctrl          Pointer to instance control structure.
 * @param[in]  p_cfg              Configuration structure for this instance
 *
 * @retval FSP_SUCCESS                 Initialization was successful.
 * @retval FSP_ERR_ASSERTION           A required input pointer is NULL.
 * @retval FSP_ERR_ALREADY_OPEN        R_MHU_NS_SWINT_GET_Open has already been called for this p_ctrl.
 * @retval FSP_ERR_INVALID_ARGUMENT    The specified IRQ number is invalid.
 * @retval FSP_ERR_INVALID_CHANNEL     Requested channel number is not available on MHU_NS_SWINT_GET.
 **********************************************************************************************************************/
static fsp_err_t r_mhu_ns_swint_get_open_param_checking (mhu_ns_swint_get_instance_ctrl_t   * p_instance_ctrl,
                                                         mhu_ns_swint_get_cfg_t const * const p_cfg)
{
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ERROR_RETURN(MHU_NS_SWINT_GET_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);

    /* Validate channel number. */
    FSP_ERROR_RETURN(((1U << p_cfg->channel) & BSP_FEATURE_MHU_NS_SWINT_GET_VALID_CHANNEL_MASK),
                     FSP_ERR_INVALID_CHANNEL);

    FSP_ERROR_RETURN(FSP_INVALID_VECTOR != p_cfg->rx_irq, FSP_ERR_INVALID_ARGUMENT);

    return FSP_SUCCESS;
}

#endif

/*******************************************************************************************************************//**
 * Common code at the beginning of all MHU_NS_SWINT_GET functions except open.
 *
 * @param[in] p_instance_ctrl          Pointer to instance control structure.
 *
 * @retval FSP_SUCCESS                 No invalid conditions detected, MHU_NS_SWINT_GET state matches expected state.
 * @retval FSP_ERR_ASSERTION           p_ctrl is null.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
static fsp_err_t r_mhu_ns_swint_get_common_preamble (mhu_ns_swint_get_instance_ctrl_t * p_instance_ctrl)
{
#if MHU_NS_SWINT_GET_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(MHU_NS_SWINT_GET_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
#endif

    return FSP_SUCCESS;
}

/*********************************************************************************************************************
 * MHU_NS_SWINT_GET receive interrupt (for bare mhu_ns_swint_get application).
 **********************************************************************************************************************/
void mhu_ns_swint_get_int_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    R_MHU_NS_SWINT_GET_IsrSub(irq);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * MHU_NS_SWINT_GET receive interrupt sub function (for OpenAMP)
 *
 * @param[in]  irq
 *
 * @retval none.
 **********************************************************************************************************************/
void R_MHU_NS_SWINT_GET_IsrSub (uint32_t irq)
{
    /* Clear pending IRQ to make sure it doesn't fire again after exiting */
    R_BSP_IrqStatusClear(irq);

    /* Recover ISR context saved in open. */
    mhu_ns_swint_get_instance_ctrl_t * p_instance_ctrl = (mhu_ns_swint_get_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Clear interrupt */
    p_instance_ctrl->p_regs->SW_INT_CLRn = 1;

    /* Invoke the callback function if it is set. */
    if (NULL != p_instance_ctrl->p_callback)
    {
        /* Setup parameters for the user-supplied callback function. */
        mhu_ns_swint_get_callback_args_t callback_args;

        /* Store callback arguments in memory provided by user if available.  This allows callback arguments to be
         * stored in non-secure memory so they can be accessed by a non-secure callback function. */
        mhu_ns_swint_get_callback_args_t * p_args = p_instance_ctrl->p_callback_memory;
        if (NULL == p_args)
        {
            /* Store on stack */
            p_args = &callback_args;
        }
        else
        {
            /* Save current arguments on the stack in case this is a nested interrupt. */
            callback_args = *p_args;
        }

        p_args->p_context = p_instance_ctrl->p_context;

        p_args->channel = p_instance_ctrl->channel;

#if BSP_TZ_SECURE_BUILD

        /* p_callback can point to a secure function or a non-secure function. */
        if (p_instance_ctrl->callback_is_secure)
        {
            /* If p_callback is secure, then the project does not need to change security state. */
            p_instance_ctrl->p_callback(p_args);
        }
        else
        {
            /* If p_callback is Non-secure, then the project must change to Non-secure state in order to call the callback. */
            mhu_ns_swint_get_prv_ns_callback p_callback =
                (mhu_ns_swint_get_prv_ns_callback) (p_instance_ctrl->p_callback);
            p_callback(p_args);
        }

#else

        /* If the project is not Trustzone Secure, then it will never need to change security state in order to call the callback. */
        p_instance_ctrl->p_callback(p_args);
#endif

        if (NULL != p_instance_ctrl->p_callback_memory)
        {
            /* Restore callback memory in case this is a nested interrupt. */
            *p_instance_ctrl->p_callback_memory = callback_args;
        }
    }
}
