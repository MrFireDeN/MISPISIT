// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CPP_Interactable.h"
#include "InteractebleHelper.generated.h"

/**
 * 
 */
UCLASS()
class MISPISIT_API UInteractebleHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, Category = "Interacteble")
	static void CallOnPrimaryAction(AActor* Target);
	
	UFUNCTION(BlueprintCallable, Category = "Interacteble")
	static void CallOnSecondaryAction(AActor* Target);
	
	UFUNCTION(BlueprintCallable, Category = "Interacteble")
	static void CallOnNumericAction(AActor* Target, const int Digit);
	
	UFUNCTION(BlueprintCallable, Category = "Interacteble")
	static void CallOnCustomKeyAction(AActor* Target, const FKey Key);
};
