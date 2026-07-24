/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_NANDC_H
 #define R_NANDC_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include "r_nand_flash_api.h"
 #include "r_nandc_cfg.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZT
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_NANDC
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Timing Mode */
typedef enum e_nandc_timing_mode
{
    NANDC_TIMING_MODE_PERFORMANCE,     ///< Drive RE# / WE# signals in performance mode
    NANDC_TIMING_MODE_EXTEND,          ///< Drive RE# / WE# signals in extended mode
} nandc_timing_mode_t;

/** Device status detection method */
typedef enum e_nandc_device_status_detection
{
    NANDC_DEVICE_STATUS_DETECTION_POLLING,   ///< Get NAND Flash device status by polling read status command
    NANDC_DEVICE_STATUS_DETECTION_RY_BY_PIN, ///< Get NAND Flash device status by RY_BY# pin level
} nandc_device_status_detection_t;

/** ECC setting */
typedef enum e_nandc_ecc
{
    NANDC_ECC_DISABLE,                 ///< ECC disabled
    NANDC_ECC_ENABLE,                  ///< ECC enabled
} nandc_ecc_t;

/** Error correction ability for ECC */
typedef enum e_nandc_ecc_correction
{
    NANDC_ECC_CORRECTION_8_BITS,       ///< Insert ECC check-bits to enable correction of 8 bits per sector
    NANDC_ECC_CORRECTION_16_BITS,      ///< Insert ECC check-bits to enable correction of 16 bits per sector
    NANDC_ECC_CORRECTION_32_BITS,      ///< Insert ECC check-bits to enable correction of 32 bits per sector
    NANDC_ECC_CORRECTION_64_BITS,      ///< Insert ECC check-bits to enable correction of 64 bits per sector
    NANDC_ECC_CORRECTION_72_BITS,      ///< Insert ECC check-bits to enable correction of 72 bits per sector
} nandc_ecc_correction_ability_t;

/** CRC setting */
typedef enum e_nandc_crc
{
    NANDC_CRC_DISABLE,                 ///< CRC disabled
    NANDC_CRC_ENABLE,                  ///< CRC enabled
} nandc_crc_t;

/** Scrambling function setting */
typedef enum e_nandc_data_scrambling
{
    NANDC_DATA_SCRAMBLING_DISABLE,     ///< Scrambling disabled
    NANDC_DATA_SCRAMBLING_ENABLE,      ///< Scrambling enabled
} nandc_data_scrambling_t;

/** Erased page detection setting */
typedef enum e_nandc_erased_page_flag
{
    NANDC_ERASED_PAGE_FLAG_DISABLE,    ///< Erased page detection flag disabled
    NANDC_ERASED_PAGE_FLAG_ENABLE,     ///< Erased page detection flag enabled
} nandc_erased_page_flag_t;

/** Multi-plane command setting */
typedef enum e_nandc_multiplane_command
{
    NANDC_MULTIPLANE_COMMAND_DISABLE,  ///< Multi-plane command sequence disabled
    NANDC_MULTIPLANE_COMMAND_ENABLE,   ///< multi-plane command sequence enabled
} nandc_multiplane_command_t;

/** Number of planes of connected NAND Flash */
typedef enum e_nandc_multiplane_number
{
    NANDC_MULTIPLANE_NUMBER_1,         ///< Connected NAND Flash has 1 plane
    NANDC_MULTIPLANE_NUMBER_2,         ///< Connected NAND Flash has 2 planes
    NANDC_MULTIPLANE_NUMBER_4,         ///< Connected NAND Flash has 4 planes
    NANDC_MULTIPLANE_NUMBER_6,         ///< Connected NAND Flash has 6 planes
    NANDC_MULTIPLANE_NUMBER_8,         ///< Connected NAND Flash has 8 planes
} nandc_multiplane_number_t;

/** Address translation setting */
typedef enum e_nandc_remap
{
    NANDC_REMAP_DISABLE,               ///< Address translation for NAND Flash is disabled
    NANDC_REMAP_ENABLE,                ///< Address translation for NAND Flash is enabled
} nandc_remap_t;

