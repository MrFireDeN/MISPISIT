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

TArray<TScriptInterface<IMIDamageStrategy>> UMIHealthComponent::GetDamageStrategies_Implementation() const
{
	return DamageStrategies;
}

void UMIHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
}

float UMIHealthComponent::UpdateHealth(const float NewHealth)
{
	if (NewHealth != CurrentHealth)
	{
		CurrentHealth = NewHealth;
		OnHealthChanged.Broadcast(GetCurrentHealth(), GetMaxHealth());
		if (IsDead()) OnDeath.Broadcast();
	}

	return GetCurrentHealth();
}

