#ifndef PSME_REST_METADATA_ASSEMBLY_V1_HPP
#define PSME_REST_METADATA_ASSEMBLY_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Assembly_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  Assembly  v1.2.0-->
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
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/PhysicalContext_v1.xml">
    <edmx:Include Namespace="PhysicalContext"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Assembly">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="Assembly" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="This is the schema definition for the Assembly properties."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent an assembly information resource for a Redfish implementation."/>
        <Annotation Term="Capabilities.InsertRestrictions">
          <Record>
            <PropertyValue Property="Insertable" Bool="false"/>
          </Record>
        </Annotation>
        <Annotation Term="Capabilities.UpdateRestrictions">
          <Record>
            <PropertyValue Property="Updatable" Bool="true"/>
            <Annotation Term="OData.Description" String="Assembly resources can be updated to change any writable properties."/>
          </Record>
        </Annotation>
        <Annotation Term="Capabilities.DeleteRestrictions">
          <Record>
            <PropertyValue Property="Deletable" Bool="false"/>
          </Record>
        </Annotation>
        <Annotation Term="Redfish.Uris">
          <Collection>
            <String>/redfish/v1/Chassis/{ChassisId}/Assembly</String>
            <String>/redfish/v1/Systems/{ComputerSystemId}/Storage/{StorageId}/Drives/{DriveId}/Assembly</String>
            <String>/redfish/v1/Chassis/{ChassisId}/Drives/{DriveId}/Assembly</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Storage/{StorageId}/Drives/{DriveId}/Assembly</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Drives/{DriveId}/Assembly</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/Storage/{StorageId}/Drives/{DriveId}/Assembly</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Storage/{StorageId}/Drives/{DriveId}/Assembly</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Drives/{DriveId}/Assembly</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/Storage/{StorageId}/Drives/{DriveId}/Assembly</String>
            <String>/redfish/v1/Systems/{ComputerSystemId}/Memory/{MemoryId}/Assembly</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Memory/{MemoryId}/Assembly</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/Memory/{MemoryId}/Assembly</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Memory/{MemoryId}/Assembly</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/Memory/{MemoryId}/Assembly</String>
            <String>/redfish/v1/Chassis/{ChassisId}/NetworkAdapters/{NetworkAdapterId}/Assembly</String>
            <String>/redfish/v1/Chassis/{ChassisId}/PCIeDevices/{PCIeDeviceId}/Assembly</String>
            <String>/redfish/v1/Systems/{ComputerSystemId}/PCIeDevices/{PCIeDeviceId}/Assembly</String>
            <String>/redfish/v1/Chassis/{ChassisId}/Power/PowerSupplies/{PowerSupplyId}/Assembly</String>
            <String>/redfish/v1/Systems/{ComputerSystemId}/Processors/{ProcessorId}/Assembly</String>
            <String>/redfish/v1/Systems/{ComputerSystemId}/Processors/{ProcessorId}/SubProcessors/{ProcessorId2}/Assembly</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Processors/{ProcessorId}/Assembly</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Processors/{ProcessorId}/SubProcessors/{ProcessorId2}/Assembly</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/Processors/{ProcessorId}/Assembly</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/Processors/{ProcessorId}/SubProcessors/{ProcessorId2}/Assembly</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Processors/{ProcessorId}/Assembly</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Processors/{ProcessorId}/SubProcessors/{ProcessorId2}/Assembly</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/Processors/{ProcessorId}/Assembly</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/Processors/{ProcessorId}/SubProcessors/{ProcessorId2}/Assembly</String>
            <String>/redfish/v1/Systems/{ComputerSystemId}/Storage/{StorageId}/Assembly</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Storage/{StorageId}/Assembly</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/Storage/{StorageId}/Assembly</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Storage/{StorageId}/Assembly</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/Storage/{StorageId}/Assembly</String>
            <String>/redfish/v1/Chassis/{ChassisId}/Thermal/Fans/{FanId}/Thermal</String>
          </Collection>
        </Annotation>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Assembly.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.3"/>

      <EntityType Name="Assembly" BaseType="Assembly.Assembly">
        <NavigationProperty Name="Assemblies" Type="Collection(Assembly.v1_0_0.AssemblyData)" ContainsTarget="true">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This is the definition for an assembly information record."/>
          <Annotation Term="OData.LongDescription" String="These properties shall be the definition for assembly records  for a Redfish implementation."/>
          <Annotation Term="OData.AutoExpand"/>
        </NavigationProperty>
        <Property Name="Actions" Type="Assembly.v1_0_0.Actions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <EntityType Name="AssemblyData" BaseType="Resource.v1_0_0.ReferenceableMember">
        <Property Name="Name" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Name of the Assembly."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the name of the assembly."/>
        </Property>
        <Property Name="Description" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Description of the Assembly."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a description of this assembly."/>
        </Property>
        <Property Name="Model" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Model number of the Assembly."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the name by which the manufacturer generally refers to the assembly."/>
        </Property>
        <Property Name="PartNumber" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Part number of the Assembly."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the name of the assembly."/>
        </Property>
        <Property Name="SparePartNumber" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Spare part number of the Assembly."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the name of the assembly."/>
        </Property>
        <Property Name="SKU" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="SKU of the Assembly."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the name of the assembly."/>
        </Property>
        <Property Name="Vendor" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Vendor of the Assembly."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the name of the company which provides the final product that includes this assembly. This value shall be equal to the 'Vendor' field in a PLDM FRU structure, if applicable, for this assembly."/>
        </Property>
        <Property Name="ProductionDate" Type="Edm.DateTimeOffset">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Production date of the Assembly."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the date of production or manufacture for this assembly.  The time of day portion of the property shall be '00:00:00Z' if the time of day is unknown."/>
        </Property>
        <Property Name="Producer" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Producer or manufacturer of the Assembly."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the name of the company which supplied or manufactured this assembly. This value shall be equal to the 'Manufacturer' field in a PLDM FRU structure, if applicable, for this assembly."/>
        </Property>
        <Property Name="Version" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Version of the Assembly."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the version of the assembly as determined by the vendor or supplier."/>
        </Property>
        <Property Name="EngineeringChangeLevel" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Engineering change level of the Assembly."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the Engineering Change Level (ECL) or revision of the assembly."/>
        </Property>
        <Property Name="BinaryDataURI" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="URI that provides the ability to access an image of the assembly information."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a URI at which the Service provides for the download of the OEM-specific binary image of the assembly data.  An HTTP GET from this URI shall return a response payload of MIME time application/octet-stream. An HTTP PUT to this URI, if supported by the Service, shall replace the binary image of the assembly."/>
          <Annotation Term="OData.IsURL"/>
        </Property>
        <Property Name="Actions" Type="Assembly.v1_0_0.AssemblyDataActions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="Assembly.v1_0_0.OemActions" Nullable="false">
          <Annotation Term="OData.Description" String="This property contains the available OEM specific actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any additional OEM actions for this resource."/>
        </Property>
      </ComplexType>

      <ComplexType Name="OemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
        <Annotation Term="OData.Description" String="The available OEM specific actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain any additional OEM actions for this resource."/>
      </ComplexType>

      <ComplexType Name="AssemblyDataActions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="Assembly.v1_0_0.AssemblyDataOemActions" Nullable="false">
          <Annotation Term="OData.Description" String="This property contains the available OEM specific actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any additional OEM actions for this resource."/>
        </Property>
      </ComplexType>

      <ComplexType Name="AssemblyDataOemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
        <Annotation Term="OData.Description" String="The available OEM specific actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain any additional OEM actions for this resource."/>
      </ComplexType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Assembly.v1_0_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number.  It was also created to clarify the time of day portion of the ProductionDate property."/>
      <EntityType Name="Assembly" BaseType="Assembly.v1_0_0.Assembly"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Assembly.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.1"/>
      <EntityType Name="Assembly" BaseType="Assembly.v1_0_0.Assembly"/>

      <EntityType Name="AssemblyData" BaseType="Assembly.v1_0_0.AssemblyData">
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Description" String="This property describes the status and health of the resource and its children."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any status or health properties of the resource."/>
        </Property>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Assembly.v1_1_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number.  It was also created to clarify the time of day portion of the ProductionDate property."/>
      <EntityType Name="Assembly" BaseType="Assembly.v1_1_0.Assembly"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Assembly.v1_2_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.2"/>
      <Annotation Term="OData.Description" String="This version was created to add SerialNumber and PhysicalContext properties."/>
      <EntityType Name="Assembly" BaseType="Assembly.v1_1_1.Assembly"/>

      <EntityType Name="AssemblyData" BaseType="Assembly.v1_1_0.AssemblyData">
        <Property Name="SerialNumber" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The serial number of this assembly."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a manufacturer-allocated number used to identify the assembly."/>
        </Property>
        <Property Name="PhysicalContext" Type="PhysicalContext.PhysicalContext" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Describes the area or device to which this assembly data applies."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a description of the physical context for this assembly data."/>
        </Property>
      </EntityType>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_ASSEMBLY_V1_HPP */
