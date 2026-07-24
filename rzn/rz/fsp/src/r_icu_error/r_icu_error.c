/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_error_api.h"
#include "bsp_api.h"
#include "bsp_cfg.h"
#include "r_icu_error.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "ERR" in ASCII, used to determine if module is open. */
#define ICU_ERROR_OPEN                    (0x455252U)

#define ICU_ERROR_ERR_REG_SIZE            (32U)   /* PERI_ERR related register size is 32bit */
#define ICU_ERROR_CR52_ERR_REG_MASK       (0x03FFFFFFU)
#define ICU_ERROR_CA55_ERR_REG_MASK       (0x00001FFFU)
#define ICU_ERROR_ERR_EVENT_SHIFT_MASK    (0x1FU) /* Shift value is max 31 */

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void r_icu_error_call_callback(icu_error_instance_ctrl_t * p_instance_ctrl, error_callback_args_t * p_args);
void        error_cpu0_int_isr(void);

#if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
void error_cpu1_int_isr(void);

#endif
#if BSP_FEATURE_ICU_ERROR_CA55_SUPPORTED
void error_ca55_int_isr(void);

#endif
void error_peripherals_int_isr(void);

#if BSP_FEATURE_ICU_ERROR_ENCIF_ERR_INTERRUPT_SUPPORTED
void error_encif_int_isr(void);

#endif

#if BSP_FEATURE_ICU_ERROR_DSMIF_ERR_INTERRUPT_SUPPORTED
void error_dsmif_int_isr(void);

#endif

static const error_table_t * gp_peri_error_handler_table;
#if BSP_FEATURE_ICU_ERROR_DSMIF_ERR_INTERRUPT_SUPPORTED
static const error_table_t * gp_dsmif_error_handler_table;
#endif
#if BSP_FEATURE_ICU_ERROR_ENCIF_ERR_INTERRUPT_SUPPORTED
static const error_table_t * gp_encif_error_handler_table;
#endif

/* This array stores the address of the register containing the error event status bits.
 * Use to handle all error events at once. */
static volatile const uint32_t * const gp_err_stat_table[BSP_FEATURE_ICU_ERROR_ERR_SOURCE_NUM] =
{
#if 3U == BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE
    [ERROR_EVENT_CPU0] = &(R_ICU_NS->CR520ERR_STAT),
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    [ERROR_EVENT_CPU1] = &(R_ICU_NS->CR521ERR_STAT),
 #endif
    [ERROR_EVENT_CA55]         = &(R_ICU_NS->CA55ERR_STAT),
    [ERROR_EVENT_PERIPHERAL_0] = &(R_ICU_NS->PERIERR_STAT[0]),
    [ERROR_EVENT_PERIPHERAL_1] = &(R_ICU_NS->PERIERR_STAT[1]),
    [ERROR_EVENT_PERIPHERAL_2] = &(R_ICU_NS->PERIERR_STAT[2]),
    [ERROR_EVENT_DSMIF_0]      = &(R_ICU_NS->DSMIFERR_STAT[0]),
    [ERROR_EVENT_DSMIF_1]      = &(R_ICU_NS->DSMIFERR_STAT[1]),
    [ERROR_EVENT_DSMIF_2]      = &(R_ICU_NS->DSMIFERR_STAT[2]),
    [ERROR_EVENT_DSMIF_3]      = &(R_ICU_NS->DSMIFERR_STAT[3]),
    [ERROR_EVENT_DSMIF_4]      = &(R_ICU_NS->DSMIFERR_STAT[4]),
    [ERROR_EVENT_DSMIF_5]      = &(R_ICU_NS->DSMIFERR_STAT[5]),
    [ERROR_EVENT_DSMIF_7]      = &(R_ICU_NS->DSMIFERR_STAT[7]),
    [ERROR_EVENT_DSMIF_8]      = &(R_ICU_NS->DSMIFERR_STAT[8]),
    [ERROR_EVENT_DSMIF_10]     = &(R_ICU_NS->DSMIFERR_STAT[10]),
    [ERROR_EVENT_DSMIF_11]     = &(R_ICU_NS->DSMIFERR_STAT[11]),
    [ERROR_EVENT_ENCIF_0]      = &(R_ICU_NS->ENCIFERR_STAT[0]),
    [ERROR_EVENT_ENCIF_1]      = &(R_ICU_NS->ENCIFERR_STAT[1]),
    [ERROR_EVENT_ENCIF_2]      = &(R_ICU_NS->ENCIFERR_STAT[2]),
    [ERROR_EVENT_ENCIF_3]      = &(R_ICU_NS->ENCIFERR_STAT[3]),
    [ERROR_EVENT_ENCIF_4]      = &(R_ICU_NS->ENCIFERR_STAT[4]),
#else
    [ERROR_EVENT_CPU0] = &(R_ICU->CPU0ERR_STAT),
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    [ERROR_EVENT_CPU1] = &(R_ICU->CPU1ERR_STAT),
 #endif
    [ERROR_EVENT_PERIPHERAL_0] = &(R_ICU->PERIERR_STAT0),
    [ERROR_EVENT_PERIPHERAL_1] = &(R_ICU->PERIERR_STAT1),
 #if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    [ERROR_EVENT_PERIPHERAL_2] = &(R_ICU->PERIERR_STAT2),
 #endif
#endif
};

/* This array stores the address of the register containing the error event status clear bits.
 * Use to handle all error events at once. */
static volatile uint32_t * const gp_err_clr_table[BSP_FEATURE_ICU_ERROR_ERR_SOURCE_NUM] =
{
#if 3U == BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE
    [ERROR_EVENT_CPU0] = &(R_ICU_NS->CR520ERR_CLR),
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    [ERROR_EVENT_CPU1] = &(R_ICU_NS->CR521ERR_CLR),
 #endif
    [ERROR_EVENT_CA55]         = &(R_ICU_NS->CA55ERR_CLR),
    [ERROR_EVENT_PERIPHERAL_0] = &(R_ICU_NS->PERIERR_CLR[0]),
    [ERROR_EVENT_PERIPHERAL_1] = &(R_ICU_NS->PERIERR_CLR[1]),
    [ERROR_EVENT_PERIPHERAL_2] = &(R_ICU_NS->PERIERR_CLR[2]),
    [ERROR_EVENT_DSMIF_0]      = &(R_ICU_NS->DSMIFERR_CLR[0]),
    [ERROR_EVENT_DSMIF_1]      = &(R_ICU_NS->DSMIFERR_CLR[1]),
    [ERROR_EVENT_DSMIF_2]      = &(R_ICU_NS->DSMIFERR_CLR[2]),
    [ERROR_EVENT_DSMIF_3]      = &(R_ICU_NS->DSMIFERR_CLR[3]),
    [ERROR_EVENT_DSMIF_4]      = &(R_ICU_NS->DSMIFERR_CLR[4]),
    [ERROR_EVENT_DSMIF_5]      = &(R_ICU_NS->DSMIFERR_CLR[5]),
    [ERROR_EVENT_DSMIF_7]      = &(R_ICU_NS->DSMIFERR_CLR[7]),
    [ERROR_EVENT_DSMIF_8]      = &(R_ICU_NS->DSMIFERR_CLR[8]),
    [ERROR_EVENT_DSMIF_10]     = &(R_ICU_NS->DSMIFERR_CLR[10]),
    [ERROR_EVENT_DSMIF_11]     = &(R_ICU_NS->DSMIFERR_CLR[11]),
    [ERROR_EVENT_ENCIF_0]      = &(R_ICU_NS->ENCIFERR_CLR[0]),
    [ERROR_EVENT_ENCIF_1]      = &(R_ICU_NS->ENCIFERR_CLR[1]),
    [ERROR_EVENT_ENCIF_2]      = &(R_ICU_NS->ENCIFERR_CLR[2]),
    [ERROR_EVENT_ENCIF_3]      = &(R_ICU_NS->ENCIFERR_CLR[3]),
    [ERROR_EVENT_ENCIF_4]      = &(R_ICU_NS->ENCIFERR_CLR[4]),
#else
    [ERROR_EVENT_CPU0] = &(R_ICU->CPU0ERR_CLR),
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    [ERROR_EVENT_CPU1] = &(R_ICU->CPU1ERR_CLR),
 #endif
    [ERROR_EVENT_PERIPHERAL_0] = &(R_ICU->PERIERR_CLR0),
    [ERROR_EVENT_PERIPHERAL_1] = &(R_ICU->PERIERR_CLR1),
 #if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    [ERROR_EVENT_PERIPHERAL_2] = &(R_ICU->PERIERR_CLR2),
 #endif
#endif
};

/* This array stores the address of the register containing the E0 error event mask bits.
 * Use to handle all error events at once. */
static volatile const uint32_t * const gp_err_e0msk_table[BSP_FEATURE_ICU_ERROR_ERR_SOURCE_NUM] =
{
#if 3U == BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE
    [ERROR_EVENT_CPU0] = &(R_ICU_NS->CR520ERR_E0MSK),
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    [ERROR_EVENT_CPU1] = &(R_ICU_NS->CR521ERR_E0MSK),
 #endif
    [ERROR_EVENT_CA55]         = &(R_ICU_NS->CA55ERR_E0MSK),
    [ERROR_EVENT_PERIPHERAL_0] = &(R_ICU_NS->PERIERR_E0MSK[0]),
    [ERROR_EVENT_PERIPHERAL_1] = &(R_ICU_NS->PERIERR_E0MSK[1]),
    [ERROR_EVENT_PERIPHERAL_2] = &(R_ICU_NS->PERIERR_E0MSK[2]),
    [ERROR_EVENT_DSMIF_0]      = &(R_ICU_NS->DSMIFERR_E0MSK[0]),
    [ERROR_EVENT_DSMIF_1]      = &(R_ICU_NS->DSMIFERR_E0MSK[1]),
    [ERROR_EVENT_DSMIF_2]      = &(R_ICU_NS->DSMIFERR_E0MSK[2]),
    [ERROR_EVENT_DSMIF_3]      = &(R_ICU_NS->DSMIFERR_E0MSK[3]),
    [ERROR_EVENT_DSMIF_4]      = &(R_ICU_NS->DSMIFERR_E0MSK[4]),
    [ERROR_EVENT_DSMIF_5]      = &(R_ICU_NS->DSMIFERR_E0MSK[5]),
    [ERROR_EVENT_DSMIF_7]      = &(R_ICU_NS->DSMIFERR_E0MSK[7]),
    [ERROR_EVENT_DSMIF_8]      = &(R_ICU_NS->DSMIFERR_E0MSK[8]),
    [ERROR_EVENT_DSMIF_10]     = &(R_ICU_NS->DSMIFERR_E0MSK[10]),
    [ERROR_EVENT_DSMIF_11]     = &(R_ICU_NS->DSMIFERR_E0MSK[11]),
    [ERROR_EVENT_ENCIF_0]      = &(R_ICU_NS->ENCIFERR_E0MSK[0]),
    [ERROR_EVENT_ENCIF_1]      = &(R_ICU_NS->ENCIFERR_E0MSK[1]),
    [ERROR_EVENT_ENCIF_2]      = &(R_ICU_NS->ENCIFERR_E0MSK[2]),
    [ERROR_EVENT_ENCIF_3]      = &(R_ICU_NS->ENCIFERR_E0MSK[3]),
    [ERROR_EVENT_ENCIF_4]      = &(R_ICU_NS->ENCIFERR_E0MSK[4]),
#else
    [ERROR_EVENT_CPU0] = &(R_ICU->CPU0ERR_E0MSK),
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    [ERROR_EVENT_CPU1] = &(R_ICU->CPU1ERR_E0MSK),
 #endif
    [ERROR_EVENT_PERIPHERAL_0] = &(R_ICU->PERIERR_E0MSK0),
    [ERROR_EVENT_PERIPHERAL_1] = &(R_ICU->PERIERR_E0MSK1),
 #if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    [ERROR_EVENT_PERIPHERAL_2] = &(R_ICU->PERIERR_E0MSK2),
 #endif
#endif
};

