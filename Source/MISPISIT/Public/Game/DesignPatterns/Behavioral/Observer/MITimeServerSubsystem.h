﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "MITimeServerSubsystem.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MISPISIT_API UMITimeServerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Observer")
	void Start();

	UFUNCTION(BlueprintCallable, Category = "Observer")
	void Stop();

	UFUNCTION(BlueprintCallable, Category = "Observer")
	void Subscribe(UObject* Observer);

	UFUNCTION(BlueprintCallable, Category = "Observer")
	void Unsubscribe(UObject* Observer);

private:
	UPROPERTY()
	int32 TimeState = 0;

	UPROPERTY()
	FTimerHandle TimerHandle;

	UPROPERTY()
	TArray<TWeakObjectPtr<UObject>> Observers;

	void NotifyObservers();
};
