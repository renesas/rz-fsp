/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/* To prevent primitives from being recompiled every time, bsp_api.h does not include. */

#ifndef R_RSIP_UTIL_H
#define R_RSIP_UTIL_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <stdint.h>

#if defined(__ICCARM__) && __ARM_32BIT_STATE
 #include <intrinsics.h>
#endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Byte swapping macro */
#define RSIP_PRV_BSWAP_32_C(data)    ((((data) & 0xff000000U) >> 24) | (((data) & 0x00ff0000U) >> 8) | \
                                      (((data) & 0x0000ff00U) << 8) | (((data) & 0x000000ffU) << 24))

/* Endianness */
#if defined(__GNUC__)
 #define RSIP_PRV_LITTLE_ENDIAN    (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
#elif defined(__IAR_SYSTEMS_ICC__)
 #define RSIP_PRV_LITTLE_ENDIAN    (__LITTLE_ENDIAN__)
#else
 #error Unsupported compiler.
#endif

/* Changes data endianness to big-endian. */
#if RSIP_PRV_LITTLE_ENDIAN
 #define BSWAP_32BIG_C(data)        RSIP_PRV_BSWAP_32_C(data)
#else
 #define BSWAP_32BIG_C(data)        (data)
#endif

/* Built-in byte swapping function */
#if defined(__GNUC__)
 #define RSIP_PRV_BSWAP_32(data)    __builtin_bswap32(data)
#elif defined(__ICCARM__) && __ARM_32BIT_STATE // __REV() is available only on AArch32
 #define RSIP_PRV_BSWAP_32(data)    __REV(data)
#else
 #define RSIP_PRV_BSWAP_32(data)    RSIP_PRV_BSWAP_32_C(data)
#endif

/* Static inline */
#if defined(__GNUC__)
 #define RSIP_PRV_STATIC_INLINE         __attribute__((always_inline)) static inline
#elif defined(__IAR_SYSTEMS_ICC__)
 #define RSIP_PRV_STATIC_INLINE         _Pragma("inline=forced") static inline
#else
 #define RSIP_PRV_STATIC_INLINE         static inline
#endif

/*
 * Set compiler optimization option for primitive functions.
 * GNU Toolchain: "Os"
 * IAR Embedded Workbench: "size" (enabled only if default optimization level is "high")
 * Other toolchains: no change
 */
#if defined(__GNUC__) && !defined(__CC_ARM) && !defined(__llvm__) // ARM Compiler and Clang do not support
 #define RSIP_PRV_PRIMITIVE_OPTIMIZE    __attribute__((optimize("Os")))
#elif defined(__IAR_SYSTEMS_ICC__)
 #define RSIP_PRV_PRIMITIVE_OPTIMIZE    _Pragma("optimize = size")
#else
 #define RSIP_PRV_PRIMITIVE_OPTIMIZE
#endif

/* Optional attribute */
#if !defined(RSIP_PRIMITIVE_ATTR)
 #define RSIP_PRIMITIVE_ATTR
#endif

/* Primitive function attributes */
#define RSIP_PRV_PRIMITIVE_FUNC    RSIP_PRV_PRIMITIVE_OPTIMIZE RSIP_PRIMITIVE_ATTR

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Changes data endianness to big-endian.
 *
 * bswap_32big(): For other than const variable. This inline function directly uses ISA.
 *
 * BSWAP_32BIG_C(): For const variable. This macro uses bit shift operation.
 *
 * @param[in] data 32-bit data
 *
 * @return big-endian data
 **********************************************************************************************************************/
RSIP_PRV_STATIC_INLINE uint32_t bswap_32big (uint32_t data)
{
#if RSIP_PRV_LITTLE_ENDIAN
    return RSIP_PRV_BSWAP_32(data);
#else
    return data;
#endif
}

/*******************************************************************************************************************//**
 * Converts byte data to word (4-byte) and rounds up it.
 *
 * @param[in] bytes Byte length
 *
 * @return Word length
 ***********************************************************************************************************************/
RSIP_PRV_STATIC_INLINE uint32_t r_rsip_byte_to_word_convert (const uint32_t bytes)
{
    return (bytes + 3) >> 2;
}

/*******************************************************************************************************************//**
 * Converts word (4-byte) length to byte length.
 *
 * @param[in] words Word length
 *
 * @return Byte length
 ***********************************************************************************************************************/
RSIP_PRV_STATIC_INLINE uint32_t r_rsip_word_to_byte_convert (const uint32_t words)
{
    return words << 2;
}

/*******************************************************************************************************************//**
 * Converts byte data to bit data. This function returns upper 3 digits.
 *
 * @param[in] bytes Byte length
 *
 * @return Bit length (upper 3 digits)
 ***********************************************************************************************************************/
RSIP_PRV_STATIC_INLINE uint32_t r_rsip_byte_to_bit_convert_upper (const uint64_t bytes)
{
    return (uint32_t) (bytes >> 29);
}

/*******************************************************************************************************************//**
 * Converts byte data to bit data. This function returns lower 32 digits.
 *
 * @param[in] bytes Byte length
 *
 * @return Bit length (lower 32 digits)
 ***********************************************************************************************************************/
RSIP_PRV_STATIC_INLINE uint32_t r_rsip_byte_to_bit_convert_lower (const uint64_t bytes)
{
    return (uint32_t) (bytes << 3);
}

#endif                                 /* R_RSIP_UTIL_H */
