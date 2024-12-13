#include "Builder/CPP_TacticalRifleBuilder.h"

ACPP_TacticalRifleBuilder::ACPP_TacticalRifleBuilder()
{
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    WeaponData = *new FWeaponData;
}

void ACPP_TacticalRifleBuilder::BeginPlay()
{
    Super::BeginPlay();
}

bool ACPP_TacticalRifleBuilder::SetBarrel_Implementation(const FString& Color)
{
    WeaponData.BarrelColor = Color;
    return true;
}

bool ACPP_TacticalRifleBuilder::SetChamber_Implementation()
{
    WeaponData.IsChamber = true;
    return true;
}

bool ACPP_TacticalRifleBuilder::SetMagazine_Implementation(const FString& Size)
{
    if (Size.Equals("Default"))
    {
        WeaponData.Magazine = Size;
    }
    return true;
}

bool ACPP_TacticalRifleBuilder::SetTrigger_Implementation()
{
    WeaponData.IsTrigger = true;
    return true;
}

bool ACPP_TacticalRifleBuilder::SetScope_Implementation(const FString& Name)
{
    if (Name.Equals("Red Dot") || Name.Equals("SniperScope"))
    {
        WeaponData.Scope = Name;
    }
    return true;
}

bool ACPP_TacticalRifleBuilder::SetAddition_Implementation(const FString& Name)
{
    if (Name.Equals("Flashlight") || Name.Equals("Laser") || Name.Equals("Foregrip"))
    {
        WeaponData.Addition = Name;
    }
	
    return true;
}

bool ACPP_TacticalRifleBuilder::ResetState_Implementation()
{
    WeaponData = *new FWeaponData;
    return true;
}

ACPP_TacticalRifle* ACPP_TacticalRifleBuilder::GetResult()
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

    ACPP_TacticalRifle* TacticalRifle = World->SpawnActor<ACPP_TacticalRifle>(
        ACPP_TacticalRifle::StaticClass(),
        Location,
        Rotator,
        SpawnParameters
        );

    if (!TacticalRifle)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to spawn Tactical Rifle"));
        return nullptr;
    }

    if (!UAssetLoader::AttachMeshToActorFromAsset(
        TacticalRifle,
        TEXT("Barrel"),
        TEXT("/Game/Project/Models/Weapons/SM_AR-15.SM_AR-15")
    ))
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to attach Barrel to Tactical Rifle"));
        TacticalRifle->Destroy();
        return nullptr;
    }

    if (WeaponData.IsChamber)
    {
        UAssetLoader::AttachMeshToActorFromAsset(
            TacticalRifle,
            TEXT("Chamber"),
            TEXT("/Game/Project/Models/Weapons/SM_AR-15_chamber.SM_AR-15_chamber")
        );
        
        UAssetLoader::AttachMeshToActorFromAsset(
            TacticalRifle,
            TEXT("ChamberHandle"),
            TEXT("/Game/Project/Models/Weapons/SM_AR-15_charging_handle.SM_AR-15_charging_handle")
        );
    }

    if (WeaponData.Magazine.Equals("Default"))
    {
        UAssetLoader::AttachMeshToActorFromAsset(
            TacticalRifle,
            TEXT("Magazine"),
            TEXT("/Game/Project/Models/Weapons/SM_AR-15_Mag.SM_AR-15_Mag")
        );
    }

    FVector ScopeLocation = FVector(0, -20, 40);

    if (WeaponData.Scope.Equals("Red Dot"))
    {
        UAssetLoader::AttachMeshToActorFromAsset(
            TacticalRifle,
            TEXT("Scope"),
            TEXT("/Game/Project/Models/Weapons/SM_Red_dot.SM_Red_dot"),
            ScopeLocation
            );
    }

    if (WeaponData.Scope.Equals("SniperScope"))
    {
        UAssetLoader::AttachMeshToActorFromAsset(
            TacticalRifle,
            TEXT("Scope"),
            TEXT("/Game/Project/Models/Weapons/SM_Scope.SM_Scope"),
            ScopeLocation
          );
    }
    
    FVector AdditionLocation = FVector(-12, -86, 30);
    FRotator AdditionRotator = FRotator(270, 0, 0);

    if (WeaponData.Addition.Equals("Flashlight"))
    {
        
        UAssetLoader::AttachMeshToActorFromAsset(
          TacticalRifle,
          TEXT("Addition"),
          TEXT("/Game/Project/Models/Weapons/SM_Flashlight.SM_Flashlight"),
          AdditionLocation,
          AdditionRotator
          );

        USpotLightComponent* Flashlight = NewObject<USpotLightComponent>(
          TacticalRifle,
          USpotLightComponent::StaticClass(),
          TEXT("Light")
          );

        if (Flashlight)
        {
            Flashlight->SetupAttachment(TacticalRifle->GetRootComponent());
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
        TacticalRifle,
        TEXT("Addition"),
        TEXT("/Game/Project/Models/Weapons/SM_Laser.SM_Laser"),
        AdditionLocation,
        AdditionRotator
        );

        // Laser Light logic TODO
    }

    if (WeaponData.Addition.Equals("Foregrip"))
    {
        UAssetLoader::AttachMeshToActorFromAsset(
        TacticalRifle,
        TEXT("Addition"),
        TEXT("/Game/Project/Models/Weapons/SM_Foregrip.SM_Foregrip"),
        FVector(0, -88, 18)
        );
    }

    return TacticalRifle;
}