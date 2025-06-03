// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "MIShootingRangeSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChangedSignature, int32, Score);

/**
 * 
 */
UCLASS(BlueprintType)
class MISPISIT_API UMIShootingRangeSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnScoreChangedSignature OnScoreChanged;
	
	UFUNCTION(BlueprintCallable, Category="Shooting Range")
	void Start();

	UFUNCTION(BlueprintCallable, Category="Shooting Range")
	void Stop();

	UFUNCTION(BlueprintCallable, Category="Shooting Range")
	void AddScore();

	UFUNCTION(BlueprintPure, Category="Shooting Range")
	bool IsPlaying() const { return bIsPlaying; }

private:
	UPROPERTY()
	int32 Score = 0;

	UPROPERTY()
	bool bIsPlaying = false;
};
