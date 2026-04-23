/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/

#include <string.h>

#include "bsp_api.h"
#include "r_ether_cfg.h"

#include "r_gmac_b.h"
#include "r_ether_phy.h"

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

#ifndef GMAC_ERROR_RETURN

/*LDRA_INSPECTED 77 S This macro does not work when surrounded by parentheses. */
 #define GMAC_ERROR_RETURN(a, err)    FSP_ERROR_RETURN((a), (err))
#endif

/** "ETHE" in ASCII.  Used to determine if the control block is open. */
#define GMAC_B_OPEN                  (0x45544845U)

/* Definition of the maximum of data that can be sent at one time in the Ethernet */
#define GMAC_B_MINIMUM_FRAME_SIZE    (60U) /* Minimum number of transmitted data */

/* the number of byte for FCS in ethernet frame */
#define GMAC_B_FCS_SIZE              (4U)

/* GMAC_B_NO_DATA is the return value that indicates that no received data. */
#define GMAC_B_NO_DATA               (0)

#define GMAC_B_PAUSE_TIME            (0xFFFFU)

/* Bit definitions of control/status member of Transmit Descriptor-2 */
#define GMAC_B_TDES2_IOC             (1UL << 31)                     /* Interrupt on Completion */
#define GMAC_B_TDES2_TTSE            (1UL << 30)                     /* Transmit Timestamp Enable */
#define GMAC_B_TDES2_TMWD            (1UL << 30)                     /* External TSO Memory Write Enable */
#define GMAC_B_TDES2_B2L(x)     (((x) << 16) & 0x3FFF0000U)          /* Buffer 2 Length */
#define GMAC_B_TDES2_VTIR(x)    (((x) << 14) & 0x0000C000U)          /* VLAN Tag Insertion or Replacement */
#define GMAC_B_TDES2_HL(x)      (((x) << 0) & 0x00003FFFU)           /* Header Length */
#define GMAC_B_TDES2_B1L(x)     (((x) << 0) & 0x00003FFFU)           /* Buffer 1 Length */

/* Bit definitions of control/status member of Transmit Descriptor-3 */
#define GMAC_B_TDES3_OWN     (1UL << 31)                             /* Own Bit */
/* Read Format */
#define GMAC_B_TDES3_CTXT    (1UL << 30)                             /* Context Type */
#define GMAC_B_TDES3_FD      (1UL << 29)                             /* First Descriptor */
#define GMAC_B_TDES3_LD      (1UL << 28)                             /* Last Descriptor */
#define GMAC_B_TDES3_CPC(x)        (((x) << 26) & 0x0C000000U)       /* CRC Pad Control */
#define GMAC_B_TDES3_SAIC(x)       (((x) << 23) & 0x03000000U)       /* SA Insertion Control */
#define GMAC_B_TDES3_SLOTNUM(x)    (((x) << 19) & 0x00F00000U)       /* Slot Number Control Bits in AV Mode */
#define GMAC_B_TDES3_THL(x)        (((x) << 19) & 0x00F00000U)       /* TCP/UDP Header Length */
#define GMAC_B_TDES3_TSE     (1UL << 18)                             /* TCP Segmentation Enable */
#define GMAC_B_TDES3_CIC(x)        (((x) << 19) & 0x00060000U)       /* Checksum Insertion Control */
#define GMAC_B_TDES3_FL(x)         (((x) << 0) & 0x0000FFFFU)        /* Frame Length */
#define GMAC_B_TDES3_TPL(x)        (((x) << 0) & 0x0007FFFFU)        /* TCP Payload Length */

/* Bit definitions of control/status member of Receive Descriptor-3 */
#define GMAC_B_RDES3_OWN                                 (1UL << 31) /* Own Bit */
/* Read Format */
#define GMAC_B_RDES3_IOC                                 (1UL << 30) /* Interrupt Enabled on Completion */
#define GMAC_B_RDES3_BUF2V                               (1UL << 25) /* Buffer 2 Address Valid */
#define GMAC_B_RDES3_BUF1V                               (1UL << 24) /* Buffer 1 Address Valid */
/* Write-Back Format */
#define GMAC_B_RDES3_CTXT                                (1UL << 30) /* Context Type */
#define GMAC_B_RDES3_FD                                  (1UL << 29) /* First Descriptor */
#define GMAC_B_RDES3_LD                                  (1UL << 28) /* Last Descriptor */
#define GMAC_B_RDES3_RS2V                                (1UL << 27) /* Receive Status RDES2 Valid */
#define GMAC_B_RDES3_RS1V                                (1UL << 26) /* Receive Status RDES1 Valid */
#define GMAC_B_RDES3_RS0V                                (1UL << 25) /* Receive Status RDES0 Valid */
#define GMAC_B_RDES3_CE                                  (1UL << 24) /* CRC Error */
#define GMAC_B_RDES3_GP                                  (1UL << 23) /* Receive Watchdog Timeout */
#define GMAC_B_RDES3_RWT                                 (1UL << 22) /* Receive Watchdog Timeout */
#define GMAC_B_RDES3_OE                                  (1UL << 21) /* Overflow Error */
#define GMAC_B_RDES3_RE                                  (1UL << 20) /* Receive Error */
#define GMAC_B_RDES3_DE                                  (1UL << 19) /* Dribble Bit Error */
#define GMAC_B_RDES3_LT(x)    (((x) << 0) & 0x00007FFFU)             /* Frame Length */
#define GMAC_B_RDES3_ES                                  (1UL << 14) /* Error Summary */
#define GMAC_B_RDES3_PL(x)    (((x) << 0) & 0x00007FFFU)             /* Frame Length */
#define GMAC_B_RDES3_PL_MASK                             0x00007FFFU
#define GMAC_B_RDES3_PL_SHIFT                            0

/* Bit definition of DMA Interrupt Status register */
#define GMAC_B_DMA_INTERRUPT_STATUS_MACIS                (1UL << 17) /* MAC Interrupt Status */
#define GMAC_B_DMA_INTERRUPT_STATUS_MTLIS                (1UL << 16) /* MTL Interrupt Status */
#define GMAC_B_DMA_INTERRUPT_STATUS_DCiIS(i)    (1UL << (i))         /* i = {0...MAX(RXDMACNT,TXDMACNT)-1} */
#define GMAC_B_DMA_INTERRUPT_STATUS_DC7IS                (1UL << 7)  /* DMA Channel 7 Interrupt Status */
#define GMAC_B_DMA_INTERRUPT_STATUS_DC6IS                (1UL << 6)  /* DMA Channel 6 Interrupt Status */
#define GMAC_B_DMA_INTERRUPT_STATUS_DC5IS                (1UL << 5)  /* DMA Channel 5 Interrupt Status */
#define GMAC_B_DMA_INTERRUPT_STATUS_DC4IS                (1UL << 4)  /* DMA Channel 4 Interrupt Status */
#define GMAC_B_DMA_INTERRUPT_STATUS_DC3IS                (1UL << 3)  /* DMA Channel 3 Interrupt Status */
#define GMAC_B_DMA_INTERRUPT_STATUS_DC2IS                (1UL << 2)  /* DMA Channel 2 Interrupt Status */
#define GMAC_B_DMA_INTERRUPT_STATUS_DC1IS                (1UL << 1)  /* DMA Channel 1 Interrupt Status */
#define GMAC_B_DMA_INTERRUPT_STATUS_DC0IS                (1UL << 0)  /* DMA Channel 0 Interrupt Status */

/* Bit definition of Interrupt Enable Register */
#define GMAC_B_MAC_INTERRUPT_STATUS_MFRIS                (1UL << 20) /* MMC FPE Receive Interrupt Status */
#define GMAC_B_MAC_INTERRUPT_STATUS_MFTIS                (1UL << 19) /* MMC FPE Transmit Interrupt Status */
#define GMAC_B_MAC_INTERRUPT_STATUS_MDIOIS               (1UL << 18) /* MDIO Interrupt Status */
#define GMAC_B_MAC_INTERRUPT_STATUS_FPEIS                (1UL << 17) /* Frame Preemption Interrupt Status */
#define GMAC_B_MAC_INTERRUPT_STATUS_RXSTSIS              (1UL << 14) /* Receive Status Interrupt */
#define GMAC_B_MAC_INTERRUPT_STATUS_TXSTSIS              (1UL << 13) /* Transmit Status Interrupt */
#define GMAC_B_MAC_INTERRUPT_STATUS_TSIS                 (1UL << 12) /* Timestamp Interrupt Status */
#define GMAC_B_MAC_INTERRUPT_STATUS_MMCRXPIS             (1UL << 11) /* MMC Receive Checksum Offload Interrupt Status */
#define GMAC_B_MAC_INTERRUPT_STATUS_MMCTXIS              (1UL << 10) /* MMC Transmit Interrupt Status */
#define GMAC_B_MAC_INTERRUPT_STATUS_MMCRXIS              (1UL << 9)  /* MMC Receive Interrupt Status */
#define GMAC_B_MAC_INTERRUPT_STATUS_MMCIS                (1UL << 8)  /* MMC Interrupt Status */
#define GMAC_B_MAC_INTERRUPT_STATUS_LPIIS                (1UL << 5)  /* LPI Interrupt Status */
#define GMAC_B_MAC_INTERRUPT_STATUS_PMTIS                (1UL << 4)  /* PMT Interrupt Status */
#define GMAC_B_MAC_INTERRUPT_STATUS_PHYIS                (1UL << 3)  /* PHY Interrupt */
#define GMAC_B_MAC_INTERRUPT_STATUS_PCSANCIS             (1UL << 2)  /* PCS Auto-Negotiation Complete */
#define GMAC_B_MAC_INTERRUPT_STATUS_PCSLCHGIS            (1UL << 1)  /* PCS Link Status Changed */
#define GMAC_B_MAC_INTERRUPT_STATUS_RGSMIIIS             (1UL << 0)  /* RGMII or SMI Interrupt Status */

/* Bit definition of Interrupt Enable Register */
#define GMAC_B_DMA_CH_INTERRUPT_ENABLE_NIE               (1UL << 15) /* Normal Interrupt Summary Enable */
#define GMAC_B_DMA_CH_INTERRUPT_ENABLE_AIE               (1UL << 14) /* Abnormal Interrupt Summary Enable */
#define GMAC_B_DMA_CH_INTERRUPT_ENABLE_CDEE              (1UL << 13) /* Context Descriptor Error Enable */
#define GMAC_B_DMA_CH_INTERRUPT_ENABLE_FBEE              (1UL << 12) /* Fatal Bus Error Enable */
#define GMAC_B_DMA_CH_INTERRUPT_ENABLE_ERIE              (1UL << 11) /* Early Receive Interrupt Enable */
#define GMAC_B_DMA_CH_INTERRUPT_ENABLE_ETIE              (1UL << 10) /* Early Transmit Interrupt Enable */
#define GMAC_B_DMA_CH_INTERRUPT_ENABLE_RWTE              (1UL << 9)  /* Receive Watchdog Timeout Enable */
#define GMAC_B_DMA_CH_INTERRUPT_ENABLE_RSE               (1UL << 8)  /* Receive Stopped Enable */
#define GMAC_B_DMA_CH_INTERRUPT_ENABLE_RBUE              (1UL << 7)  /* Receive Buffer Unavailable Enable */
#define GMAC_B_DMA_CH_INTERRUPT_ENABLE_RIE               (1UL << 6)  /* Receive Interrupt Enable */
#define GMAC_B_DMA_CH_INTERRUPT_ENABLE_TBUE              (1UL << 2)  /* Transmit Buffer Unavailable Enable */
#define GMAC_B_DMA_CH_INTERRUPT_ENABLE_TXSE              (1UL << 1)  /* Transmit Stopped Enable */
#define GMAC_B_DMA_CH_INTERRUPT_ENABLE_TIE               (1UL << 0)  /* Transmit Interrupt Enable */

/* Bit definition of Flow Control Register */
#define GMAC_B_FLOW_CONTROL_PT_VALUE                     (0x0000FFFFUL)
#define GMAC_B_FLOW_CONTROL_PLT_VALUE                    (0x00000002UL)

#define GMAC_B_FLOW_CONTROL_PT                           (GMAC_B_FLOW_CONTROL_PT_VALUE << 16) /* Pause Time (b31-b16) */
#define GMAC_B_FLOW_CONTROL_DZPQ                         (1UL << 7)                           /* Disable Zero-Quanta Pause */
#define GMAC_B_FLOW_CONTROL_PLT                          (GMAC_B_FLOW_CONTROL_PLT_VALUE << 4) /* Pause Low Threshold */
#define GMAC_B_FLOW_CONTROL_UP                           (1UL << 3)                           /* Unicast Pause Frame Detect */
#define GMAC_B_FLOW_CONTROL_RFE                          (1UL << 2)                           /* Receive Flow Control Enable */
#define GMAC_B_FLOW_CONTROL_TFE                          (1UL << 1)                           /* Transmit Flow Control Enable */
#define GMAC_B_FLOW_CONTROL_FCA_BPA                      (1UL << 0)                           /* Flow Control Busy or Backpressure Activate */

/* Bit definition of Flow Control Register */
#define GMAC_B_PMT_CONTROL_STATUS_RWKFILTRST             (1UL << 31)                          /* Wake-Up Frame Filter Register Pointer Reset */
#define GMAC_B_PMT_CONTROL_STATUS_RWKPFE                 (1UL << 10)                          /* Remote Wake-up Packet Forwarding Enable */
#define GMAC_B_PMT_CONTROL_STATUS_GLBLUCAST              (1UL << 9)                           /* Global Unicas */
#define GMAC_B_PMT_CONTROL_STATUS_RWKPRCVD               (1UL << 6)                           /* Wake-Up Frame Received */
#define GMAC_B_PMT_CONTROL_STATUS_MGKPRCVD               (1UL << 5)                           /* Magic Packet Received */
#define GMAC_B_PMT_CONTROL_STATUS_RWKPKTEN               (1UL << 2)                           /* Wake-Up Frame Enable */
#define GMAC_B_PMT_CONTROL_STATUS_MGKPKTEN               (1UL << 1)                           /* Magic Packet Enable */
#define GMAC_B_PMT_CONTROL_STATUS_PWRDWN                 (1UL << 0)                           /* Power Down */

/* Number of entries in PAUSE resolution table */
#define GMAC_B_PAUSE_TABLE_ENTRIES                       (8)

/* Local device and link partner PAUSE settings */
#define GMAC_B_PAUSE_XMIT_OFF                            (0) /* The pause frame transmission is prohibited. */
#define GMAC_B_PAUSE_RECV_OFF                            (0) /* The pause frame reception is prohibited.    */
#define GMAC_B_PAUSE_XMIT_ON                             (1) /* The pause frame transmission is permitted.  */
#define GMAC_B_PAUSE_RECV_ON                             (1) /* The pause frame reception is permitted.     */

/* PAUSE link mask and shift values */

/*
 * The mask value and shift value which are for that shift the bits form a line and
 * for comparing the bit information of PAUSE function which support the local device and
 * Link partner with the assorted table(pause_resolution) which enable or disable the PAUSE frame.
 */
#define GMAC_B_LINK_RESOLUTION_ABILITY_MASK              (3)
#define GMAC_B_LINK_RESOLUTION_LOCAL_ABILITY_BITSHIFT    (2)

/* Etherc mode */
#define GMAC_B_NO_USE_MAGIC_PACKET_DETECT                (0)
#define GMAC_B_USE_MAGIC_PACKET_DETECT                   (1)

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static fsp_err_t gmac_b_open_param_check(gmac_b_instance_ctrl_t const * const p_instance_ctrl,
                                         ether_cfg_t const * const            p_cfg);
