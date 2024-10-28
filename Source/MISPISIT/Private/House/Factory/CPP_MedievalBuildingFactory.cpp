// CPP_MedievalBuildingFactory.cpp

#include "House/Factory/CPP_MedievalBuildingFactory.h"

UCPP_MedievalBuildingFactory::UCPP_MedievalBuildingFactory()
{
	
}

ACPP_Door* UCPP_MedievalBuildingFactory::CreateDoor(float Width, float Height)
{
	// if (!World)
	// {
	// 	return nullptr;
	// }

	FActorSpawnParameters SpawnParams;
	FVector Location = FVector(1200, 1200, 0);
	FRotator Rotation = FRotator(0, 90, 0);

	
	ACPP_Door* Door = GetWorld()->SpawnActor<ACPP_MedievalDoor>(ACPP_MedievalDoor::StaticClass(), Location, Rotation, SpawnParams);
	Door->Spawn();

	return Door;
}

ACPP_Roof* UCPP_MedievalBuildingFactory::CreateRoof(float Length, float Width)
{
	return Super::CreateRoof();
}

ACPP_Wall* UCPP_MedievalBuildingFactory::CreateWall(float Length, float Width, float Height)
{
	return Super::CreateWall();
}

ACPP_Window* UCPP_MedievalBuildingFactory::CreateWindow(float Width, float Height)
{
	return Super::CreateWindow();
}
