/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_MTU3_THREE_PHASE_H
 #define R_MTU3_THREE_PHASE_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include "r_three_phase_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZT
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_MTU3_THREE_PHASE
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Complementary PWM Mode */
typedef enum e_mtu3_three_phase_pwm_mode
{
    MTU3_THREE_PHASE_PWM_MODE_1 = 0,   ///< transfer at crest
    MTU3_THREE_PHASE_PWM_MODE_2 = 1,   ///< transfer at trough
    MTU3_THREE_PHASE_PWM_MODE_3 = 2    ///< transfer at crest and trough
} mtu3_three_phase_pwm_mode_t;

/** PWM Synchronous Output Enable */
typedef enum  e_mtu3_three_phase_psye
{
    MTU3_THREE_PHASE_PSYE_NO_SIGNAL,   ///< toggle output is disabled.
    MTU3_THREE_PHASE_PSYE_TOGGLE       ///< toggle output is enabled.
} mtu3_three_phase_psye_t;

/** OUTPUT LEVEL */
typedef enum  e_mtu3_three_phase_output_level
{
    MTU3_THREE_PHASE_OUTPUT_LEVEL_ACTIVE_LOW  = 0, ///< Active level is LOW
    MTU3_THREE_PHASE_OUTPUT_LEVEL_ACTIVE_HIGH = 1  ///< Active level is HIGH
} mtu3_three_phase_output_level_t;

/** Timer Synchronous */
typedef enum e_mtu3_three_phase_synchronous_channel
{
    MTU3_THREE_PHASE_SYNCHRONOUS_CHANNEL_DISABLE = 0, ///< No Synchronous Register
    MTU3_THREE_PHASE_SYNCHRONOUS_CHANNEL_0       = 1, ///< Synchronous register is MTU0
    MTU3_THREE_PHASE_SYNCHRONOUS_CHANNEL_1       = 2, ///< Synchronous register is MTU1
    MTU3_THREE_PHASE_SYNCHRONOUS_CHANNEL_2       = 3, ///< Synchronous register is MTU2
    MTU3_THREE_PHASE_SYNCHRONOUS_CHANNEL_3       = 4, ///< Synchronous register is MTU3
    MTU3_THREE_PHASE_SYNCHRONOUS_CHANNEL_4       = 5, ///< Synchronous register is MTU4
    MTU3_THREE_PHASE_SYNCHRONOUS_CHANNEL_6       = 6, ///< Synchronous register is MTU6
    MTU3_THREE_PHASE_SYNCHRONOUS_CHANNEL_7       = 7  ///< Synchronous register is MTU7
} mtu3_three_phase_synchronous_channel_t;

/** MTU3 THREE PHASE extension features. */
struct st_mtu3_three_phase_extend_cfg
{
    mtu3_three_phase_pwm_mode_t pwm_mode;
    uint16_t                               period_half;    ///< Period in raw timer counts / 2
    uint16_t                               dead_time;      ///< dead time counts. if dead_time=0 , no dead time is generated
    uint16_t                               duty_val[3];    ///< Duty value for MTU3(6).TGRB(D), MTU4(7).TGRA(C), MTU4(7).TGRB(D)
    mtu3_three_phase_psye_t                period_out;     ///< MTIOC3(6)A Toggle output is disabled/enabled
    mtu3_three_phase_output_level_t        level;          ///< double buffer Duty
    uint16_t                               duty_double[3]; ///< if double buffer , Duty value for MTU3(6).TGRDE, MTU4(7).TGRCE, MTU4(7).TGRDF
    mtu3_three_phase_synchronous_channel_t sync;           ///< Synchronous ch
};

/** MTU3 THREE PHASE extension features. Please refer to the struct st_mtu3_three_phase_extend_cfg. */
typedef struct st_mtu3_three_phase_extend_cfg mtu3_three_phase_extended_cfg_t;

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref RZT::three_phase_api_t::open is called. */
struct st_mtu3_three_phase_instance_ctrl
{
    uint32_t                  open;        ///< Whether or not channel is open
    void                    * p_reg[2];    ///< Base register for PWM channels : MTU3/4 or MTU6/7
    R_MTU_Type              * p_reg_com;   ///< Base register for this channel(common ch)
    uint32_t                  channel;     ///< Channel of MTU3 channels used : MTU3 or MTU6
    three_phase_buffer_mode_t buffer_mode; ///< Single- or double-buffer mode
    three_phase_cfg_t const * p_cfg;       ///< Pointer to initial configurations
};

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref RZT::three_phase_api_t::open is called. Please refer to the struct st_mtu3_three_phase_instance_ctrl. */
typedef struct st_mtu3_three_phase_instance_ctrl mtu3_three_phase_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const three_phase_api_t g_three_phase_on_mtu3_three_phase;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_MTU3_THREE_PHASE_Open(three_phase_ctrl_t * const p_ctrl, three_phase_cfg_t const * const p_cfg);
fsp_err_t R_MTU3_THREE_PHASE_Stop(three_phase_ctrl_t * const p_ctrl);
fsp_err_t R_MTU3_THREE_PHASE_Start(three_phase_ctrl_t * const p_ctrl);
fsp_err_t R_MTU3_THREE_PHASE_Reset(three_phase_ctrl_t * const p_ctrl);
fsp_err_t R_MTU3_THREE_PHASE_DutyCycleSet(three_phase_ctrl_t * const       p_ctrl,
                                          three_phase_duty_cycle_t * const p_duty_cycle);
fsp_err_t R_MTU3_THREE_PHASE_CallbackSet(three_phase_ctrl_t * const    p_ctrl,
                                         void (                      * p_callback)(timer_callback_args_t *),
                                         void * const                  p_context,
                                         timer_callback_args_t * const p_callback_memory);
fsp_err_t R_MTU3_THREE_PHASE_Close(three_phase_ctrl_t * const p_ctrl);

/*******************************************************************************************************************//**
 * @} (end defgroup MTU3_THREE_PHASE)
 **********************************************************************************************************************/
#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
