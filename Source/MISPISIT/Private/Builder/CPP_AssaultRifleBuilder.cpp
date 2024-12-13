#include "Builder/CPP_AssaultRifleBuilder.h"

ACPP_AssaultRifleBuilder::ACPP_AssaultRifleBuilder()
{
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    WeaponData = *new FWeaponData;
}

void ACPP_AssaultRifleBuilder::BeginPlay()
{
    Super::BeginPlay();
}

bool ACPP_AssaultRifleBuilder::SetBarrel_Implementation(const FString& Color)
{
    WeaponData.BarrelColor = Color;
    return true;
}

bool ACPP_AssaultRifleBuilder::SetChamber_Implementation()
{
    WeaponData.IsChamber = true;
    return true;
}

bool ACPP_AssaultRifleBuilder::SetMagazine_Implementation(const FString& Size)
{
    if (Size.Equals("Default"))
    {
        WeaponData.Magazine = Size;
    }
    return true;
}

bool ACPP_AssaultRifleBuilder::SetTrigger_Implementation()
{
    WeaponData.IsTrigger = true;
    return true;
}

bool ACPP_AssaultRifleBuilder::SetScope_Implementation(const FString& Name)
{
    if (Name.Equals("Red Dot") || Name.Equals("SniperScope"))
    {
        WeaponData.Scope = Name;
    }
    return true;
}

bool ACPP_AssaultRifleBuilder::SetAddition_Implementation(const FString& Name)
{
    if (Name.Equals("Flashlight") || Name.Equals("Laser") || Name.Equals("Foregrip"))
    {
        WeaponData.Addition = Name;
    }
	
    return true;
}

bool ACPP_AssaultRifleBuilder::ResetState_Implementation()
{
    WeaponData = *new FWeaponData;
    return true;
}

ACPP_AssaultRifle* ACPP_AssaultRifleBuilder::GetResult()
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

    ACPP_AssaultRifle* AssaultRifle = World->SpawnActor<ACPP_AssaultRifle>(
        ACPP_AssaultRifle::StaticClass(),
        Location,
        Rotator
        );

    if (!AssaultRifle)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to spawn Assault Rifle"));
        return nullptr;
    }

    if (!UAssetLoader::AttachMeshToActorFromAsset(
        AssaultRifle,
        TEXT("Barrel"),
        TEXT("/Game/Project/Models/Weapons/SM_AK-556.SM_AK-556")
    ))
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to attach Barrel to Assault Rifle"));
        AssaultRifle->Destroy();
        return nullptr;
    }

    if (WeaponData.IsChamber)
    {
        UAssetLoader::AttachMeshToActorFromAsset(
            AssaultRifle,
            TEXT("Chamber"),
            TEXT("/Game/Project/Models/Weapons/SM_AK-556_chamber.SM_AK-556_chamber")
        );
    }

    if (WeaponData.Magazine.Equals("Default"))
    {
        UAssetLoader::AttachMeshToActorFromAsset(
            AssaultRifle,
            TEXT("Magazine"),
            TEXT("/Game/Project/Models/Weapons/SM_AK-556_Mag.SM_AK-556_Mag")
        );
    }

    if (WeaponData.IsTrigger)
    {
        UAssetLoader::AttachMeshToActorFromAsset(
            AssaultRifle,
            TEXT("Trigger"),
            TEXT("/Game/Project/Models/Weapons/SM_AK-556_trigger.SM_AK-556_trigger")
        );
    }

    FVector ScopeLocation = FVector(0, -20, 40);

    if (WeaponData.Scope.Equals("Red Dot"))
    {
        UAssetLoader::AttachMeshToActorFromAsset(
            AssaultRifle,
            TEXT("Scope"),
            TEXT("/Game/Project/Models/Weapons/SM_Red_dot.SM_Red_dot"),
            ScopeLocation
            );
    }

    if (WeaponData.Scope.Equals("SniperScope"))
    {
        UAssetLoader::AttachMeshToActorFromAsset(
            AssaultRifle,
            TEXT("Scope"),
            TEXT("/Game/Project/Models/Weapons/SM_Scope.SM_Scope"),
            ScopeLocation
          );
    }
    
    FVector AdditionLocation = FVector(0, -70, 10);

    if (WeaponData.Addition.Equals("Flashlight"))
    {
        
        UAssetLoader::AttachMeshToActorFromAsset(
          AssaultRifle,
          TEXT("Addition"),
          TEXT("/Game/Project/Models/Weapons/SM_Flashlight.SM_Flashlight"),
          AdditionLocation
          );

        USpotLightComponent* Flashlight = NewObject<USpotLightComponent>(
          AssaultRifle,
          USpotLightComponent::StaticClass(),
          TEXT("Light")
          );

        if (Flashlight)
        {
            Flashlight->SetupAttachment(AssaultRifle->GetRootComponent());
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
        AssaultRifle,
        TEXT("Addition"),
        TEXT("/Game/Project/Models/Weapons/SM_Laser.SM_Laser"),
        AdditionLocation
        );

        // Laser Light logic TODO
    }

    if (WeaponData.Addition.Equals("Foregrip"))
    {
        UAssetLoader::AttachMeshToActorFromAsset(
        AssaultRifle,
        TEXT("Addition"),
        TEXT("/Game/Project/Models/Weapons/SM_Foregrip.SM_Foregrip"),
        AdditionLocation
        );
    }

    return AssaultRifle;
}