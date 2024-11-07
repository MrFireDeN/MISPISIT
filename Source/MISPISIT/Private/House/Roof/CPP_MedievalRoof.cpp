// Fill out your copyright notice in the Description page of Project Settings.


#include "House/Roof/CPP_MedievalRoof.h"


// Sets default values
ACPP_MedievalRoof::ACPP_MedievalRoof()
{
	Name = "Medieval Roof";

	// Asset paths
	RoofMeshAssetPath = "/Game/Project/Models/House/Roof/SM_MedievalRoof.SM_MedievalRoof";

	ACPP_Roof::InitializeMeshes();
}

// Called when the game starts or when spawned
void ACPP_MedievalRoof::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_MedievalRoof::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

