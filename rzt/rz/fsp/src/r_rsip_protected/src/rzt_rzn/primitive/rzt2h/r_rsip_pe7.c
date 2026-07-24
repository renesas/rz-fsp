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
    r_rsip_func100(bswap_32big(0xa24ffcfaU),
                   bswap_32big(0x6f4933bbU),
                   bswap_32big(0x5f8d9ad3U),
                   bswap_32big(0x6904bee5U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x6d67717aU), bswap_32big(0x3a0dfb2bU), bswap_32big(0x3d006758U),
                       bswap_32big(0xeae26439U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0x9726a493U), bswap_32big(0xe41cf0e0U), bswap_32big(0x8fb880cdU),
                       bswap_32big(0x72e102a9U));
        WR1_PROG(REG_1600H, 0x00007c06U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x011bff02U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000000fU));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xbbc45df3U), bswap_32big(0x4898f44dU), bswap_32big(0x58053284U),
                           bswap_32big(0x34c58b3fU));
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x017a9348U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000001fU));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x62a38802U), bswap_32big(0x61802099U), bswap_32big(0xa9a31f32U),
                           bswap_32big(0xcafccc48U));
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0179875aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000000fU));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x77eb81acU), bswap_32big(0x2ebb780dU), bswap_32big(0x84d58693U),
                           bswap_32big(0x9f8c2208U));
        }
        else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0179875aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000003U));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x0857b82bU), bswap_32big(0x4a320edcU), bswap_32big(0x2c1df2ecU),
                           bswap_32big(0xbced1f47U));
        }
        else if (0x00000004U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0179875aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000000bU));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xafa84f20U), bswap_32big(0xd1b4dc7fU), bswap_32big(0x828c8b61U),
                           bswap_32big(0xe9b578c7U));
        }
        else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01ae25b0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000013U));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xb2c4db9aU), bswap_32big(0xe44fb032U), bswap_32big(0x0117803fU),
                           bswap_32big(0x4bf08464U));
        }
        else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x014320b8U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000001fU));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xe8df64dfU), bswap_32big(0xa278f322U), bswap_32big(0xdfacf0ddU),
                           bswap_32big(0x09267833U));
        }
        else if (0x00000007U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x010b526bU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000002fU));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x1de44c7dU), bswap_32big(0xf11c00dcU), bswap_32big(0x4258e372U),
                           bswap_32big(0x5f490d5bU));
        }
        else if (0x00000008U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01e2fe0aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a7U);
            WR1_PROG(REG_1608H, 0x800101c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0000003fU));
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xc952dfe2U), bswap_32big(0x819eb7ffU), bswap_32big(0x6f4c65afU),
                           bswap_32big(0x4199d4d1U));
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
        r_rsip_func100(bswap_32big(0x56361e19U), bswap_32big(0xe98f6c82U), bswap_32big(0xd027b75fU),
                       bswap_32big(0x9c74086aU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x33a62753U), bswap_32big(0xaed5b490U), bswap_32big(0xac38947aU),
                           bswap_32big(0x5956f6e7U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0xab7a3bc1U), bswap_32big(0xb8b32004U), bswap_32big(0x7fb86c3fU),
                           bswap_32big(0x1a5456d0U));
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
            r_rsip_func100(bswap_32big(0xd6862409U), bswap_32big(0x90172462U), bswap_32big(0xec721be2U),
                           bswap_32big(0x0f54ec49U));
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
                r_rsip_func100(bswap_32big(0x6548d1f0U),
                               bswap_32big(0xac6f8b72U),
                               bswap_32big(0xa73f5e03U),
                               bswap_32big(0x2acb68c4U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func101(bswap_32big(0xafff3b48U),
                                   bswap_32big(0x90871596U),
                                   bswap_32big(0x537e97d1U),
                                   bswap_32big(0x1a8d2aa9U));
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
                    r_rsip_func101(bswap_32big(0x61e8f3b2U),
                                   bswap_32big(0xadc6df17U),
                                   bswap_32big(0x8aaca705U),
                                   bswap_32big(0x321dec04U));
                    r_rsip_func045();
                    WR1_PROG(REG_1600H, 0x0000b4e0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x018f1cdcU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc009(bswap_32big(0x0000e701U));
                    r_rsip_func101(bswap_32big(0xd4585cdfU),
                                   bswap_32big(0xff83359bU),
                                   bswap_32big(0x91aeb805U),
                                   bswap_32big(0xe01271d5U));
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
                        r_rsip_func101(bswap_32big(0x5d2ce98aU),
                                       bswap_32big(0x2876cd92U),
                                       bswap_32big(0x5ab5293fU),
                                       bswap_32big(0x1d1cc6c7U));
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
                    r_rsip_func100(bswap_32big(0x98258791U),
                                   bswap_32big(0x91fc579eU),
                                   bswap_32big(0xeac796c6U),
                                   bswap_32big(0xe3dd9c4fU));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        WR1_PROG(REG_1600H, 0x0000d280U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_func101(bswap_32big(0x68cb8718U),
                                       bswap_32big(0xebba2471U),
                                       bswap_32big(0x5baffda2U),
                                       bswap_32big(0xd8fe6272U));
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0xd17d29c0U),
                                       bswap_32big(0xe6ce2a1eU),
                                       bswap_32big(0xef34a66bU),
                                       bswap_32big(0x8bb499b9U));
                    }
                }

                WR1_PROG(REG_1600H, 0x00002ea0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00002e60U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x36e2b539U),
                               bswap_32big(0xf0861711U),
                               bswap_32big(0x1b1abe64U),
                               bswap_32big(0x62342656U));
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
            r_rsip_func100(bswap_32big(0x13dd0929U), bswap_32big(0x6d8079dbU), bswap_32big(0x1bcc96acU),
                           bswap_32big(0x9f14c205U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x1656896cU),
                               bswap_32big(0x93674bedU),
                               bswap_32big(0x988bf3b4U),
                               bswap_32big(0x25887b35U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0xa2a86616U),
                               bswap_32big(0xae14d13aU),
                               bswap_32big(0x6e06d210U),
                               bswap_32big(0x2dc458aeU));
                r_rsip_func103();
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c200104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1608H, 0x80040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                r_rsip_subfunc009(bswap_32big(0x0000e702U));
                r_rsip_func101(bswap_32big(0x4308bfa8U),
                               bswap_32big(0xeac02a37U),
                               bswap_32big(0xa77ee38dU),
                               bswap_32big(0x133bc2b7U));
                r_rsip_func045();
                WR1_PROG(REG_1600H, 0x000034e9U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc009(bswap_32big(0x0000e702U));
                r_rsip_func101(bswap_32big(0xefb77a67U),
                               bswap_32big(0x4a6c9210U),
                               bswap_32big(0x478b1746U),
                               bswap_32big(0x488f9605U));
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
                r_rsip_func100(bswap_32big(0x7b49ecefU),
                               bswap_32big(0xeabd419aU),
                               bswap_32big(0xae646e8bU),
                               bswap_32big(0xd6d4a772U));
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
                    r_rsip_func100(bswap_32big(0x38ff2742U),
                                   bswap_32big(0x56a2c4b0U),
                                   bswap_32big(0x157a6f32U),
                                   bswap_32big(0xe9ead9c2U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_func100(bswap_32big(0x970c05d9U),
                                       bswap_32big(0x16e6c417U),
                                       bswap_32big(0xb4c2eaf7U),
                                       bswap_32big(0x600694e5U));
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
                        r_rsip_func100(bswap_32big(0xafaeed7aU),
                                       bswap_32big(0xdf7eeabbU),
                                       bswap_32big(0xa1853753U),
                                       bswap_32big(0x776ddae5U));
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
                        r_rsip_func101(bswap_32big(0x40d36dc3U),
                                       bswap_32big(0x13219703U),
                                       bswap_32big(0x0e4fb31eU),
                                       bswap_32big(0x04610169U));
                    }
                    else
                    {
                        r_rsip_func100(bswap_32big(0xb314f897U),
                                       bswap_32big(0x0a018058U),
                                       bswap_32big(0xf0a24007U),
                                       bswap_32big(0xa6d14ae9U));
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
                        r_rsip_func100(bswap_32big(0xf0108cf8U),
                                       bswap_32big(0xf64362d9U),
                                       bswap_32big(0xcf66c9e8U),
                                       bswap_32big(0x749f6bbdU));
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
                        r_rsip_func101(bswap_32big(0x7e626823U),
                                       bswap_32big(0x630438e1U),
                                       bswap_32big(0xf7786c6bU),
                                       bswap_32big(0x69ab2398U));
                    }

                    r_rsip_func100(bswap_32big(0x5135e58cU),
                                   bswap_32big(0x39fa21ccU),
                                   bswap_32big(0x2951d04dU),
                                   bswap_32big(0x7767e352U));
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
                    r_rsip_func102(bswap_32big(0xa837f4fbU),
                                   bswap_32big(0x1bc89435U),
                                   bswap_32big(0xa975aed2U),
                                   bswap_32big(0x0040b986U));
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
                    r_rsip_func100(bswap_32big(0x2f1df64cU),
                                   bswap_32big(0xb491fd61U),
                                   bswap_32big(0xae796f36U),
                                   bswap_32big(0x8276855dU));
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
                        r_rsip_func100(bswap_32big(0xf5e30bdcU),
                                       bswap_32big(0xa0daeee3U),
                                       bswap_32big(0x55ab1c98U),
                                       bswap_32big(0x92ce483cU));
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
                            r_rsip_func101(bswap_32big(0xa64fac66U),
                                           bswap_32big(0xc04178e8U),
                                           bswap_32big(0xbf568274U),
                                           bswap_32big(0x166f8dfbU));
                        }
                        else
                        {
                            r_rsip_func101(bswap_32big(0x187b28d0U),
                                           bswap_32big(0x33b6e8f0U),
                                           bswap_32big(0x739cbe00U),
                                           bswap_32big(0xe422bd05U));
                        }

                        WR1_PROG(REG_1600H, 0x000008e7U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_func100(bswap_32big(0xe5ecc982U),
                                       bswap_32big(0x90f60fb4U),
                                       bswap_32big(0x5005a330U),
                                       bswap_32big(0x6140e383U));
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
                            r_rsip_func100(bswap_32big(0x292ebe82U),
                                           bswap_32big(0x992dbc0fU),
                                           bswap_32big(0x3719de89U),
                                           bswap_32big(0x095dd198U));
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
                            r_rsip_func101(bswap_32big(0xd6ae8c29U),
                                           bswap_32big(0xf37107afU),
                                           bswap_32big(0x2cfc20e4U),
                                           bswap_32big(0x71d710d7U));
                        }

                        WR1_PROG(REG_1600H, 0x380009c7U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1608H, 0x00000080U);
                        WR1_PROG(REG_143CH, 0x00260000U);
                        WR1_PROG(REG_143CH, 0x00402000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_func100(bswap_32big(0xe13994e1U),
                                       bswap_32big(0x4925e196U),
                                       bswap_32big(0x975b09b9U),
                                       bswap_32big(0xcf578d0bU));
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
                        r_rsip_func100(bswap_32big(0x1d8b4f02U),
                                       bswap_32big(0x38a35305U),
                                       bswap_32big(0x0371e03fU),
                                       bswap_32big(0x327d1c31U));
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
                        r_rsip_func102(bswap_32big(0xbf5b37b6U),
                                       bswap_32big(0xbdf32816U),
                                       bswap_32big(0xdad22f3cU),
                                       bswap_32big(0x44a1e53eU));
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
                        r_rsip_func100(bswap_32big(0x5087c1e3U),
                                       bswap_32big(0x2d484b18U),
                                       bswap_32big(0x8bc8ef70U),
                                       bswap_32big(0xec3b37c8U));
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
                            r_rsip_func101(bswap_32big(0xf4fa4154U),
                                           bswap_32big(0x5329b430U),
                                           bswap_32big(0x06b61fc7U),
                                           bswap_32big(0xc9d15392U));
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
                            r_rsip_func100(bswap_32big(0xecfe9bfbU),
                                           bswap_32big(0xde78e348U),
                                           bswap_32big(0xb38dbd38U),
                                           bswap_32big(0x13f17dceU));
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
                                r_rsip_func101(bswap_32big(0xf472db52U), bswap_32big(0xa3c691b4U),
                                               bswap_32big(0x5a091d6bU), bswap_32big(0xbd926060U));
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
                                r_rsip_func101(bswap_32big(0x757d739eU), bswap_32big(0xb754053fU),
                                               bswap_32big(0xd8128dc0U), bswap_32big(0x63d3645cU));
                            }
                        }

                        r_rsip_func100(bswap_32big(0xb103a922U),
                                       bswap_32big(0xe3090237U),
                                       bswap_32big(0xe24c20e3U),
                                       bswap_32big(0x773178a1U));
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
                        r_rsip_func100(bswap_32big(0x870b064aU),
                                       bswap_32big(0x890f58f7U),
                                       bswap_32big(0x6d505f2bU),
                                       bswap_32big(0x189c2af3U));
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
                        r_rsip_func100(bswap_32big(0xb8c9a3a3U),
                                       bswap_32big(0x07bd00ccU),
                                       bswap_32big(0x47ba7cedU),
                                       bswap_32big(0xf7f21e1bU));
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
                        r_rsip_func102(bswap_32big(0x97410500U),
                                       bswap_32big(0x03e3a0a2U),
                                       bswap_32big(0xc66a9210U),
                                       bswap_32big(0xbdb97d42U));
                        WR1_PROG(REG_14B8H, 0x00000040U);
                        WAIT_STS(REG_142CH, 12U, 0U);

                        return RSIP_RET_PASS;
                    }
                }
            }
        }
    }
}
