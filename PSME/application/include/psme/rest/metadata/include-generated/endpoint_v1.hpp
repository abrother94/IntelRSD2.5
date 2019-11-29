#ifndef PSME_REST_METADATA_ENDPOINT_V1_HPP
#define PSME_REST_METADATA_ENDPOINT_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Endpoint_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  Endpoint  v1.3.0-->
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
    <edmx:Include Namespace="Validation.v1_0_0" Alias="Validation"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Redundancy_v1.xml">
    <edmx:Include Namespace="Redundancy"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/IPAddresses_v1.xml">
    <edmx:Include Namespace="IPAddresses"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Port_v1.xml">
    <edmx:Include Namespace="Port"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Protocol_v1.xml">
    <edmx:Include Namespace="Protocol"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/NetworkDeviceFunction_v1.xml">
    <edmx:Include Namespace="NetworkDeviceFunction"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Endpoint">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="Endpoint" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="The Endpoint schema defines the properties of an Endpoint resource.  It represents the properties of an entity that sends or receives protocol defined messages over a transport."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent a fabric endpoint for a Redfish implementation."/>
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
            <String>/redfish/v1/Fabrics/{FabricId}/Endpoints/{EndpointId}</String>
          </Collection>
        </Annotation>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Endpoint.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2016.2"/>

      <EntityType Name="Endpoint" BaseType="Endpoint.Endpoint">
        <Annotation Term="OData.Description" String="This is the schema definition for the Endpoint resource. It represents the properties of an entity that sends or receives protocol defined messages over a transport."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent a fabric endpoint for a Redfish implementation."/>
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Description" String="This property describes the status and health of the resource and its children."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any status or health properties of the resource."/>
        </Property>
        <Property Name="EndpointProtocol" Type="Protocol.Protocol">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The protocol supported by this endpoint."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain the protocol this endpoint uses to communicate with other endpoints on this fabric."/>
        </Property>
        <Property Name="ConnectedEntities" Type="Collection(Endpoint.v1_0_0.ConnectedEntity)">
          <Annotation Term="OData.Description" String="All the entities connected to this endpoint."/>
          <Annotation Term="OData.LongDescription" String="This value of this property shall contain all the entities which this endpoint allows access to."/>
        </Property>
        <Property Name="Identifiers" Type="Collection(Resource.Identifier)">
          <Annotation Term="OData.Description" String="Identifiers for this endpoint."/>
          <Annotation Term="OData.LongDescription" String="Identifiers for this endpoint shall be unique in the context of other endpoints that can reached over the connected network."/>
        </Property>

        <Property Name="PciId" Type="Endpoint.v1_0_0.PciId">
          <Annotation Term="OData.Description" String="The PCI ID of the endpoint."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the PCI ID of the endpoint."/>
        </Property>
        <NavigationProperty Name="Redundancy" Type="Collection(Redundancy.Redundancy)" ContainsTarget="true">
          <Annotation Term="OData.Description" String="Redundancy information for the lower level endpoints supporting this endpoint."/>
          <Annotation Term="OData.LongDescription" String="The values of the properties in this array shall be used to show how this endpoint is grouped with other endpoints for form redundancy sets."/>
          <Annotation Term="OData.AutoExpand"/>
        </NavigationProperty>
        <Property Name="HostReservationMemoryBytes" Type="Edm.Int64">
          <Annotation Term="Measures.Unit" String="By"/>
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The amount of memory in Bytes that the Host should allocate to connect to this endpoint."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the amount of memory in Bytes that the Host should allocate to connect to this endpoint."/>
        </Property>

        <Property Name="Links" Type="Endpoint.v1_0_0.Links" Nullable="false">
          <Annotation Term="OData.Description" String="The links object contains the links to other resources that are related to this resource."/>
          <Annotation Term="OData.LongDescription" String="The Links property, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        </Property>
        <Property Name="Actions" Type="Endpoint.v1_0_0.Actions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Links" BaseType="Resource.Links">
        <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
        <Annotation Term="OData.LongDescription" String="This type, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        <NavigationProperty Name="MutuallyExclusiveEndpoints" Type="Collection(Endpoint.Endpoint)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the endpoints that may not be used in zones if this endpoint is used in a zone."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of references of type Endpoint that cannot be used in a zone if this endpoint is used in a zone."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Ports" Type="Collection(Port.Port)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the the physical ports associated with this endpoint."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of references of type Port that are utilized by this endpoint."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="Endpoint.v1_0_0.OemActions">
          <Annotation Term="OData.Description" String="This property contains the available OEM specific actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any additional OEM actions for this resource."/>
        </Property>
      </ComplexType>

      <ComplexType Name="OemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
        <Annotation Term="OData.Description" String="The available OEM specific actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain any additional OEM actions for this resource."/>
      </ComplexType>

      <ComplexType Name="ConnectedEntity">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="Represents a remote resource that is connected to the network accessible to this endpoint."/>
        <Annotation Term="OData.LongDescription" String="This type shall represent a remote resource that is connected to a network accessible to an endpoint."/>
        <Property Name="EntityType" Type="Endpoint.v1_0_0.EntityType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The type of the connected entity."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate if type of connected entity."/>
        </Property>
        <Property Name="EntityRole" Type="Endpoint.v1_0_0.EntityRole">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The role of the connected entity."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate if the specified entity is an initiator, target, or both."/>
        </Property>
        <Property Name="EntityPciId" Type="Endpoint.v1_0_0.PciId">
          <Annotation Term="OData.Description" String="The PCI ID of the connected entity."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the PCI ID of the connected PCIe entity."/>
        </Property>
        <Property Name="PciFunctionNumber" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The PCI ID of the connected entity."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the PCI Function Number of the connected PCIe entity."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Deprecated"/>
                <PropertyValue Property="Version" String="v1_2_0"/>
                <PropertyValue Property="Description" String="This property has been deprecated in favor of the FunctionNumber property inside the EntityPciId object."/>
              </Record>
            </Collection>
          </Annotation>
        </Property>
        <Property Name="PciClassCode" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Class Code, Subclass code, and Programming Interface code of this PCIe function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the PCI Class Code, Subclass code, and Programming Interface code of the PCIe device function."/>
          <Annotation Term="Validation.Pattern" String="^0[xX](([a-fA-F]|[0-9]){2}){3}$"/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Deprecated"/>
                <PropertyValue Property="Version" String="v1_2_0"/>
                <PropertyValue Property="Description" String="This property has been deprecated in favor of the ClassCode property inside the EntityPciId object."/>
              </Record>
            </Collection>
          </Annotation>
        </Property>
        <Property Name="Identifiers" Type="Collection(Resource.Identifier)">
          <Annotation Term="OData.Description" String="Identifiers for the remote entity."/>
          <Annotation Term="OData.LongDescription" String="Identifiers for the remote entity shall be unique in the context of other resources that can reached over the connected network."/>
        </Property>
        <NavigationProperty Name="EntityLink" Type="Resource.Resource">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A link to the associated entity."/>
          <Annotation Term="OData.LongDescription" String="This property shall be a reference to an entity of the type specified by the description of the value of the EntityType property."/>
        </NavigationProperty>

        <Property Name="Oem" Type="Resource.Oem" Nullable="false">
          <Annotation Term="OData.Description" String="Oem extension object."/>
          <Annotation Term="OData.LongDescription" String="This object represents the Oem property.  All values for resources described by this schema shall comply to the requirements as described in the Redfish specification."/>
        </Property>
      </ComplexType>

      <EnumType Name="EntityType">
        <Member Name="StorageInitiator">
          <Annotation Term="OData.Description" String="The entity is a storage initator. The EntityLink property (if present) should be a Storage.StorageController entity."/>
        </Member>
        <Member Name="RootComplex">
          <Annotation Term="OData.Description" String="The entity is a PCI(e) root complex. The EntityLink property (if present) should be a ComputerSystem.ComputerSystem entity."/>
        </Member>
        <Member Name="NetworkController">
          <Annotation Term="OData.Description" String="The entity is a network controller. The EntityLink property (if present) should be an EthernetInterface.EthernetInterface entity."/>
        </Member>
        <Member Name="Drive">
          <Annotation Term="OData.Description" String="The entity is a disk drive. The EntityLink property (if present) should be a Drive.Drive entity."/>
        </Member>
        <Member Name="StorageExpander">
          <Annotation Term="OData.Description" String="The entity is a storage expander. The EntityLink property (if present) should be a Chassis.Chassis entity."/>
        </Member>
        <Member Name="DisplayController">
          <Annotation Term="OData.Description" String="The entity is a display controller."/>
        </Member>
        <Member Name="Bridge">
          <Annotation Term="OData.Description" String="The entity is a PCI(e) bridge."/>
        </Member>
        <Member Name="Processor">
          <Annotation Term="OData.Description" String="The entity is a processor device."/>
        </Member>
        <Member Name="Volume">
          <Annotation Term="OData.Description" String="The entity is a volume. The EntityLink property (if present) should be a Volume.Volume entity."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="v1_1_0"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="AccelerationFunction">
          <Annotation Term="OData.Description" String="The entity is an acceleration function realized through a device, such as an FPGA. The EntityLink property (if present) should be a AccelerationFunction.AccelerationFunction entity."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="v1_3_0"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
      </EnumType>

      <EnumType Name="EntityRole">
        <Member Name="Initiator">
          <Annotation Term="OData.Description" String="The entity is acting as an initiator."/>
        </Member>
        <Member Name="Target">
          <Annotation Term="OData.Description" String="The entity is acting as a target."/>
        </Member>
        <Member Name="Both">
          <Annotation Term="OData.Description" String="The entity is acting as both an initiator and a target."/>
        </Member>
      </EnumType>

      <ComplexType Name="PciId">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="A PCI ID."/>
        <Annotation Term="OData.LongDescription" String="This type shall describe a PCI ID."/>
        <Property Name="DeviceId" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Device ID of this PCIe function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the PCI Subsystem Vendor ID of the PCIe device function."/>
          <Annotation Term="Validation.Pattern" String="^0[xX](([a-fA-F]|[0-9]){2}){2}$"/>
        </Property>
        <Property Name="VendorId" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Vendor ID of this PCIe function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the PCI Vendor ID of the PCIe device function."/>
          <Annotation Term="Validation.Pattern" String="^0[xX](([a-fA-F]|[0-9]){2}){2}$"/>
        </Property>
        <Property Name="SubsystemId" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Subsystem ID of this PCIe function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the PCI Subsystem Vendor ID of the PCIe device function."/>
          <Annotation Term="Validation.Pattern" String="^0[xX](([a-fA-F]|[0-9]){2}){2}$"/>
        </Property>
        <Property Name="SubsystemVendorId" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Subsystem Vendor ID of this PCIe function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the PCI Subsystem Vendor ID of the PCIe device function."/>
          <Annotation Term="Validation.Pattern" String="^0[xX](([a-fA-F]|[0-9]){2}){2}$"/>
        </Property>
      </ComplexType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Endpoint.v1_0_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add explicit Permissions annotations to all properties for clarity."/>
      <EntityType Name="Endpoint" BaseType="Endpoint.v1_0_0.Endpoint"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Endpoint.v1_0_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated and to remove the Nullable facet on NavigationProperties of type Collection."/>
      <EntityType Name="Endpoint" BaseType="Endpoint.v1_0_1.Endpoint"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Endpoint.v1_0_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add the OData.AdditionalProperties annotation to the ConnectedEntity and PciId definitions, and to change references to Identifier to be its abstract base type, and Protocol to use the unversioned definition.."/>
      <EntityType Name="Endpoint" BaseType="Endpoint.v1_0_2.Endpoint"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Endpoint.v1_0_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Endpoint" BaseType="Endpoint.v1_0_3.Endpoint"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Endpoint.v1_0_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="Endpoint" BaseType="Endpoint.v1_0_4.Endpoint"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Endpoint.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.3"/>
      <EntityType Name="Endpoint" BaseType="Endpoint.v1_0_3.Endpoint">
        <Property Name="IPTransportDetails" Type="Collection(Endpoint.v1_1_0.IPTransportDetails)">
          <Annotation Term="OData.Description" String="This array contains details for each IP transport supported by this endpoint. The array structure can be used to model multiple IP addresses for this endpoint."/>
          <Annotation Term="OData.LongDescription" String="This array shall contain the details for each IP transport supported by this endpoint."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </Property>
      </EntityType>

      <ComplexType Name="Links" BaseType="Endpoint.v1_0_0.Links">
        <NavigationProperty Name="NetworkDeviceFunction" Type="Collection(NetworkDeviceFunction.NetworkDeviceFunction)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="When NetworkDeviceFunction resources are present, this array contains references to the network device function that connect to this endpoint."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a reference to a NetworkDeviceFunction resource, with which this endpoint is associated."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="IPTransportDetails">
        <Annotation Term="OData.Description" String="This object contains properties which specify the details of the transport supported by the endpoint. The properties which are present, is dependemt on the type of transport supported by the endpoint."/>
        <Annotation Term="OData.LongDescription" String="The type shall contain properties which specify the details of the transport supported by the endpoint."/>
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="TransportProtocol" Type="Protocol.Protocol" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The protocol used by the connection entity."/>
          <Annotation Term="OData.LongDescription" String="The value shall be the protocol used by the connection entity."/>
        </Property>
        <Property Name="IPv4Address" Type="IPAddresses.IPv4Address" Nullable="false">
          <Annotation Term="OData.Description" String="The IPv4 addresses assigned to the Endpoint."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall specify the IPv4Address."/>
        </Property>
        <Property Name="IPv6Address" Type="IPAddresses.IPv6Address" Nullable="false">
          <Annotation Term="OData.Description" String="The IPv6 addresses assigned to the Endpoint."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall specify the IPv6Address."/>
        </Property>
        <Property Name="Port" Type="Edm.Decimal" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The UDP or TCP port number used by the Endpoint."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an specify UDP or TCP port number used for communication with the Endpoint."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Validation.Maximum" Int="65535"/>
        </Property>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Endpoint.v1_1_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Endpoint" BaseType="Endpoint.v1_1_0.Endpoint"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Endpoint.v1_1_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="Endpoint" BaseType="Endpoint.v1_1_1.Endpoint"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Endpoint.v1_2_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.2"/>
      <EntityType Name="Endpoint" BaseType="Endpoint.v1_1_1.Endpoint"/>

      <ComplexType Name="PciId" BaseType="Endpoint.v1_0_0.PciId">
        <Property Name="FunctionNumber" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The PCI ID of the connected entity."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the PCI Function Number of the connected PCIe entity."/>
        </Property>
        <Property Name="ClassCode" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Class Code, Subclass code, and Programming Interface code of this PCIe function."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the PCI Class Code, Subclass code, and Programming Interface code of the PCIe device function."/>
          <Annotation Term="Validation.Pattern" String="^0[xX](([a-fA-F]|[0-9]){2}){3}$"/>
        </Property>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Endpoint.v1_2_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="Endpoint" BaseType="Endpoint.v1_2_0.Endpoint"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Endpoint.v1_3_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.3"/>
      <Annotation Term="OData.Description" String="This version was created to add AccelerationFunction to the EntityType enum."/>
      <EntityType Name="Endpoint" BaseType="Endpoint.v1_2_1.Endpoint"/>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_ENDPOINT_V1_HPP */
