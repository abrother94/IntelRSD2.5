#ifndef PSME_REST_METADATA_MESSAGE_REGISTRY_V1_HPP
#define PSME_REST_METADATA_MESSAGE_REGISTRY_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string MessageRegistry_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  MessageRegistry  v1.2.0-->
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
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
    <edmx:Include Namespace="Validation.v1_0_0" Alias="Validation"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistry">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="MessageRegistry" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="This is the schema definition for all Message Registries.  It represents the properties for the registries themselves.  The MessageId is formed per the Redfish specification.  It consists of the RegistryPrefix concatenated with the version concatenated with the unique identifier for the message registry entry."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent a message registry for a Redfish implementation."/>
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
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistry.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="1.0"/>

      <EntityType Name="MessageRegistry" BaseType="MessageRegistry.MessageRegistry">
        <Property Name="Language" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the RFC 5646 compliant language code for the registry."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a string consisting of an RFC 5646 language code."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="RegistryPrefix" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the single word prefix used to form a messageID structure."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the prefix used in messageIDs which uniquely identifies all of the messages in this registry as belonging to this registry."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="RegistryVersion" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the message registry version which is used in the middle portion of a messageID."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the version of this message registry.   The format of this string shall be of the format majorversion.minorversion.errata in compliance with Protocol Version section of the Redfish specification."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="OwningEntity" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the organization or company that publishes this registry."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a string that represents the publisher of this registry."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="Messages" Type="MessageRegistry.v1_0_0.MessageProperty" Nullable="false">
          <Annotation Term="OData.Description" String="The pattern property indicates that a free-form string is the unique identifier for the message within the registry."/>
          <Annotation Term="OData.LongDescription" String="The pattern property shall represent the suffix to be used in the MessageId and shall be unique within this message registry."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
      </EntityType>

      <ComplexType Name="MessageProperty" OpenType="true">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The pattern type indicates that a free-form string is the unique identifier for the message within the registry."/>
        <Annotation Term="OData.LongDescription" String="The pattern type shall represent the suffix to be used in the MessageId and shall be unique within this message registry."/>
        <Annotation Term="Redfish.DynamicPropertyPatterns">
          <Collection>
            <Record>
              <PropertyValue Property="Pattern" String="[A-Za-z0-9]+"/>
              <PropertyValue Property="Type" String="MessageRegistry.v1_0_0.Message"/>
            </Record>
          </Collection>
        </Annotation>
      </ComplexType>

      <ComplexType Name="Message">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This type shall reprensent how a message is defined within the registry."/>
        <Annotation Term="OData.LongDescription" String="The type shall represent how a message is defined within within a message registry."/>
        <Property Name="Description" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a short description of how and when this message is to be used."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate how and when this message is returned by the Redfish service."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="Message" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The actual message."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the message to be displayed.  If a %integer is included in part of the string, it shall be used to represent a string substitution for any MessageArgs accompanying the message, in order."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="Severity" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the severity of the message."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the severity of the condition resulting in the message, as defined in the Status section of the Redfish specification."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="NumberOfArgs" Type="Edm.Int64" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The number of arguments to be expected to be passed in as MessageArgs for this message."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the number of MessageArgs that are expected to be substituted in the Message in the locations within the Message marked by %&lt;integer&gt;."/>
          <Annotation Term="Redfish.Required"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="ParamTypes" Type="Collection(MessageRegistry.v1_0_0.ParamType)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The MessageArg types, in order, for the message."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an ordered array of parameter types which match the types of the MessageArgs, in order."/>
        </Property>
        <Property Name="Resolution" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Used to provide suggestions on how to resolve the situation that caused the error."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain an override of the Resolution of the message in message registry, if present."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="Oem" Type="Resource.Oem" Nullable="false">
          <Annotation Term="OData.Description" String="Oem extension object."/>
          <Annotation Term="OData.LongDescription" String="This object represents the Oem property.  All values for resources described by this schema shall comply to the requirements as described in the Redfish specification."/>
        </Property>
      </ComplexType>

      <EnumType Name="ParamType">
        <Member Name="string">
          <Annotation Term="OData.Description" String="The parameter is a string."/>
        </Member>
        <Member Name="number">
          <Annotation Term="OData.Description" String="The parameter is a number."/>
        </Member>
      </EnumType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistry.v1_0_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="MessageRegistry" BaseType="MessageRegistry.v1_0_0.MessageRegistry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistry.v1_0_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="MessageRegistry" BaseType="MessageRegistry.v1_0_2.MessageRegistry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistry.v1_0_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="MessageRegistry" BaseType="MessageRegistry.v1_0_3.MessageRegistry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistry.v1_0_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add descriptions to various enum values."/>
      <EntityType Name="MessageRegistry" BaseType="MessageRegistry.v1_0_4.MessageRegistry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistry.v1_0_6">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="MessageRegistry" BaseType="MessageRegistry.v1_0_5.MessageRegistry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistry.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.1"/>
      <EntityType Name="MessageRegistry" BaseType="MessageRegistry.v1_0_4.MessageRegistry">
        <Property Name="Actions" Type="MessageRegistry.v1_1_0.Actions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="MessageRegistry.v1_1_0.OemActions" Nullable="false">
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

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistry.v1_1_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add descriptions to various enum values."/>
      <EntityType Name="MessageRegistry" BaseType="MessageRegistry.v1_1_0.MessageRegistry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistry.v1_1_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="MessageRegistry" BaseType="MessageRegistry.v1_1_1.MessageRegistry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistry.v1_2_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.2"/>
      <Annotation Term="OData.Description" String="This version was created to add ClearingLogic to a MessageRegistry."/>

      <EntityType Name="MessageRegistry" BaseType="MessageRegistry.v1_1_2.MessageRegistry"/>

      <ComplexType Name="Message" BaseType="MessageRegistry.v1_0_0.Message">
        <Property Name="ClearingLogic" Type="MessageRegistry.v1_2_0.ClearingLogic">
          <Annotation Term="OData.Description" String="The clearing logic associated with this message.  The properties within indicate that what messages are cleared by this message as well as under what conditions."/>
          <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        </Property>
      </ComplexType>

      <ComplexType Name="ClearingLogic">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The clearing logic associated with this message.  The properties within indicate that what messages are cleared by this message as well as under what conditions."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="ClearsIf" Type="MessageRegistry.v1_2_0.ClearingType" Nullable="true">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This property contains the available OEM specific actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any additional OEM actions for this resource."/>
        </Property>
        <Property Name="ClearsMessage" Type="Collection(Edm.String)" Nullable="true">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This property contains the array of Message Ids that are cleared by this message, provided the other conditions are met."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain an array of Message Ids that are cleared by this message, provided the other conditions are met.  The Message Ids shall not include the Registry name or version and shall just be the Message Id portion.  Message Ids shall not reference other Message Registries."/>
        </Property>
        <Property Name="ClearsAll" Type="Edm.Boolean" Nullable="true">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This property indicates that all prior conditions and messages are cleared provided the ClearsIf condition is met."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate that all prior conditions and messages are cleared provided the ClearsIf condition is met."/>
        </Property>
      </ComplexType>

      <EnumType Name="ClearingType">
        <Annotation Term="OData.Description" String="The enumerations of ClearingType specify the choice of conditions on when an event is cleared."/>
        <Member Name="SameOriginOfCondition">
          <Annotation Term="OData.Description" String="Indicates the message is cleared by the other message(s) listed in the ClearingLogic object, provided the OriginOfCondition for both Events are the same."/>
        </Member>
      </EnumType>

    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_MESSAGE_REGISTRY_V1_HPP */
