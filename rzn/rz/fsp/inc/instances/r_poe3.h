/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_POE3_H
 #define R_POE3_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include "r_poe3_api.h"

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
 * @addtogroup RZN_POE3
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** High-impedance output mode */
typedef enum e_poe3_hiz_mode
{
    POE3_HIZ_MODE_FALLING_EDGE = 0,                           ///< Accepts a request on the falling edge of POE3 pin input.
    POE3_HIZ_MODE_CLOCK_SOURCE_DIV_8_16_TIME_PULSE_LOW   = 1, ///< Accepts a request when POE3 pin input has been sampled 16 times at clock source divided by 8 clock pulses and all are low level.
    POE3_HIZ_MODE_CLOCK_SOURCE_DIV_16_16_TIME_PULSE_LOW  = 2, ///< Accepts a request when POE3 pin input has been sampled 16 times at clock source divided by 16 clock pulses and all are low level.
    POE3_HIZ_MODE_CLOCK_SOURCE_DIV_128_16_TIME_PULSE_LOW = 3  ///< Accepts a request when POE3 pin input has been sampled 16 times at clock source divided by 128 clock pulses and all are low level.
} poe3_hiz_mode_t;

/** POEn# input signal setting */
struct st_poe3_poe_input_setting
{
    poe3_hiz_mode_t mode;              ///< High-impedance output mode
    bool            interrupt_enable;  ///< Interrupt enable
    bool            hiz_output_enable; ///< High-impedance output enable for POE8, POE10, POE11
};

/** POEn# input signal setting. Please refer to the struct st_poe3_poe_input_setting. */
typedef struct st_poe3_poe_input_setting poe3_poe_input_setting_t;

/** Extended configuration. */
struct st_poe3_extended_cfg
{
    poe3_poe_input_setting_t poe0;                     ///< Settings for the POE0# pin input
    poe3_poe_input_setting_t poe4;                     ///< Settings for the POE4# pin input
    poe3_poe_input_setting_t poe8;                     ///< Settings for the POE8# pin input
    poe3_poe_input_setting_t poe10;                    ///< Settings for the POE10# pin input
    poe3_poe_input_setting_t poe11;                    ///< Settings for the POE11# pin input

    uint32_t mtu0_control_channel_mask_trigger_pin;    ///< Additional MTU0 pin control request condition
    uint32_t mtu3_4_control_channel_mask_trigger_pin;  ///< Additional MTU3/4 pin control request condition
    uint32_t mtu6_7_control_channel_mask_trigger_pin;  ///< Additional MTU6/7 pin control request condition

    uint32_t mtu0_control_channel_mask_dsmif_error0;   ///< Additional MTU0 pin control dsmif error 0 request condition
    uint32_t mtu3_4_control_channel_mask_dsmif_error0; ///< Additional MTU3/4 pin control dsmif error 0 request condition
    uint32_t mtu6_7_control_channel_mask_dsmif_error0; ///< Additional MTU6/7 pin control dsmif error 0 request condition
    uint32_t mtu0_control_channel_mask_dsmif_error1;   ///< Additional MTU0 pin control dsmif error 1 request condition
    uint32_t mtu3_4_control_channel_mask_dsmif_error1; ///< Additional MTU3/4 pin control dsmif error 1 request condition
    uint32_t mtu6_7_control_channel_mask_dsmif_error1; ///< Additional MTU6/7 pin control dsmif error 1 request condition

