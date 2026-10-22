/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_TSIP_ERR_H
#define R_TSIP_ERR_H

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Return code of internal function */
typedef enum e_tsip_ret
{
    /* Success */
    TSIP_RET_PASS,

    /* Branching */
    TSIP_RET_PASS_0,
    TSIP_RET_PASS_1,
    TSIP_RET_PASS_2,

    /* Error */
    TSIP_RET_RESOURCE_CONFLICT,
    TSIP_RET_RETRY,
    TSIP_RET_FAIL,
    TSIP_RET_KEY_FAIL,
    TSIP_RET_PARAM_FAIL,
    TSIP_RET_VERIFICATION_FAIL,
    TSIP_RET_AUTH_FAIL,
    TSIP_RET_LIFECYCLE_FAIL,
    TSIP_RET_VERSION_MATCH,
    TSIP_RET_UNKNOWN
} tsip_ret_t;

#endif                                 /* R_TSIP_ERR_H */
