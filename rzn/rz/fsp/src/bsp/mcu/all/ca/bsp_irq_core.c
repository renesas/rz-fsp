/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_PRV_GIC_LOWEST_INTERRUPT_PRIORITY        BSP_FEATURE_BSP_IRQ_PRIORITY_MASK

#define BSP_PRV_ICC_SRE_EL3_BIT_Enable               (1 << 3)
#define BSP_PRV_ICC_SRE_EL3_BIT_DIB                  (1 << 2)
#define BSP_PRV_ICC_SRE_EL3_BIT_DFB                  (1 << 1)
#define BSP_PRV_ICC_SRE_EL3_BIT_SRE                  (1 << 0)

#define BSP_PRV_ICC_SRE_EL1_BIT_SRE                  (1 << 0)

#define BSP_PRV_GICD_CTLR_BIT_ARE_NS                 (1 << 5)
#define BSP_PRV_GICD_CTLR_BIT_ARE_S                  (1 << 4)

#define BSP_PRV_ICC_IGRPEN1_EL3_BIT_EnableGrp1S      (1 << 1)
#define BSP_PRV_ICC_IGRPEN1_EL3_BIT_EnableGrp1NS     (1 << 0)

#define BSP_PRV_GIC_REG_BITS1                        (1U)
#define BSP_PRV_GIC_REG_BITS2                        (2U)
#define BSP_PRV_GIC_REG_BITS3                        (3U)
#define BSP_PRV_GIC_REG_BITS8                        (8U)

#define BSP_PRV_GIC_REG_STRIDE04                     (4U)
#define BSP_PRV_GIC_REG_STRIDE16                     (16U)
#define BSP_PRV_GIC_REG_STRIDE32                     (32U)

#define BSP_PRV_GIC_ADD_1                            (1U)

#define BSP_PRV_GIC_SHIFT_1                          (1U)
#define BSP_PRV_GIC_SHIFT_32                         (32U)

#define BSP_PRV_GIC_REG_MASK_1BIT                    (1U)
#define BSP_PRV_GIC_REG_MASK_8BIT                    (0xFFU)
#define BSP_PRV_GIC_REG_MASK_24BIT                   (0x00FFFFFFU)
#define BSP_PRV_GIC_REG_MASK_32BIT                   (0x0FFFFFFFFU)
#define BSP_PRV_GIC_REG_MASK_SGI_PPI                 (0x1FU)

#define BSP_PRV_INTERRUPTABLE_NUM                    (32U)

#define BSP_PRV_GIC_GICR_WAKER_ProcessorSleep_Msk    (0x00000002UL)
#define BSP_PRV_GIC_GICR_WAKER_ProcessorSleep_Pos    (1UL)
#define BSP_PRV_GIC_GICR_WAKER_ChildrenAsleep_Msk    (0x00000004UL)
#define BSP_PRV_GIC_GICR_WAKER_ChildrenAsleep_Pos    (2UL)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/* This table is used to store the context in the ISR. */
void * gp_renesas_isr_context[BSP_ICU_VECTOR_MAX_ENTRIES + BSP_CORTEX_VECTOR_TABLE_ENTRIES];

extern fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES];

/* GIC current interrpt ID and variable. */
IRQn_Type g_current_interrupt_num[BSP_PRV_INTERRUPTABLE_NUM];
uint8_t   g_current_interrupt_pointer = 0;

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
uint32_t g_interrupt_nesting_count;

static void r_bsp_gic_io_regwrite_32(volatile uint32_t * ioreg, uint32_t write_value, uint32_t shift,
                                     uint64_t mask);
static uint32_t r_bsp_gic_io_regread_32(volatile const uint32_t * ioreg, uint32_t shift, uint64_t mask);

/*******************************************************************************************************************//**
 * Initialize interrupt controller.
 **********************************************************************************************************************/
void bsp_irq_core_cfg (void)
{
    uint32_t            gicd_reg_num;
    GICR_SGI_PPI_Type * GICR_TARGET_INTREG;

    g_interrupt_nesting_count = 0;
    GICR_TARGET_INTREG        = BSP_PRV_GICR_TARGET_INTREG_ADDRESS;

    /* Allow lowest priority interrupt */
    R_BSP_GICC_SetMaskLevel(BSP_PRV_GIC_LOWEST_INTERRUPT_PRIORITY);

    R_BSP_GICD_Enable(BSP_GICD_CTLR_EnableAll);

    for (gicd_reg_num = 0; gicd_reg_num < BSP_EVENT_SGI_PPI_ARRAY_NUM; gicd_reg_num++)
    {
        GICR_TARGET_INTREG->GICR_ICFGR[gicd_reg_num] = BSP_GICR_SGI_PPI_ICFGR_INIT[gicd_reg_num];
    }

    for (gicd_reg_num = 0; gicd_reg_num < BSP_EVENT_ARRAY_NUM; gicd_reg_num++)
    {
        GICD0->GICD_ICFGR[gicd_reg_num + BSP_EVENT_SGI_PPI_ARRAY_NUM] = BSP_GICD_ICFGR_INIT[gicd_reg_num];
    }

    /* Enable Interrupts */
    r_bsp_enable_all_exception();

    R_BSP_GICR_SetClass(BSP_GICD_ICLAR_CLASS1);
}

/*******************************************************************************************************************//**
 * Set GICD_CTLR Register.
 *
 * @param[in]    bit      Set value of GICD_CTRL register bit.
 **********************************************************************************************************************/
void R_BSP_GICD_SetCtlr (bsp_gicd_ctlr_bit_t bit)
{
    volatile uint32_t * p_addr;

    p_addr = &GICD0->GICD_CTLR;

    r_bsp_gic_io_regwrite_32(p_addr, (uint32_t) bit, BSP_GIC_NONSHIFT_ACCESS, BSP_GIC_NONMASK_ACCESS);
}

/*******************************************************************************************************************//**
 * Get value of GICD_CTLR Register.
 *
 * @retval GICD_CTLR register value.
 **********************************************************************************************************************/
uint32_t R_BSP_GICD_GetCtlr (void)
{
    uint32_t            value;
    volatile uint32_t * p_addr;

    p_addr = &GICD0->GICD_CTLR;
    value  = r_bsp_gic_io_regread_32(p_addr, BSP_GIC_NONSHIFT_ACCESS, BSP_GIC_NONMASK_ACCESS);

    return value;
}

/*******************************************************************************************************************//**
 * Set the values specified in the argument to EnableGrp0 bit, EnableGrp1NS bit, and EnableGrp1S bit of GICD_CTLR,
 * to enable interrupts for any interrupt group.
 *
 * @param[in]    bit      Set value of GICD_CTRL register bit.
 **********************************************************************************************************************/
