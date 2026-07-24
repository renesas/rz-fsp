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

rsip_ret_t r_rsip_pe8 (const uint32_t InData_SharedKeyNum[],
                       const uint32_t InData_SharedKeyIndex[],
                       const uint32_t InData_SessionKey[],
                       const uint32_t InData_IV[],
                       const uint32_t InData_InstData[],
                       const uint32_t InData_RootCertificateLength[],
                       uint32_t       OutData_RootCertificate[],
                       uint32_t       OutData_RootCertificateInfo[],
                       const uint32_t MAX_CNT)
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

    WR1_PROG(REG_1B00H, 0x00e80002U);
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
    r_rsip_func100(bswap_32big(0x5761e018U),
                   bswap_32big(0xedc389deU),
                   bswap_32big(0x2f996644U),
                   bswap_32big(0x9b657495U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xee73898fU), bswap_32big(0x572ed8dbU), bswap_32big(0x992347e5U),
                       bswap_32big(0x500c16bcU));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_subfunc009(bswap_32big(0x000000e8U));
        r_rsip_func101(bswap_32big(0x2b90b27dU), bswap_32big(0x4c929fa0U), bswap_32big(0x18e1b9b0U),
                       bswap_32big(0x10f5fd84U));
        r_rsip_func041();
        r_rsip_func100(bswap_32big(0x8ee5fe29U), bswap_32big(0xee6e35bbU), bswap_32big(0x65e82894U),
                       bswap_32big(0x5512bf37U));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0xf7001cb5U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[0]);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[1]);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[2]);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[3]);
        WAIT_STS(REG_1828H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000500U);
        r_rsip_func100(bswap_32big(0xabbb77daU), bswap_32big(0xdfd5bb6aU), bswap_32big(0x228ec0feU),
                       bswap_32big(0x35c69135U));
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
        r_rsip_func100(bswap_32big(0xd10665eaU), bswap_32big(0x05f00742U), bswap_32big(0x3bed586eU),
                       bswap_32big(0x803445b4U));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x0a03009dU);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_SessionKey[4]);
        WR1_ADDR(REG_1420H, &InData_SessionKey[5]);
        WR1_ADDR(REG_1420H, &InData_SessionKey[6]);
        WR1_ADDR(REG_1420H, &InData_SessionKey[7]);
        WAIT_STS(REG_1828H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000500U);
        r_rsip_func100(bswap_32big(0x7e1ca41fU), bswap_32big(0xfbc7d09fU), bswap_32big(0x9bc63892U),
                       bswap_32big(0x6cba0302U));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x08000045U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_IV[0]);
        WR1_ADDR(REG_1420H, &InData_IV[1]);
        WR1_ADDR(REG_1420H, &InData_IV[2]);
        WR1_ADDR(REG_1420H, &InData_IV[3]);
        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_1824H, 0x08000054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        r_rsip_subfunc009(bswap_32big(0x000000e8U));
        r_rsip_func101(bswap_32big(0xf120c7f4U), bswap_32big(0x86bd4fe4U), bswap_32big(0x12650d92U),
                       bswap_32big(0xd302b49dU));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0186360eU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x000000e8U));
        r_rsip_func101(bswap_32big(0xa7260767U), bswap_32big(0x9c27c590U), bswap_32big(0x494bb5c0U),
                       bswap_32big(0xe30cc698U));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0x54c5aa51U), bswap_32big(0x2c35a577U), bswap_32big(0x36b07ca9U),
                       bswap_32big(0x0e3c4fedU));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000044U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x800100c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_RootCertificateLength[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008104U);
        WR1_PROG(REG_1608H, 0x810100c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00890005U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_RootCertificateInfo[4]);
        RD1_ADDR(REG_1420H, &OutData_RootCertificateInfo[5]);
        RD1_ADDR(REG_1420H, &OutData_RootCertificateInfo[6]);
        RD1_ADDR(REG_1420H, &OutData_RootCertificateInfo[7]);
        r_rsip_func100(bswap_32big(0x7d3bfb47U), bswap_32big(0x65e63449U), bswap_32big(0x7663d4f6U),
                       bswap_32big(0xd3d7cbd2U));
        WR1_PROG(REG_1600H, 0x00000884U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000a4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000000fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x000468c6U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00026cc6U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x000028c5U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x810100c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1408H, 0x00005006U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
        for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 4)
        {
            r_rsip_func100(bswap_32big(0x406eee59U), bswap_32big(0xe94a89f0U), bswap_32big(0x26f652e4U),
                           bswap_32big(0xee6732e6U));
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0xd900090dU);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 0]);
            WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 1]);
            WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 2]);
            WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 3]);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8008105U);
            r_rsip_subfunc003(0x00810011U);
            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_RootCertificate[iLoop]);
            RD1_ADDR(REG_1420H, &OutData_RootCertificate[iLoop + 1]);
            RD1_ADDR(REG_1420H, &OutData_RootCertificate[iLoop + 2]);
            RD1_ADDR(REG_1420H, &OutData_RootCertificate[iLoop + 3]);
            WR1_PROG(REG_1600H, 0x00002485U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x24603af8U), bswap_32big(0x0b7a58ccU), bswap_32big(0xb434e552U),
                           bswap_32big(0xbfbe24bbU));
        }

        WR1_PROG(REG_1600H, 0x38000886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0xe76f705dU), bswap_32big(0xf7a99ea5U), bswap_32big(0xa4cef95fU),
                       bswap_32big(0x57576ebaU));
        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_1824H, 0x49110054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x49108054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0xd900090dU);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_InstData[MAX_CNT - 8]);
        WR1_ADDR(REG_1420H, &InData_InstData[MAX_CNT - 7]);
        WR1_ADDR(REG_1420H, &InData_InstData[MAX_CNT - 6]);
        WR1_ADDR(REG_1420H, &InData_InstData[MAX_CNT - 5]);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_subfunc003(0x00810011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_RootCertificate[iLoop]);
        RD1_ADDR(REG_1420H, &OutData_RootCertificate[iLoop + 1]);
        RD1_ADDR(REG_1420H, &OutData_RootCertificate[iLoop + 2]);
        RD1_ADDR(REG_1420H, &OutData_RootCertificate[iLoop + 3]);
        r_rsip_func100(bswap_32big(0xa9fa5b4eU), bswap_32big(0x591e2dddU), bswap_32big(0x8ee79af2U),
                       bswap_32big(0xbf20c275U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c100104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_RootCertificateInfo[8]);
        RD1_ADDR(REG_1420H, &OutData_RootCertificateInfo[9]);
        RD1_ADDR(REG_1420H, &OutData_RootCertificateInfo[10]);
        RD1_ADDR(REG_1420H, &OutData_RootCertificateInfo[11]);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x9c100005U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_InstData[MAX_CNT - 4]);
        WR1_ADDR(REG_1420H, &InData_InstData[MAX_CNT - 3]);
        WR1_ADDR(REG_1420H, &InData_InstData[MAX_CNT - 2]);
        WR1_ADDR(REG_1420H, &InData_InstData[MAX_CNT - 1]);
        r_rsip_func100(bswap_32big(0xa6097543U), bswap_32big(0x3f9f8200U), bswap_32big(0x0e9bbb24U),
                       bswap_32big(0x6366b659U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x17d7ea3aU), bswap_32big(0x85df9dd6U), bswap_32big(0x44a21a59U),
                           bswap_32big(0x7c68ca57U));
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0xa62a4b8eU), bswap_32big(0x5e31c073U), bswap_32big(0xbd8bd9ebU),
                           bswap_32big(0x58e62af9U));
            WR1_PROG(REG_1608H, 0x81040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_RootCertificateInfo[0]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_RootCertificateInfo[1]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_RootCertificateInfo[2]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_RootCertificateInfo[3]);
            r_rsip_func102(bswap_32big(0x225150c9U), bswap_32big(0x99779a14U), bswap_32big(0x1e1571e7U),
                           bswap_32big(0x2df7c185U));
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
