// CPP_WeaponDirector.cpp

#include "Builder/CPP_WeaponDirector.h"


ACPP_WeaponDirector::ACPP_WeaponDirector()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
}


void ACPP_WeaponDirector::BeginPlay()
{
	Super::BeginPlay();

	// Pistol
	Builder = GetWorld()->SpawnActor<ACPP_PistolBuilder>(GetActorLocation(), GetActorRotation());

	Builder->Execute_ResetState(Builder.GetObject());

	Builder->Execute_SetBarrel(Builder.GetObject(), "");
	Builder->Execute_SetChamber(Builder.GetObject());
	Builder->Execute_SetTrigger(Builder.GetObject());
	Builder->Execute_SetMagazine(Builder.GetObject(), "Small");
	Builder->Execute_SetScope(Builder.GetObject(), TEXT("Red Dot"));
	Builder->Execute_SetAddition(Builder.GetObject(), TEXT("Flashlight"));

	if (Cast<ACPP_PistolBuilder>(Builder.GetObject())->GetResult())
	{
		UE_LOG(LogTemp, Log, TEXT("Pistol succesfully constructed!!!"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to construct pistol."));
	}

	// SniperRifle
	Builder = GetWorld()->SpawnActor<ACPP_SniperRifleBuilder>(GetActorLocation() + FVector(100, 0, 0), GetActorRotation());

	Builder->Execute_ResetState(Builder.GetObject());

	Builder->Execute_SetBarrel(Builder.GetObject(), "");
	Builder->Execute_SetChamber(Builder.GetObject());
	Builder->Execute_SetTrigger(Builder.GetObject());
	Builder->Execute_SetMagazine(Builder.GetObject(), "Large");
	Builder->Execute_SetScope(Builder.GetObject(), TEXT("SniperScope"));
	Builder->Execute_SetAddition(Builder.GetObject(), TEXT("Laser"));

	if (Cast<ACPP_SniperRifleBuilder>(Builder.GetObject())->GetResult())
	{
		UE_LOG(LogTemp, Log, TEXT("SniperRifle succesfully constructed!!!"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to construct SniperRifle."));
	}

	// AssaultRifle
	Builder = GetWorld()->SpawnActor<ACPP_AssaultRifleBuilder>(GetActorLocation() + FVector(200, 0, 0), GetActorRotation());

	Builder->Execute_ResetState(Builder.GetObject());

	Builder->Execute_SetBarrel(Builder.GetObject(), "");
	Builder->Execute_SetChamber(Builder.GetObject());
	Builder->Execute_SetTrigger(Builder.GetObject());
	Builder->Execute_SetMagazine(Builder.GetObject(), "Default");
	Builder->Execute_SetScope(Builder.GetObject(), TEXT("Red Dot"));
	Builder->Execute_SetAddition(Builder.GetObject(), TEXT("Foregrip"));

	if (Cast<ACPP_AssaultRifleBuilder>(Builder.GetObject())->GetResult())
	{
		UE_LOG(LogTemp, Log, TEXT("AssaultRifle succesfully constructed!!!"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to construct AssaultRifle."));
	}

	// TacticalRifle
	Builder = GetWorld()->SpawnActor<ACPP_TacticalRifleBuilder>(GetActorLocation() + FVector(300, 0, 0), GetActorRotation());

	Builder->Execute_ResetState(Builder.GetObject());

	Builder->Execute_SetBarrel(Builder.GetObject(), "");
	Builder->Execute_SetChamber(Builder.GetObject());
	Builder->Execute_SetTrigger(Builder.GetObject());
	Builder->Execute_SetMagazine(Builder.GetObject(), "Default");
	Builder->Execute_SetScope(Builder.GetObject(), TEXT("SniperScope"));
	Builder->Execute_SetAddition(Builder.GetObject(), TEXT("Foregrip"));

	if (Cast<ACPP_TacticalRifleBuilder>(Builder.GetObject())->GetResult())
	{
		UE_LOG(LogTemp, Log, TEXT("TacticalRifle succesfully constructed!!!"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to construct TacticalRifle."));
	}

	//  MachineGun
	Builder = GetWorld()->SpawnActor<ACPP_MachineGunBuilder>(GetActorLocation() + FVector(400, 0, 0), GetActorRotation());

	Builder->Execute_ResetState(Builder.GetObject());

	Builder->Execute_SetBarrel(Builder.GetObject(), "");
	Builder->Execute_SetChamber(Builder.GetObject());
	Builder->Execute_SetTrigger(Builder.GetObject());
	Builder->Execute_SetMagazine(Builder.GetObject(), "Large");
	Builder->Execute_SetScope(Builder.GetObject(), TEXT("Red Dot"));
	Builder->Execute_SetAddition(Builder.GetObject(), TEXT("Laser"));

	if (Cast<ACPP_MachineGunBuilder>(Builder.GetObject())->GetResult())
	{
		UE_LOG(LogTemp, Log, TEXT("MachineGun succesfully constructed!!!"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to construct MachineGun."));
	}
}

