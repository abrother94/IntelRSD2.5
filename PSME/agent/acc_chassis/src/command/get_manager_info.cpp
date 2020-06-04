/*!
 * @copyright
 * Copyright (c) 2015-2019 Intel Corporation
 *
 * @copyright
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * @copyright
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * @copyright
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file command/get_manager_info.cpp
 * @brief GetManagerInfo acc-chassis implementation
 * */

#include "agent-framework/module/common_components.hpp"
#include "agent-framework/command/registry.hpp"
#include "agent-framework/command/chassis_commands.hpp"

using namespace agent_framework::command;
using namespace agent_framework::module;
using namespace agent_framework::model;

REGISTER_COMMAND(GetManagerInfo, [](const GetManagerInfo::Request &req, GetManagerInfo::Response &rsp) {
    const auto &manager = CommonComponents::get_instance()->get_module_manager().get_entry(req.get_uuid());
    log_debug("acc rpc", "Acc GetManagerInfo with parameters: manager " << req.get_uuid() << " mgmt type " << manager.get_manager_type() << " is persistent uuid [" << manager.has_persistent_uuid() << "]");
    if (manager.get_manager_type() == enums::ManagerInfoType::RackManager)
        rsp = manager;
    else
    {
        // Chassis agent should only be able to expose data about manager. This hack is here
        // to ensure that "virtual" sled managers cannot be discovered via chassis agent.
        THROW(::agent_framework::exceptions::InvalidUuid, "model",
              "Entry not found in the manager for UUID = " + manager.get_uuid() + ".");
    }
});
