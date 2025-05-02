// UMIShieldDamageHandler.cpp

#include "Game/DesignPatterns/Behavioral/CoR/MIShieldDamageHandler.h"
#include "Game/Gameplay/Components/MIShieldComponent.h"

UMIShieldDamageHandler::UMIShieldDamageHandler()
{
	ShieldComponent = nullptr;
}

void UMIShieldDamageHandler::SetShieldComponent(UMIShieldComponent* InShieldComponent)
{
	if (!InShieldComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] ShieldComponent is nullptr."), *GetName());
		return;
	}

	ShieldComponent = InShieldComponent;
}

float UMIShieldDamageHandler::ApplyEffects(float DamageAmount, const FDamageEvent& DamageEvent)
{
	if (!ShieldComponent || ShieldComponent->IsDepleted())
	{
		return 0.f;
	}

	// Apply damage to the shield
	const float Absorbed = ShieldComponent->TakeDamage(DamageAmount);
	return Absorbed;
}
