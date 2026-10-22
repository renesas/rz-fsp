/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_sci_i2c.h"

#if SCI_I2C_CFG_DMAC_ENABLE
 #include "r_dmac.h"
#endif

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "SI2C" in ASCII, used to determine if channel is open. */
#define SCI_I2C_OPEN                                (0x53493243ULL)

#define SCI_I2C_PRV_CODE_READ                       (0x01U)
#define SCI_I2C_PRV_CODE_10BIT                      (0xF0U)

#define SCI_I2C_PRV_SLAVE_10_BIT_ADDR_LEN_ADJUST    (2U)

#define SCI_I2C_PRV_MDDR_REG_MIN                    (0x80)
#define SCI_I2C_PRV_DUMMY_WRITE_DATA_FOR_READ_OP    (0xFFU)
#define SCI_I2C_PRV_DATA_REG_MASK                   (0xFFFFFF00)
#define SCI_I2C_PRV_GENERATE_REQUEST(R, X)    ((R & ~(uint32_t) (R_SCI0_ICR_IICSDAS_Msk | R_SCI0_ICR_IICSCLS_Msk)) \
                                               | (1U << R_SCI0_ICR_IICSDAS_Pos) | (1U << R_SCI0_ICR_IICSCLS_Pos)   \
                                               | X)

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/* I2C read/write enumeration */
typedef enum e_sci_i2c_transfer_dir_option
{
    SCI_I2C_TRANSFER_DIR_WRITE = 0x0,
    SCI_I2C_TRANSFER_DIR_READ  = 0x1
} sci_i2c_transfer_dir_t;

/* DMAC TXI/RXI enumeration */
typedef enum e_sci_i2c_dmac_interrupt_trigger
{
    SCI_I2C_DMAC_INTERRUPT_TRIGGER_TXI = 0x0,
    SCI_I2C_DMAC_INTERRUPT_TRIGGER_RXI = 0x1
} sci_i2c_dmac_interrupt_trigger_t;

/**********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/* Internal helper functions */
void        sci_i2c_notify(sci_i2c_instance_ctrl_t * const p_instance_ctrl, i2c_master_event_t const event);
static void sci_i2c_abort_seq_master(sci_i2c_instance_ctrl_t * const p_instance_ctrl);

static fsp_err_t sci_i2c_read_write(i2c_master_ctrl_t * const p_ctrl,
                                    uint8_t * const           p_buffer,
                                    uint32_t const            bytes,
                                    sci_i2c_transfer_dir_t    direction);

/* Functions that manipulate hardware */
static void sci_i2c_open_hw_master(sci_i2c_instance_ctrl_t * const p_instance_ctrl,
                                   i2c_master_cfg_t const * const  p_cfg);
static void sci_i2c_run_hw_master(sci_i2c_instance_ctrl_t * const p_instance_ctrl);

void sci_i2c_txi_isr(void);
void sci_i2c_tei_isr(void);

static void sci_i2c_txi_send_data(sci_i2c_instance_ctrl_t * const p_instance_ctrl);
static void sci_i2c_tei_send_address(sci_i2c_instance_ctrl_t * const p_instance_ctrl);

static void sci_i2c_tei_handler(sci_i2c_instance_ctrl_t * const p_instance_ctrl);
static void sci_i2c_txi_handler(sci_i2c_instance_ctrl_t * const p_instance_ctrl);
static void sci_i2c_txi_process_nack(sci_i2c_instance_ctrl_t * const p_instance_ctrl);
static void sci_i2c_issue_restart_or_stop(sci_i2c_instance_ctrl_t * const p_instance_ctrl);

#if SCI_I2C_CFG_DMAC_ENABLE
void             sci_i2c_rxi_isr(void);
static fsp_err_t sci_i2c_transfer_open(sci_i2c_instance_ctrl_t * p_instance_ctrl, i2c_master_cfg_t const * const p_cfg);
static fsp_err_t sci_i2c_transfer_configure(sci_i2c_instance_ctrl_t        * p_instance_ctrl,
                                            transfer_instance_t const      * p_transfer,
                                            sci_i2c_dmac_interrupt_trigger_t trigger);
static void sci_i2c_reconfigure_interrupts_for_transfer(sci_i2c_instance_ctrl_t * const p_instance_ctrl);
static void sci_i2c_enable_transfer_support_tx(sci_i2c_instance_ctrl_t * const p_instance_ctrl);

#endif

void sci_i2c_tx_dmac_callback(sci_i2c_instance_ctrl_t * p_instance_ctrl);
void sci_i2c_rx_dmac_callback(sci_i2c_instance_ctrl_t * p_instance_ctrl);

/**********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/* constant used as the source location for the DMAC dummy write  */
static const uint8_t g_dummy_write_data_for_read_op = SCI_I2C_PRV_DUMMY_WRITE_DATA_FOR_READ_OP;

