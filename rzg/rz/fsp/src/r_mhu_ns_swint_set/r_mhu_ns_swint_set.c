/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_mhu_ns_swint_set.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** "MHU" in ASCII, used to determine if channel is open. */
#define MHU_NS_SWINT_SET_OPEN                (0x00774855ULL)

#define MHU_NS_SWINT_SET_SHMEM_CH_SIZE       (0x8)
#define MHU_NS_SWINT_SET_SHMEM_TXD_OFFSET    (0x0)
#define MHU_NS_SWINT_SET_SHMEM_RXD_OFFSET    (0x4)

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
typedef void (BSP_CMSE_NONSECURE_CALL * mhu_ns_swint_set_prv_ns_callback)(mhu_ns_swint_set_callback_args_t * p_args);
#elif defined(__GNUC__)
typedef BSP_CMSE_NONSECURE_CALL void (*volatile mhu_ns_swint_set_prv_ns_callback)(mhu_ns_swint_set_callback_args_t *
                                                                                  p_args);
#endif

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void r_mhu_ns_swint_set_interrupt(mhu_ns_swint_set_instance_ctrl_t * p_instance_ctrl);

static fsp_err_t r_mhu_ns_swint_set_common_preamble(mhu_ns_swint_set_instance_ctrl_t * p_instance_ctrl);

#if MHU_NS_SWINT_SET_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t r_mhu_ns_swint_set_open_param_checking(mhu_ns_swint_set_instance_ctrl_t   * p_instance_ctrl,
                                                        mhu_ns_swint_set_cfg_t const * const p_cfg);

#endif

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/** MHU_NS_SWINT_SET Implementation of MHU Driver  */
const mhu_ns_swint_set_api_t g_mhu_ns_swint_set_on_mhu_ns_swint_set =
{
    .open         = R_MHU_NS_SWINT_SET_Open,
    .interruptSet = R_MHU_NS_SWINT_SET_InterruptSet,
    .close        = R_MHU_NS_SWINT_SET_Close,
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZG
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZG_MHU_NS_SWINT_SET
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initializes the MHU_NS_SWINT_SET module instance. Implements @ref mhu_ns_swint_set_api_t::open.
 *
 * @retval FSP_SUCCESS                 Initialization was successful.
 * @retval FSP_ERR_ASSERTION           A required input pointer is NULL.
 * @retval FSP_ERR_ALREADY_OPEN        R_MHU_NS_SWINT_SET_Open has already been called for this p_ctrl.
 * @retval FSP_ERR_INVALID_CHANNEL     Requested channel number is not available on MHU_NS_SWINT_SET.
 **********************************************************************************************************************/
fsp_err_t R_MHU_NS_SWINT_SET_Open (mhu_ns_swint_set_ctrl_t * const p_ctrl, mhu_ns_swint_set_cfg_t const * const p_cfg)
{
    mhu_ns_swint_set_instance_ctrl_t * p_instance_ctrl = (mhu_ns_swint_set_instance_ctrl_t *) p_ctrl;

#if MHU_NS_SWINT_SET_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = r_mhu_ns_swint_set_open_param_checking(p_instance_ctrl, p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    FSP_ASSERT(NULL != ((mhu_ns_swint_set_extended_cfg_t *) p_cfg->p_extend)->p_reg);
#endif

    /* Get extended configuration structure pointer. */
    mhu_ns_swint_set_extended_cfg_t * p_extend = (mhu_ns_swint_set_extended_cfg_t *) p_cfg->p_extend;

    p_instance_ctrl->p_regs  = (R_MHU_SWINT0_Type *) p_extend->p_reg;
    p_instance_ctrl->p_cfg   = p_cfg;
    p_instance_ctrl->channel = p_cfg->channel;

    /* Power on the MHU_NS_SWINT_SET channel. */
    R_BSP_MODULE_START(FSP_IP_MHU, p_cfg->channel);

    p_instance_ctrl->open = MHU_NS_SWINT_SET_OPEN;

    /* All done.  */
    return FSP_SUCCESS;
}

/**********************************************************************************************************************
 * End of function R_MHU_NS_SWINT_SET_Open
 *********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Set Interrupt via MHU.
 * Implements @ref mhu_ns_swint_set_api_t::interruptSet.
 *
 * @retval FSP_SUCCESS                 Set interrupt successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer was NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_MHU_NS_SWINT_SET_InterruptSet (mhu_ns_swint_set_ctrl_t * const p_ctrl)
{
    mhu_ns_swint_set_instance_ctrl_t * p_instance_ctrl = (mhu_ns_swint_set_instance_ctrl_t *) p_ctrl;
#if MHU_NS_SWINT_SET_CFG_PARAM_CHECKING_ENABLE
#endif

    fsp_err_t err = r_mhu_ns_swint_set_common_preamble(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Set interrupt. */
    r_mhu_ns_swint_set_interrupt(p_instance_ctrl);

    return FSP_SUCCESS;
}

