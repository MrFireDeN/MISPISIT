// Fill out your copyright notice in the Description page of Project Settings.

#include "House/Factory/CPP_StoneBuildingFactory.h"

UCPP_StoneBuildingFactory::UCPP_StoneBuildingFactory()
{
}

ACPP_Door* UCPP_StoneBuildingFactory::CreateDoor(FTransform Transform)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	
	ACPP_Door* Door = GetWorld()->SpawnActor<ACPP_StoneDoor>(ACPP_StoneDoor::StaticClass(), Location, Rotation, SpawnParams);

	return Door;
}

ACPP_Roof* UCPP_StoneBuildingFactory::CreateRoof(FTransform Transform)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	FVector Scale3d = Transform.GetScale3D();
	
	ACPP_Roof* Roof = GetWorld()->SpawnActor<ACPP_StoneRoof>(ACPP_StoneRoof::StaticClass(), Location, Rotation, SpawnParams);
	Roof->SetActorScale3D(Scale3d);

	return Roof;
}

ACPP_Wall* UCPP_StoneBuildingFactory::CreateWall(FTransform Transform, EWallType WallType)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();

	ACPP_Wall* Wall = GetWorld()->SpawnActor<ACPP_StoneWall>(ACPP_StoneWall::StaticClass(), Location, Rotation, SpawnParams);
	Wall->SetWallType(WallType);
	
	return Wall;
}

ACPP_Window* UCPP_StoneBuildingFactory::CreateWindow(FTransform Transform)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	
	ACPP_Window* Window = GetWorld()->SpawnActor<ACPP_StoneWindow>(ACPP_StoneWindow::StaticClass(), Location, Rotation, SpawnParams);

	return Window;
}
