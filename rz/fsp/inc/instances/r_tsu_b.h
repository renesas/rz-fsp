/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_TSU_B_H
 #define R_TSU_B_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include "r_tsu_b_cfg.h"
 #include "r_adc_api.h"

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
 * @addtogroup RZV_TSU_B
 * @{
 **********************************************************************************************************************/

/** TSU_B data sample addition and averaging options */
typedef enum e_tsu_b_average
{
    TSU_B_AVERAGE_OFF   = 0,           ///< Latest read data
    TSU_B_AVERAGE_TWO   = 1,           ///< Average two samples
    TSU_B_AVERAGE_FOUR  = 2,           ///< Average four samples
    TSU_B_AVERAGE_EIGHT = 3,           ///< Average eight samples
} tsu_b_average_t;

/** TSU_B comparison settings */
typedef enum e_tsu_b_compare_cfg
{
    TSU_B_COMPARE_CFG_DISABLE = 0,     ///< Compare function is disabled
    TSU_B_COMPARE_CFG_OUTSIDE = 1,     ///< Comparison Mode: Outside
    TSU_B_COMPARE_CFG_INSIDE  = 3,     ///< Comparison Mode: Inside
} tsu_b_compare_cfg_t;

/** Extended configuration structure for ADC. */
struct st_tsu_b_extended_cfg
{
    tsu_b_average_t     average_count;    ///< Average counts
    tsu_b_compare_cfg_t comparison_mode;  ///< TSU_B compare function configuration
    int16_t             compare_ref_low;  ///< Lower reference value
    int16_t             compare_ref_high; ///< Upper reference value
    IRQn_Type           compare_irq;      ///< IRQ number for Comparison Result Interrupts
    uint8_t             compare_ipl;      ///< Priority for Comparison Result Interrupts
    void              * p_reg;            ///< Register base address for specified channel
};

/** Extended configuration structure for ADC. Please refer to the struct st_tsu_b_extended_cfg. */
typedef struct st_tsu_b_extended_cfg tsu_b_extended_cfg_t;

/** TSU_B instance control block. DO NOT INITIALIZE. Initialized in @ref adc_api_t::open(). */
struct st_tsu_b_instance_ctrl
{
    R_TSU_B0_Type       * p_reg;                                 // Base register
    adc_cfg_t const     * p_cfg;
    uint32_t              open;                                  // Boolean to verify that the Unit has been initialized
    uint32_t              initialized;                           // Initialized status of TSU_B
    void                  (* p_callback)(adc_callback_args_t *); // Pointer to callback that is called when an adc_event_t occurs.
    adc_callback_args_t * p_callback_memory;                     // Pointer to non-secure memory that can be used to pass arguments to a callback in non-secure memory.

    /* Pointer to context to be passed into callback function */
    void * p_context;
};

/** TSU_B instance control block. DO NOT INITIALIZE. Initialized in @ref adc_api_t::open(). Please refer to the struct st_tsu_b_instance_ctrl. */
typedef struct st_tsu_b_instance_ctrl tsu_b_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Interface Structure for user access */
extern const adc_api_t g_adc_on_tsu_b;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_TSU_B_Open(adc_ctrl_t * p_ctrl, adc_cfg_t const * const p_cfg);
fsp_err_t R_TSU_B_ScanCfg(adc_ctrl_t * p_ctrl, void const * const p_channel_cfg);
fsp_err_t R_TSU_B_ScanStart(adc_ctrl_t * p_ctrl);
fsp_err_t R_TSU_B_ScanGroupStart(adc_ctrl_t * p_ctrl, adc_group_mask_t group_id);
fsp_err_t R_TSU_B_ScanStop(adc_ctrl_t * p_ctrl);
fsp_err_t R_TSU_B_StatusGet(adc_ctrl_t * p_ctrl, adc_status_t * p_status);
fsp_err_t R_TSU_B_Read(adc_ctrl_t * p_ctrl, adc_channel_t const reg_id, uint16_t * const p_data);
fsp_err_t R_TSU_B_Read32(adc_ctrl_t * p_ctrl, adc_channel_t const reg_id, uint32_t * const p_data);
fsp_err_t R_TSU_B_Close(adc_ctrl_t * p_ctrl);
fsp_err_t R_TSU_B_InfoGet(adc_ctrl_t * p_ctrl, adc_info_t * p_adc_info);
fsp_err_t R_TSU_B_Calibrate(adc_ctrl_t * const p_ctrl, void const * p_extend);
fsp_err_t R_TSU_B_OffsetSet(adc_ctrl_t * const p_ctrl, adc_channel_t const reg_id, int32_t offset);
fsp_err_t R_TSU_B_CallbackSet(adc_ctrl_t * const          p_api_ctrl,
                              void (                    * p_callback)(adc_callback_args_t *),
                              void * const                p_context,
                              adc_callback_args_t * const p_callback_memory);
fsp_err_t R_TSU_B_CalculateTemperature(adc_ctrl_t * p_ctrl, uint16_t temperature_code, float * const p_temperature);

/*******************************************************************************************************************//**
 * @} (end defgroup TSU_B)
 **********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
