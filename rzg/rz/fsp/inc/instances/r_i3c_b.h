/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_I3C_B_H
 #define R_I3C_B_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "r_i3c_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** There are two different versions of the RA2E2 MCU and the error recovery procedure is different for each version. */
 #define I3C_B_ERROR_RECOVERY_VERSION_1        (0U) ///< Support error recovery procedure for chip version 1.
 #define I3C_B_ERROR_RECOVERY_VERSION_2        (1U) ///< Support error recovery procedure for chip version 2.
 #define I3C_B_ERROR_RECOVERY_VERSION_BOTH     (2U) ///< Support error recovery procedure for chip version 1 and version 2.

/** Index for selecting the device defined in the extended address table. */
 #define I3C_B_DEVICE_INDEX_EXTENDED_DEVICE    (1U << 5U)

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZG
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZG_I3C_B
 * @{
 **********************************************************************************************************************/

/* Event Status Provided by the callback. */

/** @anchor RZG_I3C_B_EVENT_STATUS_SUCCESS */
 #define I3C_B_EVENT_STATUS_SUCCESS              (0x0)  ///< The transfer was completed as expected.

/** @anchor RZG_I3C_B_EVENT_STATUS_PARITY */
 #define I3C_B_EVENT_STATUS_PARITY               (0x2)  ///< A parity error was detected.

/** @anchor RZG_I3C_B_EVENT_STATUS_FRAME */
 #define I3C_B_EVENT_STATUS_FRAME                (0x3)  ///< A frame error was detected.

/** @anchor RZG_I3C_B_EVENT_STATUS_ADDRESS_HEADER */
 #define I3C_B_EVENT_STATUS_ADDRESS_HEADER       (0x4)  ///< An Address Header error was detected.

/** @anchor RZG_I3C_B_EVENT_STATUS_NACK */
 #define I3C_B_EVENT_STATUS_NACK                 (0x5)  ///< The transfer was NACK'd.

/** @anchor RZG_I3C_B_EVENT_STATUS_OVERFLOW */
 #define I3C_B_EVENT_STATUS_OVERFLOW             (0x6)  ///< A Receive FIFO overflow or Transmit FIFO underflow occurred.

/** @anchor RZG_I3C_B_EVENT_STATUS_ABORTED_TO_MASTER */
 #define I3C_B_EVENT_STATUS_ABORTED_TO_MASTER    (0x7)  ///< In slave mode, the write transfer was ended via the 'T' bit.

/** @anchor RZG_I3C_B_EVENT_STATUS_ABORTED */
 #define I3C_B_EVENT_STATUS_ABORTED              (0x8)  ///< In master mode, the transfer was aborted.

/** @anchor RZG_I3C_B_EVENT_STATUS_IBI_NACK_DISABLED */
 #define I3C_B_EVENT_STATUS_IBI_NACK_DISABLED    (0x20) ///< An IBI was NACK'd and the a DISEC command was sent.

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Bitrate settings that can be selected at run-time using @ref i3c_api_t::deviceSelect. */
typedef enum e_i3c_b_bitrate_mode
{
    I3C_B_BITRATE_MODE_I2C_STDBR         = 0U, ///< Use the period settings defined in STDBRH/L.
    I3C_B_BITRATE_MODE_I2C_EXTBR         = 1U, ///< Use the period settings defined in EXTBRH/L.
    I3C_B_BITRATE_MODE_I3C_SDR0_STDBR    = 0U, ///< Use the period settings defined in STDBRH/L (I3C Devices only).
    I3C_B_BITRATE_MODE_I3C_SDR1_EXTBR    = 1U, ///< Use the period settings defined in EXTBRH/L (I3C Devices only).
    I3C_B_BITRATE_MODE_I3C_SDR2_STDBR_X2 = 2U, ///< Use the period settings defined in STDBRH/L x 2 (I3C Devices only).
    I3C_B_BITRATE_MODE_I3C_SDR3_EXTBR_X2 = 3U, ///< Use the period settings defined in EXTBRH/L x 2 (I3C Devices only).
    I3C_B_BITRATE_MODE_I3C_SDR4_EXTBR_X4 = 4U, ///< Use the period settings defined in EXTBRH/L x 4 (I3C Devices only).
} i3c_b_bitrate_mode_t;

/** Supported activity states for ENTASn Command (See ENTASn in the MIPI I3C Specification v1.0). */
typedef enum e_i3c_b_activity_state
{
    I3C_B_ACTIVITY_STATE_ENTAS0 = 0U,  ///< Activity Interval (1 microsecond).
    I3C_B_ACTIVITY_STATE_ENTAS1 = 1U,  ///< Activity Interval (100 microseconds).
    I3C_B_ACTIVITY_STATE_ENTAS2 = 2U,  ///< Activity Interval (2 milliseconds).
    I3C_B_ACTIVITY_STATE_ENTAS3 = 3U,  ///< Activity Interval (50 milliseconds).
} i3c_b_activity_state_t;

/** Maximum Sustained Data Rate for non-CCC messages sent by Master Device to Slave Device (See GETMXDS in the MIPI I3C Specification v1.0). */
typedef enum e_i3c_b_data_rate_setting
{
    I3C_B_DATA_RATE_SETTING_FSCL_MAX = 0, ///< There is no data rate limit.
    I3C_B_DATA_RATE_SETTING_8MHZ     = 1, ///< The max sustained data rate is 8 Mhz.
    I3C_B_DATA_RATE_SETTING_6MHZ     = 2, ///< The max sustained data rate is 6 Mhz.
    I3C_B_DATA_RATE_SETTING_4MHZ     = 3, ///< The max sustained data rate is 4 Mhz.
    I3C_B_DATA_RATE_SETTING_2MHZ     = 4, ///< The max sustained data rate is 2 Mhz.
} i3c_b_data_rate_setting_t;

/** Clock to Data Turnaround Time (See GETMXDS in the MIPI I3C Specification v1.0). */
typedef enum e_i3c_b_clock_data_turnaround
{
    I3C_B_CLOCK_DATA_TURNAROUND_8NS      = 0, ///< Clock to turnaround time is 8 nanoseconds or less.
    I3C_B_CLOCK_DATA_TURNAROUND_9NS      = 1, ///< Clock to turnaround time is 9 nanoseconds or less.
    I3C_B_CLOCK_DATA_TURNAROUND_10NS     = 2, ///< Clock to turnaround time is 10 nanoseconds or less.
    I3C_B_CLOCK_DATA_TURNAROUND_11NS     = 3, ///< Clock to turnaround time is 11 nanoseconds or less.
    I3C_B_CLOCK_DATA_TURNAROUND_12NS     = 4, ///< Clock to turnaround time is 12 nanoseconds or less.
    I3C_B_CLOCK_DATA_TURNAROUND_EXTENDED = 7, ///< Clock to turnaround time is greater than 12 nanoseconds.
} i3c_b_clock_data_turnaround_t;

/** Clock stalling settings. */
struct st_i3c_b_clock_stalling
{
    uint32_t assigned_address_phase_enable : 1; ///< Enable Clock Stalling during the address phase of the ENTDAA command.
    uint32_t transition_phase_enable       : 1; ///< Enable Clock Stalling during the transition bit in read transfers.
    uint32_t parity_phase_enable           : 1; ///< Enable Clock Stalling during the parity bit period in write transfers.
    uint32_t ack_phase_enable              : 1; ///< Enable Clock Stalling during the ACK/NACK phase.
    uint16_t clock_stalling_time;               ///< The amount of time to stall the clock in I3C source clock ticks.
};

/** Clock stalling settings. Please refer to the struct st_i3c_b_clock_stalling. */
typedef struct st_i3c_b_clock_stalling i3c_b_clock_stalling_t;

/** Bitrate settings for configuring the SCL clock frequency. */
struct st_i3c_b_bitrate_settings
{
    uint32_t stdbr;                    ///< The standard bitrate settings.
    uint32_t extbr;                    ///< The extended bitrate settings.

    /** Clock Stalling settings (See Master Clock Stalling in the MIPI I3C Specification v1.0). */
    i3c_b_clock_stalling_t clock_stalling;
};

/** Bitrate settings for configuring the SCL clock frequency. Please refer to the struct st_i3c_b_bitrate_settings. */
typedef struct st_i3c_b_bitrate_settings i3c_b_bitrate_settings_t;

/** Settings for controlling the drivers behavior in response to IBIs. */
struct st_i3c_b_ibi_control
{
    uint32_t hot_join_acknowledge                : 1; ///< If false, NACK all Hot Join requests.
    uint32_t notify_rejected_hot_join_requests   : 1; ///< Notify the application when an IBI Hot-Join request has been NACK'd.
    uint32_t notify_rejected_mastership_requests : 1; ///< Notify the application when an IBI Mastership request has been NACK'd.
    uint32_t notify_rejected_interrupt_requests  : 1; ///< Notify the application when an IBI Interrupt request has been NACK'd.
};

/** Settings for controlling the drivers behavior in response to IBIs. Please refer to the struct st_i3c_b_ibi_control. */
typedef struct st_i3c_b_ibi_control i3c_b_ibi_control_t;

/** Default configuration settings for the slave response to Direct Get Common Command Codes. */
struct st_i3c_b_slave_command_response_info
{
    /** Slave Event Settings (See ENEC and DISEC in the MIPI I3C Specification v1.0). */
    bool inband_interrupt_enable;      ///< Enable IBI interrupts.
    bool mastership_request_enable;    ///< Enable Mastership requests.
    bool hotjoin_request_enable;       ///< Enable Hot-Join requests.

    /** Starting Activity State (See ENTASn in the MIPI I3C Specification v1.0). */
    i3c_b_activity_state_t activity_state;

    /** Max Write Length (See SETMWL and GETMWL in the MIPI I3C Specification v1.0). */
    uint16_t write_length;

    /** Max Read Length (See SETMRL and GETMRL in the MIPI I3C Specification v1.0). */
    uint16_t read_length;

    /** Number of bytes that will be written by an IBI (See SETMRL and GETMRL in the MIPI I3C Specification v1.0). */
    uint8_t ibi_payload_length;

    /** Max Data Rate Settings (See GETMXDS in the MIPI I3C Specification v1.0). */
    i3c_b_data_rate_setting_t     write_data_rate;       ///< Max Write Data Rate.
    i3c_b_data_rate_setting_t     read_data_rate;        ///< Max Read Data Rate.
    i3c_b_clock_data_turnaround_t clock_data_turnaround; ///< Max Data Speed Turnaround.
    bool     read_turnaround_time_enable;                ///< Enable transmission of the of the Max Read Max Read Turnaround Time.
    uint32_t read_turnaround_time;                       ///< Max Read Turnaround Time.

    /** This byte represents the Slave’s internal oscillator frequency in increments of 0.5 MHz (500kHz), up to 127.5 MHz.
     * (See GETXTIME in the MIPI I3C Specification v1.1). */
    uint8_t oscillator_frequency;

    /** Oscillator inaccuracy in 0.5% increments of 0% up to 25.5% (See GETXTIME in the MIPI I3C Specification v1.1). */
    uint8_t oscillator_inaccuracy;
};

/** Default configuration settings for the slave response to Direct Get Common Command Codes. Please refer to the struct st_i3c_b_slave_command_response_info. */
typedef struct st_i3c_b_slave_command_response_info i3c_b_slave_command_response_info_t;

/** Buffer descriptor for keeping track of a read transfer. */
struct st_i3c_b_read_buffer_descriptor
{
    uint8_t * p_buffer;                ///< Pointer to a buffer for storing data that has been read.
    uint32_t  count;                   ///< Number of bytes that have been read.
    uint32_t  buffer_size;             ///< Total size of the buffer.

    /** Flag for keeping track of whether the @ref I3C_EVENT_READ_BUFFER_FULL callback has been issued. */
    bool read_request_issued;
};

/** Buffer descriptor for keeping track of a read transfer. Please refer to the struct st_i3c_b_read_buffer_descriptor. */
typedef struct st_i3c_b_read_buffer_descriptor i3c_b_read_buffer_descriptor_t;

/** Buffer descriptor for keeping track of a write transfer. */
struct st_i3c_b_write_buffer_descriptor
{
    uint8_t * p_buffer;                ///< Pointer to a buffer that will be read during a write transfer.
    uint32_t  count;                   ///< Number of bytes that have been written.
    uint32_t  buffer_size;             ///< Total size of the buffer.
};

/** Buffer descriptor for keeping track of a write transfer. Please refer to the struct st_i3c_b_write_buffer_descriptor. */
typedef struct st_i3c_b_write_buffer_descriptor i3c_b_write_buffer_descriptor_t;

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref i3c_api_t::open is called. */
struct st_i3c_b_instance_ctrl
{
    uint32_t                            open;                  ///< Indicates whether the open() API has been successfully called.
    R_I3C_B0_Type                     * p_reg;                 ///< Base register for this channel
    volatile uint32_t                   internal_state;        ///< Used to track the current state of the driver.
    uint8_t                             current_command_code;  ///< The current Common Command Code that is being transferred.
    uint32_t                            device_index;          ///< The device index selected using @ref i3c_api_t::deviceSelect.
    i3c_b_bitrate_mode_t                device_bitrate_mode;   ///< Runtime bitrate settings to use for the next transfer.
    i3c_slave_info_t current_slave_info BSP_ALIGN_VARIABLE(4); ///< The last @ref s_i3c_slave_info read during ENTDAA.

    uint32_t next_word;                                        ///< The next word that will be written to the FIFO.
    uint32_t ibi_next_word;                                    ///< The next word that will be written to the IBI FIFO.
    i3c_b_write_buffer_descriptor_t write_buffer_descriptor;   ///< Buffer descriptor for keeping track of a write transfer.
    i3c_b_read_buffer_descriptor_t  read_buffer_descriptor;    ///< Buffer descriptor for keeping track of a read transfer.
    i3c_b_read_buffer_descriptor_t  ibi_buffer_descriptor;     ///< Buffer descriptor for keeping track of an IBI read/write transfer.
    volatile uint32_t               read_transfer_count_final; ///< The total number of bytes read during a read transfer.
    volatile uint32_t               ibi_transfer_count_final;  ///< The total number of bytes read during an IBI transfer.
    i3c_cfg_t const               * p_cfg;                     ///< A pointer to the configuration structure provided during open.
};

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref i3c_api_t::open is called. Please refer to the struct st_i3c_b_instance_ctrl. */
typedef struct st_i3c_b_instance_ctrl i3c_b_instance_ctrl_t;

/** Extended configuration for r_i3c_b. */
struct st_i3c_b_extended_cfg
{
    i3c_b_bitrate_settings_t bitrate_settings; ///< Bitrate settings configuring the frequency and duty cycle for SCL.
    i3c_b_ibi_control_t      ibi_control;      ///< Configure the driver's behavior in response to IBIs.

    /**
     * The time in I3C reference clock ticks needed in order to detect the bus free condition
     * (See "Bus Free Condition" in the MIPI I3C Specification v1.0).
     */
    uint32_t bus_free_detection_time;

    /**
     * The time in I3C reference clock ticks needed in order to detect the bus available condition
     * (See "Bus Available Condition" in the MIPI I3C Specification v1.0).
     */
    uint32_t bus_available_detection_time;

    /**
     * The time in I3C reference clock ticks needed in order to detect the bus idle condition
     * (See "Bus Idle Condition" in the MIPI I3C Specification v1.0).
     */
    uint32_t bus_idle_detection_time;

    bool timeout_detection_enable;     ///< Notify the application if SCL is stuck high or low.

    /** Initial settings for configuring the slave's responses to received commands. */
    i3c_b_slave_command_response_info_t slave_command_response_info;

    IRQn_Type resp_irq;                ///< Response Queue Full IRQ number.
    IRQn_Type rx_irq;                  ///< Receive FIFO Full IRQ number.
    IRQn_Type tx_irq;                  ///< Transmit FIFO Empty IRQ number.
    IRQn_Type rcv_irq;                 ///< Receive Status Queue Full IRQ number.
    IRQn_Type ibi_irq;                 ///< IBI IRQ number.
    IRQn_Type st_irq;                  ///< Start condition IRQ Number.
    IRQn_Type sp_irq;                  ///< Stop condition IRQ Number
    IRQn_Type tmo_irq;                 ///< Timeout IRQ Number
    IRQn_Type ierr_irq;                ///< Non-recoverable internal error IRQ Numbe
    IRQn_Type terr_irq;                ///< Transfer Error IRQ Number
    IRQn_Type abort_irq;               ///< Transfer Abort IRQ Number
    IRQn_Type wu_irq;                  ///< Wake-up IRQ Number
    uint8_t   ipl;                     ///< Interrupt Priority for Resp, Rx, Tx, and RCV IRQs.
    uint8_t   eei_ipl;                 ///< Error and Event Interrupt Priority.
    void    * p_reg;                   ///< Register base address for specified channel
};

/** Extended configuration for r_i3c_b. Please refer to the struct st_i3c_b_extended_cfg. */
typedef struct st_i3c_b_extended_cfg i3c_b_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const i3c_api_t g_i3c_on_i3c;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_I3C_B_Open(i3c_ctrl_t * const p_api_ctrl, i3c_cfg_t const * const p_cfg);
fsp_err_t R_I3C_B_Enable(i3c_ctrl_t * const p_api_ctrl);
fsp_err_t R_I3C_B_DeviceCfgSet(i3c_ctrl_t * const p_api_ctrl, i3c_device_cfg_t const * const p_device_cfg);
fsp_err_t R_I3C_B_MasterDeviceTableSet(i3c_ctrl_t * const                   p_api_ctrl,
                                       uint32_t                             device_index,
                                       i3c_device_table_cfg_t const * const p_device_table_cfg);
fsp_err_t R_I3C_B_SlaveStatusSet(i3c_ctrl_t * const p_api_ctrl, i3c_device_status_t status);
fsp_err_t R_I3C_B_DeviceSelect(i3c_ctrl_t * const p_api_ctrl, uint32_t device_index, uint32_t bitrate_mode);
fsp_err_t R_I3C_B_DynamicAddressAssignmentStart(i3c_ctrl_t * const            p_api_ctrl,
                                                i3c_address_assignment_mode_t address_assignment_mode,
                                                uint32_t                      starting_device_index,
                                                uint32_t                      device_count);
fsp_err_t R_I3C_B_CommandSend(i3c_ctrl_t * const                     p_api_ctrl,
                              i3c_command_descriptor_t const * const p_command_descriptor);
fsp_err_t R_I3C_B_Write(i3c_ctrl_t * const p_api_ctrl, uint8_t const * const p_data, uint32_t length, bool restart);
fsp_err_t R_I3C_B_Read(i3c_ctrl_t * const p_api_ctrl, uint8_t * const p_data, uint32_t length, bool restart);
fsp_err_t R_I3C_B_IbiWrite(i3c_ctrl_t * const    p_api_ctrl,
                           i3c_ibi_type_t        ibi_type,
                           uint8_t const * const p_data,
                           uint32_t              length);
fsp_err_t R_I3C_B_IbiRead(i3c_ctrl_t * const p_api_ctrl, uint8_t * const p_data, uint32_t length);
fsp_err_t R_I3C_B_Close(i3c_ctrl_t * const p_api_ctrl);

/*******************************************************************************************************************//**
 * @} (end defgroup I3C_B)
 **********************************************************************************************************************/
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
