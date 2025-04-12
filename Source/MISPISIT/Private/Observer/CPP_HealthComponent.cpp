// CPP_HealthComponent.cpp

#include "Observer/CPP_HealthComponent.h"

UCPP_HealthComponent::UCPP_HealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentHealth = MaxHealth;
}

void UCPP_HealthComponent::TakeDamage(const float Damage)
{
	if (IsDead() || Damage <= 0) return;
	
	const float NewHealth = FMath::Clamp(CurrentHealth - Damage, 0.f, MaxHealth);
	UpdateHealth(NewHealth);
	
	UE_LOG(LogTemp, Display, TEXT("Take Damage"));
}

void UCPP_HealthComponent::Heal(const float Amount)
{
	if (IsDead() || Amount <= 0) return;
	
	const float NewHealth = FMath::Clamp(CurrentHealth + Amount, 0.f, MaxHealth);
	UpdateHealth(NewHealth);
	
	UE_LOG(LogTemp, Display, TEXT("Heal"));
	
}

float UCPP_HealthComponent::UpdateHealth(const float NewHealth)
{
	const bool bHealthChanged = NewHealth != CurrentHealth;
	CurrentHealth = NewHealth;

	if (bHealthChanged)
	{
		OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);
		if (IsDead()) OnDeath.Broadcast();
	}

	return CurrentHealth;
}
