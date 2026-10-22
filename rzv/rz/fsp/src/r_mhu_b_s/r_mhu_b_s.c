/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_mhu_b_s.h"

#ifdef BSP_CFG_OPENAMP                 // OpenAMP
 #include "metal/irq_controller.h"
#endif

#if (BSP_CFG_RTOS == 2)                // FreeRTOS
 #include "FreeRTOS.h"
 #include "task.h"
#endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** "MHU" in ASCII, used to determine if channel is open. */
#define MHU_B_S_OPEN                      (0x00774855ULL)

#define MHU_B_S_SHMEM_SECURE_CH_OFFSET    (0x800)
#define MHU_B_S_SHMEM_CH_SIZE             (0x8)
#define MHU_B_S_RSP_TXD_OFFSET            (0x0)
#define MHU_B_S_MSG_TXD_OFFSET            (0x4)

#define MHU_B_S_PRV_ARRAY_END             (0xFFFFFFFF)

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
typedef void (BSP_CMSE_NONSECURE_CALL * mhu_b_s_prv_s_callback)(mhu_callback_args_t * p_args);
#elif defined(__GNUC__)
typedef BSP_CMSE_NONSECURE_CALL void (*volatile mhu_b_s_prv_s_callback)(mhu_callback_args_t * p_args);
#endif

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void r_mhu_b_s_set_send_data(mhu_b_s_instance_ctrl_t * p_instance_ctrl, uint32_t msg);

static fsp_err_t r_mhu_b_s_common_preamble(mhu_b_s_instance_ctrl_t * p_instance_ctrl);

#if MHU_B_S_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t r_mhu_b_s_open_param_checking(mhu_b_s_instance_ctrl_t * p_instance_ctrl,
                                               mhu_cfg_t const * const   p_cfg);

#endif

/* ISRs. */
void mhu_b_s_int_isr(void);
void metal_irq_isr_wrapper_s(void);
void metal_irq_isr(uint32_t vector);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/** Version data structure. */

extern uint32_t __mhu_shmem_start;

static const uint32_t g_shmem_base = (uint32_t) &__mhu_shmem_start;

struct st_mhu_b_reg_pair
{
    uint32_t      msg_channel;
    R_MHU0_Type * msg;
    uint32_t      rsp_channel;
    R_MHU0_Type * rsp;
};

static const struct st_mhu_b_reg_pair mhu_b_snd_ch[42] =
{
    R_BSP_MHU_B_S_REG_PAIR_BODY
};

static const uint32_t mhu_b_send_type_msg[] =
{
    R_BSP_MHU_B_S_SEND_TYPE_MSG_BODY,
    MHU_B_S_PRV_ARRAY_END
};

