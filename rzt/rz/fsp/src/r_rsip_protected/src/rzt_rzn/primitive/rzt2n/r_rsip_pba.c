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

rsip_ret_t r_rsip_pba (const uint32_t InData_Cmd[], const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[])
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
    if (0x0U != RD1_MASK(REG_14B0H, 0x1cU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00ba0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000003c7U);
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[2]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[3]);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x000000baU));
    r_rsip_func101(bswap_32big(0xc8aba39eU),
                   bswap_32big(0xc9ace0dcU),
                   bswap_32big(0x359abe9fU),
                   bswap_32big(0x41bc827aU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x016f646fU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x000000baU));
    r_rsip_func101(bswap_32big(0x19e4f6baU),
                   bswap_32big(0x2389bf80U),
                   bswap_32big(0x8e5a4569U),
                   bswap_32big(0x85165ba7U));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xf7009d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[4]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[5]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[6]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[7]);
    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80840001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x07008d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[8]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[9]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[10]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[11]);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_subfunc003(0x00820011U);
    r_rsip_func100(bswap_32big(0xb5d53b6fU),
                   bswap_32big(0x9b9cdb6bU),
                   bswap_32big(0x2c6f5b55U),
                   bswap_32big(0x801150dfU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x073be7bbU), bswap_32big(0x41039b96U), bswap_32big(0xc6234818U),
                       bswap_32big(0x8e831df7U));
        WR1_PROG(REG_14B0H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0x5b3f4964U), bswap_32big(0x95db50e5U), bswap_32big(0xf46fda08U),
                       bswap_32big(0xc08582e4U));
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80010000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Cmd[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x3000a800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000002U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00010020U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b400U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000002U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00007c00U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0x1dd2fa73U), bswap_32big(0x850de9a2U), bswap_32big(0x42093054U),
                           bswap_32big(0x0faf4cb3U));
            WR1_PROG(REG_1438H, 0x40000000U);
            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81010000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x02090005U);
            r_rsip_func100(bswap_32big(0xfded8a88U), bswap_32big(0x1f570430U), bswap_32big(0x94764573U),
                           bswap_32big(0x69def265U));
            WR1_PROG(REG_1438H, 0x40000004U);
            r_rsip_subfunc003(0x02000011U);
            r_rsip_func100(bswap_32big(0x30eb1a55U), bswap_32big(0x0c95cd10U), bswap_32big(0xa5810e89U),
                           bswap_32big(0xfbfc0a49U));
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81840001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x02090011U);
            WR1_PROG(REG_1444H, 0x000001c7U);
            WR1_PROG(REG_1608H, 0x80020000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_DOTFSEED[0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_DOTFSEED[1]);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x631a468dU), bswap_32big(0x74237d09U), bswap_32big(0xfc7e40d8U),
                           bswap_32big(0x299dd5b2U));
            WR1_PROG(REG_1438H, 0x40000024U);
            WR1_PROG(REG_1608H, 0x81020000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x02090009U);
            r_rsip_func102(bswap_32big(0xf4c098fbU), bswap_32big(0xcf91c1e7U), bswap_32big(0x0859cf6bU),
                           bswap_32big(0x243eec33U));
            WR1_PROG(REG_14B0H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0xd255293eU), bswap_32big(0x87a2c147U), bswap_32big(0xc584bebeU),
                           bswap_32big(0xa23ca094U));
            WR1_PROG(REG_1438H, 0x40000100U);
            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81010000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x02090005U);
            r_rsip_func100(bswap_32big(0x8a034c49U), bswap_32big(0x520fcc00U), bswap_32big(0xa3d9a4f2U),
                           bswap_32big(0x9d61320cU));
            WR1_PROG(REG_1438H, 0x40000104U);
            r_rsip_subfunc003(0x02000011U);
            r_rsip_func100(bswap_32big(0x631c85ceU), bswap_32big(0x4d221448U), bswap_32big(0x3a52e5e9U),
                           bswap_32big(0xdaa6b67eU));
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81840001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x02090011U);
            WR1_PROG(REG_1444H, 0x000001c7U);
            WR1_PROG(REG_1608H, 0x80020000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_DOTFSEED[0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_DOTFSEED[1]);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x6b98e0deU), bswap_32big(0x4dc07842U), bswap_32big(0xfe3ab408U),
                           bswap_32big(0xca5ef83fU));
            WR1_PROG(REG_1438H, 0x40000124U);
            WR1_PROG(REG_1608H, 0x81020000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x02090009U);
            r_rsip_func102(bswap_32big(0x5aeacb6eU), bswap_32big(0x65271a20U), bswap_32big(0x1e83449bU),
                           bswap_32big(0x407353b0U));
            WR1_PROG(REG_14B0H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
        else
        {
            r_rsip_func100(bswap_32big(0x206c7409U), bswap_32big(0xe40829f6U), bswap_32big(0xf69a66f6U),
                           bswap_32big(0x17f5848cU));
            WR1_PROG(REG_1438H, 0x40000200U);
            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81010000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x02090005U);
            r_rsip_func100(bswap_32big(0xb04cb4ebU), bswap_32big(0x223c7816U), bswap_32big(0xf46d26d7U),
                           bswap_32big(0xa4acb8f3U));
            WR1_PROG(REG_1438H, 0x40000204U);
            r_rsip_subfunc003(0x02000011U);
            r_rsip_func100(bswap_32big(0x7c984cdfU), bswap_32big(0x1181486bU), bswap_32big(0x2d0c10a1U),
                           bswap_32big(0x636ec40fU));
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81840001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x02090011U);
            WR1_PROG(REG_1444H, 0x000001c7U);
            WR1_PROG(REG_1608H, 0x80020000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_DOTFSEED[0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_DOTFSEED[1]);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x089f980eU), bswap_32big(0x85ea5289U), bswap_32big(0xa34c583dU),
                           bswap_32big(0x157847ddU));
            WR1_PROG(REG_1438H, 0x40000224U);
            WR1_PROG(REG_1608H, 0x81020000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x02090009U);
            r_rsip_func102(bswap_32big(0xb2ea8fb2U), bswap_32big(0x89d1f4e1U), bswap_32big(0x0fe58d12U),
                           bswap_32big(0x9bdd609fU));
            WR1_PROG(REG_14B0H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