void R_BSP_GICD_Enable (bsp_gicd_ctlr_bit_t bit)
{
    uint32_t value;

    value = R_BSP_GICD_GetCtlr();
    bit  &= BSP_GICD_CTLR_EnableAll;

    R_BSP_GICD_SetCtlr((bsp_gicd_ctlr_bit_t) (value | bit));
}

/*******************************************************************************************************************//**
 * Set the values specified in the argument to EnableGrp0 bit, EnableGrp1NS bit, and EnableGrp1S bit of GICD_CTLR,
 * to disable interrupts for any interrupt group.
 *
 * @param[in]    bit      Clear value of GICD_CTRL register bit.
 **********************************************************************************************************************/
void R_BSP_GICD_Disable (bsp_gicd_ctlr_bit_t bit)
{
    uint32_t value;

    value = R_BSP_GICD_GetCtlr();
    bit  &= BSP_GICD_CTLR_EnableAll;

    R_BSP_GICD_SetCtlr((bsp_gicd_ctlr_bit_t) (value & ~bit));
}

/*******************************************************************************************************************//**
 * Set the values specified in the argument to ARE_S bit and ARE_NS bit of GICD_CTLR, to enable Affinity Routing for
 * Secure state and/or Non-secure state.
 *
 * @param[in]    bit      Set value of GICD_CTRL register bit.
 **********************************************************************************************************************/
void R_BSP_GICD_AffinityRouteEnable (bsp_gicd_ctlr_bit_t bit)
{
    bit &= (BSP_GICD_CTLR_ARE_S | BSP_GICD_CTLR_ARE_NS);

    R_BSP_GICD_SetCtlr(bit);
}

/*******************************************************************************************************************//**
 * Enable interrupt forwarding to the CPU interface by set the bit of GICD_ISENABLERn to 1 corresponding to the ID
 * specified in the argument.
 *
 * @param[in]    irq      Interrupt number ID.
 **********************************************************************************************************************/
void R_BSP_GICD_SpiEnable (IRQn_Type irq)
{
    uint32_t            id;
    uint32_t            shift;
    uint32_t            mask;
    volatile uint32_t * p_addr;

    /* GICD_ISENABLERn has 32 sources in the 32 bits         */
    /* The n can be calculated by int_id / 32                */
    /* The bit field width is 1 bit                          */
    /* The target bit can be calculated by (int_id % 32) * 1 */
    /* GICD_ICENABLERn does not effect on writing "0"        */
    /* The bits except for the target write "0"              */
    id     = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    p_addr = &GICD0->GICD_ISENABLER[id / BSP_PRV_GIC_REG_STRIDE32];

    shift = id % BSP_PRV_GIC_REG_STRIDE32;
    mask  = (uint32_t) (BSP_PRV_GIC_REG_BITS1 << shift); /* Create mask data */

    *p_addr = mask;                                      /* Write GICD_ISENABLERn */
}

/*******************************************************************************************************************//**
 * Disable interrupt forwarding to the CPU interface by set the bit of GICD_ICENABLERn to 1 corresponding to the ID
 * specified in the argument.
 *
 * @param[in]    irq      Interrupt number ID.
 **********************************************************************************************************************/
void R_BSP_GICD_SpiDisable (IRQn_Type irq)
{
    uint32_t            id;
    uint32_t            shift;
    uint32_t            mask;
    volatile uint32_t * p_addr;

    /* GICD_ICENABLERn has 32 sources in the 32 bits         */
    /* The n can be calculated by int_id / 32                */
    /* The bit field width is 1 bit                          */
    /* The target bit can be calculated by (int_id % 32) * 1 */
    /* GICD_ICENABLERn does no effect on writing "0"         */
    /* Other bits except for the target write "0"            */
    id     = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    p_addr = &GICD0->GICD_ICENABLER[id / BSP_PRV_GIC_REG_STRIDE32];

    shift = id % BSP_PRV_GIC_REG_STRIDE32;
    mask  = (uint32_t) (BSP_PRV_GIC_REG_BITS1 << shift); /* Create mask data */

    *p_addr = mask;                                      /* Write GICD_ICENABLERn */
}

/*******************************************************************************************************************//**
 * Sets the value specified for GICD_IPRIORITYRn to set the interrupt priority for the specified ID.
 *
 * @param[in]    irq       Interrupt number ID.
 * @param[in]    priority  Interrupt Priority.
 **********************************************************************************************************************/
void R_BSP_GICD_SetSpiPriority (IRQn_Type irq, uint32_t priority)
{
    uint32_t            id;
    uint32_t            shift;
    uint32_t            mask;
    volatile uint32_t * p_addr;

    /* GICD_IPRIORITYRn has 4 sources in the 32 bits        */
    /* The n can be calculated by int_id / 4                */
    /* The bit field width is 8 bits                        */
    /* The target bit can be calculated by (int_id % 4) * 8 */
    id     = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    p_addr = &GICD0->GICD_IPRIORITYR[id / BSP_PRV_GIC_REG_STRIDE04];

    shift = (id % BSP_PRV_GIC_REG_STRIDE04) * BSP_PRV_GIC_REG_BITS8; /* 8bits per unit */
    mask  = (uint32_t) (BSP_PRV_GIC_REG_MASK_8BIT << shift);         /* 8bits per unit */
    r_bsp_gic_io_regwrite_32(p_addr, priority, shift, mask);
}

/*******************************************************************************************************************//**
 * Gets the interrupt priority for the specified ID by reads the value of GICD_IPRIORITYRn.
 *
 * @param[in]    irq       Interrupt number ID.
 *
 * @retval   interrupt priority.
 **********************************************************************************************************************/
uint32_t R_BSP_GICD_GetSpiPriority (IRQn_Type irq)
{
    uint32_t            id;
    uint32_t            priority;
    uint32_t            shift;
    uint32_t            mask;
    volatile uint32_t * p_addr;

    /* GICD_IPRIORITYRn has 4 sources in the 32 bits        */
    /* The n can be calculated by int_id / 4                */
    /* The bit field width is 8 bits                        */
    /* The target bit can be calculated by (int_id % 4) * 8 */
    id     = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    p_addr = &GICD0->GICD_IPRIORITYR[id / BSP_PRV_GIC_REG_STRIDE04];

    shift    = (id % BSP_PRV_GIC_REG_STRIDE04) * BSP_PRV_GIC_REG_BITS8; /* 8bits per unit */
    mask     = (uint32_t) (BSP_PRV_GIC_REG_MASK_8BIT << shift);         /* 8bits per unit */
    priority = r_bsp_gic_io_regread_32(p_addr, shift, mask);

    return priority;
}

/*******************************************************************************************************************//**
 * Set affinity routing information that is SPI Affinity level and routing mode to GICD_IROUTERn.
 *
 * @param[in]    irq      Interrupt number ID.
 * @param[in]    route    Affinity route settings. Since it will be used as it is as the setting value of the Affinity
 *                        level, write the value of Aff0 from bit 7 to bit 0, the value of Aff1 from bit 15 to bit 8,
 *                        the value of Aff2 from bit 23 to bit 16, and the value of Aff3 from bit 39 to bit 32.
 * @param[in]    mode     Mode of routing
 **********************************************************************************************************************/
