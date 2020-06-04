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

#include "agent-framework/registration/amc_connection_manager.hpp"
#include "agent-framework/signal.hpp"
#include "agent-framework/version.hpp"
#include "agent-framework/module/compute_components.hpp"
#include "agent-framework/module/common_components.hpp"
#include "agent-framework/eventing/utils.hpp"
#include "agent-framework/command/command_server.hpp"
#include "agent-framework/logger_loader.hpp"

#include "loader/acc_chassis_loader.hpp"
#include "database/database.hpp"

#include "onlp/watcher/get_onlp_info_task.hpp"
#include "onlp/watcher/watcher.hpp"

#include "configuration/configuration.hpp"
#include "configuration/configuration_validator.hpp"
#include "default_configuration.hpp"

#include "json-rpc/connectors/http_server_connector.hpp"
#include <csignal>

using namespace agent_framework;
using namespace agent_framework::generic;
using namespace agent::chassis;
using namespace logger_cpp;
using namespace configuration;
using namespace agent_framework::eventing;
using namespace agent::acc_chassis::onlp;

using agent::generic::DEFAULT_CONFIGURATION;
using agent::generic::DEFAULT_VALIDATOR_JSON;
using agent::generic::DEFAULT_ENV_FILE;
using agent::generic::DEFAULT_FILE;

using agent_framework::module::CommonComponents;

static constexpr unsigned int DEFAULT_SERVER_PORT = 7780;

const json::Json& init_configuration(int argc, const char** argv);
bool check_configuration(const json::Json& json);

/*!
 * @brief Generic Agent main method.
 * */
int main(int argc, const char* argv[]) {
    std::uint16_t server_port = DEFAULT_SERVER_PORT;

    /* Initialize configuration */
    const json::Json& configuration = ::init_configuration(argc, argv);
    if (!::check_configuration(configuration)) {
        return -1;
    }

    /* Initialize logger */
    LoggerLoader loader(configuration);
    loader.load(LoggerFactory::instance());
    log_info("chassis-agent", "Running Accton PSME Chassis ...");

    if (configuration.value("database", json::Json()).is_object() && configuration.value("database", json::Json::object()).value("location", json::Json()).is_string()) {
        database::Database::set_default_location(configuration["database"]["location"].get<std::string>());
    }

    try {
        server_port = configuration.value("server", json::Json::object()).value("port", std::uint16_t{});
    }
    catch (const std::exception& e) {
        log_error("chassis-agent", "Cannot read server port " << e.what());
    }

    agent::chassis::loader::Acc_ChassisLoader acc_module_loader{};
    if (!acc_module_loader.load(configuration))
    {
        log_error("chassis-agent", "Invalid modules configuration");
        return -2;
    }

    EventDispatcher event_dispatcher;
    event_dispatcher.start();

    RegistrationData registration_data{configuration};

    AmcConnectionManager amc_connection(event_dispatcher, registration_data);
    amc_connection.start();

    /* Initialize command server */
    auto http_server_connector = new json_rpc::HttpServerConnector(server_port, registration_data.get_ipv4_address());
    json_rpc::AbstractServerConnectorPtr http_server(http_server_connector);
    agent_framework::command::CommandServer server(http_server);
    server.add(command::Registry::get_instance()->get_commands());

    bool server_started = server.start();
    if (!server_started) {
        log_error("chassis-agent", "Could not start JSON-RPC command server on port "
            << server_port << " restricted to " << registration_data.get_ipv4_address()
            << ". " << "Quitting now...");
        amc_connection.stop();
        event_dispatcher.stop();
        return -3;
    }

    watcher::Watcher onlp_watcher{};
    onlp_watcher.add_task(std::make_shared<watcher::OnlpGetInfoTask>());
    onlp_watcher.start();

    wait_for_interrupt();
    log_info("chassis-agent", "Stopping Accton PSME Chassis Agent.");

    server.stop();
    amc_connection.stop();
    event_dispatcher.stop();
    Configuration::cleanup();
    LoggerFactory::cleanup();

    return 0;
}

const json::Json& init_configuration(int argc, const char** argv) {
    log_info("agent",
        agent_framework::generic::Version::build_info());
    auto& basic_config = Configuration::get_instance();
    basic_config.set_default_configuration(DEFAULT_CONFIGURATION);
    basic_config.set_default_file(DEFAULT_FILE);
    basic_config.set_default_env_file(DEFAULT_ENV_FILE);
    while (argc > 1) {
        basic_config.add_file(argv[argc - 1]);
        --argc;
    }
    basic_config.load_key_file();
    return basic_config.to_json();
}

bool check_configuration(const json::Json& json) {
    json::Json json_schema = json::Json();
    if (configuration::string_to_json(DEFAULT_VALIDATOR_JSON, json_schema)) {
        log_info("agent", "Loading configuration schema!");

        configuration::SchemaErrors errors;
        configuration::SchemaValidator validator;
        configuration::SchemaReader reader;
        reader.load_schema(json_schema, validator);

        validator.validate(json, errors);
        if (!errors.is_valid()) {
            std::cerr << "Configuration invalid: " <<
                         errors.to_string() << std::endl;
            return false;
        }
    }
    return true;
}
