#ifndef PSME_REST_METADATA_LOG_ENTRY_V1_HPP
#define PSME_REST_METADATA_LOG_ENTRY_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string LogEntry_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  LogEntry  v1.4.1-->
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
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Event_v1.xml">
    <edmx:Include Namespace="Event"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="LogEntry" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="This resource defines the record format for a log.  It is designed to be used for SEL logs (from IPMI) as well as Event Logs and OEM-specific log formats.  The EntryType field indicates the type of log and the resource includes several additional properties dependent on the EntryType."/>
        <Annotation Term="OData.LongDescription" String="This resource shall represent the log format for log services in a Redfish implementation."/>
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
            <PropertyValue Property="Deletable" Bool="true"/>
            <Annotation Term="OData.Description" String="Some implementations may allow the deletion of individual Log Entries."/>
          </Record>
        </Annotation>
        <Annotation Term="Redfish.Uris">
          <Collection>
            <String>/redfish/v1/Managers/{ManagerId}/LogServices/{LogServiceId}/Entries/{LogEntryId}</String>
            <String>/redfish/v1/Systems/{ComputerSystemId}/LogServices/{LogServiceId}/Entries/{LogEntryId}</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/LogServices/{LogServiceId}/Entries/{LogEntryId}</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/LogServices/{LogServiceId}/Entries/{LogEntryId}</String>
          </Collection>
        </Annotation>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="1.0"/>

      <EntityType Name="LogEntry" BaseType="LogEntry.LogEntry">
        <Property Name="Severity" Type="LogEntry.v1_0_0.EventSeverity">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the severity of the log entry."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the severity of the condition resulting in the log entry, as defined in the Status section of the Redfish specificaiton."/>
        </Property>
        <Property Name="Created" Type="Edm.DateTimeOffset" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The time the log entry was created."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the time at which the log entry was created."/>
        </Property>
        <Property Name="EntryType" Type="LogEntry.v1_0_0.LogEntryType" Nullable="false">
          <Annotation Term="Redfish.RequiredOnCreate"/>
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the type of log entry."/>
          <Annotation Term="OData.LongDescription" String="This property shall represent the type of LogEntry.  If the resource represents an IPMI SEL log entry, the value shall be SEL.  If the resource represents an Event log, the value shall be Event.  If the resource represents an OEM log format, the value shall be Oem."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="OemRecordFormat" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="If the EntryType is Oem, this will contain more information about the record format from the Oem."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the OEM specific format of the Entry.  This property shall be required if the value of EntryType is Oem."/>
        </Property>
        <Property Name="EntryCode" Type="LogEntry.v1_0_0.LogEntryCode">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="If the EntryType is SEL, this will have the entry code for the log entry."/>
          <Annotation Term="OData.LongDescription" String="This property shall be present if the EntryType value is SEL.  These enumerations are the values from tables 42-1 and 42-2 of the IPMI specification."/>
        </Property>
        <Property Name="SensorType" Type="LogEntry.v1_0_0.SensorType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="If the EntryType is SEL, this will have the sensor type that the log entry pertains to."/>
          <Annotation Term="OData.LongDescription" String="This property shall be present if the EntryType value is SEL.  These enumerations are the values from table 42-3 of the IPMI specification."/>
        </Property>
        <Property Name="SensorNumber" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This property decodes from EntryType.  If the EntryType is SEL, it is the sensor number.  If the EntryType is Event, then the count of events.  Otherwise, it is OEM specific."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the IPMI sensor number if the EntryType is SEL, the count of events if the EntryType is Event, and OEM Specific if EntryType is Oem."/>
        </Property>
        <Property Name="Message" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This property decodes from EntryType.  If the EntryType is Event, then it is a message string.  Otherwise, it is SEL or OEM specific.  In most cases, this will be the actual Log Entry."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the Message property of the event if the EntryType is Event, the Description if the EntryType is SEL, and OEM Specific if the EntryType is Oem."/>
        </Property>
        <Property Name="MessageId" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This property decodes from EntryType.  If the EntryType is Event, then it is a message id.  If the EntryType is SEL, then it contains the Event Data.  Otherwise, it is OEM specific.  This value is only used for registries - for more information, see the specification."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall the MessageId property of the event if the EntryType is Event, the three IPMI Event Data bytes if the EntryType is SEL, and OEM Specific if the EntryType is Oem.  The format of this property shall be as defined in the Redfish specification.  If representing the three IPMI Event Data bytes, the format should follow the pattern '^0[xX](([a-fA-F]|[0-9]){2}){3}$', where Event Data 1 is the first byte in the string, Event Data 2 is the second byte in the string, and Event Data 3 is the third byte in the string."/>
        </Property>
        <Property Name="MessageArgs" Type="Collection(Edm.String)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The values of this property shall be any arguments for the message."/>
          <Annotation Term="OData.LongDescription" String="This contains message arguments to be substituted into the message included or in the message looked up via a registry."/>
        </Property>
        <Property Name="Links" Type="LogEntry.v1_0_0.Links" Nullable="false">
          <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
          <Annotation Term="OData.LongDescription" String="The Links property, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Links" BaseType="Resource.Links">
        <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
        <Annotation Term="OData.LongDescription" String="This type, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        <NavigationProperty Name="OriginOfCondition" Type="Resource.Item" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the URI of the resource that caused the log entry."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an href that references the resource for which the log is associated."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <EnumType Name="EventSeverity">
        <Member Name="OK">
          <Annotation Term="OData.Description" String="Informational or operating normally."/>
        </Member>
        <Member Name="Warning">
          <Annotation Term="OData.Description" String="A condition requiring attention."/>
        </Member>
        <Member Name="Critical">
          <Annotation Term="OData.Description" String="A critical condition requiring immediate attention."/>
        </Member>
      </EnumType>

      <EnumType Name="LogEntryType">
        <Member Name="Event">
          <Annotation Term="OData.Description" String="Contains a Redfish-defined message (event)."/>
        </Member>
        <Member Name="SEL">
          <Annotation Term="OData.Description" String="Contains a legacy IPMI System Event Log (SEL) entry."/>
        </Member>
        <Member Name="Oem">
          <Annotation Term="OData.Description" String="Contains an entry in an OEM-defined format."/>
        </Member>
      </EnumType>

      <TypeDefinition Name="LogEntryCode" UnderlyingType="Edm.String">
        <Annotation Term="Redfish.Enumeration">
          <Collection>
            <Record>
              <PropertyValue Property="Member" String="Assert"/>
              <Annotation Term="OData.Description" String="The condition has been asserted."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Deassert"/>
              <Annotation Term="OData.Description" String="The condition has been deasserted."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Lower Non-critical - going low"/>
              <Annotation Term="OData.Description" String="The reading crossed the Lower Non-critical threshold while going low."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Lower Non-critical - going high"/>
              <Annotation Term="OData.Description" String="The reading crossed the Lower Non-critical threshold while going high."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Lower Critical - going low"/>
              <Annotation Term="OData.Description" String="The reading crossed the Lower Critical threshold while going low."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Lower Critical - going high"/>
              <Annotation Term="OData.Description" String="The reading crossed the Lower Critical threshold while going high."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Lower Non-recoverable - going low"/>
              <Annotation Term="OData.Description" String="The reading crossed the Lower Non-recoverable threshold while going low."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Lower Non-recoverable - going high"/>
              <Annotation Term="OData.Description" String="The reading crossed the Lower Non-recoverable threshold while going high."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Upper Non-critical - going low"/>
              <Annotation Term="OData.Description" String="The reading crossed the Upper Non-critical threshold while going low."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Upper Non-critical - going high"/>
              <Annotation Term="OData.Description" String="The reading crossed the Upper Non-critical threshold while going high."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Upper Critical - going low"/>
              <Annotation Term="OData.Description" String="The reading crossed the Upper Critical threshold while going low."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Upper Critical - going high"/>
              <Annotation Term="OData.Description" String="The reading crossed the Upper Critical threshold while going high."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Upper Non-recoverable - going low"/>
              <Annotation Term="OData.Description" String="The reading crossed the Upper Non-recoverable threshold while going low."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Upper Non-recoverable - going high"/>
              <Annotation Term="OData.Description" String="The reading crossed the Upper Non-recoverable threshold while going high."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Transition to Idle"/>
              <Annotation Term="OData.Description" String="The state transitioned to idle."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Transition to Active"/>
              <Annotation Term="OData.Description" String="The state transitioned to active."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Transition to Busy"/>
              <Annotation Term="OData.Description" String="The state transitioned to busy."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="State Deasserted"/>
              <Annotation Term="OData.Description" String="The state has been deasserted."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="State Asserted"/>
              <Annotation Term="OData.Description" String="The state has been asserted."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Predictive Failure deasserted"/>
              <Annotation Term="OData.Description" String="A Predictive Failure is no longer present."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Predictive Failure asserted"/>
              <Annotation Term="OData.Description" String="A Predictive Failure has been detected."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Limit Not Exceeded"/>
              <Annotation Term="OData.Description" String="A limit has not been exceeded."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Limit Exceeded"/>
              <Annotation Term="OData.Description" String="A limit has been exceeded."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Performance Met"/>
              <Annotation Term="OData.Description" String="Performance meets expectations."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Performance Lags"/>
              <Annotation Term="OData.Description" String="Performance does not meet expectations."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Transition to OK"/>
              <Annotation Term="OData.Description" String="A state has changed to OK."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Transition to Non-Critical from OK"/>
              <Annotation Term="OData.Description" String="A state has changed to Non-Critical from OK."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Transition to Critical from less severe"/>
              <Annotation Term="OData.Description" String="A state has changed to Critical from less severe."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Transition to Non-recoverable from less severe"/>
              <Annotation Term="OData.Description" String="A state has changed to Non-recoverable from less severe."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Transition to Non-Critical from more severe"/>
              <Annotation Term="OData.Description" String="A state has changed to Non-Critical from more severe."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Transition to Critical from Non-recoverable"/>
              <Annotation Term="OData.Description" String="A state has changed to Critical from Non-recoverable."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Transition to Non-recoverable"/>
              <Annotation Term="OData.Description" String="A state has changed to Non-recoverable."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Monitor"/>
              <Annotation Term="OData.Description" String="A Monitor event."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Informational"/>
              <Annotation Term="OData.Description" String="An Informational event."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Device Removed / Device Absent"/>
              <Annotation Term="OData.Description" String="A device has been removed or is now absent."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Device Inserted / Device Present"/>
              <Annotation Term="OData.Description" String="A device has been inserted or is now present."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Device Disabled"/>
              <Annotation Term="OData.Description" String="A device has been disabled."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Device Enabled"/>
              <Annotation Term="OData.Description" String="A device has been enabled."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Transition to Running"/>
              <Annotation Term="OData.Description" String="A state has transitioned to Running."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Transition to In Test"/>
              <Annotation Term="OData.Description" String="A state has transitioned to In Test."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Transition to Power Off"/>
              <Annotation Term="OData.Description" String="A state has transitioned to Power Off."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Transition to On Line"/>
              <Annotation Term="OData.Description" String="A state has transitioned to On Line."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Transition to Off Line"/>
              <Annotation Term="OData.Description" String="A state has transitioned to Off Line."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Transition to Off Duty"/>
              <Annotation Term="OData.Description" String="A state has transitioned to Off Duty."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Transition to Degraded"/>
              <Annotation Term="OData.Description" String="A state has transitioned to Degraded."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Transition to Power Save"/>
              <Annotation Term="OData.Description" String="A state has transitioned to Power Save."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Install Error"/>
              <Annotation Term="OData.Description" String="An Install Error has been detected."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Fully Redundant"/>
              <Annotation Term="OData.Description" String="Indicates that full redundancy has been regained."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Redundancy Lost"/>
              <Annotation Term="OData.Description" String="Entered any non-redundant state, including Non-redundant: Insufficient Resources."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Redundancy Degraded"/>
              <Annotation Term="OData.Description" String="Redundancy still exists, but at less than full level."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Non-redundant:Sufficient Resources from Redundant"/>
              <Annotation Term="OData.Description" String="Redundancy has been lost but unit is functioning with minimum resources needed for normal operation."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Non-redundant:Sufficient Resources from Insufficient Resources"/>
              <Annotation Term="OData.Description" String="Unit has regianed minimum resources needed for normal operation."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Non-redundant:Insufficient Resources"/>
              <Annotation Term="OData.Description" String="Unit is non-redundant and has insufficient resource to maintain normal operation."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Redundancy Degraded from Fully Redundant"/>
              <Annotation Term="OData.Description" String="Unit has lost some redundant resource(s) but is still in a redundant state."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Redundancy Degraded from Non-redundant"/>
              <Annotation Term="OData.Description" String="Unit has regained some resource(s) and is redundant but not fully redundant."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="D0 Power State"/>
              <Annotation Term="OData.Description" String="The ACPI defined D0 Power State."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="D1 Power State"/>
              <Annotation Term="OData.Description" String="The ACPI defined D1 Power State."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="D2 Power State"/>
              <Annotation Term="OData.Description" String="The ACPI defined D2 Power State."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="D3 Power State"/>
              <Annotation Term="OData.Description" String="The ACPI defined D3 Power State."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="OEM"/>
              <Annotation Term="OData.Description" String="An OEM defined event."/>
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

      <TypeDefinition Name="SensorType" UnderlyingType="Edm.String">
        <Annotation Term="Redfish.Enumeration">
          <Collection>
            <Record>
              <PropertyValue Property="Member" String="Platform Security Violation Attempt"/>
              <Annotation Term="OData.Description" String="A platform security sensor."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Temperature"/>
              <Annotation Term="OData.Description" String="A temperature sensor."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Voltage"/>
              <Annotation Term="OData.Description" String="A voltage sensor."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Current"/>
              <Annotation Term="OData.Description" String="A current sensor."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Fan"/>
              <Annotation Term="OData.Description" String="A fan sensor."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Physical Chassis Security"/>
              <Annotation Term="OData.Description" String="A physical security sensor."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Processor"/>
              <Annotation Term="OData.Description" String="A sensor for a processor."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Power Supply / Converter"/>
              <Annotation Term="OData.Description" String="A sensor for a power supply or DC-to-DC converter."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="PowerUnit"/>
              <Annotation Term="OData.Description" String="A sensor for a power unit."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="CoolingDevice"/>
              <Annotation Term="OData.Description" String="A sensor for a cooling device."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Other Units-based Sensor"/>
              <Annotation Term="OData.Description" String="A sensor for a miscellaneous analog sensor."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Memory"/>
              <Annotation Term="OData.Description" String="A sensor for a memory device."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Drive Slot/Bay"/>
              <Annotation Term="OData.Description" String="A sensor for a drive slot or bay."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="POST Memory Resize"/>
              <Annotation Term="OData.Description" String="A sensor for a POST memory resize event."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="System Firmware Progress"/>
              <Annotation Term="OData.Description" String="A sensor for a system firmware progress event."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Event Logging Disabled"/>
              <Annotation Term="OData.Description" String="A sensor for the event log."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="System Event"/>
              <Annotation Term="OData.Description" String="A sensor for a system event."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Critical Interrupt"/>
              <Annotation Term="OData.Description" String="A sensor for a critical interrupt event."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Button/Switch"/>
              <Annotation Term="OData.Description" String="A sensor for a button or switch."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Module/Board"/>
              <Annotation Term="OData.Description" String="A sensor for a module or board."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Microcontroller/Coprocessor"/>
              <Annotation Term="OData.Description" String="A sensor for a microcontroller or coprocessor."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Add-in Card"/>
              <Annotation Term="OData.Description" String="A sensor for an add-in card."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Chassis"/>
              <Annotation Term="OData.Description" String="A sensor for a chassis."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="ChipSet"/>
              <Annotation Term="OData.Description" String="A sensor for a chipset."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Other FRU"/>
              <Annotation Term="OData.Description" String="A sensor for an other type of FRU."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Cable/Interconnect"/>
              <Annotation Term="OData.Description" String="A sensor for a cable or interconnect type of device."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Terminator"/>
              <Annotation Term="OData.Description" String="A sensor for a terminator."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="SystemBoot/Restart"/>
              <Annotation Term="OData.Description" String="A sensor for a system boot or restart event."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Boot Error"/>
              <Annotation Term="OData.Description" String="A sensor for a boot error event."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="BaseOSBoot/InstallationStatus"/>
              <Annotation Term="OData.Description" String="A sensor for a base OS boot or installation status event."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="OS Stop/Shutdown"/>
              <Annotation Term="OData.Description" String="A sensor for an OS stop or shutdown event"/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Slot/Connector"/>
              <Annotation Term="OData.Description" String="A sensor for a slot or connector."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="System ACPI PowerState"/>
              <Annotation Term="OData.Description" String="A sensor for an ACPI power state event."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Watchdog"/>
              <Annotation Term="OData.Description" String="A sensor for a watchdog event."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Platform Alert"/>
              <Annotation Term="OData.Description" String="A sensor for a platform alert event."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Entity Presence"/>
              <Annotation Term="OData.Description" String="A sensor for an entity presence event."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Monitor ASIC/IC"/>
              <Annotation Term="OData.Description" String="A sensor for a monitor ASIC or IC."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="LAN"/>
              <Annotation Term="OData.Description" String="A sensor for a LAN device."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Management Subsystem Health"/>
              <Annotation Term="OData.Description" String="A sensor for a management subsystem health event."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Battery"/>
              <Annotation Term="OData.Description" String="A sensor for a battery."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Session Audit"/>
              <Annotation Term="OData.Description" String="A sensor for a session audit event."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Version Change"/>
              <Annotation Term="OData.Description" String="A sensor for a version change event."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="FRUState"/>
              <Annotation Term="OData.Description" String="A sensor for a FRU state event."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="OEM"/>
              <Annotation Term="OData.Description" String="An OEM defined sensor."/>
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

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_0_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_0_0.LogEntry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_0_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_0_2.LogEntry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_0_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_0_3.LogEntry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_0_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add descriptions to various enum values."/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_0_4.LogEntry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_0_6">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to correct the Description for EntryType.  It was also created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number.  It was also created to clarify the descriptions for many properties."/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_0_5.LogEntry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_0_7">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_0_6.LogEntry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2016.2"/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_0_2.LogEntry">
        <Property Name="EventType" Type="Event.EventType" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This indicates the type of an event recorded in this log."/>
          <Annotation Term="OData.LongDescription" String="If present, this LogEntry records an Event and the value shall indicate the type of event."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Deprecated"/>
                <PropertyValue Property="Version" String="v1_4_0"/>
                <PropertyValue Property="Description" String="This property has been deprecated.  Starting Redfish Spec 1.6 (Event 1.3), subscriptions are based on RegistryId and ResourceType and not EventType."/>
              </Record>
            </Collection>
          </Annotation>
        </Property>
        <Property Name="EventId" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a unique instance identifier of an event."/>
          <Annotation Term="OData.LongDescription" String="If present, this LogEntry records an Event and the value shall indicate a unique identifier for the event, the format of which is implementation dependent."/>
        </Property>
        <Property Name="EventTimestamp" Type="Edm.DateTimeOffset" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is time the event occurred."/>
          <Annotation Term="OData.LongDescription" String="If present, this LogEntry records an Event and the value shall be the time the event occurred."/>
        </Property>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_1_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_1_0.LogEntry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_1_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_1_1.LogEntry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_1_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to change references to EventType to use the unversioned definition.  It was also created to add descriptions to various enum values."/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_1_2.LogEntry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_1_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to correct the Description for EntryType.  It was also created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number.  It was also created to clarify the descriptions for many properties."/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_1_3.LogEntry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_1_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_1_4.LogEntry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_2_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.1"/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_1_2.LogEntry">
        <Property Name="Actions" Type="LogEntry.v1_2_0.Actions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="LogEntry.v1_2_0.OemActions" Nullable="false">
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
    
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_2_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to change references to EventType to use the unversioned definition.  It was also created to add descriptions to various enum values."/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_2_0.LogEntry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_2_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to correct the Description for EntryType.  It was also created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number.  It was also created to clarify the descriptions for many properties."/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_2_1.LogEntry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_2_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_2_2.LogEntry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_3_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.3"/>
      <Annotation Term="OData.Description" String="This version was created to add OEM enumerations for legacy IPMI log implementations."/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_2_1.LogEntry">
        <Property Name="OemLogEntryCode" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="If the LogEntryCode type is OEM, this will contain the OEM-specific entry code."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the OEM specific Log Entry Code type of the Entry.  This property shall only be present if the value of EntryType is SEL and the value of LogEntryCode is OEM."/>
        </Property>
        <Property Name="OemSensorType" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="If the Sensor Type is OEM, this will contain the OEM-specific sensor type."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall represent the OEM specific sensor type of the Entry.  This property shall only be used if the value of EntryType is SEL and the value of SensorType is OEM."/>
        </Property>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_3_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to correct the Description for EntryType.  It was also created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number.  It was also created to clarify the descriptions for many properties."/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_3_0.LogEntry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_3_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_3_1.LogEntry"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_4_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.2"/>
      <Annotation Term="OData.Description" String="This version was created to deprecate EventType and to add EventGroupId in the case the log is used for Events."/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_3_1.LogEntry">
        <Property Name="EventGroupId" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This value is the identifier used to correlate events that came from the same cause."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate that events are related and shall have the same value in the case where multiple Event messages are produced by the same root cause.  Implementations shall use separate values for events with separate root cause.  There shall not be ordering of events implied by the value of this property."/>
        </Property>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogEntry.v1_4_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="LogEntry" BaseType="LogEntry.v1_4_0.LogEntry"/>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_LOG_ENTRY_V1_HPP */
