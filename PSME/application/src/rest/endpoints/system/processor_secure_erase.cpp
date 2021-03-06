/*!
 * @brief Implementation of secure erase endpoint for processor.
 *
 * @copyright Copyright (c) 2019 Intel Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License") override;
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License
 *
 * @file processor_secure_erase.cpp
 */


#include "agent-framework/module/requests/common.hpp"
#include "agent-framework/module/responses/common.hpp"
#include "psme/core/agent/agent_manager.hpp"
#include "psme/rest/validators/json_validator.hpp"
#include "psme/rest/validators/schemas/common.hpp"
#include "psme/rest/constants/constants.hpp"
#include "psme/rest/endpoints/system/processor_secure_erase.hpp"
#include "psme/rest/model/handlers/handler_manager.hpp"
#include "psme/rest/model/handlers/generic_handler_deps.hpp"
#include "psme/rest/model/handlers/generic_handler.hpp"
#include "psme/rest/endpoints/task_service/monitor_content_builder.hpp"
#include "psme/rest/endpoints/task_service/task_service_utils.hpp"



using namespace psme::rest;
using namespace psme::rest::constants;


endpoint::ProcessorSecureErase::ProcessorSecureErase(const std::string& path) : EndpointBase(path) {}


endpoint::ProcessorSecureErase::~ProcessorSecureErase() {}


void endpoint::ProcessorSecureErase::post(const server::Request& request, server::Response& response) {
    static const constexpr char TRANSACTION_NAME[] = "PostProcessorSecureErase";
    validators::JsonValidator::validate_empty_request(request);

    const auto processor = model::find<agent_framework::model::System, agent_framework::model::Processor>(
        request.params).get();

    if (!processor.get_processor_type().has_value() ||
        processor.get_processor_type().value() != agent_framework::model::enums::ProcessorType::FPGA) {
        throw agent_framework::exceptions::InvalidValue("This method is allowed for FPGA processors only.");
    }

    // Check whether the processor can be erased (is it's endpoint assigned to a zone)
    auto& endpoint_manager = agent_framework::module::get_manager<agent_framework::model::Endpoint>();
    auto& zone_endpoint_manager = agent_framework::module::CommonComponents::get_instance()->get_zone_endpoint_manager();
    for (const auto& endpoint_uuid : endpoint_manager.get_keys()) {
        if (agent_framework::model::Endpoint::has_entity(endpoint_uuid, processor.get_uuid())) {
            const auto endpoint_zones = zone_endpoint_manager.get_parents(endpoint_uuid);
            if (endpoint_zones.size() > 0) {
                throw agent_framework::exceptions::InvalidValue(
                    "The processor is an entity of endpoint "
                    + endpoint::utils::get_component_url(agent_framework::model::enums::Component::Endpoint,
                                                         endpoint_uuid)
                    + " which is assigned to zone "
                    + endpoint::utils::get_component_url(agent_framework::model::enums::Component::Zone,
                                                         endpoint_zones.front())
                    + ". You need to unbind it first."
                );
            }
        }
    }

    auto gami_agent = psme::core::agent::AgentManager::get_instance()->get_agent(processor.get_agent_id());

    agent_framework::model::attribute::Attributes attributes{};
    attributes.set_value(agent_framework::model::literals::Fpga::SECURELY_ERASE, true);
    agent_framework::model::requests::SetComponentAttributes
        set_component_attributes{processor.get_uuid(), attributes};

    // prepare response which will be presented on task completion
    auto response_renderer = [](json::Json) -> server::Response {
        server::Response res;
        res.set_status(server::status_2XX::NO_CONTENT);
        return res;
    };

    // reload processor resource (on task completion)
    auto update_on_completion = [processor](const std::string& task_uuid) {
        auto agent = psme::core::agent::AgentManager::get_instance()->get_agent(processor.get_agent_id());

        {
            auto task = agent_framework::module::get_manager<agent_framework::model::Task>()
                .get_entry_reference(task_uuid);
            if (task->get_state() == agent_framework::model::enums::TaskState::Completed) {
                task->set_messages(task_service_utils::build_success_message());
            }
        }

        psme::rest::model::handler::HandlerManager::get_instance()
            ->get_handler(agent_framework::model::enums::Component::Processor)
            ->load(agent, processor.get_parent_uuid(),
                   agent_framework::model::enums::Component::System, processor.get_uuid(), false);
    };

    auto secure_erase = [&, gami_agent] {
        // Secure Erase transaction - send GAMI request, then re-load processor resource or load received Task resource

        // Send EraseprocessorSecurely request
        auto set_component_attributes_response =
            gami_agent->execute<agent_framework::model::responses::SetComponentAttributes>(set_component_attributes);

        if (set_component_attributes_response.get_task().empty()) {
            psme::rest::model::handler::HandlerManager::get_instance()
                ->get_handler(agent_framework::model::enums::Component::Processor)
                ->load(gami_agent, processor.get_parent_uuid(),
                       agent_framework::model::enums::Component::System, processor.get_uuid(), false);

            response.set_status(server::status_2XX::NO_CONTENT);
        }
        else {
            const auto task_uuid = set_component_attributes_response.get_task();

            auto task_handler = psme::rest::model::handler::HandlerManager::get_instance()->get_handler(
                agent_framework::model::enums::Component::Task);
            task_handler->load(gami_agent,
                               "",
                               agent_framework::model::enums::Component::Task,
                               task_uuid,
                               false);
            MonitorContentBuilder::get_instance()->add_builder(task_uuid, response_renderer);

            {
                agent_framework::module::get_manager<agent_framework::model::Task>().get_entry_reference(task_uuid)
                    ->add_completion_notifier(std::bind(update_on_completion, task_uuid));
            }

            std::string task_monitor_url =
                PathBuilder(utils::get_component_url(agent_framework::model::enums::Component::Task, task_uuid))
                    .append(Monitor::MONITOR).build();
            psme::rest::endpoint::utils::set_location_header(request, response, task_monitor_url);
            response.set_body(psme::rest::endpoint::task_service_utils::call_task_get(task_uuid).get_body());
            response.set_status(server::status_2XX::ACCEPTED);
        }
    };

    gami_agent->execute_in_transaction(TRANSACTION_NAME, secure_erase);
}
