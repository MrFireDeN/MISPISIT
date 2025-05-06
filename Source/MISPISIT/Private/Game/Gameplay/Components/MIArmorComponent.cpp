// MIArmorComponent.cpp

#include "Game/Gameplay/Components/MIArmorComponent.h"
#include "Game/Characters/Components/MIArmor.h"
#include "Game/DesignPatterns/Behavioral/Strategy/MIDamageStrategy.h"


UMIArmorComponent::UMIArmorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UMIArmorComponent::TakeDamage(const float Damage)
{
	float RemainingDamage = Damage;
	float TotalAbsorbed = 0;
	
	for (auto Armor : Armors)
	{
		if (!Armor || Armor->IsBroken()) continue;

		const float Absorbed = Armor->TakeDamage(RemainingDamage);
		
		if (Armor->IsBroken()) RemoveArmor(Armor);
		
		TotalAbsorbed += Absorbed;
		RemainingDamage -= Absorbed;

		if (RemainingDamage <= 0) break;
	}

	if (TotalAbsorbed > 0) OnArmorsChanged.Broadcast(Armors);
	
	return TotalAbsorbed;
}

void UMIArmorComponent::AddArmor(UMIArmor* NewArmor)
{
	if (!NewArmor || Armors.Contains(NewArmor)) return;
	Armors.Add(NewArmor);

	OnArmorsChanged.Broadcast(Armors);
}

void UMIArmorComponent::RemoveArmor(UMIArmor* NewArmor)
{
	Armors.Remove(NewArmor);

	OnArmorsChanged.Broadcast(Armors);
}

TArray<TScriptInterface<IMIDamageStrategy>> UMIArmorComponent::GetDamageStrategies_Implementation() const
{
	TArray<TScriptInterface<IMIDamageStrategy>> DamageStrategies;

	for (const auto& Armor : Armors)
	{
		if (IsValid(Armor) && Armor->DamageStrategy.GetInterface())
		{
			DamageStrategies.Add(Armor->DamageStrategy);
		}
	}
	
	return DamageStrategies;
}
