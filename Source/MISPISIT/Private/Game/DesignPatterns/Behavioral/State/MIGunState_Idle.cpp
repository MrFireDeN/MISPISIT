// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/State/MIGunState_Idle.h"

#include "Game/DesignPatterns/Behavioral/State/MIGunState_AutoFire.h"
#include "Game/DesignPatterns/Behavioral/State/MIGunState_BurstFire.h"
#include "Game/DesignPatterns/Behavioral/State/MIGunState_Fire.h"
#include "Game/DesignPatterns/Behavioral/State/MIGunState_Reload.h"
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

	switch (Gun->GetFireMode())
	{
	case EFireMode::Single:
		Gun->SetState(NewObject<UMIGunState_SingleFire>(Gun));
		break;
	case EFireMode::Auto:
		Gun->SetState(NewObject<UMIGunState_AutoFire>(Gun));
		break;
	case EFireMode::Burst:
		Gun->SetState(NewObject<UMIGunState_BurstFire>(Gun));
		break;
	default:
		Gun->SetState(NewObject<UMIGunState_Fire>(Gun));
		break;
	}
	
	Gun->StartFire();
}

void UMIGunState_Idle::Reload_Implementation()
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
