/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_PCI_API_H
#define R_PCI_API_H

/*******************************************************************************************************************//**
 * @ingroup RENESAS_CONNECTIVITY_INTERFACES
 * @defgroup PCI_API PCI Interface
 *
 * @brief Interface for PCI communications.
 *
 * @section PCI_INTERFACE_SUMMARY Summary
 * The PCI interface provides common APIs for PCI HAL drivers. The PCI interface supports the following features:
 * - PCI communication
 * - Issuing various requests supported by PCI
 * - Callback function with returned event code
 *
 * @{
 **********************************************************************************************************************/

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

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** PCI events. */
typedef enum e_pci_event
{
    PCI_EVENT_INTA_INTERRUPT,                ///< INTA interrupt
    PCI_EVENT_INTB_INTERRUPT,                ///< INTB interrupt
    PCI_EVENT_INTC_INTERRUPT,                ///< INTC interrupt
    PCI_EVENT_INTD_INTERRUPT,                ///< INTD interrupt
    PCI_EVENT_MSI_INTERRUPT,                 ///< MSI interrupt
    PCI_EVENT_MESSAGE_RECEIVE,               ///< Message receive
    PCI_EVENT_CORRECTABLE_ERROR,             ///< Correctable error
    PCI_EVENT_UNCORRECTABLE_ERROR_NON_FATAL, ///< Non fatal error
    PCI_EVENT_UNCORRECTABLE_ERROR_FATAL,     ///< Fatal error
    PCI_EVENT_FUNCTION_LEVEL_RESET,          ///< Function level reset
    PCI_EVENT_LINK_EQUALIZATION_REQUEST,     ///< Link equalization request
    PCI_EVENT_LINK_WIDTH_CHANGE,             ///< Link width change
    PCI_EVENT_EVENT,                         ///< Event interrupt
    PCI_EVENT_D3_EVENT,                      ///< Non-D0 state transition request receive
    PCI_EVENT_PME_TURN_OFF_RCV_EVENT,        ///< PME_Turn_Off message receive
    PCI_EVENT_PME_STATUS_CLEAR,              ///< PME_STATUS clear output
    PCI_EVENT_PM_PME_RECEIVE,                ///< PM_PME message receive interrupt
    PCI_EVENT_POWEROFF_L2,                   ///< POWEROFF indication on L2
    PCI_EVENT_DMA_TRANSFER_COMPLETE,         ///< DMA transfer complete
    PCI_EVENT_DMA_TRANSFER_STOP,             ///< DMA transfer stop
    PCI_EVENT_DMA_TRANSFER_ERROR,            ///< DMA transfer error
} pci_event_t;

/** PCI Configuration Write Type 0/1 */
typedef enum e_pci_configuration_write_type
{
    PCI_CONFIGURATION_WRITE_TYPE_0,    ///< Configuration Write Type 0 (CfgWr0)
    PCI_CONFIGURATION_WRITE_TYPE_1,    ///< Configuration Write Type 1 (CfgWr1)
} pci_configuration_write_type_t;

/** PCI Configuration Read Type 0/1 */
typedef enum e_pci_configuration_read_type
{
    PCI_CONFIGURATION_READ_TYPE_0,     ///< Configuration Read Type 0 (CfgRd0)
    PCI_CONFIGURATION_READ_TYPE_1,     ///< Configuration Read Type 1 (CfgRd1)
} pci_configuration_read_type_t;

/** PCI Express link speed */
typedef enum e_pci_link_speed
{
    PCI_LINK_SPEED_2_5_GTS  = 0,       ///< 2.5 GT/s PCI Express link
    PCI_LINK_SPEED_5_0_GTS  = 1,       ///< 5.0 GT/s PCI Express link
    PCI_LINK_SPEED_8_0_GTS  = 2,       ///< 8.0 GT/s PCI Express link
    PCI_LINK_SPEED_16_0_GTS = 3,       ///< 16.0 GT/s PCI Express link
} pci_link_speed_t;

