// MIDamageHandler.cpp

#include "Game/DesignPatterns/Behavioral/CoR/MIDamageHandler.h"
#include "GameFramework/DamageType.h"

UMIDamageHandlerBase::UMIDamageHandlerBase() = default;

void UMIDamageHandlerBase::HandleDamage(float DamageAmount, const FDamageEvent& DamageEvent)
{
	if (CanHandle(DamageAmount, DamageEvent))
	{
		const float DamageProcessed = ApplyEffects(DamageAmount, DamageEvent);
		const float RemainingDamage = DamageAmount - DamageProcessed;

		if (RemainingDamage > KINDA_SMALL_NUMBER && NextHandler)
		{
			NextHandler->HandleDamage(RemainingDamage, DamageEvent);
		}
	}
	else if (NextHandler)
	{
		NextHandler->HandleDamage(DamageAmount, DamageEvent);
	}
}

void UMIDamageHandlerBase::SetNextHandler(const TScriptInterface<IMIDamageHandler>& Next)
{
	if (!Next)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] SetNextHandler: NextHandler is NULL"), *GetClass()->GetName());
		return;
	}

	NextHandler = Next;
}

bool UMIDamageHandlerBase::CanHandle(float DamageAmount, const FDamageEvent& DamageEvent)
{
	return DamageAmount > KINDA_SMALL_NUMBER;
}

float UMIDamageHandlerBase::ApplyEffects(float DamageAmount, const FDamageEvent& DamageEvent)
{
	// Default implementation applies nothing.
	return 0.f;
}