/* This array stores the address of the register containing the E1 error event mask bits.
 * Use to handle all error events at once. */
static volatile const uint32_t * const gp_err_e1msk_table[BSP_FEATURE_ICU_ERROR_ERR_SOURCE_NUM] =
{
#if 3U == BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE
    [ERROR_EVENT_CPU0] = &(R_ICU_NS->CR520ERR_E1MSK),
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    [ERROR_EVENT_CPU1] = &(R_ICU_NS->CR521ERR_E1MSK),
 #endif
    [ERROR_EVENT_CA55]         = &(R_ICU_NS->CA55ERR_E1MSK),
    [ERROR_EVENT_PERIPHERAL_0] = &(R_ICU_NS->PERIERR_E1MSK[0]),
    [ERROR_EVENT_PERIPHERAL_1] = &(R_ICU_NS->PERIERR_E1MSK[1]),
    [ERROR_EVENT_PERIPHERAL_2] = &(R_ICU_NS->PERIERR_E1MSK[2]),
    [ERROR_EVENT_DSMIF_0]      = &(R_ICU_NS->DSMIFERR_E1MSK[0]),
    [ERROR_EVENT_DSMIF_1]      = &(R_ICU_NS->DSMIFERR_E1MSK[1]),
    [ERROR_EVENT_DSMIF_2]      = &(R_ICU_NS->DSMIFERR_E1MSK[2]),
    [ERROR_EVENT_DSMIF_3]      = &(R_ICU_NS->DSMIFERR_E1MSK[3]),
    [ERROR_EVENT_DSMIF_4]      = &(R_ICU_NS->DSMIFERR_E1MSK[4]),
    [ERROR_EVENT_DSMIF_5]      = &(R_ICU_NS->DSMIFERR_E1MSK[5]),
    [ERROR_EVENT_DSMIF_7]      = &(R_ICU_NS->DSMIFERR_E1MSK[7]),
    [ERROR_EVENT_DSMIF_8]      = &(R_ICU_NS->DSMIFERR_E1MSK[8]),
    [ERROR_EVENT_DSMIF_10]     = &(R_ICU_NS->DSMIFERR_E1MSK[10]),
    [ERROR_EVENT_DSMIF_11]     = &(R_ICU_NS->DSMIFERR_E1MSK[11]),
    [ERROR_EVENT_ENCIF_0]      = &(R_ICU_NS->ENCIFERR_E1MSK[0]),
    [ERROR_EVENT_ENCIF_1]      = &(R_ICU_NS->ENCIFERR_E1MSK[1]),
    [ERROR_EVENT_ENCIF_2]      = &(R_ICU_NS->ENCIFERR_E1MSK[2]),
    [ERROR_EVENT_ENCIF_3]      = &(R_ICU_NS->ENCIFERR_E1MSK[3]),
    [ERROR_EVENT_ENCIF_4]      = &(R_ICU_NS->ENCIFERR_E1MSK[4]),
#else
    [ERROR_EVENT_CPU0] = &(R_ICU->CPU0ERR_E1MSK),
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    [ERROR_EVENT_CPU1] = &(R_ICU->CPU1ERR_E1MSK),
 #endif
    [ERROR_EVENT_PERIPHERAL_0] = &(R_ICU->PERIERR_E1MSK0),
    [ERROR_EVENT_PERIPHERAL_1] = &(R_ICU->PERIERR_E1MSK1),
 #if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    [ERROR_EVENT_PERIPHERAL_2] = &(R_ICU->PERIERR_E1MSK2),
 #endif
#endif
};

/* This array stores the register mask for each error event register.
 * Use to handle all error events at once. */
static const uint32_t g_err_mask_table[BSP_FEATURE_ICU_ERROR_ERR_SOURCE_NUM] =
{
    [ERROR_EVENT_CPU0] = ICU_ERROR_CR52_ERR_REG_MASK, // Mask for CPU0 error event register
#if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    [ERROR_EVENT_CPU1] = ICU_ERROR_CR52_ERR_REG_MASK, // Mask for CPU1 error event register
#endif
#if BSP_FEATURE_ICU_ERROR_CA55_SUPPORTED
    [ERROR_EVENT_CA55] = ICU_ERROR_CA55_ERR_REG_MASK,
#endif
    [ERROR_EVENT_PERIPHERAL_0] = BSP_FEATURE_ICU_ERROR_PERI_ERR0_REG_MASK,
    [ERROR_EVENT_PERIPHERAL_1] = BSP_FEATURE_ICU_ERROR_PERI_ERR1_REG_MASK,
#if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    [ERROR_EVENT_PERIPHERAL_2] = BSP_FEATURE_ICU_ERROR_PERI_ERR2_REG_MASK,
#endif
#if BSP_FEATURE_ICU_ERROR_DSMIF_ERR_INTERRUPT_SUPPORTED
    [ERROR_EVENT_DSMIF_0]  = BSP_FEATURE_ICU_ERROR_DSMIF_ERR0_REG_MASK,
    [ERROR_EVENT_DSMIF_1]  = BSP_FEATURE_ICU_ERROR_DSMIF_ERR1_REG_MASK,
    [ERROR_EVENT_DSMIF_2]  = BSP_FEATURE_ICU_ERROR_DSMIF_ERR2_REG_MASK,
    [ERROR_EVENT_DSMIF_3]  = BSP_FEATURE_ICU_ERROR_DSMIF_ERR3_REG_MASK,
    [ERROR_EVENT_DSMIF_4]  = BSP_FEATURE_ICU_ERROR_DSMIF_ERR4_REG_MASK,
    [ERROR_EVENT_DSMIF_5]  = BSP_FEATURE_ICU_ERROR_DSMIF_ERR5_REG_MASK,
    [ERROR_EVENT_DSMIF_7]  = BSP_FEATURE_ICU_ERROR_DSMIF_ERR7_REG_MASK,
    [ERROR_EVENT_DSMIF_8]  = BSP_FEATURE_ICU_ERROR_DSMIF_ERR8_REG_MASK,
    [ERROR_EVENT_DSMIF_10] = BSP_FEATURE_ICU_ERROR_DSMIF_ERR10_REG_MASK,
    [ERROR_EVENT_DSMIF_11] = BSP_FEATURE_ICU_ERROR_DSMIF_ERR11_REG_MASK,
#endif
#if BSP_FEATURE_ICU_ERROR_ENCIF_ERR_INTERRUPT_SUPPORTED
    [ERROR_EVENT_ENCIF_0] = BSP_FEATURE_ICU_ERROR_ENCIF_ERR0_REG_MASK,
    [ERROR_EVENT_ENCIF_1] = BSP_FEATURE_ICU_ERROR_ENCIF_ERR1_REG_MASK,
    [ERROR_EVENT_ENCIF_2] = BSP_FEATURE_ICU_ERROR_ENCIF_ERR2_REG_MASK,
    [ERROR_EVENT_ENCIF_3] = BSP_FEATURE_ICU_ERROR_ENCIF_ERR3_REG_MASK,
    [ERROR_EVENT_ENCIF_4] = BSP_FEATURE_ICU_ERROR_ENCIF_ERR4_REG_MASK,
#endif
};

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/* ERROR implementation of ERROR Driver  */
const error_api_t g_error_on_icu_error =
{
    .open        = R_ICU_ERROR_Open,
    .close       = R_ICU_ERROR_Close,
    .statusGet   = R_ICU_ERROR_StatusGet,
    .statusClear = R_ICU_ERROR_StatusClear,
    .callbackSet = R_ICU_ERROR_CallbackSet,
};

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZN
{
#endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZN_ICU_ERROR
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Opens and configures the ERROR events from CPU and peripherals.
 *
 * @retval FSP_SUCCESS                  Successful open.
 * @retval FSP_ERR_ALREADY_OPEN         Module already open.
 * @retval FSP_ERR_ASSERTION            One or more pointers point to NULL or callback is NULL or the interrupt vector
 *                                      is invalid.
 *
 * @note This function clears the status of error events configured to enable interrupts or resets on the FSP Configuration editor.
 ***********************************************************************************************************************/
fsp_err_t R_ICU_ERROR_Open (error_ctrl_t * const p_ctrl, error_cfg_t const * const p_cfg)
{
    icu_error_instance_ctrl_t * p_instance_ctrl = (icu_error_instance_ctrl_t *) p_ctrl;

    /* Validate the parameters and check if the module is initialized */
#if ICU_ERROR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ERROR_RETURN(ICU_ERROR_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    /* Save pointers for later use */
    p_instance_ctrl->p_cfg = p_cfg;
    icu_error_extended_cfg_t * p_extend = (icu_error_extended_cfg_t *) p_cfg->p_extend;

    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

#if 3U == BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE
    R_ICU_NS_Type * icu_error_base = (R_ICU_NS_Type *) R_ICU_NS_BASE;
#else
    R_ICU_Type * icu_error_base = (R_ICU_Type *) R_ICU_BASE;
#endif

    /* If the status is in error, interrupts and resets occur the moment the mask is released.
     * Therefore, clear the status before releasing the mask. */
#if 3U == BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE
    icu_error_base->CR520ERR_CLR = ~(p_extend->cpu0_err_reset_mask &
                                     p_extend->cpu0_err0_event_mask &
                                     p_extend->cpu0_err1_event_mask) &
                                   ICU_ERROR_CR52_ERR_REG_MASK;

 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    icu_error_base->CR521ERR_CLR = ~(p_extend->cpu1_err_reset_mask &
                                     p_extend->cpu1_err0_event_mask &
                                     p_extend->cpu1_err1_event_mask) &
                                   ICU_ERROR_CR52_ERR_REG_MASK;
 #endif

    icu_error_base->PERIERR_CLR[0] = ~(p_extend->peri_err_event_0_reset_mask &
                                       p_extend->peri_err0_event_0_mask &
                                       p_extend->peri_err1_event_0_mask) &
                                     BSP_FEATURE_ICU_ERROR_PERI_ERR0_REG_MASK;

    icu_error_base->PERIERR_CLR[1] = ~(p_extend->peri_err_event_1_reset_mask &
                                       p_extend->peri_err0_event_1_mask &
                                       p_extend->peri_err1_event_1_mask) &
                                     BSP_FEATURE_ICU_ERROR_PERI_ERR1_REG_MASK;

 #if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    icu_error_base->PERIERR_CLR[2] = ~(p_extend->peri_err_event_2_reset_mask &
                                       p_extend->peri_err0_event_2_mask &
                                       p_extend->peri_err1_event_2_mask) &
                                     BSP_FEATURE_ICU_ERROR_PERI_ERR2_REG_MASK;
 #endif
#else
    icu_error_base->CPU0ERR_CLR = ~(p_extend->cpu0_err_reset_mask &
                                    p_extend->cpu0_err0_event_mask &
                                    p_extend->cpu0_err1_event_mask) &
                                  ICU_ERROR_CR52_ERR_REG_MASK;
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    icu_error_base->CPU1ERR_CLR = ~(p_extend->cpu1_err_reset_mask &
                                    p_extend->cpu1_err0_event_mask &
                                    p_extend->cpu1_err1_event_mask) &
                                  ICU_ERROR_CR52_ERR_REG_MASK;
 #endif
    icu_error_base->PERIERR_CLR0 = ~(p_extend->peri_err_event_0_reset_mask &
                                     p_extend->peri_err0_event_0_mask &
                                     p_extend->peri_err1_event_0_mask) &
                                   BSP_FEATURE_ICU_ERROR_PERI_ERR0_REG_MASK;

    icu_error_base->PERIERR_CLR1 = ~(p_extend->peri_err_event_1_reset_mask &
                                     p_extend->peri_err0_event_1_mask &
                                     p_extend->peri_err1_event_1_mask) &
                                   BSP_FEATURE_ICU_ERROR_PERI_ERR1_REG_MASK;

 #if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    icu_error_base->PERIERR_CLR2 = ~(p_extend->peri_err_event_2_reset_mask &
                                     p_extend->peri_err0_event_2_mask &
                                     p_extend->peri_err1_event_2_mask) &
                                   BSP_FEATURE_ICU_ERROR_PERI_ERR2_REG_MASK;
 #endif
