/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * File Name    : r_usb_hOhciMain.c
 * Description  : OHCI Main Code
 ***********************************************************************************************************************/

/**********************************************************************************************************************
 * History : DD.MM.YYYY Version Description
 *         : 31.08.2015 1.00    First Release
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/
#include "r_usb_extern.h"
#include "r_usb_hhci_local.h"

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * External variables and functions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 ***********************************************************************************************************************/
#if  USB_IP_EHCI_OHCI == 1

 #define USB_VAL_32          (32U)
 #define USB_VAL_100         (100U)
 #define USB_VAL_XFF         (0x000000FFU)
 #define USB_VAL_X7F         (0x0000007FU)
 #define USB_VAL_XC0         (0x000000C0U)
 #define USB_VAL_X80         (0x00000080U)
 #define USB_VAL_FF32U       (0xFFFFFFFFU)
 #define USB_VAL_FMINTVL     (0x27782EDFU)
 #define USB_VAL_X10000      (0x10000U)
 #define USB_VAL_X8000       (0x8000U)
 #define USB_VAL_PESC_PES    (0x00020002U)
 #define USB_VAL_PESC        (0x00020000U)
 #define USB_VAL_PESC_CSC    (0x00030000U)
 #define USB_VAL_CSC_CCS     (0x00010001U)
 #define USB_VAL_CSC         (0x00010000U)
 #define USB_VAL_X001        (0x00000001U)
 #define USB_VAL_X0008U      (0x00080000U)
 #define USB_VAL_X10         (0x00000010U)
 #define USB_VAL_X001U       (0x00100000U)
 #define USB_VAL_X0004U      (0x00040000U)
 #define USB_VAL_X0004       (0x00000004U)
 #define USB_VAL_X0008B      (0x00000008U)
 #define USB_VAL_X8000U      (0x80000000U)
 #define USB_VAL_X8000B      (0x8000U)
 #define USB_VAL_X7FFFB      (0x7FFFU)
 #define USB_VAL_X3FFF       (0x00003FFFU)
 #define USB_VAL_2A2F        (0x2A2FU)
 #define USB_VAL_02001902    (0x02001902U)
 #define USB_VAL_X1000       (0x00001000U)
 #define USB_VAL_INTENB      (0x80000062U)
 #define USB_VAL_XFFFFU      (0xFFFF0000U)
 #define USB_VAL_X3C         (0x0000003CU)
 #define USB_VAL_X34         (0x00000034U)
 #define USB_VAL_X0002U      (0x00020000U)
 #define USB_VAL_X100        (0x00000100U)
 #define USB_VAL_X200        (0x00000200U)

/***********************************************************************************************************************
 * Static variables and functions
 ***********************************************************************************************************************/
static void     usb_hstd_ohci_hw_setup(usb_utr_t * ptr);
static uint32_t usb_hstd_ohci_hw_reset(usb_utr_t * ptr);
static void     usb_hstd_ohci_initailize_interrupt_lists(st_usb_ohci_hcd_device_data_p_t device_data);
static void     usb_hstd_ohci_clear_hcca(st_usb_ohci_hcd_device_data_p_t device_data);
static void     usb_hstd_ohci_clear_device_tr_req(usb_utr_t * ptr, uint32_t devadd);
static void     usb_hstd_ohci_rootport_connection(usb_utr_t                     * ptr,
                                                  st_usb_ohci_hcd_device_data_p_t devicedata,
                                                  uint8_t                         devspeed,
                                                  uint8_t                         portnum);
static void usb_hstd_ohci_rootport_disconnection(usb_utr_t                     * ptr,
                                                 st_usb_ohci_hcd_device_data_p_t devicedata,
                                                 uint8_t                         portnum);
static void    usb_hstd_ohci_remove_device(usb_utr_t * ptr, uint8_t device_address, boolean_t free_ed);
static uint8_t usb_hstd_ohci_get_root_device_speed(st_usb_ohci_hcd_device_data_p_t device_data, uint8_t portnum);
static void    usb_hstd_ohci_process_paused_ed(usb_utr_t * ptr, st_usb_ohci_hcd_endpoint_descriptor_p_t ed);
static void    usb_hstd_ohci_remove_ed(usb_utr_t * ptr, st_usb_ohci_hcd_endpoint_p_t endpoint, boolean_t free_ed);

BSP_ALIGN_VARIABLE(4) static st_usb_ohci_hcd_device_data_p_t usb_hstd_ohci_device_data USB_BUFFER_PLACE_IN_SECTION; /* __CC_ARM */

/***********************************************************************************************************************
 * Function     : Initialize OHCI
 * Declaration  : uint32_t usb_hstd_ohci_init( void )
 * Argument     : void
 * Return       : uint32_t ; status
 * Note         :
 ***********************************************************************************************************************/
uint32_t usb_hstd_ohci_init (usb_utr_t * ptr)
{
    usb_hstd_ohci_init_device_data();

    usb_hstd_ohci_clear_list();

    usb_hstd_ohci_init_request_memory();

    usb_hstd_ohci_hw_setup(ptr);

    return USB_OK;
}                                      /* End of function usb_hstd_ohci_init() */

 #if (USB_UT_MODE == 0)

/***********************************************************************************************************************
 * Function     : Deinitialize OHCI
 * Declaration  : void usb_hstd_ohci_deinit( void )
 * Argument     : void
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ohci_deinit (usb_utr_t * ptr)
{
    usb_hstd_ohci_hw_reset(ptr);       /* H/W reset */
} /* End of function usb_hstd_ohci_deinit() */

 #endif

/***********************************************************************************************************************
 * Function     : OHCI Detect interrupt
 * Declaration  : void usb_hstd_ohci_interrupt_handler( void )
 * Argument     : void
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ohci_interrupt_handler (usb_utr_t * ptr)
{
    uint32_t context_info = 0;
    uint32_t port_reg     = 0;
    uint32_t port_num     = 0;
    uint32_t hc_int_enable;
    uint32_t hc_int_status;
    st_usb_ohci_hcca_block_p_t tmp_hcca;
    uint32_t tmp_hcca_done_head;

    if (USB_IP0 == ptr->ip)
    {
        hc_int_status = ptr->ipp->HCINTERRUPTSTATUS;
        hc_int_enable = ptr->ipp->HCINTERRUPTENABLE;

        /* It is our interrupt, prevent HC from doing it to us again until we are finished */
        ptr->ipp->HCINTERRUPTDISABLE = USB_OHCI_IS_MASTERINTENABLE;
        ptr->ipp->HCINTERRUPTSTATUS  = (~USB_OHCI_IS_WRITEBACKDONEHEAD & hc_int_status);
    }
    else
    {
 #if USB_NUM_USBIP == 2
        hc_int_status = ptr->ipp1->HCINTERRUPTSTATUS;
        hc_int_enable = ptr->ipp1->HCINTERRUPTENABLE;

        /* It is our interrupt, prevent HC from doing it to us again until we are finished */
        ptr->ipp1->HCINTERRUPTDISABLE = USB_OHCI_IS_MASTERINTENABLE;
        ptr->ipp1->HCINTERRUPTSTATUS  = (~USB_OHCI_IS_WRITEBACKDONEHEAD & hc_int_status);
 #else
        hc_int_status = ptr->ipp->HCINTERRUPTSTATUS;
        hc_int_enable = ptr->ipp->HCINTERRUPTENABLE;

        /* It is our interrupt, prevent HC from doing it to us again until we are finished */
        ptr->ipp->HCINTERRUPTDISABLE = USB_OHCI_IS_MASTERINTENABLE;
        ptr->ipp->HCINTERRUPTSTATUS  = (~USB_OHCI_IS_WRITEBACKDONEHEAD & hc_int_status);
 #endif
    }

    port_reg = usb_hcrh_port_status1;
    port_num = usb_hcrh_descriptor_a;

    /* Is this our interrupt? */
 #if defined(BSP_MCU_GROUP_RZA_USB)
    tmp_hcca           = (st_usb_ohci_hcca_block_p_t) (r_usb_pa_to_va((uint64_t) usb_hstd_ohci_device_data->hcca));
    tmp_hcca_done_head = (uint32_t) r_usb_pa_to_va((uint64_t) tmp_hcca->hcca_done_head);
 #else                                 /* 0 */
    tmp_hcca           = (st_usb_ohci_hcca_block_p_t) usb_hstd_ohci_device_data->hcca;
    tmp_hcca_done_head = tmp_hcca->hcca_done_head;
 #endif /* 0 */
    if (0 != tmp_hcca_done_head)
    {
        context_info = USB_OHCI_IS_WRITEBACKDONEHEAD; /* note interrupt processing required */

        if (tmp_hcca_done_head & 1)
        {
            context_info |= (hc_int_status & hc_int_enable);
        }
    }
    else
    {
        context_info |= (hc_int_status & hc_int_enable);
        if (0 == context_info)
        {
            return;                    /* not my interrupt */
        }
    }

    usb_hstd_hci_send_message_from_int(ptr, USB_HCI_TASK, USB_HCI_MESS_OHCI_INT, context_info, port_reg, port_num);
}                                      /* End of function usb_hstd_ohci_interrupt_handler() */

/***********************************************************************************************************************
 * Function     : OHCI Main Routine
 * Declaration  : void usb_hstd_OhciMainRoutine( uint32_t context_info )
 * Argument     : uint32_t context_info ; Interrupt Context Infomation
 * Return       : void
 * Note         : This function is based on HcdInterruptService() of OHCI specification
 ***********************************************************************************************************************/
