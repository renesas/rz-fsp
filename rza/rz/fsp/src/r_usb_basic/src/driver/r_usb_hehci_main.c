/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * File Name    : r_usb_hEhciMain.c
 * Description  : EHCI Main Code
 ***********************************************************************************************************************/

/**********************************************************************************************************************
 * History : DD.MM.YYYY Version Description
 *         : 31.08.2015 1.00    First Release
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/
#include "r_usb_hhci_local.h"
#include "r_usb_extern.h"

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

/* for debug maclo */

#define USB_VAL_50        (50U)
#define USB_VAL_100       (100U)
#define USB_VAL_256       (256U)
#define USB_VAL_512       (512U)
#define USB_VAL_X20       (0x00000020U)
#define USB_VAL_INTR      (0x00000037U)
#define USB_VAL_X1000     (0x00001000U)
#define USB_VAL_XDFD5     (0xFFFFDFD5U)
#define USB_VAL_XFFD5     (0xFFFFFFD5U)
#define USB_VAL_FFFF      (0xFFFFFFFFU)
#define USB_VAL_0100      (0x00000100U)
#define USB_VAL_XFED5     (0xFFFFFED5U)
#define USB_VAL_XFFE0     (0xFFFFFFE0U)
#define USB_VAL_XFFC      (0x00000FFCU)
#define USB_VAL_XF000     (0xFFFFF000U)
#define USB_VAL_1F020     (0x0001F020U)
#define USB_VAL_X2000     (0x00002000U)
#define USB_VAL_1F010     (0x0001F010U)
#define USB_VAL_1F004     (0x0001F004U)
#define USB_VAL_1F002     (0x0001F002U)
#define USB_VAL_1F008     (0x0001F008U)
#define USB_VAL_1F001     (0x0001F001U)
#define USB_VAL_SC_WK     (0x00700000U)
#define USB_VAL_SUSP      (0x00000040U)
#define USB_VAL_F95       (0xFFFFFF95U)
#define USB_VAL_ASUNSE    (0x00000020U)

#if USB_IP_EHCI_OHCI == 1

/***********************************************************************************************************************
 * External variables and functions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Static variables and functions
 ***********************************************************************************************************************/
static uint32_t usb_hstd_ehci_hw_reset(usb_utr_t * ptr);
static void     usb_hstd_ehci_set_port_route(usb_utr_t * ptr);
static uint32_t usb_hstd_ehci_port_enable(usb_utr_t * ptr, uint32_t * p_hs_enable_flag);
static void     usb_hstd_ehci_delete_periodec_scheduling_score(usb_utr_t * ptr,
                                                               uint32_t    max_period,
                                                               uint32_t    pollrate,
                                                               uint32_t    pollrate_offset);
static uint32_t usb_hstd_ehci_unlink_periodic(usb_utr_t * ptr, u_usb_ehci_flep_t * p_dataptr, uint32_t elementnum);
static void     usb_hstd_ehci_clear_device_trreq(uint32_t devadd);

/* For debug */
 #ifdef DEBUG_PRINT_PORT_INFOMATION
static void usb_hstd_ehci_print_port_information(usb_utr_t * ptr);

 #endif

 #ifdef DEBUG_PRINT_ASYNC_SCHEDULING
static void usb_hstd_ehci_print_async_scheduling(st_usb_ehci_qh_t * p_h_qh);

 #endif

 #ifdef DEBUG_PRINT_PERIODIC_SCHEDULING
static void usb_hstd_ehci_print_periodec_scheduling_list(usb_utr_t * ptr);
static void usb_hstd_ehci_print_periodic_scheduling_score(void);

 #endif

static uint8_t  gs_usb_ehci_root_device_address[USB_EHCI_MAXROOTPORTS];
static uint8_t  gs_usb_ehci_periodic_scheduling_score[USB_EHCI_PFL_SIZE * 8];
extern uint16_t g_usb_port_status[USB_NUM_USBIP][2];

/***********************************************************************************************************************
 * Function     : Initialize EHCI
 * Declaration  : uint32_t usb_hstd_ehci_init( void )
 * Argument     : void
 * Return       : uint32_t ; status
 * Note         :
 ***********************************************************************************************************************/
uint32_t usb_hstd_ehci_init (usb_utr_t * ptr)
{
    st_usb_ehci_qh_t * p_qh;
    uint32_t           timeout;
    uint32_t           i;
    uint32_t           addr;

    /* EHCI version check */
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        if (USB_EHCI_VERSON != ptr->ipp->CAPL_VERSION_b.InterfaceVersionNumber)
        {
            USB_HCI_PRINTF1_R("HCIVERSION Error : %04x\n", ptr->ipp->CAPL_VERSION_b.InterfaceVersionNumber);

            return USB_ERROR;
        }
    }
    else
    {
  #if USB_NUM_USBIP == 2
        if (USB_EHCI_VERSON != ptr->ipp1->CAPL_VERSION_b.InterfaceVersionNumber)
        {
            USB_HCI_PRINTF1_R("HCIVERSION Error : %04x\n", ptr->ipp1->CAPL_VERSION_b.InterfaceVersionNumber);

            return USB_ERROR;
        }
  #endif
    }
 #else
    if (USB_EHCI_VERSON != ptr->ipp->CAPL_VERSION_b.HCIVN)
    {
        USB_HCI_PRINTF1_R("HCIVERSION Error : %04x\n", USB00->CAPL_VERSION_b.HCIVN);

        return USB_ERROR;
    }
 #endif

    /* Stop & Reset eHC */
    usb_hstd_ehci_hw_reset(ptr);

    for (i = 0; i < USB_EHCI_MAXROOTPORTS; i++)
    {
        gs_usb_ehci_root_device_address[i] = USB_HCI_NODEVICE;
    }

    /* =================== */
    /*  Set Int Threshold  */
    /* =================== */
    /*  */
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        ptr->ipp->USBCMD_b.InterruptThresholdControl = 1; /* Interrupt Threshold == 1 micro-frame */
    }
    else
    {
  #if USB_NUM_USBIP == 2
        ptr->ipp1->USBCMD_b.InterruptThresholdControl = 1; /* Interrupt Threshold == 1 micro-frame */
  #endif
    }
 #else
    ptr->ipp->USBCMD_b.ITC = 1;                            /* Interrupt Threshold == 1 micro-frame */
 #endif

    /* ============================== */
    /*  Set Periodic Frame List Size  */
    /* ============================== */
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        if (ptr->ipp->HCCPARAMS_b.ProgramableFrameListFlag)
        {
            if (USB_EHCI_PFL_SIZE == USB_VAL_512)
            {
                ptr->ipp->USBCMD_b.FrameListSize = 1; /* 512 */
            }
            else if (USB_EHCI_PFL_SIZE == USB_VAL_256)
            {
                ptr->ipp->USBCMD_b.FrameListSize = 2; /* 256 */
            }
            else
            {
                /* None */
            }
        }
        else
        {
            if (USB_EHCI_PFL_SIZE != USB_VAL_1024)
            {
                return USB_ERROR;      /* error */
            }
        }
    }
    else
    {
  #if USB_NUM_USBIP == 2
        if (ptr->ipp1->HCCPARAMS_b.ProgramableFrameListFlag)
        {
            if (USB_EHCI_PFL_SIZE == USB_VAL_512)
            {
                ptr->ipp1->USBCMD_b.FrameListSize = 1; /* 512 */
            }
            else if (USB_EHCI_PFL_SIZE == USB_VAL_256)
            {
                ptr->ipp1->USBCMD_b.FrameListSize = 2; /* 256 */
            }
            else
            {
                /* None */
            }
        }
        else
        {
            if (USB_EHCI_PFL_SIZE != USB_VAL_1024)
            {
                return USB_ERROR;      /* error */
            }
        }
  #endif
    }
 #else
    if (USB00->HCCPARAMS_b.PFLF)
    {
        if (USB_EHCI_PFL_SIZE == USB_VAL_512)
        {
            USB00->USBCMD_b.FLS = 1;   /* 512 */
        }
        else if (USB_EHCI_PFL_SIZE == USB_VAL_256)
        {
            USB00->USBCMD_b.FLS = 2;   /* 256 */
        }
        else
        {
            /* None */
        }
    }
    else
    {
        if (USB_EHCI_PFL_SIZE != USB_VAL_1024)
        {
            return USB_ERROR;          /* error */
        }
    }
 #endif

    /* ========= */
    /*  Run eHC  */
    /* ========= */
    if (USB_IP0 == ptr->ip)
    {
        ptr->ipp->USBCMD_b.RS = 1;     /* Run/Stop = 1 */
    }
    else
    {
 #if USB_NUM_USBIP == 2
        ptr->ipp1->USBCMD_b.RS = 1;    /* Run/Stop = 1 */
 #endif
    }

    /* ============================= */
    /*  Initialize QH/qTD/iTD Array  */
    /* ============================= */
    usb_hstd_ehci_init_qh_memory();
    usb_hstd_ehci_init_qtd_memory();
    usb_hstd_ehci_init_itd_memory();
    usb_hstd_ehci_init_sitd_memory();

    /* ========================== */
    /*  Initialize Periodic List  */
    /* ========================== */
    usb_hstd_ehci_init_periodic_frame_list();
    memset(&gs_usb_ehci_periodic_scheduling_score[0], 0, sizeof(gs_usb_ehci_periodic_scheduling_score));

    /* Link PeriodicFrameList to PeriodicSchedule */
    addr = usb_hstd_ehci_get_periodic_frame_list_addr();
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        ptr->ipp->PERIODICLISTBASE = (uint32_t) r_usb_va_to_pa((uint64_t) addr);
    }
    else
    {
  #if USB_NUM_USBIP == 2
        ptr->ipp1->PERIODICLISTBASE = (uint32_t) r_usb_va_to_pa((uint64_t) addr);
  #endif
    }
 #else
    USB00->PERIODICLISTBASE = addr;
 #endif

    /* Enable Periodic Schedule */
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        ptr->ipp->USBCMD_b.PeriodicScheduleEnable = 1;
    }
    else
    {
  #if USB_NUM_USBIP == 2
        ptr->ipp1->USBCMD_b.PeriodicScheduleEnable = 1;
  #endif
    }
 #else
    USB00->USBCMD_b.PSE = 1;
 #endif

    timeout = 0;
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        while (0 == ptr->ipp->USBSTS_b.PeriodicScheduleStatus)
        {
            if (timeout > USB_EHCI_TIMEOUT)
            {
                USB_HCI_PRINTF0_R("Error : usb_hstd_EhciInit TIMEOUT\n");

                return USB_ERROR;
            }

            R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
            timeout++;
        }
    }
    else
    {
  #if USB_NUM_USBIP == 2
        while (0 == ptr->ipp1->USBSTS_b.PeriodicScheduleStatus)
        {
            if (timeout > USB_EHCI_TIMEOUT)
            {
                USB_HCI_PRINTF0_R("Error : usb_hstd_EhciInit TIMEOUT\n");

                return USB_ERROR;
            }

            R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
            timeout++;
        }
  #endif
    }
 #else
    while (0 == USB00->USBSTS_b.PSCHSTS)
    {
        if (timeout > USB_EHCI_TIMEOUT)
        {
            USB_HCI_PRINTF0_R("Error : usb_hstd_EhciInit TIMEOUT\n");

            return USB_ERROR;
        }

        R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
        timeout++;
    }
 #endif

    /* ======================= */
    /*  Initialize Async List  */
    /* ======================= */
    p_qh = usb_hstd_ehci_alloc_qh();
    if (NULL == p_qh)
    {
        return USB_ERROR;
    }

 #if defined(BSP_MCU_GROUP_RZA_USB)
    p_qh->queue_head_horizontal_link.address = (uint32_t) r_usb_va_to_pa((uint64_t) p_qh);
 #else
    p_qh->queue_head_horizontal_link.address = (uint32_t) p_qh;
 #endif
    p_qh->queue_head_horizontal_link.bit.typ = USB_EHCI_TYP_QH;
    p_qh->endpoint1.bit.h = 1;

    /* Link QH to AsyncSchuedule */
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        ptr->ipp->ASYNCLISTADDR = (uint32_t) r_usb_va_to_pa((uint64_t) p_qh);
    }
    else
    {
  #if USB_NUM_USBIP == 2
        ptr->ipp1->ASYNCLISTADDR = (uint32_t) r_usb_va_to_pa((uint64_t) p_qh);
  #endif
    }
 #else
    USB00->ASYNCLISTADDR = (uint32_t) p_qh;
 #endif

    /* Enable Asynchronous Schedule */
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        ptr->ipp->USBCMD_b.AsynchronousScheduleEnable         = 1;
        ptr->ipp->USBCMD_b.PerPortChangeEventsEnable          = 1;
        ptr->ipp->USBCMD_b.AsynchronousScheduleParkModeEnable = 0;
    }
    else
    {
  #if USB_NUM_USBIP == 2
        ptr->ipp1->USBCMD_b.AsynchronousScheduleEnable         = 1;
        ptr->ipp1->USBCMD_b.PerPortChangeEventsEnable          = 1;
        ptr->ipp1->USBCMD_b.AsynchronousScheduleParkModeEnable = 0;
  #endif
    }
 #else
    ptr->ipp->USBCMD        |= USB_VAL_ASUNSE;
    ptr->ipp->USBCMD_b.ASPME = 0;
 #endif

 #ifdef DEBUG_PRINT_ASYNC_SCHEDULING
    usb_hstd_ehci_print_async_scheduling(p_qh);
 #endif

    /* ================ */
    /*  Set Int Enable  */
    /* ================ */
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        ptr->ipp->USBINTR_b.InterruptonAsyncAdvanceEnable = 1;
        ptr->ipp->USBINTR_b.HostSystemErrorEnable         = 1;
        ptr->ipp->HCRHDESCRIPTORA_b.NOCP            = 1; /*over current off*/
        ptr->ipp->HCRHPORTSTATUS1_b.OCIC            = 1; /* over current status clear */
        ptr->ipp->PORTSC1_b.ConnectStatusChange     = 0; /* over current status clear */
        ptr->ipp->USBSTS_b.PortChangeDetect         = 1; /* over current status clear */
        ptr->ipp->USBINTR_b.PortChangeDetectEnable  = 1;
        ptr->ipp->USBINTR_b.USBErrorInterruptEnable = 1;
        ptr->ipp->USBINTR_b.USBInterruptEnable      = 1;
        ptr->ipp->HCRHDESCRIPTORA_b.NOCP            = 0;
        ptr->ipp->CONFIGFLAG_b.CF = 1;                  /* CF */
        ptr->ipp->USBINTR_b.Port1ChangeEventEnable = 1; /* Port1 Change Enable */
    }
    else
    {
  #if USB_NUM_USBIP == 2
        ptr->ipp1->USBINTR_b.InterruptonAsyncAdvanceEnable = 1;
        ptr->ipp1->USBINTR_b.HostSystemErrorEnable         = 1;
        ptr->ipp1->HCRHDESCRIPTORA_b.NOCP            = 1; /*over current off*/
        ptr->ipp1->HCRHPORTSTATUS1_b.OCIC            = 1; /* over current status clear */
        ptr->ipp1->PORTSC1_b.ConnectStatusChange     = 0; /* over current status clear */
        ptr->ipp1->USBSTS_b.PortChangeDetect         = 1; /* over current status clear */
        ptr->ipp1->USBINTR_b.PortChangeDetectEnable  = 1;
        ptr->ipp1->USBINTR_b.USBErrorInterruptEnable = 1;
        ptr->ipp1->USBINTR_b.USBInterruptEnable      = 1;
        ptr->ipp1->HCRHDESCRIPTORA_b.NOCP            = 0;
        ptr->ipp1->CONFIGFLAG_b.CF = 1;                  /* CF */
        ptr->ipp1->USBINTR_b.Port1ChangeEventEnable = 1; /* Port1 Change Enable */
  #endif
    }
 #else
    ptr->ipp->USBINTR         = USB_VAL_INTR;
    ptr->ipp->CONFIGFLAG_b.CF = 1;     /* CF */
 #endif

    /* ================== */
    /*  Set Port Routing  */
    /* ================== */
    usb_hstd_ehci_set_port_route(ptr);

    return USB_OK;
}                                      /* End of function usb_hstd_ehci_init() */

 #if (USB_UT_MODE == 0)

/***********************************************************************************************************************
 * Function     : Deinitialize EHCI
 * Declaration  : void usb_hstd_ehci_deinit( void )
 * Argument     : void
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ehci_deinit (usb_utr_t * ptr)
{
    usb_hstd_ehci_hw_reset(ptr);       /* Stop & Reset eHC */
} /* End of function usb_hstd_ehci_deinit() */

 #endif

