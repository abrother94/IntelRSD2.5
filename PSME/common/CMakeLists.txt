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

# Add internal libraries & includes

add_subdirectory(include)
add_subdirectory(mdr)
add_subdirectory(md5)
add_subdirectory(uuid)
add_subdirectory(base64)
add_subdirectory(logger)
add_subdirectory(database)
add_subdirectory(ipmi)
add_subdirectory(json-cxx)
add_subdirectory(json)
add_subdirectory(json-rpc)
add_subdirectory(configuration)
add_subdirectory(iscsi)
add_subdirectory(optional)
add_subdirectory(agent-framework)
add_subdirectory(netlink)
add_subdirectory(smbios)
add_subdirectory(fru_eeprom)
add_subdirectory(net)
add_subdirectory(ssdp)
add_subdirectory(telemetry)
#add_subdirectory(nvme)
add_subdirectory(crc)
add_subdirectory(utils)
add_subdirectory(interface-reader)
add_subdirectory(sysfs)
#add_subdirectory(nvme-target)
add_subdirectory(partition)
#add_subdirectory(nvmf-discovery)
add_subdirectory(spdk)
add_subdirectory(udev)
add_subdirectory(pmem)
add_subdirectory(acpi)
add_subdirectory(tgt)
add_subdirectory(lvm)
#add_subdirectory(opaepp)

#For ONL/BAL/NET helper
add_subdirectory(acc_net_helper)
add_subdirectory(acc_sys_helper)
add_subdirectory(acc_onlp_helper)

IF("${CUSE_ACC_BAL3_DISTLIB}" STREQUAL "TRUE" )
    add_subdirectory(acc_bal3_api_dist_helper)
ENDIF()

