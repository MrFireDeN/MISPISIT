// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DesignPatterns/Behavioral/State/MIGunState_SingleFire.h"

#include "Compose/CPP_Gun.h"

void UMIGunState_SingleFire::StartFire_Implementation()
{
	ACPP_Gun* Gun = Cast<ACPP_Gun>(GetOuter());

	if (!IsValid(Gun))
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] StartFire: Gun is NOT valid"), *GetName());
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("[%s] Start Fire"), *GetName())
	
	Gun->OnPrimaryAction();

	Execute_StopFire(this);
}

void UMIGunState_SingleFire::StopFire_Implementation()
{
	ACPP_Gun* Gun = Cast<ACPP_Gun>(GetOuter());

	if (!IsValid(Gun))
	{
		UE_LOG(LogTemp, Error, TEXT("[%s] StartFire: Gun is NOT valid"), *GetName());
		return;
	}

	
	
	IMIGunState::StopFire_Implementation();
}

void UMIGunState_SingleFire::Reload_Implementation()
{
	IMIGunState::Reload_Implementation();
}