/***********************************************************************************************************************
 * Function     : EHCI Port Reset
 * Declaration  : static uint32_t usb_hstd_ehci_port_reset( uint32_t portnum )
 * Argument     : uint32_t portnum ; port no
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
uint32_t usb_hstd_ehci_port_reset (usb_utr_t * ptr)
{
    uint32_t timeout;
    uint32_t portsc1_save;
    uint32_t result = FALSE;

    if (USB_IP0 == ptr->ip)
    {
        /* USB00.PORTSC1.BIT.PortReset = 1; */   /* Set Port Reset */
        portsc1_save      = ptr->ipp->PORTSC1;
        ptr->ipp->PORTSC1 = USB_VAL_0100 | (portsc1_save & USB_VAL_XFFD5);
        r_usb_hstd_hci_wait_time(ptr, 10);

        /* USB00.PORTSC1.BIT.PortReset = 0; */    /* Clear Port Reset */
        ptr->ipp->PORTSC1 &= USB_VAL_XFED5;

        /* Wait Port Reset bit was cleared */
        timeout = 0;
 #if defined(BSP_MCU_GROUP_RZA_USB)
        while (1 == ptr->ipp->PORTSC1_b.PortReset)
 #else
        while (1 == ptr->ipp->PORTSC1_b.PTRST)
 #endif
        {
            if (timeout > USB_EHCI_TIMEOUT)
            {
                USB_HCI_PRINTF0_R("Error : usb_hstd_ehci_port_enable TIMEOUT\n");

                return FALSE;
            }

            usb_cpu_delay_xms(1);
            timeout++;
        }

        usb_cpu_delay_xms(10);

        result = TRUE;
    }
    else
    {
 #if USB_NUM_USBIP == 2
        /* USB00.PORTSC1.BIT.PortReset = 1; */   /* Set Port Reset */
        portsc1_save       = ptr->ipp1->PORTSC1;
        ptr->ipp1->PORTSC1 = USB_VAL_0100 | (portsc1_save & USB_VAL_XFFD5);
        r_usb_hstd_hci_wait_time(ptr, 10);

        /* USB00.PORTSC1.BIT.PortReset = 0; */    /* Clear Port Reset */
        ptr->ipp1->PORTSC1 &= USB_VAL_XFED5;

        /* Wait Port Reset bit was cleared */
        timeout = 0;
  #if defined(BSP_MCU_GROUP_RZA_USB)
        while (1 == ptr->ipp1->PORTSC1_b.PortReset)
  #else
        while (1 == ptr->ipp1->PORTSC1_b.PTRST)
  #endif
        {
            if (timeout > USB_EHCI_TIMEOUT)
            {
                USB_HCI_PRINTF0_R("Error : usb_hstd_ehci_port_enable TIMEOUT\n");

                return FALSE;
            }

            usb_cpu_delay_xms(1);
            timeout++;
        }

  #ifdef USB_CFG_HMSC_USE
        R_BSP_SoftwareDelay(USB_VAL_100, BSP_DELAY_UNITS_MILLISECONDS);
  #else
        R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MILLISECONDS);
  #endif

        result = TRUE;
 #endif                                /* #if USB_NUM_USBIP == 2 */
    }

    return result;
}                                      /* End of function usb_hstd_ehci_port_reset() */

/***********************************************************************************************************************
 * Function     : EHCI Device Disconnect
 * Declaration  : void usb_hstd_ehci_disconnect( uint32_t devadd )
 * Argument     : uint32_t devadd ; device address
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ehci_disconnect (usb_utr_t * ptr, uint32_t devadd)
{
    usb_hstd_ehci_clear_device_trreq(devadd);
    usb_hstd_ehci_clear_device_qh(ptr, devadd);
    usb_hstd_ehci_clear_device_itd(ptr, devadd);
    usb_hstd_ehci_clear_device_sitd(ptr, devadd);
}                                      /* End of function usb_hstd_ehci_disconnect() */

/***********************************************************************************************************************
 * Function     : Getting of Frame list size
 * Declaration  : uint32_t usb_hstd_ehci_get_frame_list_size( void )
 * Argument     : void
 * Return       : uint32_t ; frame list size(1024/512/256)
 * Note         :
 ***********************************************************************************************************************/
uint32_t usb_hstd_ehci_get_frame_list_size (usb_utr_t * ptr)
{
    uint32_t frame_list_size = 0;
    uint32_t data;

 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        data = ptr->ipp->USBCMD_b.FrameListSize;
    }
    else
    {
  #if USB_NUM_USBIP == 2
        data = ptr->ipp1->USBCMD_b.FrameListSize;
  #else
        data = ptr->ipp->USBCMD_b.FrameListSize;
  #endif
    }
 #else
    data = ptr->ipp->USBCMD_b.FLS;
 #endif
    switch (data)
    {
        case 0:
        {
            frame_list_size = USB_VAL_1024;
            break;
        }

        case 1:
        {
            frame_list_size = USB_VAL_512;
            break;
        }

        case 2:
        {
            frame_list_size = USB_VAL_256;
            break;
        }

        default:
        {
            break;
        }
    }

    return frame_list_size;
}                                      /* End of function usb_hstd_ehci_get_frame_list_size() */

/***********************************************************************************************************************
 * Function     : This function is waited for until becoming a specified micro frame number.
 * Declaration  : void usb_hstd_ehci_wait_micro_frame( uint32_t uframe_no )
 * Argument     : uint32_t uframe_no ; micro frame number
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ehci_wait_micro_frame (usb_utr_t * ptr, uint32_t uframe_no)
{
    if (USB_IP0 == ptr->ip)
    {
        while ((ptr->ipp->FRINDEX & 0x00000003) == uframe_no)
        {
            ;
        }
    }
    else
    {
 #if USB_NUM_USBIP == 2
        while ((ptr->ipp1->FRINDEX & 0x00000003) == uframe_no)
        {
            ;
        }
 #endif
    }
}                                      /* End of function usb_hstd_ehci_wait_micro_frame() */

/***********************************************************************************************************************
 * Function     : Add QH to AsyncSchedule
 * Declaration  : void usb_hstd_ehci_add_async( st_usb_ehci_qh_t *qh )
 * Argument     : st_usb_ehci_qh_t *qh ; QH pointer
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ehci_add_async (usb_utr_t * ptr, st_usb_ehci_qh_t * p_qh)
{
    uint32_t           async_list_addr;
    st_usb_ehci_qh_t * p_qh_base;
    st_usb_ehci_qh_t * p_qh_base_temp = 0;
    u_usb_ehci_flep_t  tmp;

    FSP_PARAMETER_NOT_USED(p_qh_base_temp);

    if (USB_IP0 == ptr->ip)
    {
        async_list_addr = ptr->ipp->ASYNCLISTADDR;
    }
    else
    {
 #if USB_NUM_USBIP == 2
        async_list_addr = ptr->ipp1->ASYNCLISTADDR;
 #else
        async_list_addr = ptr->ipp->ASYNCLISTADDR;
 #endif
    }

    if (0x00000000 == async_list_addr)
    {
        USB_HCI_PRINTF0_R("usb_hstd_ehci_add_async Error : ASYNCLISTADDR is not registered. \n");
    }
    else
    {
 #if defined(BSP_MCU_GROUP_RZA_USB)
        p_qh_base = (st_usb_ehci_qh_t *) (r_usb_pa_to_va(async_list_addr));
 #else
        p_qh_base = (st_usb_ehci_qh_t *) async_list_addr;
 #endif
        if (p_qh != p_qh_base)
        {
            /* QH addition */
 #if defined(BSP_MCU_GROUP_RZA_USB)
            tmp.address = (uint32_t) r_usb_pa_to_va(p_qh_base->queue_head_horizontal_link.address);
            tmp.bit.typ = USB_EHCI_TYP_QH;
            p_qh->queue_head_horizontal_link.address = (uint32_t) r_usb_va_to_pa((uint64_t) tmp.address);

            tmp.address = (uint32_t) (r_usb_pa_to_va((uint64_t) p_qh));
            tmp.bit.typ = USB_EHCI_TYP_QH;
            p_qh_base->queue_head_horizontal_link.address = (uint32_t) r_usb_va_to_pa((uint64_t) tmp.address);
 #else
            tmp.address = p_qh_base->queue_head_horizontal_link.address;
            tmp.bit.typ = USB_EHCI_TYP_QH;
            p_qh->queue_head_horizontal_link.address = tmp.address;

            tmp.address = (uint32_t) p_qh;
            tmp.bit.typ = USB_EHCI_TYP_QH;
            p_qh_base->queue_head_horizontal_link.address = tmp.address;
 #endif
        }
        else
        {
            USB_HCI_PRINTF0_R("usb_hstd_ehci_add_async Error : The QH has already been registered. \n");
        }
    }

 #ifdef DEBUG_PRINT_ASYNC_SCHEDULING
    usb_hstd_ehci_print_async_scheduling(NULL);
 #endif
}                                      /* End of function usb_hstd_ehci_add_async() */

/***********************************************************************************************************************
 * Function     : Add QH/ITD/SITD to PeriodicSchedule
 * Declaration  : void usb_hstd_ehci_add_periodic( u_usb_ehci_flep_t *new_element, uint32_t type, uint32_t pollrate, uint32_t pollrate_offset )
 * Argument     : u_usb_ehci_flep_t *new_element   ; QH/ITD/SITD pointer
 *              : uint32_t type            ; element type( QH/ITD/SITD )
 *              : uint32_t pollrate        ; pollrate
 *              : uint32_t pollrate_offset ; pollrate offset
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ehci_add_periodic (usb_utr_t         * ptr,
                                 u_usb_ehci_flep_t * p_new_element,
                                 uint32_t            type,
                                 uint32_t            pollrate,
                                 uint32_t            pollrate_offset)
{
    uint32_t                     frame_list_size;
    uint32_t                     n;
    uint32_t                     periodic_list_addr;
    uint32_t                     pollrate_ms;
    uint32_t                     offset_ms;
    uint32_t                     current_element_pollrate;
    uint32_t                     tmp_addr;
    u_usb_ehci_flep_t          * p_listbase;
    volatile u_usb_ehci_flep_t * p_current_element;
    volatile u_usb_ehci_flep_t   tmp_element;

    if (0 == pollrate)
    {
        USB_HCI_PRINTF0_R("usb_hstd_ehci_add_periodic Error: pollrate = 0\n");

        return;
    }

    if (USB_EHCI_TYP_FSTN == type)
    {
        USB_HCI_PRINTF0_R("usb_hstd_ehci_add_periodic Error: USB_EHCI_TYP_FSTN is not support\n");

        return;
    }

    if (NULL == p_new_element)
    {
        USB_HCI_PRINTF0_R("usb_hstd_ehci_add_periodic Error: Element Pointer is NULL\n");

        return;
    }

    /* Get frame list size */
    frame_list_size = usb_hstd_ehci_get_frame_list_size(ptr);

    if (USB_IP0 == ptr->ip)
    {
        periodic_list_addr = ptr->ipp->PERIODICLISTBASE & USB_VAL_XF000;
    }
    else
    {
 #if USB_NUM_USBIP == 2
        periodic_list_addr = ptr->ipp1->PERIODICLISTBASE & USB_VAL_XF000;
 #else
        periodic_list_addr = ptr->ipp->PERIODICLISTBASE & USB_VAL_XF000;
 #endif
    }

    if (0x00000000 != periodic_list_addr)
    {
 #if defined(BSP_MCU_GROUP_RZA_USB)
        periodic_list_addr = (uint32_t) r_usb_pa_to_va(periodic_list_addr);
 #endif
    }
    else
    {
        USB_HCI_PRINTF0_R("usb_hstd_ehci_add_periodic Error : PERIODICLISTBASE is not registered. \n");

        return;
    }

    offset_ms   = pollrate_offset / 8;
    pollrate_ms = pollrate / 8;
    if (pollrate_ms == 0)
    {
        pollrate_ms = 1;
    }

    /*-----------*/
    /* Interrupt */
    /*-----------*/
    /* The content of the periodic frame list is changed.  */
    /* Attention: In this schedule, the Paul rate should be an involution value of two. */
    p_listbase = (u_usb_ehci_flep_t *) (uintptr_t) periodic_list_addr;
    for (n = offset_ms; n < frame_list_size; n += pollrate_ms)
    {
        p_current_element = &p_listbase[n];

        while (1)
        {
            if (NULL == p_current_element)
            {
                USB_HCI_PRINTF0_R("usb_hstd_ehci_add_periodic Error: Current Element Pointer is NULL\n");

                return;
            }

            /* If T bit is 1, the new element is added. */
            if (1 == p_current_element->bit.t)
            {
                p_new_element->address = 0x00000001;
 #if defined(BSP_MCU_GROUP_RZA_USB)
                tmp_element.address = (uint32_t) r_usb_va_to_pa((uint64_t) p_new_element);
 #else
                tmp_element.address = (uint32_t) p_new_element;
 #endif
                tmp_element.bit.typ = type & 0x00000003U;
                *p_current_element  = tmp_element;
                break;
            }

 #if defined(BSP_MCU_GROUP_RZA_USB)
            tmp_addr = (uint32_t) r_usb_pa_to_va((uint64_t) (p_current_element->address & USB_VAL_XFFE0));
 #else
            tmp_addr = p_current_element->address & USB_VAL_XFFE0;
 #endif

            /* If a current element is the same as the new element, loop termination.  */
            if (tmp_addr == (uint32_t) (uintptr_t) p_new_element)
            {
                break;
            }

            /* The paulrate of a current element is acquired. */
            switch (p_current_element->bit.typ)
            {
                case USB_EHCI_TYP_ITD:
                {
                    current_element_pollrate = ((st_usb_ehci_itd_t *) (uintptr_t) tmp_addr)->info.pollrate;
                    break;
                }

                case USB_EHCI_TYP_QH:
                {
                    current_element_pollrate = ((st_usb_ehci_qh_t *) (uintptr_t) tmp_addr)->info.pollrate;
                    break;
                }

                case USB_EHCI_TYP_SITD:
                {
                    current_element_pollrate = ((st_usb_ehci_sitd_t *) (uintptr_t) tmp_addr)->info.pollrate;
                    break;
                }

                default:
                {
                    current_element_pollrate = USB_VAL_FFFF;
                    break;
                }
            }

            /* If paulrates are compared, and the value of the new element is large, the new element is added. */
            if (pollrate > current_element_pollrate)
            {
 #if defined(BSP_MCU_GROUP_RZA_USB)
                tmp_element.address = (uint32_t) r_usb_va_to_pa(tmp_addr);
 #else
                tmp_element.address = tmp_addr;
 #endif
                tmp_element.bit.typ = p_current_element->bit.typ;
                *p_new_element      = tmp_element;

 #if defined(BSP_MCU_GROUP_RZA_USB)
                tmp_element.address = (uint32_t) r_usb_va_to_pa((uint64_t) p_new_element);
 #else
                tmp_element.address = (uint32_t) p_new_element;
 #endif
                tmp_element.bit.typ = type & 0x00000003U;
                *p_current_element  = tmp_element;
                break;
            }

            /* It shifts to the next element.  */
 #if defined(BSP_MCU_GROUP_RZA_USB)
            p_current_element =
                (u_usb_ehci_flep_t *) (r_usb_pa_to_va((uint64_t) (p_current_element->address & USB_VAL_XFFE0)));
 #else
            p_current_element = (u_usb_ehci_flep_t *) (p_current_element->address & USB_VAL_XFFE0);
 #endif
        }
    }

 #ifdef DEBUG_PRINT_PERIODIC_SCHEDULING
    usb_hstd_ehci_print_periodec_scheduling_list(ptr);
 #endif
}                                      /* End of function usb_hstd_ehci_add_periodic() */

/***********************************************************************************************************************
 * Function     : Link qTDs
 * Declaration  : void usb_hstd_ehci_link_qtd( st_usb_ehci_qtd_t *qtd1st, st_usb_ehci_qtd_t *qtd2nd )
 * Argument     : st_usb_ehci_qtd_t *qtd1st ; QTD pointer
 *              : st_usb_ehci_qtd_t *qtd2nd ; QTD pointer
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ehci_link_qtd (st_usb_ehci_qtd_t * p_qtd1st, st_usb_ehci_qtd_t * p_qtd2nd)
{
 #if defined(BSP_MCU_GROUP_RZA_USB)
    p_qtd1st->next_qtd.address = (uint32_t) r_usb_va_to_pa((uint64_t) p_qtd2nd);
 #else
    p_qtd1st->next_qtd.address = (uint32_t) p_qtd2nd;
 #endif
    p_qtd1st->alternate_next_qtd.address = p_qtd1st->next_qtd.address;
}                                      /* End of function usb_hstd_ehci_link_qtd() */

