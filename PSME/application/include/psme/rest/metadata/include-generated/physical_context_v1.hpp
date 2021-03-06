#ifndef PSME_REST_METADATA_PHYSICAL_CONTEXT_V1_HPP
#define PSME_REST_METADATA_PHYSICAL_CONTEXT_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string PhysicalContext_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  PhysicalContext-->
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
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="PhysicalContext">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="1.0"/>

      <EnumType Name="PhysicalContext">
        <Member Name="Room">
          <Annotation Term="OData.Description" String="The room."/>
        </Member>
        <Member Name="Intake">
          <Annotation Term="OData.Description" String="The air intake point(s) or region of the chassis."/>
        </Member>
        <Member Name="Exhaust">
          <Annotation Term="OData.Description" String="The air exhaust point(s) or region of the chassis."/>
        </Member>
        <Member Name="LiquidInlet">
          <Annotation Term="OData.Description" String="The liquid inlet point of the chassis."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2017.3"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="LiquidOutlet">
          <Annotation Term="OData.Description" String="The liquid outlet point of the chassis."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2017.3"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="Front">
          <Annotation Term="OData.Description" String="The front of the chassis."/>
        </Member>
        <Member Name="Back">
          <Annotation Term="OData.Description" String="The back of the chassis."/>
        </Member>
        <Member Name="Upper">
          <Annotation Term="OData.Description" String="The upper portion of the chassis."/>
        </Member>
        <Member Name="Lower">
          <Annotation Term="OData.Description" String="The lower portion of the chassis."/>
        </Member>
        <Member Name="CPU">
          <Annotation Term="OData.Description" String="A Processor (CPU)."/>
        </Member>
        <Member Name="CPUSubsystem">
          <Annotation Term="OData.Description" String="The entire Processor (CPU) subsystem."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2018.3"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="GPU">
          <Annotation Term="OData.Description" String="A Graphics Processor (GPU)."/>
        </Member>
        <Member Name="GPUSubsystem">
          <Annotation Term="OData.Description" String="The entire Graphics Processor (GPU) subsystem."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2018.3"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="FPGA">
          <Annotation Term="OData.Description" String="A Field Programmable Gate Array (FPGA)."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2018.3"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="Accelerator">
          <Annotation Term="OData.Description" String="An Accelerator."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2018.3"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="ASIC">
          <Annotation Term="OData.Description" String="An ASIC device, such as networking chip or a chipset component."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2017.3"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="Backplane">
          <Annotation Term="OData.Description" String="A backplane within the chassis."/>
        </Member>
        <Member Name="SystemBoard">
          <Annotation Term="OData.Description" String="The system board (PCB)."/>
        </Member>
        <Member Name="PowerSupply">
          <Annotation Term="OData.Description" String="A power supply."/>
        </Member>
        <Member Name="VoltageRegulator">
          <Annotation Term="OData.Description" String="A voltage regulator device."/>
        </Member>
        <Member Name="StorageDevice">
          <Annotation Term="OData.Description" String="A storage device."/>
        </Member>
        <Member Name="NetworkingDevice">
          <Annotation Term="OData.Description" String="A networking device."/>
        </Member>
        <Member Name="ComputeBay">
          <Annotation Term="OData.Description" String="Within a compute bay."/>
        </Member>
        <Member Name="StorageBay">
          <Annotation Term="OData.Description" String="Within a storage bay."/>
        </Member>
        <Member Name="NetworkBay">
          <Annotation Term="OData.Description" String="Within a networking bay."/>
        </Member>
        <Member Name="ExpansionBay">
          <Annotation Term="OData.Description" String="Within an expansion bay."/>
        </Member>
        <Member Name="PowerSupplyBay">
          <Annotation Term="OData.Description" String="Within a power supply bay."/>
        </Member>
        <Member Name="Memory">
          <Annotation Term="OData.Description" String="A memory device."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2017.1"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="MemorySubsystem">
          <Annotation Term="OData.Description" String="The entire Memory subsystem."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2018.3"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="Chassis">
          <Annotation Term="OData.Description" String="The entire chassis."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2017.2"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="Fan">
          <Annotation Term="OData.Description" String="A fan."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2017.2"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="CoolingSubsystem">
          <Annotation Term="OData.Description" String="The entire cooling (air and liquid) subsystem."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2018.3"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="Motor">
          <Annotation Term="OData.Description" String="A motor."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2018.3"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="Transformer">
          <Annotation Term="OData.Description" String="A Transformer."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2018.3"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="ACUtilityInput">
          <Annotation Term="OData.Description" String="An AC Utility Input."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2018.3"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="ACStaticBypassInput">
          <Annotation Term="OData.Description" String="An AC Static Bypass Input."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2018.3"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="ACMaintenanceBypassInput">
          <Annotation Term="OData.Description" String="An AC Maintenance Bypass Input."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2018.3"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="DCBus">
          <Annotation Term="OData.Description" String="A DC Bus."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2018.3"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="ACOutput">
          <Annotation Term="OData.Description" String="An AC Output."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2018.3"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="ACInput">
          <Annotation Term="OData.Description" String="An AC Input."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="2018.3"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
      </EnumType>

      <EnumType Name="PhysicalSubContext">
        <Annotation Term="Redfish.Revisions">
          <Collection>
            <Record>
              <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
              <PropertyValue Property="Version" String="2018.3"/>
            </Record>
          </Collection>
        </Annotation>
        <Member Name="Input">
          <Annotation Term="OData.Description" String="The input."/>
        </Member>
        <Member Name="Output">
          <Annotation Term="OData.Description" String="The output."/>
        </Member>
      </EnumType>

    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_PHYSICAL_CONTEXT_V1_HPP */
