// Fill out your copyright notice in the Description page of Project Settings.


#include "House/Wall/CPP_ModernWall.h"


// Sets default values
ACPP_ModernWall::ACPP_ModernWall()
{
	Name = "Modern Wall";
	
	WallMeshTileAssetPath = "/Game/Project/Models/House/Walls/SM_ModernWall_Tile.SM_ModernWall_Tile";
	WallMeshCornerAssetPath = "/Game/Project/Models/House/Walls/SM_ModernWall_Corner.SM_ModernWall_Corner";
	WallMeshUpDoorAssetPath = "/Game/Project/Models/House/Walls/SM_ModernWall_Door.SM_ModernWall_Door";
	WallMeshForWindowAssetPath = "/Game/Project/Models/House/Walls/SM_ModernWall_Window.SM_ModernWall_Window";

	ACPP_Wall::InitializeMeshes();
}

// Called when the game starts or when spawned
void ACPP_ModernWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_ModernWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

