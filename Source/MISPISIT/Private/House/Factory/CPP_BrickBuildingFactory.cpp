// CPP_BrickBuildingFactory.cpp

#include "House/Factory/CPP_BrickBuildingFactory.h"

UCPP_BrickBuildingFactory::UCPP_BrickBuildingFactory()
{
}

ACPP_Door* UCPP_BrickBuildingFactory::CreateDoor(FTransform Transform)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = FVector(1200, 1200, 0);
	FRotator Rotation = FRotator(0, 90, 0);
	
	ACPP_Door* Door = GetWorld()->SpawnActor<ACPP_BrickDoor>(ACPP_BrickDoor::StaticClass(), Location, Rotation, SpawnParams);

	return Door;
}

ACPP_Roof* UCPP_BrickBuildingFactory::CreateRoof(float Length, float Width)
{
	return Super::CreateRoof(Length, Width);
}

ACPP_Wall* UCPP_BrickBuildingFactory::CreateWall(FTransform Transform, EWallType WallType)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();

	ACPP_Wall* Wall = GetWorld()->SpawnActor<ACPP_BrickWall>(ACPP_BrickWall::StaticClass(), Location, Rotation, SpawnParams);
	Wall->SetWallType(WallType);

	return Wall;
}

ACPP_Window* UCPP_BrickBuildingFactory::CreateWindow(float Width, float Height)
{
	return Super::CreateWindow(Width, Height);
}
