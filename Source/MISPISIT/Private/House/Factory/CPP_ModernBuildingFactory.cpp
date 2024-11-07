// Fill out your copyright notice in the Description page of Project Settings.

#include "House/Factory/CPP_ModernBuildingFactory.h"

UCPP_ModernBuildingFactory::UCPP_ModernBuildingFactory()
{
}

ACPP_Door* UCPP_ModernBuildingFactory::CreateDoor(FTransform Transform)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();

	
	ACPP_Door* Door = GetWorld()->SpawnActor<ACPP_ModernDoor>(ACPP_ModernDoor::StaticClass(), Location, Rotation, SpawnParams);

	return Door;
}

ACPP_Roof* UCPP_ModernBuildingFactory::CreateRoof(FTransform Transform)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	FVector Scale3d = Transform.GetScale3D();
	
	ACPP_Roof* Roof = GetWorld()->SpawnActor<ACPP_ModernRoof>(ACPP_ModernRoof::StaticClass(), Location, Rotation, SpawnParams);
	Roof->SetActorScale3D(Scale3d);

	return Roof;
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

ACPP_Window* UCPP_ModernBuildingFactory::CreateWindow(FTransform Transform)
{
	FActorSpawnParameters SpawnParams;
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	
	ACPP_Window* Window = GetWorld()->SpawnActor<ACPP_ModernWindow>(ACPP_ModernWindow::StaticClass(), Location, Rotation, SpawnParams);

	return Window;
}