/***********************************************************************************************************************
 * Function     : Clear qTDs
 * Declaration  : void usb_hstd_ehci_clear_qtd( st_usb_ehci_qtd_t *qtd_head )
 * Argument     : st_usb_ehci_qtd_t *qtd_head ; QTD head pointer
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ehci_clear_qtd (st_usb_ehci_qtd_t * p_qtd_head)
{
    st_usb_ehci_qtd_t * p_clear_qtd;
    st_usb_ehci_qtd_t * p_next_qtd;

 #if defined(BSP_MCU_GROUP_RZA_USB)
    p_clear_qtd = (st_usb_ehci_qtd_t *) (r_usb_pa_to_va((uint64_t) p_qtd_head));
 #else
    p_clear_qtd = (st_usb_ehci_qtd_t *) p_qtd_head;
 #endif

    while (1)
    {
        if (NULL == p_clear_qtd)
        {
            USB_HCI_PRINTF0_R("usb_hstd_ehci_clear_qtd Error : QTD pointer is NULL. \n");

            return;
        }

        if (1 != p_clear_qtd->next_qtd.bit.t)
        {
 #if defined(BSP_MCU_GROUP_RZA_USB)
            p_next_qtd =
                (st_usb_ehci_qtd_t *) (r_usb_pa_to_va((uint64_t) (p_clear_qtd->next_qtd.address & USB_VAL_XFFE0)));
 #else
            p_next_qtd = (st_usb_ehci_qtd_t *) (p_clear_qtd->next_qtd.address & USB_VAL_XFFE0);
 #endif
            memset(p_clear_qtd, 0, sizeof(st_usb_ehci_qtd_t));
            usb_hstd_ehci_free_qtd(p_clear_qtd);
            p_clear_qtd = p_next_qtd;
        }
        else
        {
            memset(p_clear_qtd, 0, sizeof(st_usb_ehci_qtd_t));
            usb_hstd_ehci_free_qtd(p_clear_qtd);
            break;
        }
    }
}                                      /* End of function usb_hstd_ehci_clear_qtd() */

/***********************************************************************************************************************
 * Function     : Inactive qTDs
 * Declaration  : void usb_hstd_ehci_inactive_qtd( st_usb_ehci_qtd_t *qtd_head )
 * Argument     : st_usb_ehci_qtd_t *qtd_head ; QTD head pointer
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ehci_inactive_qtd (st_usb_ehci_qtd_t * p_qtd_head)
{
    st_usb_ehci_qtd_t * p_clear_qtd;
 #if defined(BSP_MCU_GROUP_RZA_USB)
    p_clear_qtd = (st_usb_ehci_qtd_t *) (r_usb_pa_to_va((uint64_t) p_qtd_head));
 #else
    p_clear_qtd = p_qtd_head;
 #endif

    while (1)
    {
        if (NULL == p_clear_qtd)
        {
            USB_HCI_PRINTF0_R("usb_hstd_ehci_inactive_qtd Error : QTD pointer is NULL. \n");

            return;
        }

        /* Clear active bit */
        p_clear_qtd->transfer_info.bit.status_active = 0;

        if (1 == p_clear_qtd->next_qtd.bit.t)
        {
            break;
        }

 #if defined(BSP_MCU_GROUP_RZA_USB)
        p_clear_qtd =
            (st_usb_ehci_qtd_t *) (r_usb_pa_to_va((uint64_t) (p_clear_qtd->next_qtd.address & USB_VAL_XFFE0)));
 #else
        p_clear_qtd = (st_usb_ehci_qtd_t *) (p_clear_qtd->next_qtd.address & USB_VAL_XFFE0);
 #endif
    }
}                                      /* End of function usb_hstd_ehci_inactive_qtd() */

/***********************************************************************************************************************
 * Function     : Unlink Async-QH( CNT/BULK ) from AsyncList
 * Declaration  : void usb_hstd_ehci_unlink_qh_for_async( st_usb_ehci_qh_t *qh )
 * Argument     : st_usb_ehci_qh_t *qh ; QH pointer
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ehci_unlink_qh_for_async (usb_utr_t * ptr, st_usb_ehci_qh_t * p_qh)
{
    st_usb_ehci_qh_t * p_asynclist;
    st_usb_ehci_qh_t * p_current_element;
    uint32_t           current_contents;
    uint32_t           timeout;

    if (NULL == p_qh)
    {
        return;
    }

    if (USB_IP0 == ptr->ip)
    {
        if ((ptr->ipp->ASYNCLISTADDR & USB_VAL_XFFE0) == 0x00000000)
        {
            USB_HCI_PRINTF0_R("usb_hstd_ehci_unlink_qh_for_async Error : ASYNCLISTADDR is not registered. \n");

            return;
        }
    }
    else
    {
 #if USB_NUM_USBIP == 2
        if ((ptr->ipp1->ASYNCLISTADDR & USB_VAL_XFFE0) == 0x00000000)
        {
            USB_HCI_PRINTF0_R("usb_hstd_ehci_unlink_qh_for_async Error : ASYNCLISTADDR is not registered. \n");

            return;
        }
 #endif
    }

 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        p_asynclist = (st_usb_ehci_qh_t *) (r_usb_pa_to_va((uint64_t) (ptr->ipp->ASYNCLISTADDR & USB_VAL_XFFE0)));
    }
    else
    {
  #if USB_NUM_USBIP == 2
        p_asynclist = (st_usb_ehci_qh_t *) (r_usb_pa_to_va((uint64_t) (ptr->ipp1->ASYNCLISTADDR & USB_VAL_XFFE0)));
  #else
        p_asynclist = (st_usb_ehci_qh_t *) (r_usb_pa_to_va((uint64_t) (ptr->ipp->ASYNCLISTADDR & USB_VAL_XFFE0)));
  #endif
    }
 #else
    p_asynclist = (st_usb_ehci_qh_t *) (ptr->ipp->ASYNCLISTADDR & USB_VAL_XFFE0);
 #endif

    /*-----------------*/
    /* check asynclist */
    /*-----------------*/
    /* When the next link of QH is oneself */
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (((uint32_t) (uintptr_t) p_qh ==
         r_usb_pa_to_va((uint64_t) (p_qh->queue_head_horizontal_link.address & USB_VAL_XFFE0))))
 #else
    if ((uint32_t) p_qh == (p_qh->queue_head_horizontal_link.address & USB_VAL_XFFE0))
 #endif
    {
        /* The termination of the asynchronization schedule is executed */
        if (p_qh != p_asynclist)
        {
            USB_HCI_PRINTF0_R("usb_hstd_ehci_unlink_qh_for_async Error : Illegal case 1\n");

            return;
        }

        /* disable Asynchronous Schedule */
 #if defined(BSP_MCU_GROUP_RZA_USB)
        if (USB_IP0 == ptr->ip)
        {
            ptr->ipp->USBCMD_b.AsynchronousScheduleParkModeEnable = 0;
        }
        else
        {
  #if USB_NUM_USBIP == 2
            ptr->ipp1->USBCMD_b.AsynchronousScheduleParkModeEnable = 0;
  #else
            ptr->ipp->USBCMD_b.AsynchronousScheduleParkModeEnable = 0;
  #endif
        }
 #else
        ptr->ipp->USBCMD_b.ASPME = 0;
 #endif

        /* wait async schedule disabled */
        timeout = 0;
 #if defined(BSP_MCU_GROUP_RZA_USB)
        if (USB_IP0 == ptr->ip)
        {
            while (1 == ptr->ipp->USBSTS_b.PeriodicScheduleStatus)
            {
                if (timeout > USB_EHCI_TIMEOUT)
                {
                    break;
                }

                usb_cpu_delay_xms(1);
                timeout++;
            }
        }
        else
        {
  #if USB_NUM_USBIP == 2
            while (1 == ptr->ipp1->USBSTS_b.PeriodicScheduleStatus)
            {
                if (timeout > USB_EHCI_TIMEOUT)
                {
                    break;
                }

                usb_cpu_delay_xms(1);
                timeout++;
            }
  #else
            while (1 == ptr->ipp->USBSTS_b.PeriodicScheduleStatus)
            {
                if (timeout > USB_EHCI_TIMEOUT)
                {
                    break;
                }

                usb_cpu_delay_xms(1);
                timeout++;
            }
  #endif
        }
 #else
        while (1 == ptr->ipp->USBSTS_b.PSCHSTS)
        {
            if (timeout > USB_EHCI_TIMEOUT)
            {
                break;
            }

            usb_cpu_delay_xms(1);
            timeout++;
        }
 #endif

        if (USB_IP0 == ptr->ip)
        {
            /* clear AsyncSchuedule */
            ptr->ipp->ASYNCLISTADDR = 0;
        }
        else
        {
 #if USB_NUM_USBIP == 2
            /* clear AsyncSchuedule */
            ptr->ipp1->ASYNCLISTADDR = 0;
 #else
            /* clear AsyncSchuedule */
            ptr->ipp->ASYNCLISTADDR = 0;
 #endif
        }

        return;
    }

    /* When you delete qh specified with asynclist by chance */
    if (p_qh == p_asynclist)
    {
        /* The setting of asynclist is changed to the next QH */

 #if defined(BSP_MCU_GROUP_RZA_USB)
        p_asynclist =
            (st_usb_ehci_qh_t *) (r_usb_pa_to_va((uint64_t) (p_asynclist->queue_head_horizontal_link.address &
                                                             USB_VAL_XFFE0)));
 #else
        p_asynclist = (st_usb_ehci_qh_t *) (p_asynclist->queue_head_horizontal_link.address & USB_VAL_XFFE0);
 #endif
    }

    /*---------*/
    /* scan QH */
    /*---------*/
    p_current_element = p_asynclist;
 #if defined(BSP_MCU_GROUP_RZA_USB)
    current_contents =
        (uint32_t) r_usb_pa_to_va((uint64_t) (p_current_element->queue_head_horizontal_link.address & USB_VAL_XFFE0));
 #else
    current_contents = (p_current_element->queue_head_horizontal_link.address & USB_VAL_XFFE0);
 #endif
    while (current_contents != (uint32_t) (uintptr_t) p_asynclist)
    {
        if (1 == p_current_element->queue_head_horizontal_link.bit.t)
        {
            /* The terminal is shown though it is a list of the round loop (This case is usually impossible) */
            USB_HCI_PRINTF0_R("usb_hstd_ehci_unlink_qh_for_async Error : Illegal case 2\n");

            return;
        }

        if (current_contents != (uint32_t) (uintptr_t) p_qh)
        {
 #if defined(BSP_MCU_GROUP_RZA_USB)
            p_current_element =
                (st_usb_ehci_qh_t *) (r_usb_pa_to_va((uint64_t) (p_current_element->queue_head_horizontal_link.address &
                                                                 USB_VAL_XFFE0)));
 #else
            p_current_element =
                (st_usb_ehci_qh_t *) (p_current_element->queue_head_horizontal_link.address & USB_VAL_XFFE0);
 #endif
            if (NULL == p_current_element)
            {
                USB_HCI_PRINTF0_R("usb_hstd_ehci_unlink_qh_for_async Error: Current Element Pointer is NULL\n");

                return;
            }

 #if defined(BSP_MCU_GROUP_RZA_USB)
            current_contents =
                (uint32_t) r_usb_pa_to_va((uint64_t) (p_current_element->queue_head_horizontal_link.address &
                                                      USB_VAL_XFFE0));
 #else
            current_contents = (p_current_element->queue_head_horizontal_link.address & USB_VAL_XFFE0);
 #endif
        }
        else
        {
 #if defined(BSP_MCU_GROUP_RZA_USB)
            p_current_element->queue_head_horizontal_link.address = (uint32_t) r_usb_va_to_pa(
                (uint64_t) p_qh->queue_head_horizontal_link.address);
 #else
            p_current_element->queue_head_horizontal_link.address = p_qh->queue_head_horizontal_link.address;
 #endif
            break;
        }
    }

    /*-----------*/
    /* unlink QH */
    /*-----------*/
    /* doorbell */
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        ptr->ipp->USBCMD_b.InterruptonAsyncAdvanceDoorbell = 1;
    }
    else
    {
  #if USB_NUM_USBIP == 2
        ptr->ipp1->USBCMD_b.InterruptonAsyncAdvanceDoorbell = 1;
  #endif
    }
 #else
    ptr->ipp->USBCMD_b.IAAD = 1;
 #endif

    /* It is necessary to wait here for 1ms */
    usb_cpu_delay_xms(1);
    timeout = 0;
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        while (1 == ptr->ipp->USBSTS_b.InterruptonAsyncAdvance)
        {
            if (timeout > USB_EHCI_TIMEOUT)
            {
                break;
            }

            usb_cpu_delay_xms(1);
            timeout++;
        }
    }
    else
    {
  #if USB_NUM_USBIP == 2
        while (1 == ptr->ipp1->USBSTS_b.InterruptonAsyncAdvance)
        {
            if (timeout > USB_EHCI_TIMEOUT)
            {
                break;
            }

            usb_cpu_delay_xms(1);
            timeout++;
        }
  #endif
    }
 #else
    while (1 == ptr->ipp->USBSTS_b.IAAIS)
    {
        if (timeout > USB_EHCI_TIMEOUT)
        {
            break;
        }

        usb_cpu_delay_xms(1);
        timeout++;
    }
 #endif

    if (USB_IP0 == ptr->ip)
    {
        /* USB00.USBSTS.BIT.InterruptonAsyncAdvance = 1; */
        ptr->ipp->USBSTS &= USB_VAL_1F020;
    }
    else
    {
 #if USB_NUM_USBIP == 2
        /* USB00.USBSTS.BIT.InterruptonAsyncAdvance = 1; */
        ptr->ipp1->USBSTS &= USB_VAL_1F020;
 #endif
    }

 #ifdef DEBUG_PRINT_ASYNC_SCHEDULING
    usb_hstd_ehci_print_async_scheduling(NULL);
 #endif
}                                      /* End of function usb_hstd_ehci_unlink_qh_for_async() */

/***********************************************************************************************************************
 * Function     : Unlink Periodic-QH( INT ) from Periodic Frame List
 * Declaration  : void usb_hstd_ehci_unlink_qh_for_periodic( st_usb_ehci_qh_t *qh )
 * Argument     : st_usb_ehci_qh_t *qh ; QH pointer
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ehci_unlink_qh_for_periodic (usb_utr_t * ptr, st_usb_ehci_qh_t * p_qh)
{
    uint32_t n;
    uint32_t frame_list_size;
    uint32_t max_period;

    if (p_qh == NULL)
    {
        return;
    }

    /* Get frame list size */
    frame_list_size = usb_hstd_ehci_get_frame_list_size(ptr);

    /* unlink qh */
    for (n = 0; n < frame_list_size; n++)
    {
        usb_hstd_ehci_unlink_periodic(ptr, &p_qh->queue_head_horizontal_link, n);
    }

 #ifdef DEBUG_PRINT_PERIODIC_SCHEDULING
    usb_hstd_ehci_print_periodec_scheduling_list(ptr);
 #endif

    if (p_qh->info.pollrate != 0)
    {
        if (p_qh->endpoint1.bit.eps == USB_HCI_DEVSPEED_HS)
        {
            max_period = 1;
        }
        else
        {
            /* The maximum term of 5 frames is set for the split transaction of the interrupt forwarding */
            max_period = 5;
        }

        usb_hstd_ehci_delete_periodec_scheduling_score(ptr,
                                                       max_period,
                                                       p_qh->info.pollrate,
                                                       p_qh->info.pollrate_offset);
    }
}                                      /* End of function usb_hstd_get_rootport() */

/***********************************************************************************************************************
 * Function     : Unlink Periodic-ITD( HS-ISO ) from Periodic Frame List
 * Declaration  : void usb_hstd_ehci_unlink_itd( st_usb_ehci_itd_t *itd )
 * Argument     : st_usb_ehci_itd_t *itd ; ITD pointer
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ehci_unlink_itd (usb_utr_t * ptr, st_usb_ehci_itd_t * p_itd)
{
    uint32_t n;
    uint32_t frame_list_size;
    uint32_t max_period;

    if (NULL == p_itd)
    {
        return;
    }

    /* Get frame list size */
    frame_list_size = usb_hstd_ehci_get_frame_list_size(ptr);

    /* unlink itd */
    for (n = 0; n < frame_list_size; n++)
    {
        usb_hstd_ehci_unlink_periodic(ptr, &p_itd->next_link, n);
    }

 #ifdef DEBUG_PRINT_PERIODIC_SCHEDULING
    usb_hstd_ehci_print_periodec_scheduling_list(ptr);
 #endif

    if (0 != p_itd->info.pollrate)
    {
        max_period = 1;
        usb_hstd_ehci_delete_periodec_scheduling_score(ptr,
                                                       max_period,
                                                       p_itd->info.pollrate,
                                                       p_itd->info.pollrate_offset);
    }
}                                      /* End of function usb_hstd_ehci_unlink_itd() */

