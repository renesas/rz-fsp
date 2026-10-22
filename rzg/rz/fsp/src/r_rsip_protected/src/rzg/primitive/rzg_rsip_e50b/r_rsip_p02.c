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

rsip_ret_t r_rsip_p02 (void)
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
    if (0x0U != RD1_MASK(REG_14BCH, 0x1fU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00020001U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0b070194U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x013a94a0U));
    WAIT_STS(REG_1A28H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000900U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000074U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1600H, 0x3000a820U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00010020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1708H, 0U, 0U);
    WAIT_STS(REG_1708H, 0U, 0U);
    WR1_PROG(REG_1704H, 0x00000080U);
    WR1_PROG(REG_1600H, 0x00000863U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000008a5U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000013U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000348U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b500U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000000b7U);
    WR1_PROG(REG_1458H, 0x00000000U);
    for (jLoop = 0; jLoop < 1; jLoop = jLoop + 1)
    {
        r_rsip_func100(bswap_32big(0x6166f721U), bswap_32big(0x7fcde256U), bswap_32big(0x5a06d4eeU),
                       bswap_32big(0x53b4b120U));
        WR1_PROG(REG_1600H, 0x00007c01U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WAIT_STS(REG_1708H, 0U, 0U);
            WAIT_STS(REG_1708H, 0U, 0U);
            WR1_PROG(REG_1704H, 0x0020001bU);
            r_rsip_func101(bswap_32big(0x7047d94fU), bswap_32big(0x3d634cfaU), bswap_32big(0x4ed1e1f4U),
                           bswap_32big(0x79028c4eU));
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WAIT_STS(REG_1708H, 0U, 0U);
            WAIT_STS(REG_1708H, 0U, 0U);
            WR1_PROG(REG_1704H, 0x00200019U);
            r_rsip_func101(bswap_32big(0xfa18c177U), bswap_32big(0x730a744bU), bswap_32big(0x17ffee5dU),
                           bswap_32big(0x91d3f067U));
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WAIT_STS(REG_1708H, 0U, 0U);
            WAIT_STS(REG_1708H, 0U, 0U);
            WR1_PROG(REG_1704H, 0x0020001aU);
            r_rsip_func101(bswap_32big(0x2a2e0ad7U), bswap_32big(0xe62e3f36U), bswap_32big(0xa5dde842U),
                           bswap_32big(0xedf5ca96U));
        }

        WR1_PROG(REG_1A2CH, 0x00000700U);
        WR1_PROG(REG_1A24H, 0x0e3d8407U);
        r_rsip_subfunc003(0x00840081U);
        WAIT_STS(REG_1708H, 2U, 1U);
        WR1_PROG(REG_143CH, 0x00001200U);
        WAIT_STS(REG_1A28H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000a00U);
        WR1_PROG(REG_1600H, 0x00000800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x808a0000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03440029U);
        WR1_PROG(REG_1600H, 0x000038a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003405U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00002804U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x342028e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x10005066U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x34202808U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x10005066U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003485U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x447dcd80U), bswap_32big(0x00281883U), bswap_32big(0x31161260U),
                       bswap_32big(0x4962adccU));
    }

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000005AU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000842U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000008c6U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b480U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_1600H, 0x01003804U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x342028e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x10005066U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00002440U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00002cc0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00002485U);
        WR1_PROG(REG_1458H, 0x00000000U);
    }

    WR1_PROG(REG_1600H, 0x00002c20U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38008840U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000100U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000033U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b480U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000024U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01003804U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x342028e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x10005066U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00002cc0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b480U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000026U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01003804U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x342028e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x10005066U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38008860U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xb8f5cbe9U),
                   bswap_32big(0x67a28f44U),
                   bswap_32big(0x01d63b1dU),
                   bswap_32big(0x1d7c4730U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x37a8707aU), bswap_32big(0x195e84a6U), bswap_32big(0x37d15647U),
                       bswap_32big(0xfd4a0e36U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_RETRY;
    }
    else
    {
        r_rsip_func100(bswap_32big(0xd52f6bf8U), bswap_32big(0xe625db72U), bswap_32big(0x540aa8dbU),
                       bswap_32big(0xbc89c210U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c300104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        WR1_PROG(REG_1A24H, 0x0e3d0505U);
        WAIT_STS(REG_1708H, 0U, 0U);
        WAIT_STS(REG_1708H, 0U, 0U);
        WR1_PROG(REG_1704H, 0x00040013U);
        r_rsip_subfunc003(0x00840011U);
        WAIT_STS(REG_1708H, 3U, 0U);
        WR1_PROG(REG_1700H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x80040080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x080000b4U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WAIT_STS(REG_1A28H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000900U);
        r_rsip_func100(bswap_32big(0xe0877e98U), bswap_32big(0xe841b260U), bswap_32big(0x0c0e38f4U),
                       bswap_32big(0x20cb9c4aU));
        WR1_PROG(REG_1444H, 0x000003a2U);
        WR1_PROG(REG_1A24H, 0x08000075U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        WR1_PROG(REG_1A2CH, 0x00000100U);
        WR1_PROG(REG_1A24H, 0x07338d07U);
        WR1_PROG(REG_1608H, 0x81080000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00890021U);
        WR1_PROG(REG_1A24H, 0x080000b5U);
        r_rsip_subfunc003(0x00820011U);
        r_rsip_func100(bswap_32big(0xc7bbbeb4U), bswap_32big(0x0a53aef5U), bswap_32big(0x156a6315U),
                       bswap_32big(0xeba2f4a0U));
        WR1_PROG(REG_1A24H, 0x08000075U);
        r_rsip_subfunc003(0x00820011U);
        r_rsip_func103();
        r_rsip_func100(bswap_32big(0x415ae6b8U), bswap_32big(0x7ecd3bfeU), bswap_32big(0xe850a73cU),
                       bswap_32big(0xbb4bb375U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c2000d4U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WAIT_STS(REG_1A28H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000900U);
        r_rsip_func100(bswap_32big(0x97e7728bU), bswap_32big(0x2ea62f2aU), bswap_32big(0xba304d18U),
                       bswap_32big(0x9d471387U));
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1404H, 0x20000000U);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_subfunc003(0x00c01001U);
        WR1_PROG(REG_1B08H, 0x00000291U);
        r_rsip_func102(bswap_32big(0xb2b4254dU), bswap_32big(0xc7439723U), bswap_32big(0x4743f45fU),
                       bswap_32big(0xb0d96039U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_PASS;
    }
}
