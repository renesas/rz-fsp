/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @ingroup RENESAS_TIMERS_INTERFACES
 * @defgroup POE3_API POE3 Interface
 *
 * @brief Interface for the Port Output Enable 3.
 *
 * Defines the API and data structures for the Port Output Enable 3 interface.
 *
 * @section POE3_API_SUMMARY Summary
 * @brief The POE3 disables timer output pins based on configurable events.
 *
 *
 * @{
 **********************************************************************************************************************/

#ifndef R_POE3_API_H
#define R_POE3_API_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Register definitions, common services and error codes. */
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
#ifndef BSP_OVERRIDE_POE3_STATE_T

/** POE3 states. */
typedef enum e_poe3_state
{
    POE3_STATE_NO_DISABLE_REQUEST           = 0,                ///< Timer output is not disabled by POE3
    POE3_STATE_POE0_HIGH_IMPEDANCE_REQUEST  = 1U,               ///< Timer output disabled due to POE0# pin
    POE3_STATE_POE4_HIGH_IMPEDANCE_REQUEST  = 1U << 1,          ///< Timer output disabled due to POE4# pin
    POE3_STATE_POE8_HIGH_IMPEDANCE_REQUEST  = 1U << 2,          ///< Timer output disabled due to POE8# pin
    POE3_STATE_POE10_HIGH_IMPEDANCE_REQUEST = 1U << 3,          ///< Timer output disabled due to POE10# pin
    POE3_STATE_POE11_HIGH_IMPEDANCE_REQUEST = 1U << 4,          ///< Timer output disabled due to POE11# pin

    POE3_STATE_SOFTWARE_STOP_DISABLE_REQUEST    = 1U << 5,      ///< Timer output disabled due to poe3_api_t::outputDisable()
    POE3_STATE_OSCILLATION_STOP_DISABLE_REQUEST = 1U << 6,      ///< Timer output disabled due to main oscillator stop

    POE3_STATE_OUTPUT_SHORT_CIRCUIT_1_ERROR_REQUEST = 1U << 9,  ///< Timer output disabled due to output short circuit 1
    POE3_STATE_OUTPUT_SHORT_CIRCUIT_2_ERROR_REQUEST = 1U << 10, ///< Timer output disabled due to output short circuit 2
} poe3_state_t;

#endif

#ifndef BSP_OVERRIDE_POE3_ACTIVE_LEVEL_T

/** Active level for short circuit detection. */
typedef enum e_poe3_active_level
{
    POE3_ACTIVE_LEVEL_HIGH         = 0U,    ///< High level is set as the active level to detect a short circuit.
    POE3_ACTIVE_LEVEL_LOW          = 1U,    ///< Low level is set as the active level to detect a short circuit.
    POE3_ACTIVE_LEVEL_SETTING_NONE = 0xFFU, ///< The active level of the pin is set by the timer peripheral side, not by POE3.
} poe3_active_level_t;

#endif

/** Timer Control Pin selection */
typedef enum e_poe3_pin_select
{
    POE3_PIN_SELECT_0 = 0U,            ///< Select pin to control. Refer to the user's manual of each device for details.
    POE3_PIN_SELECT_1 = 1U,            ///< Select pin to control. Refer to the user's manual of each device for details.
    POE3_PIN_SELECT_2 = 2U,            ///< Select pin to control. Refer to the user's manual of each device for details.
    POE3_PIN_SELECT_3 = 3U,            ///< Select pin to control. Refer to the user's manual of each device for details.
    POE3_PIN_SELECT_4 = 4U,            ///< Select pin to control. Refer to the user's manual of each device for details.
    POE3_PIN_SELECT_5 = 5U,            ///< Select pin to control. Refer to the user's manual of each device for details.
    POE3_PIN_SELECT_6 = 6U,            ///< Select pin to control. Refer to the user's manual of each device for details.
    POE3_PIN_SELECT_7 = 7U             ///< Select pin to control. Refer to the user's manual of each device for details.
} poe3_pin_select_t;

/** Timer PWM Output pin control setting */
typedef struct st_poe3_pwm_pin_setting
{
    poe3_pin_select_t pwm_pin_select;    ///< PWM Pin Select
    bool              hiz_output_enable; ///< High-impedance output enable
} poe3_pwm_pin_setting_t;

/** Timer Complementary PWM Output pin control setting */
typedef struct st_poe3_complementary_pwm_pin_setting
{
    poe3_pin_select_t   positive_pwm_pin_select;       ///< Positive PWM Pin Select
    poe3_pin_select_t   negative_pwm_pin_select;       ///< Negative PWM Pin Select
    poe3_active_level_t positive_pwm_pin_active_level; ///< Active level Positive PWM pin for short circuit detection
    poe3_active_level_t negative_pwm_pin_active_level; ///< Active level Negative PWM pin for short circuit detection
    bool                hiz_output_enable;             ///< High-impedance output enable
} poe3_complementary_pwm_pin_setting_t;

/** Timer Complementary PWM control setting */
typedef struct st_poe3_complementary_pwm_setting_t
{
    poe3_complementary_pwm_pin_setting_t pin_setting[3]; ///< Complementary PWM pin setting
} poe3_complementary_pwm_setting_t;

/** Output short circuit setting. */
typedef struct st_poe3_output_short_circuit_setting
{
    bool interrupt_enable;             ///< Interrupt enable
    bool hiz_output_enable;            ///< High-impedance output enable
} poe3_output_short_circuit_setting_t;

/** POE3 status */
typedef struct st_poe3_status
{
    poe3_state_t state;                ///< Current state of POE3
} poe3_status_t;

/** Callback function parameter data. */
typedef struct st_poe3_callback_args
{
    void * p_context;                  ///< Placeholder for user data, set in @ref poe3_cfg_t.
} poe3_callback_args_t;

/** POE3 control block.  Allocate an instance specific control block to pass into the POE3 API calls.
 */
typedef void poe3_ctrl_t;

/** User configuration structure, used in the open function. */
typedef struct st_poe3_cfg
{
    uint32_t pwm_pin;                                                         ///< Length of PWM pin settings.
    poe3_pwm_pin_setting_t const * p_pwm_pin_setting;                         ///< Settings for PWM pin.

    uint32_t complementary_pwm_pin;                                           ///< Length of complementary PWM pin settings.
    poe3_complementary_pwm_setting_t const * p_complementary_pwm_pin_setting; ///< Settings for complementary PWM pin.

    uint32_t short_circuit;                                                   ///< Length of short circuit settings.
    poe3_output_short_circuit_setting_t const * p_short_circuit_setting;      ///< High impedance output when the output short circuit.

    bool oscillation_stop_hiz_output_enable;                                  ///< High-impedance output when the oscillator is stopped.

    /** Callback called when a POE3 interrupt occurs. */
    void (* p_callback)(poe3_callback_args_t * p_args);

    /** Placeholder for user data. Passed to the user callback in @ref poe3_callback_args_t. */
    void       * p_context;
    void const * p_extend;             ///< Extension parameter for hardware specific settings.
} poe3_cfg_t;

/** Port Output Enable 3 API structure. POE3 functions implemented at the HAL layer will follow this API. */
typedef struct st_poe3_api
{
    /** Initial configuration.
     *
     * @param[in]   p_ctrl      Pointer to control block. Must be declared by user. Elements set here.
     * @param[in]   p_cfg       Pointer to configuration structure. All elements of this structure must be set by user.
     */
    fsp_err_t (* open)(poe3_ctrl_t * const p_ctrl, poe3_cfg_t const * const p_cfg);

    /** Gets the current driver state.
     *
     * @param[in]   p_ctrl      Control block set in @ref poe3_api_t::open call.
     * @param[out]  p_status    Provides the current state of the POE3.
     */
    fsp_err_t (* statusGet)(poe3_ctrl_t * const p_ctrl, poe3_status_t * p_status);

    /** Disables timer output pins by software request.
     *
     * @param[in]   p_ctrl      Control block set in @ref poe3_api_t::open call.
     */
    fsp_err_t (* outputDisable)(poe3_ctrl_t * const p_ctrl);

    /** Attempts to clear status flags to reenable timer output pins. Confirm all status flags are cleared after calling
     * this function by calling poe3_api_t::statusGet().
     *
     * @param[in]   p_ctrl      Control block set in @ref poe3_api_t::open call.
     */
    fsp_err_t (* reset)(poe3_ctrl_t * const p_ctrl);

    /** Disables POE3 interrupt.
     *
     * @param[in]   p_ctrl      Control block set in @ref poe3_api_t::open call.
     */
    fsp_err_t (* close)(poe3_ctrl_t * const p_ctrl);

    /** Specify callback function and optional context pointer and working memory pointer.
     *
     * @param[in]   p_ctrl                   Control block set in @ref poe3_api_t::open call for this timer.
     * @param[in]   p_callback               Callback function to register
     * @param[in]   p_context                Pointer to send to callback function
     * @param[in]   p_callback_memory        Pointer to volatile memory where callback structure can be allocated.
     *                                       Callback arguments allocated here are only valid during the callback.
     */
    fsp_err_t (* callbackSet)(poe3_ctrl_t * const p_ctrl, void (* p_callback)(poe3_callback_args_t *),
                              void * const p_context, poe3_callback_args_t * const p_callback_memory);
} poe3_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_poe3_instance
{
    poe3_ctrl_t      * p_ctrl;         ///< Pointer to the control structure for this instance
    poe3_cfg_t const * p_cfg;          ///< Pointer to the configuration structure for this instance
    poe3_api_t const * p_api;          ///< Pointer to the API structure for this instance
} poe3_instance_t;

/*******************************************************************************************************************//**
 * @} (end defgroup POE3_API)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