void usb_hstd_OhciMainRoutine (usb_utr_t * ptr, uint32_t context_info, uint32_t port_reg, uint32_t port_num)
{
    uint32_t temp  = 0;
    uint32_t temp2 = 0;
    uint32_t frame;
    uint32_t err;
    st_usb_ohci_hcca_block_p_t tmp_hcca;
    uint32_t                 * tmp_hcca_done_head;

    if (context_info & USB_OHCI_IS_UNRECOVERABLERROR)
    {
        /* The controller is hung, maybe resetting it can get it going again */
        /* But that code is left as an exercise tothe reader */
    }

    if (context_info &
        (USB_OHCI_IS_SCHEDULINGOVERRUN | USB_OHCI_IS_WRITEBACKDONEHEAD | USB_OHCI_IS_STARTOFFRAME |
         USB_OHCI_IS_FRAMENUMBEROVERRUN))
    {
        context_info |= USB_OHCI_IS_MASTERINTENABLE; /* flag for end of frame type interrupts */
    }

    /* Check for frame Number Overflow */
    /* Note: the formula below prevents a debugger break from making the 32-bit frame number run backward */
    if (context_info & USB_OHCI_IS_FRAMENUMBEROVERRUN)
    {
 #if defined(BSP_MCU_GROUP_RZA_USB)
        tmp_hcca = (st_usb_ohci_hcca_block_p_t) (r_usb_pa_to_va((uint64_t) usb_hstd_ohci_device_data->hcca));
 #else
        tmp_hcca = usb_hstd_ohci_device_data->hcca;
 #endif
        usb_hstd_ohci_device_data->frame_high_part += USB_VAL_X10000 -
                                                      ((tmp_hcca->hcca_frame_number ^
                                                        usb_hstd_ohci_device_data->frame_high_part) & USB_VAL_X8000);

        /* USB00->HCINTERRUPTSTATUS  = USB_OHCI_IS_FRAMENUMBEROVERRUN; */  /* acknowledge interrupt */
        context_info &= ~USB_OHCI_IS_FRAMENUMBEROVERRUN;
    }

    /* Processor interrupts could be enabled here and the interrupt dismissed at the interrupt */
    /* controller, but for simplicity this code won't */
    if (context_info & USB_OHCI_IS_RESUMEDETECTED)
    {
        /* Resume has been requested by a device on USB. HCD must wait 20ms then put controller */
        /* in the UsbOperational state. This code is left as an exercise to the reader */
        context_info &= ~USB_OHCI_IS_RESUMEDETECTED;

        /* USB00->HCINTERRUPTSTATUS = USB_OHCI_IS_RESUMEDETECTED; */
    }

    /* Process the Done Queue */
    if (context_info & USB_OHCI_IS_WRITEBACKDONEHEAD)
    {
 #if defined(BSP_MCU_GROUP_RZA_USB)
        tmp_hcca           = (st_usb_ohci_hcca_block_p_t) (r_usb_pa_to_va((uint64_t) usb_hstd_ohci_device_data->hcca));
        tmp_hcca_done_head = (uint32_t *) (r_usb_pa_to_va((uint64_t) tmp_hcca->hcca_done_head));
 #else
        tmp_hcca           = usb_hstd_ohci_device_data->hcca;
        tmp_hcca_done_head = (uint32_t *) tmp_hcca->hcca_done_head;
 #endif

        usb_hstd_ohci_process_done_queue(ptr, (uint32_t) (uintptr_t) tmp_hcca_done_head);

        /* Done Queue processing complete, notify controller */
        tmp_hcca->hcca_done_head = 0;
        if (USB_IP0 == ptr->ip)
        {
            ptr->ipp->HCINTERRUPTSTATUS = USB_OHCI_IS_WRITEBACKDONEHEAD;
        }
        else
        {
 #if USB_NUM_USBIP == 2
            ptr->ipp1->HCINTERRUPTSTATUS = USB_OHCI_IS_WRITEBACKDONEHEAD;
 #endif
        }

        context_info &= ~USB_OHCI_IS_WRITEBACKDONEHEAD;
    }

    /* Process Root Hub changes */
    if (context_info & USB_OHCI_IS_ROOTHUBSTATUSCHANGE)
    {
        /* EmulateRootHubInterruptXfer will complete a USB_OHCI_HCD_TRANSFER_DESCRIPTOR which */
        /* we then pass to usb_hstd_ohci_process_done_queue to emulate an HC completion */

        /* leave RootHubStatusChange set in context_info so that it will be masked off */
        /* (it won't be unmaskedagain until another TD is queued for the emulated endpoint) */
        usb_hstd_ohci_control_roothub(ptr, port_reg, port_num);

        /*  USB00->HCINTERRUPTSTATUS = 0x00000040; */    /* Clear RHSC bit */
        context_info &= ~USB_OHCI_IS_ROOTHUBSTATUSCHANGE;
    }

    if (context_info & USB_OHCI_IS_OWNERSHIPCHANGE)
    {
        /* Only SMM drivers need implement this */
        /* See Sections 5.1.1.3.3 and 5.1.1.3.6 for descriptions of what the code here must do */
    }

    /* Any interrupts left should just be masked out */
    /* (This is normal processing for StartOfFrame and RootHubStatusChange) */
    if (context_info & ~USB_OHCI_IS_MASTERINTENABLE)     /* any unprocessed interrupts? */
    {
        if (USB_IP0 == ptr->ip)
        {
            ptr->ipp->HCINTERRUPTDISABLE = context_info; /* yes, mask them */
        }
        else
        {
 #if USB_NUM_USBIP == 2
            ptr->ipp1->HCINTERRUPTDISABLE = context_info; /* yes, mask them */
 #endif
        }
    }

    /* We've completed the actual service of the HC interrupts, now we must deal with the effects */

    /* look for things on the PausedEDRestart list */
    frame = usb_hstd_ohci_get_32bit_frame_number(usb_hstd_ohci_device_data);
    while (FALSE == usb_hstd_ohci_is_list_empty(&usb_hstd_ohci_device_data->paused_ed_restart))
    {
        volatile st_usb_ohci_hcd_endpoint_descriptor_p_t ED;
 #if defined(BSP_MCU_GROUP_RZA_USB)
        ED =
            (st_usb_ohci_hcd_endpoint_descriptor_p_t) (uintptr_t) usb_hstd_ohci_scan_containing_record((
                                                                                                           st_usb_ohci_list_entry_p_t) (
                                                                                                           r_usb_pa_to_va((
                                                                                                                              uint64_t)
                                                                                                                          usb_hstd_ohci_device_data
                                                                                                                          ->
                                                                                                                          paused_ed_restart
                                                                                                                          .
                                                                                                                          f_link)),
                                                                                                       USB_OHCI_CR_ENDPOINT_DESCRIPTOR,
                                                                                                       USB_OHCI_CR_PAUSEDLINK);
 #else
        ED =
            (st_usb_ohci_hcd_endpoint_descriptor_p_t) usb_hstd_ohci_scan_containing_record(
                (st_usb_ohci_list_entry_p_t) usb_hstd_ohci_device_data->paused_ed_restart.f_link,
                USB_OHCI_CR_ENDPOINT_DESCRIPTOR,
                USB_OHCI_CR_PAUSEDLINK);
 #endif

        if ((int32_t) (ED->reclamation_frame - frame) > 0)
        {
            break;
        }

        if (NULL == ED)
        {
            usb_hstd_ohci_remove_list_entry(&usb_hstd_ohci_device_data->paused_ed_restart);
            break;
        }

        usb_hstd_ohci_remove_list_entry(&ED->paused_link);
        ED->paused_flag = FALSE;
        usb_hstd_ohci_process_paused_ed(ptr, ED);
    }

    /* look for things on the StalledEDReclamation list */
    err = usb_hstd_ohci_is_list_empty(&usb_hstd_ohci_device_data->stalled_ed_reclamation);
    if ((context_info & USB_OHCI_IS_MASTERINTENABLE) && (FALSE == err))
    {
        if (USB_IP0 == ptr->ip)
        {
            temp  = ptr->ipp->HCCONTROLCURRENTED;
            temp2 = ptr->ipp->HCBULKCURRENTED;
        }
        else
        {
 #if USB_NUM_USBIP == 2
            temp  = ptr->ipp1->HCCONTROLCURRENTED;
            temp2 = ptr->ipp1->HCBULKCURRENTED;
 #endif
        }

        while (FALSE == usb_hstd_ohci_is_list_empty(&usb_hstd_ohci_device_data->stalled_ed_reclamation))
        {
            volatile st_usb_ohci_hcd_endpoint_descriptor_p_t ED;

 #if defined(BSP_MCU_GROUP_RZA_USB)
            ED =
                (st_usb_ohci_hcd_endpoint_descriptor_p_t) (uintptr_t) usb_hstd_ohci_scan_containing_record((
                                                                                                               st_usb_ohci_list_entry_p_t) (
                                                                                                               r_usb_pa_to_va((
                                                                                                                                  uint64_t)
                                                                                                                              usb_hstd_ohci_device_data
                                                                                                                              ->
                                                                                                                              stalled_ed_reclamation
                                                                                                                              .
                                                                                                                              f_link)),
                                                                                                           USB_OHCI_CR_ENDPOINT_DESCRIPTOR,
                                                                                                           USB_OHCI_CR_LINK);
 #else
            ED =
                (st_usb_ohci_hcd_endpoint_descriptor_p_t) usb_hstd_ohci_scan_containing_record((
                                                                                                   st_usb_ohci_list_entry_p_t) usb_hstd_ohci_device_data->stalled_ed_reclamation.f_link,
                                                                                               USB_OHCI_CR_ENDPOINT_DESCRIPTOR,
                                                                                               USB_OHCI_CR_LINK);
 #endif
            if (NULL == ED)
            {
                usb_hstd_ohci_remove_list_entry(&usb_hstd_ohci_device_data->stalled_ed_reclamation);
                break;
            }

            usb_hstd_ohci_remove_list_entry(&ED->link);
            if (ED->physical_address == temp)
            {
 #if defined(BSP_MCU_GROUP_RZA_USB)
                if (USB_IP0 == ptr->ip)
                {
                    ptr->ipp->HCCONTROLCURRENTED = (uint32_t) usb_hstd_ohci_physical_address_of(
                        (void *) (uintptr_t) ED->hc_ed.next_ed);
                    temp = (uint32_t) usb_hstd_ohci_physical_address_of((void *) (uintptr_t) ED->hc_ed.next_ed);
                }
                else
                {
  #if USB_NUM_USBIP == 2
                    ptr->ipp1->HCCONTROLCURRENTED = (uint32_t) usb_hstd_ohci_physical_address_of(
                        (void *) (uintptr_t) ED->hc_ed.next_ed);
                    temp = (uint32_t) usb_hstd_ohci_physical_address_of((void *) (uintptr_t) ED->hc_ed.next_ed);
  #endif
                }
 #else
                ptr->ipp->HCCONTROLCURRENTED = temp = ED->hc_ed.next_ed;
 #endif
            }
            else if (ED->physical_address == temp2)
            {
 #if defined(BSP_MCU_GROUP_RZA_USB)
                if (USB_IP0 == ptr->ip)
                {
                    ptr->ipp->HCBULKCURRENTED = (uint32_t) usb_hstd_ohci_physical_address_of(
                        (void *) (uintptr_t) ED->hc_ed.next_ed);
                    temp2 = (uint32_t) usb_hstd_ohci_physical_address_of((void *) (uintptr_t) ED->hc_ed.next_ed);
                }
                else
                {
  #if USB_NUM_USBIP == 2
                    ptr->ipp1->HCBULKCURRENTED = (uint32_t) usb_hstd_ohci_physical_address_of(
                        (void *) (uintptr_t) ED->hc_ed.next_ed);
                    temp2 = (uint32_t) usb_hstd_ohci_physical_address_of((void *) (uintptr_t) ED->hc_ed.next_ed);
  #endif
                }
 #else
                ptr->ipp->HCBULKCURRENTED = temp2 = ED->hc_ed.next_ed;
 #endif
            }
            else
            {
                /* None */
            }

 #if defined(BSP_MCU_GROUP_RZA_USB)
            if (0 != ED->endpoint)
 #else
            if (NULL != ED->endpoint)
 #endif
            {
                usb_hstd_ohci_process_paused_ed(ptr, ED); /* cancel any outstanding TDs */
                usb_hstd_ohci_free_endpoint_descriptor(ED);
            }
            else
            {
                usb_hstd_ohci_free_endpoint_descriptor(ED);
            }
        }

        if (USB_IP0 == ptr->ip)
        {
            ptr->ipp->HCCONTROL |=
                (USB_OHCI_CONTROLLISTENABLE | USB_OHCI_BULKLISTENABLE | USB_OHCI_ISOCHRONOUSENABLE |
                 USB_OHCI_PERIODICLISTENABLE); /* restart queues */
        }
        else
        {
 #if USB_NUM_USBIP == 2
            ptr->ipp1->HCCONTROL |=
                (USB_OHCI_CONTROLLISTENABLE | USB_OHCI_BULKLISTENABLE | USB_OHCI_ISOCHRONOUSENABLE |
                 USB_OHCI_PERIODICLISTENABLE); /* restart queues */
 #endif
        }
    }

    /* look for things on the RunningEDReclamation list */
    frame = usb_hstd_ohci_get_32bit_frame_number(usb_hstd_ohci_device_data);
    while (FALSE == usb_hstd_ohci_is_list_empty(&usb_hstd_ohci_device_data->running_ed_reclamation))
    {
        volatile st_usb_ohci_hcd_endpoint_descriptor_p_t ED;
 #if defined(BSP_MCU_GROUP_RZA_USB)
        ED =
            (st_usb_ohci_hcd_endpoint_descriptor_p_t) (uintptr_t) usb_hstd_ohci_scan_containing_record((
                                                                                                           st_usb_ohci_list_entry_p_t) (
                                                                                                           r_usb_pa_to_va((
                                                                                                                              uint64_t)
                                                                                                                          usb_hstd_ohci_device_data
                                                                                                                          ->
                                                                                                                          running_ed_reclamation
                                                                                                                          .
                                                                                                                          f_link)),
                                                                                                       USB_OHCI_CR_ENDPOINT_DESCRIPTOR,
                                                                                                       USB_OHCI_CR_LINK);
 #else
        ED =
            (st_usb_ohci_hcd_endpoint_descriptor_p_t) usb_hstd_ohci_scan_containing_record(
                (st_usb_ohci_list_entry_p_t) usb_hstd_ohci_device_data->running_ed_reclamation.f_link,
                USB_OHCI_CR_ENDPOINT_DESCRIPTOR,
                USB_OHCI_CR_LINK);
 #endif

        if ((int32_t) (ED->reclamation_frame - frame) > 0)
        {
            break;
        }

        if (NULL == ED)
        {
            usb_hstd_ohci_remove_list_entry(&usb_hstd_ohci_device_data->running_ed_reclamation);
            break;
        }

        usb_hstd_ohci_remove_list_entry(&ED->link);
 #if defined(BSP_MCU_GROUP_RZA_USB)
        if (0 != ED->endpoint)
 #else
        if (NULL != ED->endpoint)
 #endif
        {
            usb_hstd_ohci_process_paused_ed(ptr, ED); /* cancel any outstanding TDs */
            usb_hstd_ohci_free_endpoint_descriptor(ED);
        }
        else
        {
            usb_hstd_ohci_free_endpoint_descriptor(ED);
        }
    }

    /* If processor interrupts were enabled earlier then they must be disabled here before we re-enable the interrupts at the controller */
    if (USB_IP0 == ptr->ip)
    {
        ptr->ipp->HCINTERRUPTENABLE = USB_OHCI_IS_MASTERINTENABLE;
    }
    else
    {
 #if USB_NUM_USBIP == 2
        ptr->ipp1->HCINTERRUPTENABLE = USB_OHCI_IS_MASTERINTENABLE;
 #endif
    }
}                                      /* End of function usb_hstd_OhciMainRoutine() */

