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
 * @file command/get_chassis_info.cpp
 * @brief GetChassisInfo accton chassis implementation
 * */

#include "agent-framework/module/common_components.hpp"
#include "agent-framework/module/compute_components.hpp"
#include "agent-framework/module/chassis_components.hpp"
#include "agent-framework/command/registry.hpp"
#include "agent-framework/command/chassis_commands.hpp"
#include "agent-framework/command/compute_commands.hpp"
#include "agent-framework/command/rmm_commands.hpp"

using namespace agent_framework::command;
using namespace agent_framework::module;

REGISTER_COMMAND(GetChassisInfo,
    [] (const GetChassisInfo::Request& req, GetChassisInfo::Response& rsp) {
        log_debug("acc rpc ", "Acc GetChassisInfo with parameters: chassis " << req.get_uuid());
        rsp = CommonComponents::get_instance()->get_chassis_manager().get_entry(req.get_uuid());
    }
);

REGISTER_COMMAND(GetFanInfo,
    [] (const GetFanInfo::Request& req, GetFanInfo::Response& rsp) {
         log_debug("acc rpc", "GetFanInfo with parameters: Fan " << req.get_uuid());   
        rsp = ChassisComponents::get_instance()->get_fan_manager().get_entry(req.get_uuid());
    }
);

REGISTER_COMMAND(GetThermalZoneInfo,
    [] (const GetThermalZoneInfo::Request& req, GetThermalZoneInfo::Response& rsp) {
         log_debug("acc rpc", "GetThermalZoneInfo with parameters: ThermalZone " << req.get_uuid());   
        rsp = ChassisComponents::get_instance()->get_thermal_zone_manager().get_entry(req.get_uuid());
    }
);

REGISTER_COMMAND(GetPsuInfo,
    [] (const GetPsuInfo::Request& req, GetPsuInfo::Response& rsp) {
         log_debug("acc rpc", "GetPsuInfo with parameters: PSU " << req.get_uuid());   
        rsp = ChassisComponents::get_instance()->get_psu_manager().get_entry(req.get_uuid());
    }
);
