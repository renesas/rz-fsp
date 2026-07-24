/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * File Name    : r_usb_hOhciTransfer.c
 * Description  : OHCI Transfer Code
 ***********************************************************************************************************************/

/**********************************************************************************************************************
 * History : DD.MM.YYYY Version Description
 *         : 31.08.2015 1.00    First Release
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/
#include "../driver/inc/r_usb_hhci_local.h"
#include "../driver/inc/r_usb_extern.h"

#if  USB_IP_EHCI_OHCI == 1

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/
 #define USB_VAL_X20      (0x20U)
 #define USB_VAL_F000     (0xFFFFF000U)
 #define USB_VAL_X1000    (0x00001000U)
 #define USB_VAL_X0FFF    (0x00000FFFU)
 #define USB_VAL_X1FFF    (0x00001FFFU)
 #define USB_VAL_32       (32U)

/***********************************************************************************************************************
 * External variables and functions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Static variables and functions
 ***********************************************************************************************************************/
static void usb_hstd_ohci_setup_request(st_usb_hci_tr_req_t   * p_tr_req,
                                        st_usb_ohci_request_p_t ohci_req);
static uint32_t usb_hstd_ohci_do_transfer_request(usb_utr_t                     * ptr,
                                                  st_usb_ohci_hcd_device_data_p_t device_data,
                                                  uint8_t                         device_address,
                                                  uint8_t                         endpoint_number,
                                                  uint8_t                         endpoint_type,
                                                  uint16_t                        mps,
                                                  uint8_t                         speed,
                                                  st_usb_ohci_request_p_t         ohci_req,
                                                  uint32_t                        pollrate);
static uint32_t usb_hstd_ohci_check_ep(st_usb_ohci_hcd_endpoint_p_t endpoint,
                                       uint8_t                      endpoint_type,
                                       uint16_t                     mps,
                                       uint8_t                      speed);
static uint32_t usb_hstd_ohci_queue_general_request(st_usb_ohci_hcd_endpoint_p_t endpoint,
                                                    st_usb_ohci_request_p_t      ohci_req);
static uint32_t usb_hstd_ohci_queue_iso_request(usb_utr_t                  * ptr,
                                                st_usb_ohci_hcd_endpoint_p_t endpoint,
                                                st_usb_ohci_request_p_t      ohci_req);
static uint32_t usb_hstd_ohci_queue_iso_request_in(usb_utr_t                  * ptr,
                                                   st_usb_ohci_hcd_endpoint_p_t endpoint,
                                                   st_usb_ohci_request_p_t      ohci_req);
static uint32_t usb_hstd_ohci_queue_iso_request_out(usb_utr_t                  * ptr,
                                                    st_usb_ohci_hcd_endpoint_p_t endpoint,
                                                    st_usb_ohci_request_p_t      ohci_req);
static uint32_t usb_hstd_ohci_insert_ed_for_endpoint(st_usb_ohci_hcd_endpoint_p_t endpoint);
static void     usb_hstd_ohci_complete_transfer_request_iso(usb_utr_t                  * ptr,
                                                            st_usb_ohci_hcd_endpoint_p_t endpoint);
static uint32_t usb_hstd_ohci_open_periodic_pipe(st_usb_ohci_hcd_endpoint_p_t endpoint);
static uint32_t usb_hstd_ohci_setup_endpoint(st_usb_ohci_hcd_device_data_p_t device_data,
                                             st_usb_ohci_hcd_endpoint_p_t    endpoint,
                                             uint8_t                         endpoint_type,
                                             uint16_t                        mps,
                                             uint8_t                         devaddr,
                                             uint8_t                         epnum,
                                             uint8_t                         speed,
                                             uint8_t                         direction,
                                             uint32_t                        pollrate);
static uint8_t  usb_hstd_ohci_min_delay(uint8_t delay1, uint8_t delay2);
static uint32_t usb_hstd_ohci_check_transfer_request_end(st_usb_ohci_request_p_t ohci_req,
                                                         uint32_t                mps,
                                                         uint16_t                size);
static uint32_t                     usb_hstd_ohci_cancel_request(usb_utr_t * ptr, st_usb_ohci_request_p_t ohci_req);
static st_usb_ohci_hcd_endpoint_p_t usb_hstd_ohci_initialize_endpoint(st_usb_ohci_hcd_device_data_p_t device_data,
                                                                      uint8_t                         endpoint_type,
                                                                      uint16_t                        max_packet_size,
                                                                      uint8_t                         device_address,
                                                                      uint8_t                         endpoint_number,
                                                                      uint8_t                         speed,
                                                                      uint8_t                         direction,
                                                                      uint32_t                        pollrate);
static st_usb_ohci_list_entry_p_t usb_hstd_ohci_virtual_address_of(uint32_t data);

static const uint32_t gs_usb_hstd_ohci_cc_table[16] =
{
    USB_OHCI_RS_NORMAL_COMPLETION,     /* NoError */
    USB_OHCI_CC_CRC,                   /* CRC */
    USB_OHCI_CC_BITSTUFFING,           /* BitStuffing */
    USB_OHCI_CC_DATATOGGLEMISMATCH,    /* DataToggleMismatch */
    USB_OHCI_CC_STALL,                 /* Stall */
    USB_OHCI_CC_DEVICENOTRESPOND,      /* DeviceNotResponding */
    USB_OHCI_CC_PIDCHECKFAILURE,       /* PIDCheckFailure */
    USB_OHCI_CC_UNEXPECTEDPID,         /* UnexpectedPID */
    USB_OHCI_CC_DATAOVERRUN,           /* DataOverrun */
    USB_OHCI_CC_DATAUNDERRUN,          /* DataUnderrun */
    USB_OHCI_RS_NOT_DONE,
    USB_OHCI_RS_NOT_DONE,
    USB_OHCI_CC_BUFFEROVERRUN,         /* BufferOverrun */
    USB_OHCI_CC_BUFFERUNDERRUN,        /* BufferUnderrun */
    USB_OHCI_RS_NOT_DONE,              /* NotAccessed */
    USB_OHCI_RS_NOT_DONE               /* NotAccessed */
};

static const uint8_t gs_usb_hstd_ohci_offset_psw_table[2][8] =
{
    {0, 1, 2, 3, 4, 5, 6, 7},          /* little endian */
    {1, 0, 3, 2, 5, 4, 7, 6}           /* big endian */
};

/***********************************************************************************************************************
 * Function     : OHCI Make Transfer Request
 * Declaration  : usb_hstd_ohci_make_transfer_request( st_usb_hci_tr_req_t *tr_req )
 * Argument     : st_usb_hci_tr_req_t *tr_req    ; Transfer Request Infomation
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ohci_make_transfer_request (usb_utr_t * ptr, st_usb_hci_tr_req_t * p_tr_req)
{
    st_usb_ohci_request_p_t ohci_req;
    uint32_t                result;

    /* pollrate setting */
    if (USB_EP_INT == p_tr_req->bit.eptype)
    {
        p_tr_req->pollrate = usb_hstd_hci_get_pollrate(p_tr_req) & USB_VAL_3FFF;
    }

    /* Make USBD_Request */
    ohci_req = usb_hstd_ohci_alloc_transfer_request();
    if (NULL == ohci_req)
    {
        return;
    }

#if defined(BSP_CFG_CORE_CA55)
    p_tr_req->hci_info = (void *) r_usb_va_to_pa((uint64_t) ohci_req);
 #else
    p_tr_req->hci_info = ohci_req;
 #endif

    /* Convert Driver_Request to USBD_Request */
    usb_hstd_ohci_setup_request(p_tr_req, ohci_req);

    /* Send Request to HCD */
    result = usb_hstd_ohci_do_transfer_request(ptr,
                                               (st_usb_ohci_hcd_device_data_p_t) (p_tr_req->devinfo->hci_device),
                                               p_tr_req->bit.devadrs,
                                               p_tr_req->bit.epnum,
                                               p_tr_req->bit.eptype,
                                               p_tr_req->bit.mps,
                                               p_tr_req->devinfo->bit.devspeed,
                                               ohci_req,
                                               p_tr_req->pollrate);
    if (FALSE == result)
    {
        usb_hstd_ohci_free_transfer_request(ohci_req);
    }
}

/***********************************************************************************************************************
 * Function     : OHCI Chancel Transfer Request
 * Declaration  : usb_hstd_ohci_cancel_transfer_request( st_usb_hci_tr_req_t *tr_req )
 * Argument     : st_usb_hci_tr_req_t *tr_req ; Transfer Request Address
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ohci_cancel_transfer_request (usb_utr_t * ptr, st_usb_hci_tr_req_t * p_tr_req)
{
    if (NULL == p_tr_req)
    {
        return;
    }

    if (TRUE == p_tr_req->bit.enable)
    {
 #if defined(BSP_CFG_CORE_CA55)
        if (0 != (r_usb_pa_to_va((uint64_t) p_tr_req->hci_info)))
 #else
        if (NULL != p_tr_req->hci_info)
 #endif
        {
            p_tr_req->bit.cancel_req = TRUE;

            /* Cancel Transfer Reques */
 #if defined(BSP_CFG_CORE_CA55)
            usb_hstd_ohci_cancel_request(ptr,
                                         (st_usb_ohci_request_p_t) (uintptr_t) (r_usb_pa_to_va((uint64_t) p_tr_req->
                                                                                               hci_info)));
 #else
            usb_hstd_ohci_cancel_request(ptr, (st_usb_ohci_request_p_t) p_tr_req->hci_info);
 #endif
        }
    }
}

/***********************************************************************************************************************
 * Function     : OHCI Process DoneQueue.
 * Declaration  : void usb_hstd_ohci_process_done_queue( uint32_t phys_hc_td )
 * Argument     : uint32_t phys_hc_td ; Physical Addres Hcca Done Head
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ohci_process_done_queue (usb_utr_t * ptr, uint32_t phys_hc_td)
{
    st_usb_ohci_hcd_transfer_descriptor_p_t    td;
    st_usb_ohci_hcd_transfer_descriptor_p_t    tn;
    st_usb_ohci_hcd_transfer_descriptor_p_t    td_list = NULL;
    st_usb_ohci_request_p_t                    ohci_req;
    st_usb_ohci_hcd_endpoint_p_t               endpoint;
    st_usb_ohci_hc_iso_transfer_descriptor_p_t hc_iso_td;
    st_usb_ohci_iso_transfer_info_p_t          iso_tr_info;
    uint32_t err;
    st_usb_ohci_hcd_transfer_descriptor_p_t tmp_hcd_head_p;
    uint32_t tmp_hc_ed_head_p;
    st_usb_ohci_hcd_endpoint_descriptor_p_t tmp_hcd_ed;
#if  defined(BSP_CFG_CORE_CA55)
    st_usb_ohci_iso_info_p_t                      temp;
#endif

    /* Reverse the queue passed from controller while virtualizing addresses */
    /* NOTE: The following code assumes that a uint32_t and a pointer are the same size */

    if (phys_hc_td & 1)
    {
        phys_hc_td &= ~(uint32_t) 1;
    }

    if (0 == phys_hc_td)
    {
        return;
    }

 #if USB_OHCI_SHAREDMEMORYTYPE == USB_OHCI_SHAREDMEMORYTYPE_EXCLUSIVE
    phys_hc_td += USB_OHCI_SHAREDMEMORY_OFFSET;
    do
    {
        td = (st_usb_ohci_hcd_transfer_descriptor_p_t) usb_hstd_ohci_scan_containing_record(usb_hstd_ohci_virtual_address_of(
                                                                                                phys_hc_td),
                                                                                            USB_OHCI_CR_TRANSFER_DESCRIPTOR,
                                                                                            USB_OHCI_CR_REQUESTLIST);

        phys_hc_td  = td->hc_td.next_td;
        phys_hc_td += USB_OHCI_SHAREDMEMORY_OFFSET;

        if (NULL == td_list)
        {
            td->hc_td.next_td = USB_NULL;
        }
        else
        {
            td->hc_td.next_td = (uint32_t) (td_list->physicaladdress + USB_OHCI_SHAREDMEMORY_OFFSET);
        }

        td_list = td;
    } while (USB_OHCI_SHAREDMEMORY_OFFSET != phys_hc_td);

 #elif USB_OHCI_SHAREDMEMORYTYPE == USB_OHCI_SHAREDMEMORYTYPE_PCI
 #if defined(BSP_CFG_CORE_CA55)
    phys_hc_td = (uint32_t) r_usb_pa_to_va((uint64_t) phys_hc_td);
  #endif
    do
    {
        td = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) usb_hstd_ohci_scan_containing_record(usb_hstd_ohci_virtual_address_of(
                                                                                                phys_hc_td),
                                                                                            USB_OHCI_CR_TRANSFER_DESCRIPTOR,
                                                                                            USB_OHCI_CR_REQUESTLIST);

        if (0 != td->hc_td.next_td)
        {
 #if defined(BSP_CFG_CORE_CA55)
            phys_hc_td = (uint32_t) r_usb_pa_to_va((uint64_t) td->hc_td.next_td);
  #else
            phys_hc_td = td->hc_td.next_td;
  #endif
        }
        else
        {
            phys_hc_td = 0;
        }

        if (NULL == td_list)
        {
            td->hc_td.next_td = 0;
        }
        else
        {
 #if defined(BSP_CFG_CORE_CA55)
            td->hc_td.next_td = (uint32_t) (r_usb_pa_to_va((uint64_t) td_list->physical_address));
  #else
            td->hc_td.next_td = td_list->physical_address;
  #endif
        }

        td_list = td;
    } while (0 != phys_hc_td);

 #else
    do
    {
        td = (st_usb_ohci_hcd_transfer_descriptor_p_t) usb_hstd_ohci_scan_containing_record(usb_hstd_ohci_virtual_address_of(
                                                                                                phys_hc_td),
                                                                                            USB_OHCI_CR_TRANSFER_DESCRIPTOR,
                                                                                            USB_OHCI_CR_REQUESTLIST);
 #if defined(BSP_CFG_CORE_CA55)
        phys_hc_td = (r_usb_pa_to_va((uint64_t) td->hc_td.next_td));
  #else
        phys_hc_td = r_usb_pa_to_va((uint32_t) td->hc_td.next_td);
  #endif
        if (NULL == td_list)
        {
            td->hc_td.next_td = USB_NULL;
        }
        else
        {
  #if defined(BSP_CFG_CORE_CA55)
            td->hc_td.next_td = (uint32_t) (r_usb_pa_to_va((uint64_t) td_list->physical_address));
  #else
            td->hc_td.next_td = (uint32_t) r_usb_pa_to_va((uint32_t) td_list->physical_address);
  #endif
        }

        td_list = td;
    } while (0 != phys_hc_td);
 #endif

    /* Process list that is now reordered to completion order */
    while (NULL != td_list)
    {
        td = td_list;
        if (0 != td->hc_td.next_td)
        {
 #if defined(BSP_CFG_CORE_CA55)
            td_list =
                (st_usb_ohci_hcd_transfer_descriptor_p_t) (uintptr_t) (r_usb_pa_to_va((uint64_t) ((td->hc_td.next_td) -
                                                                                                  USB_VAL_X20)));
 #else
            td_list = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) ((td->hc_td.next_td) - USB_VAL_X20);
 #endif
        }
        else
        {
            td_list = NULL;
        }

        if (USB_OHCI_TD_CANCELED == td->td_status)
        {
            usb_hstd_ohci_free_transfer_descriptor(td);
            continue;
        }

