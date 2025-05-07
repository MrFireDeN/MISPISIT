// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/State/MIGunState_Idle.h"
#include "Game/DesignPatterns/Behavioral/State/MIGunState_SingleFire.h"
#include "Game/Gameplay/Weapons/MIGun.h"

void UMIGunState_Idle::StartFire_Implementation()
{
	AMIGun* Gun = Cast<AMIGun>(GetOuter());

	if (!IsValid(Gun))
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] StartFire: Gun is NOT valid"), *GetName());
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("[%s] Start Fire"), *GetName())

	Gun->SetState(NewObject<UMIGunState_SingleFire>(Gun));
	Gun->StartFire();
}

void UMIGunState_Idle::StopFire_Implementation()
{
	IMIGunState::StopFire_Implementation();
}

void UMIGunState_Idle::Reload_Implementation()
{
	IMIGunState::Reload_Implementation();
}
