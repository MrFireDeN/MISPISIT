﻿// CPP_MedievalDoor.cpp

#include "House/Door/CPP_MedievalDoor.h"

// Sets default values
ACPP_MedievalDoor::ACPP_MedievalDoor()
{
    Name = "Medieval Door";
	
	// Asset paths
	DoorFrameMeshAssetPath = "/Game/Project/Models/House/Doors/SM_MedievalDoorFrame.SM_MedievalDoorFrame";
	DoorMeshAssetPath = "/Game/Project/Models/House/Doors/SM_MedievalDoor.SM_MedievalDoor";

	ACPP_Door::InitializeMeshes();
}

void ACPP_MedievalDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_MedievalDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

