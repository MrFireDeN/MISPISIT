// CPP_PrototypeRegistry.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_WallPrototype.h"
#include "CPP_DoorPrototype.h"
#include "CPP_RoofPrototype.h"
#include "CPP_PrototypeRegistry.generated.h"

UCLASS()
class MISPISIT_API ACPP_PrototypeRegistry : public AActor
{
	GENERATED_BODY()

public:
	ACPP_PrototypeRegistry();

protected:
	virtual void BeginPlay() override;
	
	// The default scene root component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;
};