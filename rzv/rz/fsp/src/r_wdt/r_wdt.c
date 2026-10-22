/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_wdt.h"
#include "bsp_api.h"
#include "bsp_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define WDT_OPEN    (0X00574454ULL)

/* Lookup functions for WDT settings.  Using function like macro for stringification. */
#define WDT_PRV_WDTCR_SETTING_GET(setting,                                                   \
                                  wdtcr)    (((wdtcr >> WDT_PRV_WDTCR_ ## setting ## _BIT) & \
                                              WDT_PRV_WDTCR_ ## setting ## _MASK));
#define WDT_PRV_WDTCR_SETTING_SET(setting,                                                   \
                                  value)    ((value & WDT_PRV_WDTCR_ ## setting ## _MASK) << \
                                             WDT_PRV_WDTCR_ ## setting ## _BIT);

/* WDT register settings. */
#define WDT_PRV_WDTSR_COUNTER_MASK              (0x3FFFU)
#define WDT_PRV_WDTSR_FLAGS_MASK                (0xC000U)

#define WDT_PRV_WDTCR_TIMEOUT_BIT               (0)
#define WDT_PRV_WDTCR_CLOCK_DIVISION_BIT        (4)
#define WDT_PRV_WDTCR_WINDOW_END_BIT            (8)
#define WDT_PRV_WDTCR_WINDOW_START_BIT          (12)

#define WDT_PRV_WDTRCR_RESET_CONTROL_BIT        (7)

#define WDT_PRV_WDTCR_TIMEOUT_MASK              (0x3U) // Bits 0-1
#define WDT_PRV_WDTCR_CLOCK_DIVISION_MASK       (0xFU) // Bits 4-7
#define WDT_PRV_WDTCR_WINDOW_END_MASK           (0x3U) // Bits 8-9
#define WDT_PRV_WDTCR_WINDOW_START_MASK         (0x3U) // Bits 12-13

/* Refresh register values */
#define WDT_PRV_REFRESH_STEP_1                  (0U)
#define WDT_PRV_REFRESH_STEP_2                  (0xFFU)

/* Reset Interrupt Request Select value */
#define WDT_PRV_ERROR_NOTIFICATION_PERMITTED    (0U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
typedef void (BSP_CMSE_NONSECURE_CALL * wdt_prv_ns_callback)(wdt_callback_args_t * p_args);
#elif defined(__GNUC__)
typedef BSP_CMSE_NONSECURE_CALL void (*volatile wdt_prv_ns_callback)(wdt_callback_args_t * p_args);
#endif

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
void wdt_underflow_isr(void);

static uint32_t r_wdt_clock_divider_get(wdt_clock_division_t division);

static fsp_err_t r_wdt_parameter_checking(wdt_instance_ctrl_t * const p_instance_ctrl, wdt_cfg_t const * const p_cfg);

static void r_wdt_underflow_callback(wdt_instance_ctrl_t * p_ctrl);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

static const uint8_t g_wdtcr_timeout[] =
{
    0xFFU,                             // WDTCR value for WDT_TIMEOUT_128 (not supported by WDT).
    0xFFU,                             // WDTCR value for WDT_TIMEOUT_512 (not supported by WDT).
    0x00U,                             // WDTCR value for WDT_TIMEOUT_1024.
    0xFFU,                             // WDTCR value for WDT_TIMEOUT_2048 (not supported by WDT).
    0x01U,                             // WDTCR value for WDT_TIMEOUT_4096.
    0x02U,                             // WDTCR value for WDT_TIMEOUT_8192.
    0x03U,                             // WDTCR value for WDT_TIMEOUT_16384.
};

/* Convert WDT/IWDT timeout value to an integer */
static const uint32_t g_wdt_timeout[] =
{
    128U,
    512U,
    1024U,
    2048U,
    4096U,
    8192U,
    16384U
};

/* Converts WDT division enum to log base 2 of the division value, used to shift the PCLKB frequency. */
static const uint8_t g_wdt_division_lookup[] =
{
    0U,                                // log base 2(1)    = 0
    2U,                                // log base 2(4)    = 2
    4U,                                // log base 2(16)   = 4
    5U,                                // log base 2(32)   = 5
    6U,                                // log base 2(64)   = 6
    8U,                                // log base 2(256)  = 8
    9U,                                // log base 2(512)  = 9
    11U,                               // log base 2(2048) = 11
    13U,                               // log base 2(8192) = 13
};

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/** Watchdog implementation of WDT Driver  */
const wdt_api_t g_wdt_on_wdt =
{
    .open        = R_WDT_Open,
    .refresh     = R_WDT_Refresh,
    .statusGet   = R_WDT_StatusGet,
    .statusClear = R_WDT_StatusClear,
    .counterGet  = R_WDT_CounterGet,
    .timeoutGet  = R_WDT_TimeoutGet,
    .callbackSet = R_WDT_CallbackSet,
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZV
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZV_WDT
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Configures the WDT driver based on the input configurations. This function sets the callback function,
 * the timeout count value, and enables the underflow interrupt. Implements
 * @ref wdt_api_t::open.
 *
 * This function should only be called once as WDT configuration registers can only be written to once so subsequent
 * calls will have no effect.
 *
 * Example:
 * @snippet rzv_r_wdt_example.c R_WDT_Open
 *
 * @retval FSP_SUCCESS              WDT successfully configured.
 * @retval FSP_ERR_ASSERTION        Null pointer, or one or more configuration options is invalid.
 * @retval FSP_ERR_ALREADY_OPEN     Module is already open.  This module can only be opened once.
 **********************************************************************************************************************/
fsp_err_t R_WDT_Open (wdt_ctrl_t * const p_ctrl, wdt_cfg_t const * const p_cfg)
{
    wdt_instance_ctrl_t * p_instance_ctrl = (wdt_instance_ctrl_t *) p_ctrl;
    fsp_err_t             err;

    /* Check validity of the parameters */
    err = r_wdt_parameter_checking(p_instance_ctrl, p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Get extended configuration structure pointer. */
    wdt_extended_cfg_t * p_extend = (wdt_extended_cfg_t *) p_cfg->p_extend;

    /* Save register base address. */
    p_instance_ctrl->p_reg = (R_WDT0_Type *) p_extend->p_reg;

    p_instance_ctrl->p_cfg = p_cfg;

    /* Clock On and Reset Off. */
    R_BSP_MODULE_START(FSP_IP_WDT, p_extend->channel);

    /* Register-start mode. */

    if (p_extend->underflow_irq >= 0)
    {
        /* IRQ output mode. */
        R_BSP_IrqCfgEnable(p_extend->underflow_irq, p_extend->underflow_ipl, p_instance_ctrl);
    }

    /* Set the callback function. */
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    /* Enable error notification to the ICU. */
    p_instance_ctrl->p_reg->WDT0_WDTRCR =
        (uint8_t) (WDT_PRV_ERROR_NOTIFICATION_PERMITTED << WDT_PRV_WDTRCR_RESET_CONTROL_BIT);

    uint32_t wdtcr = WDT_PRV_WDTCR_SETTING_SET(TIMEOUT, (uint16_t) g_wdtcr_timeout[p_cfg->timeout]);
    wdtcr |= WDT_PRV_WDTCR_SETTING_SET(CLOCK_DIVISION, (uint16_t) p_cfg->clock_division);
    wdtcr |= WDT_PRV_WDTCR_SETTING_SET(WINDOW_START, (uint16_t) p_cfg->window_start);
    wdtcr |= WDT_PRV_WDTCR_SETTING_SET(WINDOW_END, (uint16_t) p_cfg->window_end);

    p_instance_ctrl->p_reg->WDT0_WDTCR = (uint16_t) wdtcr;

    R_BSP_WDT_COUNTING_ENABLE(p_extend->channel, p_extend->wdt_counting_enable);
    R_BSP_WDT_SYSTEM_RESET_ENABLE(p_extend->channel, p_extend->system_reset_enable);
    R_BSP_WDT_PIN_ASSERTION_ENABLE(p_extend->channel, p_extend->wdtudfout_assertion_enable);
    R_BSP_WDT_COLD_RESET_ENABLE(p_extend->channel, p_extend->cold_reset_enable);

    p_instance_ctrl->wdt_open = WDT_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Read timeout information for the watchdog timer. Implements @ref wdt_api_t::timeoutGet.
 *
 * @retval FSP_SUCCESS              WDT timeout information retrieved successfully.
 * @retval FSP_ERR_ASSERTION        Null Pointer.
 * @retval FSP_ERR_NOT_OPEN         Instance control block is not initialized.
 **********************************************************************************************************************/
fsp_err_t R_WDT_TimeoutGet (wdt_ctrl_t * const p_ctrl, wdt_timeout_values_t * const p_timeout)
{
    wdt_instance_ctrl_t * p_instance_ctrl = (wdt_instance_ctrl_t *) p_ctrl;
#if WDT_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_timeout);
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(WDT_OPEN == p_instance_ctrl->wdt_open, FSP_ERR_NOT_OPEN);
#endif
    uint32_t             shift;
    uint32_t             index;
    uint32_t             timeout = 0;
    wdt_clock_division_t clock_division;

    /* Read the configuration of the watchdog */
    uint32_t wdtcr = p_instance_ctrl->p_reg->WDT0_WDTCR;
    clock_division = (wdt_clock_division_t) WDT_PRV_WDTCR_SETTING_GET(CLOCK_DIVISION, wdtcr);
    timeout        = WDT_PRV_WDTCR_SETTING_GET(TIMEOUT, wdtcr);

    /* Get timeout value from WDTCR register. */
    for (index = 0U; index < (sizeof(g_wdtcr_timeout)); index++)
    {
        if (g_wdtcr_timeout[index] == timeout)
        {
            p_timeout->timeout_clocks = g_wdt_timeout[index];
        }
    }

    /* Get the frequency of the clock supplying the watchdog */
    uint32_t pckb_frequency = R_FSP_SystemClockHzGet(FSP_PRIV_CLOCK_OSCCLK);
    shift = r_wdt_clock_divider_get(clock_division);

    p_timeout->clock_frequency_hz = pckb_frequency >> shift;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Refresh the watchdog timer. Implements @ref wdt_api_t::refresh.
 *
 * In addition to refreshing the watchdog counter this function can be used to start the counter in register start mode.
 *
 * Example:
 * @snippet rzv_r_wdt_example.c R_WDT_Refresh
 *
 * @retval FSP_SUCCESS              WDT successfully refreshed.
 * @retval FSP_ERR_ASSERTION        p_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN         Instance control block is not initialized.
 **********************************************************************************************************************/
fsp_err_t R_WDT_Refresh (wdt_ctrl_t * const p_ctrl)
{
    wdt_instance_ctrl_t * p_instance_ctrl = (wdt_instance_ctrl_t *) p_ctrl;
#if WDT_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(WDT_OPEN == p_instance_ctrl->wdt_open, FSP_ERR_NOT_OPEN);
#endif

    p_instance_ctrl->p_reg->WDT0_WDTRR = WDT_PRV_REFRESH_STEP_1;
    p_instance_ctrl->p_reg->WDT0_WDTRR = WDT_PRV_REFRESH_STEP_2;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Read the WDT status flags. Implements @ref wdt_api_t::statusGet.
 *
 * Indicates both status and error conditions.
 *
 * Example:
 * @snippet rzv_r_wdt_example.c R_WDT_StatusGet
 *
 * @retval FSP_SUCCESS              WDT status successfully read.
 * @retval FSP_ERR_ASSERTION        Null pointer as a parameter.
 * @retval FSP_ERR_NOT_OPEN         Instance control block is not initialized.
 **********************************************************************************************************************/
fsp_err_t R_WDT_StatusGet (wdt_ctrl_t * const p_ctrl, wdt_status_t * const p_status)
{
    wdt_instance_ctrl_t * p_instance_ctrl = (wdt_instance_ctrl_t *) p_ctrl;
#if WDT_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_status);
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(WDT_OPEN == p_instance_ctrl->wdt_open, FSP_ERR_NOT_OPEN);
#endif

    /* Check for refresh or underflow errors. */
    *p_status = (wdt_status_t) (p_instance_ctrl->p_reg->WDT0_WDTSR >> 14);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Clear the WDT status and error flags. Implements @ref wdt_api_t::statusClear.
 *
 * Example:
 * @snippet rzv_r_wdt_example.c R_WDT_StatusClear
 *
 * @retval FSP_SUCCESS              WDT flag(s) successfully cleared.
 * @retval FSP_ERR_ASSERTION        Null pointer as a parameter.
 * @retval FSP_ERR_NOT_OPEN         Instance control block is not initialized.
 **********************************************************************************************************************/
fsp_err_t R_WDT_StatusClear (wdt_ctrl_t * const p_ctrl, const wdt_status_t status)
{
    wdt_instance_ctrl_t * p_instance_ctrl = (wdt_instance_ctrl_t *) p_ctrl;
#if WDT_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(WDT_OPEN == p_instance_ctrl->wdt_open, FSP_ERR_NOT_OPEN);
#endif

    uint16_t value;
    uint16_t read_value;

    /* Casts to uint16_t to ensure value is handled as unsigned. */
    value = (uint16_t) status;

    /* Write zero to clear flags. */
    value = (uint16_t) ~value;
    value = (uint16_t) (value << 14);

    /* Read back status flags until required flag(s) cleared. */
    /* Flags cannot be cleared until the clock cycle after they are set.  */
    do
    {
        p_instance_ctrl->p_reg->WDT0_WDTSR = value;
        read_value = p_instance_ctrl->p_reg->WDT0_WDTSR;

        /* Isolate flags to clear. */
        read_value &= (uint16_t) ((uint16_t) status << 14);
    } while (0U != read_value);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Read the current count value of the WDT. Implements @ref wdt_api_t::counterGet.
 *
 * Example:
 * @snippet rzv_r_wdt_example.c R_WDT_CounterGet
 *
 * @retval FSP_SUCCESS          WDT current count successfully read.
 * @retval FSP_ERR_ASSERTION    Null pointer passed as a parameter.
 * @retval FSP_ERR_NOT_OPEN     Instance control block is not initialized.
 **********************************************************************************************************************/
fsp_err_t R_WDT_CounterGet (wdt_ctrl_t * const p_ctrl, uint32_t * const p_count)
{
    wdt_instance_ctrl_t * p_instance_ctrl = (wdt_instance_ctrl_t *) p_ctrl;
#if WDT_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_count);
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(WDT_OPEN == p_instance_ctrl->wdt_open, FSP_ERR_NOT_OPEN);
#endif

    *p_count  = (uint32_t) p_instance_ctrl->p_reg->WDT0_WDTSR;
    *p_count &= WDT_PRV_WDTSR_COUNTER_MASK;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements wdt_api_t::callbackSet
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_NO_CALLBACK_MEMORY   p_callback is non-secure and p_callback_memory is either secure or NULL.
 **********************************************************************************************************************/
fsp_err_t R_WDT_CallbackSet (wdt_ctrl_t * const          p_ctrl,
                             void (                    * p_callback)(wdt_callback_args_t *),
                             void * const                p_context,
                             wdt_callback_args_t * const p_callback_memory)
{
    wdt_instance_ctrl_t * p_instance_ctrl = (wdt_instance_ctrl_t *) p_ctrl;

#if WDT_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(WDT_OPEN == p_instance_ctrl->wdt_open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */
#if BSP_TZ_SECURE_BUILD

    /* Get security state of p_callback */
    bool callback_is_secure =
        (NULL == cmse_check_address_range((void *) p_callback, sizeof(void *), CMSE_AU_NONSECURE));

 #if WDT_CFG_PARAM_CHECKING_ENABLE

    /* In secure projects, p_callback_memory must be provided in non-secure space if p_callback is non-secure */
    wdt_callback_args_t * const p_callback_memory_checked = cmse_check_pointed_object(p_callback_memory,
                                                                                      CMSE_AU_NONSECURE);
    FSP_ERROR_RETURN(callback_is_secure || (NULL != p_callback_memory_checked), FSP_ERR_NO_CALLBACK_MEMORY);
 #endif
#endif

    /* Store callback and context */
#if BSP_TZ_SECURE_BUILD
    p_instance_ctrl->p_callback = callback_is_secure ? p_callback :
                                  (void (*)(wdt_callback_args_t *))cmse_nsfptr_create(p_callback);
#else
    p_instance_ctrl->p_callback = p_callback;
#endif
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup WDT)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Internal WDT ISR callback which calls the user provided callback passing the context provided by the user.
 *
 * @param[in]    p_ctrl   Pointer to instance control structure
 **********************************************************************************************************************/
static void r_wdt_underflow_callback (wdt_instance_ctrl_t * p_ctrl)
{
    wdt_callback_args_t args;

    /* Store callback arguments in memory provided by user if available.  This allows callback arguments to be
     * stored in non-secure memory so they can be accessed by a non-secure callback function. */
    wdt_callback_args_t * p_args = p_ctrl->p_callback_memory;
    if (NULL == p_args)
    {
        /* Store on stack */
        p_args = &args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt. */
        args = *p_args;
    }

    p_args->p_context = p_ctrl->p_context;

#if BSP_TZ_SECURE_BUILD

    /* p_callback can point to a secure function or a non-secure function. */
    if (!cmse_is_nsfptr(p_ctrl->p_callback))
    {
        /* If p_callback is secure, then the project does not need to change security state. */
        p_ctrl->p_callback(p_args);
    }
    else
    {
        /* If p_callback is Non-secure, then the project must change to Non-secure state in order to call the callback. */
        wdt_prv_ns_callback p_callback = (wdt_prv_ns_callback) (p_ctrl->p_callback);
        p_callback(p_args);
    }

#else

    /* If the project is not Trustzone Secure, then it will never need to change security state in order to call the callback. */
    p_ctrl->p_callback(p_args);
#endif
    if (NULL != p_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_ctrl->p_callback_memory = args;
    }
}

/*******************************************************************************************************************//**
 * Gets clock division shift value.
 *
 * @param[in]   division     Right shift value used to divide clock frequency.
 **********************************************************************************************************************/
static uint32_t r_wdt_clock_divider_get (wdt_clock_division_t division)
{
    uint32_t shift;

    if (WDT_CLOCK_DIVISION_128 == division)
    {
        shift = 7U;                    /* log base 2(128) = 7 */
    }
    else
    {
        shift = g_wdt_division_lookup[division];
    }

    return shift;
}

/*******************************************************************************************************************//**
 * Parameter checking function for WDT Open
 *
 * @param[in]    p_instance_ctrl   Pointer to instance control structure
 * @param[in]    p_cfg             Pointer to configuration structure
 *
 * @retval FSP_SUCCESS              WDT successfully configured.
 * @retval FSP_ERR_ASSERTION        Null pointer, or one or more configuration options is invalid.
 * @retval FSP_ERR_ALREADY_OPEN     Module is already open.  This module can only be opened once.
 **********************************************************************************************************************/
static fsp_err_t r_wdt_parameter_checking (wdt_instance_ctrl_t * const p_instance_ctrl, wdt_cfg_t const * const p_cfg)
{
#if WDT_CFG_PARAM_CHECKING_ENABLE

    /* Check that control and config structure pointers are valid. */
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(WDT_OPEN != p_instance_ctrl->wdt_open, FSP_ERR_ALREADY_OPEN);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    wdt_extended_cfg_t * p_extend = (wdt_extended_cfg_t *) p_cfg->p_extend;
    FSP_ASSERT(NULL != p_extend->p_reg);

    /* Check timeout parameter is supported by WDT. */

    /* Enum checking is done here because some enums in wdt_timeout_t are not supported by the WDT peripheral (they are
     * included for other implementations of the watchdog interface). */
    FSP_ASSERT((p_cfg->timeout == WDT_TIMEOUT_1024) || (p_cfg->timeout == WDT_TIMEOUT_4096) || \
               (p_cfg->timeout == WDT_TIMEOUT_8192) || (p_cfg->timeout == WDT_TIMEOUT_16384));
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
    FSP_PARAMETER_NOT_USED(p_cfg);
#endif

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * WDT Underflow ISR
 **********************************************************************************************************************/
void wdt_underflow_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type             irq    = R_FSP_CurrentIrqGet();
    wdt_instance_ctrl_t * p_ctrl = (wdt_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    if (NULL != p_ctrl->p_callback)
    {
        /* Call the callback function. */
        r_wdt_underflow_callback(p_ctrl);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}
