/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_POEG_H
 #define R_POEG_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include "r_poeg_cfg.h"
 #include "r_poeg_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZG
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZG_POEG
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref poeg_api_t::open is called. */
struct st_poeg_instance_ctrl
{
    uint32_t           open;                     // Whether or not channel is open
    const poeg_cfg_t * p_cfg;                    // Pointer to initial configurations
    R_POEGA_Type     * p_reg;                    // Base register for this channel
    R_GPT0_Type      * p_gpt_reg;                // Base register for GPT channel link with POEG

    void (* p_callback)(poeg_callback_args_t *); // Pointer to callback
    poeg_callback_args_t * p_callback_memory;    // Pointer to optional callback argument memory
    void                 * p_context;            // Pointer to context to be passed into callback function
};

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref poeg_api_t::open is called. Please refer to the struct st_poeg_instance_ctrl. */
typedef struct st_poeg_instance_ctrl poeg_instance_ctrl_t;

/** POEG extended configuration */
struct st_poeg_extended_cfg
{
    void * p_reg;                      // Register base address for specified channel
};

/** POEG extended configuration. Please refer to the struct st_poeg_extended_cfg. */
typedef struct st_poeg_extended_cfg poeg_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const poeg_api_t g_poeg_on_poeg;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_POEG_Open(poeg_ctrl_t * const p_ctrl, poeg_cfg_t const * const p_cfg);
fsp_err_t R_POEG_StatusGet(poeg_ctrl_t * const p_ctrl, poeg_status_t * const p_status);
fsp_err_t R_POEG_CallbackSet(poeg_ctrl_t * const          p_ctrl,
                             void (                     * p_callback)(poeg_callback_args_t *),
                             void * const                 p_context,
                             poeg_callback_args_t * const p_callback_memory);
fsp_err_t R_POEG_OutputDisable(poeg_ctrl_t * const p_ctrl);
fsp_err_t R_POEG_Reset(poeg_ctrl_t * const p_ctrl);
fsp_err_t R_POEG_Close(poeg_ctrl_t * const p_ctrl);

/*******************************************************************************************************************//**
 * @} (end defgroup POEG)
 **********************************************************************************************************************/
#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
