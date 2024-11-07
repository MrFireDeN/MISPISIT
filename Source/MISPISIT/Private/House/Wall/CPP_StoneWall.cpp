// Fill out your copyright notice in the Description page of Project Settings.


#include "House/Wall/CPP_StoneWall.h"


// Sets default values
ACPP_StoneWall::ACPP_StoneWall()
{
	Name = "Stone Wall";
	
	WallMeshTileAssetPath = "/Game/Project/Models/House/Walls/SM_StoneWall_Tile.SM_StoneWall_Tile";
	WallMeshCornerAssetPath = "/Game/Project/Models/House/Walls/SM_StoneWall_Corner.SM_StoneWall_Corner";
	WallMeshUpDoorAssetPath = "/Game/Project/Models/House/Walls/SM_StoneWall_Door.SM_StoneWall_Door";

	ACPP_Wall::InitializeMeshes();
}

// Called when the game starts or when spawned
void ACPP_StoneWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_StoneWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

