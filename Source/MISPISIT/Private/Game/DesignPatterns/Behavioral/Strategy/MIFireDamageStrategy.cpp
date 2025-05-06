// MIFireDamageStrategy.cpp

#include "Game/DesignPatterns/Behavioral/Strategy/MIFireDamageStrategy.h"
#include "Engine/DamageEvents.h"
#include "Game/Gameplay/DamageTypes/MIDamageType_Fire.h"


float UMIFireDamageStrategy::ApplyDamage_Implementation(float DamageAmount, const FDamageEvent& DamageEvent)
{
	if (DamageEvent.DamageTypeClass && DamageEvent.DamageTypeClass->IsChildOf(UMIDamageType_Fire::StaticClass()))
	{
		return DamageAmount * DamageModifier;
	}
	
	return DamageAmount;
}