#if defined(BSP_CFG_CORE_CA55)
        ohci_req = (st_usb_ohci_request_p_t) (uintptr_t) (r_usb_pa_to_va((uint64_t) td->usb_drequest));
        endpoint = (st_usb_ohci_hcd_endpoint_p_t) (uintptr_t) (r_usb_pa_to_va((uint64_t) td->endpoint));
#else
        ohci_req = (st_usb_ohci_request_p_t)(uintptr_t) td->usb_drequest;
        endpoint = td->endpoint;
 #endif

        if (USB_EP_ISO != endpoint->type)
        {
            if (0 != td->hc_td.cbp)
            {
                td->transfer_count -=
                    (((td->hc_td.be ^ td->hc_td.cbp) & USB_VAL_F000) ? USB_VAL_X1000 : 0) +
                    (td->hc_td.be & USB_VAL_X0FFF) - (td->hc_td.cbp & USB_VAL_X0FFF) + 1;
            }

            if (USB_OHCI_PID_SETUP != td->hc_td.control.dp)
            {
                ohci_req->buffer_length += td->transfer_count;
            }

            if (USB_OHCI_CC_NOERROR == td->hc_td.control.cc)
            {
                /* td completed without error, remove it from USB_OHCI_REQUEST list, */
                /* if USB_OHCI_REQUEST list is now empty, then complete the request. */
#if defined(BSP_CFG_CORE_CA55)
                endpoint->hcd_head_p =
                    (uint32_t) usb_hstd_ohci_physical_address_of((void *) (uintptr_t) td->next_hcd_td);
 #else
                endpoint->hcd_head_p = td->next_hcd_td;
 #endif
                usb_hstd_ohci_remove_list_entry(&td->request_list);
                usb_hstd_ohci_free_transfer_descriptor(td);
                err = usb_hstd_ohci_is_list_empty(&ohci_req->hcd_list);
                if (TRUE == err)
                {
                    if (USB_OHCI_RS_CANCELING != ohci_req->status)
                    {
                        ohci_req->status = USB_OHCI_RS_NORMAL_COMPLETION;
                    }
                    else
                    {
                        ohci_req->status = USB_OHCI_RS_CANCELED;
                    }

                    usb_hstd_ohci_complete_transfer_request(ptr, ohci_req);
                }
            }
            else
            {
                /* TD completed with an error, remove it and other TDs for same request, */
                /* set appropriate status in USB_OHCI_REQUEST and then complete it. There */
                /* are two special cases: 1) error is DataUnderun on Bulk or Interrupt and */
                /* ShortXferOk is true; for this do not report error to USBD and restart */
                /* endpoint. 2) error is DataUnderrun on Control and ShortXferOk is true; */
                /* for this the final status TD for the ohci_req should not be canceled, the */
                /* ohci_req should not be completed, and the endpoint should be restarted. */
                /* NOTE: The endpoint has been halted by the controller */

#if defined(BSP_CFG_CORE_CA55)
                for (tn =
                         (st_usb_ohci_hcd_transfer_descriptor_p_t) (uintptr_t) (r_usb_pa_to_va((uint64_t) endpoint->
                                                                                               hcd_head_p));
                     tn !=
                     (st_usb_ohci_hcd_transfer_descriptor_p_t) (uintptr_t) (r_usb_pa_to_va((uint64_t) endpoint->
                                                                                           hcd_tail_p)); )

                {
                    if ((ohci_req !=
                         (st_usb_ohci_request_p_t) (uintptr_t) (r_usb_pa_to_va((uint64_t) tn->usb_drequest))) ||
                        ((USB_OHCI_CC_DATAUNDERRUN == td->hc_td.control.cc) &&
                         (0 != ohci_req->shortxferok) &&
                         (USB_OHCI_RS_CANCELING != ohci_req->status) &&
                         (td->hc_td.control.dp != tn->hc_td.control.dp)))
                    {
                        break;
                    }

                    tn =
                        (st_usb_ohci_hcd_transfer_descriptor_p_t) (uintptr_t) (r_usb_pa_to_va((uint64_t) tn->next_hcd_td));
                }

                endpoint->hcd_head_p = (uint32_t) usb_hstd_ohci_physical_address_of(tn);
                tmp_hcd_ed =
                    (st_usb_ohci_hcd_endpoint_descriptor_p_t) (uintptr_t) (r_usb_pa_to_va((uint64_t) endpoint->hcd_ed));
  #else
                tn = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) endpoint->hcd_head_p;
                while (tn != (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) endpoint->hcd_tail_p)
                {
                    if ((ohci_req != tn->usb_drequest) ||
                        ((USB_OHCI_CC_DATAUNDERRUN == td->hc_td.control.cc) &&
                         (0 != ohci_req->shortxferok) &&
                         (USB_OHCI_RS_CANCELING != ohci_req->status) &&
                         (td->hc_td.control.dp != tn->hc_td.control.dp)))
                    {
                        break;
                    }

                    tn = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) tn->next_hcd_td;
                }
                endpoint->hcd_head_p = (struct usb_ohci_hcd_transfer_descriptor *) tn;
                tmp_hcd_ed           = (st_usb_ohci_hcd_endpoint_descriptor_p_t)(uintptr_t) endpoint->hcd_ed;
 #endif
                tmp_hcd_ed->hc_ed.head_p = tn->physical_address |
                                           (tmp_hcd_ed->hc_ed.head_p &
                                            (USB_OHCI_HCED_HEADP_HALT | USB_OHCI_HCED_HEADP_CARRY));


                tn =
                    (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) usb_hstd_ohci_scan_containing_record(usb_hstd_ohci_remove_list_head(
                                                                                                       &
                                                                                                       ohci_req
                                                                                                       ->
                                                                                                       hcd_list),
                                                                                                   USB_OHCI_CR_TRANSFER_DESCRIPTOR,
                                                                                                   USB_OHCI_CR_REQUESTLIST);
                while (tn != NULL)
                {
 #if defined(BSP_CFG_CORE_CA55)
                    if ((tn != td) &&
                        (tn !=
                         (st_usb_ohci_hcd_transfer_descriptor_p_t) (uintptr_t) (r_usb_pa_to_va((uint64_t) endpoint->
                                                                                               hcd_head_p))))
 #else
                    if ((tn != td) &&
                        (tn != (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) endpoint->hcd_head_p))
 #endif
                    {
                        usb_hstd_ohci_free_transfer_descriptor(tn);
                    }

                    tn =
                        (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) usb_hstd_ohci_scan_containing_record(usb_hstd_ohci_remove_list_head(
                                                                                                           &
                                                                                                           ohci_req
                                                                                                           ->
                                                                                                           hcd_list),
                                                                                                       USB_OHCI_CR_TRANSFER_DESCRIPTOR,
                                                                                                       USB_OHCI_CR_REQUESTLIST);
                }

 #if defined(BSP_CFG_CORE_CA55)
                tmp_hc_ed_head_p = (uint32_t) (r_usb_pa_to_va((uint64_t) tmp_hcd_ed->hc_ed.head_p));
                tmp_hcd_head_p   =
                    (st_usb_ohci_hcd_transfer_descriptor_p_t) (uintptr_t) (r_usb_pa_to_va((uint64_t) endpoint->
                                                                                          hcd_head_p));
 #else
                tmp_hc_ed_head_p = tmp_hcd_ed->hc_ed.head_p;
                tmp_hcd_head_p   = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) endpoint->hcd_head_p;
 #endif
#if defined(BSP_CFG_CORE_CA55)
                if (tmp_hcd_head_p->usb_drequest == (uint32_t)(uintptr_t) ohci_req)
#else
                if (tmp_hcd_head_p->usb_drequest == ohci_req)
#endif
                {
                    usb_hstd_ohci_insert_tail_list(&ohci_req->hcd_list, &tmp_hcd_head_p->request_list);
 #if defined(BSP_CFG_CORE_CA55)
                    tmp_hcd_ed->hc_ed.head_p =
                        (uint32_t) usb_hstd_ohci_physical_address_of((void *) (uintptr_t) (tmp_hc_ed_head_p &
                                                                                           ~USB_OHCI_HCED_HEADP_HALT));
 #else
                    tmp_hcd_ed->hc_ed.head_p = (tmp_hc_ed_head_p & ~USB_OHCI_HCED_HEADP_HALT);
 #endif
                }
                else
                {
                    if ((0 != ohci_req->shortxferok) && (USB_OHCI_CC_DATAUNDERRUN == td->hc_td.control.cc))
                    {
                        if (USB_OHCI_RS_CANCELING != ohci_req->status)
                        {
                            ohci_req->status = USB_OHCI_RS_NORMAL_COMPLETION;
                        }
                        else
                        {
                            ohci_req->status = USB_OHCI_RS_CANCELED;
                        }

 #if defined(BSP_CFG_CORE_CA55)
                        tmp_hcd_ed->hc_ed.head_p &=
                            (uint32_t) usb_hstd_ohci_physical_address_of((void *) (uintptr_t) (tmp_hc_ed_head_p &
                                                                                               (uint32_t) ~
                                                                                               USB_OHCI_HCED_HEADP_HALT));
 #else
                        tmp_hcd_ed->hc_ed.head_p &= (tmp_hc_ed_head_p & (uint32_t) ~USB_OHCI_HCED_HEADP_HALT);
 #endif
                    }
                    else if (USB_OHCI_RS_CANCELING != ohci_req->status)
                    {
                        ohci_req->status = gs_usb_hstd_ohci_cc_table[td->hc_td.control.cc];
                    }
                    else
                    {
                        ohci_req->status = USB_OHCI_RS_CANCELED;
                    }

                    usb_hstd_ohci_complete_transfer_request(ptr, ohci_req);
                }

                usb_hstd_ohci_free_transfer_descriptor(td);

                switch (endpoint->type)
                {
                    case USB_EP_CNTRL:
                    {
                        USB00->HCCOMMANDSTATUS = USB_OHCI_CONTROLLISTFILLED;
                        break;
                    }

                    case USB_EP_BULK:
                    {
                        USB00->HCCOMMANDSTATUS = USB_OHCI_BULKLISTFILLED;
                        break;
                    }

                    default:
                    {
                        break;
                    }
                }
            }
        }
        else if (USB_EP_ISO == endpoint->type)
        {
            /* Code for Isochronous */
#if defined(BSP_CFG_CORE_CA55)
            hc_iso_td =
                (st_usb_ohci_hc_iso_transfer_descriptor_p_t) (uintptr_t) (r_usb_pa_to_va((uint64_t) &td->hc_td));
            temp        = (st_usb_ohci_iso_info_p_t) (uintptr_t) &endpoint->iso_info;
            iso_tr_info =
                (st_usb_ohci_iso_transfer_info_p_t) (uintptr_t) (r_usb_pa_to_va((uint64_t) &temp->transfer_info[temp->
                                                                                                                end_p]));
            temp->end_p++;
            temp->end_p &= USB_OHCI_ISO_MAX_FRAME - 1;
#else /* defined(BSP_CFG_CORE_CA55) */
            hc_iso_td = (st_usb_ohci_hc_iso_transfer_descriptor_p_t) &td->hc_td;
            iso_tr_info =
                (st_usb_ohci_iso_transfer_info_p_t) &endpoint->iso_info->transfer_info[endpoint->iso_info->end_p];
            endpoint->iso_info->end_p++;
            endpoint->iso_info->end_p &= USB_OHCI_ISO_MAX_FRAME - 1;
#endif /* defined(BSP_CFG_CORE_CA55) */
            iso_tr_info->control_cc = hc_iso_td->control.cc;
            if (endpoint->control.d == (USB_HCI_DIRECTION_IN + 1))
            {
                if (1 == USB_HCI_GET_ENDIAN)
                {
                    iso_tr_info->size   = hc_iso_td->usb_ohci_offset_psw[1].psw.size;
                    iso_tr_info->psw_cc = hc_iso_td->usb_ohci_offset_psw[1].psw.cc;
                }
                else
                {
                    iso_tr_info->size   = hc_iso_td->usb_ohci_offset_psw[0].psw.size;
                    iso_tr_info->psw_cc = hc_iso_td->usb_ohci_offset_psw[0].psw.cc;
                }
            }
            else
            {
                if (1 == USB_HCI_GET_ENDIAN)
                {
                    iso_tr_info->size   = (uint16_t) (iso_tr_info->size - hc_iso_td->usb_ohci_offset_psw[1].psw.size);
                    iso_tr_info->psw_cc = hc_iso_td->usb_ohci_offset_psw[1].psw.cc;
                }
                else
                {
                    iso_tr_info->size   = (uint16_t) (iso_tr_info->size - hc_iso_td->usb_ohci_offset_psw[0].psw.size);
                    iso_tr_info->psw_cc = hc_iso_td->usb_ohci_offset_psw[0].psw.cc;
                }
            }


#if  defined(BSP_CFG_CORE_CA55)
            temp->start_cnt--;
            temp->end_cnt++;
            endpoint->hcd_head_p = (uint32_t) usb_hstd_ohci_physical_address_of((void *) (uintptr_t) td->next_hcd_td);
#else
            endpoint->iso_info->start_cnt--;
            endpoint->iso_info->end_cnt++;
            endpoint->hcd_head_p = td->next_hcd_td;
 #endif
            usb_hstd_ohci_remove_list_entry(&td->request_list);
            usb_hstd_ohci_free_transfer_descriptor(td);

#if   defined(BSP_CFG_CORE_CA55)
            if (USB_NULL != temp->usb_drequest)
#else
            if (USB_NULL != endpoint->iso_info->usb_drequest)
#endif
            {
                usb_hstd_ohci_complete_transfer_request_iso(ptr, endpoint);
            }
            else
            {

            }
        }
        else
        {

        }
    }
}

