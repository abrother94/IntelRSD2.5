#ifndef PSME_REST_METADATA_REDUNDANCY_V1_HPP
#define PSME_REST_METADATA_REDUNDANCY_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Redundancy_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  Redundancy  v1.3.2-->
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
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="Redundancy" BaseType="Resource.v1_0_0.ReferenceableMember" Abstract="true">
        <Annotation Term="OData.Description" String="This is the common redundancy definition and structure used in other Redfish schemas."/>
        <Annotation Term="OData.LongDescription" String="This object represents the Redundancy element property.  All values for resources described by this schema shall comply to the requirements as described in the Redfish specification.  The value of this string shall be of the format for the reserved word *Redundancy*."/>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="1.0"/>

      <EntityType Name="Redundancy" BaseType="Redundancy.Redundancy">
        <Annotation Term="OData.Description" String="This is the redundancy definition to be used in other resource schemas."/>
        <Annotation Term="OData.LongDescription" String="This object represents the Redundancy element property.  All values for resources described by this schema shall comply to the requirements as described in the Redfish specification.  The value of this string shall be of the format for the reserved word *Redundancy*."/>
        <Property Name="Name" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"  String="The name of the resource or array element."/>
          <Annotation Term="OData.LongDescription" String="This object represents the Name property.  All values for resources described by this schema shall comply to the requirements as described in the Redfish specification. The value of this string shall be of the format for the reserved word *Name*."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="Mode" Type="Redundancy.v1_0_0.RedundancyMode">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This is the redundancy mode of the group."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain the information about the redundancy mode of this subsystem."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="MaxNumSupported" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the maximum number of members allowable for this particular redundancy group."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain the maximum number of members allowed in the redundancy group."/>
        </Property>
        <Property Name="MinNumNeeded" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the minumum number of members needed for this group to be redundant."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain the minimum number of members allowed in the redundancy group for the current redundancy mode to still be fault tolerant."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Description" String="This property describes the status and health of the resource and its children."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any status or health properties of the resource."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <NavigationProperty Name="RedundancySet" Type="Collection(Resource.Item)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Contains any ids that represent components of this redundancy set."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain the ids of components that are part of this redundancy set. The id values may or may not be dereferenceable."/>
          <Annotation Term="OData.AutoExpandReferences"/>
          <Annotation Term="Redfish.Required"/>
        </NavigationProperty>
      </EntityType>

      <TypeDefinition Name="RedundancyMode" UnderlyingType="Edm.String">
        <Annotation Term="Redfish.Enumeration">
          <Collection>
            <Record>
              <PropertyValue Property="Member" String="Failover"/>
              <Annotation Term="OData.Description" String="Failure of one unit will automatically cause its functions to be taken over by a standby or offline unit in the redundancy set."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="N+m"/>
              <Annotation Term="OData.Description" String="Multiple units are available and active such that normal operation will continue if one or more units fail."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Sharing"/>
              <Annotation Term="OData.Description" String="Multiple units contribute or share such that operation will continue, but at a reduced capacity, if one or more units fail."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Sparing"/>
              <Annotation Term="OData.Description" String="One or more spare units are available to take over the function of a failed unit, but takeover is not automatic."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="NotRedundant"/>
              <Annotation Term="OData.Description" String="The subsystem is not configured in a redundancy mode, either due to configuration or the functionality has been disabled by the user."/>
              <Annotation Term="Redfish.Revisions">
                <Collection>
                  <Record>
                    <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                    <PropertyValue Property="Version" String="v1_3_0"/>
                  </Record>
                </Collection>
              </Annotation>
            </Record>
          </Collection>
        </Annotation>
      </TypeDefinition>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_0_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_0_0.Redundancy"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_0_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_0_1.Redundancy"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_0_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_0_2.Redundancy"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_0_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to remove the Nullable facet on NavigationProperties of type Collection."/>
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_0_3.Redundancy"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_0_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_0_4.Redundancy"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_0_6">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation.  It was also created to remove the 'Required' term on MaxNumSupported."/>
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_0_5.Redundancy"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2016.2"/>
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_0_2.Redundancy">
        <Property Name="RedundancyEnabled" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This indicates whether redundancy is enabled."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a boolean indicating whether the redundancy is enabled."/>
        </Property>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_1_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_1_0.Redundancy"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_1_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to remove the Nullable facet on NavigationProperties of type Collection."/>
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_1_1.Redundancy"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_1_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_1_2.Redundancy"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_1_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation.  It was also created to remove the 'Required' term on MaxNumSupported."/>
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_1_3.Redundancy"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_2_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.1"/>
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_1_2.Redundancy">
        <Property Name="Actions" Type="Redundancy.v1_2_0.Actions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="Redundancy.v1_2_0.OemActions" Nullable="false">
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

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_2_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_2_0.Redundancy"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_2_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation.  It was also created to remove the 'Required' term on MaxNumSupported."/>
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_2_1.Redundancy"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_3_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.3"/>
      <Annotation Term="OData.Description" String="This version was created to add the 'NotRedundant' enumeration to Mode, enable read-write support for that property, and clarify its description."/>
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_2_0.Redundancy"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_3_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_3_0.Redundancy"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_3_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation.  It was also created to remove the 'Required' term on MaxNumSupported."/>
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_3_1.Redundancy"/>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_REDUNDANCY_V1_HPP */