/**********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/* Simple I2C on SCI HAL API mapping for I2C Master interface */
i2c_master_api_t const g_i2c_master_on_sci =
{
    .open            = R_SCI_I2C_Open,
    .read            = R_SCI_I2C_Read,
    .write           = R_SCI_I2C_Write,
    .abort           = R_SCI_I2C_Abort,
    .slaveAddressSet = R_SCI_I2C_SlaveAddressSet,
    .close           = R_SCI_I2C_Close,
    .callbackSet     = R_SCI_I2C_CallbackSet,
    .statusGet       = R_SCI_I2C_StatusGet
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZT
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_SCI_I2C
 * @{
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/******************************************************************************************************************//**
 * Opens the I2C device.
 *
 * @retval  FSP_SUCCESS                       Device opened without issue.
 * @retval  FSP_ERR_ALREADY_OPEN              Module is already open.
 * @retval  FSP_ERR_IP_CHANNEL_NOT_PRESENT    Channel is not available on this MPU.
 * @retval  FSP_ERR_ASSERTION                 Parameter check failure due to one or more reasons below:
 *                                            1. p_ctrl or p_cfg is NULL.
 *                                            2. extended parameter is NULL.
 *                                            3. Clock rate requested is greater than 400KHz.
 *                                            4. Invalid IRQ number assigned.
 *                                            5. Invalid clock setting assigned.
 *                                            6. If p_transfer_rx is not NULL, p_transfer_tx is NULL.
 * @retval  FSP_ERR_INVALID_ARGUMENT          Invalid input parameter.
 **********************************************************************************************************************/
fsp_err_t R_SCI_I2C_Open (i2c_master_ctrl_t * const p_ctrl, i2c_master_cfg_t const * const p_cfg)
{
    sci_i2c_instance_ctrl_t * p_instance_ctrl = (sci_i2c_instance_ctrl_t *) p_ctrl;
#if SCI_I2C_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl != NULL);
    FSP_ASSERT(p_cfg != NULL);
    FSP_ASSERT(p_cfg->p_extend != NULL);
    FSP_ASSERT((p_cfg->rate == I2C_MASTER_RATE_STANDARD) || (p_cfg->rate == I2C_MASTER_RATE_FAST));
    FSP_ASSERT(p_cfg->txi_irq >= (IRQn_Type) 0);
    FSP_ASSERT(p_cfg->tei_irq >= (IRQn_Type) 0);
    FSP_ERROR_RETURN(SCI_I2C_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
    FSP_ERROR_RETURN((p_cfg->channel < 8 * sizeof(unsigned int)) &&
                     (BSP_FEATURE_SCI_CHANNELS & (1U << p_cfg->channel)),
                     FSP_ERR_IP_CHANNEL_NOT_PRESENT);
#endif

    sci_i2c_extended_cfg_t * pextend = (sci_i2c_extended_cfg_t *) p_cfg->p_extend;

#if SCI_I2C_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(pextend->p_reg != NULL);

    if (true == pextend->clock_settings.bitrate_modulation)
    {
        FSP_ASSERT(pextend->clock_settings.mddr_value >= SCI_I2C_PRV_MDDR_REG_MIN);
    }

 #if SCI_I2C_CFG_DMAC_ENABLE
    if (NULL != p_cfg->p_transfer_rx)
    {
        FSP_ASSERT(p_cfg->rxi_irq >= (IRQn_Type) 0);
        FSP_ASSERT(p_cfg->p_transfer_tx != NULL);
    }

    if (NULL != p_cfg->p_transfer_tx)
    {
        /* DMAC activation is not available for safety channel. */
        FSP_ERROR_RETURN(BSP_FEATURE_SCI_SAFETY_CHANNEL != p_cfg->channel, FSP_ERR_INVALID_ARGUMENT);
    }
 #endif
#endif
#if SCI_I2C_CFG_DMAC_ENABLE
    fsp_err_t err = FSP_SUCCESS;
#endif

    p_instance_ctrl->p_reg = (R_SCI0_Type *) pextend->p_reg;

    /* Record the configuration on the device for use later */
    p_instance_ctrl->p_cfg             = p_cfg;
    p_instance_ctrl->slave             = p_cfg->slave;
    p_instance_ctrl->addr_mode         = p_cfg->addr_mode;
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

#if SCI_I2C_CFG_DMAC_ENABLE

    /* Open transfer interfaces if available
     * In case of Read operations both p_transfer_tx and p_transfer_rx are used.
     * p_transfer_tx writes 0xFF to the TDR and p_transfer_rx reads from the RDR.
     * If p_transfer_tx is set to NULL, 0xFF would be written to TDR using the CPU
     * and the p_transfer_rx will be used to read the RDR.
     * Such a configuration will make the read operation CPU dependent and there would be
     * no benefit to use DMAC on p_transfer_rx only.
     *
     * In case of Write operation p_transfer_tx is used to write to the TDR.
     */
    err = sci_i2c_transfer_open(p_instance_ctrl, p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_START(FSP_IP_SCI, p_cfg->channel);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    /* Open the hardware in master mode */
    sci_i2c_open_hw_master(p_instance_ctrl, p_cfg);

    p_instance_ctrl->p_buff    = NULL;
    p_instance_ctrl->total     = 0U;
    p_instance_ctrl->remain    = 0U;
    p_instance_ctrl->loaded    = 0U;
    p_instance_ctrl->read      = false;
    p_instance_ctrl->restart   = false;
    p_instance_ctrl->err       = false;
    p_instance_ctrl->restarted = false;
    p_instance_ctrl->open      = SCI_I2C_OPEN;

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Performs a read from the I2C device.
 * The caller will be notified when the operation has completed (successfully) by an
 * I2C_MASTER_EVENT_RX_COMPLETE in the callback.
 *
 * @retval  FSP_SUCCESS                 Function executed without issue.
 * @retval  FSP_ERR_ASSERTION           The parameter p_ctrl, p_dest, p_callback is NULL, bytes is 0.
 * @retval  FSP_ERR_NOT_OPEN            Device was not even opened.
 **********************************************************************************************************************/
fsp_err_t R_SCI_I2C_Read (i2c_master_ctrl_t * const p_ctrl,
                          uint8_t * const           p_dest,
                          uint32_t const            bytes,
                          bool const                restart)
{
#if SCI_I2C_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl != NULL);
    FSP_ASSERT(bytes != 0U);
#endif
    fsp_err_t err = FSP_SUCCESS;

    /* Record the restart information about this transfer.
     * This is done here to keep the parameter (argument) list of sci_i2c_read_write to 4. */
    ((sci_i2c_instance_ctrl_t *) p_ctrl)->restart = restart;

    /* Call the common helper function to perform I2C Read operation.*/
    err = sci_i2c_read_write(p_ctrl, p_dest, bytes, SCI_I2C_TRANSFER_DIR_READ);

    return err;
}

/******************************************************************************************************************//**
 * Performs a write to the I2C device.
 *
 *  This function will fail if there is already an in-progress I2C transfer on the associated channel. Otherwise, the
 *  I2C write operation will begin. When no callback is provided by the user, this function performs a blocking write.
 *  Otherwise, the write operation is non-blocking and the caller will be notified when the operation has finished by
 *  an I2C_MASTER_EVENT_TX_COMPLETE in the callback.
 *
 * @retval  FSP_SUCCESS                 Function executed without issue.
 * @retval  FSP_ERR_ASSERTION           p_ctrl, p_src, p_callback is NULL.
 * @retval  FSP_ERR_NOT_OPEN            Device was not even opened.
 **********************************************************************************************************************/
fsp_err_t R_SCI_I2C_Write (i2c_master_ctrl_t * const p_ctrl,
                           uint8_t * const           p_src,
                           uint32_t const            bytes,
                           bool const                restart)
{
#if SCI_I2C_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl != NULL);
#endif
    fsp_err_t err = FSP_SUCCESS;

    /* Record the restart information about this transfer.
     * This is done here to keep the parameter (argument) list of sci_i2c_read_write to 4. */
    ((sci_i2c_instance_ctrl_t *) p_ctrl)->restart = restart;

    /* Call the common helper function to perform I2C Write operation.*/
    err = sci_i2c_read_write(p_ctrl, p_src, bytes, SCI_I2C_TRANSFER_DIR_WRITE);

    return err;
}

/******************************************************************************************************************//**
 * Aborts any in-progress transfer and forces the I2C peripheral into a ready state.
 *
 *  This function will safely terminate any in-progress I2C transfer with the device. If a transfer is aborted, the user
 *  will be notified via callback with an abort event. Since the callback is optional, this function will also return
 *  a specific error code in this situation.
 *
 * @retval  FSP_SUCCESS                 Transaction was aborted without issue.
 * @retval  FSP_ERR_ASSERTION           p_ctrl is NULL.
 * @retval  FSP_ERR_NOT_OPEN            Device was not even opened.
 **********************************************************************************************************************/
fsp_err_t R_SCI_I2C_Abort (i2c_master_ctrl_t * const p_ctrl)
{
    sci_i2c_instance_ctrl_t * p_instance_ctrl = (sci_i2c_instance_ctrl_t *) p_ctrl;
#if SCI_I2C_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl != NULL);
    FSP_ERROR_RETURN(SCI_I2C_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Abort any transfer happening on the channel */
    sci_i2c_abort_seq_master(p_instance_ctrl);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Sets address and addressing mode of the slave device.
 *
 * This function is used to set the device address and addressing mode of the slave without reconfiguring the entire bus.
 *
 * @retval  FSP_SUCCESS                 Address of the slave is set correctly.
 * @retval  FSP_ERR_ASSERTION           p_ctrl is NULL.
 * @retval  FSP_ERR_NOT_OPEN            Device was not even opened.
 * @retval  FSP_ERR_IN_USE              An I2C Transaction is in progress.
 *
 **********************************************************************************************************************/
fsp_err_t R_SCI_I2C_SlaveAddressSet (i2c_master_ctrl_t * const    p_ctrl,
                                     uint32_t const               slave,
                                     i2c_master_addr_mode_t const addr_mode)
{
    sci_i2c_instance_ctrl_t * p_instance_ctrl = (sci_i2c_instance_ctrl_t *) p_ctrl;

    fsp_err_t err = FSP_SUCCESS;

#if SCI_I2C_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl != NULL);
    FSP_ERROR_RETURN(SCI_I2C_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    /* Fail if there is already a transfer in progress */
    FSP_ERROR_RETURN(((0 == p_instance_ctrl->remain) && (false == p_instance_ctrl->restarted)), FSP_ERR_IN_USE);
#endif

    /* Sets the address of the slave device */
    p_instance_ctrl->slave = slave;

    /* Sets the mode of addressing */
    p_instance_ctrl->addr_mode = addr_mode;

    return err;
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements i2c_master_api_t::callbackSet
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_SCI_I2C_CallbackSet (i2c_master_ctrl_t * const          p_ctrl,
                                 void (                           * p_callback)(i2c_master_callback_args_t *),
                                 void * const                       p_context,
                                 i2c_master_callback_args_t * const p_callback_memory)
{
    sci_i2c_instance_ctrl_t * p_instance_ctrl = (sci_i2c_instance_ctrl_t *) p_ctrl;

#if (SCI_I2C_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(SCI_I2C_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */
    p_instance_ctrl->p_callback        = p_callback;
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Provides driver status.
 *
 * @retval     FSP_SUCCESS                   Status stored in p_status.
 * @retval     FSP_ERR_ASSERTION             NULL pointer.
 **********************************************************************************************************************/
fsp_err_t R_SCI_I2C_StatusGet (i2c_master_ctrl_t * const p_ctrl, i2c_master_status_t * p_status)
{
    sci_i2c_instance_ctrl_t * p_instance_ctrl = (sci_i2c_instance_ctrl_t *) p_ctrl;

#if SCI_I2C_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl != NULL);
    FSP_ASSERT(p_status != NULL);
#endif

    p_status->open = (SCI_I2C_OPEN == p_instance_ctrl->open);

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Closes the I2C device. Power down I2C peripheral.
 *
 *  This function will safely terminate any in-progress I2C transfer with the device. If a transfer is aborted, the user
 *  will be notified via callback with an abort event. Since the callback is optional, this function will also return
 *  a specific error code in this situation.
 *
 * @retval  FSP_SUCCESS                 Device closed without issue.
 * @retval  FSP_ERR_ASSERTION           The parameter p_ctrl is NULL.
 * @retval  FSP_ERR_NOT_OPEN            Device was not even opened.
 **********************************************************************************************************************/
fsp_err_t R_SCI_I2C_Close (i2c_master_ctrl_t * const p_ctrl)
{
    sci_i2c_instance_ctrl_t * p_instance_ctrl = (sci_i2c_instance_ctrl_t *) p_ctrl;

#if SCI_I2C_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl != NULL);
    FSP_ERROR_RETURN(SCI_I2C_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Abort an in-progress transfer with this device only */
    sci_i2c_abort_seq_master(p_instance_ctrl);

    /* The device is now considered closed */
    p_instance_ctrl->open = 0U;

#if SCI_I2C_CFG_DMAC_ENABLE
    if (NULL != p_instance_ctrl->p_cfg->p_transfer_rx)
    {
        p_instance_ctrl->p_cfg->p_transfer_rx->p_api->close(p_instance_ctrl->p_cfg->p_transfer_rx->p_ctrl);
    }

    if (NULL != p_instance_ctrl->p_cfg->p_transfer_tx)
    {
        p_instance_ctrl->p_cfg->p_transfer_tx->p_api->close(p_instance_ctrl->p_cfg->p_transfer_tx->p_ctrl);
    }
#endif

#if SCI_I2C_CFG_DMAC_ENABLE
    if (p_instance_ctrl->p_cfg->rxi_irq >= 0)
    {
        R_BSP_IrqDisable(p_instance_ctrl->p_cfg->rxi_irq);
    }
#endif
    R_BSP_IrqDisable(p_instance_ctrl->p_cfg->tei_irq);
    R_BSP_IrqDisable(p_instance_ctrl->p_cfg->txi_irq);

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_STOP(FSP_IP_SCI, p_instance_ctrl->p_cfg->channel);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * @} (end addtogroup SCI_I2C)
 **********************************************************************************************************************/
#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/**********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Helper function for handling I2C Read or Write.
 *
 * @param      p_ctrl          Pointer to control block
 * @param      p_buffer        Pointer to the buffer to store read/write data.
 * @param[in]  bytes           Number of bytes to be read/written.
 * @param[in]  direction       Read or Write
 *
 * @retval  FSP_SUCCESS           Function executed successfully.
 * @retval  FSP_ERR_ASSERTION     p_buffer or p_callback is NULL.
 * @retval  FSP_ERR_NOT_OPEN      Handle is not initialized. Call R_SCI_I2C_Open to initialize the control block.
 **********************************************************************************************************************/
static fsp_err_t sci_i2c_read_write (i2c_master_ctrl_t * const p_ctrl,
                                     uint8_t * const           p_buffer,
                                     uint32_t const            bytes,
                                     sci_i2c_transfer_dir_t    direction)
{
    sci_i2c_instance_ctrl_t * p_instance_ctrl = (sci_i2c_instance_ctrl_t *) p_ctrl;

#if SCI_I2C_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_buffer != NULL);
    FSP_ERROR_RETURN((p_instance_ctrl->open == SCI_I2C_OPEN), FSP_ERR_NOT_OPEN);
    FSP_ASSERT(((sci_i2c_instance_ctrl_t *) p_ctrl)->p_callback != NULL);
#endif

    p_instance_ctrl->p_buff = p_buffer;
    p_instance_ctrl->total  = bytes;

    /* Handle the (different) addressing mode(s) */
    if (p_instance_ctrl->addr_mode == I2C_MASTER_ADDR_MODE_7BIT)
    {
        /* Set the address bytes according to a 7-bit slave read command */
        p_instance_ctrl->addr_high  = 0U;
        p_instance_ctrl->addr_low   = (uint8_t) ((p_instance_ctrl->slave << 1U) | (uint8_t) direction);
        p_instance_ctrl->addr_total = 1U;
    }

#if SCI_I2C_CFG_ADDR_MODE_10_BIT_ENABLE
    else
    {
        /* Set the address bytes according to a 10-bit slave read command */
        p_instance_ctrl->addr_high =
            (uint8_t) (((p_instance_ctrl->slave >> 7U) | SCI_I2C_PRV_CODE_10BIT) & (uint8_t) ~(SCI_I2C_PRV_CODE_READ));
        p_instance_ctrl->addr_low = (uint8_t) p_instance_ctrl->slave;

        /* Addr total = 3 for Read and 2 for Write (See "Communication Data Format" in the IIC section of the relevant hardware manual). */
        p_instance_ctrl->addr_total = (uint8_t) ((uint8_t) direction + SCI_I2C_PRV_SLAVE_10_BIT_ADDR_LEN_ADJUST);
    }
#endif

    p_instance_ctrl->read = (bool) direction;

    /* Kickoff the read operation as a master */
    sci_i2c_run_hw_master(p_instance_ctrl);

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Single point for managing the logic around notifying a transfer has finished.
 *
 * @param[in]       p_instance_ctrl      Pointer to transfer that is ending.
 * @param[in]       event                The event code to pass to the callback.
 **********************************************************************************************************************/
void sci_i2c_notify (sci_i2c_instance_ctrl_t * const p_instance_ctrl, i2c_master_event_t const event)
{
    i2c_master_callback_args_t args;

    /* Store callback arguments in memory provided by user if available. */
    i2c_master_callback_args_t * p_args = p_instance_ctrl->p_callback_memory;
    if (NULL == p_args)
    {
        /* Store on stack */
        p_args = &args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt. */
        args = *p_args;
    }

    p_args->p_context = p_instance_ctrl->p_context;
    p_args->event     = event;

#if SCI_I2C_CFG_DMAC_ENABLE

    /* Stop any DMAC assisted transfer for tx */
    const transfer_instance_t * p_transfer_tx = p_instance_ctrl->p_cfg->p_transfer_tx;
    if ((NULL != p_transfer_tx) && (!p_instance_ctrl->read))
    {
        p_transfer_tx->p_api->disable(p_transfer_tx->p_ctrl);
    }

    /* Stop any DMAC assisted transfer for rx */
    const transfer_instance_t * p_transfer_rx = p_instance_ctrl->p_cfg->p_transfer_rx;
    if ((NULL != p_transfer_rx) && (p_instance_ctrl->read))
    {
        p_transfer_rx->p_api->disable(p_transfer_rx->p_ctrl);
    }
#endif

    /* Now do the callback here */
    p_instance_ctrl->p_callback(p_args);

    if (NULL != p_instance_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_instance_ctrl->p_callback_memory = args;
    }
}

/******************************************************************************************************************//**
 * Single point for managing the logic around aborting a transfer when operating as a master.
 *
 * @param[in]       p_instance_ctrl  Pointer to control struct of specific device
 **********************************************************************************************************************/
static void sci_i2c_abort_seq_master (sci_i2c_instance_ctrl_t * const p_instance_ctrl)
{
    /* Safely stop the hardware from operating
     * - Disable Serial Reception and Transmission.
     * - Disable channel interrupts.
     */
    p_instance_ctrl->p_reg->CCR0 = 0;
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.RE, 0);
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.TE, 0);

    /* Set SDA and SCL to high impedance state. */
    p_instance_ctrl->p_reg->ICR |= R_SCI0_ICR_IICSCLS_Msk | R_SCI0_ICR_IICSDAS_Msk;

    /* Update the transfer descriptor to show no longer in-progress and an error */
    p_instance_ctrl->remain    = 0U;
    p_instance_ctrl->restarted = false;
    p_instance_ctrl->restart   = false;

    /* Update the transfer descriptor to make sure interrupts no longer process */
    p_instance_ctrl->addr_loaded = p_instance_ctrl->addr_total;
    p_instance_ctrl->loaded      = p_instance_ctrl->total;
}

/******************************************************************************************************************//**
 * Performs the hardware initialization sequence when operating as a master.
 *
 * @param[in]       p_instance_ctrl  Pointer to control structure
 * @param[in]       p_cfg            Pointer to configuration structure
 *
 * @retval  FSP_SUCCESS                 Hardware initialized with proper configurations
 * @retval  FSP_ERR_INVALID_RATE        The requested rate cannot be set.
 **********************************************************************************************************************/
static void sci_i2c_open_hw_master (sci_i2c_instance_ctrl_t * const p_instance_ctrl,
                                    i2c_master_cfg_t const * const  p_cfg)
{
    /* SCI Initialization in Simple I2C Mode (See "SCI Initialization (Simple I2C mode)" in the SCI section of the
     * relevant hardware manual). */

    sci_i2c_extended_cfg_t * pextend = (sci_i2c_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* Set TEIE, TIE, RIE, TE, and RE to 0. */
    p_instance_ctrl->p_reg->CCR0 = 0U;
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.RE, 0);
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.TE, 0);

    /* Write settings to ICR:
     * - Drive SDAn and SCLn pin to high-impedance state
     * - IICDL configuration settings.
     * - Configure IIC Interrupt mode to use Rx and Tx interrupts.
     * - Enable synchronization with the clock signal.
     * - Enable NACK transmission and reception of ACK/NACK.
     */
    uint32_t icr = R_SCI0_ICR_IICSCLS_Msk | R_SCI0_ICR_IICSDAS_Msk;
    icr |= (uint32_t) (pextend->clock_settings.cycles_value & R_SCI0_ICR_IICDL_Msk) <<
           R_SCI0_ICR_IICDL_Pos;
    icr |= R_SCI0_ICR_IICINTM_Msk | R_SCI0_ICR_IICCSC_Msk | R_SCI0_ICR_IICACKT_Msk;
    p_instance_ctrl->p_reg->ICR = icr;

    /* Write settings to CCR3:
     * - Set clock source.
     * - Set Character Length to 8-Bit.
     * - Set MSB first.
     * - Set Simple I2C Mode.
     */
    uint32_t ccr3 = 2U << R_SCI0_CCR3_CHR_Pos;
    ccr3 |= (uint32_t) pextend->clock_settings.clock_source << R_SCI0_CCR3_BPEN_Pos;
    ccr3 |= 4U << R_SCI0_CCR3_MOD_Pos;
    p_instance_ctrl->p_reg->CCR3 = ccr3;

    /* Write settings to CCR2:
     * - Write the BRR setting.
     * - Write the MDDR enable setting.
     * - Write the clock divider setting.
     * - Write the MDDR setting.
     */
    uint32_t ccr2 = 4U << R_SCI0_CCR2_BCP_Pos;
    ccr2 |= (uint32_t) pextend->clock_settings.brr_value << R_SCI0_CCR2_BRR_Pos;
    ccr2 |= (uint32_t) pextend->clock_settings.bitrate_modulation << R_SCI0_CCR2_BRME_Pos;
    ccr2 |= (uint32_t) pextend->clock_settings.clk_divisor_value << R_SCI0_CCR2_CKS_Pos;
    ccr2 |= (uint32_t) pextend->clock_settings.mddr_value << R_SCI0_CCR2_MDDR_Pos;
    p_instance_ctrl->p_reg->CCR2 = ccr2;

    /* Write settings to CCR1:
     * - Write the Noise filter setting.
     * - Enable the Noise filter.
     */
    p_instance_ctrl->p_reg->CCR1 = (uint32_t) (pextend->clock_settings.snfr_value << R_SCI0_CCR1_NFCS_Pos) |
                                   R_SCI0_CCR1_NFEN_Msk;

    /* Clear status flags. */
    p_instance_ctrl->p_reg->CFCLR = (R_SCI0_CFCLR_RDRFC_Msk |
                                     R_SCI0_CFCLR_FERC_Msk |
                                     R_SCI0_CFCLR_PERC_Msk |
                                     R_SCI0_CFCLR_MFFC_Msk |
                                     R_SCI0_CFCLR_ORERC_Msk |
                                     R_SCI0_CFCLR_DFERC_Msk |
                                     R_SCI0_CFCLR_DPERC_Msk |
                                     R_SCI0_CFCLR_DCMFC_Msk |
                                     R_SCI0_CFCLR_ERSC_Msk);

    p_instance_ctrl->p_reg->ICFCLR = R_SCI0_ICFCLR_IICSTIFC_Msk;

    /* Enable interrupts (Note that when DMAC is not used, data is read in the Transmit IRQ). */
    R_BSP_IrqCfgEnable(p_cfg->txi_irq, p_cfg->ipl, p_instance_ctrl);
    R_BSP_IrqCfgEnable(p_cfg->tei_irq, p_cfg->ipl, p_instance_ctrl);
#if SCI_I2C_CFG_DMAC_ENABLE
    if (p_cfg->rxi_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_cfg->rxi_irq, p_cfg->ipl, p_instance_ctrl);
    }
#endif

    /* Step #8 of writing to CCR0 is done under helper function sci_i2c_run_hw_master */
}

/******************************************************************************************************************//**
 * Performs the data transfer described by the parameters when operating as a master.
 *
 * @param[in]       p_instance_ctrl  Pointer to Control structure of specific device.
 *
 * @retval   FSP_SUCCESS                     Data transferred when operating as a master.
 * @retval   FSP_ERR_ABORTED                 If there is an in-progress transfer.
 **********************************************************************************************************************/
static void sci_i2c_run_hw_master (sci_i2c_instance_ctrl_t * const p_instance_ctrl)
{
    /* Initialize fields used during transfer */
    p_instance_ctrl->addr_loaded       = 0U;
    p_instance_ctrl->loaded            = 0U;
    p_instance_ctrl->remain            = p_instance_ctrl->total;
    p_instance_ctrl->addr_remain       = p_instance_ctrl->addr_total;
    p_instance_ctrl->err               = false;
    p_instance_ctrl->do_dummy_read     = false;
    p_instance_ctrl->activation_on_txi = false;

    /* In case of read operation the first ACK detected on the bus is from the slave after the address is sent.
     * Since we are reading on every ACK detection on the bus [in this case from this driver],
     * we skip the first read corresponding to the address.
     */
    if (true == p_instance_ctrl->read)
    {
        p_instance_ctrl->do_dummy_read = true;
    }

    /* Enable TE, RE, TXI and TEIE. */
    p_instance_ctrl->p_reg->CCR0 =
        (R_SCI0_CCR0_TE_Msk | R_SCI0_CCR0_RE_Msk | R_SCI0_CCR0_TEIE_Msk | R_SCI0_CCR0_TIE_Msk);
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.RE, 1);
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.TE, 1);

#if SCI_I2C_CFG_DMAC_ENABLE
    sci_i2c_reconfigure_interrupts_for_transfer(p_instance_ctrl);
#endif

    /* Check if this is a new transaction or a continuation */
    if (!p_instance_ctrl->restarted)
    {
        /* Initiate a start condition.
         * - The IICSTARREQ, IICSDAS, IICSCLS bits must be set simultaneously.
         * - IICDL, IICINTM, IICCSC, and IICACKT settings must be preserved.
         */
        p_instance_ctrl->p_reg->ICR =
            SCI_I2C_PRV_GENERATE_REQUEST(p_instance_ctrl->p_reg->ICR, R_SCI0_ICR_IICSTAREQ_Msk);
    }
    else
    {
        /* Clear for next transfer */
        p_instance_ctrl->restarted = false;

#if SCI_I2C_CFG_DMAC_ENABLE

        /* Enable transfer support for tx if this is the last address byte */
        if (1U == p_instance_ctrl->addr_total)
        {
            sci_i2c_enable_transfer_support_tx(p_instance_ctrl);
        }
#endif

        /* Send MSB or LSB based on the addressing mode.
         * - Write 1 byte data to the LSB byte in the data register.
         * - Write the initial value to the remaining bits in TDR.
         */
        uint32_t data_w =
            (1U == p_instance_ctrl->addr_total) ? (p_instance_ctrl->addr_low) : (p_instance_ctrl->addr_high);
        data_w |= SCI_I2C_PRV_DATA_REG_MASK;
        p_instance_ctrl->p_reg->TDR = data_w;

        /* Update the trackers */
        p_instance_ctrl->addr_remain--;
        p_instance_ctrl->addr_loaded++;
    }
}

/******************************************************************************************************************//**
 * ISR for ACK/RXI interrupt
 *
 **********************************************************************************************************************/
#if SCI_I2C_CFG_DMAC_ENABLE
void sci_i2c_rxi_isr (void)
{
    SCI_I2C_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    /* Nothing to be done here. */

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    SCI_I2C_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

#endif

/*******************************************************************************************************************//**
 * Callback that must be called after a RX DMAC transfer completes.
 *
 * @param[in]     p_instance_ctrl     Pointer to SCI_I2C instance control block
 **********************************************************************************************************************/
void sci_i2c_rx_dmac_callback (sci_i2c_instance_ctrl_t * p_instance_ctrl)
{
    SCI_I2C_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Now that the transfer using DMAC is finished, enable the corresponding IRQ. */
    R_BSP_IrqEnable(p_instance_ctrl->p_cfg->rxi_irq);

    /* This interrupt is invoked once DMAC supported Read transfer is completed. Nothing else to be done here. */

    SCI_I2C_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/******************************************************************************************************************//**
 * ISR for NACK/TXI interrupt
 *
 **********************************************************************************************************************/
void sci_i2c_txi_isr (void)
{
    SCI_I2C_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type                 irq             = R_FSP_CurrentIrqGet();
    sci_i2c_instance_ctrl_t * p_instance_ctrl = (sci_i2c_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Call the handler */
    sci_i2c_txi_handler(p_instance_ctrl);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    SCI_I2C_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * Callback that must be called after a TX DMAC transfer completes.
 *
 * @param[in]     p_instance_ctrl     Pointer to SCI_I2C instance control block
 **********************************************************************************************************************/
void sci_i2c_tx_dmac_callback (sci_i2c_instance_ctrl_t * p_instance_ctrl)
{
    SCI_I2C_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Now that the transfer using DMAC is finished, enable the corresponding IRQ. */
    R_BSP_IrqEnable(p_instance_ctrl->p_cfg->txi_irq);

    /* Call the handler */
    sci_i2c_txi_handler(p_instance_ctrl);

    SCI_I2C_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/******************************************************************************************************************//**
 * Handles the STI interrupt
 *
 *********************************************************************************************************************/
void sci_i2c_tei_isr (void)
{
    SCI_I2C_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type                 irq             = R_FSP_CurrentIrqGet();
    sci_i2c_instance_ctrl_t * p_instance_ctrl = (sci_i2c_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Call the handler */
    sci_i2c_tei_handler(p_instance_ctrl);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    SCI_I2C_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/******************************************************************************************************************//**
 * Handles the NACK/TXI interrupt .
 *
 * @param[in]       p_instance_ctrl     pointer to the I2C control block.
 **********************************************************************************************************************/

static void sci_i2c_txi_handler (sci_i2c_instance_ctrl_t * const p_instance_ctrl)
{
    /* Check if ACK is detected  */
    if (0U == (p_instance_ctrl->p_reg->ISR & R_SCI0_ISR_IICACKR_Msk))
    {
        /* 10 bit address, transfer the remaining address or generate RESTART */
        if (p_instance_ctrl->addr_total != p_instance_ctrl->addr_loaded)
        {
            /* Issue a RESTART as this is 10 bit address read and we have already transmitted the LSB */
            if ((p_instance_ctrl->read) && (2U == p_instance_ctrl->addr_loaded))
            {
                /* Initiate a restart condition.
                 * - The IICRSTARREQ, IICSDAS, IICSCLS bits must be set simultaneously.
                 * - IICDL, IICINTM, IICCSC, and IICACKT settings must be preserved.
                 */
                p_instance_ctrl->p_reg->ICR = SCI_I2C_PRV_GENERATE_REQUEST(p_instance_ctrl->p_reg->ICR,
                                                                           R_SCI0_ICR_IICRSTAREQ_Msk);
            }
            /* Transmit the LSB of the address */
            else
            {
#if SCI_I2C_CFG_DMAC_ENABLE
                sci_i2c_enable_transfer_support_tx(p_instance_ctrl);
#endif

                /* Write 1byte p_instance_ctrl->addr_low to TDR register */
                p_instance_ctrl->p_reg->TDR = SCI_I2C_PRV_DATA_REG_MASK | p_instance_ctrl->addr_low;

                /* Update tracker that we have completed an address byte */
                p_instance_ctrl->addr_remain--;
                p_instance_ctrl->addr_loaded++;
            }
        }

#if SCI_I2C_CFG_DMAC_ENABLE

        /* This is the first interrupt after the completion of DMAC operation, ignore it */
        else if (true == p_instance_ctrl->activation_on_txi)
        {
            p_instance_ctrl->activation_on_txi = false;
        }
#endif

        /* Transmit/Receive data */
        else if (0U < p_instance_ctrl->remain)
        {
            sci_i2c_txi_send_data(p_instance_ctrl);
        }
        /* All transfers complete, send the required bus condition */
        else
        {
            sci_i2c_issue_restart_or_stop(p_instance_ctrl);
        }
    }
    /* NACK detected: Either a NACK interrupt or TXI interrupt with NACK flag set */
    else
    {
        sci_i2c_txi_process_nack(p_instance_ctrl);
    }
}

/******************************************************************************************************************//**
 * Handles the START/STOP interrupt.
 *
 * @param[in]       p_instance_ctrl     pointer to the I2C control block.
 **********************************************************************************************************************/
static void sci_i2c_tei_handler (sci_i2c_instance_ctrl_t * const p_instance_ctrl)
{
    /* Clear the interrupt STI flag */
    p_instance_ctrl->p_reg->ICFCLR = R_SCI0_ICFCLR_IICSTIFC_Msk;

    if (p_instance_ctrl->err)
    {
        /* Set SDA and SCL to high impedance state. */
        p_instance_ctrl->p_reg->ICR |= R_SCI0_ICR_IICSCLS_Msk | R_SCI0_ICR_IICSDAS_Msk;

        /* Notify the user of the error */
        sci_i2c_notify(p_instance_ctrl, I2C_MASTER_EVENT_ABORTED);
    }
    /* Address transmission is not complete, this could be the START condition prior to the transmission
     *  of first address byte or RESTART condition in between a 10 bit address read */
    else if (p_instance_ctrl->addr_total != p_instance_ctrl->addr_loaded)
    {
        /* Check to send address */
        sci_i2c_tei_send_address(p_instance_ctrl);
    }
    /*This a STOP or RESTART after completion of the read/write operation */
    else if (0U == p_instance_ctrl->remain)
    {
        i2c_master_event_t event = p_instance_ctrl->read ? I2C_MASTER_EVENT_RX_COMPLETE : I2C_MASTER_EVENT_TX_COMPLETE;

        /* Set the SCL/SDA lines to the required state */
        if (p_instance_ctrl->restarted)
        {
            /* Configure SDA and SCL for serial output. */
            p_instance_ctrl->p_reg->ICR &= ~(uint32_t) (R_SCI0_ICR_IICSDAS_Msk | R_SCI0_ICR_IICSCLS_Msk);
        }
        else
        {
            /* Set SDA and SCL to high impedance state. */
            p_instance_ctrl->p_reg->ICR |= R_SCI0_ICR_IICSCLS_Msk | R_SCI0_ICR_IICSDAS_Msk;

            /* Disable the transmitter and receiver */
            p_instance_ctrl->p_reg->CCR0 &= ~(uint32_t) (R_SCI0_CCR0_TE_Msk | R_SCI0_CCR0_RE_Msk);

            /* Dummy read to ensure that interrupts are disabled. */
            FSP_REGISTER_READ(p_instance_ctrl->p_reg->CCR0);
        }

        /* Notify anyone waiting that the transfer is finished */
        sci_i2c_notify(p_instance_ctrl, event);
    }
    else
    {
        /*Do nothing*/
    }
}

#if SCI_I2C_CFG_DMAC_ENABLE

/*******************************************************************************************************************//**
 * Configures SCI I2C related transfer drivers (if enabled).
 *
 * @param[in]     p_instance_ctrl   Pointer to SCI I2C specific control structure
 * @param[in]     p_cfg             Pointer to SCI I2C specific configuration structure
 *
 * @retval FSP_SUCCESS                 If configures SCI I2C related transfer drivers
 * @retval FSP_ERR_ASSERTION           Transfer configuration for tx/rx not proper.
 **********************************************************************************************************************/
static fsp_err_t sci_i2c_transfer_open (sci_i2c_instance_ctrl_t * const p_instance_ctrl,
                                        i2c_master_cfg_t const * const  p_cfg)
{
    fsp_err_t err = FSP_SUCCESS;

    if (NULL != p_cfg->p_transfer_rx)
    {
        err = sci_i2c_transfer_configure(p_instance_ctrl, p_cfg->p_transfer_rx, SCI_I2C_DMAC_INTERRUPT_TRIGGER_RXI);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }

    if (NULL != p_cfg->p_transfer_tx)
    {
        err = sci_i2c_transfer_configure(p_instance_ctrl, p_cfg->p_transfer_tx, SCI_I2C_DMAC_INTERRUPT_TRIGGER_TXI);
        if (FSP_SUCCESS != err)
        {
            if (NULL != p_cfg->p_transfer_rx)
            {
                err = p_cfg->p_transfer_rx->p_api->close(p_cfg->p_transfer_rx->p_ctrl);
            }

            return err;
        }
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Configures DMAC
 * @param[in]     p_instance_ctrl            Pointer to I2C specific control structure
 * @param[in]     p_transfer                 Pointer to DMAC instance structure
 * @param[in]     trigger                    TXI or RXI to be set as trigger
 *
 * @retval        FSP_SUCCESS                Transfer interface is configured with valid parameters.
 * @retval        FSP_ERR_ASSERTION          Pointer to transfer instance for I2C receive is NULL.
 **********************************************************************************************************************/
static fsp_err_t sci_i2c_transfer_configure (sci_i2c_instance_ctrl_t        * p_instance_ctrl,
                                             transfer_instance_t const      * p_transfer,
                                             sci_i2c_dmac_interrupt_trigger_t trigger)
{
    fsp_err_t err;

    /* Set default transfer info and open receive transfer module, if enabled. */
 #if (SCI_I2C_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(NULL != p_transfer->p_api);
    FSP_ASSERT(NULL != p_transfer->p_ctrl);
    FSP_ASSERT(NULL != p_transfer->p_cfg);
    FSP_ASSERT(NULL != p_transfer->p_cfg->p_info);
 #endif
    transfer_info_t * p_info = p_transfer->p_cfg->p_info;
    if (SCI_I2C_DMAC_INTERRUPT_TRIGGER_RXI == trigger)
    {
        p_info->mode           = TRANSFER_MODE_NORMAL;
        p_info->src_addr_mode  = TRANSFER_ADDR_MODE_FIXED;
        p_info->dest_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED;
        p_info->p_src          = (void *) (&(p_instance_ctrl->p_reg->RDR));
    }
    else
    {
        /* In case of read operation using DMAC, the TXI interrupt will trigger the DMAC to write 0xFF into TDR
         * (See Figure "Example of the procedure for master reception operations in simple I2C mode (when ICR.IICINTM
         * is 1, and transmission interrupts and reception interrupts are in use.)" in the SCI section of the relevant hardware manual). */

        /* In case of Write operation this will be reconfigured */
        p_info->mode           = TRANSFER_MODE_NORMAL;
        p_info->src_addr_mode  = TRANSFER_ADDR_MODE_FIXED;
        p_info->dest_addr_mode = TRANSFER_ADDR_MODE_FIXED;
        p_info->p_dest         = (void *) (&(p_instance_ctrl->p_reg->TDR));
    }

    err = p_transfer->p_api->open(p_transfer->p_ctrl, p_transfer->p_cfg);
    FSP_ERROR_RETURN((FSP_SUCCESS == err), err);

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Reconfigure the address mode for transfer interface
 *
 * @param[in]  p_instance_ctrl     transfer control block
 *
 * @retval FSP_SUCCESS                       Address mode for transfer interface reconfigured.
 **********************************************************************************************************************/
static void sci_i2c_reconfigure_interrupts_for_transfer (sci_i2c_instance_ctrl_t * const p_instance_ctrl)
{
    const transfer_instance_t * p_transfer_tx = p_instance_ctrl->p_cfg->p_transfer_tx;

    if (NULL != p_transfer_tx)
    {
        transfer_info_t * p_info = p_transfer_tx->p_cfg->p_info;

        /* Disable the transmitter and receiver for reconfiguring interrupt source */
        p_instance_ctrl->p_reg->CCR0 = 0;
        FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.RE, 0);
        FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.TE, 0);

        if (p_instance_ctrl->read)
        {
            /* Re-adjust address modes */
            p_info->mode           = TRANSFER_MODE_NORMAL;
            p_info->src_addr_mode  = TRANSFER_ADDR_MODE_FIXED;
            p_info->dest_addr_mode = TRANSFER_ADDR_MODE_FIXED;
            p_info->p_src          = (void *) &g_dummy_write_data_for_read_op;
        }
        else                           /* This is a write operation */
        {
            /* Re-adjust address modes */
            p_info->mode           = TRANSFER_MODE_NORMAL;
            p_info->src_addr_mode  = TRANSFER_ADDR_MODE_INCREMENTED;
            p_info->dest_addr_mode = TRANSFER_ADDR_MODE_FIXED;
        }

        /* Set the interrupt source to RXI/TXI */
        p_instance_ctrl->p_reg->CCR0 =
            (R_SCI0_CCR0_TE_Msk | R_SCI0_CCR0_RE_Msk | R_SCI0_CCR0_TEIE_Msk | R_SCI0_CCR0_TIE_Msk);
        FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.RE, 1);
        FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.TE, 1);
    }
}

/*******************************************************************************************************************//**
 * Enables the dmac transfer interface for the transmit operation
 *
 * @param[in]       p_instance_ctrl  Pointer to transfer control block
 **********************************************************************************************************************/
static void sci_i2c_enable_transfer_support_tx (sci_i2c_instance_ctrl_t * const p_instance_ctrl)
{
    const transfer_instance_t * p_transfer_tx = p_instance_ctrl->p_cfg->p_transfer_tx;

    if ((NULL != p_transfer_tx) && (!p_instance_ctrl->read))
    {
        /* Enable transfer interface to write to TDR
         * Re-configures the source buffer to the user buffer as this is a Write operation.
         */
        p_transfer_tx->p_cfg->p_info->p_src  = (void *) (p_instance_ctrl->p_buff);
        p_transfer_tx->p_cfg->p_info->length = p_instance_ctrl->remain;

        /* Disable the corresponding IRQ when transferring using DMAC. */
        R_BSP_IrqDisable(p_instance_ctrl->p_cfg->txi_irq);

        p_transfer_tx->p_api->reconfigure(p_transfer_tx->p_ctrl, p_transfer_tx->p_cfg->p_info);

        p_instance_ctrl->remain = 0U;
        p_instance_ctrl->loaded = p_instance_ctrl->total;

        p_instance_ctrl->activation_on_txi = true;
    }
}

#endif

/*******************************************************************************************************************//**
 * Check for the receive condition.
 *
 * @param[in]  p_instance_ctrl     Pointer to transfer control block
 **********************************************************************************************************************/
static void sci_i2c_txi_send_data (sci_i2c_instance_ctrl_t * const p_instance_ctrl)
{
    /* As per the hardware manual, a byte should be written to TDR to generate SCL.
     * If we are doing an I2C read, we will write 0xFF to the TDR  */
    uint8_t data = g_dummy_write_data_for_read_op;

    /* This is a write operation, update the data byte from user buffer */
    if (!p_instance_ctrl->read)
    {
        data = p_instance_ctrl->p_buff[p_instance_ctrl->loaded];

        /* Update trackers */
        p_instance_ctrl->remain--;
        p_instance_ctrl->loaded++;
    }
    /* This is a read operation, move data from RDR and do dummy write to TDR. */
    else
    {
        /* Skip updating the buffer on first interrupt as it is the ACK of address */
        if (true == p_instance_ctrl->do_dummy_read)
        {
            p_instance_ctrl->do_dummy_read = false;
#if SCI_I2C_CFG_DMAC_ENABLE

            /* If transfer interface is available, use it.
             * Enable the transfer interfaces if the number of bytes to be read is greater than 2.
             * The last two bytes will be read through interrupt, this is for support NACK before STOP.
             */
            if ((NULL != p_instance_ctrl->p_cfg->p_transfer_tx) && (NULL != p_instance_ctrl->p_cfg->p_transfer_rx) &&
                (p_instance_ctrl->total > 2U))
            {
                /* Enable RXI interrupt */
                p_instance_ctrl->p_reg->CCR0 =
                    (R_SCI0_CCR0_TE_Msk | R_SCI0_CCR0_RE_Msk | R_SCI0_CCR0_TEIE_Msk | R_SCI0_CCR0_TIE_Msk |
                     R_SCI0_CCR0_RIE_Msk);
                FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.RE, 1);
                FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.TE, 1);

                /* Enable transfer interface for reading data from RDR */
                p_instance_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->p_dest = (void *) (p_instance_ctrl->p_buff);
                p_instance_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->length = p_instance_ctrl->total - 2U;

                /* Disable the corresponding IRQ when transferring using DMAC. */
                R_BSP_IrqDisable(p_instance_ctrl->p_cfg->rxi_irq);

                p_instance_ctrl->p_cfg->p_transfer_rx->p_api->reconfigure(p_instance_ctrl->p_cfg->p_transfer_rx->p_ctrl,
                                                                          p_instance_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info);

                /* Enable transfer interface to do dummy write into TDR */
                p_instance_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->length = p_instance_ctrl->total - 2U;

                /* Disable the corresponding IRQ when transferring using DMAC. */
                R_BSP_IrqDisable(p_instance_ctrl->p_cfg->txi_irq);

                p_instance_ctrl->p_cfg->p_transfer_tx->p_api->reconfigure(p_instance_ctrl->p_cfg->p_transfer_tx->p_ctrl,
                                                                          p_instance_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info);

                /* Update the tracker variables */
                p_instance_ctrl->remain = 2U;
                p_instance_ctrl->loaded = p_instance_ctrl->total - 2U;

                /* Mark DMAC activation for TXI */
                p_instance_ctrl->activation_on_txi = true;
            }
#endif

            /* If number of bytes to be received is greater than one, set ACK transmission
             * NACK transmission will be set before the last byte is read.
             */
            if (1U < p_instance_ctrl->remain)
            {
                p_instance_ctrl->p_reg->ICR_b.IICACKT = 0;
            }
        }
        /* Read data into the buffer */
        else
        {
            p_instance_ctrl->p_buff[p_instance_ctrl->loaded] = (uint8_t) (p_instance_ctrl->p_reg->RDR & UINT8_MAX);

            /* Update trackers */
            p_instance_ctrl->remain--;
            p_instance_ctrl->loaded++;
        }

        /* Enable NACK transmission prior to the reception of the last byte */
        if (1U == p_instance_ctrl->remain)
        {
            p_instance_ctrl->p_reg->ICR_b.IICACKT = 1;
        }
    }

    /* Write 1 byte data to data register (see Figure "Example of the procedure for master transmission operations in
     * simple I2C mode (when ICR.IICINTM is 1, and when confirming ACK / NACK by address transmission only.)" and
     * Figure "Example of the procedure for master reception operations in simple I2C mode (when ICR.IICINTM is 1, and
     * transmission interrupts and reception interrupts are in use.)" in the SCI section of the relevant hardware manual).
     * - In case of write operation this will be data from user buffer.
     * - In case of read operation this will be 0xFF as required by HW.
     */
    p_instance_ctrl->p_reg->TDR = SCI_I2C_PRV_DATA_REG_MASK | data;
}

/*******************************************************************************************************************//**
 * Enables transfer support while handling the TEI interrupt
 *
 * @param[in] p_instance_ctrl     Pointer to transfer control block
 **********************************************************************************************************************/
static void sci_i2c_tei_send_address (sci_i2c_instance_ctrl_t * const p_instance_ctrl)
{
    uint8_t data = 0U;

    /* This is the first address byte */
    if (0U == p_instance_ctrl->addr_loaded)
    {
#if SCI_I2C_CFG_DMAC_ENABLE

        /* Enable transfer support for tx if this is the last address byte */
        if (1U == p_instance_ctrl->addr_total)
        {
            sci_i2c_enable_transfer_support_tx(p_instance_ctrl);
        }
#endif

        /* If 7 bit addressing, send LSB else send MSB of address word */
        data = (1U == p_instance_ctrl->addr_total) ? p_instance_ctrl->addr_low : p_instance_ctrl->addr_high;
    }
    /* This is a 10 bit read operation, issue the address as per the protocol */
    else if ((p_instance_ctrl->read) && (p_instance_ctrl->addr_loaded == 2U))
    {
        /* Write address MSB with R/W bit set to read */
        data = p_instance_ctrl->addr_high | (uint8_t) SCI_I2C_PRV_CODE_READ;
    }
    /* Shouldn't have come here, do nothing */
    else
    {
        /* Do Nothing */
    }

    /* Configure SDA and SCL for serial output. */
    p_instance_ctrl->p_reg->ICR &= ~(uint32_t) (R_SCI0_ICR_IICSDAS_Msk | R_SCI0_ICR_IICSCLS_Msk);

    /* Write 1 byte data to data LSB byte in TDR. */
    p_instance_ctrl->p_reg->TDR = SCI_I2C_PRV_DATA_REG_MASK | data;

    /* Update the number of address bytes remain for next pass */
    p_instance_ctrl->addr_remain--;
    p_instance_ctrl->addr_loaded++;
}

/*******************************************************************************************************************//**
 * Process NACK reception within TXI interrupt
 *
 * @param[in] p_instance_ctrl     Pointer to transfer control block
 **********************************************************************************************************************/
static void sci_i2c_txi_process_nack (sci_i2c_instance_ctrl_t * const p_instance_ctrl)
{
    /* If we are doing master write, or address is NACKed during read operation, this is an error condition, set error and send stop  */
    if ((!p_instance_ctrl->read) || (true == p_instance_ctrl->do_dummy_read))
    {
        p_instance_ctrl->remain = 0U;
        p_instance_ctrl->err    = true;

        /* Initiate a stop condition.
         * - The IICSTPREQ, IICSDAS, IICSCLS bits must be set simultaneously.
         * - IICDL, IICINTM, IICCSC, and IICACKT settings must be preserved.
         */
        p_instance_ctrl->p_reg->ICR =
            SCI_I2C_PRV_GENERATE_REQUEST(p_instance_ctrl->p_reg->ICR, R_SCI0_ICR_IICSTPREQ_Msk);
    }
    /* If we are doing master read, this marks the end of transaction, read the last byte from RDR before
     * generating the required bus condition */
    else
    {
        /* Load the RDR into user buffer */
        p_instance_ctrl->p_buff[p_instance_ctrl->loaded] = (uint8_t) (p_instance_ctrl->p_reg->RDR & UINT8_MAX);

        /* Update trackers */
        p_instance_ctrl->remain--;
        p_instance_ctrl->loaded++;

        sci_i2c_issue_restart_or_stop(p_instance_ctrl);
    }
}

/*******************************************************************************************************************//**
 * This helper function issues a Restart or a Stop condition on the channel.
 *
 * @param[in]  p_instance_ctrl         Instance control structure.
 **********************************************************************************************************************/
static void sci_i2c_issue_restart_or_stop (sci_i2c_instance_ctrl_t * const p_instance_ctrl)
{
    /* Initiate a stop or restart condition.
     * - IICDL, IICINTM, IICCSC, and IICACKT settings must be preserved.
     */
    uint32_t icr = p_instance_ctrl->p_reg->ICR;
    icr &= ~(uint32_t) (R_SCI0_ICR_IICSDAS_Msk | R_SCI0_ICR_IICSCLS_Msk);
    icr |= (1U << R_SCI0_ICR_IICSDAS_Pos) | (1U << R_SCI0_ICR_IICSCLS_Pos);

    if (true == p_instance_ctrl->restart)
    {
        /* The IICRSTAREQ, IICSDAS, IICSCLS bits must be set simultaneously. */
        p_instance_ctrl->p_reg->ICR = (R_SCI0_ICR_IICRSTAREQ_Msk | icr);
        p_instance_ctrl->restarted  = true;
    }
    else
    {
        /* The IICSTPREQ, IICSDAS, IICSCLS bits must be set simultaneously. */
        p_instance_ctrl->p_reg->ICR = (R_SCI0_ICR_IICSTPREQ_Msk | icr);
    }
}