void R_BSP_GICD_SetSpiRoute (IRQn_Type irq, uint64_t route, bsp_gicd_irouter_route_t mode)
{
    uint64_t            value;
    volatile uint64_t * p_addr;

    /* GICD_IROUTERn control only SPI, GICD_IROUTERn start n = 32 */
    if (irq >= 0)
    {
        /* Access 64bit wide */
        value  = route | (uint64_t) mode;
        p_addr = &GICD0->GICD_IROUTER[irq];

        *p_addr = value;
    }
}

/*******************************************************************************************************************//**
 * Get affinity routing information that is SPI Affinity level and routing mode by reads GICD_IROUTERn.
 *
 * @param[in]    irq       Interrupt number ID.
 *
 * @retval  interrupt routing information. Aff0 is stored in bit 7 to bit 0, Aff1 in bit 15 to bit 8, Aff2 in
 *           bit 23 to bit 16, Routing mode in bit 31, and Aff3 in bit 39 to bit 32.
 **********************************************************************************************************************/
uint64_t R_BSP_GICD_GetSpiRoute (IRQn_Type irq)
{
    uint64_t            value = 0;
    volatile uint64_t * p_addr;

    /* GICD_IROUTERn control only SPI, GICD_IROUTERn start n = 32 */
    if (irq >= 0)
    {
        /* Access per 32bit wide */
        p_addr = &GICD0->GICD_IROUTER[irq];

        value = *p_addr;
    }

    return value;
}

/*******************************************************************************************************************//**
 * Set interrupt as edge-triggered or level-sensitive.
 *
 * @param[in]    irq       Interrupt number ID.
 * @param[in]    sense     Interrupt trigger sense.
 **********************************************************************************************************************/
void R_BSP_GICD_SetSpiSense (IRQn_Type irq, bsp_gicd_icfgr_sense_t sense)
{
    uint32_t            id;
    uint32_t            shift;
    uint32_t            mask;
    volatile uint32_t * p_addr;

    id     = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    p_addr = &GICD0->GICD_ICFGR[id / BSP_PRV_GIC_REG_STRIDE16];

    shift = (id % BSP_PRV_GIC_REG_STRIDE16) * BSP_PRV_GIC_REG_BITS2; /* 2bits per unit */
    mask  = (uint32_t) (BSP_PRV_GIC_REG_BITS3 << shift);             /* 2bits per unit */
    r_bsp_gic_io_regwrite_32(p_addr, (uint32_t) sense, shift, mask);
}

/*******************************************************************************************************************//**
 * Get interrupt trigger information.
 *
 * @param[in]    irq       Interrupt number ID.
 *
 * @retval   Value that means interrupt trigger sense, which is edge-triggered or level-sensitive.
 **********************************************************************************************************************/
uint32_t R_BSP_GICD_GetSpiSense (IRQn_Type irq)
{
    uint32_t            id;
    uint32_t            shift;
    uint32_t            mask;
    uint32_t            sense;
    volatile uint32_t * p_addr;

    id     = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    p_addr = &GICD0->GICD_ICFGR[id / BSP_PRV_GIC_REG_STRIDE16];

    shift = (id % BSP_PRV_GIC_REG_STRIDE16) * BSP_PRV_GIC_REG_BITS2; /* 2bits per unit */
    mask  = (uint32_t) (BSP_PRV_GIC_REG_BITS3 << shift);             /* 2bits per unit */
    sense = r_bsp_gic_io_regread_32(p_addr, shift, mask);

    return sense;
}

/*******************************************************************************************************************//**
 * Sets the specified interrupt to the pending state by write to GICD_ISPENDRn.
 *
 * @param[in]    irq       Interrupt number ID.
 **********************************************************************************************************************/
void R_BSP_GICD_SetSpiPending (IRQn_Type irq)
{
    uint32_t            id;
    uint32_t            shift;
    uint32_t            mask;
    volatile uint32_t * p_addr;

    /* GICD_ISPENDRn has 32 sources in the 32 bits           */
    /* The n can be calculated by int_id / 32                */
    /* The bit field width is 1 bit                          */
    /* The target bit can be calculated by (int_id % 32) * 1 */
    id     = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    p_addr = &GICD0->GICD_ISPENDR[id / BSP_PRV_GIC_REG_STRIDE32];

    shift = id % BSP_PRV_GIC_REG_STRIDE32;
    mask  = (uint32_t) (BSP_PRV_GIC_REG_BITS1 << shift); /* Create mask data */

    *p_addr = mask;                                      /* Write GICD_ISPENDRn */
}

/*******************************************************************************************************************//**
 * Sets the specified interrupt to the pending state by write to GICD_ISPENDRn.
 *
 * @param[in]    irq       Interrupt number ID.
 *
 * @retval   Information of SPI pending.
 **********************************************************************************************************************/
uint32_t R_BSP_GICD_GetSpiPending (IRQn_Type irq)
{
    uint32_t            id;
    uint32_t            shift;
    uint32_t            mask;
    uint32_t            pending;
    volatile uint32_t * p_addr;

    id     = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    p_addr = &GICD0->GICD_ISPENDR[id / BSP_PRV_GIC_REG_STRIDE32];

    shift   = id % BSP_PRV_GIC_REG_STRIDE32;
    mask    = (uint32_t) (BSP_PRV_GIC_REG_BITS1 << shift); /* Create mask data */
    pending = r_bsp_gic_io_regread_32(p_addr, shift, mask);

    return pending;
}

/*******************************************************************************************************************//**
 * Clear the specified interrupt to the pending state by write to GICD_ICPENDRn.
 *
 * @param[in]    irq       Interrupt number ID.
 **********************************************************************************************************************/
void R_BSP_GICD_SetSpiClearPending (IRQn_Type irq)
{
    uint32_t            id;
    uint32_t            shift;
    uint32_t            mask;
    volatile uint32_t * p_addr;

    /* GICD_ICPENDRn has 32 sources in the 32 bits           */
    /* The n can be calculated by int_id / 32                */
    /* The bit field width is 1 bit                          */
    /* The target bit can be calculated by (int_id % 32) * 1 */
    id     = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    p_addr = &GICD0->GICD_ICPENDR[id / BSP_PRV_GIC_REG_STRIDE32];

    shift = id % BSP_PRV_GIC_REG_STRIDE32;
    mask  = (uint32_t) (BSP_PRV_GIC_REG_BITS1 << shift); /* Create mask data */

    *p_addr = mask;                                      /* Write GICD_ICPENDRn */
}

/*******************************************************************************************************************//**
 * Gets information about whether the specified interrupt is pending state by reading the value of GICD_ICPENDRn.
 *
 * @param[in]    irq       Interrupt number ID.
 *
 * @retval   Information of SPI pending.
 **********************************************************************************************************************/
