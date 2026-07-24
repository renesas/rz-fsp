/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @ingroup RENESAS_SYSTEM_INTERFACES
 * @defgroup ICU_INTER_CPU_IRQ_API Inter CPU IRQ Interface
 * @brief Interface for INTCPU interrupt.
 *
 * @section ICU_INTER_CPU_IRQ_API_Summary Summary
 * The ICU_INTER_CPU_IRQ Interface is for configuring and firing INTCPU interrupts.
 *
 * @{
 **********************************************************************************************************************/

#ifndef R_ICU_INTER_CPU_IRQ_API_H
#define R_ICU_INTER_CPU_IRQ_API_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Includes board and MCU related header files. */
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/** Callback function parameter data */
typedef struct st_icu_inter_cpu_irq_callback_args
{
    /** Placeholder for user data. Set in @ref icu_inter_cpu_irq_api_t::open function in @ref icu_inter_cpu_irq_cfg_t. */
    void * p_context;
} icu_inter_cpu_irq_callback_args_t;

/** User configuration structure, used in open function */
typedef struct st_icu_inter_cpu_irq_cfg
{
    uint8_t   channel;                 ///< Hardware channel used.
    uint8_t   ipl;                     ///< Interrupt priority
    IRQn_Type irq;                     ///< Interrupt number assigned to this instance

    /** Callback provided INTCPU occurs. */
    void (* p_callback)(icu_inter_cpu_irq_callback_args_t * p_args);

    /** Placeholder for user data.  Passed to the user callback in @ref icu_inter_cpu_irq_callback_args_t. */
    void       * p_context;
    void const * p_extend;             ///< INTCPU hardware dependent configuration.
} icu_inter_cpu_irq_cfg_t;

/** ICU_INTER_CPU_IRQ control block.  Allocate an instance specific control block to pass into the ICU_INTER_CPU_IRQ API calls.
 */
typedef void icu_inter_cpu_irq_ctrl_t;

/** ICU_INTER_CPU_IRQ driver structure. ICU_INTER_CPU_IRQ functions implemented at the HAL layer will follow this API. */
typedef struct st_icu_inter_cpu_irq_api
{
    /** Opens the core to core driver and initializes the hardware.
     *
     * @param[in] p_ctrl    Pointer to control block. Must be declared by user. Elements are set here.
     * @param[in] p_cfg     Pointer to configuration structure.
     */
    fsp_err_t (* open)(icu_inter_cpu_irq_ctrl_t * const p_ctrl, icu_inter_cpu_irq_cfg_t const * const p_cfg);

    /** Generates INTCPU interrupt.
     *
     * @param[in] p_ctrl     Control block set for this INTCPU interrupt.
     */
    fsp_err_t (* generate)(icu_inter_cpu_irq_ctrl_t * const p_ctrl);

    /**
     * Specify callback function and optional context pointer and working memory pointer.
     *
     * @param[in]   p_ctrl                   Pointer to the ICU_INTER_CPU_IRQ control block.
     * @param[in]   p_callback               Callback function
     * @param[in]   p_context                Pointer to send to callback function
     * @param[in]   p_working_memory         Pointer to volatile memory where callback structure can be allocated.
     *                                       Callback arguments allocated here are only valid during the callback.
     */
    fsp_err_t (* callbackSet)(icu_inter_cpu_irq_ctrl_t * const p_ctrl,
                              void (* p_callback)(icu_inter_cpu_irq_callback_args_t *), void * const p_context,
                              icu_inter_cpu_irq_callback_args_t * const p_callback_memory);

    /** Closes the driver and releases the device.
     *
     * @param[in] p_ctrl    Pointer to control block set in @ref icu_inter_cpu_irq_api_t::open call.
     */
    fsp_err_t (* close)(icu_inter_cpu_irq_ctrl_t * const p_ctrl);
} icu_inter_cpu_irq_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_icu_inter_cpu_irq_instance
{
    icu_inter_cpu_irq_ctrl_t      * p_ctrl; ///< Pointer to the control structure for this instance
    icu_inter_cpu_irq_cfg_t const * p_cfg;  ///< Pointer to the configuration structure for this instance
    icu_inter_cpu_irq_api_t const * p_api;  ///< Pointer to the API structure for this instance
} icu_inter_cpu_irq_instance_t;

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

/*******************************************************************************************************************//**
 * @} (end defgroup ICU_INTER_CPU_IRQ_API)
 ***********************************************************************************************************************/

#endif
