#ifndef PSME_REST_METADATA_NETWORK_ADAPTER_V1_HPP
#define PSME_REST_METADATA_NETWORK_ADAPTER_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string NetworkAdapter_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  NetworkAdapter  v1.2.0-->
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
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/NetworkPortCollection_v1.xml">
    <edmx:Include Namespace="NetworkPortCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/NetworkPort_v1.xml">
    <edmx:Include Namespace="NetworkPort"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/NetworkDeviceFunctionCollection_v1.xml">
    <edmx:Include Namespace="NetworkDeviceFunctionCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/NetworkDeviceFunction_v1.xml">
    <edmx:Include Namespace="NetworkDeviceFunction"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/PCIeDevice_v1.xml">
    <edmx:Include Namespace="PCIeDevice"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Assembly_v1.xml">
    <edmx:Include Namespace="Assembly"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkAdapter">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="NetworkAdapter" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="A NetworkAdapter represents the physical network adapter capable of connecting to a computer network.  Examples include but are not limited to Ethernet, Fibre Channel, and converged network adapters."/>
        <Annotation Term="OData.LongDescription" String="A NetworkAdapter represents the physical network adapter capable of connecting to a computer network.  Examples include but are not limited to Ethernet, Fibre Channel, and converged network adapters."/>
        <Annotation Term="Capabilities.InsertRestrictions">
          <Record>
            <PropertyValue Property="Insertable" Bool="false"/>
          </Record>
        </Annotation>
        <Annotation Term="Capabilities.UpdateRestrictions">
          <Record>
            <PropertyValue Property="Updatable" Bool="false"/>
          </Record>
        </Annotation>
        <Annotation Term="Capabilities.DeleteRestrictions">
          <Record>
            <PropertyValue Property="Deletable" Bool="false"/>
          </Record>
        </Annotation>
        <Annotation Term="Redfish.Uris">
          <Collection>
            <String>/redfish/v1/Chassis/{ChassisId}/NetworkAdapters/{NetworkAdapterId}</String>
          </Collection>
        </Annotation>
      </EntityType>

      <Action Name="ResetSettingsToDefault" IsBound="true">
        <Parameter Name="NetworkAdapter" Type="NetworkAdapter.v1_0_0.Actions"/>
        <Annotation Term="OData.Description" String="This action is to clear the settings back to factory defaults."/>
        <Annotation Term="OData.LongDescription" String="This action shall perform a reset of all active and pending settings back to factory default settings upon reset of the network adapter."/>
      </Action>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkAdapter.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2016.3"/>

      <EntityType Name="NetworkAdapter" BaseType="NetworkAdapter.NetworkAdapter">
        <Annotation Term="OData.Description" String="A NetworkAdapter represents the physical network adapter capable of connecting to a computer network.  Examples include but are not limited to Ethernet, Fibre Channel, and converged network adapters."/>
        <Annotation Term="OData.LongDescription" String="A NetworkAdapter represents the physical network adapter capable of connecting to a computer network.  Examples include but are not limited to Ethernet, Fibre Channel, and converged network adapters."/>
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Description" String="This property describes the status and health of the resource and its children."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any status or health properties of the resource."/>
        </Property>
        <NavigationProperty Name="NetworkPorts" Type="NetworkPortCollection.NetworkPortCollection" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the collection of NetworkPorts associated with this NetworkAdapter."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a link to a collection of type NetworkPortCollection."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="NetworkDeviceFunctions" Type="NetworkDeviceFunctionCollection.NetworkDeviceFunctionCollection" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the collection of NetworkDeviceFunctions associated with this NetworkAdapter."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a link to a collection of type NetworkDeviceFunctionCollection."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <Property Name="Manufacturer" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The manufacturer or OEM of this network adapter."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain a value that represents the manufacturer of the network adapter."/>
        </Property>
        <Property Name="Model" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The model string for this network adapter."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain the information about how the manufacturer references this network adapter."/>
        </Property>
        <Property Name="SKU" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The manufacturer SKU for this network adapter."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain the Stock Keeping Unit (SKU) for the network adapter."/>
        </Property>
        <Property Name="SerialNumber" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The serial number for this network adapter."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain the serial number for the network adapter."/>
        </Property>
        <Property Name="PartNumber" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Part number for this network adapter."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain the part number for the network adapter as defined by the manufacturer."/>
        </Property>
        <Property Name="Controllers" Type="Collection(NetworkAdapter.v1_0_0.Controllers)">
          <Annotation Term="OData.Description" String="The set of network controllers ASICs that make up this NetworkAdapter."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain the set of network controllers ASICs that make up this NetworkAdapter."/>
        </Property>
        <Property Name="Actions" Type="NetworkAdapter.v1_0_0.Actions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="NetworkAdapter.v1_0_0.OemActions" Nullable="false">
          <Annotation Term="OData.Description" String="This property contains the available OEM specific actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any additional OEM actions for this resource."/>
        </Property>
      </ComplexType>

      <ComplexType Name="OemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
        <Annotation Term="OData.Description" String="The available OEM specific actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain any additional OEM actions for this resource."/>
      </ComplexType>

      <ComplexType Name="Controllers">
        <Annotation Term="OData.Description" String="A network controller ASIC that makes up part of a NetworkAdapter."/>
        <Annotation Term="OData.LongDescription" String="This type shall describe a network controller ASIC that makes up part of a NetworkAdapter."/>
        <Property Name="FirmwarePackageVersion" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The version of the user-facing firmware package."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the version number of the user-facing firmware package."/>
        </Property>
        <Property Name="Links" Type="NetworkAdapter.v1_0_0.ControllerLinks" Nullable="false">
          <Annotation Term="OData.Description" String="Links."/>
          <Annotation Term="OData.LongDescription" String="Links for this controller."/>
        </Property>
        <Property Name="ControllerCapabilities" Type="NetworkAdapter.v1_0_0.ControllerCapabilities">
          <Annotation Term="OData.Description" String="The capabilities of this controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain the capabilities of this controller."/>
        </Property>
      </ComplexType>

      <ComplexType Name="ControllerCapabilities">
        <Annotation Term="OData.Description" String="The capabilities of a controller."/>
        <Annotation Term="OData.LongDescription" String="This type shall describe the capabilities of a controller."/>
        <Property Name="NetworkPortCount" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The number of physical ports on this controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the number of physical ports on this controller."/>
        </Property>
        <Property Name="NetworkDeviceFunctionCount" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The maximum number of physical functions available on this controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the number of physical functions available on this controller."/>
        </Property>
        <Property Name="DataCenterBridging" Type="NetworkAdapter.v1_0_0.DataCenterBridging">
          <Annotation Term="OData.Description" String="Data Center Bridging (DCB) for this controller."/>
          <Annotation Term="OData.LongDescription" String="This object shall contain capability, status, and configuration values related to Data Center Bridging (DCB) for this controller."/>
        </Property>
        <Property Name="VirtualizationOffload" Type="NetworkAdapter.v1_0_0.VirtualizationOffload">
          <Annotation Term="OData.Description" String="Virtualization offload for this controller."/>
          <Annotation Term="OData.LongDescription" String="This object shall contain capability, status, and configuration values related to virtualization offload for this controller."/>
        </Property>
        <Property Name="NPIV" Type="NetworkAdapter.v1_0_0.NPIV">
          <Annotation Term="OData.Description" String="N_Port ID Virtualization (NPIV) capabilties for this controller."/>
          <Annotation Term="OData.LongDescription" String="This object shall contain N_Port ID Virtualization (NPIV) capabilties for this controller."/>
        </Property>
      </ComplexType>

      <ComplexType Name="DataCenterBridging">
        <Annotation Term="OData.Description" String="Data Center Bridging (DCB) for capabilities of a controller."/>
        <Annotation Term="OData.LongDescription" String="This type shall describe the capability, status, and configuration values related to Data Center Bridging (DCB) for a controller."/>
        <Property Name="Capable" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Whether this controller is capable of Data Center Bridging (DCB)."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a boolean indicating whether this controller is capable of Data Center Bridging (DCB)."/>
        </Property>
      </ComplexType>

      <ComplexType Name="VirtualFunction">
        <Annotation Term="OData.Description" String="A virtual function of a controller."/>
        <Annotation Term="OData.LongDescription" String="This type shall describe the capability, status, and configuration values related to a virtual function for a controller."/>
        <Property Name="DeviceMaxCount" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The maximum number of Virtual Functions (VFs) supported by this controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the maximum number of Virtual Functions (VFs) supported by this controller."/>
        </Property>
        <Property Name="NetworkPortMaxCount" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The maximum number of Virtual Functions (VFs) supported per network port for this controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the maximum number of Virtual Functions (VFs) supported per network port for this controller."/>
        </Property>
        <Property Name="MinAssignmentGroupSize" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The minimum number of Virtual Functions (VFs) that can be allocated or moved between physical functions for this controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the minimum number of Virtual Functions (VFs) that can be allocated or moved between physical functions for this controller."/>
        </Property>
      </ComplexType>

      <ComplexType Name="ControllerLinks" BaseType="Resource.Links">
        <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
        <Annotation Term="OData.LongDescription" String="This type, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        <NavigationProperty Name="PCIeDevices" Type="Collection(PCIeDevice.PCIeDevice)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the PCIeDevices associated with this Network Controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of references of type PCIeDevice that represent the PCI-e Devices associated with this Network Controller."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="NetworkPorts" Type="Collection(NetworkPort.NetworkPort)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the NetworkPorts associated with this Network Controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of references of type NetworkPort that represent the Network Ports associated with this Network Controller."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="NetworkDeviceFunctions" Type="Collection(NetworkDeviceFunction.NetworkDeviceFunction)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the NetworkDeviceFunctions associated with this Network Controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of references of type NetworkDeviceFunction that represent the Network Device Functions associated with this Network Controller."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="SRIOV">
        <Annotation Term="OData.Description" String="Single-Root Input/Output Virtualization (SR-IOV) capabilities."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain Single-Root Input/Output Virtualization (SR-IOV) capabilities."/>
        <Property Name="SRIOVVEPACapable" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Whether this controller supports Single Root Input/Output Virtualization (SR-IOV) in Virtual Ethernet Port Aggregator (VEPA) mode."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a boolean indicating whether this controller supports Single Root Input/Output Virtualization (SR-IOV) in Virtual Ethernet Port Aggregator (VEPA) mode."/>
        </Property>
      </ComplexType>

      <ComplexType Name="VirtualizationOffload">
        <Annotation Term="OData.Description" String="A Virtualization offload capability of a controller."/>
        <Annotation Term="OData.LongDescription" String="This type shall describe the capability, status, and configuration values related to a virtualization offload for a controller."/>
        <Property Name="VirtualFunction" Type="NetworkAdapter.v1_0_0.VirtualFunction">
          <Annotation Term="OData.Description" String="The virtual function of the controller."/>
          <Annotation Term="OData.LongDescription" String="This property shall describe the capability, status, and configuration values related to the virtual function for this controller."/>
        </Property>
        <Property Name="SRIOV" Type="NetworkAdapter.v1_0_0.SRIOV">
          <Annotation Term="OData.Description" String="Single-Root Input/Output Virtualization (SR-IOV) capabilities."/>
          <Annotation Term="OData.LongDescription" String="This object shall contain Single-Root Input/Output Virtualization (SR-IOV) capabilities."/>
        </Property>
      </ComplexType>

      <ComplexType Name="NPIV">
        <Annotation Term="OData.Description" String="N_Port ID Virtualization (NPIV) capabilties for a controller."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain N_Port ID Virtualization (NPIV) capabilties for a controller."/>
        <Property Name="MaxDeviceLogins" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The maximum number of N_Port ID Virtualization (NPIV) logins allowed simultaneously from all ports on this controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the maximum number of N_Port ID Virtualization (NPIV) logins allowed simultaneously from all ports on this controller."/>
        </Property>
        <Property Name="MaxPortLogins" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The maximum number of N_Port ID Virtualization (NPIV) logins allowed per physical port on this controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the maximum number of N_Port ID Virtualization (NPIV) logins allowed per physical port on this controller."/>
        </Property>
      </ComplexType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkAdapter.v1_0_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to remove the Nullable facet on NavigationProperties of type Collection."/>
      <EntityType Name="NetworkAdapter" BaseType="NetworkAdapter.v1_0_0.NetworkAdapter"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkAdapter.v1_0_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="NetworkAdapter" BaseType="NetworkAdapter.v1_0_1.NetworkAdapter"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkAdapter.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.3"/>
      <EntityType Name="NetworkAdapter" BaseType="NetworkAdapter.v1_0_1.NetworkAdapter">
        <NavigationProperty Name="Assembly" Type="Assembly.Assembly" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the Assembly resource associated with this adapter."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a link to a resource of type Assembly."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

      <ComplexType Name="Controllers" BaseType="NetworkAdapter.v1_0_0.Controllers">
        <Property Name="Location" Type="Resource.Location" Nullable="false">
          <Annotation Term="OData.Description" String="The Location of the network adapter controller."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain location information of the associated network adapter controller."/>
        </Property>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkAdapter.v1_1_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="NetworkAdapter" BaseType="NetworkAdapter.v1_1_0.NetworkAdapter"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkAdapter.v1_2_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.2"/>
      <EntityType Name="NetworkAdapter" BaseType="NetworkAdapter.v1_1_1.NetworkAdapter"/>

      <ComplexType Name="Controllers" BaseType="NetworkAdapter.v1_1_0.Controllers">
        <Property Name="PCIeInterface" Type="PCIeDevice.PCIeInterface">
          <Annotation Term="OData.Description" String="The PCIe interface details for this controller."/>
          <Annotation Term="OData.LongDescription" String="This object shall contain details on the PCIe interface used to connect this PCIe-based controller to its host."/>
        </Property>
      </ComplexType>

      <ComplexType Name="ControllerCapabilities" BaseType="NetworkAdapter.v1_0_0.ControllerCapabilities">
        <Property Name="NPAR" Type="NetworkAdapter.v1_2_0.NicPartitioning">
          <Annotation Term="OData.Description" String="NIC Partitioning (NPAR) capabilities for this controller."/>
          <Annotation Term="OData.LongDescription" String="This object shall contain capability, status, and configuration values related to NIC partitioning for this controller."/>
        </Property>
      </ComplexType>

      <ComplexType Name="NicPartitioning">
        <Annotation Term="OData.Description" String="NIC Partitioning capability, status, and configuration for a controller."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the capability, status, and configuration values for a controller."/>
        <Property Name="NparCapable" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Indicates whether or not NIC function partitioning is supported by a controller."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the ability of a controller to support NIC function partitioning."/>
        </Property>
        <Property Name="NparEnabled" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="When true, NIC function partitioning is active on this controller."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate whether or not NIC function partitioning is active on this controller."/>
        </Property>
      </ComplexType>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_NETWORK_ADAPTER_V1_HPP */
