/*!
 * @brief Storage service discoverer implementation.
 *
 * @copyright Copyright (c) 2018-2019 Intel Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License") override;
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file storage_service_discoverer.cpp
 */

#include "agent-framework/discovery/discoverers/storage_service_discoverer.hpp"
#include "agent-framework/discovery/builders/storage_service_builder.hpp"

using namespace agent_framework::discovery;

agent_framework::model::StorageService StorageServiceDiscoverer::discover(const Uuid& parent_uuid) {
    auto storage_service = StorageServiceBuilder::build_default(parent_uuid);
    return storage_service;
}