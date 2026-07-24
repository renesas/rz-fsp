/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "bsp_api.h"
#include "bsp_select_irq.h"

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Private global variables and functions
 *********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZV
{
#endif
#endif

/******************************************************************************************************************//**
 * @addtogroup RZV_BSP_MCU
 *
 * @{
 *********************************************************************************************************************/

#if defined(BSP_FEATURE_ICU_HAS_SELECT_INT)

/******************************************************************************************************************//**
 * Set SELECT Interrupt.
 *
 * @param[in]  irq          The target SPI number
 * @param[in]  irqsel       The source of the event signal
 *
 * @retval     FSP_SUCCESS
 *********************************************************************************************************************/
fsp_err_t R_BSP_SelectIrqSet (IRQn_Type irq, IRQSELn_Type irqsel)
{
    volatile uint32_t * intselx_addr = BSP_FEATURE_INTC_SEL_REG;
    uint32_t            intselx_value;
    uint32_t            nregs;
    uint32_t            shift;

 #if BSP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT((uint32_t) irq < BSP_FEATURE_SELECT_IRQ_MIN);
    FSP_ASSERT(BSP_FEATURE_SELECT_IRQ_MAX < (uint32_t) irq);
 #endif

    FSP_CRITICAL_SECTION_DEFINE;

    nregs = ((uint32_t) ((uint32_t) irq - BSP_FEATURE_SELECT_IRQ_MIN)) / BSP_PRV_SELECT_IRQ_PER_REG;
    shift = (((uint32_t) ((uint32_t) irq - BSP_FEATURE_SELECT_IRQ_MIN)) % BSP_PRV_SELECT_IRQ_PER_REG) *
            BSP_PRV_SELECT_IRQ_PER_BIT;
    intselx_addr += nregs;
    FSP_CRITICAL_SECTION_ENTER;

    /* Read original value */
    intselx_value = *intselx_addr;

    /* Clear specified field */
    intselx_value &= ~(BSP_PRV_SELECT_IRQSEL_MASK << shift);

    /* Set specified number */
    intselx_value |= (irqsel << shift);

    /* Write modified value */
    *intselx_addr = intselx_value;

    FSP_CRITICAL_SECTION_EXIT;

    return FSP_SUCCESS;
}

#endif

/** @} (end addtogroup RZV_BSP_MCU) */

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif
