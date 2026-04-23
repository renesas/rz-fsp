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

#include <mailbox.hpp>

#include <cassert>
#include <cstddef>

namespace Mailbox {

Mailbox::Mailbox() {}
Mailbox::~Mailbox() {}

bool Mailbox::verifyHardware() {
    return true;
}

void Mailbox::registerCallback(CallbackFptr callback, void *userArg) {
    callbacks.push_back({callback, userArg});
}

void Mailbox::deregisterCallback(CallbackFptr callback, void *userArg) {
    callbacks.remove({callback, userArg});
}

void Mailbox::notify() {
    for (auto &it : callbacks) {
        it.callback(it.userArg);
    }
}

uint32_t Mailbox::read32(volatile uint32_t *baseAddr, const uint32_t offset) {
    assert(offset % 4 == 0);
    volatile uint32_t *addr = baseAddr + (offset / 4);

    return *addr;
}

void Mailbox::write32(volatile uint32_t *baseAddr, const uint32_t offset, const uint32_t value) {
    assert(offset % 4 == 0);
    volatile uint32_t *addr = baseAddr + (offset / 4);

    *addr = value;
}

bool Mailbox::Callback::operator==(const Callback &b) const {
    return (callback == b.callback && userArg == b.userArg);
}

} // namespace Mailbox
