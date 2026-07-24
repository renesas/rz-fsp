/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_IRQ_H
 #define BSP_IRQ_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
 #define BSP_GIC_NONSHIFT_ACCESS    (0)

 #define BSP_PRV_GIC_BITS2          (2U)
 #define BSP_PRV_GIC_BITS8          (8U)

 #define BSP_PRV_GIC_STRIDE04       (4U)
 #define BSP_PRV_GIC_STRIDE16       (16U)
 #define BSP_PRV_GIC_STRIDE32       (32U)

 #define BSP_PRV_GIC_MASK_2BIT      (0x03U)
 #define BSP_PRV_GIC_MASK_8BIT      (0xFFU)
 #define BSP_PRV_GIC_MASK_32BIT     (0xFFFFFFFFU)

/* 1023 is special interrupt ID for GIC */
 #define BSP_GIC_SPECIAL_ID         (1023)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
extern void * gp_renesas_isr_context[BSP_ICU_VECTOR_MAX_ENTRIES + BSP_CORTEX_VECTOR_TABLE_ENTRIES];
extern uint8_t g_gic_detect_type[BSP_ICU_VECTOR_MAX_ENTRIES + BSP_CORTEX_VECTOR_TABLE_ENTRIES];

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief      Sets the ISR context associated with the requested IRQ.
 *
 * @param[in]  irq            IRQ number (parameter checking must ensure the IRQ number is valid before calling this
 *                            function.
 * @param[in]  p_context      ISR context for IRQ.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_FSP_IsrContextSet (IRQn_Type const irq, void * p_context)
{
    uint32_t irq_no = (uint32_t) irq + BSP_CORTEX_VECTOR_TABLE_ENTRIES;

    /* This provides access to the ISR context array defined in bsp_irq.c. This is an inline function instead of
     * being part of bsp_irq.c for performance considerations because it is used in interrupt service routines. */
    gp_renesas_isr_context[irq_no] = p_context;
}

/*******************************************************************************************************************//**
 * @brief      Finds the ISR context associated with the requested IRQ.
 *
 * @param[in]  irq            IRQ number (parameter checking must ensure the IRQ number is valid before calling this
 *                            function.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 *
 * @return  ISR context for IRQ.
 **********************************************************************************************************************/
__STATIC_INLINE void * R_FSP_IsrContextGet (IRQn_Type const irq)
{
    uint32_t irq_no = (uint32_t) irq + BSP_CORTEX_VECTOR_TABLE_ENTRIES;

    /* This provides access to the ISR context array defined in bsp_irq.c. This is an inline function instead of
     * being part of bsp_irq.c for performance considerations because it is used in interrupt service routines. */
    return gp_renesas_isr_context[irq_no];
}

 #if BSP_CFG_INLINE_IRQ_FUNCTIONS

/*******************************************************************************************************************//**
 * Sets the interrupt detect type.
 *
 * @param[in] irq             The IRQ number to configure.
 * @param[in] detect_type     GIC detect type of the interrupt
 *                            (BSP_GIC_SPI_DETECT_LEVEL : level-sensitive, BSP_GIC_SPI_DETECT_EDGE : edge-triggerd).
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqDetectTypeSet (IRQn_Type const irq, uint8_t detect_type)
{
    volatile uint32_t * p_reg_addr;
    uint32_t            shift;
    uint32_t            mask;
    uint32_t            irq_no = (uint32_t) irq + BSP_CORTEX_VECTOR_TABLE_ENTRIES;

    /* GICD_ICDICFRn has 16 sources in the 32 bits                    */
    /* The n can be calculated by irq div 16                          */
    /* The bit field width is 2 bit, and low bit is reserved          */
    /* The target bit can be calculated by irq mod 16, and multiply 2 */
    p_reg_addr = &R_INTC_GIC->GICD_ICDICFRn;
    shift      = (irq_no % BSP_PRV_GIC_STRIDE16) * BSP_PRV_GIC_BITS2;
    mask       = (uint32_t) (BSP_PRV_GIC_MASK_2BIT << shift);

    R_BSP_IoRegWrite32((p_reg_addr + (irq_no / BSP_PRV_GIC_STRIDE16)), (uint32_t) detect_type, shift, mask);
}