/** PCI Express LTSSM state. */
typedef enum e_pci_ltssm_state
{
    PCI_LTSSM_STATE_DETECT,            ///< LTSSM detect state
    PCI_LTSSM_STATE_POLLING,           ///< LTSSM polling state
    PCI_LTSSM_STATE_CONFIG,            ///< LTSSM configuration state
    PCI_LTSSM_STATE_L0,                ///< LTSSM L0 state
    PCI_LTSSM_STATE_L1,                ///< LTSSM L1 state
    PCI_LTSSM_STATE_L2,                ///< LTSSM L2 state
    PCI_LTSSM_STATE_RECOVERY,          ///< LTSSM recovery state
    PCI_LTSSM_STATE_DISABLE,           ///< LTSSM disable state
    PCI_LTSSM_STATE_LOOPBACK           ///< LTSSM loopback state
} pci_ltssm_state_t;

/** Structure to define a PCI configuration register. */
typedef struct st_pci_configuration_register_init
{
    uint32_t register_number;          ///< Configuration register number to be initialized.
    uint32_t init_value;               ///< Configuration register initial value to be initialized.
    uint32_t init_value_mask;          ///< Configuration register initial value mask to be initialized.
} pci_configuration_register_init_t;

/** Structure to define a CfgRd/CfgWr request transfer. */
typedef struct st_pci_configuration_register_transfer
{
    union
    {
        struct
        {
            uint8_t                     : 2;
            uint8_t register_number     : 6; ///< Register number
            uint8_t ext_register_number : 4; ///< Extended register number
            uint8_t                     : 4;
            uint8_t function_number     : 3; ///< Function number
            uint8_t device_number       : 5; ///< Device number
            uint8_t bus_number          : 8; ///< Bus number
        } header_word_b;

        uint32_t header_word;
    };

    uint32_t data;
} pci_configuration_register_transfer_t;

/** Structure to define a IORd/IOWr request transfer. */
typedef struct st_pci_io_register_transfer
{
    uint32_t address;                  ///< I/O address
} pci_io_register_transfer_t;

/** Structure to define a PCI Express Msg/MsgD request transfer. */
typedef struct st_pci_message_transfer
{
    union
    {
        struct
        {
            uint32_t             : 24;
            uint8_t routing_type : 3;  ///< Routing type
            uint8_t              : 5;
        } header_1st_word_b;

        uint32_t header_1st_word;
    };

    union
    {
        struct
        {
            uint8_t message_code : 8;  ///< Message code
            uint32_t             : 24;
        } header_2nd_word_b;

        uint32_t header_2nd_word;
    };

    uint32_t header_3rd;               ///< Message 3rd header
    uint32_t header_4th;               ///< Message 4th header
    uint32_t data;                     ///< Message data for MsgD request
} pci_message_transfer_t;

/** PCI Express status */
typedef struct st_pci_status
{
    bool              is_link_up;      ///< Current link up state
    pci_ltssm_state_t ltssm_state;     ///< Current LTSSM state
} pci_status_t;

/** Common callback parameter definition */
typedef struct st_pci_callback_args
{
    pci_event_t event;                 ///< Event code
    uint32_t    dma_channel;           ///< Channel of DMA (valid only for DMA-related events)
    uint32_t    data1;                 ///< Data when event interrupt occurred.
    uint32_t    data2;                 ///< Data when event interrupt occurred.
    uint32_t    data3;                 ///< Data when event interrupt occurred.
    void      * p_context;             ///< Context provided to user during callback
} pci_callback_args_t;

/** PCI control block.  Allocate an instance specific control block to pass into the PCI API calls.
 */
typedef void pci_ctrl_t;

