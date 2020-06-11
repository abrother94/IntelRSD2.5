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

#include "agent-framework/module/model/thermal_zone.hpp"
#include "agent-framework/module/constants/rmm.hpp"

using namespace agent_framework::model;
using namespace agent_framework::model::utils;

const enums::Component ThermalZone::component = enums::Component::ThermalZone;
const enums::CollectionName ThermalZone::collection_name = enums::CollectionName::ThermalZones;

ThermalZone::ThermalZone(const std::string& parent_uuid, enums::Component parent_type) :
    Resource{parent_uuid, parent_type} {}

ThermalZone::~ThermalZone() {}

json::Json ThermalZone::to_json() const {
    json::Json result = json::Json();
    result[literals::ThermalZone::STATUS] = get_status().to_json();
    result[literals::ThermalZone::VOLUMETRIC_AIRFLOW_CFM] = get_volumetric_airflow_cfm();
    result[literals::ThermalZone::DESIRED_SPEED_PWM] = get_desired_speed_pwm();
    result[literals::ThermalZone::COLLECTIONS] = get_collections().to_json();
    result[literals::ThermalZone::OEM] = get_oem().to_json();

    result[literals::ThermalZone::CHASSIS] = get_chassis();    
    result[literals::ThermalZone::TZ_ID]  = get_tz_id();    
    result[literals::ThermalZone::STATUS_HEALTH] = get_status_health();
    result[literals::ThermalZone::STATUS_STATE] = get_status_state();	
    result[literals::ThermalZone::WARNING_TEMP] = get_warning_temp();
    result[literals::ThermalZone::ERROR_TEMP] = get_error_temp();
    result[literals::ThermalZone::SHUTDOWN_TEMP] = get_shutdown_temp();	
    result[literals::ThermalZone::THERMAL_TYPE] = get_thermal_type();	
    result[literals::ThermalZone::READINGCELSIUS] = get_temperature();	
    return result;
}

ThermalZone ThermalZone::from_json(const json::Json& json) {
    ThermalZone zone{};

    zone.set_status(attribute::Status::from_json(json[literals::ThermalZone::STATUS]));
    zone.set_volumetric_airflow_cfm(json[literals::ThermalZone::VOLUMETRIC_AIRFLOW_CFM]);
    zone.set_desired_speed_pwm(json[literals::ThermalZone::DESIRED_SPEED_PWM]);
    zone.set_collections(Collections::from_json(json[literals::ThermalZone::COLLECTIONS]));
    zone.set_oem(attribute::Oem::from_json(json[literals::ThermalZone::OEM]));

    zone.set_chassis(json[literals::ThermalZone::CHASSIS]);   
    zone.set_tz_id(json[literals::ThermalZone::TZ_ID]);    
    zone.set_status_health(json[literals::ThermalZone::STATUS_HEALTH]);       
    zone.set_status_state(json[literals::ThermalZone::STATUS_STATE]);   
    zone.set_warning_temp(json[literals::ThermalZone::WARNING_TEMP]);       
    zone.set_error_temp(json[literals::ThermalZone::ERROR_TEMP]);       
    zone.set_shutdown_temp(json[literals::ThermalZone::SHUTDOWN_TEMP]); 
    zone.set_thermal_type(json[literals::ThermalZone::THERMAL_TYPE]);          
    zone.set_temperature(json[literals::ThermalZone::READINGCELSIUS]);          
    return zone;
}
