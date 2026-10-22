/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_tsip_private.h"

#if 1U == TSIP_PRV_HASH_IP_TYPE

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* For SHA, HMAC-SHA */
 #define TSIP_PRV_WORD_SIZE_HMAC_MAC_BUFFER              (16U)
 #define TSIP_PRV_WORD_SIZE_SHA_MESSAGE_DIGEST_BUFFER    (8U)

/* Block length (in bytes) of SHA */
 #define SHA_BLOCK8_LEN                                  (64U)
 #define HMAC_LAST_BLOCK_ADD_LEN                         (64U)
 #define SHA_STOP_BIT                                    (0x80)
 #define SHA_PADDING_DATA_LEN                            (9U)
 #define SHA2_FINAL_BLOCK_MAX_MESSAGE_LEN                (SHA_BLOCK8_LEN * 2 - SHA_PADDING_DATA_LEN)

/* Initial values for SHA operation */
 #define TSIP_PRV_SHA1_INIT_VALUE1                       (0x67452301)
 #define TSIP_PRV_SHA1_INIT_VALUE2                       (0xefcdab89)
 #define TSIP_PRV_SHA1_INIT_VALUE3                       (0x98badcfe)
 #define TSIP_PRV_SHA1_INIT_VALUE4                       (0x10325476)
 #define TSIP_PRV_SHA1_INIT_VALUE5                       (0xc3d2e1f0)

 #define TSIP_PRV_SHA224_INIT_VALUE1                     (0xc1059ed8)
 #define TSIP_PRV_SHA224_INIT_VALUE2                     (0x367cd507)
 #define TSIP_PRV_SHA224_INIT_VALUE3                     (0x3070dd17)
 #define TSIP_PRV_SHA224_INIT_VALUE4                     (0xf70e5939)
 #define TSIP_PRV_SHA224_INIT_VALUE5                     (0xffc00b31)
 #define TSIP_PRV_SHA224_INIT_VALUE6                     (0x68581511)
 #define TSIP_PRV_SHA224_INIT_VALUE7                     (0x64f98fa7)
 #define TSIP_PRV_SHA224_INIT_VALUE8                     (0xbefa4fa4)

 #define TSIP_PRV_SHA256_INIT_VALUE1                     (0x6a09e667)
 #define TSIP_PRV_SHA256_INIT_VALUE2                     (0xbb67ae85)
 #define TSIP_PRV_SHA256_INIT_VALUE3                     (0x3c6ef372)
 #define TSIP_PRV_SHA256_INIT_VALUE4                     (0xa54ff53a)
 #define TSIP_PRV_SHA256_INIT_VALUE5                     (0x510e527f)
 #define TSIP_PRV_SHA256_INIT_VALUE6                     (0x9b05688c)
 #define TSIP_PRV_SHA256_INIT_VALUE7                     (0x1f83d9ab)
 #define TSIP_PRV_SHA256_INIT_VALUE8                     (0x5be0cd19)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

typedef enum e_tsip_hmac_cmd
{
    TSIP_HMAC_CMD_SIGN   = 0U,
    TSIP_HMAC_CMD_VERIFY = 1U,
} tsip_hmac_cmd_t;

typedef union u_tsip_dword_data
{
    uint64_t dword;
    struct
    {
        uint8_t pos_1st;
        uint8_t pos_2nd;
        uint8_t pos_3rd;
        uint8_t pos_4th;
        uint8_t pos_5th;
        uint8_t pos_6th;
        uint8_t pos_7th;
        uint8_t pos_8th;
    } byte;
} tsip_dword_data_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void set_sha2_final_block(const uint8_t * p_message,
                                 uint64_t        message_length,
                                 uint64_t        total_message_length,
                                 uint8_t       * p_last_block,
                                 uint32_t      * p_last_block_length);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
static const uint32_t gs_hmac_cmd[] =
{
    [TSIP_HMAC_CMD_SIGN]   = BSWAP_32BIG_C(0U),
    [TSIP_HMAC_CMD_VERIFY] = BSWAP_32BIG_C(1U),
};

static const uint32_t gs_sha1_init_value[8] =
{
    BSWAP_32BIG_C(TSIP_PRV_SHA1_INIT_VALUE1),
    BSWAP_32BIG_C(TSIP_PRV_SHA1_INIT_VALUE2),
    BSWAP_32BIG_C(TSIP_PRV_SHA1_INIT_VALUE3),
    BSWAP_32BIG_C(TSIP_PRV_SHA1_INIT_VALUE4),
    BSWAP_32BIG_C(TSIP_PRV_SHA1_INIT_VALUE5),
};

static const uint32_t gs_sha224_init_value[8] =
{
    BSWAP_32BIG_C(TSIP_PRV_SHA224_INIT_VALUE1),
    BSWAP_32BIG_C(TSIP_PRV_SHA224_INIT_VALUE2),
    BSWAP_32BIG_C(TSIP_PRV_SHA224_INIT_VALUE3),
    BSWAP_32BIG_C(TSIP_PRV_SHA224_INIT_VALUE4),
    BSWAP_32BIG_C(TSIP_PRV_SHA224_INIT_VALUE5),
    BSWAP_32BIG_C(TSIP_PRV_SHA224_INIT_VALUE6),
    BSWAP_32BIG_C(TSIP_PRV_SHA224_INIT_VALUE7),
    BSWAP_32BIG_C(TSIP_PRV_SHA224_INIT_VALUE8),
};

static const uint32_t gs_sha256_init_value[8] =
{
    BSWAP_32BIG_C(TSIP_PRV_SHA256_INIT_VALUE1),
    BSWAP_32BIG_C(TSIP_PRV_SHA256_INIT_VALUE2),
    BSWAP_32BIG_C(TSIP_PRV_SHA256_INIT_VALUE3),
    BSWAP_32BIG_C(TSIP_PRV_SHA256_INIT_VALUE4),
    BSWAP_32BIG_C(TSIP_PRV_SHA256_INIT_VALUE5),
    BSWAP_32BIG_C(TSIP_PRV_SHA256_INIT_VALUE6),
    BSWAP_32BIG_C(TSIP_PRV_SHA256_INIT_VALUE7),
    BSWAP_32BIG_C(TSIP_PRV_SHA256_INIT_VALUE8),
};