/**********************************************************************************************************************
 * End of function R_MHU_NS_SWINT_SET_InterruptSet
 *********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Clears internal driver data.
 * @ref mhu_ns_swint_set_api_t::close.
 *
 *
 *
 * @retval FSP_SUCCESS                 MHU_NS_SWINT_SET closed.
 * @retval FSP_ERR_ASSERTION           p_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t R_MHU_NS_SWINT_SET_Close (mhu_ns_swint_set_ctrl_t * const p_ctrl)
{
    mhu_ns_swint_set_instance_ctrl_t * p_instance_ctrl = (mhu_ns_swint_set_instance_ctrl_t *) p_ctrl;

    fsp_err_t err = r_mhu_ns_swint_set_common_preamble(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/**********************************************************************************************************************
 * End of function R_MHU_NS_SWINT_SET_Close
 *********************************************************************************************************************/

/** @} (end addtogroup MHU_NS_SWINT_SET) */

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

#if MHU_NS_SWINT_SET_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Parameter checking for R_MHU_NS_SWINT_SET_Open.
 *
 * @param[in] p_instance_ctrl          Pointer to instance control structure.
 * @param[in]  p_cfg                   Configuration structure for this instance
 *
 * @retval FSP_SUCCESS                 Initialization was successful.
 * @retval FSP_ERR_ASSERTION           A required input pointer is NULL.
 * @retval FSP_ERR_ALREADY_OPEN        R_MHU_NS_SWINT_SET_Open has already been called for this p_ctrl.
 * @retval FSP_ERR_INVALID_CHANNEL     Requested channel number is not available on MHU_NS_SWINT_SET.
 **********************************************************************************************************************/
static fsp_err_t r_mhu_ns_swint_set_open_param_checking (mhu_ns_swint_set_instance_ctrl_t   * p_instance_ctrl,
                                                         mhu_ns_swint_set_cfg_t const * const p_cfg)
{
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ERROR_RETURN(MHU_NS_SWINT_SET_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);

    /* Validate channel number. */
    FSP_ERROR_RETURN(((1U << p_cfg->channel) & BSP_FEATURE_MHU_NS_SWINT_SET_VALID_CHANNEL_MASK),
                     FSP_ERR_INVALID_CHANNEL);

    return FSP_SUCCESS;
}

#endif

/*******************************************************************************************************************//**
 * Common code at the beginning of all MHU_NS_SWINT_SET functions except open.
 *
 * @param[in] p_instance_ctrl          Pointer to instance control structure.
 *
 * @retval FSP_SUCCESS                 No invalid conditions detected, MHU_NS_SWINT_SET state matches expected state.
 * @retval FSP_ERR_ASSERTION           p_ctrl is null.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
static fsp_err_t r_mhu_ns_swint_set_common_preamble (mhu_ns_swint_set_instance_ctrl_t * p_instance_ctrl)
{
#if MHU_NS_SWINT_SET_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(MHU_NS_SWINT_SET_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
#endif

    return FSP_SUCCESS;
}

/**********************************************************************************************************************
 * End of function r_mhu_ns_swint_set_common_preamble
 *********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Set MHU SWINT
 *
 * @param[in]  p_instance_ctrl    Control block for this instance
 **********************************************************************************************************************/
static void r_mhu_ns_swint_set_interrupt (mhu_ns_swint_set_instance_ctrl_t * p_instance_ctrl)
{
    /* Check interrupt status: Has the previous message been received? */
    do
    {
        /* Do Nothing */
    } while (0 != p_instance_ctrl->p_regs->SW_INT_STSn);

    /* Assert interrupt. */
    p_instance_ctrl->p_regs->SW_INT_SETn = 1;
}

/**********************************************************************************************************************
 * End of function r_mhu_ns_swint_set_interrupt
 *********************************************************************************************************************/
