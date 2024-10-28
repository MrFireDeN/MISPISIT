// Fill out your copyright notice in the Description page of Project Settings.

#include "House/Factory/CPP_ModernBuildingFactory.h"

UCPP_ModernBuildingFactory::UCPP_ModernBuildingFactory()
{
}

ACPP_Door* UCPP_ModernBuildingFactory::CreateDoor(float Width, float Height)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = FVector(1200, 1200, 0);
	FRotator Rotation = FRotator(0, 90, 0);

	
	ACPP_Door* Door = GetWorld()->SpawnActor<ACPP_ModernDoor>(ACPP_ModernDoor::StaticClass(), Location, Rotation, SpawnParams);
	Door->Spawn();

	return Door;
}

ACPP_Roof* UCPP_ModernBuildingFactory::CreateRoof(float Length, float Width)
{
	return Super::CreateRoof(Length, Width);
}

ACPP_Wall* UCPP_ModernBuildingFactory::CreateWall(float Length, float Width, float Height)
{
	return Super::CreateWall(Length, Width, Height);
}

ACPP_Window* UCPP_ModernBuildingFactory::CreateWindow(float Width, float Height)
{
	return Super::CreateWindow(Width, Height);
}
