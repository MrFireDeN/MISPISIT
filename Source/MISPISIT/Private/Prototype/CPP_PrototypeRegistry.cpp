// CPP_PrototypeRegistry.cpp

#include "Prototype/CPP_PrototypeRegistry.h"

ACPP_PrototypeRegistry::ACPP_PrototypeRegistry()
{
	// Create the SceneRoot component
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;
}

// Adds a prototype to the registry, using the prototype's actor label as its name
void ACPP_PrototypeRegistry::Add(ACPP_Prototype* Prototype, FString Name)
{
	if (Prototype)
	{
		PrototypeRegistry.Add(Name, Prototype);
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