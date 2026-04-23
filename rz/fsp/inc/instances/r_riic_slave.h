/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_RIIC_SLAVE_H
 #define R_RIIC_SLAVE_H

 #include "bsp_api.h"
 #include "r_riic_slave_cfg.h"
 #include "r_i2c_slave_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZV
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZV_RIIC_SLAVE
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/** IIC Slave transaction enumeration */
typedef enum e_iic_slave_transfer_dir_option
{
    IIC_SLAVE_TRANSFER_DIR_MASTER_READ_SLAVE_WRITE = 0x0,
    IIC_SLAVE_TRANSFER_DIR_MASTER_WRITE_SLAVE_READ = 0x1,
    IIC_SLAVE_TRANSFER_DIR_NOT_ESTABLISHED         = 0x2
} iic_slave_transfer_dir_t;

/** I2C clock settings */
struct iic_slave_clock_settings
{
    uint8_t cks_value;                 ///< Internal Reference Clock Select
    uint8_t brl_value;                 ///< Low-level period of SCL clock
    uint8_t digital_filter_stages;     ///< Number of digital filter stages based on brl_value
};

/** I2C clock settings. Please refer to the struct iic_slave_clock_settings. */
typedef struct iic_slave_clock_settings iic_slave_clock_settings_t;

/** I2C control structure. DO NOT INITIALIZE. */
struct st_iic_slave_instance_ctrl
{
    i2c_slave_cfg_t const * p_cfg;               // Information describing I2C device
    uint32_t                open;                // Flag to determine if the device is open
    R_RIIC0_Type          * p_reg;               // Base register for this channel

    /* Current transfer information. */
    uint8_t     * p_buff;                        // Holds the data associated with the transfer
    uint32_t      total;                         // Holds the total number of data bytes to transfer
    uint32_t      remain;                        // Tracks the remaining data bytes to transfer
    uint32_t      loaded;                        // Tracks the number of data bytes written to the register
    uint32_t      transaction_count;             // Tracks the actual number of transactions
    volatile bool notify_request;                // Track whether the master request is notified to the application
    volatile iic_slave_transfer_dir_t direction; // Holds the direction of the data byte transfer
    volatile bool do_dummy_read;                 // Tracks whether a dummy read is issued on the first RX
 #if (RIIC_SLAVE_CFG_DMAC_ENABLE)
    volatile bool activation_on_rxi;             // Tracks whether the transfer is activated on RXI interrupt
    volatile bool activation_on_txi;             // Tracks whether the transfer is activated on TXI interrupt
 #endif
    volatile bool start_interrupt_enabled;       // Tracks whether the start interrupt is enabled
    volatile bool transaction_completed;         // Tracks whether previous transaction restarted

    /* Pointer to callback and optional working memory */
    void (* p_callback)(i2c_slave_callback_args_t *);
    i2c_slave_callback_args_t * p_callback_memory;

    /* Pointer to context to be passed into callback function */
    void * p_context;
};

/** I2C control structure. DO NOT INITIALIZE. Please refer to the struct st_iic_slave_instance_ctrl. */
typedef struct st_iic_slave_instance_ctrl iic_slave_instance_ctrl_t;

/** R_IIC_SLAVE extended configuration */
struct st_riic_slave_extended_cfg
{
    iic_slave_clock_settings_t clock_settings; ///< I2C Clock settings
    IRQn_Type naki_irq;                        ///< NACK IRQ Number
    IRQn_Type sti_irq;                         ///< Start condition IRQ Number
    IRQn_Type spi_irq;                         ///< Stop condition IRQ Number
    IRQn_Type ali_irq;                         ///< Arbitration lost IRQ Number
    IRQn_Type tmoi_irq;                        ///< Timeout IRQ Number
    void    * p_reg;                           ///< Register base address for specified channel
};

/** R_IIC_SLAVE extended configuration. Please refer to the struct st_riic_slave_extended_cfg. */
typedef struct st_riic_slave_extended_cfg riic_slave_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 ***********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern i2c_slave_api_t const g_i2c_slave_on_iic;

/** @endcond */

/***********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/

fsp_err_t R_RIIC_SLAVE_Open(i2c_slave_ctrl_t * const p_api_ctrl, i2c_slave_cfg_t const * const p_cfg);
fsp_err_t R_RIIC_SLAVE_Read(i2c_slave_ctrl_t * const p_api_ctrl, uint8_t * const p_dest, uint32_t const bytes);
fsp_err_t R_RIIC_SLAVE_Write(i2c_slave_ctrl_t * const p_api_ctrl, uint8_t * const p_src, uint32_t const bytes);
fsp_err_t R_RIIC_SLAVE_Close(i2c_slave_ctrl_t * const p_api_ctrl);
fsp_err_t R_RIIC_SLAVE_CallbackSet(i2c_slave_ctrl_t * const          p_api_ctrl,
                                   void (                          * p_callback)(i2c_slave_callback_args_t *),
                                   void * const                      p_context,
                                   i2c_slave_callback_args_t * const p_callback_memory);

/*******************************************************************************************************************//**
 * @} (end defgroup RIIC_SLAVE)
 ***********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 // R_RIIC_SLAVE_H