/*******************************************************************************************************************//**
 * Clear the interrupt status flag for a given interrupt.
 *
 * @note This function does not implement processing on this device.
 *
 * @param[in] irq            Not used
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqStatusClear (IRQn_Type irq)
{
    FSP_PARAMETER_NOT_USED(irq);

    /* Do nothing */
}

/*******************************************************************************************************************//**
 * Clear the GIC pending interrupt.
 *
 * @param[in] irq            Interrupt for which to clear the Pending bit. Note that the enums listed for IRQn_Type are
 *                           only those for the Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exception when the IIRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqClearPending (IRQn_Type irq)
{
    volatile uint32_t * p_reg_addr;
    uint32_t            shift;
    uint32_t            irq_no = (uint32_t) irq + BSP_CORTEX_VECTOR_TABLE_ENTRIES;

    /* GICD_ICDICPRn has 32 sources in the 32 bits           */
    /* The n can be calculated by irq div 32                 */
    /* The bit field width is 1 bit                          */
    /* The target bit can be calculated by irq mod 32        */
    p_reg_addr = &R_INTC_GIC->GICD_ICDICPRn;
    shift      = (irq_no % BSP_PRV_GIC_STRIDE32); /* 1bits per unit */

    R_BSP_IoRegWrite32((p_reg_addr + (irq_no / BSP_PRV_GIC_STRIDE32)), 1, shift, BSP_IO_NONMASK_ACCESS_32);
}

/*******************************************************************************************************************//**
 * Get the GIC pending interrupt.
 *
 * @param[in] irq            Interrupt that gets a pending bit.. Note that the enums listed for IRQn_Type are
 *                           only those for the Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 *
 * @return  Value indicating the status of the level interrupt.
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t R_BSP_IrqPendingGet (IRQn_Type irq)
{
    uint32_t            shift;
    uint32_t            mask;
    uint32_t            pending;
    volatile uint32_t * p_reg_addr;
    uint32_t            irq_no = (uint32_t) irq + BSP_CORTEX_VECTOR_TABLE_ENTRIES;

    p_reg_addr = &R_INTC_GIC->GICD_ICDISPRn;

    shift   = (irq_no % BSP_PRV_GIC_STRIDE32);    /* 1bits per unit */
    mask    = (uint32_t) (0x00000001UL << shift); /* 1bits per unit */
    pending = R_BSP_IoRegRead32((p_reg_addr + (irq_no / BSP_PRV_GIC_STRIDE32)), shift, mask);

    return pending;
}

