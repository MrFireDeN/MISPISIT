// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/State/MIGunState_Reload.h"
#include "Game/DesignPatterns/Behavioral/State/MIGunState_Idle.h"
#include "Game/Gameplay/Weapons/MIGun.h"


void UMIGunState_Reload::Reload_Implementation()
{
	AMIGun* Gun = Cast<AMIGun>(GetOuter());

	if (!IsValid(Gun))
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] Reload: Gun is NOT valid"), *GetName());
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("[%s] Reload"), *GetName())

	Gun->GetWorld()->GetTimerManager().SetTimer(ReloadTimerHandle, [this, Gun]()
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] Reload completed"), *GetName());
		Gun->SetState(NewObject<UMIGunState_Idle>(Gun));
	}, Gun->GetReloadDelay(), false);
}