/***********************************************************************************************************************
 * Function     : Unlink Periodic-SITD( FS-ISO ) from Periodic Frame List
 * Declaration  : void usb_hstd_ehci_unlink_sitd( st_usb_ehci_sitd_t *sitd )
 * Argument     : st_usb_ehci_sitd_t *sitd ; SITD pointer
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ehci_unlink_sitd (usb_utr_t * ptr, st_usb_ehci_sitd_t * p_sitd)
{
    uint32_t n;
    uint32_t frame_list_size;
    uint32_t max_period;

    if (NULL == p_sitd)
    {
        return;
    }

    /* Get frame list size */
    frame_list_size = usb_hstd_ehci_get_frame_list_size(ptr);

    /* unlink sitd */
    for (n = 0; n < frame_list_size; n++)
    {
        usb_hstd_ehci_unlink_periodic(ptr, &p_sitd->next_link, n);
    }

 #ifdef DEBUG_PRINT_PERIODIC_SCHEDULING
    usb_hstd_ehci_print_periodec_scheduling_list(ptr);
 #endif

    if (0 != p_sitd->info.pollrate)
    {
        /* The number of micro frames necessary for transfer is calculated */
        max_period = (p_sitd->mps + USB_EHCI_SITD_DATA_SIZE - 1) / USB_EHCI_SITD_DATA_SIZE;

        if (USB_HCI_DIRECTION_IN == p_sitd->info.direction)
        {
            /* The IN transfer adds 2 micro frame */
            max_period += 2;
        }

        usb_hstd_ehci_delete_periodec_scheduling_score(ptr,
                                                       max_period,
                                                       p_sitd->info.pollrate,
                                                       p_sitd->info.pollrate_offset);
    }
}                                      /* End of function usb_hstd_ehci_unlink_sitd() */

/***********************************************************************************************************************
 * Function     : Update Periodeic Scheuling Score
 * Declaration  : uint32_t usb_hstd_ehci_update_periodic_scheduling_score( uint32_t max_period, uint32_t pollrate )
 * Argument     : uint32_t max_period ; max period
 *              : uint32_t pollrate   ; pollrate
 * Return       : uint32_t            ; pollrate offset
 * Note         :
 ***********************************************************************************************************************/
uint32_t usb_hstd_ehci_update_periodic_scheduling_score (usb_utr_t * ptr, uint32_t max_period, uint32_t pollrate)
{
    uint32_t uframe_list_size;
    uint32_t n;
    uint32_t i;
    uint32_t j;
    uint32_t score;
    uint32_t score_min;
    uint32_t score_min_n     = 0;
    uint32_t pollrate_offset = 0;

    /* Get micro frame list size */
    uframe_list_size  = usb_hstd_ehci_get_frame_list_size(ptr);
    uframe_list_size *= 8;

    /* Search for minimum score */
    score_min = USB_VAL_FFFF;
    for (n = 0; n < pollrate; )
    {
        /* Acquisition of score */
        score = 0;
        for (j = 0; j < max_period; j++)
        {
            for (i = n + j; i < uframe_list_size; i += pollrate)
            {
                score += gs_usb_ehci_periodic_scheduling_score[i];
            }
        }

        if (score_min > score)
        {
            /* Because a minimum score at present was found, the value is kept */
            score_min   = score;
            score_min_n = n;
        }

        if (0 == score_min)
        {
            /* Because minimum score 0 was found, it ends here */
            break;
        }

        if (1 == max_period)
        {
            n++;
        }
        else
        {
            /* The split transaction that steps over the frame is not scheduled */
            if ((n % 8) == (8 - max_period))
            {
                n += max_period;
            }
            else
            {
                n++;
            }
        }
    }

    if (0 != pollrate)
    {
        pollrate_offset = score_min_n % pollrate;
    }

    /* Update Score */
    for (n = pollrate_offset; n < uframe_list_size; n += pollrate)
    {
        for (j = 0; j < max_period; j++)
        {
            gs_usb_ehci_periodic_scheduling_score[n + j]++;
        }
    }

 #ifdef DEBUG_PRINT_PERIODIC_SCHEDULING
    usb_hstd_ehci_print_periodic_scheduling_score();
 #endif

    return pollrate_offset;
}                                      /* End of function usb_hstd_get_rootport() */

/***********************************************************************************************************************
 * Function     : EHCI Transfer End Interrupt Handler
 * Declaration  : void usb_hstd_ehci_int_transfer_end( void )
 * Argument     : void
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ehci_int_transfer_end (usb_utr_t * ptr)
{
    st_usb_hci_tr_req_t * p_tr_req;
    st_usb_ehci_qh_t    * p_qh;
    st_usb_ehci_itd_t   * p_itd;
    st_usb_ehci_sitd_t  * p_sitd;
    uint32_t              i;
    uint8_t               error_status;
    st_usb_ehci_qtd_t   * tmp_qtd_end;
    st_usb_ehci_qtd_t   * p_qtd_address;

    p_tr_req = &g_usb_hstd_hci_transfer_request[0];
    for (i = 0; i < USB_HCI_TRREQ_NUM; i++, p_tr_req++)
    {
        if (TRUE == p_tr_req->bit.enable)
        {
            if (NULL == p_tr_req->devinfo)
            {
                continue;
            }

            if (USB_HCI_HCTYPE_EHCI == p_tr_req->devinfo->bit.hctype)
            {
 #if defined(BSP_MCU_GROUP_RZA_USB)
                if (0 != (r_usb_pa_to_va((uint64_t) p_tr_req->hci_info)))
 #else
                if (NULL != p_tr_req->hci_info)
 #endif
                {
                    if (USB_EP_ISO == p_tr_req->bit.eptype)
                    {
                        /* for isochronous */
                        if (USB_HCI_DEVSPEED_HS == p_tr_req->devinfo->bit.devspeed)
                        {
 #if defined(BSP_MCU_GROUP_RZA_USB)
                            p_itd = (st_usb_ehci_itd_t *) (r_usb_pa_to_va((uint64_t) p_tr_req->hci_info));
 #else
                            p_itd = (st_usb_ehci_itd_t *) p_tr_req->hci_info;
 #endif
                            if (TRUE == p_itd->info.tr_req_flag)
                            {
                                /* check status */
                                if (1 == p_itd->transaction[p_itd->next_trend_uframe].bit.status_data_buffer_error)
                                {
                                    USB_HCI_PRINTF1_R("Error ITD(%d): Data Buffer Error\n", p_tr_req->bit.devadrs);
                                }

                                if (1 == p_itd->transaction[p_itd->next_trend_uframe].bit.status_babble_detected)
                                {
                                    USB_HCI_PRINTF1_R("Error ITD(%d): Babble Detected\n", p_tr_req->bit.devadrs);
                                }

                                if (1 == p_itd->transaction[p_itd->next_trend_uframe].bit.status_transaction_error)
                                {
                                    USB_HCI_PRINTF1_R("Error ITD(%d): Transaction Error\n", p_tr_req->bit.devadrs);
                                }

                                /* High-speed isochronous */
                                if (0 == p_itd->transaction[p_itd->next_trend_uframe].bit.status_active)
                                {
                                    usb_hstd_ehci_transfer_end_itd(ptr, p_tr_req);
                                }
                            }
                        }
                        else
                        {
 #if defined(BSP_MCU_GROUP_RZA_USB)
                            p_sitd = (st_usb_ehci_sitd_t *) (r_usb_pa_to_va((uint64_t) p_tr_req->hci_info));
 #else
                            p_sitd = (st_usb_ehci_sitd_t *) p_tr_req->hci_info;
 #endif
                            if (TRUE == p_sitd->info.tr_req_flag)
                            {
                                /* check status */
                                if (1 == p_sitd->state.bit.status_err)
                                {
                                    USB_HCI_PRINTF1_R("Error SITD(%d): ERR Respons\n", p_tr_req->bit.devadrs);
                                }

                                if (1 == p_sitd->state.bit.status_data_buffer_error)
                                {
                                    USB_HCI_PRINTF1_R("Error SITD(%d): Data Buffer Error\n", p_tr_req->bit.devadrs);
                                }

                                if (1 == p_sitd->state.bit.status_babble_detected)
                                {
                                    USB_HCI_PRINTF1_R("Error SITD(%d): Babble Detected\n", p_tr_req->bit.devadrs);
                                }

                                if (1 == p_sitd->state.bit.status_transaction_error)
                                {
                                    USB_HCI_PRINTF1_R("Error SITD(%d): Transaction Error\n", p_tr_req->bit.devadrs);
                                }

                                if (1 == p_sitd->state.bit.status_missed_micro_frame)
                                {
                                    /*  USB_HCI_PRINTF1_R("Error SITD(%d): Missed Micro Frame\n", p_tr_req->bit.devadrs); */
                                }

                                /* Full-speed isochronous( Split transaction ) */
                                if ((1 == p_sitd->state.bit.ioc) && (0 == p_sitd->state.bit.status_active))
                                {
                                    usb_hstd_ehci_transfer_end_sitd(ptr, p_tr_req);
                                }
                            }
                        }
                    }
                    else
                    {
                        /* Error Status Clear */
                        error_status = 0x00;

                        /* for interrupt/control/bulk */
 #if defined(BSP_MCU_GROUP_RZA_USB)
                        p_qh        = (st_usb_ehci_qh_t *) (r_usb_pa_to_va((uint64_t) p_tr_req->hci_info));
                        tmp_qtd_end = (st_usb_ehci_qtd_t *) (r_usb_pa_to_va((uint64_t) (p_qh->qtd_end)));
 #else
                        p_qh        = (st_usb_ehci_qh_t *) p_tr_req->hci_info;
                        tmp_qtd_end = (st_usb_ehci_qtd_t *) p_qh->qtd_end;
 #endif
                        if (TRUE == p_qh->info.tr_req_flag)
                        {
                            /* check status */
                            if (3 != p_qh->transfer_info.bit.cerr)
                            {
                                if (0 == p_qh->transfer_info.bit.cerr)
                                {
                                    error_status |= 0x01;
                                }

                                USB_HCI_PRINTF2_R("Error QH(%d): CERR=%d\n",
                                                  p_tr_req->bit.devadrs,
                                                  p_qh->transfer_info.bit.cerr);
                            }

                            if (1 == p_qh->transfer_info.bit.status_halted)
                            {
                                error_status |= 0x02;
                                USB_HCI_PRINTF1_R("Error QH(%d): Halted\n", p_tr_req->bit.devadrs);
                            }

                            if (1 == p_qh->transfer_info.bit.status_data_buffer_error)
                            {
                                error_status |= 0x04;
                                USB_HCI_PRINTF1_R("Error QH(%d): Data Buffer Error\n", p_tr_req->bit.devadrs);
                            }

                            if (1 == p_qh->transfer_info.bit.status_babble_detected)
                            {
                                error_status |= 0x08;
                                USB_HCI_PRINTF1_R("Error QH(%d): Babble Detected\n", p_tr_req->bit.devadrs);
                            }

                            if (1 == p_qh->transfer_info.bit.status_transaction_error)
                            {
                                error_status |= 0x10;
                                USB_HCI_PRINTF1_R("Error QH(%d): Transaction Error\n", p_tr_req->bit.devadrs);
                                p_tr_req->bit.enable = FALSE;
                            }

                            if (1 == p_qh->transfer_info.bit.status_missed_micro_frame)
                            {
                                /* USB_HCI_PRINTF1_R("Error QH(%d): Missed Micro Frame\n", p_tr_req->bit.devadrs); */
                            }

                            if (1 == p_qh->transfer_info.bit.status_halted)
                            {
                                /* Transfer completion when abnormality operating */
                                usb_hstd_ehci_transfer_end_qh(ptr, p_tr_req);
                            }
                            else if ((1 == tmp_qtd_end->transfer_info.bit.ioc) &&
                                     (0 == tmp_qtd_end->transfer_info.bit.status_active))
                            {
                                /* Transfer completion when normality operating */
                                usb_hstd_ehci_transfer_end_qh(ptr, p_tr_req);
                            }
                            else if (0x00 != error_status)
                            {
 #if defined(BSP_MCU_GROUP_RZA_USB)
                                p_qtd_address = (st_usb_ehci_qtd_t *) (uintptr_t) p_qh->current_qtd.address;

                                /* Error Check */
                                if (0 == p_qtd_address->transfer_info.bit.status_active)
 #else
                                if (0 == p_qh->current_qtd.pointer->transfer_info.bit.status_active)
 #endif
                                {
                                    USB_HCI_PRINTF2_R("Error QH(%d): Error Stop! Error Status=0x%x\n",
                                                      p_tr_req->bit.devadrs,
                                                      error_status);
                                    usb_hstd_ehci_transfer_end_qh(ptr, p_tr_req);
                                }
                            }
                            else
                            {
                                /* None */
                            }
                        }
                        else           /* No transfer request flag */
                        {
                            if (TRUE == p_tr_req->bit.enable)
                            {
                                /* clear usage flag in g_usb_hstd_hci_transfer_request */
                                p_tr_req->bit.enable = FALSE;
                            }
                        }
                    }
                }
            }
        }
    }
}                                      /* End of function usb_hstd_ehci_int_transfer_end() */

