// CPP_BrickWall.cpp

#include "House/Wall/CPP_BrickWall.h"


ACPP_BrickWall::ACPP_BrickWall()
{
	WallMeshAssetPath = "/Game/Project/Models/House/Walls/SM_BrickWall.SM_BrickWall";
	WallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallMesh"));
	RootComponent = WallMesh;

	UStaticMesh* WallMeshAsset = LoadObject<UStaticMesh>(nullptr, *WallMeshAssetPath);
	if (WallMeshAsset)
	{
		WallMesh->SetStaticMesh(WallMeshAsset);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load wall mesh asset at path: %s"), *WallMeshAssetPath);
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

