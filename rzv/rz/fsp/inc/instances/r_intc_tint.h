/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_INTC_TINT_H
 #define R_INTC_TINT_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include "r_external_irq_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZV
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZV_INTC_TINT
 * @{
 **********************************************************************************************************************/

/*********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/** INTC_TINT GPIOINT number. */
typedef uint8_t intc_tint_gpioint_t;

/** TINT trigger condition. */
typedef enum e_intc_tint_trigger
{
    INTC_TINT_TRIGGER_RISING     = 0,  ///< Rising edge trigger
    INTC_TINT_TRIGGER_FALLING    = 1,  ///< Falling edge trigger
    INTC_TINT_TRIGGER_LEVEL_HIGH = 2,  ///< High level trigger
    INTC_TINT_TRIGGER_LEVEL_LOW  = 3,  ///< Low level trigger
} intc_tint_trigger_t;

/** INTC_TINT private control block. DO NOT MODIFY.  Initialization occurs when R_INTC_TINT_ExternalIrqOpen is called. */
struct st_intc_tint_instance_ctrl
{
    uint32_t  open;                                             ///< Used to determine if channel control block is in use
    IRQn_Type irq;                                              ///< Interrupt number
    uint8_t   channel;                                          ///< Channel

 #if BSP_TZ_SECURE_BUILD
    external_irq_callback_args_t * p_callback_memory;           // Pointer to non-secure memory that can be used to pass arguments to a callback in non-secure memory.
 #endif
    void (* p_callback)(external_irq_callback_args_t * p_args); // Pointer to callback that is called when an edge is detected on the external irq pin.

    /** Placeholder for user data.  Passed to the user callback in RZV::external_irq_callback_args_t. */
    void * p_context;
};

/** INTC_TINT private control block. DO NOT MODIFY.  Initialization occurs when R_INTC_TINT_ExternalIrqOpen is called. Please refer to the struct st_intc_tint_instance_ctrl. */
typedef struct st_intc_tint_instance_ctrl intc_tint_instance_ctrl_t;

/** INTC_TINT configuration extension. */
struct st_intc_tint_extended_cfg
{
    intc_tint_gpioint_t gpioint;       ///< GPIOINT number
    intc_tint_trigger_t tint_trigger;  ///< TINT trigger
};

/** INTC_TINT configuration extension. Please refer to the struct st_intc_tint_extended_cfg. */
typedef struct st_intc_tint_extended_cfg intc_tint_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const external_irq_api_t g_external_irq_on_intc_tint;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_INTC_TINT_ExternalIrqOpen(external_irq_ctrl_t * const p_api_ctrl, external_irq_cfg_t const * const p_cfg);

fsp_err_t R_INTC_TINT_ExternalIrqEnable(external_irq_ctrl_t * const p_api_ctrl);

fsp_err_t R_INTC_TINT_ExternalIrqDisable(external_irq_ctrl_t * const p_api_ctrl);

fsp_err_t R_INTC_TINT_ExternalIrqCallbackSet(external_irq_ctrl_t * const p_api_ctrl,
                                             void (                    * p_callback)(
                                                 external_irq_callback_args_t *),
                                             void * const                         p_context,
                                             external_irq_callback_args_t * const p_callback_memory);

fsp_err_t R_INTC_TINT_ExternalIrqClose(external_irq_ctrl_t * const p_api_ctrl);

/*******************************************************************************************************************//**
 * @} (end defgroup INTC_TINT)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 // R_INTC_TINT_H
