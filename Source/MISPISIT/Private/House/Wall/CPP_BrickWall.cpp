// CPP_BrickWall.cpp

#include "House/Wall/CPP_BrickWall.h"


ACPP_BrickWall::ACPP_BrickWall()
{
	Name = "Brick Wall";
	
	WallMeshTileAssetPath = "/Game/Project/Models/House/Walls/SM_BrickWall_Tile.SM_BrickWall_Tile";
	WallMeshCornerAssetPath = "/Game/Project/Models/House/Walls/SM_BrickWall_Corner.SM_BrickWall_Corner";
	WallMeshUpDoorAssetPath = "/Game/Project/Models/House/Walls/SM_BrickWall_Door.SM_BrickWall_Door";

	ACPP_Wall::InitializeMeshes();
}

void ACPP_BrickWall::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_BrickWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

