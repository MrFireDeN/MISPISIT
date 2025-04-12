// Fill out your copyright notice in the Description page of Project Settings.


#include "CoR/CPP_DamageHandlerBASE.h"

UCPP_DamageHandlerBASE::UCPP_DamageHandlerBASE()
{
	
}

UCPP_DamageHandlerBASE::UCPP_DamageHandlerBASE(UCPP_DamageHandlerBASE* NextHandler)
{
	SetNextHandler(NextHandler);	
}

bool UCPP_DamageHandlerBASE::HandleDamage(FCPP_DamageData& DamageData)
{
	if (CanHandle(DamageData))
	{
		AppleEffects(DamageData);
		return NextHandler ? NextHandler->HandleDamage(DamageData) : true;
	}
	
	return false;
}

bool UCPP_DamageHandlerBASE::CanHandle(const FCPP_DamageData DamageData)
{
	return true;
}

void UCPP_DamageHandlerBASE::AppleEffects(FCPP_DamageData& DamageData)
{
	if (DamageData.IsValid())
	{
		AActor* HitActor = DamageData.HitResult.GetActor();
		if (HitActor != nullptr)
		{
			// HitActor->TakeDamage(DamageData.DamageAmount, DamageData.DamageTypeClass, DamageData.InstigatorController, DamageData.DamageCauser);
		}
	}
}

void UCPP_DamageHandlerBASE::SetNextHandler(UCPP_DamageHandlerBASE* Next)
{
	if (Next == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("NextHandler is NULL"));
		return;
	}
	
	NextHandler = Next;
}