#endif
#if BSP_FEATURE_ICU_ERROR_CA55_SUPPORTED
    icu_error_base->CA55ERR_CLR = ~(p_extend->ca55_err_reset_mask &
                                    p_extend->ca55_err0_event_mask &
                                    p_extend->ca55_err1_event_mask) &
                                  ICU_ERROR_CA55_ERR_REG_MASK;
#endif

#if BSP_FEATURE_ICU_ERROR_DSMIF_ERR_INTERRUPT_SUPPORTED
    icu_error_base->DSMIFERR_CLR[0] = ~(p_extend->dsmif_err_event_0_reset_mask &
                                        p_extend->dsmif_err0_event_0_mask &
                                        p_extend->dsmif_err1_event_0_mask) &
                                      BSP_FEATURE_ICU_ERROR_DSMIF_ERR0_REG_MASK;

    icu_error_base->DSMIFERR_CLR[1] = ~(p_extend->dsmif_err_event_1_reset_mask &
                                        p_extend->dsmif_err0_event_1_mask &
                                        p_extend->dsmif_err1_event_1_mask) &
                                      BSP_FEATURE_ICU_ERROR_DSMIF_ERR1_REG_MASK;

    icu_error_base->DSMIFERR_CLR[2] = ~(p_extend->dsmif_err_event_2_reset_mask &
                                        p_extend->dsmif_err0_event_2_mask &
                                        p_extend->dsmif_err1_event_2_mask) &
                                      BSP_FEATURE_ICU_ERROR_DSMIF_ERR2_REG_MASK;

    icu_error_base->DSMIFERR_CLR[3] = ~(p_extend->dsmif_err_event_3_reset_mask &
                                        p_extend->dsmif_err0_event_3_mask &
                                        p_extend->dsmif_err1_event_3_mask) &
                                      BSP_FEATURE_ICU_ERROR_DSMIF_ERR3_REG_MASK;

    icu_error_base->DSMIFERR_CLR[4] = ~(p_extend->dsmif_err_event_4_reset_mask &
                                        p_extend->dsmif_err0_event_4_mask &
                                        p_extend->dsmif_err1_event_4_mask) &
                                      BSP_FEATURE_ICU_ERROR_DSMIF_ERR4_REG_MASK;

    icu_error_base->DSMIFERR_CLR[5] = ~(p_extend->dsmif_err_event_5_reset_mask &
                                        p_extend->dsmif_err0_event_5_mask &
                                        p_extend->dsmif_err1_event_5_mask) &
                                      BSP_FEATURE_ICU_ERROR_DSMIF_ERR5_REG_MASK;

    icu_error_base->DSMIFERR_CLR[7] = ~(p_extend->dsmif_err_event_7_reset_mask &
                                        p_extend->dsmif_err0_event_7_mask &
                                        p_extend->dsmif_err1_event_7_mask) &
                                      BSP_FEATURE_ICU_ERROR_DSMIF_ERR7_REG_MASK;

    icu_error_base->DSMIFERR_CLR[8] = ~(p_extend->dsmif_err_event_8_reset_mask &
                                        p_extend->dsmif_err0_event_8_mask &
                                        p_extend->dsmif_err1_event_8_mask) &
                                      BSP_FEATURE_ICU_ERROR_DSMIF_ERR8_REG_MASK;

    icu_error_base->DSMIFERR_CLR[10] = ~(p_extend->dsmif_err_event_10_reset_mask &
                                         p_extend->dsmif_err0_event_10_mask &
                                         p_extend->dsmif_err1_event_10_mask) &
                                       BSP_FEATURE_ICU_ERROR_DSMIF_ERR10_REG_MASK;

    icu_error_base->DSMIFERR_CLR[11] = ~(p_extend->dsmif_err_event_11_reset_mask &
                                         p_extend->dsmif_err0_event_11_mask &
                                         p_extend->dsmif_err1_event_11_mask) &
                                       BSP_FEATURE_ICU_ERROR_DSMIF_ERR11_REG_MASK;
#endif

#if BSP_FEATURE_ICU_ERROR_ENCIF_ERR_INTERRUPT_SUPPORTED
    icu_error_base->ENCIFERR_CLR[0] = ~(p_extend->encif_err_event_0_reset_mask &
                                        p_extend->encif_err0_event_0_mask &
                                        p_extend->encif_err1_event_0_mask) &
                                      BSP_FEATURE_ICU_ERROR_ENCIF_ERR0_REG_MASK;

    icu_error_base->ENCIFERR_CLR[1] = ~(p_extend->encif_err_event_1_reset_mask &
                                        p_extend->encif_err0_event_1_mask &
                                        p_extend->encif_err1_event_1_mask) &
                                      BSP_FEATURE_ICU_ERROR_ENCIF_ERR1_REG_MASK;

    icu_error_base->ENCIFERR_CLR[2] = ~(p_extend->encif_err_event_2_reset_mask &
                                        p_extend->encif_err0_event_2_mask &
                                        p_extend->encif_err1_event_2_mask) &
                                      BSP_FEATURE_ICU_ERROR_ENCIF_ERR2_REG_MASK;

    icu_error_base->ENCIFERR_CLR[3] = ~(p_extend->encif_err_event_3_reset_mask &
                                        p_extend->encif_err0_event_3_mask &
                                        p_extend->encif_err1_event_3_mask) &
                                      BSP_FEATURE_ICU_ERROR_ENCIF_ERR3_REG_MASK;

    icu_error_base->ENCIFERR_CLR[4] = ~(p_extend->encif_err_event_4_reset_mask &
                                        p_extend->encif_err0_event_4_mask &
                                        p_extend->encif_err1_event_4_mask) &
                                      BSP_FEATURE_ICU_ERROR_ENCIF_ERR3_REG_MASK;
#endif

    /* Configure Error reset signal.
     * To avoid overwriting values set by other CPU cores, AND operation is performed. */
#if 3U == BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE
    icu_error_base->CR520ERR_RSTMSK &= (p_extend->cpu0_err_reset_mask | (~ICU_ERROR_CR52_ERR_REG_MASK));
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    icu_error_base->CR521ERR_RSTMSK &= (p_extend->cpu1_err_reset_mask | (~ICU_ERROR_CR52_ERR_REG_MASK));
 #endif
    icu_error_base->PERIERR_RSTMSK[0] &=
        (p_extend->peri_err_event_0_reset_mask | (~BSP_FEATURE_ICU_ERROR_PERI_ERR0_REG_MASK));
    icu_error_base->PERIERR_RSTMSK[1] &=
        (p_extend->peri_err_event_1_reset_mask | (~BSP_FEATURE_ICU_ERROR_PERI_ERR1_REG_MASK));
 #if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    icu_error_base->PERIERR_RSTMSK[2] &=
        (p_extend->peri_err_event_2_reset_mask | (~BSP_FEATURE_ICU_ERROR_PERI_ERR2_REG_MASK));
 #endif
#else
    icu_error_base->CPU0ERR_RSTMSK &= (p_extend->cpu0_err_reset_mask | (~ICU_ERROR_CR52_ERR_REG_MASK));
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    icu_error_base->CPU1ERR_RSTMSK &= (p_extend->cpu1_err_reset_mask | (~ICU_ERROR_CR52_ERR_REG_MASK));
 #endif
    icu_error_base->PERIERR_RSTMSK0 &=
        (p_extend->peri_err_event_0_reset_mask | (~BSP_FEATURE_ICU_ERROR_PERI_ERR0_REG_MASK));
    icu_error_base->PERIERR_RSTMSK1 &=
        (p_extend->peri_err_event_1_reset_mask | (~BSP_FEATURE_ICU_ERROR_PERI_ERR1_REG_MASK));
 #if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    icu_error_base->PERIERR_RSTMSK2 &=
        (p_extend->peri_err_event_2_reset_mask | (~BSP_FEATURE_ICU_ERROR_PERI_ERR2_REG_MASK));
 #endif
#endif
#if BSP_FEATURE_ICU_ERROR_CA55_SUPPORTED
    icu_error_base->CA55ERR_RSTMSK &= (p_extend->ca55_err_reset_mask | (~ICU_ERROR_CA55_ERR_REG_MASK));
#endif

