/*
 * Copyright (c) 2016-2019 Intel Corporation
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

package com.intel.rsd.nodecomposer.externalservices.resources.redfish;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.intel.rsd.nodecomposer.externalservices.OdataTypes;
import com.intel.rsd.nodecomposer.externalservices.resources.ExternalServiceResourceImpl;
import com.intel.rsd.nodecomposer.types.Status;
import lombok.Getter;

import static com.intel.rsd.redfish.ODataTypeVersions.VERSION_PATTERN;

@OdataTypes({
    "#VLanNetworkInterface" + VERSION_PATTERN + "VLanNetworkInterface"
})
public class EthernetSwitchPortVlanResource extends ExternalServiceResourceImpl {
    @Getter
    @JsonProperty("VLANId")
    private Integer vlanId;

    @JsonProperty("Oem")
    private Oem oem = new Oem();

    public Boolean getTagged() {
        return oem.rackScaleOem.tagged;
    }

    public Status getStatus() {
        return oem.rackScaleOem.status;
    }

    public class Oem {
        @JsonProperty("Intel_RackScale")
        private RackScaleOem rackScaleOem = new RackScaleOem();

        public class RackScaleOem {
            @JsonProperty("Tagged")
            private Boolean tagged;
            @JsonProperty("Status")
            private Status status;
        }
    }
}
