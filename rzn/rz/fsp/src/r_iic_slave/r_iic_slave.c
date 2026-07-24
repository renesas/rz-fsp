/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * Includes
 *********************************************************************************************************************/
#include "r_iic_slave.h"
#if IIC_SLAVE_CFG_DMAC_ENABLE
 #include "r_dmac.h"
#endif

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

/* "I2CS" in ASCII, used to determine if channel is open. */
#define IIC_SLAVE_OPEN                                     (0x49324353ULL)

/* The timeout interrupt enable bit */
#define IIC_TMO_EN_BIT                                     (0x01U)

/* The arbitration loss detection interrupt enable bit */
#define IIC_ALD_EN_BIT                                     (0x02U)

/* The start condition detection interrupt enable bit */
#define IIC_STR_EN_BIT                                     (0x04U)

/* The stop condition detection interrupt enable bit */
#define IIC_STP_EN_BIT                                     (0x08U)

/* The NAK reception interrupt enable bit */
#define IIC_NAK_EN_BIT                                     (0x10U)

/* The receive data full interrupt enable bit */
#define IIC_RXI_EN_BIT                                     (0x20U)

/* The transmit end interrupt enable bit */
#define IIC_TEI_EN_BIT                                     (0x40U)

/* The transmit data empty interrupt enable bit */
#define IIC_TXI_EN_BIT                                     (0x80U)

/* Bit position for Timeout function (TMOF) detection flag in ICSR2 */
#define ICSR2_TMOF_BIT                                     (0x01U)

/* Bit position for Arbitration loss (AL) detection flag in ICSR2 */
#define ICSR2_AL_BIT                                       (0x02U)

/* Bit position for the START condition detection flag in ICSR2 */
#define ICSR2_START_BIT                                    (0x04U)

/* Bit position for STOP condition flag in ICSR2 */
#define ICSR2_STOP_BIT                                     (0x08U)

/* Bit position for No Acknowledgment (NACKF) flag in ICSR2 */
#define ICSR2_NACKF_BIT                                    (0x10U)

/* I2C Bus Control Register 1 Masks */
#define IIC_SLAVE_PRV_SCL_SDA_NOT_DRIVEN                   (0x1FU)
#define IIC_SLAVE_ICCR1_ICE_BIT_MASK                       (0x80)
#define IIC_SLAVE_ICCR1_IICRST_BIT_MASK                    (0x40)

/* I2C Bus Status Enable Register Mask */
#define IIC_SLAVE_ICSER_SLAVE_ADDRESS_ENABLE_REGISTER_0    (0x01U)

/* I2C Bus Function Enable Register Mask */
#define IIC_SLAVE_FUNCTION_ENABLE_INIT_SETTINGS            (0x5DU)

/* I2C Bus Bit Rate Low-Level Register Mask */
#define IIC_SLAVE_BUS_RATE_REG_RESERVED_BITS               (0xE0U)

/* I2C Bus Mode Register 1 Mask */
#define IIC_SLAVE_BUS_MODE_REGISTER_1_MASK                 (0x08U)

/* I2C Bus Mode Register 2 Masks */
#define IIC_SLAVE_BUS_MODE_REGISTER_2_MASK                 (0x06U)
#define IIC_SLAVE_INTERNAL_REF_CLOCK_SELECT_MAX            (0x07U)

/* I2C Bus Status Register 2 Mask */
#define IIC_SLAVE_STATUS_REGISTER_2_ERR_MASK               (0x1FU)

/* Register Wait Time */

/* Worst case ratio of (CPUnCLK/PCLKL) = 16 approximately.
 */
#define IIC_SLAVE_PERIPHERAL_REG_MAX_WAIT                  (0x10U)

#define IIC_SLAVE_HARDWARE_REGISTER_WAIT(reg, required_value, timeout) \
    while ((timeout))                                                  \
    {                                                                  \
        if ((required_value) == (reg))                                 \
        {                                                              \
            break;                                                     \
        }                                                              \
        (timeout)--;                                                   \
    }

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Private function prototypes
 *********************************************************************************************************************/

/* Internal helper functions */
static void iic_slave_notify(iic_slave_instance_ctrl_t * const p_instance_ctrl,
                             i2c_slave_event_t const           slave_event);
static void iic_slave_callback_request(iic_slave_instance_ctrl_t * const p_instance_ctrl,
                                       i2c_slave_event_t                 slave_event);
static void iic_slave_initiate_transaction(iic_slave_instance_ctrl_t * p_instance_ctrl,
                                           i2c_slave_event_t           slave_event);
static fsp_err_t iic_slave_read_write(i2c_slave_ctrl_t * const p_ctrl,
                                      uint8_t * const          p_buffer,
                                      uint32_t const           bytes,
                                      iic_slave_transfer_dir_t direction);
static void r_iic_slave_call_callback(iic_slave_instance_ctrl_t * p_instance_ctrl,
                                      i2c_slave_event_t           event,
                                      uint32_t                    transaction_count);

#if IIC_SLAVE_CFG_DMAC_ENABLE
static fsp_err_t iic_slave_transfer_open(i2c_slave_cfg_t const * const p_cfg);
static fsp_err_t iic_slave_transfer_configure(transfer_instance_t const * p_transfer,
                                              iic_slave_transfer_dir_t    direction);

#endif

/* Functions that manipulate hardware */
static void iic_open_hw_slave(iic_slave_instance_ctrl_t * const p_instance_ctrl);

/* Interrupt handlers */
static void iic_rxi_slave(iic_slave_instance_ctrl_t * p_instance_ctrl);
static void iic_txi_slave(iic_slave_instance_ctrl_t * p_instance_ctrl);
static void iic_tei_slave(iic_slave_instance_ctrl_t * p_instance_ctrl);
static void iic_err_slave(iic_slave_instance_ctrl_t * p_instance_ctrl);

void iic_slave_tx_dmac_callback(iic_slave_instance_ctrl_t * p_instance_ctrl);
void iic_slave_rx_dmac_callback(iic_slave_instance_ctrl_t * p_instance_ctrl);

/**********************************************************************************************************************
 * Private global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Global variables
 *********************************************************************************************************************/

