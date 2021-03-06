#ifndef PSME_REST_METADATA_CLASS_OFSERVICE_COLLECTION_V1_HPP
#define PSME_REST_METADATA_CLASS_OFSERVICE_COLLECTION_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string ClassOfServiceCollection_v1_XML =
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
  <edmx:Reference Uri="/redfish/v1/metadata/ClassOfService_v1.xml">
    <edmx:Include Namespace="ClassOfService"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ClassOfServiceCollection">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <EntityType Name="ClassOfServiceCollection" BaseType="Resource.v1_0_0.ResourceCollection">
        <Annotation Term="OData.Description" String="A Collection of ClassOfService resource instances."/>
        <Annotation Term="OData.LongDescription" String="This collection shall contain references to all ClassOfService resource instances sharing the same parent resource."/>
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
            <String>Redfish/v1/StorageServices/{StorageServiceId}/ClassesOfService</String>
	    <String>Redfish/v1/StorageServices/{StorageServiceId}/ClassesOfService/Members</String>
	    <String>Redfish/v1/StorageServices/{StorageServiceId}/StoragePools/{StoragePoolId}/ClassesOfService</String>
	    <String>Redfish/v1/StorageServices/{StorageServiceId}/StoragePools/{StoragePoolId}/ClassesOfService/Members</String>
          </Collection>
        </Annotation>
        <NavigationProperty Name="Members" Type="Collection(ClassOfService.ClassOfService)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The value of each member references a ClassOfService resource."/>
          <Annotation Term="OData.LongDescription" String="The value of each member entry shall reference a ClassOfService resource."/>
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


#endif /* PSME_REST_METADATA_CLASS_OFSERVICE_COLLECTION_V1_HPP */
