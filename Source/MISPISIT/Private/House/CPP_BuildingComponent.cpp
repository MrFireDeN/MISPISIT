// CPP_BuildingComponent.cpp

#include "House/CPP_BuildingComponent.h"

/**
 * @brief Constructor that disables the primary actor's ticking behavior.
 */
ACPP_BuildingComponent::ACPP_BuildingComponent()
{
	PrimaryActorTick.bCanEverTick = false;
}

/**
 * @brief Initializes the component and calls the Spawn function.
 * 
 * Overrides the BeginPlay function to print a message when the component is initialized.
 */
void ACPP_BuildingComponent::BeginPlay()
{
	Super::BeginPlay();

	Spawn();
}

/**
 * @brief Prints a message indicating that the component has been spawned.
 * 
 * Concatenates "Spawned Component: " with the component’s name and outputs it to the screen.
 */
void ACPP_BuildingComponent::Spawn()
{
	FString SpawnText = "Spawned Component: " + Name;
	
	UKismetSystemLibrary::PrintString(this, SpawnText);
}

bool ACPP_BuildingComponent::LoadMeshFromAsset(UStaticMeshComponent* Mesh, FString AssetPath)
{
	UStaticMesh* MeshAsset = LoadObject<UStaticMesh>(nullptr, *AssetPath);
	if (MeshAsset)
	{
		Mesh->SetStaticMesh(MeshAsset);
		return true;
	}

	UE_LOG(LogTemp, Warning, TEXT("Failed to load mesh asset at path: %s"), *AssetPath);
	return false;
}