/***********************************************************************************************************************
 * Function     : EHCI Port Change Interrupt Handler
 * Declaration  : void usb_hstd_ehci_int_port_change( void )
 * Argument     : void
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ehci_int_port_change (usb_utr_t * ptr)
{
    st_usb_hci_device_t * p_devinfo;
    uint32_t              connect_flag;
    uint32_t              hs_enable_flag;
    uint32_t              count;
    uint32_t              portsc1_save;

 #ifdef DEBUG_PRINT_PORT_INFOMATION
    usb_hstd_ehci_print_port_information(ptr);
 #endif
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        if (1 == ptr->ipp->PORTSC1_b.PortOwner)
        {
            return;
        }
    }
    else
    {
  #if USB_NUM_USBIP == 2
        if (1 == ptr->ipp1->PORTSC1_b.PortOwner)
        {
            return;
        }
  #endif
    }
 #else
    if (1 == ptr->ipp->PORTSC1_b.PTOWNR)
    {
        return;
    }
 #endif

 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        if (1 == ptr->ipp->PORTSC1_b.OvercurrentChange)
        {
            if (1 == ptr->ipp->PORTSC1_b.OvercurrentActive)
            {
                /* over current callback */
                g_usb_hstd_hci_callback.over_current_cb(ptr);
            }
        }

        if (1 == ptr->ipp->PORTSC1_b.PortEnable_DisableChange)
        {
            if (1 == ptr->ipp->PORTSC1_b.PortEnabled_Disabled)
            {
                /* port enable */
            }
            else
            {
                /* port disable */
            }
        }
    }
    else
    {
  #if USB_NUM_USBIP == 2
        if (1 == ptr->ipp1->PORTSC1_b.OvercurrentChange)
        {
            if (1 == ptr->ipp1->PORTSC1_b.OvercurrentActive)
            {
                /* over current callback */
                g_usb_hstd_hci_callback.over_current_cb(ptr);
            }
        }

        if (1 == ptr->ipp1->PORTSC1_b.PortEnable_DisableChange)
        {
            if (1 == ptr->ipp1->PORTSC1_b.PortEnabled_Disabled)
            {
                /* port enable */
            }
            else
            {
                /* port disable */
            }
        }
  #endif                               /* #if USB_NUM_USBIP == 2 */
    }
 #else
    if (1 == ptr->ipp->PORTSC1_b.OVCC)
    {
        if (1 == ptr->ipp->PORTSC1_b.OVCACT)
        {
            /* over current callback */
            g_usb_hstd_hci_callback.over_current_cb(ptr);
        }
    }

    if (1 == ptr->ipp->PORTSC1_b.PTESC)
    {
        if (1 == ptr->ipp->PORTSC1_b.PTE)
        {
            /* port enable */
        }
        else
        {
            /* port disable */
        }
    }
 #endif

 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        if (1 == ptr->ipp->PORTSC1_b.ConnectStatusChange)
        {
            /* Here is waited for until Current_Connect_Status is fixed */
            count = 0;
            while (count < 11)
            {
                connect_flag = ptr->ipp->PORTSC1_b.CurrentConnectStatus;

                usb_cpu_delay_xms(10);
                if (connect_flag == ptr->ipp->PORTSC1_b.CurrentConnectStatus)
                {
                    count++;
                }
                else
                {
                    count = 0;
                }
            }

            if ((0 == g_usb_port_status[ptr->ip][0]) && (0 == g_usb_port_status[ptr->ip][1]))
            {
                if (USB_HCI_NODEVICE != gs_usb_ehci_root_device_address[ptr->ip])
                {
                    r_usb_hstd_hci_disconnect(ptr, gs_usb_ehci_root_device_address[ptr->ip]);
                    gs_usb_ehci_root_device_address[ptr->ip] = USB_HCI_NODEVICE;

                    /* detach callback */
                    g_usb_hstd_hci_callback.detach_cb(ptr);
                }
            }
            else
            {
                if (USB_HCI_NODEVICE != gs_usb_ehci_root_device_address[ptr->ip])
                {
                    r_usb_hstd_hci_disconnect(ptr, gs_usb_ehci_root_device_address[ptr->ip]);
                    gs_usb_ehci_root_device_address[ptr->ip] = USB_HCI_NODEVICE;
                    g_usb_hstd_mgr_mode[ptr->ip]             = USB_DETACHED;
                }

                if (TRUE == usb_hstd_ehci_port_enable(ptr, &hs_enable_flag))
                {
                    if (TRUE == hs_enable_flag)
                    {
                        /* For an enable port */
                        p_devinfo = usb_hstd_hci_alloc_dev_info();
                        if (NULL != p_devinfo)
                        {
                            p_devinfo->bit.devnum = 0;
                            gs_usb_ehci_root_device_address[ptr->ip] = p_devinfo->bit.devnum;
                            p_devinfo->bit.devspeed = USB_HCI_DEVSPEED_HS;
                            p_devinfo->bit.hctype   = USB_HCI_HCTYPE_EHCI;

                            /* attach callback */
                            g_usb_hstd_hci_callback.attach_cb(ptr);
                        }
                    }
                    else
                    {
                        /* The port owner is changed to OHCI in case of the port disable */
                        /* ptr->ipp.PORTSC1.BIT.PortOwner = 1; */  /* Port Owner : OHCI */
                        portsc1_save      = ptr->ipp->PORTSC1;
                        ptr->ipp->PORTSC1 = USB_VAL_X2000 | (portsc1_save & USB_VAL_XFFD5);

                        usb_cpu_delay_xms(USB_VAL_50);
                    }
                }
            }
        }
    }
    else
    {
  #if USB_NUM_USBIP == 2
        if (1 == ptr->ipp1->PORTSC1_b.ConnectStatusChange)
        {
            /* Here is waited for until Current_Connect_Status is fixed */
            count = 0;
            while (count < 11)
            {
                connect_flag = ptr->ipp1->PORTSC1_b.CurrentConnectStatus;

                usb_cpu_delay_xms(10);
                if (connect_flag == ptr->ipp1->PORTSC1_b.CurrentConnectStatus)
                {
                    count++;
                }
                else
                {
                    count = 0;
                }
            }

            if ((0 == g_usb_port_status[ptr->ip][0]) && (0 == g_usb_port_status[ptr->ip][1]))
            {
                if (USB_HCI_NODEVICE != gs_usb_ehci_root_device_address[ptr->ip])
                {
                    r_usb_hstd_hci_disconnect(ptr, gs_usb_ehci_root_device_address[ptr->ip]);
                    gs_usb_ehci_root_device_address[ptr->ip] = USB_HCI_NODEVICE;

                    /* detach callback */
                    g_usb_hstd_hci_callback.detach_cb(ptr);
                }
            }
            else
            {
                if (USB_HCI_NODEVICE != gs_usb_ehci_root_device_address[ptr->ip])
                {
                    r_usb_hstd_hci_disconnect(ptr, gs_usb_ehci_root_device_address[ptr->ip]);
                    gs_usb_ehci_root_device_address[ptr->ip] = USB_HCI_NODEVICE;
                }

                if (TRUE == usb_hstd_ehci_port_enable(ptr, &hs_enable_flag))
                {
                    if (TRUE == hs_enable_flag)
                    {
                        /* For an enable port */
                        p_devinfo = usb_hstd_hci_alloc_dev_info();
                        if (NULL != p_devinfo)
                        {
                            p_devinfo->bit.devnum = 0;
                            gs_usb_ehci_root_device_address[ptr->ip] = p_devinfo->bit.devnum;
                            p_devinfo->bit.devspeed = USB_HCI_DEVSPEED_HS;
                            p_devinfo->bit.hctype   = USB_HCI_HCTYPE_EHCI;

                            /* attach callback */
                            g_usb_hstd_hci_callback.attach_cb(ptr);
                        }
                    }
                    else
                    {
                        /* The port owner is changed to OHCI in case of the port disable */
                        /* ptr->ipp1.PORTSC1.BIT.PortOwner = 1; */  /* Port Owner : OHCI */
                        portsc1_save       = ptr->ipp1->PORTSC1;
                        ptr->ipp1->PORTSC1 = USB_VAL_X2000 | (portsc1_save & USB_VAL_XFFD5);

                        usb_cpu_delay_xms(USB_VAL_50);
                    }
                }
            }
        }
  #endif                               /* #if USB_NUM_USBIP == 2 */
    }
 #else
    if (1 == ptr->ipp->PORTSC1_b.CSC)
    {
        /* Here is waited for until Current_Connect_Status is fixed */
        count = 0;
        while (count < 11)
        {
            connect_flag = ptr->ipp->PORTSC1_b.CCSTS;
            usb_cpu_delay_xms(10);
            if (connect_flag == ptr->ipp->PORTSC1_b.CCSTS)
            {
                count++;
            }
            else
            {
                count = 0;
            }
        }

        if ((0 == ptr->ipp->PORTSC1_b.CCSTS) && (0 == ptr->ipp->PORTSC1_b.PTOWNR))
        {
            if (USB_HCI_NODEVICE != gs_usb_ehci_root_device_address[ptr->ip])
            {
                r_usb_hstd_hci_disconnect(ptr, gs_usb_ehci_root_device_address[ptr->ip]);
                gs_usb_ehci_root_device_address[ptr->ip] = USB_HCI_NODEVICE;

                /* detach callback */
                g_usb_hstd_hci_callback.detach_cb(ptr);
            }
        }
        else
        {
            if (USB_HCI_NODEVICE != gs_usb_ehci_root_device_address[ptr->ip])
            {
                r_usb_hstd_hci_disconnect(ptr, gs_usb_ehci_root_device_address[ptr->ip]);
                gs_usb_ehci_root_device_address[ptr->ip] = USB_HCI_NODEVICE;
            }

            if (TRUE == usb_hstd_ehci_port_enable(ptr, &hs_enable_flag))
            {
                if (TRUE == hs_enable_flag)
                {
                    /* For an enable port */
                    p_devinfo = usb_hstd_hci_alloc_dev_info();
                    if (NULL != p_devinfo)
                    {
                        p_devinfo->bit.devnum = 0;
                        gs_usb_ehci_root_device_address[ptr->ip] = p_devinfo->bit.devnum;
                        p_devinfo->bit.devspeed = USB_HCI_DEVSPEED_HS;
                        p_devinfo->bit.hctype   = USB_HCI_HCTYPE_EHCI;

                        /* attach callback */
                        g_usb_hstd_hci_callback.attach_cb(ptr);
                    }
                }
                else
                {
                    /* The port owner is changed to OHCI in case of the port disable */
                    /* ptr->ipp.PORTSC1.BIT.PortOwner = 1; */  /* Port Owner : OHCI */
                    portsc1_save      = ptr->ipp->PORTSC1;
                    ptr->ipp->PORTSC1 = USB_VAL_X2000 | (portsc1_save & USB_VAL_XFFD5);

                    usb_cpu_delay_xms(USB_VAL_50);
                }
            }
        }
    }
 #endif
}                                      /* End of function usb_hstd_ehci_int_port_change() */

/***********************************************************************************************************************
 * Function     :
 * Declaration  : uint32_t usb_hstd_ehci_get_port_current_connect_status( uint16_t rootport )
 * Argument     : uint16_t rootport ; rootport no
 * Return       : uint32_t          ; Current Connect Status( 1:Connected, 0:Not Connect );
 * Note         :
 ***********************************************************************************************************************/
uint32_t usb_hstd_ehci_get_port_current_connect_status (usb_utr_t * ptr)
{
    uint32_t n_ports;
    uint32_t status = 0;

    if (USB_IP0 == ptr->ip)
    {
        n_ports = ptr->ipp->HCSPARAMS_b.N_PORTS;
    }
    else
    {
 #if USB_NUM_USBIP == 2
        n_ports = ptr->ipp1->HCSPARAMS_b.N_PORTS;
 #else
        n_ports = ptr->ipp->HCSPARAMS_b.N_PORTS;
 #endif
    }

    if (ptr->ip >= n_ports)
    {
        return 0;
    }

 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        status  = ptr->ipp->PORTSC1_b.CurrentConnectStatus;
        status |= ptr->ipp->PORTSC1_b.PortOwner;
    }
    else
    {
  #if USB_NUM_USBIP == 2
        status  = ptr->ipp1->PORTSC1_b.CurrentConnectStatus;
        status |= ptr->ipp1->PORTSC1_b.PortOwner;
  #endif
    }
 #else
    status  = ptr->ipp->PORTSC1_b.CCSTS;
    status |= ptr->ipp->PORTSC1_b.PTOWNR;
 #endif

    return status;
}                                      /* End of function usb_hstd_ehci_get_port_current_connect_status() */

/***********************************************************************************************************************
 * Function     : EHCI Clear Enumalation Wait Flag
 * Declaration  : void usb_hstd_ehci_clear_enumalation_wait_flag( void )
 * Argument     : void
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ehci_clear_enumalation_wait_flag (void)
{
}                                      /* End of function usb_hstd_ehci_clear_enumalation_wait_flag() */

/***********************************************************************************************************************
 * Function     : EHCI Interrupt Handler
 * Declaration  : void usb_hstd_ehci_interrupt_handler( void )
 * Argument     : void
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ehci_interrupt_handler (usb_utr_t * ptr)
{
    if (USB_IP0 == ptr->ip)
    {
        if ((0 != ptr->ipp->USBSTS) && (0 != ptr->ipp->USBINTR))
        {
 #if defined(BSP_MCU_GROUP_RZA_USB)
            if ((1 == ptr->ipp->USBSTS_b.HostSystemError) && (1 == ptr->ipp->USBINTR_b.HostSystemErrorEnable))
            {
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_HOST_SYSTEM_ERROR, 0, 0, 0);

                /* ptr->ipp.USBSTS.BIT.HostSystemError = 1; */
                ptr->ipp->USBSTS &= USB_VAL_1F010;
            }
 #else
            if ((1 == ptr->ipp->USBSTS_b.HSYSE) && (1 == ptr->ipp->USBINTR_b.HSEE))
            {
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_HOST_SYSTEM_ERROR, 0, 0, 0);

                /* ptr->ipp->USBSTS_b.HSYSE = 1; */
                ptr->ipp->USBSTS &= USB_VAL_1F010;
            }
 #endif
 #if defined(BSP_MCU_GROUP_RZA_USB)
            if ((1 == ptr->ipp->USBSTS_b.PortChangeDetect) && (1 == ptr->ipp->USBINTR_b.PortChangeDetectEnable))
            {
                g_usb_port_status[ptr->ip][0] = ptr->ipp->PORTSC1_b.CurrentConnectStatus;
                g_usb_port_status[ptr->ip][1] = ptr->ipp->PORTSC1_b.PortOwner;
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_PORT_CHANGE_DETECT, 0, 0, 0);

                /* ptr->ipp.USBSTS.BIT.PortChangeDetect = 1; */
                ptr->ipp->USBSTS &= USB_VAL_1F004;
            }
 #else
            if ((1 == ptr->ipp->USBSTS_b.PTCGDET) && (1 == ptr->ipp->USBINTR_b.PTCGIE))
            {
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_PORT_CHANGE_DETECT, 0, 0, 0);

                /* ptr->ipp->USBSTS_b.PTCGDET = 1; */
                ptr->ipp->USBSTS &= USB_VAL_1F004;
            }
 #endif
 #if defined(BSP_MCU_GROUP_RZA_USB)
            if ((1 == ptr->ipp->USBSTS_b.USBERRINT) && (1 == ptr->ipp->USBINTR_b.USBErrorInterruptEnable))
            {
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_USBERRINT, 0, 0, 0);

                /* ptr->ipp.USBSTS.BIT.USBERRINT = 1; */
                ptr->ipp->USBSTS &= USB_VAL_1F002;
            }
 #else
            if ((1 == ptr->ipp->USBSTS_b.USBERRINT) && (1 == ptr->ipp->USBINTR_b.USBEIE))
            {
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_USBERRINT, 0, 0, 0);

                /* ptr->ipp->USBSTS_b.USBERRINT = 1; */
                ptr->ipp->USBSTS &= USB_VAL_1F002;
            }
 #endif
 #if defined(BSP_MCU_GROUP_RZA_USB)
            if ((1 == ptr->ipp->USBSTS_b.InterruptonAsyncAdvance) &&
                (1 == ptr->ipp->USBINTR_b.InterruptonAsyncAdvanceEnable))
            {
                usb_hstd_hci_send_message_from_int(ptr,
                                                   USB_HCI_TASK,
                                                   USB_HCI_MESS_EHCI_INTERRUPT_ON_ASYNC_ADVANCE,
                                                   0,
                                                   0,
                                                   0);

                /* ptr->ipp.USBSTS.BIT.InterruptonAsyncAdvance = 1; */
                ptr->ipp->USBSTS &= USB_VAL_1F020;
            }
 #else
            if ((1 == ptr->ipp->USBSTS_b.IAAIS) && (1 == ptr->ipp->USBINTR_b.INTAADVE))
            {
                usb_hstd_hci_send_message_from_int(ptr,
                                                   USB_HCI_TASK,
                                                   USB_HCI_MESS_EHCI_INTERRUPT_ON_ASYNC_ADVANCE,
                                                   0,
                                                   0,
                                                   0);

                /* ptr->ipp->USBSTS_b.IAAIS = 1; */
                ptr->ipp->USBSTS &= USB_VAL_1F020;
            }
 #endif
 #if defined(BSP_MCU_GROUP_RZA_USB)
            if ((1 == ptr->ipp->USBSTS_b.FrameListRollover) && (1 == ptr->ipp->USBINTR_b.FrameListRolloverEnable))
            {
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_FRAME_LIST_ROLLOVER, 0, 0, 0);

                /* ptr->ipp.USBSTS.BIT.FrameListRollover = 1; */
                ptr->ipp->USBSTS &= USB_VAL_1F008;
            }
 #else
            if ((1 == ptr->ipp->USBSTS_b.FLROV) && (1 == ptr->ipp->USBINTR_b.FMLSTROE))
            {
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_FRAME_LIST_ROLLOVER, 0, 0, 0);

                /* ptr->ipp->USBSTS_b.FLROV = 1; */
                ptr->ipp->USBSTS &= USB_VAL_1F008;
            }
 #endif
 #if defined(BSP_MCU_GROUP_RZA_USB)
            if ((1 == ptr->ipp->USBSTS_b.USBINT) && (1 == ptr->ipp->USBINTR_b.USBInterruptEnable))
            {
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_USBINT, 0, 0, 0);

                /* ptr->ipp.USBSTS.BIT.USBINT = 1; */
                ptr->ipp->USBSTS &= USB_VAL_1F001;
            }
 #else
            if ((1 == ptr->ipp->USBSTS_b.USBINT) && (1 == ptr->ipp->USBINTR_b.USBIE))
            {
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_USBINT, 0, 0, 0);

                /* ptr->ipp->USBSTS_b.USBINT = 1; */
                ptr->ipp->USBSTS &= USB_VAL_1F001;
            }
 #endif
        }
    }
    else
    {
 #if USB_NUM_USBIP == 2
        if ((0 != ptr->ipp1->USBSTS) && (0 != ptr->ipp1->USBINTR))
        {
  #if defined(BSP_MCU_GROUP_RZA_USB)
            if ((1 == ptr->ipp1->USBSTS_b.HostSystemError) && (1 == ptr->ipp1->USBINTR_b.HostSystemErrorEnable))
            {
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_HOST_SYSTEM_ERROR, 0, 0, 0);

                /* ptr->ipp1.USBSTS.BIT.HostSystemError = 1; */
                ptr->ipp1->USBSTS &= USB_VAL_1F010;
            }
  #else
            if ((1 == ptr->ipp1->USBSTS_b.HSYSE) && (1 == ptr->ipp1->USBINTR_b.HSEE))
            {
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_HOST_SYSTEM_ERROR, 0, 0, 0);

                /* ptr->ipp1->USBSTS_b.HSYSE = 1; */
                ptr->ipp1->USBSTS &= USB_VAL_1F010;
            }
  #endif
  #if defined(BSP_MCU_GROUP_RZA_USB)
            if ((1 == ptr->ipp1->USBSTS_b.PortChangeDetect) && (1 == ptr->ipp1->USBINTR_b.PortChangeDetectEnable))
            {
                g_usb_port_status[ptr->ip][0] = ptr->ipp1->PORTSC1_b.CurrentConnectStatus;
                g_usb_port_status[ptr->ip][1] = ptr->ipp1->PORTSC1_b.PortOwner;
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_PORT_CHANGE_DETECT, 0, 0, 0);

                /* ptr->ipp1.USBSTS.BIT.PortChangeDetect = 1; */
                ptr->ipp1->USBSTS &= USB_VAL_1F004;
            }
  #else
            if ((1 == ptr->ipp1->USBSTS_b.PTCGDET) && (1 == ptr->ipp1->USBINTR_b.PTCGIE))
            {
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_PORT_CHANGE_DETECT, 0, 0, 0);

                /* ptr->ipp1->USBSTS_b.PTCGDET = 1; */
                ptr->ipp1->USBSTS &= USB_VAL_1F004;
            }
  #endif
  #if defined(BSP_MCU_GROUP_RZA_USB)
            if ((1 == ptr->ipp1->USBSTS_b.USBERRINT) && (1 == ptr->ipp1->USBINTR_b.USBErrorInterruptEnable))
            {
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_USBERRINT, 0, 0, 0);

                /* ptr->ipp1.USBSTS.BIT.USBERRINT = 1; */
                ptr->ipp1->USBSTS &= USB_VAL_1F002;
            }
  #else
            if ((1 == ptr->ipp1->USBSTS_b.USBERRINT) && (1 == ptr->ipp1->USBINTR_b.USBEIE))
            {
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_USBERRINT, 0, 0, 0);

                /* ptr->ipp1->USBSTS_b.USBERRINT = 1; */
                ptr->ipp1->USBSTS &= USB_VAL_1F002;
            }
  #endif
  #if defined(BSP_MCU_GROUP_RZA_USB)
            if ((1 == ptr->ipp1->USBSTS_b.InterruptonAsyncAdvance) &&
                (1 == ptr->ipp1->USBINTR_b.InterruptonAsyncAdvanceEnable))
            {
                usb_hstd_hci_send_message_from_int(ptr,
                                                   USB_HCI_TASK,
                                                   USB_HCI_MESS_EHCI_INTERRUPT_ON_ASYNC_ADVANCE,
                                                   0,
                                                   0,
                                                   0);

                /* ptr->ipp1.USBSTS.BIT.InterruptonAsyncAdvance = 1; */
                ptr->ipp1->USBSTS &= USB_VAL_1F020;
            }
  #else
            if ((1 == ptr->ipp1->USBSTS_b.IAAIS) && (1 == ptr->ipp1->USBINTR_b.INTAADVE))
            {
                usb_hstd_hci_send_message_from_int(ptr,
                                                   USB_HCI_TASK,
                                                   USB_HCI_MESS_EHCI_INTERRUPT_ON_ASYNC_ADVANCE,
                                                   0,
                                                   0,
                                                   0);

                /* ptr->ipp1->USBSTS_b.IAAIS = 1; */
                ptr->ipp1->USBSTS &= USB_VAL_1F020;
            }
  #endif
  #if defined(BSP_MCU_GROUP_RZA_USB)
            if ((1 == ptr->ipp1->USBSTS_b.FrameListRollover) && (1 == ptr->ipp1->USBINTR_b.FrameListRolloverEnable))
            {
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_FRAME_LIST_ROLLOVER, 0, 0, 0);

                /* ptr->ipp1.USBSTS.BIT.FrameListRollover = 1; */
                ptr->ipp1->USBSTS &= USB_VAL_1F008;
            }
  #else
            if ((1 == ptr->ipp1->USBSTS_b.FLROV) && (1 == ptr->ipp1->USBINTR_b.FMLSTROE))
            {
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_FRAME_LIST_ROLLOVER, 0, 0, 0);

                /* ptr->ipp1->USBSTS_b.FLROV = 1; */
                ptr->ipp1->USBSTS &= USB_VAL_1F008;
            }
  #endif
  #if defined(BSP_MCU_GROUP_RZA_USB)
            if ((1 == ptr->ipp1->USBSTS_b.USBINT) && (1 == ptr->ipp1->USBINTR_b.USBInterruptEnable))
            {
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_USBINT, 0, 0, 0);

                /* ptr->ipp1.USBSTS.BIT.USBINT = 1; */
                ptr->ipp1->USBSTS &= USB_VAL_1F001;
            }
  #else
            if ((1 == ptr->ipp1->USBSTS_b.USBINT) && (1 == ptr->ipp1->USBINTR_b.USBIE))
            {
                usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_EHCI_USBINT, 0, 0, 0);

                /* ptr->ipp1->USBSTS_b.USBINT = 1; */
                ptr->ipp1->USBSTS &= USB_VAL_1F001;
            }
  #endif
        }
 #endif                                /* #if USB_NUM_USBIP == 2 */
    }
}                                      /* End of function usb_hstd_ehci_interrupt_handler() */