/***********************************************************************************************************************
 * Function     : OHCI Control RootHub
 * Declaration  : void usb_hstd_ohci_control_roothub( void )
 * Argument     : void
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ohci_control_roothub (usb_utr_t * ptr, uint32_t port_reg, uint32_t port_num)
{
    uint32_t * volatile        p_port_status_reg;
    uint8_t                    dev_speed;
    st_usb_ohci_hcca_block_p_t tmp_hcca;
    uint32_t                 * tmp_hcca_done_head;

    FSP_PARAMETER_NOT_USED(port_num);

    /*  Detect DisConnection */
    if ((port_reg & USB_VAL_PESC_PES) == USB_VAL_PESC)
    {
        r_usb_hstd_hci_wait_time(ptr, USB_VAL_32);
 #if defined(BSP_MCU_GROUP_RZA_USB)
        tmp_hcca           = (st_usb_ohci_hcca_block_p_t) (r_usb_pa_to_va((uint64_t) usb_hstd_ohci_device_data->hcca));
        tmp_hcca_done_head = (uint32_t *) (r_usb_pa_to_va((uint64_t) tmp_hcca->hcca_done_head));
 #else
        tmp_hcca           = usb_hstd_ohci_device_data->hcca;
        tmp_hcca_done_head = (uint32_t *) tmp_hcca->hcca_done_head;
 #endif
        if (0 != tmp_hcca_done_head)
        {
            usb_hstd_ohci_process_done_queue(ptr, (uint32_t) (uintptr_t) tmp_hcca_done_head);

            /* Done Queue processing complete, notify controller */
            tmp_hcca->hcca_done_head = 0;
            if (USB_IP0 == ptr->ip)
            {
                ptr->ipp->HCINTERRUPTSTATUS = USB_OHCI_IS_WRITEBACKDONEHEAD;
            }
            else
            {
 #if USB_NUM_USBIP == 2
                ptr->ipp1->HCINTERRUPTSTATUS = USB_OHCI_IS_WRITEBACKDONEHEAD;
 #endif
            }
        }

        /* r_usb_hstd_hci_wait_time(1); */
        usb_hstd_ohci_rootport_disconnection(ptr, usb_hstd_ohci_device_data, ptr->ip);
        usb_cpu_delay_xms(1);

        if (USB_IP0 == ptr->ip)
        {
            ptr->ipp->HCRHPORTSTATUS1 = USB_VAL_PESC_CSC; /* Clear PESC & CSC bit */
        }
        else
        {
 #if USB_NUM_USBIP == 2
            ptr->ipp1->HCRHPORTSTATUS1 = USB_VAL_PESC_CSC; /* Clear PESC & CSC bit */
 #endif
        }
    }
    else
    {
        if (USB_IP0 == ptr->ip)
        {
            p_port_status_reg = (uint32_t *) &(ptr->ipp->HCRHPORTSTATUS1);
        }
        else
        {
 #if USB_NUM_USBIP == 2
            p_port_status_reg = (uint32_t *) &(ptr->ipp1->HCRHPORTSTATUS1);
 #else
            p_port_status_reg = (uint32_t *) &(ptr->ipp->HCRHPORTSTATUS1);
 #endif
        }

        if ((*p_port_status_reg & USB_VAL_CSC_CCS) == USB_VAL_CSC_CCS)
        {
            /*  Detect Connection */
            *p_port_status_reg = USB_VAL_CSC; /* Clear CSC bit */
            usb_hstd_ohci_port_reset(ptr);

            if ((*p_port_status_reg & USB_VAL_X001) == 0x00000000)
            {
                return;
            }

            /* Report USBD-Layer */
            dev_speed = usb_hstd_ohci_get_root_device_speed(usb_hstd_ohci_device_data, ptr->ip);
            usb_hstd_ohci_rootport_connection(ptr, usb_hstd_ohci_device_data, dev_speed, ptr->ip);
        }

        if ((*p_port_status_reg & USB_VAL_X0008U) == USB_VAL_X0008U)
        {
            /*  Detect OverCurrent */
            *p_port_status_reg = USB_VAL_X0008U; /* Clear OCIC bit */

            usb_cpu_delay_xms(10);

            /* over current callback */
            g_usb_hstd_hci_callback.over_current_cb(ptr);
        }
    }
}                                      /* End of function usb_hstd_ohci_control_roothub() */

/***********************************************************************************************************************
 * Function     : OHCI Device Disconnect
 * Declaration  : void usb_hstd_ohci_disconnect( uint32_t devadd )
 * Argument     : uint32_t devadd ; device address
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ohci_disconnect (usb_utr_t * ptr, uint32_t devadd)
{
    uint8_t free_ed = TRUE;

    if (USB_HCI_NODEVICE == devadd)
    {
        return;
    }

    usb_hstd_ohci_clear_device_tr_req(ptr, devadd);

    usb_hstd_ohci_remove_device(ptr, (uint8_t) devadd, free_ed);
}                                      /* End of function usb_hstd_ohci_disconnect() */

/***********************************************************************************************************************
 * Function     : OHCI Getting of device address of rootpoot
 * Declaration  : uint16_t usb_hstd_ohci_get_device_address_of_rootpoot( uint16_t rootport )
 * Argument     : uint16_t rootport ; rootport no
 * Return       : uint16_t          ; device address
 * Note         :
 ***********************************************************************************************************************/
uint16_t usb_hstd_ohci_get_device_address_of_rootpoot (uint16_t rootport)
{
    if (USB_OHCI_MAXROOTPORTS > rootport)
    {
        return usb_hstd_ohci_device_data->root_device[rootport];
    }

    return USB_HCI_NODEVICE;
}                                      /* End of function usb_hstd_ohci_get_device_address_of_rootpoot() */

/***********************************************************************************************************************
 * Function     : The device address of OHCI route port is set.
 * Declaration  : uint16_t usb_hstd_ohci_set_device_address_of_rootpoot( uint16_t rootport, uint16_t devaddr )
 * Argument     : uint16_t rootport ; rootport no
 *              : uint16_t devaddr  ; device address
 * Return       : uint16_t          ; device address
 * Note         :
 ***********************************************************************************************************************/
uint16_t usb_hstd_ohci_set_device_address_of_rootpoot (uint16_t rootport, uint16_t deviceaddr)
{
    st_usb_hci_device_t * p_devinfo;

    if (USB_OHCI_MAXROOTPORTS <= rootport)
    {
        return USB_HCI_NODEVICE;
    }

    if (0 != usb_hstd_ohci_device_data->root_device[rootport])
    {
        /* USB_HCI_PRINTF1_R("Error: The device address has already been allocated to the route port %d.\n", rootport); */
        return USB_HCI_NODEVICE;
    }

    /* The device address of device information is updated */
    p_devinfo = r_usb_hstd_hci_get_device_infomation(usb_hstd_ohci_device_data->root_device[rootport]);
    if (NULL == p_devinfo)
    {
        return USB_HCI_NODEVICE;
    }

    p_devinfo->bit.devnum = (uint8_t) deviceaddr & USB_VAL_7FU8;

    usb_hstd_ohci_device_data->root_device[rootport] = (uint8_t) deviceaddr;

    return deviceaddr;
}                                      /* End of function usb_hstd_ohci_set_device_address_of_rootpoot() */

/***********************************************************************************************************************
 * Function     : OHCI Port Reset
 * Declaration  : void usb_hstd_ohci_port_reset( usb_utr_t * ptr)
 * Argument     : uint32_t portnum ; port no
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ohci_port_reset (usb_utr_t * ptr)
{
    uint32_t * volatile p_port_status_reg;

    if (USB_IP0 == ptr->ip)
    {
        p_port_status_reg = (uint32_t *) &(ptr->ipp->HCRHPORTSTATUS1);
    }
    else
    {
 #if USB_NUM_USBIP == 2
        p_port_status_reg = (uint32_t *) &(ptr->ipp1->HCRHPORTSTATUS1);
 #else
        p_port_status_reg = (uint32_t *) &(ptr->ipp->HCRHPORTSTATUS1);
 #endif
    }

    /* Wait of ECHI ehough */

    /* r_usb_hstd_hci_wait_time(100);      Wait 100ms */

    /* Port* Reset */
    *p_port_status_reg = USB_VAL_X10;
    while ((*p_port_status_reg & USB_VAL_X001U) == 0x00000000) /* Wait Port*-Enable */
    {
        if ((*p_port_status_reg & USB_VAL_X001) == 0x00000000) /* if device is dis-connect */
        {
            break;
        }

        usb_cpu_delay_xms(1);
    }

    *p_port_status_reg = USB_VAL_X001U; /* Clear PRSC bit */

 #ifdef USB_CFG_HMSC_USE
    R_BSP_SoftwareDelay(USB_VAL_100, BSP_DELAY_UNITS_MILLISECONDS);
 #else
    R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MILLISECONDS);
 #endif                                /* Wait 10ms */
} /* End of function usb_hstd_ohci_port_reset() */

/***********************************************************************************************************************
 * Function     : Getting of OHCI PID Status
 * Declaration  : uint16_t usb_hstd_ohci_get_pid_status( st_usb_hci_tr_req_t *tr_req )
 * Argument     : st_usb_hci_tr_req_t *tr_req ; transfer request pointer
 * Return       : uint16_t               ; PID Status
 * Note         :
 ***********************************************************************************************************************/
uint16_t usb_hstd_ohci_get_pid_status (st_usb_hci_tr_req_t * p_tr_req)
{
    st_usb_ohci_request_p_t ohci_req;
    uint32_t                status;

    if (NULL != p_tr_req)
    {
        if (TRUE == p_tr_req->bit.enable)
        {
 #if defined(BSP_MCU_GROUP_RZA_USB)
            ohci_req = (st_usb_ohci_request_p_t) (r_usb_pa_to_va((uint64_t) p_tr_req->hci_info));
 #else
            ohci_req = (st_usb_ohci_request_p_t) p_tr_req->hci_info;
 #endif
            status = ohci_req->status;
            if (USB_OHCI_CC_STALL == status)
            {
                return USB_PID_STALL;
            }

            if (USB_OHCI_CC_NOERROR == status)
            {
                return USB_PID_BUF;
            }
        }
    }

    return USB_PID_NAK;
}                                      /* End of function usb_hstd_ohci_get_pid_status() */

/***********************************************************************************************************************
 * Function     : OHCI Port Suspend
 * Declaration  : void usb_hstd_ohci_port_suspend( uint16_t port )
 * Argument     : uint16_t port ; port no
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ohci_port_suspend (usb_utr_t * ptr)
{
    uint32_t * p_port_status_reg;

    if (USB_IP0 == ptr->ip)
    {
        p_port_status_reg = (uint32_t *) &(ptr->ipp->HCRHPORTSTATUS1);
    }
    else
    {
 #if USB_NUM_USBIP == 2
        p_port_status_reg = (uint32_t *) &(ptr->ipp1->HCRHPORTSTATUS1);
 #else                                 /* #if USB_NUM_USBIP == 2 */
        p_port_status_reg = (uint32_t *) &(ptr->ipp->HCRHPORTSTATUS1);
 #endif /* #if USB_NUM_USBIP == 2 */
    }

    *p_port_status_reg = USB_VAL_X0004; /* Port* Suspend */
} /* End of function usb_hstd_ohci_port_suspend() */

/***********************************************************************************************************************
 * Function     : OHCI Port Resume
 * Declaration  : void usb_hstd_ohci_port_resume( uint16_t port )
 * Argument     : uint16_t port ; port no
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ohci_port_resume (usb_utr_t * ptr)
{
    uint32_t * p_port_status_reg;

    if (USB_IP0 == ptr->ip)
    {
        p_port_status_reg = (uint32_t *) &(ptr->ipp->HCRHPORTSTATUS1);
    }
    else
    {
 #if USB_NUM_USBIP == 2
        p_port_status_reg = (uint32_t *) &(ptr->ipp1->HCRHPORTSTATUS1);
 #else
        p_port_status_reg = (uint32_t *) &(ptr->ipp->HCRHPORTSTATUS1);
 #endif
    }

    /* Port* Resume */
    *p_port_status_reg = USB_VAL_X0008B;
    while ((*p_port_status_reg & USB_VAL_X0004U) == 0x00000000) /* Wait Port*-Resume wait */
    {
        if ((*p_port_status_reg & USB_VAL_X001) == 0x00000000)  /* if device is dis-connect */
        {
            break;
        }

        usb_cpu_delay_xms(1);
    }

    *p_port_status_reg = USB_VAL_X0004U; /* Clear PSSC bit */
} /* End of function usb_hstd_ohci_port_resume() */

/***********************************************************************************************************************
 * Function     : Getting of OHCI Transfer End Status
 * Declaration  : uint16_t usb_hstd_ohci_get_transfer_end_status( st_usb_hci_tr_req_t *tr_req )
 * Argument     : st_usb_hci_tr_req_t *tr_req ; HCI transfer request pointer
 * Return       : uint16_t               ; USB Standard F/W Transfer End Status
 * Note         :
 ***********************************************************************************************************************/
