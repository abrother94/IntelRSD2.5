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
 * @file command/get_collection.cpp
 * @brief GetCollection accton-chassis implementation
 * */

#include "agent-framework/module/common_components.hpp"
#include "agent-framework/module/chassis_components.hpp"
#include "agent-framework/module/compute_components.hpp"
#include "agent-framework/command/registry.hpp"
#include "agent-framework/command/chassis_commands.hpp"
#include "base64/base64.hpp"

using namespace agent_framework::command;
using namespace agent_framework::module;
using namespace agent_framework::model;
using namespace agent_framework::model::attribute;

namespace
{

using KeysVec = std::vector<std::string>;
using Collections = attribute::Array<attribute::Collection>;
using ComputeComponents = agent_framework::module::ComputeComponents;
using ChassisComponents = agent_framework::module::ChassisComponents;
using CommonComponents = agent_framework::module::CommonComponents;

void response_add_subcomponents(const KeysVec &keys,
                                GetCollection::Response &response)
{
    for (const auto &key : keys)
    {
        SubcomponentEntry s;
        s.set_subcomponent(key);
        response.add_entry(s);
    }
}

void process_chassis(const Collection &collection, const std::string &uuid,
                     GetCollection::Response &response, const std::string &name)
{
    std::cout << "////// Process Chassis //////" << std::endl;
    // Three possible collection type for a chassis
    if (enums::CollectionType::Fans == collection.get_type())
    {
        std::cout << "////// Process Chassis Add FAN component //////" << std::endl;
        response_add_subcomponents(ChassisComponents::get_instance()->get_fan_manager().get_keys(uuid), response);
    }
    else if (enums::CollectionType::ThermalZones == collection.get_type())
    {
        std::cout << "////// Process Chassis  Add ThermalZones component //////" << std::endl;
        response_add_subcomponents(ChassisComponents::get_instance()->get_thermal_zone_manager().get_keys(uuid), response);
    }
    else if (enums::CollectionType::PSUs == collection.get_type())
    {
        std::cout << "////// Process Chassis  Add PSUs component //////" << std::endl;
        response_add_subcomponents(ChassisComponents::get_instance()->get_psu_manager().get_keys(uuid), response);
    }
    else
    {
        THROW(agent_framework::exceptions::InvalidCollection,
              "acc-chassis-agent", "Process chassis not found: \'" + name + "\'.");
    }
}

void process_manager(const Collection &collection, const std::string &uuid,
                     GetCollection::Response &response, const std::string &name)
{
    if (enums::CollectionType::Chassis == collection.get_type())
    {
        std::cout << "////// Add Chassis component //////" << std::endl;
        response_add_subcomponents(CommonComponents::get_instance()->get_chassis_manager().get_keys(uuid), response);
    }
    else if (enums::CollectionType::LogServices== collection.get_type())
    {
        std::cout << "////// Add Logservice component //////" << std::endl;
        response_add_subcomponents(CommonComponents::get_instance()->get_log_service_manager().get_keys(uuid), response);
    }
    else
    {
        THROW(agent_framework::exceptions::InvalidCollection, "acc-chassis-agent", "Process manager not found name: \'" + name + "\'");
    }
}

const Collection find_collection(const Collections &collections,
                                 const std::string &name)
{
    for (const auto &collection : collections)
    {
        if (name == collection.get_name())
        {
            return collection;
        }
    }
    Collection c;
    c.set_type(enums::CollectionType::None);
    return c;
}

void get_collection(const GetCollection::Request &request, GetCollection::Response &response)
{
    const auto &uuid = request.get_uuid();
    const auto &name = request.get_name();

    log_debug("acc-chassis-agent", "Acc GetCollection with parameters: component "
    << request.get_uuid() << ", name " << request.get_name());

    if (get_manager<Manager>().entry_exists(uuid))
    {
        const Manager manager = CommonComponents::get_instance()->get_module_manager().get_entry(uuid);
        const Collection collection = find_collection(manager.get_collections(), name);
        process_manager(collection, uuid, response, name);
    }
    else if (get_manager<Chassis>().entry_exists(uuid))
    {
        const Chassis &chassis = get_manager<Chassis>().get_entry(uuid);
        const Collection &collection = find_collection(chassis.get_collections(), name);
        process_chassis(collection, uuid, response, name);
    }
    else
    {
        THROW(::agent_framework::exceptions::InvalidUuid, "chassis-agent",
              "Component not found, invalid UUID: " + uuid);
    }
}
}

REGISTER_COMMAND(GetCollection, ::get_collection);
