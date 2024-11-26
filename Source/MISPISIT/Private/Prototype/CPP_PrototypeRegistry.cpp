// CPP_PrototypeRegistry.cpp

#include "Prototype/CPP_PrototypeRegistry.h"

ACPP_PrototypeRegistry::ACPP_PrototypeRegistry()
{
	// Create the SceneRoot component
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));

	// Set SceneRoot as the RootComponent of this actor
	RootComponent = SceneRoot;
}

// Called when the game starts or when spawned
void ACPP_PrototypeRegistry::BeginPlay()
{
	Super::BeginPlay();

	// CPP_WallPrototype
	ACPP_WallPrototype* BrickWallPrototype = GetWorld()->SpawnActor<ACPP_WallPrototype>(ACPP_WallPrototype::StaticClass(), FVector::Zero(), FRotator::ZeroRotator);
	BrickWallPrototype->SetActorLabel("BrickWallPrototype");
	BrickWallPrototype->SetStyle("Brick");
	BrickWallPrototype->SetWallType(EWallType::ForWindow);

	ACPP_Prototype* ConcreteBrickWall = BrickWallPrototype->Clone();
	ConcreteBrickWall->SetActorLocation(this->GetActorLocation());

	// CPP_DoorPrototype
	ACPP_DoorPrototype* BrickDoorPrototype = GetWorld()->SpawnActor<ACPP_DoorPrototype>(ACPP_DoorPrototype::StaticClass(), FVector::Zero(), FRotator::ZeroRotator);
	BrickDoorPrototype->SetActorLabel("BrickDoorPrototype");
	BrickDoorPrototype->SetStyle("Brick");

	ACPP_Prototype* ConcreteBrickDoor = BrickDoorPrototype->Clone();
	ConcreteBrickDoor->SetActorLocation(FVector(1100, 1000, 0));
}