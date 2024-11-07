// Fill out your copyright notice in the Description page of Project Settings.

#include "House/Factory/CPP_ModernBuildingFactory.h"

UCPP_ModernBuildingFactory::UCPP_ModernBuildingFactory()
{
}

ACPP_Door* UCPP_ModernBuildingFactory::CreateDoor(FTransform Transform)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = FVector(1200, 1200, 0);
	FRotator Rotation = FRotator(0, 90, 0);

	
	ACPP_Door* Door = GetWorld()->SpawnActor<ACPP_ModernDoor>(ACPP_ModernDoor::StaticClass(), Location, Rotation, SpawnParams);

	return Door;
}

ACPP_Roof* UCPP_ModernBuildingFactory::CreateRoof(float Length, float Width)
{
	return Super::CreateRoof(Length, Width);
}

ACPP_Wall* UCPP_ModernBuildingFactory::CreateWall(FTransform Transform, EWallType WallType)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();

	ACPP_Wall* Wall = GetWorld()->SpawnActor<ACPP_ModernWall>(ACPP_ModernWall::StaticClass(), Location, Rotation, SpawnParams);
	Wall->SetWallType(WallType);

	return Wall;
}

ACPP_Window* UCPP_ModernBuildingFactory::CreateWindow(float Width, float Height)
{
	return Super::CreateWindow(Width, Height);
}