uint32_t R_BSP_GICD_GetSpiClearPending (IRQn_Type irq)
{
    uint32_t            id;
    uint32_t            shift;
    uint32_t            mask;
    uint32_t            pending;
    volatile uint32_t * p_addr;

    id     = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    p_addr = &GICD0->GICD_ICPENDR[id / BSP_PRV_GIC_REG_STRIDE32];

    shift   = (id % BSP_PRV_GIC_REG_STRIDE32);             /* 1bits per unit */
    mask    = (uint32_t) (BSP_PRV_GIC_REG_BITS1 << shift); /* 1bits per unit */
    pending = r_bsp_gic_io_regread_32(p_addr, shift, mask);

    return pending;
}

/*******************************************************************************************************************//**
 * Set SPI security group. The combination of the modifier bit of GICD_IGRPMODR and the status bit of GICD_IGROUPR
 * determines whether the security group is Secure Group 0, Non-Secure Group 1, or Secure Group 1.
 *
 * @param[in]    irq       Interrupt number ID.
 * @param[in]    group     Security group.
 **********************************************************************************************************************/
void R_BSP_GICD_SetSpiSecurity (IRQn_Type irq, bsp_gic_igroupr_secure_t group)
{
    uint32_t            id;
    uint32_t            group_modfier;
    uint32_t            group_status;
    uint32_t            shift;
    uint32_t            mask;
    volatile uint32_t * p_addr;

    /* get group_modifier bit for GICD_IGRPMODRn */
    group_modfier = (group >> BSP_PRV_GIC_SHIFT_1) & BSP_PRV_GIC_REG_MASK_1BIT;

    /* get group_status bit for GICD_IGROUPR */
    group_status = group & BSP_PRV_GIC_REG_MASK_1BIT;

    id    = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    shift = (id % BSP_PRV_GIC_REG_STRIDE32);
    mask  = (uint32_t) (BSP_PRV_GIC_REG_BITS1 << shift);

    /* GICD_IGROUPRn, GICD_IGRPMODRn has 32 sources in the 32 bits  */
    /* The n can be calculated by int_id / 32                       */
    /* The bit field width is 1 bit                                 */
    /* The target bit can be calculated by (int_id % 32) * 1        */
    p_addr = &GICD0->GICD_IGROUPR[id / BSP_PRV_GIC_REG_STRIDE32];

    r_bsp_gic_io_regwrite_32(p_addr, group_status, shift, mask);

    p_addr = &GICD0->GICD_IGRPMODR[id / BSP_PRV_GIC_REG_STRIDE32];

    r_bsp_gic_io_regwrite_32(p_addr, group_modfier, shift, mask);
}

/*******************************************************************************************************************//**
 * Sets SPI security group with each 32 interrupts (each line). The combination of the modifier bit of GICD_IGRPMODR
 * and the status bit of GICD_IGROUPR determines whether the security group is Secure Group 0, Non-Secure Group 1, or
 * Secure Group 1.
 *
 * @param[in]    line     Line of GICD_IGRPMODRn register. Line is the quotient of the interrupt ID divided by 32.
 *                        For example, an interrupt with IDs 32 to 63 corresponds to line 1.
 * @param[in]    group    Security group.
 **********************************************************************************************************************/
void R_BSP_GICD_SetSpiSecurityLine (uint32_t line, bsp_gic_igroupr_secure_t group)
{
    uint32_t            group_modfier;
    uint32_t            group_status;
    volatile uint32_t * p_addr;

    /* get group_modifier bit for GICD_IGRPMODRn */
    group_modfier = ((group >> BSP_PRV_GIC_SHIFT_1) & BSP_PRV_GIC_REG_MASK_1BIT);

    /* GICD_IGRPMODRn is a 32-bit register with 32 group_modifer bits. */
    /* If group_modifer = 1 is set, set 0xFFFFFFFF in the register. */
    group_modfier = (~group_modfier + BSP_PRV_GIC_ADD_1);

    /* get group_status bit for GICD_IGROUPR*/
    group_status = (group & BSP_PRV_GIC_REG_MASK_1BIT);

    /* GICD_IGRPMODRn is a 32-bit register with 32 group_modifer bits. */
    /* If group_modifer = 1 is set, set 0xFFFFFFFF in the register. */
    group_status = (~group_status + BSP_PRV_GIC_ADD_1);

    /* GICD_IGROUPRn, GICD_IGRPMODRn has 32 sources in the 32 bits  */
    /* The n can be calculated by int_id / 32                       */
    /* The bit field width is 1 bit                                 */
    /* The target bit can be calculated by (int_id % 32) * 1        */
    p_addr = &GICD0->GICD_IGROUPR[line];
    r_bsp_gic_io_regwrite_32(p_addr, group_status, BSP_GIC_NONSHIFT_ACCESS, BSP_GIC_NONMASK_ACCESS);

    p_addr = &GICD0->GICD_IGRPMODR[line];
    r_bsp_gic_io_regwrite_32(p_addr, group_modfier, BSP_GIC_NONSHIFT_ACCESS, BSP_GIC_NONMASK_ACCESS);
}

/*******************************************************************************************************************//**
 * Set SPI security group for all GICD_IGRPMODRn register. The combination of the modifier bit of GICD_IGRPMODR and
 * the status bit of GICD_IGROUPR determines whether the security group is Secure Group 0, Non-Secure Group 1, or
 * Secure Group 1.
 *
 * @param[in]    group    Security group.
 **********************************************************************************************************************/
void R_BSP_GICD_SetSpiSecurityAll (bsp_gic_igroupr_secure_t group)
{
    uint32_t line;
    uint32_t cnt;
    volatile const uint32_t * p_addr;

    p_addr = &GICD0->GICD_TYPER;
    line   = r_bsp_gic_io_regread_32(p_addr, BSP_GIC_NONSHIFT_ACCESS, 0x1F);

    for (cnt = 0; cnt <= line; cnt++)
    {
        R_BSP_GICD_SetSpiSecurityLine(cnt, group);
    }
}

/*******************************************************************************************************************//**
 * Sets whether the Class0 or Class1 class is the target of the SPI.
 *
 * @param[in]    irq             Interrupt number ID.
 * @param[in]    class_group    Interrupt class.
 *
 * @note R_BSP_GICR_SetClass can be set whether each interrupt is Class0 or Class1.
 **********************************************************************************************************************/
