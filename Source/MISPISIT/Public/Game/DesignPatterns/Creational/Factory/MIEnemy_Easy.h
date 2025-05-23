// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MIEnemy.h"
#include "MIEnemy_Easy.generated.h"

UCLASS()
class MISPISIT_API AMIEnemy_Easy : public AMIEnemy
{
	GENERATED_BODY()

public:
	AMIEnemy_Easy(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void InitializeDamageChain_Implementation() override;
};
