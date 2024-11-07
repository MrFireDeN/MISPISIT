// CPP_ModernDoor.cpp

#include "House/Door/CPP_ModernDoor.h"

ACPP_ModernDoor::ACPP_ModernDoor()
{
	Name = "Modern Door";
	
	// Asset paths
	DoorFrameMeshAssetPath = "/Game/Project/Models/House/Doors/SM_ModernDoorFrame.SM_ModernDoorFrame";
	DoorMeshAssetPath = "/Game/Project/Models/House/Doors/SM_ModernDoor.SM_ModernDoor";

	ACPP_Door::InitializeMeshes();
}

void ACPP_ModernDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_ModernDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

