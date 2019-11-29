#ifndef PSME_REST_METADATA_ACCELERATION_FUNCTION_V1_HPP
#define PSME_REST_METADATA_ACCELERATION_FUNCTION_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string AccelerationFunction_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  AccelerationFunction  v1.0.0-->
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
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Measures.V1.xml">
    <edmx:Include Namespace="Org.OData.Measures.V1" Alias="Measures"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Endpoint_v1.xml">
    <edmx:Include Namespace="Endpoint"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/PCIeFunction_v1.xml">
    <edmx:Include Namespace="PCIeFunction"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="AccelerationFunction">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="AccelerationFunction" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="The AccelerationFunction schema defines the accelerator implemented in a Processor device."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent the acceleration function, implemented in a Processor, in a Redfish implementation."/>
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
            <String>/redfish/v1/Systems/{ComputerSystemId}/Processors/{ProcessorId}/AccelerationFunctions/{AccelerationFunctionId}</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Processors/{ProcessorId}/AccelerationFunctions/{AccelerationFunctionId}</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/Processors/{ProcessorId}/AccelerationFunctions/{AccelerationFunctionId}</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Processors/{ProcessorId}/AccelerationFunctions/{AccelerationFunctionId}</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/Processors/{ProcessorId}/AccelerationFunctions/{AccelerationFunctionId}</String>
          </Collection>
        </Annotation>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="AccelerationFunction.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.3"/>

      <EntityType Name="AccelerationFunction" BaseType="AccelerationFunction.AccelerationFunction">
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Description" String="This property describes the status and health of the resource and its children."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any status or health properties of the resource."/>
        </Property>
        <Property Name="UUID" Type="Resource.UUID">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The universal unique identifier (UUID) for this acceleration function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be used to contain a universal unique identifier number for the acceleration function.  RFC4122 describes methods that can be used to create the value.  The value should be considered to be opaque.  Client software should only treat the overall value as a universally unique identifier and should not interpret any sub-fields within the UUID."/>
        </Property>
        <Property Name="FpgaReconfigurationSlots" Type="Collection(Edm.String)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of the reconfiguration slot identifiers for an FPGA."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of the FPGA reconfiguration slots identifiers that this acceleration function occupies."/>
        </Property>
        <Property Name="AccelerationFunctionType" Type="AccelerationFunction.v1_0_0.AccelerationFunctionType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The type of acceleration function."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the string which identifies the type of acceleration function."/>
        </Property>
        <Property Name="Manufacturer" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The acceleration function code manufacturer."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain a string which identifies the manufacturer of the acceleration function."/>
        </Property>
        <Property Name="Version" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The acceleration function version."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain a string decsribing the acceleration function version."/>
        </Property>
        <Property Name="PowerWatts" Type="Edm.Int64" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The acceleration function power consumption."/>
          <Annotation Term="OData.LongDescription" String="The total acceleration function power consumtion in watts."/>
          <Annotation Term="Measures.Unit" String="W"/>
        </Property>
        <Property Name="Links" Type="AccelerationFunction.v1_0_0.Links" Nullable="false">
          <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
          <Annotation Term="OData.LongDescription" String="The Links property, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        </Property>
        <Property Name="Actions" Type="AccelerationFunction.v1_0_0.Actions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Links" BaseType="Resource.Links">
        <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
        <Annotation Term="OData.LongDescription" String="This type, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        <NavigationProperty Name="Endpoints" Type="Collection(Endpoint.Endpoint)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the endpoints that connect to this acceleartion function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of references to resources of type Endpoint that are associated with this acceleration function."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="PCIeFunctions" Type="Collection(PCIeFunction.PCIeFunction)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the PCIeFunctions associated with this acceleration function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of references of type PCIeFunction that represent the PCI-e Functions associated with this acceleration function."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="AccelerationFunction.v1_0_0.OemActions" Nullable="false">
          <Annotation Term="OData.Description" String="This property contains the available OEM specific actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any additional OEM actions for this resource."/>
        </Property>
      </ComplexType>

      <ComplexType Name="OemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
        <Annotation Term="OData.Description" String="The available OEM specific actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain any additional OEM actions for this resource."/>
      </ComplexType>

      <EnumType Name="AccelerationFunctionType">
        <Member Name="Encryption">
          <Annotation Term="OData.Description" String="An encryption function."/>
        </Member>
        <Member Name="Compression">
          <Annotation Term="OData.Description" String="A compression function."/>
        </Member>
        <Member Name="PacketInspection">
          <Annotation Term="OData.Description" String="A packet inspection function."/>
        </Member>
        <Member Name="PacketSwitch">
          <Annotation Term="OData.Description" String="A packet switch function."/>
        </Member>
        <Member Name="Scheduler">
          <Annotation Term="OData.Description" String="A scheduler function."/>
        </Member>
        <Member Name="AudioProcessing">
          <Annotation Term="OData.Description" String="An audio processing function."/>
        </Member>
        <Member Name="VideoProcessing">
          <Annotation Term="OData.Description" String="A video processing function."/>
        </Member>
        <Member Name="OEM">
          <Annotation Term="OData.Description" String="An OEM-defined acceleration function."/>
        </Member>
      </EnumType>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_ACCELERATION_FUNCTION_V1_HPP */
