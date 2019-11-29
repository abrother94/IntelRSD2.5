#ifndef PSME_REST_METADATA_POWER_V1_HPP
#define PSME_REST_METADATA_POWER_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Power_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  Power  v1.5.2-->
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
  <edmx:Reference Uri="/redfish/v1/metadata/PhysicalContext_v1.xml">
    <edmx:Include Namespace="PhysicalContext"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Redundancy_v1.xml">
    <edmx:Include Namespace="Redundancy"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Assembly_v1.xml">
    <edmx:Include Namespace="Assembly"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="Power" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="This is the schema definition for the Power Metrics.  It represents the properties for Power Consumption and Power Limiting."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent a power metrics resource for a Redfish implementation."/>
        <Annotation Term="Capabilities.InsertRestrictions">
          <Record>
            <PropertyValue Property="Insertable" Bool="false"/>
          </Record>
        </Annotation>
        <Annotation Term="Capabilities.UpdateRestrictions">
          <Record>
            <PropertyValue Property="Updatable" Bool="true"/>
            <Annotation Term="OData.Description" String="Power properties can be updated to change limits, exceptions and other writable properties."/>
          </Record>
        </Annotation>
        <Annotation Term="Capabilities.DeleteRestrictions">
          <Record>
            <PropertyValue Property="Deletable" Bool="false"/>
          </Record>
        </Annotation>
        <Annotation Term="Redfish.Uris">
          <Collection>
            <String>/redfish/v1/Chassis/{ChassisId}/Power</String>
          </Collection>
        </Annotation>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="1.0"/>

      <EntityType Name="Power" BaseType="Power.Power">
        <NavigationProperty Name="PowerControl" Type="Collection(Power.v1_0_0.PowerControl)" ContainsTarget="true">
          <Annotation Term="OData.Description" String="This is the definition for power control function (power reading/limiting)."/>
          <Annotation Term="OData.LongDescription" String="These properties shall be the definition for power control (power reading and limiting) for a Redfish implementation."/>
          <Annotation Term="OData.AutoExpand"/>
        </NavigationProperty>
        <NavigationProperty Name="Voltages" Type="Collection(Power.v1_0_0.Voltage)" ContainsTarget="true">
          <Annotation Term="OData.Description" String="This is the definition for voltage sensors."/>
          <Annotation Term="OData.LongDescription" String="These properties shall be the definition for voltage sensors for a Redfish implementation."/>
          <Annotation Term="OData.AutoExpand"/>
        </NavigationProperty>
        <NavigationProperty Name="PowerSupplies" Type="Collection(Power.v1_0_0.PowerSupply)" ContainsTarget="true">
          <Annotation Term="OData.Description" String="Details of the power supplies associated with this system or device."/>
          <Annotation Term="OData.LongDescription" String="This object shall contain details of the power supplies associated with this system or device."/>
          <Annotation Term="OData.AutoExpand"/>
        </NavigationProperty>
        <NavigationProperty Name="Redundancy" Type="Collection(Redundancy.Redundancy)" ContainsTarget="true">
          <Annotation Term="OData.Description" String="Redundancy information for the power subsystem of this system or device."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain redundancy information for the power subsystem of this system or device."/>
          <Annotation Term="OData.AutoExpand"/>
        </NavigationProperty>
      </EntityType>

      <EntityType Name="PowerControl" BaseType="Resource.v1_0_0.ReferenceableMember">
        <Property Name="Name" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Power Control Function name."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the name of the Voltage sensor."/>
        </Property>
        <Property Name="PowerConsumedWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The actual power being consumed by the chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the actual power being consumed (in Watts) by the chassis."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Measures.Unit" String="W"/>
        </Property>
        <Property Name="PowerRequestedWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The potential power that the chassis resources are requesting which may be higher than the current level being consumed since requested power includes budget that the chassis resource wants for future use."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the amount of power (in Watts) that the chassis resource is currently requesting be budgeted to it for future use."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Measures.Unit" String="W"/>
        </Property>
        <Property Name="PowerAvailableWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The amount of power not already budgeted and therefore available for additional allocation. (powerCapacity - powerAllocated).  This indicates how much reserve power capacity is left."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the amount of power capacity (in Watts) not already allocated and shall equal PowerCapacityWatts - PowerAllocatedWatts."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Measures.Unit" String="W"/>
        </Property>
        <Property Name="PowerCapacityWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The total amount of power available to the chassis for allocation. This may the power supply capacity, or power budget assigned to the chassis from an up-stream chassis."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the total power capacity that is available for allocation to the chassis resources."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Measures.Unit" String="W"/>
        </Property>
        <Property Name="PowerAllocatedWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The total amount of power that has been allocated (or budegeted)to  chassis resources."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the total power currently allocated to chassis resources."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Measures.Unit" String="W"/>
        </Property>
        <Property Name="PowerMetrics" Type="Power.v1_0_0.PowerMetric" Nullable="false">
          <Annotation Term="OData.Description" String="Power readings for this chassis."/>
          <Annotation Term="OData.LongDescription" String="This object shall contain power metrics for power readings (interval, minimum/maximum/average power consumption) for the chassis."/>
        </Property>
        <Property Name="PowerLimit" Type="Power.v1_0_0.PowerLimit" Nullable="false">
          <Annotation Term="OData.Description" String="Power limit status and configuration information for this chassis."/>
          <Annotation Term="OData.LongDescription" String="This object shall contain power limit status and configuration information for this chassis."/>
        </Property>
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Description" String="This property describes the status and health of the resource and its children."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any status or health properties of the resource."/>
        </Property>
        <NavigationProperty Name="RelatedItem" Type="Collection(Resource.Item)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The ID(s) of the resources associated with this Power Limit."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of IDs containing pointers consistent with JSON pointer syntax to the resource that is being limited."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

      <ComplexType Name="PowerMetric">
        <Annotation Term="OData.Description" String="This type describe the power metrics for a resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain power metrics for power readings (interval, minimum/maximum/average power consumption) for a resource."/>
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="IntervalInMin" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The time interval (or window) in which the PowerMetrics are measured over."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the time interval (or window), in minutes, in which the PowerMetrics properties are measured over."/>
          <Annotation Term="Measures.Unit" String="min"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="MinConsumedWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The lowest power consumption level over the measurement window (the last IntervalInMin minutes)."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the minimum power level in watts that occured within the last IntervalInMin minutes."/>
          <Annotation Term="Measures.Unit" String="W"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="MaxConsumedWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The highest power consumption level that has occured over the measurement window (the last IntervalInMin minutes)."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the maximum power level in watts that occured within the last IntervalInMin minutes."/>
          <Annotation Term="Measures.Unit" String="W"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="AverageConsumedWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The average power level over the measurement window (the last IntervalInMin minutes)."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the average power level that occured averaged over the last IntervalInMin minutes."/>
          <Annotation Term="Measures.Unit" String="W"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
      </ComplexType>

      <ComplexType Name="PowerLimit">
        <Annotation Term="OData.Description" String="This object contains power limit status and configuration information for the chassis."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain power limit status and configuration information for this chassis."/>
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="LimitInWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The Power limit in watts. Set to null to disable power capping."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the power cap limit in watts for the resource.  If set to null, power capping shall be disabled."/>
          <Annotation Term="Measures.Unit" String="W"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="LimitException" Type="Power.v1_0_0.PowerLimitException">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The action that is taken if the power cannot be maintained below the LimitInWatts."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the action to be taken if the resource power consumption can not be limited below the specified limit after several correction time periods."/>
        </Property>
        <Property Name="CorrectionInMs" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The time required for the limiting process to reduce power consumption to below the limit."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the time interval in ms required for the limiting process to react and reduce the power consumption below the limit."/>
          <Annotation Term="Measures.Unit" String="ms"/>
        </Property>
      </ComplexType>

      <EnumType Name="PowerLimitException">
        <Member Name="NoAction">
          <Annotation Term="OData.Description" String="Take no action when the limit is exceeded."/>
        </Member>
        <Member Name="HardPowerOff">
          <Annotation Term="OData.Description" String="Turn the power off immediately when the limit is exceeded."/>
        </Member>
        <Member Name="LogEventOnly">
          <Annotation Term="OData.Description" String="Log an event when the limit is exceeded, but take no further action."/>
        </Member>
        <Member Name="Oem">
          <Annotation Term="OData.Description" String="Take an OEM-defined action."/>
        </Member>
      </EnumType>

      <EntityType Name="Voltage" BaseType="Resource.v1_0_0.ReferenceableMember">
        <Property Name="Name" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Voltage sensor name."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the name of the Voltage sensor."/>
        </Property>
        <Property Name="SensorNumber" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A numerical identifier to represent the voltage sensor."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a numerical identifier for this voltage sensor that is unique within this resource."/>
        </Property>
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Description" String="This property describes the status and health of the resource and its children."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any status or health properties of the resource."/>
        </Property>
        <Property Name="ReadingVolts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The present reading of the voltage sensor."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the present reading of the voltage sensor's reading."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="UpperThresholdNonCritical" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Above normal range."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate the present reading is above the normal range but is not critical. Units shall use the same units as the related ReadingVolts propoerty."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="UpperThresholdCritical" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Above normal range but not yet fatal."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate the present reading is above the normal range but is not yet fatal. Units shall use the same units as the related ReadingVolts propoerty."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="UpperThresholdFatal" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Above normal range and is fatal."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate the present reading is above the normal range and is fatal. Units shall use the same units as the related ReadingVolts propoerty."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="LowerThresholdNonCritical" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Below normal range."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate the present reading is below the normal range but is not critical. Units shall use the same units as the related ReadingVolts propoerty."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="LowerThresholdCritical" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Below normal range but not yet fatal."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate the present reading is below the normal range but is not yet fatal. Units shall use the same units as the related ReadingVolts propoerty."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="LowerThresholdFatal" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Below normal range and is fatal."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate the present reading is below the normal range and is fatal. Units shall use the same units as the related ReadingVolts propoerty."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="MinReadingRange" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Minimum value for this Voltage sensor."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate the lowest possible value for ReadingVolts. Units shall use the same units as the related ReadingVolts propoerty."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="MaxReadingRange" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Maximum value for this Voltage sensor."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate the highest possible value for ReadingVolts. Units shall use the same units as the related ReadingVolts propoerty."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="PhysicalContext" Type="PhysicalContext.PhysicalContext" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Describes the area or device to which this voltage measurement applies."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a description of the affected device or region within the chassis to which this voltage measurement applies."/>
        </Property>
        <NavigationProperty Name="RelatedItem" Type="Collection(Resource.Item)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Describes the areas or devices to which this voltage measurement applies."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of IDs containing pointers consistent with JSON pointer syntax to the areas or devices to which this voltage measurement applies."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

      <EntityType Name="PowerSupply" BaseType="Resource.v1_0_0.ReferenceableMember">
        <Annotation Term="OData.Description" String="Details of a power supplies associated with this system or device."/>
        <Property Name="Name" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The name of the Power Supply."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain a descriptive name for the associated power supply."/>
        </Property>
        <Property Name="PowerSupplyType" Type="Power.v1_0_0.PowerSupplyType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Power Supply type (AC or DC)."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the input power type (AC or DC) of the associated power supply."/>
        </Property>
        <Property Name="LineInputVoltageType" Type="Power.v1_0_0.LineInputVoltageType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The line voltage type supported as an input to this Power Supply."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the type of input line voltage supported by the associated power supply."/>
        </Property>
        <Property Name="LineInputVoltage" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The line input voltage at which the Power Supply is operating."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the value in Volts of the line input voltage (measured or configured for) that the power supply has been configured to operate with or is currently receiving."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="PowerCapacityWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The maximum capacity of this Power Supply."/>
          <Annotation Term="OData.LongDescription" String="This property shall contiain the maximum amount of power, in Watts, that the associated power supply is rated to deliver."/>
          <Annotation Term="Measures.Unit" String="W"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="LastPowerOutputWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The average power output of this Power Supply."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the average power output, measured in Watts, of the associated power supply."/>
          <Annotation Term="Measures.Unit" String="W"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="Model" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The model number for this Power Supply."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the model information as defined by the manufacturer for the associated power supply."/>
        </Property>
        <Property Name="FirmwareVersion" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The firmware version for this Power Supply."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the firwmare version as defined by the manufacturer for the associated power supply."/>
        </Property>
        <Property Name="SerialNumber" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The serial number for this Power Supply."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the serial number as defined by the manufacturer for the associated power supply."/>
        </Property>
        <Property Name="PartNumber" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The part number for this Power Supply."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the part number as defined by the manufacturer for the associated power supply."/>
        </Property>
        <Property Name="SparePartNumber" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The spare part number for this Power Supply."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the spare or replacement part number as defined by the manufacturer for the associated power supply."/>
        </Property>
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Description" String="This property describes the status and health of the resource and its children."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any status or health properties of the resource."/>
        </Property>
        <NavigationProperty Name="RelatedItem" Type="Collection(Resource.Item)">
          <Annotation Term="OData.Description" String="The ID(s) of the resources associated with this Power Limit."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of IDs containing pointers consistent with JSON pointer syntax to the resource that is being limited."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Redundancy" Type="Collection(Redundancy.Redundancy)">
          <Annotation Term="OData.Description" String="This structure is used to show redundancy for power supplies.  The Component ids will reference the members of the redundancy groups."/>
          <Annotation Term="OData.LongDescription" String="The values of the properties in this array shall be used to show redundancy for power supplies and other elements in this resource.  The use of IDs within these arrays shall reference the members of the redundancy groups."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

      <EnumType Name="PowerSupplyType">
        <Member Name="Unknown">
          <Annotation Term="OData.Description" String="The power supply type cannot be determined."/>
        </Member>
        <Member Name="AC">
          <Annotation Term="OData.Description" String="Alternating Current (AC) power supply."/>
        </Member>
        <Member Name="DC">
          <Annotation Term="OData.Description" String="Direct Current (DC) power supply."/>
        </Member>
        <Member Name="ACorDC">
          <Annotation Term="OData.Description" String="Power Supply supports both DC or AC."/>
        </Member>
      </EnumType>

      <EnumType Name="LineInputVoltageType">
        <Member Name="Unknown">
          <Annotation Term="OData.Description" String="The power supply line input voltage type cannot be determined."/>
        </Member>
        <Member Name="ACLowLine">
          <Annotation Term="OData.Description" String="100-127V AC input."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Deprecated"/>
                <PropertyValue Property="Version" String="v1_1_0"/>
                <PropertyValue Property="Description" String="This value has been Deprecated in favor of AC120V."/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="ACMidLine">
          <Annotation Term="OData.Description" String="200-240V AC input."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Deprecated"/>
                <PropertyValue Property="Version" String="v1_1_0"/>
                <PropertyValue Property="Description" String="This value has been Deprecated in favor of AC240V."/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="ACHighLine">
          <Annotation Term="OData.Description" String="277V AC input."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Deprecated"/>
                <PropertyValue Property="Version" String="v1_1_0"/>
                <PropertyValue Property="Description" String="This value has been Deprecated in favor of AC277V."/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="DCNeg48V">
          <Annotation Term="OData.Description" String="-48V DC input."/>
        </Member>
        <Member Name="DC380V">
          <Annotation Term="OData.Description" String="High Voltage DC input (380V)."/>
        </Member>
        <Member Name="AC120V">
          <Annotation Term="OData.Description" String="AC 120V nominal input."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="v1_1_0"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="AC240V">
          <Annotation Term="OData.Description" String="AC 240V nominal input."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="v1_1_0"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="AC277V">
          <Annotation Term="OData.Description" String="AC 277V nominal input."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="v1_1_0"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="ACandDCWideRange">
          <Annotation Term="OData.Description" String="Wide range AC or DC input."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="v1_1_0"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="ACWideRange">
          <Annotation Term="OData.Description" String="Wide range AC input."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="v1_1_0"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="DC240V">
          <Annotation Term="OData.Description" String="DC 240V nominal input."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="v1_1_0"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
      </EnumType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_0_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Power" BaseType="Power.v1_0_0.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_0_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Power" BaseType="Power.v1_0_1.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_0_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add explicit Permissions annotations to all properties for clarity."/>
      <EntityType Name="Power" BaseType="Power.v1_0_2.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_0_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to remove the Nullable facet on NavigationProperties of type Collection and to use Redfish.Deprecated on certain enum values."/>
      <EntityType Name="Power" BaseType="Power.v1_0_3.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_0_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to remove the AutoExpand annotation for the Redundancy property inside PowerSupply."/>
      <EntityType Name="Power" BaseType="Power.v1_0_4.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_0_6">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to change references to PhysicalContext to use the unversioned definition."/>
      <EntityType Name="Power" BaseType="Power.v1_0_5.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_0_7">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Power" BaseType="Power.v1_0_6.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_0_8">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation. It was also created to fix PowerMetrics/PowerMetric description, not to use abbreviated terms."/>
      <EntityType Name="Power" BaseType="Power.v1_0_7.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2016.1"/>

      <EntityType Name="Power" BaseType="Power.v1_0_2.Power"/>
      <EntityType Name="PowerSupply" BaseType="Power.v1_0_0.PowerSupply">
        <Property Name="Manufacturer" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the manufacturer of this power supply."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the name of the organization responsible for producing the power supply. This organization might be the entity from whom the power supply is purchased, but this is not necessarily true."/>
        </Property>
        <Property Name="InputRanges" Type="Collection(Power.v1_1_0.InputRange)" Nullable="false">
          <Annotation Term="OData.Description" String="This is the input ranges that the power supply can use."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a collection of ranges usable by the power supply unit."/>
        </Property>
      </EntityType>

      <ComplexType Name="InputRange">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This type describes an input range for a power supply."/>
        <Annotation Term="OData.LongDescription" String="This type shall describe an input range that the associated power supply is able to utilize."/>
        <Property Name="InputType" Type="Power.v1_1_0.InputType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Input type (AC or DC)."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the input type (AC or DC) of the associated range."/>
        </Property>
        <Property Name="MinimumVoltage" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The minimum line input voltage at which this power supply input range is effective."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the value in Volts of the minimum line input voltage which the power supply is capable of consuming for this range."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="MaximumVoltage" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The maximum line input voltage at which this power supply input range is effective."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the value in Volts of the maximum line input voltage which the power supply is capable of consuming for this range."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="MinimumFrequencyHz" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The minimum line input frequency at which this power supply input range is effective."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the value in Hertz of the minimum line input frequency which the power supply is capable of consuming for this range."/>
          <Annotation Term="Measures.Unit" String="Hz"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="MaximumFrequencyHz" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The maximum line input frequency at which this power supply input range is effective."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the value in Hertz of the maximum line input frequency which the power supply is capable of consuming for this range."/>
          <Annotation Term="Measures.Unit" String="Hz"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="OutputWattage" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The maximum capacity of this Power Supply when operating in this input range."/>
          <Annotation Term="OData.LongDescription" String="This property shall contiain the maximum amount of power, in Watts, that the associated power supply is rated to deliver while operating in this input range."/>
          <Annotation Term="Measures.Unit" String="W"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="Oem" Type="Resource.Oem" Nullable="false">
          <Annotation Term="OData.Description" String="Oem extension object."/>
          <Annotation Term="OData.LongDescription" String="This object represents the Oem property.  All values for resources described by this schema shall comply to the requirements as described in the Redfish specification."/>
        </Property>
      </ComplexType>

      <EnumType Name="InputType">
        <Member Name="AC">
          <Annotation Term="OData.Description" String="Alternating Current (AC) input range."/>
        </Member>
        <Member Name="DC">
          <Annotation Term="OData.Description" String="Direct Current (DC) input range."/>
        </Member>
      </EnumType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_1_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add explicit Permissions annotations to all properties for clarity."/>
      <EntityType Name="Power" BaseType="Power.v1_1_0.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_1_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to remove the Nullable facet on NavigationProperties of type Collection and to use Redfish.Deprecated on certain enum values."/>
      <EntityType Name="Power" BaseType="Power.v1_1_1.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_1_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to remove the AutoExpand annotation for the Redundancy property inside PowerSupply."/>
      <EntityType Name="Power" BaseType="Power.v1_1_2.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_1_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to change references to PhysicalContext to use the unversioned definition."/>
      <EntityType Name="Power" BaseType="Power.v1_1_3.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_1_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Power" BaseType="Power.v1_1_4.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_1_6">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation. It was also created to fix PowerMetrics/PowerMetric description, not to use abbreviated terms."/>
      <EntityType Name="Power" BaseType="Power.v1_1_5.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_2_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2016.2"/>
      <EntityType Name="Power" BaseType="Power.v1_1_0.Power"/>

      <EntityType Name="PowerSupply" BaseType="Power.v1_1_0.PowerSupply">
        <Property Name="IndicatorLED" Type="Resource.IndicatorLED">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The state of the indicator LED, used to identify the power supply."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain the indicator light state for the indicator light associated with this power supply."/>
        </Property>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_2_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add explicit Permissions annotations to all properties for clarity."/>
      <EntityType Name="Power" BaseType="Power.v1_2_0.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_2_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to remove the Nullable facet on NavigationProperties of type Collection and to use Redfish.Deprecated on certain enum values."/>
      <EntityType Name="Power" BaseType="Power.v1_2_1.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_2_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to remove the AutoExpand annotation for the Redundancy property inside PowerSupply."/>
      <EntityType Name="Power" BaseType="Power.v1_2_2.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_2_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to change references to PhysicalContext and IndicatorLED to use the unversioned definition."/>
      <EntityType Name="Power" BaseType="Power.v1_2_3.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_2_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Power" BaseType="Power.v1_2_4.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_2_6">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation. It was also created to fix PowerMetrics/PowerMetric description, not to use abbreviated terms."/>
      <EntityType Name="Power" BaseType="Power.v1_2_5.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_3_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.1"/>
      <EntityType Name="Power" BaseType="Power.v1_2_2.Power">
        <Property Name="Actions" Type="Power.v1_3_0.Actions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <EntityType Name="PowerControl" BaseType="Power.v1_0_0.PowerControl">
        <Property Name="Actions" Type="Power.v1_3_0.PowerControlActions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <EntityType Name="Voltage" BaseType="Power.v1_0_0.Voltage">
        <Property Name="Actions" Type="Power.v1_3_0.VoltageActions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <EntityType Name="PowerSupply" BaseType="Power.v1_2_0.PowerSupply">
        <Property Name="Actions" Type="Power.v1_3_0.PowerSupplyActions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="Power.v1_3_0.OemActions" Nullable="false">
          <Annotation Term="OData.Description" String="This property contains the available OEM specific actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any additional OEM actions for this resource."/>
        </Property>
      </ComplexType>

      <ComplexType Name="OemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
        <Annotation Term="OData.Description" String="The available OEM specific actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain any additional OEM actions for this resource."/>
      </ComplexType>

      <ComplexType Name="PowerControlActions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="Power.v1_3_0.PowerControlOemActions" Nullable="false">
          <Annotation Term="OData.Description" String="This property contains the available OEM specific actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any additional OEM actions for this resource."/>
        </Property>
      </ComplexType>

      <ComplexType Name="PowerControlOemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
        <Annotation Term="OData.Description" String="The available OEM specific actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain any additional OEM actions for this resource."/>
      </ComplexType>

      <ComplexType Name="VoltageActions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="Power.v1_3_0.VoltageOemActions" Nullable="false">
          <Annotation Term="OData.Description" String="This property contains the available OEM specific actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any additional OEM actions for this resource."/>
        </Property>
      </ComplexType>

      <ComplexType Name="VoltageOemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
        <Annotation Term="OData.Description" String="The available OEM specific actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain any additional OEM actions for this resource."/>
      </ComplexType>

      <ComplexType Name="PowerSupplyActions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="Power.v1_3_0.PowerSupplyOemActions" Nullable="false">
          <Annotation Term="OData.Description" String="This property contains the available OEM specific actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any additional OEM actions for this resource."/>
        </Property>
      </ComplexType>

      <ComplexType Name="PowerSupplyOemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
        <Annotation Term="OData.Description" String="The available OEM specific actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain any additional OEM actions for this resource."/>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_3_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to remove the AutoExpand annotation for the Redundancy property inside PowerSupply."/>
      <EntityType Name="Power" BaseType="Power.v1_3_0.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_3_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to change references to PhysicalContext and IndicatorLED to use the unversioned definition."/>
      <EntityType Name="Power" BaseType="Power.v1_3_1.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_3_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Power" BaseType="Power.v1_3_2.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_3_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation. It was also created to fix PowerMetrics/PowerMetric description, not to use abbreviated terms."/>
      <EntityType Name="Power" BaseType="Power.v1_3_3.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_4_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.2"/>
      <EntityType Name="Power" BaseType="Power.v1_3_1.Power"/>

      <EntityType Name="PowerControl" BaseType="Power.v1_3_0.PowerControl">
        <Property Name="PhysicalContext" Type="PhysicalContext.PhysicalContext" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Describes the area, device, or set of devices to which this power control applies."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a description of the affected device(s) or region within the chassis to which this power control applies."/>
        </Property>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_4_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to change references to PhysicalContext and IndicatorLED to use the unversioned definition."/>
      <EntityType Name="Power" BaseType="Power.v1_4_0.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_4_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Power" BaseType="Power.v1_4_1.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_4_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation. It was also created to fix PowerMetrics/PowerMetric description, not to use abbreviated terms."/>
      <EntityType Name="Power" BaseType="Power.v1_4_2.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_5_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.3"/>
      <EntityType Name="Power" BaseType="Power.v1_4_1.Power"/>

      <EntityType Name="PowerSupply" BaseType="Power.v1_3_0.PowerSupply">
        <Property Name="Location" Type="Resource.Location" Nullable="false">
          <Annotation Term="OData.Description" String="The Location of the power supply."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain location information of the associated power supply."/>
        </Property>
        <NavigationProperty Name="Assembly" Type="Assembly.Assembly" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the Assembly resource associated with this power supply."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a link to a resource of type Assembly."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <Property Name="PowerInputWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The measured input power of this Power Supply."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the value of the measured input power, in Watts, of the associated power supply."/>
          <Annotation Term="Measures.Unit" String="W"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="PowerOutputWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The measured output power of this Power Supply."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the value of the measured output power, in Watts, of the associated power supply."/>
          <Annotation Term="Measures.Unit" String="W"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="EfficiencyPercent" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The measured efficiency of this Power Supply as a percentage."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the value of the measured power efficiency, as a percentage, of the associated power supply."/>
          <Annotation Term="Measures.Unit" String="%"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Validation.Maximum" Int="100"/>
        </Property>
        <Property Name="HotPluggable" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Indicates if this device can be inserted or removed while the equipment is in operation."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate whether the device can be inserted or removed while the underlying equipment otherwise remains in its current operational state.  Devices indicated as hot-pluggable shall allow the device to become operable without altering the operational state of the underlying equipment. Devices that cannot be inserted or removed from equipment in operation, or devices that cannot become operable without affecting the operational state of that equipment, shall be indicated as not hot-pluggable."/>
        </Property>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_5_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Power" BaseType="Power.v1_5_0.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_5_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation. It was also created to fix PowerMetrics/PowerMetric description, not to use abbreviated terms."/>
      <EntityType Name="Power" BaseType="Power.v1_5_1.Power"/>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_POWER_V1_HPP */
