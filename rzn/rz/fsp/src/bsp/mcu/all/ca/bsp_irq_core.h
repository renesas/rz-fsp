/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_IRQ_CORE_H
 #define BSP_IRQ_CORE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
 #define BSP_GIC_NONMASK_ACCESS                 ((uint64_t) 0xFFFFFFFFFFFFFFFF)
 #define BSP_GIC_NONSHIFT_ACCESS                (0)

 #define BSP_EVENT_SGI_PPI_ARRAY_NUM            (2U)
 #define BSP_ICU_VECTOR_MAX_ENTRIES             (BSP_VECTOR_TABLE_MAX_ENTRIES)
 #define BSP_NON_SELECTABLE_ICFGR_MAX           (BSP_FEATURE_BSP_NON_SELECTABLE_INTERRUPT_EVENT_NUM / \
                                                 BSP_INTERRUPT_TYPE_OFFSET)
 #define BSP_EVENT_ARRAY_NUM                    (BSP_FEATURE_BSP_EVENT_NUM_MAX / BSP_INTERRUPT_TYPE_OFFSET + 1U)

 #define BSP_PRV_GIC_ROUTE_MASK                 (0x0000000000FFFFFF)
 #define BSP_PRV_GIC_ROUTE_LEVEL3_MASK          (0x00000000FF000000)
 #define BSP_PRV_GIC_ROUTE_SHIFT                (8)

 #define BSP_PRV_GIC_SENSE_SHIFT                (1)

 #define BSP_PRV_GIC_PRIORITY_MASK              (0xFF)
 #define BSP_PRV_GIC_PRIORITY_SHIFT             (3)

 #define BSP_PRV_DAIF_BIT_D                     (1 << 3)
 #define BSP_PRV_DAIF_BIT_A                     (1 << 2)
 #define BSP_PRV_DAIF_BIT_I                     (1 << 1)
 #define BSP_PRV_DAIF_BIT_F                     (1 << 0)
 #define BSP_PRV_DAIF_BIT_ALL_EXCEPTION         (BSP_PRV_DAIF_BIT_D | \
                                                 BSP_PRV_DAIF_BIT_A | \
                                                 BSP_PRV_DAIF_BIT_I | \
                                                 BSP_PRV_DAIF_BIT_F)

 #if (0 == BSP_CFG_CORE_CA55)
  #define BSP_PRV_GICR_TARGET_INTREG_ADDRESS    (GICR0_TARGET0_INTREG)
  #define BSP_PRV_GICR_TARGET_IFREG_ADDRESS     (GICR0_TARGET0_IFREG)

 #elif (1 == BSP_CFG_CORE_CA55)
  #define BSP_PRV_GICR_TARGET_INTREG_ADDRESS    (GICR0_TARGET1_INTREG)
  #define BSP_PRV_GICR_TARGET_IFREG_ADDRESS     (GICR0_TARGET1_IFREG)

 #elif (2 == BSP_CFG_CORE_CA55)
  #define BSP_PRV_GICR_TARGET_INTREG_ADDRESS    (GICR0_TARGET2_INTREG)
  #define BSP_PRV_GICR_TARGET_IFREG_ADDRESS     (GICR0_TARGET2_IFREG)

 #elif (3 == BSP_CFG_CORE_CA55)
  #define BSP_PRV_GICR_TARGET_INTREG_ADDRESS    (GICR0_TARGET3_INTREG)
  #define BSP_PRV_GICR_TARGET_IFREG_ADDRESS     (GICR0_TARGET3_IFREG)

 #endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** GICD_CTLR bits. */
