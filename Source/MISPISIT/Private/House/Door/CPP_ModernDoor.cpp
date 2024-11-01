// CPP_ModernDoor.cpp

#include "House/Door/CPP_ModernDoor.h"

ACPP_ModernDoor::ACPP_ModernDoor()
{
	DoorMeshAssetPath = "/Game/Project/Models/House/Doors/SM_ModernDoor.SM_ModernDoor";
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

void ACPP_ModernDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_ModernDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

