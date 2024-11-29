// CPP_PrototypeRegistry.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_WallPrototype.h"
#include "CPP_DoorPrototype.h"
#include "CPP_RoofPrototype.h"
#include "CPP_WindowPrototype.h"
#include "CPP_PrototypeRegistry.generated.h"

UCLASS()
class MISPISIT_API ACPP_PrototypeRegistry : public AActor
{
	GENERATED_BODY()

public:
	ACPP_PrototypeRegistry();

	// Adds a prototype to the registry with the given name
	UFUNCTION(BlueprintCallable)
	virtual void Add(ACPP_Prototype* Prototype, FString Name);

	// Finds a prototype by name in the registry
	UFUNCTION(BlueprintCallable)
	virtual ACPP_Prototype* FindByName(FString Name) const;

	// Creates a new instance from the prototype identified by name
	UFUNCTION(BlueprintCallable)
	virtual ACPP_Prototype* Create(FString Name);

protected:
	// Default scene root component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	// Map for storing prototypes with their names as keys
	UPROPERTY()
	TMap<FString, ACPP_Prototype*> PrototypeRegistry;
};