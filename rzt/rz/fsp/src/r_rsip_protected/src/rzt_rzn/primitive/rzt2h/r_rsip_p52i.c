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

rsip_ret_t r_rsip_p52i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_MsgDgst[],
                        const uint32_t InData_Signature[],
                        const uint32_t InData_DomainParam[])
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

    WR1_PROG(REG_1B00H, 0x00520002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
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
    r_rsip_subfunc009(bswap_32big(0x00000052U));
    r_rsip_func101(bswap_32big(0x57a774b0U),
                   bswap_32big(0x0db76302U),
                   bswap_32big(0xc3631d09U),
                   bswap_32big(0x979d9dc6U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0122f7d5U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00000052U));
    r_rsip_func101(bswap_32big(0x6b497e7bU),
                   bswap_32big(0x8ba7afb6U),
                   bswap_32big(0x787d6f5bU),
                   bswap_32big(0x743dd321U));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000044U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000023c2U);
    WR1_PROG(REG_1A2CH, 0x40000800U);
    WR1_PROG(REG_1A24H, 0xe8009107U);
    WR1_PROG(REG_1600H, 0x0000b420U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000060U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80a80001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = 0; iLoop < 20; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
        r_rsip_subfunc003(0x03420011U);
    }

    for (iLoop = 0; iLoop < 16; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 24]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 25]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 26]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 27]);
        r_rsip_subfunc003(0x03420011U);
    }

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x49108054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8008105U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[40]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[41]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[42]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[43]);
    r_rsip_subfunc003(0x03420011U);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[44]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[45]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[46]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[47]);
    r_rsip_func100(bswap_32big(0x99dc15ecU),
                   bswap_32big(0x769cc9f6U),
                   bswap_32big(0x719df810U),
                   bswap_32big(0xa11c7b94U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xb4992d0eU), bswap_32big(0xb7c0ee18U), bswap_32big(0x1f95c773U),
                       bswap_32big(0xd043de55U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000fc7U);
        WR1_PROG(REG_1600H, 0x00000bffU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x8090001fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
        {
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_MsgDgst[iLoop + 0]);
            WR1_PROG(REG_1458H, 0x00000000U);
        }

        WR1_PROG(REG_1600H, 0x00000bdeU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b7e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000100U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1A2CH, 0x00000300U);
        WR1_PROG(REG_1A24H, 0x08008107U);
        for (iLoop = 0; iLoop < 16; iLoop = iLoop + 4)
        {
            WR1_PROG(REG_1608H, 0x8184001eU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00890011U);
            WR1_PROG(REG_1608H, 0x8084001fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03420011U);
            WR1_PROG(REG_1600H, 0x0000a7c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000010U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000a7e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000010U);
            WR1_PROG(REG_1458H, 0x00000000U);
        }

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x80010360U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000052U));
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1000H, 0x00010000U);
        WR1_PROG(REG_1024H, 0x000007f0U);
        r_rsip_subfunc009(bswap_32big(0x00000052U));
        r_rsip_func101(bswap_32big(0x016ec728U), bswap_32big(0xbabeb3c2U), bswap_32big(0x2b5a65f8U),
                       bswap_32big(0xf1a9251dU));
        r_rsip_func074(InData_DomainParam);
        r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x09090010U);
        r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x09090010U);
        WR1_PROG(REG_1404H, 0x18e00000U);
        WR1_PROG(REG_1444H, 0x000027c2U);
        WR1_PROG(REG_1A2CH, 0x00000900U);
        WR1_PROG(REG_1A24H, 0x08008107U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Signature[0]);
        WR1_ADDR(REG_1420H, &InData_Signature[1]);
        WR1_ADDR(REG_1420H, &InData_Signature[2]);
        WR1_ADDR(REG_1420H, &InData_Signature[3]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Signature[4]);
        WR1_ADDR(REG_1420H, &InData_Signature[5]);
        WR1_ADDR(REG_1420H, &InData_Signature[6]);
        WR1_ADDR(REG_1420H, &InData_Signature[7]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Signature[8]);
        WR1_ADDR(REG_1420H, &InData_Signature[9]);
        WR1_ADDR(REG_1420H, &InData_Signature[10]);
        WR1_ADDR(REG_1420H, &InData_Signature[11]);
        r_rsip_subfunc003(0x00c20031U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Signature[12]);
        WR1_ADDR(REG_1420H, &InData_Signature[13]);
        WR1_ADDR(REG_1420H, &InData_Signature[14]);
        WR1_ADDR(REG_1420H, &InData_Signature[15]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Signature[16]);
        WR1_ADDR(REG_1420H, &InData_Signature[17]);
        WR1_ADDR(REG_1420H, &InData_Signature[18]);
        WR1_ADDR(REG_1420H, &InData_Signature[19]);
        r_rsip_subfunc003(0x00c20021U);
        WR1_PROG(REG_1404H, 0x19300000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Signature[20]);
        WR1_ADDR(REG_1420H, &InData_Signature[21]);
        WR1_ADDR(REG_1420H, &InData_Signature[22]);
        WR1_ADDR(REG_1420H, &InData_Signature[23]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Signature[24]);
        WR1_ADDR(REG_1420H, &InData_Signature[25]);
        WR1_ADDR(REG_1420H, &InData_Signature[26]);
        WR1_ADDR(REG_1420H, &InData_Signature[27]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Signature[28]);
        WR1_ADDR(REG_1420H, &InData_Signature[29]);
        WR1_ADDR(REG_1420H, &InData_Signature[30]);
        WR1_ADDR(REG_1420H, &InData_Signature[31]);
        r_rsip_subfunc003(0x00c20031U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Signature[32]);
        WR1_ADDR(REG_1420H, &InData_Signature[33]);
        WR1_ADDR(REG_1420H, &InData_Signature[34]);
        WR1_ADDR(REG_1420H, &InData_Signature[35]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Signature[36]);
        WR1_ADDR(REG_1420H, &InData_Signature[37]);
        WR1_ADDR(REG_1420H, &InData_Signature[38]);
        WR1_ADDR(REG_1420H, &InData_Signature[39]);
        r_rsip_subfunc003(0x00c20021U);
        WR1_PROG(REG_1404H, 0x11b80000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c00045U);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x000000c0U, 0x00000200U, 0x00000160U, 0x0909000aU);
        r_rsip_subfunc001(0x00000160U, 0x00000930U, 0x000001b0U, 0x0909000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000930U, 0x00000200U, 0x000001b0U, 0x0909000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000160U, 0x00000980U, 0x000001b0U, 0x0909000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000980U, 0x00000200U, 0x000001b0U, 0x0909000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x9f445d10U), bswap_32big(0x0c03b17eU), bswap_32big(0x10e1fbb3U),
                       bswap_32big(0x37085b01U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x40c02fd7U), bswap_32big(0x0d928bc5U), bswap_32big(0x87fdb314U),
                           bswap_32big(0xbde891feU));
        }
        else
        {
            r_rsip_func100(bswap_32big(0xbff6269bU), bswap_32big(0xa017eb6fU), bswap_32big(0x69b6df22U),
                           bswap_32big(0x97c7c8ecU));
            r_rsip_subfunc001(0x00000160U, 0x00000200U, 0x000001b0U, 0x0909000aU);
            WR1_PROG(REG_1014H, 0x00000980U);
            WR1_PROG(REG_1018H, 0x000001b0U);
            WR1_PROG(REG_101CH, 0x000000c0U);
            WR1_PROG(REG_1020H, 0x00000110U);
            WR1_PROG(REG_1010H, 0x00000020U);
            WR1_PROG(REG_1004H, 0x0909000fU);
            WR1_PROG(REG_1408H, 0x00020000U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000840U);
            r_rsip_subfunc002(0x000000c0U, 0x00000160U, 0x09090002U);
            WR1_PROG(REG_1404H, 0x10c00000U);
            r_rsip_subfunc003(0x00c00011U);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x8190001fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00c90041U);
            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000160U);
            r_rsip_subfunc002(0x000000c0U, 0x00000480U, 0x09090002U);
            WR1_PROG(REG_1014H, 0x00000930U);
            WR1_PROG(REG_1018H, 0x00000160U);
            r_rsip_subfunc002(0x000000c0U, 0x00000340U, 0x09090002U);
            WR1_PROG(REG_1010H, 0x00000018U);
            WR1_PROG(REG_1404H, 0x11180000U);
            r_rsip_subfunc003(0x00c00049U);
            WR1_PROG(REG_1404H, 0x19800000U);
            r_rsip_subfunc003(0x00c002d1U);
            WR1_PROG(REG_1014H, 0x00000390U);
            r_rsip_subfunc002(0x00000070U, 0x00000a70U, 0x09090004U);
            r_rsip_subfunc001(0x00000890U, 0x00000160U, 0x000002a0U, 0x09090009U);
            r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x000002f0U, 0x09090009U);
            WR1_PROG(REG_1404H, 0x10c00000U);
            WR1_PROG(REG_1608H, 0x81940001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00c90051U);
            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000390U);
            r_rsip_subfunc002(0x00000070U, 0x000009d0U, 0x09090002U);
            WR1_PROG(REG_1404H, 0x10c00000U);
            WR1_PROG(REG_1600H, 0x000037e1U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000a7e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000050U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x8194001fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00c90051U);
            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000390U);
            r_rsip_subfunc002(0x00000070U, 0x00000a20U, 0x09090002U);
            r_rsip_subfunc009(bswap_32big(0x00000052U));
            r_rsip_func101(bswap_32big(0x2649e80dU), bswap_32big(0xf7457b18U), bswap_32big(0x0c1b5517U),
                           bswap_32big(0x55fd2874U));
            r_rsip_func075(InData_DomainParam);
            r_rsip_subfunc001(0x000001b0U, 0x00000160U, 0x00000ac0U, 0x09090009U);
            r_rsip_subfunc001(0x00000200U, 0x00000160U, 0x00000b10U, 0x09090009U);
            r_rsip_subfunc001(0x00000a70U, 0x00000160U, 0x00000b60U, 0x09090009U);
            r_rsip_subfunc001(0x00000ac0U, 0x000009d0U, 0x00000110U, 0x0909000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x000009d0U, 0x00000ac0U, 0x00000110U, 0x0909000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000b10U, 0x00000a20U, 0x00000110U, 0x0909000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000a20U, 0x00000b10U, 0x00000110U, 0x0909000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x116c4b43U), bswap_32big(0x5e7d27efU), bswap_32big(0x504661baU),
                           bswap_32big(0x245a8f41U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                WR1_PROG(REG_1018H, 0x00000a70U);
                r_rsip_subfunc002(0x00000070U, 0x00000c50U, 0x09090013U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                r_rsip_func101(bswap_32big(0x67bdbdefU),
                               bswap_32big(0x7845d418U),
                               bswap_32big(0x3f177482U),
                               bswap_32big(0xc6f9a9eeU));
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                r_rsip_subfunc002(0x000002f0U, 0x00000c50U, 0x09090014U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                r_rsip_func101(bswap_32big(0xa8a03cd9U),
                               bswap_32big(0xf4a6dbd7U),
                               bswap_32big(0x22c1ade9U),
                               bswap_32big(0xa080fc04U));
            }

            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x14380000U);
            WR1_PROG(REG_1608H, 0x80920001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03430049U);
            WR1_PROG(REG_1600H, 0x0000a420U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000050U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x12f80000U);
            WR1_PROG(REG_1608H, 0x80920001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03430049U);
            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_subfunc003(0x00c000f1U);
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < 18; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_1600H, 0x000034a1U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00026ca5U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003865U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000a4a0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000050U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003885U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000842U);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (jLoop = 0; jLoop < 32; jLoop = jLoop + 1)
                {
                    WR1_PROG(REG_1600H, 0x000008a5U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x01816ca3U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x01816ca4U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00016c63U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00016c84U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1404H, 0x11180000U);
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x08000104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                    r_rsip_subfunc003(0x00c00045U);
                    r_rsip_subfunc003(0x00c20005U);
                    r_rsip_subfunc003(0x0002000dU);
                    r_rsip_subfunc001(0x000001b0U, 0x00000160U, 0x00000110U, 0x0909000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_subfunc001(0x00000250U, 0x00000160U, 0x00000110U, 0x0909000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_func100(bswap_32big(0x99d82608U),
                                   bswap_32big(0x3c1bc55eU),
                                   bswap_32big(0x51f61d07U),
                                   bswap_32big(0x37d6b06eU));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        WR1_PROG(REG_1014H, 0x00000250U);
                        r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x09090014U);
                        WR1_PROG(REG_143CH, 0x00000d00U);
                        r_rsip_func101(bswap_32big(0xc95aac6cU),
                                       bswap_32big(0xb050afffU),
                                       bswap_32big(0x34c1248cU),
                                       bswap_32big(0x6ec5b463U));
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0x853d5bf1U),
                                       bswap_32big(0x1917b52aU),
                                       bswap_32big(0xbd9d554cU),
                                       bswap_32big(0xcfce5520U));
                    }

                    WR1_PROG(REG_1600H, 0x38000ca5U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00A60000U);
                    r_rsip_func100(bswap_32big(0x404aa4e0U),
                                   bswap_32big(0x516fac23U),
                                   bswap_32big(0x8ea2450dU),
                                   bswap_32big(0x631096b2U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_func100(bswap_32big(0x7651a641U),
                                       bswap_32big(0xcc8fd553U),
                                       bswap_32big(0x516ab882U),
                                       bswap_32big(0xe00a7fe0U));
                        WR1_PROG(REG_1404H, 0x11180000U);
                        r_rsip_subfunc003(0x00c00049U);
                        WR1_PROG(REG_1600H, 0x00007c05U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_143CH, 0x00600000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
                        {
                            r_rsip_subfunc001(0x000009d0U, 0x00000160U, 0x000003e0U, 0x09090009U);
                            r_rsip_subfunc001(0x00000a20U, 0x00000160U, 0x00000430U, 0x09090009U);
                            r_rsip_subfunc001(0x00000a70U, 0x00000160U, 0x00000480U, 0x09090009U);
                            r_rsip_func101(bswap_32big(0x0b1c74b4U),
                                           bswap_32big(0xc517f463U),
                                           bswap_32big(0x0fe0a621U),
                                           bswap_32big(0x1cfcada6U));
                        }
                        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
                        {
                            r_rsip_subfunc001(0x00000ac0U, 0x00000160U, 0x000003e0U, 0x09090009U);
                            r_rsip_subfunc001(0x00000b10U, 0x00000160U, 0x00000430U, 0x09090009U);
                            r_rsip_subfunc001(0x00000b60U, 0x00000160U, 0x00000480U, 0x09090009U);
                            r_rsip_func101(bswap_32big(0xf349ffd9U),
                                           bswap_32big(0x46e8dcfcU),
                                           bswap_32big(0x5cdb2bd9U),
                                           bswap_32big(0xb983a277U));
                        }
                        else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
                        {
                            r_rsip_subfunc001(0x00000bb0U, 0x00000160U, 0x000003e0U, 0x09090009U);
                            r_rsip_subfunc001(0x00000c00U, 0x00000160U, 0x00000430U, 0x09090009U);
                            r_rsip_subfunc001(0x00000c50U, 0x00000160U, 0x00000480U, 0x09090009U);
                            r_rsip_func101(bswap_32big(0xd2cb115aU),
                                           bswap_32big(0xce08ad6bU),
                                           bswap_32big(0x52838e7bU),
                                           bswap_32big(0x2ce5cf54U));
                        }

                        WR1_PROG(REG_1404H, 0x11180000U);
                        WR1_PROG(REG_1444H, 0x000000a2U);
                        WR1_PROG(REG_1A24H, 0x08000104U);
                        WAIT_STS(REG_1444H, 31U, 1U);
                        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                        r_rsip_subfunc003(0x00c00045U);
                        r_rsip_subfunc003(0x00c20005U);
                        r_rsip_subfunc003(0x0002000dU);
                        r_rsip_subfunc001(0x000001b0U, 0x00000160U, 0x00000110U, 0x0909000aU);
                        WR1_PROG(REG_143CH, 0x00a10000U);
                        r_rsip_subfunc001(0x00000250U, 0x00000160U, 0x00000110U, 0x0909000aU);
                        WR1_PROG(REG_143CH, 0x00a10000U);
                        r_rsip_func100(bswap_32big(0x06ff46bcU),
                                       bswap_32big(0xba14be86U),
                                       bswap_32big(0x2d9a8fb9U),
                                       bswap_32big(0x96598b07U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            r_rsip_subfunc001(0x000003e0U, 0x00000160U, 0x00000110U, 0x0909000aU);
                            WR1_PROG(REG_143CH, 0x00a10000U);
                            r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000110U, 0x0909000aU);
                            WR1_PROG(REG_143CH, 0x00a10000U);
                            r_rsip_func100(bswap_32big(0xd1c0edd9U),
                                           bswap_32big(0xec268801U),
                                           bswap_32big(0x9ce0ebd6U),
                                           bswap_32big(0xc912a314U));
                            WR1_PROG(REG_143CH, 0x00400000U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            if (CHCK_STS(REG_143CH, 22U, 1U))
                            {
                                r_rsip_subfunc001(0x000001b0U, 0x000003e0U, 0x00000110U, 0x0909000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x000003e0U, 0x000001b0U, 0x00000110U, 0x0909000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x00000200U, 0x00000430U, 0x00000110U, 0x0909000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x00000430U, 0x00000200U, 0x00000110U, 0x0909000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x00000250U, 0x00000480U, 0x00000110U, 0x0909000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x00000480U, 0x00000250U, 0x00000110U, 0x0909000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_func100(bswap_32big(0xa4e9fb1cU), bswap_32big(0xf811b418U),
                                               bswap_32big(0x8573272aU), bswap_32big(0x5d6b30d9U));
                                WR1_PROG(REG_143CH, 0x00400000U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                if (CHCK_STS(REG_143CH, 22U, 1U))
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    WR1_PROG(REG_1018H, 0x00000480U);
                                    r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x09090013U);
                                    WR1_PROG(REG_143CH, 0x00000d00U);
                                    r_rsip_func101(bswap_32big(0x268ac080U), bswap_32big(0x7826289aU),
                                                   bswap_32big(0x557eca07U), bswap_32big(0x6a50f2bbU));
                                }
                                else
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x09090014U);
                                    WR1_PROG(REG_143CH, 0x00000d00U);
                                    r_rsip_func101(bswap_32big(0x27f72259U), bswap_32big(0xcc3fd6dbU),
                                                   bswap_32big(0x212c1e58U), bswap_32big(0xbdaa4720U));
                                }
                            }
                            else
                            {
                                r_rsip_func101(bswap_32big(0x502133ecU), bswap_32big(0x6914b241U),
                                               bswap_32big(0xca5cb4d5U), bswap_32big(0xb9b087c6U));
                            }
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x11180000U);
                            r_rsip_subfunc003(0x00c00049U);
                            r_rsip_subfunc001(0x000003e0U, 0x00000160U, 0x000001b0U, 0x09090009U);
                            r_rsip_subfunc001(0x00000430U, 0x00000160U, 0x00000200U, 0x09090009U);
                            r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000250U, 0x09090009U);
                            r_rsip_func101(bswap_32big(0xf5bb0bbbU),
                                           bswap_32big(0x1b563b9dU),
                                           bswap_32big(0xc16b4749U),
                                           bswap_32big(0x09640f3aU));
                        }
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0xd99e77c1U),
                                       bswap_32big(0x0990fe54U),
                                       bswap_32big(0x236e39eeU),
                                       bswap_32big(0x4c5f2694U));
                    }

                    WR1_PROG(REG_1600H, 0x00002c40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x2c9acc67U),
                                   bswap_32big(0xdfdaae77U),
                                   bswap_32big(0x4bceda4fU),
                                   bswap_32big(0x35d9ea41U));
                }

                WR1_PROG(REG_1600H, 0x38008840U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000020U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00002c20U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x9816c217U),
                               bswap_32big(0x904da50aU),
                               bswap_32big(0x2cceeab9U),
                               bswap_32big(0x20082fb8U));
            }

            WR1_PROG(REG_1600H, 0x38008820U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000012U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x12580000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c00045U);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x00000250U, 0x000002a0U, 0x000002f0U, 0x0909000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x8617eeb4U), bswap_32big(0x4794aadbU), bswap_32big(0x7b7957f2U),
                           bswap_32big(0x63c17a59U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x89b55cd6U),
                               bswap_32big(0x6140586eU),
                               bswap_32big(0x920d02dcU),
                               bswap_32big(0xf6ad2d46U));
            }
            else
            {
                r_rsip_func100(bswap_32big(0xa9dd93b7U),
                               bswap_32big(0x639982c1U),
                               bswap_32big(0x97a5368bU),
                               bswap_32big(0x506531e0U));
                WR1_PROG(REG_1014H, 0x00000250U);
                r_rsip_subfunc002(0x00000070U, 0x000002a0U, 0x09090004U);
                WR1_PROG(REG_1404H, 0x11180000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                r_rsip_subfunc003(0x00c00045U);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x00000110U, 0x0909000aU);
                r_rsip_subfunc005(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0909000fU, 0x00020000U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                WR1_PROG(REG_1014H, 0x000001b0U);
                WR1_PROG(REG_1018H, 0x00000160U);
                r_rsip_subfunc002(0x00000070U, 0x000002a0U, 0x09090002U);
                r_rsip_subfunc001(0x000002a0U, 0x00000930U, 0x000001b0U, 0x0909000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_subfunc001(0x00000930U, 0x000002a0U, 0x000001b0U, 0x0909000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_func100(bswap_32big(0xb2567a29U),
                               bswap_32big(0x8ad78480U),
                               bswap_32big(0xa32a1cbeU),
                               bswap_32big(0x0e63fb4fU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xc5114745U),
                                   bswap_32big(0xb99f7d42U),
                                   bswap_32big(0x8caf664bU),
                                   bswap_32big(0xd9ba5974U));
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x19bac63dU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xcc21d48fU),
                                   bswap_32big(0x2842e834U),
                                   bswap_32big(0xdd81a60cU),
                                   bswap_32big(0x005b0de1U));
                }
            }
        }

        WR1_PROG(REG_1600H, 0x38008800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x19bac63dU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);
        WR1_PROG(REG_1600H, 0x00007c1bU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0xdef550f5U), bswap_32big(0x5cea6041U), bswap_32big(0x34f25aa9U),
                       bswap_32big(0xba58549dU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x90c09250U), bswap_32big(0x9b45672cU), bswap_32big(0xf6f56772U),
                           bswap_32big(0xf80a766eU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1600H, 0x0000b7c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000100U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1A2CH, 0x00000300U);
            WR1_PROG(REG_1A24H, 0x08008107U);
            for (iLoop = 0; iLoop < 16; iLoop = iLoop + 4)
            {
                WR1_PROG(REG_1608H, 0x8184001eU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00890011U);
                WR1_PROG(REG_1608H, 0x8084001fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                WR1_PROG(REG_1600H, 0x0000a7c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000010U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000a7e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000010U);
                WR1_PROG(REG_1458H, 0x00000000U);
            }

            r_rsip_func101(bswap_32big(0x3cf76c4eU), bswap_32big(0x18fda92fU), bswap_32big(0x6ad5a328U),
                           bswap_32big(0xfc3a75a6U));

            return RSIP_RET_PASS;
        }
    }
}
