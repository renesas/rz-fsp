/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_NAND_FLASH_API_H
 #define R_NAND_FLASH_API_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Includes board and MCU related header files. */
 #include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZT
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @ingroup RZT_RENESAS_STORAGE_INTERFACES
 * @defgroup RZT_NAND_FLASH_API NAND Flash Interface
 * @brief Interface for accessing NAND Flash devices.
 *
 * @section RZT_NAND_FLASH_API_SUMMARY Summary
 * The NAND Flash interface provides APIs and definitions for ONFI-compliant communication in NAND Flash memory devices.
 *
 * @{
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Device status */
typedef enum e_nand_flash_device_status
{
    NAND_FLASH_DEVICE_STATUS_READY,    ///< The device is in ready state.
    NAND_FLASH_DEVICE_STATUS_BUSY,     ///< The device is in busy state.
} nand_flash_device_status_t;

/** Events that can trigger a callback function */
typedef enum e_nand_flash_event
{
    NAND_FLASH_EVENT_READ_COMPLETE        = 0x00000001, ///< Read complete
    NAND_FLASH_EVENT_READ_ERROR           = 0x00000002, ///< Read failed
    NAND_FLASH_EVENT_READ_TIMEOUT         = 0x00000004, ///< Read timeout
    NAND_FLASH_EVENT_WRITE_COMPLETE       = 0x00000008, ///< Write complete
    NAND_FLASH_EVENT_WRITE_ERROR          = 0x00000010, ///< Write failed
    NAND_FLASH_EVENT_WRITE_TIMEOUT        = 0x00000020, ///< Write timeout
    NAND_FLASH_EVENT_ERASE_COMPLETE       = 0x00000040, ///< Erase complete
    NAND_FLASH_EVENT_ERASE_ERROR          = 0x00000080, ///< Erase failed
    NAND_FLASH_EVENT_ERASE_TIMEOUT        = 0x00000100, ///< Erase timeout
    NAND_FLASH_EVENT_RESET_COMPLETE       = 0x00000200, ///< Reset complete
    NAND_FLASH_EVENT_RESET_ERROR          = 0x00000400, ///< Reset failed
    NAND_FLASH_EVENT_RESET_TIMEOUT        = 0x00000800, ///< Reset timeout
    NAND_FLASH_EVENT_SET_FEATURE_COMPLETE = 0x00001000, ///< Set feature complete
    NAND_FLASH_EVENT_SET_FEATURE_ERROR    = 0x00002000, ///< Set feature failed
    NAND_FLASH_EVENT_SET_FEATURE_TIMEOUT  = 0x00004000, ///< Set feature timeout
    NAND_FLASH_EVENT_COPYBACK_COMPLETE    = 0x00008000, ///< Copy back complete
    NAND_FLASH_EVENT_COPYBACK_ERROR       = 0x00010000, ///< Copy back failed
    NAND_FLASH_EVENT_COPYBACK_TIMEOUT     = 0x00020000, ///< Copy back timeout
} nand_flash_event_t;

/** Selected page information for read or write */
struct st_nand_flash_device_page
{
    uint32_t row_address;              ///< Row address of the NAND Flash
    uint32_t page_count;               ///< Number of pages to read or write
};

/** Selected page information for read or write. Please refer to the struct st_nand_flash_device_page. */
typedef struct st_nand_flash_device_page nand_flash_device_page_t;

/** Data buffer information for read or write */
struct st_nand_flash_data_buffer
{
    uint8_t * p_main_data_buffer;      ///< Address of the main data buffer
    uint8_t * p_oob_data_buffer;       ///< Address of the OOB data buffer
};

/** Data buffer information for read or write. Please refer to the struct st_nand_flash_data_buffer. */
typedef struct st_nand_flash_data_buffer nand_flash_data_buffer_t;

/** Features supported bytes in parameter page for the NAND Flash */
struct st_nand_flash_device_feature
{
    union
    {
        uint16_t device_features;

        struct
        {
            uint16_t supports_16_bit_data_bus_width                    : 1;
            uint16_t supports_multi_lun_operations                     : 1;
            uint16_t supports_non_sequential_page_programming          : 1;
            uint16_t supports_interleaved_program_and_erase_operations : 1;
            uint16_t supports_odd_to_even_page_copyback                : 1;
            uint16_t supports_synchronous_ddr_mode                     : 1;
            uint16_t supports_interleaved_read_operations              : 1;
            uint16_t supports_extended_parameter_page                  : 1;
            uint16_t supports_program_page_register_clear_enhancement  : 1;
            uint16_t supports_eznand                                   : 1;
            uint16_t supports_nv_ddr_2                                 : 1;
            uint16_t supports_volume_addressing                        : 1;
            uint16_t supports_external_vpp                             : 1;
            uint16_t supports_nv_ddr_3                                 : 1;
            uint16_t supports_zq_calibration                           : 1;
            uint16_t supports_package_eletrical_specification          : 1;
        } device_features_bit;
    };
};

/** Features supported bytes in parameter page for the NAND Flash. Please refer to the struct st_nand_flash_device_feature. */
typedef struct st_nand_flash_device_feature nand_flash_device_feature_t;

/** Optional commands bytes in parameter page for the NAND Flash */
struct st_nand_flash_optional_commands
{
    union
    {
        uint16_t optional_commands;

        struct
        {
            uint16_t supports_page_cache_program_command    : 1;
            uint16_t supports_read_cache_command            : 1;
            uint16_t supports_get_and_set_features          : 1;
            uint16_t supports_read_status_enhanced_command  : 1;
            uint16_t supports_copyback                      : 1;
            uint16_t supports_read_unique_id                : 1;
            uint16_t supports_change_read_column_enhanced   : 1;
            uint16_t supports_change_row_address_for_onfi   : 1;
            uint16_t supports_change_small_data_move        : 1;
            uint16_t supports_reset_lun                     : 1;
            uint16_t supports_volume_select                 : 1;
            uint16_t supports_odt_configure                 : 1;
            uint16_t supports_lun_get_and_lun_set_features  : 1;
            uint16_t supports_zq_calibration_long_and_short : 1;
            uint16_t reserved                               : 2;
        } optional_commands_bit;
    };
};

/** Optional commands bytes in parameter page for the NAND Flash Please refer to the struct st_nand_flash_optional_commands. */
typedef struct st_nand_flash_optional_commands nand_flash_optional_commands_t;

/** Timing mode support bytes in parameter page for the NAND Flash */
struct st_nand_flash_timing_mode
{
    union
    {
        uint16_t timing_modes;

        struct
        {
            uint16_t supports_timing_mode_0 : 1;
            uint16_t supports_timing_mode_1 : 1;
            uint16_t supports_timing_mode_2 : 1;
            uint16_t supports_timing_mode_3 : 1;
            uint16_t supports_timing_mode_4 : 1;
            uint16_t supports_timing_mode_5 : 1;
            uint16_t reserved               : 10;
        } timing_modes_bit;
    };
};

/** Timing mode support bytes in parameter page for the NAND Flash Please refer to the struct st_nand_flash_timing_mode. */
typedef struct st_nand_flash_timing_mode nand_flash_timing_mode_t;

/** Connected NAND Flash information */
struct st_nand_flash_device_info
{
    uint32_t data_bytes_per_page;                       ///< Data bytes per page in connected NAND Flash
    uint32_t spare_bytes_per_page;                      ///< Spare bytes per page in connected NAND Flash
    uint32_t number_of_luns;                            ///< Number of LUN in connected NAND Flash
    uint32_t number_of_blocks_per_lun;                  ///< Number of blocks per LUN in connected NAND Flash
    nand_flash_device_feature_t    device_feature;      ///< Features supported bytes in parameter page for connected NAND Flash
    nand_flash_optional_commands_t optional_commands;   ///< Optional commands bytes in parameter page for connected NAND Flash
    nand_flash_timing_mode_t       support_timing_mode; ///< Timing mode support bytes in parameter page for connected NAND Flash
};

/** Connected NAND Flash information Please refer to the struct st_nand_flash_device_info. */
typedef struct st_nand_flash_device_info nand_flash_device_info_t;

/** Device status */
struct st_nand_flash_status
{
    nand_flash_device_status_t device_status; ///< Whether the device is in busy state or in ready state
};

/** Device status Please refer to the struct st_nand_flash_status. */
typedef struct st_nand_flash_status nand_flash_status_t;

/** Callback function parameter data. */
struct st_nand_flash_callback_args
{
    void const       * p_context;      ///< Placeholder for user data
    nand_flash_event_t event;          ///< The event can be used to identify what caused the callback
    uint64_t           error;          ///< Error status when an error event occurs
};

/** Callback function parameter data. Please refer to the struct st_nand_flash_callback_args. */
typedef struct st_nand_flash_callback_args nand_flash_callback_args_t;

/** User configuration structure */
struct st_nand_flash_cfg
{
    void         (* p_callback)(nand_flash_callback_args_t * p_args); ///< Pointer to callback function
    void const * p_context;                                           ///< User defined context passed into callback function
    void const * p_extend;                                            ///< Hardware dependent configuration
    IRQn_Type    irq;                                                 ///< IRQ number
    uint8_t      ipl;                                                 ///< Interrupt priority
};

/** User configuration structure Please refer to the struct st_nand_flash_cfg. */
typedef struct st_nand_flash_cfg nand_flash_cfg_t;

/** NAND Flash control block.  Allocate an instance specific control block to pass into the NAND Flash API calls. */
typedef void nand_flash_ctrl_t;

/** NAND Flash API structure. General NAND Flash functions implemented at the HAL layer follow this API. */
struct st_nand_flash_api
{
    /** Open the NAND Flash driver.
     *
     *
     * @param[in]   p_ctrl            Pointer to NAND Flash instance control block.
     * @param[in]   p_cfg             Pointer to NAND Flash instance configuration structure.
     * */
    fsp_err_t (* open)(nand_flash_ctrl_t * const p_ctrl, nand_flash_cfg_t const * const p_cfg);

    /** Close the NAND Flash driver.
     *
     *
     * @param[in]   p_ctrl            Pointer to NAND Flash instance control block.
     * */
    fsp_err_t (* close)(nand_flash_ctrl_t * const p_ctrl);

    /** Read pages of data from the NAND Flash.
     *
     *
     * @param[in]   p_ctrl            Pointer to NAND Flash instance control block.
     * @param[in]   p_src_page        Pointer to the information of the first page location and page count to read.
     * @param[in]   p_dest_buffer     Pointer to the information of data buffers to read data to.
     * @param[in]   chip_select       The target containing the pages to read.
     * */
    fsp_err_t (* read)(nand_flash_ctrl_t * const p_ctrl, nand_flash_device_page_t const * const p_src_page,
                       nand_flash_data_buffer_t * const p_dest_buffer, uint32_t const chip_select);

    /** Program pages of data to the NAND Flash.
     *
     *
     * @param[in]   p_ctrl            Pointer to NAND Flash instance control block.
     * @param[in]   p_src_buffer      Pointer to the information of data buffers to write data from.
     * @param[in]   p_dest_page       Pointer to the information of the first page location and page count to program.
     * @param[in]   chip_select       The target containing the pages to write.
     * */
    fsp_err_t (* write)(nand_flash_ctrl_t * const p_ctrl, nand_flash_data_buffer_t const * const p_src_buffer,
                        nand_flash_device_page_t const * const p_dest_page, uint32_t const chip_select);

    /** Erase blocks of data in the NAND Flash.
     *
     *
     * @param[in]   p_ctrl            Pointer to NAND Flash instance control block.
     * @param[in]   block             First block location to erase.
     * @param[in]   block_count       Number of blocks to erase.
     * @param[in]   chip_select       The target containing the blocks to be erased.
     * */
    fsp_err_t (* erase)(nand_flash_ctrl_t * const p_ctrl, uint32_t const block, uint32_t const block_count,
                        uint32_t const chip_select);

    /** Do copyback to the pages in the NAND Flash.
     *
     *
     * @param[in]   p_ctrl            Pointer to NAND Flash instance control block.
     * @param[in]   p_src_page        Pointer to the information of the first page location and page count to copy.
     * @param[in]   p_dest_page       Pointer to the information of the first page location and page count to program.
     * @param[in]   chip_select       The target containing the pages to do copyback.
     * */
    fsp_err_t (* copyback)(nand_flash_ctrl_t * const p_ctrl, nand_flash_device_page_t const * const p_src_page,
                           nand_flash_device_page_t const * const p_dest_page, uint32_t const chip_select);

    /** Read pages of raw data from the NAND Flash.
     *
     *
     * @param[in]   p_ctrl            Pointer to NAND Flash instance control block.
     * @param[in]   p_src_page        Pointer to the information of the first page location and page count to read.
     * @param[in]   p_dest            Pointer to data buffer to read data to.
     * @param[in]   chip_select       The target containing the pages to read.
     * */
    fsp_err_t (* rawRead)(nand_flash_ctrl_t * const p_ctrl, nand_flash_device_page_t const * const p_src_page,
                          uint8_t * const p_dest, uint32_t chip_select);

    /** Program pages of raw data to the NAND Flash.
     *
     *
     * @param[in]   p_ctrl            Pointer to NAND Flash instance control block.
     * @param[in]   p_src             Pointer to data buffer to write data from.
     * @param[in]   p_dest_page       Pointer to the information of the first page location and page count to program.
     * @param[in]   chip_select       The target containing the pages to write.
     * */
    fsp_err_t (* rawWrite)(nand_flash_ctrl_t * const p_ctrl, uint8_t const * const p_src,
                           nand_flash_device_page_t const * const p_dest_page, uint32_t chip_select);

    /** Reset the NAND Flash.
     *
     *
     * @param[in]   p_ctrl            Pointer to NAND Flash instance control block.
     * @param[in]   chip_select       The target to reset.
     * */
    fsp_err_t (* deviceReset)(nand_flash_ctrl_t * const p_ctrl, uint32_t const chip_select);

    /** Set a particular feature of the NAND Flash
     *
     *
     * @param[in]   p_ctrl            Pointer to NAND Flash instance control block.
     * @param[in]   feature_address   Feature address for Set Feature command in ONFI.
     * @param[in]   feature_value     Feature parameter for Set Feature command in ONFI.
     * @param[in]   chip_select       The target to send set feature command.
     * */
    fsp_err_t (* featureSet)(nand_flash_ctrl_t * const p_ctrl, uint32_t const feature_address,
                             uint32_t const feature_value, uint32_t const chip_select);

    /** Get the device status.
     *
     * @param[in]   p_ctrl            Pointer to NAND Flash instance control block.
     * @param[in]   chip_select       The target to get the device status.
     * @param[out]  p_status          Current status of the device stored here.
     */
    fsp_err_t (* statusGet)(nand_flash_ctrl_t * const p_ctrl, uint32_t const chip_select,
                            nand_flash_status_t * const p_status);

    /** Specify callback function and optional context pointer and working memory pointer.
     *
     * @param[in]   p_ctrl             Pointer to NAND Flash instance control block.
     * @param[in]   p_callback         Callback function to register
     * @param[in]   p_context          Pointer to send to callback function
     * @param[in]   p_callback_memory  Pointer to volatile memory where callback structure can be allocated.
     *                                 Callback arguments allocated here are only valid during the callback.
     */
    fsp_err_t (* callbackSet)(nand_flash_ctrl_t * p_ctrl, void (* p_callback)(nand_flash_callback_args_t *),
                              void const * const p_context, nand_flash_callback_args_t * const p_callback_memory);

    /** Get the information of the NAND Flash.
     *
     * @param[in]   p_ctrl            Pointer to NAND Flash instance control block.
     * @param[out]  p_info            Information of the device stored here.
     */
    fsp_err_t (* infoGet)(nand_flash_ctrl_t * const p_ctrl, nand_flash_device_info_t * const p_info);
};

/** NAND Flash API structure. General NAND Flash functions implemented at the HAL layer follow this API. Please refer to the struct st_nand_flash_api. */
typedef struct st_nand_flash_api nand_flash_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
struct st_nand_flash_instance
{
    nand_flash_ctrl_t      * p_ctrl;   ///< Pointer to the control structure for this instance
    nand_flash_cfg_t const * p_cfg;    ///< Pointer to the configuration structure for this instance
    nand_flash_api_t const * p_api;    ///< Pointer to the API structure for this instance
};

/** This structure encompasses everything that is needed to use an instance of this interface. Please refer to the struct st_nand_flash_instance. */
typedef struct st_nand_flash_instance nand_flash_instance_t;

/*******************************************************************************************************************//**
 * @} (end defgroup RZT_NAND_FLASH_API)
 **********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