/***********************************************************************************************************************
 * Function     : OHCI Complete Transfer Request
 * Declaration  : void usb_hstd_ohci_complete_transfer_request( st_usb_ohci_request_p_t ohci_req )
 * Argument     : st_usb_ohci_request_p_t ohci_req ; OHCI transfer request pointer
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
void usb_hstd_ohci_complete_transfer_request (usb_utr_t * ptr, st_usb_ohci_request_p_t ohci_req)
{
    st_usb_hci_tr_req_t * p_tr_req;
    uint16_t              status;

    if (FALSE == ohci_req->using_flag)
    {
        return;
    }

#if defined(BSP_CFG_CORE_CA55)
    p_tr_req = (st_usb_hci_tr_req_t *) (uintptr_t) (r_usb_pa_to_va((uint64_t) ohci_req->driver_request));
 #else
    p_tr_req = (st_usb_hci_tr_req_t *)(uintptr_t) ohci_req->driver_request;
 #endif
    if (FALSE == p_tr_req->bit.enable)
    {
        return;
    }

    p_tr_req->status       = ohci_req->status;
    p_tr_req->actual_size += ohci_req->buffer_length;

    if (USB_OHCI_RS_NORMAL_COMPLETION != p_tr_req->status)
    {
        USB_HCI_PRINTF0_R("Condition Code : ");
        if (USB_OHCI_RS_CANCELED == p_tr_req->status)
        {
            USB_HCI_PRINTF0_R("Request is Canceled\n");
        }
        else if (USB_OHCI_CC_CRC == p_tr_req->status)
        {
            USB_HCI_PRINTF0_R("CRC Error\n");
        }
        else if (USB_OHCI_CC_BITSTUFFING == p_tr_req->status)
        {
            USB_HCI_PRINTF0_R("BitStuffing Error\n");
        }
        else if (USB_OHCI_CC_DATATOGGLEMISMATCH == p_tr_req->status)
        {
            USB_HCI_PRINTF0_R("DataToggleMismatch Error\n");
        }
        else if (USB_OHCI_CC_STALL == p_tr_req->status)
        {
            USB_HCI_PRINTF0_R("Endpoint is Stalled\n");
        }
        else if (USB_OHCI_CC_DEVICENOTRESPOND == p_tr_req->status)
        {
            USB_HCI_PRINTF0_R("DeviceNotRespond\n");
        }
        else if (USB_OHCI_CC_PIDCHECKFAILURE == p_tr_req->status)
        {
            USB_HCI_PRINTF0_R("PIDCheckFailured\n");
        }
        else if (USB_OHCI_CC_UNEXPECTEDPID == p_tr_req->status)
        {
            USB_HCI_PRINTF0_R("UnexpectedPID\n");
        }
        else if (USB_OHCI_CC_DATAOVERRUN == p_tr_req->status)
        {
            USB_HCI_PRINTF0_R("DataOverrun\n");
        }
        else if (USB_OHCI_CC_DATAUNDERRUN == p_tr_req->status)
        {
            USB_HCI_PRINTF0_R("DataUnderrun\n");
        }
        else if (USB_OHCI_CC_BUFFEROVERRUN == p_tr_req->status)
        {
            USB_HCI_PRINTF0_R("BufferOverrun\n");
        }
        else if (USB_OHCI_CC_BUFFERUNDERRUN == p_tr_req->status)
        {
            USB_HCI_PRINTF0_R("BufferUnderrun\n");
        }
        else
        {
        }

        if (USB_EP_ISO != p_tr_req->bit.eptype)
        {
            usb_hstd_ohci_pause_endpoint(ptr, p_tr_req->bit.devadrs, p_tr_req->bit.epnum, ohci_req->xferinfo);
        }
    }

    /* Clear completed USBD_Request */
    usb_hstd_ohci_free_transfer_request(ohci_req);

    /* Set Transfer Status */
    status = usb_hstd_ohci_get_transfer_end_status(p_tr_req);

    p_tr_req->bit.enable = FALSE;
    ptr->keyword         = p_tr_req->bit.devadrs;

    g_usb_hstd_hci_callback.tr_end_cb(ptr, p_tr_req->utr_p, p_tr_req->actual_size, status);
}

/* Static Function */

/***********************************************************************************************************************
 * Function     : OHCI Setup Request
 * Declaration  : void usb_hstd_ohci_setup_request( st_usb_hci_tr_req_t *tr_req, st_usb_ohci_request_p_t ohci_req )
 * Argument     : st_usb_hci_tr_req_t *tr_req      ; HCI transfer request pointer
 *              : st_usb_ohci_request_p_t ohci_req ; OHCI transfer request pointer
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
static void usb_hstd_ohci_setup_request (st_usb_hci_tr_req_t * p_tr_req, st_usb_ohci_request_p_t ohci_req)
{
  #if defined(BSP_CFG_CORE_CA55)
    ohci_req->buffer        = p_tr_req->databuf;
#else
    ohci_req->buffer        = (uint8_t *) p_tr_req->databuf;
#endif
    ohci_req->buffer_length = p_tr_req->trsize;
    ohci_req->xferinfo      = p_tr_req->bit.direction;
    ohci_req->max_int_delay = 0x00;
    ohci_req->shortxferok   = 0x01;

    if (0x00 == p_tr_req->bit.epnum)
    {
#if defined(BSP_CFG_CORE_CA55)
        ohci_req->setup = (uint32_t) usb_hstd_ohci_physical_address_of(p_tr_req->setupbuf);
#else
        ohci_req->setup = (uint8_t *) p_tr_req->setupbuf;
 #endif
    }

#if defined(BSP_CFG_CORE_CA55)
    ohci_req->driver_request = (uint32_t) usb_hstd_ohci_physical_address_of(p_tr_req);
#else
    ohci_req->driver_request = (uint32_t *) p_tr_req;
 #endif
    ohci_req->status = USB_OHCI_RS_NOT_REQUESTED;
}

/***********************************************************************************************************************
 * Function     : OHCI Do Transfer Request
 * Declaration  : uint32_t usb_hstd_ohci_do_transfer_request(
 *              : st_usb_ohci_hcd_device_data_p_t device_data,
 *              : uint8_t device_address,
 *              : uint8_t endpoint_number,
 *              : uint8_t endpoint_type,
 *              : uint16_t mps,
 *              : uint8_t speed,
 *              : st_usb_ohci_request_p_t ohci_req,
 *              : uint32_t pollrate )
 * Argument     : st_usb_ohci_hcd_device_data_p_t device_data ; Device Data pointer
 *              : uint8_t device_address                 ; devide address
 *              : uint8_t endpoint_number                ; endpoint no
 *              : uint8_t endpoint_type                  ; endpoint type
 *              : uint16_t mps                           ; Max Packet Size
 *              : uint8_t speed                          ; device speed
 *              : st_usb_ohci_request_p_t ohci_req            ; Driver Request Infomation pointer
 *              : uint32_t pollrate                      ; polling rate
 * Return       : uint32_t                               ; result( TRUE:Nomal End, FALSE:Request Fail )
 * Note         :
 ***********************************************************************************************************************/
static uint32_t usb_hstd_ohci_do_transfer_request (usb_utr_t                     * ptr,
                                                   st_usb_ohci_hcd_device_data_p_t device_data,
                                                   uint8_t                         device_address,
                                                   uint8_t                         endpoint_number,
                                                   uint8_t                         endpoint_type,
                                                   uint16_t                        mps,
                                                   uint8_t                         speed,
                                                   st_usb_ohci_request_p_t         ohci_req,
                                                   uint32_t                        pollrate)
{
    st_usb_ohci_hcd_endpoint_p_t endpoint;
    uint32_t ret = FALSE;
    uint32_t err1;
    uint32_t err2;

    endpoint = usb_hstd_ohci_scan_endpoint(device_address, endpoint_number, ohci_req->xferinfo);
    if (NULL != endpoint)
    {
        err1 = usb_hstd_ohci_check_ep(endpoint, endpoint_type, mps, speed);
        if (FALSE == err1)
        {
            usb_hstd_ohci_remove_endpoint(device_address, endpoint_number, ohci_req->xferinfo, FALSE);
            endpoint = NULL;
        }
    }

    err1 = usb_hstd_ohci_check_remained_td();
    if (TRUE == err1)
    {
        if (NULL == endpoint)
        {
            err1 = usb_hstd_ohci_check_remained_ep();
            err2 = usb_hstd_ohci_check_remained_ed();
            if ((TRUE == err1) && (TRUE == err2))
            {
                endpoint = usb_hstd_ohci_initialize_endpoint(device_data,        /* Device Data pointer */
                                                             endpoint_type,      /* endpoint type */
                                                             mps,                /* Max Packet Size */
                                                             device_address,     /* devide address */
                                                             endpoint_number,    /* endpoint no */
                                                             speed,              /* device speed */
                                                             ohci_req->xferinfo, /* direction */
                                                             pollrate            /* polling rate */
                                                             );
            }
        }

        if (NULL != endpoint)
        {
            if (USB_EP_ISO == endpoint_type)
            {
                ret = usb_hstd_ohci_queue_iso_request(ptr, endpoint, ohci_req);
            }
            else
            {
                ret = usb_hstd_ohci_queue_general_request(endpoint, ohci_req);
            }
        }
    }

    return ret;
}

/***********************************************************************************************************************
 * Function     : OHCI Check difference between received information
 * Declaration  : uint8_t usb_hstd_ohci_check_ep( st_usb_ohci_hcd_endpoint_p_t endpoint, uint8_t endpoint_type, uint16_t mps, uint8_t speed )
 * Argument     : st_usb_ohci_hcd_endpoint_p_t ; endpoint pointer
 *              : uint8_t endpoint_type   ; endpoint type
 *              : uint16_t mps            ; max packet size
 *              : uint8_t speed           ; device speed
 * Return       : uint32_t                ; check result( TRUE:same, FALSE:difference )
 * Note         :
 ***********************************************************************************************************************/
static uint32_t usb_hstd_ohci_check_ep (st_usb_ohci_hcd_endpoint_p_t endpoint,
                                        uint8_t                      endpoint_type,
                                        uint16_t                     mps,
                                        uint8_t                      speed)
{
    uint8_t ret = FALSE;

    if (NULL != endpoint)
    {
        if ((mps == endpoint->max_packet) && (speed == endpoint->control.s) && (endpoint_type == endpoint->type))
        {
            if (USB_EP_INT == endpoint_type)
            {
                switch (endpoint->rate)
                {
                    case 1:
                    case 2:
                    case 4:
                    case 8:
                    case 16:
                    case USB_VAL_32:
                    {
                        ret = TRUE;
                        break;
                    }

                    default:
                    {
                        break;
                    }
                }
            }
            else
            {
                ret = TRUE;
            }
        }
    }

    return ret;
}

/***********************************************************************************************************************
 * Function     : Generate TD
 * Declaration  : uint32_t usb_hstd_ohci_queue_general_request( st_usb_ohci_hcd_endpoint_p_t endpoint, st_usb_ohci_request_p_t ohci_req )
 * Argument     : st_usb_ohci_hcd_endpoint_p_t endpoint ; Endpoint Pointer
 *              : st_usb_ohci_request_p_t ohci_req      ; Driver ohci_req Infomation pointer
 * Return       : uint32_t                         ; result( TRUE:Nomal End, FALSE:Fail )
 * Note         :
 ***********************************************************************************************************************/