#if BSP_FEATURE_ICU_ERROR_DSMIF_ERR_INTERRUPT_SUPPORTED
    icu_error_base->DSMIFERR_RSTMSK[0] &=
        (p_extend->dsmif_err_event_0_reset_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR0_REG_MASK));
    icu_error_base->DSMIFERR_RSTMSK[1] &=
        (p_extend->dsmif_err_event_1_reset_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR1_REG_MASK));
    icu_error_base->DSMIFERR_RSTMSK[2] &=
        (p_extend->dsmif_err_event_2_reset_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR2_REG_MASK));
    icu_error_base->DSMIFERR_RSTMSK[3] &=
        (p_extend->dsmif_err_event_3_reset_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR3_REG_MASK));
    icu_error_base->DSMIFERR_RSTMSK[4] &=
        (p_extend->dsmif_err_event_4_reset_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR4_REG_MASK));
    icu_error_base->DSMIFERR_RSTMSK[5] &=
        (p_extend->dsmif_err_event_5_reset_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR5_REG_MASK));
    icu_error_base->DSMIFERR_RSTMSK[7] &=
        (p_extend->dsmif_err_event_7_reset_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR7_REG_MASK));
    icu_error_base->DSMIFERR_RSTMSK[8] &=
        (p_extend->dsmif_err_event_8_reset_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR8_REG_MASK));
    icu_error_base->DSMIFERR_RSTMSK[10] &=
        (p_extend->dsmif_err_event_10_reset_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR10_REG_MASK));
    icu_error_base->DSMIFERR_RSTMSK[11] &=
        (p_extend->dsmif_err_event_11_reset_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR11_REG_MASK));
#endif
#if BSP_FEATURE_ICU_ERROR_ENCIF_ERR_INTERRUPT_SUPPORTED
    icu_error_base->ENCIFERR_RSTMSK[0] &=
        (p_extend->encif_err_event_0_reset_mask | (~BSP_FEATURE_ICU_ERROR_ENCIF_ERR0_REG_MASK));
    icu_error_base->ENCIFERR_RSTMSK[1] &=
        (p_extend->encif_err_event_1_reset_mask | (~BSP_FEATURE_ICU_ERROR_ENCIF_ERR1_REG_MASK));
    icu_error_base->ENCIFERR_RSTMSK[2] &=
        (p_extend->encif_err_event_2_reset_mask | (~BSP_FEATURE_ICU_ERROR_ENCIF_ERR2_REG_MASK));
    icu_error_base->ENCIFERR_RSTMSK[3] &=
        (p_extend->encif_err_event_3_reset_mask | (~BSP_FEATURE_ICU_ERROR_ENCIF_ERR3_REG_MASK));
    icu_error_base->ENCIFERR_RSTMSK[4] &=
        (p_extend->encif_err_event_4_reset_mask | (~BSP_FEATURE_ICU_ERROR_ENCIF_ERR4_REG_MASK));
#endif

#if 3U == BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE

    /* Configure CPU_ERR signal.
     * To avoid overwriting values set by other CPU cores, AND operation is performed. */
    icu_error_base->CR520ERR_E0MSK &= (p_extend->cpu0_err0_event_mask | (~ICU_ERROR_CR52_ERR_REG_MASK));
    icu_error_base->CR520ERR_E1MSK &= (p_extend->cpu0_err1_event_mask | (~ICU_ERROR_CR52_ERR_REG_MASK));
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    icu_error_base->CR521ERR_E0MSK &= (p_extend->cpu1_err0_event_mask | (~ICU_ERROR_CR52_ERR_REG_MASK));
    icu_error_base->CR521ERR_E1MSK &= (p_extend->cpu1_err1_event_mask | (~ICU_ERROR_CR52_ERR_REG_MASK));
 #endif

    /* Configure PERI_ERR signal.
     * To avoid overwriting values set by other CPU cores, AND operation is performed. */
    icu_error_base->PERIERR_E0MSK[0] &=
        (p_extend->peri_err0_event_0_mask | (~BSP_FEATURE_ICU_ERROR_PERI_ERR0_REG_MASK));
    icu_error_base->PERIERR_E0MSK[1] &=
        (p_extend->peri_err0_event_1_mask | (~BSP_FEATURE_ICU_ERROR_PERI_ERR1_REG_MASK));
 #if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    icu_error_base->PERIERR_E0MSK[2] &=
        (p_extend->peri_err0_event_2_mask | (~BSP_FEATURE_ICU_ERROR_PERI_ERR2_REG_MASK));
 #endif
#else

    /* Configure CPU_ERR signal.
     * To avoid overwriting values set by other CPU cores, AND operation is performed. */
    icu_error_base->CPU0ERR_E0MSK &= (p_extend->cpu0_err0_event_mask | (~ICU_ERROR_CR52_ERR_REG_MASK));
    icu_error_base->CPU0ERR_E1MSK &= (p_extend->cpu0_err1_event_mask | (~ICU_ERROR_CR52_ERR_REG_MASK));
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    icu_error_base->CPU1ERR_E0MSK &= (p_extend->cpu1_err0_event_mask | (~ICU_ERROR_CR52_ERR_REG_MASK));
    icu_error_base->CPU1ERR_E1MSK &= (p_extend->cpu1_err1_event_mask | (~ICU_ERROR_CR52_ERR_REG_MASK));
 #endif

    /* Configure PERI_ERR signal.
     * To avoid overwriting values set by other CPU cores, AND operation is performed. */
    icu_error_base->PERIERR_E0MSK0 &= (p_extend->peri_err0_event_0_mask | (~BSP_FEATURE_ICU_ERROR_PERI_ERR0_REG_MASK));
    icu_error_base->PERIERR_E0MSK1 &= (p_extend->peri_err0_event_1_mask | (~BSP_FEATURE_ICU_ERROR_PERI_ERR1_REG_MASK));
 #if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    icu_error_base->PERIERR_E0MSK2 &= (p_extend->peri_err0_event_2_mask | (~BSP_FEATURE_ICU_ERROR_PERI_ERR2_REG_MASK));
 #endif
#endif
#if BSP_FEATURE_ICU_ERROR_CA55_SUPPORTED
    icu_error_base->CA55ERR_E0MSK &= (p_extend->ca55_err0_event_mask | (~ICU_ERROR_CA55_ERR_REG_MASK));
    icu_error_base->CA55ERR_E1MSK &= (p_extend->ca55_err1_event_mask | (~ICU_ERROR_CA55_ERR_REG_MASK));
#endif

#if BSP_FEATURE_ICU_ERROR_DSMIF_ERR_INTERRUPT_SUPPORTED
    icu_error_base->DSMIFERR_E0MSK[0] &=
        (p_extend->dsmif_err0_event_0_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR0_REG_MASK));
    icu_error_base->DSMIFERR_E0MSK[1] &=
        (p_extend->dsmif_err0_event_1_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR1_REG_MASK));
    icu_error_base->DSMIFERR_E0MSK[2] &=
        (p_extend->dsmif_err0_event_2_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR2_REG_MASK));
    icu_error_base->DSMIFERR_E0MSK[3] &=
        (p_extend->dsmif_err0_event_3_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR3_REG_MASK));
    icu_error_base->DSMIFERR_E0MSK[4] &=
        (p_extend->dsmif_err0_event_4_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR4_REG_MASK));
    icu_error_base->DSMIFERR_E0MSK[5] &=
        (p_extend->dsmif_err0_event_5_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR5_REG_MASK));
    icu_error_base->DSMIFERR_E0MSK[7] &=
        (p_extend->dsmif_err0_event_7_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR7_REG_MASK));
    icu_error_base->DSMIFERR_E0MSK[8] &=
        (p_extend->dsmif_err0_event_8_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR8_REG_MASK));
    icu_error_base->DSMIFERR_E0MSK[10] &=
        (p_extend->dsmif_err0_event_10_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR10_REG_MASK));
    icu_error_base->DSMIFERR_E0MSK[11] &=
        (p_extend->dsmif_err0_event_11_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR11_REG_MASK));
#endif
#if BSP_FEATURE_ICU_ERROR_ENCIF_ERR_INTERRUPT_SUPPORTED
    icu_error_base->ENCIFERR_E0MSK[0] &=
        (p_extend->encif_err0_event_0_mask | (~BSP_FEATURE_ICU_ERROR_ENCIF_ERR0_REG_MASK));
    icu_error_base->ENCIFERR_E0MSK[1] &=
        (p_extend->encif_err0_event_1_mask | (~BSP_FEATURE_ICU_ERROR_ENCIF_ERR1_REG_MASK));
    icu_error_base->ENCIFERR_E0MSK[2] &=
        (p_extend->encif_err0_event_2_mask | (~BSP_FEATURE_ICU_ERROR_ENCIF_ERR2_REG_MASK));
    icu_error_base->ENCIFERR_E0MSK[3] &=
        (p_extend->encif_err0_event_3_mask | (~BSP_FEATURE_ICU_ERROR_ENCIF_ERR3_REG_MASK));
    icu_error_base->ENCIFERR_E0MSK[4] &=
        (p_extend->encif_err0_event_4_mask | (~BSP_FEATURE_ICU_ERROR_ENCIF_ERR4_REG_MASK));
#endif

#if 3U == BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE
    icu_error_base->PERIERR_E1MSK[0] &=
        (p_extend->peri_err1_event_0_mask | (~BSP_FEATURE_ICU_ERROR_PERI_ERR0_REG_MASK));
    icu_error_base->PERIERR_E1MSK[1] &=
        (p_extend->peri_err1_event_1_mask | (~BSP_FEATURE_ICU_ERROR_PERI_ERR1_REG_MASK));
 #if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    icu_error_base->PERIERR_E1MSK[2] &=
        (p_extend->peri_err1_event_2_mask | (~BSP_FEATURE_ICU_ERROR_PERI_ERR2_REG_MASK));
 #endif
#else
    icu_error_base->PERIERR_E1MSK0 &= (p_extend->peri_err1_event_0_mask | (~BSP_FEATURE_ICU_ERROR_PERI_ERR0_REG_MASK));
    icu_error_base->PERIERR_E1MSK1 &= (p_extend->peri_err1_event_1_mask | (~BSP_FEATURE_ICU_ERROR_PERI_ERR1_REG_MASK));
 #if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    icu_error_base->PERIERR_E1MSK2 &= (p_extend->peri_err1_event_2_mask | (~BSP_FEATURE_ICU_ERROR_PERI_ERR2_REG_MASK));
 #endif
