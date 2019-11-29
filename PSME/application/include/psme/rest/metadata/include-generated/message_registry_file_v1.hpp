#ifndef PSME_REST_METADATA_MESSAGE_REGISTRY_FILE_V1_HPP
#define PSME_REST_METADATA_MESSAGE_REGISTRY_FILE_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string MessageRegistryFile_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  MessageRegistryFile  v1.1.1-->
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
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistryFile">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="MessageRegistryFile" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="This is the schema definition for the Schema File locator resource."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent the Schema File locator resource for a Redfish implementation."/>
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
            <String>/redfish/v1/Registries/{MessageRegistryFileId}</String>
          </Collection>
        </Annotation>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistryFile.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2016.1"/>

      <EntityType Name="MessageRegistryFile" BaseType="MessageRegistryFile.MessageRegistryFile">
        <Annotation Term="OData.Description" String="This is the schema definition for the Schema File locator resource."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent the Schema File locator resource for a Redfish implementation."/>
        <Property Name="Languages" Type="Collection(Edm.String)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Language codes for the schemas available."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a string consisting of an RFC 5646 language code."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="Registry" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Registry Name, Major, and Minor version.  This Registry can reference any type of Registry, such as a Message Registry, Privilege Registry, or Attribute Registry."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the value of the Registry Name, Major, and Minor version.  This Registry may reference any type of Registry, such as a Message Registry, Privilege Registry, or Attribute Registry."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="Location" Type="Collection(MessageRegistryFile.v1_0_0.Location)" Nullable="false">
          <Annotation Term="OData.Description" String="Location information for this registry file."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the location information for this registry file."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
      </EntityType>

      <ComplexType Name="Location">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="Location information for a schema file."/>
        <Annotation Term="OData.LongDescription" String="This type shall define Location information for a schema file."/>
        <Property Name="Language" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The language code for the file the schema is in."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a string consisting of an RFC5646 language code or the string 'default'."/>
        </Property>
        <Property Name="Uri" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Link to locally available URI for schema."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a URI co-located with the Redfish service that specifies the location of the schema file.  This property shall only be used for individual schema files.  The file name portion of the URI shall conform to the syntax specified in the Redfish specification."/>
          <Annotation Term="OData.IsURL"/>
        </Property>
        <Property Name="ArchiveUri" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="If the schema is hosted on the service in an archive file, this is the link to the archive file."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a URI co-located with the Redfish service that specifies the location of the schema file.  This property shall only be used for archive files (zip or other formats).  The value of ArchiveFile shall have the file name of the individual schema file within the archive file."/>
          <Annotation Term="OData.IsURL"/>
        </Property>
        <Property Name="PublicationUri" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Link to publicly available (canonical) URI for schema."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a URI not co-located with the Redfish service that specifies the canonical location of the schema file.  This property shall only be used for individual schema files."/>
          <Annotation Term="OData.IsURL"/>
        </Property>
        <Property Name="ArchiveFile" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="If the schema is hosted on the service in an archive file, this is the name of the file within the archive."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the file name of the individual schema file within the archive file specified by the ArchiveUri property. The file name shall conform to the syntax specified in the Redfish specification."/>
        </Property>
      </ComplexType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistryFile.v1_0_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="MessageRegistryFile" BaseType="MessageRegistryFile.v1_0_0.MessageRegistryFile"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistryFile.v1_0_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="MessageRegistryFile" BaseType="MessageRegistryFile.v1_0_2.MessageRegistryFile"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistryFile.v1_0_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="MessageRegistryFile" BaseType="MessageRegistryFile.v1_0_3.MessageRegistryFile"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistryFile.v1_0_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number.  It was also updated to clarify the description for Registry."/>
      <EntityType Name="MessageRegistryFile" BaseType="MessageRegistryFile.v1_0_4.MessageRegistryFile"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistryFile.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.1"/>
      <EntityType Name="MessageRegistryFile" BaseType="MessageRegistryFile.v1_0_4.MessageRegistryFile">
        <Property Name="Actions" Type="MessageRegistryFile.v1_1_0.Actions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="MessageRegistryFile.v1_1_0.OemActions" Nullable="false">
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

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistryFile.v1_1_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number.  It was also updated to clarify the description for Registry."/>
      <EntityType Name="MessageRegistryFile" BaseType="MessageRegistryFile.v1_1_0.MessageRegistryFile"/>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_MESSAGE_REGISTRY_FILE_V1_HPP */