static fsp_err_t gmac_b_read_param_check(gmac_b_instance_ctrl_t * p_instance_ctrl,
                                         void * const             p_buffer,
                                         uint32_t * const         length_bytes);

static fsp_err_t gmac_b_write_param_check(gmac_b_instance_ctrl_t * p_instance_ctrl,
                                          void * const             p_buffer,
                                          uint32_t const           frame_length);
static void gmac_b_enable_icu(gmac_b_instance_ctrl_t * const p_instance_ctrl);
static void gmac_b_disable_icu(gmac_b_instance_ctrl_t * const p_instance_ctrl);
static void gmac_b_reset_mac(volatile R_GBETH_Type * const p_reg);
static void gmac_b_init_sysbus(volatile R_GBETH_Type * const p_reg);

#ifdef GMAC_B_IMPLEMENT_ETHSW
fsp_err_t gmac_b_open_ethsw(gmac_b_instance_ctrl_t * p_instance_ctrl);

#endif                                 // GMAC_B_IMPLEMENT_ETHSW
fsp_err_t   gmac_b_open_phy(gmac_b_instance_ctrl_t * p_instance_ctrl);
static void gmac_b_init_descriptors(gmac_b_instance_ctrl_t * const p_instance_ctrl);

static void gmac_b_configure_mac(gmac_b_instance_ctrl_t * const p_instance_ctrl,
                                 const uint8_t                  mac_addr[],
                                 const uint8_t                  mode);
static void gmac_b_disable(gmac_b_instance_ctrl_t * const p_instance_ctrl);
static void gmac_b_call_user_callback(gmac_b_instance_ctrl_t * p_instance_ctrl,
                                      ether_event_t            event,
                                      gmac_b_port_mask_t       link_status);
static fsp_err_t            gmac_b_link_process(gmac_b_instance_ctrl_t * p_instance_ctrl, uint32_t port);
static gmac_b_link_change_t gmac_b_link_change_check(gmac_b_instance_ctrl_t * p_instance_ctrl, uint32_t port);
static fsp_err_t            gmac_b_do_link(gmac_b_instance_ctrl_t * const p_instance_ctrl, const uint32_t port);
static void                 gmac_b_configure_operation(gmac_b_instance_ctrl_t * const p_instance_ctrl);
static void                 gmac_b_magic_packet_detection(gmac_b_instance_ctrl_t * const p_instance_ctrl);

static fsp_err_t gmac_b_link_status_check(gmac_b_instance_ctrl_t const * const p_instance_ctrl, uint32_t port);
static uint8_t   gmac_b_check_magic_packet_detection_bit(gmac_b_instance_ctrl_t const * const p_instance_ctrl);

static void gmac_b_call_callback(gmac_b_instance_ctrl_t * p_instance_ctrl, ether_callback_args_t * p_callback_args);

static void gmac_b_isr_dma_ch(gmac_b_instance_ctrl_t * p_instance_ctrl);
static void gmac_b_isr_mtl(gmac_b_instance_ctrl_t * p_instance_ctrl);
static void gmac_b_isr_pmt(gmac_b_instance_ctrl_t * p_instance_ctrl);
static void gmac_b_isr_mac(gmac_b_instance_ctrl_t * p_instance_ctrl);
void        gmac_b_isr_sbd(void);

#ifdef GMAC_B_IMPLEMENT_ETHSW
void gmac_b_callback_ethsw(ether_switch_callback_args_t * const p_arg);

#endif                                 // GMAC_B_IMPLEMENT_ETHSW

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/** Name of module used by error logger macro */
#if BSP_CFG_ERROR_LOG != 0
static const char g_module_name[] = "ether";
#endif

#if defined(__GNUC__)

/* This structure is affected by warnings from a GCC compiler bug. This pragma suppresses the warnings in this
 * structure only.*/

/*LDRA_INSPECTED 69 S */
 #pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

/** ETHER HAL API mapping for Ethernet Controller interface */
/*LDRA_INSPECTED 27 D This structure must be accessible in user code. It cannot be static. */
const ether_api_t g_ether_on_gmac_b =
{
    .open            = R_GMAC_B_Open,
    .close           = R_GMAC_B_Close,
    .read            = R_GMAC_B_Read,
    .bufferRelease   = R_GMAC_B_BufferRelease,
    .rxBufferUpdate  = R_GMAC_B_RxBufferUpdate,
    .write           = R_GMAC_B_Write,
    .linkProcess     = R_GMAC_B_LinkProcess,
    .wakeOnLANEnable = R_GMAC_B_WakeOnLANEnable,
    .txStatusGet     = R_GMAC_B_TxStatusGet,
    .callbackSet     = R_GMAC_B_CallbackSet,
};

/*
 * PAUSE Resolution as documented in IEEE 802.3-2008_section2 Annex
 * 28B, Table 28B-3. The following table codify logic that
 * determines how the PAUSE is configured for local transmitter
 * and receiver and partner transmitter and receiver.
 */
static const gmac_b_pause_resolution_t pause_resolution[GMAC_B_PAUSE_TABLE_ENTRIES] =
{
    {GMAC_B_PAUSE_MASKC, GMAC_B_PAUSE_VAL0, GMAC_B_PAUSE_XMIT_OFF, GMAC_B_PAUSE_RECV_OFF  },
    {GMAC_B_PAUSE_MASKE, GMAC_B_PAUSE_VAL4, GMAC_B_PAUSE_XMIT_OFF, GMAC_B_PAUSE_RECV_OFF  },
    {GMAC_B_PAUSE_MASKF, GMAC_B_PAUSE_VAL6, GMAC_B_PAUSE_XMIT_OFF, GMAC_B_PAUSE_RECV_OFF  },
    {GMAC_B_PAUSE_MASKF, GMAC_B_PAUSE_VAL7, GMAC_B_PAUSE_XMIT_ON,  GMAC_B_PAUSE_RECV_OFF  },
    {GMAC_B_PAUSE_MASKE, GMAC_B_PAUSE_VAL8, GMAC_B_PAUSE_XMIT_OFF, GMAC_B_PAUSE_RECV_OFF  },
    {GMAC_B_PAUSE_MASKA, GMAC_B_PAUSE_VALA, GMAC_B_PAUSE_XMIT_ON,  GMAC_B_PAUSE_RECV_ON   },
    {GMAC_B_PAUSE_MASKF, GMAC_B_PAUSE_VALC, GMAC_B_PAUSE_XMIT_OFF, GMAC_B_PAUSE_RECV_OFF  },
    {GMAC_B_PAUSE_MASKF, GMAC_B_PAUSE_VALD, GMAC_B_PAUSE_XMIT_OFF, GMAC_B_PAUSE_RECV_ON   }
};

static const gmac_b_port_mask_t g_gmac_port_mask[BSP_FEATURE_GMAC_MAX_PORTS] =
{
    GMAC_B_PORT_MASK_0
#if (1 < BSP_FEATURE_GMAC_MAX_PORTS)
    , GMAC_B_PORT_MASK_1
 #if (2 < BSP_FEATURE_GMAC_MAX_PORTS)
    , GMAC_B_PORT_MASK_2
  #if (3 < BSP_FEATURE_GMAC_MAX_PORTS)
    , GMAC_B_PORT_MASK_3
  #endif
 #endif
#endif
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZV
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZV_GMAC_B
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/********************************************************************************************************************//**
 * After ETHERC, EDMAC and PHY-LSI are reset in software, an auto negotiation of PHY-LSI is begun.
 * Afterwards, the link signal change interrupt is permitted. Implements @ref ether_api_t::open.
 *
 * @retval  FSP_SUCCESS                             Channel opened successfully.
 * @retval  FSP_ERR_ASSERTION                       Pointer to ETHER control block or configuration structure is NULL.
 * @retval  FSP_ERR_ALREADY_OPEN                    Control block has already been opened or channel is being used by another
 *                                                  instance. Call close() then open() to reconfigure.
 * @retval  FSP_ERR_ETHER_ERROR_PHY_COMMUNICATION   Initialization of PHY-LSI failed.
 * @retval  FSP_ERR_INVALID_CHANNEL                 Invalid channel number is given.
 * @retval  FSP_ERR_INVALID_POINTER                 Pointer to MAC address is NULL.
 * @retval  FSP_ERR_INVALID_ARGUMENT                Interrupt is not enabled.
 * @retval  FSP_ERR_ETHER_PHY_ERROR_LINK            Initialization of PHY-LSI failed.
 ***********************************************************************************************************************/
fsp_err_t R_GMAC_B_Open (ether_ctrl_t * const p_ctrl, ether_cfg_t const * const p_cfg)
{
#if (BSP_FEATURE_GMAC_HAS_PROTECTED_REGISTER)
    bsp_module_reset_t aclk[BSP_FEATURE_GMAC_MAX_CHANNELS] =
    {
        BSP_MODULE_RESET_GMAC0_PCLKH, BSP_MODULE_RESET_GMAC1_ACLK, BSP_MODULE_RESET_GMAC2_ACLK
    };
    bsp_module_reset_t hclk[BSP_FEATURE_GMAC_MAX_CHANNELS] =
    {
        BSP_MODULE_RESET_GMAC0_PCLKM, BSP_MODULE_RESET_GMAC1_HCLK, BSP_MODULE_RESET_GMAC2_HCLK
    };
#endif                                 /* BSP_FEATURE_GMAC_HAS_PROTECTED_REGISTER */
    volatile R_GBETH_Type  * p_reg_gmac;
    gmac_b_instance_ctrl_t * p_instance_ctrl = (gmac_b_instance_ctrl_t *) p_ctrl;
    gmac_b_extend_cfg_t    * p_extend;
    uint32_t                 index;

    fsp_err_t err = FSP_SUCCESS;

    /** Check parameters. */
    err = gmac_b_open_param_check(p_instance_ctrl, p_cfg); /** check arguments */
    GMAC_ERROR_RETURN((FSP_SUCCESS == err), err);

    /* Initialize the transmit and receive descriptor */
    p_extend = (gmac_b_extend_cfg_t *) p_cfg->p_extend;

    /** Make sure this channel exists. */
    p_reg_gmac = p_extend->p_reg_gmac;
    p_instance_ctrl->p_reg_gmac = (void *) p_reg_gmac;

    /* Initialize configuration of Ethernet module. */
    p_instance_ctrl->p_gmac_cfg = p_cfg;

    /* Initialize the flags */
    p_instance_ctrl->magic_packet = GMAC_B_MAGIC_PACKET_NOT_DETECTED;

    /* Clear Link status */
    p_instance_ctrl->link_status           = (gmac_b_port_mask_t) 0;
    p_instance_ctrl->previous_link_status  = (gmac_b_port_mask_t) 0;
    p_instance_ctrl->link_establish_status = (gmac_b_port_mask_t) 0;

    /* receive descriptor */
    p_instance_ctrl->rx_desc_pos = 0;

    memset(p_extend->p_rx_descriptors,
           0x00,
           sizeof(gmac_b_instance_descriptor_t) *
           p_instance_ctrl->p_gmac_cfg->num_rx_descriptors);

    /* transmit descriptor */
    p_instance_ctrl->tx_desc_pos = 0;

    memset(p_extend->p_tx_descriptors,
           0x00,
           sizeof(gmac_b_instance_descriptor_t) *
           p_instance_ctrl->p_gmac_cfg->num_tx_descriptors);

    /* Initialize the Ether buffer */
    for (index = 0;
         index < (p_instance_ctrl->p_gmac_cfg->num_tx_descriptors + p_instance_ctrl->p_gmac_cfg->num_rx_descriptors);
         index++)
    {
        memset(p_instance_ctrl->p_gmac_cfg->pp_ether_buffers[index],
               0x00,
               p_instance_ctrl->p_gmac_cfg->ether_buffer_size);
    }

    /* Set callback and context pointers, if configured */
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    /* Module start */
#if (BSP_FEATURE_GMAC_HAS_PROTECTED_REGISTER)
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_START(FSP_IP_GMAC, p_cfg->channel);
    R_BSP_ModuleResetDisable(aclk[p_cfg->channel]);
    R_BSP_ModuleResetDisable(hclk[p_cfg->channel]);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);
#else
    R_BSP_MODULE_START(FSP_IP_GBETH, p_cfg->channel);
#endif
#ifdef GMAC_B_IMPLEMENT_ETHSW

    /* Open Ether-Switch Driver */
    if (0 == p_cfg->channel)
    {
        err = gmac_b_open_ethsw(p_instance_ctrl);
    }
#endif                                 // GMAC_B_IMPLEMENT_ETHSW

    if (FSP_SUCCESS == err)
    {
        /* Open Ether-Phy Driver */
        err = gmac_b_open_phy(p_instance_ctrl);

        if (FSP_ERR_ETHER_PHY_ERROR_LINK == err)
        {
            err = FSP_ERR_ETHER_ERROR_PHY_COMMUNICATION;
        }
    }

    if (FSP_SUCCESS == err)
    {
        /* Software reset */
        gmac_b_reset_mac(p_instance_ctrl->p_reg_gmac);
        gmac_b_init_sysbus(p_instance_ctrl->p_reg_gmac);

        gmac_b_enable_icu(p_instance_ctrl);
        p_instance_ctrl->open = GMAC_B_OPEN;
    }

    return err;
}                                      /* End of function R_GMAC_B_Open() */

/********************************************************************************************************************//**
 * Disables interrupts. Removes power and releases hardware lock. Implements @ref ether_api_t::close.
 *
 * @retval  FSP_SUCCESS                                 Channel successfully closed.
 * @retval  FSP_ERR_ASSERTION                           Pointer to ETHER control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN                            The control block has not been opened
 *
 ***********************************************************************************************************************/
fsp_err_t R_GMAC_B_Close (ether_ctrl_t * const p_ctrl)
{
    fsp_err_t                err = FSP_SUCCESS;
    uint32_t                 i;
    gmac_b_instance_ctrl_t * p_instance_ctrl = (gmac_b_instance_ctrl_t *) p_ctrl;
    volatile R_GBETH_Type  * p_reg_gmac;
    gmac_b_extend_cfg_t    * p_extend;
    ether_phy_instance_t  ** pp_phy_instance;

#if (GMAC_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GMAC_ERROR_RETURN(GMAC_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Disable Ethernet interrupt. */
    gmac_b_disable_icu(p_instance_ctrl);

    p_reg_gmac      = (R_GBETH_Type *) p_instance_ctrl->p_reg_gmac;
    p_extend        = (gmac_b_extend_cfg_t *) p_instance_ctrl->p_gmac_cfg->p_extend;
    pp_phy_instance = (ether_phy_instance_t **) p_extend->pp_phy_instance;

    for (i = 0; BSP_FEATURE_GMAC_MAX_PORTS > i; i++)
    {
        if (NULL != pp_phy_instance[i])
        {
            pp_phy_instance[i]->p_api->close(pp_phy_instance[i]->p_ctrl);
        }
    }

#ifdef GMAC_B_IMPLEMENT_ETHSW
    if (0 == p_instance_ctrl->p_gmac_cfg->channel)
    {
        p_extend->p_ethsw_instance->p_api->close(p_extend->p_ethsw_instance->p_ctrl);
    }
#endif                                 // GMAC_B_IMPLEMENT_ETHSW

    p_reg_gmac->DMA_CH[0].DCIER = 0;

    /* Disable TE and RE  */
    p_reg_gmac->MACCR_b.RE = 0U;       /* Receiver Disable */
    p_reg_gmac->MACCR_b.TE = 0U;       /* Transmitter Disable */

    /* Initialize the flags */
    p_instance_ctrl->magic_packet = GMAC_B_MAGIC_PACKET_NOT_DETECTED;

    /* Clear Link status */
    p_instance_ctrl->link_status           = (gmac_b_port_mask_t) 0;
    p_instance_ctrl->previous_link_status  = (gmac_b_port_mask_t) 0;
    p_instance_ctrl->link_establish_status = (gmac_b_port_mask_t) 0;

    /** Clear configure block parameters. */
    p_instance_ctrl->p_gmac_cfg = NULL;

    /** Mark the channel not open so other APIs cannot use it. */
    p_instance_ctrl->open = 0U;

    return err;
}                                      /* End of function R_GMAC_B_Close() */

