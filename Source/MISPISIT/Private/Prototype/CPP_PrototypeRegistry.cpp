// CPP_PrototypeRegistry.cpp

#include "Prototype/CPP_PrototypeRegistry.h"

ACPP_PrototypeRegistry::ACPP_PrototypeRegistry()
{
	// Create the SceneRoot component
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;
}

// Adds a prototype to the registry, using the prototype's actor label as its name
void ACPP_PrototypeRegistry::Add(ACPP_Prototype* Prototype)
{
	if (Prototype)
	{
		FString PrototypeName = Prototype->GetActorLabel();
		PrototypeRegistry.Add(PrototypeName, Prototype);
	}
}

// Finds a prototype by name in the registry
ACPP_Prototype* ACPP_PrototypeRegistry::FindByName(FString Name) const
{
	ACPP_Prototype* const* FoundPrototype = PrototypeRegistry.Find(Name);
	return FoundPrototype ? *FoundPrototype : nullptr;
}

// Creates a new instance from the prototype identified by name
ACPP_Prototype* ACPP_PrototypeRegistry::Create(FString Name)
{
	ACPP_Prototype* Prototype = FindByName(Name);
	if (Prototype)
	{
		// Clone the prototype and return the new instance
		return Prototype->Clone();
	}
	return nullptr;
}

void ACPP_PrototypeRegistry::BeginPlay()
{
	Super::BeginPlay();

	// Instantiate prototypes and add them to the registry

	// CPP_WallPrototype
	ACPP_WallPrototype* BrickWallPrototype = GetWorld()->SpawnActor<ACPP_WallPrototype>(ACPP_WallPrototype::StaticClass(), FVector::Zero(), FRotator::ZeroRotator);
	BrickWallPrototype->SetActorLabel("BrickWallPrototype");
	BrickWallPrototype->SetStyle("Brick");
	BrickWallPrototype->SetWallType(EWallType::ForWindow);
	Add(BrickWallPrototype);  // Add to registry

	// CPP_DoorPrototype
	ACPP_DoorPrototype* BrickDoorPrototype = GetWorld()->SpawnActor<ACPP_DoorPrototype>(ACPP_DoorPrototype::StaticClass(), FVector::Zero(), FRotator::ZeroRotator);
	BrickDoorPrototype->SetActorLabel("BrickDoorPrototype");
	BrickDoorPrototype->SetStyle("Brick");
	Add(BrickDoorPrototype);  // Add to registry

	// CPP_RoofPrototype
	ACPP_RoofPrototype* ModernRoofPrototype = GetWorld()->SpawnActor<ACPP_RoofPrototype>(ACPP_RoofPrototype::StaticClass(), FVector::Zero(), FRotator::ZeroRotator);
	ModernRoofPrototype->SetActorLabel("ModernRoofPrototype");
	ModernRoofPrototype->SetStyle("Modern");
	ModernRoofPrototype->SetActorScale3D(FVector(2, 1, 3));
	Add(ModernRoofPrototype);  // Add to registry

	// CPP_WindowPrototype
	ACPP_WindowPrototype* MedievalWindowPrototype = GetWorld()->SpawnActor<ACPP_WindowPrototype>(ACPP_WindowPrototype::StaticClass(), FVector::Zero(), FRotator::ZeroRotator);
	MedievalWindowPrototype->SetActorLabel("MedievalWindowPrototype");
	MedievalWindowPrototype->SetStyle("Medieval");
	Add(MedievalWindowPrototype);  // Add to registry

	// Example usage of Create method
	// Clone and place each prototype at a unique location
	if (ACPP_Prototype* ConcreteBrickWall = Create("BrickWallPrototype"))
	{
		ConcreteBrickWall->SetActorLocation(FVector(2500, 2900, 2000));
		ConcreteBrickWall->SetActorRotation(FRotator(0, 180, 0));
	}

	if (ACPP_Prototype* ConcreteBrickDoor = Create("BrickDoorPrototype"))
	{
		ConcreteBrickDoor->SetActorLocation(FVector(2400, 2900, 2000));
		ConcreteBrickDoor->SetActorRotation(FRotator(0, 180, 0));
	}

	if (ACPP_Prototype* ConcreteModernRoof = Create("ModernRoofPrototype"))
	{
		ConcreteModernRoof->SetActorLocation(FVector(2300, 2900, 2000));
		ConcreteModernRoof->SetActorRotation(FRotator(0, 180, 0));
	}

	if (ACPP_Prototype* ConcreteMedievalWindow = Create("MedievalWindowPrototype"))
	{
		ConcreteMedievalWindow->SetActorLocation(FVector(2500, 2900, 2000));
		ConcreteMedievalWindow->SetActorRotation(FRotator(0, 180, 0));
	}
}