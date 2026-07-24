/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#ifndef R_PCIE_EP_H
 #define R_PCIE_EP_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include "r_pcie_ep_cfg.h"
 #include "r_pci_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
 #define R_PCIE_EP_NUM_AXI_WINDOW     (8)
 #define R_PCIE_EP_NUM_PCIE_WINDOW    (8)

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZT
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_PCIE_EP
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** PCI Express Link Mode */
typedef enum e_pcie_ep_link_mode
{
 #if (1 < BSP_FEATURE_PCIE_SUPPORT_LINK_WIDTH)
    PCIE_EP_LINK_MODE_2LANE_1CHANNEL = 1U << R_PCIE_LNK_PCIE_LINKMODE_LINK_MASTER_Pos, ///< PCIe 2 lanes x 1 channel
    PCIE_EP_LINK_MODE_1LANE_2CHANNEL = 3U << R_PCIE_LNK_PCIE_LINKMODE_LINK_MASTER_Pos  ///< PCIe 1 lane x 2 channels
 #else
    PCIE_EP_LINK_MODE_1LANE_1CHANNEL = 0xFF                                            ///< PCIe 1 lane x 1 channel
 #endif
} pcie_ep_link_mode_t;

/** AXI/PCIe window setting structure. */
struct st_pcie_ep_window_settings
{
    uint64_t base_address;             ///< AXI/PCIe Window Base address
    uint64_t mask_address;             ///< AXI/PCIe Window Mask address
    uint64_t destination_address;      ///< AXI/PCIe Destination address
    bool     window_enable;            ///< AXI/PCIe Window setting Enable/Disable
};

/** AXI/PCIe window setting structure. Please refer to the struct st_pcie_ep_window_settings. */
typedef struct st_pcie_ep_window_settings pcie_ep_window_settings_t;

/** Type 0 Configuration Space Header structure. */
struct st_pcie_ep_configuration_register_0
{
    uint32_t vender_device_id;           ///< Device ID / Vendor ID
    uint32_t command_status;             ///< Status / Command
    uint32_t revision_id_class_code;     ///< Class Code / Revision ID
    uint32_t cahce_line_header_type;     ///< BIST / Header Type / Master Latency Timer / Cache Line Size
    uint32_t base_address_register_0;    ///< Base Address Register 0
    uint32_t base_address_register_1;    ///< Base Address Register 1
    uint32_t base_address_register_2;    ///< Base Address Register 2
    uint32_t base_address_register_3;    ///< Base Address Register 3
    uint32_t base_address_register_4;    ///< Base Address Register 4
    uint32_t base_address_register_5;    ///< Base Address Register 5
    uint32_t cardbus_cis_pointer;        ///< Cardbus CIS Pointer
    uint32_t subsystem_id;               ///< Subsystem ID / Subsystem Vendor ID
    uint32_t expansion_rom_base_address; ///< Expansion ROM Base Address
    uint32_t capability_pointer;         ///< Capabilities Pointer
    uint32_t reserved;                   ///< Reserved
    uint32_t interrupt;                  ///< Max_Lat / Min_Gnt / Interrupt Pin / Interrupt Line
};

/** Type 0 Configuration Space Header structure. Please refer to the struct st_pcie_ep_configuration_register_0. */
typedef struct st_pcie_ep_configuration_register_0 pcie_ep_configuration_register_0_t;

/** Driver instance control structure. */
struct st_pcie_ep_instance_ctrl
{
    uint32_t open;                              // Open status of channel.
    uint32_t channel;                           // Using channel.
    uint32_t function;                          // Using function.

    const pci_cfg_t * p_cfg;                    // Pointer to the configuration structure

    R_PCIE0_Type     * p_reg;                   // Pointer to register base address
    R_PCIE_PHY_Type  * p_reg_phy;               // Pointer to physical layer control/status register base address
    R_PCIE_SPL0_Type * p_reg_spl;               // Pointer to supplemental setting register base address
 #if (1 < BSP_FEATURE_PCIE_SUPPORT_LINK_WIDTH)
    R_PCIE_LNK_Type * p_reg_lnk;                // Pointer to PCIe Link Mode register base address
 #endif

    void (* p_callback)(pci_callback_args_t *); // Pointer to callback
    pci_callback_args_t * p_callback_memory;    // Pointer to optional callback argument memory
    void                * p_context;            // Pointer to context to be passed into callback function
};

/** Driver instance control structure. Please refer to the struct st_pcie_ep_instance_ctrl. */
typedef struct st_pcie_ep_instance_ctrl pcie_ep_instance_ctrl_t;

/** PCIE_EP extension data structure.*/
struct st_pcie_ep_extended_cfg
{
 #if (1 < BSP_FEATURE_PCIE_SUPPORT_LINK_WIDTH)
    pcie_ep_link_mode_t link_mode;                                            ///< PCI Express Link mode.
 #endif

