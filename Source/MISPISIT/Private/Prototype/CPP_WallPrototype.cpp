// CPP_WallPrototype.cpp

#include "Prototype/CPP_WallPrototype.h"

void ACPP_WallPrototype::CopyPropertiesTo(ACPP_Prototype*& Target)
{
	if (Target == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Clone created from CPP_WallPrototype class"));
		
		Target =
			Target = GetWorld()->SpawnActor<ACPP_WallPrototype>(ACPP_WallPrototype::StaticClass(), this->GetActorLocation(), this->GetActorRotation());
	}
	
	Cast<ACPP_WallPrototype>(Target)->SetWallType(this->WallType);
	
	Super::CopyPropertiesTo(Target);
}

ACPP_WallPrototype::ACPP_WallPrototype()
{
	// Init mesh
	WallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallMesh"));
	RootComponent = WallMesh;
	
	// WallMeshTile
	WallMeshTileAssetPaths.Add(Styles[0], "/Game/Project/Models/House/Walls/SM_MedievalWall_Tile.SM_MedievalWall_Tile");
	WallMeshTileAssetPaths.Add(Styles[1], "/Game/Project/Models/House/Walls/SM_StoneWall_Tile.SM_StoneWall_Tile");
	WallMeshTileAssetPaths.Add(Styles[2], "/Game/Project/Models/House/Walls/SM_BrickWall_Tile.SM_BrickWall_Tile");
	WallMeshTileAssetPaths.Add(Styles[3], "/Game/Project/Models/House/Walls/SM_ModernWall_Tile.SM_ModernWall_Tile");
	
	// WallMeshCorner
	WallMeshCornerAssetPaths.Add(Styles[0], "/Game/Project/Models/House/Walls/SM_MedievalWall_Corner.SM_MedievalWall_Corner");
	WallMeshCornerAssetPaths.Add(Styles[1], "/Game/Project/Models/House/Walls/SM_StoneWall_Corner.SM_StoneWall_Corner");
	WallMeshCornerAssetPaths.Add(Styles[2], "/Game/Project/Models/House/Walls/SM_BrickWall_Corner.SM_BrickWall_Corner");
	WallMeshCornerAssetPaths.Add(Styles[3], "/Game/Project/Models/House/Walls/SM_ModernWall_Corner.SM_ModernWall_Corner");
	
	// WallMeshUpDoor
	WallMeshUpDoorAssetPaths.Add(Styles[0], "/Game/Project/Models/House/Walls/SM_MedievalWall_Door.SM_MedievalWall_Door");
	WallMeshUpDoorAssetPaths.Add(Styles[1], "/Game/Project/Models/House/Walls/SM_StoneWall_Door.SM_StoneWall_Door");
	WallMeshUpDoorAssetPaths.Add(Styles[2], "/Game/Project/Models/House/Walls/SM_BrickWall_Door.SM_BrickWall_Door");
	WallMeshUpDoorAssetPaths.Add(Styles[3], "/Game/Project/Models/House/Walls/SM_ModernWall_Door.SM_ModernWall_Door");
	
	// WallMeshForWindow
	WallMeshForWindowAssetPaths.Add(Styles[0], "/Game/Project/Models/House/Walls/SM_MedievalWall_Window.SM_MedievalWall_Window");
	WallMeshForWindowAssetPaths.Add(Styles[1], "/Game/Project/Models/House/Walls/SM_StoneWall_Window.SM_StoneWall_Window");
	WallMeshForWindowAssetPaths.Add(Styles[2], "/Game/Project/Models/House/Walls/SM_BrickWall_Window.SM_BrickWall_Window");
	WallMeshForWindowAssetPaths.Add(Styles[3], "/Game/Project/Models/House/Walls/SM_ModernWall_Window.SM_ModernWall_Window");

	SetWallType(WallType);
}

void ACPP_WallPrototype::SetWallType(const EWallType NewWallType)
{
	this->WallType = NewWallType;

	switch (this->WallType)
	{
	case EWallType::Corner:
		ACPP_BuildingComponent::LoadMeshFromAsset(WallMesh, WallMeshCornerAssetPaths[CurrentStyle]);
		break;
		
	case EWallType::UpDoor:
		ACPP_BuildingComponent::LoadMeshFromAsset(WallMesh, WallMeshUpDoorAssetPaths[CurrentStyle]);
		break;
		
	case EWallType::ForWindow:
		ACPP_BuildingComponent::LoadMeshFromAsset(WallMesh, WallMeshForWindowAssetPaths[CurrentStyle]);
		break;

	default:
		ACPP_BuildingComponent::LoadMeshFromAsset(WallMesh, WallMeshTileAssetPaths[CurrentStyle]);
		break;
	}
}

void ACPP_WallPrototype::SetStyle(const FString Name)
{
	Super::SetStyle(Name);

	SetWallType(WallType);
}