/* IIC Implementation of I2C device slave interface */
i2c_slave_api_t const g_i2c_slave_on_iic =
{
    .open        = R_IIC_SLAVE_Open,
    .read        = R_IIC_SLAVE_Read,
    .write       = R_IIC_SLAVE_Write,
    .close       = R_IIC_SLAVE_Close,
    .callbackSet = R_IIC_SLAVE_CallbackSet
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZN
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZN_IIC_SLAVE
 * @{
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Functions
 *********************************************************************************************************************/

/******************************************************************************************************************//**
 * Opens the I2C slave device.
 *
 * @retval  FSP_SUCCESS                       I2C slave device opened successfully.
 * @retval  FSP_ERR_ALREADY_OPEN              Module is already open.
 * @retval  FSP_ERR_IP_CHANNEL_NOT_PRESENT    Channel is not available on this MPU.
 * @retval  FSP_ERR_INVALID_ARGUMENT          Error interrupt priority is lower than
 *                                            Transmit, Receive and Transmit End interrupt priority.
 *                                            DMAC activation is not available for safety channel.
 * @retval  FSP_ERR_ASSERTION                 Parameter check failure due to one or more reasons below:
 *                                            1. p_ctrl or p_cfg is NULL.
 *                                            2. extended parameter is NULL.
 *                                            3. Callback parameter is NULL.
 *                                            4. Set the rate to fast mode plus on a channel which does not support it.
 *                                            5. Invalid IRQ number assigned
 *                                            6. transfer instance in p_cfg is invalid when DMAC support enabled
 *********************************************************************************************************************/
fsp_err_t R_IIC_SLAVE_Open (i2c_slave_ctrl_t * const p_ctrl, i2c_slave_cfg_t const * const p_cfg)
{
    iic_slave_instance_ctrl_t * p_instance_ctrl = (iic_slave_instance_ctrl_t *) p_ctrl;

#if IIC_SLAVE_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl != NULL);
    FSP_ASSERT(p_cfg != NULL);
    FSP_ASSERT(p_cfg->p_extend != NULL);
    FSP_ASSERT(p_cfg->rxi_irq >= (IRQn_Type) 0);
    FSP_ASSERT(p_cfg->txi_irq >= (IRQn_Type) 0);
    FSP_ASSERT(p_cfg->tei_irq >= (IRQn_Type) 0);
    FSP_ASSERT(p_cfg->eri_irq >= (IRQn_Type) 0);

    FSP_ERROR_RETURN(BSP_FEATURE_IIC_VALID_CHANNEL_MASK & (1 << p_cfg->channel), FSP_ERR_IP_CHANNEL_NOT_PRESENT);

    FSP_ERROR_RETURN(IIC_SLAVE_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
    FSP_ERROR_RETURN(p_cfg->eri_ipl <= p_cfg->ipl, FSP_ERR_INVALID_ARGUMENT);

    /* If rate is configured as Fast mode plus, check whether the channel supports it */
    if (I2C_SLAVE_RATE_FASTPLUS == p_cfg->rate)
    {
        FSP_ASSERT((BSP_FEATURE_IIC_FAST_MODE_PLUS & (1U << p_cfg->channel)));
    }

 #if IIC_SLAVE_CFG_DMAC_ENABLE
    if ((NULL != p_cfg->p_transfer_rx) || (NULL != p_cfg->p_transfer_tx))
    {
        /* DMAC activation is not available for safety channel. */
        FSP_ERROR_RETURN(BSP_FEATURE_IIC_SAFETY_CHANNEL != p_cfg->channel, FSP_ERR_INVALID_ARGUMENT);
    }
 #endif
#endif

#if IIC_SLAVE_CFG_DMAC_ENABLE
    fsp_err_t err = FSP_SUCCESS;
#endif

    iic_slave_extended_cfg_t * p_extend = (iic_slave_extended_cfg_t *) p_cfg->p_extend;

#if IIC_SLAVE_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_extend);
    FSP_ASSERT(p_extend->p_reg);
#endif

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_START(FSP_IP_IIC, p_cfg->channel);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    p_instance_ctrl->p_reg = (R_IIC0_Type *) p_extend->p_reg;

    /* Record the configuration on the device for use later */
    p_instance_ctrl->p_cfg             = p_cfg;
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    /* Indicate that restart and stop condition detection yet to be enabled */
    p_instance_ctrl->start_interrupt_enabled = false;

    /* Open the hardware in slave mode. Performs IIC initialization as described in hardware manual (see Section
     * 'Initial Settings' of the RZ microprocessor manual). */
    iic_open_hw_slave(p_instance_ctrl);

#if IIC_SLAVE_CFG_DMAC_ENABLE

    /* Open the IIC transfer interface if available */
    err = iic_slave_transfer_open(p_cfg);
    if (FSP_SUCCESS != err)
    {
        R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
        R_BSP_MODULE_STOP(FSP_IP_IIC, p_cfg->channel);
        R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

        return err;
    }
#endif

    R_BSP_IrqCfgEnable(p_instance_ctrl->p_cfg->eri_irq, p_instance_ctrl->p_cfg->eri_ipl, p_instance_ctrl);
    R_BSP_IrqCfgEnable(p_instance_ctrl->p_cfg->txi_irq, p_instance_ctrl->p_cfg->ipl, p_instance_ctrl);
    R_BSP_IrqCfgEnable(p_instance_ctrl->p_cfg->tei_irq, p_instance_ctrl->p_cfg->ipl, p_instance_ctrl);
    R_BSP_IrqCfgEnable(p_instance_ctrl->p_cfg->rxi_irq, p_instance_ctrl->p_cfg->ipl, p_instance_ctrl);

    /* Finally, we can consider the device opened */
    p_instance_ctrl->p_buff                = NULL;
    p_instance_ctrl->total                 = 0U;
    p_instance_ctrl->remain                = 0U;
    p_instance_ctrl->loaded                = 0U;
    p_instance_ctrl->transaction_completed = false;
    p_instance_ctrl->open              = IIC_SLAVE_OPEN;
    p_instance_ctrl->direction         = IIC_SLAVE_TRANSFER_DIR_NOT_ESTABLISHED;
    p_instance_ctrl->do_dummy_read     = false;
    p_instance_ctrl->notify_request    = false;
    p_instance_ctrl->transaction_count = 0U;
#if (IIC_SLAVE_CFG_DMAC_ENABLE)
    p_instance_ctrl->activation_on_rxi = false;
    p_instance_ctrl->activation_on_txi = false;
#endif

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Performs a read from the I2C Master device.
 *
 * This function will fail if there is already an in-progress I2C transfer on the associated channel. Otherwise, the
 * I2C slave read operation will begin. The caller will be notified when the operation has finished by an
 * I2C_SLAVE_EVENT_RX_COMPLETE in the callback.
 * In case the master continues to write more data, an I2C_SLAVE_EVENT_RX_MORE_REQUEST will be issued via callback.
 * In case of errors, an I2C_SLAVE_EVENT_ABORTED will be issued via callback.
 *
 * @retval  FSP_SUCCESS             Function executed without issue
 * @retval  FSP_ERR_ASSERTION       p_ctrl, bytes or p_dest is NULL.
 * @retval  FSP_ERR_IN_USE          Another transfer was in progress.
 * @retval  FSP_ERR_NOT_OPEN        Device is not open.
 *********************************************************************************************************************/
fsp_err_t R_IIC_SLAVE_Read (i2c_slave_ctrl_t * const p_ctrl, uint8_t * const p_dest, uint32_t const bytes)
{
    fsp_err_t err = FSP_SUCCESS;

    err = iic_slave_read_write(p_ctrl, p_dest, bytes, IIC_SLAVE_TRANSFER_DIR_MASTER_WRITE_SLAVE_READ);

    return err;
}

/******************************************************************************************************************//**
 * Performs a write to the I2C Master device.
 *
 * This function will fail if there is already an in-progress I2C transfer on the associated channel. Otherwise, the
 * I2C slave write operation will begin. The caller will be notified when the operation has finished by an
 * I2C_SLAVE_EVENT_TX_COMPLETE in the callback.
 * In case the master continues to read more data, an I2C_SLAVE_EVENT_TX_MORE_REQUEST will be issued via callback.
 * In case of errors, an I2C_SLAVE_EVENT_ABORTED will be issued via callback.
 *
 * @retval  FSP_SUCCESS             Function executed without issue.
 * @retval  FSP_ERR_ASSERTION       p_ctrl or p_src is NULL.
 * @retval  FSP_ERR_IN_USE          Another transfer was in progress.
 * @retval  FSP_ERR_NOT_OPEN        Device is not open.
 *********************************************************************************************************************/
fsp_err_t R_IIC_SLAVE_Write (i2c_slave_ctrl_t * const p_ctrl, uint8_t * const p_src, uint32_t const bytes)
{
    fsp_err_t err = FSP_SUCCESS;

    err = iic_slave_read_write(p_ctrl, p_src, bytes, IIC_SLAVE_TRANSFER_DIR_MASTER_READ_SLAVE_WRITE);

    return err;
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements i2c_slave_api_t::callbackSet
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_IIC_SLAVE_CallbackSet (i2c_slave_ctrl_t * const          p_ctrl,
                                   void (                          * p_callback)(i2c_slave_callback_args_t *),
                                   void * const                      p_context,
                                   i2c_slave_callback_args_t * const p_callback_memory)
{
    iic_slave_instance_ctrl_t * p_instance_ctrl = (iic_slave_instance_ctrl_t *) p_ctrl;

#if (IIC_SLAVE_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(IIC_SLAVE_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */
    p_instance_ctrl->p_callback        = p_callback;
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Closes the I2C device.
 *
 * @retval  FSP_SUCCESS         Device closed successfully.
 * @retval  FSP_ERR_NOT_OPEN    Device not opened.
 * @retval  FSP_ERR_ASSERTION   p_ctrl is NULL.
 *********************************************************************************************************************/
fsp_err_t R_IIC_SLAVE_Close (i2c_slave_ctrl_t * const p_ctrl)
{
    iic_slave_instance_ctrl_t * p_instance_ctrl = (iic_slave_instance_ctrl_t *) p_ctrl;

#if IIC_SLAVE_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl != NULL);

    /* Check if the device is even open, return an error if not */
    FSP_ERROR_RETURN(IIC_SLAVE_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Clear all interrupt bits */
    p_instance_ctrl->p_reg->ICIER = 0U;

#if IIC_SLAVE_CFG_DMAC_ENABLE

    /* Close the handles for the transfer interfaces */
    if (NULL != p_instance_ctrl->p_cfg->p_transfer_rx)
    {
        p_instance_ctrl->p_cfg->p_transfer_rx->p_api->close(p_instance_ctrl->p_cfg->p_transfer_rx->p_ctrl);
    }

    if (NULL != p_instance_ctrl->p_cfg->p_transfer_tx)
    {
        p_instance_ctrl->p_cfg->p_transfer_tx->p_api->close(p_instance_ctrl->p_cfg->p_transfer_tx->p_ctrl);
    }
#endif

    /* Disable all interrupts in GIC */
    R_BSP_IrqDisable(p_instance_ctrl->p_cfg->eri_irq);
    R_BSP_IrqDisable(p_instance_ctrl->p_cfg->rxi_irq);
    R_BSP_IrqDisable(p_instance_ctrl->p_cfg->txi_irq);
    R_BSP_IrqDisable(p_instance_ctrl->p_cfg->tei_irq);

    /* module stop */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_STOP(FSP_IP_IIC, p_instance_ctrl->p_cfg->channel);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    /* The device is now considered closed */
    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * @} (end addtogroup IIC_SLAVE)
 *********************************************************************************************************************/
#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/**********************************************************************************************************************
 * Private Functions
 *********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Helper function for handling I2C Slave Read or Write.
 *
 * @param      p_ctrl          Pointer to the control structure.
 * @param      p_buffer        Pointer to the buffer to store read/write data.
 * @param[in]  bytes           Number of bytes to be read/written.
 * @param[in]  direction       Slave Read or Slave Write
 *
 * @retval  FSP_SUCCESS           Function executed successfully.
 * @retval  FSP_ERR_ASSERTION     p_ctrl or p_buffer is NULL.
 * @retval  FSP_ERR_IN_USE        Another transfer was in progress.
 * @retval  FSP_ERR_NOT_OPEN      Handle is not initialized. Call R_IIC_SLAVE_Open to initialize the control block.
 **********************************************************************************************************************/
static fsp_err_t iic_slave_read_write (i2c_slave_ctrl_t * const p_ctrl,
                                       uint8_t * const          p_buffer,
                                       uint32_t const           bytes,
                                       iic_slave_transfer_dir_t direction)
{
    iic_slave_instance_ctrl_t * p_instance_ctrl = (iic_slave_instance_ctrl_t *) p_ctrl;

#if IIC_SLAVE_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl != NULL);
    FSP_ASSERT(p_buffer != NULL);

    /* Check if the device is even open, return an error if not */
    FSP_ERROR_RETURN(IIC_SLAVE_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    /* Fail if there is already a transfer in progress */
    FSP_ERROR_RETURN(IIC_SLAVE_TRANSFER_DIR_NOT_ESTABLISHED == p_instance_ctrl->direction, FSP_ERR_IN_USE);

    FSP_ASSERT(((iic_slave_instance_ctrl_t *) p_ctrl)->p_callback != NULL);
#endif

    /* Record the new information about this transfer */
    p_instance_ctrl->p_buff    = p_buffer;
    p_instance_ctrl->total     = bytes;
    p_instance_ctrl->remain    = bytes;
    p_instance_ctrl->direction = direction;

    /* Initialize fields used during transfer */
    p_instance_ctrl->loaded = 0U;

#if (IIC_SLAVE_CFG_DMAC_ENABLE)

    /* Reset activation for DMAC */
    p_instance_ctrl->activation_on_txi = false;
    p_instance_ctrl->activation_on_rxi = false;
#endif

    /* Indicate that restart and stop condition detection yet to be enabled */
    p_instance_ctrl->start_interrupt_enabled = false;

    /* Set the response as ACK */
    p_instance_ctrl->p_reg->ICMR3_b.ACKWP = 1; /* Write Enable */
    p_instance_ctrl->p_reg->ICMR3_b.ACKBT = 0; /* Write */
    p_instance_ctrl->p_reg->ICMR3_b.ACKWP = 0;

    /* Timeouts are enabled by the driver code at the end of an IIC Slave callback.
     * Do not enable them here to prevent time restricting the application code.
     */

    p_instance_ctrl->transaction_completed = false;

    return FSP_SUCCESS;
}

/******************************************************************************************************************//**
 * Single point for managing the logic around notifying a transfer has finished.
 *
 * @param[in]       p_instance_ctrl   Pointer to the control structure.
 * @param[in]       slave_event       The slave event code to pass to the callback.
 *********************************************************************************************************************/
static void iic_slave_notify (iic_slave_instance_ctrl_t * const p_instance_ctrl, i2c_slave_event_t const slave_event)
{
    /* Clear all interrupt bits, Only enable TXI and RXI interrupts for the next transaction. */
    p_instance_ctrl->p_reg->ICIER = (uint8_t) ((uint8_t) IIC_RXI_EN_BIT | (uint8_t) IIC_TXI_EN_BIT);

    /* Wait for the value to reflect at the peripheral.
     * See 'Note' under Table "Interrupt sources" of the RZ microprocessor manual */
    uint32_t timeout_count = IIC_SLAVE_PERIPHERAL_REG_MAX_WAIT;
    IIC_SLAVE_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->ICIER,
                                     ((uint8_t) IIC_RXI_EN_BIT | (uint8_t) IIC_TXI_EN_BIT),
                                     timeout_count);

    /* Reset the status flags */
    p_instance_ctrl->notify_request = false;
    p_instance_ctrl->do_dummy_read  = false;

    /* Disable timeout function */
    p_instance_ctrl->p_reg->ICFER_b.TMOE = 0;

#if IIC_SLAVE_CFG_DMAC_ENABLE

    /* Stop any DMAC assisted transfer for tx */
    const transfer_instance_t * p_transfer_tx = p_instance_ctrl->p_cfg->p_transfer_tx;
    if ((NULL != p_transfer_tx) && (IIC_SLAVE_TRANSFER_DIR_MASTER_READ_SLAVE_WRITE == p_instance_ctrl->direction))
    {
        p_transfer_tx->p_api->disable(p_transfer_tx->p_ctrl);
    }

    /* Stop any DMAC assisted transfer for rx */
    const transfer_instance_t * p_transfer_rx = p_instance_ctrl->p_cfg->p_transfer_rx;
    if ((NULL != p_transfer_rx) && (IIC_SLAVE_TRANSFER_DIR_MASTER_WRITE_SLAVE_READ == p_instance_ctrl->direction))
    {
        p_transfer_rx->p_api->disable(p_transfer_rx->p_ctrl);
    }
#endif

    /* Check if the transaction ended with a stop (or restart) */
    if (p_instance_ctrl->transaction_completed)
    {
        /* Clear all status flags */
        p_instance_ctrl->p_reg->ICSR2 = 0x00;

        /* Wait for the value to reflect at the peripheral.
         * See 'Note' under Table "Interrupt sources" of the RZ microprocessor manual. */
        IIC_SLAVE_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->ICSR2, 0x00U, timeout_count);
    }
    /*
     * Since the transaction resulted in an error or is not completed at the master (this is a bus hang situation)
     * the slave must do an internal reset to release the bus.
     * Refer the note in Section 'I2C Bus Control Register 1 (ICCR1)' under
     * 'IICRST bit (IIC-Bus Interface Internal Reset)' description
     * of the RZ microprocessor manual
     */
    else
    {
        /* Internal reset */
        p_instance_ctrl->p_reg->ICCR1 =
            (uint8_t) (IIC_SLAVE_ICCR1_ICE_BIT_MASK | IIC_SLAVE_ICCR1_IICRST_BIT_MASK |
                       IIC_SLAVE_PRV_SCL_SDA_NOT_DRIVEN);

        /* Release IIC from internal reset */
        p_instance_ctrl->p_reg->ICCR1 = (uint8_t) (IIC_SLAVE_ICCR1_ICE_BIT_MASK | IIC_SLAVE_PRV_SCL_SDA_NOT_DRIVEN);
    }

    /* Save transaction count */
    uint32_t transaction_count = p_instance_ctrl->transaction_count;

    /* Reset the transaction count here */
    p_instance_ctrl->transaction_count = 0U;

    p_instance_ctrl->direction = IIC_SLAVE_TRANSFER_DIR_NOT_ESTABLISHED;

    /* Invoke the callback */
    r_iic_slave_call_callback(p_instance_ctrl, slave_event, transaction_count);
}

/*******************************************************************************************************************//**
 * Deliver callback. Timeouts are disabled causing clock to stretch.
 *
 * @param      p_instance_ctrl Pointer to the control structure.
 * @param[in]  slave_event     Slave event to be reported via callback.
 **********************************************************************************************************************/
static void iic_slave_callback_request (iic_slave_instance_ctrl_t * const p_instance_ctrl,
                                        i2c_slave_event_t                 slave_event)
{
    p_instance_ctrl->direction = IIC_SLAVE_TRANSFER_DIR_NOT_ESTABLISHED;

    /* Disable timeout function */
    p_instance_ctrl->p_reg->ICFER_b.TMOE = 0;

    /* Invoke the callback to notify the read request.
     * The application must call MasterWriteSlaveRead API in the callback.*/
    r_iic_slave_call_callback(p_instance_ctrl, slave_event, p_instance_ctrl->transaction_count);

    /* Allow timeouts to be generated on both high and low value of SCL using long count mode */
    p_instance_ctrl->p_reg->ICMR2 = IIC_SLAVE_BUS_MODE_REGISTER_2_MASK;

    /* Enable timeout function */
    p_instance_ctrl->p_reg->ICFER_b.TMOE = 1;
}

/******************************************************************************************************************//**
 * Performs the hardware initialization sequence when operating as a slave (see Section
 * 'Initial Settings' of the RZ microprocessor manual).
 *
 * @param[in]       p_instance_ctrl     Pointer to the control structure.
 *********************************************************************************************************************/
static void iic_open_hw_slave (iic_slave_instance_ctrl_t * const p_instance_ctrl)
{
    uint8_t digital_filter_stages =
        (((iic_slave_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend)->clock_settings.digital_filter_stages);

    /* Perform IIC reset */
    p_instance_ctrl->p_reg->ICCR1 = (uint8_t) IIC_SLAVE_PRV_SCL_SDA_NOT_DRIVEN;

    /* Reset */
    p_instance_ctrl->p_reg->ICCR1 = (uint8_t) (IIC_SLAVE_ICCR1_IICRST_BIT_MASK | IIC_SLAVE_PRV_SCL_SDA_NOT_DRIVEN);

    /* Come out of IIC reset to internal reset */
    p_instance_ctrl->p_reg->ICCR1 =
        (uint8_t) (IIC_SLAVE_ICCR1_ICE_BIT_MASK | IIC_SLAVE_ICCR1_IICRST_BIT_MASK |
                   IIC_SLAVE_PRV_SCL_SDA_NOT_DRIVEN);

    /* Set Slave address in SARLx and SARUx. and Set ICSER */
    /*7 bit mode selected, clear SARU and set SARL */
    if (I2C_SLAVE_ADDR_MODE_7BIT == p_instance_ctrl->p_cfg->addr_mode)
    {
        p_instance_ctrl->p_reg->SAR[0].U = 0U;
        p_instance_ctrl->p_reg->SAR[0].L = (uint8_t) (p_instance_ctrl->p_cfg->slave << 1U);
    }
    /* 10 bit mode selected, set SARU and SARL */
    else
    {
        p_instance_ctrl->p_reg->SAR[0].U = (((p_instance_ctrl->p_cfg->slave >> 7U) | 0x01U) & 0x07U);
        p_instance_ctrl->p_reg->SAR[0].L = (uint8_t) p_instance_ctrl->p_cfg->slave;
    }

    /* Enable the slave address */
    p_instance_ctrl->p_reg->ICSER = (uint8_t) ((uint8_t) IIC_SLAVE_ICSER_SLAVE_ADDRESS_ENABLE_REGISTER_0 |
                                               ((uint8_t) p_instance_ctrl->p_cfg->general_call_enable <<
                                                R_IIC0_ICSER_GCAE_Pos));

    /* Allow timeouts to be generated on both high and low value of SCL using long count mode */
    p_instance_ctrl->p_reg->ICMR2 = IIC_SLAVE_BUS_MODE_REGISTER_2_MASK;

    /* ICFER Register Settings:
     * 1. Enable timeout function.
     * 2. Disable master arbitration loss detection.
     * 3. Enable NACK arbitration loss detection.
     * 4. Enable Slave arbitration loss detection.
     * 5. Enable NACK reception transfer suspension.
     * 6. Do not use the digital noise filter circuit.
     * 7. Use the SCL synchronous circuit.
     * 8. Enable FM+ slope circuit if fast mode plus is enabled.
     * (see Section 'I2C Bus Function Enable Register' of the RZ microprocessor manual for more details)
     */
    p_instance_ctrl->p_reg->ICFER =
        (uint8_t) (((uint8_t) (0 < digital_filter_stages) << 5U) |
                   (uint8_t) IIC_SLAVE_FUNCTION_ENABLE_INIT_SETTINGS);

    /* Set the clock and slope circuits to match the data setup time specified by the I2C standard */
    /* This is set in the configuration structure by the tooling. */

    /* Set the number of counts that the clock remains low, bit 7 to 5 should be written as 1 */
    p_instance_ctrl->p_reg->ICBRL =
        (uint8_t) (IIC_SLAVE_BUS_RATE_REG_RESERVED_BITS |
                   ((iic_slave_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend)->clock_settings.brl_value);

    /* ICBRH need not be updated. */
    /* Set the internal reference clock source for generating IIC clock */
    p_instance_ctrl->p_reg->ICMR1 = (uint8_t) (IIC_SLAVE_BUS_MODE_REGISTER_1_MASK |
                                               (uint8_t) ((((iic_slave_extended_cfg_t *) p_instance_ctrl->p_cfg->
                                                            p_extend)->
                                                           clock_settings.
                                                           cks_value &
                                                           IIC_SLAVE_INTERNAL_REF_CLOCK_SELECT_MAX) << 4U));

    /* 1. Set the digital filter.
     * 2. ACKBT should be set to 0 after reset to send out an ACK upon slave address match.
     * 3. Set WAIT bit based on user config.
     * Refer Section ICMR3 : I2C Bus Mode Register 3 :
     * 'WAIT bit (WAIT)' and 'RDRFS bit (RDRF Flag Set Timing Select)'
     * of the RZ microprocessor manual.
     * Since RDRFS = 0:
     * - SCLn line will *not* be held low at the falling edge of the 8th clock cycle.
     * - RDRF flag will be set at the rising edge of the 9th clock cycle. (Cause of iic_rxi_slave)
     * This means that iic_rxi_slave will be invoked during the 9th clock cycle (High) if there is no preemption.
     * Set the WAIT = 1 so that the SCLn line is held low from the falling edge of the 9th clock cycle.
     * This is done to support clock stretching during the 'iic_slave_initiate_transaction'/user event callback (more often)
     * and if iic_rxi_slave can get preempted.
     *
     * Note 1: If the preemption happens after the Read API is called in the user event callback,
     *         WAIT = 1 will be able to handle that scenario,
     *         however if the preemption happens before, the slave will timeout if the Read API
     *         is not called within 'Long Timeout Mode' duration.
     *
     * Note 2: When WAIT = 1, this driver no longer supports data reception utilizing the double buffer HW setup.
     *
     * Note 3: WAIT bit is dont-care during transmission.
     * */
    p_instance_ctrl->p_reg->ICMR3 =
        (uint8_t) ((uint8_t) (digital_filter_stages > 0U ? (digital_filter_stages - 1U) : 0U) |
                   (uint8_t) (p_instance_ctrl->p_cfg->clock_stretching_enable <<
                              R_IIC0_ICMR3_WAIT_Pos));

    p_instance_ctrl->p_reg->ICIER = (uint8_t) ((uint8_t) IIC_RXI_EN_BIT | (uint8_t) IIC_TXI_EN_BIT);

    /* Release IIC from internal reset */
    p_instance_ctrl->p_reg->ICCR1 = (uint8_t) (IIC_SLAVE_ICCR1_ICE_BIT_MASK | IIC_SLAVE_PRV_SCL_SDA_NOT_DRIVEN);
}

/*******************************************************************************************************************//**
 * Setup the Slave Read/Write transaction by issuing RX Request or TX request to the application via callback.
 *
 * @param      p_instance_ctrl Pointer to the control structure.
 * @param[in]  slave_event     Slave event to be reported via callback.
 **********************************************************************************************************************/
static void iic_slave_initiate_transaction (iic_slave_instance_ctrl_t * p_instance_ctrl, i2c_slave_event_t slave_event)
{
    /* Set the status flag to ensure this conditional clause execution only once */
    p_instance_ctrl->notify_request = true;

    /* Enable the Error ISR for servicing timeout,arbitration loss and a NACK detection conditions. */
    p_instance_ctrl->p_reg->ICIER = (uint8_t) ((uint8_t) IIC_TMO_EN_BIT |
                                               (uint8_t) IIC_ALD_EN_BIT |
                                               (uint8_t) IIC_NAK_EN_BIT |
                                               (uint8_t) IIC_RXI_EN_BIT |
                                               (uint8_t) IIC_TXI_EN_BIT);

    /* Invoke callback for the user to call a valid API. */
    iic_slave_callback_request(p_instance_ctrl, slave_event);

    /* Check if correct API is called here  Check direction (API called) against slave event requested (ISR invoked) */
    if (!(((IIC_SLAVE_TRANSFER_DIR_MASTER_WRITE_SLAVE_READ ==
            p_instance_ctrl->direction) &&
           ((I2C_SLAVE_EVENT_RX_REQUEST == slave_event) || (I2C_SLAVE_EVENT_GENERAL_CALL == slave_event))) ||
          ((IIC_SLAVE_TRANSFER_DIR_MASTER_READ_SLAVE_WRITE ==
            p_instance_ctrl->direction) && (I2C_SLAVE_EVENT_TX_REQUEST == slave_event))))
    {
        /* In case MasterWriteSlaveRead API is NOT called to service Master write operation a NACK is
         * issued from the RXI ISR (which is fired once) and the bus is released.
         *
         * In case MasterWriteSlaveRead API is NOT called to service Master General Call operation a NACK is
         * issued from the RXI ISR (which is fired once) and the bus is released.
         *
         * In case MasterReadSlaveWrite API is NOT called to service Master read operation the TXI will fire once,
         * no data will be written to ICDRT and the master will read oxFF for every byte it tries to read.
         *
         * For both the cases above the slave callback is invoked with I2C_SLAVE_EVENT_ABORTED
         * event to notify the user application.
         *
         */
    }
    else
    {
        /* Enable start interrupt to detect restart condition at the end of the current transaction. */
        if (!p_instance_ctrl->start_interrupt_enabled)
        {
            /* Enable the Start condition detection to trigger ERI ISR */

            /* Since address match is detected, enable STOP and RESTART detection for Master Read Slave Write.
             * This must be done conditionally only for Master Read Slave Write to prevent clearing the start bit
             * in case a restart occurred (and got captured) while we were in the user callback.
             * This capturing is made possible in the 'iic_rxi_slave' after the dummy read.
             */
            if (IIC_SLAVE_TRANSFER_DIR_MASTER_READ_SLAVE_WRITE == p_instance_ctrl->direction)
            {
                /* Clear the Start and Stop condition flag for Slave Read/Write operation */
                p_instance_ctrl->p_reg->ICSR2 &= ((uint8_t) ~((uint8_t) ICSR2_STOP_BIT | (uint8_t) ICSR2_START_BIT));

                /* Wait for the value to reflect at the peripheral.
                 * See 'Note' under Table "Interrupt sources" of the RZ microprocessor manual. */
                uint32_t timeout_count = IIC_SLAVE_PERIPHERAL_REG_MAX_WAIT;
                IIC_SLAVE_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->ICSR2_b.STOP, 0U, timeout_count);
                IIC_SLAVE_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->ICSR2_b.START, 0U, timeout_count);
            }

            /* Enable the Start and Stop condition detection interrupt */
            p_instance_ctrl->p_reg->ICIER = (uint8_t) ((uint8_t) IIC_STP_EN_BIT |
                                                       (uint8_t) IIC_STR_EN_BIT |
                                                       (uint8_t) IIC_TMO_EN_BIT |
                                                       (uint8_t) IIC_ALD_EN_BIT |
                                                       (uint8_t) IIC_NAK_EN_BIT |
                                                       (uint8_t) IIC_RXI_EN_BIT |
                                                       (uint8_t) IIC_TXI_EN_BIT);

            p_instance_ctrl->start_interrupt_enabled = true;
        }
    }
}

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_instance_ctrl        Pointer to iic slave instance control block
 * @param[in]     event                  Event code
 * @param[in]     transaction_count      Transaction count for iic slave
 **********************************************************************************************************************/
static void r_iic_slave_call_callback (iic_slave_instance_ctrl_t * p_instance_ctrl,
                                       i2c_slave_event_t           event,
                                       uint32_t                    transaction_count)
{
    i2c_slave_callback_args_t args;

    /* Store callback arguments in memory provided by user if available. */
    i2c_slave_callback_args_t * p_args = p_instance_ctrl->p_callback_memory;
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

    p_args->bytes     = transaction_count;
    p_args->event     = event;
    p_args->p_context = p_instance_ctrl->p_context;

    p_instance_ctrl->p_callback(p_args);

    if (NULL != p_instance_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_instance_ctrl->p_callback_memory = args;
    }
}

/******************************************************************************************************************//**
 * Handles the receive data full interrupt when operating as a slave.
 *
 * @param[in]       p_instance_ctrl     The target IIC block's control block.
 *********************************************************************************************************************/
static void iic_rxi_slave (iic_slave_instance_ctrl_t * p_instance_ctrl)
{
    /* Perform dummy read after an address match detection. */
    if (!p_instance_ctrl->do_dummy_read)
    {
        p_instance_ctrl->do_dummy_read = true;

        volatile uint8_t address_and_intent = p_instance_ctrl->p_reg->ICDRR;

        /* The below code enables/services 0 byte writes from Master.*/

        /* For 7-bit address: slave addr | R/W + data
         * For 10-bit address:
         * read:  slave high addr | W + slave low addr + data + stop
         * write: slave high addr | W + slave low addr + restart + slave high addr | R + data + stop
         */
        if ((I2C_SLAVE_ADDR_MODE_7BIT == p_instance_ctrl->p_cfg->addr_mode) && (address_and_intent & 1U))
        {
            p_instance_ctrl->p_reg->ICSR2 &= (uint8_t) ~(ICSR2_STOP_BIT);
        }
        else
        {
            p_instance_ctrl->p_reg->ICSR2 &= ((uint8_t) ~((uint8_t) ICSR2_STOP_BIT | (uint8_t) ICSR2_START_BIT));
        }

        /* Wait for the value to reflect at the peripheral.
         * See 'Note' under Table "Interrupt sources" of the RZ microprocessor manual. */
        uint32_t timeout_count = IIC_SLAVE_PERIPHERAL_REG_MAX_WAIT;
        IIC_SLAVE_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->ICSR2_b.STOP, 0U, timeout_count);

        /* Enable the Stop condition detection interrupt.
         * In case this is a greater than 0 byte write from Master and MasterWriteSlaveRead API is called
         * in the callback with valid parameters, this flag will be appropriately updated by helper function -
         * iic_slave_initiate_transaction.
         * Start condition is enabled here for Master Write Slave Read case to trigger an interrupt on detecting
         * a restart on the bus when slave is processing a long user callback.
         * This enablement is harmless for Master Read Slave Write operation as its Start bit is not cleared
         * (set during this address match).
         * */
        p_instance_ctrl->p_reg->ICIER = (uint8_t) ((uint8_t) IIC_RXI_EN_BIT |
                                                   (uint8_t) IIC_TXI_EN_BIT |
                                                   (uint8_t) IIC_STR_EN_BIT |
                                                   (uint8_t) IIC_STP_EN_BIT);
    }
    else
    {
        /* Check if the read request event has been notified through callback, if not provide the callback */
        if (!p_instance_ctrl->notify_request)
        {
            /* Check if this is a General Call by Master */
            i2c_slave_event_t receive_callback_event =
                (R_IIC0_ICSR1_GCA_Msk ==
                 (p_instance_ctrl->p_reg->ICSR1 &
                  R_IIC0_ICSR1_GCA_Msk)) ? I2C_SLAVE_EVENT_GENERAL_CALL : I2C_SLAVE_EVENT_RX_REQUEST;
            iic_slave_initiate_transaction(p_instance_ctrl, receive_callback_event);
        }

#if IIC_SLAVE_CFG_PARAM_CHECKING_ENABLE

        /* Proceed reading data */
        if (IIC_SLAVE_TRANSFER_DIR_MASTER_WRITE_SLAVE_READ != p_instance_ctrl->direction)
        {
            /* If the user application incorrectly handles Master Write, send a NACK to exit the transaction. */
            /* Do not dummy read here to allow slave to timeout */
            p_instance_ctrl->p_reg->ICMR3_b.ACKWP = 1;
            p_instance_ctrl->p_reg->ICMR3_b.ACKBT = 1;
            p_instance_ctrl->p_reg->ICMR3_b.ACKWP = 0;
        }
        else
#endif
        {
            if (0U == p_instance_ctrl->total) /* Send NACK */
            {
                /* Slave is sending a NACK. */
                /* Do dummy read to release SCL */
                FSP_REGISTER_READ(p_instance_ctrl->p_reg->ICDRR);

                /* Set the response as NACK, since slave is not setup for reading any data from master at this time.
                 * This is an intentional way to let master know that the slave receiver cannot
                 * accept any data and hence should eventually result in I2C_SLAVE_EVENT_RX_COMPLETE.
                 */
                p_instance_ctrl->p_reg->ICMR3_b.ACKWP = 1;
                p_instance_ctrl->p_reg->ICMR3_b.ACKBT = 1;
                p_instance_ctrl->p_reg->ICMR3_b.ACKWP = 0;
            }

#if (IIC_SLAVE_CFG_DMAC_ENABLE)

            /* If this is the interrupt that got fired after DMAC transfer,
             * ignore it as the DMAC has already taken care of the data transfer */
            else if (true == p_instance_ctrl->activation_on_rxi)
            {
                p_instance_ctrl->activation_on_rxi = false;
            }
#endif

            /* If master is requesting still more data than configured to be read, notify
             * with a read more event in callback */
            else if (p_instance_ctrl->total == p_instance_ctrl->loaded)
            {
                iic_slave_callback_request(p_instance_ctrl, I2C_SLAVE_EVENT_RX_MORE_REQUEST);

#if IIC_SLAVE_CFG_PARAM_CHECKING_ENABLE
                if (IIC_SLAVE_TRANSFER_DIR_MASTER_WRITE_SLAVE_READ != p_instance_ctrl->direction)
                {
                    /* If the user application incorrectly handles Master Write, send a NACK to exit the transaction. */
                    /* Do not dummy read here to allow slave to timeout */
                    p_instance_ctrl->p_reg->ICMR3_b.ACKWP = 1;
                    p_instance_ctrl->p_reg->ICMR3_b.ACKBT = 1;
                    p_instance_ctrl->p_reg->ICMR3_b.ACKWP = 0;
                }
                else
#endif
                {
                    if (0 == p_instance_ctrl->total) /* Send NACK */
                    {
                        /* Do dummy read to release SCL */
                        FSP_REGISTER_READ(p_instance_ctrl->p_reg->ICDRR);

                        /* Set the response as NACK, since slave is not setup for reading more data from master at this time.
                         * This is an intentional way to let master know that the slave receiver cannot
                         * accept any more data and hence should eventually result in I2C_SLAVE_EVENT_RX_COMPLETE.
                         */
                        p_instance_ctrl->p_reg->ICMR3_b.ACKWP = 1;
                        p_instance_ctrl->p_reg->ICMR3_b.ACKBT = 1;
                        p_instance_ctrl->p_reg->ICMR3_b.ACKWP = 0;
                    }
                    else
                    {
#if (IIC_SLAVE_CFG_DMAC_ENABLE)

                        /* Enable DMAC if possible before reading data */
                        if ((NULL != p_instance_ctrl->p_cfg->p_transfer_rx) &&
                            (false == p_instance_ctrl->activation_on_rxi) &&
                            (p_instance_ctrl->total > 1U))
                        {
                            uint8_t volatile const * p_iic_slave_rx_buffer = &(p_instance_ctrl->p_reg->ICDRR);
                            p_instance_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->p_src =
                                (uint8_t *) (p_iic_slave_rx_buffer);
                            p_instance_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->p_dest =
                                (void *) (p_instance_ctrl->p_buff + 1U);
                            p_instance_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->length = p_instance_ctrl->total - 1U;

                            /* Disable the corresponding IRQ when transferring using DMAC. */
                            R_BSP_IrqDisable(p_instance_ctrl->p_cfg->rxi_irq);

                            p_instance_ctrl->p_cfg->p_transfer_rx->p_api->reconfigure(
                                p_instance_ctrl->p_cfg->p_transfer_rx->p_ctrl,
                                p_instance_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info);
                        }
#endif

                        /* Read data */
                        p_instance_ctrl->p_buff[p_instance_ctrl->loaded++] = p_instance_ctrl->p_reg->ICDRR;

                        /* Keep track of the the actual number of transactions */
                        p_instance_ctrl->transaction_count++;

#if (IIC_SLAVE_CFG_DMAC_ENABLE)
                        if ((NULL != p_instance_ctrl->p_cfg->p_transfer_rx) &&
                            (false == p_instance_ctrl->activation_on_rxi) &&
                            (p_instance_ctrl->total > 1U))
                        {
                            p_instance_ctrl->activation_on_rxi  = true;
                            p_instance_ctrl->transaction_count += p_instance_ctrl->total - 1U;
                            p_instance_ctrl->loaded             = p_instance_ctrl->total;
                        }
#endif
                    }
                }
            }
            else
            {
#if (IIC_SLAVE_CFG_DMAC_ENABLE)

                /* Enable DMAC to operate from 2nd data byte before reading data */
                if ((NULL != p_instance_ctrl->p_cfg->p_transfer_rx) && (p_instance_ctrl->total > 1U) &&
                    (false == p_instance_ctrl->activation_on_rxi))
                {
                    uint8_t volatile const * p_iic_slave_rx_buffer = &(p_instance_ctrl->p_reg->ICDRR);
                    p_instance_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->p_src  = (uint8_t *) (p_iic_slave_rx_buffer);
                    p_instance_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->p_dest =
                        (void *) (p_instance_ctrl->p_buff + 1U);
                    p_instance_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info->length = p_instance_ctrl->total - 1U;

                    /* Disable the corresponding IRQ when transferring using DMAC. */
                    R_BSP_IrqDisable(p_instance_ctrl->p_cfg->rxi_irq);

                    p_instance_ctrl->p_cfg->p_transfer_rx->p_api->reconfigure(
                        p_instance_ctrl->p_cfg->p_transfer_rx->p_ctrl,
                        p_instance_ctrl->p_cfg->p_transfer_rx->p_cfg->p_info);
                }
#endif

                /* Read data */
                p_instance_ctrl->p_buff[p_instance_ctrl->loaded++] = p_instance_ctrl->p_reg->ICDRR;

                /* Keep track of the the actual number of transactions */
                p_instance_ctrl->transaction_count++;

#if (IIC_SLAVE_CFG_DMAC_ENABLE)
                if ((NULL != p_instance_ctrl->p_cfg->p_transfer_rx) && (p_instance_ctrl->total > 1U) &&
                    (false == p_instance_ctrl->activation_on_rxi))
                {
                    p_instance_ctrl->activation_on_rxi  = true;
                    p_instance_ctrl->transaction_count += p_instance_ctrl->total - 1U;
                    p_instance_ctrl->loaded             = p_instance_ctrl->total;
                }
#endif
            }
        }
    }
}

/******************************************************************************************************************//**
 * Handles the transmit data empty interrupt when operating as a slave.
 *
 * @param[in]       p_instance_ctrl     The target IIC block's control block.
 *********************************************************************************************************************/
static void iic_txi_slave (iic_slave_instance_ctrl_t * p_instance_ctrl)
{
    /* Check if the read request event has been notified through callback, if not provide the callback */
    if (!p_instance_ctrl->notify_request)
    {
        iic_slave_initiate_transaction(p_instance_ctrl, I2C_SLAVE_EVENT_TX_REQUEST);
    }

    /* If MasterReadSlaveWrite API is invoked, proceed writing data */
    if (IIC_SLAVE_TRANSFER_DIR_MASTER_READ_SLAVE_WRITE != p_instance_ctrl->direction)
    {
        /* MasterReadSlaveWrite API was not called in the callback.
         * Master will read 0xFF for all the byte(s) for this transaction.
         */
    }
    else
    {
        /* If slave has exhausted the buffer length from application, wait for slave to transmit last byte on the bus
         * and check for master is sending ACK or NACK. If master ACKs this last byte, it is expecting more data
         * from slave. Slave has to notify this event to application via callback */
        if (p_instance_ctrl->total == p_instance_ctrl->loaded)
        {
            /* Clear the pending interrupts for TEI */
            R_BSP_IrqClearPending(p_instance_ctrl->p_cfg->tei_irq);

            /* Enable the TEI interrupt source */
            p_instance_ctrl->p_reg->ICIER_b.TEIE = 1U;
        }
        else
        {
#if (IIC_SLAVE_CFG_DMAC_ENABLE)

            /* Enable DMAC if possible before writing data */
            if ((NULL != p_instance_ctrl->p_cfg->p_transfer_tx) && (p_instance_ctrl->total > 2U) &&
                (false == p_instance_ctrl->activation_on_txi) && (p_instance_ctrl->loaded == 1U))
            {
                uint8_t volatile const * p_iic_slave_tx_buffer = &(p_instance_ctrl->p_reg->ICDRT);
                p_instance_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->p_src  = (void *) (p_instance_ctrl->p_buff + 2U);
                p_instance_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->p_dest = (uint8_t *) (p_iic_slave_tx_buffer);
                p_instance_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info->length = p_instance_ctrl->total - 2U;

                /* Disable the corresponding IRQ when transferring using DMAC. */
                R_BSP_IrqDisable(p_instance_ctrl->p_cfg->txi_irq);

                p_instance_ctrl->p_cfg->p_transfer_tx->p_api->reconfigure(p_instance_ctrl->p_cfg->p_transfer_tx->p_ctrl,
                                                                          p_instance_ctrl->p_cfg->p_transfer_tx->p_cfg->p_info);
            }
#endif

            /* Write the data byte, this will also release SCL */
            p_instance_ctrl->p_reg->ICDRT = p_instance_ctrl->p_buff[p_instance_ctrl->loaded];
            p_instance_ctrl->loaded++;

            /* Keep track of the the actual number of transactions */
            p_instance_ctrl->transaction_count++;

#if (IIC_SLAVE_CFG_DMAC_ENABLE)
            if ((NULL != p_instance_ctrl->p_cfg->p_transfer_tx) && (p_instance_ctrl->total > 2U) &&
                (false == p_instance_ctrl->activation_on_txi) && (p_instance_ctrl->loaded == 2U))
            {
                p_instance_ctrl->transaction_count += p_instance_ctrl->total - 2U;
                p_instance_ctrl->loaded             = p_instance_ctrl->total;
                p_instance_ctrl->activation_on_txi  = true;
            }
#endif
        }
    }
}

/******************************************************************************************************************//**
 * Handles the transmission end interrupt when operating as a slave.
 *
 * @param[in]       p_instance_ctrl     The target IIC block's control block.
 *********************************************************************************************************************/
static void iic_tei_slave (iic_slave_instance_ctrl_t * p_instance_ctrl)
{
    uint32_t timeout_count = IIC_SLAVE_PERIPHERAL_REG_MAX_WAIT;

    /* Check if ACK has been detected from master expecting further data */
    if (0 == p_instance_ctrl->p_reg->ICMR3_b.ACKBR)
    {
        iic_slave_callback_request(p_instance_ctrl, I2C_SLAVE_EVENT_TX_MORE_REQUEST);

        if (IIC_SLAVE_TRANSFER_DIR_MASTER_READ_SLAVE_WRITE != p_instance_ctrl->direction)
        {
            /* MasterReadSlaveWrite API was not called in the callback.
             * Master will read 0xFF for the remaining byte(s) for this transaction.
             */
        }
        else
        {
            p_instance_ctrl->p_reg->ICDRT = p_instance_ctrl->p_buff[p_instance_ctrl->loaded];
            p_instance_ctrl->loaded++;
            p_instance_ctrl->transaction_count++;
        }
    }

    /* Disable the interrupt as we are done with the transfer */
    p_instance_ctrl->p_reg->ICIER_b.TEIE = 0U;

    /* Wait for the value to reflect at the peripheral.
     * See 'Note' under Table "Interrupt sources" of the RZ microprocessor manual */
    IIC_SLAVE_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->ICIER_b.TEIE, 0U, timeout_count);
}

/******************************************************************************************************************//**
 * Handles the error interrupts when operating as a slave.
 *
 * @param[in]       p_instance_ctrl     The target IIC block's control block.
 *********************************************************************************************************************/
static void iic_err_slave (iic_slave_instance_ctrl_t * p_instance_ctrl)
{
    uint8_t error_events = IIC_SLAVE_STATUS_REGISTER_2_ERR_MASK & p_instance_ctrl->p_reg->ICSR2;

    /* Timeout or Arbitration loss detected */
    if ((error_events & ICSR2_TMOF_BIT) || (error_events & ICSR2_AL_BIT))
    {
        /* Clear the stop flag. This indicates an error. */
        p_instance_ctrl->transaction_completed = false;

        iic_slave_notify(p_instance_ctrl, I2C_SLAVE_EVENT_ABORTED);
    }
    /* Stop or restart condition detected, a valid end of transaction */
    else if ((error_events & ICSR2_START_BIT) || (error_events & ICSR2_STOP_BIT))
    {
        i2c_slave_event_t i2c_event = I2C_SLAVE_EVENT_ABORTED;

        /* In case of stop (or restart), set the transaction_completed flag */
        p_instance_ctrl->transaction_completed = true;

        /* Set the I2C event */
        if (IIC_SLAVE_TRANSFER_DIR_MASTER_WRITE_SLAVE_READ == p_instance_ctrl->direction)
        {
            i2c_event = I2C_SLAVE_EVENT_RX_COMPLETE;

            /*
             * This is to fix the issue that after sending NACK, slave application won't be able to get any events until call read API again.
             * It is preferred to clear NACK bit in the driver to allow more granular ACK control from the slave side.
             */
            p_instance_ctrl->p_reg->ICMR3_b.ACKWP = 1; /* Write Enable */
            p_instance_ctrl->p_reg->ICMR3_b.ACKBT = 0; /* Write */
            p_instance_ctrl->p_reg->ICMR3_b.ACKWP = 0;

#if (IIC_SLAVE_CFG_DMAC_ENABLE)
            if ((NULL != p_instance_ctrl->p_cfg->p_transfer_rx) && (true == p_instance_ctrl->activation_on_rxi))
            {
                transfer_properties_t transaction_property;
                p_instance_ctrl->p_cfg->p_transfer_rx->p_api->infoGet(p_instance_ctrl->p_cfg->p_transfer_rx->p_ctrl,
                                                                      &transaction_property);
                p_instance_ctrl->transaction_count -= transaction_property.transfer_length_remaining;

                /* Now that the transfer using DMAC is finished, enable the corresponding IRQ. */
                R_BSP_IrqEnable(p_instance_ctrl->p_cfg->rxi_irq);
            }
#endif
        }
        else
        {
            i2c_event = I2C_SLAVE_EVENT_TX_COMPLETE;

            /* Decrement the transaction count when slave configured to write more data than master requested.
             * Addresses the exception raised from double buffer hardware implementation */
            if (p_instance_ctrl->total > p_instance_ctrl->loaded)
            {
                p_instance_ctrl->transaction_count -= 1U;
            }

#if (IIC_SLAVE_CFG_DMAC_ENABLE)
            if ((NULL != p_instance_ctrl->p_cfg->p_transfer_tx) && (true == p_instance_ctrl->activation_on_txi))
            {
                transfer_properties_t transaction_property;
                p_instance_ctrl->p_cfg->p_transfer_tx->p_api->infoGet(p_instance_ctrl->p_cfg->p_transfer_tx->p_ctrl,
                                                                      &transaction_property);

                /* Decrement the transaction count when slave configured to write more data than master requested.
                 * Addresses the exception raised from double buffer hardware implementation */
                if (transaction_property.transfer_length_remaining > 0)
                {
                    p_instance_ctrl->transaction_count -= 1U;
                    p_instance_ctrl->transaction_count -= transaction_property.transfer_length_remaining;
                }

                /* Now that the transfer using DMAC is finished, enable the corresponding IRQ. */
                R_BSP_IrqEnable(p_instance_ctrl->p_cfg->txi_irq);
            }
#endif
        }

        /* Notify the user */
        iic_slave_notify(p_instance_ctrl, i2c_event);
    }
    /* NACK detected */
    else if (error_events & ICSR2_NACKF_BIT)
    {
        /* NACK interrupt will be triggered on MasterReadSlaveWrite operation.
         * Do dummy read to release SCL
         * Refer point number 5 under Section "Slave Transmit Operation" of the RZ microprocessor manual
         */
        FSP_REGISTER_READ(p_instance_ctrl->p_reg->ICDRR);

        /* Disable NACK interrupt, this is required since we will clear NACK flag only on detection of STOP bit or
         * when a timeout occurs. Not clearing the flag will cause error interrupt to get triggered again.
         */
        p_instance_ctrl->p_reg->ICIER &= (uint8_t) ~(uint8_t) IIC_NAK_EN_BIT;

        /* Wait for the value to reflect at the peripheral.
         * See 'Note' under Table "Interrupt sources" of the RZ microprocessor manual */
        uint32_t timeout_count = IIC_SLAVE_PERIPHERAL_REG_MAX_WAIT;
        IIC_SLAVE_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->ICIER_b.NAKIE, 0U, timeout_count);

#if IIC_SLAVE_CFG_DMAC_ENABLE

        /* Stop any DMAC assisted transfer for tx */
        const transfer_instance_t * p_transfer_tx = p_instance_ctrl->p_cfg->p_transfer_tx;
        if (NULL != p_transfer_tx)
        {
            p_transfer_tx->p_api->disable(p_transfer_tx->p_ctrl);

            /* Now that the transfer using DMAC is finished, enable the corresponding IRQ. */
            R_BSP_IrqEnable(p_instance_ctrl->p_cfg->txi_irq);
        }
#endif
    }
    else
    {
        /* No processing, should not come here */
    }
}

#if IIC_SLAVE_CFG_DMAC_ENABLE

/*******************************************************************************************************************//**
 * Enable the transfer driver to configure for IIC.
 *
 * @param[in]   p_cfg     Pointer to IIC specific configuration structure
 *
 * @retval      FSP_SUCCESS                Transfer interface initialized successfully.
 * @retval      FSP_ERR_ASSERTION          Pointer to transfer instance for I2C in p_cfg is invalid.
 **********************************************************************************************************************/
static fsp_err_t iic_slave_transfer_open (i2c_slave_cfg_t const * const p_cfg)
{
    fsp_err_t err = FSP_SUCCESS;

    if (NULL != p_cfg->p_transfer_rx)
    {
        err = iic_slave_transfer_configure(p_cfg->p_transfer_rx, IIC_SLAVE_TRANSFER_DIR_MASTER_WRITE_SLAVE_READ);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }

    if (NULL != p_cfg->p_transfer_tx)
    {
        err = iic_slave_transfer_configure(p_cfg->p_transfer_tx, IIC_SLAVE_TRANSFER_DIR_MASTER_READ_SLAVE_WRITE);
        if (FSP_SUCCESS != err)
        {
            if (NULL != p_cfg->p_transfer_rx)
            {
                p_cfg->p_transfer_rx->p_api->close(p_cfg->p_transfer_rx->p_ctrl);
            }

            return err;
        }
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Configures IIC related transfer drivers (if enabled)
 * @param[in]     p_transfer                     Pointer to transfer specific control structure
 * @param[in]     direction                      IIC transaction direction
 *
 * @retval        FSP_SUCCESS                Transfer interface is configured with valid parameters.
 * @retval        FSP_ERR_ASSERTION          Pointer to transfer instance for I2C in p_cfg is invalid.
 **********************************************************************************************************************/
static fsp_err_t iic_slave_transfer_configure (transfer_instance_t const * p_transfer,
                                               iic_slave_transfer_dir_t    direction)
{
    fsp_err_t err;

    /* Set default transfer info and open receive transfer module, if enabled. */
 #if (IIC_SLAVE_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(NULL != p_transfer->p_api);
    FSP_ASSERT(NULL != p_transfer->p_cfg);
    FSP_ASSERT(NULL != p_transfer->p_cfg->p_info);
 #endif
    transfer_info_t * p_info = p_transfer->p_cfg->p_info;
    if (IIC_SLAVE_TRANSFER_DIR_MASTER_WRITE_SLAVE_READ == direction)
    {
        p_info->mode           = TRANSFER_MODE_NORMAL;
        p_info->src_addr_mode  = TRANSFER_ADDR_MODE_FIXED;
        p_info->dest_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED;
    }
    else
    {
        p_info->mode           = TRANSFER_MODE_NORMAL;
        p_info->src_addr_mode  = TRANSFER_ADDR_MODE_INCREMENTED;
        p_info->dest_addr_mode = TRANSFER_ADDR_MODE_FIXED;
    }

    err = p_transfer->p_api->open(p_transfer->p_ctrl, p_transfer->p_cfg);
    FSP_ERROR_RETURN((FSP_SUCCESS == err), err);

    return FSP_SUCCESS;
}

#endif

/**********************************************************************************************************************
 * Interrupt Vectors
 *********************************************************************************************************************/

/******************************************************************************************************************//**
 * Receive data full interrupt routine.
 *
 * This function implements the IIC Receive buffer full ISR routine.
 *
 *********************************************************************************************************************/
void iic_slave_rxi_isr(void);

void iic_slave_rxi_isr (void)
{
    IIC_SLAVE_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();
    iic_slave_instance_ctrl_t * p_instance_ctrl = (iic_slave_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    iic_rxi_slave(p_instance_ctrl);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    IIC_SLAVE_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * Callback that must be called after a RX DMAC transfer completes.
 *
 * @param[in]     p_instance_ctrl     Pointer to IIC_SLAVE instance control block
 **********************************************************************************************************************/
void iic_slave_rx_dmac_callback (iic_slave_instance_ctrl_t * p_instance_ctrl)
{
    IIC_SLAVE_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Now that the transfer using DMAC is finished, enable the corresponding IRQ. */
    R_BSP_IrqEnable(p_instance_ctrl->p_cfg->rxi_irq);

    iic_rxi_slave(p_instance_ctrl);

    IIC_SLAVE_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/******************************************************************************************************************//**
 * Transmit data empty interrupt routine.
 *
 * This function implements the Transmit buffer empty ISR routine.
 *
 *********************************************************************************************************************/
void iic_slave_txi_isr(void);

void iic_slave_txi_isr (void)
{
    IIC_SLAVE_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();
    iic_slave_instance_ctrl_t * p_instance_ctrl = (iic_slave_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    iic_txi_slave(p_instance_ctrl);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    IIC_SLAVE_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * Callback that must be called after a TX DMAC transfer completes.
 *
 * @param[in]     p_instance_ctrl     Pointer to IIC_SLAVE instance control block
 **********************************************************************************************************************/
void iic_slave_tx_dmac_callback (iic_slave_instance_ctrl_t * p_instance_ctrl)
{
    IIC_SLAVE_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Now that the transfer using DMAC is finished, enable the corresponding IRQ. */
    R_BSP_IrqEnable(p_instance_ctrl->p_cfg->txi_irq);

    iic_txi_slave(p_instance_ctrl);

    IIC_SLAVE_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * Transmit end interrupt routine.
 *
 * This function implements the IIC Transmission End ISR routine.
 *
 ***********************************************************************************************************************/
void iic_slave_tei_isr(void);

void iic_slave_tei_isr (void)
{
    IIC_SLAVE_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();
    iic_slave_instance_ctrl_t * p_instance_ctrl = (iic_slave_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    iic_tei_slave(p_instance_ctrl);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    IIC_SLAVE_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/******************************************************************************************************************//**
 * Error and event interrupt routine.
 *
 * This function implements the IIC Event/Error.
 *
 *********************************************************************************************************************/
void iic_slave_eri_isr(void);

void iic_slave_eri_isr (void)
{
    IIC_SLAVE_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();
    iic_slave_instance_ctrl_t * p_instance_ctrl = (iic_slave_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    iic_err_slave(p_instance_ctrl);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    IIC_SLAVE_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}
