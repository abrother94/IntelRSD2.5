#ifndef PSME_REST_METADATA_ETHERNET_SWITCH_PORT_V1_HPP
#define PSME_REST_METADATA_ETHERNET_SWITCH_PORT_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string EthernetSwitchPort_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?><!-- Copyright 2014-2015 Distributed Management Task Force, Inc. (DMTF). All rights reserved.-->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
    <edmx:Include Namespace="Validation.v1_0_0" Alias="Validation"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Manager_v1.xml">
    <edmx:Include Namespace="Manager.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Chassis_v1.xml">
    <edmx:Include Namespace="Chassis.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/VLanNetworkInterfaceCollection_v1.xml">
    <edmx:Include Namespace="VLanNetworkInterfaceCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/VLanNetworkInterface_v1.xml">
    <edmx:Include Namespace="VLanNetworkInterface.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/EthernetSwitch_v1.xml">
    <edmx:Include Namespace="EthernetSwitch.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/EthernetInterface_v1.xml">
    <edmx:Include Namespace="EthernetInterface.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/IPAddresses_v1.xml">
    <edmx:Include Namespace="IPAddresses.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/EthernetSwitchACL_v1.xml">
    <edmx:Include Namespace="EthernetSwitchACL.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/EthernetSwitchStaticMACCollection_v1.xml">
    <edmx:Include Namespace="EthernetSwitchStaticMACCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/EthernetSwitchPortMetrics_v1.xml">
    <edmx:Include Namespace="EthernetSwitchPortMetrics"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/EthernetInterface_v1.xml">
    <edmx:Include Namespace="EthernetInterface"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="EthernetSwitchPort">

      <EntityType Name="EthernetSwitchPort" BaseType="Resource.v1_0_0.Resource">
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="EthernetSwitchPort.v1_0_0">

      <EntityType Name="EthernetSwitchPort" BaseType="EthernetSwitchPort.EthernetSwitchPort">
        <Property Name="PortId" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Switch port unique identifier."/>
          <Annotation Term="OData.LongDescription" String="Switch port unique identifier."/>
        </Property>
        <Property Name="LinkType" Type="EthernetSwitchPort.v1_0_0.LinkType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Type of port link."/>
          <Annotation Term="OData.LongDescription" String="Type of port link."/>
        </Property>
        <Property Name="OperationalState" Type="EthernetSwitchPort.v1_0_0.OperationalState">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Port link operational state."/>
          <Annotation Term="OData.LongDescription" String="Port link operational state."/>
        </Property>
        <Property Name="AdministrativeState" Type="EthernetSwitchPort.v1_0_0.AdministrativeState">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Port link state forced by user."/>
          <Annotation Term="OData.LongDescription" String="Port link state forced by user."/>
        </Property>
        <Property Name="LinkSpeedMbps" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Port speed."/>
          <Annotation Term="OData.LongDescription" String="Port speed."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="NeighborInfo" Type="EthernetSwitchPort.v1_0_0.NeighborInfo">
          <Annotation Term="OData.Description"
                      String="For Upstream port type this property provide information about neighbor switch (and switch port if available) connected to this port"/>
          <Annotation Term="OData.LongDescription"
                      String="For Upstream port type this property provide information about neighbor switch (and switch port if available) connected to this port"/>
        </Property>
        <Property Name="NeighborMAC" Type="EthernetInterface.v1_0_0.MACAddress">
          <Annotation Term="OData.Description"
                      String="For Downstream port type this property provide MAC address of NIC connected to this port."/>
          <Annotation Term="OData.LongDescription"
                      String="For Downstream port type this property provide MAC address of NIC connected to this port."/>
        </Property>
        <Property Name="FrameSize" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="MAC frame size in bytes."/>
          <Annotation Term="OData.LongDescription" String="MAC frame size in bytes."/>
          <Annotation Term="Validation.Minimum" Int="68"/>
        </Property>
        <Property Name="Autosense" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="Indicates if the speed and duplex is automatically configured by the NIC"/>
          <Annotation Term="OData.LongDescription"
                      String="Indicates if the speed and duplex is automatically configured by the NIC"/>
        </Property>
        <Property Name="FullDuplex" Type="Edm.Boolean">
          <Annotation Term="OData.Description" String="Indicates if port is in Full Duplex mode or not."/>
          <Annotation Term="OData.LongDescription" String="Indicates if port is in Full Duplex mode or not."/>
        </Property>
        <Property Name="MACAddress" Type="EthernetInterface.v1_0_0.MACAddress">
          <Annotation Term="OData.Description" String="MAC address of port."/>
          <Annotation Term="OData.LongDescription" String="MAC address of port."/>
        </Property>
        <Property Name="IPv4Addresses" Type="Collection(IPAddresses.v1_0_0.IPv4Address)" Nullable="false">
          <Annotation Term="OData.Description" String="Array of following IPv4 address."/>
          <Annotation Term="OData.LongDescription" String="Array of following IPv4 address."/>
        </Property>
        <Property Name="IPv6Addresses" Type="Collection(IPAddresses.v1_0_0.IPv6Address)" Nullable="false">
          <Annotation Term="OData.Description" String="Array of following IPv6 address."/>
          <Annotation Term="OData.LongDescription" String="Array of following IPv6 address."/>
        </Property>
        <Property Name="PortClass" Type="EthernetSwitchPort.v1_0_0.PortClass">
          <Annotation Term="OData.Description" String="Port class."/>
          <Annotation Term="OData.LongDescription" String="Port class."/>
        </Property>
        <Property Name="PortMode" Type="EthernetSwitchPort.v1_0_0.PortMode">
          <Annotation Term="OData.Description"
                      String="Port working mode. The value shall correspond to the port class (especially to the logical port definition)."/>
          <Annotation Term="OData.LongDescription"
                      String="Port working mode. The value shall correspond to the port class (especially to the logical port definition)."/>
        </Property>
        <Property Name="PortType" Type="EthernetSwitchPort.v1_0_0.PortType">
          <Annotation Term="OData.Description" String="PortType."/>
          <Annotation Term="OData.LongDescription" String="PortType."/>
        </Property>

        <Property Name="Status" Type="Resource.Status">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
        </Property>

        <NavigationProperty Name="VLANs" Type="VLanNetworkInterfaceCollection.VLanNetworkInterfaceCollection"
                            ContainsTarget="true">
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="StaticMACs" Type="EthernetSwitchStaticMACCollection.EthernetSwitchStaticMACCollection"
                            ContainsTarget="true">
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>

        <Property Name="Links" Type="EthernetSwitchPort.v1_0_0.Links" Nullable="false"/>
      </EntityType>

      <EnumType Name="LinkType">
        <Member Name="Ethernet"/>
        <Member Name="PCIe"/>
      </EnumType>

      <EnumType Name="OperationalState">
        <Member Name="Up">
          <Annotation Term="OData.Description" String="Port link operational state is up."/>
        </Member>
        <Member Name="Down">
          <Annotation Term="OData.Description" String="Port link operational state is down."/>
        </Member>
      </EnumType>

      <EnumType Name="AdministrativeState">
        <Member Name="Up">
          <Annotation Term="OData.Description" String="Port link state forced by user is up."/>
        </Member>
        <Member Name="Down">
          <Annotation Term="OData.Description" String="Port link state forced by user is down."/>
        </Member>
      </EnumType>

      <EnumType Name="PortClass">
        <Member Name="Physical">
          <Annotation Term="OData.Description" String="Port class is physical."/>
        </Member>
        <Member Name="Logical">
          <Annotation Term="OData.Description" String="Port class is logical."/>
        </Member>
        <Member Name="Reserved">
          <Annotation Term="OData.Description" String="Port class is reserved."/>
        </Member>
      </EnumType>

      <EnumType Name="PortMode">
        <Member Name="LinkAggregationStatic">
          <Annotation Term="OData.Description" String="Port working mode is Link Aggregation Static."/>
        </Member>
        <Member Name="LinkAggregationDynamic">
          <Annotation Term="OData.Description" String="Port working mode is Link Aggregation Dynamic."/>
        </Member>
        <Member Name="Unknown">
          <Annotation Term="OData.Description" String="Port working mode is unknown."/>
        </Member>
      </EnumType>

      <EnumType Name="PortType">
        <Member Name="Upstream"/>
        <Member Name="Downstream"/>
        <Member Name="MeshPort"/>
        <Member Name="Unknown"/>
      </EnumType>

      <ComplexType Name="NeighborInfo">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="SwitchId" Type="Edm.String"/>
        <Property Name="PortId" Type="Edm.String"/>
        <Property Name="CableId" Type="Edm.String"/>
      </ComplexType>

      <ComplexType Name="Links" BaseType="Resource.Links">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <NavigationProperty Name="PrimaryVLAN" Type="VLanNetworkInterface.v1_0_0.VLanNetworkInterface">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Switch" Type="EthernetSwitch.v1_0_0.EthernetSwitch">
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="MemberOfPort" Type="EthernetSwitchPort.v1_0_0.EthernetSwitchPort">
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="PortMembers" Type="Collection(EthernetSwitchPort.v1_0_0.EthernetSwitchPort)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="ActiveACLs" Type="Collection(EthernetSwitchACL.v1_0_0.EthernetSwitchACL)">
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>
    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="EthernetSwitchPort.v1_1_0">
      <EntityType Name="EthernetSwitchPort" BaseType="EthernetSwitchPort.v1_0_0.EthernetSwitchPort">
        <NavigationProperty Name="Metrics" Type="EthernetSwitchPortMetrics.EthernetSwitchPortMetrics"
                            ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Description"
                      String="A reference to the Metrics associated with this EthernetSwitchPort"/>
          <Annotation Term="OData.LongDescription"
                      String="A reference to the Metrics associated with this EthernetSwitchPort."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="NeighborInterface" Type="EthernetInterface.EthernetInterface">
          <Annotation Term="OData.Description"
                      String="A reference to the Metrics associated with this EthernetSwitchPort"/>
          <Annotation Term="OData.LongDescription"
                      String="A reference to the Metrics associated with this EthernetSwitchPort."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <Property Name="PriorityFlowControl" Type="EthernetSwitchPort.v1_1_0.PFC">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="This provide configuration of PFC on this switch port."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall provide configuration of Priority Flow Control for this switch port."/>
        </Property>
        <Property Name="DCBXState" Type="EthernetSwitchPort.v1_1_0.DCBXStateType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="This indicates whether DCBX is enabled on this switch."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a boolean indicating whether Data Center Bridging Extensions is enabled on this switch port."/>
        </Property>
        <Property Name="LLDPEnabled" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="This indicates whether LLDP protocol is enabled on this switch port."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a boolean indicating whether Link Layer Discovery Protocol (LLDP) IEEE 802.1AB is enabled on this switch port."/>
        </Property>
      </EntityType>

      <ComplexType Name="PFC">
        <!--        <Annotation Term="OData.AdditionalProperties" Bool="false"/> -->
        <Annotation Term="OData.Description" String="Priority Flow Control parameters."/>
        <Annotation Term="OData.LongDescription"
                    String="This object contains properties which specify the details of Priority Flow Control parameters for ethernet switch port."/>
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Enabled" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="This indicates whether PFC feature is enabled on this switch."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a boolean indicating whether Priority Flow Control (PFC) defined in IEEE 802.1Qbb is enabled on this switch port."/>
        </Property>
        <Property Name="EnabledPriorities" Type="Collection(Edm.Int64)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="This indicates priorities that are treated as 'no drop'."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall provide a list of priorities that should be treated by switch as lossless - for those priorities switch will send PAUSE frame."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Validation.Maximum" Int="7"/>
        </Property>
      </ComplexType>

      <EnumType Name="DCBXStateType">
        <Member Name="Disabled">
          <Annotation Term="OData.Description" String="TCP."/>
        </Member>
        <Member Name="EnabledIEEE">
          <Annotation Term="OData.Description" String="DCBX messages will be sent in IEEE defined format."/>
        </Member>
        <Member Name="EnabledCEE">
          <Annotation Term="OData.Description" String="DCBX messages will be sent in CEE defined format."/>
        </Member>
      </EnumType>
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_ETHERNET_SWITCH_PORT_V1_HPP */
