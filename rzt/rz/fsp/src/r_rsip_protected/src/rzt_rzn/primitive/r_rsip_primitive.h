/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_RSIP_PRIMITIVE_H
#define R_RSIP_PRIMITIVE_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <stdint.h>
#include "r_rsip_err.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define RSIP_PRV_WORD_SIZE_S_RAM     (16U)
#define RSIP_PRV_WORD_SIZE_S_HEAP    (940U)
#define RSIP_PRV_WORD_SIZE_S_INST    (16U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

extern uint32_t         S_RAM[RSIP_PRV_WORD_SIZE_S_RAM];
extern uint32_t         S_HEAP[RSIP_PRV_WORD_SIZE_S_HEAP];
extern uint32_t         S_INST[RSIP_PRV_WORD_SIZE_S_INST];
extern uint32_t const * S_INST2;
extern uint32_t const   DomainParam_NIST_P256[];
extern uint32_t const   DomainParam_NIST_P384[];
extern uint32_t const   DomainParam_NIST_P521[];
extern uint32_t const   DomainParam_Brainpool_256r1[];
extern uint32_t const   DomainParam_Brainpool_384r1[];
extern uint32_t const   DomainParam_Brainpool_512r1[];
extern uint32_t const   DomainParam_Ed25519[];

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/

/* Internal sub functions */
void r_rsip_subfunc001(uint32_t ARG1, uint32_t ARG2, uint32_t ARG3, uint32_t ARG4);
void r_rsip_subfunc002(uint32_t ARG1, uint32_t ARG2, uint32_t ARG3);
void r_rsip_subfunc003(uint32_t ARG1);
void r_rsip_subfunc004(uint32_t ARG1, uint32_t ARG2, uint32_t ARG3);
void r_rsip_subfunc005(uint32_t ARG1, uint32_t ARG2, uint32_t ARG3, uint32_t ARG4, uint32_t ARG5, uint32_t ARG6);
void r_rsip_subfunc006(uint32_t ARG1, uint32_t ARG2, uint32_t ARG3);
void r_rsip_subfunc007(uint32_t ARG1);
void r_rsip_subfunc008(uint32_t ARG1, uint32_t ARG2, uint32_t ARG3);
void r_rsip_subfunc009(uint32_t ARG1);

