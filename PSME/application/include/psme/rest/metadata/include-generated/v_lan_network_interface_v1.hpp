#ifndef PSME_REST_METADATA_V_LAN_NETWORK_INTERFACE_V1_HPP
#define PSME_REST_METADATA_V_LAN_NETWORK_INTERFACE_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string VLanNetworkInterface_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  VLanNetworkInterface  v1.1.2-->
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
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
    <edmx:Include Namespace="Validation.v1_0_0" Alias="Validation"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VLanNetworkInterface">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <EntityType Name="VLanNetworkInterface" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="This resource contains information for a Virtual LAN (VLAN) network instance available on a manager, system or other device."/>
        <Annotation Term="Capabilities.InsertRestrictions">
          <Record>
            <PropertyValue Property="Insertable" Bool="false"/>
          </Record>
        </Annotation>
        <Annotation Term="Capabilities.UpdateRestrictions">
          <Record>
            <PropertyValue Property="Updatable" Bool="true"/>
            <Annotation Term="OData.Description" String="VLan Network Interfaces can be updated to change the VLan ID and to enable or disable it."/>
          </Record>
        </Annotation>
        <Annotation Term="Capabilities.DeleteRestrictions">
          <Record>
            <PropertyValue Property="Deletable" Bool="true"/>
            <Annotation Term="OData.Description" String="VLan Network Interface can be deleted in some implementations, though others may keep a fixed number in the collection and thus not allow deletion."/>
          </Record>
        </Annotation>
        <Annotation Term="Redfish.Uris">
          <Collection>
            <String>/redfish/v1/Chassis/{ChassisId}/NetworkAdapters/{NetworkAdapterId}/NetworkDeviceFunctions/{NetworkDeviceFunctionId}/Ethernet/VLANs/{VLanNetworkInterfaceId}</String>
            <String>/redfish/v1/Managers/{ManagerId}/EthernetInterfaces/{EthernetInterfaceId}/VLANs/{VLanNetworkInterfaceId}</String>
            <String>/redfish/v1/Systems/{ComputerSystemId}/EthernetInterfaces/{EthernetInterfaceId}/VLANs/{VLanNetworkInterfaceId}</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/EthernetInterfaces/{EthernetInterfaceId}/VLANs/{VLanNetworkInterfaceId}</String>
            <String>/redfish/v1/CompositionService/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/EthernetInterfaces/{EthernetInterfaceId}/VLANs/{VLanNetworkInterfaceId}</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/EthernetInterfaces/{EthernetInterfaceId}/VLANs/{VLanNetworkInterfaceId}</String>
            <String>/redfish/v1/ResourceBlocks/{ResourceBlockId}/Systems/{ComputerSystemId}/EthernetInterfaces/{EthernetInterfaceId}/VLANs/{VLanNetworkInterfaceId}</String>
          </Collection>
        </Annotation>
      </EntityType>

      <ComplexType Name="VLAN" Abstract="true">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This type describes the attributes of a Virtual LAN."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain any attributes of a Virtual LAN."/>
      </ComplexType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VLanNetworkInterface.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="1.0"/>

      <EntityType Name="VLanNetworkInterface" BaseType="VLanNetworkInterface.VLanNetworkInterface">
        <Annotation Term="OData.Description" String="This resource describes the attributes of a Virtual LAN."/>
        <Annotation Term="OData.LongDescription" String="This resource shall contain any attributes of a Virtual LAN."/>
        <Property Name="VLANEnable" Type="Edm.Boolean">
          <Annotation Term="Redfish.RequiredOnCreate"/>
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This indicates if this VLAN is enabled."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be used to indicate if this VLAN is enabled for this interface."/>
        </Property>
        <Property Name="VLANId" Type="VLanNetworkInterface.v1_0_0.VLANId">
          <Annotation Term="Redfish.RequiredOnCreate"/>
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This indicates the VLAN identifier for this VLAN."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be used to indicate the VLAN identifier for this VLAN."/>
        </Property>
      </EntityType>

      <ComplexType Name="VLAN" BaseType="VLanNetworkInterface.VLAN">
        <Property Name="VLANEnable" Type="Edm.Boolean">
          <Annotation Term="Redfish.RequiredOnCreate"/>
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This indicates if this VLAN is enabled."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be used to indicate if this VLAN is enabled for this interface."/>
        </Property>
        <Property Name="VLANId" Type="VLanNetworkInterface.v1_0_0.VLANId">
          <Annotation Term="Redfish.RequiredOnCreate"/>
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This indicates the VLAN identifier for this VLAN."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be used to indicate the VLAN identifier for this VLAN."/>
        </Property>
      </ComplexType>

      <TypeDefinition Name="VLANId" UnderlyingType="Edm.Int64">
        <Annotation Term="Validation.Minimum" Int="0"/>
        <Annotation Term="Validation.Maximum" Int="4094"/>
      </TypeDefinition>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VLanNetworkInterface.v1_0_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="VLanNetworkInterface" BaseType="VLanNetworkInterface.v1_0_0.VLanNetworkInterface"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VLanNetworkInterface.v1_0_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="VLanNetworkInterface" BaseType="VLanNetworkInterface.v1_0_1.VLanNetworkInterface"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VLanNetworkInterface.v1_0_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add explicit Permissions annotations to all properties for clarity."/>
      <EntityType Name="VLanNetworkInterface" BaseType="VLanNetworkInterface.v1_0_2.VLanNetworkInterface"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VLanNetworkInterface.v1_0_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="VLanNetworkInterface" BaseType="VLanNetworkInterface.v1_0_3.VLanNetworkInterface"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VLanNetworkInterface.v1_0_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add an abstract base type for VLAN."/>
      <EntityType Name="VLanNetworkInterface" BaseType="VLanNetworkInterface.v1_0_4.VLanNetworkInterface"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VLanNetworkInterface.v1_0_6">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="VLanNetworkInterface" BaseType="VLanNetworkInterface.v1_0_5.VLanNetworkInterface"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VLanNetworkInterface.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2017.1"/>
      <EntityType Name="VLanNetworkInterface" BaseType="VLanNetworkInterface.v1_0_4.VLanNetworkInterface">
        <Property Name="Actions" Type="VLanNetworkInterface.v1_1_0.Actions" Nullable="false">
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription" String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="VLanNetworkInterface.v1_1_0.OemActions" Nullable="false">
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

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VLanNetworkInterface.v1_1_1">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add an abstract base type for VLAN."/>
      <EntityType Name="VLanNetworkInterface" BaseType="VLanNetworkInterface.v1_1_0.VLanNetworkInterface"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VLanNetworkInterface.v1_1_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="VLanNetworkInterface" BaseType="VLanNetworkInterface.v1_1_1.VLanNetworkInterface"/>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_V_LAN_NETWORK_INTERFACE_V1_HPP */