static const uint32_t gs_digest_length[TSIP_HASH_TYPE_NUM] =
{
    [TSIP_HASH_TYPE_SHA1]       = TSIP_PRV_BYTE_SIZE_DIGEST_SHA1,
    [TSIP_HASH_TYPE_SHA224]     = TSIP_PRV_BYTE_SIZE_DIGEST_SHA224,
    [TSIP_HASH_TYPE_SHA256]     = TSIP_PRV_BYTE_SIZE_DIGEST_SHA256,
    [TSIP_HASH_TYPE_SHA384]     = TSIP_PRV_BYTE_SIZE_DIGEST_SHA384,
    [TSIP_HASH_TYPE_SHA512]     = TSIP_PRV_BYTE_SIZE_DIGEST_SHA512,
    [TSIP_HASH_TYPE_SHA512_224] = TSIP_PRV_BYTE_SIZE_DIGEST_SHA512_224,
    [TSIP_HASH_TYPE_SHA512_256] = TSIP_PRV_BYTE_SIZE_DIGEST_SHA512_256,
    [TSIP_HASH_TYPE_SHA3_224]   = TSIP_PRV_BYTE_SIZE_DIGEST_SHA3_224,
    [TSIP_HASH_TYPE_SHA3_256]   = TSIP_PRV_BYTE_SIZE_DIGEST_SHA3_256,
    [TSIP_HASH_TYPE_SHA3_384]   = TSIP_PRV_BYTE_SIZE_DIGEST_SHA3_384,
    [TSIP_HASH_TYPE_SHA3_512]   = TSIP_PRV_BYTE_SIZE_DIGEST_SHA3_512,
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
    tsip_ret_t             tsip_ret = TSIP_RET_FAIL;
    tsip_func_subset_sha_t p_func   = gp_func_sha1sha2[p_handle->type];

    switch (p_handle->type)
    {
        /* SHA-1 */
        case TSIP_HASH_TYPE_SHA1:
        {
            /* Call function (cast to match the argument type with the primitive function) */
            tsip_ret =
                p_func(gs_sha1_init_value, (const uint32_t *) p_message,
                       r_tsip_byte_to_word_convert((uint32_t) message_length), p_handle->internal_state);
            break;
        }

        /* SHA-224 */
        case TSIP_HASH_TYPE_SHA224:
        {
            /* Call function (cast to match the argument type with the primitive function) */
            tsip_ret =
                p_func(gs_sha224_init_value, (const uint32_t *) p_message,
                       r_tsip_byte_to_word_convert((uint32_t) message_length), p_handle->internal_state);
            break;
        }

        /* SHA-256 */
        case TSIP_HASH_TYPE_SHA256:
        {
            /* Call function (cast to match the argument type with the primitive function) */
            tsip_ret =
                p_func(gs_sha256_init_value, (const uint32_t *) p_message,
                       r_tsip_byte_to_word_convert((uint32_t) message_length), p_handle->internal_state);
            break;
        }

        default:
        {
            break;
        }
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_sha_hash_resume_update (tsip_sha_handle_t * p_handle,
                                          const uint8_t     * p_message,
                                          uint64_t            message_length)
{
    return r_tsip_sha_hash_update(p_handle, p_message, message_length);
}

tsip_ret_t r_tsip_sha_hash_update (tsip_sha_handle_t * p_handle, const uint8_t * p_message, uint64_t message_length)
{
    const tsip_func_subset_sha_t p_func = gp_func_sha1sha2[p_handle->type];

    /* Call function (cast to match the argument type with the primitive function) */
    return p_func(p_handle->internal_state, (const uint32_t *) p_message,
                  r_tsip_byte_to_word_convert((uint32_t) message_length), p_handle->internal_state);
}

tsip_ret_t r_tsip_sha_hash_suspend (tsip_sha_handle_t * p_handle)
{
    FSP_PARAMETER_NOT_USED(p_handle);

    return TSIP_RET_PASS;
}

tsip_ret_t r_tsip_sha_hash_init_final (tsip_hash_type_t hash_type,
                                       const uint8_t  * p_message,
                                       uint64_t         message_length,
                                       uint8_t        * p_digest)
{
    tsip_ret_t       tsip_ret = TSIP_RET_FAIL;
    uint8_t          padded_msg[SHA_BLOCK8_LEN * 2] = {0};
    uint32_t         set_prc_byte_size              = 0;
    uint64_t         tmp_message_length             = message_length;
    const uint8_t  * p_tmp_message = p_message;
    const uint32_t * p_tmp_digest;
    uint32_t         digest_buffer[TSIP_PRV_WORD_SIZE_SHA_MESSAGE_DIGEST_BUFFER] = {0};
    uint8_t          outdata_msg_digest[TSIP_PRV_BYTE_SIZE_DIGEST_MAX]           = {0};

    const tsip_func_subset_sha_t p_func = gp_func_sha1sha2[hash_type];

    switch (hash_type)
    {
        /* SHA-1 */
        case TSIP_HASH_TYPE_SHA1:
        {
            p_tmp_digest = gs_sha1_init_value;
            tsip_ret     = TSIP_RET_PASS;
            break;
        }

        /* SHA-224 */
        case TSIP_HASH_TYPE_SHA224:
        {
            p_tmp_digest = gs_sha224_init_value;
            tsip_ret     = TSIP_RET_PASS;
            break;
        }

        /* SHA-256 */
        case TSIP_HASH_TYPE_SHA256:
        {
            p_tmp_digest = gs_sha256_init_value;
            tsip_ret     = TSIP_RET_PASS;
            break;
        }

        default:
        {
            break;
        }
    }

    if (TSIP_RET_PASS == tsip_ret)
    {
        if (SHA2_FINAL_BLOCK_MAX_MESSAGE_LEN <= message_length)
        {
            tmp_message_length = message_length & (SHA_BLOCK8_LEN - 1);
            p_tmp_message      = p_message + (message_length - tmp_message_length);
            tsip_ret           =
                p_func(p_tmp_digest, (const uint32_t *) p_message,
                       r_tsip_byte_to_word_convert((uint32_t) (message_length - tmp_message_length)), digest_buffer);
            p_tmp_digest = digest_buffer;
        }

        if (TSIP_RET_PASS == tsip_ret)
        {
            set_sha2_final_block(p_tmp_message, tmp_message_length, message_length, padded_msg, &set_prc_byte_size);

            tsip_ret =
                p_func(p_tmp_digest, (const uint32_t *) padded_msg, r_tsip_byte_to_word_convert(set_prc_byte_size),
                       (uint32_t *) outdata_msg_digest);

            if (TSIP_RET_PASS == tsip_ret)
            {
                memcpy(p_digest, outdata_msg_digest, gs_digest_length[hash_type]);
            }
        }
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_sha_hash_resume_final (tsip_sha_handle_t * p_handle, uint8_t * p_digest)
{
    return r_tsip_sha_hash_final(p_handle, p_digest);
}

tsip_ret_t r_tsip_sha_hash_final (tsip_sha_handle_t * p_handle, uint8_t * p_digest)
{
    tsip_ret_t tsip_ret                 = TSIP_RET_FAIL;
    uint32_t   set_prc_byte_size        = 0;
    const tsip_func_subset_sha_t p_func = gp_func_sha1sha2[p_handle->type];
    uint8_t outdata_msg_digest[TSIP_PRV_BYTE_SIZE_DIGEST_MAX] = {0};

    set_sha2_final_block(p_handle->buffer,
                         p_handle->buffered_length,
                         p_handle->total_length + p_handle->buffered_length,
                         p_handle->buffer,
                         &set_prc_byte_size);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret =
        p_func(p_handle->internal_state, (const uint32_t *) p_handle->buffer,
               r_tsip_byte_to_word_convert(set_prc_byte_size), (uint32_t *) outdata_msg_digest);

    if (TSIP_RET_PASS == tsip_ret)
    {
        memcpy(p_digest, outdata_msg_digest, gs_digest_length[p_handle->type]);
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_hmac_init_update (tsip_hmac_handle_t * p_handle, const uint8_t * p_message, uint64_t message_length)
{
    tsip_ret_t             tsip_ret     = TSIP_RET_FAIL;
    tsip_key_type_extend_t key_type_ext = r_tsip_key_type_parse(p_handle->wrapped_key.type);

    if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1 == key_type_ext.subtype)
    {
        /* Call function (cast to match the argument type with the primitive function) */
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_init(
            (uint32_t *) p_handle->wrapped_key.p_value);
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224 == key_type_ext.subtype)
    {
        /* Call function (cast to match the argument type with the primitive function) */
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_init(
            (uint32_t *) p_handle->wrapped_key.p_value);
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256 == key_type_ext.subtype)
    {
        /* Call function (cast to match the argument type with the primitive function) */
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_init(
            (uint32_t *) p_handle->wrapped_key.p_value);
    }
    else
    {
        tsip_ret = TSIP_RET_FAIL;
    }

    if (TSIP_RET_PASS == tsip_ret)
    {
        if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1 == key_type_ext.subtype)
        {
            /* Call function (cast to match the argument type with the primitive function) */
            gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_update((const uint32_t *) p_message,
                                                                           r_tsip_byte_to_word_convert((uint32_t)
                                                                                                       message_length));
        }
        else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224 == key_type_ext.subtype)
        {
            /* Call function (cast to match the argument type with the primitive function) */
            gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_update((const uint32_t *) p_message,
                                                                             r_tsip_byte_to_word_convert((uint32_t)
                                                                                                         message_length));
        }
        else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256 == key_type_ext.subtype)
        {
            /* Call function (cast to match the argument type with the primitive function) */
            gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_update((const uint32_t *) p_message,
                                                                             r_tsip_byte_to_word_convert((uint32_t)
                                                                                                         message_length));
        }
        else
        {
            tsip_ret = TSIP_RET_FAIL;
        }
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_hmac_resume_update (tsip_hmac_handle_t * p_handle, const uint8_t * p_message, uint64_t message_length)
{
    FSP_PARAMETER_NOT_USED(p_handle);

    tsip_ret_t             tsip_ret     = TSIP_RET_FAIL;
    tsip_key_type_extend_t key_type_ext = r_tsip_key_type_parse(p_handle->wrapped_key.type);

    /* Call function (cast to match the argument type with the primitive function) */
    if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1 == key_type_ext.subtype)
    {
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_resume(
            (uint32_t *) p_handle->wrapped_key.p_value,
            p_handle->internal_state);
        if (TSIP_RET_PASS == tsip_ret)
        {
            gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_update((const uint32_t *) p_message,
                                                                           r_tsip_byte_to_word_convert((uint32_t)
                                                                                                       message_length));
        }
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224 == key_type_ext.subtype)
    {
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_resume(
            (uint32_t *) p_handle->wrapped_key.p_value,
            p_handle->internal_state);
        if (TSIP_RET_PASS == tsip_ret)
        {
            gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_update((const uint32_t *) p_message,
                                                                             r_tsip_byte_to_word_convert((uint32_t)
                                                                                                         message_length));
        }
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256 == key_type_ext.subtype)
    {
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_resume(
            (uint32_t *) p_handle->wrapped_key.p_value,
            p_handle->internal_state);
        if (TSIP_RET_PASS == tsip_ret)
        {
            gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_update((const uint32_t *) p_message,
                                                                             r_tsip_byte_to_word_convert((uint32_t)
                                                                                                         message_length));
        }
    }
    else
    {
        /* Do nothing */
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_hmac_update (tsip_hmac_handle_t * p_handle, const uint8_t * p_message, uint64_t message_length)
{
    tsip_ret_t             tsip_ret     = TSIP_RET_FAIL;
    tsip_key_type_extend_t key_type_ext = r_tsip_key_type_parse(p_handle->wrapped_key.type);

    if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1 == key_type_ext.subtype)
    {
        /* Call function (cast to match the argument type with the primitive function) */
        gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_update((const uint32_t *) p_message,
                                                                       r_tsip_byte_to_word_convert((uint32_t)
                                                                                                   message_length));
        tsip_ret = TSIP_RET_PASS;
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224 == key_type_ext.subtype)
    {
        /* Call function (cast to match the argument type with the primitive function) */
        gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_update((const uint32_t *) p_message,
                                                                         r_tsip_byte_to_word_convert((uint32_t)
                                                                                                     message_length));
        tsip_ret = TSIP_RET_PASS;
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256 == key_type_ext.subtype)
    {
        /* Call function (cast to match the argument type with the primitive function) */
        gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_update((const uint32_t *) p_message,
                                                                         r_tsip_byte_to_word_convert((uint32_t)
                                                                                                     message_length));
        tsip_ret = TSIP_RET_PASS;
    }
    else
    {
        tsip_ret = TSIP_RET_FAIL;
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_hmac_suspend (tsip_hmac_handle_t * p_handle)
{
    tsip_ret_t             tsip_ret     = TSIP_RET_FAIL;
    tsip_key_type_extend_t key_type_ext = r_tsip_key_type_parse(p_handle->wrapped_key.type);

    if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1 == key_type_ext.subtype)
    {
        /* Call function (cast to match the argument type with the primitive function) */
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_suspend(p_handle->internal_state);
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224 == key_type_ext.subtype)
    {
        /* Call function (cast to match the argument type with the primitive function) */
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_suspend(p_handle->internal_state);
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256 == key_type_ext.subtype)
    {
        /* Call function (cast to match the argument type with the primitive function) */
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_suspend(p_handle->internal_state);
    }
    else
    {
        /* Do nothing */
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_hmac_init_final (const tsip_wrapped_key_t * p_wrapped_key,
                                   const uint8_t            * p_message,
                                   uint64_t                   message_length,
                                   uint8_t                  * p_mac)
{
    tsip_ret_t             tsip_ret     = TSIP_RET_FAIL;
    tsip_key_type_extend_t key_type_ext = r_tsip_key_type_parse(p_wrapped_key->type);

    uint8_t         padded_msg[SHA_BLOCK8_LEN * 2] = {0};
    uint32_t        set_prc_byte_size              = 0;
    uint64_t        tmp_message_length             = message_length;
    const uint8_t * p_tmp_message = p_message;

    if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1 == key_type_ext.subtype)
    {
        /* Call function (cast to match the argument type with the primitive function) */
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_init((uint32_t *) p_wrapped_key->p_value);
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224 == key_type_ext.subtype)
    {
        /* Call function (cast to match the argument type with the primitive function) */
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_init((uint32_t *) p_wrapped_key->p_value);
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256 == key_type_ext.subtype)
    {
        /* Call function (cast to match the argument type with the primitive function) */
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_init((uint32_t *) p_wrapped_key->p_value);
    }
    else
    {
        tsip_ret = TSIP_RET_FAIL;
    }

    if (TSIP_RET_PASS == tsip_ret)
    {
        if (SHA2_FINAL_BLOCK_MAX_MESSAGE_LEN <= message_length)
        {
            tmp_message_length = message_length & (SHA_BLOCK8_LEN - 1);
            p_tmp_message      = p_message + (message_length - tmp_message_length);
        }

        set_sha2_final_block(p_tmp_message,
                             tmp_message_length,
                             message_length + HMAC_LAST_BLOCK_ADD_LEN,
                             padded_msg,
                             &set_prc_byte_size);

        if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1 == key_type_ext.subtype)
        {
            if (SHA2_FINAL_BLOCK_MAX_MESSAGE_LEN <= message_length)
            {
                gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_update((const uint32_t *) p_message,
                                                                               r_tsip_byte_to_word_convert((uint32_t) (
                                                                                                               message_length
                                                                                                               -
                                                                                                               tmp_message_length)));
            }

            gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_update((const uint32_t *) padded_msg,
                                                                           r_tsip_byte_to_word_convert(
                                                                               set_prc_byte_size));

            /* Call function (cast to match the argument type with the primitive function) */
            tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_SIGN],
                                                                                     NULL,
                                                                                     NULL,
                                                                                     (uint32_t *) p_mac);
        }
        else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224 == key_type_ext.subtype)
        {
            if (SHA2_FINAL_BLOCK_MAX_MESSAGE_LEN <= message_length)
            {
                gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_update((const uint32_t *) p_message,
                                                                                 r_tsip_byte_to_word_convert((uint32_t) (
                                                                                                                 message_length
                                                                                                                 -
                                                                                                                 tmp_message_length)));
            }

            gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_update((const uint32_t *) padded_msg,
                                                                             r_tsip_byte_to_word_convert(
                                                                                 set_prc_byte_size));

            /* Call function (cast to match the argument type with the primitive function) */
            tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_SIGN],
                                                                                       NULL,
                                                                                       NULL,
                                                                                       (uint32_t *) p_mac);
        }
        else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256 == key_type_ext.subtype)
        {
            if (SHA2_FINAL_BLOCK_MAX_MESSAGE_LEN <= message_length)
            {
                gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_update((const uint32_t *) p_message,
                                                                                 r_tsip_byte_to_word_convert((uint32_t) (
                                                                                                                 message_length
                                                                                                                 -
                                                                                                                 tmp_message_length)));
            }

            gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_update((const uint32_t *) padded_msg,
                                                                             r_tsip_byte_to_word_convert(
                                                                                 set_prc_byte_size));

            /* Call function (cast to match the argument type with the primitive function) */
            tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_SIGN],
                                                                                       NULL,
                                                                                       NULL,
                                                                                       (uint32_t *) p_mac);
        }
        else
        {
            tsip_ret = TSIP_RET_FAIL;
        }
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_hmac_resume_final (tsip_hmac_handle_t * p_handle, uint8_t * p_mac)
{
    uint32_t               set_prc_byte_size = 0;
    tsip_key_type_extend_t key_type_ext      = r_tsip_key_type_parse(p_handle->wrapped_key.type);

    set_sha2_final_block(p_handle->buffer,
                         p_handle->buffered_length,
                         p_handle->total_length + p_handle->buffered_length + HMAC_LAST_BLOCK_ADD_LEN,
                         (uint8_t *) p_handle->buffer,
                         &set_prc_byte_size);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = TSIP_RET_FAIL;
    if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1 == key_type_ext.subtype)
    {
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_resume(
            (uint32_t *) p_handle->wrapped_key.p_value,
            p_handle->internal_state);
        if (TSIP_RET_PASS == tsip_ret)
        {
            gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_update((const uint32_t *) p_handle->buffer,
                                                                           r_tsip_byte_to_word_convert(
                                                                               set_prc_byte_size));
            tsip_ret =
                gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_SIGN],
                                                                              NULL,
                                                                              NULL,
                                                                              (uint32_t *) p_mac);
        }
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224 == key_type_ext.subtype)
    {
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_resume(
            (uint32_t *) p_handle->wrapped_key.p_value,
            p_handle->internal_state);
        if (TSIP_RET_PASS == tsip_ret)
        {
            gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_update((const uint32_t *) p_handle->buffer,
                                                                             r_tsip_byte_to_word_convert(
                                                                                 set_prc_byte_size));
            tsip_ret =
                gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_SIGN],
                                                                                NULL,
                                                                                NULL,
                                                                                (uint32_t *) p_mac);
        }
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256 == key_type_ext.subtype)
    {
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_resume(
            (uint32_t *) p_handle->wrapped_key.p_value,
            p_handle->internal_state);
        if (TSIP_RET_PASS == tsip_ret)
        {
            gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_update((const uint32_t *) p_handle->buffer,
                                                                             r_tsip_byte_to_word_convert(
                                                                                 set_prc_byte_size));
            tsip_ret =
                gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_SIGN],
                                                                                NULL,
                                                                                NULL,
                                                                                (uint32_t *) p_mac);
        }
    }
    else
    {
        /* Do nothing */
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_hmac_final (tsip_hmac_handle_t * p_handle, uint8_t * p_mac)
{
    tsip_ret_t             tsip_ret          = TSIP_RET_FAIL;
    tsip_key_type_extend_t key_type_ext      = r_tsip_key_type_parse(p_handle->wrapped_key.type);
    uint32_t               set_prc_byte_size = 0;

    set_sha2_final_block(p_handle->buffer,
                         p_handle->buffered_length,
                         p_handle->total_length + p_handle->buffered_length + HMAC_LAST_BLOCK_ADD_LEN,
                         p_handle->buffer,
                         &set_prc_byte_size);

    if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1 == key_type_ext.subtype)
    {
        gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_update((const uint32_t *) p_handle->buffer,
                                                                       r_tsip_byte_to_word_convert(set_prc_byte_size));

        /* Call function (cast to match the argument type with the primitive function) */
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_SIGN],
                                                                                 NULL,
                                                                                 NULL,
                                                                                 (uint32_t *) p_mac);
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224 == key_type_ext.subtype)
    {
        gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_update((const uint32_t *) p_handle->buffer,
                                                                         r_tsip_byte_to_word_convert(set_prc_byte_size));

        /* Call function (cast to match the argument type with the primitive function) */
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_SIGN],
                                                                                   NULL,
                                                                                   NULL,
                                                                                   (uint32_t *) p_mac);
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256 == key_type_ext.subtype)
    {
        gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_update((const uint32_t *) p_handle->buffer,
                                                                         r_tsip_byte_to_word_convert(set_prc_byte_size));

        /* Call function (cast to match the argument type with the primitive function) */
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_SIGN],
                                                                                   NULL,
                                                                                   NULL,
                                                                                   (uint32_t *) p_mac);
    }
    else
    {
        tsip_ret = TSIP_RET_FAIL;
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_hmac_init_verify (const tsip_wrapped_key_t * p_wrapped_key,
                                    const uint8_t            * p_message,
                                    uint64_t                   message_length,
                                    const uint8_t            * p_mac,
                                    uint32_t                   mac_length)
{
    tsip_ret_t             tsip_ret     = TSIP_RET_FAIL;
    tsip_key_type_extend_t key_type_ext = r_tsip_key_type_parse(p_wrapped_key->type);

    uint32_t        InData_MAC[TSIP_PRV_WORD_SIZE_HMAC_MAC_BUFFER] = {0};
    uint8_t         padded_msg[SHA_BLOCK8_LEN * 2]                 = {0};
    uint32_t        set_prc_byte_size  = 0;
    uint64_t        tmp_message_length = message_length;
    const uint8_t * p_tmp_message      = p_message;
    memcpy(InData_MAC, p_mac, mac_length);
    uint32_t mac_len[1] = {bswap_32big(mac_length)};

    if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1 == key_type_ext.subtype)
    {
        /* Call function (cast to match the argument type with the primitive function) */
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_init((uint32_t *) p_wrapped_key->p_value);
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224 == key_type_ext.subtype)
    {
        /* Call function (cast to match the argument type with the primitive function) */
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_init((uint32_t *) p_wrapped_key->p_value);
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256 == key_type_ext.subtype)
    {
        /* Call function (cast to match the argument type with the primitive function) */
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_init((uint32_t *) p_wrapped_key->p_value);
    }
    else
    {
        tsip_ret = TSIP_RET_FAIL;
    }

    if (TSIP_RET_PASS == tsip_ret)
    {
        if (SHA2_FINAL_BLOCK_MAX_MESSAGE_LEN <= message_length)
        {
            tmp_message_length = message_length & (SHA_BLOCK8_LEN - 1);
            p_tmp_message      = p_message + (message_length - tmp_message_length);
        }

        set_sha2_final_block(p_tmp_message,
                             tmp_message_length,
                             message_length + HMAC_LAST_BLOCK_ADD_LEN,
                             padded_msg,
                             &set_prc_byte_size);

        if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1 == key_type_ext.subtype)
        {
            if (SHA2_FINAL_BLOCK_MAX_MESSAGE_LEN <= message_length)
            {
                gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_update((const uint32_t *) p_message,
                                                                               r_tsip_byte_to_word_convert((uint32_t) (
                                                                                                               message_length
                                                                                                               -
                                                                                                               tmp_message_length)));
            }

            gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_update((const uint32_t *) padded_msg,
                                                                           r_tsip_byte_to_word_convert(
                                                                               set_prc_byte_size));

            /* Call function (cast to match the argument type with the primitive function) */
            tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_VERIFY],
                                                                                     InData_MAC,
                                                                                     mac_len,
                                                                                     NULL);
        }
        else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224 == key_type_ext.subtype)
        {
            if (SHA2_FINAL_BLOCK_MAX_MESSAGE_LEN <= message_length)
            {
                gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_update((const uint32_t *) p_message,
                                                                                 r_tsip_byte_to_word_convert((uint32_t) (
                                                                                                                 message_length
                                                                                                                 -
                                                                                                                 tmp_message_length)));
            }

            gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_update((const uint32_t *) padded_msg,
                                                                             r_tsip_byte_to_word_convert(
                                                                                 set_prc_byte_size));

            /* Call function (cast to match the argument type with the primitive function) */
            tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_final(
                &gs_hmac_cmd[TSIP_HMAC_CMD_VERIFY],
                InData_MAC,
                mac_len,
                NULL);
        }
        else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256 == key_type_ext.subtype)
        {
            if (SHA2_FINAL_BLOCK_MAX_MESSAGE_LEN <= message_length)
            {
                gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_update((const uint32_t *) p_message,
                                                                                 r_tsip_byte_to_word_convert((uint32_t) (
                                                                                                                 message_length
                                                                                                                 -
                                                                                                                 tmp_message_length)));
            }

            gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_update((const uint32_t *) padded_msg,
                                                                             r_tsip_byte_to_word_convert(
                                                                                 set_prc_byte_size));

            /* Call function (cast to match the argument type with the primitive function) */
            tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_final(
                &gs_hmac_cmd[TSIP_HMAC_CMD_VERIFY],
                InData_MAC,
                mac_len,
                NULL);
        }
        else
        {
            tsip_ret = TSIP_RET_FAIL;
        }
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_hmac_resume_verify (tsip_hmac_handle_t * p_handle, const uint8_t * p_mac, uint32_t mac_length)
{
    tsip_key_type_extend_t key_type_ext      = r_tsip_key_type_parse(p_handle->wrapped_key.type);
    uint32_t               set_prc_byte_size = 0;
    uint32_t               InData_MAC[TSIP_PRV_WORD_SIZE_HMAC_MAC_BUFFER] =
    {
        0
    };

    set_sha2_final_block(p_handle->buffer,
                         p_handle->buffered_length,
                         p_handle->total_length + p_handle->buffered_length + HMAC_LAST_BLOCK_ADD_LEN,
                         (uint8_t *) p_handle->buffer,
                         &set_prc_byte_size);

    memcpy(InData_MAC, p_mac, mac_length);
    uint32_t mac_len[1] =
    {
        bswap_32big(mac_length)
    };

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = TSIP_RET_FAIL;
    if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1 == key_type_ext.subtype)
    {
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_resume(
            (uint32_t *) p_handle->wrapped_key.p_value,
            p_handle->internal_state);
        if (TSIP_RET_PASS == tsip_ret)
        {
            gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_update((const uint32_t *) p_handle->buffer,
                                                                           r_tsip_byte_to_word_convert(
                                                                               set_prc_byte_size));
            tsip_ret =
                gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_VERIFY],
                                                                              InData_MAC,
                                                                              mac_len,
                                                                              (uint32_t *) NULL);
        }
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224 == key_type_ext.subtype)
    {
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_resume(
            (uint32_t *) p_handle->wrapped_key.p_value,
            p_handle->internal_state);
        if (TSIP_RET_PASS == tsip_ret)
        {
            gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_update((const uint32_t *) p_handle->buffer,
                                                                             r_tsip_byte_to_word_convert(
                                                                                 set_prc_byte_size));
            tsip_ret =
                gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_VERIFY],
                                                                                InData_MAC,
                                                                                mac_len,
                                                                                (uint32_t *) NULL);
        }
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256 == key_type_ext.subtype)
    {
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_resume(
            (uint32_t *) p_handle->wrapped_key.p_value,
            p_handle->internal_state);
        if (TSIP_RET_PASS == tsip_ret)
        {
            gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_update((const uint32_t *) p_handle->buffer,
                                                                             r_tsip_byte_to_word_convert(
                                                                                 set_prc_byte_size));
            tsip_ret =
                gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_VERIFY],
                                                                                InData_MAC,
                                                                                mac_len,
                                                                                (uint32_t *) NULL);
        }
    }
    else
    {
        /* Do nothing */
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_hmac_verify (tsip_hmac_handle_t * p_handle, const uint8_t * p_mac, uint32_t mac_length)
{
    tsip_ret_t             tsip_ret     = TSIP_RET_FAIL;
    tsip_key_type_extend_t key_type_ext = r_tsip_key_type_parse(p_handle->wrapped_key.type);

    uint32_t InData_MAC[TSIP_PRV_WORD_SIZE_HMAC_MAC_BUFFER] = {0};
    uint32_t mac_len[1]        = {bswap_32big(mac_length)};
    uint32_t set_prc_byte_size = 0;

    set_sha2_final_block(p_handle->buffer,
                         p_handle->buffered_length,
                         p_handle->total_length + p_handle->buffered_length + HMAC_LAST_BLOCK_ADD_LEN,
                         p_handle->buffer,
                         &set_prc_byte_size);

    memcpy(InData_MAC, p_mac, mac_length);

    if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1 == key_type_ext.subtype)
    {
        gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_update((const uint32_t *) p_handle->buffer,
                                                                       r_tsip_byte_to_word_convert(set_prc_byte_size));

        /* Call function (cast to match the argument type with the primitive function) */
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1].p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_VERIFY],
                                                                                 InData_MAC,
                                                                                 mac_len,
                                                                                 NULL);
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224 == key_type_ext.subtype)
    {
        gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_update((const uint32_t *) p_handle->buffer,
                                                                         r_tsip_byte_to_word_convert(set_prc_byte_size));

        /* Call function (cast to match the argument type with the primitive function) */
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224].p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_VERIFY],
                                                                                   InData_MAC,
                                                                                   mac_len,
                                                                                   NULL);
    }
    else if (TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256 == key_type_ext.subtype)
    {
        gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_update((const uint32_t *) p_handle->buffer,
                                                                         r_tsip_byte_to_word_convert(set_prc_byte_size));

        /* Call function (cast to match the argument type with the primitive function) */
        tsip_ret = gp_func_hmac_sha1sha2[TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256].p_final(&gs_hmac_cmd[TSIP_HMAC_CMD_VERIFY],
                                                                                   InData_MAC,
                                                                                   mac_len,
                                                                                   NULL);
    }
    else
    {
        tsip_ret = TSIP_RET_FAIL;
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_kdf_sha_init_update (tsip_kdf_sha_handle_t * p_handle,
                                       const uint8_t         * p_message,
                                       uint64_t                message_length)
{
    FSP_PARAMETER_NOT_USED(p_handle);
    FSP_PARAMETER_NOT_USED(p_message);
    FSP_PARAMETER_NOT_USED(message_length);

    return TSIP_RET_FAIL;
}

tsip_ret_t r_tsip_kdf_sha_resume_update (tsip_kdf_sha_handle_t * p_handle,
                                         const uint8_t         * p_message,
                                         uint64_t                message_length)
{
    FSP_PARAMETER_NOT_USED(p_handle);
    FSP_PARAMETER_NOT_USED(p_message);
    FSP_PARAMETER_NOT_USED(message_length);

    return TSIP_RET_FAIL;
}

tsip_ret_t r_tsip_kdf_sha_update (tsip_kdf_sha_handle_t * p_handle, const uint8_t * p_message, uint64_t message_length)
{
    FSP_PARAMETER_NOT_USED(p_handle);
    FSP_PARAMETER_NOT_USED(p_message);
    FSP_PARAMETER_NOT_USED(message_length);

    return TSIP_RET_FAIL;
}

tsip_ret_t r_tsip_kdf_sha_suspend (tsip_kdf_sha_handle_t * p_handle)
{
    FSP_PARAMETER_NOT_USED(p_handle);

    return TSIP_RET_PASS;
}

tsip_ret_t r_tsip_kdf_sha_init_final (tsip_kdf_sha_handle_t * p_handle, uint8_t * p_digest)
{
    uint32_t total_length = p_handle->buffered_length1 + p_handle->actual_wrapped_msg_length +
                            p_handle->buffered_length2;
    tsip_dword_data_t total_bit_length = {.dword = total_length << 3};
    uint8_t           padded_buffer2[SHA_BLOCK8_LEN * 2 + SHA_PADDING_DATA_LEN] = {0};
    uint32_t          zero_padding_len = 0;

    memcpy(padded_buffer2, p_handle->buffer2, p_handle->buffered_length2);
    zero_padding_len = SHA_BLOCK8_LEN - ((total_length + SHA_PADDING_DATA_LEN) & (SHA_BLOCK8_LEN - 1));

    padded_buffer2[p_handle->buffered_length2] = SHA_STOP_BIT;
    padded_buffer2[p_handle->buffered_length2 + zero_padding_len + 1] = total_bit_length.byte.pos_8th;
    padded_buffer2[p_handle->buffered_length2 + zero_padding_len + 2] = total_bit_length.byte.pos_7th;
    padded_buffer2[p_handle->buffered_length2 + zero_padding_len + 3] = total_bit_length.byte.pos_6th;
    padded_buffer2[p_handle->buffered_length2 + zero_padding_len + 4] = total_bit_length.byte.pos_5th;
    padded_buffer2[p_handle->buffered_length2 + zero_padding_len + 5] = total_bit_length.byte.pos_4th;
    padded_buffer2[p_handle->buffered_length2 + zero_padding_len + 6] = total_bit_length.byte.pos_3rd;
    padded_buffer2[p_handle->buffered_length2 + zero_padding_len + 7] = total_bit_length.byte.pos_2nd;
    padded_buffer2[p_handle->buffered_length2 + zero_padding_len + 8] = total_bit_length.byte.pos_1st;

    uint32_t padded_buffer2_len = p_handle->buffered_length2 + zero_padding_len + SHA_PADDING_DATA_LEN;
    uint32_t msg1_len[1]        = {bswap_32big(p_handle->buffered_length1)};
    uint32_t enc_msg_len[1]     = {bswap_32big(p_handle->actual_wrapped_msg_length)};
    uint32_t msg2_len[1]        = {bswap_32big(padded_buffer2_len)};

    /* Call function (cast to match the argument type with the primitive function) */
    return gp_func_kdf_sha1sha2((const uint32_t *) p_handle->buffer1,
                                msg1_len,
                                (const uint32_t *) p_handle->wrapped_msg,
                                enc_msg_len,
                                (const uint32_t *) padded_buffer2,
                                msg2_len,
                                (uint32_t *) p_digest);
}

tsip_ret_t r_tsip_kdf_sha_resume_final (tsip_kdf_sha_handle_t * p_handle, uint8_t * p_digest)
{
    return r_tsip_kdf_sha_init_final(p_handle, p_digest);
}

tsip_ret_t r_tsip_kdf_sha_final (tsip_kdf_sha_handle_t * p_handle, uint8_t * p_digest)
{
    return r_tsip_kdf_sha_init_final(p_handle, p_digest);
}

tsip_ret_t r_tsip_kdf_hmac_init_update (tsip_kdf_hmac_handle_t * p_handle,
                                        const uint8_t          * p_message,
                                        uint64_t                 message_length)
{
    FSP_PARAMETER_NOT_USED(p_handle);
    FSP_PARAMETER_NOT_USED(p_message);
    FSP_PARAMETER_NOT_USED(message_length);

    return TSIP_RET_FAIL;
}

tsip_ret_t r_tsip_kdf_hmac_resume_update (tsip_kdf_hmac_handle_t * p_handle,
                                          const uint8_t          * p_message,
                                          uint64_t                 message_length)
{
    FSP_PARAMETER_NOT_USED(p_handle);
    FSP_PARAMETER_NOT_USED(p_message);
    FSP_PARAMETER_NOT_USED(message_length);

    return TSIP_RET_FAIL;
}

tsip_ret_t r_tsip_kdf_hmac_update (tsip_kdf_hmac_handle_t * p_handle, const uint8_t * p_message,
                                   uint64_t message_length)
{
    FSP_PARAMETER_NOT_USED(p_handle);
    FSP_PARAMETER_NOT_USED(p_message);
    FSP_PARAMETER_NOT_USED(message_length);

    return TSIP_RET_FAIL;
}

tsip_ret_t r_tsip_kdf_hmac_suspend (tsip_kdf_hmac_handle_t * p_handle)
{
    FSP_PARAMETER_NOT_USED(p_handle);

    return TSIP_RET_FAIL;
}

tsip_ret_t r_tsip_kdf_hmac_init_final (tsip_kdf_hmac_handle_t * p_handle, uint8_t * p_mac)
{
    FSP_PARAMETER_NOT_USED(p_handle);
    FSP_PARAMETER_NOT_USED(p_mac);

    return TSIP_RET_FAIL;
}

tsip_ret_t r_tsip_kdf_hmac_resume_final (tsip_kdf_hmac_handle_t * p_handle, uint8_t * p_mac)
{
    FSP_PARAMETER_NOT_USED(p_handle);
    FSP_PARAMETER_NOT_USED(p_mac);

    return TSIP_RET_FAIL;
}

tsip_ret_t r_tsip_kdf_hmac_final (tsip_kdf_hmac_handle_t * p_handle, uint8_t * p_mac)
{
    FSP_PARAMETER_NOT_USED(p_handle);
    FSP_PARAMETER_NOT_USED(p_mac);

    return TSIP_RET_FAIL;
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Set sha final block.
 *
 * @param[in]  p_message            Last block_message.
 * @param[in]  message_length       Byte length of message.(Must be (128 - 9)byte or less)
 * @param[in]  total_message_length Total message length.
 * @param[out] p_last_block         Last block data (This area is need 128byte).
 * @param[out] p_last_block_length  Last block length.
 *
 * @return void.
 **********************************************************************************************************************/
static void set_sha2_final_block (const uint8_t * p_message,
                                  uint64_t        message_length,
                                  uint64_t        total_message_length,
                                  uint8_t       * p_last_block,
                                  uint32_t      * p_last_block_length)
{
    tsip_dword_data_t total_bit_length = {.dword = total_message_length << 3};

    memset(&p_last_block[message_length], 0, (size_t) (SHA_BLOCK8_LEN * 2 - message_length));
    memcpy(p_last_block, p_message, (size_t) message_length);
    p_last_block[message_length] = SHA_STOP_BIT;

    if (SHA_BLOCK8_LEN >= (SHA_PADDING_DATA_LEN + message_length)) /* another block unnecessary */
    {
        /* Casting uint64_t data to uint8_t data array. */
        p_last_block[SHA_BLOCK8_LEN - 8] = total_bit_length.byte.pos_8th;
        p_last_block[SHA_BLOCK8_LEN - 7] = total_bit_length.byte.pos_7th;
        p_last_block[SHA_BLOCK8_LEN - 6] = total_bit_length.byte.pos_6th;
        p_last_block[SHA_BLOCK8_LEN - 5] = total_bit_length.byte.pos_5th;
        p_last_block[SHA_BLOCK8_LEN - 4] = total_bit_length.byte.pos_4th;
        p_last_block[SHA_BLOCK8_LEN - 3] = total_bit_length.byte.pos_3rd;
        p_last_block[SHA_BLOCK8_LEN - 2] = total_bit_length.byte.pos_2nd;
        p_last_block[SHA_BLOCK8_LEN - 1] = total_bit_length.byte.pos_1st;
        p_last_block_length[0]           = SHA_BLOCK8_LEN;
    }
    else
    {
        /* another block necessary */
        /* Casting uint64_t data to uint8_t data array. */
        p_last_block[(2 * SHA_BLOCK8_LEN) - 8] = total_bit_length.byte.pos_8th;
        p_last_block[(2 * SHA_BLOCK8_LEN) - 7] = total_bit_length.byte.pos_7th;
        p_last_block[(2 * SHA_BLOCK8_LEN) - 6] = total_bit_length.byte.pos_6th;
        p_last_block[(2 * SHA_BLOCK8_LEN) - 5] = total_bit_length.byte.pos_5th;
        p_last_block[(2 * SHA_BLOCK8_LEN) - 4] = total_bit_length.byte.pos_4th;
        p_last_block[(2 * SHA_BLOCK8_LEN) - 3] = total_bit_length.byte.pos_3rd;
        p_last_block[(2 * SHA_BLOCK8_LEN) - 2] = total_bit_length.byte.pos_2nd;
        p_last_block[(2 * SHA_BLOCK8_LEN) - 1] = total_bit_length.byte.pos_1st;
        p_last_block_length[0]                 = 2 * SHA_BLOCK8_LEN;
    }
}

#endif                                 /* 1U == TSIP_PRV_HASH_IP_TYPE */
