/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_ICU_INTER_CPU_IRQ_H
 #define R_ICU_INTER_CPU_IRQ_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include "r_icu_inter_cpu_irq_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZT
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_ICU_INTER_CPU_IRQ
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/** ICU_INTER_CPU_IRQ private control structure. DO NOT MODIFY. Initialization occurs when R_ICU_INTER_CPU_IRQ_Open is called. */
struct st_icu_inter_cpu_irq_instance_ctrl
{
    uint32_t open;                                                   // Whether or not channel is open

    icu_inter_cpu_irq_cfg_t const * p_cfg;                           // Pointer to the configurations.

    void (* p_callback)(icu_inter_cpu_irq_callback_args_t * p_args); // Pointer to callback
    icu_inter_cpu_irq_callback_args_t * p_callback_memory;           // Pointer to optional callback argument memory
    void * p_context;                                                // Pointer to context to be passed into callback function
};

/** ICU_INTER_CPU_IRQ private control structure. DO NOT MODIFY. Initialization occurs when R_ICU_INTER_CPU_IRQ_Open is called. Please refer to the struct st_icu_inter_cpu_irq_instance_ctrl. */
typedef struct st_icu_inter_cpu_irq_instance_ctrl icu_inter_cpu_irq_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 ***********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const icu_inter_cpu_irq_api_t g_icu_inter_cpu_irq_on_icu;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/

fsp_err_t R_ICU_INTER_CPU_IRQ_Open(icu_inter_cpu_irq_ctrl_t * const      p_ctrl,
                                   icu_inter_cpu_irq_cfg_t const * const p_cfg);

fsp_err_t R_ICU_INTER_CPU_IRQ_Generate(icu_inter_cpu_irq_ctrl_t * const p_ctrl);

fsp_err_t R_ICU_INTER_CPU_IRQ_CallbackSet(icu_inter_cpu_irq_ctrl_t * const p_ctrl,
                                          void (                         * p_callback)(
                                              icu_inter_cpu_irq_callback_args_t *),
                                          void * const                              p_context,
                                          icu_inter_cpu_irq_callback_args_t * const p_callback_memory);

fsp_err_t R_ICU_INTER_CPU_IRQ_Close(icu_inter_cpu_irq_ctrl_t * const p_ctrl);

/*******************************************************************************************************************//**
 * @} (end defgroup ICU_INTER_CPU_IRQ)
 ***********************************************************************************************************************/
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 // R_ICU_INTER_CPU_IRQ_H
