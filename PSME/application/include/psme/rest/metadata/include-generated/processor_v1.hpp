#ifndef PSME_REST_METADATA_PROCESSOR_V1_HPP
#define PSME_REST_METADATA_PROCESSOR_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Processor_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  Processor  v1.4.0-->
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
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Chassis_v1.xml">
    <edmx:Include Namespace="Chassis"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Assembly_v1.xml">
    <edmx:Include Namespace="Assembly"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ProcessorCollection_v1.xml">
    <edmx:Include Namespace="ProcessorCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ProcessorMetrics_v1.xml">
    <edmx:Include Namespace="ProcessorMetrics"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Endpoint_v1.xml">
    <edmx:Include Namespace="Endpoint"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/AccelerationFunction_v1.xml">
    <edmx:Include Namespace="AccelerationFunction"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/AccelerationFunctionCollection_v1.xml">
    <edmx:Include Namespace="AccelerationFunctionCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/PCIeDevice_v1.xml">
    <edmx:Include Namespace="PCIeDevice"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/PCIeFunction_v1.xml">
    <edmx:Include Namespace="PCIeFunction"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Processor">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="Processor" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="The Processor resource reports information about a single processor contained within a system.  This includes both performance characteristics (clock speed, architecture, core count, etc.) and compatibility (e.g. CPU ID instruction results)."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent a single processor contained within a system."/>
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
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
            <String>/redfish/v1/Systems/{ComputerSystemId}/Processors/{ProcessorId}</String>
            <String>/redfish/v1/Systems/{ComputerSystemId}/Processors/{ProcessorId}/SubProcessors/{ProcessorId2}</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Processors/{ProcessorId}</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Processors/{ProcessorId}/SubProcessors/{ProcessorId2}</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/Processors/{ProcessorId}</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/Processors/{ProcessorId}/SubProcessors/{ProcessorId2}</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Processors/{ProcessorId}</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Processors/{ProcessorId}/SubProcessors/{ProcessorId2}</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/Processors/{ProcessorId}</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/Processors/{ProcessorId}/SubProcessors/{ProcessorId2}</String>
          </Collection>
        </Annotation>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Processor.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="1.0"/>

      <EntityType Name="Processor" BaseType="Processor.Processor">
        <Annotation Term="OData.Description" String="This is the schema definition for the Processor resource.  It represents the properties of a processor attached to a System."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent a single processor contained within a system."/>
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Socket" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The socket or location of the processor."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the string which identifies the physical location or socket of the processor."/>
        </Property>
        <Property Name="ProcessorType" Type="Processor.v1_0_0.ProcessorType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The type of processor."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the string which identifies the type of processor contained in this Socket."/>
        </Property>
        <Property Name="ProcessorArchitecture" Type="Processor.v1_0_0.ProcessorArchitecture">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The architecture of the processor."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the string which identifies the architecture of the processor contained in this Socket."/>
        </Property>
        <Property Name="InstructionSet" Type="Processor.v1_0_0.InstructionSet">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The instruction set of the processor."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the string which identifies the instruction set of the processor contained in this socket."/>
        </Property>
        <Property Name="ProcessorId" Type="Processor.v1_0_0.ProcessorId"  Nullable="false">
          <Annotation Term="OData.Description" String="Identification information for this processor."/>
          <Annotation Term="OData.LongDescription" String="This object shall contain identification information for this processor."/>
        </Property>
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Description" String="This property describes the status and health of the resource and its children."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain any status or health properties of the resource."/>
        </Property>
        <Property Name="Manufacturer" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The processor manufacturer."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain a string which identifies the manufacturer of the processor."/>
        </Property>
        <Property Name="Model" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The product model number of this device."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the model information as provided by the manufacturer of this processor."/>
        </Property>
        <Property Name="MaxSpeedMHz" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The maximum clock speed of the processor."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the maximum rated clock speed of the processor in MHz."/>
          <Annotation Term="Measures.Unit" String="MHz"/>
        </Property>
        <Property Name="TotalCores" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The total number of cores contained in this processor."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the total count of independent processor cores contained within this processor."/>
        </Property>
        <Property Name="TotalThreads" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The total number of execution threads supported by this processor."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the total count of independent execution threads supported by this processor."/>
        </Property>
      </EntityType>

      <ComplexType Name="ProcessorId">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This type describes the Identification information for a processor."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain identification information for a processor."/>
        <Property Name="VendorId" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Vendor Identification for this processor."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the Vendor Identification string information as provided by the manufacturer of this processor."/>
        </Property>
        <Property Name="IdentificationRegisters" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The contents of the Identification Registers (CPUID) for this processor."/>
          <Annotation Term="OData.LongDescription" String="This property shall include the raw CPUID instruction output as provided by the manufacturer of this processor."/>
        </Property>
        <Property Name="EffectiveFamily" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The effective Family for this processor."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the effective Family information as provided by the manufacturer of this processor."/>
        </Property>
        <Property Name="EffectiveModel" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The effective Model for this processor."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the effective Model information as provided by the manufacturer of this processor."/>
        </Property>
        <Property Name="Step" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Step value for this processor."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the Step or revision string information as provided by the manufacturer of this processor."/>
        </Property>
        <Property Name="MicrocodeInfo" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Microcode Information for this processor."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the Microcode Information as provided by the manufacturer of this processor."/>
        </Property>
      </ComplexType>

      <EnumType Name="ProcessorType">
        <Member Name="CPU">
          <Annotation Term="OData.Description" String="A Central Processing Unit."/>
        </Member>
        <Member Name="GPU">
          <Annotation Term="OData.Description" String="A Graphics Processing Unit."/>
        </Member>
        <Member Name="FPGA">
          <Annotation Term="OData.Description" String="A Field Programmable Gate Array."/>
        </Member>
        <Member Name="DSP">
          <Annotation Term="OData.Description" String="A Digital Signal Processor."/>
        </Member>
        <Member Name="Accelerator">
          <Annotation Term="OData.Description" String="An Accelerator."/>
        </Member>
        <Member Name="Core">
          <Annotation Term="OData.Description" String="A Core in a Processor."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="v1_3_0"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="Thread">
          <Annotation Term="OData.Description" String="A Thread in a Processor."/>
          <Annotation Term="Redfish.Revisions">
            <Collection>
              <Record>
                <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                <PropertyValue Property="Version" String="v1_3_0"/>
              </Record>
            </Collection>
          </Annotation>
        </Member>
        <Member Name="OEM">
          <Annotation Term="OData.Description" String="An OEM-defined Processing Unit."/>
        </Member>
      </EnumType>

      <TypeDefinition Name="ProcessorArchitecture" UnderlyingType="Edm.String">
        <Annotation Term="Redfish.Enumeration">
          <Collection>
            <Record>
              <PropertyValue Property="Member" String="x86"/>
              <Annotation Term="OData.Description" String="x86 or x86-64."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="IA-64"/>
              <Annotation Term="OData.Description" String="Intel Itanium."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="ARM"/>
              <Annotation Term="OData.Description" String="ARM."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="MIPS"/>
              <Annotation Term="OData.Description" String="MIPS."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Power"/>
              <Annotation Term="OData.Description" String="Power."/>
              <Annotation Term="Redfish.Revisions">
                <Collection>
                  <Record>
                    <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                    <PropertyValue Property="Version" String="v1_4_0"/>
                  </Record>
                </Collection>
              </Annotation>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="OEM"/>
              <Annotation Term="OData.Description" String="OEM-defined."/>
            </Record>
          </Collection>
        </Annotation>
      </TypeDefinition>

      <TypeDefinition Name="InstructionSet" UnderlyingType="Edm.String">
        <Annotation Term="Redfish.Enumeration">
          <Collection>
            <Record>
              <PropertyValue Property="Member" String="x86"/>
              <Annotation Term="OData.Description" String="x86 32-bit."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="x86-64"/>
              <Annotation Term="OData.Description" String="x86 64-bit."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="IA-64"/>
              <Annotation Term="OData.Description" String="Intel IA-64."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="ARM-A32"/>
              <Annotation Term="OData.Description" String="ARM 32-bit."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="ARM-A64"/>
              <Annotation Term="OData.Description" String="ARM 64-bit."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="MIPS32"/>
              <Annotation Term="OData.Description" String="MIPS 32-bit."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="MIPS64"/>
              <Annotation Term="OData.Description" String="MIPS 64-bit."/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="PowerISA"/>
              <Annotation Term="OData.Description" String="PowerISA-64 or PowerISA-32."/>
              <Annotation Term="Redfish.Revisions">
                <Collection>
                  <Record>
                    <PropertyValue Property="Kind" EnumMember="Redfish.RevisionKind/Added"/>
                    <PropertyValue Property="Version" String="v1_4_0"/>
                  </Record>
                </Collection>
              </Annotation>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="OEM"/>
              <Annotation Term="OData.Description" String="OEM-defined."/>
            </Record>
          </Collection>
        </Annotation>
      </TypeDefinition>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Processor.v1_0_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Processor" BaseType="Processor.v1_0_0.Processor"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Processor.v1_0_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Processor" BaseType="Processor.v1_0_2.Processor"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Processor.v1_0_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Processor" BaseType="Processor.v1_0_3.Processor"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Processor.v1_0_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add Units annotations on the MaxSpeedMHz property.  It was also created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Processor" BaseType="Processor.v1_0_4.Processor"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Processor.v1_0_6">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="Processor" BaseType="Processor.v1_0_5.Processor"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Processor.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.1"/>
      <EntityType Name="Processor" BaseType="Processor.v1_0_4.Processor">
        <Property Name="Links" Type="Processor.v1_1_0.Links" Nullable="false">
          <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
          <Annotation Term="OData.LongDescription" String="The Links property, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        </Property>
        <Property Name="Actions" Type="Processor.v1_1_0.Actions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Links" BaseType="Resource.Links">
        <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
        <Annotation Term="OData.LongDescription" String="This type, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        <NavigationProperty Name="Chassis" Type="Chassis.Chassis" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the Chassis which contains this Processor."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a reference to a resource of type Chassis that represent the physical container associated with this Processor."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="Processor.v1_1_0.OemActions" Nullable="false">
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

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Processor.v1_1_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add Units annotations on the MaxSpeedMHz property.  It was also created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Processor" BaseType="Processor.v1_1_0.Processor"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Processor.v1_1_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="Processor" BaseType="Processor.v1_1_1.Processor"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Processor.v1_2_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.3"/>
      <EntityType Name="Processor" BaseType="Processor.v1_1_0.Processor">
        <Property Name="Location" Type="Resource.Location" Nullable="false">
          <Annotation Term="OData.Description" String="The Location of the processor."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain location information of the associated processor."/>
        </Property>
        <NavigationProperty Name="Assembly" Type="Assembly.Assembly" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the Assembly resource associated with this processor."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a link to a resource of type Assembly."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Processor.v1_2_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add Units annotations on the MaxSpeedMHz property.  It was also created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Processor" BaseType="Processor.v1_2_0.Processor"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Processor.v1_2_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="Processor" BaseType="Processor.v1_2_1.Processor"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Processor.v1_3_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.1"/>
      <EntityType Name="Processor" BaseType="Processor.v1_2_0.Processor">
        <NavigationProperty Name="SubProcessors" Type="ProcessorCollection.ProcessorCollection" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the collection of Sub-Processors associated with this system, such as cores or threads that are part of a processor."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a link to a collection of type ProcessorCollection."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Processor.v1_3_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add Units annotations on the MaxSpeedMHz property.  It was also created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="Processor" BaseType="Processor.v1_3_0.Processor"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Processor.v1_3_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to make use of the new Revisions annotation."/>
      <EntityType Name="Processor" BaseType="Processor.v1_3_1.Processor"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Processor.v1_4_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.3"/>
      <Annotation Term="OData.Description" String="This version was created to add TDPWatts and MaxTDPWatts.  It was also created to add Power architecture to ProcessorArchitecture and PowerISA to InstructionSet."/>

      <EntityType Name="Processor" BaseType="Processor.v1_3_2.Processor">
        <Property Name="TDPWatts" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The nominal Thermal Design Power (TDP) in watts."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the nominal Thermal Design Power (TDP) in watts."/>
          <Annotation Term="Measures.Unit" String="W"/>
        </Property>
        <Property Name="MaxTDPWatts" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The maximum Thermal Design Power (TDP) in watts."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the maximum Thermal Design Power (TDP) in watts."/>
          <Annotation Term="Measures.Unit" String="W"/>
        </Property>
        <NavigationProperty Name="Metrics" Type="ProcessorMetrics.ProcessorMetrics">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the Metrics associated with this Processor."/>
          <Annotation Term="OData.LongDescription" String="This property shall be a reference to the Metrics associated with this Processor."/>
        </NavigationProperty>
        <Property Name="UUID" Type="Resource.UUID">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The universal unique identifier (UUID) for this processor."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be used to contain a universal unique identifier number for the processor.  RFC4122 describes methods that can be used to create the value.  The value should be considered to be opaque.  Client software should only treat the overall value as a universally unique identifier and should not interpret any sub-fields within the UUID."/>
        </Property>
        <Property Name="ProcessorMemory" Type="Collection(Processor.v1_4_0.ProcessorMemory)" Nullable="false">
          <Annotation Term="OData.Description" String="The memory directly attached or integrated witin this Procesor."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the memory directly attached or integrated witin this Processor."/>
        </Property>
        <Property Name="FPGA" Type="Processor.v1_4_0.FPGA" Nullable="true">
          <Annotation Term="OData.Description" String="The properties specific for Processors of type FPGA."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an object containing properties specific for Processors of type FPGA."/>
        </Property>
        <NavigationProperty Name="AccelerationFunctions" Type="AccelerationFunctionCollection.AccelerationFunctionCollection" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the collection of Acceleration Functions associated with this Processor."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a link to a collection of type AccelerationFunctionCollection."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

      <ComplexType Name="Links" BaseType="Processor.v1_1_0.Links">
        <NavigationProperty Name="Endpoints" Type="Collection(Endpoint.Endpoint)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the endpoints that connect to this processor."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of references of type Endpoint that represent Endpoints accociated with this Processor."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="ConnectedProcessors" Type="Collection(Processor.Processor)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the processors directly connected to this processor."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of references of type Processor that are directly connected to this Processor."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="PCIeDevice" Type="PCIeDevice.PCIeDevice">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the PCIeDevice associated with this Processor."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a reference of type PCIeDevice that represents the PCI-e Device associated with this Processor."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="PCIeFunctions" Type="Collection(PCIeFunction.PCIeFunction)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="An array of references to the PCIeFunctions associated with this Processor."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of references of type PCIeFunction that represent the PCI-e Functions associated with this Processor."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="ProcessorMemory">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This type describes the memory directly attached or integrated within a processor."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain information about memory directly attached or integratied within a processor."/>
        <Property Name="IntegratedMemory" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This indicates whether this memory is integrated within the Processor."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a boolean indicating whether this memory is integrated within the Porcessor.  Otherwise it is discrete memory attached to the Processor."/>
        </Property>
        <Property Name="MemoryType" Type="Processor.v1_4_0.ProcessorMemoryType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The type of memory used by this processor."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a type of the processor memory type."/>
        </Property>
        <Property Name="CapacityMiB" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The memory capacity in MiB."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the memory capacity in MiB."/>
          <Annotation Term="Measures.Unit" String="MiBy"/>
        </Property>
        <Property Name="SpeedMHz" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The operating speed of the memory in MHz."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the operating speed of the memory in MHz."/>
        </Property>
      </ComplexType>

      <EnumType Name="ProcessorMemoryType">
        <Member Name="L1Cache">
          <Annotation Term="OData.Description" String="L1 cache."/>
        </Member>
        <Member Name="L2Cache">
          <Annotation Term="OData.Description" String="L2 cache."/>
        </Member>
        <Member Name="L3Cache">
          <Annotation Term="OData.Description" String="L3 cache."/>
        </Member>
        <Member Name="L4Cache">
          <Annotation Term="OData.Description" String="L4 cache."/>
        </Member>
        <Member Name="L5Cache">
          <Annotation Term="OData.Description" String="L5 cache."/>
        </Member>
        <Member Name="L6Cache">
          <Annotation Term="OData.Description" String="L6 cache."/>
        </Member>
        <Member Name="L7Cache">
          <Annotation Term="OData.Description" String="L7 cache."/>
        </Member>
        <Member Name="HBM1">
          <Annotation Term="OData.Description" String="High Bandwidth Memory."/>
        </Member>
        <Member Name="HBM2">
          <Annotation Term="OData.Description" String="The second generation of High Bandwidth Memory."/>
        </Member>
        <Member Name="HBM3">
          <Annotation Term="OData.Description" String="The third generation of High Bandwidth Memory."/>
        </Member>
        <Member Name="SGRAM">
          <Annotation Term="OData.Description" String="Synchronous graphics RAM."/>
        </Member>
        <Member Name="GDDR">
          <Annotation Term="OData.Description" String="Synchronous graphics random-access memory."/>
        </Member>
        <Member Name="GDDR2">
          <Annotation Term="OData.Description" String="Double data rate type two synchronous graphics random-access memory."/>
        </Member>
        <Member Name="GDDR3">
          <Annotation Term="OData.Description" String="Double data rate type three synchronous graphics random-access memory."/>
        </Member>
        <Member Name="GDDR4">
          <Annotation Term="OData.Description" String="Double data rate type four synchronous graphics random-access memory."/>
        </Member>
        <Member Name="GDDR5">
          <Annotation Term="OData.Description" String="Double data rate type five synchronous graphics random-access memory."/>
        </Member>
        <Member Name="GDDR5X">
          <Annotation Term="OData.Description" String="Double data rate type five synchronous graphics random-access memory."/>
        </Member>
        <Member Name="GDDR6">
          <Annotation Term="OData.Description" String="Double data rate type five synchronous graphics random-access memory."/>
        </Member>
        <Member Name="DDR">
          <Annotation Term="OData.Description" String="Double data rate synchronous dynamic random-access memory."/>
        </Member>
        <Member Name="DDR2">
          <Annotation Term="OData.Description" String="Double data rate type two synchronous dynamic random-access memory."/>
        </Member>
        <Member Name="DDR3">
          <Annotation Term="OData.Description" String="Double data rate type three synchronous dynamic random-access memory."/>
        </Member>
        <Member Name="DDR4">
          <Annotation Term="OData.Description" String="Double data rate type four synchronous dynamic random-access memory."/>
        </Member>
        <Member Name="DDR5">
          <Annotation Term="OData.Description" String="Double data rate type five synchronous dynamic random-access memory."/>
        </Member>
        <Member Name="SDRAM">
          <Annotation Term="OData.Description" String="Synchronous dynamic random-access memory."/>
        </Member>
        <Member Name="SRAM">
          <Annotation Term="OData.Description" String="Static random-access memory."/>
        </Member>
        <Member Name="Flash">
          <Annotation Term="OData.Description" String="Flash memory."/>
        </Member>
        <Member Name="OEM">
          <Annotation Term="OData.Description" String="OEM-defined."/>
        </Member>
      </EnumType>

      <ComplexType Name="FPGA">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The properties of the FPGA device."/>
        <Annotation Term="OData.LongDescription" String="This object shall contain the properties of the FPGA device represented by a Processor."/>
        <Property Name="FpgaType" Type="Processor.v1_4_0.FpgaType" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The FPGA type."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a type of the FPGA device."/>
        </Property>
        <Property Name="Model" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The FPGA model."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a model of the FPGA device."/>
        </Property>
        <Property Name="FirmwareId" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The FPGA firmware identifier."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain a string decsribing the FPGA firmware identifier."/>
        </Property>
        <Property Name="FirmwareManufacturer" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The FPGA firmware manufacturer."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain a string decsribing the FPGA firmware manufacturer."/>
        </Property>
        <Property Name="FirmwareVersion" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The FPGA firmware version."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain a string decsribing the FPGA firmware version."/>
        </Property>
        <Property Name="HostInterface" Type="Processor.v1_4_0.FpgaInterface" Nullable="false">
          <Annotation Term="OData.Description" String="The FPGA interface to the host."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an object that describes the connectivity to the host for system software to use."/>
        </Property>
        <Property Name="ExternalInterfaces" Type="Collection(Processor.v1_4_0.FpgaInterface)" Nullable="false">
          <Annotation Term="OData.Description" String="An array of the FPGA external interfaces."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of objects that describe the external connectivity of the FPGA."/>
        </Property>
        <Property Name="PCIeVirtualFunctions" Type="Edm.Int64" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The number of the PCIe Virtual Functions."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an integer that describes the number of PCIe Virtual Functions configured within the FPGA."/>
        </Property>
        <Property Name="ProgrammableFromHost" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This flag indicates if the FPGA firmware can be reprogrammed from the host using system software."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate whether the FPGA firmware can be reprogrammed from the host using system software.  If set to false, system software shall not be able to program the FPGA firmware from the host interface.  In either state, a management controller may be able to program the FPGA firmware using the sideband interface."/>
        </Property>
        <Property Name="ReconfigurationSlots" Type="Collection(Processor.v1_4_0.FpgaReconfigurationSlot)" Nullable="false">
          <Annotation Term="OData.Description" String="An array of the FPGA reconfiguration slots.  A reconfiguration slot is used by an FPGA to contain an acceleration function that can change as the FPGA is being provisioned."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an array of the structures describing the FPGA reconfiguration slots that can be programmed with the acceleration functions."/>
        </Property>
        <Property Name="Oem" Type="Resource.Oem" Nullable="false">
          <Annotation Term="OData.Description" String="Oem extension object."/>
          <Annotation Term="OData.LongDescription" String="This object represents the Oem property.  All values for resources described by this schema shall comply to the requirements as described in the Redfish specification."/>
        </Property>
      </ComplexType>

      <ComplexType Name="FpgaReconfigurationSlot">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This type describes the FPGA reconfiguration slot.  A reconfiguration slot is used by an FPGA to contain an acceleration function that can change as the FPGA is being provisioned."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain information about the FPGA reconfiguration slot."/>
        <Property Name="SlotId" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The FPGA reconfiguration slot identifier."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the FPGA reconfiguration slot identifier."/>
        </Property>
        <Property Name="UUID" Type="Resource.UUID">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The universal unique identifier (UUID) for this reconfiguration slot."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be used to contain a universal unique identifier number for the reconfiguration slot."/>
        </Property>
        <Property Name="ProgrammableFromHost" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This flag indicates if the reconfiguration slot can be reprogrammed from the host using system software."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall indicate whether the reconfiguration slot can be reprogrammed from the host using system software.  If set to false, system software shall not be able to program the reconfiguration slot from the host interface.  In either state, a management controller may be able to program the reconfiguration slot using the sideband interface."/>
        </Property>
        <NavigationProperty Name="AccelerationFunction" Type="AccelerationFunction.AccelerationFunction">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A link to the Acceleration Function provided by the code programmed into a reconfiguration slot."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a reference to the acceleration function resources provided by the code programmed into a reconfiguration slot and shall reference a resource of type AccelerationFunction."/>
        </NavigationProperty>
      </ComplexType>

      <EnumType Name="FpgaType">
        <Member Name="Integrated">
          <Annotation Term="OData.Description" String="The FPGA device integrasted with other porcessor in the single chip."/>
        </Member>
        <Member Name="Discrete">
          <Annotation Term="OData.Description" String="The discrete FPGA device."/>
        </Member>
      </EnumType>

      <ComplexType Name="FpgaInterface">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This type describes an interface to the FPGA."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain information about the interface to the FPGA."/>
        <Property Name="InterfaceType" Type="Processor.v1_4_0.FpgaInterfaceType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The FPGA interface type."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an enum that describes the type of interface to the FPGA."/>
        </Property>
        <Property Name="PCIe" Type="PCIeDevice.PCIeInterface">
          <Annotation Term="OData.Description" String="Describes the PCI-e related information about this FPGA interface."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an object the describes the PCI-e related information about this FPGA interface."/>
        </Property>
        <Property Name="Ethernet" Type="Processor.v1_4_0.EthernetInterface">
          <Annotation Term="OData.Description" String="Describes the Ethernet related information about this FPGA interface."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an object the describes the Ethernet related information about this FPGA interface."/>
        </Property>
      </ComplexType>

      <ComplexType Name="EthernetInterface">
        <Annotation Term="OData.Description" String="This is the definition for an Ethernet Interface object."/>
        <Annotation Term="OData.LongDescription" String="These properties shall be the definition for an Ethernet Interface for a Redfish implementation."/>
        <Property Name="Oem" Type="Resource.Oem" Nullable="false">
          <Annotation Term="OData.Description" String="Oem extension object."/>
          <Annotation Term="OData.LongDescription" String="This object represents the Oem property.  All values for resources described by this schema shall comply to the requirements as described in the Redfish specification."/>
        </Property>
        <Property Name="MaxSpeedMbps" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The maximum speed supported by this interface."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the maximum speed supported by this interface."/>
          <Annotation Term="Measures.Unit" String="Mbit/s"/>
        </Property>
        <Property Name="MaxLanes" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the number of lanes supported by this interface."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the maximum number of lanes supported by this interface."/>
        </Property>
      </ComplexType>

      <EnumType Name="FpgaInterfaceType">
        <Member Name="QPI">
          <Annotation Term="OData.Description" String="The Intel QuickPath Interconnect."/>
        </Member>
        <Member Name="UPI">
          <Annotation Term="OData.Description" String="The Intel UltraPath Interconnect."/>
        </Member>
        <Member Name="PCIe">
          <Annotation Term="OData.Description" String="A PCI Express interface."/>
        </Member>
        <Member Name="Ethernet">
          <Annotation Term="OData.Description" String="An Ethernet interface."/>
        </Member>
        <Member Name="OEM">
          <Annotation Term="OData.Description" String="An OEM defined interface."/>
        </Member>
      </EnumType>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_PROCESSOR_V1_HPP */