/***********************************************************************************************************************
 * Function     : EHCI Getting of device address of rootpoot
 * Declaration  : uint16_t usb_hstd_ehci_get_device_address_of_rootpoot( uint16_t rootport )
 * Argument     : uint16_t rootport ; rootport no
 * Return       : uint16_t          ; device address
 * Note         :
 ***********************************************************************************************************************/
uint16_t usb_hstd_ehci_get_device_address_of_rootpoot (uint16_t rootport)
{
    if (USB_EHCI_MAXROOTPORTS > rootport)
    {
        return gs_usb_ehci_root_device_address[rootport];
    }

    return USB_HCI_NODEVICE;
}                                      /* End of function usb_hstd_ehci_get_device_address_of_rootpoot() */

/***********************************************************************************************************************
 * Function     : The device address of EHCI route port is set.
 * Declaration  : uint16_t usb_hstd_ehci_set_device_address_of_rootpoot( uint16_t rootport, uint16_t devaddr )
 * Argument     : uint16_t rootport ; rootport no
 *              : uint16_t devaddr  ; device address
 * Return       : uint16_t          ; device address
 * Note         :
 ***********************************************************************************************************************/
uint16_t usb_hstd_ehci_set_device_address_of_rootpoot (uint16_t rootport, uint16_t deviceaddr)
{
    st_usb_hci_device_t * p_devinfo;

    if (USB_EHCI_MAXROOTPORTS <= rootport)
    {
        return USB_HCI_NODEVICE;
    }

    if (0 != gs_usb_ehci_root_device_address[rootport])
    {
        return USB_HCI_NODEVICE;
    }

    /* The device address of device information is updated */
    p_devinfo = r_usb_hstd_hci_get_device_infomation(gs_usb_ehci_root_device_address[rootport]);
    if (NULL == p_devinfo)
    {
        return USB_HCI_NODEVICE;
    }

    p_devinfo->bit.devnum = (uint8_t) deviceaddr & USB_VAL_7FU8;

    gs_usb_ehci_root_device_address[rootport] = (uint8_t) deviceaddr;

    return deviceaddr;
}                                      /* End of function usb_hstd_ehci_set_device_address_of_rootpoot() */

/***********************************************************************************************************************
 * Function     : Getting of EHCI Transfer End Status
 * Declaration  : uint16_t usb_hstd_ehci_get_transfer_end_status( st_usb_hci_tr_req_t *tr_req )
 * Argument     : st_usb_hci_tr_req_t *tr_req ; transfer request pointer
 * Return       : uint16_t               ; USB Standard F/W Transfer End Status
 * Note         :
 ***********************************************************************************************************************/
uint16_t usb_hstd_ehci_get_transfer_end_status (st_usb_hci_tr_req_t * p_tr_req)
{
    u_usb_ehci_transfer_info_t status;
    uint16_t ret = USB_DATA_ERR;

    if (NULL != p_tr_req)
    {
        status.dword = p_tr_req->status;

        if (FALSE == p_tr_req->bit.enable)
        {
            ret = USB_DATA_STOP;
        }
        else if (USB_EP_ISO == p_tr_req->bit.eptype)
        {
            if (1 == status.bit.status_halted)
            {
            }
            else if (1 == status.bit.status_data_buffer_error)
            {
            }
            else if (1 == status.bit.status_babble_detected)
            {
            }
            else if (1 == status.bit.status_transaction_error)
            {
            }
/* else if (1 == status.bit.status_missed_micro_frame)
 * {
 * }*/
            else
            {
                /* For isochronous */
                if (USB_HCI_DIRECTION_OUT == p_tr_req->bit.direction)
                {
                    ret = USB_DATA_WRITING;
                }
                else
                {
                    ret = USB_DATA_READING;
                }
            }
        }
        else
        {
            if (1 == status.bit.status_halted)
            {
                ret = USB_DATA_STOP;
                if (0 == status.bit.cerr)
                {
                }
                else if (1 == status.bit.status_data_buffer_error)
                {
                }
                else if (1 == status.bit.status_babble_detected)
                {
                }
                else if (1 == status.bit.status_transaction_error)
                {
                }
                else if (1 == status.bit.status_missed_micro_frame)
                {
                }
                else
                {
                    if (3 == status.bit.cerr)
                    {
                        /* For STALL */
                        ret = USB_DATA_STALL;
                    }
                }
            }
            else
            {
                if (USB_EP_CNTRL == p_tr_req->bit.eptype)
                {
                    /* For control */
                    ret = USB_CTRL_END;
                }
                else
                {
                    if (USB_HCI_DIRECTION_OUT == p_tr_req->bit.direction)
                    {
                        /* When the data sending ends normally */
                        ret = USB_DATA_NONE;
                    }
                    else
                    {
                        if (p_tr_req->actual_size > p_tr_req->trsize)
                        {
                            /* When receive data is size over */
                            ret = USB_DATA_OVR;
                        }
                        else if (p_tr_req->actual_size < p_tr_req->trsize)
                        {
                            /* When receive data is short size */
                            ret = USB_DATA_SHT;
                        }
                        else
                        {
                            /* When the data reception ends normally */
                            ret = USB_DATA_OK;
                        }
                    }
                }
            }
        }
    }

    return ret;
}                                      /* End of function usb_hstd_ehci_get_transfer_end_status() */

/***********************************************************************************************************************
 * Function     : Getting of EHCI PID Status
 * Declaration  : uint16_t usb_hstd_ehci_get_pid_status( st_usb_hci_tr_req_t *tr_req )
 * Argument     : st_usb_hci_tr_req_t *tr_req ; transfer request pointer
 * Return       : uint16_t               ; PID Status
 * Note         :
 ***********************************************************************************************************************/
uint16_t usb_hstd_ehci_get_pid_status (st_usb_hci_tr_req_t * p_tr_req)
{
    st_usb_ehci_qh_t * p_qh;

    if (NULL != p_tr_req)
    {
        if (TRUE == p_tr_req->bit.enable)
        {
            if (USB_EP_ISO != p_tr_req->bit.eptype)
            {
 #if defined(BSP_MCU_GROUP_RZA_USB)
                p_qh = (st_usb_ehci_qh_t *) (r_usb_pa_to_va((uint64_t) p_tr_req->hci_info));
 #else
                p_qh = (st_usb_ehci_qh_t *) p_tr_req->hci_info;
 #endif
                if (0 == p_qh->transfer_info.bit.status_halted)
                {
                    return USB_PID_BUF;
                }

                if (0 != p_qh->transfer_info.bit.status_halted)
                {
                    if (3 == p_qh->transfer_info.bit.cerr)
                    {
                        return USB_PID_STALL;
                    }
                }
            }
        }
    }

    return USB_PID_NAK;
}                                      /* End of function usb_hstd_ehci_get_pid_status() */

/***********************************************************************************************************************
 * Function     : EHCI Port Suspend
 * Declaration  : void usb_hstd_ehci_port_suspend( uint16_t port )
 * Argument     : uint16_t port ; port no
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ehci_port_suspend (usb_utr_t * ptr)
{
    uint32_t portsc1_save;

    if (USB_EHCI_MAXROOTPORTS <= ptr->ip)
    {
        USB_HCI_PRINTF1_R("usb_hstd_ehci_port_suspend Error: Illegal port no(%d)\n", ptr->ip);

        return;
    }

    /* ptr->ipp->PORTSC1.BIT.WKOC_E        = 1; */    /* Over-Current Detect Enable */
    /* ptr->ipp->PORTSC1.BIT.WKDSCNNT_E    = 1; */    /* DisConnect Enable */
    /* ptr->ipp->PORTSC1.BIT.WKCNNT_E      = 1; */    /* Device Connect Enable */
    if (USB_IP0 == ptr->ip)
    {
        portsc1_save      = ptr->ipp->PORTSC1;
        ptr->ipp->PORTSC1 = USB_VAL_SC_WK | (portsc1_save & USB_VAL_XFFD5);

        /* ptr->ipp->PORTSC1_b.SUSPEND       = 1; */    /* Set Suspend */
        portsc1_save      = ptr->ipp->PORTSC1;
        ptr->ipp->PORTSC1 = USB_VAL_SUSP | (portsc1_save & USB_VAL_XFFD5);
    }
    else
    {
 #if USB_NUM_USBIP == 2
        portsc1_save       = ptr->ipp1->PORTSC1;
        ptr->ipp1->PORTSC1 = USB_VAL_SC_WK | (portsc1_save & USB_VAL_XFFD5);

        /* ptr->ipp1->PORTSC1_b.SUSPEND       = 1; */    /* Set Suspend */
        portsc1_save       = ptr->ipp1->PORTSC1;
        ptr->ipp1->PORTSC1 = USB_VAL_SUSP | (portsc1_save & USB_VAL_XFFD5);
 #endif
    }
}                                      /* End of function usb_hstd_ehci_port_suspend() */

/***********************************************************************************************************************
 * Function     : EHCI Port Resume
 * Declaration  : void usb_hstd_ehci_port_resume( uint16_t port )
 * Argument     : uint16_t port ; port no
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ehci_port_resume (usb_utr_t * ptr)
{
    uint32_t portsc1_save;

    if (USB_EHCI_MAXROOTPORTS <= ptr->ip)
    {
        USB_HCI_PRINTF1_R("usb_hstd_ehci_port_resume Error: Illegal port no(%d)\n", ptr->ip);

        return;
    }

 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        if ((1 == ptr->ipp->PORTSC1_b.Suspend) && (1 == ptr->ipp->PORTSC1_b.PortEnabled_Disabled))
        {
            /* Set Force Port Resume */
            /* ptr->ipp.PORTSC1.BIT.ForcePortResume = 1; */
            portsc1_save      = ptr->ipp->PORTSC1;
            ptr->ipp->PORTSC1 = USB_VAL_0100 | (portsc1_save & USB_VAL_XFFD5);
            usb_cpu_delay_xms(20);
            do
            {
                /* Set Force Port Resume */
                /* ptr->ipp.PORTSC1.BIT.ForcePortResume = 0; */
                ptr->ipp->PORTSC1 &= USB_VAL_F95;
                usb_cpu_delay_xms(1);
            } while ((ptr->ipp->PORTSC1_b.Suspend != 0) && (ptr->ipp->PORTSC1_b.PortEnabled_Disabled != 0));
        }
    }
    else
    {
  #if USB_NUM_USBIP == 2
        if ((1 == ptr->ipp1->PORTSC1_b.Suspend) && (1 == ptr->ipp1->PORTSC1_b.PortEnabled_Disabled))
        {
            /* Set Force Port Resume */
            /* ptr->ipp.PORTSC1.BIT.ForcePortResume = 1; */
            portsc1_save       = ptr->ipp1->PORTSC1;
            ptr->ipp1->PORTSC1 = USB_VAL_0100 | (portsc1_save & USB_VAL_XFFD5);
            usb_cpu_delay_xms(20);
            do
            {
                /* Set Force Port Resume */
                /* ptr->ipp1.PORTSC1.BIT.ForcePortResume = 0; */
                ptr->ipp1->PORTSC1 &= USB_VAL_F95;
                usb_cpu_delay_xms(1);
            } while ((ptr->ipp1->PORTSC1_b.Suspend != 0) && (ptr->ipp1->PORTSC1_b.PortEnabled_Disabled != 0));
        }
  #endif
    }
 #else
    if ((1 == ptr->ipp->PORTSC1_b.SUSPEND) && (1 == ptr->ipp->PORTSC1_b.PTE))
    {
        /* Set Force Port Resume */
        /* ptr->ipp.PORTSC1.BIT.ForcePortResume = 1; */
        portsc1_save      = ptr->ipp->PORTSC1;
        ptr->ipp->PORTSC1 = USB_VAL_0100 | (portsc1_save & USB_VAL_XFFD5);
        usb_cpu_delay_xms(20);

        /* R_BSP_SoftwareDelay(20,BSP_DELAY_UNITS_MICROSECONDS); */
        do
        {
            /* Set Force Port Resume */
            /* ptr->ipp.PORTSC1.BIT.ForcePortResume = 0; */
            ptr->ipp->PORTSC1 &= USB_VAL_F95;

            /* r_usb_hstd_hci_wait_time(1); */
            R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);
        } while ((ptr->ipp->PORTSC1_b.SUSPEND != 0) && (ptr->ipp->PORTSC1_b.PTE != 0));
    }
 #endif
}                                      /* End of function usb_hstd_ehci_port_resume() */

