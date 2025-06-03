// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Game/Characters/MICharacterBase.h"
#include "MIEnemy.generated.h"

UCLASS()
class MISPISIT_API AMIEnemy : public AMICharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMIEnemy(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;

	virtual void HandleDeath_Implementation() override;
};
