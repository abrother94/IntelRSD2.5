#ifndef PSME_REST_METADATA_SENSOR_COLLECTION_V1_HPP
#define PSME_REST_METADATA_SENSOR_COLLECTION_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string SensorCollection_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  SensorCollection-->
<!--#                                                                                      -->
<!--# For a detailed change log, see the README file contained in the DSP8010 bundle,      -->
<!--# available at http://www.dmtf.org/standards/redfish                                   -->
<!--# Copyright 2014-2017 Distributed Management Task Force, Inc. (DMTF).                  -->
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
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Sensor_v1.xml">
    <edmx:Include Namespace="Sensor"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="SensorCollection">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="SensorCollection" BaseType="Resource.v1_0_0.ResourceCollection">
        <Annotation Term="OData.Description" String="A Collection of Sensor resource instances."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent a Resource Collection of Sensor instances for a Redfish implementation."/>
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
            <String>/redfish/v1/Chassis/{ChassisId}/Sensors</String>
          </Collection>
        </Annotation>
        <NavigationProperty Name="Members" Type="Collection(Sensor.Sensor)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Contains the members of this collection."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain an array of references to the members of this collection."/>
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


#endif /* PSME_REST_METADATA_SENSOR_COLLECTION_V1_HPP */