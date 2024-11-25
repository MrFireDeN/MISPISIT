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

	ACPP_WallPrototype* BrickWallPrototype = GetWorld()->SpawnActor<ACPP_WallPrototype>(ACPP_WallPrototype::StaticClass(), FVector::Zero(), FRotator::ZeroRotator);
	BrickWallPrototype->SetActorLabel("BrickWallPrototype");
	BrickWallPrototype->SetStyle("Brick");
	BrickWallPrototype->SetWallType(EWallType::ForWindow);

	ACPP_Prototype* ConcreteBrickWall = BrickWallPrototype->Clone();
	ConcreteBrickWall->SetActorLocation(this->GetActorLocation());
}