/* ${REA_DISCLAIMER_PLACEHOLDER} */

#include "rm_arm_mailbox_mhu.hpp"
#include <stdexcept>

namespace Mailbox
{

RM_MHU::RM_MHU(const mhu_instance_t &mhu_inst) : Mailbox(), mhu_instance(mhu_inst)
{
    auto err = mhu_instance.p_api->open(mhu_instance.p_ctrl, mhu_instance.p_cfg);
    if (err != FSP_SUCCESS)
    {
        handleError(err);
    }

    err = mhu_instance.p_api->callbackSet(mhu_instance.p_ctrl, mhuCallback, this, nullptr);
    if (err != FSP_SUCCESS)
    {
        handleError(err);
    }
}

RM_MHU::RM_MHU() : RM_MHU(*rm_arm_mailbox_mhu_get_mhu_instance())
{
}

RM_MHU::~RM_MHU() noexcept
{
    auto err = mhu_instance.p_api->close(mhu_instance.p_ctrl);
    if (err != FSP_SUCCESS)
    {
        FSP_ERROR_LOG(err);
    }
}

bool RM_MHU::sendMessage()
{
    auto err = mhu_instance.p_api->msgSend(mhu_instance.p_ctrl, 0);
    return err == FSP_SUCCESS;
}

void RM_MHU::handleMessage()
{
    notify();
}

void RM_MHU::handleError(fsp_err_t err)
{
    FSP_PARAMETER_NOT_USED(err);
    FSP_ERROR_LOG(err);
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
    while (1)
    {
        ;
    }
}

} // namespace Mailbox