    bool dsmif0_error;                                 ///< High impedance output when the DSMIF0 is error
    bool dsmif1_error;                                 ///< High impedance output when the DSMIF1 is error
 #if 3 == BSP_FEATURE_POE3_ERROR_SIGNAL_TYPE
    bool dsmif2_error;                                 ///< High impedance output when the DSMIF2 Error 0 is error
    bool dsmif3_error;                                 ///< High impedance output when the DSMIF3 Error 0 is error
    bool dsmif4_error;                                 ///< High impedance output when the DSMIF4 Error 0 is error
    bool dsmif5_error;                                 ///< High impedance output when the DSMIF5 Error 0 is error
    bool dsmif7_error;                                 ///< High impedance output when the DSMIF7 Error 0 is error
    bool dsmif8_error;                                 ///< High impedance output when the DSMIF8 Error 0 is error
    bool dsmif0_error_1;                               ///< High impedance output when the DSMIF0 Error 1 is error
    bool dsmif1_error_1;                               ///< High impedance output when the DSMIF1 Error 1 is error
    bool dsmif2_error_1;                               ///< High impedance output when the DSMIF2 Error 1 is error
    bool dsmif3_error_1;                               ///< High impedance output when the DSMIF3 Error 1 is error
    bool dsmif4_error_1;                               ///< High impedance output when the DSMIF4 Error 1 is error
    bool dsmif5_error_1;                               ///< High impedance output when the DSMIF5 Error 1 is error
    bool dsmif7_error_1;                               ///< High impedance output when the DSMIF7 Error 1 is error
    bool dsmif8_error_1;                               ///< High impedance output when the DSMIF8 Error 1 is error
 #endif
    uint8_t   oei1_ipl;                                ///< Output Enable Interrupt 1 interrupt priority
    IRQn_Type oei1_irq;                                ///< Output Enable Interrupt 1 interrupt number assigned to this instance
    uint8_t   oei2_ipl;                                ///< Output Enable Interrupt 2 interrupt priority
    IRQn_Type oei2_irq;                                ///< Output Enable Interrupt 2 interrupt number assigned to this instance
    uint8_t   oei3_ipl;                                ///< Output Enable Interrupt 3 interrupt priority
    IRQn_Type oei3_irq;                                ///< Output Enable Interrupt 3 interrupt number assigned to this instance
    uint8_t   oei4_ipl;                                ///< Output Enable Interrupt 4 interrupt priority
    IRQn_Type oei4_irq;                                ///< Output Enable Interrupt 4 interrupt number assigned to this instance

    void * p_reg;                                      ///< Register base address
};

/** Extended configuration. Please refer to the struct st_poe3_extended_cfg. */
typedef struct st_poe3_extended_cfg poe3_extended_cfg_t;

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref RZN::poe3_api_t::open is called. */
struct st_poe3_instance_ctrl
{
    uint32_t           open;                     // Whether or not channel is open
    const poe3_cfg_t * p_cfg;                    // Pointer to initial configurations
    R_POE3_Type      * p_reg;                    // Base register for this channel

    void (* p_callback)(poe3_callback_args_t *); // Pointer to callback
    poe3_callback_args_t * p_callback_memory;    // Pointer to optional callback argument memory
    void                 * p_context;            // Pointer to context to be passed into callback function
};

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref RZN::poe3_api_t::open is called. Please refer to the struct st_poe3_instance_ctrl. */
typedef struct st_poe3_instance_ctrl poe3_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const poe3_api_t g_poe30_on_poe3;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_POE3_Open(poe3_ctrl_t * const p_ctrl, poe3_cfg_t const * const p_cfg);
fsp_err_t R_POE3_OutputDisable(poe3_ctrl_t * const p_ctrl);
fsp_err_t R_POE3_Reset(poe3_ctrl_t * const p_ctrl);
fsp_err_t R_POE3_StatusGet(poe3_ctrl_t * const p_ctrl, poe3_status_t * const p_status);
fsp_err_t R_POE3_Close(poe3_ctrl_t * const p_ctrl);
fsp_err_t R_POE3_CallbackSet(poe3_ctrl_t * const          p_ctrl,
                             void (                     * p_callback)(poe3_callback_args_t *),
                             void * const                 p_context,
                             poe3_callback_args_t * const p_callback_memory);

/*******************************************************************************************************************//**
 * @} (end defgroup POE3)
 **********************************************************************************************************************/
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
