// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Game/Gameplay/MIInteractableBase.h"
#include "MIPuzzleRemote.generated.h"

class IMIOriginator;
class IMIMemento;

UCLASS()
class MISPISIT_API AMIPuzzleRemote : public AMIInteractableBase
{
	GENERATED_BODY()

public:
	virtual bool OnPrimaryAction() override;
	virtual bool OnSecondaryAction() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Remote")
	TScriptInterface<IMIOriginator> Originator;

	UPROPERTY()
	TScriptInterface<IMIMemento> Memento;
};
