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
    r_rsip_func101(bswap_32big(0x3e99731eU),
                   bswap_32big(0x0e49a6dfU),
                   bswap_32big(0x565bc31dU),
                   bswap_32big(0xb4169943U));
    r_rsip_func078(InData_DomainParam);
    r_rsip_func100(bswap_32big(0x711d8e40U),
                   bswap_32big(0xd6ae7b07U),
                   bswap_32big(0xe7545e49U),
                   bswap_32big(0x279a6c07U));
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
    r_rsip_func100(bswap_32big(0x3d843ba7U),
                   bswap_32big(0xb578dc43U),
                   bswap_32big(0x6acef0d9U),
                   bswap_32big(0xa669933dU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x64838670U),
                   bswap_32big(0x369b841aU),
                   bswap_32big(0x48fb7325U),
                   bswap_32big(0x13ca2955U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x61ba04deU),
                   bswap_32big(0x7fa33cf9U),
                   bswap_32big(0xb51e6f64U),
                   bswap_32big(0x65fc7b0aU));
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
    r_rsip_func101(bswap_32big(0x559d7218U),
                   bswap_32big(0x18af0324U),
                   bswap_32big(0xb037b0f1U),
                   bswap_32big(0x51cbe4c5U));
    r_rsip_func079(InData_DomainParam);
    r_rsip_subfunc009(bswap_32big(0x0000007dU));
    r_rsip_func101(bswap_32big(0x45fe33daU),
                   bswap_32big(0x36767293U),
                   bswap_32big(0x27d2eabcU),
                   bswap_32big(0x374ba5d8U));
    r_rsip_func071();
    r_rsip_func100(bswap_32big(0xd02eeda9U),
                   bswap_32big(0x17d28133U),
                   bswap_32big(0x7ff4e1f4U),
                   bswap_32big(0xe5168d18U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xb125cb1cU), bswap_32big(0x413e9ef1U), bswap_32big(0xe59bd7d6U),
                       bswap_32big(0x08f04470U));
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
        r_rsip_func100(bswap_32big(0x2baf2e33U), bswap_32big(0x9a8b9bc3U), bswap_32big(0x6e582757U),
                       bswap_32big(0x22f001fcU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x60078277U), bswap_32big(0xe0ce863dU), bswap_32big(0x6327973dU),
                           bswap_32big(0x378c2766U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0x09f0b33dU), bswap_32big(0x9e969839U), bswap_32big(0x10376356U),
                           bswap_32big(0xfe96f56cU));
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
            r_rsip_func101(bswap_32big(0x6ebd2a6cU), bswap_32big(0x2003c6deU), bswap_32big(0x8319b49dU),
                           bswap_32big(0x1fae7ca2U));
            r_rsip_func045();
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01cc489dU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x0000007dU));
            r_rsip_func101(bswap_32big(0x48573afeU), bswap_32big(0x42c7a0bcU), bswap_32big(0x3bfbb95fU),
                           bswap_32big(0x8b196703U));
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
            r_rsip_func100(bswap_32big(0xc618daa3U), bswap_32big(0xb14c371cU), bswap_32big(0xe733af5bU),
                           bswap_32big(0xeef16b12U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x222d9365U),
                               bswap_32big(0xd4afbc86U),
                               bswap_32big(0x70f6bfbeU),
                               bswap_32big(0x7fcfd001U));
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
                r_rsip_func100(bswap_32big(0x588002fcU),
                               bswap_32big(0x61ccf57aU),
                               bswap_32big(0x4f23db7bU),
                               bswap_32big(0x77afa82bU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func102(bswap_32big(0xcdd8c718U),
                                   bswap_32big(0x8288b4feU),
                                   bswap_32big(0x616a56b3U),
                                   bswap_32big(0xb8f72dddU));
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    r_rsip_func100(bswap_32big(0x91393aafU),
                                   bswap_32big(0x56c5b2f7U),
                                   bswap_32big(0x4c0842e1U),
                                   bswap_32big(0x637c39f3U));
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
                    r_rsip_func100(bswap_32big(0x0eebeb99U),
                                   bswap_32big(0x6ab78edeU),
                                   bswap_32big(0xb3f0e2e1U),
                                   bswap_32big(0x26ecf3c7U));
                    WR1_PROG(REG_1A24H, 0x08000105U);
                    r_rsip_subfunc003(0x00830011U);
                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[12]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[13]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[14]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[15]);
                    r_rsip_func100(bswap_32big(0x73318beeU),
                                   bswap_32big(0x4a298d84U),
                                   bswap_32big(0xbfd0a08bU),
                                   bswap_32big(0x478cf9a7U));
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
                    r_rsip_func100(bswap_32big(0xc10595bfU),
                                   bswap_32big(0x5f73fe9aU),
                                   bswap_32big(0x86383ed0U),
                                   bswap_32big(0x909b979aU));
                    WR1_PROG(REG_1A24H, 0x08000105U);
                    r_rsip_subfunc003(0x00830011U);
                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[28]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[29]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[30]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[31]);
                    r_rsip_func102(bswap_32big(0xbc0ca537U),
                                   bswap_32big(0x37b0452eU),
                                   bswap_32big(0xb36b7184U),
                                   bswap_32big(0xd29fe8e1U));
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