static const uint32_t mhu_b_send_type_rsp[] =
{
    R_BSP_MHU_B_S_SEND_TYPE_RSP_BODY,
    MHU_B_S_PRV_ARRAY_END
};

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/** MHU_B_S Implementation of MHU Driver  */
const mhu_api_t g_mhu_b_s_on_mhu_b_s =
{
    .open        = R_MHU_B_S_Open,
    .msgSend     = R_MHU_B_S_MsgSend,
    .callbackSet = R_MHU_B_S_CallbackSet,
    .close       = R_MHU_B_S_Close,
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZV
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZV_MHU_B_S
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initializes the MHU_B_S module instance. Implements @ref mhu_api_t::open.
 *
 * @retval FSP_SUCCESS                 Initialization was successful.
 * @retval FSP_ERR_ASSERTION           A required input pointer is NULL.
 * @retval FSP_ERR_ALREADY_OPEN        R_MHU_B_S_Open has already been called for this p_ctrl.
 * @retval FSP_ERR_INVALID_ARGUMENT    The specified IRQ number is invalid.
 * @retval FSP_ERR_INVALID_CHANNEL     Requested channel number is not available on MHU_B_S.
 **********************************************************************************************************************/
fsp_err_t R_MHU_B_S_Open (mhu_ctrl_t * const p_ctrl, mhu_cfg_t const * const p_cfg)
{
    mhu_b_s_instance_ctrl_t * p_instance_ctrl = (mhu_b_s_instance_ctrl_t *) p_ctrl;

#if MHU_B_S_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = r_mhu_b_s_open_param_checking(p_instance_ctrl, p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    FSP_ASSERT(NULL != ((mhu_b_s_extended_cfg_t *) p_cfg->p_extend)->p_reg);
#endif

    /* Get extended configuration structure pointer. */
    mhu_b_s_extended_cfg_t * p_extend = (mhu_b_s_extended_cfg_t *) p_cfg->p_extend;

    p_instance_ctrl->p_regs    = (R_MHU0_Type *) p_extend->p_reg;
    p_instance_ctrl->p_cfg     = p_cfg;
    p_instance_ctrl->channel   = p_cfg->channel;
    p_instance_ctrl->send_type = MHU_SEND_TYPE_MSG;

    for (uint32_t i = 0; mhu_b_send_type_msg[i] != MHU_B_S_PRV_ARRAY_END; i++)
    {
        if (p_cfg->rx_irq == (IRQn_Type) mhu_b_send_type_msg[i])
        {
            p_instance_ctrl->send_type = MHU_SEND_TYPE_MSG;
            break;
        }
    }

    for (uint32_t i = 0; mhu_b_send_type_rsp[i] != MHU_B_S_PRV_ARRAY_END; i++)
    {
        if (p_cfg->rx_irq == (IRQn_Type) mhu_b_send_type_rsp[i])
        {
            p_instance_ctrl->send_type = MHU_SEND_TYPE_RSP;
            break;
        }
    }

    if (0 != p_cfg->p_shared_memory)
    {
        /* Use specified address */
        if (p_instance_ctrl->send_type == MHU_SEND_TYPE_RSP)
        {
            p_instance_ctrl->p_shared_memory_tx = (uint32_t *) (((uint32_t) p_cfg->p_shared_memory) +
                                                                MHU_B_S_RSP_TXD_OFFSET);
            p_instance_ctrl->p_shared_memory_rx = (uint32_t *) (((uint32_t) p_cfg->p_shared_memory) +
                                                                MHU_B_S_MSG_TXD_OFFSET);
        }
        else
        {
            p_instance_ctrl->p_shared_memory_tx = (uint32_t *) (((uint32_t) p_cfg->p_shared_memory) +
                                                                MHU_B_S_MSG_TXD_OFFSET);
            p_instance_ctrl->p_shared_memory_rx = (uint32_t *) (((uint32_t) p_cfg->p_shared_memory) +
                                                                MHU_B_S_RSP_TXD_OFFSET);
        }
    }
    else
    {
        /* Use default location */
        if (p_instance_ctrl->send_type == MHU_SEND_TYPE_RSP)
        {
            p_instance_ctrl->p_shared_memory_tx =
                (uint32_t *) (g_shmem_base + MHU_B_S_SHMEM_SECURE_CH_OFFSET + (MHU_B_S_SHMEM_CH_SIZE * p_cfg->channel) +
                              MHU_B_S_RSP_TXD_OFFSET);
            p_instance_ctrl->p_shared_memory_rx =
                (uint32_t *) (g_shmem_base + MHU_B_S_SHMEM_SECURE_CH_OFFSET + (MHU_B_S_SHMEM_CH_SIZE * p_cfg->channel) +
                              MHU_B_S_MSG_TXD_OFFSET);
        }
        else
        {
            p_instance_ctrl->p_shared_memory_tx =
                (uint32_t *) (g_shmem_base + MHU_B_S_SHMEM_SECURE_CH_OFFSET +
                              (MHU_B_S_SHMEM_CH_SIZE * mhu_b_snd_ch[p_cfg->channel].msg_channel) +
                              MHU_B_S_MSG_TXD_OFFSET);
            p_instance_ctrl->p_shared_memory_rx =
                (uint32_t *) (g_shmem_base + MHU_B_S_SHMEM_SECURE_CH_OFFSET +
                              (MHU_B_S_SHMEM_CH_SIZE * mhu_b_snd_ch[p_cfg->channel].msg_channel) +
                              MHU_B_S_RSP_TXD_OFFSET);
        }
    }

    /* Power on the MHU_B_S channel. */
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

    p_instance_ctrl->open = MHU_B_S_OPEN;

    /* All done.  */
    return FSP_SUCCESS;
}

/**********************************************************************************************************************
 * End of function R_MHU_B_S_Open
 *********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Send message via MHU.
 * Implements @ref mhu_api_t::msgSend.
 *
 * @retval FSP_SUCCESS                 Send message successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_MHU_B_S_MsgSend (mhu_ctrl_t * const p_ctrl, uint32_t const msg)
{
    mhu_b_s_instance_ctrl_t * p_instance_ctrl = (mhu_b_s_instance_ctrl_t *) p_ctrl;
#if MHU_B_S_CFG_PARAM_CHECKING_ENABLE
#endif

    fsp_err_t err = r_mhu_b_s_common_preamble(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Set msg. */
    r_mhu_b_s_set_send_data(p_instance_ctrl, msg);

    return FSP_SUCCESS;
}

