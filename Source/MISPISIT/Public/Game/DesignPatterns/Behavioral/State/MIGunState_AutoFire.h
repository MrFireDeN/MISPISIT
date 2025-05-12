// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MIGunState_Fire.h"
#include "MIGunState_AutoFire.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MISPISIT_API UMIGunState_AutoFire : public UMIGunState_Fire
{
	GENERATED_BODY()

public:
	virtual void StartFire_Implementation() override;
	virtual bool IsGunReady() override;
};
