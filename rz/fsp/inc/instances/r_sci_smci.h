/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SCI_SMCI_H
 #define R_SCI_SMCI_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include "r_smci_api.h"
 #include "r_sci_smci_cfg.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZT
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_SCI_SMCI
 * @{
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Source clock selection options for SCI. */
typedef enum e_sci_smci_clock_source
{
    SCI_SMCI_CLOCK_SOURCE_SCI0ASYNCCLK = 0,
    SCI_SMCI_CLOCK_SOURCE_SCI1ASYNCCLK = 1,
    SCI_SMCI_CLOCK_SOURCE_SCI2ASYNCCLK = 2,
    SCI_SMCI_CLOCK_SOURCE_SCI3ASYNCCLK = 3,
    SCI_SMCI_CLOCK_SOURCE_SCI4ASYNCCLK = 4,
    SCI_SMCI_CLOCK_SOURCE_SCI5ASYNCCLK = 5,
    SCI_SMCI_CLOCK_SOURCE_PCLKM        = 6,
} sci_smci_clock_source_t;

/** SMCI instance control block. */
struct st_sci_smci_instance_ctrl
{
    /* Used to determine if the channel is configured. */
    uint32_t open;

    /* Source buffer pointer used to fill hardware TDR from transmit ISR. */
    uint8_t const * p_tx_src;

    /* Size of source buffer pointer used to fill hardware TDR from transmit ISR. */
    uint32_t tx_src_bytes;

    /* Destination buffer pointer used for receiving data. */
    uint8_t * p_rx_dest;

    /* Size of destination buffer pointer used for receiving data. */
    uint32_t rx_dest_bytes;

    /* Number of bytes received. */
    uint32_t rx_bytes_received;

    /* Pointer to the configuration block. */
    smci_cfg_t const * p_cfg;

    /* State of this instance of the SMCI. */
    smci_state_t smci_state;

    /* Base register for this channel. */
    R_SCI0_Type * p_reg;

    void (* p_callback)(smci_callback_args_t *); // Pointer to callback that is called when a smci_event_t occurs.
    smci_callback_args_t * p_callback_memory;    // Pointer to non-secure memory that can be used to pass arguments to a callback in non-secure memory.

    /* Pointer to context to be passed into callback function. */
    void * p_context;
};

/** SMCI instance control block. Please refer to the struct st_sci_smci_instance_ctrl. */
typedef struct st_sci_smci_instance_ctrl sci_smci_instance_ctrl_t;

/** Register settings to achieve a desired baud rate in Smart Card mode. */
struct st_sci_smci_baud_setting_t
{
    uint32_t computed_baud_rate;
    union
    {
        uint32_t ccr2_clock_bits;

        struct
        {
            uint32_t bcp : 3;          ///< Base Clock Pulse
            uint32_t     : 5;
            uint32_t brr : 8;          ///< Bit rate setting
            uint32_t     : 4;
            uint32_t cks : 2;          ///< Clock Select
            uint32_t     : 10;
        } ccr2_clock_bits_b;
    };
};

/** Register settings to achieve a desired baud rate in Smart Card mode. Please refer to the struct st_sci_smci_baud_setting_t. */
typedef struct st_sci_smci_baud_setting_t sci_smci_baud_setting_t;

/** SMCI on SCI device Configuration. */
struct st_sci_smci_extended_cfg
{
    sci_smci_baud_setting_t * p_smci_baud_setting; ///< Register settings for a desired baud rate.

    /** Clock source to generate SCK can either be selected as PCLKM or SCInASYNCCLK. */
    sci_smci_clock_source_t clock_source;
    void * p_reg;                                  ///< Register base address.
};

/** SMCI on SCI device Configuration. Please refer to the struct st_sci_smci_extended_cfg. */
typedef struct st_sci_smci_extended_cfg sci_smci_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const smci_api_t g_smci_on_sci;

/** @endcond */
fsp_err_t R_SCI_SMCI_Open(smci_ctrl_t * const p_ctrl, smci_cfg_t const * const p_cfg);
fsp_err_t R_SCI_SMCI_Write(smci_ctrl_t * const p_ctrl, uint8_t const * const p_src, uint32_t const bytes);
fsp_err_t R_SCI_SMCI_Read(smci_ctrl_t * const p_ctrl, uint8_t * const p_dest, uint32_t const bytes);
fsp_err_t R_SCI_SMCI_TransferModeSet(smci_ctrl_t * const                p_ctrl,
                                     smci_transfer_mode_t const * const p_transfer_mode_params);
fsp_err_t R_SCI_SMCI_BaudSet(smci_ctrl_t * const p_ctrl, void const * const p_baud_setting);
fsp_err_t R_SCI_SMCI_StatusGet(smci_ctrl_t * const p_ctrl, smci_status_t * const p_status);
fsp_err_t R_SCI_SMCI_ClockControl(smci_ctrl_t * const p_ctrl, bool clock_enable);
fsp_err_t R_SCI_SMCI_CallbackSet(smci_ctrl_t * const          p_ctrl,
                                 void (                     * p_callback)(smci_callback_args_t *),
                                 void * const                 p_context,
                                 smci_callback_args_t * const p_callback_memory);
fsp_err_t R_SCI_SMCI_Close(smci_ctrl_t * const p_ctrl);
fsp_err_t R_SCI_SMCI_BaudCalculate(smci_speed_params_t const * const p_speed_params,
                                   uint32_t                          baud_rate_error_x_1000,
                                   sci_smci_clock_source_t           clock_source,
                                   void * const                      p_baud_setting);

/*******************************************************************************************************************//**
 * @} (end addtogroup SCI_SMCI)
 **********************************************************************************************************************/
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* R_SCI_SMCI_H */