/***********************************************************************************************************************
 * Function     : EHCI Chancel Transfer Request
 * Declaration  : usb_hstd_ehci_cancel_transfer_request( st_usb_hci_tr_req_t *tr_req )
 * Argument     : st_usb_hci_tr_req_t *tr_req ; Transfer Request Address
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ehci_cancel_transfer_request (st_usb_hci_tr_req_t * p_tr_req)
{
    st_usb_ehci_qh_t   * p_qh;
    st_usb_ehci_itd_t  * p_itd;
    st_usb_ehci_sitd_t * p_sitd;
    uint32_t             n;

    if (NULL == p_tr_req)
    {
        return;
    }

 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (0 != (r_usb_pa_to_va((uint64_t) p_tr_req->hci_info)))
 #else
    if (NULL != p_tr_req->hci_info)
 #endif
    {
        if (USB_EP_ISO == p_tr_req->bit.eptype)
        {
            if (USB_HCI_DEVSPEED_HS == p_tr_req->devinfo->bit.devspeed)
            {
 #if defined(BSP_MCU_GROUP_RZA_USB)
                p_itd = (st_usb_ehci_itd_t *) (r_usb_pa_to_va((uint64_t) p_tr_req->hci_info));
 #else
                p_itd = (st_usb_ehci_itd_t *) p_tr_req->hci_info;
 #endif

                /* inactivate itd */
                for (n = 0; n < 8; n++)
                {
                    p_itd->transaction[n].bit.status_active = 0;
                }
            }
            else
            {
 #if defined(BSP_MCU_GROUP_RZA_USB)
                p_sitd = (st_usb_ehci_sitd_t *) (r_usb_pa_to_va((uint64_t) p_tr_req->hci_info));
 #else
                p_sitd = (st_usb_ehci_sitd_t *) p_tr_req->hci_info;
 #endif

                /* inactivate sitd */
                p_sitd->state.bit.status_active = 0;
            }
        }
        else
        {
 #if defined(BSP_MCU_GROUP_RZA_USB)
            p_qh = (st_usb_ehci_qh_t *) (r_usb_pa_to_va((uint64_t) p_tr_req->hci_info));

            /* inactivate qh */
            if (0 != p_qh->qtd_head)
            {
                /* inactive qtd */
                usb_hstd_ehci_inactive_qtd((st_usb_ehci_qtd_t *) (uintptr_t) p_qh->qtd_head);
            }

            p_qh->transfer_info.bit.status_active = 0;

            /* delete qtd */
            if (0 != p_qh->qtd_head)
            {
                usb_hstd_ehci_clear_qtd((st_usb_ehci_qtd_t *) (uintptr_t) p_qh->qtd_head);
                p_qh->qtd_head = 0;
            }
 #else
            p_qh = (st_usb_ehci_qh_t *) p_tr_req->hci_info;

            /* inactivate qh */
            if (NULL != p_qh->qtd_head)
            {
                /* inactive qtd */
                usb_hstd_ehci_inactive_qtd(p_qh->qtd_head);
            }

            p_qh->transfer_info.bit.status_active = 0;

            /* delete qtd */
            if (NULL != p_qh->qtd_head)
            {
                usb_hstd_ehci_clear_qtd(p_qh->qtd_head);
                p_qh->qtd_head = NULL;
            }
 #endif
        }
    }

    /* delete tr-req */
    p_tr_req->bit.enable = FALSE;
}                                      /* End of function usb_hstd_ehci_cancel_transfer_request() */

/* Static Function */

/***********************************************************************************************************************
 * Function     : Reset EHCI H/W
 * Declaration  : void usb_hstd_ehci_hw_reset( void )
 * Argument     : void
 * Return       : uint32_t ; status
 * Note         :
 ***********************************************************************************************************************/
static uint32_t usb_hstd_ehci_hw_reset (usb_utr_t * ptr)
{
    uint32_t timeout;

    /* ========== */
    /*  Stop eHC  */
    /* ========== */
    if (USB_IP0 == ptr->ip)
    {
        ptr->ipp->USBCMD_b.RS = 0;     /* Clear Run/Stop bit. Stop HC */
    }
    else
    {
 #if USB_NUM_USBIP == 2
        ptr->ipp1->USBCMD_b.RS = 0;    /* Clear Run/Stop bit. Stop HC */
 #endif
    }

    timeout = 0;
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        while (0 == ptr->ipp->USBSTS_b.HCHalted) /* Wait Halted == 1 */
        {
            if (timeout > USB_EHCI_TIMEOUT)
            {
                USB_HCI_PRINTF0_R("Error : usb_hstd_ehci_init TIMEOUT\n");

                return USB_ERROR;
            }

            /* r_usb_hstd_hci_wait_time(1); */
            R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
            timeout++;
        }
    }
    else
    {
  #if USB_NUM_USBIP == 2
        while (0 == ptr->ipp1->USBSTS_b.HCHalted) /* Wait Halted == 1 */
        {
            if (timeout > USB_EHCI_TIMEOUT)
            {
                USB_HCI_PRINTF0_R("Error : usb_hstd_ehci_init TIMEOUT\n");

                return USB_ERROR;
            }

            /* r_usb_hstd_hci_wait_time(1); */
            R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
            timeout++;
        }
  #endif
    }
 #else
    while (0 == USB00->USBSTS_b.EHCSTS) /* Wait Halted == 1 */
    {
        if (timeout > USB_EHCI_TIMEOUT)
        {
            USB_HCI_PRINTF0_R("Error : usb_hstd_ehci_init TIMEOUT\n");

            return USB_ERROR;
        }

        /* r_usb_hstd_hci_wait_time(1); */
        R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
        timeout++;
    }
 #endif

    /* =========== */
    /*  Reset eHC  */
    /* =========== */
    if (USB_IP0 == ptr->ip)
    {
        ptr->ipp->USBCMD_b.HCRESET = 1; /* Reset */
    }
    else
    {
 #if USB_NUM_USBIP == 2
        ptr->ipp1->USBCMD_b.HCRESET = 1; /* Reset */
 #endif
    }

    timeout = 0;
    if (USB_IP0 == ptr->ip)
    {
        while (1 == ptr->ipp->USBCMD_b.HCRESET)
        {
            if (timeout > USB_EHCI_TIMEOUT)
            {
                USB_HCI_PRINTF0_R("Error : usb_hstd_ehci_init TIMEOUT\n");

                return USB_ERROR;
            }

            /* r_usb_hstd_hci_wait_time(1); */
            R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
            timeout++;
        }
    }
    else
    {
 #if USB_NUM_USBIP == 2
        while (1 == ptr->ipp1->USBCMD_b.HCRESET)
        {
            if (timeout > USB_EHCI_TIMEOUT)
            {
                USB_HCI_PRINTF0_R("Error : usb_hstd_ehci_init TIMEOUT\n");

                return USB_ERROR;
            }

            /* r_usb_hstd_hci_wait_time(1); */
            R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
            timeout++;
        }
 #endif
    }

    return USB_OK;
}                                      /* End of function usb_hstd_ehci_hw_reset() */

/***********************************************************************************************************************
 * Function     : Set Port Routing
 * Declaration  : static void usb_hstd_ehci_set_port_route( void )
 * Argument     : void
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
static void usb_hstd_ehci_set_port_route (usb_utr_t * ptr)
{
    uint32_t n_ports;
    uint32_t n;
    uint32_t portsc1_save;

    /* =============== */
    /*  Set Ownership  */
    /* =============== */
    if (USB_IP0 == ptr->ip)
    {
        n_ports = ptr->ipp->HCSPARAMS_b.N_PORTS;
    }
    else
    {
 #if USB_NUM_USBIP == 2
        n_ports = ptr->ipp1->HCSPARAMS_b.N_PORTS;
 #else
        n_ports = ptr->ipp->HCSPARAMS_b.N_PORTS;
 #endif
    }

    for (n = 0; n < n_ports; n++)
    {
        /* USB00->PORTSC1_b.PTOWNR = 0; */    /* Port Owner : EHCI */
        /* USB00.PORTSC1.BIT.PP        = 1; */    /* Port Power : ON */
        if (USB_IP0 == ptr->ip)
        {
            portsc1_save      = ptr->ipp->PORTSC1;
            ptr->ipp->PORTSC1 = USB_VAL_X1000 | (portsc1_save & USB_VAL_XDFD5);
        }
        else
        {
 #if USB_NUM_USBIP == 2
            portsc1_save       = ptr->ipp1->PORTSC1;
            ptr->ipp1->PORTSC1 = USB_VAL_X1000 | (portsc1_save & USB_VAL_XDFD5);
 #endif
        }

 #if defined(BSP_MCU_GROUP_RZA_USB)
        if (USB_IP0 == ptr->ip)
        {
            if (1 == ptr->ipp->PORTSC1_b.OvercurrentChange)
            {
                /* ptr->ipp.PORTSC1.BIT.OvercurrentChange = 1; */   /* Clear Over-curent */
                portsc1_save      = ptr->ipp->PORTSC1;
                ptr->ipp->PORTSC1 = USB_VAL_X20 | (portsc1_save & USB_VAL_XFFD5);
            }
        }
        else
        {
  #if USB_NUM_USBIP == 2
            if (1 == ptr->ipp1->PORTSC1_b.OvercurrentChange)
            {
                /* ptr->ipp1.PORTSC1.BIT.OvercurrentChange = 1; */   /* Clear Over-curent */
                portsc1_save       = ptr->ipp1->PORTSC1;
                ptr->ipp1->PORTSC1 = USB_VAL_X20 | (portsc1_save & USB_VAL_XFFD5);
            }
  #endif
        }
 #else
        if (1 == ptr->ipp->PORTSC1_b.OVCC)
        {
            /* ptr->ipp->PORTSC1_b.OVCC = 1; */   /* Clear Over-curent */
            portsc1_save      = ptr->ipp->PORTSC1;
            ptr->ipp->PORTSC1 = USB_VAL_X20 | (portsc1_save & USB_VAL_XFFD5);
        }
 #endif

        /* Wait port power stabilization time */
        usb_cpu_delay_xms(USB_VAL_100);
    }
}                                      /* End of function usb_hstd_ehci_set_port_route() */

/***********************************************************************************************************************
 * Function     : EHCI Port Enable
 * Declaration  : uint32_t usb_hstd_ehci_port_enable(uint32_t portnum, uint32_t *hs_enable_flag)
 * Argument     : uint32_t portnum ; port no
 * Return       : uint32_t *hs_enable_flag ; HS Device Enable Flag pointer
 * Note         :
 ***********************************************************************************************************************/
static uint32_t usb_hstd_ehci_port_enable (usb_utr_t * ptr, uint32_t * p_hs_enable_flag)
{
    *p_hs_enable_flag = FALSE;

    /* Device existence confirmation */
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        if (0 == ptr->ipp->PORTSC1_b.CurrentConnectStatus)
        {
            return FALSE;
        }
    }
    else
    {
  #if USB_NUM_USBIP == 2
        if (0 == ptr->ipp1->PORTSC1_b.CurrentConnectStatus)
        {
            return FALSE;
        }
  #endif
    }
 #else
    if (0 == USB00->PORTSC1_b.CCSTS)
    {
        return FALSE;
    }
 #endif

    /* For Low-Speed Device */
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        if (USB_EHCI_LINE_STATE_K == ptr->ipp->PORTSC1_b.LineStatus)
        {
            return TRUE;
        }
    }
    else
    {
  #if USB_NUM_USBIP == 2
        if (USB_EHCI_LINE_STATE_K == ptr->ipp1->PORTSC1_b.LineStatus)
        {
            return TRUE;
        }
  #endif
    }
 #else
    if (USB_EHCI_LINE_STATE_K == USB00->PORTSC1_b.LINESTS)
    {
        return TRUE;
    }
 #endif

    /* Port Reset */
    if (FALSE == usb_hstd_ehci_port_reset(ptr))
    {
        return FALSE;
    }

    /* Device existence confirmation */
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        if (0 == ptr->ipp->PORTSC1_b.CurrentConnectStatus)
        {
            return FALSE;
        }
    }
    else
    {
  #if USB_NUM_USBIP == 2
        if (0 == ptr->ipp1->PORTSC1_b.CurrentConnectStatus)
        {
            return FALSE;
        }
  #endif
    }
 #else
    if (0 == USB00->PORTSC1_b.CCSTS)
    {
        return FALSE;
    }
 #endif

    /* HS Device Enable confirmation */
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        if (1 == ptr->ipp->PORTSC1_b.PortEnabled_Disabled)
        {
            *p_hs_enable_flag = TRUE;
        }
    }
    else
    {
  #if USB_NUM_USBIP == 2
        if (1 == ptr->ipp1->PORTSC1_b.PortEnabled_Disabled)
        {
            *p_hs_enable_flag = TRUE;
        }
  #endif
    }
 #else
    if (1 == USB00->PORTSC1_b.PTE)
    {
        *p_hs_enable_flag = TRUE;
    }
 #endif

    return TRUE;
}                                      /* End of function usb_hstd_ehci_port_enable() */

/***********************************************************************************************************************
 * Function     : Delete Periodeic Scheuling Score
 * Declaration  : void usb_hstd_ehci_delete_periodec_scheduling_score( uint32_t max_period, uint32_t pollrate, uint32_t pollrate_offset )
 * Argument     : uint32_t max_period ; max period
 *              : uint32_t pollrate   ; pollrate
 *              : uint32_t            ; pollrate offset
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
static void usb_hstd_ehci_delete_periodec_scheduling_score (usb_utr_t * ptr,
                                                            uint32_t    max_period,
                                                            uint32_t    pollrate,
                                                            uint32_t    pollrate_offset)
{
    uint32_t uframe_list_size;
    uint32_t n;
    uint32_t j;

    /* Get micro frame list size */
    uframe_list_size  = usb_hstd_ehci_get_frame_list_size(ptr);
    uframe_list_size *= 8;

    /* Update of score */
    for (n = pollrate_offset; n < uframe_list_size; n += pollrate)
    {
        for (j = 0; j < max_period; j++)
        {
            if (0 != gs_usb_ehci_periodic_scheduling_score[n + j])
            {
                gs_usb_ehci_periodic_scheduling_score[n + j]--;
            }
            else
            {
                USB_HCI_PRINTF0_R("Error: Can't delete Periodic Scheduing Score\n");
            }
        }
    }

 #ifdef DEBUG_PRINT_PERIODIC_SCHEDULING
    usb_hstd_ehci_print_periodic_scheduling_score();
 #endif
}                                      /* End of function usb_hstd_ehci_delete_periodec_scheduling_score() */

/***********************************************************************************************************************
 * Function     : Unlink data structure from periodic frame list
 * Declaration  : uint32_t usb_hstd_ehci_unlink_periodic( u_usb_ehci_flep_t *data, uint32_t elementnum )
 * Argument     : u_usb_ehci_flep_t *data ; data structure pointer
 *              : uint32_t elementnum ; periodic frame list no
 * Return       : uint32_t status     ; unlink flag
 * Note         :
 ***********************************************************************************************************************/