/* Subroutine */
void r_rsip_func008(void);
void r_rsip_func016(uint32_t ARG1);
void r_rsip_func017(uint32_t ARG1);
void r_rsip_func022(void);
void r_rsip_func023(void);
void r_rsip_func027(const uint32_t ARG1[]);
void r_rsip_func028(const uint32_t ARG1[]);
void r_rsip_func029(void);
void r_rsip_func030(void);
void r_rsip_func031(void);
void r_rsip_func032(void);
void r_rsip_func033(void);
void r_rsip_func034(void);
void r_rsip_func040(void);
void r_rsip_func041(void);
void r_rsip_func043(void);
void r_rsip_func044(void);
void r_rsip_func045(void);
void r_rsip_func046(void);
void r_rsip_func047(void);
void r_rsip_func050(void);
void r_rsip_func051(void);
void r_rsip_func052(void);
void r_rsip_func053(void);
void r_rsip_func054(void);
void r_rsip_func055(void);
void r_rsip_func056(void);
void r_rsip_func057(void);
void r_rsip_func058(void);
void r_rsip_func059(void);
void r_rsip_func060(void);
void r_rsip_func061(void);
void r_rsip_func062(void);
void r_rsip_func066(void);
void r_rsip_func071(void);
void r_rsip_func072(void);
void r_rsip_func073(const uint32_t ARG1[]);
void r_rsip_func074(const uint32_t ARG1[]);
void r_rsip_func075(const uint32_t ARG1[]);
void r_rsip_func076(void);
void r_rsip_func077(void);
void r_rsip_func078(const uint32_t ARG1[]);
void r_rsip_func079(const uint32_t ARG1[]);
void r_rsip_func084(void);
void r_rsip_func085(void);
void r_rsip_func086(const uint32_t ARG1[]);
void r_rsip_func087(const uint32_t ARG1[]);
void r_rsip_func088(void);
void r_rsip_func089(void);
void r_rsip_func091(void);
void r_rsip_func100(uint32_t ARG1, uint32_t ARG2, uint32_t ARG3, uint32_t ARG4);
void r_rsip_func101(uint32_t ARG1, uint32_t ARG2, uint32_t ARG3, uint32_t ARG4);
void r_rsip_func102(uint32_t ARG1, uint32_t ARG2, uint32_t ARG3, uint32_t ARG4);
void r_rsip_func103(void);
void r_rsip_func205(void);
void r_rsip_func206(void);
void r_rsip_func215(void);
void r_rsip_func216(void);
void r_rsip_func220(const uint32_t ARG1[], uint32_t ARG2, uint32_t ARG3[]);
void r_rsip_func221(const uint32_t ARG1[], uint32_t ARG2);
void r_rsip_func300(void);
void r_rsip_func301(void);
void r_rsip_func302(void);
void r_rsip_func303(void);
void r_rsip_func304(void);
void r_rsip_func305(void);
void r_rsip_func306(void);
void r_rsip_func307(void);
void r_rsip_func308(void);
void r_rsip_func309(void);
void r_rsip_func310(void);
void r_rsip_func311(void);
void r_rsip_func400(const uint32_t ARG1[]);
void r_rsip_func401(const uint32_t ARG1[]);
void r_rsip_func402(void);
void r_rsip_func403(void);
void r_rsip_func404(void);
void r_rsip_func405(void);
void r_rsip_func406(const uint32_t ARG1[]);
void r_rsip_func407(const uint32_t ARG1[]);
void r_rsip_func408(void);
void r_rsip_func420(void);
void r_rsip_func421(void);
void r_rsip_func422(const uint32_t ARG1[], uint32_t ARG2);
void r_rsip_func423(uint32_t ARG1[], uint32_t ARG2);
void r_rsip_func431(void);
void r_rsip_func432(void);
void r_rsip_func433(void);
void r_rsip_func434(void);
void r_rsip_func435(const uint32_t ARG1[], uint32_t ARG2[]);
void r_rsip_func436(const uint32_t ARG1[]);
void r_rsip_func440(const uint32_t ARG1[]);
void r_rsip_func441(const uint32_t ARG1[]);
void r_rsip_func443(const uint32_t ARG1[]);
void r_rsip_func450(const uint32_t ARG1[]);
void r_rsip_func501(const uint32_t ARG1[], const uint32_t ARG2[], uint32_t ARG3);

/* Open */
void       r_rsip_p00(void);
rsip_ret_t r_rsip_p01(void);
rsip_ret_t r_rsip_p02(void);
rsip_ret_t r_rsip_p06(const uint32_t InData_Cmd[]);
rsip_ret_t r_rsip_p25(const uint32_t InData_Cmd[]);
rsip_ret_t r_rsip_p40(const uint32_t InData_KeyIndex[]);

