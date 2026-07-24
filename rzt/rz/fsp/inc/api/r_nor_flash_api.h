/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @ingroup RENESAS_STORAGE_INTERFACES
 * @defgroup NOR_FLASH_API NOR Flash Interface
 * @brief Interface for external nor flash communication.
 *
 * @section NOR_FLASH_API_SUMMARY Summary
 * The NOR Flash interface provides APIs and definitions for NOR Flash communication.
 *
 * @{
 **********************************************************************************************************************/
#ifndef R_NOR_FLASH_API_H
#define R_NOR_FLASH_API_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Register definitions, common services and error codes. */
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define NOR_FLASH_ERASE_SIZE_CHIP_ERASE    (UINT32_MAX)

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** NOR Flash chip select. */
typedef enum e_nor_flash_chip_select
{
    NOR_FLASH_CHIP_SELECT_0 = 0x00,    ///< Device connected to Chip-Select 0
    NOR_FLASH_CHIP_SELECT_1,           ///< Device connected to Chip-Select 1
    NOR_FLASH_CHIP_SELECT_2,           ///< Device connected to Chip-Select 2
    NOR_FLASH_CHIP_SELECT_3,           ///< Device connected to Chip-Select 3
    NOR_FLASH_CHIP_SELECT_4,           ///< Device connected to Chip-Select 4
    NOR_FLASH_CHIP_SELECT_5,           ///< Device connected to Chip-Select 5
    NOR_FLASH_CHIP_SELECT_6,           ///< Device connected to Chip-Select 6
    NOR_FLASH_CHIP_SELECT_7,           ///< Device connected to Chip-Select 7
} nor_flash_chip_select_t;

/** NOR Flash data bus width. */
typedef enum e_nor_flash_data_bus_width
{
    NOR_FLASH_DATA_BUS_WIDTH_8BIT  = 0x01, ///< Data bus width 8bit
    NOR_FLASH_DATA_BUS_WIDTH_16BIT = 0x02, ///< Data bus width 16bit
    NOR_FLASH_DATA_BUS_WIDTH_32BIT = 0x03, ///< Data bus width 32bit
} nor_flash_data_bus_width_t;

/** NOR Flash configuration */
typedef struct st_nor_flash_cfg
{
    nor_flash_chip_select_t    chip_select; ///< Select which device to use
    nor_flash_data_bus_width_t data_width;  ///< Select data bus width
    void const               * p_extend;    ///< NOR Flash hardware dependent configuration
} nor_flash_cfg_t;

/** Status. */
typedef struct st_nor_flash_status
{
    /** Whether or not a write is in progress. */
    bool write_in_progress;
} nor_flash_status_t;

/** NOR Flash control block.  Allocate an instance specific control block to pass into the NOR Flash API calls.
 */
typedef void nor_flash_ctrl_t;

/** NOR Flash implementations follow this API. */
typedef struct st_nor_flash_api
{
    /** Open the NOR Flash driver module.
     *
     * @param[in] p_ctrl               Pointer to a driver handle
     * @param[in] p_cfg                Pointer to a configuration structure
     **/
    fsp_err_t (* open)(nor_flash_ctrl_t * p_ctrl, nor_flash_cfg_t const * const p_cfg);

    /** Program data to the flash.
     *
     * @param[in] p_ctrl               Pointer to a driver handle
     * @param[in] p_src                The memory address of the data to write to the flash device
     * @param[in] p_dest               The location in the flash device address space to write the data to
     * @param[in] byte_count           The number of bytes to write
     **/
    fsp_err_t (* write)(nor_flash_ctrl_t * p_ctrl, uint8_t const * const p_src, uint8_t * const p_dest,
                        uint32_t byte_count);

    /** Erase a certain number of bytes of the flash.
     *
     * @param[in] p_ctrl               Pointer to a driver handle
     * @param[in] p_device_address     The location in the flash device address space to start the erase from
     * @param[in] byte_count           The number of bytes to erase. Set to NOR_FLASH_ERASE_SIZE_CHIP_ERASE to erase entire
     *                                 chip.
     **/
    fsp_err_t (* erase)(nor_flash_ctrl_t * p_ctrl, uint8_t * const p_device_address, uint32_t byte_count);

    /** Get the write or erase status of the flash.
     *
     * @param[in] p_ctrl               Pointer to a driver handle
     * @param[in] p_device_address     The location in the flash device address space to get status
     * @param[out] p_status            Current status of the flash device stored here.
     **/
    fsp_err_t (* statusGet)(nor_flash_ctrl_t * p_ctrl, uint8_t * const p_device_address,
                            nor_flash_status_t * const p_status);

    /** Close the NOR Flash driver module.
     *
     * @param[in] p_ctrl               Pointer to a driver handle
     **/
    fsp_err_t (* close)(nor_flash_ctrl_t * p_ctrl);
} nor_flash_api_t;

typedef struct st_nor_flash_instance
{
    nor_flash_ctrl_t      * p_ctrl;    ///< Pointer to the control structure for this instance
    nor_flash_cfg_t const * p_cfg;     ///< Pointer to the configuration structure for this instance
    nor_flash_api_t const * p_api;     ///< Pointer to the API structure for this instance
} nor_flash_instance_t;

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/*******************************************************************************************************************//**
 * @} (end defgroup NOR_FLASH_API)
 **********************************************************************************************************************/