static uint32_t usb_hstd_ehci_unlink_periodic (usb_utr_t * ptr, u_usb_ehci_flep_t * p_data, uint32_t elementnum)
{
    uint32_t            periodic_list_addr;
    uint32_t            tmp_addr;
    u_usb_ehci_flep_t * p_current_element;

    if (USB_IP0 == ptr->ip)
    {
        periodic_list_addr = ptr->ipp->PERIODICLISTBASE & USB_VAL_XF000;
    }
    else
    {
 #if USB_NUM_USBIP == 2
        periodic_list_addr = ptr->ipp1->PERIODICLISTBASE & USB_VAL_XF000;
 #else
        periodic_list_addr = ptr->ipp->PERIODICLISTBASE & USB_VAL_XF000;
 #endif
    }

    if (0x00000000 != periodic_list_addr)
    {
 #if defined(BSP_MCU_GROUP_RZA_USB)
        periodic_list_addr = (uint32_t) r_usb_pa_to_va((uint64_t) periodic_list_addr);
 #endif
    }
    else
    {
        USB_HCI_PRINTF0_R("usb_hstd_ehci_unlink_periodic Error : PERIODICLISTBASE is not registered. \n");

        return 0;
    }

    /* The address of the periodic frame list specified with elementnum is calculated.  */
    tmp_addr          = elementnum * sizeof(uint32_t);
    tmp_addr         &= USB_VAL_XFFC;
    tmp_addr         |= periodic_list_addr;
    p_current_element = (u_usb_ehci_flep_t *) (uintptr_t) tmp_addr;

    while (1)
    {
        if (NULL == p_current_element)
        {
            USB_HCI_PRINTF0_R("usb_hstd_ehci_unlink_periodic Error: Current Element Pointer is NULL\n");

            return 0;
        }

        if (1 == p_current_element->bit.t)
        {
            break;
        }

 #if defined(BSP_MCU_GROUP_RZA_USB)
        if ((r_usb_pa_to_va((uint64_t) (p_current_element->address & USB_VAL_XFFE0))) == (uint32_t) (uintptr_t) p_data)
 #else
        if ((p_current_element->address & USB_VAL_XFFE0) == (uint32_t) p_data)
 #endif
        {
            /* The value of the next link pointer of qh/itd/sitd is set */
            *p_current_element = *p_data;

            return 1;
        }

        if ((p_current_element->address & USB_VAL_XFFE0) != (uint32_t) (uintptr_t) p_data)
        {
            /* The nest qh/itd/sitd is retrieved referring to the next link pointer.  */
 #if defined(BSP_MCU_GROUP_RZA_USB)
            p_current_element =
                (u_usb_ehci_flep_t *) (r_usb_pa_to_va((uint64_t) (p_current_element->address & USB_VAL_XFFE0)));
 #else
            p_current_element = (u_usb_ehci_flep_t *) (p_current_element->address & USB_VAL_XFFE0);
 #endif
        }
    }

    return 0;
}                                      /* End of function usb_hstd_ehci_unlink_periodic() */

/***********************************************************************************************************************
 * Function     : EHCI Clear transfer request for disconnected device
 * Declaration  : void usb_hstd_ehci_clear_device_trreq( uint32_t devadd )
 * Argument     : uint32_t devadd ; Device Address
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
static void usb_hstd_ehci_clear_device_trreq (uint32_t devadd)
{
    uint8_t n;

    for (n = 0; n < USB_HCI_TRREQ_NUM; n++)
    {
        if ((1 == g_usb_hstd_hci_transfer_request[n].bit.enable) &&
            (devadd == g_usb_hstd_hci_transfer_request[n].bit.devadrs))
        {
            usb_hstd_ehci_cancel_transfer_request(&g_usb_hstd_hci_transfer_request[n]);
        }
    }
}                                      /* End of function usb_hstd_ehci_clear_device_trreq() */

 #ifdef DEBUG_PRINT_PORT_INFOMATION

/***********************************************************************************************************************
 * Function     : EHCI Port Infomation Print
 * Declaration  : void usb_hstd_ehci_print_port_information( )
 * Argument     : none
 * Return       : void
 * Note         : This function is used for debugging.
 ***********************************************************************************************************************/
static void usb_hstd_ehci_print_port_information (usb_utr_t * ptr)
{
    USB_HCI_PRINTF0("-------------------------------\n");
    USB_HCI_PRINTF1("  EHCI Port No.%d Infomation\n", 0);
    USB_HCI_PRINTF0("-------------------------------\n");

    if (USB_IP0 == ptr->ip)
    {
        /* USB_HCI_PRINTF1("WKOC_E                     : %d\n", ptr->ipp.PORTSC1.BIT.WKOC_E);
         * USB_HCI_PRINTF1("WKDSCNNT_E                 : %d\n", ptr->ipp.PORTSC1.BIT.WKDSCNNT_E);
         * USB_HCI_PRINTF1("WKCNNT_E                   : %d\n", ptr->ipp.PORTSC1.BIT.WKCNNT_E);
         * USB_HCI_PRINTF1("Port_Test_Control          : %d\n", ptr->ipp.PORTSC1.BIT.PortTestControl);
         * USB_HCI_PRINTF1("Port_IndicatorControl      : %d\n", ptr->ipp.PORTSC1.BIT.PortIndicatorControl);*/
        USB_HCI_PRINTF1("Port_Owner                 : %d\n", ptr->ipp->PORTSC1_b.PTOWNR);

        /* USB_HCI_PRINTF1("PP                         : %d\n", ptr->ipp.PORTSC1.BIT.PP); */
        USB_HCI_PRINTF1("Line_Status                : %d\n", ptr->ipp->PORTSC1_b.LINESTS);

        /* USB_HCI_PRINTF1("Port_Reset                 : %d\n", ptr->ipp.PORTSC1.BIT.PortReset); */
        USB_HCI_PRINTF1("Suspend                    : %d\n", ptr->ipp->PORTSC1_b.SUSPEND);

        /* USB_HCI_PRINTF1("Force_Port_Resume          : %d\n", ptr->ipp.PORTSC1.BIT.ForcePortResume); */
        USB_HCI_PRINTF1("Over_Current_Change        : %d\n", ptr->ipp->PORTSC1_b.OVCC);
        USB_HCI_PRINTF1("Over_Current_Active        : %d\n", ptr->ipp->PORTSC1_b.OVCACT);
        USB_HCI_PRINTF1("Port_Enable_Disable_Change : %d\n", ptr->ipp->PORTSC1_b.PTESC);
        USB_HCI_PRINTF1("Port_Enabled               : %d\n", ptr->ipp->PORTSC1_b.PTE);
        USB_HCI_PRINTF1("Connect_Status_Change      : %d\n", ptr->ipp->PORTSC1_b.CSC);
        USB_HCI_PRINTF1("Current_Connect_Status     : %d\n", ptr->ipp->PORTSC1_b.CCSTS);
        USB_HCI_PRINTF0("\n");
    }
    else
    {
        /* USB_HCI_PRINTF1("WKOC_E                     : %d\n", ptr->ipp1.PORTSC1.BIT.WKOC_E);
         * USB_HCI_PRINTF1("WKDSCNNT_E                 : %d\n", ptr->ipp1.PORTSC1.BIT.WKDSCNNT_E);
         * USB_HCI_PRINTF1("WKCNNT_E                   : %d\n", ptr->ipp1.PORTSC1.BIT.WKCNNT_E);
         * USB_HCI_PRINTF1("Port_Test_Control          : %d\n", ptr->ipp1.PORTSC1.BIT.PortTestControl);
         * USB_HCI_PRINTF1("Port_IndicatorControl      : %d\n", ptr->ipp1.PORTSC1.BIT.PortIndicatorControl);*/
        USB_HCI_PRINTF1("Port_Owner                 : %d\n", ptr->ipp1->PORTSC1_b.PTOWNR);

        /* USB_HCI_PRINTF1("PP                         : %d\n", ptr->ipp1.PORTSC1.BIT.PP); */
        USB_HCI_PRINTF1("Line_Status                : %d\n", ptr->ipp1->PORTSC1_b.LINESTS);

        /* USB_HCI_PRINTF1("Port_Reset                 : %d\n", ptr->ipp1.PORTSC1.BIT.PortReset); */
        USB_HCI_PRINTF1("Suspend                    : %d\n", ptr->ipp1->PORTSC1_b.SUSPEND);

        /* USB_HCI_PRINTF1("Force_Port_Resume          : %d\n", ptr->ipp.PORTSC1.BIT.ForcePortResume); */
        USB_HCI_PRINTF1("Over_Current_Change        : %d\n", ptr->ipp1->PORTSC1_b.OVCC);
        USB_HCI_PRINTF1("Over_Current_Active        : %d\n", ptr->ipp1->PORTSC1_b.OVCACT);
        USB_HCI_PRINTF1("Port_Enable_Disable_Change : %d\n", ptr->ipp1->PORTSC1_b.PTESC);
        USB_HCI_PRINTF1("Port_Enabled               : %d\n", ptr->ipp1->PORTSC1_b.PTE);
        USB_HCI_PRINTF1("Connect_Status_Change      : %d\n", ptr->ipp1->PORTSC1_b.CSC);
        USB_HCI_PRINTF1("Current_Connect_Status     : %d\n", ptr->ipp1->PORTSC1_b.CCSTS);
        USB_HCI_PRINTF0("\n");
    }
}                                      /* End of function usb_hstd_ehci_print_port_information() */

 #endif

 #ifdef DEBUG_PRINT_ASYNC_SCHEDULING

/***********************************************************************************************************************
 * Function     : Asynchronization scheduling print
 * Declaration  : void usb_hstd_ehci_print_async_scheduling( st_usb_ehci_qh_t *h_qh )
 * Argument     : st_usb_ehci_qh_t *qh ; QH pointer
 * Return       : void
 * Note         : This function is used for debugging.
 ***********************************************************************************************************************/
static void usb_hstd_ehci_print_async_scheduling (st_usb_ehci_qh_t * p_h_qh)
{
    static st_usb_ehci_qh_t * p_keep_h_qh = NULL;
    st_usb_ehci_qh_t        * p_qh;
    uint32_t cnt = 0;
    uint32_t tmp_addr;

    if (NULL != p_h_qh)
    {
        p_keep_h_qh = p_h_qh;
    }

    USB_HCI_PRINTF0("\n--------------------------------------- Async Scheduling Start \n");

    p_qh = p_keep_h_qh;
    if (NULL == p_qh)
    {
        return;
    }
    else
    {
        while (1)
        {
            USB_HCI_PRINTF1("0x%X", (uint32_t) p_qh);
            if (1 == p_qh->endpoint1.bit.h)
            {
                USB_HCI_PRINTF0(" H = 1");
                cnt++;
                if (2 == cnt)
                {
                    USB_HCI_PRINTF0("\n");
                    break;
                }
            }

            USB_HCI_PRINTF0("\n");
  #if defined(BSP_MCU_GROUP_RZA_USB)
            tmp_addr = (r_usb_pa_to_va((uint64_t) p_qh->queue_head_horizontal_link.address & USB_VAL_XFFE0));
            p_qh     = (st_usb_ehci_qh_t *) tmp_addr;
  #else
            tmp_addr = r_usb_pa_to_va((uint32_t) p_qh->queue_head_horizontal_link.address & USB_VAL_XFFE0);
            p_qh     = (st_usb_ehci_qh_t *) tmp_addr;
  #endif
        }
    }

    USB_HCI_PRINTF0("----------------------------------------- Async Scheduling End \n\n");
}                                      /* End of function usb_hstd_ehci_print_async_scheduling() */

 #endif

 #ifdef DEBUG_PRINT_PERIODIC_SCHEDULING

/***********************************************************************************************************************
 * Function     : Print EHCI Periodec Scheduling List
 * Declaration  : void usb_hstd_ehci_print_periodec_scheduling_list( void )
 * Argument     : void
 * Return       : void
 * Note         : This function is used for debugging.
 ***********************************************************************************************************************/
static void usb_hstd_ehci_print_periodec_scheduling_list (usb_utr_t * ptr)
{
    uint32_t                     frame_list_size;
    uint32_t                     n;
    uint32_t                     periodic_list_addr;
    uint32_t                     tmp_addr;
    u_usb_ehci_flep_t          * p_listbase;
    volatile u_usb_ehci_flep_t * p_current_element;

    /* Get frame list size */
    frame_list_size = usb_hstd_ehci_get_frame_list_size();

    if (USB_IP0 == ptr->ip)
    {
        periodic_list_addr = ptr->ipp->PERIODICLISTBASE & USB_VAL_XF000;
    }
    else
    {
        periodic_list_addr = ptr->ipp1->PERIODICLISTBASE & USB_VAL_XF000;
    }

    if (0x00000000 == periodic_list_addr)
    {
        USB_HCI_PRINTF0_R("usb_hstd_ehci_print_periodec_scheduling_list Error : PERIODICLISTBASE is not registered. \n");

        return;
    }
    else if (0x00000000 != periodic_list_addr)
    {
  #if defined(BSP_MCU_GROUP_RZA_USB)
        periodic_list_addr = (r_usb_pa_to_va((uint64_t) periodic_list_addr));
  #else
        periodic_list_addr = r_usb_pa_to_va(periodic_list_addr);
  #endif
    }

    p_listbase = (u_usb_ehci_flep_t *) periodic_list_addr;
    for (n = 0; n < frame_list_size; n++)
    {
        p_current_element = &p_listbase[n];
        USB_HCI_PRINTF1("FLEP(%4d):", n);
        while (1)
        {
            if (NULL == p_current_element)
            {
                USB_HCI_PRINTF0_R(
                    "usb_hstd_ehci_print_periodec_scheduling_list Error: Current Element Pointer is NULL\n");

                return;
            }

            if (1 == p_current_element->bit.t)
            {
                break;
            }

  #if defined(BSP_MCU_GROUP_RZA_USB)
            tmp_addr = (r_usb_pa_to_va((uint64_t) p_current_element->Address & USB_VAL_XFFE0));
  #else
            tmp_addr = r_usb_pa_to_va((uint32_t) p_current_element->Address & USB_VAL_XFFE0);
  #endif

            switch (p_current_element->bit.typ)
            {
                case USB_EHCI_TYP_ITD:
                {
                    USB_HCI_PRINTF2(" (%d,%d)",
                                    ((st_usb_ehci_itd_t *) tmp_addr)->buffer[0].bit0.device_address,
                                    ((st_usb_ehci_itd_t *) tmp_addr)->info.pollrate);
                    break;
                }

                case USB_EHCI_TYP_QH:
                {
                    USB_HCI_PRINTF2(" (%d,%d)",
                                    ((st_usb_ehci_qh_t *) tmp_addr)->endpoint1.bit.device_address,
                                    ((st_usb_ehci_qh_t *) tmp_addr)->info.pollrate);
                    break;
                }

                case USB_EHCI_TYP_SITD:
                {
                    USB_HCI_PRINTF2(" (%d,%d)",
                                    ((st_usb_ehci_sitd_t *) tmp_addr)->endpoint1.bit.device_address,
                                    ((st_usb_ehci_sitd_t *) tmp_addr)->info.pollrate);
                    break;
                }

                default:
                {
                    break;
                }
            }

  #if defined(BSP_MCU_GROUP_RZA_USB)
            tmp_addr = (r_usb_pa_to_va((uint64_t) p_current_element->address & USB_VAL_XFFE0));
            p_qh     = (u_usb_ehci_flep_t *) tmp_addr;
  #else
            tmp_addr = r_usb_pa_to_va((uint32_t) p_current_element->address & USB_VAL_XFFE0);
            p_qh     = (u_usb_ehci_flep_t *) tmp_addr;
  #endif
        }

        USB_HCI_PRINTF0("\n");
    }
}                                      /* End of function usb_hstd_ehci_print_periodec_scheduling_list() */

 #endif

 #ifdef DEBUG_PRINT_PERIODIC_SCHEDULING

/***********************************************************************************************************************
 * Function     : EHCI Periodec Scheduling Score Print
 * Declaration  : void usb_hstd_ehci_print_periodic_scheduling_score( void )
 * Argument     : void
 * Return       : void
 * Note         : This function is used for debugging.
 ***********************************************************************************************************************/
static void usb_hstd_ehci_print_periodic_scheduling_score (void)
{
    uint32_t uframe_list_size;
    uint32_t n;

    /* Get micro frame list size */
    uframe_list_size  = usb_hstd_ehci_get_frame_list_size();
    uframe_list_size *= 8;

    for (n = 0; n < uframe_list_size; n++)
    {
        if (0 == (n % 8))
        {
            USB_HCI_PRINTF1("Score(%4d):", n / 8);
        }

        USB_HCI_PRINTF1(" %d", gs_usb_ehci_periodic_scheduling_score[n]);

        if (7 == (n % 8))
        {
            USB_HCI_PRINTF0("\n");
        }
    }
}                                      /* End of function usb_hstd_ehci_print_periodic_scheduling_score() */

 #endif
#endif  /* USB_IP_EHCI_OHCI == 1 */

/***********************************************************************************************************************
 * End Of File
 ***********************************************************************************************************************/