/********************************************************************************************************************//**
 * Move to the next buffer in the circular receive buffer list. Implements @ref ether_api_t::bufferRelease.
 *
 * @retval  FSP_SUCCESS                             Processing completed successfully.
 * @retval  FSP_ERR_ASSERTION                       Pointer to ETHER control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN                        The control block has not been opened
 * @retval  FSP_ERR_ETHER_ERROR_MAGIC_PACKET_MODE   As a Magic Packet is being detected, transmission and reception is
 *                                                  not enabled.
 * @retval  FSP_ERR_ETHER_ERROR_LINK                Link is down.
 ***********************************************************************************************************************/
fsp_err_t R_GMAC_B_BufferRelease (ether_ctrl_t * const p_ctrl)
{
    fsp_err_t                      err             = FSP_SUCCESS;
    gmac_b_instance_ctrl_t       * p_instance_ctrl = (gmac_b_instance_ctrl_t *) p_ctrl;
    volatile R_GBETH_Type        * p_reg_gmac;
    gmac_b_extend_cfg_t          * p_extend;
    gmac_b_instance_descriptor_t * p_rx_descriptor;
    uint32_t desc_tail_addr;

    /* Check argument */
#if (GMAC_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GMAC_ERROR_RETURN(GMAC_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* When the Link up processing is not completed, return error */
    GMAC_ERROR_RETURN(0 != p_instance_ctrl->previous_link_status, FSP_ERR_ETHER_ERROR_LINK);

    /* In case of detection mode of magic packet, return error. */
    GMAC_ERROR_RETURN(0 == gmac_b_check_magic_packet_detection_bit(p_instance_ctrl),
                      FSP_ERR_ETHER_ERROR_MAGIC_PACKET_MODE);

    p_reg_gmac = (R_GBETH_Type *) p_instance_ctrl->p_reg_gmac;
    p_extend   = (gmac_b_extend_cfg_t *) p_instance_ctrl->p_gmac_cfg->p_extend;

    p_rx_descriptor = &p_extend->p_rx_descriptors[p_instance_ctrl->rx_desc_pos];

    if (GMAC_B_RDES3_OWN != (p_rx_descriptor->des3 & GMAC_B_RDES3_OWN))
    {
#if (BSP_LP64_SUPPORT)
        uint64_t va =
            (uint64_t) (uintptr_t) p_instance_ctrl->p_gmac_cfg->pp_ether_buffers[p_instance_ctrl->p_gmac_cfg->
                                                                                 num_tx_descriptors +
                                                                                 p_instance_ctrl->rx_desc_pos];
        uint64_t pa;
        R_BSP_MmuVatoPa(va, &pa);
        p_rx_descriptor->des0 = (uint32_t) (uintptr_t) pa;
#else
        p_rx_descriptor->des0 =
            (uint32_t) (uintptr_t) p_instance_ctrl->p_gmac_cfg->pp_ether_buffers[p_instance_ctrl->p_gmac_cfg->
                                                                                 num_tx_descriptors +
                                                                                 p_instance_ctrl->rx_desc_pos];
#endif

        p_rx_descriptor->des3 = (GMAC_B_RDES3_OWN | GMAC_B_RDES3_IOC | GMAC_B_RDES3_BUF1V);

        p_instance_ctrl->rx_desc_pos++; /* next */
        if (p_instance_ctrl->p_gmac_cfg->num_rx_descriptors <= p_instance_ctrl->rx_desc_pos)
        {
            p_instance_ctrl->rx_desc_pos = 0;
        }
    }

    /* restart */
#if (BSP_LP64_SUPPORT)
    uint64_t va = (uint64_t) (uintptr_t) (p_extend->p_rx_descriptors + p_instance_ctrl->p_gmac_cfg->num_rx_descriptors);
    uint64_t pa;
    R_BSP_MmuVatoPa(va, &pa);
    desc_tail_addr = (uint32_t) pa;
#else
    desc_tail_addr =
        (uint32_t) (uintptr_t) (p_extend->p_rx_descriptors + p_instance_ctrl->p_gmac_cfg->num_rx_descriptors);
#endif

    p_reg_gmac->DMA_CH[0].DCRTPR = desc_tail_addr;

    err = FSP_SUCCESS;

    return err;
}                                      /* End of function R_GMAC_B_BufferRelease() */

/********************************************************************************************************************//**
 * Change the buffer pointer of the current rx buffer descriptor. Implements @ref ether_api_t::rxBufferUpdate.
 *
 * @retval  FSP_SUCCESS                             Processing completed successfully.
 * @retval  FSP_ERR_ASSERTION                       A pointer argument is NULL.
 * @retval  FSP_ERR_NOT_OPEN                        The control block has not been opened.
 * @retval  FSP_ERR_INVALID_POINTER                 The pointer of buffer is NULL or not aligned on a 32-bit boundary.
 * @retval  FSP_ERR_INVALID_MODE                    Driver is configured to non zero copy mode.
 * @retval  FSP_ERR_ETHER_RECEIVE_BUFFER_ACTIVE     All descriptor is active.
 ***********************************************************************************************************************/
fsp_err_t R_GMAC_B_RxBufferUpdate (ether_ctrl_t * const p_ctrl, void * const p_buffer)
{
    fsp_err_t                      err             = FSP_SUCCESS;
    gmac_b_instance_ctrl_t       * p_instance_ctrl = (gmac_b_instance_ctrl_t *) p_ctrl;
    volatile R_GBETH_Type        * p_reg_gmac;
    gmac_b_extend_cfg_t          * p_extend;
    gmac_b_instance_descriptor_t * p_rx_descriptor;
    uint32_t desc_tail_addr;

#if (GMAC_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GMAC_ERROR_RETURN(GMAC_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    GMAC_ERROR_RETURN(NULL != p_buffer, FSP_ERR_INVALID_POINTER);
    GMAC_ERROR_RETURN(ETHER_ZEROCOPY_ENABLE == p_instance_ctrl->p_gmac_cfg->zerocopy, FSP_ERR_INVALID_MODE);
#endif

    /* need to implement */
    p_reg_gmac = (R_GBETH_Type *) p_instance_ctrl->p_reg_gmac;
    p_extend   = (gmac_b_extend_cfg_t *) p_instance_ctrl->p_gmac_cfg->p_extend;

    p_rx_descriptor = &p_extend->p_rx_descriptors[p_instance_ctrl->rx_desc_pos];

    if (GMAC_B_RDES3_OWN != (p_rx_descriptor->des3 & GMAC_B_RDES3_OWN))
    {
        void * p_rx_buffer = p_buffer;

#if (BSP_LP64_SUPPORT)
        {
            uint64_t pa;
            R_BSP_MmuVatoPa((uint64_t) p_buffer, &pa);
            p_rx_buffer = (void *) pa;
        }
#endif

        /* TODO: The buffer address set in p_rx_descriptor->des0 writen back by DMA.
         *       Therefore, the buffer address needs to be saved, when ETHER_ZEROCOPY_ENABLE.
         */

        /* restart(ch0) */
        p_rx_descriptor->des0 = (uint32_t) (uintptr_t) p_rx_buffer;
        p_rx_descriptor->des3 = (GMAC_B_RDES3_OWN | GMAC_B_RDES3_IOC | GMAC_B_RDES3_BUF1V);

        p_instance_ctrl->rx_desc_pos++; /* next */
        if (p_instance_ctrl->p_gmac_cfg->num_rx_descriptors <= p_instance_ctrl->rx_desc_pos)
        {
            p_instance_ctrl->rx_desc_pos = 0;
        }

#if (BSP_LP64_SUPPORT)
        {
            uint64_t va =
                (uint64_t) (uintptr_t) (p_extend->p_rx_descriptors + p_instance_ctrl->p_gmac_cfg->num_rx_descriptors);
            uint64_t pa;
            R_BSP_MmuVatoPa(va, &pa);
            desc_tail_addr = (uint32_t) (uintptr_t) pa;
        }
#else
        desc_tail_addr =
            (uint32_t) (uintptr_t) (p_extend->p_rx_descriptors + p_instance_ctrl->p_gmac_cfg->num_rx_descriptors);
#endif

        p_reg_gmac->DMA_CH[0].DCRTPR = desc_tail_addr;
    }
    else
    {
        err = FSP_ERR_ETHER_RECEIVE_BUFFER_ACTIVE;
    }

    return err;
}                                      /* End of function R_GMAC_B_RxBufferUpdate() */

/********************************************************************************************************************//**
 * The Link up processing, the Link down processing, and the magic packet detection processing are executed.
 * Implements @ref ether_api_t::linkProcess.
 *
 * @retval  FSP_SUCCESS                             Processing completed successfully.
 * @retval  FSP_ERR_ASSERTION                       Pointer to ETHER control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN                        The control block has not been opened.
 * @retval  FSP_ERR_ETHER_ERROR_PHY_COMMUNICATION   When reopening the PHY interface initialization of the PHY-LSI failed.
 * @retval  FSP_ERR_ALREADY_OPEN                    When reopening the PHY interface it was already opened.
 * @retval  FSP_ERR_INVALID_CHANNEL                 When reopening the PHY interface an invalid channel was passed.
 * @retval  FSP_ERR_INVALID_POINTER                 When reopening the PHY interface the MAC address pointer was NULL.
 * @retval  FSP_ERR_INVALID_ARGUMENT                When reopening the PHY interface the interrupt was not enabled.
 * @retval  FSP_ERR_ETHER_PHY_ERROR_LINK            Initialization of the PHY-LSI failed.
 ***********************************************************************************************************************/
fsp_err_t R_GMAC_B_LinkProcess (ether_ctrl_t * const p_ctrl)
{
    fsp_err_t                err             = FSP_SUCCESS;
    gmac_b_instance_ctrl_t * p_instance_ctrl = (gmac_b_instance_ctrl_t *) p_ctrl;

    ether_cfg_t const     * p_gmac_cfg;
    gmac_b_port_mask_t      temp_previous_link_status;
    gmac_b_port_mask_t      previous_link_establish_status;
    ether_phy_instance_t ** pp_phy_instance;
    gmac_b_extend_cfg_t   * p_extend;
    void (* temp_p_callback)(ether_callback_args_t *);
    ether_callback_args_t * temp_p_callback_memory;
    void * temp_p_context;

    uint32_t i;

#if (GMAC_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GMAC_ERROR_RETURN(GMAC_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_gmac_cfg = p_instance_ctrl->p_gmac_cfg;

    /* When the magic packet is detected. */
    if (GMAC_B_MAGIC_PACKET_DETECTED == p_instance_ctrl->magic_packet)
    {
        p_instance_ctrl->magic_packet = GMAC_B_MAGIC_PACKET_NOT_DETECTED;

        gmac_b_call_user_callback(p_instance_ctrl, ETHER_EVENT_WAKEON_LAN, (gmac_b_port_mask_t) 0);

        /*
         * After the close function is called, the open function is called
         * to have to set ETHERC to a usual operational mode
         * to usually communicate after magic packet is detected.
         *//* back up previous_link_status */
        temp_previous_link_status = p_instance_ctrl->previous_link_status;

        /* back up callback and contex */
        temp_p_callback        = p_instance_ctrl->p_callback;
        temp_p_callback_memory = p_instance_ctrl->p_callback_memory;
        temp_p_context         = p_instance_ctrl->p_context;

        err = R_GMAC_B_Close((ether_ctrl_t *) p_instance_ctrl);
        GMAC_ERROR_RETURN(FSP_SUCCESS == err, err);

        err = R_GMAC_B_Open((ether_ctrl_t *) p_instance_ctrl, (ether_cfg_t *) p_gmac_cfg);
        GMAC_ERROR_RETURN(FSP_SUCCESS == err, err);

        /* restore previous_link_status */
        p_instance_ctrl->previous_link_status = temp_previous_link_status;

        /* restore callback and contex */
        p_instance_ctrl->p_callback        = temp_p_callback;
        p_instance_ctrl->p_callback_memory = temp_p_callback_memory;
        p_instance_ctrl->p_context         = temp_p_context;
    }

    previous_link_establish_status = p_instance_ctrl->link_establish_status;

    p_extend        = (gmac_b_extend_cfg_t *) p_gmac_cfg->p_extend;
    pp_phy_instance = (ether_phy_instance_t **) p_extend->pp_phy_instance;

    for (i = 0; BSP_FEATURE_GMAC_MAX_PORTS > i; i++)
    {
        if (NULL != pp_phy_instance[i])
        {
            /* Open Ether-Phy */
            (void) gmac_b_link_process(p_instance_ctrl, i);
        }
    }

    if (0 == previous_link_establish_status)
    {
        if (0 != p_instance_ctrl->link_establish_status)
        {
            /* Previous link status of all ports are down */
            /* Initialize the transmit and receive descriptor */

            /*
             * ETHERC and EDMAC are set after ETHERC and EDMAC are reset in software
             * and sending and receiving is permitted.
             */
            gmac_b_configure_mac(p_instance_ctrl, p_gmac_cfg->p_mac_address, GMAC_B_NO_USE_MAGIC_PACKET_DETECT);
            gmac_b_configure_operation(p_instance_ctrl);

            if (GMAC_B_MAGIC_PACKET_DETECTING == p_instance_ctrl->magic_packet)
            {
                R_GMAC_B_WakeOnLANEnable(p_ctrl);
            }
        }
    }
    else
    {
        if (0 == p_instance_ctrl->previous_link_status)
        {
            /* Software reset */
            gmac_b_reset_mac(p_instance_ctrl->p_reg_gmac);
            gmac_b_init_sysbus(p_instance_ctrl->p_reg_gmac);
        }
    }

    return err;
}                                      /* End of function R_GMAC_B_LinkProcess() */

/********************************************************************************************************************//**
 * Get link status of specificed port.
 *
 * @retval  FSP_SUCCESS                                 Processing completed successfully.
 * @retval  FSP_ERR_ASSERTION                           Pointer to ETHER control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN                            The control block has not been opened.
 * @retval  FSP_ERR_INVALID_POINTER                     Value of the pointer is NULL.
 * @retval  FSP_ERR_INVALID_ARGUMENT                    When reopening the PHY interface the interrupt was not enabled.
 ***********************************************************************************************************************/
fsp_err_t R_GMAC_B_GetLinkStatus (ether_ctrl_t * const p_ctrl, uint8_t port, gmac_b_link_status_t * p_status)
{
    gmac_b_port_mask_t port_status;
    fsp_err_t          err = FSP_SUCCESS;

    gmac_b_instance_ctrl_t * p_instance_ctrl = (gmac_b_instance_ctrl_t *) p_ctrl;

    /* Check argument */
#if (GMAC_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GMAC_ERROR_RETURN(GMAC_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    GMAC_ERROR_RETURN(NULL != p_status, FSP_ERR_INVALID_POINTER);
    GMAC_ERROR_RETURN(BSP_FEATURE_GMAC_MAX_PORTS > port, FSP_ERR_INVALID_ARGUMENT);

    GMAC_ERROR_RETURN(0 != ((gmac_b_extend_cfg_t *) p_instance_ctrl->p_gmac_cfg->p_extend)->pp_phy_instance[port],
                      FSP_ERR_INVALID_ARGUMENT);
#endif

    port_status = g_gmac_port_mask[port];

    if (port_status == (p_instance_ctrl->previous_link_status & port_status))
    {
        if (port_status == (p_instance_ctrl->link_establish_status & port_status))
        {
            *p_status = GMAC_LINK_STATUS_READY;
        }
        else
        {
            *p_status = GMAC_LINK_STATUS_UP;
        }
    }
    else
    {
        *p_status = GMAC_LINK_STATUS_DOWN;
    }

    return err;
}                                      /* End of function R_GMAC_B_GetLinkStatus() */

