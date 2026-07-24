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
    r_rsip_func100(bswap_32big(0x4dfd27d4U),
                   bswap_32big(0x68f70703U),
                   bswap_32big(0x91c2892bU),
                   bswap_32big(0x80ed6273U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xe7d603daU), bswap_32big(0xccabe707U), bswap_32big(0xf999e051U),
                       bswap_32big(0x7f3c1ef4U));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_subfunc009(bswap_32big(0x000000e8U));
        r_rsip_func101(bswap_32big(0x924e785eU), bswap_32big(0x3796bdcbU), bswap_32big(0x47aa1f3fU),
                       bswap_32big(0x9fb1e52fU));
        r_rsip_func041();
        r_rsip_func100(bswap_32big(0x48fdf700U), bswap_32big(0x23cbe350U), bswap_32big(0x1245b09cU),
                       bswap_32big(0x85133578U));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0xf7001cb5U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[0]);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[1]);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[2]);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[3]);
        WAIT_STS(REG_1828H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000500U);
        r_rsip_func100(bswap_32big(0xe7614a76U), bswap_32big(0x9fe0a775U), bswap_32big(0x3880508fU),
                       bswap_32big(0x87db0d58U));
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
        r_rsip_func100(bswap_32big(0xe78ab237U), bswap_32big(0x186f1455U), bswap_32big(0xc689f464U),
                       bswap_32big(0x8a471f5eU));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x0a03009dU);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_SessionKey[4]);
        WR1_ADDR(REG_1420H, &InData_SessionKey[5]);
        WR1_ADDR(REG_1420H, &InData_SessionKey[6]);
        WR1_ADDR(REG_1420H, &InData_SessionKey[7]);
        WAIT_STS(REG_1828H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000500U);
        r_rsip_func100(bswap_32big(0x318db1f8U), bswap_32big(0xb96122f7U), bswap_32big(0xa9b83385U),
                       bswap_32big(0x5413da2cU));
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
        r_rsip_func101(bswap_32big(0xa0487cf6U), bswap_32big(0x4e35c66aU), bswap_32big(0xdfdedeb8U),
                       bswap_32big(0x1f87eb9dU));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01fee154U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x000000e8U));
        r_rsip_func101(bswap_32big(0xd6205d91U), bswap_32big(0xac297b15U), bswap_32big(0x3c63070bU),
                       bswap_32big(0xca0f2eacU));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0xbc70d590U), bswap_32big(0x574bb4d9U), bswap_32big(0x0250d5a3U),
                       bswap_32big(0x36f3850bU));
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
        r_rsip_func100(bswap_32big(0x49e0d171U), bswap_32big(0x463fd91eU), bswap_32big(0x47cd371aU),
                       bswap_32big(0xe31f84ffU));
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
            r_rsip_func100(bswap_32big(0x94f34946U), bswap_32big(0x4116e730U), bswap_32big(0xc210dcf6U),
                           bswap_32big(0xf013d68bU));
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
            r_rsip_func101(bswap_32big(0x5c81de7cU), bswap_32big(0xc3e079b7U), bswap_32big(0xfef48119U),
                           bswap_32big(0xe17ef2c1U));
        }

        WR1_PROG(REG_1600H, 0x38000886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0x827f8f74U), bswap_32big(0xcb08c73fU), bswap_32big(0xb4e51c61U),
                       bswap_32big(0x29c06ea1U));
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
        r_rsip_func100(bswap_32big(0x886bf80eU), bswap_32big(0xb1ad78f6U), bswap_32big(0x9fa96e29U),
                       bswap_32big(0x3b485f63U));
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
        r_rsip_func100(bswap_32big(0xbe2839dbU), bswap_32big(0xef75a75cU), bswap_32big(0xd47bbc1fU),
                       bswap_32big(0x06259276U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xf9d7b8b6U), bswap_32big(0x73c7c94cU), bswap_32big(0xd15e92fdU),
                           bswap_32big(0x7ab8c9bdU));
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0xcdc9e831U), bswap_32big(0x9ecbff14U), bswap_32big(0xf07cb3eeU),
                           bswap_32big(0xddfdb632U));
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
            r_rsip_func102(bswap_32big(0x7adc4378U), bswap_32big(0xce4fe05dU), bswap_32big(0x9eb1039aU),
                           bswap_32big(0x53cb8fcaU));
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
