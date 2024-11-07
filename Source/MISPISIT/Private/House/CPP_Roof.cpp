// CPP_Roof.cpp

#include "House/CPP_Roof.h"

/**
 * @file CPP_Roof.cpp
 * 
 * Implementation file for ACPP_Roof. Currently, this file only includes the header for ACPP_Roof,
 * as all functionality is defined by the properties that represent the roof's dimensions.
 * Additional behavior and functionality for ACPP_Roof can be implemented here as needed.
 */
void ACPP_Roof::InitializeMeshes()
{
 RoofMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WindowMesh"));
 RootComponent = RoofMesh;

 LoadMeshFromAsset(RoofMesh, RoofMeshAssetPath);
}
