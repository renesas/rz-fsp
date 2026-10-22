/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_TSIP_PRIMITIVE_H
#define R_TSIP_PRIMITIVE_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <stdint.h>
#include "r_tsip_err.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define TSIP_PRV_WORD_SIZE_S_RAM     (20U)
#define TSIP_PRV_WORD_SIZE_S_HEAP    (1496U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

extern uint32_t         S_RAM[TSIP_PRV_WORD_SIZE_S_RAM];
extern uint32_t         S_HEAP[TSIP_PRV_WORD_SIZE_S_HEAP];
extern uint32_t const * S_INST2;

extern uint32_t const S_FLASH[];

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/

/* Subroutine */
void r_tsip_func000(const uint32_t InData_PaddedMsg[], uint32_t MAX_CNT);
void r_tsip_func001(void);
void r_tsip_func002(void);
void r_tsip_func003(uint32_t * ARG1);
void r_tsip_func004(uint32_t ARG1);
void r_tsip_func005(uint32_t ARG1);
void r_tsip_func006(void);
void r_tsip_func007(void);
void r_tsip_func009(void);
void r_tsip_func022(void);
void r_tsip_func023(void);
void r_tsip_func027(uint32_t ARG1);
void r_tsip_func028(uint32_t ARG1);
void r_tsip_func050(uint32_t ARG1);
void r_tsip_func051(void);
void r_tsip_func052(uint32_t ARG1);
void r_tsip_func053(uint32_t ARG1);
void r_tsip_func054(uint32_t ARG1, uint32_t ARG2);
void r_tsip_func060(void);
void r_tsip_func061(void);
void r_tsip_func070(uint32_t ARG1);
void r_tsip_func071(uint32_t ARG1);
void r_tsip_func076(void);
void r_tsip_func077(void);
void r_tsip_func078(uint32_t ARG1);
void r_tsip_func079(uint32_t ARG1);
void r_tsip_func080(void);
void r_tsip_func100(uint32_t ARG1, uint32_t ARG2, uint32_t ARG3, uint32_t ARG4);
void r_tsip_func101(uint32_t ARG1, uint32_t ARG2, uint32_t ARG3, uint32_t ARG4);
void r_tsip_func102(uint32_t ARG1, uint32_t ARG2, uint32_t ARG3, uint32_t ARG4);
void r_tsip_func103(void);
void r_tsip_func200(void);
void r_tsip_func205(void);
void r_tsip_func206(void);
void r_tsip_func300(void);
void r_tsip_func301(void);
void r_tsip_func302(void);
void r_tsip_func303(const uint32_t ARG1[]);
void r_tsip_func304(void);
void r_tsip_func305(void);
void r_tsip_func306(void);
void r_tsip_func307(void);
void r_tsip_func308(void);
void r_tsip_func309(void);
void r_tsip_func310(void);
void r_tsip_func311(void);
void r_tsip_func312(uint32_t ARG1);
void r_tsip_func313(uint32_t ARG1);
void r_tsip_func314(uint32_t ARG1);
void r_tsip_func315(uint32_t ARG1);
void r_tsip_func326(void);
void r_tsip_func327(void);

/* Open */
void       r_tsip_p00(void);
tsip_ret_t r_tsip_p01(void);
tsip_ret_t r_tsip_p02(void);
tsip_ret_t r_tsip_p06(const uint32_t InData_Cmd[]);
tsip_ret_t r_tsip_p1a(void);
void       r_tsip_subprc01(void);

/* Key generation */
tsip_ret_t r_tsip_p07(uint32_t OutData_KeyIndex[]);
tsip_ret_t r_tsip_p08(uint32_t OutData_KeyIndex[]);
tsip_ret_t r_tsip_p16(uint32_t OutData_KeyIndex[]);
tsip_ret_t r_tsip_p17(uint32_t OutData_KeyIndex[]);
tsip_ret_t r_tsip_p6d(uint32_t OutData_KeyIndex[]);
tsip_ret_t r_tsip_p6e(uint32_t OutData_KeyIndex[]);
tsip_ret_t r_tsip_p6f(uint32_t OutData_KeyIndex[]);

/* Key pair generation */
tsip_ret_t r_tsip_pf4(uint32_t const InData_CurveType[],
                      uint32_t const InData_Cmd[],
                      uint32_t       OutData_PubKeyIndex[],
                      uint32_t       OutData_PrivKeyIndex[]);
tsip_ret_t r_tsip_pf9(uint32_t const InData_CurveType[], uint32_t OutData_PubKeyIndex[],
                      uint32_t OutData_PrivKeyIndex[]);
