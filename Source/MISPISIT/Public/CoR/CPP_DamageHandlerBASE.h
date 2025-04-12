// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_FDamageData.h"
#include "UObject/Object.h"
#include "CPP_DamageHandlerBASE.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class MISPISIT_API UCPP_DamageHandlerBASE : public UObject
{
	GENERATED_BODY()

	UCPP_DamageHandlerBASE();
	UCPP_DamageHandlerBASE(UCPP_DamageHandlerBASE* NextHandler);

private:
	UPROPERTY()
	UCPP_DamageHandlerBASE* NextHandler;

public:
	virtual bool HandleDamage(FCPP_DamageData& DamageData);
	virtual bool CanHandle(const FCPP_DamageData DamageData);
	virtual void AppleEffects(FCPP_DamageData& DamageData);

	virtual void SetNextHandler(UCPP_DamageHandlerBASE* Next);
};
