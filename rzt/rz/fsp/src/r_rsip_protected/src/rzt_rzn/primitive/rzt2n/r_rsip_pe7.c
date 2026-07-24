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

rsip_ret_t r_rsip_pe7 (const uint32_t InData_HashType[],
                       const uint32_t InData_KDFInfo[],
                       const uint32_t InData_KDFInfo_Count[],
                       const uint32_t InData_OutDataType[],
                       const uint32_t InData_OutDataLocation[],
                       const uint32_t InData_SeqNum[],
                       uint32_t       OutData_HMACKeyIndex[],
                       uint32_t       OutData_KeyIndex[],
                       uint32_t       OutData_EncIV[])
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

    WR1_PROG(REG_1B00H, 0x00e70002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000002c7U);
    WR1_PROG(REG_1608H, 0x80030080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KDFInfo_Count[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_OutDataType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x3000a880U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00010020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b480U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x30003080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00070020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b680U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x08000000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00030040U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b680U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x05555555U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00050040U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b680U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x04000000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x3000a8c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000009U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00010020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000008U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000ca5U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_1600H, 0x34202a85U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    r_rsip_func100(bswap_32big(0xc2a07021U),
                   bswap_32big(0xced02c79U),
                   bswap_32big(0x50591ae7U),
                   bswap_32big(0x0418c7f5U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x9041c290U), bswap_32big(0x7dfb99a0U), bswap_32big(0x1df2a3b6U),
                       bswap_32big(0x5f0c249fU));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0xb1199022U), bswap_32big(0xd19577bdU), bswap_32big(0xf0ff546bU),
                       bswap_32big(0xb3ecc4fdU));
        WR1_PROG(REG_1600H, 0x00007c06U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x016f646fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000000fU));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x53de4a48U), bswap_32big(0x026cb216U), bswap_32big(0xe854a74eU),
                           bswap_32big(0x9b6868dbU));
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01a9b3eaU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000001fU));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xe48c4252U), bswap_32big(0x88f0c7a3U), bswap_32big(0xb3f91117U),
                           bswap_32big(0x265bf7b6U));
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01beb3f5U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000000fU));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xcd2d7763U), bswap_32big(0x72568e74U), bswap_32big(0xb07a0dc8U),
                           bswap_32big(0x5ed298e1U));
        }
        else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01beb3f5U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000003U));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xd3246746U), bswap_32big(0xc6a30a60U), bswap_32big(0xbb98248cU),
                           bswap_32big(0xe4499fa3U));
        }
        else if (0x00000004U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01beb3f5U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000000bU));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x2ac8310fU), bswap_32big(0xc51546feU), bswap_32big(0x14bcad3fU),
                           bswap_32big(0xf51f3497U));
        }
        else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01db6812U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000013U));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xb2aedc5eU), bswap_32big(0x56033093U), bswap_32big(0xd3df1fd0U),
                           bswap_32big(0x65870f68U));
        }
        else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01394e42U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000001fU));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xe9cbf489U), bswap_32big(0xcf5afdf4U), bswap_32big(0xd7c7ba62U),
                           bswap_32big(0x4a588d8bU));
        }
        else if (0x00000007U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x014b49a1U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000002fU));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x018593e1U), bswap_32big(0x15ce0f44U), bswap_32big(0x384cac29U),
                           bswap_32big(0x7ba30dd4U));
        }
        else if (0x00000008U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01d9e28cU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000003fU));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x4d1651e7U), bswap_32big(0x4a8144bdU), bswap_32big(0x4c4b1d37U),
                           bswap_32big(0xa36b0db3U));
        }

        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80010100U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_OutDataLocation[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x30003080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00070020U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b600U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000001fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b700U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000010U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003685U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00056e94U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003280U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x30003080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00030020U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b600U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000002fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b700U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000014U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003685U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00046e94U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x000036a5U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00056eb4U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00002695U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003280U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x30003080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00050020U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b600U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000003fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b700U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000018U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003685U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00066e94U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003280U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003628U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000262eU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x34202a91U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_1600H, 0x34202911U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);
        r_rsip_func100(bswap_32big(0xa77a5d78U), bswap_32big(0x524d8cc4U), bswap_32big(0x1678ba63U),
                       bswap_32big(0xd2b98c07U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x820334b4U), bswap_32big(0x7b429a90U), bswap_32big(0x6133c51bU),
                           bswap_32big(0xc2a0956aU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0x669ed759U), bswap_32big(0x3f3893e9U), bswap_32big(0x55c8638dU),
                           bswap_32big(0x3b828ae9U));
            WR1_PROG(REG_1600H, 0x00000a73U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000ab5U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x000009efU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000a94U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000ad6U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000af7U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81010300U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
            OFS_ADR = S_RAM[0];
            r_rsip_func100(bswap_32big(0x25f854f4U), bswap_32big(0x8089f0fbU), bswap_32big(0x1f966d9aU),
                           bswap_32big(0x79ace61fU));
            WR1_PROG(REG_1608H, 0x810100a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
            for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_1600H, 0x34202a65U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x2000d2c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00007c16U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_143CH, 0x00602000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x34202a35U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_1600H, 0x000026b0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x34202aa8U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x100026f0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x10002ee0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                r_rsip_func100(bswap_32big(0x24f5b8eeU),
                               bswap_32big(0x1037928eU),
                               bswap_32big(0xa0c1838aU),
                               bswap_32big(0xca6f3d92U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func101(bswap_32big(0xa7bc7c1eU),
                                   bswap_32big(0xdaa97cf2U),
                                   bswap_32big(0xec074656U),
                                   bswap_32big(0xf4e4a6e8U));
                }
                else
                {
                    WR1_PROG(REG_1444H, 0x000003c7U);
                    WR1_PROG(REG_1608H, 0x80040000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * OFS_ADR + 0]);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * OFS_ADR + 1]);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * OFS_ADR + 2]);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_KDFInfo[iLoop * OFS_ADR + 3]);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc009(bswap_32big(0x0000e701U));
                    r_rsip_func101(bswap_32big(0x058d4902U),
                                   bswap_32big(0x1e53ae7cU),
                                   bswap_32big(0x18b66258U),
                                   bswap_32big(0xcee7e264U));
                    r_rsip_func045();
                    WR1_PROG(REG_1600H, 0x0000b4e0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x013f271aU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc009(bswap_32big(0x0000e701U));
                    r_rsip_func101(bswap_32big(0xb635b8d7U),
                                   bswap_32big(0xd34c6874U),
                                   bswap_32big(0xc4ea07efU),
                                   bswap_32big(0xb5c9b600U));
                    r_rsip_func046();
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x08000044U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x08000054U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                    WR1_PROG(REG_1600H, 0x00000842U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    for (jLoop = 0; jLoop < OFS_ADR - 8; jLoop = jLoop + 4)
                    {
                        WR1_PROG(REG_1444H, 0x000003c2U);
                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0xf7008d05U);
                        WAIT_STS(REG_1444H, 31U, 1U);
                        WR1_ADDR(REG_1420H, &InData_KDFInfo[jLoop + iLoop * OFS_ADR + 4]);
                        WR1_ADDR(REG_1420H, &InData_KDFInfo[jLoop + iLoop * OFS_ADR + 5]);
                        WR1_ADDR(REG_1420H, &InData_KDFInfo[jLoop + iLoop * OFS_ADR + 6]);
                        WR1_ADDR(REG_1420H, &InData_KDFInfo[jLoop + iLoop * OFS_ADR + 7]);
                        WR1_PROG(REG_1608H, 0x8084000fU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_subfunc003(0x03420011U);
                        WR1_PROG(REG_1600H, 0x0000a5e0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00000010U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x0000a440U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00000004U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_func101(bswap_32big(0x0f9822b8U),
                                       bswap_32big(0xf12b0352U),
                                       bswap_32big(0x0765bb4eU),
                                       bswap_32big(0xe12caf44U));
                    }

                    WR1_PROG(REG_1600H, 0x000037f8U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x0000abe0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000008U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x38000be2U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    WR1_PROG(REG_143CH, 0x00402000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1444H, 0x000003c2U);
                    WR1_PROG(REG_1A2CH, 0x40000000U);
                    WR1_PROG(REG_1A24H, 0x07008d05U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_KDFInfo[jLoop + iLoop * OFS_ADR + 4]);
                    WR1_ADDR(REG_1420H, &InData_KDFInfo[jLoop + iLoop * OFS_ADR + 5]);
                    WR1_ADDR(REG_1420H, &InData_KDFInfo[jLoop + iLoop * OFS_ADR + 6]);
                    WR1_ADDR(REG_1420H, &InData_KDFInfo[jLoop + iLoop * OFS_ADR + 7]);
                    WR1_PROG(REG_1A24H, 0x9c100005U);
                    r_rsip_subfunc003(0x00820011U);
                    r_rsip_func100(bswap_32big(0x7aaf5265U),
                                   bswap_32big(0xb123e27fU),
                                   bswap_32big(0x44d04678U),
                                   bswap_32big(0x5765df50U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        WR1_PROG(REG_1600H, 0x0000d280U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_func101(bswap_32big(0x21363fedU),
                                       bswap_32big(0x0637de00U),
                                       bswap_32big(0x87768af4U),
                                       bswap_32big(0xa0203cf9U));
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0xe4cd57f5U),
                                       bswap_32big(0x2728a48dU),
                                       bswap_32big(0xd22177d2U),
                                       bswap_32big(0x1ebb1cd5U));
                    }
                }

                WR1_PROG(REG_1600H, 0x00002ea0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00002e60U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x5df9cab6U),
                               bswap_32big(0xbb7dbfdeU),
                               bswap_32big(0xe6c30196U),
                               bswap_32big(0xd087aa85U));
            }

            WR1_PROG(REG_1600H, 0x38000a65U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x38000e94U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00A60000U);
            r_rsip_func100(bswap_32big(0xd1318841U), bswap_32big(0x506bb82dU), bswap_32big(0xd89b67fbU),
                           bswap_32big(0x0f6e4461U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x8fe2409aU),
                               bswap_32big(0xbaa91561U),
                               bswap_32big(0x4a497486U),
                               bswap_32big(0xf0ff89d7U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0x9b5a2490U),
                               bswap_32big(0x0cb2b708U),
                               bswap_32big(0x8c1a2175U),
                               bswap_32big(0x16bcc639U));
                r_rsip_func103();
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c200104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1608H, 0x80040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                r_rsip_subfunc009(bswap_32big(0x0000e702U));
                r_rsip_func101(bswap_32big(0x79b229fcU),
                               bswap_32big(0xc30a9ea6U),
                               bswap_32big(0x68ea1c08U),
                               bswap_32big(0x34c79289U));
                r_rsip_func045();
                WR1_PROG(REG_1600H, 0x000034e9U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc009(bswap_32big(0x0000e702U));
                r_rsip_func101(bswap_32big(0xab0afae5U),
                               bswap_32big(0xda4aa4e7U),
                               bswap_32big(0x54e88c25U),
                               bswap_32big(0x30e12d4dU));
                r_rsip_func046();
                WR1_PROG(REG_1600H, 0x00002917U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b5e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000080U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x3420a8c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000002U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                r_rsip_func100(bswap_32big(0xfb7b13a2U),
                               bswap_32big(0x7adb8819U),
                               bswap_32big(0x261b3b7bU),
                               bswap_32big(0xaeb3ef4dU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    for (iLoop = 0; iLoop < 32; iLoop = iLoop + 1)
                    {
                        WR1_PROG(REG_1600H, 0x00000ab5U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x02003aa8U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x02003eafU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00002d00U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00002de0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                    }

                    WR1_PROG(REG_1600H, 0x0000b5e0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000080U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x38000cc6U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    r_rsip_func100(bswap_32big(0x4b6f2953U),
                                   bswap_32big(0x167165b0U),
                                   bswap_32big(0xac0c6fccU),
                                   bswap_32big(0xfb269aa5U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_func100(bswap_32big(0x137b2221U),
                                       bswap_32big(0x80c0dd26U),
                                       bswap_32big(0xa7f983ffU),
                                       bswap_32big(0x5d3e8aaaU));
                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0xe7009d05U);
                        WR1_PROG(REG_1608H, 0x8184000fU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_subfunc003(0x00890011U);
                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[4]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[5]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[6]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[7]);
                        r_rsip_func100(bswap_32big(0x035736c1U),
                                       bswap_32big(0xa22c1ee9U),
                                       bswap_32big(0x3ccd2692U),
                                       bswap_32big(0xe570d8bbU));
                        WR1_PROG(REG_1444H, 0x000000a2U);
                        WR1_PROG(REG_1A24H, 0x0c000104U);
                        WAIT_STS(REG_1444H, 31U, 1U);
                        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0x09108105U);
                        r_rsip_subfunc003(0x00820011U);
                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[8]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[9]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[10]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[11]);
                        r_rsip_func101(bswap_32big(0x787e6e7aU),
                                       bswap_32big(0x191f6fa8U),
                                       bswap_32big(0x0bf65b4dU),
                                       bswap_32big(0xd3dda455U));
                    }
                    else
                    {
                        r_rsip_func100(bswap_32big(0x4cef3f91U),
                                       bswap_32big(0x998b7a85U),
                                       bswap_32big(0x532d3b6fU),
                                       bswap_32big(0xcd3e8006U));
                        WR1_PROG(REG_1A2CH, 0x40000100U);
                        WR1_PROG(REG_1A24H, 0xe7009d07U);
                        WR1_PROG(REG_1608H, 0x8188000fU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_subfunc003(0x00890021U);
                        WR1_PROG(REG_1408H, 0x00002022U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[4]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[5]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[6]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[7]);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[8]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[9]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[10]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[11]);
                        r_rsip_func100(bswap_32big(0xb1420910U),
                                       bswap_32big(0x2670b9d4U),
                                       bswap_32big(0xe6977457U),
                                       bswap_32big(0xf14b2f36U));
                        WR1_PROG(REG_1444H, 0x000000a2U);
                        WR1_PROG(REG_1A24H, 0x0c000104U);
                        WAIT_STS(REG_1444H, 31U, 1U);
                        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0x09108105U);
                        r_rsip_subfunc003(0x00820011U);
                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[12]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[13]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[14]);
                        RD1_ADDR(REG_1420H, &OutData_KeyIndex[15]);
                        r_rsip_func101(bswap_32big(0x77c006aaU),
                                       bswap_32big(0xd8d874f3U),
                                       bswap_32big(0x73447fa4U),
                                       bswap_32big(0x8ee2b154U));
                    }

                    r_rsip_func100(bswap_32big(0xb0adbdb9U),
                                   bswap_32big(0x4002c0a3U),
                                   bswap_32big(0xa32dabd6U),
                                   bswap_32big(0x55369c93U));
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
                    r_rsip_func102(bswap_32big(0xc07a3f7dU),
                                   bswap_32big(0xc3417548U),
                                   bswap_32big(0x23ba4ce7U),
                                   bswap_32big(0x7d1a4f3eU));
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_PASS;
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x3420a8c0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000005U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00A60000U);
                    r_rsip_func100(bswap_32big(0x5e4e67eeU),
                                   bswap_32big(0x3e94009eU),
                                   bswap_32big(0x08813ed3U),
                                   bswap_32big(0xb8b01887U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        for (iLoop = 0; iLoop < 64; iLoop = iLoop + 1)
                        {
                            WR1_PROG(REG_1600H, 0x00000ab5U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x02003aa8U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x02003eafU);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x00002d00U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x00002de0U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                        }

                        WR1_PROG(REG_1600H, 0x0000b5e0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00000080U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x380088c0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00000005U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1608H, 0x00000080U);
                        WR1_PROG(REG_143CH, 0x00260000U);
                        r_rsip_func100(bswap_32big(0x216abb99U),
                                       bswap_32big(0x90879512U),
                                       bswap_32big(0xe3c324b7U),
                                       bswap_32big(0x162e508aU));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            WR1_PROG(REG_1600H, 0x0000a5e0U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x00000014U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1608H, 0x8083000fU);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_subfunc003(0x0340000dU);
                            WR1_PROG(REG_1600H, 0x0000b5e0U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x00000080U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x0000b5c0U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x0000001fU);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_func101(bswap_32big(0x76f3de53U),
                                           bswap_32big(0x6c1ebd5bU),
                                           bswap_32big(0x9f94dfe6U),
                                           bswap_32big(0xb716032aU));
                        }
                        else
                        {
                            r_rsip_func101(bswap_32big(0xfd133116U),
                                           bswap_32big(0x182f46a9U),
                                           bswap_32big(0xfe4f4cc7U),
                                           bswap_32big(0x5cd920d3U));
                        }

                        WR1_PROG(REG_1600H, 0x000008e7U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_func100(bswap_32big(0x16384e44U),
                                       bswap_32big(0xca7f161eU),
                                       bswap_32big(0xfc60a715U),
                                       bswap_32big(0xadd4ba10U));
                        WR1_PROG(REG_1444H, 0x000000a2U);
                        WR1_PROG(REG_1A24H, 0x08000044U);
                        WAIT_STS(REG_1444H, 31U, 1U);
                        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                        WR1_PROG(REG_1444H, 0x000000a2U);
                        WR1_PROG(REG_1A24H, 0x08000054U);
                        WAIT_STS(REG_1444H, 31U, 1U);
                        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                        WR1_PROG(REG_1600H, 0x00002dc0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x000269ceU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1608H, 0x810101c0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1408H, 0x00005006U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
                        for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 4)
                        {
                            r_rsip_func100(bswap_32big(0x39526ec3U),
                                           bswap_32big(0x70ca04d2U),
                                           bswap_32big(0x4e3ff32cU),
                                           bswap_32big(0xb5e30872U));
                            WR1_PROG(REG_1A2CH, 0x40000000U);
                            WR1_PROG(REG_1A24H, 0xe7008d05U);
                            WR1_PROG(REG_1608H, 0x8184000fU);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_subfunc003(0x00890011U);
                            WR1_PROG(REG_1408H, 0x00002012U);
                            WAIT_STS(REG_1408H, 30U, 1U);
                            RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[iLoop + 4]);
                            RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[iLoop + 5]);
                            RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[iLoop + 6]);
                            RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[iLoop + 7]);
                            WR1_PROG(REG_1600H, 0x0000a5e0U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x00000010U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x0000a4e0U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x00000004U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_func101(bswap_32big(0xc581a629U),
                                           bswap_32big(0x7a8a99b6U),
                                           bswap_32big(0x00e59469U),
                                           bswap_32big(0x5b84b190U));
                        }

                        WR1_PROG(REG_1600H, 0x380009c7U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1608H, 0x00000080U);
                        WR1_PROG(REG_143CH, 0x00260000U);
                        WR1_PROG(REG_143CH, 0x00402000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_func100(bswap_32big(0xe292d403U),
                                       bswap_32big(0x453df0f9U),
                                       bswap_32big(0xba08c8d4U),
                                       bswap_32big(0x1d104d4dU));
                        WR1_PROG(REG_1444H, 0x000000a2U);
                        WR1_PROG(REG_1A24H, 0x0c000104U);
                        WAIT_STS(REG_1444H, 31U, 1U);
                        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0x09108105U);
                        r_rsip_subfunc003(0x00820011U);
                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[iLoop + 4]);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[iLoop + 5]);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[iLoop + 6]);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[iLoop + 7]);
                        r_rsip_func100(bswap_32big(0xc03358b6U),
                                       bswap_32big(0x9b29a87bU),
                                       bswap_32big(0x4c299d57U),
                                       bswap_32big(0xb0dcacd5U));
                        WR1_PROG(REG_1608H, 0x81040000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1408H, 0x00005012U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[0]);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[1]);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[2]);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[3]);
                        r_rsip_func102(bswap_32big(0xa760e2cfU),
                                       bswap_32big(0xca0d9373U),
                                       bswap_32big(0xe98f04d6U),
                                       bswap_32big(0x8d0bd1aaU));
                        WR1_PROG(REG_14B8H, 0x00000040U);
                        WAIT_STS(REG_142CH, 12U, 0U);

                        return RSIP_RET_PASS;
                    }
                    else
                    {
                        for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
                        {
                            WR1_PROG(REG_1600H, 0x00000ab5U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x02003aa8U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x02003eafU);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x00002d00U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x00002de0U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                        }

                        WR1_PROG(REG_1600H, 0x0000b5e0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00000080U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x380088c0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00000002U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1608H, 0x00000080U);
                        WR1_PROG(REG_143CH, 0x00260000U);
                        r_rsip_func100(bswap_32big(0x83ee2483U),
                                       bswap_32big(0x2879245eU),
                                       bswap_32big(0x9269d6dcU),
                                       bswap_32big(0xce34b98fU));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            WR1_PROG(REG_1A24H, 0x08000105U);
                            WR1_PROG(REG_1608H, 0x8184000fU);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_subfunc003(0x00890011U);
                            WR1_PROG(REG_1608H, 0x80040140U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_subfunc003(0x03420011U);
                            r_rsip_func101(bswap_32big(0xc560e5f6U),
                                           bswap_32big(0x6d16b409U),
                                           bswap_32big(0x557a52b4U),
                                           bswap_32big(0x152659b4U));
                        }
                        else
                        {
                            WR1_PROG(REG_1444H, 0x000001c7U);
                            WR1_PROG(REG_1608H, 0x80020080U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WAIT_STS(REG_1444H, 31U, 1U);
                            WR1_ADDR(REG_1420H, &InData_SeqNum[0]);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WAIT_STS(REG_1444H, 31U, 1U);
                            WR1_ADDR(REG_1420H, &InData_SeqNum[1]);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x380088c0U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1600H, 0x00000003U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            WR1_PROG(REG_1608H, 0x00000080U);
                            WR1_PROG(REG_143CH, 0x00260000U);
                            r_rsip_func100(bswap_32big(0x05436242U),
                                           bswap_32big(0x79e40616U),
                                           bswap_32big(0x2b1d7381U),
                                           bswap_32big(0x2c0912a3U));
                            WR1_PROG(REG_143CH, 0x00400000U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            if (CHCK_STS(REG_143CH, 22U, 1U))
                            {
                                WR1_PROG(REG_1600H, 0x0000394fU);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1600H, 0x00003564U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1600H, 0x00003585U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1600H, 0x0000b5a0U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1600H, 0x00000001U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                r_rsip_func101(bswap_32big(0x0aaeb747U), bswap_32big(0x91d425abU),
                                               bswap_32big(0x91f451d7U), bswap_32big(0xc0f015d6U));
                            }
                            else
                            {
                                WR1_PROG(REG_1A24H, 0x08000105U);
                                WR1_PROG(REG_1608H, 0x8183000fU);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                r_rsip_subfunc003(0x0089000dU);
                                r_rsip_subfunc003(0x00800005U);
                                WR1_PROG(REG_1608H, 0x80040140U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                r_rsip_subfunc003(0x03420011U);
                                WR1_PROG(REG_1600H, 0x00000964U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1600H, 0x00000985U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1600H, 0x0000b5a0U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                WR1_PROG(REG_1600H, 0x00000001U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                r_rsip_func101(bswap_32big(0x8b7e9c7cU), bswap_32big(0x6f228139U),
                                               bswap_32big(0xbeb89776U), bswap_32big(0x12a5332aU));
                            }
                        }

                        r_rsip_func100(bswap_32big(0x5bec5ef1U),
                                       bswap_32big(0x017a96f7U),
                                       bswap_32big(0xd52d4c70U),
                                       bswap_32big(0xb10cef83U));
                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0xe7009d05U);
                        WR1_PROG(REG_1608H, 0x81040140U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_subfunc003(0x00890011U);
                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[4]);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[5]);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[6]);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[7]);
                        r_rsip_func100(bswap_32big(0x74890864U),
                                       bswap_32big(0x855b7ae3U),
                                       bswap_32big(0x6b8f7552U),
                                       bswap_32big(0x4bd054c8U));
                        WR1_PROG(REG_1444H, 0x000000a2U);
                        WR1_PROG(REG_1A24H, 0x0c000104U);
                        WAIT_STS(REG_1444H, 31U, 1U);
                        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0x09108105U);
                        r_rsip_subfunc003(0x00820011U);
                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[8]);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[9]);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[10]);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[11]);
                        r_rsip_func100(bswap_32big(0x6860521dU),
                                       bswap_32big(0x0b2e2e46U),
                                       bswap_32big(0x173622e7U),
                                       bswap_32big(0x58c3788dU));
                        WR1_PROG(REG_1608H, 0x81040000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1408H, 0x00005012U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[0]);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[1]);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[2]);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[3]);
                        r_rsip_func102(bswap_32big(0xdc435d90U),
                                       bswap_32big(0x52aadaa2U),
                                       bswap_32big(0x87899f3dU),
                                       bswap_32big(0x24e7276dU));
                        WR1_PROG(REG_14B8H, 0x00000040U);
                        WAIT_STS(REG_142CH, 12U, 0U);

                        return RSIP_RET_PASS;
                    }
                }
            }
        }
    }
}
