/*!
 * @brief SetDcpmemConfiguration command interface.
 *
 * @copyright Copyright (c) 2018-2019 Intel Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file set_dcpmem_configuration.cpp
 */

#include "ipmi/command/sdv/rsd/set_dcpmem_configuration.hpp"
#include "ipmi/command/sdv/rsd/constants.hpp"



using namespace ipmi;
using namespace ipmi::command::sdv::rsd;


request::SetDcpmemConfiguration::SetDcpmemConfiguration() : Request(sdv::NetFn::GROUP_EXTENSION,
                                                                        sdv::Cmd::SET_DCPMEM_CONFIGURATION) {}


request::SetDcpmemConfiguration::~SetDcpmemConfiguration() {}


void request::SetDcpmemConfiguration::pack(IpmiInterface::ByteBuffer& data) const {
    data.push_back(static_cast<uint8_t>(GroupExtension::RACKSCALE));
    data.push_back(static_cast<uint8_t>(m_command_status));
    data.push_back(static_cast<uint8_t>(m_erase_dcpmem_action));
}


response::SetDcpmemConfiguration::SetDcpmemConfiguration() : Response(sdv::NetFn::GROUP_EXTENSION,
                                                                          sdv::Cmd::SET_DCPMEM_CONFIGURATION,
                                                                          RESPONSE_SIZE) {}


response::SetDcpmemConfiguration::~SetDcpmemConfiguration() {}


void response::SetDcpmemConfiguration::unpack(const IpmiInterface::ByteBuffer& data) {
    if (static_cast<uint8_t>(GroupExtension::RACKSCALE) == data[constants::GROUP_EXTENSION_ID_OFFSET]) {
        m_is_rackscale_extension_byte_present = true;
    }
    m_command_status = static_cast<DcpmemConfigurationCommandStatus>(data[COMMAND_STATUS_OFFSET]);
    m_erase_dcpmem_action = static_cast<EraseDcpmemAction>(data[ERASE_DCPMEM_ACTION_OFFSET]);
}

