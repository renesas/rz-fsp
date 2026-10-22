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

rsip_ret_t r_rsip_p78i (const uint32_t InData_HashType[], const uint32_t InData_MsgLen[])
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

    WR1_PROG(REG_1B00H, 0x00780002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    r_rsip_func100(bswap_32big(0xdeb114d4U),
                   bswap_32big(0x9ff3ee5dU),
                   bswap_32big(0xd13ada5dU),
                   bswap_32big(0x6e19b850U));
    WR1_PROG(REG_2400H, 0x00000001U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x3420a800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x2000b400U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00600000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2404H, 0x00000001U);
        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000024U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x6b833c6eU), bswap_32big(0x478fd738U), bswap_32big(0x19b18a84U),
                       bswap_32big(0xd345dfd2U));
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2404H, 0x00000011U);
        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000022U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x62dbac23U), bswap_32big(0x34ab7306U), bswap_32big(0x7f83f2e7U),
                       bswap_32big(0xcb289591U));
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2404H, 0x00000021U);
        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000001aU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x1ce0cf24U), bswap_32big(0xc0ca296bU), bswap_32big(0x5dfd4b08U),
                       bswap_32big(0xa3df4c0dU));
    }
    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2404H, 0x00000031U);
        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000012U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xbc7d8a98U), bswap_32big(0x85c544b5U), bswap_32big(0xc7b17cf1U),
                       bswap_32big(0x024fe3b4U));
    }

    r_rsip_func100(bswap_32big(0xdea52196U),
                   bswap_32big(0xe0e27a87U),
                   bswap_32big(0x6402d8a9U),
                   bswap_32big(0x1da13830U));
    WR1_PROG(REG_1608H, 0x81010020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1408H, 0x00005006U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
    if ((InData_MsgLen[0] == 0) && (InData_MsgLen[1] == 0))
    {
        WR1_PROG(REG_240CH, 0x00000100U);
        r_rsip_func101(bswap_32big(0xadf9f61bU), bswap_32big(0xe7d6e424U), bswap_32big(0xb95840eeU),
                       bswap_32big(0xa957929aU));
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_ADDR(REG_2414H, &InData_MsgLen[0]);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_ADDR(REG_2410H, &InData_MsgLen[1]);
        r_rsip_func101(bswap_32big(0xe313d6d1U), bswap_32big(0xdf29b492U), bswap_32big(0x71e1824bU),
                       bswap_32big(0x2236a304U));
    }

    return RSIP_RET_PASS;
}
