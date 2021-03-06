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
 *
 * @brief Declaration of PSU resource class
 * @file psu.hpp
 * */

#pragma once



#include "agent-framework/module/model/attributes/model_attributes.hpp"
#include "agent-framework/module/model/resource.hpp"
#include "agent-framework/module/enum/common.hpp"



namespace agent_framework {
namespace model {

class Psu : public Resource {
public:

    explicit Psu(const std::string& parent_uuid = {}, enums::Component parent_type = enums::Component::None);


    ~Psu();


    Psu(const Psu&) = default;


    Psu& operator=(const Psu&) = default;


    Psu(Psu&&) = default;


    Psu& operator=(Psu&&) = default;


    /*!
     * @brief construct an object of class Psu from JSON
     *
     * @param json the json::Json deserialized to object
     *
     * @return the newly constructed Psu object
     */
    static Psu from_json(const json::Json& json);


    /*!
     * @brief transform the object to JSon
     *
     * @return the object serialized to json::Json
     */
    json::Json to_json() const;


    static enums::CollectionName get_collection_name() {
        return Psu::collection_name;
    }


    static enums::Component get_component() {
        return Psu::component;
    }


    /*!
     * @brief Returns power supply type
     * @return Current value
     */
    const OptionalField<enums::PowerSupplyType>& get_power_supply_type() const {
        return m_power_supply_type;
    }


    /*!
     * @brief Sets power supply type
     * @param[in] power_supply_type New value
     */
    void set_power_supply_type(const OptionalField<enums::PowerSupplyType>& power_supply_type) {
        m_power_supply_type = power_supply_type;
    }


    /*!
     * @brief Returns line input voltage type
     * @return Current value
     */
    const OptionalField<enums::LineInputVoltageType>& get_line_input_voltage_type() const {
        return m_line_input_voltage_type;
    }


    /*!
     * @brief Sets line input voltage type
     * @param[in] line_input_voltage_type New value
     */
    void set_line_input_voltage_type(const OptionalField<enums::LineInputVoltageType>& line_input_voltage_type) {
        m_line_input_voltage_type = line_input_voltage_type;
    }


    /*!
     * @brief Returns line input voltage [V]
     * @return Current value
     */
    const OptionalField<double>& get_line_input_voltage_volts() const {
        return m_line_input_voltage_volts;
    }


    /*!
     * @brief Sets line input voltage [V]
     * @param[in] line_input_voltage_volts New value
     */
    void set_line_input_voltage_volts(const OptionalField<double>& line_input_voltage_volts) {
        m_line_input_voltage_volts = line_input_voltage_volts;
    }


    /*!
     * @brief Returns firmware version
     * @return Current value
     */
    const OptionalField<std::string>& get_firmware_version() const {
        return m_firmware_version;
    }


    /*!
     * @brief Sets firmware version
     * @param[in] firmware_version New value
     */
    void set_firmware_version(const OptionalField<std::string>& firmware_version) {
        m_firmware_version = firmware_version;
    }


    /*!
     * @brief Returns power_capacity_watts
     * @return Current value
     */
    const OptionalField<double>& get_power_capacity_watts() const {
        return m_power_capacity_watts;
    }


    /*!
     * @brief Sets power_capacity_watts
     * @param[in] power_capacity_watts New value
     */
    void set_power_capacity_watts(const OptionalField<double>& power_capacity_watts) {
        m_power_capacity_watts = power_capacity_watts;
    }


    /*!
     * @brief Returns last_power_output_watts
     * @return Current value
     */
    const OptionalField<double>& get_last_power_output_watts() const {
        return m_last_power_output_watts;
    }


    /*!
     * @brief Sets last_power_output_watts
     * @param[in] last_power_output_watts New value
     */
    void set_last_power_output_watts(const OptionalField<double>& last_power_output_watts) {
        m_last_power_output_watts = last_power_output_watts;
    }


    /*!
     * @brief return an object fru_info of class attribute::FruInfo
     *
     * @return the fru_info value
     * */
    const attribute::FruInfo& get_fru_info() const {
        return m_fru_info;
    }


