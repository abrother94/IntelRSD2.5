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
namespace agent {
namespace generic {

static constexpr const char DEFAULT_CONFIGURATION[] = R"({
    "service" : "rmm",
    "agent": {
        "vendor" : "Intel Corporation",
        "capabilities" : [ "Rmm" ]
    },
    "server": {
        "port": 7791
    },
    "registration": {
        "ipv4": "localhost",
        "port": 8383,
        "interval": 3
    },
    "certificate-files": {
        "podm" : "/etc/psme/certs/ca.crt"
    },
    "managers": [
        {
            "locationOffset": 0,
            "device": "/dev/ttyCm1IPMI"
        },
        {
            "locationOffset": 4,
            "device": "/dev/ttyCm2IPMI"
        }
    ],
    "database": {
        "location": "/var/opt/psme/rmm"
    },
    "loggers" : [
        {
            "name" : "rmm-agent",
            "level" : "DEBUG",
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
static constexpr const char DEFAULT_ENV_FILE[] = "AGENT_RMM_CONFIGURATION_FILE";

/*!
 * @brief Default configuration file to load when environment
 * isn't present or valid
 * */
static constexpr const char DEFAULT_FILE[] = "configuration.json";

}
}
