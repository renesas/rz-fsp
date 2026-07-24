/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_MHU_NS_SWINT_GET_H
 #define R_MHU_NS_SWINT_GET_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "r_mhu_ns_swint_get_api.h"
 #include "r_mhu_ns_swint_get_cfg.h"

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
 * @addtogroup RZV_MHU_NS_SWINT_GET
 * @{
 **********************************************************************************************************************/

/*************************************************************************************************
 * Type defines
 *************************************************************************************************/

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref mhu_ns_swint_get_api_t::open is called. */
struct st_mhu_ns_swint_get_instance_ctrl
{
    uint32_t open;                         ///< Indicates whether the open() API has been successfully called.
    mhu_ns_swint_get_cfg_t const * p_cfg;  ///< Pointer to instance configuration
    R_MHU_SWINT0_Type            * p_regs; ///< Base register for this channel

    uint32_t channel;                      ///< channel

 #if BSP_TZ_SECURE_BUILD
    bool callback_is_secure;               ///< p_callback is in secure memory
 #endif

    /* Pointer to callback and optional working memory */
    void (* p_callback)(mhu_ns_swint_get_callback_args_t *);
    mhu_ns_swint_get_callback_args_t * p_callback_memory; // Pointer to non-secure memory that can be used to pass arguments to a callback in non-secure memory.
    void * p_context;                                     // Pointer to context to be passed into callback function
};

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref mhu_ns_swint_get_api_t::open is called. Please refer to the struct st_mhu_ns_swint_get_instance_ctrl. */
typedef struct st_mhu_ns_swint_get_instance_ctrl mhu_ns_swint_get_instance_ctrl_t;

/** R_MHU_NS_SWINT_GET extended configuration */
struct st_mhu_ns_swint_get_extended_cfg
{
    void * p_reg;                      ///< Register base address for specified channel
};

/** R_MHU_NS_SWINT_GET extended configuration. Please refer to the struct st_mhu_ns_swint_get_extended_cfg. */
typedef struct st_mhu_ns_swint_get_extended_cfg mhu_ns_swint_get_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const mhu_ns_swint_get_api_t g_mhu_ns_swint_get_on_mhu_ns_swint_get;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_MHU_NS_SWINT_GET_Open(mhu_ns_swint_get_ctrl_t * p_ctrl, mhu_ns_swint_get_cfg_t const * const p_cfg);

fsp_err_t R_MHU_NS_SWINT_GET_Close(mhu_ns_swint_get_ctrl_t * const p_ctrl);

fsp_err_t R_MHU_NS_SWINT_GET_CallbackSet(mhu_ns_swint_get_ctrl_t * const p_api_ctrl,
                                         void (                        * p_callback)(
                                             mhu_ns_swint_get_callback_args_t *),
                                         void * const                             p_context,
                                         mhu_ns_swint_get_callback_args_t * const p_callback_memory);

void R_MHU_NS_SWINT_GET_IsrSub(uint32_t irq);

/*******************************************************************************************************************//**
 * @} (end ingroup MHU_NS_SWINT_GET)
 **********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
