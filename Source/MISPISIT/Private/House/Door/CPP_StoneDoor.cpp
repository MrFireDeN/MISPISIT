// CPP_StoneDoor.cpp

#include "House/Door/CPP_StoneDoor.h"

ACPP_StoneDoor::ACPP_StoneDoor()
{
	DoorMeshAssetPath = "/Game/Project/Models/House/Doors/SM_StoneDoor.SM_StoneDoor";
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

void ACPP_StoneDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_StoneDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

