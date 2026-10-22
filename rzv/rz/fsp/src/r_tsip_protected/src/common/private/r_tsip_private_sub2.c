/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_tsip_private.h"

#if (3U == TSIP_PRV_HASH_IP_TYPE) || (5U == TSIP_PRV_HASH_IP_TYPE)

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

 #define TSIP_PRV_SHA_INIT_VAL1                             (0xffffffffU)
 #define TSIP_PRV_SHA_INIT_VAL2                             (0xfffffc00U)
 #define TSIP_PRV_INTERNAL_STATE_OVERWRITE_BASE_SHA1SHA2    (16U)
 #define TSIP_PRV_INTERNAL_STATE_OVERWRITE_BASE_SHA3        (50U)

 #define TSIP_PRV_WORD_SIZE_HMAC_MAC_BUFFER                 (16U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

typedef enum e_tsip_hmac_cmd
{
    TSIP_HMAC_CMD_SIGN   = 0U,
    TSIP_HMAC_CMD_VERIFY = 1U,
} tsip_hmac_cmd_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

static bool hash_type_is_sha3(tsip_hash_type_t hash_type);
static bool hmac_type_is_sha3(tsip_key_type_extend_t key_type_ext);

static void overwrite_internal_state_sha1sha2(uint32_t * internal_state, uint64_t buffered_length,
                                              uint64_t input_length);
static void overwrite_internal_state_sha3(uint32_t * internal_state, uint64_t buffered_length);

static void overwrite_internal_state_sha(tsip_sha_handle_t * p_handle);
static void overwrite_internal_state_hmac(tsip_hmac_handle_t * p_handle);
static void overwrite_internal_state_kdf_sha(tsip_kdf_sha_handle_t * p_handle);
static void overwrite_internal_state_kdf_hmac(tsip_kdf_hmac_handle_t * p_handle);

TSIP_PRV_STATIC_INLINE const tsip_func_subset_sha_t      * get_hash_func(tsip_hash_type_t hash_type);
TSIP_PRV_STATIC_INLINE const tsip_func_subset_hmac_t     * get_hmac_func(tsip_key_type_extend_t key_type_ext);
TSIP_PRV_STATIC_INLINE const tsip_func_subset_kdf_sha_t  * get_kdf_hash_func(tsip_hash_type_t hash_type);
TSIP_PRV_STATIC_INLINE const tsip_func_subset_kdf_hmac_t * get_kdf_hmac_func(tsip_key_type_extend_t key_type_ext);
TSIP_PRV_STATIC_INLINE uint32_t                            get_cmd_kdf_hmac_alg(uint8_t alg);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

static const uint32_t gs_sha_hash_type[TSIP_HASH_TYPE_NUM] =
{
    [TSIP_HASH_TYPE_SHA1]       = BSWAP_32BIG_C(0U),
    [TSIP_HASH_TYPE_SHA224]     = BSWAP_32BIG_C(1U),
    [TSIP_HASH_TYPE_SHA256]     = BSWAP_32BIG_C(2U),
    [TSIP_HASH_TYPE_SHA384]     = BSWAP_32BIG_C(5U),
    [TSIP_HASH_TYPE_SHA512]     = BSWAP_32BIG_C(6U),
    [TSIP_HASH_TYPE_SHA512_224] = BSWAP_32BIG_C(3U),
    [TSIP_HASH_TYPE_SHA512_256] = BSWAP_32BIG_C(4U),
};

static const uint32_t gs_hmac_hash_type[TSIP_PRV_KEY_SUBTYPE_HMAC_NUM] =
{
    [TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1]   = BSWAP_32BIG_C(0U),
    [TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224] = BSWAP_32BIG_C(1U),
    [TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256] = BSWAP_32BIG_C(2U),
    [TSIP_PRV_KEY_SUBTYPE_HMAC_SHA384] = BSWAP_32BIG_C(5U),
    [TSIP_PRV_KEY_SUBTYPE_HMAC_SHA512] = BSWAP_32BIG_C(6U),
};

static const uint32_t gs_hmac_cmd[] =
{
    [TSIP_HMAC_CMD_SIGN]   = BSWAP_32BIG_C(0U),
    [TSIP_HMAC_CMD_VERIFY] = BSWAP_32BIG_C(1U),
};

static const uint32_t gs_kdf_sha_hash_type[] =
{
    [TSIP_HASH_TYPE_SHA256] = BSWAP_32BIG_C(0U),
    [TSIP_HASH_TYPE_SHA384] = BSWAP_32BIG_C(1U),
};

