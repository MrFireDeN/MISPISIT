// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/State/MIGunState_Fire.h"
#include "Game/DesignPatterns/Behavioral/State/MIGunState_Idle.h"
#include "Game/DesignPatterns/Behavioral/State/MIGunState_Reload.h"
#include "Game/Gameplay/Weapons/MIGun.h"

void UMIGunState_Fire::StartFire_Implementation()
{
	if (!IsValid(CachedGun))
	{
		CachedGun = Cast<AMIGun>(GetOuter());
	}

	if (!IsValid(CachedGun))
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] StartFire: Gun is NOT valid"), *GetName());
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("[%s] Start Fire"), *GetName())

	const bool bIsAuto = CachedGun->GetFireMode() == EFireMode::Auto ||
						 CachedGun->GetFireMode() == EFireMode::Burst;

	CachedGun->RemainingBurstShots = CachedGun->GetBurstShotsCount();
	
	CachedGun->GetWorld()->GetTimerManager().SetTimer(
		FireRateTimerHandle,
		this,
		&UMIGunState_Fire::TraceShoot,
		1 / CachedGun->GetFireRate(),
		bIsAuto,
		0.f);
}

void UMIGunState_Fire::StopFire_Implementation()
{
	if (!IsValid(CachedGun))
	{
		CachedGun = Cast<AMIGun>(GetOuter());
	}

	if (!IsValid(CachedGun))
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] StopFire: Gun is NOT valid"), *GetName());
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("[%s] Stop Fire"), *GetName())

	CachedGun->GetWorld()->GetTimerManager().ClearTimer(FireRateTimerHandle);
	CachedGun->SetState(NewObject<UMIGunState_Idle>(CachedGun));
}

void UMIGunState_Fire::Reload_Implementation()
{
	if (!IsValid(CachedGun))
	{
		CachedGun = Cast<AMIGun>(GetOuter());
	}

	if (!IsValid(CachedGun))
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] Reload: Gun is NOT valid"), *GetName());
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("[%s] Reload"), *GetName())
	
	CachedGun->SetState(NewObject<UMIGunState_Reload>(CachedGun));
	CachedGun->Reload();
}

void UMIGunState_Fire::TraceShoot()
{
	if (!IsValid(CachedGun))
	{
		Execute_StopFire(this);
		return;
	}
	
	UE_LOG(LogTemp, Log, TEXT("[%s] TraceShoot: Shoot"), *GetName());

	if (CachedGun->GetFireMode() == EFireMode::Burst)
	{
		CachedGun->RemainingBurstShots--;

		if (CachedGun->RemainingBurstShots <= 0)
		{
			Execute_StopFire(this);
		}
	}
}
