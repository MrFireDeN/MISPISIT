// CPP_BrickDoor.cpp

#include "House/Door/CPP_BrickDoor.h"

ACPP_BrickDoor::ACPP_BrickDoor()
{
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	RootComponent = DoorMesh;
	
	const ConstructorHelpers::FObjectFinder<UStaticMesh>
		DoorMeshAsset(TEXT("/Game/Megascans/3D_Assets/Modular_Building_Door_wdhtajodw/S_Modular_Building_Door_wdhtajodw_lod3_Var1.S_Modular_Building_Door_wdhtajodw_lod3_Var1"));
	if (DoorMeshAsset.Succeeded())
	{
		DoorMesh->SetStaticMesh(DoorMeshAsset.Object);
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