uint16_t usb_hstd_ohci_get_transfer_end_status (st_usb_hci_tr_req_t * p_tr_req)
{
    uint32_t status;
    uint16_t ret = USB_DATA_ERR;

    status = p_tr_req->status;

    if (USB_OHCI_CC_NOERROR == status)
    {
        if (USB_EP_CNTRL == p_tr_req->bit.eptype)
        {
            /* For control */
            ret = USB_CTRL_END;
        }
        else if (USB_EP_ISO == p_tr_req->bit.eptype)
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
        else
        {
            /* For bulk/interrupt */
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
    else
    {
        if (USB_EP_ISO == p_tr_req->bit.eptype)
        {
            if (USB_OHCI_CC_DATAOVERRUN == status)
            {
                /* For isochronous */
                if (USB_HCI_DIRECTION_OUT == p_tr_req->bit.direction)
                {
                    ret = USB_DATA_WRITING;
                }
                else
                {
                    /* When receive data is size over */
                    ret = USB_DATA_OVR;
                }
            }
        }
        else
        {
            if (USB_OHCI_CC_DATAUNDERRUN == status)
            {
                ret = USB_DATA_OK;
            }
            else if (USB_OHCI_CC_STALL == status)
            {
                /* For STALL */
                ret = USB_DATA_STALL;
            }
            else if (USB_OHCI_CC_DEVICENOTRESPOND == status)
            {
                /* Transfer stop by Detach */
                ret = USB_DATA_STOP;
            }
            else if (USB_OHCI_RS_CANCELED == status)
            {
                /* Transfer stop by Cancel */
                ret = USB_DATA_STOP;
            }
            else
            {
                /* None */
            }
        }
    }

    return ret;
}                                      /* End of function usb_hstd_ohci_get_transfer_end_status() */

/***********************************************************************************************************************
 * Function     : OHCI Remove Endpoint/ED
 * Declaration  : uint32_t usb_hstd_ohci_remove_endpoint( uint8_t device_address, uint8_t endpoint_number, uint8_t direction, boolean_t free_ed )
 * Argument     : uint8_t device_address  ; device address
 *              : uint8_t endpoint_number ; endpoint no
 *              : uint8_t direction       ; direction
 *              : boolean_t free_ed       ; free flag
 * Return       : uint32_t                : result( TRUE:Nomal End, FALSE:Fail )
 * Note         :
 ***********************************************************************************************************************/
uint32_t usb_hstd_ohci_remove_endpoint (usb_utr_t * ptr,
                                        uint8_t     device_address,
                                        uint8_t     endpoint_number,
                                        uint8_t     direction,
                                        boolean_t   free_ed)
{
    st_usb_ohci_hcd_endpoint_p_t endpoint;

    /* uint32_t                        hcd_ed_tmp; */
    uint32_t ret = FALSE;

    endpoint = usb_hstd_ohci_scan_endpoint(device_address, endpoint_number, direction);
    if (NULL != endpoint)
    {
        /* hcd_ed_tmp = r_usb_pa_to_va((uint32_t)endpoint->hcd_ed); */
        usb_hstd_ohci_remove_ed(ptr, endpoint, free_ed);
        if (TRUE == free_ed)
        {
            usb_hstd_ohci_free_endpoint(endpoint);

/* usb_hstd_ohci_release_ed(hcd_ed_tmp); */
        }

        usb_hstd_ohci_store_endpoint(device_address, endpoint_number, direction, NULL);

        ret = TRUE;
    }

    return ret;
}                                      /* End of function usb_hstd_ohci_remove_endpoint() */

/***********************************************************************************************************************
 * Function     : OHCI Pause ED
 * Declaration  : uint32_t usb_hstd_ohci_pause_endpoint( uint8_t device_address, uint8_t endpoint_number, uint8_t direction )
 * Argument     : uint8_t device_address  ; device address
 *              : uint8_t endpoint_number ; endpoint no
 *              : uint8_t direction       ; direction
 * Return       : uint32_t                : result( TRUE:Nomal End, FALSE:Fail )
 * Note         :
 ***********************************************************************************************************************/
uint32_t usb_hstd_ohci_pause_endpoint (usb_utr_t * ptr,
                                       uint8_t     device_address,
                                       uint8_t     endpoint_number,
                                       uint8_t     direction)
{
    st_usb_ohci_hcd_endpoint_p_t endpoint;
    uint32_t ret = FALSE;

    endpoint = usb_hstd_ohci_scan_endpoint(device_address, endpoint_number, direction);
    if (NULL != endpoint)
    {
        usb_hstd_ohci_pause_ed(ptr, endpoint);
        ret = TRUE;
    }

    return ret;
}                                      /* End of function usb_hstd_ohci_pause_endpoint() */

/***********************************************************************************************************************
 * Function     : OHCI Remove ListHead
 * Declaration  : st_usb_ohci_list_entry_p_t usb_hstd_ohci_remove_list_head( st_usb_ohci_list_entry_p_t list )
 * Argument     : st_usb_ohci_list_entry_p_t list ; remove list head pointer
 * Return       : st_usb_ohci_list_entry_p_t      ; next link list pointer
 * Note         :
 ***********************************************************************************************************************/
st_usb_ohci_list_entry_p_t usb_hstd_ohci_remove_list_head (st_usb_ohci_list_entry_p_t list)
{
    st_usb_ohci_list_entry_t * p_ret_list;
    st_usb_ohci_list_entry_p_t tmp_f_link;
    st_usb_ohci_list_entry_p_t tmp_b_link;

 #if defined(BSP_MCU_GROUP_RZA_USB)
    p_ret_list = (st_usb_ohci_list_entry_t *) (r_usb_pa_to_va((uint64_t) list->f_link));
    tmp_f_link = (st_usb_ohci_list_entry_p_t) (r_usb_pa_to_va((uint64_t) list->f_link));
    tmp_b_link = (st_usb_ohci_list_entry_p_t) (r_usb_pa_to_va((uint64_t) list->b_link));
 #else
    p_ret_list = (st_usb_ohci_list_entry_t *) list->f_link;
    tmp_f_link = (st_usb_ohci_list_entry_p_t) list->f_link;
    tmp_b_link = (st_usb_ohci_list_entry_p_t) list->b_link;
 #endif

    if (tmp_f_link == tmp_b_link)
    {
        tmp_b_link = NULL;
        tmp_f_link = NULL;
 #if defined(BSP_MCU_GROUP_RZA_USB)
        list->b_link = 0;
        list->f_link = 0;
 #else
        list->b_link = NULL;
        list->f_link = NULL;
 #endif
    }
    else
    {
 #if defined(BSP_MCU_GROUP_RZA_USB)
        list->f_link = (uint32_t) r_usb_va_to_pa((uint64_t) tmp_f_link->f_link);
 #else
        list->f_link = (st_usb_ohci_list_entry_t *) tmp_f_link->f_link;
 #endif
    }

    return p_ret_list;
}                                      /* End of function usb_hstd_ohci_remove_list_head() */

/***********************************************************************************************************************
 * Function     : OHCI Remove ListEntry
 * Declaration  : void usb_hstd_ohci_remove_list_entry( st_usb_ohci_list_entry_p_t list )
 * Argument     : st_usb_ohci_list_entry_p_t list ; remove list pointer
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ohci_remove_list_entry (st_usb_ohci_list_entry_p_t list)
{
    st_usb_ohci_list_entry_t * p_list_head;
    st_usb_ohci_list_entry_p_t tmp_f_link;
    st_usb_ohci_list_entry_p_t tmp_b_link;

 #if defined(BSP_MCU_GROUP_RZA_USB)
    tmp_f_link = (st_usb_ohci_list_entry_p_t) (r_usb_pa_to_va((uint64_t) list->f_link));
    tmp_b_link = (st_usb_ohci_list_entry_p_t) (r_usb_pa_to_va((uint64_t) list->b_link));
 #else
    tmp_f_link = (st_usb_ohci_list_entry_p_t) list->f_link;
    tmp_b_link = (st_usb_ohci_list_entry_p_t) list->b_link;
 #endif

    if ((NULL == tmp_b_link) && (NULL == tmp_f_link))
    {
        return;
    }

    if (tmp_b_link == tmp_f_link)
    {
 #if defined(BSP_MCU_GROUP_RZA_USB)
        p_list_head         = (st_usb_ohci_list_entry_t *) (r_usb_pa_to_va((uint64_t) list->b_link));
        p_list_head->f_link = 0;
        p_list_head->b_link = 0;
 #else
        p_list_head         = (st_usb_ohci_list_entry_t *) list->b_link;
        p_list_head->f_link = NULL;
        p_list_head->b_link = NULL;
 #endif
    }
    else
    {
 #if defined(BSP_MCU_GROUP_RZA_USB)
        if (NULL != tmp_b_link)
        {
            tmp_b_link->f_link = (uint32_t) r_usb_pa_to_va((uint64_t) list->f_link);
        }

        if (NULL != tmp_f_link)
        {
            tmp_f_link->b_link = (uint32_t) r_usb_pa_to_va((uint64_t) list->b_link);
        }
 #else
        if (NULL != tmp_b_link)
        {
            tmp_b_link->f_link = (st_usb_ohci_list_entry_t *) list->f_link; /* check */
        }

        if (NULL != tmp_f_link)
        {
            tmp_f_link->b_link = (st_usb_ohci_list_entry_t *) list->b_link;
        }
 #endif
    }

    tmp_f_link = NULL;
    tmp_b_link = NULL;
 #if defined(BSP_MCU_GROUP_RZA_USB)
    list->b_link = 0;
    list->f_link = 0;
 #else
    list->b_link = NULL;
    list->f_link = NULL;
 #endif
}                                      /* End of function usb_hstd_ohci_remove_list_entry() */

/***********************************************************************************************************************
 * Function     : OHCI Initialize ListHead
 * Declaration  : void usb_hstd_ohci_initialize_list_head( st_usb_ohci_list_entry_p_t list )
 * Argument     : st_usb_ohci_list_entry_p_t list ; list pointer
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ohci_initialize_list_head (st_usb_ohci_list_entry_p_t list)
{
 #if defined(BSP_MCU_GROUP_RZA_USB)
    list->f_link = 0;
    list->b_link = 0;
 #else
    list->f_link = NULL;
    list->b_link = NULL;
 #endif
}                                      /* End of function usb_hstd_ohci_initialize_list_head() */

/***********************************************************************************************************************
 * Function     : Judge List is empty or not
 * Declaration  : uint32_t usb_hstd_ohci_is_list_empty( st_usb_ohci_list_entry_p_t list )
 * Argument     : st_usb_ohci_list_entry_p_t list ; List pointer
 * Return       : uint32_t                   ; result( TRUE:Empty, FALSE:Not Empty )
 * Note         :
 ***********************************************************************************************************************/
uint32_t usb_hstd_ohci_is_list_empty (st_usb_ohci_list_entry_p_t list)
{
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (0 == (r_usb_pa_to_va((uint64_t) list->f_link)))
 #else
    if (NULL == list->f_link)
 #endif
    {
        return TRUE;
    }

    return FALSE;
}                                      /* End of function usb_hstd_ohci_is_list_empty() */

/***********************************************************************************************************************
 * Function     : OHCI Insert list to the head of list
 * Declaration  : void usb_hstd_ohci_insert_head_list( st_usb_ohci_list_entry_p_t list_head, st_usb_ohci_list_entry_p_t link )
 * Argument     : st_usb_ohci_list_entry_p_t list_head ; List Head pointer
 *              : st_usb_ohci_list_entry_p_t link      ; insert list pointer
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ohci_insert_head_list (st_usb_ohci_list_entry_p_t list_head, st_usb_ohci_list_entry_p_t link)
{
    st_usb_ohci_list_entry_p_t tmp_f_link;
 #if defined(BSP_MCU_GROUP_RZA_USB)
    tmp_f_link = (st_usb_ohci_list_entry_p_t) (r_usb_pa_to_va((uint64_t) list_head->f_link));
 #else
    tmp_f_link = (st_usb_ohci_list_entry_p_t) list_head->f_link;
 #endif
    if (NULL == tmp_f_link)
    {
        /* list_head is Empty */
 #if defined(BSP_MCU_GROUP_RZA_USB)
        list_head->b_link = (uint32_t) usb_hstd_ohci_physical_address_of(link);
        list_head->f_link = list_head->b_link;
        link->b_link      = (uint32_t) usb_hstd_ohci_physical_address_of(list_head);
        link->f_link      = link->b_link;
 #else
        list_head->b_link = (st_usb_ohci_list_entry_t *) link;
        list_head->f_link = list_head->b_link;
        link->b_link      = (st_usb_ohci_list_entry_t *) list_head;
        link->f_link      = link->b_link;
 #endif
    }
    else
    {
 #if defined(BSP_MCU_GROUP_RZA_USB)
        tmp_f_link->b_link = (uint32_t) usb_hstd_ohci_physical_address_of(link);
        link->f_link       = (uint32_t) r_usb_va_to_pa((uint64_t) list_head->f_link);
        list_head->f_link  = (uint32_t) usb_hstd_ohci_physical_address_of(link);
        link->b_link       = (uint32_t) usb_hstd_ohci_physical_address_of(list_head);
 #else
        tmp_f_link->b_link = (st_usb_ohci_list_entry_t *) link;
        link->f_link       = (st_usb_ohci_list_entry_t *) list_head->f_link;
        list_head->f_link  = (st_usb_ohci_list_entry_t *) link;
        link->b_link       = (st_usb_ohci_list_entry_t *) list_head;
 #endif
    }
}                                      /* End of function usb_hstd_ohci_insert_head_list() */

