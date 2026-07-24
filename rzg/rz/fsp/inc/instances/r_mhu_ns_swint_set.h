/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_MHU_NS_SWINT_SET_H
 #define R_MHU_NS_SWINT_SET_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "r_mhu_ns_swint_set_api.h"
 #include "r_mhu_ns_swint_set_cfg.h"

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
 * @addtogroup RZG_MHU_NS_SWINT_SET
 * @{
 **********************************************************************************************************************/

/*************************************************************************************************
 * Type defines
 *************************************************************************************************/

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref mhu_ns_swint_set_api_t::open is called. */
struct st_mhu_ns_swint_set_instance_ctrl
{
    uint32_t open;                         ///< Indicates whether the open() API has been successfully called.
    mhu_ns_swint_set_cfg_t const * p_cfg;  ///< Pointer to instance configuration
    R_MHU_SWINT0_Type            * p_regs; ///< Base register for this channel

    uint32_t channel;                      ///< channel
};

/** Channel control block. DO NOT INITIALIZE. Initialization occurs when @ref mhu_ns_swint_set_api_t::open is called. Please refer to the struct st_mhu_ns_swint_set_instance_ctrl. */
typedef struct st_mhu_ns_swint_set_instance_ctrl mhu_ns_swint_set_instance_ctrl_t;

/** R_MHU_NS_SWINT_SET extended configuration */
struct st_mhu_ns_swint_set_extended_cfg
{
    void * p_reg;                      ///< Register base address for specified channel
};

/** R_MHU_NS_SWINT_SET extended configuration. Please refer to the struct st_mhu_ns_swint_set_extended_cfg. */
typedef struct st_mhu_ns_swint_set_extended_cfg mhu_ns_swint_set_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const mhu_ns_swint_set_api_t g_mhu_ns_swint_set_on_mhu_ns_swint_set;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_MHU_NS_SWINT_SET_Open(mhu_ns_swint_set_ctrl_t * p_ctrl, mhu_ns_swint_set_cfg_t const * const p_cfg);

fsp_err_t R_MHU_NS_SWINT_SET_InterruptSet(mhu_ns_swint_set_ctrl_t * const p_ctrl);

fsp_err_t R_MHU_NS_SWINT_SET_Close(mhu_ns_swint_set_ctrl_t * const p_ctrl);

/*******************************************************************************************************************//**
 * @} (end ingroup MHU_NS_SWINT_SET)
 **********************************************************************************************************************/
#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
