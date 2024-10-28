// CPP_ModernDoor.cpp

#include "House/Door/CPP_ModernDoor.h"

ACPP_ModernDoor::ACPP_ModernDoor()
{
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	RootComponent = DoorMesh;
	
	const ConstructorHelpers::FObjectFinder<UStaticMesh>
		DoorMeshAsset(TEXT("/Game/Megascans/3D_Assets/Modular_Building_Door_vjrocebdw/S_Modular_Building_Door_vjrocebdw_lod3.S_Modular_Building_Door_vjrocebdw_lod3"));
	if (DoorMeshAsset.Succeeded())
	{
		DoorMesh->SetStaticMesh(DoorMeshAsset.Object);
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

