/*!
 * @brief Endpoint Builder interface
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
 * @file endpoint_builder.hpp
 */


#pragma once

#include "agent-framework/module/model/endpoint.hpp"

namespace agent_framework {
namespace discovery {

class EndpointBuilder {
public:

    /*!
     * @brief Build default endpoint object.
     * @param[in] parent_uuid UUID of the parent component.
     * @return Default endpoint object.
     */
    static agent_framework::model::Endpoint build_default(const Uuid& parent_uuid);

    /*!
     * @brief Updates endpoint model with iSCSI protocol type.
     * @param[in,out] endpoint Endpoint to be updated.
     */
    static void iscsi_protocol(agent_framework::model::Endpoint& endpoint);


    /*!
     * @brief Updates endpoint model with NVMe over Fabric protocol type.
     * @param[in,out] endpoint Endpoint to be updated.
     */
    static void nvmeof_protocol(agent_framework::model::Endpoint& endpoint);

    /*!
     * @brief Updates endpoint model with FPGA over Fabric protocol type.
     * @param[in,out] endpoint Endpoint to be updated.
     */
    static void fpgaof_protocol(agent_framework::model::Endpoint& endpoint);

    /*!
     * @brief Update endpoint with initiator connected entity data.
     * @param[in,out] endpoint Endpoint to be updated.
     */
    static void add_initiator_connected_entity(agent_framework::model::Endpoint& endpoint);


    /*!
     * @brief Update endpoint with target connected entity data.
     * @param[in,out] endpoint Endpoint to be updated.
     * @param entity UUID of connected entity (like Volume, Drive, etc)
     */
    static void add_target_connected_entity(agent_framework::model::Endpoint& endpoint, const Uuid& entity);

};

}
}