#endif
#if BSP_FEATURE_ICU_ERROR_DSMIF_ERR_INTERRUPT_SUPPORTED
    icu_error_base->DSMIFERR_E1MSK[0] &=
        (p_extend->dsmif_err1_event_0_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR0_REG_MASK));
    icu_error_base->DSMIFERR_E1MSK[1] &=
        (p_extend->dsmif_err1_event_1_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR1_REG_MASK));
    icu_error_base->DSMIFERR_E1MSK[2] &=
        (p_extend->dsmif_err1_event_2_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR2_REG_MASK));
    icu_error_base->DSMIFERR_E1MSK[3] &=
        (p_extend->dsmif_err1_event_3_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR3_REG_MASK));
    icu_error_base->DSMIFERR_E1MSK[4] &=
        (p_extend->dsmif_err1_event_4_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR4_REG_MASK));
    icu_error_base->DSMIFERR_E1MSK[5] &=
        (p_extend->dsmif_err1_event_5_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR5_REG_MASK));
    icu_error_base->DSMIFERR_E1MSK[7] &=
        (p_extend->dsmif_err1_event_7_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR7_REG_MASK));
    icu_error_base->DSMIFERR_E1MSK[8] &=
        (p_extend->dsmif_err1_event_8_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR8_REG_MASK));
    icu_error_base->DSMIFERR_E1MSK[10] &=
        (p_extend->dsmif_err1_event_10_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR10_REG_MASK));
    icu_error_base->DSMIFERR_E1MSK[11] &=
        (p_extend->dsmif_err1_event_11_mask | (~BSP_FEATURE_ICU_ERROR_DSMIF_ERR11_REG_MASK));
#endif
#if BSP_FEATURE_ICU_ERROR_ENCIF_ERR_INTERRUPT_SUPPORTED
    icu_error_base->ENCIFERR_E1MSK[0] &=
        (p_extend->encif_err1_event_0_mask | (~BSP_FEATURE_ICU_ERROR_ENCIF_ERR0_REG_MASK));
    icu_error_base->ENCIFERR_E1MSK[1] &=
        (p_extend->encif_err1_event_1_mask | (~BSP_FEATURE_ICU_ERROR_ENCIF_ERR1_REG_MASK));
    icu_error_base->ENCIFERR_E1MSK[2] &=
        (p_extend->encif_err1_event_2_mask | (~BSP_FEATURE_ICU_ERROR_ENCIF_ERR2_REG_MASK));
    icu_error_base->ENCIFERR_E1MSK[3] &=
        (p_extend->encif_err1_event_3_mask | (~BSP_FEATURE_ICU_ERROR_ENCIF_ERR3_REG_MASK));
    icu_error_base->ENCIFERR_E1MSK[4] &=
        (p_extend->encif_err1_event_4_mask | (~BSP_FEATURE_ICU_ERROR_ENCIF_ERR4_REG_MASK));
#endif

    /* Enable interrupts in GIC. */
    if (p_extend->cpu0_err0_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_extend->cpu0_err0_irq, p_extend->cpu0_err0_ipl, p_instance_ctrl);
    }

    if (p_extend->cpu0_err1_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_extend->cpu0_err1_irq, p_extend->cpu0_err1_ipl, p_instance_ctrl);
    }

#if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    if (p_extend->cpu1_err0_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_extend->cpu1_err0_irq, p_extend->cpu1_err0_ipl, p_instance_ctrl);
    }

    if (p_extend->cpu1_err1_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_extend->cpu1_err1_irq, p_extend->cpu1_err1_ipl, p_instance_ctrl);
    }
#endif
#if BSP_FEATURE_ICU_ERROR_CA55_SUPPORTED
    if (p_extend->ca55_err0_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_extend->ca55_err0_irq, p_extend->ca55_err0_ipl, p_instance_ctrl);
    }

    if (p_extend->ca55_err1_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_extend->ca55_err1_irq, p_extend->ca55_err1_ipl, p_instance_ctrl);
    }
#endif
    if (p_extend->peri_err0_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_extend->peri_err0_irq, p_extend->peri_err0_ipl, p_instance_ctrl);
    }

    if (p_extend->peri_err1_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_extend->peri_err1_irq, p_extend->peri_err1_ipl, p_instance_ctrl);
    }

#if BSP_FEATURE_ICU_ERROR_DSMIF_ERR_INTERRUPT_SUPPORTED
    if (p_extend->dsmif_err0_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_extend->dsmif_err0_irq, p_extend->dsmif_err0_ipl, p_instance_ctrl);
    }

    if (p_extend->dsmif_err1_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_extend->dsmif_err1_irq, p_extend->dsmif_err1_ipl, p_instance_ctrl);
    }
#endif
#if BSP_FEATURE_ICU_ERROR_ENCIF_ERR_INTERRUPT_SUPPORTED
    if (p_extend->encif_err0_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_extend->encif_err0_irq, p_extend->encif_err0_ipl, p_instance_ctrl);
    }

    if (p_extend->encif_err1_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_extend->encif_err1_irq, p_extend->encif_err1_ipl, p_instance_ctrl);
    }
#endif

    gp_peri_error_handler_table = p_extend->p_error_handler_table;
#if BSP_FEATURE_ICU_ERROR_DSMIF_ERR_INTERRUPT_SUPPORTED
    gp_dsmif_error_handler_table = p_extend->p_dsmif_error_handler_table;
#endif
#if BSP_FEATURE_ICU_ERROR_ENCIF_ERR_INTERRUPT_SUPPORTED
    gp_encif_error_handler_table = p_extend->p_encif_error_handler_table;
#endif

    /* Mark driver as open by initializing it to "ERR" in its ASCII equivalent. */
    p_instance_ctrl->open = ICU_ERROR_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Closes the module driver.
 *
 * @retval FSP_SUCCESS          Module successfully closed.
 * @retval FSP_ERR_NOT_OPEN     Driver not open.
 * @retval FSP_ERR_ASSERTION    Pointer pointing to NULL.
 *
 * @note This function will disable the ERROR interrupt in the GIC.
 **********************************************************************************************************************/