/***********************************************************************************************************************
 * Function     : OHCI Insert list to tail of list
 * Declaration  : void usb_hstd_ohci_insert_tail_list( st_usb_ohci_list_entry_p_t list_head, st_usb_ohci_list_entry_p_t link )
 * Argument     : st_usb_ohci_list_entry_p_t list_head ; List Head pointer
 *              : st_usb_ohci_list_entry_p_t link      ; insert list pointer
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ohci_insert_tail_list (st_usb_ohci_list_entry_p_t list_head, st_usb_ohci_list_entry_p_t link)
{
    st_usb_ohci_list_entry_p_t tmp_b_link;
 #if defined(BSP_MCU_GROUP_RZA_USB)
    tmp_b_link = (st_usb_ohci_list_entry_p_t) (r_usb_pa_to_va((uint64_t) list_head->b_link));
 #else
    tmp_b_link = (st_usb_ohci_list_entry_p_t) list_head->b_link;
 #endif
    if (NULL == tmp_b_link)
    {
        /* list_head is Empty */
 #if defined(BSP_MCU_GROUP_RZA_USB)
        list_head->f_link = (uint32_t) usb_hstd_ohci_physical_address_of(link);
        list_head->b_link = list_head->f_link;
        link->b_link      = (uint32_t) usb_hstd_ohci_physical_address_of(list_head);
        link->f_link      = link->b_link;
 #else
        list_head->f_link = (st_usb_ohci_list_entry_t *) link;
        list_head->b_link = list_head->f_link;
        link->b_link      = (st_usb_ohci_list_entry_t *) list_head;
        link->f_link      = link->b_link;
 #endif
    }
    else
    {
 #if defined(BSP_MCU_GROUP_RZA_USB)
        tmp_b_link->f_link = (uint32_t) usb_hstd_ohci_physical_address_of(link);
        link->b_link       = (uint32_t) r_usb_va_to_pa((uint64_t) list_head->b_link);
        list_head->b_link  = (uint32_t) usb_hstd_ohci_physical_address_of(link);
        link->f_link       = (uint32_t) usb_hstd_ohci_physical_address_of(list_head);
 #else
        tmp_b_link->f_link = (st_usb_ohci_list_entry_t *) link;
        link->b_link       = (st_usb_ohci_list_entry_t *) list_head->b_link;
        list_head->b_link  = (st_usb_ohci_list_entry_t *) link;
        link->f_link       = (st_usb_ohci_list_entry_t *) list_head;
 #endif
    }
}                                      /* End of function usb_hstd_ohci_insert_tail_list() */

 #if defined(BSP_MCU_GROUP_RZA_USB)

/***********************************************************************************************************************
 * Function     : Return PhysicalAddress
 * Declaration  : uint32_t usb_hstd_ohci_physical_address_of( void *Data )
 * Argument     : void *Data ; Data Address
 * Return       : uint32_t   ; Physical Address
 * Note         :
 ***********************************************************************************************************************/
uint64_t usb_hstd_ohci_physical_address_of (void * p_data)
{
  #if USB_OHCI_SHAREDMEMORYTYPE == USB_OHCI_SHAREDMEMORYTYPE_EXCLUSIVE

    return (uint32_t) p_data - USB_OHCI_SHAREDMEMORY_OFFSET;
  #elif USB_OHCI_SHAREDMEMORYTYPE == USB_OHCI_SHAREDMEMORYTYPE_PCI
    uint64_t retadrr;

   #if defined(BSP_MCU_GROUP_RZA_USB)
    retadrr = r_usb_va_to_pa((uint64_t) p_data);
   #else
    retadrr = p_data;
   #endif

    return retadrr;
  #else

    return (uint32_t) p_data;
  #endif
}                                      /* End of function usb_hstd_ohci_physical_address_of() */

 #endif /* #if defined(BSP_MCU_GROUP_RZA3UL) */

/***********************************************************************************************************************
 * Function     : OHCI Pause Endpoint
 * Declaration  : void usb_hstd_ohci_pause_ed( st_usb_ohci_hcd_endpoint_p_t endpoint )
 * Argument     : st_usb_ohci_hcd_endpoint_p_t endpoint ; Endpoint Pointer
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ohci_pause_ed (usb_utr_t * ptr, st_usb_ohci_hcd_endpoint_p_t endpoint)
{
    st_usb_ohci_hcd_device_data_p_t         device_data;
    st_usb_ohci_hcd_endpoint_descriptor_p_t ed;

 #if defined(BSP_MCU_GROUP_RZA_USB)
    device_data = (st_usb_ohci_hcd_device_data_p_t) (r_usb_pa_to_va((uint64_t) endpoint->device_data));
    ed          = (st_usb_ohci_hcd_endpoint_descriptor_p_t) (r_usb_pa_to_va((uint64_t) endpoint->hcd_ed));
 #else
    device_data = endpoint->device_data;
    ed          = (st_usb_ohci_hcd_endpoint_descriptor_p_t) endpoint->hcd_ed;
 #endif
    ed->hc_ed.control.k = TRUE;

    if (ed->paused_flag)
    {
        /* already awaiting pause processing */
        return;
    }

    if (0 == (ed->hc_ed.head_p & USB_OHCI_HCED_HEADP_HALT))
    {
        /* Endpoint is active in Host Controller, wait for SOF before processing the endpoint */
        ed->paused_flag = TRUE;
        if (USB_IP0 == ptr->ip)
        {
            ptr->ipp->HCINTERRUPTSTATUS = USB_OHCI_HC_INT_SOF; /* clear SOF interrupt pending */
        }
        else
        {
 #if USB_NUM_USBIP == 2
            ptr->ipp1->HCINTERRUPTSTATUS = USB_OHCI_HC_INT_SOF; /* clear SOF interrupt pending */
 #endif
        }

        ed->reclamation_frame = usb_hstd_ohci_get_32bit_frame_number(device_data) + 1;
        usb_hstd_ohci_insert_tail_list(&device_data->paused_ed_restart, &ed->paused_link);

        if (USB_IP0 == ptr->ip)
        {
            ptr->ipp->HCINTERRUPTENABLE = USB_OHCI_HC_INT_SOF; /* interrupt on next SOF */
        }
        else
        {
 #if USB_NUM_USBIP == 2
            ptr->ipp1->HCINTERRUPTENABLE = USB_OHCI_HC_INT_SOF; /* interrupt on next SOF */
 #endif
        }

        return;
    }

    /* Endpoint already paused, do processing now */
    usb_hstd_ohci_process_paused_ed(ptr, ed);
}                                      /* End of function usb_hstd_ohci_pause_ed() */

/***********************************************************************************************************************
 * Function     : OHCI Unschedule Iso,Int Endpoint
 * Declaration  : void usb_hstd_ohci_unschedule_isochronous_or_interrupt_endpoint( st_usb_ohci_hcd_endpoint_p_t endpoint, boolean_t free_ed, boolean_t endpoint_processing_required )
 * Argument     : st_usb_ohci_hcd_endpoint_p_t endpoint       ; Endpoint Pointer
 *              : boolean_t free_ed                      ; endpoint free flag
 *              : boolean_t endpoint_processing_required ; endpoint processing required flag
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ohci_unschedule_isochronous_or_interrupt_endpoint (usb_utr_t                  * ptr,
                                                                 st_usb_ohci_hcd_endpoint_p_t endpoint,
                                                                 boolean_t                    free_ed,
                                                                 boolean_t                    endpoint_processing_required)
{
    usb_hstd_ohci_remove_ed(ptr, endpoint, free_ed); /* see sample code in Section 5.2.7.1.2 */
    if (TRUE == endpoint_processing_required)
    {
        if (USB_IP0 == ptr->ip)
        {
            ptr->ipp->HCINTERRUPTENABLE = USB_OHCI_HC_INT_SOF; /* interrupt on next SOF */
        }
        else
        {
 #if USB_NUM_USBIP == 2
            ptr->ipp1->HCINTERRUPTENABLE = USB_OHCI_HC_INT_SOF; /* interrupt on next SOF */
 #endif
        }
    }
} /* End of function usb_hstd_ohci_unschedule_isochronous_or_interrupt_endpoint() */

/***********************************************************************************************************************
 * Function     : OHCI Set FrameInterval
 * Declaration  : uint32_t usb_hstd_ohci_set_frame_interval( st_usb_ohci_hcd_device_data_p_t device_data, boolean_t up_not_down )
 * Argument     : st_usb_ohci_hcd_device_data_p_t device_data ; Device Data Pointer
 *              ; boolean_t up_not_down                  ; up or down flag( TRUE:up, FALSE:down )
 * Return       : uint32_t                               ; frame number
 * Note         :
 ***********************************************************************************************************************/
uint32_t usb_hstd_ohci_set_frame_interval (usb_utr_t                     * ptr,
                                           st_usb_ohci_hcd_device_data_p_t device_data,
                                           boolean_t                       up_not_down)
{
    uint32_t frame_number;
    uint32_t interval;

    if (USB_IP0 == ptr->ip)
    {
        interval = (ptr->ipp->HCFMINTERVAL & USB_VAL_X3FFF);
    }
    else
    {
 #if USB_NUM_USBIP == 2
        interval = (ptr->ipp1->HCFMINTERVAL & USB_VAL_X3FFF);
 #else
        interval = (ptr->ipp->HCFMINTERVAL & USB_VAL_X3FFF);
 #endif
    }

    if (TRUE == up_not_down)
    {
        ++interval;
    }
    else
    {
        --interval;
    }

    interval |= (((interval - USB_OHCI_MAXIMUM_OVERHEAD) * 6) / 7) << 16;
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        interval |= USB_VAL_X8000U & (USB_VAL_X8000U ^ (ptr->ipp->HCFMREMAINING));
    }
    else
    {
  #if USB_NUM_USBIP == 2
        interval |= USB_VAL_X8000U & (USB_VAL_X8000U ^ (ptr->ipp1->HCFMREMAINING));
  #else
        interval |= USB_VAL_X8000U & (USB_VAL_X8000U ^ (ptr->ipp->HCFMREMAINING));
  #endif
    }
 #else
    interval |= USB_VAL_X8000U & (USB_VAL_X8000U ^ (ptr->ipp->HCFNREMAINING));
 #endif
    frame_number = usb_hstd_ohci_get_32bit_frame_number(device_data);
    if (USB_IP0 == ptr->ip)
    {
        ptr->ipp->HCFMINTERVAL = interval;
    }
    else
    {
 #if USB_NUM_USBIP == 2
        ptr->ipp1->HCFMINTERVAL = interval;
 #endif
    }

 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        if (USB_VAL_X8000U & (ptr->ipp->HCFMREMAINING ^ interval))
        {
            frame_number += 1;
        }
        else
        {
            frame_number = usb_hstd_ohci_get_32bit_frame_number(device_data);
        }
    }
    else
    {
  #if USB_NUM_USBIP == 2
        if (USB_VAL_X8000U & (ptr->ipp1->HCFMREMAINING ^ interval))
        {
            frame_number += 1;
        }
        else
        {
            frame_number = usb_hstd_ohci_get_32bit_frame_number(device_data);
        }
  #endif
    }
 #else
    if (USB_VAL_X8000U & (ptr->ipp->HCFNREMAINING ^ interval))
    {
        frame_number += 1;
    }
    else
    {
        frame_number = usb_hstd_ohci_get_32bit_frame_number(device_data);
    }
 #endif

    return frame_number;               /* return frame number new interval takes effect */
} /* End of function usb_hstd_ohci_set_frame_interval() */

/***********************************************************************************************************************
 * Function     : OHCI Get 32bit FrameNumber
 * Declaration  : uint32_t usb_hstd_ohci_get_32bit_frame_number( st_usb_ohci_hcd_device_data_p_t device_data )
 * Argument     : st_usb_ohci_hcd_device_data_p_t device_data ; Device Data Pointer
 * Return       : uint32_t                               ; 32bit frame number
 * Note         :
 ***********************************************************************************************************************/
uint32_t usb_hstd_ohci_get_32bit_frame_number (st_usb_ohci_hcd_device_data_p_t device_data)
{
    uint32_t fm;
    uint32_t hp;
    st_usb_ohci_hcca_block_p_t tmp_hcca;

    /* This code accounts for the fact that hcca_frame_number is updated by the HC before the HCD gets an interrupt that will adjust frame_high_part */
 #if defined(BSP_MCU_GROUP_RZA_USB)
    tmp_hcca = (st_usb_ohci_hcca_block_p_t) (r_usb_pa_to_va((uint64_t) device_data->hcca));
 #else
    tmp_hcca = device_data->hcca;
 #endif
    hp = device_data->frame_high_part;
    fm = tmp_hcca->hcca_frame_number;

    return ((fm & USB_VAL_X7FFFB) | hp) + ((fm ^ hp) & USB_VAL_X8000B);
}                                      /* End of function usb_hstd_ohci_get_32bit_frame_number() */

