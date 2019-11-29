#ifndef PSME_REST_METADATA_SENSOR_V1_HPP
#define PSME_REST_METADATA_SENSOR_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Sensor_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  Sensor  v1.0.0-->
<!--#                                                                                      -->
<!--# For a detailed change log, see the README file contained in the DSP8010 bundle,      -->
<!--# available at http://www.dmtf.org/standards/redfish                                   -->
<!--# Copyright 2014-2018 Distributed Management Task Force, Inc. (DMTF).                  -->
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
  <edmx:Reference Uri="/redfish/v1/metadata/PhysicalContext_v1.xml">
    <edmx:Include Namespace="PhysicalContext"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Sensor">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="Sensor" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="This is the schema definition for the Sensor.  It represents the properties for Sensor."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent a Sensor resource for a Redfish implementation."/>
        <Annotation Term="Capabilities.InsertRestrictions">
          <Record>
            <PropertyValue Property="Insertable" Bool="false"/>
          </Record>
        </Annotation>
        <Annotation Term="Capabilities.UpdateRestrictions">
          <Record>
            <PropertyValue Property="Updatable" Bool="true"/>
            <Annotation Term="OData.Description" String="Sensor properties can be updated to change limits, exceptions and other writable properties."/>
          </Record>
        </Annotation>
        <Annotation Term="Capabilities.DeleteRestrictions">
          <Record>
            <PropertyValue Property="Deletable" Bool="false"/>
          </Record>
        </Annotation>
        <Annotation Term="Redfish.Uris">
          <Collection>
            <String>/redfish/v1/Chassis/{ChassisId}/Sensors/{SensorId}</String>
          </Collection>
        </Annotation>
      </EntityType>

      <Action Name="ResetStatistics" IsBound="true">
        <Parameter Name="Sensor" Type="Sensor.v1_0_0.Actions"/>
        <Annotation Term="OData.Description" String="This action is used to reset statistics related to this sensor."/>
        <Annotation Term="OData.LongDescription" String="This action shall perform a reset of any time intervals or counted values for this sensor."/>
      </Action>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Sensor.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.3"/>

      <EntityType Name="Sensor" BaseType="Sensor.Sensor">

        <Annotation Term="OData.Description" String="This schema defines a Sensor to be used in conjunction with data center equipment."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent resources that represent the sensor data."/>

        <Property Name="ReadingType" Type="Sensor.v1_0_0.ReadingType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The kind of sensor being represented."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the type of the sensor being represented."/>
        </Property>
        <Property Name="DataSourceUri" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A link to the resource that provides the data for this object."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain a URI to the resource that provides the source of the schema Excerpt contained within this copy."/>
          <Annotation Term="OData.IsURL"/>
          <Annotation Term="Redfish.ExcerptCopyOnly"/>
        </Property>

        <!-- Excerpt properties for a sensor -->
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Description" String="This property describes the status and health of the resource and its children."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any status or health properties of the resource."/>
          <Annotation Term="Redfish.Excerpt"/>
        </Property>

        <Property Name="Reading" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The present value for this Sensor."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the present value of this Sensor at the time the information request occurred."/>
          <Annotation Term="Redfish.Excerpt"/>
        </Property>
        <Property Name="ReadingUnits" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Units in which the reading and thresholds are measured."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the units in which the sensor's reading and thresholds are measured."/>
          <Annotation Term="Redfish.Excerpt"/>
        </Property>
        <Property Name="PhysicalContext" Type="PhysicalContext.PhysicalContext">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Describes the area or device to which this sensor measurement applies."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a description of the affected component or region within the equipment to which this sensor measurement applies."/>
          <Annotation Term="Redfish.Excerpt"/>
        </Property>
        <Property Name="PhysicalSubContext" Type="PhysicalContext.PhysicalSubContext">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Describes the usage or location within a device to which this sensor measurement applies."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a description of the usage or sub-region within the equipment to which this sensor measurement applies. This property is generally used to differentiate multiple sensors within the same instance of a PhysicalContext."/>
          <Annotation Term="Redfish.Excerpt"/>
        </Property>
        <Property Name="PeakReading" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The peak reading value for this sensor."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the peak value of the Reading for this sensor during the last interval."/>
          <Annotation Term="Redfish.Excerpt"/>
        </Property>

        <Property Name="MaxAllowableOperatingValue" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Maximum allowable operating value for this equipment."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate the maximum allowable operating value for the equipment monitored by this sensor, as specified by a standards body, manufacturer, or a combination."/>
        </Property>
        <Property Name="MinAllowableOperatingValue" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Minimum allowable operating value for this equipment."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate the minimum allowable operating value for the equipment monitored by this sensor, as specified by a standards body, manufacturer, or a combination."/>
        </Property>
        <Property Name="AdjustedMaxAllowableOperatingValue" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Adjusted maximum allowable operating value for this equipment based on the current environmental conditions present."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate the adjusted maximum allowable operating value for the equipment monitored by this sensor, as specified by a standards body, manufacturer, or a combination, and adjusted based on environmental conditions present. For example, liquid inlet temperature may be adjusted based on the available liquid pressure."/>
        </Property>
        <Property Name="AdjustedMinAllowableOperatingValue" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Adjusted minimum allowable operating value for this equipment based on the current environmental conditions present."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate the adjusted minimum allowable operating value for the equipment monitored by this sensor, as specified by a standards body, manufacturer, or a combination, and adjusted based on environmental conditions present. For example, liquid inlet temperature may be adjusted based on the available liquid pressure."/>
        </Property>

        <!-- Excerpt properties specific to power reading type -->
        <Property Name="ApparentVA" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The product of Voltage and Current for an AC circuit, in Volt-Amperes units."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the product of VoltageRMS multiplied by CurrentRMS for a circuit. PowerApparentVA is expressed in Volt-Amperes units using the ReadingUnits value of 'V'. This property may appear in sensors of ReadingType of Power, and shall not appear in sensors of other ReadingType values."/>
          <Annotation Term="Redfish.Excerpt" String="Power"/>
        </Property>
        <Property Name="ReactiveVAR" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The square root of the difference term of squared ApparentVA and squared Power (Reading) for a circuit, expressed in VAR units."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the arithmetic mean of product terms of instantaneous voltage and quadrature current measurements calculated over an integer number of line cycles for a circuit. PowerReactiveVAR is expressed in VAR units using the ReadingUnits value of 'V'. This property may appear in sensors of ReadingType of Power, and shall not appear in sensors of other ReadingType values."/>
          <Annotation Term="Redfish.Excerpt" String="Power"/>
        </Property>
        <Property Name="PowerFactor" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The power factor for this Sensor."/>
          <Annotation Term="OData.LongDescription" String="This property shall identify the quotient of PowerRealWatts and PowerApparentVA for a circuit. PowerFactor is expressed in unit-less 1/100ths. This property may appear in sensors of ReadingType of Power, and shall not appear in sensors of other ReadingType values."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Validation.Maximum" Int="1"/>
          <Annotation Term="Redfish.Excerpt" String="Power"/>
        </Property>
        <Property Name="LoadPercent" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The power load utilization for this Sensor."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the present value of this Sensor at the time the information request occurred. This property may appear in sensors of ReadingType of Power, and shall not appear in sensors of other ReadingType values."/>
          <Annotation Term="Redfish.Excerpt" String="Power"/>
        </Property>
        <!-- end of Excerpt properties -->

        <Property Name="Location" Type="Resource.Location">
          <Annotation Term="OData.Description" String="The location information for this Sensor."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the location information of this Sensor."/>
        </Property>
        <Property Name="ElectricalContext" Type="Sensor.v1_0_0.ElectricalContext">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The combination of current-carrying conductors."/>
          <Annotation Term="OData.LongDescription" String="This property shall represent the combination of current-carrying conductors that are utilized to distribute power."/>
        </Property>
        <Property Name="VoltageType" Type="Sensor.v1_0_0.VoltageType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The voltage type (AC or DC) for this sensor."/>
          <Annotation Term="OData.LongDescription" String="This property shall represent the type of input voltage the sensor monitors. Please use AC for alternating current and DC for direct current."/>
        </Property>

        <Property Name="Thresholds" Type="Sensor.v1_0_0.Thresholds">
          <Annotation Term="OData.Description" String="The set of thresholds defined for this sensor."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the set of thresholds that are used to derive a sensor's health and operational range."/>
        </Property>

        <Property Name="ReadingRangeMax" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The maximum value of Reading possible for this Sensor."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the Max Reading Range information of this Sensor. This is the range of valid readings for this sensor. Values outside this range are discarded as reading errors."/>
        </Property>
        <Property Name="ReadingRangeMin" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The minimum value of Reading possible for this Sensor."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the Min Reading Range information of this Sensor. This is the range of valid readings for this sensor. Values outside this range are discarded as reading errors."/>
        </Property>
        <Property Name="Precision" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Number of significant digits in the Reading."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall specify the number of significant digits in the Reading."/>
        </Property>
        <Property Name="Accuracy" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Estimated percent error of measured vs. actual values."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the percent error +/- of the measured vs. actual values."/>
        </Property>
        <Property Name="SensingFrequency" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The time interval between readings of the physical sensor."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall the time interval between reading the physical sensor."/>
        </Property>
        <Property Name="PeakReadingTime" Type="Edm.DateTimeOffset">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The time at which the Peak Reading value occurred."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall the timestamp when the Peak Reading value was observed."/>
        </Property>
        <Property Name="SensorResetTime" Type="Edm.DateTimeOffset">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The time at which the time-based properties were last reset."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the timestamp when the time-based property values were last reset by the user or the service."/>
        </Property>

        <Property Name="Actions" Type="Sensor.v1_0_0.Actions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>

      </EntityType>

      <ComplexType Name="Thresholds">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The set of thresholds defined for a sensor."/>
        <Annotation Term="OData.LongDescription" String="This object shall contain the set of thresholds that are used to derive a sensor's health and operational range."/>
        <Property Name="UpperCaution" Type="Sensor.v1_0_0.Threshold">
          <Annotation Term="OData.Description" String="Above normal range."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate the Reading is above the normal range. The units shall be the same units as the Reading."/>
        </Property>
        <Property Name="UpperCritical" Type="Sensor.v1_0_0.Threshold">
          <Annotation Term="OData.Description" String="Above normal range but not yet fatal."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate the Reading is above the normal range and but is not yet fatal. The units shall be the same units as the Reading."/>
        </Property>
        <Property Name="UpperFatal" Type="Sensor.v1_0_0.Threshold">
          <Annotation Term="OData.Description" String="Above normal range and fatal."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate the Reading is above the normal range and is fatal. The units shall be the same units as the Reading."/>
        </Property>
        <Property Name="LowerCaution" Type="Sensor.v1_0_0.Threshold">
          <Annotation Term="OData.Description" String="Below normal range."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate the Reading is below the normal range. The units shall be the same units as the Reading."/>
        </Property>
        <Property Name="LowerCritical" Type="Sensor.v1_0_0.Threshold">
          <Annotation Term="OData.Description" String="Below normal range but not yet fatal."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate the Reading is below the normal range and but is not yet fatal. The units shall be the same units as the Reading."/>
        </Property>
        <Property Name="LowerFatal" Type="Sensor.v1_0_0.Threshold">
          <Annotation Term="OData.Description" String="Below normal range and fatal."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate the Reading is below the normal range and is fatal. The units shall be the same units as the Reading."/>
        </Property>
      </ComplexType>

      <ComplexType Name="Threshold">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="A threshold definition for a sensor."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the properties for an individual threshold for this sensor."/>
        <Property Name="Reading" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The threshold value."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the Reading value of this Sensor that triggers the threshold. The units of this property shall follow the Reading and ReadingUnits of this sensor."/>
        </Property>
        <Property Name="Activation" Type="Sensor.v1_0_0.ThresholdActivation">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The direction of crossing that activates this threshold."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the direction of crossing of the Reading value for this Sensor that triggers the threshold."/>
        </Property>
        <Property Name="DwellTime" Type="Edm.Duration">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The time interval over which the sensor reading must have passed through this Threshold value before the threshold is considered to be violated."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the time interval over which the sensor reading must have passed through this Threshold value before the threshold is considered to be violated."/>
        </Property>
      </ComplexType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="Sensor.v1_0_0.OemActions" Nullable="false">
          <Annotation Term="OData.Description" String="This property contains the available OEM specific actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any additional OEM actions for this resource."/>
        </Property>
      </ComplexType>

      <ComplexType Name="OemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
        <Annotation Term="OData.Description" String="The available OEM specific actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain any additional OEM actions for this resource."/>
      </ComplexType>

      <EnumType Name="ThresholdActivation">
        <Member Name="Increasing">
          <Annotation Term="OData.Description" String="Value increases above the threshold."/>
          <Annotation Term="OData.LongDescription" String="This threshold is activated when the value of Reading changes from a value lower than the threshold to a value higher than the threshold."/>
        </Member>
        <Member Name="Decreasing">
          <Annotation Term="OData.Description" String="Value decreases below the threshold."/>
          <Annotation Term="OData.LongDescription" String="This threshold is activated when the value of Reading changes from a value higher than the threshold to a value lower than the threshold."/>
        </Member>
        <Member Name="Either">
          <Annotation Term="OData.Description" String="Value crosses the threshold in either direction."/>
          <Annotation Term="OData.LongDescription" String="This threshold is activated when either the Increasing or Decreasing conditions are met."/>
        </Member>
      </EnumType>

      <EnumType Name="ReadingType">
        <Member Name="Temperature">
          <Annotation Term="OData.Description" String="Temperature."/>
          <Annotation Term="OData.LongDescription" String="The value of the Reading property shall be a temperature measurement in degrees Celsius units and the ReadingUnits value shall be 'Cel'."/>
        </Member>
        <Member Name="Humidity">
          <Annotation Term="OData.Description" String="Relative Humidity."/>
          <Annotation Term="OData.LongDescription" String="The value of the Reading property shall be a relative humidity measurement in percent units and the ReadingUnits value shall be '%'."/>
        </Member>
        <Member Name="Power">
          <Annotation Term="OData.Description" String="Power."/>
          <Annotation Term="OData.LongDescription" String="The value of the Reading property shall be the arithmetic mean of product terms of instantaneous voltage and current values measured over integer number of line cycles for a circuit in Watt units and the ReadingUnits value shall be 'W'."/>
        </Member>
        <Member Name="EnergykWh">
          <Annotation Term="OData.Description" String="Energy consumption (kW/h)."/>
          <Annotation Term="OData.LongDescription" String="The value of the Reading property shall indicate the energy consumption (integral of Real Power over time) of the monitored item since the sensor statistics were last reset. The value of the Reading property shall be in kilowatt-hour units and the ReadingUnits value shall be 'kW'. This type is used for large-scale energy consumption measurements, while EnergyJoules is used for device-level consumption measurements."/>
        </Member>
        <Member Name="EnergyJoules">
          <Annotation Term="OData.Description" String="Energy consumption (Joules)."/>
          <Annotation Term="OData.LongDescription" String="The value of the Reading property shall indicate the energy consumption (integral of Real Power over time) of the monitored item since the sensor statistics were last reset. The value of the Reading property shall be in Joule units and the ReadingUnits value shall be 'J'. This type is used for device-level energy consumption measurements, while EnergykWh is used for large-scale consumption measurements."/>
        </Member>
        <Member Name="Voltage">
          <Annotation Term="OData.Description" String="Voltage (AC or DC)."/>
          <Annotation Term="OData.LongDescription" String="The value of the Reading property shall be a measurement of the root mean square (RMS) of instantaneous voltage calculated over an integer number of line cycles for a circuit.  Voltage is expressed in Volts units and the ReadingUnits value shall be 'V'."/>
        </Member>
        <Member Name="Current">
          <Annotation Term="OData.Description" String="Current."/>
          <Annotation Term="OData.LongDescription" String="The value of the Reading property shall be a measurement of  the root mean square (RMS) of instantaneous current calculated over an integer number of line cycles for a circuit. Current is expressed in Amperes units and the ReadingUnits value shall be 'A'."/>
        </Member>
        <Member Name="Frequency">
          <Annotation Term="OData.Description" String="Frequency."/>
          <Annotation Term="OData.LongDescription" String="The value of the Reading property shall be a frequency measurement in Hertz units and the ReadingUnits value shall be 'Hz'."/>
        </Member>
        <Member Name="Pressure">
          <Annotation Term="OData.Description" String="Pressure."/>
          <Annotation Term="OData.LongDescription" String="The value of the Reading property shall be a measurement of force applied perpendicular to the surface of an object per unit area over which that force is distributed. The ReadingUnits shall be 'Pa'."/>
        </Member>
        <Member Name="LiquidLevel">
          <Annotation Term="OData.Description" String="Liquid level."/>
          <Annotation Term="OData.LongDescription" String="The value of the Reading property shall be a measurement of fluid height relative to a specified vertical datum and the ReadingUnits value shall be 'cm'."/>
        </Member>
        <Member Name="Rotational">
          <Annotation Term="OData.Description" String="Rotational."/>
          <Annotation Term="OData.LongDescription" String="The value of the Reading property shall be a measurement of rotational frequency in Revolutions per Minute unit and the ReadingUnits value shall be 'RPM'."/>
        </Member>
        <Member Name="AirFlow">
          <Annotation Term="OData.Description" String="Airflow."/>
          <Annotation Term="OData.LongDescription" String="The value of the Reading property shall be a measurement of a volume of gas per unit of time that flows through a particular junction. The ReadingUnits shall be 'cft_i/min'."/>
        </Member>
        <Member Name="LiquidFlow">
          <Annotation Term="OData.Description" String="Liquid flow."/>
          <Annotation Term="OData.LongDescription" String="The value of the Reading property shall be a measurement of a volume of liquid per unit of time that flows through a particular junction. The ReadingUnits shall be 'L/s'."/>
        </Member>
        <Member Name="Barometric">
          <Annotation Term="OData.Description" String="Barometric Pressure."/>
          <Annotation Term="OData.LongDescription" String="the value of the Reading property shall be a measurement of barometric pressure in millimeters of a mercury column and the ReadingUnits value shall be 'mm[Hg]'."/>
        </Member>
        <Member Name="Altitude">
          <Annotation Term="OData.Description" String="Altitude."/>
          <Annotation Term="OData.LongDescription" String="The value of the Reading property shall be a measurement of altitude in meter units and the ReadingUnits value shall be 'm'."/>
        </Member>
      </EnumType>

      <EnumType Name="VoltageType">
        <Member Name="AC">
          <Annotation Term="OData.Description" String="Alternating Current."/>
        </Member>
        <Member Name="DC">
          <Annotation Term="OData.Description" String="Direct Current."/>
        </Member>
      </EnumType>

      <EnumType Name="ElectricalContext">
        <Member Name="Line1">
          <Annotation Term="OData.Description" String="The circuits sharing L1 current-carrying conductor."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the circuits sharing L1 current-carrying conductor when PhaseWiringType.TwoPhase3Wire, TwoPhase4Wire, ThreePhase4Wire, or ThreePhase5Wire."/>
        </Member>
        <Member Name="Line2">
          <Annotation Term="OData.Description" String="The circuits sharing L2 current-carrying conductor when PhaseWiringType.ThreePhase4Wire. TwoPhase4Wire, or ThreePhase5Wire."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the circuits sharing L2 current-carrying conductor when PhaseWiringType.ThreePhase4Wire. TwoPhase4Wire, or ThreePhase5Wire."/>
        </Member>
        <Member Name="Line3">
          <Annotation Term="OData.Description" String="The circuits sharing L3 current-carrying conductor when PhaseWiringType.ThreePhase4Wire or ThreePhase5Wire."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the circuits sharing L3 current-carrying conductor when PhaseWiringType.ThreePhase4Wire or ThreePhase5Wire."/>
        </Member>
        <Member Name="Neutral">
          <Annotation Term="OData.Description" String="The grounded current-carrying return circuit of current-carrying conductors when PhaseWiringType.OnePhase3Wire, TwoPhase4Wire, or ThreePhase5Wire."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the grounded current-carrying return circuit of current-carrying conductors when PhaseWiringType.OnePhase3Wire, TwoPhase4Wire, or ThreePhase5Wire."/>
        </Member>
        <Member Name="LineToLine">
          <Annotation Term="OData.Description" String="The circuit formed by two current-carrying conductors when PhaseWiringType.TwoPhase3Wire, TwoPhase4Wire, ThreePhase4Wire, or ThreePhase5Wire."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the circuit formed by two current-carrying conductors when PhaseWiringType.TwoPhase3Wire, TwoPhase4Wire, ThreePhase4Wire, or ThreePhase5Wire."/>
        </Member>
        <Member Name="Line1ToLine2">
          <Annotation Term="OData.Description" String="The circuit formed by L1 and L2 current-carrying conductors when PhaseWiringType.TwoPhase3Wire, TwoPhase4Wire, ThreePhase4Wire, or ThreePhase5Wire."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the circuit formed by L1 and L2 current-carrying conductors when PhaseWiringType.TwoPhase3Wire, TwoPhase4Wire, ThreePhase4Wire, or ThreePhase5Wire."/>
        </Member>
        <Member Name="Line2ToLine3">
          <Annotation Term="OData.Description" String="The circuit formed by L2 and L3 current-carrying conductors when PhaseWiringType.ThreePhase4Wire or ThreePhase5Wire."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the circuit formed by L2 and L3 current-carrying conductors when PhaseWiringType.ThreePhase4Wire or ThreePhase5Wire."/>
        </Member>
        <Member Name="Line3ToLine1">
          <Annotation Term="OData.Description" String="The circuit formed by L3 and L1 current-carrying conductors when PhaseWiringType.ThreePhase4Wire or ThreePhase5Wire."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the circuit formed by L3 and L1 current-carrying conductors when PhaseWiringType.ThreePhase4Wire or ThreePhase5Wire."/>
        </Member>
        <Member Name="LineToNeutral">
          <Annotation Term="OData.Description" String="The circuit formed by a line and Neutral current-carrying conductor when PhaseWiringType.OnePhase3Wire, TwoPhase4Wire, ThreePhase4Wire, or ThreePhase5Wire."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the circuit formed by a line and Neutral current-carrying conductor when PhaseWiringType.OnePhase3Wire, TwoPhase4Wire, ThreePhase4Wire, or ThreePhase5Wire."/>
        </Member>
        <Member Name="Line1ToNeutral">
          <Annotation Term="OData.Description" String="The circuit formed by L1 and Neutral current-carrying conductors when PhaseWiringType.OnePhase3Wire, TwoPhase4Wire, ThreePhase4Wire, or ThreePhase5Wire."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the circuit formed by L1 and Neutral current-carrying conductors when PhaseWiringType.OnePhase3Wire, TwoPhase4Wire, ThreePhase4Wire, or ThreePhase5Wire."/>
        </Member>
        <Member Name="Line2ToNeutral">
          <Annotation Term="OData.Description" String="The circuit formed by L2 and Neutral current-carrying conductors when PhaseWiringType.TwoPhase4Wire or ThreePhase5Wire."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the circuit formed by L2 and Neutral current-carrying conductors when PhaseWiringType.TwoPhase4Wire or ThreePhase5Wire."/>
        </Member>
        <Member Name="Line3ToNeutral">
          <Annotation Term="OData.Description" String="The circuit formed by L3 and Neutral current-carrying conductors when PhaseWiringType.ThreePhase5Wire."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the circuit formed by L3 and Neutral current-carrying conductors when PhaseWiringType.ThreePhase5Wire."/>
        </Member>
         <Member Name="Line1ToNeutralAndL1L2">
          <Annotation Term="OData.Description" String="The circuits formed by L1, L2, and Neutral current-carrying conductors when PhaseWiringType.TwoPhase4Wire or ThreePhase5Wire."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the circuits formed by L1, L2, and Neutral current-carrying conductors when PhaseWiringType.TwoPhase4Wire or ThreePhase5Wire."/>
        </Member>
        <Member Name="Line2ToNeutralAndL1L2">
          <Annotation Term="OData.Description" String="The circuits formed by L1, L2, and Neutral current-carrying conductors when PhaseWiringType.TwoPhase4Wire or ThreePhase5Wire."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the circuits formed by L1, L2, and Neutral current-carrying conductors when PhaseWiringType.TwoPhase4Wire or ThreePhase5Wire."/>
        </Member>
        <Member Name="Line2ToNeutralAndL2L3">
          <Annotation Term="OData.Description" String="The circuits formed by L2, L3, and Neutral current-carrying conductors when PhaseWiringType.ThreePhase5Wire."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the circuits formed by L2, L3, and Neutral current-carrying conductors when PhaseWiringType.ThreePhase5Wire."/>
        </Member>
        <Member Name="Line3ToNeutralAndL3L1">
          <Annotation Term="OData.Description" String="The circuits formed by L3, L1, and Neutral current-carrying conductors when PhaseWiringType.ThreePhase5Wire."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the circuits formed by L3, L1, and Neutral current-carrying conductors when PhaseWiringType.ThreePhase5Wire."/>
        </Member>
        <Member Name="Total">
          <Annotation Term="OData.Description" String="The circuits formed by all current-carrying conductors for any PhaseWiringType."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the circuits formed by all current-carrying conductors for any PhaseWiringType."/>
        </Member>
      </EnumType>

    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_SENSOR_V1_HPP */
