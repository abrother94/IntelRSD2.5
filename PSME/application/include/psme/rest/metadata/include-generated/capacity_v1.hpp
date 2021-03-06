#ifndef PSME_REST_METADATA_CAPACITY_V1_HPP
#define PSME_REST_METADATA_CAPACITY_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Capacity_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!-- Copyright 2015-2018 Storage Networking Industry Association (SNIA), USA. All rights reserved.-->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Measures.V1.xml">
    <edmx:Include Namespace="Org.OData.Measures.V1" Alias="Measures"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ClassOfService_v1.xml">
    <edmx:Include Namespace="ClassOfService"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/VolumeCollection_v1.xml">
    <edmx:Include Namespace="VolumeCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/StoragePoolCollection_v1.xml">
    <edmx:Include Namespace="StoragePoolCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/DriveCollection_v1.xml">
    <edmx:Include Namespace="DriveCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/MemoryChunksCollection_v1.xml">
    <edmx:Include Namespace="MemoryChunksCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/MemoryCollection_v1.xml">
    <edmx:Include Namespace="MemoryCollection"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Capacity">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <ComplexType Name="Capacity" Abstract="true">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This is the schema definition for the Capacity of a device. It represents the properties for capacity for any data store."/>
        <Annotation Term="OData.LongDescription" String="This composition may be used to represent storage capacity.  The sum of the values in Data, Metadata, and Snapshot shall be equal to the total capacity for the data store."/>
      </ComplexType>

      <ComplexType Name="CapacityInfo" Abstract="true">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The capacity of specific data type in a data store."/>
        <Annotation Term="OData.LongDescription" String="This composition may be used to represent the utilization of storage capacity."/>
      </ComplexType>

      <EntityType Name="CapacitySource" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="A description of the type and source of storage."/>
        <Annotation Term="OData.LongDescription" String="This type may be used to represent the source and type of storage capacity.  At most one of the ProvidingDrives, ProvidingVolumes or ProvidingPools properties may have a value.  If any of ProvidingDrives, ProvidingVolumes or ProvidingPools reference more than one resource, allocation of capacity across those resources is implementation dependent."/>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Capacity.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <ComplexType Name="Capacity" BaseType="Capacity.Capacity">
        <Annotation Term="OData.Description" String="This is the schema definition for the Capacity of a device. It represents the properties for capacity for any data store."/>
        <Annotation Term="OData.LongDescription" String="This composition may be used to represent storage capacity.  The sum of the values in Data, Metadata, and Snapshot shall be equal to the total capacity for the data store."/>
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Data" Type="Capacity.v1_0_0.CapacityInfo">
          <Annotation Term="OData.Description" String="The capacity information relating to the user data."/>
          <Annotation Term="OData.LongDescription" String="The value shall be capacity information relating to provisioned user data."/>
        </Property>
        <Property Name="Metadata" Type="Capacity.v1_0_0.CapacityInfo">
          <Annotation Term="OData.Description" String="The capacity information relating to  metadata."/>
          <Annotation Term="OData.LongDescription" String="The value shall be capacity information relating to provisioned system (non-user accessible) data."/>
        </Property>
        <Property Name="Snapshot" Type="Capacity.v1_0_0.CapacityInfo">
          <Annotation Term="OData.Description" String="The capacity information relating to snapshot or backup data."/>
          <Annotation Term="OData.LongDescription" String="The value shall be capacity information relating to provisioned snapshot or backup data."/>
        </Property>
        <Property Name="IsThinProvisioned" Type="Edm.Boolean" DefaultValue="false">
          <Annotation Term="OData.Description" String="Marks that the capacity is not necessarily fully allocated."/>
          <Annotation Term="OData.LongDescription" String="If the value is false, the capacity shall be fully allocated.  The default value shall be false."/>
        </Property>
      </ComplexType>

      <ComplexType Name="CapacityInfo" BaseType="Capacity.CapacityInfo">
        <Annotation Term="OData.Description" String="The capacity of specific data type in a data store."/>
        <Annotation Term="OData.LongDescription" String="This composition may be used to represent the utilization of storage capacity."/>
        <Property Name="ConsumedBytes" Type="Edm.Int64">
          <Annotation Term="OData.Description" String="The number of bytes consumed in this data store for this data type."/>
          <Annotation Term="OData.LongDescription" String="The value shall be the number of logical bytes currently consumed in this data store for this data type."/>
          <Annotation Term="Measures.Unit" String="By"/>
        </Property>
        <Property Name="AllocatedBytes" Type="Edm.Int64">
          <Annotation Term="OData.Description" String="The number of bytes currently allocated by the storage system in this data store for this data type."/>
          <Annotation Term="OData.LongDescription" String="The value shall be the number of bytes currently allocated by the storage system in this data store for this data type."/>
          <Annotation Term="Measures.Unit" String="By"/>
        </Property>
        <Property Name="GuaranteedBytes" Type="Edm.Int64">
          <Annotation Term="OData.Description" String="The number of bytes the storage system guarantees can be allocated in this data store for this data type."/>
          <Annotation Term="OData.LongDescription" String="The value shall be the number of bytes the storage system guarantees can be allocated in this data store for this data type."/>
          <Annotation Term="Measures.Unit" String="By"/>
        </Property>
        <Property Name="ProvisionedBytes" Type="Edm.Int64">
          <Annotation Term="OData.Description" String="The maximum number of bytes that can be allocated in this data store for this data type."/>
          <Annotation Term="OData.LongDescription" String="The value shall be the maximum number of bytes that can be allocated in this data store for this data type."/>
          <Annotation Term="Measures.Unit" String="By"/>
        </Property>
      </ComplexType>

      <EntityType Name="CapacitySource" BaseType="Capacity.CapacitySource">
        <Annotation Term="OData.Description" String="A description of the type and source of storage."/>
        <Annotation
          Term="OData.LongDescription"
          String="This composition may be used to represent the source and type of storage capacity.  At most one of the ProvidingDrives, ProvidingVolumes, ProvidingMemoryChunks, ProvidingMemory or ProvidingPools properties may have a value.  If any of ProvidingDrives, ProvidingVolumes, ProvidingMemory or ProvidingPools reference more than one resource, allocation of capacity across those resources is implementation dependent."/>
        <Property Name="ProvidedCapacity" Type="Capacity.v1_0_0.Capacity">
          <Annotation Term="OData.Description" String="The amount of space that has been provided from the ProvidingDrives, ProvidingVolumes, ProvidingMemory or ProvidingPools."/>
          <Annotation Term="OData.LongDescription" String="The value shall be the amount of space that has been provided from the ProvidingDrives, ProvidingVolumes, ProvidingMemory or ProvidingPools."/>
        </Property>
        <NavigationProperty Name="ProvidedClassOfService" Type="ClassOfService.ClassOfService">
          <Annotation Term="OData.Description" String="The ClassOfService provided from the ProvidingDrives, ProvidingVolumes, ProvidingMemoryChunks, ProvidingMemory or ProvidingPools."/>
          <Annotation Term="OData.LongDescription" String="The value shall reference the provided ClassOfService from the ProvidingDrives, ProvidingVolumes, ProvidingMemoryChunks, ProvidingMemory or ProvidingPools."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="ProvidingVolumes" Type="VolumeCollection.VolumeCollection" ContainsTarget="true">
          <Annotation Term="OData.Description" String="The volume or volumes that provide this space."/>
          <Annotation Term="OData.LongDescription" String="If present, the value shall be a reference to a contributing volume or volumes."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="ProvidingPools" Type="StoragePoolCollection.StoragePoolCollection" ContainsTarget="true">
          <Annotation Term="OData.Description" String="The pool or pools that provide this space."/>
          <Annotation Term="OData.LongDescription" String="If present, the value shall be a reference to a contributing storage pool or storage pools."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="ProvidingDrives" Type="DriveCollection.DriveCollection" ContainsTarget="true">
          <Annotation Term="OData.Description" String="The drive or drives that provide this space."/>
          <Annotation Term="OData.LongDescription" String="If present, the value shall be a reference to a contributing drive or drives."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <!-- ToDo: Add Providing File, FileSystem, Object, ObjectStore, Memory... as appropriate. -->
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Capacity.v1_0_1">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in the previous namespace were updated."/>
      <EntityType Name="CapacitySource" BaseType="Capacity.v1_0_0.CapacitySource"/>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Capacity.v1_0_2">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <Annotation Term="OData.Description" String="This version was created to show CapacitySources is promoted from a ComplexType to an EntityType for compatibility with OData v4.0."/>
      <EntityType Name="CapacitySource" BaseType="Capacity.v1_0_1.CapacitySource">
        <Annotation Term="OData.Description" String="A description of the type and source of storage."/>
        <Annotation
          Term="OData.LongDescription"
          String="This composition may be used to represent the source and type of storage capacity.  At most one of the ProvidingDrives, ProvidingVolumes or ProvidingPools properties may have a value.  If any of ProvidingDrives, ProvidingVolumes or ProvidingPools reference more than one resource, allocation of capacity across those resources is implementation dependent."/>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Capacity.v1_0_3">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="CapacitySource" BaseType="Capacity.v1_0_2.CapacitySource"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Capacity.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <Annotation Term="OData.Description" String="This version was created to add ProvidingMemoryChunks and ProvidingMemory as contributing types to CapacitySource. Move ComplexTypes to unversioned namespace. Change references to unversioned."/>
      <EntityType Name="CapacitySource" BaseType="Capacity.v1_0_2.CapacitySource">
        <NavigationProperty Name="ProvidingMemoryChunks" Type="MemoryChunksCollection.MemoryChunksCollection" ContainsTarget="true">
          <Annotation Term="OData.Description" String="The memory chunks that provide this space."/>
          <Annotation Term="OData.LongDescription" String="If present, the value shall be a reference to the contributing memory chunks."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="ProvidingMemory" Type="MemoryCollection.MemoryCollection" ContainsTarget="true">
          <Annotation Term="OData.Description" String="The memory that provides this space."/>
          <Annotation Term="OData.LongDescription" String="If present, the value shall be a reference to the contributing memory."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Capacity.v1_1_1">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="CapacitySource" BaseType="Capacity.v1_1_0.CapacitySource"/>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_CAPACITY_V1_HPP */
