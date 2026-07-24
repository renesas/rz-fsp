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

rsip_ret_t r_rsip_pedf (const uint32_t InData_SignatureType[],
                        const uint32_t InData_HashType[],
                        const uint32_t InData_MsgDgst[],
                        const uint32_t InData_Salt[],
                        const uint32_t InData_SaltLength[],
                        uint32_t       OutData_EncCertificateInfo[])
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
    r_rsip_func100(bswap_32big(0x4d4af114U),
                   bswap_32big(0xf8e12c70U),
                   bswap_32big(0xd7649485U),
                   bswap_32big(0x5bda43ffU));
    WR1_PROG(REG_1444H, 0x000001c7U);
    WR1_PROG(REG_1608H, 0x80020080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_SignatureType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x3420a8a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000006U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x2000b4a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000005U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000034c5U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x380088c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x100008c6U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x380088c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000b4c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b420U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80b10000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x034000c5U);
    WR1_PROG(REG_1600H, 0x00007c06U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00600000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1600H, 0x0000b560U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000007U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b580U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x000000a4U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x8b74cb29U), bswap_32big(0x59d5a0f9U), bswap_32big(0xee83ef7fU),
                       bswap_32big(0x59ac9ff8U));
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1600H, 0x0000b560U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000008U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b580U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x000000a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xb6ec7658U), bswap_32big(0x4cec64afU), bswap_32big(0xdd432efcU),
                       bswap_32big(0x4bc98b9cU));
    }
    else if (0x00000004U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1600H, 0x0000b560U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000000cU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b580U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000090U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x1f60e303U), bswap_32big(0x73831300U), bswap_32big(0xd2082e38U),
                       bswap_32big(0x2b262864U));
    }
    else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1600H, 0x0000b560U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000010U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b580U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xa5295e15U), bswap_32big(0xedc2e457U), bswap_32big(0x400742eeU),
                       bswap_32big(0xe2fc641eU));
    }

    WR1_PROG(REG_1600H, 0x0000094aU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x27d11cffU),
                   bswap_32big(0x891f5e94U),
                   bswap_32big(0xce71399bU),
                   bswap_32big(0x656c5289U));
    WR1_PROG(REG_1608H, 0x81010160U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1408H, 0x00005006U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
    for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80810000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_MsgDgst[iLoop + 0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000a400U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00002d40U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x5896a2d0U), bswap_32big(0x8c649102U), bswap_32big(0x1d35c947U),
                       bswap_32big(0xc3eb21a5U));
    }

    WR1_PROG(REG_1600H, 0x3800094bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000c84U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    r_rsip_func100(bswap_32big(0xba52cd5fU),
                   bswap_32big(0x005b7e44U),
                   bswap_32big(0x729427caU),
                   bswap_32big(0x9f4d4d32U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1404H, 0x17f80000U);
        WR1_PROG(REG_1608H, 0x80900001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03430041U);
        WR1_PROG(REG_1600H, 0x00000842U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xc5928053U), bswap_32big(0xf7c77520U), bswap_32big(0x2411827eU),
                       bswap_32big(0x1b671f42U));
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x800100e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_SaltLength[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003527U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x000035abU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00026dadU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000252dU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000a520U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000002U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x3420a920U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000101U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);
        r_rsip_func100(bswap_32big(0x08ec37c8U), bswap_32big(0xb7cf7be0U), bswap_32big(0x5f67f29dU),
                       bswap_32big(0x542e10c5U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x64bcf58fU), bswap_32big(0x595d0d68U), bswap_32big(0x8b5a684cU),
                           bswap_32big(0x18ad94bbU));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0x942058baU), bswap_32big(0x0fc810d4U), bswap_32big(0xde66f0f0U),
                           bswap_32big(0x4f8b1bb6U));
            WR1_PROG(REG_1404H, 0x17f00000U);
            r_rsip_subfunc003(0x1003001dU);
            WR1_PROG(REG_1608H, 0x80900001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x13430101U);
            r_rsip_subfunc003(0x10030005U);
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000040U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_2000H, 0x00000001U);
            WR1_PROG(REG_1600H, 0x00007c05U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_143CH, 0x00600000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
            {
                WR1_PROG(REG_2004H, 0x00000040U);
                r_rsip_func101(bswap_32big(0x1f925789U),
                               bswap_32big(0xc2a1dd1bU),
                               bswap_32big(0xafcc9c9aU),
                               bswap_32big(0x753e043aU));
            }
            else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
            {
                WR1_PROG(REG_2004H, 0x00000050U);
                r_rsip_func101(bswap_32big(0xdb5a6f68U),
                               bswap_32big(0x8925f5d7U),
                               bswap_32big(0x9f4fc752U),
                               bswap_32big(0xa0a66175U));
            }
            else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
            {
                WR1_PROG(REG_2004H, 0x00000080U);
                r_rsip_func101(bswap_32big(0x27e8d684U),
                               bswap_32big(0x9fcab6aaU),
                               bswap_32big(0x722b9df1U),
                               bswap_32big(0x107974ffU));
            }
            else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
            {
                WR1_PROG(REG_2004H, 0x00000090U);
                r_rsip_func101(bswap_32big(0x011a35d9U),
                               bswap_32big(0x1e31026eU),
                               bswap_32big(0xe64151c2U),
                               bswap_32big(0x40e8b337U));
            }
            else if (0x00000004U == RD1_MASK(REG_1440H, 0xffffffffU))
            {
                WR1_PROG(REG_2004H, 0x000000a0U);
                r_rsip_func101(bswap_32big(0x3e7cce75U),
                               bswap_32big(0x7d020d86U),
                               bswap_32big(0x7792a594U),
                               bswap_32big(0xbce006beU));
            }
            else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
            {
                WR1_PROG(REG_2004H, 0x000000b0U);
                r_rsip_func101(bswap_32big(0x276ddb76U),
                               bswap_32big(0xd80c2011U),
                               bswap_32big(0xd3749925U),
                               bswap_32big(0x02de5ba8U));
            }

            r_rsip_func100(bswap_32big(0x6878604fU), bswap_32big(0x5c9992d5U), bswap_32big(0xd88ad257U),
                           bswap_32big(0x9570362eU));
            WR1_PROG(REG_1600H, 0x0000a520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000006U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000908U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01836d09U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00036d29U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81020100U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x0000500aU);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[1]);
            r_rsip_func100(bswap_32big(0x0643881fU), bswap_32big(0x6c52a4a9U), bswap_32big(0x11e7b4e7U),
                           bswap_32big(0xd3ef487fU));
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_ADDR(REG_2014H, &S_RAM[0]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_ADDR(REG_2010H, &S_RAM[1]);
            r_rsip_subfunc003(0x01400009U);
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000094aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81010160U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
            for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_1608H, 0x81810000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x01490005U);
                WR1_PROG(REG_1600H, 0x0000a400U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00002d40U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x3ddfc503U),
                               bswap_32big(0xd167a931U),
                               bswap_32big(0x87e4be75U),
                               bswap_32big(0xc676d8dcU));
            }

            r_rsip_func100(bswap_32big(0xc15191feU), bswap_32big(0xc8d47a76U), bswap_32big(0x89dce42fU),
                           bswap_32big(0x437d7236U));
            WR1_PROG(REG_1600H, 0x3800094bU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000a4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000003U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x000268e7U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000094aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x810100e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[1]);
            for (iLoop = 0; iLoop < S_RAM[0 + 1]; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_1444H, 0x000000c4U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_Salt[iLoop + 0]);
                WR1_PROG(REG_1600H, 0x00002d40U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x9ab03e1aU),
                               bswap_32big(0x93597e3bU),
                               bswap_32big(0x98e87ce5U),
                               bswap_32big(0xf6199327U));
            }

            WR1_PROG(REG_1600H, 0x38000947U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_2030H, 8U, 0U);
            WR1_PROG(REG_143CH, 0x00001600U);
            WAIT_STS(REG_2030H, 4U, 1U);
            WR1_PROG(REG_1600H, 0x0000094aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_1608H, 0x80810002U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03450005U);
                WR1_PROG(REG_1600H, 0x0000a440U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00002d40U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x9548abf7U),
                               bswap_32big(0xd483f7faU),
                               bswap_32big(0x5d1e5898U),
                               bswap_32big(0xbb2ba8bcU));
            }

            WR1_PROG(REG_1600H, 0x3800094bU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000040U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x16ebdc89U), bswap_32big(0x2332ff76U), bswap_32big(0x1b6b6d17U),
                           bswap_32big(0xa7fec3dcU));
        }
    }

    r_rsip_func100(bswap_32big(0x5dfd1d2cU),
                   bswap_32big(0x3c81e747U),
                   bswap_32big(0x20d3b586U),
                   bswap_32big(0x206d0b6aU));
    WR1_PROG(REG_1600H, 0x00002d60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0002696bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000094aU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000bffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x81010160U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1408H, 0x00005006U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
    for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_1824H, 0x08000045U);
        WR1_PROG(REG_1608H, 0x81840002U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00490011U);
        WR1_PROG(REG_1608H, 0x8184000cU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1824H, 0x9c000005U);
        r_rsip_subfunc003(0x00490011U);
        r_rsip_func100(bswap_32big(0x23509fd1U), bswap_32big(0xe0114959U), bswap_32big(0xd2639070U),
                       bswap_32big(0x1525bd3fU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x0000d3e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x6231ff03U), bswap_32big(0x3c64f27bU), bswap_32big(0x6b761c8fU),
                           bswap_32big(0x07ce27e0U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x04ab7e12U), bswap_32big(0x40222ea5U), bswap_32big(0xca94d289U),
                           bswap_32big(0xf0db5b6dU));
        }

        WR1_PROG(REG_1600H, 0x0000a440U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000010U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000a580U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000010U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00002d40U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x078378efU), bswap_32big(0x1861b5aeU), bswap_32big(0x611cf180U),
                       bswap_32big(0x96db03bfU));
    }

    WR1_PROG(REG_1600H, 0x3800094bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000fffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x5141068cU),
                   bswap_32big(0xba1add5cU),
                   bswap_32big(0x2ade453eU),
                   bswap_32big(0xdfa816dbU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x7b0fd6c8U), bswap_32big(0xaa58e26bU), bswap_32big(0xfb20f0a8U),
                       bswap_32big(0x1809dd57U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0xa809edcaU), bswap_32big(0x391807cdU), bswap_32big(0x11a6f128U),
                       bswap_32big(0x28279dcdU));
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        r_rsip_subfunc009(bswap_32big(0x0000ed02U));
        r_rsip_func101(bswap_32big(0x028ad097U), bswap_32big(0x93fa09dfU), bswap_32big(0x65d82b57U),
                       bswap_32big(0x43986674U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0133058dU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x0000ed02U));
        r_rsip_func101(bswap_32big(0x58f57588U), bswap_32big(0x63fbceb3U), bswap_32big(0xa6812022U),
                       bswap_32big(0x67123951U));
        r_rsip_func046();
        WR1_PROG(REG_1600H, 0x00000884U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0x7d5eff64U), bswap_32big(0x7703ecedU), bswap_32big(0xdba7cda7U),
                       bswap_32big(0x6c733b45U));
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xe7009d07U);
        WR1_PROG(REG_1608H, 0x81880004U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00890021U);
        WR1_PROG(REG_1408H, 0x00002022U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[4]);
        RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[5]);
        RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[6]);
        RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[7]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[8]);
        RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[9]);
        RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[10]);
        RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[11]);
        r_rsip_func100(bswap_32big(0x585d8177U), bswap_32big(0xd1f7b438U), bswap_32big(0xf9c11032U),
                       bswap_32big(0x0ca7e24fU));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_subfunc003(0x00820011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[12]);
        RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[13]);
        RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[14]);
        RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[15]);
        r_rsip_func100(bswap_32big(0x335a653cU), bswap_32big(0xcf984143U), bswap_32big(0x93f5d3ebU),
                       bswap_32big(0x77a0a41dU));
        WR1_PROG(REG_1608H, 0x81040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1408H, 0x00005012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[0]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[1]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[2]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[3]);
        r_rsip_func102(bswap_32big(0xd01e1cdfU), bswap_32big(0xc6eb2ad0U), bswap_32big(0xf34aa4cbU),
                       bswap_32big(0x68fbd8e8U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_PASS;
    }
}