static uint32_t usb_hstd_ohci_queue_general_request (st_usb_ohci_hcd_endpoint_p_t endpoint,
                                                     st_usb_ohci_request_p_t      ohci_req)
{
    st_usb_ohci_hcd_endpoint_descriptor_p_t ed;
    st_usb_ohci_hcd_transfer_descriptor_p_t td;
    st_usb_ohci_hcd_transfer_descriptor_p_t list_td = NULL;
    uint32_t  remaining_length;
    uint32_t  count;
#if defined(BSP_CFG_CORE_CA55)
    uint32_t  p_current_buffer_pointer;
#else
    uint8_t * p_current_buffer_pointer;
#endif

    st_usb_ohci_hcd_transfer_descriptor_p_t tmp_next_hcd_td;

 #if defined(BSP_CFG_CORE_CA55)
    ed = (st_usb_ohci_hcd_endpoint_descriptor_p_t) (uintptr_t) (r_usb_pa_to_va((uint64_t) endpoint->hcd_ed));
 #else
    ed = (st_usb_ohci_hcd_endpoint_descriptor_p_t)(uintptr_t) endpoint->hcd_ed;
 #endif

    if ((NULL == ed) || (USB_OHCI_ED_EOF == ed->list_index))
    {

        /* endpoint has been removed from schedule */
        return FALSE;
    }

 #if defined(BSP_CFG_CORE_CA55)
    td = (st_usb_ohci_hcd_transfer_descriptor_p_t) (uintptr_t) (r_usb_pa_to_va((uint64_t) endpoint->hcd_tail_p)); /* hcd_head_p => hcd_tail_p */
 #else
    td =
        (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) endpoint->hcd_tail_p;                            /* hcd_head_p => hcd_tail_p */
 #endif
    ohci_req->status        = USB_OHCI_RS_NOT_DONE;
    remaining_length        = ohci_req->buffer_length;
    ohci_req->buffer_length = 0;                                                                   /* Report back bytes transferred so far */
#if defined(BSP_CFG_CORE_CA55)
    p_current_buffer_pointer = (uint32_t) (uintptr_t) (r_usb_pa_to_va((uint64_t) ohci_req->buffer));
#else
    p_current_buffer_pointer = ohci_req->buffer;
 #endif
    usb_hstd_ohci_initialize_list_head(&ohci_req->hcd_list);

    if (USB_EP_CNTRL == endpoint->type)
    {
        /* Setup a TD for setup packet */
        usb_hstd_ohci_insert_tail_list(&ohci_req->hcd_list, &td->request_list);
#if defined(BSP_CFG_CORE_CA55)
        td->usb_drequest   = (uint32_t)(uintptr_t)ohci_req;
        td->endpoint       = (uint32_t)(uintptr_t)endpoint;
#else
        td->usb_drequest   = ohci_req;
        td->endpoint       = endpoint;
#endif
        td->cancel_pending = FALSE;
 #if defined(BSP_CFG_CORE_CA55)
        td->hc_td.cbp = (uint32_t) usb_hstd_ohci_physical_address_of((void *) (uintptr_t) ohci_req->setup);
        td->hc_td.be  = (uint32_t) usb_hstd_ohci_physical_address_of((void *) (uintptr_t) (ohci_req->setup + 7));
 #else
        td->hc_td.cbp = (uint32_t) ohci_req->setup;
        td->hc_td.be  = (uint32_t) (ohci_req->setup + 7);
 #endif
        td->transfer_count       = 0;
        td->hc_td.control.dp     = USB_OHCI_PID_SETUP;
        td->hc_td.control.toggle = 2;
        td->hc_td.control.r      = TRUE;
        td->hc_td.control.int_d  = 7;  /* Specify no interrupt */
        td->hc_td.control.cc     = USB_OHCI_CC_NOTACCESSED;
        tmp_next_hcd_td          = usb_hstd_ohci_allocate_transfer_descriptor();
#if defined(BSP_CFG_CORE_CA55)
        td->next_hcd_td = (uint32_t) usb_hstd_ohci_physical_address_of(
            (void *) (uintptr_t) tmp_next_hcd_td);
        td->hc_td.next_td = (uint32_t) usb_hstd_ohci_physical_address_of(
            (void *) (uintptr_t) &tmp_next_hcd_td->hc_td);
        tmp_next_hcd_td->physical_address = (uint32_t) usb_hstd_ohci_physical_address_of(
            (void *) (uintptr_t) &tmp_next_hcd_td->hc_td);
#else
        td->next_hcd_td =
            (struct usb_ohci_hcd_transfer_descriptor *) tmp_next_hcd_td;
        td->hc_td.next_td                 = (uint32_t)(uintptr_t) &tmp_next_hcd_td->hc_td;
        tmp_next_hcd_td->physical_address = (uint32_t)(uintptr_t) &tmp_next_hcd_td->hc_td;
 #endif

        list_td = td;
        td      = tmp_next_hcd_td;
    }

    /* Setup TD(s) for data packets */
    while ((0 != remaining_length) || (NULL == list_td))
    {
        usb_hstd_ohci_insert_tail_list(&ohci_req->hcd_list, &td->request_list);
#if defined(BSP_CFG_CORE_CA55)
        td->usb_drequest = (uint32_t) usb_hstd_ohci_physical_address_of(ohci_req);
        td->endpoint     = (uint32_t) usb_hstd_ohci_physical_address_of(endpoint);
#else
        td->usb_drequest = (struct usb_ohci_request *) ohci_req;
        td->endpoint     = endpoint;
 #endif
        td->cancel_pending = FALSE;

        if (0 != remaining_length)
        {
#if defined(BSP_CFG_CORE_CA55)
            td->hc_td.cbp = (uint32_t) usb_hstd_ohci_physical_address_of((void *)(uint64_t)p_current_buffer_pointer);
#else
            td->hc_td.cbp = (uint32_t) p_current_buffer_pointer;
 #endif
            count = USB_OHCI_MAXTDSIZE - (td->hc_td.cbp & USB_VAL_X0FFF);
            if (count < remaining_length)
            {
            }
            else
            {
                count = remaining_length;
            }

            p_current_buffer_pointer += count - 1;
#if defined(BSP_CFG_CORE_CA55)
            td->hc_td.be = (uint32_t) usb_hstd_ohci_physical_address_of((void *)(uint64_t)p_current_buffer_pointer++);
#else
            td->hc_td.be = (uint32_t) p_current_buffer_pointer++;
 #endif
        }
        else
        {
            count         = 0;
            td->hc_td.be  = count;
            td->hc_td.cbp = td->hc_td.be;
        }

        td->transfer_count   = count;
        td->hc_td.control.dp = (uint32_t) (ohci_req->xferinfo + 1) & 0x00000003U;

        if (USB_EP_CNTRL == endpoint->type)
        {
            td->hc_td.control.toggle = 3;
        }
        else
        {
            td->hc_td.control.toggle = 0;
        }

        if ((0 == (remaining_length -= count)) && (0 != ohci_req->shortxferok))
        {
            td->hc_td.control.r = TRUE;
        }
        else
        {
            td->hc_td.control.r = FALSE;
        }

        td->hc_td.control.int_d = 7;   /* Specify no interrupt */
        td->hc_td.control.cc    = USB_OHCI_CC_NOTACCESSED;

        tmp_next_hcd_td = usb_hstd_ohci_allocate_transfer_descriptor();
#if defined(BSP_CFG_CORE_CA55)
        td->next_hcd_td                   = (uint32_t) usb_hstd_ohci_physical_address_of(tmp_next_hcd_td);
        td->hc_td.next_td                 = (uint32_t) usb_hstd_ohci_physical_address_of(&tmp_next_hcd_td->hc_td);
        tmp_next_hcd_td->physical_address = (uint32_t) usb_hstd_ohci_physical_address_of(&tmp_next_hcd_td->hc_td);
#else
        td->next_hcd_td =
            (struct usb_ohci_hcd_transfer_descriptor *) tmp_next_hcd_td;
        td->hc_td.next_td                 = (uint32_t)(uintptr_t) &tmp_next_hcd_td->hc_td;
        tmp_next_hcd_td->physical_address = td->hc_td.next_td;
 #endif

        list_td = td;
        td      = tmp_next_hcd_td;
    }

    if (USB_EP_CNTRL == endpoint->type)
    {
        /* Setup TD for status phase */
        usb_hstd_ohci_insert_tail_list(&ohci_req->hcd_list, &td->request_list);
#if defined(BSP_CFG_CORE_CA55)
        td->endpoint     = (uint32_t) usb_hstd_ohci_physical_address_of(endpoint);
        td->usb_drequest = (uint32_t) usb_hstd_ohci_physical_address_of(ohci_req);
#else
        td->endpoint     = endpoint;
        td->usb_drequest = (struct usb_ohci_request *) ohci_req;
 #endif
        td->cancel_pending = FALSE;
        td->hc_td.cbp      = 0;
        td->hc_td.be       = 0;
        td->transfer_count = 0;

        if (USB_HCI_DIRECTION_IN == ohci_req->xferinfo)
        {
            td->hc_td.control.dp = USB_OHCI_PID_OUT;
        }
        else
        {
            td->hc_td.control.dp = USB_OHCI_PID_IN;
        }

        td->hc_td.control.toggle = 3;
        td->hc_td.control.r      = FALSE;
        td->hc_td.control.int_d  = 7;  /* Specify no interrupt */
        td->hc_td.control.cc     = USB_OHCI_CC_NOTACCESSED;
        tmp_next_hcd_td          = usb_hstd_ohci_allocate_transfer_descriptor();
#if defined(BSP_CFG_CORE_CA55)
        td->next_hcd_td = (uint32_t) usb_hstd_ohci_physical_address_of(tmp_next_hcd_td);
        tmp_next_hcd_td->physical_address = (uint32_t) usb_hstd_ohci_physical_address_of(&tmp_next_hcd_td->hc_td);
        td->hc_td.next_td                 = (uint32_t) usb_hstd_ohci_physical_address_of(&tmp_next_hcd_td->hc_td);
#else
        td->next_hcd_td                   = (struct usb_ohci_hcd_transfer_descriptor *) tmp_next_hcd_td;
        td->hc_td.next_td                 = (uint32_t)(uintptr_t) &tmp_next_hcd_td->hc_td;
        tmp_next_hcd_td->physical_address = td->hc_td.next_td;
 #endif

        list_td = td;

        td = tmp_next_hcd_td;
    }

    /* Setup interrupt delay */
    list_td->hc_td.control.int_d = usb_hstd_ohci_min_delay(6, ohci_req->max_int_delay) & 0x07U;

    /* Set new TailP in ED */
    #if defined(BSP_CFG_CORE_CA55)
    td->usb_drequest = USB_NULL;
    #else
    td->usb_drequest = USB_NULL;
    #endif
#if defined(BSP_CFG_CORE_CA55)
    endpoint->hcd_tail_p = (uint32_t) usb_hstd_ohci_physical_address_of(td);
#else
    endpoint->hcd_tail_p = (struct usb_ohci_hcd_transfer_descriptor *) td;
 #endif
    ed->hc_ed.tail_p = td->physical_address; /* Add null TD to the tail */
#if defined(BSP_CFG_CORE_CA55)
    __asm volatile("DMB SY");
#else
    __asm volatile ("dmb");
#endif

    switch (endpoint->type)
    {
        case USB_EP_CNTRL:
        {
            USB00->HCCOMMANDSTATUS = USB_OHCI_CONTROLLISTFILLED;
            break;
        }

        case USB_EP_BULK:
        {
            USB00->HCCOMMANDSTATUS = USB_OHCI_BULKLISTFILLED;
            break;
        }

        case USB_EP_INT:
        {
            break;
        }

        default:
        {
            return FALSE;
            break;
        }
    }

    return TRUE;
}

/***********************************************************************************************************************
 * Function     : OHCI Isochronous TD
 * Declaration  : uint32_t usb_hstd_ohci_queue_iso_request( st_usb_ohci_hcd_endpoint_p_t endpoint, st_usb_ohci_request_p_t ohci_req )
 * Argument     : st_usb_ohci_hcd_endpoint_p_t endpoint ; Endpoint Pointer
 *              ; st_usb_ohci_request_p_t ohci_req      ; Driver ohci_req Infomation pointer
 * Return       : uint32_t                         ; result( TRUE:Nomal End, FALSE:Fail )
 * Note         :
 ***********************************************************************************************************************/
static uint32_t usb_hstd_ohci_queue_iso_request (usb_utr_t                  * ptr,
                                                 st_usb_ohci_hcd_endpoint_p_t endpoint,
                                                 st_usb_ohci_request_p_t      ohci_req)
{
    if (USB_HCI_DIRECTION_IN == ohci_req->xferinfo)
    {
        return usb_hstd_ohci_queue_iso_request_in(ptr, endpoint, ohci_req);
    }

    return usb_hstd_ohci_queue_iso_request_out(ptr, endpoint, ohci_req);
}

/***********************************************************************************************************************
 * Function     : OHCI Isochronous TD for IN Transfer
 * Declaration  : uint32_t usb_hstd_ohci_queue_iso_request_in( st_usb_ohci_hcd_endpoint_p_t endpoint, st_usb_ohci_request_p_t ohci_req )
 * Argument     : st_usb_ohci_hcd_endpoint_p_t endpoint ; Endpoint Pointer
 *              ; st_usb_ohci_request_p_t ohci_req      ; Driver ohci_req Infomation pointer
 * Return       : uint32_t                         ; result( TRUE:Nomal End, FALSE:Fail )
 * Note         :
 ***********************************************************************************************************************/