/**********************************************************************************************************************
 * End of function R_MHU_B_S_MsgSend
 *********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 * Implements @ref mhu_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_NO_CALLBACK_MEMORY   p_callback is non-secure and p_callback_memory is either secure or NULL.
 **********************************************************************************************************************/
fsp_err_t R_MHU_B_S_CallbackSet (mhu_ctrl_t * const          p_api_ctrl,
                                 void (                    * p_callback)(mhu_callback_args_t *),
                                 void * const                p_context,
                                 mhu_callback_args_t * const p_callback_memory)
{
    mhu_b_s_instance_ctrl_t * p_ctrl = (mhu_b_s_instance_ctrl_t *) p_api_ctrl;

#if MHU_B_S_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(MHU_B_S_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

#if BSP_TZ_SECURE_BUILD

    /* Get security state of p_callback */
    p_ctrl->callback_is_secure =
        (NULL == cmse_check_address_range((void *) p_callback, sizeof(void *), CMSE_AU_NONSECURE));

 #if MHU_B_S_CFG_PARAM_CHECKING_ENABLE

    /* In secure projects, p_callback_memory must be provided in non-secure space if p_callback is non-secure */
    mhu_callback_args_t * const p_callback_memory_checked = cmse_check_pointed_object(p_callback_memory,
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

/**********************************************************************************************************************
 * End of function R_MHU_B_S_CallbackSet
 *********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Disables interrupts, clears internal driver data.
 * @ref mhu_api_t::close.
 *
 * @retval FSP_SUCCESS                 MHU_B_S closed.
 * @retval FSP_ERR_ASSERTION           p_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_MHU_B_S_Close (mhu_ctrl_t * const p_ctrl)
{
    mhu_b_s_instance_ctrl_t * p_instance_ctrl = (mhu_b_s_instance_ctrl_t *) p_ctrl;

    fsp_err_t err = r_mhu_b_s_common_preamble(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Cleanup the device: disable interrupts. */

    R_BSP_IrqDisable(p_instance_ctrl->p_cfg->rx_irq);
    R_FSP_IsrContextSet(p_instance_ctrl->p_cfg->rx_irq, p_instance_ctrl);

    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/**********************************************************************************************************************
 * End of function R_MHU_B_S_Close
 *********************************************************************************************************************/

/** @} (end addtogroup MHU_B_S) */

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

#if MHU_B_S_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Parameter checking for R_MHU_B_S_Open.
 *
 * @param[in] p_instance_ctrl          Pointer to instance control structure.
 * @param[in]  p_cfg                   Configuration structure for this instance
 *
 * @retval FSP_SUCCESS                 Initialization was successful.
 * @retval FSP_ERR_ASSERTION           A required input pointer is NULL.
 * @retval FSP_ERR_ALREADY_OPEN        R_MHU_B_S_Open has already been called for this p_ctrl.
 * @retval FSP_ERR_INVALID_ARGUMENT    The specified IRQ number is invalid.
 * @retval FSP_ERR_INVALID_CHANNEL     Requested channel number is not available on MHU_B_S.
 **********************************************************************************************************************/
static fsp_err_t r_mhu_b_s_open_param_checking (mhu_b_s_instance_ctrl_t * p_instance_ctrl,
                                                mhu_cfg_t const * const   p_cfg)
{
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ERROR_RETURN(MHU_B_S_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);

    /* Validate channel number. */
    FSP_ERROR_RETURN(((1ULL << p_cfg->channel) & BSP_FEATURE_MHU_B_S_VALID_CHANNEL_MASK), FSP_ERR_INVALID_CHANNEL);

    FSP_ERROR_RETURN(FSP_INVALID_VECTOR != p_cfg->rx_irq, FSP_ERR_INVALID_ARGUMENT);

    return FSP_SUCCESS;
}

#endif

/*******************************************************************************************************************//**
 * Common code at the beginning of all MHU_B_S functions except open.
 *
 * @param[in] p_instance_ctrl          Pointer to instance control structure.
 *
 * @retval FSP_SUCCESS                 No invalid conditions detected, MHU_B_S state matches expected state.
 * @retval FSP_ERR_ASSERTION           p_ctrl is null.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
static fsp_err_t r_mhu_b_s_common_preamble (mhu_b_s_instance_ctrl_t * p_instance_ctrl)
{
#if MHU_B_S_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(MHU_B_S_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
#endif

    return FSP_SUCCESS;
}

/**********************************************************************************************************************
 * End of function r_mhu_b_s_common_preamble
 *********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Write a message to shared memory and generate inter-core interrupt
 *
 * @param[in]  p_instance_ctrl    Control block for this instance
 * @param[in]  msg                32bit send data
 **********************************************************************************************************************/
static void r_mhu_b_s_set_send_data (mhu_b_s_instance_ctrl_t * p_instance_ctrl, uint32_t msg)
{
    if (MHU_SEND_TYPE_MSG == p_instance_ctrl->send_type)
    {
        /* Check interrupt status: Has the previous message been received? */
        do
        {
#if (BSP_CFG_RTOS == 2)                // FreeRTOS
            BSP_FEATURE_MHU_B_TX_COMPLETE_DELAY();
#endif
        } while (0 != mhu_b_snd_ch[p_instance_ctrl->channel].msg->MSG_INT_STSn);

        /* Store the message data. */
        *p_instance_ctrl->p_shared_memory_tx = msg;

        /* Assert interrupt. */
        mhu_b_snd_ch[p_instance_ctrl->channel].msg->MSG_INT_SETn = 1;
    }
    else
    {
        /* Check interrupt status: Has the previous message been received? */
        do
        {
#if (BSP_CFG_RTOS == 2)                // FreeRTOS
            BSP_FEATURE_MHU_B_TX_COMPLETE_DELAY();
#endif
        } while (0 != mhu_b_snd_ch[p_instance_ctrl->channel].rsp->RSP_INT_STSn);

        /* Store the message data. */
        *p_instance_ctrl->p_shared_memory_tx = msg;

        /* Assert interrupt. */
        mhu_b_snd_ch[p_instance_ctrl->channel].rsp->RSP_INT_SETn = 1;
    }
}

/**********************************************************************************************************************
 * End of function r_mhu_b_s_set_send_data
 *********************************************************************************************************************/

#ifdef BSP_CFG_OPENAMP

/*********************************************************************************************************************
 * MHU_B_S receive interrupt (for OpenAMP)
 **********************************************************************************************************************/
void metal_irq_isr_wrapper_s (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    metal_irq_handle(&(struct metal_irq) { (void *) R_MHU_B_S_IsrSub, NULL}, irq);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

/**********************************************************************************************************************
 * End of function metal_irq_isr_wrapper_s
 *********************************************************************************************************************/
#endif

/*********************************************************************************************************************
 * MHU_B_S receive interrupt (for bare mhu_b_s application).
 **********************************************************************************************************************/
void mhu_b_s_int_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    R_MHU_B_S_IsrSub(irq);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

/**********************************************************************************************************************
 * End of function mhu_b_s_int_isr
 *********************************************************************************************************************/

/*******************************************************************************************************************//**
 * MHU_B_S receive interrupt sub function (for OpenAMP)
 *
 * @param[in]  irq    irq number for inter-core interrupt
 **********************************************************************************************************************/
void R_MHU_B_S_IsrSub (uint32_t irq)
{
    uint32_t msg;

    /* Clear pending IRQ to make sure it doesn't fire again after exiting */
    R_BSP_IrqStatusClear(irq);

    /* Recover ISR context saved in open. */
    mhu_b_s_instance_ctrl_t * p_instance_ctrl = (mhu_b_s_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Check interrupt reason */
    if (
        ((MHU_SEND_TYPE_RSP == p_instance_ctrl->send_type) && (0 != p_instance_ctrl->p_regs->MSG_INT_STSn)) ||
        ((MHU_SEND_TYPE_MSG == p_instance_ctrl->send_type) && (0 != p_instance_ctrl->p_regs->RSP_INT_STSn)))
    {
        /* Read data */
        msg = *p_instance_ctrl->p_shared_memory_rx;

        /* Clear interrupt */
        if (MHU_SEND_TYPE_RSP == p_instance_ctrl->send_type)
        {
            p_instance_ctrl->p_regs->MSG_INT_CLRn = 1;
        }
        else
        {
            p_instance_ctrl->p_regs->RSP_INT_CLRn = 1;
        }

        /* Invoke the callback function if it is set. */
        if (NULL != p_instance_ctrl->p_callback)
        {
            /* Setup parameters for the user-supplied callback function. */
            mhu_callback_args_t callback_args;

            /* Store callback arguments in memory provided by user if available.  This allows callback arguments to be
             * stored in non-secure memory so they can be accessed by a non-secure callback function. */
            mhu_callback_args_t * p_args = p_instance_ctrl->p_callback_memory;
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
            p_args->msg     = msg;

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
                mhu_b_s_prv_s_callback p_callback = (mhu_b_s_prv_s_callback) (p_instance_ctrl->p_callback);
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
}

/**********************************************************************************************************************
 * End of function R_MHU_B_S_IsrSub
 *********************************************************************************************************************/