/** User configuration structure, used in open function */
typedef struct st_pci_cfg
{
    uint8_t channel;                              ///< Channel number to be used
    uint8_t function;                             ///< PCI function number to be used

    void const * p_configuration_register_header; ///< PCI configuration register

    /** List of configuration registers initialized in pci_api_t::open. */
    pci_configuration_register_init_t const * p_configuration_register_init_list;

    uint32_t configuration_register_init_list_length; ///< Length of configuration register list initialized in pci_api_t::open.

    IRQn_Type inta_irq;                               ///< INTA interrupt number
    uint8_t   inta_ipl;                               ///< INTA interrupt priority
    IRQn_Type intb_irq;                               ///< INTB interrupt number
    uint8_t   intb_ipl;                               ///< INTB interrupt priority
    IRQn_Type intc_irq;                               ///< INTC interrupt number
    uint8_t   intc_ipl;                               ///< INTC interrupt priority
    IRQn_Type intd_irq;                               ///< INTD interrupt number
    uint8_t   intd_ipl;                               ///< INTD interrupt priority
    IRQn_Type msi_irq;                                ///< MSI interrupt number
    uint8_t   msi_ipl;                                ///< MSI interrupt priority

    void       * p_context;                           ///< User defined context passed to callback function
    void const * p_extend;                            ///< Extended PCI hardware dependent configuration

    /** Callback provided when a PCI ISR occurs.  Set to NULL for no CPU interrupt. */
    void (* p_callback)(pci_callback_args_t * p_args);
} pci_cfg_t;

