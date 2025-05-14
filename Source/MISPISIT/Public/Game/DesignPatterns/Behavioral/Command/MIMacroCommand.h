// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MICommand.h"
#include "UObject/Object.h"
#include "MIMacroCommand.generated.h"

/**
 * 
 */
UCLASS()
class MISPISIT_API UMIMacroCommand : public UObject, public IMICommand
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Command")
	virtual void Execute_Implementation() override;

	UFUNCTION(BlueprintCallable, Category = "Command")
	virtual void Undo_Implementation() override;

	UFUNCTION(BlueprintCallable, Category = "Command")
	void AddCommand(TScriptInterface<IMICommand> NewCommand);

private:
	TArray<TScriptInterface<IMICommand>> Commands;
};