typedef enum
{
    BSP_GICD_CTLR_EnableGrp0   = (1UL << 0),
    BSP_GICD_CTLR_EnableGrp1NS = (1UL << 1),
    BSP_GICD_CTLR_EnableGrp1S  = (1UL << 2),
    BSP_GICD_CTLR_EnableAll    = (1UL << 2) | (1UL << 1) | (1UL << 0),
    BSP_GICD_CTLR_ARE_S        = (1UL << 4),
    BSP_GICD_CTLR_ARE_NS       = (1UL << 5),
    BSP_GICD_CTLR_DS           = (1UL << 6),
    BSP_GICD_CTLR_E1NWF        = (1UL << 7),
    BSP_GICD_CTLR_RWP          = (1UL << 31)
} bsp_gicd_ctlr_bit_t;

/** Routing mode setting. */
typedef enum
{
    BSP_GICD_IROUTER_ROUTE_AFF = (0UL << 31),
    BSP_GICD_IROUTER_ROUTE_FIX = (1UL << 31)
} bsp_gicd_irouter_route_t;

/** Interrupt types. */
typedef enum
{
    BSP_GICD_ICFGR_SENSE_LEVEL = 0UL,
    BSP_GICD_ICFGR_SENSE_EDGE  = (1UL << 1)
} bsp_gicd_icfgr_sense_t;

/** Class group settings. */
typedef enum
{
    BSP_GICD_ICLAR_CLASS0 = 0UL,
    BSP_GICD_ICLAR_CLASS1 = (1UL << 0)
} bsp_gicd_iclar_class_t;

/** GICR powerup status. */
typedef enum
{
    BSP_GICR_WAKER_PROCESSOR_SLEEP = (1UL << 1),
    BSP_GICR_WAKER_CHILDREN_ASLEEP = (1UL << 2)
} bsp_gicr_waker_mode_t;