/** NANDC interrupt source setting */
typedef enum e_nandc_int
{
    NANDC_INT_DISABLE,                 ///< The event is not used as NANDC interrupt source
    NANDC_INT_ENABLE,                  ///< The event is used as NANDC interrupt source
} nandc_int_t;

/** Controller status */
typedef enum e_nandc_controller_state
{
    NANDC_CONTROLLER_STATE_READY,      ///< The controller is in ready state
    NANDC_CONTROLLER_STATE_BUSY,       ///< The controller is in busy state
} nandc_controller_state_t;

/** Timing mode setting of connected NAND Flash */
typedef enum e_nandc_flash_timing_mode
{
    NANDC_FLASH_TIMING_MODE_0,         ///< Set timing configuration of connected NAND Flash to Timing Mode 0
    NANDC_FLASH_TIMING_MODE_1,         ///< Set timing configuration of connected NAND Flash to Timing Mode 1
    NANDC_FLASH_TIMING_MODE_2,         ///< Set timing configuration of connected NAND Flash to Timing Mode 2
    NANDC_FLASH_TIMING_MODE_3,         ///< Set timing configuration of connected NAND Flash to Timing Mode 3
} nandc_flash_timing_mode_t;

/** Timing information during communication with the NAND Flash */
struct st_nandc_timing_info
{
    uint32_t we_pulse_width;                        ///< WE_n pulse width cycles
    uint32_t we_high_hold_time;                     ///< WE_n high hold time cycles
    uint32_t re_pulse_width;                        ///< RE_n pulse width cycles
    uint32_t re_high_hold_time;                     ///< RE_n high hold time cycles
    uint32_t re_high_to_we_low_time;                ///< RE_n high to WE_n low time cycles
    uint32_t we_high_to_re_low_time;                ///< WE_n high to RE_n low time cycles
    uint32_t ale_to_data_loading_time;              ///< ALE to data loading time cycles
    uint32_t command_end_to_sr6_low;                ///< Command end timing to SR[6] low cycles
    uint32_t re_high_to_output_hiz;                 ///< RE_n high to output hi-Z cycles
    uint32_t ce_setup_time;                         ///< CE_n setup time cycles
    uint32_t ce_high_hold_time;                     ///< CE_n high hold time cycles
    uint32_t interface_and_timing_mode_change_time; ///< Interface and Timing Mode Change time cycles
};

/** Timing information during communication with the NAND Flash Please refer to the struct st_nandc_timing_info. */
typedef struct st_nandc_timing_info nandc_timing_info_t;

/** Command error status */
struct st_nandc_comnand_status
{
    union
    {
        uint64_t command_status;          ///< Raw 64-bit command status.

        struct
        {
            uint64_t command_error   : 1; ///< Incorrect controller configuration
            uint64_t ecc_err         : 1; ///< Uncorrectable ECC error
            uint64_t max_error       : 8; ///< Maximum amount of correction applied to one ECC sector
            uint64_t reserved_10     : 1;
            uint64_t erased_page     : 1; ///< Detected an erased page in the read transaction
            uint64_t device_error    : 1; ///< Device error was detected during read status operation
            uint64_t reserved_13     : 1;
            uint64_t fail            : 1; ///< Operation failed to complete successfully
            uint64_t complete        : 1; ///< Updated status information and the operation is complete
            uint64_t bus_error       : 1; ///< Received an error response on the system bus
            uint64_t di_dat_err      : 1; ///< Data integrity error was detected in the data path
            uint64_t reserved_18     : 2;
            uint64_t prot_err        : 1; ///< Programmed operation tried to modify protected area
            uint64_t reserved_21     : 3;
            uint64_t error_index     : 8; ///< The operation index number where the first error was detected
            uint64_t reserved_32     : 16;
            uint64_t pl_device_error : 8; ///< Each bit of this field indicates the device error status for the corresponding plane
            uint64_t pl_ecc_err      : 8; ///< Each bit of this field indicates the ECC error status for the corresponding plane
        } nandc_command_status_bit;
    };
};

