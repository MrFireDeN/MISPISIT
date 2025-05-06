// MIFireImmuneStrategy.cpp

#include "Game/DesignPatterns/Behavioral/Strategy/MIFireImmuneStrategy.h"
#include "Engine/DamageEvents.h"
#include "Game/Gameplay/DamageTypes/MIDamageType_Fire.h"


float UMIFireImmuneStrategy::ApplyDamage_Implementation(float DamageAmount, const FDamageEvent& DamageEvent)
{
	if (DamageEvent.DamageTypeClass && DamageEvent.DamageTypeClass->IsChildOf(UMIDamageType_Fire::StaticClass()))
	{
		return 0.f;
	}
	
	return DamageAmount;
}