/********************************************************************************************************************//**
 * The setting of ETHERC is changed from normal sending and receiving mode to magic packet detection mode.
 * Implements @ref ether_api_t::wakeOnLANEnable.
 *
 * @retval  FSP_SUCCESS                                 Processing completed successfully.
 * @retval  FSP_ERR_ASSERTION                           Pointer to ETHER control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN                            The control block has not been opened.
 ***********************************************************************************************************************/
fsp_err_t R_GMAC_B_WakeOnLANEnable (ether_ctrl_t * const p_ctrl)
{
    fsp_err_t err = FSP_SUCCESS;

    gmac_b_instance_ctrl_t * p_instance_ctrl = (gmac_b_instance_ctrl_t *) p_ctrl;

    /* Check argument */
#if (GMAC_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GMAC_ERROR_RETURN(GMAC_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_instance_ctrl->magic_packet = GMAC_B_MAGIC_PACKET_DETECTING;

    /* When the Link up processing is completed */
    /* Change to the magic packet detection mode.  */
    gmac_b_configure_mac(p_instance_ctrl, p_instance_ctrl->p_gmac_cfg->p_mac_address, GMAC_B_USE_MAGIC_PACKET_DETECT);
    gmac_b_magic_packet_detection(p_instance_ctrl);

    return err;
}                                      /* End of function R_GMAC_B_WakeOnLANEnable() */

/********************************************************************************************************************//**
 * Receive Ethernet frame. Receives data to the location specified by the pointer to the receive buffer.
 * In zero copy mode, the address of the receive buffer is returned.
 * In non zero copy mode, the received data in the internal buffer is copied to the pointer passed by the argument.
 * Implements @ref ether_api_t::read.
 *
 * @retval  FSP_SUCCESS                                 Processing completed successfully.
 * @retval  FSP_ERR_ASSERTION                           Pointer to ETHER control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN                            The control block has not been opened.
 * @retval  FSP_ERR_ETHER_ERROR_NO_DATA                 There is no data in receive buffer.
 * @retval  FSP_ERR_ETHER_ERROR_LINK                    Auto-negotiation is not completed, and reception is not enabled.
 * @retval  FSP_ERR_ETHER_ERROR_MAGIC_PACKET_MODE       As a Magic Packet is being detected, transmission and reception
 *                                                      is not enabled.
 * @retval  FSP_ERR_INVALID_POINTER                     Value of the pointer is NULL.
 * @retval  FSP_ERR_INVALID_SIZE                        The buffer size is smaller than  @ref ether_cfg_t::ether_buffer_size.
 *
 ***********************************************************************************************************************/
fsp_err_t R_GMAC_B_Read (ether_ctrl_t * const p_ctrl, void * const p_buffer, uint32_t * const length_bytes)
{
    fsp_err_t                err             = FSP_SUCCESS;
    gmac_b_instance_ctrl_t * p_instance_ctrl = (gmac_b_instance_ctrl_t *) p_ctrl;
    uint8_t                * p_read_buffer   = NULL; /* Buffer location controlled by the Ethernet driver */
    uint32_t                 received_size   = GMAC_B_NO_DATA;
    uint8_t               ** pp_read_buffer  = (uint8_t **) p_buffer;

    gmac_b_instance_descriptor_t * p_rx_descriptor;
    gmac_b_extend_cfg_t          * p_extend;

    /* Check argument */
    err = gmac_b_read_param_check(p_instance_ctrl, p_buffer, length_bytes);

    p_extend = (gmac_b_extend_cfg_t *) p_instance_ctrl->p_gmac_cfg->p_extend;

    while (FSP_SUCCESS == err)
    {
        p_rx_descriptor = &p_extend->p_rx_descriptors[p_instance_ctrl->rx_desc_pos];

        /* When receive data exists. */
        if (GMAC_B_RDES3_OWN != (p_rx_descriptor->des3 & GMAC_B_RDES3_OWN))
        {
            if ((GMAC_B_RDES3_FD | GMAC_B_RDES3_LD) != (p_rx_descriptor->des3 & (GMAC_B_RDES3_FD | GMAC_B_RDES3_LD)))
            {
                /* The buffer is released when it is at the error or when single-frame is not in single descriptor. */
                err = R_GMAC_B_BufferRelease((ether_ctrl_t *) p_instance_ctrl);
                continue;
            }

            if (GMAC_B_RDES3_ES == (p_rx_descriptor->des3 & GMAC_B_RDES3_ES))
            {
                /* Error Summary */
                err = R_GMAC_B_BufferRelease((ether_ctrl_t *) p_instance_ctrl);
                continue;
            }

            p_read_buffer =
                p_instance_ctrl->p_gmac_cfg->pp_ether_buffers[p_instance_ctrl->p_gmac_cfg->num_tx_descriptors +
                                                              p_instance_ctrl->rx_desc_pos];
            received_size = (p_rx_descriptor->des3 & GMAC_B_RDES3_PL_MASK) >> GMAC_B_RDES3_PL_SHIFT;

            if (GMAC_B_MINIMUM_FRAME_SIZE > received_size)
            {
                /* bytes received is short */
                err = R_GMAC_B_BufferRelease((ether_ctrl_t *) p_instance_ctrl);
                continue;
            }
        }
        else
        {
            err = FSP_ERR_ETHER_ERROR_NO_DATA;
        }

        break;
    }

    if (FSP_SUCCESS == err)
    {
        /* When there is data to receive */
        if (received_size > GMAC_B_NO_DATA)
        {
            if (ETHER_ZEROCOPY_DISABLE == p_instance_ctrl->p_gmac_cfg->zerocopy)
            {
                /* (2) Copy the data read from the receive buffer which is controlled
                 *     by the descriptor to the buffer which is specified by the user (up to 1024 bytes). */
                memcpy(p_buffer, p_read_buffer, received_size);

                /* (3) Read the receive data from the receive buffer controlled by the descriptor,
                 * and then release the receive buffer. */
                err = R_GMAC_B_BufferRelease((ether_ctrl_t *) p_instance_ctrl);
            }
            else
            {
                *pp_read_buffer = p_read_buffer;
            }

            *length_bytes = received_size;
        }
        /* When there is no data to receive */
        else
        {
            err = FSP_ERR_ETHER_ERROR_NO_DATA;
        }
    }

    return err;
}                                      /* End of function R_GMAC_B_Read() */

/********************************************************************************************************************//**
 * Transmit Ethernet frame. Transmits data from the location specified by the pointer to the transmit
 *  buffer, with the data size equal to the specified frame length.
 *  In the non zero copy mode, transmits data after being copied to the internal buffer.
 *  Implements @ref ether_api_t::write.
 *
 * @retval  FSP_SUCCESS                                Processing completed successfully.
 * @retval  FSP_ERR_ASSERTION                          Pointer to ETHER control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN                           The control block has not been opened.
 * @retval  FSP_ERR_ETHER_ERROR_LINK                    Auto-negotiation is not completed, and reception is not enabled.
 * @retval  FSP_ERR_ETHER_ERROR_MAGIC_PACKET_MODE       As a Magic Packet is being detected, transmission and reception
 *                                                     is not enabled.
 * @retval  FSP_ERR_ETHER_ERROR_TRANSMIT_BUFFER_FULL    Transmit buffer is not empty.
 * @retval  FSP_ERR_INVALID_POINTER                    Value of the pointer is NULL.
 * @retval  FSP_ERR_INVALID_ARGUMENT                   Value of the send frame size is out of range.
 *
 ***********************************************************************************************************************/
fsp_err_t R_GMAC_B_Write (ether_ctrl_t * const p_ctrl, void * const p_buffer, uint32_t const frame_length)
{
    fsp_err_t                      err             = FSP_SUCCESS;
    gmac_b_instance_ctrl_t       * p_instance_ctrl = (gmac_b_instance_ctrl_t *) p_ctrl;
    gmac_b_instance_descriptor_t * p_tx_descriptor;
    volatile R_GBETH_Type        * p_reg_gmac;
    gmac_b_extend_cfg_t          * p_extend;
    uint32_t desc_tail_addr;

    /* Check argument */
    err = gmac_b_write_param_check(p_instance_ctrl, p_buffer, frame_length);
    GMAC_ERROR_RETURN((FSP_SUCCESS == err), err);

    /* When the Link up processing is completed */
    p_reg_gmac = (R_GBETH_Type *) p_instance_ctrl->p_reg_gmac;
    p_extend   = (gmac_b_extend_cfg_t *) p_instance_ctrl->p_gmac_cfg->p_extend;

    p_tx_descriptor = &p_extend->p_tx_descriptors[p_instance_ctrl->tx_desc_pos];

    /* check transmit descriptor */
    if (GMAC_B_TDES3_OWN == (p_tx_descriptor->des3 & GMAC_B_TDES3_OWN))
    {
        /* All transmit descriptors are full */
        err = FSP_ERR_ETHER_ERROR_TRANSMIT_BUFFER_FULL;
    }

    /* set frame data */
    if (FSP_SUCCESS == err)
    {
        if (ETHER_ZEROCOPY_DISABLE == p_instance_ctrl->p_gmac_cfg->zerocopy)
        {
            if (p_instance_ctrl->p_gmac_cfg->ether_buffer_size < frame_length)
            {
                err = FSP_ERR_ETHER_ERROR_TRANSMIT_BUFFER_FULL; /* Transmit buffer overflow */
            }
            else
            {
                /* Write the transmit data to the transmit buffer. */
#if (BSP_LP64_SUPPORT)
                {
                    uint64_t va =
                        (uint64_t) (uintptr_t) p_instance_ctrl->p_gmac_cfg->pp_ether_buffers[p_instance_ctrl->
                                                                                             tx_desc_pos];
                    uint64_t pa;
                    R_BSP_MmuVatoPa(va, &pa);
                    p_tx_descriptor->des0 = (uint32_t) (uintptr_t) pa;

                    /* (2) Write the data to the transmit buffer controlled by the  descriptor. */
                    memcpy((void *) (uintptr_t) va, p_buffer, frame_length);
                }
#else
                p_tx_descriptor->des0 =
                    (uint32_t) (uintptr_t) p_instance_ctrl->p_gmac_cfg->pp_ether_buffers[p_instance_ctrl->tx_desc_pos];

                /* (2) Write the data to the transmit buffer controlled by the  descriptor. */
                memcpy((void *) (uintptr_t) p_tx_descriptor->des0, p_buffer, frame_length);
#endif
            }
        }
        else
        {
            /* (ETHER_ZEROCOPY_ENABLE == p_instance_ctrl->p_gmac_cfg->zerocopy) */

#if (BSP_LP64_SUPPORT)
            {
                uint64_t va = (uint64_t) (uintptr_t) p_buffer;
                uint64_t pa;
                R_BSP_MmuVatoPa(va, &pa);
                p_tx_descriptor->des0 = (uint32_t) (uintptr_t) pa;   // Set Buffer 1 Address of TDES
            }
#else
            p_tx_descriptor->des0 = (uint32_t) (uintptr_t) p_buffer; // Set Buffer 1 Address of TDES
#endif

            /* TODO: The buffer address set in p_tx_descriptor->des0 writen back by DMA.
             *       Therefore, the buffer address needs to be saved, when ETHER_ZEROCOPY_ENABLE.
             */
        }
    }

    /* Writing to the transmit buffer (buf) is enabled. */
    if (FSP_SUCCESS == err)
    {
        /* (3) Enable the EDMAC to transmit data in the transmit buffer. */
        /* When the Link up processing is not completed, return error */
        p_tx_descriptor->des2 = (uint32_t) (GMAC_B_TDES2_IOC | GMAC_B_TDES2_B1L(frame_length));
        p_tx_descriptor->des3 = (GMAC_B_TDES3_OWN | GMAC_B_TDES3_FD | GMAC_B_TDES3_LD);

        p_instance_ctrl->tx_desc_pos++;       /* next */
        if (p_instance_ctrl->p_gmac_cfg->num_tx_descriptors <= p_instance_ctrl->tx_desc_pos)
        {
            p_instance_ctrl->tx_desc_pos = 0; /* round */
        }

#if (BSP_LP64_SUPPORT)
        {
            uint64_t va =
                (uint64_t) (uintptr_t) (p_extend->p_tx_descriptors + p_instance_ctrl->p_gmac_cfg->num_tx_descriptors);
            uint64_t pa;
            R_BSP_MmuVatoPa(va, &pa);
            desc_tail_addr = (uint32_t) (uintptr_t) pa;
        }
#else
        desc_tail_addr =
            (uint32_t) (uintptr_t) (p_extend->p_tx_descriptors + p_instance_ctrl->p_gmac_cfg->num_tx_descriptors);
#endif

        /* restart */
#if defined(RENESAS_CORTEX_A55)
        __ASM volatile ("dmb 0xF" ::: "memory");
#else
        __ASM volatile ("dmb");
#endif
        p_reg_gmac->DMA_CH[0].DCTTPR = desc_tail_addr;
    }

    return err;
}                                      /* End of function R_GMAC_B_Write() */

/**********************************************************************************************************************//**
 * Provides status of Ethernet driver in the user provided pointer. Implements @ref ether_api_t::txStatusGet.
 *
 * @retval  FSP_SUCCESS                  Transmit buffer address is stored in provided p_buffer_address.
 * @retval  FSP_ERR_ASSERTION            Pointer to ETHER control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_INVALID_POINTER      p_status is NULL.
 * @retval  FSP_ERR_NOT_FOUND            Transmit buffer address has been overwritten in transmit descriptor.
 ***********************************************************************************************************************/
