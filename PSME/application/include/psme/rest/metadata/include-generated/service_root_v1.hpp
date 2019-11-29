#ifndef PSME_REST_METADATA_SERVICE_ROOT_V1_HPP
#define PSME_REST_METADATA_SERVICE_ROOT_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string ServiceRoot_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  ServiceRoot  v1.5.0-->
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
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
    <edmx:Include Namespace="Validation.v1_0_0" Alias="Validation"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/EventService_v1.xml">
    <edmx:Include Namespace="EventService"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/AccountService_v1.xml">
    <edmx:Include Namespace="AccountService"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ComputerSystemCollection_v1.xml">
    <edmx:Include Namespace="ComputerSystemCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ChassisCollection_v1.xml">
    <edmx:Include Namespace="ChassisCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ManagerCollection_v1.xml">
    <edmx:Include Namespace="ManagerCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/TaskService_v1.xml">
    <edmx:Include Namespace="TaskService"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/SessionService_v1.xml">
    <edmx:Include Namespace="SessionService"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/JsonSchemaFileCollection_v1.xml">
    <edmx:Include Namespace="JsonSchemaFileCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/MessageRegistryFileCollection_v1.xml">
    <edmx:Include Namespace="MessageRegistryFileCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/SessionCollection_v1.xml">
    <edmx:Include Namespace="SessionCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/StorageServiceCollection_v1.xml">
    <edmx:Include Namespace="StorageServiceCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/FabricCollection_v1.xml">
    <edmx:Include Namespace="FabricCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/StorageSystemCollection_v1.xml">
    <edmx:Include Namespace="StorageSystemCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/UpdateService_v1.xml">
    <edmx:Include Namespace="UpdateService"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/CompositionService_v1.xml">
    <edmx:Include Namespace="CompositionService"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/JobService_v1.xml">
    <edmx:Include Namespace="JobService"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/TelemetryService_v1.xml">
    <edmx:Include Namespace="TelemetryService"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/CertificateService_v1.xml">
    <edmx:Include Namespace="CertificateService"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ResourceBlockCollection_v1.xml">
    <edmx:Include Namespace="ResourceBlockCollection"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="ServiceRoot" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="This resource represents the root of the Redfish service, located at the \redfish\v1 URI.  As a hypermedia API, all other resources accessible through the Redfish interface on this device are linked directly or indirectly from the Service Root."/>
        <Annotation Term="OData.LongDescription" String="This object represents the root Redfish service.  All values for resources described by this schema shall comply to the requirements as described in the Redfish specification."/>
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
            <String>/redfish/v1/</String>
          </Collection>
        </Annotation>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="1.0"/>

      <EntityContainer Name="ServiceContainer">
        <Singleton Name="Service" Type="ServiceRoot.ServiceRoot"/>
        <Singleton Name="Systems" Type="ComputerSystemCollection.ComputerSystemCollection"/>
        <Singleton Name="Chassis" Type="ChassisCollection.ChassisCollection"/>
        <Singleton Name="Managers" Type="ManagerCollection.ManagerCollection"/>
        <Singleton Name="Tasks" Type="TaskService.TaskService"/>
        <Singleton Name="AccountService" Type="AccountService.AccountService"/>
        <Singleton Name="SessionService" Type="SessionService.SessionService"/>
        <Singleton Name="EventService" Type="EventService.EventService"/>
        <Singleton Name="Registries" Type="MessageRegistryFileCollection.MessageRegistryFileCollection"/>
        <Singleton Name="JsonSchemas" Type="JsonSchemaFileCollection.JsonSchemaFileCollection"/>
        <Singleton Name="Sessions" Type="SessionCollection.SessionCollection"/>
      </EntityContainer>

      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.ServiceRoot">
        <Annotation Term="OData.Description" String="This object represents the root Redfish service."/>
        <Annotation Term="OData.LongDescription" String="This object represents the root Redfish service.  All values for resources described by this schema shall comply to the requirements as described in the Redfish specification."/>
        <Property Name="RedfishVersion" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The version of the Redfish service."/>
          <Annotation Term="OData.LongDescription" String="The value of this string shall represent the version of the Redfish service.  The format of this string shall be of the format majorversion.minorversion.errata in compliance with Protocol Version section of the Redfish specification."/>
          <Annotation Term="Validation.Pattern" String="^\d+\.\d+\.\d+$"/>
        </Property>
        <Property Name="UUID" Type="Resource.UUID">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Unique identifier for a service instance. When SSDP is used, this value should be an exact match of the UUID value returned in a 200OK from an SSDP M-SEARCH request during discovery."/>
          <Annotation Term="OData.LongDescription" String="The value of this string shall represent the id of the Redfish service instance.  The format of this string shall be a 32-byte value in the form 8-4-4-4-12.  If SSDP is used, this value shall be an exact match of the UUID value returned in a 200OK from an SSDP M-SEARCH request during discovery. RFC4122 describes methods that can be used to create a UUID value. The value should be considered to be opaque. Client software should only treat the overall value as a universally unique identifier and should not interpret any sub-fields within the UUID."/>
        </Property>
        <NavigationProperty Name="Systems" Type="ComputerSystemCollection.ComputerSystemCollection" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a link to a collection of Systems."/>
          <Annotation Term="OData.LongDescription" String="This object shall only contain a reference to a collection of resources that comply to the Systems schema."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Chassis" Type="ChassisCollection.ChassisCollection" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a link to a collection of Chassis."/>
          <Annotation Term="OData.LongDescription" String="This object shall only contain a reference to a collection of resources that comply to the Chassis schema."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Managers" Type="ManagerCollection.ManagerCollection" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a link to a collection of Managers."/>
          <Annotation Term="OData.LongDescription" String="This object shall only contain a reference to a collection of resources that comply to the Managers schema."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Tasks" Type="TaskService.TaskService" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a link to the Task Service."/>
          <Annotation Term="OData.LongDescription" String="The classes structure shall only contain a reference to a resource that complies to the TaskService schema."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="SessionService" Type="SessionService.SessionService" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a link to the Sessions Service."/>
          <Annotation Term="OData.LongDescription" String="The classes structure shall only contain a reference to a resource that complies to the SessionService schema."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="AccountService" Type="AccountService.AccountService" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a link to the Account Service."/>
          <Annotation Term="OData.LongDescription" String="The classes structure shall only contain a reference to a resource that complies to the AccountService schema."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="EventService" Type="EventService.EventService" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a link to the EventService."/>
          <Annotation Term="OData.LongDescription" String="The classes structure shall only contain a reference to a resource that complies to the EventService schema."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Registries" Type="MessageRegistryFileCollection.MessageRegistryFileCollection" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a link to a collection of Registries."/>
          <Annotation Term="OData.LongDescription" String="This object shall contain a reference to Message Registry."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="JsonSchemas" Type="JsonSchemaFileCollection.JsonSchemaFileCollection" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a link to a collection of Json-Schema files."/>
          <Annotation Term="OData.LongDescription" String="This object shall only contain a reference to a collection of resources that comply to the SchemaFile schema where the files are Json-Schema files."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <Property Name="Links" Type="ServiceRoot.v1_0_0.Links" Nullable="false">
          <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
          <Annotation Term="OData.LongDescription" String="The Links property, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
      </EntityType>

      <ComplexType Name="Links" BaseType="Resource.Links">
        <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
        <Annotation Term="OData.LongDescription" String="This type, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        <NavigationProperty Name="Sessions" Type="SessionCollection.SessionCollection" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Link to a collection of Sessions."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the link to a collection of Sessions."/>
          <Annotation Term="OData.AutoExpandReferences"/>
          <Annotation Term="Redfish.Required"/>
        </NavigationProperty>
      </ComplexType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_0_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_0_0.ServiceRoot"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_0_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_0_2.ServiceRoot"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_0_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_0_3.ServiceRoot"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_0_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_0_4.ServiceRoot"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_0_6">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add a missing Redfish.Required term to the Sessions link."/>
      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_0_5.ServiceRoot"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_0_7">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_0_6.ServiceRoot"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2016.2"/>
      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_0_2.ServiceRoot">
        <NavigationProperty Name="StorageSystems" Type="StorageSystemCollection.StorageSystemCollection" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a link to a collection of storage systems."/>
          <Annotation Term="OData.LongDescription" String="The referenced collection shall contain computer systems that act as storage servers.  The HostingRoles attribute of each such computer system shall have an entry for StorageServer."/>
        </NavigationProperty>
        <NavigationProperty Name="StorageServices" Type="StorageServiceCollection.StorageServiceCollection" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A link to a collection of all storage service entities."/>
          <Annotation Term="OData.LongDescription" String="The referenced collection shall contain references to all StorageService instances."/>
        </NavigationProperty>
        <NavigationProperty Name="Fabrics" Type="FabricCollection.FabricCollection" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A link to a collection of all fabric entities."/>
          <Annotation Term="OData.LongDescription" String="The referenced collection shall contain references to all Fabric instances."/>
        </NavigationProperty>
        <NavigationProperty Name="UpdateService" Type="UpdateService.UpdateService" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a link to the UpdateService."/>
          <Annotation Term="OData.LongDescription" String="The classes structure shall only contain a reference to a resource that complies to the UpdateService schema."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_1_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityContainer Name="ServiceContainer" Extends="ServiceRoot.v1_0_0.ServiceContainer">
        <Singleton Name="StorageSystems" Type="StorageSystemCollection.StorageSystemCollection"/>
        <Singleton Name="StorageServices" Type="StorageServiceCollection.StorageServiceCollection"/>
        <Singleton Name="Fabrics" Type="FabricCollection.FabricCollection"/>
        <Singleton Name="UpdateService" Type="UpdateService.UpdateService"/>
      </EntityContainer>

      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_1_0.ServiceRoot"/>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_1_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_1_1.ServiceRoot"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_1_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add a missing Redfish.Required term to the Sessions link."/>
      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_1_2.ServiceRoot"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_1_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_1_3.ServiceRoot"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_2_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.1"/>

      <EntityContainer Name="ServiceContainer" Extends="ServiceRoot.v1_1_1.ServiceContainer">
        <Singleton Name="CompositionService" Type="CompositionService.CompositionService"/>
      </EntityContainer>

      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_1_2.ServiceRoot">
        <NavigationProperty Name="CompositionService" Type="CompositionService.CompositionService" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a link to the CompositionService."/>
          <Annotation Term="OData.LongDescription" String="The classes structure shall only contain a reference to a resource that complies to the CompositionService schema."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_2_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add a missing Redfish.Required term to the Sessions link."/>
      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_2_0.ServiceRoot"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_2_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_2_1.ServiceRoot"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_3_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.3"/>

      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_2_0.ServiceRoot">
        <Property Name="Product" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The product associated with this Redfish service."/>
          <Annotation Term="OData.LongDescription" String="The value of this string shall include the name of the product represented by this Redfish service."/>
        </Property>
        <Property Name="ProtocolFeaturesSupported" Type="ServiceRoot.v1_3_0.ProtocolFeaturesSupported" Nullable="false">
          <Annotation Term="OData.Description" String="Contains information about protocol features supported by the service."/>
          <Annotation Term="OData.LongDescription" String="This type contains information about protocol features supported by the service."/>
        </Property>
      </EntityType>

      <ComplexType Name="ProtocolFeaturesSupported">
        <Annotation Term="OData.Description" String="Contains information about protocol features supported by the service."/>
        <Annotation Term="OData.LongDescription" String="This type contains information about protocol features supported by the service."/>
        <Property Name="ExpandQuery" Type="ServiceRoot.v1_3_0.Expand" Nullable="false">
          <Annotation Term="OData.Description" String="Contains information about the use of $expand in the service."/>
          <Annotation Term="OData.LongDescription" String="This type, as described by the Redfish Specification, shall contain information about the support of the $expand query parameter by the service."/>
        </Property>
        <Property Name="FilterQuery" Type="Edm.Boolean" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This indicates whether the $filter query parameter is supported."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a boolean indicating whether this service supports the use of the $filter query parameter as described by the specification."/>
        </Property>
        <Property Name="SelectQuery" Type="Edm.Boolean" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This indicates whether the $select query parameter is supported."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a boolean indicating whether this service supports the use of the $select query parameter as described by the specification."/>
        </Property>
      </ComplexType>

      <ComplexType Name="Expand">
        <Annotation Term="OData.Description" String="Contains information about the use of $expand in the service."/>
        <Annotation Term="OData.LongDescription" String="This type, as described by the Redfish Specification, shall contain information about the support of the $expand query parameter by the service."/>
        <Property Name="Links" Type="Edm.Boolean" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This indicates whether the $expand support of tilde (expand only entries in the Links section) is supported."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a boolean indicating whether this service supports the use of tilde (expand only entries in the Links section) as a value for the $expand query parameter as described by the specification."/>
        </Property>
        <Property Name="NoLinks" Type="Edm.Boolean" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This indicates whether the $expand support of period (expand only entries not in the Links section) is supported."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a boolean indicating whether this service supports the use of period (expand only entries not in the Links section) as a value for the $expand query parameter as described by the specification."/>
        </Property>
        <Property Name="ExpandAll" Type="Edm.Boolean" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This indicates whether the $expand support of asterisk (expand all entries) is supported."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a boolean indicating whether this service supports the use of asterisk (expand all entries) as a value for the $expand query parameter as described by the specification."/>
        </Property>
        <Property Name="Levels" Type="Edm.Boolean" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This indicates whether the expand support of the $levels qualifier is supported by the service."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a boolean indicating whether this service supports the use of $levels as a value for the $expand query parameter as described by the specification."/>
        </Property>
        <Property Name="MaxLevels" Type="Edm.Int64" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This indicates the maximum number value of the $levels qualifier in $expand operations."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the maximum value of the $levels qualifier supported by the service and shall only be included if the value of the Levels property is true."/>
          <Annotation Term="Validation.Minimum" Int="1"/>
          <Annotation Term="Validation.Maximum" Int="6"/>
        </Property>
      </ComplexType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_3_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add a missing Redfish.Required term to the Sessions link."/>
      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_3_0.ServiceRoot"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_3_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_3_1.ServiceRoot"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_3_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that the Product property can be marked as a nullable property."/>
      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_3_2.ServiceRoot"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_4_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.2"/>
      <Annotation Term="OData.Description" String="This version was created to add support of the 'excerpt' and 'only' query parameters to ProtocolFeaturesSupported.  It was also created to add the JobService and Telemetry properties."/>

      <EntityContainer Name="ServiceContainer" Extends="ServiceRoot.v1_2_0.ServiceContainer">
        <Singleton Name="JobService" Type="JobService.JobService"/>
        <Singleton Name="TelemetryService" Type="TelemetryService.TelemetryService"/>
      </EntityContainer>

      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_3_2.ServiceRoot">
        <NavigationProperty Name="JobService" Type="JobService.JobService" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a link to the JobService."/>
          <Annotation Term="OData.LongDescription" String="The classes structure shall only contain a reference to a resource that conforms to the JobService schema."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="TelemetryService" Type="TelemetryService.TelemetryService" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a link to the TelemetryService."/>
          <Annotation Term="OData.LongDescription" String="The value shall be a link to the TelemetryService."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

      <ComplexType Name="ProtocolFeaturesSupported" BaseType="ServiceRoot.v1_3_0.ProtocolFeaturesSupported">
        <Property Name="ExcerptQuery" Type="Edm.Boolean" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This indicates whether the 'excerpt' query parameter is supported."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a boolean indicating whether this service supports the use of the 'excerpt' query parameter as described by the specification."/>
        </Property>
        <Property Name="OnlyMemberQuery" Type="Edm.Boolean" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This indicates whether the 'only' query parameter is supported."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a boolean indicating whether this service supports the use of the 'only' query parameter as described by the specification."/>
        </Property>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_4_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that the Product property can be marked as a nullable property."/>
      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_4_0.ServiceRoot"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ServiceRoot.v1_5_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.3"/>

      <EntityContainer Name="ServiceContainer" Extends="ServiceRoot.v1_4_0.ServiceContainer">
        <Singleton Name="CertificateService" Type="CertificateService.CertificateService"/>
        <Singleton Name="ResourceBlocks" Type="ResourceBlockCollection.ResourceBlockCollection"/>
      </EntityContainer>

      <EntityType Name="ServiceRoot" BaseType="ServiceRoot.v1_4_1.ServiceRoot">
        <Property Name="Vendor" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The vendor or manufacturer associated with this Redfish service."/>
          <Annotation Term="OData.LongDescription" String="The value of this string shall include the name of the manufacturer or vendor represented by this Redfish service. If this property is supported, the vendor name shall not be included in the value of the Product property."/>
        </Property>
        <NavigationProperty Name="CertificateService" Type="CertificateService.CertificateService" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a link to the CertificateService."/>
          <Annotation Term="OData.LongDescription" String="The value shall be a link to the CertificateService."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="ResourceBlocks" Type="ResourceBlockCollection.ResourceBlockCollection" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A link to a collection of all resource block entities.  This collection is intended for implementations that do not contain a Composition Service, but will expose resources to an orchestrator that implements a Composition Service."/>
          <Annotation Term="OData.LongDescription" String="The referenced collection shall contain references to all Resource Block instances."/>
        </NavigationProperty>
      </EntityType>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_SERVICE_ROOT_V1_HPP */
