// CPP_PistolBuilder.cpp

#include "Builder/CPP_PistolBuilder.h"

// Sets default values
ACPP_PistolBuilder::ACPP_PistolBuilder()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	WeaponData = *new FWeaponData;
}

void ACPP_PistolBuilder::BeginPlay()
{
	Super::BeginPlay();
	
}

bool ACPP_PistolBuilder::SetBarrel_Implementation(const FString& Color)
{
	WeaponData.BarrelColor = Color;
	
	return true;
}

bool ACPP_PistolBuilder::SetChamber_Implementation()
{
	WeaponData.IsChamber = true;
	
	return true;
}

bool ACPP_PistolBuilder::SetMagazine_Implementation(const FString& Size)
{
	if (Size.Equals("Small"))
	{
		WeaponData.Magazine = Size;
	}
	
	return true;
}

bool ACPP_PistolBuilder::SetTrigger_Implementation()
{
	WeaponData.IsTrigger = true;
	
	return true;
}

bool ACPP_PistolBuilder::SetScope_Implementation(const FString& Name)
{
	if (Name.Equals("Red Dot"))
	{
		WeaponData.Scope = Name;
	}
	
	return true;
}

bool ACPP_PistolBuilder::SetAddition_Implementation(const FString& Name)
{
	if (Name.Equals("Flashlight") || Name.Equals("Laser"))
	{
		WeaponData.Addition = Name;
	}
	
	return true;
}

bool ACPP_PistolBuilder::ResetState_Implementation()
{
	WeaponData = *new FWeaponData;
	
	return true;
}

ACPP_Pistol* ACPP_PistolBuilder::GetResult()
{
	UWorld* World = GetWorld();
	
	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("World do NOT exist"));
		return nullptr;
	}

	FActorSpawnParameters SpawnParameters;
	FVector Location = GetActorLocation();
	FRotator Rotator = GetActorRotation();

	ACPP_Pistol* Pistol = World->SpawnActor<ACPP_Pistol>(ACPP_Pistol::StaticClass(), Location, Rotator, SpawnParameters);

	if (!Pistol)
	{
		UE_LOG(LogTemp, Error, TEXT("Can NOT spawn Pistol"));
		return nullptr;
	}
	
	if (!UAssetLoader::AttachMeshToActorFromAsset(
		Pistol,
		TEXT("Barrel"),
		TEXT("/Game/Project/Models/Weapons/SM_FN_FIVE-SEVEN.SM_FN_FIVE-SEVEN")
		))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to attach Barrel to Pistol. Destroying Pistol."));
		Pistol->Destroy();
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
			Pistol,
			TEXT("Chamber"),
			TEXT("/Game/Project/Models/Weapons/SM_FN_FIVE-SEVEN_slide.SM_FN_FIVE-SEVEN_slide")
			);
	}

	if (WeaponData.IsTrigger)
	{
		UAssetLoader::AttachMeshToActorFromAsset(
			Pistol,
			TEXT("Trigger"),
			TEXT("/Game/Project/Models/Weapons/SM_FN_FIVE-SEVEN_trigger.SM_FN_FIVE-SEVEN_trigger")
			);
	}

	if (WeaponData.Magazine.Equals("Small"))
	{
		UAssetLoader::AttachMeshToActorFromAsset(
			Pistol,
			TEXT("Magazine"),
			TEXT("/Game/Project/Models/Weapons/SM_FN_FIVE-SEVEN_Mag.SM_FN_FIVE-SEVEN_Mag")
			);
	}

	if (WeaponData.Scope.Equals("Red Dot"))
	{
		UAssetLoader::AttachMeshToActorFromAsset(
			Pistol,
			TEXT("Scope"),
			TEXT("/Game/Project/Models/Weapons/SM_Red_dot.SM_Red_dot"),
			FVector(0, -2, 22)
			);
	}

	if (WeaponData.Addition.Equals("Flashlight"))
	{
		UAssetLoader::AttachMeshToActorFromAsset(
			Pistol,
			TEXT("Addition"),
			TEXT("/Game/Project/Models/Weapons/SM_Flashlight.SM_Flashlight"),
			FVector(0, -40, 18)
			);

		USpotLightComponent* Flashlight = NewObject<USpotLightComponent>(
			Pistol,
			USpotLightComponent::StaticClass(),
			TEXT("Light")
			);

		if (Flashlight)
		{
			Flashlight->SetupAttachment(Pistol->GetRootComponent());
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
			Pistol,
			TEXT("Addition"),
			TEXT("/Game/Project/Models/Weapons/SM_Laser.SM_Laser"),
			FVector(0, -40, 18)
			);

		// Laser Light need TODO
	}

	return Pistol;
}