// CPP_BrickBuildingFactory.cpp

#include "House/Factory/CPP_BrickBuildingFactory.h"

#include "Math/TransformCalculus3D.h"

UCPP_BrickBuildingFactory::UCPP_BrickBuildingFactory()
{
}

ACPP_Door* UCPP_BrickBuildingFactory::CreateDoor(FTransform Transform)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	
	ACPP_Door* Door = GetWorld()->SpawnActor<ACPP_BrickDoor>(ACPP_BrickDoor::StaticClass(), Location, Rotation, SpawnParams);

	return Door;
}

ACPP_Roof* UCPP_BrickBuildingFactory::CreateRoof(FTransform Transform)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	FVector Scale3d = Transform.GetScale3D();
	
	ACPP_Roof* Roof = GetWorld()->SpawnActor<ACPP_BrickRoof>(ACPP_BrickRoof::StaticClass(), Location, Rotation, SpawnParams);
	Roof->SetActorScale3D(Scale3d);

	return Roof;
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

ACPP_Window* UCPP_BrickBuildingFactory::CreateWindow(FTransform Transform)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	
	ACPP_Window* Window = GetWorld()->SpawnActor<ACPP_BrickWindow>(ACPP_BrickWindow::StaticClass(), Location, Rotation, SpawnParams);

	return Window;
}