tsip_ret_t r_tsip_ped(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
tsip_ret_t r_tsip_p2a(uint32_t MAX_CNT, uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
tsip_ret_t r_tsip_p2b(uint32_t MAX_CNT, uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);

/* Key update */
tsip_ret_t r_tsip_p19(const uint32_t InData_IV[], const uint32_t InData_InstData[], uint32_t OutData_KeyIndex[]);
tsip_ret_t r_tsip_p1c(const uint32_t InData_IV[], const uint32_t InData_InstData[], uint32_t OutData_KeyIndex[]);
tsip_ret_t r_tsip_p2c(uint32_t const InData_CurveType[],
                      uint32_t const InData_Cmd[],
                      uint32_t const InData_IV[],
                      uint32_t const InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
tsip_ret_t r_tsip_p1e(uint32_t const InData_CurveType[],
                      uint32_t const InData_Cmd[],
                      uint32_t const InData_IV[],
                      uint32_t const InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
tsip_ret_t r_tsip_p2d(uint32_t const InData_CurveType[],
                      uint32_t const InData_IV[],
                      uint32_t const InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
tsip_ret_t r_tsip_p2e(uint32_t const InData_CurveType[],
                      uint32_t const InData_IV[],
                      uint32_t const InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
tsip_ret_t r_tsip_pee(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
tsip_ret_t r_tsip_pef(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
tsip_ret_t r_tsip_p0b(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
tsip_ret_t r_tsip_p0c(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
tsip_ret_t r_tsip_p0d(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
tsip_ret_t r_tsip_p0e(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
tsip_ret_t r_tsip_p9e(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
tsip_ret_t r_tsip_p0f(const uint32_t InData_Cmd[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);

/* RNG */
tsip_ret_t r_tsip_p20(uint32_t p_random[]);

/* AES-ECB/CBC/CTR */
tsip_ret_t r_tsip_p48i(const uint32_t InData_Cmd[], const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
tsip_ret_t r_tsip_p50i(const uint32_t InData_Cmd[], const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
void       r_tsip_p48u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
void       r_tsip_p50u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
tsip_ret_t r_tsip_p48f(void);
tsip_ret_t r_tsip_p50f(void);

/* AES-GCM */
tsip_ret_t r_tsip_p29i(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
tsip_ret_t r_tsip_p32i(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
tsip_ret_t r_tsip_p34i(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
tsip_ret_t r_tsip_p36i(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
void       r_tsip_p29t(void);
void       r_tsip_p32t(void);
void       r_tsip_p34t(void);
void       r_tsip_p36t(void);
void       r_tsip_p29a(const uint32_t InData_DataA[], uint32_t MAX_CNT);
void       r_tsip_p32a(const uint32_t InData_DataA[], uint32_t MAX_CNT);
void       r_tsip_p34a(const uint32_t InData_DataA[], uint32_t MAX_CNT);
void       r_tsip_p36a(const uint32_t InData_DataA[], uint32_t MAX_CNT);
void       r_tsip_p29u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
void       r_tsip_p32u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
void       r_tsip_p34u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
void       r_tsip_p36u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
tsip_ret_t r_tsip_p29f(const uint32_t InData_Text[],
                       const uint32_t InData_DataALen[],
                       const uint32_t InData_TextLen[],
                       uint32_t       OutData_Text[],
                       uint32_t       OutData_DataT[]);
tsip_ret_t r_tsip_p34f(const uint32_t InData_Text[],
                       const uint32_t InData_DataALen[],
                       const uint32_t InData_TextLen[],
                       uint32_t       OutData_Text[],
                       uint32_t       OutData_DataT[]);
tsip_ret_t r_tsip_p32f(const uint32_t InData_Text[],
                       const uint32_t InData_DataT[],
                       const uint32_t InData_DataALen[],
                       const uint32_t InData_TextLen[],
                       const uint32_t InData_DataTLen[],
                       uint32_t       OutData_Text[]);
tsip_ret_t r_tsip_p36f(const uint32_t InData_Text[],
                       const uint32_t InData_DataT[],
                       const uint32_t InData_DataALen[],
                       const uint32_t InData_TextLen[],
                       const uint32_t InData_DataTLen[],
                       uint32_t       OutData_Text[]);
tsip_ret_t r_tsip_p21(const uint32_t InData_HV[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_Text[],
                      uint32_t       OutData_DataT[],
                      uint32_t       MAX_CNT);

/* AES-CMAC */
tsip_ret_t r_tsip_p41i(const uint32_t InData_KeyIndex[]);
tsip_ret_t r_tsip_p44i(const uint32_t InData_KeyIndex[]);
void       r_tsip_p41u(const uint32_t InData_Text[], uint32_t MAX_CNT);
void       r_tsip_p44u(const uint32_t InData_Text[], uint32_t MAX_CNT);
tsip_ret_t r_tsip_p41f(const uint32_t InData_Cmd[],
                       const uint32_t InData_Text[],
                       const uint32_t InData_DataT[],
                       const uint32_t InData_DataTLen[],
                       uint32_t       OutData_DataT[]);
tsip_ret_t r_tsip_p44f(const uint32_t InData_Cmd[],
                       const uint32_t InData_Text[],
                       const uint32_t InData_DataT[],
                       const uint32_t InData_DataTLen[],
                       uint32_t       OutData_DataT[]);

/* ECDSA */
tsip_ret_t r_tsip_pf0(const uint32_t InData_CurveType[],
                      const uint32_t InData_Cmd[],
                      const uint32_t InData_KeyIndex[],
                      const uint32_t InData_MsgDgst[],
                      uint32_t       OutData_Signature[]);
tsip_ret_t r_tsip_pf1(const uint32_t InData_CurveType[],
                      const uint32_t InData_Cmd[],
                      const uint32_t InData_KeyIndex[],
                      const uint32_t InData_MsgDgst[],
                      const uint32_t InData_Signature[]);
tsip_ret_t r_tsip_pf5(const uint32_t InData_CurveType[],
                      const uint32_t InData_KeyIndex[],
                      const uint32_t InData_MsgDgst[],
                      uint32_t       OutData_Signature[]);
tsip_ret_t r_tsip_pf6(const uint32_t InData_CurveType[],
                      const uint32_t InData_KeyIndex[],
                      const uint32_t InData_MsgDgst[],
                      const uint32_t InData_Signature[]);
tsip_ret_t r_tsip_p7d(const uint32_t InData_KeyIndex[], const uint32_t InData_MsgDgst[], uint32_t OutData_Signature[]);
tsip_ret_t r_tsip_p7e(const uint32_t InData_KeyIndex[],
                      const uint32_t InData_MsgDgst[],
                      const uint32_t InData_Signature[]);

/* RSA */
tsip_ret_t r_tsip_p53(const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[]);
tsip_ret_t r_tsip_p54(const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[]);
tsip_ret_t r_tsip_p56(const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[]);
tsip_ret_t r_tsip_p57(const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[]);
tsip_ret_t r_tsip_p7c(const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[]);

/* SHA */
tsip_ret_t r_tsip_p71(const uint32_t InData_SHA1InitVal[],
                      const uint32_t InData_PaddedMsg[],
                      const uint32_t MAX_CNT,
                      uint32_t       OutData_MsgDigest[]);
tsip_ret_t r_tsip_p72(const uint32_t InData_SHA_InitVal[],
                      const uint32_t InData_PaddedMsg[],
                      const uint32_t MAX_CNT,
                      uint32_t       OutData_MsgDigest[]);

/* HMAC */
tsip_ret_t r_tsip_p73i(const uint32_t InData_KeyIndex[]);
tsip_ret_t r_tsip_pdci(const uint32_t InData_KeyIndex[]);
tsip_ret_t r_tsip_p76i(const uint32_t InData_KeyIndex[]);
tsip_ret_t r_tsip_p73r(const uint32_t InData_KeyIndex[], const uint32_t InData_State[]);
tsip_ret_t r_tsip_pdcr(const uint32_t InData_KeyIndex[], const uint32_t InData_State[]);
tsip_ret_t r_tsip_p76r(const uint32_t InData_KeyIndex[], const uint32_t InData_State[]);
void       r_tsip_p73u(const uint32_t InData_PaddedMsg[], uint32_t MAX_CNT);
void       r_tsip_pdcu(const uint32_t InData_PaddedMsg[], uint32_t MAX_CNT);
void       r_tsip_p76u(const uint32_t InData_PaddedMsg[], uint32_t MAX_CNT);
tsip_ret_t r_tsip_p73s(uint32_t OutData_State[]);
tsip_ret_t r_tsip_pdcs(uint32_t OutData_State[]);
tsip_ret_t r_tsip_p76s(uint32_t OutData_State[]);
tsip_ret_t r_tsip_p73f(const uint32_t InData_Cmd[],
                       const uint32_t InData_MAC[],
                       const uint32_t InData_length[],
                       uint32_t       OutData_MAC[]);
tsip_ret_t r_tsip_pdcf(const uint32_t InData_Cmd[],
                       const uint32_t InData_MAC[],
                       const uint32_t InData_length[],
                       uint32_t       OutData_MAC[]);
tsip_ret_t r_tsip_p76f(const uint32_t InData_Cmd[],
                       const uint32_t InData_MAC[],
                       const uint32_t InData_length[],
                       uint32_t       OutData_MAC[]);

#endif                                 /* R_TSIP_PRIMITIVE_H_ */
