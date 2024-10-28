// CPP_MedievalDoor.cpp

#include "House/Door/CPP_MedievalDoor.h"

// Sets default values
ACPP_MedievalDoor::ACPP_MedievalDoor()
{
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	RootComponent = DoorMesh;
	
	const ConstructorHelpers::FObjectFinder<UStaticMesh> DoorMeshAsset(TEXT("/Game/Megascans/3D_Assets/Medieval_Modular_Wall_ucskcaehx/S_Medieval_Modular_Wall_ucskcaehx_lod3_Var1.S_Medieval_Modular_Wall_ucskcaehx_lod3_Var1"));
	if (DoorMeshAsset.Succeeded())
	{
		DoorMesh->SetStaticMesh(DoorMeshAsset.Object);
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

