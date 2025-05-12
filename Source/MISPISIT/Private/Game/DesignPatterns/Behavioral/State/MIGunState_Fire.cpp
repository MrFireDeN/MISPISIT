// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/State/MIGunState_Fire.h"
#include "Game/DesignPatterns/Behavioral/State/MIGunState_Idle.h"
#include "Game/DesignPatterns/Behavioral/State/MIGunState_Reload.h"
#include "Game/Gameplay/Weapons/MIGun.h"

void UMIGunState_Fire::StartFire_Implementation()
{
	AMIGun* Gun = Cast<AMIGun>(GetOuter());

	if (!IsValid(Gun))
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] StartFire: Gun is NOT valid"), *GetName());
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("[%s] Start Fire"), *GetName())
	
	TraceShoot();

	Execute_StopFire(this);
}

void UMIGunState_Fire::StopFire_Implementation()
{
	AMIGun* Gun = Cast<AMIGun>(GetOuter());

	if (!IsValid(Gun))
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] StopFire: Gun is NOT valid"), *GetName());
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("[%s] Stop Fire"), *GetName())

	Gun->SetState(NewObject<UMIGunState_Idle>(Gun));
}

void UMIGunState_Fire::Reload_Implementation()
{
	AMIGun* Gun = Cast<AMIGun>(GetOuter());

	if (!IsValid(Gun))
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] Reload: Gun is NOT valid"), *GetName());
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("[%s] Reload"), *GetName())
	
	Gun->SetState(NewObject<UMIGunState_Reload>(Gun));
	Gun->Reload();
}

void UMIGunState_Fire::TraceShoot()
{
	UE_LOG(LogTemp, Log, TEXT("[%s] TraceShoot: Shoot"), *GetName());
}
