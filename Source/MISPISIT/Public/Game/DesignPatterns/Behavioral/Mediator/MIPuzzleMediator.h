// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MIPuzzleMediator.generated.h"

class IMIPuzzleElement;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class MISPISIT_API UMIPuzzleMediator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Mediator")
	void RegisterElement(FName ElementID, const TScriptInterface<IMIPuzzleElement>& Element);

	UFUNCTION(BlueprintCallable, Category = "Mediator")
	void NotifyFrom(FName Name, bool State);

	UFUNCTION(BlueprintCallable, Category = "Mediator")
	void SendEventTo(FName ElementID, FName EventName);

private:
	UPROPERTY()
	TMap<FName, TScriptInterface<IMIPuzzleElement>> Elements;

	bool bButtonPressed = false;
};