/*******************************************************************************************************************//**
 * Sets the interrupt priority and context.
 *
 * @param[in] irq            The IRQ number to configure.
 * @param[in] priority       GIC priority of the interrupt
 * @param[in] p_context      The interrupt context is a pointer to data required in the ISR.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqCfg (IRQn_Type const irq, uint32_t priority, void * p_context)
{
    volatile uint8_t * p_reg_byte_addr;
    uint8_t            cpu_id;
    uint8_t            cpu_interface_bit;
    uint32_t           irq_no = (uint32_t) irq + BSP_CORTEX_VECTOR_TABLE_ENTRIES;

    /* Initialize SPI interrupt detection type */
    R_BSP_IrqDetectTypeSet(irq, g_gic_detect_type[irq_no]);

    /* According the GICv1 Architecture Specification:
     * DIV and MOD are the integer division and modulo operations:
     * - the corresponding ICDIPR number, M, is given by irq_no DIV 4
     * - the offset of the required register is (Multiply 4)
     * - the byte offset of the required Priority field in this register is irq_no MOD 4
     */
    uint32_t M           = irq_no / BSP_PRV_GIC_STRIDE04;
    uint32_t reg_offset  = BSP_PRV_GIC_STRIDE04 * M;
    uint32_t byte_offset = irq_no % 4;

    p_reg_byte_addr = ((volatile uint8_t *) &R_INTC_GIC->GICD_ICDIPRn) + reg_offset + byte_offset;

    uint8_t set_priority = (priority << 4) & BSP_FEATURE_INTC_IRQ_PRIORITY_MASK;

    R_BSP_IoRegWrite8(p_reg_byte_addr, set_priority, 0, BSP_IO_NONMASK_ACCESS_8);

    /* set interrupt target CPU */
    p_reg_byte_addr = ((volatile uint8_t *) &R_INTC_GIC->GICD_ICDIPTRn) + reg_offset + byte_offset;

    cpu_id            = BSP_CR8_CORE_NUM;
    cpu_interface_bit = 1 << cpu_id;
    R_BSP_IoRegWrite8(p_reg_byte_addr, cpu_interface_bit, 0, BSP_IO_NONMASK_ACCESS_8);

    /* Store the context. The context is recovered in the ISR. */
    R_FSP_IsrContextSet(irq, p_context);
}

/*******************************************************************************************************************//**
 * Enable the IRQ in the GIC (Without clearing the pending bit).
 *
 * @param[in] irq            The IRQ number to enable. Note that the enums listed for IRQn_Type are only those for the
 *                           Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqEnableNoClear (IRQn_Type const irq)
{
    volatile uint32_t * p_reg_addr;
    volatile uint32_t   shift;
    uint32_t            irq_no = (uint32_t) irq + BSP_CORTEX_VECTOR_TABLE_ENTRIES;
    volatile uint32_t   tmp;

    /* GICD_ICDISERn has 32 sources in the 32 bits           */
    /* The n can be calculated by irq div 32                 */
    /* The bit field width is 1 bit                          */
    /* The target bit can be calculated by (irq mod 32) 1    */
    /* GICD_ICDISERn does not effect on writing "0"          */
    /* The bits except for the target write "0"              */
    p_reg_addr = &R_INTC_GIC->GICD_ICDISERn;
    shift      = (irq_no % BSP_PRV_GIC_STRIDE32); /* Create mask data */
    tmp        = shift;
    tmp        = 1UL << shift;

    R_BSP_IoRegWrite32((p_reg_addr + (irq_no / BSP_PRV_GIC_STRIDE32)), tmp, 0, BSP_IO_NONMASK_ACCESS_32);
}

/*******************************************************************************************************************//**
 * Enable the IRQ in the GIC (With clearing the pending bit).
 *
 * @param[in] irq            The IRQ number to enable. Note that the enums listed for IRQn_Type are only those for the
 *                           Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqEnable (IRQn_Type const irq)
{
    /* Clear pending interrupts in the GIC. */

    R_BSP_IrqClearPending(irq);

    /* Enable the interrupt in the GIC. */
    R_BSP_IrqEnableNoClear(irq);
}

/*******************************************************************************************************************//**
 * Disables interrupts in the GIC.
 *
 * @param[in] irq            The IRQ number to disable in the GIC. Note that the enums listed for IRQn_Type are
 *                           only those for the Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqDisable (IRQn_Type const irq)
{
    volatile uint32_t * p_reg_addr;
    uint32_t            shift;
    uint32_t            irq_no = (uint32_t) irq + BSP_CORTEX_VECTOR_TABLE_ENTRIES;
    volatile uint32_t   tmp;

    /* GICD_ICDICERn has 32 sources in the 32 bits           */
    /* The n can be calculated by irq div 32                 */
    /* The bit field width is 1 bit                          */
    /* The target bit can be calculated by (irq mod 32)      */
    /* GICD_ICDICERn does not effect on writing "0"          */
    /* The bits except for the target write "0"              */
    p_reg_addr = &R_INTC_GIC->GICD_ICDICERn;
    shift      = (irq_no % BSP_PRV_GIC_STRIDE32);
    tmp        = 1UL << shift;

    R_BSP_IoRegWrite32((p_reg_addr + (irq_no / BSP_PRV_GIC_STRIDE32)), tmp, 0, BSP_IO_NONMASK_ACCESS_32);

    __DSB();
    __ISB();
}

