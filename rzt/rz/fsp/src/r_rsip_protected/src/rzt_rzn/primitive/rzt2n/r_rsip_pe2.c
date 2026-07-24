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

rsip_ret_t r_rsip_pe2 (const uint32_t InData_CurveType[],
                       const uint32_t InData_PubKeyType[],
                       const uint32_t InData_PubKey[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_EncSecret[])
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
    if (0x0U != RD1_MASK(REG_14B8H, 0x1eU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00e20002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010340U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000b9cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x000000e2U));
    r_rsip_func101(bswap_32big(0x005a3826U),
                   bswap_32big(0xe3ca3217U),
                   bswap_32big(0xed6f285bU),
                   bswap_32big(0xf38c8485U));
    r_rsip_func086(InData_DomainParam);
    r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x04040010U);
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
    r_rsip_subfunc009(bswap_32big(0x0000e201U));
    r_rsip_func101(bswap_32big(0x97485776U),
                   bswap_32big(0xfa7fb38dU),
                   bswap_32big(0x679da3e8U),
                   bswap_32big(0x8f317f58U));
    r_rsip_func045();
    r_rsip_func022();
    r_rsip_subfunc009(bswap_32big(0x0000e201U));
    r_rsip_func101(bswap_32big(0xa1f2ea3dU),
                   bswap_32big(0xa27d234fU),
                   bswap_32big(0xec00a4d7U),
                   bswap_32big(0x3fed5f19U));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000007c2U);
    WR1_PROG(REG_1A2CH, 0x40000100U);
    WR1_PROG(REG_1A24H, 0xf7009d07U);
    for (iLoop = 0; iLoop < 8; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
    }

    WR1_PROG(REG_1404H, 0x13200000U);
    r_rsip_subfunc003(0x00c20021U);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x07008d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_subfunc003(0x00820011U);
    r_rsip_func100(bswap_32big(0xcd7a8bc4U),
                   bswap_32big(0x9ca37439U),
                   bswap_32big(0xb2f1d93aU),
                   bswap_32big(0xee5914c1U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x45a81b8fU), bswap_32big(0x38755bb9U), bswap_32big(0x0f0c928eU),
                       bswap_32big(0x9807c4c7U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80010360U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_PubKeyType[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x38000f7bU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x494a3317U), bswap_32big(0xe01b69e3U), bswap_32big(0xa37e23eaU),
                       bswap_32big(0x38ab8174U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1444H, 0x000007d0U);
            for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
            {
                WR1_ADDR((&(REG_00F0H))[iLoop / 4], &InData_PubKey[(iLoop / 4) + 0]);
            }

            WR1_PROG(REG_1444H, 0x000007d0U);
            for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
            {
                WR1_ADDR((&(REG_0140H))[iLoop / 4], &InData_PubKey[(iLoop / 4) + 8]);
            }

            r_rsip_func101(bswap_32big(0x9d1b6ab8U), bswap_32big(0x18a3faeaU), bswap_32big(0xdb8bf1e1U),
                           bswap_32big(0x876d705eU));
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000003c7U);
            WR1_PROG(REG_1608H, 0x80040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[1]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[2]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[3]);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x0000e202U));
            r_rsip_func101(bswap_32big(0x25dfe68aU), bswap_32big(0xeb45b61aU), bswap_32big(0xaafb1e8bU),
                           bswap_32big(0xddd248c3U));
            r_rsip_func045();
            r_rsip_func023();
            r_rsip_subfunc009(bswap_32big(0x0000e202U));
            r_rsip_func101(bswap_32big(0x8d825006U), bswap_32big(0xbd9f0589U), bswap_32big(0x25f80bfcU),
                           bswap_32big(0x5a913688U));
            r_rsip_func046();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000044U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1444H, 0x00000bc2U);
            WR1_PROG(REG_1A2CH, 0x40000200U);
            WR1_PROG(REG_1A24H, 0xe8009107U);
            for (iLoop = 0; iLoop < 12; iLoop = iLoop + 4)
            {
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 4]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 5]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 6]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 7]);
            }

            WR1_PROG(REG_1404H, 0x10f00000U);
            r_rsip_subfunc003(0x00c20021U);
            WR1_PROG(REG_1404H, 0x11400000U);
            r_rsip_subfunc003(0x00c20011U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x49108054U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8008105U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[16]);
            WR1_ADDR(REG_1420H, &InData_PubKey[17]);
            WR1_ADDR(REG_1420H, &InData_PubKey[18]);
            WR1_ADDR(REG_1420H, &InData_PubKey[19]);
            r_rsip_subfunc003(0x00c20011U);
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A24H, 0x9c100005U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[20]);
            WR1_ADDR(REG_1420H, &InData_PubKey[21]);
            WR1_ADDR(REG_1420H, &InData_PubKey[22]);
            WR1_ADDR(REG_1420H, &InData_PubKey[23]);
            r_rsip_func100(bswap_32big(0x7fb20c6cU), bswap_32big(0x387cea2aU), bswap_32big(0x01889884U),
                           bswap_32big(0xa2d03ea3U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x09bfcebeU),
                               bswap_32big(0x10767ce4U),
                               bswap_32big(0xb0f12c53U),
                               bswap_32big(0x0fb782d4U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x3305fe88U),
                               bswap_32big(0x47897502U),
                               bswap_32big(0x57993955U),
                               bswap_32big(0x474d3824U));
            }
        }

        r_rsip_func008();
        r_rsip_func100(bswap_32big(0xc3925351U), bswap_32big(0x5fae6e12U), bswap_32big(0x437c814aU),
                       bswap_32big(0xa0965e99U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xb7a64e8bU), bswap_32big(0x8d860c05U), bswap_32big(0x4afe13d7U),
                           bswap_32big(0x4d332113U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1404H, 0x10f00000U);
            r_rsip_subfunc003(0x00c00021U);
            r_rsip_subfunc001(0x00000200U, 0x00000110U, 0x00000228U, 0x04040009U);
            r_rsip_subfunc001(0x000001b0U, 0x00000110U, 0x00000200U, 0x04040009U);
            r_rsip_subfunc009(bswap_32big(0x000000e2U));
            r_rsip_func101(bswap_32big(0x1a13b55cU), bswap_32big(0x9aa1765aU), bswap_32big(0x1b24d0a8U),
                           bswap_32big(0xf581ff04U));
            r_rsip_func088();
            r_rsip_func100(bswap_32big(0x68500d37U), bswap_32big(0x6182e480U), bswap_32big(0x39813135U),
                           bswap_32big(0x7e41351aU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x095c1562U),
                               bswap_32big(0x2c6eed02U),
                               bswap_32big(0x4fe8f6e0U),
                               bswap_32big(0x8274baa1U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0x588bb4a0U),
                               bswap_32big(0x30d71bd3U),
                               bswap_32big(0x8d2c4abeU),
                               bswap_32big(0x0d5a2fa8U));
                r_rsip_func103();
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c200104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1608H, 0x80040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                r_rsip_subfunc009(bswap_32big(0x0000e203U));
                r_rsip_func101(bswap_32big(0xa416dd98U),
                               bswap_32big(0xd3af3b94U),
                               bswap_32big(0x77692473U),
                               bswap_32big(0x8d95c962U));
                r_rsip_func045();
                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x011ec161U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc009(bswap_32big(0x0000e203U));
                r_rsip_func101(bswap_32big(0x8a2295bcU),
                               bswap_32big(0x703e16c8U),
                               bswap_32big(0x471db6c1U),
                               bswap_32big(0x8680840dU));
                r_rsip_func046();
                r_rsip_func100(bswap_32big(0xf8cc5110U),
                               bswap_32big(0xa18ef480U),
                               bswap_32big(0x0dab5f92U),
                               bswap_32big(0xee8f096aU));
                WR1_PROG(REG_1A2CH, 0x40000100U);
                WR1_PROG(REG_1A24H, 0xe7009d07U);
                WR1_PROG(REG_1404H, 0x12800000U);
                r_rsip_subfunc003(0x00830021U);
                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[4]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[5]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[6]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[7]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[8]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[9]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[10]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[11]);
                r_rsip_func100(bswap_32big(0x3183e313U),
                               bswap_32big(0xbbc764eeU),
                               bswap_32big(0xb1fe445aU),
                               bswap_32big(0xce0e0349U));
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_subfunc003(0x00820011U);
                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[12]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[13]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[14]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[15]);
                r_rsip_func100(bswap_32big(0xa6c080b8U),
                               bswap_32big(0x53a91e3bU),
                               bswap_32big(0xef30b63dU),
                               bswap_32big(0xaba21a96U));
                WR1_PROG(REG_1608H, 0x81040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1408H, 0x00005012U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[0]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[1]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[2]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[3]);
                r_rsip_func102(bswap_32big(0x9a21d51fU),
                               bswap_32big(0x31d66e73U),
                               bswap_32big(0xb6e19798U),
                               bswap_32big(0xc767203cU));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
