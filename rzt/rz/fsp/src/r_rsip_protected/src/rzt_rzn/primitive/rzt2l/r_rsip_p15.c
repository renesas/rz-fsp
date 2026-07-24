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

rsip_ret_t r_rsip_p15 (const uint32_t InData_SharedKeyNum[],
                       const uint32_t InData_SharedKeyIndex[],
                       const uint32_t InData_SessionKey[],
                       const uint32_t InData_IV[],
                       const uint32_t InData_EncAuthData[],
                       const uint32_t InData_HashType[],
                       uint32_t       OutData_Hash[])
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
    if (0x0U != RD1_MASK(REG_14B4H, 0x1dU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00150002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_SharedKeyNum[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38008c00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0xfffffff0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x10b9f517U),
                   bswap_32big(0x34ec42ddU),
                   bswap_32big(0xceb2e538U),
                   bswap_32big(0xd1d3e4eaU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xe7614053U), bswap_32big(0xe6194a5bU), bswap_32big(0xe85d4778U),
                       bswap_32big(0x906f6e1aU));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_subfunc009(bswap_32big(0x00000015U));
        r_rsip_func101(bswap_32big(0x3e136f33U), bswap_32big(0xcd088d9fU), bswap_32big(0x464b20baU),
                       bswap_32big(0xc3a3f7d6U));
        r_rsip_func041();
        r_rsip_func100(bswap_32big(0x304d7132U), bswap_32big(0xfcfccb71U), bswap_32big(0x540f16caU),
                       bswap_32big(0xe340b6e2U));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0xf7001cb5U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[0]);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[1]);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[2]);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[3]);
        WAIT_STS(REG_1828H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000500U);
        r_rsip_func100(bswap_32big(0x9d6a47cdU), bswap_32big(0x41301476U), bswap_32big(0x715b0f52U),
                       bswap_32big(0x3ec538b8U));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x07000d05U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[4]);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[5]);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[6]);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[7]);
        WR1_PROG(REG_1824H, 0x8c100005U);
        r_rsip_subfunc003(0x00410011U);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x0a03008dU);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_SessionKey[0]);
        WR1_ADDR(REG_1420H, &InData_SessionKey[1]);
        WR1_ADDR(REG_1420H, &InData_SessionKey[2]);
        WR1_ADDR(REG_1420H, &InData_SessionKey[3]);
        WAIT_STS(REG_1828H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000500U);
        r_rsip_func100(bswap_32big(0x7ba4ec35U), bswap_32big(0x569616afU), bswap_32big(0x97d03dffU),
                       bswap_32big(0x4152e904U));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x0a03009dU);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_SessionKey[4]);
        WR1_ADDR(REG_1420H, &InData_SessionKey[5]);
        WR1_ADDR(REG_1420H, &InData_SessionKey[6]);
        WR1_ADDR(REG_1420H, &InData_SessionKey[7]);
        WAIT_STS(REG_1828H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000500U);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x08000045U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_IV[0]);
        WR1_ADDR(REG_1420H, &InData_IV[1]);
        WR1_ADDR(REG_1420H, &InData_IV[2]);
        WR1_ADDR(REG_1420H, &InData_IV[3]);
        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_1824H, 0x4a010054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0xd900090dU);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncAuthData[0]);
        WR1_ADDR(REG_1420H, &InData_EncAuthData[1]);
        WR1_ADDR(REG_1420H, &InData_EncAuthData[2]);
        WR1_ADDR(REG_1420H, &InData_EncAuthData[3]);
        WR1_PROG(REG_1824H, 0x08000045U);
        r_rsip_subfunc003(0x00410011U);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x9c100005U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncAuthData[4]);
        WR1_ADDR(REG_1420H, &InData_EncAuthData[5]);
        WR1_ADDR(REG_1420H, &InData_EncAuthData[6]);
        WR1_ADDR(REG_1420H, &InData_EncAuthData[7]);
        r_rsip_func100(bswap_32big(0xca6b8a9dU), bswap_32big(0x197afcb3U), bswap_32big(0xfcd59875U),
                       bswap_32big(0x778afd7bU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x90b6a0d7U), bswap_32big(0xad04ef23U), bswap_32big(0x4841762bU),
                           bswap_32big(0xd53a238bU));
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000000c7U);
            WR1_PROG(REG_1608H, 0x80010000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_HashType[0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x3000a800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000003U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00010020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000003U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000080U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x24cca113U), bswap_32big(0xa0632057U), bswap_32big(0x98ac2c0aU),
                           bswap_32big(0x4fef3821U));
            WR1_PROG(REG_1600H, 0x00007c00U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_143CH, 0x00600000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
            {
                WR1_PROG(REG_1600H, 0x0000b420U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x017adf63U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b440U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0xefeafb0dU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x40a038b6U),
                               bswap_32big(0xd4119813U),
                               bswap_32big(0x25c7bf23U),
                               bswap_32big(0xba9752c4U));
            }
            else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
            {
                WR1_PROG(REG_1600H, 0x0000b420U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x01b262e6U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b440U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0xefeafb0dU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x82c9bebcU),
                               bswap_32big(0xc8ec75fdU),
                               bswap_32big(0x80af32c6U),
                               bswap_32big(0x043e82b8U));
            }
            else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
            {
                WR1_PROG(REG_1600H, 0x0000b420U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x01ad187eU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b440U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0xcbfac6bbU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xedf6c729U),
                               bswap_32big(0x0579a881U),
                               bswap_32big(0x73e6e96aU),
                               bswap_32big(0x389c63cdU));
            }
            else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
            {
                WR1_PROG(REG_1600H, 0x0000b420U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x01d2fa53U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b440U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0xcbfac6bbU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xb8c4737cU),
                               bswap_32big(0x8ee869d7U),
                               bswap_32big(0x3fae6272U),
                               bswap_32big(0x256eb37bU));
            }

            r_rsip_func100(bswap_32big(0xe4c7cce5U), bswap_32big(0x511055beU), bswap_32big(0x7c2856f8U),
                           bswap_32big(0x91824a87U));
            WR1_PROG(REG_1A24H, 0x0a470084U);
            WR1_PROG(REG_1608H, 0x81010040U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00890005U);
            WAIT_STS(REG_1A28H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000900U);
            WR1_PROG(REG_1A24H, 0x30001104U);
            WR1_PROG(REG_1608H, 0x81010020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00890005U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000004U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1600H, 0x00008c20U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00ffffffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00009020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x02000000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1A24H, 0x30001104U);
            WR1_PROG(REG_1608H, 0x81010020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00890005U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000004U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_2000H, 0x00000001U);
            WR1_PROG(REG_2004H, 0x00000050U);
            WR1_PROG(REG_2008H, 0x00000013U);
            r_rsip_subfunc003(0x01420021U);
            WR1_PROG(REG_1444H, 0x00000020U);
            WR1_PROG(REG_2014H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x00000020U);
            WR1_PROG(REG_2010H, 0x00000080U);
            WR1_PROG(REG_200CH, 0x00000001U);
            WAIT_STS(REG_2030H, 0U, 1U);
            WR1_PROG(REG_1444H, 0x000000a1U);
            WR1_PROG(REG_1824H, 0x0c000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            r_rsip_subfunc003(0x01410011U);
            WAIT_STS(REG_2030H, 8U, 0U);
            WR1_PROG(REG_143CH, 0x00001600U);
            WAIT_STS(REG_2030H, 4U, 1U);
            r_rsip_func100(bswap_32big(0x4d4d99b4U), bswap_32big(0x41f78a4cU), bswap_32big(0xf9e4c10eU),
                           bswap_32big(0x80759064U));
            WR1_PROG(REG_1408H, 0x00004022U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_Hash[0]);
            RD1_ADDR(REG_1420H, &OutData_Hash[1]);
            RD1_ADDR(REG_1420H, &OutData_Hash[2]);
            RD1_ADDR(REG_1420H, &OutData_Hash[3]);
            RD1_ADDR(REG_1420H, &OutData_Hash[4]);
            RD1_ADDR(REG_1420H, &OutData_Hash[5]);
            RD1_ADDR(REG_1420H, &OutData_Hash[6]);
            RD1_ADDR(REG_1420H, &OutData_Hash[7]);
            r_rsip_func102(bswap_32big(0x1e48436eU), bswap_32big(0xf0acbde0U), bswap_32big(0xc730f6e3U),
                           bswap_32big(0x6c0b9135U));
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
