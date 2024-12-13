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
		UE_LOG(LogTemp, Log, TEXT("Pistol succesfully constructed!!!"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to construct pistol."));
	}
}

