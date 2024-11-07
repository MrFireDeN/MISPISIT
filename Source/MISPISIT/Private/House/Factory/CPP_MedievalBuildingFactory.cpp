// CPP_MedievalBuildingFactory.cpp

#include "House/Factory/CPP_MedievalBuildingFactory.h"

UCPP_MedievalBuildingFactory::UCPP_MedievalBuildingFactory()
{
	
}

ACPP_Door* UCPP_MedievalBuildingFactory::CreateDoor(FTransform Transform)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	
	ACPP_Door* Door = GetWorld()->SpawnActor<ACPP_MedievalDoor>(ACPP_MedievalDoor::StaticClass(), Location, Rotation, SpawnParams);

	return Door;
}

ACPP_Roof* UCPP_MedievalBuildingFactory::CreateRoof(float Length, float Width)
{
	return Super::CreateRoof();
}

ACPP_Wall* UCPP_MedievalBuildingFactory::CreateWall(FTransform Transform, EWallType WallType)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();

	ACPP_Wall* Wall = GetWorld()->SpawnActor<ACPP_MedievalWall>(ACPP_MedievalWall::StaticClass(), Location, Rotation, SpawnParams);
	Wall->SetWallType(WallType);

	return Wall;
}

ACPP_Window* UCPP_MedievalBuildingFactory::CreateWindow(FTransform Transform)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	
	ACPP_Window* Window = GetWorld()->SpawnActor<ACPP_MedievalWindow>(ACPP_MedievalWindow::StaticClass(), Location, Rotation, SpawnParams);

	return Window;
}
