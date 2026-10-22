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

rsip_ret_t r_rsip_p7d (const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_Signature[])
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

    WR1_PROG(REG_1B00H, 0x007d0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    r_rsip_subfunc009(bswap_32big(0x0000007dU));
    r_rsip_func101(bswap_32big(0xd2cbab06U),
                   bswap_32big(0xaf2e417eU),
                   bswap_32big(0x94770127U),
                   bswap_32big(0xa6842374U));
    r_rsip_func078(InData_DomainParam);
    r_rsip_func100(bswap_32big(0x2dba402bU),
                   bswap_32big(0x231cc01fU),
                   bswap_32big(0xb255f95fU),
                   bswap_32big(0x23886981U));
    WR1_PROG(REG_1404H, 0x11200000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c0003dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x000000c0U, 0x00000160U, 0x000003f0U, 0x0808000aU);
    r_rsip_subfunc006(0x00000020U, 0x000003f0U, 0x08080010U);
    r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x08080010U);
    WR1_PROG(REG_1404H, 0x10d00000U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xd7b336dcU),
                   bswap_32big(0x4ea0fc53U),
                   bswap_32big(0x6cbd3eb4U),
                   bswap_32big(0x65836d47U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x03d8ca9fU),
                   bswap_32big(0xdacae8b7U),
                   bswap_32big(0xece2dd8cU),
                   bswap_32big(0xc4ee64dcU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x8b9cbec8U),
                   bswap_32big(0xe2b3cc45U),
                   bswap_32big(0xd1074262U),
                   bswap_32big(0x2f8ca666U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    WR1_PROG(REG_1014H, 0x00000110U);
    WR1_PROG(REG_101CH, 0x000003f0U);
    WR1_PROG(REG_1020H, 0x00000160U);
    WR1_PROG(REG_1010H, 0x00000020U);
    WR1_PROG(REG_1004H, 0x08080004U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0U, 0U);
    WR1_PROG(REG_1404H, 0x13f80000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0003dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000160U, 0x00000438U, 0x00000340U, 0x08080009U);
    r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x08080010U);
    r_rsip_subfunc009(bswap_32big(0x0000007dU));
    r_rsip_func101(bswap_32big(0x825462d9U),
                   bswap_32big(0x5b555773U),
                   bswap_32big(0xa1e09474U),
                   bswap_32big(0xd2428754U));
    r_rsip_func079(InData_DomainParam);
    r_rsip_subfunc009(bswap_32big(0x0000007dU));
    r_rsip_func101(bswap_32big(0x94614e40U),
                   bswap_32big(0x7cbbbddcU),
                   bswap_32big(0xbdd5bd82U),
                   bswap_32big(0xd9e93045U));
    r_rsip_func071();
    r_rsip_func100(bswap_32big(0x55e3c69dU),
                   bswap_32big(0x7ada1f0dU),
                   bswap_32big(0x71917a26U),
                   bswap_32big(0xbccc3f73U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x5e2a3ea3U), bswap_32big(0x88941213U), bswap_32big(0x2ecba34aU),
                       bswap_32big(0x903df761U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1014H, 0x000002a0U);
        WR1_PROG(REG_1018H, 0x00000840U);
        WR1_PROG(REG_101CH, 0x000000c0U);
        WR1_PROG(REG_1020H, 0x000002f0U);
        WR1_PROG(REG_1010H, 0x00000020U);
        WR1_PROG(REG_1004H, 0x08080002U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x000002f0U);
        r_rsip_subfunc002(0x000000c0U, 0x000002a0U, 0x08080004U);
        WR1_PROG(REG_1404H, 0x10d00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0003dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x000002a0U, 0x00000110U, 0x00000150U, 0x0808000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xe05f9de9U), bswap_32big(0x3e59ee0dU), bswap_32big(0xd619ccccU),
                       bswap_32big(0x696177d3U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xad8953c3U), bswap_32big(0xf652a083U), bswap_32big(0x53f8d22eU),
                           bswap_32big(0x6585a332U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0x7ebc6ba8U), bswap_32big(0x35ddf1feU), bswap_32big(0x68dcbca5U),
                           bswap_32big(0xd8e92ea2U));
            WR1_PROG(REG_1404H, 0x11200000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
            r_rsip_subfunc003(0x00c0003dU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x000000c0U, 0x00000160U, 0x00000110U, 0x0808000aU);
            r_rsip_subfunc005(0x00000340U, 0x00000110U, 0x000000c0U, 0x00000160U, 0x0808000fU, 0x00020000U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            WR1_PROG(REG_1014H, 0x00000160U);
            WR1_PROG(REG_1018H, 0x00000840U);
            r_rsip_subfunc002(0x000000c0U, 0x00000110U, 0x08080002U);
            WR1_PROG(REG_1444H, 0x00000fc2U);
            WR1_PROG(REG_1A2CH, 0x00000300U);
            WR1_PROG(REG_1A24H, 0x08008107U);
            WR1_PROG(REG_1404H, 0x11200000U);
            for (iLoop = 0; iLoop < 16; iLoop = iLoop + 4)
            {
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_MsgDgst[iLoop + 0]);
                WR1_ADDR(REG_1420H, &InData_MsgDgst[iLoop + 1]);
                WR1_ADDR(REG_1420H, &InData_MsgDgst[iLoop + 2]);
                WR1_ADDR(REG_1420H, &InData_MsgDgst[iLoop + 3]);
                r_rsip_subfunc003(0x00c20011U);
            }

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
            r_rsip_subfunc009(bswap_32big(0x0000007dU));
            r_rsip_func101(bswap_32big(0xf8acbf52U), bswap_32big(0xb12e5ed8U), bswap_32big(0x290595fbU),
                           bswap_32big(0x0d4f8b49U));
            r_rsip_func045();
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01e1bac4U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x0000007dU));
            r_rsip_func101(bswap_32big(0xe665d483U), bswap_32big(0xd1e62802U), bswap_32big(0x3492e419U),
                           bswap_32big(0x9a7825a4U));
            r_rsip_func046();
            WR1_PROG(REG_1444H, 0x00000fc2U);
            WR1_PROG(REG_1A2CH, 0x40000300U);
            WR1_PROG(REG_1A24H, 0xf7009d07U);
            WR1_PROG(REG_1404H, 0x11c00000U);
            for (iLoop = 0; iLoop < 16; iLoop = iLoop + 4)
            {
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
                WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
                WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
                WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
                r_rsip_subfunc003(0x00c20011U);
            }

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
            r_rsip_func100(bswap_32big(0xf83bb46bU), bswap_32big(0x95717d31U), bswap_32big(0xa9711fe7U),
                           bswap_32big(0x7caeeb90U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x1f876f11U),
                               bswap_32big(0xf2c1dad3U),
                               bswap_32big(0xc8d222bbU),
                               bswap_32big(0x7cbd06f7U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000200U);
                WR1_PROG(REG_1018H, 0x00000840U);
                r_rsip_subfunc002(0x000000c0U, 0x000001b0U, 0x08080002U);
                WR1_PROG(REG_1014H, 0x000001b0U);
                WR1_PROG(REG_1018H, 0x000002a0U);
                r_rsip_subfunc002(0x000000c0U, 0x00000200U, 0x08080002U);
                WR1_PROG(REG_1014H, 0x00000160U);
                WR1_PROG(REG_1018H, 0x00000200U);
                r_rsip_subfunc002(0x000000c0U, 0x000001b0U, 0x08080005U);
                WR1_PROG(REG_1014H, 0x00000110U);
                WR1_PROG(REG_1018H, 0x000001b0U);
                r_rsip_subfunc002(0x000000c0U, 0x00000200U, 0x08080002U);
                WR1_PROG(REG_1404H, 0x10d00000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                r_rsip_subfunc003(0x00c0003dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000200U, 0x00000110U, 0x00000150U, 0x0808000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_func100(bswap_32big(0x8672c6aeU),
                               bswap_32big(0x7ca7afb9U),
                               bswap_32big(0x1e84c783U),
                               bswap_32big(0x3c3a0581U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func102(bswap_32big(0x1746c887U),
                                   bswap_32big(0x9690380cU),
                                   bswap_32big(0x03ea0bfbU),
                                   bswap_32big(0xc1bca7c4U));
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    r_rsip_func100(bswap_32big(0x8704ba5eU),
                                   bswap_32big(0xc1bc7d0dU),
                                   bswap_32big(0x91055c8dU),
                                   bswap_32big(0x70511435U));
                    WR1_PROG(REG_1404H, 0x12600000U);
                    WR1_PROG(REG_1A2CH, 0x00000200U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_subfunc003(0x00830031U);
                    WR1_PROG(REG_1408H, 0x00002032U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[0]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[1]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[2]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[3]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[4]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[5]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[6]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[7]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[8]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[9]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[10]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[11]);
                    r_rsip_func100(bswap_32big(0x5646e649U),
                                   bswap_32big(0x60270ec5U),
                                   bswap_32big(0x7c867bcfU),
                                   bswap_32big(0x88cacf0bU));
                    WR1_PROG(REG_1A24H, 0x08000105U);
                    r_rsip_subfunc003(0x00830011U);
                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[12]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[13]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[14]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[15]);
                    r_rsip_func100(bswap_32big(0x2e241bceU),
                                   bswap_32big(0x553d44c4U),
                                   bswap_32big(0x9aaceb7bU),
                                   bswap_32big(0x7eeddc20U));
                    WR1_PROG(REG_1404H, 0x11c00000U);
                    WR1_PROG(REG_1A2CH, 0x00000200U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_subfunc003(0x00830031U);
                    WR1_PROG(REG_1408H, 0x00002032U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[16]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[17]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[18]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[19]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[20]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[21]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[22]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[23]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[24]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[25]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[26]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[27]);
                    r_rsip_func100(bswap_32big(0x34d8c9d2U),
                                   bswap_32big(0x6a17a0daU),
                                   bswap_32big(0xe696a6f8U),
                                   bswap_32big(0xbf87e3cfU));
                    WR1_PROG(REG_1A24H, 0x08000105U);
                    r_rsip_subfunc003(0x00830011U);
                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[28]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[29]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[30]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[31]);
                    r_rsip_func102(bswap_32big(0x21a1aadcU),
                                   bswap_32big(0xeed37b98U),
                                   bswap_32big(0x8de21dd6U),
                                   bswap_32big(0x91a709e2U));
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
