// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/State/MIGunState_AutoFire.h"

#include "Game/Gameplay/Weapons/MIGun.h"

void UMIGunState_AutoFire::StartFire_Implementation()
{
	if (!IsGunReady()) return;

	CachedGun->GetWorld()->GetTimerManager().SetTimer(
		FireRateTimerHandle,
		[this]()
		{
			CachedGun->Fire();
		},
		1 / CachedGun->GetFireRate(),
		true,
		0.f);
}

bool UMIGunState_AutoFire::IsGunReady()
{
	if (!IsValid(CachedGun))
	{
		CachedGun = Cast<AMIGun>(GetOuter());
	}

	if (!IsValid(CachedGun))
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] Reload: Gun is NOT valid"), *GetName());
		return false;
	}

	return true;
}
