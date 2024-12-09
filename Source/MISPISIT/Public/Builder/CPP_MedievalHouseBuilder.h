// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CPP_IHouseBuilder.h"
#include "../House/CPP_BuildingComponent.h"
#include "CPP_MedievalHouseBuilder.generated.h"

UCLASS()
class ACPP_MedievalHouse : public AActor
{
	GENERATED_BODY()
	
public:
	ACPP_MedievalHouse();

	TMap<FVector, UStaticMeshComponent*> Walls;
	TMap<FVector, UStaticMeshComponent*> Doors;
	TMap<FVector, UStaticMeshComponent*> Windows;
	TMap<FVector, UStaticMeshComponent*> Roofs;

	TMap<FString, FString> WallMeshAssetPaths;
	TMap<FString, FString> DoorMeshAssetPaths;
	TMap<FString, FString> WindowMeshAssetPaths;
	TMap<FString, FString> RoofMeshAssetPaths;
};

UCLASS()
class MISPISIT_API ACPP_MedievalHouseBuilder : public AActor, public ICPP_IHouseBuilder
{
	GENERATED_BODY()

public:
	ACPP_MedievalHouseBuilder();

protected:
	ACPP_MedievalHouse* MedievalHouse;

	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "HouseBuilder")
	bool SetWalls(int Length, int Width); virtual bool SetWalls_Implementation(int Length, int Width) override;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "HouseBuilder")
	bool SetDoors(int Count); virtual bool SetDoors_Implementation(int Count) override;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "HouseBuilder")
	bool SetWindows(int Count); virtual bool SetWindows_Implementation(int Count) override;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "HouseBuilder")
	bool SetRoof(int Height); virtual bool SetRoof_Implementation(int Height) override;
};
