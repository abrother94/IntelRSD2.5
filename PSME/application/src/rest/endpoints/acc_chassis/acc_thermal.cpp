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
 * */

#include "agent-framework/module/constants/rmm.hpp"
#include "agent-framework/module/requests/common.hpp"
#include "agent-framework/module/responses/common.hpp"

#include "psme/rest/endpoints/acc_chassis/acc_thermal.hpp"
#include "psme/rest/server/error/error_factory.hpp"
#include "psme/rest/utils/status_helpers.hpp"
#include "psme/rest/validators/json_validator.hpp"
#include "psme/rest/validators/schemas/thermal.hpp"
#include <acc_onlp_helper/acc_onlp_helper.hpp>

using namespace acc_onlp_helper;
using namespace psme::rest;
using namespace psme::rest::constants;
using namespace psme::rest::validators;

namespace
{

json::Json make_prototype()
{
    json::Json r(json::Json::value_t::object);

    r[Common::ODATA_CONTEXT] = "/redfish/v1/$metadata#Thermal.Thermal";
    r[Common::ODATA_ID] = json::Json::value_t::null;
    r[Common::ODATA_TYPE] = "#Thermal.v1_1_0.Thermal";
    r[Common::NAME] = "Thermal";
    r[Common::DESCRIPTION] = "Thermal";
    r[Common::ID] = "Thermal";

    r[ThermalZone::TEMPERATURES] = json::Json::value_t::array;
    r[ThermalZone::FANS] = json::Json::value_t::array;
    r[Common::REDUNDANCY] = json::Json::value_t::array;
    return r;
}

json::Json make_fan_prototype()
{
    json::Json r(json::Json::value_t::object);

    r[Common::ODATA_ID] = json::Json::value_t::null;
    r[Common::MEMBER_ID] = json::Json::value_t::null;
    r[Common::NAME] = json::Json::value_t::null;

    r[ThermalZone::READING] = json::Json::value_t::null;
    r[ThermalZone::READING_UNITS] = json::Json::value_t::null;

    r[ChassisSensor::UPPER_THRESHOLD_NON_CRITICAL] = json::Json::value_t::null;
    r[ChassisSensor::UPPER_THRESHOLD_CRITICAL] = json::Json::value_t::null;
    r[ChassisSensor::UPPER_THRESHOLD_FATAL] = json::Json::value_t::null;

    r[ChassisSensor::MIN_READING_RANGE] = json::Json::value_t::null;
    r[ChassisSensor::MAX_READING_RANGE] = json::Json::value_t::null;
    r[ChassisSensor::PHYSICAL_CONTEXT] = json::Json::value_t::null;

    r[Common::STATUS][Common::STATE] = json::Json::value_t::null;
    r[Common::STATUS][Common::HEALTH] = json::Json::value_t::null;
    r[Common::STATUS][Common::HEALTH_ROLLUP] = json::Json::value_t::null;

    r[Common::REDUNDANCY] = json::Json::value_t::array;
    r[Common::RELATED_ITEM] = json::Json::value_t::array;
    return r;
}

json::Json make_temperature_prototype()
{
    json::Json r(json::Json::value_t::object);

    r[Common::ODATA_ID] = json::Json::value_t::null;
    r[Common::MEMBER_ID] = json::Json::value_t::null;
    r[Common::NAME] = json::Json::value_t::null;

    r[ChassisSensor::SENSOR_NUMBER] = json::Json::value_t::null;
    r[ChassisSensor::READING_CELSIUS] = json::Json::value_t::null;

    r[ChassisSensor::UPPER_THRESHOLD_NON_CRITICAL] = json::Json::value_t::null;
    r[ChassisSensor::UPPER_THRESHOLD_CRITICAL] = json::Json::value_t::null;
    r[ChassisSensor::UPPER_THRESHOLD_FATAL] = json::Json::value_t::null;

    r[ChassisSensor::LOWER_THRESHOLD_NON_CRITICAL] = json::Json::value_t::null;
    r[ChassisSensor::LOWER_THRESHOLD_CRITICAL] = json::Json::value_t::null;
    r[ChassisSensor::LOWER_THRESHOLD_FATAL] = json::Json::value_t::null;

    r[ChassisSensor::MIN_READING_RANGE_TEMP] = json::Json::value_t::null;
    r[ChassisSensor::MAX_READING_RANGE_TEMP] = json::Json::value_t::null;
    r[ChassisSensor::PHYSICAL_CONTEXT] = json::Json::value_t::null;

    r[Common::STATUS][Common::STATE] = json::Json::value_t::null;
    r[Common::STATUS][Common::HEALTH] = json::Json::value_t::null;
    r[Common::RELATED_ITEM] = json::Json::value_t::array;

    return r;
}

void fill_fans(json::Json &json_response, const std::string &thermal_url, int chassis_id)
{
    auto &fan_manager = agent_framework::module::ChassisComponents::get_instance()->get_fan_manager();
    auto fan_uuids = fan_manager.get_keys();

    for (const auto &fan_uuid : fan_uuids)
    {
        auto fan_ = fan_manager.get_entry(fan_uuid);
        int fan_id = (int)fan_.get_id();
        signed int RPM = fan_.get_current_speed();
        auto jsontmp = ::make_fan_prototype();
        //jsontmp[Common::ODATA_ID] = endpoint::PathBuilder(thermal_url + Common::HASH)
        //                                .append(ThermalZone::FANS)
        //                                .append(fan_id)
        //                                .build();

        jsontmp[Common::ODATA_ID] = endpoint::PathBuilder(thermal_url).build();
        jsontmp[Common::MEMBER_ID] = std::to_string(fan_id);

        int fan_type = fan_.get_fan_type();

        if (fan_type == acc_onlp_helper::Fan_Info::PSU_Fan)
        {
            jsontmp[Common::NAME] = "PSU Fan";
            jsontmp["PhysicalContext"] = "PowerSupply";
        }
        else if (fan_type == acc_onlp_helper::Fan_Info::SYSTEM_Fan)
        {
            jsontmp[Common::NAME] = "System Fan";
            jsontmp[ChassisSensor::PHYSICAL_CONTEXT] = "Back";
        }
        else
        {
            jsontmp[Common::NAME] = "unknow";
            jsontmp[ChassisSensor::PHYSICAL_CONTEXT] = "unknow";
        }

        if (RPM >= 0)
            jsontmp[ThermalZone::READING] = RPM;
        else
            jsontmp[ThermalZone::READING] = json::Json::value_t::null;

        std::string str_Health = fan_.get_status_health();
        std::string str_State = fan_.get_status_state();

        jsontmp[Common::STATUS][Common::HEALTH] = str_Health.c_str();
        jsontmp[Common::STATUS][Common::STATE] = str_State.c_str();
        jsontmp[ThermalZone::READING_UNITS] = "RPM";

        json::Json lrejsontmp(json::Json::value_t::object);
        lrejsontmp[Common::ODATA_ID] = endpoint::PathBuilder(PathParam::BASE_URL).append(Common::CHASSIS).append(chassis_id).build();
        jsontmp[Common::RELATED_ITEM].push_back(std::move(lrejsontmp));
        json_response[ThermalZone::FANS].push_back(jsontmp);
    }
}

void fill_temperatures(json::Json &json_response, std::string thermal_url, int chassis_id)
{
    auto &tz_manager = agent_framework::module::ChassisComponents::get_instance()->get_thermal_zone_manager();
    auto tz_uuids = tz_manager.get_keys();
    //Set thermal related info. //
    for (const auto &tz_uuid : tz_uuids)
    {
        auto tz_ = tz_manager.get_entry(tz_uuid);
        int thermal_id = tz_.get_tz_id();
        auto jsontmp = ::make_temperature_prototype();
        //jsontmp[Common::ODATA_ID] = endpoint::PathBuilder(thermal_url + Common::HASH)
        //                            .append(ThermalZone::TEMPERATURES)
        //                            .append(thermal_id)
        //                            .build();

        jsontmp[Common::ODATA_ID] = endpoint::PathBuilder(thermal_url).build();
        jsontmp[Common::MEMBER_ID] = std::to_string(thermal_id);

        int thermal_type = tz_.get_thermal_type();

        if (thermal_type == acc_onlp_helper::Thermal_Info::PSU_Sensor)
        {
            jsontmp[Common::NAME] = "PSU Thermal Sensor Temperature";
            jsontmp[ChassisSensor::PHYSICAL_CONTEXT] = "PowerSupply";
        }
        else if (thermal_type == acc_onlp_helper::Thermal_Info::CPU_Sensor)
        {
            jsontmp[Common::NAME] = "System CPU Thermal Sensor Temperature";
            jsontmp[ChassisSensor::PHYSICAL_CONTEXT] = "CPU";
        }
        else if (thermal_type == acc_onlp_helper::Thermal_Info::SYSTEM_Sensor)
        {
            jsontmp[Common::NAME] = "Chassis Thermal Sensor Temperature";
            jsontmp[ChassisSensor::PHYSICAL_CONTEXT] = "SystemBoard";
        }
        else
        {
            jsontmp[Common::NAME] = "unknow";
            jsontmp[ChassisSensor::PHYSICAL_CONTEXT] = "unknow";
        }

        jsontmp[ChassisSensor::SENSOR_NUMBER] = thermal_id;
        jsontmp[ChassisSensor::READING_CELSIUS] = (tz_.get_temperature() * 0.001);
        jsontmp[ChassisSensor::UPPER_THRESHOLD_NON_CRITICAL] = (tz_.get_warning_temp() * 0.001);
        jsontmp[ChassisSensor::UPPER_THRESHOLD_CRITICAL] = (tz_.get_error_temp() * 0.001);
        jsontmp[ChassisSensor::UPPER_THRESHOLD_FATAL] = (tz_.get_shutdown_temp() * 0.001);

        jsontmp[Common::STATUS][Common::HEALTH] = tz_.get_status_health();
        jsontmp[Common::STATUS][Common::STATE] = tz_.get_status_state();

        json::Json lrejsontmp(json::Json::value_t::object);
        lrejsontmp[Common::ODATA_ID] = endpoint::PathBuilder(PathParam::BASE_URL).append(Common::CHASSIS).append(chassis_id).build();
        jsontmp[Common::RELATED_ITEM].push_back(std::move(lrejsontmp));
        json_response[ThermalZone::TEMPERATURES].push_back(jsontmp);
    }
}

static const std::map<std::string, std::string> gami_to_rest_attributes = {
    {agent_framework::model::literals::ThermalZone::DESIRED_SPEED_PWM,
     endpoint::PathBuilder(constants::Common::OEM)
         .append(constants::Common::RACKSCALE)
         .append(constants::ThermalZone::DESIRED_SPEED_PWM)
         .build()}};

void fill_patch_attributes(const json::Json &patch, agent_framework::model::attribute::Attributes &attributes)
{
    if (patch.count(constants::Common::OEM))
    {
        const auto &oem = patch[constants::Common::OEM];
        if (oem.count(constants::Common::RACKSCALE))
        {
            const auto &rackscale = oem[constants::Common::RACKSCALE];
            if (rackscale.count(constants::ThermalZone::DESIRED_SPEED_PWM))
            {
                attributes.set_value(agent_framework::model::literals::ThermalZone::DESIRED_SPEED_PWM,
                                     rackscale[constants::ThermalZone::DESIRED_SPEED_PWM]);
            }
        }
    }
}

void check_response_errors(const agent_framework::model::responses::SetComponentAttributes &response)
{
    const auto &result_statuses = response.get_statuses();
    if (!result_statuses.empty())
    {
        const auto &error = error::ErrorFactory::create_error_from_set_component_attributes_results(
            result_statuses, ::gami_to_rest_attributes);
        throw error::ServerException(error);
    }
}

void update_model_after_patch(psme::core::agent::JsonAgentSPtr agent,
                              const agent_framework::model::ThermalZone &thermal_zone)
{
    psme::rest::model::handler::HandlerManager::get_instance()->get_handler(
                                                                  agent_framework::model::enums::Component::ThermalZone)
        ->load(agent,
               thermal_zone.get_parent_uuid(),
               agent_framework::model::enums::Component::Chassis,
               thermal_zone.get_uuid(),
               true);
}

} // namespace