fsp_err_t R_ICU_ERROR_Close (error_ctrl_t * const p_ctrl)
{
    icu_error_instance_ctrl_t * p_instance_ctrl = (icu_error_instance_ctrl_t *) p_ctrl;

    /* Validate the parameter and check if the module is initialized */
#if ICU_ERROR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(ICU_ERROR_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    icu_error_extended_cfg_t * p_extend = ((icu_error_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend);

#if 3U == BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE
    R_ICU_NS_Type * icu_error_base = (R_ICU_NS_Type *) R_ICU_NS_BASE;
#else
    R_ICU_Type * icu_error_base = (R_ICU_Type *) R_ICU_BASE;
#endif

    /* To avoid overwriting values set by other CPU cores, OR operation is performed. */
#if 3U == BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE
    icu_error_base->CR520ERR_RSTMSK |= ((~p_extend->cpu0_err_reset_mask) & ICU_ERROR_CR52_ERR_REG_MASK);
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    icu_error_base->CR521ERR_RSTMSK |= ((~p_extend->cpu1_err_reset_mask) & ICU_ERROR_CR52_ERR_REG_MASK);
 #endif
    icu_error_base->PERIERR_RSTMSK[0] |=
        ((~p_extend->peri_err_event_0_reset_mask) & BSP_FEATURE_ICU_ERROR_PERI_ERR0_REG_MASK);
    icu_error_base->PERIERR_RSTMSK[1] |=
        ((~p_extend->peri_err_event_1_reset_mask) & BSP_FEATURE_ICU_ERROR_PERI_ERR1_REG_MASK);
 #if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    icu_error_base->PERIERR_RSTMSK[2] |=
        ((~p_extend->peri_err_event_2_reset_mask) & BSP_FEATURE_ICU_ERROR_PERI_ERR2_REG_MASK);
 #endif
#else
    icu_error_base->CPU0ERR_RSTMSK |= ((~p_extend->cpu0_err_reset_mask) & ICU_ERROR_CR52_ERR_REG_MASK);
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    icu_error_base->CPU1ERR_RSTMSK |= ((~p_extend->cpu1_err_reset_mask) & ICU_ERROR_CR52_ERR_REG_MASK);
 #endif
    icu_error_base->PERIERR_RSTMSK0 |=
        ((~p_extend->peri_err_event_0_reset_mask) & BSP_FEATURE_ICU_ERROR_PERI_ERR0_REG_MASK);
    icu_error_base->PERIERR_RSTMSK1 |=
        ((~p_extend->peri_err_event_1_reset_mask) & BSP_FEATURE_ICU_ERROR_PERI_ERR1_REG_MASK);
 #if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    icu_error_base->PERIERR_RSTMSK2 |=
        ((~p_extend->peri_err_event_2_reset_mask) & BSP_FEATURE_ICU_ERROR_PERI_ERR2_REG_MASK);
 #endif
#endif
#if BSP_FEATURE_ICU_ERROR_CA55_SUPPORTED
    icu_error_base->CA55ERR_RSTMSK |= ((~p_extend->ca55_err_reset_mask) & ICU_ERROR_CA55_ERR_REG_MASK);
#endif

#if BSP_FEATURE_ICU_ERROR_DSMIF_ERR_INTERRUPT_SUPPORTED
    icu_error_base->DSMIFERR_RSTMSK[0] |=
        ((~p_extend->dsmif_err_event_0_reset_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR0_REG_MASK);
    icu_error_base->DSMIFERR_RSTMSK[1] |=
        ((~p_extend->dsmif_err_event_1_reset_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR1_REG_MASK);
    icu_error_base->DSMIFERR_RSTMSK[2] |=
        ((~p_extend->dsmif_err_event_2_reset_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR2_REG_MASK);
    icu_error_base->DSMIFERR_RSTMSK[3] |=
        ((~p_extend->dsmif_err_event_3_reset_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR3_REG_MASK);
    icu_error_base->DSMIFERR_RSTMSK[4] |=
        ((~p_extend->dsmif_err_event_4_reset_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR4_REG_MASK);
    icu_error_base->DSMIFERR_RSTMSK[5] |=
        ((~p_extend->dsmif_err_event_5_reset_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR5_REG_MASK);
    icu_error_base->DSMIFERR_RSTMSK[7] |=
        ((~p_extend->dsmif_err_event_7_reset_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR7_REG_MASK);
    icu_error_base->DSMIFERR_RSTMSK[8] |=
        ((~p_extend->dsmif_err_event_8_reset_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR8_REG_MASK);
    icu_error_base->DSMIFERR_RSTMSK[10] |=
        ((~p_extend->dsmif_err_event_10_reset_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR10_REG_MASK);
    icu_error_base->DSMIFERR_RSTMSK[11] |=
        ((~p_extend->dsmif_err_event_11_reset_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR11_REG_MASK);
#endif
#if BSP_FEATURE_ICU_ERROR_ENCIF_ERR_INTERRUPT_SUPPORTED
    icu_error_base->ENCIFERR_RSTMSK[0] |=
        ((~p_extend->encif_err_event_0_reset_mask) & BSP_FEATURE_ICU_ERROR_ENCIF_ERR0_REG_MASK);
    icu_error_base->ENCIFERR_RSTMSK[1] |=
        ((~p_extend->encif_err_event_1_reset_mask) & BSP_FEATURE_ICU_ERROR_ENCIF_ERR1_REG_MASK);
    icu_error_base->ENCIFERR_RSTMSK[2] |=
        ((~p_extend->encif_err_event_2_reset_mask) & BSP_FEATURE_ICU_ERROR_ENCIF_ERR2_REG_MASK);
    icu_error_base->ENCIFERR_RSTMSK[3] |=
        ((~p_extend->encif_err_event_3_reset_mask) & BSP_FEATURE_ICU_ERROR_ENCIF_ERR3_REG_MASK);
    icu_error_base->ENCIFERR_RSTMSK[4] |=
        ((~p_extend->encif_err_event_4_reset_mask) & BSP_FEATURE_ICU_ERROR_ENCIF_ERR4_REG_MASK);
#endif

    /* ICU_ERROR event mask configure. */
#if 3U == BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE
    icu_error_base->CR520ERR_E0MSK |= ((~p_extend->cpu0_err0_event_mask) & ICU_ERROR_CR52_ERR_REG_MASK);
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    icu_error_base->CR521ERR_E0MSK |= ((~p_extend->cpu1_err0_event_mask) & ICU_ERROR_CR52_ERR_REG_MASK);
 #endif
    icu_error_base->PERIERR_E0MSK[0] |=
        ((~p_extend->peri_err0_event_0_mask) & BSP_FEATURE_ICU_ERROR_PERI_ERR0_REG_MASK);
    icu_error_base->PERIERR_E0MSK[1] |=
        ((~p_extend->peri_err0_event_1_mask) & BSP_FEATURE_ICU_ERROR_PERI_ERR1_REG_MASK);
 #if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    icu_error_base->PERIERR_E0MSK[2] |=
        ((~p_extend->peri_err0_event_2_mask) & BSP_FEATURE_ICU_ERROR_PERI_ERR2_REG_MASK);
 #endif
#else
    icu_error_base->CPU0ERR_E0MSK |= ((~p_extend->cpu0_err0_event_mask) & ICU_ERROR_CR52_ERR_REG_MASK);
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    icu_error_base->CPU1ERR_E0MSK |= ((~p_extend->cpu1_err0_event_mask) & ICU_ERROR_CR52_ERR_REG_MASK);
 #endif
    icu_error_base->PERIERR_E0MSK0 |= ((~p_extend->peri_err0_event_0_mask) & BSP_FEATURE_ICU_ERROR_PERI_ERR0_REG_MASK);
    icu_error_base->PERIERR_E0MSK1 |= ((~p_extend->peri_err0_event_1_mask) & BSP_FEATURE_ICU_ERROR_PERI_ERR1_REG_MASK);
 #if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    icu_error_base->PERIERR_E0MSK2 |= ((~p_extend->peri_err0_event_2_mask) & BSP_FEATURE_ICU_ERROR_PERI_ERR2_REG_MASK);
 #endif
#endif
#if BSP_FEATURE_ICU_ERROR_CA55_SUPPORTED
    icu_error_base->CA55ERR_E0MSK |= ((~p_extend->ca55_err0_event_mask) & ICU_ERROR_CA55_ERR_REG_MASK);
#endif

#if BSP_FEATURE_ICU_ERROR_DSMIF_ERR_INTERRUPT_SUPPORTED
    icu_error_base->DSMIFERR_E0MSK[0] |=
        ((~p_extend->dsmif_err0_event_0_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR0_REG_MASK);
    icu_error_base->DSMIFERR_E0MSK[1] |=
        ((~p_extend->dsmif_err0_event_1_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR1_REG_MASK);
    icu_error_base->DSMIFERR_E0MSK[2] |=
        ((~p_extend->dsmif_err0_event_2_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR2_REG_MASK);
    icu_error_base->DSMIFERR_E0MSK[3] |=
        ((~p_extend->dsmif_err0_event_3_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR3_REG_MASK);
    icu_error_base->DSMIFERR_E0MSK[4] |=
        ((~p_extend->dsmif_err0_event_4_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR4_REG_MASK);
    icu_error_base->DSMIFERR_E0MSK[5] |=
        ((~p_extend->dsmif_err0_event_5_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR5_REG_MASK);
    icu_error_base->DSMIFERR_E0MSK[7] |=
        ((~p_extend->dsmif_err0_event_7_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR7_REG_MASK);
    icu_error_base->DSMIFERR_E0MSK[8] |=
        ((~p_extend->dsmif_err0_event_8_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR8_REG_MASK);
    icu_error_base->DSMIFERR_E0MSK[10] |=
        ((~p_extend->dsmif_err0_event_10_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR10_REG_MASK);
    icu_error_base->DSMIFERR_E0MSK[11] |=
        ((~p_extend->dsmif_err0_event_11_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR11_REG_MASK);
#endif
#if BSP_FEATURE_ICU_ERROR_ENCIF_ERR_INTERRUPT_SUPPORTED
    icu_error_base->ENCIFERR_E0MSK[0] |=
        ((~p_extend->encif_err0_event_0_mask) & BSP_FEATURE_ICU_ERROR_ENCIF_ERR0_REG_MASK);
    icu_error_base->ENCIFERR_E0MSK[1] |=
        ((~p_extend->encif_err0_event_1_mask) & BSP_FEATURE_ICU_ERROR_ENCIF_ERR1_REG_MASK);
    icu_error_base->ENCIFERR_E0MSK[2] |=
        ((~p_extend->encif_err0_event_2_mask) & BSP_FEATURE_ICU_ERROR_ENCIF_ERR2_REG_MASK);
    icu_error_base->ENCIFERR_E0MSK[3] |=
        ((~p_extend->encif_err0_event_3_mask) & BSP_FEATURE_ICU_ERROR_ENCIF_ERR3_REG_MASK);
    icu_error_base->ENCIFERR_E0MSK[4] |=
        ((~p_extend->encif_err0_event_4_mask) & BSP_FEATURE_ICU_ERROR_ENCIF_ERR4_REG_MASK);
#endif

#if 3U == BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE
    icu_error_base->CR520ERR_E1MSK |= ((~p_extend->cpu0_err1_event_mask) & ICU_ERROR_CR52_ERR_REG_MASK);
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    icu_error_base->CR521ERR_E1MSK |= ((~p_extend->cpu1_err1_event_mask) & ICU_ERROR_CR52_ERR_REG_MASK);
 #endif
    icu_error_base->PERIERR_E1MSK[0] |=
        ((~p_extend->peri_err1_event_0_mask) & BSP_FEATURE_ICU_ERROR_PERI_ERR0_REG_MASK);
    icu_error_base->PERIERR_E1MSK[1] |=
        ((~p_extend->peri_err1_event_1_mask) & BSP_FEATURE_ICU_ERROR_PERI_ERR1_REG_MASK);
 #if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    icu_error_base->PERIERR_E1MSK[2] |=
        ((~p_extend->peri_err1_event_2_mask) & BSP_FEATURE_ICU_ERROR_PERI_ERR2_REG_MASK);
 #endif
#else
    icu_error_base->CPU0ERR_E1MSK |= ((~p_extend->cpu0_err1_event_mask) & ICU_ERROR_CR52_ERR_REG_MASK);
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    icu_error_base->CPU1ERR_E1MSK |= ((~p_extend->cpu1_err1_event_mask) & ICU_ERROR_CR52_ERR_REG_MASK);
 #endif
    icu_error_base->PERIERR_E1MSK0 |=
        ((~p_extend->peri_err1_event_0_mask) & BSP_FEATURE_ICU_ERROR_PERI_ERR0_REG_MASK);
    icu_error_base->PERIERR_E1MSK1 |=
        ((~p_extend->peri_err1_event_1_mask) & BSP_FEATURE_ICU_ERROR_PERI_ERR1_REG_MASK);
 #if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    icu_error_base->PERIERR_E1MSK2 |=
        ((~p_extend->peri_err1_event_2_mask) & BSP_FEATURE_ICU_ERROR_PERI_ERR2_REG_MASK);
 #endif
#endif
#if BSP_FEATURE_ICU_ERROR_CA55_SUPPORTED
    icu_error_base->CA55ERR_E1MSK |= ((~p_extend->ca55_err1_event_mask) & ICU_ERROR_CA55_ERR_REG_MASK);
#endif

#if BSP_FEATURE_ICU_ERROR_DSMIF_ERR_INTERRUPT_SUPPORTED
    icu_error_base->DSMIFERR_E1MSK[0] |=
        ((~p_extend->dsmif_err1_event_0_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR0_REG_MASK);
    icu_error_base->DSMIFERR_E1MSK[1] |=
        ((~p_extend->dsmif_err1_event_1_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR1_REG_MASK);
    icu_error_base->DSMIFERR_E1MSK[2] |=
        ((~p_extend->dsmif_err1_event_2_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR2_REG_MASK);
    icu_error_base->DSMIFERR_E1MSK[3] |=
        ((~p_extend->dsmif_err1_event_3_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR3_REG_MASK);
    icu_error_base->DSMIFERR_E1MSK[4] |=
        ((~p_extend->dsmif_err1_event_4_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR4_REG_MASK);
    icu_error_base->DSMIFERR_E1MSK[5] |=
        ((~p_extend->dsmif_err1_event_5_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR5_REG_MASK);
    icu_error_base->DSMIFERR_E1MSK[7] |=
        ((~p_extend->dsmif_err1_event_7_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR7_REG_MASK);
    icu_error_base->DSMIFERR_E1MSK[8] |=
        ((~p_extend->dsmif_err1_event_8_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR8_REG_MASK);
    icu_error_base->DSMIFERR_E1MSK[10] |=
        ((~p_extend->dsmif_err1_event_10_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR10_REG_MASK);
    icu_error_base->DSMIFERR_E1MSK[11] |=
        ((~p_extend->dsmif_err1_event_11_mask) & BSP_FEATURE_ICU_ERROR_DSMIF_ERR11_REG_MASK);
#endif
#if BSP_FEATURE_ICU_ERROR_ENCIF_ERR_INTERRUPT_SUPPORTED
    icu_error_base->ENCIFERR_E1MSK[0] |=
        ((~p_extend->encif_err1_event_0_mask) & BSP_FEATURE_ICU_ERROR_ENCIF_ERR0_REG_MASK);
    icu_error_base->ENCIFERR_E1MSK[1] |=
        ((~p_extend->encif_err1_event_1_mask) & BSP_FEATURE_ICU_ERROR_ENCIF_ERR1_REG_MASK);
    icu_error_base->ENCIFERR_E1MSK[2] |=
        ((~p_extend->encif_err1_event_2_mask) & BSP_FEATURE_ICU_ERROR_ENCIF_ERR2_REG_MASK);
    icu_error_base->ENCIFERR_E1MSK[3] |=
        ((~p_extend->encif_err1_event_3_mask) & BSP_FEATURE_ICU_ERROR_ENCIF_ERR3_REG_MASK);
    icu_error_base->ENCIFERR_E1MSK[4] |=
        ((~p_extend->encif_err1_event_4_mask) & BSP_FEATURE_ICU_ERROR_ENCIF_ERR4_REG_MASK);
#endif

    /* Disable the IRQ in the GIC in case it has been left enabled. */
    if (p_extend->cpu0_err0_irq >= 0)
    {
        R_BSP_IrqDisable(p_extend->cpu0_err0_irq);
        R_FSP_IsrContextSet(p_extend->cpu0_err0_irq, NULL);
    }

    if (p_extend->cpu0_err1_irq >= 0)
    {
        R_BSP_IrqDisable(p_extend->cpu0_err1_irq);
        R_FSP_IsrContextSet(p_extend->cpu0_err1_irq, NULL);
    }

#if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    if (p_extend->cpu1_err0_irq >= 0)
    {
        R_BSP_IrqDisable(p_extend->cpu1_err0_irq);
        R_FSP_IsrContextSet(p_extend->cpu1_err0_irq, NULL);
    }

    if (p_extend->cpu1_err1_irq >= 0)
    {
        R_BSP_IrqDisable(p_extend->cpu1_err1_irq);
        R_FSP_IsrContextSet(p_extend->cpu1_err1_irq, NULL);
    }
#endif
#if BSP_FEATURE_ICU_ERROR_CA55_SUPPORTED
    if (p_extend->ca55_err0_irq >= 0)
    {
        R_BSP_IrqDisable(p_extend->ca55_err0_irq);
        R_FSP_IsrContextSet(p_extend->ca55_err0_irq, NULL);
    }

    if (p_extend->ca55_err1_irq >= 0)
    {
        R_BSP_IrqDisable(p_extend->ca55_err1_irq);
        R_FSP_IsrContextSet(p_extend->ca55_err1_irq, NULL);
    }
#endif
    if (p_extend->peri_err0_irq >= 0)
    {
        R_BSP_IrqDisable(p_extend->peri_err0_irq);
        R_FSP_IsrContextSet(p_extend->peri_err0_irq, NULL);
    }

    if (p_extend->peri_err1_irq >= 0)
    {
        R_BSP_IrqDisable(p_extend->peri_err1_irq);
        R_FSP_IsrContextSet(p_extend->peri_err1_irq, NULL);
    }

#if BSP_FEATURE_ICU_ERROR_DSMIF_ERR_INTERRUPT_SUPPORTED
    if (p_extend->dsmif_err0_irq >= 0)
    {
        R_BSP_IrqDisable(p_extend->dsmif_err0_irq);
        R_FSP_IsrContextSet(p_extend->dsmif_err0_irq, NULL);
    }

    if (p_extend->dsmif_err1_irq >= 0)
    {
        R_BSP_IrqDisable(p_extend->dsmif_err1_irq);
        R_FSP_IsrContextSet(p_extend->dsmif_err1_irq, NULL);
    }
#endif
#if BSP_FEATURE_ICU_ERROR_ENCIF_ERR_INTERRUPT_SUPPORTED
    if (p_extend->encif_err0_irq >= 0)
    {
        R_BSP_IrqDisable(p_extend->encif_err0_irq);
        R_FSP_IsrContextSet(p_extend->encif_err0_irq, NULL);
    }

    if (p_extend->encif_err1_irq >= 0)
    {
        R_BSP_IrqDisable(p_extend->encif_err1_irq);
        R_FSP_IsrContextSet(p_extend->encif_err1_irq, NULL);
    }
#endif

    /* Mark driver as closed.  */
    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Returns the status
 *
 * @retval FSP_SUCCESS          Status successfully read.
 * @retval FSP_ERR_NOT_OPEN     Driver not open.
 * @retval FSP_ERR_ASSERTION    One or more pointers point to NULL.
 **********************************************************************************************************************/
fsp_err_t R_ICU_ERROR_StatusGet (error_ctrl_t * const p_ctrl, uint32_t source, uint32_t * const p_status)
{
    icu_error_instance_ctrl_t * p_instance_ctrl = (icu_error_instance_ctrl_t *) p_ctrl;

    /* Validate the parameters and check if the module is initialized */
#if ICU_ERROR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(ICU_ERROR_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    FSP_PARAMETER_NOT_USED(p_instance_ctrl);

    /* Get status register value indicated by argument */
    *p_status = *(gp_err_stat_table[source]);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Clear the status
 *
 * @note The ICU_ERROR HAL module does not clear the error status flag automatically.
 *       Need to call this function to clear the flag manually.
 *
 * @retval FSP_SUCCESS          Status successfully read.
 * @retval FSP_ERR_NOT_OPEN     Driver not open.
 * @retval FSP_ERR_ASSERTION    One or more pointers point to NULL.
 *
 **********************************************************************************************************************/
fsp_err_t R_ICU_ERROR_StatusClear (error_ctrl_t * const p_ctrl, uint32_t source, uint32_t const event)
{
    icu_error_instance_ctrl_t * p_instance_ctrl = (icu_error_instance_ctrl_t *) p_ctrl;

    FSP_PARAMETER_NOT_USED(p_instance_ctrl);

    /* Validate the parameters and check if the module is initialized */
#if ICU_ERROR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(ICU_ERROR_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Clear status register of error events indicated by arguments */
    *(gp_err_clr_table[source]) = (uint32_t) (event & g_err_mask_table[source]);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 * Implements @ref error_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_ICU_ERROR_CallbackSet (error_ctrl_t * const          p_ctrl,
                                   void (                      * p_callback)(error_callback_args_t *),
                                   void * const                  p_context,
                                   error_callback_args_t * const p_callback_memory)
{
    icu_error_instance_ctrl_t * p_instance_ctrl = (icu_error_instance_ctrl_t *) p_ctrl;

#if ICU_ERROR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(ICU_ERROR_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */
    p_instance_ctrl->p_callback        = p_callback;
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup ICU_ERROR)
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
 * Calls user callback.
 *
 * @param[in]     p_instance_ctrl     Pointer to ICU_ERROR instance control block
 * @param[in]     p_args              Pointer to arguments on stack
 **********************************************************************************************************************/
static void r_icu_error_call_callback (icu_error_instance_ctrl_t * p_instance_ctrl, error_callback_args_t * p_args)
{
    error_callback_args_t args;

    /* Store callback arguments in memory provided by user if available. */
    error_callback_args_t * p_args_memory = p_instance_ctrl->p_callback_memory;
    if (NULL == p_args_memory)
    {
        /* Use provided args struct on stack */
        p_args_memory = p_args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt. */
        args = *p_args_memory;

        /* Copy the stacked args to callback memory */
        *p_args_memory = *p_args;
    }

    p_instance_ctrl->p_callback(p_args_memory);

    if (NULL != p_instance_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_instance_ctrl->p_callback_memory = args;
    }
}

/*******************************************************************************************************************//**
 * CPU0 error ISR.
 *
 * When CPU0_ERR0 or CPU0_ERR1 interrupt fires, saves context if RTOS is used, scans CPU0 error event,
 * calls callback if one was provided in the open function and restores context if RTOS is used.
 **********************************************************************************************************************/
void error_cpu0_int_isr (void)
{
    ICU_ERROR_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used. */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    icu_error_instance_ctrl_t * p_instance_ctrl = (icu_error_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    icu_error_extended_cfg_t * p_extend = (icu_error_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* Get the current error status */
#if 3U == BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE
    uint32_t cpuerr_stat = R_ICU_NS->CR520ERR_STAT;
#else
    uint32_t cpuerr_stat = R_ICU->CPU0ERR_STAT;
#endif

    /* Extract events that are only processed by this instance */
#if 3U == BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE
    uint32_t event_mask = (irq == p_extend->cpu0_err0_irq) ? R_ICU_NS->CR520ERR_E0MSK : R_ICU_NS->CR520ERR_E1MSK;
#else
    uint32_t event_mask = (irq == p_extend->cpu0_err0_irq) ? R_ICU->CPU0ERR_E0MSK : R_ICU->CPU0ERR_E1MSK;
#endif
    cpuerr_stat &= ~event_mask;

    uint32_t cpu_error_event = 0;

    /* After going through the event scan, the interrupt handler ends */
    while (cpuerr_stat)
    {
        /* Scan and search for error factors one by one */
        uint32_t next_event = __CLZ(__RBIT(cpuerr_stat));
        cpuerr_stat    >>= next_event;
        cpu_error_event += next_event;

        /* Call the callback. */
        error_callback_args_t args;

        /* Set data to identify callback to the user. */
        args.p_context    = p_instance_ctrl->p_context;
        args.error_event  = ERROR_EVENT_CPU0;
        args.error_status = 1U << (cpu_error_event & ICU_ERROR_ERR_EVENT_SHIFT_MASK);

        /* Call the callback. */
        if (NULL != p_instance_ctrl->p_callback)
        {
            r_icu_error_call_callback(p_instance_ctrl, &args);
        }

        /* Clear the scanned flags one by one */
        cpuerr_stat &= (uint32_t) ~(1UL);
    }

    /* Error status flag in the ICU module is cleared in the user application. */

    /* Restore context if RTOS is used. */
    FSP_CONTEXT_RESTORE;

    ICU_ERROR_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

#if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED

/*******************************************************************************************************************//**
 * CPU1 error ISR.
 *
 * When CPU1_ERR0 or CPU1_ERR1 interrupt fires, saves context if RTOS is used, scans CPU1 error event,
 * calls callback if one was provided in the open function and restores context if RTOS is used.
 **********************************************************************************************************************/
void error_cpu1_int_isr (void)
{
    ICU_ERROR_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used. */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    icu_error_instance_ctrl_t * p_instance_ctrl = (icu_error_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    icu_error_extended_cfg_t * p_extend = (icu_error_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* Get the current error status */
 #if 3U == BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE
    uint32_t cpuerr_stat = R_ICU_NS->CR521ERR_STAT;
 #else
    uint32_t cpuerr_stat = R_ICU->CPU1ERR_STAT;
 #endif

    /* Extract events that are only processed by this instance */
 #if 3U == BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE
    uint32_t event_mask = (irq == p_extend->cpu1_err0_irq) ? R_ICU_NS->CR521ERR_E0MSK : R_ICU_NS->CR521ERR_E1MSK;
 #else
    uint32_t event_mask = (irq == p_extend->cpu1_err0_irq) ? R_ICU->CPU1ERR_E0MSK : R_ICU->CPU1ERR_E1MSK;
 #endif
    cpuerr_stat &= ~event_mask;

    uint32_t cpu_error_event = 0;

    /* After going through the event scan, the interrupt handler ends */
    while (cpuerr_stat)
    {
        /* Scan and search for error factors one by one */
        uint32_t next_event = __CLZ(__RBIT(cpuerr_stat));
        cpuerr_stat    >>= next_event;
        cpu_error_event += next_event;

        /* Call the callback. */
        error_callback_args_t args;

        /* Set data to identify callback to the user. */
        args.p_context    = p_instance_ctrl->p_context;
        args.error_event  = ERROR_EVENT_CPU1;
        args.error_status = 1U << (cpu_error_event & ICU_ERROR_ERR_EVENT_SHIFT_MASK);

        /* Call the callback. */
        if (NULL != p_instance_ctrl->p_callback)
        {
            r_icu_error_call_callback(p_instance_ctrl, &args);
        }

        /* Clear the scanned flags one by one */
        cpuerr_stat &= (uint32_t) ~(1UL);
    }

    /* Error status flag in the ICU module is cleared in the user application. */

    /* Restore context if RTOS is used. */
    FSP_CONTEXT_RESTORE;

    ICU_ERROR_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

#endif

#if BSP_FEATURE_ICU_ERROR_CA55_SUPPORTED

/*******************************************************************************************************************//**
 * CA55 error ISR.
 *
 * When CA55_ERR0 or CA55_ERR1 interrupt fires, saves context if RTOS is used, scans CA55 error event,
 * calls callback if one was provided in the open function and restores context if RTOS is used.
 **********************************************************************************************************************/
void error_ca55_int_isr (void)
{
    ICU_ERROR_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used. */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    icu_error_instance_ctrl_t * p_instance_ctrl = (icu_error_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    icu_error_extended_cfg_t * p_extend = (icu_error_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* Get the current error status */
    uint32_t cpuerr_stat = R_ICU_NS->CA55ERR_STAT;

    /* Extract events that are only processed by this instance */
    uint32_t event_mask = (irq == p_extend->ca55_err0_irq) ? R_ICU_NS->CA55ERR_E0MSK : R_ICU_NS->CA55ERR_E1MSK;
    cpuerr_stat &= ~event_mask;

    uint32_t cpu_error_event = 0;

    /* After going through the event scan, the interrupt handler ends */
    while (cpuerr_stat)
    {
        /* Scan and search for error factors one by one */
        uint32_t next_event = __CLZ(__RBIT(cpuerr_stat));
        cpuerr_stat    >>= next_event;
        cpu_error_event += next_event;

        /* Call the callback. */
        error_callback_args_t args;

        /* Set data to identify callback to the user. */
        args.p_context    = p_instance_ctrl->p_context;
        args.error_event  = ERROR_EVENT_CA55;
        args.error_status = 1U << (cpu_error_event & ICU_ERROR_ERR_EVENT_SHIFT_MASK);

        /* Call the callback. */
        if (NULL != p_instance_ctrl->p_callback)
        {
            r_icu_error_call_callback(p_instance_ctrl, &args);
        }

        /* Clear the scanned flags one by one */
        cpuerr_stat &= (uint32_t) ~(1UL);
    }

    /* Error status flag in the ICU module is cleared in the user application. */

    /* Restore context if RTOS is used. */
    FSP_CONTEXT_RESTORE;

    ICU_ERROR_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

#endif

/*******************************************************************************************************************//**
 * Peripheral error ISR.
 *
 * When PERI_ERR0 or PERI_ERR1 interrupt fires, saves context if RTOS is used, scans peripheral error event,
 * calls callback if one was provided in the open function and restores context if RTOS is used.
 **********************************************************************************************************************/
void error_peripherals_int_isr (void)
{
    ICU_ERROR_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used. */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    icu_error_instance_ctrl_t * p_instance_ctrl = (icu_error_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    icu_error_extended_cfg_t * p_extend = (icu_error_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    for (error_event_t source = ERROR_EVENT_PERIPHERAL_0;
         source < ERROR_EVENT_PERIPHERAL_0 + BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM;
         source++)
    {
        /* Get the current error status */
        uint32_t perierr_stat = *(gp_err_stat_table[source]);

        /* Extract events that are only processed by this instance */
        uint32_t event_mask =
            (irq == p_extend->peri_err0_irq) ? *(gp_err_e0msk_table[source]) : *(gp_err_e1msk_table[source]);
        perierr_stat &= ~event_mask;

        /* Error event number of the event at the beginning of each register */
        uint32_t event_number_offset = ICU_ERROR_ERR_REG_SIZE * (uint32_t) (source - ERROR_EVENT_PERIPHERAL_0);
        uint32_t peri_error_event    = event_number_offset;

        /* After going through the event scan, the interrupt handler ends */
        while (perierr_stat)
        {
            /* Scan and search for error factors one by one */
            uint32_t next_event = __CLZ(__RBIT(perierr_stat));
            perierr_stat    >>= next_event;
            peri_error_event += next_event;

            /* Call peripheral error handler */
            if (NULL != gp_peri_error_handler_table[peri_error_event])
            {
                gp_peri_error_handler_table[peri_error_event](peri_error_event);
            }

            /* Call the callback. */
            error_callback_args_t args;

            /* Set data to identify callback to the user. */
            args.p_context    = p_instance_ctrl->p_context;
            args.error_event  = source;
            args.error_status = 1U <<
                                ((peri_error_event - event_number_offset) &
                                 ICU_ERROR_ERR_EVENT_SHIFT_MASK);

            /* Call the callback. */
            if (NULL != p_instance_ctrl->p_callback)
            {
                r_icu_error_call_callback(p_instance_ctrl, &args);
            }

            /* Clear the scanned flags one by one */
            perierr_stat &= (uint32_t) ~(1UL);
        }
    }

    /* Error status flag in the ICU module is cleared in the user application. */

    /* Restore context if RTOS is used. */
    FSP_CONTEXT_RESTORE;

    ICU_ERROR_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

#if BSP_FEATURE_ICU_ERROR_DSMIF_ERR_INTERRUPT_SUPPORTED

/*******************************************************************************************************************//**
 * DSMIF error ISR.
 *
 * When DSMIF_ERR0 or DSMIF_ERR1 interrupt fires, saves context if RTOS is used, scans DSMIF error event,
 * calls callback if one was provided in the open function and restores context if RTOS is used.
 **********************************************************************************************************************/
void error_dsmif_int_isr (void)
{
    ICU_ERROR_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used. */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    icu_error_instance_ctrl_t * p_instance_ctrl = (icu_error_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    icu_error_extended_cfg_t * p_extend = (icu_error_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    for (error_event_t source = ERROR_EVENT_DSMIF_0;
         source < ERROR_EVENT_DSMIF_0 + BSP_FEATURE_ICU_ERROR_DSMIF_ERR_REG_NUM;
         source++)
    {
        /* Get the current error status */
        uint32_t dsmiferr_stat = *(gp_err_stat_table[source]);

        /* Extract events that are only processed by this instance */
        uint32_t event_mask =
            (irq == p_extend->dsmif_err0_irq) ? *(gp_err_e0msk_table[source]) : *(gp_err_e1msk_table[source]);
        dsmiferr_stat &= ~event_mask;

        /* Error event number of the event at the beginning of each register */
        uint32_t event_number_offset = ICU_ERROR_ERR_REG_SIZE * (uint32_t) (source - ERROR_EVENT_DSMIF_0);
        uint32_t dsmif_error_event   = event_number_offset;

        /* After going through the event scan, the interrupt handler ends */
        while (dsmiferr_stat)
        {
            /* Scan and search for error factors one by one */
            uint32_t next_event = __CLZ(__RBIT(dsmiferr_stat));
            dsmiferr_stat    >>= next_event;
            dsmif_error_event += next_event;

            /* Call peripheral error handler */
            if (NULL != gp_dsmif_error_handler_table[dsmif_error_event])
            {
                gp_dsmif_error_handler_table[dsmif_error_event](dsmif_error_event);
            }

            /* Call the callback. */
            error_callback_args_t args;

            /* Set data to identify callback to the user. */
            args.p_context    = p_instance_ctrl->p_context;
            args.error_event  = source;
            args.error_status = 1U <<
                                ((dsmif_error_event - event_number_offset) &
                                 ICU_ERROR_ERR_EVENT_SHIFT_MASK);

            /* Call the callback. */
            if (NULL != p_instance_ctrl->p_callback)
            {
                r_icu_error_call_callback(p_instance_ctrl, &args);
            }

            /* Clear the scanned flags one by one */
            dsmiferr_stat &= (uint32_t) ~(1UL);
        }
    }

    /* Error status flag in the ICU module is cleared in the user application. */

    /* Restore context if RTOS is used. */
    FSP_CONTEXT_RESTORE;

    ICU_ERROR_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

#endif

#if BSP_FEATURE_ICU_ERROR_ENCIF_ERR_INTERRUPT_SUPPORTED

/*******************************************************************************************************************//**
 * ENCIF error ISR.
 *
 * When ENCIF_ERR0 or ENCIF_ERR1 interrupt fires, saves context if RTOS is used, scans ENCIF error event,
 * calls callback if one was provided in the open function and restores context if RTOS is used.
 **********************************************************************************************************************/
void error_encif_int_isr (void)
{
    ICU_ERROR_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used. */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    icu_error_instance_ctrl_t * p_instance_ctrl = (icu_error_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    icu_error_extended_cfg_t * p_extend = (icu_error_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    for (error_event_t source = ERROR_EVENT_ENCIF_0;
         source < ERROR_EVENT_ENCIF_0 + BSP_FEATURE_ICU_ERROR_ENCIF_ERR_REG_NUM;
         source++)
    {
        /* Get the current error status */
        uint32_t enciferr_stat = *(gp_err_stat_table[source]);

        /* Extract events that are only processed by this instance */
        uint32_t event_mask =
            (irq == p_extend->encif_err0_irq) ? *(gp_err_e0msk_table[source]) : *(gp_err_e1msk_table[source]);
        enciferr_stat &= ~event_mask;

        /* Error event number of the event at the beginning of each register */
        uint32_t event_number_offset = ICU_ERROR_ERR_REG_SIZE * (uint32_t) (source - ERROR_EVENT_ENCIF_0);
        uint32_t encif_error_event   = event_number_offset;

        /* After going through the event scan, the interrupt handler ends */
        while (enciferr_stat)
        {
            /* Scan and search for error factors one by one */
            uint32_t next_event = __CLZ(__RBIT(enciferr_stat));
            enciferr_stat    >>= next_event;
            encif_error_event += next_event;

            /* Call peripheral error handler */
            if (NULL != gp_encif_error_handler_table[encif_error_event])
            {
                gp_encif_error_handler_table[encif_error_event](encif_error_event);
            }

            /* Call the callback. */
            error_callback_args_t args;

            /* Set data to identify callback to the user. */
            args.p_context    = p_instance_ctrl->p_context;
            args.error_event  = source;
            args.error_status = 1U <<
                                ((encif_error_event - event_number_offset) &
                                 ICU_ERROR_ERR_EVENT_SHIFT_MASK);

            /* Call the callback. */
            if (NULL != p_instance_ctrl->p_callback)
            {
                r_icu_error_call_callback(p_instance_ctrl, &args);
            }

            /* Clear the scanned flags one by one */
            enciferr_stat &= (uint32_t) ~(1UL);
        }
    }

    /* Error status flag in the ICU module is cleared in the user application. */

    /* Restore context if RTOS is used. */
    FSP_CONTEXT_RESTORE;

    ICU_ERROR_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

#endif