static uint32_t usb_hstd_ohci_queue_iso_request_in (usb_utr_t                  * ptr,
                                                    st_usb_ohci_hcd_endpoint_p_t endpoint,
                                                    st_usb_ohci_request_p_t      ohci_req)
{
    st_usb_ohci_hcd_endpoint_descriptor_p_t ed;
    st_usb_ohci_hcd_transfer_descriptor_p_t td;
    uint32_t  remaining_length;
#if defined(BSP_CFG_CORE_CA55)
    uint32_t  p_current_buffer_pointer;
#else
    uint8_t * p_current_buffer_pointer;
#endif
    uint32_t  buffer_pointer_tmp;
    st_usb_ohci_iso_transfer_info_p_t          iso_tr_info;
    st_usb_ohci_hc_iso_transfer_descriptor_p_t hc_iso_td;
    st_usb_ohci_hcd_transfer_descriptor_p_t    last_valid_iso_td;
    st_usb_ohci_hc_iso_transfer_descriptor_p_t last_iso_hctd;
    st_usb_ohci_hcd_transfer_descriptor_p_t    tmp_next_hcd_td_2;
    st_usb_ohci_hcd_transfer_descriptor_p_t    tmp_td_next_hcd_td;
#if defined(BSP_CFG_CORE_CA55)
    st_usb_ohci_iso_info_p_t                      temp;
#endif

 #if defined(BSP_CFG_CORE_CA55)
    ed = (st_usb_ohci_hcd_endpoint_descriptor_p_t) (r_usb_pa_to_va((uint64_t) endpoint->hcd_ed));
 #else
    ed = (st_usb_ohci_hcd_endpoint_descriptor_p_t)(uintptr_t) endpoint->hcd_ed;
 #endif

    if (NULL == ed)
    {
        return FALSE;
    }

    if (USB_OHCI_ED_EOF == ed->list_index)
    {

        /* Endpoint has been removed from schedule */
        return FALSE;
    }

#if defined(BSP_CFG_CORE_CA55)
    temp = (st_usb_ohci_iso_info_p_t)&endpoint->iso_info;
    if (0 == temp->usb_drequest)
    {
        /* The relations between Endpoint and usb_drequest are linked here */
        temp->usb_drequest = (uint32_t)(uintptr_t) ohci_req;
    }
#else
    if (NULL == endpoint->iso_info->usb_drequest)
    {
        /* The relations between Endpoint and usb_drequest are linked here */
        endpoint->iso_info->usb_drequest = ohci_req;
    }
#endif
    else
    {

        /* Error when new transfer request comes */
        return FALSE;
    }

#if defined(BSP_CFG_CORE_CA55)
    if (0 != temp->end_cnt)
#else
    if (0 != endpoint->iso_info->end_cnt)
#endif    

    {
        usb_hstd_ohci_complete_transfer_request_iso(ptr, endpoint);

        return TRUE;
    }

 #if defined(BSP_CFG_CORE_CA55)
    td = (st_usb_ohci_hcd_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) endpoint->hcd_tail_p)); /* hcd_head_p => hcd_tail_p */
 #else
    td = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) endpoint->hcd_tail_p;                            /* hcd_head_p => hcd_tail_p */
 #endif
    if (NULL == td)
    {
        return FALSE;
    }

    ohci_req->status        = USB_OHCI_RS_NOT_DONE;
    ohci_req->buffer_length = 0;       /* report back bytes transferred so far */
#if defined(BSP_CFG_CORE_CA55)
    remaining_length = (USB_OHCI_ISO_MAX_FRAME - (temp->start_cnt + temp->end_cnt)) * endpoint->max_packet;
#else    
    remaining_length        =
        ((uint32_t) ((uint8_t) USB_OHCI_ISO_MAX_FRAME - (endpoint->iso_info->start_cnt + endpoint->iso_info->end_cnt)) *
         endpoint->max_packet);
#endif
    usb_hstd_ohci_initialize_list_head(&ohci_req->hcd_list);

    /* Setup TD(s) for data packets */
    while (0 != remaining_length)
    {
        usb_hstd_ohci_insert_tail_list(&ohci_req->hcd_list, &td->request_list);
#if defined(BSP_CFG_CORE_CA55)
        td->usb_drequest = USB_NULL;
        td->endpoint     = (uint32_t) usb_hstd_ohci_physical_address_of(endpoint);
        hc_iso_td        = (st_usb_ohci_hc_iso_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) &td->hc_td));
#else
        td->usb_drequest = NULL;
        td->endpoint = endpoint;
        hc_iso_td    = (st_usb_ohci_hc_iso_transfer_descriptor_p_t) &td->hc_td;
 #endif
        td->cancel_pending = FALSE;

#if defined(BSP_CFG_CORE_CA55)
        iso_tr_info             = &temp->transfer_info[temp->start_p];
#else        
        iso_tr_info             = &endpoint->iso_info->transfer_info[endpoint->iso_info->start_p];
#endif
        iso_tr_info->size       = 0;
        iso_tr_info->control_cc = 0;
        iso_tr_info->psw_cc     = 0;

#if defined(BSP_CFG_CORE_CA55)
        p_current_buffer_pointer = (uint32_t) (r_usb_pa_to_va((uint64_t) &iso_tr_info->buffer));
        temp->start_cnt++;
        temp->start_p++;
        temp->start_p &= USB_OHCI_ISO_MAX_FRAME - 1;
 #else
        p_current_buffer_pointer = &iso_tr_info->buffer[0];
        endpoint->iso_info->start_cnt++;
        endpoint->iso_info->start_p++;
        endpoint->iso_info->start_p &= USB_OHCI_ISO_MAX_FRAME - 1;
#endif

#if defined(BSP_CFG_CORE_CA55)
        hc_iso_td->bp0 = (uint32_t) usb_hstd_ohci_physical_address_of((void *)(uint64_t)p_current_buffer_pointer);
        if (remaining_length > endpoint->max_packet)
        {
            hc_iso_td->be = (uint32_t) usb_hstd_ohci_physical_address_of(
                (void *)(uint64_t)(p_current_buffer_pointer + endpoint->max_packet - 1));
        }
        else
        {
            hc_iso_td->be =
                (uint32_t) usb_hstd_ohci_physical_address_of((void *)(uint64_t)(p_current_buffer_pointer + remaining_length - 1));
        }
        buffer_pointer_tmp = p_current_buffer_pointer & USB_VAL_X0FFF;
 #else
        hc_iso_td->bp0 = (uint32_t) p_current_buffer_pointer;
        if (remaining_length > endpoint->max_packet)
        {
            hc_iso_td->be = (uint32_t) (p_current_buffer_pointer + endpoint->max_packet - 1);
        }
        else
        {
            hc_iso_td->be = (uint32_t) (p_current_buffer_pointer + remaining_length - 1);
        }
        buffer_pointer_tmp = (uint32_t) p_current_buffer_pointer & USB_VAL_X0FFF;
 #endif


#if defined(BSP_CFG_CORE_CA55)
        hc_iso_td->usb_ohci_offset_psw[gs_usb_hstd_ohci_offset_psw_table[USB_HCI_GET_ENDIAN][0]].offset.offset =
            ((uint16_t) usb_hstd_ohci_physical_address_of((void *) (uintptr_t) buffer_pointer_tmp)) & USB_VAL_X1FFF;
 #else
        hc_iso_td->usb_ohci_offset_psw[gs_usb_hstd_ohci_offset_psw_table[USB_HCI_GET_ENDIAN][0]].offset.offset =
            (uint16_t) (buffer_pointer_tmp & USB_VAL_X1FFF);
 #endif
        hc_iso_td->usb_ohci_offset_psw[gs_usb_hstd_ohci_offset_psw_table[USB_HCI_GET_ENDIAN][0]].offset.cc = 7;

        if (remaining_length > endpoint->max_packet)
        {
            td->transfer_count += endpoint->max_packet;
            remaining_length   -= endpoint->max_packet;
        }
        else
        {
            td->transfer_count += remaining_length;
            remaining_length    = 0;
        }

        hc_iso_td->control.int_d = 7;                                                           /* specify no interrupt */
        hc_iso_td->control.cc    = USB_OHCI_CC_NOTACCESSED;
        hc_iso_td->control.fc    = 0;
        hc_iso_td->control.int_d = usb_hstd_ohci_min_delay(6, ohci_req->max_int_delay) & 0x07U; /* Setup interrupt delay */

#if defined(BSP_CFG_CORE_CA55)
        last_valid_iso_td = (st_usb_ohci_hcd_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) endpoint->hcd_head_p));
 #else
        last_valid_iso_td = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) endpoint->hcd_head_p;
 #endif
        if (0 == last_valid_iso_td->next_hcd_td) /* Valid IsoTD is Empty */
        {
            hc_iso_td->control.sf = (uint16_t) (USB00->HCFMNUMBER + 2);
        }
        else
        {
#if defined(BSP_CFG_CORE_CA55)
            tmp_next_hcd_td_2 =
                (st_usb_ohci_hcd_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) last_valid_iso_td->next_hcd_td));
            while (0 != tmp_next_hcd_td_2->next_hcd_td)
            {
                last_valid_iso_td =
                    (st_usb_ohci_hcd_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) last_valid_iso_td->next_hcd_td));
                tmp_next_hcd_td_2 =
                    (st_usb_ohci_hcd_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) last_valid_iso_td->next_hcd_td));
            }

            last_iso_hctd =
                (st_usb_ohci_hc_iso_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) &last_valid_iso_td->hc_td));
            hc_iso_td->control.sf = (uint16_t) (last_iso_hctd->control.sf + last_iso_hctd->control.fc + 1);
 #else
            tmp_next_hcd_td_2 = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) last_valid_iso_td->next_hcd_td;
            while (0 != tmp_next_hcd_td_2->next_hcd_td)
            {
                last_valid_iso_td = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) last_valid_iso_td->next_hcd_td;
                tmp_next_hcd_td_2 = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) last_valid_iso_td->next_hcd_td;
            }

            last_iso_hctd         = (st_usb_ohci_hc_iso_transfer_descriptor_p_t) &last_valid_iso_td->hc_td;
            hc_iso_td->control.sf = (uint16_t) (last_iso_hctd->control.sf + last_iso_hctd->control.fc + 1);
 #endif
        }

#if defined(BSP_CFG_CORE_CA55)
        td->next_hcd_td    = (uint32_t) usb_hstd_ohci_physical_address_of(usb_hstd_ohci_allocate_transfer_descriptor());
        tmp_td_next_hcd_td = (st_usb_ohci_hcd_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) td->next_hcd_td));
        tmp_td_next_hcd_td->physical_address = (uint32_t) usb_hstd_ohci_physical_address_of(&tmp_td_next_hcd_td->hc_td);
        td->hc_td.next_td = tmp_td_next_hcd_td->physical_address;
        td                = (st_usb_ohci_hcd_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) td->next_hcd_td));
#else
        td->next_hcd_td    = (struct usb_ohci_hcd_transfer_descriptor *) usb_hstd_ohci_allocate_transfer_descriptor();
        tmp_td_next_hcd_td = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) td->next_hcd_td;
        td->hc_td.next_td  = (uint32_t)(uintptr_t) &tmp_td_next_hcd_td->hc_td;
        tmp_td_next_hcd_td->physical_address = td->hc_td.next_td;
        td = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) td->next_hcd_td;
 #endif
    }

    /* Set new TailP in ED */
#if defined(BSP_CFG_CORE_CA55)
    td->usb_drequest = USB_NULL;
    endpoint->hcd_tail_p = (uint32_t) usb_hstd_ohci_physical_address_of(td);
#else
    td->usb_drequest = NULL;
    endpoint->hcd_tail_p = (struct usb_ohci_hcd_transfer_descriptor *) td;
 #endif
    ed->hc_ed.tail_p = td->physical_address; /* Add null TD to the tail */

    return TRUE;
}

/***********************************************************************************************************************
 * Function     : OHCI Isochronous TD for OUT Transfer
 * Declaration  : uint32_t usb_hstd_ohci_queue_iso_request_out( st_usb_ohci_hcd_endpoint_p_t endpoint, st_usb_ohci_request_p_t ohci_req )
 * Argument     : st_usb_ohci_hcd_endpoint_p_t endpoint ; Endpoint Pointer
 *              ; st_usb_ohci_request_p_t ohci_req      ; Driver ohci_req Infomation pointer
 * Return       : uint32_t                         ; result( TRUE:Nomal End, FALSE:Fail )
 * Note         :
 ***********************************************************************************************************************/