endpoint::Acc_Thermal::Acc_Thermal(const std::string& path) : EndpointBase(path) {}

endpoint::Acc_Thermal::~Acc_Thermal() {}

void endpoint::Acc_Thermal::get(const server::Request &request, server::Response &response)
{
    auto chassis = model::find<agent_framework::model::Chassis>(request.params).get();
    auto thermal_zones = agent_framework::module::get_manager<agent_framework::model::ThermalZone>().get_keys(chassis.get_uuid());
    auto r = ::make_prototype();

    r[Common::ODATA_ID] = PathBuilder(request).build();

    if (thermal_zones.empty())
    {
        throw error::ServerException(error::ErrorFactory::create_resource_missing_error(request.get_url()));
    }
    else
    {
        fill_temperatures(r, request.get_url(), 1);
        fill_fans(r, request.get_url(), 1);
    }
    set_response(response, r);
}

void endpoint::Acc_Thermal::patch(const server::Request& request, server::Response& response) {
    static const constexpr char TRANSACTION_NAME[] = "PatchThermal";

    auto chassis = model::find<agent_framework::model::Chassis>(request.params).get();

    // Only RMM service has this action
    if (!utils::has_resource_capability(chassis, Capability::RMM)) {
        throw error::ServerException(
            error::ErrorFactory::create_method_not_allowed_error(
                "This action is allowed only for RMM service."));
    }

    auto thermal_zones = agent_framework::module::get_manager<agent_framework::model::ThermalZone>()
        .get_keys(chassis.get_uuid());

    if (!thermal_zones.empty()) {
        auto thermal_zone = agent_framework::module::get_manager<agent_framework::model::ThermalZone>()
            .get_entry(thermal_zones.front());

        const auto json = JsonValidator::validate_request_body<schema::ThermalPatchSchema>(request);
        agent_framework::model::attribute::Attributes attributes{};
        ::fill_patch_attributes(json, attributes);

        if (!attributes.empty()) {
            agent_framework::model::requests::SetComponentAttributes gami_request{thermal_zone.get_uuid(), attributes};
            const auto& gami_agent = psme::core::agent::AgentManager::get_instance()->get_agent(thermal_zone.get_agent_id());

            auto set_thermal_zone_attributes = [&, gami_agent] {
                const auto& gami_response =
                    gami_agent->execute<agent_framework::model::responses::SetComponentAttributes>(gami_request);

                ::check_response_errors(gami_response);
                ::update_model_after_patch(gami_agent, thermal_zone);
            };

            gami_agent->execute_in_transaction(TRANSACTION_NAME, set_thermal_zone_attributes);
        }
    }
    else {
        auto message = std::string("PATCH operation on chassis of type ") +
            chassis.get_type().to_string() + " is not allowed.";
        throw error::ServerException(error::ErrorFactory::create_invalid_payload_error(message));
    }

    get(request, response);
}
