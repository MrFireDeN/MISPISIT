// MIArmorDamageHandler.cpp

#include "Game/DesignPatterns/Behavioral/CoR/MIArmorDamageHandler.h"
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
	if (!ArmorComponent || DamageAmount <= 0.f)
	{
		return 0.f;
	}

	// ArmorComponent returns how much damage it actually absorbed
	const float AbsorbedDamage = ArmorComponent->TakeDamage(DamageAmount);
	return AbsorbedDamage;
}
