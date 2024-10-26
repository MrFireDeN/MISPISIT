#include "House/CPP_BuildingComponent.h"

ACPP_BuildingComponent::ACPP_BuildingComponent()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ACPP_BuildingComponent::BeginPlay()
{
	Super::BeginPlay();

	Spawn();
}

void ACPP_BuildingComponent::Spawn()
{
	FString SpawnText = "Spawned Component: " + Name;
	
	UKismetSystemLibrary::PrintString(this, SpawnText);
}