/*******************************************************************************************************************//**
 * Sets the interrupt priority and context, clears pending interrupts, then enables the interrupt.
 *
 * @param[in] irq            Interrupt number.
 * @param[in] priority       GIC priority of the interrupt
 * @param[in] p_context      The interrupt context is a pointer to data required in the ISR.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqCfgEnable (IRQn_Type const irq, uint32_t priority, void * p_context)
{
    R_BSP_IrqCfg(irq, priority, p_context);
    R_BSP_IrqEnable(irq);
}

/*******************************************************************************************************************//**
 * Sets the interrupt Group.
 *
 * @param[in] irq               The IRQ number to configure.
 * @param[in] interrupt_group   GIC interrupt group number ( 0 : FIQ, 1 : IRQ ).
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqGroupSet (IRQn_Type const irq, uint32_t interrupt_group)
{
    /* this function is not yet supported */
    FSP_PARAMETER_NOT_USED(irq);
    FSP_PARAMETER_NOT_USED(interrupt_group);
}

/*******************************************************************************************************************//**
 * Sets the interrupt priority mask level.
 *
 * @param[in] mask_level          The interrupt mask level
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqMaskLevelSet (uint32_t mask_level)
{
    FSP_CRITICAL_SECTION_SET_STATE((mask_level << BSP_FEATURE_INTC_IRQ_PRIORITY_POS_BIT) &
                                   BSP_FEATURE_INTC_IRQ_PRIORITY_MASK);
}

/*******************************************************************************************************************//**
 * Gets the interruptpriority  mask level.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 *
 * @return  Value indicating the interrupt mask level.
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t R_BSP_IrqMaskLevelGet (void)
{
    return (uint32_t) ((FSP_CRITICAL_SECTION_GET_CURRENT_STATE() & BSP_FEATURE_INTC_IRQ_PRIORITY_MASK) >>
                       BSP_FEATURE_INTC_IRQ_PRIORITY_POS_BIT);
}

 #else
void     R_BSP_IrqDetectTypeSet(IRQn_Type const irq, uint8_t detect_type);
void     R_BSP_IrqStatusClear(IRQn_Type irq);
void     R_BSP_IrqClearPending(IRQn_Type irq);
uint32_t R_BSP_IrqPendingGet(IRQn_Type irq);
void     R_BSP_IrqCfg(IRQn_Type const irq, uint32_t priority, void * p_context);
void     R_BSP_IrqEnableNoClear(IRQn_Type const irq);
void     R_BSP_IrqEnable(IRQn_Type const irq);
void     R_BSP_IrqDisable(IRQn_Type const irq);
void     R_BSP_IrqCfgEnable(IRQn_Type const irq, uint32_t priority, void * p_context);
void     R_BSP_IrqGroupSet(IRQn_Type const irq, uint32_t interrupt_group);
void     R_BSP_IrqMaskLevelSet(uint32_t mask_level);
uint32_t R_BSP_IrqMaskLevelGet(void);

 #endif

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZV
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @internal
 * @addtogroup RZV_BSP_MCU_PRV
 * @ingroup RZV_RENESAS_INTERNAL
 * @{
 **********************************************************************************************************************/

/* Public functions defined in bsp.h */
void        bsp_irq_cfg(void);         // Used internally by BSP
void        bsp_common_interrupt_handler(uint32_t id);
__WEAK void IRQ_Handler(void);

/** @} (end addtogroup RZV_BSP_MCU_PRV) */

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
