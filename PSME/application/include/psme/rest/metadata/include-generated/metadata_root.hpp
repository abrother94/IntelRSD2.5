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
    <edmx:Include Namespace="ServiceRoot.v1_3_1"/>
    <edmx:Include Namespace="ServiceRoot.v1_1_1"/>
    <edmx:Include Namespace="ServiceRoot"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/IntelRackScaleOem_v1.xml">
    <edmx:Include Namespace="Intel.Oem"/>
  </edmx:Reference>


  <edmx:DataServices>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Service">
      <EntityContainer Name="Service" Extends="ServiceRoot.v1_1_1.ServiceContainer">
        <Annotation Term="OData.Description" String="Default Entity Container."/>
      </EntityContainer>
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>

)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_METADATA_ROOT_HPP */
