#ifndef PSME_REST_METADATA_STORAGE_GROUP_COLLECTION_V1_HPP
#define PSME_REST_METADATA_STORAGE_GROUP_COLLECTION_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string StorageGroupCollection_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!-- Copyright 2015-2018 Storage Networking Industry Association (SNIA), USA. All rights reserved.-->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Capabilities.V1.xml">
    <edmx:Include Namespace="Org.OData.Capabilities.V1" Alias="Capabilities"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource.v1_0_0" />
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/StorageGroup_v1.xml">
    <edmx:Include Namespace="StorageGroup"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="StorageGroupCollection">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <EntityType Name="StorageGroupCollection" BaseType="Resource.v1_0_0.ResourceCollection">
        <Annotation Term="OData.Description" String="A Collection of StorageGroup resource instances."/>
        <Annotation Term="OData.LongDescription" String="This collection shall contain references to all StorageGroup resource instances sharing the same parent resource."/>
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
            <String>/redfish/v1/StorageServices/{StorageServiceId}/StorageGroups</String>
            <String>/redfish/v1/StorageServices/{StorageServiceId}/Volumes/{VolumeId}/StorageGroups</String>
          </Collection>
        </Annotation>
        <NavigationProperty Name="Members" Type="Collection(StorageGroup.StorageGroup)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The value of each member references a StorageGroup resource."/>
          <Annotation Term="OData.LongDescription" String="The value of each member entry shall reference a StorageGroup resource."/>
          <Annotation Term="OData.AutoExpandReferences"/>
          <Annotation Term="Redfish.Required"/>
        </NavigationProperty>
      </EntityType>

    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_STORAGE_GROUP_COLLECTION_V1_HPP */
