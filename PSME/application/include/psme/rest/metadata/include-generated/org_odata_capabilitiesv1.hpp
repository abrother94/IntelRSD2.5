#ifndef PSME_REST_METADATA_ORG_ODATA_CAPABILITIESV1_HPP
#define PSME_REST_METADATA_ORG_ODATA_CAPABILITIESV1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string OrgODataCapabilitiesV1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!--
     OData Version 4.0
     OASIS Standard
     24 February 2014
     Copyright (c) OASIS Open 2014. All Rights Reserved.
     Source: http://docs.oasis-open.org/odata/odata/v4.0/os/vocabularies/
     -->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Alias="Core" Namespace="Org.OData.Core.V1"/>
  </edmx:Reference>
  <edmx:DataServices>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Org.OData.Capabilities.V1" Alias="Capabilities">
      <Annotation Term="Core.Description">
        <String>
          The Capabilities vocabulary aims to provide a way for service authors to describe
          certain capabilities of an OData Service.
        </String>
      </Annotation>
      <Annotation Term="Core.LongDescription">
        <String>
          There are some capabilities which are strongly recommended for services to support even
          though they are optional. Support for $top and $skip is a good example as
          supporting these query options helps with performance of a service and are essential. Such
          capabilities are assumed to be default capabilities of an OData service even in
          the case that a capabilities annotation doesn’t exist. Capabilities annotations are
          mainly expected to be used to explicitly specify that a service doesn’t support such
          capabilities. Capabilities annotations can as well be used to declaratively
          specify the support of such capabilities.

          On the other hand, there are some capabilities that a service may choose to support or
          not support and in varying degrees. $filter and $orderby are such good examples.
          This vocabulary aims to define terms to specify support or no support for such
          capabilities.

          A service is assumed to support by default the following capabilities even though an
          annotation doesn’t exist:
          - Countability ($count, $inlinecount)
          - Client pageability ($top, $skip)
          - Expandability ($expand)
          - Indexability by key
          - Batch support ($batch)
          - Navigability of navigation properties

          A service is expected to support the following capabilities. If not supported, the
          service is expected to call out the restrictions using annotations:
          - Filterability ($filter)
          - Sortability ($orderby)
          - Queryability of top level entity sets
          - Query functions

          A client cannot assume that a service supports certain capabilities. A client can try, but
          it needs to be prepared to handle an error in case the following capabilities are not
          supported:
          - Insertability
          - Updatability
          - Deletability
        </String>
      </Annotation>

      <!-- Conformance Level -->

      <Term Name="ConformanceLevel" Type="Capabilities.ConformanceLevelType" AppliesTo="EntityContainer"/>
      <EnumType Name="ConformanceLevelType">
        <Member Name="Minimal"/>
        <Member Name="Intermediate"/>
        <Member Name="Advanced"/>
      </EnumType>

      <!-- Request Capabilities -->

      <Term Name="SupportedFormats" Type="Collection(Edm.String)">
        <Annotation Term="Core.Description" String="Media types of supported formats, including format parameters"/>
        <Annotation Term="Core.IsMediaType"/>
      </Term>

      <Term Name="AcceptableEncodings" Type="Collection(Edm.String)" AppliesTo="EntityContainer">
        <Annotation Term="Core.Description" String="List of acceptable compression methods for ($batch) requests, e.g. gzip"/>
      </Term>

      <!-- Supported Preferences -->

      <Term Name="AsynchronousRequestsSupported" Type="Core.Tag" DefaultValue="true" AppliesTo="EntityContainer">
        <Annotation Term="Core.Description" String="Service supports the asynchronous request preference"/>
      </Term>

      <Term Name="BatchContinueOnErrorSupported" Type="Core.Tag" DefaultValue="true" AppliesTo="EntityContainer">
        <Annotation Term="Core.Description" String="Service supports the continue on error preference"/>
      </Term>

      <Term Name="IsolationSupported" Type="Capabilities.IsolationLevel" AppliesTo="EntityContainer">
        <Annotation Term="Core.Description" String="Supported odata.isolation levels"/>
      </Term>
      <EnumType Name="IsolationLevel" IsFlags="true">
        <Member Name="Snapshot" Value="1"/>
      </EnumType>

      <Term Name="CallbackSupported" Type="Capabilities.CallbackType" AppliesTo="EntityContainer EntitySet">
        <Annotation Term="Core.Description" String="Supports callbacks for the specified protocols"/>
      </Term>
      <Term Name="CrossJoinSupported" Type="Core.Tag" DefaultValue="true" AppliesTo="EntityContainer">
        <Annotation Term="Core.Description" String="Supports cross joins for the entity sets in this container"/>
      </Term>
      <ComplexType Name="CallbackType">
        <Property Name="CallbackProtocols" Type="Collection(Capabilities.CallbackProtocol)"/>
        <Annotation Term="Core.Description" String="A non-empty collection lists the full set of supported protocols. A empty collection means 'only HTTP is supported'"/>
      </ComplexType>
      <ComplexType Name="CallbackProtocol">
        <Property Name="Id" Type="Edm.String">
          <Annotation Term="Core.Description" String="Protcol Identifier"/>
        </Property>
        <Property Name="UrlTemplate" Type="Edm.String">
          <Annotation Term="Core.Description" String="URL Template including parameters. Parameters are enclosed in curly braces {} as defined in RFC6570"/>
        </Property>
        <Property Name="DocumentationUrl" Type="Edm.String" Nullable="true">
          <Annotation Term="Core.Description" String="Human readable description of the meaning of the URL Template parameters"/>
          <Annotation Term="Core.IsURL"/>
        </Property>
      </ComplexType>

      <Term Name="ChangeTracking" Type="Capabilities.ChangeTrackingType" AppliesTo="EntityContainer EntitySet">
        <Annotation Term="Core.Description" String="Change tracking capabilities of this service or entity set"/>
      </Term>
      <ComplexType Name="ChangeTrackingType">
        <Property Name="Supported" Type="Edm.Boolean" DefaultValue="true">
          <Annotation Term="Core.Description" String="This entity set supports the odata.track-changes preference"/>
        </Property>
        <Property Name="FilterableProperties" Type="Collection(Edm.PropertyPath)">
          <Annotation Term="Core.Description" String="Change tracking supports filters on these properties"/>
        </Property>
        <Property Name="ExpandableProperties" Type="Collection(Edm.NavigationPropertyPath)">
          <Annotation Term="Core.Description" String="Change tracking supports these properties expanded"/>
        </Property>
      </ComplexType>

      <!--Query Capabilities -->

      <Term Name="CountRestrictions" Type="Capabilities.CountRestrictionsType" AppliesTo="EntitySet">
        <Annotation Term="Core.Description" String="Restrictions on /$count path suffix and $count=true system query option"/>
      </Term>
      <ComplexType Name="CountRestrictionsType">
        <Property Name="Countable" Type="Edm.Boolean" DefaultValue="true">
          <Annotation Term="Core.Description" String="Entities can be counted"/>
        </Property>
        <Property Name="NonCountableProperties" Type="Collection(Edm.PropertyPath)">
          <Annotation Term="Core.Description" String="These collection properties do not allow /$count segments"/>
        </Property>
        <Property Name="NonCountableNavigationProperties" Type="Collection(Edm.NavigationPropertyPath)">
          <Annotation Term="Core.Description" String="These navigation properties do not allow /$count segments"/>
        </Property>
      </ComplexType>

      <Term Name="NavigationRestrictions" Type="Capabilities.NavigationRestrictionsType" AppliesTo="EntitySet">
        <Annotation Term="Core.Description" String="Restrictions on navigating properties according to OData URL conventions"/>
      </Term>
      <ComplexType Name="NavigationRestrictionsType">
        <Property Name="Navigability" Type="Capabilities.NavigationType">
          <Annotation Term="Core.Description" String="Supported Navigability"/>
        </Property>
        <Property Name="RestrictedProperties" Type="Collection(Capabilities.NavigationPropertyRestriction)"/>
      </ComplexType>
      <ComplexType Name="NavigationPropertyRestriction">
        <Property Name="NavigationProperty" Type="Edm.NavigationPropertyPath">
          <Annotation Term="Core.Description" String="Navigation properties can be navigated to a single level"/>
        </Property>
        <Property Name="Navigability" Type="Capabilities.NavigationType">
          <Annotation Term="Core.Description" String="Navigation properties can be navigated to a single level"/>
        </Property>
      </ComplexType>
      <EnumType Name="NavigationType">
        <Member Name="Recursive">
          <Annotation Term="Core.Description" String="Navigation properties can be recursively navigated"/>
        </Member>
        <Member Name="Single">
          <Annotation Term="Core.Description" String="Navigation properties can be navigated to a single level"/>
        </Member>
        <Member Name="None">
          <Annotation Term="Core.Description" String="Navigation properties are not navigable"/>
        </Member>
      </EnumType>

      <Term Name="IndexableByKey" Type="Core.Tag" DefaultValue="true" AppliesTo="EntitySet">
        <Annotation Term="Core.Description" String="Supports key values according to OData URL conventions"/>
      </Term>

      <Term Name="TopSupported" Type="Core.Tag" DefaultValue="true" AppliesTo="EntitySet">
        <Annotation Term="Core.Description" String="Supports $top"/>
      </Term>
      <Term Name="SkipSupported" Type="Core.Tag" DefaultValue="true" AppliesTo="EntitySet">
        <Annotation Term="Core.Description" String="Supports $skip"/>
      </Term>

      <Term Name="BatchSupported" Type="Core.Tag" DefaultValue="true" AppliesTo="EntityContainer">
        <Annotation Term="Core.Description" String="Supports $batch requests"/>
      </Term>

      <Term Name="FilterFunctions" Type="Collection(Edm.String)" AppliesTo="EntityContainer EntitySet">
        <Annotation Term="Core.Description" String="List of functions supported in $filter"/>
      </Term>

      <Term Name="FilterRestrictions" Type="Capabilities.FilterRestrictionsType" AppliesTo="EntitySet">
        <Annotation Term="Core.Description" String="Restrictions on $filter expressions"/>
      </Term>
      <ComplexType Name="FilterRestrictionsType">
        <Property Name="Filterable" Type="Edm.Boolean" DefaultValue="true">
          <Annotation Term="Core.Description" String="$filter is supported"/>
        </Property>
        <Property Name="RequiresFilter" Type="Edm.Boolean" Nullable="true">
          <Annotation Term="Core.Description" String="$filter is required"/>
        </Property>
        <Property Name="RequiredProperties" Type="Collection(Edm.PropertyPath)">
          <Annotation Term="Core.Description" String="These properties must be specified in the $filter clause (properties of derived types are not allowed here)"/>
        </Property>
        <Property Name="NonFilterableProperties" Type="Collection(Edm.PropertyPath)">
          <Annotation Term="Core.Description" String="These properties cannot be used in $filter expressions"/>
        </Property>
      </ComplexType>

      <Term Name="SortRestrictions" Type="Capabilities.SortRestrictionsType" AppliesTo="EntitySet">
        <Annotation Term="Core.Description" String="Restrictions on $orderby expressions"/>
      </Term>
      <ComplexType Name="SortRestrictionsType">
        <Property Name="Sortable" Type="Edm.Boolean" DefaultValue="true">
          <Annotation Term="Core.Description" String="$orderby is supported"/>
        </Property>
        <Property Name="AscendingOnlyProperties" Type="Collection(Edm.PropertyPath)">
          <Annotation Term="Core.Description" String="These properties can only be used for sorting in Ascending order"/>
        </Property>
        <Property Name="DescendingOnlyProperties" Type="Collection(Edm.PropertyPath)">
          <Annotation Term="Core.Description" String="These properties can only be used for sorting in Descending order"/>
        </Property>
        <Property Name="NonSortableProperties" Type="Collection(Edm.PropertyPath)">
          <Annotation Term="Core.Description" String="These properties cannot be used in $orderby expressions"/>
        </Property>
      </ComplexType>

      <Term Name="ExpandRestrictions" Type="Capabilities.ExpandRestrictionsType" AppliesTo="EntitySet">
        <Annotation Term="Core.Description" String="Restrictions on $expand expressions"/>
      </Term>
      <ComplexType Name="ExpandRestrictionsType">
        <Property Name="Expandable" Type="Edm.Boolean" DefaultValue="true">
          <Annotation Term="Core.Description" String="$expand is supported"/>
        </Property>
        <Property Name="NonExpandableProperties" Type="Collection(Edm.NavigationPropertyPath)">
          <Annotation Term="Core.Description" String="These properties cannot be used in $expand expressions"/>
        </Property>
      </ComplexType>

      <Term Name="SearchRestrictions" Type="Capabilities.SearchRestrictionsType" AppliesTo="EntitySet">
        <Annotation Term="Core.Description" String="Restrictions on $search expressions"/>
      </Term>
      <ComplexType Name="SearchRestrictionsType">
        <Property Name="Searchable" Type="Edm.Boolean" DefaultValue="true">
          <Annotation Term="Core.Description" String="$search is supported"/>
        </Property>
        <Property Name="UnsupportedExpressions" Type="Capabilities.SearchExpressions" DefaultValue="none">
          <Annotation Term="Core.Description" String="Expressions supported in $search"/>
        </Property>
      </ComplexType>
      <EnumType Name="SearchExpressions" IsFlags="true">
        <Member Name="none" Value="0"/>
        <Member Name="AND" Value="1"/>
        <Member Name="OR" Value="2"/>
        <Member Name="NOT" Value="4"/>
        <Member Name="phrase" Value="8"/>
        <Member Name="group" Value="16"/>
      </EnumType>

      <!-- Data Modification Capabilities -->

      <Term Name="InsertRestrictions" Type="Capabilities.InsertRestrictionsType" AppliesTo="EntitySet">
        <Annotation Term="Core.Description" String="Restrictions on insert operations"/>
      </Term>
      <ComplexType Name="InsertRestrictionsType">
        <Property Name="Insertable" Type="Edm.Boolean" DefaultValue="true">
          <Annotation Term="Core.Description" String="Entities can be inserted"/>
        </Property>
        <Property Name="NonInsertableNavigationProperties" Type="Collection(Edm.NavigationPropertyPath)">
          <Annotation Term="Core.Description" String="These navigation properties do not allow deep inserts"/>
        </Property>
      </ComplexType>

      <Term Name="UpdateRestrictions" Type="Capabilities.UpdateRestrictionsType" AppliesTo="EntitySet">
        <Annotation Term="Core.Description" String="Restrictions on update operations"/>
      </Term>
      <ComplexType Name="UpdateRestrictionsType">
        <Property Name="Updatable" Type="Edm.Boolean" DefaultValue="true">
          <Annotation Term="Core.Description" String="Entities can be updated"/>
        </Property>
        <Property Name="NonUpdatableNavigationProperties" Type="Collection(Edm.NavigationPropertyPath)">
          <Annotation Term="Core.Description" String="These navigation properties do not allow rebinding"/>
        </Property>
      </ComplexType>

      <Term Name="DeleteRestrictions" Type="Capabilities.DeleteRestrictionsType" AppliesTo="EntitySet">
        <Annotation Term="Core.Description" String="Restrictions on delete operations"/>
      </Term>
      <ComplexType Name="DeleteRestrictionsType">
        <Property Name="Deletable" Type="Edm.Boolean" DefaultValue="true">
          <Annotation Term="Core.Description" String="Entities can be deleted"/>
        </Property>
        <Property Name="NonDeletableNavigationProperties" Type="Collection(Edm.NavigationPropertyPath)">
          <Annotation Term="Core.Description" String="These navigation properties do not allow DeleteLink requests"/>
        </Property>
      </ComplexType>

    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_ORG_ODATA_CAPABILITIESV1_HPP */
