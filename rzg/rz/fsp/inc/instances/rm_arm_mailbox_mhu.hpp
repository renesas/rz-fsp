/* ${REA_DISCLAIMER_PLACEHOLDER} */

#ifndef _RM_MHU_HPP
#define _RM_MHU_HPP

#include "rm_arm_mailbox_on_mhu_cfg.h"
#include <mailbox.hpp>

namespace Mailbox
{

class RM_MHU : public Mailbox
{
public:
    RM_MHU();
    RM_MHU(const mhu_instance_t &mhu_inst);
    ~RM_MHU() noexcept final;
    bool sendMessage() final;
    void handleMessage() final;

private:
    const mhu_instance_t &mhu_instance;

    void handleError(fsp_err_t err);

    static void mhuCallback(mhu_callback_args_t *p_args)
    {
        auto instance = const_cast<RM_MHU *>(static_cast<const RM_MHU *>(p_args->p_context));
        instance->handleMessage();
    }
};

} // namespace Mailbox

#endif /* #ifndef _RM_MHU_HPP */
