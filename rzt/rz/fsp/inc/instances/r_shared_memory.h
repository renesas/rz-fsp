/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SHARED_MEMORY_H
 #define R_SHARED_MEMORY_H

 #include "bsp_api.h"
 #include "r_shared_memory_cfg.h"
 #include "r_shared_memory_api.h"
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
 * @addtogroup RZT_SHARED_MEMORY
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/** Extended configuration */
struct st_shared_memory_extended_cfg
{
    icu_inter_cpu_irq_instance_t const * p_software_int_tx; ///< Pointer to icu_inter_cpu_irq_instance_t to transmit
    icu_inter_cpu_irq_instance_t const * p_software_int_rx; ///< Pointer to icu_inter_cpu_irq_instance_t to receive
};

/** Extended configuration. Please refer to the struct st_shared_memory_extended_cfg. */
typedef struct st_shared_memory_extended_cfg shared_memory_extended_cfg_t;

/** SHARED_MEMORY control structure. DO NOT INITIALIZE. */
struct st_shared_memory_instance_ctrl
{
    shared_memory_cfg_t const * p_cfg;                    // Information describing SHARED_MEMORY
    uint32_t              open;                           // Flag to determine if the device is open
    shared_memory_state_t state;                          // Connection status with communication partner

    void (* p_callback)(shared_memory_callback_args_t *); // Pointer to callback
    shared_memory_callback_args_t * p_callback_memory;    // Pointer to optional callback argument memory
    void * p_context;                                     // Pointer to context to be passed into callback function
};

/** SHARED_MEMORY control structure. DO NOT INITIALIZE. Please refer to the struct st_shared_memory_instance_ctrl. */
typedef struct st_shared_memory_instance_ctrl shared_memory_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 ***********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern shared_memory_api_t const g_shared_memory_on_shared_memory;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/

fsp_err_t R_SHARED_MEMORY_Open(shared_memory_ctrl_t * const p_ctrl, shared_memory_cfg_t const * const p_cfg);
fsp_err_t R_SHARED_MEMORY_Read(shared_memory_ctrl_t * const p_ctrl,
                               uint8_t * const              p_dest,
                               uint32_t const               offset,
                               uint32_t const               bytes);
fsp_err_t R_SHARED_MEMORY_Write(shared_memory_ctrl_t * const p_ctrl,
                                uint8_t * const              p_src,
                                uint32_t const               offset,
                                uint32_t const               bytes);
fsp_err_t R_SHARED_MEMORY_StatusGet(shared_memory_ctrl_t * const p_ctrl, shared_memory_status_t * p_status);
fsp_err_t R_SHARED_MEMORY_CallbackSet(shared_memory_ctrl_t * const p_ctrl,
                                      void (                     * p_callback)(
                                          shared_memory_callback_args_t *),
                                      void * const                          p_context,
                                      shared_memory_callback_args_t * const p_callback_memory);
fsp_err_t R_SHARED_MEMORY_Close(shared_memory_ctrl_t * const p_ctrl);

/*******************************************************************************************************************//**
 * @} (end defgroup SHARED_MEMORY)
 ***********************************************************************************************************************/
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 // R_SHARED_MEMORY_H
