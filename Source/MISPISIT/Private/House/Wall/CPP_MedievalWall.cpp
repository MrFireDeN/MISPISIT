// Fill out your copyright notice in the Description page of Project Settings.


#include "House/Wall/CPP_MedievalWall.h"


// Sets default values
ACPP_MedievalWall::ACPP_MedievalWall()
{
	Name = "Medieval Wall";
	
	WallMeshTileAssetPath = "/Game/Project/Models/House/Walls/SM_MedievalWall_Tile.SM_MedievalWall_Tile";
	WallMeshCornerAssetPath = "/Game/Project/Models/House/Walls/SM_MedievalWall_Corner.SM_MedievalWall_Corner";
	WallMeshUpDoorAssetPath = "/Game/Project/Models/House/Walls/SM_MedievalWall_Door.SM_MedievalWall_Door";

	ACPP_Wall::InitializeMeshes();
}

// Called when the game starts or when spawned
void ACPP_MedievalWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_MedievalWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