fsp_err_t R_GMAC_B_TxStatusGet (ether_ctrl_t * const p_ctrl, void * const p_buffer_address)
{
    gmac_b_instance_ctrl_t       * p_instance_ctrl       = (gmac_b_instance_ctrl_t *) p_ctrl;
    uint8_t                     ** p_sent_buffer_address = (uint8_t **) p_buffer_address;
    volatile R_GBETH_Type        * p_reg_gmac;
    ether_cfg_t                  * p_gmac_cfg;
    gmac_b_extend_cfg_t          * p_extend;
    gmac_b_instance_descriptor_t * p_tx_descriptor;
    uint32_t  current;
    uint32_t  pos;
    fsp_err_t err = FSP_ERR_NOT_FOUND;

#if (GMAC_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GMAC_ERROR_RETURN(GMAC_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    GMAC_ERROR_RETURN(NULL != p_buffer_address, FSP_ERR_INVALID_POINTER);
#endif
    p_reg_gmac = (R_GBETH_Type *) p_instance_ctrl->p_reg_gmac;
    p_gmac_cfg = (ether_cfg_t *) p_instance_ctrl->p_gmac_cfg;
    p_extend   = (gmac_b_extend_cfg_t *) p_gmac_cfg->p_extend;

    current = p_reg_gmac->DMA_CH[0].DCCATDR_b.CURTDESAPTR;

#if (BSP_LP64_SUPPORT)
    uint64_t va;
    R_BSP_MmuPatoVa((uint64_t) current, &va, BSP_MMU_CONVERSION_NON_CACHE);
#endif

    if (current != 0)
    {
#if (BSP_LP64_SUPPORT)
        pos = (uint32_t) (va - (uint64_t) (uintptr_t) p_extend->p_tx_descriptors) /
              sizeof(gmac_b_instance_descriptor_t);
#else
        pos = (current - (uint32_t) (uintptr_t) p_extend->p_tx_descriptors) / sizeof(gmac_b_instance_descriptor_t);
#endif

        if (pos == 0)
        {
            pos = (uint32_t) (p_gmac_cfg->num_tx_descriptors - 1);
        }
        else
        {
            pos--;
        }

        p_tx_descriptor = &p_extend->p_tx_descriptors[pos];

        if (!(p_tx_descriptor->des3 & GMAC_B_TDES3_OWN) &&
            (p_tx_descriptor->des3 & GMAC_B_TDES3_FD))
        {
            /* TODO: It not be correct to obtain the send buffer address from pp_ether_buffers,
             *       when ETHER_ZEROCOPY_ENABLE.
             */

            *p_sent_buffer_address = p_gmac_cfg->pp_ether_buffers[pos];

            err = FSP_SUCCESS;
        }
    }

    return err;
}                                      /* End of function R_GMAC_B_TxStatusGet() */

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 * Implements @ref ether_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_GMAC_B_CallbackSet (ether_ctrl_t * const          p_ctrl,
                                void (                      * p_callback)(ether_callback_args_t *),
                                void * const                  p_context,
                                ether_callback_args_t * const p_callback_memory)
{
    gmac_b_instance_ctrl_t * p_instance_ctrl = (gmac_b_instance_ctrl_t *) p_ctrl;

#if (GMAC_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(GMAC_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */
    p_instance_ctrl->p_callback        = p_callback;
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}                                      /* End of function R_GMAC_B_CallbackSet() */

/*******************************************************************************************************************//**
 * @} (end addtogroup RZV_GMAC_B)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Parameter error check function for open.
 *
 * @param[in] p_instance_ctrl   Pointer to the control block for the channel
 * @param[in] p_cfg             Pointer to the configuration structure specific to UART mode
 *
 * @retval  FSP_SUCCESS                  No parameter error found
 * @retval  FSP_ERR_ASSERTION            Pointer to ETHER control block or configuration structure is NULL
 * @retval  FSP_ERR_ALREADY_OPEN         Control block has already been opened
 * @retval  FSP_ERR_INVALID_CHANNEL      Invalid channel number is given.
 * @retval  FSP_ERR_INVALID_POINTER      Pointer to MAC address is NULL.
 * @retval  FSP_ERR_INVALID_ARGUMENT      Irq number lower then 0.
 **********************************************************************************************************************/