static uint32_t usb_hstd_ohci_queue_iso_request_out (usb_utr_t                  * ptr,
                                                     st_usb_ohci_hcd_endpoint_p_t endpoint,
                                                     st_usb_ohci_request_p_t      ohci_req)
{
    st_usb_ohci_hcd_endpoint_descriptor_p_t ed;
    st_usb_ohci_hcd_transfer_descriptor_p_t td;
    uint32_t  remaining_count;
#if defined(BSP_CFG_CORE_CA55)
    uint32_t p_current_buffer_pointer;
#else
    uint8_t * p_current_buffer_pointer;
#endif
    uint32_t  buffer_pointer_tmp;
    uint32_t  total_size;
    st_usb_ohci_iso_transfer_info_p_t          iso_tr_info;
    st_usb_ohci_hc_iso_transfer_descriptor_p_t hc_iso_td;
    st_usb_ohci_hcd_transfer_descriptor_p_t    last_valid_iso_td;
    st_usb_ohci_hc_iso_transfer_descriptor_p_t last_iso_hctd;
    uint8_t * tmp_iso_tr_info_buffer;
#if defined(BSP_CFG_CORE_CA55)
    uint32_t  tmp_ohci_req_buffer;
#else
    uint8_t * tmp_ohci_req_buffer;
#endif
    st_usb_ohci_hcd_transfer_descriptor_p_t tmp_next_hcd_td_2;
    st_usb_ohci_hcd_transfer_descriptor_p_t tmp_td_next_hcd_td;
#if defined(BSP_CFG_CORE_CA55)
    st_usb_ohci_iso_info_p_t                      temp;
#endif

#if defined(BSP_CFG_CORE_CA55)
    ed = (st_usb_ohci_hcd_endpoint_descriptor_p_t) (r_usb_pa_to_va((uint64_t) endpoint->hcd_ed));
 #else
    ed = (st_usb_ohci_hcd_endpoint_descriptor_p_t)(uintptr_t) endpoint->hcd_ed;
 #endif

    if (NULL == ed)
    {
        return FALSE;
    }

    if (USB_OHCI_ED_EOF == ed->list_index)
    {

        /* endpoint has been removed from schedule */
        return FALSE;
    }

#if defined(BSP_CFG_CORE_CA55)
    temp = (st_usb_ohci_iso_info_p_t)(uintptr_t) endpoint->iso_info;
    if (USB_NULL == temp->usb_drequest)
    {
        /* The relations between Endpoint and usb_drequest are linked here */
        temp->usb_drequest = (uint32_t)(uintptr_t) ohci_req;
    }
#else
    if (NULL == endpoint->iso_info->usb_drequest)
    {
        /* The relations between Endpoint and usb_drequest are linked here */
        endpoint->iso_info->usb_drequest = ohci_req;
    }
#endif    
    else
    {

        /* Error when new transfer request comes */
        return FALSE;
    }

    /* Buffering */
    total_size = 0;
#if defined(BSP_CFG_CORE_CA55)
    while ((temp->copy_cnt < USB_OHCI_ISO_MAX_FRAME) && (0 != ohci_req->buffer_length))
    {
        iso_tr_info = &temp->transfer_info[temp->copy_p];
#else
    while ((endpoint->iso_info->copy_cnt < USB_OHCI_ISO_MAX_FRAME) && (0 != ohci_req->buffer_length))
    {
        iso_tr_info = &endpoint->iso_info->transfer_info[endpoint->iso_info->copy_p];

#endif        

        if (ohci_req->buffer_length > endpoint->max_packet)
        {
            iso_tr_info->size = (uint16_t) endpoint->max_packet;
        }
        else
        {
            iso_tr_info->size = (uint16_t) ohci_req->buffer_length;
        }

        iso_tr_info->control_cc = 0;
        iso_tr_info->psw_cc     = 0;

#if defined(BSP_CFG_CORE_CA55)
        tmp_iso_tr_info_buffer = (uint8_t *) (r_usb_pa_to_va((uint64_t) &iso_tr_info->buffer));
        tmp_ohci_req_buffer    = (uint32_t) (r_usb_pa_to_va((uint64_t) ohci_req->buffer));
        memcpy(tmp_iso_tr_info_buffer, (void const *)(uintptr_t) tmp_ohci_req_buffer, iso_tr_info->size);
 #else
        tmp_iso_tr_info_buffer = &iso_tr_info->buffer[0];
        tmp_ohci_req_buffer    = ohci_req->buffer;
        memcpy(tmp_iso_tr_info_buffer, tmp_ohci_req_buffer, iso_tr_info->size);
 #endif


        tmp_ohci_req_buffer += iso_tr_info->size;
 #if defined(BSP_CFG_CORE_CA55)
        ohci_req->buffer = (uint32_t) usb_hstd_ohci_physical_address_of((void *)(uint64_t)tmp_ohci_req_buffer);
 #else
        ohci_req->buffer = tmp_ohci_req_buffer;
 #endif
        ohci_req->buffer_length -= iso_tr_info->size;
        total_size              += iso_tr_info->size;

#if defined(BSP_CFG_CORE_CA55)
        temp->copy_cnt++;
        temp->copy_p++;
        temp->copy_p &= USB_OHCI_ISO_MAX_FRAME - 1;
#else
        endpoint->iso_info->copy_cnt++;
        endpoint->iso_info->copy_p++;
        endpoint->iso_info->copy_p &= USB_OHCI_ISO_MAX_FRAME - 1;

#endif        

    }

    /* The transfer request size buffering is completed */
    /* However, the transfer completion is notified when not having arrived at USB_OHCI_ISO_MAX_FRAME yet */
    /* As a result, the following forwarding is requested */
#if defined(BSP_CFG_CORE_CA55)
    if ((temp->copy_cnt < USB_OHCI_ISO_MAX_FRAME)
            && (0 == ohci_req->buffer_length)
            && (0 == temp->start_cnt))
#else
    if ((endpoint->iso_info->copy_cnt < USB_OHCI_ISO_MAX_FRAME) &&
        (0 == ohci_req->buffer_length) &&
        (0 == endpoint->iso_info->start_cnt))
#endif            
    {
        ohci_req->buffer_length = total_size;

        /* The relation between Endpoint and usb_drequest is released here */
#if defined(BSP_CFG_CORE_CA55)
        temp->usb_drequest = 0;
#else
        endpoint->iso_info->usb_drequest = NULL;
#endif        
        if (USB_OHCI_RS_CANCELING != ohci_req->status)
        {
            ohci_req->status = USB_OHCI_RS_NORMAL_COMPLETION;
        }
        else
        {
            ohci_req->status = USB_OHCI_RS_CANCELED;
        }

        usb_hstd_ohci_complete_transfer_request(ptr, ohci_req);

        return TRUE;
    }

#if defined(BSP_CFG_CORE_CA55)
    if (temp->end_cnt)
#else
    if (endpoint->iso_info->end_cnt)
#endif    
    {
        usb_hstd_ohci_complete_transfer_request_iso(ptr, endpoint);

        return TRUE;
    }

 #if defined(BSP_CFG_CORE_CA55)
    td = (st_usb_ohci_hcd_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) endpoint->hcd_tail_p)); /* hcd_head_p => hcd_tail_p */
 #else
    td = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) endpoint->hcd_tail_p;                            /* hcd_head_p => hcd_tail_p */
 #endif
    ohci_req->status = USB_OHCI_RS_NOT_DONE;
#if defined(BSP_CFG_CORE_CA55)
    remaining_count = USB_OHCI_ISO_MAX_FRAME - temp->start_cnt;
#else
    remaining_count  = USB_OHCI_ISO_MAX_FRAME - endpoint->iso_info->start_cnt;
#endif    
    usb_hstd_ohci_initialize_list_head(&ohci_req->hcd_list);

    /* Setup TD(s) for data packets */
    while (0 != remaining_count)
    {
        usb_hstd_ohci_insert_tail_list(&ohci_req->hcd_list, &td->request_list);
#if defined(BSP_CFG_CORE_CA55)
        td->usb_drequest = USB_NULL;
        td->endpoint     = (uint32_t) usb_hstd_ohci_physical_address_of(endpoint);        
#else
        td->usb_drequest = NULL;
        td->endpoint = endpoint;
 #endif
        td->cancel_pending = FALSE;

#if defined(BSP_CFG_CORE_CA55)
        hc_iso_td = (st_usb_ohci_hc_iso_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) &td->hc_td));
 #else
        hc_iso_td = (st_usb_ohci_hc_iso_transfer_descriptor_p_t) &td->hc_td;
 #endif

#if defined(BSP_CFG_CORE_CA55)
        iso_tr_info = &temp->transfer_info[temp->start_p];
        p_current_buffer_pointer = (uint32_t) (r_usb_pa_to_va((uint64_t) &iso_tr_info->buffer));
        temp->start_cnt++;
        temp->start_p++;
        temp->start_p &= USB_OHCI_ISO_MAX_FRAME - 1;
        hc_iso_td->bp0 = (uint32_t) usb_hstd_ohci_physical_address_of((void *)(uint64_t)p_current_buffer_pointer);
        hc_iso_td->be  = (uint32_t) usb_hstd_ohci_physical_address_of((void *)(uint64_t)(p_current_buffer_pointer + iso_tr_info->size - 1));
 #else
        iso_tr_info = &endpoint->iso_info->transfer_info[endpoint->iso_info->start_p];
        p_current_buffer_pointer = &iso_tr_info->buffer[0];
        endpoint->iso_info->start_cnt++;
        endpoint->iso_info->start_p++;
        endpoint->iso_info->start_p &= USB_OHCI_ISO_MAX_FRAME - 1;
        hc_iso_td->bp0 = (uint32_t) p_current_buffer_pointer;
        hc_iso_td->be  = (uint32_t) (p_current_buffer_pointer + iso_tr_info->size - 1);
 #endif

        buffer_pointer_tmp = (uint32_t) p_current_buffer_pointer & USB_VAL_X0FFF;
#if defined(BSP_CFG_CORE_CA55)
        hc_iso_td->usb_ohci_offset_psw[gs_usb_hstd_ohci_offset_psw_table[USB_HCI_GET_ENDIAN][0]].offset.offset =
            ((uint16_t) usb_hstd_ohci_physical_address_of((void *) (uintptr_t) buffer_pointer_tmp)) & USB_VAL_X1FFF;
 #else
        hc_iso_td->usb_ohci_offset_psw[gs_usb_hstd_ohci_offset_psw_table[USB_HCI_GET_ENDIAN][0]].offset.offset =
            (buffer_pointer_tmp & USB_VAL_X1FFF);
 #endif
        hc_iso_td->usb_ohci_offset_psw[gs_usb_hstd_ohci_offset_psw_table[USB_HCI_GET_ENDIAN][0]].offset.cc = 7;
        td->transfer_count += iso_tr_info->size;

#if defined(BSP_CFG_CORE_CA55)
        temp->copy_cnt--;
#else
        endpoint->iso_info->copy_cnt--;
#endif        
        remaining_count--;

        hc_iso_td->control.int_d = 7;                                                           /* specify no interrupt */
        hc_iso_td->control.cc    = USB_OHCI_CC_NOTACCESSED;
        hc_iso_td->control.fc    = 0;
        hc_iso_td->control.int_d = usb_hstd_ohci_min_delay(6, ohci_req->max_int_delay) & 0x07U; /* Setup interrupt delay */

#if defined(BSP_CFG_CORE_CA55)
        last_valid_iso_td = (st_usb_ohci_hcd_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) endpoint->hcd_head_p));
 #else
        last_valid_iso_td = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) endpoint->hcd_head_p;
 #endif
        if (0 == last_valid_iso_td->next_hcd_td) /* Valid IsoTD is Empty */
        {
            hc_iso_td->control.sf = (uint16_t) (USB00->HCFMNUMBER + 2);
        }
        else
        {
#if defined(BSP_CFG_CORE_CA55)
            tmp_next_hcd_td_2 =
                (st_usb_ohci_hcd_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) last_valid_iso_td->next_hcd_td));
            while (0 != tmp_next_hcd_td_2->next_hcd_td)
            {
                last_valid_iso_td =
                    (st_usb_ohci_hcd_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) last_valid_iso_td->next_hcd_td));
                tmp_next_hcd_td_2 =
                    (st_usb_ohci_hcd_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) last_valid_iso_td->next_hcd_td));
            }

            last_iso_hctd =
                (st_usb_ohci_hc_iso_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) &last_valid_iso_td->hc_td));
 #else
            tmp_next_hcd_td_2 = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) last_valid_iso_td->next_hcd_td;
            while (0 != tmp_next_hcd_td_2->next_hcd_td)
            {
                last_valid_iso_td = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) last_valid_iso_td->next_hcd_td;
                tmp_next_hcd_td_2 = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) last_valid_iso_td->next_hcd_td;
            }
            last_iso_hctd = (st_usb_ohci_hc_iso_transfer_descriptor_p_t) &last_valid_iso_td->hc_td;
 #endif
            hc_iso_td->control.sf = (uint16_t) (last_iso_hctd->control.sf + last_iso_hctd->control.fc + 1);
        }

#if defined(BSP_CFG_CORE_CA55)
        td->next_hcd_td    = (uint32_t) usb_hstd_ohci_physical_address_of(usb_hstd_ohci_allocate_transfer_descriptor());
        tmp_td_next_hcd_td = (st_usb_ohci_hcd_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) td->next_hcd_td));
        tmp_td_next_hcd_td->physical_address = (uint32_t) usb_hstd_ohci_physical_address_of(&tmp_td_next_hcd_td->hc_td);
        td->hc_td.next_td = tmp_td_next_hcd_td->physical_address;
        td                =
            (st_usb_ohci_hcd_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) td->next_hcd_td));
#else
        td->next_hcd_td    = (struct usb_ohci_hcd_transfer_descriptor *) usb_hstd_ohci_allocate_transfer_descriptor();
        tmp_td_next_hcd_td = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) td->next_hcd_td;
        td->hc_td.next_td  = (uint32_t)(uintptr_t) &tmp_td_next_hcd_td->hc_td;
        tmp_td_next_hcd_td->physical_address = td->hc_td.next_td;
        td = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) td->next_hcd_td;
 #endif
    }

    /* Set new TailP in ED */
    
#if defined(BSP_CFG_CORE_CA55)
    td->usb_drequest = USB_NULL;
    endpoint->hcd_tail_p = (uint32_t) usb_hstd_ohci_physical_address_of(td);
#else
    td->usb_drequest = NULL;
    endpoint->hcd_tail_p = (struct usb_ohci_hcd_transfer_descriptor *) td;
 #endif
    ed->hc_ed.tail_p = td->physical_address; /* Add null TD to the tail */

    return TRUE;
}

/***********************************************************************************************************************
 * Function     : OHCI Inserting ED to Endpoint structure.
 * Declaration  : void usb_hstd_ohci_insert_ed_for_endpoint( st_usb_ohci_hcd_endpoint_p_t endpoint )
 * Argument     : st_usb_ohci_hcd_endpoint_p_t endpoint ; Endpoint Pointer
 * Return       : uint32_t                         ; result( TRUE:Nomal End, FALSE:Fail )
 * Note         :
 ***********************************************************************************************************************/
