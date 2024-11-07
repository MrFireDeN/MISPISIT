// Fill out your copyright notice in the Description page of Project Settings.


#include "House/Roof/CPP_StoneRoof.h"


// Sets default values
ACPP_StoneRoof::ACPP_StoneRoof()
{
	Name = "Stone Roof";

	// Asset paths
	RoofMeshAssetPath = "/Game/Project/Models/House/Roof/SM_StoneRoof.SM_StoneRoof";

	ACPP_Roof::InitializeMeshes();
}

// Called when the game starts or when spawned
void ACPP_StoneRoof::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_StoneRoof::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

