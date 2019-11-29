#ifndef PSME_REST_METADATA_MEMORY_CHUNKS_V1_HPP
#define PSME_REST_METADATA_MEMORY_CHUNKS_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string MemoryChunks_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  MemoryChunks  v1.2.2-->
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
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
  </edmx:Reference>
  
  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MemoryChunks">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="MemoryChunks" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="This is the schema definition of a Memory Chunk and its configuration."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent Memory Chunks and Interleave Sets in a Redfish implementation."/>
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="Capabilities.InsertRestrictions">
          <Record>
            <PropertyValue Property="Insertable" Bool="false"/>
          </Record>
        </Annotation>
        <Annotation Term="Capabilities.UpdateRestrictions">
          <Record>
            <PropertyValue Property="Updatable" Bool="true"/>
          </Record>
        </Annotation>
        <Annotation Term="Capabilities.DeleteRestrictions">
          <Record>
            <PropertyValue Property="Deletable" Bool="true"/>
          </Record>
        </Annotation>
        <Annotation Term="Redfish.Uris">
          <Collection>
            <String>/redfish/v1/Systems/{ComputerSystemId}/MemoryDomains/{MemoryDomainId}/MemoryChunks/{MemoryChunksId}</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/MemoryDomains/{MemoryDomainId}/MemoryChunks/{MemoryChunksId}</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/MemoryDomains/{MemoryDomainId}/MemoryChunks/{MemoryChunksId}</String>
          </Collection>
        </Annotation>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MemoryChunks.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2016.2"/>

      <EntityType Name="MemoryChunks" BaseType="MemoryChunks.MemoryChunks">
        <Property Name="MemoryChunkSizeMiB" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Size of the memory chunk measured in mebibytes (MiB)."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the size of the memory chunk in MiB."/>
          <Annotation Term="Measures.Unit" String="MiBy"/>
        </Property>
        <Property Name="AddressRangeType" Type="MemoryChunks.v1_0_0.AddressRangeType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Memory type of this memory chunk."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the type of memory chunk."/>
        </Property>
        <Property Name="IsMirrorEnabled" Type="Edm.Boolean" DefaultValue="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Mirror Enabled status."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate if memory mirroring is enabled for this MemoryChunk."/>
        </Property>
        <Property Name="IsSpare" Type="Edm.Boolean" DefaultValue="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Spare enabled status."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate if sparing is enabled for this MemoryChunk."/>
        </Property>
        <Property Name="InterleaveSets" Type="Collection(MemoryChunks.v1_0_0.InterleaveSet)">
          <Annotation Term="OData.Description" String="This is the interleave sets for the memory chunk."/>
          <Annotation Term="OData.LongDescription" String="These properties shall represent the interleave sets for the memory chunk."/>
        </Property>
      </EntityType>

      <ComplexType Name="InterleaveSet">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This an interleave set for a memory chunk."/>
        <Annotation Term="OData.LongDescription" String="This type shall describe an interleave set of which the memory chunk is a part."/>
        <NavigationProperty Name="Memory" Type="Resource.Item" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Describes a memory device of the interleave set."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the memory device to which these settings apply."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <Property Name="RegionId" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="DIMM region identifier."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the DIMM region identifier."/>
        </Property>
        <Property Name="OffsetMiB" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Offset within the DIMM that corresponds to the start of this memory region, measured in mebibytes (MiB)."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the offset within the DIMM that corresponds to the start of this memory region, with units in MiB."/>
          <Annotation Term="Measures.Unit" String="MiBy"/>
        </Property>
        <Property Name="SizeMiB" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Size of this memory region measured in mebibytes (MiB)."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the size of this memory region, with units in MiB."/>
          <Annotation Term="Measures.Unit" String="MiBy"/>
        </Property>
        <Property Name="MemoryLevel" Type="Edm.Int64" DefaultValue="1">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Level of the interleave set for multi-level tiered memory."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the level of this interleave set for multi-level tiered memory."/>
        </Property>
      </ComplexType>

      <EnumType Name="AddressRangeType">
        <Member Name="Volatile">
          <Annotation Term="OData.Description" String="Volatile memory."/>
        </Member>
        <Member Name="PMEM">
          <Annotation Term="OData.Description" String="Byte accessible persistent memory."/>
        </Member>
        <Member Name="Block">
          <Annotation Term="OData.Description" String="Block accesible memory."/>
        </Member>
      </EnumType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MemoryChunks.v1_0_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="MemoryChunks" BaseType="MemoryChunks.v1_0_0.MemoryChunks"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MemoryChunks.v1_0_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="MemoryChunks" BaseType="MemoryChunks.v1_0_1.MemoryChunks"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MemoryChunks.v1_0_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add Units annotations on various properties.  It was also created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="MemoryChunks" BaseType="MemoryChunks.v1_0_2.MemoryChunks"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MemoryChunks.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.1"/>
      <EntityType Name="MemoryChunks" BaseType="MemoryChunks.v1_0_2.MemoryChunks">
        <Property Name="Actions" Type="MemoryChunks.v1_1_0.Actions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="MemoryChunks.v1_1_0.OemActions" Nullable="false">
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

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MemoryChunks.v1_1_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add Units annotations on various properties.  It was also created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="MemoryChunks" BaseType="MemoryChunks.v1_1_0.MemoryChunks"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MemoryChunks.v1_2_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.3"/>
      <EntityType Name="MemoryChunks" BaseType="MemoryChunks.v1_1_0.MemoryChunks">
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Description" String="This property describes the status and health of the resource and its children."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any status or health properties of the resource."/>
        </Property>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MemoryChunks.v1_2_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to update descriptions to match the editorial style used in other Redfish schemas."/>
      <EntityType Name="MemoryChunks" BaseType="MemoryChunks.v1_2_0.MemoryChunks"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MemoryChunks.v1_2_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add Units annotations on various properties.  It was also created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="MemoryChunks" BaseType="MemoryChunks.v1_2_1.MemoryChunks"/>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_MEMORY_CHUNKS_V1_HPP */
