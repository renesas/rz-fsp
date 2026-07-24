/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_MHU_NS_SWINT_SET_API_H
#define R_MHU_NS_SWINT_SET_API_H

/*******************************************************************************************************************//**
 * @ingroup RENESAS_SYSTEM_INTERFACES
 * @defgroup MHU_NS_SWINT_SET_API MHU Interface (Software Interrupt Set)
 * @brief Interface for Message Handling Unit (Software Interrupt Set)
 *
 * @section MHU_NS_SWINT_SET_API_SUMMARY Summary
 * The Message Handling Unit (Software Interrupt Set) interface provides a common API for MHU HAL drivers.
 * The Message Handling Unit (Software Interrupt Set) interface supports:
 *        - Generate software interrupt via MHU.
 *
 *
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Register definitions, common services and error codes. */
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** MHU callback parameter definition */
typedef struct st_mhu_ns_swint_set_callback_args
{
    /** Placeholder for user data.  Set in @ref mhu_ns_swint_set_api_t::open function in @ref mhu_ns_swint_set_cfg_t. */
    void   * p_context;
    uint32_t channel;                  ///< Channel where the receive interrupt occurred.
} mhu_ns_swint_set_callback_args_t;

/** MHU configuration block */
typedef struct st_mhu_ns_swint_set_cfg
{
    /** Generic configuration */
    uint32_t channel;                  ///< Identifier recognizable by implementation

    /** Placeholder for user data.  Passed to the user callback in @ref timer_callback_args_t. */
    void       * p_context;
    void const * p_extend;             ///< Extension parameter for hardware specific settings
} mhu_ns_swint_set_cfg_t;

/** MHU control block.  Allocate an instance specific control block to pass into the MHU API calls.
 */
typedef void mhu_ns_swint_set_ctrl_t;

/** Interface definition for MHU */
typedef struct st_mhu_ns_swint_set_api
{
    /** Opens the MHU driver and initializes the hardware.
     *
     * @param[in] p_ctrl    Pointer to control block. Must be declared by user. Elements are set here.
     * @param[in] p_cfg     Pointer to configuration structure.
     */
    fsp_err_t (* open)(mhu_ns_swint_set_ctrl_t * const p_ctrl, mhu_ns_swint_set_cfg_t const * const p_cfg);

    /** Performs a send operation on an MHU device.
     *
     * @param[in] p_ctrl    Pointer to control block set in mhu_ns_swint_set_api_t::open call.
     */
    fsp_err_t (* interruptSet)(mhu_ns_swint_set_ctrl_t * const p_ctrl);

    /** Closes the driver and releases the MHU device.
     *
     * @param[in] p_ctrl    Pointer to control block set in mhu_ns_swint_set_api_t::open call.
     */
    fsp_err_t (* close)(mhu_ns_swint_set_ctrl_t * const p_ctrl);
} mhu_ns_swint_set_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_mhu_ns_swint_set_instance
{
    mhu_ns_swint_set_ctrl_t      * p_ctrl; ///< Pointer to the control structure for this instance
    mhu_ns_swint_set_cfg_t const * p_cfg;  ///< Pointer to the configuration structure for this instance
    mhu_ns_swint_set_api_t const * p_api;  ///< Pointer to the API structure for this instance
} mhu_ns_swint_set_instance_t;

/******************************************************************************************************************//**
 * @} (end defgroup MHU_NS_SWINT_SET_API)
 *********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
