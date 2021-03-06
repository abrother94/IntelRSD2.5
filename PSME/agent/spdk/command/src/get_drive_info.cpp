/*!
 * @brief Implementation of GetDriveInfo command.
 *
 * @copyright Copyright (c) 2018-2019 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file get_drive_info.cpp
 */


#include "spdk_agent_commands.hpp"
#include "agent-framework/module/common_components.hpp"



using namespace agent::spdk;
using namespace agent_framework;

namespace {
void get_drive_info(GetDriveInfo::ContextPtr, const GetDriveInfo::Request& request, GetDriveInfo::Response& response) {

    log_debug("spdk-agent", "Getting drive info.");
    response = module::get_manager<model::Drive>().get_entry(request.get_uuid());

}
}

REGISTER_SPDK_COMMAND(GetDriveInfo, ::get_drive_info);

