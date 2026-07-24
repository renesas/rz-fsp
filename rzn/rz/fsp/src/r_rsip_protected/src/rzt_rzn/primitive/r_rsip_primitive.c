/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_rsip_primitive.h"
#include "r_rsip_reg.h"
#include "r_rsip_util.h"

#if RSIP_POLLING_LOOP_LIMIT
 #include "bsp_api.h"
 #include "r_rsip_addr.h"
#endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

#if RSIP_POLLING_LOOP_LIMIT
static uintptr_t gs_rsip_old_mask_level = 0U;
#endif

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

#if RSIP_POLLING_LOOP_LIMIT
jmp_buf g_rsip_jmp_buf = {0};
#endif

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

RSIP_PRV_PRIMITIVE_FUNC void r_rsip_subfunc001 (uint32_t ARG1, uint32_t ARG2, uint32_t ARG3, uint32_t ARG4)
{
    WR1_PROG(REG_1014H, ARG1);
    WR1_PROG(REG_1018H, ARG2);
    WR1_PROG(REG_1020H, ARG3);
    WR1_PROG(REG_1004H, ARG4);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0U, 0U);
}

RSIP_PRV_PRIMITIVE_FUNC void r_rsip_subfunc002 (uint32_t ARG1, uint32_t ARG2, uint32_t ARG3)
{
    WR1_PROG(REG_101CH, ARG1);
    WR1_PROG(REG_1020H, ARG2);
    WR1_PROG(REG_1004H, ARG3);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0U, 0U);
}

RSIP_PRV_PRIMITIVE_FUNC void r_rsip_subfunc003 (uint32_t ARG1)
{
    WR1_PROG(REG_1400H, ARG1);
    WAIT_STS(REG_1404H, 30U, 0U);
    WR1_PROG(REG_143CH, 0x00001800U);
}

RSIP_PRV_PRIMITIVE_FUNC void r_rsip_subfunc004 (uint32_t ARG1, uint32_t ARG2, uint32_t ARG3)
{
    WR1_PROG(REG_1014H, ARG1);
    WR1_PROG(REG_1020H, ARG2);
    WR1_PROG(REG_1004H, ARG3);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0U, 0U);
}

RSIP_PRV_PRIMITIVE_FUNC void r_rsip_subfunc005 (uint32_t ARG1,
                                                uint32_t ARG2,
                                                uint32_t ARG3,
                                                uint32_t ARG4,
                                                uint32_t ARG5,
                                                uint32_t ARG6)
{
    WR1_PROG(REG_1014H, ARG1);
    WR1_PROG(REG_1018H, ARG2);
    WR1_PROG(REG_101CH, ARG3);
    WR1_PROG(REG_1020H, ARG4);
    WR1_PROG(REG_1004H, ARG5);
    WR1_PROG(REG_1408H, ARG6);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0U, 0U);
}

RSIP_PRV_PRIMITIVE_FUNC void r_rsip_subfunc006 (uint32_t ARG1, uint32_t ARG2, uint32_t ARG3)
{
    WR1_PROG(REG_1010H, ARG1);
    WR1_PROG(REG_101CH, ARG2);
    WR1_PROG(REG_1004H, ARG3);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0U, 0U);
}

RSIP_PRV_PRIMITIVE_FUNC void r_rsip_subfunc007 (uint32_t ARG1)
{
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b040184U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, ARG1);
    WAIT_STS(REG_1A28H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000900U);
}

RSIP_PRV_PRIMITIVE_FUNC void r_rsip_subfunc008 (uint32_t ARG1, uint32_t ARG2, uint32_t ARG3)
{
    WR1_PROG(REG_1404H, ARG1);
    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, ARG2);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, ARG3);
    WR1_PROG(REG_1458H, 0x00000000U);
}

RSIP_PRV_PRIMITIVE_FUNC void r_rsip_subfunc009 (uint32_t ARG1)
{
    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x800103a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, ARG1);
    WR1_PROG(REG_1458H, 0x00000000U);
}

#if RSIP_POLLING_LOOP_LIMIT

/*
 * To avoid rebuilding all primitive functions every time, they do not include bsp_api.h.
 * Instead, these functions are defined as global functions.
 */

void r_rsip_wait_sts (volatile uint32_t * reg, uint8_t bitPos, uint8_t value)
{
    uint32_t loop = RSIP_POLLING_LOOP_LIMIT;

    while (!CHCK_STS(*reg, bitPos, value) && --loop)
    {
        ;
    }

    if (!loop)
    {
        /* Critical section enter */
        gs_rsip_old_mask_level = FSP_CRITICAL_SECTION_GET_CURRENT_STATE();
        FSP_CRITICAL_SECTION_SET_STATE(FSP_CRITICAL_SECTION_IRQ_MASK_SET);

        /* Abort */
        longjmp(g_rsip_jmp_buf, 1);
    }
}

void r_rsip_critical_section_exit (void)
{
    FSP_CRITICAL_SECTION_SET_STATE(gs_rsip_old_mask_level);
}

#endif
