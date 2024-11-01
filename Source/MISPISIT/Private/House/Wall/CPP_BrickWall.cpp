// CPP_BrickWall.cpp

#include "House/Wall/CPP_BrickWall.h"


ACPP_BrickWall::ACPP_BrickWall()
{
	WallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallMesh"));
	RootComponent = WallMesh;

	const ConstructorHelpers::FObjectFinder<UStaticMesh>
		WallMeshAsset(TEXT("/Game/Megascans/3D_Assets/Modular_Building_Base_Wall_Kit_wdetchodw/S_Modular_Building_Base_Wall_Kit_wdetchodw_lod3_Var1.S_Modular_Building_Base_Wall_Kit_wdetchodw_lod3_Var1"));
	if (WallMeshAsset.Succeeded())
	{
		WallMesh->SetStaticMesh(WallMeshAsset.Object);
	}
}

void ACPP_BrickWall::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_BrickWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACPP_BrickWall::Initialize(FString WallType)
{
	Super::Initialize(WallType);
}