    /*!
     * @brief setter for fru_info attribute
     *
     * @param fru_info of type attribute::FruInfo
     */
    void set_fru_info(const attribute::FruInfo& fru_info) {
        m_fru_info = fru_info;
    }

    /*!
     * @brief Gets slot id value
     * @return Slot id value
     */
    uint8_t get_slot_id() const {
        return m_slot_id;
    }

    /*!
     * @brief Sets slot id value
     * @param slot_id new slot id value
     */
    void set_slot_id(const uint8_t slot_id) {
        m_slot_id = slot_id;
    }

    /*!
     * @brief Return an indicator LED value of enum enums::IndicatorLed
     * @return The indicator LED value
     * */
    const OptionalField<enums::IndicatorLed>& get_indicator_led() const {
        return m_indicator_led;
    }


    /*!
     * @brief Setter for indicator LED
     * @param indicator_led Indicator LED of type enums::IndicatorLed
     */
    void set_indicator_led(const OptionalField<enums::IndicatorLed>& indicator_led) {
        m_indicator_led = indicator_led;
    }

    /*!
     * @brief setter for chassis attribute
     *
     * @param chassis of type std::string
     */
    void set_chassis(const OptionalField<std::string> &chassis)
    {
        m_chassis = chassis;
    }

    /*!
     * @brief return an object chassis of class std::string
     *
     * @return the chassis value
     */
    const OptionalField<std::string> &get_chassis() const
    {
        return m_chassis;
    }

    /*!
     * @brief setter for fan_id attribute
     *
     * @param fan_id of type uint32_t
     */
    void set_psu_id(const OptionalField<uint32_t> pz_id)
    {
        m_psu_id = pz_id;
    }

    /*!
     * @brief return pz_id of type std::uint32_t
     *
     * @return the pz_id value
     */
    OptionalField<std::uint32_t> get_psu_id() const
    {
        return m_psu_id;
    }

    /*!
     * @brief setter for status_health attribute
     *
     * @param status_health of type std::string
     */
    void set_status_health(const OptionalField<std::string> &status_health)
    {
        m_status_health = status_health;
    }

    /*!
     * @brief return an object status_health of class std::string
     *
     * @return the status_health value
     */
    const OptionalField<std::string> &get_status_health() const
    {
        return m_status_health;
    }

    /*!
     * @brief setter for status_state attribute
     *
     * @param status_state of type std::string
     */
    void set_status_state(const OptionalField<std::string> &status_state)
    {
        m_status_state = status_state;
    }

    /*!
     * @brief return an object status_state of class std::string
     *
     * @return the status_state value
     */
    const OptionalField<std::string> &get_status_state() const
    {
        return m_status_state;
    }

    /*!
     * @brief return current_input of type double
     *
     * @return the current_input value
     */
    OptionalField<double> get_current_input() const
    {
        return m_current_input;
    }

    /*!
     * @brief setter for current_input attribute
     *
     * @param current_input of type double
     */
    void set_current_input(const OptionalField<double> current_input)
    {
        m_current_input = current_input;
    }

    /*!
     * @brief return current_output of type double
     *
     * @return the current_output value
     */
    OptionalField<double> get_current_output() const
    {
        return m_current_output;
    }

    /*!
     * @brief setter for current_output attribute
     *
     * @param current_output of type double
     */
    void set_current_output(const OptionalField<double> current_output)
    {
        m_current_output = current_output;
    }

    /*!
     * @brief return voltage_input of type double
     *
     * @return the voltage_input value
     */
    OptionalField<double> get_voltage_input() const
    {
        return m_voltage_input;
    }

    /*!
     * @brief setter for voltage_input attribute
     *
     * @param voltage_input of type double
     */
    void set_voltage_input(const OptionalField<double> voltage_input)
    {
        m_voltage_input = voltage_input;
    }

    /*!
     * @brief return voltage_output of type double
     *
     * @return the voltage_output value
     */
    OptionalField<double> get_voltage_output() const
    {
        return m_voltage_output;
    }