static uint32_t usb_hstd_ohci_insert_ed_for_endpoint (st_usb_ohci_hcd_endpoint_p_t endpoint)
{
    st_usb_ohci_hcd_device_data_p_t         device_data;
    st_usb_ohci_hcd_ed_list_p_t             list;
    st_usb_ohci_hcd_endpoint_descriptor_p_t ed;
    st_usb_ohci_hcd_endpoint_descriptor_p_t tail_ed;
    st_usb_ohci_hcd_transfer_descriptor_p_t tmp_hcd_head_p;
    uint32_t * tmp_list_physical_head;

#if defined(BSP_CFG_CORE_CA55)
    device_data = (st_usb_ohci_hcd_device_data_p_t) (r_usb_pa_to_va((uint64_t) endpoint->device_data));
    list        =
        (st_usb_ohci_hcd_ed_list_p_t) (r_usb_pa_to_va((uint64_t) &device_data->ed_list[endpoint->list_index]));
#else
    device_data = endpoint->device_data;
    list        = &device_data->ed_list[endpoint->list_index];
 #endif

    /* Initialize an endpoint descriptor for this endpoint */
    ed = usb_hstd_ohci_allocate_endpoint_descriptor();
    if (NULL == ed)
    {
        return FALSE;
    }

#if defined(BSP_CFG_CORE_CA55)
    ed->endpoint         = (uint32_t) usb_hstd_ohci_physical_address_of(endpoint);
    ed->list_index       = endpoint->list_index;
    ed->physical_address = (uint32_t) usb_hstd_ohci_physical_address_of(&ed->hc_ed);
    ed->hc_ed.control    = endpoint->control;

    endpoint->hcd_head_p = (uint32_t) usb_hstd_ohci_physical_address_of(usb_hstd_ohci_allocate_transfer_descriptor()); /* Make Dummy TD */
#else
    ed->endpoint         = endpoint;
    ed->list_index       = endpoint->list_index;
    ed->physical_address = (uint32_t) &ed->hc_ed;
    ed->hc_ed.control    = endpoint->control;

    endpoint->hcd_head_p = (struct usb_ohci_hcd_transfer_descriptor *) usb_hstd_ohci_allocate_transfer_descriptor(); /* Make Dummy TD */
 #endif
#if defined(BSP_CFG_CORE_CA55)
    if (USB_NULL == endpoint->hcd_head_p)
#else
    if (NULL == endpoint->hcd_head_p)
#endif
    {
        usb_hstd_ohci_free_endpoint_descriptor(ed);

        return FALSE;
    }

    endpoint->hcd_tail_p = endpoint->hcd_head_p;
#if defined(BSP_CFG_CORE_CA55)
    tmp_hcd_head_p   = (st_usb_ohci_hcd_transfer_descriptor_p_t) (r_usb_pa_to_va((uint64_t) endpoint->hcd_head_p)); /* debug */
    ed->hc_ed.head_p = (uint32_t) usb_hstd_ohci_physical_address_of(&tmp_hcd_head_p->hc_td);
 #else
    tmp_hcd_head_p   = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) endpoint->hcd_head_p;                            /* debug */
    ed->hc_ed.head_p = (uint32_t)(uintptr_t) &tmp_hcd_head_p->hc_td;
 #endif

    ed->hc_ed.tail_p                 = ed->hc_ed.head_p;
    tmp_hcd_head_p->physical_address = ed->hc_ed.tail_p;
#if defined(BSP_CFG_CORE_CA55)
    endpoint->hcd_ed             = (uint32_t) usb_hstd_ohci_physical_address_of(ed);
    tmp_hcd_head_p->usb_drequest = 0;
#else
    endpoint->hcd_ed = (struct usb_ohci_hcd_endpoint_descriptor *) ed;
    tmp_hcd_head_p->usb_drequest = NULL;
 #endif

    /* Link endpoint descriptor into HCD tracking queue */
    if ((USB_EP_ISO != endpoint->type) || (TRUE == usb_hstd_ohci_is_list_empty(&list->head)))
    {
        /* Control/Bulk/Interrupt(any case) , Iso(List is empty) */

        /* Link ED into head of ED list */
        usb_hstd_ohci_insert_head_list(&list->head, &ed->link);
#if defined(BSP_CFG_CORE_CA55)
        tmp_list_physical_head = (uint32_t *) (r_usb_pa_to_va((uint64_t) list->physical_head));
#else
        tmp_list_physical_head = list->physical_head;
 #endif
        ed->hc_ed.next_ed       = *tmp_list_physical_head;
        *tmp_list_physical_head = ed->physical_address;
    }
    else
    {
        /* Iso type ( List is not empty) */

        /* Link ED into tail of ED list */
#if defined(BSP_CFG_CORE_CA55)
        tail_ed =
            (st_usb_ohci_hcd_endpoint_descriptor_p_t) (uintptr_t) usb_hstd_ohci_scan_containing_record((
                                                                                                           st_usb_ohci_list_entry_p_t) (
                                                                                                           r_usb_pa_to_va((
                                                                                                                              uint64_t)
                                                                                                                          list
                                                                                                                          ->
                                                                                                                          head
                                                                                                                          .
                                                                                                                          b_link)),
                                                                                           USB_OHCI_CR_ENDPOINT_DESCRIPTOR,
                                                                                           USB_OHCI_CR_LINK);
 #else
        tail_ed =
            (st_usb_ohci_hcd_endpoint_descriptor_p_t)(uintptr_t) usb_hstd_ohci_scan_containing_record(
                (st_usb_ohci_list_entry_p_t)(uintptr_t) list->head.b_link,
                USB_OHCI_CR_ENDPOINT_DESCRIPTOR,
                USB_OHCI_CR_LINK);
 #endif

        usb_hstd_ohci_insert_tail_list(&list->head, &ed->link);
        ed->hc_ed.next_ed      = 0;
        tail_ed->hc_ed.next_ed = ed->physical_address;
    }

    return TRUE;
}

/***********************************************************************************************************************
 * Function     : OHCI Complete Transfer Request for Isochronous
 * Declaration  : void usb_hstd_ohci_complete_transfer_request_iso( st_usb_ohci_hcd_endpoint_p_t endpoint )
 * Argument     : st_usb_ohci_hcd_endpoint_p_t endpoint ; Endpoint Pointer
 * Return       : void
 * Note         :
 ***********************************************************************************************************************/
static void usb_hstd_ohci_complete_transfer_request_iso (usb_utr_t * ptr, st_usb_ohci_hcd_endpoint_p_t endpoint)
{
    st_usb_ohci_iso_transfer_info_p_t iso_tr_info;
    st_usb_ohci_request_p_t           ohci_req;
    uint32_t  err;
    uint8_t * tmp_iso_tr_info_buffer;
    uint8_t * tmp_ohci_req_buffer;
#if defined(BSP_CFG_CORE_CA55)
    st_usb_ohci_iso_info_p_t          temp;
#endif    

#if defined(BSP_CFG_CORE_CA55)
    temp = (st_usb_ohci_iso_info_p_t)&endpoint->iso_info;
    ohci_req    = (st_usb_ohci_request_p_t) (r_usb_pa_to_va((uint64_t) temp->usb_drequest));
    iso_tr_info = &temp->transfer_info[temp->complete_p];
    temp->complete_p++;
    temp->complete_p &= USB_OHCI_ISO_MAX_FRAME - 1;
 #else
    ohci_req = endpoint->iso_info->usb_drequest;
    iso_tr_info = &endpoint->iso_info->transfer_info[endpoint->iso_info->complete_p];
    endpoint->iso_info->complete_p++;
    endpoint->iso_info->complete_p &= USB_OHCI_ISO_MAX_FRAME - 1;
#endif    
    if (USB_HCI_DIRECTION_IN == ohci_req->xferinfo)
    {
#if defined(BSP_CFG_CORE_CA55)
        tmp_iso_tr_info_buffer = (uint8_t *) (r_usb_pa_to_va((uint64_t) iso_tr_info->buffer));
        tmp_ohci_req_buffer    = (uint8_t *) (r_usb_pa_to_va((uint64_t) ohci_req->buffer));
#else
        tmp_iso_tr_info_buffer = iso_tr_info->buffer;
        tmp_ohci_req_buffer    = ohci_req->buffer;
 #endif
        memcpy(tmp_ohci_req_buffer, tmp_iso_tr_info_buffer, iso_tr_info->size);
    }

    ohci_req->buffer_length += iso_tr_info->size;
#if defined(BSP_CFG_CORE_CA55)
    temp->end_cnt--; //RZA3
#else
    endpoint->iso_info->end_cnt--;
#endif    

    /* Check Transfer Request End */
    err = usb_hstd_ohci_check_transfer_request_end(ohci_req, endpoint->max_packet, iso_tr_info->size);
    if (TRUE == err)
    {
        /* The relation between Endpoint and usb_drequest is released here */
#if defined(BSP_CFG_CORE_CA55)
        temp->usb_drequest = 0;
#else
        endpoint->iso_info->usb_drequest = NULL;
#endif 
        if (USB_OHCI_RS_CANCELING != ohci_req->status)
        {
            if (USB_OHCI_CC_NOERROR == iso_tr_info->control_cc)
            {
                ohci_req->status = USB_OHCI_RS_NORMAL_COMPLETION;
            }
            else
            {
                ohci_req->status = gs_usb_hstd_ohci_cc_table[iso_tr_info->control_cc];
            }
        }
        else
        {
            ohci_req->status = USB_OHCI_RS_CANCELED;
        }

        usb_hstd_ohci_complete_transfer_request(ptr, ohci_req);
    }
}

/***********************************************************************************************************************
 * Function     : OHCI Open periodic pipe
 * Declaration  : uint32_t usb_hstd_ohci_open_periodic_pipe( st_usb_ohci_hcd_endpoint_p_t endpoint )
 * Argument     : st_usb_ohci_hcd_endpoint_p_t endpoint ; Endpoint Pointer
 * Return       : uint32_t                         ; result( TRUE:Nomal End, FALSE:Fail )
 * Note         :
 ***********************************************************************************************************************/
static uint32_t usb_hstd_ohci_open_periodic_pipe (st_usb_ohci_hcd_endpoint_p_t endpoint)
{
    uint32_t which_list;
    uint32_t junk;
    st_usb_ohci_hcd_device_data_p_t device_data;
#if defined(BSP_CFG_CORE_CA55)
    device_data = (st_usb_ohci_hcd_device_data_p_t) (r_usb_pa_to_va((uint64_t) endpoint->device_data));
#else
    device_data = endpoint->device_data;
 #endif

    /* Determine the scheduling period  */
    which_list = USB_OHCI_ED_INTERRUPT_32ms;
    while ((which_list >= endpoint->rate) && (which_list >>= 1))
    {
// continue;
    }

    /* Commit this endpoints bandwidth to the proper scheduling slot */
    if (USB_OHCI_ED_ISOCHRONOUS == which_list)
    {
        device_data->ed_list[USB_OHCI_ED_ISOCHRONOUS].bandwidth =
            (uint16_t) (device_data->ed_list[USB_OHCI_ED_ISOCHRONOUS].bandwidth + endpoint->bandwidth);
        device_data->max_bandwidth_inuse += endpoint->bandwidth;
    }
    else
    {
        /* Determine which scheduling list has the least bandwidth */
        usb_hstd_ohci_check_bandwidth(device_data, which_list, &which_list);
        device_data->ed_list[which_list].bandwidth =
            (uint16_t) (device_data->ed_list[which_list].bandwidth + endpoint->bandwidth);

        /* Recalculate the max bandwidth which is in use */
        /* This allows 1ms (isoc) pipe opens to occur with few calculation */
        device_data->max_bandwidth_inuse =
            usb_hstd_ohci_check_bandwidth(device_data, USB_OHCI_ED_INTERRUPT_32ms, &junk);
    }

    /* Verify the new max has not overcomitted the USB */
    if (device_data->max_bandwidth_inuse > device_data->available_bandwidth)
    {
        /* Too much, back this bandwidth out and fail the request */

        device_data->ed_list[which_list].bandwidth =
            (uint16_t) (device_data->ed_list[which_list].bandwidth - endpoint->bandwidth);
        device_data->max_bandwidth_inuse =
            usb_hstd_ohci_check_bandwidth(device_data, USB_OHCI_ED_INTERRUPT_32ms, &junk);

        return FALSE;
    }

    /* Assign endpoint to list and open pipe */
    endpoint->list_index = (uint8_t) which_list;

    return TRUE;
}

/***********************************************************************************************************************
 * Function     : OHCI Initialize Endpoint
 * Declaration  : st_usb_ohci_hcd_endpoint_p_t usb_hstd_ohci_initialize_endpoint(
 *              : st_usb_ohci_hcd_device_data_p_t device_data,
 *              : uint8_t endpoint_type,
 *              : uint16_t max_packet_size,
 *              : uint8_t device_address,
 *              : uint8_t endpoint_number,
 *              : uint8_t speed,
 *              : uint8_t direction,
 *              : uint32_t pollrate )
 * Argument     : st_usb_ohci_hcd_device_data_p_t device_data ; Device Data pointer
 *              : uint8_t endpoint_type                  ; endpoint type
 *              : uint16_t max_packet_size               ; Max Packet Size
 *              : uint8_t device_address                 ; devide address
 *              : uint8_t endpoint_number                ; endpoint no
 *              : uint8_t speed                          ; device speed
 *              : uint8_t direction                      ; direction
 *              : uint32_t pollrate                      ; polling rate
 * Return       : st_usb_ohci_hcd_endpoint_p_t endpoint       ; endpoint pointer
 * Note         :
 ***********************************************************************************************************************/
