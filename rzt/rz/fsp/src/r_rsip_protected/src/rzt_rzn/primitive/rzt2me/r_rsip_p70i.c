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

rsip_ret_t r_rsip_p70i (const uint32_t InData_HashType[], const uint32_t InData_MsgLen[])
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

    WR1_PROG(REG_1B00H, 0x00700002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    r_rsip_func100(bswap_32big(0xade13e4fU),
                   bswap_32big(0xa52eadd8U),
                   bswap_32big(0xde8a349bU),
                   bswap_32big(0x519a9680U));
    WR1_PROG(REG_2000H, 0x00000001U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x3420a800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000007U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x2000b400U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000006U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00600000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xbdc711fcU), bswap_32big(0xb1175664U), bswap_32big(0x616b043eU),
                       bswap_32big(0x6ab6162eU));
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00000040U);
        r_rsip_func101(bswap_32big(0x560437d4U), bswap_32big(0xda2563c9U), bswap_32big(0xb673250bU),
                       bswap_32big(0x954366a8U));
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00000050U);
        r_rsip_func101(bswap_32big(0x224728f5U), bswap_32big(0x83aa17d0U), bswap_32big(0x5f60d96eU),
                       bswap_32big(0x4aee0873U));
    }
    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00000080U);
        r_rsip_func101(bswap_32big(0x94f84da1U), bswap_32big(0x51730359U), bswap_32big(0x578e7a2bU),
                       bswap_32big(0xf720c4c4U));
    }
    else if (0x00000004U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00000090U);
        r_rsip_func101(bswap_32big(0x05d62859U), bswap_32big(0xa88840cdU), bswap_32big(0xe2083ad2U),
                       bswap_32big(0xb7b84bdfU));
    }
    else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x000000a0U);
        r_rsip_func101(bswap_32big(0x45c98961U), bswap_32big(0x45c359d6U), bswap_32big(0xed5a986eU),
                       bswap_32big(0xd8abd43cU));
    }
    else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x000000b0U);
        r_rsip_func101(bswap_32big(0x5f7ff51eU), bswap_32big(0x44b9a7d5U), bswap_32big(0xabf15500U),
                       bswap_32big(0xef7e458eU));
    }

    if ((InData_MsgLen[0] == 0) && (InData_MsgLen[1] == 0))
    {
        WR1_PROG(REG_200CH, 0x00000100U);
        r_rsip_func101(bswap_32big(0x3ecdc4f4U), bswap_32big(0x4e6d568dU), bswap_32big(0xcec8063bU),
                       bswap_32big(0x871a73f7U));
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_ADDR(REG_2014H, &InData_MsgLen[0]);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_ADDR(REG_2010H, &InData_MsgLen[1]);
        r_rsip_func101(bswap_32big(0xcae819a9U), bswap_32big(0xe87d46a7U), bswap_32big(0xec4deda1U),
                       bswap_32big(0xec19563fU));
    }

    return RSIP_RET_PASS;
}
