// CPP_MedievalDoor.cpp

#include "House/Door/CPP_MedievalDoor.h"

// Sets default values
ACPP_MedievalDoor::ACPP_MedievalDoor()
{
	DoorMeshAssetPath = "/Game/Project/Models/House/Doors/SM_MedievalDoor.SM_MedievalDoor";
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

void ACPP_MedievalDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_MedievalDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

