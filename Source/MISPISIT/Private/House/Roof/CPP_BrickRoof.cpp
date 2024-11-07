// Fill out your copyright notice in the Description page of Project Settings.


#include "House/Roof/CPP_BrickRoof.h"


// Sets default values
ACPP_BrickRoof::ACPP_BrickRoof()
{
	Name = "Brick Roof";

	// Asset paths
	RoofMeshAssetPath = "/Game/Project/Models/House/Roof/SM_BrickRoof.SM_BrickRoof";

	ACPP_Roof::InitializeMeshes();
}

// Called when the game starts or when spawned
void ACPP_BrickRoof::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_BrickRoof::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

