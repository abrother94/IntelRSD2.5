/*!
 * @brief Application default configuration
 *
 * @copyright Copyright (c) 2018-2019 Intel Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file default_configuration.hpp
 */

#pragma once
namespace psme {
namespace app {

static constexpr const char DEFAULT_CONFIGURATION[] = R"({
    "service" : "rest-server",
    "server": {
        "network-interface-name" : ["enp0s20f0.4094"],
        "connectors" : [
            {
                "use-ssl" : true,
                "certs-directory" : "/etc/psme/certs",
                "port": 8443,
                "thread-mode" : "select",
                "client-cert-required" : true,
                "authentication-type" : "basic-or-session"
            },
            {
                "use-ssl" : false,
                "port": 8888,
                "redirect-port" : 8443,
                "thread-mode" : "select",
                "thread-pool-size" : 1,
                "authentication-type" : "none"
            }
        ]
    },
    "event-service" : {
        "delivery-retry-attempts" : 3,
        "delivery-retry-interval-seconds" : 60
    },
    "authentication" : {
        "username" : "root",
        "password" : "put_password_hash_here"
    },
    "session-service" : {
        "service-enabled" : true,
        "session-timeout" : 30
    },
    "ssdp-service" : {
        "enabled" : true,
        "announce-interval-seconds" : 0,
        "ttl" : 2
    },
    "rmm-present" : true,
    "registration": {
        "port": 8383,
        "minDelay": 3
    },
    "eventing" : {
        "address": "localhost",
        "port" : 5567,
        "poll-interval-sec" : 200
    },
    "rest" : {
        "service-root-name" : "PSME Service Root"
    },
    "database": {
        "location": "/var/opt/psme",
        "retention-interval-sec": 600,
        "retention-outdated-sec": 2419200
    },
    "loggers" : [
        {
            "name" : "app",
            "level" : "INFO",
            "timeformat" : "DATE_NS",
            "color" : true,
            "output" : true,
            "tagging" : true,
            "moredebug" : false,
            "streams" : [
                {
                    "type" : "STDOUT"
                }
            ]
        }
    ]
}
)";

static constexpr char DEFAULT_VALIDATOR_JSON[] = R"({ })";

/*! @brief Default environment variable for configuration file */
static constexpr const char DEFAULT_ENV_FILE[] = "CORE_CONFIGURATION_FILE";

/*!
 * @brief Default configuration file to load when environment
 * isn't present or valid
 * */
static constexpr const char DEFAULT_FILE[] = "configuration.json";

}
}