void R_BSP_GICD_SetSpiClass (IRQn_Type irq, bsp_gicd_iclar_class_t class_group)
{
    uint32_t            id;
    uint32_t            shift;
    uint32_t            mask;
    uint32_t            class_set;
    volatile uint32_t * p_addr;

    /* ICLAR control only SPI */
    if (irq >= 0)
    {
        class_set = BSP_PRV_GIC_REG_BITS1 << (~class_group & BSP_PRV_GIC_REG_MASK_1BIT);

        /* ICLAR start from ICLAR2 */
        id     = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
        p_addr = &GICD0->GICD_ICLAR[id / BSP_PRV_GIC_REG_STRIDE16];

        shift = (id % BSP_PRV_GIC_REG_STRIDE16) * BSP_PRV_GIC_REG_BITS2; /* 2bits per unit */
        mask  = (uint32_t) (BSP_PRV_GIC_REG_BITS3 << shift);             /* 2bits per unit */
        r_bsp_gic_io_regwrite_32(p_addr, class_set, shift, mask);
    }
}

/*******************************************************************************************************************//**
 * Enables Redistributor and configue power management by access GICR_PWRR and GICR_WAKER.
 * This BSP sets GICR_WAKER.ProcessorSleep to 0, so wake_request signal wake-up the core when the core is powered off
 * is disabled.
 **********************************************************************************************************************/
void R_BSP_GICR_Enable (void)
{
    volatile uint32_t        * p_addr;
    GICR_CONTROL_TARGET_Type * GICR_TARGET_IFREG;

    GICR_TARGET_IFREG = BSP_PRV_GICR_TARGET_IFREG_ADDRESS;

    /* Power up Redistributor */
    p_addr = &GICR_TARGET_IFREG->GICR_PWRR;
    r_bsp_gic_io_regwrite_32(p_addr, BSP_GICR_WAKER_PROCESSOR_SLEEP, BSP_GIC_NONSHIFT_ACCESS, BSP_GIC_NONMASK_ACCESS);

    /* GICR_WAKER.ProcessorSleep off */
    p_addr = &GICR_TARGET_IFREG->GICR_WAKER;
    r_bsp_gic_io_regwrite_32(p_addr,
                             0,
                             BSP_PRV_GIC_GICR_WAKER_ProcessorSleep_Pos,
                             BSP_PRV_GIC_GICR_WAKER_ProcessorSleep_Msk);

    /* wait for ChildrenAsleep bit to be cleared */
    FSP_HARDWARE_REGISTER_WAIT(r_bsp_gic_io_regread_32(p_addr, BSP_PRV_GIC_GICR_WAKER_ChildrenAsleep_Pos,
                                                       BSP_PRV_GIC_GICR_WAKER_ChildrenAsleep_Msk),
                               0);
}

/*******************************************************************************************************************//**
 * Enable SGI or PPI forwarding to the CPU interface by set the bit of GICR_ISENABLER0 to 1 corresponding to the ID
 * specified in the argument.
 *
 * @param[in]    irq      Interrupt number ID.
 **********************************************************************************************************************/
void R_BSP_GICR_SgiPpiEnable (IRQn_Type irq)
{
    uint32_t            id;
    uint32_t            shift;
    uint32_t            mask;
    volatile uint32_t * p_addr;
    GICR_SGI_PPI_Type * GICR_TARGET_INTREG;

    id  = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    id &= BSP_PRV_GIC_REG_MASK_SGI_PPI;

    GICR_TARGET_INTREG = BSP_PRV_GICR_TARGET_INTREG_ADDRESS;

    /* Enable SGI0 - SGI15, PPI0 - PPI15 */
    p_addr = &GICR_TARGET_INTREG->GICR_ISENABLER0;

    shift = id;
    mask  = (uint32_t) (BSP_PRV_GIC_REG_BITS1 << shift);

    *p_addr = mask;
}

/*******************************************************************************************************************//**
 * Disable SGI of PPI forwarding to the CPU interface by set the bit of GICR_ICENABLER0 to 1 corresponding to the ID
 * specified in the argument.
 *
 * @param[in]    irq      Interrupt number ID.
 **********************************************************************************************************************/
void R_BSP_GICR_SgiPpiDisable (IRQn_Type irq)
{
    uint32_t            id;
    uint32_t            shift;
    uint32_t            mask;
    volatile uint32_t * p_addr;
    GICR_SGI_PPI_Type * GICR_TARGET_INTREG;

    id  = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    id &= BSP_PRV_GIC_REG_MASK_SGI_PPI;

    GICR_TARGET_INTREG = BSP_PRV_GICR_TARGET_INTREG_ADDRESS;

    /* Disable SGI0 - SGI15, PPI0 - PPI15 */
    p_addr = &GICR_TARGET_INTREG->GICR_ICENABLER0;

    shift = id;
    mask  = (uint32_t) (BSP_PRV_GIC_REG_BITS1 << shift);

    *p_addr = mask;
}

/*******************************************************************************************************************//**
 * Sets the value specified for GICR_IPRIORITYRn to set the interrupt priority for the specified ID.
 *
 * @param[in]    irq       Interrupt number ID.
 * @param[in]    priority Interrupt Priority.
 **********************************************************************************************************************/
void R_BSP_GICR_SetSgiPpiPriority (IRQn_Type irq, uint32_t priority)
{
    uint32_t            id;
    uint32_t            shift;
    uint32_t            mask;
    volatile uint32_t * p_addr;
    GICR_SGI_PPI_Type * GICR_TARGET_INTREG;

    id  = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    id &= BSP_PRV_GIC_REG_MASK_SGI_PPI;

    GICR_TARGET_INTREG = BSP_PRV_GICR_TARGET_INTREG_ADDRESS;

    /* GICR_IPRIORITYRn has 4 sources in the 32 bits        */
    /* The n can be calculated by int_id / 4                */
    /* The bit field width is 8 bits                        */
    /* The target bit can be calculated by (int_id % 4) * 8 */
    p_addr = &GICR_TARGET_INTREG->GICR_IPRIORITYR[id / BSP_PRV_GIC_REG_STRIDE04];

    shift = (id % BSP_PRV_GIC_REG_STRIDE04) * BSP_PRV_GIC_REG_BITS8; /* 8bits per unit */
    mask  = (uint32_t) (BSP_PRV_GIC_REG_MASK_8BIT << shift);         /* 8bits per unit */
    r_bsp_gic_io_regwrite_32(p_addr, priority, shift, mask);
}

/*******************************************************************************************************************//**
 * Gets the interrupt priority for the specified ID by reads the value of GICR_IPRIORITYRn.
 *
 * @param[in]    irq       Interrupt number ID.
 *
 * @retval   interrupt priority.
 **********************************************************************************************************************/
