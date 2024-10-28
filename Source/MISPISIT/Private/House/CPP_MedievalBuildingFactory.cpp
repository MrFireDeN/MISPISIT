// CPP_MedievalBuildingFactory.cpp

#include "House/CPP_MedievalBuildingFactory.h"

UCPP_MedievalBuildingFactory::UCPP_MedievalBuildingFactory()
{
	
}

ACPP_Door* UCPP_MedievalBuildingFactory::CreateDoor(UWorld* World, float Width, float Height)
{
	return Super::CreateDoor(World);
}

ACPP_Roof* UCPP_MedievalBuildingFactory::CreateRoof(UWorld* World, float Length, float Width)
{
	return Super::CreateRoof(World);
}

ACPP_Wall* UCPP_MedievalBuildingFactory::CreateWall(UWorld* World, float Length, float Width, float Height)
{
	return Super::CreateWall(World);
}

ACPP_Window* UCPP_MedievalBuildingFactory::CreateWindow(UWorld* World, float Width, float Height)
{
	return Super::CreateWindow(World);
}
