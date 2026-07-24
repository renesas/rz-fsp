/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include <stdio.h>
#include "bsp_api.h"
#include "bsp_otfde.h"

#if BSP_FEATURE_DDR_SUPPORTED && BSP_CFG_DDR_INIT_ENABLE && (BSP_CFG_OTFDE0_SUPPORT_ENABLE || \
                                                             BSP_CFG_OTFDE1_SUPPORT_ENABLE)

 #include "r_rsip.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
 #define BSP_OTFDE_IV_INV_MASK_VALUE     (0xffffffff)
 #define BSP_OTFDE_REG00_VALUE1_MASK     (0x10)
 #define BSP_OTFDE_REG00_VALUE2_NUM      (0x6)
 #define BSP_OTFDE_REG32_RESET_VALUE     (0x22000000)

 #define BSP_OTFDE_SEED_1_SEED_MASK      (0x3)
 #define BSP_OTFDE_SEED_1_ENABLE_MASK    (0xC)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
static fsp_err_t bsp_prv_otfde_side_channal_seed_init(uint32_t p_seed[]);
static fsp_err_t bsp_prv_otfde_aes_setup(void);

static rsip_instance_ctrl_t g_bsp_otfde_rsip_ctrl;
static const rsip_cfg_t     g_bsp_otfde_rsip_cfg;

/*******************************************************************************************************************//**
 * Initialize OTFDE.
 **********************************************************************************************************************/
void bsp_otfde_init (void)
{
    /* Setting OTFDE_CONVAREST > OTFDE_CONVAREAEN is prohibited. */
    if (BSP_CFG_OTFDE_START_ADDRESS <= BSP_CFG_OTFDE_END_ADDRESS)
    {
        /* Configure OTFDE decryption/encryption area. */
        R_OTFDE_MISC->OTFDE_CONVAREAST = BSP_CFG_OTFDE_START_ADDRESS & R_OTFDE_MISC_OTFDE_CONVAREAST_CONVAREAST_Msk;
        R_OTFDE_MISC->OTFDE_CONVAREAED = BSP_CFG_OTFDE_END_ADDRESS & R_OTFDE_MISC_OTFDE_CONVAREAED_CONVAREAED_Msk;

        /* Initialize AES. */
        fsp_err_t otfde_ret = bsp_prv_otfde_aes_setup();
        if (FSP_SUCCESS != otfde_ret)
        {
            R_RSIP_Close(&g_bsp_otfde_rsip_ctrl);
        }
    }
}

/*******************************************************************************************************************//**
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Configure OTFDE side channel seed information.
 **********************************************************************************************************************/
static fsp_err_t bsp_prv_otfde_side_channal_seed_init (uint32_t p_seed[])
{
    uint32_t  random_number[4U] = {0};
    fsp_err_t err               = R_RSIP_RandomNumberGenerate(&g_bsp_otfde_rsip_ctrl, (uint8_t *) &random_number[0]);

    if (FSP_SUCCESS == err)
    {
        p_seed[0] = random_number[0];
        p_seed[1] = (random_number[1] & BSP_OTFDE_SEED_1_SEED_MASK) | BSP_OTFDE_SEED_1_ENABLE_MASK;
    }

    return err;
}

/*******************************************************************************************************************//**
 * Configure the device for OTFDE operation.
 **********************************************************************************************************************/
static fsp_err_t bsp_prv_otfde_aes_setup (void)
{
    fsp_err_t rsip_ret = FSP_SUCCESS;
    uint32_t  seed[2]  = {0};
    uint8_t   wrapped_key_value[RSIP_BYTE_SIZE_WRAPPED_KEY_AES_256] = {0};

    rsip_key_type_t key_type = RSIP_KEY_TYPE_AES_128;

    if (BSP_OTFDE_AES_KEY_TYPE_128 == BSP_CFG_OTFDE_KEY_TYPE)
    {
        key_type = RSIP_KEY_TYPE_AES_128;
    }
    else if (BSP_OTFDE_AES_KEY_TYPE_256 == BSP_CFG_OTFDE_KEY_TYPE)
    {
        key_type = RSIP_KEY_TYPE_AES_256;
    }
    else
    {
        return FSP_ERR_INVALID_ARGUMENT;
    }

    /* Open RSIP. */
    rsip_ret = R_RSIP_Open(&g_bsp_otfde_rsip_ctrl, &g_bsp_otfde_rsip_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == rsip_ret, rsip_ret);

    /* Generates structure data "rsip_wrapped_key_t". */
    rsip_wrapped_key_t wrapped_key = {.type = key_type, .p_value = wrapped_key_value};
    rsip_ret = R_RSIP_KeyGenerate(&g_bsp_otfde_rsip_ctrl, &wrapped_key);
    FSP_ERROR_RETURN(FSP_SUCCESS == rsip_ret, rsip_ret);

    rsip_ret = bsp_prv_otfde_side_channal_seed_init(seed);
    FSP_ERROR_RETURN(FSP_SUCCESS == rsip_ret, rsip_ret);

    /* Init OTFDE. */
    rsip_ret = R_RSIP_OTF_Init(&g_bsp_otfde_rsip_ctrl, RSIP_OTF_CHANNEL_2, &wrapped_key, (uint8_t *) &seed[0]);
    FSP_ERROR_RETURN(FSP_SUCCESS == rsip_ret, rsip_ret);

    /* Generate IV of AES-CTR. */
    uint32_t iv[4]       = {0};
    uint32_t iv_inv_mask = BSP_CFG_OTFDE_IV_CHANGE ? BSP_OTFDE_IV_INV_MASK_VALUE : 0x0;
    rsip_ret = R_RSIP_RandomNumberGenerate(&g_bsp_otfde_rsip_ctrl, (uint8_t *) &iv[0]);
    FSP_ERROR_RETURN(FSP_SUCCESS == rsip_ret, rsip_ret);

    if (FSP_SUCCESS == rsip_ret)
    {
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < BSP_OTFDE_REG00_VALUE2_NUM; j++)
            {
                R_OTFDE0->REG00 = (i ? BSP_OTFDE_REG00_VALUE1_MASK : 0) | j;

                /* Disable byte order conversion. */
                R_OTFDE0->REG32 = (BSP_OTFDE_REG32_RESET_VALUE | R_OTFDE0_REG32_B09_Msk);

                /* Load the IV. */
                R_OTFDE0->REG35 = iv[0];
                R_OTFDE0->REG35 = iv[1];
                R_OTFDE0->REG35 = iv[2];
                R_OTFDE0->REG35 = iv[3];

                R_OTFDE1->REG00 = (i ? BSP_OTFDE_REG00_VALUE1_MASK : 0) | j;

                /* Disable byte order conversion. */
                R_OTFDE1->REG32 = (BSP_OTFDE_REG32_RESET_VALUE | R_OTFDE0_REG32_B09_Msk);

                /* Load the IV. */
                R_OTFDE1->REG35 = iv[0] ^ iv_inv_mask;
                R_OTFDE1->REG35 = iv[1] ^ iv_inv_mask;
                R_OTFDE1->REG35 = iv[2] ^ iv_inv_mask;
                R_OTFDE1->REG35 = iv[3] ^ iv_inv_mask;
            }
        }
    }

    /* Close RSIP. */
    rsip_ret = R_RSIP_Close(&g_bsp_otfde_rsip_ctrl);

    return rsip_ret;
}

#endif
