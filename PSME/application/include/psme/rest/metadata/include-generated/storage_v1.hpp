#ifndef PSME_REST_METADATA_STORAGE_V1_HPP
#define PSME_REST_METADATA_STORAGE_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Storage_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  Storage  v1.5.1-->
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
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Measures.V1.xml">
    <edmx:Include Namespace="Org.OData.Measures.V1" Alias="Measures"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
    <edmx:Include Namespace="Validation.v1_0_0" Alias="Validation"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Chassis_v1.xml">
    <edmx:Include Namespace="Chassis"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Redundancy_v1.xml">
    <edmx:Include Namespace="Redundancy"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Drive_v1.xml">
    <edmx:Include Namespace="Drive"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/VolumeCollection_v1.xml">
    <edmx:Include Namespace="VolumeCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Endpoint_v1.xml">
    <edmx:Include Namespace="Endpoint"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Assembly_v1.xml">
    <edmx:Include Namespace="Assembly"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Protocol_v1.xml">
    <edmx:Include Namespace="Protocol"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/PCIeDevice_v1.xml">
    <edmx:Include Namespace="PCIeDevice"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/StorageService_v1.xml">
    <edmx:Include Namespace="StorageService"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Volume_v1.xml">
    <edmx:Include Namespace="Volume"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="Storage" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="Storage defines a storage subsystem and its respective properties.  A storage subsystem represents a set of storage controllers (physical or virtual) and the resources such as volumes that can be accessed from that subsystem."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent resources that represent a storage subsystem in the Redfish specification."/>
        <Annotation Term="Capabilities.InsertRestrictions">
          <Record>
            <PropertyValue Property="Insertable" Bool="false"/>
          </Record>
        </Annotation>
        <Annotation Term="Capabilities.UpdateRestrictions">
          <Record>
            <PropertyValue Property="Updatable" Bool="true"/>
            <Annotation Term="OData.Description" String="Storage can be updated to change AssetTag and other writable properties."/>
          </Record>
        </Annotation>
        <Annotation Term="Capabilities.DeleteRestrictions">
          <Record>
            <PropertyValue Property="Deletable" Bool="false"/>
          </Record>
        </Annotation>
        <Annotation Term="Redfish.Uris">
          <Collection>
            <String>/redfish/v1/Systems/{ComputerSystemId}/Storage/{StorageId}</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Storage/{StorageId}</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/Storage/{StorageId}</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Storage/{StorageId}</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/Storage/{StorageId}</String>
          </Collection>
        </Annotation>
      </EntityType>

      <EntityType Name="StorageController" BaseType="Resource.v1_0_0.ReferenceableMember" Abstract="true">
        <Annotation Term="OData.Description" String="This schema defines a storage controller and its respective properties.  A storage controller represents a storage device (physical or virtual) that produces Volumes."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent a resource that represents a storage controller in the Redfish specification."/>
      </EntityType>

      <Action Name="SetEncryptionKey" IsBound="true">
        <Parameter Name="Storage" Type="Storage.v1_0_0.Actions"/>
        <Parameter Name="EncryptionKey" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Description" String="The encryption key to set on the storage subsytem."/>
          <Annotation Term="OData.LongDescription" String="This parameter shall contain the encryption key to set on the storage subsystem."/>
        </Parameter>
        <Annotation Term="OData.Description" String="This action is used to set the encryption key for the storage subsystem."/>
        <Annotation Term="OData.LongDescription" String="This action shall set the encryption key for the storage subsystem."/>
      </Action>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2016.1"/>

      <EntityType Name="Storage" BaseType="Storage.Storage">
        <Annotation Term="OData.Description" String="This schema defines a storage subsystem and its respective properties.  A storage subsystem represents a set of storage controllers (physical or virtual) and the resources such as volumes that can be accessed from that subsystem."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent resources that represent a storage subsystem in the Redfish specification."/>
        <NavigationProperty Name="StorageControllers" Type="Collection(Storage.v1_0_0.StorageController)" ContainsTarget="true">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The set of storage controllers represented by this resource."/>
          <Annotation Term="OData.LongDescription" String="A collection that indicates all the storage controllers that this resource represents."/>
          <Annotation Term="OData.AutoExpand"/>
        </NavigationProperty>
        <NavigationProperty Name="Drives" Type="Collection(Drive.Drive)" ContainsTarget="true">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The set of drives attached to the storage controllers represented by this resource."/>
          <Annotation Term="OData.LongDescription" String="A collection that indicates all the drives attached to the storage controllers that this resource represents."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Volumes" Type="VolumeCollection.VolumeCollection" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The set of volumes produced by the storage controllers represented by this resource."/>
          <Annotation Term="OData.LongDescription" String="A collection that indicates all the volumes produced by the storage controllers that this resource represents."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <Property Name="Links" Type="Storage.v1_0_0.Links" Nullable="false">
          <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
          <Annotation Term="OData.LongDescription" String="The Links property, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        </Property>
        <Property Name="Actions" Type="Storage.v1_0_0.Actions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Description" String="This property describes the status and health of the resource and its children."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any status or health properties of the resource."/>
        </Property>
        <NavigationProperty Name="Redundancy" Type="Collection(Redundancy.Redundancy)" ContainsTarget="true">
          <Annotation Term="OData.Description" String="Redundancy information for the storage subsystem."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain redundancy information for the storage subsystem."/>
          <Annotation Term="OData.AutoExpand"/>
        </NavigationProperty>
      </EntityType>

      <ComplexType Name="Links" BaseType="Resource.Links">
        <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
        <Annotation Term="OData.LongDescription" String="This type, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        <NavigationProperty Name="Enclosures" Type="Collection(Chassis.Chassis)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the chassis to which this storage subsystem is attached."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall reference a resource of type Chassis that represents the physical containers attached to this resource."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="Storage.v1_0_0.OemActions" Nullable="false">
          <Annotation Term="OData.Description" String="This property contains the available OEM specific actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any additional OEM actions for this resource."/>
        </Property>
      </ComplexType>

      <ComplexType Name="OemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
        <Annotation Term="OData.Description" String="The available OEM specific actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain any additional OEM actions for this resource."/>
      </ComplexType>

      <EntityType Name="StorageController" BaseType="Storage.StorageController">
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Description" String="This property describes the status and health of the resource and its children."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any status or health properties of the resource."/>
        </Property>
        <Property Name="SpeedGbps" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The maximum speed of the storage controller's device interface."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the maximum supported speed of the Storage bus interface (in Gigabits per second). The interface specified connects the controller to the storage devices, not the controller to a host (e.g. SAS bus, not PCIe host bus)."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Measures.Unit" String="Gbit/s"/>
        </Property>
        <Property Name="FirmwareVersion" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The firmware version of this storage Controller."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the firwmare version as defined by the manufacturer for the associated storage controller."/>
        </Property>
        <Property Name="Manufacturer" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the manufacturer of this storage controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the name of the organization responsible for producing the storage controller. This organization might be the entity from whom the storage controller is purchased, but this is not necessarily true."/>
        </Property>
        <Property Name="Model" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the model number for the storage controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the name by which the manufacturer generally refers to the storage controller."/>
        </Property>
        <Property Name="SKU" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the SKU for this storage controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the stock-keeping unit number for this storage storage controller."/>
        </Property>
        <Property Name="SerialNumber" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The serial number for this storage controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a manufacturer-allocated number used to identify the storage controller."/>
        </Property>
        <Property Name="PartNumber" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The part number for this storage controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a part number assigned by the organization that is responsible for producing or manufacturing the storage controller."/>
        </Property>
        <Property Name="AssetTag" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The user assigned asset tag for this storage controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an identifying string used to track the storage controller for inventory purposes."/>
        </Property>
        <Property Name="SupportedControllerProtocols" Type="Collection(Protocol.Protocol)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This represents the protocols by which this storage controller can be communicated to."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the set of protocols this storage controller can be communicated to."/>
        </Property>
        <Property Name="SupportedDeviceProtocols" Type="Collection(Protocol.Protocol)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This represents the protocols which the storage controller can use to communicate with attached devices."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the set of protocols this storage controller can use to communicate with attached devices."/>
        </Property>
        <Property Name="Identifiers" Type="Collection(Resource.Identifier)" Nullable="false">
          <Annotation Term="OData.Description" String="The Durable names for the storage controller."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain a list of all known durable names for the associated storage controller."/>
        </Property>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_0_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Storage" BaseType="Storage.v1_0_0.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_0_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Storage" BaseType="Storage.v1_0_1.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_0_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to remove the Nullable facet on NavigationProperties of type Collection."/>
      <EntityType Name="Storage" BaseType="Storage.v1_0_2.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_0_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to change references to Identifier to be its abstract base type, to add an abstract definition of StorageController, and to deprecate the versioned definition of Protocol to use an unversioned definition.  It was also created to add requirements on the action parameters to show they are mandatory via Nullable=false.  It was also created to correct the Descriptions and LongDescriptions used in the defined Actions."/>
      <EntityType Name="Storage" BaseType="Storage.v1_0_3.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_0_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Storage" BaseType="Storage.v1_0_4.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_0_6">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation.  It was also created to change the VolumeCollection reference to Swordfish."/>
      <EntityType Name="Storage" BaseType="Storage.v1_0_5.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2016.2"/>
      <EntityType Name="Storage" BaseType="Storage.v1_0_1.Storage"/>
      <EntityType Name="StorageController" BaseType="Storage.v1_0_0.StorageController">
        <Property Name="Links" Type="Storage.v1_1_0.StorageControllerLinks" Nullable="false">
          <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
          <Annotation Term="OData.LongDescription" String="The Links property, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="StorageControllerLinks" BaseType="Resource.Links">
        <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
        <Annotation Term="OData.LongDescription" String="This type, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        <NavigationProperty Name="Endpoints" Type="Collection(Endpoint.Endpoint)">
          <Annotation Term="OData.Description" String="An array of references to the endpoints that connect to this controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a reference to the resources that this controller is associated with and shall reference a resource of type Endpoint."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_1_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Storage" BaseType="Storage.v1_1_0.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_1_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to remove the Nullable facet on NavigationProperties of type Collection."/>
      <EntityType Name="Storage" BaseType="Storage.v1_1_1.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_1_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to change references to Identifier to be its abstract base type, to add an abstract definition of StorageController, and to deprecate the versioned definition of Protocol to use an unversioned definition.  It was also created to add requirements on the action parameters to show they are mandatory via Nullable=false.  It was also created to correct the Descriptions and LongDescriptions used in the defined Actions."/>
      <EntityType Name="Storage" BaseType="Storage.v1_1_2.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_1_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Storage" BaseType="Storage.v1_1_3.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_1_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation.  It was also created to change the VolumeCollection reference to Swordfish."/>
      <EntityType Name="Storage" BaseType="Storage.v1_1_4.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_2_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.1"/>
      <EntityType Name="Storage" BaseType="Storage.v1_1_2.Storage"/>
      <EntityType Name="StorageController" BaseType="Storage.v1_1_0.StorageController">
        <Property Name="Actions" Type="Storage.v1_2_0.StorageControllerActions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="StorageControllerActions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="Storage.v1_2_0.StorageControllerOemActions" Nullable="false">
          <Annotation Term="OData.Description" String="This property contains the available OEM specific actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any additional OEM actions for this resource."/>
        </Property>
      </ComplexType>

      <ComplexType Name="StorageControllerOemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
        <Annotation Term="OData.Description" String="The available OEM specific actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain any additional OEM actions for this resource."/>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_2_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to change references to Identifier to be its abstract base type, to add an abstract definition of StorageController, and to deprecate the versioned definition of Protocol to use an unversioned definition.  It was also created to add requirements on the action parameters to show they are mandatory via Nullable=false.  It was also created to correct the Descriptions and LongDescriptions used in the defined Actions."/>
      <EntityType Name="Storage" BaseType="Storage.v1_2_0.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_2_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Storage" BaseType="Storage.v1_2_1.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_2_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation.  It was also created to change the VolumeCollection reference to Swordfish."/>
      <EntityType Name="Storage" BaseType="Storage.v1_2_2.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_3_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.2"/>
      <EntityType Name="Storage" BaseType="Storage.v1_2_0.Storage"/>
      <EntityType Name="StorageController" BaseType="Storage.v1_2_0.StorageController">
        <Property Name="Name" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The name of the Storage Controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the name of the Storage Controller."/>
        </Property>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_3_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to move Protocols to its own CSDL file.  It was also created to add requirements on the action parameters to show they are mandatory via Nullable=false.  It was also created to correct the Descriptions and LongDescriptions used in the defined Actions."/>
      <EntityType Name="Storage" BaseType="Storage.v1_3_0.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_3_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Storage" BaseType="Storage.v1_3_1.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_3_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation.  It was also created to change the VolumeCollection reference to Swordfish."/>
      <EntityType Name="Storage" BaseType="Storage.v1_3_2.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_4_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.3"/>
      <EntityType Name="Storage" BaseType="Storage.v1_3_1.Storage"/>
      <EntityType Name="StorageController" BaseType="Storage.v1_3_0.StorageController">
        <Property Name="Location" Type="Resource.Location" Nullable="false">
          <Annotation Term="OData.Description" String="The Location of the storage controller."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain location information of the associated storage controller."/>
        </Property>
        <NavigationProperty Name="Assembly" Type="Assembly.Assembly" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the Assembly resource associated with this Storage Controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a link to a resource of type Assembly."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

      <ComplexType Name="StorageControllerLinks" BaseType="Storage.v1_1_0.StorageControllerLinks">
        <NavigationProperty Name="StorageServices" Type="Collection(StorageService.StorageService)">
          <Annotation Term="OData.Description" String="An array of references to the StorageServices that connect to this controller."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a reference to the resources that this controller is associated with and shall reference a resource of type StorageService."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_4_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Storage" BaseType="Storage.v1_4_0.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_4_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation.  It was also created to change the VolumeCollection reference to Swordfish."/>
      <EntityType Name="Storage" BaseType="Storage.v1_4_1.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_5_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.2"/>
      <EntityType Name="Storage" BaseType="Storage.v1_4_1.Storage"/>
      <EntityType Name="StorageController" BaseType="Storage.v1_4_0.StorageController">
        <Property Name="CacheSummary" Type="Storage.v1_5_0.CacheSummary" Nullable="false">
          <Annotation Term="OData.Description" String="This object describes the cache memory of the storage controller in general detail."/>
          <Annotation Term="OData.LongDescription" String="This object shall contain properties which describe the cache memory for the current resource."/>
        </Property>
        <Property Name="PCIeInterface" Type="PCIeDevice.PCIeInterface">
          <Annotation Term="OData.Description" String="The PCIe interface details for this controller."/>
          <Annotation Term="OData.LongDescription" String="This object shall contain details on the PCIe interface used to connect this PCIe-based controller to its host."/>
        </Property>
      </EntityType>

      <ComplexType Name="CacheSummary">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This object describes the cache memory of the storage controller in general detail."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain properties which describe the cache memory for a storage controller."/>
        <Property Name="TotalCacheSizeMiB" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The total configured cache memory, measured in MiB."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the amount of configured cache memory as measured in mebibytes."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Measures.Unit" String="MiBy"/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="PersistentCacheSizeMiB" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The portion of the cache memory that is persistent, measured in MiB."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the amount of cache memory that is persistent as measured in mebibytes. This size shall be less than or equal to the TotalCacheSizeMib."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Measures.Unit" String="MiBy"/>
        </Property>
        <Property Name="Status" Type="Resource.Status"  Nullable="false">
          <Annotation Term="OData.Description" String="This property describes the status and health of the resource and its children."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any status or health properties of the resource."/>
        </Property>
      </ComplexType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_5_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation.  It was also created to change the VolumeCollection reference to Swordfish."/>
      <EntityType Name="Storage" BaseType="Storage.v1_5_0.Storage"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Storage.v1_6_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.3"/>
      <EntityType Name="Storage" BaseType="Storage.v1_4_1.Storage"/>
      <EntityType Name="StorageController" BaseType="Storage.v1_5_0.StorageController">
        <Property Name="SupportedRAIDTypes" Type="Collection(Volume.RAIDType)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This object describes the RAID Types supported by the storage controller."/>
          <Annotation Term="OData.LongDescription" String="This object shall contain all the RAIDType values supported by the current resource."/>
        </Property>
      </EntityType>

    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_STORAGE_V1_HPP */
