// CPP_DoorPrototype.cpp

#include "Prototype/CPP_DoorPrototype.h"


// Sets default values
ACPP_DoorPrototype::ACPP_DoorPrototype()
{
	// Component creation and attachment
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DoorRoot"));
	DoorFrameMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrameMesh"));
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorFrameMesh->SetupAttachment(RootComponent);
	DoorMesh->SetupAttachment(DoorFrameMesh);

	// Door frame setup
	const FVector DoorFrameSize(30.0f);
	DoorFrameMesh->SetWorldScale3D(DoorFrameSize);

	// Door setup with relative scale and location
	const FVector DoorScale(1.0f / 30.0f);
	const FVector DoorLocation(94.94f / 30.0f, -4.97f / 30.0f, 0.0f);
	DoorMesh->SetRelativeScale3D(DoorScale);
	DoorMesh->SetRelativeLocation(DoorLocation);
	
	// DoorMeshAssetPaths
	DoorMeshAssetPaths.Add(Styles[0], "/Game/Project/Models/House/Doors/SM_MedievalDoor.SM_MedievalDoor");
	DoorMeshAssetPaths.Add(Styles[1], "/Game/Project/Models/House/Doors/SM_StoneDoor.SM_StoneDoor");
	DoorMeshAssetPaths.Add(Styles[2], "/Game/Project/Models/House/Doors/SM_BrickDoor.SM_BrickDoor");
	DoorMeshAssetPaths.Add(Styles[3], "/Game/Project/Models/House/Doors/SM_ModernDoor.SM_ModernDoor");
	
	// DoorFrameMeshAssetPaths
	DoorFrameMeshAssetPaths.Add(Styles[0], "/Game/Project/Models/House/Doors/SM_MedievalDoorFrame.SM_MedievalDoorFrame");
	DoorFrameMeshAssetPaths.Add(Styles[1], "/Game/Project/Models/House/Doors/SM_StoneDoorFrame.SM_StoneDoorFrame");
	DoorFrameMeshAssetPaths.Add(Styles[2], "/Game/Project/Models/House/Doors/SM_BrickDoorFrame.SM_BrickDoorFrame");
	DoorFrameMeshAssetPaths.Add(Styles[3], "/Game/Project/Models/House/Doors/SM_ModernDoorFrame.SM_ModernDoorFrame");

	SetStyle(CurrentStyle);
}

void ACPP_DoorPrototype::CopyPropertiesTo(ACPP_Prototype*& Target)
{
	if (Target == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Clone created from CPP_WallPrototype class"));
		
		Target =
			Target = GetWorld()->SpawnActor<ACPP_DoorPrototype>(ACPP_DoorPrototype::StaticClass(), this->GetActorLocation(), this->GetActorRotation());
	}

	if (IsOpen())
	{
		Cast<ACPP_DoorPrototype>(Target)->Toggle();
	}
	
	Super::CopyPropertiesTo(Target);
}

void ACPP_DoorPrototype::SetStyle(const FString Name)
{
	Super::SetStyle(Name);

	ACPP_BuildingComponent::LoadMeshFromAsset(DoorMesh, DoorMeshAssetPaths[CurrentStyle]);
	ACPP_BuildingComponent::LoadMeshFromAsset(DoorFrameMesh, DoorFrameMeshAssetPaths[CurrentStyle]);
}

void ACPP_DoorPrototype::Toggle()
{
	if (IsOpen())
	{
		// TODO
	}
	else
	{
		// TODO
	}
}

bool ACPP_DoorPrototype::IsOpen()
{
	return false;
}

