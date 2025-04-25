// MIHealthComponent.cpp

#include "Game/Gameplay/Components/MIHealthComponent.h"


UMIHealthComponent::UMIHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UMIHealthComponent::TakeDamage(const float Damage)
{
	if (IsDead() || Damage <= 0) return;
	
	const float NewHealth = FMath::Clamp(CurrentHealth - Damage, 0.f, MaxHealth);
	UpdateHealth(NewHealth);
	
	UE_LOG(LogTemp, Display, TEXT("Take Damage"));
}

void UMIHealthComponent::Heal(const float Amount)
{
	if (IsDead() || Amount <= 0) return;
	
	const float NewHealth = FMath::Clamp(CurrentHealth + Amount, 0.f, MaxHealth);
	UpdateHealth(NewHealth);
	
	UE_LOG(LogTemp, Display, TEXT("Heal"));
}

void UMIHealthComponent::InitializeComponent()
{
	Super::InitializeComponent();
	CurrentHealth = MaxHealth;
}

float UMIHealthComponent::UpdateHealth(const float NewHealth)
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