/* Key generation */
rsip_ret_t r_rsip_p07(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p86(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p08(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p16(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p17(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p6d(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p6e(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p6f(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p3c(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p3d(uint32_t OutData_KeyIndex[]);

/* Key pair generation */
rsip_ret_t r_rsip_pf4(uint32_t const InData_CurveType[],
                      uint32_t const InData_Cmd[],
                      uint32_t const InData_DomainParam[],
                      uint32_t       OutData_PubKeyIndex[],
                      uint32_t       OutData_PrivKeyIndex[]);
rsip_ret_t r_rsip_pf9(uint32_t const InData_CurveType[],
                      uint32_t const InData_DomainParam[],
                      uint32_t       OutData_PubKeyIndex[],
                      uint32_t       OutData_PrivKeyIndex[]);
rsip_ret_t r_rsip_p7f(uint32_t const InData_DomainParam[],
                      uint32_t       OutData_PubKeyIndex[],
                      uint32_t       OutData_PrivKeyIndex[]);
rsip_ret_t r_rsip_p13(uint32_t const InData_DomainParam[],
                      uint32_t       OutData_PubKeyIndex[],
                      uint32_t       OutData_PrivKeyIndex[]);
rsip_ret_t r_rsip_p4a(uint32_t const InData_DomainParam[],
                      uint32_t       OutData_PubKeyIndex[],
                      uint32_t       OutData_PrivKeyIndex[]);
rsip_ret_t r_rsip_p2a(uint32_t MAX_CNT, uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
rsip_ret_t r_rsip_p2b(uint32_t MAX_CNT, uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
rsip_ret_t r_rsip_p3a(uint32_t MAX_CNT, uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
rsip_ret_t r_rsip_p3b(uint32_t MAX_CNT, uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);

/* Key injection */
rsip_ret_t r_rsip_p10(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p84(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p04(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p18(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p1a(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p59(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p60(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p62(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p63(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p37(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p42(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p43(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p45(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_pfa(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_CurveType[],
                      const uint32_t InData_Cmd[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_pf3(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_CurveType[],
                      const uint32_t InData_Cmd[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_pf7(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_CurveType[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_pf8(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_CurveType[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_pfb(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_pfc(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p3e(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p3f(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_pb1(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_pb2(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p80(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_Cmd[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p92(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p93(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p1f(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);

/* Key update */
rsip_ret_t r_rsip_p19(const uint32_t InData_IV[], const uint32_t InData_InstData[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p88(const uint32_t InData_IV[], const uint32_t InData_InstData[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p1c(const uint32_t InData_IV[], const uint32_t InData_InstData[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p1b(const uint32_t InData_IV[], const uint32_t InData_InstData[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p1d(const uint32_t InData_IV[], const uint32_t InData_InstData[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p2c(uint32_t const InData_CurveType[],
                      uint32_t const InData_Cmd[],
                      uint32_t const InData_IV[],
                      uint32_t const InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p1e(uint32_t const InData_CurveType[],
                      uint32_t const InData_Cmd[],
                      uint32_t const InData_IV[],
                      uint32_t const InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p2d(uint32_t const InData_CurveType[],
                      uint32_t const InData_IV[],
                      uint32_t const InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p2e(uint32_t const InData_CurveType[],
                      uint32_t const InData_IV[],
                      uint32_t const InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p8a(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p8b(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p8c(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p8d(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_paa(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_pab(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);

rsip_ret_t r_rsip_p0b(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p0c(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p0d(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p0e(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p38(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p9e(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p9d(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p9f(uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_p0f(const uint32_t InData_Cmd[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_pa8(const uint32_t InData_IV[], const uint32_t InData_InstData[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_pa9(const uint32_t InData_IV[], const uint32_t InData_InstData[], uint32_t OutData_KeyIndex[]);

/* RFC3394 AES Key Wrap */
rsip_ret_t r_rsip_p8f(const uint32_t InData_Cmd[],
                      const uint32_t InData_KeyIndex[],
                      const uint32_t InData_WrappedKeyType[],
                      const uint32_t InData_WrappedKeyIndex[],
                      uint32_t       OutData_Text[],
                      uint32_t       KEY_INDEX_SIZE,
                      uint32_t       WRAPPED_KEY_SIZE);
rsip_ret_t r_rsip_p90(const uint32_t InData_Cmd[],
                      const uint32_t InData_KeyIndex[],
                      const uint32_t InData_WrappedKeyType[],
                      const uint32_t InData_Text[],
                      uint32_t       OutData_KeyIndex[],
                      uint32_t       WRAPPED_KEY_SIZE,
                      uint32_t       KEY_INDEX_SIZE);

/* RNG */
rsip_ret_t r_rsip_p20(uint32_t p_random[]);

/* AES-ECB/CBC/CTR */
rsip_ret_t r_rsip_p48i(const uint32_t InData_Cmd[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_IVType[],
                       const uint32_t InData_IV[]);
rsip_ret_t r_rsip_p89i(const uint32_t InData_Cmd[], const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_p50i(const uint32_t InData_Cmd[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_IVType[],
                       const uint32_t InData_IV[]);
void       r_rsip_p48u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
void       r_rsip_p89u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
void       r_rsip_p50u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
rsip_ret_t r_rsip_p48f(void);
rsip_ret_t r_rsip_p89f(void);
rsip_ret_t r_rsip_p50f(void);

/* AES-XTS */
rsip_ret_t r_rsip_pb3i(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_pb6i(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_pb9i(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_pc2i(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
void       r_rsip_pb3u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
void       r_rsip_pb6u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
void       r_rsip_pb9u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
void       r_rsip_pc2u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
rsip_ret_t r_rsip_pb3f(const uint32_t InData_TextBitLen[], const uint32_t InData_Text[], uint32_t OutData_Text[]);
rsip_ret_t r_rsip_pb6f(const uint32_t InData_TextBitLen[], const uint32_t InData_Text[], uint32_t OutData_Text[]);
rsip_ret_t r_rsip_pb9f(const uint32_t InData_TextBitLen[], const uint32_t InData_Text[], uint32_t OutData_Text[]);
rsip_ret_t r_rsip_pc2f(const uint32_t InData_TextBitLen[], const uint32_t InData_Text[], uint32_t OutData_Text[]);

/* AES-GCM */
rsip_ret_t r_rsip_p29i(const uint32_t InData_KeyIndex[], const uint32_t InData_IVType[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_p83i(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_p32i(const uint32_t InData_KeyIndex[], const uint32_t InData_IVType[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_p34i(const uint32_t InData_KeyIndex[], const uint32_t InData_IVType[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_p85i(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_p36i(const uint32_t InData_KeyIndex[], const uint32_t InData_IVType[], const uint32_t InData_IV[]);
void       r_rsip_p29t(void);
void       r_rsip_p83t(void);
void       r_rsip_p32t(void);
void       r_rsip_p34t(void);
void       r_rsip_p85t(void);
void       r_rsip_p36t(void);
void       r_rsip_p29a(const uint32_t InData_DataA[], uint32_t MAX_CNT);
void       r_rsip_p83a(const uint32_t InData_DataA[], uint32_t MAX_CNT);
void       r_rsip_p32a(const uint32_t InData_DataA[], uint32_t MAX_CNT);
void       r_rsip_p34a(const uint32_t InData_DataA[], uint32_t MAX_CNT);
void       r_rsip_p85a(const uint32_t InData_DataA[], uint32_t MAX_CNT);
void       r_rsip_p36a(const uint32_t InData_DataA[], uint32_t MAX_CNT);
void       r_rsip_p29u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
void       r_rsip_p83u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
void       r_rsip_p32u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
void       r_rsip_p34u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
void       r_rsip_p85u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
void       r_rsip_p36u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
rsip_ret_t r_rsip_p29f(const uint32_t InData_Text[],
                       const uint32_t InData_DataALen[],
                       const uint32_t InData_TextLen[],
                       uint32_t       OutData_Text[],
                       uint32_t       OutData_DataT[]);
rsip_ret_t r_rsip_p83f(const uint32_t InData_Text[],
                       const uint32_t InData_DataALen[],
                       const uint32_t InData_TextLen[],
                       uint32_t       OutData_Text[],
                       uint32_t       OutData_DataT[]);
rsip_ret_t r_rsip_p34f(const uint32_t InData_Text[],
                       const uint32_t InData_DataALen[],
                       const uint32_t InData_TextLen[],
                       uint32_t       OutData_Text[],
                       uint32_t       OutData_DataT[]);
rsip_ret_t r_rsip_p32f(const uint32_t InData_Text[],
                       const uint32_t InData_DataT[],
                       const uint32_t InData_DataALen[],
                       const uint32_t InData_TextLen[],
                       const uint32_t InData_DataTLen[],
                       uint32_t       OutData_Text[]);
rsip_ret_t r_rsip_p85f(const uint32_t InData_Text[],
                       const uint32_t InData_DataT[],
                       const uint32_t InData_DataALen[],
                       const uint32_t InData_TextLen[],
                       const uint32_t InData_DataTLen[],
                       uint32_t       OutData_Text[]);
rsip_ret_t r_rsip_p36f(const uint32_t InData_Text[],
                       const uint32_t InData_DataT[],
                       const uint32_t InData_DataALen[],
                       const uint32_t InData_TextLen[],
                       const uint32_t InData_DataTLen[],
                       uint32_t       OutData_Text[]);
rsip_ret_t r_rsip_p21(const uint32_t InData_HV[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_Text[],
                      uint32_t       OutData_DataT[],
                      uint32_t       MAX_CNT);

/* AES-CCM */
rsip_ret_t r_rsip_p95i(const uint32_t InData_KeyIndex[],
                       const uint32_t InData_IV[],
                       const uint32_t InData_Header[],
                       uint32_t       Header_Len);
void       r_rsip_p95u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
rsip_ret_t r_rsip_p95f(const uint32_t InData_Text[],
                       const uint32_t InData_TextLen[],
                       uint32_t       OutData_Text[],
                       uint32_t       OutData_MAC[]);
rsip_ret_t r_rsip_p98i(const uint32_t InData_KeyIndex[],
                       const uint32_t InData_IV[],
                       const uint32_t InData_Header[],
                       uint32_t       Header_Len);
void       r_rsip_p98u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
rsip_ret_t r_rsip_p98f(const uint32_t InData_Text[],
                       const uint32_t InData_TextLen[],
                       const uint32_t InData_MAC[],
                       const uint32_t InData_MACLength[],
                       uint32_t       OutData_Text[]);
rsip_ret_t r_rsip_pa7i(const uint32_t InData_KeyIndex[],
                       const uint32_t InData_IV[],
                       const uint32_t InData_Header[],
                       uint32_t       Header_Len);
void       r_rsip_pa7u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
rsip_ret_t r_rsip_pa7f(const uint32_t InData_Text[],
                       const uint32_t InData_TextLen[],
                       uint32_t       OutData_Text[],
                       uint32_t       OutData_MAC[]);
rsip_ret_t r_rsip_pb0i(const uint32_t InData_KeyIndex[],
                       const uint32_t InData_IV[],
                       const uint32_t InData_Header[],
                       uint32_t       Header_Len);
void       r_rsip_pb0u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
rsip_ret_t r_rsip_pb0f(const uint32_t InData_Text[],
                       const uint32_t InData_TextLen[],
                       const uint32_t InData_MAC[],
                       const uint32_t InData_MACLength[],
                       uint32_t       OutData_Text[]);
rsip_ret_t r_rsip_pa1i(const uint32_t InData_KeyIndex[],
                       const uint32_t InData_IV[],
                       const uint32_t InData_Header[],
                       uint32_t       Header_Len);
void       r_rsip_pa1u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
rsip_ret_t r_rsip_pa1f(const uint32_t InData_Text[],
                       const uint32_t InData_TextLen[],
                       uint32_t       OutData_Text[],
                       uint32_t       OutData_MAC[]);
rsip_ret_t r_rsip_pa4i(const uint32_t InData_KeyIndex[],
                       const uint32_t InData_IV[],
                       const uint32_t InData_Header[],
                       uint32_t       Header_Len);
void       r_rsip_pa4u(const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT);
rsip_ret_t r_rsip_pa4f(const uint32_t InData_Text[],
                       const uint32_t InData_TextLen[],
                       const uint32_t InData_MAC[],
                       const uint32_t InData_MACLength[],
                       uint32_t       OutData_Text[]);

/* AES-CMAC */
rsip_ret_t r_rsip_p41i(const uint32_t InData_KeyIndex[]);
rsip_ret_t r_rsip_p87i(const uint32_t InData_KeyIndex[]);
rsip_ret_t r_rsip_p44i(const uint32_t InData_KeyIndex[]);
void       r_rsip_p41u(const uint32_t InData_Text[], uint32_t MAX_CNT);
void       r_rsip_p87u(const uint32_t InData_Text[], uint32_t MAX_CNT);
void       r_rsip_p44u(const uint32_t InData_Text[], uint32_t MAX_CNT);
rsip_ret_t r_rsip_p41f(const uint32_t InData_Cmd[],
                       const uint32_t InData_Text[],
                       const uint32_t InData_DataT[],
                       const uint32_t InData_DataTLen[],
                       uint32_t       OutData_DataT[]);
rsip_ret_t r_rsip_p87f(const uint32_t InData_Cmd[],
                       const uint32_t InData_Text[],
                       const uint32_t InData_DataT[],
                       const uint32_t InData_DataTLen[],
                       uint32_t       OutData_DataT[]);
rsip_ret_t r_rsip_p44f(const uint32_t InData_Cmd[],
                       const uint32_t InData_Text[],
                       const uint32_t InData_DataT[],
                       const uint32_t InData_DataTLen[],
                       uint32_t       OutData_DataT[]);

/* ECDSA */
rsip_ret_t r_rsip_pf0(const uint32_t InData_CurveType[],
                      const uint32_t InData_Cmd[],
                      const uint32_t InData_KeyIndex[],
                      const uint32_t InData_MsgDgst[],
                      const uint32_t InData_DomainParam[],
                      uint32_t       OutData_Signature[]);
rsip_ret_t r_rsip_pf1(const uint32_t InData_CurveType[],
                      const uint32_t InData_Cmd[],
                      const uint32_t InData_KeyIndex[],
                      const uint32_t InData_MsgDgst[],
                      const uint32_t InData_Signature[],
                      const uint32_t InData_DomainParam[]);
rsip_ret_t r_rsip_pf5(const uint32_t InData_CurveType[],
                      const uint32_t InData_KeyIndex[],
                      const uint32_t InData_MsgDgst[],
                      const uint32_t InData_DomainParam[],
                      uint32_t       OutData_Signature[]);
rsip_ret_t r_rsip_pf6(const uint32_t InData_CurveType[],
                      const uint32_t InData_KeyIndex[],
                      const uint32_t InData_MsgDgst[],
                      const uint32_t InData_Signature[],
                      const uint32_t InData_DomainParam[]);
rsip_ret_t r_rsip_p7d(const uint32_t InData_KeyIndex[],
                      const uint32_t InData_MsgDgst[],
                      const uint32_t InData_DomainParam[],
                      uint32_t       OutData_Signature[]);
rsip_ret_t r_rsip_p7e(const uint32_t InData_KeyIndex[],
                      const uint32_t InData_MsgDgst[],
                      const uint32_t InData_Signature[],
                      const uint32_t InData_DomainParam[]);
rsip_ret_t r_rsip_p11(const uint32_t InData_KeyIndex[],
                      const uint32_t InData_MsgDgst[],
                      const uint32_t InData_DomainParam[],
                      uint32_t       OutData_Signature[]);
rsip_ret_t r_rsip_p12(const uint32_t InData_KeyIndex[],
                      const uint32_t InData_MsgDgst[],
                      const uint32_t InData_Signature[],
                      const uint32_t InData_DomainParam[]);

/* EdDSA */
rsip_ret_t r_rsip_p4c(const uint32_t InData_PrivKeyIndex[],
                      const uint32_t InData_PubKeyIndex[],
                      const uint32_t InData_Msg[],
                      const uint32_t InData_MsgLen[],
                      const uint32_t InData_DomainParam[],
                      uint32_t       OutData_Signature[],
                      uint64_t       MAX_CNT);
rsip_ret_t r_rsip_p4d(const uint32_t InData_KeyIndex[],
                      const uint32_t InData_Msg[],
                      const uint32_t InData_MsgLen[],
                      const uint32_t InData_Signature[],
                      const uint32_t InData_DomainParam[],
                      uint64_t       MAX_CNT);

/* RSA */
rsip_ret_t r_rsip_p53(const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[]);
rsip_ret_t r_rsip_p54(const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[]);
rsip_ret_t r_rsip_p56(const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[]);
rsip_ret_t r_rsip_p57(const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[]);
rsip_ret_t r_rsip_p79(const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[]);
rsip_ret_t r_rsip_p7a(const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[]);
rsip_ret_t r_rsip_p7b(const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[]);
rsip_ret_t r_rsip_p7c(const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[]);

/* SHA */
rsip_ret_t r_rsip_p70i(const uint32_t InData_HashType[], const uint32_t InData_MsgLen[]);
rsip_ret_t r_rsip_p70r(const uint32_t InData_HashType[], const uint32_t InData_State[]);
rsip_ret_t r_rsip_p70u(const uint32_t InData_Msg[], uint32_t MAX_CNT);
rsip_ret_t r_rsip_p70s(uint32_t OutData_State[]);
rsip_ret_t r_rsip_p70f(const uint32_t InData_Msg[], uint32_t MAX_CNT, uint32_t OutData_MsgDigest[]);

/* HMAC */
rsip_ret_t r_rsip_p75i(const uint32_t InData_KeyIndex[],
                       const uint32_t InData_HashType[],
                       const uint32_t InData_MsgLen[],
                       uint32_t       KEY_INDEX_SIZE);
rsip_ret_t r_rsip_p75r(const uint32_t InData_KeyIndex[],
                       const uint32_t InData_HashType[],
                       const uint32_t InData_State[],
                       uint32_t       KEY_INDEX_SIZE);
rsip_ret_t r_rsip_p75u(const uint32_t InData_Msg[], uint32_t MAX_CNT);
rsip_ret_t r_rsip_p75s(uint32_t OutData_State[]);
rsip_ret_t r_rsip_p75f(const uint32_t InData_Cmd[],
                       const uint32_t InData_Msg[],
                       const uint32_t InData_MAC[],
                       const uint32_t InData_length[],
                       uint32_t       MAX_CNT,
                       uint32_t       OutData_MAC[]);

/* ECDH */
rsip_ret_t r_rsip_pe2(const uint32_t InData_CurveType[],
                      const uint32_t InData_PubKeyType[],
                      const uint32_t InData_PubKey[],
                      const uint32_t InData_KeyIndex[],
                      const uint32_t InData_DomainParam[],
                      uint32_t       OutData_EncSecret[]);
rsip_ret_t r_rsip_p4e(const uint32_t InData_CurveType[],
                      const uint32_t InData_PubKeyType[],
                      const uint32_t InData_PubKey[],
                      const uint32_t InData_KeyIndex[],
                      const uint32_t InData_DomainParam[],
                      uint32_t       OutData_EncSecret[]);
rsip_ret_t r_rsip_p5e(const uint32_t InData_PubKeyType[],
                      const uint32_t InData_PubKey[],
                      const uint32_t InData_KeyIndex[],
                      const uint32_t InData_DomainParam[],
                      uint32_t       OutData_EncSecret[]);
rsip_ret_t r_rsip_p4f(const uint32_t InData_PubKeyType[],
                      const uint32_t InData_PubKey[],
                      const uint32_t InData_KeyIndex[],
                      const uint32_t InData_DomainParam[],
                      uint32_t       OutData_EncSecret[]);

/* PKI root certificate */
rsip_ret_t r_rsip_pe0(const uint32_t InData_Sel_KeyType[],
                      const uint32_t InData_RootCertificate[],
                      const uint32_t InData_RootCertificateInfo[],
                      const uint32_t InData_RootCertificatePubKey[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_pe8(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      const uint32_t InData_RootCertificateLength[],
                      uint32_t       OutData_RootCertificate[],
                      uint32_t       OutData_RootCertificateInfo[],
                      const uint32_t MAX_CNT);

/* PKI */
rsip_ret_t r_rsip_pe1(const uint32_t InData_Sel_KeyType[],
                      const uint32_t InData_HashType[],
                      const uint32_t InData_Certificate[],
                      const uint32_t InData_CertificateLength[],
                      const uint32_t InData_CertificatePubKey[],
                      const uint32_t InData_EncCertificateInfo[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_pedi(const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[]);
rsip_ret_t r_rsip_pedf(const uint32_t InData_SignatureType[],
                       const uint32_t InData_HashType[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_Salt[],
                       const uint32_t InData_SaltLength[],
                       uint32_t       OutData_EncCertificateInfo[]);
rsip_ret_t r_rsip_peei(const uint32_t InData_CurveType[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_Signature[],
                       const uint32_t InData_DomainParam[]);
rsip_ret_t r_rsip_peef(uint32_t OutData_EncCertificateInfo[]);
rsip_ret_t r_rsip_p51i(const uint32_t InData_CurveType[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_Signature[],
                       const uint32_t InData_DomainParam[]);
rsip_ret_t r_rsip_p51f(uint32_t OutData_EncCertificateInfo[]);
rsip_ret_t r_rsip_p52i(const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_Signature[],
                       const uint32_t InData_DomainParam[]);
rsip_ret_t r_rsip_p52f(uint32_t OutData_EncCertificateInfo[]);
rsip_ret_t r_rsip_p5fi(const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_Signature[],
                       const uint32_t InData_DomainParam[]);
rsip_ret_t r_rsip_p5ff(uint32_t OutData_EncCertificateInfo[]);

/* KDF */
rsip_ret_t r_rsip_pe3(const uint32_t InData_HashType[],
                      const uint32_t InData_CurveType[],
                      const uint32_t InData_EncSecret[],
                      uint32_t       OutData_EncMsg[]);
rsip_ret_t r_rsip_pe4(const uint32_t InData_HashType[],
                      const uint32_t InData_CurveType[],
                      const uint32_t InData_EncSecret[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_pe5i(const uint32_t InData_KeyType[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_HashType[],
                       const uint32_t InData_MsgLen[]);
rsip_ret_t r_rsip_pe5r(const uint32_t InData_KeyType[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_HashType[],
                       const uint32_t InData_State[]);
rsip_ret_t r_rsip_pe5e(const uint32_t InData_EncMsg[], const uint32_t MAX_CNT2);
rsip_ret_t r_rsip_pe5u(const uint32_t InData_Msg[], const uint32_t MAX_CNT);
rsip_ret_t r_rsip_pe5s(uint32_t OutData_State[]);
rsip_ret_t r_rsip_pe5f(const uint32_t InData_Msg[],
                       const uint32_t InData_EncMsg[],
                       uint32_t       OutData_KDFInfo[],
                       const uint32_t MAX_CNT,
                       const uint32_t MAX_CNT2);
rsip_ret_t r_rsip_pe6(const uint32_t InData_HashType[],
                      const uint32_t InData_KDFInfo[],
                      const uint32_t InData_KDFInfo_Count[],
                      const uint32_t InData_OutDataLength[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_pe7(const uint32_t InData_HashType[],
                      const uint32_t InData_KDFInfo[],
                      const uint32_t InData_KDFInfo_Count[],
                      const uint32_t InData_OutDataType[],
                      const uint32_t InData_OutDataLocation[],
                      const uint32_t InData_SeqNum[],
                      uint32_t       OutData_HMACKeyIndex[],
                      uint32_t       OutData_KeyIndex[],
                      uint32_t       OutData_EncIV[]);
rsip_ret_t r_rsip_pe9(const uint32_t InData_HashType[],
                      const uint32_t InData_Hash[],
                      const uint32_t InData_KeyIndex[],
                      const uint32_t InData_FinishedLabel[],
                      uint32_t       OutData_VerifyData[]);

/* TLS1.2 RSA key exchange */
rsip_ret_t r_rsip_pea(uint32_t OutData_EncPreMasterSecret[]);
rsip_ret_t r_rsip_peb(const uint32_t InData_KeyIndex[],
                      const uint32_t InData_EncPreMasterSecret[],
                      uint32_t       OutData_EncPreMasterSecret[]);
rsip_ret_t r_rsip_pec(const uint32_t InData_KeyIndex[],
                      const uint32_t InData_EncPreMasterSecret[],
                      uint32_t       OutData_KeyIndex[]);

/* Secure boot */
rsip_ret_t r_rsip_p03(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_InstData[],
                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_p15(const uint32_t InData_SharedKeyNum[],
                      const uint32_t InData_SharedKeyIndex[],
                      const uint32_t InData_SessionKey[],
                      const uint32_t InData_IV[],
                      const uint32_t InData_EncAuthData[],
                      const uint32_t InData_HashType[],
                      uint32_t       OutData_Hash[]);
rsip_ret_t r_rsip_p24(const uint32_t InData_Cmd[],
                      const uint32_t InData_KeyCertificate[],
                      const uint32_t InData_KeyCertificateLength[],
                      const uint32_t InData_KeyCertificateSignature[],
                      const uint32_t InData_KeyCertificatePubKey[],
                      const uint32_t InData_ImgPkHash[],
                      const uint32_t InData_OemRootPkHash[],
                      const uint32_t InData_CodeCertificate[],
                      const uint32_t InData_CodeCertificateLength[],
                      const uint32_t InData_CodeCertificateSignature[],
                      const uint32_t InData_CodeCertificatePubKey[],
                      const uint32_t InData_ImageHash[],
                      const uint32_t InData_Image[],
                      uint32_t       MAX_CNT);

rsip_ret_t r_rsip_p47i(const uint32_t InData_Cmd[], const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
void       r_rsip_p47u(const uint32_t InData_Text[], uint32_t OutData_Text[], const uint32_t MAX_CNT);
rsip_ret_t r_rsip_p47f(void);

/* OTF */
rsip_ret_t r_rsip_pba(const uint32_t InData_Cmd[], const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[]);
rsip_ret_t r_rsip_pbc(const uint32_t InData_Cmd[], const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[]);

#endif                                 /* R_RSIP_PRIMITIVE_H */
