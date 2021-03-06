#ifndef PSME_REST_METADATA_DRIVE_METRICS_V1_HPP
#define PSME_REST_METADATA_DRIVE_METRICS_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string DriveMetrics_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Measures.V1.xml">
    <edmx:Include Namespace="Org.OData.Measures.V1" Alias="Measures"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
    <edmx:Include Namespace="Validation.v1_0_0" Alias="Validation"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="DriveMetrics">

      <EntityType Name="DriveMetrics" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description"
                    String="DriveMetrics contains usage and health statistics for a single physical Drive."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent the Drive Metrics for a single physical Drive in a Redfish implementation."/>
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="DriveMetrics.v1_0_0">

      <EntityType Name="DriveMetrics" BaseType="DriveMetrics.DriveMetrics">
        <Property Name="TemperatureKelvin" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Temperature in degrees Kelvin corresponding to the Drive resource."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be temperature of the Drive resource in Kelvin degrees."/>
          <Annotation Term="Measures.Unit" String="Kel"/>
        </Property>
        <Property Name="LifeTime" Type="DriveMetrics.v1_0_0.LifeTime" Nullable="false">
          <Annotation Term="OData.Description"
                      String="This object contains the physical Drive metrics for the lifetime of the physical drive."/>
          <Annotation Term="OData.LongDescription"
                      String="This object shall contain properties which describe the LifeTime metrics for the current resource."/>
        </Property>
        <Property Name="HealthData" Type="DriveMetrics.v1_0_0.HealthData" Nullable="false">
          <Annotation Term="OData.Description" String="This object describes the health information of the physical drive."/>
          <Annotation Term="OData.LongDescription"
                      String="This object shall contain properties which describe the HealthData metrics for the current resource."/>
        </Property>
        <Property Name="ReadsLatencyHistogram" Type="DriveMetrics.v1_0_0.LatencyHistogram" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Histogram of the various latency ranges for disk reads."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall provide a way to track latencies experienced internally by the controller for read commands."/>
        </Property>
        <Property Name="WritesLatencyHistogram" Type="DriveMetrics.v1_0_0.LatencyHistogram" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Histogram of the various latency rangeis of disk writes."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall provide a way to track latencies experienced internally by the controller for write commands."/>
        </Property>
      </EntityType>

      <ComplexType Name="LifeTime">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="UnitSizeBytes" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Size in bytes corresponding to UnitRead / UnitWrite basic unit."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be size of a unit (the value is reported in bytes) that is utilized by UnitRead / UnitWrite properties as a basic unit."/>
        </Property>
        <Property Name="UnitsRead" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Number of units read since reset."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be number of units of a size UnitSizeBytes read since reset. This can be used to compute average bandwidth by polling the drive at regular intervals."/>
        </Property>
        <Property Name="UnitsWritten" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Number of units written since reset."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be number of units of a size UnitSizeBytes written since reset. This can be used to compute average bandwidth by polling the drive at regular intervals."/>
        </Property>
        <Property Name="HostReadCommands" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Number of read commands completed by Disk controller since reset."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be number of number of read commands completed by Disk controller since reset. For NMVe Disk controller specifically, this is number of Compare and Read commands."/>
        </Property>
        <Property Name="HostWriteCommands" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Number of write commands completed by Disk controller since reset."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be number of number of write commands completed by Disk controller since reset."/>
        </Property>
        <Property Name="PowerCycles" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Contains number of power cycles."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be number of power cycles of the physical drive."/>
        </Property>
        <Property Name="PowerOnHours" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Contains number of power-on hours."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the number of hours the physical drive was powered on. This may not include time that the controller was powered and remained in an non-operational power state."/>
        </Property>
        <Property Name="ControllerBusyTimeMinutes" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Contains amount of time (in minutes) the drive controller is busy with I/O commands."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be amount of time (in minutes) the drive controller is busy with I/O commands."/>
        </Property>
        <Annotation Term="OData.Description"
                    String="This object contains the physical Drive metrics for the lifetime of the physical drive."/>
        <Annotation Term="OData.LongDescription"
                    String="This type shall describe the metrics of the physical drive since manufacturing."/>
      </ComplexType>

      <ComplexType Name="HealthData">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This type describes the health information of the physical drive."/>
        <Annotation Term="OData.LongDescription"
                    String="This type shall contain properties which describe the HealthData metrics for the current resource."/>
        <Property Name="AvailableSparePercentage" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Percentage of the remaining spare capacity available."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a normalized percentage (0 to 100%) of the remaining spare capacity available."/>
        </Property>
        <Property Name="PredictedMediaLifeUsedPercent" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="Estimate of the percentage of Drive life used based on the actual usage and the manufacturer’s prediction of Drive life"/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain an indicator of the percentage of life remaining in the Drive's media."/>
        </Property>
        <Property Name="UnsafeShutdowns" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Contains the number of unsafe shutdowns of a drive."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be number of unsafe shutdowns of a drive."/>
        </Property>
        <Property Name="MediaErrors" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Contains the number of media and data integrity errors of a drive."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be number of media and data integrity errors of a drive. This includes ECC, CRC checksum failure or LBA tag mismatch errors."/>
        </Property>
      </ComplexType>

      <ComplexType Name="LatencyHistogram">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
        <Annotation Term="Redfish.DynamicPropertyPatterns">
          <Collection>
            <Record>
              <PropertyValue Property="Pattern" String="From[0-9]+(To[0-9]+)?(Micro|Milli|)Seconds"/>
              <PropertyValue Property="Type" String="Edm.Int64"/>
              <Annotation Term="OData.Description" String="Each property in the histogram shall represent one bucket of the histogram."/>
              <Annotation Term="OData.LongDescription" String="Each property in the histogram shall represent one bucket of the histogram."/>
            </Record>
          </Collection>
        </Annotation>
        <Annotation Term="OData.Description" String="A set of buckets constituting a histogram of latencies of handling commands."/>
        <Annotation Term="OData.LongDescription" String="A set of buckets constituting a histogram of latencies of handling commands."/>
      </ComplexType>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_DRIVE_METRICS_V1_HPP */
