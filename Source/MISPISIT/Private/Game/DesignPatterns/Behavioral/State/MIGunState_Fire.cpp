// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/State/MIGunState_Fire.h"
#include "Game/DesignPatterns/Behavioral/State/MIGunState_Idle.h"
#include "Game/DesignPatterns/Behavioral/State/MIGunState_Reload.h"
#include "Game/Gameplay/Weapons/MIGun.h"

void UMIGunState_Fire::StartFire_Implementation()
{
	if (!IsGunReady()) return;

	CachedGun->Fire();

	CachedGun->GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, [this]()
	{
		FireRateTimerHandle.Invalidate();
		Execute_StopFire(this);
	}, 1 / CachedGun.Get()->GetFireRate(), false);
}

void UMIGunState_Fire::StopFire_Implementation()
{
	if (!IsGunReady()) return;

	UE_LOG(LogTemp, Log, TEXT("[%s] Stop Fire"), *GetName())
	
	CachedGun->GetWorld()->GetTimerManager().ClearTimer(FireRateTimerHandle);
	CachedGun->ShotIndex = 0;
	CachedGun->SetState(NewObject<UMIGunState_Idle>(CachedGun));
}

void UMIGunState_Fire::Reload_Implementation()
{
	if (!IsGunReady()) return;
	
	CachedGun->SetState(NewObject<UMIGunState_Reload>(CachedGun));
	CachedGun->Reload();
}

bool UMIGunState_Fire::IsGunReady()
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

	return !CachedGun->GetWorld()->GetTimerManager().IsTimerActive(FireRateTimerHandle);
}
