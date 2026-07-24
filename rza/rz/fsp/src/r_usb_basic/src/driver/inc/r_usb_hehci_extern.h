/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * File Name    : r_usb_hEhciExtern.c
 * Description  : EHCI Extern Header
 ***********************************************************************************************************************/

/**********************************************************************************************************************
 * History : DD.MM.YYYY Version Description
 *         : 31.08.2015 1.00    First Release
 ***********************************************************************************************************************/

#ifndef R_USB_HEHCIEXTERN_H
#define R_USB_HEHCIEXTERN_H

/*======================================================================== */
/*                      Prototypes                                         */
/*======================================================================== */
/* function */
/* r_usb_hEhciMain.c */
uint32_t usb_hstd_ehci_init(usb_utr_t * ptr);
void     usb_hstd_ehci_deinit(usb_utr_t * ptr);

uint32_t usb_hstd_ehci_port_reset(usb_utr_t * ptr);
void     usb_hstd_ehci_disconnect(usb_utr_t * ptr, uint32_t devadd);
uint32_t usb_hstd_ehci_get_frame_list_size(usb_utr_t * ptr);
void     usb_hstd_ehci_wait_micro_frame(usb_utr_t * ptr, uint32_t uframe_no);
void     usb_hstd_ehci_add_async(usb_utr_t * ptr, st_usb_ehci_qh_t * qh);
void     usb_hstd_ehci_add_periodic(usb_utr_t         * ptr,
                                    u_usb_ehci_flep_t * new_element,
                                    uint32_t            type,
                                    uint32_t            pollrate,
                                    uint32_t            pollrate_offset);
void     usb_hstd_ehci_link_qtd(st_usb_ehci_qtd_t * qtd1st, st_usb_ehci_qtd_t * qtd2nd);
void     usb_hstd_ehci_clear_qtd(st_usb_ehci_qtd_t * qtd_head);
void     usb_hstd_ehci_inactive_qtd(st_usb_ehci_qtd_t * qtd_head);
void     usb_hstd_ehci_unlink_qh_for_async(usb_utr_t * ptr, st_usb_ehci_qh_t * qh);
void     usb_hstd_ehci_unlink_qh_for_periodic(usb_utr_t * ptr, st_usb_ehci_qh_t * qh);
void     usb_hstd_ehci_unlink_itd(usb_utr_t * ptr, st_usb_ehci_itd_t * itd);
void     usb_hstd_ehci_unlink_sitd(usb_utr_t * ptr, st_usb_ehci_sitd_t * sitd);
uint32_t usb_hstd_ehci_update_periodic_scheduling_score(usb_utr_t * ptr, uint32_t max_period, uint32_t pollrate);
void     usb_hstd_ehci_int_transfer_end(usb_utr_t * ptr);
void     usb_hstd_ehci_int_port_change(usb_utr_t * ptr);
uint32_t usb_hstd_ehci_get_port_current_connect_status(usb_utr_t * ptr);
void     usb_hstd_ehci_clear_enumalation_wait_flag(void);
void     usb_hstd_ehci_interrupt_handler(usb_utr_t * ptr);
uint16_t usb_hstd_ehci_get_device_address_of_rootpoot(uint16_t rootport);
uint16_t usb_hstd_ehci_set_device_address_of_rootpoot(uint16_t rootport, uint16_t deviceaddr);
uint16_t usb_hstd_ehci_get_transfer_end_status(st_usb_hci_tr_req_t * tr_req);
uint16_t usb_hstd_ehci_get_pid_status(st_usb_hci_tr_req_t * tr_req);
void     usb_hstd_ehci_port_suspend(usb_utr_t * ptr);
void     usb_hstd_ehci_port_resume(usb_utr_t * ptr);
void     usb_hstd_ehci_cancel_transfer_request(st_usb_hci_tr_req_t * tr_req);

/* r_usb_hEhciMemory.c */
void                 usb_hstd_ehci_init_qh_memory(void);
void                 usb_hstd_ehci_init_itd_memory(void);
void                 usb_hstd_ehci_init_sitd_memory(void);
void                 usb_hstd_ehci_init_qtd_memory(void);
void                 usb_hstd_ehci_init_periodic_frame_list(void);
uint32_t             usb_hstd_ehci_get_periodic_frame_list_addr(void);
st_usb_ehci_qh_t   * usb_hstd_ehci_alloc_qh(void);
st_usb_ehci_itd_t  * usb_hstd_ehci_alloc_itd(void);
st_usb_ehci_sitd_t * usb_hstd_ehci_alloc_sitd(void);
st_usb_ehci_qtd_t  * usb_hstd_ehci_alloc_qtd(void);
void                 usb_hstd_ehci_free_qtd(st_usb_ehci_qtd_t * free_qtd);
st_usb_ehci_qh_t   * usb_hstd_ehci_search_qh(uint32_t devadd, uint32_t epnum, uint32_t direction, uint32_t eptype);
st_usb_ehci_itd_t  * usb_hstd_ehci_search_itd(uint32_t devadd, uint32_t epnum, uint32_t direction);
st_usb_ehci_sitd_t * usb_hstd_ehci_search_sitd(uint32_t devadd, uint32_t epnum, uint32_t direction);
void                 usb_hstd_ehci_clear_device_qh(usb_utr_t * ptr, uint32_t devadd);
void                 usb_hstd_ehci_clear_qh(usb_utr_t * ptr, st_usb_ehci_qh_t * qh);
void                 usb_hstd_ehci_clear_device_itd(usb_utr_t * ptr, uint32_t devadd);
void                 usb_hstd_ehci_clear_device_sitd(usb_utr_t * ptr, uint32_t devadd);

/* r_usb_hEhciTransfer.c */
void usb_hstd_ehci_make_transfer_request(st_usb_hci_tr_req_t * p_tr_req);

void usb_hstd_ehci_transfer_end_qh(usb_utr_t * ptr, st_usb_hci_tr_req_t * p_tr_req);
void usb_hstd_ehci_transfer_end_itd(usb_utr_t * ptr, st_usb_hci_tr_req_t * p_tr_req);
void usb_hstd_ehci_transfer_end_sitd(usb_utr_t * ptr, st_usb_hci_tr_req_t * p_tr_req);

#endif                                 /* R_USB_HEHCIEXTERN_H */
