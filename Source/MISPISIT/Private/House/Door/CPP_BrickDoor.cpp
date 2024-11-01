// CPP_BrickDoor.cpp

#include "House/Door/CPP_BrickDoor.h"

ACPP_BrickDoor::ACPP_BrickDoor()
{
	DoorMeshAssetPath = "/Game/Project/Models/House/Doors/SM_BrickDoor.SM_BrickDoor";
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	RootComponent = DoorMesh;

	UStaticMesh* DoorMeshAsset = LoadObject<UStaticMesh>(nullptr, *DoorMeshAssetPath);
	if (DoorMeshAsset)
	{
		DoorMesh->SetStaticMesh(DoorMeshAsset);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load wall mesh asset at path: %s"), *DoorMeshAssetPath);
	}
}

void ACPP_BrickDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_BrickDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