/***********************************************************************************************************************
 * Function     : OHCI Check bandwidth
 * Declaration  : uint32_t usb_hstd_ohci_check_bandwidth( st_usb_ohci_hcd_device_data_p_t device_data, uint32_t list, uint32_t *best_list )
 * Argument     : st_usb_ohci_hcd_device_data_p_t device_data ; Device Data Pointer
 *              ; uint32_t list                          ; list
 *              ; uint32_t *best_list                    ; pointer of return best list
 * Return       : uint32_t                               ; Worst Bandwidth
 * Note         :
 ***********************************************************************************************************************/
uint32_t usb_hstd_ohci_check_bandwidth (st_usb_ohci_hcd_device_data_p_t device_data,
                                        uint32_t                        list,
                                        uint32_t                      * p_best_list)
{
/*++
 *  This routine scans all the scheduling lists of frequency determined by
 *  the base List passed in and returns the worst bandwidth found (i.e., max
 *  in use by any given scheduling list) and the list which had the least
 *  bandwidth in use.
 *  List - must be a base scheduling list. I.e., it must be one of
 *  USB_OHCI_ED_INTERRUPT_1ms, USB_OHCI_ED_INTERRUPT_2ms,USB_OHCI_ED_INTERRUPT_4ms, ..., USB_OHCI_ED_INTERRUPT_32ms.
 *  All lists of the appropriate frequency are checked
 * --*/
    uint32_t last_list;
    uint32_t index;
    uint32_t best_bandwidth;
    uint32_t worst_bandwidth;
    uint32_t bandwidth;

    worst_bandwidth = 0;
    best_bandwidth  = ~0U;

    for (last_list = list + list; list <= last_list; list++)
    {
        /* Sum bandwidth in use in this scheduling time */
        bandwidth = 0;
        for (index = list; index != USB_OHCI_ED_EOF; )
        {
            bandwidth += device_data->ed_list[index].bandwidth;
            index      = device_data->ed_list[index].next;
        }

        /* Remember best and worst */
        if (bandwidth < best_bandwidth)
        {
            best_bandwidth = bandwidth;
            *p_best_list   = list;
        }

        if (bandwidth > worst_bandwidth)
        {
            worst_bandwidth = bandwidth;
        }
    }

    return worst_bandwidth;
}                                      /* End of function usb_hstd_ohci_check_bandwidth() */

/***********************************************************************************************************************
 * Function     : OHCI H/W Setup
 * Declaration  : uint32_t usb_hstd_ohci_hw_setup( void )
 * Argument     : void
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
static void usb_hstd_ohci_hw_setup (usb_utr_t * ptr)
{
    uint32_t   n;
    uint32_t   portnum;
    uint32_t   numports;
    uint32_t * p_port_status_reg;
    uint32_t   timeout;
    uint32_t   err;

    /* Setup usb_hstd_ohci_device_data */
    usb_hstd_ohci_device_data = usb_hstd_ohci_alloc_device_data();
    if (NULL == usb_hstd_ohci_device_data)
    {
        return;
    }

    /* Register setting */

/* usb_hstd_ohci_device_data->HC = (USB_OHCI_HC_OPERATIONAL_REGISTER_P)USB_OHCI_BASE; */

    /* H/W reset */
    err = usb_hstd_ohci_hw_reset(ptr);
    if (USB_OK != err)
    {
        return;
    }

 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        ptr->ipp->HCHCCA = (uint32_t) usb_hstd_ohci_physical_address_of(usb_hstd_ohci_get_hcca_address());
    }
    else
    {
  #if USB_NUM_USBIP == 2
        ptr->ipp1->HCHCCA = (uint32_t) usb_hstd_ohci_physical_address_of(usb_hstd_ohci_get_hcca_address());
  #endif
    }

    usb_hstd_ohci_device_data->hcca = (uint32_t) usb_hstd_ohci_physical_address_of(usb_hstd_ohci_get_hcca_address());
 #else
    ptr->ipp->HCHCCA                = (uint32_t) usb_hstd_ohci_get_hcca_address();
    usb_hstd_ohci_device_data->hcca = usb_hstd_ohci_get_hcca_address();
 #endif

    usb_hstd_ohci_clear_hcca(usb_hstd_ohci_device_data);

    usb_hstd_ohci_initailize_interrupt_lists(usb_hstd_ohci_device_data);

    if (USB_IP0 == ptr->ip)
    {
        numports = ptr->ipp->HCRHDESCRIPTORA & USB_VAL_XFF;

        /* Set USB-Operational state */
        ptr->ipp->HCCONTROL = (ptr->ipp->HCCONTROL & ~USB_VAL_XC0) | USB_VAL_X80;
    }
    else
    {
 #if USB_NUM_USBIP == 2
        numports = ptr->ipp1->HCRHDESCRIPTORA & USB_VAL_XFF;

        /* Set USB-Operational state */
        ptr->ipp1->HCCONTROL = (ptr->ipp1->HCCONTROL & ~USB_VAL_XC0) | USB_VAL_X80;
 #else                                 /* #if USB_NUM_USBIP == 2 */
        numports = ptr->ipp->HCRHDESCRIPTORA & USB_VAL_XFF;

        /* Set USB-Operational state */
        ptr->ipp->HCCONTROL = (ptr->ipp->HCCONTROL & ~USB_VAL_XC0) | USB_VAL_X80;
 #endif                                /* #if USB_NUM_USBIP == 2 */
    }

    /*  Clear HcInterruptStatus */
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if (USB_IP0 == ptr->ip)
    {
        ptr->ipp->HCINTERRUPTSTATUS = USB_VAL_X7F;
        ptr->ipp->HCFMINTERVAL      = USB_VAL_FMINTVL;
        ptr->ipp->HCPERIODICSTART   = USB_VAL_2A2F;
    }
    else
    {
  #if USB_NUM_USBIP == 2
        ptr->ipp1->HCINTERRUPTSTATUS = USB_VAL_X7F;
        ptr->ipp1->HCFMINTERVAL      = USB_VAL_FMINTVL;
        ptr->ipp1->HCPERIODICSTART   = USB_VAL_2A2F;
  #endif
    }
 #else
    ptr->ipp->HCINTERRUPTSTATUS = USB_VAL_FF32U;
    ptr->ipp->HCFMINTERVAL      = USB_VAL_FMINTVL;
    ptr->ipp->HCPERIODSTART     = USB_VAL_2A2F;
 #endif

    if (USB_IP0 == ptr->ip)
    {
        /*  Set PowerControl-related Reg */
        ptr->ipp->HCRHDESCRIPTORA = USB_VAL_02001902; /* Enable Power-SW, Disable OverCurrent */
        for (n = 0; n < numports; n++)
        {
            ptr->ipp->HCRHDESCRIPTORB |= (USB_VAL_X0002U << n);
        }
    }
    else
    {
 #if USB_NUM_USBIP == 2
        /*  Set PowerControl-related Reg */
        ptr->ipp1->HCRHDESCRIPTORA = USB_VAL_02001902; /* Enable Power-SW, Disable OverCurrent */
        for (n = 0; n < numports; n++)
        {
            ptr->ipp1->HCRHDESCRIPTORB |= (USB_VAL_X0002U << n);
        }
 #else
        /*  Set PowerControl-related Reg */
        ptr->ipp->HCRHDESCRIPTORA = USB_VAL_02001902; /* Enable Power-SW, Disable OverCurrent */
        for (n = 0; n < numports; n++)
        {
            ptr->ipp->HCRHDESCRIPTORB |= (USB_VAL_X0002U << n);
        }
 #endif
    }

    for (portnum = 0; portnum < numports; portnum++)
    {
        if (USB_IP0 == ptr->ip)
        {
            p_port_status_reg = (uint32_t *) &(ptr->ipp->HCRHPORTSTATUS1);
        }
        else
        {
 #if USB_NUM_USBIP == 2
            p_port_status_reg = (uint32_t *) &(ptr->ipp1->HCRHPORTSTATUS1);
 #else
            p_port_status_reg = (uint32_t *) &(ptr->ipp->HCRHPORTSTATUS1);
 #endif
        }

        *p_port_status_reg = USB_VAL_X100;
        timeout            = 0;
        while (0x00000000 == (*p_port_status_reg & USB_VAL_X100))
        {
            if (timeout > USB_OHCI_TIMEOUT)
            {
                USB_HCI_PRINTF0_R("Error : usb_hstd_ohci_hw_setup TIMEOUT\n");

                return;
            }

            usb_cpu_delay_xms(1);
            timeout++;
        }
    }

    /* Enable OverCurrent */
    if (USB_IP0 == ptr->ip)
    {
        ptr->ipp->HCRHDESCRIPTORA &= ~USB_VAL_X1000;
    }
    else
    {
 #if USB_NUM_USBIP == 2
        ptr->ipp1->HCRHDESCRIPTORA &= ~USB_VAL_X1000;
 #endif
    }

    for (portnum = 0; portnum < numports; portnum++)
    {
        if (USB_IP0 == ptr->ip)
        {
            p_port_status_reg = (uint32_t *) &(ptr->ipp->HCRHPORTSTATUS1);
        }
        else
        {
 #if USB_NUM_USBIP == 2
            p_port_status_reg = (uint32_t *) &(ptr->ipp1->HCRHPORTSTATUS1);
 #else
            p_port_status_reg = (uint32_t *) &(ptr->ipp->HCRHPORTSTATUS1);
 #endif
        }

        *p_port_status_reg = USB_VAL_XFFFFU;
    }

    if (USB_IP0 == ptr->ip)
    {
 #if defined(BSP_MCU_GROUP_RZA_USB)
        usb_hstd_ohci_device_data->ed_list[USB_OHCI_ED_CONTROL].physical_head =
            (uint32_t) (uintptr_t) &ptr->ipp->HCCONTROLHEADED;
        usb_hstd_ohci_device_data->ed_list[USB_OHCI_ED_BULK].physical_head =
            (uint32_t) (uintptr_t) &ptr->ipp->HCBULKHEADED;
 #else
        usb_hstd_ohci_device_data->ed_list[USB_OHCI_ED_CONTROL].physical_head = (uint32_t *) &ptr->ipp->HCCONTROLHEADED;
        usb_hstd_ohci_device_data->ed_list[USB_OHCI_ED_BULK].physical_head    = (uint32_t *) &ptr->ipp->HCBULKHEADED;
 #endif

        /*  Enable MasterInt,RHSC,FNO,WBDH */
        ptr->ipp->HCINTERRUPTENABLE = USB_VAL_INTENB;

        /* Control,Bulk,Iso,Periodic List Enable */
        ptr->ipp->HCCONTROL |= USB_VAL_X34;
    }
    else
    {
 #if USB_NUM_USBIP == 2
  #if defined(BSP_MCU_GROUP_RZA_USB)
        usb_hstd_ohci_device_data->ed_list[USB_OHCI_ED_CONTROL].physical_head =
            (uint32_t) (uintptr_t) &ptr->ipp1->HCCONTROLHEADED;
        usb_hstd_ohci_device_data->ed_list[USB_OHCI_ED_BULK].physical_head =
            (uint32_t) (uintptr_t) &ptr->ipp1->HCBULKHEADED;
  #else
        usb_hstd_ohci_device_data->ed_list[USB_OHCI_ED_CONTROL].physical_head =
            (uint32_t *) &ptr->ipp1->HCCONTROLHEADED;
        usb_hstd_ohci_device_data->ed_list[USB_OHCI_ED_BULK].physical_head = (uint32_t *) &ptr->ipp1->HCBULKHEADED;
  #endif

        /*  Enable MasterInt,RHSC,FNO,WBDH */
        ptr->ipp1->HCINTERRUPTENABLE = USB_VAL_INTENB;

        /* Control,Bulk,Iso,Periodic List Enable */
        ptr->ipp1->HCCONTROL |= USB_VAL_X34;
 #endif
    }
}                                      /* End of function usb_hstd_ohci_hw_setup() */

/***********************************************************************************************************************
 * Function     : Reset OHCI H/W
 * Declaration  : void usb_hstd_EhciHwReset( void )
 * Argument     : void
 * Return       : uint32_t ; status
 * Note         :
 ***********************************************************************************************************************/
static uint32_t usb_hstd_ohci_hw_reset (usb_utr_t * ptr)
{
    uint32_t timeout;

    if (USB_IP0 == ptr->ip)
    {
        ptr->ipp->HCCOMMANDSTATUS = USB_VAL_X001; /* Reset HC */
        timeout = 0;
        while (ptr->ipp->HCCOMMANDSTATUS & USB_VAL_X001)
        {
            if (timeout > USB_OHCI_TIMEOUT)
            {
                USB_HCI_PRINTF0_R("Error : usb_hstd_ohci_hw_setup TIMEOUT\n");

                return USB_ERROR;
            }

            usb_cpu_delay_xms(1);

            timeout++;
        }
    }
    else
    {
 #if USB_NUM_USBIP == 2
        ptr->ipp1->HCCOMMANDSTATUS = USB_VAL_X001; /* Reset HC */
        timeout = 0;
        while (ptr->ipp1->HCCOMMANDSTATUS & USB_VAL_X001)
        {
            if (timeout > USB_OHCI_TIMEOUT)
            {
                USB_HCI_PRINTF0_R("Error : usb_hstd_ohci_hw_setup TIMEOUT\n");

                return USB_ERROR;
            }

            usb_cpu_delay_xms(1);

            timeout++;
        }
 #endif
    }

    return USB_OK;
}                                      /* End of function usb_hstd_ohci_hw_reset() */

