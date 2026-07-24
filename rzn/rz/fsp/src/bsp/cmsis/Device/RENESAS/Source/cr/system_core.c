/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include <string.h>
#include "bsp_api.h"

#include "../../../../../mcu/all/bsp_clocks.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_CPCAR_CP_ENABLE          (0x00F00000)
#define BSP_FPEXC_EN_ENABLE          (0x40000000)
#define BSP_TCM_ALL_ACCESS_ENABLE    (0x00000003)

#define BSP_PRIORITY_MASK            BSP_FEATURE_BSP_IRQ_PRIORITY_MASK /* Priority mask value for GIC */
#define BSP_ENABLE_GROUP_INT         (0x00000001)                      /* Enable Group1 interrupt value */
#define BSP_ICC_CTLR                 (0x00000001)                      /* ICC_BPR0 is used for Group1 interrupt */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/* This vector table is for SGI and PPI interrupts. */
BSP_DONT_REMOVE fsp_vector_t g_sgi_ppi_vector_table[BSP_CORTEX_VECTOR_TABLE_ENTRIES] =
{
    NULL,                              /* INTID0    : SOFTWARE_GENERATE_INT0                   */
    NULL,                              /* INTID1    : SOFTWARE_GENERATE_INT1                   */
    NULL,                              /* INTID2    : SOFTWARE_GENERATE_INT2                   */
    NULL,                              /* INTID3    : SOFTWARE_GENERATE_INT3                   */
    NULL,                              /* INTID4    : SOFTWARE_GENERATE_INT4                   */
    NULL,                              /* INTID5    : SOFTWARE_GENERATE_INT5                   */
    NULL,                              /* INTID6    : SOFTWARE_GENERATE_INT6                   */
    NULL,                              /* INTID7    : SOFTWARE_GENERATE_INT7                   */
    NULL,                              /* INTID8    : SOFTWARE_GENERATE_INT8                   */
    NULL,                              /* INTID9    : SOFTWARE_GENERATE_INT9                   */
    NULL,                              /* INTID10   : SOFTWARE_GENERATE_INT10                  */
    NULL,                              /* INTID11   : SOFTWARE_GENERATE_INT11                  */
    NULL,                              /* INTID12   : SOFTWARE_GENERATE_INT12                  */
    NULL,                              /* INTID13   : SOFTWARE_GENERATE_INT13                  */
    NULL,                              /* INTID14   : SOFTWARE_GENERATE_INT14                  */
    NULL,                              /* INTID15   : SOFTWARE_GENERATE_INT15                  */
    NULL,                              /* INTID16   : RESERVED                                 */
    NULL,                              /* INTID17   : RESERVED                                 */
    NULL,                              /* INTID18   : RESERVED                                 */
    NULL,                              /* INTID19   : RESERVED                                 */
    NULL,                              /* INTID20   : RESERVED                                 */
    NULL,                              /* INTID21   : RESERVED                                 */
    NULL,                              /* INTID22   : DEBUG_COMMUNICATIONS_CHANNEL_INT         */
    NULL,                              /* INTID23   : PERFORMANCE_MONITOR_COUNTER_OVERFLOW_INT */
    NULL,                              /* INTID24   : CROSS_TRIGGER_INTERFACE_INT              */
    NULL,                              /* INTID25   : VIRTUAL_CPU_INTERFACE_MAINTENANCE_INT    */
    NULL,                              /* INTID26   : HYPERVISOR_TIMER_INT                     */
    NULL,                              /* INTID27   : VIRTUAL_TIMER_INT                        */
    NULL,                              /* INTID28   : RESERVED                                 */
    NULL,                              /* INTID29   : RESERVED                                 */
    NULL,                              /* INTID30   : NON-SECURE_PHYSICAL_TIMER_INT            */
    NULL,                              /* INTID31   : RESERVED                                 */
};

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

#if __FPU_USED
void bsp_fpu_advancedsimd_init(void);

#endif

#if (0 == BSP_CFG_CORE_CR52) || (1 == BSP_FEATURE_BSP_HAS_CR52_CPU1_TCM)
void bsp_slavetcm_enable(void);

#endif

void bsp_irq_cfg_common(void);

#if __FPU_USED

/*******************************************************************************************************************//**
 * Initialize FPU and Advanced SIMD setting.
 **********************************************************************************************************************/
void bsp_fpu_advancedsimd_init (void)
{
    uint32_t apacr;
    uint32_t fpexc;

    /* Enables cp10 and cp11 accessing */
    apacr  = __get_CPACR();
    apacr |= BSP_CPCAR_CP_ENABLE;
    __set_CPACR(apacr);
    __ISB();

    /* Enables the FPU */
    fpexc  = __get_FPEXC();
    fpexc |= BSP_FPEXC_EN_ENABLE;
    __set_FPEXC(fpexc);
    __ISB();
}

#endif

#if (0 == BSP_CFG_CORE_CR52) || (1 == BSP_FEATURE_BSP_HAS_CR52_CPU1_TCM)

/*******************************************************************************************************************//**
 * Settings the privilege level required for the AXIS to access the TCM.
 **********************************************************************************************************************/
void bsp_slavetcm_enable (void)
{
    uint32_t imp_slavepctlr;

    /* Enable TCM access privilege and non privilege */
    imp_slavepctlr  = __get_IMP_SLAVEPCTLR();
    imp_slavepctlr |= BSP_TCM_ALL_ACCESS_ENABLE;
    __DSB();

    __set_IMP_SLAVEPCTLR(imp_slavepctlr);
    __ISB();
}

#endif

/*******************************************************************************************************************//**
 * Initialize common configuration settings for interrupts
 **********************************************************************************************************************/
void bsp_irq_cfg_common (void)
{
    uint32_t icc_pmr;
    uint32_t icc_igrpen1;
    uint32_t icc_ctlr;

    /* Set priority mask level for CPU interface */
    icc_pmr = BSP_PRIORITY_MASK;
    __set_ICC_PMR(icc_pmr);

    /* Enable group 1 interrupts */
    icc_igrpen1 = BSP_ENABLE_GROUP_INT;
    __set_ICC_IGRPEN1(icc_igrpen1);

    /* Use ICC_BPR0 for interrupt preemption for both group 0 and group 1 interrupts */
    icc_ctlr  = __get_ICC_CTLR();
    icc_ctlr |= BSP_ICC_CTLR;
    __set_ICC_CTLR(icc_ctlr);

    __ISB();
}
