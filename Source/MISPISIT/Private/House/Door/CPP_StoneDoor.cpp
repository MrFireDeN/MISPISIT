// CPP_StoneDoor.cpp

#include "House/Door/CPP_StoneDoor.h"

ACPP_StoneDoor::ACPP_StoneDoor()
{
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	RootComponent = DoorMesh;
	
	const ConstructorHelpers::FObjectFinder<UStaticMesh>
		DoorMeshAsset(TEXT("/Game/Megascans/3D_Assets/Modular_Wooden_Door_xedsdifdw/S_Modular_Wooden_Door_xedsdifdw_lod3_Var1.S_Modular_Wooden_Door_xedsdifdw_lod3_Var1"));
	if (DoorMeshAsset.Succeeded())
	{
		DoorMesh->SetStaticMesh(DoorMeshAsset.Object);
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

