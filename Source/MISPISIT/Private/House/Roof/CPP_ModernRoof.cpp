// Fill out your copyright notice in the Description page of Project Settings.


#include "House/Roof/CPP_ModernRoof.h"


// Sets default values
ACPP_ModernRoof::ACPP_ModernRoof()
{
	Name = "Modern Roof";

	// Asset paths
	RoofMeshAssetPath = "/Game/Project/Models/House/Roof/SM_ModernRoof.SM_ModernRoof";

	ACPP_Roof::InitializeMeshes();
}

// Called when the game starts or when spawned
void ACPP_ModernRoof::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_ModernRoof::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

