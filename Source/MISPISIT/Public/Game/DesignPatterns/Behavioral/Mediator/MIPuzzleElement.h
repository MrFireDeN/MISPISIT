﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MIPuzzleElement.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable, BlueprintType)
class UMIPuzzleElement : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MISPISIT_API IMIPuzzleElement
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Mediator")
	void RegisterWithMediator(class UMIPuzzleMediator* InMediator);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Mediator")
	void NotifyMediator(bool State);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Mediator")
	void ReceiveEvent(FName EventName);
};