    pcie_ep_window_settings_t axi_window_settings[R_PCIE_EP_NUM_AXI_WINDOW];  ///< Settings the AXI Window (PCIe to AXI)
    pcie_ep_window_settings_t pci_window_settings[R_PCIE_EP_NUM_PCIE_WINDOW]; ///< Settings the PCIe Window (AXI to PCIe)

    uint32_t event0_interrupts;                                               ///< Event0 interrupt enable bits
    uint32_t event1_interrupts;                                               ///< Event1 interrupt enable bits
    uint32_t event2_interrupts;                                               ///< Event2 interrupt enable bits

    IRQn_Type msg_irq;                                                        ///< PCI Express Message Receive Interrupt Number
    uint8_t   msg_ipl;                                                        ///< PCI Express Message Receive Interrupt Priority
    IRQn_Type flr_irq;                                                        ///< Function Level Reset Interrupt Number
    uint8_t   flr_ipl;                                                        ///< Function Level Reset Interrupt Priority
    IRQn_Type d3_event_irq;                                                   ///< Non-D0 State transition request receive output interrupt
    uint8_t   d3_event_ipl;                                                   ///< Non-D0 State transition request receive output interrupt priority
    IRQn_Type pme_turn_off_rcv_irq;                                           ///< PME_Turn_Off Message receive interrupt
    uint8_t   pme_turn_off_rcv_ipl;                                           ///< PME_Turn_Off Message receive interrupt priority
    IRQn_Type poweroff_indication_l2_irq;                                     ///< POWEROFF indication on L2 interrupt
    uint8_t   poweroff_indication_l2_ipl;                                     ///< POWEROFF indication on L2 interrupt priority
    IRQn_Type pcie_event_irq;                                                 ///< Event Interrupt
    uint8_t   pcie_event_ipl;                                                 ///< Event Interrupt priority

    void * p_reg;                                                             ///< AXI bridge registers base address for specified channel
    void * p_reg_spl;                                                         ///< Supplemental setting registers base address for specified channel
};

/** PCIE_EP extension data structure. Please refer to the struct st_pcie_ep_extended_cfg. */
typedef struct st_pcie_ep_extended_cfg pcie_ep_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const pci_api_t g_pci_on_pcie_ep;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_PCIE_EP_Open(pci_ctrl_t * const p_ctrl, pci_cfg_t const * const p_cfg);
fsp_err_t R_PCIE_EP_SelfConfigurationRegisterSet(pci_ctrl_t * const p_ctrl, uint32_t register_number, uint32_t data);
fsp_err_t R_PCIE_EP_SelfConfigurationRegisterGet(pci_ctrl_t * const p_ctrl, uint32_t register_number,
                                                 uint32_t * p_data);
fsp_err_t R_PCIE_EP_ConfigurationRegisterWrite(pci_ctrl_t * const                            p_ctrl,
                                               pci_configuration_write_type_t                transaction_type,
                                               pci_configuration_register_transfer_t * const p_transfer);
fsp_err_t R_PCIE_EP_ConfigurationRegisterRead(pci_ctrl_t * const                            p_ctrl,
                                              pci_configuration_read_type_t                 transaction_type,
                                              pci_configuration_register_transfer_t * const p_transfer);
fsp_err_t R_PCIE_EP_IORegisterWrite(pci_ctrl_t * const p_ctrl, pci_io_register_transfer_t * const p_transfer);
fsp_err_t R_PCIE_EP_IORegisterRead(pci_ctrl_t * const p_ctrl, pci_io_register_transfer_t * const p_transfer);
fsp_err_t R_PCIE_EP_MessageWrite(pci_ctrl_t * const p_ctrl, pci_message_transfer_t * const p_transfer, bool with_data);
fsp_err_t R_PCIE_EP_MessageRead(pci_ctrl_t * const p_ctrl, pci_message_transfer_t * const p_transfer);
fsp_err_t R_PCIE_EP_IntxAssert(pci_ctrl_t * const p_ctrl);
fsp_err_t R_PCIE_EP_IntxDeassert(pci_ctrl_t * const p_ctrl);
fsp_err_t R_PCIE_EP_LinkStatusGet(pci_ctrl_t * const p_ctrl, pci_status_t * const p_status);
fsp_err_t R_PCIE_EP_LinkWidthChange(pci_ctrl_t * const p_ctrl, uint32_t link_width, uint32_t option);
fsp_err_t R_PCIE_EP_LinkSpeedChange(pci_ctrl_t * const p_ctrl, pci_link_speed_t link_speed, uint32_t option);
fsp_err_t R_PCIE_EP_LinkEqualizationRequest(pci_ctrl_t * const p_ctrl);
fsp_err_t R_PCIE_EP_CallbackSet(pci_ctrl_t * const          p_ctrl,
                                void (                    * p_callback)(pci_callback_args_t *),
                                void * const                p_context,
                                pci_callback_args_t * const p_callback_memory);
fsp_err_t R_PCIE_EP_Close(pci_ctrl_t * const p_ctrl);

/*******************************************************************************************************************//**
 * @} (end defgroup PCIE_EP)
 **********************************************************************************************************************/
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