/** Command error status Please refer to the struct st_nandc_comnand_status. */
typedef struct st_nandc_comnand_status nandc_command_status_t;

/** Controller status */
struct st_nandc_controller_status
{
    nandc_controller_state_t status;   ///< NANDC controller status is stored
};

/** Controller status Please refer to the struct st_nandc_controller_status. */
typedef struct st_nandc_controller_status nandc_controller_status_t;

/** NAND_FLASH Instance Control Block. This is private to the FSP and should not be used or modified by the application */
struct st_nandc_instance_ctrl
{
    uint32_t                 open;                     ///< Boolean to verify that the Unit has been initialized
    nand_flash_cfg_t const * p_cfg;                    ///< Pointer to initial configurations
    R_NANDC_Type           * p_reg;                    ///< Base register for this channel

    void (* p_callback)(nand_flash_callback_args_t *); ///< Pointer to callback
    nand_flash_callback_args_t * p_callback_memory;    ///< Pointer to optional callback argument memory
    void const                 * p_context;            ///< Pointer to context to be passed into callback function
};

/** NAND_FLASH Instance Control Block. This is private to the FSP and should not be used or modified by the application Please refer to the struct st_nandc_instance_ctrl. */
typedef struct st_nandc_instance_ctrl nandc_instance_ctrl_t;

/** Optional NANDC extension data structure */
struct st_nandc_extended_cfg
{
    nandc_timing_mode_t             read_enable_signal_timing_mode;  ///< RE# timing mode
    nandc_timing_mode_t             write_enable_signal_timing_mode; ///< WE# timing mode
    nandc_timing_info_t           * p_signal_timing_info;            ///< Settings of signal timing
    nandc_flash_timing_mode_t       flash_timing_mode;               ///< Timing Mode of NAND Flash defined in ONFI
    nandc_device_status_detection_t ready_status_detection_method;   ///< Device status detection method
    uint32_t    long_polling_time;                                   ///< System clock cycles after issue of erase/write/read operation before the controller starts to poll for status
    uint32_t    short_polling_time;                                  ///< Subsequent status polling interval cycles
    uint32_t    sector_bytes;                                        ///< Sector size
    uint8_t     sector_number;                                       ///< Sector number per page
    uint32_t    oob_data_size;                                       ///< Size of Out-of-Band data handled by NANDC control data function
    nandc_ecc_t ecc_enable;                                          ///< ECC setting
    nandc_ecc_correction_ability_t ecc_correction_ability;           ///< Error correction ability for ECC
    nandc_crc_t              crc_enable;                             ///< CRC setting
    uint32_t                 command_timeout_count;                  ///< Timeout cycles of NANDC thread operation
    nandc_data_scrambling_t  data_scrambling_enable;                 ///< Scrambling setting
    nandc_erased_page_flag_t erased_page_detection;                  ///< Erased page detection setting
    uint8_t erase_detection_level;                                   ///< Permissible number of 0 bits for erased page detection
    nandc_multiplane_command_t multiplane_read_enable;               ///< Multi-plane read operation setting
    nandc_multiplane_command_t multiplane_write_enable;              ///< Multi-plane write and erase operation setting
    nandc_multiplane_number_t  plane_number;                         ///< Number of Planes in NAND Flash
    uint32_t      skip_bytes_offset;                                 ///< Offset of skipped bytes
    uint32_t      skip_bytes_size;                                   ///< Number of skipped bytes
    uint32_t      skip_bytes_marker_value;                           ///< Byte pattern written in skipped bytes
    nandc_remap_t remap_enable;                                      ///< Address translation setting
    uint32_t      remap_valid_bits;                                  ///< Row address bits that address translation is applied to
    nandc_int_t   command_complete_interrupt;                        ///< Command complete interrupt source setting
    nandc_int_t   command_error_interrupt;                           ///< Command error interrupt source setting
    nandc_int_t   command_timeout_interrupt;                         ///< Command timeout interrupt source setting
    uint32_t      rb_valid_time_cycles;                              ///< Time to wait for the R/B pin to become valid before device discovery (SYS_CLK cycles)
    void        * p_reg;                                             ///< Base register
};

