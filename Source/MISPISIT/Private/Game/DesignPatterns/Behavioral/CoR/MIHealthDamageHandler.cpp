// MIHealthDamageHandler.cpp

#include "Game/DesignPatterns/Behavioral/CoR/MIHealthDamageHandler.h"
#include "Engine/DamageEvents.h"
#include "Game/Gameplay/Components/MIHealthComponent.h"
#include "Game/Gameplay/DamageTypes/MIDamageType_Bullet.h"

UMIHealthDamageHandler::UMIHealthDamageHandler() = default;

void UMIHealthDamageHandler::SetHealthComponent(UMIHealthComponent* HealthComp)
{
	if (!ensureMsgf(HealthComp, TEXT("[%s] SetHealthComponent: Provided component is null."), *GetClass()->GetName()))
	{
		return;
	}

	HealthComponent = HealthComp;
}

float UMIHealthDamageHandler::ApplyEffects(float DamageAmount, const FDamageEvent& DamageEvent)
{
	if (!HealthComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] ApplyEffects: No HealthComponent set."), *GetClass()->GetName());
		return 0.f;
	}

	// TODO: Apply DamageType-based modifiers here (fire, acid, DOTs, etc.)

	float AppliedDamage = FMath::Min(DamageAmount, HealthComponent->GetCurrentHealth());

	/*
	if (DamageEvent.DamageTypeClass && DamageEvent.DamageTypeClass->IsChildOf(UMIDamageType_Bullet::StaticClass()))
	{
		AppliedDamage *= 0.1f;
	}
	*/
		
	HealthComponent->TakeDamage(AppliedDamage);
	return AppliedDamage;
}
