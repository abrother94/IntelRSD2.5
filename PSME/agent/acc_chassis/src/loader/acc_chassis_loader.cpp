/*!
 * @section LICENSE
 *
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
 * @section DESCRIPTION
 *
 * */

#include "loader/acc_chassis_loader.hpp"
#include "configuration/configuration.hpp"
#include "logger/logger_factory.hpp"

#include "agent-framework/module/chassis_components.hpp"
#include "agent-framework/module/common_components.hpp"
#include "agent-framework/version.hpp"

#include <chrono>
#include <thread>



using namespace agent::chassis::loader;
using namespace agent_framework::generic;
using namespace agent_framework::model;
using namespace agent_framework::module;
using namespace agent_framework::model::attribute;

#define ENABLE_CONFIGURATION_ENCRYPTION

namespace
{
#ifdef ENABLE_CONFIGURATION_ENCRYPTION

inline std::string decrypt_value(const std::string &value)
{
    return configuration::Configuration::get_instance().decrypt_value(value);
}

#else
inline std::string decrypt_value(const std::string &value)
{
    return value;
}
#endif
} // namespace

Acc_ChassisLoader::~Acc_ChassisLoader() {}

class Acc_LoadManagers
{
public:
    void read_managers(const json::Json &json)
    {
        if (json.count("managers"))
        {
            for (const auto &elem : json["managers"])
            {
                auto manager = make_manager(elem);
                read_manager(manager, elem);
            }
        }
    }

private:
    void read_manager(Manager &manager, const json::Json &json)
    {

        if (json.value("chassis", json::Json()).is_object())
        {
            auto chassis = make_chassis(manager, json["chassis"]);
            log_debug("discovery", "Adding chassis:" << chassis.get_uuid() << " to manager " << manager.get_uuid());

            Psu psu{chassis.get_uuid()};
            log_debug("discovery", "Adding psu:" << psu.get_uuid() << " to chassis " << chassis.get_uuid());
            get_manager<Psu>().add_entry(psu);

            ThermalZone thermal_zone{chassis.get_uuid()};
            log_debug("discovery", "Adding thermal zone:" << thermal_zone.get_uuid() << " to chassis " << chassis.get_uuid());
            get_manager<ThermalZone>().add_entry(thermal_zone);

            Fan fan{chassis.get_uuid()};
            log_debug("discovery", "Adding fan :" << fan.get_uuid() << " to chassis " << chassis.get_uuid());
            get_manager<Fan>().add_entry(fan);

            chassis.add_collection(attribute::Collection(
                enums::CollectionName::Fans,
                enums::CollectionType::Fans));

            chassis.add_collection(attribute::Collection(
                enums::CollectionName::ThermalZones,
                enums::CollectionType::ThermalZones));

            chassis.add_collection(attribute::Collection(
                enums::CollectionName::Psus,
                enums::CollectionType::PSUs));

            get_manager<Chassis>().add_entry(chassis);
        }

        log_debug("discovery", "Adding manager:" << manager.get_uuid());
        get_manager<Manager>().add_entry(manager);
    }

    Manager make_manager(const json::Json &json)
    {
        Manager manager{};
        //Chassis collection is added only to top level manager.
        manager.add_collection(attribute::Collection(
            enums::CollectionName::Chassis,
            enums::CollectionType::Chassis));

        make_manager_info(manager, json);
        return manager;
    }

    void make_manager_info(Manager &manager, const json::Json &json)
    {
        manager.set_firmware_version(Version::VERSION_STRING);
        manager.set_slot(std::uint8_t(json.value("slot", std::uint16_t{})));

        manager.set_manager_type(enums::ManagerInfoType::RackManager);
        manager.set_status({agent_framework::model::enums::State::Enabled,
                            agent_framework::model::enums::Health::OK});

        attribute::SerialConsole serial{};
        serial.set_bitrate(115200);
        serial.set_data_bits(8);
        serial.set_enabled(json.value("serialConsoleEnabled", bool{}));
        serial.set_flow_control(enums::SerialConsoleFlowControl::None);
        serial.set_parity(enums::SerialConsoleParity::None);
        serial.set_pin_out(enums::SerialConsolePinOut::Cisco);
        serial.set_stop_bits(1);
        serial.set_signal_type(enums::SerialConsoleSignalType::Rs232);
        manager.set_serial_console(std::move(serial));
    }

    Chassis make_chassis(Manager &parent, const json::Json &json)
    {
        Chassis chassis{parent.get_uuid()};
        try
        {
            chassis.set_location_offset(json.value("locationOffset", std::uint16_t{}));

            chassis.set_type(enums::ChassisType::from_string(json.value("type", std::string{})));
            parent.set_location(chassis.get_uuid());

            const auto &parent_id_json = json.value("parentId", json::Json());
            if (parent_id_json.is_number_unsigned())
            { // for backward compatibility
                chassis.set_parent_id(std::to_string(parent_id_json.get<unsigned int>()));
            }
            else
            {
                chassis.set_parent_id(parent_id_json.get<std::string>());
            }
        }
        catch (const std::runtime_error &e)
        {
            log_error("discovery", "Invalid chassis configuration.");
            log_debug("discovery", "Invalid chassis configuration: " << e.what());
        }

        if (json.value("platform", json::Json()).is_string())
        {
            chassis.set_platform(enums::PlatformType::from_string(json.value("platform", std::string{})));
        }
        else
        {
            log_warning("discovery", "Field 'platform' missing in configuration file. Set default: BDCR");
            chassis.set_platform(enums::PlatformType::BDCR);
        }

        if (json.value("networkInterface", json::Json()).is_string())
        {
            chassis.set_network_interface(json.value("networkInterface", std::string{}));
        }

        chassis.set_status({agent_framework::model::enums::State::Enabled,
                            agent_framework::model::enums::Health::OK});

        /*Add ONL related PM Nodes*/
        Fan fan{chassis.get_uuid()};
        fan.set_chassis(chassis.get_uuid());
        fan.set_current_speed(0);
        fan.set_fan_type(0);
        fan.set_status_health("unknown");
        fan.set_status_state("unknown");
        fan.set_fan_id(1);
        ChassisComponents::get_instance()->get_fan_manager().add_entry(fan);

        ThermalZone tzone{chassis.get_uuid()};
        tzone.set_chassis(chassis.get_uuid());
        tzone.set_temperature(0);
        tzone.set_tz_id(1);
        tzone.set_warning_temp(0);
        tzone.set_error_temp(0);
        tzone.set_shutdown_temp(0);
        tzone.set_status_health("unknow");
        tzone.set_status_state("unknow");
        ChassisComponents::get_instance()->get_thermal_zone_manager().add_entry(tzone);

        Psu psu{chassis.get_uuid()};
        psu.set_chassis(chassis.get_uuid());
        psu.set_psu_id(1);
        ChassisComponents::get_instance()->get_psu_manager().add_entry(psu);
        return chassis;
    }
};

bool Acc_ChassisLoader::load(const json::Json &json)
{
    try
    {
        log_warning("Acc_ChassisLoader", "load");
        Acc_LoadManagers lm{};
        lm.read_managers(json);
        return true;
    }
    catch (const std::exception e)
    {
        log_error("discovery", "Load agent configuration failed: " << e.what());
    }
    return false;
}
