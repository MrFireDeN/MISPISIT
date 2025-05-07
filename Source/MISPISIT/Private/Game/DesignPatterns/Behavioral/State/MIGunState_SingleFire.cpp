// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/State/MIGunState_SingleFire.h"
#include "Game/DesignPatterns/Behavioral/State/MIGunState_Idle.h"
#include "Game/Gameplay/Weapons/MIGun.h"

void UMIGunState_SingleFire::StartFire_Implementation()
{
	AMIGun* Gun = Cast<AMIGun>(GetOuter());

	if (!IsValid(Gun))
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] StartFire: Gun is NOT valid"), *GetName());
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("[%s] Start Fire"), *GetName())
	
	//Gun->OnPrimaryAction();

	Execute_StopFire(this);
}

void UMIGunState_SingleFire::StopFire_Implementation()
{
	AMIGun* Gun = Cast<AMIGun>(GetOuter());

	if (!IsValid(Gun))
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] StartFire: Gun is NOT valid"), *GetName());
		return;
	}

	Gun->SetState(NewObject<UMIGunState_Idle>(Gun));

	UE_LOG(LogTemp, Log, TEXT("[%s] Stop Fire"), *GetName())
}

void UMIGunState_SingleFire::Reload_Implementation()
{
	IMIGunState::Reload_Implementation();
}
