/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * Includes
 *********************************************************************************************************************/
#include "r_shared_memory.h"
#include "r_shared_memory_cfg.h"

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

/* "SHARED_MEMORY" in ASCII, used to determine if channel is open. */
#define SHARED_MEMORY_OPEN           (0x0053484DULL)

#define SHARED_MEMORY_MEMORY_INIT    (0x00U)
#define SHARED_MEMORY_MEMORY_OPEN    (0x53U)

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Private function prototypes
 *********************************************************************************************************************/

void            r_shared_memory_callback(icu_inter_cpu_irq_callback_args_t * p_args);
static void     r_shared_memory_release_resource(uint8_t semaphore_reg);
static uint32_t r_shared_memory_read_resource_status(uint8_t semaphore_reg);

/**********************************************************************************************************************
 * Private global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Global variables
 *********************************************************************************************************************/

shared_memory_api_t const g_shared_memory_on_shared_memory =
{
    .open        = R_SHARED_MEMORY_Open,
    .read        = R_SHARED_MEMORY_Read,
    .write       = R_SHARED_MEMORY_Write,
    .statusGet   = R_SHARED_MEMORY_StatusGet,
    .close       = R_SHARED_MEMORY_Close,
    .callbackSet = R_SHARED_MEMORY_CallbackSet,
};

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZT
{
#endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_SHARED_MEMORY
 * @{
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Functions
 *********************************************************************************************************************/

/******************************************************************************************************************//**
 * Opens the shared memory driver. Implements @ref shared_memory_api_t::open().
 *
 * @retval  FSP_SUCCESS                       Module opened successfully.
 * @retval  FSP_ERR_ALREADY_OPEN              Module is already open.
 * @retval  FSP_ERR_IN_USE                    Semaphore registor selected in configuration is in use.
 * @retval  FSP_ERR_ASSERTION                 Parameter check failure due to one or more reasons below:
 *                                            1. p_ctrl or p_cfg is NULL.
 *                                            2. extended parameter is NULL.
 *                                            3. Callback parameter is NULL.
 * @return See @ref RZT_RENESAS_ERROR_CODES or functions called by this function for other possible return codes.
 *         This function calls:
 *             - @ref icu_inter_cpu_irq_api_t::open
 *             - @ref icu_inter_cpu_irq_api_t::generate
 *********************************************************************************************************************/
fsp_err_t R_SHARED_MEMORY_Open (shared_memory_ctrl_t * const p_ctrl, shared_memory_cfg_t const * const p_cfg)
{
    shared_memory_instance_ctrl_t * p_instance_ctrl = (shared_memory_instance_ctrl_t *) p_ctrl;
    fsp_err_t         err;
    volatile uint32_t resource_status = 0;
    uint32_t          memory_size;

#if SHARED_MEMORY_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl != NULL);
    FSP_ASSERT(p_cfg != NULL);
    FSP_ASSERT(p_cfg->semaphore_reg < 8);
    FSP_ASSERT(p_cfg->p_memory != NULL);
    FSP_ASSERT(p_cfg->p_callback != NULL);
    FSP_ASSERT(p_cfg->p_extend != NULL);
    FSP_ASSERT(((shared_memory_extended_cfg_t *) p_cfg->p_extend)->p_software_int_tx != NULL);
    FSP_ASSERT(((shared_memory_extended_cfg_t *) p_cfg->p_extend)->p_software_int_rx != NULL);

    FSP_ERROR_RETURN(SHARED_MEMORY_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    /* Record the configuration for using it later */
    p_instance_ctrl->p_cfg = p_cfg;
    memory_size            = p_instance_ctrl->p_cfg->memory_size;

    /* Check the initialization status of the shared memory. */
    FSP_ERROR_RETURN(((SHARED_MEMORY_MEMORY_INIT == p_cfg->p_memory[memory_size]) ||
                      (SHARED_MEMORY_MEMORY_OPEN == p_cfg->p_memory[memory_size])),
                     FSP_ERR_ALREADY_OPEN);

    /* Set callback and context pointers, if configured */
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    icu_inter_cpu_irq_instance_t * p_software_int_tx =
        (icu_inter_cpu_irq_instance_t *) ((shared_memory_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend)->
        p_software_int_tx;
    icu_inter_cpu_irq_instance_t * p_software_int_rx =
        (icu_inter_cpu_irq_instance_t *) ((shared_memory_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend)->
        p_software_int_rx;

    ((icu_inter_cpu_irq_cfg_t *) (p_software_int_tx->p_cfg))->p_context = p_instance_ctrl;
    err = p_software_int_tx->p_api->open(p_software_int_tx->p_ctrl, p_software_int_tx->p_cfg);
    if (FSP_SUCCESS != err)
    {
        return err;
    }

    ((icu_inter_cpu_irq_cfg_t *) (p_software_int_rx->p_cfg))->p_context = p_instance_ctrl;
    err = p_software_int_rx->p_api->open(p_software_int_rx->p_ctrl, p_software_int_rx->p_cfg);
    if (FSP_SUCCESS != err)
    {
        return err;
    }

    resource_status = r_shared_memory_read_resource_status(p_instance_ctrl->p_cfg->semaphore_reg);
    if (0x00000000 == resource_status) // wait Shared memory available
    {
        return FSP_ERR_IN_USE;
    }

    if (SHARED_MEMORY_MEMORY_INIT == p_instance_ctrl->p_cfg->p_memory[memory_size])
    {
        p_instance_ctrl->p_cfg->p_memory[memory_size] = SHARED_MEMORY_MEMORY_OPEN;
        __asm("dmb sy");               /* Ensuring data-changing */
        p_instance_ctrl->state = SHARED_MEMORY_STATE_NOT_READY;
    }
    else
    {
        p_instance_ctrl->p_cfg->p_memory[memory_size] =
            (uint8_t) (p_instance_ctrl->p_cfg->p_memory[memory_size] + SHARED_MEMORY_MEMORY_OPEN);
        __asm("dmb sy");               /* Ensuring data-changing */

        err = p_software_int_tx->p_api->generate(p_software_int_tx->p_ctrl);
        if (FSP_SUCCESS != err)
        {
            return err;
        }

        p_instance_ctrl->state = SHARED_MEMORY_STATE_READY_TO_WRITE;
    }

    r_shared_memory_release_resource(p_instance_ctrl->p_cfg->semaphore_reg); // Shared memory becomes available

    /* Finally, we can consider this module opened */
    p_instance_ctrl->open = SHARED_MEMORY_OPEN;

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Performs a read from the shared memory. Implements @ref shared_memory_api_t::read().
 *
 * @retval  FSP_SUCCESS        Function executed without issue
 * @retval  FSP_ERR_ASSERTION  p_ctrl or p_dest is NULL.
 * @retval  FSP_ERR_INVALID_ARGUMENT    Invalid input parameter.
 * @retval  FSP_ERR_IN_USE     Another transfer was in progress.
 * @retval  FSP_ERR_NOT_OPEN   Module is not open.
 *********************************************************************************************************************/
fsp_err_t R_SHARED_MEMORY_Read (shared_memory_ctrl_t * const p_ctrl,
                                uint8_t * const              p_dest,
                                uint32_t const               offset,
                                uint32_t const               bytes)
{
    shared_memory_instance_ctrl_t * p_instance_ctrl = (shared_memory_instance_ctrl_t *) p_ctrl;
    volatile uint32_t               resource_status = 0;

#if SHARED_MEMORY_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl != NULL);
    FSP_ASSERT(p_dest != NULL);

    /* Return an error if this module have already been opened */
    FSP_ERROR_RETURN(SHARED_MEMORY_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    if ((p_instance_ctrl->p_cfg->memory_size < (offset + bytes)) ||
        (p_instance_ctrl->p_cfg->memory_size <= offset) ||
        (p_instance_ctrl->p_cfg->memory_size < bytes))
    {
        return FSP_ERR_INVALID_ARGUMENT;
    }

    resource_status = r_shared_memory_read_resource_status(p_instance_ctrl->p_cfg->semaphore_reg);
    if (0x00000000 == resource_status) // wait Shared memory available
    {
        return FSP_ERR_IN_USE;
    }

    memcpy(p_dest, &p_instance_ctrl->p_cfg->p_memory[offset], bytes);

    r_shared_memory_release_resource(p_instance_ctrl->p_cfg->semaphore_reg); // Shared memory becomes available

    if (SHARED_MEMORY_STATE_READY_TO_READ_WRITE == p_instance_ctrl->state)
    {
        p_instance_ctrl->state = SHARED_MEMORY_STATE_READY_TO_WRITE;
    }

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Performs a write to the shared memory. Implements @ref shared_memory_api_t::write().
 *
 * @retval  FSP_SUCCESS        Function executed without issue.
 * @retval  FSP_ERR_ASSERTION  p_ctrl or p_src is NULL.
 * @retval  FSP_ERR_INVALID_ARGUMENT    Invalid input parameter.
 * @retval  FSP_ERR_IN_USE     Another transfer was in progress.
 * @retval  FSP_ERR_NOT_OPEN   Module is not open.
 *********************************************************************************************************************/
fsp_err_t R_SHARED_MEMORY_Write (shared_memory_ctrl_t * const p_ctrl,
                                 uint8_t * const              p_src,
                                 uint32_t const               offset,
                                 uint32_t const               bytes)
{
    shared_memory_instance_ctrl_t * p_instance_ctrl = (shared_memory_instance_ctrl_t *) p_ctrl;
    volatile uint32_t               resource_status = 0;

#if SHARED_MEMORY_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl != NULL);
    FSP_ASSERT(p_src != NULL);

    /* Return an error if this module have already been opened */
    FSP_ERROR_RETURN(SHARED_MEMORY_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    icu_inter_cpu_irq_instance_t * p_software_int_tx =
        (icu_inter_cpu_irq_instance_t *) ((shared_memory_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend)->
        p_software_int_tx;

    if ((p_instance_ctrl->p_cfg->memory_size < (offset + bytes)) ||
        (p_instance_ctrl->p_cfg->memory_size <= offset) ||
        (p_instance_ctrl->p_cfg->memory_size < bytes))
    {
        return FSP_ERR_INVALID_ARGUMENT;
    }

    resource_status = r_shared_memory_read_resource_status(p_instance_ctrl->p_cfg->semaphore_reg);
    if (0x00000000 == resource_status) // wait Shared memory available
    {
        return FSP_ERR_IN_USE;
    }

    memcpy(&p_instance_ctrl->p_cfg->p_memory[offset], p_src, bytes);
    __asm("dmb sy");                                                         /*Ensuring data-changing */

    r_shared_memory_release_resource(p_instance_ctrl->p_cfg->semaphore_reg); // Shared memory becomes available

    p_software_int_tx->p_api->generate(p_software_int_tx->p_ctrl);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Provides driver status. Implements @ref shared_memory_api_t::statusGet().
 *
 * @retval     FSP_SUCCESS                   Status is stored in p_status.
 * @retval     FSP_ERR_ASSERTION             p_ctrl or p_status is NULL.
 * @retval     FSP_ERR_NOT_OPEN              Module is not open.
 **********************************************************************************************************************/
fsp_err_t R_SHARED_MEMORY_StatusGet (shared_memory_ctrl_t * const p_ctrl, shared_memory_status_t * p_status)
{
    shared_memory_instance_ctrl_t * p_instance_ctrl = (shared_memory_instance_ctrl_t *) p_ctrl;

#if SHARED_MEMORY_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl != NULL);
    FSP_ASSERT(p_status != NULL);

    /* Return an error if this module have already been opened */
    FSP_ERROR_RETURN(SHARED_MEMORY_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_status->state = p_instance_ctrl->state;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements @ref shared_memory_api_t::callbackSet
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_SHARED_MEMORY_CallbackSet (shared_memory_ctrl_t * const p_ctrl,
                                       void (                     * p_callback)(
                                           shared_memory_callback_args_t *),
                                       void * const                          p_context,
                                       shared_memory_callback_args_t * const p_callback_memory)
{
    shared_memory_instance_ctrl_t * p_instance_ctrl = (shared_memory_instance_ctrl_t *) p_ctrl;

#if (SHARED_MEMORY_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(SHARED_MEMORY_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */
    p_instance_ctrl->p_callback        = p_callback;
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Closes the SHARED_MEMORY. Implements @ref shared_memory_api_t::close().
 *
 * @retval  FSP_SUCCESS         Module closed successfully.
 * @retval  FSP_ERR_NOT_OPEN    Module is not open.
 * @retval  FSP_ERR_ASSERTION   p_ctrl is NULL.
 * @retval  FSP_ERR_IN_USE     Another transfer was in progress.
 *********************************************************************************************************************/
fsp_err_t R_SHARED_MEMORY_Close (shared_memory_ctrl_t * const p_ctrl)
{
    shared_memory_instance_ctrl_t * p_instance_ctrl = (shared_memory_instance_ctrl_t *) p_ctrl;
    volatile uint32_t               resource_status = 0;

#if SHARED_MEMORY_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl != NULL);

    /* Return an error if this module have already been opened */
    FSP_ERROR_RETURN(SHARED_MEMORY_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    uint32_t memory_size = p_instance_ctrl->p_cfg->memory_size;

    icu_inter_cpu_irq_instance_t * p_software_int_tx =
        (icu_inter_cpu_irq_instance_t *) ((shared_memory_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend)->
        p_software_int_tx;
    icu_inter_cpu_irq_instance_t * p_software_int_rx =
        (icu_inter_cpu_irq_instance_t *) ((shared_memory_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend)->
        p_software_int_rx;

    p_software_int_tx->p_api->close(p_software_int_tx->p_ctrl);
    p_software_int_rx->p_api->close(p_software_int_rx->p_ctrl);

    resource_status = r_shared_memory_read_resource_status(p_instance_ctrl->p_cfg->semaphore_reg);
    if (0x00000000 == resource_status) // wait Shared memory available
    {
        return FSP_ERR_IN_USE;
    }

    if ((SHARED_MEMORY_MEMORY_OPEN == p_instance_ctrl->p_cfg->p_memory[memory_size]) ||
        ((SHARED_MEMORY_MEMORY_OPEN + SHARED_MEMORY_MEMORY_OPEN) == p_instance_ctrl->p_cfg->p_memory[memory_size]))
    {
        p_instance_ctrl->p_cfg->p_memory[memory_size] =
            (uint8_t) (p_instance_ctrl->p_cfg->p_memory[memory_size] - SHARED_MEMORY_MEMORY_OPEN);
        __asm("dmb sy");               /* Ensuring data-changing */
        p_instance_ctrl->state = SHARED_MEMORY_STATE_NOT_READY;
    }
    else
    {
        // Do nothing
    }

    r_shared_memory_release_resource(p_instance_ctrl->p_cfg->semaphore_reg); // Shared memory becomes available

    /* This module is considered closed */
    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * @} (end addtogroup SHARED_MEMORY)
 *********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif

/**********************************************************************************************************************
 * Private Functions
 *********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Releases the resource so that share memory becomes available.
 *
 * @param[in]  semaphore_reg               Select semaphore register
 **********************************************************************************************************************/
static void r_shared_memory_release_resource (uint8_t semaphore_reg)
{
#if 1U == BSP_FEATURE_SHARED_MEMORY_SETTING_TYPE
    R_SEM->SYTSEMF_b[semaphore_reg].SEMF = 1;
#elif 2U == BSP_FEATURE_SHARED_MEMORY_SETTING_TYPE
    R_MBXSEM->SEMAR_b[semaphore_reg].SEM = 1;
#else
    FSP_PARAMETER_NOT_USED(semaphore_reg);
#endif
}

/*******************************************************************************************************************//**
 * Reads and returns the status of resource.
 *
 * @param[in]  semaphore_reg               Select semaphore register
 *
 * @retval resource_status                  Status of semaphore bit
 **********************************************************************************************************************/
static uint32_t r_shared_memory_read_resource_status (uint8_t semaphore_reg)
{
    uint32_t resource_status;

#if 1U == BSP_FEATURE_SHARED_MEMORY_SETTING_TYPE
    resource_status = R_SEM->SYTSEMF_b[semaphore_reg].SEMF;
#elif 2U == BSP_FEATURE_SHARED_MEMORY_SETTING_TYPE
    resource_status = R_MBXSEM->SEMAR_b[semaphore_reg].SEM;
#else
    resource_status = 0;
#endif

    return resource_status;
}

/**********************************************************************************************************************
 * Interrupt Vectors
 *********************************************************************************************************************/

/******************************************************************************************************************//**
 * Processing when an interrupt occurs from core to core.
 *********************************************************************************************************************/
void r_shared_memory_callback (icu_inter_cpu_irq_callback_args_t * p_args)
{
    shared_memory_instance_ctrl_t * p_instance_ctrl = (shared_memory_instance_ctrl_t *) p_args->p_context;
    shared_memory_callback_args_t   args_stacked;
    shared_memory_callback_args_t   args;
    memset(&args, 0U, sizeof(shared_memory_callback_args_t));

    /* Store callback arguments in memory provided by user if available. */
    shared_memory_callback_args_t * p_args_memory = p_instance_ctrl->p_callback_memory;

    if (NULL == p_args_memory)
    {
        /* Use provided args struct on stack */
        p_args_memory = &args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt. */
        args_stacked = *p_args_memory;

        /* Copy the stacked args to callback memory */
        *p_args_memory = args;
    }

    p_args_memory->p_context = p_instance_ctrl->p_context;

    if (SHARED_MEMORY_STATE_READY_TO_WRITE == p_instance_ctrl->state)
    {
        p_instance_ctrl->state = SHARED_MEMORY_STATE_READY_TO_READ_WRITE;
        p_args_memory->state   = SHARED_MEMORY_STATE_READY_TO_READ_WRITE;
    }
    else
    {
        p_instance_ctrl->state = SHARED_MEMORY_STATE_READY_TO_WRITE;
        p_args_memory->state   = SHARED_MEMORY_STATE_READY_TO_WRITE;
    }

    p_instance_ctrl->p_callback(p_args_memory);

    if (NULL != p_instance_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_instance_ctrl->p_callback_memory = args_stacked;
    }
}
