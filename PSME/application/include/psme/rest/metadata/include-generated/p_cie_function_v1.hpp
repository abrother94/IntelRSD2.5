#ifndef PSME_REST_METADATA_P_CIE_FUNCTION_V1_HPP
#define PSME_REST_METADATA_P_CIE_FUNCTION_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string PCIeFunction_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  PCIeFunction  v1.2.1-->
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
  <edmx:Reference Uri="/redfish/v1/metadata/EthernetInterface_v1.xml">
    <edmx:Include Namespace="EthernetInterface"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/PCIeDevice_v1.xml">
    <edmx:Include Namespace="PCIeDevice"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Drive_v1.xml">
    <edmx:Include Namespace="Drive"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Storage_v1.xml">
    <edmx:Include Namespace="Storage"/>
  </edmx:Reference>
    <edmx:Reference Uri="/redfish/v1/metadata/NetworkDeviceFunction_v1.xml">
    <edmx:Include Namespace="NetworkDeviceFunction"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="PCIeFunction">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="PCIeFunction" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="This is the schema definition for the PCIeFunction resource.  It represents the properties of a PCIeFunction attached to a System."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent a PCIeFunction attached to a System."/>
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
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
            <String>/redfish/v1/Chassis/{ChassisId}/PCIeDevices/{PCIeDeviceId}/PCIeFunctions/{PCIeFunctionId}</String>
            <String>/redfish/v1/Systems/{ComputerSystemId}/PCIeDevices/{PCIeDeviceId}/PCIeFunctions/{PCIeFunctionId}</String>
          </Collection>
        </Annotation>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="PCIeFunction.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2016.2"/>
      <EntityType Name="PCIeFunction" BaseType="PCIeFunction.PCIeFunction">
        <Annotation Term="OData.Description" String="This is the schema definition for the PCIeFunction resource.  It represents the properties of a PCIeFunction attached to a System."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent a PCIeFunction attached to a System."/>
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>

        <Property Name="FunctionId" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The the PCIe Function identifier."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall the PCIe device function number within a given PCIe device."/>
        </Property>
        <Property Name="FunctionType" Type="PCIeFunction.v1_0_0.FunctionType" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The type of the PCIe Function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the function type of the PCIe device function such as Physical or Virtual."/>
        </Property>
        <Property Name="DeviceClass" Type="PCIeFunction.v1_0_0.DeviceClass" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The class for this PCIe Function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the device class of the PCIe device function such as Storage, Network, Memory etc."/>
        </Property>
        <Property Name="DeviceId" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Device ID of this PCIe function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the PCI Device ID of the PCIe device function."/>
          <Annotation Term="Validation.Pattern" String="^0[xX](([a-fA-F]|[0-9]){2}){2}$"/>
        </Property>
        <Property Name="VendorId" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Vendor ID of this PCIe function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the PCI Vendor ID of the PCIe device function."/>
          <Annotation Term="Validation.Pattern" String="^0[xX](([a-fA-F]|[0-9]){2}){2}$"/>
        </Property>
        <Property Name="ClassCode" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Class Code of this PCIe function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the PCI Class Code of the PCIe device function."/>
          <Annotation Term="Validation.Pattern" String="^0[xX](([a-fA-F]|[0-9]){2}){3}$"/>
        </Property>
        <Property Name="RevisionId" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Revision ID of this PCIe function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the PCI Revision ID of the PCIe device function."/>
          <Annotation Term="Validation.Pattern" String="^0[xX](([a-fA-F]|[0-9]){2}){1}$"/>
        </Property>
        <Property Name="SubsystemId" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Subsystem ID of this PCIe function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the PCI Subsystem ID of the PCIe device function."/>
          <Annotation Term="Validation.Pattern" String="^0[xX](([a-fA-F]|[0-9]){2}){2}$"/>
        </Property>
        <Property Name="SubsystemVendorId" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Subsystem Vendor ID of this PCIe function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the PCI Subsystem Vendor ID of the PCIe device function."/>
          <Annotation Term="Validation.Pattern" String="^0[xX](([a-fA-F]|[0-9]){2}){2}$"/>
        </Property>

        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Description" String="This property describes the status and health of the resource and its children."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any status or health properties of the resource."/>
        </Property>

        <Property Name="Links" Type="PCIeFunction.v1_0_0.Links" Nullable="false">
          <Annotation Term="OData.Description" String="The links object contains the links to other resources that are related to this resource."/>
          <Annotation Term="OData.LongDescription" String="The Links property, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Links" BaseType="Resource.Links">
        <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
        <Annotation Term="OData.LongDescription" String="This type, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        <NavigationProperty Name="EthernetInterfaces" Type="Collection(EthernetInterface.EthernetInterface)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the ethernet interfaces which the PCIe device produces."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall reference a resource of type EthernetInterface that represents the network interfaces associated with this resource."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Drives" Type="Collection(Drive.Drive)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the drives which the PCIe device produces."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall reference a resource of type Drive that represents the storage drives associated with this resource."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="StorageControllers" Type="Collection(Storage.StorageController)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the storage controllers which the PCIe device produces."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall reference a resource of type StorageController that represents the storage controllers associated with this resource."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="PCIeDevice" Type="PCIeDevice.PCIeDevice">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the PCIeDevice on which this function resides."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a reference to the resource that this function is a part of and shall reference a resource of type PCIeDevice."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <EnumType Name="DeviceClass">
        <Member Name="UnclassifiedDevice">
          <Annotation Term="OData.Description" String="An unclassified device."/>
        </Member>
        <Member Name="MassStorageController">
          <Annotation Term="OData.Description" String="A mass storage controller."/>
        </Member>
        <Member Name="NetworkController">
          <Annotation Term="OData.Description" String="A network controller."/>
        </Member>
        <Member Name="DisplayController">
          <Annotation Term="OData.Description" String="A display controller."/>
        </Member>
        <Member Name="MultimediaController">
          <Annotation Term="OData.Description" String="A multimedia controller."/>
        </Member>
        <Member Name="MemoryController">
          <Annotation Term="OData.Description" String="A memory controller."/>
        </Member>
        <Member Name="Bridge">
          <Annotation Term="OData.Description" String="A bridge."/>
        </Member>
        <Member Name="CommunicationController">
          <Annotation Term="OData.Description" String="A communication controller."/>
        </Member>
        <Member Name="GenericSystemPeripheral">
          <Annotation Term="OData.Description" String="A generic system peripheral."/>
        </Member>
        <Member Name="InputDeviceController">
          <Annotation Term="OData.Description" String="An input device controller."/>
        </Member>
        <Member Name="DockingStation">
          <Annotation Term="OData.Description" String="A docking station."/>
        </Member>
        <Member Name="Processor">
          <Annotation Term="OData.Description" String="A processor."/>
        </Member>
        <Member Name="SerialBusController">
          <Annotation Term="OData.Description" String="A serial bus controller."/>
        </Member>
        <Member Name="WirelessController">
          <Annotation Term="OData.Description" String="A wireless controller."/>
        </Member>
        <Member Name="IntelligentController">
          <Annotation Term="OData.Description" String="An intelligent controller."/>
        </Member>
        <Member Name="SatelliteCommunicationsController">
          <Annotation Term="OData.Description" String="A satellite communications controller."/>
        </Member>
        <Member Name="EncryptionController">
          <Annotation Term="OData.Description" String="An encryption controller."/>
        </Member>
        <Member Name="SignalProcessingController">
          <Annotation Term="OData.Description" String="A signal processing controller."/>
        </Member>
        <Member Name="ProcessingAccelerators">
          <Annotation Term="OData.Description" String="A processing accelerators."/>
        </Member>
        <Member Name="NonEssentialInstrumentation">
          <Annotation Term="OData.Description" String="A non-essential instrumentation."/>
        </Member>
        <Member Name="Coprocessor">
          <Annotation Term="OData.Description" String="A coprocessor."/>
        </Member>
        <Member Name="UnassignedClass">
          <Annotation Term="OData.Description" String="An unassigned class."/>
        </Member>
        <Member Name="Other">
          <Annotation Term="OData.Description" String="A other class. The function Device Class Id needs to be verified."/>
        </Member>
      </EnumType>

      <EnumType Name="FunctionType">
        <Member Name="Physical">
          <Annotation Term="OData.Description" String="A physical PCie function."/>
        </Member>
        <Member Name="Virtual">
          <Annotation Term="OData.Description" String="A virtual PCIe function."/>
        </Member>
      </EnumType>
      
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="PCIeFunction.v1_0_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="PCIeFunction" BaseType="PCIeFunction.v1_0_0.PCIeFunction"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="PCIeFunction.v1_0_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="PCIeFunction" BaseType="PCIeFunction.v1_0_1.PCIeFunction"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="PCIeFunction.v1_0_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to change references to StorageController to be its abstract base type."/>
      <EntityType Name="PCIeFunction" BaseType="PCIeFunction.v1_0_2.PCIeFunction"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="PCIeFunction.v1_0_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="PCIeFunction" BaseType="PCIeFunction.v1_0_3.PCIeFunction"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="PCIeFunction.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.1"/>
      <EntityType Name="PCIeFunction" BaseType="PCIeFunction.v1_0_2.PCIeFunction">
        <Property Name="Actions" Type="PCIeFunction.v1_1_0.Actions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="PCIeFunction.v1_1_0.OemActions" Nullable="false">
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

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="PCIeFunction.v1_1_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to change references to StorageController to be its abstract base type."/>
      <EntityType Name="PCIeFunction" BaseType="PCIeFunction.v1_1_0.PCIeFunction"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="PCIeFunction.v1_1_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="PCIeFunction" BaseType="PCIeFunction.v1_1_1.PCIeFunction"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="PCIeFunction.v1_2_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.1"/>
      <Annotation Term="OData.Description" String="This version was created to add NetworkDeviceFunctions to the Links section."/>
      <EntityType Name="PCIeFunction" BaseType="PCIeFunction.v1_1_1.PCIeFunction"/>
      <ComplexType Name="Links" BaseType="PCIeFunction.v1_0_0.Links">
        <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
        <Annotation Term="OData.LongDescription" String="This type, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        <NavigationProperty Name="NetworkDeviceFunctions" Type="Collection(NetworkDeviceFunction.NetworkDeviceFunction)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the Network Device Functions which the PCIe device produces."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of references to resources of type NetworkDeviceFunction that represents the network device functions associated with this resource."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="PCIeFunction.v1_2_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="PCIeFunction" BaseType="PCIeFunction.v1_2_0.PCIeFunction"/>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_P_CIE_FUNCTION_V1_HPP */