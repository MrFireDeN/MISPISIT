// CPP_SniperRifleBuilder.cpp

#include "Builder/CPP_SniperRifleBuilder.h"

// Sets default values
ACPP_SniperRifleBuilder::ACPP_SniperRifleBuilder()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
  
	WeaponData = *new FWeaponData;
}

void ACPP_SniperRifleBuilder::BeginPlay()
{
	Super::BeginPlay();
  
}

bool ACPP_SniperRifleBuilder::SetBarrel_Implementation(const FString& Color)
{
	WeaponData.BarrelColor = Color;
  
	return true;
}

bool ACPP_SniperRifleBuilder::SetChamber_Implementation()
{
	WeaponData.IsChamber = true;
  
	return true;
}

bool ACPP_SniperRifleBuilder::SetMagazine_Implementation(const FString& Size)
{
	if (Size.Equals("Large"))
	{
		WeaponData.Magazine = Size;
	}
  
	return true;
}

bool ACPP_SniperRifleBuilder::SetTrigger_Implementation()
{
	WeaponData.IsTrigger = true;
  
	return true;
}

bool ACPP_SniperRifleBuilder::SetScope_Implementation(const FString& Name)
{
	if (Name.Equals("SniperScope"))
	{
		WeaponData.Scope = Name;
	}
  
	return true;
}

bool ACPP_SniperRifleBuilder::SetAddition_Implementation(const FString& Name)
{
	if (Name.Equals("Flashlight") || Name.Equals("Laser"))
	{
		WeaponData.Addition = Name;
	}
  
	return true;
}

bool ACPP_SniperRifleBuilder::ResetState_Implementation()
{
	WeaponData = *new FWeaponData;
  
	return true;
}

ACPP_SniperRifle* ACPP_SniperRifleBuilder::GetResult()
{
	UWorld* World = GetWorld();
  
	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("World does NOT exist"));
		return nullptr;
	}

	FActorSpawnParameters SpawnParameters;
	FVector Location = GetActorLocation();
	FRotator Rotator = GetActorRotation();

	ACPP_SniperRifle* SniperRifle = World->SpawnActor<ACPP_SniperRifle>(ACPP_SniperRifle::StaticClass(), Location, Rotator, SpawnParameters);

	if (!SniperRifle)
	{
		UE_LOG(LogTemp, Error, TEXT("Can NOT spawn SniperRifle"));
		return nullptr;
	}
	
	if (!UAssetLoader::AttachMeshToActorFromAsset(
		SniperRifle,
	    TEXT("Barrel"),
	    TEXT("/Game/Project/Models/Weapons/SM_AWM.SM_AWM")
	    ))
		{
		UE_LOG(LogTemp, Error, TEXT("Failed to attach Barrel to SniperRifle. Destroying SniperRifle."));
		SniperRifle->Destroy();
		return nullptr;
	}

	// Apply Barrel color if specified
	if (!WeaponData.BarrelColor.IsEmpty())
	{
		// Set color logic here TODO
	}

	if (WeaponData.IsChamber)
	{
		UAssetLoader::AttachMeshToActorFromAsset(
		  SniperRifle,
		  TEXT("Chamber"),
		  TEXT("/Game/Project/Models/Weapons/SM_AWM_bolt_action.SM_AWM_bolt_action")
		  );
	}

	if (WeaponData.IsTrigger)
	{
		UAssetLoader::AttachMeshToActorFromAsset(
		  SniperRifle,
		  TEXT("Trigger"),
		  TEXT("/Game/Project/Models/Weapons/SM_AWM_trigger.SM_AWM_trigger")
		  );
	}

	if (WeaponData.Magazine.Equals("Large"))
	{
		UAssetLoader::AttachMeshToActorFromAsset(
		  SniperRifle,
		  TEXT("Magazine"),
		  TEXT("/Game/Project/Models/Weapons/SM_AWM_mag.SM_AWM_mag")
		  );
	}

	if (WeaponData.Scope.Equals("SniperScope"))
	{
		UAssetLoader::AttachMeshToActorFromAsset(
		  SniperRifle,
		  TEXT("Scope"),
		  TEXT("/Game/Project/Models/Weapons/SM_Scope.SM_Scope"),
		  FVector(0, -50, 46)
		  );
	}

	if (WeaponData.Addition.Equals("Flashlight"))
	{
		UAssetLoader::AttachMeshToActorFromAsset(
		  SniperRifle,
		  TEXT("Addition"),
		  TEXT("/Game/Project/Models/Weapons/SM_Flashlight.SM_Flashlight"),
		  FVector(-12, -132, 36),
		  FRotator(270, 0, 0)
		  );

		USpotLightComponent* Flashlight = NewObject<USpotLightComponent>(
		  SniperRifle,
		  USpotLightComponent::StaticClass(),
		  TEXT("Light")
		  );

		if (Flashlight)
		{
			Flashlight->SetupAttachment(SniperRifle->GetRootComponent());
			Flashlight->SetRelativeLocation(FVector(0, -60, 8));
			Flashlight->SetRelativeRotation(FRotator(0, 270, 0));

			Flashlight->IntensityUnits = ELightUnits::Lumens;
			Flashlight->Intensity = 150;

			Flashlight->RegisterComponent();
		}
	}

	if (WeaponData.Addition.Equals("Laser"))
	{
		UAssetLoader::AttachMeshToActorFromAsset(
		SniperRifle,
		TEXT("Addition"),
		TEXT("/Game/Project/Models/Weapons/SM_Laser.SM_Laser"),
		FVector(-12, -132, 36),
		FRotator(270, 0, 0)
		);

		// Laser Light logic TODO
	}

	return SniperRifle;
}