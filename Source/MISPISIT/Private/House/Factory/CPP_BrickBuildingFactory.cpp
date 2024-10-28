// CPP_BrickBuildingFactory.cpp

#include "House/Factory/CPP_BrickBuildingFactory.h"

UCPP_BrickBuildingFactory::UCPP_BrickBuildingFactory()
{
}

ACPP_Door* UCPP_BrickBuildingFactory::CreateDoor(float Width, float Height)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = FVector(1200, 1200, 0);
	FRotator Rotation = FRotator(0, 90, 0);

	
	ACPP_Door* Door = GetWorld()->SpawnActor<ACPP_BrickDoor>(ACPP_BrickDoor::StaticClass(), Location, Rotation, SpawnParams);
	Door->Spawn();

	return Door;
}

ACPP_Roof* UCPP_BrickBuildingFactory::CreateRoof(float Length, float Width)
{
	return Super::CreateRoof(Length, Width);
}

ACPP_Wall* UCPP_BrickBuildingFactory::CreateWall(float Length, float Width, float Height)
{
	return Super::CreateWall(Length, Width, Height);
}

ACPP_Window* UCPP_BrickBuildingFactory::CreateWindow(float Width, float Height)
{
	return Super::CreateWindow(Width, Height);
}
