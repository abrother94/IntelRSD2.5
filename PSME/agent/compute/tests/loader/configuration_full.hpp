/*!
 * @brief Declaration of full configuration
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
 * @file configuration_full.hpp
 */

#pragma once
static constexpr const char COMPUTE_FULL_CONFIGURATION[] = R"({
    "service" : "compute",
    "agent": {
        "vendor" : "Intel Corporation",
        "capabilities" : [ "Compute" ]
    },
    "server": {
        "port": 7777
    },
    "registration": {
        "ipv4": "localhost",
        "port": 8383,
        "interval": 3
    },
    "managers": [
        {
            "slot" : 1,
            "ipv4": "172.17.8.165",
            "username": "put_username_hash_here",
            "password": "put_password_hash_here",
            "port": 623
        }
    ],
    "cyMux": {
        "ipv4": "127.0.0.1",
        "port": 5623
    },
    "database": {
        "location": "/var/opt/psme/compute"
    },
    "loggers" : [
        {
            "name" : "compute-agent",
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


