#ifndef PSME_REST_METADATA_ETHERNET_SWITCH_PORT_METRICS_V1_HPP
#define PSME_REST_METADATA_ETHERNET_SWITCH_PORT_METRICS_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string EthernetSwitchPortMetrics_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  EthernetSwitchPortMetrics  v1.1.0-->
<!--#                                                                                      -->
<!--# For a detailed change log, see the README file contained in the DSP8010 bundle,      -->
<!--# available at http://www.dmtf.org/standards/redfish                                   -->
<!--# Copyright 2014-2016 Distributed Management Task Force, Inc. (DMTF).                  -->
<!--# For the full DMTF copyright policy, see http://www.dmtf.org/about/policies/copyright -->
<!--################################################################################       -->
<!---->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Measures.V1.xml">
    <edmx:Include Namespace="Org.OData.Measures.V1" Alias="Measures"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="EthernetSwitchPortMetrics">

      <EntityType Name="EthernetSwitchPortMetrics" BaseType="Resource.v1_0_0.Resource" Abstract="true">
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="EthernetSwitchPortMetrics.v1_0_0">

      <EntityType Name="EthernetSwitchPortMetrics" BaseType="EthernetSwitchPortMetrics.EthernetSwitchPortMetrics">
        <Property Name="Received" Type="EthernetSwitchPortMetrics.v1_0_0.Metrics">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Port Receive metrics."/>
          <Annotation Term="OData.LongDescription" String="This property shall represent port receive metrics."/>
          <Annotation Term="Measures.Unit" String="By"/>
        </Property>

        <Property Name="Transmitted" Type="EthernetSwitchPortMetrics.v1_0_0.Metrics">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Port Transmit metrics."/>
          <Annotation Term="OData.LongDescription" String="This property shall represent port transmit metrics."/>
          <Annotation Term="Measures.Unit" String="By"/>
        </Property>
        <Property Name="Collisions" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Collisions counter."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be Port collisions counter."/>
        </Property>

      </EntityType>

      <ComplexType Name="Metrics">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Packets" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Packets counter."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be Port packets counter."/>
        </Property>
        <Property Name="DroppedPackets" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Dropped packets counter."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be Port dropped packets counter."/>
        </Property>
        <Property Name="ErrorPackets" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Error packets counter."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be Port error packets counter."/>
        </Property>
        <Property Name="BroadcastPackets" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Broadcast packets counter."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be Port broadcast packets counter."/>
        </Property>
        <Property Name="MulticastPackets" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Multicats packets counter."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be Port multicast packets counter."/>
        </Property>
        <Property Name="Bytes" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Bytes counter."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be Port bytes counter."/>
          <Annotation Term="Measures.Unit" String="By"/>
        </Property>
        <Property Name="Errors" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Error counter."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be Port error counter."/>
        </Property>
      </ComplexType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Oem" Type="EthernetSwitchPortMetrics.v1_0_0.OemActions" Nullable="false"/>
      </ComplexType>

      <ComplexType Name="OemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
      </ComplexType>

    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_ETHERNET_SWITCH_PORT_METRICS_V1_HPP */
