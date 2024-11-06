// CPP_StoneDoor.cpp

#include "House/Door/CPP_StoneDoor.h"

ACPP_StoneDoor::ACPP_StoneDoor()
{
	
	// Asset paths
	DoorFrameMeshAssetPath = "/Game/Project/Models/House/Doors/SM_StoneDoorFrame.SM_StoneDoorFrame";
	DoorMeshAssetPath = "/Game/Project/Models/House/Doors/SM_StoneDoor.SM_StoneDoor";

	InitializeMeshes();
}

void ACPP_StoneDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_StoneDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

