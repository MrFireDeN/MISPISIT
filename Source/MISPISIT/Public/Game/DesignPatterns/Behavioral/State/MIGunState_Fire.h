// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MIGunState.h"
#include "UObject/Object.h"
#include "MIGunState_Fire.generated.h"

/**
 * 
 */
UCLASS()
class MISPISIT_API UMIGunState_Fire : public UObject, public IMIGunState
{
	GENERATED_BODY()

public:
	virtual void StartFire_Implementation() override;
	virtual void StopFire_Implementation() override;
	virtual void Reload_Implementation() override;

protected:
	void TraceShoot();
};
