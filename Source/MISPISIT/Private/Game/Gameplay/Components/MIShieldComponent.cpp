// MIShieldComponent.cpp

#include "Game/Gameplay/Components/MIShieldComponent.h"
#include "TimerManager.h"


UMIShieldComponent::UMIShieldComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentShield = MaxShield;
}

void UMIShieldComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentShield = MaxShield;
}

float UMIShieldComponent::TakeDamage(float DamageAmount)
{
	if (IsDepleted() || DamageAmount <= 0.f)
		return 0.f;

	ResetRegen();

	const float DamageAbsorbed = FMath::Min(DamageAmount, CurrentShield);
	CurrentShield -= DamageAbsorbed;
	CurrentShield = FMath::Clamp(CurrentShield, 0.f, MaxShield);

	BroadcastShieldChange();
	StartRegenTimer();

	return DamageAbsorbed;
}

void UMIShieldComponent::StartRegenTimer()
{
	GetWorld()->GetTimerManager().SetTimer(RegenDelayTimerHandle, this, &UMIShieldComponent::RegenerateShield, RegenDelay, false);
}

void UMIShieldComponent::ResetRegen()
{
	GetWorld()->GetTimerManager().ClearTimer(RegenDelayTimerHandle);
	GetWorld()->GetTimerManager().ClearTimer(RegenTickTimerHandle);
}

void UMIShieldComponent::RegenerateShield()
{
	GetWorld()->GetTimerManager().SetTimer(RegenTickTimerHandle, [this]()
	{
	  CurrentShield = FMath::Clamp(CurrentShield + RegenRate * GetWorld()->GetDeltaSeconds(), 0.f, MaxShield);
	  BroadcastShieldChange();

	  if (CurrentShield >= MaxShield)
	  {
		GetWorld()->GetTimerManager().ClearTimer(RegenTickTimerHandle);
	  }

	}, GetWorld()->GetDeltaSeconds(), true);
}

void UMIShieldComponent::BroadcastShieldChange()
{
	OnShieldChanged.Broadcast(CurrentShield, MaxShield);
}
