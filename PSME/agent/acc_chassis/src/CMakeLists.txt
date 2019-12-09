# <license_header>
#
# Copyright (c) 2015-2019 Intel Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# </license_header>
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(command)
add_subdirectory(onlp)
add_subdirectory(loader)


add_library(acc-chassis-commands STATIC
        $<TARGET_OBJECTS:chassis-command-acc>
)

add_library(acc-chassis-loader-lib
        $<TARGET_OBJECTS:acc-chassis-loader>
)

add_library(acc-onlp-watcher
        $<TARGET_OBJECTS:onlp-watcher>
)

add_executable(acc-psme-chassis
    main.cpp
)

generate_default_config_file(
    main.cpp
    agent
    generic
    "AGENT_CHASSIS_CONFIGURATION_FILE"
    ../include/default_configuration.hpp
    ..
)

target_link_libraries(acc-psme-chassis
    ${AGENT_ACC_CHASSIS_LIBRARIES}
    acc-chassis-loader-lib
    acc-onlp-watcher
    agent-framework
    uuid
    logger
    ${SAFESTRING_LIBRARIES}
    configuration
    base64
    pthread
    ${MICROHTTPD_LIBRARIES}
    ${CURL_LIBRARIES}
    ${NET_LIBRARIES}
    ${SAFESTRING_LIBRARIES}
    md5
)
