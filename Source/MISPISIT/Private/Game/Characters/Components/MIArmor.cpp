// MIArmor.cpp

#include "Game/Characters/Components/MIArmor.h"


UMIArmor::UMIArmor()
{
	
}

float UMIArmor::TakeDamage(const float Damage)
{
	if (IsBroken() || Damage <= 0) return 0.f;

	const float AppliedDamage = FMath::Min(Damage, CurrentArmor);
	const float NewArmor = FMath::Clamp(CurrentArmor - Damage, 0.f, MaxArmor);
	
	UpdateArmor(NewArmor);

	return AppliedDamage;
}

void UMIArmor::BeginPlay()
{
	Super::BeginPlay();
	CurrentArmor = MaxArmor;
}

float UMIArmor::UpdateArmor(const float NewArmor)
{
	if (NewArmor != CurrentArmor)
	{
		CurrentArmor = NewArmor;
		OnArmorChanged.Broadcast(CurrentArmor, MaxArmor);
	}

	return CurrentArmor;
}
