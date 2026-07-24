/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_TSU_H
 #define R_TSU_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include "r_tsu_cfg.h"
 #include "r_adc_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZN
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZN_TSU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** TSU instance control block. DO NOT INITIALIZE. Initialized in @ref RZN::adc_api_t::open(). */
struct st_tsu_instance_ctrl
{
    uint32_t open;                     // Boolean to verify that the Unit has been initialized
};

/** TSU instance control block. DO NOT INITIALIZE. Initialized in @ref RZN::adc_api_t::open(). Please refer to the struct st_tsu_instance_ctrl. */
typedef struct st_tsu_instance_ctrl tsu_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Interface Structure for user access */
extern const adc_api_t g_adc_on_tsu;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_TSU_Open(adc_ctrl_t * p_ctrl, adc_cfg_t const * const p_cfg);
fsp_err_t R_TSU_ScanStart(adc_ctrl_t * p_ctrl);
fsp_err_t R_TSU_ScanStop(adc_ctrl_t * p_ctrl);
fsp_err_t R_TSU_StatusGet(adc_ctrl_t * p_ctrl, adc_status_t * p_status);
fsp_err_t R_TSU_Read(adc_ctrl_t * p_ctrl, adc_channel_t const reg_id, uint16_t * const p_data);
fsp_err_t R_TSU_Close(adc_ctrl_t * p_ctrl);
fsp_err_t R_TSU_ScanCfg(adc_ctrl_t * p_ctrl, void const * const p_extend);
fsp_err_t R_TSU_ScanGroupStart(adc_ctrl_t * p_ctrl, adc_group_mask_t group_mask);
fsp_err_t R_TSU_Read32(adc_ctrl_t * p_ctrl, adc_channel_t const reg_id, uint32_t * const p_data);
fsp_err_t R_TSU_Calibrate(adc_ctrl_t * const p_ctrl, void const * p_extend);
fsp_err_t R_TSU_OffsetSet(adc_ctrl_t * const p_ctrl, adc_channel_t const reg_id, int32_t offset);
fsp_err_t R_TSU_CallbackSet(adc_ctrl_t * const          p_ctrl,
                            void (                    * p_callback)(adc_callback_args_t *),
                            void * const                p_context,
                            adc_callback_args_t * const p_callback_memory);
fsp_err_t R_TSU_InfoGet(adc_ctrl_t * p_ctrl, adc_info_t * p_adc_info);

/*******************************************************************************************************************//**
 * @} (end defgroup TSU)
 **********************************************************************************************************************/
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