/** PCI driver structure. General PCI functions implemented at the HAL layer will follow this API. */
typedef struct st_pci_api
{
    /** Open function for PCI device.
     *
     * @param[in,out]  p_ctrl     Pointer to the PCI control block. Must be declared by user. Value set here.
     * @param[in]      p_cfg      Pointer to PCI configuration structure. All elements of this structure must be set by
     *                            user.
     */
    fsp_err_t (* open)(pci_ctrl_t * const p_ctrl, pci_cfg_t const * const p_cfg);

    /** Get the self PCI configuration register value.
     *
     * @param[in,out]  p_ctrl              Pointer to the PCI control block.
     * @param[in]      register_number     Register number of the configuration register.
     * @param[out]     p_data              Memory address to return data.
     */
    fsp_err_t (* selfConfigurationRegisterGet)(pci_ctrl_t * const p_ctrl, uint32_t register_number, uint32_t * p_data);

    /** Set the self PCI configuration register value.
     *
     * @param[in,out]  p_ctrl              Pointer to the PCI control block.
     * @param[in]      register_number     Register number of the configuration register.
     * @param[in]      data                Value to set.
     */
    fsp_err_t (* selfConfigurationRegisterSet)(pci_ctrl_t * const p_ctrl, uint32_t register_number, uint32_t data);

    /** Issue Configuration Write Type 0/1 Request (CfgWr 0/1).
     *
     * @param[in]   p_ctrl           Pointer to the PCI control block.
     * @param[in]   transaction_type Whether issue CfgWr0 or CfgWr1
     * @param[in]   p_transfer       Pointer for data to send.
     */
    fsp_err_t (* configurationRegisterWrite)(pci_ctrl_t * const p_ctrl, pci_configuration_write_type_t transaction_type,
                                             pci_configuration_register_transfer_t * const p_transfer);

    /** Issue Configuration Read Type 0/1 Request (CfgRd 0/1).
     *
     * @param[in]   p_ctrl           Pointer to the PCI control block.
     * @param[in]   transaction_type Whether issue CfgRd0 or CfgRd1
     * @param[in]   p_transfer       Pointer for store receive data.
     */
    fsp_err_t (* configurationRegisterRead)(pci_ctrl_t * const p_ctrl, pci_configuration_read_type_t transaction_type,
                                            pci_configuration_register_transfer_t * const p_transfer);

    /** Issue I/O Write Request (IOWr).
     *
     * @param[in]   p_ctrl          Pointer to the PCI control block.
     * @param[in]   p_transfer      Pointer for data to send.
     */
    fsp_err_t (* iORegisterWrite)(pci_ctrl_t * const p_ctrl, pci_io_register_transfer_t * const p_transfer);

    /** Issue I/O Read Request (IORd).
     *
     * @param[in]   p_ctrl          Pointer to the PCI control block.
     * @param[in]   p_transfer      Pointer for store receive I/O data.
     */
    fsp_err_t (* iORegisterRead)(pci_ctrl_t * const p_ctrl, pci_io_register_transfer_t * const p_transfer);

    /** PCI Express issue Message Request (Msg) / Message Request with data payload (MsgD).
     *
     * @param[in]   p_ctrl          Pointer to the PCI control block.
     * @param[in]   p_transfer      Pointer for message data to send.
     * @param[in]   with_data       Weather issue Meg or MsgD request.
     */
    fsp_err_t (* messageWrite)(pci_ctrl_t * const p_ctrl, pci_message_transfer_t * const p_transfer, bool with_data);

    /** PCI Express read Message Request.
     *
     * @param[in]   p_ctrl          Pointer to the PCI control block.
     * @param[in]   p_transfer      Pointer for store receive message data.
     *
     */
    fsp_err_t (* messageRead)(pci_ctrl_t * const p_ctrl, pci_message_transfer_t * const p_transfer);

    /** Assert INTx interrupt.
     *
     * @param[in]  p_ctrl     Pointer to the PCI control block.
     */
    fsp_err_t (* intxAssert)(pci_ctrl_t * const p_ctrl);

    /** Deassert INTx interrupt.
     *
     * @param[in]  p_ctrl     Pointer to the PCI control block.
     */
    fsp_err_t (* intxDeassert)(pci_ctrl_t * const p_ctrl);

    /** Get PCI Express link information.
     *
     * @param[in,out]  p_ctrl     Pointer to the PCI control block.
     * @param[out]     p_status   Memory address to return data.
     */
    fsp_err_t (* linkStatusGet)(pci_ctrl_t * const p_ctrl, pci_status_t * const p_status);

    /** PCI Express link width change.
     *
     * @param[in]  p_ctrl     Pointer to the PCI control block.
     * @param[in]  link_width Link width to change.
     * @param[in]  option     Option when link width to change.
     */
    fsp_err_t (* linkWidthChange)(pci_ctrl_t * const p_ctrl, uint32_t link_width, uint32_t option);

    /** PCI Express link speed change.
     *
     * @param[in]  p_ctrl     Pointer to the PCI control block.
     * @param[in]  link_speed Link speed to change.
     * @param[in]  option     Option when link speed to change.
     */
    fsp_err_t (* linkSpeedChange)(pci_ctrl_t * const p_ctrl, pci_link_speed_t link_speed, uint32_t option);

    /** PCI Express send link equalization.
     *
     * @param[in]  p_ctrl     Pointer to the PCI control block.
     */
    fsp_err_t (* linkEqualizationRequest)(pci_ctrl_t * const p_ctrl);

    /** Specify callback function and optional context pointer and working memory pointer.
     *
     * @param[in]   p_ctrl                   Control block set in @ref pci_api_t::open call.
     * @param[in]   p_callback               Callback function to register
     * @param[in]   p_context                Pointer to send to callback function
     * @param[in]   p_working_memory         Pointer to volatile memory where callback structure can be allocated.
     *                                       Callback arguments allocated here are only valid during the callback.
     */
    fsp_err_t (* callbackSet)(pci_ctrl_t * const p_ctrl, void (* p_callback)(pci_callback_args_t *),
                              void * const p_context, pci_callback_args_t * const p_callback_memory);

    /** Close function for PCI device.
     * @param[in]   p_ctrl     Pointer to the PCI control block.
     */
    fsp_err_t (* close)(pci_ctrl_t * const p_ctrl);
} pci_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_pci_instance
{
    pci_ctrl_t      * p_ctrl;          ///< Pointer to the control structure for this instance
    pci_cfg_t const * p_cfg;           ///< Pointer to the configuration structure for this instance
    pci_api_t const * p_api;           ///< Pointer to the API structure for this instance
} pci_instance_t;

/*******************************************************************************************************************//**
 * @} (end defgroup PCI_API)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
