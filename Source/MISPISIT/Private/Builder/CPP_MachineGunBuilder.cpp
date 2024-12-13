// CPP_MachineGunBuilder.cpp

#include "Builder/CPP_MachineGunBuilder.h"

ACPP_MachineGunBuilder::ACPP_MachineGunBuilder()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	WeaponData = *new FWeaponData;
}

void ACPP_MachineGunBuilder::BeginPlay()
{
	Super::BeginPlay();
	
}

bool ACPP_MachineGunBuilder::SetBarrel_Implementation(const FString& Color)
{
	WeaponData.BarrelColor = Color;
	return true;
}

bool ACPP_MachineGunBuilder::SetChamber_Implementation()
{
	WeaponData.IsChamber = true;
	return true;
}

bool ACPP_MachineGunBuilder::SetMagazine_Implementation(const FString& Size)
{
	if (Size.Equals("Large"))
	{
		WeaponData.Magazine = Size;
	}
	return true;
}

bool ACPP_MachineGunBuilder::SetTrigger_Implementation()
{
	WeaponData.IsTrigger = true;
	return true;
}

bool ACPP_MachineGunBuilder::SetScope_Implementation(const FString& Name)
{
	if (Name.Equals("Red Dot") || Name.Equals("SniperScope"))
	{
		WeaponData.Scope = Name;
	}
	return true;
}

bool ACPP_MachineGunBuilder::SetAddition_Implementation(const FString& Name)
{
	if (Name.Equals("Flashlight") || Name.Equals("Laser"))
	{
		WeaponData.Addition = Name;
	}
	
	return true;
}

bool ACPP_MachineGunBuilder::ResetState_Implementation()
{
	WeaponData = *new FWeaponData;
	return true;
}

ACPP_MachineGun* ACPP_MachineGunBuilder::GetResult()
{
	UWorld* World = GetWorld();
    if (!World)
    {
        UE_LOG(LogTemp, Error, TEXT("World does not exist"));
        return nullptr;
    }

    FActorSpawnParameters SpawnParameters;
    FVector Location = GetActorLocation();
    FRotator Rotator = GetActorRotation();

    ACPP_MachineGun* MachineGun = World->SpawnActor<ACPP_MachineGun>(
        ACPP_MachineGun::StaticClass(),
        Location,
        Rotator,
        SpawnParameters
        );

    if (!MachineGun)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to spawn Machine Gun"));
        return nullptr;
    }

    if (!UAssetLoader::AttachMeshToActorFromAsset(
        MachineGun,
        TEXT("Barrel"),
        TEXT("/Game/Project/Models/Weapons/SM_RPD.SM_RPD")
    ))
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to attach Barrel to Machine Gun"));
        MachineGun->Destroy();
        return nullptr;
    }

    if (WeaponData.IsChamber)
    {
        UAssetLoader::AttachMeshToActorFromAsset(
            MachineGun,
            TEXT("Chamber"),
            TEXT("/Game/Project/Models/Weapons/SM_RPD_charging_handle.SM_RPD_charging_handle")
        );
    }

    if (WeaponData.Magazine.Equals("Large"))
    {
        UAssetLoader::AttachMeshToActorFromAsset(
            MachineGun,
            TEXT("Magazine"),
            TEXT("/Game/Project/Models/Weapons/SM_RPD_mag.SM_RPD_mag")
        );
    }

    FVector ScopeLocation = FVector(0, -10, 38);

    if (WeaponData.Scope.Equals("Red Dot"))
    {
        UAssetLoader::AttachMeshToActorFromAsset(
            MachineGun,
            TEXT("Scope"),
            TEXT("/Game/Project/Models/Weapons/SM_Red_dot.SM_Red_dot"),
            ScopeLocation
            );
    }

    if (WeaponData.Scope.Equals("SniperScope"))
    {
        UAssetLoader::AttachMeshToActorFromAsset(
            MachineGun,
            TEXT("Scope"),
            TEXT("/Game/Project/Models/Weapons/SM_Scope.SM_Scope"),
            ScopeLocation
          );
    }
    
    FVector AdditionLocation = FVector(-8, -8, 22);
    FRotator AdditionRotator = FRotator(270, 0, 0);

    if (WeaponData.Addition.Equals("Flashlight"))
    {
        
        UAssetLoader::AttachMeshToActorFromAsset(
          MachineGun,
          TEXT("Addition"),
          TEXT("/Game/Project/Models/Weapons/SM_Flashlight.SM_Flashlight"),
          AdditionLocation,
          AdditionRotator
          );

        USpotLightComponent* Flashlight = NewObject<USpotLightComponent>(
          MachineGun,
          USpotLightComponent::StaticClass(),
          TEXT("Light")
          );

        if (Flashlight)
        {
            Flashlight->SetupAttachment(MachineGun->GetRootComponent());
            Flashlight->SetRelativeLocation(AdditionLocation + FVector(0, -20, -10));
            Flashlight->SetRelativeRotation(FRotator(0, 270, 0));

            Flashlight->IntensityUnits = ELightUnits::Lumens;
            Flashlight->Intensity = 150;

            Flashlight->RegisterComponent();
        }
    }

    if (WeaponData.Addition.Equals("Laser"))
    {
        UAssetLoader::AttachMeshToActorFromAsset(
        MachineGun,
        TEXT("Addition"),
        TEXT("/Game/Project/Models/Weapons/SM_Laser.SM_Laser"),
        AdditionLocation,
        AdditionRotator
        );

        // Laser Light logic TODO
    }

    return MachineGun;
}
