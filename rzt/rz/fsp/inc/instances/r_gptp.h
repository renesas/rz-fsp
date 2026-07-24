/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_GPTP_H
 #define R_GPTP_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"

 #include "r_gptp_cfg.h"
 #include "r_gptp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZT
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_GPTP
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** GPTP control block. DO NOT INITIALIZE.  Initialization occurs when @ref gptp_api_t::open is called. */
struct st_gptp_instance_ctrl
{
    uint32_t           open;                     ///< Indicates whether the open() API has been successfully called.
    gptp_cfg_t const * p_cfg;                    ///< Pointer to initial configurations.

    R_GPTP_Type * p_reg_gptp;                    ///< Pointer to GPTP timer register.

    void (* p_callback)(gptp_callback_args_t *); ///< Pointer to callback that is called.
    gptp_callback_args_t * p_callback_memory;    ///< Pointer to non-secure memory that can be used to pass arguments to a callback in non-secure memory.

    void const * p_context;                      ///< Pointer to context to be passed into callback function.
};

/** GPTP control block. DO NOT INITIALIZE.  Initialization occurs when @ref gptp_api_t::open is called. Please refer to the struct st_gptp_instance_ctrl. */
typedef struct st_gptp_instance_ctrl gptp_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const gptp_api_t g_gptp_on_gptp;

/** @endcond */

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/
fsp_err_t R_GPTP_Open(gptp_ctrl_t * const p_ctrl, gptp_cfg_t const * const p_cfg);

fsp_err_t R_GPTP_Close(gptp_ctrl_t * const p_ctrl);

fsp_err_t R_GPTP_TimerCfg(gptp_ctrl_t * const p_ctrl, uint8_t timer, gptp_timer_cfg_t const * const p_timer_cfg);

fsp_err_t R_GPTP_Start(gptp_ctrl_t * const p_ctrl, uint8_t timer);

fsp_err_t R_GPTP_Stop(gptp_ctrl_t * const p_ctrl, uint8_t timer);

fsp_err_t R_GPTP_TimerValueGet(gptp_ctrl_t * const p_ctrl, uint8_t timer, gptp_timer_value_t * const p_timer_value);

fsp_err_t R_GPTP_TimerOffsetSet(gptp_ctrl_t * const p_ctrl, uint8_t timer, int64_t offset);

fsp_err_t R_GPTP_TimerRateSet(gptp_ctrl_t * const p_ctrl, uint8_t timer, uint32_t rate);

fsp_err_t R_GPTP_CallbackSet(gptp_ctrl_t * const          p_ctrl,
                             void (                     * p_callback)(gptp_callback_args_t *),
                             void * const                 p_context,
                             gptp_callback_args_t * const p_callback_memory);

/*******************************************************************************************************************//**
 * @} (end addtogroup GPTP)
 **********************************************************************************************************************/
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 // R_GPTP_H
