// CPP_Wall.cpp

#include "House/CPP_Wall.h"

void ACPP_Wall::InitializeMeshes()
{
 WallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallMesh"));
 RootComponent = WallMesh;
 
 SetWallType(WallType);
}

void ACPP_Wall::SetWallType(const EWallType NewWallType)
{
 this->WallType = NewWallType;

 switch (this->WallType)
 {
 case EWallType::Corner:
  LoadMeshFromAsset(WallMesh, WallMeshCornerAssetPath);
  break;
		
 case EWallType::UpDoor:
  LoadMeshFromAsset(WallMesh, WallMeshUpDoorAssetPath);
  break;
		
 case EWallType::ForWindow:
  LoadMeshFromAsset(WallMesh, WallMeshForWindowAssetPath);
  break;

 default:
  LoadMeshFromAsset(WallMesh, WallMeshTileAssetPath);
  break;
 }
}
