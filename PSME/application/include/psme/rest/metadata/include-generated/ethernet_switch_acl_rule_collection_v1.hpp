#ifndef PSME_REST_METADATA_ETHERNET_SWITCH_ACL_RULE_COLLECTION_V1_HPP
#define PSME_REST_METADATA_ETHERNET_SWITCH_ACL_RULE_COLLECTION_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string EthernetSwitchACLRuleCollection_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?><!-- Copyright 2014-2015 Distributed Management Task Force, Inc. (DMTF). All rights reserved.-->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/EthernetSwitchACLRule_v1.xml">
    <edmx:Include Namespace="EthernetSwitchACLRule.v1_0_0"/>
  </edmx:Reference>

  <edmx:DataServices>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="EthernetSwitchACLRuleCollection">

      <EntityType Name="EthernetSwitchACLRuleCollection" BaseType="Resource.v1_0_0.ResourceCollection">
        <NavigationProperty Name="Members" Type="Collection(EthernetSwitchACLRule.v1_0_0.EthernetSwitchACLRule)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Contains the members of this collection."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_ETHERNET_SWITCH_ACL_RULE_COLLECTION_V1_HPP */