uint32_t R_BSP_GICR_GetSgiPpiPriority (IRQn_Type irq)
{
    uint32_t            id;
    uint32_t            priority;
    uint32_t            shift;
    uint32_t            mask;
    volatile uint32_t * p_addr;
    GICR_SGI_PPI_Type * GICR_TARGET_INTREG;

    id  = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    id &= BSP_PRV_GIC_REG_MASK_SGI_PPI;

    GICR_TARGET_INTREG = BSP_PRV_GICR_TARGET_INTREG_ADDRESS;

    /* GICR_IPRIORITYRn has 4 sources in the 32 bits        */
    /* The n can be calculated by int_id / 4                */
    /* The bit field width is 8 bits                        */
    /* The target bit can be calculated by (int_id % 4) * 8 */
    p_addr = &GICR_TARGET_INTREG->GICR_IPRIORITYR[id / BSP_PRV_GIC_REG_STRIDE04];

    shift    = (id % BSP_PRV_GIC_REG_STRIDE04) * BSP_PRV_GIC_REG_BITS8; /* 8bits per unit */
    mask     = (uint32_t) (BSP_PRV_GIC_REG_MASK_8BIT << shift);         /* 8bits per unit */
    priority = r_bsp_gic_io_regread_32(p_addr, shift, mask);

    return priority;
}

/*******************************************************************************************************************//**
 * Set interrupt as edge-triggered or level-sensitive.
 *
 * @param[in]    irq       Interrupt number ID.
 * @param[in]    sense    Interrupt trigger sense.
 **********************************************************************************************************************/
void R_BSP_GICR_SetSgiPpiSense (IRQn_Type irq, bsp_gicd_icfgr_sense_t sense)
{
    uint32_t            id;
    uint32_t            shift;
    uint32_t            mask;
    volatile uint32_t * p_addr;
    GICR_SGI_PPI_Type * GICR_TARGET_INTREG;

    id  = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    id &= BSP_PRV_GIC_REG_MASK_SGI_PPI;

    GICR_TARGET_INTREG = BSP_PRV_GICR_TARGET_INTREG_ADDRESS;
    p_addr             = &GICR_TARGET_INTREG->GICR_ICFGR[id / BSP_PRV_GIC_REG_STRIDE16];

    shift = (id % BSP_PRV_GIC_REG_STRIDE16) * BSP_PRV_GIC_REG_BITS2; /* 2bits per unit */
    mask  = (uint32_t) (BSP_PRV_GIC_REG_BITS3 << shift);             /* 2bits per unit */
    r_bsp_gic_io_regwrite_32(p_addr, (uint32_t) sense, shift, mask);
}

/*******************************************************************************************************************//**
 * Get interrupt trigger information.
 *
 * @param[in]    irq       Interrupt number ID.
 *
 * @retval   Value that means interrupt trigger sense, which is edge-triggered or level-sensitive.
 **********************************************************************************************************************/
uint32_t R_BSP_GICR_GetSgiPpiSense (IRQn_Type irq)
{
    uint32_t            id;
    uint32_t            shift;
    uint32_t            mask;
    uint32_t            sense;
    volatile uint32_t * p_addr;
    GICR_SGI_PPI_Type * GICR_TARGET_INTREG;

    id  = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    id &= BSP_PRV_GIC_REG_MASK_SGI_PPI;

    GICR_TARGET_INTREG = BSP_PRV_GICR_TARGET_INTREG_ADDRESS;
    p_addr             = &GICR_TARGET_INTREG->GICR_ICFGR[id / BSP_PRV_GIC_REG_STRIDE16];

    shift = (id % BSP_PRV_GIC_REG_STRIDE16) * BSP_PRV_GIC_REG_BITS2; /* 2bits per unit */
    mask  = (uint32_t) (BSP_PRV_GIC_REG_BITS3 << shift);             /* 2bits per unit */
    sense = r_bsp_gic_io_regread_32(p_addr, shift, mask);

    return sense;
}

/*******************************************************************************************************************//**
 * Sets the specified interrupt to the pending state by write to GICR_ISPENDR0.
 *
 * @param[in]    irq       Interrupt number ID.
 **********************************************************************************************************************/
void R_BSP_GICR_SetSgiPpiPending (IRQn_Type irq)
{
    uint32_t            id;
    uint32_t            shift;
    uint32_t            mask;
    volatile uint32_t * p_addr;
    GICR_SGI_PPI_Type * GICR_TARGET_INTREG;

    id  = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    id &= BSP_PRV_GIC_REG_MASK_SGI_PPI;

    GICR_TARGET_INTREG = BSP_PRV_GICR_TARGET_INTREG_ADDRESS;

    /* GICR_ISPENDn has 32 sources in the 32 bits            */
    /* The n can be calculated by int_id / 32                */
    /* The bit field width is 1 bit                          */
    /* The target bit can be calculated by (int_id % 32) * 1 */
    p_addr = &GICR_TARGET_INTREG->GICR_ISPENDR0;

    shift = id % BSP_PRV_GIC_REG_STRIDE32;
    mask  = (uint32_t) (BSP_PRV_GIC_REG_BITS1 << shift); /* Create mask data */

    *p_addr = mask;                                      /* Write GICR_ISPENDR0 */
}

/*******************************************************************************************************************//**
 * Gets information about whether the specified interrupt is pending state by reading the value of GICR_ISPENDR0.
 *
 * @param[in]    irq       Interrupt number ID.
 *
 * @retval   Information of SGI or PPI pending.
 **********************************************************************************************************************/
uint32_t R_BSP_GICR_GetSgiPpiPending (IRQn_Type irq)
{
    uint32_t            id;
    uint32_t            shift;
    uint32_t            mask;
    uint32_t            pending;
    volatile uint32_t * p_addr;
    GICR_SGI_PPI_Type * GICR_TARGET_INTREG;

    id  = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    id &= BSP_PRV_GIC_REG_MASK_SGI_PPI;

    GICR_TARGET_INTREG = BSP_PRV_GICR_TARGET_INTREG_ADDRESS;
    p_addr             = &GICR_TARGET_INTREG->GICR_ISPENDR0;

    shift   = (id % BSP_PRV_GIC_REG_STRIDE32);             /* 1bits per unit */
    mask    = (uint32_t) (BSP_PRV_GIC_REG_BITS1 << shift); /* 1bits per unit */
    pending = r_bsp_gic_io_regread_32(p_addr, shift, mask);

    return pending;
}

/*******************************************************************************************************************//**
 * Clear the specified interrupt to the pending state by write to GICR_ICPENDR0.
 *
 * @param[in]    irq       Interrupt number ID.
 **********************************************************************************************************************/
void R_BSP_GICR_SetSgiPpiClearPending (IRQn_Type irq)
{
    uint32_t            id;
    uint32_t            shift;
    uint32_t            mask;
    volatile uint32_t * p_addr;
    GICR_SGI_PPI_Type * GICR_TARGET_INTREG;

    id  = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    id &= BSP_PRV_GIC_REG_MASK_SGI_PPI;

    GICR_TARGET_INTREG = BSP_PRV_GICR_TARGET_INTREG_ADDRESS;

    /* GICR_ICPENDRn has 32 sources in the 32 bits           */
    /* The n can be calculated by int_id / 32                */
    /* The bit field width is 1 bit                          */
    /* The target bit can be calculated by (int_id % 32) * 1 */
    p_addr = &GICR_TARGET_INTREG->GICR_ICPENDR0;

    shift = id % BSP_PRV_GIC_REG_STRIDE32;
    mask  = (uint32_t) (BSP_PRV_GIC_REG_BITS1 << shift); /* Create mask data */

    *p_addr = mask;                                      /* Write GICR_ICPENDR0 */
}

