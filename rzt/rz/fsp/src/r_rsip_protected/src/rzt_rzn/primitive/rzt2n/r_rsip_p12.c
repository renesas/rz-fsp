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

rsip_ret_t r_rsip_p12 (const uint32_t InData_KeyIndex[],
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

    WR1_PROG(REG_1B00H, 0x00120002U);
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
    r_rsip_subfunc009(bswap_32big(0x00000012U));
    r_rsip_func101(bswap_32big(0x6e3dc01eU),
                   bswap_32big(0xce9d718fU),
                   bswap_32big(0x96bbe5faU),
                   bswap_32big(0x0eb1113dU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0103c0b8U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00000012U));
    r_rsip_func101(bswap_32big(0x02da0ab0U),
                   bswap_32big(0xa12d342dU),
                   bswap_32big(0x4c64243aU),
                   bswap_32big(0x0a955c12U));
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
    r_rsip_func100(bswap_32big(0x5e73a0c0U),
                   bswap_32big(0x89091452U),
                   bswap_32big(0xd7ce26adU),
                   bswap_32big(0xcb9f6d5fU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x3e226ba1U), bswap_32big(0x60655fe0U), bswap_32big(0x5a280395U),
                       bswap_32big(0x2cf01c0cU));
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

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x80010360U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000012U));
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1000H, 0x00010000U);
        WR1_PROG(REG_1024H, 0x000007f0U);
        r_rsip_subfunc009(bswap_32big(0x00000012U));
        r_rsip_func101(bswap_32big(0x8a1a898bU), bswap_32big(0x3dce5429U), bswap_32big(0x8371009fU),
                       bswap_32big(0xf5089b3dU));
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
        r_rsip_func100(bswap_32big(0xfe7e6c18U), bswap_32big(0xaf55edebU), bswap_32big(0x362612a1U),
                       bswap_32big(0x03df5637U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x6694071cU), bswap_32big(0xcffb9c86U), bswap_32big(0x3a6aca4aU),
                           bswap_32big(0x5e13d3f1U));
        }
        else
        {
            r_rsip_func100(bswap_32big(0x74b0439cU), bswap_32big(0x9377c836U), bswap_32big(0x03e6a9a2U),
                           bswap_32big(0x02fbc232U));
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
            r_rsip_subfunc009(bswap_32big(0x00000012U));
            r_rsip_func101(bswap_32big(0x12ea31a4U), bswap_32big(0x6be181a0U), bswap_32big(0x5d7d5596U),
                           bswap_32big(0x9e1bfc33U));
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
            r_rsip_func100(bswap_32big(0x08b535d1U), bswap_32big(0x091079fcU), bswap_32big(0x321c6787U),
                           bswap_32big(0xae866206U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                WR1_PROG(REG_1018H, 0x00000a70U);
                r_rsip_subfunc002(0x00000070U, 0x00000c50U, 0x09090013U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                r_rsip_func101(bswap_32big(0xe6e4e06aU),
                               bswap_32big(0x50fbada9U),
                               bswap_32big(0xe7829893U),
                               bswap_32big(0x935e2825U));
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                r_rsip_subfunc002(0x000002f0U, 0x00000c50U, 0x09090014U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                r_rsip_func101(bswap_32big(0xa744da8fU),
                               bswap_32big(0xc34b506cU),
                               bswap_32big(0x2b75a85aU),
                               bswap_32big(0x2436e051U));
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
                    r_rsip_func100(bswap_32big(0xbe5c941eU),
                                   bswap_32big(0x59a9fef1U),
                                   bswap_32big(0x79de4304U),
                                   bswap_32big(0x8cd56725U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        WR1_PROG(REG_1014H, 0x00000250U);
                        r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x09090014U);
                        WR1_PROG(REG_143CH, 0x00000d00U);
                        r_rsip_func101(bswap_32big(0xf21dd9abU),
                                       bswap_32big(0xb3390b30U),
                                       bswap_32big(0x5eaf274eU),
                                       bswap_32big(0x9c0ec4adU));
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0x4886160cU),
                                       bswap_32big(0x1fa1480cU),
                                       bswap_32big(0x2e552647U),
                                       bswap_32big(0x7153ad70U));
                    }

                    WR1_PROG(REG_1600H, 0x38000ca5U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00A60000U);
                    r_rsip_func100(bswap_32big(0x6ca4e697U),
                                   bswap_32big(0xff8c8bddU),
                                   bswap_32big(0xdf46634dU),
                                   bswap_32big(0x25ae1a34U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_func100(bswap_32big(0x7155d876U),
                                       bswap_32big(0x7f0ae124U),
                                       bswap_32big(0xdd494f0cU),
                                       bswap_32big(0xb601ffc1U));
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
                            r_rsip_func101(bswap_32big(0x7c7b2c0cU),
                                           bswap_32big(0x4860af96U),
                                           bswap_32big(0x0947ed72U),
                                           bswap_32big(0x664e7b25U));
                        }
                        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
                        {
                            r_rsip_subfunc001(0x00000ac0U, 0x00000160U, 0x000003e0U, 0x09090009U);
                            r_rsip_subfunc001(0x00000b10U, 0x00000160U, 0x00000430U, 0x09090009U);
                            r_rsip_subfunc001(0x00000b60U, 0x00000160U, 0x00000480U, 0x09090009U);
                            r_rsip_func101(bswap_32big(0xcaa338d5U),
                                           bswap_32big(0x9847995bU),
                                           bswap_32big(0x6eee2150U),
                                           bswap_32big(0xd1b765b0U));
                        }
                        else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
                        {
                            r_rsip_subfunc001(0x00000bb0U, 0x00000160U, 0x000003e0U, 0x09090009U);
                            r_rsip_subfunc001(0x00000c00U, 0x00000160U, 0x00000430U, 0x09090009U);
                            r_rsip_subfunc001(0x00000c50U, 0x00000160U, 0x00000480U, 0x09090009U);
                            r_rsip_func101(bswap_32big(0x1529dc3fU),
                                           bswap_32big(0x3795490fU),
                                           bswap_32big(0xed6851d3U),
                                           bswap_32big(0x2399608cU));
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
                        r_rsip_func100(bswap_32big(0x6449f5b4U),
                                       bswap_32big(0x4a3caf7aU),
                                       bswap_32big(0xf914e19fU),
                                       bswap_32big(0xb6f7b5d9U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            r_rsip_subfunc001(0x000003e0U, 0x00000160U, 0x00000110U, 0x0909000aU);
                            WR1_PROG(REG_143CH, 0x00a10000U);
                            r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000110U, 0x0909000aU);
                            WR1_PROG(REG_143CH, 0x00a10000U);
                            r_rsip_func100(bswap_32big(0x810e1222U),
                                           bswap_32big(0xc4147bdeU),
                                           bswap_32big(0x020ea427U),
                                           bswap_32big(0xc2fdc311U));
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
                                r_rsip_func100(bswap_32big(0xacaf1c00U), bswap_32big(0x5ad2b358U),
                                               bswap_32big(0x87a8c6d3U), bswap_32big(0x1ca64666U));
                                WR1_PROG(REG_143CH, 0x00400000U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                if (CHCK_STS(REG_143CH, 22U, 1U))
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    WR1_PROG(REG_1018H, 0x00000480U);
                                    r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x09090013U);
                                    WR1_PROG(REG_143CH, 0x00000d00U);
                                    r_rsip_func101(bswap_32big(0x8758a034U), bswap_32big(0x4902bca7U),
                                                   bswap_32big(0xd491acd2U), bswap_32big(0xf05a2ff1U));
                                }
                                else
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x09090014U);
                                    WR1_PROG(REG_143CH, 0x00000d00U);
                                    r_rsip_func101(bswap_32big(0xa91af5afU), bswap_32big(0x8dd8dd77U),
                                                   bswap_32big(0xe28a9703U), bswap_32big(0x9e54d1e6U));
                                }
                            }
                            else
                            {
                                r_rsip_func101(bswap_32big(0xae656575U), bswap_32big(0xe63066a3U),
                                               bswap_32big(0x77754735U), bswap_32big(0x96331557U));
                            }
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x11180000U);
                            r_rsip_subfunc003(0x00c00049U);
                            r_rsip_subfunc001(0x000003e0U, 0x00000160U, 0x000001b0U, 0x09090009U);
                            r_rsip_subfunc001(0x00000430U, 0x00000160U, 0x00000200U, 0x09090009U);
                            r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000250U, 0x09090009U);
                            r_rsip_func101(bswap_32big(0xa688a987U),
                                           bswap_32big(0x6e6ba0fdU),
                                           bswap_32big(0xab93bb4fU),
                                           bswap_32big(0x2e15cc47U));
                        }
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0x82fd2561U),
                                       bswap_32big(0x68f6b807U),
                                       bswap_32big(0xff9499a4U),
                                       bswap_32big(0x9c7de2a9U));
                    }

                    WR1_PROG(REG_1600H, 0x00002c40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x658913e9U),
                                   bswap_32big(0x3364eb5cU),
                                   bswap_32big(0x00569fadU),
                                   bswap_32big(0xcc2be2b6U));
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
                r_rsip_func101(bswap_32big(0xd8cc14c4U),
                               bswap_32big(0xd0839db4U),
                               bswap_32big(0x640ef918U),
                               bswap_32big(0x02175694U));
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
            r_rsip_func100(bswap_32big(0xa91bcecdU), bswap_32big(0x5171d324U), bswap_32big(0x9863f886U),
                           bswap_32big(0xd16a3aaeU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x7d57add3U),
                               bswap_32big(0x9b9076b2U),
                               bswap_32big(0x05754f64U),
                               bswap_32big(0x9f6a2292U));
            }
            else
            {
                r_rsip_func100(bswap_32big(0x4f089d68U),
                               bswap_32big(0xe4918234U),
                               bswap_32big(0xec8da7d9U),
                               bswap_32big(0x85aaebcfU));
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
                r_rsip_func100(bswap_32big(0xc85246f1U),
                               bswap_32big(0x9bb0cf20U),
                               bswap_32big(0xb5193e03U),
                               bswap_32big(0x5539036dU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xe554614bU),
                                   bswap_32big(0x956c00bcU),
                                   bswap_32big(0x03dc9063U),
                                   bswap_32big(0xb2b2f740U));
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x19bac63dU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xe97628b7U),
                                   bswap_32big(0xfbf2e973U),
                                   bswap_32big(0x8a85ced8U),
                                   bswap_32big(0x71015681U));
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
        r_rsip_func100(bswap_32big(0x0d85e815U), bswap_32big(0x455dcb82U), bswap_32big(0x807e0ec3U),
                       bswap_32big(0x4c8e4967U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xc52e2dd5U), bswap_32big(0xf9ead266U), bswap_32big(0xfbf83a98U),
                           bswap_32big(0x691db6eaU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func102(bswap_32big(0x0e7c7305U), bswap_32big(0x85f9c855U), bswap_32big(0xa3afaea9U),
                           bswap_32big(0xf1975a11U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
