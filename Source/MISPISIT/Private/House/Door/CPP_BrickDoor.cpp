// CPP_BrickDoor.cpp

#include "House/Door/CPP_BrickDoor.h"

ACPP_BrickDoor::ACPP_BrickDoor()
{
	// Asset paths
	DoorFrameMeshAssetPath = "/Game/Project/Models/House/Doors/SM_BrickDoorFrame.SM_BrickDoorFrame";
	DoorMeshAssetPath = "/Game/Project/Models/House/Doors/SM_BrickDoor.SM_BrickDoor";

	InitializeMeshes();
}

void ACPP_BrickDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_BrickDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

