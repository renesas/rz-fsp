/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * File Name    : r_usb_hOhciExtern.c
 * Description  : OHCI Extern Header
 ***********************************************************************************************************************/

/**********************************************************************************************************************
 * History : DD.MM.YYYY Version Description
 *         : 31.08.2015 1.00    First Release
 ***********************************************************************************************************************/

#ifndef R_USB_HOHCI_EXTERN_H
#define R_USB_HOHCI_EXTERN_H

/*======================================================================== */
/*                      Prototypes                                         */
/*======================================================================== */
/* function */
/* r_usb_hOhciMain.c */
uint32_t usb_hstd_ohci_init(void);
void     usb_hstd_ohci_deinit(void);
void     usb_hstd_ohci_interrupt_handler(usb_utr_t * ptr);
void     usb_hstd_OhciMainRoutine(usb_utr_t * ptr,
                                  uint32_t    context_info,
                                  uint32_t    port_reg,
                                  uint32_t    port_num);
void     usb_hstd_ohci_control_roothub(usb_utr_t * ptr, uint32_t port_reg, uint32_t port_num);
void     usb_hstd_ohci_disconnect(usb_utr_t * ptr, uint32_t devadd);
uint16_t usb_hstd_ohci_get_device_address_of_rootpoot(uint16_t rootport);
uint16_t usb_hstd_ohci_set_device_address_of_rootpoot(uint16_t rootport, uint16_t deviceaddr);
void     usb_hstd_ohci_port_reset(uint32_t portnum);
uint16_t usb_hstd_ohci_get_pid_status(st_usb_hci_tr_req_t * tr_req);
void     usb_hstd_ohci_port_suspend(uint16_t port);
void     usb_hstd_ohci_port_resume(uint16_t port);
uint16_t usb_hstd_ohci_get_transfer_end_status(st_usb_hci_tr_req_t * tr_req);
uint32_t usb_hstd_ohci_remove_endpoint(uint8_t   device_address,
                                       uint8_t   endpoint_number,
                                       uint8_t   direction,
                                       boolean_t free_ed);
uint32_t usb_hstd_ohci_pause_endpoint(usb_utr_t * ptr,
                                      uint8_t     device_address,
                                      uint8_t     endpoint_number,
                                      uint8_t     direction);
st_usb_ohci_list_entry_p_t usb_hstd_ohci_remove_list_head(st_usb_ohci_list_entry_p_t list);
void                       usb_hstd_ohci_remove_list_entry(st_usb_ohci_list_entry_p_t list);
void                       usb_hstd_ohci_initialize_list_head(st_usb_ohci_list_entry_p_t list);
uint32_t                   usb_hstd_ohci_is_list_empty(st_usb_ohci_list_entry_p_t list);
void                       usb_hstd_ohci_insert_head_list(st_usb_ohci_list_entry_p_t list_head,
                                                          st_usb_ohci_list_entry_p_t link);
void usb_hstd_ohci_insert_tail_list(st_usb_ohci_list_entry_p_t list_head,
                                    st_usb_ohci_list_entry_p_t link);
#if defined(BSP_CFG_CORE_CA55)
uint64_t usb_hstd_ohci_physical_address_of (void * p_data);
#endif
void     usb_hstd_ohci_pause_ed(usb_utr_t * ptr, st_usb_ohci_hcd_endpoint_p_t endpoint);
void     usb_hstd_ohci_unschedule_isochronous_or_interrupt_endpoint(
    st_usb_ohci_hcd_endpoint_p_t endpoint,
    boolean_t                    free_ed,
    boolean_t                    endpoint_processing_required);
uint32_t usb_hstd_ohci_set_frame_interval(st_usb_ohci_hcd_device_data_p_t device_data,
                                          boolean_t                       up_not_down);
uint32_t usb_hstd_ohci_get_32bit_frame_number(st_usb_ohci_hcd_device_data_p_t device_data);
uint32_t usb_hstd_ohci_check_bandwidth(st_usb_ohci_hcd_device_data_p_t device_data,
                                       uint32_t                        list,
                                       uint32_t                      * p_best_list);

/* r_usb_hOhciMemory.c */
st_usb_ohci_hcca_block_p_t              usb_hstd_ohci_get_hcca_address(void);
void                                    usb_hstd_ohci_init_request_memory(void);
void                                    usb_hstd_ohci_init_device_data(void);
void                                    usb_hstd_ohci_clear_list(void);
st_usb_ohci_request_p_t                 usb_hstd_ohci_alloc_transfer_request(void);
st_usb_ohci_hcd_device_data_p_t         usb_hstd_ohci_alloc_device_data(void);
st_usb_ohci_hcd_endpoint_p_t            usb_hstd_ohci_alloc_endpoint(void);
st_usb_ohci_hcd_endpoint_descriptor_p_t usb_hstd_ohci_allocate_endpoint_descriptor(void);
st_usb_ohci_hcd_transfer_descriptor_p_t usb_hstd_ohci_allocate_transfer_descriptor(void);
st_usb_ohci_iso_info_p_t                usb_hstd_ohci_alloc_endpoint_iso(void);
void                                    usb_hstd_ohci_free_transfer_request(st_usb_ohci_request_p_t ohci_req);
void                                    usb_hstd_ohci_free_transfer_descriptor(
    st_usb_ohci_hcd_transfer_descriptor_p_t td);
void usb_hstd_ohci_free_endpoint(st_usb_ohci_hcd_endpoint_p_t endpoint);
void usb_hstd_ohci_free_endpoint_descriptor(
    st_usb_ohci_hcd_endpoint_descriptor_p_t ed);
st_usb_ohci_hcd_endpoint_p_t usb_hstd_ohci_scan_endpoint(uint8_t device_address,
                                                         uint8_t endpoint_number,
                                                         uint8_t direction);
void usb_hstd_ohci_store_endpoint(uint8_t                      device_address,
                                  uint8_t                      endpoint_number,
                                  uint8_t                      direction,
                                  st_usb_ohci_hcd_endpoint_p_t endpoint);
uint32_t usb_hstd_ohci_scan_containing_record(st_usb_ohci_list_entry_p_t list,
                                              uint8_t                    type,
                                              uint8_t                    field);
uint32_t usb_hstd_ohci_check_remained_td(void);
uint32_t usb_hstd_ohci_check_remained_ed(void);
uint32_t usb_hstd_ohci_check_remained_ep(void);

/* r_usb_hOhciTransfer.c */
void usb_hstd_ohci_make_transfer_request(usb_utr_t * ptr, st_usb_hci_tr_req_t * p_tr_req);
void usb_hstd_ohci_cancel_transfer_request(usb_utr_t * ptr, st_usb_hci_tr_req_t * p_tr_req);
void usb_hstd_ohci_process_done_queue(usb_utr_t * ptr, uint32_t phys_hc_td);
void usb_hstd_ohci_complete_transfer_request(usb_utr_t * ptr, st_usb_ohci_request_p_t ohci_req);

#endif                                 /* R_USB_HOHCI_EXTERN_H */
