// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/State/MIGunState_SingleFire.h"
#include "Game/DesignPatterns/Behavioral/State/MIGunState_Idle.h"
#include "Game/Gameplay/Weapons/MIGun.h"

void UMIGunState_SingleFire::StartFire_Implementation()
{
	if (!IsGunReady()) return;

	CachedGun->Fire();

	CachedGun->GetWorld()->GetTimerManager().SetTimer(
		FireRateTimerHandle,
		[this]()
		{
			FireRateTimerHandle.Invalidate();
			Execute_StopFire(this);
		},
		1 / CachedGun->GetFireRate(),
		false);
}