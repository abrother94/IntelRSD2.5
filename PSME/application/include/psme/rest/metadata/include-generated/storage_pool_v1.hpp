#ifndef PSME_REST_METADATA_STORAGE_POOL_V1_HPP
#define PSME_REST_METADATA_STORAGE_POOL_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string StoragePool_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!-- Copyright 2015-2018 Storage Networking Industry Association (SNIA), USA. All rights reserved.-->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
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
    <edmx:Include Namespace="Validation.v1_0_0" Alias="Validation"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ClassOfService_v1.xml">
    <edmx:Include Namespace="ClassOfService"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ClassOfServiceCollection_v1.xml">
    <edmx:Include Namespace="ClassOfServiceCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Capacity_v1.xml">
    <edmx:Include Namespace="Capacity"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/VolumeCollection_v1.xml">
    <edmx:Include Namespace="VolumeCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/StoragePoolCollection_v1.xml">
    <edmx:Include Namespace="StoragePoolCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/IOStatistics_v1.xml">
    <edmx:Include Namespace="IOStatistics"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/SpareResourceSet_v1.xml">
    <edmx:Include Namespace="SpareResourceSet"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Drive_v1.xml">
    <edmx:Include Namespace="Drive"/>
  </edmx:Reference>

  <edmx:DataServices>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="StoragePool">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <EntityType Name="StoragePool" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="A container of data storage."/>
        <Annotation Term="OData.LongDescription" String="A container of data storage capable of providing capacity conforming to one of its supported classes of service. The storage pool does not support IO to its data storage."/>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="StoragePool.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <EntityType Name="StoragePool" BaseType="StoragePool.StoragePool">
        <Property Name="Identifier" Type="Resource.Identifier">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The value identifies this resource."/>
          <Annotation Term="OData.LongDescription" String="The value identifies this resource. The value shall be unique within the managed ecosystem."/>
        </Property>
        <Property Name="BlockSizeBytes" Type="Edm.Int64">
          <Annotation Term="Redfish.Deprecated" String="This property has been Deprecated in favor of StoragePool.v1_1_1.StoragePool.MaxBlockSizeBytes"/>
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Maximum Block size in bytes."/>
          <Annotation
            Term="OData.LongDescription"
            String="Maximum size in bytes of the blocks which form this Volume. If the block size is variable, then the maximum block size in bytes should be specified. If the block size is unknown or if a block concept is not valid (for example, with Memory), enter a 1."/>
          <Annotation Term="Measures.Unit" String="By"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="Capacity" Type="Capacity.Capacity">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Capacity utilization."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall provide an information about the actual utilization of the capacity within this storage pool."/>
        </Property>
        <NavigationProperty Name="CapacitySources" Type="Collection(Capacity.CapacitySource)" ContainsTarget="true">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of space allocations to this store."/>
          <Annotation Term="OData.LongDescription" String="Fully or partially consumed storage from a source resource. Each entry shall provide capacity allocation data from a named source resource."/>
        </NavigationProperty>
        <Property Name="LowSpaceWarningThresholdPercents" Type="Collection(Edm.Int64)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Low space warning threshold specified in percents."/>
          <Annotation
            Term="OData.LongDescription"
            String="Each time the following value is less than one of the values in the array the LOW_SPACE_THRESHOLD_WARNING event shall be triggered: Across all CapacitySources entries, percent = (SUM(AllocatedBytes) - SUM(ConsumedBytes))/SUM(AllocatedBytes)."/>
          <Annotation Term="Measures.Unit" String="%"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Validation.Maximum" Int="100"/>
        </Property>
        <NavigationProperty Name="AllocatedVolumes" Type="VolumeCollection.VolumeCollection" ContainsTarget="true">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the collection of volumes allocated from this storage pool."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain a reference to the collection of volumes allocated from this storage pool."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="AllocatedPools" Type="StoragePoolCollection.StoragePoolCollection" ContainsTarget="true">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the collection of storage pools allocated from this storage pool."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain a reference to the collection of storage pools allocated from this storage pool."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="ClassesOfService" Type="ClassOfServiceCollection.ClassOfServiceCollection" ContainsTarget="true">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The ClassesOfService supported by this storage pool."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain references to all classes of service supported by this storage pool. Capacity allocated from this storage pool shall conform to one of the referenced classes of service."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <Property Name="Links" Type="StoragePool.v1_0_0.Links" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Contains links to other resources that are related to this resource."/>
          <Annotation Term="OData.LongDescription" String="This structure shall contain references to resources that are not contained within this resource."/>
        </Property>
        <Property Name="Status" Type="Resource.Status"/>
      </EntityType>
      <ComplexType Name="Links" BaseType="Resource.Links">
        <NavigationProperty Name="DefaultClassOfService" Type="ClassOfService.ClassOfService">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The default class of service for entities allocated from this storage pool."/>
          <Annotation
            Term="OData.LongDescription"
            String="If present, this property shall reference the default class of service for entities allocated from this storage pool.  If the ClassesOfService collection is not empty, then the value of this property shall be one of its entries. If not present, the default class of service of the containing StorageService entity shall be used."/>
          <Annotation Term="OData.AutoExpandReferences"/>
          <Annotation Term="Redfish.Deprecated" String="Default ClassOfService moved from Links to NavigationProperty."/>
        </NavigationProperty>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="StoragePool.v1_0_1">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="StoragePool" BaseType="StoragePool.v1_0_0.StoragePool"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="StoragePool.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <Annotation Term="OData.Description" String="This version adds the RemainingCapacityPercent property."/>
      <EntityType Name="StoragePool" BaseType="StoragePool.v1_0_1.StoragePool">
        <Property Name="RemainingCapacityPercent" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The percentage of the capacity remaining in the StoragePool."/>
          <Annotation Term="OData.LongDescription" String="If present, this value shall return  {[(SUM(AllocatedBytes) - SUM(ConsumedBytes)]/SUM(AllocatedBytes)}*100 represented as an integer value."/>
        </Property>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="StoragePool.v1_1_1">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <Annotation Term="OData.Description" String="This version was for errata to StoragePool."/>
      <EntityType Name="StoragePool" BaseType="StoragePool.v1_1_0.StoragePool">
        <Annotation Term="OData.Description" String="CapacitySources changes from Property to NavigationProperty with ContainsTarget=true.  Fixes BlockSizeBytes to MaxBlockSizeBytes."/>
        <Property Name="MaxBlockSizeBytes" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Maximum Block size in bytes."/>
          <Annotation Term="OData.LongDescription" String="If present, the value is the maximum block size of an allocated resource. If the block size is unknown or if a block concept is not valid (for example, with Memory), this property shall be NULL."/>
          <Annotation Term="Measures.Unit" String="By"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="StoragePool.v1_1_2">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="StoragePool" BaseType="StoragePool.v1_1_1.StoragePool"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="StoragePool.v1_2_0">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <Annotation Term="OData.Description" String="This version was created to add RecoverableCapacitySourceCount, IOStatistics to StoragePool. It also moves DefaultClassOfService outside of Links complex type."/>
      <EntityType Name="StoragePool" BaseType="StoragePool.v1_1_1.StoragePool">
        <Annotation Term="OData.Description" String="A container of data storage."/>
        <Annotation Term="OData.LongDescription" String="A container of data storage capable of providing capacity conforming to one of its supported classes of service. The storage pool does not support IO to its data storage."/>
        <Property Name="IOStatistics" Type="IOStatistics.IOStatistics">
          <Annotation Term="OData.Description" String="Statistics for this StoragePool."/>
          <Annotation Term="OData.LongDescription" String="The value shall represent IO statistics for this StoragePool."/>
        </Property>
        <Property Name="RecoverableCapacitySourceCount" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Current number of capacity source resources that are available as replacements."/>
          <Annotation Term="OData.LongDescription" String="The value is the number of available capacity source resources currently available in the event that an equivalent capacity source resource fails."/>
        </Property>
        <NavigationProperty Name="DefaultClassOfService" Type="ClassOfService.ClassOfService">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The default class of service for entities allocated from this storage pool."/>
          <Annotation
            Term="OData.LongDescription"
            String="If present, this property shall reference the default class of service for entities allocated from this storage pool.  If the ClassesOfService collection is not empty, then the value of this property shall be one of its entries. If not present, the default class of service of the containing StorageService entity shall be used."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

      <ComplexType Name="Links" BaseType="StoragePool.v1_0_0.Links">
        <Annotation Term="OData.Description" String="This version was created to add DedicatedSpareDrives and SpareResourceSets."/>
        <NavigationProperty Name="DedicatedSpareDrives" Type="Collection(Drive.Drive)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the drives which are dedicated spares for this StoragePool."/>
          <Annotation
            Term="OData.LongDescription"
            String="The value of this property shall be a reference to the resources that this StoragePool is associated with and shall reference resources of type Drive. This property shall only contain references to Drive entities which are currently assigned as a dedicated spare and are able to support this StoragePool."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="SpareResourceSets" Type="Collection(SpareResourceSet.SpareResourceSet)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="An array of references to SpareResourceSets."/>
          <Annotation Term="OData.LongDescription" String="Each referenced SpareResourceSet shall contain resources that may be utilized to replace the capacity provided by a failed resource having a compatible type."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_STORAGE_POOL_V1_HPP */
