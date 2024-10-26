#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetSystemLibrary.h"
#include "CPP_BuildingComponent.generated.h"

UCLASS()
class MISPISIT_API ACPP_BuildingComponent : public AActor
{
	GENERATED_BODY()
	
public:
	ACPP_BuildingComponent();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	FString Name = "BuildingComponent";

public:
	UFUNCTION(BlueprintCallable)
	virtual void Spawn();
};