/** Secure group settings. */
typedef enum
{
    BSP_GIC_IGROUPR_G0S  = 0UL,
    BSP_GIC_IGROUPR_G1NS = (1UL << 0),
    BSP_GIC_IGROUPR_G1S  = (1UL << 1)
} bsp_gic_igroupr_secure_t;

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZN
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZN_BSP_MCU
 *
 * @{
 **********************************************************************************************************************/

/** Which interrupts can have callbacks registered. */
typedef enum e_bsp_grp_irq
{
    BSP_GRP_IRQ_UNSUPPORTED = 0,       ///< NMI Group IRQ are not supported.
} bsp_grp_irq_t;

/* Callback type. */
typedef void (* bsp_grp_irq_cb_t)(bsp_grp_irq_t irq);

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
extern void * gp_renesas_isr_context[BSP_ICU_VECTOR_MAX_ENTRIES + BSP_CORTEX_VECTOR_TABLE_ENTRIES];

 #if (1 == BSP_FEATURE_BSP_IRQ_CR52_SEL_SUPPORTED)
extern const uint32_t BSP_GICD_ICFGR_INIT[BSP_EVENT_ARRAY_NUM];
extern const uint32_t BSP_GICR_SGI_PPI_ICFGR_INIT[BSP_EVENT_SGI_PPI_ARRAY_NUM];
 #endif

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Setting of GICD
 **********************************************************************************************************************/

void     R_BSP_GICD_SetCtlr(bsp_gicd_ctlr_bit_t bit);
uint32_t R_BSP_GICD_GetCtlr(void);
void     R_BSP_GICD_Enable(bsp_gicd_ctlr_bit_t bit);
void     R_BSP_GICD_Disable(bsp_gicd_ctlr_bit_t bit);
void     R_BSP_GICD_AffinityRouteEnable(bsp_gicd_ctlr_bit_t bit);
void     R_BSP_GICD_SpiEnable(IRQn_Type irq);
void     R_BSP_GICD_SpiDisable(IRQn_Type irq);
void     R_BSP_GICD_SetSpiPriority(IRQn_Type irq, uint32_t priority);
uint32_t R_BSP_GICD_GetSpiPriority(IRQn_Type irq);
void     R_BSP_GICD_SetSpiRoute(IRQn_Type id, uint64_t route, bsp_gicd_irouter_route_t mode);
uint64_t R_BSP_GICD_GetSpiRoute(IRQn_Type id);
void     R_BSP_GICD_SetSpiSense(IRQn_Type irq, bsp_gicd_icfgr_sense_t sense);
uint32_t R_BSP_GICD_GetSpiSense(IRQn_Type irq);
void     R_BSP_GICD_SetSpiPending(IRQn_Type irq);
uint32_t R_BSP_GICD_GetSpiPending(IRQn_Type irq);
void     R_BSP_GICD_SetSpiClearPending(IRQn_Type irq);
uint32_t R_BSP_GICD_GetSpiClearPending(IRQn_Type irq);
void     R_BSP_GICD_SetSpiSecurity(IRQn_Type irq, bsp_gic_igroupr_secure_t group);
void     R_BSP_GICD_SetSpiSecurityLine(uint32_t line, bsp_gic_igroupr_secure_t group);
void     R_BSP_GICD_SetSpiSecurityAll(bsp_gic_igroupr_secure_t group);
void     R_BSP_GICD_SetSpiClass(IRQn_Type id, bsp_gicd_iclar_class_t class_group);

/***********************************************************************************************************************
 * Setting of GICR
 **********************************************************************************************************************/

void     R_BSP_GICR_Enable(void);
void     R_BSP_GICR_SgiPpiEnable(IRQn_Type irq);
void     R_BSP_GICR_SgiPpiDisable(IRQn_Type irq);
void     R_BSP_GICR_SetSgiPpiPriority(IRQn_Type irq, uint32_t priority);
uint32_t R_BSP_GICR_GetSgiPpiPriority(IRQn_Type irq);
void     R_BSP_GICR_SetSgiPpiPriority(IRQn_Type irq, uint32_t priority);
uint32_t R_BSP_GICR_GetSgiPpiPriority(IRQn_Type irq);
void     R_BSP_GICR_SetSgiPpiSense(IRQn_Type irq, bsp_gicd_icfgr_sense_t sense);
uint32_t R_BSP_GICR_GetSgiPpiSense(IRQn_Type irq);
void     R_BSP_GICR_SetSgiPpiPending(IRQn_Type irq);
uint32_t R_BSP_GICR_GetSgiPpiPending(IRQn_Type irq);
void     R_BSP_GICR_SetSgiPpiClearPending(IRQn_Type irq);
uint32_t R_BSP_GICR_GetSgiPpiClearPending(IRQn_Type irq);
void     R_BSP_GICR_SetSgiPpiSecurity(IRQn_Type irq, bsp_gic_igroupr_secure_t group);
void     R_BSP_GICR_SetSgiPpiSecurityLine(bsp_gic_igroupr_secure_t group);
void     R_BSP_GICR_SetClass(bsp_gicd_iclar_class_t class_group);
uint32_t R_BSP_GICR_GetRoute(void);

/***********************************************************************************************************************
 * Setting of GICC
 **********************************************************************************************************************/

void     R_BSP_GICC_SetMaskLevel(uint64_t mask_level);
uint64_t R_BSP_GICC_GetMaskLevel(void);
void     R_BSP_GICC_SetEoiGrp0(IRQn_Type irq);
void     R_BSP_GICC_SetEoiGrp1(IRQn_Type irq);
uint32_t R_BSP_GICC_Get_IntIdGrp0(void);
uint32_t R_BSP_GICC_Get_IntIdGrp1(void);

/** @} (end addtogroup BSP_MCU) */
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/*******************************************************************************************************************//**
 * @brief      Sets the ISR context associated with the requested IRQ.
 *
 * @param[in]  irq            IRQ number (parameter checking must ensure the IRQ number is valid before calling this
 *                            function.
 * @param[in]  p_context      ISR context for IRQ.
 **********************************************************************************************************************/
__STATIC_INLINE void r_fsp_irq_context_set (IRQn_Type const irq, void * p_context)
{
    gp_renesas_isr_context[irq + BSP_VECTOR_NUM_OFFSET] = p_context;
}

/*******************************************************************************************************************//**
 * Clear the GIC pending interrupt.
 *
 * @param[in] irq            Interrupt for which to clear the Pending bit. Note that the enums listed for IRQn_Type are
 *                           only those for the Cortex Processor Exceptions Numbers.
 **********************************************************************************************************************/
__STATIC_INLINE void r_bsp_irq_clear_pending (IRQn_Type irq)
{
    /* Clear pending state in GIC. */
    if (irq >= 0)
    {
        R_BSP_GICD_SetSpiClearPending(irq);
    }
    else
    {
        R_BSP_GICR_SetSgiPpiClearPending(irq);
    }
}

/*******************************************************************************************************************//**
 * Get the GIC pending interrupt.
 *
 * @param[in] irq            Interrupt that gets a pending bit. Note that the enums listed for IRQn_Type are
 *                           only those for the Cortex Processor Exceptions Numbers.
 *
 * @return  Value indicating the status of the level interrupt.
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t r_bsp_irq_pending_get (IRQn_Type irq)
{
    uint32_t value = 0;

    if (irq >= 0)
    {
        value = R_BSP_GICD_GetSpiPending(irq);
    }
    else
    {
        value = R_BSP_GICR_GetSgiPpiPending(irq);
    }

    return value;
}

/*******************************************************************************************************************//**
 * Sets the interrupt priority and context.
 *
 * @param[in] irq            The IRQ number to configure.
 * @param[in] priority       GIC priority of the interrupt
 **********************************************************************************************************************/
__STATIC_INLINE void r_bsp_irq_cfg (IRQn_Type const irq, uint32_t priority)
{
    uint64_t route;

    route = R_BSP_GICR_GetRoute();

    /* Calculate route information to be given to the R_BSP_GICD_SetSpiRoute function. The second argument to
     * R_BSP_GICD_SetSpiRoute function expects Affinity level 3 value to be located from bit 39 to bit 32.
     * However, in the return value of the R_BSP_GICR_GetRoute function that refers to the Affinity value bit of
     * the GICR_TYPER register, Affinity level 3 value is located from bit 31 to bit 24. Therefore, this calculation
     * adjusts the bit position of Affinity level 3 value. */
    route = (BSP_PRV_GIC_ROUTE_MASK & route) | ((BSP_PRV_GIC_ROUTE_LEVEL3_MASK & route) << BSP_PRV_GIC_ROUTE_SHIFT);

    /* Sets information that affinity level and routing mode to identify a CPU interface that notify of interrupts. */
    R_BSP_GICD_SetSpiRoute(irq, route, BSP_GICD_IROUTER_ROUTE_AFF);

    if (irq >= 0)
    {
        /* Sets interrupt priority. */
        R_BSP_GICD_SetSpiPriority(irq, (priority << BSP_PRV_GIC_PRIORITY_SHIFT) & BSP_PRV_GIC_PRIORITY_MASK);

        /* Sets interrupt group. */
        R_BSP_GICD_SetSpiSecurity(irq, BSP_GIC_IGROUPR_G1S);

        /* Sets interrupt class to class1. */
        R_BSP_GICD_SetSpiClass(irq, BSP_GICD_ICLAR_CLASS1);
    }
    else
    {
        /* Sets interrupt priority. */
        R_BSP_GICR_SetSgiPpiPriority(irq, (priority << BSP_PRV_GIC_PRIORITY_SHIFT) & BSP_PRV_GIC_PRIORITY_MASK);

        /* Sets interrupt group. */
        R_BSP_GICR_SetSgiPpiSecurity(irq, BSP_GIC_IGROUPR_G1S);
    }
}

/*******************************************************************************************************************//**
 * Enable the IRQ in the GIC (Without clearing the pending bit).
 *
 * @param[in] irq            The IRQ number to enable. Note that the enums listed for IRQn_Type are only those for the
 *                           Cortex Processor Exceptions Numbers.
 **********************************************************************************************************************/
__STATIC_INLINE void r_bsp_irq_enable_no_clear (IRQn_Type irq)
{
    if (irq >= 0)
    {
        R_BSP_GICD_SpiEnable(irq);
    }
    else
    {
        R_BSP_GICR_SgiPpiEnable(irq);
    }
}

/*******************************************************************************************************************//**
 * Disables interrupts in the GIC.
 *
 * @param[in] irq            The IRQ number to disable in the GIC. Note that the enums listed for IRQn_Type are
 *                           only those for the Cortex Processor Exceptions Numbers.
 **********************************************************************************************************************/
__STATIC_INLINE void r_bsp_irq_disable (IRQn_Type irq)
{
    if (irq >= 0)
    {
        R_BSP_GICD_SpiDisable(irq);
    }
    else
    {
        R_BSP_GICR_SgiPpiDisable(irq);
    }
}

/*******************************************************************************************************************//**
 * Sets the interrupt detect type.
 *
 * @param[in] irq             The IRQ number to configure.
 * @param[in] detect_type     GIC detect type of the interrupt (0 : active-HIGH level, 1 : rising edge-triggerd).
 **********************************************************************************************************************/
__STATIC_INLINE void r_bsp_irq_detect_type_set (IRQn_Type const irq, uint32_t detect_type)
{
    if (irq >= 0)
    {
        R_BSP_GICD_SetSpiSense(irq, (bsp_gicd_icfgr_sense_t) (detect_type << BSP_PRV_GIC_SENSE_SHIFT));
    }
    else
    {
        R_BSP_GICR_SetSgiPpiSense(irq, (bsp_gicd_icfgr_sense_t) (detect_type << BSP_PRV_GIC_SENSE_SHIFT));
    }
}

/*******************************************************************************************************************//**
 * Sets the interrupt Group.
 *
 * @param[in] irq               The IRQ number to configure.
 * @param[in] interrupt_group   GIC interrupt group number ( 0 : FIQ, 1 : IRQ ).
 **********************************************************************************************************************/
__STATIC_INLINE void r_bsp_irq_group_set (IRQn_Type const irq, uint32_t interrupt_group)
{
    if (irq >= 0)
    {
        R_BSP_GICD_SetSpiSecurity(irq, (bsp_gic_igroupr_secure_t) interrupt_group);
    }
    else
    {
        R_BSP_GICR_SetSgiPpiSecurity(irq, (bsp_gic_igroupr_secure_t) interrupt_group);
    }
}

/*******************************************************************************************************************//**
 * ENABLE ALL_EXCEPTION
 **********************************************************************************************************************/
__STATIC_INLINE void r_bsp_enable_all_exception (void)
{
    __asm volatile (
        "MSR     DAIFCLR, %[bsp_prv_daif_bit_all_exception]     \n"
        "ISB     SY                                             \n"
        ::[bsp_prv_daif_bit_all_exception] "i" (BSP_PRV_DAIF_BIT_ALL_EXCEPTION) : "memory");
}

/*******************************************************************************************************************//**
 * Disable FIQ
 **********************************************************************************************************************/
__STATIC_INLINE void r_bsp_disable_fiq (void)
{
    __asm volatile (
        "MSR     DAIFSET, %[bsp_prv_daif_bit_f]     \n"
        "ISB     SY                                 \n"
        ::[bsp_prv_daif_bit_f] "i" (BSP_PRV_DAIF_BIT_F) : "memory");
}

/*******************************************************************************************************************//**
 * Enable FIQ
 **********************************************************************************************************************/
__STATIC_INLINE void r_bsp_enable_fiq (void)
{
    __asm volatile (
        "MSR     DAIFCLR, %[bsp_prv_daif_bit_f]     \n"
        "ISB     SY                                 \n"
        ::[bsp_prv_daif_bit_f] "i" (BSP_PRV_DAIF_BIT_F) : "memory");
}

void bsp_irq_core_cfg(void);

fsp_err_t R_BSP_GroupIrqWrite(bsp_grp_irq_t irq, void (* p_callback)(bsp_grp_irq_t irq));

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
