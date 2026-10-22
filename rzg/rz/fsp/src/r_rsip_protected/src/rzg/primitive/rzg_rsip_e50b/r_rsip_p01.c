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

#include "bsp_api.h"

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

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

RSIP_PRV_PRIMITIVE_FUNC

rsip_ret_t r_rsip_p01 (void)
{
    RSIP_PRV_PRIMITIVE_ENTRY;
    uint32_t iLoop;
    uint32_t jLoop;
    uint32_t kLoop;
    uint32_t oLoop;
    uint32_t oLoop1;
    uint32_t OFS_ADR;
    (void) iLoop;
    (void) jLoop;
    (void) kLoop;
    (void) oLoop;
    (void) oLoop1;
    (void) OFS_ADR;
#if BSP_MCU_GROUP_RZG3E
    WR1_PROG(REG_1D04H, 0x0007ad35U);
    WR1_PROG(REG_1D08H, 0x000ba56eU);
#else
    WR1_PROG(REG_1D04H, 0x000cf33cU);
    WR1_PROG(REG_1D08H, 0x0005797eU);
#endif
    WR1_PROG(REG_1D00H, 0x00000001U);
    WAIT_STS(REG_1D00H, 1U, 0U);
    if (0x00000000U != RD1_MASK(REG_1D00H, 0x00030000U))
    {
        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_140CH, 0x38c60eedU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1448H, 0x00000000U);
        WR1_PROG(REG_1408H, 0x00000001U);
        WR1_PROG(REG_1414H, 0x00001401U);
        if (0x0U != RD1_MASK(REG_14BCH, 0x1fU))
        {
            return RSIP_RET_RESOURCE_CONFLICT;
        }

        WR1_PROG(REG_1800H, 0x00000001U);
        WR1_PROG(REG_1700H, 0x00000001U);
        WR1_PROG(REG_1B00H, 0x00018001U);
        WR1_PROG(REG_1B08H, 0x00000d00U);
        WR1_PROG(REG_1804H, 0x00008004U);
        WR1_PROG(REG_1444H, 0x000003a2U);
#if BSP_MCU_GROUP_RZG3E
        r_rsip_func101(0xf6a0b0e8U, 0x9051cdceU, 0x0b5e282eU, 0x41c911e9U);
#else
        r_rsip_func101(0x277ada2fU, 0x3f446a74U, 0x7cd563f9U, 0xdd7d87a1U);
#endif
        WR1_PROG(REG_1804H, 0x00000000U);
        WR1_PROG(REG_1444H, 0x000003a2U);
        WR1_PROG(REG_1A24H, 0x0a0700f5U);
        WAIT_STS(REG_1444H, 31U, 1U);
#if BSP_MCU_GROUP_RZG3E
        WR1_PROG(REG_1420H, 0x32239e90U);
        WR1_PROG(REG_1420H, 0xf3ae3ad0U);
        WR1_PROG(REG_1420H, 0x47fe1346U);
        WR1_PROG(REG_1420H, 0x92d02723U);
#else
        WR1_PROG(REG_1420H, 0x3a459328U);
        WR1_PROG(REG_1420H, 0xd8a737e0U);
        WR1_PROG(REG_1420H, 0x55c5c888U);
        WR1_PROG(REG_1420H, 0x2131df81U);
#endif
        WAIT_STS(REG_1A28H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000900U);
#if BSP_MCU_GROUP_RZG3E
        r_rsip_func101(0xd56d4976U, 0xb30ee1ebU, 0x298c0a4fU, 0x814833abU);
#else
        r_rsip_func101(0x7a410d4aU, 0x27d3c8b5U, 0xfb30fd61U, 0x161396b2U);
#endif
        r_rsip_func100(0xd4116c3aU, 0x73981cd9U, 0xba68133dU, 0x842b3c9fU);
        WR1_PROG(REG_1408H, 0x00020000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_142CH, 13U, 0U))
        {
            WR1_PROG(REG_14BCH, 0x00000020U);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1430H, 0x0000FFFFU);
            WR1_PROG(REG_143CH, 0x003e0000U);
            r_rsip_func100(0x351971bdU, 0x5b405310U, 0xbdea2ff5U, 0x900e221aU);
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_14BCH, 0x00000020U);

                return RSIP_RET_LIFECYCLE_FAIL;
            }
            else
            {
                WR1_PROG(REG_1444H, 0x000001a2U);
                WR1_PROG(REG_1A24H, 0x0a4700c4U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, 0xe3975ed0U);
                WAIT_STS(REG_1A28H, 6U, 0U);
                WR1_PROG(REG_143CH, 0x00000900U);
                WR1_PROG(REG_1A24H, 0x0a040104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, 0x84e94055U);
                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000001e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x80840000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                WR1_PROG(REG_1444H, 0x000001a2U);
                WR1_PROG(REG_1A24H, 0x0a0700c4U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, 0x5639e336U);
                WAIT_STS(REG_1A28H, 6U, 0U);
                WR1_PROG(REG_143CH, 0x00000900U);
                WR1_PROG(REG_1A24H, 0x0a040104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, 0x7d47c3feU);
                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000001f0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x80840000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                WR1_PROG(REG_1B08H, 0x00000201U);
                r_rsip_func102(0xf79a728bU, 0x6471ad52U, 0x2b5fd63fU, 0xd531e5bdU);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
