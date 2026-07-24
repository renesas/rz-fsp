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

rsip_ret_t r_rsip_pe0 (const uint32_t InData_Sel_KeyType[],
                       const uint32_t InData_RootCertificate[],
                       const uint32_t InData_RootCertificateInfo[],
                       const uint32_t InData_RootCertificatePubKey[],
                       uint32_t       OutData_KeyIndex[])
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

    WR1_PROG(REG_1B00H, 0x00e00002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x800101e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_Sel_KeyType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000bffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000defU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000d3e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x380089e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000d3e1U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000fffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    r_rsip_func100(bswap_32big(0xd05500f9U),
                   bswap_32big(0x3dafbc99U),
                   bswap_32big(0xa91fac1fU),
                   bswap_32big(0xb34e2f8aU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xe45e50a7U), bswap_32big(0x03332816U), bswap_32big(0xe8cc66d4U),
                       bswap_32big(0x2bf89bedU));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000003c7U);
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_RootCertificateInfo[0]);
        WR1_ADDR(REG_1420H, &InData_RootCertificateInfo[1]);
        WR1_ADDR(REG_1420H, &InData_RootCertificateInfo[2]);
        WR1_ADDR(REG_1420H, &InData_RootCertificateInfo[3]);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x0000e001U));
        r_rsip_func101(bswap_32big(0x2ecf2b2dU), bswap_32big(0x39e4aa6dU), bswap_32big(0x02c6b3b0U),
                       bswap_32big(0x1e2ce926U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01fee154U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x0000e001U));
        r_rsip_func101(bswap_32big(0x0957456eU), bswap_32big(0xad3cd1a0U), bswap_32big(0x030ca4cdU),
                       bswap_32big(0xd986684dU));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0xb9bcc58dU), bswap_32big(0xd47d7284U), bswap_32big(0xc75056edU),
                       bswap_32big(0xd327d5b0U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000044U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_RootCertificateInfo[4]);
        WR1_ADDR(REG_1420H, &InData_RootCertificateInfo[5]);
        WR1_ADDR(REG_1420H, &InData_RootCertificateInfo[6]);
        WR1_ADDR(REG_1420H, &InData_RootCertificateInfo[7]);
        WR1_PROG(REG_1608H, 0x800102c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420005U);
        r_rsip_subfunc003(0x0002000dU);
        WR1_PROG(REG_1444H, 0x000003c7U);
        WR1_PROG(REG_1608H, 0x800402e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_RootCertificatePubKey[0]);
        WR1_ADDR(REG_1420H, &InData_RootCertificatePubKey[1]);
        WR1_ADDR(REG_1420H, &InData_RootCertificatePubKey[2]);
        WR1_ADDR(REG_1420H, &InData_RootCertificatePubKey[3]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000bffU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00007c0fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x000000ffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b420U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000003U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x3c002b59U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x2000d3e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00002439U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x3c00283aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x2000d3e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b760U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000040U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x017ae4daU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x599d51faU), bswap_32big(0x262cbaddU), bswap_32big(0x9409f98bU),
                           bswap_32big(0x6fa7beddU));
        }
        else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000001fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b420U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000001fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x3c002b3aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x1000d3e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00002439U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0800283aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x2000d3e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b760U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000000cU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0175e269U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x757bd698U), bswap_32big(0xbbc8ac63U), bswap_32big(0x7abf5c9eU),
                           bswap_32big(0xa8bfa51fU));
        }

        WR1_PROG(REG_1600H, 0x3c002af8U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x1000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x3c002b19U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x1000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x3c002b56U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x1000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00002417U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x08002818U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000d3e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x38000fffU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);
        r_rsip_func100(bswap_32big(0xf99b4d91U), bswap_32big(0xed35ee61U), bswap_32big(0x4079600cU),
                       bswap_32big(0x0a965686U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x6548cc16U), bswap_32big(0x00dd140bU), bswap_32big(0x149106feU),
                           bswap_32big(0xb0f380deU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0xe9e3b7e3U), bswap_32big(0xe7b8161aU), bswap_32big(0xb5d6f8feU),
                           bswap_32big(0x8cefb03dU));
            WR1_PROG(REG_1600H, 0x00003417U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00046800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00026c00U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81010000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
            WR1_PROG(REG_1600H, 0x000008a5U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 4)
            {
                WR1_PROG(REG_1444H, 0x000003c2U);
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0xe8008005U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_RootCertificate[iLoop + 0]);
                WR1_ADDR(REG_1420H, &InData_RootCertificate[iLoop + 1]);
                WR1_ADDR(REG_1420H, &InData_RootCertificate[iLoop + 2]);
                WR1_ADDR(REG_1420H, &InData_RootCertificate[iLoop + 3]);
                WR1_PROG(REG_1600H, 0x0000a4a0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x145be541U),
                               bswap_32big(0x32a2b287U),
                               bswap_32big(0x2b8aea8fU),
                               bswap_32big(0x7034d0d0U));
            }

            r_rsip_func100(bswap_32big(0x64572daaU), bswap_32big(0x50233bc4U), bswap_32big(0x1484923eU),
                           bswap_32big(0x69ae9abeU));
            WR1_PROG(REG_1600H, 0x38000805U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1000H, 0x00010000U);
            WR1_PROG(REG_1404H, 0x10000000U);
            WR1_PROG(REG_1600H, 0x00003416U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000a400U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000000fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00046800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00026c00U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000a800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000004U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00003445U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00026c42U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x000008c6U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000a94U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81010000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
            r_rsip_subfunc009(bswap_32big(0x0000e001U));
            for ( ; iLoop < S_RAM[0]; iLoop = iLoop + 4)
            {
                WR1_PROG(REG_1444H, 0x000003c2U);
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0xe8008105U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_RootCertificate[iLoop + 0]);
                WR1_ADDR(REG_1420H, &InData_RootCertificate[iLoop + 1]);
                WR1_ADDR(REG_1420H, &InData_RootCertificate[iLoop + 2]);
                WR1_ADDR(REG_1420H, &InData_RootCertificate[iLoop + 3]);
                WR1_PROG(REG_1608H, 0x80840006U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                r_rsip_func101(bswap_32big(0x360d739cU),
                               bswap_32big(0x76d52d03U),
                               bswap_32big(0x9b50c461U),
                               bswap_32big(0xccdf21e3U));
                r_rsip_func091();
                WR1_PROG(REG_1600H, 0x000008c6U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000a4a0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x375cd543U),
                               bswap_32big(0x00a6bd42U),
                               bswap_32big(0x7ed105ffU),
                               bswap_32big(0x5e0e15d2U));
            }

            WR1_PROG(REG_1600H, 0x38000805U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x49108054U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8008105U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_RootCertificate[iLoop + 0]);
            WR1_ADDR(REG_1420H, &InData_RootCertificate[iLoop + 1]);
            WR1_ADDR(REG_1420H, &InData_RootCertificate[iLoop + 2]);
            WR1_ADDR(REG_1420H, &InData_RootCertificate[iLoop + 3]);
            WR1_PROG(REG_1608H, 0x80840006U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03420011U);
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A24H, 0x9c100005U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_RootCertificateInfo[8]);
            WR1_ADDR(REG_1420H, &InData_RootCertificateInfo[9]);
            WR1_ADDR(REG_1420H, &InData_RootCertificateInfo[10]);
            WR1_ADDR(REG_1420H, &InData_RootCertificateInfo[11]);
            r_rsip_func100(bswap_32big(0xbd2ac34fU), bswap_32big(0xa43d24b0U), bswap_32big(0xe77b0ccbU),
                           bswap_32big(0x871697c8U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x9ee9b5d3U),
                               bswap_32big(0x6add6b41U),
                               bswap_32big(0xf61f4b45U),
                               bswap_32big(0xcae7a414U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_subfunc009(bswap_32big(0x0000e002U));
                r_rsip_func101(bswap_32big(0x1d6fe695U),
                               bswap_32big(0x6097808cU),
                               bswap_32big(0xfae53edeU),
                               bswap_32big(0xde24fe2aU));
                r_rsip_func091();
                r_rsip_func100(bswap_32big(0xde004fecU),
                               bswap_32big(0x72f7f650U),
                               bswap_32big(0x54618303U),
                               bswap_32big(0x6930e6feU));
                r_rsip_func103();
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c200104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1608H, 0x80040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                r_rsip_subfunc009(bswap_32big(0x0000e002U));
                r_rsip_func101(bswap_32big(0x21abef14U),
                               bswap_32big(0xc69054e2U),
                               bswap_32big(0xd03a16a6U),
                               bswap_32big(0x2ed7f0b1U));
                r_rsip_func045();
                r_rsip_subfunc009(bswap_32big(0x0000e002U));
                r_rsip_func101(bswap_32big(0x952bedc1U),
                               bswap_32big(0x11db93b9U),
                               bswap_32big(0xda007300U),
                               bswap_32big(0x0d7b3aa7U));
                r_rsip_func046();
                r_rsip_func100(bswap_32big(0xb900a6c3U),
                               bswap_32big(0xefee833fU),
                               bswap_32big(0xa3cc0352U),
                               bswap_32big(0xb6291ccaU));
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000044U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000054U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1608H, 0x81010360U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1408H, 0x00005006U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
                WR1_PROG(REG_1600H, 0x00000884U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000008a5U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1404H, 0x10000000U);
                for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 4)
                {
                    WR1_PROG(REG_1600H, 0x342028bbU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x2000d080U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00007c04U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_143CH, 0x00602000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func100(bswap_32big(0xcad6d2d4U),
                                   bswap_32big(0x63b74497U),
                                   bswap_32big(0xa07cb65cU),
                                   bswap_32big(0x63d84bcaU));
                    WR1_PROG(REG_1A2CH, 0x40000000U);
                    WR1_PROG(REG_1A24H, 0xe8008105U);
                    r_rsip_subfunc003(0x00830011U);
                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 4]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 5]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 6]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 7]);
                    WR1_PROG(REG_1600H, 0x0000a4a0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000004U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x9009b485U),
                                   bswap_32big(0x70c744d1U),
                                   bswap_32big(0xa6b0c219U),
                                   bswap_32big(0x377fdc9cU));
                }

                r_rsip_func100(bswap_32big(0x00efa862U),
                               bswap_32big(0xa1094159U),
                               bswap_32big(0xe90e70f5U),
                               bswap_32big(0x47a0d749U));
                WR1_PROG(REG_1600H, 0x380008bbU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x49108054U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1600H, 0x00007c0fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_143CH, 0x00600000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
                {
                    r_rsip_func100(bswap_32big(0xea316f98U),
                                   bswap_32big(0x4a038609U),
                                   bswap_32big(0xbe162f40U),
                                   bswap_32big(0x2fde7c6eU));
                    WR1_PROG(REG_1A2CH, 0x40000000U);
                    WR1_PROG(REG_1A24H, 0xe8008104U);
                    WR1_PROG(REG_1608H, 0x81010280U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x00890005U);
                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 4]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 5]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 6]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 7]);
                    r_rsip_func101(bswap_32big(0x02ec8fc0U),
                                   bswap_32big(0x0d8d7cd4U),
                                   bswap_32big(0xd43fa14cU),
                                   bswap_32big(0xc42134d2U));
                }
                else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
                {
                    r_rsip_func100(bswap_32big(0xd5679f9fU),
                                   bswap_32big(0xe1e08898U),
                                   bswap_32big(0xfa86a024U),
                                   bswap_32big(0x8020cf8cU));
                    WR1_PROG(REG_1A2CH, 0x40000000U);
                    WR1_PROG(REG_1A24H, 0xe8008105U);
                    r_rsip_subfunc003(0x00830011U);
                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 4]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 5]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 6]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 7]);
                    r_rsip_func101(bswap_32big(0x91892dd9U),
                                   bswap_32big(0x9d71259fU),
                                   bswap_32big(0xe628a670U),
                                   bswap_32big(0x8bc009eaU));
                }

                r_rsip_func100(bswap_32big(0xb125dbadU),
                               bswap_32big(0x2d6c6cfcU),
                               bswap_32big(0x8bdf3227U),
                               bswap_32big(0x6ee8f8c9U));
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c100104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 8]);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 9]);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 10]);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 11]);
                r_rsip_func100(bswap_32big(0xbaa57821U),
                               bswap_32big(0x0ed349deU),
                               bswap_32big(0xd9fb22b7U),
                               bswap_32big(0xba8abb8fU));
                WR1_PROG(REG_1608H, 0x81040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1408H, 0x00005012U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[1]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[2]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[3]);
                r_rsip_func102(bswap_32big(0x76f84fc0U),
                               bswap_32big(0x92f7774cU),
                               bswap_32big(0x17042bc3U),
                               bswap_32big(0x4bb02685U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
