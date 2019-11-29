#ifndef PSME_REST_METADATA_I_PADDRESSES_V1_HPP
#define PSME_REST_METADATA_I_PADDRESSES_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string IPAddresses_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  IPAddresses  v1.0.7-->
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
    <edmx:Include Namespace="Validation.v1_0_0" Alias="Validation"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="IPAddresses">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>

      <ComplexType Name="IPv4Address" Abstract="true">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This type describes an IPv4 Address."/>
        <Annotation Term="OData.LongDescription" String="This type shall describe an IPv4 address assigned to an interface."/>
      </ComplexType>

      <ComplexType Name="IPv6Address" Abstract="true">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This type describes an IPv6 Address."/>
        <Annotation Term="OData.LongDescription" String="This type shall describe an IPv6 address assigned to an interface."/>
      </ComplexType>

      <ComplexType Name="IPv6StaticAddress" Abstract="true">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This object represents a single IPv6 static address to be assigned on a network interface."/>
        <Annotation Term="OData.LongDescription" String="This type shall represent a single IPv6 static address to be assigned on a network interface."/>
      </ComplexType>

      <ComplexType Name="IPv6GatewayStaticAddress" Abstract="true">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This object represents a single IPv6 static address to be assigned on a network interface."/>
        <Annotation Term="OData.LongDescription" String="This type shall represent a single IPv6 static address to be assigned on a network interface."/>
      </ComplexType>

    </Schema>


    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="IPAddresses.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="1.0"/>

      <ComplexType Name="IPv4Address" BaseType="IPAddresses.IPv4Address">
        <Property Name="Oem" Type="Resource.Oem" Nullable="false">
          <Annotation Term="OData.Description" String="Oem extension object."/>
          <Annotation Term="OData.LongDescription" String="This object represents the Oem property.  All values for resources described by this schema shall comply to the requirements as described in the Redfish specification."/>
        </Property>
        <Property Name="Address" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This is the IPv4 Address."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be an IPv4 address assigned to this interface.  If DHCPv4 is enabled on the interface, this property becomes read-only."/>
          <Annotation Term="Validation.Pattern" String="^(?:[0-9]{1,3}\.){3}[0-9]{1,3}$"/>
        </Property>
        <Property Name="SubnetMask" Type="IPAddresses.v1_0_0.SubnetMask">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This is the IPv4 Subnet mask."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the IPv4 subnet mask for this address.  If DHCPv4 is enabled on the interface, this property becomes read-only."/>
        </Property>
        <Property Name="AddressOrigin" Type="IPAddresses.v1_0_0.IPv4AddressOrigin">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This indicates how the address was determined."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the IP address origin for this network interface."/>
        </Property>
        <Property Name="Gateway" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This is the IPv4 gateway for this address."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the IPv4 default gateway address for this interface. If DHCPv4 is enabled on the interface and is configured to set the IPv4 default gateway address, this property becomes read-only."/>
          <Annotation Term="Validation.Pattern" String="^(?:[0-9]{1,3}\.){3}[0-9]{1,3}$"/>
        </Property>
      </ComplexType>

      <ComplexType Name="IPv6Address" BaseType="IPAddresses.IPv6Address">
        <Property Name="Oem" Type="Resource.Oem" Nullable="false">
          <Annotation Term="OData.Description" String="Oem extension object."/>
          <Annotation Term="OData.LongDescription" String="This object represents the Oem property.  All values for resources described by this schema shall comply to the requirements as described in the Redfish specification."/>
        </Property>
        <Property Name="Address" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This is the IPv6 Address."/>
          <Annotation Term="OData.LongDescription" String="This property lists an IPv6 address that is currently assigned on this interface."/>
          <Annotation Term="Redfish.IPv6Format"/>
        </Property>
        <Property Name="PrefixLength" Type="IPAddresses.v1_0_0.PrefixLength">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the IPv6 Address Prefix Length."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the IPv6 address prefix length for this interface."/>
        </Property>
        <Property Name="AddressOrigin" Type="IPAddresses.v1_0_0.IPv6AddressOrigin">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This indicates how the address was determined."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the IPv6 address origin for this interface."/>
        </Property>
        <Property Name="AddressState" Type="IPAddresses.v1_0_0.AddressState">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The current state of this address as defined in RFC 4862."/>
          <Annotation Term="OData.LongDescription" String="Preferred and Deprecated states follow the definitions given RFC4862 Section 5.5.4. An address is in the Tentative state while undergoing Duplicate Address Detection (DAD) per RFC4862 Section 5.4.  The Failed state indicates a Static addresses which did not pass DAD.  A Static address in the Failed state is not in use on the network stack, and corrective action will be needed to remedy this condition."/>
        </Property>
      </ComplexType>

      <EnumType Name="IPv4AddressOrigin">
        <Member Name="Static">
          <Annotation Term="OData.Description" String="A static address as configured by the user."/>
        </Member>
        <Member Name="DHCP">
          <Annotation Term="OData.Description" String="Address is provided by a DHCPv4 service."/>
        </Member>
        <Member Name="BOOTP">
          <Annotation Term="OData.Description" String="Address is provided by a BOOTP service."/>
        </Member>
        <Member Name="IPv4LinkLocal">
          <Annotation Term="OData.Description" String="Address is valid only for this network segment (link)."/>
        </Member>
      </EnumType>

      <EnumType Name="IPv6AddressOrigin">
        <Member Name="Static">
          <Annotation Term="OData.Description" String="A static address as configured by the user."/>
        </Member>
        <Member Name="DHCPv6">
          <Annotation Term="OData.Description" String="Address is provided by a DHCPv6 service."/>
        </Member>
        <Member Name="LinkLocal">
          <Annotation Term="OData.Description" String="Address is valid only for this network segment (link)."/>
        </Member>
        <Member Name="SLAAC">
          <Annotation Term="OData.Description" String="Address is provided by a Stateless Address AutoConfiguration (SLAAC) service."/>
        </Member>
      </EnumType>

      <TypeDefinition Name="SubnetMask" UnderlyingType="Edm.String">
        <Annotation Term="Validation.Pattern" String="^(?:[0-9]{1,3}\.){3}[0-9]{1,3}$"/>
      </TypeDefinition>

      <TypeDefinition Name="PrefixLength" UnderlyingType="Edm.Int64">
        <Annotation Term="Validation.Minimum" Int="1"/>
        <Annotation Term="Validation.Maximum" Int="128"/>
      </TypeDefinition>

      <EnumType Name="AddressState">
        <Member Name="Preferred">
          <Annotation Term="OData.Description" String="This address is currently within both it's valid and preferred lifetimes as defined in RFC 4862."/>
        </Member>
        <Member Name="Deprecated">
          <Annotation Term="OData.Description" String="This address is currently within it's valid lifetime, but is now outside of it's preferred lifetime as defined in RFC 4862."/>
        </Member>
        <Member Name="Tentative">
          <Annotation Term="OData.Description" String="This address is currently undergoing Duplicate Address Detection testing as defined in RFC 4862 section 5.4."/>
        </Member>
        <Member Name="Failed">
          <Annotation Term="OData.Description" String="This address has failed Duplicate Address Detection testing as defined in RFC 4862 section 5.4 and is not currently in use."/>
        </Member>
      </EnumType>

      <ComplexType Name="IPv6StaticAddress" BaseType="IPAddresses.IPv6StaticAddress">
        <Property Name="Oem" Type="Resource.Oem" Nullable="false">
          <Annotation Term="OData.Description" String="Oem extension object."/>
          <Annotation Term="OData.LongDescription" String="This object represents the Oem property.  All values for resources described by this schema shall comply to the requirements as described in the Redfish specification."/>
        </Property>
        <Property Name="Address" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="A valid IPv6 address."/>
          <Annotation Term="OData.LongDescription" String="This property provides access to a static IPv6 address that is currently assigned on a network interface."/>
          <Annotation Term="Redfish.Required"/>
          <Annotation Term="Redfish.IPv6Format"/>
        </Property>
        <Property Name="PrefixLength" Type="IPAddresses.v1_0_0.PrefixLength">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The Prefix Length of this IPv6 address."/>
          <Annotation Term="OData.LongDescription" String="Provides the IPv6 network prefix length in bits for this address."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="IPAddresses.v1_0_2">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="IPAddresses.v1_0_3">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="IPAddresses.v1_0_4">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="IPAddresses.v1_0_5">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="IPAddresses.v1_0_6">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to add an abstract base type for IPv4Address, IPv6Address, and IPv6StaticAddress.  It was also created to make PrefixLength in IPv6StaticAddress writable."/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="IPAddresses.v1_0_7">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number.  It was also created to add an abstract base type for IPv6GatewayStaticAddress.  It was also created to remove the requirement for PrefixLength in IPv6StaticAddress when used for gateway addresses."/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="IPAddresses.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="DMTF"/>
      <Annotation Term="Redfish.Release" String="2018.2"/>

      <ComplexType Name="IPv6GatewayStaticAddress" BaseType="IPAddresses.IPv6GatewayStaticAddress">
        <Property Name="Oem" Type="Resource.Oem" Nullable="false">
          <Annotation Term="OData.Description" String="Oem extension object."/>
          <Annotation Term="OData.LongDescription" String="This object represents the Oem property.  All values for resources described by this schema shall comply to the requirements as described in the Redfish specification."/>
        </Property>
        <Property Name="Address" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="A valid IPv6 address."/>
          <Annotation Term="OData.LongDescription" String="This property provides access to a static IPv6 address that is currently assigned on a network interface."/>
          <Annotation Term="Redfish.Required"/>
          <Annotation Term="Redfish.IPv6Format"/>
        </Property>
        <Property Name="PrefixLength" Type="IPAddresses.v1_0_0.PrefixLength">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The Prefix Length of this IPv6 address."/>
          <Annotation Term="OData.LongDescription" String="Provides the IPv6 network prefix length in bits for this address."/>
        </Property>
      </ComplexType>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_I_PADDRESSES_V1_HPP */