/***********************************************************************************************************************
 * Function     : OHCI Initialize InterruptED List
 * Declaration  : void usb_hstd_ohci_initailize_interrupt_lists( st_usb_ohci_hcd_device_data_p_t device_data )
 * Argument     : st_usb_ohci_hcd_device_data_p_t device_data ; Device Data Pointer
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
static void usb_hstd_ohci_initailize_interrupt_lists (st_usb_ohci_hcd_device_data_p_t device_data)
{
    st_usb_ohci_hcd_endpoint_descriptor_p_t ed;
    st_usb_ohci_hcd_endpoint_descriptor_p_t static_ed[USB_OHCI_ED_INTERRUPT_32ms];
    uint32_t i;
    uint32_t j;
    uint32_t k;
    st_usb_ohci_hcca_block_p_t tmp_hcca;

    /* static uint8_t Balance[16] = */
    uint8_t Balance[16] =
    {
        0x0, 0x8, 0x4, 0xC, 0x2, 0xA, 0x6, 0xE, 0x1, 0x9, 0x5, 0xD, 0x3, 0xB, 0x7, 0xF
    };

    /* Allocate satirically disabled EDs, and set head pointers for scheduling lists */
    for (i = 0; i < USB_OHCI_ED_INTERRUPT_32ms; i++)
    {
        ed = usb_hstd_ohci_allocate_endpoint_descriptor();
 #if defined(BSP_MCU_GROUP_RZA_USB)
        ed->physical_address = (uint32_t) usb_hstd_ohci_physical_address_of(&ed->hc_ed);
        device_data->ed_list[i].physical_head = (uint32_t) usb_hstd_ohci_physical_address_of(&ed->hc_ed.next_ed);
 #else
        ed->physical_address = (uint32_t) &ed->hc_ed;
        device_data->ed_list[i].physical_head = (uint32_t *) &ed->hc_ed.next_ed;
 #endif

        ed->hc_ed.control.k = 1;       /* mark ED as disabled */
        ed->hc_ed.control.s = 0;

        usb_hstd_ohci_initialize_list_head(&device_data->ed_list[i].head);
        static_ed[i] = ed;
        if (i > 0)
        {
            device_data->ed_list[i].next = (uint8_t) ((i - 1) / 2);
            ed->hc_ed.next_ed            = static_ed[(i - 1) / 2]->physical_address;
        }
        else
        {
            device_data->ed_list[i].next = USB_OHCI_ED_EOF;
            ed->hc_ed.next_ed            = 0;
        }
    }

    i = 0;
    j = USB_OHCI_ED_INTERRUPT_32ms;

    /* Set head pointers for 32ms scheduling lists which start from HCCA */
    for ( ; i < USB_VAL_32; i++, j++)
    {
 #if defined(BSP_MCU_GROUP_RZA_USB)
        tmp_hcca = (st_usb_ohci_hcca_block_p_t) (r_usb_pa_to_va((uint64_t) device_data->hcca));
        device_data->ed_list[j].physical_head = (uint32_t) usb_hstd_ohci_physical_address_of(
            &tmp_hcca->hcca_interrupt_list[i]);
 #else
        tmp_hcca = device_data->hcca;
        device_data->ed_list[j].physical_head = (uint32_t *) tmp_hcca->hcca_interrupt_list[i];
 #endif
        usb_hstd_ohci_initialize_list_head(&device_data->ed_list[j].head);
        k = Balance[i & 0xF] + USB_OHCI_ED_INTERRUPT_16ms;
        device_data->ed_list[j].next     = (uint8_t) k;
        tmp_hcca->hcca_interrupt_list[i] = static_ed[k]->physical_address;
    }
}                                      /* End of function usb_hstd_ohci_initailize_interrupt_lists() */

/***********************************************************************************************************************
 * Function     : OHCI Clear HCCA
 * Declaration  : void usb_hstd_ohci_clear_hcca( st_usb_ohci_hcd_device_data_p_t device_data )
 * Argument     : st_usb_ohci_hcd_device_data_p_t device_data ; Device Data Pointer
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
static void usb_hstd_ohci_clear_hcca (st_usb_ohci_hcd_device_data_p_t device_data)
{
    st_usb_ohci_hcca_block_p_t tmp_hcca;

 #if defined(BSP_MCU_GROUP_RZA_USB)
    tmp_hcca = (st_usb_ohci_hcca_block_p_t) (r_usb_pa_to_va((uint64_t) device_data->hcca));
 #else
    tmp_hcca = device_data->hcca;
 #endif

    tmp_hcca->hcca_frame_number = 0x0;
    tmp_hcca->hcca_pad1         = 0x0;
    tmp_hcca->hcca_done_head    = 0x0;
}                                      /* End of function usb_hstd_ohci_clear_hcca() */

/***********************************************************************************************************************
 * Function     : OHCI Clear transfer request for disconnected device
 * Declaration  : void usb_hstd_ohci_clear_device_tr_req( uint32_t devadd )
 * Argument     : uint32_t devadd ; Device Address
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
static void usb_hstd_ohci_clear_device_tr_req (usb_utr_t * ptr, uint32_t devadd)
{
    uint32_t i;
    uint32_t n;
    uint8_t  free_ed = TRUE;

    for (i = 0; i < USB_HCI_TRREQ_NUM; i++)
    {
        if ((TRUE == g_usb_hstd_hci_transfer_request[i].bit.enable) &&
            (devadd == g_usb_hstd_hci_transfer_request[i].bit.devadrs))
        {
            /* Cancel Request */
            usb_hstd_ohci_cancel_transfer_request(ptr, &g_usb_hstd_hci_transfer_request[i]);

            /* Remove ED */
            usb_hstd_ohci_remove_device(ptr, (uint8_t) devadd, free_ed);

            /* Check downstream port */
            for (n = 0; n < USB_HCI_HUBPORT_NUM; n++)
            {
                if (0 != g_usb_hstd_hci_transfer_request[i].devinfo->hubdevinfo.devnum[n])
                {
                    usb_hstd_ohci_clear_device_tr_req(ptr,
                                                      g_usb_hstd_hci_transfer_request[i].devinfo->hubdevinfo.devnum[n]);
                }
            }
        }
    }
}                                      /* End of function usb_hstd_ohci_clear_device_tr_req() */

/***********************************************************************************************************************
 * Function     : OHCI Root Port Device Connection
 * Declaration  : void usb_hstd_ohci_rootport_connection( st_usb_ohci_hcd_device_data_p_t devicedata, uint8_t devspeed, uint8_t portnum )
 * Argument     : st_usb_ohci_hcd_device_data_p_t devicedata ; Device Data Pointer
 *              : uint8_t devspeed                      ; Device Speed
 *              : uint8_t portnum                       ; Port No
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
static void usb_hstd_ohci_rootport_connection (usb_utr_t                     * ptr,
                                               st_usb_ohci_hcd_device_data_p_t devicedata,
                                               uint8_t                         devspeed,
                                               uint8_t                         portnum)
{
    st_usb_hci_device_t * p_devinfo;
    uint8_t               free_ed = TRUE;

    usb_hstd_ohci_remove_device(ptr, 0, free_ed);

    p_devinfo = usb_hstd_hci_alloc_dev_info();
    if (p_devinfo != NULL)
    {
        p_devinfo->bit.devspeed          = devspeed & 0x03U;
        p_devinfo->bit.devnum            = 0;
        p_devinfo->bit.hctype            = USB_HCI_HCTYPE_OHCI;
        p_devinfo->hci_device            = devicedata;
        devicedata->root_device[portnum] = p_devinfo->bit.devnum;

        /* attach callback */
        g_usb_hstd_hci_callback.attach_cb(ptr);
    }
}                                      /* End of function usb_hstd_ohci_rootport_connection() */

/***********************************************************************************************************************
 * Function     : OHCI Root Port Device Disconnection
 * Declaration  : void usb_hstd_ohci_rootport_disconnection( st_usb_ohci_hcd_device_data_p_t devicedata, uint8_t portnum )
 * Argument     : st_usb_ohci_hcd_device_data_p_t devicedata ; Device Data Pointer
 *              : uint8_t portnum                       ; Port No
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
static void usb_hstd_ohci_rootport_disconnection (usb_utr_t                     * ptr,
                                                  st_usb_ohci_hcd_device_data_p_t devicedata,
                                                  uint8_t                         portnum)
{
    r_usb_hstd_hci_disconnect(ptr, devicedata->root_device[portnum]);

    devicedata->root_device[portnum] = USB_HCI_NODEVICE;

    /* detach callback */
    g_usb_hstd_hci_callback.detach_cb(ptr);
}                                      /* End of function usb_hstd_ohci_rootport_disconnection() */

/***********************************************************************************************************************
 * Function     : OHCI Remove Device
 * Declaration  : void usb_hstd_ohci_remove_device( uint8_t device_address, boolean_t free_ed )
 * Argument     : uint8_t device_address  ; device address
 *              : boolean_t free_ed       ; free flag
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
static void usb_hstd_ohci_remove_device (usb_utr_t * ptr, uint8_t device_address, boolean_t free_ed)
{
    uint32_t n;

    for (n = 0; n < USB_OHCI_MAXENDPOINT; n++)
    {
        usb_hstd_ohci_remove_endpoint(ptr, device_address, (uint8_t) n, USB_HCI_DIRECTION_OUT, free_ed);
        usb_hstd_ohci_remove_endpoint(ptr, device_address, (uint8_t) n, USB_HCI_DIRECTION_IN, free_ed);
    }
}                                      /* End of function usb_hstd_ohci_remove_device() */

/***********************************************************************************************************************
 * Function     : OHCI Return speed information
 * Declaration  : uint8_t usb_hstd_ohci_get_root_device_speed( st_usb_ohci_hcd_device_data_p_t device_data, uint8_t portnum )
 * Argument     : st_usb_ohci_hcd_device_data_p_t device_data ; Device Data pointer
 *              : uint8_t portnum                        ; Port No
 * Return       : uint8_t                                ; Speed
 * Note         :
 ***********************************************************************************************************************/
static uint8_t usb_hstd_ohci_get_root_device_speed (st_usb_ohci_hcd_device_data_p_t device_data, uint8_t portnum)
{
    uint32_t * p_port_status_reg;
    FSP_PARAMETER_NOT_USED(device_data);

    if (USB_IP0 == portnum)
    {
        p_port_status_reg = (uint32_t *) &(USB00->HCRHPORTSTATUS1);
    }
    else
    {
 #if USB_NUM_USBIP == 2
        p_port_status_reg = (uint32_t *) &(USB10->HCRHPORTSTATUS1);
 #else
        p_port_status_reg = (uint32_t *) &(USB00->HCRHPORTSTATUS1);
 #endif
    }

    if (0 == (*p_port_status_reg & USB_VAL_X200))
    {
        return USB_HCI_DEVSPEED_FS;
    }

    return USB_HCI_DEVSPEED_LS;
}                                      /* End of function usb_hstd_ohci_get_root_device_speed() */

