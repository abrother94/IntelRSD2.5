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

#include "agent-framework/module/chassis_components.hpp"
#include "psme/rest/endpoints/acc_chassis/acc_power.hpp"
#include "psme/rest/constants/constants.hpp"
#include "psme/rest/utils/status_helpers.hpp"
#include "psme/rest/server/error/error_factory.hpp"
#include <acc_onlp_helper/acc_onlp_helper.hpp>
using namespace acc_onlp_helper;
using namespace psme::rest;
using namespace psme::rest::constants;
using namespace agent_framework::module;
using namespace agent_framework::model;

namespace
{
json::Json make_prototype()
{
    json::Json r(json::Json::value_t::object);
    r[Common::ODATA_CONTEXT] = "/redfish/v1/$metadata#Power.Power";
    r[Common::ODATA_ID] = json::Json::value_t::null;
    r[Common::ID] = "Power";
    r[Common::ODATA_TYPE] = "#Power.v1_1_0.Power";
    r[Common::NAME] = "Power Supply Collection";
    r[Common::DESCRIPTION] = "Collection of Power Power Supply";
    return r;
}

void fill_acc_power_supplies(Psu &psu_ ,const std::string &power_url, json::Json &r, int chassis_id)
{
    json::Json json_PowerSupplies(json::Json::value_t::object);
    json_PowerSupplies[Common::ODATA_ID] = endpoint::PathBuilder(power_url).build();
    //endpoint::PathBuilder(power_url + Common::HASH).append(PowerZone::POWER_SUPPLIES).append(psu_.get_psu_id()).build();

    json_PowerSupplies[Common::MEMBER_ID] = std::to_string(psu_.get_psu_id());
    json_PowerSupplies[PowerZone::LAST_POWER_OUTPUT_WATTS] = (psu_.get_last_power_output_watts() * 0.001);
    json_PowerSupplies[Common::MODEL] = psu_.get_psu_module();
    json_PowerSupplies[Common::SERIAL_NUMBER] = psu_.get_psu_sn();
    json_PowerSupplies[Common::STATUS][Common::STATE] = psu_.get_status_state();
    json_PowerSupplies[Common::STATUS][Common::HEALTH] = psu_.get_status_health();

    switch (psu_.get_psu_type())
    {
    case 0:
        json_PowerSupplies[PowerZone::POWER_SUPPLY_TYPE] = "AC";
        break;
    case 1:
        json_PowerSupplies[PowerZone::POWER_SUPPLY_TYPE] = "DC";
        break;
    case 2:
        json_PowerSupplies[PowerZone::POWER_SUPPLY_TYPE] = "DC";
        break;
    default:
        json_PowerSupplies[PowerZone::POWER_SUPPLY_TYPE] = "Unknown";
    }

    json_PowerSupplies[Common::NAME] = "Power Supplies Unit";

    json::Json json_input_range(json::Json::value_t::object);
    json_input_range["InputType"] = json::Json::value_t::null;
    json_input_range["MinimumVoltage"] = json::Json::value_t::null;
    json_input_range["MaximumVoltage"] = json::Json::value_t::null;
    json_input_range["OutputWattage"] = json::Json::value_t::null;

    json::Json lrejsontmp(json::Json::value_t::object);
    lrejsontmp[Common::ODATA_ID] = endpoint::PathBuilder(PathParam::BASE_URL).append(Common::CHASSIS).append(chassis_id).build();
    json_PowerSupplies[Common::RELATED_ITEM].push_back(std::move(lrejsontmp));
    r[PowerZone::POWER_SUPPLIES].push_back(std::move(json_PowerSupplies));
}

} // namespace

endpoint::Acc_Power::Acc_Power(const std::string& path) : EndpointBase(path) {}

endpoint::Acc_Power::~Acc_Power() {}

void endpoint::Acc_Power::get(const server::Request& request, server::Response& response)
{
    try
    {
        auto json_f = ::make_prototype();

        json_f[Common::ODATA_ID] = PathBuilder(request).build();
        json_f[Common::ID] = "Power";
        const auto &url = request.get_url();
        auto &psu_manager = agent_framework::module::ChassisComponents::get_instance()->get_psu_manager();
        auto psu_uuids = psu_manager.get_keys();

        for (const auto &psu_uuid : psu_uuids)
        {
            auto psu_ = psu_manager.get_entry(psu_uuid);
            ::fill_acc_power_supplies(psu_, url, json_f, 1);
        }
        set_response(response, json_f);
    }
    catch (const std::exception &e)
    {
        log_debug(LOGUSR, "PsuCollection get - exception : " << e.what());
    }
}
