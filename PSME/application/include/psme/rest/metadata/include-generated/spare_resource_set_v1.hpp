#ifndef PSME_REST_METADATA_SPARE_RESOURCE_SET_V1_HPP
#define PSME_REST_METADATA_SPARE_RESOURCE_SET_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string SpareResourceSet_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!-- Copyright 2015-2017 Storage Networking Industry Association (SNIA), USA. All rights reserved.-->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource"/>
  <edmx:Include Namespace="Resource.v1_0_0"/>
    <edmx:Include Namespace="Resource.v1_5_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="SpareResourceSet">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <EntityType Name="SpareResourceSet" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="A description of a set of spare resources."/>
        <Annotation Term="OData.LongDescription" String="The values define a set of spares of a particular type."/>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="SpareResourceSet.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <EntityType Name="SpareResourceSet" BaseType="SpareResourceSet.SpareResourceSet">
        <Annotation Term="OData.Description" String="A description of a set if spare resources."/>
        <Annotation Term="OData.LongDescription" String="The values define a set of spares of a particular type."/>
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="ResourceType" Type="Edm.String">
          <Annotation Term="OData.Description" String="The type of resources in the set."/>
          <Annotation Term="OData.LongDescription" String="The type of resources in the set."/>
        </Property>
        <Property Name="TimeToProvision" Type="Edm.Duration">
          <Annotation Term="OData.Description" String="Amount of time needed to make an on-hand resource available as a spare."/>
          <Annotation Term="OData.LongDescription" String="Amount of time  needed to make an on-hand resource available as a spare."/>
        </Property>
        <Property Name="TimeToReplenish" Type="Edm.Duration">
          <Annotation Term="OData.Description" String="Amount of time needed to get more on-hand resources."/>
          <Annotation Term="OData.LongDescription" String="Amount of time to needed replenish consumed on-hand resources."/>
        </Property>
        <Property Name="OnHandLocation" Type="Resource.v1_5_0.Location">
          <Annotation Term="OData.Description" String="Location where this set of spares is kept."/>
          <Annotation Term="OData.LongDescription" String="The location where this set of spares is kept."/>
        </Property>
        <Property Name="OnLine" Type="Edm.Boolean">
          <Annotation Term="OData.Description" String="This set is available online."/>
          <Annotation Term="OData.LongDescription" String="This set shall be online."/>
        </Property>
        <Property Name="Links" Type="SpareResourceSet.v1_0_0.Links" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Contains links to other resources that are related to this resource."/>
          <Annotation Term="OData.LongDescription" String="This structure shall contain references to resources that are not contained within this resource."/>
        </Property>
      </EntityType>
      <ComplexType Name="Links" BaseType="Resource.Links">
        <NavigationProperty Name="OnHandSpares" Type="Collection(Resource.Item)">
          <Annotation Term="OData.Description" String="The type of resources in the set."/>
          <Annotation Term="OData.LongDescription" String="The type of resources in the set."/>
        </NavigationProperty>
        <NavigationProperty Name="ReplacementSpareSets" Type="Collection(SpareResourceSet.v1_0_0.SpareResourceSet)">
          <Annotation Term="OData.Description" String="Other spare sets that can be utilized to replenish this spare set."/>
          <Annotation Term="OData.LongDescription" String="Other spare sets that can be utilized to replenish this spare set."/>
        </NavigationProperty>
      </ComplexType>
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_SPARE_RESOURCE_SET_V1_HPP */
