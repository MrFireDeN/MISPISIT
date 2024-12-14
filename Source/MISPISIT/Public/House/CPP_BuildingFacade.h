// CPP_BuildingFacade.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Factory/CPP_BrickBuildingFactory.h"
#include "Factory/CPP_MedievalBuildingFactory.h"
#include "Factory/CPP_ModernBuildingFactory.h"
#include "Factory/CPP_StoneBuildingFactory.h"
#include "CPP_BuildingFacade.generated.h"

UCLASS()
class MISPISIT_API ACPP_BuildingFacade : public AActor
{
	GENERATED_BODY()

public:
	ACPP_BuildingFacade();

protected:
	virtual void BeginPlay() override;

	TMap<FString, UCPP_BuildingFactory*> BuildingFactories;

public:
	UFUNCTION(BlueprintCallable, Category = "Building Facade")
	virtual void CreateHouse(const FString& Style, const FVector& Location);
	
	UFUNCTION(BlueprintCallable, Category = "Building Facade")
	virtual void DeleteAll();
	
	UFUNCTION(BlueprintCallable, Category = "Building Facade")
	virtual void UpdateHouse(const FString& Style, const FVector& Location);

private:
	TArray<AActor*> HouseParts;
	
	virtual TArray<AActor*> CreateWalls(UCPP_BuildingFactory* BuildingFactory, const FVector& Location);
	virtual TArray<AActor*> CreateWindows(UCPP_BuildingFactory* BuildingFactory, const FVector& Location);
};