static fsp_err_t gmac_b_open_param_check (gmac_b_instance_ctrl_t const * const p_instance_ctrl,
                                          ether_cfg_t const * const            p_cfg)
{
#if (GMAC_B_CFG_PARAM_CHECKING_ENABLE)
    gmac_b_extend_cfg_t * p_extend;

    FSP_ASSERT(p_instance_ctrl);
    GMAC_ERROR_RETURN((NULL != p_cfg), FSP_ERR_INVALID_POINTER);
    GMAC_ERROR_RETURN((NULL != p_cfg->p_mac_address), FSP_ERR_INVALID_POINTER);
    GMAC_ERROR_RETURN((BSP_FEATURE_GMAC_MAX_CHANNELS > p_cfg->channel), FSP_ERR_INVALID_CHANNEL);

    GMAC_ERROR_RETURN((0 <= p_cfg->irq), FSP_ERR_INVALID_ARGUMENT);
    GMAC_ERROR_RETURN((NULL != p_cfg->p_extend), FSP_ERR_INVALID_POINTER);
    GMAC_ERROR_RETURN((NULL != p_cfg->pp_ether_buffers), FSP_ERR_INVALID_POINTER);

    p_extend = (gmac_b_extend_cfg_t *) p_cfg->p_extend;

    GMAC_ERROR_RETURN((NULL != p_extend->p_rx_descriptors), FSP_ERR_INVALID_POINTER);
    GMAC_ERROR_RETURN((NULL != p_extend->p_tx_descriptors), FSP_ERR_INVALID_POINTER);

    GMAC_ERROR_RETURN((NULL != p_extend->p_reg_gmac), FSP_ERR_INVALID_POINTER);

    GMAC_ERROR_RETURN((GMAC_B_OPEN != p_instance_ctrl->open), FSP_ERR_ALREADY_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
    FSP_PARAMETER_NOT_USED(p_cfg);
#endif

    return FSP_SUCCESS;
}                                      /* End of function gmac_b_open_param_check() */

/*******************************************************************************************************************//**
 * Parameter error check function for read.
 *
 * @param[in] p_instance_ctrl   Pointer to the control block for the channel
 * @param[in] p_buffer          Pointer to where to store read data.
 * @param[in] length_bytes      Number of bytes in buffer
 *
 * @retval  FSP_SUCCESS                                 Processing completed successfully.
 * @retval  FSP_ERR_ASSERTION                           Pointer to ETHER control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN                            The control block has not been opened.
 * @retval  FSP_ERR_ETHER_ERROR_LINK                     Auto-negotiation is not completed, and reception is not enabled.
 * @retval  FSP_ERR_ETHER_ERROR_MAGIC_PACKET_MODE        As a Magic Packet is being detected, transmission and reception
 *                                                      is not enabled.
 * @retval  FSP_ERR_INVALID_POINTER                     Value of the pointer is NULL.
 * @retval  FSP_ERR_INVALID_SIZE                        The buffer size is smaller than  @ref RZV::ether_cfg_t::ether_buffer_size.
 **********************************************************************************************************************/
static fsp_err_t gmac_b_read_param_check (gmac_b_instance_ctrl_t * p_instance_ctrl,
                                          void * const             p_buffer,
                                          uint32_t * const         length_bytes)
{
    /* Check argument */
#if (GMAC_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GMAC_ERROR_RETURN(GMAC_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    GMAC_ERROR_RETURN(NULL != p_buffer, FSP_ERR_INVALID_POINTER);
    GMAC_ERROR_RETURN(NULL != length_bytes, FSP_ERR_INVALID_POINTER);
 #if (GMAC_B_CFG_READ_BUFFER_SIZE_CHECK)
    GMAC_ERROR_RETURN(p_instance_ctrl->p_gmac_cfg->ether_buffer_size <= *length_bytes, FSP_ERR_INVALID_SIZE);
 #endif
#else
    FSP_PARAMETER_NOT_USED(p_buffer);
    FSP_PARAMETER_NOT_USED(length_bytes);
#endif

    /* (1) Retrieve the receive buffer location controlled by the  descriptor. */
    /* When the Link up processing is not completed, return error */
    GMAC_ERROR_RETURN(0 != p_instance_ctrl->link_establish_status, FSP_ERR_ETHER_ERROR_LINK);

    /* In case of detection mode of magic packet, return error. */
    GMAC_ERROR_RETURN(0 == gmac_b_check_magic_packet_detection_bit(p_instance_ctrl),
                      FSP_ERR_ETHER_ERROR_MAGIC_PACKET_MODE);

    return FSP_SUCCESS;
}                                      /* End of function gmac_b_read_param_check() */

/*******************************************************************************************************************//**
 * Parameter error check function for write.
 *
 * @param[in]  p_instance_ctrl  Pointer to the control block for the channel.
 * @param[in]  p_buffer         Pointer to data to write.
 * @param[in]  frame_length     Send ethernet frame size (without 4 bytes of CRC data size).
 *
 * @retval  FSP_SUCCESS                                Processing completed successfully.
 * @retval  FSP_ERR_ASSERTION                          Pointer to ETHER control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN                           The control block has not been opened.
 * @retval  FSP_ERR_ETHER_ERROR_LINK                    Auto-negotiation is not completed, and reception is not enabled.
 * @retval  FSP_ERR_ETHER_ERROR_MAGIC_PACKET_MODE       As a Magic Packet is being detected, transmission and reception
 *                                                     is not enabled.
 * @retval  FSP_ERR_INVALID_POINTER                    Value of the pointer is NULL.
 * @retval  FSP_ERR_INVALID_ARGUMENT                   Value of the send frame size is out of range.
 **********************************************************************************************************************/
static fsp_err_t gmac_b_write_param_check (gmac_b_instance_ctrl_t * p_instance_ctrl,
                                           void * const             p_buffer,
                                           uint32_t const           frame_length)
{
#if (GMAC_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GMAC_ERROR_RETURN(GMAC_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    GMAC_ERROR_RETURN(NULL != p_buffer, FSP_ERR_INVALID_POINTER);
    GMAC_ERROR_RETURN(p_instance_ctrl->p_gmac_cfg->ether_buffer_size >= frame_length, FSP_ERR_INVALID_ARGUMENT);
#else
    FSP_PARAMETER_NOT_USED(p_buffer);
    FSP_PARAMETER_NOT_USED(frame_length);
#endif

    /* When the Link up processing is not completed, return error */
    GMAC_ERROR_RETURN(0 != p_instance_ctrl->link_establish_status, FSP_ERR_ETHER_ERROR_LINK);

    /* In case of detection mode of magic packet, return error. */
    GMAC_ERROR_RETURN(0 == gmac_b_check_magic_packet_detection_bit(p_instance_ctrl),
                      FSP_ERR_ETHER_ERROR_MAGIC_PACKET_MODE);

    return FSP_SUCCESS;
}                                      /* End of function gmac_b_write_param_check() */

/*******************************************************************************************************************//**
 * Reset The GMAC are reset through the software reset.
 *
 * @param[out]  p_reg       Base address of regeister for GMAC
 *
 * @retval  none
 **********************************************************************************************************************/
static void gmac_b_reset_mac (volatile R_GBETH_Type * const p_reg)
{
    /* reset DMA */
    p_reg->DMR_b.SWR = 1;

    while (1 == p_reg->DMR_b.SWR)
    {
        ;
    }
}                                      /* End of function gmac_b_reset_mac() */

/*******************************************************************************************************************//**
 *
 *
 * @param[out]  p_reg       Base address of regeister for GMAC
 *
 * @retval  none
 **********************************************************************************************************************/
static void gmac_b_init_sysbus (volatile R_GBETH_Type * const p_reg)
{
    /* initialize sysbus */
    p_reg->DSMR_b.FB         = 1;
    p_reg->DSMR_b.AAL        = 1;
    p_reg->DSMR_b.BLEN4      = 1;
    p_reg->DSMR_b.BLEN8      = 1;
    p_reg->DSMR_b.BLEN16     = 1;
    p_reg->DSMR_b.RD_OSR_LMT = 3;
    p_reg->DSMR_b.WR_OSR_LMT = 3;

    p_reg->DMR_b.INTM = 2;
}                                      /* End of function gmac_b_init_sysbus() */

#ifdef GMAC_B_IMPLEMENT_ETHSW

/*******************************************************************************************************************//**
 * Open ether switch driver.
 *
 * @param[in]   p_instance_ctrl     Pointer to the control block for the channel
 *
 * @retval  FSP_SUCCESS                 Channel opened successfully.
 **********************************************************************************************************************/
fsp_err_t gmac_b_open_ethsw (gmac_b_instance_ctrl_t * p_instance_ctrl)
{
    ether_switch_instance_t const * p_ethsw_instance; ///< Pointer to ETHER_SWITCH instance
    fsp_err_t err;

    p_ethsw_instance = ((gmac_b_extend_cfg_t *) p_instance_ctrl->p_gmac_cfg->p_extend)->p_ethsw_instance;

    err = FSP_SUCCESS;

    if (NULL != p_ethsw_instance)
    {
        err = p_ethsw_instance->p_api->open(p_ethsw_instance->p_ctrl, p_ethsw_instance->p_cfg);
        if (FSP_SUCCESS != err)
        {
            p_ethsw_instance->p_api->close(p_ethsw_instance->p_ctrl);
        }
    }

    return err;
}                                      /* End of function gmac_b_open_ethsw() */

#endif // GMAC_B_IMPLEMENT_ETHSW

/*******************************************************************************************************************//**
 * Open ether phy driver.
 *
 * @param[in]   p_instance_ctrl     Pointer to the control block for the channel
 *
 * @retval  FSP_SUCCESS                             Channel opened successfully.
 **********************************************************************************************************************/
fsp_err_t gmac_b_open_phy (gmac_b_instance_ctrl_t * p_instance_ctrl)
{
    ether_phy_instance_t const *(*pp_phy_instance)[BSP_FEATURE_GMAC_MAX_PORTS];
    ether_phy_instance_t const * p_phy_instance;

    fsp_err_t err = FSP_SUCCESS;
    uint32_t  i;

    pp_phy_instance = ((gmac_b_extend_cfg_t *) p_instance_ctrl->p_gmac_cfg->p_extend)->pp_phy_instance;

    for (i = 0; BSP_FEATURE_GMAC_MAX_PORTS > i; i++)
    {
        p_phy_instance = (*pp_phy_instance)[i];

        if (NULL != p_phy_instance)
        {
            /* Open Ether-Phy */
            ether_phy_instance_ctrl_t * p_phy_instance_ctrl = (ether_phy_instance_ctrl_t *) p_phy_instance->p_ctrl;
            p_phy_instance_ctrl->p_reg_etherc = (uint32_t *) p_instance_ctrl->p_reg_gmac;
            err = p_phy_instance->p_api->open(p_phy_instance->p_ctrl, p_phy_instance->p_cfg);
            if (FSP_SUCCESS == err)
            {
                /* Start Auto-Negotiate */
                p_phy_instance->p_api->startAutoNegotiate(p_phy_instance->p_ctrl);
            }
            else
            {
                break;
            }
        }
    }

    if (FSP_SUCCESS != err)
    {
        for (i = 0; BSP_FEATURE_GMAC_MAX_PORTS > i; i++)
        {
            p_phy_instance = (*pp_phy_instance)[i];

            if (NULL != p_phy_instance)
            {
                p_phy_instance->p_api->close(p_phy_instance->p_ctrl);
            }
        }
    }

    return err;
}                                      /* End of function gmac_b_open_phy() */

/*******************************************************************************************************************//**
 * The DMAC descriptors and the driver buffers are initialized.
 *
 * @param[in]   p_instance_ctrl     Pointer to the control block for the channel
 *
 * @retval  none
 **********************************************************************************************************************/
static void gmac_b_init_descriptors (gmac_b_instance_ctrl_t * const p_instance_ctrl)
{
    ether_cfg_t                  * p_gmac_cfg;
    gmac_b_extend_cfg_t          * p_extend;
    gmac_b_instance_descriptor_t * p_rx_descriptor;
    int index;

    p_gmac_cfg = (ether_cfg_t *) p_instance_ctrl->p_gmac_cfg;
    p_extend   = (gmac_b_extend_cfg_t *) p_gmac_cfg->p_extend;

    /* initialize tx descriptors */
    memset(p_extend->p_tx_descriptors, 0x00, sizeof(gmac_b_instance_descriptor_t) * p_gmac_cfg->num_tx_descriptors);

    /* initialize rx descriptors */
    for (index = 0;
         index < p_gmac_cfg->num_rx_descriptors;
         index++)
    {
        p_rx_descriptor = &p_extend->p_rx_descriptors[index];

#if (BSP_LP64_SUPPORT)
        uint64_t va = (uint64_t) (uintptr_t) p_gmac_cfg->pp_ether_buffers[p_gmac_cfg->num_tx_descriptors + index];
        uint64_t pa;
        R_BSP_MmuVatoPa(va, &pa);
        p_rx_descriptor->des0 = (uint32_t) pa;
#else
        p_rx_descriptor->des0 =
            (uint32_t) (uintptr_t) p_gmac_cfg->pp_ether_buffers[p_gmac_cfg->num_tx_descriptors + index];
#endif

        p_rx_descriptor->des1 = 0;
        p_rx_descriptor->des2 = 0;
        p_rx_descriptor->des3 = (GMAC_B_RDES3_OWN | GMAC_B_RDES3_IOC | GMAC_B_RDES3_BUF1V);
    }

    /* initialize descriptor position */
    p_instance_ctrl->tx_desc_pos = 0;  ///< tx descriptor position
    p_instance_ctrl->rx_desc_pos = 0;  ///< rx descriptor position
}                                      /* End of function gmac_b_init_descriptors() */

/********************************************************************************************************************//**
 * Configure the GMAC
 *
 * @param[in]   p_instance_ctrl         Ethernet driver control block.
 * @param[in]   mode                    The operational mode is specified.
 *                                      NO_USE_MAGIC_PACKET_DETECT (0) - Communicate mode usually
 *                                      USE_MAGIC_PACKET_DETECT    (1) - Magic packet detection mode
 *
 * @retval      none
 ***********************************************************************************************************************/
static void gmac_config_ethernet (gmac_b_instance_ctrl_t const * const p_instance_ctrl, const uint8_t mode)
{
    volatile R_GBETH_Type * const p_reg = p_instance_ctrl->p_reg_gmac;
    ether_cfg_t                 * p_gmac_cfg;
    gmac_b_extend_cfg_t         * p_extend;

    p_gmac_cfg = (ether_cfg_t *) p_instance_ctrl->p_gmac_cfg;
    p_extend   = (gmac_b_extend_cfg_t *) p_gmac_cfg->p_extend;

    p_reg->MACPFR_b.PR = p_gmac_cfg->promiscuous; /* Promiscuous Mode */

    /* tx descriptor */
    p_reg->DMA_CH[0].DCTRLR =
        ((uint32_t) (p_gmac_cfg->num_tx_descriptors - 1) << R_GBETH0_DCTRLR0_TDRL_Pos) &
        R_GBETH0_DCTRLR0_TDRL_Msk;     /* count */

#if (BSP_LP64_SUPPORT)
    {
        uint64_t va;
        uint64_t pa;

        va = (uint64_t) (uintptr_t) p_extend->p_tx_descriptors;
        R_BSP_MmuVatoPa(va, &pa);
        p_reg->DMA_CH[0].DCTLAR = (uint32_t) (uintptr_t) pa; /* top */

        va = (uint64_t) (uintptr_t) (p_extend->p_tx_descriptors + p_gmac_cfg->num_tx_descriptors);
        R_BSP_MmuVatoPa(va, &pa);
        p_reg->DMA_CH[0].DCTTPR = (uint32_t) (uintptr_t) pa; /* end */
    }
#else
    {
        uint32_t desc_tail_addr = (uint32_t) (uintptr_t) (p_extend->p_tx_descriptors + p_gmac_cfg->num_tx_descriptors);

        p_reg->DMA_CH[0].DCTLAR = (uint32_t) (uintptr_t) p_extend->p_tx_descriptors; /* top */
        p_reg->DMA_CH[0].DCTTPR = desc_tail_addr;                                    /* end */
    }
#endif

    p_reg->DMA_CH[0].DCTCR_b.ST = 1;

    p_reg->MTL_Q[0].MTLTOMR_b.TSF   = 1;
    p_reg->MTL_Q[0].MTLTOMR_b.TXQEN = 2;

    /* rx descriptor */
    p_reg->DMA_CH[0].DCRC2R =
        ((uint32_t) (p_gmac_cfg->num_rx_descriptors - 1) << R_GBETH0_DCRC2R0_RDRL_Pos) &
        R_GBETH0_DCRC2R0_RDRL_Msk;     /* count */

#if (BSP_LP64_SUPPORT)
    {
        uint64_t va;
        uint64_t pa;

        va = (uint64_t) (uintptr_t) p_extend->p_rx_descriptors;
        R_BSP_MmuVatoPa(va, &pa);
        p_reg->DMA_CH[0].DCRLAR = (uint32_t) (uintptr_t) pa; /* top */

        va = (uint64_t) (uintptr_t) (p_extend->p_rx_descriptors + p_gmac_cfg->num_rx_descriptors);
        R_BSP_MmuVatoPa(va, &pa);
        p_reg->DMA_CH[0].DCRTPR = (uint32_t) (uintptr_t) pa; /* end */
    }
#else
    {
        uint32_t desc_tail_addr = (uint32_t) (uintptr_t) (p_extend->p_rx_descriptors + p_gmac_cfg->num_rx_descriptors);

        p_reg->DMA_CH[0].DCRLAR = (uint32_t) (uintptr_t) p_extend->p_rx_descriptors;                                     /* top */
        p_reg->DMA_CH[0].DCRTPR = desc_tail_addr;                                                                        /* end */
    }
#endif

    p_reg->DMA_CH[0].DCRCR      = (uint32_t) ((uint16_t) p_gmac_cfg->ether_buffer_size << R_GBETH0_DCRCR0_RBSZ_4_0_Pos); /* rx buffer size */
    p_reg->DMA_CH[0].DCRCR_b.SR = 1;                                                                                     /* rx start */

    p_reg->MACRC0_b.RXQ0EN  = 2;
    p_reg->MACRC1_b.MCBCQ   = 0;
    p_reg->MACRC1_b.MCBCQEN = 1;

#if (BSP_FEATURE_GMAC_RXQ_ARBITRATION_SUPPORT)
    p_reg->MTL_Q[0].MTLRCR_b.RXQ_FRM_ARBIT = 1;
#endif
    p_reg->MTL_Q[0].MTLRCR_b.RXQ_WEGT = 1;

    p_reg->MTL_Q[0].MTLROMR_b.RQS = 0xF;
    p_reg->MTL_Q[0].MTLROMR_b.FEP = 1;
    p_reg->MTL_Q[0].MTLROMR_b.FUP = 1;
    p_reg->MTL_Q[0].MTLROMR_b.RSF = 1;

    p_reg->MTLRDMR_b.Q0MDMACH = 0;
    p_reg->MTLRDMR_b.Q0DDMACH = 1;
#if (1 <= BSP_FEATURE_GMAC_RXQ_DMA_MAX_MAP)
    p_reg->MTL_RxQ_DMA_Map1 = 0;
#endif

    if (GMAC_B_USE_MAGIC_PACKET_DETECT == mode)
    {
        /* Magic packet detection mode */
        p_reg->MACIER_b.PMTIE = 1;
    }
    else
    {
        /* Normal mode */
        p_reg->MACIER_b.PMTIE = 0;

        p_reg->DMA_CH[0].DCIER =
            GMAC_B_DMA_CH_INTERRUPT_ENABLE_NIE |  /* Normal Interrupt Summary Enable */
            GMAC_B_DMA_CH_INTERRUPT_ENABLE_AIE |  /* Abnormal Interrupt Summary Enable */
            GMAC_B_DMA_CH_INTERRUPT_ENABLE_CDEE | /* Context Descriptor Error Enable */
            GMAC_B_DMA_CH_INTERRUPT_ENABLE_FBEE | /* Fatal Bus Error Enable */
            GMAC_B_DMA_CH_INTERRUPT_ENABLE_ERIE | /* Early Receive Interrupt Enable */
            GMAC_B_DMA_CH_INTERRUPT_ENABLE_ETIE | /* Early Transmit Interrupt Enable */
            GMAC_B_DMA_CH_INTERRUPT_ENABLE_RWTE | /* Receive Watchdog Timeout Enable */

// GMAC_B_DMA_CH_INTERRUPT_ENABLE_RSE    |   /* Receive Stopped Enable */
            GMAC_B_DMA_CH_INTERRUPT_ENABLE_RBUE | /* Receive Buffer Unavailable Enable */
            GMAC_B_DMA_CH_INTERRUPT_ENABLE_RIE |  /* Receive Interrupt Enable */
            GMAC_B_DMA_CH_INTERRUPT_ENABLE_TBUE | /* Transmit Buffer Unavailable Enable */

// GMAC_B_DMA_CH_INTERRUPT_ENABLE_TXSE   |  /* Transmit Stopped Enable */
            GMAC_B_DMA_CH_INTERRUPT_ENABLE_TIE;   /* Transmit Interrupt Enable */
    }
}                                                 /* End of function gmac_config_ethernet() */

/********************************************************************************************************************//**
 * Description  : Determines PAUSE frame generation and handling. Uses the resolution Table 28B-3 of IEEE 802.3-2008.
 *
 * @param[in]   local_ability       local PAUSE capability (2 least significant bits)
 * @param[in]   partner_ability     link partner PAUSE capability (2 least significant bits)
 * @param[in]   p_tx_pause          pointer to location to store the result of the table lookup for transmit PAUSE.
 *                                  1 is enable, 0 is disable.
 * @param[in]   p_rx_pause          pointer to location to store the result of the table lookup for receive PAUSE.
 *                                  1 is enable, 0 is disable.
 *
 * @retval      none
 ***********************************************************************************************************************/
static void gmac_pause_resolution (uint32_t const local_ability,
                                   uint32_t const partner_ability,
                                   uint32_t     * p_tx_pause,
                                   uint32_t     * p_rx_pause)
{
    uint32_t i;
    uint32_t ability_compare;

    /*
     * Arrange the bits so that they correspond to the Table 28B-3
     * of the IEEE 802.3 values.
     */
    ability_compare =
        (uint32_t) (((local_ability & GMAC_B_LINK_RESOLUTION_ABILITY_MASK) <<
                     GMAC_B_LINK_RESOLUTION_LOCAL_ABILITY_BITSHIFT) |
                    (partner_ability & GMAC_B_LINK_RESOLUTION_ABILITY_MASK));

    /* Walk through the look up table */
    for (i = 0; i < GMAC_B_PAUSE_TABLE_ENTRIES; i++)
    {
        if ((ability_compare & pause_resolution[i].mask) == pause_resolution[i].value)
        {
            (*p_tx_pause) = pause_resolution[i].transmit;
            (*p_rx_pause) = pause_resolution[i].receive;

            return;
        }
    }
}                                      /* End of function gmac_pause_resolution() */

/********************************************************************************************************************//**
 * Description  : GMAC are configured.
 *
 * @param[in]   p_instance_ctrl         Ethernet driver control block.
 * @param[in]   mac_addr                The MAC address of GMAC
 * @param[in]   mode                    The operational mode is specified.
 *                                      NO_USE_MAGIC_PACKET_DETECT (0) - Communicate mode usually
 *                                      USE_MAGIC_PACKET_DETECT    (1) - Magic packet detection mode
 *
 * @retval      none
 ***********************************************************************************************************************/
static void gmac_b_configure_mac (gmac_b_instance_ctrl_t * const p_instance_ctrl,
                                  const uint8_t                  mac_addr[],
                                  const uint8_t                  mode)
{
    volatile R_GBETH_Type * const p_reg = p_instance_ctrl->p_reg_gmac;

    gmac_b_disable(p_instance_ctrl);

    /* set mac address 0 */
    p_reg->MAC_ADDRESS[0].MACAHR_b.DCS = 0;

    p_reg->MAC_ADDRESS[0].MACAHR_b.ADDRHI = (uint16_t) ((mac_addr[5] << 8) |
                                                        (mac_addr[4]));

    p_reg->MAC_ADDRESS[0].MACALR_b.ADDRLO = (uint32_t) ((mac_addr[3] << 24) |
                                                        (mac_addr[2] << 16) |
                                                        (mac_addr[1] << 8) |
                                                        (mac_addr[0]));

    /* set mac address 1 */
    uint8_t * mac_addr1 = ((gmac_b_extend_cfg_t *) p_instance_ctrl->p_gmac_cfg->p_extend)->p_mac_address1;
    if (0 != mac_addr1)
    {
        p_reg->MAC_ADDRESS[1].MACAHR_b.AE  = 1; /* enable address */
        p_reg->MAC_ADDRESS[1].MACAHR_b.DCS = 0;
        p_reg->MAC_ADDRESS[1].MACAHR_b.MBC = 0;

        p_reg->MAC_ADDRESS[1].MACAHR_b.ADDRHI = (uint16_t) ((mac_addr1[5] << 8) |
                                                            (mac_addr1[4]));

        p_reg->MAC_ADDRESS[1].MACALR_b.ADDRLO = (uint32_t) ((mac_addr1[3] << 24) |
                                                            (mac_addr1[2] << 16) |
                                                            (mac_addr1[1] << 8) |
                                                            (mac_addr1[0]));
    }

    /* set mac address 2 */
    uint8_t * mac_addr2 = ((gmac_b_extend_cfg_t *) p_instance_ctrl->p_gmac_cfg->p_extend)->p_mac_address2;
    if (0 != mac_addr2)
    {
        p_reg->MAC_ADDRESS[2].MACAHR_b.AE  = 1; /* enable address */
        p_reg->MAC_ADDRESS[2].MACAHR_b.DCS = 0;
        p_reg->MAC_ADDRESS[2].MACAHR_b.MBC = 0;

        p_reg->MAC_ADDRESS[2].MACAHR_b.ADDRHI = (uint16_t) ((mac_addr2[5] << 8) |
                                                            (mac_addr2[4]));

        p_reg->MAC_ADDRESS[2].MACALR_b.ADDRLO = (uint32_t) ((mac_addr2[3] << 24) |
                                                            (mac_addr2[2] << 16) |
                                                            (mac_addr2[1] << 8) |
                                                            (mac_addr2[0]));
    }

    gmac_b_init_descriptors(p_instance_ctrl);

    gmac_config_ethernet(p_instance_ctrl, mode);
}                                      /* End of function gmac_b_configure_mac() */

/*******************************************************************************************************************//**
 * Disable receive and transmit
 *
 * @param[in] p_instance_ctrl           Ethernet driver control block.
 *
 * @retval      none
 ***********************************************************************************************************************/
static void gmac_b_disable (gmac_b_instance_ctrl_t * const p_instance_ctrl)
{
    volatile R_GBETH_Type * p_reg_gmac;

    p_reg_gmac = (R_GBETH_Type *) p_instance_ctrl->p_reg_gmac;

    /* Disable TE and RE  */
    p_reg_gmac->MACCR_b.RE = 0U;       /* Receiver Disable */
    p_reg_gmac->MACCR_b.TE = 0U;       /* Transmitter Disable */
}                                      /* End of function gmac_b_disable() */

/*******************************************************************************************************************//**
 * Call user's callback function from R_GMAC_LinkProcess
 *
 * @param[in] p_instance_ctrl           Ethernet driver control block.
 * @param[in] event                     Event code.
 * @param[in] link_status               Link status.
 *
 * @retval      none
 ***********************************************************************************************************************/
void gmac_b_call_user_callback (gmac_b_instance_ctrl_t * p_instance_ctrl,
                                ether_event_t            event,
                                gmac_b_port_mask_t       link_status)
{
    ether_cfg_t const   * p_gmac_cfg = p_instance_ctrl->p_gmac_cfg;
    ether_callback_args_t callback_arg;

    if (NULL != p_instance_ctrl->p_callback)
    {
        callback_arg.channel      = p_gmac_cfg->channel;
        callback_arg.event        = event;
        callback_arg.status_ether = 0;
        callback_arg.status_link  = link_status;
        callback_arg.p_context    = p_gmac_cfg->p_context;

        gmac_b_call_callback(p_instance_ctrl, &callback_arg);
    }
}                                      /* End of function gmac_b_call_user_callback() */

/*******************************************************************************************************************//**
 * Run Link process by port
 *
 * @param[in] p_instance_ctrl       Ethernet driver control block.
 * @param[in] port                  The port number.
 *
 * @retval     FSP_SUCCESS                      Processing completed successfully.
 * @retval     FSP_ERR_ASSERTION                Pointer to ETHER control block or configuration structure is NULL.
 * @retval     FSP_ERR_NOT_OPEN                 The control block has not been opened.
 * @retval     FSP_ERR_ETHER_ERROR_LINK         Auto-negotiation is not completed, and reception is not enabled.
 ***********************************************************************************************************************/
static fsp_err_t gmac_b_link_process (gmac_b_instance_ctrl_t * p_instance_ctrl, uint32_t port)
{
    fsp_err_t            err = FSP_SUCCESS;
    gmac_b_link_change_t link_change;
    gmac_b_port_mask_t   port_status = g_gmac_port_mask[port];

    link_change = gmac_b_link_change_check(p_instance_ctrl, port);

    /* When the change status is Link-up */
    if (GMAC_B_LINK_CHANGE_LINK_UP == link_change)
    {
        err = gmac_b_do_link(p_instance_ctrl, port);
        if (FSP_SUCCESS == err)
        {
            p_instance_ctrl->link_establish_status |= port_status;

            gmac_b_call_user_callback(p_instance_ctrl, ETHER_EVENT_LINK_ON, port_status);
        }
        else
        {
            /* When PHY auto-negotiation is not completed */
            p_instance_ctrl->link_establish_status &= ~port_status;
        }
    }
    /* When the change status is Link-down */
    else if (GMAC_B_LINK_CHANGE_LINK_DOWN == link_change)
    {
        p_instance_ctrl->link_establish_status &= ~port_status; // the establesh status is down

        gmac_b_call_user_callback(p_instance_ctrl, ETHER_EVENT_LINK_OFF, port_status);

        err = FSP_ERR_ETHER_ERROR_LINK;
    }
    /* When the change status is no change */
    else
    {
        /* when the previous link status is Link-up and the establesh status is down */
        if ((0 != (p_instance_ctrl->previous_link_status & port_status)) &&
            (0 == (p_instance_ctrl->link_establish_status & port_status)))
        {
            err = gmac_b_do_link(p_instance_ctrl, port);
            if (FSP_SUCCESS == err)
            {
                p_instance_ctrl->link_establish_status |= port_status; // the establesh status is up

                gmac_b_call_user_callback(p_instance_ctrl, ETHER_EVENT_LINK_ON, port_status);
            }
        }
        else
        {
            /* no operation */
        }
    }

    return err;
}                                      /* End of function gmac_b_link_process() */

/*******************************************************************************************************************//**
 * Check Link status change
 *
 * @param[in] p_instance_ctrl       Ethernet driver control block.
 * @param[in] port                  The port number.
 *
 * @retval     GMAC_B_LINK_CHANGE_LINK_UP         Change from link down to link up.
 * @retval     GMAC_B_LINK_CHANGE_LINK_DOWN       Change from link down to link up.
 * @retval     GMAC_B_LINK_CHANGE_NO_CHANGE       No change link status.
 ***********************************************************************************************************************/
static gmac_b_link_change_t gmac_b_link_change_check (gmac_b_instance_ctrl_t * p_instance_ctrl, uint32_t port)
{
    gmac_b_link_change_t link_change = GMAC_B_LINK_CHANGE_NO_CHANGE;
    gmac_b_port_mask_t   port_status = g_gmac_port_mask[port];
    fsp_err_t            err;

    if (GMAC_B_PHYLINK_ENABLE == ((gmac_b_extend_cfg_t *) p_instance_ctrl->p_gmac_cfg->p_extend)->phylink)
    {
        if (0 != (p_instance_ctrl->link_status & port_status))
        {
            /* When becoming Link up */
            if (0 == (p_instance_ctrl->previous_link_status & port_status))
            {
                /* When the previous link status is Link-down, the change status is Link-up */
                link_change = GMAC_B_LINK_CHANGE_LINK_UP;

                /* Update previous link status */
                p_instance_ctrl->previous_link_status |= port_status;
            }
        }
        else
        {
            /* When becoming Link down */
            if (0 != (p_instance_ctrl->previous_link_status & port_status))
            {
                /* When the previous link status is Link-up, the change status is Link-down */
                link_change = GMAC_B_LINK_CHANGE_LINK_DOWN;

                /* Update previous link status */
                p_instance_ctrl->previous_link_status &= ~port_status;
            }
        }
    }
    else
    {
        err = gmac_b_link_status_check(p_instance_ctrl, port);

        /* The state of the link status in PHY-LSI is confirmed and Link Up/Down is judged. */
        if (FSP_SUCCESS == err)
        {
            /* When becoming Link-up */
            if (0 == (p_instance_ctrl->previous_link_status & port_status))
            {
                /* When the previous link status is Link-down, the change status is Link-up */
                link_change = GMAC_B_LINK_CHANGE_LINK_UP;

                /* Update previous link status */
                p_instance_ctrl->previous_link_status |= port_status;
            }
        }
        else
        {
            /* When becoming Link-down */
            if (0 != (p_instance_ctrl->previous_link_status & port_status))
            {
                /* When the previous link status is Link-up, the change status is Link-down */
                link_change = GMAC_B_LINK_CHANGE_LINK_DOWN;

                /* Update previous link status */
                p_instance_ctrl->previous_link_status &= ~port_status;
            }
        }
    }

    return link_change;
}                                      /* End of function gmac_b_link_change_check() */

/*******************************************************************************************************************//**
 * Determines the partner PHY capability through auto-negotiation process.
 * The link abilities are handled to determine duplex, speed and flow control (PAUSE frames).
 *
 * @param[in] p_instance_ctrl           Pointer to the control block for the channel
 * @param[in] port                      Port number
 *
 * @retval  FSP_SUCCESS                 Processing completed successfully.
 * @retval  FSP_ERR_ASSERTION           Pointer to ETHER control block or configuration structure is NULL.
 * @retval  FSP_ERR_NOT_OPEN            The control block has not been opened.
 * @retval  FSP_ERR_ETHER_ERROR_LINK    Auto-negotiation of PHY-LSI is not completed
 *                                      or result of Auto-negotiation is abnormal.
 ***********************************************************************************************************************/
static fsp_err_t gmac_b_do_link (gmac_b_instance_ctrl_t * const p_instance_ctrl, const uint32_t port)
{
    ether_phy_instance_t const *(*pp_phy_instance)[BSP_FEATURE_GMAC_MAX_PORTS];

    fsp_err_t err = FSP_SUCCESS;
#ifdef GMAC_B_IMPLEMENT_ETHSW
    ethsw_link_speed_t speed;
#endif                                 // GMAC_B_IMPLEMENT_ETHSW

#if (GMAC_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    GMAC_ERROR_RETURN(GMAC_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Get the link status */
    pp_phy_instance = ((gmac_b_extend_cfg_t *) p_instance_ctrl->p_gmac_cfg->p_extend)->pp_phy_instance;

    err = (*pp_phy_instance)[port]->p_api->linkPartnerAbilityGet((*pp_phy_instance)[port]->p_ctrl,
                                                                 &p_instance_ctrl->link_speed_duplex,
                                                                 &p_instance_ctrl->local_pause_bits,
                                                                 &p_instance_ctrl->partner_pause_bits);
#ifdef GMAC_B_IMPLEMENT_ETHSW
    if (FSP_SUCCESS == err)
    {
        switch (p_instance_ctrl->link_speed_duplex)
        {
            /* Half duplex link */
            case ETHER_PHY_LINK_SPEED_1000H:
            {
                speed = ETHSW_LINK_SPEED_1000H;
                break;
            }

            case ETHER_PHY_LINK_SPEED_100H:
            {
                speed = ETHSW_LINK_SPEED_100H;
                break;
            }

            case ETHER_PHY_LINK_SPEED_10H:
            {
                speed = ETHSW_LINK_SPEED_10H;
                break;
            }

            /* Full duplex link */
            case ETHER_PHY_LINK_SPEED_1000F:
            {
                speed = ETHSW_LINK_SPEED_1000F;
                break;
            }

            case ETHER_PHY_LINK_SPEED_100F:
            {
                speed = ETHSW_LINK_SPEED_100F;
                break;
            }

            case ETHER_PHY_LINK_SPEED_10F:
            {
                speed = ETHSW_LINK_SPEED_10F;
                break;
            }

            default:
            {
                err = FSP_ERR_ETHER_ERROR_LINK;
                break;
            }
        }
    }
#endif                                 // GMAC_B_IMPLEMENT_ETHSW

    if (FSP_SUCCESS == err)
    {
#ifdef GMAC_B_IMPLEMENT_ETHSW
        if (0 == p_instance_ctrl->p_gmac_cfg->channel)
        {
            ether_switch_instance_t const * p_ethsw_instance = ///< Pointer to ETHER_SWITCH instance
                                                               ((gmac_b_extend_cfg_t *) p_instance_ctrl->p_gmac_cfg->
                                                                p_extend)->
                                                               p_ethsw_instance;

            err = R_ETHSW_SpeedCfg(p_ethsw_instance->p_ctrl, (uint8_t) port, speed);
        }
#endif                                 // GMAC_B_IMPLEMENT_ETHSW
    }
    else
    {
        err = FSP_ERR_ETHER_ERROR_LINK;
    }

    return err;
}                                      /* End of function gmac_b_do_link() */

/*******************************************************************************************************************//**
 * Set the GMAC operation mode and enable transmission/reception.
 *
 * Note: The flow control cannot be used in the mode of transmitting and receiving via ETHSW.
 *       Therefore, currently, the code for the flow control is left for compatibility with RA.
 *       Operation is not guaranteed when the flow control is enabled.
 *
 * @param[in] p_instance_ctrl           Pointer to the control block for the channel
 *
 * @retval  none
 ***********************************************************************************************************************/
static void gmac_b_configure_operation (gmac_b_instance_ctrl_t * const p_instance_ctrl)
{
    volatile R_GBETH_Type * p_reg_gmac;
    uint32_t                transmit_pause_set = 0;
    uint32_t                receive_pause_set  = 0;
    bool full_duplex = false;
#if (0 == BSP_FEATURE_ETHSS_SUPPORTED)
    fsp_priv_clock_divider_t divider;
    uint32_t                 divide_value = BSP_CLOCKS_PLLETH_GBE0_DIV_2;

    if (0 == p_instance_ctrl->p_gmac_cfg->channel)
    {
        divider = FSP_PRIV_CLOCK_DIVIDER_PLLETH_GBE0;
    }
    else
    {
        divider = FSP_PRIV_CLOCK_DIVIDER_PLLETH_GBE1;
    }
#endif

    p_reg_gmac = (R_GBETH_Type *) p_instance_ctrl->p_reg_gmac;

#ifdef GMAC_B_IMPLEMENT_ETHSW
    if (0 == p_instance_ctrl->p_gmac_cfg->channel)
    {
        p_reg_gmac->MACCR_b.PS  = 0;   /* Port Selec: 1Gbps */
        p_reg_gmac->MACCR_b.FES = 1;   /* Speed: 100Mbps */
        p_reg_gmac->MACCR_b.DM  = 1;   /* Duplex Mode: Full-duple */
        full_duplex             = true;
    }
    else
#endif /* GMAC_B_IMPLEMENT_ETHSW */
    {
        switch (p_instance_ctrl->link_speed_duplex)
        {
            /* Half duplex link */
            case ETHER_PHY_LINK_SPEED_1000H:
            {
                p_reg_gmac->MACCR_b.PS  = 0;                 /* Port Selec: 1Gbps */
                p_reg_gmac->MACCR_b.FES = 0;
                p_reg_gmac->MACCR_b.DM  = 0;                 /* Duplex Mode: Half-duple */
#if (0 == BSP_FEATURE_ETHSS_SUPPORTED)
                divide_value = BSP_CLOCKS_PLLETH_GBE0_DIV_2; /* 125MHz = 250MHz / 2 */
#endif
                break;
            }

            case ETHER_PHY_LINK_SPEED_100H:
            {
                p_reg_gmac->MACCR_b.PS  = 1;                  /* Port Selec: 10Mbps or 100Mbps */
                p_reg_gmac->MACCR_b.FES = 1;                  /* Speed Select: 100Mbps */
                p_reg_gmac->MACCR_b.DM  = 0;                  /* Duplex Mode: Half-duple */
#if (0 == BSP_FEATURE_ETHSS_SUPPORTED)
                divide_value = BSP_CLOCKS_PLLETH_GBE0_DIV_10; /* 25MHz = 250MHz / 10 */
#endif
                break;
            }

            case ETHER_PHY_LINK_SPEED_10H:
            {
                p_reg_gmac->MACCR_b.PS  = 1;                   /* Port Selec: 10Mbps or 100Mbps */
                p_reg_gmac->MACCR_b.FES = 0;                   /* Speed Select: 10Mbps */
                p_reg_gmac->MACCR_b.DM  = 0;                   /* Duplex Mode: Half-duple */
#if (0 == BSP_FEATURE_ETHSS_SUPPORTED)
                divide_value = BSP_CLOCKS_PLLETH_GBE0_DIV_100; /* 2.5MHz = 250MHz / 100 */
#endif
                break;
            }

            /* Full duplex link */
            case ETHER_PHY_LINK_SPEED_1000F:
            {
                p_reg_gmac->MACCR_b.PS  = 0;                 /* Port Selec: 1Gbps */
                p_reg_gmac->MACCR_b.FES = 0;
                p_reg_gmac->MACCR_b.DM  = 1;                 /* Duplex Mode: Full-duple */
                full_duplex             = true;
#if (0 == BSP_FEATURE_ETHSS_SUPPORTED)
                divide_value = BSP_CLOCKS_PLLETH_GBE0_DIV_2; /* 125MHz = 250MHz / 2 */
#endif
                break;
            }

            case ETHER_PHY_LINK_SPEED_100F:
            {
                p_reg_gmac->MACCR_b.PS  = 1;                  /* Port Selec: 10Mbps or 100Mbps */
                p_reg_gmac->MACCR_b.FES = 1;                  /* Speed Select: 100Mbps */
                p_reg_gmac->MACCR_b.DM  = 1;                  /* Duplex Mode: Full-duple */
                full_duplex             = true;
#if (0 == BSP_FEATURE_ETHSS_SUPPORTED)
                divide_value = BSP_CLOCKS_PLLETH_GBE0_DIV_10; /* 25MHz = 250MHz / 10 */
#endif
                break;
            }

            case ETHER_PHY_LINK_SPEED_10F:
            {
                p_reg_gmac->MACCR_b.PS  = 1;                   /* Port Selec: 10Mbps or 100Mbps */
                p_reg_gmac->MACCR_b.FES = 0;                   /* Speed Select: 10Mbps */
                p_reg_gmac->MACCR_b.DM  = 1;                   /* Duplex Mode: Full-duple */
                full_duplex             = true;
#if (0 == BSP_FEATURE_ETHSS_SUPPORTED)
                divide_value = BSP_CLOCKS_PLLETH_GBE0_DIV_100; /* 2.5MHz = 250MHz / 100 */
#endif
                break;
            }

            /* Unknown */
            default:
            {
                p_reg_gmac->MACCR_b.PS  = 0;                 /* Port Selec: 1Gbps */
                p_reg_gmac->MACCR_b.FES = 0;
                p_reg_gmac->MACCR_b.DM  = 1;                 /* Duplex Mode: Full-duple */
#if (0 == BSP_FEATURE_ETHSS_SUPPORTED)
                divide_value = BSP_CLOCKS_PLLETH_GBE0_DIV_2; /* 125MHz = 250MHz / 2 */
#endif
                break;
            }
        }
    }

    if ((ETHER_FLOW_CONTROL_ENABLE == p_instance_ctrl->p_gmac_cfg->flow_control) &&
        (true == full_duplex))
    {
        /* pause frame is used */

        /**
         * Enable PAUSE for full duplex link depending on
         * the pause resolution results
         */
        gmac_pause_resolution(p_instance_ctrl->local_pause_bits,
                              p_instance_ctrl->partner_pause_bits,
                              &transmit_pause_set,
                              &receive_pause_set);

        if (GMAC_B_PAUSE_XMIT_ON == transmit_pause_set)
        {
            /* Enable automatic PAUSE frame transmission */
            p_reg_gmac->MTL_Q[0].MTLROMR_b.RFD  = 2; /* Threshold for Deactivating Flow Control = FULL - 3KB */
            p_reg_gmac->MTL_Q[0].MTLROMR_b.RFA  = 1; /* Threshold for Deactivating Flow Control = FULL - 2KB */
            p_reg_gmac->MTL_Q[0].MTLROMR_b.EHFC = 1; /* Enable HW Flow Control */

            p_reg_gmac->MACQTFCR_b.PT  = GMAC_B_PAUSE_TIME;
            p_reg_gmac->MACQTFCR_b.PLT = 2;
            p_reg_gmac->MACQTFCR_b.TFE = 1;
        }

        if (GMAC_B_PAUSE_RECV_ON == receive_pause_set)
        {
            /* Enable reception of PAUSE frames */
            p_reg_gmac->MACRFCR_b.RFE = 1;
        }
    }
    else
    {
        /* pause frame is not used */
        p_reg_gmac->MTL_Q[0].MTLROMR_b.RFD  = 0;
        p_reg_gmac->MTL_Q[0].MTLROMR_b.RFA  = 0;
        p_reg_gmac->MTL_Q[0].MTLROMR_b.EHFC = 0;
        p_reg_gmac->MACQTFCR_b.TFE          = 0;
        p_reg_gmac->MACRFCR                 = 0;
    }

    /* CRC Stripping for Type Frames */
    p_reg_gmac->MACCR_b.CST = 1;

    /* Automatic Pad or CRC Stripping */
    p_reg_gmac->MACCR_b.ACS = 1;

#if (0 == BSP_FEATURE_ETHSS_SUPPORTED)

    /* Set TX_CLK frequency */
    R_BSP_ClockDividerSet(divider, divide_value);
#endif

    /* Enable receive and transmit. */
    p_reg_gmac->MACCR_b.TE = 1U;
    p_reg_gmac->MACCR_b.RE = 1U;
}                                      /* End of function gmac_b_configure_operation() */

/*******************************************************************************************************************//**
 * The magic packet detection is permitted.
 *
 * @param[in]   p_instance_ctrl             Pointer to the control block for the channel
 *
 * @retval      non
 ***********************************************************************************************************************/
void gmac_b_magic_packet_detection (gmac_b_instance_ctrl_t * const p_instance_ctrl)
{
    volatile R_GBETH_Type * p_reg_gmac = (R_GBETH_Type *) p_instance_ctrl->p_reg_gmac;

    /* The magic packet detection is permitted. */
    p_reg_gmac->MACPCSR =
        GMAC_B_PMT_CONTROL_STATUS_MGKPKTEN | /* Magic Packet Enable */
        GMAC_B_PMT_CONTROL_STATUS_PWRDWN;    /* Power Down */

    /* Because data is not transmitted for the magic packet detection waiting,
     * only the reception is permitted. */
    p_reg_gmac->MACCR_b.RE = 1;
}                                            /* End of function gmac_b_magic_packet_detection() */

/*******************************************************************************************************************//**
 * The magic packet detection is permitted.
 *
 * @param[in]   p_instance_ctrl             Pointer to the control block for the channel
 *
 * @retval      1: Magic Packet detection is enabled.
 *              0: Magic Packet detection is disabled.
 ***********************************************************************************************************************/
static uint8_t gmac_b_check_magic_packet_detection_bit (gmac_b_instance_ctrl_t const * const p_instance_ctrl)
{
    uint8_t ret = 0;

    volatile R_GBETH_Type * p_reg_gmac = (R_GBETH_Type *) p_instance_ctrl->p_reg_gmac;

    if (1 == p_reg_gmac->MACPCSR_b.MGKPKTEN)
    {
        ret = 1;
    }
    else
    {
        ret = 0;
    }

    return ret;
}                                      /* End of function gmac_b_check_magic_packet_detection_bit() */

/*******************************************************************************************************************//**
 * Verifies the Etherent link is up or not.
 *
 * @param[in] p_instance_ctrl   Pointer to the control block for the channel
 * @param[in] port              Port number
 *
 * @retval  FSP_SUCCESS:                  Link is up
 * @retval  FSP_ERR_ETHER_ERROR_LINK      Link is down
 * @retval  FSP_ERR_ETHER_PHY_ERROR_LINK  Initialization of PHY-LSI failed.
 * @retval  FSP_ERR_INVALID_ARGUMENT      The ether_phy driver for the specified port cannot be used.
 **********************************************************************************************************************/
static fsp_err_t gmac_b_link_status_check (gmac_b_instance_ctrl_t const * const p_instance_ctrl, uint32_t port)
{
    fsp_err_t err = FSP_SUCCESS;
    fsp_err_t link_status;

    ether_phy_instance_t const *(*pp_phy_instance)[BSP_FEATURE_GMAC_MAX_PORTS];

    pp_phy_instance = ((gmac_b_extend_cfg_t *) p_instance_ctrl->p_gmac_cfg->p_extend)->pp_phy_instance;

    if (NULL == (*pp_phy_instance)[port])
    {
        return FSP_ERR_INVALID_ARGUMENT;
    }

    link_status = (*pp_phy_instance)[port]->p_api->linkStatusGet((*pp_phy_instance)[port]->p_ctrl);

    if (FSP_ERR_ETHER_PHY_ERROR_LINK == link_status)
    {
        /* Link is down */
        err = FSP_ERR_ETHER_ERROR_LINK;
    }
    else
    {
        /* Link is up */
        err = FSP_SUCCESS;
    }

    return err;
}                                      /* End of function gmac_b_link_status_check() */

#ifdef GMAC_B_IMPLEMENT_ETHSW

/*******************************************************************************************************************//**
 * Callback function for link status change from switch
 *
 * @param[in] p_arg     Pointer to the callback parameter
 *
 * @retval  non
 **********************************************************************************************************************/
void gmac_b_callback_ethsw (ether_switch_callback_args_t * const p_arg)
{
    gmac_b_instance_ctrl_t * p_instance_ctrl = (gmac_b_instance_ctrl_t *) p_arg->p_context;

    if (0 != p_instance_ctrl)
    {
        p_instance_ctrl->link_status = (gmac_b_port_mask_t) p_arg->status_link;
    }
}                                      /* End of function gmac_b_callback_ethsw() */

#endif // GMAC_B_IMPLEMENT_ETHSW

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_instance_ctrl      Pointer to ether instance control block
 * @param[in]     p_callback_args      Pointer to callback args
 **********************************************************************************************************************/
static void gmac_b_call_callback (gmac_b_instance_ctrl_t * p_instance_ctrl, ether_callback_args_t * p_callback_args)
{
    ether_callback_args_t args;

    /* Store callback arguments in memory provided by user if available.  This allows callback arguments to be
     * stored in non-secure memory so they can be accessed by a non-secure callback function. */
    ether_callback_args_t * p_args = p_instance_ctrl->p_callback_memory;
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

    p_args->channel      = p_instance_ctrl->p_gmac_cfg->channel;
    p_args->event        = p_callback_args->event;
    p_args->status_ether = p_callback_args->status_ether;
    p_args->status_link  = p_callback_args->status_link;
    p_args->p_context    = p_instance_ctrl->p_context;

    /* If the project is not Trustzone Secure, then it will never need to change security state in order to call the callback. */
    p_instance_ctrl->p_callback(p_args);

    if (NULL != p_instance_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_instance_ctrl->p_callback_memory = args;
    }
}                                      /* End of function gmac_b_call_callback() */

/*******************************************************************************************************************//**
 * Interrupt handler for SBD(DMA channel) interrupts.
 *
 * @retval      none
 **********************************************************************************************************************/
static void gmac_b_isr_dma_ch (gmac_b_instance_ctrl_t * p_instance_ctrl)
{
    ether_callback_args_t   callback_arg;
    volatile R_GBETH_Type * p_reg_gmac;
    uint32_t                status;
    volatile uint32_t       dammy_read;

    p_reg_gmac = (R_GBETH_Type *) p_instance_ctrl->p_reg_gmac;

    status = p_reg_gmac->DMA_CH[0].DCSR;
    p_reg_gmac->DMA_CH[0].DCSR = status; /* clear */

    /* Dammy read for Countermeasure when the CPU clock is 400 or 800MHz */
    dammy_read = p_reg_gmac->DMA_CH[0].DCSR;
    dammy_read = dammy_read;

    /* Callback : Interrupt handler */
    if (NULL != p_instance_ctrl->p_callback)
    {
        callback_arg.channel      = p_instance_ctrl->p_gmac_cfg->channel;
        callback_arg.event        = ETHER_EVENT_SBD_INTERRUPT;
        callback_arg.status_ether = status;
        callback_arg.status_link  = 0;
        callback_arg.p_context    = p_instance_ctrl->p_gmac_cfg->p_context;

        gmac_b_call_callback(p_instance_ctrl, &callback_arg);
    }
}                                      /* End of function gmac_b_isr_dma_ch() */

/*******************************************************************************************************************//**
 * Interrupt handler for SBD(MTL) interrupts.
 *
 * @retval      none
 **********************************************************************************************************************/
static void gmac_b_isr_mtl (gmac_b_instance_ctrl_t * p_instance_ctrl)
{
    uint32_t                status;
    volatile R_GBETH_Type * p_reg_gmac;
    volatile uint32_t       dammy_read;

    p_reg_gmac = (R_GBETH_Type *) p_instance_ctrl->p_reg_gmac;

    status = p_reg_gmac->MTL_Q[0].MTLQICSR;
    p_reg_gmac->MTL_Q[0].MTLQICSR = status; /* clear */

    /* Dammy read  */
    dammy_read = p_reg_gmac->MTL_Q[0].MTLQICSR;
    dammy_read = dammy_read;
}                                      /* End of function gmac_b_isr_mtl() */

/*******************************************************************************************************************//**
 * Interrupt handler for PMT interrupts.
 *
 * @retval      none
 **********************************************************************************************************************/
static void gmac_b_isr_pmt (gmac_b_instance_ctrl_t * p_instance_ctrl)
{
    ether_callback_args_t   callback_arg;
    volatile R_GBETH_Type * p_reg_gmac;
    uint32_t                pmt_control_status;

    p_reg_gmac = (R_GBETH_Type *) p_instance_ctrl->p_reg_gmac;

    pmt_control_status = p_reg_gmac->MACPCSR;

    /* Callback : Interrupt handler */
    if (NULL != p_instance_ctrl->p_callback)
    {
        callback_arg.channel      = p_instance_ctrl->p_gmac_cfg->channel;
        callback_arg.event        = ETHER_EVENT_PMT_INTERRUPT;
        callback_arg.status_ether = pmt_control_status;
        callback_arg.status_link  = 0;
        callback_arg.p_context    = p_instance_ctrl->p_gmac_cfg->p_context;

        gmac_b_call_callback(p_instance_ctrl, &callback_arg);
    }

    if ((GMAC_B_PMT_CONTROL_STATUS_MGKPRCVD == (GMAC_B_PMT_CONTROL_STATUS_MGKPRCVD & pmt_control_status)) ||
        (GMAC_B_PMT_CONTROL_STATUS_PWRDWN != (GMAC_B_PMT_CONTROL_STATUS_PWRDWN & pmt_control_status)))
    {
        p_instance_ctrl->magic_packet = GMAC_B_MAGIC_PACKET_DETECTED;
    }
    else
    {
        p_reg_gmac->MACPCSR =
            GMAC_B_PMT_CONTROL_STATUS_MGKPKTEN | /* Magic Packet Enable */
            GMAC_B_PMT_CONTROL_STATUS_PWRDWN;    /* Power Down */
    }
}                                                /* End of function gmac_b_isr_pmt() */

/*******************************************************************************************************************//**
 * Interrupt handler for SBD(MAC) interrupts.
 *
 * @retval      none
 **********************************************************************************************************************/
static void gmac_b_isr_mac (gmac_b_instance_ctrl_t * p_instance_ctrl)
{
    uint32_t                status;
    volatile R_GBETH_Type * p_reg_gmac;

    p_reg_gmac = (R_GBETH_Type *) p_instance_ctrl->p_reg_gmac;

    status = p_reg_gmac->MACISR;

    if (GMAC_B_MAC_INTERRUPT_STATUS_PMTIS == (status & GMAC_B_MAC_INTERRUPT_STATUS_PMTIS))
    {
        gmac_b_isr_pmt(p_instance_ctrl);
    }
}                                      /* End of function gmac_b_isr_mac() */

/*******************************************************************************************************************//**
 * Interrupt handler for SBD interrupts.
 *
 * @retval      none
 **********************************************************************************************************************/
void gmac_b_isr_sbd (void)
{
    uint32_t                 status;
    volatile R_GBETH_Type  * p_reg_gmac;
    IRQn_Type                irq             = R_FSP_CurrentIrqGet();
    gmac_b_instance_ctrl_t * p_instance_ctrl = (gmac_b_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    p_reg_gmac = (R_GBETH_Type *) p_instance_ctrl->p_reg_gmac;

    status = p_reg_gmac->DISR;

    if (GMAC_B_DMA_INTERRUPT_STATUS_DC0IS == (status & GMAC_B_DMA_INTERRUPT_STATUS_DC0IS))
    {
        /* only channel 0 is used */
        gmac_b_isr_dma_ch(p_instance_ctrl);
    }

    if (GMAC_B_DMA_INTERRUPT_STATUS_MTLIS == (status & GMAC_B_DMA_INTERRUPT_STATUS_MTLIS))
    {
        gmac_b_isr_mtl(p_instance_ctrl);
    }

    if (GMAC_B_DMA_INTERRUPT_STATUS_MACIS == (status & GMAC_B_DMA_INTERRUPT_STATUS_MACIS))
    {
        gmac_b_isr_mac(p_instance_ctrl);
    }
}                                      /* End of function gmac_b_isr_sbd() */

/*******************************************************************************************************************//**
 * Enable ICU
 *
 * @param[in] p_instance_ctrl   Pointer to the control block for the channel
 *
 * @retval      none
 **********************************************************************************************************************/
static void gmac_b_enable_icu (gmac_b_instance_ctrl_t * const p_instance_ctrl)
{
    R_BSP_IrqDisable(p_instance_ctrl->p_gmac_cfg->irq);
    R_BSP_IrqStatusClear(p_instance_ctrl->p_gmac_cfg->irq);

    /** Configure the Ethernet interrupt. */
    R_BSP_IrqCfgEnable(p_instance_ctrl->p_gmac_cfg->irq,
                       p_instance_ctrl->p_gmac_cfg->interrupt_priority,
                       p_instance_ctrl);
}                                      /* End of function gmac_b_enable_icu() */

/*******************************************************************************************************************//**
 * Disable ICU
 *
 * @param[in] p_instance_ctrl   Pointer to the control block for the channel
 *
 * @retval      none
 **********************************************************************************************************************/
static void gmac_b_disable_icu (gmac_b_instance_ctrl_t * const p_instance_ctrl)
{
    R_BSP_IrqDisable(p_instance_ctrl->p_gmac_cfg->irq);

    R_FSP_IsrContextSet(p_instance_ctrl->p_gmac_cfg->irq, NULL);
}                                      /* End of function gmac_b_disable_icu() */
