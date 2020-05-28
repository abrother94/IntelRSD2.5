#ifndef PSME_REST_METADATA_METADATA_ROOT_HPP
#define PSME_REST_METADATA_METADATA_ROOT_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string metadata_root_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>

  <edmx:Reference Uri="/redfish/v1/metadata/ServiceRoot_v1.xml">
    <edmx:Include Namespace="ServiceRoot"/>
    <edmx:Include Namespace="ServiceRoot.v1_1_1"/>    
    <edmx:Include Namespace="ServiceRoot.v1_4_0"/>    
  </edmx:Reference>

  <edmx:Reference Uri="/redfish/v1/metadata/Resource_v1.xml">
    <edmx:Include Namespace="Resource"/>
  </edmx:Reference>
   
  <edmx:Reference Uri="/redfish/v1/metadata/IntelRackScaleOem_v1.xml">
    <edmx:Include Namespace="Intel.Oem"/>
  </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/ChassisCollection_v1.xml">
    <edmx:Include Namespace="ChassisCollection"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/Chassis_v1.xml">
    <edmx:Include Namespace="Chassis"/>
    <edmx:Include Namespace="Chassis.v1_2_0"/>
    <edmx:Include Namespace="Chassis.v1_3_0"/>   
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/Thermal_v1.xml">
    <edmx:Include Namespace="Thermal"/>
    <edmx:Include Namespace="Thermal.v1_1_0"/>    
   </edmx:Reference>  

   <edmx:Reference Uri="/redfish/v1/metadata/Power_v1.xml">
    <edmx:Include Namespace="Power"/>
    <edmx:Include Namespace="Power.v1_1_0"/>    
   </edmx:Reference>  

  <edmx:Reference Uri="/redfish/v1/metadata/ManagerCollection_v1.xml">
    <edmx:Include Namespace="ManagerCollection"/>
  </edmx:Reference>

  <edmx:Reference Uri="/redfish/v1/metadata/Manager_v1.xml">
    <edmx:Include Namespace="Manager"/>
    <edmx:Include Namespace="Manager.v1_0_0"/>    
  </edmx:Reference>

  <edmx:Reference Uri="/redfish/v1/metadata/ComputerSystem_v1.xml">
    <edmx:Include Namespace="ComputerSystem"/>
    <edmx:Include Namespace="ComputerSystem.v1_2_0"/>
    <edmx:Include Namespace="ComputerSystem.v1_3_0"/>
  </edmx:Reference>

  <edmx:Reference Uri="/redfish/v1/metadata/ComputerSystemCollection_v1.xml">
    <edmx:Include Namespace="ComputerSystemCollection"/>
  </edmx:Reference>

  <edmx:Reference Uri="/redfish/v1/metadata/MessageRegistryFileCollection_v1.xml">
    <edmx:Include Namespace="MessageRegistryFileCollection"/>
  </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/MessageRegistryFile_v1.xml">
    <edmx:Include Namespace="MessageRegistryFile"/>
    <edmx:Include Namespace="MessageRegistryFile.v1_0_0"/>    
    <edmx:Include Namespace="MessageRegistryFile.v1_1_0"/>    
   </edmx:Reference> 

   <edmx:Reference Uri="/redfish/v1/metadata/MemoryCollection_v1.xml">
    <edmx:Include Namespace="MemoryCollection"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/Memory_v1.xml">
    <edmx:Include Namespace="Memory"/>
    <edmx:Include Namespace="Memory.v1_1_0"/>    
   </edmx:Reference>
 
   <edmx:Reference Uri="/redfish/v1/metadata/StorageCollection_v1.xml">
    <edmx:Include Namespace="StorageCollection"/>
   </edmx:Reference> 

   <edmx:Reference Uri="/redfish/v1/metadata/Storage_v1.xml">
    <edmx:Include Namespace="Storage"/>
    <edmx:Include Namespace="Storage.v1_1_0"/>    
   </edmx:Reference> 

   <edmx:Reference Uri="/redfish/v1/metadata/Drive_v1.xml">
    <edmx:Include Namespace="Drive"/>
    <edmx:Include Namespace="Drive.v1_1_0"/>    
    <edmx:Include Namespace="Drive.v1_1_1"/>     
   </edmx:Reference> 

   <edmx:Reference Uri="/redfish/v1/metadata/VolumeCollection_v1.xml">
    <edmx:Include Namespace="VolumeCollection"/>
   </edmx:Reference> 

   <edmx:Reference Uri="/redfish/v1/metadata/ProcessorCollection_v1.xml">
    <edmx:Include Namespace="ProcessorCollection"/>
   </edmx:Reference> 
   
   <edmx:Reference Uri="/redfish/v1/metadata/Processor_v1.xml">
    <edmx:Include Namespace="Processor"/>
    <edmx:Include Namespace="Processor.v1_0_0"/>    
   </edmx:Reference>          

   <edmx:Reference Uri="/redfish/v1/metadata/EthernetInterfaceCollection_v1.xml">
    <edmx:Include Namespace="EthernetInterfaceCollection"/>
   </edmx:Reference>   

   <edmx:Reference Uri="/redfish/v1/metadata/EthernetInterface_v1.xml">
    <edmx:Include Namespace="EthernetInterface"/>
    <edmx:Include Namespace="EthernetInterface.v1_1_0"/>    
    <edmx:Include Namespace="EthernetInterface.v1_4_0"/>   
   </edmx:Reference> 

   <edmx:Reference Uri="/redfish/v1/metadata/SerialInterfaceCollection_v1.xml">
    <edmx:Include Namespace="SerialInterfaceCollection"/>
   </edmx:Reference>
 
   <edmx:Reference Uri="/redfish/v1/metadata/SerialInterface_v1.xml">
    <edmx:Include Namespace="SerialInterface"/>
    <edmx:Include Namespace="SerialInterface.v1_0_2"/>    
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/ManagerNetworkProtocol_v1.xml">
    <edmx:Include Namespace="ManagerNetworkProtocol"/> 
    <edmx:Include Namespace="ManagerNetworkProtocol.v1_0_2"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/LogServiceCollection_v1.xml">
    <edmx:Include Namespace="LogServiceCollection"/>
   </edmx:Reference>
   
   <edmx:Reference Uri="/redfish/v1/metadata/LogService_v1.xml">
    <edmx:Include Namespace="LogService"/>
    <edmx:Include Namespace="LogService.v1_0_0"/>
   </edmx:Reference> 

   <edmx:Reference Uri="/redfish/v1/metadata/LogEntryCollection_v1.xml">
    <edmx:Include Namespace="LogEntryCollection"/>
   </edmx:Reference> 

   <edmx:Reference Uri="/redfish/v1/metadata/LogEntry_v1.xml">
    <edmx:Include Namespace="LogEntry"/>
    <edmx:Include Namespace="LogEntry.v1_0_0"/>
   </edmx:Reference> 

   <edmx:Reference Uri="/redfish/v1/metadata/SessionCollection_v1.xml">
    <edmx:Include Namespace="SessionCollection"/>
   </edmx:Reference> 

   <edmx:Reference Uri="/redfish/v1/metadata/SessionService_v1.xml">
    <edmx:Include Namespace="SessionService"/>
    <edmx:Include Namespace="SessionService.v1_0_0"/>
    <edmx:Include Namespace="SessionService.v1_1_2"/>
   </edmx:Reference> 

   <edmx:Reference Uri="/redfish/v1/metadata/EventService_v1.xml">
    <edmx:Include Namespace="EventService"/>
    <edmx:Include Namespace="EventService.v1_0_0"/>    
    <edmx:Include Namespace="EventService.v1_0_2"/>    
   </edmx:Reference>   

   <edmx:Reference Uri="/redfish/v1/metadata/EventDestination_v1.xml">
    <edmx:Include Namespace="EventDestination"/>
    <edmx:Include Namespace="EventDestination.v1_0_0"/>    
   </edmx:Reference>   

   <edmx:Reference Uri="/redfish/v1/metadata/EventDestinationCollection_v1.xml">
    <edmx:Include Namespace="EventDestinationCollection"/>
   </edmx:Reference>   

   <edmx:Reference Uri="/redfish/v1/metadata/AccountService_v1.xml">
    <edmx:Include Namespace="AccountService"/>
    <edmx:Include Namespace="AccountService.v1_0_0"/>    
    <edmx:Include Namespace="AccountService.v1_3_0"/>    
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/ManagerAccountCollection_v1.xml">
    <edmx:Include Namespace="ManagerAccountCollection"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/ManagerAccount_v1.xml">
    <edmx:Include Namespace="ManagerAccount"/>
    <edmx:Include Namespace="ManagerAccount.v1_0_0"/>
    <edmx:Include Namespace="ManagerAccount.v1_1_0"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/RoleCollection_v1.xml">
    <edmx:Include Namespace="RoleCollection"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/Role_v1.xml">
    <edmx:Include Namespace="Role"/>
    <edmx:Include Namespace="Role.v1_0_0"/>    
    <edmx:Include Namespace="Role.v1_2_1"/>    
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/Session_v1.xml">
    <edmx:Include Namespace="Session"/>
    <edmx:Include Namespace="Session.v1_0_0"/>    
   </edmx:Reference>
   
   <edmx:Reference Uri="/redfish/v1/metadata/EthernetSwitchCollection_v1.xml">  
   <edmx:Include Namespace="EthernetSwitchCollection"/> 
   </edmx:Reference>
   
   <edmx:Reference Uri="/redfish/v1/metadata/EthernetSwitch_v1.xml">  
   <edmx:Include Namespace="EthernetSwitch.v1_0_0"/> 
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/EthernetSwitchPortCollection_v1.xml">
    <edmx:Include Namespace="EthernetSwitchPortCollection"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/EthernetSwitchPort_v1.xml">
    <edmx:Include Namespace="EthernetSwitchPort"/>  
    <edmx:Include Namespace="EthernetSwitchPort.v1_0_0"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/EthernetSwitchACLCollection_v1.xml">
    <edmx:Include Namespace="EthernetSwitchACLCollection"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/VLanNetworkInterfaceCollection_v1.xml">
    <edmx:Include Namespace="VLanNetworkInterfaceCollection"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/EthernetSwitchStaticMACCollection_v1.xml">
    <edmx:Include Namespace="EthernetSwitchStaticMACCollection"/>
   </edmx:Reference>  

   <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions_v1.xml">
     <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
   </edmx:Reference>   

   <edmx:Reference Uri="/redfish/v1/metadata/PrivilegeRegistry_v1.xml">
    <edmx:Include Namespace="PrivilegeRegistry"/>
    <edmx:Include Namespace="PrivilegeRegistry.v1_0_0"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/FabricCollection_v1.xml">
    <edmx:Include Namespace="FabricCollection"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/TelemetryService_v1.xml">
    <edmx:Include Namespace="TelemetryService"/>
    <edmx:Include Namespace="TelemetryService.v1_0_0"/>
    <edmx:Include Namespace="TelemetryService.v1_1_0"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/ActionInfo_v1.xml">
    <edmx:Include Namespace="ActionInfo"/>
    <edmx:Include Namespace="ActionInfo.v1_0_0"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/StorageServiceCollection_v1.xml">
    <edmx:Include Namespace="StorageServiceCollection"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/StorageService_v1.xml">
    <edmx:Include Namespace="StorageService"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/UpdateService_v1.xml">
    <edmx:Include Namespace="UpdateService"/>
    <edmx:Include Namespace="UpdateService.v1_0_0"/>
    <edmx:Include Namespace="UpdateService.v1_1_0"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/TaskCollection_v1.xml">
    <edmx:Include Namespace="TaskCollection"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/TaskService_v1.xml">
    <edmx:Include Namespace="TaskService"/>
    <edmx:Include Namespace="TaskService.v1_0_0"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/MetricDefinitionCollection_v1.xml">
    <edmx:Include Namespace="MetricDefinitionCollection"/>
   </edmx:Reference>

   <edmx:Reference Uri="/redfish/v1/metadata/MessageRegistry_v1.xml">
    <edmx:Include Namespace="MessageRegistry"/>
    <edmx:Include Namespace="MessageRegistry.v1_0_0"/>
   </edmx:Reference>

  <edmx:DataServices>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Service">
      <EntityContainer Name="Service" Extends="ServiceRoot.v1_0_0.ServiceContainer">
        <Annotation Term="OData.Description" String="Default Entity Container"/>
      </EntityContainer>
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>

)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_METADATA_ROOT_HPP */