/*******************************************************************************************************************//**
 * Gets information about whether the specified interrupt is pending state by reading the value of GICR_ICPENDR0.
 *
 * @param[in]    irq       Interrupt number ID.
 *
 * @retval   Information of SGI or PPI pending.
 **********************************************************************************************************************/
uint32_t R_BSP_GICR_GetSgiPpiClearPending (IRQn_Type irq)
{
    uint32_t            id;
    uint32_t            shift;
    uint32_t            mask;
    uint32_t            pending;
    volatile uint32_t * p_addr;
    GICR_SGI_PPI_Type * GICR_TARGET_INTREG;

    id  = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    id &= BSP_PRV_GIC_REG_MASK_SGI_PPI;

    GICR_TARGET_INTREG = BSP_PRV_GICR_TARGET_INTREG_ADDRESS;

    p_addr = &GICR_TARGET_INTREG->GICR_ICPENDR0;

    shift   = (id % BSP_PRV_GIC_REG_STRIDE32);             /* 1bits per unit */
    mask    = (uint32_t) (BSP_PRV_GIC_REG_BITS1 << shift); /* 1bits per unit */
    pending = r_bsp_gic_io_regread_32(p_addr, shift, mask);

    return pending;
}

/*******************************************************************************************************************//**
 * Set SGI and PPI security group. The combination of the modifier bit of GICR_IGRPMODR0 and the status bit of
 * GICR_IGROUPR determines whether the security group is Secure Group 0, Non-Secure Group 1, or Secure Group 1.
 *
 * @param[in]    irq       Interrupt number ID.
 * @param[in]    group    Security group.
 **********************************************************************************************************************/
void R_BSP_GICR_SetSgiPpiSecurity (IRQn_Type irq, bsp_gic_igroupr_secure_t group)
{
    uint32_t            id;
    uint32_t            group_modfier;
    uint32_t            group_status;
    uint32_t            shift;
    uint32_t            mask;
    volatile uint32_t * p_addr;
    GICR_SGI_PPI_Type * GICR_TARGET_INTREG;

    /* get group_modifier bit for GICR_IGRPMODR0 */
    group_modfier = (group >> BSP_PRV_GIC_SHIFT_1) & BSP_PRV_GIC_REG_MASK_1BIT;

    /* get group_status bit for GICR_IGROUPR0 */
    group_status = group & BSP_PRV_GIC_REG_MASK_1BIT;

    id  = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    id &= BSP_PRV_GIC_REG_MASK_SGI_PPI;

    shift = (id % BSP_PRV_GIC_REG_STRIDE32);
    mask  = (uint32_t) (BSP_PRV_GIC_REG_BITS1 << shift);

    GICR_TARGET_INTREG = BSP_PRV_GICR_TARGET_INTREG_ADDRESS;

    /* GICR_IGROUPR0, GICR_IGRPMODR0 has 32 sources in the 32 bits  */
    /* The n can be calculated by int_id / 32                       */
    /* The bit field width is 1 bit                                 */
    /* The target bit can be calculated by (int_id % 32) * 1        */
    p_addr = &GICR_TARGET_INTREG->GICR_IGROUPR0;
    r_bsp_gic_io_regwrite_32(p_addr, group_status, shift, mask);

    p_addr = &GICR_TARGET_INTREG->GICR_IGRPMODR0;
    r_bsp_gic_io_regwrite_32(p_addr, group_modfier, shift, mask);
}

/*******************************************************************************************************************//**
 * Sets security group for all SGI and PPI. The combination of the modifier bit of GICR_IGRPMODR0 and the status bit of
 * GICR_IGROUPR0 determines whether the security group is Secure Group 0, Non-Secure Group 1, or Secure Group 1.
 *
 * @param[in]    group    Security group.
 **********************************************************************************************************************/
void R_BSP_GICR_SetSgiPpiSecurityLine (bsp_gic_igroupr_secure_t group)
{
    uint32_t            group_modfier;
    uint32_t            group_status;
    volatile uint32_t * p_addr;
    GICR_SGI_PPI_Type * GICR_TARGET_INTREG;

    /* get group_modifier bit for GICR_IGRPMODR0 */
    group_modfier = ((group >> BSP_PRV_GIC_SHIFT_1) & BSP_PRV_GIC_REG_MASK_1BIT);

    /* GICR_IGRPMODR0 is a 32-bit register with 32 group_modifer bits. */
    /* If group_modifer = 1 is set, set 0xFFFFFFFF in the register. */
    group_modfier = (~group_modfier + BSP_PRV_GIC_ADD_1);

    /* get group_status bit for GICR_IGROUPR0 */
    group_status = (group & BSP_PRV_GIC_REG_MASK_1BIT);

    /* GICR_IGRPMODR0 is a 32-bit register with 32 group_modifer bits. */
    /* If group_modifer = 1 is set, set 0xFFFFFFFF in the register. */
    group_status = (~group_status + BSP_PRV_GIC_ADD_1);

    GICR_TARGET_INTREG = BSP_PRV_GICR_TARGET_INTREG_ADDRESS;

    /* GICR_IGROUPR0, GICR_IGRPMODR0 has 32 sources in the 32 bits  */
    /* The n can be calculated by int_id / 32                       */
    /* The bit field width is 1 bit                                 */
    /* The target bit can be calculated by (int_id % 32) * 1        */
    p_addr = &GICR_TARGET_INTREG->GICR_IGROUPR0;
    r_bsp_gic_io_regwrite_32(p_addr, group_status, BSP_GIC_NONSHIFT_ACCESS, BSP_GIC_NONMASK_ACCESS);

    p_addr = &GICR_TARGET_INTREG->GICR_IGRPMODR0;
    r_bsp_gic_io_regwrite_32(p_addr, group_modfier, BSP_GIC_NONSHIFT_ACCESS, BSP_GIC_NONMASK_ACCESS);
}

/*******************************************************************************************************************//**
 * Sets the interrupt class to either Class0 or Class1.
 *
 * @param[in]    class_group    Interrupt class group.
 **********************************************************************************************************************/
void R_BSP_GICR_SetClass (bsp_gicd_iclar_class_t class_group)
{
    volatile uint32_t        * p_addr;
    GICR_CONTROL_TARGET_Type * GICR_TARGET_IFREG;

    GICR_TARGET_IFREG = BSP_PRV_GICR_TARGET_IFREG_ADDRESS;

    p_addr = &GICR_TARGET_IFREG->GICR_CLASS;
    r_bsp_gic_io_regwrite_32(p_addr, class_group, BSP_GIC_NONSHIFT_ACCESS, BSP_GIC_NONMASK_ACCESS);
}

