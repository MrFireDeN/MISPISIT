// CPP_SMGBuilder.cpp

#include "Builder/CPP_SMGBuilder.h"

ACPP_SMGBuilder::ACPP_SMGBuilder()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	WeaponData = *new FWeaponData;
}

void ACPP_SMGBuilder::BeginPlay()
{
	Super::BeginPlay();
}

bool ACPP_SMGBuilder::SetBarrel_Implementation(const FString& Color)
{
	WeaponData.BarrelColor = Color;
	return true;
}

bool ACPP_SMGBuilder::SetChamber_Implementation()
{
	WeaponData.IsChamber = true;
	return true;
}

bool ACPP_SMGBuilder::SetMagazine_Implementation(const FString& Size)
{
	if (Size.Equals("Dafault"))
	{
		WeaponData.Magazine = Size;
	}
	return true;
}

bool ACPP_SMGBuilder::SetTrigger_Implementation()
{
	WeaponData.IsTrigger = true;
	return true;
}

bool ACPP_SMGBuilder::SetScope_Implementation(const FString& Name)
{
	if (Name.Equals("Red Dot") || Name.Equals("SniperScope"))
	{
		WeaponData.Scope = Name;
	}
	return true;
}

bool ACPP_SMGBuilder::SetAddition_Implementation(const FString& Name)
{
	if (Name.Equals("Flashlight") || Name.Equals("Laser"))
	{
		WeaponData.Addition = Name;
	}
	
	return true;
}

bool ACPP_SMGBuilder::ResetState_Implementation()
{
	WeaponData = *new FWeaponData;
	return true;
}

ACPP_SMG* ACPP_SMGBuilder::GetResult()
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
	
    ACPP_SMG* SMG = World->SpawnActor<ACPP_SMG>(
        ACPP_SMG::StaticClass(),
        Location,
        Rotator,
        SpawnParameters
        );

    if (!SMG)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to spawn SMG"));
        return nullptr;
    }

    if (!UAssetLoader::AttachMeshToActorFromAsset(
        SMG,
        TEXT("Barrel"),
        TEXT("/Game/Project/Models/Weapons/SM_HK_MP7.SM_HK_MP7")
    ))
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to attach Barrel to SMG"));
        SMG->Destroy();
        return nullptr;
    }

    if (WeaponData.IsChamber)
    {
        UAssetLoader::AttachMeshToActorFromAsset(
            SMG,
            TEXT("Chamber"),
            TEXT("/Game/Project/Models/Weapons/SM_HK_MP7_chamber.SM_HK_MP7_chamber")
            );
    	
    	UAssetLoader::AttachMeshToActorFromAsset(
			SMG,
			TEXT("ChamberHandle"),
			TEXT("/Game/Project/Models/Weapons/SM_HK_MP7_charging_handle.SM_HK_MP7_charging_handle")
		);
    }

    if (WeaponData.Magazine.Equals("Default"))
    {
        UAssetLoader::AttachMeshToActorFromAsset(
            SMG,
            TEXT("Magazine"),
            TEXT("/Game/Project/Models/Weapons/SM_HK_MP7_Mag.SM_HK_MP7_Mag")
        );
    }

    FVector ScopeLocation = FVector(0, -10, 40);

    if (WeaponData.Scope.Equals("Red Dot"))
    {
        UAssetLoader::AttachMeshToActorFromAsset(
            SMG,
            TEXT("Scope"),
            TEXT("/Game/Project/Models/Weapons/SM_Red_dot.SM_Red_dot"),
            ScopeLocation
            );
    }

    if (WeaponData.Scope.Equals("SniperScope"))
    {
        UAssetLoader::AttachMeshToActorFromAsset(
            SMG,
            TEXT("Scope"),
            TEXT("/Game/Project/Models/Weapons/SM_Scope.SM_Scope"),
            ScopeLocation
          );
    }
    
    FVector AdditionLocation = FVector(-10, -38, 26);
    FRotator AdditionRotator = FRotator(270, 0, 0);

    if (WeaponData.Addition.Equals("Flashlight"))
    {
        
        UAssetLoader::AttachMeshToActorFromAsset(
          SMG,
          TEXT("Addition"),
          TEXT("/Game/Project/Models/Weapons/SM_Flashlight.SM_Flashlight"),
          AdditionLocation,
          AdditionRotator
          );

        USpotLightComponent* Flashlight = NewObject<USpotLightComponent>(
          SMG,
          USpotLightComponent::StaticClass(),
          TEXT("Light")
          );

        if (Flashlight)
        {
            Flashlight->SetupAttachment(SMG->GetRootComponent());
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
        SMG,
        TEXT("Addition"),
        TEXT("/Game/Project/Models/Weapons/SM_Laser.SM_Laser"),
        AdditionLocation,
        AdditionRotator
        );

        // Laser Light logic TODO
    }

    return SMG;
}

