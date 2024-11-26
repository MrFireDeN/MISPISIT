// CPP_RoofPrototype.cpp

#include "Prototype/CPP_RoofPrototype.h"

ACPP_RoofPrototype::ACPP_RoofPrototype()
{
	// Init mesh
	RoofMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WindowMesh"));
	RootComponent = RoofMesh;
	
	// RoofMeshAssetPaths
	RoofMeshAssetPaths.Add(Styles[0], "/Game/Project/Models/House/Roof/SM_MedievalRoof.SM_MedievalRoof");
	RoofMeshAssetPaths.Add(Styles[2], "/Game/Project/Models/House/Roof/SM_StoneRoof.SM_StoneRoof");
	RoofMeshAssetPaths.Add(Styles[2], "/Game/Project/Models/House/Roof/SM_BrickRoof.SM_BrickRoof");
	RoofMeshAssetPaths.Add(Styles[3], "/Game/Project/Models/House/Roof/SM_ModernRoof.SM_ModernRoof");

	SetStyle(CurrentStyle);
}

void ACPP_RoofPrototype::CopyPropertiesTo(ACPP_Prototype*& Target)
{
	if (Target == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Clone created from CPP_WallPrototype class"));
		
		Target =
			Target = GetWorld()->SpawnActor<ACPP_RoofPrototype>(ACPP_RoofPrototype::StaticClass(), this->GetActorLocation(), this->GetActorRotation());
	}

	Target->SetActorScale3D(this->GetActorScale3D());
	
	Super::CopyPropertiesTo(Target);
}

void ACPP_RoofPrototype::SetStyle(const FString Name)
{
	Super::SetStyle(Name);

	ACPP_BuildingComponent::LoadMeshFromAsset(RoofMesh, RoofMeshAssetPaths[CurrentStyle]);
}