/***********************************************************************************************************************
 * Function     : OHCI Pause Endpoint
 * Declaration  : void usb_hstd_ohci_process_paused_ed( st_usb_ohci_hcd_endpoint_descriptor_p_t ed )
 * Argument     : st_usb_ohci_hcd_endpoint_descriptor_p_t ed ; Endpoint Descriptor Pointer
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
static void usb_hstd_ohci_process_paused_ed (usb_utr_t * ptr, st_usb_ohci_hcd_endpoint_descriptor_p_t ed)
{
    st_usb_ohci_hcd_endpoint_p_t              endpoint;
    st_usb_ohci_request_p_t                   ohci_req;
    st_usb_ohci_hcd_transfer_descriptor_p_t   td;
    st_usb_ohci_hcd_transfer_descriptor_p_t   last = NULL;
    st_usb_ohci_hcd_transfer_descriptor_p_t * p_previous;
    boolean_t b4head = TRUE;
    st_usb_ohci_hcd_endpoint_descriptor_p_t tmp_last_hc_td;
    st_usb_ohci_hcd_transfer_descriptor_p_t tmp_endpoint_hcd_head_p;

 #if defined(BSP_MCU_GROUP_RZA_USB)
    endpoint = (st_usb_ohci_hcd_endpoint_p_t) (r_usb_pa_to_va((uint64_t) ed->endpoint));
 #else
    endpoint = ed->endpoint;
 #endif

    if (NULL == endpoint)
    {
        return;
    }

 #if defined(BSP_MCU_GROUP_RZA_USB)
    td = (st_usb_ohci_hcd_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) endpoint->hcd_head_p)); /* set head TD */

    while (td != (st_usb_ohci_hcd_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) endpoint->hcd_tail_p)))
 #else
    td = (st_usb_ohci_hcd_transfer_descriptor_p_t) endpoint->hcd_head_p;                              /* set head TD */

    while (td != (st_usb_ohci_hcd_transfer_descriptor_p_t) endpoint->hcd_tail_p)
 #endif

    {
        if ((ed->hc_ed.head_p & ~0xFU) == td->physical_address)
        {
            b4head = FALSE;
        }

        if ((USB_OHCI_ED_EOF == ed->list_index) || (td->cancel_pending)) /* cancel TD */
        {
 #if defined(BSP_MCU_GROUP_RZA_USB)
            ohci_req = (st_usb_ohci_request_p_t) (r_usb_pa_to_va((uint64_t) td->usb_drequest));
 #else
            ohci_req = (st_usb_ohci_request_p_t) &td->usb_drequest;
 #endif
            usb_hstd_ohci_remove_list_entry(&td->request_list);
            if (usb_hstd_ohci_is_list_empty(&ohci_req->hcd_list) == TRUE)
            {
                ohci_req->status = USB_OHCI_RS_CANCELED;
                usb_hstd_ohci_complete_transfer_request(ptr, ohci_req);
            }

 #if defined(BSP_MCU_GROUP_RZA_USB)
            p_previous = (st_usb_ohci_hcd_transfer_descriptor_p_t *) (r_usb_pa_to_va((uint64_t) td->next_hcd_td)); /* point around TD */
 #else
            p_previous = (st_usb_ohci_hcd_transfer_descriptor_p_t *) &td->next_hcd_td;                             /* point around TD */
 #endif

            if (NULL != last)
            {
                FSP_PARAMETER_NOT_USED(tmp_last_hc_td);
            }

            if (TRUE == b4head)        /* TD on delayed Done List */
            {
                td->td_status = USB_OHCI_TD_CANCELED;
            }
            else
            {
                usb_hstd_ohci_free_transfer_descriptor(td);
            }
        }
        else                           /* don't cancel TD */
        {
 #if defined(BSP_MCU_GROUP_RZA_USB)
            p_previous = (st_usb_ohci_hcd_transfer_descriptor_p_t *) (r_usb_pa_to_va((uint64_t) td->next_hcd_td));
 #else
            p_previous = (st_usb_ohci_hcd_transfer_descriptor_p_t *) &td->next_hcd_td;
 #endif
            if (FALSE == b4head)
            {
                last = td;
            }
        }

 #if defined(BSP_MCU_GROUP_RZA_USB)
        td = (st_usb_ohci_hcd_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) p_previous));
 #else
        td = *p_previous;
 #endif
    }

 #if defined(BSP_MCU_GROUP_RZA_USB)
    tmp_endpoint_hcd_head_p =
        (st_usb_ohci_hcd_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) endpoint->hcd_head_p));
 #else
    tmp_endpoint_hcd_head_p = (st_usb_ohci_hcd_transfer_descriptor_p_t) endpoint->hcd_head_p;
 #endif
    ed->hc_ed.head_p = tmp_endpoint_hcd_head_p->physical_address |
                       (ed->hc_ed.head_p & USB_OHCI_HCED_HEADP_CARRY);
    ed->hc_ed.control.k = FALSE;
}                                      /* End of function usb_hstd_ohci_process_paused_ed() */

/***********************************************************************************************************************
 * Function     : OHCI Remove Endpoint
 * Declaration  : void usb_hstd_ohci_remove_ed( st_usb_ohci_hcd_endpoint_p_t endpoint, boolean_t free_ed )
 * Argument     : st_usb_ohci_hcd_endpoint_p_t endpoint ; Endpoint Pointer
 *              : boolean_t free_ed                ; endpoint free flag
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
static void usb_hstd_ohci_remove_ed (usb_utr_t * ptr, st_usb_ohci_hcd_endpoint_p_t endpoint, boolean_t free_ed)
{
    st_usb_ohci_hcd_device_data_p_t         device_data;
    st_usb_ohci_hcd_ed_list_p_t             list;
    st_usb_ohci_hcd_endpoint_descriptor_p_t ed;
    st_usb_ohci_hcd_endpoint_descriptor_p_t previous_ed;
    uint32_t list_disable;
    st_usb_ohci_list_entry_p_t tmp_link_b_link = 0;
    uint32_t                 * tmp_list_physical_head;

    FSP_PARAMETER_NOT_USED(tmp_link_b_link);

 #if defined(BSP_MCU_GROUP_RZA_USB)
    device_data = (st_usb_ohci_hcd_device_data_p_t) (r_usb_pa_to_va((uint64_t) endpoint->device_data));
    list        = &device_data->ed_list[endpoint->list_index];
    ed          = (st_usb_ohci_hcd_endpoint_descriptor_p_t) (r_usb_pa_to_va((uint64_t) endpoint->hcd_ed));
 #else
    device_data = endpoint->device_data;
    list        = &device_data->ed_list[endpoint->list_index];
    ed          = (st_usb_ohci_hcd_endpoint_descriptor_p_t) endpoint->hcd_ed;
 #endif

    /* Prevent Host controller from processing this ED */
    ed->hc_ed.control.k = TRUE;

    /* Unlink the ED from the physical ED list */
 #if defined(BSP_MCU_GROUP_RZA_USB)
    if ((st_usb_ohci_list_entry_t *) (r_usb_pa_to_va((uint64_t) ed->link.b_link)) == &list->head) /* Removing ED is located in head of ED List */
 #else
    if ((st_usb_ohci_list_entry_t *) ed->link.b_link == &list->head)                              /* Removing ED is located in head of ED List */
 #endif
    {
        /* Remove ED from head */
 #if defined(BSP_MCU_GROUP_RZA_USB)
        tmp_list_physical_head = (uint32_t *) (r_usb_pa_to_va((uint64_t) list->physical_head));
 #else
        tmp_list_physical_head = list->physical_head;
 #endif
        *tmp_list_physical_head = ed->hc_ed.next_ed;
        previous_ed             = NULL;
    }
    else
    {
        /* Remove ED from list */
 #if defined(BSP_MCU_GROUP_RZA_USB)
        previous_ed =
            (st_usb_ohci_hcd_endpoint_descriptor_p_t) (uintptr_t) usb_hstd_ohci_scan_containing_record((
                                                                                                           st_usb_ohci_list_entry_p_t) (
                                                                                                           r_usb_pa_to_va((
                                                                                                                              uint64_t)
                                                                                                                          ed
                                                                                                                          ->
                                                                                                                          link
                                                                                                                          .
                                                                                                                          b_link)),
                                                                                                       USB_OHCI_CR_ENDPOINT_DESCRIPTOR,
                                                                                                       USB_OHCI_CR_LINK);
 #else
        previous_ed =
            (st_usb_ohci_hcd_endpoint_descriptor_p_t) usb_hstd_ohci_scan_containing_record(
                (st_usb_ohci_list_entry_p_t) ed->link.b_link,
                USB_OHCI_CR_ENDPOINT_DESCRIPTOR,
                USB_OHCI_CR_LINK);
 #endif
        if (NULL != previous_ed)
        {
            previous_ed->hc_ed.next_ed = ed->hc_ed.next_ed;
        }
    }

    /* Unlink ED from HCD list */
    usb_hstd_ohci_remove_list_entry(&ed->link);

    /* If freeing the endpoint, remove the descriptor */
    if (TRUE == free_ed)               /* TD queue must already be empty */
    {
 #if defined(BSP_MCU_GROUP_RZA_USB)
        endpoint->hcd_ed = 0;
        ed->endpoint     = 0;
 #else
        endpoint->hcd_ed = NULL;
        ed->endpoint     = NULL;
 #endif
    }

    /* Check to see if interrupt processing is required to free the ED */
    switch (endpoint->type)
    {
        case USB_EP_CNTRL:
        {
            list_disable = ~USB_OHCI_CONTROLLISTENABLE;
            break;
        }

        case USB_EP_BULK:
        {
            list_disable = ~USB_OHCI_BULKLISTENABLE;
            break;
        }

        case USB_EP_INT:
        case USB_EP_ISO:
        {
            list_disable = ~(USB_OHCI_ISOCHRONOUSENABLE | USB_OHCI_INTERRUPTLISTENABLE);
            break;
        }

        default:
        {
            device_data->ed_list[endpoint->list_index].bandwidth =
                (uint16_t) (device_data->ed_list[endpoint->list_index].bandwidth - endpoint->bandwidth);
            device_data->max_bandwidth_inuse = usb_hstd_ohci_check_bandwidth(device_data,
                                                                             USB_OHCI_ED_INTERRUPT_32ms,
                                                                             &list_disable);
            list_disable = 0;
            break;
        }
    }

    ed->list_index = USB_OHCI_ED_EOF;  /* ED is not on a list now */

    /* Set ED for reclamation */
    if (USB_IP0 == ptr->ip)
    {
        ptr->ipp->HCINTERRUPTSTATUS = USB_OHCI_HC_INT_SOF; /* Clear SOF interrupt pending */
    }
    else
    {
 #if USB_NUM_USBIP == 2
        ptr->ipp1->HCINTERRUPTSTATUS = USB_OHCI_HC_INT_SOF; /* Clear SOF interrupt pending */
 #endif
    }

    if (0 != list_disable)
    {
        if (USB_IP0 == ptr->ip)
        {
            ptr->ipp->HCCONTROL  &= list_disable;
            ed->reclamation_frame = usb_hstd_ohci_get_32bit_frame_number(device_data) + 1;
            usb_hstd_ohci_insert_tail_list(&device_data->stalled_ed_reclamation, &ed->link);
            ptr->ipp->HCINTERRUPTENABLE = USB_OHCI_HC_INT_SOF; /* interrupt on next SOF */
        }
        else
        {
 #if USB_NUM_USBIP == 2
            ptr->ipp1->HCCONTROL &= list_disable;
            ed->reclamation_frame = usb_hstd_ohci_get_32bit_frame_number(device_data) + 1;
            usb_hstd_ohci_insert_tail_list(&device_data->stalled_ed_reclamation, &ed->link);
            ptr->ipp1->HCINTERRUPTENABLE = USB_OHCI_HC_INT_SOF; /* interrupt on next SOF */
 #endif
        }
    }
    else
    {
        ed->reclamation_frame = usb_hstd_ohci_get_32bit_frame_number(device_data) + 1;
        usb_hstd_ohci_insert_tail_list(&device_data->running_ed_reclamation, &ed->link);
    }
}                                      /* End of function usb_hstd_ohci_remove_ed() */

/***********************************************************************************************************************
 * Function     : usb_disconnect_done_queue
 * Argument     : uint16_t devadr
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_disconnect_done_queue (usb_utr_t * ptr, uint16_t devadr)
{
    st_usb_ohci_hcca_block_p_t tmp_hcca;
    uint32_t                 * tmp_hcca_done_head;

    FSP_PARAMETER_NOT_USED(devadr);

    usb_cpu_delay_xms(USB_VAL_32);

 #if defined(BSP_MCU_GROUP_RZA_USB)
    tmp_hcca           = (st_usb_ohci_hcca_block_p_t) (r_usb_pa_to_va((uint64_t) usb_hstd_ohci_device_data->hcca));
    tmp_hcca_done_head = (uint32_t *) (r_usb_pa_to_va((uint64_t) tmp_hcca->hcca_done_head));
 #else
    tmp_hcca           = usb_hstd_ohci_device_data->hcca;
    tmp_hcca_done_head = (uint32_t *) tmp_hcca->hcca_done_head;
 #endif
    if (0 != tmp_hcca_done_head)
    {
        usb_hstd_ohci_process_done_queue(ptr, (uint32_t) (uintptr_t) tmp_hcca_done_head);

        /* Done Queue processing complete, notify controller */
        tmp_hcca->hcca_done_head = 0;
        if (USB_IP0 == ptr->ip)
        {
            if (ptr->ipp->HCINTERRUPTSTATUS & USB_OHCI_IS_WRITEBACKDONEHEAD)
            {
                ptr->ipp->HCINTERRUPTSTATUS = USB_OHCI_IS_WRITEBACKDONEHEAD;
            }
        }
        else
        {
 #if USB_NUM_USBIP == 2
            if (ptr->ipp1->HCINTERRUPTSTATUS & USB_OHCI_IS_WRITEBACKDONEHEAD)
            {
                ptr->ipp1->HCINTERRUPTSTATUS = USB_OHCI_IS_WRITEBACKDONEHEAD;
            }
 #endif
        }
    }

    /* r_usb_hstd_hci_wait_time(1); */
}

#endif                                 /* USB_IP_EHCI_OHCI == 1 */

/***********************************************************************************************************************
 * End Of File
 ***********************************************************************************************************************/
