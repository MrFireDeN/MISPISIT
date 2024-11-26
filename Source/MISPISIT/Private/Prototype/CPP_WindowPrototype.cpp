// CPP_WindowPrototype.h

#include "Prototype/CPP_WindowPrototype.h"

ACPP_WindowPrototype::ACPP_WindowPrototype()
{
	WindowMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WindowMesh"));
	RootComponent = WindowMesh;
	
	// WindowMeshAssetPaths
	WindowMeshAssetPaths.Add(Styles[0], "/Game/Project/Models/House/Windows/SM_MedievalWindow.SM_MedievalWindow");
	WindowMeshAssetPaths.Add(Styles[2], "/Game/Project/Models/House/Windows/SM_StoneWindow.SM_StoneWindow");
	WindowMeshAssetPaths.Add(Styles[2], "/Game/Project/Models/House/Windows/SM_BrickWindow.SM_BrickWindow");
	WindowMeshAssetPaths.Add(Styles[3], "/Game/Project/Models/House/Windows/SM_ModernWindow.SM_ModernWindow");

	SetStyle(CurrentStyle);
}

void ACPP_WindowPrototype::CopyPropertiesTo(ACPP_Prototype*& Target)
{
	if (Target == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Clone created from CPP_WallPrototype class"));
		
		Target =
			Target = GetWorld()->SpawnActor<ACPP_WindowPrototype>(ACPP_WindowPrototype::StaticClass(), this->GetActorLocation(), this->GetActorRotation());
	}

	if (IsLightOn())
	{
		Cast<ACPP_WindowPrototype>(Target)->ToggleLight();
	}
	
	Super::CopyPropertiesTo(Target);
}

void ACPP_WindowPrototype::ToggleLight()
{
	if (IsLightOn())
	{
		// TODO
	}
	else
	{
		// TODO
	}
}

bool ACPP_WindowPrototype::IsLightOn()
{
	return false;
}

void ACPP_WindowPrototype::SetStyle(const FString Name)
{
	Super::SetStyle(Name);
	
	ACPP_BuildingComponent::LoadMeshFromAsset(WindowMesh, WindowMeshAssetPaths[CurrentStyle]);
}

