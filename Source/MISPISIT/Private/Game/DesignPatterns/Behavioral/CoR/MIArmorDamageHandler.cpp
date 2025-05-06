// MIArmorDamageHandler.cpp

#include "Game/DesignPatterns/Behavioral/CoR/MIArmorDamageHandler.h"

#include "Game/DesignPatterns/Behavioral/Strategy/MIDamageStrategy.h"
#include "Game/Gameplay/Components/MIArmorComponent.h"


void UMIArmorDamageHandler::SetArmorComponent(UMIArmorComponent* InArmorComponent)
{
	if (!InArmorComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] ArmorComponent is null"), *GetName());
		return;
	}

	ArmorComponent = InArmorComponent;
}

float UMIArmorDamageHandler::ApplyEffects(float DamageAmount, const FDamageEvent& DamageEvent)
{
	if (!ArmorComponent) return 0.f;

	const auto StrategyProvider = Cast<IMIDamageStrategyProvider>(ArmorComponent);
	if (!StrategyProvider) return 0.f;

	float ModifiedDamage = DamageAmount;

	for (const auto& Strategy : StrategyProvider->GetDamageStrategies_Implementation())
	{
		if (Strategy)
		{
			ModifiedDamage = Strategy->ApplyDamage_Implementation(ModifiedDamage, DamageEvent);
		}
	}

	const float DamageDifference = DamageAmount - ModifiedDamage;
	
	const float AbsorbedDamage = ArmorComponent->TakeDamage(ModifiedDamage);
	return AbsorbedDamage + DamageDifference;
}
