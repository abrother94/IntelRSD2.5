#ifndef PSME_REST_METADATA_STORAGE_REPLICA_INFO_V1_HPP
#define PSME_REST_METADATA_STORAGE_REPLICA_INFO_V1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string StorageReplicaInfo_v1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!-- Copyright 2015-2018 Storage Networking Industry Association (SNIA), USA. All rights reserved.-->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Measures.V1.xml">
    <edmx:Include Namespace="Org.OData.Measures.V1" Alias="Measures"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
		<edmx:Include Namespace="Resource"/>
		<edmx:Include Namespace="Resource.v1_0_0"/>
	</edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/DataProtectionLineOfService_v1.xml">
    <edmx:Include Namespace="DataProtectionLineOfService"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="StorageReplicaInfo">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <EntityType Name="StorageReplicaInfo" BaseType="Resource.v1_0_0.Resource" Abstract="true"/>

      <ComplexType Name="ReplicaInfo" Abstract="true">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="Defines the characteristics of a replica of a source."/>
        <Annotation Term="OData.LongDescription" String="The value shall define the characteristics of a replica of a source."/>
      </ComplexType>

      <EnumType Name="ReplicaUpdateMode">
        <Annotation Term="OData.Description" String="Values of ReplicaUpdateMode describe whether the target elements will be updated synchronously or asynchronously."/>
        <Annotation Term="OData.LongDescription" String="The enumeration literals may be used to specify whether the target elements will be updated synchronously or asynchronously."/>
        <Member Name="Active">
          <Annotation Term="OData.Description" String="Active-Active (i.e. bidirectional) synchronous updates."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate Active-Active (i.e. bidirectional) synchronous updates."/>
        </Member>
        <Member Name="Synchronous">
          <Annotation Term="OData.Description" String="Synchronous updates."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate Synchronous updates."/>
        </Member>
        <Member Name="Asynchronous">
          <Annotation Term="OData.Description" String="Asynchronous updates."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate Asynchronous updates."/>
        </Member>
        <Member Name="Adaptive">
          <Annotation Term="OData.Description" String="Allows implementation to switch between synchronous and asynchronous modes."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that an implementation may switch between synchronous and asynchronous modes."/>
        </Member>
      </EnumType>

      <EnumType Name="ReplicaType">
        <Annotation Term="OData.Description" String="Values of ReplicaType describe the intended outcome of the replication."/>
        <Annotation Term="OData.LongDescription" String="The enumeration literals may be used to specify the intended outcome of the replication."/>
        <Member Name="Mirror">
          <Annotation Term="OData.Description" String="Create and maintain a copy of the source."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that replication shall create and maintain a copy of the source."/>
        </Member>
        <Member Name="Snapshot">
          <Annotation Term="OData.Description" String="Create a point in time, virtual copy of the source."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that replication shall create a point in time, virtual copy of the source."/>
        </Member>
        <Member Name="Clone">
          <Annotation Term="OData.Description" String="Create a point in time, full copy the source."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that replication shall create a point in time, full copy the source."/>
        </Member>
        <Member Name="TokenizedClone">
          <Annotation Term="OData.Description" String="Create a token based clone."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that replication shall create a token based clone."/>
        </Member>
      </EnumType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="StorageReplicaInfo.v1_0_0">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <EntityType Name="StorageReplicaInfo" BaseType="StorageReplicaInfo.StorageReplicaInfo"/>

      <ComplexType Name="ReplicaInfo" BaseType="StorageReplicaInfo.ReplicaInfo">
        <Annotation Term="OData.Description" String="Defines the characteristics of a replica."/>
        <Annotation Term="OData.LongDescription" String="The value shall define the characteristics of a replica."/>
        <Property Name="ReplicaPriority" Type="StorageReplicaInfo.v1_0_0.ReplicaPriority">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The priority of background copy engine I/O to be managed relative to host I/O operations during a sequential background copy operation."/>
          <Annotation Term="OData.LongDescription" String="The enumeration literal shall specify the priority of background copy engine I/O to be managed relative to host I/O operations during a sequential background copy operation."/>
        </Property>
        <Property Name="ReplicaReadOnlyAccess" Type="StorageReplicaInfo.v1_0_0.ReplicaReadOnlyAccess">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This property specifies whether the source, the target, or both elements are read only to the host."/>
          <Annotation Term="OData.LongDescription" String="The enumeration literal shall specify whether the source, the target, or both elements are read only to the host."/>
        </Property>
        <Property Name="UndiscoveredElement" Type="StorageReplicaInfo.v1_0_0.UndiscoveredElement">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This property specifies whether the source, the target, or both elements involved in a copy operation are undiscovered."/>
          <Annotation
            Term="OData.LongDescription"
            String="The enumeration literal shall specify whether the source, the target, or both elements involved in a copy operation are undiscovered. An element is considered undiscovered if its object model is not known to the service performing the copy operation."/>
        </Property>
        <Property Name="WhenSynced" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The point in time that the Elements were synchronized."/>
          <Annotation Term="OData.LongDescription" String="The value shall be an ISO 8601 conformant time of day that specifies when the elements were synchronized."/>
        </Property>
        <Property Name="SyncMaintained" Type="Edm.Boolean" DefaultValue="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Synchronization is maintained."/>
          <Annotation Term="OData.LongDescription" String="If true, Synchronization shall be maintained. The default value for this property is false."/>
        </Property>
        <Property Name="ReplicaRecoveryMode" Type="StorageReplicaInfo.v1_0_0.ReplicaRecoveryMode">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Describes whether the copy operation continues after a broken link is restored."/>
          <Annotation Term="OData.LongDescription" String="The enumeration literal shall specify whether the copy operation continues after a broken link is restored."/>
        </Property>
        <Property Name="ReplicaUpdateMode" Type="StorageReplicaInfo.ReplicaUpdateMode">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Describes whether the target elements will be updated synchronously or asynchronously."/>
          <Annotation Term="OData.LongDescription" String="The enumeration literal shall specify whether the target elements will be updated synchronously or asynchronously."/>
        </Property>
        <Property Name="PercentSynced" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Specifies the percent of the work completed to reach synchronization."/>
          <Annotation
            Term="OData.LongDescription"
            String="Specifies the percent of the work completed to reach synchronization. Shall not be instantiated if implementation is not capable of providing this information.  If related to a group, then PercentSynced shall be an average of the PercentSynced across all members of the group."/>
          <Annotation Term="Measures.Unit" String="%"/>
        </Property>
        <Property Name="FailedCopyStopsHostIO" Type="Edm.Boolean" DefaultValue="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="If true, the storage array tells host to stop sending data to source element if copying to a remote element fails."/>
          <Annotation Term="OData.LongDescription" String="If true, the storage array shall stop receiving data to the source element if copying to a remote element fails. The default value for this property is false."/>
        </Property>
        <Property Name="WhenActivated" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Specifies when point-in-time copy was taken or when the replication relationship is activated, reactivated, resumed or re-established."/>
          <Annotation
            Term="OData.LongDescription"
            String="The value shall be an ISO 8601 conformant time of day that specifies when the point-in-time copy was taken or when the replication relationship is activated, reactivated, resumed or re-established. This property shall be null if the implementation is not capable of providing this information."/>
          <Annotation Term="Measures.Unit" String="%"/>
        </Property>
        <Property Name="WhenDeactivated" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Specifies when the replication relationship is deactivated."/>
          <Annotation
            Term="OData.LongDescription"
            String="The value shall be an ISO 8601 conformant time of day that specifies when the replication relationship is deactivated. Do not instantiate this property if implementation is not capable of providing this information."/>
          <Annotation Term="Measures.Unit" String="%"/>
        </Property>
        <Property Name="WhenEstablished" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Specifies when the replication relationship is established."/>
          <Annotation
            Term="OData.LongDescription"
            String="The value shall be an ISO 8601 conformant time of day that specifies when the replication relationship is established. Do not instantiate this property if implementation is not capable of providing this information."/>
          <Annotation Term="Measures.Unit" String="%"/>
        </Property>
        <Property Name="WhenSuspended" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Specifies when the replication relationship is suspended."/>
          <Annotation
            Term="OData.LongDescription"
            String="The value shall be an ISO 8601 conformant time of day that specifies when the replication relationship is suspended. Do not instantiate this property if implementation is not capable of providing this information."/>
          <Annotation Term="Measures.Unit" String="%"/>
        </Property>
        <Property Name="WhenSynchronized" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Specifies when the replication relationship is synchronized."/>
          <Annotation
            Term="OData.LongDescription"
            String="The value shall be an ISO 8601 conformant time of day that specifies when the replication relationship is synchronized. Do not instantiate this property if implementation is not capable of providing this information."/>
          <Annotation Term="Measures.Unit" String="%"/>
        </Property>
        <Property Name="ReplicaSkewBytes" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Applies to Adaptive mode and it describes maximum number of bytes the SyncedElement (target) can be out of sync."/>
          <Annotation
            Term="OData.LongDescription"
            String="Applies to Adaptive mode and it describes maximum number of bytes the SyncedElement (target) can be out of sync. If the number of out-of-sync bytes exceeds the skew value, ReplicaUpdateMode shall be switched to synchronous."/>
          <Annotation Term="Measures.Unit" String="By"/>
        </Property>
        <Property Name="ReplicaType" Type="StorageReplicaInfo.ReplicaType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="ReplicaType describes the intended outcome of the replication."/>
          <Annotation Term="OData.LongDescription" String="The ReplicaType enumeration literal shall describe the intended outcome of the replication."/>
        </Property>
        <Property Name="ReplicaProgressStatus" Type="StorageReplicaInfo.v1_0_0.ReplicaProgressStatus">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The status of the session with respect to Replication activity."/>
          <Annotation Term="OData.LongDescription" String="The ReplicaProgressStatus enumeration literal shall specify the status of the session with respect to Replication activity."/>
        </Property>
        <Property Name="ReplicaState" Type="StorageReplicaInfo.v1_0_0.ReplicaState">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="ReplicaState describes the state of the relationship with respect to Replication activity."/>
          <Annotation Term="OData.LongDescription" String="The ReplicaState enumeration literal shall specify the state of the relationship with respect to Replication activity."/>
        </Property>
        <Property Name="RequestedReplicaState" Type="StorageReplicaInfo.v1_0_0.ReplicaState">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The last requested or desired state for the relationship."/>
          <Annotation
            Term="OData.LongDescription"
            String="The last requested or desired state for the relationship. The actual state of the relationship shall be represented by ReplicaState. When RequestedState reaches the requested state, this property shall be null."/>
        </Property>
        <Property Name="ConsistencyEnabled" Type="Edm.Boolean" DefaultValue="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="True if consistency is enabled."/>
          <Annotation Term="OData.LongDescription" String="If true, consistency shall be enabled across the source and its associated target replica(s). The default value for this property is false."/>
        </Property>
        <Property Name="ConsistencyType" Type="StorageReplicaInfo.v1_0_0.ConsistencyType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Indicates the consistency type used by the source and its associated target group."/>
          <Annotation Term="OData.LongDescription" String="The ConsistencyType enumeration literal shall indicate the consistency type used by the source and its associated target group."/>
        </Property>
        <Property Name="ConsistencyState" Type="StorageReplicaInfo.v1_0_0.ConsistencyState">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The current state of consistency."/>
          <Annotation Term="OData.LongDescription" String="The ConsistencyState enumeration literal shall indicate the current state of consistency."/>
        </Property>
        <Property Name="ConsistencyStatus" Type="StorageReplicaInfo.v1_0_0.ConsistencyStatus">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The current status of consistency."/>
          <Annotation Term="OData.LongDescription" String="The ConsistencyStatus enumeration literal shall specify the current status of consistency. Consistency may have been disabled or is experiencing an error condition."/>
        </Property>
        <Property Name="ReplicaRole" Type="StorageReplicaInfo.v1_0_0.ReplicaRole">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="Redfish.Deprecated" String="ReplicaInfo is only used within a replica target. The Replica property here addresses the source resource.  A TargetReplicas property in each source resource describes the replica targets of a source."/>
          <Annotation Term="OData.Description" String="The source or target role of this replica."/>
          <Annotation Term="OData.LongDescription" String="The ReplicaRole enumeration literal shall represent the source or target role of this replica as known to the containing resource."/>
        </Property>
        <NavigationProperty Name="Replica" Type="Resource.Item">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The resource that is the source of this replica."/>
          <Annotation Term="OData.LongDescription" String="The value shall reference the resource that is the source of this replica."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <EnumType Name="ReplicaPriority">
        <Annotation Term="OData.Description" String="ReplicaPriority allows the priority of background copy engine I/O to be managed relative to host I/O operations during a sequential background copy operation."/>
        <Annotation
          Term="OData.LongDescription"
          String="The enumeration literals of the ReplicaPriority enumeration may be used to specify the priority of background copy engine I/O relative to host I/O operations during a sequential background copy operation."/>
        <Member Name="Low">
          <Annotation Term="OData.Description" String="Copy engine I/O lower priority than host I/O."/>
          <Annotation Term="OData.LongDescription" String="Copy engine I/O shall have a lower priority than host I/O."/>
        </Member>
        <Member Name="Same">
          <Annotation Term="OData.Description" String="Copy engine I/O has the same priority as host I/O."/>
          <Annotation Term="OData.LongDescription" String="Copy engine I/O shall have the same priority as host I/O."/>
        </Member>
        <Member Name="High">
          <Annotation Term="OData.Description" String="Copy engine I/O has higher priority than host I/O."/>
          <Annotation Term="OData.LongDescription" String="Copy engine I/O shall have a higher priority than host I/O."/>
        </Member>
        <Member Name="Urgent">
          <Annotation Term="OData.Description" String="Copy operation to be performed as soon as possible, regardless of the host I/O requests."/>
          <Annotation Term="OData.LongDescription" String="Regardless of the host I/O requests, the Copy operation shall be performed as soon as possible."/>
        </Member>
      </EnumType>

      <EnumType Name="ReplicaReadOnlyAccess">
        <Annotation Term="OData.Description" String="Values of ReplicaReadOnlyAccess specify whether the source, the target, or both elements are read only to the host."/>
        <Annotation Term="OData.LongDescription" String="The enumeration literals may be used to specify whether the source, the target, or both elements are read-only to the host."/>
        <Member Name="SourceElement">
          <Annotation Term="OData.Description" String="The source element."/>
          <Annotation Term="OData.LongDescription" String="The source element shall be read-only to the host."/>
        </Member>
        <Member Name="ReplicaElement">
          <Annotation Term="OData.Description" String="The replica element. "/>
          <Annotation Term="OData.LongDescription" String="The replica element shall be read-only to the host."/>
        </Member>
        <Member Name="Both">
          <Annotation Term="OData.Description" String="Both the source and the target elements are read only to the host."/>
          <Annotation Term="OData.LongDescription" String="Both the source and the target elements shall be read only to the host."/>
        </Member>
      </EnumType>

      <EnumType Name="ReplicaRole">
        <Annotation Term="Redfish.Deprecated" String="ReplicaRole is not used."/>
        <Annotation Term="OData.Description" String="Values of ReplicaRole specify whether the resource is a source of replication or the target of replication."/>
        <Annotation Term="OData.LongDescription" String="The enumeration literals may be used to specify whether the resource is a source of replication or the target of replication."/>
        <Member Name="Source">
          <Annotation Term="OData.Description" String="The source element."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate a source element."/>
        </Member>
        <Member Name="Target">
          <Annotation Term="OData.Description" String="The target element. "/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate target element."/>
        </Member>

      </EnumType>
      <EnumType Name="UndiscoveredElement">
        <Annotation
          Term="OData.Description"
          String="Values of UndiscoveredElement specify whether the source, the target, or both elements involved in a copy operation are undiscovered. An element is considered undiscovered if its object model is not known to the service performing the copy operation."/>
        <Annotation
          Term="OData.LongDescription"
          String="The enumeration literals may be used to specify whether the source, the target, or both elements involved in a copy operation are undiscovered. An element shall be considered undiscovered if its object model is not known to the service performing the copy operation."/>
        <Member Name="SourceElement">
          <Annotation Term="OData.Description" String="The source element is undiscovered."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the source element is undiscovered."/>
        </Member>
        <Member Name="ReplicaElement">
          <Annotation Term="OData.Description" String="The replica element is undiscovered."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the replica element is undiscovered."/>
        </Member>
      </EnumType>

      <EnumType Name="ReplicaRecoveryMode">
        <Annotation Term="OData.Description" String="Values of ReplicaRecoveryMode describe whether the copy operation continues after a broken link is restored."/>
        <Annotation Term="OData.LongDescription" String="The enumeration literals may be used to specify whether the copy operation continues after a broken link is restored."/>
        <Member Name="Automatic">
          <Annotation Term="OData.Description" String="Copy operation resumes automatically."/>
          <Annotation Term="OData.LongDescription" String="The copy operation shall resume automatically."/>
        </Member>
        <Member Name="Manual">
          <Annotation Term="OData.Description" String="ReplicaState is set to Suspended after the link is restored. It is required to issue the Resume operation to continue."/>
          <Annotation Term="OData.LongDescription" String="The ReplicaState shall be set to Suspended after the link is restored. It is required to issue the Resume operation to continue."/>
        </Member>
      </EnumType>

      <EnumType Name="ReplicaProgressStatus">
        <Annotation Term="OData.Description" String="Values of ReplicaProgressStatus describe the status of the session with respect to Replication activity."/>
        <Annotation Term="OData.LongDescription" String="ReplicaProgressStatus enumeration literals may be used to describe the status of the session with respect to Replication activity."/>
        <Member Name="Completed">
          <Annotation Term="OData.Description" String="The request is completed. Data flow is idle."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the request is completed. Data flow is idle."/>
        </Member>
        <Member Name="Dormant">
          <Annotation Term="OData.Description" String="Indicates that the data flow is inactive, suspended or quiesced."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the data flow is inactive, suspended or quiesced."/>
        </Member>
        <Member Name="Initializing">
          <Annotation Term="OData.Description" String="In the process of establishing source/replica relationship and the data flow has not started."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that replication is in the process of establishing source/replica relationship and the data flow has not started."/>
        </Member>
        <Member Name="Preparing">
          <Annotation Term="OData.Description" String="Preparation in progress."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that replication has preparation in progress."/>
        </Member>
        <Member Name="Synchronizing">
          <Annotation Term="OData.Description" String="Sync in progress."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that replication has synchronization in progress."/>
        </Member>
        <Member Name="Resyncing">
          <Annotation Term="OData.Description" String="Resync in progess."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that replication has resynchronization in progess."/>
        </Member>
        <Member Name="Restoring">
          <Annotation Term="OData.Description" String="Restore in progress."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that replication has a restore in progress."/>
        </Member>
        <Member Name="Fracturing">
          <Annotation Term="OData.Description" String="Fracture in progress."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that replication has a fracture in progress."/>
        </Member>
        <Member Name="Splitting">
          <Annotation Term="OData.Description" String="Split in progress."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that replication has a split in progress."/>
        </Member>
        <Member Name="FailingOver">
          <Annotation Term="OData.Description" String="In the process of switching source and target."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that replication is in the process of switching source and target."/>
        </Member>
        <Member Name="FailingBack">
          <Annotation Term="OData.Description" String="Undoing the result of failover."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that replication is undoing the result of failover."/>
        </Member>
        <Member Name="Detaching">
          <Annotation Term="OData.Description" String="Detach in progress."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that replication has a detach in progress."/>
        </Member>
        <Member Name="Aborting">
          <Annotation Term="OData.Description" String="Abort in progress."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that replication has an abort in progress."/>
        </Member>
        <Member Name="Mixed">
          <Annotation Term="OData.Description" String="Applies to groups with element pairs with different statuses. Generally, the individual statuses need to be examined."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that replication status is mixed across element pairs in a replication group. Generally, the individual statuses need to be examined."/>
        </Member>
        <Member Name="Suspending">
          <Annotation Term="OData.Description" String="The copy operation is in the process of being suspended."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that replication has a copy operation in the process of being suspended."/>
        </Member>
        <Member Name="RequiresFracture">
          <Annotation Term="OData.Description" String="The requested operation has completed, however, the synchronization relationship needs to be fractured before further copy operations can be issued."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the requested operation has completed, however, the synchronization relationship needs to be fractured before further copy operations can be issued."/>
        </Member>
        <Member Name="RequiresResync">
          <Annotation Term="OData.Description" String="The requested operation has completed, however, the synchronization relationship needs to be resynced before further copy operations can be issued."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the requested operation has completed, however, the synchronization relationship needs to be resynced before further copy operations can be issued."/>
        </Member>
        <Member Name="RequiresActivate">
          <Annotation Term="OData.Description" String="The requested operation has completed, however, the synchronization relationship needs to be activated before further copy operations can be issued."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the requested operation has completed, however, the synchronization relationship needs to be activated before further copy operations can be issued."/>
        </Member>
        <Member Name="Pending">
          <Annotation Term="OData.Description" String="The flow of data has stopped momentarily due to limited bandwidth or a busy system."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the flow of data has stopped momentarily due to limited bandwidth or a busy system."/>
        </Member>
        <Member Name="RequiresDetach">
          <Annotation Term="OData.Description" String="The requested operation has completed, however, the synchronization relationship needs to be detached before further copy operations can be issued."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the requested operation has completed, however, the synchronization relationship needs to be detached before further copy operations can be issued."/>
        </Member>
        <Member Name="Terminating">
          <Annotation Term="OData.Description" String="The relationship is in the process of terminating."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the replication relationship is in the process of terminating."/>
        </Member>
        <Member Name="RequiresSplit">
          <Annotation Term="OData.Description" String="The requested operation has completed, however, the synchronization relationship needs to be split before further copy operations can be issued."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the requested operation has completed, however, the synchronization relationship needs to be split before further copy operations can be issued."/>
        </Member>
        <Member Name="RequiresResume">
          <Annotation Term="OData.Description" String="The requested operation has completed, however, the synchronization relationship needs to be resumed before further copy operations can be issued."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the requested operation has completed, however, the synchronization relationship needs to be resumed before further copy operations can be issued."/>
        </Member>
      </EnumType>

      <EnumType Name="ReplicaState">
        <Annotation Term="OData.Description" String="Values of ReplicaState describe the state of the relationship with respect to Replication activity."/>
        <Annotation Term="OData.LongDescription" String="ReplicaState enumeration literals may be used to describe the state of the relationship with respect to Replication activity."/>
        <Member Name="Initialized">
          <Annotation Term="OData.Description" String=" The link to enable replication is established and source/replica elements are associated, but the data flow has not started. "/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the link to enable replication is established and source/replica elements are associated, but the data flow has not started."/>
        </Member>
        <Member Name="Unsynchronized">
          <Annotation Term="OData.Description" String="Not all the source element data has been copied to the target element. "/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that not all the source element data has been copied to the target element."/>
        </Member>
        <Member Name="Synchronized">
          <Annotation Term="OData.Description" String="For the Mirror, Snapshot, or Clone replication, the target represents a copy of the source. "/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that for Mirror, Snapshot, or Clone replication, the target represents a copy of the source."/>
        </Member>
        <Member Name="Broken">
          <Annotation Term="OData.Description" String="The relationship is non-functional due to errors in the source, the target, the path between the two or space constraints. "/>
          <Annotation Term="OData.LongDescription" String=" This enumeration literal shall indicate that the relationship is non-functional due to errors in the source, the target, the path between the two or space constraints."/>
        </Member>
        <Member Name="Fractured">
          <Annotation Term="OData.Description" String="Target is split from the source. "/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the Target is split from the source. The target may not be consistent."/>
        </Member>
        <Member Name="Split">
          <Annotation Term="OData.Description" String="The target element was gracefully (or systematically) split from its source element -- consistency is guaranteed. "/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the target element was gracefully (or systematically) split from its source element -- consistency shall be guaranteed."/>
        </Member>
        <Member Name="Inactive">
          <Annotation Term="OData.Description" String="Data flow has stopped, writes to source element will not be sent to target element. "/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that data flow has stopped, writes to source element shall not be sent to target element."/>
        </Member>
        <Member Name="Suspended">
          <Annotation Term="OData.Description" String="Data flow between the source and target elements has stopped. Writes to source element are held until the relationship is Resumed. "/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the data flow between the source and target elements has stopped. Writes to source element shall be held until the relationship is Resumed."/>
        </Member>
        <Member Name="Failedover">
          <Annotation Term="OData.Description" String="Reads and writes are sent to the target element. Source element is not reachable. "/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the reads and writes are sent to the target element. The source element may not be reachable."/>
        </Member>
        <Member Name="Prepared">
          <Annotation Term="OData.Description" String="Initialization is completed, however, the data flow has not started. "/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that initialization is completed, however, the data flow has not started."/>
        </Member>
        <Member Name="Aborted">
          <Annotation Term="OData.Description" String="The copy operation is aborted with the Abort operation. Use the Resync Replica operation to restart the copy operation. "/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the copy operation is aborted with the Abort operation. The Resync Replica operation can be used to restart the copy operation."/>
        </Member>
        <Member Name="Skewed">
          <Annotation Term="OData.Description" String="The target has been modified and is no longer synchronized with the source element or the point-in-time view. "/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the target has been modified and is no longer synchronized with the source element or the point-in-time view."/>
        </Member>
        <Member Name="Mixed">
          <Annotation Term="OData.Description" String="Applies to the ReplicaState of GroupSynchronized. It indicates the StorageSynchronized relationships of the elements in the groups have different ReplicaState values. "/>
          <Annotation
            Term="OData.LongDescription"
            String="This enumeration literal shall indicate the ReplicaState of GroupSynchronized. The value indicates the StorageSynchronized relationships of the elements in the group have different ReplicaState values."/>
        </Member>
        <Member Name="Partitioned">
          <Annotation Term="OData.Description" String="State of replication relationship can not be determined, for example, due to a connection problem. "/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the state of replication relationship can not be determined, for example, due to a connection problem."/>
        </Member>
        <Member Name="Invalid">
          <Annotation Term="OData.Description" String="The array is unable to determine the state of the replication relationship, for example, after the connection is restored; however, either source or target elements have an unknown status. "/>
          <Annotation
            Term="OData.LongDescription"
            String="This enumeration literal shall indicate that the storage server is unable to determine the state of the replication relationship, for example, after the connection is restored; however, either source or target elements have an unknown status."/>
        </Member>
        <Member Name="Restored">
          <Annotation Term="OData.Description" String="It indicates the source element was restored from the target element."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the source element was restored from the target element."/>
        </Member>
      </EnumType>

      <EnumType Name="ConsistencyType">
        <Annotation Term="OData.Description" String="The values of ConsistencyType indicates the consistency type used by the source and its associated target group."/>
        <Annotation Term="OData.LongDescription" String="ConsistencyType enumeration literals indicate the consistency type used by the source and its associated target group."/>
        <Member Name="SequentiallyConsistent">
          <Annotation Term="OData.Description" String="Sequentially consistent."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the source and target shall be sequentially consistent."/>
        </Member>
      </EnumType>

      <EnumType Name="ConsistencyState">
        <Annotation Term="OData.Description" String="The values of ConsistencyState indicate the consistency type used by the source and its associated target group."/>
        <Annotation Term="OData.LongDescription" String="ConsistencyState enumeration literals may be used to describe the consistency type used by the source and its associated target group."/>
        <Member Name="Consistent">
          <Annotation Term="OData.Description" String="Consistent."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the source and target shall be consistent."/>
        </Member>
        <Member Name="Inconsistent">
          <Annotation Term="OData.Description" String="Not consistent."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the source and target are not required to be consistent."/>
        </Member>
      </EnumType>

      <EnumType Name="ConsistencyStatus">
        <Annotation Term="OData.Description" String="The values of ConsistencyStatus indicate the current status of consistency. Consistency may have been disabled or might be experiencing an error condition."/>
        <Annotation Term="OData.LongDescription" String="ConsistencyStatus enumeration literals may be used to indicate the current status of consistency. Consistency may have been disabled or may be experiencing an error condition."/>
        <Member Name="Consistent">
          <Annotation Term="OData.Description" String="Consistent."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the source and target are consistent."/>
        </Member>
        <Member Name="InProgress">
          <Annotation Term="OData.Description" String="Becoming consistent."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the source and target are becoming consistent."/>
        </Member>
        <Member Name="Disabled">
          <Annotation Term="OData.Description" String="Consistency disabled."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the source and target have consistency disabled."/>
        </Member>
        <Member Name="InError">
          <Annotation Term="OData.Description" String="Consistency error."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the source and target are not consistent."/>
        </Member>
      </EnumType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="StorageReplicaInfo.v1_0_1">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="StorageReplicaInfo" BaseType="StorageReplicaInfo.v1_0_0.StorageReplicaInfo"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="StorageReplicaInfo.v1_1_0">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <Annotation Term="OData.Description" String="Enhance to track DataProtectionLineOfService LoS for each replicaInfo. Move ComplexType into unversioned namespace.Move enums into unversioned namespace. Change references to unversioned."/>
      <EntityType Name="StorageReplicaInfo" BaseType="StorageReplicaInfo.v1_0_1.StorageReplicaInfo"/>

      <ComplexType Name="ReplicaInfo" BaseType="StorageReplicaInfo.v1_0_0.ReplicaInfo">
        <NavigationProperty Name="DataProtectionLineOfService" Type="DataProtectionLineOfService.DataProtectionLineOfService">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="A collection of DataProtection lines of service elements."/>
          <Annotation Term="OData.LongDescription" String="The value shall be a set of data protection service options.  Within a class of service, one data protection service option shall be present for each replication session."/>
        </NavigationProperty>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="StorageReplicaInfo.v1_1_1">
      <Annotation Term="Redfish.OwningEntity" String="SNIA"/>
      <Annotation Term="OData.Description" String="This version was created to force the regeneration of JSON Schema so that OData properties are marked as required, and integer properties are marked as integer rather than number."/>
      <EntityType Name="StorageReplicaInfo" BaseType="StorageReplicaInfo.v1_1_0.StorageReplicaInfo"/>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_STORAGE_REPLICA_INFO_V1_HPP */