/*******************************************************************************************************************//**
 * Get routing information (Affinity level value) by reading bit[63:32] of GICR_TYPER.
 *
 * @retval   value  interrupt routing information. Aff3 is stored from bit 31 to bit 24, Aff2 from bit 23 to bit 16,
 *                  Aff1 from bit15 to 8, and Aff0 from bit 7 to 0.
 **********************************************************************************************************************/
uint32_t R_BSP_GICR_GetRoute (void)
{
    uint32_t                   value;
    volatile uint32_t        * p_addr;
    GICR_CONTROL_TARGET_Type * GICR_TARGET_IFREG;

    GICR_TARGET_IFREG = BSP_PRV_GICR_TARGET_IFREG_ADDRESS;

    p_addr = (uint32_t *) (&GICR_TARGET_IFREG->GICR_TYPER);
    value  = *(p_addr + BSP_PRV_GIC_ADD_1);

    return value;
}

/*******************************************************************************************************************//**
 * Set interrupt mask level to Interrupt Priority Mask Register.
 *
 * @param[in]    mask_level  Mask level.
 **********************************************************************************************************************/
void R_BSP_GICC_SetMaskLevel (uint64_t mask_level)
{
    __set_CP(3, 0, mask_level, 4, 6, 0);
}

/*******************************************************************************************************************//**
 * Get interrupt mask level information from Interrupt Priority Mask Register.
 *
 * @retval   Information of mask level.
 **********************************************************************************************************************/
uint64_t R_BSP_GICC_GetMaskLevel (void)
{
    uint64_t mask_level = 0;

    /* Read system registers is using the MRS instruction. */
    __get_CP(3, 0, mask_level, 4, 6, 0);

    return mask_level;
}

/*******************************************************************************************************************//**
 * Set end of interrupt to End Of Interrupt Register 0 for Group 0.
 *
 * @param[in]    irq       Interrupt number ID.
 **********************************************************************************************************************/
void R_BSP_GICC_SetEoiGrp0 (IRQn_Type irq)
{
    uint32_t          id;
    volatile uint64_t set_id;

    id     = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    set_id = (uint64_t) (id & BSP_PRV_GIC_REG_MASK_24BIT); /* 23bit INTID filed */

    /* Write to system registers is using the MSR instruction. */
    __set_CP(3, 0, set_id, 12, 8, 1);
}

/*******************************************************************************************************************//**
 * Set end of interrupt to End Of Interrupt Register 1 for Group 1.
 *
 * @param[in]    irq       Interrupt number ID.
 **********************************************************************************************************************/
void R_BSP_GICC_SetEoiGrp1 (IRQn_Type irq)
{
    uint32_t          id;
    volatile uint64_t set_id;

    id     = (uint32_t) (irq + BSP_VECTOR_NUM_OFFSET);
    set_id = (uint64_t) (id & BSP_PRV_GIC_REG_MASK_24BIT); /* 23bit INTID filed */

    /* Write to system registers is using the MSR instruction. */
    __set_CP(3, 0, set_id, 12, 12, 1);
}

/*******************************************************************************************************************//**
 * Get interrupt ID being asserted from Group 0 by reading Interrupt Acknowledge Register 0.
 *
 * @retval   Interrupt ID number.
 **********************************************************************************************************************/
uint32_t R_BSP_GICC_Get_IntIdGrp0 (void)
{
    uint64_t get_id = 0;

    /* Read system registers is using the MRS instruction. */
    __get_CP(3, 0, get_id, 12, 8, 0);

    get_id &= BSP_PRV_GIC_REG_MASK_24BIT; /* 23bit INTID filed */

    return (uint32_t) get_id;
}

/*******************************************************************************************************************//**
 * Get interrupt ID being asserted from Group 1 by reading Interrupt Acknowledge Register 1.
 *
 * @retval   Interrupt ID number.
 **********************************************************************************************************************/
uint32_t R_BSP_GICC_Get_IntIdGrp1 (void)
{
    uint64_t get_id = 0;

    /* Read system registers is using the MRS instruction. */
    __get_CP(3, 0, get_id, 12, 12, 0);

    get_id &= BSP_PRV_GIC_REG_MASK_24BIT; /* 23bit INTID filed */

    return (uint32_t) get_id;
}

/**********************************************************************************************************************
 * IO register 32-bit write
 *
 * @param[in]   * ioreg            IO register for writing
 * @param[in]   write_value        Write value for the IO register
 * @param[in]   shift              The number of left shifts to the target bit
 * @param[in]   mask               Mask value for the IO register (Target bit : "1")
 *********************************************************************************************************************/
static void r_bsp_gic_io_regwrite_32 (volatile uint32_t * ioreg, uint32_t write_value, uint32_t shift, uint64_t mask)
{
    uint32_t reg_value;

    if (BSP_GIC_NONMASK_ACCESS != mask)
    {
        /* Read from register */
        reg_value = *ioreg;

        /* Modify value */
        reg_value = (uint32_t) ((reg_value & (~mask)) | (write_value << shift));
    }
    else
    {
        reg_value = write_value;
    }

    /* Write to register */
    *ioreg = reg_value;
}

/**********************************************************************************************************************
 * IO register 32-bit read
 *
 * @param[in]   * ioreg            IO register for reading
 * @param[in]   shift              The number of left shifts to the target bit
 * @param[in]   mask               Mask value for the IO register (Target bit : "1")
 *
 * @retval      Register value
 *********************************************************************************************************************/
static uint32_t r_bsp_gic_io_regread_32 (volatile const uint32_t * ioreg, uint32_t shift, uint64_t mask)
{
    uint32_t reg_value;

    /* Read from register */
    reg_value = *ioreg;

    if (BSP_GIC_NONMASK_ACCESS != mask)
    {
        /* Clear other bit and Bit shift */
        reg_value = (uint32_t) ((reg_value & mask) >> shift);
    }

    return reg_value;
}

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

/*******************************************************************************************************************//**
 * Register a callback function for supported interrupts. If NULL is passed for the callback argument then any
 * previously registered callbacks are unregistered.
 *
 * @param[in]  irq          Interrupt for which  to register a callback.
 * @param[in]  p_callback   Pointer to function to call when interrupt occurs.
 *
 * @retval     FSP_ERR_UNSUPPORTED          NMI Group IRQ are not supported in RZ/A3UL.
 **********************************************************************************************************************/
fsp_err_t R_BSP_GroupIrqWrite (bsp_grp_irq_t irq, void (* p_callback)(bsp_grp_irq_t irq))
{
    (void) irq;
    (void) p_callback;
#if BSP_CFG_PARAM_CHECKING_ENABLE

    /* Check pointer for NULL value. */
    FSP_ASSERT(p_callback);
#endif

    return FSP_ERR_UNSUPPORTED;
}

/** @} (end addtogroup BSP_MCU) */
#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif
