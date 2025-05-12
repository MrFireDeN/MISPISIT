// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/State/MIGunState_BurstFire.h"

#include "Game/Gameplay/Weapons/MIGun.h"

void UMIGunState_BurstFire::StartFire_Implementation()
{
	if (!IsGunReady()) return;

	CachedGun->RemainingBurstShots = CachedGun->GetBurstShotsCount();

	CachedGun->GetWorld()->GetTimerManager().SetTimer(
		FireRateTimerHandle,
		[this]()
		{
			CachedGun->Fire();

			CachedGun->RemainingBurstShots--;

			if (CachedGun->RemainingBurstShots <= 0)
			{
				CachedGun->GetWorld()->GetTimerManager().ClearTimer(FireRateTimerHandle);
				CachedGun->GetWorld()->GetTimerManager().SetTimer(
					FireRateTimerHandle,
					[this]()
					{
						FireRateTimerHandle.Invalidate();
						Execute_StopFire(this);
					},
					2 / CachedGun->GetFireRate(),
					false);
			}
		},
		1 / CachedGun->GetFireRate(),
		true,
		0.f);
}
