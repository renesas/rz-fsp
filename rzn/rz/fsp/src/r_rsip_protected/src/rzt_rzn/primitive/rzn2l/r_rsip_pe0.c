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
    r_rsip_func100(bswap_32big(0x34663681U),
                   bswap_32big(0x4611eec4U),
                   bswap_32big(0x4bd940deU),
                   bswap_32big(0xea0ba652U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xdc048deeU), bswap_32big(0xffb4357cU), bswap_32big(0x34c51b5dU),
                       bswap_32big(0x11ef1a82U));
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
        r_rsip_func101(bswap_32big(0x4492a547U), bswap_32big(0x6367a3e6U), bswap_32big(0xda753e82U),
                       bswap_32big(0x36a002b7U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0187c405U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x0000e001U));
        r_rsip_func101(bswap_32big(0x405b984eU), bswap_32big(0xc966cd4bU), bswap_32big(0xa6c477ceU),
                       bswap_32big(0x4d46e461U));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0x53dc1780U), bswap_32big(0xf1b65a59U), bswap_32big(0xea832379U),
                       bswap_32big(0xb862ddc2U));
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
            WR1_PROG(REG_1600H, 0x0185023cU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x7a0662eeU), bswap_32big(0x66e904ffU), bswap_32big(0xdd30273dU),
                           bswap_32big(0x4e9e62e1U));
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
            WR1_PROG(REG_1600H, 0x01d8c542U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x39974956U), bswap_32big(0x353eed56U), bswap_32big(0xba9c7c6dU),
                           bswap_32big(0xb798f339U));
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
        r_rsip_func100(bswap_32big(0x0db72198U), bswap_32big(0x484c19ceU), bswap_32big(0x46494d4bU),
                       bswap_32big(0x1c5d0d2aU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xe23d401cU), bswap_32big(0xc6332e58U), bswap_32big(0x20e787cfU),
                           bswap_32big(0xe3d41872U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0x207c47ddU), bswap_32big(0x362a61b7U), bswap_32big(0x982274e8U),
                           bswap_32big(0x698b331eU));
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
                r_rsip_func101(bswap_32big(0xb892f841U),
                               bswap_32big(0xad80ff70U),
                               bswap_32big(0x89b5483eU),
                               bswap_32big(0xd33eba97U));
            }

            r_rsip_func100(bswap_32big(0x03f20937U), bswap_32big(0xbea99df7U), bswap_32big(0x915b1bdeU),
                           bswap_32big(0xc8f77d34U));
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
                r_rsip_func101(bswap_32big(0xb95ee7a3U),
                               bswap_32big(0x54df29d3U),
                               bswap_32big(0xe1cb229fU),
                               bswap_32big(0x08bd66a7U));
                r_rsip_func091();
                WR1_PROG(REG_1600H, 0x000008c6U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000a4a0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xb57fdab7U),
                               bswap_32big(0x897261a0U),
                               bswap_32big(0x9c7788b7U),
                               bswap_32big(0x45c5367cU));
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
            r_rsip_func100(bswap_32big(0x45a742d5U), bswap_32big(0x4bedd659U), bswap_32big(0xc18d193eU),
                           bswap_32big(0x5cb7a877U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x553381b6U),
                               bswap_32big(0xd5ef6005U),
                               bswap_32big(0x71483d5dU),
                               bswap_32big(0xf31da330U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_subfunc009(bswap_32big(0x0000e002U));
                r_rsip_func101(bswap_32big(0xe311cf86U),
                               bswap_32big(0x89ee20a7U),
                               bswap_32big(0xe0080f66U),
                               bswap_32big(0x8411b77aU));
                r_rsip_func091();
                r_rsip_func100(bswap_32big(0x69576ab9U),
                               bswap_32big(0x9fd5631bU),
                               bswap_32big(0x41182abfU),
                               bswap_32big(0xfbe5da5fU));
                r_rsip_func103();
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c200104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1608H, 0x80040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                r_rsip_subfunc009(bswap_32big(0x0000e002U));
                r_rsip_func101(bswap_32big(0x82cbda54U),
                               bswap_32big(0xb812cac0U),
                               bswap_32big(0xf6151313U),
                               bswap_32big(0x8075f0c4U));
                r_rsip_func045();
                r_rsip_subfunc009(bswap_32big(0x0000e002U));
                r_rsip_func101(bswap_32big(0xc5b5485fU),
                               bswap_32big(0xfac694a5U),
                               bswap_32big(0x5c369a3fU),
                               bswap_32big(0xc73c97b2U));
                r_rsip_func046();
                r_rsip_func100(bswap_32big(0x253821ddU),
                               bswap_32big(0x86d79c9cU),
                               bswap_32big(0x9b0ee7afU),
                               bswap_32big(0x43905e16U));
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
                    r_rsip_func100(bswap_32big(0xb88dbf7bU),
                                   bswap_32big(0xd0aad186U),
                                   bswap_32big(0x8b539167U),
                                   bswap_32big(0xa2122977U));
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
                    r_rsip_func101(bswap_32big(0x113807f8U),
                                   bswap_32big(0x90f52605U),
                                   bswap_32big(0x767f8779U),
                                   bswap_32big(0xb822d566U));
                }

                r_rsip_func100(bswap_32big(0x2bfef6bbU),
                               bswap_32big(0x23378972U),
                               bswap_32big(0xd0c5dea5U),
                               bswap_32big(0xb79cbfeaU));
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
                    r_rsip_func100(bswap_32big(0x23933c9eU),
                                   bswap_32big(0x8ec509abU),
                                   bswap_32big(0xc691e995U),
                                   bswap_32big(0xc36ac535U));
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
                    r_rsip_func101(bswap_32big(0x1f3ce97eU),
                                   bswap_32big(0x78f058f0U),
                                   bswap_32big(0xf3e21fabU),
                                   bswap_32big(0x49351791U));
                }
                else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
                {
                    r_rsip_func100(bswap_32big(0x5d725550U),
                                   bswap_32big(0x2dd546e0U),
                                   bswap_32big(0xdf589360U),
                                   bswap_32big(0xe3259c42U));
                    WR1_PROG(REG_1A2CH, 0x40000000U);
                    WR1_PROG(REG_1A24H, 0xe8008105U);
                    r_rsip_subfunc003(0x00830011U);
                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 4]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 5]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 6]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 7]);
                    r_rsip_func101(bswap_32big(0x81786022U),
                                   bswap_32big(0x9e4a8934U),
                                   bswap_32big(0x898feed7U),
                                   bswap_32big(0x1b518755U));
                }

                r_rsip_func100(bswap_32big(0xb86f0125U),
                               bswap_32big(0x91ea64b6U),
                               bswap_32big(0x7e58c632U),
                               bswap_32big(0x538437e3U));
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
                r_rsip_func100(bswap_32big(0xf0884a9eU),
                               bswap_32big(0x50746dfbU),
                               bswap_32big(0xb3541986U),
                               bswap_32big(0xdb14c8edU));
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
                r_rsip_func102(bswap_32big(0x27dfcb86U),
                               bswap_32big(0x4eda818cU),
                               bswap_32big(0x202b2534U),
                               bswap_32big(0xcbcc0b3fU));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