    /*!
     * @brief setter for voltage_output attribute
     *
     * @param voltage_output of type double
     */
    void set_voltage_output(const OptionalField<double> voltage_output)
    {
        m_voltage_output = voltage_output;
    }

    /*!
     * @brief return psu_type of type double
     *
     * @return the psu_type value
     */
    OptionalField<int32_t> get_psu_type() const
    {
        return m_psu_type;
    }

    /*!
     * @brief setter for psu_type attribute
     *
     * @param psu_type of type double
     */
    void set_psu_type(const OptionalField<int32_t> psu_type)
    {
        m_psu_type = psu_type;
    }

    /*!
     * @brief setter for psu module attribute
     *
     * @param psu module of type std::string
     */
    void set_psu_module(const OptionalField<std::string> &psu_module)
    {
        m_module = psu_module;
    }

    /*!
     * @brief return an object status_health of class std::string
     *
     * @return the status_health value
     */
    const OptionalField<std::string> &get_psu_module() const
    {
        return m_module;
    }

    /*!
     * @brief setter for psu S/N attribute
     *
     * @param psu S/N of type std::string
     */
    void set_psu_sn(const OptionalField<std::string> &psu_sn)
    {
        m_sn = psu_sn;
    }

    /*!
     * @brief return an object psu S/N  of class std::string
     *
     * @return the psu S/N  value
     */
    const OptionalField<std::string> &get_psu_sn() const
    {
        return m_sn;
    }

    /*!
     * @brief return power_capacity of type double
     *
     * @return the power_capacity value
     */
    OptionalField<double> get_power_capacity() const
    {
        return m_power_capacity;
    }

    /*!
     * @brief setter for power_capacity attribute
     *
     * @param power_capacity of type double
     */
    void set_power_capacity(const OptionalField<double> power_capacity)
    {
        m_power_capacity = power_capacity;
    }

    /*!
     * @brief return power_input of type double
     *
     * @return the power_input value
     */
    OptionalField<double> get_power_input() const
    {
        return m_power_input;
    }

    /*!
     * @brief setter for power_input attribute
     *
     * @param power_input of type double
     */
    void set_power_input(const OptionalField<double> power_input)
    {
        m_power_input = power_input;
    }

    /*!
     * @brief return power_output of type double
     *
     * @return the power_output value
     */
    OptionalField<double> get_power_output() const
    {
        return m_power_output;
    }

    /*!
     * @brief setter for power_output attribute
     *
     * @param power_output of type double
     */
    void set_power_output(const OptionalField<double> power_output)
    {
        m_power_output = power_output;
    }

private:
    OptionalField<enums::PowerSupplyType> m_power_supply_type{};
    OptionalField<enums::LineInputVoltageType> m_line_input_voltage_type{};
    OptionalField<double> m_line_input_voltage_volts{};
    OptionalField<double> m_power_capacity_watts{};
    OptionalField<double> m_last_power_output_watts{};
    OptionalField<std::string> m_firmware_version{};
    OptionalField<enums::IndicatorLed> m_indicator_led{};
    attribute::FruInfo m_fru_info{};

    OptionalField<std::uint32_t> m_psu_id{0u}; 
    OptionalField<std::string> m_chassis{}; 
    OptionalField<std::string> m_status_health{};
    OptionalField<std::string> m_status_state{};	
    OptionalField<double> m_current_input{0.0};
    OptionalField<double> m_current_output{0.0};
    OptionalField<double> m_voltage_input{0.0};
    OptionalField<double> m_voltage_output{0.0};
    OptionalField<double> m_power_input{0.0};
    OptionalField<double> m_power_output{0.0};
    OptionalField<double> m_power_capacity{0.0};    
    OptionalField<int32_t> m_psu_type{-1};
    OptionalField<std::string> m_module{};
    OptionalField<std::string> m_sn{};
    // agent only data
    uint8_t m_slot_id{};    // physical slot id

    static const enums::CollectionName collection_name;
    static const enums::Component component;

};

}
}
