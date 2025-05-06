// MIBulletDamageStrategy.cpp

#include "Game/DesignPatterns/Behavioral/Strategy/MIBulletDamageStrategy.h"
#include "Engine/DamageEvents.h"
#include "Game/Gameplay/DamageTypes/MIDamageType_Bullet.h"


float UMIBulletDamageStrategy::ApplyDamage_Implementation(float DamageAmount, const FDamageEvent& DamageEvent)
{
	if (DamageEvent.DamageTypeClass && DamageEvent.DamageTypeClass->IsChildOf(UMIDamageType_Bullet::StaticClass()))
	{
		return DamageAmount * DamageModifier;
	}
	
	return DamageAmount;
}
