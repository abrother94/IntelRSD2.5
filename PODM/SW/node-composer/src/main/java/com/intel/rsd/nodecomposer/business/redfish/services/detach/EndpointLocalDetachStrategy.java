/*
 * Copyright (c) 2019 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.intel.rsd.nodecomposer.business.redfish.services.detach;

import com.intel.rsd.nodecomposer.business.BusinessApiException;
import com.intel.rsd.nodecomposer.business.redfish.services.helpers.AttachDetachOperationContext;
import com.intel.rsd.nodecomposer.discovery.external.partial.ZoneObtainer;
import com.intel.rsd.nodecomposer.persistence.redfish.ComposedNode;
import com.intel.rsd.nodecomposer.persistence.redfish.Endpoint;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class EndpointLocalDetachStrategy implements LocalDetachStrategy<Endpoint> {

    private final ZoneObtainer zoneObtainer;

    @Autowired
    public EndpointLocalDetachStrategy(ZoneObtainer zoneObtainer) {
        this.zoneObtainer = zoneObtainer;
    }

    @Override
    public void deallocate(ComposedNode composedNode, Endpoint endpoint) {
        composedNode.deallocate(endpoint);
        endpoint.getProcessors().forEach(composedNode::deallocate);
        endpoint.getVolumes().forEach(composedNode::deallocate);
        endpoint.getDrives().forEach(composedNode::deallocate);

    }

    @Override
    public void updateFabricModel(ComposedNode composedNode, Endpoint resource, AttachDetachOperationContext context) throws BusinessApiException {
        if (context.getFabricODataId() != null && context.getRelatedZoneODataId() != null) {
            zoneObtainer.discoverZone(context.getFabricODataId().toUri(), context.getRelatedZoneODataId().toUri());
        }
    }

    @Override
    public void onAfterLocalDetach(ComposedNode composedNode, Endpoint endpoint) {
        endpoint.getDrives().forEach(drive -> drive.setDriveErased(false));
        endpoint.getProcessors().forEach(processor -> processor.setProcessorErased(false));
    }
}
