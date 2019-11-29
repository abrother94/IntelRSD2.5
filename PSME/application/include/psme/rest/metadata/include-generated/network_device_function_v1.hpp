#ifndef PSME_REST_METADATA_NETWORK_DEVICE_FUNCTION_V1_HPP
#define PSME_REST_METADATA_NETWORK_DEVICE_FUNCTION_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string NetworkDeviceFunction_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  NetworkDeviceFunction  v1.3.1-->
<!--#                                                                                      -->
<!--# For a detailed change log, see the README file contained in the DSP8010 bundle,      -->
<!--# available at http://www.dmtf.org/standards/redfish                                   -->
<!--# Copyright 2014-2018 DMTF.                                                            -->
<!--# For the full DMTF copyright policy, see http://www.dmtf.org/about/policies/copyright -->
<!--################################################################################       -->
<!---->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Capabilities.V1.xml">
    <edmx:Include Namespace="Org.OData.Capabilities.V1" Alias="Capabilities"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="Validation.v1_0_0" Alias="Validation"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Endpoint_v1.xml">
    <edmx:Include Namespace="Endpoint"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/NetworkPort_v1.xml">
    <edmx:Include Namespace="NetworkPort"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/PCIeFunction_v1.xml">
    <edmx:Include Namespace="PCIeFunction"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/VLanNetworkInterface_v1.xml">
    <edmx:Include Namespace="VLanNetworkInterface"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/VLanNetworkInterfaceCollection_v1.xml">
    <edmx:Include Namespace="VLanNetworkInterfaceCollection"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkDeviceFunction">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="NetworkDeviceFunction" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="The NetworkDeviceFunction schema represents a logical interface exposed by the network adapter."/>
        <Annotation Term="OData.LongDescription" String="A Network Device Function represents a logical interface exposed by the network adapter."/>
        <Annotation Term="Capabilities.InsertRestrictions">
          <Record>
            <PropertyValue Property="Insertable" Bool="false"/>
          </Record>
        </Annotation>
        <Annotation Term="Capabilities.UpdateRestrictions">
          <Record>
            <PropertyValue Property="Updatable" Bool="true"/>
            <Annotation Term="OData.Description" String="A Network Device Function can be updated to change properties such as WWN and MAC address information for this device."/>
          </Record>
        </Annotation>
        <Annotation Term="Capabilities.DeleteRestrictions">
          <Record>
            <PropertyValue Property="Deletable" Bool="false"/>
          </Record>
        </Annotation>
        <Annotation Term="Redfish.Uris">
          <Collection>
            <String>/redfish/v1/Chassis/{ChassisId}/NetworkAdapters/{NetworkAdapterId}/NetworkDeviceFunctions/{NetworkDeviceFunctionId}</String>
          </Collection>
        </Annotation>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkDeviceFunction.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2016.3"/>

      <EntityType Name="NetworkDeviceFunction" BaseType="NetworkDeviceFunction.NetworkDeviceFunction">
        <Annotation Term="OData.Description" String="A Network Device Function represents a logical interface exposed by the network adapter."/>
        <Annotation Term="OData.LongDescription" String="A Network Device Function represents a logical interface exposed by the network adapter."/>
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Description" String="This property describes the status and health of the resource and its children."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any status or health properties of the resource."/>
        </Property>
        <Property Name="NetDevFuncType" Type="NetworkDeviceFunction.v1_0_0.NetworkDeviceTechnology">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The configured capability of this network device function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the configured capability of this network device function."/>
        </Property>
        <Property Name="DeviceEnabled" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Whether the network device function is enabled."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a boolean indicating whether the network device function is enabled.  Disabled network device functions shall not be enumerated or seen by the operating system."/>
        </Property>
        <Property Name="NetDevFuncCapabilities" Type="Collection(NetworkDeviceFunction.v1_0_0.NetworkDeviceTechnology)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Capabilities of this network device function."/>
          <Annotation Term="OData.LongDescription" String="This object shall contain an array of capabilities of this network device function."/>
        </Property>
        <Property Name="Ethernet" Type="NetworkDeviceFunction.v1_0_0.Ethernet">
          <Annotation Term="OData.Description" String="Ethernet."/>
          <Annotation Term="OData.LongDescription" String="This object shall contain Ethernet capabilities, status, and configuration values for this network device function."/>
        </Property>
        <Property Name="iSCSIBoot" Type="NetworkDeviceFunction.v1_0_0.iSCSIBoot">
          <Annotation Term="OData.Description" String="iSCSI Boot."/>
          <Annotation Term="OData.LongDescription" String="This object shall contain iSCSI boot capabilities, status, and configuration values for this network device function."/>
        </Property>
        <Property Name="FibreChannel" Type="NetworkDeviceFunction.v1_0_0.FibreChannel">
          <Annotation Term="OData.Description" String="Fibre Channel."/>
          <Annotation Term="OData.LongDescription" String="This object shall contain Fibre Channel capabilities, status, and configuration values for this network device function."/>
        </Property>
        <NavigationProperty Name="AssignablePhysicalPorts" Type="Collection(NetworkPort.NetworkPort)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The array of physical port references that this network device function may be assigned to."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of physical port references that this network device function may be assigned to."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="PhysicalPortAssignment" Type="NetworkPort.NetworkPort" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The physical port that this network device function is currently assigned to."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the physical port that this network device function is currently assigned to. This value shall be one of the AssignablePhysicalPorts array members."/>
          <Annotation Term="OData.AutoExpandReferences"/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Deprecated"/>
                <PropertyValue Property="Version" String="v1_3_0"/>
                <PropertyValue Property="Description" String="This property has been deprecated and moved to the Links section to avoid loops on expand."/>
              </Record>
            </Collection>
          </Annotation>
        </NavigationProperty>
        <Property Name="BootMode" Type="NetworkDeviceFunction.v1_0_0.BootMode">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The boot mode configured for this network device function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the boot mode configured for this network device function.  If the value is not quot;Disabled&quot;, this network device function shall be configured for boot using the specified technology."/>
        </Property>
        <Property Name="VirtualFunctionsEnabled" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Whether Single Root I/O Virtualization (SR-IOV) Virual Functions (VFs) are enabled for this Network Device Function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a boolean indicating whether Single Root I/O Virtualization (SR-IOV) Virual Functions (VFs) are enabled for this Network Device Function."/>
        </Property>
        <Property Name="MaxVirtualFunctions" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The number of virtual functions (VFs) that are available for this Network Device Function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the number of virtual functions (VFs) that are available for this Network Device Function."/>
        </Property>
        <Property Name="Links" Type="NetworkDeviceFunction.v1_0_0.Links" Nullable="false">
          <Annotation Term="OData.Description" String="Links."/>
          <Annotation Term="OData.LongDescription" String="Links for this NetworkDeviceFunction."/>
        </Property>
      </EntityType>

      <ComplexType Name="FibreChannel">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This type describes Fibre Channel capabilities, status, and configuration of a network device function."/>
        <Annotation Term="OData.LongDescription" String="This object shall describe the Fibre Channel capabilities, status, and configuration values for a network device function."/>
        <Property Name="PermanentWWPN" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the permanent WWPN address assigned to this network device function (physical function)."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the permanent World-Wide Port Name (WWPN) of this network device function (physical function). This value is typically programmed during the manufacturing time. This address is not assignable."/>
        </Property>
        <Property Name="PermanentWWNN" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the permanent WWNN address assigned to this network device function (physical function)."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the permanent World-Wide Node Name (WWNN) of this network device function (physical function). This value is typically programmed during the manufacturing time. This address is not assignable."/>
        </Property>
        <Property Name="WWPN" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This is the currently configured WWPN address of the network device function (physical function)."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the effective current World-Wide Port Name (WWPN) of this network device function (physical function). If an assignable WWPN is not supported, this is a read only alias of the PermanentWWPN."/>
        </Property>
        <Property Name="WWNN" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This is the currently configured WWNN address of the network device function (physical function)."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the effective current World-Wide Node Name (WWNN) of this network device function (physical function). If an assignable WWNN is not supported, this is a read only alias of the PermanentWWNN."/>
        </Property>
        <Property Name="WWNSource" Type="NetworkDeviceFunction.v1_0_0.WWNSource">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The configuration source of the WWNs for this connection (WWPN and WWNN)."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the configuration source of the World-Wide Names (WWNs) for this connection (WWPN and WWNN)."/>
        </Property>
        <Property Name="FCoELocalVLANId" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The locally configured FCoE VLAN ID."/>
          <Annotation Term="OData.LongDescription" String="For FCoE connections, the value of this property shall be the VLAN ID configured locally by setting this property.  This value shall be used for FCoE traffic to this network device function during boot unless AllowFIPVLANDiscovery is true and a valid FCoE VLAN ID is found via the FIP VLAN Discovery Protocol."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Validation.Maximum" Int="4094"/>
        </Property>
        <Property Name="AllowFIPVLANDiscovery" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Whether the FCoE Initialization Protocol (FIP) is used for populating the FCoE VLAN Id."/>
          <Annotation Term="OData.LongDescription" String="For FCoE connections, the value of this property shall be a boolean indicating whether the FIP VLAN Discovery Protocol is used to determine the FCoE VLAN ID selected by the network device function for the FCoE connection.  If true, and the FIP VLAN Discovery succeeds, the FCoEActiveVLANId property shall reflect the FCoE VLAN ID to be used for all FCoE traffic.  If false, or if the FIP VLAN Discovery protocol fails, the FCoELocalVLANId shall be used for all FCoE traffic and the FCoEActiveVLANId shall reflect the FCoELocalVLANId."/>
        </Property>
        <Property Name="FCoEActiveVLANId" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The active FCoE VLAN ID."/>
          <Annotation Term="OData.LongDescription" String="For FCoE connections, the value of this property shall be null or a VLAN ID currently being used for FCoE traffic.  When the FCoE link is down this value shall be null.  When the FCoE link is up this value shall be either the FCoELocalVLANId property or a VLAN discovered via the FIP protocol."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Validation.Maximum" Int="4094"/>
        </Property>
        <Property Name="BootTargets" Type="Collection(NetworkDeviceFunction.v1_0_0.BootTargets)">
          <Annotation Term="OData.Description" String="An array of Fibre Channel boot targets configured for this network device function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of Fibre Channel boot targets configured for this network device function."/>
        </Property>
      </ComplexType>

      <ComplexType Name="Ethernet">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This type describes Ethernet capabilities, status, and configuration of a network device function."/>
        <Annotation Term="OData.LongDescription" String="This type shall describe the Ethernet capabilities, status, and configuration values for a network device function."/>
        <Property Name="PermanentMACAddress" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the permanent MAC address assigned to this network device function (physical function)."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the Permanent MAC Address of this network device function (physical function). This value is typically programmed during the manufacturing time. This address is not assignable."/>
        </Property>
        <Property Name="MACAddress" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This is the currently configured MAC address of the (logical port) network device function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the effective current MAC Address of this network device function. If an assignable MAC address is not supported, this is a read only alias of the PermanentMACAddress."/>
        </Property>
        <Property Name="MTUSize" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The Maximum Transmission Unit (MTU) configured for this network device function."/>
          <Annotation Term="OData.LongDescription" String="The Maximum Transmission Unit (MTU) configured for this Network Device Function.  This value serves as a default for the OS driver when booting.  The value only takes-effect on boot."/>
        </Property>
      </ComplexType>

      <ComplexType Name="Links">
        <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
        <Annotation Term="OData.LongDescription" String="This type, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        <NavigationProperty Name="PCIeFunction" Type="PCIeFunction.PCIeFunction" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the PCIeFunction associated with this Network Device Function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a references of type PCIeFunction that represents the PCI-e Function associated with this Network Device Function."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="iSCSIBoot">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This type describes iSCSI boot capabilities, status, and configuration of a network device function."/>
        <Annotation Term="OData.LongDescription" String="This type shall describe the iSCSI boot capabilities, status, and configuration values for a network device function."/>
        <Property Name="IPAddressType" Type="NetworkDeviceFunction.v1_0_0.IPAddressType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The type of IP address (IPv6 or IPv4) being populated in the iSCSIBoot IP address fields."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall behe type of IP address (IPv6 or IPv4) being populated in the iSCSIBoot IP address fields.  Mixing of IPv6 and IPv4 addresses on the same network device function shall not be permissible."/>
        </Property>
        <Property Name="InitiatorIPAddress" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The IPv6 or IPv4 address of the iSCSI initiator."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the IPv6 or IPv4 address of the iSCSI boot initiator."/>
        </Property>
        <Property Name="InitiatorName" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The iSCSI initiator name."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the iSCSI boot initiator name.  The value of this property should match formats defined in RFC3720 or RFC3721."/>
        </Property>
        <Property Name="InitiatorDefaultGateway" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The IPv6 or IPv4 iSCSI boot default gateway."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the IPv6 or IPv4 iSCSI boot default gateway."/>
        </Property>
        <Property Name="InitiatorNetmask" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The IPv6 or IPv4 netmask of the iSCSI boot initiator."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the IPv6 or IPv4 netmask of the iSCSI boot initiator."/>
        </Property>
        <Property Name="TargetInfoViaDHCP" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Whether the iSCSI boot target name, LUN, IP address, and netmask should be obtained from DHCP."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a boolean indicating whether the iSCSI boot target name, LUN, IP address, and netmask should be obtained from DHCP."/>
        </Property>
        <Property Name="PrimaryTargetName" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The name of the iSCSI primary boot target."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the name of the primary iSCSI boot target.  The value of this property should match formats defined in RFC3720 or RFC3721."/>
        </Property>
        <Property Name="PrimaryTargetIPAddress" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The IP address (IPv6 or IPv4) for the primary iSCSI boot target."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the IP address (IPv6 or IPv4) for the primary iSCSI boot target."/>
        </Property>
        <Property Name="PrimaryTargetTCPPort" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The TCP port for the primary iSCSI boot target."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the TCP port for the primary iSCSI boot target."/>
        </Property>
        <Property Name="PrimaryLUN" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The logical unit number (LUN) for the primary iSCSI boot target."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the logical unit number (LUN) for the primary iSCSI boot target."/>
        </Property>
        <Property Name="PrimaryVLANEnable" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This indicates if the primary VLAN is enabled."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be used to indicate if this VLAN is enabled for the primary iSCSI boot target."/>
        </Property>
        <Property Name="PrimaryVLANId" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The 802.1q VLAN ID to use for iSCSI boot from the primary target."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the 802.1q VLAN ID to use for iSCSI boot from the primary target.  This VLAN ID is only used if PrimaryVLANEnable is true."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Validation.Maximum" Int="4094"/>
        </Property>
        <Property Name="PrimaryDNS" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The IPv6 or IPv4 address of the primary DNS server for the iSCSI boot initiator."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the IPv6 or IPv4 address of the primary DNS server for the iSCSI boot initiator."/>
        </Property>
        <Property Name="SecondaryTargetName" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The name of the iSCSI secondary boot target."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the name of the secondary iSCSI boot target.  The value of this property should match formats defined in RFC3720 or RFC3721."/>
        </Property>
        <Property Name="SecondaryTargetIPAddress" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The IP address (IPv6 or IPv4) for the secondary iSCSI boot target."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the IP address (IPv6 or IPv4) for the secondary iSCSI boot target."/>
        </Property>
        <Property Name="SecondaryTargetTCPPort" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The TCP port for the secondary iSCSI boot target."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the TCP port for the secondary iSCSI boot target."/>
        </Property>
        <Property Name="SecondaryLUN" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The logical unit number (LUN) for the secondary iSCSI boot target."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the logical unit number (LUN) for the secondary iSCSI boot target."/>
        </Property>
        <Property Name="SecondaryVLANEnable" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This indicates if the secondary VLAN is enabled."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be used to indicate if this VLAN is enabled for the secondary iSCSI boot target."/>
        </Property>
        <Property Name="SecondaryVLANId" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The 802.1q VLAN ID to use for iSCSI boot from the secondary target."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the 802.1q VLAN ID to use for iSCSI boot from the secondary target.  This VLAN ID is only used if SecondaryVLANEnable is true."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Validation.Maximum" Int="4094"/>
        </Property>
        <Property Name="SecondaryDNS" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The IPv6 or IPv4 address of the secondary DNS server for the iSCSI boot initiator."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the IPv6 or IPv4 address of the secondary DNS server for the iSCSI boot initiator."/>
        </Property>
        <Property Name="IPMaskDNSViaDHCP" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Whether the iSCSI boot initiator uses DHCP to obtain the iniator name, IP address, and netmask."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a boolean indicating whether the iSCSI boot initiator uses DHCP to obtain the iniator name, IP address, and netmask."/>
        </Property>
        <Property Name="RouterAdvertisementEnabled" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Whether IPv6 router advertisement is enabled for the iSCSI boot target."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a boolean indicating whether IPv6 router advertisement is enabled for the iSCSI boot target.  This setting shall only apply to IPv6 configurations."/>
        </Property>
        <Property Name="AuthenticationMethod" Type="NetworkDeviceFunction.v1_0_0.AuthenticationMethod">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The iSCSI boot authentication method for this network device function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the iSCSI boot authentication method for this network device function."/>
        </Property>
        <Property Name="CHAPUsername" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The username for CHAP authentication."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall behe username for CHAP authentication."/>
        </Property>
        <Property Name="CHAPSecret" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The shared secret for CHAP authentication."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the shared secret for CHAP authentication."/>
        </Property>
        <Property Name="MutualCHAPUsername" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The CHAP Username for 2-way CHAP authentication."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the CHAP Username for 2-way CHAP authentication."/>
        </Property>
        <Property Name="MutualCHAPSecret" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The CHAP Secret for 2-way CHAP authentication."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the CHAP Secret for 2-way CHAP authentication."/>
        </Property>
      </ComplexType>

      <ComplexType Name="BootTargets">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="A Fibre Channel boot target configured for a network device function."/>
        <Annotation Term="OData.LongDescription" String="This type shall describe a Fibre Channel boot target configured for a network device function."/>
        <Property Name="WWPN" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The World-Wide Port Name to boot from."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be World-Wide Port Name (WWPN) to boot from."/>
        </Property>
        <Property Name="LUNID" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The Logical Unit Number (LUN) ID to boot from on the device referred to by the corresponding WWPN."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the Logical Unit Number (LUN) ID to boot from on the device referred to by the corresponding WWPN."/>
        </Property>
        <Property Name="BootPriority" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The relative priority for this entry in the boot targets array."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the relative priority for this entry in the boot targets array.  Lower numbers shall represent higher priority, with zero being the highest priority.  The BootPriority shall be unique for all entries of the BootTargets array."/>
        </Property>
      </ComplexType>

      <EnumType Name="NetworkDeviceTechnology">
        <Member Name="Disabled">
          <Annotation Term="OData.Description" String="Neither enumerated nor visible to the operating system." />
        </Member>
        <Member Name="Ethernet">
          <Annotation Term="OData.Description" String="Appears to the operating system as an Ethernet device." />
        </Member>
        <Member Name="FibreChannel">
          <Annotation Term="OData.Description" String="Appears to the operating system as a Fibre Channel device." />
        </Member>
        <Member Name="iSCSI">
          <Annotation Term="OData.Description" String="Appears to the operating system as an iSCSI device." />
        </Member>
        <Member Name="FibreChannelOverEthernet">
          <Annotation Term="OData.Description" String="Appears to the operating system as an FCoE device." />
        </Member>
      </EnumType>

      <EnumType Name="IPAddressType">
        <Member Name="IPv4">
          <Annotation Term="OData.Description" String="IPv4 addressing is used for all IP-fields in this object." />
        </Member>
        <Member Name="IPv6">
          <Annotation Term="OData.Description" String="IPv6 addressing is used for all IP-fields in this object." />
        </Member>
      </EnumType>

      <EnumType Name="AuthenticationMethod">
        <Member Name="None">
          <Annotation Term="OData.Description" String="No iSCSI authentication is used." />
        </Member>
        <Member Name="CHAP">
          <Annotation Term="OData.Description" String="iSCSI Challenge Handshake Authentication Protocol (CHAP) authentication is used." />
        </Member>
        <Member Name="MutualCHAP">
          <Annotation Term="OData.Description" String="iSCSI Mutual Challenge Handshake Authentication Protocol (CHAP) authentication is used." />
        </Member>
      </EnumType>

      <EnumType Name="WWNSource">
        <Member Name="ConfiguredLocally">
          <Annotation Term="OData.Description" String="The set of FC/FCoE boot targets was applied locally through API or UI." />
        </Member>
        <Member Name="ProvidedByFabric">
          <Annotation Term="OData.Description" String="The set of FC/FCoE boot targets was applied by the Fibre Channel fabric." />
        </Member>
      </EnumType>

      <EnumType Name="BootMode">
        <Member Name="Disabled">
          <Annotation Term="OData.Description" String="Do not indicate to UEFI/BIOS that this device is bootable." />
        </Member>
        <Member Name="PXE">
          <Annotation Term="OData.Description" String="Boot this device using the embedded PXE support.  Only applicable if the NetworkDeviceFunctionType is set to Ethernet." />
        </Member>
        <Member Name="iSCSI">
          <Annotation Term="OData.Description" String="Boot this device using the embedded iSCSI boot support and configuration.  Only applicable if the NetworkDeviceFunctionType is set to iSCSI." />
        </Member>
        <Member Name="FibreChannel">
          <Annotation Term="OData.Description" String="Boot this device using the embedded Fibre Channel support and configuration.  Only applicable if the NetworkDeviceFunctionType is set to FibreChannel." />
        </Member>
        <Member Name="FibreChannelOverEthernet">
          <Annotation Term="OData.Description" String="Boot this device using the embedded Fibre Channel over Ethernet (FCoE) boot support and configuration.  Only applicable if the NetworkDeviceFunctionType is set to FibreChannelOverEthernet." />
        </Member>
      </EnumType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkDeviceFunction.v1_0_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to remove the Nullable facet on NavigationProperties of type Collection."/>
      <EntityType Name="NetworkDeviceFunction" BaseType="NetworkDeviceFunction.v1_0_0.NetworkDeviceFunction"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkDeviceFunction.v1_0_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add normative statements about the format of InitiatorName, PrimaryTargetName, and SecondaryTargetName properties in the iSCSIBoot structure.  It was also created to fix the descriptions for AssignablePhysicalPorts and PhysicalPortAssignment."/>
      <EntityType Name="NetworkDeviceFunction" BaseType="NetworkDeviceFunction.v1_0_1.NetworkDeviceFunction"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkDeviceFunction.v1_0_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="NetworkDeviceFunction" BaseType="NetworkDeviceFunction.v1_0_2.NetworkDeviceFunction"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkDeviceFunction.v1_0_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="NetworkDeviceFunction" BaseType="NetworkDeviceFunction.v1_0_3.NetworkDeviceFunction"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkDeviceFunction.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.1"/>
      <EntityType Name="NetworkDeviceFunction" BaseType="NetworkDeviceFunction.v1_0_1.NetworkDeviceFunction">
        <Property Name="Actions" Type="NetworkDeviceFunction.v1_1_0.Actions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="NetworkDeviceFunction.v1_1_0.OemActions" Nullable="false">
          <Annotation Term="OData.Description" String="This property contains the available OEM specific actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any additional OEM actions for this resource."/>
        </Property>
      </ComplexType>

      <ComplexType Name="OemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
        <Annotation Term="OData.Description" String="The available OEM specific actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain any additional OEM actions for this resource."/>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkDeviceFunction.v1_1_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add normative statements about the format of InitiatorName, PrimaryTargetName, and SecondaryTargetName properties in the iSCSIBoot structure.  It was also created to fix the descriptions for AssignablePhysicalPorts and PhysicalPortAssignment."/>
      <EntityType Name="NetworkDeviceFunction" BaseType="NetworkDeviceFunction.v1_1_0.NetworkDeviceFunction"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkDeviceFunction.v1_1_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="NetworkDeviceFunction" BaseType="NetworkDeviceFunction.v1_1_1.NetworkDeviceFunction"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkDeviceFunction.v1_1_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="NetworkDeviceFunction" BaseType="NetworkDeviceFunction.v1_1_2.NetworkDeviceFunction"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkDeviceFunction.v1_2_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.3"/>
      <EntityType Name="NetworkDeviceFunction" BaseType="NetworkDeviceFunction.v1_1_1.NetworkDeviceFunction"/>
      <ComplexType Name="Links" BaseType="NetworkDeviceFunction.v1_0_0.Links">
        <NavigationProperty Name="Endpoints" Type="Collection(Endpoint.Endpoint)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to endpoints associated with this network device function."/>
          <Annotation Term="OData.LongDescription" String="The type shall contain an array property who's members reference resources, of type Endpoint, which are associated with this network device function."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkDeviceFunction.v1_2_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add validation terms to the different VLANId properties."/>
      <EntityType Name="NetworkDeviceFunction" BaseType="NetworkDeviceFunction.v1_2_0.NetworkDeviceFunction"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkDeviceFunction.v1_2_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="NetworkDeviceFunction" BaseType="NetworkDeviceFunction.v1_2_1.NetworkDeviceFunction"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkDeviceFunction.v1_2_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="NetworkDeviceFunction" BaseType="NetworkDeviceFunction.v1_2_2.NetworkDeviceFunction"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkDeviceFunction.v1_3_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.2"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number.  Also adds support for VLAN to Ethernet. Also moving PhysicalPortAssignment to Links.  Also adds FibreChannel Adapter properties."/>
      <EntityType Name="NetworkDeviceFunction" BaseType="NetworkDeviceFunction.v1_2_2.NetworkDeviceFunction"/>
      <ComplexType Name="Links" BaseType="NetworkDeviceFunction.v1_2_0.Links">
        <NavigationProperty Name="PhysicalPortAssignment" Type="NetworkPort.NetworkPort" Nullable="false">
          <Annotation Term="OData.Description" String="The physical port that this network device function is currently assigned to."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the physical port that this network device function is currently assigned to. This value shall be one of the AssignablePhysicalPorts array members."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>
      <ComplexType Name="Ethernet" BaseType="NetworkDeviceFunction.v1_0_0.Ethernet">
        <Property Name="VLAN" Type="VLanNetworkInterface.VLAN">
          <Annotation Term="OData.Description" String="If this Network Interface supports more than one VLAN, this property is not present. VLANs collections appear in the Link section of this resource."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the VLAN for this interface.  If this interface supports more than one VLAN, the VLAN property shall not be present and the VLANS collection link shall be present instead."/>
        </Property>
        <NavigationProperty Name="VLANs" Type="VLanNetworkInterfaceCollection.VLanNetworkInterfaceCollection" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a reference to a collection of VLANs and is only used if the interface supports more than one VLANs."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall reference a collection of VLAN resources. If this property is used, the VLANEnabled and VLANId property shall not be used."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>
      <ComplexType Name="FibreChannel" BaseType="NetworkDeviceFunction.v1_0_0.FibreChannel">
        <Property Name="FibreChannelId" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Fibre Channel Id assigned by the switch for this interface."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the Fibre Channel Id assigned by the switch for this interface."/>
        </Property>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkDeviceFunction.v1_3_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="NetworkDeviceFunction" BaseType="NetworkDeviceFunction.v1_3_0.NetworkDeviceFunction"/>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_NETWORK_DEVICE_FUNCTION_V1_HPP */
