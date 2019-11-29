#ifndef PSME_REST_METADATA_CHASSIS_V1_HPP
#define PSME_REST_METADATA_CHASSIS_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Chassis_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  Chassis  v1.9.0-->
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
  <edmx:Reference Uri="/redfish/v1/metadata/Thermal_v1.xml">
    <edmx:Include Namespace="Thermal"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Power_v1.xml">
    <edmx:Include Namespace="Power"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Manager_v1.xml">
    <edmx:Include Namespace="Manager"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ComputerSystem_v1.xml">
    <edmx:Include Namespace="ComputerSystem"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/LogServiceCollection_v1.xml">
    <edmx:Include Namespace="LogServiceCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Storage_v1.xml">
    <edmx:Include Namespace="Storage"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Drive_v1.xml">
    <edmx:Include Namespace="Drive"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/PCIeDevice_v1.xml">
    <edmx:Include Namespace="PCIeDevice"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/NetworkAdapterCollection_v1.xml">
    <edmx:Include Namespace="NetworkAdapterCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ResourceBlock_v1.xml">
    <edmx:Include Namespace="ResourceBlock"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Assembly_v1.xml">
    <edmx:Include Namespace="Assembly"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Switch_v1.xml">
    <edmx:Include Namespace="Switch"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/PCIeSlots_v1.xml">
    <edmx:Include Namespace="PCIeSlots"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Processor_v1.xml">
    <edmx:Include Namespace="Processor"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/SensorCollection_v1.xml">
    <edmx:Include Namespace="SensorCollection"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="Chassis" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="The Chassis schema represents the physical components of a system.  This resource represents the sheet-metal confined spaces and logical zones such as racks, enclosures, chassis and all other containers. Subsystems (like sensors) that operate outside of a system's data plane (meaning the resources are not accessible to software running on the system) are linked either directly or indirectly through this resource."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent a chassis or other physical enclosure for a Redfish implementation."/>
        <Annotation Term="Capabilities.InsertRestrictions">
          <Record>
            <PropertyValue Property="Insertable" Bool="false"/>
          </Record>
        </Annotation>
        <Annotation Term="Capabilities.UpdateRestrictions">
          <Record>
            <PropertyValue Property="Updatable" Bool="true"/>
            <Annotation Term="OData.Description" String="A Chassis can be updated to change some properties such as the IndicatorLED."/>
          </Record>
        </Annotation>
        <Annotation Term="Capabilities.DeleteRestrictions">
          <Record>
            <PropertyValue Property="Deletable" Bool="false"/>
          </Record>
        </Annotation>
        <Annotation Term="Redfish.Uris">
          <Collection>
            <String>/redfish/v1/Chassis/{ChassisId}</String>
          </Collection>
        </Annotation>
      </EntityType>

      <Action Name="Reset" IsBound="true">
        <Parameter Name="Chassis" Type="Chassis.v1_0_0.Actions"/>
        <Parameter Name="ResetType" Type="Resource.ResetType">
          <Annotation Term="OData.Description" String="The type of reset to be performed."/>
          <Annotation Term="OData.LongDescription" String="This parameter shall define the type of reset to be performed.  The service may accept a request without the parameter and perform an implementation specific default reset."/>
        </Parameter>
        <Annotation Term="OData.Description" String="This action is used to reset the chassis. This action resets the chassis, not Systems or other contained resources, although side effects may occur which affect those resources."/>
        <Annotation Term="OData.LongDescription" String="This action shall reset the chassis.  This action shall not reset Systems or other contained resource, although side effects may occur which affect those resources."/>
      </Action>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="1.0"/>

      <EntityType Name="Chassis" BaseType="Chassis.Chassis">
        <Property Name="ChassisType" Nullable="false" Type="Chassis.v1_0_0.ChassisType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The type of physical form factor of the chassis."/>
          <Annotation Term="OData.LongDescription" String="ChassisType shall indicate the physical form factor for the type of chassis."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="Manufacturer" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The manufacturer of this chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the name of the organization responsible for producing the chassis. This organization might be the entity from whom the chassis is purchased, but this is not necessarily true."/>
        </Property>
        <Property Name="Model" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The model number of the chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the name by which the manufacturer generally refers to the chassis."/>
        </Property>
        <Property Name="SKU" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The SKU of the chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the stock-keeping unit number for this chassis."/>
        </Property>
        <Property Name="SerialNumber" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The serial number of the chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a manufacturer-allocated number used to identify the chassis."/>
        </Property>
        <Property Name="PartNumber" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The part number of the chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a part number assigned by the organization that is responsible for producing or manufacturing the chassis."/>
        </Property>
        <Property Name="AssetTag" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The user assigned asset tag of this chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an identifying string used to track the chassis for inventory purposes."/>
        </Property>
        <Property Name="IndicatorLED" Type="Chassis.v1_0_0.IndicatorLED">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The state of the indicator LED, used to identify the chassis."/>
          <Annotation Term="OData.LongDescription" String="This value of this property shall contain the indicator light state for the indicator light associated with this system."/>
        </Property>
        <Property Name="Links" Type="Chassis.v1_0_0.Links" Nullable="false">
          <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
          <Annotation Term="OData.LongDescription" String="The Links property, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        </Property>
        <Property Name="Actions" Type="Chassis.v1_0_0.Actions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Description" String="This property describes the status and health of the resource and its children."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any status or health properties of the resource."/>
        </Property>
        <NavigationProperty Name="LogServices" Type="LogServiceCollection.LogServiceCollection" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the logs for this chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a link to a collection of type LogServiceCollection."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Thermal" Type="Thermal.Thermal" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the thermal properties (fans, cooling, sensors) of this chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a reference to the resource that represents the thermal characteristics of this chassis and shall be of type Thermal."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Power" Type="Power.Power" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the power properties (power supplies, power policies, sensors) of this chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a reference to the resource that represents the power characteristics of this chassis and shall be of type Power."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

      <ComplexType Name="Links" BaseType="Resource.Links">
        <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
        <Annotation Term="OData.LongDescription" String="This type, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        <NavigationProperty Name="ComputerSystems" Type="Collection(ComputerSystem.ComputerSystem)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the computer systems contained in this chassis.  This will only reference ComputerSystems that are directly and wholly contained in this chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a reference to the resource that this physical container is associated with and shall reference a resource of type ComputerSystem.  If a ComputerSystem is also referenced in a Chassis that is referenced in a Contains link from this resource, that ComputerSystem shall not be referenced in this Chassis."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="ManagedBy" Type="Collection(Manager.Manager)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the Managers responsible for managing this chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a reference to the resource that manages this chassis and shall reference a resource of type Manager."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="ContainedBy" Type="Chassis.Chassis" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the chassis that this chassis is contained by."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a reference to the resource that represents the chassis that contains this chassis and shall be of type Chassis."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Contains" Type="Collection(Chassis.Chassis)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to any other chassis that this chassis has in it."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a reference to the resource that represents the chassis that this chassis contains and shall be of type Chassis."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="PoweredBy" Type="Collection(Resource.Item)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of ID[s] of resources that power this chassis. Normally the ID will be a chassis or a specific set of Power Supplies."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of IDs containing pointers consistent with JSON pointer syntax to the resource that powers this chassis."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="CooledBy" Type="Collection(Resource.Item)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of ID[s] of resources that cool this chassis. Normally the ID will be a chassis or a specific set of fans."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of IDs containing pointers consistent with JSON pointer syntax to the resource that cools this chassis."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="Chassis.v1_0_0.OemActions" Nullable="false">
          <Annotation Term="OData.Description" String="This property contains the available OEM specific actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any additional OEM actions for this resource."/>
        </Property>
      </ComplexType>

      <ComplexType Name="OemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
        <Annotation Term="OData.Description" String="The available OEM specific actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain any additional OEM actions for this resource."/>
      </ComplexType>

      <EnumType Name="ChassisType">
        <Member Name="Rack">
          <Annotation Term="OData.Description" String="An equipment rack, typically a 19-inch wide freestanding unit."/>
        </Member>
        <Member Name="Blade">
          <Annotation Term="OData.Description" String="An enclosed or semi-enclosed, typically vertically-oriented, system chassis which must be plugged into a multi-system chassis to function normally."/>
        </Member>
        <Member Name="Enclosure">
          <Annotation Term="OData.Description" String="A generic term for a chassis that does not fit any other description."/>
        </Member>
        <Member Name="StandAlone">
          <Annotation Term="OData.Description" String="A single, free-standing system, commonly called a tower or desktop chassis."/>
        </Member>
        <Member Name="RackMount">
          <Annotation Term="OData.Description" String="A single system chassis designed specifically for mounting in an equipment rack."/>
        </Member>
        <Member Name="Card">
          <Annotation Term="OData.Description" String="A loose device or circuit board intended to be installed in a system or other enclosure."/>
        </Member>
        <Member Name="Cartridge">
          <Annotation Term="OData.Description" String="A small self-contained system intended to be plugged into a multi-system chassis."/>
        </Member>
        <Member Name="Row">
          <Annotation Term="OData.Description" String="A collection of equipment racks."/>
        </Member>
        <Member Name="Pod">
          <Annotation Term="OData.Description" String="A collection of equipment racks in a large, likely transportable, container."/>
        </Member>
        <Member Name="Expansion">
          <Annotation Term="OData.Description" String="A chassis which expands the capabilities or capacity of another chassis."/>
        </Member>
        <Member Name="Sidecar">
          <Annotation Term="OData.Description" String="A chassis that mates mechanically with another chassis to expand its capabilities or capacity."/>
        </Member>
        <Member Name="Zone">
          <Annotation Term="OData.Description" String="A logical division or portion of a physical chassis that contains multiple devices or systems that cannot be physically separated."/>
        </Member>
        <Member Name="Sled">
          <Annotation Term="OData.Description" String="An enclosed or semi-enclosed, system chassis which must be plugged into a multi-system chassis to function normally similar to a blade type chassis."/>
        </Member>
        <Member Name="Shelf">
          <Annotation Term="OData.Description" String="An enclosed or semi-enclosed, typically horizontally-oriented, system chassis which must be plugged into a multi-system chassis to function normally."/>
        </Member>
        <Member Name="Drawer">
          <Annotation Term="OData.Description" String="An enclosed or semi-enclosed, typically horizontally-oriented, system chassis which may be slid into a multi-system chassis."/>
        </Member>
        <Member Name="Module">
          <Annotation Term="OData.Description" String="A small, typically removable, chassis or card which contains devices for a particular subsystem or function."/>
        </Member>
        <Member Name="Component">
          <Annotation Term="OData.Description" String="A small chassis, card, or device which contains devices for a particular subsystem or function."/>
        </Member>
        <Member Name="IPBasedDrive">
          <Annotation Term="OData.Description" String="A chassis in a drive form factor with IP-based network connections."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="v1_3_0"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="RackGroup">
          <Annotation Term="OData.Description" String="A group of racks which form a single entity or share infrastructure."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="v1_4_0"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="StorageEnclosure">
          <Annotation Term="OData.Description" String="A chassis which encloses storage."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="v1_6_0"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="Other">
          <Annotation Term="OData.Description" String="A chassis that does not fit any of these definitions."/>
        </Member>
      </EnumType>

      <!-- These are all supported LED statuses. -->
      <EnumType Name="IndicatorLED">
        <Member Name="Unknown">
          <Annotation Term="OData.Description" String="The state of the Indicator LED cannot be determined."/>
          <Annotation Term="OData.LongDescription" String="This value shall represent the Indicator LED is in an unknown state.  The service shall reject PATCH or PUT requests containing this value by returning HTTP 400 (Bad Request)."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Deprecated"/>
                <PropertyValue Property="Version" String="v1_2_0"/>
                <PropertyValue Property="Description" String="This value has been Deprecated in favor of returning null if the state is unknown."/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="Lit">
          <Annotation Term="OData.Description" String="The Indicator LED is lit."/>
          <Annotation Term="OData.LongDescription" String="This value shall represent the Indicator LED is in a solid on state.  If this value is not supported by the service, the service shall reject PATCH or PUT requests containing this value by returning HTTP 400 (Bad Request)."/>
        </Member>
        <Member Name="Blinking">
          <Annotation Term="OData.Description" String="The Indicator LED is blinking."/>
          <Annotation Term="OData.LongDescription" String="This value shall represent the Indicator LED is in a blinking state where the LED is being turned on and off in repetition.  If this value is not supported by the service, the service shall reject PATCH or PUT requests containing this value by returning HTTP 400 (Bad Request)."/>
        </Member>
        <Member Name="Off">
          <Annotation Term="OData.Description" String="The Indicator LED is off."/>
          <Annotation Term="OData.LongDescription" String="This value shall represent the Indicator LED is in a solid off state.  If this value is not supported by the service, the service shall reject PATCH or PUT requests containing this value by returning HTTP 400 (Bad Request)."/>
        </Member>
      </EnumType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_0_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="Chassis" BaseType="Chassis.v1_0_0.Chassis">
        <Property Name="PowerState" Type="Chassis.v1_0_1.PowerState">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The current power state of the chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain the power state of the chassis."/>
        </Property>
      </EntityType>

      <EnumType Name="PowerState">
        <Member Name="On">
          <Annotation Term="OData.Description" String="The components within the chassis has power on."/>
        </Member>
        <Member Name="Off">
          <Annotation Term="OData.Description" String="The components within the chassis has no power, except some components may continue to have AUX power such as management controller."/>
        </Member>
        <Member Name="PoweringOn">
          <Annotation Term="OData.Description" String="A temporary state between Off and On. The components within the chassis can take time to process the power on action."/>
        </Member>
        <Member Name="PoweringOff">
          <Annotation Term="OData.Description" String="A temporary state between On and Off. The components within the chassis can take time to process the power off action."/>
        </Member>
      </EnumType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_0_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_0_1.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_0_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add explicit Permissions annotations to all properties for clarity."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_0_2.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_0_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to remove the Nullable facet on NavigationProperties of type Collection and to use Redfish.Deprecated on certain enum values."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_0_3.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_0_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_0_4.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_0_6">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to correct the Descriptions and LongDescriptions used in the defined Actions."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_0_5.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_0_7">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_0_6.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_0_8">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_0_7.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="1.1"/>

      <EntityType Name="Chassis" BaseType="Chassis.v1_0_2.Chassis">
        <Property Name="PhysicalSecurity" Type="Chassis.v1_1_0.PhysicalSecurity" Nullable="false">
          <Annotation Term="OData.Description" String="The state of the physical security sensor."/>
          <Annotation Term="OData.LongDescription" String="This value of this property shall contain the sensor state of the physical security."/>
        </Property>
      </EntityType>

      <ComplexType Name="PhysicalSecurity">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The state of the physical security sensor."/>
        <Annotation Term="OData.LongDescription" String="This type shall describe the sensor state of the physical security."/>
        <Property Name="IntrusionSensorNumber" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A numerical identifier to represent the physical security sensor."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a numerical identifier for this physical security sensor that is unique within this resource."/>
        </Property>
        <Property Name="IntrusionSensor" Type="Chassis.v1_1_0.IntrusionSensor">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This indicates the known state of the physical security sensor, such as if it is hardware intrusion detected."/>
          <Annotation Term="OData.LongDescription" String="This property shall represent the state of this physical security sensor.  Hardware intrusion indicates the internal hardware is detected as being accessed in an insecure state. Tampering detected indicates the physical tampering of the monitored entity is detected."/>
        </Property>
        <Property Name="IntrusionSensorReArm" Type="Chassis.v1_1_0.IntrusionSensorReArm">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This indicates how the Normal state to be restored."/>
          <Annotation Term="OData.LongDescription" String="This property shall represent the method to set back to the Normal statue of this physical security sensor.  Manual indicates manual re-arm is needed.  Automatic indicates the state is restored automatically as no abnormal physical security conditions are detected."/>
        </Property>
      </ComplexType>

      <EnumType Name="IntrusionSensor">
        <Member Name="Normal">
          <Annotation Term="OData.Description" String="No abnormal physical security conditions are detected at this time."/>
        </Member>
        <Member Name="HardwareIntrusion">
          <Annotation Term="OData.Description" String="A door, lock, or other mechanism protecting the internal system hardware from being accessed is detected as being in an insecure state."/>
        </Member>
        <Member Name="TamperingDetected">
          <Annotation Term="OData.Description" String="Physical tampering of the monitored entity is detected."/>
        </Member>
      </EnumType>

      <EnumType Name="IntrusionSensorReArm">
        <Member Name="Manual">
          <Annotation Term="OData.Description" String="This sensor would be restored to the Normal state by a manual re-arm."/>
        </Member>
        <Member Name="Automatic">
          <Annotation Term="OData.Description" String="This sensor would be restored to the Normal state automatically as no abnormal physical security conditions are detected."/>
        </Member>
      </EnumType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_1_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_1_0.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_1_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add explicit Permissions annotations to all properties for clarity."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_1_2.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_1_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to remove the Nullable facet on NavigationProperties of type Collection and to use Redfish.Deprecated on certain enum values."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_1_3.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_1_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_1_4.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_1_6">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to correct the Descriptions and LongDescriptions used in the defined Actions."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_1_5.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_1_7">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_1_6.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_1_8">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_1_7.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_2_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2016.1"/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_1_2.Chassis">
        <Property Name="Location" Type="Resource.Location" Nullable="false">
          <Annotation Term="OData.Description" String="The Location of the chassis."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain location information of the associated chassis."/>
        </Property>
      </EntityType>

      <ComplexType Name="Links" BaseType="Chassis.v1_0_0.Links">
        <NavigationProperty Name="ManagersInChassis" Type="Collection(Manager.Manager)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the managers located in this Chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall reference one or more resources of type Manager that are in this Chassis."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Drives" Type="Collection(Drive.Drive)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the disk drives located in this Chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall reference one or more resources of type Drive that are in this Chassis."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Storage" Type="Collection(Storage.Storage)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the storage subsystems connected to or inside this Chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall reference one or more resources of type Storage that are connected to or contained inside this Chassis."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_2_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add explicit Permissions annotations to all properties for clarity."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_2_0.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_2_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to remove the Nullable facet on NavigationProperties of type Collection and to use Redfish.Deprecated on certain enum values."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_2_1.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_2_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_2_2.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_2_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to change references to Location to be its abstract base type.  It was also created to correct the Descriptions and LongDescriptions used in the defined Actions."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_2_3.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_2_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_2_4.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_2_6">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_2_5.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_3_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2016.2"/>
      <Annotation Term="OData.Description" String="This version was created to show the ChassisType enumerated list was updated."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_2_0.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_3_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add explicit Permissions annotations to all properties for clarity."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_3_0.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_3_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to remove the Nullable facet on NavigationProperties of type Collection and to use Redfish.Deprecated on certain enum values."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_3_1.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_3_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_3_2.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_3_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to change references to Location to be its abstract base type.  It was also created to correct the Descriptions and LongDescriptions used in the defined Actions."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_3_3.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_3_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_3_4.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_3_6">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_3_5.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_4_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2016.3"/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_3_1.Chassis">
        <Property Name="HeightMm" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The height of the chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the height of the chassis (in millimeters) as specified by the manufacturer."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Measures.Unit" String="mm"/>
        </Property>
        <Property Name="WidthMm" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The width of the chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the width of the chassis (in millimeters) as specified by the manufacturer."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Measures.Unit" String="mm"/>
        </Property>
        <Property Name="DepthMm" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The depth of the chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the depth (length) of the chassis (in millimeters) as specified by the manufacturer."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Measures.Unit" String="mm"/>
        </Property>
        <Property Name="WeightKg" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The weight of the chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the published mass (commonly referred to as weight) of the chassis (in kilograms)."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Measures.Unit" String="kg"/>
        </Property>
        <NavigationProperty Name="NetworkAdapters" Type="NetworkAdapterCollection.NetworkAdapterCollection" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the collection of Network Adapters associated with this chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a link to a collection of type NetworkAdapterCollection."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

      <ComplexType Name="Links" BaseType="Chassis.v1_2_0.Links">
        <NavigationProperty Name="PCIeDevices" Type="Collection(PCIeDevice.PCIeDevice)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the PCIe Devices located in this Chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall reference one or more resources of type PCIeDevices."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_4_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to remove the Nullable facet on NavigationProperties of type Collection and to use Redfish.Deprecated on certain enum values."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_4_0.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_4_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_4_1.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_4_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to change references to Location to be its abstract base type.  It was also created to correct the Descriptions and LongDescriptions used in the defined Actions."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_4_2.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_4_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_4_3.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_4_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_4_4.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_5_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.1"/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_4_1.Chassis"/>

      <ComplexType Name="Links" BaseType="Chassis.v1_4_0.Links">
        <NavigationProperty Name="ResourceBlocks" Type="Collection(ResourceBlock.ResourceBlock)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the Resource Blocks located in this Chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of references of type ResourceBlock that are contained in this Chassis."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_5_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_5_0.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_5_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to change references to Location to be its abstract base type.  It was also created to correct the Descriptions and LongDescriptions used in the defined Actions."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_5_1.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_5_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_5_2.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_5_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_5_3.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_6_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.3"/>
      <Annotation Term="OData.Description" String="This version was created to add a link to an Assembly resource."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_5_2.Chassis">
        <NavigationProperty Name="Assembly" Type="Assembly.Assembly" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the Assembly resource associated with this chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a link to a resource of type Assembly."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_6_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_6_0.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_6_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_6_1.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_7_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.1"/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_6_0.Chassis">
        <Property Name="UUID" Type="Resource.UUID">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Universal Unique Identifier (UUID) for this Chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain the universal unique identifier number for the chassis."/>
        </Property>
      </EntityType>

      <ComplexType Name="Links" BaseType="Chassis.v1_5_0.Links">
        <NavigationProperty Name="Switches" Type="Collection(Switch.Switch)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the Switches located in this Chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of references of type Switch that are contained in this Chassis."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_7_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_7_0.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_7_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_7_1.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_8_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.2"/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_7_1.Chassis">
        <NavigationProperty Name="PCIeSlots" Type="PCIeSlots.PCIeSlots" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the PCIe Slot properties of this chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a reference to the resource that represents the PCIe Slot information for this chassis and shall be of type PCIeSlot."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_8_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="Chassis" BaseType="Chassis.v1_8_0.Chassis"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Chassis.v1_9_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.3"/>

      <EntityType Name="Chassis" BaseType="Chassis.v1_8_1.Chassis">
        <Property Name="EnvironmentalClass" Type="Chassis.v1_9_0.EnvironmentalClass">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The ASHRAE Environmental Class for this Chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the ASHRAE Environmental Specification Class for this Chassis, as defined by ASHRAE Thermal Guidelines for Data Processing Environments. These classes define respective environmental limits which include temperature, relative humidity, dew point, and maximum allowable elevation."/>
        </Property>
        <NavigationProperty Name="Sensors" Type="SensorCollection.SensorCollection" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The naivgation pointer to the collection of sensors located in the equipment and sub-components."/>
          <Annotation Term="OData.LongDescription" String="This property shall be a reference to a resource of type SensorCollection that contains the sensors located in the Chassis and sub-components."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

      <EnumType Name="EnvironmentalClass">
        <Member Name="A1">
          <Annotation Term="OData.Description" String="ASHRAE Environmental Specification Class 'A1'."/>
        </Member>
        <Member Name="A2">
          <Annotation Term="OData.Description" String="ASHRAE Environmental Specification Class 'A2'."/>
        </Member>
        <Member Name="A3">
          <Annotation Term="OData.Description" String="ASHRAE Environmental Specification Class 'A3'."/>
        </Member>
        <Member Name="A4">
          <Annotation Term="OData.Description" String="ASHRAE Environmental Specification Class 'A4'."/>
        </Member>
      </EnumType>

      <ComplexType Name="Links" BaseType="Chassis.v1_7_0.Links">
        <NavigationProperty Name="Processors" Type="Collection(Processor.Processor)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the Processors located in this Chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of references of type Processor that are contained in this Chassis."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_CHASSIS_V1_HPP */