/** Optional NANDC extension data structure Please refer to the struct st_nandc_extended_cfg. */
typedef struct st_nandc_extended_cfg nandc_extended_cfg_t;

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const nand_flash_api_t g_nand_flash_on_nandc;

/** @endcond */

/***********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/
fsp_err_t R_NANDC_Open(nand_flash_ctrl_t * const p_ctrl, nand_flash_cfg_t const * const p_cfg);
fsp_err_t R_NANDC_Close(nand_flash_ctrl_t * const p_ctrl);
fsp_err_t R_NANDC_Read(nand_flash_ctrl_t * const              p_ctrl,
                       nand_flash_device_page_t const * const p_src_page,
                       nand_flash_data_buffer_t * const       p_dest_buffer,
                       uint32_t const                         chip_select);
fsp_err_t R_NANDC_Write(nand_flash_ctrl_t * const              p_ctrl,
                        nand_flash_data_buffer_t const * const p_src_buffer,
                        nand_flash_device_page_t const * const p_dest_page,
                        uint32_t const                         chip_select);
fsp_err_t R_NANDC_Erase(nand_flash_ctrl_t * const p_ctrl,
                        uint32_t const            block,
                        uint32_t const            block_count,
                        uint32_t const            chip_select);
fsp_err_t R_NANDC_FeatureSet(nand_flash_ctrl_t * const p_ctrl,
                             uint32_t const            feature_address,
                             uint32_t const            feature_value,
                             uint32_t const            chip_select);
fsp_err_t R_NANDC_DeviceReset(nand_flash_ctrl_t * const p_ctrl, uint32_t const chip_select);
fsp_err_t R_NANDC_StatusGet(nand_flash_ctrl_t * const   p_ctrl,
                            uint32_t const              chip_select,
                            nand_flash_status_t * const p_status);
fsp_err_t R_NANDC_CallbackSet(nand_flash_ctrl_t * const          p_ctrl,
                              void (                           * p_callback)(nand_flash_callback_args_t *),
                              void const * const                 p_context,
                              nand_flash_callback_args_t * const p_callback_memory);
fsp_err_t R_NANDC_InfoGet(nand_flash_ctrl_t * const p_ctrl, nand_flash_device_info_t * const p_info);
fsp_err_t R_NANDC_Copyback(nand_flash_ctrl_t * const              p_ctrl,
                           nand_flash_device_page_t const * const p_src_page,
                           nand_flash_device_page_t const * const p_dest_page,
                           uint32_t const                         chip_select);
fsp_err_t R_NANDC_RawRead(nand_flash_ctrl_t * const              p_ctrl,
                          nand_flash_device_page_t const * const p_src_page,
                          uint8_t * const                        p_dest,
                          uint32_t const                         chip_select);
fsp_err_t R_NANDC_RawWrite(nand_flash_ctrl_t * const              p_ctrl,
                           uint8_t const * const                  p_src,
                           nand_flash_device_page_t const * const p_dest_page,
                           uint32_t const                         chip_select);
fsp_err_t R_NANDC_RemapSet(nand_flash_ctrl_t * const p_ctrl,
                           uint32_t const            logical_address,
                           uint32_t const            physical_address);
fsp_err_t R_NANDC_RemapClear(nand_flash_ctrl_t * const p_ctrl);
fsp_err_t R_NANDC_WriteProtectEnable(nand_flash_ctrl_t * const p_ctrl,
                                     uint32_t const            start_address,
                                     uint32_t const            size,
                                     uint32_t const            index);
fsp_err_t R_NANDC_WriteProtectDisable(nand_flash_ctrl_t * const p_ctrl, uint32_t const index);
fsp_err_t R_NANDC_ControllerStatusGet(nand_flash_ctrl_t * const p_ctrl, nandc_controller_status_t * const p_status);

/*******************************************************************************************************************//**
 * @} (end defgroup NANDC)
 **********************************************************************************************************************/
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