static st_usb_ohci_hcd_endpoint_p_t usb_hstd_ohci_initialize_endpoint (st_usb_ohci_hcd_device_data_p_t device_data,
                                                                       uint8_t                         endpoint_type,
                                                                       uint16_t                        max_packet_size,
                                                                       uint8_t                         device_address,
                                                                       uint8_t                         endpoint_number,
                                                                       uint8_t                         speed,
                                                                       uint8_t                         direction,
                                                                       uint32_t                        pollrate)
{
    st_usb_ohci_hcd_endpoint_p_t endpoint;
    uint32_t ret;

    /* Create EndPoint */
    endpoint = usb_hstd_ohci_alloc_endpoint();
    if (NULL == endpoint)
    {
        return NULL;
    }

    ret = usb_hstd_ohci_setup_endpoint(device_data,
                                       endpoint,
                                       endpoint_type,
                                       max_packet_size,
                                       device_address,
                                       endpoint_number,
                                       speed,
                                       direction,
                                       pollrate);

    if (FALSE == ret)
    {
        usb_hstd_ohci_free_endpoint(endpoint);

        return NULL;
    }

    if ((USB_EP_INT == endpoint->type) || (USB_EP_ISO == endpoint->type))
    {
        ret = usb_hstd_ohci_open_periodic_pipe(endpoint);
        if (FALSE == ret)
        {
            return NULL;
        }
    }

    /* Add to Host Controller schedule processing */
    ret = usb_hstd_ohci_insert_ed_for_endpoint(endpoint);
    if (TRUE == ret)
    {
        usb_hstd_ohci_store_endpoint(device_address, endpoint_number, direction, endpoint);
    }
    else
    {
        return NULL;
    }

    return endpoint;
}

/***********************************************************************************************************************
 * Function     : OHCI Setup Endpoint Memory
 * Declaration  : st_usb_ohci_hcd_endpoint_p_t usb_hstd_ohci_setup_endpoint(
 *              :   st_usb_ohci_hcd_device_data_p_t device_data,
 *              :   st_usb_ohci_hcd_endpoint_p_t endpoint,
 *              :   uint8_t endpoint_type,
 *              :   uint16_t mps,
 *              :   uint8_t devaddr,
 *              :   uint8_t epnum,
 *              :   uint8_t speed,
 *              :   uint8_t direction,
 *              :   uint32_t pollrate )
 * Argument     : st_usb_ohci_hcd_device_data_p_t device_data ; Device Data pointer
 *              : st_usb_ohci_hcd_endpoint_p_t endpoint       ; endpoint pointer
 *              : uint8_t endpoint_type                  ; endpoint type
 *              : uint16_t mps                           ; Max Packet Size
 *              : uint8_t devaddr                        ; devide address
 *              : uint8_t epnum                          ; endpoint no
 *              : uint8_t speed                          ; device speed
 *              : uint8_t direction                      ; direction
 *              : uint32_t pollrate                      ; polling rate
 * Return       : uint32_t                               ; status
 * Note         :
 ***********************************************************************************************************************/
static uint32_t usb_hstd_ohci_setup_endpoint (st_usb_ohci_hcd_device_data_p_t device_data,
                                              st_usb_ohci_hcd_endpoint_p_t    endpoint,
                                              uint8_t                         endpoint_type,
                                              uint16_t                        mps,
                                              uint8_t                         devaddr,
                                              uint8_t                         epnum,
                                              uint8_t                         speed,
                                              uint8_t                         direction,
                                              uint32_t                        pollrate)
{
    uint8_t endpoint_descriptor_type;
#if defined(BSP_CFG_CORE_CA55)
    endpoint->device_data = (uint32_t) usb_hstd_ohci_physical_address_of((void *) device_data);
#else
    endpoint->device_data = device_data;
 #endif

    switch (endpoint_type)
    {
        case USB_EP_CNTRL:
        {
            endpoint_descriptor_type = USB_OHCI_ED_CONTROL;
            endpoint->type           = endpoint_type;
            break;
        }

        case USB_EP_BULK:
        {
            endpoint_descriptor_type = USB_OHCI_ED_BULK;
            endpoint->type           = endpoint_type;
            break;
        }

        case USB_EP_ISO:
        {
            endpoint_descriptor_type = USB_OHCI_ED_ISOCHRONOUS;
            endpoint->type           = endpoint_type;
#if defined(BSP_CFG_CORE_CA55)
            endpoint->iso_info       = (uint32_t)(uintptr_t) usb_hstd_ohci_alloc_endpoint_iso();
            if (USB_NULL == endpoint->iso_info)
            {
                return FALSE;
            }
#else
            endpoint->iso_info       = usb_hstd_ohci_alloc_endpoint_iso();
            if (NULL == endpoint->iso_info)
            {
                return FALSE;
            }
#endif            

            break;
        }

        case USB_EP_INT:
        {
            endpoint->type = USB_EP_INT;
            if (pollrate < (2 * 8))
            {
                endpoint_descriptor_type = USB_OHCI_ED_INTERRUPT_1ms;
                endpoint->rate           = 1;
            }
            else if (pollrate < (4 * 8))
            {
                endpoint_descriptor_type = USB_OHCI_ED_INTERRUPT_2ms;
                endpoint->rate           = 2;
            }
            else if (pollrate < (8 * 8))
            {
                endpoint_descriptor_type = USB_OHCI_ED_INTERRUPT_4ms;
                endpoint->rate           = 4;
            }
            else if (pollrate < (16 * 8))
            {
                endpoint_descriptor_type = USB_OHCI_ED_INTERRUPT_8ms;
                endpoint->rate           = 8;
            }
            else if (pollrate < (USB_VAL_32 * 8))
            {
                endpoint_descriptor_type = USB_OHCI_ED_INTERRUPT_16ms;
                endpoint->rate           = 16;
            }
            else
            {
                endpoint_descriptor_type = USB_OHCI_ED_INTERRUPT_32ms;
                endpoint->rate           = USB_VAL_32;
            }

            break;
        }

        default:

            return FALSE;
    }

    endpoint->list_index  = endpoint_descriptor_type;
    endpoint->max_packet  = mps;
    endpoint->control.mps = mps;
    endpoint->control.fa  = devaddr & USB_VAL_7FU8;
    endpoint->control.en  = epnum & 0x0FU;
    endpoint->control.s   = speed & 0x01U;

    if (USB_EP_ISO == endpoint_type)
    {
        endpoint->control.d = (uint32_t) (direction + 1) & 0x00000003U;
        endpoint->control.f = 1;
    }
    else
    {
        endpoint->bandwidth = mps;
    }

    return TRUE;
}

/***********************************************************************************************************************
 * Function     : OHCI Return VirtualAddress
 * Declaration  : st_usb_ohci_list_entry_p_t usb_hstd_ohci_virtual_address_of( uint32_t data )
 * Argument     : uint32_t data         ; address
 * Return       : st_usb_ohci_list_entry_p_t ; Virtual Address
 * Note         :
 ***********************************************************************************************************************/
static st_usb_ohci_list_entry_p_t usb_hstd_ohci_virtual_address_of (uint32_t data)
{
    return (st_usb_ohci_list_entry_p_t)(uintptr_t) (data - 20);
}

/***********************************************************************************************************************
 * Function     : OHCI Judge minimum value
 * Declaration  : uint8_t usb_hstd_ohci_min_delay( uint8_t delay1, uint8_t delay2 )
 * Argument     : uint8_t delay1 ; value1
 *              : uint8_t delay2 ; value2
 * Return       : uint8_t        ; Minimum value
 * Note         :
 ***********************************************************************************************************************/
static uint8_t usb_hstd_ohci_min_delay (uint8_t delay1, uint8_t delay2)
{
    if (delay1 <= delay2)
    {
        return delay1;
    }

    return delay2;
}

/***********************************************************************************************************************
 * Function     : OHCI Check Transfer Request End
 * Declaration  : uint32_t usb_hstd_ohci_check_transfer_request_end( st_usb_ohci_request_p_t ohci_req, uint32_t mps, uint16_t size )
 * Argument     : st_usb_ohci_request_p_t ohci_req ; OHCI transfer request pointer
 *              : uint32_t mps                ; max packet size
 *              : uint16_t size               ; transfer size
 * Return       : uint32_t                    ; check flag( TRUE:End, FALSE:Not End )
 * Note         :
 ***********************************************************************************************************************/
static uint32_t usb_hstd_ohci_check_transfer_request_end (st_usb_ohci_request_p_t ohci_req, uint32_t mps, uint16_t size)
{
    st_usb_hci_tr_req_t * p_tr_req;

    if (FALSE == ohci_req->using_flag)
    {
        return FALSE;
    }

#if defined(BSP_CFG_CORE_CA55)
    p_tr_req = (st_usb_hci_tr_req_t *) (r_usb_pa_to_va((uint64_t) ohci_req->driver_request));
 #else
    p_tr_req = (st_usb_hci_tr_req_t *)(uintptr_t) ohci_req->driver_request;
 #endif

    /* check short packet */
    if (mps > size)
    {
        return TRUE;
    }

    /* check transfer request size */
    if (p_tr_req->trsize <= (p_tr_req->actual_size + size))
    {
        return TRUE;
    }

    return FALSE;
}

/***********************************************************************************************************************
 * Function     : OHCI Cancel Transfer Request
 * Declaration  : uint32_t usb_hstd_ohci_cancel_request( st_usb_ohci_request_p_t ohci_req )
 * Argument     : st_usb_ohci_request_p_t ohci_req      ; Driver ohci_req Infomation pointer
 * Return       : uint32_t                         ; result( TRUE:Nomal End, FALSE:Fail )
 * Note         :
 ***********************************************************************************************************************/
static uint32_t usb_hstd_ohci_cancel_request (usb_utr_t * ptr, st_usb_ohci_request_p_t ohci_req)
{
    st_usb_ohci_hcd_transfer_descriptor_p_t td;
    st_usb_ohci_hcd_endpoint_p_t            endpoint;
    st_usb_ohci_list_entry_p_t              tmp_request_list;
    st_usb_ohci_list_entry_p_t              tmp_b_link;

    /* If request status is 'not done' set status to 'canceling' */
    if (USB_OHCI_RS_NOT_DONE != ohci_req->status)
    {
        return FALSE;                  /* cannot cancel a completed request */
    }

    ohci_req->status = USB_OHCI_RS_CANCELING;

#if defined(BSP_CFG_CORE_CA55)
    td =
        (st_usb_ohci_hcd_transfer_descriptor_p_t) (uintptr_t) usb_hstd_ohci_scan_containing_record((
                                                                                                       st_usb_ohci_list_entry_p_t) (
                                                                                                       r_usb_pa_to_va((
                                                                                                                          uint64_t)
                                                                                                                      ohci_req
                                                                                                                      ->
                                                                                                                      hcd_list
                                                                                                                      .
                                                                                                                      f_link)),
                                                                                        USB_OHCI_CR_TRANSFER_DESCRIPTOR,
                                                                                        USB_OHCI_CR_REQUESTLIST);
 #else
    td = (st_usb_ohci_hcd_transfer_descriptor_p_t)(uintptr_t) usb_hstd_ohci_scan_containing_record(
        (st_usb_ohci_list_entry_p_t)(uintptr_t) ohci_req->hcd_list.f_link,
        USB_OHCI_CR_TRANSFER_DESCRIPTOR,
        USB_OHCI_CR_REQUESTLIST);
 #endif

    if (NULL == td)
    {
        return TRUE;
    }

    while (1)
    {
#if defined(BSP_CFG_CORE_CA55)
        tmp_request_list = (st_usb_ohci_list_entry_p_t) (r_usb_pa_to_va((uint64_t) &td->request_list));
        tmp_b_link       = (st_usb_ohci_list_entry_p_t) (r_usb_pa_to_va((uint64_t) ohci_req->hcd_list.b_link));
 #else
        tmp_request_list = (st_usb_ohci_list_entry_p_t)(uintptr_t) &td->request_list;
        tmp_b_link       = (st_usb_ohci_list_entry_p_t)(uintptr_t) ohci_req->hcd_list.b_link;
 #endif

        td->cancel_pending = TRUE;
        if (tmp_request_list == tmp_b_link)
        {
            break;
        }

#if defined(BSP_CFG_CORE_CA55)
        td =
            (st_usb_ohci_hcd_transfer_descriptor_p_t) (uintptr_t) usb_hstd_ohci_scan_containing_record((
                                                                                                           st_usb_ohci_list_entry_p_t) (
                                                                                                           r_usb_pa_to_va((
                                                                                                                              uint64_t)
                                                                                                                          td
                                                                                                                          ->
                                                                                                                          request_list
                                                                                                                          .
                                                                                                                          f_link)),
                                                                                            USB_OHCI_CR_TRANSFER_DESCRIPTOR,
                                                                                            USB_OHCI_CR_REQUESTLIST);
#else
        td = (st_usb_ohci_hcd_transfer_descriptor_p_t) usb_hstd_ohci_scan_containing_record(td->request_list.f_link,
                                                                                            USB_OHCI_CR_TRANSFER_DESCRIPTOR,
                                                                                            USB_OHCI_CR_REQUESTLIST);
 #endif
        if (NULL == td)
        {
            return TRUE;
        }
    }
#if defined(BSP_CFG_CORE_CA55)
    endpoint = (st_usb_ohci_hcd_endpoint_p_t)(uintptr_t)td->endpoint;
#else
    endpoint = td->endpoint;
#endif
    usb_hstd_ohci_pause_ed(ptr, endpoint); /* stop endpoint, schedule cleanup (see Section 5.2.7.1.3) */

    return TRUE;
}

#endif                                 /* USB_IP_EHCI_OHCI == 1 */

/***********************************************************************************************************************
 * End Of File
 ***********************************************************************************************************************/
