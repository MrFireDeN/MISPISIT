// Fill out your copyright notice in the Description page of Project Settings.


#include "Builder/CPP_MedievalHouseBuilder.h"

ACPP_MedievalHouse::ACPP_MedievalHouse()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("HouseRoot"));

	// WallMeshAssetPaths
	WallMeshAssetPaths.Add("Default", "/Game/Project/Models/House/Walls/SM_MedievalWall_Tile.SM_MedievalWall_Tile");
	WallMeshAssetPaths.Add("Corner", "/Game/Project/Models/House/Walls/SM_MedievalWall_Corner.SM_MedievalWall_Corner");
	WallMeshAssetPaths.Add("ForDoor", "/Game/Project/Models/House/Walls/SM_MedievalWall_Door.SM_MedievalWall_Door");
	WallMeshAssetPaths.Add("ForWindow", "/Game/Project/Models/House/Walls/SM_MedievalWall_Window.SM_MedievalWall_Window");

	// DoorMeshAssetPaths
	DoorMeshAssetPaths.Add("Door", "/Game/Project/Models/House/Doors/SM_MedievalDoor.SM_MedievalDoor");
	DoorMeshAssetPaths.Add("Frame", "/Game/Project/Models/House/Doors/SM_MedievalDoorFrame.SM_MedievalDoorFrame");
	
	// WindowMeshAssetPaths
	WindowMeshAssetPaths.Add("Default", "/Game/Project/Models/House/Windows/SM_MedievalWindow.SM_MedievalWindow");;
	
	// RoofMeshAssetPaths
	RoofMeshAssetPaths.Add("Default", "/Game/Project/Models/House/Roof/SM_MedievalRoof.SM_MedievalRoof");
}

ACPP_MedievalHouseBuilder::ACPP_MedievalHouseBuilder()
{
	
}

bool ACPP_MedievalHouseBuilder::SetWalls_Implementation(int Length, int Width)
{
	if (Length < 2 || Width < 2)
	{
		UE_LOG(LogTemp, Log, TEXT("Incorrect Length or Width"));
		return false;
	}

	for (int I = 0; I < 4; ++I)
	{
		UStaticMeshComponent* WallCornerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallCorner"));
		WallCornerMesh->SetupAttachment(MedievalHouse->GetRootComponent());
		
		WallCornerMesh->SetRelativeRotation(FRotator(0, I*90, 0));

		FVector WallCornerLocation = FVector(0, 0, 0);
		
		switch (I)
		{
		case 1:
			WallCornerLocation.Set(Length*100, 0, 0);
			break;
		case 2:
			WallCornerLocation.Set(0, Width*100, 0);
			break;
		case 3:
			WallCornerLocation.Set(Length*100, Width*100, 0);
			break;
		}
		
		MedievalHouse->Walls.Add(WallCornerLocation);
		WallCornerMesh->SetRelativeLocation(WallCornerLocation);

		ACPP_BuildingComponent::LoadMeshFromAsset(WallCornerMesh, MedievalHouse->WallMeshAssetPaths.Find("Corner"));
	}
	
	/*
	for (int X = 0; X < Length; ++X)
	{
		
		
		for (int Y = 0; Y < Width; ++Y)
		{
			if (MedievalHouse->Walls.Contains(FVector(X*100, Y*100, 0)) == false)
			{
				UStaticMeshComponent* WallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallMesh"));
				WallMesh->SetupAttachment(MedievalHouse->GetRootComponent());
				WallMesh->SetRelativeLocation(FVector(X*100, Y*100, 0));
			
				MedievalHouse->Walls.Add(FVector(X*100, Y*100, 0), WallMesh);
			}
		}
	}
	*/
	
	return true;
}

bool ACPP_MedievalHouseBuilder::SetDoors_Implementation(int Count)
{
	return true;
}

bool ACPP_MedievalHouseBuilder::SetWindows_Implementation(int Count)
{
	return true;
}

bool ACPP_MedievalHouseBuilder::SetRoof_Implementation(int Height)
{
	return true;
}
