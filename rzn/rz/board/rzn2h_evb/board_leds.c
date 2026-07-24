/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * File Name    : board_leds.c
 * Description  : This module has information about the LEDs on this board.
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BOARD_RZN2H_EVB_LEDS
 *
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#if defined(BOARD_RZN2H_EVB)

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/** Array of LED IOPORT pins. */
static const uint32_t g_bsp_prv_leds[][2] =
{
 #if defined(BSP_CFG_CORE_CR52)
  #if (0 == BSP_CFG_CORE_CR52)
    {(uint32_t) BSP_IO_PORT_31_PIN_6, (uint32_t) BSP_IO_REGION_NOT_SAFE_DEDICATED} ///< LED3(Green)
  #elif (1 == BSP_CFG_CORE_CR52)
    {(uint32_t) BSP_IO_PORT_18_PIN_1, (uint32_t) BSP_IO_REGION_NOT_SAFE_DEDICATED} ///< LED4(Red)
  #endif
 #elif defined(BSP_CFG_CORE_CA55)
  #if (0 == BSP_CFG_CORE_CA55)
    {(uint32_t) BSP_IO_PORT_14_PIN_6, (uint32_t) BSP_IO_REGION_NOT_SAFE_DEDICATED}               ///< LED8(Green)
  #elif (1 == BSP_CFG_CORE_CA55)
    {(uint32_t) BSP_IO_PORT_14_PIN_7, (uint32_t) BSP_IO_REGION_NOT_SAFE_DEDICATED} ///< LED9(Green)
  #elif (2 == BSP_CFG_CORE_CA55)
    {(uint32_t) BSP_IO_PORT_02_PIN_7, (uint32_t) BSP_IO_REGION_SAFE}               ///< LED10(Yellow)
  #elif (3 == BSP_CFG_CORE_CA55)
    {(uint32_t) BSP_IO_PORT_03_PIN_0, (uint32_t) BSP_IO_REGION_SAFE}               ///< LED11(Red)
  #endif
 #endif
};

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/** Structure with LED information for this board. */

const bsp_leds_t g_bsp_leds =
{
    .led_count = (uint16_t) (sizeof(g_bsp_prv_leds) / sizeof(g_bsp_prv_leds[0])),
    .p_leds    = g_bsp_prv_leds
};

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

#endif

/** @} (end addtogroup BOARD_RZN2H_EVB_LEDS) */