static const uint32_t gs_kdf_hmac_hash_type[] =
{
    [TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256] = BSWAP_32BIG_C(0U),
    [TSIP_PRV_KEY_SUBTYPE_HMAC_SHA384] = BSWAP_32BIG_C(1U),
    [TSIP_PRV_KEY_SUBTYPE_HMAC_SHA512] = BSWAP_32BIG_C(2U),
};

static const uint32_t gs_sha_msg_len_multi[2] =
{
    TSIP_PRV_SHA_INIT_VAL1, TSIP_PRV_SHA_INIT_VAL2
};

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

tsip_ret_t r_tsip_sha_hash_init_update (tsip_sha_handle_t * p_handle, const uint8_t * p_message,
                                        uint64_t message_length)
{
    const tsip_func_subset_sha_t * p_func = get_hash_func(p_handle->type);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = p_func->p_init(&gs_sha_hash_type[p_handle->type], gs_sha_msg_len_multi);
    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret =
            p_func->p_update((const uint32_t *) p_message, r_tsip_byte_to_word_convert((uint32_t) message_length));
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_sha_hash_resume_update (tsip_sha_handle_t * p_handle,
                                          const uint8_t     * p_message,
                                          uint64_t            message_length)
{
    const tsip_func_subset_sha_t * p_func = get_hash_func(p_handle->type);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = p_func->p_resume(&gs_sha_hash_type[p_handle->type], p_handle->internal_state);
    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret =
            p_func->p_update((const uint32_t *) p_message, r_tsip_byte_to_word_convert((uint32_t) message_length));
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_sha_hash_update (tsip_sha_handle_t * p_handle, const uint8_t * p_message, uint64_t message_length)
{
    const tsip_func_subset_sha_t * p_func = get_hash_func(p_handle->type);

    /* Call function (cast to match the argument type with the primitive function) */
    return p_func->p_update((const uint32_t *) p_message, r_tsip_byte_to_word_convert((uint32_t) message_length));
}

tsip_ret_t r_tsip_sha_hash_suspend (tsip_sha_handle_t * p_handle)
{
    const tsip_func_subset_sha_t * p_func = get_hash_func(p_handle->type);

    /* Call function (cast to match the argument type with the primitive function) */
    return p_func->p_suspend(p_handle->internal_state);
}

tsip_ret_t r_tsip_sha_hash_init_final (tsip_hash_type_t hash_type,
                                       const uint8_t  * p_message,
                                       uint64_t         message_length,
                                       uint8_t        * p_digest)
{
    const tsip_func_subset_sha_t * p_func = get_hash_func(hash_type);

    uint32_t msg_len[2] =
    {
        r_tsip_byte_to_bit_convert_upper(message_length),
        r_tsip_byte_to_bit_convert_lower(message_length)
    };

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = p_func->p_init(&gs_sha_hash_type[hash_type], msg_len);
    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret =
            p_func->p_final((const uint32_t *) p_message, r_tsip_byte_to_word_convert((uint32_t) message_length),
                            (uint32_t *) p_digest);
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_sha_hash_resume_final (tsip_sha_handle_t * p_handle, uint8_t * p_digest)
{
    const tsip_func_subset_sha_t * p_func = get_hash_func(p_handle->type);

    overwrite_internal_state_sha(p_handle);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = p_func->p_resume(&gs_sha_hash_type[p_handle->type], p_handle->internal_state);
    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret =
            p_func->p_final((const uint32_t *) p_handle->buffer,
                            r_tsip_byte_to_word_convert(p_handle->buffered_length),
                            (uint32_t *) p_digest);
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_sha_hash_final (tsip_sha_handle_t * p_handle, uint8_t * p_digest)
{
    const tsip_func_subset_sha_t * p_func = get_hash_func(p_handle->type);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = p_func->p_suspend(p_handle->internal_state);
    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret = r_tsip_sha_hash_resume_final(p_handle, p_digest);
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_hmac_init_update (tsip_hmac_handle_t * p_handle, const uint8_t * p_message, uint64_t message_length)
{
    tsip_wrapped_key_t            * p_wrapped_key = &p_handle->wrapped_key;
    tsip_key_type_extend_t          key_type_ext  = r_tsip_key_type_parse(p_wrapped_key->type);
    const tsip_func_subset_hmac_t * p_func        = get_hmac_func(key_type_ext);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret =
        p_func->p_init((uint32_t *) p_wrapped_key->p_value,
                       &gs_hmac_hash_type[key_type_ext.subtype],
                       gs_sha_msg_len_multi,
                       r_tsip_byte_to_word_convert(TSIP_BYTE_SIZE_WRAPPED_KEY(p_wrapped_key->type)));
    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret =
            p_func->p_update((const uint32_t *) p_message, r_tsip_byte_to_word_convert((uint32_t) message_length));
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_hmac_resume_update (tsip_hmac_handle_t * p_handle, const uint8_t * p_message, uint64_t message_length)
{
    tsip_wrapped_key_t            * p_wrapped_key = &p_handle->wrapped_key;
    tsip_key_type_extend_t          key_type_ext  = r_tsip_key_type_parse(p_wrapped_key->type);
    const tsip_func_subset_hmac_t * p_func        = get_hmac_func(key_type_ext);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret =
        p_func->p_resume((uint32_t *) p_wrapped_key->p_value,
                         &gs_hmac_hash_type[key_type_ext.subtype],
                         p_handle->internal_state,
                         r_tsip_byte_to_word_convert(TSIP_BYTE_SIZE_WRAPPED_KEY(p_wrapped_key->type)));
    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret =
            p_func->p_update((const uint32_t *) p_message, r_tsip_byte_to_word_convert((uint32_t) message_length));
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_hmac_update (tsip_hmac_handle_t * p_handle, const uint8_t * p_message, uint64_t message_length)
{
    tsip_key_type_extend_t          key_type_ext = r_tsip_key_type_parse(p_handle->wrapped_key.type);
    const tsip_func_subset_hmac_t * p_func       = get_hmac_func(key_type_ext);

    /* Call function (cast to match the argument type with the primitive function) */
    return p_func->p_update((const uint32_t *) p_message, r_tsip_byte_to_word_convert((uint32_t) message_length));
}

tsip_ret_t r_tsip_hmac_suspend (tsip_hmac_handle_t * p_handle)
{
    tsip_key_type_extend_t          key_type_ext = r_tsip_key_type_parse(p_handle->wrapped_key.type);
    const tsip_func_subset_hmac_t * p_func       = get_hmac_func(key_type_ext);

    /* Call function (cast to match the argument type with the primitive function) */
    return p_func->p_suspend(p_handle->internal_state);
}

tsip_ret_t r_tsip_hmac_init_final (const tsip_wrapped_key_t * p_wrapped_key,
                                   const uint8_t            * p_message,
                                   uint64_t                   message_length,
                                   uint8_t                  * p_mac)
{
    tsip_key_type_extend_t          key_type_ext = r_tsip_key_type_parse(p_wrapped_key->type);
    const tsip_func_subset_hmac_t * p_func       = get_hmac_func(key_type_ext);

    uint32_t msg_len[2] =
    {
        r_tsip_byte_to_bit_convert_upper(message_length),
        r_tsip_byte_to_bit_convert_lower(message_length)
    };

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret =
        p_func->p_init((uint32_t *) p_wrapped_key->p_value,
                       &gs_hmac_hash_type[key_type_ext.subtype],
                       msg_len,
                       r_tsip_byte_to_word_convert(TSIP_BYTE_SIZE_WRAPPED_KEY(p_wrapped_key->type)));
    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret =
            p_func->p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_SIGN],
                            (const uint32_t *) p_message,
                            NULL,
                            NULL,
                            r_tsip_byte_to_word_convert((uint32_t) message_length),
                            (uint32_t *) p_mac);
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_hmac_resume_final (tsip_hmac_handle_t * p_handle, uint8_t * p_mac)
{
    tsip_wrapped_key_t            * p_wrapped_key = &p_handle->wrapped_key;
    tsip_key_type_extend_t          key_type_ext  = r_tsip_key_type_parse(p_wrapped_key->type);
    const tsip_func_subset_hmac_t * p_func        = get_hmac_func(key_type_ext);

    overwrite_internal_state_hmac(p_handle);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret =
        p_func->p_resume((uint32_t *) p_wrapped_key->p_value,
                         &gs_hmac_hash_type[key_type_ext.subtype],
                         p_handle->internal_state,
                         r_tsip_byte_to_word_convert(TSIP_BYTE_SIZE_WRAPPED_KEY(p_wrapped_key->type)));
    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret =
            p_func->p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_SIGN],
                            (const uint32_t *) p_handle->buffer,
                            NULL,
                            NULL,
                            r_tsip_byte_to_word_convert(p_handle->buffered_length),
                            (uint32_t *) p_mac);
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_hmac_final (tsip_hmac_handle_t * p_handle, uint8_t * p_mac)
{
    tsip_key_type_extend_t          key_type_ext = r_tsip_key_type_parse(p_handle->wrapped_key.type);
    const tsip_func_subset_hmac_t * p_func       = get_hmac_func(key_type_ext);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = p_func->p_suspend(p_handle->internal_state);
    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret = r_tsip_hmac_resume_final(p_handle, p_mac);
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_hmac_init_verify (const tsip_wrapped_key_t * p_wrapped_key,
                                    const uint8_t            * p_message,
                                    uint64_t                   message_length,
                                    const uint8_t            * p_mac,
                                    uint32_t                   mac_length)
{
    tsip_key_type_extend_t          key_type_ext = r_tsip_key_type_parse(p_wrapped_key->type);
    const tsip_func_subset_hmac_t * p_func       = get_hmac_func(key_type_ext);

    uint32_t msg_len[2] =
    {
        r_tsip_byte_to_bit_convert_upper(message_length),
        r_tsip_byte_to_bit_convert_lower(message_length)
    };
    uint32_t InData_MAC[TSIP_PRV_WORD_SIZE_HMAC_MAC_BUFFER] =
    {
        0
    };
    memcpy(InData_MAC, p_mac, mac_length);
    uint32_t mac_len[1] =
    {
        bswap_32big(mac_length)
    };

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret =
        p_func->p_init((uint32_t *) p_wrapped_key->p_value,
                       &gs_hmac_hash_type[key_type_ext.subtype],
                       msg_len,
                       r_tsip_byte_to_word_convert(TSIP_BYTE_SIZE_WRAPPED_KEY(p_wrapped_key->type)));
    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret =
            p_func->p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_VERIFY],
                            (const uint32_t *) p_message,
                            InData_MAC,
                            mac_len,
                            r_tsip_byte_to_word_convert((uint32_t) message_length),
                            (uint32_t *) NULL);
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_hmac_resume_verify (tsip_hmac_handle_t * p_handle, const uint8_t * p_mac, uint32_t mac_length)
{
    tsip_wrapped_key_t            * p_wrapped_key = &p_handle->wrapped_key;
    tsip_key_type_extend_t          key_type_ext  = r_tsip_key_type_parse(p_wrapped_key->type);
    const tsip_func_subset_hmac_t * p_func        = get_hmac_func(key_type_ext);

    overwrite_internal_state_hmac(p_handle);

    uint32_t InData_MAC[TSIP_PRV_WORD_SIZE_HMAC_MAC_BUFFER] =
    {
        0
    };
    memcpy(InData_MAC, p_mac, mac_length);
    uint32_t mac_len[1] =
    {
        bswap_32big(mac_length)
    };

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret =
        p_func->p_resume((uint32_t *) p_wrapped_key->p_value,
                         &gs_hmac_hash_type[key_type_ext.subtype],
                         p_handle->internal_state,
                         r_tsip_byte_to_word_convert(TSIP_BYTE_SIZE_WRAPPED_KEY(p_wrapped_key->type)));
    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret =
            p_func->p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_VERIFY],
                            (const uint32_t *) p_handle->buffer,
                            InData_MAC,
                            mac_len,
                            r_tsip_byte_to_word_convert(p_handle->buffered_length),
                            (uint32_t *) NULL);
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_hmac_verify (tsip_hmac_handle_t * p_handle, const uint8_t * p_mac, uint32_t mac_length)
{
    tsip_key_type_extend_t          key_type_ext = r_tsip_key_type_parse(p_handle->wrapped_key.type);
    const tsip_func_subset_hmac_t * p_func       = get_hmac_func(key_type_ext);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = p_func->p_suspend(p_handle->internal_state);
    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret = r_tsip_hmac_resume_verify(p_handle, p_mac, mac_length);
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_kdf_sha_init_update (tsip_kdf_sha_handle_t * p_handle,
                                       const uint8_t         * p_message,
                                       uint64_t                message_length)
{
    const tsip_func_subset_kdf_sha_t * p_func = get_kdf_hash_func(p_handle->type);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = p_func->p_init(&gs_kdf_sha_hash_type[p_handle->type], gs_sha_msg_len_multi);
    if (TSIP_RET_PASS == tsip_ret)
    {
        uint32_t msg1_len[1]    = {bswap_32big(r_tsip_byte_to_word_convert(p_handle->buffered_length1))};
        uint32_t enc_msg_len[1] = {bswap_32big(r_tsip_byte_to_word_convert(p_handle->actual_wrapped_msg_length))};
        uint32_t msg2_len[1]    = {bswap_32big(r_tsip_byte_to_word_convert((uint32_t) message_length))};

        tsip_ret = p_func->p_update((const uint32_t *) p_handle->buffer1,
                                    msg1_len,
                                    (const uint32_t *) p_handle->wrapped_msg,
                                    enc_msg_len,
                                    (const uint32_t *) p_message,
                                    msg2_len);
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_kdf_sha_resume_update (tsip_kdf_sha_handle_t * p_handle,
                                         const uint8_t         * p_message,
                                         uint64_t                message_length)
{
    const tsip_func_subset_kdf_sha_t * p_func = get_kdf_hash_func(p_handle->type);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = p_func->p_resume(&gs_kdf_sha_hash_type[p_handle->type], p_handle->internal_state);
    if (TSIP_RET_PASS == tsip_ret)
    {
        uint32_t msg1_len[1]    = {bswap_32big(r_tsip_byte_to_word_convert(p_handle->buffered_length1))};
        uint32_t enc_msg_len[1] = {bswap_32big(r_tsip_byte_to_word_convert(p_handle->actual_wrapped_msg_length))};
        uint32_t msg2_len[1]    = {bswap_32big(r_tsip_byte_to_word_convert((uint32_t) message_length))};

        tsip_ret = p_func->p_update((const uint32_t *) p_handle->buffer1,
                                    msg1_len,
                                    (const uint32_t *) p_handle->wrapped_msg,
                                    enc_msg_len,
                                    (const uint32_t *) p_message,
                                    msg2_len);
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_kdf_sha_update (tsip_kdf_sha_handle_t * p_handle, const uint8_t * p_message, uint64_t message_length)
{
    const tsip_func_subset_kdf_sha_t * p_func = get_kdf_hash_func(p_handle->type);
    uint32_t msg1_len[1]    = {bswap_32big(r_tsip_byte_to_word_convert(p_handle->buffered_length1))};
    uint32_t enc_msg_len[1] = {bswap_32big(r_tsip_byte_to_word_convert(p_handle->actual_wrapped_msg_length))};
    uint32_t msg2_len[1]    = {bswap_32big(r_tsip_byte_to_word_convert((uint32_t) message_length))};

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = p_func->p_update((const uint32_t *) p_handle->buffer1,
                                           msg1_len,
                                           (const uint32_t *) p_handle->wrapped_msg,
                                           enc_msg_len,
                                           (const uint32_t *) p_message,
                                           msg2_len);

    return tsip_ret;
}

tsip_ret_t r_tsip_kdf_sha_suspend (tsip_kdf_sha_handle_t * p_handle)
{
    const tsip_func_subset_kdf_sha_t * p_func = get_kdf_hash_func(p_handle->type);

    /* Call function (cast to match the argument type with the primitive function) */
    return p_func->p_suspend(p_handle->internal_state);
}

tsip_ret_t r_tsip_kdf_sha_init_final (tsip_kdf_sha_handle_t * p_handle, uint8_t * p_digest)
{
    const tsip_func_subset_kdf_sha_t * p_func = get_kdf_hash_func(p_handle->type);
    uint64_t total_length = p_handle->buffered_length1 + p_handle->actual_wrapped_msg_length +
                            p_handle->buffered_length2;

    uint32_t msg_len[2] =
    {
        r_tsip_byte_to_bit_convert_upper(total_length),
        r_tsip_byte_to_bit_convert_lower(total_length)
    };

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = p_func->p_init(&gs_kdf_sha_hash_type[p_handle->type], msg_len);
    if (TSIP_RET_PASS == tsip_ret)
    {
        uint32_t msg1_len[1]    = {bswap_32big(r_tsip_byte_to_word_convert(p_handle->buffered_length1))};
        uint32_t enc_msg_len[1] = {bswap_32big(r_tsip_byte_to_word_convert(p_handle->actual_wrapped_msg_length))};
        uint32_t msg2_len[1]    = {bswap_32big(r_tsip_byte_to_word_convert(p_handle->buffered_length2))};

        tsip_ret = p_func->p_final((const uint32_t *) p_handle->buffer1,
                                   msg1_len,
                                   (const uint32_t *) p_handle->wrapped_msg,
                                   enc_msg_len,
                                   (const uint32_t *) p_handle->buffer2,
                                   msg2_len,
                                   (uint32_t *) p_digest);
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_kdf_sha_resume_final (tsip_kdf_sha_handle_t * p_handle, uint8_t * p_digest)
{
    const tsip_func_subset_kdf_sha_t * p_func = get_kdf_hash_func(p_handle->type);

    overwrite_internal_state_kdf_sha(p_handle);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = p_func->p_resume(&gs_kdf_sha_hash_type[p_handle->type], p_handle->internal_state);
    if (TSIP_RET_PASS == tsip_ret)
    {
        uint32_t msg1_len[1]    = {bswap_32big(r_tsip_byte_to_word_convert(p_handle->buffered_length1))};
        uint32_t enc_msg_len[1] = {bswap_32big(r_tsip_byte_to_word_convert(p_handle->actual_wrapped_msg_length))};
        uint32_t msg2_len[1]    = {bswap_32big(r_tsip_byte_to_word_convert(p_handle->buffered_length2))};

        tsip_ret = p_func->p_final((const uint32_t *) p_handle->buffer1,
                                   msg1_len,
                                   (const uint32_t *) p_handle->wrapped_msg,
                                   enc_msg_len,
                                   (const uint32_t *) p_handle->buffer2,
                                   msg2_len,
                                   (uint32_t *) p_digest);
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_kdf_sha_final (tsip_kdf_sha_handle_t * p_handle, uint8_t * p_digest)
{
    const tsip_func_subset_kdf_sha_t * p_func = get_kdf_hash_func(p_handle->type);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = p_func->p_suspend(p_handle->internal_state);
    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret = r_tsip_kdf_sha_resume_final(p_handle, p_digest);
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_kdf_hmac_init_update (tsip_kdf_hmac_handle_t * p_handle,
                                        const uint8_t          * p_message,
                                        uint64_t                 message_length)
{
    tsip_key_type_extend_t              key_type_ext = r_tsip_key_type_parse(p_handle->wrapped_key.type);
    uint32_t                            cmd_key_type = get_cmd_kdf_hmac_alg(key_type_ext.alg);
    const tsip_func_subset_kdf_hmac_t * p_func       = get_kdf_hmac_func(key_type_ext);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret =
        p_func->p_init(&cmd_key_type, (const uint32_t *) p_handle->wrapped_key.p_value,
                       &gs_kdf_hmac_hash_type[key_type_ext.subtype], gs_sha_msg_len_multi);

    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret =
            p_func->p_enc_update((const uint32_t *) p_handle->wrapped_msg,
                                 r_tsip_byte_to_word_convert(p_handle->wrapped_msg_length));
        if (TSIP_RET_PASS == tsip_ret)
        {
            tsip_ret =
                p_func->p_update((const uint32_t *) p_message, r_tsip_byte_to_word_convert((uint32_t) message_length));
        }
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_kdf_hmac_resume_update (tsip_kdf_hmac_handle_t * p_handle,
                                          const uint8_t          * p_message,
                                          uint64_t                 message_length)
{
    tsip_key_type_extend_t              key_type_ext = r_tsip_key_type_parse(p_handle->wrapped_key.type);
    uint32_t                            cmd_key_type = get_cmd_kdf_hmac_alg(key_type_ext.alg);
    const tsip_func_subset_kdf_hmac_t * p_func       = get_kdf_hmac_func(key_type_ext);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret =
        p_func->p_resume(&cmd_key_type, (uint32_t *) p_handle->wrapped_key.p_value,
                         &gs_kdf_hmac_hash_type[key_type_ext.subtype], p_handle->internal_state);

    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret =
            p_func->p_enc_update((const uint32_t *) p_handle->wrapped_msg,
                                 r_tsip_byte_to_word_convert(p_handle->wrapped_msg_length));
        if (TSIP_RET_PASS == tsip_ret)
        {
            tsip_ret =
                p_func->p_update((const uint32_t *) p_message, r_tsip_byte_to_word_convert((uint32_t) message_length));
        }
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_kdf_hmac_update (tsip_kdf_hmac_handle_t * p_handle, const uint8_t * p_message,
                                   uint64_t message_length)
{
    tsip_key_type_extend_t              key_type_ext = r_tsip_key_type_parse(p_handle->wrapped_key.type);
    const tsip_func_subset_kdf_hmac_t * p_func       = get_kdf_hmac_func(key_type_ext);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = p_func->p_enc_update(NULL, 0);
    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret =
            p_func->p_update((const uint32_t *) p_message, r_tsip_byte_to_word_convert((uint32_t) message_length));
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_kdf_hmac_suspend (tsip_kdf_hmac_handle_t * p_handle)
{
    tsip_key_type_extend_t              key_type_ext = r_tsip_key_type_parse(p_handle->wrapped_key.type);
    const tsip_func_subset_kdf_hmac_t * p_func       = get_kdf_hmac_func(key_type_ext);

    /* Call function (cast to match the argument type with the primitive function) */
    return p_func->p_suspend(p_handle->internal_state);
}

tsip_ret_t r_tsip_kdf_hmac_init_final (tsip_kdf_hmac_handle_t * p_handle, uint8_t * p_mac)
{
    uint64_t total_length = p_handle->buffered_length + p_handle->actual_wrapped_msg_length;

    uint32_t msg_len[2] =
    {
        r_tsip_byte_to_bit_convert_upper(total_length),
        r_tsip_byte_to_bit_convert_lower(total_length)
    };

    tsip_key_type_extend_t              key_type_ext = r_tsip_key_type_parse(p_handle->wrapped_key.type);
    uint32_t                            cmd_key_type = get_cmd_kdf_hmac_alg(key_type_ext.alg);
    const tsip_func_subset_kdf_hmac_t * p_func       = get_kdf_hmac_func(key_type_ext);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret =
        p_func->p_init(&cmd_key_type, (const uint32_t *) p_handle->wrapped_key.p_value,
                       &gs_kdf_hmac_hash_type[key_type_ext.subtype], msg_len);
    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret =
            p_func->p_final((const uint32_t *) p_handle->buffer,
                            (const uint32_t *) p_handle->wrapped_msg,
                            (uint32_t *) p_mac,
                            r_tsip_byte_to_word_convert(p_handle->buffered_length),
                            r_tsip_byte_to_word_convert(p_handle->wrapped_msg_length));
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_kdf_hmac_resume_final (tsip_kdf_hmac_handle_t * p_handle, uint8_t * p_mac)
{
    overwrite_internal_state_kdf_hmac(p_handle);

    tsip_key_type_extend_t              key_type_ext = r_tsip_key_type_parse(p_handle->wrapped_key.type);
    uint32_t                            cmd_key_type = get_cmd_kdf_hmac_alg(key_type_ext.alg);
    const tsip_func_subset_kdf_hmac_t * p_func       = get_kdf_hmac_func(key_type_ext);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret =
        p_func->p_resume(&cmd_key_type, (uint32_t *) p_handle->wrapped_key.p_value,
                         &gs_kdf_hmac_hash_type[key_type_ext.subtype], p_handle->internal_state);
    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret =
            p_func->p_final((const uint32_t *) p_handle->buffer, NULL, (uint32_t *) p_mac,
                            r_tsip_byte_to_word_convert(p_handle->buffered_length), 0);
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_kdf_hmac_final (tsip_kdf_hmac_handle_t * p_handle, uint8_t * p_mac)
{
    tsip_key_type_extend_t              key_type_ext = r_tsip_key_type_parse(p_handle->wrapped_key.type);
    const tsip_func_subset_kdf_hmac_t * p_func       = get_kdf_hmac_func(key_type_ext);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = p_func->p_suspend(p_handle->internal_state);
    if (TSIP_RET_PASS == tsip_ret)
    {
        tsip_ret = r_tsip_kdf_hmac_resume_final(p_handle, p_mac);
    }

    return tsip_ret;
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

bool hash_type_is_sha3 (tsip_hash_type_t hash_type)
{
    bool ret = false;

    switch (hash_type)
    {
        case TSIP_HASH_TYPE_SHA1:
        case TSIP_HASH_TYPE_SHA224:
        case TSIP_HASH_TYPE_SHA256:
        case TSIP_HASH_TYPE_SHA384:
        case TSIP_HASH_TYPE_SHA512:
        case TSIP_HASH_TYPE_SHA512_224:
        case TSIP_HASH_TYPE_SHA512_256:
        {
            ret = false;
            break;
        }

        default:
        {
            ret = true;
        }
    }

    return ret;
}

bool hmac_type_is_sha3 (tsip_key_type_extend_t key_type_ext)
{
    bool ret = false;

    switch (key_type_ext.subtype)
    {
        case TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1:
        case TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224:
        case TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256:
        case TSIP_PRV_KEY_SUBTYPE_HMAC_SHA384:
        case TSIP_PRV_KEY_SUBTYPE_HMAC_SHA512:
        {
            ret = false;
            break;
        }

        default:
        {
            ret = true;
        }
    }

    return ret;
}

static void overwrite_internal_state_sha1sha2 (uint32_t * internal_state,
                                               uint64_t   buffered_length,
                                               uint64_t   input_length)
{
 #if 5U == TSIP_PRV_HASH_IP_TYPE
    uint64_t total_length = buffered_length + input_length;
    internal_state[TSIP_PRV_INTERNAL_STATE_OVERWRITE_BASE_SHA1SHA2] =
        r_tsip_byte_to_bit_convert_lower(total_length);
    internal_state[TSIP_PRV_INTERNAL_STATE_OVERWRITE_BASE_SHA1SHA2 +
                   1] = r_tsip_byte_to_bit_convert_upper(total_length);
 #else
    FSP_PARAMETER_NOT_USED(input_length);
 #endif
    internal_state[TSIP_PRV_INTERNAL_STATE_OVERWRITE_BASE_SHA1SHA2 + 2] = r_tsip_byte_to_bit_convert_upper(
        buffered_length);
    internal_state[TSIP_PRV_INTERNAL_STATE_OVERWRITE_BASE_SHA1SHA2 + 3] = r_tsip_byte_to_bit_convert_lower(
        buffered_length);
}

static void overwrite_internal_state_sha3 (uint32_t * internal_state, uint64_t buffered_length)
{
    internal_state[TSIP_PRV_INTERNAL_STATE_OVERWRITE_BASE_SHA3]     = r_tsip_byte_to_bit_convert_upper(buffered_length);
    internal_state[TSIP_PRV_INTERNAL_STATE_OVERWRITE_BASE_SHA3 + 1] = r_tsip_byte_to_bit_convert_lower(buffered_length);
}

void overwrite_internal_state_sha (tsip_sha_handle_t * p_handle)
{
    if (hash_type_is_sha3(p_handle->type))
    {
        overwrite_internal_state_sha3(p_handle->internal_state, p_handle->buffered_length);
    }
    else
    {
        overwrite_internal_state_sha1sha2(p_handle->internal_state, p_handle->buffered_length, p_handle->total_length);
    }
}

void overwrite_internal_state_hmac (tsip_hmac_handle_t * p_handle)
{
    if (hmac_type_is_sha3(r_tsip_key_type_parse(p_handle->wrapped_key.type)))
    {
        overwrite_internal_state_sha3(p_handle->internal_state, p_handle->buffered_length);
    }
    else
    {
        overwrite_internal_state_sha1sha2(p_handle->internal_state, p_handle->buffered_length, p_handle->total_length);
    }
}

void overwrite_internal_state_kdf_sha (tsip_kdf_sha_handle_t * p_handle)
{
    overwrite_internal_state_sha1sha2(p_handle->internal_state, p_handle->buffered_length2, p_handle->total_length);
}

void overwrite_internal_state_kdf_hmac (tsip_kdf_hmac_handle_t * p_handle)
{
    overwrite_internal_state_sha1sha2(p_handle->internal_state, p_handle->buffered_length, p_handle->total_length);
}

TSIP_PRV_STATIC_INLINE const tsip_func_subset_sha_t * get_hash_func (tsip_hash_type_t hash_type)
{
    return hash_type_is_sha3(hash_type) ? &gp_func_sha3 : &gp_func_sha1sha2;
}

TSIP_PRV_STATIC_INLINE const tsip_func_subset_hmac_t * get_hmac_func (tsip_key_type_extend_t key_type_ext)
{
    return hmac_type_is_sha3(key_type_ext) ? &gp_func_hmac_sha3 : &gp_func_hmac_sha1sha2;
}

TSIP_PRV_STATIC_INLINE const tsip_func_subset_kdf_sha_t * get_kdf_hash_func (tsip_hash_type_t hash_type)
{
    FSP_PARAMETER_NOT_USED(hash_type);

    return &gp_func_kdf_sha1sha2;
}

TSIP_PRV_STATIC_INLINE const tsip_func_subset_kdf_hmac_t * get_kdf_hmac_func (tsip_key_type_extend_t key_type_ext)
{
    FSP_PARAMETER_NOT_USED(key_type_ext);

    return &gp_func_kdf_hmac_sha1sha2;
}

TSIP_PRV_STATIC_INLINE uint32_t get_cmd_kdf_hmac_alg (uint8_t alg)
{
    return (TSIP_PRV_ALG_HMAC == alg) ? bswap_32big(0) : bswap_32big(1);
}

#endif                                 /* (3U == TSIP_PRV_HASH_IP_TYPE) || (5U == TSIP_PRV_HASH_IP_TYPE) */
