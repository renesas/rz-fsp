/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_RTC_H
 #define R_RTC_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include "r_rtc_cfg.h"
 #include "r_rtc_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Counting mode */
 #define RTC_CALENDAR_MODE    (0)

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZV
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZV_RTC
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** RTC Clock Bypass Mode */
typedef enum e_rtc_clock_bypass_mode
{
    CRYSTAL_OSCILLATOR_MODE,
    EXTERNAL_CLOCK_RECEIVE_MODE,
} rtc_clock_bypass_mode_t;

/** RTC extend configuration */
struct st_rtc_extended_cfg
{
    uint8_t                 alarm1_ipl;        ///< Alarm 1 interrupt priority
    IRQn_Type               alarm1_irq;        ///< Alarm 1 interrupt vector
    rtc_clock_bypass_mode_t clock_bypass_mode; ///< Clock Bypass Mode
};

/** RTC extend configuration. Please refer to the struct st_rtc_extended_cfg. */
typedef struct st_rtc_extended_cfg rtc_extended_cfg_t;

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref rtc_api_t::open is called */
struct st_rtc_ctrl
{
    uint32_t          open;                     ///< Whether or not driver is open
    const rtc_cfg_t * p_cfg;                    ///< Pointer to initial configurations
    volatile bool     carry_isr_triggered;      ///< Was the carry isr triggered

    void (* p_callback)(rtc_callback_args_t *); // Pointer to callback that is called when a rtc_event_t occurs.
    rtc_callback_args_t * p_callback_memory;    // Pointer to non-secure memory that can be used to pass arguments to a callback in non-secure memory.

    void * p_context;                           // Pointer to context to be passed into callback function
};

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref rtc_api_t::open is called. Please refer to the struct st_rtc_ctrl. */
typedef struct st_rtc_ctrl rtc_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const rtc_api_t g_rtc_on_rtc;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_RTC_Open(rtc_ctrl_t * const p_ctrl, rtc_cfg_t const * const p_cfg);
fsp_err_t R_RTC_Close(rtc_ctrl_t * const p_ctrl);
fsp_err_t R_RTC_ClockSourceSet(rtc_ctrl_t * const p_ctrl);
fsp_err_t R_RTC_CalendarTimeSet(rtc_ctrl_t * const p_ctrl, rtc_time_t * const p_time);
fsp_err_t R_RTC_CalendarTimeGet(rtc_ctrl_t * const p_ctrl, rtc_time_t * const p_time);
fsp_err_t R_RTC_CalendarAlarmSet(rtc_ctrl_t * const p_ctrl, rtc_alarm_time_t * const p_alarm);
fsp_err_t R_RTC_CalendarAlarmGet(rtc_ctrl_t * const p_ctrl, rtc_alarm_time_t * const p_alarm);
fsp_err_t R_RTC_PeriodicIrqRateSet(rtc_ctrl_t * const p_ctrl, rtc_periodic_irq_select_t const rate);
fsp_err_t R_RTC_ErrorAdjustmentSet(rtc_ctrl_t * const p_ctrl, rtc_error_adjustment_cfg_t const * const err_adj_cfg);
fsp_err_t R_RTC_InfoGet(rtc_ctrl_t * const p_ctrl, rtc_info_t * const p_rtc_info);
fsp_err_t R_RTC_CallbackSet(rtc_ctrl_t * const          p_ctrl,
                            void (                    * p_callback)(rtc_callback_args_t *),
                            void * const                p_context,
                            rtc_callback_args_t * const p_callback_memory);
fsp_err_t R_RTC_TimeCaptureSet(rtc_ctrl_t * const p_ctrl, rtc_time_capture_t * const p_time_capture);
fsp_err_t R_RTC_TimeCaptureGet(rtc_ctrl_t * const p_ctrl, rtc_time_capture_t * const p_time_capture);

/*******************************************************************************************************************//**
 * @} (end addtogroup RTC)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 // R_RTC_H
