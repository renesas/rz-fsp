/*
 * Copyright (c) 2020-2021 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MAILBOX_HPP
#define MAILBOX_HPP

#include <cstddef>
#include <cstdint>
#include <list>

namespace Mailbox {

/**
 * The Mailbox parent class
 *
 * Intended to be implemented by a driver subclass, see MHU_v2 driver as example.
 */
class Mailbox {
public:
    /**
     * Constructor/Destructor
     */
    Mailbox();
    virtual ~Mailbox();

    /**
     * Intended to trigger an interrupt to an external block
     * MUST be implemented by subclass.
     */
    virtual bool sendMessage() = 0;

    /**
     * Intended to be called when Cortex M has received an
     * interrupt/event from mailbox/mhu. If an interrupt needs to be cleared,
     * this is a good place to do that. MUST call notify().
     * MUST be implemented by subclass.
     */
    virtual void handleMessage() = 0;

    /**
     * Can be used to verify that hardware versions match expected versions
     * CAN be implemented by subclass, optional. Default impl returns true.
     */
    virtual bool verifyHardware();

    /**
     * Function signature for callbacks
     */
    typedef void (*CallbackFptr)(void *userArg);

    /**
     * Register a callback to be called when a message is received.
     */
    void registerCallback(CallbackFptr callback, void *userArg);

    /**
     * Remove a specific callback from the callback list.
     */
    void deregisterCallback(CallbackFptr callback, void *userArg);

protected:
    /**
     * Calls every registered callback when a message has been received.
     */
    void notify();

    /**
     * Helper functions
     */
    uint32_t read32(volatile uint32_t *baseAddr, const uint32_t offset);
    void write32(volatile uint32_t *baseAddr, const uint32_t offset, const uint32_t value);

private:
    struct Callback {
        bool operator==(const Callback &b) const;
        CallbackFptr callback;
        void *userArg;
    };

    std::list<Callback> callbacks;
};

} // namespace Mailbox

#endif
